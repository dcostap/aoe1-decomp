#include "common.h"
#include "dlg_conf.h"

TribeConfigDialog::~TribeConfigDialog() {
    /* TODO: Stub */
    //                              void __thiscall ~TribeConfigDialog(TribeConfigDialog * this)
    //              void              <VOID>         <RETURN>
    //              TribeConfigDia    ECX:4 (auto)   this
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     0043c0eb(W), 0043c286(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     0043c293(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     0043c0db(W)  
    //                               ??1TribeConfigDialog@@UAE@XZ                                 XREF[1]:     `scalar_deleting_destructor':0043c
    //                               TribeConfigDialog::~TribeConfigDialog
    //                              dlg_conf.cpp:326 (37)
    //         0043c0c0     PUSH       -0x1
    //         0043c0c2     PUSH       FUN_0055d008
    //         0043c0c7     MOV        EAX,FS:[0x0]
    //         0043c0cd     PUSH       EAX
    //         0043c0ce     MOV        dword ptr FS:[0x0],ESP
    //         0043c0d5     PUSH       this
    //         0043c0d6     PUSH       EBX
    //         0043c0d7     PUSH       ESI
    //         0043c0d8     MOV        ESI,this
    //         0043c0da     PUSH       EDI
    //         0043c0db     MOV        dword ptr [ESP + local_10],ESI
    //         0043c0df     MOV        dword ptr [ESI],TribeConfigDialog::`vftable'     = 0043c0a0
    //                              dlg_conf.cpp:329 (31)
    //         0043c0e5     LEA        EAX,[ESI + 0x494]
    //         0043c0eb     MOV        dword ptr [ESP + local_4],0x0
    //         0043c0f3     PUSH       EAX
    //         0043c0f4     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //         0043c0f9     LEA        EDI,[ESI + 0x498]
    //         0043c0ff     MOV        EBX,0x4
    //                               LAB_0043c104                                                 XREF[1]:     0043c110(j)  
    //                              dlg_conf.cpp:332 (14)
    //         0043c104     PUSH       EDI
    //         0043c105     MOV        this,ESI
    //         0043c107     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //         0043c10c     ADD        EDI,0x4
    //         0043c10f     DEC        EBX
    //         0043c110     JNZ        LAB_0043c104
    //                              dlg_conf.cpp:371 (403)
    //         0043c112     LEA        EDI,[ESI + 0x4a8]
    //         0043c118     MOV        EBX,0x3
    //                               LAB_0043c11d                                                 XREF[1]:     0043c129(j)  
    //         0043c11d     PUSH       EDI
    //         0043c11e     MOV        this,ESI
    //         0043c120     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //         0043c125     ADD        EDI,0x4
    //         0043c128     DEC        EBX
    //         0043c129     JNZ        LAB_0043c11d
    //         0043c12b     LEA        EDI,[ESI + 0x4b4]
    //         0043c131     MOV        EBX,0x3
    //                               LAB_0043c136                                                 XREF[1]:     0043c142(j)  
    //         0043c136     PUSH       EDI
    //         0043c137     MOV        this,ESI
    //         0043c139     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //         0043c13e     ADD        EDI,0x4
    //         0043c141     DEC        EBX
    //         0043c142     JNZ        LAB_0043c136
    //         0043c144     LEA        this,[ESI + 0x4c0]
    //         0043c14a     PUSH       this
    //         0043c14b     MOV        this,ESI
    //         0043c14d     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //         0043c152     LEA        EDI,[ESI + 0x4c4]
    //         0043c158     MOV        EBX,0x3
    //                               LAB_0043c15d                                                 XREF[1]:     0043c169(j)  
    //         0043c15d     PUSH       EDI
    //         0043c15e     MOV        this,ESI
    //         0043c160     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //         0043c165     ADD        EDI,0x4
    //         0043c168     DEC        EBX
    //         0043c169     JNZ        LAB_0043c15d
    //         0043c16b     LEA        EDX,[ESI + 0x4d0]
    //         0043c171     MOV        this,ESI
    //         0043c173     PUSH       EDX
    //         0043c174     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //         0043c179     LEA        EDI,[ESI + 0x4d4]
    //         0043c17f     MOV        EBX,0x3
    //                               LAB_0043c184                                                 XREF[1]:     0043c190(j)  
    //         0043c184     PUSH       EDI
    //         0043c185     MOV        this,ESI
    //         0043c187     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //         0043c18c     ADD        EDI,0x4
    //         0043c18f     DEC        EBX
    //         0043c190     JNZ        LAB_0043c184
    //         0043c192     LEA        EAX,[ESI + 0x4e0]
    //         0043c198     MOV        this,ESI
    //         0043c19a     PUSH       EAX
    //         0043c19b     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //         0043c1a0     LEA        EDI,[ESI + 0x4e4]
    //         0043c1a6     MOV        EBX,0x4
    //                               LAB_0043c1ab                                                 XREF[1]:     0043c1b7(j)  
    //         0043c1ab     PUSH       EDI
    //         0043c1ac     MOV        this,ESI
    //         0043c1ae     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //         0043c1b3     ADD        EDI,0x4
    //         0043c1b6     DEC        EBX
    //         0043c1b7     JNZ        LAB_0043c1ab
    //         0043c1b9     LEA        EDI,[ESI + 0x4f4]
    //         0043c1bf     MOV        EBX,0x3
    //                               LAB_0043c1c4                                                 XREF[1]:     0043c1d0(j)  
    //         0043c1c4     PUSH       EDI
    //         0043c1c5     MOV        this,ESI
    //         0043c1c7     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //         0043c1cc     ADD        EDI,0x4
    //         0043c1cf     DEC        EBX
    //         0043c1d0     JNZ        LAB_0043c1c4
    //         0043c1d2     LEA        EDI,[ESI + 0x500]
    //         0043c1d8     MOV        EBX,0x3
    //                               LAB_0043c1dd                                                 XREF[1]:     0043c1e9(j)  
    //         0043c1dd     PUSH       EDI
    //         0043c1de     MOV        this,ESI
    //         0043c1e0     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //         0043c1e5     ADD        EDI,0x4
    //         0043c1e8     DEC        EBX
    //         0043c1e9     JNZ        LAB_0043c1dd
    //         0043c1eb     LEA        EDI,[ESI + 0x50c]
    //         0043c1f1     MOV        EBX,0x2
    //                               LAB_0043c1f6                                                 XREF[1]:     0043c202(j)  
    //         0043c1f6     PUSH       EDI
    //         0043c1f7     MOV        this,ESI
    //         0043c1f9     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //         0043c1fe     ADD        EDI,0x4
    //         0043c201     DEC        EBX
    //         0043c202     JNZ        LAB_0043c1f6
    //         0043c204     LEA        EDI,[ESI + 0x514]
    //         0043c20a     MOV        EBX,0x3
    //                               LAB_0043c20f                                                 XREF[1]:     0043c21b(j)  
    //         0043c20f     PUSH       EDI
    //         0043c210     MOV        this,ESI
    //         0043c212     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //         0043c217     ADD        EDI,0x4
    //         0043c21a     DEC        EBX
    //         0043c21b     JNZ        LAB_0043c20f
    //         0043c21d     LEA        EDI,[ESI + 0x520]
    //         0043c223     MOV        EBX,0x2
    //                               LAB_0043c228                                                 XREF[1]:     0043c234(j)  
    //         0043c228     PUSH       EDI
    //         0043c229     MOV        this,ESI
    //         0043c22b     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //         0043c230     ADD        EDI,0x4
    //         0043c233     DEC        EBX
    //         0043c234     JNZ        LAB_0043c228
    //         0043c236     LEA        EDI,[ESI + 0x528]
    //         0043c23c     MOV        EBX,0x4
    //                               LAB_0043c241                                                 XREF[1]:     0043c24d(j)  
    //         0043c241     PUSH       EDI
    //         0043c242     MOV        this,ESI
    //         0043c244     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //         0043c249     ADD        EDI,0x4
    //         0043c24c     DEC        EBX
    //         0043c24d     JNZ        LAB_0043c241
    //         0043c24f     LEA        EDI,[ESI + 0x538]
    //         0043c255     MOV        EBX,0x3
    //                               LAB_0043c25a                                                 XREF[1]:     0043c266(j)  
    //         0043c25a     PUSH       EDI
    //         0043c25b     MOV        this,ESI
    //         0043c25d     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //         0043c262     ADD        EDI,0x4
    //         0043c265     DEC        EBX
    //         0043c266     JNZ        LAB_0043c25a
    //         0043c268     LEA        this,[ESI + 0x544]
    //         0043c26e     PUSH       this
    //         0043c26f     MOV        this,ESI
    //         0043c271     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //         0043c276     LEA        EDX,[ESI + 0x548]
    //         0043c27c     MOV        this,ESI
    //         0043c27e     PUSH       EDX
    //         0043c27f     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //         0043c284     MOV        this,ESI
    //         0043c286     MOV        dword ptr [ESP + local_4],0xffffffff
    //         0043c28e     CALL       TDialogPanel::~TDialogPanel                      void ~TDialogPanel(TDialogPanel * this)
    //         0043c293     MOV        this,dword ptr [ESP + local_c]
    //         0043c297     POP        EDI
    //         0043c298     POP        ESI
    //         0043c299     MOV        dword ptr FS:[0x0],this
    //         0043c2a0     POP        EBX
    //         0043c2a1     ADD        ESP,0x10
    //         0043c2a4     RET
    //         0043c2a5     ??         90h
    //         0043c2a6     NOP
    //         0043c2a7     NOP
    //         0043c2a8     NOP
    //         0043c2a9     NOP
    //         0043c2aa     NOP
    //         0043c2ab     NOP
    //         0043c2ac     NOP
    //         0043c2ad     NOP
    //         0043c2ae     NOP
    //         0043c2af     NOP
    //                              * public: virtual long __thiscall TribeConfigDialog::action(class TPanel *,long,unsigned long,unsign... *
    //                              long __thiscall action(TribeConfigDialog * this, TPanel * param_1, l
    //              long              EAX:4          <RETURN>
    //              TribeConfigDia    ECX:4 (auto)   this
    //              TPanel *          Stack[0x4]:4   param_1                   XREF[1]:     0043c2b0(R)  
    //              long              Stack[0x8]:4   param_2                   XREF[1]:     0043c2c6(R)  
    //              ulong             Stack[0xc]:4   param_3                   XREF[3]:     0043c2bd(R), 0043c73e(R), 0043c7a3(R)  
    //              ulong             Stack[0x10]:4  param_4                   XREF[1]:     0043c80d(R)  
    //              char[256]         Stack[-0x104   msg
    //              float             Stack[-0x108   new_speed
    //                               ?action@TribeConfigDialog@@UAEJPAVTPanel@@JKK@Z              XREF[1]:     0056f804(*)  
    //                               TribeConfigDialog::action
    //                              dlg_conf.cpp:377 (37)
    //         0043c2b0     MOV        EAX,dword ptr [ESP + param_1]
    //         0043c2b4     SUB        ESP,0x104
    //         0043c2ba     TEST       EAX,EAX
    //         0043c2bc     PUSH       EBP
    //         0043c2bd     MOV        EBP,dword ptr [ESP + param_3]
    //         0043c2c4     PUSH       ESI
    //         0043c2c5     PUSH       EDI
    //         0043c2c6     MOV        EDI,dword ptr [ESP + param_2]
    //         0043c2cd     MOV        ESI,this
    //         0043c2cf     JZ         LAB_0043c80d
    //                              dlg_conf.cpp:380 (21)
    //         0043c2d5     CMP        EAX,dword ptr [ESI + 0x544]
    //         0043c2db     JNZ        LAB_0043c695
    //         0043c2e1     CMP        EDI,0x1
    //         0043c2e4     JNZ        LAB_0043c695
    //                              dlg_conf.cpp:381 (14)
    //         0043c2ea     MOV        EAX,dword ptr [ESI + 0x490]
    //         0043c2f0     TEST       EAX,EAX
    //         0043c2f2     JNZ        LAB_0043c8fa
    //                              dlg_conf.cpp:383 (33)
    //         0043c2f8     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0043c2fe     CALL       RGE_Base_Game::singlePlayerGame                  int singlePlayerGame(RGE_Base_Game * this)
    //         0043c303     MOV        EBP,EDI
    //         0043c305     CMP        EAX,EBP
    //         0043c307     JNZ        LAB_0043c322
    //         0043c309     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0043c30f     MOV        EAX,dword ptr [this->_padding_ + 0xa00]
    //         0043c315     TEST       EAX,EAX
    //         0043c317     JNZ        LAB_0043c322
    //                              dlg_conf.cpp:384 (9)
    //         0043c319     PUSH       0x0
    //         0043c31b     PUSH       0x0
    //         0043c31d     CALL       RGE_Base_Game::set_paused                        void set_paused(RGE_Base_Game * this, int par
    //                               LAB_0043c322                                                 XREF[2]:     0043c307(j), 0043c317(j)  
    //                              dlg_conf.cpp:387 (13)
    //         0043c322     MOV        this,dword ptr [ESI + 0x50c]
    //         0043c328     CALL       TButtonPanel::get_state                          int get_state(TButtonPanel * this)
    //         0043c32d     TEST       EAX,EAX
    //                              dlg_conf.cpp:388 (19)
    //         0043c32f     MOV        EAX,[rge_base_game]                              = 00000000
    //         0043c334     JZ         LAB_0043c344
    //         0043c336     MOV        EAX,dword ptr [EAX + 0xc]
    //         0043c339     MOV        word ptr [EAX + 0x8dc],0x2
    //                              dlg_conf.cpp:389 (2)
    //         0043c342     JMP        LAB_0043c34e
    //                               LAB_0043c344                                                 XREF[1]:     0043c334(j)  
    //                              dlg_conf.cpp:390 (10)
    //         0043c344     MOV        this,dword ptr [EAX + 0xc]
    //         0043c347     MOV        word ptr [this->_padding_ + 0x8dc],BP
    //                               LAB_0043c34e                                                 XREF[1]:     0043c342(j)  
    //                              dlg_conf.cpp:392 (14)
    //         0043c34e     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0043c354     MOV        EDX,dword ptr [this->_padding_]
    //         0043c356     CALL       dword ptr [EDX + 0x140]
    //                              dlg_conf.cpp:395 (13)
    //         0043c35c     MOV        this,dword ptr [ESI + 0x520]
    //         0043c362     CALL       TButtonPanel::get_state                          int get_state(TButtonPanel * this)
    //         0043c367     TEST       EAX,EAX
    //                              dlg_conf.cpp:396 (13)
    //         0043c369     MOV        EAX,[rge_base_game]                              = 00000000
    //         0043c36e     JZ         LAB_0043c378
    //         0043c370     MOV        dword ptr [EAX + 0xa08],EBP
    //                              dlg_conf.cpp:397 (2)
    //         0043c376     JMP        LAB_0043c382
    //                               LAB_0043c378                                                 XREF[1]:     0043c36e(j)  
    //                              dlg_conf.cpp:398 (10)
    //         0043c378     MOV        dword ptr [EAX + 0xa08],0x0
    //                               LAB_0043c382                                                 XREF[1]:     0043c376(j)  
    //                              dlg_conf.cpp:401 (15)
    //         0043c382     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0043c388     CALL       RGE_Base_Game::singlePlayerGame                  int singlePlayerGame(RGE_Base_Game * this)
    //         0043c38d     TEST       EAX,EAX
    //         0043c38f     JZ         LAB_0043c406
    //                              dlg_conf.cpp:403 (15)
    //         0043c391     MOV        this,dword ptr [ESI + 0x538]
    //         0043c397     CALL       TButtonPanel::get_state                          int get_state(TButtonPanel * this)
    //         0043c39c     TEST       EAX,EAX
    //         0043c39e     JZ         LAB_0043c3b9
    //                              dlg_conf.cpp:405 (13)
    //         0043c3a0     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0043c3a6     PUSH       0x0
    //         0043c3a8     CALL       RGE_Base_Game::setPathFinding                    void setPathFinding(RGE_Base_Game * this, uch
    //                              language.dll match for 0x9c4: "This is not enabled in the tri
    //                              dlg_conf.cpp:406 (10)
    //         0043c3ad     MOV        dword ptr [numberPathingIterations],0x9c4        = 9C4h
    //                              dlg_conf.cpp:408 (17)
    //         0043c3b7     JMP        LAB_0043c406
    //                               LAB_0043c3b9                                                 XREF[1]:     0043c39e(j)  
    //         0043c3b9     MOV        this,dword ptr [ESI + 0x53c]
    //         0043c3bf     CALL       TButtonPanel::get_state                          int get_state(TButtonPanel * this)
    //         0043c3c4     TEST       EAX,EAX
    //         0043c3c6     JZ         LAB_0043c3e0
    //                              dlg_conf.cpp:410 (12)
    //         0043c3c8     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0043c3ce     PUSH       EBP
    //         0043c3cf     CALL       RGE_Base_Game::setPathFinding                    void setPathFinding(RGE_Base_Game * this, uch
    //                              dlg_conf.cpp:411 (10)
    //         0043c3d4     MOV        dword ptr [numberPathingIterations],0x1388       = 9C4h
    //                              dlg_conf.cpp:413 (17)
    //         0043c3de     JMP        LAB_0043c406
    //                               LAB_0043c3e0                                                 XREF[1]:     0043c3c6(j)  
    //         0043c3e0     MOV        this,dword ptr [ESI + 0x540]
    //         0043c3e6     CALL       TButtonPanel::get_state                          int get_state(TButtonPanel * this)
    //         0043c3eb     TEST       EAX,EAX
    //         0043c3ed     JZ         LAB_0043c406
    //                              dlg_conf.cpp:415 (13)
    //         0043c3ef     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0043c3f5     PUSH       0x2
    //         0043c3f7     CALL       RGE_Base_Game::setPathFinding                    void setPathFinding(RGE_Base_Game * this, uch
    //                              dlg_conf.cpp:416 (10)
    //         0043c3fc     MOV        dword ptr [numberPathingIterations],0x1d4c       = 9C4h
    //                               LAB_0043c406                                                 XREF[4]:     0043c38f(j), 0043c3b7(j), 
    //                                                                                                         0043c3de(j), 0043c3ed(j)  
    //                              dlg_conf.cpp:421 (18)
    //         0043c406     MOV        EAX,[rge_base_game]                              = 00000000
    //         0043c40b     CMP        dword ptr [EAX + 0x1b0],0x5
    //         0043c412     JZ         LAB_0043c524
    //                              dlg_conf.cpp:424 (23)
    //         0043c418     MOV        this,dword ptr [ESI + 0x4a8]
    //         0043c41e     MOV        dword ptr [ESP + 0xc],0x0
    //         0043c426     CALL       TButtonPanel::get_state                          int get_state(TButtonPanel * this)
    //         0043c42b     TEST       EAX,EAX
    //         0043c42d     JZ         LAB_0043c439
    //                              dlg_conf.cpp:425 (8)
    //         0043c42f     MOV        dword ptr [ESP + 0xc],0x3f800000
    //                              dlg_conf.cpp:426 (17)
    //         0043c437     JMP        LAB_0043c469
    //                               LAB_0043c439                                                 XREF[1]:     0043c42d(j)  
    //         0043c439     MOV        this,dword ptr [ESI + 0x4ac]
    //         0043c43f     CALL       TButtonPanel::get_state                          int get_state(TButtonPanel * this)
    //         0043c444     TEST       EAX,EAX
    //         0043c446     JZ         LAB_0043c452
    //                              dlg_conf.cpp:427 (8)
    //         0043c448     MOV        dword ptr [ESP + 0xc],0x3fc00000
    //                              dlg_conf.cpp:428 (17)
    //         0043c450     JMP        LAB_0043c469
    //                               LAB_0043c452                                                 XREF[1]:     0043c446(j)  
    //         0043c452     MOV        this,dword ptr [ESI + 0x4b0]
    //         0043c458     CALL       TButtonPanel::get_state                          int get_state(TButtonPanel * this)
    //         0043c45d     TEST       EAX,EAX
    //         0043c45f     JZ         LAB_0043c469
    //                              dlg_conf.cpp:429 (8)
    //         0043c461     MOV        dword ptr [ESP + 0xc],0x40000000
    //                               LAB_0043c469                                                 XREF[3]:     0043c437(j), 0043c450(j), 
    //                                                                                                         0043c45f(j)  
    //                              dlg_conf.cpp:430 (55)
    //         0043c469     MOV        EAX,[allow_user_commands]                        = 1h
    //         0043c46e     TEST       EAX,EAX
    //         0043c470     JZ         LAB_0043c524
    //         0043c476     FLD        float ptr [ESP + 0xc]
    //         0043c47a     FCOMP      float ptr [DAT_0056f74c]
    //         0043c480     FNSTSW     AX
    //         0043c482     TEST       AH,0x40
    //         0043c485     JNZ        LAB_0043c524
    //         0043c48b     FLD        float ptr [ESP + 0xc]
    //         0043c48f     FCOMP      float ptr [ESI + 0x554]
    //         0043c495     FNSTSW     AX
    //         0043c497     TEST       AH,0x40
    //         0043c49a     JNZ        LAB_0043c524
    //                              dlg_conf.cpp:432 (15)
    //         0043c4a0     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0043c4a6     CALL       RGE_Base_Game::multiplayerGame                   int multiplayerGame(RGE_Base_Game * this)
    //         0043c4ab     TEST       EAX,EAX
    //         0043c4ad     JZ         LAB_0043c4f1
    //                              dlg_conf.cpp:435 (47)
    //         0043c4af     MOV        this,dword ptr [comm]                            = 00000000
    //         0043c4b5     CALL       TCommunications_Handler::WhoAmI                  int WhoAmI(TCommunications_Handler * this)
    //         0043c4ba     MOV        this,dword ptr [comm]                            = 00000000
    //         0043c4c0     PUSH       EAX
    //         0043c4c1     CALL       TCommunications_Handler::GetPlayerName           char * GetPlayerName(TCommunications_Handler 
    //         0043c4c6     PUSH       EAX
    //                              language.dll match for 0xbf3: "Game speed changed."
    //         0043c4c7     PUSH       offset DAT_fffffff8
    //         0043c4cc     MOV        this,ESI
    //         0043c4ce     CALL       TPanel::get_string                               char * get_string(TPanel * this, int param_1)
    //         0043c4d3     LEA        this,[ESP + 0x14]
    //         0043c4d7     PUSH       EAX=>DAT_fffffff8
    //         0043c4d8     PUSH       this=>DAT_fffffff4
    //         0043c4d9     CALL       sprintf                                          undefined sprintf()
    //                              dlg_conf.cpp:436 (19)
    //         0043c4de     MOV        this,dword ptr [comm]                            = 00000000
    //         0043c4e4     ADD        ESP,0xc
    //         0043c4e7     LEA        EDX,[ESP + 0x10]
    //         0043c4eb     PUSH       EDX
    //         0043c4ec     CALL       TCommunications_Handler::SendChatMsgAll          void SendChatMsgAll(TCommunications_Handler *
    //                               LAB_0043c4f1                                                 XREF[1]:     0043c4ad(j)  
    //                              dlg_conf.cpp:438 (24)
    //         0043c4f1     MOV        EAX,[rge_base_game]                              = 00000000
    //         0043c4f6     MOV        EDI,dword ptr [ESP + 0xc]
    //         0043c4fa     PUSH       EDI
    //         0043c4fb     MOV        this,dword ptr [EAX + 0x3f4]
    //         0043c501     MOV        this,dword ptr [ECX + this->_padding_]
    //         0043c504     CALL       TRIBE_Command::command_game_speed                void command_game_speed(TRIBE_Command * this,
    //                              dlg_conf.cpp:439 (15)
    //         0043c509     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0043c50f     CALL       RGE_Base_Game::singlePlayerGame                  int singlePlayerGame(RGE_Base_Game * this)
    //         0043c514     TEST       EAX,EAX
    //         0043c516     JZ         LAB_0043c524
    //                              dlg_conf.cpp:440 (12)
    //         0043c518     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0043c51e     PUSH       EDI
    //         0043c51f     CALL       RGE_Base_Game::set_game_speed                    void set_game_speed(RGE_Base_Game * this, flo
    //                               LAB_0043c524                                                 XREF[5]:     0043c412(j), 0043c470(j), 
    //                                                                                                         0043c485(j), 0043c49a(j), 
    //                                                                                                         0043c516(j)  
    //                              dlg_conf.cpp:445 (20)
    //         0043c524     MOV        this,dword ptr [ESI + 0x55c]
    //         0043c52a     MOV        EAX,dword ptr [ESI + 0x54c]
    //         0043c530     CMP        this,EAX
    //         0043c532     JZ         LAB_0043c606
    //                              dlg_conf.cpp:447 (6)
    //         0043c538     MOV        EDX,dword ptr [rge_base_game]                    = 00000000
    //                              dlg_conf.cpp:448 (6)
    //         0043c53e     CMP        this,0x63
    //         0043c541     MOV        EAX,dword ptr [EDX + 0xc]
    //                              dlg_conf.cpp:450 (16)
    //         0043c544     MOV        this,dword ptr [EAX + 0x8a4]
    //         0043c54a     JL         LAB_0043c56b
    //         0043c54c     TEST       this,this
    //         0043c54e     JZ         LAB_0043c5dd
    //                              dlg_conf.cpp:453 (10)
    //         0043c554     MOV        dword ptr [EAX + 0x8a4],0x0
    //                              dlg_conf.cpp:454 (11)
    //         0043c55e     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0043c564     MOV        EAX,dword ptr [this->_padding_]
    //         0043c566     CALL       dword ptr [EAX + 0x5c]
    //                              dlg_conf.cpp:457 (2)
    //         0043c569     JMP        LAB_0043c5dd
    //                               LAB_0043c56b                                                 XREF[1]:     0043c54a(j)  
    //                              dlg_conf.cpp:459 (4)
    //         0043c56b     TEST       this,this
    //         0043c56d     JNZ        LAB_0043c5dd
    //                              dlg_conf.cpp:462 (6)
    //         0043c56f     MOV        dword ptr [EAX + 0x8a4],EBP
    //                              dlg_conf.cpp:463 (33)
    //         0043c575     MOV        EAX,dword ptr [ESI + 0x55c]
    //         0043c57b     LEA        EAX,[EAX + EAX*0x4]
    //         0043c57e     LEA        this,[EAX + EAX*0x4]
    //         0043c581     SHL        this,0x2
    //         0043c584     PUSH       this
    //         0043c585     MOV        this,dword ptr [Regs]                            = 00000000
    //         0043c58b     PUSH       s_Music_Volume                                   = "Music Volume"
    //         0043c590     PUSH       EBP=>DAT_fffffff4
    //         0043c591     CALL       TRegistry::RegSetInt                             int RegSetInt(TRegistry * this, int param_1, 
    //                              dlg_conf.cpp:464 (11)
    //         0043c596     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0043c59c     MOV        EDX,dword ptr [this->_padding_]
    //         0043c59e     CALL       dword ptr [EDX + 0x58]
    //                              dlg_conf.cpp:467 (8)
    //         0043c5a1     MOV        EAX,[rge_base_game]                              = 00000000
    //         0043c5a6     MOV        this,dword ptr [EAX + 0x64]
    //                              dlg_conf.cpp:468 (4)
    //         0043c5a9     TEST       this,this
    //         0043c5ab     JZ         LAB_0043c5dd
    //                              dlg_conf.cpp:470 (10)
    //         0043c5ad     MOV        AL,byte ptr [ECX + this->_padding_]
    //         0043c5b3     CMP        AL,0x1
    //         0043c5b5     JNZ        LAB_0043c5c7
    //                              dlg_conf.cpp:471 (14)
    //         0043c5b7     MOV        EDX,dword ptr [ECX + this->_padding_]
    //         0043c5bd     PUSH       0x0
    //         0043c5bf     PUSH       0x0=>DAT_fffffff8
    //         0043c5c1     PUSH       EBP=>DAT_fffffff4
    //         0043c5c2     PUSH       EDX=>DAT_fffffff0
    //         0043c5c3     PUSH       0x5
    //                              dlg_conf.cpp:472 (6)
    //         0043c5c5     JMP        LAB_0043c5d8
    //                               LAB_0043c5c7                                                 XREF[1]:     0043c5b5(j)  
    //         0043c5c7     CMP        AL,0x2
    //         0043c5c9     JNZ        LAB_0043c5dd
    //                              dlg_conf.cpp:473 (18)
    //         0043c5cb     MOV        EAX,dword ptr [ECX + this->_padding_]
    //         0043c5d1     PUSH       0x0
    //         0043c5d3     PUSH       0x0=>DAT_fffffff8
    //         0043c5d5     PUSH       EBP=>DAT_fffffff4
    //         0043c5d6     PUSH       EAX=>DAT_fffffff0
    //         0043c5d7     PUSH       EBP
    //                               LAB_0043c5d8                                                 XREF[1]:     0043c5c5(j)  
    //         0043c5d8     CALL       TMusic_System::play_tracks                       int play_tracks(TMusic_System * this, int par
    //                               LAB_0043c5dd                                                 XREF[5]:     0043c54e(j), 0043c569(j), 
    //                                                                                                         0043c56d(j), 0043c5ab(j), 
    //                                                                                                         0043c5c9(j)  
    //                              dlg_conf.cpp:480 (9)
    //         0043c5dd     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0043c5e3     MOV        this,dword ptr [ECX + this->_padding_]
    //                              dlg_conf.cpp:481 (4)
    //         0043c5e6     TEST       this,this
    //         0043c5e8     JZ         LAB_0043c606
    //                              dlg_conf.cpp:484 (28)
    //         0043c5ea     MOV        EDX,dword ptr [ESI + 0x560]
    //         0043c5f0     PUSH       EBP
    //         0043c5f1     MOV        EAX,EDX
    //         0043c5f3     NEG        EAX
    //         0043c5f5     SHL        EAX,0x2
    //         0043c5f8     SUB        EAX,EDX
    //         0043c5fa     LEA        EDX,[EAX + EAX*0x4]
    //         0043c5fd     SHL        EDX,0x2
    //         0043c600     PUSH       EDX=>DAT_fffffff8
    //         0043c601     CALL       TSound_Driver::set_volume                        void set_volume(TSound_Driver * this, long pa
    //                               LAB_0043c606                                                 XREF[2]:     0043c532(j), 0043c5e8(j)  
    //                              dlg_conf.cpp:489 (13)
    //         0043c606     MOV        this,dword ptr [ESI + 0x4f4]
    //         0043c60c     CALL       TButtonPanel::get_state                          int get_state(TButtonPanel * this)
    //         0043c611     TEST       EAX,EAX
    //                              dlg_conf.cpp:493 (17)
    //         0043c613     JNZ        LAB_0043c64b
    //         0043c615     MOV        this,dword ptr [ESI + 0x4f8]
    //         0043c61b     CALL       TButtonPanel::get_state                          int get_state(TButtonPanel * this)
    //         0043c620     TEST       EAX,EAX
    //         0043c622     JZ         LAB_0043c630
    //                              dlg_conf.cpp:494 (5)
    //         0043c624     MOV        EDI,0x320
    //                              dlg_conf.cpp:495 (5)
    //         0043c629     MOV        EBP,0x258
    //                              dlg_conf.cpp:497 (17)
    //         0043c62e     JMP        LAB_0043c655
    //                               LAB_0043c630                                                 XREF[1]:     0043c622(j)  
    //         0043c630     MOV        this,dword ptr [ESI + 0x4fc]
    //         0043c636     CALL       TButtonPanel::get_state                          int get_state(TButtonPanel * this)
    //         0043c63b     TEST       EAX,EAX
    //         0043c63d     JZ         LAB_0043c64b
    //                              dlg_conf.cpp:498 (5)
    //         0043c63f     MOV        EDI,0x400
    //                              dlg_conf.cpp:499 (5)
    //         0043c644     MOV        EBP,0x300
    //                              dlg_conf.cpp:501 (2)
    //         0043c649     JMP        LAB_0043c655
    //                               LAB_0043c64b                                                 XREF[2]:     0043c613(j), 0043c63d(j)  
    //                              dlg_conf.cpp:503 (5)
    //         0043c64b     MOV        EDI,0x280
    //                              dlg_conf.cpp:504 (5)
    //         0043c650     MOV        EBP,0x1e0
    //                               LAB_0043c655                                                 XREF[2]:     0043c62e(j), 0043c649(j)  
    //                              dlg_conf.cpp:509 (17)
    //         0043c655     PUSH       0x0
    //         0043c657     PUSH       s_Game_Screen                                    = "Game Screen"
    //         0043c65c     MOV        this,panel_system
    //         0043c661     CALL       TPanelSystem::setCurrentPanel                    int setCurrentPanel(TPanelSystem * this, char
    //                              dlg_conf.cpp:510 (9)
    //         0043c666     MOV        EAX,dword ptr [ESI]
    //         0043c668     PUSH       0x0
    //         0043c66a     MOV        this,ESI
    //         0043c66c     CALL       dword ptr [EAX + 0x14]
    //                              dlg_conf.cpp:511 (7)
    //         0043c66f     MOV        this,ESI
    //         0043c671     CALL       TEasy_Panel::prepare_for_close                   void prepare_for_close(TEasy_Panel * this)
    //                              dlg_conf.cpp:512 (13)
    //         0043c676     MOV        AL,[do_color_log]                                = 00h
    //         0043c67b     TEST       AL,AL
    //         0043c67d     JNZ        LAB_0043c90b
    //                              dlg_conf.cpp:518 (13)
    //         0043c683     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0043c689     PUSH       EBP
    //         0043c68a     PUSH       EDI=>DAT_fffffff8
    //         0043c68b     CALL       RGE_Base_Game::set_screen_size                   void set_screen_size(RGE_Base_Game * this, lo
    //                              dlg_conf.cpp:541 (5)
    //         0043c690     JMP        LAB_0043c90b
    //                               LAB_0043c695                                                 XREF[2]:     0043c2db(j), 0043c2e4(j)  
    //                              dlg_conf.cpp:543 (13)
    //         0043c695     CMP        EAX,dword ptr [ESI + 0x4a8]
    //         0043c69b     JNZ        LAB_0043c6b0
    //         0043c69d     CMP        EDI,0x1
    //         0043c6a0     JNZ        LAB_0043c6b0
    //                              dlg_conf.cpp:545 (2)
    //         0043c6a2     MOV        EAX,EDI
    //                              dlg_conf.cpp:647 (12)
    //         0043c6a4     POP        EDI
    //         0043c6a5     POP        ESI
    //         0043c6a6     POP        EBP
    //         0043c6a7     ADD        ESP,0x104
    //         0043c6ad     RET        0x10
    //                               LAB_0043c6b0                                                 XREF[2]:     0043c69b(j), 0043c6a0(j)  
    //                              dlg_conf.cpp:547 (13)
    //         0043c6b0     CMP        EAX,dword ptr [ESI + 0x4ac]
    //         0043c6b6     JNZ        LAB_0043c6cb
    //         0043c6b8     CMP        EDI,0x1
    //         0043c6bb     JNZ        LAB_0043c6cb
    //                              dlg_conf.cpp:549 (2)
    //         0043c6bd     MOV        EAX,EDI
    //                              dlg_conf.cpp:647 (12)
    //         0043c6bf     POP        EDI
    //         0043c6c0     POP        ESI
    //         0043c6c1     POP        EBP
    //         0043c6c2     ADD        ESP,0x104
    //         0043c6c8     RET        0x10
    //                               LAB_0043c6cb                                                 XREF[2]:     0043c6b6(j), 0043c6bb(j)  
    //                              dlg_conf.cpp:551 (13)
    //         0043c6cb     CMP        EAX,dword ptr [ESI + 0x4b0]
    //         0043c6d1     JNZ        LAB_0043c6e6
    //         0043c6d3     CMP        EDI,0x1
    //         0043c6d6     JNZ        LAB_0043c6e6
    //                              dlg_conf.cpp:553 (2)
    //         0043c6d8     MOV        EAX,EDI
    //                              dlg_conf.cpp:647 (12)
    //         0043c6da     POP        EDI
    //         0043c6db     POP        ESI
    //         0043c6dc     POP        EBP
    //         0043c6dd     ADD        ESP,0x104
    //         0043c6e3     RET        0x10
    //                               LAB_0043c6e6                                                 XREF[2]:     0043c6d1(j), 0043c6d6(j)  
    //                              dlg_conf.cpp:555 (8)
    //         0043c6e6     CMP        EAX,dword ptr [ESI + 0x4f4]
    //         0043c6ec     JNZ        LAB_0043c6ff
    //                              dlg_conf.cpp:557 (5)
    //         0043c6ee     MOV        EAX,0x1
    //                              dlg_conf.cpp:647 (12)
    //         0043c6f3     POP        EDI
    //         0043c6f4     POP        ESI
    //         0043c6f5     POP        EBP
    //         0043c6f6     ADD        ESP,0x104
    //         0043c6fc     RET        0x10
    //                               LAB_0043c6ff                                                 XREF[1]:     0043c6ec(j)  
    //                              dlg_conf.cpp:559 (8)
    //         0043c6ff     CMP        EAX,dword ptr [ESI + 0x4f8]
    //         0043c705     JNZ        LAB_0043c718
    //                              dlg_conf.cpp:561 (5)
    //         0043c707     MOV        EAX,0x1
    //                              dlg_conf.cpp:647 (12)
    //         0043c70c     POP        EDI
    //         0043c70d     POP        ESI
    //         0043c70e     POP        EBP
    //         0043c70f     ADD        ESP,0x104
    //         0043c715     RET        0x10
    //                               LAB_0043c718                                                 XREF[1]:     0043c705(j)  
    //                              dlg_conf.cpp:563 (8)
    //         0043c718     CMP        EAX,dword ptr [ESI + 0x4fc]
    //         0043c71e     JNZ        LAB_0043c731
    //                              dlg_conf.cpp:565 (5)
    //         0043c720     MOV        EAX,0x1
    //                              dlg_conf.cpp:647 (12)
    //         0043c725     POP        EDI
    //         0043c726     POP        ESI
    //         0043c727     POP        EBP
    //         0043c728     ADD        ESP,0x104
    //         0043c72e     RET        0x10
    //                               LAB_0043c731                                                 XREF[1]:     0043c71e(j)  
    //                              dlg_conf.cpp:568 (13)
    //         0043c731     CMP        EAX,dword ptr [ESI + 0x4c0]
    //         0043c737     JNZ        LAB_0043c796
    //         0043c739     CMP        EDI,0x4
    //         0043c73c     JNZ        LAB_0043c796
    //                              dlg_conf.cpp:569 (13)
    //         0043c73e     MOV        EDX,dword ptr [ESP + param_3]
    //         0043c745     MOV        dword ptr [ESI + 0x55c],EDX
    //                              dlg_conf.cpp:570 (9)
    //         0043c74b     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0043c751     MOV        this,dword ptr [ECX + this->_padding_]
    //                              dlg_conf.cpp:571 (8)
    //         0043c754     TEST       this,this
    //         0043c756     JZ         LAB_0043c91a
    //                              dlg_conf.cpp:573 (23)
    //         0043c75c     MOV        EAX,EDX
    //         0043c75e     PUSH       0x1
    //         0043c760     NEG        EAX
    //         0043c762     SHL        EAX,0x2
    //         0043c765     SUB        EAX,EDX
    //         0043c767     LEA        EDX,[EAX + EAX*0x4]
    //         0043c76a     SHL        EDX,0x2
    //         0043c76d     PUSH       EDX
    //         0043c76e     CALL       TMusic_System::set_volume                        void set_volume(TMusic_System * this, long pa
    //                              dlg_conf.cpp:577 (8)
    //         0043c773     MOV        EAX,[rge_base_game]                              = 00000000
    //         0043c778     MOV        this,dword ptr [EAX + 0x60]
    //                              dlg_conf.cpp:578 (8)
    //         0043c77b     TEST       this,this
    //         0043c77d     JZ         LAB_0043c91a
    //                              dlg_conf.cpp:580 (17)
    //         0043c783     MOV        ESI,dword ptr [ESI + 0x560]
    //         0043c789     PUSH       0x1
    //         0043c78b     MOV        EAX,ESI
    //         0043c78d     NEG        EAX
    //         0043c78f     SHL        EAX,0x2
    //         0043c792     SUB        EAX,ESI
    //                              dlg_conf.cpp:584 (2)
    //         0043c794     JMP        LAB_0043c7cb
    //                               LAB_0043c796                                                 XREF[2]:     0043c737(j), 0043c73c(j)  
    //                              dlg_conf.cpp:587 (13)
    //         0043c796     CMP        EAX,dword ptr [ESI + 0x4d0]
    //         0043c79c     JNZ        LAB_0043c7e8
    //         0043c79e     CMP        EDI,0x4
    //         0043c7a1     JNZ        LAB_0043c7e8
    //                              dlg_conf.cpp:588 (13)
    //         0043c7a3     MOV        EDX,dword ptr [ESP + param_3]
    //         0043c7aa     MOV        dword ptr [ESI + 0x560],EDX
    //                              dlg_conf.cpp:589 (8)
    //         0043c7b0     MOV        EAX,[rge_base_game]                              = 00000000
    //         0043c7b5     MOV        this,dword ptr [EAX + 0x60]
    //                              dlg_conf.cpp:590 (8)
    //         0043c7b8     TEST       this,this
    //         0043c7ba     JZ         LAB_0043c91a
    //                              dlg_conf.cpp:592 (23)
    //         0043c7c0     MOV        EAX,EDX
    //         0043c7c2     PUSH       0x1
    //         0043c7c4     NEG        EAX
    //         0043c7c6     SHL        EAX,0x2
    //         0043c7c9     SUB        EAX,EDX
    //                               LAB_0043c7cb                                                 XREF[1]:     0043c794(j)  
    //         0043c7cb     LEA        EDX,[EAX + EAX*0x4]
    //         0043c7ce     SHL        EDX,0x2
    //         0043c7d1     PUSH       EDX
    //         0043c7d2     CALL       TSound_Driver::set_volume                        void set_volume(TSound_Driver * this, long pa
    //                              dlg_conf.cpp:594 (5)
    //         0043c7d7     MOV        EAX,0x1
    //                              dlg_conf.cpp:647 (12)
    //         0043c7dc     POP        EDI
    //         0043c7dd     POP        ESI
    //         0043c7de     POP        EBP
    //         0043c7df     ADD        ESP,0x104
    //         0043c7e5     RET        0x10
    //                               LAB_0043c7e8                                                 XREF[2]:     0043c79c(j), 0043c7a1(j)  
    //                              dlg_conf.cpp:597 (13)
    //         0043c7e8     CMP        EAX,dword ptr [ESI + 0x4e0]
    //         0043c7ee     JNZ        LAB_0043c82b
    //         0043c7f0     CMP        EDI,0x4
    //         0043c7f3     JNZ        LAB_0043c82b
    //                              dlg_conf.cpp:598 (6)
    //         0043c7f5     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //                              dlg_conf.cpp:599 (12)
    //         0043c7fb     LEA        EDX,[EBP + 0xa]
    //         0043c7fe     MOV        this,dword ptr [ECX + this->_padding_]
    //         0043c801     MOV        dword ptr [this->_padding_ + 0x8c8],EDX
    //                              dlg_conf.cpp:600 (6)
    //         0043c807     MOV        dword ptr [this->_padding_ + 0x8d0],EDX
    //                               LAB_0043c80d                                                 XREF[3]:     0043c2cf(j), 0043c831(j), 
    //                                                                                                         0043c836(j)  
    //                              dlg_conf.cpp:646 (18)
    //         0043c80d     MOV        this,dword ptr [ESP + param_4]
    //         0043c814     PUSH       this
    //         0043c815     PUSH       EBP
    //         0043c816     PUSH       EDI
    //         0043c817     PUSH       EAX
    //         0043c818     MOV        this,ESI
    //         0043c81a     CALL       TPanel::action                                   long action(TPanel * this, TPanel * param_1, 
    //                              dlg_conf.cpp:647 (12)
    //         0043c81f     POP        EDI
    //         0043c820     POP        ESI
    //         0043c821     POP        EBP
    //         0043c822     ADD        ESP,0x104
    //         0043c828     RET        0x10
    //                               LAB_0043c82b                                                 XREF[2]:     0043c7ee(j), 0043c7f3(j)  
    //                              dlg_conf.cpp:603 (13)
    //         0043c82b     CMP        EAX,dword ptr [ESI + 0x548]
    //         0043c831     JNZ        LAB_0043c80d
    //         0043c833     CMP        EDI,0x1
    //         0043c836     JNZ        LAB_0043c80d
    //                              dlg_conf.cpp:608 (9)
    //         0043c838     MOV        EDX,dword ptr [rge_base_game]                    = 00000000
    //         0043c83e     MOV        this,dword ptr [EDX + 0x64]
    //                              dlg_conf.cpp:609 (4)
    //         0043c841     TEST       this,this
    //         0043c843     JZ         LAB_0043c861
    //                              dlg_conf.cpp:612 (28)
    //         0043c845     MOV        EDX,dword ptr [ESI + 0x54c]
    //         0043c84b     PUSH       EDI
    //         0043c84c     MOV        EAX,EDX
    //         0043c84e     NEG        EAX
    //         0043c850     SHL        EAX,0x2
    //         0043c853     SUB        EAX,EDX
    //         0043c855     LEA        EAX,[EAX + EAX*0x4]
    //         0043c858     SHL        EAX,0x2
    //         0043c85b     PUSH       EAX
    //         0043c85c     CALL       TMusic_System::set_volume                        void set_volume(TMusic_System * this, long pa
    //                               LAB_0043c861                                                 XREF[1]:     0043c843(j)  
    //                              dlg_conf.cpp:616 (9)
    //         0043c861     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0043c867     MOV        this,dword ptr [ECX + this->_padding_]
    //                              dlg_conf.cpp:617 (4)
    //         0043c86a     TEST       this,this
    //         0043c86c     JZ         LAB_0043c88b
    //                              dlg_conf.cpp:620 (29)
    //         0043c86e     MOV        EDX,dword ptr [ESI + 0x550]
    //         0043c874     PUSH       0x1
    //         0043c876     MOV        EAX,EDX
    //         0043c878     NEG        EAX
    //         0043c87a     SHL        EAX,0x2
    //         0043c87d     SUB        EAX,EDX
    //         0043c87f     LEA        EDX,[EAX + EAX*0x4]
    //         0043c882     SHL        EDX,0x2
    //         0043c885     PUSH       EDX
    //         0043c886     CALL       TSound_Driver::set_volume                        void set_volume(TSound_Driver * this, long pa
    //                               LAB_0043c88b                                                 XREF[1]:     0043c86c(j)  
    //                              dlg_conf.cpp:624 (5)
    //         0043c88b     MOV        EAX,[rge_base_game]                              = 00000000
    //                              dlg_conf.cpp:625 (15)
    //         0043c890     MOV        this,dword ptr [ESI + 0x558]
    //         0043c896     MOV        EAX,dword ptr [EAX + 0xc]
    //         0043c899     MOV        dword ptr [EAX + 0x8c8],this
    //                              dlg_conf.cpp:626 (12)
    //         0043c89f     MOV        EDX,dword ptr [ESI + 0x558]
    //         0043c8a5     MOV        dword ptr [EAX + 0x8d0],EDX
    //                              dlg_conf.cpp:629 (10)
    //         0043c8ab     MOV        EAX,dword ptr [ESI + 0x490]
    //         0043c8b1     TEST       EAX,EAX
    //         0043c8b3     JNZ        LAB_0043c8fa
    //                              dlg_conf.cpp:631 (32)
    //         0043c8b5     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0043c8bb     CALL       RGE_Base_Game::singlePlayerGame                  int singlePlayerGame(RGE_Base_Game * this)
    //         0043c8c0     CMP        EAX,0x1
    //         0043c8c3     JNZ        LAB_0043c8de
    //         0043c8c5     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0043c8cb     MOV        EAX,dword ptr [this->_padding_ + 0xa00]
    //         0043c8d1     TEST       EAX,EAX
    //         0043c8d3     JNZ        LAB_0043c8de
    //                              dlg_conf.cpp:632 (9)
    //         0043c8d5     PUSH       0x0
    //         0043c8d7     PUSH       0x0
    //         0043c8d9     CALL       RGE_Base_Game::set_paused                        void set_paused(RGE_Base_Game * this, int par
    //                               LAB_0043c8de                                                 XREF[2]:     0043c8c3(j), 0043c8d3(j)  
    //                              dlg_conf.cpp:633 (17)
    //         0043c8de     PUSH       0x0
    //         0043c8e0     PUSH       s_Game_Screen                                    = "Game Screen"
    //         0043c8e5     MOV        this,panel_system
    //         0043c8ea     CALL       TPanelSystem::setCurrentPanel                    int setCurrentPanel(TPanelSystem * this, char
    //                              dlg_conf.cpp:634 (9)
    //         0043c8ef     MOV        EAX,dword ptr [ESI]
    //         0043c8f1     PUSH       0x0
    //         0043c8f3     MOV        this,ESI
    //         0043c8f5     CALL       dword ptr [EAX + 0x14]
    //                              dlg_conf.cpp:637 (2)
    //         0043c8f8     JMP        LAB_0043c90b
    //                               LAB_0043c8fa                                                 XREF[2]:     0043c2f2(j), 0043c8b3(j)  
    //                              dlg_conf.cpp:639 (17)
    //         0043c8fa     PUSH       0x0
    //         0043c8fc     PUSH       s_Main_Menu                                      = "Main Menu"
    //         0043c901     MOV        this,panel_system
    //         0043c906     CALL       TPanelSystem::setCurrentPanel                    int setCurrentPanel(TPanelSystem * this, char
    //                               LAB_0043c90b                                                 XREF[3]:     0043c67d(j), 0043c690(j), 
    //                                                                                                         0043c8f8(j)  
    //                              dlg_conf.cpp:640 (15)
    //         0043c90b     PUSH       s_Config_Dialog                                  = "Config Dialog"
    //         0043c910     MOV        this,panel_system
    //         0043c915     CALL       TPanelSystem::destroyPanel                       int destroyPanel(TPanelSystem * this, char * 
    //                               LAB_0043c91a                                                 XREF[3]:     0043c756(j), 0043c77d(j), 
    //                                                                                                         0043c7ba(j)  
    //                              dlg_conf.cpp:647 (17)
    //         0043c91a     POP        EDI
    //         0043c91b     POP        ESI
    //         0043c91c     MOV        EAX,0x1
    //         0043c921     POP        EBP
    //         0043c922     ADD        ESP,0x104
    //         0043c928     RET        0x10
    //         0043c92b     ??         90h
    //         0043c92c     NOP
    //         0043c92d     NOP
    //         0043c92e     NOP
    //         0043c92f     NOP
}

TribeConfigDialog::TribeConfigDialog(Mode param_1, TScreenPanel* param_2) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
}

long TribeConfigDialog::action(TPanel* param_1, long param_2, ulong param_3, ulong param_4) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return 0;
}

