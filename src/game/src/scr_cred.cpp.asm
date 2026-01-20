// Auto-generated scaffold unit: scr_cred.cpp.asm
// SourceMap: C:/msdev/work/age1_x1/scr_cred.cpp
#include "../include/common.h"

// Offset: 0x004926E0
undefined TRIBE_Credits_Screen(TRIBE_Credits_Screen* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall TRIBE_Credits_Screen::TRIBE_Credits_Screen(void)                                   *
    //                              *********************************************************************************************************
    //                              undefined __thiscall TRIBE_Credits_Screen(TRIBE_Credits_Screen * this)
    //              undefined         <UNASSIGNED>   <RETURN>
    //              TRIBE_Credits_    ECX:4 (auto)   this
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[5]:     0049276c(W), 0049283a(W), 00492885(W), 004928db(W), 
    //                                                                                     004928f9(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[2]:     00492784(R), 00492936(R)  
    //              char[13]          Stack[-0x20]   temp_file_name            XREF[1,2]:   00492703(W), 004928b8(*), 004928e2(*)  
    //              undefined4        Stack[-0x24]:4 local_24                  XREF[4]:     004927e7(W), 0049280a(R), 00492834(W), 004928d5(W)  
    //              long              Stack[-0x28]:4 size
    //                               ??0TRIBE_Credits_Screen@@QAE@XZ                              XREF[2]:     action:0043b4dc(c), 
    //                               TRIBE_Credits_Screen::TRIBE_Credits_Screen                                key_down_action:0049eda2(c)  
    //                              scr_cred.cpp:46 (46)
    //         004926e0     PUSH       -0x1
    //         004926e2     PUSH       FUN_0055eace
    //         004926e7     MOV        EAX,FS:[0x0]
    //         004926ed     PUSH       EAX
    //         004926ee     MOV        dword ptr FS:[0x0],ESP
    //         004926f5     SUB        ESP,0x18
    //         004926f8     PUSH       EBX
    //         004926f9     PUSH       EBP
    //         004926fa     PUSH       ESI
    //         004926fb     PUSH       EDI
    //         004926fc     MOV        EBP,this
    //         004926fe     PUSH       s_Credits_Screen                                 = "Credits Screen"
    //         00492703     MOV        dword ptr [ESP + temp_file_name[0]],EBP
    //         00492707     CALL       TScreenPanel::TScreenPanel                       undefined TScreenPanel(TScreenPanel * this, c
    //         0049270c     XOR        ESI,ESI
    //                              scr_cred.cpp:57 (11)
    //         0049270e     MOV        EBX,0x1
    //         00492713     LEA        EDI,[EBP + 0x894]
    //                              scr_cred.cpp:66 (64)
    //         00492719     MOV        this,0x7
    //         0049271e     XOR        EAX,EAX
    //         00492720     MOV        dword ptr [EBP],TRIBE_Credits_Screen::`vftable'  = 00492950
    //         00492727     MOV        dword ptr [EBP + 0x478],ESI
    //         0049272d     MOV        dword ptr [EBP + 0x47c],EBX
    //         00492733     MOV        dword ptr [EBP + 0x480],EBX
    //         00492739     MOV        dword ptr [EBP + 0x484],ESI
    //         0049273f     MOV        dword ptr [EBP + 0x488],ESI
    //         00492745     MOV        dword ptr [EBP + 0x48c],EBX
    //         0049274b     MOV        dword ptr [EBP + 0x8b0],EBX
    //         00492751     MOV        dword ptr [EBP + 0x8b4],ESI
    //         00492757     STOSD.REP  ES:EDI
    //                              scr_cred.cpp:69 (35)
    //         00492759     MOV        EAX,[rge_base_game]                              = 00000000
    //         0049275e     PUSH       EBX
    //         0049275f     PUSH       0xc38b
    //         00492764     PUSH       s_scr_cred                                       = "scr_cred"
    //         00492769     MOV        this,dword ptr [EAX + 0x4c]
    //         0049276c     MOV        dword ptr [ESP + local_4],ESI
    //         00492770     PUSH       this
    //         00492771     MOV        this,EBP
    //         00492773     CALL       TScreenPanel::setup                              long setup(TScreenPanel * this, TDrawArea * p
    //         00492778     TEST       EAX,EAX
    //         0049277a     JNZ        LAB_00492797
    //                              scr_cred.cpp:71 (6)
    //         0049277c     MOV        dword ptr [EBP + 0xd8],EBX
    //                              scr_cred.cpp:169 (21)
    //         00492782     MOV        EAX,EBP
    //         00492784     MOV        this,dword ptr [ESP + local_c]
    //         00492788     MOV        dword ptr FS:[0x0],this
    //         0049278f     POP        EDI
    //         00492790     POP        ESI
    //         00492791     POP        EBP
    //         00492792     POP        EBX
    //         00492793     ADD        ESP,0x24
    //         00492796     RET
    //                               LAB_00492797                                                 XREF[1]:     0049277a(j)  
    //                              scr_cred.cpp:75 (17)
    //         00492797     PUSH       0x1e0
    //         0049279c     PUSH       0x280
    //         004927a1     MOV        this,EBP
    //         004927a3     CALL       TEasy_Panel::set_ideal_size                      void set_ideal_size(TEasy_Panel * this, long 
    //                              scr_cred.cpp:77 (13)
    //         004927a8     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004927ae     PUSH       0x4
    //         004927b0     CALL       RGE_Base_Game::get_font                          RGE_Font * get_font(RGE_Base_Game * this, int
    //                              scr_cred.cpp:85 (24)
    //         004927b5     PUSH       0x8000
    //         004927ba     PUSH       s_data2\list.cr                                  = "data2\\list.cr"
    //         004927bf     MOV        EBX,EAX
    //         004927c1     XOR        EDI,EDI
    //         004927c3     CALL       __open                                           undefined __open()
    //         004927c8     MOV        ESI,EAX
    //         004927ca     ADD        ESP,0x8
    //                              scr_cred.cpp:86 (5)
    //         004927cd     CMP        ESI,-0x1
    //         004927d0     JZ         LAB_00492825
    //                              scr_cred.cpp:88 (12)
    //         004927d2     PUSH       0x2
    //         004927d4     PUSH       EDI
    //         004927d5     PUSH       ESI
    //         004927d6     CALL       lseek                                            undefined lseek()
    //         004927db     ADD        ESP,0xc
    //                              scr_cred.cpp:89 (13)
    //         004927de     PUSH       ESI
    //         004927df     CALL       __tell                                           undefined __tell()
    //         004927e4     ADD        ESP,0x4
    //         004927e7     MOV        dword ptr [ESP + local_24],EAX
    //                              scr_cred.cpp:90 (17)
    //         004927eb     INC        EAX
    //         004927ec     PUSH       0x400
    //         004927f1     PUSH       EAX
    //         004927f2     CALL       calloc                                           undefined calloc()
    //         004927f7     MOV        EDI,EAX
    //         004927f9     ADD        ESP,0x8
    //                              scr_cred.cpp:91 (4)
    //         004927fc     TEST       EDI,EDI
    //         004927fe     JZ         LAB_0049281c
    //                              scr_cred.cpp:93 (10)
    //         00492800     PUSH       0x0
    //         00492802     PUSH       0x0
    //         00492804     PUSH       ESI
    //         00492805     CALL       lseek                                            undefined lseek()
    //                              scr_cred.cpp:94 (18)
    //         0049280a     MOV        EDX,dword ptr [ESP + local_24]
    //         0049280e     ADD        ESP,0xc
    //         00492811     PUSH       EDX
    //         00492812     PUSH       EDI
    //         00492813     PUSH       ESI
    //         00492814     CALL       read                                             undefined read()
    //         00492819     ADD        ESP,0xc
    //                               LAB_0049281c                                                 XREF[1]:     004927fe(j)  
    //                              scr_cred.cpp:96 (9)
    //         0049281c     PUSH       ESI
    //         0049281d     CALL       close                                            undefined close()
    //         00492822     ADD        ESP,0x4
    //                               LAB_00492825                                                 XREF[1]:     004927d0(j)  
    //                              scr_cred.cpp:134 (94)
    //         00492825     PUSH       0x198
    //         0049282a     CALL       operator_new                                     void * operator_new(uint param_1)
    //         0049282f     MOV        this,EAX
    //         00492831     ADD        ESP,0x4
    //         00492834     MOV        dword ptr [ESP + local_24],this
    //         00492838     TEST       this,this
    //         0049283a     MOV        byte ptr [ESP + local_4],0x1
    //         0049283f     JZ         LAB_00492881
    //         00492841     MOV        EAX,dword ptr [EBX + 0x8]
    //         00492844     MOV        EDX,dword ptr [EBX + 0x4]
    //         00492847     PUSH       EDI
    //         00492848     PUSH       EAX
    //         00492849     MOV        EAX,dword ptr [EBX]
    //         0049284b     PUSH       EDX
    //         0049284c     PUSH       EAX
    //         0049284d     MOV        EAX,dword ptr [EBP + 0x18]
    //         00492850     CDQ
    //         00492851     SUB        EAX,EDX
    //         00492853     PUSH       0x1e
    //         00492855     SAR        EAX,0x1
    //         00492857     PUSH       0x12c
    //         0049285c     SUB        EAX,0x96
    //         00492861     PUSH       0x1f4
    //         00492866     PUSH       EAX
    //         00492867     MOV        EAX,dword ptr [EBP + 0x14]
    //         0049286a     CDQ
    //         0049286b     SUB        EAX,EDX
    //         0049286d     MOV        EDX,dword ptr [EBP + 0x20]
    //         00492870     SAR        EAX,0x1
    //         00492872     SUB        EAX,0xfa
    //         00492877     PUSH       EAX
    //         00492878     PUSH       EDX
    //         00492879     PUSH       EBP
    //         0049287a     CALL       TScrollTextPanel::TScrollTextPanel               undefined TScrollTextPanel(TScrollTextPanel *
    //         0049287f     JMP        LAB_00492883
    //                               LAB_00492881                                                 XREF[1]:     0049283f(j)  
    //         00492881     XOR        EAX,EAX
    //                               LAB_00492883                                                 XREF[1]:     0049287f(j)  
    //                              scr_cred.cpp:139 (15)
    //         00492883     TEST       EDI,EDI
    //         00492885     MOV        byte ptr [ESP + local_4],0x0
    //         0049288a     MOV        dword ptr [EBP + 0x478],EAX
    //         00492890     JZ         LAB_0049289b
    //                              scr_cred.cpp:140 (9)
    //         00492892     PUSH       EDI
    //         00492893     CALL       free                                             undefined free()
    //         00492898     ADD        ESP,0x4
    //                               LAB_0049289b                                                 XREF[1]:     00492890(j)  
    //                              scr_cred.cpp:142 (23)
    //         0049289b     MOV        EAX,dword ptr [EBP + 0x204]
    //         004928a1     MOV        ESI,0xc3eb
    //         004928a6     MOV        dword ptr [EBP + 0x894],EAX
    //         004928ac     LEA        EDI,[EBP + 0x898]
    //                               LAB_004928b2                                                 XREF[1]:     00492907(j)  
    //                              scr_cred.cpp:143 (6)
    //         004928b2     LEA        this,[ESI + 0xffff3c17]
    //                              scr_cred.cpp:146 (19)
    //         004928b8     LEA        EDX=>temp_file_name[4],[ESP + 0x18]
    //         004928bc     PUSH       this
    //         004928bd     PUSH       s_credit%d                                       = "credit%d"
    //         004928c2     PUSH       EDX
    //         004928c3     CALL       sprintf                                          undefined sprintf()
    //         004928c8     ADD        ESP,0xc
    //                              scr_cred.cpp:147 (62)
    //         004928cb     PUSH       0x20
    //         004928cd     CALL       operator_new                                     void * operator_new(uint param_1)
    //         004928d2     ADD        ESP,0x4
    //         004928d5     MOV        dword ptr [ESP + local_24],EAX
    //         004928d9     TEST       EAX,EAX
    //         004928db     MOV        byte ptr [ESP + local_4],0x2
    //         004928e0     JZ         LAB_004928f1
    //         004928e2     LEA        this=>temp_file_name[4],[ESP + 0x18]
    //         004928e6     PUSH       ESI
    //         004928e7     PUSH       this
    //         004928e8     MOV        this,EAX
    //         004928ea     CALL       TShape::TShape                                   undefined TShape(TShape * this, char * param_
    //         004928ef     JMP        LAB_004928f3
    //                               LAB_004928f1                                                 XREF[1]:     004928e0(j)  
    //         004928f1     XOR        EAX,EAX
    //                               LAB_004928f3                                                 XREF[1]:     004928ef(j)  
    //         004928f3     MOV        dword ptr [EDI],EAX
    //         004928f5     ADD        EDI,0x4
    //         004928f8     INC        ESI
    //         004928f9     MOV        byte ptr [ESP + local_4],0x0
    //         004928fe     LEA        EDX,[ESI + 0xffff3c16]
    //         00492904     CMP        EDX,0x7
    //         00492907     JL         LAB_004928b2
    //                              scr_cred.cpp:165 (8)
    //         00492909     MOV        EAX,[rge_base_game]                              = 00000000
    //         0049290e     MOV        this,dword ptr [EAX + 0x64]
    //                              scr_cred.cpp:166 (4)
    //         00492911     TEST       this,this
    //         00492913     JZ         LAB_00492936
    //                              scr_cred.cpp:167 (18)
    //         00492915     CMP        byte ptr [ECX + this->_padding_],0x1
    //         0049291c     JNZ        LAB_00492936
    //         0049291e     CMP        dword ptr [ECX + this->_padding_],0xf
    //         00492925     JNZ        LAB_00492936
    //                              scr_cred.cpp:168 (15)
    //         00492927     PUSH       0x0
    //         00492929     PUSH       0x0
    //         0049292b     PUSH       0x1
    //         0049292d     PUSH       0xf
    //         0049292f     PUSH       0xf
    //         00492931     CALL       TMusic_System::play_tracks                       int play_tracks(TMusic_System * this, int par
    //                               LAB_00492936                                                 XREF[3]:     00492913(j), 0049291c(j), 
    //                                                                                                         00492925(j)  
    //                              scr_cred.cpp:169 (21)
    //         00492936     MOV        this,dword ptr [ESP + local_c]
    //         0049293a     POP        EDI
    //         0049293b     MOV        EAX,EBP
    //         0049293d     POP        ESI
    //         0049293e     POP        EBP
    //         0049293f     MOV        dword ptr FS:[0x0],this
    //         00492946     POP        EBX
    //         00492947     ADD        ESP,0x24
    //         0049294a     RET
}

