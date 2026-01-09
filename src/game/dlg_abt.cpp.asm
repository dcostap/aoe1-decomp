#include "common.h"
#include "dlg_abt.h"

TribeAboutDialog::TribeAboutDialog(TScreenPanel* param_1) {
    /* TODO: Stub */
    //                              undefined __thiscall TribeAboutDialog(TribeAboutDialog * this, TScre
    //              undefined         <UNASSIGNED>   <RETURN>
    //              TribeAboutDial    ECX:4 (auto)   this
    //              TScreenPanel *    Stack[0x4]:4   param_1                   XREF[1]:     0043ada3(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     0043adbc(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     0043b2bf(R)  
    //              char[4096]        Stack[-0x101   str
    //              char[512]         Stack[-0x121   temp_str                  XREF[1]:     0043ad9a(W)  
    //              tagRECT           Stack[-0x122   rect
    //              TPanel *[2]       Stack[-0x123   tabList
    //                               ??0TribeAboutDialog@@QAE@PAVTScreenPanel@@@Z                 XREF[1]:     action:0043fa8d(c)  
    //                               TribeAboutDialog::TribeAboutDialog
    //                              dlg_abt.cpp:46 (51)
    //         0043ad70     PUSH       -0x1
    //         0043ad72     MOV        EAX,FS:[0x0]
    //         0043ad78     PUSH       FUN_0055cf89
    //         0043ad7d     PUSH       EAX
    //         0043ad7e     MOV        EAX,0x1220
    //         0043ad83     MOV        dword ptr FS:[0x0],ESP
    //         0043ad8a     CALL       __alloca_probe                                   undefined __alloca_probe()
    //         0043ad8f     PUSH       EBX
    //         0043ad90     PUSH       EBP
    //         0043ad91     PUSH       ESI
    //         0043ad92     PUSH       EDI
    //         0043ad93     MOV        EBP,this
    //         0043ad95     PUSH       s_About_Dialog                                   = "About Dialog"
    //         0043ad9a     MOV        dword ptr [ESP + temp_str[0]],EBP
    //         0043ad9e     CALL       TDialogPanel::TDialogPanel                       undefined TDialogPanel(TDialogPanel * this, c
    //                              dlg_abt.cpp:64 (157)
    //         0043ada3     MOV        ESI,dword ptr [ESP + param_1]
    //         0043adaa     LEA        EBX,[EBP + 0x498]
    //         0043adb0     LEA        EDI,[EBP + 0x4b4]
    //         0043adb6     XOR        EAX,EAX
    //         0043adb8     PUSH       0x1
    //         0043adba     MOV        this,ESI
    //         0043adbc     MOV        dword ptr [ESP + local_4],EAX
    //         0043adc3     MOV        dword ptr [EBP],TribeAboutDialog::`vftable'      = 0043b2e0
    //         0043adca     MOV        dword ptr [EBP + 0x490],EAX
    //         0043add0     MOV        dword ptr [EBP + 0x494],EAX
    //         0043add6     MOV        dword ptr [EBX],EAX
    //         0043add8     MOV        dword ptr [EBP + 0x49c],EAX
    //         0043adde     MOV        dword ptr [EBP + 0x4a0],EAX
    //         0043ade4     MOV        dword ptr [EBP + 0x4a4],EAX
    //         0043adea     MOV        dword ptr [EBP + 0x4a8],EAX
    //         0043adf0     MOV        dword ptr [EBP + 0x4ac],EAX
    //         0043adf6     MOV        dword ptr [EBP + 0x4b0],EAX
    //         0043adfc     MOV        dword ptr [EBP + 0x4b8],EAX
    //         0043ae02     MOV        dword ptr [EBP + 0x4bc],EAX
    //         0043ae08     MOV        dword ptr [EBP + 0x4c0],EAX
    //         0043ae0e     MOV        dword ptr [EDI],EAX
    //         0043ae10     CALL       TEasy_Panel::get_popup_info_id                   long get_popup_info_id(TEasy_Panel * this)
    //         0043ae15     PUSH       EAX
    //         0043ae16     MOV        this,ESI
    //         0043ae18     CALL       TEasy_Panel::get_popup_info_file                 char * get_popup_info_file(TEasy_Panel * this)
    //         0043ae1d     PUSH       EAX
    //         0043ae1e     PUSH       0x19c
    //         0043ae23     PUSH       0x208
    //         0043ae28     PUSH       ESI
    //         0043ae29     MOV        this,ESI
    //         0043ae2b     CALL       TPanel::renderArea                               TDrawArea * renderArea(TPanel * this)
    //         0043ae30     PUSH       EAX
    //         0043ae31     MOV        this,EBP
    //         0043ae33     CALL       TDialogPanel::setup                              int setup(TDialogPanel * this, TDrawArea * pa
    //         0043ae38     TEST       EAX,EAX
    //         0043ae3a     JZ         LAB_0043b2bf
    //                              dlg_abt.cpp:67 (36)
    //         0043ae40     PUSH       0x0
    //         0043ae42     PUSH       0x0
    //         0043ae44     PUSH       0x0
    //         0043ae46     PUSH       0x4
    //         0043ae48     PUSH       0x15e
    //         0043ae4d     PUSH       0x1f4
    //         0043ae52     PUSH       0xa
    //         0043ae54     PUSH       0xa
    //         0043ae56     PUSH       s_                                               = ""
    //         0043ae5b     PUSH       EDI
    //         0043ae5c     PUSH       EBP
    //         0043ae5d     MOV        this,EBP
    //         0043ae5f     CALL       TEasy_Panel::create_text                         int create_text(TEasy_Panel * this, TPanel * 
    //                              dlg_abt.cpp:68 (68)
    //         0043ae64     XOR        this,this
    //         0043ae66     XOR        EDX,EDX
    //         0043ae68     MOV        this,byte ptr [EBP + 0x325]
    //         0043ae6e     MOV        DL,byte ptr [EBP + 0x324]
    //         0043ae74     MOV        EDI,dword ptr [EDI]
    //         0043ae76     PUSH       this
    //         0043ae77     PUSH       EDX
    //         0043ae78     XOR        this,this
    //         0043ae7a     MOV        this,byte ptr [EBP + 0x323]
    //         0043ae80     XOR        EDX,EDX
    //         0043ae82     MOV        DL,byte ptr [EBP + 0x322]
    //         0043ae88     MOV        EAX,dword ptr [EDI]
    //         0043ae8a     PUSH       this
    //         0043ae8b     PUSH       EDX
    //         0043ae8c     XOR        this,this
    //         0043ae8e     XOR        EDX,EDX
    //         0043ae90     MOV        this,byte ptr [EBP + 0x321]
    //         0043ae96     MOV        DL,byte ptr [EBP + 0x320]
    //         0043ae9c     PUSH       this
    //         0043ae9d     PUSH       EDX
    //         0043ae9e     PUSH       0x3
    //         0043aea0     MOV        this,EDI
    //         0043aea2     CALL       dword ptr [EAX + 0xec]
    //                              dlg_abt.cpp:73 (39)
    //         0043aea8     PUSH       0x0
    //         0043aeaa     PUSH       0x0=>DAT_fffffff8
    //         0043aeac     PUSH       0x0=>DAT_fffffff4
    //         0043aeae     PUSH       offset DAT_fffffff0
    //         0043aeb0     PUSH       0x14
    //         0043aeb2     PUSH       0x1e0
    //         0043aeb7     PUSH       0x14
    //         0043aeb9     PUSH       0x14
    //         0043aebb     LEA        EAX,[EBP + 0x490]
    //                              language.dll match for 0x2419: "Microsoft\\xAE Age of Empires
    //                              language.dll match for 0x2419: "Microsoft\\xA9 Age of Empires
    //         0043aec1     PUSH       0x2419
    //         0043aec6     PUSH       EAX
    //         0043aec7     PUSH       EBP
    //         0043aec8     MOV        this,EBP
    //         0043aeca     CALL       TEasy_Panel::create_text                         int create_text(TEasy_Panel * this, TPanel * 
    //                              dlg_abt.cpp:76 (39)
    //         0043aecf     PUSH       0x0
    //         0043aed1     PUSH       0x0=>DAT_fffffff8
    //         0043aed3     PUSH       0x0=>DAT_fffffff4
    //         0043aed5     PUSH       offset DAT_fffffff0
    //         0043aed7     PUSH       0x14
    //         0043aed9     PUSH       0x1e0
    //         0043aede     PUSH       0x28
    //         0043aee0     PUSH       0x14
    //         0043aee2     LEA        EAX,[EBP + 0x494]
    //                              language.dll match for 0x241a: "Version 1.0"
    //                              language.dll match for 0x241a: "Version 1.0b"
    //         0043aee8     PUSH       0x241a
    //         0043aeed     PUSH       EAX
    //         0043aeee     PUSH       EBP
    //         0043aeef     MOV        this,EBP
    //         0043aef1     CALL       TEasy_Panel::create_text                         int create_text(TEasy_Panel * this, TPanel * 
    //                              dlg_abt.cpp:79 (22)
    //         0043aef6     LEA        EAX,[ESP + 0x30]
    //         0043aefa     PUSH       0x200
    //         0043aeff     PUSH       EAX=>DAT_fffffff8
    //         0043af00     PUSH       offset DAT_fffffff4
    //         0043af05     MOV        this,EBP
    //         0043af07     CALL       TPanel::get_string                               int get_string(TPanel * this, int param_1, ch
    //                              dlg_abt.cpp:80 (12)
    //         0043af0c     MOV        AL,byte ptr [ESP + 0x30]
    //         0043af10     TEST       AL,AL
    //         0043af12     JNZ        LAB_0043b00a
    //                              dlg_abt.cpp:82 (33)
    //         0043af18     PUSH       0x0
    //         0043af1a     PUSH       0x0=>DAT_fffffff8
    //         0043af1c     PUSH       0x0=>DAT_fffffff4
    //         0043af1e     PUSH       offset DAT_fffffff0
    //         0043af20     PUSH       0x14
    //         0043af22     PUSH       0x1e0
    //         0043af27     PUSH       0x41
    //         0043af29     PUSH       0x14
    //                              language.dll match for 0x241b: "\\xA9 & "
    //         0043af2b     PUSH       0x241b
    //         0043af30     PUSH       EBX
    //         0043af31     PUSH       EBP
    //         0043af32     MOV        this,EBP
    //         0043af34     CALL       TEasy_Panel::create_text                         int create_text(TEasy_Panel * this, TPanel * 
    //                              dlg_abt.cpp:83 (10)
    //         0043af39     MOV        EBX,dword ptr [EBX]
    //         0043af3b     TEST       EBX,EBX
    //         0043af3d     JZ         LAB_0043b0f1
    //                              dlg_abt.cpp:85 (20)
    //         0043af43     LEA        this,[ESP + 0x18]
    //         0043af47     PUSH       this
    //         0043af48     MOV        this,EBX
    //         0043af4a     CALL       TTextPanel::get_text_rect                        int get_text_rect(TTextPanel * this, tagRECT 
    //         0043af4f     TEST       EAX,EAX
    //         0043af51     JZ         LAB_0043b0f1
    //                              dlg_abt.cpp:87 (40)
    //         0043af57     PUSH       0x11c
    //         0043af5c     CALL       operator_new                                     void * operator_new(uint param_1)
    //         0043af61     ADD        ESP,0x4
    //         0043af64     MOV        dword ptr [ESP + 0x28],EAX
    //         0043af68     TEST       EAX,EAX
    //         0043af6a     MOV        byte ptr [ESP + 0x1238],0x1
    //         0043af72     JZ         LAB_0043af7d
    //         0043af74     MOV        this,EAX
    //         0043af76     CALL       TPicturePanel::TPicturePanel                     undefined TPicturePanel(TPicturePanel * this)
    //         0043af7b     JMP        LAB_0043af7f
    //                               LAB_0043af7d                                                 XREF[1]:     0043af72(j)  
    //         0043af7d     XOR        EAX,EAX
    //                               LAB_0043af7f                                                 XREF[1]:     0043af7b(j)  
    //                              dlg_abt.cpp:88 (22)
    //         0043af7f     TEST       EAX,EAX
    //         0043af81     MOV        byte ptr [ESP + 0x1238],0x0
    //         0043af89     MOV        dword ptr [EBP + 0x4c0],EAX
    //         0043af8f     JZ         LAB_0043b0f1
    //                              dlg_abt.cpp:90 (45)
    //         0043af95     MOV        EDX,dword ptr [ESP + 0x20]
    //         0043af99     MOV        this,dword ptr [EBP + 0xc]
    //         0043af9c     PUSH       0x1
    //         0043af9e     PUSH       0x0=>DAT_fffffff8
    //         0043afa0     PUSH       offset DAT_fffffff4
    //         0043afa5     PUSH       s_circlep                                        = "circlep"
    //         0043afaa     SUB        EDX,this
    //         0043afac     MOV        this,dword ptr [EBP + 0x20]
    //         0043afaf     PUSH       0xe
    //         0043afb1     PUSH       0xf
    //         0043afb3     ADD        EDX,0x3
    //         0043afb6     PUSH       0x42
    //         0043afb8     PUSH       EDX
    //         0043afb9     PUSH       EBP
    //         0043afba     PUSH       this
    //         0043afbb     MOV        this,EAX
    //         0043afbd     CALL       TPicturePanel::setup                             long setup(TPicturePanel * this, TDrawArea * 
    //                              dlg_abt.cpp:91 (67)
    //         0043afc2     MOV        this,dword ptr [EBP + 0x4c0]
    //         0043afc8     PUSH       0x0
    //         0043afca     PUSH       0x0=>DAT_fffffff8
    //         0043afcc     PUSH       0x0=>DAT_fffffff4
    //         0043afce     PUSH       offset DAT_fffffff0
    //         0043afd0     PUSH       0x14
    //         0043afd2     PUSH       0x1e0
    //         0043afd7     PUSH       0x41
    //         0043afd9     CALL       TPanel::xPosition                                long xPosition(TPanel * this)
    //         0043afde     MOV        this,dword ptr [EBP + 0x4c0]
    //         0043afe4     MOV        ESI,EAX
    //         0043afe6     SUB        ESI,dword ptr [EBP + 0xc]
    //         0043afe9     CALL       TPanel::width                                    long width(TPanel * this)
    //         0043afee     ADD        ESI,EAX
    //         0043aff0     LEA        EAX,[EBP + 0x49c]
    //         0043aff6     PUSH       ESI
    //                              language.dll match for 0x241c: "1997-1998 Microsoft Corporati
    //                              language.dll match for 0x241c: "1997 Microsoft Corporation. A
    //         0043aff7     PUSH       0x241c
    //         0043affc     PUSH       EAX
    //         0043affd     PUSH       EBP
    //         0043affe     MOV        this,EBP
    //         0043b000     CALL       TEasy_Panel::create_text                         int create_text(TEasy_Panel * this, TPanel * 
    //                              dlg_abt.cpp:96 (5)
    //         0043b005     JMP        LAB_0043b0f1
    //                              language.dll match for 0x241b: "\\xA9 & "
    //                               LAB_0043b00a                                                 XREF[1]:     0043af12(j)  
    //                              dlg_abt.cpp:98 (29)
    //         0043b00a     PUSH       0x241b
    //         0043b00f     MOV        this,EBP
    //         0043b011     CALL       TPanel::get_string                               char * get_string(TPanel * this, int param_1)
    //         0043b016     MOV        EDI,EAX
    //         0043b018     OR         this,0xffffffff
    //         0043b01b     XOR        EAX,EAX
    //         0043b01d     LEA        EDX,[ESP + 0x30]
    //         0043b021     SCASB.RE   ES:EDI
    //         0043b023     NOT        this
    //         0043b025     SUB        EDI,this
    //                              dlg_abt.cpp:99 (47)
    //         0043b027     PUSH       0x2424
    //         0043b02c     MOV        EAX,this
    //         0043b02e     MOV        ESI,EDI
    //         0043b030     MOV        EDI,EDX
    //         0043b032     SHR        this,0x2
    //         0043b035     MOVSD.REP  ES:EDI,ESI
    //         0043b037     MOV        this,EAX
    //         0043b039     AND        this,0x3
    //         0043b03c     MOVSB.REP  ES:EDI,ESI
    //         0043b03e     MOV        this,EBP
    //         0043b040     CALL       TPanel::get_string                               char * get_string(TPanel * this, int param_1)
    //         0043b045     MOV        EDI,EAX
    //         0043b047     OR         this,0xffffffff
    //         0043b04a     XOR        EAX,EAX
    //         0043b04c     LEA        EDX,[ESP + 0x30]
    //         0043b050     SCASB.RE   ES:EDI
    //         0043b052     NOT        this
    //         0043b054     SUB        EDI,this
    //                              dlg_abt.cpp:101 (99)
    //         0043b056     PUSH       0x241c
    //         0043b05b     MOV        ESI,EDI
    //         0043b05d     MOV        EDI,EDX
    //         0043b05f     MOV        EDX,this
    //         0043b061     OR         this,0xffffffff
    //         0043b064     SCASB.RE   ES:EDI
    //         0043b066     MOV        this,EDX
    //         0043b068     DEC        EDI
    //         0043b069     SHR        this,0x2
    //         0043b06c     MOVSD.REP  ES:EDI,ESI
    //         0043b06e     MOV        this,EDX
    //         0043b070     LEA        EDX,[ESP + 0x34]
    //         0043b074     AND        this,0x3
    //         0043b077     MOVSB.REP  ES:EDI,ESI
    //         0043b079     MOV        EDI,s__                                          = 20h
    //         0043b07e     OR         this,0xffffffff
    //         0043b081     SCASB.RE   ES:EDI=>s__                                      = 20h
    //         0043b083     NOT        this
    //         0043b085     SUB        EDI,this
    //         0043b087     MOV        ESI,EDI
    //         0043b089     MOV        EDI,EDX
    //         0043b08b     MOV        EDX,this
    //         0043b08d     OR         this,0xffffffff
    //         0043b090     SCASB.RE   ES:EDI
    //         0043b092     MOV        this,EDX
    //         0043b094     DEC        EDI
    //         0043b095     SHR        this,0x2
    //         0043b098     MOVSD.REP  ES:EDI,ESI
    //         0043b09a     MOV        this,EDX
    //         0043b09c     AND        this,0x3
    //         0043b09f     MOVSB.REP  ES:EDI,ESI
    //         0043b0a1     MOV        this,EBP
    //         0043b0a3     CALL       TPanel::get_string                               char * get_string(TPanel * this, int param_1)
    //         0043b0a8     MOV        EDI,EAX
    //         0043b0aa     OR         this,0xffffffff
    //         0043b0ad     XOR        EAX,EAX
    //         0043b0af     LEA        EDX,[ESP + 0x30]
    //         0043b0b3     SCASB.RE   ES:EDI
    //         0043b0b5     NOT        this
    //         0043b0b7     SUB        EDI,this
    //                              dlg_abt.cpp:102 (56)
    //         0043b0b9     PUSH       EAX
    //         0043b0ba     MOV        ESI,EDI
    //         0043b0bc     MOV        EDI,EDX
    //         0043b0be     MOV        EDX,this
    //         0043b0c0     OR         this,0xffffffff
    //         0043b0c3     SCASB.RE   ES:EDI
    //         0043b0c5     MOV        this,EDX
    //         0043b0c7     DEC        EDI
    //         0043b0c8     SHR        this,0x2
    //         0043b0cb     MOVSD.REP  ES:EDI,ESI
    //         0043b0cd     MOV        this,EDX
    //         0043b0cf     AND        this,0x3
    //         0043b0d2     MOVSB.REP  ES:EDI,ESI
    //         0043b0d4     PUSH       EAX=>DAT_fffffff8
    //         0043b0d5     PUSH       EAX=>DAT_fffffff4
    //         0043b0d6     PUSH       offset DAT_fffffff0
    //         0043b0d8     PUSH       0x14
    //         0043b0da     PUSH       0x1e0
    //         0043b0df     PUSH       0x41
    //         0043b0e1     LEA        EAX,[ESP + 0x4c]
    //         0043b0e5     PUSH       0x14
    //         0043b0e7     PUSH       EAX
    //         0043b0e8     PUSH       EBX
    //         0043b0e9     PUSH       EBP
    //         0043b0ea     MOV        this,EBP
    //         0043b0ec     CALL       TEasy_Panel::create_text                         int create_text(TEasy_Panel * this, TPanel * 
    //                               LAB_0043b0f1                                                 XREF[4]:     0043af3d(j), 0043af51(j), 
    //                                                                                                         0043af8f(j), 0043b005(j)  
    //                              dlg_abt.cpp:105 (39)
    //         0043b0f1     PUSH       0x0
    //         0043b0f3     PUSH       0x0=>DAT_fffffff8
    //         0043b0f5     PUSH       0x0=>DAT_fffffff4
    //         0043b0f7     PUSH       offset DAT_fffffff0
    //         0043b0f9     PUSH       0x14
    //         0043b0fb     PUSH       0x1e0
    //         0043b100     PUSH       0x55
    //         0043b102     PUSH       0x14
    //         0043b104     LEA        EAX,[EBP + 0x4a0]
    //                              language.dll match for 0x241d: "Developed by Ensemble Studios
    //         0043b10a     PUSH       0x241d
    //         0043b10f     PUSH       EAX
    //         0043b110     PUSH       EBP
    //         0043b111     MOV        this,EBP
    //         0043b113     CALL       TEasy_Panel::create_text                         int create_text(TEasy_Panel * this, TPanel * 
    //                              dlg_abt.cpp:107 (39)
    //         0043b118     PUSH       0x1
    //         0043b11a     PUSH       0x0=>DAT_fffffff8
    //         0043b11c     PUSH       0x0=>DAT_fffffff4
    //         0043b11e     PUSH       offset DAT_fffffff0
    //         0043b120     PUSH       0x28
    //         0043b122     PUSH       0x1e0
    //         0043b127     PUSH       0x69
    //         0043b129     PUSH       0x14
    //         0043b12b     LEA        EAX,[EBP + 0x4a4]
    //                              language.dll match for 0x2423: "Genie engine technology \\xA9
    //         0043b131     PUSH       0x2423
    //         0043b136     PUSH       EAX
    //         0043b137     PUSH       EBP
    //         0043b138     MOV        this,EBP
    //         0043b13a     CALL       TEasy_Panel::create_text                         int create_text(TEasy_Panel * this, TPanel * 
    //                              dlg_abt.cpp:110 (39)
    //         0043b13f     PUSH       0x0
    //         0043b141     PUSH       0x0=>DAT_fffffff8
    //         0043b143     PUSH       0x0=>DAT_fffffff4
    //         0043b145     PUSH       offset DAT_fffffff0
    //         0043b147     PUSH       0x14
    //         0043b149     PUSH       0x5f
    //         0043b14b     PUSH       0x96
    //         0043b150     PUSH       0x14
    //         0043b152     LEA        ESI,[EBP + 0x4a8]
    //                              language.dll match for 0x241e: "Product ID:"
    //         0043b158     PUSH       0x241e
    //         0043b15d     PUSH       ESI
    //         0043b15e     PUSH       EBP
    //         0043b15f     MOV        this,EBP
    //         0043b161     CALL       TEasy_Panel::create_text                         int create_text(TEasy_Panel * this, TPanel * 
    //                              dlg_abt.cpp:112 (6)
    //         0043b166     MOV        ESI,dword ptr [ESI]
    //         0043b168     TEST       ESI,ESI
    //         0043b16a     JZ         LAB_0043b1e5
    //                              dlg_abt.cpp:114 (16)
    //         0043b16c     LEA        this,[ESP + 0x18]
    //         0043b170     PUSH       this
    //         0043b171     MOV        this,ESI
    //         0043b173     CALL       TTextPanel::get_text_rect                        int get_text_rect(TTextPanel * this, tagRECT 
    //         0043b178     TEST       EAX,EAX
    //         0043b17a     JZ         LAB_0043b1e5
    //                              dlg_abt.cpp:116 (18)
    //         0043b17c     MOV        this,dword ptr [Regs]                            = 00000000
    //         0043b182     PUSH       s_PID                                            = "PID"
    //         0043b187     PUSH       0x0=>DAT_fffffff8
    //         0043b189     CALL       TRegistry::RegGetAscii                           char * RegGetAscii(TRegistry * this, int para
    //                              dlg_abt.cpp:117 (28)
    //         0043b18e     TEST       EAX,EAX
    //         0043b190     JNZ        LAB_0043b197
    //         0043b192     MOV        EAX,s_00000-000-0000000-00000                    = "00000-000-0000000-00000"
    //                               LAB_0043b197                                                 XREF[1]:     0043b190(j)  
    //         0043b197     PUSH       EAX=>s_00000-000-0000000-00000                   = "00000-000-0000000-00000"
    //         0043b198     LEA        EDX,[ESP + 0x234]
    //         0043b19f     PUSH       s_%s                                             = "%s"
    //         0043b1a4     PUSH       EDX=>DAT_fffffff4
    //         0043b1a5     CALL       sprintf                                          undefined sprintf()
    //                              dlg_abt.cpp:118 (59)
    //         0043b1aa     MOV        EAX,dword ptr [ESP + 0x2c]
    //         0043b1ae     MOV        EBX,dword ptr [EBP + 0xc]
    //         0043b1b1     ADD        ESP,0xc
    //         0043b1b4     SUB        EAX,EBX
    //         0043b1b6     ADD        EAX,0x4
    //         0043b1b9     LEA        this,[ESP + 0x230]
    //         0043b1c0     PUSH       0x0
    //         0043b1c2     PUSH       0x0=>DAT_fffffff8
    //         0043b1c4     PUSH       0x0=>DAT_fffffff4
    //         0043b1c6     PUSH       offset DAT_fffffff0
    //         0043b1c8     PUSH       0x14
    //         0043b1ca     PUSH       0xc8
    //         0043b1cf     PUSH       0x96
    //         0043b1d4     PUSH       EAX
    //         0043b1d5     LEA        EAX,[EBP + 0x4ac]
    //         0043b1db     PUSH       this
    //         0043b1dc     PUSH       EAX
    //         0043b1dd     PUSH       EBP
    //         0043b1de     MOV        this,EBP
    //         0043b1e0     CALL       TEasy_Panel::create_text                         int create_text(TEasy_Panel * this, TPanel * 
    //                               LAB_0043b1e5                                                 XREF[2]:     0043b16a(j), 0043b17a(j)  
    //                              dlg_abt.cpp:123 (25)
    //         0043b1e5     LEA        EDX,[ESP + 0x230]
    //         0043b1ec     PUSH       0x1000
    //         0043b1f1     PUSH       EDX=>DAT_fffffff8
    //                              language.dll match for 0x241f: "WARNING: This computer progra
    //                              language.dll match for 0x241f: "WARNING: This computer progra
    //         0043b1f2     PUSH       offset DAT_fffffff4
    //         0043b1f7     MOV        this,EBP
    //         0043b1f9     CALL       TPanel::get_string                               int get_string(TPanel * this, int param_1, ch
    //                              dlg_abt.cpp:124 (48)
    //         0043b1fe     PUSH       0x1
    //         0043b200     PUSH       0x0=>DAT_fffffff8
    //         0043b202     PUSH       0x0=>DAT_fffffff4
    //         0043b204     PUSH       offset DAT_fffffff0
    //         0043b206     PUSH       0xdc
    //         0043b20b     PUSH       0x1e0
    //         0043b210     PUSH       0xaf
    //         0043b215     LEA        EAX,[ESP + 0x24c]
    //         0043b21c     PUSH       0x14
    //         0043b21e     PUSH       EAX
    //         0043b21f     LEA        EAX,[EBP + 0x4b0]
    //         0043b225     MOV        this,EBP
    //         0043b227     PUSH       EAX
    //         0043b228     PUSH       EBP
    //         0043b229     CALL       TEasy_Panel::create_text                         int create_text(TEasy_Panel * this, TPanel * 
    //                              dlg_abt.cpp:127 (42)
    //         0043b22e     PUSH       0x0
    //         0043b230     PUSH       0x0=>DAT_fffffff8
    //         0043b232     PUSH       0x0=>DAT_fffffff4
    //         0043b234     PUSH       offset DAT_fffffff0
    //         0043b236     PUSH       0xaa
    //         0043b23b     PUSH       0x172
    //         0043b240     PUSH       0x46
    //         0043b242     PUSH       0x0
    //         0043b244     LEA        ESI,[EBP + 0x4b8]
    //                              language.dll match for 0x2420: "Credits"
    //         0043b24a     PUSH       0x2420
    //         0043b24f     PUSH       ESI
    //         0043b250     PUSH       EBP
    //         0043b251     MOV        this,EBP
    //         0043b253     CALL       TEasy_Panel::create_button                       int create_button(TEasy_Panel * this, TPanel 
    //                              dlg_abt.cpp:129 (45)
    //         0043b258     PUSH       0x0
    //         0043b25a     PUSH       0x0=>DAT_fffffff8
    //         0043b25c     PUSH       0x0=>DAT_fffffff4
    //         0043b25e     PUSH       offset DAT_fffffff0
    //         0043b260     PUSH       0xaa
    //         0043b265     PUSH       0x172
    //         0043b26a     PUSH       0x118
    //         0043b26f     PUSH       0x0
    //         0043b271     LEA        EDI,[EBP + 0x4bc]
    //                              language.dll match for 0x2421: "Close"
    //         0043b277     PUSH       0x2421
    //         0043b27c     PUSH       EDI
    //         0043b27d     PUSH       EBP
    //         0043b27e     MOV        this,EBP
    //         0043b280     CALL       TEasy_Panel::create_button                       int create_button(TEasy_Panel * this, TPanel 
    //                              dlg_abt.cpp:130 (2)
    //         0043b285     MOV        EAX,dword ptr [EDI]
    //                              dlg_abt.cpp:135 (46)
    //         0043b287     PUSH       0x2
    //         0043b289     MOV        dword ptr [EAX + 0x298],0x1b
    //         0043b293     MOV        dword ptr [EAX + 0x29c],0x0
    //         0043b29d     MOV        this,dword ptr [ESI]
    //         0043b29f     MOV        EDX,dword ptr [EDI]
    //         0043b2a1     LEA        EAX,[ESP + 0x14]
    //         0043b2a5     MOV        dword ptr [ESP + 0x14],this
    //         0043b2a9     PUSH       EAX=>DAT_fffffff8
    //         0043b2aa     MOV        this,EBP
    //         0043b2ac     MOV        dword ptr [ESP + 0x1c],EDX
    //         0043b2b0     CALL       TPanel::set_tab_order                            void set_tab_order(TPanel * this, TPanel * * 
    //                              dlg_abt.cpp:137 (10)
    //         0043b2b5     MOV        this,dword ptr [ESI]
    //         0043b2b7     PUSH       this
    //         0043b2b8     MOV        this,EBP
    //         0043b2ba     CALL       TPanel::set_curr_child                           void set_curr_child(TPanel * this, TPanel * p
    //                               LAB_0043b2bf                                                 XREF[1]:     0043ae3a(j)  
    //                              dlg_abt.cpp:148 (29)
    //         0043b2bf     MOV        this,dword ptr [ESP + local_c]
    //         0043b2c6     POP        EDI
    //         0043b2c7     MOV        EAX,EBP
    //         0043b2c9     POP        ESI
    //         0043b2ca     POP        EBP
    //         0043b2cb     MOV        dword ptr FS:[0x0],this
    //         0043b2d2     POP        EBX
    //         0043b2d3     ADD        ESP,0x122c
    //         0043b2d9     RET        0x4
    //         0043b2dc     ??         90h
    //         0043b2dd     NOP
    //         0043b2de     NOP
    //         0043b2df     NOP
}

