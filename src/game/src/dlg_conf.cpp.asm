// Auto-generated scaffold unit: dlg_conf.cpp.asm
// SourceMap: C:/msdev/work/age1_x1/dlg_conf.cpp
#include "../include/common.h"

// Offset: 0x0043B560
undefined TribeConfigDialog(TribeConfigDialog* this_, Mode param_2, TScreenPanel* param_3) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall TribeConfigDialog::TribeConfigDialog(enum TribeConfigDialog::Mode,class TScreen... *
    //                              *********************************************************************************************************
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
}

// Offset: 0x0043C0C0
void TribeConfigDialog(TribeConfigDialog* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual __thiscall TribeConfigDialog::~TribeConfigDialog(void)                                *
    //                              *********************************************************************************************************
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
}

// Offset: 0x0043C2B0
long TribeConfigDialog::action(TPanel* param_1, long param_2, ulong param_3, ulong param_4) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual long __thiscall TribeConfigDialog::action(class TPanel *,long,unsigned long,unsign... *
    //                              *********************************************************************************************************
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
}