// Offset: 0x00492970
void TRIBE_Credits_Screen(TRIBE_Credits_Screen* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual __thiscall TRIBE_Credits_Screen::~TRIBE_Credits_Screen(void)                          *
    //                              *********************************************************************************************************
    //                              void __thiscall ~TRIBE_Credits_Screen(TRIBE_Credits_Screen * this)
    //              void              <VOID>         <RETURN>
    //              TRIBE_Credits_    ECX:4 (auto)   this
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     00492997(W)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     0049298c(W)  
    //                               ??1TRIBE_Credits_Screen@@UAE@XZ                              XREF[1]:     `scalar_deleting_destructor':00492
    //                               TRIBE_Credits_Screen::~TRIBE_Credits_Screen
    //                              scr_cred.cpp:173 (58)
    //         00492970     PUSH       -0x1
    //         00492972     PUSH       FUN_0055eae8
    //         00492977     MOV        EAX,FS:[0x0]
    //         0049297d     PUSH       EAX
    //         0049297e     MOV        dword ptr FS:[0x0],ESP
    //         00492985     PUSH       this
    //         00492986     PUSH       EBX
    //         00492987     PUSH       EBP
    //         00492988     MOV        EBP,this
    //         0049298a     PUSH       ESI
    //         0049298b     PUSH       EDI
    //         0049298c     MOV        dword ptr [ESP + local_10],EBP
    //         00492990     MOV        dword ptr [EBP],TRIBE_Credits_Screen::`vftable'  = 00492950
    //         00492997     MOV        dword ptr [ESP + local_4],0x0
    //         0049299f     LEA        EDI,[EBP + 0x894]
    //         004929a5     MOV        EBX,0x7
    //                               LAB_004929aa                                                 XREF[1]:     004929ca(j)  
    //                              scr_cred.cpp:178 (6)
    //         004929aa     MOV        ESI,dword ptr [EDI]
    //         004929ac     TEST       ESI,ESI
    //         004929ae     JZ         LAB_004929c6
    //                              scr_cred.cpp:180 (16)
    //         004929b0     MOV        this,ESI
    //         004929b2     CALL       TShape::~TShape                                  void ~TShape(TShape * this)
    //         004929b7     PUSH       ESI
    //         004929b8     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         004929bd     ADD        ESP,0x4
    //                              scr_cred.cpp:181 (12)
    //         004929c0     MOV        dword ptr [EDI],0x0
    //                               LAB_004929c6                                                 XREF[1]:     004929ae(j)  
    //         004929c6     ADD        EDI,0x4
    //         004929c9     DEC        EBX
    //         004929ca     JNZ        LAB_004929aa
    //                              scr_cred.cpp:186 (20)
    //         004929cc     MOV        this,dword ptr [EBP + 0x478]
    //         004929d2     MOV        dword ptr [EBP + 0x204],0x0
    //         004929dc     TEST       this,this
    //         004929de     JZ         LAB_004929f0
    //                              scr_cred.cpp:188 (6)
    //         004929e0     MOV        EAX,dword ptr [this->_padding_]
    //         004929e2     PUSH       0x1
    //         004929e4     CALL       dword ptr [EAX]
    //                              scr_cred.cpp:189 (10)
    //         004929e6     MOV        dword ptr [EBP + 0x478],0x0
    //                               LAB_004929f0                                                 XREF[1]:     004929de(j)  
    //                              scr_cred.cpp:202 (9)
    //         004929f0     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004929f6     MOV        this,dword ptr [ECX + this->_padding_]
    //                              scr_cred.cpp:203 (4)
    //         004929f9     TEST       this,this
    //         004929fb     JZ         LAB_00492a1e
    //                              scr_cred.cpp:204 (18)
    //         004929fd     CMP        byte ptr [ECX + this->_padding_],0x1
    //         00492a04     JNZ        LAB_00492a1e
    //         00492a06     CMP        dword ptr [ECX + this->_padding_],0xf
    //         00492a0d     JNZ        LAB_00492a1e
    //                              scr_cred.cpp:205 (17)
    //         00492a0f     PUSH       0x0
    //         00492a11     PUSH       0x0=>DAT_fffffff8
    //         00492a13     PUSH       offset DAT_fffffff4
    //         00492a15     PUSH       offset DAT_fffffff0
    //         00492a17     PUSH       0x5
    //         00492a19     CALL       TMusic_System::play_tracks                       int play_tracks(TMusic_System * this, int par
    //                               LAB_00492a1e                                                 XREF[3]:     004929fb(j), 00492a04(j), 
    //                                                                                                         00492a0d(j)  
    //         00492a1e     MOV        this,EBP
    //                              scr_cred.cpp:206 (32)
    //         00492a20     MOV        dword ptr [ESP + 0x1c],0xffffffff
    //         00492a28     CALL       TScreenPanel::~TScreenPanel                      void ~TScreenPanel(TScreenPanel * this)
    //         00492a2d     MOV        this,dword ptr [ESP + 0x14]
    //         00492a31     POP        EDI
    //         00492a32     POP        ESI
    //         00492a33     POP        EBP
    //         00492a34     MOV        dword ptr FS:[0x0],this
    //         00492a3b     POP        EBX
    //         00492a3c     ADD        ESP,0x10
    //         00492a3f     RET
}

// Offset: 0x00492A40
long TRIBE_Credits_Screen::handle_mouse_down(uchar param_1, long param_2, long param_3, int param_4, int param_5) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual long __thiscall TRIBE_Credits_Screen::handle_mouse_down(unsigned char,long,long,in... *
    //                              *********************************************************************************************************
    //                              long __thiscall handle_mouse_down(TRIBE_Credits_Screen * this, uchar
    //              long              EAX:4          <RETURN>
    //              TRIBE_Credits_    ECX:4 (auto)   this
    //              uchar             Stack[0x4]:1   param_1
    //              long              Stack[0x8]:4   param_2
    //              long              Stack[0xc]:4   param_3
    //              int               Stack[0x10]:4  param_4
    //              int               Stack[0x14]:4  param_5
    //                               ?handle_mouse_down@TRIBE_Credits_Screen@@UAEJEJJHH@Z         XREF[1]:     005727c0(*)  
    //                               TRIBE_Credits_Screen::handle_mouse_down
    //                              scr_cred.cpp:210 (5)
    //         00492a40     CALL       TRIBE_Credits_Screen::close_screen               void close_screen(TRIBE_Credits_Screen * this)
    //                              scr_cred.cpp:212 (5)
    //         00492a45     MOV        EAX,0x1
    //                              scr_cred.cpp:213 (3)
    //         00492a4a     RET        0x14
}