TribeAboutDialog::~TribeAboutDialog() {
    /* TODO: Stub */
    //                              void __thiscall ~TribeAboutDialog(TribeAboutDialog * this)
    //              void              <VOID>         <RETURN>
    //              TribeAboutDial    ECX:4 (auto)   this
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     0043b329(W), 0043b3e1(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     0043b3ee(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     0043b319(W)  
    //                               ??1TribeAboutDialog@@UAE@XZ                                  XREF[1]:     `scalar_deleting_destructor':0043b
    //                               TribeAboutDialog::~TribeAboutDialog
    //                              dlg_abt.cpp:154 (35)
    //         0043b300     PUSH       -0x1
    //         0043b302     PUSH       FUN_0055cfa8
    //         0043b307     MOV        EAX,FS:[0x0]
    //         0043b30d     PUSH       EAX
    //         0043b30e     MOV        dword ptr FS:[0x0],ESP
    //         0043b315     PUSH       this
    //         0043b316     PUSH       ESI
    //         0043b317     MOV        ESI,this
    //         0043b319     MOV        dword ptr [ESP + local_10],ESI
    //         0043b31d     MOV        dword ptr [ESI],TribeAboutDialog::`vftable'      = 0043b2e0
    //                              dlg_abt.cpp:155 (20)
    //         0043b323     LEA        EAX,[ESI + 0x490]
    //         0043b329     MOV        dword ptr [ESP + local_4],0x0
    //         0043b331     PUSH       EAX
    //         0043b332     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //                              dlg_abt.cpp:156 (14)
    //         0043b337     LEA        this,[ESI + 0x494]
    //         0043b33d     PUSH       this
    //         0043b33e     MOV        this,ESI
    //         0043b340     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //                              dlg_abt.cpp:157 (14)
    //         0043b345     LEA        EDX,[ESI + 0x498]
    //         0043b34b     MOV        this,ESI
    //         0043b34d     PUSH       EDX
    //         0043b34e     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //                              dlg_abt.cpp:158 (14)
    //         0043b353     LEA        EAX,[ESI + 0x49c]
    //         0043b359     MOV        this,ESI
    //         0043b35b     PUSH       EAX
    //         0043b35c     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //                              dlg_abt.cpp:159 (14)
    //         0043b361     LEA        this,[ESI + 0x4a0]
    //         0043b367     PUSH       this
    //         0043b368     MOV        this,ESI
    //         0043b36a     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //                              dlg_abt.cpp:160 (14)
    //         0043b36f     LEA        EDX,[ESI + 0x4a4]
    //         0043b375     MOV        this,ESI
    //         0043b377     PUSH       EDX
    //         0043b378     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //                              dlg_abt.cpp:161 (14)
    //         0043b37d     LEA        EAX,[ESI + 0x4a8]
    //         0043b383     MOV        this,ESI
    //         0043b385     PUSH       EAX
    //         0043b386     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //                              dlg_abt.cpp:162 (14)
    //         0043b38b     LEA        this,[ESI + 0x4ac]
    //         0043b391     PUSH       this
    //         0043b392     MOV        this,ESI
    //         0043b394     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //                              dlg_abt.cpp:163 (14)
    //         0043b399     LEA        EDX,[ESI + 0x4b0]
    //         0043b39f     MOV        this,ESI
    //         0043b3a1     PUSH       EDX
    //         0043b3a2     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //                              dlg_abt.cpp:164 (14)
    //         0043b3a7     LEA        EAX,[ESI + 0x4b8]
    //         0043b3ad     MOV        this,ESI
    //         0043b3af     PUSH       EAX
    //         0043b3b0     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //                              dlg_abt.cpp:165 (14)
    //         0043b3b5     LEA        this,[ESI + 0x4bc]
    //         0043b3bb     PUSH       this
    //         0043b3bc     MOV        this,ESI
    //         0043b3be     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //                              dlg_abt.cpp:166 (14)
    //         0043b3c3     LEA        EDX,[ESI + 0x4c0]
    //         0043b3c9     MOV        this,ESI
    //         0043b3cb     PUSH       EDX
    //         0043b3cc     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //                              dlg_abt.cpp:167 (16)
    //         0043b3d1     LEA        EAX,[ESI + 0x4b4]
    //         0043b3d7     MOV        this,ESI
    //         0043b3d9     PUSH       EAX
    //         0043b3da     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //         0043b3df     MOV        this,ESI
    //                              dlg_abt.cpp:168 (29)
    //         0043b3e1     MOV        dword ptr [ESP + local_4],0xffffffff
    //         0043b3e9     CALL       TDialogPanel::~TDialogPanel                      void ~TDialogPanel(TDialogPanel * this)
    //         0043b3ee     MOV        this,dword ptr [ESP + local_c]
    //         0043b3f2     POP        ESI
    //         0043b3f3     MOV        dword ptr FS:[0x0],this
    //         0043b3fa     ADD        ESP,0x10
    //         0043b3fd     RET
    //         0043b3fe     ??         90h
    //         0043b3ff     NOP
    //                              * protected: virtual long __thiscall TribeAboutDialog::action(class TPanel *,long,unsigned long,unsi... *
    //                              long __thiscall action(TribeAboutDialog * this, TPanel * param_1, lo
    //              long              EAX:4          <RETURN>
    //              TribeAboutDial    ECX:4 (auto)   this
    //              TPanel *          Stack[0x4]:4   param_1                   XREF[1]:     0043b40e(R)  
    //              long              Stack[0x8]:4   param_2                   XREF[2]:     0043b41c(R), 0043b4ca(W)  
    //              ulong             Stack[0xc]:4   param_3                   XREF[1]:     0043b525(R)  
    //              ulong             Stack[0x10]:4  param_4                   XREF[1]:     0043b520(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     0043b4d0(W), 0043b4ed(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[2]:     0043b50e(R), 0043b533(R)  
    //                               ?action@TribeAboutDialog@@MAEJPAVTPanel@@JKK@Z               XREF[1]:     0056f6c4(*)  
    //                               TribeAboutDialog::action
    //                              dlg_abt.cpp:174 (14)
    //         0043b400     MOV        EAX,FS:[0x0]
    //         0043b406     PUSH       -0x1
    //         0043b408     PUSH       FUN_0055cfcb
    //         0043b40d     PUSH       EAX
    //                              dlg_abt.cpp:175 (27)
    //         0043b40e     MOV        EAX,dword ptr [ESP + param_1]
    //         0043b412     MOV        dword ptr FS:[0x0],ESP
    //         0043b419     PUSH       ESI
    //         0043b41a     MOV        ESI,this
    //         0043b41c     MOV        this,dword ptr [ESP + param_2]
    //         0043b420     CMP        this,0x1
    //         0043b423     JNZ        LAB_0043b520
    //                              dlg_abt.cpp:177 (12)
    //         0043b429     CMP        EAX,dword ptr [ESI + 0x4bc]
    //         0043b42f     JNZ        LAB_0043b4b5
    //                              dlg_abt.cpp:179 (23)
    //         0043b435     PUSH       s_Game_Screen                                    = "Game Screen"
    //         0043b43a     MOV        this,panel_system
    //         0043b43f     CALL       TPanelSystem::panel                              TPanel * panel(TPanelSystem * this, char * pa
    //         0043b444     TEST       EAX,EAX
    //         0043b446     JZ         LAB_0043b4fa
    //                              dlg_abt.cpp:181 (32)
    //         0043b44c     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0043b452     CALL       RGE_Base_Game::singlePlayerGame                  int singlePlayerGame(RGE_Base_Game * this)
    //         0043b457     CMP        EAX,0x1
    //         0043b45a     JNZ        LAB_0043b475
    //         0043b45c     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0043b462     MOV        EAX,dword ptr [this->_padding_ + 0xa00]
    //         0043b468     TEST       EAX,EAX
    //         0043b46a     JNZ        LAB_0043b475
    //                              dlg_abt.cpp:182 (9)
    //         0043b46c     PUSH       0x0
    //         0043b46e     PUSH       0x0
    //         0043b470     CALL       RGE_Base_Game::set_paused                        void set_paused(RGE_Base_Game * this, int par
    //                               LAB_0043b475                                                 XREF[2]:     0043b45a(j), 0043b46a(j)  
    //                              dlg_abt.cpp:183 (17)
    //         0043b475     PUSH       0x0
    //         0043b477     PUSH       s_Game_Screen                                    = "Game Screen"
    //         0043b47c     MOV        this,panel_system
    //         0043b481     CALL       TPanelSystem::setCurrentPanel                    int setCurrentPanel(TPanelSystem * this, char
    //                              dlg_abt.cpp:184 (9)
    //         0043b486     MOV        EAX,dword ptr [ESI]
    //         0043b488     PUSH       0x0
    //         0043b48a     MOV        this,ESI
    //         0043b48c     CALL       dword ptr [EAX + 0x14]
    //                              dlg_abt.cpp:186 (15)
    //         0043b48f     PUSH       s_About_Dialog                                   = "About Dialog"
    //         0043b494     MOV        this,panel_system
    //         0043b499     CALL       TPanelSystem::destroyPanel                       int destroyPanel(TPanelSystem * this, char * 
    //                              dlg_abt.cpp:187 (5)
    //         0043b49e     MOV        EAX,0x1
    //                              dlg_abt.cpp:200 (18)
    //         0043b4a3     MOV        this,dword ptr [ESP + 0x4]
    //         0043b4a7     MOV        dword ptr FS:[0x0],this
    //         0043b4ae     POP        ESI
    //         0043b4af     ADD        ESP,0xc
    //         0043b4b2     RET        0x10
    //                               LAB_0043b4b5                                                 XREF[1]:     0043b42f(j)  
    //                              dlg_abt.cpp:190 (8)
    //         0043b4b5     CMP        EAX,dword ptr [ESI + 0x4b8]
    //         0043b4bb     JNZ        LAB_0043b520
    //                              dlg_abt.cpp:192 (36)
    //         0043b4bd     PUSH       0x8b8
    //         0043b4c2     CALL       operator_new                                     void * operator_new(uint param_1)
    //         0043b4c7     ADD        ESP,0x4
    //         0043b4ca     MOV        dword ptr [ESP + param_2],EAX
    //         0043b4ce     TEST       EAX,EAX
    //         0043b4d0     MOV        dword ptr [ESP + local_4],0x0
    //         0043b4d8     JZ         LAB_0043b4e1
    //         0043b4da     MOV        this,EAX
    //         0043b4dc     CALL       TRIBE_Credits_Screen::TRIBE_Credits_Screen       undefined TRIBE_Credits_Screen(TRIBE_Credits_
    //                               LAB_0043b4e1                                                 XREF[1]:     0043b4d8(j)  
    //                              dlg_abt.cpp:193 (25)
    //         0043b4e1     PUSH       0x0
    //         0043b4e3     PUSH       s_Credits_Screen                                 = "Credits Screen"
    //         0043b4e8     MOV        this,panel_system
    //         0043b4ed     MOV        dword ptr [ESP + local_4],0xffffffff
    //         0043b4f5     CALL       TPanelSystem::setCurrentPanel                    int setCurrentPanel(TPanelSystem * this, char
    //                               LAB_0043b4fa                                                 XREF[1]:     0043b446(j)  
    //                              dlg_abt.cpp:194 (15)
    //         0043b4fa     PUSH       s_About_Dialog                                   = "About Dialog"
    //         0043b4ff     MOV        this,panel_system
    //         0043b504     CALL       TPanelSystem::destroyPanel                       int destroyPanel(TPanelSystem * this, char * 
    //                              dlg_abt.cpp:195 (5)
    //         0043b509     MOV        EAX,0x1
    //                              dlg_abt.cpp:200 (18)
    //         0043b50e     MOV        this,dword ptr [ESP + local_c]
    //         0043b512     MOV        dword ptr FS:[0x0],this
    //         0043b519     POP        ESI
    //         0043b51a     ADD        ESP,0xc
    //         0043b51d     RET        0x10
    //                               LAB_0043b520                                                 XREF[2]:     0043b423(j), 0043b4bb(j)  
    //                              dlg_abt.cpp:199 (19)
    //         0043b520     MOV        EDX,dword ptr [ESP + param_4]
    //         0043b524     PUSH       EDX
    //         0043b525     MOV        EDX,dword ptr [ESP + param_3]
    //         0043b529     PUSH       EDX
    //         0043b52a     PUSH       this
    //         0043b52b     PUSH       EAX
    //         0043b52c     MOV        this,ESI
    //         0043b52e     CALL       TEasy_Panel::action                              long action(TEasy_Panel * this, TPanel * para
    //                              dlg_abt.cpp:200 (18)
    //         0043b533     MOV        this,dword ptr [ESP + local_c]
    //         0043b537     POP        ESI
    //         0043b538     MOV        dword ptr FS:[0x0],this
    //         0043b53f     ADD        ESP,0xc
    //         0043b542     RET        0x10
    //         0043b545     ??         90h
    //         0043b546     NOP
    //         0043b547     NOP
    //         0043b548     NOP
    //         0043b549     NOP
    //         0043b54a     NOP
    //         0043b54b     NOP
    //         0043b54c     NOP
    //         0043b54d     NOP
    //         0043b54e     NOP
    //         0043b54f     NOP
}

void TribeAboutDialog::draw() {
    /* TODO: Stub */
    //                              void __thiscall draw(TribeAboutDialog * this)
    //              void              <VOID>         <RETURN>
    //              TribeAboutDial    ECX:4 (auto)   this
    //                               ?draw@TribeAboutDialog@@UAEXXZ                               XREF[1]:     0056f640(*)  
    //                               TribeAboutDialog::draw
    //                              dlg_abt.cpp:206 (5)
    //         0043b550     JMP        TEasy_Panel::draw
    //         0043b555     ??         90h
    //         0043b556     NOP
    //         0043b557     NOP
    //         0043b558     NOP
    //         0043b559     NOP
    //         0043b55a     NOP
    //         0043b55b     NOP
    //         0043b55c     NOP
    //         0043b55d     NOP
    //         0043b55e     NOP
    //         0043b55f     NOP
    //                              * public: __thiscall TribeConfigDialog::TribeConfigDialog(enum TribeConfigDialog::Mode,class TScreen... *
    //                              undefined __thiscall TribeConfigDialog(TribeConfigDialog * this, Mod
    //              undefined         <UNASSIGNED>   <RETURN>
    //              TribeConfigDia    ECX:4 (auto)   this
    //              Mode              Stack[0x4]:4   param_1                   XREF[5]:     0043b58c(R), 0043b774(W), 0043bb66(R), 0043bfd4(W), 
    //                                                                                     0043bfda(R)  
    //              TScreenPanel *    Stack[0x8]:4   param_2                   XREF[1]:     0043b5ba(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     0043b5c3(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     0043c089(R)  
    //              TPanel *[10]      Stack[-0x38]   tabList                   XREF[1,3]:   0043b583(W), 0043c073(*), 0043c077(W), 0043c080(W)  
    //                               ??0TribeConfigDialog@@QAE@W4Mode@0@PAVTScreenPanel@@@Z       XREF[1]:     action:0043f9aa(c)  
    //                               TribeConfigDialog::TribeConfigDialog
    //                              dlg_conf.cpp:84 (54)
    //         0043b560     PUSH       -0x1
    //         0043b562     PUSH       FUN_0055cfe8
    //         0043b567     MOV        EAX,FS:[0x0]
    //         0043b56d     PUSH       EAX
    //         0043b56e     MOV        dword ptr FS:[0x0],ESP
    //         0043b575     SUB        ESP,0x2c
    //         0043b578     PUSH       EBX
    //         0043b579     PUSH       EBP
    //         0043b57a     PUSH       ESI
    //         0043b57b     PUSH       EDI
    //         0043b57c     MOV        ESI,this
    //         0043b57e     PUSH       s_Config_Dialog                                  = "Config Dialog"
    //         0043b583     MOV        dword ptr [ESP + tabList[0]],ESI
    //         0043b587     CALL       TDialogPanel::TDialogPanel                       undefined TDialogPanel(TDialogPanel * this, c
    //         0043b58c     MOV        EAX,dword ptr [ESP + param_1]
    //         0043b590     LEA        EBP,[ESI + 0x498]
    //                              dlg_conf.cpp:89 (6)
    //         0043b596     LEA        EBX,[ESI + 0x494]
    //                              dlg_conf.cpp:92 (24)
    //         0043b59c     MOV        EDX,EBP
    //         0043b59e     XOR        this,this
    //         0043b5a0     MOV        dword ptr [ESI + 0x490],EAX
    //         0043b5a6     MOV        dword ptr [ESI],TribeConfigDialog::`vftable'     = 0043c0a0
    //         0043b5ac     MOV        dword ptr [EBX],0x0
    //         0043b5b2     MOV        dword ptr [EDX],this
    //                              dlg_conf.cpp:321 (380)
    //         0043b5b4     LEA        EAX,[ESI + 0x4a8]
    //         0043b5ba     MOV        EDI,dword ptr [ESP + param_2]
    //         0043b5be     PUSH       0x1
    //         0043b5c0     MOV        dword ptr [EDX + 0x4],this
    //         0043b5c3     MOV        dword ptr [ESP + local_4],0x0
    //         0043b5cb     MOV        dword ptr [EDX + 0x8],this
    //         0043b5ce     MOV        dword ptr [EDX + 0xc],this
    //         0043b5d1     MOV        dword ptr [EAX],this
    //         0043b5d3     XOR        EDX,EDX
    //         0043b5d5     MOV        dword ptr [EAX + 0x4],this
    //         0043b5d8     MOV        dword ptr [EAX + 0x8],this
    //         0043b5db     LEA        EAX,[ESI + 0x4b4]
    //         0043b5e1     MOV        dword ptr [ESI + 0x4b4],EDX
    //         0043b5e7     MOV        dword ptr [EAX + 0x4],EDX
    //         0043b5ea     MOV        dword ptr [EAX + 0x8],EDX
    //         0043b5ed     LEA        EAX,[ESI + 0x4c4]
    //         0043b5f3     MOV        dword ptr [ESI + 0x4c0],EDX
    //         0043b5f9     MOV        dword ptr [EAX],this
    //         0043b5fb     MOV        dword ptr [EAX + 0x4],this
    //         0043b5fe     MOV        dword ptr [EAX + 0x8],this
    //         0043b601     LEA        EAX,[ESI + 0x4d4]
    //         0043b607     MOV        dword ptr [ESI + 0x4d0],EDX
    //         0043b60d     MOV        dword ptr [EAX],EDX
    //         0043b60f     MOV        dword ptr [EAX + 0x4],EDX
    //         0043b612     MOV        dword ptr [EAX + 0x8],EDX
    //         0043b615     LEA        EAX,[ESI + 0x4e4]
    //         0043b61b     MOV        dword ptr [ESI + 0x4e0],EDX
    //         0043b621     MOV        dword ptr [EAX],this
    //         0043b623     MOV        dword ptr [EAX + 0x4],this
    //         0043b626     MOV        dword ptr [EAX + 0x8],this
    //         0043b629     MOV        dword ptr [EAX + 0xc],this
    //         0043b62c     LEA        EAX,[ESI + 0x4f4]
    //         0043b632     MOV        dword ptr [ESI + 0x4f4],EDX
    //         0043b638     MOV        dword ptr [EAX + 0x4],EDX
    //         0043b63b     MOV        dword ptr [EAX + 0x8],EDX
    //         0043b63e     LEA        EAX,[ESI + 0x500]
    //         0043b644     MOV        dword ptr [ESI + 0x500],this
    //         0043b64a     MOV        dword ptr [EAX + 0x4],this
    //         0043b64d     MOV        dword ptr [EAX + 0x8],this
    //         0043b650     LEA        EAX,[ESI + 0x50c]
    //         0043b656     MOV        dword ptr [ESI + 0x50c],EDX
    //         0043b65c     MOV        dword ptr [EAX + 0x4],EDX
    //         0043b65f     LEA        EAX,[ESI + 0x514]
    //         0043b665     MOV        dword ptr [ESI + 0x514],this
    //         0043b66b     MOV        dword ptr [EAX + 0x4],this
    //         0043b66e     MOV        dword ptr [EAX + 0x8],this
    //         0043b671     LEA        EAX,[ESI + 0x520]
    //         0043b677     MOV        dword ptr [ESI + 0x520],EDX
    //         0043b67d     MOV        dword ptr [EAX + 0x4],EDX
    //         0043b680     LEA        EAX,[ESI + 0x528]
    //         0043b686     MOV        dword ptr [ESI + 0x528],this
    //         0043b68c     MOV        dword ptr [EAX + 0x4],this
    //         0043b68f     MOV        dword ptr [EAX + 0x8],this
    //         0043b692     MOV        dword ptr [EAX + 0xc],this
    //         0043b695     LEA        EAX,[ESI + 0x538]
    //         0043b69b     MOV        this,EDI
    //         0043b69d     MOV        dword ptr [EAX],EDX
    //         0043b69f     MOV        dword ptr [EAX + 0x4],EDX
    //         0043b6a2     MOV        dword ptr [EAX + 0x8],EDX
    //         0043b6a5     MOV        dword ptr [ESI + 0x544],EDX
    //         0043b6ab     MOV        dword ptr [ESI + 0x548],EDX
    //         0043b6b1     CALL       TEasy_Panel::get_popup_info_id                   long get_popup_info_id(TEasy_Panel * this)
    //         0043b6b6     PUSH       EAX
    //         0043b6b7     MOV        this,EDI
    //         0043b6b9     CALL       TEasy_Panel::get_popup_info_file                 char * get_popup_info_file(TEasy_Panel * this)
    //         0043b6be     PUSH       EAX
    //         0043b6bf     PUSH       0x186
    //         0043b6c4     PUSH       0x258
    //         0043b6c9     PUSH       EDI
    //         0043b6ca     MOV        this,EDI
    //         0043b6cc     CALL       TPanel::renderArea                               TDrawArea * renderArea(TPanel * this)
    //         0043b6d1     PUSH       EAX
    //         0043b6d2     MOV        this,ESI
    //         0043b6d4     CALL       TDialogPanel::setup                              int setup(TDialogPanel * this, TDrawArea * pa
    //         0043b6d9     TEST       EAX,EAX
    //         0043b6db     JZ         LAB_0043c089
    //         0043b6e1     PUSH       0x0
    //         0043b6e3     PUSH       0x1
    //         0043b6e5     PUSH       0x1
    //         0043b6e7     PUSH       0x1
    //         0043b6e9     PUSH       0x1e
    //         0043b6eb     PUSH       0x18b
    //         0043b6f0     PUSH       0xa
    //         0043b6f2     PUSH       0x67
    //                              language.dll match for 0x24d7: "Game Settings"
    //         0043b6f4     PUSH       0x24d7
    //         0043b6f9     PUSH       EBX
    //         0043b6fa     PUSH       ESI
    //         0043b6fb     MOV        this,ESI
    //         0043b6fd     CALL       TEasy_Panel::create_text                         int create_text(TEasy_Panel * this, TPanel * 
    //         0043b702     TEST       EAX,EAX
    //         0043b704     JZ         LAB_0043c089
    //         0043b70a     PUSH       0x0
    //         0043b70c     PUSH       0x1
    //         0043b70e     PUSH       0x0
    //         0043b710     PUSH       0xb
    //         0043b712     PUSH       0x1e
    //         0043b714     PUSH       0x6e
    //         0043b716     PUSH       0x32
    //         0043b718     PUSH       0x14
    //                              language.dll match for 0x24df: "Speed"
    //         0043b71a     PUSH       0x24df
    //         0043b71f     PUSH       EBP
    //         0043b720     PUSH       ESI
    //         0043b721     MOV        this,ESI
    //         0043b723     CALL       TEasy_Panel::create_text                         int create_text(TEasy_Panel * this, TPanel * 
    //         0043b728     TEST       EAX,EAX
    //         0043b72a     JZ         LAB_0043c089
    //                              dlg_conf.cpp:139 (2)
    //         0043b730     XOR        EDI,EDI
    //                               LAB_0043b732                                                 XREF[1]:     0043b7b0(j)  
    //                              dlg_conf.cpp:140 (11)
    //         0043b732     MOV        EAX,EDI
    //         0043b734     SUB        EAX,0x0
    //         0043b737     JZ         LAB_0043b74d
    //         0043b739     DEC        EAX
    //         0043b73a     JZ         LAB_0043b746
    //         0043b73c     DEC        EAX
    //                              dlg_conf.cpp:144 (2)
    //         0043b73d     JNZ        LAB_0043b74d
    //                              dlg_conf.cpp:143 (7)
    //         0043b73f     MOV        this,0x24da
    //         0043b744     JMP        LAB_0043b752
    //                               LAB_0043b746                                                 XREF[1]:     0043b73a(j)  
    //                              dlg_conf.cpp:142 (7)
    //         0043b746     MOV        this,0x24d9
    //         0043b74b     JMP        LAB_0043b752
    //                               LAB_0043b74d                                                 XREF[2]:     0043b737(j), 0043b73d(j)  
    //                              dlg_conf.cpp:141 (5)
    //         0043b74d     MOV        this,0x24d8
    //                               LAB_0043b752                                                 XREF[2]:     0043b744(j), 0043b74b(j)  
    //                              dlg_conf.cpp:146 (55)
    //         0043b752     MOV        EAX,EDI
    //         0043b754     PUSH       0x0
    //         0043b756     SHL        EAX,0x3
    //         0043b759     SUB        EAX,EDI
    //         0043b75b     PUSH       0x1
    //         0043b75d     PUSH       0x0
    //         0043b75f     PUSH       0xb
    //         0043b761     LEA        EBX,[EAX + EAX*0x4 + 0x55]
    //         0043b765     PUSH       0x1e
    //                              language.dll match for 0x6e: "Copperplate Gothic Light"
    //         0043b767     PUSH       0x6e
    //         0043b769     PUSH       EBX
    //         0043b76a     PUSH       0x37
    //         0043b76c     LEA        EAX,[ESI + EDI*0x4 + 0x49c]
    //         0043b773     PUSH       this
    //         0043b774     MOV        dword ptr [ESP + param_1],this
    //         0043b778     PUSH       EAX
    //         0043b779     PUSH       ESI
    //         0043b77a     MOV        this,ESI
    //         0043b77c     CALL       TEasy_Panel::create_text                         int create_text(TEasy_Panel * this, TPanel * 
    //         0043b781     TEST       EAX,EAX
    //         0043b783     JZ         LAB_0043c089
    //                              dlg_conf.cpp:147 (41)
    //         0043b789     PUSH       0x0
    //         0043b78b     PUSH       0x0
    //         0043b78d     PUSH       0x1e
    //         0043b78f     PUSH       0x1e
    //         0043b791     PUSH       EBX
    //         0043b792     LEA        this,[ESI + EDI*0x4 + 0x4a8]
    //         0043b799     PUSH       0x14
    //         0043b79b     PUSH       this
    //         0043b79c     PUSH       ESI
    //         0043b79d     MOV        this,ESI
    //         0043b79f     CALL       TEasy_Panel::create_radio_button                 int create_radio_button(TEasy_Panel * this, T
    //         0043b7a4     TEST       EAX,EAX
    //         0043b7a6     JZ         LAB_0043c089
    //         0043b7ac     INC        EDI
    //         0043b7ad     CMP        EDI,0x3
    //         0043b7b0     JL         LAB_0043b732
    //                              dlg_conf.cpp:149 (13)
    //         0043b7b2     LEA        EBX,[ESI + 0x4a8]
    //         0043b7b8     MOV        EBP,0x3
    //         0043b7bd     MOV        EDI,EBX
    //                               LAB_0043b7bf                                                 XREF[1]:     0043b7cd(j)  
    //                              dlg_conf.cpp:150 (16)
    //         0043b7bf     MOV        this,dword ptr [EDI]
    //         0043b7c1     PUSH       0x3
    //         0043b7c3     PUSH       EBX
    //         0043b7c4     CALL       TButtonPanel::set_radio_info                     void set_radio_info(TButtonPanel * this, TBut
    //         0043b7c9     ADD        EDI,0x4
    //         0043b7cc     DEC        EBP
    //         0043b7cd     JNZ        LAB_0043b7bf
    //                              dlg_conf.cpp:151 (15)
    //         0043b7cf     MOV        EDX,dword ptr [rge_base_game]                    = 00000000
    //         0043b7d5     CMP        dword ptr [EDX + 0x1b0],0x5
    //         0043b7dc     JNZ        LAB_0043b7f4
    //                              dlg_conf.cpp:321 (22)
    //         0043b7de     MOV        EDI,EBX
    //         0043b7e0     MOV        EBX,0x3
    //                               LAB_0043b7e5                                                 XREF[1]:     0043b7f2(j)  
    //         0043b7e5     MOV        this,dword ptr [EDI]
    //         0043b7e7     PUSH       0x1
    //         0043b7e9     CALL       TButtonPanel::set_disabled                       void set_disabled(TButtonPanel * this, int pa
    //         0043b7ee     ADD        EDI,0x4
    //         0043b7f1     DEC        EBX
    //         0043b7f2     JNZ        LAB_0043b7e5
    //                               LAB_0043b7f4                                                 XREF[1]:     0043b7dc(j)  
    //                              dlg_conf.cpp:157 (14)
    //         0043b7f4     MOV        EAX,[rge_base_game]                              = 00000000
    //         0043b7f9     MOV        this,dword ptr [EAX + 0x3f4]
    //         0043b7ff     FLD        float ptr [ECX + this->_padding_]
    //                              dlg_conf.cpp:158 (19)
    //         0043b802     FCOM       float ptr [DAT_0056f740]                         = align(3)
    //         0043b808     FST        float ptr [ESI + 0x554]
    //         0043b80e     FNSTSW     AX
    //         0043b810     TEST       AH,0x40
    //         0043b813     JZ         LAB_0043b81f
    //                              dlg_conf.cpp:159 (8)
    //         0043b815     MOV        this,dword ptr [ESI + 0x4b0]
    //         0043b81b     FSTP       ST0
    //                              dlg_conf.cpp:160 (15)
    //         0043b81d     JMP        LAB_0043b849
    //                               LAB_0043b81f                                                 XREF[1]:     0043b813(j)  
    //         0043b81f     FCOM       float ptr [DAT_0056f744]
    //         0043b825     FNSTSW     AX
    //         0043b827     TEST       AH,0x40
    //         0043b82a     JZ         LAB_0043b836
    //                              dlg_conf.cpp:161 (8)
    //         0043b82c     MOV        this,dword ptr [ESI + 0x4ac]
    //         0043b832     FSTP       ST0
    //                              dlg_conf.cpp:162 (15)
    //         0043b834     JMP        LAB_0043b849
    //                               LAB_0043b836                                                 XREF[1]:     0043b82a(j)  
    //         0043b836     FCOMP      float ptr [DAT_0056f748]
    //         0043b83c     FNSTSW     AX
    //         0043b83e     TEST       AH,0x40
    //         0043b841     JZ         LAB_0043b84e
    //                              dlg_conf.cpp:163 (11)
    //         0043b843     MOV        this,dword ptr [ESI + 0x4a8]
    //                               LAB_0043b849                                                 XREF[2]:     0043b81d(j), 0043b834(j)  
    //         0043b849     CALL       TButtonPanel::set_radio_button                   void set_radio_button(TButtonPanel * this)
    //                               LAB_0043b84e                                                 XREF[1]:     0043b841(j)  
    //                              dlg_conf.cpp:166 (47)
    //         0043b84e     PUSH       0x1
    //         0043b850     PUSH       0x1
    //         0043b852     PUSH       0x0
    //         0043b854     PUSH       0xb
    //         0043b856     PUSH       0x28
    //         0043b858     PUSH       0x6e
    //         0043b85a     PUSH       0x2d
    //         0043b85c     PUSH       0xa5
    //         0043b861     LEA        EAX,[ESI + 0x4b4]
    //                              language.dll match for 0x24db: "Music\\nVolume"
    //         0043b867     PUSH       0x24db
    //         0043b86c     PUSH       EAX
    //         0043b86d     PUSH       ESI
    //         0043b86e     MOV        this,ESI
    //         0043b870     CALL       TEasy_Panel::create_text                         int create_text(TEasy_Panel * this, TPanel * 
    //         0043b875     TEST       EAX,EAX
    //         0043b877     JZ         LAB_0043c089
    //                              dlg_conf.cpp:167 (47)
    //         0043b87d     PUSH       0x0
    //         0043b87f     PUSH       0x1
    //         0043b881     PUSH       0x0
    //         0043b883     PUSH       0xb
    //         0043b885     PUSH       0x14
    //         0043b887     PUSH       0x6e
    //         0043b889     PUSH       0x55
    //         0043b88b     PUSH       0xbe
    //         0043b890     LEA        EDX,[ESI + 0x4b8]
    //                              language.dll match for 0x24dc: "High"
    //         0043b896     PUSH       0x24dc
    //         0043b89b     PUSH       EDX
    //         0043b89c     PUSH       ESI
    //         0043b89d     MOV        this,ESI
    //         0043b89f     CALL       TEasy_Panel::create_text                         int create_text(TEasy_Panel * this, TPanel * 
    //         0043b8a4     TEST       EAX,EAX
    //         0043b8a6     JZ         LAB_0043c089
    //                              dlg_conf.cpp:168 (50)
    //         0043b8ac     PUSH       0x0
    //         0043b8ae     PUSH       0x1
    //         0043b8b0     PUSH       0x0
    //         0043b8b2     PUSH       0xb
    //         0043b8b4     PUSH       0x14
    //         0043b8b6     PUSH       0x6e
    //         0043b8b8     PUSH       0xa5
    //         0043b8bd     PUSH       0xbe
    //         0043b8c2     LEA        EAX,[ESI + 0x4bc]
    //                              language.dll match for 0x24dd: "Off"
    //         0043b8c8     PUSH       0x24dd
    //         0043b8cd     PUSH       EAX
    //         0043b8ce     PUSH       ESI
    //         0043b8cf     MOV        this,ESI
    //         0043b8d1     CALL       TEasy_Panel::create_text                         int create_text(TEasy_Panel * this, TPanel * 
    //         0043b8d6     TEST       EAX,EAX
    //         0043b8d8     JZ         LAB_0043c089
    //                              dlg_conf.cpp:169 (40)
    //         0043b8de     PUSH       0x64
    //         0043b8e0     PUSH       0x14
    //         0043b8e2     PUSH       0x55
    //         0043b8e4     PUSH       0xaa
    //         0043b8e9     PUSH       0x14
    //         0043b8eb     PUSH       0xa
    //         0043b8ed     LEA        EDI,[ESI + 0x4c0]
    //         0043b8f3     PUSH       0x64
    //         0043b8f5     PUSH       EDI
    //         0043b8f6     PUSH       ESI
    //         0043b8f7     MOV        this,ESI
    //         0043b8f9     CALL       TEasy_Panel::create_vert_slider                  int create_vert_slider(TEasy_Panel * this, TP
    //         0043b8fe     TEST       EAX,EAX
    //         0043b900     JZ         LAB_0043c089
    //                              dlg_conf.cpp:171 (6)
    //         0043b906     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //                              dlg_conf.cpp:172 (12)
    //         0043b90c     MOV        EBX,0x63
    //         0043b911     MOV        EAX,dword ptr [ECX + this->_padding_]
    //         0043b914     TEST       EAX,EAX
    //         0043b916     JZ         LAB_0043b937
    //                              dlg_conf.cpp:175 (29)
    //         0043b918     MOV        this,dword ptr [EAX + 0x254]
    //         0043b91e     MOV        EAX,0xae147ae1
    //         0043b923     IMUL       this
    //         0043b925     SAR        EDX,0x5
    //         0043b928     MOV        EAX,EDX
    //         0043b92a     SHR        EAX,0x1f
    //         0043b92d     ADD        EDX,EAX
    //         0043b92f     MOV        dword ptr [ESI + 0x54c],EDX
    //                              dlg_conf.cpp:177 (2)
    //         0043b935     JMP        LAB_0043b93d
    //                               LAB_0043b937                                                 XREF[1]:     0043b916(j)  
    //                              dlg_conf.cpp:178 (6)
    //         0043b937     MOV        dword ptr [ESI + 0x54c],EBX
    //                               LAB_0043b93d                                                 XREF[1]:     0043b935(j)  
    //                              dlg_conf.cpp:179 (14)
    //         0043b93d     MOV        this,dword ptr [ESI + 0x54c]
    //         0043b943     PUSH       this
    //         0043b944     MOV        this,dword ptr [EDI]
    //         0043b946     CALL       TScrollBarPanel::set_tab_pos                     void set_tab_pos(TScrollBarPanel * this, long
    //                              dlg_conf.cpp:183 (59)
    //         0043b94b     PUSH       0x1
    //         0043b94d     MOV        EDX,dword ptr [ESI + 0x54c]
    //         0043b953     PUSH       0x1
    //         0043b955     PUSH       0x0
    //         0043b957     PUSH       0xb
    //         0043b959     PUSH       0x28
    //         0043b95b     PUSH       0x6e
    //         0043b95d     PUSH       0x2d
    //         0043b95f     PUSH       0x131
    //         0043b964     LEA        EAX,[ESI + 0x4c4]
    //                              language.dll match for 0x24de: "Sound\\nVolume"
    //         0043b96a     PUSH       0x24de
    //         0043b96f     PUSH       EAX
    //         0043b970     PUSH       ESI
    //         0043b971     MOV        this,ESI
    //         0043b973     MOV        dword ptr [ESI + 0x55c],EDX
    //         0043b979     CALL       TEasy_Panel::create_text                         int create_text(TEasy_Panel * this, TPanel * 
    //         0043b97e     TEST       EAX,EAX
    //         0043b980     JZ         LAB_0043c089
    //                              dlg_conf.cpp:184 (47)
    //         0043b986     PUSH       0x0
    //         0043b988     PUSH       0x1
    //         0043b98a     PUSH       0x0
    //         0043b98c     PUSH       0xb
    //         0043b98e     PUSH       0x14
    //         0043b990     PUSH       0x6e
    //         0043b992     PUSH       0x55
    //         0043b994     PUSH       0x14a
    //         0043b999     LEA        EAX,[ESI + 0x4c8]
    //                              language.dll match for 0x24dc: "High"
    //         0043b99f     PUSH       0x24dc
    //         0043b9a4     PUSH       EAX
    //         0043b9a5     PUSH       ESI
    //         0043b9a6     MOV        this,ESI
    //         0043b9a8     CALL       TEasy_Panel::create_text                         int create_text(TEasy_Panel * this, TPanel * 
    //         0043b9ad     TEST       EAX,EAX
    //         0043b9af     JZ         LAB_0043c089
    //                              dlg_conf.cpp:185 (50)
    //         0043b9b5     PUSH       0x0
    //         0043b9b7     PUSH       0x1
    //         0043b9b9     PUSH       0x0
    //         0043b9bb     PUSH       0xb
    //         0043b9bd     PUSH       0x14
    //         0043b9bf     PUSH       0x6e
    //         0043b9c1     PUSH       0xa5
    //         0043b9c6     PUSH       0x14a
    //         0043b9cb     LEA        this,[ESI + 0x4cc]
    //                              language.dll match for 0x24dd: "Off"
    //         0043b9d1     PUSH       0x24dd
    //         0043b9d6     PUSH       this
    //         0043b9d7     PUSH       ESI
    //         0043b9d8     MOV        this,ESI
    //         0043b9da     CALL       TEasy_Panel::create_text                         int create_text(TEasy_Panel * this, TPanel * 
    //         0043b9df     TEST       EAX,EAX
    //         0043b9e1     JZ         LAB_0043c089
    //                              dlg_conf.cpp:186 (40)
    //         0043b9e7     PUSH       0x64
    //         0043b9e9     PUSH       0x14
    //         0043b9eb     PUSH       0x55
    //         0043b9ed     PUSH       0x136
    //         0043b9f2     PUSH       0x14
    //         0043b9f4     PUSH       0xa
    //         0043b9f6     LEA        EDI,[ESI + 0x4d0]
    //         0043b9fc     PUSH       0x64
    //         0043b9fe     PUSH       EDI
    //         0043b9ff     PUSH       ESI
    //         0043ba00     MOV        this,ESI
    //         0043ba02     CALL       TEasy_Panel::create_vert_slider                  int create_vert_slider(TEasy_Panel * this, TP
    //         0043ba07     TEST       EAX,EAX
    //         0043ba09     JZ         LAB_0043c089
    //                              dlg_conf.cpp:188 (9)
    //         0043ba0f     MOV        EDX,dword ptr [rge_base_game]                    = 00000000
    //         0043ba15     MOV        this,dword ptr [EDX + 0x60]
    //                              dlg_conf.cpp:189 (4)
    //         0043ba18     TEST       this,this
    //         0043ba1a     JZ         LAB_0043ba3c
    //                              dlg_conf.cpp:192 (30)
    //         0043ba1c     CALL       TSound_Driver::get_volume                        long get_volume(TSound_Driver * this)
    //         0043ba21     MOV        this,EAX
    //         0043ba23     MOV        EAX,0xae147ae1
    //         0043ba28     IMUL       this
    //         0043ba2a     SAR        EDX,0x5
    //         0043ba2d     MOV        EAX,EDX
    //         0043ba2f     SHR        EAX,0x1f
    //         0043ba32     ADD        EDX,EAX
    //         0043ba34     MOV        dword ptr [ESI + 0x550],EDX
    //                              dlg_conf.cpp:194 (2)
    //         0043ba3a     JMP        LAB_0043ba42
    //                               LAB_0043ba3c                                                 XREF[1]:     0043ba1a(j)  
    //                              dlg_conf.cpp:195 (6)
    //         0043ba3c     MOV        dword ptr [ESI + 0x550],EBX
    //                               LAB_0043ba42                                                 XREF[1]:     0043ba3a(j)  
    //                              dlg_conf.cpp:196 (14)
    //         0043ba42     MOV        this,dword ptr [ESI + 0x550]
    //         0043ba48     PUSH       this
    //         0043ba49     MOV        this,dword ptr [EDI]
    //         0043ba4b     CALL       TScrollBarPanel::set_tab_pos                     void set_tab_pos(TScrollBarPanel * this, long
    //                              dlg_conf.cpp:200 (59)
    //         0043ba50     PUSH       0x1
    //         0043ba52     MOV        EDX,dword ptr [ESI + 0x550]
    //         0043ba58     PUSH       0x1
    //         0043ba5a     PUSH       0x0
    //         0043ba5c     PUSH       0xb
    //         0043ba5e     PUSH       0x28
    //         0043ba60     PUSH       0x6e
    //         0043ba62     PUSH       0x2d
    //         0043ba64     PUSH       0x1bd
    //         0043ba69     LEA        EAX,[ESI + 0x4d4]
    //                              language.dll match for 0x24f0: "Scroll\\nSpeed"
    //         0043ba6f     PUSH       0x24f0
    //         0043ba74     PUSH       EAX
    //         0043ba75     PUSH       ESI
    //         0043ba76     MOV        this,ESI
    //         0043ba78     MOV        dword ptr [ESI + 0x560],EDX
    //         0043ba7e     CALL       TEasy_Panel::create_text                         int create_text(TEasy_Panel * this, TPanel * 
    //         0043ba83     TEST       EAX,EAX
    //         0043ba85     JZ         LAB_0043c089
    //                              dlg_conf.cpp:201 (47)
    //         0043ba8b     PUSH       0x0
    //         0043ba8d     PUSH       0x1
    //         0043ba8f     PUSH       0x0
    //         0043ba91     PUSH       0xb
    //         0043ba93     PUSH       0x14
    //         0043ba95     PUSH       0x6e
    //         0043ba97     PUSH       0x55
    //         0043ba99     PUSH       0x1d6
    //         0043ba9e     LEA        EAX,[ESI + 0x4d8]
    //                              language.dll match for 0x24f1: "Fast"
    //         0043baa4     PUSH       0x24f1
    //         0043baa9     PUSH       EAX
    //         0043baaa     PUSH       ESI
    //         0043baab     MOV        this,ESI
    //         0043baad     CALL       TEasy_Panel::create_text                         int create_text(TEasy_Panel * this, TPanel * 
    //         0043bab2     TEST       EAX,EAX
    //         0043bab4     JZ         LAB_0043c089
    //                              dlg_conf.cpp:202 (50)
    //         0043baba     PUSH       0x0
    //         0043babc     PUSH       0x1
    //         0043babe     PUSH       0x0
    //         0043bac0     PUSH       0xb
    //         0043bac2     PUSH       0x14
    //         0043bac4     PUSH       0x6e
    //         0043bac6     PUSH       0xa5
    //         0043bacb     PUSH       0x1d6
    //         0043bad0     LEA        this,[ESI + 0x4dc]
    //                              language.dll match for 0x24f2: "Slow"
    //         0043bad6     PUSH       0x24f2
    //         0043badb     PUSH       this
    //         0043badc     PUSH       ESI
    //         0043badd     MOV        this,ESI
    //         0043badf     CALL       TEasy_Panel::create_text                         int create_text(TEasy_Panel * this, TPanel * 
    //         0043bae4     TEST       EAX,EAX
    //         0043bae6     JZ         LAB_0043c089
    //                              dlg_conf.cpp:203 (40)
    //         0043baec     PUSH       0x64
    //         0043baee     PUSH       0x14
    //         0043baf0     PUSH       0x55
    //         0043baf2     PUSH       0x1c2
    //         0043baf7     PUSH       0x14
    //         0043baf9     PUSH       0xa
    //         0043bafb     LEA        EDI,[ESI + 0x4e0]
    //         0043bb01     PUSH       0x64
    //         0043bb03     PUSH       EDI
    //         0043bb04     PUSH       ESI
    //         0043bb05     MOV        this,ESI
    //         0043bb07     CALL       TEasy_Panel::create_vert_slider                  int create_vert_slider(TEasy_Panel * this, TP
    //         0043bb0c     TEST       EAX,EAX
    //         0043bb0e     JZ         LAB_0043c089
    //                              dlg_conf.cpp:205 (6)
    //         0043bb14     MOV        EDX,dword ptr [rge_base_game]                    = 00000000
    //                              dlg_conf.cpp:206 (26)
    //         0043bb1a     MOV        this,dword ptr [EDI]
    //         0043bb1c     MOV        EAX,dword ptr [EDX + 0xc]
    //         0043bb1f     MOV        EAX,dword ptr [EAX + 0x8c8]
    //         0043bb25     MOV        dword ptr [ESI + 0x558],EAX
    //         0043bb2b     ADD        EAX,-0xa
    //         0043bb2e     PUSH       EAX
    //         0043bb2f     CALL       TScrollBarPanel::set_tab_pos                     void set_tab_pos(TScrollBarPanel * this, long
    //                              dlg_conf.cpp:210 (50)
    //         0043bb34     PUSH       0x0
    //         0043bb36     PUSH       0x1
    //         0043bb38     PUSH       0x0
    //         0043bb3a     PUSH       0xb
    //         0043bb3c     PUSH       0x1e
    //         0043bb3e     PUSH       0xc8
    //         0043bb43     PUSH       0xbe
    //         0043bb48     PUSH       0x14
    //         0043bb4a     LEA        EAX,[ESI + 0x4e4]
    //                              language.dll match for 0x24e0: "Screen Size"
    //         0043bb50     PUSH       0x24e0
    //         0043bb55     PUSH       EAX
    //         0043bb56     PUSH       ESI
    //         0043bb57     MOV        this,ESI
    //         0043bb59     CALL       TEasy_Panel::create_text                         int create_text(TEasy_Panel * this, TPanel * 
    //         0043bb5e     TEST       EAX,EAX
    //         0043bb60     JZ         LAB_0043c089
    //                              dlg_conf.cpp:211 (6)
    //         0043bb66     MOV        EBP,dword ptr [ESP + param_1]
    //         0043bb6a     XOR        EDI,EDI
    //                               LAB_0043bb6c                                                 XREF[1]:     0043bbe9(j)  
    //                              dlg_conf.cpp:212 (13)
    //         0043bb6c     MOV        EAX,EDI
    //         0043bb6e     SUB        EAX,0x0
    //         0043bb71     JZ         LAB_0043bb87
    //         0043bb73     DEC        EAX
    //         0043bb74     JZ         LAB_0043bb80
    //         0043bb76     DEC        EAX
    //         0043bb77     JNZ        LAB_0043bb8c
    //                              dlg_conf.cpp:215 (7)
    //         0043bb79     MOV        EBP,0x24e9
    //         0043bb7e     JMP        LAB_0043bb8c
    //                               LAB_0043bb80                                                 XREF[1]:     0043bb74(j)  
    //                              dlg_conf.cpp:214 (7)
    //         0043bb80     MOV        EBP,0x24e8
    //         0043bb85     JMP        LAB_0043bb8c
    //                               LAB_0043bb87                                                 XREF[1]:     0043bb71(j)  
    //                              dlg_conf.cpp:213 (5)
    //         0043bb87     MOV        EBP,0x24e7
    //                               LAB_0043bb8c                                                 XREF[3]:     0043bb77(j), 0043bb7e(j), 
    //                                                                                                         0043bb85(j)  
    //                              dlg_conf.cpp:217 (54)
    //         0043bb8c     MOV        EAX,EDI
    //         0043bb8e     PUSH       0x0
    //         0043bb90     SHL        EAX,0x3
    //         0043bb93     SUB        EAX,EDI
    //         0043bb95     PUSH       0x1
    //         0043bb97     PUSH       0x0
    //         0043bb99     PUSH       0xb
    //         0043bb9b     LEA        EBX,[EAX + EAX*0x4 + 0xe1]
    //         0043bba2     PUSH       0x1e
    //         0043bba4     PUSH       0x64
    //         0043bba6     PUSH       EBX
    //         0043bba7     PUSH       0x37
    //         0043bba9     LEA        this,[ESI + EDI*0x4 + 0x4e8]
    //         0043bbb0     PUSH       EBP
    //         0043bbb1     PUSH       this
    //         0043bbb2     PUSH       ESI
    //         0043bbb3     MOV        this,ESI
    //         0043bbb5     CALL       TEasy_Panel::create_text                         int create_text(TEasy_Panel * this, TPanel * 
    //         0043bbba     TEST       EAX,EAX
    //         0043bbbc     JZ         LAB_0043c089
    //                              dlg_conf.cpp:218 (41)
    //         0043bbc2     PUSH       0x0
    //         0043bbc4     PUSH       0x0
    //         0043bbc6     PUSH       0x1e
    //         0043bbc8     PUSH       0x1e
    //         0043bbca     PUSH       EBX
    //         0043bbcb     LEA        EDX,[ESI + EDI*0x4 + 0x4f4]
    //         0043bbd2     PUSH       0x14
    //         0043bbd4     PUSH       EDX
    //         0043bbd5     PUSH       ESI
    //         0043bbd6     MOV        this,ESI
    //         0043bbd8     CALL       TEasy_Panel::create_radio_button                 int create_radio_button(TEasy_Panel * this, T
    //         0043bbdd     TEST       EAX,EAX
    //         0043bbdf     JZ         LAB_0043c089
    //         0043bbe5     INC        EDI
    //         0043bbe6     CMP        EDI,0x3
    //         0043bbe9     JL         LAB_0043bb6c
    //                              dlg_conf.cpp:220 (13)
    //         0043bbeb     LEA        EBX,[ESI + 0x4f4]
    //         0043bbf1     MOV        EBP,0x3
    //         0043bbf6     MOV        EDI,EBX
    //                               LAB_0043bbf8                                                 XREF[1]:     0043bc06(j)  
    //                              dlg_conf.cpp:221 (16)
    //         0043bbf8     MOV        this,dword ptr [EDI]
    //         0043bbfa     PUSH       0x3
    //         0043bbfc     PUSH       EBX
    //         0043bbfd     CALL       TButtonPanel::set_radio_info                     void set_radio_info(TButtonPanel * this, TBut
    //         0043bc02     ADD        EDI,0x4
    //         0043bc05     DEC        EBP
    //         0043bc06     JNZ        LAB_0043bbf8
    //                              dlg_conf.cpp:222 (29)
    //         0043bc08     MOV        EAX,dword ptr [ESI + 0x20]
    //         0043bc0b     MOV        this,dword ptr [EAX]
    //         0043bc0d     MOV        EAX,dword ptr [ECX + this->_padding_]
    //         0043bc10     CMP        EAX,0x280
    //         0043bc15     JZ         LAB_0043bc35
    //         0043bc17     CMP        EAX,0x320
    //         0043bc1c     JZ         LAB_0043bc2d
    //         0043bc1e     CMP        EAX,0x400
    //         0043bc23     JNZ        LAB_0043bc3c
    //                              dlg_conf.cpp:226 (8)
    //         0043bc25     MOV        this,dword ptr [ESI + 0x4fc]
    //         0043bc2b     JMP        LAB_0043bc37
    //                               LAB_0043bc2d                                                 XREF[1]:     0043bc1c(j)  
    //                              dlg_conf.cpp:225 (8)
    //         0043bc2d     MOV        this,dword ptr [ESI + 0x4f8]
    //         0043bc33     JMP        LAB_0043bc37
    //                               LAB_0043bc35                                                 XREF[1]:     0043bc15(j)  
    //                              dlg_conf.cpp:224 (7)
    //         0043bc35     MOV        this,dword ptr [EBX]
    //                               LAB_0043bc37                                                 XREF[2]:     0043bc2b(j), 0043bc33(j)  
    //         0043bc37     CALL       TButtonPanel::set_radio_button                   void set_radio_button(TButtonPanel * this)
    //                               LAB_0043bc3c                                                 XREF[1]:     0043bc23(j)  
    //                              dlg_conf.cpp:228 (23)
    //         0043bc3c     MOV        EDX,dword ptr [ESI + 0x20]
    //         0043bc3f     PUSH       0x8
    //         0043bc41     PUSH       0x0
    //         0043bc43     PUSH       0x280
    //         0043bc48     MOV        this,dword ptr [EDX]
    //         0043bc4a     CALL       TDrawSystem::IsModeAvail                         int IsModeAvail(TDrawSystem * this, long para
    //         0043bc4f     TEST       EAX,EAX
    //         0043bc51     JNZ        LAB_0043bc5c
    //                              dlg_conf.cpp:229 (9)
    //         0043bc53     MOV        this,dword ptr [EBX]
    //         0043bc55     PUSH       0x1
    //         0043bc57     CALL       TButtonPanel::set_disabled                       void set_disabled(TButtonPanel * this, int pa
    //                               LAB_0043bc5c                                                 XREF[1]:     0043bc51(j)  
    //                              dlg_conf.cpp:230 (23)
    //         0043bc5c     MOV        EAX,dword ptr [ESI + 0x20]
    //         0043bc5f     PUSH       0x8
    //         0043bc61     PUSH       0x0
    //         0043bc63     PUSH       0x320
    //         0043bc68     MOV        this,dword ptr [EAX]
    //         0043bc6a     CALL       TDrawSystem::IsModeAvail                         int IsModeAvail(TDrawSystem * this, long para
    //         0043bc6f     TEST       EAX,EAX
    //         0043bc71     JNZ        LAB_0043bc80
    //                              dlg_conf.cpp:231 (13)
    //         0043bc73     MOV        this,dword ptr [ESI + 0x4f8]
    //         0043bc79     PUSH       0x1
    //         0043bc7b     CALL       TButtonPanel::set_disabled                       void set_disabled(TButtonPanel * this, int pa
    //                               LAB_0043bc80                                                 XREF[1]:     0043bc71(j)  
    //                              dlg_conf.cpp:232 (23)
    //         0043bc80     MOV        this,dword ptr [ESI + 0x20]
    //         0043bc83     PUSH       0x8
    //         0043bc85     PUSH       0x0
    //         0043bc87     PUSH       0x400
    //         0043bc8c     MOV        this,dword ptr [this->_padding_]
    //         0043bc8e     CALL       TDrawSystem::IsModeAvail                         int IsModeAvail(TDrawSystem * this, long para
    //         0043bc93     TEST       EAX,EAX
    //         0043bc95     JNZ        LAB_0043bca4
    //                              dlg_conf.cpp:233 (13)
    //         0043bc97     MOV        this,dword ptr [ESI + 0x4fc]
    //         0043bc9d     PUSH       0x1
    //         0043bc9f     CALL       TButtonPanel::set_disabled                       void set_disabled(TButtonPanel * this, int pa
    //                               LAB_0043bca4                                                 XREF[1]:     0043bc95(j)  
    //                              dlg_conf.cpp:236 (53)
    //         0043bca4     PUSH       0x0
    //         0043bca6     PUSH       0x1
    //         0043bca8     PUSH       0x0
    //         0043bcaa     PUSH       0xb
    //         0043bcac     PUSH       0x1e
    //         0043bcae     PUSH       0xd2
    //         0043bcb3     PUSH       0xbe
    //         0043bcb8     PUSH       0xaa
    //         0043bcbd     LEA        EAX,[ESI + 0x500]
    //                              language.dll match for 0x24ea: "Mouse Interface"
    //         0043bcc3     PUSH       0x24ea
    //         0043bcc8     PUSH       EAX
    //         0043bcc9     PUSH       ESI
    //         0043bcca     MOV        this,ESI
    //         0043bccc     CALL       TEasy_Panel::create_text                         int create_text(TEasy_Panel * this, TPanel * 
    //         0043bcd1     TEST       EAX,EAX
    //         0043bcd3     JZ         LAB_0043c089
    //                              dlg_conf.cpp:237 (2)
    //         0043bcd9     XOR        EDI,EDI
    //                               LAB_0043bcdb                                                 XREF[1]:     0043bd7c(j)  
    //                              dlg_conf.cpp:241 (54)
    //         0043bcdb     PUSH       0x0
    //         0043bcdd     PUSH       0x1
    //         0043bcdf     PUSH       0x0
    //         0043bce1     PUSH       0xb
    //         0043bce3     TEST       EDI,EDI
    //         0043bce5     PUSH       0x1e
    //         0043bce7     PUSH       0x78
    //         0043bce9     JNZ        LAB_0043bd13
    //         0043bceb     PUSH       0xe1
    //         0043bcf0     PUSH       0xcd
    //         0043bcf5     LEA        EDX,[ESI + 0x504]
    //                              language.dll match for 0x24eb: "Two Buttons"
    //         0043bcfb     PUSH       0x24eb
    //         0043bd00     PUSH       EDX
    //         0043bd01     PUSH       ESI
    //         0043bd02     MOV        this,ESI
    //         0043bd04     CALL       TEasy_Panel::create_text                         int create_text(TEasy_Panel * this, TPanel * 
    //         0043bd09     TEST       EAX,EAX
    //         0043bd0b     JZ         LAB_0043c089
    //                              dlg_conf.cpp:243 (2)
    //         0043bd11     JMP        LAB_0043bd44
    //                               LAB_0043bd13                                                 XREF[1]:     0043bce9(j)  
    //                              dlg_conf.cpp:245 (49)
    //         0043bd13     MOV        EAX,EDI
    //         0043bd15     LEA        this,[ESI + EDI*0x4 + 0x504]
    //         0043bd1c     SHL        EAX,0x3
    //         0043bd1f     SUB        EAX,EDI
    //         0043bd21     LEA        EAX,[EAX + EAX*0x4 + 0xe1]
    //         0043bd28     PUSH       EAX
    //         0043bd29     PUSH       0xcd
    //                              language.dll match for 0x24ec: "One Button"
    //         0043bd2e     PUSH       0x24ec
    //         0043bd33     PUSH       this
    //         0043bd34     PUSH       ESI
    //         0043bd35     MOV        this,ESI
    //         0043bd37     CALL       TEasy_Panel::create_text                         int create_text(TEasy_Panel * this, TPanel * 
    //         0043bd3c     TEST       EAX,EAX
    //         0043bd3e     JZ         LAB_0043c089
    //                               LAB_0043bd44                                                 XREF[1]:     0043bd11(j)  
    //                              dlg_conf.cpp:247 (62)
    //         0043bd44     MOV        EAX,EDI
    //         0043bd46     PUSH       0x0
    //         0043bd48     SHL        EAX,0x3
    //         0043bd4b     SUB        EAX,EDI
    //         0043bd4d     PUSH       0x0
    //         0043bd4f     PUSH       0x1e
    //         0043bd51     PUSH       0x1e
    //         0043bd53     LEA        EDX,[EAX + EAX*0x4 + 0xe1]
    //         0043bd5a     LEA        EAX,[ESI + EDI*0x4 + 0x50c]
    //         0043bd61     PUSH       EDX
    //         0043bd62     PUSH       0xaa
    //         0043bd67     PUSH       EAX
    //         0043bd68     PUSH       ESI
    //         0043bd69     MOV        this,ESI
    //         0043bd6b     CALL       TEasy_Panel::create_radio_button                 int create_radio_button(TEasy_Panel * this, T
    //         0043bd70     TEST       EAX,EAX
    //         0043bd72     JZ         LAB_0043c089
    //         0043bd78     INC        EDI
    //         0043bd79     CMP        EDI,0x2
    //         0043bd7c     JL         LAB_0043bcdb
    //                              dlg_conf.cpp:249 (13)
    //         0043bd82     LEA        EBX,[ESI + 0x50c]
    //         0043bd88     MOV        EBP,0x2
    //         0043bd8d     MOV        EDI,EBX
    //                               LAB_0043bd8f                                                 XREF[1]:     0043bd9d(j)  
    //                              dlg_conf.cpp:250 (16)
    //         0043bd8f     MOV        this,dword ptr [EDI]
    //         0043bd91     PUSH       0x2
    //         0043bd93     PUSH       EBX
    //         0043bd94     CALL       TButtonPanel::set_radio_info                     void set_radio_info(TButtonPanel * this, TBut
    //         0043bd99     ADD        EDI,0x4
    //         0043bd9c     DEC        EBP
    //         0043bd9d     JNZ        LAB_0043bd8f
    //                              dlg_conf.cpp:251 (19)
    //         0043bd9f     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0043bda5     MOV        EDX,dword ptr [ECX + this->_padding_]
    //         0043bda8     CMP        word ptr [EDX + 0x8dc],0x2
    //         0043bdb0     JNZ        LAB_0043bdb6
    //                              dlg_conf.cpp:252 (2)
    //         0043bdb2     MOV        this,dword ptr [EBX]
    //                              dlg_conf.cpp:253 (2)
    //         0043bdb4     JMP        LAB_0043bdbc
    //                               LAB_0043bdb6                                                 XREF[1]:     0043bdb0(j)  
    //                              dlg_conf.cpp:254 (11)
    //         0043bdb6     MOV        this,dword ptr [ESI + 0x510]
    //                               LAB_0043bdbc                                                 XREF[1]:     0043bdb4(j)  
    //         0043bdbc     CALL       TButtonPanel::set_radio_button                   void set_radio_button(TButtonPanel * this)
    //                              dlg_conf.cpp:257 (53)
    //         0043bdc1     PUSH       0x0
    //         0043bdc3     PUSH       0x1
    //         0043bdc5     PUSH       0x0
    //         0043bdc7     PUSH       0xb
    //         0043bdc9     PUSH       0x1e
    //         0043bdcb     PUSH       0xd2
    //         0043bdd0     PUSH       0xbe
    //         0043bdd5     PUSH       0x14a
    //         0043bdda     LEA        EAX,[ESI + 0x514]
    //                              language.dll match for 0x24ed: "Roll-over Help"
    //         0043bde0     PUSH       0x24ed
    //         0043bde5     PUSH       EAX
    //         0043bde6     PUSH       ESI
    //         0043bde7     MOV        this,ESI
    //         0043bde9     CALL       TEasy_Panel::create_text                         int create_text(TEasy_Panel * this, TPanel * 
    //         0043bdee     TEST       EAX,EAX
    //         0043bdf0     JZ         LAB_0043c089
    //                              dlg_conf.cpp:258 (2)
    //         0043bdf6     XOR        EDI,EDI
    //                               LAB_0043bdf8                                                 XREF[1]:     0043be99(j)  
    //                              dlg_conf.cpp:262 (54)
    //         0043bdf8     PUSH       0x0
    //         0043bdfa     PUSH       0x1
    //         0043bdfc     PUSH       0x0
    //         0043bdfe     PUSH       0xb
    //         0043be00     TEST       EDI,EDI
    //         0043be02     PUSH       0x1e
    //         0043be04     PUSH       0x78
    //         0043be06     JNZ        LAB_0043be30
    //         0043be08     PUSH       0xe1
    //         0043be0d     PUSH       0x16d
    //         0043be12     LEA        EAX,[ESI + 0x518]
    //                              language.dll match for 0x24ee: "On"
    //         0043be18     PUSH       0x24ee
    //         0043be1d     PUSH       EAX
    //         0043be1e     PUSH       ESI
    //         0043be1f     MOV        this,ESI
    //         0043be21     CALL       TEasy_Panel::create_text                         int create_text(TEasy_Panel * this, TPanel * 
    //         0043be26     TEST       EAX,EAX
    //         0043be28     JZ         LAB_0043c089
    //                              dlg_conf.cpp:264 (2)
    //         0043be2e     JMP        LAB_0043be61
    //                               LAB_0043be30                                                 XREF[1]:     0043be06(j)  
    //                              dlg_conf.cpp:266 (49)
    //         0043be30     MOV        EAX,EDI
    //         0043be32     LEA        EDX,[ESI + EDI*0x4 + 0x518]
    //         0043be39     SHL        EAX,0x3
    //         0043be3c     SUB        EAX,EDI
    //         0043be3e     LEA        this,[EAX + EAX*0x4 + 0xe1]
    //         0043be45     PUSH       this
    //         0043be46     PUSH       0x16d
    //                              language.dll match for 0x24ef: "Off"
    //         0043be4b     PUSH       0x24ef
    //         0043be50     PUSH       EDX
    //         0043be51     PUSH       ESI
    //         0043be52     MOV        this,ESI
    //         0043be54     CALL       TEasy_Panel::create_text                         int create_text(TEasy_Panel * this, TPanel * 
    //         0043be59     TEST       EAX,EAX
    //         0043be5b     JZ         LAB_0043c089
    //                               LAB_0043be61                                                 XREF[1]:     0043be2e(j)  
    //                              dlg_conf.cpp:268 (62)
    //         0043be61     MOV        EAX,EDI
    //         0043be63     PUSH       0x0
    //         0043be65     SHL        EAX,0x3
    //         0043be68     SUB        EAX,EDI
    //         0043be6a     PUSH       0x0
    //         0043be6c     PUSH       0x1e
    //         0043be6e     PUSH       0x1e
    //         0043be70     LEA        EAX,[EAX + EAX*0x4 + 0xe1]
    //         0043be77     LEA        this,[ESI + EDI*0x4 + 0x520]
    //         0043be7e     PUSH       EAX
    //         0043be7f     PUSH       0x14a
    //         0043be84     PUSH       this
    //         0043be85     PUSH       ESI
    //         0043be86     MOV        this,ESI
    //         0043be88     CALL       TEasy_Panel::create_radio_button                 int create_radio_button(TEasy_Panel * this, T
    //         0043be8d     TEST       EAX,EAX
    //         0043be8f     JZ         LAB_0043c089
    //         0043be95     INC        EDI
    //         0043be96     CMP        EDI,0x2
    //         0043be99     JL         LAB_0043bdf8
    //                              dlg_conf.cpp:270 (13)
    //         0043be9f     LEA        EBX,[ESI + 0x520]
    //         0043bea5     MOV        EBP,0x2
    //         0043beaa     MOV        EDI,EBX
    //                               LAB_0043beac                                                 XREF[1]:     0043beba(j)  
    //                              dlg_conf.cpp:271 (16)
    //         0043beac     MOV        this,dword ptr [EDI]
    //         0043beae     PUSH       0x2
    //         0043beb0     PUSH       EBX
    //         0043beb1     CALL       TButtonPanel::set_radio_info                     void set_radio_info(TButtonPanel * this, TBut
    //         0043beb6     ADD        EDI,0x4
    //         0043beb9     DEC        EBP
    //         0043beba     JNZ        LAB_0043beac
    //                              dlg_conf.cpp:272 (16)
    //         0043bebc     MOV        EDX,dword ptr [rge_base_game]                    = 00000000
    //         0043bec2     MOV        EAX,dword ptr [EDX + 0xa08]
    //         0043bec8     TEST       EAX,EAX
    //         0043beca     JZ         LAB_0043bed0
    //                              dlg_conf.cpp:273 (2)
    //         0043becc     MOV        this,dword ptr [EBX]
    //                              dlg_conf.cpp:274 (2)
    //         0043bece     JMP        LAB_0043bed6
    //                               LAB_0043bed0                                                 XREF[1]:     0043beca(j)  
    //                              dlg_conf.cpp:275 (11)
    //         0043bed0     MOV        this,dword ptr [ESI + 0x524]
    //                               LAB_0043bed6                                                 XREF[1]:     0043bece(j)  
    //         0043bed6     CALL       TButtonPanel::set_radio_button                   void set_radio_button(TButtonPanel * this)
    //                              dlg_conf.cpp:278 (53)
    //         0043bedb     PUSH       0x0
    //         0043bedd     PUSH       0x1
    //         0043bedf     PUSH       0x0
    //         0043bee1     PUSH       0xb
    //         0043bee3     PUSH       0x1e
    //         0043bee5     PUSH       0xd2
    //         0043beea     PUSH       0xbe
    //         0043beef     PUSH       0x1cc
    //         0043bef4     LEA        EAX,[ESI + 0x528]
    //                              language.dll match for 0x260d: "Path Finding"
    //         0043befa     PUSH       0x260d
    //         0043beff     PUSH       EAX
    //         0043bf00     PUSH       ESI
    //         0043bf01     MOV        this,ESI
    //         0043bf03     CALL       TEasy_Panel::create_text                         int create_text(TEasy_Panel * this, TPanel * 
    //         0043bf08     TEST       EAX,EAX
    //         0043bf0a     JZ         LAB_0043c089
    //                              dlg_conf.cpp:279 (13)
    //         0043bf10     XOR        EBP,EBP
    //         0043bf12     MOV        EDI,0xe1
    //         0043bf17     LEA        EBX,[ESI + 0x538]
    //                               LAB_0043bf1d                                                 XREF[1]:     0043bf8e(j)  
    //                              dlg_conf.cpp:281 (45)
    //         0043bf1d     PUSH       0x0
    //         0043bf1f     PUSH       0x1
    //         0043bf21     PUSH       0x0
    //         0043bf23     PUSH       0xb
    //         0043bf25     PUSH       0x1e
    //                              language.dll match for 0x78: "10"
    //         0043bf27     PUSH       0x78
    //         0043bf29     PUSH       EDI
    //         0043bf2a     LEA        EAX,[EBP + 0x260e]
    //         0043bf30     PUSH       0x1ef
    //         0043bf35     LEA        this,[EBX + -0xc]
    //         0043bf38     PUSH       EAX
    //         0043bf39     PUSH       this
    //         0043bf3a     PUSH       ESI
    //         0043bf3b     MOV        this,ESI
    //         0043bf3d     CALL       TEasy_Panel::create_text                         int create_text(TEasy_Panel * this, TPanel * 
    //         0043bf42     TEST       EAX,EAX
    //         0043bf44     JZ         LAB_0043c089
    //                              dlg_conf.cpp:282 (31)
    //         0043bf4a     PUSH       0x0
    //         0043bf4c     PUSH       0x0
    //         0043bf4e     PUSH       0x1e
    //         0043bf50     PUSH       0x1e
    //         0043bf52     PUSH       EDI
    //         0043bf53     PUSH       0x1cc
    //         0043bf58     PUSH       EBX
    //         0043bf59     PUSH       ESI
    //         0043bf5a     MOV        this,ESI
    //         0043bf5c     CALL       TEasy_Panel::create_radio_button                 int create_radio_button(TEasy_Panel * this, T
    //         0043bf61     TEST       EAX,EAX
    //         0043bf63     JZ         LAB_0043c089
    //                              dlg_conf.cpp:283 (15)
    //         0043bf69     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0043bf6f     CALL       RGE_Base_Game::multiplayerGame                   int multiplayerGame(RGE_Base_Game * this)
    //         0043bf74     TEST       EAX,EAX
    //         0043bf76     JZ         LAB_0043bf81
    //                              dlg_conf.cpp:284 (24)
    //         0043bf78     MOV        this,dword ptr [EBX]
    //         0043bf7a     PUSH       0x1
    //         0043bf7c     CALL       TButtonPanel::set_disabled                       void set_disabled(TButtonPanel * this, int pa
    //                               LAB_0043bf81                                                 XREF[1]:     0043bf76(j)  
    //         0043bf81     ADD        EDI,0x23
    //         0043bf84     INC        EBP
    //         0043bf85     ADD        EBX,0x4
    //         0043bf88     CMP        EDI,0x14a
    //         0043bf8e     JL         LAB_0043bf1d
    //                              dlg_conf.cpp:286 (11)
    //         0043bf90     LEA        EDI,[ESI + 0x538]
    //         0043bf96     MOV        EBX,0x3
    //                               LAB_0043bf9b                                                 XREF[1]:     0043bfaf(j)  
    //                              dlg_conf.cpp:287 (22)
    //         0043bf9b     MOV        this,dword ptr [EDI]
    //         0043bf9d     LEA        EAX,[ESI + 0x538]
    //         0043bfa3     PUSH       0x3
    //         0043bfa5     PUSH       EAX
    //         0043bfa6     CALL       TButtonPanel::set_radio_info                     void set_radio_info(TButtonPanel * this, TBut
    //         0043bfab     ADD        EDI,0x4
    //         0043bfae     DEC        EBX
    //         0043bfaf     JNZ        LAB_0043bf9b
    //                              dlg_conf.cpp:289 (11)
    //         0043bfb1     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0043bfb7     CALL       RGE_Base_Game::multiplayerGame                   int multiplayerGame(RGE_Base_Game * this)
    //                              dlg_conf.cpp:290 (15)
    //         0043bfbc     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0043bfc2     TEST       EAX,EAX
    //         0043bfc4     JZ         LAB_0043bfcd
    //         0043bfc6     CALL       RGE_Base_Game::mpPathFinding                     uchar mpPathFinding(RGE_Base_Game * this)
    //                              dlg_conf.cpp:291 (2)
    //         0043bfcb     JMP        LAB_0043bfd2
    //                               LAB_0043bfcd                                                 XREF[1]:     0043bfc4(j)  
    //                              dlg_conf.cpp:292 (5)
    //         0043bfcd     CALL       RGE_Base_Game::pathFinding                       uchar pathFinding(RGE_Base_Game * this)
    //                               LAB_0043bfd2                                                 XREF[1]:     0043bfcb(j)  
    //                              dlg_conf.cpp:293 (8)
    //         0043bfd2     CMP        AL,0x2
    //         0043bfd4     MOV        byte ptr [ESP + param_1],AL
    //         0043bfd8     JA         LAB_0043bff0
    //                              dlg_conf.cpp:294 (22)
    //         0043bfda     MOV        EDX,dword ptr [ESP + param_1]
    //         0043bfde     AND        EDX,0xff
    //         0043bfe4     MOV        this,dword ptr [ESI + EDX*0x4 + 0x538]
    //         0043bfeb     CALL       TButtonPanel::set_radio_button                   void set_radio_button(TButtonPanel * this)
    //                               LAB_0043bff0                                                 XREF[1]:     0043bfd8(j)  
    //                              dlg_conf.cpp:301 (46)
    //         0043bff0     PUSH       0x0
    //         0043bff2     PUSH       0x0
    //         0043bff4     PUSH       0x0
    //         0043bff6     PUSH       0x1e
    //         0043bff8     PUSH       0xaa
    //         0043bffd     PUSH       0x159
    //         0043c002     PUSH       0x78
    //         0043c004     PUSH       0x0
    //         0043c006     LEA        EBX,[ESI + 0x544]
    //                              language.dll match for 0xfa1: "OK"
    //         0043c00c     PUSH       0xfa1
    //         0043c011     PUSH       EBX
    //         0043c012     PUSH       ESI
    //         0043c013     MOV        this,ESI
    //         0043c015     CALL       TEasy_Panel::create_button                       int create_button(TEasy_Panel * this, TPanel 
    //         0043c01a     TEST       EAX,EAX
    //         0043c01c     JZ         LAB_0043c089
    //                              dlg_conf.cpp:304 (49)
    //         0043c01e     PUSH       0x0
    //         0043c020     PUSH       0x0
    //         0043c022     PUSH       0x0
    //         0043c024     PUSH       0x1e
    //         0043c026     PUSH       0xaa
    //         0043c02b     PUSH       0x159
    //         0043c030     PUSH       0x136
    //         0043c035     PUSH       0x0
    //         0043c037     LEA        EDI,[ESI + 0x548]
    //                              language.dll match for 0xfa2: "Cancel"
    //         0043c03d     PUSH       0xfa2
    //         0043c042     PUSH       EDI
    //         0043c043     PUSH       ESI
    //         0043c044     MOV        this,ESI
    //         0043c046     CALL       TEasy_Panel::create_button                       int create_button(TEasy_Panel * this, TPanel 
    //         0043c04b     TEST       EAX,EAX
    //         0043c04d     JZ         LAB_0043c089
    //                              dlg_conf.cpp:306 (2)
    //         0043c04f     MOV        EAX,dword ptr [EDI]
    //                              dlg_conf.cpp:308 (30)
    //         0043c051     MOV        this,ESI
    //         0043c053     MOV        dword ptr [EAX + 0x298],0x1b
    //         0043c05d     MOV        dword ptr [EAX + 0x29c],0x0
    //         0043c067     MOV        EAX,dword ptr [EBX]
    //         0043c069     PUSH       EAX
    //         0043c06a     CALL       TPanel::set_curr_child                           void set_curr_child(TPanel * this, TPanel * p
    //                              dlg_conf.cpp:318 (2)
    //         0043c06f     MOV        this,dword ptr [EBX]
    //                              dlg_conf.cpp:319 (2)
    //         0043c071     MOV        EDX,dword ptr [EDI]
    //                              dlg_conf.cpp:320 (22)
    //         0043c073     LEA        EAX=>tabList[1],[ESP + 0x14]
    //         0043c077     MOV        dword ptr [ESP + tabList[1]],this
    //         0043c07b     PUSH       0x2
    //         0043c07d     PUSH       EAX
    //         0043c07e     MOV        this,ESI
    //         0043c080     MOV        dword ptr [ESP + tabList[2]],EDX
    //         0043c084     CALL       TPanel::set_tab_order                            void set_tab_order(TPanel * this, TPanel * * 
    //                               LAB_0043c089                                                 XREF[33]:    0043b6db(j), 0043b704(j), 
    //                                                                                                         0043b72a(j), 0043b783(j), 
    //                                                                                                         0043b7a6(j), 0043b877(j), 
    //                                                                                                         0043b8a6(j), 0043b8d8(j), 
    //                                                                                                         0043b900(j), 0043b980(j), 
    //                                                                                                         0043b9af(j), 0043b9e1(j), 
    //                                                                                                         0043ba09(j), 0043ba85(j), 
    //                                                                                                         0043bab4(j), 0043bae6(j), 
    //                                                                                                         0043bb0e(j), 0043bb60(j), 
    //                                                                                                         0043bbbc(j), 0043bbdf(j), [more]
    //                              dlg_conf.cpp:321 (23)
    //         0043c089     MOV        this,dword ptr [ESP + local_c]
    //         0043c08d     MOV        EAX,ESI
    //         0043c08f     POP        EDI
    //         0043c090     POP        ESI
    //         0043c091     POP        EBP
    //         0043c092     MOV        dword ptr FS:[0x0],this
    //         0043c099     POP        EBX
    //         0043c09a     ADD        ESP,0x38
    //         0043c09d     RET        0x8
    return;
}

long TribeAboutDialog::action(TPanel* param_1, long param_2, ulong param_3, ulong param_4) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return 0;
}

