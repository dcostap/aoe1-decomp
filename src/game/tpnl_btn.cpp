#include "../common.h"
#include "tpnl_btn.h"

TRIBE_Panel_Button::TRIBE_Panel_Button(TDrawArea* param_1, TPanel* param_2, TDigital* param_3, void* param_4, long param_5, long param_6, TShape* param_7) {
    /* TODO: Stub */
//                              undefined __thiscall TRIBE_Panel_Button(TRIBE_Panel_Button * this, T
//              undefined         <UNASSIGNED>   <RETURN>
//              TRIBE_Panel_Bu    ECX:4 (auto)   this
//              TDrawArea *       Stack[0x4]:4   param_1                   XREF[1]:     00519e0f(R)
//              TPanel *          Stack[0x8]:4   param_2                   XREF[1]:     00519e05(R)
//              TDigital *        Stack[0xc]:4   param_3                   XREF[1]:     00519dc2(R)
//              void *            Stack[0x10]:4  param_4                   XREF[1]:     00519e4c(R)
//              long              Stack[0x14]:4  param_5                   XREF[1]:     00519e48(R)
//              long              Stack[0x18]:4  param_6                   XREF[1]:     00519e44(R)
//              TShape *          Stack[0x1c]:4  param_7                   XREF[1]:     00519dc6(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     00519dd6(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[2]:     00519e32(R), 00519e5a(R)
//              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     00519db9(W)
//                               ??0TRIBE_Panel_Button@@QAE@PAVTDrawArea@@PAVTPanel@@PAVTDig  XREF[1]:     TRIBE_Screen_Game:0049457d(c)
//                               TRIBE_Panel_Button::TRIBE_Panel_Button
//                              tpnl_btn.cpp:50 (34)
//         00519da0     PUSH       -0x1
//         00519da2     PUSH       FUN_005612f8
//         00519da7     MOV        EAX,FS:[0x0]
//         00519dad     PUSH       EAX
//         00519dae     MOV        dword ptr FS:[0x0],ESP
//         00519db5     PUSH       this
//         00519db6     PUSH       ESI
//         00519db7     MOV        ESI,this
//         00519db9     MOV        dword ptr [ESP + local_10],ESI
//         00519dbd     CALL       TButtonPanel::TButtonPanel                       undefined TButtonPanel(TButtonPanel * this)
//                              tpnl_btn.cpp:61 (100)
//         00519dc2     MOV        EDX,dword ptr [ESP + param_3]
//         00519dc6     MOV        this,dword ptr [ESP + param_7]
//         00519dca     PUSH       -0x1
//         00519dcc     PUSH       0x1
//         00519dce     XOR        EAX,EAX
//         00519dd0     PUSH       EDX
//         00519dd1     PUSH       0x1
//         00519dd3     PUSH       EAX
//         00519dd4     PUSH       EAX
//         00519dd5     PUSH       EAX
//         00519dd6     MOV        dword ptr [ESP + local_4],EAX
//         00519dda     MOV        byte ptr [ESI + 0x2c0],AL
//         00519de0     MOV        dword ptr [ESI + 0x2c8],EAX
//         00519de6     MOV        dword ptr [ESI + 0x2cc],EAX
//         00519dec     MOV        byte ptr [ESI + 0x2d0],AL
//         00519df2     MOV        dword ptr [ESI + 0x3d0],EAX
//         00519df8     MOV        dword ptr [ESI + 0x2b8],EAX
//         00519dfe     MOV        dword ptr [ESI + 0x2bc],EAX
//         00519e04     PUSH       EAX
//         00519e05     MOV        EAX,dword ptr [ESP + param_2]
//         00519e09     MOV        dword ptr [ESI + 0x2c4],this
//         00519e0f     MOV        this,dword ptr [ESP + param_1]
//         00519e13     PUSH       EAX
//         00519e14     PUSH       this
//         00519e15     MOV        this,ESI
//         00519e17     MOV        dword ptr [ESI],TRIBE_Panel_Button::`vftable'    = 00519e70
//         00519e1d     CALL       TButtonPanel::setup                              long setup(TButtonPanel * this, TDrawArea * p
//         00519e22     TEST       EAX,EAX
//         00519e24     JNZ        LAB_00519e44
//                              tpnl_btn.cpp:63 (10)
//         00519e26     MOV        dword ptr [ESI + 0xd8],0x1
//                              tpnl_btn.cpp:68 (20)
//         00519e30     MOV        EAX,ESI
//         00519e32     MOV        this,dword ptr [ESP + local_c]
//         00519e36     MOV        dword ptr FS:[0x0],this
//         00519e3d     POP        ESI
//         00519e3e     ADD        ESP,0x10
//         00519e41     RET        0x1c
//                               LAB_00519e44                                                 XREF[1]:     00519e24(j)
//                              tpnl_btn.cpp:67 (22)
//         00519e44     MOV        EDX,dword ptr [ESP + param_6]
//         00519e48     MOV        EAX,dword ptr [ESP + param_5]
//         00519e4c     MOV        this,dword ptr [ESP + param_4]
//         00519e50     PUSH       EDX
//         00519e51     PUSH       EAX
//         00519e52     PUSH       this
//         00519e53     MOV        this,ESI
//         00519e55     CALL       TButtonPanel::set_font                           void set_font(TButtonPanel * this, void * par
//                              tpnl_btn.cpp:68 (20)
//         00519e5a     MOV        this,dword ptr [ESP + local_c]
//         00519e5e     MOV        EAX,ESI
//         00519e60     MOV        dword ptr FS:[0x0],this
//         00519e67     POP        ESI
//         00519e68     ADD        ESP,0x10
//         00519e6b     RET        0x1c
//         00519e6e     ??         90h
//         00519e6f     NOP
}

void TRIBE_Panel_Button::set_text_msg(char* param_1) {
    /* TODO: Stub */
//                              void __thiscall set_text_msg(TRIBE_Panel_Button * this, char * param
//              void              <VOID>         <RETURN>
//              TRIBE_Panel_Bu    ECX:4 (auto)   this
//              char *            Stack[0x4]:4   param_1                   XREF[1]:     00519ea0(R)
//                               ?set_text_msg@TRIBE_Panel_Button@@QAEXPAD@Z                  XREF[2]:     TRIBE_Screen_Game:00494825(c),
//                               TRIBE_Panel_Button::set_text_msg                                          set_button:0049ac5f(c)
//                              tpnl_btn.cpp:74 (11)
//         00519ea0     MOV        EAX,dword ptr [ESP + param_1]
//         00519ea4     PUSH       ESI
//         00519ea5     TEST       EAX,EAX
//         00519ea7     MOV        ESI,this
//         00519ea9     JNZ        LAB_00519eb5
//                              tpnl_btn.cpp:76 (6)
//         00519eab     MOV        byte ptr [ESI + 0x2d0],AL
//                              tpnl_btn.cpp:82 (4)
//         00519eb1     POP        ESI
//         00519eb2     RET        0x4
//                               LAB_00519eb5                                                 XREF[1]:     00519ea9(j)
//                              tpnl_btn.cpp:79 (21)
//         00519eb5     PUSH       0x100
//         00519eba     PUSH       EAX
//         00519ebb     LEA        EAX,[ESI + 0x2d0]
//         00519ec1     PUSH       EAX
//         00519ec2     CALL       strncpy                                          undefined strncpy()
//         00519ec7     ADD        ESP,0xc
//                              tpnl_btn.cpp:80 (7)
//         00519eca     MOV        byte ptr [ESI + 0x3cf],0x0
//                              tpnl_btn.cpp:82 (4)
//         00519ed1     POP        ESI
//         00519ed2     RET        0x4
//         00519ed5     ??         90h
//         00519ed6     NOP
//         00519ed7     NOP
//         00519ed8     NOP
//         00519ed9     NOP
//         00519eda     NOP
//         00519edb     NOP
//         00519edc     NOP
//         00519edd     NOP
//         00519ede     NOP
//         00519edf     NOP
    return;
}

