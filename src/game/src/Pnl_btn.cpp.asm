// Auto-generated scaffold unit: Pnl_btn.cpp.asm
// SourceMap: C:/msdev/work/age1_x1/Pnl_btn.cpp
#include "../include/common.h"

// Offset: 0x00471EC0
undefined TButtonPanel(TButtonPanel* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall TButtonPanel::TButtonPanel(void)                                                   *
    //                              *********************************************************************************************************
    //                              undefined __thiscall TButtonPanel(TButtonPanel * this)
    //              undefined         <UNASSIGNED>   <RETURN>
    //              TButtonPanel *    ECX:4 (auto)   this
    //                               ??0TButtonPanel@@QAE@XZ                                      XREF[16]:    create_button:004685bb(c), 
    //                               TButtonPanel::TButtonPanel                                                create_check_box:004687ed(c), 
    //                                                                                                         create_radio_button:00468a4d(c), 
    //                                                                                                         TDropDownButtonPanel:00475473(c), 
    //                                                                                                         RGE_Panel_Tool_Box:004899b5(c), 
    //                                                                                                         RGE_Panel_Tool_Box:00489a44(c), 
    //                                                                                                         RGE_Panel_Tool_Box:00489acf(c), 
    //                                                                                                         RGE_Panel_Tool_Box:00489b5a(c), 
    //                                                                                                         RGE_Panel_Tool_Box:00489be8(c), 
    //                                                                                                         RGE_Panel_Tool_Box:00489c83(c), 
    //                                                                                                         RGE_Panel_Tool_Box:00489dc0(c), 
    //                                                                                                         TribeEndScreen:00493ab7(c), 
    //                                                                                                         TribeSelectTribeScreen:004b78ae(c)
    //                                                                                                         TribeSelectTribeScreen:004b7b4a(c)
    //                                                                                                         TribeSelectTribeScreen:004b7c5f(c)
    //                                                                                                         TRIBE_Panel_Button:00519dbd(c)  
    //                              Pnl_btn.cpp:59 (222)
    //         00471ec0     PUSH       EBX
    //         00471ec1     PUSH       EBP
    //         00471ec2     PUSH       ESI
    //         00471ec3     PUSH       EDI
    //         00471ec4     MOV        ESI,this
    //         00471ec6     CALL       TPanel::TPanel                                   undefined TPanel(TPanel * this)
    //         00471ecb     MOV        EAX,0x1
    //         00471ed0     XOR        this,this
    //         00471ed2     MOV        dword ptr [ESI + 0x13c],EAX
    //         00471ed8     OR         EDX,0xffffffff
    //         00471edb     MOV        dword ptr [ESI + 0x140],EAX
    //         00471ee1     MOV        dword ptr [ESI + 0x144],EAX
    //         00471ee7     MOV        dword ptr [ESI + 0x184],EAX
    //         00471eed     MOV        dword ptr [ESI + 0x190],EAX
    //         00471ef3     MOV        dword ptr [ESI + 0x1e0],EDX
    //         00471ef9     MOV        dword ptr [ESI + 0x1e4],EDX
    //         00471eff     MOV        word ptr [ESI + 0x1f4],AX
    //         00471f06     MOV        dword ptr [ESI + 0x2a0],EAX
    //         00471f0c     MOV        dword ptr [ESI + 0x2b4],EDX
    //         00471f12     MOV        dword ptr [ESI + 0x148],this
    //         00471f18     MOV        dword ptr [ESI + 0x188],this
    //         00471f1e     MOV        dword ptr [ESI + 0x18c],this
    //         00471f24     MOV        dword ptr [ESI + 0x194],this
    //         00471f2a     MOV        dword ptr [ESI + 0x1e8],this
    //         00471f30     MOV        dword ptr [ESI + 0x1ec],this
    //         00471f36     MOV        dword ptr [ESI + 0x1f0],this
    //         00471f3c     MOV        word ptr [ESI + 0x1f6],this
    //         00471f43     MOV        dword ptr [ESI + 0x1f8],this
    //         00471f49     MOV        dword ptr [ESI + 0x1fc],this
    //         00471f4f     MOV        word ptr [ESI + 0x200],this
    //         00471f56     MOV        dword ptr [ESI + 0x204],this
    //         00471f5c     MOV        dword ptr [ESI + 0x298],this
    //         00471f62     MOV        dword ptr [ESI + 0x29c],this
    //         00471f68     MOV        byte ptr [ESI + 0x2a4],this
    //         00471f6e     MOV        byte ptr [ESI + 0x2a5],this
    //         00471f74     MOV        byte ptr [ESI + 0x2a6],this
    //         00471f7a     MOV        byte ptr [ESI + 0x2a7],this
    //         00471f80     MOV        byte ptr [ESI + 0x2a8],this
    //         00471f86     MOV        byte ptr [ESI + 0x2a9],this
    //         00471f8c     MOV        dword ptr [ESI + 0x2ac],this
    //         00471f92     MOV        dword ptr [ESI + 0x2b0],this
    //         00471f98     MOV        dword ptr [ESI],TButtonPanel::`vftable'          = 00472010
    //                              Pnl_btn.cpp:61 (34)
    //         00471f9e     MOV        byte ptr [ESI + 0xee],0x3
    //         00471fa5     LEA        EDX,[ESI + 0x170]
    //         00471fab     LEA        EAX,[ESI + 0x118]
    //         00471fb1     MOV        EDI,0x9
    //         00471fb6     MOV        EBP,0xffffff
    //         00471fbb     MOV        EBX,0xffff
    //                               LAB_00471fc0                                                 XREF[1]:     00471ff8(j)  
    //                              Pnl_btn.cpp:64 (3)
    //         00471fc0     MOV        dword ptr [EAX + -0x24],this
    //                              Pnl_btn.cpp:65 (2)
    //         00471fc3     MOV        dword ptr [EAX],this
    //                              Pnl_btn.cpp:66 (3)
    //         00471fc5     MOV        dword ptr [EAX + 0x34],this
    //                              Pnl_btn.cpp:67 (5)
    //         00471fc8     MOV        word ptr [EDX],0xffff
    //                              Pnl_btn.cpp:68 (6)
    //         00471fcd     MOV        dword ptr [EAX + 0x80],this
    //                              Pnl_btn.cpp:69 (6)
    //         00471fd3     MOV        dword ptr [EAX + 0xa4],this
    //                              Pnl_btn.cpp:70 (6)
    //         00471fd9     MOV        dword ptr [EAX + 0xf0],EBP
    //                              Pnl_btn.cpp:71 (6)
    //         00471fdf     MOV        dword ptr [EAX + 0x114],this
    //                              Pnl_btn.cpp:72 (6)
    //         00471fe5     MOV        dword ptr [EAX + 0x138],EBX
    //                              Pnl_btn.cpp:73 (15)
    //         00471feb     MOV        dword ptr [EAX + 0x15c],this
    //         00471ff1     ADD        EDX,0x2
    //         00471ff4     ADD        EAX,0x4
    //         00471ff7     DEC        EDI
    //         00471ff8     JNZ        LAB_00471fc0
    //                              Pnl_btn.cpp:75 (7)
    //         00471ffa     MOV        EAX,ESI
    //         00471ffc     POP        EDI
    //         00471ffd     POP        ESI
    //         00471ffe     POP        EBP
    //         00471fff     POP        EBX
    //         00472000     RET
}

// Offset: 0x00472030
void TButtonPanel(TButtonPanel* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual __thiscall TButtonPanel::~TButtonPanel(void)                                          *
    //                              *********************************************************************************************************
    //                              void __thiscall ~TButtonPanel(TButtonPanel * this)
    //              void              <VOID>         <RETURN>
    //              TButtonPanel *    ECX:4 (auto)   this
    //                               ??1TButtonPanel@@UAE@XZ                                      XREF[3]:     `scalar_deleting_destructor':00472
    //                               TButtonPanel::~TButtonPanel                                               ~TButtonPanel:004754ae(T), 
    //                                                                                                         ~TDropDownButtonPanel:004754b0(j), 
    //                                                                                                         ~TButtonPanel:00519e8e(T), 
    //                                                                                                         ~TRIBE_Panel_Button:00519e90(j)  
    //                              Pnl_btn.cpp:81 (26)
    //         00472030     PUSH       EBX
    //         00472031     PUSH       EBP
    //         00472032     MOV        EBP,this
    //         00472034     PUSH       ESI
    //         00472035     PUSH       EDI
    //         00472036     MOV        EBX,0x9
    //         0047203b     MOV        dword ptr [EBP],TButtonPanel::`vftable'          = 00472010
    //         00472042     LEA        ESI,[EBP + 0x1bc]
    //         00472048     XOR        EDI,EDI
    //                               LAB_0047204a                                                 XREF[1]:     00472072(j)  
    //                              Pnl_btn.cpp:86 (7)
    //         0047204a     MOV        EAX,dword ptr [ESI + -0x24]
    //         0047204d     CMP        EAX,EDI
    //         0047204f     JZ         LAB_0047205d
    //                              Pnl_btn.cpp:88 (9)
    //         00472051     PUSH       EAX
    //         00472052     CALL       free                                             undefined free()
    //         00472057     ADD        ESP,0x4
    //                              Pnl_btn.cpp:89 (3)
    //         0047205a     MOV        dword ptr [ESI + -0x24],EDI
    //                               LAB_0047205d                                                 XREF[1]:     0047204f(j)  
    //                              Pnl_btn.cpp:92 (6)
    //         0047205d     MOV        EAX,dword ptr [ESI]
    //         0047205f     CMP        EAX,EDI
    //         00472061     JZ         LAB_0047206e
    //                              Pnl_btn.cpp:94 (9)
    //         00472063     PUSH       EAX
    //         00472064     CALL       free                                             undefined free()
    //         00472069     ADD        ESP,0x4
    //                              Pnl_btn.cpp:95 (8)
    //         0047206c     MOV        dword ptr [ESI],EDI
    //                               LAB_0047206e                                                 XREF[1]:     00472061(j)  
    //         0047206e     ADD        ESI,0x4
    //         00472071     DEC        EBX
    //         00472072     JNZ        LAB_0047204a
    //                              Pnl_btn.cpp:99 (10)
    //         00472074     MOV        EAX,dword ptr [EBP + 0x1fc]
    //         0047207a     CMP        EAX,EDI
    //         0047207c     JZ         LAB_0047208d
    //                              Pnl_btn.cpp:101 (9)
    //         0047207e     PUSH       EAX
    //         0047207f     CALL       free                                             undefined free()
    //         00472084     ADD        ESP,0x4
    //                              Pnl_btn.cpp:102 (13)
    //         00472087     MOV        dword ptr [EBP + 0x1fc],EDI
    //                               LAB_0047208d                                                 XREF[1]:     0047207c(j)  
    //         0047208d     MOV        this,EBP
    //         0047208f     CALL       TPanel::~TPanel                                  void ~TPanel(TPanel * this)
    //                              Pnl_btn.cpp:104 (5)
    //         00472094     POP        EDI
    //         00472095     POP        ESI
    //         00472096     POP        EBP
    //         00472097     POP        EBX
    //         00472098     RET
}

// Offset: 0x004720A0
long setup(TButtonPanel* this_, TDrawArea* param_2, TPanel* param_3, long param_4, long param_5, long param_6, long param_7, DrawType param_8, TDigital* param_9, NotifyType param_10, long param_11) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: long __thiscall TButtonPanel::setup(class TDrawArea *,class TPanel *,long,long,long,long,e... *
    //                              *********************************************************************************************************
    //                              long __thiscall setup(TButtonPanel * this, TDrawArea * param_1, TPan
    //              long              EAX:4          <RETURN>
    //              TButtonPanel *    ECX:4 (auto)   this
    //              TDrawArea *       Stack[0x4]:4   param_1                   XREF[1]:     004720bc(R)  
    //              TPanel *          Stack[0x8]:4   param_2                   XREF[1]:     004720b7(R)  
    //              long              Stack[0xc]:4   param_3                   XREF[1]:     004720b2(R)  
    //              long              Stack[0x10]:4  param_4                   XREF[1]:     004720a4(R)  
    //              long              Stack[0x14]:4  param_5                   XREF[1]:     004720ab(R)  
    //              long              Stack[0x18]:4  param_6                   XREF[1]:     004720a0(R)  
    //              DrawType          Stack[0x1c]:4  param_7                   XREF[1]:     004720d2(R)  
    //              TDigital *        Stack[0x20]:4  param_8                   XREF[1]:     004720ce(R)  
    //              NotifyType        Stack[0x24]:4  param_9                   XREF[1]:     004720ca(R)  
    //              long              Stack[0x28]:4  param_10                  XREF[1]:     004720ea(R)  
    //                               ?setup@TButtonPanel@@QAEJPAVTDrawArea@@PAVTPanel@@JJJJW4Dra  XREF[16]:    create_button:00468623(c), 
    //                               TButtonPanel::setup                                                       create_check_box:00468859(c), 
    //                                                                                                         create_radio_button:00468ab9(c), 
    //                                                                                                         setup:00474195(c), 
    //                                                                                                         RGE_Panel_Tool_Box:004899ee(c), 
    //                                                                                                         RGE_Panel_Tool_Box:00489a81(c), 
    //                                                                                                         RGE_Panel_Tool_Box:00489b0c(c), 
    //                                                                                                         RGE_Panel_Tool_Box:00489b9a(c), 
    //                                                                                                         RGE_Panel_Tool_Box:00489c28(c), 
    //                                                                                                         RGE_Panel_Tool_Box:00489cc3(c), 
    //                                                                                                         RGE_Panel_Tool_Box:00489dfd(c), 
    //                                                                                                         TribeEndScreen:00493b7f(c), 
    //                                                                                                         TribeSelectTribeScreen:004b799e(c)
    //                                                                                                         TribeSelectTribeScreen:004b7c1f(c)
    //                                                                                                         TribeSelectTribeScreen:004b7d3a(c)
    //                                                                                                         TRIBE_Panel_Button:00519e1d(c)  
    //                              Pnl_btn.cpp:112 (42)
    //         004720a0     MOV        EAX,dword ptr [ESP + param_6]
    //         004720a4     MOV        EDX,dword ptr [ESP + param_4]
    //         004720a8     PUSH       ESI
    //         004720a9     MOV        ESI,this
    //         004720ab     MOV        this,dword ptr [ESP + param_5]
    //         004720af     PUSH       0x0
    //         004720b1     PUSH       EAX
    //         004720b2     MOV        EAX,dword ptr [ESP + param_3]
    //         004720b6     PUSH       this
    //         004720b7     MOV        this,dword ptr [ESP + param_2]
    //         004720bb     PUSH       EDX
    //         004720bc     MOV        EDX,dword ptr [ESP + param_1]
    //         004720c0     PUSH       EAX
    //         004720c1     PUSH       this
    //         004720c2     PUSH       EDX
    //         004720c3     MOV        this,ESI
    //         004720c5     CALL       TPanel::setup                                    long setup(TPanel * this, TDrawArea * param_1
    //                              Pnl_btn.cpp:116 (4)
    //         004720ca     MOV        this,dword ptr [ESP + param_9]
    //                              Pnl_btn.cpp:118 (28)
    //         004720ce     MOV        EDX,dword ptr [ESP + param_8]
    //         004720d2     MOV        EAX,dword ptr [ESP + param_7]
    //         004720d6     MOV        dword ptr [ESI + 0x144],this
    //         004720dc     PUSH       EDX
    //         004720dd     MOV        this,ESI
    //         004720df     MOV        dword ptr [ESI + 0x140],EAX
    //         004720e5     CALL       TButtonPanel::set_sound                          void set_sound(TButtonPanel * this, TDigital 
    //                              Pnl_btn.cpp:119 (16)
    //         004720ea     MOV        EAX,dword ptr [ESP + param_10]
    //         004720ee     PUSH       0x0
    //         004720f0     PUSH       EAX
    //         004720f1     PUSH       0x0
    //         004720f3     MOV        this,ESI
    //         004720f5     CALL       TButtonPanel::set_id                             void set_id(TButtonPanel * this, short param_
    //                              Pnl_btn.cpp:121 (5)
    //         004720fa     MOV        EAX,0x1
    //                              Pnl_btn.cpp:122 (4)
    //         004720ff     POP        ESI
    //         00472100     RET        0x28
}

// Offset: 0x00472110
ButtonType buttonType(TButtonPanel* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: enum TButtonPanel::ButtonType __thiscall TButtonPanel::buttonType(void)const                  *
    //                              *********************************************************************************************************
    //                              ButtonType __thiscall buttonType(TButtonPanel * this)
    //              ButtonType        EAX:4          <RETURN>
    //              TButtonPanel *    ECX:4 (auto)   this
    //                               ?buttonType@TButtonPanel@@QBE?AW4ButtonType@1@XZ
    //                               TButtonPanel::buttonType
    //                              Pnl_btn.cpp:127 (6)
    //         00472110     MOV        EAX,dword ptr [ECX + this->buttonTypeValue]
    //                              Pnl_btn.cpp:129 (1)
    //         00472116     RET
}

// Offset: 0x00472120
DrawType drawType(TButtonPanel* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: enum TButtonPanel::DrawType __thiscall TButtonPanel::drawType(void)const                      *
    //                              *********************************************************************************************************
    //                              DrawType __thiscall drawType(TButtonPanel * this)
    //              DrawType          EAX:4          <RETURN>
    //              TButtonPanel *    ECX:4 (auto)   this
    //                               ?drawType@TButtonPanel@@QBE?AW4DrawType@1@XZ
    //                               TButtonPanel::drawType
    //                              Pnl_btn.cpp:134 (6)
    //         00472120     MOV        EAX,dword ptr [ECX + this->drawTypeValue]
    //                              Pnl_btn.cpp:136 (1)
    //         00472126     RET
}

// Offset: 0x00472130
NotifyType notifyType(TButtonPanel* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: enum TButtonPanel::NotifyType __thiscall TButtonPanel::notifyType(void)const                  *
    //                              *********************************************************************************************************
    //                              NotifyType __thiscall notifyType(TButtonPanel * this)
    //              NotifyType        EAX:4          <RETURN>
    //              TButtonPanel *    ECX:4 (auto)   this
    //                               ?notifyType@TButtonPanel@@QBE?AW4NotifyType@1@XZ
    //                               TButtonPanel::notifyType
    //                              Pnl_btn.cpp:141 (6)
    //         00472130     MOV        EAX,dword ptr [ECX + this->notifyTypeValue]
    //                              Pnl_btn.cpp:143 (1)
    //         00472136     RET
}

// Offset: 0x00472140
void setDrawType(TButtonPanel* this_, DrawType param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TButtonPanel::setDrawType(enum TButtonPanel::DrawType)                        *
    //                              *********************************************************************************************************
    //                              void __thiscall setDrawType(TButtonPanel * this, DrawType param_1)
    //              void              <VOID>         <RETURN>
    //              TButtonPanel *    ECX:4 (auto)   this
    //              DrawType          Stack[0x4]:4   param_1                   XREF[1]:     00472140(R)  
    //                               ?setDrawType@TButtonPanel@@QAEXW4DrawType@1@@Z               XREF[11]:    TribeDiplomacyDialog:0043d162(c), 
    //                               TButtonPanel::setDrawType                                                 TribeDiplomacyDialog:0043d16b(c), 
    //                                                                                                         TribeDiplomacyDialog:0043d175(c), 
    //                                                                                                         TribeDiplomacyDialog:0043d17e(c), 
    //                                                                                                         create_check_box:00468885(c), 
    //                                                                                                         create_check_box:004688ea(c), 
    //                                                                                                         create_radio_button:00468adc(c), 
    //                                                                                                         create_radio_button:00468b0b(c), 
    //                                                                                                         TRIBE_Screen_Game:0049467a(c), 
    //                                                                                                         TRIBE_Screen_Game:00494730(c), 
    //                                                                                                         TRIBE_Screen_Game:0049479e(c)  
    //                              Pnl_btn.cpp:148 (10)
    //         00472140     MOV        EAX,dword ptr [ESP + param_1]
    //         00472144     MOV        dword ptr [ECX + this->drawTypeValue],EAX
    //                              Pnl_btn.cpp:150 (3)
    //         0047214a     RET        0x4
}

// Offset: 0x00472150
void setButtonType(TButtonPanel* this_, ButtonType param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TButtonPanel::setButtonType(enum TButtonPanel::ButtonType)                    *
    //                              *********************************************************************************************************
    //                              void __thiscall setButtonType(TButtonPanel * this, ButtonType param_1)
    //              void              <VOID>         <RETURN>
    //              TButtonPanel *    ECX:4 (auto)   this
    //              ButtonType        Stack[0x4]:4   param_1                   XREF[1]:     00472150(R)  
    //                               ?setButtonType@TButtonPanel@@QAEXW4ButtonType@1@@Z
    //                               TButtonPanel::setButtonType
    //                              Pnl_btn.cpp:155 (10)
    //         00472150     MOV        EAX,dword ptr [ESP + param_1]
    //         00472154     MOV        dword ptr [ECX + this->buttonTypeValue],EAX
    //                              Pnl_btn.cpp:157 (3)
    //         0047215a     RET        0x4
}

// Offset: 0x00472160
void set_picture_info(TButtonPanel* this_, TShape* param_2, short param_3, long param_4, long param_5, int param_6, int param_7) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TButtonPanel::set_picture_info(class TShape *,short,long,long,int,int)        *
    //                              *********************************************************************************************************
    //                              void __thiscall set_picture_info(TButtonPanel * this, TShape * param
    //              void              <VOID>         <RETURN>
    //              TButtonPanel *    ECX:4 (auto)   this
    //              TShape *          Stack[0x4]:4   param_1                   XREF[1]:     0047218c(R)  
    //              short             Stack[0x8]:2   param_2                   XREF[1]:     00472182(R)  
    //              long              Stack[0xc]:4   param_3                   XREF[1]:     00472160(R)  
    //              long              Stack[0x10]:4  param_4                   XREF[1]:     00472164(R)  
    //              int               Stack[0x14]:4  param_5                   XREF[1]:     0047216e(R)  
    //              int               Stack[0x18]:4  param_6                   XREF[1]:     00472178(R)  
    //                               ?set_picture_info@TButtonPanel@@QAEXPAVTShape@@FJJHH@Z
    //                               TButtonPanel::set_picture_info
    //                              Pnl_btn.cpp:164 (4)
    //         00472160     MOV        EAX,dword ptr [ESP + param_3]
    //                              Pnl_btn.cpp:166 (10)
    //         00472164     MOV        EDX,dword ptr [ESP + param_4]
    //         00472168     MOV        dword ptr [ECX + this->pic_x],EAX
    //                              Pnl_btn.cpp:167 (10)
    //         0047216e     MOV        EAX,dword ptr [ESP + param_5]
    //         00472172     MOV        dword ptr [ECX + this->pic_y],EDX
    //                              Pnl_btn.cpp:168 (10)
    //         00472178     MOV        EDX,dword ptr [ESP + param_6]
    //         0047217c     MOV        dword ptr [ECX + this->all_hot],EAX
    //                              Pnl_btn.cpp:169 (23)
    //         00472182     MOV        EAX,dword ptr [ESP + param_2]
    //         00472186     MOV        dword ptr [ECX + this->auto_pic_pos],EDX
    //         0047218c     MOV        EDX,dword ptr [ESP + param_1]
    //         00472190     PUSH       EAX
    //         00472191     PUSH       EDX
    //         00472192     PUSH       0x0
    //         00472194     CALL       TButtonPanel::set_picture                        void set_picture(TButtonPanel * this, short p
    //                              Pnl_btn.cpp:170 (3)
    //         00472199     RET        0x18
}

// Offset: 0x004721A0
void set_text_info(TButtonPanel* this_, char* param_2, void* param_3, long param_4, long param_5, long param_6, long param_7) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TButtonPanel::set_text_info(char *,void *,long,long,long,long)                *
    //                              *********************************************************************************************************
    //                              void __thiscall set_text_info(TButtonPanel * this, char * param_1, v
    //              void              <VOID>         <RETURN>
    //              TButtonPanel *    ECX:4 (auto)   this
    //              char *            Stack[0x4]:4   param_1                   XREF[1]:     004721b4(R)  
    //              void *            Stack[0x8]:4   param_2                   XREF[1]:     004721ca(R)  
    //              long              Stack[0xc]:4   param_3                   XREF[1]:     004721c6(R)  
    //              long              Stack[0x10]:4  param_4                   XREF[1]:     004721c2(R)  
    //              long              Stack[0x14]:4  param_5                   XREF[1]:     004721a8(R)  
    //              long              Stack[0x18]:4  param_6                   XREF[1]:     004721a0(R)  
    //                               ?set_text_info@TButtonPanel@@QAEXPADPAXJJJJ@Z                XREF[14]:    create_button:0046866a(c), 
    //                               TButtonPanel::set_text_info                                               create_check_box:004688d3(c), 
    //                                                                                                         create_radio_button:00468b33(c), 
    //                                                                                                         RGE_Panel_Tool_Box:00489a11(c), 
    //                                                                                                         RGE_Panel_Tool_Box:00489a9c(c), 
    //                                                                                                         RGE_Panel_Tool_Box:00489b27(c), 
    //                                                                                                         RGE_Panel_Tool_Box:00489bb5(c), 
    //                                                                                                         RGE_Panel_Tool_Box:00489c43(c), 
    //                                                                                                         RGE_Panel_Tool_Box:00489cde(c), 
    //                                                                                                         RGE_Panel_Tool_Box:00489e18(c), 
    //                                                                                                         TribeEndScreen:00493b9e(c), 
    //                                                                                                         TribeSelectTribeScreen:004b79c9(c)
    //                                                                                                         TribeSelectTribeScreen:004b7c3e(c)
    //                                                                                                         TribeSelectTribeScreen:004b7d59(c)
    //                              Pnl_btn.cpp:177 (20)
    //         004721a0     MOV        EAX,dword ptr [ESP + param_6]
    //         004721a4     PUSH       ESI
    //         004721a5     MOV        ESI,this
    //         004721a7     PUSH       EAX
    //         004721a8     MOV        this,dword ptr [ESP + param_5]
    //         004721ac     PUSH       this
    //         004721ad     MOV        this,ESI
    //         004721af     CALL       TButtonPanel::set_text_pos                       void set_text_pos(TButtonPanel * this, long p
    //                              Pnl_btn.cpp:179 (14)
    //         004721b4     MOV        EDX,dword ptr [ESP + param_1]
    //         004721b8     MOV        this,ESI
    //         004721ba     PUSH       EDX
    //         004721bb     PUSH       0x0
    //         004721bd     CALL       TButtonPanel::set_text                           void set_text(TButtonPanel * this, short para
    //                              Pnl_btn.cpp:180 (22)
    //         004721c2     MOV        EAX,dword ptr [ESP + param_4]
    //         004721c6     MOV        this,dword ptr [ESP + param_3]
    //         004721ca     MOV        EDX,dword ptr [ESP + param_2]
    //         004721ce     PUSH       EAX
    //         004721cf     PUSH       this
    //         004721d0     PUSH       EDX
    //         004721d1     MOV        this,ESI
    //         004721d3     CALL       TButtonPanel::set_font                           void set_font(TButtonPanel * this, void * par
    //                              Pnl_btn.cpp:181 (4)
    //         004721d8     POP        ESI
    //         004721d9     RET        0x18
}

// Offset: 0x004721E0
void set_text_info(TButtonPanel* this_, long param_2, void* param_3, long param_4, long param_5, long param_6, long param_7) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TButtonPanel::set_text_info(long,void *,long,long,long,long)                  *
    //                              *********************************************************************************************************
    //                              void __thiscall set_text_info(TButtonPanel * this, long param_1, voi
    //              void              <VOID>         <RETURN>
    //              TButtonPanel *    ECX:4 (auto)   this
    //              long              Stack[0x4]:4   param_1                   XREF[1]:     004721f4(R)  
    //              void *            Stack[0x8]:4   param_2                   XREF[1]:     0047220a(R)  
    //              long              Stack[0xc]:4   param_3                   XREF[1]:     00472206(R)  
    //              long              Stack[0x10]:4  param_4                   XREF[1]:     00472202(R)  
    //              long              Stack[0x14]:4  param_5                   XREF[1]:     004721e8(R)  
    //              long              Stack[0x18]:4  param_6                   XREF[1]:     004721e0(R)  
    //                               ?set_text_info@TButtonPanel@@QAEXJPAXJJJJ@Z
    //                               TButtonPanel::set_text_info
    //                              Pnl_btn.cpp:188 (20)
    //         004721e0     MOV        EAX,dword ptr [ESP + param_6]
    //         004721e4     PUSH       ESI
    //         004721e5     MOV        ESI,this
    //         004721e7     PUSH       EAX
    //         004721e8     MOV        this,dword ptr [ESP + param_5]
    //         004721ec     PUSH       this
    //         004721ed     MOV        this,ESI
    //         004721ef     CALL       TButtonPanel::set_text_pos                       void set_text_pos(TButtonPanel * this, long p
    //                              Pnl_btn.cpp:190 (14)
    //         004721f4     MOV        EDX,dword ptr [ESP + param_1]
    //         004721f8     MOV        this,ESI
    //         004721fa     PUSH       EDX
    //         004721fb     PUSH       0x0
    //         004721fd     CALL       TButtonPanel::set_text                           void set_text(TButtonPanel * this, short para
    //                              Pnl_btn.cpp:191 (22)
    //         00472202     MOV        EAX,dword ptr [ESP + param_4]
    //         00472206     MOV        this,dword ptr [ESP + param_3]
    //         0047220a     MOV        EDX,dword ptr [ESP + param_2]
    //         0047220e     PUSH       EAX
    //         0047220f     PUSH       this
    //         00472210     PUSH       EDX
    //         00472211     MOV        this,ESI
    //         00472213     CALL       TButtonPanel::set_font                           void set_font(TButtonPanel * this, void * par
    //                              Pnl_btn.cpp:192 (4)
    //         00472218     POP        ESI
    //         00472219     RET        0x18
}

