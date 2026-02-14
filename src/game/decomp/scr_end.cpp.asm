// Auto-generated scaffold unit: scr_end.cpp.asm
// SourceMap: C:/msdev/work/age1_x1/scr_end.cpp
#include "../include/common.h"

// Offset: 0x004936D0
undefined TribeEndScreen(TribeEndScreen* this_, char* param_2, char** param_3, int param_4) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall TribeEndScreen::TribeEndScreen(char *,char * *,int)                                *
    //                              *********************************************************************************************************
    //                              undefined __thiscall TribeEndScreen(TribeEndScreen * this, char * pa
    //              undefined         <UNASSIGNED>   <RETURN>
    //              TribeEndScreen    ECX:4 (auto)   this
    //              char *            Stack[0x4]:4   param_1
    //              char * *          Stack[0x8]:4   param_2
    //              int               Stack[0xc]:4   param_3
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[3]:     0049370d(W), 00493791(W), 004937a5(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     00493bc3(R)  
    //              char[10]          Stack[-0x1c]   backgroundName            XREF[1,3]:   004936f3(W), 00493741(*), 00493751(*), 004937c3(*)  
    //              undefined4        Stack[-0x20]:4 local_20                  XREF[1]:     0049378b(W)  
    //                               ??0TribeEndScreen@@QAE@PADPAPADH@Z
    //                               TribeEndScreen::TribeEndScreen
    //                              scr_end.cpp:34 (51)
    //         004936d0     PUSH       -0x1
    //         004936d2     PUSH       FUN_0055eb74
    //         004936d7     MOV        EAX,FS:[0x0]
    //         004936dd     PUSH       EAX
    //         004936de     MOV        dword ptr FS:[0x0],ESP
    //         004936e5     SUB        ESP,0x14
    //         004936e8     PUSH       EBX
    //         004936e9     PUSH       EBP
    //         004936ea     PUSH       ESI
    //         004936eb     PUSH       EDI
    //         004936ec     MOV        EBP,this
    //         004936ee     PUSH       s_End_Screen                                     = "End Screen"
    //         004936f3     MOV        dword ptr [ESP + backgroundName[0]],EBP
    //         004936f7     CALL       TScreenPanel::TScreenPanel                       undefined TScreenPanel(TScreenPanel * this, c
    //         004936fc     MOV        dword ptr [EBP],TribeEndScreen::`vftable'        = 00493be0
    //                              scr_end.cpp:41 (38)
    //         00493703     MOV        EAX,[rge_base_game]                              = 00000000
    //         00493708     MOV        EBX,0x1
    //         0049370d     MOV        dword ptr [ESP + local_4],0x0
    //         00493715     MOV        this,dword ptr [EAX + 0x4c]
    //         00493718     PUSH       EBX
    //         00493719     PUSH       0x0
    //         0049371b     PUSH       0x0
    //         0049371d     PUSH       this
    //         0049371e     MOV        this,EBP
    //         00493720     CALL       TScreenPanel::setup                              long setup(TScreenPanel * this, TDrawArea * p
    //         00493725     TEST       EAX,EAX
    //         00493727     JNZ        LAB_00493734
    //                              scr_end.cpp:42 (6)
    //         00493729     MOV        dword ptr [EBP + 0xd8],EBX
    //                              scr_end.cpp:43 (5)
    //         0049372f     JMP        LAB_00493bc3
    //                               LAB_00493734                                                 XREF[1]:     00493727(j)  
    //                              scr_end.cpp:48 (13)
    //         00493734     MOV        EDX,dword ptr [EBP + 0x20]
    //         00493737     MOV        EAX,dword ptr [EDX + 0x18]
    //         0049373a     CMP        EAX,0x320
    //         0049373f     JGE        LAB_0049374c
    //                              scr_end.cpp:49 (9)
    //         00493741     LEA        EDX=>backgroundName[4],[ESP + 0x18]
    //         00493745     MOV        EDI,s_bgA640                                     = 62h
    //                              scr_end.cpp:50 (7)
    //         0049374a     JMP        LAB_00493761
    //                               LAB_0049374c                                                 XREF[1]:     0049373f(j)  
    //         0049374c     CMP        EAX,0x400
    //                              scr_end.cpp:51 (11)
    //         00493751     LEA        EDX=>backgroundName[4],[ESP + 0x18]
    //         00493755     MOV        EDI,s_bgA800                                     = "bgA800"
    //         0049375a     JL         LAB_00493761
    //                              scr_end.cpp:53 (16)
    //         0049375c     MOV        EDI,s_bgA1024                                    = "bgA1024"
    //                               LAB_00493761                                                 XREF[2]:     0049374a(j), 0049375a(j)  
    //         00493761     OR         this,0xffffffff
    //         00493764     XOR        EAX,EAX
    //         00493766     SCASB.RE   ES:EDI=>s_bgA640                                 = "bgA1024"
    //                                                                                  = "bgA800"
    //                                                                                  = 62h
    //                                                                                  = "gA640"
    //         00493768     NOT        this
    //         0049376a     SUB        EDI,this
    //                              scr_end.cpp:56 (55)
    //         0049376c     PUSH       0x11c
    //         00493771     MOV        EAX,this
    //         00493773     MOV        ESI,EDI
    //         00493775     MOV        EDI,EDX
    //         00493777     SHR        this,0x2
    //         0049377a     MOVSD.REP  ES:EDI,ESI
    //         0049377c     MOV        this,EAX
    //         0049377e     AND        this,0x3
    //         00493781     MOVSB.REP  ES:EDI,ESI
    //         00493783     CALL       operator_new                                     void * operator_new(uint param_1)
    //         00493788     ADD        ESP,0x4
    //         0049378b     MOV        dword ptr [ESP + local_20],EAX
    //         0049378f     TEST       EAX,EAX
    //         00493791     MOV        byte ptr [ESP + local_4],0x1
    //         00493796     JZ         LAB_004937a1
    //         00493798     MOV        this,EAX
    //         0049379a     CALL       TPicturePanel::TPicturePanel                     undefined TPicturePanel(TPicturePanel * this)
    //         0049379f     JMP        LAB_004937a3
    //                               LAB_004937a1                                                 XREF[1]:     00493796(j)  
    //         004937a1     XOR        EAX,EAX
    //                               LAB_004937a3                                                 XREF[1]:     0049379f(j)  
    //                              scr_end.cpp:57 (15)
    //         004937a3     TEST       EAX,EAX
    //         004937a5     MOV        byte ptr [ESP + local_4],0x0
    //         004937aa     MOV        dword ptr [EBP + 0x478],EAX
    //         004937b0     JNZ        LAB_004937bd
    //                              scr_end.cpp:58 (6)
    //         004937b2     MOV        dword ptr [EBP + 0xd8],EBX
    //                              scr_end.cpp:59 (5)
    //         004937b8     JMP        LAB_00493bc3
    //                               LAB_004937bd                                                 XREF[1]:     004937b0(j)  
    //                              scr_end.cpp:62 (34)
    //         004937bd     MOV        EDX,dword ptr [EBP + 0x20]
    //         004937c0     PUSH       EBX
    //         004937c1     PUSH       0x0
    //         004937c3     LEA        this=>backgroundName[4],[ESP + 0x20]
    //         004937c7     PUSH       -0x1
    //         004937c9     PUSH       this
    //         004937ca     PUSH       0x0
    //         004937cc     PUSH       0x0
    //         004937ce     PUSH       0x0
    //         004937d0     PUSH       0x0
    //         004937d2     PUSH       EBP
    //         004937d3     PUSH       EDX
    //         004937d4     MOV        this,EAX
    //         004937d6     CALL       TPicturePanel::setup                             long setup(TPicturePanel * this, TDrawArea * 
    //         004937db     TEST       EAX,EAX
    //         004937dd     JNZ        LAB_004937ea
    //                              scr_end.cpp:63 (6)
    //         004937df     MOV        dword ptr [EBP + 0xd8],EBX
    //                              scr_end.cpp:64 (5)
    //         004937e5     JMP        LAB_00493bc3
    //                               LAB_004937ea                                                 XREF[1]:     004937dd(j)  
    //                              scr_end.cpp:69 (92)
    //         004937ea     MOV        EAX,dword ptr [EBP + 0x18]
    //         004937ed     MOV        this,dword ptr [EBP + 0x478]
    //         004937f3     PUSH       0x0
    //         004937f5     PUSH       0x0
    //         004937f7     LEA        ESI,[EAX + EAX*0x2]
    //         004937fa     MOV        EAX,0x88888889
    //         004937ff     PUSH       0x0
    //         00493801     PUSH       0x0
    //         00493803     LEA        ESI,[ESI + ESI*0x4]
    //         00493806     SHL        ESI,0x5
    //         00493809     IMUL       ESI
    //         0049380b     ADD        EDX,ESI
    //         0049380d     SAR        EDX,0x8
    //         00493810     MOV        EAX,EDX
    //         00493812     SHR        EAX,0x1f
    //         00493815     ADD        EDX,EAX
    //         00493817     MOV        EAX,dword ptr [EBP + 0x14]
    //         0049381a     MOV        ESI,EDX
    //         0049381c     LEA        EDX,[EAX + EAX*0x4]
    //         0049381f     MOV        EAX,0x66666667
    //         00493824     SHL        EDX,0x7
    //         00493827     IMUL       EDX
    //         00493829     SAR        EDX,0x8
    //         0049382c     MOV        EAX,EDX
    //         0049382e     PUSH       ESI
    //         0049382f     SHR        EAX,0x1f
    //         00493832     ADD        EDX,EAX
    //         00493834     MOV        EAX,dword ptr [this->_padding_]
    //         00493836     PUSH       ESI
    //         00493837     PUSH       EDX
    //         00493838     PUSH       EDX
    //         00493839     PUSH       0x0
    //         0049383b     PUSH       0x0
    //         0049383d     PUSH       0x0
    //         0049383f     PUSH       0x0
    //         00493841     PUSH       0x2
    //         00493843     CALL       dword ptr [EAX + 0x18]
    //                              scr_end.cpp:72 (12)
    //         00493846     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0049384c     PUSH       EBX
    //         0049384d     CALL       RGE_Base_Game::get_font                          RGE_Font * get_font(RGE_Base_Game * this, int
    //                              scr_end.cpp:75 (53)
    //         00493852     PUSH       0x188
    //         00493857     MOV        EBX,EAX
    //         00493859     CALL       operator_new                                     void * operator_new(uint param_1)
    //         0049385e     ADD        ESP,0x4
    //         00493861     MOV        dword ptr [ESP + 0x10],EAX
    //         00493865     TEST       EAX,EAX
    //         00493867     MOV        byte ptr [ESP + 0x2c],0x2
    //         0049386c     JZ         LAB_0049387b
    //         0049386e     MOV        this,EAX
    //         00493870     CALL       TTextPanel::TTextPanel                           undefined TTextPanel(TTextPanel * this)
    //         00493875     MOV        dword ptr [ESP + 0x10],EAX
    //         00493879     JMP        LAB_00493887
    //                               LAB_0049387b                                                 XREF[1]:     0049386c(j)  
    //         0049387b     MOV        dword ptr [ESP + 0x10],0x0
    //         00493883     MOV        EAX,dword ptr [ESP + 0x10]
    //                               LAB_00493887                                                 XREF[1]:     00493879(j)  
    //                              scr_end.cpp:76 (15)
    //         00493887     TEST       EAX,EAX
    //         00493889     MOV        byte ptr [ESP + 0x2c],0x0
    //         0049388e     MOV        dword ptr [EBP + 0x47c],EAX
    //         00493894     JNZ        LAB_004938a5
    //                              scr_end.cpp:77 (10)
    //         00493896     MOV        dword ptr [EBP + 0xd8],0x1
    //                              scr_end.cpp:78 (5)
    //         004938a0     JMP        LAB_00493bc3
    //                               LAB_004938a5                                                 XREF[1]:     00493894(j)  
    //                              scr_end.cpp:83 (162)
    //         004938a5     MOV        this,dword ptr [ESP + 0x34]
    //         004938a9     MOV        EDX,dword ptr [EBX + 0x8]
    //         004938ac     MOV        EAX,dword ptr [EBX + 0x4]
    //         004938af     MOV        ESI,dword ptr [EBP + 0x18]
    //         004938b2     PUSH       this
    //         004938b3     MOV        this,dword ptr [EBX]
    //         004938b5     PUSH       0x0=>DAT_fffffff8
    //         004938b7     PUSH       0x0=>DAT_fffffff4
    //         004938b9     PUSH       0x0=>DAT_fffffff0
    //         004938bb     PUSH       0x0
    //         004938bd     PUSH       0x0
    //         004938bf     PUSH       0x0
    //         004938c1     PUSH       EDX
    //         004938c2     PUSH       EAX
    //         004938c3     PUSH       this
    //         004938c4     LEA        this,[ESI + ESI*0x2]
    //         004938c7     MOV        EAX,0x88888889
    //         004938cc     MOV        EDI,dword ptr [EBP + 0x14]
    //         004938cf     LEA        this,[ECX + ECX*0x4]
    //         004938d2     SHL        this,0x1
    //         004938d4     IMUL       this
    //         004938d6     ADD        EDX,this
    //         004938d8     SAR        EDX,0x8
    //         004938db     MOV        EAX,EDX
    //         004938dd     SHR        EAX,0x1f
    //         004938e0     ADD        EDX,EAX
    //         004938e2     LEA        EAX,[EDI + EDI*0x2]
    //         004938e5     PUSH       EDX
    //         004938e6     LEA        EDI,[EDI + EDI*0x4]
    //         004938e9     LEA        this,[EAX + EAX*0x4]
    //         004938ec     MOV        EAX,0x66666667
    //         004938f1     SHL        EDI,0x2
    //         004938f4     LEA        this,[ECX + ECX*0x4]
    //         004938f7     SHL        this,0x3
    //         004938fa     IMUL       this
    //         004938fc     SAR        EDX,0x8
    //         004938ff     MOV        this,EDX
    //         00493901     MOV        EAX,0x88888889
    //         00493906     SHR        this,0x1f
    //         00493909     ADD        EDX,this
    //         0049390b     LEA        this,[ESI + ESI*0x4]
    //         0049390e     SHL        this,0x2
    //         00493911     PUSH       EDX
    //         00493912     IMUL       this
    //         00493914     ADD        EDX,this
    //         00493916     SAR        EDX,0x8
    //         00493919     MOV        EAX,EDX
    //         0049391b     SHR        EAX,0x1f
    //         0049391e     ADD        EDX,EAX
    //         00493920     MOV        EAX,0x66666667
    //         00493925     PUSH       EDX
    //         00493926     IMUL       EDI
    //         00493928     SAR        EDX,0x8
    //         0049392b     MOV        this,EDX
    //         0049392d     MOV        EAX,dword ptr [EBP + 0x20]
    //         00493930     SHR        this,0x1f
    //         00493933     ADD        EDX,this
    //         00493935     MOV        this,dword ptr [ESP + 0x44]
    //         00493939     PUSH       EDX
    //         0049393a     MOV        EDX,dword ptr [EBP + 0x478]
    //         00493940     PUSH       EDX
    //         00493941     PUSH       EAX
    //         00493942     CALL       TTextPanel::setup                                long setup(TTextPanel * this, TDrawArea * par
    //                              scr_end.cpp:86 (37)
    //         00493947     PUSH       0x188
    //         0049394c     CALL       operator_new                                     void * operator_new(uint param_1)
    //         00493951     ADD        ESP,0x4
    //         00493954     MOV        dword ptr [ESP + 0x34],EAX
    //         00493958     TEST       EAX,EAX
    //         0049395a     MOV        byte ptr [ESP + 0x2c],0x3
    //         0049395f     JZ         LAB_0049396a
    //         00493961     MOV        this,EAX
    //         00493963     CALL       TTextPanel::TTextPanel                           undefined TTextPanel(TTextPanel * this)
    //         00493968     JMP        LAB_0049396c
    //                               LAB_0049396a                                                 XREF[1]:     0049395f(j)  
    //         0049396a     XOR        EAX,EAX
    //                               LAB_0049396c                                                 XREF[1]:     00493968(j)  
    //                              scr_end.cpp:87 (15)
    //         0049396c     TEST       EAX,EAX
    //         0049396e     MOV        byte ptr [ESP + 0x2c],0x0
    //         00493973     MOV        dword ptr [EBP + 0x480],EAX
    //         00493979     JNZ        LAB_0049398a
    //                              scr_end.cpp:88 (10)
    //         0049397b     MOV        dword ptr [EBP + 0xd8],0x1
    //                              scr_end.cpp:89 (5)
    //         00493985     JMP        LAB_00493bc3
    //                               LAB_0049398a                                                 XREF[1]:     00493979(j)  
    //                              scr_end.cpp:91 (13)
    //         0049398a     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         00493990     PUSH       0xb
    //         00493992     CALL       RGE_Base_Game::get_font                          RGE_Font * get_font(RGE_Base_Game * this, int
    //                              scr_end.cpp:95 (174)
    //         00493997     MOV        EDX,dword ptr [EAX + 0x8]
    //         0049399a     PUSH       0x0
    //         0049399c     PUSH       0x0=>DAT_fffffff8
    //         0049399e     MOV        this,dword ptr [EBP + 0x18]
    //         004939a1     PUSH       0x0=>DAT_fffffff4
    //         004939a3     PUSH       0x0=>DAT_fffffff0
    //         004939a5     PUSH       0x0
    //         004939a7     PUSH       0x0
    //         004939a9     PUSH       0x0
    //         004939ab     PUSH       EDX
    //         004939ac     MOV        EDX,dword ptr [EAX + 0x4]
    //         004939af     MOV        EAX,dword ptr [EAX]
    //         004939b1     PUSH       EDX
    //         004939b2     PUSH       EAX
    //         004939b3     MOV        EAX,this
    //         004939b5     MOV        ESI,dword ptr [EBP + 0x14]
    //         004939b8     SHL        EAX,0x4
    //         004939bb     ADD        EAX,this
    //         004939bd     LEA        EDI,[EAX + EAX*0x4]
    //         004939c0     MOV        EAX,0x88888889
    //         004939c5     SHL        EDI,0x2
    //         004939c8     IMUL       EDI
    //         004939ca     ADD        EDX,EDI
    //         004939cc     SAR        EDX,0x8
    //         004939cf     MOV        EAX,EDX
    //         004939d1     SHR        EAX,0x1f
    //         004939d4     ADD        EDX,EAX
    //         004939d6     LEA        EAX,[ESI + ESI*0x2]
    //         004939d9     PUSH       EDX
    //         004939da     LEA        EDX,[EAX + EAX*0x4]
    //         004939dd     MOV        EAX,0x66666667
    //         004939e2     LEA        EDX,[EDX + EDX*0x4]
    //         004939e5     SHL        EDX,0x3
    //         004939e8     IMUL       EDX
    //         004939ea     SAR        EDX,0x8
    //         004939ed     MOV        EAX,EDX
    //         004939ef     SHR        EAX,0x1f
    //         004939f2     ADD        EDX,EAX
    //         004939f4     LEA        EAX,[this->_padding_*0x8 + 0x0]
    //         004939fb     SUB        EAX,this
    //         004939fd     PUSH       EDX
    //         004939fe     LEA        this,[EAX + EAX*0x4]
    //         00493a01     MOV        EAX,0x88888889
    //         00493a06     SHL        this,0x1
    //         00493a08     IMUL       this
    //         00493a0a     ADD        EDX,this
    //         00493a0c     MOV        EAX,0x66666667
    //         00493a11     SAR        EDX,0x8
    //         00493a14     MOV        this,EDX
    //         00493a16     SHR        this,0x1f
    //         00493a19     ADD        EDX,this
    //         00493a1b     LEA        this,[ESI + ESI*0x4]
    //         00493a1e     SHL        this,0x2
    //         00493a21     PUSH       EDX
    //         00493a22     IMUL       this
    //         00493a24     SAR        EDX,0x8
    //         00493a27     MOV        this,dword ptr [EBP + 0x478]
    //         00493a2d     MOV        EAX,EDX
    //         00493a2f     SHR        EAX,0x1f
    //         00493a32     ADD        EDX,EAX
    //         00493a34     PUSH       EDX
    //         00493a35     MOV        EDX,dword ptr [EBP + 0x20]
    //         00493a38     PUSH       this
    //         00493a39     MOV        this,dword ptr [EBP + 0x480]
    //         00493a3f     PUSH       EDX
    //         00493a40     CALL       TTextPanel::setup                                long setup(TTextPanel * this, TDrawArea * par
    //                              scr_end.cpp:96 (24)
    //         00493a45     MOV        EDX,dword ptr [ESP + 0x3c]
    //         00493a49     MOV        this,dword ptr [EBP + 0x480]
    //         00493a4f     PUSH       EDX
    //         00493a50     MOV        EDX,dword ptr [ESP + 0x3c]
    //         00493a54     MOV        EAX,dword ptr [this->_padding_]
    //         00493a56     PUSH       EDX=>DAT_fffffff8
    //         00493a57     CALL       dword ptr [EAX + 0xe0]
    //                              scr_end.cpp:97 (15)
    //         00493a5d     MOV        this,dword ptr [EBP + 0x480]
    //         00493a63     PUSH       0x0
    //         00493a65     PUSH       0x0=>DAT_fffffff8
    //         00493a67     CALL       TTextPanel::set_alignment                        void set_alignment(TTextPanel * this, Alignme
    //                              scr_end.cpp:98 (17)
    //         00493a6c     PUSH       0x1
    //         00493a6e     MOV        this,dword ptr [EBP + 0x480]
    //         00493a74     PUSH       0x0=>DAT_fffffff8
    //         00493a76     PUSH       offset DAT_fffffff4
    //         00493a78     CALL       TTextPanel::scroll                               void scroll(TTextPanel * this, uchar param_1,
    //                              scr_end.cpp:101 (13)
    //         00493a7d     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         00493a83     PUSH       0x0
    //         00493a85     CALL       RGE_Base_Game::get_sound                         TDigital * get_sound(RGE_Base_Game * this, in
    //                              scr_end.cpp:102 (15)
    //         00493a8a     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         00493a90     PUSH       0x0
    //         00493a92     MOV        ESI,EAX
    //         00493a94     CALL       RGE_Base_Game::get_font                          RGE_Font * get_font(RGE_Base_Game * this, int
    //                              scr_end.cpp:103 (53)
    //         00493a99     PUSH       0x2b8
    //         00493a9e     MOV        EBX,EAX
    //         00493aa0     CALL       operator_new                                     void * operator_new(uint param_1)
    //         00493aa5     ADD        ESP,0x4
    //         00493aa8     MOV        dword ptr [ESP + 0x34],EAX
    //         00493aac     TEST       EAX,EAX
    //         00493aae     MOV        byte ptr [ESP + 0x2c],0x4
    //         00493ab3     JZ         LAB_00493ac2
    //         00493ab5     MOV        this,EAX
    //         00493ab7     CALL       TButtonPanel::TButtonPanel                       undefined TButtonPanel(TButtonPanel * this)
    //         00493abc     MOV        dword ptr [ESP + 0x34],EAX
    //         00493ac0     JMP        LAB_00493ace
    //                               LAB_00493ac2                                                 XREF[1]:     00493ab3(j)  
    //         00493ac2     MOV        dword ptr [ESP + 0x34],0x0
    //         00493aca     MOV        EAX,dword ptr [ESP + 0x34]
    //                               LAB_00493ace                                                 XREF[1]:     00493ac0(j)  
    //                              scr_end.cpp:104 (15)
    //         00493ace     TEST       EAX,EAX
    //         00493ad0     MOV        byte ptr [ESP + 0x2c],0x0
    //         00493ad5     MOV        dword ptr [EBP + 0x484],EAX
    //         00493adb     JNZ        LAB_00493aec
    //                              scr_end.cpp:105 (10)
    //         00493add     MOV        dword ptr [EBP + 0xd8],0x1
    //                              scr_end.cpp:106 (5)
    //         00493ae7     JMP        LAB_00493bc3
    //                               LAB_00493aec                                                 XREF[1]:     00493adb(j)  
    //                              scr_end.cpp:110 (152)
    //         00493aec     MOV        EDI,dword ptr [EBP + 0x18]
    //         00493aef     PUSH       0x0
    //         00493af1     PUSH       offset DAT_fffffff8
    //         00493af3     PUSH       ESI=>DAT_fffffff4
    //         00493af4     LEA        ESI,[EDI + EDI*0x4]
    //         00493af7     MOV        EAX,0x88888889
    //         00493afc     SHL        ESI,0x3
    //         00493aff     IMUL       ESI
    //         00493b01     MOV        this,dword ptr [EBP + 0x14]
    //         00493b04     ADD        EDX,ESI
    //         00493b06     SAR        EDX,0x8
    //         00493b09     MOV        EAX,EDX
    //         00493b0b     PUSH       offset DAT_fffffff0
    //         00493b0d     SHR        EAX,0x1f
    //         00493b10     ADD        EDX,EAX
    //         00493b12     LEA        EAX,[ECX + ECX*0x2]
    //         00493b15     PUSH       EDX
    //         00493b16     LEA        ESI,[EDI + EDI*0x2]
    //         00493b19     LEA        EDX,[EAX + EAX*0x4]
    //         00493b1c     MOV        EAX,0x66666667
    //         00493b21     LEA        ESI,[ESI + ESI*0x8]
    //         00493b24     LEA        EDX,[EDX + EDX*0x4]
    //         00493b27     SHL        EDX,0x2
    //         00493b2a     IMUL       EDX
    //         00493b2c     SAR        EDX,0x8
    //         00493b2f     MOV        EAX,EDX
    //         00493b31     SHL        ESI,0x3
    //         00493b34     SHR        EAX,0x1f
    //         00493b37     SUB        ESI,EDI
    //         00493b39     ADD        EDX,EAX
    //         00493b3b     SHL        ESI,0x1
    //         00493b3d     MOV        EAX,0x88888889
    //         00493b42     PUSH       EDX
    //         00493b43     IMUL       ESI
    //         00493b45     ADD        EDX,ESI
    //         00493b47     SAR        EDX,0x8
    //         00493b4a     MOV        EAX,EDX
    //         00493b4c     SHR        EAX,0x1f
    //         00493b4f     ADD        EDX,EAX
    //         00493b51     MOV        EAX,this
    //         00493b53     SHL        EAX,0x4
    //         00493b56     ADD        EAX,this
    //         00493b58     PUSH       EDX
    //         00493b59     LEA        this,[EAX + EAX*0x4]
    //         00493b5c     MOV        EAX,0x66666667
    //         00493b61     SHL        this,0x1
    //         00493b63     IMUL       this
    //         00493b65     SAR        EDX,0x8
    //         00493b68     MOV        this,EDX
    //         00493b6a     MOV        EAX,dword ptr [EBP + 0x20]
    //         00493b6d     SHR        this,0x1f
    //         00493b70     ADD        EDX,this
    //         00493b72     MOV        this,dword ptr [ESP + 0x50]
    //         00493b76     PUSH       EDX
    //         00493b77     MOV        EDX,dword ptr [EBP + 0x478]
    //         00493b7d     PUSH       EDX
    //         00493b7e     PUSH       EAX
    //         00493b7f     CALL       TButtonPanel::setup                              long setup(TButtonPanel * this, TDrawArea * p
    //                              scr_end.cpp:112 (31)
    //         00493b84     MOV        this,dword ptr [EBX + 0x8]
    //         00493b87     MOV        EDX,dword ptr [EBX + 0x4]
    //         00493b8a     MOV        EAX,dword ptr [EBX]
    //         00493b8c     PUSH       -0x1
    //         00493b8e     PUSH       offset DAT_fffffff8
    //         00493b90     PUSH       this=>DAT_fffffff4
    //         00493b91     MOV        this,dword ptr [EBP + 0x484]
    //         00493b97     PUSH       EDX=>DAT_fffffff0
    //         00493b98     PUSH       EAX
    //         00493b99     PUSH       s_OK                                             = "OK"
    //         00493b9e     CALL       TButtonPanel::set_text_info                      void set_text_info(TButtonPanel * this, char 
    //                              scr_end.cpp:114 (14)
    //         00493ba3     MOV        this,dword ptr [EBP + 0x478]
    //         00493ba9     PUSH       this
    //         00493baa     MOV        this,EBP
    //         00493bac     CALL       TPanel::set_curr_child                           void set_curr_child(TPanel * this, TPanel * p
    //                              scr_end.cpp:115 (18)
    //         00493bb1     MOV        EDX,dword ptr [EBP + 0x480]
    //         00493bb7     MOV        this,dword ptr [EBP + 0x478]
    //         00493bbd     PUSH       EDX
    //         00493bbe     CALL       TPanel::set_curr_child                           void set_curr_child(TPanel * this, TPanel * p
    //                               LAB_00493bc3                                                 XREF[6]:     0049372f(j), 004937b8(j), 
    //                                                                                                         004937e5(j), 004938a0(j), 
    //                                                                                                         00493985(j), 00493ae7(j)  
    //                              scr_end.cpp:116 (23)
    //         00493bc3     MOV        this,dword ptr [ESP + local_c]
    //         00493bc7     POP        EDI
    //         00493bc8     MOV        EAX,EBP
    //         00493bca     POP        ESI
    //         00493bcb     POP        EBP
    //         00493bcc     MOV        dword ptr FS:[0x0],this
    //         00493bd3     POP        EBX
    //         00493bd4     ADD        ESP,0x20
    //         00493bd7     RET        0xc
}