int TRIBE_Panel_Button::is_inside(long param_1, long param_2) {
    /* TODO: Stub */
//                              int __thiscall is_inside(TRIBE_Panel_Button * this, long param_1, lo
//              int               EAX:4          <RETURN>
//              TRIBE_Panel_Bu    ECX:4 (auto)   this
//              long              Stack[0x4]:4   param_1                   XREF[1]:     00519ee1(R)
//              long              Stack[0x8]:4   param_2                   XREF[1]:     00519ee7(R)
//                               ?is_inside@TRIBE_Panel_Button@@UAEHJJ@Z                      XREF[1]:     00576b8c(*)
//                               TRIBE_Panel_Button::is_inside
//                              tpnl_btn.cpp:88 (1)
//         00519ee0     PUSH       EBX
//                              tpnl_btn.cpp:89 (23)
//         00519ee1     MOV        EBX,dword ptr [ESP + param_1]
//         00519ee5     PUSH       ESI
//         00519ee6     PUSH       EDI
//         00519ee7     MOV        EDI,dword ptr [ESP + param_2]
//         00519eeb     MOV        ESI,this
//         00519eed     PUSH       EDI
//         00519eee     PUSH       EBX
//         00519eef     CALL       TPanel::is_inside                                int is_inside(TPanel * this, long param_1, lo
//         00519ef4     TEST       EAX,EAX
//         00519ef6     JNZ        LAB_00519efe
//                              tpnl_btn.cpp:100 (6)
//         00519ef8     POP        EDI
//         00519ef9     POP        ESI
//         00519efa     POP        EBX
//         00519efb     RET        0x8
//                               LAB_00519efe                                                 XREF[1]:     00519ef6(j)
//                              tpnl_btn.cpp:92 (14)
//         00519efe     MOV        AL,byte ptr [ESI + 0x2c0]
//         00519f04     CMP        AL,0x2
//         00519f06     JZ         LAB_00519f0c
//         00519f08     CMP        AL,0x3
//         00519f0a     JNZ        LAB_00519f2f
//                               LAB_00519f0c                                                 XREF[1]:     00519f06(j)
//                              tpnl_btn.cpp:94 (9)
//         00519f0c     MOV        EAX,dword ptr [ESI + 0x40]
//         00519f0f     MOV        this,dword ptr [EAX + 0x4bc]
//                              tpnl_btn.cpp:95 (18)
//         00519f15     TEST       this,this
//         00519f17     JZ         LAB_00519f2f
//         00519f19     MOV        EDX,dword ptr [this->_padding_]
//         00519f1b     PUSH       EDI
//         00519f1c     PUSH       EBX
//         00519f1d     CALL       dword ptr [EDX + 0xbc]
//         00519f23     TEST       EAX,EAX
//         00519f25     JZ         LAB_00519f2f
//                              tpnl_btn.cpp:96 (2)
//         00519f27     XOR        EAX,EAX
//                              tpnl_btn.cpp:100 (17)
//         00519f29     POP        EDI
//         00519f2a     POP        ESI
//         00519f2b     POP        EBX
//         00519f2c     RET        0x8
//                               LAB_00519f2f                                                 XREF[3]:     00519f0a(j), 00519f17(j),
//                                                                                                         00519f25(j)
//         00519f2f     POP        EDI
//         00519f30     POP        ESI
//         00519f31     MOV        EAX,0x1
//         00519f36     POP        EBX
//         00519f37     RET        0x8
//         00519f3a     ??         90h
//         00519f3b     NOP
//         00519f3c     NOP
//         00519f3d     NOP
//         00519f3e     NOP
//         00519f3f     NOP
    return 0;
}

