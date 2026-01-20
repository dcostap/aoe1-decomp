// Auto-generated scaffold unit: dlg_abt.cpp.asm
// SourceMap: C:/msdev/work/age1_x1/dlg_abt.cpp
#include "../include/common.h"

// Offset: 0x0043AD70
undefined TribeAboutDialog(TribeAboutDialog* this_, TScreenPanel* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall TribeAboutDialog::TribeAboutDialog(class TScreenPanel *)                           *
    //                              *********************************************************************************************************
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
}

// Offset: 0x0043B300
void TribeAboutDialog(TribeAboutDialog* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual __thiscall TribeAboutDialog::~TribeAboutDialog(void)                                  *
    //                              *********************************************************************************************************
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
}

// Offset: 0x0043B400
long TribeAboutDialog::action(TPanel* param_1, long param_2, ulong param_3, ulong param_4) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * protected: virtual long __thiscall TribeAboutDialog::action(class TPanel *,long,unsigned long,unsi... *
    //                              *********************************************************************************************************
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
}

// Offset: 0x0043B550
void TribeAboutDialog::draw() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void __thiscall TribeAboutDialog::draw(void)                                          *
    //                              *********************************************************************************************************
    //                              void __thiscall draw(TribeAboutDialog * this)
    //              void              <VOID>         <RETURN>
    //              TribeAboutDial    ECX:4 (auto)   this
    //                               ?draw@TribeAboutDialog@@UAEXXZ                               XREF[1]:     0056f640(*)  
    //                               TribeAboutDialog::draw
    //                              dlg_abt.cpp:206 (5)
    //         0043b550     JMP        TEasy_Panel::draw
}