// Offset: 0x00472220
void set_text_pos(TButtonPanel* this_, long param_2, long param_3) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TButtonPanel::set_text_pos(long,long)                                         *
    //                              *********************************************************************************************************
    //                              void __thiscall set_text_pos(TButtonPanel * this, long param_1, long
    //              void              <VOID>         <RETURN>
    //              TButtonPanel *    ECX:4 (auto)   this
    //              long              Stack[0x4]:4   param_1                   XREF[1]:     00472220(R)  
    //              long              Stack[0x8]:4   param_2                   XREF[1]:     00472224(R)  
    //                               ?set_text_pos@TButtonPanel@@QAEXJJ@Z                         XREF[2]:     set_text_info:004721af(c), 
    //                               TButtonPanel::set_text_pos                                                set_text_info:004721ef(c)  
    //                              Pnl_btn.cpp:198 (4)
    //         00472220     MOV        EAX,dword ptr [ESP + param_1]
    //                              Pnl_btn.cpp:200 (10)
    //         00472224     MOV        EDX,dword ptr [ESP + param_2]
    //         00472228     MOV        dword ptr [ECX + this->text_x],EAX
    //                              Pnl_btn.cpp:201 (13)
    //         0047222e     MOV        EAX,dword ptr [this->_padding_]
    //         00472230     PUSH       0x1
    //         00472232     MOV        dword ptr [ECX + this->text_y],EDX
    //         00472238     CALL       dword ptr [EAX + 0x20]
    //                              Pnl_btn.cpp:202 (3)
    //         0047223b     RET        0x8
}

// Offset: 0x00472240
void set_radio_info(TButtonPanel* this_, TButtonPanel** param_2, short param_3) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TButtonPanel::set_radio_info(class TButtonPanel * *,short)                    *
    //                              *********************************************************************************************************
    //                              void __thiscall set_radio_info(TButtonPanel * this, TButtonPanel * *
    //              void              <VOID>         <RETURN>
    //              TButtonPanel *    ECX:4 (auto)   this
    //              TButtonPanel *    Stack[0x4]:4   param_1                   XREF[1]:     00472296(R)  
    //              short             Stack[0x8]:2   param_2                   XREF[1]:     0047226c(R)  
    //                               ?set_radio_info@TButtonPanel@@QAEXPAPAV1@F@Z                 XREF[25]:    TribeConfigDialog:0043b7c4(c), 
    //                               TButtonPanel::set_radio_info                                              TribeConfigDialog:0043bbfd(c), 
    //                                                                                                         TribeConfigDialog:0043bd94(c), 
    //                                                                                                         TribeConfigDialog:0043beb1(c), 
    //                                                                                                         RGE_Panel_Tool_Box:00489d45(c), 
    //                                                                                                         RGE_Panel_Tool_Box:00489d57(c), 
    //                                                                                                         RGE_Panel_Tool_Box:00489d69(c), 
    //                                                                                                         RGE_Panel_Tool_Box:00489d7b(c), 
    //                                                                                                         RGE_Panel_Tool_Box:00489d8d(c), 
    //                                                                                                         RGE_Panel_Tool_Box:00489d9f(c), 
    //                                                                                                         create_all_buttons_etc:004af8a4(c)
    //                                                                                                         create_all_buttons_etc:004afc31(c)
    //                                                                                                         create_all_buttons_etc:004aff7b(c)
    //                                                                                                         create_all_buttons_etc:004aff98(c)
    //                                                                                                         create_all_buttons_etc:004b00e3(c)
    //                                                                                                         create_all_buttons_etc:004b07e6(c)
    //                                                                                                         create_all_buttons_etc:004b0c63(c)
    //                                                                                                         create_all_buttons_etc:004b12f4(c)
    //                                                                                                         create_all_buttons_etc:004b193f(c)
    //                                                                                                         create_all_buttons_etc:004b1949(c)
    //                                                                                                         [more]
    //                              Pnl_btn.cpp:207 (5)
    //         00472240     PUSH       EBX
    //         00472241     PUSH       ESI
    //         00472242     MOV        ESI,this
    //         00472244     PUSH       EDI
    //                              Pnl_btn.cpp:212 (20)
    //         00472245     MOV        EAX,dword ptr [ESI + 0x1fc]
    //         0047224b     MOV        dword ptr [ESI + 0x13c],0x2
    //         00472255     TEST       EAX,EAX
    //         00472257     JZ         LAB_0047226c
    //                              Pnl_btn.cpp:213 (9)
    //         00472259     PUSH       EAX
    //         0047225a     CALL       free                                             undefined free()
    //         0047225f     ADD        ESP,0x4
    //                              Pnl_btn.cpp:214 (10)
    //         00472262     MOV        dword ptr [ESI + 0x1fc],0x0
    //                               LAB_0047226c                                                 XREF[1]:     00472257(j)  
    //                              Pnl_btn.cpp:217 (10)
    //         0047226c     MOV        DI,word ptr [ESP + param_2]
    //         00472271     TEST       DI,DI
    //         00472274     JZ         LAB_004722b0
    //                              Pnl_btn.cpp:221 (27)
    //         00472276     MOVSX      EBX,DI
    //         00472279     PUSH       0x4
    //         0047227b     PUSH       EBX
    //         0047227c     MOV        word ptr [ESI + 0x200],DI
    //         00472283     CALL       calloc                                           undefined calloc()
    //         00472288     ADD        ESP,0x8
    //         0047228b     MOV        dword ptr [ESI + 0x1fc],EAX
    //                              Pnl_btn.cpp:223 (5)
    //         00472291     TEST       DI,DI
    //         00472294     JLE        LAB_004722b0
    //                              Pnl_btn.cpp:225 (32)
    //         00472296     MOV        EDX,dword ptr [ESP + param_1]
    //         0047229a     XOR        EAX,EAX
    //         0047229c     MOV        this,EBX
    //                               LAB_0047229e                                                 XREF[1]:     004722ae(j)  
    //         0047229e     MOV        EDI,dword ptr [ESI + 0x1fc]
    //         004722a4     MOV        EBX,dword ptr [EDX + EAX*0x1]
    //         004722a7     MOV        dword ptr [EDI + EAX*0x1],EBX
    //         004722aa     ADD        EAX,0x4
    //         004722ad     DEC        this
    //         004722ae     JNZ        LAB_0047229e
    //                               LAB_004722b0                                                 XREF[2]:     00472274(j), 00472294(j)  
    //         004722b0     POP        EDI
    //         004722b1     POP        ESI
    //         004722b2     POP        EBX
    //         004722b3     RET        0x8
}

// Offset: 0x004722C0
void set_state_info(TButtonPanel* this_, short param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TButtonPanel::set_state_info(short)                                           *
    //                              *********************************************************************************************************
    //                              void __thiscall set_state_info(TButtonPanel * this, short param_1)
    //              void              <VOID>         <RETURN>
    //              TButtonPanel *    ECX:4 (auto)   this
    //              short             Stack[0x4]:2   param_1                   XREF[1]:     004722c0(R)  
    //                               ?set_state_info@TButtonPanel@@QAEXF@Z                        XREF[4]:     create_check_box:00468872(c), 
    //                               TButtonPanel::set_state_info                                              RGE_Panel_Tool_Box:00489e37(c), 
    //                                                                                                         TribeMPSetupScreen:004a05de(c), 
    //                                                                                                         fillPlayerColors:004a55c4(c)  
    //                              Pnl_btn.cpp:231 (22)
    //         004722c0     MOV        AX,word ptr [ESP + param_1]
    //         004722c5     MOV        dword ptr [ECX + this->buttonTypeValue],0x3
    //         004722cf     MOV        word ptr [ECX + this->num_states],AX
    //                              Pnl_btn.cpp:236 (3)
    //         004722d6     RET        0x4
}

// Offset: 0x004722E0
void set_id(TButtonPanel* this_, short param_2, long param_3, long param_4) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TButtonPanel::set_id(short,long,long)                                         *
    //                              *********************************************************************************************************
    //                              void __thiscall set_id(TButtonPanel * this, short param_1, long para
    //              void              <VOID>         <RETURN>
    //              TButtonPanel *    ECX:4 (auto)   this
    //              short             Stack[0x4]:2   param_1                   XREF[1]:     004722e0(R)  
    //              long              Stack[0x8]:4   param_2                   XREF[1]:     004722e5(R)  
    //              long              Stack[0xc]:4   param_3                   XREF[1]:     004722f0(R)  
    //                               ?set_id@TButtonPanel@@QAEXFJJ@Z                              XREF[10]:    setup:004720f5(c), 
    //                               TButtonPanel::set_id                                                      TRIBE_Screen_Game:004945d7(c), 
    //                                                                                                         TRIBE_Screen_Game:004945f4(c), 
    //                                                                                                         TRIBE_Screen_Game:00494615(c), 
    //                                                                                                         TRIBE_Screen_Game:00494636(c), 
    //                                                                                                         TRIBE_Screen_Game:00494657(c), 
    //                                                                                                         disable_unused_buttons:0049a8c8(c)
    //                                                                                                         set_button:0049ac0c(c), 
    //                                                                                                         TribeMPSetupScreen:004a0617(c), 
    //                                                                                                         fillPlayerColors:004a5553(c)  
    //                              Pnl_btn.cpp:242 (16)
    //         004722e0     MOVSX      EAX,word ptr [ESP + param_1]
    //         004722e5     MOV        EDX,dword ptr [ESP + param_2]
    //         004722e9     MOV        dword ptr [ECX + EAX*0x4 + this->id[0]],EDX
    //                              Pnl_btn.cpp:246 (11)
    //         004722f0     MOV        EDX,dword ptr [ESP + param_3]
    //         004722f4     MOV        dword ptr [ECX + EAX*0x4 + this->id2[0]],EDX
    //                              Pnl_btn.cpp:247 (3)
    //         004722fb     RET        0xc
}

// Offset: 0x00472300
void set_picture(TButtonPanel* this_, short param_2, TShape* param_3, short param_4) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TButtonPanel::set_picture(short,class TShape *,short)                         *
    //                              *********************************************************************************************************
    //                              void __thiscall set_picture(TButtonPanel * this, short param_1, TSha
    //              void              <VOID>         <RETURN>
    //              TButtonPanel *    ECX:4 (auto)   this
    //              short             Stack[0x4]:2   param_1                   XREF[1]:     00472300(R)  
    //              TShape *          Stack[0x8]:4   param_2                   XREF[1]:     00472305(R)  
    //              short             Stack[0xc]:2   param_3                   XREF[1]:     00472312(R)  
    //                               ?set_picture@TButtonPanel@@QAEXFPAVTShape@@F@Z               XREF[13]:    TribeDiplomacyDialog:0043d11e(c), 
    //                               TButtonPanel::set_picture                                                 TribeDiplomacyDialog:0043d130(c), 
    //                                                                                                         TribeDiplomacyDialog:0043d143(c), 
    //                                                                                                         TribeDiplomacyDialog:0043d155(c), 
    //                                                                                                         create_check_box:00468897(c), 
    //                                                                                                         create_check_box:004688a9(c), 
    //                                                                                                         create_radio_button:00468aee(c), 
    //                                                                                                         create_radio_button:00468b00(c), 
    //                                                                                                         set_picture_info:00472194(c), 
    //                                                                                                         set_buttons:00474844(c), 
    //                                                                                                         player_changed:00499140(c), 
    //                                                                                                         player_changed:0049917d(c), 
    //                                                                                                         set_button:0049ac00(c)  
    //                              Pnl_btn.cpp:253 (9)
    //         00472300     MOVSX      EAX,word ptr [ESP + param_1]
    //         00472305     MOV        EDX,dword ptr [ESP + param_2]
    //                              Pnl_btn.cpp:275 (27)
    //         00472309     PUSH       0x1
    //         0047230b     MOV        dword ptr [ECX + EAX*0x4 + this->pic[0]],EDX
    //         00472312     MOV        DX,word ptr [ESP + param_3]
    //         00472317     MOV        word ptr [ECX + EAX*0x2 + this->pic_index[0]],DX
    //         0047231f     MOV        EAX,dword ptr [this->_padding_]
    //         00472321     CALL       dword ptr [EAX + 0x20]
    //                              Pnl_btn.cpp:276 (3)
    //         00472324     RET        0xc
}

// Offset: 0x00472330
void set_text(TButtonPanel* this_, short param_2, char* param_3) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TButtonPanel::set_text(short,char *)                                          *
    //                              *********************************************************************************************************
    //                              void __thiscall set_text(TButtonPanel * this, short param_1, char * 
    //              void              <VOID>         <RETURN>
    //              TButtonPanel *    ECX:4 (auto)   this
    //              short             Stack[0x4]:2   param_1                   XREF[1]:     00472335(R)  
    //              char *            Stack[0x8]:4   param_2                   XREF[2]:     00472373(R), 004723c5(R)  
    //                               ?set_text@TButtonPanel@@QAEXFPAD@Z                           XREF[25]:    action:0043dc3b(c), 
    //                               TButtonPanel::set_text                                                    action:0043dc4c(c), 
    //                                                                                                         action:0043dc5e(c), 
    //                                                                                                         action:0043dc70(c), 
    //                                                                                                         create_button:0046867c(c), 
    //                                                                                                         create_check_box:004688e1(c), 
    //                                                                                                         create_radio_button:00468b41(c), 
    //                                                                                                         set_text_info:004721bd(c), 
    //                                                                                                         set_text:00472571(c), 
    //                                                                                                         RGE_Panel_Tool_Box:00489a23(c), 
    //                                                                                                         RGE_Panel_Tool_Box:00489aae(c), 
    //                                                                                                         RGE_Panel_Tool_Box:00489b39(c), 
    //                                                                                                         RGE_Panel_Tool_Box:00489bc7(c), 
    //                                                                                                         RGE_Panel_Tool_Box:00489c55(c), 
    //                                                                                                         RGE_Panel_Tool_Box:00489cf0(c), 
    //                                                                                                         RGE_Panel_Tool_Box:00489e2a(c), 
    //                                                                                                         TRIBE_Screen_Game:004946b2(c), 
    //                                                                                                         TribeMPSetupScreen:004a0604(c), 
    //                                                                                                         fillPlayerColors:004a5548(c), 
    //                                                                                                         create_button:004a8883(c), [more]
    //                              Pnl_btn.cpp:282 (5)
    //         00472330     PUSH       EBX
    //         00472331     PUSH       EBP
    //         00472332     PUSH       ESI
    //         00472333     MOV        EBP,this
    //                              Pnl_btn.cpp:290 (19)
    //         00472335     MOVSX      ESI,word ptr [ESP + param_1]
    //         0047233a     XOR        EBX,EBX
    //         0047233c     PUSH       EDI
    //         0047233d     MOV        EAX,dword ptr [EBP + ESI*0x4 + 0x198]
    //         00472344     CMP        EAX,EBX
    //         00472346     JZ         LAB_00472358
    //                              Pnl_btn.cpp:292 (9)
    //         00472348     PUSH       EAX
    //         00472349     CALL       free                                             undefined free()
    //         0047234e     ADD        ESP,0x4
    //                              Pnl_btn.cpp:293 (7)
    //         00472351     MOV        dword ptr [EBP + ESI*0x4 + 0x198],EBX
    //                               LAB_00472358                                                 XREF[1]:     00472346(j)  
    //                              Pnl_btn.cpp:296 (11)
    //         00472358     MOV        EAX,dword ptr [EBP + ESI*0x4 + 0x1bc]
    //         0047235f     CMP        EAX,EBX
    //         00472361     JZ         LAB_00472373
    //                              Pnl_btn.cpp:298 (9)
    //         00472363     PUSH       EAX
    //         00472364     CALL       free                                             undefined free()
    //         00472369     ADD        ESP,0x4
    //                              Pnl_btn.cpp:299 (7)
    //         0047236c     MOV        dword ptr [EBP + ESI*0x4 + 0x1bc],EBX
    //                               LAB_00472373                                                 XREF[1]:     00472361(j)  
    //                              Pnl_btn.cpp:302 (21)
    //         00472373     MOV        EDI,dword ptr [ESP + param_2]
    //         00472377     CMP        EDI,EBX
    //         00472379     JZ         LAB_00472426
    //         0047237f     CMP        byte ptr [EDI],0x0
    //         00472382     JZ         LAB_00472426
    //                              Pnl_btn.cpp:305 (13)
    //         00472388     PUSH       0xa
    //         0047238a     PUSH       EDI
    //         0047238b     CALL       strchr                                           undefined strchr()
    //         00472390     MOV        EBX,EAX
    //         00472392     ADD        ESP,0x8
    //                              Pnl_btn.cpp:308 (4)
    //         00472395     TEST       EBX,EBX
    //         00472397     JZ         LAB_0047239f
    //                              Pnl_btn.cpp:309 (4)
    //         00472399     MOV        this,EBX
    //         0047239b     SUB        this,EDI
    //                              Pnl_btn.cpp:310 (2)
    //         0047239d     JMP        LAB_004723a9
    //                               LAB_0047239f                                                 XREF[1]:     00472397(j)  
    //                              Pnl_btn.cpp:311 (10)
    //         0047239f     OR         this,0xffffffff
    //         004723a2     XOR        EAX,EAX
    //         004723a4     SCASB.RE   ES:EDI
    //         004723a6     NOT        this
    //         004723a8     DEC        this
    //                               LAB_004723a9                                                 XREF[1]:     0047239d(j)  
    //                              Pnl_btn.cpp:313 (24)
    //         004723a9     MOVSX      EDI,this
    //         004723ac     PUSH       0x1
    //         004723ae     LEA        EAX,[EDI + 0x1]
    //         004723b1     PUSH       EAX
    //         004723b2     CALL       calloc                                           undefined calloc()
    //         004723b7     ADD        ESP,0x8
    //         004723ba     MOV        dword ptr [EBP + ESI*0x4 + 0x198],EAX
    //                              Pnl_btn.cpp:314 (4)
    //         004723c1     TEST       EAX,EAX
    //         004723c3     JZ         LAB_00472426
    //                              Pnl_btn.cpp:316 (12)
    //         004723c5     MOV        this,dword ptr [ESP + param_2]
    //         004723c9     PUSH       EDI
    //         004723ca     PUSH       this
    //         004723cb     PUSH       EAX
    //         004723cc     CALL       strncpy                                          undefined strncpy()
    //                              Pnl_btn.cpp:317 (10)
    //         004723d1     MOV        EDX,dword ptr [EBP + ESI*0x4 + 0x198]
    //         004723d8     ADD        ESP,0xc
    //                              Pnl_btn.cpp:320 (8)
    //         004723db     TEST       EBX,EBX
    //         004723dd     MOV        byte ptr [EDI + EDX*0x1],0x0
    //         004723e1     JZ         LAB_00472426
    //                              Pnl_btn.cpp:322 (1)
    //         004723e3     INC        EBX
    //                              Pnl_btn.cpp:323 (24)
    //         004723e4     OR         this,0xffffffff
    //         004723e7     MOV        EDI,EBX
    //         004723e9     XOR        EAX,EAX
    //         004723eb     SCASB.RE   ES:EDI
    //         004723ed     NOT        this
    //         004723ef     PUSH       0x1
    //         004723f1     PUSH       this
    //         004723f2     CALL       calloc                                           undefined calloc()
    //         004723f7     MOV        EDX,EAX
    //         004723f9     ADD        ESP,0x8
    //                              Pnl_btn.cpp:324 (11)
    //         004723fc     TEST       EDX,EDX
    //         004723fe     MOV        dword ptr [EBP + ESI*0x4 + 0x1bc],EDX
    //         00472405     JZ         LAB_00472426
    //                              Pnl_btn.cpp:325 (31)
    //         00472407     MOV        EDI,EBX
    //         00472409     OR         this,0xffffffff
    //         0047240c     XOR        EAX,EAX
    //         0047240e     SCASB.RE   ES:EDI
    //         00472410     NOT        this
    //         00472412     SUB        EDI,this
    //         00472414     MOV        EAX,this
    //         00472416     MOV        ESI,EDI
    //         00472418     MOV        EDI,EDX
    //         0047241a     SHR        this,0x2
    //         0047241d     MOVSD.REP  ES:EDI,ESI
    //         0047241f     MOV        this,EAX
    //         00472421     AND        this,0x3
    //         00472424     MOVSB.REP  ES:EDI,ESI
    //                               LAB_00472426                                                 XREF[5]:     00472379(j), 00472382(j), 
    //                                                                                                         004723c3(j), 004723e1(j), 
    //                                                                                                         00472405(j)  
    //                              Pnl_btn.cpp:330 (10)
    //         00472426     MOV        EDX,dword ptr [EBP]
    //         00472429     PUSH       0x1
    //         0047242b     MOV        this,EBP
    //         0047242d     CALL       dword ptr [EDX + 0x20]
    //                              Pnl_btn.cpp:331 (7)
    //         00472430     POP        EDI
    //         00472431     POP        ESI
    //         00472432     POP        EBP
    //         00472433     POP        EBX
    //         00472434     RET        0x8
}

// Offset: 0x00472440
void set_text(TButtonPanel* this_, short param_2, char* param_3, char* param_4) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TButtonPanel::set_text(short,char *,char *)                                   *
    //                              *********************************************************************************************************
    //                              void __thiscall set_text(TButtonPanel * this, short param_1, char * 
    //              void              <VOID>         <RETURN>
    //              TButtonPanel *    ECX:4 (auto)   this
    //              short             Stack[0x4]:2   param_1                   XREF[1]:     00472442(R)  
    //              char *            Stack[0x8]:4   param_2                   XREF[1]:     00472483(R)  
    //              char *            Stack[0xc]:4   param_3                   XREF[1]:     004724da(R)  
    //                               ?set_text@TButtonPanel@@QAEXFPAD0@Z                          XREF[2]:     set_text:004725d5(c), 
    //                               TButtonPanel::set_text                                                    set_button:0049ac2e(c)  
    //                              Pnl_btn.cpp:337 (2)
    //         00472440     PUSH       EBX
    //         00472441     PUSH       EBP
    //                              Pnl_btn.cpp:342 (22)
    //         00472442     MOVSX      EBX,word ptr [ESP + param_1]
    //         00472447     MOV        EBP,this
    //         00472449     PUSH       ESI
    //         0047244a     PUSH       EDI
    //         0047244b     XOR        EDI,EDI
    //         0047244d     MOV        EAX,dword ptr [EBP + EBX*0x4 + 0x198]
    //         00472454     CMP        EAX,EDI
    //         00472456     JZ         LAB_00472468
    //                              Pnl_btn.cpp:344 (9)
    //         00472458     PUSH       EAX
    //         00472459     CALL       free                                             undefined free()
    //         0047245e     ADD        ESP,0x4
    //                              Pnl_btn.cpp:345 (7)
    //         00472461     MOV        dword ptr [EBP + EBX*0x4 + 0x198],EDI
    //                               LAB_00472468                                                 XREF[1]:     00472456(j)  
    //                              Pnl_btn.cpp:348 (11)
    //         00472468     MOV        EAX,dword ptr [EBP + EBX*0x4 + 0x1bc]
    //         0047246f     CMP        EAX,EDI
    //         00472471     JZ         LAB_00472483
    //                              Pnl_btn.cpp:350 (9)
    //         00472473     PUSH       EAX
    //         00472474     CALL       free                                             undefined free()
    //         00472479     ADD        ESP,0x4
    //                              Pnl_btn.cpp:351 (7)
    //         0047247c     MOV        dword ptr [EBP + EBX*0x4 + 0x1bc],EDI
    //                               LAB_00472483                                                 XREF[1]:     00472471(j)  
    //                              Pnl_btn.cpp:354 (21)
    //         00472483     MOV        ESI,dword ptr [ESP + param_2]
    //         00472487     CMP        ESI,EDI
    //         00472489     JZ         LAB_00472529
    //         0047248f     CMP        byte ptr [ESI],0x0
    //         00472492     JZ         LAB_00472529
    //                              Pnl_btn.cpp:356 (24)
    //         00472498     MOV        EDI,ESI
    //         0047249a     OR         this,0xffffffff
    //         0047249d     XOR        EAX,EAX
    //         0047249f     PUSH       0x1
    //         004724a1     SCASB.RE   ES:EDI
    //         004724a3     NOT        this
    //         004724a5     PUSH       this
    //         004724a6     CALL       calloc                                           undefined calloc()
    //         004724ab     MOV        EDX,EAX
    //         004724ad     ADD        ESP,0x8
    //                              Pnl_btn.cpp:357 (11)
    //         004724b0     TEST       EDX,EDX
    //         004724b2     MOV        dword ptr [EBP + EBX*0x4 + 0x198],EDX
    //         004724b9     JZ         LAB_00472529
    //                              Pnl_btn.cpp:359 (31)
    //         004724bb     MOV        EDI,ESI
    //         004724bd     OR         this,0xffffffff
    //         004724c0     XOR        EAX,EAX
    //         004724c2     SCASB.RE   ES:EDI
    //         004724c4     NOT        this
    //         004724c6     SUB        EDI,this
    //         004724c8     MOV        EAX,this
    //         004724ca     MOV        ESI,EDI
    //         004724cc     MOV        EDI,EDX
    //         004724ce     SHR        this,0x2
    //         004724d1     MOVSD.REP  ES:EDI,ESI
    //         004724d3     MOV        this,EAX
    //         004724d5     AND        this,0x3
    //         004724d8     MOVSB.REP  ES:EDI,ESI
    //                              Pnl_btn.cpp:362 (13)
    //         004724da     MOV        ESI,dword ptr [ESP + param_3]
    //         004724de     TEST       ESI,ESI
    //         004724e0     JZ         LAB_00472529
    //         004724e2     CMP        byte ptr [ESI],0x0
    //         004724e5     JZ         LAB_00472529
    //                              Pnl_btn.cpp:364 (24)
    //         004724e7     MOV        EDI,ESI
    //         004724e9     OR         this,0xffffffff
    //         004724ec     XOR        EAX,EAX
    //         004724ee     PUSH       0x1
    //         004724f0     SCASB.RE   ES:EDI
    //         004724f2     NOT        this
    //         004724f4     PUSH       this
    //         004724f5     CALL       calloc                                           undefined calloc()
    //         004724fa     MOV        EDX,EAX
    //         004724fc     ADD        ESP,0x8
    //                              Pnl_btn.cpp:365 (11)
    //         004724ff     TEST       EDX,EDX
    //         00472501     MOV        dword ptr [EBP + EBX*0x4 + 0x1bc],EDX
    //         00472508     JZ         LAB_00472529
    //                              Pnl_btn.cpp:366 (31)
    //         0047250a     MOV        EDI,ESI
    //         0047250c     OR         this,0xffffffff
    //         0047250f     XOR        EAX,EAX
    //         00472511     SCASB.RE   ES:EDI
    //         00472513     NOT        this
    //         00472515     SUB        EDI,this
    //         00472517     MOV        EAX,this
    //         00472519     MOV        ESI,EDI
    //         0047251b     MOV        EDI,EDX
    //         0047251d     SHR        this,0x2
    //         00472520     MOVSD.REP  ES:EDI,ESI
    //         00472522     MOV        this,EAX
    //         00472524     AND        this,0x3
    //         00472527     MOVSB.REP  ES:EDI,ESI
    //                               LAB_00472529                                                 XREF[6]:     00472489(j), 00472492(j), 
    //                                                                                                         004724b9(j), 004724e0(j), 
    //                                                                                                         004724e5(j), 00472508(j)  
    //                              Pnl_btn.cpp:371 (10)
    //         00472529     MOV        EDX,dword ptr [EBP]
    //         0047252c     PUSH       0x1
    //         0047252e     MOV        this,EBP
    //         00472530     CALL       dword ptr [EDX + 0x20]
    //                              Pnl_btn.cpp:372 (7)
    //         00472533     POP        EDI
    //         00472534     POP        ESI
    //         00472535     POP        EBP
    //         00472536     POP        EBX
    //         00472537     RET        0xc
}