void TRIBE_Panel_Button::draw() {
    /* TODO: Stub */
//                              void __thiscall draw(TRIBE_Panel_Button * this)
//              void              <VOID>         <RETURN>
//              TRIBE_Panel_Bu    ECX:4 (auto)   this
//              char[10]          Stack[-0x10]   msg
//              tagSIZE           Stack[-0x18]:8 text_size                 XREF[1]:     00519f86(W)
//              void *            Stack[-0x20]:4 old_font
//              short             Stack[-0x24]:2 frame
//              long              Stack[-0x28]:4 x
//              char *            Stack[-0x2c]:4 text
//              long              Stack[-0x30]:4 y
//                               ?draw@TRIBE_Panel_Button@@UAEXXZ                             XREF[1]:     00576b00(*)
//                               TRIBE_Panel_Button::draw
//                              tpnl_btn.cpp:109 (9)
//         00519f40     SUB        ESP,0x2c
//         00519f43     PUSH       EBX
//         00519f44     PUSH       EBP
//         00519f45     PUSH       ESI
//         00519f46     MOV        ESI,this
//         00519f48     PUSH       EDI
//                              tpnl_btn.cpp:120 (9)
//         00519f49     CMP        byte ptr [ESI + 0x2c0],0x3
//         00519f50     JNZ        LAB_00519f5f
//                              tpnl_btn.cpp:122 (5)
//         00519f52     CALL       TButtonPanel::draw                               void draw(TButtonPanel * this)
//                              tpnl_btn.cpp:317 (8)
//         00519f57     POP        EDI
//         00519f58     POP        ESI
//         00519f59     POP        EBP
//         00519f5a     POP        EBX
//         00519f5b     ADD        ESP,0x2c
//         00519f5e     RET
//                               LAB_00519f5f                                                 XREF[1]:     00519f50(j)
//                              tpnl_btn.cpp:126 (33)
//         00519f5f     MOV        EAX,dword ptr [ESI + 0x20]
//         00519f62     TEST       EAX,EAX
//         00519f64     JZ         LAB_0051a556
//         00519f6a     MOV        EAX,dword ptr [ESI + 0x70]
//         00519f6d     TEST       EAX,EAX
//         00519f6f     JZ         LAB_0051a556
//         00519f75     MOV        EAX,dword ptr [ESI + 0x6c]
//         00519f78     TEST       EAX,EAX
//         00519f7a     JZ         LAB_0051a556
//                              tpnl_btn.cpp:132 (13)
//         00519f80     MOV        EAX,dword ptr [ESI]
//         00519f82     PUSH       0x0
//         00519f84     MOV        this,ESI
//         00519f86     MOV        dword ptr [ESP + text_size.cx],EAX
//         00519f8a     CALL       dword ptr [EAX + 0x28]
//                              tpnl_btn.cpp:134 (12)
//         00519f8d     MOV        this,dword ptr [ESI + 0x40]
//         00519f90     LEA        EBP,[ESI + 0x24]
//         00519f93     PUSH       EBP
//         00519f94     MOV        EAX,dword ptr [this->_padding_]
//         00519f96     CALL       dword ptr [EAX + 0x34]
//                              tpnl_btn.cpp:139 (19)
//         00519f99     MOV        AL,byte ptr [ESI + 0x2c0]
//         00519f9f     MOV        EDI,0x1
//         00519fa4     TEST       AL,AL
//         00519fa6     JZ         LAB_00519fac
//         00519fa8     CMP        AL,0x1
//         00519faa     JNZ        LAB_0051a007
//                               LAB_00519fac                                                 XREF[1]:     00519fa6(j)
//                              tpnl_btn.cpp:141 (29)
//         00519fac     MOV        EAX,dword ptr [ESI + 0x2c4]
//         00519fb2     TEST       EAX,EAX
//         00519fb4     JZ         LAB_0051a007
//         00519fb6     MOV        this,dword ptr [ESI + 0x20]
//         00519fb9     PUSH       0x1
//         00519fbb     PUSH       s_tpnl_btn::draw                                 = "tpnl_btn::draw"
//         00519fc0     CALL       TDrawArea::Lock                                  uchar * Lock(TDrawArea * this, char * param_1
//         00519fc5     TEST       EAX,EAX
//         00519fc7     JZ         LAB_0051a007
//                              tpnl_btn.cpp:144 (49)
//         00519fc9     MOV        EAX,dword ptr [ESI + 0x1f8]
//         00519fcf     MOV        EBX,dword ptr [ESI + 0x2cc]
//         00519fd5     MOV        EDX,dword ptr [ESI + 0x10]
//         00519fd8     XOR        EDI,EDI
//         00519fda     XOR        this,this
//         00519fdc     PUSH       EDI
//         00519fdd     TEST       EAX,EAX
//         00519fdf     MOV        EAX,dword ptr [ESI + 0xc]
//         00519fe2     PUSH       EDI=>DAT_fffffff8
//         00519fe3     SETNZ      this
//         00519fe6     ADD        this,EBX
//         00519fe8     PUSH       this=>DAT_fffffff4
//         00519fe9     MOV        this,dword ptr [ESI + 0x20]
//         00519fec     PUSH       EDX=>DAT_fffffff0
//         00519fed     PUSH       EAX
//         00519fee     PUSH       this
//         00519fef     MOV        this,dword ptr [ESI + 0x2c4]
//         00519ff5     CALL       TShape::shape_draw                               uchar shape_draw(TShape * this, TDrawArea * p
//                              tpnl_btn.cpp:145 (13)
//         00519ffa     MOV        this,dword ptr [ESI + 0x20]
//         00519ffd     PUSH       s_tpnl_btn::draw                                 = "tpnl_btn::draw"
//         0051a002     CALL       TDrawArea::Unlock                                void Unlock(TDrawArea * this, char * param_1)
//                               LAB_0051a007                                                 XREF[3]:     00519faa(j), 00519fb4(j),
//                                                                                                         00519fc7(j)
//                              tpnl_btn.cpp:149 (4)
//         0051a007     TEST       EDI,EDI
//         0051a009     JZ         LAB_0051a014
//                              tpnl_btn.cpp:150 (9)
//         0051a00b     MOV        this,dword ptr [ESI + 0x40]
//         0051a00e     PUSH       EBP
//         0051a00f     MOV        EDX,dword ptr [this->_padding_]
//         0051a011     CALL       dword ptr [EDX + 0x34]
//                               LAB_0051a014                                                 XREF[1]:     0051a009(j)
//                              tpnl_btn.cpp:156 (32)
//         0051a014     MOV        AL,byte ptr [ESI + 0x2c0]
//         0051a01a     CMP        AL,0x1
//         0051a01c     JZ         LAB_0051a026
//         0051a01e     CMP        AL,0x3
//         0051a020     JNZ        LAB_0051a2c8
//                               LAB_0051a026                                                 XREF[1]:     0051a01c(j)
//         0051a026     MOV        EAX,dword ptr [ESI + 0x198]
//         0051a02c     TEST       EAX,EAX
//         0051a02e     JZ         LAB_0051a2c8
//                              tpnl_btn.cpp:158 (15)
//         0051a034     MOV        this,dword ptr [ESI + 0x20]
//         0051a037     PUSH       s_tpnl_btn::draw                                 = "tpnl_btn::draw"
//         0051a03c     CALL       TDrawArea::GetDc                                 void * GetDc(TDrawArea * this, char * param_1)
//         0051a041     MOV        EBP,EAX
//                              tpnl_btn.cpp:159 (8)
//         0051a043     TEST       EBP,EBP
//         0051a045     JZ         LAB_0051a46c
//                              tpnl_btn.cpp:161 (14)
//         0051a04b     MOV        EAX,dword ptr [ESI + 0x88]
//         0051a051     PUSH       EAX
//         0051a052     PUSH       EBP=>DAT_fffffff8
//         0051a053     CALL       dword ptr [->GDI32.DLL::SelectClipRgn]           = 0048b2fc
//                              tpnl_btn.cpp:162 (14)
//         0051a059     MOV        this,dword ptr [ESI + 0x1e8]
//         0051a05f     PUSH       this
//         0051a060     PUSH       EBP=>DAT_fffffff8
//         0051a061     CALL       dword ptr [->GDI32.DLL::SelectObject]            = 0048b192
//                              tpnl_btn.cpp:163 (13)
//         0051a067     PUSH       0x1
//         0051a069     PUSH       EBP=>DAT_fffffff8
//         0051a06a     MOV        dword ptr [ESP + 0x28],EAX
//         0051a06e     CALL       dword ptr [->GDI32.DLL::SetBkMode]               = 0048b340
//                              tpnl_btn.cpp:165 (8)
//         0051a074     MOV        EAX,dword ptr [ESI + 0x14]
//         0051a077     CDQ
//         0051a078     SUB        EAX,EDX
//         0051a07a     MOV        EBX,EAX
//                              tpnl_btn.cpp:166 (6)
//         0051a07c     MOV        EAX,dword ptr [ESI + 0x18]
//         0051a07f     CDQ
//         0051a080     SUB        EAX,EDX
//                              tpnl_btn.cpp:169 (26)
//         0051a082     MOVSX      EDX,word ptr [ESI + 0x1f6]
//         0051a089     SAR        EAX,0x1
//         0051a08b     MOV        dword ptr [ESP + 0x1c],EAX
//         0051a08f     MOV        EAX,dword ptr [ESI + EDX*0x4 + 0x198]
//         0051a096     SAR        EBX,0x1
//         0051a098     TEST       EAX,EAX
//         0051a09a     JZ         LAB_0051a0a4
//                              tpnl_btn.cpp:170 (6)
//         0051a09c     MOV        EDX,EAX
//         0051a09e     MOV        dword ptr [ESP + 0x14],EDX
//                              tpnl_btn.cpp:171 (2)
//         0051a0a2     JMP        LAB_0051a0b0
//                               LAB_0051a0a4                                                 XREF[1]:     0051a09a(j)
//                              tpnl_btn.cpp:172 (12)
//         0051a0a4     MOV        EAX,dword ptr [ESI + 0x198]
//         0051a0aa     MOV        dword ptr [ESP + 0x14],EAX
//         0051a0ae     MOV        EDX,EAX
//                               LAB_0051a0b0                                                 XREF[1]:     0051a0a2(j)
//                              tpnl_btn.cpp:174 (8)
//         0051a0b0     TEST       EDX,EDX
//         0051a0b2     JZ         LAB_0051a2a1
//                              tpnl_btn.cpp:176 (12)
//         0051a0b8     MOV        EDI,EDX
//         0051a0ba     OR         this,0xffffffff
//         0051a0bd     XOR        EAX,EAX
//         0051a0bf     SCASB.RE   ES:EDI
//         0051a0c1     NOT        this
//         0051a0c3     DEC        this
//                              tpnl_btn.cpp:177 (21)
//         0051a0c4     MOVSX      EAX,this
//         0051a0c7     LEA        this,[ESP + 0x28]
//         0051a0cb     MOV        dword ptr [ESP + 0x18],EAX
//         0051a0cf     PUSH       this
//         0051a0d0     PUSH       EAX=>DAT_fffffff8
//         0051a0d1     PUSH       EDX=>DAT_fffffff4
//         0051a0d2     PUSH       EBP=>DAT_fffffff0
//         0051a0d3     CALL       dword ptr [->GDI32.DLL::GetTextExtentPoint32A]   = 0048b328
//                              tpnl_btn.cpp:179 (18)
//         0051a0d9     MOV        EAX,dword ptr [ESP + 0x28]
//         0051a0dd     MOV        this,dword ptr [ESI + 0xc]
//         0051a0e0     CDQ
//         0051a0e1     SUB        EAX,EDX
//         0051a0e3     MOV        EDI,EBX
//         0051a0e5     SAR        EAX,0x1
//         0051a0e7     SUB        EDI,EAX
//         0051a0e9     ADD        EDI,this
//                              tpnl_btn.cpp:181 (18)
//         0051a0eb     MOVSX      this,word ptr [ESI + 0x1f6]
//         0051a0f2     MOV        EAX,dword ptr [ESI + this->_padding_*0x4 + 0x1
//         0051a0f9     TEST       EAX,EAX
//         0051a0fb     JZ         LAB_0051a114
//                              tpnl_btn.cpp:182 (21)
//         0051a0fd     MOV        EAX,dword ptr [ESP + 0x1c]
//         0051a101     MOV        EDX,dword ptr [ESI + 0x1f0]
//         0051a107     SUB        EAX,EDX
//         0051a109     MOV        EDX,dword ptr [ESI + 0x10]
//         0051a10c     ADD        EAX,EDX
//         0051a10e     MOV        dword ptr [ESP + 0x10],EAX
//                              tpnl_btn.cpp:183 (2)
//         0051a112     JMP        LAB_0051a130
//                               LAB_0051a114                                                 XREF[1]:     0051a0fb(j)
//                              tpnl_btn.cpp:184 (28)
//         0051a114     MOV        EAX,dword ptr [ESI + 0x1f0]
//         0051a11a     CDQ
//         0051a11b     SUB        EAX,EDX
//         0051a11d     MOV        EDX,EAX
//         0051a11f     MOV        EAX,dword ptr [ESP + 0x1c]
//         0051a123     SAR        EDX,0x1
//         0051a125     SUB        EAX,EDX
//         0051a127     MOV        EDX,dword ptr [ESI + 0x10]
//         0051a12a     ADD        EAX,EDX
//         0051a12c     MOV        dword ptr [ESP + 0x10],EAX
//                               LAB_0051a130                                                 XREF[1]:     0051a112(j)
//                              tpnl_btn.cpp:186 (32)
//         0051a130     MOV        EDX,dword ptr [ESI + 0x194]
//         0051a136     TEST       EDX,EDX
//         0051a138     JNZ        LAB_0051a146
//         0051a13a     CMP        dword ptr [ESI + 0x1f8],EDX
//         0051a140     JNZ        LAB_0051a150
//         0051a142     TEST       EDX,EDX
//         0051a144     JZ         LAB_0051a156
//                               LAB_0051a146                                                 XREF[1]:     0051a138(j)
//         0051a146     MOV        EDX,dword ptr [ESI + 0x1f8]
//         0051a14c     TEST       EDX,EDX
//         0051a14e     JNZ        LAB_0051a156
//                               LAB_0051a150                                                 XREF[1]:     0051a140(j)
//                              tpnl_btn.cpp:188 (1)
//         0051a150     INC        EDI
//                              tpnl_btn.cpp:189 (5)
//         0051a151     INC        EAX
//         0051a152     MOV        dword ptr [ESP + 0x10],EAX
//                               LAB_0051a156                                                 XREF[2]:     0051a144(j), 0051a14e(j)
//                              tpnl_btn.cpp:192 (15)
//         0051a156     MOV        EAX,dword ptr [ESI + this->_padding_*0x4 + 0x2
//         0051a15d     PUSH       EAX
//         0051a15e     PUSH       EBP=>DAT_fffffff8
//         0051a15f     CALL       dword ptr [->GDI32.DLL::SetTextColor]            = 0048b318
//                              tpnl_btn.cpp:193 (27)
//         0051a165     MOV        this,dword ptr [ESP + 0x18]
//         0051a169     MOV        EAX,dword ptr [ESP + 0x10]
//         0051a16d     MOV        EDX,dword ptr [ESP + 0x14]
//         0051a171     PUSH       this
//         0051a172     INC        EAX
//         0051a173     PUSH       EDX=>DAT_fffffff8
//         0051a174     LEA        this,[EDI + -0x1]
//         0051a177     PUSH       EAX=>DAT_fffffff4
//         0051a178     PUSH       this=>DAT_fffffff0
//         0051a179     PUSH       EBP
//         0051a17a     CALL       dword ptr [->GDI32.DLL::TextOutA]                = 0048b30c
//                              tpnl_btn.cpp:194 (22)
//         0051a180     MOVSX      EDX,word ptr [ESI + 0x1f6]
//         0051a187     MOV        EAX,dword ptr [ESI + EDX*0x4 + 0x208]
//         0051a18e     PUSH       EAX
//         0051a18f     PUSH       EBP=>DAT_fffffff8
//         0051a190     CALL       dword ptr [->GDI32.DLL::SetTextColor]            = 0048b318
//                              tpnl_btn.cpp:195 (23)
//         0051a196     MOV        this,dword ptr [ESP + 0x18]
//         0051a19a     MOV        EDX,dword ptr [ESP + 0x14]
//         0051a19e     MOV        EAX,dword ptr [ESP + 0x10]
//         0051a1a2     PUSH       this
//         0051a1a3     PUSH       EDX=>DAT_fffffff8
//         0051a1a4     PUSH       EAX=>DAT_fffffff4
//         0051a1a5     PUSH       EDI=>DAT_fffffff0
//         0051a1a6     PUSH       EBP
//         0051a1a7     CALL       dword ptr [->GDI32.DLL::TextOutA]                = 0048b30c
//                              tpnl_btn.cpp:198 (18)
//         0051a1ad     MOVSX      this,word ptr [ESI + 0x1f6]
//         0051a1b4     MOV        EDX,dword ptr [ESI + this->_padding_*0x4 + 0x1
//         0051a1bb     TEST       EDX,EDX
//         0051a1bd     JZ         LAB_0051a1c5
//                              tpnl_btn.cpp:199 (4)
//         0051a1bf     MOV        dword ptr [ESP + 0x14],EDX
//                              tpnl_btn.cpp:200 (2)
//         0051a1c3     JMP        LAB_0051a1cf
//                               LAB_0051a1c5                                                 XREF[1]:     0051a1bd(j)
//                              tpnl_btn.cpp:201 (10)
//         0051a1c5     MOV        EDX,dword ptr [ESI + 0x1bc]
//         0051a1cb     MOV        dword ptr [ESP + 0x14],EDX
//                               LAB_0051a1cf                                                 XREF[1]:     0051a1c3(j)
//                              tpnl_btn.cpp:203 (8)
//         0051a1cf     TEST       EDX,EDX
//         0051a1d1     JZ         LAB_0051a2a1
//                              tpnl_btn.cpp:205 (12)
//         0051a1d7     MOV        EDI,EDX
//         0051a1d9     OR         this,0xffffffff
//         0051a1dc     XOR        EAX,EAX
//         0051a1de     SCASB.RE   ES:EDI
//         0051a1e0     NOT        this
//         0051a1e2     DEC        this
//                              tpnl_btn.cpp:206 (17)
//         0051a1e3     LEA        EAX,[ESP + 0x28]
//         0051a1e7     MOVSX      EDI,this
//         0051a1ea     PUSH       EAX
//         0051a1eb     PUSH       EDI=>DAT_fffffff8
//         0051a1ec     PUSH       EDX=>DAT_fffffff4
//         0051a1ed     PUSH       EBP=>DAT_fffffff0
//         0051a1ee     CALL       dword ptr [->GDI32.DLL::GetTextExtentPoint32A]   = 0048b328
//                              tpnl_btn.cpp:208 (7)
//         0051a1f4     MOV        EAX,dword ptr [ESP + 0x28]
//         0051a1f8     CDQ
//         0051a1f9     SUB        EAX,EDX
//                              tpnl_btn.cpp:209 (26)
//         0051a1fb     MOV        EDX,dword ptr [ESI + 0x10]
//         0051a1fe     SAR        EAX,0x1
//         0051a200     SUB        EBX,EAX
//         0051a202     MOV        EAX,dword ptr [ESI + 0xc]
//         0051a205     ADD        EBX,EAX
//         0051a207     MOV        EAX,dword ptr [ESP + 0x1c]
//         0051a20b     ADD        EAX,EDX
//         0051a20d     MOV        dword ptr [ESP + 0x18],EBX
//         0051a211     MOV        dword ptr [ESP + 0x10],EAX
//                              tpnl_btn.cpp:211 (34)
//         0051a215     MOV        EAX,dword ptr [ESI + 0x194]
//         0051a21b     TEST       EAX,EAX
//         0051a21d     JNZ        LAB_0051a22d
//         0051a21f     MOV        this,dword ptr [ESI + 0x1f8]
//         0051a225     TEST       this,this
//         0051a227     JNZ        LAB_0051a237
//         0051a229     TEST       EAX,EAX
//         0051a22b     JZ         LAB_0051a249
//                               LAB_0051a22d                                                 XREF[1]:     0051a21d(j)
//         0051a22d     MOV        EAX,dword ptr [ESI + 0x1f8]
//         0051a233     TEST       EAX,EAX
//         0051a235     JNZ        LAB_0051a249
//                               LAB_0051a237                                                 XREF[1]:     0051a227(j)
//                              tpnl_btn.cpp:213 (4)
//         0051a237     MOV        this,dword ptr [ESP + 0x18]
//                              tpnl_btn.cpp:214 (14)
//         0051a23b     MOV        EAX,dword ptr [ESP + 0x10]
//         0051a23f     INC        this
//         0051a240     INC        EAX
//         0051a241     MOV        dword ptr [ESP + 0x18],this
//         0051a245     MOV        dword ptr [ESP + 0x10],EAX
//                               LAB_0051a249                                                 XREF[2]:     0051a22b(j), 0051a235(j)
//                              tpnl_btn.cpp:217 (22)
//         0051a249     MOVSX      this,word ptr [ESI + 0x1f6]
//         0051a250     MOV        EDX,dword ptr [ESI + this->_padding_*0x4 + 0x2
//         0051a257     PUSH       EDX
//         0051a258     PUSH       EBP=>DAT_fffffff8
//         0051a259     CALL       dword ptr [->GDI32.DLL::SetTextColor]            = 0048b318
//                              tpnl_btn.cpp:218 (25)
//         0051a25f     MOV        EAX,dword ptr [ESP + 0x10]
//         0051a263     MOV        EBX,dword ptr [ESP + 0x14]
//         0051a267     MOV        this,dword ptr [ESP + 0x18]
//         0051a26b     PUSH       EDI
//         0051a26c     INC        EAX
//         0051a26d     PUSH       EBX=>DAT_fffffff8
//         0051a26e     DEC        this
//         0051a26f     PUSH       EAX=>DAT_fffffff4
//         0051a270     PUSH       this=>DAT_fffffff0
//         0051a271     PUSH       EBP
//         0051a272     CALL       dword ptr [->GDI32.DLL::TextOutA]                = 0048b30c
//                              tpnl_btn.cpp:219 (22)
//         0051a278     MOVSX      EDX,word ptr [ESI + 0x1f6]
//         0051a27f     MOV        EAX,dword ptr [ESI + EDX*0x4 + 0x208]
//         0051a286     PUSH       EAX
//         0051a287     PUSH       EBP=>DAT_fffffff8
//         0051a288     CALL       dword ptr [->GDI32.DLL::SetTextColor]            = 0048b318
//                              tpnl_btn.cpp:220 (19)
//         0051a28e     MOV        this,dword ptr [ESP + 0x10]
//         0051a292     MOV        EDX,dword ptr [ESP + 0x18]
//         0051a296     PUSH       EDI
//         0051a297     PUSH       EBX=>DAT_fffffff8
//         0051a298     PUSH       this=>DAT_fffffff4
//         0051a299     PUSH       EDX=>DAT_fffffff0
//         0051a29a     PUSH       EBP
//         0051a29b     CALL       dword ptr [->GDI32.DLL::TextOutA]                = 0048b30c
//                               LAB_0051a2a1                                                 XREF[2]:     0051a0b2(j), 0051a1d1(j)
//                              tpnl_btn.cpp:224 (12)
//         0051a2a1     MOV        EAX,dword ptr [ESP + 0x20]
//         0051a2a5     PUSH       EAX
//         0051a2a6     PUSH       EBP=>DAT_fffffff8
//         0051a2a7     CALL       dword ptr [->GDI32.DLL::SelectObject]            = 0048b192
//                              tpnl_btn.cpp:225 (9)
//         0051a2ad     PUSH       0x0
//         0051a2af     PUSH       EBP=>DAT_fffffff8
//         0051a2b0     CALL       dword ptr [->GDI32.DLL::SelectClipRgn]           = 0048b2fc
//                              tpnl_btn.cpp:226 (13)
//         0051a2b6     MOV        this,dword ptr [ESI + 0x20]
//         0051a2b9     PUSH       s_tpnl_btn::draw                                 = "tpnl_btn::draw"
//         0051a2be     CALL       TDrawArea::ReleaseDc                             void ReleaseDc(TDrawArea * this, char * param
//                              tpnl_btn.cpp:230 (33)
//         0051a2c3     JMP        LAB_0051a46c
//                               LAB_0051a2c8                                                 XREF[2]:     0051a020(j), 0051a02e(j)
//         0051a2c8     MOV        EAX,dword ptr [ESI + 0x14c]
//         0051a2ce     TEST       EAX,EAX
//         0051a2d0     JZ         LAB_0051a46c
//         0051a2d6     CMP        word ptr [ESI + 0x170],0x0
//         0051a2de     JL         LAB_0051a46c
//                              tpnl_btn.cpp:232 (23)
//         0051a2e4     MOV        this,dword ptr [ESI + 0x20]
//         0051a2e7     PUSH       0x1
//         0051a2e9     PUSH       s_tpnl_btn::draw3                                = "tpnl_btn::draw3"
//         0051a2ee     CALL       TDrawArea::Lock                                  uchar * Lock(TDrawArea * this, char * param_1
//         0051a2f3     TEST       EAX,EAX
//         0051a2f5     JZ         LAB_0051a46c
//                              tpnl_btn.cpp:237 (21)
//         0051a2fb     MOV        AL,byte ptr [ESI + 0x2c0]
//         0051a301     MOV        this,word ptr [ESI + 0x170]
//         0051a308     TEST       AL,AL
//         0051a30a     MOV        dword ptr [ESP + 0x1c],this
//         0051a30e     JNZ        LAB_0051a37b
//                              tpnl_btn.cpp:239 (6)
//         0051a310     MOV        EAX,dword ptr [ESI + 0x1f8]
//                              tpnl_btn.cpp:241 (7)
//         0051a316     MOV        EDI,dword ptr [ESI + 0xc]
//         0051a319     TEST       EAX,EAX
//         0051a31b     JNZ        LAB_0051a34c
//                              tpnl_btn.cpp:243 (45)
//         0051a31d     MOV        this,dword ptr [ESI + 0x30]
//         0051a320     MOV        EDX,dword ptr [ESI + 0x2c]
//         0051a323     MOV        EAX,dword ptr [ESI + 0x28]
//         0051a326     MOV        EBX,dword ptr [ESI + 0x10]
//         0051a329     SUB        this,0x2
//         0051a32c     SUB        EDX,0x2
//         0051a32f     PUSH       this
//         0051a330     MOV        this,dword ptr [EBP]
//         0051a333     ADD        EAX,0x2
//         0051a336     PUSH       EDX=>DAT_fffffff8
//         0051a337     ADD        this,0x2
//         0051a33a     PUSH       EAX=>DAT_fffffff4
//         0051a33b     PUSH       this=>DAT_fffffff0
//         0051a33c     MOV        this,dword ptr [ESI + 0x20]
//         0051a33f     ADD        EDI,0x2
//         0051a342     ADD        EBX,0x2
//         0051a345     CALL       TDrawArea::SetClipRect                           void SetClipRect(TDrawArea * this, long param
//                              tpnl_btn.cpp:245 (2)
//         0051a34a     JMP        LAB_0051a3c3
//                               LAB_0051a34c                                                 XREF[1]:     0051a31b(j)
//                              tpnl_btn.cpp:250 (45)
//         0051a34c     MOV        EDX,dword ptr [ESI + 0x30]
//         0051a34f     MOV        EAX,dword ptr [ESI + 0x2c]
//         0051a352     MOV        this,dword ptr [ESI + 0x28]
//         0051a355     MOV        EBX,dword ptr [ESI + 0x10]
//         0051a358     SUB        EDX,0x3
//         0051a35b     SUB        EAX,0x2
//         0051a35e     PUSH       EDX
//         0051a35f     MOV        EDX,dword ptr [EBP]
//         0051a362     ADD        this,0x3
//         0051a365     PUSH       EAX=>DAT_fffffff8
//         0051a366     ADD        EDX,0x3
//         0051a369     PUSH       this=>DAT_fffffff4
//         0051a36a     MOV        this,dword ptr [ESI + 0x20]
//         0051a36d     PUSH       EDX=>DAT_fffffff0
//         0051a36e     ADD        EDI,0x3
//         0051a371     ADD        EBX,0x3
//         0051a374     CALL       TDrawArea::SetClipRect                           void SetClipRect(TDrawArea * this, long param
//                              tpnl_btn.cpp:254 (2)
//         0051a379     JMP        LAB_0051a3c3
//                               LAB_0051a37b                                                 XREF[1]:     0051a30e(j)
//                              tpnl_btn.cpp:256 (7)
//         0051a37b     MOV        EDI,dword ptr [ESI + 0xc]
//         0051a37e     CMP        AL,0x1
//         0051a380     JNZ        LAB_0051a3b1
//                              tpnl_btn.cpp:257 (3)
//         0051a382     MOV        EBX,dword ptr [ESI + 0x10]
//                              tpnl_btn.cpp:258 (30)
//         0051a385     MOV        EAX,dword ptr [ESI + 0x30]
//         0051a388     MOV        this,dword ptr [ESI + 0x2c]
//         0051a38b     MOV        EDX,dword ptr [ESI + 0x28]
//         0051a38e     INC        EDI
//         0051a38f     INC        EBX
//         0051a390     DEC        EAX
//         0051a391     DEC        this
//         0051a392     PUSH       EAX
//         0051a393     MOV        EAX,dword ptr [EBP]
//         0051a396     INC        EDX
//         0051a397     PUSH       this=>DAT_fffffff8
//         0051a398     MOV        this,dword ptr [ESI + 0x20]
//         0051a39b     INC        EAX
//         0051a39c     PUSH       EDX=>DAT_fffffff4
//         0051a39d     PUSH       EAX=>DAT_fffffff0
//         0051a39e     CALL       TDrawArea::SetClipRect                           void SetClipRect(TDrawArea * this, long param
//                              tpnl_btn.cpp:259 (10)
//         0051a3a3     MOV        EAX,dword ptr [ESI + 0x1f8]
//         0051a3a9     TEST       EAX,EAX
//         0051a3ab     JZ         LAB_0051a3c3
//                              tpnl_btn.cpp:261 (1)
//         0051a3ad     INC        EDI
//                              tpnl_btn.cpp:262 (1)
//         0051a3ae     INC        EBX
//                              tpnl_btn.cpp:266 (2)
//         0051a3af     JMP        LAB_0051a3c3
//                               LAB_0051a3b1                                                 XREF[1]:     0051a380(j)
//                              tpnl_btn.cpp:270 (13)
//         0051a3b1     MOV        EAX,dword ptr [ESI + 0x1f8]
//         0051a3b7     MOV        EBX,dword ptr [ESI + 0x10]
//         0051a3ba     TEST       EAX,EAX
//         0051a3bc     JZ         LAB_0051a3c3
//                              tpnl_btn.cpp:271 (5)
//         0051a3be     INC        this
//         0051a3bf     MOV        dword ptr [ESP + 0x1c],this
//                               LAB_0051a3c3                                                 XREF[5]:     0051a34a(j), 0051a379(j),
//                                                                                                         0051a3ab(j), 0051a3af(j),
//                                                                                                         0051a3bc(j)
//                              tpnl_btn.cpp:274 (10)
//         0051a3c3     MOV        EAX,dword ptr [ESI + 0x2b0]
//         0051a3c9     TEST       EAX,EAX
//         0051a3cb     JZ         LAB_0051a3ed
//                              tpnl_btn.cpp:277 (32)
//         0051a3cd     PUSH       0x0
//         0051a3cf     PUSH       offset DAT_fffffff8
//         0051a3d4     PUSH       0x0=>DAT_fffffff4
//         0051a3d6     PUSH       offset DAT_fffffff0
//         0051a3db     MOV        dword ptr [fog_next_shape],0x1
//         0051a3e5     CALL       _ASMSet_Shadowing                                undefined _ASMSet_Shadowing()
//         0051a3ea     ADD        ESP,0x10
//                               LAB_0051a3ed                                                 XREF[1]:     0051a3cb(j)
//                              tpnl_btn.cpp:280 (10)
//         0051a3ed     MOV        EAX,dword ptr [ESI + 0x2c8]
//         0051a3f3     TEST       EAX,EAX
//         0051a3f5     JZ         LAB_0051a430
//                              tpnl_btn.cpp:282 (31)
//         0051a3f7     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0051a3fd     CALL       RGE_Base_Game::get_player                        RGE_Player * get_player(RGE_Base_Game * this)
//         0051a402     MOV        this,dword ptr [EAX + 0x108]
//         0051a408     MOVSX      EDX,word ptr [ECX + this+0x26]
//         0051a40c     INC        EDX
//         0051a40d     SHL        EDX,0x4
//         0051a410     PUSH       EDX
//         0051a411     CALL       _ASMSet_Color_Xform                              undefined _ASMSet_Color_Xform()
//                              tpnl_btn.cpp:283 (24)
//         0051a416     MOV        EAX,dword ptr [ESI + 0x2c8]
//         0051a41c     MOV        EDX,dword ptr [ESI + 0x20]
//         0051a41f     MOVSX      this,word ptr [ESP + 0x20]
//         0051a424     ADD        ESP,0x4
//         0051a427     PUSH       EAX
//         0051a428     PUSH       offset DAT_fffffff8
//         0051a42a     PUSH       this=>DAT_fffffff4
//         0051a42b     PUSH       EBX=>DAT_fffffff0
//         0051a42c     PUSH       EDI
//         0051a42d     PUSH       EDX
//                              tpnl_btn.cpp:285 (2)
//         0051a42e     JMP        LAB_0051a440
//                               LAB_0051a430                                                 XREF[1]:     0051a3f5(j)
//                              tpnl_btn.cpp:286 (27)
//         0051a430     MOVSX      EAX,word ptr [ESP + 0x1c]
//         0051a435     MOV        this,dword ptr [ESI + 0x20]
//         0051a438     PUSH       0x0
//         0051a43a     PUSH       0x0=>DAT_fffffff8
//         0051a43c     PUSH       EAX=>DAT_fffffff4
//         0051a43d     PUSH       EBX=>DAT_fffffff0
//         0051a43e     PUSH       EDI
//         0051a43f     PUSH       this
//                               LAB_0051a440                                                 XREF[1]:     0051a42e(j)
//         0051a440     MOV        this,dword ptr [ESI + 0x14c]
//         0051a446     CALL       TShape::shape_draw                               uchar shape_draw(TShape * this, TDrawArea * p
//                              tpnl_btn.cpp:288 (10)
//         0051a44b     MOV        EAX,dword ptr [ESI + 0x2b0]
//         0051a451     TEST       EAX,EAX
//         0051a453     JZ         LAB_0051a45f
//                              tpnl_btn.cpp:289 (10)
//         0051a455     MOV        dword ptr [fog_next_shape],0x0
//                               LAB_0051a45f                                                 XREF[1]:     0051a453(j)
//                              tpnl_btn.cpp:291 (13)
//         0051a45f     MOV        this,dword ptr [ESI + 0x20]
//         0051a462     PUSH       s_tpnl_btn::draw3                                = "tpnl_btn::draw3"
//         0051a467     CALL       TDrawArea::Unlock                                void Unlock(TDrawArea * this, char * param_1)
//                               LAB_0051a46c                                                 XREF[5]:     0051a045(j), 0051a2c3(j),
//                                                                                                         0051a2d0(j), 0051a2de(j),
//                                                                                                         0051a2f5(j)
//                              tpnl_btn.cpp:295 (14)
//         0051a46c     MOV        EAX,dword ptr [ESI + 0x2b8]
//         0051a472     TEST       EAX,EAX
//         0051a474     JZ         LAB_0051a545
//                              tpnl_btn.cpp:298 (14)
//         0051a47a     MOV        EAX,dword ptr [ESI + 0x2bc]
//         0051a480     TEST       EAX,EAX
//         0051a482     JLE        LAB_0051a545
//                              tpnl_btn.cpp:300 (21)
//         0051a488     MOV        this,dword ptr [ESI + 0x20]
//         0051a48b     PUSH       s_tpnl_btn::draw2                                = "tpnl_btn::draw2"
//         0051a490     CALL       TDrawArea::GetDc                                 void * GetDc(TDrawArea * this, char * param_1)
//         0051a495     TEST       EAX,EAX
//         0051a497     JZ         LAB_0051a545
//                              tpnl_btn.cpp:303 (22)
//         0051a49d     MOV        EDX,dword ptr [ESI + 0x2bc]
//         0051a4a3     LEA        EAX,[ESP + 0x30]
//         0051a4a7     PUSH       EDX
//         0051a4a8     PUSH       s_%d                                             = 6425h
//         0051a4ad     PUSH       EAX=>DAT_fffffff4
//         0051a4ae     CALL       sprintf                                          undefined sprintf()
//                              tpnl_btn.cpp:305 (23)
//         0051a4b3     MOV        EDX,dword ptr [ESI + 0x20]
//         0051a4b6     MOV        this,dword ptr [ESI + 0x88]
//         0051a4bc     ADD        ESP,0xc
//         0051a4bf     MOV        EAX,dword ptr [EDX + 0x38]
//         0051a4c2     PUSH       this
//         0051a4c3     PUSH       EAX=>DAT_fffffff8
//         0051a4c4     CALL       dword ptr [->GDI32.DLL::SelectClipRgn]           = 0048b2fc
//                              tpnl_btn.cpp:306 (15)
//         0051a4ca     MOV        this,dword ptr [ESI + 0x20]
//         0051a4cd     PUSH       0x1
//         0051a4cf     MOV        EDX,dword ptr [ECX + this->_padding_]
//         0051a4d2     PUSH       EDX=>DAT_fffffff8
//         0051a4d3     CALL       dword ptr [->GDI32.DLL::SetBkMode]               = 0048b340
//                              tpnl_btn.cpp:308 (18)
//         0051a4d9     MOV        EAX,dword ptr [ESI + 0x20]
//         0051a4dc     PUSH       0xcccccc
//         0051a4e1     MOV        this,dword ptr [EAX + 0x38]
//         0051a4e4     PUSH       this=>DAT_fffffff8
//         0051a4e5     CALL       dword ptr [->GDI32.DLL::SetTextColor]            = 0048b318
//                              tpnl_btn.cpp:309 (62)
//         0051a4eb     MOV        EAX,dword ptr [ESI + 0x1f8]
//         0051a4f1     XOR        EDX,EDX
//         0051a4f3     TEST       EAX,EAX
//         0051a4f5     SETNZ      DL
//         0051a4f8     LEA        EDI,[ESP + 0x30]
//         0051a4fc     OR         this,0xffffffff
//         0051a4ff     XOR        EAX,EAX
//         0051a501     SCASB.RE   ES:EDI
//         0051a503     NOT        this
//         0051a505     DEC        this
//         0051a506     LEA        EAX,[ESP + 0x30]
//         0051a50a     PUSH       this
//         0051a50b     MOV        this,dword ptr [ESI + 0x10]
//         0051a50e     PUSH       EAX=>DAT_fffffff8
//         0051a50f     LEA        EAX,[ECX + EDX*0x1 + this+0x2]
//         0051a513     MOV        this,dword ptr [ESI + 0xc]
//         0051a516     PUSH       EAX=>DAT_fffffff4
//         0051a517     MOV        EAX,dword ptr [ESI + 0x20]
//         0051a51a     LEA        EDX,[ECX + EDX*0x1 + this+0x3]
//         0051a51e     MOV        this,dword ptr [EAX + 0x38]
//         0051a521     PUSH       EDX=>DAT_fffffff0
//         0051a522     PUSH       this
//         0051a523     CALL       dword ptr [->GDI32.DLL::TextOutA]                = 0048b30c
//                              tpnl_btn.cpp:310 (15)
//         0051a529     MOV        EDX,dword ptr [ESI + 0x20]
//         0051a52c     PUSH       0x0
//         0051a52e     MOV        EAX,dword ptr [EDX + 0x38]
//         0051a531     PUSH       EAX=>DAT_fffffff8
//         0051a532     CALL       dword ptr [->GDI32.DLL::SelectClipRgn]           = 0048b2fc
//                              tpnl_btn.cpp:311 (13)
//         0051a538     MOV        this,dword ptr [ESI + 0x20]
//         0051a53b     PUSH       s_tpnl_inv::draw2                                = "tpnl_inv::draw2"
//         0051a540     CALL       TDrawArea::ReleaseDc                             void ReleaseDc(TDrawArea * this, char * param
//                               LAB_0051a545                                                 XREF[3]:     0051a474(j), 0051a482(j),
//                                                                                                         0051a497(j)
//                              tpnl_btn.cpp:316 (9)
//         0051a545     MOV        EDX,dword ptr [ESP + 0x24]
//         0051a549     MOV        this,ESI
//         0051a54b     CALL       dword ptr [EDX + 0x2c]
//                              tpnl_btn.cpp:317 (8)
//         0051a54e     POP        EDI
//         0051a54f     POP        ESI
//         0051a550     POP        EBP
//         0051a551     POP        EBX
//         0051a552     ADD        ESP,0x2c
//         0051a555     RET
//                               LAB_0051a556                                                 XREF[3]:     00519f64(j), 00519f6f(j),
//                                                                                                         00519f7a(j)
//                              tpnl_btn.cpp:128 (7)
//         0051a556     MOV        dword ptr [ESI + 0x38],0x0
//                              tpnl_btn.cpp:317 (8)
//         0051a55d     POP        EDI
//         0051a55e     POP        ESI
//         0051a55f     POP        EBP
//         0051a560     POP        EBX
//         0051a561     ADD        ESP,0x2c
//         0051a564     RET
//         0051a565     ??         90h
//         0051a566     NOP
//         0051a567     NOP
//         0051a568     NOP
//         0051a569     NOP
//         0051a56a     NOP
//         0051a56b     NOP
//         0051a56c     NOP
//         0051a56d     NOP
//         0051a56e     NOP
//         0051a56f     NOP
    return;
}