// Offset: 0x00492A50
long TRIBE_Credits_Screen::handle_idle() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual long __thiscall TRIBE_Credits_Screen::handle_idle(void)                               *
    //                              *********************************************************************************************************
    //                              long __thiscall handle_idle(TRIBE_Credits_Screen * this)
    //              long              EAX:4          <RETURN>
    //              TRIBE_Credits_    ECX:4 (auto)   this
    //                               ?handle_idle@TRIBE_Credits_Screen@@UAEJXZ                    XREF[1]:     0057279c(*)  
    //                               TRIBE_Credits_Screen::handle_idle
    //                              scr_cred.cpp:217 (4)
    //         00492a50     PUSH       ESI
    //         00492a51     MOV        ESI,this
    //         00492a53     PUSH       EDI
    //                              scr_cred.cpp:238 (15)
    //         00492a54     MOV        EAX,dword ptr [ESI + 0x48c]
    //         00492a5a     CMP        EAX,0x1
    //         00492a5d     JNZ        LAB_00492b36
    //                              scr_cred.cpp:240 (10)
    //         00492a63     MOV        EAX,dword ptr [ESI + 0x484]
    //         00492a69     TEST       EAX,EAX
    //         00492a6b     JNZ        LAB_00492a77
    //                              scr_cred.cpp:241 (5)
    //         00492a6d     PUSH       0xf1
    //                              scr_cred.cpp:242 (5)
    //         00492a72     JMP        LAB_00492c7e
    //                               LAB_00492a77                                                 XREF[1]:     00492a6b(j)  
    //                              scr_cred.cpp:245 (15)
    //         00492a77     PUSH       0xf5
    //         00492a7c     PUSH       s_C:\msdev\work\age1_x1\scr_cred.c               = "C:\\msdev\\work\\age1_x1\\scr_cred.cpp"
    //         00492a81     CALL       debug_timeGetTime                                ulong debug_timeGetTime(char * param_1, int p
    //                              scr_cred.cpp:246 (22)
    //         00492a86     MOV        EDX,dword ptr [ESI + 0x484]
    //         00492a8c     ADD        ESP,0x8
    //         00492a8f     SUB        EAX,EDX
    //         00492a91     CMP        EAX,0x2710
    //         00492a96     JC         LAB_00492c91
    //                              scr_cred.cpp:248 (23)
    //         00492a9c     MOV        this,dword ptr [ESI + 0x20]
    //         00492a9f     MOV        EAX,dword ptr [this->_padding_]
    //         00492aa1     CMP        byte ptr [EAX + 0x479],0x2
    //         00492aa8     JZ         LAB_00492ac2
    //         00492aaa     CMP        byte ptr [EAX + 0x478],0x1
    //         00492ab1     JZ         LAB_00492ac2
    //                              scr_cred.cpp:264 (15)
    //         00492ab3     MOV        dword ptr [ESI + 0x48c],0x4
    //         00492abd     JMP        LAB_00492c91
    //                               LAB_00492ac2                                                 XREF[2]:     00492aa8(j), 00492ab1(j)  
    //                              scr_cred.cpp:256 (41)
    //         00492ac2     MOV        EAX,dword ptr [ESI + 0x20c]
    //         00492ac8     MOV        dword ptr [ESI + 0x48c],0x2
    //         00492ad2     TEST       EAX,EAX
    //         00492ad4     MOV        byte ptr [ESI + 0x890],0x0
    //         00492adb     MOV        byte ptr [ESI + 0x891],0x0
    //         00492ae2     MOV        byte ptr [ESI + 0x892],0x0
    //         00492ae9     JNZ        LAB_00492af9
    //                              scr_cred.cpp:257 (12)
    //         00492aeb     LEA        EAX,[ESI + 0x490]
    //         00492af1     PUSH       EAX
    //         00492af2     CALL       TDrawArea::GetPalette                            void GetPalette(TDrawArea * this, tagPALETTEE
    //                              scr_cred.cpp:258 (2)
    //         00492af7     JMP        LAB_00492b0e
    //                               LAB_00492af9                                                 XREF[1]:     00492ae9(j)  
    //                              scr_cred.cpp:259 (21)
    //         00492af9     LEA        this,[ESI + 0x490]
    //         00492aff     PUSH       this
    //         00492b00     PUSH       0x100
    //         00492b05     PUSH       0x0
    //         00492b07     PUSH       EAX
    //         00492b08     CALL       dword ptr [->GDI32.DLL::GetPaletteEntries]       = 0048b270
    //                               LAB_00492b0e                                                 XREF[1]:     00492af7(j)  
    //                              scr_cred.cpp:261 (35)
    //         00492b0e     MOV        EDX,dword ptr [ESI + 0x890]
    //         00492b14     MOV        EAX,dword ptr [ESI + 0x20]
    //         00492b17     PUSH       -0x1
    //         00492b19     PUSH       0xff
    //         00492b1e     PUSH       0x0
    //         00492b20     PUSH       0x1
    //         00492b22     PUSH       0x3f000000
    //         00492b27     PUSH       EDX
    //         00492b28     PUSH       EAX
    //         00492b29     CALL       RGE_fade_palette_start                           void RGE_fade_palette_start(TDrawArea * param
    //         00492b2e     ADD        ESP,0x1c
    //                              scr_cred.cpp:268 (10)
    //         00492b31     JMP        LAB_00492c91
    //                               LAB_00492b36                                                 XREF[1]:     00492a5d(j)  
    //         00492b36     CMP        EAX,0x2
    //         00492b39     JNZ        LAB_00492b7b
    //                              scr_cred.cpp:270 (13)
    //         00492b3b     CALL       RGE_fade_palette_step                            int RGE_fade_palette_step(void)
    //         00492b40     TEST       EAX,EAX
    //         00492b42     JZ         LAB_00492c91
    //                              scr_cred.cpp:274 (29)
    //         00492b48     MOV        EDI,dword ptr [ESI]
    //         00492b4a     PUSH       0x1
    //         00492b4c     MOV        this,ESI
    //         00492b4e     MOV        dword ptr [ESI + 0x48c],0x4
    //         00492b58     MOV        dword ptr [ESI + 0x488],0x0
    //         00492b62     CALL       dword ptr [EDI + 0x20]
    //                              scr_cred.cpp:275 (5)
    //         00492b65     MOV        this,ESI
    //         00492b67     CALL       dword ptr [EDI + 0x54]
    //                              scr_cred.cpp:276 (12)
    //         00492b6a     MOV        this,dword ptr [ESI + 0x20]
    //         00492b6d     PUSH       0x0
    //         00492b6f     MOV        this,dword ptr [this->_padding_]
    //         00492b71     CALL       TDrawSystem::Paint                               void Paint(TDrawSystem * this, tagRECT * para
    //                              scr_cred.cpp:279 (14)
    //         00492b76     JMP        LAB_00492c91
    //                               LAB_00492b7b                                                 XREF[1]:     00492b39(j)  
    //         00492b7b     CMP        EAX,0x4
    //         00492b7e     JNZ        LAB_00492c61
    //                              scr_cred.cpp:281 (10)
    //         00492b84     MOV        EAX,dword ptr [ESI + 0x488]
    //         00492b8a     TEST       EAX,EAX
    //         00492b8c     JNZ        LAB_00492bab
    //                              scr_cred.cpp:282 (24)
    //         00492b8e     PUSH       0x11a
    //         00492b93     PUSH       s_C:\msdev\work\age1_x1\scr_cred.c               = "C:\\msdev\\work\\age1_x1\\scr_cred.cpp"
    //         00492b98     CALL       debug_timeGetTime                                ulong debug_timeGetTime(char * param_1, int p
    //         00492b9d     ADD        ESP,0x8
    //         00492ba0     MOV        dword ptr [ESI + 0x488],EAX
    //                              scr_cred.cpp:283 (5)
    //         00492ba6     JMP        LAB_00492c91
    //                               LAB_00492bab                                                 XREF[1]:     00492b8c(j)  
    //                              scr_cred.cpp:286 (15)
    //         00492bab     PUSH       0x11e
    //         00492bb0     PUSH       s_C:\msdev\work\age1_x1\scr_cred.c               = "C:\\msdev\\work\\age1_x1\\scr_cred.cpp"
    //         00492bb5     CALL       debug_timeGetTime                                ulong debug_timeGetTime(char * param_1, int p
    //                              scr_cred.cpp:292 (20)
    //         00492bba     MOV        this,dword ptr [ESI + 0x480]
    //         00492bc0     ADD        ESP,0x8
    //         00492bc3     INC        this
    //         00492bc4     MOV        dword ptr [ESI + 0x48c],0x5
    //                              scr_cred.cpp:293 (13)
    //         00492bce     MOV        EAX,this
    //         00492bd0     MOV        dword ptr [ESI + 0x480],this
    //         00492bd6     CMP        EAX,0x7
    //         00492bd9     JLE        LAB_00492be5
    //                              scr_cred.cpp:294 (10)
    //         00492bdb     MOV        dword ptr [ESI + 0x480],0x1
    //                               LAB_00492be5                                                 XREF[1]:     00492bd9(j)  
    //                              scr_cred.cpp:298 (6)
    //         00492be5     MOV        EDX,dword ptr [ESI + 0x480]
    //                              scr_cred.cpp:300 (22)
    //         00492beb     MOV        EDI,dword ptr [ESI]
    //         00492bed     PUSH       0x1
    //         00492bef     MOV        this,ESI
    //         00492bf1     MOV        EAX,dword ptr [ESI + EDX*0x4 + 0x890]
    //         00492bf8     MOV        dword ptr [ESI + 0x204],EAX
    //         00492bfe     CALL       dword ptr [EDI + 0x20]
    //                              scr_cred.cpp:301 (5)
    //         00492c01     MOV        this,ESI
    //         00492c03     CALL       dword ptr [EDI + 0x54]
    //                              scr_cred.cpp:302 (12)
    //         00492c06     MOV        this,dword ptr [ESI + 0x20]
    //         00492c09     PUSH       0x0
    //         00492c0b     MOV        this,dword ptr [this->_padding_]
    //         00492c0d     CALL       TDrawSystem::Paint                               void Paint(TDrawSystem * this, tagRECT * para
    //                              scr_cred.cpp:304 (23)
    //         00492c12     MOV        EAX,dword ptr [ESI + 0x20]
    //         00492c15     MOV        this,dword ptr [EAX]
    //         00492c17     CMP        byte ptr [ECX + this+0x479],0x2
    //         00492c1e     JZ         LAB_00492c3a
    //         00492c20     CMP        byte ptr [ECX + this->text_panel],0x1
    //         00492c27     JZ         LAB_00492c3a
    //                              scr_cred.cpp:311 (10)
    //         00492c29     MOV        dword ptr [ESI + 0x48c],0x1
    //                              scr_cred.cpp:312 (7)
    //         00492c33     PUSH       0x138
    //         00492c38     JMP        LAB_00492c7e
    //                               LAB_00492c3a                                                 XREF[2]:     00492c1e(j), 00492c27(j)  
    //                              scr_cred.cpp:307 (37)
    //         00492c3a     MOV        this,dword ptr [ESI + 0x890]
    //         00492c40     PUSH       -0x1
    //         00492c42     LEA        EDX,[ESI + 0x490]
    //         00492c48     PUSH       offset DAT_fffffff8
    //         00492c4d     PUSH       EDX=>DAT_fffffff4
    //         00492c4e     PUSH       offset DAT_fffffff0
    //         00492c50     PUSH       0x3f000000
    //         00492c55     PUSH       this
    //         00492c56     PUSH       EAX
    //         00492c57     CALL       RGE_fade_palette_start                           void RGE_fade_palette_start(TDrawArea * param
    //         00492c5c     ADD        ESP,0x1c
    //                              scr_cred.cpp:317 (7)
    //         00492c5f     JMP        LAB_00492c91
    //                               LAB_00492c61                                                 XREF[1]:     00492b7e(j)  
    //         00492c61     CMP        EAX,0x5
    //         00492c64     JNZ        LAB_00492c91
    //                              scr_cred.cpp:319 (9)
    //         00492c66     CALL       RGE_fade_palette_step                            int RGE_fade_palette_step(void)
    //         00492c6b     TEST       EAX,EAX
    //         00492c6d     JZ         LAB_00492c91
    //                              scr_cred.cpp:321 (10)
    //         00492c6f     MOV        dword ptr [ESI + 0x48c],0x1
    //                              scr_cred.cpp:322 (24)
    //         00492c79     PUSH       0x142
    //                               LAB_00492c7e                                                 XREF[2]:     00492a72(j), 00492c38(j)  
    //         00492c7e     PUSH       s_C:\msdev\work\age1_x1\scr_cred.c               = "C:\\msdev\\work\\age1_x1\\scr_cred.cpp"
    //         00492c83     CALL       debug_timeGetTime                                ulong debug_timeGetTime(char * param_1, int p
    //         00492c88     ADD        ESP,0x8
    //         00492c8b     MOV        dword ptr [ESI + 0x484],EAX
    //                               LAB_00492c91                                                 XREF[9]:     00492a96(j), 00492abd(j), 
    //                                                                                                         00492b31(j), 00492b42(j), 
    //                                                                                                         00492b76(j), 00492ba6(j), 
    //                                                                                                         00492c5f(j), 00492c64(j), 
    //                                                                                                         00492c6d(j)  
    //                              scr_cred.cpp:326 (6)
    //         00492c91     MOV        EAX,dword ptr [ESI + 0x8b4]
    //                              scr_cred.cpp:328 (11)
    //         00492c97     MOV        this,ESI
    //         00492c99     TEST       EAX,EAX
    //         00492c9b     JZ         LAB_00492caa
    //         00492c9d     CALL       TRIBE_Credits_Screen::close_screen               void close_screen(TRIBE_Credits_Screen * this)
    //                              scr_cred.cpp:329 (5)
    //         00492ca2     MOV        EAX,0x1
    //                              scr_cred.cpp:333 (3)
    //         00492ca7     POP        EDI
    //         00492ca8     POP        ESI
    //         00492ca9     RET
    //                               LAB_00492caa                                                 XREF[1]:     00492c9b(j)  
    //                              scr_cred.cpp:332 (5)
    //         00492caa     CALL       TPanel::handle_idle                              long handle_idle(TPanel * this)
    //                              scr_cred.cpp:333 (3)
    //         00492caf     POP        EDI
    //         00492cb0     POP        ESI
    //         00492cb1     RET
}

// Offset: 0x00492CC0
void TRIBE_Credits_Screen::draw() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void __thiscall TRIBE_Credits_Screen::draw(void)                                      *
    //                              *********************************************************************************************************
    //                              void __thiscall draw(TRIBE_Credits_Screen * this)
    //              void              <VOID>         <RETURN>
    //              TRIBE_Credits_    ECX:4 (auto)   this
    //                               ?draw@TRIBE_Credits_Screen@@UAEXXZ                           XREF[1]:     00572780(*)  
    //                               TRIBE_Credits_Screen::draw
    //                              scr_cred.cpp:337 (6)
    //         00492cc0     PUSH       EBX
    //         00492cc1     PUSH       EBP
    //         00492cc2     PUSH       ESI
    //         00492cc3     MOV        ESI,this
    //         00492cc5     PUSH       EDI
    //                              scr_cred.cpp:346 (32)
    //         00492cc6     CMP        dword ptr [ESI + 0x48c],0x4
    //         00492ccd     JNZ        LAB_00492cf6
    //         00492ccf     MOV        this,dword ptr [ESI + 0x20]
    //         00492cd2     MOV        EAX,dword ptr [this->_padding_]
    //         00492cd4     CMP        byte ptr [EAX + 0x479],0x2
    //         00492cdb     JZ         LAB_00492ce6
    //         00492cdd     CMP        byte ptr [EAX + 0x478],0x1
    //         00492ce4     JNZ        LAB_00492cf6
    //                               LAB_00492ce6                                                 XREF[1]:     00492cdb(j)  
    //                              scr_cred.cpp:347 (11)
    //         00492ce6     ADD        ESI,0x24
    //         00492ce9     PUSH       0x0
    //         00492ceb     PUSH       ESI
    //         00492cec     CALL       TDrawArea::Clear                                 void Clear(TDrawArea * this, tagRECT * param_
    //                              scr_cred.cpp:363 (5)
    //         00492cf1     POP        EDI
    //         00492cf2     POP        ESI
    //         00492cf3     POP        EBP
    //         00492cf4     POP        EBX
    //         00492cf5     RET
    //                               LAB_00492cf6                                                 XREF[2]:     00492ccd(j), 00492ce4(j)  
    //                              scr_cred.cpp:350 (10)
    //         00492cf6     MOV        EAX,dword ptr [ESI + 0x8b0]
    //         00492cfc     TEST       EAX,EAX
    //         00492cfe     JZ         LAB_00492d35
    //                              scr_cred.cpp:363 (65)
    //         00492d00     LEA        EBP,[ESI + 0x894]
    //         00492d06     MOV        EBX,0x7
    //         00492d0b     MOV        EDI,EBP
    //                               LAB_00492d0d                                                 XREF[1]:     00492d20(j)  
    //         00492d0d     MOV        EAX,dword ptr [EDI]
    //         00492d0f     MOV        this,ESI
    //         00492d11     MOV        dword ptr [ESI + 0x204],EAX
    //         00492d17     CALL       TScreenPanel::draw                               void draw(TScreenPanel * this)
    //         00492d1c     ADD        EDI,0x4
    //         00492d1f     DEC        EBX
    //         00492d20     JNZ        LAB_00492d0d
    //         00492d22     MOV        this,dword ptr [EBP]
    //         00492d25     MOV        dword ptr [ESI + 0x8b0],0x0
    //         00492d2f     MOV        dword ptr [ESI + 0x204],this
    //                               LAB_00492d35                                                 XREF[1]:     00492cfe(j)  
    //         00492d35     MOV        this,ESI
    //         00492d37     CALL       TScreenPanel::draw                               void draw(TScreenPanel * this)
    //         00492d3c     POP        EDI
    //         00492d3d     POP        ESI
    //         00492d3e     POP        EBP
    //         00492d3f     POP        EBX
    //         00492d40     RET
}