// Offset: 0x00472540
void set_text(TButtonPanel* this_, short param_2, long param_3) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TButtonPanel::set_text(short,long)                                            *
    //                              *********************************************************************************************************
    //                              void __thiscall set_text(TButtonPanel * this, short param_1, long pa
    //              void              <VOID>         <RETURN>
    //              TButtonPanel *    ECX:4 (auto)   this
    //              short             Stack[0x4]:2   param_1                   XREF[1]:     00472562(R)  
    //              long              Stack[0x8]:4   param_2                   XREF[1]:     0047254d(R)  
    //              char[256]         Stack[-0x104   str                       XREF[0,2]:   00472546(*), 00472569(*)  
    //                               ?set_text@TButtonPanel@@QAEXFJ@Z                             XREF[28]:    setup:0043feda(c), 
    //                               TButtonPanel::set_text                                                    set_text_info:004721fd(c), 
    //                                                                                                         TRIBE_Screen_Game:00494791(c), 
    //                                                                                                         TRIBE_Screen_Game:004947ff(c), 
    //                                                                                                         TRIBE_Screen_Main_Menu:0049e7d5(c)
    //                                                                                                         TRIBE_Screen_Main_Menu:0049e7e7(c)
    //                                                                                                         TRIBE_Screen_Main_Menu:0049e7f9(c)
    //                                                                                                         TRIBE_Screen_Main_Menu:0049e80b(c)
    //                                                                                                         TRIBE_Screen_Main_Menu:0049e81d(c)
    //                                                                                                         TribeMPSetupScreen:004a0a1e(c), 
    //                                                                                                         TribeMPSetupScreen:004a0b1e(c), 
    //                                                                                                         TRIBE_Screen_Sed_Menu:004b3069(c), 
    //                                                                                                         TRIBE_Screen_Sed_Menu:004b307b(c), 
    //                                                                                                         TRIBE_Screen_Sed_Menu:004b308d(c), 
    //                                                                                                         TRIBE_Screen_Sed_Menu:004b309f(c), 
    //                                                                                                         TribeSPMenuScreen:004b6b2c(c), 
    //                                                                                                         TribeSPMenuScreen:004b6b3e(c), 
    //                                                                                                         TribeSPMenuScreen:004b6b50(c), 
    //                                                                                                         TribeSPMenuScreen:004b6b62(c), 
    //                                                                                                         TribeSPMenuScreen:004b6b74(c), 
    //                                                                                                         [more]
    //                              Pnl_btn.cpp:378 (6)
    //         00472540     SUB        ESP,0x100
    //                              Pnl_btn.cpp:383 (28)
    //         00472546     LEA        EAX=>str[4],[ESP]
    //         0047254a     PUSH       ESI
    //         0047254b     MOV        ESI,this
    //         0047254d     MOV        this,dword ptr [ESP + param_2]
    //         00472554     PUSH       0x100
    //         00472559     PUSH       EAX
    //         0047255a     PUSH       this
    //         0047255b     MOV        this,ESI
    //         0047255d     CALL       TPanel::get_string                               int get_string(TPanel * this, int param_1, ch
    //                              Pnl_btn.cpp:384 (20)
    //         00472562     MOV        EAX,dword ptr [ESP + param_1]
    //         00472569     LEA        EDX=>str[4],[ESP + 0x4]
    //         0047256d     PUSH       EDX
    //         0047256e     PUSH       EAX
    //         0047256f     MOV        this,ESI
    //         00472571     CALL       TButtonPanel::set_text                           void set_text(TButtonPanel * this, short para
    //                              Pnl_btn.cpp:385 (10)
    //         00472576     POP        ESI
    //         00472577     ADD        ESP,0x100
    //         0047257d     RET        0x8
}

// Offset: 0x00472580
void set_text(TButtonPanel* this_, short param_2, long param_3, long param_4) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TButtonPanel::set_text(short,long,long)                                       *
    //                              *********************************************************************************************************
    //                              void __thiscall set_text(TButtonPanel * this, short param_1, long pa
    //              void              <VOID>         <RETURN>
    //              TButtonPanel *    ECX:4 (auto)   this
    //              short             Stack[0x4]:2   param_1                   XREF[1]:     004725be(R)  
    //              long              Stack[0x8]:4   param_2                   XREF[1]:     00472590(R)  
    //              long              Stack[0xc]:4   param_3                   XREF[1]:     004725a5(R)  
    //              char[256]         Stack[-0x104   str1                      XREF[0,2]:   00472586(*), 004725c9(*)  
    //              char[256]         Stack[-0x204   str2                      XREF[0,2]:   004725ac(*), 004725c5(*)  
    //                               ?set_text@TButtonPanel@@QAEXFJJ@Z
    //                               TButtonPanel::set_text
    //                              Pnl_btn.cpp:391 (6)
    //         00472580     SUB        ESP,0x200
    //                              Pnl_btn.cpp:398 (31)
    //         00472586     LEA        EAX=>str1[4],[ESP + 0x100]
    //         0047258d     PUSH       ESI
    //         0047258e     MOV        ESI,this
    //         00472590     MOV        this,dword ptr [ESP + param_2]
    //         00472597     PUSH       0x100
    //         0047259c     PUSH       EAX
    //         0047259d     PUSH       this
    //         0047259e     MOV        this,ESI
    //         004725a0     CALL       TPanel::get_string                               int get_string(TPanel * this, int param_1, ch
    //                              Pnl_btn.cpp:399 (25)
    //         004725a5     MOV        EAX,dword ptr [ESP + param_3]
    //         004725ac     LEA        EDX=>str2[4],[ESP + 0x4]
    //         004725b0     PUSH       0x100
    //         004725b5     PUSH       EDX
    //         004725b6     PUSH       EAX
    //         004725b7     MOV        this,ESI
    //         004725b9     CALL       TPanel::get_string                               int get_string(TPanel * this, int param_1, ch
    //                              Pnl_btn.cpp:401 (28)
    //         004725be     MOV        EAX,dword ptr [ESP + param_1]
    //         004725c5     LEA        this=>str2[4],[ESP + 0x4]
    //         004725c9     LEA        EDX=>str1[4],[ESP + 0x104]
    //         004725d0     PUSH       this
    //         004725d1     PUSH       EDX
    //         004725d2     PUSH       EAX
    //         004725d3     MOV        this,ESI
    //         004725d5     CALL       TButtonPanel::set_text                           void set_text(TButtonPanel * this, short para
    //                              Pnl_btn.cpp:402 (10)
    //         004725da     POP        ESI
    //         004725db     ADD        ESP,0x200
    //         004725e1     RET        0xc
}

// Offset: 0x004725F0
void set_font(TButtonPanel* this_, void* param_2, long param_3, long param_4) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TButtonPanel::set_font(void *,long,long)                                      *
    //                              *********************************************************************************************************
    //                              void __thiscall set_font(TButtonPanel * this, void * param_1, long p
    //              void              <VOID>         <RETURN>
    //              TButtonPanel *    ECX:4 (auto)   this
    //              void *            Stack[0x4]:4   param_1                   XREF[1]:     004725f0(R)  
    //              long              Stack[0x8]:4   param_2                   XREF[1]:     004725f4(R)  
    //              long              Stack[0xc]:4   param_3                   XREF[1]:     004725fe(R)  
    //                               ?set_font@TButtonPanel@@QAEXPAXJJ@Z                          XREF[3]:     set_text_info:004721d3(c), 
    //                               TButtonPanel::set_font                                                    set_text_info:00472213(c), 
    //                                                                                                         TRIBE_Panel_Button:00519e55(c)  
    //                              Pnl_btn.cpp:408 (4)
    //         004725f0     MOV        EAX,dword ptr [ESP + param_1]
    //                              Pnl_btn.cpp:410 (10)
    //         004725f4     MOV        EDX,dword ptr [ESP + param_2]
    //         004725f8     MOV        dword ptr [ECX + this->font],EAX
    //                              Pnl_btn.cpp:411 (10)
    //         004725fe     MOV        EAX,dword ptr [ESP + param_3]
    //         00472602     MOV        dword ptr [ECX + this->font_wid],EDX
    //                              Pnl_btn.cpp:412 (13)
    //         00472608     MOV        EDX,dword ptr [this->_padding_]
    //         0047260a     PUSH       0x1
    //         0047260c     MOV        dword ptr [ECX + this->font_hgt],EAX
    //         00472612     CALL       dword ptr [EDX + 0x20]
    //                              Pnl_btn.cpp:413 (3)
    //         00472615     RET        0xc
}

// Offset: 0x00472620
void set_text_color(TButtonPanel* this_, int param_2, ulong param_3, ulong param_4) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TButtonPanel::set_text_color(int,unsigned long,unsigned long)                 *
    //                              *********************************************************************************************************
    //                              void __thiscall set_text_color(TButtonPanel * this, int param_1, ulo
    //              void              <VOID>         <RETURN>
    //              TButtonPanel *    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     00472620(R)  
    //              ulong             Stack[0x8]:4   param_2                   XREF[1]:     0047262d(R)  
    //              ulong             Stack[0xc]:4   param_3                   XREF[1]:     0047263a(R)  
    //                               ?set_text_color@TButtonPanel@@QAEXHKK@Z                      XREF[17]:    create_button:004686dd(c), 
    //                               TButtonPanel::set_text_color                                              create_button:00468710(c), 
    //                                                                                                         create_check_box:0046894a(c), 
    //                                                                                                         create_check_box:00468978(c), 
    //                                                                                                         create_radio_button:00468ba1(c), 
    //                                                                                                         create_radio_button:00468bcf(c), 
    //                                                                                                         TRIBE_Screen_Game:004945ac(c), 
    //                                                                                                         player_changed:004991cc(c), 
    //                                                                                                         player_changed:004991e0(c), 
    //                                                                                                         player_changed:004991f4(c), 
    //                                                                                                         player_changed:00499208(c), 
    //                                                                                                         player_changed:00499249(c), 
    //                                                                                                         player_changed:0049925d(c), 
    //                                                                                                         player_changed:00499271(c), 
    //                                                                                                         player_changed:00499285(c), 
    //                                                                                                         player_changed:00499299(c), 
    //                                                                                                         fillPlayerColors:004a55ad(c)  
    //                              Pnl_btn.cpp:419 (13)
    //         00472620     MOV        EAX,dword ptr [ESP + param_1]
    //         00472624     TEST       EAX,EAX
    //         00472626     JL         LAB_0047264a
    //         00472628     CMP        EAX,0x8
    //         0047262b     JG         LAB_0047264a
    //                              Pnl_btn.cpp:422 (4)
    //         0047262d     MOV        EDX,dword ptr [ESP + param_2]
    //                              Pnl_btn.cpp:424 (25)
    //         00472631     PUSH       0x1
    //         00472633     MOV        dword ptr [ECX + EAX*0x4 + this->text_color1[0
    //         0047263a     MOV        EDX,dword ptr [ESP + param_3]
    //         0047263e     MOV        dword ptr [ECX + EAX*0x4 + this->text_color2[0
    //         00472645     MOV        EAX,dword ptr [this->_padding_]
    //         00472647     CALL       dword ptr [EAX + 0x20]
    //                               LAB_0047264a                                                 XREF[2]:     00472626(j), 0047262b(j)  
    //                              Pnl_btn.cpp:425 (3)
    //         0047264a     RET        0xc
}

// Offset: 0x00472650
void set_highlight_text_color(TButtonPanel* this_, int param_2, ulong param_3, ulong param_4) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TButtonPanel::set_highlight_text_color(int,unsigned long,unsigned long)       *
    //                              *********************************************************************************************************
    //                              void __thiscall set_highlight_text_color(TButtonPanel * this, int pa
    //              void              <VOID>         <RETURN>
    //              TButtonPanel *    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     00472650(R)  
    //              ulong             Stack[0x8]:4   param_2                   XREF[1]:     0047265d(R)  
    //              ulong             Stack[0xc]:4   param_3                   XREF[1]:     0047266a(R)  
    //                               ?set_highlight_text_color@TButtonPanel@@QAEXHKK@Z            XREF[6]:     create_button:004686f3(c), 
    //                               TButtonPanel::set_highlight_text_color                                    create_button:00468727(c), 
    //                                                                                                         create_check_box:00468961(c), 
    //                                                                                                         create_check_box:0046898f(c), 
    //                                                                                                         create_radio_button:00468bb8(c), 
    //                                                                                                         create_radio_button:00468be6(c)  
    //                              Pnl_btn.cpp:431 (13)
    //         00472650     MOV        EAX,dword ptr [ESP + param_1]
    //         00472654     TEST       EAX,EAX
    //         00472656     JL         LAB_0047267a
    //         00472658     CMP        EAX,0x8
    //         0047265b     JG         LAB_0047267a
    //                              Pnl_btn.cpp:434 (4)
    //         0047265d     MOV        EDX,dword ptr [ESP + param_2]
    //                              Pnl_btn.cpp:436 (25)
    //         00472661     PUSH       0x1
    //         00472663     MOV        dword ptr [ECX + EAX*0x4 + this->highlight_tex
    //         0047266a     MOV        EDX,dword ptr [ESP + param_3]
    //         0047266e     MOV        dword ptr [ECX + EAX*0x4 + this->highlight_tex
    //         00472675     MOV        EAX,dword ptr [this->_padding_]
    //         00472677     CALL       dword ptr [EAX + 0x20]
    //                               LAB_0047267a                                                 XREF[2]:     00472656(j), 0047265b(j)  
    //                              Pnl_btn.cpp:437 (3)
    //         0047267a     RET        0xc
}

// Offset: 0x00472680
void set_sound(TButtonPanel* this_, TDigital* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TButtonPanel::set_sound(class TDigital *)                                     *
    //                              *********************************************************************************************************
    //                              void __thiscall set_sound(TButtonPanel * this, TDigital * param_1)
    //              void              <VOID>         <RETURN>
    //              TButtonPanel *    ECX:4 (auto)   this
    //              TDigital *        Stack[0x4]:4   param_1                   XREF[1]:     00472680(R)  
    //                               ?set_sound@TButtonPanel@@QAEXPAVTDigital@@@Z                 XREF[1]:     setup:004720e5(c)  
    //                               TButtonPanel::set_sound
    //                              Pnl_btn.cpp:443 (10)
    //         00472680     MOV        EAX,dword ptr [ESP + param_1]
    //         00472684     MOV        dword ptr [ECX + this->sound],EAX
    //                              Pnl_btn.cpp:445 (3)
    //         0047268a     RET        0x4
}

// Offset: 0x00472690
void set_radio_button(TButtonPanel* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TButtonPanel::set_radio_button(void)                                          *
    //                              *********************************************************************************************************
    //                              void __thiscall set_radio_button(TButtonPanel * this)
    //              void              <VOID>         <RETURN>
    //              TButtonPanel *    ECX:4 (auto)   this
    //                               ?set_radio_button@TButtonPanel@@QAEXXZ                       XREF[34]:    TribeConfigDialog:0043b849(c), 
    //                               TButtonPanel::set_radio_button                                            TribeConfigDialog:0043bc37(c), 
    //                                                                                                         TribeConfigDialog:0043bdbc(c), 
    //                                                                                                         TribeConfigDialog:0043bed6(c), 
    //                                                                                                         TribeConfigDialog:0043bfeb(c), 
    //                                                                                                         TribeDiplomacyDialog:0043d023(c), 
    //                                                                                                         do_right_action:00473ae9(c), 
    //                                                                                                         game_mode_changed:0048a5da(c), 
    //                                                                                                         set_scenario_mode:004aa6ba(c), 
    //                                                                                                         set_map_type:004aa8d5(c), 
    //                                                                                                         set_mp_victory_type:004aaa60(c), 
    //                                                                                                         set_brush_size:004aaaac(c), 
    //                                                                                                         set_paint_type:004aad28(c), 
    //                                                                                                         load_multi_victory_cond_from_scena
    //                                                                                                         create_all_buttons_etc:004b00f0(c)
    //                                                                                                         create_all_buttons_etc:004b07f3(c)
    //                                                                                                         create_all_buttons_etc:004b0c74(c)
    //                                                                                                         create_all_buttons_etc:004b195b(c)
    //                                                                                                         TRIBE_Mission_Screen:004b8651(c), 
    //                                                                                                         TRIBE_Mission_Screen:004b86b5(c), 
    //                                                                                                         [more]
    //                              Pnl_btn.cpp:450 (5)
    //         00472690     PUSH       EBX
    //         00472691     PUSH       ESI
    //         00472692     MOV        ESI,this
    //         00472694     PUSH       EDI
    //                              Pnl_btn.cpp:451 (13)
    //         00472695     XOR        EBX,EBX
    //         00472697     XOR        EDI,EDI
    //         00472699     CMP        word ptr [ESI + 0x200],BX
    //         004726a0     JLE        LAB_004726cf
    //                               LAB_004726a2                                                 XREF[1]:     004726cd(j)  
    //                              Pnl_btn.cpp:452 (6)
    //         004726a2     MOV        EAX,dword ptr [ESI + 0x1fc]
    //                              Pnl_btn.cpp:453 (39)
    //         004726a8     PUSH       EBX
    //         004726a9     MOV        this,dword ptr [EAX + EDI*0x4]
    //         004726ac     MOV        dword ptr [ECX + this->is_down],EBX
    //         004726b2     MOV        EDX,dword ptr [ESI + 0x1fc]
    //         004726b8     MOV        this,dword ptr [EDX + EDI*0x4]
    //         004726bb     MOV        EAX,dword ptr [this->_padding_]
    //         004726bd     CALL       dword ptr [EAX + 0xe0]
    //         004726c3     MOVSX      this,word ptr [ESI + 0x200]
    //         004726ca     INC        EDI
    //         004726cb     CMP        EDI,this
    //         004726cd     JL         LAB_004726a2
    //                               LAB_004726cf                                                 XREF[1]:     004726a0(j)  
    //                              Pnl_btn.cpp:455 (16)
    //         004726cf     MOV        EAX,dword ptr [ESI + 0x140]
    //         004726d5     CMP        EAX,0x3
    //         004726d8     JZ         LAB_004726df
    //         004726da     CMP        EAX,0x5
    //         004726dd     JNZ        LAB_004726e9
    //                               LAB_004726df                                                 XREF[1]:     004726d8(j)  
    //                              Pnl_btn.cpp:456 (10)
    //         004726df     MOV        dword ptr [ESI + 0x1f8],0x1
    //                               LAB_004726e9                                                 XREF[1]:     004726dd(j)  
    //                              Pnl_btn.cpp:457 (12)
    //         004726e9     MOV        EDX,dword ptr [ESI]
    //         004726eb     PUSH       0x1
    //         004726ed     MOV        this,ESI
    //         004726ef     CALL       dword ptr [EDX + 0xe0]
    //                              Pnl_btn.cpp:458 (4)
    //         004726f5     POP        EDI
    //         004726f6     POP        ESI
    //         004726f7     POP        EBX
    //         004726f8     RET
}

// Offset: 0x00472700
void TDropDownButtonPanel::set_state(short param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void __thiscall TButtonPanel::set_state(short)                                        *
    //                              *********************************************************************************************************
    //                              void __thiscall set_state(TButtonPanel * this, short param_1)
    //              void              <VOID>         <RETURN>
    //              TButtonPanel *    ECX:4 (auto)   this
    //              short             Stack[0x4]:2   param_1                   XREF[1]:     00472700(R)  
    //                               ?set_state@TButtonPanel@@UAEXF@Z                             XREF[3]:     005710a8(*), 005713a0(*), 
    //                               TButtonPanel::set_state                                                   00576bb0(*)  
    //                              Pnl_btn.cpp:463 (5)
    //         00472700     MOV        AX,word ptr [ESP + param_1]
    //                              Pnl_btn.cpp:465 (14)
    //         00472705     MOV        EDX,dword ptr [this->_padding_]
    //         00472707     PUSH       0x1
    //         00472709     MOV        word ptr [ECX + this->cur_state],AX
    //         00472710     CALL       dword ptr [EDX + 0x20]
    //                              Pnl_btn.cpp:466 (3)
    //         00472713     RET        0x4
}

// Offset: 0x00472720
void set_state_by_id(TButtonPanel* this_, long param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TButtonPanel::set_state_by_id(long)                                           *
    //                              *********************************************************************************************************
    //                              void __thiscall set_state_by_id(TButtonPanel * this, long param_1)
    //              void              <VOID>         <RETURN>
    //              TButtonPanel *    ECX:4 (auto)   this
    //              long              Stack[0x4]:4   param_1                   XREF[1]:     0047272f(R)  
    //                               ?set_state_by_id@TButtonPanel@@QAEXJ@Z                       XREF[1]:     fillPlayers:004a3b0e(c)  
    //                               TButtonPanel::set_state_by_id
    //                              Pnl_btn.cpp:472 (1)
    //         00472720     PUSH       ESI
    //                              Pnl_btn.cpp:473 (24)
    //         00472721     MOVSX      ESI,word ptr [ECX + this->num_states]
    //         00472728     XOR        EAX,EAX
    //         0047272a     PUSH       EDI
    //         0047272b     TEST       ESI,ESI
    //         0047272d     JLE        LAB_00472758
    //         0047272f     MOV        EDI,dword ptr [ESP + param_1]
    //         00472733     LEA        EDX,[ECX + this->id[0]]
    //                               LAB_00472739                                                 XREF[1]:     00472743(j)  
    //                              Pnl_btn.cpp:475 (12)
    //         00472739     CMP        dword ptr [EDX],EDI
    //         0047273b     JZ         LAB_0047274a
    //         0047273d     INC        EAX
    //         0047273e     ADD        EDX,0x4
    //         00472741     CMP        EAX,ESI
    //         00472743     JL         LAB_00472739
    //                              Pnl_btn.cpp:482 (5)
    //         00472745     POP        EDI
    //         00472746     POP        ESI
    //         00472747     RET        0x4
    //                               LAB_0047274a                                                 XREF[1]:     0047273b(j)  
    //                              Pnl_btn.cpp:477 (7)
    //         0047274a     MOV        word ptr [ECX + this->cur_state],AX
    //                              Pnl_btn.cpp:478 (7)
    //         00472751     MOV        EAX,dword ptr [this->_padding_]
    //         00472753     PUSH       0x1
    //         00472755     CALL       dword ptr [EAX + 0x20]
    //                               LAB_00472758                                                 XREF[1]:     0047272d(j)  
    //                              Pnl_btn.cpp:482 (5)
    //         00472758     POP        EDI
    //         00472759     POP        ESI
    //         0047275a     RET        0x4
}

// Offset: 0x00472760
void set_bevel_info(TButtonPanel* this_, int param_2, int param_3, int param_4, int param_5, int param_6, int param_7, int param_8) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TButtonPanel::set_bevel_info(int,int,int,int,int,int,int)                     *
    //                              *********************************************************************************************************
    //                              void __thiscall set_bevel_info(TButtonPanel * this, int param_1, int
    //              void              <VOID>         <RETURN>
    //              TButtonPanel *    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     00472760(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     00472764(R)  
    //              int               Stack[0xc]:4   param_3                   XREF[1]:     0047276e(R)  
    //              int               Stack[0x10]:4  param_4                   XREF[1]:     00472778(R)  
    //              int               Stack[0x14]:4  param_5                   XREF[1]:     00472782(R)  
    //              int               Stack[0x18]:4  param_6                   XREF[1]:     0047278c(R)  
    //              int               Stack[0x1c]:4  param_7                   XREF[1]:     00472796(R)  
    //                               ?set_bevel_info@TButtonPanel@@QAEXHHHHHHH@Z                  XREF[15]:    create_button:004686c5(c), 
    //                               TButtonPanel::set_bevel_info                                              create_check_box:00468933(c), 
    //                                                                                                         create_radio_button:00468b8a(c), 
    //                                                                                                         set_bevel_info:004747cf(c), 
    //                                                                                                         TRIBE_Screen_Game:004946f1(c), 
    //                                                                                                         TRIBE_Screen_Game:00494773(c), 
    //                                                                                                         TRIBE_Screen_Game:004947e1(c), 
    //                                                                                                         player_changed:00498c4f(c), 
    //                                                                                                         player_changed:00498c92(c), 
    //                                                                                                         player_changed:00498cd5(c), 
    //                                                                                                         player_changed:00498d18(c), 
    //                                                                                                         player_changed:00498d5b(c), 
    //                                                                                                         create_button:004a88f2(c), 
    //                                                                                                         create_check_box:004b2e50(c), 
    //                                                                                                         create_radio_button:004b2ee0(c)  
    //                              Pnl_btn.cpp:488 (4)
    //         00472760     MOV        EAX,dword ptr [ESP + param_1]
    //                              Pnl_btn.cpp:490 (10)
    //         00472764     MOV        DL,byte ptr [ESP + param_2]
    //         00472768     MOV        dword ptr [ECX + this->bevel_type],EAX
    //                              Pnl_btn.cpp:491 (10)
    //         0047276e     MOV        AL,byte ptr [ESP + param_3]
    //         00472772     MOV        byte ptr [ECX + this->bevel_color1],DL
    //                              Pnl_btn.cpp:492 (10)
    //         00472778     MOV        DL,byte ptr [ESP + param_4]
    //         0047277c     MOV        byte ptr [ECX + this->bevel_color2],AL
    //                              Pnl_btn.cpp:493 (10)
    //         00472782     MOV        AL,byte ptr [ESP + param_5]
    //         00472786     MOV        byte ptr [ECX + this->bevel_color3],DL
    //                              Pnl_btn.cpp:494 (10)
    //         0047278c     MOV        DL,byte ptr [ESP + param_6]
    //         00472790     MOV        byte ptr [ECX + this->bevel_color4],AL
    //                              Pnl_btn.cpp:495 (16)
    //         00472796     MOV        AL,byte ptr [ESP + param_7]
    //         0047279a     MOV        byte ptr [ECX + this->bevel_color5],DL
    //         004727a0     MOV        byte ptr [ECX + this->bevel_color6],AL
    //                              Pnl_btn.cpp:496 (3)
    //         004727a6     RET        0x1c
}

// Offset: 0x004727B0
void set_disabled(TButtonPanel* this_, int param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TButtonPanel::set_disabled(int)                                               *
    //                              *********************************************************************************************************
    //                              void __thiscall set_disabled(TButtonPanel * this, int param_1)
    //              void              <VOID>         <RETURN>
    //              TButtonPanel *    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     004727b0(R)  
    //                               ?set_disabled@TButtonPanel@@QAEXH@Z                          XREF[29]:    TribeConfigDialog:0043b7e9(c), 
    //                               TButtonPanel::set_disabled                                                TribeConfigDialog:0043bc57(c), 
    //                                                                                                         TribeConfigDialog:0043bc7b(c), 
    //                                                                                                         TribeConfigDialog:0043bc9f(c), 
    //                                                                                                         TribeConfigDialog:0043bf7c(c), 
    //                                                                                                         check_gold:0043e587(c), 
    //                                                                                                         check_wood:0043e617(c), 
    //                                                                                                         check_food:0043e6a6(c), 
    //                                                                                                         check_stone:0043e737(c), 
    //                                                                                                         set_button:0049ab96(c), 
    //                                                                                                         TribeLoadSavedGameScreen:0049dff1(
    //                                                                                                         TribeLoadSavedGameScreen:0049dffe(
    //                                                                                                         TribeMPSetupScreen:004a0b35(c), 
    //                                                                                                         action:004a19f7(c), 
    //                                                                                                         action:004a1a10(c), 
    //                                                                                                         fillPlayers:004a3be5(c), 
    //                                                                                                         fillPlayers:004a3d13(c), 
    //                                                                                                         setup_tab_order:004a68e4(c), 
    //                                                                                                         TribeSaveGameScreen:004a753a(c), 
    //                                                                                                         TRIBE_Screen_Sed_Open:004b361e(c), 
    //                                                                                                         [more]
    //                              Pnl_btn.cpp:502 (7)
    //         004727b0     MOV        EAX,dword ptr [ESP + param_1]
    //         004727b4     PUSH       ESI
    //         004727b5     MOV        ESI,this
    //                              Pnl_btn.cpp:504 (13)
    //         004727b7     PUSH       0x1
    //         004727b9     MOV        EDX,dword ptr [ESI]
    //         004727bb     MOV        dword ptr [ESI + 0x2b0],EAX
    //         004727c1     CALL       dword ptr [EDX + 0x20]
    //                              Pnl_btn.cpp:505 (10)
    //         004727c4     MOV        EAX,dword ptr [ESI + 0x2b0]
    //         004727ca     TEST       EAX,EAX
    //         004727cc     JZ         LAB_004727dc
    //                              Pnl_btn.cpp:506 (10)
    //         004727ce     MOV        dword ptr [ESI + 0x80],0x0
    //                              Pnl_btn.cpp:509 (4)
    //         004727d8     POP        ESI
    //         004727d9     RET        0x4
    //                               LAB_004727dc                                                 XREF[1]:     004727cc(j)  
    //                              Pnl_btn.cpp:508 (10)
    //         004727dc     MOV        dword ptr [ESI + 0x80],0x1
    //                              Pnl_btn.cpp:509 (4)
    //         004727e6     POP        ESI
    //         004727e7     RET        0x4
}

// Offset: 0x004727F0
void TDropDownButtonPanel::set_rect(long param_1, long param_2, long param_3, long param_4) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void __thiscall TButtonPanel::set_rect(long,long,long,long)                           *
    //                              *********************************************************************************************************
    //                              void __thiscall set_rect(TButtonPanel * this, long param_1, long par
    //              void              <VOID>         <RETURN>
    //              TButtonPanel *    ECX:4 (auto)   this
    //              long              Stack[0x4]:4   param_1                   XREF[1]:     004727fe(R)  
    //              long              Stack[0x8]:4   param_2                   XREF[1]:     004727f9(R)  
    //              long              Stack[0xc]:4   param_3                   XREF[1]:     004727f4(R)  
    //              long              Stack[0x10]:4  param_4                   XREF[1]:     004727f0(R)  
    //                               ?set_rect@TButtonPanel@@UAEXJJJJ@Z                           XREF[3]:     00570fd4(*), 005712cc(*), 
    //                               TButtonPanel::set_rect                                                    00576adc(*)  
    //                              Pnl_btn.cpp:515 (25)
    //         004727f0     MOV        EAX,dword ptr [ESP + param_4]
    //         004727f4     MOV        EDX,dword ptr [ESP + param_3]
    //         004727f8     PUSH       EAX
    //         004727f9     MOV        EAX,dword ptr [ESP + param_2]
    //         004727fd     PUSH       EDX
    //         004727fe     MOV        EDX,dword ptr [ESP + param_1]
    //         00472802     PUSH       EAX
    //         00472803     PUSH       EDX
    //         00472804     CALL       TPanel::set_rect                                 void set_rect(TPanel * this, long param_1, lo
    //                              Pnl_btn.cpp:533 (3)
    //         00472809     RET        0x10
}