void TRIBE_Panel_Button::set_display_garrison(int param_1) {
    /* TODO: Stub */
//                              void __thiscall set_display_garrison(TRIBE_Panel_Button * this, int
//              void              <VOID>         <RETURN>
//              TRIBE_Panel_Bu    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     0051a570(R)
//                               ?set_display_garrison@TRIBE_Panel_Button@@QAEXH@Z            XREF[3]:     setup_buttons:0049a1d9(c),
//                               TRIBE_Panel_Button::set_display_garrison                                  setup_buttons:0049a1fa(c),
//                                                                                                         set_button:0049abce(c)
//                              tpnl_btn.cpp:320 (4)
//         0051a570     MOV        EAX,dword ptr [ESP + param_1]
//                              tpnl_btn.cpp:322 (13)
//         0051a574     MOV        EDX,dword ptr [this->_padding_]
//         0051a576     PUSH       0x1
//         0051a578     MOV        dword ptr [ECX + this->display_garrison],EAX
//         0051a57e     CALL       dword ptr [EDX + 0x20]
//                              tpnl_btn.cpp:323 (3)
//         0051a581     RET        0x4
//         0051a584     ??         90h
//         0051a585     NOP
//         0051a586     NOP
//         0051a587     NOP
//         0051a588     NOP
//         0051a589     NOP
//         0051a58a     NOP
//         0051a58b     NOP
//         0051a58c     NOP
//         0051a58d     NOP
//         0051a58e     NOP
//         0051a58f     NOP
    return;
}