// Offset: 0x00492D50
long TRIBE_Credits_Screen::key_down_action(long param_1, short param_2, int param_3, int param_4, int param_5) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual long __thiscall TRIBE_Credits_Screen::key_down_action(long,short,int,int,int)         *
    //                              *********************************************************************************************************
    //                              long __thiscall key_down_action(TRIBE_Credits_Screen * this, long pa
    //              long              EAX:4          <RETURN>
    //              TRIBE_Credits_    ECX:4 (auto)   this
    //              long              Stack[0x4]:4   param_1                   XREF[1]:     00492d50(R)  
    //              short             Stack[0x8]:2   param_2
    //              int               Stack[0xc]:4   param_3
    //              int               Stack[0x10]:4  param_4
    //              int               Stack[0x14]:4  param_5
    //                               ?key_down_action@TRIBE_Credits_Screen@@UAEJJFHHH@Z           XREF[1]:     005727fc(*)  
    //                               TRIBE_Credits_Screen::key_down_action
    //                              scr_cred.cpp:367 (14)
    //         00492d50     MOV        EAX,dword ptr [ESP + param_1]
    //         00492d54     CMP        EAX,0xd
    //         00492d57     JZ         LAB_00492d63
    //         00492d59     CMP        EAX,0x1b
    //         00492d5c     JZ         LAB_00492d63
    //                              scr_cred.cpp:376 (2)
    //         00492d5e     XOR        EAX,EAX
    //                              scr_cred.cpp:377 (3)
    //         00492d60     RET        0x14
    //                               LAB_00492d63                                                 XREF[2]:     00492d57(j), 00492d5c(j)  
    //                              scr_cred.cpp:372 (5)
    //         00492d63     CALL       TRIBE_Credits_Screen::close_screen               void close_screen(TRIBE_Credits_Screen * this)
    //                              scr_cred.cpp:373 (5)
    //         00492d68     MOV        EAX,0x1
    //                              scr_cred.cpp:377 (3)
    //         00492d6d     RET        0x14
}

// Offset: 0x00492D70
long TRIBE_Credits_Screen::action(TPanel* param_1, long param_2, ulong param_3, ulong param_4) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual long __thiscall TRIBE_Credits_Screen::action(class TPanel *,long,unsigned long,uns... *
    //                              *********************************************************************************************************
    //                              long __thiscall action(TRIBE_Credits_Screen * this, TPanel * param_1
    //              long              EAX:4          <RETURN>
    //              TRIBE_Credits_    ECX:4 (auto)   this
    //              TPanel *          Stack[0x4]:4   param_1                   XREF[1]:     00492d70(R)  
    //              long              Stack[0x8]:4   param_2                   XREF[1]:     00492d74(R)  
    //              ulong             Stack[0xc]:4   param_3                   XREF[1]:     00492d9b(R)  
    //              ulong             Stack[0x10]:4  param_4                   XREF[1]:     00492d96(R)  
    //                               ?action@TRIBE_Credits_Screen@@UAEJPAVTPanel@@JKK@Z           XREF[1]:     00572804(*)  
    //                               TRIBE_Credits_Screen::action
    //                              scr_cred.cpp:381 (13)
    //         00492d70     MOV        EAX,dword ptr [ESP + param_1]
    //         00492d74     MOV        EDX,dword ptr [ESP + param_2]
    //         00492d78     TEST       EAX,EAX
    //         00492d7a     PUSH       ESI
    //         00492d7b     JZ         LAB_00492d96
    //                              scr_cred.cpp:384 (13)
    //         00492d7d     CMP        EAX,dword ptr [ECX + this->text_panel]
    //         00492d83     JNZ        LAB_00492d96
    //         00492d85     CMP        EDX,0x1
    //         00492d88     JNZ        LAB_00492d96
    //                              scr_cred.cpp:386 (6)
    //         00492d8a     MOV        dword ptr [ECX + this->text_done],EDX
    //                              scr_cred.cpp:411 (2)
    //         00492d90     MOV        EAX,EDX
    //                              scr_cred.cpp:416 (4)
    //         00492d92     POP        ESI
    //         00492d93     RET        0x10
    //                               LAB_00492d96                                                 XREF[3]:     00492d7b(j), 00492d83(j), 
    //                                                                                                         00492d88(j)  
    //                              scr_cred.cpp:415 (17)
    //         00492d96     MOV        ESI,dword ptr [ESP + param_4]
    //         00492d9a     PUSH       ESI
    //         00492d9b     MOV        ESI,dword ptr [ESP + param_3]
    //         00492d9f     PUSH       ESI
    //         00492da0     PUSH       EDX
    //         00492da1     PUSH       EAX
    //         00492da2     CALL       TEasy_Panel::action                              long action(TEasy_Panel * this, TPanel * para
    //                              scr_cred.cpp:416 (4)
    //         00492da7     POP        ESI
    //         00492da8     RET        0x10
}