// Offset: 0x00472810
int get_state(TButtonPanel* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall TButtonPanel::get_state(void)                                                  *
    //                              *********************************************************************************************************
    //                              int __thiscall get_state(TButtonPanel * this)
    //              int               EAX:4          <RETURN>
    //              TButtonPanel *    ECX:4 (auto)   this
    //                               ?get_state@TButtonPanel@@QAEHXZ                              XREF[47]:    action:0043c328(c), 
    //                               TButtonPanel::get_state                                                   action:0043c362(c), 
    //                                                                                                         action:0043c397(c), 
    //                                                                                                         action:0043c3bf(c), 
    //                                                                                                         action:0043c3e6(c), 
    //                                                                                                         action:0043c426(c), 
    //                                                                                                         action:0043c43f(c), 
    //                                                                                                         action:0043c458(c), 
    //                                                                                                         action:0043c60c(c), 
    //                                                                                                         action:0043c61b(c), 
    //                                                                                                         action:0043c636(c), 
    //                                                                                                         action:0043d90b(c), 
    //                                                                                                         action:0043d91a(c), 
    //                                                                                                         action:0043d97b(c), 
    //                                                                                                         action:0043d98c(c), 
    //                                                                                                         action:004a1767(c), 
    //                                                                                                         action:004a1845(c), 
    //                                                                                                         action:004a2004(c), 
    //                                                                                                         action:004a2044(c), 
    //                                                                                                         fillPlayers:004a3b1a(c), [more]
    //                              Pnl_btn.cpp:538 (7)
    //         00472810     MOVSX      EAX,word ptr [ECX + this->cur_state]
    //                              Pnl_btn.cpp:540 (1)
    //         00472817     RET
}

// Offset: 0x00472820
long get_id(TButtonPanel* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: long __thiscall TButtonPanel::get_id(void)                                                    *
    //                              *********************************************************************************************************
    //                              long __thiscall get_id(TButtonPanel * this)
    //              long              EAX:4          <RETURN>
    //              TButtonPanel *    ECX:4 (auto)   this
    //                               ?get_id@TButtonPanel@@QAEJXZ                                 XREF[7]:     TRIBE_Screen_Game:0049469d(c), 
    //                               TButtonPanel::get_id                                                      player_changed:0049914b(c), 
    //                                                                                                         set_button:0049ab9d(c), 
    //                                                                                                         handle_mouse_pointing_at:0049bbf0(
    //                                                                                                         action:004a1833(c), 
    //                                                                                                         action:004a1fb4(c), 
    //                                                                                                         action:004a1feb(c)  
    //                              Pnl_btn.cpp:546 (14)
    //         00472820     MOVSX      EAX,word ptr [ECX + this->cur_state]
    //         00472827     MOV        EAX,dword ptr [ECX + EAX*0x4 + this->id[0]]
    //                              Pnl_btn.cpp:548 (1)
    //         0047282e     RET
}

// Offset: 0x00472830
long get_id2(TButtonPanel* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: long __thiscall TButtonPanel::get_id2(void)                                                   *
    //                              *********************************************************************************************************
    //                              long __thiscall get_id2(TButtonPanel * this)
    //              long              EAX:4          <RETURN>
    //              TButtonPanel *    ECX:4 (auto)   this
    //                               ?get_id2@TButtonPanel@@QAEJXZ                                XREF[1]:     set_button:0049abb6(c)  
    //                               TButtonPanel::get_id2
    //                              Pnl_btn.cpp:554 (14)
    //         00472830     MOVSX      EAX,word ptr [ECX + this->cur_state]
    //         00472837     MOV        EAX,dword ptr [ECX + EAX*0x4 + this->id2[0]]
    //                              Pnl_btn.cpp:556 (1)
    //         0047283e     RET
}

// Offset: 0x00472840
int get_text(TButtonPanel* this_, short param_2, char** param_3, char** param_4) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall TButtonPanel::get_text(short,char * *,char * *)                                *
    //                              *********************************************************************************************************
    //                              int __thiscall get_text(TButtonPanel * this, short param_1, char * *
    //              int               EAX:4          <RETURN>
    //              TButtonPanel *    ECX:4 (auto)   this
    //              short             Stack[0x4]:2   param_1                   XREF[1]:     00472840(R)  
    //              char * *          Stack[0x8]:4   param_2                   XREF[1]:     00472852(R)  
    //              char * *          Stack[0xc]:4   param_3                   XREF[1]:     00472869(R)  
    //                               ?get_text@TButtonPanel@@QAEHFPAPAD0@Z                        XREF[2]:     fillPlayers:004a3b33(c), 
    //                               TButtonPanel::get_text                                                    fillPlayers:004a3c74(c)  
    //                              Pnl_btn.cpp:562 (11)
    //         00472840     MOV        EAX,dword ptr [ESP + param_1]
    //         00472844     PUSH       ESI
    //         00472845     CMP        AX,0xffff
    //         00472849     JNZ        LAB_00472852
    //                              Pnl_btn.cpp:564 (7)
    //         0047284b     MOV        AX,word ptr [ECX + this->cur_state]
    //                               LAB_00472852                                                 XREF[1]:     00472849(j)  
    //                              Pnl_btn.cpp:565 (16)
    //         00472852     MOV        EDX,dword ptr [ESP + param_2]
    //         00472856     MOVSX      EAX,AX
    //         00472859     MOV        ESI,dword ptr [ECX + EAX*0x4 + this->text1[0]]
    //         00472860     MOV        dword ptr [EDX],ESI
    //                              Pnl_btn.cpp:566 (11)
    //         00472862     MOV        EAX,dword ptr [ECX + EAX*0x4 + this->text2[0]]
    //         00472869     MOV        this,dword ptr [ESP + param_3]
    //                              Pnl_btn.cpp:568 (15)
    //         0047286d     POP        ESI
    //         0047286e     MOV        dword ptr [this->_padding_],EAX
    //         00472870     MOV        this,dword ptr [EDX]
    //         00472872     XOR        EAX,EAX
    //         00472874     TEST       this,this
    //         00472876     SETNZ      AL
    //         00472879     RET        0xc
}

// Offset: 0x00472880
void get_text_color(TButtonPanel* this_, short param_2, ulong* param_3, ulong* param_4) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TButtonPanel::get_text_color(short,unsigned long *,unsigned long *)           *
    //                              *********************************************************************************************************
    //                              void __thiscall get_text_color(TButtonPanel * this, short param_1, u
    //              void              <VOID>         <RETURN>
    //              TButtonPanel *    ECX:4 (auto)   this
    //              short             Stack[0x4]:2   param_1                   XREF[1]:     00472880(R)  
    //              ulong *           Stack[0x8]:4   param_2                   XREF[1]:     00472892(R)  
    //              ulong *           Stack[0xc]:4   param_3                   XREF[1]:     004728a9(R)  
    //                               ?get_text_color@TButtonPanel@@QAEXFPAK0@Z                    XREF[1]:     fillPlayers:004a3b4a(c)  
    //                               TButtonPanel::get_text_color
    //                              Pnl_btn.cpp:574 (11)
    //         00472880     MOV        EAX,dword ptr [ESP + param_1]
    //         00472884     PUSH       ESI
    //         00472885     CMP        AX,0xffff
    //         00472889     JNZ        LAB_00472892
    //                              Pnl_btn.cpp:576 (7)
    //         0047288b     MOV        AX,word ptr [ECX + this->cur_state]
    //                               LAB_00472892                                                 XREF[1]:     00472889(j)  
    //                              Pnl_btn.cpp:577 (16)
    //         00472892     MOV        ESI,dword ptr [ESP + param_2]
    //         00472896     MOVSX      EAX,AX
    //         00472899     MOV        EDX,dword ptr [ECX + EAX*0x4 + this->text_colo
    //         004728a0     MOV        dword ptr [ESI],EDX
    //                              Pnl_btn.cpp:578 (11)
    //         004728a2     MOV        EAX,dword ptr [ECX + EAX*0x4 + this->text_colo
    //         004728a9     MOV        this,dword ptr [ESP + param_3]
    //                              Pnl_btn.cpp:579 (6)
    //         004728ad     POP        ESI
    //         004728ae     MOV        dword ptr [this->_padding_],EAX
    //         004728b0     RET        0xc
}