void TRIBE_Panel_Button::set_garrison_number(int param_1) {
    /* TODO: Stub */
//                              void __thiscall set_garrison_number(TRIBE_Panel_Button * this, int p
//              void              <VOID>         <RETURN>
//              TRIBE_Panel_Bu    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     0051a590(R)
//                               ?set_garrison_number@TRIBE_Panel_Button@@QAEXH@Z             XREF[1]:     setup_buttons:0049a1e5(c)
//                               TRIBE_Panel_Button::set_garrison_number
//                              tpnl_btn.cpp:326 (4)
//         0051a590     MOV        EAX,dword ptr [ESP + param_1]
//                              tpnl_btn.cpp:328 (13)
//         0051a594     MOV        EDX,dword ptr [this->_padding_]
//         0051a596     PUSH       0x1
//         0051a598     MOV        dword ptr [ECX + this->garrsion_number],EAX
//         0051a59e     CALL       dword ptr [EDX + 0x20]
//                              tpnl_btn.cpp:329 (3)
//         0051a5a1     RET        0x4
//         0051a5a4     ??         90h
//         0051a5a5     NOP
//         0051a5a6     NOP
//         0051a5a7     NOP
//         0051a5a8     NOP
//         0051a5a9     NOP
//         0051a5aa     NOP
//         0051a5ab     NOP
//         0051a5ac     NOP
//         0051a5ad     NOP
//         0051a5ae     NOP
//         0051a5af     NOP
    return;
}