// Offset: 0x00492DB0
void close_screen(TRIBE_Credits_Screen* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TRIBE_Credits_Screen::close_screen(void)                                      *
    //                              *********************************************************************************************************
    //                              void __thiscall close_screen(TRIBE_Credits_Screen * this)
    //              void              <VOID>         <RETURN>
    //              TRIBE_Credits_    ECX:4 (auto)   this
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     00492e1e(W), 00492e31(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     00492e57(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     00492e18(*)  
    //                               ?close_screen@TRIBE_Credits_Screen@@QAEXXZ                   XREF[3]:     handle_mouse_down:00492a40(c), 
    //                               TRIBE_Credits_Screen::close_screen                                        handle_idle:00492c9d(c), 
    //                                                                                                         key_down_action:00492d63(c)  
    //                              scr_cred.cpp:420 (22)
    //         00492db0     PUSH       -0x1
    //         00492db2     PUSH       FUN_0055eb0b
    //         00492db7     MOV        EAX,FS:[0x0]
    //         00492dbd     PUSH       EAX
    //         00492dbe     MOV        dword ptr FS:[0x0],ESP
    //         00492dc5     PUSH       this
    //                              scr_cred.cpp:421 (19)
    //         00492dc6     PUSH       s_Game_Screen                                    = "Game Screen"
    //         00492dcb     MOV        this,panel_system
    //         00492dd0     CALL       TPanelSystem::panel                              TPanel * panel(TPanelSystem * this, char * pa
    //         00492dd5     TEST       EAX,EAX
    //         00492dd7     JZ         LAB_00492e0b
    //                              scr_cred.cpp:423 (32)
    //         00492dd9     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         00492ddf     CALL       RGE_Base_Game::singlePlayerGame                  int singlePlayerGame(RGE_Base_Game * this)
    //         00492de4     CMP        EAX,0x1
    //         00492de7     JNZ        LAB_00492e02
    //         00492de9     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         00492def     MOV        EAX,dword ptr [this->_padding_ + 0xa00]
    //         00492df5     TEST       EAX,EAX
    //         00492df7     JNZ        LAB_00492e02
    //                              scr_cred.cpp:424 (9)
    //         00492df9     PUSH       0x0
    //         00492dfb     PUSH       0x0
    //         00492dfd     CALL       RGE_Base_Game::set_paused                        void set_paused(RGE_Base_Game * this, int par
    //                               LAB_00492e02                                                 XREF[2]:     00492de7(j), 00492df7(j)  
    //                              scr_cred.cpp:425 (7)
    //         00492e02     PUSH       0x0
    //         00492e04     PUSH       s_Game_Screen                                    = "Game Screen"
    //                              scr_cred.cpp:427 (2)
    //         00492e09     JMP        LAB_00492e3e
    //                              language.dll match for 0x4b0: "Ready"
    //                               LAB_00492e0b                                                 XREF[1]:     00492dd7(j)  
    //                              scr_cred.cpp:429 (36)
    //         00492e0b     PUSH       0x4b0
    //         00492e10     CALL       operator_new                                     void * operator_new(uint param_1)
    //         00492e15     ADD        ESP,0x4
    //         00492e18     MOV        dword ptr [ESP]=>local_10,EAX
    //         00492e1c     TEST       EAX,EAX
    //         00492e1e     MOV        dword ptr [ESP + local_4],0x0
    //         00492e26     JZ         LAB_00492e2f
    //         00492e28     MOV        this,EAX
    //         00492e2a     CALL       TRIBE_Screen_Main_Menu::TRIBE_Screen_Main_Menu   undefined TRIBE_Screen_Main_Menu(TRIBE_Screen
    //                               LAB_00492e2f                                                 XREF[1]:     00492e26(j)  
    //                              scr_cred.cpp:430 (25)
    //         00492e2f     PUSH       0x0
    //         00492e31     MOV        dword ptr [ESP + local_4],0xffffffff
    //         00492e39     PUSH       s_Main_Menu                                      = "Main Menu"
    //                               LAB_00492e3e                                                 XREF[1]:     00492e09(j)  
    //         00492e3e     MOV        this,panel_system
    //         00492e43     CALL       TPanelSystem::setCurrentPanel                    int setCurrentPanel(TPanelSystem * this, char
    //                              scr_cred.cpp:432 (15)
    //         00492e48     PUSH       s_Credits_Screen                                 = "Credits Screen"
    //         00492e4d     MOV        this,panel_system
    //         00492e52     CALL       TPanelSystem::destroyPanel                       int destroyPanel(TPanelSystem * this, char * 
    //                              scr_cred.cpp:433 (15)
    //         00492e57     MOV        this,dword ptr [ESP + local_c]
    //         00492e5b     MOV        dword ptr FS:[0x0],this
    //         00492e62     ADD        ESP,0x10
    //         00492e65     RET
}

// Offset: 0x00492E70
undefined TScrollTextPanel(TScrollTextPanel* this_, TPanel* param_2, TDrawArea* param_3, long param_4, long param_5, long param_6, long param_7, int param_8, void* param_9, long param_10, long param_11, char* param_12) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall TScrollTextPanel::TScrollTextPanel(class TPanel *,class TDrawArea *,long,long,l... *
    //                              *********************************************************************************************************
    //                              undefined __thiscall TScrollTextPanel(TScrollTextPanel * this, TPane
    //              undefined         <UNASSIGNED>   <RETURN>
    //              TScrollTextPan    ECX:4 (auto)   this
    //              TPanel *          Stack[0x4]:4   param_1                   XREF[1]:     00492ec7(R)  
    //              TDrawArea *       Stack[0x8]:4   param_2                   XREF[1]:     00492ecc(R)  
    //              long              Stack[0xc]:4   param_3                   XREF[1]:     00492ec2(R)  
    //              long              Stack[0x10]:4  param_4                   XREF[1]:     00492ebd(R)  
    //              long              Stack[0x14]:4  param_5                   XREF[1]:     00492eb8(R)  
    //              long              Stack[0x18]:4  param_6                   XREF[1]:     00492eb3(R)  
    //              int               Stack[0x1c]:4  param_7                   XREF[1]:     00492e93(R)  
    //              void *            Stack[0x20]:4  param_8                   XREF[1]:     00492ead(R)  
    //              long              Stack[0x24]:4  param_9                   XREF[1]:     00492e9d(R)  
    //              long              Stack[0x28]:4  param_10                  XREF[1]:     00492e97(R)  
    //              char *            Stack[0x2c]:4  param_11                  XREF[1]:     00492f0d(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     00492ed5(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     00492f2e(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     00492e8a(W)  
    //                               ??0TScrollTextPanel@@QAE@PAVTPanel@@PAVTDrawArea@@JJJJHPAXJ  XREF[1]:     TRIBE_Credits_Screen:0049287a(c)  
    //                               TScrollTextPanel::TScrollTextPanel
    //                              scr_cred.cpp:440 (35)
    //         00492e70     PUSH       -0x1
    //         00492e72     PUSH       FUN_0055eb28
    //         00492e77     MOV        EAX,FS:[0x0]
    //         00492e7d     PUSH       EAX
    //         00492e7e     MOV        dword ptr FS:[0x0],ESP
    //         00492e85     PUSH       this
    //         00492e86     PUSH       ESI
    //         00492e87     MOV        ESI,this
    //         00492e89     PUSH       EDI
    //         00492e8a     MOV        dword ptr [ESP + local_10],ESI
    //         00492e8e     CALL       TTextPanel::TTextPanel                           undefined TTextPanel(TTextPanel * this)
    //                              scr_cred.cpp:444 (4)
    //         00492e93     MOV        EAX,dword ptr [ESP + param_7]
    //                              scr_cred.cpp:449 (99)
    //         00492e97     MOV        this,dword ptr [ESP + param_10]
    //         00492e9b     XOR        EDI,EDI
    //         00492e9d     MOV        EDX,dword ptr [ESP + param_9]
    //         00492ea1     PUSH       EDI
    //         00492ea2     PUSH       EDI
    //         00492ea3     PUSH       EDI
    //         00492ea4     PUSH       EDI
    //         00492ea5     PUSH       EDI
    //         00492ea6     PUSH       EDI
    //         00492ea7     MOV        dword ptr [ESI + 0x190],EAX
    //         00492ead     MOV        EAX,dword ptr [ESP + param_8]
    //         00492eb1     PUSH       EDI
    //         00492eb2     PUSH       this
    //         00492eb3     MOV        this,dword ptr [ESP + param_6]
    //         00492eb7     PUSH       EDX
    //         00492eb8     MOV        EDX,dword ptr [ESP + param_5]
    //         00492ebc     PUSH       EAX
    //         00492ebd     MOV        EAX,dword ptr [ESP + param_4]
    //         00492ec1     PUSH       this
    //         00492ec2     MOV        this,dword ptr [ESP + param_3]
    //         00492ec6     PUSH       EDX
    //         00492ec7     MOV        EDX,dword ptr [ESP + param_1]
    //         00492ecb     PUSH       EAX
    //         00492ecc     MOV        EAX,dword ptr [ESP + param_2]
    //         00492ed0     PUSH       this
    //         00492ed1     PUSH       EDX
    //         00492ed2     PUSH       EAX
    //         00492ed3     MOV        this,ESI
    //         00492ed5     MOV        dword ptr [ESP + local_4],EDI
    //         00492ed9     MOV        dword ptr [ESI],TScrollTextPanel::`vftable'      = 00492f50
    //         00492edf     MOV        dword ptr [ESI + 0x188],EDI
    //         00492ee5     MOV        dword ptr [ESI + 0x18c],EDI
    //         00492eeb     MOV        dword ptr [ESI + 0x194],EDI
    //         00492ef1     CALL       TTextPanel::setup                                long setup(TTextPanel * this, TDrawArea * par
    //         00492ef6     TEST       EAX,EAX
    //         00492ef8     JZ         LAB_00492f2e
    //                              scr_cred.cpp:451 (10)
    //         00492efa     PUSH       EDI
    //         00492efb     PUSH       0x3
    //         00492efd     MOV        this,ESI
    //         00492eff     CALL       TTextPanel::set_alignment                        void set_alignment(TTextPanel * this, Alignme
    //                              scr_cred.cpp:452 (9)
    //         00492f04     PUSH       0x1
    //         00492f06     MOV        this,ESI
    //         00492f08     CALL       TTextPanel::set_word_wrap                        void set_word_wrap(TTextPanel * this, int par
    //                              scr_cred.cpp:453 (12)
    //         00492f0d     MOV        this,dword ptr [ESP + param_11]
    //         00492f11     PUSH       this
    //         00492f12     MOV        this,ESI
    //         00492f14     CALL       TScrollTextPanel::set_text                       void set_text(TScrollTextPanel * this, char *
    //                              scr_cred.cpp:454 (21)
    //         00492f19     MOV        EDX,dword ptr [ESI + 0x124]
    //         00492f1f     MOV        EAX,dword ptr [ESI + 0x120]
    //         00492f25     PUSH       EDX
    //         00492f26     PUSH       EAX
    //         00492f27     MOV        this,ESI
    //         00492f29     CALL       TTextPanel::set_text_color                       void set_text_color(TTextPanel * this, ulong 
    //                               LAB_00492f2e                                                 XREF[1]:     00492ef8(j)  
    //                              scr_cred.cpp:456 (21)
    //         00492f2e     MOV        this,dword ptr [ESP + local_c]
    //         00492f32     MOV        EAX,ESI
    //         00492f34     POP        EDI
    //         00492f35     MOV        dword ptr FS:[0x0],this
    //         00492f3c     POP        ESI
    //         00492f3d     ADD        ESP,0x10
    //         00492f40     RET        0x2c
}

// Offset: 0x00492F70
void TScrollTextPanel(TScrollTextPanel* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual __thiscall TScrollTextPanel::~TScrollTextPanel(void)                                  *
    //                              *********************************************************************************************************
    //                              void __thiscall ~TScrollTextPanel(TScrollTextPanel * this)
    //              void              <VOID>         <RETURN>
    //              TScrollTextPan    ECX:4 (auto)   this
    //                               ??1TScrollTextPanel@@UAE@XZ                                  XREF[1]:     `vector_deleting_destructor':00492
    //                               TScrollTextPanel::~TScrollTextPanel
    //                              scr_cred.cpp:460 (11)
    //         00492f70     MOV        dword ptr [this->_padding_],TScrollTextPanel::   = 00492f50
    //         00492f76     JMP        TTextPanel::~TTextPanel                          void ~TTextPanel(TTextPanel * this)
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
}

// Offset: 0x00492F80
void TScrollTextPanel::set_text(char* param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void __thiscall TScrollTextPanel::set_text(char *)                                    *
    //                              *********************************************************************************************************
    //                              void __thiscall set_text(TScrollTextPanel * this, char * param_1)
    //              void              <VOID>         <RETURN>
    //              TScrollTextPan    ECX:4 (auto)   this
    //              char *            Stack[0x4]:4   param_1                   XREF[1]:     00492f80(R)  
    //                               ?set_text@TScrollTextPanel@@UAEXPAD@Z                        XREF[2]:     TScrollTextPanel:00492f14(c), 
    //                               TScrollTextPanel::set_text                                                00572960(*)  
    //                              scr_cred.cpp:465 (13)
    //         00492f80     MOV        EAX,dword ptr [ESP + param_1]
    //         00492f84     PUSH       ESI
    //         00492f85     MOV        ESI,this
    //         00492f87     PUSH       EAX
    //         00492f88     CALL       TTextPanel::set_text                             void set_text(TTextPanel * this, char * param
    //                              scr_cred.cpp:467 (8)
    //         00492f8d     XOR        EAX,EAX
    //         00492f8f     MOV        dword ptr [ESI + 0x18c],EAX
    //                              scr_cred.cpp:468 (6)
    //         00492f95     MOV        dword ptr [ESI + 0x188],EAX
    //                              scr_cred.cpp:469 (6)
    //         00492f9b     MOV        dword ptr [ESI + 0x194],EAX
    //                              scr_cred.cpp:470 (4)
    //         00492fa1     POP        ESI
    //         00492fa2     RET        0x4
}

// Offset: 0x00492FB0
long TScrollTextPanel::handle_idle() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual long __thiscall TScrollTextPanel::handle_idle(void)                                   *
    //                              *********************************************************************************************************
    //                              long __thiscall handle_idle(TScrollTextPanel * this)
    //              long              EAX:4          <RETURN>
    //              TScrollTextPan    ECX:4 (auto)   this
    //              undefined8        Stack[-0x8]:8  local_8                   XREF[2,1]:   00492ffc(W), 00493003(R), 00492ff4(W)  
    //                               ?handle_idle@TScrollTextPanel@@UAEJXZ                        XREF[1]:     005728c4(*)  
    //                               TScrollTextPanel::handle_idle
    //                              scr_cred.cpp:474 (7)
    //         00492fb0     SUB        ESP,0x8
    //         00492fb3     PUSH       ESI
    //         00492fb4     MOV        ESI,this
    //         00492fb6     PUSH       EDI
    //                              scr_cred.cpp:475 (10)
    //         00492fb7     MOV        EAX,dword ptr [ESI + 0x18c]
    //         00492fbd     TEST       EAX,EAX
    //         00492fbf     JNZ        LAB_00492fdb
    //                              scr_cred.cpp:476 (24)
    //         00492fc1     PUSH       0x1dc
    //         00492fc6     PUSH       s_C:\msdev\work\age1_x1\scr_cred.c               = "C:\\msdev\\work\\age1_x1\\scr_cred.cpp"
    //         00492fcb     CALL       debug_timeGetTime                                ulong debug_timeGetTime(char * param_1, int p
    //         00492fd0     ADD        ESP,0x8
    //         00492fd3     MOV        dword ptr [ESI + 0x18c],EAX
    //                              scr_cred.cpp:477 (2)
    //         00492fd9     JMP        LAB_0049303b
    //                               LAB_00492fdb                                                 XREF[1]:     00492fbf(j)  
    //                              scr_cred.cpp:479 (15)
    //         00492fdb     PUSH       0x1df
    //         00492fe0     PUSH       s_C:\msdev\work\age1_x1\scr_cred.c               = "C:\\msdev\\work\\age1_x1\\scr_cred.cpp"
    //         00492fe5     CALL       debug_timeGetTime                                ulong debug_timeGetTime(char * param_1, int p
    //                              scr_cred.cpp:480 (48)
    //         00492fea     MOV        EDX,dword ptr [ESI + 0x18c]
    //         00492ff0     MOV        EDI,EAX
    //         00492ff2     SUB        EAX,EDX
    //         00492ff4     MOV        dword ptr [ESP + local_8+0x4],0x0
    //         00492ffc     MOV        dword ptr [ESP + local_8],EAX
    //         00493000     ADD        ESP,0x8
    //         00493003     FILD       qword ptr [ESP + local_8]
    //         00493007     FMUL       float ptr [DAT_00572968]                         = 6Fh    o
    //         0049300d     FILD       dword ptr [ESI + 0x190]
    //         00493013     FMULP
    //         00493015     CALL       __ftol                                           undefined __ftol()
    //                              scr_cred.cpp:481 (4)
    //         0049301a     TEST       EAX,EAX
    //         0049301c     JLE        LAB_0049303b
    //                              scr_cred.cpp:483 (6)
    //         0049301e     MOV        this,dword ptr [ESI + 0x188]
    //                              scr_cred.cpp:484 (17)
    //         00493024     MOV        EDX,dword ptr [ESI]
    //         00493026     ADD        this,EAX
    //         00493028     PUSH       0x1
    //         0049302a     MOV        dword ptr [ESI + 0x188],this
    //         00493030     MOV        this,ESI
    //         00493032     CALL       dword ptr [EDX + 0x20]
    //                              scr_cred.cpp:485 (6)
    //         00493035     MOV        dword ptr [ESI + 0x18c],EDI
    //                               LAB_0049303b                                                 XREF[2]:     00492fd9(j), 0049301c(j)  
    //                              scr_cred.cpp:489 (10)
    //         0049303b     MOV        EAX,dword ptr [ESI + 0x194]
    //         00493041     TEST       EAX,EAX
    //         00493043     JZ         LAB_0049305b
    //                              scr_cred.cpp:491 (7)
    //         00493045     MOV        this,dword ptr [ESI + 0x40]
    //         00493048     TEST       this,this
    //         0049304a     JZ         LAB_0049305b
    //                              scr_cred.cpp:492 (15)
    //         0049304c     MOV        EAX,dword ptr [this->_padding_]
    //         0049304e     PUSH       0x0
    //         00493050     PUSH       0x0=>DAT_fffffff8
    //         00493052     PUSH       offset DAT_fffffff4
    //         00493054     PUSH       ESI=>DAT_fffffff0
    //         00493055     CALL       dword ptr [EAX + 0xb4]
    //                               LAB_0049305b                                                 XREF[2]:     00493043(j), 0049304a(j)  
    //                              scr_cred.cpp:495 (7)
    //         0049305b     MOV        this,ESI
    //         0049305d     CALL       TPanel::handle_idle                              long handle_idle(TPanel * this)
    //                              scr_cred.cpp:496 (6)
    //         00493062     POP        EDI
    //         00493063     POP        ESI
    //         00493064     ADD        ESP,0x8
    //         00493067     RET
}

// Offset: 0x00493070
void TScrollTextPanel::draw() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void __thiscall TScrollTextPanel::draw(void)                                          *
    //                              *********************************************************************************************************
    //                              void __thiscall draw(TScrollTextPanel * this)
    //              void              <VOID>         <RETURN>
    //              TScrollTextPan    ECX:4 (auto)   this
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     004930ab(W)  
    //              void *            Stack[-0xc]:4  old_font
    //                               ?draw@TScrollTextPanel@@UAEXXZ                               XREF[1]:     005728a8(*)  
    //                               TScrollTextPanel::draw
    //                              scr_cred.cpp:500 (6)
    //         00493070     SUB        ESP,0x8
    //         00493073     PUSH       ESI
    //         00493074     MOV        ESI,this
    //                              scr_cred.cpp:508 (42)
    //         00493076     MOV        EAX,dword ptr [ESI + 0x20]
    //         00493079     MOV        dword ptr [ESI + 0x38],0x0
    //         00493080     TEST       EAX,EAX
    //         00493082     JZ         LAB_0049314f
    //         00493088     MOV        EAX,dword ptr [ESI + 0x70]
    //         0049308b     TEST       EAX,EAX
    //         0049308d     JZ         LAB_0049314f
    //         00493093     MOV        EAX,dword ptr [ESI + 0x6c]
    //         00493096     TEST       EAX,EAX
    //         00493098     JZ         LAB_0049314f
    //         0049309e     PUSH       EDI
    //         0049309f     PUSH       EBX
    //                              scr_cred.cpp:512 (5)
    //         004930a0     CALL       TTextPanel::draw_background                      void draw_background(TTextPanel * this)
    //                              scr_cred.cpp:514 (13)
    //         004930a5     MOV        EBX,dword ptr [ESI]
    //         004930a7     PUSH       0x0
    //         004930a9     MOV        this,ESI
    //         004930ab     MOV        dword ptr [ESP + local_4],EBX
    //         004930af     CALL       dword ptr [EBX + 0x28]
    //                              scr_cred.cpp:517 (15)
    //         004930b2     MOV        this,dword ptr [ESI + 0x20]
    //         004930b5     PUSH       s_scr_cred::draw                                 = "scr_cred::draw"
    //         004930ba     CALL       TDrawArea::GetDc                                 void * GetDc(TDrawArea * this, char * param_1)
    //         004930bf     MOV        EDI,EAX
    //                              scr_cred.cpp:518 (4)
    //         004930c1     TEST       EDI,EDI
    //         004930c3     JZ         LAB_00493141
    //                              scr_cred.cpp:520 (17)
    //         004930c5     MOV        EAX,dword ptr [ESI + 0x88]
    //         004930cb     PUSH       EBP
    //         004930cc     MOV        EBP,dword ptr [->GDI32.DLL::SelectClipRgn]       = 0048b2fc
    //         004930d2     PUSH       EAX=>DAT_fffffff8
    //         004930d3     PUSH       EDI=>DAT_fffffff4
    //         004930d4     CALL       EBP=>GDI32.DLL::SelectClipRgn
    //                              scr_cred.cpp:521 (14)
    //         004930d6     MOV        this,dword ptr [ESI + 0x104]
    //         004930dc     PUSH       this=>DAT_fffffff8
    //         004930dd     PUSH       EDI=>DAT_fffffff4
    //         004930de     CALL       dword ptr [->GDI32.DLL::SelectObject]            = 0048b192
    //                              scr_cred.cpp:522 (13)
    //         004930e4     PUSH       offset DAT_fffffff8
    //         004930e6     PUSH       EDI=>DAT_fffffff4
    //         004930e7     MOV        dword ptr [ESP + 0x18],EAX
    //         004930eb     CALL       dword ptr [->GDI32.DLL::SetBkMode]               = 0048b340
    //                              scr_cred.cpp:524 (11)
    //         004930f1     XOR        EBX,EBX
    //         004930f3     CMP        word ptr [ESI + 0xf8],BX
    //         004930fa     JLE        LAB_0049311e
    //                               LAB_004930fc                                                 XREF[1]:     0049311c(j)  
    //                              scr_cred.cpp:527 (34)
    //         004930fc     MOV        EDX,dword ptr [ESI + 0x124]
    //         00493102     MOV        EAX,dword ptr [ESI + 0x120]
    //         00493108     PUSH       EDX=>DAT_fffffff8
    //         00493109     PUSH       EAX=>DAT_fffffff4
    //         0049310a     PUSH       EBX=>DAT_fffffff0
    //         0049310b     PUSH       EBX
    //         0049310c     PUSH       EDI
    //         0049310d     MOV        this,ESI
    //         0049310f     CALL       TScrollTextPanel::draw_scrolled_line             void draw_scrolled_line(TScrollTextPanel * th
    //         00493114     INC        EBX
    //         00493115     CMP        BX,word ptr [ESI + 0xf8]
    //         0049311c     JL         LAB_004930fc
    //                               LAB_0049311e                                                 XREF[1]:     004930fa(j)  
    //                              scr_cred.cpp:530 (12)
    //         0049311e     MOV        this,dword ptr [ESP + 0x10]
    //         00493122     PUSH       this=>DAT_fffffff8
    //         00493123     PUSH       EDI=>DAT_fffffff4
    //         00493124     CALL       dword ptr [->GDI32.DLL::SelectObject]            = 0048b192
    //                              scr_cred.cpp:531 (5)
    //         0049312a     PUSH       0x0=>DAT_fffffff8
    //         0049312c     PUSH       EDI=>DAT_fffffff4
    //         0049312d     CALL       EBP=>GDI32.DLL::SelectClipRgn
    //                              scr_cred.cpp:532 (18)
    //         0049312f     MOV        this,dword ptr [ESI + 0x20]
    //         00493132     PUSH       s_scr_cred::draw                                 = "scr_cred::draw"
    //         00493137     CALL       TDrawArea::ReleaseDc                             void ReleaseDc(TDrawArea * this, char * param
    //         0049313c     MOV        EBX,dword ptr [ESP + 0x14]
    //         00493140     POP        EBP
    //                               LAB_00493141                                                 XREF[1]:     004930c3(j)  
    //                              scr_cred.cpp:536 (7)
    //         00493141     MOV        this,ESI
    //         00493143     CALL       TTextPanel::draw_border                          void draw_border(TTextPanel * this)
    //                              scr_cred.cpp:538 (7)
    //         00493148     MOV        this,ESI
    //         0049314a     CALL       dword ptr [EBX + 0x2c]
    //         0049314d     POP        EBX
    //         0049314e     POP        EDI
    //                               LAB_0049314f                                                 XREF[3]:     00493082(j), 0049308d(j), 
    //                                                                                                         00493098(j)  
    //                              scr_cred.cpp:540 (5)
    //         0049314f     POP        ESI
    //         00493150     ADD        ESP,0x8
    //         00493153     RET
}