// Offset: 0x004728C0
void TDropDownButtonPanel::draw() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void __thiscall TButtonPanel::draw(void)                                              *
    //                              *********************************************************************************************************
    //                              void __thiscall draw(TButtonPanel * this)
    //              void              <VOID>         <RETURN>
    //              TButtonPanel *    ECX:4 (auto)   this
    //              tagSIZE           Stack[-0xc]:8  text_size                 XREF[1]:     00472948(W)  
    //              void *            Stack[-0x14]:4 old_font
    //              long              Stack[-0x18]:4 y_min
    //              long              Stack[-0x1c]:4 y_max
    //              long              Stack[-0x20]:4 x_min
    //              long              Stack[-0x24]:4 x_max
    //              long              Stack[-0x28]:4 calc_x
    //              long              Stack[-0x2c]:4 x
    //              long              Stack[-0x30]:4 y
    //              char *            Stack[-0x34]:4 text
    //                               ?draw@TButtonPanel@@UAEXXZ                                   XREF[3]:     draw:00519f52(c), 00570ff8(*), 
    //                               TButtonPanel::draw                                                        005712f0(*)  
    //                              Pnl_btn.cpp:586 (8)
    //         004728c0     SUB        ESP,0x30
    //         004728c3     PUSH       EBX
    //         004728c4     PUSH       EBP
    //         004728c5     PUSH       ESI
    //         004728c6     MOV        ESI,this
    //                              Pnl_btn.cpp:597 (32)
    //         004728c8     XOR        EBP,EBP
    //         004728ca     PUSH       EDI
    //         004728cb     MOV        this,dword ptr [ESI + 0x20]
    //         004728ce     CMP        this,EBP
    //         004728d0     JZ         LAB_004730e6
    //         004728d6     CMP        dword ptr [ESI + 0x70],EBP
    //         004728d9     JZ         LAB_004730e6
    //         004728df     CMP        dword ptr [ESI + 0x6c],EBP
    //         004728e2     JZ         LAB_004730e6
    //                              Pnl_btn.cpp:603 (9)
    //         004728e8     MOV        EAX,dword ptr [ESI + 0x140]
    //         004728ee     CMP        EAX,0x1
    //                              Pnl_btn.cpp:606 (6)
    //         004728f1     JZ         LAB_004730e6
    //                              Pnl_btn.cpp:610 (5)
    //         004728f7     CMP        EAX,0x5
    //         004728fa     JNZ        LAB_00472910
    //                              Pnl_btn.cpp:611 (18)
    //         004728fc     XOR        EAX,EAX
    //         004728fe     LEA        EDX,[ESI + 0x24]
    //         00472901     MOV        AL,byte ptr [ESI + 0xef]
    //         00472907     PUSH       EAX
    //         00472908     PUSH       EDX
    //         00472909     CALL       TDrawArea::Clear                                 void Clear(TDrawArea * this, tagRECT * param_
    //                              Pnl_btn.cpp:612 (9)
    //         0047290e     JMP        LAB_00472943
    //                               LAB_00472910                                                 XREF[1]:     004728fa(j)  
    //         00472910     MOV        this,dword ptr [ESI + 0x40]
    //         00472913     CMP        this,EBP
    //         00472915     JZ         LAB_00472943
    //                              Pnl_btn.cpp:622 (16)
    //         00472917     MOV        EAX,dword ptr [ESI + 0x2a0]
    //         0047291d     CMP        EAX,0x2
    //         00472920     JL         LAB_00472932
    //         00472922     CMP        EAX,0x4
    //         00472925     JG         LAB_00472932
    //                              Pnl_btn.cpp:623 (9)
    //         00472927     MOV        EAX,dword ptr [this->_padding_]
    //         00472929     LEA        EDX,[ESI + 0x24]
    //         0047292c     PUSH       EDX
    //         0047292d     CALL       dword ptr [EAX + 0x3c]
    //                              Pnl_btn.cpp:624 (10)
    //         00472930     JMP        LAB_00472943
    //                               LAB_00472932                                                 XREF[2]:     00472920(j), 00472925(j)  
    //         00472932     CMP        dword ptr [ECX + this->_padding_],EBP
    //         00472938     JNZ        LAB_00472943
    //                              Pnl_btn.cpp:625 (9)
    //         0047293a     MOV        EAX,dword ptr [this->_padding_]
    //         0047293c     LEA        EDX,[ESI + 0x24]
    //         0047293f     PUSH       EDX
    //         00472940     CALL       dword ptr [EAX + 0x34]
    //                               LAB_00472943                                                 XREF[4]:     0047290e(j), 00472915(j), 
    //                                                                                                         00472930(j), 00472938(j)  
    //                              Pnl_btn.cpp:629 (12)
    //         00472943     MOV        EDI,dword ptr [ESI]
    //         00472945     PUSH       EBP
    //         00472946     MOV        this,ESI
    //         00472948     MOV        dword ptr [ESP + text_size.cx],EDI
    //         0047294c     CALL       dword ptr [EDI + 0x28]
    //                              Pnl_btn.cpp:642 (25)
    //         0047294f     MOV        EAX,dword ptr [ESI + 0x140]
    //         00472955     CMP        EAX,0x2
    //         00472958     JZ         LAB_00472968
    //         0047295a     CMP        EAX,0x4
    //         0047295d     JZ         LAB_00472968
    //         0047295f     CMP        EAX,0x6
    //         00472962     JNZ        LAB_00472a74
    //                               LAB_00472968                                                 XREF[2]:     00472958(j), 0047295d(j)  
    //                              Pnl_btn.cpp:644 (23)
    //         00472968     MOV        this,dword ptr [ESI + 0x20]
    //         0047296b     PUSH       0x1
    //         0047296d     PUSH       s_pnl_btn::draw                                  = "pnl_btn::draw"
    //         00472972     CALL       TDrawArea::Lock                                  uchar * Lock(TDrawArea * this, char * param_1
    //         00472977     TEST       EAX,EAX
    //         00472979     JZ         LAB_00472a74
    //                              Pnl_btn.cpp:646 (22)
    //         0047297f     MOVSX      EAX,word ptr [ESI + 0x1f6]
    //         00472986     MOV        this,dword ptr [ESI + EAX*0x4 + 0x14c]
    //         0047298d     CMP        this,EBP
    //         0047298f     JZ         LAB_00472a67
    //                              Pnl_btn.cpp:648 (8)
    //         00472995     CMP        dword ptr [ESI + 0x184],EBP
    //         0047299b     JZ         LAB_00472a0d
    //                              Pnl_btn.cpp:650 (34)
    //         0047299d     MOVSX      EAX,word ptr [ESI + EAX*0x2 + 0x170]
    //         004729a5     PUSH       EAX
    //         004729a6     LEA        EDX,[ESP + 0x2c]
    //         004729aa     LEA        EAX,[ESP + 0x24]
    //         004729ae     PUSH       EDX=>DAT_fffffff8
    //         004729af     PUSH       EAX=>DAT_fffffff4
    //         004729b0     LEA        EDX,[ESP + 0x38]
    //         004729b4     LEA        EAX,[ESP + 0x30]
    //         004729b8     PUSH       EDX=>DAT_fffffff0
    //         004729b9     PUSH       EAX
    //         004729ba     CALL       TShape::shape_minmax                             uchar shape_minmax(TShape * this, long * para
    //                              Pnl_btn.cpp:653 (33)
    //         004729bf     MOV        EAX,dword ptr [ESP + 0x20]
    //         004729c3     MOV        this,dword ptr [ESP + 0x24]
    //         004729c7     SUB        EAX,this
    //         004729c9     INC        EAX
    //         004729ca     CDQ
    //         004729cb     SUB        EAX,EDX
    //         004729cd     MOV        EBX,EAX
    //         004729cf     MOV        EAX,dword ptr [ESI + 0x14]
    //         004729d2     CDQ
    //         004729d3     SUB        EAX,EDX
    //         004729d5     SAR        EBX,0x1
    //         004729d7     SAR        EAX,0x1
    //         004729d9     SUB        EAX,EBX
    //         004729db     SUB        EAX,this
    //         004729dd     MOVSX      this,AX
    //                              Pnl_btn.cpp:654 (45)
    //         004729e0     MOV        EAX,dword ptr [ESP + 0x28]
    //         004729e4     MOV        dword ptr [ESI + 0x188],this
    //         004729ea     MOV        this,dword ptr [ESP + 0x2c]
    //         004729ee     SUB        EAX,this
    //         004729f0     INC        EAX
    //         004729f1     CDQ
    //         004729f2     SUB        EAX,EDX
    //         004729f4     MOV        EBX,EAX
    //         004729f6     MOV        EAX,dword ptr [ESI + 0x18]
    //         004729f9     CDQ
    //         004729fa     SUB        EAX,EDX
    //         004729fc     SAR        EBX,0x1
    //         004729fe     SAR        EAX,0x1
    //         00472a00     SUB        EAX,EBX
    //         00472a02     SUB        EAX,this
    //         00472a04     MOVSX      EDX,AX
    //         00472a07     MOV        dword ptr [ESI + 0x18c],EDX
    //                               LAB_00472a0d                                                 XREF[1]:     0047299b(j)  
    //                              Pnl_btn.cpp:658 (20)
    //         00472a0d     MOV        this,dword ptr [ESI + 0x18c]
    //         00472a13     MOV        EDX,dword ptr [ESI + 0x10]
    //         00472a16     MOV        EAX,dword ptr [ESI + 0x188]
    //         00472a1c     MOV        EBX,dword ptr [ESI + 0xc]
    //         00472a1f     ADD        this,EDX
    //                              Pnl_btn.cpp:659 (32)
    //         00472a21     MOV        EDX,dword ptr [ESI + 0x194]
    //         00472a27     ADD        EAX,EBX
    //         00472a29     CMP        EDX,EBP
    //         00472a2b     JNZ        LAB_00472a39
    //         00472a2d     CMP        dword ptr [ESI + 0x1f8],EBP
    //         00472a33     JNZ        LAB_00472a41
    //         00472a35     CMP        EDX,EBP
    //         00472a37     JZ         LAB_00472a43
    //                               LAB_00472a39                                                 XREF[1]:     00472a2b(j)  
    //         00472a39     CMP        dword ptr [ESI + 0x1f8],EBP
    //         00472a3f     JNZ        LAB_00472a43
    //                               LAB_00472a41                                                 XREF[1]:     00472a33(j)  
    //                              Pnl_btn.cpp:661 (1)
    //         00472a41     INC        EAX
    //                              Pnl_btn.cpp:662 (1)
    //         00472a42     DEC        this
    //                               LAB_00472a43                                                 XREF[2]:     00472a37(j), 00472a3f(j)  
    //                              Pnl_btn.cpp:665 (36)
    //         00472a43     MOVSX      EDX,word ptr [ESI + 0x1f6]
    //         00472a4a     PUSH       EBP
    //         00472a4b     PUSH       EBP=>DAT_fffffff8
    //         00472a4c     MOVSX      EBX,word ptr [ESI + EDX*0x2 + 0x170]
    //         00472a54     PUSH       EBX=>DAT_fffffff4
    //         00472a55     PUSH       this=>DAT_fffffff0
    //         00472a56     MOV        this,dword ptr [ESI + EDX*0x4 + 0x14c]
    //         00472a5d     PUSH       EAX
    //         00472a5e     MOV        EAX,dword ptr [ESI + 0x20]
    //         00472a61     PUSH       EAX
    //         00472a62     CALL       TShape::shape_draw                               uchar shape_draw(TShape * this, TDrawArea * p
    //                               LAB_00472a67                                                 XREF[1]:     0047298f(j)  
    //                              Pnl_btn.cpp:667 (13)
    //         00472a67     MOV        this,dword ptr [ESI + 0x20]
    //         00472a6a     PUSH       s_pnl_btn::draw                                  = "pnl_btn::draw"
    //         00472a6f     CALL       TDrawArea::Unlock                                void Unlock(TDrawArea * this, char * param_1)
    //                               LAB_00472a74                                                 XREF[2]:     00472962(j), 00472979(j)  
    //                              Pnl_btn.cpp:671 (25)
    //         00472a74     MOV        EAX,dword ptr [ESI + 0x140]
    //         00472a7a     CMP        EAX,0x3
    //         00472a7d     JZ         LAB_00472a8d
    //         00472a7f     CMP        EAX,0x4
    //         00472a82     JZ         LAB_00472a8d
    //         00472a84     CMP        EAX,0x5
    //         00472a87     JNZ        LAB_00472de9
    //                               LAB_00472a8d                                                 XREF[2]:     00472a7d(j), 00472a82(j)  
    //                              Pnl_btn.cpp:673 (15)
    //         00472a8d     MOV        this,dword ptr [ESI + 0x20]
    //         00472a90     PUSH       s_pnl_btn::draw                                  = "pnl_btn::draw"
    //         00472a95     CALL       TDrawArea::GetDc                                 void * GetDc(TDrawArea * this, char * param_1)
    //         00472a9a     MOV        EBX,EAX
    //                              Pnl_btn.cpp:674 (8)
    //         00472a9c     CMP        EBX,EBP
    //         00472a9e     JZ         LAB_00472de9
    //                              Pnl_btn.cpp:676 (14)
    //         00472aa4     MOV        this,dword ptr [ESI + 0x88]
    //         00472aaa     PUSH       this
    //         00472aab     PUSH       EBX=>DAT_fffffff8
    //         00472aac     CALL       dword ptr [->GDI32.DLL::SelectClipRgn]           = 0048b2fc
    //                              Pnl_btn.cpp:677 (14)
    //         00472ab2     MOV        EDX,dword ptr [ESI + 0x1e8]
    //         00472ab8     PUSH       EDX
    //         00472ab9     PUSH       EBX=>DAT_fffffff8
    //         00472aba     CALL       dword ptr [->GDI32.DLL::SelectObject]            = 0048b192
    //                              Pnl_btn.cpp:678 (13)
    //         00472ac0     PUSH       0x1
    //         00472ac2     PUSH       EBX=>DAT_fffffff8
    //         00472ac3     MOV        dword ptr [ESP + 0x38],EAX
    //         00472ac7     CALL       dword ptr [->GDI32.DLL::SetBkMode]               = 0048b340
    //                              Pnl_btn.cpp:680 (11)
    //         00472acd     MOV        EAX,dword ptr [ESI + 0x1e0]
    //         00472ad3     CMP        EAX,-0x1
    //         00472ad6     JNZ        LAB_00472ae8
    //                              Pnl_btn.cpp:681 (14)
    //         00472ad8     MOV        EAX,dword ptr [ESI + 0x14]
    //         00472adb     CDQ
    //         00472adc     SUB        EAX,EDX
    //         00472ade     MOV        EBP,EAX
    //         00472ae0     SAR        EBP,0x1
    //         00472ae2     MOV        dword ptr [ESP + 0x1c],EBP
    //                              Pnl_btn.cpp:682 (2)
    //         00472ae6     JMP        LAB_00472aee
    //                               LAB_00472ae8                                                 XREF[1]:     00472ad6(j)  
    //                              Pnl_btn.cpp:683 (6)
    //         00472ae8     MOV        dword ptr [ESP + 0x1c],EAX
    //         00472aec     MOV        EBP,EAX
    //                               LAB_00472aee                                                 XREF[1]:     00472ae6(j)  
    //                              Pnl_btn.cpp:685 (11)
    //         00472aee     MOV        EAX,dword ptr [ESI + 0x1e4]
    //         00472af4     CMP        EAX,-0x1
    //         00472af7     JNZ        LAB_00472b01
    //                              Pnl_btn.cpp:686 (8)
    //         00472af9     MOV        EAX,dword ptr [ESI + 0x18]
    //         00472afc     CDQ
    //         00472afd     SUB        EAX,EDX
    //         00472aff     SAR        EAX,0x1
    //                               LAB_00472b01                                                 XREF[1]:     00472af7(j)  
    //                              Pnl_btn.cpp:688 (4)
    //         00472b01     MOV        dword ptr [ESP + 0x14],EAX
    //                              Pnl_btn.cpp:691 (18)
    //         00472b05     MOVSX      EAX,word ptr [ESI + 0x1f6]
    //         00472b0c     MOV        EDX,dword ptr [ESI + EAX*0x4 + 0x198]
    //         00472b13     TEST       EDX,EDX
    //         00472b15     JZ         LAB_00472b1d
    //                              Pnl_btn.cpp:692 (4)
    //         00472b17     MOV        dword ptr [ESP + 0x10],EDX
    //                              Pnl_btn.cpp:693 (2)
    //         00472b1b     JMP        LAB_00472b29
    //                               LAB_00472b1d                                                 XREF[1]:     00472b15(j)  
    //                              Pnl_btn.cpp:694 (12)
    //         00472b1d     MOV        this,dword ptr [ESI + 0x198]
    //         00472b23     MOV        dword ptr [ESP + 0x10],this
    //         00472b27     MOV        EDX,this
    //                               LAB_00472b29                                                 XREF[1]:     00472b1b(j)  
    //                              Pnl_btn.cpp:696 (8)
    //         00472b29     TEST       EDX,EDX
    //         00472b2b     JZ         LAB_00472dc3
    //                              Pnl_btn.cpp:698 (12)
    //         00472b31     MOV        EDI,EDX
    //         00472b33     OR         this,0xffffffff
    //         00472b36     XOR        EAX,EAX
    //         00472b38     SCASB.RE   ES:EDI
    //         00472b3a     NOT        this
    //         00472b3c     DEC        this
    //                              Pnl_btn.cpp:699 (21)
    //         00472b3d     MOVSX      EAX,this
    //         00472b40     LEA        this,[ESP + 0x38]
    //         00472b44     MOV        dword ptr [ESP + 0x18],EAX
    //         00472b48     PUSH       this
    //         00472b49     PUSH       EAX=>DAT_fffffff8
    //         00472b4a     PUSH       EDX=>DAT_fffffff4
    //         00472b4b     PUSH       EBX=>DAT_fffffff0
    //         00472b4c     CALL       dword ptr [->GDI32.DLL::GetTextExtentPoint32A]   = 0048b328
    //                              Pnl_btn.cpp:701 (18)
    //         00472b52     MOV        EAX,dword ptr [ESP + 0x38]
    //         00472b56     MOV        this,dword ptr [ESI + 0xc]
    //         00472b59     CDQ
    //         00472b5a     SUB        EAX,EDX
    //         00472b5c     MOV        EDI,EBP
    //         00472b5e     SAR        EAX,0x1
    //         00472b60     SUB        EDI,EAX
    //         00472b62     ADD        EDI,this
    //                              Pnl_btn.cpp:703 (18)
    //         00472b64     MOVSX      this,word ptr [ESI + 0x1f6]
    //         00472b6b     MOV        EAX,dword ptr [ESI + this->_padding_*0x4 + 0x1
    //         00472b72     TEST       EAX,EAX
    //         00472b74     JZ         LAB_00472b84
    //                              Pnl_btn.cpp:704 (12)
    //         00472b76     MOV        EBP,dword ptr [ESP + 0x14]
    //         00472b7a     MOV        EDX,dword ptr [ESI + 0x1f0]
    //         00472b80     SUB        EBP,EDX
    //                              Pnl_btn.cpp:705 (2)
    //         00472b82     JMP        LAB_00472b95
    //                               LAB_00472b84                                                 XREF[1]:     00472b74(j)  
    //                              Pnl_btn.cpp:706 (22)
    //         00472b84     MOV        EAX,dword ptr [ESI + 0x1f0]
    //         00472b8a     MOV        EBP,dword ptr [ESP + 0x14]
    //         00472b8e     CDQ
    //         00472b8f     SUB        EAX,EDX
    //         00472b91     SAR        EAX,0x1
    //         00472b93     SUB        EBP,EAX
    //                               LAB_00472b95                                                 XREF[1]:     00472b82(j)  
    //         00472b95     MOV        EAX,dword ptr [ESI + 0x10]
    //         00472b98     ADD        EBP,EAX
    //                              Pnl_btn.cpp:708 (34)
    //         00472b9a     MOV        EAX,dword ptr [ESI + 0x194]
    //         00472ba0     TEST       EAX,EAX
    //         00472ba2     JNZ        LAB_00472bb2
    //         00472ba4     MOV        EDX,dword ptr [ESI + 0x1f8]
    //         00472baa     TEST       EDX,EDX
    //         00472bac     JNZ        LAB_00472bbc
    //         00472bae     TEST       EAX,EAX
    //         00472bb0     JZ         LAB_00472bbe
    //                               LAB_00472bb2                                                 XREF[1]:     00472ba2(j)  
    //         00472bb2     MOV        EAX,dword ptr [ESI + 0x1f8]
    //         00472bb8     TEST       EAX,EAX
    //         00472bba     JNZ        LAB_00472bbe
    //                               LAB_00472bbc                                                 XREF[1]:     00472bac(j)  
    //                              Pnl_btn.cpp:710 (1)
    //         00472bbc     INC        EDI
    //                              Pnl_btn.cpp:711 (1)
    //         00472bbd     DEC        EBP
    //                               LAB_00472bbe                                                 XREF[2]:     00472bb0(j), 00472bba(j)  
    //                              Pnl_btn.cpp:714 (7)
    //         00472bbe     MOV        EAX,dword ptr [ESI + 0x78]
    //         00472bc1     TEST       EAX,EAX
    //         00472bc3     JZ         LAB_00472c1a
    //                              Pnl_btn.cpp:715 (15)
    //         00472bc5     MOV        EDX,dword ptr [ESI + this->_padding_*0x4 + 0x2
    //         00472bcc     PUSH       EDX
    //         00472bcd     PUSH       EBX=>DAT_fffffff8
    //         00472bce     CALL       dword ptr [->GDI32.DLL::SetTextColor]            = 0048b318
    //                              Pnl_btn.cpp:716 (25)
    //         00472bd4     MOV        EAX,dword ptr [ESP + 0x18]
    //         00472bd8     MOV        this,dword ptr [ESP + 0x10]
    //         00472bdc     PUSH       EAX
    //         00472bdd     LEA        EDX,[EBP + 0x1]
    //         00472be0     PUSH       this=>DAT_fffffff8
    //         00472be1     LEA        EAX,[EDI + -0x1]
    //         00472be4     PUSH       EDX=>DAT_fffffff4
    //         00472be5     PUSH       EAX=>DAT_fffffff0
    //         00472be6     PUSH       EBX
    //         00472be7     CALL       dword ptr [->GDI32.DLL::TextOutA]                = 0048b30c
    //                              Pnl_btn.cpp:717 (22)
    //         00472bed     MOVSX      this,word ptr [ESI + 0x1f6]
    //         00472bf4     MOV        EDX,dword ptr [ESI + this->_padding_*0x4 + 0x2
    //         00472bfb     PUSH       EDX
    //         00472bfc     PUSH       EBX=>DAT_fffffff8
    //         00472bfd     CALL       dword ptr [->GDI32.DLL::SetTextColor]            = 0048b318
    //                              Pnl_btn.cpp:718 (21)
    //         00472c03     MOV        EAX,dword ptr [ESP + 0x18]
    //         00472c07     MOV        this,dword ptr [ESP + 0x10]
    //         00472c0b     PUSH       EAX
    //         00472c0c     PUSH       this=>DAT_fffffff8
    //         00472c0d     PUSH       EBP=>DAT_fffffff4
    //         00472c0e     MOV        EBP,dword ptr [->GDI32.DLL::TextOutA]            = 0048b30c
    //         00472c14     PUSH       EDI=>DAT_fffffff0
    //         00472c15     PUSH       EBX
    //         00472c16     CALL       EBP=>GDI32.DLL::TextOutA
    //                              Pnl_btn.cpp:720 (2)
    //         00472c18     JMP        LAB_00472c71
    //                               LAB_00472c1a                                                 XREF[1]:     00472bc3(j)  
    //                              Pnl_btn.cpp:721 (15)
    //         00472c1a     MOV        EDX,dword ptr [ESI + this->_padding_*0x4 + 0x2
    //         00472c21     PUSH       EDX
    //         00472c22     PUSH       EBX=>DAT_fffffff8
    //         00472c23     CALL       dword ptr [->GDI32.DLL::SetTextColor]            = 0048b318
    //                              Pnl_btn.cpp:722 (25)
    //         00472c29     MOV        EAX,dword ptr [ESP + 0x18]
    //         00472c2d     MOV        this,dword ptr [ESP + 0x10]
    //         00472c31     PUSH       EAX
    //         00472c32     LEA        EDX,[EBP + 0x1]
    //         00472c35     PUSH       this=>DAT_fffffff8
    //         00472c36     LEA        EAX,[EDI + -0x1]
    //         00472c39     PUSH       EDX=>DAT_fffffff4
    //         00472c3a     PUSH       EAX=>DAT_fffffff0
    //         00472c3b     PUSH       EBX
    //         00472c3c     CALL       dword ptr [->GDI32.DLL::TextOutA]                = 0048b30c
    //                              Pnl_btn.cpp:723 (22)
    //         00472c42     MOVSX      this,word ptr [ESI + 0x1f6]
    //         00472c49     MOV        EDX,dword ptr [ESI + this->_padding_*0x4 + 0x2
    //         00472c50     PUSH       EDX
    //         00472c51     PUSH       EBX=>DAT_fffffff8
    //         00472c52     CALL       dword ptr [->GDI32.DLL::SetTextColor]            = 0048b318
    //                              Pnl_btn.cpp:724 (25)
    //         00472c58     MOV        EAX,dword ptr [ESP + 0x18]
    //         00472c5c     MOV        this,dword ptr [ESP + 0x10]
    //         00472c60     PUSH       EAX
    //         00472c61     PUSH       this=>DAT_fffffff8
    //         00472c62     PUSH       EBP=>DAT_fffffff4
    //         00472c63     PUSH       EDI=>DAT_fffffff0
    //         00472c64     PUSH       EBX
    //         00472c65     CALL       dword ptr [->GDI32.DLL::TextOutA]                = 0048b30c
    //         00472c6b     MOV        EBP,dword ptr [->GDI32.DLL::TextOutA]            = 0048b30c
    //                               LAB_00472c71                                                 XREF[1]:     00472c18(j)  
    //                              Pnl_btn.cpp:728 (18)
    //         00472c71     MOVSX      EDX,word ptr [ESI + 0x1f6]
    //         00472c78     MOV        EDX,dword ptr [ESI + EDX*0x4 + 0x1bc]
    //         00472c7f     TEST       EDX,EDX
    //         00472c81     JZ         LAB_00472c89
    //                              Pnl_btn.cpp:729 (4)
    //         00472c83     MOV        dword ptr [ESP + 0x10],EDX
    //                              Pnl_btn.cpp:730 (2)
    //         00472c87     JMP        LAB_00472c95
    //                               LAB_00472c89                                                 XREF[1]:     00472c81(j)  
    //                              Pnl_btn.cpp:731 (12)
    //         00472c89     MOV        EAX,dword ptr [ESI + 0x1bc]
    //         00472c8f     MOV        dword ptr [ESP + 0x10],EAX
    //         00472c93     MOV        EDX,EAX
    //                               LAB_00472c95                                                 XREF[1]:     00472c87(j)  
    //                              Pnl_btn.cpp:733 (8)
    //         00472c95     TEST       EDX,EDX
    //         00472c97     JZ         LAB_00472dc3
    //                              Pnl_btn.cpp:735 (12)
    //         00472c9d     MOV        EDI,EDX
    //         00472c9f     OR         this,0xffffffff
    //         00472ca2     XOR        EAX,EAX
    //         00472ca4     SCASB.RE   ES:EDI
    //         00472ca6     NOT        this
    //         00472ca8     DEC        this
    //                              Pnl_btn.cpp:736 (17)
    //         00472ca9     MOVSX      EDI,this
    //         00472cac     LEA        this,[ESP + 0x38]
    //         00472cb0     PUSH       this
    //         00472cb1     PUSH       EDI=>DAT_fffffff8
    //         00472cb2     PUSH       EDX=>DAT_fffffff4
    //         00472cb3     PUSH       EBX=>DAT_fffffff0
    //         00472cb4     CALL       dword ptr [->GDI32.DLL::GetTextExtentPoint32A]   = 0048b328
    //                              Pnl_btn.cpp:738 (20)
    //         00472cba     MOV        EAX,dword ptr [ESP + 0x38]
    //         00472cbe     MOV        this,dword ptr [ESI + 0xc]
    //         00472cc1     CDQ
    //         00472cc2     SUB        EAX,EDX
    //         00472cc4     MOV        EDX,EAX
    //         00472cc6     MOV        EAX,dword ptr [ESP + 0x1c]
    //         00472cca     SAR        EDX,0x1
    //         00472ccc     SUB        EAX,EDX
    //                              Pnl_btn.cpp:739 (19)
    //         00472cce     MOV        EDX,dword ptr [ESI + 0x10]
    //         00472cd1     ADD        EAX,this
    //         00472cd3     MOV        dword ptr [ESP + 0x18],EAX
    //         00472cd7     MOV        EAX,dword ptr [ESP + 0x14]
    //         00472cdb     ADD        EAX,EDX
    //         00472cdd     MOV        dword ptr [ESP + 0x14],EAX
    //                              Pnl_btn.cpp:741 (34)
    //         00472ce1     MOV        EAX,dword ptr [ESI + 0x194]
    //         00472ce7     TEST       EAX,EAX
    //         00472ce9     JNZ        LAB_00472cf9
    //         00472ceb     MOV        this,dword ptr [ESI + 0x1f8]
    //         00472cf1     TEST       this,this
    //         00472cf3     JNZ        LAB_00472d03
    //         00472cf5     TEST       EAX,EAX
    //         00472cf7     JZ         LAB_00472d15
    //                               LAB_00472cf9                                                 XREF[1]:     00472ce9(j)  
    //         00472cf9     MOV        EAX,dword ptr [ESI + 0x1f8]
    //         00472cff     TEST       EAX,EAX
    //         00472d01     JNZ        LAB_00472d15
    //                               LAB_00472d03                                                 XREF[1]:     00472cf3(j)  
    //                              Pnl_btn.cpp:743 (4)
    //         00472d03     MOV        this,dword ptr [ESP + 0x18]
    //                              Pnl_btn.cpp:744 (14)
    //         00472d07     MOV        EAX,dword ptr [ESP + 0x14]
    //         00472d0b     INC        this
    //         00472d0c     DEC        EAX
    //         00472d0d     MOV        dword ptr [ESP + 0x18],this
    //         00472d11     MOV        dword ptr [ESP + 0x14],EAX
    //                               LAB_00472d15                                                 XREF[2]:     00472cf7(j), 00472d01(j)  
    //                              Pnl_btn.cpp:747 (7)
    //         00472d15     MOV        EAX,dword ptr [ESI + 0x78]
    //         00472d18     TEST       EAX,EAX
    //         00472d1a     JZ         LAB_00472d6f
    //                              Pnl_btn.cpp:748 (22)
    //         00472d1c     MOVSX      EAX,word ptr [ESI + 0x1f6]
    //         00472d23     MOV        this,dword ptr [ESI + EAX*0x4 + 0x274]
    //         00472d2a     PUSH       this
    //         00472d2b     PUSH       EBX=>DAT_fffffff8
    //         00472d2c     CALL       dword ptr [->GDI32.DLL::SetTextColor]            = 0048b318
    //                              Pnl_btn.cpp:749 (21)
    //         00472d32     MOV        EAX,dword ptr [ESP + 0x14]
    //         00472d36     MOV        EDX,dword ptr [ESP + 0x10]
    //         00472d3a     MOV        this,dword ptr [ESP + 0x18]
    //         00472d3e     PUSH       EDI
    //         00472d3f     INC        EAX
    //         00472d40     PUSH       EDX=>DAT_fffffff8
    //         00472d41     DEC        this
    //         00472d42     PUSH       EAX=>DAT_fffffff4
    //         00472d43     PUSH       this=>DAT_fffffff0
    //         00472d44     PUSH       EBX
    //         00472d45     CALL       EBP=>GDI32.DLL::TextOutA
    //                              Pnl_btn.cpp:750 (22)
    //         00472d47     MOVSX      EDX,word ptr [ESI + 0x1f6]
    //         00472d4e     MOV        EAX,dword ptr [ESI + EDX*0x4 + 0x250]
    //         00472d55     PUSH       EAX
    //         00472d56     PUSH       EBX=>DAT_fffffff8
    //         00472d57     CALL       dword ptr [->GDI32.DLL::SetTextColor]            = 0048b318
    //                              Pnl_btn.cpp:751 (16)
    //         00472d5d     MOV        this,dword ptr [ESP + 0x10]
    //         00472d61     MOV        EDX,dword ptr [ESP + 0x14]
    //         00472d65     MOV        EAX,dword ptr [ESP + 0x18]
    //         00472d69     PUSH       EDI
    //         00472d6a     PUSH       this=>DAT_fffffff8
    //         00472d6b     PUSH       EDX=>DAT_fffffff4
    //         00472d6c     PUSH       EAX=>DAT_fffffff0
    //                              Pnl_btn.cpp:753 (2)
    //         00472d6d     JMP        LAB_00472dc0
    //                               LAB_00472d6f                                                 XREF[1]:     00472d1a(j)  
    //                              Pnl_btn.cpp:754 (22)
    //         00472d6f     MOVSX      this,word ptr [ESI + 0x1f6]
    //         00472d76     MOV        EDX,dword ptr [ESI + this->_padding_*0x4 + 0x2
    //         00472d7d     PUSH       EDX
    //         00472d7e     PUSH       EBX=>DAT_fffffff8
    //         00472d7f     CALL       dword ptr [->GDI32.DLL::SetTextColor]            = 0048b318
    //                              Pnl_btn.cpp:755 (21)
    //         00472d85     MOV        this,dword ptr [ESP + 0x14]
    //         00472d89     MOV        EAX,dword ptr [ESP + 0x10]
    //         00472d8d     MOV        EDX,dword ptr [ESP + 0x18]
    //         00472d91     PUSH       EDI
    //         00472d92     INC        this
    //         00472d93     PUSH       EAX=>DAT_fffffff8
    //         00472d94     DEC        EDX
    //         00472d95     PUSH       this=>DAT_fffffff4
    //         00472d96     PUSH       EDX=>DAT_fffffff0
    //         00472d97     PUSH       EBX
    //         00472d98     CALL       EBP=>GDI32.DLL::TextOutA
    //                              Pnl_btn.cpp:756 (22)
    //         00472d9a     MOVSX      EAX,word ptr [ESI + 0x1f6]
    //         00472da1     MOV        this,dword ptr [ESI + EAX*0x4 + 0x208]
    //         00472da8     PUSH       this
    //         00472da9     PUSH       EBX=>DAT_fffffff8
    //         00472daa     CALL       dword ptr [->GDI32.DLL::SetTextColor]            = 0048b318
    //                              Pnl_btn.cpp:757 (19)
    //         00472db0     MOV        EDX,dword ptr [ESP + 0x10]
    //         00472db4     MOV        EAX,dword ptr [ESP + 0x14]
    //         00472db8     MOV        this,dword ptr [ESP + 0x18]
    //         00472dbc     PUSH       EDI
    //         00472dbd     PUSH       EDX=>DAT_fffffff8
    //         00472dbe     PUSH       EAX=>DAT_fffffff4
    //         00472dbf     PUSH       this=>DAT_fffffff0
    //                               LAB_00472dc0                                                 XREF[1]:     00472d6d(j)  
    //         00472dc0     PUSH       EBX
    //         00472dc1     CALL       EBP=>GDI32.DLL::TextOutA
    //                               LAB_00472dc3                                                 XREF[2]:     00472b2b(j), 00472c97(j)  
    //                              Pnl_btn.cpp:764 (12)
    //         00472dc3     MOV        EDX,dword ptr [ESP + 0x30]
    //         00472dc7     PUSH       EDX
    //         00472dc8     PUSH       EBX=>DAT_fffffff8
    //         00472dc9     CALL       dword ptr [->GDI32.DLL::SelectObject]            = 0048b192
    //                              Pnl_btn.cpp:765 (9)
    //         00472dcf     PUSH       0x0
    //         00472dd1     PUSH       EBX=>DAT_fffffff8
    //         00472dd2     CALL       dword ptr [->GDI32.DLL::SelectClipRgn]           = 0048b2fc
    //                              Pnl_btn.cpp:766 (17)
    //         00472dd8     MOV        this,dword ptr [ESI + 0x20]
    //         00472ddb     PUSH       s_pnl_btn::draw                                  = "pnl_btn::draw"
    //         00472de0     CALL       TDrawArea::ReleaseDc                             void ReleaseDc(TDrawArea * this, char * param
    //         00472de5     MOV        EDI,dword ptr [ESP + 0x34]
    //                               LAB_00472de9                                                 XREF[2]:     00472a87(j), 00472a9e(j)  
    //                              Pnl_btn.cpp:770 (30)
    //         00472de9     MOV        EAX,dword ptr [ESI + 0x140]
    //         00472def     CMP        EAX,0x3
    //         00472df2     JZ         LAB_00472e07
    //         00472df4     CMP        EAX,0x4
    //         00472df7     JZ         LAB_00472e07
    //         00472df9     CMP        EAX,0x5
    //         00472dfc     JZ         LAB_00472e07
    //         00472dfe     CMP        EAX,0x6
    //         00472e01     JNZ        LAB_004730d9
    //                               LAB_00472e07                                                 XREF[3]:     00472df2(j), 00472df7(j), 
    //                                                                                                         00472dfc(j)  
    //                              Pnl_btn.cpp:772 (23)
    //         00472e07     MOV        this,dword ptr [ESI + 0x20]
    //         00472e0a     PUSH       0x1
    //         00472e0c     PUSH       s_pnl_btn::draw2                                 = "pnl_btn::draw2"
    //         00472e11     CALL       TDrawArea::Lock                                  uchar * Lock(TDrawArea * this, char * param_1
    //         00472e16     TEST       EAX,EAX
    //         00472e18     JZ         LAB_004730d9
    //                              Pnl_btn.cpp:786 (10)
    //         00472e1e     MOV        EAX,dword ptr [ESI + 0x2b0]
    //         00472e24     TEST       EAX,EAX
    //         00472e26     JZ         LAB_00472e7d
    //                              Pnl_btn.cpp:788 (39)
    //         00472e28     MOV        DL,byte ptr [ESI + 0x2a9]
    //         00472e2e     MOV        EAX,dword ptr [ESI + 0x10]
    //         00472e31     MOV        this,dword ptr [ESI + 0xc]
    //         00472e34     PUSH       EDX
    //         00472e35     MOV        EDX,dword ptr [ESI + 0x18]
    //         00472e38     LEA        EDX,[EDX + EAX*0x1 + -0x1]
    //         00472e3c     PUSH       EDX=>DAT_fffffff8
    //         00472e3d     MOV        EDX,dword ptr [ESI + 0x14]
    //         00472e40     LEA        EDX,[EDX + this->_padding_*0x1 + -0x1]
    //         00472e44     PUSH       EDX=>DAT_fffffff4
    //         00472e45     PUSH       EAX=>DAT_fffffff0
    //         00472e46     PUSH       this
    //         00472e47     MOV        this,dword ptr [ESI + 0x20]
    //         00472e4a     CALL       TDrawArea::DrawRect                              void DrawRect(TDrawArea * this, long param_1,
    //                              Pnl_btn.cpp:789 (41)
    //         00472e4f     MOV        DL,byte ptr [ESI + 0x2a4]
    //         00472e55     MOV        EAX,dword ptr [ESI + 0x10]
    //         00472e58     MOV        this,dword ptr [ESI + 0xc]
    //         00472e5b     PUSH       EDX
    //         00472e5c     MOV        EDX,dword ptr [ESI + 0x18]
    //         00472e5f     LEA        EDX,[EDX + EAX*0x1 + -0x2]
    //         00472e63     INC        EAX
    //         00472e64     PUSH       EDX=>DAT_fffffff8
    //         00472e65     MOV        EDX,dword ptr [ESI + 0x14]
    //         00472e68     LEA        EDX,[EDX + this->_padding_*0x1 + -0x2]
    //         00472e6c     INC        this
    //         00472e6d     PUSH       EDX=>DAT_fffffff4
    //         00472e6e     PUSH       EAX=>DAT_fffffff0
    //         00472e6f     PUSH       this
    //         00472e70     MOV        this,dword ptr [ESI + 0x20]
    //         00472e73     CALL       TDrawArea::DrawRect                              void DrawRect(TDrawArea * this, long param_1,
    //                              Pnl_btn.cpp:791 (47)
    //         00472e78     JMP        switchD_00472eb7::default
    //                               LAB_00472e7d                                                 XREF[1]:     00472e26(j)  
    //         00472e7d     MOV        EAX,dword ptr [ESI + 0x194]
    //         00472e83     TEST       EAX,EAX
    //         00472e85     JNZ        LAB_00472e99
    //         00472e87     MOV        this,dword ptr [ESI + 0x1f8]
    //         00472e8d     TEST       this,this
    //         00472e8f     JNZ        LAB_00472ea7
    //         00472e91     TEST       EAX,EAX
    //         00472e93     JZ         LAB_00472f92
    //                               LAB_00472e99                                                 XREF[1]:     00472e85(j)  
    //         00472e99     MOV        EAX,dword ptr [ESI + 0x1f8]
    //         00472e9f     TEST       EAX,EAX
    //         00472ea1     JNZ        LAB_00472f92
    //                               LAB_00472ea7                                                 XREF[1]:     00472e8f(j)  
    //                              Pnl_btn.cpp:793 (23)
    //         00472ea7     MOV        EAX,dword ptr [ESI + 0x2a0]
    //         00472ead     DEC        EAX
    //         00472eae     CMP        EAX,0x3
    //         00472eb1     JA         switchD_00472eb7::default
    //                               switchD_00472eb7::switchD
    //         00472eb7     JMP        dword ptr [EAX*0x4 + switchD_00472eb7::switchd   = 00472ebe
    //                               switchD_00472eb7::caseD_1                                    XREF[2]:     00472eb7(j), 004730f4(*)  
    //                              Pnl_btn.cpp:796 (39)
    //         00472ebe     MOV        EAX,dword ptr [ESI + 0x10]
    //         00472ec1     MOV        EDX,dword ptr [ESI + 0x18]
    //         00472ec4     MOV        this,dword ptr [ESI + 0xc]
    //         00472ec7     PUSH       0xff
    //         00472ecc     LEA        EDX,[EDX + EAX*0x1 + -0x2]
    //         00472ed0     INC        EAX
    //         00472ed1     PUSH       EDX=>DAT_fffffff8
    //         00472ed2     MOV        EDX,dword ptr [ESI + 0x14]
    //         00472ed5     LEA        EDX,[EDX + this->_padding_*0x1 + -0x2]
    //         00472ed9     INC        this
    //         00472eda     PUSH       EDX=>DAT_fffffff4
    //         00472edb     PUSH       EAX=>DAT_fffffff0
    //         00472edc     PUSH       this
    //         00472edd     MOV        this,dword ptr [ESI + 0x20]
    //         00472ee0     CALL       TDrawArea::DrawRect                              void DrawRect(TDrawArea * this, long param_1,
    //                              Pnl_btn.cpp:797 (5)
    //         00472ee5     JMP        switchD_00472eb7::default
    //                               switchD_00472eb7::caseD_2                                    XREF[2]:     00472eb7(j), 004730f8(*)  
    //                              Pnl_btn.cpp:800 (19)
    //         00472eea     MOV        DL,byte ptr [ESI + 0x2a4]
    //         00472ef0     MOV        EAX,dword ptr [ESI + 0x10]
    //         00472ef3     MOV        this,dword ptr [ESI + 0xc]
    //         00472ef6     PUSH       EDX
    //         00472ef7     MOV        DL,byte ptr [ESI + 0x2a9]
    //                              Pnl_btn.cpp:801 (5)
    //         00472efd     JMP        LAB_00473024
    //                               switchD_00472eb7::caseD_3                                    XREF[2]:     00472eb7(j), 004730fc(*)  
    //                              Pnl_btn.cpp:804 (60)
    //         00472f02     MOV        DL,byte ptr [ESI + 0x2a4]
    //         00472f08     MOV        EAX,dword ptr [ESI + 0x10]
    //         00472f0b     PUSH       EDX
    //         00472f0c     MOV        DL,byte ptr [ESI + 0x2a5]
    //         00472f12     PUSH       EDX=>DAT_fffffff8
    //         00472f13     MOV        DL,byte ptr [ESI + 0x2a8]
    //         00472f19     PUSH       EDX=>DAT_fffffff4
    //         00472f1a     MOV        DL,byte ptr [ESI + 0x2a9]
    //         00472f20     MOV        this,dword ptr [ESI + 0xc]
    //         00472f23     PUSH       EDX=>DAT_fffffff0
    //         00472f24     MOV        EDX,dword ptr [ESI + 0x18]
    //         00472f27     LEA        EDX,[EDX + EAX*0x1 + -0x1]
    //         00472f2b     PUSH       EDX
    //         00472f2c     MOV        EDX,dword ptr [ESI + 0x14]
    //         00472f2f     LEA        EDX,[EDX + this->_padding_*0x1 + -0x1]
    //         00472f33     PUSH       EDX
    //         00472f34     PUSH       EAX
    //         00472f35     PUSH       this
    //         00472f36     MOV        this,dword ptr [ESI + 0x20]
    //         00472f39     CALL       TDrawArea::DrawBevel21                           void DrawBevel21(TDrawArea * this, long param
    //                              Pnl_btn.cpp:805 (5)
    //         00472f3e     JMP        switchD_00472eb7::default
    //                               switchD_00472eb7::caseD_4                                    XREF[2]:     00472eb7(j), 00473100(*)  
    //                              Pnl_btn.cpp:808 (74)
    //         00472f43     MOV        DL,byte ptr [ESI + 0x2a4]
    //         00472f49     MOV        EAX,dword ptr [ESI + 0x10]
    //         00472f4c     PUSH       EDX
    //         00472f4d     MOV        DL,byte ptr [ESI + 0x2a5]
    //         00472f53     PUSH       EDX=>DAT_fffffff8
    //         00472f54     MOV        DL,byte ptr [ESI + 0x2a6]
    //         00472f5a     PUSH       EDX=>DAT_fffffff4
    //         00472f5b     MOV        DL,byte ptr [ESI + 0x2a7]
    //         00472f61     PUSH       EDX=>DAT_fffffff0
    //         00472f62     MOV        DL,byte ptr [ESI + 0x2a8]
    //         00472f68     PUSH       EDX
    //         00472f69     MOV        DL,byte ptr [ESI + 0x2a9]
    //         00472f6f     MOV        this,dword ptr [ESI + 0xc]
    //         00472f72     PUSH       EDX
    //         00472f73     MOV        EDX,dword ptr [ESI + 0x18]
    //         00472f76     LEA        EDX,[EDX + EAX*0x1 + -0x1]
    //         00472f7a     PUSH       EDX
    //         00472f7b     MOV        EDX,dword ptr [ESI + 0x14]
    //         00472f7e     LEA        EDX,[EDX + this->_padding_*0x1 + -0x1]
    //         00472f82     PUSH       EDX
    //         00472f83     PUSH       EAX
    //         00472f84     PUSH       this
    //         00472f85     MOV        this,dword ptr [ESI + 0x20]
    //         00472f88     CALL       TDrawArea::DrawBevel32                           void DrawBevel32(TDrawArea * this, long param
    //                              Pnl_btn.cpp:812 (5)
    //         00472f8d     JMP        switchD_00472eb7::default
    //                               LAB_00472f92                                                 XREF[2]:     00472e93(j), 00472ea1(j)  
    //                              Pnl_btn.cpp:814 (23)
    //         00472f92     MOV        EAX,dword ptr [ESI + 0x2a0]
    //         00472f98     DEC        EAX
    //         00472f99     CMP        EAX,0x3
    //         00472f9c     JA         switchD_00472eb7::default
    //                               switchD_00472fa2::switchD
    //         00472fa2     JMP        dword ptr [EAX*0x4 + switchD_00472fa2::switchd   = 00472fa9
    //                               switchD_00472fa2::caseD_1                                    XREF[2]:     00472fa2(j), 00473104(*)  
    //                              Pnl_btn.cpp:817 (31)
    //         00472fa9     MOV        EAX,dword ptr [ESI + 0x18]
    //         00472fac     MOV        this,dword ptr [ESI + 0x10]
    //         00472faf     MOV        EDX,dword ptr [ESI + 0x14]
    //         00472fb2     DEC        EAX
    //         00472fb3     PUSH       0x0
    //         00472fb5     PUSH       EAX=>DAT_fffffff8
    //         00472fb6     MOV        EAX,dword ptr [ESI + 0xc]
    //         00472fb9     INC        this
    //         00472fba     PUSH       this=>DAT_fffffff4
    //         00472fbb     LEA        this,[EDX + EAX*0x1 + -0x1]
    //         00472fbf     PUSH       this=>DAT_fffffff0
    //         00472fc0     MOV        this,dword ptr [ESI + 0x20]
    //         00472fc3     CALL       TDrawArea::DrawVertLine                          void DrawVertLine(TDrawArea * this, long para
    //                              Pnl_btn.cpp:818 (31)
    //         00472fc8     MOV        EDX,dword ptr [ESI + 0x14]
    //         00472fcb     MOV        EAX,dword ptr [ESI + 0x18]
    //         00472fce     MOV        this,dword ptr [ESI + 0x10]
    //         00472fd1     DEC        EDX
    //         00472fd2     PUSH       0x0
    //         00472fd4     PUSH       EDX=>DAT_fffffff8
    //         00472fd5     LEA        EDX,[EAX + this->_padding_*0x1 + -0x1]
    //         00472fd9     MOV        EAX,dword ptr [ESI + 0xc]
    //         00472fdc     MOV        this,dword ptr [ESI + 0x20]
    //         00472fdf     INC        EAX
    //         00472fe0     PUSH       EDX=>DAT_fffffff4
    //         00472fe1     PUSH       EAX=>DAT_fffffff0
    //         00472fe2     CALL       TDrawArea::DrawHorzLine                          void DrawHorzLine(TDrawArea * this, long para
    //                              Pnl_btn.cpp:819 (37)
    //         00472fe7     MOV        EAX,dword ptr [ESI + 0x10]
    //         00472fea     MOV        EDX,dword ptr [ESI + 0x18]
    //         00472fed     MOV        this,dword ptr [ESI + 0xc]
    //         00472ff0     PUSH       0xff
    //         00472ff5     LEA        EDX,[EDX + EAX*0x1 + -0x2]
    //         00472ff9     PUSH       EDX=>DAT_fffffff8
    //         00472ffa     MOV        EDX,dword ptr [ESI + 0x14]
    //         00472ffd     LEA        EDX,[EDX + this->_padding_*0x1 + -0x2]
    //         00473001     PUSH       EDX=>DAT_fffffff4
    //         00473002     PUSH       EAX=>DAT_fffffff0
    //         00473003     PUSH       this
    //         00473004     MOV        this,dword ptr [ESI + 0x20]
    //         00473007     CALL       TDrawArea::DrawRect                              void DrawRect(TDrawArea * this, long param_1,
    //                              Pnl_btn.cpp:820 (5)
    //         0047300c     JMP        switchD_00472eb7::default
    //                               switchD_00472fa2::caseD_2                                    XREF[2]:     00472fa2(j), 00473108(*)  
    //                              Pnl_btn.cpp:823 (46)
    //         00473011     MOV        DL,byte ptr [ESI + 0x2a9]
    //         00473017     MOV        EAX,dword ptr [ESI + 0x10]
    //         0047301a     MOV        this,dword ptr [ESI + 0xc]
    //         0047301d     PUSH       EDX
    //         0047301e     MOV        DL,byte ptr [ESI + 0x2a4]
    //                               LAB_00473024                                                 XREF[1]:     00472efd(j)  
    //         00473024     PUSH       EDX=>DAT_fffffff8
    //         00473025     MOV        EDX,dword ptr [ESI + 0x18]
    //         00473028     LEA        EDX,[EDX + EAX*0x1 + -0x1]
    //         0047302c     PUSH       EDX=>DAT_fffffff4
    //         0047302d     MOV        EDX,dword ptr [ESI + 0x14]
    //         00473030     LEA        EDX,[EDX + this->_padding_*0x1 + -0x1]
    //         00473034     PUSH       EDX=>DAT_fffffff0
    //         00473035     PUSH       EAX
    //         00473036     PUSH       this
    //         00473037     MOV        this,dword ptr [ESI + 0x20]
    //         0047303a     CALL       TDrawArea::DrawBevel                             void DrawBevel(TDrawArea * this, long param_1
    //                              Pnl_btn.cpp:824 (5)
    //         0047303f     JMP        switchD_00472eb7::default
    //                               switchD_00472fa2::caseD_3                                    XREF[2]:     00472fa2(j), 0047310c(*)  
    //                              Pnl_btn.cpp:827 (60)
    //         00473044     MOV        DL,byte ptr [ESI + 0x2a9]
    //         0047304a     MOV        EAX,dword ptr [ESI + 0x10]
    //         0047304d     PUSH       EDX
    //         0047304e     MOV        DL,byte ptr [ESI + 0x2a8]
    //         00473054     PUSH       EDX=>DAT_fffffff8
    //         00473055     MOV        DL,byte ptr [ESI + 0x2a5]
    //         0047305b     PUSH       EDX=>DAT_fffffff4
    //         0047305c     MOV        DL,byte ptr [ESI + 0x2a4]
    //         00473062     MOV        this,dword ptr [ESI + 0xc]
    //         00473065     PUSH       EDX=>DAT_fffffff0
    //         00473066     MOV        EDX,dword ptr [ESI + 0x18]
    //         00473069     LEA        EDX,[EDX + EAX*0x1 + -0x1]
    //         0047306d     PUSH       EDX
    //         0047306e     MOV        EDX,dword ptr [ESI + 0x14]
    //         00473071     LEA        EDX,[EDX + this->_padding_*0x1 + -0x1]
    //         00473075     PUSH       EDX
    //         00473076     PUSH       EAX
    //         00473077     PUSH       this
    //         00473078     MOV        this,dword ptr [ESI + 0x20]
    //         0047307b     CALL       TDrawArea::DrawBevel2                            void DrawBevel2(TDrawArea * this, long param_
    //                              Pnl_btn.cpp:828 (2)
    //         00473080     JMP        switchD_00472eb7::default
    //                               switchD_00472fa2::caseD_4                                    XREF[2]:     00472fa2(j), 00473110(*)  
    //                              Pnl_btn.cpp:831 (74)
    //         00473082     MOV        DL,byte ptr [ESI + 0x2a9]
    //         00473088     MOV        EAX,dword ptr [ESI + 0x10]
    //         0047308b     PUSH       EDX
    //         0047308c     MOV        DL,byte ptr [ESI + 0x2a8]
    //         00473092     PUSH       EDX=>DAT_fffffff8
    //         00473093     MOV        DL,byte ptr [ESI + 0x2a7]
    //         00473099     PUSH       EDX=>DAT_fffffff4
    //         0047309a     MOV        DL,byte ptr [ESI + 0x2a6]
    //         004730a0     PUSH       EDX=>DAT_fffffff0
    //         004730a1     MOV        DL,byte ptr [ESI + 0x2a5]
    //         004730a7     PUSH       EDX
    //         004730a8     MOV        DL,byte ptr [ESI + 0x2a4]
    //         004730ae     MOV        this,dword ptr [ESI + 0xc]
    //         004730b1     PUSH       EDX
    //         004730b2     MOV        EDX,dword ptr [ESI + 0x18]
    //         004730b5     LEA        EDX,[EDX + EAX*0x1 + -0x1]
    //         004730b9     PUSH       EDX
    //         004730ba     MOV        EDX,dword ptr [ESI + 0x14]
    //         004730bd     LEA        EDX,[EDX + this->_padding_*0x1 + -0x1]
    //         004730c1     PUSH       EDX
    //         004730c2     PUSH       EAX
    //         004730c3     PUSH       this
    //         004730c4     MOV        this,dword ptr [ESI + 0x20]
    //         004730c7     CALL       TDrawArea::DrawBevel3                            void DrawBevel3(TDrawArea * this, long param_
    //                               switchD_00472fa2::default                                    XREF[9]:     00472e78(j), 00472eb1(j), 
    //                               switchD_00472eb7::default                                                 00472ee5(j), 00472f3e(j), 
    //                                                                                                         00472f8d(j), 00472f9c(j), 
    //                                                                                                         0047300c(j), 0047303f(j), 
    //                                                                                                         00473080(j)  
    //                              Pnl_btn.cpp:835 (13)
    //         004730cc     MOV        this,dword ptr [ESI + 0x20]
    //         004730cf     PUSH       s_pnl_btn::draw2                                 = "pnl_btn::draw2"
    //         004730d4     CALL       TDrawArea::Unlock                                void Unlock(TDrawArea * this, char * param_1)
    //                               LAB_004730d9                                                 XREF[2]:     00472e01(j), 00472e18(j)  
    //                              Pnl_btn.cpp:839 (5)
    //         004730d9     MOV        this,ESI
    //         004730db     CALL       dword ptr [EDI + 0x2c]
    //                              Pnl_btn.cpp:840 (8)
    //         004730de     POP        EDI
    //         004730df     POP        ESI
    //         004730e0     POP        EBP
    //         004730e1     POP        EBX
    //         004730e2     ADD        ESP,0x30
    //         004730e5     RET
    //                               LAB_004730e6                                                 XREF[4]:     004728d0(j), 004728d9(j), 
    //                                                                                                         004728e2(j), 004728f1(j)  
    //                              Pnl_btn.cpp:599 (3)
    //         004730e6     MOV        dword ptr [ESI + 0x38],EBP
    //                              Pnl_btn.cpp:840 (43)
    //         004730e9     POP        EDI
    //         004730ea     POP        ESI
    //         004730eb     POP        EBP
    //         004730ec     POP        EBX
    //         004730ed     ADD        ESP,0x30
    //         004730f0     RET
}

