// Auto-generated scaffold unit: Panel_ez.cpp.asm
// SourceMap: C:/msdev/work/age1_x1/Panel_ez.cpp
#include "../include/common.h"

// Offset: 0x00466A20
undefined TEasy_Panel(TEasy_Panel* this_, char* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall TEasy_Panel::TEasy_Panel(char *)                                                   *
    //                              *********************************************************************************************************
    //                              undefined __thiscall TEasy_Panel(TEasy_Panel * this, char * param_1)
    //              undefined         <UNASSIGNED>   <RETURN>
    //              TEasy_Panel *     ECX:4 (auto)   this
    //              char *            Stack[0x4]:4   param_1                   XREF[1]:     00466a36(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     00466a49(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     00466a5c(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     00466a3e(W)  
    //                               ??0TEasy_Panel@@QAE@PAD@Z                                    XREF[2]:     TDialogPanel:00473c18(c), 
    //                               TEasy_Panel::TEasy_Panel                                                  TScreenPanel:0047bab8(c)  
    //                              Panel_ez.cpp:44 (39)
    //         00466a20     PUSH       -0x1
    //         00466a22     PUSH       FUN_0055de38
    //         00466a27     MOV        EAX,FS:[0x0]
    //         00466a2d     PUSH       EAX
    //         00466a2e     MOV        dword ptr FS:[0x0],ESP
    //         00466a35     PUSH       this
    //         00466a36     MOV        EAX,dword ptr [ESP + param_1]
    //         00466a3a     PUSH       ESI
    //         00466a3b     MOV        ESI,this
    //         00466a3d     PUSH       EAX
    //         00466a3e     MOV        dword ptr [ESP + local_10],ESI
    //         00466a42     CALL       TPanel::TPanel                                   undefined TPanel(TPanel * this, char * param_1)
    //                              Panel_ez.cpp:45 (21)
    //         00466a47     MOV        this,ESI
    //         00466a49     MOV        dword ptr [ESP + local_4],0x0
    //         00466a51     MOV        dword ptr [ESI],TEasy_Panel::`vftable'           = 00466a70
    //         00466a57     CALL       TEasy_Panel::init_vars                           void init_vars(TEasy_Panel * this)
    //                              Panel_ez.cpp:46 (20)
    //         00466a5c     MOV        this,dword ptr [ESP + local_c]
    //         00466a60     MOV        EAX,ESI
    //         00466a62     MOV        dword ptr FS:[0x0],this
    //         00466a69     POP        ESI
    //         00466a6a     ADD        ESP,0x10
    //         00466a6d     RET        0x4
}

// Offset: 0x00466A90
long setup(TEasy_Panel* this_, TDrawArea* param_2, TPanel* param_3, char* param_4, long param_5, int param_6, long param_7, long param_8, long param_9, long param_10, int param_11) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: long __thiscall TEasy_Panel::setup(class TDrawArea *,class TPanel *,char *,long,int,long,l... *
    //                              *********************************************************************************************************
    //                              long __thiscall setup(TEasy_Panel * this, TDrawArea * param_1, TPane
    //              long              EAX:4          <RETURN>
    //              TEasy_Panel *     ECX:4 (auto)   this
    //              TDrawArea *       Stack[0x4]:4   param_1                   XREF[4]:     00466ad3(R), 00466b06(R), 00466b3c(R), 00466b66(R)  
    //              TPanel *          Stack[0x8]:4   param_2                   XREF[1]:     00466b72(R)  
    //              char *            Stack[0xc]:4   param_3                   XREF[1]:     00466a96(R)  
    //              long              Stack[0x10]:4  param_4                   XREF[1]:     00466aa9(R)  
    //              int               Stack[0x14]:4  param_5                   XREF[1]:     00466ac8(R)  
    //              long              Stack[0x18]:4  param_6                   XREF[2]:     00466b11(R), 00466b5f(R)  
    //              long              Stack[0x1c]:4  param_7                   XREF[2]:     00466b30(R), 00466b58(R)  
    //              long              Stack[0x20]:4  param_8                   XREF[1]:     00466af0(R)  
    //              long              Stack[0x24]:4  param_9                   XREF[1]:     00466af7(R)  
    //              int               Stack[0x28]:4  param_10                  XREF[1]:     00466a9d(R)  
    //              char[260]         Stack[-0x108   popup_info_file_name_in
    //              char[260]         Stack[-0x20c   background_pic_file_name
    //              char[260]         Stack[-0x310   button_pics_file_name
    //              char[260]         Stack[-0x414   background_pic_file_name
    //              char[260]         Stack[-0x518   cursor_file_name
    //              char[260]         Stack[-0x61c   background_pic_file_name
    //              char[260]         Stack[-0x720   palette_file_name
    //              char[260]         Stack[-0x824   background_pic_file_name
    //              char[260]         Stack[-0x928   background_pic_file_name
    //              char[260]         Stack[-0xa2c   background_pic_file_name
    //              char[260]         Stack[-0xb30   info_file_name2
    //              char[256]         Stack[-0xc30   temp_label
    //              int               Stack[-0xc34   resDataSize
    //              int               Stack[-0xc38   back_pic_id_b1
    //              int               Stack[-0xc3c   shad_amt
    //              int               Stack[-0xc40   t1r
    //              int               Stack[-0xc44   background_color1_in
    //              int               Stack[-0xc48   t1b
    //              int               Stack[-0xc4c   back_pic_id_c1
    //              int               Stack[-0xc50   t2g
    //              int               Stack[-0xc54   cursor_id
    //              int               Stack[-0xc58   bc1
    //              int               Stack[-0xc5c   back_pic_id_a1
    //              int               Stack[-0xc60   bc3
    //              int               Stack[-0xc64   bc5
    //              int               Stack[-0xc68   f2b
    //              int               Stack[-0xc6c   popup_info_id
    //              int               Stack[-0xc70   t1g
    //              int               Stack[-0xc74   button_pic_id
    //              int               Stack[-0xc78   t2r
    //              int               Stack[-0xc7c   s1r
    //              int               Stack[-0xc80   t2b
    //              int               Stack[-0xc84   s1g
    //              int               Stack[-0xc88   bc2
    //              int               Stack[-0xc8c   s1b
    //              int               Stack[-0xc90   bc4
    //              int               Stack[-0xc94   s2r
    //              int               Stack[-0xc98   bc6
    //              int               Stack[-0xc9c   s2g
    //              int               Stack[-0xca0   background_pos_in
    //              int               Stack[-0xca4   s2b
    //              int               Stack[-0xca8   pal_id
    //              int               Stack[-0xcac   f1r
    //              int               Stack[-0xcb0   back_pic_id_a2
    //              int               Stack[-0xcb4   f1g
    //              int               Stack[-0xcb8   back_pic_id_c2
    //              int               Stack[-0xcbc   f1b
    //              int               Stack[-0xcc0   back_pic_id_b2
    //              int               Stack[-0xcc4   f2r
    //              int               Stack[-0xcc8   f2g                       XREF[1]:     00466ab5(W)  
    //              int               Stack[-0xccc   own_mem
    //                               ?setup@TEasy_Panel@@QAEJPAVTDrawArea@@PAVTPanel@@PADJHJJJJH@Z XREF[8]:     setup:00473d09(c), 
    //                               TEasy_Panel::setup                                                        setup:00473dd5(c), 
    //                                                                                                         setup:0047bb00(c), 
    //                                                                                                         setup:0047bb2a(c), 
    //                                                                                                         TribeMPSetupScreen:004a0173(c), 
    //                                                                                                         TRIBE_Screen_Name:004a6431(c), 
    //                                                                                                         TribeSelectScenarioScreen:004b3d14
    //                                                                                                         TribeGameSettingsScreen:004b491a(c
    //                              Panel_ez.cpp:52 (6)
    //         00466a90     SUB        ESP,0xcc8
    //                              Panel_ez.cpp:93 (50)
    //         00466a96     MOV        EDX,dword ptr [ESP + param_3]
    //         00466a9d     MOV        EAX,dword ptr [ESP + param_10]
    //         00466aa4     PUSH       EBX
    //         00466aa5     PUSH       EBP
    //         00466aa6     PUSH       ESI
    //         00466aa7     MOV        ESI,this
    //         00466aa9     MOV        this,dword ptr [ESP + param_4]
    //         00466ab0     PUSH       EDI
    //         00466ab1     PUSH       this
    //         00466ab2     PUSH       EDX
    //         00466ab3     MOV        this,ESI
    //         00466ab5     MOV        dword ptr [ESP + f2g],0xffffffff
    //         00466abd     MOV        dword ptr [ESI + 0x470],EAX
    //         00466ac3     CALL       TEasy_Panel::set_info_file                       void set_info_file(TEasy_Panel * this, char *
    //                              Panel_ez.cpp:96 (11)
    //         00466ac8     MOV        EAX,dword ptr [ESP + param_5]
    //         00466acf     TEST       EAX,EAX
    //         00466ad1     JZ         LAB_00466af0
    //                              Panel_ez.cpp:100 (15)
    //         00466ad3     MOV        EAX,dword ptr [ESP + param_1]
    //         00466ada     XOR        EBX,EBX
    //         00466adc     XOR        this,this
    //         00466ade     TEST       EAX,EAX
    //         00466ae0     JZ         LAB_00466aea
    //                              Panel_ez.cpp:102 (3)
    //         00466ae2     MOV        EBP,dword ptr [EAX + 0x18]
    //                              Panel_ez.cpp:103 (3)
    //         00466ae5     MOV        EDI,dword ptr [EAX + 0x1c]
    //                              Panel_ez.cpp:105 (2)
    //         00466ae8     JMP        LAB_00466b66
    //                               LAB_00466aea                                                 XREF[1]:     00466ae0(j)  
    //                              Panel_ez.cpp:107 (2)
    //         00466aea     XOR        EBP,EBP
    //                              Panel_ez.cpp:108 (2)
    //         00466aec     XOR        EDI,EDI
    //                              Panel_ez.cpp:111 (35)
    //         00466aee     JMP        LAB_00466b66
    //                               LAB_00466af0                                                 XREF[1]:     00466ad1(j)  
    //         00466af0     MOV        EBP,dword ptr [ESP + param_8]
    //         00466af7     MOV        EDI,dword ptr [ESP + param_9]
    //         00466afe     TEST       EBP,EBP
    //         00466b00     JLE        LAB_00466b58
    //         00466b02     TEST       EDI,EDI
    //         00466b04     JLE        LAB_00466b58
    //         00466b06     MOV        EAX,dword ptr [ESP + param_1]
    //         00466b0d     TEST       EAX,EAX
    //         00466b0f     JZ         LAB_00466b58
    //                              Panel_ez.cpp:113 (12)
    //         00466b11     MOV        EBX,dword ptr [ESP + param_6]
    //         00466b18     CMP        EBX,-0x1
    //         00466b1b     JNZ        LAB_00466b30
    //                              Panel_ez.cpp:114 (19)
    //         00466b1d     MOV        EAX,dword ptr [EAX + 0x18]
    //         00466b20     CDQ
    //         00466b21     SUB        EAX,EDX
    //         00466b23     MOV        EBX,EAX
    //         00466b25     MOV        EAX,EBP
    //         00466b27     CDQ
    //         00466b28     SUB        EAX,EDX
    //         00466b2a     SAR        EBX,0x1
    //         00466b2c     SAR        EAX,0x1
    //         00466b2e     SUB        EBX,EAX
    //                               LAB_00466b30                                                 XREF[1]:     00466b1b(j)  
    //                              Panel_ez.cpp:116 (12)
    //         00466b30     MOV        this,dword ptr [ESP + param_7]
    //         00466b37     CMP        this,-0x1
    //         00466b3a     JNZ        LAB_00466b66
    //                              Panel_ez.cpp:117 (42)
    //         00466b3c     MOV        EAX,dword ptr [ESP + param_1]
    //         00466b43     MOV        EAX,dword ptr [EAX + 0x1c]
    //         00466b46     CDQ
    //         00466b47     SUB        EAX,EDX
    //         00466b49     MOV        this,EAX
    //         00466b4b     MOV        EAX,EDI
    //         00466b4d     CDQ
    //         00466b4e     SUB        EAX,EDX
    //         00466b50     SAR        this,0x1
    //         00466b52     SAR        EAX,0x1
    //         00466b54     SUB        this,EAX
    //         00466b56     JMP        LAB_00466b66
    //                               LAB_00466b58                                                 XREF[3]:     00466b00(j), 00466b04(j), 
    //                                                                                                         00466b0f(j)  
    //         00466b58     MOV        this,dword ptr [ESP + param_7]
    //         00466b5f     MOV        EBX,dword ptr [ESP + param_6]
    //                               LAB_00466b66                                                 XREF[4]:     00466ae8(j), 00466aee(j), 
    //                                                                                                         00466b3a(j), 00466b56(j)  
    //                              Panel_ez.cpp:120 (33)
    //         00466b66     MOV        EDX,dword ptr [ESP + param_1]
    //         00466b6d     PUSH       0x0
    //         00466b6f     PUSH       EDI
    //         00466b70     PUSH       EBP
    //         00466b71     PUSH       this
    //         00466b72     MOV        this,dword ptr [ESP + param_2]
    //         00466b79     PUSH       EBX
    //         00466b7a     PUSH       this
    //         00466b7b     PUSH       EDX
    //         00466b7c     MOV        this,ESI
    //         00466b7e     CALL       TPanel::setup                                    long setup(TPanel * this, TDrawArea * param_1
    //         00466b83     TEST       EAX,EAX
    //         00466b85     JNZ        LAB_00466b94
    //                              Panel_ez.cpp:215 (13)
    //         00466b87     POP        EDI
    //         00466b88     POP        ESI
    //         00466b89     POP        EBP
    //         00466b8a     POP        EBX
    //         00466b8b     ADD        ESP,0xcc8
    //         00466b91     RET        0x28
    //                               LAB_00466b94                                                 XREF[1]:     00466b85(j)  
    //                              Panel_ez.cpp:123 (12)
    //         00466b94     MOV        EBX,dword ptr [ESI]
    //         00466b96     PUSH       EDI
    //         00466b97     PUSH       EBP
    //         00466b98     MOV        this,ESI
    //         00466b9a     CALL       dword ptr [EBX + 0xe4]
    //                              Panel_ez.cpp:125 (11)
    //         00466ba0     MOV        EAX,dword ptr [ESP + 0xcec]
    //         00466ba7     TEST       EAX,EAX
    //         00466ba9     JZ         LAB_00466bca
    //                              Panel_ez.cpp:126 (31)
    //         00466bab     PUSH       0x0
    //         00466bad     PUSH       0x0=>DAT_fffffff8
    //         00466baf     PUSH       0x0=>DAT_fffffff4
    //         00466bb1     PUSH       0x0=>DAT_fffffff0
    //         00466bb3     PUSH       0x0
    //         00466bb5     PUSH       0x0
    //         00466bb7     PUSH       0x0
    //         00466bb9     PUSH       0x0
    //         00466bbb     PUSH       0x0
    //         00466bbd     PUSH       0x0
    //         00466bbf     PUSH       0x0
    //         00466bc1     PUSH       0x0
    //         00466bc3     PUSH       0x1
    //         00466bc5     MOV        this,ESI
    //         00466bc7     CALL       dword ptr [EBX + 0x18]
    //                               LAB_00466bca                                                 XREF[1]:     00466ba9(j)  
    //                              Panel_ez.cpp:131 (38)
    //         00466bca     MOV        AL,[shape_file_first]                            = 00h
    //         00466bcf     XOR        EBP,EBP
    //         00466bd1     TEST       AL,AL
    //         00466bd3     JZ         LAB_00466c90
    //         00466bd9     LEA        EDI,[ESI + 0xfc]
    //         00466bdf     TEST       EDI,EDI
    //         00466be1     JZ         LAB_00466c90
    //         00466be7     CMP        byte ptr [EDI],0x0
    //         00466bea     JZ         LAB_00466c90
    //                              Panel_ez.cpp:133 (13)
    //         00466bf0     PUSH       0x2e
    //         00466bf2     PUSH       EDI=>DAT_fffffff8
    //         00466bf3     CALL       strchr                                           undefined strchr()
    //         00466bf8     ADD        ESP,0x8
    //         00466bfb     TEST       EAX,EAX
    //                              Panel_ez.cpp:134 (16)
    //         00466bfd     PUSH       EDI
    //         00466bfe     JNZ        LAB_00466c0f
    //         00466c00     LEA        EAX,[ESP + 0x1b0]
    //         00466c07     PUSH       s_%s.sin                                         = "%s.sin"
    //         00466c0c     PUSH       EAX=>DAT_fffffff4
    //                              Panel_ez.cpp:135 (2)
    //         00466c0d     JMP        LAB_00466c1c
    //                               LAB_00466c0f                                                 XREF[1]:     00466bfe(j)  
    //                              Panel_ez.cpp:136 (21)
    //         00466c0f     LEA        this,[ESP + 0x1b0]
    //         00466c16     PUSH       s_%s                                             = "%s"
    //         00466c1b     PUSH       this=>DAT_fffffff4
    //                               LAB_00466c1c                                                 XREF[1]:     00466c0d(j)  
    //         00466c1c     CALL       sprintf                                          undefined sprintf()
    //         00466c21     ADD        ESP,0xc
    //                              Panel_ez.cpp:137 (23)
    //         00466c24     LEA        EDX,[ESP + 0x1ac]
    //         00466c2b     PUSH       0x8000
    //         00466c30     PUSH       EDX=>DAT_fffffff8
    //         00466c31     CALL       __open                                           undefined __open()
    //         00466c36     MOV        EDI,EAX
    //         00466c38     ADD        ESP,0x8
    //                              Panel_ez.cpp:138 (5)
    //         00466c3b     CMP        EDI,-0x1
    //         00466c3e     JZ         LAB_00466c90
    //                              Panel_ez.cpp:140 (13)
    //         00466c40     PUSH       0x2
    //         00466c42     PUSH       0x0=>DAT_fffffff8
    //         00466c44     PUSH       EDI=>DAT_fffffff4
    //         00466c45     CALL       lseek                                            undefined lseek()
    //         00466c4a     ADD        ESP,0xc
    //                              Panel_ez.cpp:141 (11)
    //         00466c4d     PUSH       EDI
    //         00466c4e     CALL       __tell                                           undefined __tell()
    //         00466c53     ADD        ESP,0x4
    //         00466c56     MOV        EBX,EAX
    //                              Panel_ez.cpp:142 (11)
    //         00466c58     PUSH       EBX
    //         00466c59     CALL       malloc                                           undefined malloc()
    //         00466c5e     MOV        EBP,EAX
    //         00466c60     ADD        ESP,0x4
    //                              Panel_ez.cpp:143 (4)
    //         00466c63     TEST       EBP,EBP
    //         00466c65     JZ         LAB_00466c87
    //                              Panel_ez.cpp:145 (13)
    //         00466c67     PUSH       0x0
    //         00466c69     PUSH       0x0=>DAT_fffffff8
    //         00466c6b     PUSH       EDI=>DAT_fffffff4
    //         00466c6c     CALL       lseek                                            undefined lseek()
    //         00466c71     ADD        ESP,0xc
    //                              Panel_ez.cpp:146 (11)
    //         00466c74     PUSH       EBX
    //         00466c75     PUSH       EBP=>DAT_fffffff8
    //         00466c76     PUSH       EDI=>DAT_fffffff4
    //         00466c77     CALL       read                                             undefined read()
    //         00466c7c     ADD        ESP,0xc
    //                              Panel_ez.cpp:147 (8)
    //         00466c7f     MOV        dword ptr [ESP + 0x10],0x1
    //                               LAB_00466c87                                                 XREF[1]:     00466c65(j)  
    //                              Panel_ez.cpp:149 (9)
    //         00466c87     PUSH       EDI
    //         00466c88     CALL       close                                            undefined close()
    //         00466c8d     ADD        ESP,0x4
    //                               LAB_00466c90                                                 XREF[4]:     00466bd3(j), 00466be1(j), 
    //                                                                                                         00466bea(j), 00466c3e(j)  
    //                              Panel_ez.cpp:153 (15)
    //         00466c90     TEST       EBP,EBP
    //         00466c92     JNZ        LAB_00466cc4
    //         00466c94     MOV        EAX,dword ptr [ESI + 0x200]
    //         00466c9a     CMP        EAX,-0x1
    //         00466c9d     JZ         LAB_00466cbc
    //                              Panel_ez.cpp:154 (29)
    //         00466c9f     LEA        this,[ESP + 0xa8]
    //         00466ca6     LEA        EDX,[ESP + 0x10]
    //         00466caa     PUSH       this
    //         00466cab     PUSH       EDX=>DAT_fffffff8
    //         00466cac     PUSH       EAX=>DAT_fffffff4
    //         00466cad     PUSH       offset DAT_fffffff0
    //         00466cb2     CALL       RESFILE_load                                     uchar * RESFILE_load(ulong param_1, ulong par
    //         00466cb7     ADD        ESP,0x10
    //         00466cba     MOV        EBP,EAX
    //                               LAB_00466cbc                                                 XREF[1]:     00466c9d(j)  
    //                              Panel_ez.cpp:156 (8)
    //         00466cbc     TEST       EBP,EBP
    //         00466cbe     JZ         LAB_004670e7
    //                               LAB_00466cc4                                                 XREF[1]:     00466c92(j)  
    //                              Panel_ez.cpp:177 (513)
    //         00466cc4     LEA        EAX,[ESP + 0x38]
    //         00466cc8     LEA        this,[ESP + 0x40]
    //         00466ccc     PUSH       EAX
    //         00466ccd     LEA        EDX,[ESP + 0x4c]
    //         00466cd1     PUSH       this=>DAT_fffffff8
    //         00466cd2     LEA        EAX,[ESP + 0xb4]
    //         00466cd9     PUSH       EDX=>DAT_fffffff4
    //         00466cda     LEA        this,[ESP + 0x5c]
    //         00466cde     PUSH       EAX=>DAT_fffffff0
    //         00466cdf     LEA        EDX,[ESP + 0x68]
    //         00466ce3     PUSH       this
    //         00466ce4     LEA        EAX,[ESP + 0x74]
    //         00466ce8     PUSH       EDX
    //         00466ce9     LEA        this,[ESP + 0xc4]
    //         00466cf0     PUSH       EAX
    //         00466cf1     LEA        EDX,[ESP + 0x90]
    //         00466cf8     PUSH       this
    //         00466cf9     LEA        EAX,[ESP + 0x34]
    //         00466cfd     PUSH       EDX
    //         00466cfe     LEA        this,[ESP + 0x3c]
    //         00466d02     PUSH       EAX
    //         00466d03     LEA        EDX,[ESP + 0xd4]
    //         00466d0a     PUSH       this
    //         00466d0b     LEA        EAX,[ESP + 0x4c]
    //         00466d0f     PUSH       EDX
    //         00466d10     LEA        this,[ESP + 0x58]
    //         00466d14     PUSH       EAX
    //         00466d15     LEA        EDX,[ESP + 0x64]
    //         00466d19     PUSH       this
    //         00466d1a     LEA        EAX,[ESP + 0xe4]
    //         00466d21     PUSH       EDX
    //         00466d22     LEA        this,[ESP + 0x98]
    //         00466d29     PUSH       EAX
    //         00466d2a     LEA        EDX,[ESP + 0xcc]
    //         00466d31     PUSH       this
    //         00466d32     LEA        EAX,[ESP + 0xa8]
    //         00466d39     PUSH       EDX
    //         00466d3a     LEA        this,[ESP + 0xf4]
    //         00466d41     PUSH       EAX
    //         00466d42     LEA        EDX,[ESP + 0xe0]
    //         00466d49     PUSH       this
    //         00466d4a     LEA        EAX,[ESP + 0xbc]
    //         00466d51     PUSH       EDX
    //         00466d52     LEA        this,[ESP + 0xf0]
    //         00466d59     PUSH       EAX
    //         00466d5a     LEA        EDX,[ESP + 0x104]
    //         00466d61     PUSH       this
    //         00466d62     LEA        EAX,[ESP + 0xa0]
    //         00466d69     PUSH       EDX
    //         00466d6a     LEA        this,[ESP + 0xd8]
    //         00466d71     PUSH       EAX
    //         00466d72     LEA        EDX,[ESP + 0xb0]
    //         00466d79     PUSH       this
    //         00466d7a     LEA        EAX,[ESP + 0xe4]
    //         00466d81     PUSH       EDX
    //         00466d82     LEA        this,[ESP + 0xc0]
    //         00466d89     PUSH       EAX
    //         00466d8a     LEA        EDX,[ESP + 0xf4]
    //         00466d91     PUSH       this
    //         00466d92     LEA        EAX,[ESP + 0x120]
    //         00466d99     PUSH       EDX
    //         00466d9a     LEA        this,[ESP + 0x110]
    //         00466da1     PUSH       EAX
    //         00466da2     LEA        EDX,[ESP + 0x128]
    //         00466da9     PUSH       this
    //         00466daa     LEA        EAX,[ESP + 0xbc]
    //         00466db1     PUSH       EDX
    //         00466db2     LEA        this,[ESP + 0x130]
    //         00466db9     PUSH       EAX
    //         00466dba     LEA        EDX,[ESP + 0xf8]
    //         00466dc1     PUSH       this
    //         00466dc2     LEA        EAX,[ESP + 0xc60]
    //         00466dc9     PUSH       EDX
    //         00466dca     LEA        this,[ESP + 0x13c]
    //         00466dd1     PUSH       EAX
    //         00466dd2     LEA        EDX,[ESP + 0xfc]
    //         00466dd9     PUSH       this
    //         00466dda     LEA        EAX,[ESP + 0xa64]
    //         00466de1     PUSH       EDX
    //         00466de2     PUSH       EAX
    //         00466de3     LEA        this,[ESP + 0x14c]
    //         00466dea     LEA        EDX,[ESP + 0x140]
    //         00466df1     PUSH       this
    //         00466df2     LEA        EAX,[ESP + 0x150]
    //         00466df9     PUSH       EDX
    //         00466dfa     LEA        this,[ESP + 0x154]
    //         00466e01     PUSH       EAX
    //         00466e02     LEA        EDX,[ESP + 0x134]
    //         00466e09     PUSH       this
    //         00466e0a     LEA        EAX,[ESP + 0x874]
    //         00466e11     PUSH       EDX
    //         00466e12     LEA        this,[ESP + 0x160]
    //         00466e19     PUSH       EAX
    //         00466e1a     LEA        EDX,[ESP + 0xec]
    //         00466e21     PUSH       this
    //         00466e22     LEA        EAX,[ESP + 0x678]
    //         00466e29     PUSH       EDX
    //         00466e2a     LEA        this,[ESP + 0x16c]
    //         00466e31     PUSH       EAX
    //         00466e32     LEA        EDX,[ESP + 0xe8]
    //         00466e39     PUSH       this
    //         00466e3a     LEA        EAX,[ESP + 0x158]
    //         00466e41     PUSH       EDX
    //         00466e42     LEA        this,[ESP + 0x480]
    //         00466e49     PUSH       EAX
    //         00466e4a     LEA        EDX,[ESP + 0x998]
    //         00466e51     PUSH       this
    //         00466e52     LEA        EAX,[ESP + 0x180]
    //         00466e59     PUSH       EDX
    //         00466e5a     LEA        this,[ESP + 0xf4]
    //         00466e61     PUSH       EAX
    //         00466e62     LEA        EDX,[ESP + 0x180]
    //         00466e69     PUSH       this
    //         00466e6a     LEA        EAX,[ESP + 0x7a0]
    //         00466e71     PUSH       EDX
    //         00466e72     LEA        this,[ESP + 0x394]
    //         00466e79     PUSH       EAX
    //         00466e7a     LEA        EDX,[ESP + 0x194]
    //         00466e81     PUSH       this
    //         00466e82     LEA        EAX,[ESP + 0x118]
    //         00466e89     PUSH       EDX
    //         00466e8a     LEA        this,[ESP + 0x170]
    //         00466e91     PUSH       EAX
    //         00466e92     LEA        EDX,[ESP + 0x5ac]
    //         00466e99     PUSH       this
    //         00466e9a     LEA        EAX,[ESP + 0xbc8]
    //         00466ea1     PUSH       EDX
    //         00466ea2     LEA        this,[ESP + 0x1a8]
    //         00466ea9     PUSH       EAX
    //         00466eaa     PUSH       this
    //         00466eab     PUSH       s_%s_%s_%s_%d_%d___%s_%s_%s_%d_%d_               = "%s %s %s %d %d   %s %s %s %d %d   %s %s %s
    //         00466eb0     PUSH       EBP
    //         00466eb1     CALL       sscanf                                           undefined sscanf()
    //         00466eb6     ADD        ESP,0x10c
    //         00466ebc     CMP        EAX,-0x1
    //         00466ebf     JZ         LAB_004670d7
    //                              Panel_ez.cpp:179 (9)
    //         00466ec5     PUSH       0x1
    //         00466ec7     MOV        this,ESI
    //         00466ec9     CALL       TEasy_Panel::set_use_bevels                      void set_use_bevels(TEasy_Panel * this, int p
    //                              Panel_ez.cpp:181 (37)
    //         00466ece     MOV        EDX,dword ptr [ESI + 0x20]
    //         00466ed1     CMP        dword ptr [EDX + 0x18],0x320
    //         00466ed8     JL         LAB_00466f4b
    //         00466eda     LEA        EAX,[ESP + 0x2b0]
    //         00466ee1     PUSH       s_none                                           = "none"
    //         00466ee6     PUSH       EAX=>DAT_fffffff8
    //         00466ee7     CALL       stricmp                                          undefined stricmp()
    //         00466eec     ADD        ESP,0x8
    //         00466eef     TEST       EAX,EAX
    //         00466ef1     JZ         LAB_00466f4b
    //                              Panel_ez.cpp:186 (12)
    //         00466ef3     MOV        this,dword ptr [ESI + 0x20]
    //         00466ef6     CMP        dword ptr [ECX + this->_padding_],0x400
    //         00466efd     JGE        LAB_00466f25
    //                              Panel_ez.cpp:188 (23)
    //         00466eff     MOV        EDX,dword ptr [ESP + 0xa4]
    //         00466f06     LEA        EAX,[ESP + 0x2b0]
    //         00466f0d     PUSH       EDX
    //         00466f0e     PUSH       EAX=>DAT_fffffff8
    //         00466f0f     MOV        this,ESI
    //         00466f11     CALL       TEasy_Panel::set_background                      int set_background(TEasy_Panel * this, char *
    //                              Panel_ez.cpp:189 (13)
    //         00466f16     MOV        this,dword ptr [ESP + 0x1c]
    //         00466f1a     LEA        EDX,[ESP + 0x6c0]
    //         00466f21     PUSH       this
    //         00466f22     PUSH       EDX=>DAT_fffffff8
    //                              Panel_ez.cpp:191 (2)
    //         00466f23     JMP        LAB_00466f6f
    //                               LAB_00466f25                                                 XREF[1]:     00466efd(j)  
    //                              Panel_ez.cpp:193 (23)
    //         00466f25     MOV        EAX,dword ptr [ESP + 0x90]
    //         00466f2c     LEA        this,[ESP + 0x8c8]
    //         00466f33     PUSH       EAX
    //         00466f34     PUSH       this=>DAT_fffffff8
    //         00466f35     MOV        this,ESI
    //         00466f37     CALL       TEasy_Panel::set_background                      int set_background(TEasy_Panel * this, char *
    //                              Panel_ez.cpp:194 (15)
    //         00466f3c     MOV        EDX,dword ptr [ESP + 0x24]
    //         00466f40     LEA        EAX,[ESP + 0x3b4]
    //         00466f47     PUSH       EDX
    //         00466f48     PUSH       EAX=>DAT_fffffff8
    //         00466f49     JMP        LAB_00466f6f
    //                               LAB_00466f4b                                                 XREF[2]:     00466ed8(j), 00466ef1(j)  
    //                              Panel_ez.cpp:183 (23)
    //         00466f4b     MOV        this,dword ptr [ESP + 0x80]
    //         00466f52     LEA        EDX,[ESP + 0xad0]
    //         00466f59     PUSH       this
    //         00466f5a     PUSH       EDX=>DAT_fffffff8
    //         00466f5b     MOV        this,ESI
    //         00466f5d     CALL       TEasy_Panel::set_background                      int set_background(TEasy_Panel * this, char *
    //                              Panel_ez.cpp:184 (20)
    //         00466f62     MOV        EAX,dword ptr [ESP + 0x2c]
    //         00466f66     LEA        this,[ESP + 0x4b8]
    //         00466f6d     PUSH       EAX
    //         00466f6e     PUSH       this=>DAT_fffffff8
    //                               LAB_00466f6f                                                 XREF[2]:     00466f23(j), 00466f49(j)  
    //         00466f6f     MOV        this,ESI
    //         00466f71     CALL       TEasy_Panel::set_background2                     int set_background2(TEasy_Panel * this, char 
    //                              Panel_ez.cpp:197 (15)
    //         00466f76     MOV        EDX,dword ptr [ESP + 0xa0]
    //         00466f7d     MOV        this,ESI
    //         00466f7f     PUSH       EDX
    //         00466f80     CALL       TEasy_Panel::set_shadow_amount                   void set_shadow_amount(TEasy_Panel * this, lo
    //                              Panel_ez.cpp:198 (20)
    //         00466f85     MOV        EAX,dword ptr [ESP + 0x34]
    //         00466f89     LEA        this,[ESP + 0x5bc]
    //         00466f90     PUSH       EAX
    //         00466f91     PUSH       this=>DAT_fffffff8
    //         00466f92     MOV        this,ESI
    //         00466f94     CALL       TEasy_Panel::set_palette                         int set_palette(TEasy_Panel * this, char * pa
    //                              Panel_ez.cpp:199 (23)
    //         00466f99     MOV        EDX,dword ptr [ESP + 0x88]
    //         00466fa0     LEA        EAX,[ESP + 0x7c4]
    //         00466fa7     PUSH       EDX
    //         00466fa8     PUSH       EAX=>DAT_fffffff8
    //         00466fa9     MOV        this,ESI
    //         00466fab     CALL       TEasy_Panel::set_cursor                          int set_cursor(TEasy_Panel * this, char * par
    //                              Panel_ez.cpp:200 (12)
    //         00466fb0     MOV        this,dword ptr [ESP + 0x3c]
    //         00466fb4     PUSH       this
    //         00466fb5     MOV        this,ESI
    //         00466fb7     CALL       TEasy_Panel::set_background_pos                  void set_background_pos(TEasy_Panel * this, i
    //                              Panel_ez.cpp:201 (16)
    //         00466fbc     MOV        EAX,dword ptr [ESP + 0x98]
    //         00466fc3     MOV        this,ESI
    //         00466fc5     PUSH       EAX
    //         00466fc6     PUSH       EAX=>DAT_fffffff8
    //         00466fc7     CALL       TEasy_Panel::set_background_colors               void set_background_colors(TEasy_Panel * this
    //                              Panel_ez.cpp:202 (43)
    //         00466fcc     MOV        EDX,dword ptr [ESP + 0x44]
    //         00466fd0     MOV        EAX,dword ptr [ESP + 0x78]
    //         00466fd4     MOV        this,dword ptr [ESP + 0x4c]
    //         00466fd8     PUSH       EDX
    //         00466fd9     MOV        EDX,dword ptr [ESP + 0x80]
    //         00466fe0     PUSH       EAX=>DAT_fffffff8
    //         00466fe1     MOV        EAX,dword ptr [ESP + 0x5c]
    //         00466fe5     PUSH       this=>DAT_fffffff4
    //         00466fe6     MOV        this,dword ptr [ESP + 0x90]
    //         00466fed     PUSH       EDX=>DAT_fffffff0
    //         00466fee     PUSH       EAX
    //         00466fef     PUSH       this
    //         00466ff0     MOV        this,ESI
    //         00466ff2     CALL       TEasy_Panel::set_bevel_colors                    void set_bevel_colors(TEasy_Panel * this, uch
    //                              Panel_ez.cpp:203 (67)
    //         00466ff7     MOV        EAX,dword ptr [ESP + 0x64]
    //         00466ffb     XOR        EDX,EDX
    //         00466ffd     MOV        DH,byte ptr [ESP + 0x5c]
    //         00467001     AND        EAX,0xff
    //         00467006     MOV        DL,byte ptr [ESP + 0x8c]
    //         0046700d     XOR        this,this
    //         0046700f     MOV        this,byte ptr [ESP + 0x94]
    //         00467016     MOV        this,byte ptr [ESP + 0x6c]
    //         0046701a     SHL        EDX,0x8
    //         0046701d     OR         EDX,EAX
    //         0046701f     PUSH       EDX
    //         00467020     MOV        EDX,dword ptr [ESP + 0xa0]
    //         00467027     SHL        this,0x8
    //         0046702a     AND        EDX,0xff
    //         00467030     OR         this,EDX
    //         00467032     PUSH       this=>DAT_fffffff8
    //         00467033     MOV        this,ESI
    //         00467035     CALL       TEasy_Panel::set_text_colors                     void set_text_colors(TEasy_Panel * this, ulon
    //                              Panel_ez.cpp:204 (58)
    //         0046703a     MOV        this,dword ptr [ESP + 0x18]
    //         0046703e     XOR        EAX,EAX
    //         00467040     MOV        AH,byte ptr [ESP + 0x74]
    //         00467044     AND        this,0xff
    //         0046704a     MOV        AL,byte ptr [ESP + 0x14]
    //         0046704e     XOR        EDX,EDX
    //         00467050     MOV        DH,byte ptr [ESP + 0x20]
    //         00467054     MOV        DL,byte ptr [ESP + 0x28]
    //         00467058     SHL        EAX,0x8
    //         0046705b     OR         EAX,this
    //         0046705d     MOV        this,ESI
    //         0046705f     PUSH       EAX
    //         00467060     MOV        EAX,dword ptr [ESP + 0x34]
    //         00467064     SHL        EDX,0x8
    //         00467067     AND        EAX,0xff
    //         0046706c     OR         EDX,EAX
    //         0046706e     PUSH       EDX=>DAT_fffffff8
    //         0046706f     CALL       TEasy_Panel::set_focus_colors                    void set_focus_colors(TEasy_Panel * this, ulo
    //                              Panel_ez.cpp:205 (59)
    //         00467074     XOR        this,this
    //         00467076     MOV        this,byte ptr [ESP + 0x38]
    //         0046707a     MOV        this,byte ptr [ESP + 0x40]
    //         0046707e     SHL        this,0x8
    //         00467081     MOV        EDX,dword ptr [ESP + 0x48]
    //         00467085     XOR        EAX,EAX
    //         00467087     MOV        AH,byte ptr [ESP + 0x50]
    //         0046708b     AND        EDX,0xff
    //         00467091     MOV        AL,byte ptr [ESP + 0x58]
    //         00467095     OR         this,EDX
    //         00467097     PUSH       this
    //         00467098     MOV        this,dword ptr [ESP + 0x64]
    //         0046709c     SHL        EAX,0x8
    //         0046709f     AND        this,0xff
    //         004670a5     OR         EAX,this
    //         004670a7     MOV        this,ESI
    //         004670a9     PUSH       EAX=>DAT_fffffff8
    //         004670aa     CALL       TEasy_Panel::set_state_colors                    void set_state_colors(TEasy_Panel * this, ulo
    //                              Panel_ez.cpp:206 (20)
    //         004670af     MOV        EDX,dword ptr [ESP + 0x68]
    //         004670b3     LEA        EAX,[ESP + 0x9cc]
    //         004670ba     PUSH       EDX
    //         004670bb     PUSH       EAX=>DAT_fffffff8
    //         004670bc     MOV        this,ESI
    //         004670be     CALL       TEasy_Panel::set_button_pics                     void set_button_pics(TEasy_Panel * this, char
    //                              Panel_ez.cpp:207 (20)
    //         004670c3     MOV        this,dword ptr [ESP + 0x70]
    //         004670c7     LEA        EDX,[ESP + 0xbd4]
    //         004670ce     PUSH       this
    //         004670cf     PUSH       EDX=>DAT_fffffff8
    //         004670d0     MOV        this,ESI
    //         004670d2     CALL       TEasy_Panel::set_popup_info_file                 void set_popup_info_file(TEasy_Panel * this, 
    //                               LAB_004670d7                                                 XREF[1]:     00466ebf(j)  
    //                              Panel_ez.cpp:210 (7)
    //         004670d7     CMP        dword ptr [ESP + 0x10],0x1
    //         004670dc     JNZ        LAB_004670e7
    //                              Panel_ez.cpp:211 (9)
    //         004670de     PUSH       EBP
    //         004670df     CALL       free                                             undefined free()
    //         004670e4     ADD        ESP,0x4
    //                               LAB_004670e7                                                 XREF[2]:     00466cbe(j), 004670dc(j)  
    //                              Panel_ez.cpp:215 (18)
    //         004670e7     POP        EDI
    //         004670e8     POP        ESI
    //         004670e9     POP        EBP
    //         004670ea     MOV        EAX,0x1
    //         004670ef     POP        EBX
    //         004670f0     ADD        ESP,0xcc8
    //         004670f6     RET        0x28
}

// Offset: 0x00467100
undefined TEasy_Panel(TEasy_Panel* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall TEasy_Panel::TEasy_Panel(void)                                                     *
    //                              *********************************************************************************************************
    //                              undefined __thiscall TEasy_Panel(TEasy_Panel * this)
    //              undefined         <UNASSIGNED>   <RETURN>
    //              TEasy_Panel *     ECX:4 (auto)   this
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     00467124(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     00467137(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     00467119(W)  
    //                               ??0TEasy_Panel@@QAE@XZ                                       XREF[2]:     TScreenPanel:0047ba73(c), 
    //                               TEasy_Panel::TEasy_Panel                                                  Time_Line_Panel:0051e653(c)  
    //                              Panel_ez.cpp:222 (34)
    //         00467100     PUSH       -0x1
    //         00467102     PUSH       FUN_0055de58
    //         00467107     MOV        EAX,FS:[0x0]
    //         0046710d     PUSH       EAX
    //         0046710e     MOV        dword ptr FS:[0x0],ESP
    //         00467115     PUSH       this
    //         00467116     PUSH       ESI
    //         00467117     MOV        ESI,this
    //         00467119     MOV        dword ptr [ESP + local_10],ESI
    //         0046711d     CALL       TPanel::TPanel                                   undefined TPanel(TPanel * this)
    //                              Panel_ez.cpp:223 (21)
    //         00467122     MOV        this,ESI
    //         00467124     MOV        dword ptr [ESP + local_4],0x0
    //         0046712c     MOV        dword ptr [ESI],TEasy_Panel::`vftable'           = 00466a70
    //         00467132     CALL       TEasy_Panel::init_vars                           void init_vars(TEasy_Panel * this)
    //                              Panel_ez.cpp:224 (18)
    //         00467137     MOV        this,dword ptr [ESP + local_c]
    //         0046713b     MOV        EAX,ESI
    //         0046713d     MOV        dword ptr FS:[0x0],this
    //         00467144     POP        ESI
    //         00467145     ADD        ESP,0x10
    //         00467148     RET
}

// Offset: 0x00467150
void init_vars(TEasy_Panel* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * protected: void __thiscall TEasy_Panel::init_vars(void)                                               *
    //                              *********************************************************************************************************
    //                              void __thiscall init_vars(TEasy_Panel * this)
    //              void              <VOID>         <RETURN>
    //              TEasy_Panel *     ECX:4 (auto)   this
    //                               ?init_vars@TEasy_Panel@@IAEXXZ                               XREF[2]:     TEasy_Panel:00466a57(c), 
    //                               TEasy_Panel::init_vars                                                    TEasy_Panel:00467132(c)  
    //                              Panel_ez.cpp:230 (10)
    //         00467150     MOV        dword ptr [ECX + this->ideal_width],0x280
    //                              Panel_ez.cpp:233 (12)
    //         0046715a     XOR        EAX,EAX
    //         0046715c     MOV        dword ptr [ECX + this->ideal_height],0x1e0
    //                              Panel_ez.cpp:234 (15)
    //         00467166     OR         EDX,0xffffffff
    //         00467169     MOV        byte ptr [ECX + this->info_file_name[0]],AL
    //         0046716f     MOV        dword ptr [ECX + this->info_id],EDX
    //                              Panel_ez.cpp:235 (6)
    //         00467175     MOV        dword ptr [ECX + this->background_pic],EAX
    //                              Panel_ez.cpp:236 (6)
    //         0046717b     MOV        dword ptr [ECX + this->background_pic2],EAX
    //                              Panel_ez.cpp:237 (6)
    //         00467181     MOV        dword ptr [ECX + this->palette],EAX
    //                              Panel_ez.cpp:238 (6)
    //         00467187     MOV        byte ptr [ECX + this->cursor_file[0]],AL
    //                              Panel_ez.cpp:239 (6)
    //         0046718d     MOV        dword ptr [ECX + this->cursor_id],EDX
    //                              Panel_ez.cpp:240 (6)
    //         00467193     MOV        dword ptr [ECX + this->background_pos],EAX
    //                              Panel_ez.cpp:241 (6)
    //         00467199     MOV        dword ptr [ECX + this->use_bevels],EAX
    //                              Panel_ez.cpp:242 (6)
    //         0046719f     MOV        byte ptr [ECX + this->bevel_color1],AL
    //                              Panel_ez.cpp:243 (6)
    //         004671a5     MOV        byte ptr [ECX + this->bevel_color2],AL
    //                              Panel_ez.cpp:244 (6)
    //         004671ab     MOV        byte ptr [ECX + this->bevel_color3],AL
    //                              Panel_ez.cpp:245 (6)
    //         004671b1     MOV        byte ptr [ECX + this->bevel_color4],AL
    //                              Panel_ez.cpp:246 (6)
    //         004671b7     MOV        byte ptr [ECX + this->bevel_color5],AL
    //                              Panel_ez.cpp:247 (6)
    //         004671bd     MOV        byte ptr [ECX + this->bevel_color6],AL
    //                              Panel_ez.cpp:248 (10)
    //         004671c3     MOV        dword ptr [ECX + this->text_color1],0xffffff
    //                              Panel_ez.cpp:249 (6)
    //         004671cd     MOV        dword ptr [ECX + this->text_color2],EAX
    //                              Panel_ez.cpp:250 (10)
    //         004671d3     MOV        dword ptr [ECX + this->focus_color1],0xffff
    //                              Panel_ez.cpp:251 (6)
    //         004671dd     MOV        dword ptr [ECX + this->focus_color2],EAX
    //                              Panel_ez.cpp:252 (10)
    //         004671e3     MOV        dword ptr [ECX + this->state_color1],0xffffff
    //                              Panel_ez.cpp:253 (6)
    //         004671ed     MOV        dword ptr [ECX + this->state_color2],EAX
    //                              Panel_ez.cpp:254 (6)
    //         004671f3     MOV        byte ptr [ECX + this->popup_info_file_name[0]]
    //                              Panel_ez.cpp:255 (6)
    //         004671f9     MOV        dword ptr [ECX + this->popup_info_id],EDX
    //                              Panel_ez.cpp:256 (6)
    //         004671ff     MOV        dword ptr [ECX + this->button_pics],EAX
    //                              Panel_ez.cpp:257 (6)
    //         00467205     MOV        dword ptr [ECX + this->shadow_color_table],EAX
    //                              Panel_ez.cpp:258 (6)
    //         0046720b     MOV        byte ptr [ECX + this->background_color1],AL
    //                              Panel_ez.cpp:259 (6)
    //         00467211     MOV        byte ptr [ECX + this->background_color2],AL
    //                              Panel_ez.cpp:260 (6)
    //         00467217     MOV        dword ptr [ECX + this->enable_ime],EAX
    //                              Panel_ez.cpp:261 (6)
    //         0046721d     MOV        byte ptr [ECX + this->help_mode],AL
    //                              Panel_ez.cpp:262 (6)
    //         00467223     MOV        dword ptr [ECX + this->stock_brush],EAX
    //                              Panel_ez.cpp:263 (6)
    //         00467229     MOV        dword ptr [ECX + this->brush],EAX
    //                              Panel_ez.cpp:264 (6)
    //         0046722f     MOV        dword ptr [ECX + this->brush_color],EAX
    //                              Panel_ez.cpp:265 (6)
    //         00467235     MOV        dword ptr [ECX + this->shadow_amount],EAX
    //                              Panel_ez.cpp:266 (6)
    //         0046723b     MOV        dword ptr [ECX + this->shadow_area],EAX
    //                              Panel_ez.cpp:267 (6)
    //         00467241     MOV        dword ptr [ECX + this->saved_mouse_mode],EAX
    //                              Panel_ez.cpp:268 (1)
    //         00467247     RET
}

// Offset: 0x00467250
void TEasy_Panel(TEasy_Panel* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual __thiscall TEasy_Panel::~TEasy_Panel(void)                                            *
    //                              *********************************************************************************************************
    //                              void __thiscall ~TEasy_Panel(TEasy_Panel * this)
    //              void              <VOID>         <RETURN>
    //              TEasy_Panel *     ECX:4 (auto)   this
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     00467273(W), 00467282(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     0046728f(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     00467269(W)  
    //                               ??1TEasy_Panel@@UAE@XZ                                       XREF[4]:     `scalar_deleting_destructor':00466
    //                               TEasy_Panel::~TEasy_Panel                                                 ~TDialogPanel:00473eab(c), 
    //                                                                                                         ~TScreenPanel:0047bad6(c), 
    //                                                                                                         ~Time_Line_Panel:0051e847(c)  
    //                              Panel_ez.cpp:274 (43)
    //         00467250     PUSH       -0x1
    //         00467252     PUSH       FUN_0055de78
    //         00467257     MOV        EAX,FS:[0x0]
    //         0046725d     PUSH       EAX
    //         0046725e     MOV        dword ptr FS:[0x0],ESP
    //         00467265     PUSH       this
    //         00467266     PUSH       ESI
    //         00467267     MOV        ESI,this
    //         00467269     MOV        dword ptr [ESP + local_10],ESI
    //         0046726d     MOV        dword ptr [ESI],TEasy_Panel::`vftable'           = 00466a70
    //         00467273     MOV        dword ptr [ESP + local_4],0x0
    //                              Panel_ez.cpp:275 (7)
    //         0046727b     CALL       TEasy_Panel::prepare_for_close                   void prepare_for_close(TEasy_Panel * this)
    //         00467280     MOV        this,ESI
    //                              Panel_ez.cpp:276 (29)
    //         00467282     MOV        dword ptr [ESP + local_4],0xffffffff
    //         0046728a     CALL       TPanel::~TPanel                                  void ~TPanel(TPanel * this)
    //         0046728f     MOV        this,dword ptr [ESP + local_c]
    //         00467293     POP        ESI
    //         00467294     MOV        dword ptr FS:[0x0],this
    //         0046729b     ADD        ESP,0x10
    //         0046729e     RET
}

// Offset: 0x004672A0
void prepare_for_close(TEasy_Panel* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TEasy_Panel::prepare_for_close(void)                                          *
    //                              *********************************************************************************************************
    //                              void __thiscall prepare_for_close(TEasy_Panel * this)
    //              void              <VOID>         <RETURN>
    //              TEasy_Panel *     ECX:4 (auto)   this
    //                               ?prepare_for_close@TEasy_Panel@@QAEXXZ                       XREF[2]:     action:0043c671(c), 
    //                               TEasy_Panel::prepare_for_close                                            ~TEasy_Panel:0046727b(c)  
    //                              Panel_ez.cpp:282 (5)
    //         004672a0     PUSH       EBX
    //         004672a1     PUSH       ESI
    //         004672a2     MOV        ESI,this
    //         004672a4     PUSH       EDI
    //                              Panel_ez.cpp:283 (12)
    //         004672a5     XOR        EBX,EBX
    //         004672a7     MOV        EDI,dword ptr [ESI + 0x46c]
    //         004672ad     CMP        EDI,EBX
    //         004672af     JZ         LAB_004672c7
    //                              Panel_ez.cpp:285 (16)
    //         004672b1     MOV        this,EDI
    //         004672b3     CALL       TDrawArea::~TDrawArea                            void ~TDrawArea(TDrawArea * this)
    //         004672b8     PUSH       EDI
    //         004672b9     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         004672be     ADD        ESP,0x4
    //                              Panel_ez.cpp:286 (6)
    //         004672c1     MOV        dword ptr [ESI + 0x46c],EBX
    //                               LAB_004672c7                                                 XREF[1]:     004672af(j)  
    //                              Panel_ez.cpp:289 (10)
    //         004672c7     MOV        EAX,dword ptr [ESI + 0x464]
    //         004672cd     CMP        EAX,EBX
    //         004672cf     JZ         LAB_004672e6
    //                              Panel_ez.cpp:291 (8)
    //         004672d1     CMP        dword ptr [ESI + 0x460],EBX
    //         004672d7     JNZ        LAB_004672e0
    //                              Panel_ez.cpp:292 (7)
    //         004672d9     PUSH       EAX
    //         004672da     CALL       dword ptr [->GDI32.DLL::DeleteObject]            = 0048b160
    //                               LAB_004672e0                                                 XREF[1]:     004672d7(j)  
    //                              Panel_ez.cpp:293 (6)
    //         004672e0     MOV        dword ptr [ESI + 0x464],EBX
    //                               LAB_004672e6                                                 XREF[1]:     004672cf(j)  
    //                              Panel_ez.cpp:296 (10)
    //         004672e6     MOV        EDI,dword ptr [ESI + 0x204]
    //         004672ec     CMP        EDI,EBX
    //         004672ee     JZ         LAB_00467306
    //                              Panel_ez.cpp:298 (16)
    //         004672f0     MOV        this,EDI
    //         004672f2     CALL       TShape::~TShape                                  void ~TShape(TShape * this)
    //         004672f7     PUSH       EDI
    //         004672f8     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         004672fd     ADD        ESP,0x4
    //                              Panel_ez.cpp:299 (6)
    //         00467300     MOV        dword ptr [ESI + 0x204],EBX
    //                               LAB_00467306                                                 XREF[1]:     004672ee(j)  
    //                              Panel_ez.cpp:302 (10)
    //         00467306     MOV        EDI,dword ptr [ESI + 0x208]
    //         0046730c     CMP        EDI,EBX
    //         0046730e     JZ         LAB_00467326
    //                              Panel_ez.cpp:304 (16)
    //         00467310     MOV        this,EDI
    //         00467312     CALL       TShape::~TShape                                  void ~TShape(TShape * this)
    //         00467317     PUSH       EDI
    //         00467318     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         0046731d     ADD        ESP,0x4
    //                              Panel_ez.cpp:305 (6)
    //         00467320     MOV        dword ptr [ESI + 0x208],EBX
    //                               LAB_00467326                                                 XREF[1]:     0046730e(j)  
    //                              Panel_ez.cpp:308 (10)
    //         00467326     MOV        EAX,dword ptr [ESI + 0x20c]
    //         0046732c     CMP        EAX,EBX
    //         0046732e     JZ         LAB_00467341
    //                              Panel_ez.cpp:310 (11)
    //         00467330     PUSH       EAX
    //         00467331     MOV        this,panel_system
    //         00467336     CALL       TPanelSystem::release_palette                    void release_palette(TPanelSystem * this, voi
    //                              Panel_ez.cpp:311 (6)
    //         0046733b     MOV        dword ptr [ESI + 0x20c],EBX
    //                               LAB_00467341                                                 XREF[1]:     0046732e(j)  
    //                              Panel_ez.cpp:314 (10)
    //         00467341     MOV        this,dword ptr [ESI + 0x44c]
    //         00467347     CMP        this,EBX
    //         00467349     JZ         LAB_00467357
    //                              Panel_ez.cpp:316 (6)
    //         0046734b     MOV        EAX,dword ptr [this->_padding_]
    //         0046734d     PUSH       0x1
    //         0046734f     CALL       dword ptr [EAX]
    //                              Panel_ez.cpp:317 (6)
    //         00467351     MOV        dword ptr [ESI + 0x44c],EBX
    //                               LAB_00467357                                                 XREF[1]:     00467349(j)  
    //                              Panel_ez.cpp:320 (10)
    //         00467357     MOV        EDI,dword ptr [ESI + 0x448]
    //         0046735d     CMP        EDI,EBX
    //         0046735f     JZ         LAB_00467377
    //                              Panel_ez.cpp:322 (16)
    //         00467361     MOV        this,EDI
    //         00467363     CALL       TShape::~TShape                                  void ~TShape(TShape * this)
    //         00467368     PUSH       EDI
    //         00467369     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         0046736e     ADD        ESP,0x4
    //                              Panel_ez.cpp:323 (6)
    //         00467371     MOV        dword ptr [ESI + 0x448],EBX
    //                               LAB_00467377                                                 XREF[1]:     0046735f(j)  
    //                              Panel_ez.cpp:325 (4)
    //         00467377     POP        EDI
    //         00467378     POP        ESI
    //         00467379     POP        EBX
    //         0046737a     RET
}

// Offset: 0x00467380
void setup_shadow_area(TEasy_Panel* this_, int param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TEasy_Panel::setup_shadow_area(int)                                           *
    //                              *********************************************************************************************************
    //                              void __thiscall setup_shadow_area(TEasy_Panel * this, int param_1)
    //              void              <VOID>         <RETURN>
    //              TEasy_Panel *     ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     004673ab(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     00467416(W), 00467435(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     0046753d(R)  
    //              char[256]         Stack[-0x110   area_name                 XREF[2,2]:   0046745a(*), 00467475(R), 004673e4(*), 00467423(*)  
    //              long              Stack[-0x114   x_max                     XREF[2]:     0046746a(*), 00467479(R)  
    //              long              Stack[-0x118   x_min                     XREF[2]:     00467454(*), 0046747d(R)  
    //              long              Stack[-0x11c   y_max                     XREF[3]:     00467410(W), 0046745f(*), 00467481(R)  
    //              long              Stack[-0x120   y_min
    //                               ?setup_shadow_area@TEasy_Panel@@QAEXH@Z                      XREF[14]:    draw:00467589(c), 
    //                               TEasy_Panel::setup_shadow_area                                            TRIBE_Campaign_Editor_Screen:0048f
    //                                                                                                         TRIBE_Screen_Campaign_Selection:00
    //                                                                                                         TribeJoinScreen:0049171a(c), 
    //                                                                                                         TribeLoadSavedGameScreen:0049de3a(
    //                                                                                                         TribeMPStartupScreen:0049f407(c), 
    //                                                                                                         TribeMPSetupScreen:004a018f(c), 
    //                                                                                                         TRIBE_Screen_Name:004a645c(c), 
    //                                                                                                         TribeSaveGameScreen:004a7325(c), 
    //                                                                                                         TRIBE_Screen_Sed:004a83ad(c), 
    //                                                                                                         TRIBE_Screen_Sed_Open:004b34c0(c), 
    //                                                                                                         TribeSelectScenarioScreen:004b3d40
    //                                                                                                         TribeGameSettingsScreen:004b4945(c
    //                                                                                                         TRIBE_Mission_Screen:004b81ea(c)  
    //                              Panel_ez.cpp:331 (33)
    //         00467380     MOV        EAX,FS:[0x0]
    //         00467386     PUSH       -0x1
    //         00467388     PUSH       FUN_0055de9e
    //         0046738d     PUSH       EAX
    //         0046738e     MOV        dword ptr FS:[0x0],ESP
    //         00467395     SUB        ESP,0x110
    //         0046739b     PUSH       EBX
    //         0046739c     PUSH       EBP
    //         0046739d     PUSH       ESI
    //         0046739e     MOV        ESI,this
    //         004673a0     PUSH       EDI
    //                              Panel_ez.cpp:332 (25)
    //         004673a1     MOV        this,dword ptr [ESI + 0x46c]
    //         004673a7     TEST       this,this
    //         004673a9     JZ         LAB_004673ba
    //         004673ab     MOV        EAX,dword ptr [ESP + param_1]
    //         004673b2     TEST       EAX,EAX
    //         004673b4     JZ         LAB_0046753d
    //                               LAB_004673ba                                                 XREF[1]:     004673a9(j)  
    //                              Panel_ez.cpp:336 (28)
    //         004673ba     MOV        EAX,dword ptr [ESI + 0x204]
    //         004673c0     TEST       EAX,EAX
    //         004673c2     JZ         LAB_0046753d
    //         004673c8     MOV        EAX,dword ptr [ESI + 0x44c]
    //         004673ce     TEST       EAX,EAX
    //         004673d0     JZ         LAB_0046753d
    //                              Panel_ez.cpp:338 (3)
    //         004673d6     MOV        EAX,dword ptr [ESI + 0x20]
    //                              Panel_ez.cpp:339 (9)
    //         004673d9     TEST       this,this
    //         004673db     MOV        EDX,dword ptr [EAX]
    //         004673dd     MOV        EBP,dword ptr [EDX + 0x28]
    //         004673e0     JNZ        LAB_00467446
    //                              Panel_ez.cpp:341 (2)
    //         004673e2     MOV        EAX,EDX
    //                              Panel_ez.cpp:343 (31)
    //         004673e4     LEA        this=>area_name[4],[ESP + 0x20]
    //         004673e8     MOV        EDI,dword ptr [EAX + 0x28]
    //         004673eb     AND        EDI,0x1
    //         004673ee     MOV        dword ptr [EAX + 0x28],EDI
    //         004673f1     MOV        EAX,dword ptr [ESI + 0x1c]
    //         004673f4     PUSH       EAX
    //         004673f5     PUSH       s_%s_Shadow_Panel                                = "%s Shadow Panel"
    //         004673fa     PUSH       this
    //         004673fb     CALL       sprintf                                          undefined sprintf()
    //         00467400     ADD        ESP,0xc
    //                              Panel_ez.cpp:344 (67)
    //         00467403     PUSH       0x100
    //         00467408     CALL       operator_new                                     void * operator_new(uint param_1)
    //         0046740d     ADD        ESP,0x4
    //         00467410     MOV        dword ptr [ESP + y_max],EAX
    //         00467414     TEST       EAX,EAX
    //         00467416     MOV        dword ptr [ESP + local_4],0x0
    //         00467421     JZ         LAB_00467433
    //         00467423     LEA        EDX=>area_name[4],[ESP + 0x20]
    //         00467427     PUSH       0x0
    //         00467429     PUSH       EDX
    //         0046742a     MOV        this,EAX
    //         0046742c     CALL       TDrawArea::TDrawArea                             undefined TDrawArea(TDrawArea * this, char * 
    //         00467431     JMP        LAB_00467435
    //                               LAB_00467433                                                 XREF[1]:     00467421(j)  
    //         00467433     XOR        EAX,EAX
    //                               LAB_00467435                                                 XREF[1]:     00467431(j)  
    //         00467435     MOV        dword ptr [ESP + local_4],0xffffffff
    //         00467440     MOV        dword ptr [ESI + 0x46c],EAX
    //                               LAB_00467446                                                 XREF[1]:     004673e0(j)  
    //                              Panel_ez.cpp:346 (14)
    //         00467446     MOV        EAX,dword ptr [ESI + 0x46c]
    //         0046744c     TEST       EAX,EAX
    //         0046744e     JZ         LAB_00467535
    //                              Panel_ez.cpp:349 (33)
    //         00467454     LEA        EAX=>x_min,[ESP + 0x14]
    //         00467458     PUSH       0x0
    //         0046745a     LEA        this=>area_name,[ESP + 0x20]
    //         0046745e     PUSH       EAX
    //         0046745f     LEA        EDX=>y_max,[ESP + 0x18]
    //         00467463     PUSH       this
    //         00467464     MOV        this,dword ptr [ESI + 0x204]
    //         0046746a     LEA        EAX=>x_max,[ESP + 0x24]
    //         0046746e     PUSH       EDX
    //         0046746f     PUSH       EAX
    //         00467470     CALL       TShape::shape_minmax                             uchar shape_minmax(TShape * this, long * para
    //                              Panel_ez.cpp:350 (8)
    //         00467475     MOV        EDI,dword ptr [ESP + area_name[0]]
    //         00467479     MOV        EDX,dword ptr [ESP + x_max]
    //                              Panel_ez.cpp:351 (12)
    //         0046747d     MOV        EBX,dword ptr [ESP + x_min]
    //         00467481     MOV        EAX,dword ptr [ESP + y_max]
    //         00467485     SUB        EDI,EDX
    //         00467487     SUB        EBX,EAX
    //                              Panel_ez.cpp:352 (9)
    //         00467489     MOV        EAX,dword ptr [ESI + 0x14]
    //         0046748c     INC        EDI
    //         0046748d     INC        EBX
    //         0046748e     CMP        EDI,EAX
    //         00467490     JLE        LAB_00467494
    //                              Panel_ez.cpp:353 (2)
    //         00467492     MOV        EDI,EAX
    //                               LAB_00467494                                                 XREF[1]:     00467490(j)  
    //                              Panel_ez.cpp:354 (7)
    //         00467494     MOV        EAX,dword ptr [ESI + 0x18]
    //         00467497     CMP        EBX,EAX
    //         00467499     JLE        LAB_0046749d
    //                              Panel_ez.cpp:355 (2)
    //         0046749b     MOV        EBX,EAX
    //                               LAB_0046749d                                                 XREF[1]:     00467499(j)  
    //                              Panel_ez.cpp:356 (27)
    //         0046749d     MOV        this,dword ptr [ESI + 0x20]
    //         004674a0     PUSH       0x0
    //         004674a2     PUSH       0x0
    //         004674a4     PUSH       EBX
    //         004674a5     MOV        EDX,dword ptr [this->_padding_]
    //         004674a7     MOV        this,dword ptr [ESI + 0x46c]
    //         004674ad     PUSH       EDI
    //         004674ae     PUSH       EDX
    //         004674af     CALL       TDrawArea::Init                                  int Init(TDrawArea * this, TDrawSystem * para
    //         004674b4     TEST       EAX,EAX
    //         004674b6     JZ         LAB_00467535
    //                              Panel_ez.cpp:358 (22)
    //         004674b8     MOV        this,dword ptr [ESI + 0x46c]
    //         004674be     XOR        EAX,EAX
    //         004674c0     MOV        AL,byte ptr [ESI + 0x454]
    //         004674c6     PUSH       EAX
    //         004674c7     PUSH       0x0
    //         004674c9     CALL       TDrawArea::Clear                                 void Clear(TDrawArea * this, tagRECT * param_
    //                              Panel_ez.cpp:359 (22)
    //         004674ce     MOV        this,dword ptr [ESI + 0x46c]
    //         004674d4     PUSH       0x1
    //         004674d6     PUSH       s_panel_ez::setup_shadow_area                    = "panel_ez::setup_shadow_area"
    //         004674db     CALL       TDrawArea::Lock                                  uchar * Lock(TDrawArea * this, char * param_1
    //         004674e0     TEST       EAX,EAX
    //         004674e2     JZ         LAB_00467535
    //                              Panel_ez.cpp:361 (28)
    //         004674e4     MOV        this,dword ptr [ESI + 0x46c]
    //         004674ea     PUSH       0x0
    //         004674ec     PUSH       0x0
    //         004674ee     PUSH       0x0
    //         004674f0     PUSH       0x0
    //         004674f2     PUSH       0x0
    //         004674f4     PUSH       this
    //         004674f5     MOV        this,dword ptr [ESI + 0x204]
    //         004674fb     CALL       TShape::shape_draw                               uchar shape_draw(TShape * this, TDrawArea * p
    //                              Panel_ez.cpp:362 (18)
    //         00467500     MOV        EDX,dword ptr [ESI + 0x44c]
    //         00467506     MOV        this,dword ptr [ESI + 0x46c]
    //         0046750c     PUSH       EDX
    //         0046750d     CALL       TDrawArea::SetShadowTable                        void SetShadowTable(TDrawArea * this, RGE_Col
    //                              Panel_ez.cpp:363 (19)
    //         00467512     MOV        this,dword ptr [ESI + 0x46c]
    //         00467518     DEC        EBX
    //         00467519     DEC        EDI
    //         0046751a     PUSH       EBX
    //         0046751b     PUSH       EDI
    //         0046751c     PUSH       0x0
    //         0046751e     PUSH       0x0
    //         00467520     CALL       TDrawArea::DrawShadowBox                         void DrawShadowBox(TDrawArea * this, long par
    //                              Panel_ez.cpp:364 (16)
    //         00467525     MOV        this,dword ptr [ESI + 0x46c]
    //         0046752b     PUSH       s_panel_ez::setup_shadow_area                    = "panel_ez::setup_shadow_area"
    //         00467530     CALL       TDrawArea::Unlock                                void Unlock(TDrawArea * this, char * param_1)
    //                               LAB_00467535                                                 XREF[3]:     0046744e(j), 004674b6(j), 
    //                                                                                                         004674e2(j)  
    //                              Panel_ez.cpp:368 (8)
    //         00467535     MOV        EAX,dword ptr [ESI + 0x20]
    //         00467538     MOV        this,dword ptr [EAX]
    //         0046753a     MOV        dword ptr [ECX + this->_padding_],EBP
    //                               LAB_0046753d                                                 XREF[3]:     004673b4(j), 004673c2(j), 
    //                                                                                                         004673d0(j)  
    //                              Panel_ez.cpp:370 (27)
    //         0046753d     MOV        this,dword ptr [ESP + local_c]
    //         00467544     POP        EDI
    //         00467545     POP        ESI
    //         00467546     POP        EBP
    //         00467547     MOV        dword ptr FS:[0x0],this
    //         0046754e     POP        EBX
    //         0046754f     ADD        ESP,0x11c
    //         00467555     RET        0x4
}

// Offset: 0x00467560
void TRIBE_Screen_Sed_Open::draw_setup(int param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void __thiscall TEasy_Panel::draw_setup(int)                                          *
    //                              *********************************************************************************************************
    //                              void __thiscall draw_setup(TEasy_Panel * this, int param_1)
    //              void              <VOID>         <RETURN>
    //              TEasy_Panel *     ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     00467560(R)  
    //                               ?draw_setup@TEasy_Panel@@UAEXH@Z                             XREF[44]:    0056f638(*), 0056f778(*), 
    //                               TEasy_Panel::draw_setup                                                   0056f8c0(*), 0056f9f0(*), 
    //                                                                                                         0056fb20(*), 0056fc58(*), 
    //                                                                                                         0056fd88(*), 0056feb8(*), 
    //                                                                                                         0056ffe8(*), 00570118(*), 
    //                                                                                                         00570d40(*), 005710d8(*), 
    //                                                                                                         00571938(*), 00571d18(*), 
    //                                                                                                         005721a8(*), 005722d0(*), 
    //                                                                                                         005723f8(*), 00572520(*), 
    //                                                                                                         00572648(*), 00572778(*), [more]
    //                              Panel_ez.cpp:376 (10)
    //         00467560     MOV        EAX,dword ptr [ESP + param_1]
    //         00467564     PUSH       EAX
    //         00467565     CALL       TPanel::draw_setup                               void draw_setup(TPanel * this, int param_1)
    //                              Panel_ez.cpp:378 (3)
    //         0046756a     RET        0x4
}

// Offset: 0x00467570
void RGE_Dialog_List::draw() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void __thiscall TEasy_Panel::draw(void)                                               *
    //                              *********************************************************************************************************
    //                              void __thiscall draw(TEasy_Panel * this)
    //              void              <VOID>         <RETURN>
    //              TEasy_Panel *     ECX:4 (auto)   this
    //                               ?draw@TEasy_Panel@@UAEXXZ                                    XREF[18]:    draw:0043b550(j), 
    //                               TEasy_Panel::draw                                                         draw:0043e777(c), 
    //                                                                                                         draw:00441466(c), 
    //                                                                                                         draw:0047bb40(j), 
    //                                                                                                         draw:004ad0f6(c), 0056f780(*), 
    //                                                                                                         0056f9f8(*), 0056fb28(*), 
    //                                                                                                         0056fc60(*), 0056fd90(*), 
    //                                                                                                         0056fec0(*), 00570120(*), 
    //                                                                                                         00570d48(*), 005710e0(*), 
    //                                                                                                         00571d20(*), 00572650(*), 
    //                                                                                                         00573798(*), 005765b0(*)  
    //                              Panel_ez.cpp:384 (3)
    //         00467570     PUSH       ESI
    //         00467571     MOV        ESI,this
    //                              Panel_ez.cpp:385 (10)
    //         00467573     MOV        AL,byte ptr [ESI + 0xf3]
    //         00467579     TEST       AL,AL
    //         0046757b     JZ         LAB_00467595
    //                              Panel_ez.cpp:387 (10)
    //         0046757d     MOV        EAX,dword ptr [ESI + 0x46c]
    //         00467583     TEST       EAX,EAX
    //         00467585     JZ         LAB_0046758e
    //                              Panel_ez.cpp:388 (7)
    //         00467587     PUSH       0x1
    //         00467589     CALL       TEasy_Panel::setup_shadow_area                   void setup_shadow_area(TEasy_Panel * this, in
    //                               LAB_0046758e                                                 XREF[1]:     00467585(j)  
    //                              Panel_ez.cpp:389 (7)
    //         0046758e     MOV        byte ptr [ESI + 0xf3],0x0
    //                               LAB_00467595                                                 XREF[1]:     0046757b(j)  
    //                              Panel_ez.cpp:392 (10)
    //         00467595     MOV        AL,byte ptr [ESI + 0xf2]
    //         0046759b     TEST       AL,AL
    //         0046759d     JZ         LAB_004675ad
    //                              Panel_ez.cpp:393 (12)
    //         0046759f     MOV        EAX,dword ptr [ESI]
    //         004675a1     PUSH       0x1
    //         004675a3     MOV        this,ESI
    //         004675a5     CALL       dword ptr [EAX + 0xe0]
    //                              Panel_ez.cpp:396 (2)
    //         004675ab     POP        ESI
    //         004675ac     RET
    //                               LAB_004675ad                                                 XREF[1]:     0046759d(j)  
    //                              Panel_ez.cpp:395 (12)
    //         004675ad     MOV        EDX,dword ptr [ESI]
    //         004675af     PUSH       0x0
    //         004675b1     MOV        this,ESI
    //         004675b3     CALL       dword ptr [EDX + 0xe0]
    //                              Panel_ez.cpp:396 (2)
    //         004675b9     POP        ESI
    //         004675ba     RET
}

// Offset: 0x004675C0
void TRIBE_Screen_Sed_Open::draw_background(int param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void __thiscall TEasy_Panel::draw_background(int)                                     *
    //                              *********************************************************************************************************
    //                              void __thiscall draw_background(TEasy_Panel * this, int param_1)
    //              void              <VOID>         <RETURN>
    //              TEasy_Panel *     ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     004675cd(W)  
    //              long              Stack[-0xc]:4  y_min
    //              long              Stack[-0x10]:4 y_max
    //              long              Stack[-0x14]:4 x_min
    //              long              Stack[-0x18]:4 x_max
    //              long              Stack[-0x1c]:4 pic_hgt
    //              TShape *          Stack[-0x20]:4 pic
    //                               ?draw_background@TEasy_Panel@@UAEXH@Z                        XREF[44]:    0056f6f0(*), 0056f830(*), 
    //                               TEasy_Panel::draw_background                                              0056f978(*), 0056faa8(*), 
    //                                                                                                         0056fbd8(*), 0056fd10(*), 
    //                                                                                                         0056fe40(*), 0056ff70(*), 
    //                                                                                                         005700a0(*), 005701d0(*), 
    //                                                                                                         00570df8(*), 00571190(*), 
    //                                                                                                         005719f0(*), 00571dd0(*), 
    //                                                                                                         00572260(*), 00572388(*), 
    //                                                                                                         005724b0(*), 005725d8(*), 
    //                                                                                                         00572700(*), 00572830(*), [more]
    //                              Panel_ez.cpp:402 (9)
    //         004675c0     SUB        ESP,0x1c
    //         004675c3     PUSH       EBX
    //         004675c4     PUSH       EBP
    //         004675c5     PUSH       ESI
    //         004675c6     MOV        ESI,this
    //         004675c8     PUSH       EDI
    //                              Panel_ez.cpp:408 (11)
    //         004675c9     PUSH       0x0
    //         004675cb     MOV        EAX,dword ptr [ESI]
    //         004675cd     MOV        dword ptr [ESP + local_4],EAX
    //         004675d1     CALL       dword ptr [EAX + 0x28]
    //                              Panel_ez.cpp:410 (26)
    //         004675d4     MOV        EAX,dword ptr [ESP + 0x30]
    //         004675d8     TEST       EAX,EAX
    //         004675da     JZ         LAB_004676fe
    //         004675e0     MOV        this,dword ptr [ESI + 0x46c]
    //         004675e6     TEST       this,this
    //         004675e8     JZ         LAB_004676ea
    //                              Panel_ez.cpp:412 (6)
    //         004675ee     CMP        dword ptr [ESI + 0x38],0x2
    //         004675f2     JNZ        LAB_00467609
    //                              Panel_ez.cpp:413 (21)
    //         004675f4     XOR        EAX,EAX
    //         004675f6     LEA        this,[ESI + 0x24]
    //         004675f9     MOV        AL,byte ptr [ESI + 0x455]
    //         004675ff     PUSH       EAX
    //         00467600     PUSH       this=>DAT_fffffff8
    //         00467601     MOV        this,dword ptr [ESI + 0x20]
    //         00467604     CALL       TDrawArea::Clear                                 void Clear(TDrawArea * this, tagRECT * param_
    //                               LAB_00467609                                                 XREF[1]:     004675f2(j)  
    //                              Panel_ez.cpp:415 (6)
    //         00467609     MOV        this,dword ptr [ESI + 0x46c]
    //                              Panel_ez.cpp:418 (35)
    //         0046760f     MOV        EAX,dword ptr [ESI + 0x318]
    //         00467615     SUB        EAX,0x0
    //         00467618     MOV        EDI,dword ptr [ECX + this->_padding_]
    //         0046761b     MOV        EBP,dword ptr [ECX + this->_padding_]
    //         0046761e     MOV        dword ptr [ESP + 0x14],EDI
    //         00467622     JZ         LAB_004676d0
    //         00467628     DEC        EAX
    //         00467629     JZ         LAB_00467686
    //         0046762b     DEC        EAX
    //         0046762c     JNZ        LAB_0046790c
    //                              Panel_ez.cpp:432 (13)
    //         00467632     MOV        EAX,dword ptr [ESI + 0x18]
    //         00467635     XOR        EBX,EBX
    //         00467637     TEST       EAX,EAX
    //         00467639     JL         LAB_0046790c
    //                               LAB_0046763f                                                 XREF[1]:     0046767f(j)  
    //                              Panel_ez.cpp:435 (9)
    //         0046763f     MOV        EAX,dword ptr [ESI + 0x14]
    //         00467642     XOR        EDI,EDI
    //         00467644     TEST       EAX,EAX
    //         00467646     JL         LAB_00467674
    //                               LAB_00467648                                                 XREF[1]:     00467672(j)  
    //                              Panel_ez.cpp:437 (38)
    //         00467648     MOV        this,dword ptr [ESI + 0x10]
    //         0046764b     MOV        EDX,EBX
    //         0046764d     PUSH       0x0
    //         0046764f     ADD        EDX,this
    //         00467651     MOV        this,dword ptr [ESI + 0x20]
    //         00467654     PUSH       0x0=>DAT_fffffff8
    //         00467656     PUSH       EDX=>DAT_fffffff4
    //         00467657     MOV        EDX,dword ptr [ESI + 0xc]
    //         0046765a     MOV        EAX,EDI
    //         0046765c     ADD        EAX,EDX
    //         0046765e     PUSH       EAX=>DAT_fffffff0
    //         0046765f     PUSH       this
    //         00467660     MOV        this,dword ptr [ESI + 0x46c]
    //         00467666     CALL       TDrawArea::Copy                                  void Copy(TDrawArea * this, TDrawArea * param
    //         0046766b     MOV        EAX,dword ptr [ESI + 0x14]
    //                              Panel_ez.cpp:438 (6)
    //         0046766e     ADD        EDI,EBP
    //         00467670     CMP        EDI,EAX
    //         00467672     JLE        LAB_00467648
    //                               LAB_00467674                                                 XREF[1]:     00467646(j)  
    //                              Panel_ez.cpp:440 (13)
    //         00467674     MOV        this,dword ptr [ESP + 0x14]
    //         00467678     MOV        EAX,dword ptr [ESI + 0x18]
    //         0046767b     ADD        EBX,this
    //         0046767d     CMP        EBX,EAX
    //         0046767f     JLE        LAB_0046763f
    //                              Panel_ez.cpp:442 (5)
    //         00467681     JMP        LAB_0046790c
    //                               LAB_00467686                                                 XREF[1]:     00467629(j)  
    //                              Panel_ez.cpp:426 (3)
    //         00467686     MOV        EAX,dword ptr [ESI + 0x18]
    //                              Panel_ez.cpp:427 (66)
    //         00467689     MOV        BX,word ptr [ESI + 0x10]
    //         0046768d     CDQ
    //         0046768e     SUB        EAX,EDX
    //         00467690     PUSH       0x0
    //         00467692     SAR        EAX,0x1
    //         00467694     ADD        BX,AX
    //         00467697     MOV        EAX,EDI
    //         00467699     CDQ
    //         0046769a     SUB        EAX,EDX
    //         0046769c     MOV        DI,word ptr [ESI + 0xc]
    //         004676a0     SAR        EAX,0x1
    //         004676a2     SUB        EBX,EAX
    //         004676a4     MOV        EAX,dword ptr [ESI + 0x14]
    //         004676a7     MOVSX      EDX,BX
    //         004676aa     PUSH       0x0=>DAT_fffffff8
    //         004676ac     PUSH       EDX=>DAT_fffffff4
    //         004676ad     CDQ
    //         004676ae     SUB        EAX,EDX
    //         004676b0     SAR        EAX,0x1
    //         004676b2     ADD        DI,AX
    //         004676b5     MOV        EAX,EBP
    //         004676b7     CDQ
    //         004676b8     SUB        EAX,EDX
    //         004676ba     MOV        EDX,dword ptr [ESI + 0x20]
    //         004676bd     SAR        EAX,0x1
    //         004676bf     SUB        EDI,EAX
    //         004676c1     MOVSX      EAX,DI
    //         004676c4     PUSH       EAX=>DAT_fffffff0
    //         004676c5     PUSH       EDX
    //         004676c6     CALL       TDrawArea::Copy                                  void Copy(TDrawArea * this, TDrawArea * param
    //                              Panel_ez.cpp:428 (5)
    //         004676cb     JMP        LAB_0046790c
    //                               LAB_004676d0                                                 XREF[1]:     00467622(j)  
    //                              Panel_ez.cpp:421 (21)
    //         004676d0     MOV        EAX,dword ptr [ESI + 0x10]
    //         004676d3     MOV        EDX,dword ptr [ESI + 0xc]
    //         004676d6     PUSH       0x0
    //         004676d8     PUSH       0x0=>DAT_fffffff8
    //         004676da     PUSH       EAX=>DAT_fffffff4
    //         004676db     MOV        EAX,dword ptr [ESI + 0x20]
    //         004676de     PUSH       EDX=>DAT_fffffff0
    //         004676df     PUSH       EAX
    //         004676e0     CALL       TDrawArea::Copy                                  void Copy(TDrawArea * this, TDrawArea * param
    //                              Panel_ez.cpp:445 (5)
    //         004676e5     JMP        LAB_0046790c
    //                               LAB_004676ea                                                 XREF[1]:     004675e8(j)  
    //                              Panel_ez.cpp:447 (14)
    //         004676ea     TEST       EAX,EAX
    //         004676ec     JZ         LAB_004676fe
    //         004676ee     MOV        EDI,dword ptr [ESI + 0x208]
    //         004676f4     TEST       EDI,EDI
    //         004676f6     JZ         LAB_004676fe
    //                              Panel_ez.cpp:448 (4)
    //         004676f8     MOV        dword ptr [ESP + 0x10],EDI
    //                              Panel_ez.cpp:449 (2)
    //         004676fc     JMP        LAB_0046770a
    //                               LAB_004676fe                                                 XREF[3]:     004675da(j), 004676ec(j), 
    //                                                                                                         004676f6(j)  
    //                              Panel_ez.cpp:450 (12)
    //         004676fe     MOV        this,dword ptr [ESI + 0x204]
    //         00467704     MOV        dword ptr [ESP + 0x10],this
    //         00467708     MOV        EDI,this
    //                               LAB_0046770a                                                 XREF[1]:     004676fc(j)  
    //                              Panel_ez.cpp:452 (10)
    //         0046770a     CMP        dword ptr [ESI + 0x38],0x2
    //         0046770e     JZ         LAB_00467714
    //         00467710     TEST       EDI,EDI
    //         00467712     JNZ        LAB_00467744
    //                               LAB_00467714                                                 XREF[1]:     0046770e(j)  
    //                              Panel_ez.cpp:454 (4)
    //         00467714     TEST       EAX,EAX
    //         00467716     JZ         LAB_00467727
    //                              Panel_ez.cpp:455 (13)
    //         00467718     XOR        EDX,EDX
    //         0046771a     LEA        EAX,[ESI + 0x24]
    //         0046771d     MOV        DL,byte ptr [ESI + 0x455]
    //         00467723     PUSH       EDX
    //         00467724     PUSH       EAX=>DAT_fffffff8
    //                              Panel_ez.cpp:456 (2)
    //         00467725     JMP        LAB_00467734
    //                               LAB_00467727                                                 XREF[1]:     00467716(j)  
    //                              Panel_ez.cpp:457 (21)
    //         00467727     XOR        this,this
    //         00467729     LEA        EDX,[ESI + 0x24]
    //         0046772c     MOV        this,byte ptr [ESI + 0x454]
    //         00467732     PUSH       this
    //         00467733     PUSH       EDX=>DAT_fffffff8
    //                               LAB_00467734                                                 XREF[1]:     00467725(j)  
    //         00467734     MOV        this,dword ptr [ESI + 0x20]
    //         00467737     CALL       TDrawArea::Clear                                 void Clear(TDrawArea * this, tagRECT * param_
    //                              Panel_ez.cpp:460 (8)
    //         0046773c     TEST       EDI,EDI
    //         0046773e     JZ         LAB_0046790c
    //                               LAB_00467744                                                 XREF[1]:     00467712(j)  
    //                              Panel_ez.cpp:462 (23)
    //         00467744     MOV        this,dword ptr [ESI + 0x20]
    //         00467747     PUSH       0x1
    //         00467749     PUSH       s_panel_ez::draw_background                      = "panel_ez::draw_background"
    //         0046774e     CALL       TDrawArea::Lock                                  uchar * Lock(TDrawArea * this, char * param_1
    //         00467753     TEST       EAX,EAX
    //         00467755     JZ         LAB_0046790c
    //                              Panel_ez.cpp:464 (29)
    //         0046775b     LEA        EAX,[ESP + 0x20]
    //         0046775f     PUSH       0x0
    //         00467761     LEA        this,[ESP + 0x1c]
    //         00467765     PUSH       EAX=>DAT_fffffff8
    //         00467766     LEA        EDX,[ESP + 0x2c]
    //         0046776a     PUSH       this=>DAT_fffffff4
    //         0046776b     LEA        EAX,[ESP + 0x28]
    //         0046776f     PUSH       EDX=>DAT_fffffff0
    //         00467770     PUSH       EAX
    //         00467771     MOV        this,EDI
    //         00467773     CALL       TShape::shape_minmax                             uchar shape_minmax(TShape * this, long * para
    //                              Panel_ez.cpp:465 (8)
    //         00467778     MOV        EBX,dword ptr [ESP + 0x18]
    //         0046777c     MOV        EDX,dword ptr [ESP + 0x1c]
    //                              Panel_ez.cpp:466 (12)
    //         00467780     MOV        EBP,dword ptr [ESP + 0x20]
    //         00467784     MOV        EAX,dword ptr [ESP + 0x24]
    //         00467788     SUB        EBX,EDX
    //         0046778a     SUB        EBP,EAX
    //                              Panel_ez.cpp:468 (22)
    //         0046778c     MOV        EAX,dword ptr [ESI + 0x318]
    //         00467792     INC        EBX
    //         00467793     INC        EBP
    //         00467794     DEC        EAX
    //         00467795     MOV        dword ptr [ESP + 0x14],EBP
    //         00467799     JZ         LAB_0046787d
    //         0046779f     DEC        EAX
    //         004677a0     JZ         LAB_004677f5
    //                              Panel_ez.cpp:472 (25)
    //         004677a2     MOV        this,dword ptr [ESI + 0x10]
    //         004677a5     MOV        EDX,dword ptr [ESI + 0xc]
    //         004677a8     MOV        EAX,dword ptr [ESI + 0x20]
    //         004677ab     PUSH       0x0
    //         004677ad     PUSH       0x0=>DAT_fffffff8
    //         004677af     PUSH       0x0=>DAT_fffffff4
    //         004677b1     PUSH       this=>DAT_fffffff0
    //         004677b2     PUSH       EDX
    //         004677b3     PUSH       EAX
    //         004677b4     MOV        this,EDI
    //         004677b6     CALL       TShape::shape_draw                               uchar shape_draw(TShape * this, TDrawArea * p
    //                              Panel_ez.cpp:473 (26)
    //         004677bb     MOV        EAX,dword ptr [ESP + 0x30]
    //         004677bf     TEST       EAX,EAX
    //         004677c1     JZ         LAB_004678ff
    //         004677c7     MOV        EAX,dword ptr [ESI + 0x44c]
    //         004677cd     TEST       EAX,EAX
    //         004677cf     JZ         LAB_004678ff
    //                              Panel_ez.cpp:475 (9)
    //         004677d5     MOV        this,dword ptr [ESI + 0x20]
    //         004677d8     PUSH       EAX
    //         004677d9     CALL       TDrawArea::SetShadowTable                        void SetShadowTable(TDrawArea * this, RGE_Col
    //                              Panel_ez.cpp:476 (18)
    //         004677de     MOV        EAX,dword ptr [ESI + 0x10]
    //         004677e1     MOV        this,dword ptr [ESI + 0xc]
    //         004677e4     LEA        EDX,[EBP + EAX*0x1 + -0x1]
    //         004677e8     PUSH       EDX
    //         004677e9     LEA        EDX,[EBX + this->_padding_*0x1 + -0x1]
    //         004677ed     PUSH       EDX=>DAT_fffffff8
    //         004677ee     PUSH       EAX=>DAT_fffffff4
    //         004677ef     PUSH       this=>DAT_fffffff0
    //                              Panel_ez.cpp:478 (5)
    //         004677f0     JMP        LAB_004678f7
    //                               LAB_004677f5                                                 XREF[1]:     004677a0(j)  
    //                              Panel_ez.cpp:493 (9)
    //         004677f5     MOV        EAX,dword ptr [ESI + 0x18]
    //         004677f8     XOR        EBP,EBP
    //         004677fa     TEST       EAX,EAX
    //         004677fc     JL         LAB_00467840
    //                               LAB_004677fe                                                 XREF[1]:     0046783e(j)  
    //                              Panel_ez.cpp:496 (9)
    //         004677fe     MOV        EAX,dword ptr [ESI + 0x14]
    //         00467801     XOR        EDI,EDI
    //         00467803     TEST       EAX,EAX
    //         00467805     JL         LAB_00467833
    //                               LAB_00467807                                                 XREF[1]:     00467831(j)  
    //                              Panel_ez.cpp:498 (38)
    //         00467807     MOV        EDX,dword ptr [ESI + 0x10]
    //         0046780a     MOV        EAX,EBP
    //         0046780c     PUSH       0x0
    //         0046780e     PUSH       0x0=>DAT_fffffff8
    //         00467810     ADD        EAX,EDX
    //         00467812     MOV        EDX,dword ptr [ESI + 0x20]
    //         00467815     PUSH       0x0=>DAT_fffffff4
    //         00467817     PUSH       EAX=>DAT_fffffff0
    //         00467818     MOV        EAX,dword ptr [ESI + 0xc]
    //         0046781b     MOV        this,EDI
    //         0046781d     ADD        this,EAX
    //         0046781f     PUSH       this
    //         00467820     MOV        this,dword ptr [ESP + 0x24]
    //         00467824     PUSH       EDX
    //         00467825     CALL       TShape::shape_draw                               uchar shape_draw(TShape * this, TDrawArea * p
    //         0046782a     MOV        EAX,dword ptr [ESI + 0x14]
    //                              Panel_ez.cpp:499 (6)
    //         0046782d     ADD        EDI,EBX
    //         0046782f     CMP        EDI,EAX
    //         00467831     JLE        LAB_00467807
    //                               LAB_00467833                                                 XREF[1]:     00467805(j)  
    //                              Panel_ez.cpp:501 (13)
    //         00467833     MOV        this,dword ptr [ESP + 0x14]
    //         00467837     MOV        EAX,dword ptr [ESI + 0x18]
    //         0046783a     ADD        EBP,this
    //         0046783c     CMP        EBP,EAX
    //         0046783e     JLE        LAB_004677fe
    //                               LAB_00467840                                                 XREF[1]:     004677fc(j)  
    //                              Panel_ez.cpp:503 (26)
    //         00467840     MOV        EAX,dword ptr [ESP + 0x30]
    //         00467844     TEST       EAX,EAX
    //         00467846     JZ         LAB_004678ff
    //         0046784c     MOV        EAX,dword ptr [ESI + 0x44c]
    //         00467852     TEST       EAX,EAX
    //         00467854     JZ         LAB_004678ff
    //                              Panel_ez.cpp:505 (9)
    //         0046785a     MOV        this,dword ptr [ESI + 0x20]
    //         0046785d     PUSH       EAX
    //         0046785e     CALL       TDrawArea::SetShadowTable                        void SetShadowTable(TDrawArea * this, RGE_Col
    //                              Panel_ez.cpp:506 (24)
    //         00467863     MOV        EAX,dword ptr [ESI + 0x10]
    //         00467866     MOV        EDX,dword ptr [ESI + 0x18]
    //         00467869     MOV        this,dword ptr [ESI + 0xc]
    //         0046786c     LEA        EDX,[EAX + EDX*0x1 + -0x1]
    //         00467870     PUSH       EDX
    //         00467871     MOV        EDX,dword ptr [ESI + 0x14]
    //         00467874     LEA        EDX,[EDX + this->_padding_*0x1 + -0x1]
    //         00467878     PUSH       EDX=>DAT_fffffff8
    //         00467879     PUSH       EAX=>DAT_fffffff4
    //         0046787a     PUSH       this=>DAT_fffffff0
    //                              Panel_ez.cpp:508 (2)
    //         0046787b     JMP        LAB_004678f7
    //                               LAB_0046787d                                                 XREF[1]:     00467799(j)  
    //                              Panel_ez.cpp:481 (10)
    //         0046787d     MOV        EAX,dword ptr [ESI + 0x14]
    //         00467880     MOV        this,word ptr [ESI + 0xc]
    //         00467884     CDQ
    //         00467885     SUB        EAX,EDX
    //                              Panel_ez.cpp:483 (69)
    //         00467887     PUSH       0x0
    //         00467889     SAR        EAX,0x1
    //         0046788b     ADD        this,AX
    //         0046788e     MOV        EAX,EBX
    //         00467890     CDQ
    //         00467891     SUB        EAX,EDX
    //         00467893     PUSH       0x0=>DAT_fffffff8
    //         00467895     SAR        EAX,0x1
    //         00467897     SUB        this,EAX
    //         00467899     MOV        EAX,dword ptr [ESI + 0x18]
    //         0046789c     CDQ
    //         0046789d     SUB        EAX,EDX
    //         0046789f     PUSH       0x0=>DAT_fffffff4
    //         004678a1     MOVSX      EDI,this
    //         004678a4     MOV        this,word ptr [ESI + 0x10]
    //         004678a8     SAR        EAX,0x1
    //         004678aa     ADD        this,AX
    //         004678ad     MOV        EAX,EBP
    //         004678af     CDQ
    //         004678b0     SUB        EAX,EDX
    //         004678b2     MOV        EDX,dword ptr [ESI + 0x20]
    //         004678b5     SAR        EAX,0x1
    //         004678b7     SUB        this,EAX
    //         004678b9     MOVSX      EAX,this
    //         004678bc     MOV        this,dword ptr [ESP + 0x1c]
    //         004678c0     PUSH       EAX=>DAT_fffffff0
    //         004678c1     PUSH       EDI
    //         004678c2     PUSH       EDX
    //         004678c3     MOV        dword ptr [ESP + 0x2c],EAX
    //         004678c7     CALL       TShape::shape_draw                               uchar shape_draw(TShape * this, TDrawArea * p
    //                              Panel_ez.cpp:484 (18)
    //         004678cc     MOV        EAX,dword ptr [ESP + 0x30]
    //         004678d0     TEST       EAX,EAX
    //         004678d2     JZ         LAB_004678ff
    //         004678d4     MOV        EAX,dword ptr [ESI + 0x44c]
    //         004678da     TEST       EAX,EAX
    //         004678dc     JZ         LAB_004678ff
    //                              Panel_ez.cpp:486 (9)
    //         004678de     MOV        this,dword ptr [ESI + 0x20]
    //         004678e1     PUSH       EAX
    //         004678e2     CALL       TDrawArea::SetShadowTable                        void SetShadowTable(TDrawArea * this, RGE_Col
    //                              Panel_ez.cpp:487 (24)
    //         004678e7     MOV        EAX,dword ptr [ESP + 0x14]
    //         004678eb     LEA        EDX,[EDI + EBX*0x1 + -0x1]
    //         004678ef     LEA        this,[EAX + EBP*0x1 + -0x1]
    //         004678f3     PUSH       this
    //         004678f4     PUSH       EDX=>DAT_fffffff8
    //         004678f5     PUSH       EAX=>DAT_fffffff4
    //         004678f6     PUSH       EDI=>DAT_fffffff0
    //                               LAB_004678f7                                                 XREF[2]:     004677f0(j), 0046787b(j)  
    //         004678f7     MOV        this,dword ptr [ESI + 0x20]
    //         004678fa     CALL       TDrawArea::DrawShadowBox                         void DrawShadowBox(TDrawArea * this, long par
    //                               LAB_004678ff                                                 XREF[6]:     004677c1(j), 004677cf(j), 
    //                                                                                                         00467846(j), 00467854(j), 
    //                                                                                                         004678d2(j), 004678dc(j)  
    //                              Panel_ez.cpp:510 (13)
    //         004678ff     MOV        this,dword ptr [ESI + 0x20]
    //         00467902     PUSH       s_panel_ez::draw_background                      = "panel_ez::draw_background"
    //         00467907     CALL       TDrawArea::Unlock                                void Unlock(TDrawArea * this, char * param_1)
    //                               LAB_0046790c                                                 XREF[7]:     0046762c(j), 00467639(j), 
    //                                                                                                         00467681(j), 004676cb(j), 
    //                                                                                                         004676e5(j), 0046773e(j), 
    //                                                                                                         00467755(j)  
    //                              Panel_ez.cpp:515 (10)
    //         0046790c     MOV        EAX,dword ptr [ESI + 0x31c]
    //         00467912     TEST       EAX,EAX
    //         00467914     JZ         LAB_00467980
    //                              Panel_ez.cpp:517 (19)
    //         00467916     MOV        this,dword ptr [ESI + 0x20]
    //         00467919     PUSH       0x1
    //         0046791b     PUSH       s_panel_ez::draw_background2                     = "panel_ez::draw_background2"
    //         00467920     CALL       TDrawArea::Lock                                  uchar * Lock(TDrawArea * this, char * param_1
    //         00467925     TEST       EAX,EAX
    //         00467927     JZ         LAB_00467980
    //                              Panel_ez.cpp:523 (74)
    //         00467929     MOV        DL,byte ptr [ESI + 0x325]
    //         0046792f     MOV        EAX,dword ptr [ESI + 0x10]
    //         00467932     PUSH       EDX
    //         00467933     MOV        DL,byte ptr [ESI + 0x324]
    //         00467939     PUSH       EDX=>DAT_fffffff8
    //         0046793a     MOV        DL,byte ptr [ESI + 0x323]
    //         00467940     PUSH       EDX=>DAT_fffffff4
    //         00467941     MOV        DL,byte ptr [ESI + 0x322]
    //         00467947     PUSH       EDX=>DAT_fffffff0
    //         00467948     MOV        DL,byte ptr [ESI + 0x321]
    //         0046794e     PUSH       EDX
    //         0046794f     MOV        DL,byte ptr [ESI + 0x320]
    //         00467955     MOV        this,dword ptr [ESI + 0xc]
    //         00467958     PUSH       EDX
    //         00467959     MOV        EDX,dword ptr [ESI + 0x18]
    //         0046795c     LEA        EDX,[EDX + EAX*0x1 + -0x1]
    //         00467960     PUSH       EDX
    //         00467961     MOV        EDX,dword ptr [ESI + 0x14]
    //         00467964     LEA        EDX,[EDX + this->_padding_*0x1 + -0x1]
    //         00467968     PUSH       EDX
    //         00467969     PUSH       EAX
    //         0046796a     PUSH       this
    //         0046796b     MOV        this,dword ptr [ESI + 0x20]
    //         0046796e     CALL       TDrawArea::DrawBevel3                            void DrawBevel3(TDrawArea * this, long param_
    //                              Panel_ez.cpp:525 (13)
    //         00467973     MOV        this,dword ptr [ESI + 0x20]
    //         00467976     PUSH       s_panel_ez::draw_background2                     = "panel_ez::draw_background2"
    //         0046797b     CALL       TDrawArea::Unlock                                void Unlock(TDrawArea * this, char * param_1)
    //                               LAB_00467980                                                 XREF[2]:     00467914(j), 00467927(j)  
    //                              Panel_ez.cpp:529 (9)
    //         00467980     MOV        EAX,dword ptr [ESP + 0x28]
    //         00467984     MOV        this,ESI
    //         00467986     CALL       dword ptr [EAX + 0x2c]
    //                              Panel_ez.cpp:530 (10)
    //         00467989     POP        EDI
    //         0046798a     POP        ESI
    //         0046798b     POP        EBP
    //         0046798c     POP        EBX
    //         0046798d     ADD        ESP,0x1c
    //         00467990     RET        0x4
}

// Offset: 0x004679A0
long TRIBE_Screen_Sed_Open::handle_mouse_down(uchar param_1, long param_2, long param_3, int param_4, int param_5) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual long __thiscall TEasy_Panel::handle_mouse_down(unsigned char,long,long,int,int)       *
    //                              *********************************************************************************************************
    //                              long __thiscall handle_mouse_down(TEasy_Panel * this, uchar param_1,
    //              long              EAX:4          <RETURN>
    //              TEasy_Panel *     ECX:4 (auto)   this
    //              uchar             Stack[0x4]:1   param_1                   XREF[1]:     004679a6(R)  
    //              long              Stack[0x8]:4   param_2                   XREF[1]:     004679a1(R)  
    //              long              Stack[0xc]:4   param_3                   XREF[1]:     004679ac(R)  
    //              int               Stack[0x10]:4  param_4                   XREF[1]:     004679ce(R)  
    //              int               Stack[0x14]:4  param_5                   XREF[1]:     004679ca(R)  
    //                               ?handle_mouse_down@TEasy_Panel@@UAEJEJJHH@Z                  XREF[43]:    handle_mouse_down:0043ee5e(c), 
    //                               TEasy_Panel::handle_mouse_down                                            handle_mouse_down:0044188e(c), 
    //                                                                                                         handle_mouse_down:0048f1b1(c), 
    //                                                                                                         handle_mouse_down:00497270(c), 
    //                                                                                                         0056f680(*), 0056f7c0(*), 
    //                                                                                                         0056f908(*), 0056fb68(*), 
    //                                                                                                         0056fca0(*), 0056fdd0(*), 
    //                                                                                                         0056ff00(*), 00570030(*), 
    //                                                                                                         00570d88(*), 00571120(*), 
    //                                                                                                         00571980(*), 00571d60(*), 
    //                                                                                                         00572318(*), 00572440(*), 
    //                                                                                                         00572568(*), 00572690(*), [more]
    //                              Panel_ez.cpp:536 (1)
    //         004679a0     PUSH       EBX
    //                              Panel_ez.cpp:537 (34)
    //         004679a1     MOV        EBX,dword ptr [ESP + param_2]
    //         004679a5     PUSH       EBP
    //         004679a6     MOV        EBP,dword ptr [ESP + param_1]
    //         004679aa     PUSH       ESI
    //         004679ab     PUSH       EDI
    //         004679ac     MOV        EDI,dword ptr [ESP + param_3]
    //         004679b0     MOV        ESI,this
    //         004679b2     PUSH       EDI
    //         004679b3     PUSH       EBX
    //         004679b4     PUSH       EBP
    //         004679b5     CALL       TEasy_Panel::command_do_popup_help               long command_do_popup_help(TEasy_Panel * this
    //         004679ba     TEST       EAX,EAX
    //         004679bc     JZ         LAB_004679ca
    //         004679be     MOV        EAX,0x1
    //                              Panel_ez.cpp:540 (7)
    //         004679c3     POP        EDI
    //         004679c4     POP        ESI
    //         004679c5     POP        EBP
    //         004679c6     POP        EBX
    //         004679c7     RET        0x14
    //                               LAB_004679ca                                                 XREF[1]:     004679bc(j)  
    //                              Panel_ez.cpp:539 (20)
    //         004679ca     MOV        EAX,dword ptr [ESP + param_5]
    //         004679ce     MOV        this,dword ptr [ESP + param_4]
    //         004679d2     PUSH       EAX
    //         004679d3     PUSH       this
    //         004679d4     PUSH       EDI
    //         004679d5     PUSH       EBX
    //         004679d6     PUSH       EBP
    //         004679d7     MOV        this,ESI
    //         004679d9     CALL       TPanel::handle_mouse_down                        long handle_mouse_down(TPanel * this, uchar p
    //                              Panel_ez.cpp:540 (7)
    //         004679de     POP        EDI
    //         004679df     POP        ESI
    //         004679e0     POP        EBP
    //         004679e1     POP        EBX
    //         004679e2     RET        0x14
}

// Offset: 0x004679F0
void set_info_file(TEasy_Panel* this_, char* param_2, long param_3) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TEasy_Panel::set_info_file(char *,long)                                       *
    //                              *********************************************************************************************************
    //                              void __thiscall set_info_file(TEasy_Panel * this, char * param_1, lo
    //              void              <VOID>         <RETURN>
    //              TEasy_Panel *     ECX:4 (auto)   this
    //              char *            Stack[0x4]:4   param_1                   XREF[1]:     004679f1(R)  
    //              long              Stack[0x8]:4   param_2                   XREF[2]:     00467a21(R), 00467a30(R)  
    //                               ?set_info_file@TEasy_Panel@@QAEXPADJ@Z                       XREF[3]:     setup:00466ac3(c), 
    //                               TEasy_Panel::set_info_file                                                player_changed:00498b37(c), 
    //                                                                                                         player_changed:00498b56(c)  
    //                              Panel_ez.cpp:547 (1)
    //         004679f0     PUSH       EDI
    //                              Panel_ez.cpp:548 (10)
    //         004679f1     MOV        EDI,dword ptr [ESP + param_1]
    //         004679f5     TEST       EDI,EDI
    //         004679f7     MOV        EDX,this
    //         004679f9     JZ         LAB_00467a30
    //                              Panel_ez.cpp:549 (38)
    //         004679fb     OR         this,0xffffffff
    //         004679fe     XOR        EAX,EAX
    //         00467a00     SCASB.RE   ES:EDI
    //         00467a02     NOT        this
    //         00467a04     PUSH       ESI
    //         00467a05     SUB        EDI,this
    //         00467a07     PUSH       EBX
    //         00467a08     LEA        EBX,[EDX + 0xfc]
    //         00467a0e     MOV        EAX,this
    //         00467a10     MOV        ESI,EDI
    //         00467a12     MOV        EDI,EBX
    //         00467a14     POP        EBX
    //         00467a15     SHR        this,0x2
    //         00467a18     MOVSD.REP  ES:EDI,ESI
    //         00467a1a     MOV        this,EAX
    //         00467a1c     AND        this,0x3
    //         00467a1f     MOVSB.REP  ES:EDI,ESI
    //                              Panel_ez.cpp:552 (11)
    //         00467a21     MOV        this,dword ptr [ESP + param_2]
    //         00467a25     POP        ESI
    //         00467a26     MOV        dword ptr [EDX + 0x200],this
    //                              Panel_ez.cpp:553 (4)
    //         00467a2c     POP        EDI
    //         00467a2d     RET        0x8
    //                               LAB_00467a30                                                 XREF[1]:     004679f9(j)  
    //                              Panel_ez.cpp:552 (17)
    //         00467a30     MOV        this,dword ptr [ESP + param_2]
    //         00467a34     MOV        byte ptr [EDX + 0xfc],0x0
    //         00467a3b     MOV        dword ptr [EDX + 0x200],this
    //                              Panel_ez.cpp:553 (4)
    //         00467a41     POP        EDI
    //         00467a42     RET        0x8
}

// Offset: 0x00467A50
void TRIBE_Screen_Sed_Open::set_ideal_size(long param_1, long param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * protected: virtual void __thiscall TEasy_Panel::set_ideal_size(long,long)                             *
    //                              *********************************************************************************************************
    //                              void __thiscall set_ideal_size(TEasy_Panel * this, long param_1, lon
    //              void              <VOID>         <RETURN>
    //              TEasy_Panel *     ECX:4 (auto)   this
    //              long              Stack[0x4]:4   param_1                   XREF[1]:     00467a50(R)  
    //              long              Stack[0x8]:4   param_2                   XREF[1]:     00467a54(R)  
    //                               ?set_ideal_size@TEasy_Panel@@MAEXJJ@Z                        XREF[70]:    TribeAchievementsScreen:0048d73a(c
    //                               TEasy_Panel::set_ideal_size                                               TRIBE_Screen_Campaign_Selection:00
    //                                                                                                         TribeJoinScreen:0049172b(c), 
    //                                                                                                         TRIBE_Credits_Screen:004927a3(c), 
    //                                                                                                         TribeLoadSavedGameScreen:0049de4b(
    //                                                                                                         TRIBE_Screen_Main_Menu:0049e783(c)
    //                                                                                                         TRIBE_Screen_Main_Menu:0049e82c(c)
    //                                                                                                         TRIBE_Screen_Main_Menu:0049eb86(c)
    //                                                                                                         TRIBE_Screen_Main_Error:0049f169(c
    //                                                                                                         TribeMPSetupScreen:004a01a0(c), 
    //                                                                                                         TRIBE_Screen_Wait:004a56b4(c), 
    //                                                                                                         TribeSaveGameScreen:004a7336(c), 
    //                                                                                                         TRIBE_Screen_Sed_Menu:004b2f9b(c), 
    //                                                                                                         TRIBE_Screen_Sed_Open:004b34d1(c), 
    //                                                                                                         TribeSelectScenarioScreen:004b3d51
    //                                                                                                         TribeGameSettingsScreen:004b4956(c
    //                                                                                                         TribeSPMenuScreen:004b6a59(c), 
    //                                                                                                         TRIBE_Screen_Status_Message:004b72
    //                                                                                                         TRIBE_Screen_Status_Message:004b74
    //                                                                                                         TRIBE_Mission_Screen:004b81fb(c), 
    //                                                                                                         [more]
    //                              Panel_ez.cpp:559 (4)
    //         00467a50     MOV        EAX,dword ptr [ESP + param_1]
    //                              Panel_ez.cpp:561 (16)
    //         00467a54     MOV        EDX,dword ptr [ESP + param_2]
    //         00467a58     MOV        dword ptr [ECX + this->ideal_width],EAX
    //         00467a5e     MOV        dword ptr [ECX + this->ideal_height],EDX
    //                              Panel_ez.cpp:562 (3)
    //         00467a64     RET        0x8
}

// Offset: 0x00467A70
int set_background(TEasy_Panel* this_, char* param_2, long param_3) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall TEasy_Panel::set_background(char *,long)                                       *
    //                              *********************************************************************************************************
    //                              int __thiscall set_background(TEasy_Panel * this, char * param_1, lo
    //              int               EAX:4          <RETURN>
    //              TEasy_Panel *     ECX:4 (auto)   this
    //              char *            Stack[0x4]:4   param_1                   XREF[1]:     00467ab3(R)  
    //              long              Stack[0x8]:4   param_2                   XREF[2]:     00467b20(R), 00467b36(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[3]:     00467b13(W), 00467b52(W), 00467b70(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     00467bc2(R)  
    //              char[260]         Stack[-0x114   file_name2                XREF[2,3]:   00467b0d(W), 00467b4c(W), 00467ae5(*), 00467af1(*), 
    //                                                                                     00467b27(*)  
    //                               ?set_background@TEasy_Panel@@QAEHPADJ@Z                      XREF[3]:     setup:00466f11(c), 
    //                               TEasy_Panel::set_background                                               setup:00466f37(c), 
    //                                                                                                         setup:00466f5d(c)  
    //                              Panel_ez.cpp:568 (31)
    //         00467a70     MOV        EAX,FS:[0x0]
    //         00467a76     PUSH       -0x1
    //         00467a78     PUSH       FUN_0055decc
    //         00467a7d     PUSH       EAX
    //         00467a7e     MOV        dword ptr FS:[0x0],ESP
    //         00467a85     SUB        ESP,0x108
    //         00467a8b     PUSH       ESI
    //         00467a8c     PUSH       EDI
    //         00467a8d     MOV        EDI,this
    //                              Panel_ez.cpp:571 (10)
    //         00467a8f     MOV        ESI,dword ptr [EDI + 0x204]
    //         00467a95     TEST       ESI,ESI
    //         00467a97     JZ         LAB_00467ab3
    //                              Panel_ez.cpp:573 (16)
    //         00467a99     MOV        this,ESI
    //         00467a9b     CALL       TShape::~TShape                                  void ~TShape(TShape * this)
    //         00467aa0     PUSH       ESI
    //         00467aa1     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         00467aa6     ADD        ESP,0x4
    //                              Panel_ez.cpp:574 (10)
    //         00467aa9     MOV        dword ptr [EDI + 0x204],0x0
    //                               LAB_00467ab3                                                 XREF[1]:     00467a97(j)  
    //                              Panel_ez.cpp:577 (34)
    //         00467ab3     MOV        ESI,dword ptr [ESP + param_1]
    //         00467aba     TEST       ESI,ESI
    //         00467abc     JZ         LAB_00467b36
    //         00467abe     CMP        byte ptr [ESI],0x0
    //         00467ac1     JZ         LAB_00467b36
    //         00467ac3     PUSH       s_none                                           = "none"
    //         00467ac8     PUSH       ESI
    //         00467ac9     CALL       stricmp                                          undefined stricmp()
    //         00467ace     ADD        ESP,0x8
    //         00467ad1     TEST       EAX,EAX
    //         00467ad3     JZ         LAB_00467b36
    //                              Panel_ez.cpp:579 (13)
    //         00467ad5     PUSH       0x2e
    //         00467ad7     PUSH       ESI
    //         00467ad8     CALL       strchr                                           undefined strchr()
    //         00467add     ADD        ESP,0x8
    //         00467ae0     TEST       EAX,EAX
    //                              Panel_ez.cpp:580 (13)
    //         00467ae2     PUSH       ESI
    //         00467ae3     JNZ        LAB_00467af1
    //         00467ae5     LEA        EAX=>file_name2[4],[ESP + 0x10]
    //         00467ae9     PUSH       s_%s.shp                                         = "%s.shp"
    //         00467aee     PUSH       EAX
    //                              Panel_ez.cpp:581 (2)
    //         00467aef     JMP        LAB_00467afb
    //                               LAB_00467af1                                                 XREF[1]:     00467ae3(j)  
    //                              Panel_ez.cpp:582 (18)
    //         00467af1     LEA        this=>file_name2[4],[ESP + 0x10]
    //         00467af5     PUSH       s_%s                                             = "%s"
    //         00467afa     PUSH       this
    //                               LAB_00467afb                                                 XREF[1]:     00467aef(j)  
    //         00467afb     CALL       sprintf                                          undefined sprintf()
    //         00467b00     ADD        ESP,0xc
    //                              Panel_ez.cpp:583 (42)
    //         00467b03     PUSH       0x20
    //         00467b05     CALL       operator_new                                     void * operator_new(uint param_1)
    //         00467b0a     ADD        ESP,0x4
    //         00467b0d     MOV        dword ptr [ESP + file_name2[0]],EAX
    //         00467b11     TEST       EAX,EAX
    //         00467b13     MOV        dword ptr [ESP + local_4],0x0
    //         00467b1e     JZ         LAB_00467b6e
    //         00467b20     MOV        EDX,dword ptr [ESP + param_2]
    //         00467b27     LEA        this=>file_name2[4],[ESP + 0xc]
    //         00467b2b     PUSH       EDX
    //         00467b2c     PUSH       this
    //                              Panel_ez.cpp:586 (9)
    //         00467b2d     MOV        this,EAX
    //         00467b2f     CALL       TShape::TShape                                   undefined TShape(TShape * this, char * param_
    //         00467b34     JMP        LAB_00467b70
    //                               LAB_00467b36                                                 XREF[3]:     00467abc(j), 00467ac1(j), 
    //                                                                                                         00467ad3(j)  
    //                              Panel_ez.cpp:585 (12)
    //         00467b36     MOV        ESI,dword ptr [ESP + param_2]
    //         00467b3d     CMP        ESI,-0x1
    //         00467b40     JZ         LAB_00467b81
    //                              Panel_ez.cpp:586 (63)
    //         00467b42     PUSH       0x20
    //         00467b44     CALL       operator_new                                     void * operator_new(uint param_1)
    //         00467b49     ADD        ESP,0x4
    //         00467b4c     MOV        dword ptr [ESP + file_name2[0]],EAX
    //         00467b50     TEST       EAX,EAX
    //         00467b52     MOV        dword ptr [ESP + local_4],0x1
    //         00467b5d     JZ         LAB_00467b6e
    //         00467b5f     PUSH       ESI
    //         00467b60     PUSH       s_                                               = ""
    //         00467b65     MOV        this,EAX
    //         00467b67     CALL       TShape::TShape                                   undefined TShape(TShape * this, char * param_
    //         00467b6c     JMP        LAB_00467b70
    //                               LAB_00467b6e                                                 XREF[2]:     00467b1e(j), 00467b5d(j)  
    //         00467b6e     XOR        EAX,EAX
    //                               LAB_00467b70                                                 XREF[2]:     00467b34(j), 00467b6c(j)  
    //         00467b70     MOV        dword ptr [ESP + local_4],0xffffffff
    //         00467b7b     MOV        dword ptr [EDI + 0x204],EAX
    //                               LAB_00467b81                                                 XREF[1]:     00467b40(j)  
    //                              Panel_ez.cpp:588 (19)
    //         00467b81     MOV        this,dword ptr [EDI + 0x204]
    //         00467b87     TEST       this,this
    //         00467b89     JZ         LAB_00467bb8
    //         00467b8b     CALL       TShape::is_loaded                                int is_loaded(TShape * this)
    //         00467b90     TEST       EAX,EAX
    //         00467b92     JNZ        LAB_00467bb8
    //                              Panel_ez.cpp:590 (26)
    //         00467b94     MOV        ESI,dword ptr [EDI + 0x204]
    //         00467b9a     TEST       ESI,ESI
    //         00467b9c     JZ         LAB_00467bae
    //         00467b9e     MOV        this,ESI
    //         00467ba0     CALL       TShape::~TShape                                  void ~TShape(TShape * this)
    //         00467ba5     PUSH       ESI
    //         00467ba6     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         00467bab     ADD        ESP,0x4
    //                               LAB_00467bae                                                 XREF[1]:     00467b9c(j)  
    //                              Panel_ez.cpp:591 (10)
    //         00467bae     MOV        dword ptr [EDI + 0x204],0x0
    //                               LAB_00467bb8                                                 XREF[2]:     00467b89(j), 00467b92(j)  
    //                              Panel_ez.cpp:594 (10)
    //         00467bb8     MOV        this,dword ptr [EDI + 0x204]
    //         00467bbe     XOR        EAX,EAX
    //         00467bc0     TEST       this,this
    //                              Panel_ez.cpp:598 (28)
    //         00467bc2     MOV        this,dword ptr [ESP + local_c]
    //         00467bc9     POP        EDI
    //         00467bca     SETNZ      AL
    //         00467bcd     MOV        dword ptr FS:[0x0],this
    //         00467bd4     POP        ESI
    //         00467bd5     ADD        ESP,0x114
    //         00467bdb     RET        0x8
}

// Offset: 0x00467BE0
int set_background2(TEasy_Panel* this_, char* param_2, long param_3) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall TEasy_Panel::set_background2(char *,long)                                      *
    //                              *********************************************************************************************************
    //                              int __thiscall set_background2(TEasy_Panel * this, char * param_1, l
    //              int               EAX:4          <RETURN>
    //              TEasy_Panel *     ECX:4 (auto)   this
    //              char *            Stack[0x4]:4   param_1                   XREF[1]:     00467c23(R)  
    //              long              Stack[0x8]:4   param_2                   XREF[2]:     00467c90(R), 00467ca6(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[3]:     00467c83(W), 00467cc2(W), 00467ce0(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     00467d32(R)  
    //              char[260]         Stack[-0x114   file_name2                XREF[2,3]:   00467c7d(W), 00467cbc(W), 00467c55(*), 00467c61(*), 
    //                                                                                     00467c97(*)  
    //                               ?set_background2@TEasy_Panel@@QAEHPADJ@Z                     XREF[1]:     setup:00466f71(c)  
    //                               TEasy_Panel::set_background2
    //                              Panel_ez.cpp:604 (31)
    //         00467be0     MOV        EAX,FS:[0x0]
    //         00467be6     PUSH       -0x1
    //         00467be8     PUSH       FUN_0055defc
    //         00467bed     PUSH       EAX
    //         00467bee     MOV        dword ptr FS:[0x0],ESP
    //         00467bf5     SUB        ESP,0x108
    //         00467bfb     PUSH       ESI
    //         00467bfc     PUSH       EDI
    //         00467bfd     MOV        EDI,this
    //                              Panel_ez.cpp:607 (10)
    //         00467bff     MOV        ESI,dword ptr [EDI + 0x208]
    //         00467c05     TEST       ESI,ESI
    //         00467c07     JZ         LAB_00467c23
    //                              Panel_ez.cpp:609 (16)
    //         00467c09     MOV        this,ESI
    //         00467c0b     CALL       TShape::~TShape                                  void ~TShape(TShape * this)
    //         00467c10     PUSH       ESI
    //         00467c11     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         00467c16     ADD        ESP,0x4
    //                              Panel_ez.cpp:610 (10)
    //         00467c19     MOV        dword ptr [EDI + 0x208],0x0
    //                               LAB_00467c23                                                 XREF[1]:     00467c07(j)  
    //                              Panel_ez.cpp:613 (34)
    //         00467c23     MOV        ESI,dword ptr [ESP + param_1]
    //         00467c2a     TEST       ESI,ESI
    //         00467c2c     JZ         LAB_00467ca6
    //         00467c2e     CMP        byte ptr [ESI],0x0
    //         00467c31     JZ         LAB_00467ca6
    //         00467c33     PUSH       s_none                                           = "none"
    //         00467c38     PUSH       ESI
    //         00467c39     CALL       stricmp                                          undefined stricmp()
    //         00467c3e     ADD        ESP,0x8
    //         00467c41     TEST       EAX,EAX
    //         00467c43     JZ         LAB_00467ca6
    //                              Panel_ez.cpp:615 (13)
    //         00467c45     PUSH       0x2e
    //         00467c47     PUSH       ESI
    //         00467c48     CALL       strchr                                           undefined strchr()
    //         00467c4d     ADD        ESP,0x8
    //         00467c50     TEST       EAX,EAX
    //                              Panel_ez.cpp:616 (13)
    //         00467c52     PUSH       ESI
    //         00467c53     JNZ        LAB_00467c61
    //         00467c55     LEA        EAX=>file_name2[4],[ESP + 0x10]
    //         00467c59     PUSH       s_%s.shp                                         = "%s.shp"
    //         00467c5e     PUSH       EAX
    //                              Panel_ez.cpp:617 (2)
    //         00467c5f     JMP        LAB_00467c6b
    //                               LAB_00467c61                                                 XREF[1]:     00467c53(j)  
    //                              Panel_ez.cpp:618 (18)
    //         00467c61     LEA        this=>file_name2[4],[ESP + 0x10]
    //         00467c65     PUSH       s_%s                                             = "%s"
    //         00467c6a     PUSH       this
    //                               LAB_00467c6b                                                 XREF[1]:     00467c5f(j)  
    //         00467c6b     CALL       sprintf                                          undefined sprintf()
    //         00467c70     ADD        ESP,0xc
    //                              Panel_ez.cpp:619 (42)
    //         00467c73     PUSH       0x20
    //         00467c75     CALL       operator_new                                     void * operator_new(uint param_1)
    //         00467c7a     ADD        ESP,0x4
    //         00467c7d     MOV        dword ptr [ESP + file_name2[0]],EAX
    //         00467c81     TEST       EAX,EAX
    //         00467c83     MOV        dword ptr [ESP + local_4],0x0
    //         00467c8e     JZ         LAB_00467cde
    //         00467c90     MOV        EDX,dword ptr [ESP + param_2]
    //         00467c97     LEA        this=>file_name2[4],[ESP + 0xc]
    //         00467c9b     PUSH       EDX
    //         00467c9c     PUSH       this
    //                              Panel_ez.cpp:622 (9)
    //         00467c9d     MOV        this,EAX
    //         00467c9f     CALL       TShape::TShape                                   undefined TShape(TShape * this, char * param_
    //         00467ca4     JMP        LAB_00467ce0
    //                               LAB_00467ca6                                                 XREF[3]:     00467c2c(j), 00467c31(j), 
    //                                                                                                         00467c43(j)  
    //                              Panel_ez.cpp:621 (12)
    //         00467ca6     MOV        ESI,dword ptr [ESP + param_2]
    //         00467cad     CMP        ESI,-0x1
    //         00467cb0     JZ         LAB_00467cf1
    //                              Panel_ez.cpp:622 (63)
    //         00467cb2     PUSH       0x20
    //         00467cb4     CALL       operator_new                                     void * operator_new(uint param_1)
    //         00467cb9     ADD        ESP,0x4
    //         00467cbc     MOV        dword ptr [ESP + file_name2[0]],EAX
    //         00467cc0     TEST       EAX,EAX
    //         00467cc2     MOV        dword ptr [ESP + local_4],0x1
    //         00467ccd     JZ         LAB_00467cde
    //         00467ccf     PUSH       ESI
    //         00467cd0     PUSH       s_                                               = ""
    //         00467cd5     MOV        this,EAX
    //         00467cd7     CALL       TShape::TShape                                   undefined TShape(TShape * this, char * param_
    //         00467cdc     JMP        LAB_00467ce0
    //                               LAB_00467cde                                                 XREF[2]:     00467c8e(j), 00467ccd(j)  
    //         00467cde     XOR        EAX,EAX
    //                               LAB_00467ce0                                                 XREF[2]:     00467ca4(j), 00467cdc(j)  
    //         00467ce0     MOV        dword ptr [ESP + local_4],0xffffffff
    //         00467ceb     MOV        dword ptr [EDI + 0x208],EAX
    //                               LAB_00467cf1                                                 XREF[1]:     00467cb0(j)  
    //                              Panel_ez.cpp:624 (19)
    //         00467cf1     MOV        this,dword ptr [EDI + 0x208]
    //         00467cf7     TEST       this,this
    //         00467cf9     JZ         LAB_00467d28
    //         00467cfb     CALL       TShape::is_loaded                                int is_loaded(TShape * this)
    //         00467d00     TEST       EAX,EAX
    //         00467d02     JNZ        LAB_00467d28
    //                              Panel_ez.cpp:626 (26)
    //         00467d04     MOV        ESI,dword ptr [EDI + 0x208]
    //         00467d0a     TEST       ESI,ESI
    //         00467d0c     JZ         LAB_00467d1e
    //         00467d0e     MOV        this,ESI
    //         00467d10     CALL       TShape::~TShape                                  void ~TShape(TShape * this)
    //         00467d15     PUSH       ESI
    //         00467d16     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         00467d1b     ADD        ESP,0x4
    //                               LAB_00467d1e                                                 XREF[1]:     00467d0c(j)  
    //                              Panel_ez.cpp:627 (10)
    //         00467d1e     MOV        dword ptr [EDI + 0x208],0x0
    //                               LAB_00467d28                                                 XREF[2]:     00467cf9(j), 00467d02(j)  
    //                              Panel_ez.cpp:630 (10)
    //         00467d28     MOV        this,dword ptr [EDI + 0x208]
    //         00467d2e     XOR        EAX,EAX
    //         00467d30     TEST       this,this
    //                              Panel_ez.cpp:634 (28)
    //         00467d32     MOV        this,dword ptr [ESP + local_c]
    //         00467d39     POP        EDI
    //         00467d3a     SETNZ      AL
    //         00467d3d     MOV        dword ptr FS:[0x0],this
    //         00467d44     POP        ESI
    //         00467d45     ADD        ESP,0x114
    //         00467d4b     RET        0x8
}

// Offset: 0x00467D50
void set_background_colors(TEasy_Panel* this_, uchar param_2, uchar param_3) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TEasy_Panel::set_background_colors(unsigned char,unsigned char)               *
    //                              *********************************************************************************************************
    //                              void __thiscall set_background_colors(TEasy_Panel * this, uchar para
    //              void              <VOID>         <RETURN>
    //              TEasy_Panel *     ECX:4 (auto)   this
    //              uchar             Stack[0x4]:1   param_1                   XREF[1]:     00467d51(R)  
    //              uchar             Stack[0x8]:1   param_2
    //                               ?set_background_colors@TEasy_Panel@@QAEXEE@Z                 XREF[1]:     setup:00466fc7(c)  
    //                               TEasy_Panel::set_background_colors
    //                              Panel_ez.cpp:640 (1)
    //         00467d50     PUSH       EBX
    //                              Panel_ez.cpp:641 (13)
    //         00467d51     MOV        EBX,dword ptr [ESP + param_1]
    //         00467d55     PUSH       ESI
    //         00467d56     MOV        ESI,this
    //         00467d58     PUSH       EBX
    //         00467d59     MOV        EAX,dword ptr [ESI]
    //         00467d5b     CALL       dword ptr [EAX + 0x10]
    //                              Panel_ez.cpp:643 (4)
    //         00467d5e     MOV        this,byte ptr [ESP + 0x10]
    //                              Panel_ez.cpp:684 (26)
    //         00467d62     PUSH       0x4
    //         00467d64     MOV        byte ptr [ESI + 0x454],BL
    //         00467d6a     MOV        byte ptr [ESI + 0x455],this
    //         00467d70     CALL       dword ptr [->GDI32.DLL::GetStockObject]          = 0048b1b8
    //         00467d76     MOV        dword ptr [ESI + 0x464],EAX
    //                              Panel_ez.cpp:685 (10)
    //         00467d7c     MOV        dword ptr [ESI + 0x460],0x1
    //                              Panel_ez.cpp:686 (10)
    //         00467d86     MOV        dword ptr [ESI + 0x468],0x0
    //                              Panel_ez.cpp:687 (5)
    //         00467d90     POP        ESI
    //         00467d91     POP        EBX
    //         00467d92     RET        0x8
}

// Offset: 0x00467DA0
int set_palette(TEasy_Panel* this_, char* param_2, long param_3) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall TEasy_Panel::set_palette(char *,long)                                          *
    //                              *********************************************************************************************************
    //                              int __thiscall set_palette(TEasy_Panel * this, char * param_1, long 
    //              int               EAX:4          <RETURN>
    //              TEasy_Panel *     ECX:4 (auto)   this
    //              char *            Stack[0x4]:4   param_1                   XREF[1]:     00467e00(R)  
    //              long              Stack[0x8]:4   param_2                   XREF[1]:     00467df9(R)  
    //              tagPALETTEENTR    Stack[-0x410   palette_entries
    //                               ?set_palette@TEasy_Panel@@QAEHPADJ@Z                         XREF[1]:     setup:00466f94(c)  
    //                               TEasy_Panel::set_palette
    //                              Panel_ez.cpp:693 (32)
    //         00467da0     MOV        EAX,FS:[0x0]
    //         00467da6     PUSH       -0x1
    //         00467da8     PUSH       FUN_0055df1e
    //         00467dad     PUSH       EAX
    //         00467dae     MOV        dword ptr FS:[0x0],ESP
    //         00467db5     SUB        ESP,0x404
    //         00467dbb     PUSH       EBP
    //         00467dbc     PUSH       ESI
    //         00467dbd     MOV        ESI,this
    //         00467dbf     PUSH       EDI
    //                              Panel_ez.cpp:694 (10)
    //         00467dc0     MOV        EAX,dword ptr [ESI + 0x20c]
    //         00467dc6     TEST       EAX,EAX
    //         00467dc8     JZ         LAB_00467ddf
    //                              Panel_ez.cpp:696 (11)
    //         00467dca     PUSH       EAX
    //         00467dcb     MOV        this,panel_system
    //         00467dd0     CALL       TPanelSystem::release_palette                    void release_palette(TPanelSystem * this, voi
    //                              Panel_ez.cpp:697 (10)
    //         00467dd5     MOV        dword ptr [ESI + 0x20c],0x0
    //                               LAB_00467ddf                                                 XREF[1]:     00467dc8(j)  
    //                              Panel_ez.cpp:700 (10)
    //         00467ddf     MOV        this,dword ptr [ESI + 0x44c]
    //         00467de5     TEST       this,this
    //         00467de7     JZ         LAB_00467df9
    //                              Panel_ez.cpp:702 (6)
    //         00467de9     MOV        EAX,dword ptr [this->_padding_]
    //         00467deb     PUSH       0x1
    //         00467ded     CALL       dword ptr [EAX]
    //                              Panel_ez.cpp:703 (10)
    //         00467def     MOV        dword ptr [ESI + 0x44c],0x0
    //                               LAB_00467df9                                                 XREF[1]:     00467de7(j)  
    //                              Panel_ez.cpp:706 (54)
    //         00467df9     MOV        EBP,dword ptr [ESP + param_2]
    //         00467e00     MOV        EDI,dword ptr [ESP + param_1]
    //         00467e07     CMP        EBP,-0x1
    //         00467e0a     JNZ        LAB_00467e39
    //         00467e0c     TEST       EDI,EDI
    //         00467e0e     JZ         LAB_00467ebe
    //         00467e14     CMP        byte ptr [EDI],0x0
    //         00467e17     JZ         LAB_00467ebe
    //         00467e1d     PUSH       s_none                                           = "none"
    //         00467e22     PUSH       EDI=>DAT_fffffff8
    //         00467e23     CALL       stricmp                                          undefined stricmp()
    //         00467e28     ADD        ESP,0x8
    //         00467e2b     TEST       EAX,EAX
    //         00467e2d     JNZ        LAB_00467e39
    //                              Panel_ez.cpp:720 (10)
    //         00467e2f     MOV        EAX,0x1
    //         00467e34     JMP        LAB_00467ec7
    //                               LAB_00467e39                                                 XREF[2]:     00467e0a(j), 00467e2d(j)  
    //                              Panel_ez.cpp:708 (12)
    //         00467e39     PUSH       EBP
    //         00467e3a     PUSH       EDI=>DAT_fffffff8
    //         00467e3b     MOV        this,panel_system
    //         00467e40     CALL       TPanelSystem::get_palette                        void * get_palette(TPanelSystem * this, char 
    //                              Panel_ez.cpp:709 (20)
    //         00467e45     TEST       EAX,EAX
    //         00467e47     MOV        dword ptr [ESI + 0x20c],EAX
    //         00467e4d     JZ         LAB_00467ec5
    //         00467e4f     MOV        this,dword ptr [ESI + 0x450]
    //         00467e55     TEST       this,this
    //         00467e57     JLE        LAB_00467ec5
    //                              Panel_ez.cpp:712 (23)
    //         00467e59     LEA        this,[ESP + 0x10]
    //         00467e5d     PUSH       this
    //         00467e5e     PUSH       offset DAT_fffffff8
    //         00467e63     PUSH       0x0=>DAT_fffffff4
    //         00467e65     PUSH       EAX=>DAT_fffffff0
    //         00467e66     CALL       dword ptr [->GDI32.DLL::GetPaletteEntries]       = 0048b270
    //         00467e6c     TEST       EAX,EAX
    //         00467e6e     JZ         LAB_00467ebe
    //                              Panel_ez.cpp:713 (63)
    //         00467e70     PUSH       0x128
    //         00467e75     CALL       operator_new                                     void * operator_new(uint param_1)
    //         00467e7a     ADD        ESP,0x4
    //         00467e7d     MOV        dword ptr [ESP + 0xc],EAX
    //         00467e81     TEST       EAX,EAX
    //         00467e83     MOV        dword ptr [ESP + 0x418],0x0
    //         00467e8e     JZ         LAB_00467eb6
    //         00467e90     MOV        this,dword ptr [ESI + 0x450]
    //         00467e96     LEA        EDX,[ESP + 0x10]
    //         00467e9a     PUSH       EDX
    //         00467e9b     MOV        EDX,dword ptr [ESI + 0x20]
    //         00467e9e     PUSH       0x0=>DAT_fffffff8
    //         00467ea0     PUSH       this=>DAT_fffffff4
    //         00467ea1     PUSH       EDX=>DAT_fffffff0
    //         00467ea2     MOV        this,EAX
    //         00467ea4     CALL       RGE_Color_Table::RGE_Color_Table                 undefined RGE_Color_Table(RGE_Color_Table * t
    //         00467ea9     MOV        dword ptr [ESI + 0x44c],EAX
    //                              Panel_ez.cpp:714 (7)
    //         00467eaf     MOV        EAX,0x1
    //         00467eb4     JMP        LAB_00467ec7
    //                               LAB_00467eb6                                                 XREF[1]:     00467e8e(j)  
    //                              Panel_ez.cpp:713 (8)
    //         00467eb6     XOR        EAX,EAX
    //         00467eb8     MOV        dword ptr [ESI + 0x44c],EAX
    //                               LAB_00467ebe                                                 XREF[3]:     00467e0e(j), 00467e17(j), 
    //                                                                                                         00467e6e(j)  
    //                              Panel_ez.cpp:714 (7)
    //         00467ebe     MOV        EAX,0x1
    //         00467ec3     JMP        LAB_00467ec7
    //                               LAB_00467ec5                                                 XREF[2]:     00467e4d(j), 00467e57(j)  
    //                              Panel_ez.cpp:717 (2)
    //         00467ec5     XOR        EAX,EAX
    //                               LAB_00467ec7                                                 XREF[3]:     00467e34(j), 00467eb4(j), 
    //                                                                                                         00467ec3(j)  
    //                              Panel_ez.cpp:721 (26)
    //         00467ec7     MOV        this,dword ptr [ESP + 0x410]
    //         00467ece     POP        EDI
    //         00467ecf     POP        ESI
    //         00467ed0     MOV        dword ptr FS:[0x0],this
    //         00467ed7     POP        EBP
    //         00467ed8     ADD        ESP,0x410
    //         00467ede     RET        0x8
}

// Offset: 0x00467EF0
int set_cursor(TEasy_Panel* this_, char* param_2, long param_3) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall TEasy_Panel::set_cursor(char *,long)                                           *
    //                              *********************************************************************************************************
    //                              int __thiscall set_cursor(TEasy_Panel * this, char * param_1, long p
    //              int               EAX:4          <RETURN>
    //              TEasy_Panel *     ECX:4 (auto)   this
    //              char *            Stack[0x4]:4   param_1                   XREF[1]:     00467ef5(R)  
    //              long              Stack[0x8]:4   param_2                   XREF[1]:     00467f21(R)  
    //                               ?set_cursor@TEasy_Panel@@QAEHPADJ@Z                          XREF[1]:     setup:00466fab(c)  
    //                               TEasy_Panel::set_cursor
    //                              Panel_ez.cpp:727 (5)
    //         00467ef0     PUSH       EBX
    //         00467ef1     PUSH       ESI
    //         00467ef2     MOV        EDX,this
    //         00467ef4     PUSH       EDI
    //                              Panel_ez.cpp:728 (34)
    //         00467ef5     MOV        EDI,dword ptr [ESP + param_1]
    //         00467ef9     OR         this,0xffffffff
    //         00467efc     XOR        EAX,EAX
    //         00467efe     LEA        EBX,[EDX + 0x210]
    //         00467f04     SCASB.RE   ES:EDI
    //         00467f06     NOT        this
    //         00467f08     SUB        EDI,this
    //         00467f0a     MOV        EAX,this
    //         00467f0c     MOV        ESI,EDI
    //         00467f0e     MOV        EDI,EBX
    //         00467f10     SHR        this,0x2
    //         00467f13     MOVSD.REP  ES:EDI,ESI
    //         00467f15     MOV        this,EAX
    //                              Panel_ez.cpp:730 (14)
    //         00467f17     MOV        EAX,0x1
    //         00467f1c     AND        this,0x3
    //         00467f1f     MOVSB.REP  ES:EDI,ESI
    //         00467f21     MOV        this,dword ptr [ESP + param_2]
    //                              Panel_ez.cpp:731 (12)
    //         00467f25     POP        EDI
    //         00467f26     POP        ESI
    //         00467f27     MOV        dword ptr [EDX + 0x314],this
    //         00467f2d     POP        EBX
    //         00467f2e     RET        0x8
}

// Offset: 0x00467F40
void set_use_bevels(TEasy_Panel* this_, int param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TEasy_Panel::set_use_bevels(int)                                              *
    //                              *********************************************************************************************************
    //                              void __thiscall set_use_bevels(TEasy_Panel * this, int param_1)
    //              void              <VOID>         <RETURN>
    //              TEasy_Panel *     ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     00467f40(R)  
    //                               ?set_use_bevels@TEasy_Panel@@QAEXH@Z                         XREF[1]:     setup:00466ec9(c)  
    //                               TEasy_Panel::set_use_bevels
    //                              Panel_ez.cpp:737 (10)
    //         00467f40     MOV        EAX,dword ptr [ESP + param_1]
    //         00467f44     MOV        dword ptr [ECX + this->use_bevels],EAX
    //                              Panel_ez.cpp:739 (3)
    //         00467f4a     RET        0x4
}

// Offset: 0x00467F50
void set_background_pos(TEasy_Panel* this_, int param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TEasy_Panel::set_background_pos(int)                                          *
    //                              *********************************************************************************************************
    //                              void __thiscall set_background_pos(TEasy_Panel * this, int param_1)
    //              void              <VOID>         <RETURN>
    //              TEasy_Panel *     ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     00467f50(R)  
    //                               ?set_background_pos@TEasy_Panel@@QAEXH@Z                     XREF[1]:     setup:00466fb7(c)  
    //                               TEasy_Panel::set_background_pos
    //                              Panel_ez.cpp:745 (10)
    //         00467f50     MOV        EAX,dword ptr [ESP + param_1]
    //         00467f54     MOV        dword ptr [ECX + this->background_pos],EAX
    //                              Panel_ez.cpp:747 (3)
    //         00467f5a     RET        0x4
}

// Offset: 0x00467F60
void set_bevel_colors(TEasy_Panel* this_, uchar param_2, uchar param_3, uchar param_4, uchar param_5, uchar param_6, uchar param_7) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TEasy_Panel::set_bevel_colors(unsigned char,unsigned char,unsigned char,un... *
    //                              *********************************************************************************************************
    //                              void __thiscall set_bevel_colors(TEasy_Panel * this, uchar param_1, 
    //              void              <VOID>         <RETURN>
    //              TEasy_Panel *     ECX:4 (auto)   this
    //              uchar             Stack[0x4]:1   param_1                   XREF[1]:     00467f60(R)  
    //              uchar             Stack[0x8]:1   param_2                   XREF[1]:     00467f64(R)  
    //              uchar             Stack[0xc]:1   param_3                   XREF[1]:     00467f6e(R)  
    //              uchar             Stack[0x10]:1  param_4                   XREF[1]:     00467f78(R)  
    //              uchar             Stack[0x14]:1  param_5                   XREF[1]:     00467f82(R)  
    //              uchar             Stack[0x18]:1  param_6                   XREF[1]:     00467f8c(R)  
    //                               ?set_bevel_colors@TEasy_Panel@@QAEXEEEEEE@Z                  XREF[2]:     setup:00466ff2(c), 
    //                               TEasy_Panel::set_bevel_colors                                             player_changed:00498c0c(c)  
    //                              Panel_ez.cpp:753 (4)
    //         00467f60     MOV        AL,byte ptr [ESP + param_1]
    //                              Panel_ez.cpp:755 (10)
    //         00467f64     MOV        DL,byte ptr [ESP + param_2]
    //         00467f68     MOV        byte ptr [ECX + this->bevel_color1],AL
    //                              Panel_ez.cpp:756 (10)
    //         00467f6e     MOV        AL,byte ptr [ESP + param_3]
    //         00467f72     MOV        byte ptr [ECX + this->bevel_color2],DL
    //                              Panel_ez.cpp:757 (10)
    //         00467f78     MOV        DL,byte ptr [ESP + param_4]
    //         00467f7c     MOV        byte ptr [ECX + this->bevel_color3],AL
    //                              Panel_ez.cpp:758 (10)
    //         00467f82     MOV        AL,byte ptr [ESP + param_5]
    //         00467f86     MOV        byte ptr [ECX + this->bevel_color4],DL
    //                              Panel_ez.cpp:759 (16)
    //         00467f8c     MOV        DL,byte ptr [ESP + param_6]
    //         00467f90     MOV        byte ptr [ECX + this->bevel_color5],AL
    //         00467f96     MOV        byte ptr [ECX + this->bevel_color6],DL
    //                              Panel_ez.cpp:760 (3)
    //         00467f9c     RET        0x18
}

// Offset: 0x00467FA0
void set_text_colors(TEasy_Panel* this_, ulong param_2, ulong param_3) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TEasy_Panel::set_text_colors(unsigned long,unsigned long)                     *
    //                              *********************************************************************************************************
    //                              void __thiscall set_text_colors(TEasy_Panel * this, ulong param_1, u
    //              void              <VOID>         <RETURN>
    //              TEasy_Panel *     ECX:4 (auto)   this
    //              ulong             Stack[0x4]:4   param_1                   XREF[1]:     00467fa0(R)  
    //              ulong             Stack[0x8]:4   param_2                   XREF[1]:     00467fa4(R)  
    //                               ?set_text_colors@TEasy_Panel@@QAEXKK@Z                       XREF[1]:     setup:00467035(c)  
    //                               TEasy_Panel::set_text_colors
    //                              Panel_ez.cpp:766 (4)
    //         00467fa0     MOV        EAX,dword ptr [ESP + param_1]
    //                              Panel_ez.cpp:768 (16)
    //         00467fa4     MOV        EDX,dword ptr [ESP + param_2]
    //         00467fa8     MOV        dword ptr [ECX + this->text_color1],EAX
    //         00467fae     MOV        dword ptr [ECX + this->text_color2],EDX
    //                              Panel_ez.cpp:769 (3)
    //         00467fb4     RET        0x8
}

// Offset: 0x00467FC0
void set_focus_colors(TEasy_Panel* this_, ulong param_2, ulong param_3) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TEasy_Panel::set_focus_colors(unsigned long,unsigned long)                    *
    //                              *********************************************************************************************************
    //                              void __thiscall set_focus_colors(TEasy_Panel * this, ulong param_1, 
    //              void              <VOID>         <RETURN>
    //              TEasy_Panel *     ECX:4 (auto)   this
    //              ulong             Stack[0x4]:4   param_1                   XREF[1]:     00467fc0(R)  
    //              ulong             Stack[0x8]:4   param_2                   XREF[1]:     00467fc4(R)  
    //                               ?set_focus_colors@TEasy_Panel@@QAEXKK@Z                      XREF[1]:     setup:0046706f(c)  
    //                               TEasy_Panel::set_focus_colors
    //                              Panel_ez.cpp:775 (4)
    //         00467fc0     MOV        EAX,dword ptr [ESP + param_1]
    //                              Panel_ez.cpp:777 (16)
    //         00467fc4     MOV        EDX,dword ptr [ESP + param_2]
    //         00467fc8     MOV        dword ptr [ECX + this->focus_color1],EAX
    //         00467fce     MOV        dword ptr [ECX + this->focus_color2],EDX
    //                              Panel_ez.cpp:778 (3)
    //         00467fd4     RET        0x8
}

// Offset: 0x00467FE0
void set_state_colors(TEasy_Panel* this_, ulong param_2, ulong param_3) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TEasy_Panel::set_state_colors(unsigned long,unsigned long)                    *
    //                              *********************************************************************************************************
    //                              void __thiscall set_state_colors(TEasy_Panel * this, ulong param_1, 
    //              void              <VOID>         <RETURN>
    //              TEasy_Panel *     ECX:4 (auto)   this
    //              ulong             Stack[0x4]:4   param_1                   XREF[1]:     00467fe0(R)  
    //              ulong             Stack[0x8]:4   param_2                   XREF[1]:     00467fe4(R)  
    //                               ?set_state_colors@TEasy_Panel@@QAEXKK@Z                      XREF[1]:     setup:004670aa(c)  
    //                               TEasy_Panel::set_state_colors
    //                              Panel_ez.cpp:784 (4)
    //         00467fe0     MOV        EAX,dword ptr [ESP + param_1]
    //                              Panel_ez.cpp:786 (16)
    //         00467fe4     MOV        EDX,dword ptr [ESP + param_2]
    //         00467fe8     MOV        dword ptr [ECX + this->state_color1],EAX
    //         00467fee     MOV        dword ptr [ECX + this->state_color2],EDX
    //                              Panel_ez.cpp:787 (3)
    //         00467ff4     RET        0x8
}

// Offset: 0x00468000
void set_popup_info_file(TEasy_Panel* this_, char* param_2, long param_3) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TEasy_Panel::set_popup_info_file(char *,long)                                 *
    //                              *********************************************************************************************************
    //                              void __thiscall set_popup_info_file(TEasy_Panel * this, char * param
    //              void              <VOID>         <RETURN>
    //              TEasy_Panel *     ECX:4 (auto)   this
    //              char *            Stack[0x4]:4   param_1                   XREF[1]:     00468001(R)  
    //              long              Stack[0x8]:4   param_2                   XREF[2]:     00468031(R), 00468040(R)  
    //                               ?set_popup_info_file@TEasy_Panel@@QAEXPADJ@Z                 XREF[2]:     setup:004670d2(c), 
    //                               TEasy_Panel::set_popup_info_file                                          player_changed:00498b63(c)  
    //                              Panel_ez.cpp:793 (1)
    //         00468000     PUSH       EDI
    //                              Panel_ez.cpp:794 (10)
    //         00468001     MOV        EDI,dword ptr [ESP + param_1]
    //         00468005     TEST       EDI,EDI
    //         00468007     MOV        EDX,this
    //         00468009     JZ         LAB_00468040
    //                              Panel_ez.cpp:795 (38)
    //         0046800b     OR         this,0xffffffff
    //         0046800e     XOR        EAX,EAX
    //         00468010     SCASB.RE   ES:EDI
    //         00468012     NOT        this
    //         00468014     PUSH       ESI
    //         00468015     SUB        EDI,this
    //         00468017     PUSH       EBX
    //         00468018     LEA        EBX,[EDX + 0x340]
    //         0046801e     MOV        EAX,this
    //         00468020     MOV        ESI,EDI
    //         00468022     MOV        EDI,EBX
    //         00468024     POP        EBX
    //         00468025     SHR        this,0x2
    //         00468028     MOVSD.REP  ES:EDI,ESI
    //         0046802a     MOV        this,EAX
    //         0046802c     AND        this,0x3
    //         0046802f     MOVSB.REP  ES:EDI,ESI
    //                              Panel_ez.cpp:798 (11)
    //         00468031     MOV        this,dword ptr [ESP + param_2]
    //         00468035     POP        ESI
    //         00468036     MOV        dword ptr [EDX + 0x444],this
    //                              Panel_ez.cpp:799 (4)
    //         0046803c     POP        EDI
    //         0046803d     RET        0x8
    //                               LAB_00468040                                                 XREF[1]:     00468009(j)  
    //                              Panel_ez.cpp:798 (17)
    //         00468040     MOV        this,dword ptr [ESP + param_2]
    //         00468044     MOV        byte ptr [EDX + 0x340],0x0
    //         0046804b     MOV        dword ptr [EDX + 0x444],this
    //                              Panel_ez.cpp:799 (4)
    //         00468051     POP        EDI
    //         00468052     RET        0x8
}

// Offset: 0x00468060
void set_button_pics(TEasy_Panel* this_, char* param_2, long param_3) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TEasy_Panel::set_button_pics(char *,long)                                     *
    //                              *********************************************************************************************************
    //                              void __thiscall set_button_pics(TEasy_Panel * this, char * param_1, 
    //              void              <VOID>         <RETURN>
    //              TEasy_Panel *     ECX:4 (auto)   this
    //              char *            Stack[0x4]:4   param_1                   XREF[1]:     004680a3(R)  
    //              long              Stack[0x8]:4   param_2                   XREF[2]:     00468110(R), 00468126(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[3]:     00468103(W), 00468142(W), 00468160(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     004681a8(R)  
    //              char[260]         Stack[-0x114   file_name2                XREF[2,3]:   004680fd(W), 0046813c(W), 004680d5(*), 004680e1(*), 
    //                                                                                     00468117(*)  
    //                               ?set_button_pics@TEasy_Panel@@QAEXPADJ@Z                     XREF[2]:     setup:004670be(c), 
    //                               TEasy_Panel::set_button_pics                                              player_changed:00498b9a(c)  
    //                              Panel_ez.cpp:805 (31)
    //         00468060     MOV        EAX,FS:[0x0]
    //         00468066     PUSH       -0x1
    //         00468068     PUSH       FUN_0055df4c
    //         0046806d     PUSH       EAX
    //         0046806e     MOV        dword ptr FS:[0x0],ESP
    //         00468075     SUB        ESP,0x108
    //         0046807b     PUSH       ESI
    //         0046807c     PUSH       EDI
    //         0046807d     MOV        EDI,this
    //                              Panel_ez.cpp:808 (10)
    //         0046807f     MOV        ESI,dword ptr [EDI + 0x448]
    //         00468085     TEST       ESI,ESI
    //         00468087     JZ         LAB_004680a3
    //                              Panel_ez.cpp:810 (16)
    //         00468089     MOV        this,ESI
    //         0046808b     CALL       TShape::~TShape                                  void ~TShape(TShape * this)
    //         00468090     PUSH       ESI
    //         00468091     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         00468096     ADD        ESP,0x4
    //                              Panel_ez.cpp:811 (10)
    //         00468099     MOV        dword ptr [EDI + 0x448],0x0
    //                               LAB_004680a3                                                 XREF[1]:     00468087(j)  
    //                              Panel_ez.cpp:814 (34)
    //         004680a3     MOV        ESI,dword ptr [ESP + param_1]
    //         004680aa     TEST       ESI,ESI
    //         004680ac     JZ         LAB_00468126
    //         004680ae     CMP        byte ptr [ESI],0x0
    //         004680b1     JZ         LAB_00468126
    //         004680b3     PUSH       s_none                                           = "none"
    //         004680b8     PUSH       ESI
    //         004680b9     CALL       stricmp                                          undefined stricmp()
    //         004680be     ADD        ESP,0x8
    //         004680c1     TEST       EAX,EAX
    //         004680c3     JZ         LAB_00468126
    //                              Panel_ez.cpp:816 (13)
    //         004680c5     PUSH       0x2e
    //         004680c7     PUSH       ESI
    //         004680c8     CALL       strchr                                           undefined strchr()
    //         004680cd     ADD        ESP,0x8
    //         004680d0     TEST       EAX,EAX
    //                              Panel_ez.cpp:817 (13)
    //         004680d2     PUSH       ESI
    //         004680d3     JNZ        LAB_004680e1
    //         004680d5     LEA        EAX=>file_name2[4],[ESP + 0x10]
    //         004680d9     PUSH       s_%s.shp                                         = "%s.shp"
    //         004680de     PUSH       EAX
    //                              Panel_ez.cpp:818 (2)
    //         004680df     JMP        LAB_004680eb
    //                               LAB_004680e1                                                 XREF[1]:     004680d3(j)  
    //                              Panel_ez.cpp:819 (18)
    //         004680e1     LEA        this=>file_name2[4],[ESP + 0x10]
    //         004680e5     PUSH       s_%s                                             = "%s"
    //         004680ea     PUSH       this
    //                               LAB_004680eb                                                 XREF[1]:     004680df(j)  
    //         004680eb     CALL       sprintf                                          undefined sprintf()
    //         004680f0     ADD        ESP,0xc
    //                              Panel_ez.cpp:820 (42)
    //         004680f3     PUSH       0x20
    //         004680f5     CALL       operator_new                                     void * operator_new(uint param_1)
    //         004680fa     ADD        ESP,0x4
    //         004680fd     MOV        dword ptr [ESP + file_name2[0]],EAX
    //         00468101     TEST       EAX,EAX
    //         00468103     MOV        dword ptr [ESP + local_4],0x0
    //         0046810e     JZ         LAB_0046815e
    //         00468110     MOV        EDX,dword ptr [ESP + param_2]
    //         00468117     LEA        this=>file_name2[4],[ESP + 0xc]
    //         0046811b     PUSH       EDX
    //         0046811c     PUSH       this
    //                              Panel_ez.cpp:823 (9)
    //         0046811d     MOV        this,EAX
    //         0046811f     CALL       TShape::TShape                                   undefined TShape(TShape * this, char * param_
    //         00468124     JMP        LAB_00468160
    //                               LAB_00468126                                                 XREF[3]:     004680ac(j), 004680b1(j), 
    //                                                                                                         004680c3(j)  
    //                              Panel_ez.cpp:822 (12)
    //         00468126     MOV        ESI,dword ptr [ESP + param_2]
    //         0046812d     CMP        ESI,-0x1
    //         00468130     JZ         LAB_00468171
    //                              Panel_ez.cpp:823 (63)
    //         00468132     PUSH       0x20
    //         00468134     CALL       operator_new                                     void * operator_new(uint param_1)
    //         00468139     ADD        ESP,0x4
    //         0046813c     MOV        dword ptr [ESP + file_name2[0]],EAX
    //         00468140     TEST       EAX,EAX
    //         00468142     MOV        dword ptr [ESP + local_4],0x1
    //         0046814d     JZ         LAB_0046815e
    //         0046814f     PUSH       ESI
    //         00468150     PUSH       s_                                               = ""
    //         00468155     MOV        this,EAX
    //         00468157     CALL       TShape::TShape                                   undefined TShape(TShape * this, char * param_
    //         0046815c     JMP        LAB_00468160
    //                               LAB_0046815e                                                 XREF[2]:     0046810e(j), 0046814d(j)  
    //         0046815e     XOR        EAX,EAX
    //                               LAB_00468160                                                 XREF[2]:     00468124(j), 0046815c(j)  
    //         00468160     MOV        dword ptr [ESP + local_4],0xffffffff
    //         0046816b     MOV        dword ptr [EDI + 0x448],EAX
    //                               LAB_00468171                                                 XREF[1]:     00468130(j)  
    //                              Panel_ez.cpp:825 (19)
    //         00468171     MOV        this,dword ptr [EDI + 0x448]
    //         00468177     TEST       this,this
    //         00468179     JZ         LAB_004681a8
    //         0046817b     CALL       TShape::is_loaded                                int is_loaded(TShape * this)
    //         00468180     TEST       EAX,EAX
    //         00468182     JNZ        LAB_004681a8
    //                              Panel_ez.cpp:827 (26)
    //         00468184     MOV        ESI,dword ptr [EDI + 0x448]
    //         0046818a     TEST       ESI,ESI
    //         0046818c     JZ         LAB_0046819e
    //         0046818e     MOV        this,ESI
    //         00468190     CALL       TShape::~TShape                                  void ~TShape(TShape * this)
    //         00468195     PUSH       ESI
    //         00468196     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         0046819b     ADD        ESP,0x4
    //                               LAB_0046819e                                                 XREF[1]:     0046818c(j)  
    //                              Panel_ez.cpp:828 (10)
    //         0046819e     MOV        dword ptr [EDI + 0x448],0x0
    //                               LAB_004681a8                                                 XREF[2]:     00468179(j), 00468182(j)  
    //                              Panel_ez.cpp:830 (25)
    //         004681a8     MOV        this,dword ptr [ESP + local_c]
    //         004681af     POP        EDI
    //         004681b0     MOV        dword ptr FS:[0x0],this
    //         004681b7     POP        ESI
    //         004681b8     ADD        ESP,0x114
    //         004681be     RET        0x8
}

// Offset: 0x004681D0
void set_shadow_amount(TEasy_Panel* this_, long param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TEasy_Panel::set_shadow_amount(long)                                          *
    //                              *********************************************************************************************************
    //                              void __thiscall set_shadow_amount(TEasy_Panel * this, long param_1)
    //              void              <VOID>         <RETURN>
    //              TEasy_Panel *     ECX:4 (auto)   this
    //              long              Stack[0x4]:4   param_1                   XREF[1]:     004681de(R)  
    //              tagPALETTEENTR    Stack[-0x410   palette_entries           XREF[0,1]:   00468237(*)  
    //                               ?set_shadow_amount@TEasy_Panel@@QAEXJ@Z                      XREF[1]:     setup:00466f80(c)  
    //                               TEasy_Panel::set_shadow_amount
    //                              Panel_ez.cpp:836 (14)
    //         004681d0     MOV        EAX,FS:[0x0]
    //         004681d6     PUSH       -0x1
    //         004681d8     PUSH       FUN_0055df6e
    //         004681dd     PUSH       EAX
    //                              Panel_ez.cpp:837 (25)
    //         004681de     MOV        EAX,dword ptr [ESP + param_1]
    //         004681e2     MOV        dword ptr FS:[0x0],ESP
    //         004681e9     SUB        ESP,0x404
    //         004681ef     CMP        EAX,-0x1
    //         004681f2     PUSH       ESI
    //         004681f3     MOV        ESI,this
    //         004681f5     JNZ        LAB_00468203
    //                              Panel_ez.cpp:838 (10)
    //         004681f7     MOV        dword ptr [ESI + 0x450],0x0
    //                              Panel_ez.cpp:839 (2)
    //         00468201     JMP        LAB_00468209
    //                               LAB_00468203                                                 XREF[1]:     004681f5(j)  
    //                              Panel_ez.cpp:840 (6)
    //         00468203     MOV        dword ptr [ESI + 0x450],EAX
    //                               LAB_00468209                                                 XREF[1]:     00468201(j)  
    //                              Panel_ez.cpp:842 (10)
    //         00468209     MOV        this,dword ptr [ESI + 0x44c]
    //         0046820f     TEST       this,this
    //         00468211     JZ         LAB_00468223
    //                              Panel_ez.cpp:844 (6)
    //         00468213     MOV        EAX,dword ptr [this->_padding_]
    //         00468215     PUSH       0x1
    //         00468217     CALL       dword ptr [EAX]
    //                              Panel_ez.cpp:845 (10)
    //         00468219     MOV        dword ptr [ESI + 0x44c],0x0
    //                               LAB_00468223                                                 XREF[1]:     00468211(j)  
    //                              Panel_ez.cpp:848 (20)
    //         00468223     MOV        EAX,dword ptr [ESI + 0x20c]
    //         00468229     TEST       EAX,EAX
    //         0046822b     JZ         LAB_0046829c
    //         0046822d     MOV        this,dword ptr [ESI + 0x450]
    //         00468233     TEST       this,this
    //         00468235     JLE        LAB_0046829c
    //                              Panel_ez.cpp:851 (23)
    //         00468237     LEA        this=>palette_entries[1],[ESP + 0x8]
    //         0046823b     PUSH       this
    //         0046823c     PUSH       offset DAT_fffffff8
    //         00468241     PUSH       0x0=>DAT_fffffff4
    //         00468243     PUSH       EAX=>DAT_fffffff0
    //         00468244     CALL       dword ptr [->GDI32.DLL::GetPaletteEntries]       = 0048b270
    //         0046824a     TEST       EAX,EAX
    //         0046824c     JZ         LAB_0046829c
    //                              Panel_ez.cpp:852 (78)
    //         0046824e     PUSH       0x128
    //         00468253     CALL       operator_new                                     void * operator_new(uint param_1)
    //         00468258     ADD        ESP,0x4
    //         0046825b     MOV        dword ptr [ESP + 0x4],EAX
    //         0046825f     TEST       EAX,EAX
    //         00468261     MOV        dword ptr [ESP + 0x410],0x0
    //         0046826c     JZ         LAB_00468289
    //         0046826e     MOV        this,dword ptr [ESI + 0x450]
    //         00468274     LEA        EDX,[ESP + 0x8]
    //         00468278     PUSH       EDX
    //         00468279     MOV        EDX,dword ptr [ESI + 0x20]
    //         0046827c     PUSH       0x0=>DAT_fffffff8
    //         0046827e     PUSH       this=>DAT_fffffff4
    //         0046827f     PUSH       EDX=>DAT_fffffff0
    //         00468280     MOV        this,EAX
    //         00468282     CALL       RGE_Color_Table::RGE_Color_Table                 undefined RGE_Color_Table(RGE_Color_Table * t
    //         00468287     JMP        LAB_0046828b
    //                               LAB_00468289                                                 XREF[1]:     0046826c(j)  
    //         00468289     XOR        EAX,EAX
    //                               LAB_0046828b                                                 XREF[1]:     00468287(j)  
    //         0046828b     MOV        dword ptr [ESP + 0x410],0xffffffff
    //         00468296     MOV        dword ptr [ESI + 0x44c],EAX
    //                               LAB_0046829c                                                 XREF[3]:     0046822b(j), 00468235(j), 
    //                                                                                                         0046824c(j)  
    //                              Panel_ez.cpp:855 (7)
    //         0046829c     MOV        EAX,dword ptr [ESI + 0x78]
    //         0046829f     TEST       EAX,EAX
    //         004682a1     JZ         LAB_004682ac
    //                              Panel_ez.cpp:856 (9)
    //         004682a3     MOV        EAX,dword ptr [ESI]
    //         004682a5     PUSH       0x2
    //         004682a7     MOV        this,ESI
    //         004682a9     CALL       dword ptr [EAX + 0x20]
    //                               LAB_004682ac                                                 XREF[1]:     004682a1(j)  
    //                              Panel_ez.cpp:857 (24)
    //         004682ac     MOV        this,dword ptr [ESP + 0x408]
    //         004682b3     POP        ESI
    //         004682b4     MOV        dword ptr FS:[0x0],this
    //         004682bb     ADD        ESP,0x410
    //         004682c1     RET        0x4
}

// Offset: 0x004682D0
void set_enable_ime(TEasy_Panel* this_, int param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TEasy_Panel::set_enable_ime(int)                                              *
    //                              *********************************************************************************************************
    //                              void __thiscall set_enable_ime(TEasy_Panel * this, int param_1)
    //              void              <VOID>         <RETURN>
    //              TEasy_Panel *     ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     004682d3(R)  
    //                               ?set_enable_ime@TEasy_Panel@@QAEXH@Z
    //                               TEasy_Panel::set_enable_ime
    //                              Panel_ez.cpp:863 (17)
    //         004682d0     MOV        EDX,dword ptr [ECX + this->_padding_]
    //         004682d3     MOV        EAX,dword ptr [ESP + param_1]
    //         004682d7     TEST       EDX,EDX
    //         004682d9     MOV        dword ptr [ECX + this->enable_ime],EAX
    //         004682df     JZ         LAB_004682f7
    //                              Panel_ez.cpp:867 (2)
    //         004682e1     TEST       EAX,EAX
    //                              Panel_ez.cpp:868 (12)
    //         004682e3     MOV        this,panel_system
    //         004682e8     JZ         LAB_004682f2
    //         004682ea     CALL       TPanelSystem::EnableIME                          void EnableIME(TPanelSystem * this)
    //                              Panel_ez.cpp:872 (3)
    //         004682ef     RET        0x4
    //                               LAB_004682f2                                                 XREF[1]:     004682e8(j)  
    //                              Panel_ez.cpp:870 (5)
    //         004682f2     CALL       TPanelSystem::DisableIME                         void DisableIME(TPanelSystem * this)
    //                               LAB_004682f7                                                 XREF[1]:     004682df(j)  
    //                              Panel_ez.cpp:872 (3)
    //         004682f7     RET        0x4
}

// Offset: 0x00468300
char* get_info_file(TEasy_Panel* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: char * __thiscall TEasy_Panel::get_info_file(void)                                            *
    //                              *********************************************************************************************************
    //                              char * __thiscall get_info_file(TEasy_Panel * this)
    //              char *            EAX:4          <RETURN>
    //              TEasy_Panel *     ECX:4 (auto)   this
    //                               ?get_info_file@TEasy_Panel@@QAEPADXZ                         XREF[4]:     TribeLoadSavedGameScreen:0049ddd9(
    //                               TEasy_Panel::get_info_file                                                TRIBE_Screen_Sed_Open:004b345f(c), 
    //                                                                                                         TRIBE_Screen_Status_Message:004b71
    //                                                                                                         TRIBE_Screen_Status_Message:004b73
    //                              Panel_ez.cpp:878 (6)
    //         00468300     LEA        EAX,[ECX + this->info_file_name[0]]
    //                              Panel_ez.cpp:880 (1)
    //         00468306     RET
}

// Offset: 0x00468310
long get_info_id(TEasy_Panel* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: long __thiscall TEasy_Panel::get_info_id(void)                                                *
    //                              *********************************************************************************************************
    //                              long __thiscall get_info_id(TEasy_Panel * this)
    //              long              EAX:4          <RETURN>
    //              TEasy_Panel *     ECX:4 (auto)   this
    //                               ?get_info_id@TEasy_Panel@@QAEJXZ                             XREF[4]:     TribeLoadSavedGameScreen:0049de10(
    //                               TEasy_Panel::get_info_id                                                  TRIBE_Screen_Sed_Open:004b3496(c), 
    //                                                                                                         TRIBE_Screen_Status_Message:004b71
    //                                                                                                         TRIBE_Screen_Status_Message:004b73
    //                              Panel_ez.cpp:886 (6)
    //         00468310     MOV        EAX,dword ptr [ECX + this->info_id]
    //                              Panel_ez.cpp:888 (1)
    //         00468316     RET
}

// Offset: 0x00468320
TShape* get_background(TEasy_Panel* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: class TShape * __thiscall TEasy_Panel::get_background(void)                                   *
    //                              *********************************************************************************************************
    //                              TShape * __thiscall get_background(TEasy_Panel * this)
    //              TShape *          EAX:4          <RETURN>
    //              TEasy_Panel *     ECX:4 (auto)   this
    //                               ?get_background@TEasy_Panel@@QAEPAVTShape@@XZ
    //                               TEasy_Panel::get_background
    //                              Panel_ez.cpp:894 (6)
    //         00468320     MOV        EAX,dword ptr [ECX + this->background_pic]
    //                              Panel_ez.cpp:896 (1)
    //         00468326     RET
}

// Offset: 0x00468330
TShape* get_background2(TEasy_Panel* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: class TShape * __thiscall TEasy_Panel::get_background2(void)                                  *
    //                              *********************************************************************************************************
    //                              TShape * __thiscall get_background2(TEasy_Panel * this)
    //              TShape *          EAX:4          <RETURN>
    //              TEasy_Panel *     ECX:4 (auto)   this
    //                               ?get_background2@TEasy_Panel@@QAEPAVTShape@@XZ
    //                               TEasy_Panel::get_background2
    //                              Panel_ez.cpp:902 (6)
    //         00468330     MOV        EAX,dword ptr [ECX + this->background_pic2]
    //                              Panel_ez.cpp:904 (1)
    //         00468336     RET
}

// Offset: 0x00468340
void* get_palette(TEasy_Panel* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void * __thiscall TEasy_Panel::get_palette(void)                                              *
    //                              *********************************************************************************************************
    //                              void * __thiscall get_palette(TEasy_Panel * this)
    //              void *            EAX:4          <RETURN>
    //              TEasy_Panel *     ECX:4 (auto)   this
    //                               ?get_palette@TEasy_Panel@@QAEPAXXZ                           XREF[3]:     handle_query_new_palette:00421af6(
    //                               TEasy_Panel::get_palette                                                  handle_query_new_palette:00421b03(
    //                                                                                                         do_command_game:0050a3a6(c)  
    //                              Panel_ez.cpp:910 (6)
    //         00468340     MOV        EAX,dword ptr [ECX + this->palette]
    //                              Panel_ez.cpp:912 (1)
    //         00468346     RET
}

// Offset: 0x00468350
char* get_cursor(TEasy_Panel* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: char * __thiscall TEasy_Panel::get_cursor(void)                                               *
    //                              *********************************************************************************************************
    //                              char * __thiscall get_cursor(TEasy_Panel * this)
    //              char *            EAX:4          <RETURN>
    //              TEasy_Panel *     ECX:4 (auto)   this
    //                               ?get_cursor@TEasy_Panel@@QAEPADXZ
    //                               TEasy_Panel::get_cursor
    //                              Panel_ez.cpp:918 (6)
    //         00468350     LEA        EAX,[ECX + this->cursor_file[0]]
    //                              Panel_ez.cpp:920 (1)
    //         00468356     RET
}

// Offset: 0x00468360
int get_use_bevels(TEasy_Panel* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall TEasy_Panel::get_use_bevels(void)                                              *
    //                              *********************************************************************************************************
    //                              int __thiscall get_use_bevels(TEasy_Panel * this)
    //              int               EAX:4          <RETURN>
    //              TEasy_Panel *     ECX:4 (auto)   this
    //                               ?get_use_bevels@TEasy_Panel@@QAEHXZ
    //                               TEasy_Panel::get_use_bevels
    //                              Panel_ez.cpp:926 (6)
    //         00468360     MOV        EAX,dword ptr [ECX + this->use_bevels]
    //                              Panel_ez.cpp:928 (1)
    //         00468366     RET
}

// Offset: 0x00468370
int get_background_pos(TEasy_Panel* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall TEasy_Panel::get_background_pos(void)                                          *
    //                              *********************************************************************************************************
    //                              int __thiscall get_background_pos(TEasy_Panel * this)
    //              int               EAX:4          <RETURN>
    //              TEasy_Panel *     ECX:4 (auto)   this
    //                               ?get_background_pos@TEasy_Panel@@QAEHXZ
    //                               TEasy_Panel::get_background_pos
    //                              Panel_ez.cpp:934 (6)
    //         00468370     MOV        EAX,dword ptr [ECX + this->background_pos]
    //                              Panel_ez.cpp:936 (1)
    //         00468376     RET
}

// Offset: 0x00468380
void get_bevel_colors(TEasy_Panel* this_, uchar* param_2, uchar* param_3, uchar* param_4, uchar* param_5, uchar* param_6, uchar* param_7) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TEasy_Panel::get_bevel_colors(unsigned char &,unsigned char &,unsigned cha... *
    //                              *********************************************************************************************************
    //                              void __thiscall get_bevel_colors(TEasy_Panel * this, uchar * param_1
    //              void              <VOID>         <RETURN>
    //              TEasy_Panel *     ECX:4 (auto)   this
    //              uchar *           Stack[0x4]:4   param_1                   XREF[1]:     00468380(R)  
    //              uchar *           Stack[0x8]:4   param_2                   XREF[1]:     0046838c(R)  
    //              uchar *           Stack[0xc]:4   param_3                   XREF[1]:     00468398(R)  
    //              uchar *           Stack[0x10]:4  param_4                   XREF[1]:     004683a4(R)  
    //              uchar *           Stack[0x14]:4  param_5                   XREF[1]:     004683b0(R)  
    //              uchar *           Stack[0x18]:4  param_6                   XREF[1]:     004683c2(R)  
    //                               ?get_bevel_colors@TEasy_Panel@@QAEXAAE00000@Z
    //                               TEasy_Panel::get_bevel_colors
    //                              Panel_ez.cpp:942 (12)
    //         00468380     MOV        EDX,dword ptr [ESP + param_1]
    //         00468384     MOV        AL,byte ptr [ECX + this->bevel_color1]
    //         0046838a     MOV        byte ptr [EDX],AL
    //                              Panel_ez.cpp:944 (12)
    //         0046838c     MOV        EDX,dword ptr [ESP + param_2]
    //         00468390     MOV        AL,byte ptr [ECX + this->bevel_color2]
    //         00468396     MOV        byte ptr [EDX],AL
    //                              Panel_ez.cpp:945 (12)
    //         00468398     MOV        EDX,dword ptr [ESP + param_3]
    //         0046839c     MOV        AL,byte ptr [ECX + this->bevel_color3]
    //         004683a2     MOV        byte ptr [EDX],AL
    //                              Panel_ez.cpp:946 (12)
    //         004683a4     MOV        EDX,dword ptr [ESP + param_4]
    //         004683a8     MOV        AL,byte ptr [ECX + this->bevel_color4]
    //         004683ae     MOV        byte ptr [EDX],AL
    //                              Panel_ez.cpp:947 (12)
    //         004683b0     MOV        EDX,dword ptr [ESP + param_5]
    //         004683b4     MOV        AL,byte ptr [ECX + this->bevel_color5]
    //         004683ba     MOV        byte ptr [EDX],AL
    //                              Panel_ez.cpp:948 (12)
    //         004683bc     MOV        AL,byte ptr [ECX + this->bevel_color6]
    //         004683c2     MOV        this,dword ptr [ESP + param_6]
    //         004683c6     MOV        byte ptr [this->_padding_],AL
    //                              Panel_ez.cpp:949 (3)
    //         004683c8     RET        0x18
}

// Offset: 0x004683D0
void get_text_colors(TEasy_Panel* this_, ulong* param_2, ulong* param_3) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TEasy_Panel::get_text_colors(unsigned long &,unsigned long &)                 *
    //                              *********************************************************************************************************
    //                              void __thiscall get_text_colors(TEasy_Panel * this, ulong * param_1,
    //              void              <VOID>         <RETURN>
    //              TEasy_Panel *     ECX:4 (auto)   this
    //              ulong *           Stack[0x4]:4   param_1                   XREF[1]:     004683d0(R)  
    //              ulong *           Stack[0x8]:4   param_2                   XREF[1]:     004683e2(R)  
    //                               ?get_text_colors@TEasy_Panel@@QAEXAAK0@Z
    //                               TEasy_Panel::get_text_colors
    //                              Panel_ez.cpp:955 (12)
    //         004683d0     MOV        EDX,dword ptr [ESP + param_1]
    //         004683d4     MOV        EAX,dword ptr [ECX + this->text_color1]
    //         004683da     MOV        dword ptr [EDX],EAX
    //                              Panel_ez.cpp:957 (12)
    //         004683dc     MOV        EAX,dword ptr [ECX + this->text_color2]
    //         004683e2     MOV        this,dword ptr [ESP + param_2]
    //         004683e6     MOV        dword ptr [this->_padding_],EAX
    //                              Panel_ez.cpp:958 (3)
    //         004683e8     RET        0x8
}

// Offset: 0x004683F0
void get_focus_colors(TEasy_Panel* this_, ulong* param_2, ulong* param_3) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TEasy_Panel::get_focus_colors(unsigned long &,unsigned long &)                *
    //                              *********************************************************************************************************
    //                              void __thiscall get_focus_colors(TEasy_Panel * this, ulong * param_1
    //              void              <VOID>         <RETURN>
    //              TEasy_Panel *     ECX:4 (auto)   this
    //              ulong *           Stack[0x4]:4   param_1                   XREF[1]:     004683f0(R)  
    //              ulong *           Stack[0x8]:4   param_2                   XREF[1]:     00468402(R)  
    //                               ?get_focus_colors@TEasy_Panel@@QAEXAAK0@Z
    //                               TEasy_Panel::get_focus_colors
    //                              Panel_ez.cpp:964 (12)
    //         004683f0     MOV        EDX,dword ptr [ESP + param_1]
    //         004683f4     MOV        EAX,dword ptr [ECX + this->focus_color1]
    //         004683fa     MOV        dword ptr [EDX],EAX
    //                              Panel_ez.cpp:966 (12)
    //         004683fc     MOV        EAX,dword ptr [ECX + this->focus_color2]
    //         00468402     MOV        this,dword ptr [ESP + param_2]
    //         00468406     MOV        dword ptr [this->_padding_],EAX
    //                              Panel_ez.cpp:967 (3)
    //         00468408     RET        0x8
}

// Offset: 0x00468410
long get_shadow_amount(TEasy_Panel* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: long __thiscall TEasy_Panel::get_shadow_amount(void)                                          *
    //                              *********************************************************************************************************
    //                              long __thiscall get_shadow_amount(TEasy_Panel * this)
    //              long              EAX:4          <RETURN>
    //              TEasy_Panel *     ECX:4 (auto)   this
    //                               ?get_shadow_amount@TEasy_Panel@@QAEJXZ
    //                               TEasy_Panel::get_shadow_amount
    //                              Panel_ez.cpp:973 (6)
    //         00468410     MOV        EAX,dword ptr [ECX + this->shadow_amount]
    //                              Panel_ez.cpp:975 (1)
    //         00468416     RET
}

// Offset: 0x00468420
void get_state_colors(TEasy_Panel* this_, ulong* param_2, ulong* param_3) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TEasy_Panel::get_state_colors(unsigned long &,unsigned long &)                *
    //                              *********************************************************************************************************
    //                              void __thiscall get_state_colors(TEasy_Panel * this, ulong * param_1
    //              void              <VOID>         <RETURN>
    //              TEasy_Panel *     ECX:4 (auto)   this
    //              ulong *           Stack[0x4]:4   param_1                   XREF[1]:     00468420(R)  
    //              ulong *           Stack[0x8]:4   param_2                   XREF[1]:     00468432(R)  
    //                               ?get_state_colors@TEasy_Panel@@QAEXAAK0@Z
    //                               TEasy_Panel::get_state_colors
    //                              Panel_ez.cpp:981 (12)
    //         00468420     MOV        EDX,dword ptr [ESP + param_1]
    //         00468424     MOV        EAX,dword ptr [ECX + this->state_color1]
    //         0046842a     MOV        dword ptr [EDX],EAX
    //                              Panel_ez.cpp:983 (12)
    //         0046842c     MOV        EAX,dword ptr [ECX + this->state_color2]
    //         00468432     MOV        this,dword ptr [ESP + param_2]
    //         00468436     MOV        dword ptr [this->_padding_],EAX
    //                              Panel_ez.cpp:984 (3)
    //         00468438     RET        0x8
}

// Offset: 0x00468440
char* get_popup_info_file(TEasy_Panel* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: char * __thiscall TEasy_Panel::get_popup_info_file(void)                                      *
    //                              *********************************************************************************************************
    //                              char * __thiscall get_popup_info_file(TEasy_Panel * this)
    //              char *            EAX:4          <RETURN>
    //              TEasy_Panel *     ECX:4 (auto)   this
    //                               ?get_popup_info_file@TEasy_Panel@@QAEPADXZ                   XREF[12]:    TribeAboutDialog:0043ae18(c), 
    //                               TEasy_Panel::get_popup_info_file                                          TribeConfigDialog:0043b6b9(c), 
    //                                                                                                         TribeDiplomacyDialog:0043ca46(c), 
    //                                                                                                         setup_help:0043ea68(c), 
    //                                                                                                         TribeMenuDialog:0043f3d3(c), 
    //                                                                                                         TRIBE_Dialog_Sed_Menu:004401a1(c), 
    //                                                                                                         TribeSendMessageDialog:00440895(c)
    //                                                                                                         TribeSendQuickMessageDialog:004415
    //                                                                                                         action:0048a02a(c), 
    //                                                                                                         TribeMPCreateDialog:0049214a(c), 
    //                                                                                                         TRIBE_Dialog_Name:004a6dd1(c), 
    //                                                                                                         TribeSaveGameScreen:004a72c4(c)  
    //                              Panel_ez.cpp:990 (6)
    //         00468440     LEA        EAX,[ECX + this->popup_info_file_name[0]]
    //                              Panel_ez.cpp:992 (1)
    //         00468446     RET
}

// Offset: 0x00468450
long get_popup_info_id(TEasy_Panel* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: long __thiscall TEasy_Panel::get_popup_info_id(void)                                          *
    //                              *********************************************************************************************************
    //                              long __thiscall get_popup_info_id(TEasy_Panel * this)
    //              long              EAX:4          <RETURN>
    //              TEasy_Panel *     ECX:4 (auto)   this
    //                               ?get_popup_info_id@TEasy_Panel@@QAEJXZ                       XREF[12]:    TribeAboutDialog:0043ae10(c), 
    //                               TEasy_Panel::get_popup_info_id                                            TribeConfigDialog:0043b6b1(c), 
    //                                                                                                         TribeDiplomacyDialog:0043ca3e(c), 
    //                                                                                                         setup_help:0043ea60(c), 
    //                                                                                                         TribeMenuDialog:0043f3cb(c), 
    //                                                                                                         TRIBE_Dialog_Sed_Menu:00440199(c), 
    //                                                                                                         TribeSendMessageDialog:0044088d(c)
    //                                                                                                         TribeSendQuickMessageDialog:004415
    //                                                                                                         action:0048a01e(c), 
    //                                                                                                         TribeMPCreateDialog:00492142(c), 
    //                                                                                                         TRIBE_Dialog_Name:004a6dc9(c), 
    //                                                                                                         TribeSaveGameScreen:004a72fb(c)  
    //                              Panel_ez.cpp:998 (6)
    //         00468450     MOV        EAX,dword ptr [ECX + this->popup_info_id]
    //                              Panel_ez.cpp:1000 (1)
    //         00468456     RET
}

// Offset: 0x00468460
TShape* get_button_pics(TEasy_Panel* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: class TShape * __thiscall TEasy_Panel::get_button_pics(void)                                  *
    //                              *********************************************************************************************************
    //                              TShape * __thiscall get_button_pics(TEasy_Panel * this)
    //              TShape *          EAX:4          <RETURN>
    //              TEasy_Panel *     ECX:4 (auto)   this
    //                               ?get_button_pics@TEasy_Panel@@QAEPAVTShape@@XZ
    //                               TEasy_Panel::get_button_pics
    //                              Panel_ez.cpp:1006 (6)
    //         00468460     MOV        EAX,dword ptr [ECX + this->button_pics]
    //                              Panel_ez.cpp:1008 (1)
    //         00468466     RET
}

// Offset: 0x00468470
RGE_Color_Table* get_shadow_color_table(TEasy_Panel* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: class RGE_Color_Table * __thiscall TEasy_Panel::get_shadow_color_table(void)                  *
    //                              *********************************************************************************************************
    //                              RGE_Color_Table * __thiscall get_shadow_color_table(TEasy_Panel * th
    //              RGE_Color_Tabl    EAX:4          <RETURN>
    //              TEasy_Panel *     ECX:4 (auto)   this
    //                               ?get_shadow_color_table@TEasy_Panel@@QAEPAVRGE_Color_Table@
    //                               TEasy_Panel::get_shadow_color_table
    //                              Panel_ez.cpp:1014 (6)
    //         00468470     MOV        EAX,dword ptr [ECX + this->shadow_color_table]
    //                              Panel_ez.cpp:1016 (1)
    //         00468476     RET
}

// Offset: 0x00468480
int get_enable_ime(TEasy_Panel* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall TEasy_Panel::get_enable_ime(void)                                              *
    //                              *********************************************************************************************************
    //                              int __thiscall get_enable_ime(TEasy_Panel * this)
    //              int               EAX:4          <RETURN>
    //              TEasy_Panel *     ECX:4 (auto)   this
    //                               ?get_enable_ime@TEasy_Panel@@QAEHXZ
    //                               TEasy_Panel::get_enable_ime
    //                              Panel_ez.cpp:1022 (6)
    //         00468480     MOV        EAX,dword ptr [ECX + this->enable_ime]
    //                              Panel_ez.cpp:1024 (1)
    //         00468486     RET
}

// Offset: 0x00468490
int TRIBE_Screen_Sed_Open::create_button(TPanel* param_1, TButtonPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9, long param_10, long param_11) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * protected: virtual int __thiscall TEasy_Panel::create_button(class TPanel *,class TButtonPanel * *... *
    //                              *********************************************************************************************************
    //                              int __thiscall create_button(TEasy_Panel * this, TPanel * param_1, T
    //              int               EAX:4          <RETURN>
    //              TEasy_Panel *     ECX:4 (auto)   this
    //              TPanel *          Stack[0x4]:4   param_1                   XREF[1]:     00468513(R)  
    //              TButtonPanel *    Stack[0x8]:4   param_2                   XREF[1]:     0046850b(R)  
    //              long              Stack[0xc]:4   param_3                   XREF[1]:     0046849d(R)  
    //              long              Stack[0x10]:4  param_4                   XREF[1]:     004684af(R)  
    //              long              Stack[0x14]:4  param_5                   XREF[1]:     004684f6(R)  
    //              long              Stack[0x18]:4  param_6                   XREF[1]:     004684ec(R)  
    //              long              Stack[0x1c]:4  param_7                   XREF[1]:     004684e4(R)  
    //              long              Stack[0x20]:4  param_8                   XREF[1]:     004684dc(R)  
    //              long              Stack[0x24]:4  param_9                   XREF[1]:     004684d4(R)  
    //              long              Stack[0x28]:4  param_10                  XREF[1]:     004684cc(R)  
    //              long              Stack[0x2c]:4  param_11                  XREF[1]:     004684c5(R)  
    //              char[120]         Stack[-0x7c]   text1                     XREF[0,2]:   00468496(*), 00468503(*)  
    //              char[120]         Stack[-0xf4]   text2                     XREF[0,2]:   004684b6(*), 004684ff(*)  
    //                               ?create_button@TEasy_Panel@@MAEHPAVTPanel@@PAPAVTButtonPane  XREF[145]:   TribeAchievementsScreen:0048d9e4(c
    //                               TEasy_Panel::create_button                                                TribeAchievementsScreen:0048dec0(c
    //                                                                                                         TribeAchievementsScreen:0048deed(c
    //                                                                                                         TribeAchievementsScreen:0048df1a(c
    //                                                                                                         TribeAchievementsScreen:0048df58(c
    //                                                                                                         TribeAchievementsScreen:0048df85(c
    //                                                                                                         TribeAchievementsScreen:0048dfc8(c
    //                                                                                                         TribeAchievementsScreen:0048dff5(c
    //                                                                                                         TribeAchievementsScreen:0048e022(c
    //                                                                                                         TribeAchievementsScreen:0048e06f(c
    //                                                                                                         TRIBE_Screen_Campaign_Selection:00
    //                                                                                                         TRIBE_Screen_Campaign_Selection:00
    //                                                                                                         TRIBE_Screen_Campaign_Selection:00
    //                                                                                                         TRIBE_Screen_Wait:004a56f6(c), 
    //                                                                                                         TribeSaveGameScreen:004a7466(c), 
    //                                                                                                         TribeSaveGameScreen:004a749b(c), 
    //                                                                                                         TribeSaveGameScreen:004a74d0(c), 
    //                                                                                                         TRIBE_Screen_Sed_Open:004b3566(c), 
    //                                                                                                         TRIBE_Screen_Sed_Open:004b359b(c), 
    //                                                                                                         TRIBE_Screen_Sed_Open:004b35d0(c), 
    //                                                                                                         [more]
    //                              Panel_ez.cpp:1030 (6)
    //         00468490     SUB        ESP,0xf0
    //                              Panel_ez.cpp:1033 (25)
    //         00468496     LEA        EAX=>text1[4],[ESP + 0x78]
    //         0046849a     PUSH       ESI
    //         0046849b     MOV        ESI,this
    //         0046849d     MOV        this,dword ptr [ESP + param_3]
    //                              language.dll match for 0x78: "10"
    //         004684a4     PUSH       0x78
    //         004684a6     PUSH       EAX
    //         004684a7     PUSH       this
    //         004684a8     MOV        this,ESI
    //         004684aa     CALL       TPanel::get_string                               int get_string(TPanel * this, int param_1, ch
    //                              Panel_ez.cpp:1034 (22)
    //         004684af     MOV        EAX,dword ptr [ESP + param_4]
    //         004684b6     LEA        EDX=>text2[4],[ESP + 0x4]
    //                              language.dll match for 0x78: "10"
    //         004684ba     PUSH       0x78
    //         004684bc     PUSH       EDX
    //         004684bd     PUSH       EAX
    //         004684be     MOV        this,ESI
    //         004684c0     CALL       TPanel::get_string                               int get_string(TPanel * this, int param_1, ch
    //                              Panel_ez.cpp:1036 (95)
    //         004684c5     MOV        EAX,dword ptr [ESP + param_11]
    //         004684cc     MOV        this,dword ptr [ESP + param_10]
    //         004684d3     PUSH       EAX
    //         004684d4     MOV        EAX,dword ptr [ESP + param_9]
    //         004684db     PUSH       this
    //         004684dc     MOV        this,dword ptr [ESP + param_8]
    //         004684e3     PUSH       EAX
    //         004684e4     MOV        EAX,dword ptr [ESP + param_7]
    //         004684eb     PUSH       this
    //         004684ec     MOV        this,dword ptr [ESP + param_6]
    //         004684f3     MOV        EDX,dword ptr [ESI]
    //         004684f5     PUSH       EAX
    //         004684f6     MOV        EAX,dword ptr [ESP + param_5]
    //         004684fd     PUSH       this
    //         004684fe     PUSH       EAX
    //         004684ff     LEA        this=>text2[4],[ESP + 0x20]
    //         00468503     LEA        EAX=>text1[4],[ESP + 0x98]
    //         0046850a     PUSH       this
    //         0046850b     MOV        this,dword ptr [ESP + param_2]
    //         00468512     PUSH       EAX
    //         00468513     MOV        EAX,dword ptr [ESP + param_1]
    //         0046851a     PUSH       this
    //         0046851b     PUSH       EAX
    //         0046851c     MOV        this,ESI
    //         0046851e     CALL       dword ptr [EDX + 0xec]
    //                              Panel_ez.cpp:1037 (10)
    //         00468524     POP        ESI
    //         00468525     ADD        ESP,0xf0
    //         0046852b     RET        0x2c
}

// Offset: 0x00468530
int TRIBE_Screen_Sed_Open::create_button(TPanel* param_1, TButtonPanel** param_2, char* param_3, char* param_4, long param_5, long param_6, long param_7, long param_8, long param_9, long param_10, long param_11) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * protected: virtual int __thiscall TEasy_Panel::create_button(class TPanel *,class TButtonPanel * *... *
    //                              *********************************************************************************************************
    //                              int __thiscall create_button(TEasy_Panel * this, TPanel * param_1, T
    //              int               EAX:4          <RETURN>
    //              TEasy_Panel *     ECX:4 (auto)   this
    //              TPanel *          Stack[0x4]:4   param_1                   XREF[1]:     0046860b(R)  
    //              TButtonPanel *    Stack[0x8]:4   param_2                   XREF[1]:     004685c4(R)  
    //              char *            Stack[0xc]:4   param_3                   XREF[1]:     00468661(R)  
    //              char *            Stack[0x10]:4  param_4                   XREF[1]:     0046866f(R)  
    //              long              Stack[0x14]:4  param_5                   XREF[3]:     00468548(R), 00468585(W), 00468606(R)  
    //              long              Stack[0x18]:4  param_6                   XREF[2]:     0046857b(R), 004685a9(W)  
    //              long              Stack[0x1c]:4  param_7                   XREF[1]:     00468589(R)  
    //              long              Stack[0x20]:4  param_8                   XREF[1]:     00468595(R)  
    //              long              Stack[0x24]:4  param_9                   XREF[1]:     0046863c(R)  
    //              long              Stack[0x28]:4  param_10                  XREF[2]:     004685e8(R), 00468630(R)  
    //              long              Stack[0x2c]:4  param_11                  XREF[1]:     00468602(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     004685af(W), 004685c8(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     0046873f(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[2]:     00468577(W), 00468612(R)  
    //              long              Stack[-0x14]:4 ideal_x                   XREF[2]:     00468557(W), 004685fe(R)  
    //              TDigital *        Stack[-0x18]:4 sound
    //                               ?create_button@TEasy_Panel@@MAEHPAVTPanel@@PAPAVTButtonPane  XREF[51]:    TRIBE_Screen_Main_Menu:0049e7ad(c)
    //                               TEasy_Panel::create_button                                                TribeMPSetupScreen:004a0555(c), 
    //                                                                                                         TribeMPSetupScreen:004a0a09(c), 
    //                                                                                                         TribeMPSetupScreen:004a0b09(c), 
    //                                                                                                         create_button:004a8868(c), 
    //                                                                                                         TRIBE_Screen_Sed_Menu:004b2fee(c), 
    //                                                                                                         TribeSPMenuScreen:004b6ab2(c), 
    //                                                                                                         0056f6fc(*), 0056f83c(*), 
    //                                                                                                         0056f984(*), 0056fab4(*), 
    //                                                                                                         0056fbe4(*), 0056fd1c(*), 
    //                                                                                                         0056fe4c(*), 0056ff7c(*), 
    //                                                                                                         005700ac(*), 005701dc(*), 
    //                                                                                                         00570e04(*), 0057119c(*), 
    //                                                                                                         005719fc(*), [more]
    //                              Panel_ez.cpp:1043 (24)
    //         00468530     PUSH       -0x1
    //         00468532     PUSH       FUN_0055df8b
    //         00468537     MOV        EAX,FS:[0x0]
    //         0046853d     PUSH       EAX
    //         0046853e     MOV        dword ptr FS:[0x0],ESP
    //         00468545     SUB        ESP,0x8
    //                              Panel_ez.cpp:1046 (10)
    //         00468548     MOV        EAX,dword ptr [ESP + param_5]
    //         0046854c     PUSH       EBX
    //         0046854d     PUSH       EBP
    //         0046854e     PUSH       ESI
    //         0046854f     MOV        ESI,this
    //         00468551     PUSH       EDI
    //                              Panel_ez.cpp:1052 (126)
    //         00468552     PUSH       0x2b8
    //         00468557     MOV        dword ptr [ESP + ideal_x],0x0
    //         0046855f     MOV        this,dword ptr [ESI + 0x14]
    //         00468562     MOV        EDI,dword ptr [ESI + 0xf4]
    //         00468568     IMUL       EAX,this
    //         0046856b     CDQ
    //         0046856c     IDIV       EDI
    //         0046856e     MOV        EBX,dword ptr [ESI + 0x18]
    //         00468571     MOV        EBP,dword ptr [ESI + 0xf8]
    //         00468577     MOV        dword ptr [ESP + local_10],EAX
    //         0046857b     MOV        EAX,dword ptr [ESP + param_6]
    //         0046857f     IMUL       EAX,EBX
    //         00468582     CDQ
    //         00468583     IDIV       EBP
    //         00468585     MOV        dword ptr [ESP + param_5],EAX
    //         00468589     MOV        EAX,dword ptr [ESP + param_7]
    //         0046858d     IMUL       EAX,this
    //         00468590     CDQ
    //         00468591     IDIV       EDI
    //         00468593     MOV        EDI,EAX
    //         00468595     MOV        EAX,dword ptr [ESP + param_8]
    //         00468599     IMUL       EAX,EBX
    //         0046859c     CDQ
    //         0046859d     IDIV       EBP
    //         0046859f     MOV        EBP,EAX
    //         004685a1     CALL       operator_new                                     void * operator_new(uint param_1)
    //         004685a6     ADD        ESP,0x4
    //         004685a9     MOV        dword ptr [ESP + param_6],EAX
    //         004685ad     TEST       EAX,EAX
    //         004685af     MOV        dword ptr [ESP + local_4],0x0
    //         004685b7     JZ         LAB_004685c2
    //         004685b9     MOV        this,EAX
    //         004685bb     CALL       TButtonPanel::TButtonPanel                       undefined TButtonPanel(TButtonPanel * this)
    //         004685c0     JMP        LAB_004685c4
    //                               LAB_004685c2                                                 XREF[1]:     004685b7(j)  
    //         004685c2     XOR        EAX,EAX
    //                               LAB_004685c4                                                 XREF[1]:     004685c0(j)  
    //         004685c4     MOV        EBX,dword ptr [ESP + param_2]
    //         004685c8     MOV        dword ptr [ESP + local_4],0xffffffff
    //                              Panel_ez.cpp:1053 (24)
    //         004685d0     TEST       EAX,EAX
    //         004685d2     MOV        dword ptr [EBX],EAX
    //         004685d4     JZ         LAB_00468733
    //         004685da     MOV        this,dword ptr [EAX + 0xd8]
    //         004685e0     TEST       this,this
    //         004685e2     JNZ        LAB_00468733
    //                              Panel_ez.cpp:1059 (8)
    //         004685e8     MOV        EAX,dword ptr [ESP + param_10]
    //         004685ec     TEST       EAX,EAX
    //         004685ee     JL         LAB_004685fe
    //                              Panel_ez.cpp:1060 (18)
    //         004685f0     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004685f6     PUSH       EAX
    //         004685f7     CALL       RGE_Base_Game::get_sound                         TDigital * get_sound(RGE_Base_Game * this, in
    //         004685fc     JMP        LAB_00468602
    //                               LAB_004685fe                                                 XREF[1]:     004685ee(j)  
    //         004685fe     MOV        EAX,dword ptr [ESP + ideal_x]
    //                               LAB_00468602                                                 XREF[1]:     004685fc(j)  
    //                              Panel_ez.cpp:1063 (40)
    //         00468602     MOV        this,dword ptr [ESP + param_11]
    //         00468606     MOV        EDX,dword ptr [ESP + param_5]
    //         0046860a     PUSH       this
    //         0046860b     MOV        this,dword ptr [ESP + param_1]
    //         0046860f     PUSH       0x1
    //         00468611     PUSH       EAX
    //         00468612     MOV        EAX,dword ptr [ESP + local_10]
    //         00468616     PUSH       0x3
    //         00468618     PUSH       EBP
    //         00468619     PUSH       EDI
    //         0046861a     PUSH       EDX
    //         0046861b     MOV        EDX,dword ptr [ESI + 0x20]
    //         0046861e     PUSH       EAX
    //         0046861f     PUSH       this
    //         00468620     MOV        this,dword ptr [EBX]
    //         00468622     PUSH       EDX
    //         00468623     CALL       TButtonPanel::setup                              long setup(TButtonPanel * this, TDrawArea * p
    //         00468628     TEST       EAX,EAX
    //                              Panel_ez.cpp:1066 (6)
    //         0046862a     JZ         LAB_00468733
    //                              Panel_ez.cpp:1069 (12)
    //         00468630     MOV        EAX,dword ptr [ESP + param_10]
    //         00468634     MOV        this,dword ptr [EBX]
    //         00468636     PUSH       EAX
    //         00468637     CALL       TButtonPanel::set_sound_number                   void set_sound_number(TButtonPanel * this, in
    //                              Panel_ez.cpp:1071 (8)
    //         0046863c     MOV        EAX,dword ptr [ESP + param_9]
    //         00468640     TEST       EAX,EAX
    //         00468642     JL         LAB_00468647
    //                              Panel_ez.cpp:1072 (1)
    //         00468644     PUSH       EAX
    //                              Panel_ez.cpp:1073 (2)
    //         00468645     JMP        LAB_00468649
    //                               LAB_00468647                                                 XREF[1]:     00468642(j)  
    //                              Panel_ez.cpp:1074 (13)
    //         00468647     PUSH       0xa
    //                               LAB_00468649                                                 XREF[1]:     00468645(j)  
    //         00468649     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0046864f     CALL       RGE_Base_Game::get_font                          RGE_Font * get_font(RGE_Base_Game * this, int
    //                              Panel_ez.cpp:1076 (27)
    //         00468654     MOV        this,dword ptr [EAX + 0x8]
    //         00468657     MOV        EDX,dword ptr [EAX + 0x4]
    //         0046865a     MOV        EAX,dword ptr [EAX]
    //         0046865c     PUSH       -0x1
    //         0046865e     PUSH       -0x1
    //         00468660     PUSH       this
    //         00468661     MOV        this,dword ptr [ESP + param_3]
    //         00468665     PUSH       EDX
    //         00468666     PUSH       EAX
    //         00468667     PUSH       this
    //         00468668     MOV        this,dword ptr [EBX]
    //         0046866a     CALL       TButtonPanel::set_text_info                      void set_text_info(TButtonPanel * this, char 
    //                              Panel_ez.cpp:1077 (8)
    //         0046866f     MOV        EAX,dword ptr [ESP + param_4]
    //         00468673     TEST       EAX,EAX
    //         00468675     JZ         LAB_00468681
    //                              Panel_ez.cpp:1078 (10)
    //         00468677     MOV        this,dword ptr [EBX]
    //         00468679     PUSH       EAX
    //         0046867a     PUSH       0x1
    //         0046867c     CALL       TButtonPanel::set_text                           void set_text(TButtonPanel * this, short para
    //                               LAB_00468681                                                 XREF[1]:     00468675(j)  
    //                              Panel_ez.cpp:1080 (10)
    //         00468681     MOV        EAX,dword ptr [ESI + 0x31c]
    //         00468687     TEST       EAX,EAX
    //         00468689     JZ         LAB_004686ca
    //                              Panel_ez.cpp:1081 (63)
    //         0046868b     XOR        EDX,EDX
    //         0046868d     XOR        EAX,EAX
    //         0046868f     MOV        DL,byte ptr [ESI + 0x325]
    //         00468695     MOV        AL,byte ptr [ESI + 0x324]
    //         0046869b     XOR        this,this
    //         0046869d     PUSH       EDX
    //         0046869e     MOV        this,byte ptr [ESI + 0x323]
    //         004686a4     PUSH       EAX
    //         004686a5     XOR        EDX,EDX
    //         004686a7     PUSH       this
    //         004686a8     MOV        DL,byte ptr [ESI + 0x322]
    //         004686ae     XOR        EAX,EAX
    //         004686b0     MOV        AL,byte ptr [ESI + 0x321]
    //         004686b6     XOR        this,this
    //         004686b8     MOV        this,byte ptr [ESI + 0x320]
    //         004686be     PUSH       EDX
    //         004686bf     PUSH       EAX
    //         004686c0     PUSH       this
    //         004686c1     MOV        this,dword ptr [EBX]
    //         004686c3     PUSH       0x4
    //         004686c5     CALL       TButtonPanel::set_bevel_info                     void set_bevel_info(TButtonPanel * this, int 
    //                               LAB_004686ca                                                 XREF[1]:     00468689(j)  
    //                              Panel_ez.cpp:1083 (2)
    //         004686ca     XOR        EDI,EDI
    //                               LAB_004686cc                                                 XREF[1]:     004686fc(j)  
    //                              Panel_ez.cpp:1085 (22)
    //         004686cc     MOV        EDX,dword ptr [ESI + 0x32c]
    //         004686d2     MOV        EAX,dword ptr [ESI + 0x328]
    //         004686d8     MOV        this,dword ptr [EBX]
    //         004686da     PUSH       EDX
    //         004686db     PUSH       EAX
    //         004686dc     PUSH       EDI
    //         004686dd     CALL       TButtonPanel::set_text_color                     void set_text_color(TButtonPanel * this, int 
    //                              Panel_ez.cpp:1086 (28)
    //         004686e2     MOV        this,dword ptr [ESI + 0x334]
    //         004686e8     MOV        EDX,dword ptr [ESI + 0x330]
    //         004686ee     PUSH       this
    //         004686ef     MOV        this,dword ptr [EBX]
    //         004686f1     PUSH       EDX
    //         004686f2     PUSH       EDI
    //         004686f3     CALL       TButtonPanel::set_highlight_text_color           void set_highlight_text_color(TButtonPanel * 
    //         004686f8     INC        EDI
    //         004686f9     CMP        EDI,0x9
    //         004686fc     JL         LAB_004686cc
    //                              Panel_ez.cpp:1089 (23)
    //         004686fe     MOV        EAX,dword ptr [ESI + 0x33c]
    //         00468704     MOV        this,dword ptr [ESI + 0x338]
    //         0046870a     PUSH       EAX
    //         0046870b     PUSH       this
    //         0046870c     MOV        this,dword ptr [EBX]
    //         0046870e     PUSH       0x1
    //         00468710     CALL       TButtonPanel::set_text_color                     void set_text_color(TButtonPanel * this, int 
    //                              Panel_ez.cpp:1090 (23)
    //         00468715     MOV        EDX,dword ptr [ESI + 0x334]
    //         0046871b     MOV        EAX,dword ptr [ESI + 0x330]
    //         00468721     MOV        this,dword ptr [EBX]
    //         00468723     PUSH       EDX
    //         00468724     PUSH       EAX
    //         00468725     PUSH       0x1
    //         00468727     CALL       TButtonPanel::set_highlight_text_color           void set_highlight_text_color(TButtonPanel * 
    //                              Panel_ez.cpp:1092 (7)
    //         0046872c     MOV        EAX,0x1
    //         00468731     JMP        LAB_0046873f
    //                               LAB_00468733                                                 XREF[3]:     004685d4(j), 004685e2(j), 
    //                                                                                                         0046862a(j)  
    //                              Panel_ez.cpp:1055 (10)
    //         00468733     MOV        dword ptr [ESI + 0xd8],0x1
    //                              Panel_ez.cpp:1056 (2)
    //         0046873d     XOR        EAX,EAX
    //                               LAB_0046873f                                                 XREF[1]:     00468731(j)  
    //                              Panel_ez.cpp:1093 (21)
    //         0046873f     MOV        this,dword ptr [ESP + local_c]
    //         00468743     POP        EDI
    //         00468744     POP        ESI
    //         00468745     POP        EBP
    //         00468746     MOV        dword ptr FS:[0x0],this
    //         0046874d     POP        EBX
    //         0046874e     ADD        ESP,0x14
    //         00468751     RET        0x2c
}

// Offset: 0x00468760
int TRIBE_Screen_Sed_Open::create_check_box(TPanel* param_1, TButtonPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * protected: virtual int __thiscall TEasy_Panel::create_check_box(class TPanel *,class TButtonPanel ... *
    //                              *********************************************************************************************************
    //                              int __thiscall create_check_box(TEasy_Panel * this, TPanel * param_1
    //              int               EAX:4          <RETURN>
    //              TEasy_Panel *     ECX:4 (auto)   this
    //              TPanel *          Stack[0x4]:4   param_1                   XREF[1]:     0046884c(R)  
    //              TButtonPanel *    Stack[0x8]:4   param_2                   XREF[1]:     004687f6(R)  
    //              long              Stack[0xc]:4   param_3                   XREF[3]:     00468778(R), 004687c3(W), 00468838(R)  
    //              long              Stack[0x10]:4  param_4                   XREF[3]:     004687ab(R), 004687b5(W), 00468844(R)  
    //              long              Stack[0x14]:4  param_5                   XREF[2]:     004687b9(R), 004687db(W)  
    //              long              Stack[0x18]:4  param_6                   XREF[1]:     004687c7(R)  
    //              long              Stack[0x1c]:4  param_7                   XREF[1]:     0046881a(R)  
    //              long              Stack[0x20]:4  param_8                   XREF[1]:     00468834(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     004687e1(W), 004687fa(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     004689a7(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[2]:     004687a7(W), 0046883d(R)  
    //              long              Stack[-0x14]:4 ideal_x                   XREF[2]:     00468787(W), 00468830(R)  
    //              TDigital *        Stack[-0x18]:4 sound
    //                               ?create_check_box@TEasy_Panel@@MAEHPAVTPanel@@PAPAVTButtonP  XREF[53]:    TribeDiplomacyDialog:0043d223(c), 
    //                               TEasy_Panel::create_check_box                                             TribeSendMessageDialog:00440a9d(c)
    //                                                                                                         TribeMPSetupScreen:004a0a9b(c), 
    //                                                                                                         TribeMPSetupScreen:004a0bd3(c), 
    //                                                                                                         create_check_box:004b2dea(c), 
    //                                                                                                         TribeGameSettingsScreen:004b528d(c
    //                                                                                                         TribeGameSettingsScreen:004b52f6(c
    //                                                                                                         TribeGameSettingsScreen:004b5362(c
    //                                                                                                         TribeGameSettingsScreen:004b53dd(c
    //                                                                                                         0056f700(*), 0056f840(*), 
    //                                                                                                         0056f988(*), 0056fab8(*), 
    //                                                                                                         0056fbe8(*), 0056fd20(*), 
    //                                                                                                         0056fe50(*), 0056ff80(*), 
    //                                                                                                         005700b0(*), 005701e0(*), 
    //                                                                                                         00570e08(*), [more]
    //                              Panel_ez.cpp:1099 (24)
    //         00468760     PUSH       -0x1
    //         00468762     PUSH       FUN_0055dfab
    //         00468767     MOV        EAX,FS:[0x0]
    //         0046876d     PUSH       EAX
    //         0046876e     MOV        dword ptr FS:[0x0],ESP
    //         00468775     SUB        ESP,0x8
    //                              Panel_ez.cpp:1102 (10)
    //         00468778     MOV        EAX,dword ptr [ESP + param_3]
    //         0046877c     PUSH       EBX
    //         0046877d     PUSH       EBP
    //         0046877e     PUSH       ESI
    //         0046877f     MOV        ESI,this
    //         00468781     PUSH       EDI
    //                              Panel_ez.cpp:1107 (128)
    //         00468782     PUSH       0x2b8
    //         00468787     MOV        dword ptr [ESP + ideal_x],0x0
    //         0046878f     MOV        this,dword ptr [ESI + 0x14]
    //         00468792     MOV        EDI,dword ptr [ESI + 0xf4]
    //         00468798     IMUL       EAX,this
    //         0046879b     CDQ
    //         0046879c     IDIV       EDI
    //         0046879e     MOV        EBX,dword ptr [ESI + 0x18]
    //         004687a1     MOV        EBP,dword ptr [ESI + 0xf8]
    //         004687a7     MOV        dword ptr [ESP + local_10],EAX
    //         004687ab     MOV        EAX,dword ptr [ESP + param_4]
    //         004687af     IMUL       EAX,EBX
    //         004687b2     CDQ
    //         004687b3     IDIV       EBP
    //         004687b5     MOV        dword ptr [ESP + param_4],EAX
    //         004687b9     MOV        EAX,dword ptr [ESP + param_5]
    //         004687bd     IMUL       EAX,this
    //         004687c0     CDQ
    //         004687c1     IDIV       EDI
    //         004687c3     MOV        dword ptr [ESP + param_3],EAX
    //         004687c7     MOV        EAX,dword ptr [ESP + param_6]
    //         004687cb     IMUL       EAX,EBX
    //         004687ce     CDQ
    //         004687cf     IDIV       EBP
    //         004687d1     MOV        EBX,EAX
    //         004687d3     CALL       operator_new                                     void * operator_new(uint param_1)
    //         004687d8     ADD        ESP,0x4
    //         004687db     MOV        dword ptr [ESP + param_5],EAX
    //         004687df     TEST       EAX,EAX
    //         004687e1     MOV        dword ptr [ESP + local_4],0x0
    //         004687e9     JZ         LAB_004687f4
    //         004687eb     MOV        this,EAX
    //         004687ed     CALL       TButtonPanel::TButtonPanel                       undefined TButtonPanel(TButtonPanel * this)
    //         004687f2     JMP        LAB_004687f6
    //                               LAB_004687f4                                                 XREF[1]:     004687e9(j)  
    //         004687f4     XOR        EAX,EAX
    //                               LAB_004687f6                                                 XREF[1]:     004687f2(j)  
    //         004687f6     MOV        EDI,dword ptr [ESP + param_2]
    //         004687fa     MOV        dword ptr [ESP + local_4],0xffffffff
    //                              Panel_ez.cpp:1108 (24)
    //         00468802     TEST       EAX,EAX
    //         00468804     MOV        dword ptr [EDI],EAX
    //         00468806     JZ         LAB_0046899b
    //         0046880c     MOV        this,dword ptr [EAX + 0xd8]
    //         00468812     TEST       this,this
    //         00468814     JNZ        LAB_0046899b
    //                              Panel_ez.cpp:1114 (8)
    //         0046881a     MOV        EBP,dword ptr [ESP + param_7]
    //         0046881e     TEST       EBP,EBP
    //         00468820     JL         LAB_00468830
    //                              Panel_ez.cpp:1115 (18)
    //         00468822     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         00468828     PUSH       EBP
    //         00468829     CALL       RGE_Base_Game::get_sound                         TDigital * get_sound(RGE_Base_Game * this, in
    //         0046882e     JMP        LAB_00468834
    //                               LAB_00468830                                                 XREF[1]:     00468820(j)  
    //         00468830     MOV        EAX,dword ptr [ESP + ideal_x]
    //                               LAB_00468834                                                 XREF[1]:     0046882e(j)  
    //                              Panel_ez.cpp:1118 (44)
    //         00468834     MOV        this,dword ptr [ESP + param_8]
    //         00468838     MOV        EDX,dword ptr [ESP + param_3]
    //         0046883c     PUSH       this
    //         0046883d     MOV        this,dword ptr [ESP + local_10]
    //         00468841     PUSH       0x1
    //         00468843     PUSH       EAX
    //         00468844     MOV        EAX,dword ptr [ESP + param_4]
    //         00468848     PUSH       0x6
    //         0046884a     PUSH       EBX
    //         0046884b     PUSH       EDX
    //         0046884c     MOV        EDX,dword ptr [ESP + param_1]
    //         00468850     PUSH       EAX
    //         00468851     MOV        EAX,dword ptr [ESI + 0x20]
    //         00468854     PUSH       this
    //         00468855     MOV        this,dword ptr [EDI]
    //         00468857     PUSH       EDX
    //         00468858     PUSH       EAX
    //         00468859     CALL       TButtonPanel::setup                              long setup(TButtonPanel * this, TDrawArea * p
    //         0046885e     TEST       EAX,EAX
    //                              Panel_ez.cpp:1121 (6)
    //         00468860     JZ         LAB_0046899b
    //                              Panel_ez.cpp:1124 (8)
    //         00468866     MOV        this,dword ptr [EDI]
    //         00468868     PUSH       EBP
    //         00468869     CALL       TButtonPanel::set_sound_number                   void set_sound_number(TButtonPanel * this, in
    //                              Panel_ez.cpp:1126 (9)
    //         0046886e     MOV        this,dword ptr [EDI]
    //         00468870     PUSH       0x2
    //         00468872     CALL       TButtonPanel::set_state_info                     void set_state_info(TButtonPanel * this, shor
    //                              Panel_ez.cpp:1128 (10)
    //         00468877     MOV        EAX,dword ptr [ESI + 0x448]
    //         0046887d     TEST       EAX,EAX
    //         0046887f     JZ         LAB_004688b0
    //                              Panel_ez.cpp:1130 (9)
    //         00468881     MOV        this,dword ptr [EDI]
    //         00468883     PUSH       0x6
    //         00468885     CALL       TButtonPanel::setDrawType                        void setDrawType(TButtonPanel * this, DrawTyp
    //                              Panel_ez.cpp:1131 (18)
    //         0046888a     MOV        this,dword ptr [ESI + 0x448]
    //         00468890     PUSH       0x0
    //         00468892     PUSH       this
    //         00468893     MOV        this,dword ptr [EDI]
    //         00468895     PUSH       0x0
    //         00468897     CALL       TButtonPanel::set_picture                        void set_picture(TButtonPanel * this, short p
    //                              Panel_ez.cpp:1132 (18)
    //         0046889c     MOV        EDX,dword ptr [ESI + 0x448]
    //         004688a2     MOV        this,dword ptr [EDI]
    //         004688a4     PUSH       0x2
    //         004688a6     PUSH       EDX
    //         004688a7     PUSH       0x1
    //         004688a9     CALL       TButtonPanel::set_picture                        void set_picture(TButtonPanel * this, short p
    //                              Panel_ez.cpp:1134 (2)
    //         004688ae     JMP        LAB_004688ef
    //                               LAB_004688b0                                                 XREF[1]:     0046887f(j)  
    //                              Panel_ez.cpp:1136 (13)
    //         004688b0     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004688b6     PUSH       0x0
    //         004688b8     CALL       RGE_Base_Game::get_font                          RGE_Font * get_font(RGE_Base_Game * this, int
    //                              Panel_ez.cpp:1137 (27)
    //         004688bd     MOV        this,dword ptr [EAX + 0x8]
    //         004688c0     MOV        EDX,dword ptr [EAX + 0x4]
    //         004688c3     MOV        EAX,dword ptr [EAX]
    //         004688c5     PUSH       -0x1
    //         004688c7     PUSH       -0x1
    //         004688c9     PUSH       this
    //         004688ca     MOV        this,dword ptr [EDI]
    //         004688cc     PUSH       EDX
    //         004688cd     PUSH       EAX
    //         004688ce     PUSH       s__                                              = 20h
    //         004688d3     CALL       TButtonPanel::set_text_info                      void set_text_info(TButtonPanel * this, char 
    //                              Panel_ez.cpp:1138 (14)
    //         004688d8     MOV        this,dword ptr [EDI]
    //         004688da     PUSH       s_X                                              = "X"
    //         004688df     PUSH       0x1
    //         004688e1     CALL       TButtonPanel::set_text                           void set_text(TButtonPanel * this, short para
    //                              Panel_ez.cpp:1139 (9)
    //         004688e6     MOV        this,dword ptr [EDI]
    //         004688e8     PUSH       0x3
    //         004688ea     CALL       TButtonPanel::setDrawType                        void setDrawType(TButtonPanel * this, DrawTyp
    //                               LAB_004688ef                                                 XREF[1]:     004688ae(j)  
    //                              Panel_ez.cpp:1142 (10)
    //         004688ef     MOV        EAX,dword ptr [ESI + 0x31c]
    //         004688f5     TEST       EAX,EAX
    //         004688f7     JZ         LAB_00468938
    //                              Panel_ez.cpp:1143 (63)
    //         004688f9     XOR        this,this
    //         004688fb     XOR        EDX,EDX
    //         004688fd     MOV        this,byte ptr [ESI + 0x325]
    //         00468903     MOV        DL,byte ptr [ESI + 0x324]
    //         00468909     XOR        EAX,EAX
    //         0046890b     PUSH       this
    //         0046890c     MOV        AL,byte ptr [ESI + 0x323]
    //         00468912     PUSH       EDX
    //         00468913     XOR        this,this
    //         00468915     PUSH       EAX
    //         00468916     MOV        this,byte ptr [ESI + 0x322]
    //         0046891c     XOR        EDX,EDX
    //         0046891e     MOV        DL,byte ptr [ESI + 0x321]
    //         00468924     XOR        EAX,EAX
    //         00468926     MOV        AL,byte ptr [ESI + 0x320]
    //         0046892c     PUSH       this
    //         0046892d     MOV        this,dword ptr [EDI]
    //         0046892f     PUSH       EDX
    //         00468930     PUSH       EAX
    //         00468931     PUSH       0x4
    //         00468933     CALL       TButtonPanel::set_bevel_info                     void set_bevel_info(TButtonPanel * this, int 
    //                               LAB_00468938                                                 XREF[1]:     004688f7(j)  
    //                              Panel_ez.cpp:1145 (23)
    //         00468938     MOV        this,dword ptr [ESI + 0x32c]
    //         0046893e     MOV        EDX,dword ptr [ESI + 0x328]
    //         00468944     PUSH       this
    //         00468945     MOV        this,dword ptr [EDI]
    //         00468947     PUSH       EDX
    //         00468948     PUSH       0x0
    //         0046894a     CALL       TButtonPanel::set_text_color                     void set_text_color(TButtonPanel * this, int 
    //                              Panel_ez.cpp:1146 (23)
    //         0046894f     MOV        EAX,dword ptr [ESI + 0x334]
    //         00468955     MOV        this,dword ptr [ESI + 0x330]
    //         0046895b     PUSH       EAX
    //         0046895c     PUSH       this
    //         0046895d     MOV        this,dword ptr [EDI]
    //         0046895f     PUSH       0x0
    //         00468961     CALL       TButtonPanel::set_highlight_text_color           void set_highlight_text_color(TButtonPanel * 
    //                              Panel_ez.cpp:1148 (23)
    //         00468966     MOV        EDX,dword ptr [ESI + 0x33c]
    //         0046896c     MOV        EAX,dword ptr [ESI + 0x338]
    //         00468972     MOV        this,dword ptr [EDI]
    //         00468974     PUSH       EDX
    //         00468975     PUSH       EAX
    //         00468976     PUSH       0x1
    //         00468978     CALL       TButtonPanel::set_text_color                     void set_text_color(TButtonPanel * this, int 
    //                              Panel_ez.cpp:1149 (23)
    //         0046897d     MOV        this,dword ptr [ESI + 0x334]
    //         00468983     MOV        EDX,dword ptr [ESI + 0x330]
    //         00468989     PUSH       this
    //         0046898a     MOV        this,dword ptr [EDI]
    //         0046898c     PUSH       EDX
    //         0046898d     PUSH       0x1
    //         0046898f     CALL       TButtonPanel::set_highlight_text_color           void set_highlight_text_color(TButtonPanel * 
    //                              Panel_ez.cpp:1151 (7)
    //         00468994     MOV        EAX,0x1
    //         00468999     JMP        LAB_004689a7
    //                               LAB_0046899b                                                 XREF[3]:     00468806(j), 00468814(j), 
    //                                                                                                         00468860(j)  
    //                              Panel_ez.cpp:1110 (10)
    //         0046899b     MOV        dword ptr [ESI + 0xd8],0x1
    //                              Panel_ez.cpp:1111 (2)
    //         004689a5     XOR        EAX,EAX
    //                               LAB_004689a7                                                 XREF[1]:     00468999(j)  
    //                              Panel_ez.cpp:1152 (21)
    //         004689a7     MOV        this,dword ptr [ESP + local_c]
    //         004689ab     POP        EDI
    //         004689ac     POP        ESI
    //         004689ad     POP        EBP
    //         004689ae     MOV        dword ptr FS:[0x0],this
    //         004689b5     POP        EBX
    //         004689b6     ADD        ESP,0x14
    //         004689b9     RET        0x20
}

// Offset: 0x004689C0
int TRIBE_Screen_Sed_Open::create_radio_button(TPanel* param_1, TButtonPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * protected: virtual int __thiscall TEasy_Panel::create_radio_button(class TPanel *,class TButtonPan... *
    //                              *********************************************************************************************************
    //                              int __thiscall create_radio_button(TEasy_Panel * this, TPanel * para
    //              int               EAX:4          <RETURN>
    //              TEasy_Panel *     ECX:4 (auto)   this
    //              TPanel *          Stack[0x4]:4   param_1                   XREF[1]:     00468aac(R)  
    //              TButtonPanel *    Stack[0x8]:4   param_2                   XREF[1]:     00468a56(R)  
    //              long              Stack[0xc]:4   param_3                   XREF[3]:     004689d8(R), 00468a23(W), 00468a98(R)  
    //              long              Stack[0x10]:4  param_4                   XREF[3]:     00468a0b(R), 00468a15(W), 00468aa4(R)  
    //              long              Stack[0x14]:4  param_5                   XREF[2]:     00468a19(R), 00468a3b(W)  
    //              long              Stack[0x18]:4  param_6                   XREF[1]:     00468a27(R)  
    //              long              Stack[0x1c]:4  param_7                   XREF[1]:     00468a7a(R)  
    //              long              Stack[0x20]:4  param_8                   XREF[1]:     00468a94(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     00468a41(W), 00468a5a(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     00468bfe(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[2]:     00468a07(W), 00468a9d(R)  
    //              long              Stack[-0x14]:4 ideal_x                   XREF[2]:     004689e7(W), 00468a90(R)  
    //              TDigital *        Stack[-0x18]:4 sound
    //                               ?create_radio_button@TEasy_Panel@@MAEHPAVTPanel@@PAPAVTButt  XREF[57]:    TribeConfigDialog:0043b79f(c), 
    //                               TEasy_Panel::create_radio_button                                          TribeConfigDialog:0043bbd8(c), 
    //                                                                                                         TribeConfigDialog:0043bd6b(c), 
    //                                                                                                         TribeConfigDialog:0043be88(c), 
    //                                                                                                         TribeConfigDialog:0043bf5c(c), 
    //                                                                                                         TribeDiplomacyDialog:0043cf31(c), 
    //                                                                                                         TribeDiplomacyDialog:0043cf69(c), 
    //                                                                                                         TribeDiplomacyDialog:0043cf9a(c), 
    //                                                                                                         TribeSendMessageDialog:00440b8f(c)
    //                                                                                                         TribeSendMessageDialog:00440bb8(c)
    //                                                                                                         TribeSendMessageDialog:00440bde(c)
    //                                                                                                         TribeSendMessageDialog:00440c07(c)
    //                                                                                                         create_radio_button:004b2e7a(c), 
    //                                                                                                         0056f704(*), 0056f844(*), 
    //                                                                                                         0056f98c(*), 0056fabc(*), 
    //                                                                                                         0056fbec(*), 0056fd24(*), 
    //                                                                                                         0056fe54(*), [more]
    //                              Panel_ez.cpp:1158 (24)
    //         004689c0     PUSH       -0x1
    //         004689c2     PUSH       FUN_0055dfcb
    //         004689c7     MOV        EAX,FS:[0x0]
    //         004689cd     PUSH       EAX
    //         004689ce     MOV        dword ptr FS:[0x0],ESP
    //         004689d5     SUB        ESP,0x8
    //                              Panel_ez.cpp:1161 (10)
    //         004689d8     MOV        EAX,dword ptr [ESP + param_3]
    //         004689dc     PUSH       EBX
    //         004689dd     PUSH       EBP
    //         004689de     PUSH       ESI
    //         004689df     MOV        ESI,this
    //         004689e1     PUSH       EDI
    //                              Panel_ez.cpp:1166 (128)
    //         004689e2     PUSH       0x2b8
    //         004689e7     MOV        dword ptr [ESP + ideal_x],0x0
    //         004689ef     MOV        this,dword ptr [ESI + 0x14]
    //         004689f2     MOV        EDI,dword ptr [ESI + 0xf4]
    //         004689f8     IMUL       EAX,this
    //         004689fb     CDQ
    //         004689fc     IDIV       EDI
    //         004689fe     MOV        EBX,dword ptr [ESI + 0x18]
    //         00468a01     MOV        EBP,dword ptr [ESI + 0xf8]
    //         00468a07     MOV        dword ptr [ESP + local_10],EAX
    //         00468a0b     MOV        EAX,dword ptr [ESP + param_4]
    //         00468a0f     IMUL       EAX,EBX
    //         00468a12     CDQ
    //         00468a13     IDIV       EBP
    //         00468a15     MOV        dword ptr [ESP + param_4],EAX
    //         00468a19     MOV        EAX,dword ptr [ESP + param_5]
    //         00468a1d     IMUL       EAX,this
    //         00468a20     CDQ
    //         00468a21     IDIV       EDI
    //         00468a23     MOV        dword ptr [ESP + param_3],EAX
    //         00468a27     MOV        EAX,dword ptr [ESP + param_6]
    //         00468a2b     IMUL       EAX,EBX
    //         00468a2e     CDQ
    //         00468a2f     IDIV       EBP
    //         00468a31     MOV        EBX,EAX
    //         00468a33     CALL       operator_new                                     void * operator_new(uint param_1)
    //         00468a38     ADD        ESP,0x4
    //         00468a3b     MOV        dword ptr [ESP + param_5],EAX
    //         00468a3f     TEST       EAX,EAX
    //         00468a41     MOV        dword ptr [ESP + local_4],0x0
    //         00468a49     JZ         LAB_00468a54
    //         00468a4b     MOV        this,EAX
    //         00468a4d     CALL       TButtonPanel::TButtonPanel                       undefined TButtonPanel(TButtonPanel * this)
    //         00468a52     JMP        LAB_00468a56
    //                               LAB_00468a54                                                 XREF[1]:     00468a49(j)  
    //         00468a54     XOR        EAX,EAX
    //                               LAB_00468a56                                                 XREF[1]:     00468a52(j)  
    //         00468a56     MOV        EDI,dword ptr [ESP + param_2]
    //         00468a5a     MOV        dword ptr [ESP + local_4],0xffffffff
    //                              Panel_ez.cpp:1167 (24)
    //         00468a62     TEST       EAX,EAX
    //         00468a64     MOV        dword ptr [EDI],EAX
    //         00468a66     JZ         LAB_00468bf2
    //         00468a6c     MOV        this,dword ptr [EAX + 0xd8]
    //         00468a72     TEST       this,this
    //         00468a74     JNZ        LAB_00468bf2
    //                              Panel_ez.cpp:1173 (8)
    //         00468a7a     MOV        EBP,dword ptr [ESP + param_7]
    //         00468a7e     TEST       EBP,EBP
    //         00468a80     JL         LAB_00468a90
    //                              Panel_ez.cpp:1174 (18)
    //         00468a82     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         00468a88     PUSH       EBP
    //         00468a89     CALL       RGE_Base_Game::get_sound                         TDigital * get_sound(RGE_Base_Game * this, in
    //         00468a8e     JMP        LAB_00468a94
    //                               LAB_00468a90                                                 XREF[1]:     00468a80(j)  
    //         00468a90     MOV        EAX,dword ptr [ESP + ideal_x]
    //                               LAB_00468a94                                                 XREF[1]:     00468a8e(j)  
    //                              Panel_ez.cpp:1177 (44)
    //         00468a94     MOV        this,dword ptr [ESP + param_8]
    //         00468a98     MOV        EDX,dword ptr [ESP + param_3]
    //         00468a9c     PUSH       this
    //         00468a9d     MOV        this,dword ptr [ESP + local_10]
    //         00468aa1     PUSH       0x1
    //         00468aa3     PUSH       EAX
    //         00468aa4     MOV        EAX,dword ptr [ESP + param_4]
    //         00468aa8     PUSH       0x2
    //         00468aaa     PUSH       EBX
    //         00468aab     PUSH       EDX
    //         00468aac     MOV        EDX,dword ptr [ESP + param_1]
    //         00468ab0     PUSH       EAX
    //         00468ab1     MOV        EAX,dword ptr [ESI + 0x20]
    //         00468ab4     PUSH       this
    //         00468ab5     MOV        this,dword ptr [EDI]
    //         00468ab7     PUSH       EDX
    //         00468ab8     PUSH       EAX
    //         00468ab9     CALL       TButtonPanel::setup                              long setup(TButtonPanel * this, TDrawArea * p
    //         00468abe     TEST       EAX,EAX
    //                              Panel_ez.cpp:1180 (6)
    //         00468ac0     JZ         LAB_00468bf2
    //                              Panel_ez.cpp:1183 (8)
    //         00468ac6     MOV        this,dword ptr [EDI]
    //         00468ac8     PUSH       EBP
    //         00468ac9     CALL       TButtonPanel::set_sound_number                   void set_sound_number(TButtonPanel * this, in
    //                              Panel_ez.cpp:1185 (10)
    //         00468ace     MOV        EAX,dword ptr [ESI + 0x448]
    //         00468ad4     TEST       EAX,EAX
    //         00468ad6     JZ         LAB_00468b07
    //                              Panel_ez.cpp:1187 (9)
    //         00468ad8     MOV        this,dword ptr [EDI]
    //         00468ada     PUSH       0x6
    //         00468adc     CALL       TButtonPanel::setDrawType                        void setDrawType(TButtonPanel * this, DrawTyp
    //                              Panel_ez.cpp:1188 (18)
    //         00468ae1     MOV        this,dword ptr [ESI + 0x448]
    //         00468ae7     PUSH       0x4
    //         00468ae9     PUSH       this
    //         00468aea     MOV        this,dword ptr [EDI]
    //         00468aec     PUSH       0x0
    //         00468aee     CALL       TButtonPanel::set_picture                        void set_picture(TButtonPanel * this, short p
    //                              Panel_ez.cpp:1189 (18)
    //         00468af3     MOV        EDX,dword ptr [ESI + 0x448]
    //         00468af9     MOV        this,dword ptr [EDI]
    //         00468afb     PUSH       0x6
    //         00468afd     PUSH       EDX
    //         00468afe     PUSH       0x1
    //         00468b00     CALL       TButtonPanel::set_picture                        void set_picture(TButtonPanel * this, short p
    //                              Panel_ez.cpp:1191 (2)
    //         00468b05     JMP        LAB_00468b46
    //                               LAB_00468b07                                                 XREF[1]:     00468ad6(j)  
    //                              Panel_ez.cpp:1193 (9)
    //         00468b07     MOV        this,dword ptr [EDI]
    //         00468b09     PUSH       0x3
    //         00468b0b     CALL       TButtonPanel::setDrawType                        void setDrawType(TButtonPanel * this, DrawTyp
    //                              Panel_ez.cpp:1194 (13)
    //         00468b10     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         00468b16     PUSH       0x0
    //         00468b18     CALL       RGE_Base_Game::get_font                          RGE_Font * get_font(RGE_Base_Game * this, int
    //                              Panel_ez.cpp:1195 (27)
    //         00468b1d     MOV        this,dword ptr [EAX + 0x8]
    //         00468b20     MOV        EDX,dword ptr [EAX + 0x4]
    //         00468b23     MOV        EAX,dword ptr [EAX]
    //         00468b25     PUSH       -0x1
    //         00468b27     PUSH       -0x1
    //         00468b29     PUSH       this
    //         00468b2a     MOV        this,dword ptr [EDI]
    //         00468b2c     PUSH       EDX
    //         00468b2d     PUSH       EAX
    //         00468b2e     PUSH       s__                                              = 20h
    //         00468b33     CALL       TButtonPanel::set_text_info                      void set_text_info(TButtonPanel * this, char 
    //                              Panel_ez.cpp:1196 (14)
    //         00468b38     MOV        this,dword ptr [EDI]
    //         00468b3a     PUSH       s_X                                              = "X"
    //         00468b3f     PUSH       0x1
    //         00468b41     CALL       TButtonPanel::set_text                           void set_text(TButtonPanel * this, short para
    //                               LAB_00468b46                                                 XREF[1]:     00468b05(j)  
    //                              Panel_ez.cpp:1199 (10)
    //         00468b46     MOV        EAX,dword ptr [ESI + 0x31c]
    //         00468b4c     TEST       EAX,EAX
    //         00468b4e     JZ         LAB_00468b8f
    //                              Panel_ez.cpp:1200 (63)
    //         00468b50     XOR        this,this
    //         00468b52     XOR        EDX,EDX
    //         00468b54     MOV        this,byte ptr [ESI + 0x325]
    //         00468b5a     MOV        DL,byte ptr [ESI + 0x324]
    //         00468b60     XOR        EAX,EAX
    //         00468b62     PUSH       this
    //         00468b63     MOV        AL,byte ptr [ESI + 0x323]
    //         00468b69     PUSH       EDX
    //         00468b6a     XOR        this,this
    //         00468b6c     PUSH       EAX
    //         00468b6d     MOV        this,byte ptr [ESI + 0x322]
    //         00468b73     XOR        EDX,EDX
    //         00468b75     MOV        DL,byte ptr [ESI + 0x321]
    //         00468b7b     XOR        EAX,EAX
    //         00468b7d     MOV        AL,byte ptr [ESI + 0x320]
    //         00468b83     PUSH       this
    //         00468b84     MOV        this,dword ptr [EDI]
    //         00468b86     PUSH       EDX
    //         00468b87     PUSH       EAX
    //         00468b88     PUSH       0x4
    //         00468b8a     CALL       TButtonPanel::set_bevel_info                     void set_bevel_info(TButtonPanel * this, int 
    //                               LAB_00468b8f                                                 XREF[1]:     00468b4e(j)  
    //                              Panel_ez.cpp:1202 (23)
    //         00468b8f     MOV        this,dword ptr [ESI + 0x32c]
    //         00468b95     MOV        EDX,dword ptr [ESI + 0x328]
    //         00468b9b     PUSH       this
    //         00468b9c     MOV        this,dword ptr [EDI]
    //         00468b9e     PUSH       EDX
    //         00468b9f     PUSH       0x0
    //         00468ba1     CALL       TButtonPanel::set_text_color                     void set_text_color(TButtonPanel * this, int 
    //                              Panel_ez.cpp:1203 (23)
    //         00468ba6     MOV        EAX,dword ptr [ESI + 0x334]
    //         00468bac     MOV        this,dword ptr [ESI + 0x330]
    //         00468bb2     PUSH       EAX
    //         00468bb3     PUSH       this
    //         00468bb4     MOV        this,dword ptr [EDI]
    //         00468bb6     PUSH       0x0
    //         00468bb8     CALL       TButtonPanel::set_highlight_text_color           void set_highlight_text_color(TButtonPanel * 
    //                              Panel_ez.cpp:1205 (23)
    //         00468bbd     MOV        EDX,dword ptr [ESI + 0x33c]
    //         00468bc3     MOV        EAX,dword ptr [ESI + 0x338]
    //         00468bc9     MOV        this,dword ptr [EDI]
    //         00468bcb     PUSH       EDX
    //         00468bcc     PUSH       EAX
    //         00468bcd     PUSH       0x1
    //         00468bcf     CALL       TButtonPanel::set_text_color                     void set_text_color(TButtonPanel * this, int 
    //                              Panel_ez.cpp:1206 (23)
    //         00468bd4     MOV        this,dword ptr [ESI + 0x334]
    //         00468bda     MOV        EDX,dword ptr [ESI + 0x330]
    //         00468be0     PUSH       this
    //         00468be1     MOV        this,dword ptr [EDI]
    //         00468be3     PUSH       EDX
    //         00468be4     PUSH       0x1
    //         00468be6     CALL       TButtonPanel::set_highlight_text_color           void set_highlight_text_color(TButtonPanel * 
    //                              Panel_ez.cpp:1208 (7)
    //         00468beb     MOV        EAX,0x1
    //         00468bf0     JMP        LAB_00468bfe
    //                               LAB_00468bf2                                                 XREF[3]:     00468a66(j), 00468a74(j), 
    //                                                                                                         00468ac0(j)  
    //                              Panel_ez.cpp:1169 (10)
    //         00468bf2     MOV        dword ptr [ESI + 0xd8],0x1
    //                              Panel_ez.cpp:1170 (2)
    //         00468bfc     XOR        EAX,EAX
    //                               LAB_00468bfe                                                 XREF[1]:     00468bf0(j)  
    //                              Panel_ez.cpp:1209 (21)
    //         00468bfe     MOV        this,dword ptr [ESP + local_c]
    //         00468c02     POP        EDI
    //         00468c03     POP        ESI
    //         00468c04     POP        EBP
    //         00468c05     MOV        dword ptr FS:[0x0],this
    //         00468c0c     POP        EBX
    //         00468c0d     ADD        ESP,0x14
    //         00468c10     RET        0x20
}

// Offset: 0x00468C20
int TRIBE_Screen_Sed_Open::create_text(TPanel* param_1, TTextPanel** param_2, int param_3, long param_4, long param_5, long param_6, long param_7, long param_8, int param_9, int param_10, int param_11) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * protected: virtual int __thiscall TEasy_Panel::create_text(class TPanel *,class TTextPanel * *,int... *
    //                              *********************************************************************************************************
    //                              int __thiscall create_text(TEasy_Panel * this, TPanel * param_1, TTe
    //              int               EAX:4          <RETURN>
    //              TEasy_Panel *     ECX:4 (auto)   this
    //              TPanel *          Stack[0x4]:4   param_1                   XREF[1]:     00468c90(R)  
    //              TTextPanel * *    Stack[0x8]:4   param_2                   XREF[1]:     00468c88(R)  
    //              int               Stack[0xc]:4   param_3                   XREF[1]:     00468c2d(R)  
    //              long              Stack[0x10]:4  param_4                   XREF[1]:     00468c7b(R)  
    //              long              Stack[0x14]:4  param_5                   XREF[1]:     00468c73(R)  
    //              long              Stack[0x18]:4  param_6                   XREF[1]:     00468c69(R)  
    //              long              Stack[0x1c]:4  param_7                   XREF[1]:     00468c61(R)  
    //              long              Stack[0x20]:4  param_8                   XREF[1]:     00468c59(R)  
    //              int               Stack[0x24]:4  param_9                   XREF[1]:     00468c51(R)  
    //              int               Stack[0x28]:4  param_10                  XREF[1]:     00468c49(R)  
    //              int               Stack[0x2c]:4  param_11                  XREF[1]:     00468c42(R)  
    //              char[256]         Stack[-0x104   text                      XREF[0,2]:   00468c26(*), 00468c83(*)  
    //                               ?create_text@TEasy_Panel@@MAEHPAVTPanel@@PAPAVTTextPanel@@H  XREF[179]:   TribeAchievementsScreen:0048d810(c
    //                               TEasy_Panel::create_text                                                  TribeAchievementsScreen:0048d834(c
    //                                                                                                         TribeAchievementsScreen:0048d85e(c
    //                                                                                                         TribeAchievementsScreen:0048da3d(c
    //                                                                                                         TribeAchievementsScreen:0048da67(c
    //                                                                                                         TribeAchievementsScreen:0048da8e(c
    //                                                                                                         TribeAchievementsScreen:0048dab5(c
    //                                                                                                         TribeAchievementsScreen:0048dadc(c
    //                                                                                                         TRIBE_Screen_Campaign_Selection:00
    //                                                                                                         TRIBE_Screen_Campaign_Selection:00
    //                                                                                                         TRIBE_Screen_Campaign_Selection:00
    //                                                                                                         TRIBE_Screen_Campaign_Selection:00
    //                                                                                                         TRIBE_Screen_Main_Menu:0049e85a(c)
    //                                                                                                         TRIBE_Screen_Main_Menu:0049e8a2(c)
    //                                                                                                         TRIBE_Screen_Main_Menu:0049e96d(c)
    //                                                                                                         TRIBE_Screen_Main_Menu:0049eb75(c)
    //                                                                                                         TribeSaveGameScreen:004a7365(c), 
    //                                                                                                         create_text:004a8930(c), 
    //                                                                                                         create_all_buttons_etc:004afaa3(c)
    //                                                                                                         TRIBE_Screen_Sed_Open:004b34f8(c), 
    //                                                                                                         [more]
    //                              Panel_ez.cpp:1215 (6)
    //         00468c20     SUB        ESP,0x100
    //                              Panel_ez.cpp:1218 (28)
    //         00468c26     LEA        EAX=>text[4],[ESP]
    //         00468c2a     PUSH       ESI
    //         00468c2b     MOV        ESI,this
    //         00468c2d     MOV        this,dword ptr [ESP + param_3]
    //         00468c34     PUSH       0x100
    //         00468c39     PUSH       EAX
    //         00468c3a     PUSH       this
    //         00468c3b     MOV        this,ESI
    //         00468c3d     CALL       TPanel::get_string                               int get_string(TPanel * this, int param_1, ch
    //                              Panel_ez.cpp:1220 (95)
    //         00468c42     MOV        EAX,dword ptr [ESP + param_11]
    //         00468c49     MOV        this,dword ptr [ESP + param_10]
    //         00468c50     PUSH       EAX
    //         00468c51     MOV        EAX,dword ptr [ESP + param_9]
    //         00468c58     PUSH       this
    //         00468c59     MOV        this,dword ptr [ESP + param_8]
    //         00468c60     PUSH       EAX
    //         00468c61     MOV        EAX,dword ptr [ESP + param_7]
    //         00468c68     PUSH       this
    //         00468c69     MOV        this,dword ptr [ESP + param_6]
    //         00468c70     MOV        EDX,dword ptr [ESI]
    //         00468c72     PUSH       EAX
    //         00468c73     MOV        EAX,dword ptr [ESP + param_5]
    //         00468c7a     PUSH       this
    //         00468c7b     MOV        this,dword ptr [ESP + param_4]
    //         00468c82     PUSH       EAX
    //         00468c83     LEA        EAX=>text[4],[ESP + 0x20]
    //         00468c87     PUSH       this
    //         00468c88     MOV        this,dword ptr [ESP + param_2]
    //         00468c8f     PUSH       EAX
    //         00468c90     MOV        EAX,dword ptr [ESP + param_1]
    //         00468c97     PUSH       this
    //         00468c98     PUSH       EAX
    //         00468c99     MOV        this,ESI
    //         00468c9b     CALL       dword ptr [EDX + 0x100]
    //                              Panel_ez.cpp:1221 (10)
    //         00468ca1     POP        ESI
    //         00468ca2     ADD        ESP,0x100
    //         00468ca8     RET        0x2c
}

// Offset: 0x00468CB0
int TRIBE_Screen_Sed_Open::create_text(TPanel* param_1, TTextPanel** param_2, char* param_3, long param_4, long param_5, long param_6, long param_7, long param_8, int param_9, int param_10, int param_11) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * protected: virtual int __thiscall TEasy_Panel::create_text(class TPanel *,class TTextPanel * *,cha... *
    //                              *********************************************************************************************************
    //                              int __thiscall create_text(TEasy_Panel * this, TPanel * param_1, TTe
    //              int               EAX:4          <RETURN>
    //              TEasy_Panel *     ECX:4 (auto)   this
    //              TPanel *          Stack[0x4]:4   param_1                   XREF[1]:     00468d97(R)  
    //              TTextPanel * *    Stack[0x8]:4   param_2                   XREF[1]:     00468d3a(R)  
    //              char *            Stack[0xc]:4   param_3                   XREF[1]:     00468dee(R)  
    //              long              Stack[0x10]:4  param_4                   XREF[3]:     00468cc6(R), 00468cfb(W), 00468d8d(R)  
    //              long              Stack[0x14]:4  param_5                   XREF[2]:     00468cf1(R), 00468d1f(W)  
    //              long              Stack[0x18]:4  param_6                   XREF[1]:     00468cff(R)  
    //              long              Stack[0x1c]:4  param_7                   XREF[1]:     00468d0b(R)  
    //              long              Stack[0x20]:4  param_8                   XREF[1]:     00468d5e(R)  
    //              int               Stack[0x24]:4  param_9                   XREF[1]:     00468daf(R)  
    //              int               Stack[0x28]:4  param_10                  XREF[1]:     00468db3(R)  
    //              int               Stack[0x2c]:4  param_11                  XREF[1]:     00468de0(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     00468d25(W), 00468d3e(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     00468e38(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[2]:     00468ced(W), 00468d92(R)  
    //              long              Stack[-0x14]:4 ideal_x
    //                               ?create_text@TEasy_Panel@@MAEHPAVTPanel@@PAPAVTTextPanel@@P  XREF[81]:    TribeAchievementsScreen:0048d7de(c
    //                               TEasy_Panel::create_text                                                  TribeAchievementsScreen:0048d8e6(c
    //                                                                                                         TribeAchievementsScreen:0048dc8e(c
    //                                                                                                         TRIBE_Screen_Game:004950f5(c), 
    //                                                                                                         TRIBE_Screen_Main_Menu:0049eb4a(c)
    //                                                                                                         TRIBE_Screen_Main_Error:0049f18d(c
    //                                                                                                         TribeMPSetupScreen:004a0592(c), 
    //                                                                                                         TribeMPSetupScreen:004a0647(c), 
    //                                                                                                         TribeMPSetupScreen:004a0678(c), 
    //                                                                                                         TribeMPSetupScreen:004a06a6(c), 
    //                                                                                                         TribeMPSetupScreen:004a06d4(c), 
    //                                                                                                         TribeMPSetupScreen:004a0733(c), 
    //                                                                                                         TribeMPSetupScreen:004a07e9(c), 
    //                                                                                                         TribeMPSetupScreen:004a081c(c), 
    //                                                                                                         TribeMPSetupScreen:004a0899(c), 
    //                                                                                                         TRIBE_Screen_Wait:004a56d8(c), 
    //                                                                                                         TRIBE_Screen_Wait:004a5752(c), 
    //                                                                                                         TRIBE_Screen_Wait:004a5788(c), 
    //                                                                                                         create_text:004a8980(c), 
    //                                                                                                         TribeSelectScenarioScreen:004b3f55
    //                                                                                                         [more]
    //                              Panel_ez.cpp:1227 (22)
    //         00468cb0     PUSH       -0x1
    //         00468cb2     PUSH       FUN_0055dfeb
    //         00468cb7     MOV        EAX,FS:[0x0]
    //         00468cbd     PUSH       EAX
    //         00468cbe     MOV        dword ptr FS:[0x0],ESP
    //         00468cc5     PUSH       this
    //                              Panel_ez.cpp:1229 (10)
    //         00468cc6     MOV        EAX,dword ptr [ESP + param_4]
    //         00468cca     PUSH       EBX
    //         00468ccb     PUSH       EBP
    //         00468ccc     PUSH       ESI
    //         00468ccd     MOV        ESI,this
    //         00468ccf     PUSH       EDI
    //                              Panel_ez.cpp:1234 (118)
    //         00468cd0     PUSH       0x188
    //         00468cd5     MOV        this,dword ptr [ESI + 0x14]
    //         00468cd8     MOV        EDI,dword ptr [ESI + 0xf4]
    //         00468cde     IMUL       EAX,this
    //         00468ce1     CDQ
    //         00468ce2     IDIV       EDI
    //         00468ce4     MOV        EBX,dword ptr [ESI + 0x18]
    //         00468ce7     MOV        EBP,dword ptr [ESI + 0xf8]
    //         00468ced     MOV        dword ptr [ESP + local_10],EAX
    //         00468cf1     MOV        EAX,dword ptr [ESP + param_5]
    //         00468cf5     IMUL       EAX,EBX
    //         00468cf8     CDQ
    //         00468cf9     IDIV       EBP
    //         00468cfb     MOV        dword ptr [ESP + param_4],EAX
    //         00468cff     MOV        EAX,dword ptr [ESP + param_6]
    //         00468d03     IMUL       EAX,this
    //         00468d06     CDQ
    //         00468d07     IDIV       EDI
    //         00468d09     MOV        EDI,EAX
    //         00468d0b     MOV        EAX,dword ptr [ESP + param_7]
    //         00468d0f     IMUL       EAX,EBX
    //         00468d12     CDQ
    //         00468d13     IDIV       EBP
    //         00468d15     MOV        EBP,EAX
    //         00468d17     CALL       operator_new                                     void * operator_new(uint param_1)
    //         00468d1c     ADD        ESP,0x4
    //         00468d1f     MOV        dword ptr [ESP + param_5],EAX
    //         00468d23     TEST       EAX,EAX
    //         00468d25     MOV        dword ptr [ESP + local_4],0x0
    //         00468d2d     JZ         LAB_00468d38
    //         00468d2f     MOV        this,EAX
    //         00468d31     CALL       TTextPanel::TTextPanel                           undefined TTextPanel(TTextPanel * this)
    //         00468d36     JMP        LAB_00468d3a
    //                               LAB_00468d38                                                 XREF[1]:     00468d2d(j)  
    //         00468d38     XOR        EAX,EAX
    //                               LAB_00468d3a                                                 XREF[1]:     00468d36(j)  
    //         00468d3a     MOV        EBX,dword ptr [ESP + param_2]
    //         00468d3e     MOV        dword ptr [ESP + local_4],0xffffffff
    //                              Panel_ez.cpp:1235 (24)
    //         00468d46     TEST       EAX,EAX
    //         00468d48     MOV        dword ptr [EBX],EAX
    //         00468d4a     JZ         LAB_00468e2c
    //         00468d50     MOV        this,dword ptr [EAX + 0xd8]
    //         00468d56     TEST       this,this
    //         00468d58     JNZ        LAB_00468e2c
    //                              Panel_ez.cpp:1241 (8)
    //         00468d5e     MOV        EAX,dword ptr [ESP + param_8]
    //         00468d62     TEST       EAX,EAX
    //         00468d64     JL         LAB_00468d69
    //                              Panel_ez.cpp:1242 (1)
    //         00468d66     PUSH       EAX
    //                              Panel_ez.cpp:1243 (2)
    //         00468d67     JMP        LAB_00468d6b
    //                               LAB_00468d69                                                 XREF[1]:     00468d64(j)  
    //                              Panel_ez.cpp:1244 (13)
    //         00468d69     PUSH       0xa
    //                               LAB_00468d6b                                                 XREF[1]:     00468d67(j)  
    //         00468d6b     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         00468d71     CALL       RGE_Base_Game::get_font                          RGE_Font * get_font(RGE_Base_Game * this, int
    //                              Panel_ez.cpp:1247 (55)
    //         00468d76     MOV        this,dword ptr [EAX + 0x8]
    //         00468d79     MOV        EDX,dword ptr [EAX + 0x4]
    //         00468d7c     MOV        EAX,dword ptr [EAX]
    //         00468d7e     PUSH       0x0
    //         00468d80     PUSH       0x0
    //         00468d82     PUSH       0x0
    //         00468d84     PUSH       0x0
    //         00468d86     PUSH       0x0
    //         00468d88     PUSH       0x0
    //         00468d8a     PUSH       0x0
    //         00468d8c     PUSH       this
    //         00468d8d     MOV        this,dword ptr [ESP + param_4]
    //         00468d91     PUSH       EDX
    //         00468d92     MOV        EDX,dword ptr [ESP + local_10]
    //         00468d96     PUSH       EAX
    //         00468d97     MOV        EAX,dword ptr [ESP + param_1]
    //         00468d9b     PUSH       EBP
    //         00468d9c     PUSH       EDI
    //         00468d9d     PUSH       this
    //         00468d9e     MOV        this,dword ptr [ESI + 0x20]
    //         00468da1     PUSH       EDX
    //         00468da2     PUSH       EAX
    //         00468da3     PUSH       this
    //         00468da4     MOV        this,dword ptr [EBX]
    //         00468da6     CALL       TTextPanel::setup                                long setup(TTextPanel * this, TDrawArea * par
    //         00468dab     TEST       EAX,EAX
    //                              Panel_ez.cpp:1250 (2)
    //         00468dad     JZ         LAB_00468e2c
    //                              Panel_ez.cpp:1253 (16)
    //         00468daf     MOV        EAX,dword ptr [ESP + param_9]
    //         00468db3     MOV        this,dword ptr [ESP + param_10]
    //         00468db7     TEST       EAX,EAX
    //         00468db9     JZ         LAB_00468dc5
    //         00468dbb     TEST       this,this
    //         00468dbd     JZ         LAB_00468dc5
    //                              Panel_ez.cpp:1254 (4)
    //         00468dbf     PUSH       0x0
    //         00468dc1     PUSH       0x0
    //                              Panel_ez.cpp:1255 (6)
    //         00468dc3     JMP        LAB_00468dd9
    //                               LAB_00468dc5                                                 XREF[2]:     00468db9(j), 00468dbd(j)  
    //         00468dc5     TEST       EAX,EAX
    //         00468dc7     JZ         LAB_00468dcd
    //                              Panel_ez.cpp:1256 (2)
    //         00468dc9     PUSH       0x0
    //                              Panel_ez.cpp:1257 (4)
    //         00468dcb     JMP        LAB_00468dd7
    //                               LAB_00468dcd                                                 XREF[1]:     00468dc7(j)  
    //         00468dcd     TEST       this,this
    //                              Panel_ez.cpp:1258 (6)
    //         00468dcf     PUSH       0x1
    //         00468dd1     JZ         LAB_00468dd7
    //         00468dd3     PUSH       0x0
    //                              Panel_ez.cpp:1259 (2)
    //         00468dd5     JMP        LAB_00468dd9
    //                               LAB_00468dd7                                                 XREF[2]:     00468dcb(j), 00468dd1(j)  
    //                              Panel_ez.cpp:1260 (9)
    //         00468dd7     PUSH       0x3
    //                               LAB_00468dd9                                                 XREF[2]:     00468dc3(j), 00468dd5(j)  
    //         00468dd9     MOV        this,dword ptr [EBX]
    //         00468ddb     CALL       TTextPanel::set_alignment                        void set_alignment(TTextPanel * this, Alignme
    //                              Panel_ez.cpp:1262 (12)
    //         00468de0     MOV        EDX,dword ptr [ESP + param_11]
    //         00468de4     MOV        this,dword ptr [EBX]
    //         00468de6     PUSH       EDX
    //         00468de7     CALL       TTextPanel::set_word_wrap                        void set_word_wrap(TTextPanel * this, int par
    //                              Panel_ez.cpp:1264 (15)
    //         00468dec     MOV        this,dword ptr [EBX]
    //         00468dee     MOV        EDX,dword ptr [ESP + param_3]
    //         00468df2     PUSH       EDX
    //         00468df3     MOV        EAX,dword ptr [this->_padding_]
    //         00468df5     CALL       dword ptr [EAX + 0xe8]
    //                              Panel_ez.cpp:1271 (21)
    //         00468dfb     MOV        EAX,dword ptr [ESI + 0x32c]
    //         00468e01     MOV        this,dword ptr [ESI + 0x328]
    //         00468e07     PUSH       EAX
    //         00468e08     PUSH       this=>DAT_fffffff8
    //         00468e09     MOV        this,dword ptr [EBX]
    //         00468e0b     CALL       TTextPanel::set_text_color                       void set_text_color(TTextPanel * this, ulong 
    //                              Panel_ez.cpp:1272 (21)
    //         00468e10     MOV        EDX,dword ptr [ESI + 0x334]
    //         00468e16     MOV        EAX,dword ptr [ESI + 0x330]
    //         00468e1c     MOV        this,dword ptr [EBX]
    //         00468e1e     PUSH       EDX
    //         00468e1f     PUSH       EAX=>DAT_fffffff8
    //         00468e20     CALL       TTextPanel::set_highlight_text_color             void set_highlight_text_color(TTextPanel * th
    //                              Panel_ez.cpp:1274 (7)
    //         00468e25     MOV        EAX,0x1
    //         00468e2a     JMP        LAB_00468e38
    //                               LAB_00468e2c                                                 XREF[3]:     00468d4a(j), 00468d58(j), 
    //                                                                                                         00468dad(j)  
    //                              Panel_ez.cpp:1237 (10)
    //         00468e2c     MOV        dword ptr [ESI + 0xd8],0x1
    //                              Panel_ez.cpp:1238 (2)
    //         00468e36     XOR        EAX,EAX
    //                               LAB_00468e38                                                 XREF[1]:     00468e2a(j)  
    //                              Panel_ez.cpp:1275 (21)
    //         00468e38     MOV        this,dword ptr [ESP + local_c]
    //         00468e3c     POP        EDI
    //         00468e3d     POP        ESI
    //         00468e3e     POP        EBP
    //         00468e3f     MOV        dword ptr FS:[0x0],this
    //         00468e46     POP        EBX
    //         00468e47     ADD        ESP,0x10
    //         00468e4a     RET        0x2c
}

// Offset: 0x00468E50
int TRIBE_Screen_Sed_Open::create_text(TPanel* param_1, TTextPanel** param_2, char** param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9, int param_10, int param_11) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * protected: virtual int __thiscall TEasy_Panel::create_text(class TPanel *,class TTextPanel * *,cha... *
    //                              *********************************************************************************************************
    //                              int __thiscall create_text(TEasy_Panel * this, TPanel * param_1, TTe
    //              int               EAX:4          <RETURN>
    //              TEasy_Panel *     ECX:4 (auto)   this
    //              TPanel *          Stack[0x4]:4   param_1                   XREF[1]:     00468f37(R)  
    //              TTextPanel * *    Stack[0x8]:4   param_2                   XREF[1]:     00468eda(R)  
    //              char * *          Stack[0xc]:4   param_3                   XREF[1]:     00468f5a(R)  
    //              long              Stack[0x10]:4  param_4                   XREF[1]:     00468f53(R)  
    //              long              Stack[0x14]:4  param_5                   XREF[3]:     00468e66(R), 00468e9b(W), 00468f2d(R)  
    //              long              Stack[0x18]:4  param_6                   XREF[2]:     00468e91(R), 00468ebf(W)  
    //              long              Stack[0x1c]:4  param_7                   XREF[1]:     00468e9f(R)  
    //              long              Stack[0x20]:4  param_8                   XREF[1]:     00468eab(R)  
    //              long              Stack[0x24]:4  param_9                   XREF[1]:     00468efe(R)  
    //              int               Stack[0x28]:4  param_10
    //              int               Stack[0x2c]:4  param_11
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     00468ec5(W), 00468ede(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     00468fe2(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[2]:     00468e8d(W), 00468f32(R)  
    //              long              Stack[-0x14]:4 ideal_x
    //                               ?create_text@TEasy_Panel@@MAEHPAVTPanel@@PAPAVTTextPanel@@P  XREF[44]:    0056f70c(*), 0056f84c(*), 
    //                               TEasy_Panel::create_text                                                  0056f994(*), 0056fac4(*), 
    //                                                                                                         0056fbf4(*), 0056fd2c(*), 
    //                                                                                                         0056fe5c(*), 0056ff8c(*), 
    //                                                                                                         005700bc(*), 005701ec(*), 
    //                                                                                                         00570e14(*), 005711ac(*), 
    //                                                                                                         00571a0c(*), 00571dec(*), 
    //                                                                                                         0057227c(*), 005723a4(*), 
    //                                                                                                         005724cc(*), 005725f4(*), 
    //                                                                                                         0057271c(*), 0057284c(*), [more]
    //                              Panel_ez.cpp:1281 (22)
    //         00468e50     PUSH       -0x1
    //         00468e52     PUSH       FUN_0055e00b
    //         00468e57     MOV        EAX,FS:[0x0]
    //         00468e5d     PUSH       EAX
    //         00468e5e     MOV        dword ptr FS:[0x0],ESP
    //         00468e65     PUSH       this
    //                              Panel_ez.cpp:1283 (10)
    //         00468e66     MOV        EAX,dword ptr [ESP + param_5]
    //         00468e6a     PUSH       EBX
    //         00468e6b     PUSH       EBP
    //         00468e6c     PUSH       ESI
    //         00468e6d     MOV        ESI,this
    //         00468e6f     PUSH       EDI
    //                              Panel_ez.cpp:1288 (118)
    //         00468e70     PUSH       0x188
    //         00468e75     MOV        this,dword ptr [ESI + 0x14]
    //         00468e78     MOV        EDI,dword ptr [ESI + 0xf4]
    //         00468e7e     IMUL       EAX,this
    //         00468e81     CDQ
    //         00468e82     IDIV       EDI
    //         00468e84     MOV        EBX,dword ptr [ESI + 0x18]
    //         00468e87     MOV        EBP,dword ptr [ESI + 0xf8]
    //         00468e8d     MOV        dword ptr [ESP + local_10],EAX
    //         00468e91     MOV        EAX,dword ptr [ESP + param_6]
    //         00468e95     IMUL       EAX,EBX
    //         00468e98     CDQ
    //         00468e99     IDIV       EBP
    //         00468e9b     MOV        dword ptr [ESP + param_5],EAX
    //         00468e9f     MOV        EAX,dword ptr [ESP + param_7]
    //         00468ea3     IMUL       EAX,this
    //         00468ea6     CDQ
    //         00468ea7     IDIV       EDI
    //         00468ea9     MOV        EDI,EAX
    //         00468eab     MOV        EAX,dword ptr [ESP + param_8]
    //         00468eaf     IMUL       EAX,EBX
    //         00468eb2     CDQ
    //         00468eb3     IDIV       EBP
    //         00468eb5     MOV        EBP,EAX
    //         00468eb7     CALL       operator_new                                     void * operator_new(uint param_1)
    //         00468ebc     ADD        ESP,0x4
    //         00468ebf     MOV        dword ptr [ESP + param_6],EAX
    //         00468ec3     TEST       EAX,EAX
    //         00468ec5     MOV        dword ptr [ESP + local_4],0x0
    //         00468ecd     JZ         LAB_00468ed8
    //         00468ecf     MOV        this,EAX
    //         00468ed1     CALL       TTextPanel::TTextPanel                           undefined TTextPanel(TTextPanel * this)
    //         00468ed6     JMP        LAB_00468eda
    //                               LAB_00468ed8                                                 XREF[1]:     00468ecd(j)  
    //         00468ed8     XOR        EAX,EAX
    //                               LAB_00468eda                                                 XREF[1]:     00468ed6(j)  
    //         00468eda     MOV        EBX,dword ptr [ESP + param_2]
    //         00468ede     MOV        dword ptr [ESP + local_4],0xffffffff
    //                              Panel_ez.cpp:1289 (24)
    //         00468ee6     TEST       EAX,EAX
    //         00468ee8     MOV        dword ptr [EBX],EAX
    //         00468eea     JZ         LAB_00468fd6
    //         00468ef0     MOV        this,dword ptr [EAX + 0xd8]
    //         00468ef6     TEST       this,this
    //         00468ef8     JNZ        LAB_00468fd6
    //                              Panel_ez.cpp:1295 (8)
    //         00468efe     MOV        EAX,dword ptr [ESP + param_9]
    //         00468f02     TEST       EAX,EAX
    //         00468f04     JL         LAB_00468f09
    //                              Panel_ez.cpp:1296 (1)
    //         00468f06     PUSH       EAX
    //                              Panel_ez.cpp:1297 (2)
    //         00468f07     JMP        LAB_00468f0b
    //                               LAB_00468f09                                                 XREF[1]:     00468f04(j)  
    //                              Panel_ez.cpp:1298 (13)
    //         00468f09     PUSH       0xa
    //                               LAB_00468f0b                                                 XREF[1]:     00468f07(j)  
    //         00468f0b     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         00468f11     CALL       RGE_Base_Game::get_font                          RGE_Font * get_font(RGE_Base_Game * this, int
    //                              Panel_ez.cpp:1301 (55)
    //         00468f16     MOV        this,dword ptr [EAX + 0x8]
    //         00468f19     MOV        EDX,dword ptr [EAX + 0x4]
    //         00468f1c     MOV        EAX,dword ptr [EAX]
    //         00468f1e     PUSH       0x0
    //         00468f20     PUSH       0x0
    //         00468f22     PUSH       0x0
    //         00468f24     PUSH       0x0
    //         00468f26     PUSH       0x0
    //         00468f28     PUSH       0x0
    //         00468f2a     PUSH       0x0
    //         00468f2c     PUSH       this
    //         00468f2d     MOV        this,dword ptr [ESP + param_5]
    //         00468f31     PUSH       EDX
    //         00468f32     MOV        EDX,dword ptr [ESP + local_10]
    //         00468f36     PUSH       EAX
    //         00468f37     MOV        EAX,dword ptr [ESP + param_1]
    //         00468f3b     PUSH       EBP
    //         00468f3c     PUSH       EDI
    //         00468f3d     PUSH       this
    //         00468f3e     MOV        this,dword ptr [ESI + 0x20]
    //         00468f41     PUSH       EDX
    //         00468f42     PUSH       EAX
    //         00468f43     PUSH       this
    //         00468f44     MOV        this,dword ptr [EBX]
    //         00468f46     CALL       TTextPanel::setup                                long setup(TTextPanel * this, TDrawArea * par
    //         00468f4b     TEST       EAX,EAX
    //                              Panel_ez.cpp:1304 (6)
    //         00468f4d     JZ         LAB_00468fd6
    //                              Panel_ez.cpp:1307 (20)
    //         00468f53     MOV        EAX,dword ptr [ESP + param_4]
    //         00468f57     MOV        this,dword ptr [EBX]
    //         00468f59     PUSH       EAX
    //         00468f5a     MOV        EAX,dword ptr [ESP + param_3]
    //         00468f5e     MOV        EDX,dword ptr [this->_padding_]
    //         00468f60     PUSH       EAX
    //         00468f61     CALL       dword ptr [EDX + 0xe0]
    //                              Panel_ez.cpp:1308 (13)
    //         00468f67     MOV        this,dword ptr [EBX]
    //         00468f69     PUSH       0x1
    //         00468f6b     PUSH       0x0=>DAT_fffffff8
    //         00468f6d     PUSH       offset DAT_fffffff4
    //         00468f6f     CALL       TTextPanel::scroll                               void scroll(TTextPanel * this, uchar param_1,
    //                              Panel_ez.cpp:1310 (16)
    //         00468f74     MOV        EAX,dword ptr [ESP + 0x48]
    //         00468f78     MOV        this,dword ptr [ESP + 0x4c]
    //         00468f7c     TEST       EAX,EAX
    //         00468f7e     JZ         LAB_00468f8a
    //         00468f80     TEST       this,this
    //         00468f82     JZ         LAB_00468f8a
    //                              Panel_ez.cpp:1311 (4)
    //         00468f84     PUSH       0x0
    //         00468f86     PUSH       0x0=>DAT_fffffff8
    //                              Panel_ez.cpp:1312 (6)
    //         00468f88     JMP        LAB_00468f9e
    //                               LAB_00468f8a                                                 XREF[2]:     00468f7e(j), 00468f82(j)  
    //         00468f8a     TEST       EAX,EAX
    //         00468f8c     JZ         LAB_00468f92
    //                              Panel_ez.cpp:1313 (2)
    //         00468f8e     PUSH       0x0
    //                              Panel_ez.cpp:1314 (4)
    //         00468f90     JMP        LAB_00468f9c
    //                               LAB_00468f92                                                 XREF[1]:     00468f8c(j)  
    //         00468f92     TEST       this,this
    //                              Panel_ez.cpp:1315 (6)
    //         00468f94     PUSH       0x1
    //         00468f96     JZ         LAB_00468f9c
    //         00468f98     PUSH       0x0=>DAT_fffffff8
    //                              Panel_ez.cpp:1316 (2)
    //         00468f9a     JMP        LAB_00468f9e
    //                               LAB_00468f9c                                                 XREF[2]:     00468f90(j), 00468f96(j)  
    //                              Panel_ez.cpp:1317 (9)
    //         00468f9c     PUSH       offset DAT_fffffff8
    //                               LAB_00468f9e                                                 XREF[2]:     00468f88(j), 00468f9a(j)  
    //         00468f9e     MOV        this,dword ptr [EBX]
    //         00468fa0     CALL       TTextPanel::set_alignment                        void set_alignment(TTextPanel * this, Alignme
    //                              Panel_ez.cpp:1324 (21)
    //         00468fa5     MOV        this,dword ptr [ESI + 0x32c]
    //         00468fab     MOV        EDX,dword ptr [ESI + 0x328]
    //         00468fb1     PUSH       this
    //         00468fb2     MOV        this,dword ptr [EBX]
    //         00468fb4     PUSH       EDX=>DAT_fffffff8
    //         00468fb5     CALL       TTextPanel::set_text_color                       void set_text_color(TTextPanel * this, ulong 
    //                              Panel_ez.cpp:1325 (21)
    //         00468fba     MOV        EAX,dword ptr [ESI + 0x334]
    //         00468fc0     MOV        this,dword ptr [ESI + 0x330]
    //         00468fc6     PUSH       EAX
    //         00468fc7     PUSH       this=>DAT_fffffff8
    //         00468fc8     MOV        this,dword ptr [EBX]
    //         00468fca     CALL       TTextPanel::set_highlight_text_color             void set_highlight_text_color(TTextPanel * th
    //                              Panel_ez.cpp:1327 (7)
    //         00468fcf     MOV        EAX,0x1
    //         00468fd4     JMP        LAB_00468fe2
    //                               LAB_00468fd6                                                 XREF[3]:     00468eea(j), 00468ef8(j), 
    //                                                                                                         00468f4d(j)  
    //                              Panel_ez.cpp:1291 (10)
    //         00468fd6     MOV        dword ptr [ESI + 0xd8],0x1
    //                              Panel_ez.cpp:1292 (2)
    //         00468fe0     XOR        EAX,EAX
    //                               LAB_00468fe2                                                 XREF[1]:     00468fd4(j)  
    //                              Panel_ez.cpp:1328 (21)
    //         00468fe2     MOV        this,dword ptr [ESP + local_c]
    //         00468fe6     POP        EDI
    //         00468fe7     POP        ESI
    //         00468fe8     POP        EBP
    //         00468fe9     MOV        dword ptr FS:[0x0],this
    //         00468ff0     POP        EBX
    //         00468ff1     ADD        ESP,0x10
    //         00468ff4     RET        0x2c
}

// Offset: 0x00469000
int TRIBE_Screen_Sed_Open::create_input(TPanel* param_1, TInputPanel** param_2, char* param_3, short param_4, FormatType param_5, long param_6, long param_7, long param_8, long param_9, long param_10) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * protected: virtual int __thiscall TEasy_Panel::create_input(class TPanel *,class TInputPanel * *,c... *
    //                              *********************************************************************************************************
    //                              int __thiscall create_input(TEasy_Panel * this, TPanel * param_1, TI
    //              int               EAX:4          <RETURN>
    //              TEasy_Panel *     ECX:4 (auto)   this
    //              TPanel *          Stack[0x4]:4   param_1                   XREF[1]:     004690fc(R)  
    //              TInputPanel * *   Stack[0x8]:4   param_2                   XREF[1]:     0046908a(R)  
    //              char *            Stack[0xc]:4   param_3                   XREF[1]:     004690ca(R)  
    //              short             Stack[0x10]:2  param_4                   XREF[1]:     004690cf(R)  
    //              FormatType        Stack[0x14]:4  param_5                   XREF[1]:     004690c6(R)  
    //              long              Stack[0x18]:4  param_6                   XREF[3]:     00469016(R), 0046904b(W), 004690f2(R)  
    //              long              Stack[0x1c]:4  param_7                   XREF[2]:     00469041(R), 0046906f(W)  
    //              long              Stack[0x20]:4  param_8                   XREF[1]:     0046904f(R)  
    //              long              Stack[0x24]:4  param_9                   XREF[1]:     0046905b(R)  
    //              long              Stack[0x28]:4  param_10                  XREF[1]:     004690ae(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     00469075(W), 0046908e(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     0046919d(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[2]:     0046903d(W), 004690f7(R)  
    //              long              Stack[-0x14]:4 ideal_x
    //                               ?create_input@TEasy_Panel@@MAEHPAVTPanel@@PAPAVTInputPanel@  XREF[45]:    create_input:004a89d4(c), 
    //                               TEasy_Panel::create_input                                                 0056f714(*), 0056f854(*), 
    //                                                                                                         0056f99c(*), 0056facc(*), 
    //                                                                                                         0056fbfc(*), 0056fd34(*), 
    //                                                                                                         0056fe64(*), 0056ff94(*), 
    //                                                                                                         005700c4(*), 005701f4(*), 
    //                                                                                                         00570e1c(*), 005711b4(*), 
    //                                                                                                         00571a14(*), 00571df4(*), 
    //                                                                                                         00572284(*), 005723ac(*), 
    //                                                                                                         005724d4(*), 005725fc(*), 
    //                                                                                                         00572724(*), [more]
    //                              Panel_ez.cpp:1345 (22)
    //         00469000     PUSH       -0x1
    //         00469002     PUSH       FUN_0055e02b
    //         00469007     MOV        EAX,FS:[0x0]
    //         0046900d     PUSH       EAX
    //         0046900e     MOV        dword ptr FS:[0x0],ESP
    //         00469015     PUSH       this
    //                              Panel_ez.cpp:1347 (10)
    //         00469016     MOV        EAX,dword ptr [ESP + param_6]
    //         0046901a     PUSH       EBX
    //         0046901b     PUSH       EBP
    //         0046901c     PUSH       ESI
    //         0046901d     MOV        ESI,this
    //         0046901f     PUSH       EDI
    //                              Panel_ez.cpp:1352 (118)
    //         00469020     PUSH       0x1b8
    //         00469025     MOV        this,dword ptr [ESI + 0x14]
    //         00469028     MOV        EDI,dword ptr [ESI + 0xf4]
    //         0046902e     IMUL       EAX,this
    //         00469031     CDQ
    //         00469032     IDIV       EDI
    //         00469034     MOV        EBX,dword ptr [ESI + 0x18]
    //         00469037     MOV        EBP,dword ptr [ESI + 0xf8]
    //         0046903d     MOV        dword ptr [ESP + local_10],EAX
    //         00469041     MOV        EAX,dword ptr [ESP + param_7]
    //         00469045     IMUL       EAX,EBX
    //         00469048     CDQ
    //         00469049     IDIV       EBP
    //         0046904b     MOV        dword ptr [ESP + param_6],EAX
    //         0046904f     MOV        EAX,dword ptr [ESP + param_8]
    //         00469053     IMUL       EAX,this
    //         00469056     CDQ
    //         00469057     IDIV       EDI
    //         00469059     MOV        EDI,EAX
    //         0046905b     MOV        EAX,dword ptr [ESP + param_9]
    //         0046905f     IMUL       EAX,EBX
    //         00469062     CDQ
    //         00469063     IDIV       EBP
    //         00469065     MOV        EBP,EAX
    //         00469067     CALL       operator_new                                     void * operator_new(uint param_1)
    //         0046906c     ADD        ESP,0x4
    //         0046906f     MOV        dword ptr [ESP + param_7],EAX
    //         00469073     TEST       EAX,EAX
    //         00469075     MOV        dword ptr [ESP + local_4],0x0
    //         0046907d     JZ         LAB_00469088
    //         0046907f     MOV        this,EAX
    //         00469081     CALL       TInputPanel::TInputPanel                         undefined TInputPanel(TInputPanel * this)
    //         00469086     JMP        LAB_0046908a
    //                               LAB_00469088                                                 XREF[1]:     0046907d(j)  
    //         00469088     XOR        EAX,EAX
    //                               LAB_0046908a                                                 XREF[1]:     00469086(j)  
    //         0046908a     MOV        EBX,dword ptr [ESP + param_2]
    //         0046908e     MOV        dword ptr [ESP + local_4],0xffffffff
    //                              Panel_ez.cpp:1353 (24)
    //         00469096     TEST       EAX,EAX
    //         00469098     MOV        dword ptr [EBX],EAX
    //         0046909a     JZ         LAB_00469191
    //         004690a0     MOV        this,dword ptr [EAX + 0xd8]
    //         004690a6     TEST       this,this
    //         004690a8     JNZ        LAB_00469191
    //                              Panel_ez.cpp:1359 (8)
    //         004690ae     MOV        EAX,dword ptr [ESP + param_10]
    //         004690b2     TEST       EAX,EAX
    //         004690b4     JL         LAB_004690b9
    //                              Panel_ez.cpp:1360 (1)
    //         004690b6     PUSH       EAX
    //                              Panel_ez.cpp:1361 (2)
    //         004690b7     JMP        LAB_004690bb
    //                               LAB_004690b9                                                 XREF[1]:     004690b4(j)  
    //                              Panel_ez.cpp:1362 (13)
    //         004690b9     PUSH       0xa
    //                               LAB_004690bb                                                 XREF[1]:     004690b7(j)  
    //         004690bb     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004690c1     CALL       RGE_Base_Game::get_font                          RGE_Font * get_font(RGE_Base_Game * this, int
    //                              Panel_ez.cpp:1365 (76)
    //         004690c6     MOV        this,dword ptr [ESP + param_5]
    //         004690ca     MOV        EDX,dword ptr [ESP + param_3]
    //         004690ce     PUSH       this
    //         004690cf     MOV        this,dword ptr [ESP + param_4]
    //         004690d3     PUSH       EDX
    //         004690d4     MOV        EDX,dword ptr [EAX + 0x8]
    //         004690d7     PUSH       0x0
    //         004690d9     PUSH       this
    //         004690da     MOV        this,dword ptr [EAX + 0x4]
    //         004690dd     PUSH       0xff
    //         004690e2     PUSH       0xff
    //         004690e7     PUSH       0x1
    //         004690e9     PUSH       0x0
    //         004690eb     PUSH       0x0
    //         004690ed     PUSH       0x0
    //         004690ef     PUSH       EDX
    //         004690f0     MOV        EDX,dword ptr [EAX]
    //         004690f2     MOV        EAX,dword ptr [ESP + param_6]
    //         004690f6     PUSH       this
    //         004690f7     MOV        this,dword ptr [ESP + local_10]
    //         004690fb     PUSH       EDX
    //         004690fc     MOV        EDX,dword ptr [ESP + param_1]
    //         00469100     PUSH       EBP
    //         00469101     PUSH       EDI
    //         00469102     PUSH       EAX
    //         00469103     MOV        EAX,dword ptr [ESI + 0x20]
    //         00469106     PUSH       this
    //         00469107     MOV        this,dword ptr [EBX]
    //         00469109     PUSH       EDX
    //         0046910a     PUSH       EAX
    //         0046910b     CALL       TInputPanel::setup                               long setup(TInputPanel * this, TDrawArea * pa
    //         00469110     TEST       EAX,EAX
    //                              Panel_ez.cpp:1368 (2)
    //         00469112     JZ         LAB_00469191
    //                              Panel_ez.cpp:1373 (10)
    //         00469114     MOV        EAX,dword ptr [ESI + 0x31c]
    //         0046911a     TEST       EAX,EAX
    //         0046911c     JZ         LAB_00469160
    //                              Panel_ez.cpp:1374 (66)
    //         0046911e     XOR        EAX,EAX
    //         00469120     MOV        this,dword ptr [EBX]
    //         00469122     MOV        AL,byte ptr [ESI + 0x325]
    //         00469128     PUSH       EAX
    //         00469129     XOR        EAX,EAX
    //         0046912b     MOV        AL,byte ptr [ESI + 0x324]
    //         00469131     MOV        EDX,dword ptr [this->_padding_]
    //         00469133     PUSH       EAX
    //         00469134     XOR        EAX,EAX
    //         00469136     MOV        AL,byte ptr [ESI + 0x323]
    //         0046913c     PUSH       EAX
    //         0046913d     XOR        EAX,EAX
    //         0046913f     MOV        AL,byte ptr [ESI + 0x322]
    //         00469145     PUSH       EAX
    //         00469146     XOR        EAX,EAX
    //         00469148     MOV        AL,byte ptr [ESI + 0x321]
    //         0046914e     PUSH       EAX
    //         0046914f     XOR        EAX,EAX
    //         00469151     MOV        AL,byte ptr [ESI + 0x320]
    //         00469157     PUSH       EAX
    //         00469158     PUSH       0x3
    //         0046915a     CALL       dword ptr [EDX + 0xec]
    //                               LAB_00469160                                                 XREF[1]:     0046911c(j)  
    //                              Panel_ez.cpp:1376 (21)
    //         00469160     MOV        this,dword ptr [ESI + 0x32c]
    //         00469166     MOV        EDX,dword ptr [ESI + 0x328]
    //         0046916c     PUSH       this
    //         0046916d     MOV        this,dword ptr [EBX]
    //         0046916f     PUSH       EDX=>DAT_fffffff8
    //         00469170     CALL       TTextPanel::set_text_color                       void set_text_color(TTextPanel * this, ulong 
    //                              Panel_ez.cpp:1377 (21)
    //         00469175     MOV        EAX,dword ptr [ESI + 0x334]
    //         0046917b     MOV        this,dword ptr [ESI + 0x330]
    //         00469181     PUSH       EAX
    //         00469182     PUSH       this=>DAT_fffffff8
    //         00469183     MOV        this,dword ptr [EBX]
    //         00469185     CALL       TTextPanel::set_highlight_text_color             void set_highlight_text_color(TTextPanel * th
    //                              Panel_ez.cpp:1379 (7)
    //         0046918a     MOV        EAX,0x1
    //         0046918f     JMP        LAB_0046919d
    //                               LAB_00469191                                                 XREF[3]:     0046909a(j), 004690a8(j), 
    //                                                                                                         00469112(j)  
    //                              Panel_ez.cpp:1355 (10)
    //         00469191     MOV        dword ptr [ESI + 0xd8],0x1
    //                              Panel_ez.cpp:1356 (2)
    //         0046919b     XOR        EAX,EAX
    //                               LAB_0046919d                                                 XREF[1]:     0046918f(j)  
    //                              Panel_ez.cpp:1380 (21)
    //         0046919d     MOV        this,dword ptr [ESP + local_c]
    //         004691a1     POP        EDI
    //         004691a2     POP        ESI
    //         004691a3     POP        EBP
    //         004691a4     MOV        dword ptr FS:[0x0],this
    //         004691ab     POP        EBX
    //         004691ac     ADD        ESP,0x10
    //         004691af     RET        0x28
}

// Offset: 0x004691C0
int TRIBE_Screen_Sed_Open::create_edit(TPanel* param_1, TEditPanel** param_2, char* param_3, short param_4, FormatType param_5, long param_6, long param_7, long param_8, long param_9, long param_10, int param_11, int param_12) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * protected: virtual int __thiscall TEasy_Panel::create_edit(class TPanel *,class TEditPanel * *,cha... *
    //                              *********************************************************************************************************
    //                              int __thiscall create_edit(TEasy_Panel * this, TPanel * param_1, TEd
    //              int               EAX:4          <RETURN>
    //              TEasy_Panel *     ECX:4 (auto)   this
    //              TPanel *          Stack[0x4]:4   param_1                   XREF[1]:     00469296(R)  
    //              TEditPanel * *    Stack[0x8]:4   param_2                   XREF[1]:     00469237(R)  
    //              char *            Stack[0xc]:4   param_3                   XREF[1]:     00469287(R)  
    //              short             Stack[0x10]:2  param_4                   XREF[1]:     00469282(R)  
    //              FormatType        Stack[0x14]:4  param_5                   XREF[1]:     00469273(R)  
    //              long              Stack[0x18]:4  param_6                   XREF[3]:     004691ce(R), 00469210(W), 00469291(R)  
    //              long              Stack[0x1c]:4  param_7                   XREF[2]:     004691f8(R), 0046921c(W)  
    //              long              Stack[0x20]:4  param_8                   XREF[1]:     00469206(R)  
    //              long              Stack[0x24]:4  param_9                   XREF[1]:     0046928c(R)  
    //              long              Stack[0x28]:4  param_10                  XREF[1]:     0046925b(R)  
    //              int               Stack[0x2c]:4  param_11                  XREF[1]:     00469345(R)  
    //              int               Stack[0x30]:4  param_12                  XREF[1]:     00469341(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     00469222(W), 0046923b(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     00469365(R)  
    //                               ?create_edit@TEasy_Panel@@MAEHPAVTPanel@@PAPAVTEditPanel@@P  XREF[53]:    TribeSendMessageDialog:00440b5d(c)
    //                               TEasy_Panel::create_edit                                                  TribeSendQuickMessageDialog:004415
    //                                                                                                         TRIBE_Campaign_Editor_Screen:0048f
    //                                                                                                         TribeMPCreateDialog:0049223a(c), 
    //                                                                                                         TribeMPStartupScreen:0049f4f5(c), 
    //                                                                                                         TribeMPSetupScreen:004a08e9(c), 
    //                                                                                                         TRIBE_Dialog_Name:004a6e6f(c), 
    //                                                                                                         TribeSaveGameScreen:004a73d6(c), 
    //                                                                                                         create_edit:004a8a2e(c), 
    //                                                                                                         0056f718(*), 0056f858(*), 
    //                                                                                                         0056f9a0(*), 0056fad0(*), 
    //                                                                                                         0056fc00(*), 0056fd38(*), 
    //                                                                                                         0056fe68(*), 0056ff98(*), 
    //                                                                                                         005700c8(*), 005701f8(*), 
    //                                                                                                         00570e20(*), [more]
    //                              Panel_ez.cpp:1399 (14)
    //         004691c0     MOV        EAX,FS:[0x0]
    //         004691c6     PUSH       -0x1
    //         004691c8     PUSH       FUN_0055e04b
    //         004691cd     PUSH       EAX
    //                              Panel_ez.cpp:1401 (17)
    //         004691ce     MOV        EAX,dword ptr [ESP + param_6]
    //         004691d2     MOV        dword ptr FS:[0x0],ESP
    //         004691d9     PUSH       EBX
    //         004691da     PUSH       EBP
    //         004691db     PUSH       ESI
    //         004691dc     MOV        ESI,this
    //         004691de     PUSH       EDI
    //                              Panel_ez.cpp:1407 (100)
    //         004691df     PUSH       0x16c
    //         004691e4     MOV        this,dword ptr [ESI + 0x14]
    //         004691e7     MOV        EDI,dword ptr [ESI + 0xf4]
    //         004691ed     IMUL       EAX,this
    //         004691f0     CDQ
    //         004691f1     IDIV       EDI
    //         004691f3     MOV        EBP,EAX
    //         004691f5     MOV        EAX,dword ptr [ESI + 0x18]
    //         004691f8     IMUL       EAX,dword ptr [ESP + param_7]
    //         004691fd     CDQ
    //         004691fe     IDIV       dword ptr [ESI + 0xf8]
    //         00469204     MOV        EBX,EAX
    //         00469206     MOV        EAX,dword ptr [ESP + param_8]
    //         0046920a     IMUL       EAX,this
    //         0046920d     CDQ
    //         0046920e     IDIV       EDI
    //         00469210     MOV        dword ptr [ESP + param_6],EAX
    //         00469214     CALL       operator_new                                     void * operator_new(uint param_1)
    //         00469219     ADD        ESP,0x4
    //         0046921c     MOV        dword ptr [ESP + param_7],EAX
    //         00469220     TEST       EAX,EAX
    //         00469222     MOV        dword ptr [ESP + local_4],0x0
    //         0046922a     JZ         LAB_00469235
    //         0046922c     MOV        this,EAX
    //         0046922e     CALL       TEditPanel::TEditPanel                           undefined TEditPanel(TEditPanel * this)
    //         00469233     JMP        LAB_00469237
    //                               LAB_00469235                                                 XREF[1]:     0046922a(j)  
    //         00469235     XOR        EAX,EAX
    //                               LAB_00469237                                                 XREF[1]:     00469233(j)  
    //         00469237     MOV        EDI,dword ptr [ESP + param_2]
    //         0046923b     MOV        dword ptr [ESP + local_4],0xffffffff
    //                              Panel_ez.cpp:1408 (24)
    //         00469243     TEST       EAX,EAX
    //         00469245     MOV        dword ptr [EDI],EAX
    //         00469247     JZ         LAB_00469359
    //         0046924d     MOV        this,dword ptr [EAX + 0xd8]
    //         00469253     TEST       this,this
    //         00469255     JNZ        LAB_00469359
    //                              Panel_ez.cpp:1414 (8)
    //         0046925b     MOV        EAX,dword ptr [ESP + param_10]
    //         0046925f     TEST       EAX,EAX
    //         00469261     JL         LAB_00469266
    //                              Panel_ez.cpp:1415 (1)
    //         00469263     PUSH       EAX
    //                              Panel_ez.cpp:1416 (2)
    //         00469264     JMP        LAB_00469268
    //                               LAB_00469266                                                 XREF[1]:     00469261(j)  
    //                              Panel_ez.cpp:1417 (13)
    //         00469266     PUSH       0xa
    //                               LAB_00469268                                                 XREF[1]:     00469264(j)  
    //         00469268     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0046926e     CALL       RGE_Base_Game::get_font                          RGE_Font * get_font(RGE_Base_Game * this, int
    //                              Panel_ez.cpp:1419 (9)
    //         00469273     MOV        this,dword ptr [ESP + param_5]
    //         00469277     XOR        EDX,EDX
    //         00469279     CMP        this,0x7
    //                              Panel_ez.cpp:1424 (48)
    //         0046927c     MOV        EAX,dword ptr [EAX]
    //         0046927e     SETNZ      DL
    //         00469281     PUSH       EDX
    //         00469282     MOV        EDX,dword ptr [ESP + param_4]
    //         00469286     PUSH       this
    //         00469287     MOV        this,dword ptr [ESP + param_3]
    //         0046928b     PUSH       this
    //         0046928c     MOV        this,dword ptr [ESP + param_9]
    //         00469290     PUSH       EDX
    //         00469291     MOV        EDX,dword ptr [ESP + param_6]
    //         00469295     PUSH       EAX
    //         00469296     MOV        EAX,dword ptr [ESP + param_1]
    //         0046929a     PUSH       this
    //         0046929b     MOV        this,dword ptr [ESI + 0x20]
    //         0046929e     PUSH       EDX
    //         0046929f     PUSH       EBX
    //         004692a0     PUSH       EBP
    //         004692a1     PUSH       EAX
    //         004692a2     PUSH       this
    //         004692a3     MOV        this,dword ptr [EDI]
    //         004692a5     CALL       TEditPanel::setup                                long setup(TEditPanel * this, TDrawArea * par
    //         004692aa     TEST       EAX,EAX
    //                              Panel_ez.cpp:1427 (6)
    //         004692ac     JZ         LAB_00469359
    //                              Panel_ez.cpp:1430 (10)
    //         004692b2     MOV        EAX,dword ptr [ESI + 0x31c]
    //         004692b8     TEST       EAX,EAX
    //         004692ba     JZ         LAB_004692fb
    //                              Panel_ez.cpp:1431 (63)
    //         004692bc     XOR        EDX,EDX
    //         004692be     XOR        EAX,EAX
    //         004692c0     MOV        DL,byte ptr [ESI + 0x325]
    //         004692c6     MOV        AL,byte ptr [ESI + 0x324]
    //         004692cc     XOR        this,this
    //         004692ce     PUSH       EDX
    //         004692cf     MOV        this,byte ptr [ESI + 0x323]
    //         004692d5     PUSH       EAX
    //         004692d6     XOR        EDX,EDX
    //         004692d8     PUSH       this
    //         004692d9     MOV        DL,byte ptr [ESI + 0x322]
    //         004692df     XOR        EAX,EAX
    //         004692e1     MOV        AL,byte ptr [ESI + 0x321]
    //         004692e7     XOR        this,this
    //         004692e9     MOV        this,byte ptr [ESI + 0x320]
    //         004692ef     PUSH       EDX
    //         004692f0     PUSH       EAX
    //         004692f1     PUSH       this
    //         004692f2     MOV        this,dword ptr [EDI]
    //         004692f4     PUSH       0x3
    //         004692f6     CALL       TEditPanel::set_bevel_info                       void set_bevel_info(TEditPanel * this, int pa
    //                               LAB_004692fb                                                 XREF[1]:     004692ba(j)  
    //                              Panel_ez.cpp:1433 (21)
    //         004692fb     MOV        EDX,dword ptr [ESI + 0x32c]
    //         00469301     MOV        EAX,dword ptr [ESI + 0x328]
    //         00469307     MOV        this,dword ptr [EDI]
    //         00469309     PUSH       EDX
    //         0046930a     PUSH       EAX
    //         0046930b     CALL       TEditPanel::set_text_color                       void set_text_color(TEditPanel * this, ulong 
    //                              Panel_ez.cpp:1434 (21)
    //         00469310     MOV        this,dword ptr [ESI + 0x334]
    //         00469316     MOV        EDX,dword ptr [ESI + 0x330]
    //         0046931c     PUSH       this
    //         0046931d     MOV        this,dword ptr [EDI]
    //         0046931f     PUSH       EDX
    //         00469320     CALL       TEditPanel::set_highlight_text_color             void set_highlight_text_color(TEditPanel * th
    //                              Panel_ez.cpp:1435 (28)
    //         00469325     MOV        AL,byte ptr [ESI + 0x454]
    //         0046932b     MOV        this,dword ptr [ESI + 0x468]
    //         00469331     MOV        EDX,dword ptr [ESI + 0x464]
    //         00469337     PUSH       EAX
    //         00469338     PUSH       this
    //         00469339     MOV        this,dword ptr [EDI]
    //         0046933b     PUSH       EDX
    //         0046933c     CALL       TEditPanel::set_back_color                       void set_back_color(TEditPanel * this, void *
    //                              Panel_ez.cpp:1436 (17)
    //         00469341     MOV        EAX,dword ptr [ESP + param_12]
    //         00469345     MOV        this,dword ptr [ESP + param_11]
    //         00469349     PUSH       EAX
    //         0046934a     PUSH       this
    //         0046934b     MOV        this,dword ptr [EDI]
    //         0046934d     CALL       TEditPanel::set_ime_info                         void set_ime_info(TEditPanel * this, int para
    //                              Panel_ez.cpp:1438 (7)
    //         00469352     MOV        EAX,0x1
    //         00469357     JMP        LAB_00469365
    //                               LAB_00469359                                                 XREF[3]:     00469247(j), 00469255(j), 
    //                                                                                                         004692ac(j)  
    //                              Panel_ez.cpp:1410 (10)
    //         00469359     MOV        dword ptr [ESI + 0xd8],0x1
    //                              Panel_ez.cpp:1411 (2)
    //         00469363     XOR        EAX,EAX
    //                               LAB_00469365                                                 XREF[1]:     00469357(j)  
    //                              Panel_ez.cpp:1439 (21)
    //         00469365     MOV        this,dword ptr [ESP + local_c]
    //         00469369     POP        EDI
    //         0046936a     POP        ESI
    //         0046936b     POP        EBP
    //         0046936c     MOV        dword ptr FS:[0x0],this
    //         00469373     POP        EBX
    //         00469374     ADD        ESP,0xc
    //         00469377     RET        0x30
}

// Offset: 0x00469380
int TRIBE_Screen_Sed_Open::create_drop_down(TPanel* param_1, TDropDownPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * protected: virtual int __thiscall TEasy_Panel::create_drop_down(class TPanel *,class TDropDownPane... *
    //                              *********************************************************************************************************
    //                              int __thiscall create_drop_down(TEasy_Panel * this, TPanel * param_1
    //              int               EAX:4          <RETURN>
    //              TEasy_Panel *     ECX:4 (auto)   this
    //              TPanel *          Stack[0x4]:4   param_1                   XREF[1]:     0046953d(R)  
    //              TDropDownPanel    Stack[0x8]:4   param_2                   XREF[1]:     004694bd(R)  
    //              long              Stack[0xc]:4   param_3                   XREF[2]:     004693f4(R), 004694a2(W)  
    //              long              Stack[0x10]:4  param_4                   XREF[1]:     00469402(R)  
    //              long              Stack[0x14]:4  param_5                   XREF[4]:     00469398(R), 00469438(W), 004694f1(R), 0046965a(R)  
    //              long              Stack[0x18]:4  param_6                   XREF[3]:     004693be(R), 004693f0(W), 004694ed(R)  
    //              long              Stack[0x1c]:4  param_7                   XREF[3]:     004693cc(R), 00469412(W), 00469503(R)  
    //              long              Stack[0x20]:4  param_8                   XREF[3]:     004693da(R), 004693fe(W), 00469508(R)  
    //              long              Stack[0x24]:4  param_9                   XREF[1]:     0046940c(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     004694a8(W), 004694c1(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     00469696(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[2]:     004693ba(W), 00469523(R)  
    //              long              Stack[-0x14]:4 ideal_x                   XREF[2]:     004693c8(W), 0046951e(R)  
    //              long              Stack[-0x18]:4 ideal_y                   XREF[2]:     004693d6(W), 00469515(R)  
    //              long              Stack[-0x1c]:4 ideal_w                   XREF[2]:     004693e4(W), 0046950d(R)  
    //              long              Stack[-0x20]:4 ideal_h
    //                               ?create_drop_down@TEasy_Panel@@MAEHPAVTPanel@@PAPAVTDropDow  XREF[61]:    TRIBE_Campaign_Editor_Screen:0048f
    //                               TEasy_Panel::create_drop_down                                             TRIBE_Screen_Campaign_Selection:00
    //                                                                                                         TribeMPSetupScreen:004a0335(c), 
    //                                                                                                         TribeMPSetupScreen:004a03ca(c), 
    //                                                                                                         TribeMPSetupScreen:004a0506(c), 
    //                                                                                                         TribeMPSetupScreen:004a09b4(c), 
    //                                                                                                         create_drop_down:004a8bcb(c), 
    //                                                                                                         TribeGameSettingsScreen:004b49dd(c
    //                                                                                                         TribeGameSettingsScreen:004b4aac(c
    //                                                                                                         TribeGameSettingsScreen:004b4b9f(c
    //                                                                                                         TribeGameSettingsScreen:004b4c6c(c
    //                                                                                                         TribeGameSettingsScreen:004b4d58(c
    //                                                                                                         TribeGameSettingsScreen:004b4f35(c
    //                                                                                                         TribeGameSettingsScreen:004b5004(c
    //                                                                                                         TribeGameSettingsScreen:004b50a9(c
    //                                                                                                         TribeGameSettingsScreen:004b5161(c
    //                                                                                                         TribeGameSettingsScreen:004b520c(c
    //                                                                                                         0056f71c(*), 0056f85c(*), 
    //                                                                                                         0056f9a4(*), [more]
    //                              Panel_ez.cpp:1445 (24)
    //         00469380     PUSH       -0x1
    //         00469382     PUSH       FUN_0055e06b
    //         00469387     MOV        EAX,FS:[0x0]
    //         0046938d     PUSH       EAX
    //         0046938e     MOV        dword ptr FS:[0x0],ESP
    //         00469395     SUB        ESP,0x10
    //                              Panel_ez.cpp:1451 (25)
    //         00469398     MOV        EAX,dword ptr [ESP + param_5]
    //         0046939c     PUSH       EBX
    //         0046939d     MOV        EBX,this
    //         0046939f     PUSH       EBP
    //         004693a0     PUSH       ESI
    //         004693a1     PUSH       EDI
    //         004693a2     MOV        this,dword ptr [EBX + 0x14]
    //         004693a5     MOV        ESI,dword ptr [EBX + 0xf4]
    //         004693ab     IMUL       EAX,this
    //         004693ae     CDQ
    //         004693af     IDIV       ESI
    //                              Panel_ez.cpp:1452 (27)
    //         004693b1     MOV        EDI,dword ptr [EBX + 0x18]
    //         004693b4     MOV        EBP,dword ptr [EBX + 0xf8]
    //         004693ba     MOV        dword ptr [ESP + local_10],EAX
    //         004693be     MOV        EAX,dword ptr [ESP + param_6]
    //         004693c2     IMUL       EAX,EDI
    //         004693c5     CDQ
    //         004693c6     IDIV       EBP
    //         004693c8     MOV        dword ptr [ESP + ideal_x],EAX
    //                              Panel_ez.cpp:1453 (14)
    //         004693cc     MOV        EAX,dword ptr [ESP + param_7]
    //         004693d0     IMUL       EAX,this
    //         004693d3     CDQ
    //         004693d4     IDIV       ESI
    //         004693d6     MOV        dword ptr [ESP + ideal_y],EAX
    //                              Panel_ez.cpp:1454 (14)
    //         004693da     MOV        EAX,dword ptr [ESP + param_8]
    //         004693de     IMUL       EAX,EDI
    //         004693e1     CDQ
    //         004693e2     IDIV       EBP
    //         004693e4     MOV        dword ptr [ESP + ideal_w],EAX
    //                              Panel_ez.cpp:1455 (12)
    //         004693e8     LEA        EAX,[ECX + ECX*0x8]
    //         004693eb     SHL        EAX,0x1
    //         004693ed     CDQ
    //         004693ee     IDIV       ESI
    //         004693f0     MOV        dword ptr [ESP + param_6],EAX
    //                              Panel_ez.cpp:1456 (14)
    //         004693f4     MOV        EAX,dword ptr [ESP + param_3]
    //         004693f8     IMUL       EAX,this
    //         004693fb     CDQ
    //         004693fc     IDIV       ESI
    //         004693fe     MOV        dword ptr [ESP + param_8],EAX
    //                              Panel_ez.cpp:1457 (10)
    //         00469402     MOV        EAX,dword ptr [ESP + param_4]
    //         00469406     IMUL       EAX,EDI
    //         00469409     CDQ
    //         0046940a     IDIV       EBP
    //                              Panel_ez.cpp:1460 (12)
    //         0046940c     MOV        EBP,dword ptr [ESP + param_9]
    //         00469410     TEST       EBP,EBP
    //         00469412     MOV        dword ptr [ESP + param_7],EAX
    //         00469416     JL         LAB_0046941b
    //                              Panel_ez.cpp:1461 (1)
    //         00469418     PUSH       EBP
    //                              Panel_ez.cpp:1462 (2)
    //         00469419     JMP        LAB_0046941d
    //                               LAB_0046941b                                                 XREF[1]:     00469416(j)  
    //                              Panel_ez.cpp:1463 (13)
    //         0046941b     PUSH       0xa
    //                               LAB_0046941d                                                 XREF[1]:     00469419(j)  
    //         0046941d     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         00469423     CALL       RGE_Base_Game::get_font                          RGE_Font * get_font(RGE_Base_Game * this, int
    //                              Panel_ez.cpp:1469 (14)
    //         00469428     PUSH       0x4
    //         0046942a     PUSH       0x1
    //         0046942c     CALL       calloc                                           undefined calloc()
    //         00469431     MOV        ESI,EAX
    //         00469433     ADD        ESP,0x8
    //                              Panel_ez.cpp:1470 (8)
    //         00469436     TEST       ESI,ESI
    //         00469438     MOV        dword ptr [ESP + param_5],ESI
    //         0046943c     JNZ        LAB_0046944d
    //                              Panel_ez.cpp:1472 (10)
    //         0046943e     MOV        dword ptr [EBX + 0xd8],0x1
    //                              Panel_ez.cpp:1473 (5)
    //         00469448     JMP        LAB_00469696
    //                               LAB_0046944d                                                 XREF[1]:     0046943c(j)  
    //                              Panel_ez.cpp:1475 (14)
    //         0046944d     PUSH       0x1
    //         0046944f     PUSH       0x14
    //         00469451     CALL       calloc                                           undefined calloc()
    //         00469456     MOV        EDX,EAX
    //         00469458     ADD        ESP,0x8
    //                              Panel_ez.cpp:1476 (10)
    //         0046945b     TEST       EDX,EDX
    //         0046945d     MOV        dword ptr [ESI],EDX
    //         0046945f     JZ         LAB_00469696
    //                              Panel_ez.cpp:1478 (34)
    //         00469465     MOV        EDI,s__                                          = 20h
    //         0046946a     OR         this,0xffffffff
    //         0046946d     XOR        EAX,EAX
    //         0046946f     SCASB.RE   ES:EDI=>s__                                      = 20h
    //         00469471     NOT        this
    //         00469473     SUB        EDI,this
    //         00469475     MOV        EAX,this
    //         00469477     MOV        ESI,EDI
    //         00469479     MOV        EDI,EDX
    //         0046947b     SHR        this,0x2
    //         0046947e     MOVSD.REP  ES:EDI,ESI
    //         00469480     MOV        this,EAX
    //         00469482     AND        this,0x3
    //         00469485     MOVSB.REP  ES:EDI,ESI
    //                              Panel_ez.cpp:1481 (14)
    //         00469487     MOV        EAX,dword ptr [EBX + 0xd8]
    //         0046948d     TEST       EAX,EAX
    //         0046948f     JNZ        LAB_0046965a
    //                              Panel_ez.cpp:1483 (52)
    //         00469495     PUSH       0x144
    //         0046949a     CALL       operator_new                                     void * operator_new(uint param_1)
    //         0046949f     ADD        ESP,0x4
    //         004694a2     MOV        dword ptr [ESP + param_3],EAX
    //         004694a6     TEST       EAX,EAX
    //         004694a8     MOV        dword ptr [ESP + local_4],0x0
    //         004694b0     JZ         LAB_004694bb
    //         004694b2     MOV        this,EAX
    //         004694b4     CALL       TDropDownPanel::TDropDownPanel                   undefined TDropDownPanel(TDropDownPanel * this)
    //         004694b9     JMP        LAB_004694bd
    //                               LAB_004694bb                                                 XREF[1]:     004694b0(j)  
    //         004694bb     XOR        EAX,EAX
    //                               LAB_004694bd                                                 XREF[1]:     004694b9(j)  
    //         004694bd     MOV        ESI,dword ptr [ESP + param_2]
    //         004694c1     MOV        dword ptr [ESP + local_4],0xffffffff
    //                              Panel_ez.cpp:1484 (24)
    //         004694c9     TEST       EAX,EAX
    //         004694cb     MOV        dword ptr [ESI],EAX
    //         004694cd     JZ         LAB_00469650
    //         004694d3     MOV        this,dword ptr [EAX + 0xd8]
    //         004694d9     TEST       this,this
    //         004694db     JNZ        LAB_00469650
    //                              Panel_ez.cpp:1486 (12)
    //         004694e1     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004694e7     PUSH       EBP
    //         004694e8     CALL       RGE_Base_Game::get_font                          RGE_Font * get_font(RGE_Base_Game * this, int
    //                              Panel_ez.cpp:1492 (109)
    //         004694ed     MOV        this,dword ptr [ESP + param_6]
    //         004694f1     MOV        EDX,dword ptr [ESP + param_5]
    //         004694f5     PUSH       this
    //         004694f6     PUSH       this
    //         004694f7     PUSH       0x0
    //         004694f9     PUSH       0x0
    //         004694fb     PUSH       0x0
    //         004694fd     PUSH       0x0
    //         004694ff     PUSH       this
    //         00469500     PUSH       0x1
    //         00469502     PUSH       EDX
    //         00469503     MOV        EDX,dword ptr [ESP + param_7]
    //         00469507     PUSH       EDX
    //         00469508     MOV        EDX,dword ptr [ESP + param_8]
    //         0046950c     PUSH       EDX
    //         0046950d     MOV        EDX,dword ptr [ESP + ideal_w]
    //         00469511     PUSH       0x0
    //         00469513     PUSH       EDX
    //         00469514     PUSH       this
    //         00469515     MOV        this,dword ptr [ESP + ideal_y]
    //         00469519     PUSH       0x0
    //         0046951b     PUSH       0x0
    //         0046951d     PUSH       EDX
    //         0046951e     MOV        EDX,dword ptr [ESP + ideal_x]
    //         00469522     PUSH       this
    //         00469523     MOV        this,dword ptr [ESP + local_10]
    //         00469527     PUSH       EDX
    //         00469528     MOV        EDX,dword ptr [EAX + 0x8]
    //         0046952b     PUSH       this
    //         0046952c     MOV        this,dword ptr [EAX + 0x4]
    //         0046952f     PUSH       0xff
    //         00469534     PUSH       0x1
    //         00469536     PUSH       0x0
    //         00469538     PUSH       0x0
    //         0046953a     PUSH       EDX
    //         0046953b     MOV        EDX,dword ptr [EAX]
    //         0046953d     MOV        EAX,dword ptr [ESP + param_1]
    //         00469544     PUSH       this
    //         00469545     MOV        this,dword ptr [EBX + 0x20]
    //         00469548     PUSH       EDX
    //         00469549     PUSH       EAX
    //         0046954a     PUSH       this
    //         0046954b     MOV        this,dword ptr [ESI]
    //         0046954d     CALL       TDropDownPanel::setup                            long setup(TDropDownPanel * this, TDrawArea *
    //         00469552     TEST       EAX,EAX
    //         00469554     JZ         LAB_00469650
    //                              Panel_ez.cpp:1495 (10)
    //         0046955a     MOV        EAX,dword ptr [EBX + 0x448]
    //         00469560     TEST       EAX,EAX
    //         00469562     JZ         LAB_00469576
    //                              Panel_ez.cpp:1496 (18)
    //         00469564     MOV        this,dword ptr [ESI]
    //         00469566     PUSH       0xc
    //         00469568     PUSH       0xa
    //         0046956a     PUSH       0x8
    //         0046956c     PUSH       -0x1
    //         0046956e     PUSH       0xe
    //         00469570     PUSH       EAX
    //         00469571     CALL       TDropDownPanel::set_buttons                      void set_buttons(TDropDownPanel * this, TShap
    //                               LAB_00469576                                                 XREF[1]:     00469562(j)  
    //                              Panel_ez.cpp:1498 (10)
    //         00469576     MOV        EAX,dword ptr [EBX + 0x31c]
    //         0046957c     TEST       EAX,EAX
    //         0046957e     JZ         LAB_004695bf
    //                              Panel_ez.cpp:1499 (63)
    //         00469580     XOR        EDX,EDX
    //         00469582     XOR        EAX,EAX
    //         00469584     MOV        DL,byte ptr [EBX + 0x325]
    //         0046958a     MOV        AL,byte ptr [EBX + 0x324]
    //         00469590     XOR        this,this
    //         00469592     PUSH       EDX
    //         00469593     MOV        this,byte ptr [EBX + 0x323]
    //         00469599     PUSH       EAX
    //         0046959a     XOR        EDX,EDX
    //         0046959c     PUSH       this
    //         0046959d     MOV        DL,byte ptr [EBX + 0x322]
    //         004695a3     XOR        EAX,EAX
    //         004695a5     MOV        AL,byte ptr [EBX + 0x321]
    //         004695ab     XOR        this,this
    //         004695ad     MOV        this,byte ptr [EBX + 0x320]
    //         004695b3     PUSH       EDX
    //         004695b4     PUSH       EAX
    //         004695b5     PUSH       this
    //         004695b6     MOV        this,dword ptr [ESI]
    //         004695b8     PUSH       0x3
    //         004695ba     CALL       TDropDownPanel::set_bevel_info                   void set_bevel_info(TDropDownPanel * this, in
    //                               LAB_004695bf                                                 XREF[1]:     0046957e(j)  
    //                              Panel_ez.cpp:1501 (21)
    //         004695bf     MOV        EDX,dword ptr [EBX + 0x32c]
    //         004695c5     MOV        EAX,dword ptr [EBX + 0x328]
    //         004695cb     MOV        this,dword ptr [ESI]
    //         004695cd     PUSH       EDX
    //         004695ce     PUSH       EAX
    //         004695cf     CALL       TDropDownPanel::set_val_text_color               void set_val_text_color(TDropDownPanel * this
    //                              Panel_ez.cpp:1503 (2)
    //         004695d4     MOV        this,dword ptr [ESI]
    //                              Panel_ez.cpp:1504 (27)
    //         004695d6     MOV        EDX,dword ptr [EBX + 0x32c]
    //         004695dc     MOV        EAX,dword ptr [EBX + 0x328]
    //         004695e2     PUSH       EDX
    //         004695e3     MOV        EDI,dword ptr [ECX + this->info_file_name[0]]
    //         004695e9     PUSH       EAX
    //         004695ea     MOV        this,EDI
    //         004695ec     CALL       TTextPanel::set_text_color                       void set_text_color(TTextPanel * this, ulong 
    //                              Panel_ez.cpp:1505 (21)
    //         004695f1     MOV        this,dword ptr [EBX + 0x334]
    //         004695f7     MOV        EDX,dword ptr [EBX + 0x330]
    //         004695fd     PUSH       this
    //         004695fe     PUSH       EDX
    //         004695ff     MOV        this,EDI
    //         00469601     CALL       TTextPanel::set_highlight_text_color             void set_highlight_text_color(TTextPanel * th
    //                              Panel_ez.cpp:1507 (72)
    //         00469606     MOV        EAX,dword ptr [ESI]
    //         00469608     MOV        this,dword ptr [EAX + 0xf4]
    //         0046960e     XOR        EAX,EAX
    //         00469610     MOV        AL,byte ptr [EBX + 0x325]
    //         00469616     PUSH       EAX
    //         00469617     XOR        EAX,EAX
    //         00469619     MOV        AL,byte ptr [EBX + 0x324]
    //         0046961f     MOV        EDX,dword ptr [this->_padding_]
    //         00469621     PUSH       EAX
    //         00469622     XOR        EAX,EAX
    //         00469624     MOV        AL,byte ptr [EBX + 0x323]
    //         0046962a     PUSH       EAX
    //         0046962b     XOR        EAX,EAX
    //         0046962d     MOV        AL,byte ptr [EBX + 0x322]
    //         00469633     PUSH       EAX
    //         00469634     XOR        EAX,EAX
    //         00469636     MOV        AL,byte ptr [EBX + 0x321]
    //         0046963c     PUSH       EAX
    //         0046963d     XOR        EAX,EAX
    //         0046963f     MOV        AL,byte ptr [EBX + 0x320]
    //         00469645     PUSH       EAX
    //         00469646     PUSH       0x3
    //         00469648     CALL       dword ptr [EDX + 0xec]
    //                              Panel_ez.cpp:1509 (2)
    //         0046964e     JMP        LAB_0046965a
    //                               LAB_00469650                                                 XREF[3]:     004694cd(j), 004694db(j), 
    //                                                                                                         00469554(j)  
    //                              Panel_ez.cpp:1513 (10)
    //         00469650     MOV        dword ptr [EBX + 0xd8],0x1
    //                               LAB_0046965a                                                 XREF[2]:     0046948f(j), 0046964e(j)  
    //                              Panel_ez.cpp:1534 (81)
    //         0046965a     MOV        EBP,dword ptr [ESP + param_5]
    //         0046965e     MOV        EDI,0x1
    //         00469663     MOV        ESI,EBP
    //                               LAB_00469665                                                 XREF[1]:     0046967e(j)  
    //         00469665     MOV        EAX,dword ptr [ESI]
    //         00469667     TEST       EAX,EAX
    //         00469669     JZ         LAB_0046967a
    //         0046966b     PUSH       EAX
    //         0046966c     CALL       free                                             undefined free()
    //         00469671     ADD        ESP,0x4
    //         00469674     MOV        dword ptr [ESI],0x0
    //                               LAB_0046967a                                                 XREF[1]:     00469669(j)  
    //         0046967a     ADD        ESI,0x4
    //         0046967d     DEC        EDI
    //         0046967e     JNZ        LAB_00469665
    //         00469680     PUSH       EBP
    //         00469681     CALL       free                                             undefined free()
    //         00469686     MOV        this,dword ptr [EBX + 0xd8]
    //         0046968c     ADD        ESP,0x4
    //         0046968f     XOR        EAX,EAX
    //         00469691     TEST       this,this
    //         00469693     SETZ       AL
    //                               LAB_00469696                                                 XREF[2]:     00469448(j), 0046945f(j)  
    //         00469696     MOV        this,dword ptr [ESP + local_c]
    //         0046969a     POP        EDI
    //         0046969b     POP        ESI
    //         0046969c     POP        EBP
    //         0046969d     MOV        dword ptr FS:[0x0],this
    //         004696a4     POP        EBX
    //         004696a5     ADD        ESP,0x1c
    //         004696a8     RET        0x24
}

// Offset: 0x004696B0
int TRIBE_Screen_Sed_Open::create_list(TPanel* param_1, TListPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * protected: virtual int __thiscall TEasy_Panel::create_list(class TPanel *,class TListPanel * *,lon... *
    //                              *********************************************************************************************************
    //                              int __thiscall create_list(TEasy_Panel * this, TPanel * param_1, TLi
    //              int               EAX:4          <RETURN>
    //              TEasy_Panel *     ECX:4 (auto)   this
    //              TPanel *          Stack[0x4]:4   param_1                   XREF[1]:     00469820(R)  
    //              TListPanel * *    Stack[0x8]:4   param_2                   XREF[1]:     00469795(R)  
    //              long              Stack[0xc]:4   param_3                   XREF[5]:     004696c8(R), 00469740(W), 004697ed(R), 0046984f(R), 
    //                                                                                     00469873(R)  
    //              long              Stack[0x10]:4  param_4                   XREF[3]:     004696ee(R), 0046971a(W), 0046980c(R)  
    //              long              Stack[0x14]:4  param_5                   XREF[3]:     004696fc(R), 00469706(W), 00469811(R)  
    //              long              Stack[0x18]:4  param_6                   XREF[2]:     0046970a(R), 004697ae(W)  
    //              long              Stack[0x1c]:4  param_7                   XREF[1]:     00469714(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     004697b4(W), 004697cb(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     004698fb(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[2]:     004696ea(W), 0046981b(R)  
    //              long              Stack[-0x14]:4 ideal_x                   XREF[2]:     004696f8(W), 00469816(R)  
    //              long              Stack[-0x18]:4 ideal_y
    //                               ?create_list@TEasy_Panel@@MAEHPAVTPanel@@PAPAVTListPanel@@J  XREF[57]:    TRIBE_Campaign_Editor_Screen:0048f
    //                               TEasy_Panel::create_list                                                  TRIBE_Campaign_Editor_Screen:0048f
    //                                                                                                         TRIBE_Screen_Campaign_Selection:00
    //                                                                                                         TRIBE_Screen_Campaign_Selection:00
    //                                                                                                         TribeJoinScreen:00491799(c), 
    //                                                                                                         TribeLoadSavedGameScreen:0049dec2(
    //                                                                                                         TribeMPStartupScreen:0049f55f(c), 
    //                                                                                                         TRIBE_Screen_Name:004a64ea(c), 
    //                                                                                                         TribeSaveGameScreen:004a740b(c), 
    //                                                                                                         create_list:004a93dc(c), 
    //                                                                                                         TRIBE_Screen_Sed_Open:004b3519(c), 
    //                                                                                                         TribeSelectScenarioScreen:004b3dc7
    //                                                                                                         TribeGameSettingsScreen:004b5498(c
    //                                                                                                         0056f720(*), 0056f860(*), 
    //                                                                                                         0056f9a8(*), 0056fad8(*), 
    //                                                                                                         0056fc08(*), 0056fd40(*), 
    //                                                                                                         0056fe70(*), [more]
    //                              Panel_ez.cpp:1540 (24)
    //         004696b0     PUSH       -0x1
    //         004696b2     PUSH       FUN_0055e08b
    //         004696b7     MOV        EAX,FS:[0x0]
    //         004696bd     PUSH       EAX
    //         004696be     MOV        dword ptr FS:[0x0],ESP
    //         004696c5     SUB        ESP,0x8
    //                              Panel_ez.cpp:1546 (25)
    //         004696c8     MOV        EAX,dword ptr [ESP + param_3]
    //         004696cc     PUSH       EBX
    //         004696cd     MOV        EBX,this
    //         004696cf     PUSH       EBP
    //         004696d0     PUSH       ESI
    //         004696d1     PUSH       EDI
    //         004696d2     MOV        this,dword ptr [EBX + 0x14]
    //         004696d5     MOV        ESI,dword ptr [EBX + 0xf4]
    //         004696db     IMUL       EAX,this
    //         004696de     CDQ
    //         004696df     IDIV       ESI
    //                              Panel_ez.cpp:1547 (27)
    //         004696e1     MOV        EDI,dword ptr [EBX + 0x18]
    //         004696e4     MOV        EBP,dword ptr [EBX + 0xf8]
    //         004696ea     MOV        dword ptr [ESP + local_10],EAX
    //         004696ee     MOV        EAX,dword ptr [ESP + param_4]
    //         004696f2     IMUL       EAX,EDI
    //         004696f5     CDQ
    //         004696f6     IDIV       EBP
    //         004696f8     MOV        dword ptr [ESP + ideal_x],EAX
    //                              Panel_ez.cpp:1548 (14)
    //         004696fc     MOV        EAX,dword ptr [ESP + param_5]
    //         00469700     IMUL       EAX,this
    //         00469703     CDQ
    //         00469704     IDIV       ESI
    //         00469706     MOV        dword ptr [ESP + param_5],EAX
    //                              Panel_ez.cpp:1549 (10)
    //         0046970a     MOV        EAX,dword ptr [ESP + param_6]
    //         0046970e     IMUL       EAX,EDI
    //         00469711     CDQ
    //         00469712     IDIV       EBP
    //                              Panel_ez.cpp:1551 (12)
    //         00469714     MOV        EBP,dword ptr [ESP + param_7]
    //         00469718     TEST       EBP,EBP
    //         0046971a     MOV        dword ptr [ESP + param_4],EAX
    //         0046971e     JL         LAB_00469723
    //                              Panel_ez.cpp:1552 (1)
    //         00469720     PUSH       EBP
    //                              Panel_ez.cpp:1553 (2)
    //         00469721     JMP        LAB_00469725
    //                               LAB_00469723                                                 XREF[1]:     0046971e(j)  
    //                              Panel_ez.cpp:1554 (13)
    //         00469723     PUSH       0xa
    //                               LAB_00469725                                                 XREF[1]:     00469721(j)  
    //         00469725     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0046972b     CALL       RGE_Base_Game::get_font                          RGE_Font * get_font(RGE_Base_Game * this, int
    //                              Panel_ez.cpp:1560 (14)
    //         00469730     PUSH       0x4
    //         00469732     PUSH       0x1
    //         00469734     CALL       calloc                                           undefined calloc()
    //         00469739     MOV        ESI,EAX
    //         0046973b     ADD        ESP,0x8
    //                              Panel_ez.cpp:1561 (8)
    //         0046973e     TEST       ESI,ESI
    //         00469740     MOV        dword ptr [ESP + param_3],ESI
    //         00469744     JNZ        LAB_00469755
    //                              Panel_ez.cpp:1563 (10)
    //         00469746     MOV        dword ptr [EBX + 0xd8],0x1
    //                              Panel_ez.cpp:1564 (5)
    //         00469750     JMP        LAB_004698fb
    //                               LAB_00469755                                                 XREF[1]:     00469744(j)  
    //                              Panel_ez.cpp:1566 (14)
    //         00469755     PUSH       0x1
    //         00469757     PUSH       0x14
    //         00469759     CALL       calloc                                           undefined calloc()
    //         0046975e     MOV        EDX,EAX
    //         00469760     ADD        ESP,0x8
    //                              Panel_ez.cpp:1567 (10)
    //         00469763     TEST       EDX,EDX
    //         00469765     MOV        dword ptr [ESI],EDX
    //         00469767     JZ         LAB_004698fb
    //                              Panel_ez.cpp:1569 (34)
    //         0046976d     MOV        EDI,s__                                          = 20h
    //         00469772     OR         this,0xffffffff
    //         00469775     XOR        EAX,EAX
    //         00469777     SCASB.RE   ES:EDI=>s__                                      = 20h
    //         00469779     NOT        this
    //         0046977b     SUB        EDI,this
    //         0046977d     MOV        EAX,this
    //         0046977f     MOV        ESI,EDI
    //         00469781     MOV        EDI,EDX
    //         00469783     SHR        this,0x2
    //         00469786     MOVSD.REP  ES:EDI,ESI
    //         00469788     MOV        this,EAX
    //         0046978a     AND        this,0x3
    //         0046978d     MOVSB.REP  ES:EDI,ESI
    //                              Panel_ez.cpp:1572 (18)
    //         0046978f     MOV        EAX,dword ptr [EBX + 0xd8]
    //         00469795     MOV        EDI,dword ptr [ESP + param_2]
    //         00469799     TEST       EAX,EAX
    //         0046979b     JNZ        LAB_0046984f
    //                              Panel_ez.cpp:1574 (40)
    //         004697a1     PUSH       0x1a0
    //         004697a6     CALL       operator_new                                     void * operator_new(uint param_1)
    //         004697ab     ADD        ESP,0x4
    //         004697ae     MOV        dword ptr [ESP + param_6],EAX
    //         004697b2     TEST       EAX,EAX
    //         004697b4     MOV        dword ptr [ESP + local_4],0x0
    //         004697bc     JZ         LAB_004697c7
    //         004697be     MOV        this,EAX
    //         004697c0     CALL       TListPanel::TListPanel                           undefined TListPanel(TListPanel * this)
    //         004697c5     JMP        LAB_004697c9
    //                               LAB_004697c7                                                 XREF[1]:     004697bc(j)  
    //         004697c7     XOR        EAX,EAX
    //                               LAB_004697c9                                                 XREF[1]:     004697c5(j)  
    //                              Panel_ez.cpp:1575 (24)
    //         004697c9     TEST       EAX,EAX
    //         004697cb     MOV        dword ptr [ESP + local_4],0xffffffff
    //         004697d3     MOV        dword ptr [EDI],EAX
    //         004697d5     JZ         LAB_00469845
    //         004697d7     MOV        this,dword ptr [EAX + 0xd8]
    //         004697dd     TEST       this,this
    //         004697df     JNZ        LAB_00469845
    //                              Panel_ez.cpp:1577 (12)
    //         004697e1     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004697e7     PUSH       EBP
    //         004697e8     CALL       RGE_Base_Game::get_font                          RGE_Font * get_font(RGE_Base_Game * this, int
    //                              Panel_ez.cpp:1579 (73)
    //         004697ed     MOV        this,dword ptr [ESP + param_3]
    //         004697f1     MOV        EDX,dword ptr [EAX + 0x8]
    //         004697f4     PUSH       0x1
    //         004697f6     PUSH       this
    //         004697f7     MOV        this,dword ptr [EAX + 0x4]
    //         004697fa     PUSH       0x0
    //         004697fc     PUSH       0xff
    //         00469801     PUSH       0x1
    //         00469803     PUSH       0x0
    //         00469805     PUSH       0x0
    //         00469807     PUSH       0x0
    //         00469809     PUSH       EDX
    //         0046980a     MOV        EDX,dword ptr [EAX]
    //         0046980c     MOV        EAX,dword ptr [ESP + param_4]
    //         00469810     PUSH       this
    //         00469811     MOV        this,dword ptr [ESP + param_5]
    //         00469815     PUSH       EDX
    //         00469816     MOV        EDX,dword ptr [ESP + ideal_x]
    //         0046981a     PUSH       EAX
    //         0046981b     MOV        EAX,dword ptr [ESP + local_10]
    //         0046981f     PUSH       this
    //         00469820     MOV        this,dword ptr [ESP + param_1]
    //         00469824     PUSH       EDX
    //         00469825     MOV        EDX,dword ptr [EBX + 0x20]
    //         00469828     PUSH       EAX
    //         00469829     PUSH       this
    //         0046982a     MOV        this,dword ptr [EDI]
    //         0046982c     PUSH       EDX
    //         0046982d     CALL       TTextPanel::setup                                long setup(TTextPanel * this, TDrawArea * par
    //         00469832     TEST       EAX,EAX
    //         00469834     JZ         LAB_00469845
    //                              Panel_ez.cpp:1580 (13)
    //         00469836     MOV        this,dword ptr [EDI]
    //         00469838     PUSH       0x1
    //         0046983a     PUSH       0x0
    //         0046983c     PUSH       0x1
    //         0046983e     CALL       TListPanel::scroll_cur_line                      void scroll_cur_line(TListPanel * this, uchar
    //                              Panel_ez.cpp:1581 (2)
    //         00469843     JMP        LAB_0046984f
    //                               LAB_00469845                                                 XREF[3]:     004697d5(j), 004697df(j), 
    //                                                                                                         00469834(j)  
    //                              Panel_ez.cpp:1585 (10)
    //         00469845     MOV        dword ptr [EBX + 0xd8],0x1
    //                               LAB_0046984f                                                 XREF[2]:     0046979b(j), 00469843(j)  
    //                              Panel_ez.cpp:1610 (193)
    //         0046984f     MOV        ESI,dword ptr [ESP + param_3]
    //         00469853     MOV        EBP,0x1
    //                               LAB_00469858                                                 XREF[1]:     00469871(j)  
    //         00469858     MOV        EAX,dword ptr [ESI]
    //         0046985a     TEST       EAX,EAX
    //         0046985c     JZ         LAB_0046986d
    //         0046985e     PUSH       EAX
    //         0046985f     CALL       free                                             undefined free()
    //         00469864     ADD        ESP,0x4
    //         00469867     MOV        dword ptr [ESI],0x0
    //                               LAB_0046986d                                                 XREF[1]:     0046985c(j)  
    //         0046986d     ADD        ESI,0x4
    //         00469870     DEC        EBP
    //         00469871     JNZ        LAB_00469858
    //         00469873     MOV        EAX,dword ptr [ESP + param_3]
    //         00469877     PUSH       EAX
    //         00469878     CALL       free                                             undefined free()
    //         0046987d     MOV        EAX,dword ptr [EBX + 0x31c]
    //         00469883     ADD        ESP,0x4
    //         00469886     TEST       EAX,EAX
    //         00469888     JZ         LAB_004698cc
    //         0046988a     XOR        EAX,EAX
    //         0046988c     MOV        this,dword ptr [EDI]
    //         0046988e     MOV        AL,byte ptr [EBX + 0x325]
    //         00469894     PUSH       EAX
    //         00469895     XOR        EAX,EAX
    //         00469897     MOV        AL,byte ptr [EBX + 0x324]
    //         0046989d     MOV        EDX,dword ptr [this->_padding_]
    //         0046989f     PUSH       EAX
    //         004698a0     XOR        EAX,EAX
    //         004698a2     MOV        AL,byte ptr [EBX + 0x323]
    //         004698a8     PUSH       EAX
    //         004698a9     XOR        EAX,EAX
    //         004698ab     MOV        AL,byte ptr [EBX + 0x322]
    //         004698b1     PUSH       EAX
    //         004698b2     XOR        EAX,EAX
    //         004698b4     MOV        AL,byte ptr [EBX + 0x321]
    //         004698ba     PUSH       EAX
    //         004698bb     XOR        EAX,EAX
    //         004698bd     MOV        AL,byte ptr [EBX + 0x320]
    //         004698c3     PUSH       EAX
    //         004698c4     PUSH       0x3
    //         004698c6     CALL       dword ptr [EDX + 0xec]
    //                               LAB_004698cc                                                 XREF[1]:     00469888(j)  
    //         004698cc     MOV        this,dword ptr [EBX + 0x32c]
    //         004698d2     MOV        EDX,dword ptr [EBX + 0x328]
    //         004698d8     PUSH       this
    //         004698d9     MOV        this,dword ptr [EDI]
    //         004698db     PUSH       EDX=>DAT_fffffff8
    //         004698dc     CALL       TTextPanel::set_text_color                       void set_text_color(TTextPanel * this, ulong 
    //         004698e1     MOV        EAX,dword ptr [EBX + 0x334]
    //         004698e7     MOV        this,dword ptr [EBX + 0x330]
    //         004698ed     PUSH       EAX
    //         004698ee     PUSH       this=>DAT_fffffff8
    //         004698ef     MOV        this,dword ptr [EDI]
    //         004698f1     CALL       TTextPanel::set_highlight_text_color             void set_highlight_text_color(TTextPanel * th
    //         004698f6     MOV        EAX,0x1
    //                               LAB_004698fb                                                 XREF[2]:     00469750(j), 00469767(j)  
    //         004698fb     MOV        this,dword ptr [ESP + local_c]
    //         004698ff     POP        EDI
    //         00469900     POP        ESI
    //         00469901     POP        EBP
    //         00469902     MOV        dword ptr FS:[0x0],this
    //         00469909     POP        EBX
    //         0046990a     ADD        ESP,0x14
    //         0046990d     RET        0x1c
}

// Offset: 0x00469910
int TRIBE_Screen_Sed_Open::create_scrollbar(TPanel* param_1, TScrollBarPanel** param_2, TTextPanel* param_3, long param_4, long param_5, long param_6, long param_7, long param_8) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * protected: virtual int __thiscall TEasy_Panel::create_scrollbar(class TPanel *,class TScrollBarPan... *
    //                              *********************************************************************************************************
    //                              int __thiscall create_scrollbar(TEasy_Panel * this, TPanel * param_1
    //              int               EAX:4          <RETURN>
    //              TEasy_Panel *     ECX:4 (auto)   this
    //              TPanel *          Stack[0x4]:4   param_1                   XREF[1]:     004699ca(R)  
    //              TScrollBarPane    Stack[0x8]:4   param_2                   XREF[3]:     00469987(R), 004699e9(R), 004699fb(R)  
    //              TTextPanel *      Stack[0xc]:4   param_3                   XREF[1]:     004699af(R)  
    //              long              Stack[0x10]:4  param_4                   XREF[1]:     004699ab(R)  
    //              long              Stack[0x14]:4  param_5                   XREF[3]:     00469936(R), 00469960(W), 004699b5(R)  
    //              long              Stack[0x18]:4  param_6                   XREF[2]:     0046994a(R), 0046996c(W)  
    //              long              Stack[0x1c]:4  param_7                   XREF[1]:     004699ba(R)  
    //              long              Stack[0x20]:4  param_8                   XREF[1]:     00469956(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     00469972(W), 0046998b(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     00469a6b(R)  
    //                               ?create_scrollbar@TEasy_Panel@@MAEHPAVTPanel@@PAPAVTScrollB  XREF[44]:    0056f724(*), 0056f864(*), 
    //                               TEasy_Panel::create_scrollbar                                             0056f9ac(*), 0056fadc(*), 
    //                                                                                                         0056fc0c(*), 0056fd44(*), 
    //                                                                                                         0056fe74(*), 0056ffa4(*), 
    //                                                                                                         005700d4(*), 00570204(*), 
    //                                                                                                         00570e2c(*), 005711c4(*), 
    //                                                                                                         00571a24(*), 00571e04(*), 
    //                                                                                                         00572294(*), 005723bc(*), 
    //                                                                                                         005724e4(*), 0057260c(*), 
    //                                                                                                         00572734(*), 00572864(*), [more]
    //                              Panel_ez.cpp:1616 (27)
    //         00469910     MOV        EAX,FS:[0x0]
    //         00469916     PUSH       -0x1
    //         00469918     PUSH       FUN_0055e0ab
    //         0046991d     PUSH       EAX
    //         0046991e     MOV        dword ptr FS:[0x0],ESP
    //         00469925     PUSH       EBX
    //         00469926     PUSH       EBP
    //         00469927     PUSH       ESI
    //         00469928     MOV        ESI,this
    //         0046992a     PUSH       EDI
    //                              Panel_ez.cpp:1622 (104)
    //         0046992b     PUSH       0x1c4
    //         00469930     MOV        EAX,dword ptr [ESI + 0x14]
    //         00469933     MOV        this,dword ptr [ESI + 0x18]
    //         00469936     IMUL       EAX,dword ptr [ESP + param_5]
    //         0046993b     CDQ
    //         0046993c     IDIV       dword ptr [ESI + 0xf4]
    //         00469942     MOV        EDI,dword ptr [ESI + 0xf8]
    //         00469948     MOV        EBX,EAX
    //         0046994a     MOV        EAX,dword ptr [ESP + param_6]
    //         0046994e     IMUL       EAX,this
    //         00469951     CDQ
    //         00469952     IDIV       EDI
    //         00469954     MOV        EBP,EAX
    //         00469956     MOV        EAX,dword ptr [ESP + param_8]
    //         0046995a     IMUL       EAX,this
    //         0046995d     CDQ
    //         0046995e     IDIV       EDI
    //         00469960     MOV        dword ptr [ESP + param_5],EAX
    //         00469964     CALL       operator_new                                     void * operator_new(uint param_1)
    //         00469969     ADD        ESP,0x4
    //         0046996c     MOV        dword ptr [ESP + param_6],EAX
    //         00469970     TEST       EAX,EAX
    //         00469972     MOV        dword ptr [ESP + local_4],0x0
    //         0046997a     JZ         LAB_00469985
    //         0046997c     MOV        this,EAX
    //         0046997e     CALL       TScrollBarPanel::TScrollBarPanel                 undefined TScrollBarPanel(TScrollBarPanel * t
    //         00469983     JMP        LAB_00469987
    //                               LAB_00469985                                                 XREF[1]:     0046997a(j)  
    //         00469985     XOR        EAX,EAX
    //                               LAB_00469987                                                 XREF[1]:     00469983(j)  
    //         00469987     MOV        this,dword ptr [ESP + param_2]
    //         0046998b     MOV        dword ptr [ESP + local_4],0xffffffff
    //                              Panel_ez.cpp:1623 (24)
    //         00469993     TEST       EAX,EAX
    //         00469995     MOV        dword ptr [this->_padding_],EAX
    //         00469997     JZ         LAB_00469a69
    //         0046999d     MOV        this,dword ptr [EAX + 0xd8]
    //         004699a3     TEST       this,this
    //         004699a5     JNZ        LAB_00469a69
    //                              Panel_ez.cpp:1627 (52)
    //         004699ab     MOV        EDX,dword ptr [ESP + param_4]
    //         004699af     MOV        EDI,dword ptr [ESP + param_3]
    //         004699b3     PUSH       0x0
    //         004699b5     MOV        this,dword ptr [ESP + param_5]
    //         004699b9     PUSH       EDX
    //         004699ba     MOV        EDX,dword ptr [ESP + param_7]
    //         004699be     PUSH       EDI
    //         004699bf     PUSH       EDX
    //         004699c0     PUSH       EDX
    //         004699c1     PUSH       0x0
    //         004699c3     PUSH       0x0
    //         004699c5     PUSH       0x0
    //         004699c7     PUSH       0x0
    //         004699c9     PUSH       this
    //         004699ca     MOV        this,dword ptr [ESP + param_1]
    //         004699ce     PUSH       EDX
    //         004699cf     MOV        EDX,dword ptr [ESI + 0x20]
    //         004699d2     PUSH       EBP
    //         004699d3     PUSH       EBX
    //         004699d4     PUSH       this
    //         004699d5     PUSH       EDX
    //         004699d6     MOV        this,EAX
    //         004699d8     CALL       TScrollBarPanel::setup                           long setup(TScrollBarPanel * this, TDrawArea 
    //         004699dd     TEST       EAX,EAX
    //                              Panel_ez.cpp:1628 (6)
    //         004699df     JZ         LAB_00469a69
    //                              Panel_ez.cpp:1630 (4)
    //         004699e5     TEST       EDI,EDI
    //         004699e7     JZ         LAB_004699fb
    //                              Panel_ez.cpp:1631 (22)
    //         004699e9     MOV        EBX,dword ptr [ESP + param_2]
    //         004699ed     PUSH       0x0
    //         004699ef     MOV        this,EDI
    //         004699f1     MOV        EAX,dword ptr [EBX]
    //         004699f3     PUSH       EAX
    //         004699f4     CALL       TTextPanel::set_scrollbar                        void set_scrollbar(TTextPanel * this, TScroll
    //         004699f9     JMP        LAB_004699ff
    //                               LAB_004699fb                                                 XREF[1]:     004699e7(j)  
    //         004699fb     MOV        EBX,dword ptr [ESP + param_2]
    //                               LAB_004699ff                                                 XREF[1]:     004699f9(j)  
    //                              Panel_ez.cpp:1633 (10)
    //         004699ff     MOV        EAX,dword ptr [ESI + 0x448]
    //         00469a05     TEST       EAX,EAX
    //         00469a07     JZ         LAB_00469a19
    //                              Panel_ez.cpp:1634 (16)
    //         00469a09     MOV        this,dword ptr [EBX]
    //         00469a0b     PUSH       0xc
    //         00469a0d     PUSH       0xa
    //         00469a0f     PUSH       0x8
    //         00469a11     PUSH       -0x1
    //         00469a13     PUSH       EAX
    //         00469a14     CALL       TScrollBarPanel::set_buttons                     void set_buttons(TScrollBarPanel * this, TSha
    //                               LAB_00469a19                                                 XREF[1]:     00469a07(j)  
    //                              Panel_ez.cpp:1636 (10)
    //         00469a19     MOV        EAX,dword ptr [ESI + 0x31c]
    //         00469a1f     TEST       EAX,EAX
    //         00469a21     JZ         LAB_00469a62
    //                              Panel_ez.cpp:1637 (63)
    //         00469a23     XOR        this,this
    //         00469a25     XOR        EDX,EDX
    //         00469a27     MOV        this,byte ptr [ESI + 0x325]
    //         00469a2d     MOV        DL,byte ptr [ESI + 0x324]
    //         00469a33     XOR        EAX,EAX
    //         00469a35     PUSH       this
    //         00469a36     MOV        AL,byte ptr [ESI + 0x323]
    //         00469a3c     PUSH       EDX
    //         00469a3d     XOR        this,this
    //         00469a3f     PUSH       EAX
    //         00469a40     MOV        this,byte ptr [ESI + 0x322]
    //         00469a46     XOR        EDX,EDX
    //         00469a48     MOV        DL,byte ptr [ESI + 0x321]
    //         00469a4e     XOR        EAX,EAX
    //         00469a50     MOV        AL,byte ptr [ESI + 0x320]
    //         00469a56     PUSH       this
    //         00469a57     MOV        this,dword ptr [EBX]
    //         00469a59     PUSH       EDX
    //         00469a5a     PUSH       EAX
    //         00469a5b     PUSH       0x3
    //         00469a5d     CALL       TScrollBarPanel::set_bevel_info                  void set_bevel_info(TScrollBarPanel * this, i
    //                               LAB_00469a62                                                 XREF[1]:     00469a21(j)  
    //                              Panel_ez.cpp:1639 (7)
    //         00469a62     MOV        EAX,0x1
    //         00469a67     JMP        LAB_00469a6b
    //                               LAB_00469a69                                                 XREF[3]:     00469997(j), 004699a5(j), 
    //                                                                                                         004699df(j)  
    //                              Panel_ez.cpp:1624 (2)
    //         00469a69     XOR        EAX,EAX
    //                               LAB_00469a6b                                                 XREF[1]:     00469a67(j)  
    //                              Panel_ez.cpp:1640 (21)
    //         00469a6b     MOV        this,dword ptr [ESP + local_c]
    //         00469a6f     POP        EDI
    //         00469a70     POP        ESI
    //         00469a71     POP        EBP
    //         00469a72     MOV        dword ptr FS:[0x0],this
    //         00469a79     POP        EBX
    //         00469a7a     ADD        ESP,0xc
    //         00469a7d     RET        0x20
}

// Offset: 0x00469A80
int TRIBE_Screen_Sed_Open::create_auto_scrollbar(TScrollBarPanel** param_1, TTextPanel* param_2, long param_3) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * protected: virtual int __thiscall TEasy_Panel::create_auto_scrollbar(class TScrollBarPanel * *,cla... *
    //                              *********************************************************************************************************
    //                              int __thiscall create_auto_scrollbar(TEasy_Panel * this, TScrollBarP
    //              int               EAX:4          <RETURN>
    //              TEasy_Panel *     ECX:4 (auto)   this
    //              TScrollBarPane    Stack[0x4]:4   param_1                   XREF[1]:     00469a8c(R)  
    //              TTextPanel *      Stack[0x8]:4   param_2                   XREF[1]:     00469a85(R)  
    //              long              Stack[0xc]:4   param_3                   XREF[1]:     00469a80(R)  
    //                               ?create_auto_scrollbar@TEasy_Panel@@MAEHPAPAVTScrollBarPane  XREF[63]:    TribeAchievementsScreen:0048d8fd(c
    //                               TEasy_Panel::create_auto_scrollbar                                        TRIBE_Campaign_Editor_Screen:0048f
    //                                                                                                         TRIBE_Campaign_Editor_Screen:0048f
    //                                                                                                         TRIBE_Screen_Campaign_Selection:00
    //                                                                                                         TRIBE_Screen_Campaign_Selection:00
    //                                                                                                         TribeJoinScreen:004917b5(c), 
    //                                                                                                         TRIBE_Screen_Game:00495142(c), 
    //                                                                                                         TribeLoadSavedGameScreen:0049dedd(
    //                                                                                                         TribeMPStartupScreen:0049f57a(c), 
    //                                                                                                         TribeMPSetupScreen:004a08b4(c), 
    //                                                                                                         TRIBE_Screen_Name:004a6505(c), 
    //                                                                                                         TribeSaveGameScreen:004a7426(c), 
    //                                                                                                         create_list:004a940d(c), 
    //                                                                                                         TRIBE_Screen_Sed_Open:004b3534(c), 
    //                                                                                                         TribeSelectScenarioScreen:004b3e12
    //                                                                                                         TribeSelectScenarioScreen:004b3fb2
    //                                                                                                         TribeGameSettingsScreen:004b54fd(c
    //                                                                                                         TribeGameSettingsScreen:004b56c7(c
    //                                                                                                         TRIBE_Mission_Screen:004b82f1(c), 
    //                                                                                                         0056f728(*), [more]
    //                              Panel_ez.cpp:1646 (41)
    //         00469a80     MOV        EDX,dword ptr [ESP + param_3]
    //         00469a84     PUSH       ESI
    //         00469a85     MOV        ESI,dword ptr [ESP + param_2]
    //         00469a89     MOV        EAX,dword ptr [this->_padding_]
    //         00469a8b     PUSH       EDI
    //         00469a8c     MOV        EDI,dword ptr [ESP + param_1]
    //         00469a90     PUSH       0x0
    //         00469a92     PUSH       EDX
    //         00469a93     MOV        EDX,dword ptr [ESI + 0x40]
    //         00469a96     PUSH       0x0
    //         00469a98     PUSH       0x0
    //         00469a9a     PUSH       0x0
    //         00469a9c     PUSH       ESI
    //         00469a9d     PUSH       EDI
    //         00469a9e     PUSH       EDX
    //         00469a9f     CALL       dword ptr [EAX + 0x114]
    //         00469aa5     TEST       EAX,EAX
    //         00469aa7     JNZ        LAB_00469aae
    //                              Panel_ez.cpp:1651 (5)
    //         00469aa9     POP        EDI
    //         00469aaa     POP        ESI
    //         00469aab     RET        0xc
    //                               LAB_00469aae                                                 XREF[1]:     00469aa7(j)  
    //                              Panel_ez.cpp:1649 (12)
    //         00469aae     MOV        EAX,dword ptr [EDI]
    //         00469ab0     PUSH       0x1
    //         00469ab2     PUSH       EAX
    //         00469ab3     MOV        this,ESI
    //         00469ab5     CALL       TTextPanel::set_scrollbar                        void set_scrollbar(TTextPanel * this, TScroll
    //                              Panel_ez.cpp:1651 (10)
    //         00469aba     POP        EDI
    //         00469abb     MOV        EAX,0x1
    //         00469ac0     POP        ESI
    //         00469ac1     RET        0xc
}

// Offset: 0x00469AD0
int TRIBE_Screen_Sed_Open::create_vert_slider(TPanel* param_1, TVerticalSliderPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * protected: virtual int __thiscall TEasy_Panel::create_vert_slider(class TPanel *,class TVerticalSl... *
    //                              *********************************************************************************************************
    //                              int __thiscall create_vert_slider(TEasy_Panel * this, TPanel * param
    //              int               EAX:4          <RETURN>
    //              TEasy_Panel *     ECX:4 (auto)   this
    //              TPanel *          Stack[0x4]:4   param_1                   XREF[1]:     00469ba3(R)  
    //              TVerticalSlide    Stack[0x8]:4   param_2                   XREF[1]:     00469b5a(R)  
    //              long              Stack[0xc]:4   param_3                   XREF[1]:     00469b8c(R)  
    //              long              Stack[0x10]:4  param_4                   XREF[1]:     00469b83(R)  
    //              long              Stack[0x14]:4  param_5                   XREF[1]:     00469b7f(R)  
    //              long              Stack[0x18]:4  param_6                   XREF[3]:     00469ae6(R), 00469b1b(W), 00469b91(R)  
    //              long              Stack[0x1c]:4  param_7                   XREF[2]:     00469b11(R), 00469b3f(W)  
    //              long              Stack[0x20]:4  param_8                   XREF[1]:     00469b1f(R)  
    //              long              Stack[0x24]:4  param_9                   XREF[1]:     00469b2b(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     00469b45(W), 00469b5e(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     00469c26(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[2]:     00469b0d(W), 00469b96(R)  
    //              long              Stack[-0x14]:4 ideal_x
    //                               ?create_vert_slider@TEasy_Panel@@MAEHPAVTPanel@@PAPAVTVerti  XREF[47]:    TribeConfigDialog:0043b8f9(c), 
    //                               TEasy_Panel::create_vert_slider                                           TribeConfigDialog:0043ba02(c), 
    //                                                                                                         TribeConfigDialog:0043bb07(c), 
    //                                                                                                         0056f72c(*), 0056f86c(*), 
    //                                                                                                         0056f9b4(*), 0056fae4(*), 
    //                                                                                                         0056fc14(*), 0056fd4c(*), 
    //                                                                                                         0056fe7c(*), 0056ffac(*), 
    //                                                                                                         005700dc(*), 0057020c(*), 
    //                                                                                                         00570e34(*), 005711cc(*), 
    //                                                                                                         00571a2c(*), 00571e0c(*), 
    //                                                                                                         0057229c(*), 005723c4(*), 
    //                                                                                                         005724ec(*), [more]
    //                              Panel_ez.cpp:1657 (22)
    //         00469ad0     PUSH       -0x1
    //         00469ad2     PUSH       FUN_0055e0cb
    //         00469ad7     MOV        EAX,FS:[0x0]
    //         00469add     PUSH       EAX
    //         00469ade     MOV        dword ptr FS:[0x0],ESP
    //         00469ae5     PUSH       this
    //                              Panel_ez.cpp:1658 (10)
    //         00469ae6     MOV        EAX,dword ptr [ESP + param_6]
    //         00469aea     PUSH       EBX
    //         00469aeb     PUSH       EBP
    //         00469aec     PUSH       ESI
    //         00469aed     MOV        ESI,this
    //         00469aef     PUSH       EDI
    //                              Panel_ez.cpp:1663 (118)
    //         00469af0     PUSH       0x1cc
    //         00469af5     MOV        this,dword ptr [ESI + 0x14]
    //         00469af8     MOV        EDI,dword ptr [ESI + 0xf4]
    //         00469afe     IMUL       EAX,this
    //         00469b01     CDQ
    //         00469b02     IDIV       EDI
    //         00469b04     MOV        EBX,dword ptr [ESI + 0x18]
    //         00469b07     MOV        EBP,dword ptr [ESI + 0xf8]
    //         00469b0d     MOV        dword ptr [ESP + local_10],EAX
    //         00469b11     MOV        EAX,dword ptr [ESP + param_7]
    //         00469b15     IMUL       EAX,EBX
    //         00469b18     CDQ
    //         00469b19     IDIV       EBP
    //         00469b1b     MOV        dword ptr [ESP + param_6],EAX
    //         00469b1f     MOV        EAX,dword ptr [ESP + param_8]
    //         00469b23     IMUL       EAX,this
    //         00469b26     CDQ
    //         00469b27     IDIV       EDI
    //         00469b29     MOV        EDI,EAX
    //         00469b2b     MOV        EAX,dword ptr [ESP + param_9]
    //         00469b2f     IMUL       EAX,EBX
    //         00469b32     CDQ
    //         00469b33     IDIV       EBP
    //         00469b35     MOV        EBX,EAX
    //         00469b37     CALL       operator_new                                     void * operator_new(uint param_1)
    //         00469b3c     ADD        ESP,0x4
    //         00469b3f     MOV        dword ptr [ESP + param_7],EAX
    //         00469b43     TEST       EAX,EAX
    //         00469b45     MOV        dword ptr [ESP + local_4],0x0
    //         00469b4d     JZ         LAB_00469b58
    //         00469b4f     MOV        this,EAX
    //         00469b51     CALL       TVerticalSliderPanel::TVerticalSliderPanel       undefined TVerticalSliderPanel(TVerticalSlide
    //         00469b56     JMP        LAB_00469b5a
    //                               LAB_00469b58                                                 XREF[1]:     00469b4d(j)  
    //         00469b58     XOR        EAX,EAX
    //                               LAB_00469b5a                                                 XREF[1]:     00469b56(j)  
    //         00469b5a     MOV        EBP,dword ptr [ESP + param_2]
    //         00469b5e     MOV        dword ptr [ESP + local_4],0xffffffff
    //                              Panel_ez.cpp:1664 (25)
    //         00469b66     TEST       EAX,EAX
    //         00469b68     MOV        dword ptr [EBP],EAX
    //         00469b6b     JZ         LAB_00469c24
    //         00469b71     MOV        this,dword ptr [EAX + 0xd8]
    //         00469b77     TEST       this,this
    //         00469b79     JNZ        LAB_00469c24
    //                              Panel_ez.cpp:1668 (55)
    //         00469b7f     MOV        this,dword ptr [ESP + param_5]
    //         00469b83     MOV        EDX,dword ptr [ESP + param_4]
    //         00469b87     PUSH       0x0
    //         00469b89     PUSH       0x1
    //         00469b8b     PUSH       this
    //         00469b8c     MOV        this,dword ptr [ESP + param_3]
    //         00469b90     PUSH       EDX
    //         00469b91     MOV        EDX,dword ptr [ESP + param_6]
    //         00469b95     PUSH       this
    //         00469b96     MOV        this,dword ptr [ESP + local_10]
    //         00469b9a     PUSH       0x0
    //         00469b9c     PUSH       0x0
    //         00469b9e     PUSH       0x0
    //         00469ba0     PUSH       EBX
    //         00469ba1     PUSH       EDI
    //         00469ba2     PUSH       EDX
    //         00469ba3     MOV        EDX,dword ptr [ESP + param_1]
    //         00469ba7     PUSH       this
    //         00469ba8     MOV        this,dword ptr [ESI + 0x20]
    //         00469bab     PUSH       EDX
    //         00469bac     PUSH       this
    //         00469bad     MOV        this,EAX
    //         00469baf     CALL       TVerticalSliderPanel::setup                      long setup(TVerticalSliderPanel * this, TDraw
    //         00469bb4     TEST       EAX,EAX
    //                              Panel_ez.cpp:1669 (2)
    //         00469bb6     JZ         LAB_00469c24
    //                              Panel_ez.cpp:1671 (10)
    //         00469bb8     MOV        EAX,dword ptr [ESI + 0x448]
    //         00469bbe     TEST       EAX,EAX
    //         00469bc0     JZ         LAB_00469bd3
    //                              Panel_ez.cpp:1672 (17)
    //         00469bc2     MOV        this,dword ptr [EBP]
    //         00469bc5     PUSH       0xc
    //         00469bc7     PUSH       0xa
    //         00469bc9     PUSH       0x8
    //         00469bcb     PUSH       -0x1
    //         00469bcd     PUSH       EAX
    //         00469bce     CALL       TScrollBarPanel::set_buttons                     void set_buttons(TScrollBarPanel * this, TSha
    //                               LAB_00469bd3                                                 XREF[1]:     00469bc0(j)  
    //                              Panel_ez.cpp:1674 (10)
    //         00469bd3     MOV        EAX,dword ptr [ESI + 0x31c]
    //         00469bd9     TEST       EAX,EAX
    //         00469bdb     JZ         LAB_00469c1d
    //                              Panel_ez.cpp:1675 (64)
    //         00469bdd     XOR        EDX,EDX
    //         00469bdf     XOR        EAX,EAX
    //         00469be1     MOV        DL,byte ptr [ESI + 0x325]
    //         00469be7     MOV        AL,byte ptr [ESI + 0x324]
    //         00469bed     XOR        this,this
    //         00469bef     PUSH       EDX
    //         00469bf0     MOV        this,byte ptr [ESI + 0x323]
    //         00469bf6     PUSH       EAX
    //         00469bf7     XOR        EDX,EDX
    //         00469bf9     PUSH       this
    //         00469bfa     MOV        DL,byte ptr [ESI + 0x322]
    //         00469c00     XOR        EAX,EAX
    //         00469c02     MOV        AL,byte ptr [ESI + 0x321]
    //         00469c08     XOR        this,this
    //         00469c0a     MOV        this,byte ptr [ESI + 0x320]
    //         00469c10     PUSH       EDX
    //         00469c11     PUSH       EAX
    //         00469c12     PUSH       this
    //         00469c13     MOV        this,dword ptr [EBP]
    //         00469c16     PUSH       0x3
    //         00469c18     CALL       TScrollBarPanel::set_bevel_info                  void set_bevel_info(TScrollBarPanel * this, i
    //                               LAB_00469c1d                                                 XREF[1]:     00469bdb(j)  
    //                              Panel_ez.cpp:1677 (7)
    //         00469c1d     MOV        EAX,0x1
    //         00469c22     JMP        LAB_00469c26
    //                               LAB_00469c24                                                 XREF[3]:     00469b6b(j), 00469b79(j), 
    //                                                                                                         00469bb6(j)  
    //                              Panel_ez.cpp:1665 (2)
    //         00469c24     XOR        EAX,EAX
    //                               LAB_00469c26                                                 XREF[1]:     00469c22(j)  
    //                              Panel_ez.cpp:1678 (21)
    //         00469c26     MOV        this,dword ptr [ESP + local_c]
    //         00469c2a     POP        EDI
    //         00469c2b     POP        ESI
    //         00469c2c     POP        EBP
    //         00469c2d     MOV        dword ptr FS:[0x0],this
    //         00469c34     POP        EBX
    //         00469c35     ADD        ESP,0x10
    //         00469c38     RET        0x24
}

// Offset: 0x00469C40
int TRIBE_Screen_Sed_Open::create_horz_slider(TPanel* param_1, THorizontalSliderPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * protected: virtual int __thiscall TEasy_Panel::create_horz_slider(class TPanel *,class THorizontal... *
    //                              *********************************************************************************************************
    //                              int __thiscall create_horz_slider(TEasy_Panel * this, TPanel * param
    //              int               EAX:4          <RETURN>
    //              TEasy_Panel *     ECX:4 (auto)   this
    //              TPanel *          Stack[0x4]:4   param_1                   XREF[1]:     00469d13(R)  
    //              THorizontalSli    Stack[0x8]:4   param_2                   XREF[1]:     00469cca(R)  
    //              long              Stack[0xc]:4   param_3                   XREF[1]:     00469cfc(R)  
    //              long              Stack[0x10]:4  param_4                   XREF[1]:     00469cf3(R)  
    //              long              Stack[0x14]:4  param_5                   XREF[1]:     00469cef(R)  
    //              long              Stack[0x18]:4  param_6                   XREF[3]:     00469c56(R), 00469c8b(W), 00469d01(R)  
    //              long              Stack[0x1c]:4  param_7                   XREF[2]:     00469c81(R), 00469caf(W)  
    //              long              Stack[0x20]:4  param_8                   XREF[1]:     00469c8f(R)  
    //              long              Stack[0x24]:4  param_9                   XREF[1]:     00469c9b(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     00469cb5(W), 00469cce(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     00469d96(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[2]:     00469c7d(W), 00469d06(R)  
    //              long              Stack[-0x14]:4 ideal_x
    //                               ?create_horz_slider@TEasy_Panel@@MAEHPAVTPanel@@PAPAVTHoriz  XREF[44]:    0056f730(*), 0056f870(*), 
    //                               TEasy_Panel::create_horz_slider                                           0056f9b8(*), 0056fae8(*), 
    //                                                                                                         0056fc18(*), 0056fd50(*), 
    //                                                                                                         0056fe80(*), 0056ffb0(*), 
    //                                                                                                         005700e0(*), 00570210(*), 
    //                                                                                                         00570e38(*), 005711d0(*), 
    //                                                                                                         00571a30(*), 00571e10(*), 
    //                                                                                                         005722a0(*), 005723c8(*), 
    //                                                                                                         005724f0(*), 00572618(*), 
    //                                                                                                         00572740(*), 00572870(*), [more]
    //                              Panel_ez.cpp:1684 (22)
    //         00469c40     PUSH       -0x1
    //         00469c42     PUSH       FUN_0055e0eb
    //         00469c47     MOV        EAX,FS:[0x0]
    //         00469c4d     PUSH       EAX
    //         00469c4e     MOV        dword ptr FS:[0x0],ESP
    //         00469c55     PUSH       this
    //                              Panel_ez.cpp:1685 (10)
    //         00469c56     MOV        EAX,dword ptr [ESP + param_6]
    //         00469c5a     PUSH       EBX
    //         00469c5b     PUSH       EBP
    //         00469c5c     PUSH       ESI
    //         00469c5d     MOV        ESI,this
    //         00469c5f     PUSH       EDI
    //                              Panel_ez.cpp:1690 (118)
    //         00469c60     PUSH       0x1cc
    //         00469c65     MOV        this,dword ptr [ESI + 0x14]
    //         00469c68     MOV        EDI,dword ptr [ESI + 0xf4]
    //         00469c6e     IMUL       EAX,this
    //         00469c71     CDQ
    //         00469c72     IDIV       EDI
    //         00469c74     MOV        EBX,dword ptr [ESI + 0x18]
    //         00469c77     MOV        EBP,dword ptr [ESI + 0xf8]
    //         00469c7d     MOV        dword ptr [ESP + local_10],EAX
    //         00469c81     MOV        EAX,dword ptr [ESP + param_7]
    //         00469c85     IMUL       EAX,EBX
    //         00469c88     CDQ
    //         00469c89     IDIV       EBP
    //         00469c8b     MOV        dword ptr [ESP + param_6],EAX
    //         00469c8f     MOV        EAX,dword ptr [ESP + param_8]
    //         00469c93     IMUL       EAX,this
    //         00469c96     CDQ
    //         00469c97     IDIV       EDI
    //         00469c99     MOV        EDI,EAX
    //         00469c9b     MOV        EAX,dword ptr [ESP + param_9]
    //         00469c9f     IMUL       EAX,EBX
    //         00469ca2     CDQ
    //         00469ca3     IDIV       EBP
    //         00469ca5     MOV        EBX,EAX
    //         00469ca7     CALL       operator_new                                     void * operator_new(uint param_1)
    //         00469cac     ADD        ESP,0x4
    //         00469caf     MOV        dword ptr [ESP + param_7],EAX
    //         00469cb3     TEST       EAX,EAX
    //         00469cb5     MOV        dword ptr [ESP + local_4],0x0
    //         00469cbd     JZ         LAB_00469cc8
    //         00469cbf     MOV        this,EAX
    //         00469cc1     CALL       THorizontalSliderPanel::THorizontalSliderPanel   undefined THorizontalSliderPanel(THorizontalS
    //         00469cc6     JMP        LAB_00469cca
    //                               LAB_00469cc8                                                 XREF[1]:     00469cbd(j)  
    //         00469cc8     XOR        EAX,EAX
    //                               LAB_00469cca                                                 XREF[1]:     00469cc6(j)  
    //         00469cca     MOV        EBP,dword ptr [ESP + param_2]
    //         00469cce     MOV        dword ptr [ESP + local_4],0xffffffff
    //                              Panel_ez.cpp:1691 (25)
    //         00469cd6     TEST       EAX,EAX
    //         00469cd8     MOV        dword ptr [EBP],EAX
    //         00469cdb     JZ         LAB_00469d94
    //         00469ce1     MOV        this,dword ptr [EAX + 0xd8]
    //         00469ce7     TEST       this,this
    //         00469ce9     JNZ        LAB_00469d94
    //                              Panel_ez.cpp:1695 (55)
    //         00469cef     MOV        this,dword ptr [ESP + param_5]
    //         00469cf3     MOV        EDX,dword ptr [ESP + param_4]
    //         00469cf7     PUSH       0x0
    //         00469cf9     PUSH       0x1
    //         00469cfb     PUSH       this
    //         00469cfc     MOV        this,dword ptr [ESP + param_3]
    //         00469d00     PUSH       EDX
    //         00469d01     MOV        EDX,dword ptr [ESP + param_6]
    //         00469d05     PUSH       this
    //         00469d06     MOV        this,dword ptr [ESP + local_10]
    //         00469d0a     PUSH       0x0
    //         00469d0c     PUSH       0x0
    //         00469d0e     PUSH       0x0
    //         00469d10     PUSH       EBX
    //         00469d11     PUSH       EDI
    //         00469d12     PUSH       EDX
    //         00469d13     MOV        EDX,dword ptr [ESP + param_1]
    //         00469d17     PUSH       this
    //         00469d18     MOV        this,dword ptr [ESI + 0x20]
    //         00469d1b     PUSH       EDX
    //         00469d1c     PUSH       this
    //         00469d1d     MOV        this,EAX
    //         00469d1f     CALL       THorizontalSliderPanel::setup                    long setup(THorizontalSliderPanel * this, TDr
    //         00469d24     TEST       EAX,EAX
    //                              Panel_ez.cpp:1696 (2)
    //         00469d26     JZ         LAB_00469d94
    //                              Panel_ez.cpp:1698 (10)
    //         00469d28     MOV        EAX,dword ptr [ESI + 0x448]
    //         00469d2e     TEST       EAX,EAX
    //         00469d30     JZ         LAB_00469d43
    //                              Panel_ez.cpp:1699 (17)
    //         00469d32     MOV        this,dword ptr [EBP]
    //         00469d35     PUSH       0xc
    //         00469d37     PUSH       0xa
    //         00469d39     PUSH       0x8
    //         00469d3b     PUSH       -0x1
    //         00469d3d     PUSH       EAX
    //         00469d3e     CALL       TScrollBarPanel::set_buttons                     void set_buttons(TScrollBarPanel * this, TSha
    //                               LAB_00469d43                                                 XREF[1]:     00469d30(j)  
    //                              Panel_ez.cpp:1701 (10)
    //         00469d43     MOV        EAX,dword ptr [ESI + 0x31c]
    //         00469d49     TEST       EAX,EAX
    //         00469d4b     JZ         LAB_00469d8d
    //                              Panel_ez.cpp:1702 (64)
    //         00469d4d     XOR        EDX,EDX
    //         00469d4f     XOR        EAX,EAX
    //         00469d51     MOV        DL,byte ptr [ESI + 0x325]
    //         00469d57     MOV        AL,byte ptr [ESI + 0x324]
    //         00469d5d     XOR        this,this
    //         00469d5f     PUSH       EDX
    //         00469d60     MOV        this,byte ptr [ESI + 0x323]
    //         00469d66     PUSH       EAX
    //         00469d67     XOR        EDX,EDX
    //         00469d69     PUSH       this
    //         00469d6a     MOV        DL,byte ptr [ESI + 0x322]
    //         00469d70     XOR        EAX,EAX
    //         00469d72     MOV        AL,byte ptr [ESI + 0x321]
    //         00469d78     XOR        this,this
    //         00469d7a     MOV        this,byte ptr [ESI + 0x320]
    //         00469d80     PUSH       EDX
    //         00469d81     PUSH       EAX
    //         00469d82     PUSH       this
    //         00469d83     MOV        this,dword ptr [EBP]
    //         00469d86     PUSH       0x3
    //         00469d88     CALL       TScrollBarPanel::set_bevel_info                  void set_bevel_info(TScrollBarPanel * this, i
    //                               LAB_00469d8d                                                 XREF[1]:     00469d4b(j)  
    //                              Panel_ez.cpp:1704 (7)
    //         00469d8d     MOV        EAX,0x1
    //         00469d92     JMP        LAB_00469d96
    //                               LAB_00469d94                                                 XREF[3]:     00469cdb(j), 00469ce9(j), 
    //                                                                                                         00469d26(j)  
    //                              Panel_ez.cpp:1692 (2)
    //         00469d94     XOR        EAX,EAX
    //                               LAB_00469d96                                                 XREF[1]:     00469d92(j)  
    //                              Panel_ez.cpp:1705 (21)
    //         00469d96     MOV        this,dword ptr [ESP + local_c]
    //         00469d9a     POP        EDI
    //         00469d9b     POP        ESI
    //         00469d9c     POP        EBP
    //         00469d9d     MOV        dword ptr FS:[0x0],this
    //         00469da4     POP        EBX
    //         00469da5     ADD        ESP,0x10
    //         00469da8     RET        0x24
}

// Offset: 0x00469DB0
void TRIBE_Screen_Sed_Open::position_panel(TPanel* param_1, long param_2, long param_3, long param_4, long param_5) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * protected: virtual void __thiscall TEasy_Panel::position_panel(class TPanel *,long,long,long,long)    *
    //                              *********************************************************************************************************
    //                              void __thiscall position_panel(TEasy_Panel * this, TPanel * param_1,
    //              void              <VOID>         <RETURN>
    //              TEasy_Panel *     ECX:4 (auto)   this
    //              TPanel *          Stack[0x4]:4   param_1                   XREF[2]:     00469db0(R), 00469df7(R)  
    //              long              Stack[0x8]:4   param_2                   XREF[1]:     00469ded(R)  
    //              long              Stack[0xc]:4   param_3                   XREF[1]:     00469de2(R)  
    //              long              Stack[0x10]:4  param_4                   XREF[1]:     00469dd7(R)  
    //              long              Stack[0x14]:4  param_5                   XREF[1]:     00469dbc(R)  
    //                               ?position_panel@TEasy_Panel@@MAEXPAVTPanel@@JJJJ@Z           XREF[44]:    0056f734(*), 0056f874(*), 
    //                               TEasy_Panel::position_panel                                               0056f9bc(*), 0056faec(*), 
    //                                                                                                         0056fc1c(*), 0056fd54(*), 
    //                                                                                                         0056fe84(*), 0056ffb4(*), 
    //                                                                                                         005700e4(*), 00570214(*), 
    //                                                                                                         00570e3c(*), 005711d4(*), 
    //                                                                                                         00571a34(*), 00571e14(*), 
    //                                                                                                         005722a4(*), 005723cc(*), 
    //                                                                                                         005724f4(*), 0057261c(*), 
    //                                                                                                         00572744(*), 00572874(*), [more]
    //                              Panel_ez.cpp:1711 (79)
    //         00469db0     MOV        EAX,dword ptr [ESP + param_1]
    //         00469db4     PUSH       EBX
    //         00469db5     PUSH       EBP
    //         00469db6     PUSH       ESI
    //         00469db7     MOV        EBP,dword ptr [EAX]
    //         00469db9     MOV        ESI,dword ptr [ECX + this->_padding_]
    //         00469dbc     MOV        EAX,dword ptr [ESP + param_5]
    //         00469dc0     PUSH       EDI
    //         00469dc1     IMUL       EAX,ESI
    //         00469dc4     MOV        EDI,dword ptr [ECX + this->ideal_height]
    //         00469dca     MOV        EBX,dword ptr [ECX + this->_padding_]
    //         00469dcd     CDQ
    //         00469dce     IDIV       EDI
    //         00469dd0     MOV        this,dword ptr [ECX + this->ideal_width]
    //         00469dd6     PUSH       EAX
    //         00469dd7     MOV        EAX,dword ptr [ESP + param_4]
    //         00469ddb     IMUL       EAX,EBX
    //         00469dde     CDQ
    //         00469ddf     IDIV       this
    //         00469de1     PUSH       EAX
    //         00469de2     MOV        EAX,dword ptr [ESP + param_3]
    //         00469de6     IMUL       EAX,ESI
    //         00469de9     CDQ
    //         00469dea     IDIV       EDI
    //         00469dec     PUSH       EAX
    //         00469ded     MOV        EAX,dword ptr [ESP + param_2]
    //         00469df1     IMUL       EAX,EBX
    //         00469df4     CDQ
    //         00469df5     IDIV       this
    //         00469df7     MOV        this,dword ptr [ESP + param_1]
    //         00469dfb     PUSH       EAX
    //         00469dfc     CALL       dword ptr [EBP + 0x1c]
    //                              Panel_ez.cpp:1713 (7)
    //         00469dff     POP        EDI
    //         00469e00     POP        ESI
    //         00469e01     POP        EBP
    //         00469e02     POP        EBX
    //         00469e03     RET        0x14
}

// Offset: 0x00469E10
void Time_Line_Panel::set_focus(int param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void __thiscall TEasy_Panel::set_focus(int)                                           *
    //                              *********************************************************************************************************
    //                              void __thiscall set_focus(TEasy_Panel * this, int param_1)
    //              void              <VOID>         <RETURN>
    //              TEasy_Panel *     ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     00469e10(R)  
    //                               ?set_focus@TEasy_Panel@@UAEXH@Z                              XREF[4]:     set_focus:00473ec5(c), 
    //                               TEasy_Panel::set_focus                                                    set_focus:0047bc35(c), 
    //                                                                                                         00570dd8(*), 00577048(*)  
    //                              Panel_ez.cpp:1719 (14)
    //         00469e10     MOV        EAX,dword ptr [ESP + param_1]
    //         00469e14     PUSH       ESI
    //         00469e15     PUSH       EDI
    //         00469e16     MOV        ESI,this
    //         00469e18     PUSH       EAX
    //         00469e19     CALL       TPanel::set_focus                                void set_focus(TPanel * this, int param_1)
    //                              Panel_ez.cpp:1724 (11)
    //         00469e1e     MOV        EAX,dword ptr [ESI + 0x78]
    //         00469e21     TEST       EAX,EAX
    //         00469e23     JZ         LAB_00469eb4
    //                              Panel_ez.cpp:1726 (26)
    //         00469e29     MOV        this,byte ptr [ESI + 0x210]
    //         00469e2f     LEA        EAX,[ESI + 0x210]
    //         00469e35     TEST       this,this
    //         00469e37     JNZ        LAB_00469e43
    //         00469e39     MOV        this,dword ptr [ESI + 0x314]
    //         00469e3f     TEST       this,this
    //         00469e41     JL         LAB_00469e62
    //                               LAB_00469e43                                                 XREF[1]:     00469e37(j)  
    //                              Panel_ez.cpp:1728 (12)
    //         00469e43     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         00469e49     MOV        this,dword ptr [ECX + this+0x1c0]
    //                              Panel_ez.cpp:1729 (4)
    //         00469e4f     TEST       this,this
    //         00469e51     JZ         LAB_00469e62
    //                              Panel_ez.cpp:1730 (15)
    //         00469e53     MOV        EDX,dword ptr [ESI + 0x314]
    //         00469e59     PUSH       0x0
    //         00469e5b     PUSH       EDX
    //         00469e5c     PUSH       EAX
    //         00469e5d     CALL       TMousePointer::LoadCursors                       int LoadCursors(TMousePointer * this, char * 
    //                               LAB_00469e62                                                 XREF[2]:     00469e41(j), 00469e51(j)  
    //                              Panel_ez.cpp:1733 (13)
    //         00469e62     MOV        this,dword ptr [ESI + 0x20]
    //         00469e65     TEST       this,this
    //         00469e67     JZ         LAB_00469eb4
    //         00469e69     MOV        EAX,dword ptr [this->_padding_]
    //         00469e6b     TEST       EAX,EAX
    //         00469e6d     JZ         LAB_00469eb4
    //                              Panel_ez.cpp:1735 (8)
    //         00469e6f     MOV        EDI,dword ptr [ESI + 0x20c]
    //         00469e75     TEST       EDI,EDI
    //                              Panel_ez.cpp:1737 (2)
    //         00469e77     JNZ        LAB_00469e86
    //                              Panel_ez.cpp:1738 (9)
    //         00469e79     MOV        EDX,dword ptr [rge_base_game]                    = 00000000
    //         00469e7f     MOV        EDI,dword ptr [EDX + 0x1c]
    //                              Panel_ez.cpp:1739 (9)
    //         00469e82     TEST       EDI,EDI
    //         00469e84     JZ         LAB_00469eb4
    //                               LAB_00469e86                                                 XREF[1]:     00469e77(j)  
    //         00469e86     CMP        dword ptr [EAX + 0x8],EDI
    //         00469e89     JZ         LAB_00469eb4
    //                              Panel_ez.cpp:1741 (9)
    //         00469e8b     PUSH       0x0
    //         00469e8d     PUSH       0x0
    //         00469e8f     CALL       TDrawArea::Clear                                 void Clear(TDrawArea * this, tagRECT * param_
    //                              Panel_ez.cpp:1742 (12)
    //         00469e94     MOV        EAX,dword ptr [ESI + 0x20]
    //         00469e97     PUSH       0x0
    //         00469e99     MOV        this,dword ptr [EAX]
    //         00469e9b     CALL       TDrawSystem::Paint                               void Paint(TDrawSystem * this, tagRECT * para
    //                              Panel_ez.cpp:1743 (11)
    //         00469ea0     MOV        this,dword ptr [ESI + 0x20]
    //         00469ea3     PUSH       EDI
    //         00469ea4     MOV        this,dword ptr [this->_padding_]
    //         00469ea6     CALL       TDrawSystem::SetPalette                          void SetPalette(TDrawSystem * this, void * pa
    //                              Panel_ez.cpp:1744 (9)
    //         00469eab     MOV        EDX,dword ptr [ESI]
    //         00469ead     PUSH       0x2
    //         00469eaf     MOV        this,ESI
    //         00469eb1     CALL       dword ptr [EDX + 0x20]
    //                               LAB_00469eb4                                                 XREF[5]:     00469e23(j), 00469e67(j), 
    //                                                                                                         00469e6d(j), 00469e84(j), 
    //                                                                                                         00469e89(j)  
    //                              Panel_ez.cpp:1749 (10)
    //         00469eb4     MOV        EAX,dword ptr [ESI + 0x458]
    //         00469eba     TEST       EAX,EAX
    //         00469ebc     JZ         LAB_00469ed9
    //                              Panel_ez.cpp:1751 (3)
    //         00469ebe     MOV        EAX,dword ptr [ESI + 0x78]
    //                              Panel_ez.cpp:1752 (14)
    //         00469ec1     MOV        this,panel_system
    //         00469ec6     TEST       EAX,EAX
    //         00469ec8     JZ         LAB_00469ed4
    //         00469eca     CALL       TPanelSystem::EnableIME                          void EnableIME(TPanelSystem * this)
    //                              Panel_ez.cpp:1756 (5)
    //         00469ecf     POP        EDI
    //         00469ed0     POP        ESI
    //         00469ed1     RET        0x4
    //                               LAB_00469ed4                                                 XREF[1]:     00469ec8(j)  
    //                              Panel_ez.cpp:1754 (5)
    //         00469ed4     CALL       TPanelSystem::DisableIME                         void DisableIME(TPanelSystem * this)
    //                               LAB_00469ed9                                                 XREF[1]:     00469ebc(j)  
    //                              Panel_ez.cpp:1756 (5)
    //         00469ed9     POP        EDI
    //         00469eda     POP        ESI
    //         00469edb     RET        0x4
}

// Offset: 0x00469EE0
void popupOKDialog(TEasy_Panel* this_, long param_2, char* param_3, int param_4, int param_5) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TEasy_Panel::popupOKDialog(long,char *,int,int)                               *
    //                              *********************************************************************************************************
    //                              void __thiscall popupOKDialog(TEasy_Panel * this, long param_1, char
    //              void              <VOID>         <RETURN>
    //              TEasy_Panel *     ECX:4 (auto)   this
    //              long              Stack[0x4]:4   param_1                   XREF[1]:     00469eed(R)  
    //              char *            Stack[0x8]:4   param_2                   XREF[1]:     00469f10(R)  
    //              int               Stack[0xc]:4   param_3                   XREF[1]:     00469f09(R)  
    //              int               Stack[0x10]:4  param_4                   XREF[1]:     00469f02(R)  
    //              char[256]         Stack[-0x104   text                      XREF[0,2]:   00469ee6(*), 00469f19(*)  
    //                               ?popupOKDialog@TEasy_Panel@@QAEXJPADHH@Z                     XREF[45]:    startGame:004914c8(c), 
    //                               TEasy_Panel::popupOKDialog                                                startGame:0049163d(c), 
    //                                                                                                         handle_idle:00491b09(c), 
    //                                                                                                         action:00492665(c), 
    //                                                                                                         key_down_action:0049ed67(c), 
    //                                                                                                         action:0049fa90(c), 
    //                                                                                                         action:0049fabe(c), 
    //                                                                                                         action:004a17d8(c), 
    //                                                                                                         startGame:004a20c3(c), 
    //                                                                                                         startGame:004a21e2(c), 
    //                                                                                                         startGame:004a230a(c), 
    //                                                                                                         startGame:004a244f(c), 
    //                                                                                                         startGame:004a2725(c), 
    //                                                                                                         showNetInfo:004a2b67(c), 
    //                                                                                                         command_save:004ad769(c), 
    //                                                                                                         command_save:004ad7a5(c), 
    //                                                                                                         command_save:004ad834(c), 
    //                                                                                                         command_save_as:004ad9b8(c), 
    //                                                                                                         command_save_as:004ad9e5(c), 
    //                                                                                                         setup:00521f5d(c), [more]
    //                              Panel_ez.cpp:1762 (6)
    //         00469ee0     SUB        ESP,0x100
    //                              Panel_ez.cpp:1764 (28)
    //         00469ee6     LEA        EAX=>text[4],[ESP]
    //         00469eea     PUSH       ESI
    //         00469eeb     MOV        ESI,this
    //         00469eed     MOV        this,dword ptr [ESP + param_1]
    //         00469ef4     PUSH       0x100
    //         00469ef9     PUSH       EAX
    //         00469efa     PUSH       this
    //         00469efb     MOV        this,ESI
    //         00469efd     CALL       TPanel::get_string                               int get_string(TPanel * this, int param_1, ch
    //                              Panel_ez.cpp:1765 (36)
    //         00469f02     MOV        EDX,dword ptr [ESP + param_4]
    //         00469f09     MOV        EAX,dword ptr [ESP + param_3]
    //         00469f10     MOV        this,dword ptr [ESP + param_2]
    //         00469f17     PUSH       EDX
    //         00469f18     PUSH       EAX
    //         00469f19     LEA        EDX=>text[4],[ESP + 0xc]
    //         00469f1d     PUSH       this
    //         00469f1e     PUSH       EDX
    //         00469f1f     MOV        this,ESI
    //         00469f21     CALL       TEasy_Panel::popupOKDialog                       void popupOKDialog(TEasy_Panel * this, char *
    //                              Panel_ez.cpp:1766 (10)
    //         00469f26     POP        ESI
    //         00469f27     ADD        ESP,0x100
    //         00469f2d     RET        0x10
}

// Offset: 0x00469F30
void popupOKDialog(TEasy_Panel* this_, char* param_2, char* param_3, int param_4, int param_5) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TEasy_Panel::popupOKDialog(char *,char *,int,int)                             *
    //                              *********************************************************************************************************
    //                              void __thiscall popupOKDialog(TEasy_Panel * this, char * param_1, ch
    //              void              <VOID>         <RETURN>
    //              TEasy_Panel *     ECX:4 (auto)   this
    //              char *            Stack[0x4]:4   param_1                   XREF[1]:     00469fde(R)  
    //              char *            Stack[0x8]:4   param_2                   XREF[1]:     00469f4e(R)  
    //              int               Stack[0xc]:4   param_3                   XREF[1]:     00469ff1(R)  
    //              int               Stack[0x10]:4  param_4                   XREF[1]:     00469fe5(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     00469fc1(W), 0046a00d(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     0046a01d(R)  
    //              char[256]         Stack[-0x110   temp_title                XREF[1,5]:   00469fbb(W), 00469f60(*), 00469f66(*), 00469f8c(*), 
    //                                                                                     00469f9f(*), 00469fce(*)  
    //                               ?popupOKDialog@TEasy_Panel@@QAEXPAD0HH@Z                     XREF[9]:     popupOKDialog:00469f21(c), 
    //                               TEasy_Panel::popupOKDialog                                                action:00491f25(c), 
    //                                                                                                         startGame:004a21a7(c), 
    //                                                                                                         startGame:004a2363(c), 
    //                                                                                                         startGame:004a23c3(c), 
    //                                                                                                         startGame:004a2785(c), 
    //                                                                                                         showNetInfo:004a2b50(c), 
    //                                                                                                         handle_user_command:004a35ff(c), 
    //                                                                                                         handle_user_command:004a3669(c)  
    //                              Panel_ez.cpp:1772 (30)
    //         00469f30     MOV        EAX,FS:[0x0]
    //         00469f36     PUSH       -0x1
    //         00469f38     PUSH       FUN_0055e10e
    //         00469f3d     PUSH       EAX
    //         00469f3e     MOV        dword ptr FS:[0x0],ESP
    //         00469f45     SUB        ESP,0x104
    //         00469f4b     PUSH       EBX
    //         00469f4c     PUSH       ESI
    //         00469f4d     PUSH       EDI
    //                              Panel_ez.cpp:1776 (18)
    //         00469f4e     MOV        EDI,dword ptr [ESP + param_2]
    //         00469f55     TEST       EDI,EDI
    //         00469f57     MOV        EBX,this
    //         00469f59     JZ         LAB_00469f66
    //         00469f5b     CMP        byte ptr [EDI],0x0
    //         00469f5e     JZ         LAB_00469f66
    //                              Panel_ez.cpp:1777 (4)
    //         00469f60     LEA        EDX=>temp_title[4],[ESP + 0x10]
    //                              Panel_ez.cpp:1778 (2)
    //         00469f64     JMP        LAB_00469f6f
    //                               LAB_00469f66                                                 XREF[2]:     00469f59(j), 00469f5e(j)  
    //                              Panel_ez.cpp:1779 (38)
    //         00469f66     LEA        EDX=>temp_title[4],[ESP + 0x10]
    //         00469f6a     MOV        EDI,s_OKDialog                                   = 4Fh
    //                               LAB_00469f6f                                                 XREF[1]:     00469f64(j)  
    //         00469f6f     OR         this,0xffffffff
    //         00469f72     XOR        EAX,EAX
    //         00469f74     SCASB.RE   ES:EDI=>s_OKDialog                               = 4Fh
    //         00469f76     NOT        this
    //         00469f78     SUB        EDI,this
    //         00469f7a     MOV        EAX,this
    //         00469f7c     MOV        ESI,EDI
    //         00469f7e     MOV        EDI,EDX
    //         00469f80     SHR        this,0x2
    //         00469f83     MOVSD.REP  ES:EDI,ESI
    //         00469f85     MOV        this,EAX
    //         00469f87     AND        this,0x3
    //         00469f8a     MOVSB.REP  ES:EDI,ESI
    //                              Panel_ez.cpp:1781 (15)
    //         00469f8c     LEA        this=>temp_title[4],[ESP + 0x10]
    //         00469f90     PUSH       this
    //         00469f91     MOV        this,panel_system
    //         00469f96     CALL       TPanelSystem::panel                              TPanel * panel(TPanelSystem * this, char * pa
    //                              Panel_ez.cpp:1782 (4)
    //         00469f9b     TEST       EAX,EAX
    //         00469f9d     JZ         LAB_00469fae
    //                              Panel_ez.cpp:1783 (15)
    //         00469f9f     LEA        EDX=>temp_title[4],[ESP + 0x10]
    //         00469fa3     MOV        this,panel_system
    //         00469fa8     PUSH       EDX
    //         00469fa9     CALL       TPanelSystem::destroyPanel                       int destroyPanel(TPanelSystem * this, char * 
    //                               LAB_00469fae                                                 XREF[1]:     00469f9d(j)  
    //                              Panel_ez.cpp:1785 (48)
    //         00469fae     PUSH       0x4a4
    //         00469fb3     CALL       operator_new                                     void * operator_new(uint param_1)
    //         00469fb8     ADD        ESP,0x4
    //         00469fbb     MOV        dword ptr [ESP + temp_title[0]],EAX
    //         00469fbf     TEST       EAX,EAX
    //         00469fc1     MOV        dword ptr [ESP + local_4],0x0
    //         00469fcc     JZ         LAB_00469fdc
    //         00469fce     LEA        this=>temp_title[4],[ESP + 0x10]
    //         00469fd2     PUSH       this
    //         00469fd3     MOV        this,EAX
    //         00469fd5     CALL       TMessageDialog::TMessageDialog                   undefined TMessageDialog(TMessageDialog * thi
    //         00469fda     JMP        LAB_00469fde
    //                               LAB_00469fdc                                                 XREF[1]:     00469fcc(j)  
    //         00469fdc     XOR        EAX,EAX
    //                               LAB_00469fde                                                 XREF[1]:     00469fda(j)  
    //                              Panel_ez.cpp:1792 (63)
    //         00469fde     MOV        EDX,dword ptr [ESP + param_1]
    //         00469fe5     MOV        this,dword ptr [ESP + param_4]
    //         00469fec     PUSH       0x1e
    //         00469fee     PUSH       0x5a
    //         00469ff0     PUSH       EDX
    //         00469ff1     MOV        EDX,dword ptr [ESP + param_3]
    //         00469ff8     PUSH       0x0
    //         00469ffa     PUSH       this
    //         00469ffb     MOV        this,dword ptr [EBX + 0x444]
    //         0046a001     PUSH       EDX
    //         0046a002     LEA        EDX,[EBX + 0x340]
    //         0046a008     PUSH       this
    //         0046a009     PUSH       EDX
    //         0046a00a     PUSH       EBX
    //         0046a00b     MOV        this,EAX
    //         0046a00d     MOV        dword ptr [ESP + local_4],0xffffffff
    //         0046a018     CALL       TMessageDialog::setup                            long setup(TMessageDialog * this, TPanel * pa
    //                              Panel_ez.cpp:1793 (26)
    //         0046a01d     MOV        this,dword ptr [ESP + local_c]
    //         0046a024     POP        EDI
    //         0046a025     POP        ESI
    //         0046a026     MOV        dword ptr FS:[0x0],this
    //         0046a02d     POP        EBX
    //         0046a02e     ADD        ESP,0x110
    //         0046a034     RET        0x10
}

// Offset: 0x0046A040
void popupYesNoDialog(TEasy_Panel* this_, long param_2, char* param_3, int param_4, int param_5) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TEasy_Panel::popupYesNoDialog(long,char *,int,int)                            *
    //                              *********************************************************************************************************
    //                              void __thiscall popupYesNoDialog(TEasy_Panel * this, long param_1, c
    //              void              <VOID>         <RETURN>
    //              TEasy_Panel *     ECX:4 (auto)   this
    //              long              Stack[0x4]:4   param_1                   XREF[1]:     0046a04d(R)  
    //              char *            Stack[0x8]:4   param_2                   XREF[1]:     0046a070(R)  
    //              int               Stack[0xc]:4   param_3                   XREF[1]:     0046a069(R)  
    //              int               Stack[0x10]:4  param_4                   XREF[1]:     0046a062(R)  
    //              char[256]         Stack[-0x104   text                      XREF[0,2]:   0046a046(*), 0046a079(*)  
    //                               ?popupYesNoDialog@TEasy_Panel@@QAEXJPADHH@Z                  XREF[7]:     action:0043f85f(c), 
    //                               TEasy_Panel::popupYesNoDialog                                             action:0043f93f(c), 
    //                                                                                                         action:0043fae5(c), 
    //                                                                                                         action:0043fc26(c), 
    //                                                                                                         wnd_proc:004971d5(c), 
    //                                                                                                         action:0049fafa(c), 
    //                                                                                                         action:004a7d1c(c)  
    //                              Panel_ez.cpp:1799 (6)
    //         0046a040     SUB        ESP,0x100
    //                              Panel_ez.cpp:1801 (28)
    //         0046a046     LEA        EAX=>text[4],[ESP]
    //         0046a04a     PUSH       ESI
    //         0046a04b     MOV        ESI,this
    //         0046a04d     MOV        this,dword ptr [ESP + param_1]
    //         0046a054     PUSH       0x100
    //         0046a059     PUSH       EAX
    //         0046a05a     PUSH       this
    //         0046a05b     MOV        this,ESI
    //         0046a05d     CALL       TPanel::get_string                               int get_string(TPanel * this, int param_1, ch
    //                              Panel_ez.cpp:1802 (36)
    //         0046a062     MOV        EDX,dword ptr [ESP + param_4]
    //         0046a069     MOV        EAX,dword ptr [ESP + param_3]
    //         0046a070     MOV        this,dword ptr [ESP + param_2]
    //         0046a077     PUSH       EDX
    //         0046a078     PUSH       EAX
    //         0046a079     LEA        EDX=>text[4],[ESP + 0xc]
    //         0046a07d     PUSH       this
    //         0046a07e     PUSH       EDX
    //         0046a07f     MOV        this,ESI
    //         0046a081     CALL       TEasy_Panel::popupYesNoDialog                    void popupYesNoDialog(TEasy_Panel * this, cha
    //                              Panel_ez.cpp:1803 (10)
    //         0046a086     POP        ESI
    //         0046a087     ADD        ESP,0x100
    //         0046a08d     RET        0x10
}

// Offset: 0x0046A090
void popupYesNoDialog(TEasy_Panel* this_, char* param_2, char* param_3, int param_4, int param_5) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TEasy_Panel::popupYesNoDialog(char *,char *,int,int)                          *
    //                              *********************************************************************************************************
    //                              void __thiscall popupYesNoDialog(TEasy_Panel * this, char * param_1,
    //              void              <VOID>         <RETURN>
    //              TEasy_Panel *     ECX:4 (auto)   this
    //              char *            Stack[0x4]:4   param_1                   XREF[1]:     0046a10a(R)  
    //              char *            Stack[0x8]:4   param_2                   XREF[3]:     0046a0a6(R), 0046a0c3(W), 0046a0ea(W)  
    //              int               Stack[0xc]:4   param_3                   XREF[1]:     0046a117(R)  
    //              int               Stack[0x10]:4  param_4                   XREF[1]:     0046a10e(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[3]:     0046a0c9(W), 0046a0f0(W), 0046a130(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     0046a13d(R)  
    //                               ?popupYesNoDialog@TEasy_Panel@@QAEXPAD0HH@Z                  XREF[7]:     popupYesNoDialog:0046a081(c), 
    //                               TEasy_Panel::popupYesNoDialog                                             wnd_proc:0048f597(c), 
    //                                                                                                         action:0049e4ae(c), 
    //                                                                                                         kickPlayer:004a500d(c), 
    //                                                                                                         action:004a6bfa(c), 
    //                                                                                                         action:004a7a72(c), 
    //                                                                                                         action:004b3a6e(c)  
    //                              Panel_ez.cpp:1809 (22)
    //         0046a090     MOV        EAX,FS:[0x0]
    //         0046a096     PUSH       -0x1
    //         0046a098     PUSH       FUN_0055e136
    //         0046a09d     PUSH       EAX
    //         0046a09e     MOV        dword ptr FS:[0x0],ESP
    //         0046a0a5     PUSH       ESI
    //                              Panel_ez.cpp:1812 (16)
    //         0046a0a6     MOV        ESI,dword ptr [ESP + param_2]
    //         0046a0aa     PUSH       EDI
    //         0046a0ab     TEST       ESI,ESI
    //         0046a0ad     MOV        EDI,this
    //         0046a0af     JZ         LAB_0046a0dd
    //         0046a0b1     CMP        byte ptr [ESI],0x0
    //         0046a0b4     JZ         LAB_0046a0dd
    //                              Panel_ez.cpp:1813 (30)
    //         0046a0b6     PUSH       0x4a4
    //         0046a0bb     CALL       operator_new                                     void * operator_new(uint param_1)
    //         0046a0c0     ADD        ESP,0x4
    //         0046a0c3     MOV        dword ptr [ESP + param_2],EAX
    //         0046a0c7     TEST       EAX,EAX
    //         0046a0c9     MOV        dword ptr [ESP + local_4],0x0
    //         0046a0d1     JZ         LAB_0046a108
    //         0046a0d3     PUSH       ESI
    //                              Panel_ez.cpp:1815 (54)
    //         0046a0d4     MOV        this,EAX
    //         0046a0d6     CALL       TMessageDialog::TMessageDialog                   undefined TMessageDialog(TMessageDialog * thi
    //         0046a0db     JMP        LAB_0046a10a
    //                               LAB_0046a0dd                                                 XREF[2]:     0046a0af(j), 0046a0b4(j)  
    //         0046a0dd     PUSH       0x4a4
    //         0046a0e2     CALL       operator_new                                     void * operator_new(uint param_1)
    //         0046a0e7     ADD        ESP,0x4
    //         0046a0ea     MOV        dword ptr [ESP + param_2],EAX
    //         0046a0ee     TEST       EAX,EAX
    //         0046a0f0     MOV        dword ptr [ESP + local_4],0x1
    //         0046a0f8     JZ         LAB_0046a108
    //         0046a0fa     PUSH       s_YesNoDialog                                    = 59h
    //         0046a0ff     MOV        this,EAX
    //         0046a101     CALL       TMessageDialog::TMessageDialog                   undefined TMessageDialog(TMessageDialog * thi
    //         0046a106     JMP        LAB_0046a10a
    //                               LAB_0046a108                                                 XREF[2]:     0046a0d1(j), 0046a0f8(j)  
    //         0046a108     XOR        EAX,EAX
    //                               LAB_0046a10a                                                 XREF[2]:     0046a0db(j), 0046a106(j)  
    //                              Panel_ez.cpp:1822 (51)
    //         0046a10a     MOV        this,dword ptr [ESP + param_1]
    //         0046a10e     MOV        EDX,dword ptr [ESP + param_4]
    //         0046a112     PUSH       0x1e
    //         0046a114     PUSH       0x5a
    //         0046a116     PUSH       this
    //         0046a117     MOV        this,dword ptr [ESP + param_3]
    //         0046a11b     PUSH       0x2
    //         0046a11d     PUSH       EDX
    //         0046a11e     MOV        EDX,dword ptr [EDI + 0x444]
    //         0046a124     PUSH       this
    //         0046a125     LEA        this,[EDI + 0x340]
    //         0046a12b     PUSH       EDX
    //         0046a12c     PUSH       this
    //         0046a12d     PUSH       EDI
    //         0046a12e     MOV        this,EAX
    //         0046a130     MOV        dword ptr [ESP + local_4],0xffffffff
    //         0046a138     CALL       TMessageDialog::setup                            long setup(TMessageDialog * this, TPanel * pa
    //                              Panel_ez.cpp:1823 (19)
    //         0046a13d     MOV        this,dword ptr [ESP + local_c]
    //         0046a141     POP        EDI
    //         0046a142     MOV        dword ptr FS:[0x0],this
    //         0046a149     POP        ESI
    //         0046a14a     ADD        ESP,0xc
    //         0046a14d     RET        0x10
}

// Offset: 0x0046A150
void popupYesNoCancelDialog(TEasy_Panel* this_, long param_2, char* param_3, int param_4, int param_5) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TEasy_Panel::popupYesNoCancelDialog(long,char *,int,int)                      *
    //                              *********************************************************************************************************
    //                              void __thiscall popupYesNoCancelDialog(TEasy_Panel * this, long para
    //              void              <VOID>         <RETURN>
    //              TEasy_Panel *     ECX:4 (auto)   this
    //              long              Stack[0x4]:4   param_1                   XREF[1]:     0046a15d(R)  
    //              char *            Stack[0x8]:4   param_2                   XREF[1]:     0046a180(R)  
    //              int               Stack[0xc]:4   param_3                   XREF[1]:     0046a179(R)  
    //              int               Stack[0x10]:4  param_4                   XREF[1]:     0046a172(R)  
    //              char[256]         Stack[-0x104   text                      XREF[0,2]:   0046a156(*), 0046a189(*)  
    //                               ?popupYesNoCancelDialog@TEasy_Panel@@QAEXJPADHH@Z            XREF[3]:     command_new:004ad31f(c), 
    //                               TEasy_Panel::popupYesNoCancelDialog                                       command_open:004ad5c5(c), 
    //                                                                                                         command_quit:004ad6bf(c)  
    //                              Panel_ez.cpp:1830 (6)
    //         0046a150     SUB        ESP,0x100
    //                              Panel_ez.cpp:1832 (28)
    //         0046a156     LEA        EAX=>text[4],[ESP]
    //         0046a15a     PUSH       ESI
    //         0046a15b     MOV        ESI,this
    //         0046a15d     MOV        this,dword ptr [ESP + param_1]
    //         0046a164     PUSH       0x100
    //         0046a169     PUSH       EAX
    //         0046a16a     PUSH       this
    //         0046a16b     MOV        this,ESI
    //         0046a16d     CALL       TPanel::get_string                               int get_string(TPanel * this, int param_1, ch
    //                              Panel_ez.cpp:1833 (36)
    //         0046a172     MOV        EDX,dword ptr [ESP + param_4]
    //         0046a179     MOV        EAX,dword ptr [ESP + param_3]
    //         0046a180     MOV        this,dword ptr [ESP + param_2]
    //         0046a187     PUSH       EDX
    //         0046a188     PUSH       EAX
    //         0046a189     LEA        EDX=>text[4],[ESP + 0xc]
    //         0046a18d     PUSH       this
    //         0046a18e     PUSH       EDX
    //         0046a18f     MOV        this,ESI
    //         0046a191     CALL       TEasy_Panel::popupYesNoCancelDialog              void popupYesNoCancelDialog(TEasy_Panel * thi
    //                              Panel_ez.cpp:1834 (10)
    //         0046a196     POP        ESI
    //         0046a197     ADD        ESP,0x100
    //         0046a19d     RET        0x10
}

// Offset: 0x0046A1A0
void popupYesNoCancelDialog(TEasy_Panel* this_, char* param_2, char* param_3, int param_4, int param_5) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TEasy_Panel::popupYesNoCancelDialog(char *,char *,int,int)                    *
    //                              *********************************************************************************************************
    //                              void __thiscall popupYesNoCancelDialog(TEasy_Panel * this, char * pa
    //              void              <VOID>         <RETURN>
    //              TEasy_Panel *     ECX:4 (auto)   this
    //              char *            Stack[0x4]:4   param_1                   XREF[1]:     0046a21a(R)  
    //              char *            Stack[0x8]:4   param_2                   XREF[3]:     0046a1b6(R), 0046a1d3(W), 0046a1fa(W)  
    //              int               Stack[0xc]:4   param_3                   XREF[1]:     0046a227(R)  
    //              int               Stack[0x10]:4  param_4                   XREF[1]:     0046a21e(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[3]:     0046a1d9(W), 0046a200(W), 0046a240(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     0046a24d(R)  
    //                               ?popupYesNoCancelDialog@TEasy_Panel@@QAEXPAD0HH@Z            XREF[3]:     popupYesNoCancelDialog:0046a191(c)
    //                               TEasy_Panel::popupYesNoCancelDialog                                       action:004906e9(c), 
    //                                                                                                         action:00490789(c)  
    //                              Panel_ez.cpp:1840 (22)
    //         0046a1a0     MOV        EAX,FS:[0x0]
    //         0046a1a6     PUSH       -0x1
    //         0046a1a8     PUSH       FUN_0055e156
    //         0046a1ad     PUSH       EAX
    //         0046a1ae     MOV        dword ptr FS:[0x0],ESP
    //         0046a1b5     PUSH       ESI
    //                              Panel_ez.cpp:1843 (16)
    //         0046a1b6     MOV        ESI,dword ptr [ESP + param_2]
    //         0046a1ba     PUSH       EDI
    //         0046a1bb     TEST       ESI,ESI
    //         0046a1bd     MOV        EDI,this
    //         0046a1bf     JZ         LAB_0046a1ed
    //         0046a1c1     CMP        byte ptr [ESI],0x0
    //         0046a1c4     JZ         LAB_0046a1ed
    //                              Panel_ez.cpp:1844 (30)
    //         0046a1c6     PUSH       0x4a4
    //         0046a1cb     CALL       operator_new                                     void * operator_new(uint param_1)
    //         0046a1d0     ADD        ESP,0x4
    //         0046a1d3     MOV        dword ptr [ESP + param_2],EAX
    //         0046a1d7     TEST       EAX,EAX
    //         0046a1d9     MOV        dword ptr [ESP + local_4],0x0
    //         0046a1e1     JZ         LAB_0046a218
    //         0046a1e3     PUSH       ESI
    //                              Panel_ez.cpp:1846 (54)
    //         0046a1e4     MOV        this,EAX
    //         0046a1e6     CALL       TMessageDialog::TMessageDialog                   undefined TMessageDialog(TMessageDialog * thi
    //         0046a1eb     JMP        LAB_0046a21a
    //                               LAB_0046a1ed                                                 XREF[2]:     0046a1bf(j), 0046a1c4(j)  
    //         0046a1ed     PUSH       0x4a4
    //         0046a1f2     CALL       operator_new                                     void * operator_new(uint param_1)
    //         0046a1f7     ADD        ESP,0x4
    //         0046a1fa     MOV        dword ptr [ESP + param_2],EAX
    //         0046a1fe     TEST       EAX,EAX
    //         0046a200     MOV        dword ptr [ESP + local_4],0x1
    //         0046a208     JZ         LAB_0046a218
    //         0046a20a     PUSH       s_YesNoCancelDialog                              = 59h
    //         0046a20f     MOV        this,EAX
    //         0046a211     CALL       TMessageDialog::TMessageDialog                   undefined TMessageDialog(TMessageDialog * thi
    //         0046a216     JMP        LAB_0046a21a
    //                               LAB_0046a218                                                 XREF[2]:     0046a1e1(j), 0046a208(j)  
    //         0046a218     XOR        EAX,EAX
    //                               LAB_0046a21a                                                 XREF[2]:     0046a1eb(j), 0046a216(j)  
    //                              Panel_ez.cpp:1853 (51)
    //         0046a21a     MOV        this,dword ptr [ESP + param_1]
    //         0046a21e     MOV        EDX,dword ptr [ESP + param_4]
    //         0046a222     PUSH       0x19
    //                              language.dll match for 0x78: "10"
    //         0046a224     PUSH       0x78
    //         0046a226     PUSH       this
    //         0046a227     MOV        this,dword ptr [ESP + param_3]
    //         0046a22b     PUSH       0x4
    //         0046a22d     PUSH       EDX
    //         0046a22e     MOV        EDX,dword ptr [EDI + 0x444]
    //         0046a234     PUSH       this
    //         0046a235     LEA        this,[EDI + 0x340]
    //         0046a23b     PUSH       EDX
    //         0046a23c     PUSH       this
    //         0046a23d     PUSH       EDI
    //         0046a23e     MOV        this,EAX
    //         0046a240     MOV        dword ptr [ESP + local_4],0xffffffff
    //         0046a248     CALL       TMessageDialog::setup                            long setup(TMessageDialog * this, TPanel * pa
    //                              Panel_ez.cpp:1854 (19)
    //         0046a24d     MOV        this,dword ptr [ESP + local_c]
    //         0046a251     POP        EDI
    //         0046a252     MOV        dword ptr FS:[0x0],this
    //         0046a259     POP        ESI
    //         0046a25a     ADD        ESP,0xc
    //         0046a25d     RET        0x10
}

// Offset: 0x0046A260
void command_help(TEasy_Panel* this_, char* param_2, long param_3, long param_4, long param_5, long param_6) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * protected: void __thiscall TEasy_Panel::command_help(char *,long,long,long,long)                      *
    //                              *********************************************************************************************************
    //                              void __thiscall command_help(TEasy_Panel * this, char * param_1, lon
    //              void              <VOID>         <RETURN>
    //              TEasy_Panel *     ECX:4 (auto)   this
    //              char *            Stack[0x4]:4   param_1                   XREF[1]:     0046a2bb(R)  
    //              long              Stack[0x8]:4   param_2                   XREF[2]:     0046a277(R), 0046a29d(W)  
    //              long              Stack[0xc]:4   param_3                   XREF[1]:     0046a2b6(R)  
    //              long              Stack[0x10]:4  param_4                   XREF[1]:     0046a2b1(R)  
    //              long              Stack[0x14]:4  param_5                   XREF[1]:     0046a2ad(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     0046a2a3(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     0046a2ca(R)  
    //                               ?command_help@TEasy_Panel@@IAEXPADJJJJ@Z
    //                               TEasy_Panel::command_help
    //                              Panel_ez.cpp:1861 (23)
    //         0046a260     MOV        EAX,FS:[0x0]
    //         0046a266     PUSH       -0x1
    //         0046a268     PUSH       FUN_0055e16b
    //         0046a26d     PUSH       EAX
    //         0046a26e     MOV        dword ptr FS:[0x0],ESP
    //         0046a275     PUSH       ESI
    //         0046a276     PUSH       EDI
    //                              Panel_ez.cpp:1866 (10)
    //         0046a277     MOV        EDI,dword ptr [ESP + param_2]
    //         0046a27b     TEST       EDI,EDI
    //         0046a27d     MOV        ESI,this
    //         0046a27f     JL         LAB_0046a2ca
    //                              Panel_ez.cpp:1868 (6)
    //         0046a281     PUSH       EDI
    //         0046a282     CALL       TPanel::get_string                               char * get_string(TPanel * this, int param_1)
    //                              Panel_ez.cpp:1869 (9)
    //         0046a287     TEST       EAX,EAX
    //         0046a289     JNZ        LAB_0046a290
    //         0046a28b     CMP        byte ptr [EAX],0x0
    //         0046a28e     JZ         LAB_0046a2ca
    //                               LAB_0046a290                                                 XREF[1]:     0046a289(j)  
    //                              Panel_ez.cpp:1873 (58)
    //         0046a290     PUSH       0x5a4
    //         0046a295     CALL       operator_new                                     void * operator_new(uint param_1)
    //         0046a29a     ADD        ESP,0x4
    //         0046a29d     MOV        dword ptr [ESP + param_2],EAX
    //         0046a2a1     TEST       EAX,EAX
    //         0046a2a3     MOV        dword ptr [ESP + local_4],0x0
    //         0046a2ab     JZ         LAB_0046a2ca
    //         0046a2ad     MOV        this,dword ptr [ESP + param_5]
    //         0046a2b1     MOV        EDX,dword ptr [ESP + param_4]
    //         0046a2b5     PUSH       this
    //         0046a2b6     MOV        this,dword ptr [ESP + param_3]
    //         0046a2ba     PUSH       EDX
    //         0046a2bb     MOV        EDX,dword ptr [ESP + param_1]
    //         0046a2bf     PUSH       this
    //         0046a2c0     PUSH       EDI
    //         0046a2c1     PUSH       EDX
    //         0046a2c2     PUSH       ESI
    //         0046a2c3     MOV        this,EAX
    //         0046a2c5     CALL       THelpDialog::THelpDialog                         undefined THelpDialog(THelpDialog * this, TEa
    //                               LAB_0046a2ca                                                 XREF[3]:     0046a27f(j), 0046a28e(j), 
    //                                                                                                         0046a2ab(j)  
    //                              Panel_ez.cpp:1876 (19)
    //         0046a2ca     MOV        this,dword ptr [ESP + local_c]
    //         0046a2ce     POP        EDI
    //         0046a2cf     MOV        dword ptr FS:[0x0],this
    //         0046a2d6     POP        ESI
    //         0046a2d7     ADD        ESP,0xc
    //         0046a2da     RET        0x14
}

// Offset: 0x0046A2E0
void command_help(TEasy_Panel* this_, char* param_2, char* param_3, long param_4, long param_5, long param_6) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * protected: void __thiscall TEasy_Panel::command_help(char *,char *,long,long,long)                    *
    //                              *********************************************************************************************************
    //                              void __thiscall command_help(TEasy_Panel * this, char * param_1, cha
    //              void              <VOID>         <RETURN>
    //              TEasy_Panel *     ECX:4 (auto)   this
    //              char *            Stack[0x4]:4   param_1                   XREF[1]:     0046a331(R)  
    //              char *            Stack[0x8]:4   param_2                   XREF[2]:     0046a2f6(R), 0046a313(W)  
    //              long              Stack[0xc]:4   param_3                   XREF[1]:     0046a32c(R)  
    //              long              Stack[0x10]:4  param_4                   XREF[1]:     0046a327(R)  
    //              long              Stack[0x14]:4  param_5                   XREF[1]:     0046a323(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     0046a319(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     0046a340(R)  
    //                               ?command_help@TEasy_Panel@@IAEXPAD0JJJ@Z                     XREF[1]:     command_do_popup_help:0046a4ba(c)  
    //                               TEasy_Panel::command_help
    //                              Panel_ez.cpp:1883 (22)
    //         0046a2e0     MOV        EAX,FS:[0x0]
    //         0046a2e6     PUSH       -0x1
    //         0046a2e8     PUSH       FUN_0055e18b
    //         0046a2ed     PUSH       EAX
    //         0046a2ee     MOV        dword ptr FS:[0x0],ESP
    //         0046a2f5     PUSH       ESI
    //                              Panel_ez.cpp:1886 (16)
    //         0046a2f6     MOV        ESI,dword ptr [ESP + param_2]
    //         0046a2fa     PUSH       EDI
    //         0046a2fb     TEST       ESI,ESI
    //         0046a2fd     MOV        EDI,this
    //         0046a2ff     JZ         LAB_0046a340
    //         0046a301     CMP        byte ptr [ESI],0x0
    //         0046a304     JZ         LAB_0046a340
    //                              Panel_ez.cpp:1890 (58)
    //         0046a306     PUSH       0x5a4
    //         0046a30b     CALL       operator_new                                     void * operator_new(uint param_1)
    //         0046a310     ADD        ESP,0x4
    //         0046a313     MOV        dword ptr [ESP + param_2],EAX
    //         0046a317     TEST       EAX,EAX
    //         0046a319     MOV        dword ptr [ESP + local_4],0x0
    //         0046a321     JZ         LAB_0046a340
    //         0046a323     MOV        this,dword ptr [ESP + param_5]
    //         0046a327     MOV        EDX,dword ptr [ESP + param_4]
    //         0046a32b     PUSH       this
    //         0046a32c     MOV        this,dword ptr [ESP + param_3]
    //         0046a330     PUSH       EDX
    //         0046a331     MOV        EDX,dword ptr [ESP + param_1]
    //         0046a335     PUSH       this
    //         0046a336     PUSH       ESI
    //         0046a337     PUSH       EDX
    //         0046a338     PUSH       EDI
    //         0046a339     MOV        this,EAX
    //         0046a33b     CALL       THelpDialog::THelpDialog                         undefined THelpDialog(THelpDialog * this, TEa
    //                               LAB_0046a340                                                 XREF[3]:     0046a2ff(j), 0046a304(j), 
    //                                                                                                         0046a321(j)  
    //                              Panel_ez.cpp:1892 (19)
    //         0046a340     MOV        this,dword ptr [ESP + local_c]
    //         0046a344     POP        EDI
    //         0046a345     MOV        dword ptr FS:[0x0],this
    //         0046a34c     POP        ESI
    //         0046a34d     ADD        ESP,0xc
    //         0046a350     RET        0x14
}

// Offset: 0x0046A360
void setup_popup_help(TEasy_Panel* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TEasy_Panel::setup_popup_help(void)                                           *
    //                              *********************************************************************************************************
    //                              void __thiscall setup_popup_help(TEasy_Panel * this)
    //              void              <VOID>         <RETURN>
    //              TEasy_Panel *     ECX:4 (auto)   this
    //                               ?setup_popup_help@TEasy_Panel@@QAEXXZ                        XREF[8]:     action:0043dbe6(c), 
    //                               TEasy_Panel::setup_popup_help                                             action:004411bc(c), 
    //                                                                                                         key_down_action:0049765b(c), 
    //                                                                                                         do_button_action:0049891d(c), 
    //                                                                                                         action:0049fcfb(c), 
    //                                                                                                         action:004a1ae9(c), 
    //                                                                                                         action:004abec9(c), 
    //                                                                                                         action:004b5d60(c)  
    //                              Panel_ez.cpp:1900 (3)
    //         0046a360     PUSH       ESI
    //         0046a361     MOV        ESI,this
    //                              Panel_ez.cpp:1903 (32)
    //         0046a363     PUSH       0x7f8b
    //         0046a368     PUSH       0x0
    //         0046a36a     MOV        byte ptr [ESI + 0x45c],0x1
    //         0046a371     CALL       dword ptr [->USER32.DLL::LoadCursorA]            = 0048acbc
    //         0046a377     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0046a37d     PUSH       EAX
    //         0046a37e     CALL       RGE_Base_Game::set_mouse_cursor                  void set_mouse_cursor(RGE_Base_Game * this, v
    //                              Panel_ez.cpp:1907 (13)
    //         0046a383     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0046a389     PUSH       0x6
    //         0046a38b     CALL       RGE_Base_Game::set_mouse_facet                   void set_mouse_facet(RGE_Base_Game * this, lo
    //                              Panel_ez.cpp:1908 (22)
    //         0046a390     MOV        EAX,[rge_base_game]                              = 00000000
    //         0046a395     MOV        this,dword ptr [EAX + 0x1c0]
    //         0046a39b     CALL       TMousePointer::get_game_enable                   int get_game_enable(TMousePointer * this)
    //         0046a3a0     MOV        dword ptr [ESI + 0x474],EAX
    //                              Panel_ez.cpp:1909 (19)
    //         0046a3a6     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0046a3ac     PUSH       0x0
    //         0046a3ae     MOV        this,dword ptr [ECX + this+0x1c0]
    //         0046a3b4     CALL       TMousePointer::set_game_enable                   void set_game_enable(TMousePointer * this, in
    //                              Panel_ez.cpp:1911 (2)
    //         0046a3b9     POP        ESI
    //         0046a3ba     RET
}

// Offset: 0x0046A3C0
void clear_popup_help(TEasy_Panel* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TEasy_Panel::clear_popup_help(void)                                           *
    //                              *********************************************************************************************************
    //                              void __thiscall clear_popup_help(TEasy_Panel * this)
    //              void              <VOID>         <RETURN>
    //              TEasy_Panel *     ECX:4 (auto)   this
    //                               ?clear_popup_help@TEasy_Panel@@QAEXXZ                        XREF[1]:     command_cancel:0049bead(c)  
    //                               TEasy_Panel::clear_popup_help
    //                              Panel_ez.cpp:1919 (3)
    //         0046a3c0     PUSH       ESI
    //         0046a3c1     MOV        ESI,this
    //                              Panel_ez.cpp:1922 (32)
    //         0046a3c3     PUSH       0x7f00
    //         0046a3c8     PUSH       0x0
    //         0046a3ca     MOV        byte ptr [ESI + 0x45c],0x0
    //         0046a3d1     CALL       dword ptr [->USER32.DLL::LoadCursorA]            = 0048acbc
    //         0046a3d7     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0046a3dd     PUSH       EAX
    //         0046a3de     CALL       RGE_Base_Game::set_mouse_cursor                  void set_mouse_cursor(RGE_Base_Game * this, v
    //                              Panel_ez.cpp:1925 (13)
    //         0046a3e3     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0046a3e9     PUSH       0x0
    //         0046a3eb     CALL       RGE_Base_Game::set_mouse_facet                   void set_mouse_facet(RGE_Base_Game * this, lo
    //                              Panel_ez.cpp:1926 (24)
    //         0046a3f0     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0046a3f6     MOV        EAX,dword ptr [ESI + 0x474]
    //         0046a3fc     PUSH       EAX
    //         0046a3fd     MOV        this,dword ptr [ECX + this+0x1c0]
    //         0046a403     CALL       TMousePointer::set_game_enable                   void set_game_enable(TMousePointer * this, in
    //                              Panel_ez.cpp:1927 (2)
    //         0046a408     POP        ESI
    //         0046a409     RET
}

// Offset: 0x0046A410
long command_do_popup_help(TEasy_Panel* this_, uchar param_2, long param_3, long param_4) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: long __thiscall TEasy_Panel::command_do_popup_help(unsigned char,long,long)                   *
    //                              *********************************************************************************************************
    //                              long __thiscall command_do_popup_help(TEasy_Panel * this, uchar para
    //              long              EAX:4          <RETURN>
    //              TEasy_Panel *     ECX:4 (auto)   this
    //              uchar             Stack[0x4]:1   param_1
    //              long              Stack[0x8]:4   param_2
    //              long              Stack[0xc]:4   param_3
    //              char[1000]        Stack[-0x3ec   help_string2              XREF[1,1]:   0046a41d(W), 0046a419(*)  
    //              char *            Stack[-0x3f0   temp
    //              long              Stack[-0x3f4   help_page
    //                               ?command_do_popup_help@TEasy_Panel@@QAEJEJJ@Z                XREF[1]:     handle_mouse_down:004679b5(c)  
    //                               TEasy_Panel::command_do_popup_help
    //                              Panel_ez.cpp:1935 (9)
    //         0046a410     SUB        ESP,0x3f0
    //         0046a416     PUSH       ESI
    //         0046a417     MOV        ESI,this
    //                              Panel_ez.cpp:1938 (8)
    //         0046a419     LEA        EAX=>help_string2[4],[ESP + 0xc]
    //         0046a41d     MOV        dword ptr [ESP + help_string2[0]],EAX
    //                              Panel_ez.cpp:1940 (16)
    //         0046a421     MOV        AL,byte ptr [ESI + 0x45c]
    //         0046a427     CMP        AL,0x1
    //         0046a429     JNZ        LAB_0046a4d0
    //         0046a42f     PUSH       EDI
    //         0046a430     PUSH       EBP
    //                              Panel_ez.cpp:1944 (32)
    //         0046a431     PUSH       0x7f00
    //         0046a436     PUSH       0x0
    //         0046a438     MOV        byte ptr [ESI + 0x45c],0x0
    //         0046a43f     CALL       dword ptr [->USER32.DLL::LoadCursorA]            = 0048acbc
    //         0046a445     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0046a44b     PUSH       EAX
    //         0046a44c     CALL       RGE_Base_Game::set_mouse_cursor                  void set_mouse_cursor(RGE_Base_Game * this, v
    //                              Panel_ez.cpp:1950 (13)
    //         0046a451     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0046a457     PUSH       0x0
    //         0046a459     CALL       RGE_Base_Game::set_mouse_facet                   void set_mouse_facet(RGE_Base_Game * this, lo
    //                              Panel_ez.cpp:1951 (24)
    //         0046a45e     MOV        this,dword ptr [ESI + 0x474]
    //         0046a464     MOV        EDX,dword ptr [rge_base_game]                    = 00000000
    //         0046a46a     PUSH       this
    //         0046a46b     MOV        this,dword ptr [EDX + 0x1c0]
    //         0046a471     CALL       TMousePointer::set_game_enable                   void set_game_enable(TMousePointer * this, in
    //                              Panel_ez.cpp:1953 (10)
    //         0046a476     CMP        byte ptr [ESP + 0x400],0x1
    //         0046a47e     JNZ        LAB_0046a4bf
    //                              Panel_ez.cpp:1955 (40)
    //         0046a480     MOV        EDI,dword ptr [ESP + 0x408]
    //         0046a487     MOV        EBP,dword ptr [ESP + 0x404]
    //         0046a48e     MOV        EAX,dword ptr [ESI]
    //         0046a490     PUSH       EDI
    //         0046a491     LEA        this,[ESP + 0x10]
    //         0046a495     PUSH       EBP
    //         0046a496     LEA        EDX,[ESP + 0x18]
    //         0046a49a     PUSH       this
    //         0046a49b     PUSH       EDX
    //         0046a49c     MOV        this,ESI
    //         0046a49e     CALL       dword ptr [EAX + 0xcc]
    //         0046a4a4     TEST       AL,AL
    //         0046a4a6     JZ         LAB_0046a4bf
    //                              Panel_ez.cpp:1956 (24)
    //         0046a4a8     MOV        EAX,dword ptr [ESP + 0xc]
    //         0046a4ac     MOV        EDX,dword ptr [ESI + 0x1c]
    //         0046a4af     PUSH       EDI
    //         0046a4b0     PUSH       EBP=>DAT_fffffff8
    //         0046a4b1     LEA        this,[ESP + 0x1c]
    //         0046a4b5     PUSH       EAX=>DAT_fffffff4
    //         0046a4b6     PUSH       this=>DAT_fffffff0
    //         0046a4b7     PUSH       EDX
    //         0046a4b8     MOV        this,ESI
    //         0046a4ba     CALL       TEasy_Panel::command_help                        void command_help(TEasy_Panel * this, char * 
    //                               LAB_0046a4bf                                                 XREF[2]:     0046a47e(j), 0046a4a6(j)  
    //         0046a4bf     POP        EBP
    //                              Panel_ez.cpp:1958 (6)
    //         0046a4c0     MOV        EAX,0x1
    //         0046a4c5     POP        EDI
    //                              Panel_ez.cpp:1961 (10)
    //         0046a4c6     POP        ESI
    //         0046a4c7     ADD        ESP,0x3f0
    //         0046a4cd     RET        0xc
    //                               LAB_0046a4d0                                                 XREF[1]:     0046a429(j)  
    //                              Panel_ez.cpp:1960 (2)
    //         0046a4d0     XOR        EAX,EAX
    //                              Panel_ez.cpp:1961 (10)
    //         0046a4d2     POP        ESI
    //         0046a4d3     ADD        ESP,0x3f0
    //         0046a4d9     RET        0xc
}

// Offset: 0x0046A4E0
long Time_Line_Panel::action(TPanel* param_1, long param_2, ulong param_3, ulong param_4) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual long __thiscall TEasy_Panel::action(class TPanel *,long,unsigned long,unsigned long)  *
    //                              *********************************************************************************************************
    //                              long __thiscall action(TEasy_Panel * this, TPanel * param_1, long pa
    //              long              EAX:4          <RETURN>
    //              TEasy_Panel *     ECX:4 (auto)   this
    //              TPanel *          Stack[0x4]:4   param_1                   XREF[1]:     0046a4e4(R)  
    //              long              Stack[0x8]:4   param_2                   XREF[4]:     0046a53a(R), 0046a5ae(R), 0046a622(R), 0046a657(R)  
    //              ulong             Stack[0xc]:4   param_3                   XREF[1]:     0046a653(R)  
    //              ulong             Stack[0x10]:4  param_4                   XREF[1]:     0046a64f(R)  
    //                               ?action@TEasy_Panel@@UAEJPAVTPanel@@JKK@Z                    XREF[36]:    action:0043b52e(c), 
    //                               TEasy_Panel::action                                                       action:0043f30f(c), 
    //                                                                                                         action:0043fc4d(c), 
    //                                                                                                         action:004400f2(c), 
    //                                                                                                         action:00441827(c), 
    //                                                                                                         action:0048f4f2(c), 
    //                                                                                                         action:00491188(c), 
    //                                                                                                         action:004920a2(c), 
    //                                                                                                         action:00493d3d(c), 
    //                                                                                                         action:0049874f(c), 
    //                                                                                                         action:0049d6d4(c), 
    //                                                                                                         action:0049e6ad(c), 
    //                                                                                                         action:0049f0b1(c), 
    //                                                                                                         action:0049fea2(c), 
    //                                                                                                         action:004a1f8d(c), 
    //                                                                                                         action:004a615a(c), 
    //                                                                                                         action:004a6d22(c), 
    //                                                                                                         action:004a71ad(c), 
    //                                                                                                         action:004b33af(c), 
    //                                                                                                         action:004b5df0(c), [more]
    //                              Panel_ez.cpp:1967 (4)
    //         0046a4e0     PUSH       EBX
    //         0046a4e1     PUSH       EBP
    //         0046a4e2     PUSH       ESI
    //         0046a4e3     PUSH       EDI
    //                              Panel_ez.cpp:1968 (14)
    //         0046a4e4     MOV        EDI,dword ptr [ESP + param_1]
    //         0046a4e8     MOV        EBP,this
    //         0046a4ea     TEST       EDI,EDI
    //         0046a4ec     JZ         LAB_0046a64f
    //                              Panel_ez.cpp:1970 (72)
    //         0046a4f2     MOV        this,EDI
    //         0046a4f4     CALL       TPanel::panelName                                char * panelName(TPanel * this)
    //         0046a4f9     TEST       EAX,EAX
    //         0046a4fb     JZ         LAB_0046a566
    //         0046a4fd     MOV        this,EDI
    //         0046a4ff     MOV        ESI,s_OKDialog                                   = 4Fh
    //         0046a504     CALL       TPanel::panelName                                char * panelName(TPanel * this)
    //                               LAB_0046a509                                                 XREF[1]:     0046a52b(j)  
    //         0046a509     MOV        DL,byte ptr [EAX]
    //         0046a50b     MOV        BL,byte ptr [ESI]=>s_OKDialog                    = 4Fh
    //                                                                                  = 44h
    //         0046a50d     MOV        this,DL
    //         0046a50f     CMP        DL,BL
    //         0046a511     JNZ        LAB_0046a531
    //         0046a513     TEST       this,this
    //         0046a515     JZ         LAB_0046a52d
    //         0046a517     MOV        DL,byte ptr [EAX + 0x1]
    //         0046a51a     MOV        BL,byte ptr [ESI + 0x1]=>DAT_00584eb5            = 4Bh
    //                                                                                  = "ialog"
    //         0046a51d     MOV        this,DL
    //         0046a51f     CMP        DL,BL
    //         0046a521     JNZ        LAB_0046a531
    //         0046a523     ADD        EAX,0x2
    //         0046a526     ADD        ESI,0x2
    //         0046a529     TEST       this,this
    //         0046a52b     JNZ        LAB_0046a509
    //                               LAB_0046a52d                                                 XREF[1]:     0046a515(j)  
    //         0046a52d     XOR        EAX,EAX
    //         0046a52f     JMP        LAB_0046a536
    //                               LAB_0046a531                                                 XREF[2]:     0046a511(j), 0046a521(j)  
    //         0046a531     SBB        EAX,EAX
    //         0046a533     SBB        EAX,-0x1
    //                               LAB_0046a536                                                 XREF[1]:     0046a52f(j)  
    //         0046a536     TEST       EAX,EAX
    //         0046a538     JNZ        LAB_0046a566
    //                              Panel_ez.cpp:1972 (17)
    //         0046a53a     MOV        EAX,dword ptr [ESP + param_2]
    //         0046a53e     TEST       EAX,EAX
    //         0046a540     JZ         LAB_0046a54b
    //         0046a542     CMP        EAX,0x1
    //         0046a545     JNZ        LAB_0046a643
    //                               LAB_0046a54b                                                 XREF[1]:     0046a540(j)  
    //                              Panel_ez.cpp:1973 (15)
    //         0046a54b     PUSH       s_OKDialog                                       = 4Fh
    //         0046a550     MOV        this,panel_system
    //         0046a555     CALL       TPanelSystem::destroyPanel                       int destroyPanel(TPanelSystem * this, char * 
    //                              Panel_ez.cpp:1975 (5)
    //         0046a55a     MOV        EAX,0x1
    //                              Panel_ez.cpp:1996 (7)
    //         0046a55f     POP        EDI
    //         0046a560     POP        ESI
    //         0046a561     POP        EBP
    //         0046a562     POP        EBX
    //         0046a563     RET        0x10
    //                               LAB_0046a566                                                 XREF[2]:     0046a4fb(j), 0046a538(j)  
    //                              Panel_ez.cpp:1978 (72)
    //         0046a566     MOV        this,EDI
    //         0046a568     CALL       TPanel::panelName                                char * panelName(TPanel * this)
    //         0046a56d     TEST       EAX,EAX
    //         0046a56f     JZ         LAB_0046a5da
    //         0046a571     MOV        this,EDI
    //         0046a573     MOV        ESI,s_YesNoDialog                                = 59h
    //         0046a578     CALL       TPanel::panelName                                char * panelName(TPanel * this)
    //                               LAB_0046a57d                                                 XREF[1]:     0046a59f(j)  
    //         0046a57d     MOV        DL,byte ptr [EAX]
    //         0046a57f     MOV        BL,byte ptr [ESI]=>s_YesNoDialog                 = 59h
    //                                                                                  = 73h
    //         0046a581     MOV        this,DL
    //         0046a583     CMP        DL,BL
    //         0046a585     JNZ        LAB_0046a5a5
    //         0046a587     TEST       this,this
    //         0046a589     JZ         LAB_0046a5a1
    //         0046a58b     MOV        DL,byte ptr [EAX + 0x1]
    //         0046a58e     MOV        BL,byte ptr [ESI + 0x1]=>DAT_00584ec1            = 65h
    //                                                                                  = "NoDialog"
    //         0046a591     MOV        this,DL
    //         0046a593     CMP        DL,BL
    //         0046a595     JNZ        LAB_0046a5a5
    //         0046a597     ADD        EAX,0x2
    //         0046a59a     ADD        ESI,0x2
    //         0046a59d     TEST       this,this
    //         0046a59f     JNZ        LAB_0046a57d
    //                               LAB_0046a5a1                                                 XREF[1]:     0046a589(j)  
    //         0046a5a1     XOR        EAX,EAX
    //         0046a5a3     JMP        LAB_0046a5aa
    //                               LAB_0046a5a5                                                 XREF[2]:     0046a585(j), 0046a595(j)  
    //         0046a5a5     SBB        EAX,EAX
    //         0046a5a7     SBB        EAX,-0x1
    //                               LAB_0046a5aa                                                 XREF[1]:     0046a5a3(j)  
    //         0046a5aa     TEST       EAX,EAX
    //         0046a5ac     JNZ        LAB_0046a5da
    //                              Panel_ez.cpp:1980 (17)
    //         0046a5ae     MOV        EAX,dword ptr [ESP + param_2]
    //         0046a5b2     TEST       EAX,EAX
    //         0046a5b4     JZ         LAB_0046a5bf
    //         0046a5b6     CMP        EAX,0x1
    //         0046a5b9     JNZ        LAB_0046a643
    //                               LAB_0046a5bf                                                 XREF[1]:     0046a5b4(j)  
    //                              Panel_ez.cpp:1981 (15)
    //         0046a5bf     PUSH       s_YesNoDialog                                    = 59h
    //         0046a5c4     MOV        this,panel_system
    //         0046a5c9     CALL       TPanelSystem::destroyPanel                       int destroyPanel(TPanelSystem * this, char * 
    //                              Panel_ez.cpp:1983 (5)
    //         0046a5ce     MOV        EAX,0x1
    //                              Panel_ez.cpp:1996 (7)
    //         0046a5d3     POP        EDI
    //         0046a5d4     POP        ESI
    //         0046a5d5     POP        EBP
    //         0046a5d6     POP        EBX
    //         0046a5d7     RET        0x10
    //                               LAB_0046a5da                                                 XREF[2]:     0046a56f(j), 0046a5ac(j)  
    //                              Panel_ez.cpp:1986 (72)
    //         0046a5da     MOV        this,EDI
    //         0046a5dc     CALL       TPanel::panelName                                char * panelName(TPanel * this)
    //         0046a5e1     TEST       EAX,EAX
    //         0046a5e3     JZ         LAB_0046a64f
    //         0046a5e5     MOV        this,EDI
    //         0046a5e7     MOV        ESI,s_YesNoCancelDialog                          = 59h
    //         0046a5ec     CALL       TPanel::panelName                                char * panelName(TPanel * this)
    //                               LAB_0046a5f1                                                 XREF[1]:     0046a613(j)  
    //         0046a5f1     MOV        DL,byte ptr [EAX]
    //         0046a5f3     MOV        BL,byte ptr [ESI]=>s_YesNoCancelDialog           = 59h
    //                                                                                  = 73h
    //         0046a5f5     MOV        this,DL
    //         0046a5f7     CMP        DL,BL
    //         0046a5f9     JNZ        LAB_0046a619
    //         0046a5fb     TEST       this,this
    //         0046a5fd     JZ         LAB_0046a615
    //         0046a5ff     MOV        DL,byte ptr [EAX + 0x1]
    //         0046a602     MOV        BL,byte ptr [ESI + 0x1]=>DAT_00584ecd            = 65h
    //                                                                                  = "NoCancelDialog"
    //         0046a605     MOV        this,DL
    //         0046a607     CMP        DL,BL
    //         0046a609     JNZ        LAB_0046a619
    //         0046a60b     ADD        EAX,0x2
    //         0046a60e     ADD        ESI,0x2
    //         0046a611     TEST       this,this
    //         0046a613     JNZ        LAB_0046a5f1
    //                               LAB_0046a615                                                 XREF[1]:     0046a5fd(j)  
    //         0046a615     XOR        EAX,EAX
    //         0046a617     JMP        LAB_0046a61e
    //                               LAB_0046a619                                                 XREF[2]:     0046a5f9(j), 0046a609(j)  
    //         0046a619     SBB        EAX,EAX
    //         0046a61b     SBB        EAX,-0x1
    //                               LAB_0046a61e                                                 XREF[1]:     0046a617(j)  
    //         0046a61e     TEST       EAX,EAX
    //         0046a620     JNZ        LAB_0046a64f
    //                              Panel_ez.cpp:1989 (18)
    //         0046a622     MOV        EAX,dword ptr [ESP + param_2]
    //         0046a626     TEST       EAX,EAX
    //         0046a628     JZ         LAB_0046a634
    //         0046a62a     CMP        EAX,0x1
    //         0046a62d     JZ         LAB_0046a634
    //         0046a62f     CMP        EAX,0x2
    //         0046a632     JNZ        LAB_0046a643
    //                               LAB_0046a634                                                 XREF[2]:     0046a628(j), 0046a62d(j)  
    //                              Panel_ez.cpp:1990 (15)
    //         0046a634     PUSH       s_YesNoCancelDialog                              = 59h
    //         0046a639     MOV        this,panel_system
    //         0046a63e     CALL       TPanelSystem::destroyPanel                       int destroyPanel(TPanelSystem * this, char * 
    //                               LAB_0046a643                                                 XREF[3]:     0046a545(j), 0046a5b9(j), 
    //                                                                                                         0046a632(j)  
    //                              Panel_ez.cpp:1992 (5)
    //         0046a643     MOV        EAX,0x1
    //                              Panel_ez.cpp:1996 (7)
    //         0046a648     POP        EDI
    //         0046a649     POP        ESI
    //         0046a64a     POP        EBP
    //         0046a64b     POP        EBX
    //         0046a64c     RET        0x10
    //                               LAB_0046a64f                                                 XREF[3]:     0046a4ec(j), 0046a5e3(j), 
    //                                                                                                         0046a620(j)  
    //                              Panel_ez.cpp:1995 (23)
    //         0046a64f     MOV        EAX,dword ptr [ESP + param_4]
    //         0046a653     MOV        this,dword ptr [ESP + param_3]
    //         0046a657     MOV        EDX,dword ptr [ESP + param_2]
    //         0046a65b     PUSH       EAX
    //         0046a65c     PUSH       this
    //         0046a65d     PUSH       EDX
    //         0046a65e     PUSH       EDI
    //         0046a65f     MOV        this,EBP
    //         0046a661     CALL       TPanel::action                                   long action(TPanel * this, TPanel * param_1, 
    //                              Panel_ez.cpp:1996 (7)
    //         0046a666     POP        EDI
    //         0046a667     POP        ESI
    //         0046a668     POP        EBP
    //         0046a669     POP        EBX
    //         0046a66a     RET        0x10
}

// Offset: 0x0046A670
void set_system_colors(TEasy_Panel* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TEasy_Panel::set_system_colors(void)                                          *
    //                              *********************************************************************************************************
    //                              void __thiscall set_system_colors(TEasy_Panel * this)
    //              void              <VOID>         <RETURN>
    //              TEasy_Panel *     ECX:4 (auto)   this
    //              undefined6        Stack[-0x8]:6  local_8                   XREF[4,4]:   0046a677(*), 0046a69f(R), 0046a6ea(*), 0046a6fd(R), 
    //                                                                                     0046a69b(R), 0046a6f9(R), 0046a697(R), 0046a6f5(R)  
    //              tagPALETTEENTRY   Stack[-0xc]:4  pe                        XREF[4]:     0046a6c4(*), 0046a6d4(W), 0046a717(*), 0046a720(W)  
    //              int               Stack[-0x10]:4 elems                     XREF[4]:     0046a6c8(W), 0046a6cc(*), 0046a728(W), 0046a72c(*)  
    //              ulong             Stack[-0x14]:4 cols
    //                               ?set_system_colors@TEasy_Panel@@QAEXXZ
    //                               TEasy_Panel::set_system_colors
    //                              Panel_ez.cpp:2002 (7)
    //         0046a670     SUB        ESP,0x10
    //         0046a673     PUSH       EBX
    //         0046a674     PUSH       ESI
    //         0046a675     MOV        ESI,this
    //                              Panel_ez.cpp:2004 (32)
    //         0046a677     LEA        EAX=>local_8,[ESP + 0x10]
    //         0046a67b     XOR        this,this
    //         0046a67d     PUSH       EDI
    //         0046a67e     MOV        this,byte ptr [ESI + 0xef]
    //         0046a684     MOV        EDX,dword ptr [ESI + 0x20c]
    //         0046a68a     MOV        EDI,dword ptr [->GDI32.DLL::GetPaletteEntries]   = 0048b270
    //         0046a690     PUSH       EAX
    //         0046a691     PUSH       0x1
    //         0046a693     PUSH       this
    //         0046a694     PUSH       EDX
    //         0046a695     CALL       EDI=>GDI32.DLL::GetPaletteEntries
    //                              Panel_ez.cpp:2006 (34)
    //         0046a697     MOV        EAX,dword ptr [ESP + local_8+0x2]
    //         0046a69b     MOV        this,dword ptr [ESP + local_8+0x1]
    //         0046a69f     MOV        EDX,dword ptr [ESP + local_8]
    //         0046a6a3     AND        EAX,0xff
    //         0046a6a8     SHL        EAX,0x8
    //         0046a6ab     AND        this,0xff
    //         0046a6b1     AND        EDX,0xff
    //         0046a6b7     OR         EAX,this
    //                              Panel_ez.cpp:2007 (37)
    //         0046a6b9     MOV        EBX,dword ptr [->USER32.DLL::SetSysColors]       = 0048b038
    //         0046a6bf     SHL        EAX,0x8
    //         0046a6c2     OR         EAX,EDX
    //         0046a6c4     LEA        this=>pe,[ESP + 0x10]
    //         0046a6c8     MOV        dword ptr [ESP + elems],EAX
    //         0046a6cc     LEA        EAX=>elems,[ESP + 0xc]
    //         0046a6d0     PUSH       EAX
    //         0046a6d1     PUSH       this
    //         0046a6d2     PUSH       0x1
    //         0046a6d4     MOV        dword ptr [ESP + pe.peRed],0x5
    //         0046a6dc     CALL       EBX=>USER32.DLL::SetSysColors
    //                              Panel_ez.cpp:2009 (23)
    //         0046a6de     MOV        EAX,dword ptr [ESI + 0x328]
    //         0046a6e4     MOV        this,dword ptr [ESI + 0x20c]
    //         0046a6ea     LEA        EDX=>local_8,[ESP + 0x14]
    //         0046a6ee     PUSH       EDX
    //         0046a6ef     PUSH       0x1
    //         0046a6f1     PUSH       EAX
    //         0046a6f2     PUSH       this
    //         0046a6f3     CALL       EDI=>GDI32.DLL::GetPaletteEntries
    //                              Panel_ez.cpp:2011 (34)
    //         0046a6f5     MOV        EDX,dword ptr [ESP + local_8+0x2]
    //         0046a6f9     MOV        EAX,dword ptr [ESP + local_8+0x1]
    //         0046a6fd     MOV        this,dword ptr [ESP + local_8]
    //         0046a701     AND        EDX,0xff
    //         0046a707     SHL        EDX,0x8
    //         0046a70a     AND        EAX,0xff
    //         0046a70f     AND        this,0xff
    //         0046a715     OR         EDX,EAX
    //                              Panel_ez.cpp:2012 (31)
    //         0046a717     LEA        EAX=>pe,[ESP + 0x10]
    //         0046a71b     SHL        EDX,0x8
    //         0046a71e     OR         EDX,this
    //         0046a720     MOV        dword ptr [ESP + pe.peRed],0x8
    //         0046a728     MOV        dword ptr [ESP + elems],EDX
    //         0046a72c     LEA        EDX=>elems,[ESP + 0xc]
    //         0046a730     PUSH       EDX
    //         0046a731     PUSH       EAX
    //         0046a732     PUSH       0x1
    //         0046a734     CALL       EBX=>USER32.DLL::SetSysColors
    //                              Panel_ez.cpp:2013 (7)
    //         0046a736     POP        EDI
    //         0046a737     POP        ESI
    //         0046a738     POP        EBX
    //         0046a739     ADD        ESP,0x10
    //         0046a73c     RET
}