// Offset: 0x00493160
void draw_scrolled_line(TScrollTextPanel* this_, void* param_2, short param_3, short param_4, ulong param_5, ulong param_6) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TScrollTextPanel::draw_scrolled_line(void *,short,short,unsigned long,unsi... *
    //                              *********************************************************************************************************
    //                              void __thiscall draw_scrolled_line(TScrollTextPanel * this, void * p
    //              void              <VOID>         <RETURN>
    //              TScrollTextPan    ECX:4 (auto)   this
    //              void *            Stack[0x4]:4   param_1                   XREF[1]:     004931d8(R)  
    //              short             Stack[0x8]:2   param_2                   XREF[2]:     004931cc(R), 00493216(W)  
    //              short             Stack[0xc]:2   param_3                   XREF[4]:     00493166(R), 004931f1(W), 004931ff(W), 00493209(R)  
    //              ulong             Stack[0x10]:4  param_4
    //              ulong             Stack[0x14]:4  param_5                   XREF[1]:     0049327e(R)  
    //              tagRECT           Stack[-0x14]   line_rect                 XREF[1,3]:   00493173(W), 004931d0(*), 004931eb(R), 00493210(R)  
    //              undefined4        Stack[-0x18]:4 local_18                  XREF[2]:     0049317f(W), 00493222(R)  
    //              undefined4        Stack[-0x1c]:4 local_1c                  XREF[2]:     0049317b(W), 004931c8(W)  
    //              short             Stack[-0x20]:2 text2_len                 XREF[1]:     00493196(W)  
    //              char *            Stack[-0x24]:4 temp_text2                XREF[2]:     00493177(W), 004931b4(W)  
    //              short             Stack[-0x28]:2 text_len
    //                               ?draw_scrolled_line@TScrollTextPanel@@QAEXPAXFFKK@Z          XREF[1]:     draw:0049310f(c)  
    //                               TScrollTextPanel::draw_scrolled_line
    //                              scr_cred.cpp:547 (6)
    //         00493160     SUB        ESP,0x24
    //         00493163     PUSH       EBX
    //         00493164     PUSH       EBP
    //         00493165     PUSH       ESI
    //                              scr_cred.cpp:554 (34)
    //         00493166     MOV        ESI,dword ptr [ESP + param_3]
    //         0049316a     PUSH       EDI
    //         0049316b     MOV        EBX,this
    //         0049316d     MOVSX      EDI,SI
    //         00493170     XOR        EAX,EAX
    //         00493172     PUSH       EDI
    //         00493173     MOV        dword ptr [ESP + line_rect.left],EBX
    //         00493177     MOV        dword ptr [ESP + temp_text2],EAX
    //         0049317b     MOV        dword ptr [ESP + local_1c],EAX
    //         0049317f     MOV        dword ptr [ESP + local_18],EDI
    //         00493183     CALL       TTextPanel::get_text                             char * get_text(TTextPanel * this, long param
    //                              scr_cred.cpp:555 (12)
    //         00493188     PUSH       EDI
    //         00493189     MOV        this,EBX
    //         0049318b     MOV        EBP,EAX
    //         0049318d     CALL       TTextPanel::get_text2                            char * get_text2(TTextPanel * this, long para
    //         00493192     MOV        EDX,EAX
    //                              scr_cred.cpp:557 (16)
    //         00493194     TEST       EBP,EBP
    //         00493196     MOV        dword ptr [ESP + text2_len],EDX
    //         0049319a     JNZ        LAB_004931a8
    //         0049319c     TEST       EDX,EDX
    //         0049319e     JZ         LAB_0049340a
    //                              scr_cred.cpp:560 (4)
    //         004931a4     TEST       EBP,EBP
    //         004931a6     JZ         LAB_004931b8
    //                               LAB_004931a8                                                 XREF[1]:     0049319a(j)  
    //                              scr_cred.cpp:562 (16)
    //         004931a8     MOV        EDI,EBP
    //         004931aa     OR         this,0xffffffff
    //         004931ad     XOR        EAX,EAX
    //         004931af     SCASB.RE   ES:EDI
    //         004931b1     NOT        this
    //         004931b3     DEC        this
    //         004931b4     MOV        dword ptr [ESP + temp_text2],this
    //                               LAB_004931b8                                                 XREF[1]:     004931a6(j)  
    //                              scr_cred.cpp:564 (4)
    //         004931b8     TEST       EDX,EDX
    //         004931ba     JZ         LAB_004931cc
    //                              scr_cred.cpp:566 (16)
    //         004931bc     MOV        EDI,EDX
    //         004931be     OR         this,0xffffffff
    //         004931c1     XOR        EAX,EAX
    //         004931c3     SCASB.RE   ES:EDI
    //         004931c5     NOT        this
    //         004931c7     DEC        this
    //         004931c8     MOV        dword ptr [ESP + local_1c],this
    //                               LAB_004931cc                                                 XREF[1]:     004931ba(j)  
    //                              scr_cred.cpp:568 (25)
    //         004931cc     MOV        this,dword ptr [ESP + param_2]
    //         004931d0     LEA        EAX=>line_rect.top,[ESP + 0x24]
    //         004931d4     PUSH       0x0
    //         004931d6     PUSH       EAX
    //         004931d7     PUSH       ESI
    //         004931d8     MOV        ESI,dword ptr [ESP + param_1]
    //         004931dc     PUSH       this
    //         004931dd     PUSH       ESI
    //         004931de     MOV        this,EBX
    //         004931e0     CALL       TTextPanel::calc_line_pos                        void calc_line_pos(TTextPanel * this, void * 
    //                              scr_cred.cpp:571 (23)
    //         004931e5     MOV        EAX,dword ptr [EBX + 0x114]
    //         004931eb     MOV        this,dword ptr [ESP + line_rect.top]
    //         004931ef     TEST       EAX,EAX
    //         004931f1     MOV        dword ptr [ESP + param_3],this
    //         004931f5     JZ         LAB_00493203
    //         004931f7     CMP        EAX,0x6
    //         004931fa     JZ         LAB_00493203
    //                              scr_cred.cpp:572 (7)
    //         004931fc     ADD        this,0x5
    //         004931ff     MOV        dword ptr [ESP + param_3],this
    //                               LAB_00493203                                                 XREF[2]:     004931f5(j), 004931fa(j)  
    //                              scr_cred.cpp:573 (10)
    //         00493203     MOV        EAX,dword ptr [EBX + 0x160]
    //         00493209     MOV        this,dword ptr [ESP + param_3]
    //                              scr_cred.cpp:578 (21)
    //         0049320d     MOV        EDI,dword ptr [EBX + 0x18]
    //         00493210     MOV        EDX,dword ptr [ESP + line_rect.right]
    //         00493214     ADD        EAX,this
    //         00493216     MOV        dword ptr [ESP + param_2],EAX
    //         0049321a     MOV        EAX,dword ptr [EBX + 0x188]
    //         00493220     SUB        EDI,EAX
    //                              scr_cred.cpp:580 (33)
    //         00493222     MOV        EAX,dword ptr [ESP + local_18]
    //         00493226     ADD        EDI,EDX
    //         00493228     MOVSX      EDX,word ptr [EBX + 0xf8]
    //         0049322f     DEC        EDX
    //         00493230     CMP        EAX,EDX
    //         00493232     JNZ        LAB_0049324d
    //         00493234     MOV        EAX,dword ptr [EBX + 0x10c]
    //         0049323a     MOV        this,dword ptr [EBX + 0x10]
    //         0049323d     ADD        EAX,EDI
    //         0049323f     CMP        EAX,this
    //         00493241     JGE        LAB_0049324d
    //                              scr_cred.cpp:581 (10)
    //         00493243     MOV        dword ptr [EBX + 0x194],0x1
    //                               LAB_0049324d                                                 XREF[2]:     00493232(j), 00493241(j)  
    //                              scr_cred.cpp:587 (10)
    //         0049324d     MOV        EAX,dword ptr [EBX + 0x17c]
    //         00493253     TEST       EAX,EAX
    //         00493255     JZ         LAB_0049325f
    //                              scr_cred.cpp:588 (8)
    //         00493257     PUSH       EAX
    //         00493258     PUSH       ESI
    //         00493259     CALL       dword ptr [->GDI32.DLL::SelectClipRgn]           = 0048b2fc
    //                               LAB_0049325f                                                 XREF[1]:     00493255(j)  
    //                              scr_cred.cpp:590 (31)
    //         0049325f     MOV        EAX,dword ptr [EBX + 0x11c]
    //         00493265     MOV        EBX,dword ptr [->GDI32.DLL::TextOutA]            = 0048b30c
    //         0049326b     SUB        EAX,0x0
    //         0049326e     JZ         LAB_004932f7
    //         00493274     DEC        EAX
    //         00493275     JZ         LAB_004932c1
    //         00493277     DEC        EAX
    //         00493278     JNZ        LAB_00493317
    //                              scr_cred.cpp:606 (12)
    //         0049327e     MOV        this,dword ptr [ESP + param_5]
    //         00493282     PUSH       this
    //         00493283     PUSH       ESI
    //         00493284     CALL       dword ptr [->GDI32.DLL::SetTextColor]            = 0048b318
    //                              scr_cred.cpp:607 (24)
    //         0049328a     TEST       EBP,EBP
    //         0049328c     JZ         LAB_004932a2
    //         0049328e     MOVSX      EDX,word ptr [ESP + 0x10]
    //         00493293     MOV        this,dword ptr [ESP + 0x40]
    //         00493297     PUSH       EDX
    //         00493298     LEA        EAX,[EDI + 0x1]
    //         0049329b     PUSH       EBP
    //         0049329c     DEC        this
    //         0049329d     PUSH       EAX
    //         0049329e     PUSH       this
    //         0049329f     PUSH       ESI
    //         004932a0     CALL       EBX=>GDI32.DLL::TextOutA
    //                               LAB_004932a2                                                 XREF[1]:     0049328c(j)  
    //                              scr_cred.cpp:609 (12)
    //         004932a2     MOV        EDX,dword ptr [ESP + 0x44]
    //         004932a6     PUSH       EDX
    //         004932a7     PUSH       ESI
    //         004932a8     CALL       dword ptr [->GDI32.DLL::SetTextColor]            = 0048b318
    //                              scr_cred.cpp:610 (17)
    //         004932ae     TEST       EBP,EBP
    //         004932b0     JZ         LAB_00493317
    //         004932b2     MOVSX      EAX,word ptr [ESP + 0x10]
    //         004932b7     MOV        this,dword ptr [ESP + 0x40]
    //         004932bb     PUSH       EAX
    //         004932bc     PUSH       EBP
    //         004932bd     PUSH       EDI
    //         004932be     PUSH       this
    //                              scr_cred.cpp:611 (2)
    //         004932bf     JMP        LAB_00493314
    //                               LAB_004932c1                                                 XREF[1]:     00493275(j)  
    //                              scr_cred.cpp:598 (12)
    //         004932c1     MOV        EDX,dword ptr [ESP + 0x44]
    //         004932c5     PUSH       EDX
    //         004932c6     PUSH       ESI
    //         004932c7     CALL       dword ptr [->GDI32.DLL::SetTextColor]            = 0048b318
    //                              scr_cred.cpp:599 (24)
    //         004932cd     TEST       EBP,EBP
    //         004932cf     JZ         LAB_004932e5
    //         004932d1     MOVSX      EAX,word ptr [ESP + 0x10]
    //         004932d6     MOV        EDX,dword ptr [ESP + 0x40]
    //         004932da     PUSH       EAX
    //         004932db     LEA        this,[EDI + 0x1]
    //         004932de     PUSH       EBP
    //         004932df     DEC        EDX
    //         004932e0     PUSH       this
    //         004932e1     PUSH       EDX
    //         004932e2     PUSH       ESI
    //         004932e3     CALL       EBX=>GDI32.DLL::TextOutA
    //                               LAB_004932e5                                                 XREF[1]:     004932cf(j)  
    //                              scr_cred.cpp:601 (12)
    //         004932e5     MOV        EAX,dword ptr [ESP + 0x48]
    //         004932e9     PUSH       EAX
    //         004932ea     PUSH       ESI
    //         004932eb     CALL       dword ptr [->GDI32.DLL::SetTextColor]            = 0048b318
    //                              scr_cred.cpp:602 (4)
    //         004932f1     TEST       EBP,EBP
    //         004932f3     JZ         LAB_00493317
    //                              scr_cred.cpp:603 (2)
    //         004932f5     JMP        LAB_00493307
    //                               LAB_004932f7                                                 XREF[1]:     0049326e(j)  
    //                              scr_cred.cpp:593 (12)
    //         004932f7     MOV        EAX,dword ptr [ESP + 0x44]
    //         004932fb     PUSH       EAX
    //         004932fc     PUSH       ESI
    //         004932fd     CALL       dword ptr [->GDI32.DLL::SetTextColor]            = 0048b318
    //                              scr_cred.cpp:594 (20)
    //         00493303     TEST       EBP,EBP
    //         00493305     JZ         LAB_00493317
    //                               LAB_00493307                                                 XREF[1]:     004932f5(j)  
    //         00493307     MOVSX      this,word ptr [ESP + 0x10]
    //         0049330c     MOV        EDX,dword ptr [ESP + 0x40]
    //         00493310     PUSH       this
    //         00493311     PUSH       EBP
    //         00493312     PUSH       EDI
    //         00493313     PUSH       EDX
    //                               LAB_00493314                                                 XREF[1]:     004932bf(j)  
    //         00493314     PUSH       ESI
    //         00493315     CALL       EBX=>GDI32.DLL::TextOutA
    //                               LAB_00493317                                                 XREF[4]:     00493278(j), 004932b0(j), 
    //                                                                                                         004932f3(j), 00493305(j)  
    //                              scr_cred.cpp:615 (12)
    //         00493317     MOV        EAX,dword ptr [ESP + 0x14]
    //         0049331b     TEST       EAX,EAX
    //         0049331d     JZ         LAB_0049340a
    //                              scr_cred.cpp:617 (14)
    //         00493323     MOV        EBP,dword ptr [ESP + 0x20]
    //         00493327     MOV        EAX,dword ptr [EBP + 0x17c]
    //         0049332d     TEST       EAX,EAX
    //         0049332f     JZ         LAB_0049333f
    //                              scr_cred.cpp:618 (14)
    //         00493331     MOV        EAX,dword ptr [EBP + 0x88]
    //         00493337     PUSH       EAX
    //         00493338     PUSH       ESI
    //         00493339     CALL       dword ptr [->GDI32.DLL::SelectClipRgn]           = 0048b2fc
    //                               LAB_0049333f                                                 XREF[1]:     0049332f(j)  
    //                              scr_cred.cpp:620 (25)
    //         0049333f     MOV        EAX,dword ptr [EBP + 0x11c]
    //         00493345     SUB        EAX,0x0
    //         00493348     JZ         LAB_004933ea
    //         0049334e     DEC        EAX
    //         0049334f     JZ         LAB_004933a1
    //         00493351     DEC        EAX
    //         00493352     JNZ        LAB_0049340a
    //                              scr_cred.cpp:636 (12)
    //         00493358     MOV        this,dword ptr [ESP + 0x48]
    //         0049335c     PUSH       this
    //         0049335d     PUSH       ESI
    //         0049335e     CALL       dword ptr [->GDI32.DLL::SetTextColor]            = 0048b318
    //                              scr_cred.cpp:637 (24)
    //         00493364     MOVSX      EBP,word ptr [ESP + 0x18]
    //         00493369     MOV        EDX,dword ptr [ESP + 0x14]
    //         0049336d     MOV        this,dword ptr [ESP + 0x3c]
    //         00493371     PUSH       EBP
    //         00493372     LEA        EAX,[EDI + 0x1]
    //         00493375     PUSH       EDX
    //         00493376     DEC        this
    //         00493377     PUSH       EAX
    //         00493378     PUSH       this
    //         00493379     PUSH       ESI
    //         0049337a     CALL       EBX=>GDI32.DLL::TextOutA
    //                              scr_cred.cpp:639 (12)
    //         0049337c     MOV        EDX,dword ptr [ESP + 0x44]
    //         00493380     PUSH       EDX
    //         00493381     PUSH       ESI
    //         00493382     CALL       dword ptr [->GDI32.DLL::SetTextColor]            = 0048b318
    //                              scr_cred.cpp:640 (15)
    //         00493388     MOV        EAX,dword ptr [ESP + 0x14]
    //         0049338c     MOV        this,dword ptr [ESP + 0x3c]
    //         00493390     PUSH       EBP
    //         00493391     PUSH       EAX
    //         00493392     PUSH       EDI
    //         00493393     PUSH       this
    //         00493394     PUSH       ESI
    //         00493395     CALL       EBX=>GDI32.DLL::TextOutA
    //                              scr_cred.cpp:644 (10)
    //         00493397     POP        EDI
    //         00493398     POP        ESI
    //         00493399     POP        EBP
    //         0049339a     POP        EBX
    //         0049339b     ADD        ESP,0x24
    //         0049339e     RET        0x14
    //                               LAB_004933a1                                                 XREF[1]:     0049334f(j)  
    //                              scr_cred.cpp:628 (12)
    //         004933a1     MOV        EDX,dword ptr [ESP + 0x44]
    //         004933a5     PUSH       EDX
    //         004933a6     PUSH       ESI
    //         004933a7     CALL       dword ptr [->GDI32.DLL::SetTextColor]            = 0048b318
    //                              scr_cred.cpp:629 (24)
    //         004933ad     MOVSX      EBP,word ptr [ESP + 0x18]
    //         004933b2     MOV        EAX,dword ptr [ESP + 0x14]
    //         004933b6     MOV        EDX,dword ptr [ESP + 0x3c]
    //         004933ba     PUSH       EBP
    //         004933bb     LEA        this,[EDI + 0x1]
    //         004933be     PUSH       EAX
    //         004933bf     DEC        EDX
    //         004933c0     PUSH       this
    //         004933c1     PUSH       EDX
    //         004933c2     PUSH       ESI
    //         004933c3     CALL       EBX=>GDI32.DLL::TextOutA
    //                              scr_cred.cpp:631 (12)
    //         004933c5     MOV        EAX,dword ptr [ESP + 0x48]
    //         004933c9     PUSH       EAX
    //         004933ca     PUSH       ESI
    //         004933cb     CALL       dword ptr [->GDI32.DLL::SetTextColor]            = 0048b318
    //                              scr_cred.cpp:632 (15)
    //         004933d1     MOV        this,dword ptr [ESP + 0x14]
    //         004933d5     MOV        EDX,dword ptr [ESP + 0x3c]
    //         004933d9     PUSH       EBP
    //         004933da     PUSH       this
    //         004933db     PUSH       EDI
    //         004933dc     PUSH       EDX
    //         004933dd     PUSH       ESI
    //         004933de     CALL       EBX=>GDI32.DLL::TextOutA
    //                              scr_cred.cpp:644 (10)
    //         004933e0     POP        EDI
    //         004933e1     POP        ESI
    //         004933e2     POP        EBP
    //         004933e3     POP        EBX
    //         004933e4     ADD        ESP,0x24
    //         004933e7     RET        0x14
    //                               LAB_004933ea                                                 XREF[1]:     00493348(j)  
    //                              scr_cred.cpp:623 (12)
    //         004933ea     MOV        EAX,dword ptr [ESP + 0x44]
    //         004933ee     PUSH       EAX
    //         004933ef     PUSH       ESI
    //         004933f0     CALL       dword ptr [->GDI32.DLL::SetTextColor]            = 0048b318
    //                              scr_cred.cpp:624 (20)
    //         004933f6     MOVSX      this,word ptr [ESP + 0x18]
    //         004933fb     MOV        EDX,dword ptr [ESP + 0x14]
    //         004933ff     MOV        EAX,dword ptr [ESP + 0x3c]
    //         00493403     PUSH       this
    //         00493404     PUSH       EDX
    //         00493405     PUSH       EDI
    //         00493406     PUSH       EAX
    //         00493407     PUSH       ESI
    //         00493408     CALL       EBX=>GDI32.DLL::TextOutA
    //                               LAB_0049340a                                                 XREF[3]:     0049319e(j), 0049331d(j), 
    //                                                                                                         00493352(j)  
    //                              scr_cred.cpp:644 (10)
    //         0049340a     POP        EDI
    //         0049340b     POP        ESI
    //         0049340c     POP        EBP
    //         0049340d     POP        EBX
    //         0049340e     ADD        ESP,0x24
    //         00493411     RET        0x14
}