// Offset: 0x004730F1
undefined FUN_004730f1() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_004730f1()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_004730f1
    //         004730f1     NOP
    //         004730f2     MOV        EDI,EDI
    //                              Symbol Ref: No symbol: NONAME
    //                               switchD_00472eb7::switchdataD_004730f4                       XREF[1]:     draw:00472eb7(*)  
}

// Offset: 0x00473120
long TDropDownButtonPanel::handle_mouse_down(uchar param_1, long param_2, long param_3, int param_4, int param_5) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual long __thiscall TButtonPanel::handle_mouse_down(unsigned char,long,long,int,int)      *
    //                              *********************************************************************************************************
    //                              long __thiscall handle_mouse_down(TButtonPanel * this, uchar param_1
    //              long              EAX:4          <RETURN>
    //              TButtonPanel *    ECX:4 (auto)   this
    //              uchar             Stack[0x4]:1   param_1
    //              long              Stack[0x8]:4   param_2                   XREF[1]:     00473147(R)  
    //              long              Stack[0xc]:4   param_3                   XREF[1]:     00473143(R)  
    //              int               Stack[0x10]:4  param_4
    //              int               Stack[0x14]:4  param_5
    //                               ?handle_mouse_down@TButtonPanel@@UAEJEJJHH@Z                 XREF[3]:     00571038(*), 00571330(*), 
    //                               TButtonPanel::handle_mouse_down                                           00576b40(*)  
    //                              Pnl_btn.cpp:846 (5)
    //         00473120     PUSH       EBX
    //         00473121     PUSH       ESI
    //         00473122     MOV        ESI,this
    //         00473124     PUSH       EDI
    //                              Pnl_btn.cpp:847 (7)
    //         00473125     MOV        EAX,dword ptr [ESI + 0x6c]
    //         00473128     TEST       EAX,EAX
    //         0047312a     JNZ        LAB_00473134
    //                              Pnl_btn.cpp:848 (2)
    //         0047312c     XOR        EAX,EAX
    //                              Pnl_btn.cpp:856 (6)
    //         0047312e     POP        EDI
    //         0047312f     POP        ESI
    //         00473130     POP        EBX
    //         00473131     RET        0x14
    //                               LAB_00473134                                                 XREF[1]:     0047312a(j)  
    //                              Pnl_btn.cpp:849 (7)
    //         00473134     MOV        EAX,dword ptr [ESI + 0x68]
    //         00473137     TEST       EAX,EAX
    //         00473139     JZ         LAB_00473143
    //                              Pnl_btn.cpp:850 (2)
    //         0047313b     XOR        EAX,EAX
    //                              Pnl_btn.cpp:856 (6)
    //         0047313d     POP        EDI
    //         0047313e     POP        ESI
    //         0047313f     POP        EBX
    //         00473140     RET        0x14
    //                               LAB_00473143                                                 XREF[1]:     00473139(j)  
    //                              Pnl_btn.cpp:852 (24)
    //         00473143     MOV        EDI,dword ptr [ESP + param_3]
    //         00473147     MOV        EBX,dword ptr [ESP + param_2]
    //         0047314b     MOV        EAX,dword ptr [ESI]
    //         0047314d     PUSH       EDI
    //         0047314e     PUSH       EBX
    //         0047314f     MOV        this,ESI
    //         00473151     CALL       dword ptr [EAX + 0xe4]
    //         00473157     TEST       EAX,EAX
    //         00473159     JNZ        LAB_00473161
    //                              Pnl_btn.cpp:856 (6)
    //         0047315b     POP        EDI
    //         0047315c     POP        ESI
    //         0047315d     POP        EBX
    //         0047315e     RET        0x14
    //                               LAB_00473161                                                 XREF[1]:     00473159(j)  
    //                              Pnl_btn.cpp:855 (24)
    //         00473161     MOV        this,dword ptr [ESP + 0x20]
    //         00473165     MOV        EDX,dword ptr [ESP + 0x1c]
    //         00473169     MOV        EAX,dword ptr [ESP + 0x10]
    //         0047316d     PUSH       this
    //         0047316e     PUSH       EDX
    //         0047316f     PUSH       EDI
    //         00473170     PUSH       EBX
    //         00473171     PUSH       EAX
    //         00473172     MOV        this,ESI
    //         00473174     CALL       TPanel::handle_mouse_down                        long handle_mouse_down(TPanel * this, uchar p
    //                              Pnl_btn.cpp:856 (6)
    //         00473179     POP        EDI
    //         0047317a     POP        ESI
    //         0047317b     POP        EBX
    //         0047317c     RET        0x14
}

// Offset: 0x00473180
long TDropDownButtonPanel::mouse_left_dbl_click_action(long param_1, long param_2, int param_3, int param_4) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual long __thiscall TButtonPanel::mouse_left_dbl_click_action(long,long,int,int)          *
    //                              *********************************************************************************************************
    //                              long __thiscall mouse_left_dbl_click_action(TButtonPanel * this, lon
    //              long              EAX:4          <RETURN>
    //              TButtonPanel *    ECX:4 (auto)   this
    //              long              Stack[0x4]:4   param_1
    //              long              Stack[0x8]:4   param_2
    //              int               Stack[0xc]:4   param_3
    //              int               Stack[0x10]:4  param_4
    //                               ?mouse_left_dbl_click_action@TButtonPanel@@UAEJJJHH@Z        XREF[3]:     0057105c(*), 00571354(*), 
    //                               TButtonPanel::mouse_left_dbl_click_action                                 00576b64(*)  
    //                              Pnl_btn.cpp:862 (2)
    //         00473180     XOR        EAX,EAX
    //                              Pnl_btn.cpp:865 (3)
    //         00473182     RET        0x10
}

// Offset: 0x00473190
long TDropDownButtonPanel::mouse_left_down_action(long param_1, long param_2, int param_3, int param_4) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual long __thiscall TButtonPanel::mouse_left_down_action(long,long,int,int)               *
    //                              *********************************************************************************************************
    //                              long __thiscall mouse_left_down_action(TButtonPanel * this, long par
    //              long              EAX:4          <RETURN>
    //              TButtonPanel *    ECX:4 (auto)   this
    //              long              Stack[0x4]:4   param_1
    //              long              Stack[0x8]:4   param_2
    //              int               Stack[0xc]:4   param_3
    //              int               Stack[0x10]:4  param_4
    //                               ?mouse_left_down_action@TButtonPanel@@UAEJJJHH@Z             XREF[3]:     0057104c(*), 00571344(*), 
    //                               TButtonPanel::mouse_left_down_action                                      00576b54(*)  
    //                              Pnl_btn.cpp:871 (3)
    //         00473190     PUSH       ESI
    //         00473191     MOV        ESI,this
    //                              Pnl_btn.cpp:872 (10)
    //         00473193     MOV        EAX,dword ptr [ESI + 0x2b0]
    //         00473199     TEST       EAX,EAX
    //         0047319b     JZ         LAB_004731a3
    //                              Pnl_btn.cpp:873 (2)
    //         0047319d     XOR        EAX,EAX
    //                              Pnl_btn.cpp:887 (4)
    //         0047319f     POP        ESI
    //         004731a0     RET        0x10
    //                               LAB_004731a3                                                 XREF[1]:     0047319b(j)  
    //                              Pnl_btn.cpp:874 (11)
    //         004731a3     MOV        this,dword ptr [ESI + 0x148]
    //         004731a9     PUSH       EDI
    //         004731aa     TEST       this,this
    //         004731ac     JZ         LAB_004731cd
    //                              Pnl_btn.cpp:876 (9)
    //         004731ae     CALL       TDigital::is_playing                             int is_playing(TDigital * this)
    //         004731b3     TEST       EAX,EAX
    //         004731b5     JZ         LAB_004731c2
    //                              Pnl_btn.cpp:877 (11)
    //         004731b7     MOV        this,dword ptr [ESI + 0x148]
    //         004731bd     CALL       TDigital::stop                                   void stop(TDigital * this)
    //                               LAB_004731c2                                                 XREF[1]:     004731b5(j)  
    //                              Pnl_btn.cpp:878 (11)
    //         004731c2     MOV        this,dword ptr [ESI + 0x148]
    //         004731c8     CALL       TDigital::play                                   int play(TDigital * this)
    //                               LAB_004731cd                                                 XREF[1]:     004731ac(j)  
    //                              Pnl_btn.cpp:880 (7)
    //         004731cd     MOV        this,ESI
    //         004731cf     CALL       TPanel::capture_mouse                            int capture_mouse(TPanel * this)
    //                              Pnl_btn.cpp:882 (34)
    //         004731d4     PUSH       0x372
    //         004731d9     PUSH       s_C:\msdev\work\age1_x1\Pnl_btn.cp               = "C:\\msdev\\work\\age1_x1\\Pnl_btn.cpp"
    //         004731de     MOV        dword ptr [ESI + 0x1f8],0x1
    //         004731e8     CALL       debug_timeGetTime                                ulong debug_timeGetTime(char * param_1, int p
    //         004731ed     ADD        ESP,0x8
    //         004731f0     MOV        dword ptr [ESI + 0x204],EAX
    //                              Pnl_btn.cpp:883 (9)
    //         004731f6     MOV        EAX,dword ptr [ESI]
    //         004731f8     MOV        this,ESI
    //         004731fa     PUSH       0x1
    //         004731fc     CALL       dword ptr [EAX + 0x20]
    //                              Pnl_btn.cpp:884 (7)
    //         004731ff     MOV        this,dword ptr [ESI + 0x40]
    //         00473202     TEST       this,this
    //         00473204     JZ         LAB_00473228
    //                              Pnl_btn.cpp:885 (35)
    //         00473206     MOVSX      EAX,word ptr [ESI + 0x1f6]
    //         0047320d     MOV        EDX,dword ptr [this->_padding_]
    //         0047320f     MOV        EDI,dword ptr [ESI + EAX*0x4 + 0x118]
    //         00473216     MOV        EAX,dword ptr [ESI + EAX*0x4 + 0xf4]
    //         0047321d     PUSH       EDI
    //         0047321e     PUSH       EAX=>DAT_fffffff8
    //         0047321f     PUSH       offset DAT_fffffff4
    //         00473221     PUSH       ESI=>DAT_fffffff0
    //         00473222     CALL       dword ptr [EDX + 0xb4]
    //                               LAB_00473228                                                 XREF[1]:     00473204(j)  
    //         00473228     POP        EDI
    //                              Pnl_btn.cpp:886 (5)
    //         00473229     MOV        EAX,0x1
    //                              Pnl_btn.cpp:887 (4)
    //         0047322e     POP        ESI
    //         0047322f     RET        0x10
}

// Offset: 0x00473240
long TDropDownButtonPanel::mouse_left_move_action(long param_1, long param_2, int param_3, int param_4) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual long __thiscall TButtonPanel::mouse_left_move_action(long,long,int,int)               *
    //                              *********************************************************************************************************
    //                              long __thiscall mouse_left_move_action(TButtonPanel * this, long par
    //              long              EAX:4          <RETURN>
    //              TButtonPanel *    ECX:4 (auto)   this
    //              long              Stack[0x4]:4   param_1                   XREF[1]:     00473248(R)  
    //              long              Stack[0x8]:4   param_2                   XREF[1]:     00473240(R)  
    //              int               Stack[0xc]:4   param_3
    //              int               Stack[0x10]:4  param_4
    //                               ?mouse_left_move_action@TButtonPanel@@UAEJJJHH@Z             XREF[3]:     00571054(*), 0057134c(*), 
    //                               TButtonPanel::mouse_left_move_action                                      00576b5c(*)  
    //                              Pnl_btn.cpp:893 (24)
    //         00473240     MOV        EAX,dword ptr [ESP + param_2]
    //         00473244     PUSH       ESI
    //         00473245     MOV        ESI,this
    //         00473247     PUSH       EDI
    //         00473248     MOV        this,dword ptr [ESP + param_1]
    //         0047324c     PUSH       EAX
    //         0047324d     MOV        EDI,dword ptr [ESI]
    //         0047324f     PUSH       this
    //         00473250     MOV        this,ESI
    //         00473252     CALL       dword ptr [EDI + 0xbc]
    //                              Pnl_btn.cpp:901 (20)
    //         00473258     MOV        this,dword ptr [ESI + 0x1f8]
    //         0047325e     NEG        EAX
    //         00473260     SBB        EAX,EAX
    //         00473262     NEG        EAX
    //         00473264     CMP        this,EAX
    //         00473266     JZ         LAB_004732f8
    //                              Pnl_btn.cpp:904 (10)
    //         0047326c     TEST       EAX,EAX
    //         0047326e     MOV        dword ptr [ESI + 0x1f8],EAX
    //         00473274     JZ         LAB_0047328e
    //                              Pnl_btn.cpp:905 (24)
    //         00473276     PUSH       0x389
    //         0047327b     PUSH       s_C:\msdev\work\age1_x1\Pnl_btn.cp               = "C:\\msdev\\work\\age1_x1\\Pnl_btn.cpp"
    //         00473280     CALL       debug_timeGetTime                                ulong debug_timeGetTime(char * param_1, int p
    //         00473285     ADD        ESP,0x8
    //         00473288     MOV        dword ptr [ESI + 0x204],EAX
    //                               LAB_0047328e                                                 XREF[1]:     00473274(j)  
    //                              Pnl_btn.cpp:906 (7)
    //         0047328e     PUSH       0x1
    //         00473290     MOV        this,ESI
    //         00473292     CALL       dword ptr [EDI + 0x20]
    //                              Pnl_btn.cpp:907 (6)
    //         00473295     MOV        EAX,dword ptr [ESI + 0x1f8]
    //                              Pnl_btn.cpp:909 (11)
    //         0047329b     MOV        this,dword ptr [ESI + 0x40]
    //         0047329e     TEST       EAX,EAX
    //         004732a0     JZ         LAB_004732d2
    //         004732a2     TEST       this,this
    //         004732a4     JZ         LAB_004732f8
    //                              Pnl_btn.cpp:910 (27)
    //         004732a6     MOVSX      EAX,word ptr [ESI + 0x1f6]
    //         004732ad     MOV        EDX,dword ptr [this->_padding_]
    //         004732af     MOV        EDI,dword ptr [ESI + EAX*0x4 + 0x118]
    //         004732b6     MOV        EAX,dword ptr [ESI + EAX*0x4 + 0xf4]
    //         004732bd     PUSH       EDI
    //         004732be     PUSH       EAX=>DAT_fffffff8
    //         004732bf     PUSH       offset DAT_fffffff4
    //                              Pnl_btn.cpp:915 (7)
    //         004732c1     PUSH       ESI=>DAT_fffffff0
    //         004732c2     CALL       dword ptr [EDX + 0xb4]
    //                              Pnl_btn.cpp:919 (5)
    //         004732c8     MOV        EAX,0x1
    //                              Pnl_btn.cpp:920 (5)
    //         004732cd     POP        EDI
    //         004732ce     POP        ESI
    //         004732cf     RET        0x10
    //                               LAB_004732d2                                                 XREF[1]:     004732a0(j)  
    //                              Pnl_btn.cpp:914 (4)
    //         004732d2     TEST       this,this
    //         004732d4     JZ         LAB_004732f8
    //                              Pnl_btn.cpp:915 (34)
    //         004732d6     MOVSX      EAX,word ptr [ESI + 0x1f6]
    //         004732dd     MOV        EDX,dword ptr [this->_padding_]
    //         004732df     MOV        EDI,dword ptr [ESI + EAX*0x4 + 0x118]
    //         004732e6     MOV        EAX,dword ptr [ESI + EAX*0x4 + 0xf4]
    //         004732ed     PUSH       EDI
    //         004732ee     PUSH       EAX=>DAT_fffffff8
    //         004732ef     PUSH       offset DAT_fffffff4
    //         004732f1     PUSH       ESI=>DAT_fffffff0
    //         004732f2     CALL       dword ptr [EDX + 0xb4]
    //                               LAB_004732f8                                                 XREF[3]:     00473266(j), 004732a4(j), 
    //                                                                                                         004732d4(j)  
    //                              Pnl_btn.cpp:920 (10)
    //         004732f8     POP        EDI
    //         004732f9     MOV        EAX,0x1
    //         004732fe     POP        ESI
    //         004732ff     RET        0x10
}

// Offset: 0x00473310
long TDropDownButtonPanel::mouse_left_up_action(long param_1, long param_2, int param_3, int param_4) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual long __thiscall TButtonPanel::mouse_left_up_action(long,long,int,int)                 *
    //                              *********************************************************************************************************
    //                              long __thiscall mouse_left_up_action(TButtonPanel * this, long param
    //              long              EAX:4          <RETURN>
    //              TButtonPanel *    ECX:4 (auto)   this
    //              long              Stack[0x4]:4   param_1
    //              long              Stack[0x8]:4   param_2
    //              int               Stack[0xc]:4   param_3
    //              int               Stack[0x10]:4  param_4
    //                               ?mouse_left_up_action@TButtonPanel@@UAEJJJHH@Z               XREF[3]:     00571058(*), 00571350(*), 
    //                               TButtonPanel::mouse_left_up_action                                        00576b60(*)  
    //                              Pnl_btn.cpp:926 (3)
    //         00473310     PUSH       ESI
    //         00473311     MOV        ESI,this
    //                              Pnl_btn.cpp:927 (5)
    //         00473313     CALL       TPanel::release_mouse                            void release_mouse(TPanel * this)
    //                              Pnl_btn.cpp:929 (8)
    //         00473318     MOV        EAX,dword ptr [ESI + 0x1f8]
    //         0047331e     TEST       EAX,EAX
    //                              Pnl_btn.cpp:931 (13)
    //         00473320     MOV        EAX,dword ptr [ESI + 0x13c]
    //         00473326     JZ         LAB_00473363
    //         00473328     CMP        EAX,0x2
    //         0047332b     JZ         LAB_00473337
    //                              Pnl_btn.cpp:932 (10)
    //         0047332d     MOV        dword ptr [ESI + 0x1f8],0x0
    //                               LAB_00473337                                                 XREF[1]:     0047332b(j)  
    //                              Pnl_btn.cpp:934 (9)
    //         00473337     MOV        EAX,dword ptr [ESI]
    //         00473339     PUSH       0x1
    //         0047333b     MOV        this,ESI
    //         0047333d     CALL       dword ptr [EAX + 0x20]
    //                              Pnl_btn.cpp:935 (19)
    //         00473340     MOV        this,dword ptr [ESI + 0x20]
    //         00473343     PUSH       0x0
    //         00473345     PUSH       0x0=>DAT_fffffff8
    //         00473347     PUSH       offset DAT_fffffff4
    //         00473349     MOV        EDX,dword ptr [ECX + this->_padding_]
    //         0047334c     PUSH       EDX=>DAT_fffffff0
    //         0047334d     CALL       dword ptr [->USER32.DLL::SendMessageA]           = 0048ad08
    //                              Pnl_btn.cpp:937 (7)
    //         00473353     MOV        this,ESI
    //         00473355     CALL       TButtonPanel::do_action                          void do_action(TButtonPanel * this)
    //                              Pnl_btn.cpp:945 (5)
    //         0047335a     MOV        EAX,0x1
    //                              Pnl_btn.cpp:946 (4)
    //         0047335f     POP        ESI
    //         00473360     RET        0x10
    //                               LAB_00473363                                                 XREF[1]:     00473326(j)  
    //                              Pnl_btn.cpp:939 (15)
    //         00473363     CMP        EAX,0x2
    //         00473366     JNZ        LAB_00473385
    //         00473368     CMP        word ptr [ESI + 0x1f6],0x1
    //         00473370     JNZ        LAB_00473385
    //                              Pnl_btn.cpp:942 (19)
    //         00473372     MOV        EAX,dword ptr [ESI]
    //         00473374     PUSH       0x1
    //         00473376     MOV        this,ESI
    //         00473378     MOV        dword ptr [ESI + 0x1f8],0x1
    //         00473382     CALL       dword ptr [EAX + 0x20]
    //                               LAB_00473385                                                 XREF[2]:     00473366(j), 00473370(j)  
    //                              Pnl_btn.cpp:945 (5)
    //         00473385     MOV        EAX,0x1
    //                              Pnl_btn.cpp:946 (4)
    //         0047338a     POP        ESI
    //         0047338b     RET        0x10
}

// Offset: 0x00473390
long TDropDownButtonPanel::mouse_right_dbl_click_action(long param_1, long param_2, int param_3, int param_4) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual long __thiscall TButtonPanel::mouse_right_dbl_click_action(long,long,int,int)         *
    //                              *********************************************************************************************************
    //                              long __thiscall mouse_right_dbl_click_action(TButtonPanel * this, lo
    //              long              EAX:4          <RETURN>
    //              TButtonPanel *    ECX:4 (auto)   this
    //              long              Stack[0x4]:4   param_1
    //              long              Stack[0x8]:4   param_2
    //              int               Stack[0xc]:4   param_3
    //              int               Stack[0x10]:4  param_4
    //                               ?mouse_right_dbl_click_action@TButtonPanel@@UAEJJJHH@Z       XREF[3]:     00571070(*), 00571368(*), 
    //                               TButtonPanel::mouse_right_dbl_click_action                                00576b78(*)  
    //                              Pnl_btn.cpp:952 (2)
    //         00473390     XOR        EAX,EAX
    //                              Pnl_btn.cpp:955 (3)
    //         00473392     RET        0x10
}