int TRIBE_Panel_Button::get_garrison_number() {
    /* TODO: Stub */
//                              int __thiscall get_garrison_number(TRIBE_Panel_Button * this)
//              int               EAX:4          <RETURN>
//              TRIBE_Panel_Bu    ECX:4 (auto)   this
//                               ?get_garrison_number@TRIBE_Panel_Button@@QAEHXZ
//                               TRIBE_Panel_Button::get_garrison_number
//                              tpnl_btn.cpp:332 (6)
//         0051a5b0     MOV        EAX,dword ptr [ECX + this->garrsion_number]
//                              tpnl_btn.cpp:334 (1)
//         0051a5b6     RET
//         0051a5b7     ??         90h
//         0051a5b8     NOP
//         0051a5b9     NOP
//         0051a5ba     NOP
//         0051a5bb     NOP
//         0051a5bc     NOP
//         0051a5bd     NOP
//         0051a5be     NOP
//         0051a5bf     NOP
    return 0;
}

TRIBE_Panel_Button::~TRIBE_Panel_Button() {
    /* TODO: Stub */
//                              void __thiscall ~TRIBE_Panel_Button(TRIBE_Panel_Button * this)
//              void              <VOID>         <RETURN>
//              TRIBE_Panel_Bu    ECX:4 (auto)   this
//                               ??1TRIBE_Panel_Button@@UAE@XZ                                XREF[1]:     `scalar_deleting_destructor':00519
//                               TRIBE_Panel_Button::~TRIBE_Panel_Button
//         00519e90     JMP        TButtonPanel::~TButtonPanel
//         00519e95     ??         90h
//         00519e96     NOP
//         00519e97     NOP
//         00519e98     NOP
//         00519e99     NOP
//         00519e9a     NOP
//         00519e9b     NOP
//         00519e9c     NOP
//         00519e9d     NOP
//         00519e9e     NOP
//         00519e9f     NOP
}