// Offset: 0x00493420
void RGE_fade_palette_start(TDrawArea* param_1, tagPALETTEENTRY param_2, float param_3, uchar param_4, tagPALETTEENTRY* param_5, int param_6, int param_7) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * void __cdecl RGE_fade_palette_start(class TDrawArea *,struct tagPALETTEENTRY,float,unsigned char,s... *
    //                              *********************************************************************************************************
    //                              void __cdecl RGE_fade_palette_start(TDrawArea * param_1, tagPALETTEE
    //              void              <VOID>         <RETURN>
    //              TDrawArea *       Stack[0x4]:4   param_1                   XREF[1]:     00493428(R)  
    //              tagPALETTEENTRY   Stack[0x8]:4   param_2                   XREF[1]:     00493420(R)  
    //              float             Stack[0xc]:4   param_3                   XREF[1]:     00493424(R)  
    //              uchar             Stack[0x10]:1  param_4                   XREF[1]:     00493431(R)  
    //              tagPALETTEENTR    Stack[0x14]:4  param_5                   XREF[1]:     0049349b(R)  
    //              int               Stack[0x18]:4  param_6                   XREF[1]:     0049343b(R)  
    //              int               Stack[0x1c]:4  param_7                   XREF[1]:     00493444(R)  
    //                               ?RGE_fade_palette_start@@YAXPAVTDrawArea@@UtagPALETTEENTRY@  XREF[2]:     handle_idle:00492b29(c), 
    //                               RGE_fade_palette_start                                                    handle_idle:00492c57(c)  
    //                              scr_cred.cpp:660 (4)
    //         00493420     MOV        EAX,dword ptr [ESP + param_2.peRed]
    //                              scr_cred.cpp:665 (13)
    //         00493424     MOV        EDX,dword ptr [ESP + param_3]
    //         00493428     MOV        ECX,dword ptr [ESP + param_1]
    //         0049342c     MOV        [DAT_0086b2a8],EAX
    //                              scr_cred.cpp:666 (10)
    //         00493431     MOV        AL,byte ptr [ESP + param_4]
    //         00493435     MOV        dword ptr [null_0086b290],EDX                    = align(4)
    //                              scr_cred.cpp:667 (9)
    //         0049343b     MOV        EDX,dword ptr [ESP + param_6]
    //         0049343f     MOV        [DAT_0086b2a4],AL
    //                              scr_cred.cpp:668 (18)
    //         00493444     MOV        EAX,dword ptr [ESP + param_7]
    //         00493448     PUSH       EBX
    //         00493449     PUSH       EBP
    //         0049344a     MOV        dword ptr [DAT_0086b298],EDX
    //         00493450     PUSH       ESI
    //         00493451     MOV        [DAT_0086b29c],EAX
    //                              scr_cred.cpp:672 (17)
    //         00493456     XOR        EDX,EDX
    //         00493458     PUSH       EDI
    //         00493459     MOV        dword ptr [DAT_0086bab0],ECX
    //         0049345f     XOR        EAX,EAX
    //                               LAB_00493461                                                 XREF[1]:     00493499(j)  
    //         00493461     MOV        byte ptr [EAX + DAT_0086b2b0],DL
    //                              scr_cred.cpp:676 (12)
    //         00493467     MOV        byte ptr [EAX + DAT_0086b6b0],DL
    //         0049346d     MOV        byte ptr [EAX + DAT_0086b2b2],DL
    //                              scr_cred.cpp:677 (12)
    //         00493473     MOV        byte ptr [EAX + DAT_0086b6b2],DL
    //         00493479     MOV        byte ptr [EAX + DAT_0086b2b1],DL
    //                              scr_cred.cpp:678 (12)
    //         0049347f     MOV        byte ptr [EAX + DAT_0086b6b1],DL
    //         00493485     MOV        byte ptr [EAX + DAT_0086b2b3],DL
    //                              scr_cred.cpp:679 (16)
    //         0049348b     MOV        byte ptr [EAX + DAT_0086b6b3],DL
    //         00493491     ADD        EAX,0x4
    //         00493494     CMP        EAX,0x400
    //         00493499     JL         LAB_00493461
    //                              scr_cred.cpp:682 (8)
    //         0049349b     MOV        EBX,dword ptr [ESP + param_5]
    //         0049349f     CMP        EBX,EDX
    //         004934a1     JNZ        LAB_004934af
    //                              scr_cred.cpp:683 (10)
    //         004934a3     PUSH       DAT_0086b2b0
    //         004934a8     CALL       TDrawArea::GetPalette                            void GetPalette(TDrawArea * this, tagPALETTEE
    //                              scr_cred.cpp:684 (2)
    //         004934ad     JMP        LAB_004934f1
    //                               LAB_004934af                                                 XREF[1]:     004934a1(j)  
    //                              scr_cred.cpp:701 (66)
    //         004934af     MOV        ECX,DAT_0086b2b0
    //         004934b4     MOV        ESI,DAT_0086b2b1
    //         004934b9     MOV        EDI,ECX
    //         004934bb     MOV        EBP,DAT_0086b2b2
    //         004934c0     SUB        ESI,EBX
    //         004934c2     SUB        EDI,EBX
    //         004934c4     LEA        EAX,[EBX + 0x1]
    //         004934c7     SUB        EBP,EBX
    //                               LAB_004934c9                                                 XREF[1]:     004934ef(j)  
    //         004934c9     MOV        DL,byte ptr [EAX + -0x1]
    //         004934cc     ADD        EAX,0x4
    //         004934cf     MOV        byte ptr [ECX]=>DAT_0086b2b0,DL
    //         004934d1     MOV        DL,byte ptr [EAX + -0x3]
    //         004934d4     MOV        byte ptr [ESI + EAX*0x1 + -0x4],DL
    //         004934d8     MOV        DL,byte ptr [EAX + -0x4]
    //         004934db     MOV        byte ptr [EDI + EAX*0x1 + -0x4],DL
    //         004934df     MOV        DL,byte ptr [EAX + -0x2]
    //         004934e2     MOV        byte ptr [EBP + EAX*0x1 + -0x4],DL
    //         004934e6     ADD        ECX,0x4
    //         004934e9     CMP        ECX,DAT_0086b6b0
    //         004934ef     JL         LAB_004934c9
    //                               LAB_004934f1                                                 XREF[1]:     004934ad(j)  
    //                              scr_cred.cpp:693 (15)
    //         004934f1     PUSH       0x2b5
    //         004934f6     PUSH       s_C:\msdev\work\age1_x1\scr_cred.c               = "C:\\msdev\\work\\age1_x1\\scr_cred.cpp"
    //         004934fb     CALL       debug_timeGetTime                                ulong debug_timeGetTime(char * param_1, int p
    //                              scr_cred.cpp:695 (17)
    //         00493500     FLD        float ptr [null_0086b290]                        = align(4)
    //         00493506     FMUL       float ptr [null_0086b290]                        = align(4)
    //         0049350c     MOV        [DAT_0086b294],EAX
    //                              scr_cred.cpp:697 (20)
    //         00493511     MOV        AL,[DAT_0086b2a4]
    //         00493516     ADD        ESP,0x8
    //         00493519     DEC        AL
    //         0049351b     NEG        AL
    //         0049351d     FSTP       float ptr [DAT_0086b2ac]                         = align(4)
    //         00493523     SBB        EAX,EAX
    //                              scr_cred.cpp:701 (13)
    //         00493525     POP        EDI
    //         00493526     AND        EAX,0x64
    //         00493529     POP        ESI
    //         0049352a     POP        EBP
    //         0049352b     MOV        [DAT_0086b2a0],EAX                               = align(4)
    //         00493530     POP        EBX
    //         00493531     RET
}