// Offset: 0x004733A0
long TDropDownButtonPanel::mouse_right_down_action(long param_1, long param_2, int param_3, int param_4) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual long __thiscall TButtonPanel::mouse_right_down_action(long,long,int,int)              *
    //                              *********************************************************************************************************
    //                              long __thiscall mouse_right_down_action(TButtonPanel * this, long pa
    //              long              EAX:4          <RETURN>
    //              TButtonPanel *    ECX:4 (auto)   this
    //              long              Stack[0x4]:4   param_1
    //              long              Stack[0x8]:4   param_2
    //              int               Stack[0xc]:4   param_3
    //              int               Stack[0x10]:4  param_4
    //                               ?mouse_right_down_action@TButtonPanel@@UAEJJJHH@Z            XREF[3]:     00571060(*), 00571358(*), 
    //                               TButtonPanel::mouse_right_down_action                                     00576b68(*)  
    //                              Pnl_btn.cpp:961 (3)
    //         004733a0     PUSH       ESI
    //         004733a1     MOV        ESI,this
    //                              Pnl_btn.cpp:962 (10)
    //         004733a3     MOV        EAX,dword ptr [ESI + 0x2b0]
    //         004733a9     TEST       EAX,EAX
    //         004733ab     JZ         LAB_004733b3
    //                              Pnl_btn.cpp:963 (2)
    //         004733ad     XOR        EAX,EAX
    //                              Pnl_btn.cpp:977 (4)
    //         004733af     POP        ESI
    //         004733b0     RET        0x10
    //                               LAB_004733b3                                                 XREF[1]:     004733ab(j)  
    //                              Pnl_btn.cpp:964 (11)
    //         004733b3     MOV        this,dword ptr [ESI + 0x148]
    //         004733b9     PUSH       EDI
    //         004733ba     TEST       this,this
    //         004733bc     JZ         LAB_004733dd
    //                              Pnl_btn.cpp:966 (9)
    //         004733be     CALL       TDigital::is_playing                             int is_playing(TDigital * this)
    //         004733c3     TEST       EAX,EAX
    //         004733c5     JZ         LAB_004733d2
    //                              Pnl_btn.cpp:967 (11)
    //         004733c7     MOV        this,dword ptr [ESI + 0x148]
    //         004733cd     CALL       TDigital::stop                                   void stop(TDigital * this)
    //                               LAB_004733d2                                                 XREF[1]:     004733c5(j)  
    //                              Pnl_btn.cpp:968 (11)
    //         004733d2     MOV        this,dword ptr [ESI + 0x148]
    //         004733d8     CALL       TDigital::play                                   int play(TDigital * this)
    //                               LAB_004733dd                                                 XREF[1]:     004733bc(j)  
    //                              Pnl_btn.cpp:970 (7)
    //         004733dd     MOV        this,ESI
    //         004733df     CALL       TPanel::capture_mouse                            int capture_mouse(TPanel * this)
    //                              Pnl_btn.cpp:972 (34)
    //         004733e4     PUSH       0x3cc
    //         004733e9     PUSH       s_C:\msdev\work\age1_x1\Pnl_btn.cp               = "C:\\msdev\\work\\age1_x1\\Pnl_btn.cpp"
    //         004733ee     MOV        dword ptr [ESI + 0x1f8],0x1
    //         004733f8     CALL       debug_timeGetTime                                ulong debug_timeGetTime(char * param_1, int p
    //         004733fd     ADD        ESP,0x8
    //         00473400     MOV        dword ptr [ESI + 0x204],EAX
    //                              Pnl_btn.cpp:973 (9)
    //         00473406     MOV        EAX,dword ptr [ESI]
    //         00473408     MOV        this,ESI
    //         0047340a     PUSH       0x1
    //         0047340c     CALL       dword ptr [EAX + 0x20]
    //                              Pnl_btn.cpp:974 (7)
    //         0047340f     MOV        this,dword ptr [ESI + 0x40]
    //         00473412     TEST       this,this
    //         00473414     JZ         LAB_00473438
    //                              Pnl_btn.cpp:975 (35)
    //         00473416     MOVSX      EAX,word ptr [ESI + 0x1f6]
    //         0047341d     MOV        EDX,dword ptr [this->_padding_]
    //         0047341f     MOV        EDI,dword ptr [ESI + EAX*0x4 + 0x118]
    //         00473426     MOV        EAX,dword ptr [ESI + EAX*0x4 + 0xf4]
    //         0047342d     PUSH       EDI
    //         0047342e     PUSH       EAX=>DAT_fffffff8
    //         0047342f     PUSH       offset DAT_fffffff4
    //         00473431     PUSH       ESI=>DAT_fffffff0
    //         00473432     CALL       dword ptr [EDX + 0xb4]
    //                               LAB_00473438                                                 XREF[1]:     00473414(j)  
    //         00473438     POP        EDI
    //                              Pnl_btn.cpp:976 (5)
    //         00473439     MOV        EAX,0x1
    //                              Pnl_btn.cpp:977 (4)
    //         0047343e     POP        ESI
    //         0047343f     RET        0x10
}

// Offset: 0x00473450
long TDropDownButtonPanel::mouse_right_move_action(long param_1, long param_2, int param_3, int param_4) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual long __thiscall TButtonPanel::mouse_right_move_action(long,long,int,int)              *
    //                              *********************************************************************************************************
    //                              long __thiscall mouse_right_move_action(TButtonPanel * this, long pa
    //              long              EAX:4          <RETURN>
    //              TButtonPanel *    ECX:4 (auto)   this
    //              long              Stack[0x4]:4   param_1                   XREF[1]:     00473458(R)  
    //              long              Stack[0x8]:4   param_2                   XREF[1]:     00473450(R)  
    //              int               Stack[0xc]:4   param_3
    //              int               Stack[0x10]:4  param_4
    //                               ?mouse_right_move_action@TButtonPanel@@UAEJJJHH@Z            XREF[3]:     00571068(*), 00571360(*), 
    //                               TButtonPanel::mouse_right_move_action                                     00576b70(*)  
    //                              Pnl_btn.cpp:983 (24)
    //         00473450     MOV        EAX,dword ptr [ESP + param_2]
    //         00473454     PUSH       ESI
    //         00473455     MOV        ESI,this
    //         00473457     PUSH       EDI
    //         00473458     MOV        this,dword ptr [ESP + param_1]
    //         0047345c     PUSH       EAX
    //         0047345d     MOV        EDI,dword ptr [ESI]
    //         0047345f     PUSH       this
    //         00473460     MOV        this,ESI
    //         00473462     CALL       dword ptr [EDI + 0xbc]
    //                              Pnl_btn.cpp:991 (20)
    //         00473468     MOV        this,dword ptr [ESI + 0x1f8]
    //         0047346e     NEG        EAX
    //         00473470     SBB        EAX,EAX
    //         00473472     NEG        EAX
    //         00473474     CMP        this,EAX
    //         00473476     JZ         LAB_00473508
    //                              Pnl_btn.cpp:994 (10)
    //         0047347c     TEST       EAX,EAX
    //         0047347e     MOV        dword ptr [ESI + 0x1f8],EAX
    //         00473484     JZ         LAB_0047349e
    //                              Pnl_btn.cpp:995 (24)
    //         00473486     PUSH       0x3e3
    //         0047348b     PUSH       s_C:\msdev\work\age1_x1\Pnl_btn.cp               = "C:\\msdev\\work\\age1_x1\\Pnl_btn.cpp"
    //         00473490     CALL       debug_timeGetTime                                ulong debug_timeGetTime(char * param_1, int p
    //         00473495     ADD        ESP,0x8
    //         00473498     MOV        dword ptr [ESI + 0x204],EAX
    //                               LAB_0047349e                                                 XREF[1]:     00473484(j)  
    //                              Pnl_btn.cpp:996 (7)
    //         0047349e     PUSH       0x1
    //         004734a0     MOV        this,ESI
    //         004734a2     CALL       dword ptr [EDI + 0x20]
    //                              Pnl_btn.cpp:997 (6)
    //         004734a5     MOV        EAX,dword ptr [ESI + 0x1f8]
    //                              Pnl_btn.cpp:999 (11)
    //         004734ab     MOV        this,dword ptr [ESI + 0x40]
    //         004734ae     TEST       EAX,EAX
    //         004734b0     JZ         LAB_004734e2
    //         004734b2     TEST       this,this
    //         004734b4     JZ         LAB_00473508
    //                              Pnl_btn.cpp:1000 (27)
    //         004734b6     MOVSX      EAX,word ptr [ESI + 0x1f6]
    //         004734bd     MOV        EDX,dword ptr [this->_padding_]
    //         004734bf     MOV        EDI,dword ptr [ESI + EAX*0x4 + 0x118]
    //         004734c6     MOV        EAX,dword ptr [ESI + EAX*0x4 + 0xf4]
    //         004734cd     PUSH       EDI
    //         004734ce     PUSH       EAX=>DAT_fffffff8
    //         004734cf     PUSH       offset DAT_fffffff4
    //                              Pnl_btn.cpp:1005 (7)
    //         004734d1     PUSH       ESI=>DAT_fffffff0
    //         004734d2     CALL       dword ptr [EDX + 0xb4]
    //                              Pnl_btn.cpp:1009 (5)
    //         004734d8     MOV        EAX,0x1
    //                              Pnl_btn.cpp:1010 (5)
    //         004734dd     POP        EDI
    //         004734de     POP        ESI
    //         004734df     RET        0x10
    //                               LAB_004734e2                                                 XREF[1]:     004734b0(j)  
    //                              Pnl_btn.cpp:1004 (4)
    //         004734e2     TEST       this,this
    //         004734e4     JZ         LAB_00473508
    //                              Pnl_btn.cpp:1005 (34)
    //         004734e6     MOVSX      EAX,word ptr [ESI + 0x1f6]
    //         004734ed     MOV        EDX,dword ptr [this->_padding_]
    //         004734ef     MOV        EDI,dword ptr [ESI + EAX*0x4 + 0x118]
    //         004734f6     MOV        EAX,dword ptr [ESI + EAX*0x4 + 0xf4]
    //         004734fd     PUSH       EDI
    //         004734fe     PUSH       EAX=>DAT_fffffff8
    //         004734ff     PUSH       offset DAT_fffffff4
    //         00473501     PUSH       ESI=>DAT_fffffff0
    //         00473502     CALL       dword ptr [EDX + 0xb4]
    //                               LAB_00473508                                                 XREF[3]:     00473476(j), 004734b4(j), 
    //                                                                                                         004734e4(j)  
    //                              Pnl_btn.cpp:1010 (10)
    //         00473508     POP        EDI
    //         00473509     MOV        EAX,0x1
    //         0047350e     POP        ESI
    //         0047350f     RET        0x10
}

// Offset: 0x00473520
long TDropDownButtonPanel::mouse_right_up_action(long param_1, long param_2, int param_3, int param_4) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual long __thiscall TButtonPanel::mouse_right_up_action(long,long,int,int)                *
    //                              *********************************************************************************************************
    //                              long __thiscall mouse_right_up_action(TButtonPanel * this, long para
    //              long              EAX:4          <RETURN>
    //              TButtonPanel *    ECX:4 (auto)   this
    //              long              Stack[0x4]:4   param_1
    //              long              Stack[0x8]:4   param_2
    //              int               Stack[0xc]:4   param_3
    //              int               Stack[0x10]:4  param_4
    //                               ?mouse_right_up_action@TButtonPanel@@UAEJJJHH@Z              XREF[3]:     0057106c(*), 00571364(*), 
    //                               TButtonPanel::mouse_right_up_action                                       00576b74(*)  
    //                              Pnl_btn.cpp:1016 (3)
    //         00473520     PUSH       ESI
    //         00473521     MOV        ESI,this
    //                              Pnl_btn.cpp:1017 (5)
    //         00473523     CALL       TPanel::release_mouse                            void release_mouse(TPanel * this)
    //                              Pnl_btn.cpp:1019 (8)
    //         00473528     MOV        EAX,dword ptr [ESI + 0x1f8]
    //         0047352e     TEST       EAX,EAX
    //                              Pnl_btn.cpp:1021 (13)
    //         00473530     MOV        EAX,dword ptr [ESI + 0x13c]
    //         00473536     JZ         LAB_00473578
    //         00473538     CMP        EAX,0x2
    //         0047353b     JZ         LAB_00473547
    //                              Pnl_btn.cpp:1022 (10)
    //         0047353d     MOV        dword ptr [ESI + 0x1f8],0x0
    //                               LAB_00473547                                                 XREF[1]:     0047353b(j)  
    //                              Pnl_btn.cpp:1024 (9)
    //         00473547     MOV        EAX,dword ptr [ESI]
    //         00473549     PUSH       0x1
    //         0047354b     MOV        this,ESI
    //         0047354d     CALL       dword ptr [EAX + 0x20]
    //                              Pnl_btn.cpp:1025 (19)
    //         00473550     MOV        this,dword ptr [ESI + 0x20]
    //         00473553     PUSH       0x0
    //         00473555     PUSH       0x0=>DAT_fffffff8
    //         00473557     PUSH       offset DAT_fffffff4
    //         00473559     MOV        EDX,dword ptr [ECX + this->_padding_]
    //         0047355c     PUSH       EDX=>DAT_fffffff0
    //         0047355d     CALL       dword ptr [->USER32.DLL::SendMessageA]           = 0048ad08
    //                              Pnl_btn.cpp:1027 (12)
    //         00473563     MOV        EAX,dword ptr [ESP + 0x14]
    //         00473567     MOV        this,ESI
    //         00473569     PUSH       EAX
    //         0047356a     CALL       TButtonPanel::do_right_action                    void do_right_action(TButtonPanel * this, int
    //                              Pnl_btn.cpp:1035 (5)
    //         0047356f     MOV        EAX,0x1
    //                              Pnl_btn.cpp:1036 (4)
    //         00473574     POP        ESI
    //         00473575     RET        0x10
    //                               LAB_00473578                                                 XREF[1]:     00473536(j)  
    //                              Pnl_btn.cpp:1029 (15)
    //         00473578     CMP        EAX,0x2
    //         0047357b     JNZ        LAB_0047359a
    //         0047357d     CMP        word ptr [ESI + 0x1f6],0x1
    //         00473585     JNZ        LAB_0047359a
    //                              Pnl_btn.cpp:1032 (19)
    //         00473587     MOV        EDX,dword ptr [ESI]
    //         00473589     PUSH       0x1
    //         0047358b     MOV        this,ESI
    //         0047358d     MOV        dword ptr [ESI + 0x1f8],0x1
    //         00473597     CALL       dword ptr [EDX + 0x20]
    //                               LAB_0047359a                                                 XREF[2]:     0047357b(j), 00473585(j)  
    //                              Pnl_btn.cpp:1035 (5)
    //         0047359a     MOV        EAX,0x1
    //                              Pnl_btn.cpp:1036 (4)
    //         0047359f     POP        ESI
    //         004735a0     RET        0x10
}

// Offset: 0x004735B0
long TDropDownButtonPanel::handle_key_down(long param_1, short param_2, int param_3, int param_4, int param_5) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual long __thiscall TButtonPanel::handle_key_down(long,short,int,int,int)                 *
    //                              *********************************************************************************************************
    //                              long __thiscall handle_key_down(TButtonPanel * this, long param_1, s
    //              long              EAX:4          <RETURN>
    //              TButtonPanel *    ECX:4 (auto)   this
    //              long              Stack[0x4]:4   param_1                   XREF[1]:     004735b5(R)  
    //              short             Stack[0x8]:2   param_2                   XREF[1]:     004736ce(R)  
    //              int               Stack[0xc]:4   param_3                   XREF[1]:     004735c1(R)  
    //              int               Stack[0x10]:4  param_4                   XREF[1]:     004735b1(R)  
    //              int               Stack[0x14]:4  param_5                   XREF[1]:     004735bd(R)  
    //                               ?handle_key_down@TButtonPanel@@UAEJJFHHH@Z                   XREF[3]:     00571020(*), 00571318(*), 
    //                               TButtonPanel::handle_key_down                                             00576b28(*)  
    //                              Pnl_btn.cpp:1042 (1)
    //         004735b0     PUSH       EBX
    //                              Pnl_btn.cpp:1045 (115)
    //         004735b1     MOV        EDX,dword ptr [ESP + param_4]
    //         004735b5     MOV        EBX,dword ptr [ESP + param_1]
    //         004735b9     PUSH       ESI
    //         004735ba     MOV        ESI,this
    //         004735bc     PUSH       EDI
    //         004735bd     MOV        this,dword ptr [ESP + param_5]
    //         004735c1     MOV        EDI,dword ptr [ESP + param_3]
    //         004735c5     MOV        EAX,dword ptr [ESI + 0x6c]
    //         004735c8     TEST       EAX,EAX
    //         004735ca     JZ         LAB_004736cd
    //         004735d0     MOV        EAX,dword ptr [ESI + 0x2b0]
    //         004735d6     TEST       EAX,EAX
    //         004735d8     JNZ        LAB_004736cd
    //         004735de     TEST       EDI,EDI
    //         004735e0     JNZ        LAB_004736cd
    //         004735e6     TEST       EDX,EDX
    //         004735e8     JNZ        LAB_004736cd
    //         004735ee     MOV        EAX,dword ptr [ESI + 0x298]
    //         004735f4     TEST       EAX,EAX
    //         004735f6     JZ         LAB_004736cd
    //         004735fc     CMP        EBX,EAX
    //         004735fe     JNZ        LAB_004736cd
    //         00473604     MOV        EAX,dword ptr [ESI + 0x2ac]
    //         0047360a     TEST       EAX,EAX
    //         0047360c     JNZ        LAB_004736cd
    //         00473612     MOV        EAX,dword ptr [ESI + 0x29c]
    //         00473618     TEST       EAX,EAX
    //         0047361a     JZ         LAB_00473624
    //         0047361c     CMP        this,EAX
    //         0047361e     JNZ        LAB_004736cd
    //                               LAB_00473624                                                 XREF[1]:     0047361a(j)  
    //                              Pnl_btn.cpp:1047 (21)
    //         00473624     MOV        EAX,dword ptr [ESI + 0x74]
    //         00473627     TEST       EAX,EAX
    //         00473629     JZ         LAB_0047363f
    //         0047362b     MOV        this,dword ptr [ESI + 0x40]
    //         0047362e     TEST       this,this
    //         00473630     JZ         LAB_0047363f
    //         00473632     MOV        EAX,dword ptr [ESI + 0x78]
    //         00473635     TEST       EAX,EAX
    //         00473637     JNZ        LAB_0047363f
    //                              Pnl_btn.cpp:1048 (6)
    //         00473639     PUSH       ESI
    //         0047363a     CALL       TPanel::set_curr_child                           void set_curr_child(TPanel * this, TPanel * p
    //                               LAB_0047363f                                                 XREF[3]:     00473629(j), 00473630(j), 
    //                                                                                                         00473637(j)  
    //                              Pnl_btn.cpp:1049 (10)
    //         0047363f     MOV        this,dword ptr [ESI + 0x148]
    //         00473645     TEST       this,this
    //         00473647     JZ         LAB_00473668
    //                              Pnl_btn.cpp:1051 (9)
    //         00473649     CALL       TDigital::is_playing                             int is_playing(TDigital * this)
    //         0047364e     TEST       EAX,EAX
    //         00473650     JZ         LAB_0047365d
    //                              Pnl_btn.cpp:1052 (11)
    //         00473652     MOV        this,dword ptr [ESI + 0x148]
    //         00473658     CALL       TDigital::stop                                   void stop(TDigital * this)
    //                               LAB_0047365d                                                 XREF[1]:     00473650(j)  
    //                              Pnl_btn.cpp:1053 (11)
    //         0047365d     MOV        this,dword ptr [ESI + 0x148]
    //         00473663     CALL       TDigital::play                                   int play(TDigital * this)
    //                               LAB_00473668                                                 XREF[1]:     00473647(j)  
    //                              Pnl_btn.cpp:1057 (40)
    //         00473668     PUSH       0x421
    //         0047366d     PUSH       s_C:\msdev\work\age1_x1\Pnl_btn.cp               = "C:\\msdev\\work\\age1_x1\\Pnl_btn.cpp"
    //         00473672     MOV        dword ptr [ESI + 0x2ac],EBX
    //         00473678     MOV        dword ptr [ESI + 0x1f8],0x1
    //         00473682     CALL       debug_timeGetTime                                ulong debug_timeGetTime(char * param_1, int p
    //         00473687     ADD        ESP,0x8
    //         0047368a     MOV        dword ptr [ESI + 0x204],EAX
    //                              Pnl_btn.cpp:1058 (9)
    //         00473690     MOV        EAX,dword ptr [ESI]
    //         00473692     MOV        this,ESI
    //         00473694     PUSH       0x1
    //         00473696     CALL       dword ptr [EAX + 0x20]
    //                              Pnl_btn.cpp:1059 (7)
    //         00473699     MOV        this,dword ptr [ESI + 0x40]
    //         0047369c     TEST       this,this
    //         0047369e     JZ         LAB_004736c2
    //                              Pnl_btn.cpp:1060 (34)
    //         004736a0     MOVSX      EAX,word ptr [ESI + 0x1f6]
    //         004736a7     MOV        EDX,dword ptr [this->_padding_]
    //         004736a9     MOV        EDI,dword ptr [ESI + EAX*0x4 + 0x118]
    //         004736b0     MOV        EAX,dword ptr [ESI + EAX*0x4 + 0xf4]
    //         004736b7     PUSH       EDI
    //         004736b8     PUSH       EAX=>DAT_fffffff8
    //         004736b9     PUSH       offset DAT_fffffff4
    //         004736bb     PUSH       ESI=>DAT_fffffff0
    //         004736bc     CALL       dword ptr [EDX + 0xb4]
    //                               LAB_004736c2                                                 XREF[1]:     0047369e(j)  
    //                              Pnl_btn.cpp:1062 (5)
    //         004736c2     MOV        EAX,0x1
    //                              Pnl_btn.cpp:1065 (6)
    //         004736c7     POP        EDI
    //         004736c8     POP        ESI
    //         004736c9     POP        EBX
    //         004736ca     RET        0x14
    //                               LAB_004736cd                                                 XREF[8]:     004735ca(j), 004735d8(j), 
    //                                                                                                         004735e0(j), 004735e8(j), 
    //                                                                                                         004735f6(j), 004735fe(j), 
    //                                                                                                         0047360c(j), 0047361e(j)  
    //                              Pnl_btn.cpp:1064 (16)
    //         004736cd     PUSH       this
    //         004736ce     MOV        this,dword ptr [ESP + param_2]
    //         004736d2     PUSH       EDX
    //         004736d3     PUSH       EDI
    //         004736d4     PUSH       this
    //         004736d5     PUSH       EBX
    //         004736d6     MOV        this,ESI
    //         004736d8     CALL       TPanel::handle_key_down                          long handle_key_down(TPanel * this, long para
    //                              Pnl_btn.cpp:1065 (6)
    //         004736dd     POP        EDI
    //         004736de     POP        ESI
    //         004736df     POP        EBX
    //         004736e0     RET        0x14
}

// Offset: 0x004736F0
long TDropDownButtonPanel::key_down_action(long param_1, short param_2, int param_3, int param_4, int param_5) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual long __thiscall TButtonPanel::key_down_action(long,short,int,int,int)                 *
    //                              *********************************************************************************************************
    //                              long __thiscall key_down_action(TButtonPanel * this, long param_1, s
    //              long              EAX:4          <RETURN>
    //              TButtonPanel *    ECX:4 (auto)   this
    //              long              Stack[0x4]:4   param_1                   XREF[1]:     00473702(R)  
    //              short             Stack[0x8]:2   param_2
    //              int               Stack[0xc]:4   param_3                   XREF[3]:     00473721(R), 00473754(R), 004737ab(R)  
    //              int               Stack[0x10]:4  param_4                   XREF[3]:     0047372d(R), 00473760(R), 004737b7(R)  
    //              int               Stack[0x14]:4  param_5
    //                               ?key_down_action@TButtonPanel@@UAEJJFHHH@Z                   XREF[3]:     00571074(*), 0057136c(*), 
    //                               TButtonPanel::key_down_action                                             00576b7c(*)  
    //                              Pnl_btn.cpp:1071 (4)
    //         004736f0     PUSH       ESI
    //         004736f1     MOV        ESI,this
    //         004736f3     PUSH       EDI
    //                              Pnl_btn.cpp:1074 (14)
    //         004736f4     MOV        EAX,dword ptr [ESI + 0x2ac]
    //         004736fa     TEST       EAX,EAX
    //         004736fc     JNZ        switchD_0047371a::caseD_e
    //                              Pnl_btn.cpp:1076 (31)
    //         00473702     MOV        EDI,dword ptr [ESP + param_1]
    //         00473706     LEA        EAX,[EDI + -0xd]
    //         00473709     CMP        EAX,0x1b
    //         0047370c     JA         switchD_0047371a::caseD_e
    //         00473712     XOR        this,this
    //         00473714     MOV        this,byte ptr [EAX + 0x47386c]=>PTR_caseD_d_00
    //                               switchD_0047371a::switchD
    //         0047371a     JMP        dword ptr [this->_padding_*0x4 + switchD_00473   = 0047379d
    //                               switchD_0047371a::caseD_28                                   XREF[2]:     0047371a(j), 00473864(*)  
    //                              Pnl_btn.cpp:1079 (49)
    //         00473721     MOV        EAX,dword ptr [ESP + param_3]
    //         00473725     TEST       EAX,EAX
    //         00473727     JNZ        LAB_00473846
    //         0047372d     MOV        EAX,dword ptr [ESP + param_4]
    //         00473731     TEST       EAX,EAX
    //         00473733     JNZ        LAB_00473846
    //         00473739     MOV        EAX,dword ptr [ESI + 0x74]
    //         0047373c     TEST       EAX,EAX
    //         0047373e     JZ         LAB_00473846
    //         00473744     MOV        this,dword ptr [ESI + 0x40]
    //         00473747     TEST       this,this
    //         00473749     JZ         LAB_00473846
    //         0047374f     MOV        ESI,dword ptr [ESI + 0x64]
    //                              Pnl_btn.cpp:1081 (2)
    //         00473752     JMP        LAB_00473785
    //                               switchD_0047371a::caseD_26                                   XREF[2]:     0047371a(j), 00473860(*)  
    //                              Pnl_btn.cpp:1084 (57)
    //         00473754     MOV        EAX,dword ptr [ESP + param_3]
    //         00473758     TEST       EAX,EAX
    //         0047375a     JNZ        LAB_00473846
    //         00473760     MOV        EAX,dword ptr [ESP + param_4]
    //         00473764     TEST       EAX,EAX
    //         00473766     JNZ        LAB_00473846
    //         0047376c     MOV        EAX,dword ptr [ESI + 0x74]
    //         0047376f     TEST       EAX,EAX
    //         00473771     JZ         LAB_00473846
    //         00473777     MOV        this,dword ptr [ESI + 0x40]
    //         0047377a     TEST       this,this
    //         0047377c     JZ         LAB_00473846
    //         00473782     MOV        ESI,dword ptr [ESI + 0x60]
    //                               LAB_00473785                                                 XREF[1]:     00473752(j)  
    //         00473785     TEST       ESI,ESI
    //         00473787     JZ         LAB_00473846
    //                              Pnl_btn.cpp:1085 (6)
    //         0047378d     PUSH       ESI
    //         0047378e     CALL       TPanel::set_curr_child                           void set_curr_child(TPanel * this, TPanel * p
    //                              Pnl_btn.cpp:1086 (5)
    //         00473793     MOV        EAX,0x1
    //                              Pnl_btn.cpp:1110 (5)
    //         00473798     POP        EDI
    //         00473799     POP        ESI
    //         0047379a     RET        0x14
    //                               switchD_0047371a::caseD_20                                   XREF[3]:     0047371a(j), 00473858(*), 
    //                               switchD_0047371a::caseD_d                                                 0047385c(*)  
    //                              Pnl_btn.cpp:1090 (38)
    //         0047379d     MOV        EAX,dword ptr [ESI + 0x2b0]
    //         004737a3     TEST       EAX,EAX
    //         004737a5     JNZ        switchD_0047371a::caseD_e
    //         004737ab     MOV        EAX,dword ptr [ESP + param_3]
    //         004737af     TEST       EAX,EAX
    //         004737b1     JNZ        switchD_0047371a::caseD_e
    //         004737b7     MOV        EAX,dword ptr [ESP + param_4]
    //         004737bb     TEST       EAX,EAX
    //         004737bd     JNZ        switchD_0047371a::caseD_e
    //                              Pnl_btn.cpp:1091 (10)
    //         004737c3     MOV        this,dword ptr [ESI + 0x148]
    //         004737c9     TEST       this,this
    //         004737cb     JZ         LAB_004737ec
    //                              Pnl_btn.cpp:1093 (9)
    //         004737cd     CALL       TDigital::is_playing                             int is_playing(TDigital * this)
    //         004737d2     TEST       EAX,EAX
    //         004737d4     JZ         LAB_004737e1
    //                              Pnl_btn.cpp:1094 (11)
    //         004737d6     MOV        this,dword ptr [ESI + 0x148]
    //         004737dc     CALL       TDigital::stop                                   void stop(TDigital * this)
    //                               LAB_004737e1                                                 XREF[1]:     004737d4(j)  
    //                              Pnl_btn.cpp:1095 (11)
    //         004737e1     MOV        this,dword ptr [ESI + 0x148]
    //         004737e7     CALL       TDigital::play                                   int play(TDigital * this)
    //                               LAB_004737ec                                                 XREF[1]:     004737cb(j)  
    //                              Pnl_btn.cpp:1099 (31)
    //         004737ec     PUSH       0x44b
    //         004737f1     PUSH       s_C:\msdev\work\age1_x1\Pnl_btn.cp               = "C:\\msdev\\work\\age1_x1\\Pnl_btn.cpp"
    //         004737f6     MOV        dword ptr [ESI + 0x2ac],EDI
    //         004737fc     MOV        dword ptr [ESI + 0x1f8],0x1
    //         00473806     CALL       debug_timeGetTime                                ulong debug_timeGetTime(char * param_1, int p
    //                              Pnl_btn.cpp:1100 (18)
    //         0047380b     MOV        EDX,dword ptr [ESI]
    //         0047380d     ADD        ESP,0x8
    //         00473810     MOV        this,ESI
    //         00473812     MOV        dword ptr [ESI + 0x204],EAX
    //         00473818     PUSH       0x1
    //         0047381a     CALL       dword ptr [EDX + 0x20]
    //                              Pnl_btn.cpp:1101 (7)
    //         0047381d     MOV        this,dword ptr [ESI + 0x40]
    //         00473820     TEST       this,this
    //         00473822     JZ         LAB_00473846
    //                              Pnl_btn.cpp:1102 (34)
    //         00473824     MOVSX      EAX,word ptr [ESI + 0x1f6]
    //         0047382b     MOV        EDX,dword ptr [this->_padding_]
    //         0047382d     MOV        EDI,dword ptr [ESI + EAX*0x4 + 0x118]
    //         00473834     MOV        EAX,dword ptr [ESI + EAX*0x4 + 0xf4]
    //         0047383b     PUSH       EDI
    //         0047383c     PUSH       EAX=>DAT_fffffff8
    //         0047383d     PUSH       offset DAT_fffffff4
    //         0047383f     PUSH       ESI=>DAT_fffffff0
    //         00473840     CALL       dword ptr [EDX + 0xb4]
    //                               LAB_00473846                                                 XREF[10]:    00473727(j), 00473733(j), 
    //                                                                                                         0047373e(j), 00473749(j), 
    //                                                                                                         0047375a(j), 00473766(j), 
    //                                                                                                         00473771(j), 0047377c(j), 
    //                                                                                                         00473787(j), 00473822(j)  
    //                              Pnl_btn.cpp:1104 (5)
    //         00473846     MOV        EAX,0x1
    //                              Pnl_btn.cpp:1110 (61)
    //         0047384b     POP        EDI
    //         0047384c     POP        ESI
    //         0047384d     RET        0x14
    //                               switchD_0047371a::caseD_f                                    XREF[7]:     004736fc(j), 0047370c(j), 
    //                               switchD_0047371a::caseD_10                                                0047371a(j), 004737a5(j), 
    //                               switchD_0047371a::caseD_11                                                004737b1(j), 004737bd(j), 
    //                               switchD_0047371a::caseD_12                                                00473868(*)  
    //                               switchD_0047371a::caseD_13
    //                               switchD_0047371a::caseD_14
    //                               switchD_0047371a::caseD_15
    //                               switchD_0047371a::caseD_16
    //                               switchD_0047371a::caseD_17
    //                               switchD_0047371a::caseD_18
    //                               switchD_0047371a::caseD_19
    //                               switchD_0047371a::caseD_1a
    //                               switchD_0047371a::caseD_1b
    //                               switchD_0047371a::caseD_1c
    //                               switchD_0047371a::caseD_1d
    //                               switchD_0047371a::caseD_1e
    //                               switchD_0047371a::caseD_1f
    //                               switchD_0047371a::caseD_21
    //                               switchD_0047371a::caseD_22
    //                               switchD_0047371a::caseD_23
    //                               switchD_0047371a::caseD_24
    //                               switchD_0047371a::caseD_25
    //                               switchD_0047371a::caseD_27
    //                               switchD_0047371a::caseD_e
    //         00473850     POP        EDI
    //         00473851     XOR        EAX,EAX
    //         00473853     POP        ESI
    //         00473854     RET        0x14
}