// Offset: 0x00493C00
void TribeEndScreen(TribeEndScreen* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual __thiscall TribeEndScreen::~TribeEndScreen(void)                                      *
    //                              *********************************************************************************************************
    //                              void __thiscall ~TribeEndScreen(TribeEndScreen * this)
    //              void              <VOID>         <RETURN>
    //              TribeEndScreen    ECX:4 (auto)   this
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     00493c29(W)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     00493c19(W)  
    //                               ??1TribeEndScreen@@UAE@XZ                                    XREF[1]:     `scalar_deleting_destructor':00493
    //                               TribeEndScreen::~TribeEndScreen
    //                              scr_end.cpp:121 (35)
    //         00493c00     PUSH       -0x1
    //         00493c02     PUSH       FUN_0055eb88
    //         00493c07     MOV        EAX,FS:[0x0]
    //         00493c0d     PUSH       EAX
    //         00493c0e     MOV        dword ptr FS:[0x0],ESP
    //         00493c15     PUSH       this
    //         00493c16     PUSH       ESI
    //         00493c17     MOV        ESI,this
    //         00493c19     MOV        dword ptr [ESP + local_10],ESI
    //         00493c1d     MOV        dword ptr [ESI],TribeEndScreen::`vftable'        = 00493be0
    //                              scr_end.cpp:122 (24)
    //         00493c23     MOV        this,dword ptr [ESI + 0x47c]
    //         00493c29     MOV        dword ptr [ESP + local_4],0x0
    //         00493c31     TEST       this,this
    //         00493c33     JZ         LAB_00493c3b
    //         00493c35     MOV        EAX,dword ptr [this->_padding_]
    //         00493c37     PUSH       0x1
    //         00493c39     CALL       dword ptr [EAX]
    //                               LAB_00493c3b                                                 XREF[1]:     00493c33(j)  
    //                              scr_end.cpp:123 (16)
    //         00493c3b     MOV        this,dword ptr [ESI + 0x480]
    //         00493c41     TEST       this,this
    //         00493c43     JZ         LAB_00493c4b
    //         00493c45     MOV        EDX,dword ptr [this->_padding_]
    //         00493c47     PUSH       0x1
    //         00493c49     CALL       dword ptr [EDX]
    //                               LAB_00493c4b                                                 XREF[1]:     00493c43(j)  
    //                              scr_end.cpp:124 (16)
    //         00493c4b     MOV        this,dword ptr [ESI + 0x484]
    //         00493c51     TEST       this,this
    //         00493c53     JZ         LAB_00493c5b
    //         00493c55     MOV        EAX,dword ptr [this->_padding_]
    //         00493c57     PUSH       0x1
    //         00493c59     CALL       dword ptr [EAX]
    //                               LAB_00493c5b                                                 XREF[1]:     00493c53(j)  
    //                              scr_end.cpp:125 (18)
    //         00493c5b     MOV        this,dword ptr [ESI + 0x478]
    //         00493c61     TEST       this,this
    //         00493c63     JZ         LAB_00493c6b
    //         00493c65     MOV        EDX,dword ptr [this->_padding_]
    //         00493c67     PUSH       0x1
    //         00493c69     CALL       dword ptr [EDX]
    //                               LAB_00493c6b                                                 XREF[1]:     00493c63(j)  
    //         00493c6b     MOV        this,ESI
    //                              scr_end.cpp:126 (29)
    //         00493c6d     MOV        dword ptr [ESP + 0x10],0xffffffff
    //         00493c75     CALL       TScreenPanel::~TScreenPanel                      void ~TScreenPanel(TScreenPanel * this)
    //         00493c7a     MOV        this,dword ptr [ESP + 0x8]
    //         00493c7e     POP        ESI
    //         00493c7f     MOV        dword ptr FS:[0x0],this
    //         00493c86     ADD        ESP,0x10
    //         00493c89     RET
}

