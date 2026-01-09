#include "common.h"
#include "scr_trb.h"

TribeSelectTribeScreen::TribeSelectTribeScreen() {
    /* TODO: Stub */
    //                              undefined __thiscall TribeSelectTribeScreen(TribeSelectTribeScreen *
    //              undefined         <UNASSIGNED>   <RETURN>
    //              TribeSelectTri    ECX:4 (auto)   this
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[3]:     004b75ea(W), 004b7673(W), 004b7687(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[3]:     004b7603(R), 004b76a0(R), 004b76dd(R)  
    //              TPanel *[10]      Stack[-0x38]   tabList
    //              char[10]          Stack[-0x44]   backgroundName            XREF[1,3]:   004b75c3(W), 004b7623(*), 004b7633(*), 004b76b9(*)  
    //              undefined4        Stack[-0x48]:4 local_48                  XREF[1]:     004b766d(W)  
    //              RGE_Font *        Stack[-0x4c]:4 font
    //              int               Stack[-0x50]:4 i
    //              TDigital *        Stack[-0x54]:4 buttonSound
    //              int               Stack[-0x58]:4 secondWidth
    //              int               Stack[-0x60]:4 secondHeight
    //                               ??0TribeSelectTribeScreen@@QAE@XZ
    //                               TribeSelectTribeScreen::TribeSelectTribeScreen
    //                              scr_trb.cpp:37 (59)
    //         004b75a0     PUSH       -0x1
    //         004b75a2     PUSH       FUN_0055f81a
    //         004b75a7     MOV        EAX,FS:[0x0]
    //         004b75ad     PUSH       EAX
    //         004b75ae     MOV        dword ptr FS:[0x0],ESP
    //         004b75b5     SUB        ESP,0x54
    //         004b75b8     PUSH       EBX
    //         004b75b9     PUSH       EBP
    //         004b75ba     PUSH       ESI
    //         004b75bb     PUSH       EDI
    //         004b75bc     MOV        EBP,this
    //         004b75be     PUSH       s_Select_Tribe_Screen                            = "Select Tribe Screen"
    //         004b75c3     MOV        dword ptr [ESP + backgroundName[0]],EBP
    //         004b75c7     CALL       TScreenPanel::TScreenPanel                       undefined TScreenPanel(TScreenPanel * this, c
    //         004b75cc     XOR        EBX,EBX
    //         004b75ce     MOV        dword ptr [EBP],TribeSelectTribeScreen::`vftab   = 004b7dd0
    //         004b75d5     MOV        dword ptr [EBP + 0x4b0],EBX
    //                              scr_trb.cpp:44 (28)
    //         004b75db     MOV        EAX,[rge_base_game]                              = 00000000
    //         004b75e0     PUSH       0x1
    //         004b75e2     PUSH       EBX
    //         004b75e3     MOV        this,dword ptr [EAX + 0x4c]
    //         004b75e6     PUSH       EBX
    //         004b75e7     PUSH       this
    //         004b75e8     MOV        this,EBP
    //         004b75ea     MOV        dword ptr [ESP + local_4],EBX
    //         004b75ee     CALL       TScreenPanel::setup                              long setup(TScreenPanel * this, TDrawArea * p
    //         004b75f3     TEST       EAX,EAX
    //         004b75f5     JNZ        LAB_004b7616
    //                              scr_trb.cpp:45 (10)
    //         004b75f7     MOV        dword ptr [EBP + 0xd8],0x1
    //                              scr_trb.cpp:157 (21)
    //         004b7601     MOV        EAX,EBP
    //         004b7603     MOV        this,dword ptr [ESP + local_c]
    //         004b7607     MOV        dword ptr FS:[0x0],this
    //         004b760e     POP        EDI
    //         004b760f     POP        ESI
    //         004b7610     POP        EBP
    //         004b7611     POP        EBX
    //         004b7612     ADD        ESP,0x60
    //         004b7615     RET
    //                               LAB_004b7616                                                 XREF[1]:     004b75f5(j)  
    //                              scr_trb.cpp:50 (13)
    //         004b7616     MOV        EDX,dword ptr [EBP + 0x20]
    //         004b7619     MOV        EAX,dword ptr [EDX + 0x18]
    //         004b761c     CMP        EAX,0x320
    //         004b7621     JGE        LAB_004b762e
    //                              scr_trb.cpp:51 (9)
    //         004b7623     LEA        EDX=>backgroundName[4],[ESP + 0x30]
    //         004b7627     MOV        EDI,s_bgA640                                     = 62h
    //                              scr_trb.cpp:52 (7)
    //         004b762c     JMP        LAB_004b7643
    //                               LAB_004b762e                                                 XREF[1]:     004b7621(j)  
    //         004b762e     CMP        EAX,0x400
    //                              scr_trb.cpp:53 (11)
    //         004b7633     LEA        EDX=>backgroundName[4],[ESP + 0x30]
    //         004b7637     MOV        EDI,s_bgA800                                     = "bgA800"
    //         004b763c     JL         LAB_004b7643
    //                              scr_trb.cpp:55 (16)
    //         004b763e     MOV        EDI,s_bgA1024                                    = "bgA1024"
    //                               LAB_004b7643                                                 XREF[2]:     004b762c(j), 004b763c(j)  
    //         004b7643     OR         this,0xffffffff
    //         004b7646     XOR        EAX,EAX
    //         004b7648     SCASB.RE   ES:EDI=>s_bgA640                                 = "bgA1024"
    //                                                                                  = "bgA800"
    //                                                                                  = 62h
    //                                                                                  = "gA640"
    //         004b764a     NOT        this
    //         004b764c     SUB        EDI,this
    //                              scr_trb.cpp:58 (55)
    //         004b764e     PUSH       0x11c
    //         004b7653     MOV        EAX,this
    //         004b7655     MOV        ESI,EDI
    //         004b7657     MOV        EDI,EDX
    //         004b7659     SHR        this,0x2
    //         004b765c     MOVSD.REP  ES:EDI,ESI
    //         004b765e     MOV        this,EAX
    //         004b7660     AND        this,0x3
    //         004b7663     MOVSB.REP  ES:EDI,ESI
    //         004b7665     CALL       operator_new                                     void * operator_new(uint param_1)
    //         004b766a     ADD        ESP,0x4
    //         004b766d     MOV        dword ptr [ESP + local_48],EAX
    //         004b7671     CMP        EAX,EBX
    //         004b7673     MOV        byte ptr [ESP + local_4],0x1
    //         004b7678     JZ         LAB_004b7683
    //         004b767a     MOV        this,EAX
    //         004b767c     CALL       TPicturePanel::TPicturePanel                     undefined TPicturePanel(TPicturePanel * this)
    //         004b7681     JMP        LAB_004b7685
    //                               LAB_004b7683                                                 XREF[1]:     004b7678(j)  
    //         004b7683     XOR        EAX,EAX
    //                               LAB_004b7685                                                 XREF[1]:     004b7681(j)  
    //                              scr_trb.cpp:59 (15)
    //         004b7685     CMP        EAX,EBX
    //         004b7687     MOV        byte ptr [ESP + local_4],0x0
    //         004b768c     MOV        dword ptr [EBP + 0x478],EAX
    //         004b7692     JNZ        LAB_004b76b3
    //                              scr_trb.cpp:60 (10)
    //         004b7694     MOV        dword ptr [EBP + 0xd8],0x1
    //                              scr_trb.cpp:157 (21)
    //         004b769e     MOV        EAX,EBP
    //         004b76a0     MOV        this,dword ptr [ESP + local_c]
    //         004b76a4     MOV        dword ptr FS:[0x0],this
    //         004b76ab     POP        EDI
    //         004b76ac     POP        ESI
    //         004b76ad     POP        EBP
    //         004b76ae     POP        EBX
    //         004b76af     ADD        ESP,0x60
    //         004b76b2     RET
    //                               LAB_004b76b3                                                 XREF[1]:     004b7692(j)  
    //                              scr_trb.cpp:64 (30)
    //         004b76b3     MOV        EDX,dword ptr [EBP + 0x20]
    //         004b76b6     PUSH       0x1
    //         004b76b8     PUSH       EBX
    //         004b76b9     LEA        this=>backgroundName[4],[ESP + 0x38]
    //         004b76bd     PUSH       -0x1
    //         004b76bf     PUSH       this
    //         004b76c0     PUSH       EBX
    //         004b76c1     PUSH       EBX
    //         004b76c2     PUSH       EBX
    //         004b76c3     PUSH       EBX
    //         004b76c4     PUSH       EBP
    //         004b76c5     PUSH       EDX
    //         004b76c6     MOV        this,EAX
    //         004b76c8     CALL       TPicturePanel::setup                             long setup(TPicturePanel * this, TDrawArea * 
    //         004b76cd     TEST       EAX,EAX
    //         004b76cf     JNZ        LAB_004b76f0
    //                              scr_trb.cpp:65 (10)
    //         004b76d1     MOV        dword ptr [EBP + 0xd8],0x1
    //                              scr_trb.cpp:157 (21)
    //         004b76db     MOV        EAX,EBP
    //         004b76dd     MOV        this,dword ptr [ESP + local_c]
    //         004b76e1     MOV        dword ptr FS:[0x0],this
    //         004b76e8     POP        EDI
    //         004b76e9     POP        ESI
    //         004b76ea     POP        EBP
    //         004b76eb     POP        EBX
    //         004b76ec     ADD        ESP,0x60
    //         004b76ef     RET
    //                               LAB_004b76f0                                                 XREF[1]:     004b76cf(j)  
    //                              scr_trb.cpp:71 (84)
    //         004b76f0     MOV        EAX,dword ptr [EBP + 0x18]
    //         004b76f3     MOV        this,dword ptr [EBP + 0x478]
    //         004b76f9     PUSH       EBX
    //         004b76fa     PUSH       EBX
    //         004b76fb     LEA        ESI,[EAX + EAX*0x2]
    //         004b76fe     MOV        EAX,0x88888889
    //         004b7703     PUSH       EBX
    //         004b7704     PUSH       EBX
    //         004b7705     LEA        ESI,[ESI + ESI*0x4]
    //         004b7708     SHL        ESI,0x5
    //         004b770b     IMUL       ESI
    //         004b770d     ADD        EDX,ESI
    //         004b770f     SAR        EDX,0x8
    //         004b7712     MOV        EAX,EDX
    //         004b7714     SHR        EAX,0x1f
    //         004b7717     ADD        EDX,EAX
    //         004b7719     MOV        EAX,dword ptr [EBP + 0x14]
    //         004b771c     MOV        ESI,EDX
    //         004b771e     LEA        EDX,[EAX + EAX*0x4]
    //         004b7721     MOV        EAX,0x66666667
    //         004b7726     SHL        EDX,0x7
    //         004b7729     IMUL       EDX
    //         004b772b     SAR        EDX,0x8
    //         004b772e     MOV        EAX,EDX
    //         004b7730     PUSH       ESI
    //         004b7731     SHR        EAX,0x1f
    //         004b7734     ADD        EDX,EAX
    //         004b7736     MOV        EAX,dword ptr [this->_padding_]
    //         004b7738     PUSH       ESI
    //         004b7739     PUSH       EDX
    //         004b773a     PUSH       EDX
    //         004b773b     PUSH       EBX
    //         004b773c     PUSH       EBX
    //         004b773d     PUSH       EBX
    //         004b773e     PUSH       EBX
    //         004b773f     PUSH       0x2
    //         004b7741     CALL       dword ptr [EAX + 0x18]
    //                              scr_trb.cpp:74 (13)
    //         004b7744     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004b774a     PUSH       0x1
    //         004b774c     CALL       RGE_Base_Game::get_font                          RGE_Font * get_font(RGE_Base_Game * this, int
    //                              scr_trb.cpp:77 (53)
    //         004b7751     PUSH       0x188
    //         004b7756     MOV        EBX,EAX
    //         004b7758     CALL       operator_new                                     void * operator_new(uint param_1)
    //         004b775d     ADD        ESP,0x4
    //         004b7760     MOV        dword ptr [ESP + 0x28],EAX
    //         004b7764     TEST       EAX,EAX
    //         004b7766     MOV        byte ptr [ESP + 0x6c],0x2
    //         004b776b     JZ         LAB_004b777a
    //         004b776d     MOV        this,EAX
    //         004b776f     CALL       TTextPanel::TTextPanel                           undefined TTextPanel(TTextPanel * this)
    //         004b7774     MOV        dword ptr [ESP + 0x14],EAX
    //         004b7778     JMP        LAB_004b7786
    //                               LAB_004b777a                                                 XREF[1]:     004b776b(j)  
    //         004b777a     MOV        dword ptr [ESP + 0x14],0x0
    //         004b7782     MOV        EAX,dword ptr [ESP + 0x14]
    //                               LAB_004b7786                                                 XREF[1]:     004b7778(j)  
    //                              scr_trb.cpp:78 (15)
    //         004b7786     TEST       EAX,EAX
    //         004b7788     MOV        byte ptr [ESP + 0x6c],0x0
    //         004b778d     MOV        dword ptr [EBP + 0x47c],EAX
    //         004b7793     JNZ        LAB_004b77b4
    //                              scr_trb.cpp:79 (10)
    //         004b7795     MOV        dword ptr [EBP + 0xd8],0x1
    //                              scr_trb.cpp:157 (21)
    //         004b779f     MOV        EAX,EBP
    //         004b77a1     MOV        this,dword ptr [ESP + 0x64]
    //         004b77a5     MOV        dword ptr FS:[0x0],this
    //         004b77ac     POP        EDI
    //         004b77ad     POP        ESI
    //         004b77ae     POP        EBP
    //         004b77af     POP        EBX
    //         004b77b0     ADD        ESP,0x60
    //         004b77b3     RET
    //                               LAB_004b77b4                                                 XREF[1]:     004b7793(j)  
    //                              scr_trb.cpp:85 (162)
    //         004b77b4     MOV        ESI,dword ptr [EBP + 0x18]
    //         004b77b7     MOV        this,dword ptr [EBX + 0x8]
    //         004b77ba     PUSH       s_Civilization_Selection                         = "Civilization Selection"
    //         004b77bf     PUSH       0x0=>DAT_fffffff8
    //         004b77c1     MOV        EDX,dword ptr [EBX + 0x4]
    //         004b77c4     PUSH       0x0=>DAT_fffffff4
    //         004b77c6     MOV        EAX,dword ptr [EBX]
    //         004b77c8     PUSH       0x0=>DAT_fffffff0
    //         004b77ca     PUSH       0x0
    //         004b77cc     PUSH       0x0
    //         004b77ce     PUSH       0x0
    //         004b77d0     PUSH       this
    //         004b77d1     LEA        this,[ESI + ESI*0x2]
    //         004b77d4     PUSH       EDX
    //         004b77d5     PUSH       EAX
    //         004b77d6     MOV        EAX,0x88888889
    //         004b77db     LEA        this,[ECX + ECX*0x4]
    //         004b77de     MOV        EDI,dword ptr [EBP + 0x14]
    //         004b77e1     SHL        this,0x1
    //         004b77e3     IMUL       this
    //         004b77e5     ADD        EDX,this
    //         004b77e7     LEA        EAX,[EDI + EDI*0x2]
    //         004b77ea     SAR        EDX,0x8
    //         004b77ed     MOV        this,EDX
    //         004b77ef     SHR        this,0x1f
    //         004b77f2     ADD        EDX,this
    //         004b77f4     LEA        this,[EAX + EAX*0x4]
    //         004b77f7     MOV        EAX,0x66666667
    //         004b77fc     PUSH       EDX
    //         004b77fd     LEA        this,[ECX + ECX*0x4]
    //         004b7800     SHL        this,0x3
    //         004b7803     IMUL       this
    //         004b7805     SAR        EDX,0x8
    //         004b7808     MOV        EAX,EDX
    //         004b780a     LEA        this,[ESI + ESI*0x4]
    //         004b780d     SHR        EAX,0x1f
    //         004b7810     ADD        EDX,EAX
    //         004b7812     MOV        EAX,0x88888889
    //         004b7817     SHL        this,0x2
    //         004b781a     PUSH       EDX
    //         004b781b     IMUL       this
    //         004b781d     ADD        EDX,this
    //         004b781f     MOV        EAX,0x66666667
    //         004b7824     SAR        EDX,0x8
    //         004b7827     MOV        this,EDX
    //         004b7829     SHR        this,0x1f
    //         004b782c     ADD        EDX,this
    //         004b782e     LEA        this,[EDI + EDI*0x4]
    //         004b7831     SHL        this,0x2
    //         004b7834     PUSH       EDX
    //         004b7835     IMUL       this
    //         004b7837     SAR        EDX,0x8
    //         004b783a     MOV        this,dword ptr [EBP + 0x478]
    //         004b7840     MOV        EAX,EDX
    //         004b7842     SHR        EAX,0x1f
    //         004b7845     ADD        EDX,EAX
    //         004b7847     PUSH       EDX
    //         004b7848     MOV        EDX,dword ptr [EBP + 0x20]
    //         004b784b     PUSH       this
    //         004b784c     MOV        this,dword ptr [ESP + 0x50]
    //         004b7850     PUSH       EDX
    //         004b7851     CALL       TTextPanel::setup                                long setup(TTextPanel * this, TDrawArea * par
    //                              scr_trb.cpp:87 (14)
    //         004b7856     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004b785c     XOR        EBX,EBX
    //         004b785e     PUSH       EBX
    //         004b785f     CALL       RGE_Base_Game::get_sound                         TDigital * get_sound(RGE_Base_Game * this, in
    //                              scr_trb.cpp:88 (20)
    //         004b7864     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004b786a     PUSH       EBX
    //         004b786b     MOV        dword ptr [ESP + 0x24],EAX
    //         004b786f     CALL       RGE_Base_Game::get_font                          RGE_Font * get_font(RGE_Base_Game * this, int
    //         004b7874     MOV        dword ptr [ESP + 0x28],EAX
    //                              scr_trb.cpp:157 (26)
    //         004b7878     LEA        EAX,[EBP + 0x484]
    //         004b787e     MOV        dword ptr [ESP + 0x1c],EBX
    //         004b7882     MOV        dword ptr [ESP + 0x14],EBX
    //         004b7886     MOV        dword ptr [ESP + 0x24],EBX
    //         004b788a     MOV        dword ptr [ESP + 0x10],EAX
    //         004b788e     JMP        LAB_004b7892
    //                               LAB_004b7890                                                 XREF[1]:     004b7a09(j)  
    //         004b7890     XOR        EBX,EBX
    //                               LAB_004b7892                                                 XREF[1]:     004b788e(j)  
    //                              scr_trb.cpp:92 (49)
    //         004b7892     PUSH       0x2b8
    //         004b7897     CALL       operator_new                                     void * operator_new(uint param_1)
    //         004b789c     ADD        ESP,0x4
    //         004b789f     MOV        dword ptr [ESP + 0x18],EAX
    //         004b78a3     CMP        EAX,EBX
    //         004b78a5     MOV        byte ptr [ESP + 0x6c],0x3
    //         004b78aa     JZ         LAB_004b78b9
    //         004b78ac     MOV        this,EAX
    //         004b78ae     CALL       TButtonPanel::TButtonPanel                       undefined TButtonPanel(TButtonPanel * this)
    //         004b78b3     MOV        dword ptr [ESP + 0x18],EAX
    //         004b78b7     JMP        LAB_004b78bf
    //                               LAB_004b78b9                                                 XREF[1]:     004b78aa(j)  
    //         004b78b9     MOV        dword ptr [ESP + 0x18],EBX
    //         004b78bd     MOV        EAX,EBX
    //                               LAB_004b78bf                                                 XREF[1]:     004b78b7(j)  
    //         004b78bf     MOV        this,dword ptr [ESP + 0x10]
    //                              scr_trb.cpp:93 (15)
    //         004b78c3     CMP        EAX,EBX
    //         004b78c5     MOV        byte ptr [ESP + 0x6c],0x0
    //         004b78ca     MOV        dword ptr [this->_padding_],EAX
    //         004b78cc     JZ         LAB_004b7c85
    //                              scr_trb.cpp:102 (209)
    //         004b78d2     MOV        EDI,dword ptr [EBP + 0x18]
    //         004b78d5     MOV        EDX,dword ptr [ESP + 0x20]
    //         004b78d9     PUSH       EBX
    //         004b78da     PUSH       offset DAT_fffffff8
    //         004b78dc     LEA        EAX,[EDI + EDI*0x4]
    //         004b78df     PUSH       EDX=>DAT_fffffff4
    //         004b78e0     MOV        ESI,dword ptr [EBP + 0x14]
    //         004b78e3     PUSH       offset DAT_fffffff0
    //         004b78e5     LEA        EAX,[EDI + EAX*0x2]
    //         004b78e8     LEA        this,[EAX + EAX*0x4]
    //         004b78eb     MOV        EAX,0x88888889
    //         004b78f0     SHL        this,0x1
    //         004b78f2     IMUL       this
    //         004b78f4     ADD        EDX,this
    //         004b78f6     MOV        EAX,0x66666667
    //         004b78fb     SAR        EDX,0x8
    //         004b78fe     MOV        this,EDX
    //         004b7900     SHR        this,0x1f
    //         004b7903     ADD        EDX,this
    //         004b7905     MOV        this,ESI
    //         004b7907     IMUL       this,this,0xc8
    //         004b790d     PUSH       EDX
    //         004b790e     IMUL       this
    //         004b7910     SAR        EDX,0x8
    //         004b7913     MOV        EAX,EDX
    //         004b7915     SHR        EAX,0x1f
    //         004b7918     ADD        EDX,EAX
    //         004b791a     MOV        EAX,dword ptr [ESP + 0x28]
    //         004b791e     IMUL       EAX,EDI
    //         004b7921     IMUL       EDI,EDI,0x32
    //         004b7924     LEA        this,[EAX + EAX*0x2]
    //         004b7927     PUSH       EDX
    //         004b7928     SHL        this,0x3
    //         004b792b     SUB        this,EAX
    //         004b792d     MOV        EAX,0x88888889
    //         004b7932     LEA        EBX,[ECX + ECX*0x4]
    //         004b7935     IMUL       EBX
    //         004b7937     MOV        this,EDX
    //         004b7939     MOV        EAX,0x88888889
    //         004b793e     ADD        this,EBX
    //         004b7940     SAR        this,0x8
    //         004b7943     MOV        EDX,this
    //         004b7945     SHR        EDX,0x1f
    //         004b7948     ADD        this,EDX
    //         004b794a     IMUL       EDI
    //         004b794c     ADD        EDX,EDI
    //         004b794e     SAR        EDX,0x8
    //         004b7951     MOV        EAX,EDX
    //         004b7953     ADD        EDX,this
    //         004b7955     MOV        this,dword ptr [ESP + 0x34]
    //         004b7959     IMUL       this,ESI
    //         004b795c     SHR        EAX,0x1f
    //         004b795f     ADD        EAX,EDX
    //         004b7961     PUSH       EAX
    //         004b7962     MOV        EAX,0x66666667
    //         004b7967     IMUL       this
    //         004b7969     MOV        this,EDX
    //         004b796b     MOV        EAX,0x66666667
    //         004b7970     SAR        this,0x8
    //         004b7973     MOV        EDX,this
    //         004b7975     SHR        EDX,0x1f
    //         004b7978     ADD        this,EDX
    //         004b797a     LEA        EDX,[ESI + ESI*0x4]
    //         004b797d     SHL        EDX,0x2
    //         004b7980     IMUL       EDX
    //         004b7982     SAR        EDX,0x8
    //         004b7985     MOV        EAX,EDX
    //         004b7987     ADD        EDX,this
    //         004b7989     MOV        this,dword ptr [EBP + 0x478]
    //         004b798f     SHR        EAX,0x1f
    //         004b7992     ADD        EAX,EDX
    //         004b7994     MOV        EDX,dword ptr [EBP + 0x20]
    //         004b7997     PUSH       EAX
    //         004b7998     PUSH       this
    //         004b7999     MOV        this,dword ptr [ESP + 0x3c]
    //         004b799d     PUSH       EDX
    //         004b799e     CALL       TButtonPanel::setup                              long setup(TButtonPanel * this, TDrawArea * p
    //                              scr_trb.cpp:104 (43)
    //         004b79a3     MOV        EAX,dword ptr [ESP + 0x28]
    //         004b79a7     PUSH       -0x1
    //         004b79a9     PUSH       offset DAT_fffffff8
    //         004b79ab     MOV        this,dword ptr [EAX + 0x8]
    //         004b79ae     MOV        EDX,dword ptr [EAX + 0x4]
    //         004b79b1     MOV        EAX,dword ptr [EAX]
    //         004b79b3     MOV        ESI,dword ptr [ESP + 0x2c]
    //         004b79b7     PUSH       this=>DAT_fffffff4
    //         004b79b8     PUSH       EDX=>DAT_fffffff0
    //         004b79b9     PUSH       EAX
    //         004b79ba     PUSH       ESI
    //         004b79bb     MOV        this,EBP
    //         004b79bd     CALL       TribeSelectTribeScreen::tribeName                char * tribeName(TribeSelectTribeScreen * thi
    //         004b79c2     MOV        this,dword ptr [ESP + 0x24]
    //         004b79c6     PUSH       EAX
    //         004b79c7     MOV        this,dword ptr [this->_padding_]
    //         004b79c9     CALL       TButtonPanel::set_text_info                      void set_text_info(TButtonPanel * this, char 
    //                              scr_trb.cpp:106 (10)
    //         004b79ce     CMP        ESI,0x2
    //         004b79d1     JZ         LAB_004b79d8
    //         004b79d3     CMP        ESI,0x5
    //         004b79d6     JNZ        LAB_004b79ed
    //                               LAB_004b79d8                                                 XREF[1]:     004b79d1(j)  
    //                              scr_trb.cpp:107 (4)
    //         004b79d8     MOV        EAX,dword ptr [ESP + 0x1c]
    //                              scr_trb.cpp:108 (51)
    //         004b79dc     MOV        dword ptr [ESP + 0x14],0xffffffff
    //         004b79e4     ADD        EAX,0xc8
    //         004b79e9     MOV        dword ptr [ESP + 0x1c],EAX
    //                               LAB_004b79ed                                                 XREF[1]:     004b79d6(j)  
    //         004b79ed     MOV        EDX,dword ptr [ESP + 0x10]
    //         004b79f1     MOV        this,dword ptr [ESP + 0x14]
    //         004b79f5     INC        ESI
    //         004b79f6     ADD        EDX,0x4
    //         004b79f9     INC        this
    //         004b79fa     CMP        ESI,0x9
    //         004b79fd     MOV        dword ptr [ESP + 0x24],ESI
    //         004b7a01     MOV        dword ptr [ESP + 0x10],EDX
    //         004b7a05     MOV        dword ptr [ESP + 0x14],this
    //         004b7a09     JL         LAB_004b7890
    //                              scr_trb.cpp:112 (13)
    //         004b7a0f     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004b7a15     PUSH       0xb
    //         004b7a17     CALL       RGE_Base_Game::get_font                          RGE_Font * get_font(RGE_Base_Game * this, int
    //                              scr_trb.cpp:113 (53)
    //         004b7a1c     PUSH       0x188
    //         004b7a21     MOV        ESI,EAX
    //         004b7a23     CALL       operator_new                                     void * operator_new(uint param_1)
    //         004b7a28     ADD        ESP,0x4
    //         004b7a2b     MOV        dword ptr [ESP + 0x28],EAX
    //         004b7a2f     TEST       EAX,EAX
    //         004b7a31     MOV        byte ptr [ESP + 0x6c],0x4
    //         004b7a36     JZ         LAB_004b7a45
    //         004b7a38     MOV        this,EAX
    //         004b7a3a     CALL       TTextPanel::TTextPanel                           undefined TTextPanel(TTextPanel * this)
    //         004b7a3f     MOV        dword ptr [ESP + 0x1c],EAX
    //         004b7a43     JMP        LAB_004b7a51
    //                               LAB_004b7a45                                                 XREF[1]:     004b7a36(j)  
    //         004b7a45     MOV        dword ptr [ESP + 0x1c],0x0
    //         004b7a4d     MOV        EAX,dword ptr [ESP + 0x1c]
    //                               LAB_004b7a51                                                 XREF[1]:     004b7a43(j)  
    //                              scr_trb.cpp:114 (15)
    //         004b7a51     TEST       EAX,EAX
    //         004b7a53     MOV        byte ptr [ESP + 0x6c],0x0
    //         004b7a58     MOV        dword ptr [EBP + 0x480],EAX
    //         004b7a5e     JNZ        LAB_004b7a7f
    //                              scr_trb.cpp:115 (10)
    //         004b7a60     MOV        dword ptr [EBP + 0xd8],0x1
    //                              scr_trb.cpp:157 (21)
    //         004b7a6a     MOV        EAX,EBP
    //         004b7a6c     MOV        this,dword ptr [ESP + 0x64]
    //         004b7a70     MOV        dword ptr FS:[0x0],this
    //         004b7a77     POP        EDI
    //         004b7a78     POP        ESI
    //         004b7a79     POP        EBP
    //         004b7a7a     POP        EBX
    //         004b7a7b     ADD        ESP,0x60
    //         004b7a7e     RET
    //                               LAB_004b7a7f                                                 XREF[1]:     004b7a5e(j)  
    //                              scr_trb.cpp:122 (160)
    //         004b7a7f     MOV        EDX,dword ptr [ESI + 0x8]
    //         004b7a82     MOV        EDI,dword ptr [EBP + 0x18]
    //         004b7a85     MOV        EAX,dword ptr [ESI + 0x4]
    //         004b7a88     PUSH       s_                                               = ""
    //         004b7a8d     PUSH       0x0=>DAT_fffffff8
    //         004b7a8f     MOV        this,dword ptr [ESI]
    //         004b7a91     PUSH       0x0=>DAT_fffffff4
    //         004b7a93     PUSH       0x0=>DAT_fffffff0
    //         004b7a95     PUSH       0x0
    //         004b7a97     PUSH       0x0
    //         004b7a99     PUSH       0x0
    //         004b7a9b     PUSH       EDX
    //         004b7a9c     PUSH       EAX
    //         004b7a9d     LEA        EAX,[EDI + EDI*0x2]
    //         004b7aa0     PUSH       this
    //         004b7aa1     MOV        EBX,dword ptr [EBP + 0x14]
    //         004b7aa4     LEA        this,[EAX + EAX*0x4]
    //         004b7aa7     MOV        EAX,0x88888889
    //         004b7aac     SHL        this,0x2
    //         004b7aaf     IMUL       EDI,EDI,0x190
    //         004b7ab5     IMUL       this
    //         004b7ab7     ADD        EDX,this
    //         004b7ab9     SAR        EDX,0x8
    //         004b7abc     MOV        EAX,EDX
    //         004b7abe     SHR        EAX,0x1f
    //         004b7ac1     ADD        EDX,EAX
    //         004b7ac3     MOV        EAX,0x66666667
    //         004b7ac8     PUSH       EDX
    //         004b7ac9     MOV        EDX,EBX
    //         004b7acb     SHL        EDX,0x8
    //         004b7ace     SUB        EDX,EBX
    //         004b7ad0     LEA        EBX,[EBX + EBX*0x4]
    //         004b7ad3     SHL        EDX,0x1
    //         004b7ad5     IMUL       EDX
    //         004b7ad7     SAR        EDX,0x8
    //         004b7ada     MOV        this,EDX
    //         004b7adc     MOV        EAX,0x88888889
    //         004b7ae1     SHR        this,0x1f
    //         004b7ae4     ADD        EDX,this
    //         004b7ae6     PUSH       EDX
    //         004b7ae7     IMUL       EDI
    //         004b7ae9     ADD        EDX,EDI
    //         004b7aeb     SAR        EDX,0x8
    //         004b7aee     MOV        EAX,EDX
    //         004b7af0     SHR        EAX,0x1f
    //         004b7af3     ADD        EDX,EAX
    //         004b7af5     MOV        EAX,0x66666667
    //         004b7afa     SHL        EBX,0x2
    //         004b7afd     PUSH       EDX
    //         004b7afe     IMUL       EBX
    //         004b7b00     SAR        EDX,0x8
    //         004b7b03     MOV        this,EDX
    //         004b7b05     MOV        EAX,dword ptr [EBP + 0x20]
    //         004b7b08     SHR        this,0x1f
    //         004b7b0b     ADD        EDX,this
    //         004b7b0d     MOV        this,dword ptr [ESP + 0x50]
    //         004b7b11     PUSH       EDX
    //         004b7b12     MOV        EDX,dword ptr [EBP + 0x478]
    //         004b7b18     PUSH       EDX
    //         004b7b19     PUSH       EAX
    //         004b7b1a     CALL       TTextPanel::setup                                long setup(TTextPanel * this, TDrawArea * par
    //                              scr_trb.cpp:124 (15)
    //         004b7b1f     MOV        this,dword ptr [EBP + 0x480]
    //         004b7b25     PUSH       0x6
    //         004b7b27     PUSH       offset DAT_fffffff8
    //         004b7b29     CALL       TTextPanel::set_alignment                        void set_alignment(TTextPanel * this, Alignme
    //                              scr_trb.cpp:126 (51)
    //         004b7b2e     PUSH       0x2b8
    //         004b7b33     CALL       operator_new                                     void * operator_new(uint param_1)
    //         004b7b38     ADD        ESP,0x4
    //         004b7b3b     MOV        dword ptr [ESP + 0x28],EAX
    //         004b7b3f     TEST       EAX,EAX
    //         004b7b41     MOV        byte ptr [ESP + 0x6c],0x5
    //         004b7b46     JZ         LAB_004b7b55
    //         004b7b48     MOV        this,EAX
    //         004b7b4a     CALL       TButtonPanel::TButtonPanel                       undefined TButtonPanel(TButtonPanel * this)
    //         004b7b4f     MOV        dword ptr [ESP + 0x1c],EAX
    //         004b7b53     JMP        LAB_004b7b61
    //                               LAB_004b7b55                                                 XREF[1]:     004b7b46(j)  
    //         004b7b55     MOV        dword ptr [ESP + 0x1c],0x0
    //         004b7b5d     MOV        EAX,dword ptr [ESP + 0x1c]
    //                               LAB_004b7b61                                                 XREF[1]:     004b7b53(j)  
    //                              scr_trb.cpp:127 (15)
    //         004b7b61     TEST       EAX,EAX
    //         004b7b63     MOV        byte ptr [ESP + 0x6c],0x0
    //         004b7b68     MOV        dword ptr [EBP + 0x4a8],EAX
    //         004b7b6e     JNZ        LAB_004b7b8f
    //                              scr_trb.cpp:128 (10)
    //         004b7b70     MOV        dword ptr [EBP + 0xd8],0x1
    //                              scr_trb.cpp:157 (21)
    //         004b7b7a     MOV        EAX,EBP
    //         004b7b7c     MOV        this,dword ptr [ESP + 0x64]
    //         004b7b80     MOV        dword ptr FS:[0x0],this
    //         004b7b87     POP        EDI
    //         004b7b88     POP        ESI
    //         004b7b89     POP        EBP
    //         004b7b8a     POP        EBX
    //         004b7b8b     ADD        ESP,0x60
    //         004b7b8e     RET
    //                               LAB_004b7b8f                                                 XREF[1]:     004b7b6e(j)  
    //                              scr_trb.cpp:133 (149)
    //         004b7b8f     MOV        EDI,dword ptr [EBP + 0x18]
    //         004b7b92     MOV        EDX,dword ptr [ESP + 0x20]
    //         004b7b96     PUSH       0x0
    //         004b7b98     PUSH       offset DAT_fffffff8
    //         004b7b9a     LEA        EBX,[EDI + EDI*0x2]
    //         004b7b9d     MOV        EAX,0x88888889
    //         004b7ba2     PUSH       EDX=>DAT_fffffff4
    //         004b7ba3     MOV        this,dword ptr [EBP + 0x14]
    //         004b7ba6     LEA        EBX,[EBX + EBX*0x4]
    //         004b7ba9     PUSH       offset DAT_fffffff0
    //         004b7bab     SHL        EBX,0x1
    //         004b7bad     IMUL       EDI,EDI,0x190
    //         004b7bb3     IMUL       EBX
    //         004b7bb5     ADD        EDX,EBX
    //         004b7bb7     SAR        EDX,0x8
    //         004b7bba     MOV        EAX,EDX
    //         004b7bbc     SHR        EAX,0x1f
    //         004b7bbf     ADD        EDX,EAX
    //         004b7bc1     LEA        EAX,[ECX + ECX*0x2]
    //         004b7bc4     PUSH       EDX
    //         004b7bc5     LEA        EDX,[EAX + EAX*0x4]
    //         004b7bc8     MOV        EAX,0x66666667
    //         004b7bcd     SHL        EDX,0x3
    //         004b7bd0     IMUL       EDX
    //         004b7bd2     SAR        EDX,0x8
    //         004b7bd5     MOV        EAX,EDX
    //         004b7bd7     SHR        EAX,0x1f
    //         004b7bda     ADD        EDX,EAX
    //         004b7bdc     MOV        EAX,0x88888889
    //         004b7be1     PUSH       EDX
    //         004b7be2     IMUL       EDI
    //         004b7be4     ADD        EDX,EDI
    //         004b7be6     SAR        EDX,0x8
    //         004b7be9     MOV        EAX,EDX
    //         004b7beb     SHR        EAX,0x1f
    //         004b7bee     ADD        EDX,EAX
    //         004b7bf0     MOV        EAX,0x66666667
    //         004b7bf5     PUSH       EDX
    //         004b7bf6     MOV        EDX,this
    //         004b7bf8     SHL        EDX,0x5
    //         004b7bfb     SUB        EDX,this
    //         004b7bfd     LEA        this,[this->_padding_ + EDX*0x4]
    //         004b7c00     SHL        this,0x2
    //         004b7c03     IMUL       this
    //         004b7c05     SAR        EDX,0x8
    //         004b7c08     MOV        this,dword ptr [EBP + 0x478]
    //         004b7c0e     MOV        EAX,EDX
    //         004b7c10     SHR        EAX,0x1f
    //         004b7c13     ADD        EDX,EAX
    //         004b7c15     PUSH       EDX
    //         004b7c16     MOV        EDX,dword ptr [EBP + 0x20]
    //         004b7c19     PUSH       this
    //         004b7c1a     MOV        this,dword ptr [ESP + 0x40]
    //         004b7c1e     PUSH       EDX
    //         004b7c1f     CALL       TButtonPanel::setup                              long setup(TButtonPanel * this, TDrawArea * p
    //                              scr_trb.cpp:135 (31)
    //         004b7c24     MOV        EAX,dword ptr [ESI + 0x8]
    //         004b7c27     MOV        this,dword ptr [ESI + 0x4]
    //         004b7c2a     MOV        EDX,dword ptr [ESI]
    //         004b7c2c     PUSH       -0x1
    //         004b7c2e     PUSH       offset DAT_fffffff8
    //         004b7c30     PUSH       EAX=>DAT_fffffff4
    //         004b7c31     PUSH       this=>DAT_fffffff0
    //         004b7c32     MOV        this,dword ptr [EBP + 0x4a8]
    //         004b7c38     PUSH       EDX
    //         004b7c39     PUSH       s_Previous_Screen                                = "Previous Screen"
    //         004b7c3e     CALL       TButtonPanel::set_text_info                      void set_text_info(TButtonPanel * this, char 
    //                              scr_trb.cpp:137 (51)
    //         004b7c43     PUSH       0x2b8
    //         004b7c48     CALL       operator_new                                     void * operator_new(uint param_1)
    //         004b7c4d     ADD        ESP,0x4
    //         004b7c50     MOV        dword ptr [ESP + 0x28],EAX
    //         004b7c54     TEST       EAX,EAX
    //         004b7c56     MOV        byte ptr [ESP + 0x6c],0x6
    //         004b7c5b     JZ         LAB_004b7c6a
    //         004b7c5d     MOV        this,EAX
    //         004b7c5f     CALL       TButtonPanel::TButtonPanel                       undefined TButtonPanel(TButtonPanel * this)
    //         004b7c64     MOV        dword ptr [ESP + 0x1c],EAX
    //         004b7c68     JMP        LAB_004b7c76
    //                               LAB_004b7c6a                                                 XREF[1]:     004b7c5b(j)  
    //         004b7c6a     MOV        dword ptr [ESP + 0x1c],0x0
    //         004b7c72     MOV        EAX,dword ptr [ESP + 0x1c]
    //                               LAB_004b7c76                                                 XREF[1]:     004b7c68(j)  
    //                              scr_trb.cpp:138 (15)
    //         004b7c76     TEST       EAX,EAX
    //         004b7c78     MOV        byte ptr [ESP + 0x6c],0x0
    //         004b7c7d     MOV        dword ptr [EBP + 0x4ac],EAX
    //         004b7c83     JNZ        LAB_004b7ca4
    //                               LAB_004b7c85                                                 XREF[1]:     004b78cc(j)  
    //                              scr_trb.cpp:139 (10)
    //         004b7c85     MOV        dword ptr [EBP + 0xd8],0x1
    //                              scr_trb.cpp:157 (21)
    //         004b7c8f     MOV        EAX,EBP
    //         004b7c91     MOV        this,dword ptr [ESP + 0x64]
    //         004b7c95     MOV        dword ptr FS:[0x0],this
    //         004b7c9c     POP        EDI
    //         004b7c9d     POP        ESI
    //         004b7c9e     POP        EBP
    //         004b7c9f     POP        EBX
    //         004b7ca0     ADD        ESP,0x60
    //         004b7ca3     RET
    //                               LAB_004b7ca4                                                 XREF[1]:     004b7c83(j)  
    //                              scr_trb.cpp:144 (155)
    //         004b7ca4     MOV        EDI,dword ptr [EBP + 0x18]
    //         004b7ca7     MOV        EAX,dword ptr [ESP + 0x20]
    //         004b7cab     PUSH       0x0
    //         004b7cad     PUSH       offset DAT_fffffff8
    //         004b7caf     LEA        EBX,[EDI + EDI*0x2]
    //         004b7cb2     PUSH       EAX=>DAT_fffffff4
    //         004b7cb3     MOV        EAX,0x88888889
    //         004b7cb8     MOV        this,dword ptr [EBP + 0x14]
    //         004b7cbb     LEA        EBX,[EBX + EBX*0x4]
    //         004b7cbe     PUSH       offset DAT_fffffff0
    //         004b7cc0     SHL        EBX,0x1
    //         004b7cc2     IMUL       EBX
    //         004b7cc4     ADD        EDX,EBX
    //         004b7cc6     SAR        EDX,0x8
    //         004b7cc9     MOV        EAX,EDX
    //         004b7ccb     SHR        EAX,0x1f
    //         004b7cce     ADD        EDX,EAX
    //         004b7cd0     LEA        EAX,[ECX + ECX*0x2]
    //         004b7cd3     PUSH       EDX
    //         004b7cd4     LEA        EDX,[EAX + EAX*0x4]
    //         004b7cd7     MOV        EAX,0x66666667
    //         004b7cdc     SHL        EDX,0x3
    //         004b7cdf     IMUL       EDX
    //         004b7ce1     SAR        EDX,0x8
    //         004b7ce4     MOV        EAX,EDX
    //         004b7ce6     SHR        EAX,0x1f
    //         004b7ce9     ADD        EDX,EAX
    //         004b7ceb     MOV        EAX,0x88888889
    //         004b7cf0     PUSH       EDX
    //         004b7cf1     LEA        EDX,[EDI + EDI*0x4]
    //         004b7cf4     LEA        EDI,[EDI + EDX*0x2]
    //         004b7cf7     LEA        EDI,[EDI + EDI*0x4]
    //         004b7cfa     SHL        EDI,0x3
    //         004b7cfd     IMUL       EDI
    //         004b7cff     ADD        EDX,EDI
    //         004b7d01     SAR        EDX,0x8
    //         004b7d04     MOV        EAX,EDX
    //         004b7d06     SHR        EAX,0x1f
    //         004b7d09     ADD        EDX,EAX
    //         004b7d0b     MOV        EAX,0x66666667
    //         004b7d10     PUSH       EDX
    //         004b7d11     MOV        EDX,this
    //         004b7d13     SHL        EDX,0x5
    //         004b7d16     SUB        EDX,this
    //         004b7d18     LEA        this,[this->_padding_ + EDX*0x4]
    //         004b7d1b     SHL        this,0x2
    //         004b7d1e     IMUL       this
    //         004b7d20     SAR        EDX,0x8
    //         004b7d23     MOV        this,dword ptr [EBP + 0x478]
    //         004b7d29     MOV        EAX,EDX
    //         004b7d2b     SHR        EAX,0x1f
    //         004b7d2e     ADD        EDX,EAX
    //         004b7d30     PUSH       EDX
    //         004b7d31     MOV        EDX,dword ptr [EBP + 0x20]
    //         004b7d34     PUSH       this
    //         004b7d35     MOV        this,dword ptr [ESP + 0x40]
    //         004b7d39     PUSH       EDX
    //         004b7d3a     CALL       TButtonPanel::setup                              long setup(TButtonPanel * this, TDrawArea * p
    //                              scr_trb.cpp:146 (31)
    //         004b7d3f     MOV        EAX,dword ptr [ESI + 0x8]
    //         004b7d42     MOV        this,dword ptr [ESI + 0x4]
    //         004b7d45     MOV        EDX,dword ptr [ESI]
    //         004b7d47     PUSH       -0x1
    //         004b7d49     PUSH       offset DAT_fffffff8
    //         004b7d4b     PUSH       EAX=>DAT_fffffff4
    //         004b7d4c     PUSH       this=>DAT_fffffff0
    //         004b7d4d     MOV        this,dword ptr [EBP + 0x4ac]
    //         004b7d53     PUSH       EDX
    //         004b7d54     PUSH       s_Cancel                                         = "Cancel"
    //         004b7d59     CALL       TButtonPanel::set_text_info                      void set_text_info(TButtonPanel * this, char 
    //                              scr_trb.cpp:148 (14)
    //         004b7d5e     MOV        EAX,dword ptr [EBP + 0x478]
    //         004b7d64     MOV        this,EBP
    //         004b7d66     PUSH       EAX
    //         004b7d67     CALL       TPanel::set_curr_child                           void set_curr_child(TPanel * this, TPanel * p
    //                              scr_trb.cpp:149 (24)
    //         004b7d6c     MOV        this,dword ptr [EBP + 0x484]
    //         004b7d72     LEA        ESI,[EBP + 0x484]
    //         004b7d78     PUSH       this
    //         004b7d79     MOV        this,dword ptr [EBP + 0x478]
    //         004b7d7f     CALL       TPanel::set_curr_child                           void set_curr_child(TPanel * this, TPanel * p
    //                              scr_trb.cpp:150 (9)
    //         004b7d84     PUSH       0x0
    //         004b7d86     MOV        this,EBP
    //         004b7d88     CALL       TribeSelectTribeScreen::fillTribeText            void fillTribeText(TribeSelectTribeScreen * t
    //                              scr_trb.cpp:155 (15)
    //         004b7d8d     MOV        EDX,dword ptr [EBP + 0x4a8]
    //         004b7d93     MOV        this,0x9
    //         004b7d98     LEA        EDI,[ESP + 0x3c]
    //                              scr_trb.cpp:156 (20)
    //         004b7d9c     LEA        EAX,[ESP + 0x3c]
    //         004b7da0     MOVSD.REP  ES:EDI,ESI
    //         004b7da2     PUSH       0xa
    //         004b7da4     PUSH       EAX=>DAT_fffffff8
    //         004b7da5     MOV        this,EBP
    //         004b7da7     MOV        dword ptr [ESP + 0x68],EDX
    //         004b7dab     CALL       TPanel::set_tab_order                            void set_tab_order(TPanel * this, TPanel * * 
    //                              scr_trb.cpp:157 (21)
    //         004b7db0     MOV        this,dword ptr [ESP + 0x64]
    //         004b7db4     POP        EDI
    //         004b7db5     MOV        EAX,EBP
    //         004b7db7     POP        ESI
    //         004b7db8     POP        EBP
    //         004b7db9     MOV        dword ptr FS:[0x0],this
    //         004b7dc0     POP        EBX
    //         004b7dc1     ADD        ESP,0x60
    //         004b7dc4     RET
    //         004b7dc5     ??         90h
    //         004b7dc6     NOP
    //         004b7dc7     NOP
    //         004b7dc8     NOP
    //         004b7dc9     NOP
    //         004b7dca     NOP
    //         004b7dcb     NOP
    //         004b7dcc     NOP
    //         004b7dcd     NOP
    //         004b7dce     NOP
    //         004b7dcf     NOP
}

TribeSelectTribeScreen::~TribeSelectTribeScreen() {
    /* TODO: Stub */
    //                              void __thiscall ~TribeSelectTribeScreen(TribeSelectTribeScreen * this)
    //              void              <VOID>         <RETURN>
    //              TribeSelectTri    ECX:4 (auto)   this
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     004b7e1b(W)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     004b7e0b(W)  
    //                               ??1TribeSelectTribeScreen@@UAE@XZ                            XREF[1]:     `scalar_deleting_destructor':004b7
    //                               TribeSelectTribeScreen::~TribeSelectTribeScreen
    //                              scr_trb.cpp:162 (37)
    //         004b7df0     PUSH       -0x1
    //         004b7df2     PUSH       FUN_0055f838
    //         004b7df7     MOV        EAX,FS:[0x0]
    //         004b7dfd     PUSH       EAX
    //         004b7dfe     MOV        dword ptr FS:[0x0],ESP
    //         004b7e05     PUSH       this
    //         004b7e06     PUSH       EBX
    //         004b7e07     PUSH       ESI
    //         004b7e08     PUSH       EDI
    //         004b7e09     MOV        EDI,this
    //         004b7e0b     MOV        dword ptr [ESP + local_10],EDI
    //         004b7e0f     MOV        dword ptr [EDI],TribeSelectTribeScreen::`vftab   = 004b7dd0
    //                              scr_trb.cpp:163 (24)
    //         004b7e15     MOV        this,dword ptr [EDI + 0x47c]
    //         004b7e1b     MOV        dword ptr [ESP + local_4],0x0
    //         004b7e23     TEST       this,this
    //         004b7e25     JZ         LAB_004b7e2d
    //         004b7e27     MOV        EAX,dword ptr [this->_padding_]
    //         004b7e29     PUSH       0x1
    //         004b7e2b     CALL       dword ptr [EAX]
    //                               LAB_004b7e2d                                                 XREF[1]:     004b7e25(j)  
    //                              scr_trb.cpp:164 (16)
    //         004b7e2d     MOV        this,dword ptr [EDI + 0x480]
    //         004b7e33     TEST       this,this
    //         004b7e35     JZ         LAB_004b7e3d
    //         004b7e37     MOV        EDX,dword ptr [this->_padding_]
    //         004b7e39     PUSH       0x1
    //         004b7e3b     CALL       dword ptr [EDX]
    //                               LAB_004b7e3d                                                 XREF[1]:     004b7e35(j)  
    //                              scr_trb.cpp:165 (11)
    //         004b7e3d     LEA        ESI,[EDI + 0x484]
    //         004b7e43     MOV        EBX,0x9
    //                               LAB_004b7e48                                                 XREF[1]:     004b7e58(j)  
    //                              scr_trb.cpp:166 (18)
    //         004b7e48     MOV        this,dword ptr [ESI]
    //         004b7e4a     TEST       this,this
    //         004b7e4c     JZ         LAB_004b7e54
    //         004b7e4e     MOV        EAX,dword ptr [this->_padding_]
    //         004b7e50     PUSH       0x1
    //         004b7e52     CALL       dword ptr [EAX]
    //                               LAB_004b7e54                                                 XREF[1]:     004b7e4c(j)  
    //         004b7e54     ADD        ESI,0x4
    //         004b7e57     DEC        EBX
    //         004b7e58     JNZ        LAB_004b7e48
    //                              scr_trb.cpp:167 (16)
    //         004b7e5a     MOV        this,dword ptr [EDI + 0x4a8]
    //         004b7e60     TEST       this,this
    //         004b7e62     JZ         LAB_004b7e6a
    //         004b7e64     MOV        EDX,dword ptr [this->_padding_]
    //         004b7e66     PUSH       0x1
    //         004b7e68     CALL       dword ptr [EDX]
    //                               LAB_004b7e6a                                                 XREF[1]:     004b7e62(j)  
    //                              scr_trb.cpp:168 (16)
    //         004b7e6a     MOV        this,dword ptr [EDI + 0x4ac]
    //         004b7e70     TEST       this,this
    //         004b7e72     JZ         LAB_004b7e7a
    //         004b7e74     MOV        EAX,dword ptr [this->_padding_]
    //         004b7e76     PUSH       0x1
    //         004b7e78     CALL       dword ptr [EAX]
    //                               LAB_004b7e7a                                                 XREF[1]:     004b7e72(j)  
    //                              scr_trb.cpp:169 (12)
    //         004b7e7a     MOV        EAX,dword ptr [EDI + 0x4b4]
    //         004b7e80     XOR        ESI,ESI
    //         004b7e82     TEST       EAX,EAX
    //         004b7e84     JLE        LAB_004b7ea3
    //                               LAB_004b7e86                                                 XREF[1]:     004b7ea1(j)  
    //                              scr_trb.cpp:170 (29)
    //         004b7e86     MOV        this,dword ptr [EDI + 0x4b0]
    //         004b7e8c     MOV        EDX,dword ptr [this->_padding_ + ESI*0x4]
    //         004b7e8f     PUSH       EDX
    //         004b7e90     CALL       free                                             undefined free()
    //         004b7e95     MOV        EAX,dword ptr [EDI + 0x4b4]
    //         004b7e9b     ADD        ESP,0x4
    //         004b7e9e     INC        ESI
    //         004b7e9f     CMP        ESI,EAX
    //         004b7ea1     JL         LAB_004b7e86
    //                               LAB_004b7ea3                                                 XREF[1]:     004b7e84(j)  
    //                              scr_trb.cpp:171 (17)
    //         004b7ea3     MOV        EAX,dword ptr [EDI + 0x4b0]
    //         004b7ea9     PUSH       EAX
    //         004b7eaa     CALL       free                                             undefined free()
    //         004b7eaf     ADD        ESP,0x4
    //         004b7eb2     MOV        this,EDI
    //                              scr_trb.cpp:172 (31)
    //         004b7eb4     MOV        dword ptr [ESP + 0x18],0xffffffff
    //         004b7ebc     CALL       TScreenPanel::~TScreenPanel                      void ~TScreenPanel(TScreenPanel * this)
    //         004b7ec1     MOV        this,dword ptr [ESP + 0x10]
    //         004b7ec5     POP        EDI
    //         004b7ec6     POP        ESI
    //         004b7ec7     MOV        dword ptr FS:[0x0],this
    //         004b7ece     POP        EBX
    //         004b7ecf     ADD        ESP,0x10
    //         004b7ed2     RET
    //         004b7ed3     ??         90h
    //         004b7ed4     NOP
    //         004b7ed5     NOP
    //         004b7ed6     NOP
    //         004b7ed7     NOP
    //         004b7ed8     NOP
    //         004b7ed9     NOP
    //         004b7eda     NOP
    //         004b7edb     NOP
    //         004b7edc     NOP
    //         004b7edd     NOP
    //         004b7ede     NOP
    //         004b7edf     NOP
    //                              * protected: virtual long __thiscall TribeSelectTribeScreen::action(class TPanel *,long,unsigned lon... *
    //                              long __thiscall action(TribeSelectTribeScreen * this, TPanel * param
    //              long              EAX:4          <RETURN>
    //              TribeSelectTri    ECX:4 (auto)   this
    //              TPanel *          Stack[0x4]:4   param_1                   XREF[1]:     004b7ee7(R)  
    //              long              Stack[0x8]:4   param_2                   XREF[2]:     004b7ef8(R), 004b7f3c(R)  
    //              ulong             Stack[0xc]:4   param_3                   XREF[1]:     004b7f1a(R)  
    //              ulong             Stack[0x10]:4  param_4                   XREF[1]:     004b7f16(R)  
    //                               ?action@TribeSelectTribeScreen@@MAEJPAVTPanel@@JKK@Z         XREF[1]:     005742a4(*)  
    //                               TribeSelectTribeScreen::action
    //                              scr_trb.cpp:178 (24)
    //         004b7ee0     MOV        EAX,dword ptr [ECX + this->okButton]
    //         004b7ee6     PUSH       ESI
    //         004b7ee7     MOV        ESI,dword ptr [ESP + param_1]
    //         004b7eeb     CMP        ESI,EAX
    //         004b7eed     PUSH       EDI
    //         004b7eee     JZ         LAB_004b7f3c
    //         004b7ef0     CMP        ESI,dword ptr [ECX + this->cancelButton]
    //         004b7ef6     JZ         LAB_004b7f3c
    //                              scr_trb.cpp:187 (9)
    //         004b7ef8     MOV        EDI,dword ptr [ESP + param_2]
    //         004b7efc     CMP        EDI,0x1
    //         004b7eff     JNZ        LAB_004b7f16
    //                              scr_trb.cpp:188 (2)
    //         004b7f01     XOR        EAX,EAX
    //                              scr_trb.cpp:197 (19)
    //         004b7f03     LEA        EDX,[ECX + this->tribeButton[0]]
    //                               LAB_004b7f09                                                 XREF[1]:     004b7f14(j)  
    //         004b7f09     CMP        ESI,dword ptr [EDX]
    //         004b7f0b     JZ         LAB_004b7f2c
    //         004b7f0d     INC        EAX
    //         004b7f0e     ADD        EDX,0x4
    //         004b7f11     CMP        EAX,0x9
    //         004b7f14     JL         LAB_004b7f09
    //                               LAB_004b7f16                                                 XREF[2]:     004b7eff(j), 004b7f43(j)  
    //                              scr_trb.cpp:196 (17)
    //         004b7f16     MOV        EAX,dword ptr [ESP + param_4]
    //         004b7f1a     MOV        EDX,dword ptr [ESP + param_3]
    //         004b7f1e     PUSH       EAX
    //         004b7f1f     PUSH       EDX
    //         004b7f20     PUSH       EDI
    //         004b7f21     PUSH       ESI
    //         004b7f22     CALL       TEasy_Panel::action                              long action(TEasy_Panel * this, TPanel * para
    //                              scr_trb.cpp:197 (5)
    //         004b7f27     POP        EDI
    //         004b7f28     POP        ESI
    //         004b7f29     RET        0x10
    //                               LAB_004b7f2c                                                 XREF[1]:     004b7f0b(j)  
    //                              scr_trb.cpp:191 (6)
    //         004b7f2c     PUSH       EAX
    //         004b7f2d     CALL       TribeSelectTribeScreen::fillTribeText            void fillTribeText(TribeSelectTribeScreen * t
    //                              scr_trb.cpp:192 (5)
    //         004b7f32     MOV        EAX,0x1
    //                              scr_trb.cpp:197 (5)
    //         004b7f37     POP        EDI
    //         004b7f38     POP        ESI
    //         004b7f39     RET        0x10
    //                               LAB_004b7f3c                                                 XREF[2]:     004b7eee(j), 004b7ef6(j)  
    //                              scr_trb.cpp:180 (9)
    //         004b7f3c     MOV        EDI,dword ptr [ESP + param_2]
    //         004b7f40     CMP        EDI,0x1
    //         004b7f43     JNZ        LAB_004b7f16
    //                              scr_trb.cpp:182 (17)
    //         004b7f45     PUSH       0x0
    //         004b7f47     PUSH       s_MP_Setup_Screen                                = "MP Setup Screen"
    //         004b7f4c     MOV        this,panel_system
    //         004b7f51     CALL       TPanelSystem::setCurrentPanel                    int setCurrentPanel(TPanelSystem * this, char
    //                              scr_trb.cpp:183 (15)
    //         004b7f56     PUSH       s_Select_Tribe_Screen                            = "Select Tribe Screen"
    //         004b7f5b     MOV        this,panel_system
    //         004b7f60     CALL       TPanelSystem::destroyPanel                       int destroyPanel(TPanelSystem * this, char * 
    //                              scr_trb.cpp:184 (2)
    //         004b7f65     MOV        EAX,EDI
    //                              scr_trb.cpp:197 (5)
    //         004b7f67     POP        EDI
    //         004b7f68     POP        ESI
    //         004b7f69     RET        0x10
    //         004b7f6c     ??         90h
    //         004b7f6d     NOP
    //         004b7f6e     NOP
    //         004b7f6f     NOP
}

void TribeSelectTribeScreen::fillTribeText(int param_1) {
    /* TODO: Stub */
    //                              void __thiscall fillTribeText(TribeSelectTribeScreen * this, int par
    //              void              <VOID>         <RETURN>
    //              TribeSelectTri    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     004b7f70(R)  
    //                               ?fillTribeText@TribeSelectTribeScreen@@IAEXH@Z               XREF[2]:     TribeSelectTribeScreen:004b7d88(c)
    //                               TribeSelectTribeScreen::fillTribeText                                     action:004b7f2d(c)  
    //                              scr_trb.cpp:202 (23)
    //         004b7f70     MOV        EAX,dword ptr [ESP + param_1]
    //         004b7f74     PUSH       ESI
    //         004b7f75     CMP        EAX,0x8
    //         004b7f78     MOV        ESI,this
    //         004b7f7a     JA         switchD_004b7f80::default
    //                               switchD_004b7f80::switchD
    //         004b7f80     JMP        dword ptr [EAX*0x4 + switchD_004b7f80::switchd   = 004b7f87
    //                               switchD_004b7f80::caseD_0                                    XREF[2]:     004b7f80(j), 004b8044(*)  
    //                              scr_trb.cpp:205 (13)
    //         004b7f87     MOV        this,dword ptr [ESI + 0x480]
    //         004b7f8d     PUSH       s_Assyrian_information_here.                     = "Assyrian information here."
    //         004b7f92     MOV        EAX,dword ptr [this->_padding_]
    //                              scr_trb.cpp:206 (5)
    //         004b7f94     JMP        LAB_004b8027
    //                               switchD_004b7f80::caseD_1                                    XREF[2]:     004b7f80(j), 004b8048(*)  
    //                              scr_trb.cpp:208 (19)
    //         004b7f99     MOV        this,dword ptr [ESI + 0x480]
    //         004b7f9f     PUSH       s_Babylonian_information_here.                   = "Babylonian information here."
    //         004b7fa4     MOV        EDX,dword ptr [this->_padding_]
    //         004b7fa6     CALL       dword ptr [EDX + 0xe8]
    //                              scr_trb.cpp:209 (2)
    //         004b7fac     JMP        switchD_004b7f80::default
    //                               switchD_004b7f80::caseD_2                                    XREF[2]:     004b7f80(j), 004b804c(*)  
    //                              scr_trb.cpp:211 (13)
    //         004b7fae     MOV        this,dword ptr [ESI + 0x480]
    //         004b7fb4     PUSH       s_Egyptian_information_here.                     = "Egyptian information here."
    //         004b7fb9     MOV        EAX,dword ptr [this->_padding_]
    //                              scr_trb.cpp:212 (2)
    //         004b7fbb     JMP        LAB_004b8027
    //                               switchD_004b7f80::caseD_3                                    XREF[2]:     004b7f80(j), 004b8050(*)  
    //                              scr_trb.cpp:214 (19)
    //         004b7fbd     MOV        this,dword ptr [ESI + 0x480]
    //         004b7fc3     PUSH       s_Greek_information_here.                        = "Greek information here."
    //         004b7fc8     MOV        EDX,dword ptr [this->_padding_]
    //         004b7fca     CALL       dword ptr [EDX + 0xe8]
    //                              scr_trb.cpp:215 (2)
    //         004b7fd0     JMP        switchD_004b7f80::default
    //                               switchD_004b7f80::caseD_4                                    XREF[2]:     004b7f80(j), 004b8054(*)  
    //                              scr_trb.cpp:217 (13)
    //         004b7fd2     MOV        this,dword ptr [ESI + 0x480]
    //         004b7fd8     PUSH       s_Hittite_information_here.                      = "Hittite information here."
    //         004b7fdd     MOV        EAX,dword ptr [this->_padding_]
    //                              scr_trb.cpp:218 (2)
    //         004b7fdf     JMP        LAB_004b8027
    //                               switchD_004b7f80::caseD_5                                    XREF[2]:     004b7f80(j), 004b8058(*)  
    //                              scr_trb.cpp:220 (19)
    //         004b7fe1     MOV        this,dword ptr [ESI + 0x480]
    //         004b7fe7     PUSH       s_Isrealite_information_here.                    = "Isrealite information here."
    //         004b7fec     MOV        EDX,dword ptr [this->_padding_]
    //         004b7fee     CALL       dword ptr [EDX + 0xe8]
    //                              scr_trb.cpp:221 (2)
    //         004b7ff4     JMP        switchD_004b7f80::default
    //                               switchD_004b7f80::caseD_6                                    XREF[2]:     004b7f80(j), 004b805c(*)  
    //                              scr_trb.cpp:223 (13)
    //         004b7ff6     MOV        this,dword ptr [ESI + 0x480]
    //         004b7ffc     PUSH       s_Minoan_information_here.                       = "Minoan information here."
    //         004b8001     MOV        EAX,dword ptr [this->_padding_]
    //                              scr_trb.cpp:224 (2)
    //         004b8003     JMP        LAB_004b8027
    //                               switchD_004b7f80::caseD_7                                    XREF[2]:     004b7f80(j), 004b8060(*)  
    //                              scr_trb.cpp:226 (19)
    //         004b8005     MOV        this,dword ptr [ESI + 0x480]
    //         004b800b     PUSH       s_Phoenician_information_here.                   = "Phoenician information here."
    //         004b8010     MOV        EDX,dword ptr [this->_padding_]
    //         004b8012     CALL       dword ptr [EDX + 0xe8]
    //                              scr_trb.cpp:227 (2)
    //         004b8018     JMP        switchD_004b7f80::default
    //                               switchD_004b7f80::caseD_8                                    XREF[2]:     004b7f80(j), 004b8064(*)  
    //                              scr_trb.cpp:229 (19)
    //         004b801a     MOV        this,dword ptr [ESI + 0x480]
    //         004b8020     PUSH       s_Sumerian_information_here.                     = "Sumerian information here."
    //         004b8025     MOV        EAX,dword ptr [this->_padding_]
    //                               LAB_004b8027                                                 XREF[4]:     004b7f94(j), 004b7fbb(j), 
    //                                                                                                         004b7fdf(j), 004b8003(j)  
    //         004b8027     CALL       dword ptr [EAX + 0xe8]
    //                               switchD_004b7f80::default                                    XREF[5]:     004b7f7a(j), 004b7fac(j), 
    //                                                                                                         004b7fd0(j), 004b7ff4(j), 
    //                                                                                                         004b8018(j)  
    //                              scr_trb.cpp:232 (17)
    //         004b802d     MOV        this,dword ptr [ESI + 0x480]
    //         004b8033     PUSH       0x1
    //         004b8035     PUSH       0x0=>DAT_fffffff8
    //         004b8037     PUSH       offset DAT_fffffff4
    //         004b8039     CALL       TTextPanel::scroll                               void scroll(TTextPanel * this, uchar param_1,
    //                              scr_trb.cpp:233 (42)
    //         004b803e     POP        ESI
    //         004b803f     RET        0x4
    //                              *                                               FUNCTION                                                *
    //                              undefined FUN_004b8042()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_004b8042
    //         004b8042     MOV        EDI,EDI
    //                              Symbol Ref: No symbol: NONAME
    //                               switchD_004b7f80::switchdataD_004b8044                       XREF[1]:     fillTribeText:004b7f80(*)  
    //         004b8044     addr       switchD_004b7f80::caseD_0
    //         004b8048     addr       switchD_004b7f80::caseD_1
    //         004b804c     addr       switchD_004b7f80::caseD_2
    //         004b8050     addr       switchD_004b7f80::caseD_3
    //         004b8054     addr       switchD_004b7f80::caseD_4
    //         004b8058     addr       switchD_004b7f80::caseD_5
    //         004b805c     addr       switchD_004b7f80::caseD_6
    //         004b8060     addr       switchD_004b7f80::caseD_7
    //         004b8064     addr       switchD_004b7f80::caseD_8
    //         004b8068     ??         90h
    //         004b8069     ??         90h
    //         004b806a     ??         90h
    //         004b806b     ??         90h
    //         004b806c     ??         90h
    //         004b806d     ??         90h
    //         004b806e     ??         90h
    //         004b806f     ??         90h
    return;
}

char* TribeSelectTribeScreen::tribeName(int param_1) {
    /* TODO: Stub */
    //                              char * __thiscall tribeName(TribeSelectTribeScreen * this, int param
    //              char *            EAX:4          <RETURN>
    //              TribeSelectTri    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     004b8070(R)  
    //                               ?tribeName@TribeSelectTribeScreen@@IAEPADH@Z                 XREF[1]:     TribeSelectTribeScreen:004b79bd(c)
    //                               TribeSelectTribeScreen::tribeName
    //                              scr_trb.cpp:238 (16)
    //         004b8070     MOV        EAX,dword ptr [ESP + param_1]
    //         004b8074     CMP        EAX,0x8
    //         004b8077     JA         switchD_004b8079::default
    //                               switchD_004b8079::switchD
    //         004b8079     JMP        dword ptr [EAX*0x4 + switchD_004b8079::switchd   = 004b8080
    //                               switchD_004b8079::caseD_0                                    XREF[2]:     004b8079(j), 004b80d0(*)  
    //                              scr_trb.cpp:241 (5)
    //         004b8080     MOV        EAX,s_Assyrian                                   = "Assyrian"
    //                              scr_trb.cpp:261 (3)
    //         004b8085     RET        0x4
    //                               switchD_004b8079::caseD_1                                    XREF[2]:     004b8079(j), 004b80d4(*)  
    //                              scr_trb.cpp:243 (5)
    //         004b8088     MOV        EAX,s_Babylonian                                 = "Babylonian"
    //                              scr_trb.cpp:261 (3)
    //         004b808d     RET        0x4
    //                               switchD_004b8079::caseD_2                                    XREF[2]:     004b8079(j), 004b80d8(*)  
    //                              scr_trb.cpp:245 (5)
    //         004b8090     MOV        EAX,s_Egyptian                                   = "Egyptian"
    //                              scr_trb.cpp:261 (3)
    //         004b8095     RET        0x4
    //                               switchD_004b8079::caseD_3                                    XREF[2]:     004b8079(j), 004b80dc(*)  
    //                              scr_trb.cpp:247 (5)
    //         004b8098     MOV        EAX,s_Greek                                      = "Greek"
    //                              scr_trb.cpp:261 (3)
    //         004b809d     RET        0x4
    //                               switchD_004b8079::caseD_4                                    XREF[2]:     004b8079(j), 004b80e0(*)  
    //                              scr_trb.cpp:249 (5)
    //         004b80a0     MOV        EAX,s_Hittite                                    = "Hittite"
    //                              scr_trb.cpp:261 (3)
    //         004b80a5     RET        0x4
    //                               switchD_004b8079::caseD_5                                    XREF[2]:     004b8079(j), 004b80e4(*)  
    //                              scr_trb.cpp:251 (5)
    //         004b80a8     MOV        EAX,s_Isrealite                                  = "Isrealite"
    //                              scr_trb.cpp:261 (3)
    //         004b80ad     RET        0x4
    //                               switchD_004b8079::caseD_6                                    XREF[2]:     004b8079(j), 004b80e8(*)  
    //                              scr_trb.cpp:253 (5)
    //         004b80b0     MOV        EAX,s_Minoan                                     = "Minoan"
    //                              scr_trb.cpp:261 (3)
    //         004b80b5     RET        0x4
    //                               switchD_004b8079::caseD_7                                    XREF[2]:     004b8079(j), 004b80ec(*)  
    //                              scr_trb.cpp:255 (5)
    //         004b80b8     MOV        EAX,s_Phoenician                                 = "Phoenician"
    //                              scr_trb.cpp:261 (3)
    //         004b80bd     RET        0x4
    //                               switchD_004b8079::caseD_8                                    XREF[2]:     004b8079(j), 004b80f0(*)  
    //                              scr_trb.cpp:257 (5)
    //         004b80c0     MOV        EAX,s_Sumerian                                   = "Sumerian"
    //                              scr_trb.cpp:261 (3)
    //         004b80c5     RET        0x4
    //                               switchD_004b8079::default                                    XREF[1]:     004b8077(j)  
    //                              scr_trb.cpp:259 (5)
    //         004b80c8     MOV        EAX,s_No_Culture                                 = "No Culture"
    //                              scr_trb.cpp:261 (39)
    //         004b80cd     RET        0x4
    //                              Symbol Ref: No symbol: NONAME
    //                               switchD_004b8079::switchdataD_004b80d0                       XREF[1]:     tribeName:004b8079(*)  
    //         004b80d0     addr       switchD_004b8079::caseD_0
    //         004b80d4     addr       switchD_004b8079::caseD_1
    //         004b80d8     addr       switchD_004b8079::caseD_2
    //         004b80dc     addr       switchD_004b8079::caseD_3
    //         004b80e0     addr       switchD_004b8079::caseD_4
    //         004b80e4     addr       switchD_004b8079::caseD_5
    //         004b80e8     addr       switchD_004b8079::caseD_6
    //         004b80ec     addr       switchD_004b8079::caseD_7
    //         004b80f0     addr       switchD_004b8079::caseD_8
    //         004b80f4     ??         90h
    //         004b80f5     ??         90h
    //         004b80f6     ??         90h
    //         004b80f7     ??         90h
    //         004b80f8     ??         90h
    //         004b80f9     ??         90h
    //         004b80fa     ??         90h
    //         004b80fb     ??         90h
    //         004b80fc     ??         90h
    //         004b80fd     ??         90h
    //         004b80fe     ??         90h
    //         004b80ff     ??         90h
    return 0;
}

long TribeSelectTribeScreen::action(TPanel* param_1, long param_2, ulong param_3, ulong param_4) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return 0;
}

