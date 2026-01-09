#include "common.h"
#include "scr_sedo.h"

TRIBE_Screen_Sed_Open::TRIBE_Screen_Sed_Open() {
    /* TODO: Stub */
    //                              undefined __thiscall TRIBE_Screen_Sed_Open(TRIBE_Screen_Sed_Open * t
    //              undefined         <UNASSIGNED>   <RETURN>
    //              TRIBE_Screen_S    ECX:4 (auto)   this
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     004b340a(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     004b3660(R)  
    //              char[260]         Stack[-0x114   info_file                 XREF[1,2]:   004b33f6(W), 004b346b(*), 004b349b(*)  
    //              undefined4        Stack[-0x118   local_118                 XREF[1]:     004b3657(W)  
    //              TPanel *[4]       Stack[-0x128   tabList                   XREF[2,4]:   004b345b(W), 004b3492(R), 004b3644(W), 004b364a(*), 
    //                                                                                     004b3640(W), 004b364e(W)  
    //              TEasy_Panel *     Stack[-0x12c   from_panel
    //                               ??0TRIBE_Screen_Sed_Open@@QAE@XZ                             XREF[6]:     action:00440738(c), 
    //                               TRIBE_Screen_Sed_Open::TRIBE_Screen_Sed_Open                              save_for_scenario_editor:004a816c(
    //                                                                                                         action:004acf9f(c), 
    //                                                                                                         command_open:004ad5f9(c), 
    //                                                                                                         command_save:004ad905(c), 
    //                                                                                                         action:004b3254(c)  
    //                              scr_sedo.cpp:45 (47)
    //         004b33d0     PUSH       -0x1
    //         004b33d2     PUSH       FUN_0055f5db
    //         004b33d7     MOV        EAX,FS:[0x0]
    //         004b33dd     PUSH       EAX
    //         004b33de     MOV        dword ptr FS:[0x0],ESP
    //         004b33e5     SUB        ESP,0x11c
    //         004b33eb     PUSH       EBX
    //         004b33ec     PUSH       EBP
    //         004b33ed     PUSH       ESI
    //         004b33ee     PUSH       EDI
    //         004b33ef     MOV        EBP,this
    //         004b33f1     PUSH       s_Scenario_Editor_Open                           = "Scenario Editor Open"
    //         004b33f6     MOV        dword ptr [ESP + info_file[0]],EBP
    //         004b33fa     CALL       TScreenPanel::TScreenPanel                       undefined TScreenPanel(TScreenPanel * this, c
    //                              scr_sedo.cpp:48 (6)
    //         004b33ff     LEA        EBX,[EBP + 0x47c]
    //                              scr_sedo.cpp:55 (84)
    //         004b3405     MOV        this,panel_system
    //         004b340a     MOV        dword ptr [ESP + local_4],0x0
    //         004b3415     MOV        dword ptr [EBP],TRIBE_Screen_Sed_Open::`vftable' = 004b3680
    //         004b341c     MOV        dword ptr [EBP + 0x478],0x0
    //         004b3426     MOV        dword ptr [EBX],0x0
    //         004b342c     MOV        dword ptr [EBP + 0x480],0x0
    //         004b3436     MOV        dword ptr [EBP + 0x484],0x0
    //         004b3440     MOV        dword ptr [EBP + 0x488],0x0
    //         004b344a     MOV        dword ptr [EBP + 0x48c],0x0
    //         004b3454     CALL       TPanelSystem::currentPanel                       TPanel * currentPanel(TPanelSystem * this)
    //                              scr_sedo.cpp:57 (28)
    //         004b3459     MOV        this,EAX
    //         004b345b     MOV        dword ptr [ESP + tabList[0]],EAX
    //         004b345f     CALL       TEasy_Panel::get_info_file                       char * get_info_file(TEasy_Panel * this)
    //         004b3464     MOV        EDI,EAX
    //         004b3466     OR         this,0xffffffff
    //         004b3469     XOR        EAX,EAX
    //         004b346b     LEA        EDX=>info_file[4],[ESP + 0x28]
    //         004b346f     SCASB.RE   ES:EDI
    //         004b3471     NOT        this
    //         004b3473     SUB        EDI,this
    //                              scr_sedo.cpp:59 (56)
    //         004b3475     PUSH       0x1
    //         004b3477     MOV        EAX,this
    //         004b3479     MOV        ESI,EDI
    //         004b347b     MOV        EDI,EDX
    //         004b347d     SHR        this,0x2
    //         004b3480     MOVSD.REP  ES:EDI,ESI
    //         004b3482     MOV        this,EAX
    //         004b3484     AND        this,0x3
    //         004b3487     MOVSB.REP  ES:EDI,ESI
    //         004b3489     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004b348f     MOV        ESI,dword ptr [ECX + this->_padding_]
    //         004b3492     MOV        this,dword ptr [ESP + tabList[0]]
    //         004b3496     CALL       TEasy_Panel::get_info_id                         long get_info_id(TEasy_Panel * this)
    //         004b349b     LEA        EDX=>info_file[4],[ESP + 0x2c]
    //         004b349f     PUSH       EAX
    //         004b34a0     PUSH       EDX
    //         004b34a1     PUSH       ESI
    //         004b34a2     MOV        this,EBP
    //         004b34a4     CALL       TScreenPanel::setup                              long setup(TScreenPanel * this, TDrawArea * p
    //         004b34a9     TEST       EAX,EAX
    //         004b34ab     JNZ        LAB_004b34bc
    //                              scr_sedo.cpp:60 (10)
    //         004b34ad     MOV        dword ptr [EBP + 0xd8],0x1
    //                              scr_sedo.cpp:61 (5)
    //         004b34b7     JMP        LAB_004b3660
    //                               LAB_004b34bc                                                 XREF[1]:     004b34ab(j)  
    //                              scr_sedo.cpp:64 (9)
    //         004b34bc     PUSH       0x0
    //         004b34be     MOV        this,EBP
    //         004b34c0     CALL       TEasy_Panel::setup_shadow_area                   void setup_shadow_area(TEasy_Panel * this, in
    //                              scr_sedo.cpp:65 (17)
    //         004b34c5     PUSH       0x1e0
    //         004b34ca     PUSH       0x280
    //         004b34cf     MOV        this,EBP
    //         004b34d1     CALL       TEasy_Panel::set_ideal_size                      void set_ideal_size(TEasy_Panel * this, long 
    //                              scr_sedo.cpp:68 (47)
    //         004b34d6     PUSH       0x0
    //         004b34d8     PUSH       0x0
    //         004b34da     PUSH       0x1
    //         004b34dc     PUSH       0x1
    //         004b34de     PUSH       0x1e
    //         004b34e0     PUSH       0x258
    //         004b34e5     PUSH       0x14
    //         004b34e7     PUSH       0x14
    //         004b34e9     LEA        EAX,[EBP + 0x478]
    //                              language.dll match for 0x24cd: "Select Scenario"
    //         004b34ef     PUSH       0x24cd
    //         004b34f4     PUSH       EAX
    //         004b34f5     PUSH       EBP
    //         004b34f6     MOV        this,EBP
    //         004b34f8     CALL       TEasy_Panel::create_text                         int create_text(TEasy_Panel * this, TPanel * 
    //         004b34fd     TEST       EAX,EAX
    //         004b34ff     JZ         LAB_004b3660
    //                              scr_sedo.cpp:71 (33)
    //         004b3505     PUSH       0xb
    //         004b3507     PUSH       0x154
    //         004b350c     PUSH       0x258
    //         004b3511     PUSH       0x46
    //         004b3513     PUSH       0x14
    //         004b3515     PUSH       EBX
    //         004b3516     PUSH       EBP
    //         004b3517     MOV        this,EBP
    //         004b3519     CALL       TEasy_Panel::create_list                         int create_list(TEasy_Panel * this, TPanel * 
    //         004b351e     TEST       EAX,EAX
    //         004b3520     JZ         LAB_004b3660
    //                              scr_sedo.cpp:72 (27)
    //         004b3526     MOV        EAX,dword ptr [EBX]
    //         004b3528     PUSH       0x14
    //         004b352a     PUSH       EAX
    //         004b352b     LEA        EAX,[EBP + 0x480]
    //         004b3531     PUSH       EAX
    //         004b3532     MOV        this,EBP
    //         004b3534     CALL       TEasy_Panel::create_auto_scrollbar               int create_auto_scrollbar(TEasy_Panel * this,
    //         004b3539     TEST       EAX,EAX
    //         004b353b     JZ         LAB_004b3660
    //                              scr_sedo.cpp:75 (50)
    //         004b3541     PUSH       0x0
    //         004b3543     PUSH       0x0
    //         004b3545     PUSH       0x0
    //         004b3547     PUSH       0x1e
    //         004b3549     PUSH       0xb4
    //         004b354e     PUSH       0x1b8
    //         004b3553     PUSH       0x1e
    //         004b3555     PUSH       0x0
    //         004b3557     LEA        EAX,[EBP + 0x484]
    //                              language.dll match for 0xfa1: "OK"
    //         004b355d     PUSH       0xfa1
    //         004b3562     PUSH       EAX
    //         004b3563     PUSH       EBP
    //         004b3564     MOV        this,EBP
    //         004b3566     CALL       TEasy_Panel::create_button                       int create_button(TEasy_Panel * this, TPanel 
    //         004b356b     TEST       EAX,EAX
    //         004b356d     JZ         LAB_004b3660
    //                              scr_sedo.cpp:76 (53)
    //         004b3573     PUSH       0x0
    //         004b3575     PUSH       0x0
    //         004b3577     PUSH       0x0
    //         004b3579     PUSH       0x1e
    //         004b357b     PUSH       0xb4
    //         004b3580     PUSH       0x1b8
    //         004b3585     PUSH       0xe6
    //         004b358a     PUSH       0x0
    //         004b358c     LEA        ESI,[EBP + 0x48c]
    //                              language.dll match for 0x24c9: "Delete"
    //         004b3592     PUSH       0x24c9
    //         004b3597     PUSH       ESI
    //         004b3598     PUSH       EBP
    //         004b3599     MOV        this,EBP
    //         004b359b     CALL       TEasy_Panel::create_button                       int create_button(TEasy_Panel * this, TPanel 
    //         004b35a0     TEST       EAX,EAX
    //         004b35a2     JZ         LAB_004b3660
    //                              scr_sedo.cpp:77 (53)
    //         004b35a8     PUSH       0x0
    //         004b35aa     PUSH       0x0
    //         004b35ac     PUSH       0x0
    //         004b35ae     PUSH       0x1e
    //         004b35b0     PUSH       0xb4
    //         004b35b5     PUSH       0x1b8
    //         004b35ba     PUSH       0x1ae
    //         004b35bf     PUSH       0x0
    //         004b35c1     LEA        EDI,[EBP + 0x488]
    //                              language.dll match for 0xfa2: "Cancel"
    //         004b35c7     PUSH       0xfa2
    //         004b35cc     PUSH       EDI
    //         004b35cd     PUSH       EBP
    //         004b35ce     MOV        this,EBP
    //         004b35d0     CALL       TEasy_Panel::create_button                       int create_button(TEasy_Panel * this, TPanel 
    //         004b35d5     TEST       EAX,EAX
    //         004b35d7     JZ         LAB_004b3660
    //                              scr_sedo.cpp:78 (20)
    //         004b35dd     MOV        EAX,dword ptr [EDI]
    //         004b35df     XOR        this,this
    //         004b35e1     MOV        dword ptr [EAX + 0x298],0x1b
    //         004b35eb     MOV        dword ptr [EAX + 0x29c],this
    //                              scr_sedo.cpp:79 (8)
    //         004b35f1     MOV        EAX,dword ptr [ESI]
    //         004b35f3     MOV        dword ptr [EAX + 0x29c],this
    //                              scr_sedo.cpp:82 (17)
    //         004b35f9     MOV        this,EBP
    //         004b35fb     MOV        dword ptr [EAX + 0x298],0x2e
    //         004b3605     CALL       TRIBE_Screen_Sed_Open::fillList                  void fillList(TRIBE_Screen_Sed_Open * this)
    //                              scr_sedo.cpp:84 (12)
    //         004b360a     MOV        this,dword ptr [EBX]
    //         004b360c     CALL       TTextPanel::currentLine                          char * currentLine(TTextPanel * this)
    //         004b3611     CMP        byte ptr [EAX],0x0
    //         004b3614     JNZ        LAB_004b362c
    //                              scr_sedo.cpp:86 (13)
    //         004b3616     MOV        this,dword ptr [EBP + 0x484]
    //         004b361c     PUSH       0x1
    //         004b361e     CALL       TButtonPanel::set_disabled                       void set_disabled(TButtonPanel * this, int pa
    //                              scr_sedo.cpp:87 (9)
    //         004b3623     MOV        this,dword ptr [ESI]
    //         004b3625     PUSH       0x1
    //         004b3627     CALL       TButtonPanel::set_disabled                       void set_disabled(TButtonPanel * this, int pa
    //                               LAB_004b362c                                                 XREF[1]:     004b3614(j)  
    //                              scr_sedo.cpp:91 (10)
    //         004b362c     MOV        this,dword ptr [EBX]
    //         004b362e     PUSH       this
    //         004b362f     MOV        this,EBP
    //         004b3631     CALL       TPanel::set_curr_child                           void set_curr_child(TPanel * this, TPanel * p
    //                              scr_sedo.cpp:95 (8)
    //         004b3636     MOV        EAX,dword ptr [EBP + 0x484]
    //         004b363c     MOV        EDX,dword ptr [EBX]
    //                              scr_sedo.cpp:96 (10)
    //         004b363e     MOV        this,dword ptr [ESI]
    //         004b3640     MOV        dword ptr [ESP + tabList[2]],EAX
    //         004b3644     MOV        dword ptr [ESP + tabList[1]],EDX
    //                              scr_sedo.cpp:97 (2)
    //         004b3648     MOV        EDX,dword ptr [EDI]
    //                              scr_sedo.cpp:98 (22)
    //         004b364a     LEA        EAX=>tabList[1],[ESP + 0x14]
    //         004b364e     MOV        dword ptr [ESP + tabList[3]],this
    //         004b3652     PUSH       0x4
    //         004b3654     PUSH       EAX
    //         004b3655     MOV        this,EBP
    //         004b3657     MOV        dword ptr [ESP + local_118],EDX
    //         004b365b     CALL       TPanel::set_tab_order                            void set_tab_order(TPanel * this, TPanel * * 
    //                               LAB_004b3660                                                 XREF[7]:     004b34b7(j), 004b34ff(j), 
    //                                                                                                         004b3520(j), 004b353b(j), 
    //                                                                                                         004b356d(j), 004b35a2(j), 
    //                                                                                                         004b35d7(j)  
    //                              scr_sedo.cpp:99 (27)
    //         004b3660     MOV        this,dword ptr [ESP + local_c]
    //         004b3667     POP        EDI
    //         004b3668     MOV        EAX,EBP
    //         004b366a     POP        ESI
    //         004b366b     POP        EBP
    //         004b366c     MOV        dword ptr FS:[0x0],this
    //         004b3673     POP        EBX
    //         004b3674     ADD        ESP,0x128
    //         004b367a     RET
    //         004b367b     ??         90h
    //         004b367c     NOP
    //         004b367d     NOP
    //         004b367e     NOP
    //         004b367f     NOP
}

TRIBE_Screen_Sed_Open::~TRIBE_Screen_Sed_Open() {
    /* TODO: Stub */
    //                              void __thiscall ~TRIBE_Screen_Sed_Open(TRIBE_Screen_Sed_Open * this)
    //              void              <VOID>         <RETURN>
    //              TRIBE_Screen_S    ECX:4 (auto)   this
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     004b36c9(W), 004b371f(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     004b372c(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     004b36b9(W)  
    //                               ??1TRIBE_Screen_Sed_Open@@UAE@XZ                             XREF[1]:     `scalar_deleting_destructor':004b3
    //                               TRIBE_Screen_Sed_Open::~TRIBE_Screen_Sed_Open
    //                              scr_sedo.cpp:104 (35)
    //         004b36a0     PUSH       -0x1
    //         004b36a2     PUSH       FUN_0055f5f8
    //         004b36a7     MOV        EAX,FS:[0x0]
    //         004b36ad     PUSH       EAX
    //         004b36ae     MOV        dword ptr FS:[0x0],ESP
    //         004b36b5     PUSH       this
    //         004b36b6     PUSH       ESI
    //         004b36b7     MOV        ESI,this
    //         004b36b9     MOV        dword ptr [ESP + local_10],ESI
    //         004b36bd     MOV        dword ptr [ESI],TRIBE_Screen_Sed_Open::`vftable' = 004b3680
    //                              scr_sedo.cpp:105 (20)
    //         004b36c3     LEA        EAX,[ESI + 0x478]
    //         004b36c9     MOV        dword ptr [ESP + local_4],0x0
    //         004b36d1     PUSH       EAX
    //         004b36d2     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //                              scr_sedo.cpp:106 (14)
    //         004b36d7     LEA        this,[ESI + 0x47c]
    //         004b36dd     PUSH       this
    //         004b36de     MOV        this,ESI
    //         004b36e0     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //                              scr_sedo.cpp:107 (14)
    //         004b36e5     LEA        EDX,[ESI + 0x480]
    //         004b36eb     MOV        this,ESI
    //         004b36ed     PUSH       EDX
    //         004b36ee     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //                              scr_sedo.cpp:108 (14)
    //         004b36f3     LEA        EAX,[ESI + 0x484]
    //         004b36f9     MOV        this,ESI
    //         004b36fb     PUSH       EAX
    //         004b36fc     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //                              scr_sedo.cpp:109 (14)
    //         004b3701     LEA        this,[ESI + 0x488]
    //         004b3707     PUSH       this
    //         004b3708     MOV        this,ESI
    //         004b370a     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //                              scr_sedo.cpp:110 (16)
    //         004b370f     LEA        EDX,[ESI + 0x48c]
    //         004b3715     MOV        this,ESI
    //         004b3717     PUSH       EDX
    //         004b3718     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //         004b371d     MOV        this,ESI
    //                              scr_sedo.cpp:111 (29)
    //         004b371f     MOV        dword ptr [ESP + local_4],0xffffffff
    //         004b3727     CALL       TScreenPanel::~TScreenPanel                      void ~TScreenPanel(TScreenPanel * this)
    //         004b372c     MOV        this,dword ptr [ESP + local_c]
    //         004b3730     POP        ESI
    //         004b3731     MOV        dword ptr FS:[0x0],this
    //         004b3738     ADD        ESP,0x10
    //         004b373b     RET
    //         004b373c     ??         90h
    //         004b373d     NOP
    //         004b373e     NOP
    //         004b373f     NOP
}

void TRIBE_Screen_Sed_Open::fillList() {
    /* TODO: Stub */
    //                              void __thiscall fillList(TRIBE_Screen_Sed_Open * this)
    //              void              <VOID>         <RETURN>
    //              TRIBE_Screen_S    ECX:4 (auto)   this
    //              _finddata_t       Stack[-0x11c   fileInfo                  XREF[0,8]:   004b3789(*), 004b37e8(*), 004b3820(*), 004b387f(*), 
    //                                                                                     004b37a5(*), 004b37b6(*), 004b383c(*), 004b384d(*)  
    //              char[260]         Stack[-0x220   file_name                 XREF[0,8]:   004b376d(*), 004b3790(*), 004b37bf(*), 004b37d7(*), 
    //                                                                                     004b3804(*), 004b3827(*), 004b3856(*), 004b386e(*)  
    //                               ?fillList@TRIBE_Screen_Sed_Open@@IAEXXZ                      XREF[1]:     TRIBE_Screen_Sed_Open:004b3605(c)  
    //                               TRIBE_Screen_Sed_Open::fillList
    //                              scr_sedo.cpp:116 (12)
    //         004b3740     SUB        ESP,0x21c
    //         004b3746     PUSH       EBX
    //         004b3747     PUSH       EBP
    //         004b3748     MOV        EBP,this
    //         004b374a     PUSH       ESI
    //         004b374b     PUSH       EDI
    //                              scr_sedo.cpp:123 (11)
    //         004b374c     MOV        this,dword ptr [EBP + 0x47c]
    //         004b3752     CALL       TTextPanel::empty_list                           void empty_list(TTextPanel * this)
    //                              scr_sedo.cpp:124 (16)
    //         004b3757     MOV        EAX,dword ptr [EBP + 0x47c]
    //         004b375d     MOV        dword ptr [EAX + 0x15c],0x1
    //                              scr_sedo.cpp:128 (34)
    //         004b3767     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004b376d     LEA        EAX=>file_name[4],[ESP + 0x10]
    //         004b3771     MOV        EDX,dword ptr [ECX + this->_padding_]
    //         004b3774     ADD        EDX,0xc17
    //         004b377a     PUSH       EDX
    //         004b377b     PUSH       s_%s*.scn                                        = "%s*.scn"
    //         004b3780     PUSH       EAX
    //         004b3781     CALL       sprintf                                          undefined sprintf()
    //         004b3786     ADD        ESP,0xc
    //                              scr_sedo.cpp:129 (23)
    //         004b3789     LEA        this=>fileInfo.time_create,[ESP + 0x114]
    //         004b3790     LEA        EDX=>file_name[4],[ESP + 0x10]
    //         004b3794     PUSH       this
    //         004b3795     PUSH       EDX
    //         004b3796     CALL       __findfirst                                      undefined __findfirst()
    //         004b379b     MOV        EBX,EAX
    //         004b379d     ADD        ESP,0x8
    //                              scr_sedo.cpp:130 (5)
    //         004b37a0     CMP        EBX,-0x1
    //         004b37a3     JZ         LAB_004b37fe
    //                               LAB_004b37a5                                                 XREF[1]:     004b37fc(j)  
    //                              scr_sedo.cpp:131 (17)
    //         004b37a5     LEA        EDI=>fileInfo+0x18,[ESP + 0x128]
    //         004b37ac     OR         this,0xffffffff
    //         004b37af     XOR        EAX,EAX
    //         004b37b1     SCASB.RE   ES:EDI
    //         004b37b3     NOT        this
    //         004b37b5     DEC        this
    //                              scr_sedo.cpp:132 (24)
    //         004b37b6     LEA        EAX=>fileInfo+0x18,[ESP + 0x128]
    //         004b37bd     MOV        ESI,this
    //         004b37bf     LEA        this=>file_name[4],[ESP + 0x10]
    //         004b37c3     SUB        ESI,0x4
    //         004b37c6     PUSH       ESI
    //         004b37c7     PUSH       EAX
    //         004b37c8     PUSH       this
    //         004b37c9     CALL       strncpy                                          undefined strncpy()
    //                              scr_sedo.cpp:134 (26)
    //         004b37ce     MOV        this,dword ptr [EBP + 0x47c]
    //         004b37d4     ADD        ESP,0xc
    //         004b37d7     LEA        EDX=>file_name[4],[ESP + 0x10]
    //         004b37db     MOV        byte ptr [ESP + ESI*0x1 + 0x10],0x0
    //         004b37e0     PUSH       0x0
    //         004b37e2     PUSH       EDX
    //         004b37e3     CALL       TTextPanel::append_line                          int append_line(TTextPanel * this, char * par
    //                              scr_sedo.cpp:135 (22)
    //         004b37e8     LEA        EAX=>fileInfo.time_create,[ESP + 0x114]
    //         004b37ef     PUSH       EAX
    //         004b37f0     PUSH       EBX
    //         004b37f1     CALL       __findnext                                       undefined __findnext()
    //         004b37f6     ADD        ESP,0x8
    //         004b37f9     CMP        EAX,-0x1
    //         004b37fc     JNZ        LAB_004b37a5
    //                               LAB_004b37fe                                                 XREF[1]:     004b37a3(j)  
    //                              scr_sedo.cpp:139 (34)
    //         004b37fe     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004b3804     LEA        EAX=>file_name[4],[ESP + 0x10]
    //         004b3808     MOV        EDX,dword ptr [ECX + this->_padding_]
    //         004b380b     ADD        EDX,0xc17
    //         004b3811     PUSH       EDX
    //         004b3812     PUSH       s_%s*.scx                                        = "%s*.scx"
    //         004b3817     PUSH       EAX
    //         004b3818     CALL       sprintf                                          undefined sprintf()
    //         004b381d     ADD        ESP,0xc
    //                              scr_sedo.cpp:140 (23)
    //         004b3820     LEA        this=>fileInfo.time_create,[ESP + 0x114]
    //         004b3827     LEA        EDX=>file_name[4],[ESP + 0x10]
    //         004b382b     PUSH       this
    //         004b382c     PUSH       EDX
    //         004b382d     CALL       __findfirst                                      undefined __findfirst()
    //         004b3832     MOV        EBX,EAX
    //         004b3834     ADD        ESP,0x8
    //                              scr_sedo.cpp:141 (5)
    //         004b3837     CMP        EBX,-0x1
    //         004b383a     JZ         LAB_004b3895
    //                               LAB_004b383c                                                 XREF[1]:     004b3893(j)  
    //                              scr_sedo.cpp:142 (17)
    //         004b383c     LEA        EDI=>fileInfo+0x18,[ESP + 0x128]
    //         004b3843     OR         this,0xffffffff
    //         004b3846     XOR        EAX,EAX
    //         004b3848     SCASB.RE   ES:EDI
    //         004b384a     NOT        this
    //         004b384c     DEC        this
    //                              scr_sedo.cpp:143 (24)
    //         004b384d     LEA        EAX=>fileInfo+0x18,[ESP + 0x128]
    //         004b3854     MOV        ESI,this
    //         004b3856     LEA        this=>file_name[4],[ESP + 0x10]
    //         004b385a     SUB        ESI,0x4
    //         004b385d     PUSH       ESI
    //         004b385e     PUSH       EAX
    //         004b385f     PUSH       this
    //         004b3860     CALL       strncpy                                          undefined strncpy()
    //                              scr_sedo.cpp:145 (26)
    //         004b3865     MOV        this,dword ptr [EBP + 0x47c]
    //         004b386b     ADD        ESP,0xc
    //         004b386e     LEA        EDX=>file_name[4],[ESP + 0x10]
    //         004b3872     MOV        byte ptr [ESP + ESI*0x1 + 0x10],0x0
    //         004b3877     PUSH       0x0
    //         004b3879     PUSH       EDX
    //         004b387a     CALL       TTextPanel::append_line                          int append_line(TTextPanel * this, char * par
    //                              scr_sedo.cpp:146 (22)
    //         004b387f     LEA        EAX=>fileInfo.time_create,[ESP + 0x114]
    //         004b3886     PUSH       EAX
    //         004b3887     PUSH       EBX
    //         004b3888     CALL       __findnext                                       undefined __findnext()
    //         004b388d     ADD        ESP,0x8
    //         004b3890     CMP        EAX,-0x1
    //         004b3893     JNZ        LAB_004b383c
    //                               LAB_004b3895                                                 XREF[1]:     004b383a(j)  
    //                              scr_sedo.cpp:149 (11)
    //         004b3895     POP        EDI
    //         004b3896     POP        ESI
    //         004b3897     POP        EBP
    //         004b3898     POP        EBX
    //         004b3899     ADD        ESP,0x21c
    //         004b389f     RET
    //                              * protected: virtual long __thiscall TRIBE_Screen_Sed_Open::action(class TPanel *,long,unsigned long... *
    //                              long __thiscall action(TRIBE_Screen_Sed_Open * this, TPanel * param_
    //              long              EAX:4          <RETURN>
    //              TRIBE_Screen_S    ECX:4 (auto)   this
    //              TPanel *          Stack[0x4]:4   param_1                   XREF[1]:     004b38c4(R)  
    //              long              Stack[0x8]:4   param_2                   XREF[2]:     004b38bc(R), 004b3932(R)  
    //              ulong             Stack[0xc]:4   param_3                   XREF[1]:     004b3c5e(R)  
    //              ulong             Stack[0x10]:4  param_4                   XREF[1]:     004b3c57(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     004b3c11(W), 004b3c27(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     004b3c70(R)  
    //              char[556]         Stack[-0x23c   text                      XREF[0,2]:   004b3a47(*), 004b3a58(*)  
    //              char[257]         Stack[-0x340   fileName                  XREF[0,6]:   004b3ae5(*), 004b3b04(*), 004b3b48(*), 004b3b61(*), 
    //                                                                                     004b3b87(*), 004b3b9d(*)  
    //              _OFSTRUCT         Stack[-0x440   of                        XREF[1,8]:   004b3c0b(W), 004b395c(*), 004b396e(*), 004b3996(*), 
    //                                                                                     004b39a8(*), 004b3a21(*), 004b3a42(*), 004b3b00(*), 
    //                                                                                     004b3b5d(*)  
    //                               ?action@TRIBE_Screen_Sed_Open@@MAEJPAVTPanel@@JKK@Z          XREF[1]:     00573cdc(*)  
    //                               TRIBE_Screen_Sed_Open::action
    //                              scr_sedo.cpp:155 (28)
    //         004b38a0     MOV        EAX,FS:[0x0]
    //         004b38a6     PUSH       -0x1
    //         004b38a8     PUSH       FUN_0055f61e
    //         004b38ad     PUSH       EAX
    //         004b38ae     MOV        dword ptr FS:[0x0],ESP
    //         004b38b5     SUB        ESP,0x434
    //         004b38bb     PUSH       EBX
    //                              scr_sedo.cpp:156 (27)
    //         004b38bc     MOV        EBX,dword ptr [ESP + param_2]
    //         004b38c3     PUSH       EBP
    //         004b38c4     MOV        EBP,dword ptr [ESP + param_1]
    //         004b38cb     PUSH       ESI
    //         004b38cc     PUSH       EDI
    //         004b38cd     TEST       EBP,EBP
    //         004b38cf     MOV        ESI,this
    //         004b38d1     JZ         LAB_004b3c57
    //                              scr_sedo.cpp:157 (76)
    //         004b38d7     MOV        this,EBP
    //         004b38d9     CALL       TPanel::panelName                                char * panelName(TPanel * this)
    //         004b38de     TEST       EAX,EAX
    //         004b38e0     JZ         LAB_004b3a04
    //         004b38e6     MOV        this,EBP
    //         004b38e8     MOV        EDI,s_Cancel_Dialog                              = 43h
    //         004b38ed     CALL       TPanel::panelName                                char * panelName(TPanel * this)
    //                               LAB_004b38f2                                                 XREF[1]:     004b3910(j)  
    //         004b38f2     MOV        DL,byte ptr [EAX]
    //         004b38f4     MOV        this,DL
    //         004b38f6     CMP        DL,byte ptr [EDI]=>s_Cancel_Dialog               = 43h
    //                                                                                  = 6Eh
    //         004b38f8     JNZ        LAB_004b3916
    //         004b38fa     TEST       this,this
    //         004b38fc     JZ         LAB_004b3912
    //         004b38fe     MOV        DL,byte ptr [EAX + 0x1]
    //         004b3901     MOV        this,DL
    //         004b3903     CMP        DL,byte ptr [EDI + 0x1]=>DAT_005860e5            = 61h
    //                                                                                  = "cel Dialog"
    //         004b3906     JNZ        LAB_004b3916
    //         004b3908     ADD        EAX,0x2
    //         004b390b     ADD        EDI,0x2
    //         004b390e     TEST       this,this
    //         004b3910     JNZ        LAB_004b38f2
    //                               LAB_004b3912                                                 XREF[1]:     004b38fc(j)  
    //         004b3912     XOR        EAX,EAX
    //         004b3914     JMP        LAB_004b391b
    //                               LAB_004b3916                                                 XREF[2]:     004b38f8(j), 004b3906(j)  
    //         004b3916     SBB        EAX,EAX
    //         004b3918     SBB        EAX,-0x1
    //                               LAB_004b391b                                                 XREF[1]:     004b3914(j)  
    //         004b391b     TEST       EAX,EAX
    //         004b391d     JNZ        LAB_004b3a04
    //                              scr_sedo.cpp:159 (15)
    //         004b3923     PUSH       s_Cancel_Dialog                                  = 43h
    //         004b3928     MOV        this,panel_system
    //         004b392d     CALL       TPanelSystem::destroyPanel                       int destroyPanel(TPanelSystem * this, char * 
    //                              scr_sedo.cpp:161 (15)
    //         004b3932     MOV        EAX,dword ptr [ESP + param_2]
    //         004b3939     TEST       EAX,EAX
    //         004b393b     JNZ        LAB_004b3c50
    //                              scr_sedo.cpp:166 (45)
    //         004b3941     MOV        EAX,[rge_base_game]                              = 00000000
    //         004b3946     MOV        this,dword ptr [ESI + 0x47c]
    //         004b394c     MOV        EDI,dword ptr [EAX + 0xc]
    //         004b394f     ADD        EDI,0xc17
    //         004b3955     CALL       TTextPanel::currentLine                          char * currentLine(TTextPanel * this)
    //         004b395a     PUSH       EAX
    //         004b395b     PUSH       EDI
    //         004b395c     LEA        this=>of.Reserved1,[ESP + 0x1c]
    //         004b3960     PUSH       s_%s%s.scn                                       = "%s%s.scn"
    //         004b3965     PUSH       this
    //         004b3966     CALL       sprintf                                          undefined sprintf()
    //         004b396b     ADD        ESP,0x10
    //                              scr_sedo.cpp:167 (10)
    //         004b396e     LEA        EDX=>of.Reserved1,[ESP + 0x14]
    //         004b3972     PUSH       EDX
    //         004b3973     CALL       __unlink                                         undefined __unlink()
    //                              scr_sedo.cpp:169 (48)
    //         004b3978     MOV        EAX,[rge_base_game]                              = 00000000
    //         004b397d     MOV        this,dword ptr [ESI + 0x47c]
    //         004b3983     ADD        ESP,0x4
    //         004b3986     MOV        EDI,dword ptr [EAX + 0xc]
    //         004b3989     ADD        EDI,0xc17
    //         004b398f     CALL       TTextPanel::currentLine                          char * currentLine(TTextPanel * this)
    //         004b3994     PUSH       EAX
    //         004b3995     PUSH       EDI
    //         004b3996     LEA        this=>of.Reserved1,[ESP + 0x1c]
    //         004b399a     PUSH       s_%s%s.scx                                       = "%s%s.scx"
    //         004b399f     PUSH       this
    //         004b39a0     CALL       sprintf                                          undefined sprintf()
    //         004b39a5     ADD        ESP,0x10
    //                              scr_sedo.cpp:170 (10)
    //         004b39a8     LEA        EDX=>of.Reserved1,[ESP + 0x14]
    //         004b39ac     PUSH       EDX
    //         004b39ad     CALL       __unlink                                         undefined __unlink()
    //                              scr_sedo.cpp:173 (26)
    //         004b39b2     MOV        this,dword ptr [ESI + 0x47c]
    //         004b39b8     ADD        ESP,0x4
    //         004b39bb     CALL       TTextPanel::get_line                             long get_line(TTextPanel * this)
    //         004b39c0     MOV        this,dword ptr [ESI + 0x47c]
    //         004b39c6     PUSH       EAX
    //         004b39c7     CALL       TTextPanel::delete_line                          int delete_line(TTextPanel * this, long param
    //                              scr_sedo.cpp:174 (20)
    //         004b39cc     MOV        this,dword ptr [ESI + 0x47c]
    //         004b39d2     CALL       TTextPanel::currentLine                          char * currentLine(TTextPanel * this)
    //         004b39d7     CMP        byte ptr [EAX],0x0
    //         004b39da     JNZ        LAB_004b3c50
    //                              scr_sedo.cpp:176 (13)
    //         004b39e0     MOV        this,dword ptr [ESI + 0x484]
    //         004b39e6     PUSH       0x1
    //         004b39e8     CALL       TButtonPanel::set_disabled                       void set_disabled(TButtonPanel * this, int pa
    //                              scr_sedo.cpp:177 (13)
    //         004b39ed     MOV        this,dword ptr [ESI + 0x48c]
    //         004b39f3     PUSH       0x1
    //         004b39f5     CALL       TButtonPanel::set_disabled                       void set_disabled(TButtonPanel * this, int pa
    //                              scr_sedo.cpp:181 (10)
    //         004b39fa     MOV        EAX,0x1
    //         004b39ff     JMP        LAB_004b3c70
    //                               LAB_004b3a04                                                 XREF[2]:     004b38e0(j), 004b391d(j)  
    //                              scr_sedo.cpp:183 (13)
    //         004b3a04     CMP        EBP,dword ptr [ESI + 0x48c]
    //         004b3a0a     JNZ        LAB_004b3a73
    //         004b3a0c     CMP        EBX,0x1
    //         004b3a0f     JNZ        LAB_004b3a73
    //                              scr_sedo.cpp:187 (16)
    //         004b3a11     MOV        this,dword ptr [ESI + 0x47c]
    //         004b3a17     CALL       TTextPanel::currentLine                          char * currentLine(TTextPanel * this)
    //         004b3a1c     CMP        byte ptr [EAX],0x0
    //         004b3a1f     JZ         LAB_004b3a73
    //                              scr_sedo.cpp:189 (22)
    //         004b3a21     LEA        EAX=>of.Reserved1,[ESP + 0x14]
    //         004b3a25     PUSH       0x100
    //         004b3a2a     PUSH       EAX
    //                              language.dll match for 0x24ca: "Are you sure you want to dele
    //         004b3a2b     PUSH       0x24ca
    //         004b3a30     MOV        this,ESI
    //         004b3a32     CALL       TPanel::get_string                               int get_string(TPanel * this, int param_1, ch
    //                              scr_sedo.cpp:190 (33)
    //         004b3a37     MOV        this,dword ptr [ESI + 0x47c]
    //         004b3a3d     CALL       TTextPanel::currentLine                          char * currentLine(TTextPanel * this)
    //         004b3a42     LEA        this=>of.Reserved1,[ESP + 0x14]
    //         004b3a46     PUSH       EAX
    //         004b3a47     LEA        EDX=>text[4],[ESP + 0x21c]
    //         004b3a4e     PUSH       this
    //         004b3a4f     PUSH       EDX
    //         004b3a50     CALL       sprintf                                          undefined sprintf()
    //         004b3a55     ADD        ESP,0xc
    //                              scr_sedo.cpp:191 (27)
    //         004b3a58     LEA        EAX=>text[4],[ESP + 0x218]
    //         004b3a5f     MOV        this,ESI
    //         004b3a61     PUSH       0x64
    //         004b3a63     PUSH       0x1c2
    //         004b3a68     PUSH       s_Cancel_Dialog                                  = 43h
    //         004b3a6d     PUSH       EAX
    //         004b3a6e     CALL       TEasy_Panel::popupYesNoDialog                    void popupYesNoDialog(TEasy_Panel * this, cha
    //                               LAB_004b3a73                                                 XREF[3]:     004b3a0a(j), 004b3a0f(j), 
    //                                                                                                         004b3a1f(j)  
    //                              scr_sedo.cpp:194 (10)
    //         004b3a73     MOV        this,dword ptr [ESI + 0x47c]
    //         004b3a79     CMP        EBP,this
    //         004b3a7b     JNZ        LAB_004b3aa7
    //                              scr_sedo.cpp:195 (9)
    //         004b3a7d     CMP        EBX,0x3
    //         004b3a80     JNZ        LAB_004b3c57
    //                              scr_sedo.cpp:196 (23)
    //         004b3a86     MOV        EAX,dword ptr [ESI + 0x484]
    //         004b3a8c     MOV        EDX,dword ptr [ESI]
    //         004b3a8e     PUSH       0x0
    //         004b3a90     PUSH       0x0
    //         004b3a92     PUSH       0x1
    //         004b3a94     PUSH       EAX
    //         004b3a95     MOV        this,ESI
    //         004b3a97     CALL       dword ptr [EDX + 0xb4]
    //                              scr_sedo.cpp:197 (10)
    //         004b3a9d     MOV        EAX,0x1
    //         004b3aa2     JMP        LAB_004b3c70
    //                               LAB_004b3aa7                                                 XREF[1]:     004b3a7b(j)  
    //                              scr_sedo.cpp:200 (12)
    //         004b3aa7     CMP        EBP,dword ptr [ESI + 0x484]
    //         004b3aad     JNZ        LAB_004b3bd5
    //                              scr_sedo.cpp:201 (9)
    //         004b3ab3     CMP        EBX,0x1
    //         004b3ab6     JNZ        LAB_004b3c57
    //                              scr_sedo.cpp:202 (13)
    //         004b3abc     CALL       TTextPanel::numberLines                          int numberLines(TTextPanel * this)
    //         004b3ac1     TEST       EAX,EAX
    //         004b3ac3     JLE        LAB_004b3c50
    //                              scr_sedo.cpp:205 (46)
    //         004b3ac9     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004b3acf     MOV        EDI,dword ptr [ECX + this->_padding_]
    //         004b3ad2     MOV        this,dword ptr [ESI + 0x47c]
    //         004b3ad8     ADD        EDI,0xc17
    //         004b3ade     CALL       TTextPanel::currentLine                          char * currentLine(TTextPanel * this)
    //         004b3ae3     PUSH       EAX
    //         004b3ae4     PUSH       EDI
    //         004b3ae5     LEA        EDX=>fileName[4],[ESP + 0x11c]
    //         004b3aec     PUSH       s_%s%s.scn                                       = "%s%s.scn"
    //         004b3af1     PUSH       EDX
    //         004b3af2     CALL       sprintf                                          undefined sprintf()
    //                              scr_sedo.cpp:209 (34)
    //         004b3af7     MOV        EBX,dword ptr [->KERNEL32.DLL::OpenFile]         = 0048a9e6
    //         004b3afd     ADD        ESP,0x10
    //         004b3b00     LEA        EAX=>of.Reserved1,[ESP + 0x14]
    //         004b3b04     LEA        this=>fileName[4],[ESP + 0x114]
    //         004b3b0b     PUSH       0x4000
    //         004b3b10     PUSH       EAX
    //         004b3b11     PUSH       this
    //         004b3b12     CALL       EBX=>KERNEL32.DLL::OpenFile
    //         004b3b14     CMP        EAX,-0x1
    //         004b3b17     JZ         LAB_004b3b2c
    //                              scr_sedo.cpp:211 (17)
    //         004b3b19     MOV        this,dword ptr [ESI + 0x47c]
    //         004b3b1f     CALL       TTextPanel::currentLine                          char * currentLine(TTextPanel * this)
    //         004b3b24     PUSH       EAX
    //         004b3b25     PUSH       s_%s.scn                                         = "%s.scn"
    //                              scr_sedo.cpp:214 (2)
    //         004b3b2a     JMP        LAB_004b3b87
    //                               LAB_004b3b2c                                                 XREF[1]:     004b3b17(j)  
    //                              scr_sedo.cpp:216 (49)
    //         004b3b2c     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004b3b32     MOV        EDI,dword ptr [ECX + this->_padding_]
    //         004b3b35     MOV        this,dword ptr [ESI + 0x47c]
    //         004b3b3b     ADD        EDI,0xc17
    //         004b3b41     CALL       TTextPanel::currentLine                          char * currentLine(TTextPanel * this)
    //         004b3b46     PUSH       EAX
    //         004b3b47     PUSH       EDI
    //         004b3b48     LEA        EDX=>fileName[4],[ESP + 0x11c]
    //         004b3b4f     PUSH       s_%s%s.scx                                       = "%s%s.scx"
    //         004b3b54     PUSH       EDX
    //         004b3b55     CALL       sprintf                                          undefined sprintf()
    //         004b3b5a     ADD        ESP,0x10
    //                              scr_sedo.cpp:217 (25)
    //         004b3b5d     LEA        EAX=>of.Reserved1,[ESP + 0x14]
    //         004b3b61     LEA        this=>fileName[4],[ESP + 0x114]
    //         004b3b68     PUSH       0x4000
    //         004b3b6d     PUSH       EAX
    //         004b3b6e     PUSH       this
    //         004b3b6f     CALL       EBX=>KERNEL32.DLL::OpenFile
    //         004b3b71     CMP        EAX,-0x1
    //         004b3b74     JZ         LAB_004b3bb6
    //                              scr_sedo.cpp:219 (30)
    //         004b3b76     MOV        this,dword ptr [ESI + 0x47c]
    //         004b3b7c     CALL       TTextPanel::currentLine                          char * currentLine(TTextPanel * this)
    //         004b3b81     PUSH       EAX
    //         004b3b82     PUSH       s_%s.scx                                         = "%s.scx"
    //                               LAB_004b3b87                                                 XREF[1]:     004b3b2a(j)  
    //         004b3b87     LEA        EDX=>fileName[4],[ESP + 0x11c]
    //         004b3b8e     PUSH       EDX
    //         004b3b8f     CALL       sprintf                                          undefined sprintf()
    //                              scr_sedo.cpp:220 (24)
    //         004b3b94     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004b3b9a     ADD        ESP,0xc
    //         004b3b9d     LEA        EAX=>fileName[4],[ESP + 0x114]
    //         004b3ba4     PUSH       0x0
    //         004b3ba6     PUSH       EAX
    //         004b3ba7     CALL       TRIBE_Game::start_scenario_editor                int start_scenario_editor(TRIBE_Game * this, 
    //                              scr_sedo.cpp:239 (10)
    //         004b3bac     MOV        EAX,0x1
    //         004b3bb1     JMP        LAB_004b3c70
    //                               LAB_004b3bb6                                                 XREF[1]:     004b3b74(j)  
    //                              scr_sedo.cpp:223 (21)
    //         004b3bb6     PUSH       0x64
    //         004b3bb8     PUSH       0x1c2
    //         004b3bbd     PUSH       0x0
    //                              language.dll match for 0x24cf: "Cannot load that scenario."
    //         004b3bbf     PUSH       0x24cf
    //         004b3bc4     MOV        this,ESI
    //         004b3bc6     CALL       TEasy_Panel::popupOKDialog                       void popupOKDialog(TEasy_Panel * this, long p
    //                              scr_sedo.cpp:226 (10)
    //         004b3bcb     MOV        EAX,0x1
    //         004b3bd0     JMP        LAB_004b3c70
    //                               LAB_004b3bd5                                                 XREF[1]:     004b3aad(j)  
    //                              scr_sedo.cpp:229 (8)
    //         004b3bd5     CMP        EBP,dword ptr [ESI + 0x488]
    //         004b3bdb     JNZ        LAB_004b3c57
    //                              scr_sedo.cpp:230 (5)
    //         004b3bdd     CMP        EBX,0x1
    //         004b3be0     JNZ        LAB_004b3c57
    //                              scr_sedo.cpp:231 (19)
    //         004b3be2     PUSH       s_Scenario_Editor_Screen                         = "Scenario Editor Screen"
    //         004b3be7     MOV        this,panel_system
    //         004b3bec     CALL       TPanelSystem::panel                              TPanel * panel(TPanelSystem * this, char * pa
    //         004b3bf1     TEST       EAX,EAX
    //         004b3bf3     JZ         LAB_004b3bfe
    //                              scr_sedo.cpp:232 (7)
    //         004b3bf5     PUSH       0x0
    //         004b3bf7     PUSH       s_Scenario_Editor_Screen                         = "Scenario Editor Screen"
    //                              scr_sedo.cpp:233 (2)
    //         004b3bfc     JMP        LAB_004b3c37
    //                               LAB_004b3bfe                                                 XREF[1]:     004b3bf3(j)  
    //                              scr_sedo.cpp:235 (39)
    //         004b3bfe     PUSH       0x490
    //         004b3c03     CALL       operator_new                                     void * operator_new(uint param_1)
    //         004b3c08     ADD        ESP,0x4
    //         004b3c0b     MOV        dword ptr [ESP + of.cBytes],EAX
    //         004b3c0f     TEST       EAX,EAX
    //         004b3c11     MOV        dword ptr [ESP + local_4],0x0
    //         004b3c1c     JZ         LAB_004b3c25
    //         004b3c1e     MOV        this,EAX
    //         004b3c20     CALL       TRIBE_Screen_Sed_Menu::TRIBE_Screen_Sed_Menu     undefined TRIBE_Screen_Sed_Menu(TRIBE_Screen_
    //                               LAB_004b3c25                                                 XREF[1]:     004b3c1c(j)  
    //                              scr_sedo.cpp:236 (28)
    //         004b3c25     PUSH       0x0
    //         004b3c27     MOV        dword ptr [ESP + local_4],0xffffffff
    //         004b3c32     PUSH       s_Scenario_Editor_Menu                           = "Scenario Editor Menu"
    //                               LAB_004b3c37                                                 XREF[1]:     004b3bfc(j)  
    //         004b3c37     MOV        this,panel_system
    //         004b3c3c     CALL       TPanelSystem::setCurrentPanel                    int setCurrentPanel(TPanelSystem * this, char
    //                              scr_sedo.cpp:238 (15)
    //         004b3c41     PUSH       s_Scenario_Editor_Open                           = "Scenario Editor Open"
    //         004b3c46     MOV        this,panel_system
    //         004b3c4b     CALL       TPanelSystem::destroyPanel                       int destroyPanel(TPanelSystem * this, char * 
    //                               LAB_004b3c50                                                 XREF[3]:     004b393b(j), 004b39da(j), 
    //                                                                                                         004b3ac3(j)  
    //                              scr_sedo.cpp:239 (7)
    //         004b3c50     MOV        EAX,0x1
    //         004b3c55     JMP        LAB_004b3c70
    //                               LAB_004b3c57                                                 XREF[5]:     004b38d1(j), 004b3a80(j), 
    //                                                                                                         004b3ab6(j), 004b3bdb(j), 
    //                                                                                                         004b3be0(j)  
    //                              scr_sedo.cpp:244 (25)
    //         004b3c57     MOV        this,dword ptr [ESP + param_4]
    //         004b3c5e     MOV        EDX,dword ptr [ESP + param_3]
    //         004b3c65     PUSH       this
    //         004b3c66     PUSH       EDX
    //         004b3c67     PUSH       EBX
    //         004b3c68     PUSH       EBP
    //         004b3c69     MOV        this,ESI
    //         004b3c6b     CALL       TEasy_Panel::action                              long action(TEasy_Panel * this, TPanel * para
    //                               LAB_004b3c70                                                 XREF[5]:     004b39ff(j), 004b3aa2(j), 
    //                                                                                                         004b3bb1(j), 004b3bd0(j), 
    //                                                                                                         004b3c55(j)  
    //                              scr_sedo.cpp:245 (27)
    //         004b3c70     MOV        this,dword ptr [ESP + local_c]
    //         004b3c77     POP        EDI
    //         004b3c78     POP        ESI
    //         004b3c79     POP        EBP
    //         004b3c7a     MOV        dword ptr FS:[0x0],this
    //         004b3c81     POP        EBX
    //         004b3c82     ADD        ESP,0x440
    //         004b3c88     RET        0x10
    //         004b3c8b     ??         90h
    //         004b3c8c     NOP
    //         004b3c8d     NOP
    //         004b3c8e     NOP
    //         004b3c8f     NOP
    return;
}

long TRIBE_Screen_Sed_Open::action(TPanel* param_1, long param_2, ulong param_3, ulong param_4) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return 0;
}

