#include "common.h"
#include "rpnl_tbx.h"

RGE_Panel_Tool_Box::~RGE_Panel_Tool_Box() {
    /* TODO: Stub */
    //                              void __thiscall ~RGE_Panel_Tool_Box(RGE_Panel_Tool_Box * this)
    //              void              <VOID>         <RETURN>
    //              RGE_Panel_Tool    ECX:4 (auto)   this
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     00489eb9(W)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     00489ea9(W)  
    //                               ??1RGE_Panel_Tool_Box@@UAE@XZ                                XREF[1]:     `vector_deleting_destructor':00489
    //                               RGE_Panel_Tool_Box::~RGE_Panel_Tool_Box
    //                              rpnl_tbx.cpp:166 (35)
    //         00489e90     PUSH       -0x1
    //         00489e92     PUSH       FUN_0055e758
    //         00489e97     MOV        EAX,FS:[0x0]
    //         00489e9d     PUSH       EAX
    //         00489e9e     MOV        dword ptr FS:[0x0],ESP
    //         00489ea5     PUSH       this
    //         00489ea6     PUSH       ESI
    //         00489ea7     MOV        ESI,this
    //         00489ea9     MOV        dword ptr [ESP + local_10],ESI
    //         00489ead     MOV        dword ptr [ESI],RGE_Panel_Tool_Box::`vftable'    = 00489e70
    //                              rpnl_tbx.cpp:167 (24)
    //         00489eb3     MOV        this,dword ptr [ESI + 0x100]
    //         00489eb9     MOV        dword ptr [ESP + local_4],0x0
    //         00489ec1     TEST       this,this
    //         00489ec3     JZ         LAB_00489ecb
    //         00489ec5     MOV        EAX,dword ptr [this->_padding_]
    //         00489ec7     PUSH       0x1
    //         00489ec9     CALL       dword ptr [EAX]
    //                               LAB_00489ecb                                                 XREF[1]:     00489ec3(j)  
    //                              rpnl_tbx.cpp:168 (16)
    //         00489ecb     MOV        this,dword ptr [ESI + 0x104]
    //         00489ed1     TEST       this,this
    //         00489ed3     JZ         LAB_00489edb
    //         00489ed5     MOV        EDX,dword ptr [this->_padding_]
    //         00489ed7     PUSH       0x1
    //         00489ed9     CALL       dword ptr [EDX]
    //                               LAB_00489edb                                                 XREF[1]:     00489ed3(j)  
    //                              rpnl_tbx.cpp:169 (16)
    //         00489edb     MOV        this,dword ptr [ESI + 0x10c]
    //         00489ee1     TEST       this,this
    //         00489ee3     JZ         LAB_00489eeb
    //         00489ee5     MOV        EAX,dword ptr [this->_padding_]
    //         00489ee7     PUSH       0x1
    //         00489ee9     CALL       dword ptr [EAX]
    //                               LAB_00489eeb                                                 XREF[1]:     00489ee3(j)  
    //                              rpnl_tbx.cpp:170 (16)
    //         00489eeb     MOV        this,dword ptr [ESI + 0x108]
    //         00489ef1     TEST       this,this
    //         00489ef3     JZ         LAB_00489efb
    //         00489ef5     MOV        EDX,dword ptr [this->_padding_]
    //         00489ef7     PUSH       0x1
    //         00489ef9     CALL       dword ptr [EDX]
    //                               LAB_00489efb                                                 XREF[1]:     00489ef3(j)  
    //                              rpnl_tbx.cpp:171 (16)
    //         00489efb     MOV        this,dword ptr [ESI + 0x110]
    //         00489f01     TEST       this,this
    //         00489f03     JZ         LAB_00489f0b
    //         00489f05     MOV        EAX,dword ptr [this->_padding_]
    //         00489f07     PUSH       0x1
    //         00489f09     CALL       dword ptr [EAX]
    //                               LAB_00489f0b                                                 XREF[1]:     00489f03(j)  
    //                              rpnl_tbx.cpp:172 (16)
    //         00489f0b     MOV        this,dword ptr [ESI + 0x114]
    //         00489f11     TEST       this,this
    //         00489f13     JZ         LAB_00489f1b
    //         00489f15     MOV        EDX,dword ptr [this->_padding_]
    //         00489f17     PUSH       0x1
    //         00489f19     CALL       dword ptr [EDX]
    //                               LAB_00489f1b                                                 XREF[1]:     00489f13(j)  
    //                              rpnl_tbx.cpp:173 (18)
    //         00489f1b     MOV        this,dword ptr [ESI + 0x118]
    //         00489f21     TEST       this,this
    //         00489f23     JZ         LAB_00489f2b
    //         00489f25     MOV        EAX,dword ptr [this->_padding_]
    //         00489f27     PUSH       0x1
    //         00489f29     CALL       dword ptr [EAX]
    //                               LAB_00489f2b                                                 XREF[1]:     00489f23(j)  
    //         00489f2b     MOV        this,ESI
    //                              rpnl_tbx.cpp:174 (29)
    //         00489f2d     MOV        dword ptr [ESP + 0x10],0xffffffff
    //         00489f35     CALL       TPanel::~TPanel                                  void ~TPanel(TPanel * this)
    //         00489f3a     MOV        this,dword ptr [ESP + 0x8]
    //         00489f3e     POP        ESI
    //         00489f3f     MOV        dword ptr FS:[0x0],this
    //         00489f46     ADD        ESP,0x10
    //         00489f49     RET
    //         00489f4a     ??         90h
    //         00489f4b     NOP
    //         00489f4c     NOP
    //         00489f4d     NOP
    //         00489f4e     NOP
    //         00489f4f     NOP
    //                              * public: virtual long __thiscall RGE_Panel_Tool_Box::action(class TPanel *,long,unsigned long,unsig... *
    //                              long __thiscall action(RGE_Panel_Tool_Box * this, TPanel * param_1, 
    //              long              EAX:4          <RETURN>
    //              RGE_Panel_Tool    ECX:4 (auto)   this
    //              TPanel *          Stack[0x4]:4   param_1                   XREF[1]:     00489f5e(R)  
    //              long              Stack[0x8]:4   param_2                   XREF[4]:     00489f7e(R), 00489fd3(W), 0048a1d2(R), 0048a275(R)  
    //              ulong             Stack[0xc]:4   param_3
    //              ulong             Stack[0x10]:4  param_4
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     00489fd9(W), 00489ff5(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[3]:     0048a069(R), 0048a2f3(R), 0048a307(R)  
    //                               ?action@RGE_Panel_Tool_Box@@UAEJPAVTPanel@@JKK@Z             XREF[1]:     00572014(*)  
    //                               RGE_Panel_Tool_Box::action
    //                              rpnl_tbx.cpp:180 (14)
    //         00489f50     MOV        EAX,FS:[0x0]
    //         00489f56     PUSH       -0x1
    //         00489f58     PUSH       FUN_0055e77b
    //         00489f5d     PUSH       EAX
    //                              rpnl_tbx.cpp:181 (18)
    //         00489f5e     MOV        EAX,dword ptr [ESP + param_1]
    //         00489f62     MOV        dword ptr FS:[0x0],ESP
    //         00489f69     PUSH       EBP
    //         00489f6a     PUSH       ESI
    //         00489f6b     TEST       EAX,EAX
    //         00489f6d     PUSH       EDI
    //         00489f6e     MOV        EBP,this
    //                              rpnl_tbx.cpp:182 (6)
    //         00489f70     JZ         LAB_0048a307
    //                              rpnl_tbx.cpp:187 (19)
    //         00489f76     MOV        this,dword ptr [EBP + 0x100]
    //         00489f7c     CMP        EAX,this
    //         00489f7e     MOV        this,dword ptr [ESP + param_2]
    //         00489f82     JNZ        LAB_00489fb1
    //         00489f84     CMP        this,0x1
    //         00489f87     JNZ        LAB_00489fb1
    //                              rpnl_tbx.cpp:189 (15)
    //         00489f89     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         00489f8f     PUSH       0x0
    //         00489f91     PUSH       0x0
    //         00489f93     MOV        EAX,dword ptr [this->_padding_]
    //         00489f95     CALL       dword ptr [EAX + 0x10]
    //                              rpnl_tbx.cpp:190 (5)
    //         00489f98     MOV        EAX,0x1
    //                              rpnl_tbx.cpp:306 (20)
    //         00489f9d     MOV        this,dword ptr [ESP + 0xc]
    //         00489fa1     MOV        dword ptr FS:[0x0],this
    //         00489fa8     POP        EDI
    //         00489fa9     POP        ESI
    //         00489faa     POP        EBP
    //         00489fab     ADD        ESP,0xc
    //         00489fae     RET        0x10
    //                               LAB_00489fb1                                                 XREF[2]:     00489f82(j), 00489f87(j)  
    //                              rpnl_tbx.cpp:196 (21)
    //         00489fb1     CMP        EAX,dword ptr [EBP + 0x104]
    //         00489fb7     JNZ        LAB_0048a07d
    //         00489fbd     CMP        this,0x1
    //         00489fc0     JNZ        LAB_0048a07d
    //                              language.dll match for 0x4bc: "Intentional drop of Ser#%d  Cm
    //                              rpnl_tbx.cpp:198 (45)
    //         00489fc6     PUSH       0x4bc
    //         00489fcb     CALL       operator_new                                     void * operator_new(uint param_1)
    //         00489fd0     ADD        ESP,0x4
    //         00489fd3     MOV        dword ptr [ESP + param_2],EAX
    //         00489fd7     TEST       EAX,EAX
    //         00489fd9     MOV        dword ptr [ESP + local_4],0x0
    //         00489fe1     JZ         LAB_00489ff1
    //         00489fe3     PUSH       s_Object_List_Dialog                             = 4Fh
    //         00489fe8     MOV        this,EAX
    //         00489fea     CALL       RGE_Dialog_List::RGE_Dialog_List                 undefined RGE_Dialog_List(RGE_Dialog_List * t
    //         00489fef     JMP        LAB_00489ff3
    //                               LAB_00489ff1                                                 XREF[1]:     00489fe1(j)  
    //         00489ff1     XOR        EAX,EAX
    //                               LAB_00489ff3                                                 XREF[1]:     00489fef(j)  
    //                              rpnl_tbx.cpp:199 (87)
    //         00489ff3     TEST       EAX,EAX
    //         00489ff5     MOV        dword ptr [ESP + local_4],0xffffffff
    //         00489ffd     MOV        dword ptr [EBP + 0x11c],EAX
    //         0048a003     JZ         LAB_0048a2ee
    //                              language.dll match for 0x232a: "Select Object"
    //         0048a009     PUSH       0x232a
    //         0048a00e     MOV        this,EBP
    //         0048a010     CALL       TPanel::get_string                               char * get_string(TPanel * this, int param_1)
    //         0048a015     MOV        this,dword ptr [EBP + 0xf4]
    //         0048a01b     PUSH       EAX
    //         0048a01c     PUSH       0x1
    //         0048a01e     CALL       TEasy_Panel::get_popup_info_id                   long get_popup_info_id(TEasy_Panel * this)
    //         0048a023     MOV        this,dword ptr [EBP + 0xf4]
    //         0048a029     PUSH       EAX
    //         0048a02a     CALL       TEasy_Panel::get_popup_info_file                 char * get_popup_info_file(TEasy_Panel * this)
    //         0048a02f     MOV        this,dword ptr [EBP + 0xf4]
    //         0048a035     PUSH       EAX
    //         0048a036     PUSH       this
    //         0048a037     MOV        this,dword ptr [EBP + 0x11c]
    //         0048a03d     CALL       RGE_Dialog_List::setup                           int setup(RGE_Dialog_List * this, TScreenPane
    //         0048a042     TEST       EAX,EAX
    //         0048a044     JNZ        LAB_0048a2ee
    //                              rpnl_tbx.cpp:201 (16)
    //         0048a04a     MOV        this,dword ptr [EBP + 0x11c]
    //         0048a050     TEST       this,this
    //         0048a052     JZ         LAB_0048a05a
    //         0048a054     MOV        EDX,dword ptr [this->_padding_]
    //         0048a056     PUSH       0x1
    //         0048a058     CALL       dword ptr [EDX]
    //                               LAB_0048a05a                                                 XREF[1]:     0048a052(j)  
    //                              rpnl_tbx.cpp:202 (10)
    //         0048a05a     MOV        dword ptr [EBP + 0x11c],0x0
    //                              rpnl_tbx.cpp:204 (5)
    //         0048a064     MOV        EAX,0x1
    //                              rpnl_tbx.cpp:306 (20)
    //         0048a069     MOV        this,dword ptr [ESP + local_c]
    //         0048a06d     MOV        dword ptr FS:[0x0],this
    //         0048a074     POP        EDI
    //         0048a075     POP        ESI
    //         0048a076     POP        EBP
    //         0048a077     ADD        ESP,0xc
    //         0048a07a     RET        0x10
    //                               LAB_0048a07d                                                 XREF[2]:     00489fb7(j), 00489fc0(j)  
    //                              rpnl_tbx.cpp:210 (13)
    //         0048a07d     CMP        EAX,dword ptr [EBP + 0x10c]
    //         0048a083     JNZ        LAB_0048a0b2
    //         0048a085     CMP        this,0x1
    //         0048a088     JNZ        LAB_0048a0b2
    //                              rpnl_tbx.cpp:212 (15)
    //         0048a08a     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0048a090     PUSH       0x0
    //         0048a092     PUSH       0x12
    //         0048a094     MOV        EAX,dword ptr [this->_padding_]
    //         0048a096     CALL       dword ptr [EAX + 0x10]
    //                              rpnl_tbx.cpp:213 (5)
    //         0048a099     MOV        EAX,0x1
    //                              rpnl_tbx.cpp:306 (20)
    //         0048a09e     MOV        this,dword ptr [ESP + 0xc]
    //         0048a0a2     MOV        dword ptr FS:[0x0],this
    //         0048a0a9     POP        EDI
    //         0048a0aa     POP        ESI
    //         0048a0ab     POP        EBP
    //         0048a0ac     ADD        ESP,0xc
    //         0048a0af     RET        0x10
    //                               LAB_0048a0b2                                                 XREF[2]:     0048a083(j), 0048a088(j)  
    //                              rpnl_tbx.cpp:219 (13)
    //         0048a0b2     CMP        EAX,dword ptr [EBP + 0x108]
    //         0048a0b8     JNZ        LAB_0048a0e7
    //         0048a0ba     CMP        this,0x1
    //         0048a0bd     JNZ        LAB_0048a0e7
    //                              rpnl_tbx.cpp:221 (15)
    //         0048a0bf     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0048a0c5     PUSH       0x0
    //         0048a0c7     PUSH       0xe
    //         0048a0c9     MOV        EDX,dword ptr [this->_padding_]
    //         0048a0cb     CALL       dword ptr [EDX + 0x10]
    //                              rpnl_tbx.cpp:222 (5)
    //         0048a0ce     MOV        EAX,0x1
    //                              rpnl_tbx.cpp:306 (20)
    //         0048a0d3     MOV        this,dword ptr [ESP + 0xc]
    //         0048a0d7     MOV        dword ptr FS:[0x0],this
    //         0048a0de     POP        EDI
    //         0048a0df     POP        ESI
    //         0048a0e0     POP        EBP
    //         0048a0e1     ADD        ESP,0xc
    //         0048a0e4     RET        0x10
    //                               LAB_0048a0e7                                                 XREF[2]:     0048a0b8(j), 0048a0bd(j)  
    //                              rpnl_tbx.cpp:242 (13)
    //         0048a0e7     CMP        EAX,dword ptr [EBP + 0x114]
    //         0048a0ed     JNZ        LAB_0048a11c
    //         0048a0ef     CMP        this,0x1
    //         0048a0f2     JNZ        LAB_0048a11c
    //                              rpnl_tbx.cpp:244 (15)
    //         0048a0f4     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0048a0fa     PUSH       0x0
    //         0048a0fc     PUSH       0x3
    //         0048a0fe     MOV        EAX,dword ptr [this->_padding_]
    //         0048a100     CALL       dword ptr [EAX + 0x10]
    //                              rpnl_tbx.cpp:245 (5)
    //         0048a103     MOV        EAX,0x1
    //                              rpnl_tbx.cpp:306 (20)
    //         0048a108     MOV        this,dword ptr [ESP + 0xc]
    //         0048a10c     MOV        dword ptr FS:[0x0],this
    //         0048a113     POP        EDI
    //         0048a114     POP        ESI
    //         0048a115     POP        EBP
    //         0048a116     ADD        ESP,0xc
    //         0048a119     RET        0x10
    //                               LAB_0048a11c                                                 XREF[2]:     0048a0ed(j), 0048a0f2(j)  
    //                              rpnl_tbx.cpp:251 (13)
    //         0048a11c     CMP        EAX,dword ptr [EBP + 0x118]
    //         0048a122     JNZ        LAB_0048a187
    //         0048a124     CMP        this,0x1
    //         0048a127     JNZ        LAB_0048a187
    //                              rpnl_tbx.cpp:253 (12)
    //         0048a129     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0048a12f     MOV        EAX,dword ptr [this->_padding_ + 0x1b0]
    //                              rpnl_tbx.cpp:255 (12)
    //         0048a135     MOV        EDX,dword ptr [this->_padding_]
    //         0048a137     CMP        EAX,0x4
    //         0048a13a     JNZ        LAB_0048a169
    //         0048a13c     PUSH       0x6
    //         0048a13e     CALL       dword ptr [EDX + 0xc]
    //                              rpnl_tbx.cpp:256 (11)
    //         0048a141     MOV        EAX,[rge_base_game]                              = 00000000
    //         0048a146     MOV        this,dword ptr [EAX + 0x3f4]
    //                              rpnl_tbx.cpp:302 (9)
    //         0048a14c     MOV        EAX,0x1
    //         0048a151     MOV        byte ptr [ECX + this->_padding_],0x1
    //                              rpnl_tbx.cpp:306 (20)
    //         0048a155     MOV        this,dword ptr [ESP + 0xc]
    //         0048a159     MOV        dword ptr FS:[0x0],this
    //         0048a160     POP        EDI
    //         0048a161     POP        ESI
    //         0048a162     POP        EBP
    //         0048a163     ADD        ESP,0xc
    //         0048a166     RET        0x10
    //                               LAB_0048a169                                                 XREF[1]:     0048a13a(j)  
    //                              rpnl_tbx.cpp:259 (5)
    //         0048a169     PUSH       0x4
    //         0048a16b     CALL       dword ptr [EDX + 0xc]
    //                              rpnl_tbx.cpp:260 (5)
    //         0048a16e     MOV        EAX,0x1
    //                              rpnl_tbx.cpp:306 (20)
    //         0048a173     MOV        this,dword ptr [ESP + 0xc]
    //         0048a177     MOV        dword ptr FS:[0x0],this
    //         0048a17e     POP        EDI
    //         0048a17f     POP        ESI
    //         0048a180     POP        EBP
    //         0048a181     ADD        ESP,0xc
    //         0048a184     RET        0x10
    //                               LAB_0048a187                                                 XREF[2]:     0048a122(j), 0048a127(j)  
    //                              rpnl_tbx.cpp:263 (20)
    //         0048a187     MOV        this,dword ptr [EBP + 0x11c]
    //         0048a18d     LEA        EDI,[EBP + 0x11c]
    //         0048a193     CMP        EAX,this
    //         0048a195     JNZ        LAB_0048a307
    //                              rpnl_tbx.cpp:268 (55)
    //         0048a19b     MOV        ESI,s_Object_List_Dialog                         = 4Fh
    //         0048a1a0     CALL       TPanel::panelName                                char * panelName(TPanel * this)
    //                               LAB_0048a1a5                                                 XREF[1]:     0048a1c3(j)  
    //         0048a1a5     MOV        DL,byte ptr [EAX]
    //         0048a1a7     MOV        this,DL
    //         0048a1a9     CMP        DL,byte ptr [ESI]=>s_Object_List_Dialog          = 4Fh
    //                                                                                  = 6Ah
    //         0048a1ab     JNZ        LAB_0048a1c9
    //         0048a1ad     TEST       this,this
    //         0048a1af     JZ         LAB_0048a1c5
    //         0048a1b1     MOV        DL,byte ptr [EAX + 0x1]
    //         0048a1b4     MOV        this,DL
    //         0048a1b6     CMP        DL,byte ptr [ESI + 0x1]=>DAT_00585f99            = 62h
    //                                                                                  = "ect List Dialog"
    //         0048a1b9     JNZ        LAB_0048a1c9
    //         0048a1bb     ADD        EAX,0x2
    //         0048a1be     ADD        ESI,0x2
    //         0048a1c1     TEST       this,this
    //         0048a1c3     JNZ        LAB_0048a1a5
    //                               LAB_0048a1c5                                                 XREF[1]:     0048a1af(j)  
    //         0048a1c5     XOR        EAX,EAX
    //         0048a1c7     JMP        LAB_0048a1ce
    //                               LAB_0048a1c9                                                 XREF[2]:     0048a1ab(j), 0048a1b9(j)  
    //         0048a1c9     SBB        EAX,EAX
    //         0048a1cb     SBB        EAX,-0x1
    //                               LAB_0048a1ce                                                 XREF[1]:     0048a1c7(j)  
    //         0048a1ce     TEST       EAX,EAX
    //         0048a1d0     JNZ        LAB_0048a23c
    //                              rpnl_tbx.cpp:270 (13)
    //         0048a1d2     MOV        EAX,dword ptr [ESP + param_2]
    //         0048a1d6     CMP        EAX,0x1
    //         0048a1d9     JNZ        LAB_0048a2c9
    //                              rpnl_tbx.cpp:272 (16)
    //         0048a1df     MOV        this,dword ptr [EDI]
    //         0048a1e1     MOV        EAX,dword ptr [this->_padding_]
    //         0048a1e3     CALL       dword ptr [EAX + 0x130]
    //         0048a1e9     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //                              rpnl_tbx.cpp:273 (19)
    //         0048a1ef     PUSH       EDI
    //         0048a1f0     MOV        word ptr [this->_padding_ + 0x3fc],AX
    //         0048a1f7     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0048a1fd     CALL       RGE_Base_Game::delete_dialog                     void delete_dialog(RGE_Base_Game * this, TPan
    //                              rpnl_tbx.cpp:274 (15)
    //         0048a202     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0048a208     PUSH       0x0
    //         0048a20a     PUSH       offset DAT_fffffff8
    //         0048a20c     MOV        EDX,dword ptr [this->_padding_]
    //         0048a20e     CALL       dword ptr [EDX + 0x10]
    //                              rpnl_tbx.cpp:275 (18)
    //         0048a211     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0048a217     CALL       RGE_Base_Game::get_player                        RGE_Player * get_player(RGE_Base_Game * this)
    //         0048a21c     MOV        this,EAX
    //         0048a21e     CALL       RGE_Player::unselect_object                      void unselect_object(RGE_Player * this)
    //                              rpnl_tbx.cpp:302 (5)
    //         0048a223     MOV        EAX,0x1
    //                              rpnl_tbx.cpp:306 (20)
    //         0048a228     MOV        this,dword ptr [ESP + 0xc]
    //         0048a22c     MOV        dword ptr FS:[0x0],this
    //         0048a233     POP        EDI
    //         0048a234     POP        ESI
    //         0048a235     POP        EBP
    //         0048a236     ADD        ESP,0xc
    //         0048a239     RET        0x10
    //                               LAB_0048a23c                                                 XREF[1]:     0048a1d0(j)  
    //                              rpnl_tbx.cpp:288 (57)
    //         0048a23c     MOV        this,dword ptr [EDI]
    //         0048a23e     MOV        ESI,s_Terrain_List_Dialog                        = 54h
    //         0048a243     CALL       TPanel::panelName                                char * panelName(TPanel * this)
    //                               LAB_0048a248                                                 XREF[1]:     0048a266(j)  
    //         0048a248     MOV        DL,byte ptr [EAX]
    //         0048a24a     MOV        this,DL
    //         0048a24c     CMP        DL,byte ptr [ESI]=>s_Terrain_List_Dialog         = 54h
    //                                                                                  = 72h
    //         0048a24e     JNZ        LAB_0048a26c
    //         0048a250     TEST       this,this
    //         0048a252     JZ         LAB_0048a268
    //         0048a254     MOV        DL,byte ptr [EAX + 0x1]
    //         0048a257     MOV        this,DL
    //         0048a259     CMP        DL,byte ptr [ESI + 0x1]=>DAT_00585f85            = 65h
    //                                                                                  = "rain List Dialog"
    //         0048a25c     JNZ        LAB_0048a26c
    //         0048a25e     ADD        EAX,0x2
    //         0048a261     ADD        ESI,0x2
    //         0048a264     TEST       this,this
    //         0048a266     JNZ        LAB_0048a248
    //                               LAB_0048a268                                                 XREF[1]:     0048a252(j)  
    //         0048a268     XOR        EAX,EAX
    //         0048a26a     JMP        LAB_0048a271
    //                               LAB_0048a26c                                                 XREF[2]:     0048a24e(j), 0048a25c(j)  
    //         0048a26c     SBB        EAX,EAX
    //         0048a26e     SBB        EAX,-0x1
    //                               LAB_0048a271                                                 XREF[1]:     0048a26a(j)  
    //         0048a271     TEST       EAX,EAX
    //         0048a273     JNZ        LAB_0048a2ee
    //                              rpnl_tbx.cpp:290 (9)
    //         0048a275     MOV        EAX,dword ptr [ESP + param_2]
    //         0048a279     CMP        EAX,0x1
    //         0048a27c     JNZ        LAB_0048a2c9
    //                              rpnl_tbx.cpp:292 (16)
    //         0048a27e     MOV        this,dword ptr [EDI]
    //         0048a280     MOV        EAX,dword ptr [this->_padding_]
    //         0048a282     CALL       dword ptr [EAX + 0x130]
    //         0048a288     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //                              rpnl_tbx.cpp:293 (19)
    //         0048a28e     PUSH       EDI
    //         0048a28f     MOV        word ptr [this->_padding_ + 0x3fe],AX
    //         0048a296     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0048a29c     CALL       RGE_Base_Game::delete_dialog                     void delete_dialog(RGE_Base_Game * this, TPan
    //                              rpnl_tbx.cpp:294 (15)
    //         0048a2a1     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0048a2a7     PUSH       0x0
    //         0048a2a9     PUSH       offset DAT_fffffff8
    //         0048a2ab     MOV        EDX,dword ptr [this->_padding_]
    //         0048a2ad     CALL       dword ptr [EDX + 0x10]
    //                              rpnl_tbx.cpp:302 (5)
    //         0048a2b0     MOV        EAX,0x1
    //                              rpnl_tbx.cpp:306 (20)
    //         0048a2b5     MOV        this,dword ptr [ESP + 0xc]
    //         0048a2b9     MOV        dword ptr FS:[0x0],this
    //         0048a2c0     POP        EDI
    //         0048a2c1     POP        ESI
    //         0048a2c2     POP        EBP
    //         0048a2c3     ADD        ESP,0xc
    //         0048a2c6     RET        0x10
    //                               LAB_0048a2c9                                                 XREF[2]:     0048a1d9(j), 0048a27c(j)  
    //                              rpnl_tbx.cpp:296 (5)
    //         0048a2c9     CMP        EAX,0x2
    //         0048a2cc     JNZ        LAB_0048a2ee
    //                              rpnl_tbx.cpp:298 (12)
    //         0048a2ce     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0048a2d4     PUSH       EDI
    //         0048a2d5     CALL       RGE_Base_Game::delete_dialog                     void delete_dialog(RGE_Base_Game * this, TPan
    //                              rpnl_tbx.cpp:299 (20)
    //         0048a2da     MOV        EAX,[rge_base_game]                              = 00000000
    //         0048a2df     MOV        this,EBP
    //         0048a2e1     MOV        EAX,dword ptr [EAX + 0x1b4]
    //         0048a2e7     PUSH       EAX
    //         0048a2e8     PUSH       EAX
    //         0048a2e9     CALL       RGE_Panel_Tool_Box::game_mode_changed            void game_mode_changed(RGE_Panel_Tool_Box * t
    //                               LAB_0048a2ee                                                 XREF[4]:     0048a003(j), 0048a044(j), 
    //                                                                                                         0048a273(j), 0048a2cc(j)  
    //                              rpnl_tbx.cpp:302 (5)
    //         0048a2ee     MOV        EAX,0x1
    //                              rpnl_tbx.cpp:306 (42)
    //         0048a2f3     MOV        this,dword ptr [ESP + local_c]
    //         0048a2f7     MOV        dword ptr FS:[0x0],this
    //         0048a2fe     POP        EDI
    //         0048a2ff     POP        ESI
    //         0048a300     POP        EBP
    //         0048a301     ADD        ESP,0xc
    //         0048a304     RET        0x10
    //                               LAB_0048a307                                                 XREF[2]:     00489f70(j), 0048a195(j)  
    //         0048a307     MOV        this,dword ptr [ESP + local_c]
    //         0048a30b     POP        EDI
    //         0048a30c     POP        ESI
    //         0048a30d     XOR        EAX,EAX
    //         0048a30f     MOV        dword ptr FS:[0x0],this
    //         0048a316     POP        EBP
    //         0048a317     ADD        ESP,0xc
    //         0048a31a     RET        0x10
    //         0048a31d     ??         90h
    //         0048a31e     NOP
    //         0048a31f     NOP
}

long RGE_Panel_Tool_Box::key_down_action(long param_1, short param_2, int param_3, int param_4, int param_5) {
    /* TODO: Stub */
    //                              long __thiscall key_down_action(RGE_Panel_Tool_Box * this, long para
    //              long              EAX:4          <RETURN>
    //              RGE_Panel_Tool    ECX:4 (auto)   this
    //              long              Stack[0x4]:4   param_1                   XREF[1]:     0048a35a(R)  
    //              short             Stack[0x8]:2   param_2
    //              int               Stack[0xc]:4   param_3
    //              int               Stack[0x10]:4  param_4
    //              int               Stack[0x14]:4  param_5
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[6]:     0048a402(*), 0048a420(R), 0048a44a(R), 0048a47f(*), 
    //                                                                                     0048a4a3(R), 0048a4cc(R)  
    //              long              Stack[-0x8]:4  x1                        XREF[6]:     0048a3f7(*), 0048a415(R), 0048a443(R), 0048a47a(*), 
    //                                                                                     0048a498(R), 0048a4c5(R)  
    //              long              Stack[-0xc]:4  y1                        XREF[6]:     0048a3f2(*), 0048a411(R), 0048a43f(R), 0048a475(*), 
    //                                                                                     0048a494(R), 0048a4c1(R)  
    //              long              Stack[-0x10]:4 x2                        XREF[6]:     0048a3ec(*), 0048a40d(R), 0048a43b(R), 0048a46f(*), 
    //                                                                                     0048a490(R), 0048a4bd(R)  
    //              long              Stack[-0x14]:4 y2
    //                               ?key_down_action@RGE_Panel_Tool_Box@@UAEJJFHHH@Z             XREF[1]:     0057200c(*)  
    //                               RGE_Panel_Tool_Box::key_down_action
    //                              rpnl_tbx.cpp:312 (8)
    //         0048a320     SUB        ESP,0x10
    //         0048a323     PUSH       EBX
    //         0048a324     PUSH       ESI
    //         0048a325     MOV        ESI,this
    //         0048a327     PUSH       EDI
    //                              rpnl_tbx.cpp:317 (50)
    //         0048a328     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0048a32e     CALL       RGE_Base_Game::get_paused                        int get_paused(RGE_Base_Game * this)
    //         0048a333     TEST       EAX,EAX
    //         0048a335     JNZ        LAB_0048a512
    //         0048a33b     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0048a341     MOV        EAX,dword ptr [this->_padding_ + 0x1b0]
    //         0048a347     CMP        EAX,0x4
    //         0048a34a     JZ         LAB_0048a35a
    //         0048a34c     CMP        EAX,0x6
    //         0048a34f     JZ         LAB_0048a35a
    //         0048a351     CMP        EAX,0x7
    //         0048a354     JNZ        LAB_0048a512
    //                               LAB_0048a35a                                                 XREF[2]:     0048a34a(j), 0048a34f(j)  
    //                              rpnl_tbx.cpp:320 (25)
    //         0048a35a     MOV        EAX,dword ptr [ESP + param_1]
    //         0048a35e     SUB        EAX,0x21
    //         0048a361     JZ         LAB_0048a462
    //         0048a367     DEC        EAX
    //         0048a368     JZ         LAB_0048a3df
    //         0048a36a     SUB        EAX,0xc
    //         0048a36d     JNZ        LAB_0048a512
    //                              rpnl_tbx.cpp:323 (13)
    //         0048a373     CMP        dword ptr [this->_padding_ + 0x1b4],0x12
    //         0048a37a     JNZ        LAB_0048a512
    //                              rpnl_tbx.cpp:325 (11)
    //         0048a380     CALL       RGE_Base_Game::get_player                        RGE_Player * get_player(RGE_Base_Game * this)
    //         0048a385     MOV        EDI,dword ptr [EAX + 0x130]
    //                              rpnl_tbx.cpp:326 (8)
    //         0048a38b     TEST       EDI,EDI
    //         0048a38d     JZ         LAB_0048a504
    //                              rpnl_tbx.cpp:328 (7)
    //         0048a393     MOV        this,dword ptr [EDI + 0x18]
    //         0048a396     TEST       this,this
    //         0048a398     JZ         LAB_0048a3a3
    //                              rpnl_tbx.cpp:329 (7)
    //         0048a39a     CALL       RGE_Active_Sprite_List::get_lowest_draw_level    uchar get_lowest_draw_level(RGE_Active_Sprite
    //         0048a39f     MOV        BL,AL
    //                              rpnl_tbx.cpp:330 (9)
    //         0048a3a1     JMP        LAB_0048a3b5
    //                               LAB_0048a3a3                                                 XREF[1]:     0048a398(j)  
    //         0048a3a3     MOV        this,dword ptr [EDI + 0x10]
    //         0048a3a6     TEST       this,this
    //         0048a3a8     JZ         LAB_0048a3b3
    //                              rpnl_tbx.cpp:331 (7)
    //         0048a3aa     CALL       RGE_Sprite::get_lowest_draw_level                uchar get_lowest_draw_level(RGE_Sprite * this)
    //         0048a3af     MOV        BL,AL
    //                              rpnl_tbx.cpp:332 (2)
    //         0048a3b1     JMP        LAB_0048a3b5
    //                               LAB_0048a3b3                                                 XREF[1]:     0048a3a8(j)  
    //                              rpnl_tbx.cpp:333 (2)
    //         0048a3b3     MOV        BL,0x14
    //                               LAB_0048a3b5                                                 XREF[2]:     0048a3a1(j), 0048a3b1(j)  
    //                              rpnl_tbx.cpp:335 (7)
    //         0048a3b5     MOV        EAX,dword ptr [EDI]
    //         0048a3b7     MOV        this,EDI
    //         0048a3b9     CALL       dword ptr [EAX + 0x68]
    //                              rpnl_tbx.cpp:337 (8)
    //         0048a3bc     TEST       BL,BL
    //         0048a3be     JNZ        LAB_0048a504
    //                              rpnl_tbx.cpp:338 (13)
    //         0048a3c4     MOV        this,dword ptr [ESI + 0xf8]
    //         0048a3ca     PUSH       0x2
    //         0048a3cc     MOV        EDX,dword ptr [this->_padding_]
    //         0048a3ce     CALL       dword ptr [EDX + 0x20]
    //                              rpnl_tbx.cpp:340 (5)
    //         0048a3d1     MOV        EAX,0x1
    //                              rpnl_tbx.cpp:372 (9)
    //         0048a3d6     POP        EDI
    //         0048a3d7     POP        ESI
    //         0048a3d8     POP        EBX
    //         0048a3d9     ADD        ESP,0x10
    //         0048a3dc     RET        0x14
    //                               LAB_0048a3df                                                 XREF[1]:     0048a368(j)  
    //                              rpnl_tbx.cpp:358 (13)
    //         0048a3df     CMP        dword ptr [this->_padding_ + 0x1b4],0x3
    //         0048a3e6     JNZ        LAB_0048a512
    //                              rpnl_tbx.cpp:360 (33)
    //         0048a3ec     LEA        EAX=>x2,[ESP + 0xc]
    //         0048a3f0     PUSH       0x1
    //         0048a3f2     LEA        this=>y1,[ESP + 0x14]
    //         0048a3f6     PUSH       EAX
    //         0048a3f7     LEA        EDX=>x1,[ESP + 0x1c]
    //         0048a3fb     PUSH       this
    //         0048a3fc     MOV        this,dword ptr [ESI + 0xf8]
    //         0048a402     LEA        EAX=>local_4,[ESP + 0x24]
    //         0048a406     PUSH       EDX
    //         0048a407     PUSH       EAX
    //         0048a408     CALL       RGE_View::get_selection_area                     int get_selection_area(RGE_View * this, long 
    //                              rpnl_tbx.cpp:361 (46)
    //         0048a40d     MOV        this,dword ptr [ESP + x2]
    //         0048a411     MOV        EDX,dword ptr [ESP + y1]
    //         0048a415     MOV        EAX,dword ptr [ESP + x1]
    //         0048a419     PUSH       0x1
    //         0048a41b     PUSH       -0x1
    //         0048a41d     PUSH       0x0
    //         0048a41f     PUSH       this
    //         0048a420     MOV        this,dword ptr [ESP + local_4]
    //         0048a424     PUSH       EDX
    //         0048a425     MOV        EDX,dword ptr [rge_base_game]                    = 00000000
    //         0048a42b     PUSH       EAX
    //         0048a42c     PUSH       this
    //         0048a42d     MOV        EAX,dword ptr [EDX + 0x3f4]
    //         0048a433     MOV        this,dword ptr [EAX + 0x28]
    //         0048a436     CALL       RGE_Map::set_elev                                void set_elev(RGE_Map * this, short param_1, 
    //                              rpnl_tbx.cpp:362 (37)
    //         0048a43b     MOV        this,dword ptr [ESP + x2]
    //         0048a43f     MOV        EDX,dword ptr [ESP + y1]
    //         0048a443     MOV        EAX,dword ptr [ESP + x1]
    //         0048a447     PUSH       0x8
    //         0048a449     PUSH       this
    //         0048a44a     MOV        this,dword ptr [ESP + local_4]
    //         0048a44e     PUSH       EDX
    //         0048a44f     MOV        EDX,dword ptr [rge_base_game]                    = 00000000
    //         0048a455     PUSH       EAX
    //         0048a456     PUSH       this
    //         0048a457     MOV        EAX,dword ptr [EDX + 0x3f4]
    //         0048a45d     MOV        this,dword ptr [EAX + 0x28]
    //                              rpnl_tbx.cpp:366 (2)
    //         0048a460     JMP        LAB_0048a4e1
    //                               LAB_0048a462                                                 XREF[1]:     0048a361(j)  
    //                              rpnl_tbx.cpp:345 (13)
    //         0048a462     CMP        dword ptr [this->_padding_ + 0x1b4],0x3
    //         0048a469     JNZ        LAB_0048a512
    //                              rpnl_tbx.cpp:347 (33)
    //         0048a46f     LEA        this=>x2,[ESP + 0xc]
    //         0048a473     PUSH       0x1
    //         0048a475     LEA        EDX=>y1,[ESP + 0x14]
    //         0048a479     PUSH       this
    //         0048a47a     LEA        EAX=>x1,[ESP + 0x1c]
    //         0048a47e     PUSH       EDX
    //         0048a47f     LEA        this=>local_4,[ESP + 0x24]
    //         0048a483     PUSH       EAX
    //         0048a484     PUSH       this
    //         0048a485     MOV        this,dword ptr [ESI + 0xf8]
    //         0048a48b     CALL       RGE_View::get_selection_area                     int get_selection_area(RGE_View * this, long 
    //                              rpnl_tbx.cpp:348 (45)
    //         0048a490     MOV        EDX,dword ptr [ESP + x2]
    //         0048a494     MOV        EAX,dword ptr [ESP + y1]
    //         0048a498     MOV        this,dword ptr [ESP + x1]
    //         0048a49c     PUSH       0x1
    //         0048a49e     PUSH       0x1
    //         0048a4a0     PUSH       0x0
    //         0048a4a2     PUSH       EDX
    //         0048a4a3     MOV        EDX,dword ptr [ESP + local_4]
    //         0048a4a7     PUSH       EAX
    //         0048a4a8     MOV        EAX,[rge_base_game]                              = 00000000
    //         0048a4ad     PUSH       this
    //         0048a4ae     PUSH       EDX
    //         0048a4af     MOV        this,dword ptr [EAX + 0x3f4]
    //         0048a4b5     MOV        this,dword ptr [ECX + this->_padding_]
    //         0048a4b8     CALL       RGE_Map::set_elev                                void set_elev(RGE_Map * this, short param_1, 
    //                              rpnl_tbx.cpp:349 (41)
    //         0048a4bd     MOV        EDX,dword ptr [ESP + x2]
    //         0048a4c1     MOV        EAX,dword ptr [ESP + y1]
    //         0048a4c5     MOV        this,dword ptr [ESP + x1]
    //         0048a4c9     PUSH       0x8
    //         0048a4cb     PUSH       EDX
    //         0048a4cc     MOV        EDX,dword ptr [ESP + local_4]
    //         0048a4d0     PUSH       EAX
    //         0048a4d1     MOV        EAX,[rge_base_game]                              = 00000000
    //         0048a4d6     PUSH       this
    //         0048a4d7     PUSH       EDX
    //         0048a4d8     MOV        this,dword ptr [EAX + 0x3f4]
    //         0048a4de     MOV        this,dword ptr [ECX + this->_padding_]
    //                               LAB_0048a4e1                                                 XREF[1]:     0048a460(j)  
    //         0048a4e1     CALL       RGE_Map::clean_elevation                         void clean_elevation(RGE_Map * this, long par
    //                              rpnl_tbx.cpp:350 (13)
    //         0048a4e6     MOV        this,dword ptr [ESI + 0xf8]
    //         0048a4ec     PUSH       0x2
    //         0048a4ee     MOV        EDX,dword ptr [this->_padding_]
    //         0048a4f0     CALL       dword ptr [EDX + 0x20]
    //                              rpnl_tbx.cpp:351 (10)
    //         0048a4f3     MOV        this,dword ptr [ESI + 0xfc]
    //         0048a4f9     TEST       this,this
    //         0048a4fb     JZ         LAB_0048a504
    //                              rpnl_tbx.cpp:352 (7)
    //         0048a4fd     MOV        EAX,dword ptr [this->_padding_]
    //         0048a4ff     PUSH       0x2
    //         0048a501     CALL       dword ptr [EAX + 0x20]
    //                               LAB_0048a504                                                 XREF[3]:     0048a38d(j), 0048a3be(j), 
    //                                                                                                         0048a4fb(j)  
    //                              rpnl_tbx.cpp:353 (5)
    //         0048a504     MOV        EAX,0x1
    //                              rpnl_tbx.cpp:372 (20)
    //         0048a509     POP        EDI
    //         0048a50a     POP        ESI
    //         0048a50b     POP        EBX
    //         0048a50c     ADD        ESP,0x10
    //         0048a50f     RET        0x14
    //                               LAB_0048a512                                                 XREF[6]:     0048a335(j), 0048a354(j), 
    //                                                                                                         0048a36d(j), 0048a37a(j), 
    //                                                                                                         0048a3e6(j), 0048a469(j)  
    //         0048a512     POP        EDI
    //         0048a513     POP        ESI
    //         0048a514     XOR        EAX,EAX
    //         0048a516     POP        EBX
    //         0048a517     ADD        ESP,0x10
    //         0048a51a     RET        0x14
    //         0048a51d     ??         90h
    //         0048a51e     NOP
    //         0048a51f     NOP
    return 0;
}

void RGE_Panel_Tool_Box::game_mode_changed(int param_1, int param_2) {
    /* TODO: Stub */
    //                              void __thiscall game_mode_changed(RGE_Panel_Tool_Box * this, int par
    //              void              <VOID>         <RETURN>
    //              RGE_Panel_Tool    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0048a520(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     0048a563(R)  
    //                               ?game_mode_changed@RGE_Panel_Tool_Box@@QAEXHH@Z              XREF[3]:     RGE_Panel_Tool_Box:00489e4b(c), 
    //                               RGE_Panel_Tool_Box::game_mode_changed                                     action:0048a2e9(c), 
    //                                                                                                         game_mode_changed:00498a27(c)  
    //                              rpnl_tbx.cpp:380 (28)
    //         0048a520     MOV        EAX,dword ptr [ESP + param_1]
    //         0048a524     PUSH       ESI
    //         0048a525     DEC        EAX
    //         0048a526     MOV        ESI,this
    //         0048a528     CMP        EAX,0x11
    //         0048a52b     JA         switchD_0048a535::caseD_4
    //         0048a52d     XOR        this,this
    //         0048a52f     MOV        this,byte ptr [EAX + 0x48a5f4]=>PTR_caseD_4_00
    //                               switchD_0048a535::switchD
    //         0048a535     JMP        dword ptr [this->_padding_*0x4 + switchD_0048a   = 0048a53c
    //                               switchD_0048a535::caseD_12                                   XREF[3]:     0048a535(j), 0048a5e4(*), 
    //                               switchD_0048a535::caseD_1                                                 0048a5ec(*)  
    //                              rpnl_tbx.cpp:385 (18)
    //         0048a53c     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0048a542     CALL       RGE_Base_Game::get_player                        RGE_Player * get_player(RGE_Base_Game * this)
    //         0048a547     MOV        this,EAX
    //         0048a549     CALL       RGE_Player::unselect_object                      void unselect_object(RGE_Player * this)
    //                              rpnl_tbx.cpp:386 (2)
    //         0048a54e     JMP        switchD_0048a535::caseD_4
    //                               switchD_0048a535::caseD_3                                    XREF[2]:     0048a535(j), 0048a5e8(*)  
    //                               switchD_0048a535::caseD_2
    //                              rpnl_tbx.cpp:390 (19)
    //         0048a550     MOV        this,dword ptr [ESI + 0xf8]
    //         0048a556     PUSH       -0x1
    //         0048a558     PUSH       -0x1
    //         0048a55a     PUSH       -0x1
    //         0048a55c     PUSH       -0x1
    //         0048a55e     CALL       RGE_View::set_selection_area                     void set_selection_area(RGE_View * this, long
    //                               switchD_0048a535::caseD_5                                    XREF[4]:     0048a52b(j), 0048a535(j), 
    //                               switchD_0048a535::caseD_6                                                 0048a54e(j), 0048a5f0(*)  
    //                               switchD_0048a535::caseD_7
    //                               switchD_0048a535::caseD_8
    //                               switchD_0048a535::caseD_9
    //                               switchD_0048a535::caseD_a
    //                               switchD_0048a535::caseD_b
    //                               switchD_0048a535::caseD_c
    //                               switchD_0048a535::caseD_d
    //                               switchD_0048a535::caseD_e
    //                               switchD_0048a535::caseD_f
    //                               switchD_0048a535::caseD_10
    //                               switchD_0048a535::caseD_11
    //                               switchD_0048a535::caseD_4
    //                              rpnl_tbx.cpp:394 (27)
    //         0048a563     MOV        EDX,dword ptr [ESP + param_2]
    //         0048a567     LEA        EAX,[EDX + -0x1]
    //         0048a56a     CMP        EAX,0x11
    //         0048a56d     JA         switchD_0048a577::caseD_4
    //         0048a56f     XOR        this,this
    //         0048a571     MOV        this,byte ptr [EAX + 0x48a620]=>PTR_caseD_4_00
    //                               switchD_0048a577::switchD
    //         0048a577     JMP        dword ptr [this->_padding_*0x4 + switchD_0048a   = 0048a57e
    //                               switchD_0048a577::caseD_1                                    XREF[2]:     0048a577(j), 0048a608(*)  
    //                              rpnl_tbx.cpp:397 (6)
    //         0048a57e     MOV        this,dword ptr [ESI + 0x104]
    //                              rpnl_tbx.cpp:419 (5)
    //         0048a584     CALL       TButtonPanel::set_radio_button                   void set_radio_button(TButtonPanel * this)
    //                              rpnl_tbx.cpp:422 (4)
    //         0048a589     POP        ESI
    //         0048a58a     RET        0x8
    //                               switchD_0048a577::caseD_12                                   XREF[2]:     0048a577(j), 0048a618(*)  
    //                              rpnl_tbx.cpp:401 (6)
    //         0048a58d     MOV        this,dword ptr [ESI + 0x10c]
    //                              rpnl_tbx.cpp:419 (5)
    //         0048a593     CALL       TButtonPanel::set_radio_button                   void set_radio_button(TButtonPanel * this)
    //                              rpnl_tbx.cpp:422 (4)
    //         0048a598     POP        ESI
    //         0048a599     RET        0x8
    //                               switchD_0048a577::caseD_e                                    XREF[2]:     0048a577(j), 0048a614(*)  
    //                              rpnl_tbx.cpp:405 (6)
    //         0048a59c     MOV        this,dword ptr [ESI + 0x108]
    //                              rpnl_tbx.cpp:419 (5)
    //         0048a5a2     CALL       TButtonPanel::set_radio_button                   void set_radio_button(TButtonPanel * this)
    //                              rpnl_tbx.cpp:422 (4)
    //         0048a5a7     POP        ESI
    //         0048a5a8     RET        0x8
    //                               switchD_0048a577::caseD_2                                    XREF[2]:     0048a577(j), 0048a60c(*)  
    //                              rpnl_tbx.cpp:409 (6)
    //         0048a5ab     MOV        this,dword ptr [ESI + 0x110]
    //                              rpnl_tbx.cpp:411 (2)
    //         0048a5b1     JMP        LAB_0048a5b9
    //                               switchD_0048a577::caseD_3                                    XREF[2]:     0048a577(j), 0048a610(*)  
    //                              rpnl_tbx.cpp:414 (11)
    //         0048a5b3     MOV        this,dword ptr [ESI + 0x114]
    //                               LAB_0048a5b9                                                 XREF[1]:     0048a5b1(j)  
    //         0048a5b9     CALL       TButtonPanel::set_radio_button                   void set_radio_button(TButtonPanel * this)
    //                              rpnl_tbx.cpp:415 (18)
    //         0048a5be     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0048a5c4     CALL       RGE_Base_Game::get_player                        RGE_Player * get_player(RGE_Base_Game * this)
    //         0048a5c9     MOV        this,EAX
    //         0048a5cb     CALL       RGE_Player::unselect_object                      void unselect_object(RGE_Player * this)
    //                              rpnl_tbx.cpp:422 (4)
    //         0048a5d0     POP        ESI
    //         0048a5d1     RET        0x8
    //                               switchD_0048a577::caseD_5                                    XREF[3]:     0048a56d(j), 0048a577(j), 
    //                               switchD_0048a577::caseD_6                                                 0048a61c(*)  
    //                               switchD_0048a577::caseD_7
    //                               switchD_0048a577::caseD_8
    //                               switchD_0048a577::caseD_9
    //                               switchD_0048a577::caseD_a
    //                               switchD_0048a577::caseD_b
    //                               switchD_0048a577::caseD_c
    //                               switchD_0048a577::caseD_d
    //                               switchD_0048a577::caseD_f
    //                               switchD_0048a577::caseD_10
    //                               switchD_0048a577::caseD_11
    //                               switchD_0048a577::caseD_4
    //                              rpnl_tbx.cpp:419 (11)
    //         0048a5d4     MOV        this,dword ptr [ESI + 0x100]
    //         0048a5da     CALL       TButtonPanel::set_radio_button                   void set_radio_button(TButtonPanel * this)
    //                              rpnl_tbx.cpp:422 (83)
    //         0048a5df     POP        ESI
    //         0048a5e0     RET        0x8
    //         0048a5e3     ??         90h
    //                              Symbol Ref: No symbol: NONAME
    //                               switchD_0048a535::switchdataD_0048a5e4                       XREF[1]:     game_mode_changed:0048a535(*)  
    //         0048a5e4     addr       switchD_0048a535::caseD_1
    //         0048a5e8     addr       switchD_0048a535::caseD_2
    //         0048a5ec     addr       switchD_0048a535::caseD_1
    //                               PTR_caseD_4_0048a5f0+3                                       XREF[0,1]:   game_mode_changed:0048a52f(*)  
    //         0048a5f0     addr       switchD_0048a535::caseD_4
    //                              Symbol Ref: No symbol: NONAME
    //                               switchD_0048a535::switchdataD_0048a5f4
    //         0048a5f4     db         0h
    //         0048a5f5     db         1h
    //         0048a5f6     db         1h
    //         0048a5f7     db         3h
    //         0048a5f8     db         3h
    //         0048a5f9     db         3h
    //         0048a5fa     db         3h
    //         0048a5fb     db         3h
    //         0048a5fc     db         3h
    //         0048a5fd     db         3h
    //         0048a5fe     db         3h
    //         0048a5ff     db         3h
    //         0048a600     db         3h
    //         0048a601     db         3h
    //         0048a602     db         3h
    //         0048a603     db         3h
    //         0048a604     db         3h
    //         0048a605     db         2h
    //         0048a606     ??         8Bh
    //         0048a607     ??         FFh
    //                              Symbol Ref: No symbol: NONAME
    //                               switchD_0048a577::switchdataD_0048a608                       XREF[1]:     game_mode_changed:0048a577(*)  
    //         0048a608     addr       switchD_0048a577::caseD_1
    //         0048a60c     addr       switchD_0048a577::caseD_2
    //         0048a610     addr       switchD_0048a577::caseD_3
    //         0048a614     addr       switchD_0048a577::caseD_e
    //         0048a618     addr       switchD_0048a577::caseD_12
    //                               PTR_caseD_4_0048a61c+3                                       XREF[0,1]:   game_mode_changed:0048a571(*)  
    //         0048a61c     addr       switchD_0048a577::caseD_4
    //                              Symbol Ref: No symbol: NONAME
    //                               switchD_0048a577::switchdataD_0048a620
    //         0048a620     db         0h
    //         0048a621     db         1h
    //         0048a622     db         2h
    //         0048a623     db         5h
    //         0048a624     db         5h
    //         0048a625     db         5h
    //         0048a626     db         5h
    //         0048a627     db         5h
    //         0048a628     db         5h
    //         0048a629     db         5h
    //         0048a62a     db         5h
    //         0048a62b     db         5h
    //         0048a62c     db         5h
    //         0048a62d     db         3h
    //         0048a62e     db         5h
    //         0048a62f     db         5h
    //         0048a630     db         5h
    //         0048a631     db         4h
    //         0048a632     ??         90h
    //         0048a633     ??         90h
    //         0048a634     ??         90h
    //         0048a635     ??         90h
    //         0048a636     ??         90h
    //         0048a637     ??         90h
    //         0048a638     ??         90h
    //         0048a639     ??         90h
    //         0048a63a     ??         90h
    //         0048a63b     ??         90h
    //         0048a63c     ??         90h
    //         0048a63d     ??         90h
    //         0048a63e     ??         90h
    //         0048a63f     ??         90h
    return;
}

void RGE_Panel_Tool_Box::draw() {
    /* TODO: Stub */
    //                              void __thiscall draw(RGE_Panel_Tool_Box * this)
    //              void              <VOID>         <RETURN>
    //              RGE_Panel_Tool    ECX:4 (auto)   this
    //                               ?draw@RGE_Panel_Tool_Box@@UAEXXZ                             XREF[1]:     00571f90(*)  
    //                               RGE_Panel_Tool_Box::draw
    //                              rpnl_tbx.cpp:428 (3)
    //         0048a640     PUSH       ESI
    //         0048a641     MOV        ESI,this
    //                              rpnl_tbx.cpp:429 (22)
    //         0048a643     MOV        EAX,dword ptr [ESI + 0x20]
    //         0048a646     TEST       EAX,EAX
    //         0048a648     JZ         LAB_0048a674
    //         0048a64a     MOV        EAX,dword ptr [ESI + 0x70]
    //         0048a64d     TEST       EAX,EAX
    //         0048a64f     JZ         LAB_0048a674
    //         0048a651     MOV        EAX,dword ptr [ESI + 0x6c]
    //         0048a654     TEST       EAX,EAX
    //         0048a656     JZ         LAB_0048a674
    //         0048a658     PUSH       EDI
    //                              rpnl_tbx.cpp:432 (7)
    //         0048a659     MOV        EDI,dword ptr [ESI]
    //         0048a65b     PUSH       0x0
    //         0048a65d     CALL       dword ptr [EDI + 0x28]
    //                              rpnl_tbx.cpp:434 (14)
    //         0048a660     MOV        this,dword ptr [ESI + 0x20]
    //         0048a663     LEA        EAX,[ESI + 0x24]
    //         0048a666     PUSH       0x0
    //         0048a668     PUSH       EAX
    //         0048a669     CALL       TDrawArea::Clear                                 void Clear(TDrawArea * this, tagRECT * param_
    //                              rpnl_tbx.cpp:436 (6)
    //         0048a66e     MOV        this,ESI
    //         0048a670     CALL       dword ptr [EDI + 0x2c]
    //         0048a673     POP        EDI
    //                               LAB_0048a674                                                 XREF[3]:     0048a648(j), 0048a64f(j), 
    //                                                                                                         0048a656(j)  
    //                              rpnl_tbx.cpp:437 (2)
    //         0048a674     POP        ESI
    //         0048a675     RET
    //         0048a676     ??         90h
    //         0048a677     NOP
    //         0048a678     NOP
    //         0048a679     NOP
    //         0048a67a     NOP
    //         0048a67b     NOP
    //         0048a67c     NOP
    //         0048a67d     NOP
    //         0048a67e     NOP
    //         0048a67f     NOP
    return;
}

RGE_Panel_Tool_Box::RGE_Panel_Tool_Box(TDrawArea* param_1, TPanel* param_2, long param_3, long param_4, long param_5, long param_6, void* param_7, long param_8, long param_9, TDigital* param_10, TScreenPanel* param_11, RGE_View* param_12, RGE_Diamond_Map* param_13) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
}

long RGE_Panel_Tool_Box::action(TPanel* param_1, long param_2, ulong param_3, ulong param_4) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return 0;
}