// Offset: 0x00493C90
long TribeEndScreen::action(TPanel* param_1, long param_2, ulong param_3, ulong param_4) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * protected: virtual long __thiscall TribeEndScreen::action(class TPanel *,long,unsigned long,unsign... *
    //                              *********************************************************************************************************
    //                              long __thiscall action(TribeEndScreen * this, TPanel * param_1, long
    //              long              EAX:4          <RETURN>
    //              TribeEndScreen    ECX:4 (auto)   this
    //              TPanel *          Stack[0x4]:4   param_1                   XREF[2]:     00493c9e(R), 00493cc9(W)  
    //              long              Stack[0x8]:4   param_2                   XREF[1]:     00493cac(R)  
    //              ulong             Stack[0xc]:4   param_3                   XREF[1]:     00493d34(R)  
    //              ulong             Stack[0x10]:4  param_4                   XREF[1]:     00493d2f(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     00493ccf(W), 00493cfb(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[2]:     00493d1c(R), 00493d42(R)  
    //                               ?action@TribeEndScreen@@MAEJPAVTPanel@@JKK@Z                 XREF[1]:     00572a34(*)  
    //                               TribeEndScreen::action
    //                              scr_end.cpp:132 (14)
    //         00493c90     MOV        EAX,FS:[0x0]
    //         00493c96     PUSH       -0x1
    //         00493c98     PUSH       FUN_0055ebab
    //         00493c9d     PUSH       EAX
    //                              scr_end.cpp:133 (28)
    //         00493c9e     MOV        EAX,dword ptr [ESP + param_1]
    //         00493ca2     MOV        dword ptr FS:[0x0],ESP
    //         00493ca9     PUSH       ESI
    //         00493caa     MOV        ESI,this
    //         00493cac     MOV        this,dword ptr [ESP + param_2]
    //         00493cb0     PUSH       EDI
    //         00493cb1     TEST       EAX,EAX
    //         00493cb3     JZ         LAB_00493d2f
    //         00493cb5     CMP        this,0x1
    //         00493cb8     JNZ        LAB_00493d2f
    //                              scr_end.cpp:135 (53)
    //         00493cba     PUSH       0x5f8
    //         00493cbf     CALL       operator_new                                     void * operator_new(uint param_1)
    //         00493cc4     MOV        EDI,EAX
    //         00493cc6     ADD        ESP,0x4
    //         00493cc9     MOV        dword ptr [ESP + param_1],EDI
    //         00493ccd     TEST       EDI,EDI
    //         00493ccf     MOV        dword ptr [ESP + local_4],0x0
    //         00493cd7     JZ         LAB_00493cef
    //         00493cd9     PUSH       0x1
    //                              language.dll match for 0x269e: "Achievements"
    //         00493cdb     PUSH       0x269e
    //         00493ce0     MOV        this,ESI
    //         00493ce2     CALL       TPanel::get_string                               char * get_string(TPanel * this, int param_1)
    //         00493ce7     PUSH       EAX
    //         00493ce8     MOV        this,EDI
    //         00493cea     CALL       TribeAchievementsScreen::TribeAchievementsScreen undefined TribeAchievementsScreen(TribeAchiev
    //                               LAB_00493cef                                                 XREF[1]:     00493cd7(j)  
    //                              scr_end.cpp:137 (25)
    //         00493cef     PUSH       0x0
    //         00493cf1     PUSH       s_Achievements_Screen                            = "Achievements Screen"
    //         00493cf6     MOV        this,panel_system
    //         00493cfb     MOV        dword ptr [ESP + local_4],0xffffffff
    //         00493d03     CALL       TPanelSystem::setCurrentPanel                    int setCurrentPanel(TPanelSystem * this, char
    //                              scr_end.cpp:139 (15)
    //         00493d08     PUSH       s_End_Screen                                     = "End Screen"
    //         00493d0d     MOV        this,panel_system
    //         00493d12     CALL       TPanelSystem::destroyPanel                       int destroyPanel(TPanelSystem * this, char * 
    //                              scr_end.cpp:140 (5)
    //         00493d17     MOV        EAX,0x1
    //                              scr_end.cpp:143 (19)
    //         00493d1c     MOV        this,dword ptr [ESP + local_c]
    //         00493d20     MOV        dword ptr FS:[0x0],this
    //         00493d27     POP        EDI
    //         00493d28     POP        ESI
    //         00493d29     ADD        ESP,0xc
    //         00493d2c     RET        0x10
    //                               LAB_00493d2f                                                 XREF[2]:     00493cb3(j), 00493cb8(j)  
    //                              scr_end.cpp:142 (19)
    //         00493d2f     MOV        EDX,dword ptr [ESP + param_4]
    //         00493d33     PUSH       EDX
    //         00493d34     MOV        EDX,dword ptr [ESP + param_3]
    //         00493d38     PUSH       EDX
    //         00493d39     PUSH       this
    //         00493d3a     PUSH       EAX
    //         00493d3b     MOV        this,ESI
    //         00493d3d     CALL       TEasy_Panel::action                              long action(TEasy_Panel * this, TPanel * para
    //                              scr_end.cpp:143 (19)
    //         00493d42     MOV        this,dword ptr [ESP + local_c]
    //         00493d46     POP        EDI
    //         00493d47     MOV        dword ptr FS:[0x0],this
    //         00493d4e     POP        ESI
    //         00493d4f     ADD        ESP,0xc
    //         00493d52     RET        0x10
}