// Offset: 0x00473890
long TDropDownButtonPanel::wnd_proc(void* param_1, uint param_2, uint param_3, long param_4) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual long __thiscall TButtonPanel::wnd_proc(void *,unsigned int,unsigned int,long)         *
    //                              *********************************************************************************************************
    //                              long __thiscall wnd_proc(TButtonPanel * this, void * param_1, uint p
    //              long              EAX:4          <RETURN>
    //              TButtonPanel *    ECX:4 (auto)   this
    //              void *            Stack[0x4]:4   param_1                   XREF[1]:     00473903(R)  
    //              uint              Stack[0x8]:4   param_2                   XREF[1]:     00473897(R)  
    //              uint              Stack[0xc]:4   param_3                   XREF[1]:     00473890(R)  
    //              long              Stack[0x10]:4  param_4                   XREF[1]:     004738fc(R)  
    //                               ?wnd_proc@TButtonPanel@@UAEJPAXIIJ@Z                         XREF[3]:     00571010(*), 00571308(*), 
    //                               TButtonPanel::wnd_proc                                                    00576b18(*)  
    //                              Pnl_btn.cpp:1118 (19)
    //         00473890     MOV        EDX,dword ptr [ESP + param_3]
    //         00473894     PUSH       ESI
    //         00473895     MOV        ESI,this
    //         00473897     MOV        this,dword ptr [ESP + param_2]
    //         0047389b     CMP        this,0x101
    //         004738a1     JNZ        LAB_004738fc
    //                              Pnl_btn.cpp:1121 (14)
    //         004738a3     MOV        EAX,dword ptr [ESI + 0x2ac]
    //         004738a9     TEST       EAX,EAX
    //         004738ab     JZ         LAB_004738fc
    //         004738ad     CMP        EDX,EAX
    //         004738af     JNZ        LAB_004738fc
    //                              Pnl_btn.cpp:1124 (21)
    //         004738b1     MOV        EAX,dword ptr [ESI + 0x13c]
    //         004738b7     MOV        dword ptr [ESI + 0x2ac],0x0
    //         004738c1     CMP        EAX,0x2
    //         004738c4     JZ         LAB_004738d0
    //                              Pnl_btn.cpp:1125 (10)
    //         004738c6     MOV        dword ptr [ESI + 0x1f8],0x0
    //                               LAB_004738d0                                                 XREF[1]:     004738c4(j)  
    //                              Pnl_btn.cpp:1127 (9)
    //         004738d0     MOV        EAX,dword ptr [ESI]
    //         004738d2     PUSH       0x1
    //         004738d4     MOV        this,ESI
    //         004738d6     CALL       dword ptr [EAX + 0x20]
    //                              Pnl_btn.cpp:1128 (19)
    //         004738d9     MOV        this,dword ptr [ESI + 0x20]
    //         004738dc     PUSH       0x0
    //         004738de     PUSH       0x0
    //         004738e0     PUSH       0xf
    //         004738e2     MOV        EDX,dword ptr [ECX + this->_padding_]
    //         004738e5     PUSH       EDX
    //         004738e6     CALL       dword ptr [->USER32.DLL::SendMessageA]           = 0048ad08
    //                              Pnl_btn.cpp:1130 (7)
    //         004738ec     MOV        this,ESI
    //         004738ee     CALL       TButtonPanel::do_action                          void do_action(TButtonPanel * this)
    //                              Pnl_btn.cpp:1131 (5)
    //         004738f3     MOV        EAX,0x1
    //                              Pnl_btn.cpp:1135 (4)
    //         004738f8     POP        ESI
    //         004738f9     RET        0x10
    //                               LAB_004738fc                                                 XREF[3]:     004738a1(j), 004738ab(j), 
    //                                                                                                         004738af(j)  
    //                              Pnl_btn.cpp:1134 (19)
    //         004738fc     MOV        EAX,dword ptr [ESP + param_4]
    //         00473900     PUSH       EAX
    //         00473901     PUSH       EDX
    //         00473902     PUSH       this
    //         00473903     MOV        this,dword ptr [ESP + param_1]
    //         00473907     PUSH       this
    //         00473908     MOV        this,ESI
    //         0047390a     CALL       TPanel::wnd_proc                                 long wnd_proc(TPanel * this, void * param_1, 
    //                              Pnl_btn.cpp:1135 (4)
    //         0047390f     POP        ESI
    //         00473910     RET        0x10
}

// Offset: 0x00473920
long TDropDownButtonPanel::char_action(long param_1, short param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual long __thiscall TButtonPanel::char_action(long,short)                                 *
    //                              *********************************************************************************************************
    //                              long __thiscall char_action(TButtonPanel * this, long param_1, short
    //              long              EAX:4          <RETURN>
    //              TButtonPanel *    ECX:4 (auto)   this
    //              long              Stack[0x4]:4   param_1
    //              short             Stack[0x8]:2   param_2
    //                               ?char_action@TButtonPanel@@UAEJJF@Z                          XREF[3]:     00571078(*), 00571370(*), 
    //                               TButtonPanel::char_action                                                 00576b80(*)  
    //                              Pnl_btn.cpp:1140 (2)
    //         00473920     XOR        EAX,EAX
    //                              Pnl_btn.cpp:1165 (3)
    //         00473922     RET        0x8
}

// Offset: 0x00473930
int TDropDownButtonPanel::hit_button(long param_1, long param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual int __thiscall TButtonPanel::hit_button(long,long)                                    *
    //                              *********************************************************************************************************
    //                              int __thiscall hit_button(TButtonPanel * this, long param_1, long pa
    //              int               EAX:4          <RETURN>
    //              TButtonPanel *    ECX:4 (auto)   this
    //              long              Stack[0x4]:4   param_1                   XREF[1]:     00473931(R)  
    //              long              Stack[0x8]:4   param_2                   XREF[1]:     00473937(R)  
    //                               ?hit_button@TButtonPanel@@UAEHJJ@Z                           XREF[3]:     005710ac(*), 005713a4(*), 
    //                               TButtonPanel::hit_button                                                  00576bb4(*)  
    //                              Pnl_btn.cpp:1171 (1)
    //         00473930     PUSH       EBX
    //                              Pnl_btn.cpp:1172 (26)
    //         00473931     MOV        EBX,dword ptr [ESP + param_1]
    //         00473935     PUSH       ESI
    //         00473936     PUSH       EDI
    //         00473937     MOV        EDI,dword ptr [ESP + param_2]
    //         0047393b     MOV        ESI,this
    //         0047393d     PUSH       EDI
    //         0047393e     PUSH       EBX
    //         0047393f     MOV        EAX,dword ptr [ESI]
    //         00473941     CALL       dword ptr [EAX + 0xbc]
    //         00473947     TEST       EAX,EAX
    //         00473949     JNZ        LAB_00473951
    //                              Pnl_btn.cpp:1182 (6)
    //         0047394b     POP        EDI
    //         0047394c     POP        ESI
    //         0047394d     POP        EBX
    //         0047394e     RET        0x8
    //                               LAB_00473951                                                 XREF[1]:     00473949(j)  
    //                              Pnl_btn.cpp:1175 (36)
    //         00473951     MOV        EAX,dword ptr [ESI + 0x190]
    //         00473957     TEST       EAX,EAX
    //         00473959     JNZ        LAB_004739a1
    //         0047395b     MOVSX      EAX,word ptr [ESI + 0x1f6]
    //         00473962     MOV        this,dword ptr [ESI + EAX*0x4 + 0x14c]
    //         00473969     TEST       this,this
    //         0047396b     JZ         LAB_004739a1
    //         0047396d     MOVSX      EDX,word ptr [ESI + EAX*0x2 + 0x170]
    //                              Pnl_btn.cpp:1178 (38)
    //         00473975     MOV        EAX,dword ptr [ESI + 0x10]
    //         00473978     PUSH       EDX
    //         00473979     SUB        EDI,dword ptr [ESI + 0x18c]
    //         0047397f     SUB        EDI,EAX
    //         00473981     MOV        EAX,dword ptr [ESI + 0x188]
    //         00473987     PUSH       EDI=>DAT_fffffff8
    //         00473988     MOV        EDI,dword ptr [ESI + 0xc]
    //         0047398b     SUB        EBX,EAX
    //         0047398d     SUB        EBX,EDI
    //         0047398f     PUSH       EBX=>DAT_fffffff4
    //         00473990     CALL       TShape::shape_check                              uchar shape_check(TShape * this, long param_1
    //         00473995     NEG        AL
    //         00473997     SBB        EAX,EAX
    //         00473999     NEG        EAX
    //                              Pnl_btn.cpp:1182 (17)
    //         0047399b     POP        EDI
    //         0047399c     POP        ESI
    //         0047399d     POP        EBX
    //         0047399e     RET        0x8
    //                               LAB_004739a1                                                 XREF[2]:     00473959(j), 0047396b(j)  
    //         004739a1     POP        EDI
    //         004739a2     POP        ESI
    //         004739a3     MOV        EAX,0x1
    //         004739a8     POP        EBX
    //         004739a9     RET        0x8
}

// Offset: 0x004739B0
void do_action(TButtonPanel* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TButtonPanel::do_action(void)                                                 *
    //                              *********************************************************************************************************
    //                              void __thiscall do_action(TButtonPanel * this)
    //              void              <VOID>         <RETURN>
    //              TButtonPanel *    ECX:4 (auto)   this
    //                               ?do_action@TButtonPanel@@QAEXXZ                              XREF[2]:     mouse_left_up_action:00473355(c), 
    //                               TButtonPanel::do_action                                                   wnd_proc:004738ee(c)  
    //                              Pnl_btn.cpp:1188 (4)
    //         004739b0     PUSH       ESI
    //         004739b1     MOV        ESI,this
    //         004739b3     PUSH       EDI
    //                              Pnl_btn.cpp:1189 (11)
    //         004739b4     MOV        EAX,dword ptr [ESI + 0x13c]
    //         004739ba     CMP        EAX,0x3
    //         004739bd     JNZ        LAB_004739f1
    //                              Pnl_btn.cpp:1191 (22)
    //         004739bf     MOV        AX,word ptr [ESI + 0x1f6]
    //         004739c6     MOVSX      this,word ptr [ESI + 0x1f4]
    //         004739cd     MOVSX      EDX,AX
    //         004739d0     DEC        this
    //         004739d1     CMP        EDX,this
    //         004739d3     JNZ        LAB_004739e3
    //                              Pnl_btn.cpp:1192 (12)
    //         004739d5     MOV        EAX,dword ptr [ESI]
    //         004739d7     PUSH       0x0
    //         004739d9     MOV        this,ESI
    //         004739db     CALL       dword ptr [EAX + 0xe0]
    //                              Pnl_btn.cpp:1193 (2)
    //         004739e1     JMP        LAB_004739fd
    //                               LAB_004739e3                                                 XREF[1]:     004739d3(j)  
    //                              Pnl_btn.cpp:1194 (12)
    //         004739e3     MOV        EDX,dword ptr [ESI]
    //         004739e5     INC        EAX
    //         004739e6     PUSH       EAX
    //         004739e7     MOV        this,ESI
    //         004739e9     CALL       dword ptr [EDX + 0xe0]
    //                              Pnl_btn.cpp:1196 (7)
    //         004739ef     JMP        LAB_004739fd
    //                               LAB_004739f1                                                 XREF[1]:     004739bd(j)  
    //         004739f1     CMP        EAX,0x2
    //         004739f4     JNZ        LAB_004739fd
    //                              Pnl_btn.cpp:1197 (7)
    //         004739f6     MOV        this,ESI
    //         004739f8     CALL       TButtonPanel::set_radio_button                   void set_radio_button(TButtonPanel * this)
    //                               LAB_004739fd                                                 XREF[3]:     004739e1(j), 004739ef(j), 
    //                                                                                                         004739f4(j)  
    //                              Pnl_btn.cpp:1199 (7)
    //         004739fd     MOV        this,dword ptr [ESI + 0x40]
    //         00473a00     TEST       this,this
    //         00473a02     JZ         LAB_00473a26
    //                              Pnl_btn.cpp:1200 (34)
    //         00473a04     MOVSX      EAX,word ptr [ESI + 0x1f6]
    //         00473a0b     MOV        EDX,dword ptr [this->_padding_]
    //         00473a0d     MOV        EDI,dword ptr [ESI + EAX*0x4 + 0x118]
    //         00473a14     MOV        EAX,dword ptr [ESI + EAX*0x4 + 0xf4]
    //         00473a1b     PUSH       EDI
    //         00473a1c     PUSH       EAX=>DAT_fffffff8
    //         00473a1d     PUSH       offset DAT_fffffff4
    //         00473a1f     PUSH       ESI=>DAT_fffffff0
    //         00473a20     CALL       dword ptr [EDX + 0xb4]
    //                               LAB_00473a26                                                 XREF[1]:     00473a02(j)  
    //                              Pnl_btn.cpp:1202 (9)
    //         00473a26     CMP        dword ptr [ESI + 0x144],0x1
    //         00473a2d     JNZ        LAB_00473a5b
    //                              Pnl_btn.cpp:1204 (7)
    //         00473a2f     MOV        this,dword ptr [ESI + 0x40]
    //         00473a32     TEST       this,this
    //         00473a34     JZ         LAB_00473a93
    //                              Pnl_btn.cpp:1205 (34)
    //         00473a36     MOVSX      EAX,word ptr [ESI + 0x1f6]
    //         00473a3d     MOV        EDX,dword ptr [this->_padding_]
    //         00473a3f     MOV        EDI,dword ptr [ESI + EAX*0x4 + 0x118]
    //         00473a46     MOV        EAX,dword ptr [ESI + EAX*0x4 + 0xf4]
    //         00473a4d     PUSH       EDI
    //         00473a4e     PUSH       EAX=>DAT_fffffff8
    //         00473a4f     PUSH       offset DAT_fffffff4
    //         00473a51     PUSH       ESI=>DAT_fffffff0
    //         00473a52     CALL       dword ptr [EDX + 0xb4]
    //                              Pnl_btn.cpp:1212 (3)
    //         00473a58     POP        EDI
    //         00473a59     POP        ESI
    //         00473a5a     RET
    //                               LAB_00473a5b                                                 XREF[1]:     00473a2d(j)  
    //                              Pnl_btn.cpp:1209 (29)
    //         00473a5b     MOVSX      EAX,word ptr [ESI + 0x1f6]
    //         00473a62     MOV        this,dword ptr [ESI + EAX*0x4 + 0xf4]
    //         00473a69     TEST       this,this
    //         00473a6b     JNZ        LAB_00473a78
    //         00473a6d     MOV        EDX,dword ptr [ESI + EAX*0x4 + 0x118]
    //         00473a74     TEST       EDX,EDX
    //         00473a76     JZ         LAB_00473a93
    //                               LAB_00473a78                                                 XREF[1]:     00473a6b(j)  
    //                              Pnl_btn.cpp:1210 (27)
    //         00473a78     MOV        EDX,dword ptr [ESI + EAX*0x4 + 0x118]
    //         00473a7f     MOV        EAX,dword ptr [ESI + 0x20]
    //         00473a82     PUSH       EDX
    //         00473a83     PUSH       this=>DAT_fffffff8
    //         00473a84     MOV        this,dword ptr [EAX + 0x4]
    //         00473a87     PUSH       offset DAT_fffffff4
    //         00473a8c     PUSH       this=>DAT_fffffff0
    //         00473a8d     CALL       dword ptr [->USER32.DLL::SendMessageA]           = 0048ad08
    //                               LAB_00473a93                                                 XREF[2]:     00473a34(j), 00473a76(j)  
    //                              Pnl_btn.cpp:1212 (3)
    //         00473a93     POP        EDI
    //         00473a94     POP        ESI
    //         00473a95     RET
}

// Offset: 0x00473AA0
void do_right_action(TButtonPanel* this_, int param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TButtonPanel::do_right_action(int)                                            *
    //                              *********************************************************************************************************
    //                              void __thiscall do_right_action(TButtonPanel * this, int param_1)
    //              void              <VOID>         <RETURN>
    //              TButtonPanel *    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1
    //                               ?do_right_action@TButtonPanel@@QAEXH@Z                       XREF[1]:     mouse_right_up_action:0047356a(c)  
    //                               TButtonPanel::do_right_action
    //                              Pnl_btn.cpp:1218 (5)
    //         00473aa0     PUSH       EBX
    //         00473aa1     PUSH       ESI
    //         00473aa2     MOV        ESI,this
    //         00473aa4     PUSH       EDI
    //                              Pnl_btn.cpp:1221 (11)
    //         00473aa5     MOV        EAX,dword ptr [ESI + 0x13c]
    //         00473aab     CMP        EAX,0x3
    //         00473aae     JNZ        LAB_00473ae2
    //                              Pnl_btn.cpp:1223 (22)
    //         00473ab0     MOV        AX,word ptr [ESI + 0x1f6]
    //         00473ab7     MOVSX      this,word ptr [ESI + 0x1f4]
    //         00473abe     MOVSX      EDX,AX
    //         00473ac1     DEC        this
    //         00473ac2     CMP        EDX,this
    //         00473ac4     JNZ        LAB_00473ad4
    //                              Pnl_btn.cpp:1224 (12)
    //         00473ac6     MOV        EAX,dword ptr [ESI]
    //         00473ac8     PUSH       0x0
    //         00473aca     MOV        this,ESI
    //         00473acc     CALL       dword ptr [EAX + 0xe0]
    //                              Pnl_btn.cpp:1225 (2)
    //         00473ad2     JMP        LAB_00473aee
    //                               LAB_00473ad4                                                 XREF[1]:     00473ac4(j)  
    //                              Pnl_btn.cpp:1226 (12)
    //         00473ad4     MOV        EDX,dword ptr [ESI]
    //         00473ad6     INC        EAX
    //         00473ad7     PUSH       EAX
    //         00473ad8     MOV        this,ESI
    //         00473ada     CALL       dword ptr [EDX + 0xe0]
    //                              Pnl_btn.cpp:1228 (7)
    //         00473ae0     JMP        LAB_00473aee
    //                               LAB_00473ae2                                                 XREF[1]:     00473aae(j)  
    //         00473ae2     CMP        EAX,0x2
    //         00473ae5     JNZ        LAB_00473aee
    //                              Pnl_btn.cpp:1229 (7)
    //         00473ae7     MOV        this,ESI
    //         00473ae9     CALL       TButtonPanel::set_radio_button                   void set_radio_button(TButtonPanel * this)
    //                               LAB_00473aee                                                 XREF[3]:     00473ad2(j), 00473ae0(j), 
    //                                                                                                         00473ae5(j)  
    //                              Pnl_btn.cpp:1238 (7)
    //         00473aee     MOVSX      EAX,word ptr [ESI + 0x1f6]
    //                              Pnl_btn.cpp:1242 (21)
    //         00473af5     MOV        this,dword ptr [ESI + 0x40]
    //         00473af8     MOV        EDI,dword ptr [ESI + EAX*0x4 + 0xf4]
    //         00473aff     MOV        EBX,dword ptr [ESI + EAX*0x4 + 0x118]
    //         00473b06     TEST       this,this
    //         00473b08     JZ         LAB_00473b17
    //                              Pnl_btn.cpp:1243 (13)
    //         00473b0a     MOV        EAX,dword ptr [this->_padding_]
    //         00473b0c     PUSH       EBX
    //         00473b0d     PUSH       EDI=>DAT_fffffff8
    //         00473b0e     PUSH       offset DAT_fffffff4
    //         00473b10     PUSH       ESI=>DAT_fffffff0
    //         00473b11     CALL       dword ptr [EAX + 0xb4]
    //                               LAB_00473b17                                                 XREF[1]:     00473b08(j)  
    //                              Pnl_btn.cpp:1245 (9)
    //         00473b17     CMP        dword ptr [ESI + 0x144],0x1
    //         00473b1e     JNZ        LAB_00473b3a
    //                              Pnl_btn.cpp:1247 (7)
    //         00473b20     MOV        this,dword ptr [ESI + 0x40]
    //         00473b23     TEST       this,this
    //         00473b25     JZ         LAB_00473b6b
    //                              Pnl_btn.cpp:1248 (13)
    //         00473b27     MOV        EDX,dword ptr [this->_padding_]
    //         00473b29     PUSH       EBX
    //         00473b2a     PUSH       EDI=>DAT_fffffff8
    //         00473b2b     PUSH       offset DAT_fffffff4
    //         00473b2d     PUSH       ESI=>DAT_fffffff0
    //         00473b2e     CALL       dword ptr [EDX + 0xb4]
    //                              Pnl_btn.cpp:1255 (6)
    //         00473b34     POP        EDI
    //         00473b35     POP        ESI
    //         00473b36     POP        EBX
    //         00473b37     RET        0x4
    //                               LAB_00473b3a                                                 XREF[1]:     00473b1e(j)  
    //                              Pnl_btn.cpp:1252 (29)
    //         00473b3a     MOVSX      EAX,word ptr [ESI + 0x1f6]
    //         00473b41     MOV        this,dword ptr [ESI + EAX*0x4 + 0xf4]
    //         00473b48     TEST       this,this
    //         00473b4a     JNZ        LAB_00473b57
    //         00473b4c     MOV        this,dword ptr [ESI + EAX*0x4 + 0x118]
    //         00473b53     TEST       this,this
    //         00473b55     JZ         LAB_00473b6b
    //                               LAB_00473b57                                                 XREF[1]:     00473b4a(j)  
    //                              Pnl_btn.cpp:1253 (20)
    //         00473b57     MOV        EAX,dword ptr [ESI + 0x20]
    //         00473b5a     PUSH       EBX
    //         00473b5b     PUSH       EDI=>DAT_fffffff8
    //         00473b5c     PUSH       offset DAT_fffffff4
    //         00473b61     MOV        this,dword ptr [EAX + 0x4]
    //         00473b64     PUSH       this=>DAT_fffffff0
    //         00473b65     CALL       dword ptr [->USER32.DLL::SendMessageA]           = 0048ad08
    //                               LAB_00473b6b                                                 XREF[2]:     00473b25(j), 00473b55(j)  
    //                              Pnl_btn.cpp:1255 (6)
    //         00473b6b     POP        EDI
    //         00473b6c     POP        ESI
    //         00473b6d     POP        EBX
    //         00473b6e     RET        0x4
}

// Offset: 0x00473B80
void reset(TButtonPanel* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TButtonPanel::reset(void)                                                     *
    //                              *********************************************************************************************************
    //                              void __thiscall reset(TButtonPanel * this)
    //              void              <VOID>         <RETURN>
    //              TButtonPanel *    ECX:4 (auto)   this
    //                               ?reset@TButtonPanel@@QAEXXZ                                  XREF[1]:     set_button:0049abc5(c)  
    //                               TButtonPanel::reset
    //                              Pnl_btn.cpp:1261 (3)
    //         00473b80     PUSH       ESI
    //         00473b81     MOV        ESI,this
    //                              Pnl_btn.cpp:1262 (5)
    //         00473b83     CALL       TPanel::release_mouse                            void release_mouse(TPanel * this)
    //                              Pnl_btn.cpp:1264 (10)
    //         00473b88     MOV        EAX,dword ptr [ESI + 0x1f8]
    //         00473b8e     TEST       EAX,EAX
    //         00473b90     JZ         LAB_00473bae
    //                              Pnl_btn.cpp:1266 (9)
    //         00473b92     CMP        dword ptr [ESI + 0x13c],0x2
    //         00473b99     JZ         LAB_00473ba5
    //                              Pnl_btn.cpp:1267 (10)
    //         00473b9b     MOV        dword ptr [ESI + 0x1f8],0x0
    //                               LAB_00473ba5                                                 XREF[1]:     00473b99(j)  
    //                              Pnl_btn.cpp:1268 (9)
    //         00473ba5     MOV        EAX,dword ptr [ESI]
    //         00473ba7     PUSH       0x1
    //         00473ba9     MOV        this,ESI
    //         00473bab     CALL       dword ptr [EAX + 0x20]
    //                               LAB_00473bae                                                 XREF[1]:     00473b90(j)  
    //                              Pnl_btn.cpp:1270 (2)
    //         00473bae     POP        ESI
    //         00473baf     RET
}

// Offset: 0x00473BB0
void set_sound_number(TButtonPanel* this_, int param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TButtonPanel::set_sound_number(int)                                           *
    //                              *********************************************************************************************************
    //                              void __thiscall set_sound_number(TButtonPanel * this, int param_1)
    //              void              <VOID>         <RETURN>
    //              TButtonPanel *    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     00473bb0(R)  
    //                               ?set_sound_number@TButtonPanel@@QAEXH@Z                      XREF[4]:     create_button:00468637(c), 
    //                               TButtonPanel::set_sound_number                                            create_check_box:00468869(c), 
    //                                                                                                         create_radio_button:00468ac9(c), 
    //                                                                                                         TRIBE_Screen_Game:004945b5(c)  
    //                              Pnl_btn.cpp:1276 (10)
    //         00473bb0     MOV        EAX,dword ptr [ESP + param_1]
    //         00473bb4     MOV        dword ptr [ECX + this->sound_number],EAX
    //                              Pnl_btn.cpp:1278 (3)
    //         00473bba     RET        0x4
}

// Offset: 0x00473BC0
void TDropDownButtonPanel::stop_sound_system() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void __thiscall TButtonPanel::stop_sound_system(void)                                 *
    //                              *********************************************************************************************************
    //                              void __thiscall stop_sound_system(TButtonPanel * this)
    //              void              <VOID>         <RETURN>
    //              TButtonPanel *    ECX:4 (auto)   this
    //                               ?stop_sound_system@TButtonPanel@@UAEXXZ                      XREF[3]:     00571098(*), 00571390(*), 
    //                               TButtonPanel::stop_sound_system                                           00576ba0(*)  
    //                              Pnl_btn.cpp:1284 (10)
    //         00473bc0     MOV        EAX,dword ptr [ECX + this->sound]
    //         00473bc6     TEST       EAX,EAX
    //         00473bc8     JZ         LAB_00473bd4
    //                              Pnl_btn.cpp:1286 (10)
    //         00473bca     MOV        dword ptr [ECX + this->sound],0x0
    //                               LAB_00473bd4                                                 XREF[1]:     00473bc8(j)  
    //                              Pnl_btn.cpp:1287 (1)
    //         00473bd4     RET
}

// Offset: 0x00473BE0
int TDropDownButtonPanel::restart_sound_system() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual int __thiscall TButtonPanel::restart_sound_system(void)                               *
    //                              *********************************************************************************************************
    //                              int __thiscall restart_sound_system(TButtonPanel * this)
    //              int               EAX:4          <RETURN>
    //              TButtonPanel *    ECX:4 (auto)   this
    //                               ?restart_sound_system@TButtonPanel@@UAEHXZ                   XREF[3]:     0057109c(*), 00571394(*), 
    //                               TButtonPanel::restart_sound_system                                        00576ba4(*)  
    //                              Pnl_btn.cpp:1293 (3)
    //         00473be0     PUSH       ESI
    //         00473be1     MOV        ESI,this
    //                              Pnl_btn.cpp:1294 (11)
    //         00473be3     MOV        EAX,dword ptr [ESI + 0x2b4]
    //         00473be9     CMP        EAX,-0x1
    //         00473bec     JZ         LAB_00473c00
    //                              Pnl_btn.cpp:1295 (18)
    //         00473bee     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         00473bf4     PUSH       EAX
    //         00473bf5     CALL       RGE_Base_Game::get_sound                         TDigital * get_sound(RGE_Base_Game * this, in
    //         00473bfa     MOV        dword ptr [ESI + 0x148],EAX
    //                               LAB_00473c00                                                 XREF[1]:     00473bec(j)  
    //                              Pnl_btn.cpp:1296 (5)
    //         00473c00     MOV        EAX,0x1
    //                              Pnl_btn.cpp:1297 (2)
    //         00473c05     POP        ESI
    //         00473c06     RET
}