// Offset: 0x00493540
int RGE_fade_palette_step() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * int __cdecl RGE_fade_palette_step(void)                                                               *
    //                              *********************************************************************************************************
    //                              int __cdecl RGE_fade_palette_step(void)
    //              int               EAX:4          <RETURN>
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[3]:     00493548(W), 00493682(W), 004936be(R)  
    //              uchar             Stack[-0x8]:1  done                      XREF[14]:    0049356f(*), 00493573(*), 0049357d(*), 00493594(*), 
    //                                                                                     004935a5(*), 004935b6(*), 004935ba(*), 00493608(*), 
    //                                                                                     0049360c(*), 0049361c(*), 00493633(*), 00493644(*), 
    //                                                                                     00493655(*), 00493659(*)  
    //              float             Stack[-0xc]:4  delta_time
    //                               ?RGE_fade_palette_step@@YAHXZ                                XREF[2]:     handle_idle:00492b3b(c), 
    //                               RGE_fade_palette_step                                                     handle_idle:00492c66(c)  
    //                              scr_cred.cpp:705 (3)
    //         00493540     SUB        ESP,0x8
    //                              scr_cred.cpp:710 (18)
    //         00493543     MOV        AL,[DAT_0086b2a4]
    //         00493548     MOV        byte ptr [ESP + local_4],0x0
    //         0049354d     CMP        AL,0x1
    //         0049354f     JNZ        LAB_004935ee
    //                              scr_cred.cpp:712 (15)
    //         00493555     PUSH       0x2c8
    //         0049355a     PUSH       s_C:\msdev\work\age1_x1\scr_cred.c               = "C:\\msdev\\work\\age1_x1\\scr_cred.cpp"
    //         0049355f     CALL       debug_timeGetTime                                ulong debug_timeGetTime(char * param_1, int p
    //                              scr_cred.cpp:713 (29)
    //         00493564     MOV        ECX,dword ptr [DAT_0086b294]
    //         0049356a     ADD        ESP,0x8
    //         0049356d     SUB        EAX,ECX
    //         0049356f     MOV        dword ptr [ESP]=>done,EAX
    //         00493573     FILD       dword ptr [ESP]=>done
    //         00493577     FMUL       float ptr [DAT_00572968]                         = 6Fh    o
    //         0049357d     FSTP       float ptr [ESP]=>done
    //                              scr_cred.cpp:714 (53)
    //         00493581     FLD        float ptr [null_0086b290]                        = align(4)
    //         00493587     FCOMP      double ptr [DAT_00572970]
    //         0049358d     FNSTSW     AX
    //         0049358f     TEST       AH,0x41
    //         00493592     JNZ        LAB_004935d1
    //         00493594     FLD        float ptr [ESP]=>done
    //         00493598     FCOMP      float ptr [null_0086b290]                        = align(4)
    //         0049359e     FNSTSW     AX
    //         004935a0     TEST       AH,0x41
    //         004935a3     JZ         LAB_004935d1
    //         004935a5     FLD        float ptr [ESP]=>done
    //         004935a9     FCOMP      float ptr [DAT_00572978]
    //         004935af     FNSTSW     AX
    //         004935b1     TEST       AH,0x1
    //         004935b4     JNZ        LAB_004935d1
    //                              scr_cred.cpp:719 (27)
    //         004935b6     FLD        float ptr [ESP]=>done
    //         004935ba     FMUL       float ptr [ESP]=>done
    //         004935be     FDIV       float ptr [DAT_0086b2ac]                         = align(4)
    //         004935c4     FMUL       float ptr [DAT_0057297c]
    //         004935ca     CALL       __ftol                                           undefined __ftol()
    //         004935cf     JMP        LAB_004935d6
    //                               LAB_004935d1                                                 XREF[3]:     00493592(j), 004935a3(j), 
    //                                                                                                         004935b4(j)  
    //                              scr_cred.cpp:715 (5)
    //         004935d1     MOV        EAX,0x64
    //                               LAB_004935d6                                                 XREF[1]:     004935cf(j)  
    //                              scr_cred.cpp:722 (14)
    //         004935d6     CMP        EAX,0x64
    //         004935d9     MOV        [DAT_0086b2a0],EAX                               = align(4)
    //         004935de     JL         LAB_00493687
    //                              scr_cred.cpp:724 (5)
    //         004935e4     MOV        EAX,0x64
    //                              scr_cred.cpp:730 (5)
    //         004935e9     JMP        LAB_0049367d
    //                               LAB_004935ee                                                 XREF[1]:     0049354f(j)  
    //                              scr_cred.cpp:732 (15)
    //         004935ee     PUSH       0x2dc
    //         004935f3     PUSH       s_C:\msdev\work\age1_x1\scr_cred.c               = "C:\\msdev\\work\\age1_x1\\scr_cred.cpp"
    //         004935f8     CALL       debug_timeGetTime                                ulong debug_timeGetTime(char * param_1, int p
    //                              scr_cred.cpp:734 (35)
    //         004935fd     MOV        ECX,dword ptr [DAT_0086b294]
    //         00493603     ADD        ESP,0x8
    //         00493606     SUB        EAX,ECX
    //         00493608     MOV        dword ptr [ESP]=>done,EAX
    //         0049360c     FILD       dword ptr [ESP]=>done
    //         00493610     FMUL       float ptr [DAT_00572968]                         = 6Fh    o
    //         00493616     FSUBR      float ptr [null_0086b290]                        = align(4)
    //         0049361c     FSTP       float ptr [ESP]=>done
    //                              scr_cred.cpp:735 (53)
    //         00493620     FLD        float ptr [null_0086b290]                        = align(4)
    //         00493626     FCOMP      double ptr [DAT_00572970]
    //         0049362c     FNSTSW     AX
    //         0049362e     TEST       AH,0x41
    //         00493631     JNZ        LAB_00493670
    //         00493633     FLD        float ptr [ESP]=>done
    //         00493637     FCOMP      float ptr [null_0086b290]                        = align(4)
    //         0049363d     FNSTSW     AX
    //         0049363f     TEST       AH,0x41
    //         00493642     JZ         LAB_00493670
    //         00493644     FLD        float ptr [ESP]=>done
    //         00493648     FCOMP      float ptr [DAT_00572978]
    //         0049364e     FNSTSW     AX
    //         00493650     TEST       AH,0x1
    //         00493653     JNZ        LAB_00493670
    //                              scr_cred.cpp:740 (27)
    //         00493655     FLD        float ptr [ESP]=>done
    //         00493659     FMUL       float ptr [ESP]=>done
    //         0049365d     FDIV       float ptr [DAT_0086b2ac]                         = align(4)
    //         00493663     FMUL       float ptr [DAT_0057297c]
    //         00493669     CALL       __ftol                                           undefined __ftol()
    //         0049366e     JMP        LAB_00493672
    //                               LAB_00493670                                                 XREF[3]:     00493631(j), 00493642(j), 
    //                                                                                                         00493653(j)  
    //                              scr_cred.cpp:736 (2)
    //         00493670     XOR        EAX,EAX
    //                               LAB_00493672                                                 XREF[1]:     0049366e(j)  
    //                              scr_cred.cpp:743 (9)
    //         00493672     TEST       EAX,EAX
    //         00493674     MOV        [DAT_0086b2a0],EAX                               = align(4)
    //         00493679     JG         LAB_00493687
    //                              scr_cred.cpp:745 (7)
    //         0049367b     XOR        EAX,EAX
    //                               LAB_0049367d                                                 XREF[1]:     004935e9(j)  
    //         0049367d     MOV        [DAT_0086b2a0],EAX                               = align(4)
    //                              scr_cred.cpp:746 (5)
    //         00493682     MOV        byte ptr [ESP + local_4],0x1
    //                               LAB_00493687                                                 XREF[2]:     004935de(j), 00493679(j)  
    //                              scr_cred.cpp:748 (36)
    //         00493687     MOV        ECX,dword ptr [DAT_0086b29c]
    //         0049368d     MOV        EDX,dword ptr [DAT_0086b298]
    //         00493693     PUSH       ECX
    //         00493694     PUSH       EDX
    //         00493695     PUSH       EAX
    //         00493696     MOV        EAX,[DAT_0086b2a8]
    //         0049369b     PUSH       EAX
    //         0049369c     PUSH       DAT_0086b6b0
    //         004936a1     PUSH       DAT_0086b2b0
    //         004936a6     CALL       RGE_translate_palette                            void RGE_translate_palette(tagPALETTEENTRY * 
    //                              scr_cred.cpp:749 (19)
    //         004936ab     MOV        ECX,dword ptr [DAT_0086bab0]
    //         004936b1     ADD        ESP,0x18
    //         004936b4     PUSH       DAT_0086b6b0
    //         004936b9     CALL       TDrawArea::SetPalette                            void SetPalette(TDrawArea * this, tagPALETTEE
    //                              scr_cred.cpp:752 (9)
    //         004936be     MOV        EAX,dword ptr [ESP + local_4]
    //         004936c2     AND        EAX,0xff
    //                              scr_cred.cpp:753 (4)
    //         004936c7     ADD        ESP,0x8
    //         004936ca     RET
}

