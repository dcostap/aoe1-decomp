#include "../common.h"
#include "tpnl_pop.h"

TRIBE_Panel_Pop::TRIBE_Panel_Pop(TDrawArea* param_1, TPanel* param_2) {
    /* TODO: Stub */
//                              undefined __thiscall TRIBE_Panel_Pop(TRIBE_Panel_Pop * this, TDrawAr
//              undefined         <UNASSIGNED>   <RETURN>
//              TRIBE_Panel_Po    ECX:4 (auto)   this
//              TDrawArea *       Stack[0x4]:4   param_1                   XREF[1]:     0051cce8(R)
//              TPanel *          Stack[0x8]:4   param_2                   XREF[1]:     0051cce4(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     0051ccd9(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     0051cd73(R)
//              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     0051ccba(W)
//                               ??0TRIBE_Panel_Pop@@QAE@PAVTDrawArea@@PAVTPanel@@@Z          XREF[1]:     TRIBE_Screen_Game:004949df(c)
//                               TRIBE_Panel_Pop::TRIBE_Panel_Pop
//                              tpnl_pop.cpp:32 (43)
//         0051cca0     PUSH       -0x1
//         0051cca2     PUSH       FUN_005613a8
//         0051cca7     MOV        EAX,FS:[0x0]
//         0051ccad     PUSH       EAX
//         0051ccae     MOV        dword ptr FS:[0x0],ESP
//         0051ccb5     PUSH       this
//         0051ccb6     PUSH       EBX
//         0051ccb7     PUSH       ESI
//         0051ccb8     MOV        ESI,this
//         0051ccba     MOV        dword ptr [ESP + local_10],ESI
//         0051ccbe     CALL       TPanel::TPanel                                   undefined TPanel(TPanel * this)
//         0051ccc3     XOR        EBX,EBX
//         0051ccc5     MOV        dword ptr [ESI],TRIBE_Panel_Pop::`vftable'       = 0051cd90
//                              tpnl_pop.cpp:33 (6)
//         0051cccb     MOV        dword ptr [ESI + 0x80],EBX
//                              tpnl_pop.cpp:35 (17)
//         0051ccd1     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0051ccd7     PUSH       0xb
//         0051ccd9     MOV        dword ptr [ESP + local_4],EBX
//         0051ccdd     CALL       RGE_Base_Game::get_font                          RGE_Font * get_font(RGE_Base_Game * this, int
//                              tpnl_pop.cpp:36 (2)
//         0051cce2     MOV        EAX,dword ptr [EAX]
//                              tpnl_pop.cpp:55 (133)
//         0051cce4     MOV        this,dword ptr [ESP + param_2]
//         0051cce8     MOV        EDX,dword ptr [ESP + param_1]
//         0051ccec     PUSH       EBX
//         0051cced     PUSH       EBX
//         0051ccee     PUSH       EBX
//         0051ccef     PUSH       EBX
//         0051ccf0     MOV        dword ptr [ESI + 0xf4],EAX
//         0051ccf6     PUSH       EBX
//         0051ccf7     OR         EAX,0xffffffff
//         0051ccfa     PUSH       this
//         0051ccfb     PUSH       EDX
//         0051ccfc     MOV        this,ESI
//         0051ccfe     MOV        dword ptr [ESI + 0xf8],0xffffff
//         0051cd08     MOV        dword ptr [ESI + 0xfc],EBX
//         0051cd0e     MOV        dword ptr [ESI + 0x100],0xffff
//         0051cd18     MOV        dword ptr [ESI + 0x104],EBX
//         0051cd1e     MOV        dword ptr [ESI + 0x108],EBX
//         0051cd24     MOV        dword ptr [ESI + 0x10c],EBX
//         0051cd2a     MOV        dword ptr [ESI + 0x110],EBX
//         0051cd30     MOV        dword ptr [ESI + 0x114],EBX
//         0051cd36     MOV        byte ptr [ESI + 0x118],BL
//         0051cd3c     MOV        dword ptr [ESI + 0x11c],EBX
//         0051cd42     MOV        dword ptr [ESI + 0x124],EBX
//         0051cd48     MOV        dword ptr [ESI + 0x15c],EAX
//         0051cd4e     MOV        dword ptr [ESI + 0x160],EAX
//         0051cd54     MOV        dword ptr [ESI + 0x158],EBX
//         0051cd5a     MOV        dword ptr [ESI + 0x120],EBX
//         0051cd60     CALL       TPanel::setup                                    long setup(TPanel * this, TDrawArea * param_1
//         0051cd65     TEST       EAX,EAX
//         0051cd67     JNZ        LAB_0051cd73
//                              tpnl_pop.cpp:56 (10)
//         0051cd69     MOV        dword ptr [ESI + 0xd8],0x1
//                               LAB_0051cd73                                                 XREF[1]:     0051cd67(j)
//                              tpnl_pop.cpp:57 (21)
//         0051cd73     MOV        this,dword ptr [ESP + local_c]
//         0051cd77     MOV        EAX,ESI
//         0051cd79     POP        ESI
//         0051cd7a     MOV        dword ptr FS:[0x0],this
//         0051cd81     POP        EBX
//         0051cd82     ADD        ESP,0x10
//         0051cd85     RET        0x8
//         0051cd88     ??         90h
//         0051cd89     NOP
//         0051cd8a     NOP
//         0051cd8b     NOP
//         0051cd8c     NOP
//         0051cd8d     NOP
//         0051cd8e     NOP
//         0051cd8f     NOP
}

TRIBE_Panel_Pop::~TRIBE_Panel_Pop() {
    /* TODO: Stub */
//                              void __thiscall ~TRIBE_Panel_Pop(TRIBE_Panel_Pop * this)
//              void              <VOID>         <RETURN>
//              TRIBE_Panel_Po    ECX:4 (auto)   this
//              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     0051cdda(W)
//              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     0051cdca(W)
//                               ??1TRIBE_Panel_Pop@@UAE@XZ                                   XREF[1]:     `scalar_deleting_destructor':0051c
//                               TRIBE_Panel_Pop::~TRIBE_Panel_Pop
//                              tpnl_pop.cpp:64 (36)
//         0051cdb0     PUSH       -0x1
//         0051cdb2     PUSH       FUN_005613c8
//         0051cdb7     MOV        EAX,FS:[0x0]
//         0051cdbd     PUSH       EAX
//         0051cdbe     MOV        dword ptr FS:[0x0],ESP
//         0051cdc5     PUSH       this
//         0051cdc6     PUSH       ESI
//         0051cdc7     MOV        ESI,this
//         0051cdc9     PUSH       EDI
//         0051cdca     MOV        dword ptr [ESP + local_10],ESI
//         0051cdce     MOV        dword ptr [ESI],TRIBE_Panel_Pop::`vftable'       = 0051cd90
//                              tpnl_pop.cpp:66 (18)
//         0051cdd4     MOV        EAX,dword ptr [ESI + 0x120]
//         0051cdda     MOV        dword ptr [ESP + local_4],0x0
//         0051cde2     TEST       EAX,EAX
//         0051cde4     JZ         LAB_0051cdf7
//                              tpnl_pop.cpp:68 (7)
//         0051cde6     PUSH       EAX
//         0051cde7     CALL       dword ptr [->GDI32.DLL::DeleteObject]            = 0048b160
//                              tpnl_pop.cpp:69 (10)
//         0051cded     MOV        dword ptr [ESI + 0x120],0x0
//                               LAB_0051cdf7                                                 XREF[1]:     0051cde4(j)
//                              tpnl_pop.cpp:72 (10)
//         0051cdf7     MOV        EDI,dword ptr [ESI + 0x124]
//         0051cdfd     TEST       EDI,EDI
//         0051cdff     JZ         LAB_0051ce1b
//                              tpnl_pop.cpp:74 (16)
//         0051ce01     MOV        this,EDI
//         0051ce03     CALL       TDrawArea::~TDrawArea                            void ~TDrawArea(TDrawArea * this)
//         0051ce08     PUSH       EDI
//         0051ce09     CALL       operator_delete                                  void operator_delete(void * param_1)
//         0051ce0e     ADD        ESP,0x4
//                              tpnl_pop.cpp:75 (12)
//         0051ce11     MOV        dword ptr [ESI + 0x124],0x0
//                               LAB_0051ce1b                                                 XREF[1]:     0051cdff(j)
//         0051ce1b     MOV        this,ESI
//                              tpnl_pop.cpp:78 (30)
//         0051ce1d     MOV        dword ptr [ESP + 0x14],0xffffffff
//         0051ce25     CALL       TPanel::~TPanel                                  void ~TPanel(TPanel * this)
//         0051ce2a     MOV        this,dword ptr [ESP + 0xc]
//         0051ce2e     POP        EDI
//         0051ce2f     MOV        dword ptr FS:[0x0],this
//         0051ce36     POP        ESI
//         0051ce37     ADD        ESP,0x10
//         0051ce3a     RET
//         0051ce3b     ??         90h
//         0051ce3c     NOP
//         0051ce3d     NOP
//         0051ce3e     NOP
//         0051ce3f     NOP
}

void TRIBE_Panel_Pop::set_rect(long param_1, long param_2, long param_3, long param_4) {
    /* TODO: Stub */
//                              void __thiscall set_rect(TRIBE_Panel_Pop * this, long param_1, long
//              void              <VOID>         <RETURN>
//              TRIBE_Panel_Po    ECX:4 (auto)   this
//              long              Stack[0x4]:4   param_1                   XREF[1]:     0051ce66(R)
//              long              Stack[0x8]:4   param_2                   XREF[1]:     0051ce52(R)
//              long              Stack[0xc]:4   param_3                   XREF[1]:     0051ce61(R)
//              long              Stack[0x10]:4  param_4                   XREF[1]:     0051ce4e(R)
//                               ?set_rect@TRIBE_Panel_Pop@@UAEXJJJJ@Z                        XREF[1]:     00576dcc(*)
//                               TRIBE_Panel_Pop::set_rect
//                              tpnl_pop.cpp:85 (14)
//         0051ce40     MOV        EAX,FS:[0x0]
//         0051ce46     PUSH       -0x1
//         0051ce48     PUSH       FUN_005613eb
//         0051ce4d     PUSH       EAX
//                              tpnl_pop.cpp:87 (39)
//         0051ce4e     MOV        EAX,dword ptr [ESP + param_4]
//         0051ce52     MOV        EDX,dword ptr [ESP + param_2]
//         0051ce56     MOV        dword ptr FS:[0x0],ESP
//         0051ce5d     PUSH       EBX
//         0051ce5e     PUSH       ESI
//         0051ce5f     MOV        ESI,this
//         0051ce61     MOV        this,dword ptr [ESP + param_3]
//         0051ce65     PUSH       EDI
//         0051ce66     MOV        EDI,dword ptr [ESP + param_1]
//         0051ce6a     PUSH       EAX
//         0051ce6b     PUSH       this
//         0051ce6c     PUSH       EDX
//         0051ce6d     PUSH       EDI
//         0051ce6e     MOV        this,ESI
//         0051ce70     CALL       TPanel::set_rect                                 void set_rect(TPanel * this, long param_1, lo
//                              tpnl_pop.cpp:91 (42)
//         0051ce75     MOV        EAX,dword ptr [ESI + 0x15c]
//         0051ce7b     MOV        this,dword ptr [ESI + 0x14]
//         0051ce7e     XOR        EBX,EBX
//         0051ce80     CMP        this,EAX
//         0051ce82     JG         LAB_0051ce9f
//         0051ce84     MOV        this,dword ptr [ESI + 0x18]
//         0051ce87     MOV        EDX,dword ptr [ESI + 0x160]
//         0051ce8d     CMP        this,EDX
//         0051ce8f     JG         LAB_0051ce9f
//         0051ce91     MOV        EDX,dword ptr [ESI + 0x20]
//         0051ce94     ADD        EDI,EAX
//         0051ce96     CMP        EDI,dword ptr [EDX + 0x18]
//         0051ce99     JL         LAB_0051cf61
//                               LAB_0051ce9f                                                 XREF[2]:     0051ce82(j), 0051ce8f(j)
//                              tpnl_pop.cpp:93 (10)
//         0051ce9f     MOV        EAX,dword ptr [ESI + 0x120]
//         0051cea5     CMP        EAX,EBX
//         0051cea7     JZ         LAB_0051ceb6
//                              tpnl_pop.cpp:95 (7)
//         0051cea9     PUSH       EAX
//         0051ceaa     CALL       dword ptr [->GDI32.DLL::DeleteObject]            = 0048b160
//                              tpnl_pop.cpp:96 (6)
//         0051ceb0     MOV        dword ptr [ESI + 0x120],EBX
//                               LAB_0051ceb6                                                 XREF[1]:     0051cea7(j)
//                              tpnl_pop.cpp:99 (10)
//         0051ceb6     MOV        EDI,dword ptr [ESI + 0x124]
//         0051cebc     CMP        EDI,EBX
//         0051cebe     JZ         LAB_0051ced6
//                              tpnl_pop.cpp:101 (16)
//         0051cec0     MOV        this,EDI
//         0051cec2     CALL       TDrawArea::~TDrawArea                            void ~TDrawArea(TDrawArea * this)
//         0051cec7     PUSH       EDI
//         0051cec8     CALL       operator_delete                                  void operator_delete(void * param_1)
//         0051cecd     ADD        ESP,0x4
//                              tpnl_pop.cpp:102 (6)
//         0051ced0     MOV        dword ptr [ESI + 0x124],EBX
//                               LAB_0051ced6                                                 XREF[1]:     0051cebe(j)
//                              tpnl_pop.cpp:105 (42)
//         0051ced6     PUSH       0x100
//         0051cedb     CALL       operator_new                                     void * operator_new(uint param_1)
//         0051cee0     ADD        ESP,0x4
//         0051cee3     MOV        dword ptr [ESP + 0x28],EAX
//         0051cee7     CMP        EAX,EBX
//         0051cee9     MOV        dword ptr [ESP + 0x14],EBX
//         0051ceed     JZ         LAB_0051cefe
//         0051ceef     PUSH       EBX
//         0051cef0     PUSH       s_time_message_panel                             = "time message panel"
//         0051cef5     MOV        this,EAX
//         0051cef7     CALL       TDrawArea::TDrawArea                             undefined TDrawArea(TDrawArea * this, char *
//         0051cefc     JMP        LAB_0051cf00
//                               LAB_0051cefe                                                 XREF[1]:     0051ceed(j)
//         0051cefe     XOR        EAX,EAX
//                               LAB_0051cf00                                                 XREF[1]:     0051cefc(j)
//                              tpnl_pop.cpp:106 (37)
//         0051cf00     MOV        this,dword ptr [ESI + 0x18]
//         0051cf03     MOV        EDX,dword ptr [ESI + 0x14]
//         0051cf06     PUSH       EBX
//         0051cf07     PUSH       EBX
//         0051cf08     PUSH       this
//         0051cf09     MOV        this,dword ptr [ESI + 0x20]
//         0051cf0c     MOV        dword ptr [ESI + 0x124],EAX
//         0051cf12     PUSH       EDX
//         0051cf13     MOV        EDX,dword ptr [this->_padding_]
//         0051cf15     MOV        this,EAX
//         0051cf17     PUSH       EDX
//         0051cf18     MOV        dword ptr [ESP + 0x28],0xffffffff
//         0051cf20     CALL       TDrawArea::Init                                  int Init(TDrawArea * this, TDrawSystem * para
//                              tpnl_pop.cpp:107 (3)
//         0051cf25     MOV        EAX,dword ptr [ESI + 0x14]
//                              tpnl_pop.cpp:108 (15)
//         0051cf28     MOV        this,dword ptr [ESI + 0x18]
//         0051cf2b     MOV        dword ptr [ESI + 0x15c],EAX
//         0051cf31     MOV        dword ptr [ESI + 0x160],this
//                              tpnl_pop.cpp:112 (1)
//         0051cf37     DEC        EAX
//                              tpnl_pop.cpp:113 (1)
//         0051cf38     DEC        this
//                              tpnl_pop.cpp:115 (40)
//         0051cf39     PUSH       this
//         0051cf3a     PUSH       EAX
//         0051cf3b     PUSH       EBX
//         0051cf3c     PUSH       EBX
//         0051cf3d     MOV        dword ptr [ESI + 0x128],EBX
//         0051cf43     MOV        dword ptr [ESI + 0x12c],EBX
//         0051cf49     MOV        dword ptr [ESI + 0x130],EAX
//         0051cf4f     MOV        dword ptr [ESI + 0x134],this
//         0051cf55     CALL       dword ptr [->GDI32.DLL::CreateRectRgn]           = 0048b2ec
//         0051cf5b     MOV        dword ptr [ESI + 0x120],EAX
//                               LAB_0051cf61                                                 XREF[1]:     0051ce99(j)
//                              tpnl_pop.cpp:118 (8)
//         0051cf61     CMP        dword ptr [ESI + 0x124],EBX
//         0051cf67     JZ         LAB_0051cf8d
//                              tpnl_pop.cpp:119 (34)
//         0051cf69     LEA        EAX,[ESI + 0x128]
//         0051cf6f     LEA        this,[ESI + 0x138]
//         0051cf75     MOV        EDX,dword ptr [EAX]
//         0051cf77     MOV        dword ptr [this->_padding_],EDX
//         0051cf79     MOV        EDX,dword ptr [EAX + 0x4]
//         0051cf7c     MOV        dword ptr [ECX + this->_padding_],EDX
//         0051cf7f     MOV        EDX,dword ptr [EAX + 0x8]
//         0051cf82     MOV        dword ptr [ECX + this->_padding_],EDX
//         0051cf85     MOV        EAX,dword ptr [EAX + 0xc]
//         0051cf88     MOV        dword ptr [ECX + this->_padding_],EAX
//                              tpnl_pop.cpp:120 (2)
//         0051cf8b     JMP        LAB_0051cfa1
//                               LAB_0051cf8d                                                 XREF[1]:     0051cf67(j)
//                              tpnl_pop.cpp:122 (10)
//         0051cf8d     MOV        dword ptr [ESI + 0x15c],0xffffffff
//                              tpnl_pop.cpp:123 (10)
//         0051cf97     MOV        dword ptr [ESI + 0x160],0xffffffff
//                               LAB_0051cfa1                                                 XREF[1]:     0051cf8b(j)
//                              tpnl_pop.cpp:127 (16)
//         0051cfa1     MOV        EDX,dword ptr [ESI]
//         0051cfa3     PUSH       0x1
//         0051cfa5     MOV        this,ESI
//         0051cfa7     MOV        byte ptr [ESI + 0xf3],0x1
//         0051cfae     CALL       dword ptr [EDX + 0x20]
//                              tpnl_pop.cpp:129 (20)
//         0051cfb1     MOV        this,dword ptr [ESP + 0xc]
//         0051cfb5     POP        EDI
//         0051cfb6     POP        ESI
//         0051cfb7     MOV        dword ptr FS:[0x0],this
//         0051cfbe     POP        EBX
//         0051cfbf     ADD        ESP,0xc
//         0051cfc2     RET        0x10
//         0051cfc5     ??         90h
//         0051cfc6     NOP
//         0051cfc7     NOP
//         0051cfc8     NOP
//         0051cfc9     NOP
//         0051cfca     NOP
//         0051cfcb     NOP
//         0051cfcc     NOP
//         0051cfcd     NOP
//         0051cfce     NOP
//         0051cfcf     NOP
    return;
}

void TRIBE_Panel_Pop::startup() {
    /* TODO: Stub */
//                              void __thiscall startup(TRIBE_Panel_Pop * this)
//              void              <VOID>         <RETURN>
//              TRIBE_Panel_Po    ECX:4 (auto)   this
//                               ?startup@TRIBE_Panel_Pop@@QAEXXZ                             XREF[1]:     TRIBE_Screen_Game:004953b1(c)
//                               TRIBE_Panel_Pop::startup
//                              tpnl_pop.cpp:135 (22)
//         0051cfd0     MOV        EAX,[rge_base_game]                              = 00000000
//         0051cfd5     PUSH       EBX
//         0051cfd6     PUSH       ESI
//         0051cfd7     MOV        ESI,this
//         0051cfd9     MOV        this,dword ptr [EAX + 0x3f4]
//         0051cfdf     PUSH       EDI
//         0051cfe0     MOV        dword ptr [ESI + 0x108],this
//                              tpnl_pop.cpp:137 (19)
//         0051cfe6     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0051cfec     CALL       RGE_Base_Game::get_player                        RGE_Player * get_player(RGE_Base_Game * this)
//         0051cff1     MOV        EDI,EAX
//         0051cff3     MOV        dword ptr [ESI + 0x10c],EDI
//                              tpnl_pop.cpp:138 (19)
//         0051cff9     MOV        EDX,dword ptr [EDI + 0x50]
//         0051cffc     FLD        float ptr [EDX + 0x2c]
//         0051cfff     CALL       __ftol                                           undefined __ftol()
//         0051d004     MOV        EBX,EAX
//         0051d006     MOV        dword ptr [ESI + 0x110],EBX
//                              tpnl_pop.cpp:139 (19)
//         0051d00c     MOV        EAX,dword ptr [EDI + 0x50]
//         0051d00f     FLD        float ptr [EAX + 0x10]
//         0051d012     CALL       __ftol                                           undefined __ftol()
//         0051d017     ADD        EBX,EAX
//         0051d019     MOV        dword ptr [ESI + 0x114],EBX
//                              tpnl_pop.cpp:140 (18)
//         0051d01f     MOV        this,dword ptr [EDI + 0x50]
//         0051d022     FLD        float ptr [ECX + this->_padding_]
//         0051d028     CALL       __ftol                                           undefined __ftol()
//         0051d02d     CMP        EBX,EAX
//         0051d02f     JLE        LAB_0051d037
//                              tpnl_pop.cpp:141 (6)
//         0051d031     MOV        dword ptr [ESI + 0x114],EAX
//                               LAB_0051d037                                                 XREF[1]:     0051d02f(j)
//                              tpnl_pop.cpp:142 (4)
//         0051d037     POP        EDI
//         0051d038     POP        ESI
//         0051d039     POP        EBX
//         0051d03a     RET
//         0051d03b     ??         90h
//         0051d03c     NOP
//         0051d03d     NOP
//         0051d03e     NOP
//         0051d03f     NOP
    return;
}

int TRIBE_Panel_Pop::get_player_id() {
    /* TODO: Stub */
//                              int __thiscall get_player_id(TRIBE_Panel_Pop * this)
//              int               EAX:4          <RETURN>
//              TRIBE_Panel_Po    ECX:4 (auto)   this
//                               ?get_player_id@TRIBE_Panel_Pop@@QAEHXZ
//                               TRIBE_Panel_Pop::get_player_id
//                              tpnl_pop.cpp:148 (10)
//         0051d040     MOV        EAX,dword ptr [ECX + this->player]
//         0051d046     TEST       EAX,EAX
//         0051d048     JZ         LAB_0051d04f
//                              tpnl_pop.cpp:150 (4)
//         0051d04a     MOVSX      EAX,word ptr [EAX + 0x4a]
//                              tpnl_pop.cpp:153 (1)
//         0051d04e     RET
//                               LAB_0051d04f                                                 XREF[1]:     0051d048(j)
//                              tpnl_pop.cpp:152 (2)
//         0051d04f     XOR        EAX,EAX
//                              tpnl_pop.cpp:153 (1)
//         0051d051     RET
//         0051d052     ??         90h
//         0051d053     NOP
//         0051d054     NOP
//         0051d055     NOP
//         0051d056     NOP
//         0051d057     NOP
//         0051d058     NOP
//         0051d059     NOP
//         0051d05a     NOP
//         0051d05b     NOP
//         0051d05c     NOP
//         0051d05d     NOP
//         0051d05e     NOP
//         0051d05f     NOP
    return 0;
}

void TRIBE_Panel_Pop::draw() {
    /* TODO: Stub */
//                              void __thiscall draw(TRIBE_Panel_Pop * this)
//              void              <VOID>         <RETURN>
//              TRIBE_Panel_Po    ECX:4 (auto)   this
//              char[256]         Stack[-0x104   str
//              void *            Stack[-0x108   old_font
//              undefined4        Stack[-0x10c   local_10c                 XREF[1]:     0051d099(W)
//              tagRECT           Stack[-0x124   rect
//              uchar             Stack[-0x131   changed_mode
//                               ?draw@TRIBE_Panel_Pop@@UAEXXZ                                XREF[1]:     00576df0(*)
//                               TRIBE_Panel_Pop::draw
//                              tpnl_pop.cpp:159 (10)
//         0051d060     SUB        ESP,0x130
//         0051d066     PUSH       ESI
//         0051d067     MOV        ESI,this
//         0051d069     PUSH       EDI
//                              tpnl_pop.cpp:165 (29)
//         0051d06a     XOR        EDI,EDI
//         0051d06c     CMP        dword ptr [ESI + 0x20],EDI
//         0051d06f     JZ         LAB_0051d460
//         0051d075     CMP        dword ptr [ESI + 0x70],EDI
//         0051d078     JZ         LAB_0051d460
//         0051d07e     CMP        dword ptr [ESI + 0x6c],EDI
//         0051d081     JZ         LAB_0051d460
//                              tpnl_pop.cpp:168 (6)
//         0051d087     MOV        EDX,dword ptr [ESI + 0xe0]
//                              tpnl_pop.cpp:170 (19)
//         0051d08d     MOV        EAX,dword ptr [ESI]
//         0051d08f     PUSH       EBP
//         0051d090     PUSH       EBX
//         0051d091     INC        EDX
//         0051d092     PUSH       EDI
//         0051d093     MOV        dword ptr [ESI + 0xe0],EDX
//         0051d099     MOV        dword ptr [ESP + local_10c],EAX
//         0051d09d     CALL       dword ptr [EAX + 0x28]
//                              tpnl_pop.cpp:173 (13)
//         0051d0a0     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0051d0a6     CALL       RGE_Base_Game::get_player                        RGE_Player * get_player(RGE_Base_Game * this)
//         0051d0ab     MOV        EDX,EAX
//                              tpnl_pop.cpp:176 (40)
//         0051d0ad     MOV        AL,byte ptr [ESI + 0x118]
//         0051d0b3     TEST       AL,AL
//         0051d0b5     MOV        dword ptr [ESI + 0x10c],EDX
//         0051d0bb     MOV        byte ptr [ESP + 0x13],0x0
//         0051d0c0     JNZ        LAB_0051d0e7
//         0051d0c2     MOVSX      EAX,word ptr [EDX + 0x4a]
//         0051d0c6     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0051d0cc     CMP        dword ptr [this->_padding_ + EAX*0x4 + 0xa34],
//         0051d0d3     JLE        LAB_0051d0e7
//                              tpnl_pop.cpp:178 (7)
//         0051d0d5     MOV        byte ptr [ESI + 0x118],0x1
//                              tpnl_pop.cpp:179 (6)
//         0051d0dc     MOV        dword ptr [ESI + 0x11c],EDI
//                              tpnl_pop.cpp:180 (5)
//         0051d0e2     MOV        byte ptr [ESP + 0x13],0x1
//                               LAB_0051d0e7                                                 XREF[2]:     0051d0c0(j), 0051d0d3(j)
//                              tpnl_pop.cpp:183 (10)
//         0051d0e7     MOV        this,byte ptr [ESI + 0x118]
//         0051d0ed     TEST       this,this
//         0051d0ef     JBE        LAB_0051d133
//                              tpnl_pop.cpp:185 (15)
//         0051d0f1     MOV        EAX,dword ptr [EDX + 0x3c]
//         0051d0f4     FLD        float ptr [EAX + 0x84]
//         0051d0fa     FADD       float ptr [ESI + 0x11c]
//                              tpnl_pop.cpp:186 (19)
//         0051d100     FCOM       float ptr [DAT_00576ea0]                         = align(2)
//         0051d106     FSTP       float ptr [ESI + 0x11c]
//         0051d10c     FNSTSW     AX
//         0051d10e     TEST       AH,0x41
//         0051d111     JNZ        LAB_0051d133
//                              tpnl_pop.cpp:189 (9)
//         0051d113     MOV        AL,this
//         0051d115     MOV        byte ptr [ESP + 0x13],0x1
//         0051d11a     INC        AL
//                              tpnl_pop.cpp:190 (6)
//         0051d11c     MOV        dword ptr [ESI + 0x11c],EDI
//                              tpnl_pop.cpp:191 (10)
//         0051d122     CMP        AL,0x2
//         0051d124     MOV        byte ptr [ESI + 0x118],AL
//         0051d12a     JBE        LAB_0051d133
//                              tpnl_pop.cpp:192 (7)
//         0051d12c     MOV        byte ptr [ESI + 0x118],0x0
//                               LAB_0051d133                                                 XREF[3]:     0051d0ef(j), 0051d111(j),
//                                                                                                         0051d12a(j)
//                              tpnl_pop.cpp:196 (11)
//         0051d133     MOV        EBP,dword ptr [EDX + 0x50]
//         0051d136     FLD        float ptr [EBP + 0x2c]
//         0051d139     CALL       __ftol                                           undefined __ftol()
//                              tpnl_pop.cpp:197 (10)
//         0051d13e     FLD        float ptr [EBP + 0x10]
//         0051d141     MOV        EBX,EAX
//         0051d143     CALL       __ftol                                           undefined __ftol()
//                              tpnl_pop.cpp:198 (19)
//         0051d148     FLD        float ptr [EBP + 0x80]
//         0051d14e     MOV        EDI,EAX
//         0051d150     ADD        EDI,EBX
//         0051d152     CALL       __ftol                                           undefined __ftol()
//         0051d157     CMP        EDI,EAX
//         0051d159     JLE        LAB_0051d15d
//                              tpnl_pop.cpp:199 (2)
//         0051d15b     MOV        EDI,EAX
//                               LAB_0051d15d                                                 XREF[1]:     0051d159(j)
//                              tpnl_pop.cpp:201 (44)
//         0051d15d     MOV        EAX,dword ptr [ESI + 0x124]
//         0051d163     TEST       EAX,EAX
//         0051d165     JZ         LAB_0051d1c1
//         0051d167     MOV        AL,byte ptr [ESP + 0x13]
//         0051d16b     TEST       AL,AL
//         0051d16d     JNZ        LAB_0051d189
//         0051d16f     MOV        AL,byte ptr [ESI + 0xf3]
//         0051d175     TEST       AL,AL
//         0051d177     JNZ        LAB_0051d189
//         0051d179     CMP        dword ptr [ESI + 0x110],EBX
//         0051d17f     JNZ        LAB_0051d189
//         0051d181     CMP        dword ptr [ESI + 0x114],EDI
//         0051d187     JZ         LAB_0051d1c1
//                               LAB_0051d189                                                 XREF[3]:     0051d16d(j), 0051d177(j),
//                                                                                                         0051d17f(j)
//                              tpnl_pop.cpp:206 (19)
//         0051d189     MOV        this,ESI
//         0051d18b     MOV        dword ptr [ESI + 0x110],EBX
//         0051d191     MOV        dword ptr [ESI + 0x114],EDI
//         0051d197     CALL       TRIBE_Panel_Pop::render_to_image_buffer          int render_to_image_buffer(TRIBE_Panel_Pop *
//                              tpnl_pop.cpp:207 (10)
//         0051d19c     MOV        AL,byte ptr [ESI + 0xf3]
//         0051d1a2     TEST       AL,AL
//         0051d1a4     JZ         LAB_0051d1c1
//                              tpnl_pop.cpp:292 (18)
//         0051d1a6     MOV        EDX,dword ptr [ESP + 0x34]
//         0051d1aa     MOV        this,ESI
//         0051d1ac     MOV        byte ptr [ESI + 0xf3],0x0
//         0051d1b3     CALL       dword ptr [EDX + 0x2c]
//         0051d1b6     POP        EBX
//         0051d1b7     POP        EBP
//                              tpnl_pop.cpp:293 (9)
//         0051d1b8     POP        EDI
//         0051d1b9     POP        ESI
//         0051d1ba     ADD        ESP,0x130
//         0051d1c0     RET
//                               LAB_0051d1c1                                                 XREF[3]:     0051d165(j), 0051d187(j),
//                                                                                                         0051d1a4(j)
//                              tpnl_pop.cpp:216 (20)
//         0051d1c1     MOV        EAX,dword ptr [ESI + 0x158]
//         0051d1c7     TEST       EAX,EAX
//         0051d1c9     JZ         LAB_0051d227
//         0051d1cb     MOV        this,dword ptr [ESI + 0x124]
//         0051d1d1     TEST       this,this
//         0051d1d3     JZ         LAB_0051d227
//                              tpnl_pop.cpp:227 (9)
//         0051d1d5     PUSH       0x1
//         0051d1d7     PUSH       offset DAT_fffffff8
//         0051d1d9     CALL       TDrawArea::SetTrans                              void SetTrans(TDrawArea * this, int param_1,
//                              tpnl_pop.cpp:228 (38)
//         0051d1de     MOV        EDX,dword ptr [ESI + 0x14c]
//         0051d1e4     MOV        EAX,dword ptr [ESI + 0x148]
//         0051d1ea     LEA        this,[ESI + 0x138]
//         0051d1f0     PUSH       0x1
//         0051d1f2     PUSH       this=>DAT_fffffff8
//         0051d1f3     MOV        this,dword ptr [ESI + 0x20]
//         0051d1f6     PUSH       EDX=>DAT_fffffff4
//         0051d1f7     PUSH       EAX=>DAT_fffffff0
//         0051d1f8     PUSH       this
//         0051d1f9     MOV        this,dword ptr [ESI + 0x124]
//         0051d1ff     CALL       TDrawArea::Copy                                  void Copy(TDrawArea * this, TDrawArea * param
//                              tpnl_pop.cpp:229 (15)
//         0051d204     MOV        this,dword ptr [ESI + 0x124]
//         0051d20a     PUSH       0x1
//         0051d20c     PUSH       0x0=>DAT_fffffff8
//         0051d20e     CALL       TDrawArea::SetTrans                              void SetTrans(TDrawArea * this, int param_1,
//                              tpnl_pop.cpp:292 (11)
//         0051d213     MOV        EDX,dword ptr [ESP + 0x34]
//         0051d217     MOV        this,ESI
//         0051d219     CALL       dword ptr [EDX + 0x2c]
//         0051d21c     POP        EBX
//         0051d21d     POP        EBP
//                              tpnl_pop.cpp:293 (9)
//         0051d21e     POP        EDI
//         0051d21f     POP        ESI
//         0051d220     ADD        ESP,0x130
//         0051d226     RET
//                               LAB_0051d227                                                 XREF[2]:     0051d1c9(j), 0051d1d3(j)
//                              tpnl_pop.cpp:236 (21)
//         0051d227     MOV        this,dword ptr [ESI + 0x20]
//         0051d22a     PUSH       s_tpnl_tim::draw                                 = "tpnl_tim::draw"
//         0051d22f     CALL       TDrawArea::GetDc                                 void * GetDc(TDrawArea * this, char * param_1)
//         0051d234     TEST       EAX,EAX
//         0051d236     JZ         LAB_0051d455
//                              tpnl_pop.cpp:238 (20)
//         0051d23c     MOV        EAX,dword ptr [ESI + 0x20]
//         0051d23f     MOV        EDX,dword ptr [ESI + 0x88]
//         0051d245     PUSH       EDX
//         0051d246     MOV        this,dword ptr [EAX + 0x38]
//         0051d249     PUSH       this=>DAT_fffffff8
//         0051d24a     CALL       dword ptr [->GDI32.DLL::SelectClipRgn]           = 0048b2fc
//                              tpnl_pop.cpp:239 (20)
//         0051d250     MOV        EAX,dword ptr [ESI + 0x20]
//         0051d253     MOV        EDX,dword ptr [ESI + 0xf4]
//         0051d259     PUSH       EDX
//         0051d25a     MOV        this,dword ptr [EAX + 0x38]
//         0051d25d     PUSH       this=>DAT_fffffff8
//         0051d25e     CALL       dword ptr [->GDI32.DLL::SelectObject]            = 0048b192
//                              tpnl_pop.cpp:240 (19)
//         0051d264     MOV        EDX,dword ptr [ESI + 0x20]
//         0051d267     MOV        dword ptr [ESP + 0x3c],EAX
//         0051d26b     PUSH       0x1
//         0051d26d     MOV        EAX,dword ptr [EDX + 0x38]
//         0051d270     PUSH       EAX=>DAT_fffffff8
//         0051d271     CALL       dword ptr [->GDI32.DLL::SetBkMode]               = 0048b340
//                              tpnl_pop.cpp:242 (42)
//         0051d277     MOV        this,dword ptr [ESI + 0x114]
//         0051d27d     MOV        EDX,dword ptr [ESI + 0x110]
//         0051d283     PUSH       this
//         0051d284     PUSH       EDX=>DAT_fffffff8
//                              language.dll match for 0x2b2a: "pop: "
//         0051d285     PUSH       offset DAT_fffffff4
//         0051d28a     MOV        this,ESI
//         0051d28c     CALL       TPanel::get_string                               char * get_string(TPanel * this, int param_1)
//         0051d291     PUSH       EAX=>DAT_fffffff4
//         0051d292     LEA        EAX,[ESP + 0x4c]
//         0051d296     PUSH       s_%s%ld/%ld                                      = "%s%ld/%ld"
//         0051d29b     PUSH       EAX
//         0051d29c     CALL       sprintf                                          undefined sprintf()
//                              tpnl_pop.cpp:245 (23)
//         0051d2a1     MOV        EDX,dword ptr [ESI + 0x20]
//         0051d2a4     MOV        this,dword ptr [ESI + 0xfc]
//         0051d2aa     ADD        ESP,0x14
//         0051d2ad     MOV        EAX,dword ptr [EDX + 0x38]
//         0051d2b0     PUSH       this
//         0051d2b1     PUSH       EAX=>DAT_fffffff8
//         0051d2b2     CALL       dword ptr [->GDI32.DLL::SetTextColor]            = 0048b318
//                              tpnl_pop.cpp:249 (6)
//         0051d2b8     MOV        EDI,dword ptr [ESI + 0x8c]
//                              tpnl_pop.cpp:250 (6)
//         0051d2be     MOV        EBP,dword ptr [ESI + 0x90]
//                              tpnl_pop.cpp:252 (14)
//         0051d2c4     MOV        EBX,dword ptr [ESI + 0x18]
//         0051d2c7     MOV        EAX,dword ptr [ESI + 0x14]
//         0051d2ca     INC        EDI
//         0051d2cb     INC        EBP
//         0051d2cc     SUB        EBX,0x2
//         0051d2cf     SUB        EAX,0x2
//                              tpnl_pop.cpp:254 (51)
//         0051d2d2     ADD        EBX,EBP
//         0051d2d4     ADD        EAX,EDI
//         0051d2d6     MOV        dword ptr [ESP + 0x18],EAX
//         0051d2da     LEA        EDX,[EBP + -0x1]
//         0051d2dd     LEA        this,[EBX + -0x2]
//         0051d2e0     ADD        EAX,-0x2
//         0051d2e3     MOV        dword ptr [ESP + 0x1c],EDX
//         0051d2e7     PUSH       this
//         0051d2e8     MOV        dword ptr [ESP + 0x3c],EAX
//         0051d2ec     PUSH       EAX=>DAT_fffffff8
//         0051d2ed     MOV        EAX,dword ptr [ESP + 0x24]
//         0051d2f1     LEA        EDX,[EDI + -0x1]
//         0051d2f4     PUSH       EAX=>DAT_fffffff4
//         0051d2f5     LEA        this,[ESP + 0x2c]
//         0051d2f9     PUSH       EDX=>DAT_fffffff0
//         0051d2fa     PUSH       this
//         0051d2fb     MOV        dword ptr [ESP + 0x28],EDX
//         0051d2ff     CALL       dword ptr [->USER32.DLL::SetRect]                = 0048b002
//                              tpnl_pop.cpp:255 (27)
//         0051d305     MOV        this,dword ptr [ESI + 0x20]
//         0051d308     LEA        EDX,[ESP + 0x20]
//         0051d30c     PUSH       0x21
//         0051d30e     PUSH       EDX=>DAT_fffffff8
//         0051d30f     MOV        EDX,dword ptr [ECX + this->_padding_]
//         0051d312     LEA        EAX,[ESP + 0x48]
//         0051d316     PUSH       offset DAT_fffffff4
//         0051d318     PUSH       EAX=>DAT_fffffff0
//         0051d319     PUSH       EDX
//         0051d31a     CALL       dword ptr [->USER32.DLL::DrawTextA]              = 0048b10a
//                              tpnl_pop.cpp:257 (30)
//         0051d320     MOV        this,dword ptr [ESP + 0x38]
//         0051d324     MOV        EDX,dword ptr [ESP + 0x14]
//         0051d328     LEA        EAX,[EBP + 0x1]
//         0051d32b     PUSH       EBX
//         0051d32c     PUSH       this=>DAT_fffffff8
//         0051d32d     PUSH       EAX=>DAT_fffffff4
//         0051d32e     MOV        dword ptr [ESP + 0x3c],EAX
//         0051d332     PUSH       EDX=>DAT_fffffff0
//         0051d333     LEA        EAX,[ESP + 0x30]
//         0051d337     PUSH       EAX
//         0051d338     CALL       dword ptr [->USER32.DLL::SetRect]                = 0048b002
//                              tpnl_pop.cpp:258 (27)
//         0051d33e     MOV        EAX,dword ptr [ESI + 0x20]
//         0051d341     LEA        this,[ESP + 0x20]
//         0051d345     PUSH       0x21
//         0051d347     PUSH       this=>DAT_fffffff8
//         0051d348     MOV        this,dword ptr [EAX + 0x38]
//         0051d34b     LEA        EDX,[ESP + 0x48]
//         0051d34f     PUSH       offset DAT_fffffff4
//         0051d351     PUSH       EDX=>DAT_fffffff0
//         0051d352     PUSH       this
//         0051d353     CALL       dword ptr [->USER32.DLL::DrawTextA]              = 0048b10a
//                              tpnl_pop.cpp:260 (33)
//         0051d359     MOV        EDX,dword ptr [ESP + 0x18]
//         0051d35d     LEA        EAX,[EBX + -0x2]
//         0051d360     PUSH       EAX
//         0051d361     MOV        EAX,dword ptr [ESP + 0x20]
//         0051d365     LEA        this,[EDI + 0x1]
//         0051d368     PUSH       EDX=>DAT_fffffff8
//         0051d369     PUSH       EAX=>DAT_fffffff4
//         0051d36a     MOV        dword ptr [ESP + 0x20],this
//         0051d36e     PUSH       this=>DAT_fffffff0
//         0051d36f     LEA        this,[ESP + 0x30]
//         0051d373     PUSH       this
//         0051d374     CALL       dword ptr [->USER32.DLL::SetRect]                = 0048b002
//                              tpnl_pop.cpp:261 (27)
//         0051d37a     MOV        this,dword ptr [ESI + 0x20]
//         0051d37d     LEA        EDX,[ESP + 0x20]
//         0051d381     PUSH       0x21
//         0051d383     PUSH       EDX=>DAT_fffffff8
//         0051d384     MOV        EDX,dword ptr [ECX + this->_padding_]
//         0051d387     LEA        EAX,[ESP + 0x48]
//         0051d38b     PUSH       offset DAT_fffffff4
//         0051d38d     PUSH       EAX=>DAT_fffffff0
//         0051d38e     PUSH       EDX
//         0051d38f     CALL       dword ptr [->USER32.DLL::DrawTextA]              = 0048b10a
//                              tpnl_pop.cpp:263 (27)
//         0051d395     MOV        EAX,dword ptr [ESP + 0x18]
//         0051d399     MOV        this,dword ptr [ESP + 0x30]
//         0051d39d     MOV        EDX,dword ptr [ESP + 0x14]
//         0051d3a1     PUSH       EBX
//         0051d3a2     PUSH       EAX=>DAT_fffffff8
//         0051d3a3     PUSH       this=>DAT_fffffff4
//         0051d3a4     LEA        EAX,[ESP + 0x2c]
//         0051d3a8     PUSH       EDX=>DAT_fffffff0
//         0051d3a9     PUSH       EAX
//         0051d3aa     CALL       dword ptr [->USER32.DLL::SetRect]                = 0048b002
//                              tpnl_pop.cpp:264 (27)
//         0051d3b0     MOV        EAX,dword ptr [ESI + 0x20]
//         0051d3b3     LEA        this,[ESP + 0x20]
//         0051d3b7     PUSH       0x21
//         0051d3b9     PUSH       this=>DAT_fffffff8
//         0051d3ba     MOV        this,dword ptr [EAX + 0x38]
//         0051d3bd     LEA        EDX,[ESP + 0x48]
//         0051d3c1     PUSH       offset DAT_fffffff4
//         0051d3c3     PUSH       EDX=>DAT_fffffff0
//         0051d3c4     PUSH       this
//         0051d3c5     CALL       dword ptr [->USER32.DLL::DrawTextA]              = 0048b10a
//                              tpnl_pop.cpp:273 (9)
//         0051d3cb     CMP        byte ptr [ESI + 0x118],0x1
//         0051d3d2     JNZ        LAB_0051d3e3
//                              tpnl_pop.cpp:274 (13)
//         0051d3d4     MOV        EDX,dword ptr [ESI + 0x100]
//         0051d3da     MOV        EAX,dword ptr [ESI + 0x124]
//         0051d3e0     PUSH       EDX
//                              tpnl_pop.cpp:275 (2)
//         0051d3e1     JMP        LAB_0051d3ed
//                               LAB_0051d3e3                                                 XREF[1]:     0051d3d2(j)
//                              tpnl_pop.cpp:276 (20)
//         0051d3e3     MOV        EDX,dword ptr [ESI + 0xf8]
//         0051d3e9     MOV        EAX,dword ptr [ESI + 0x20]
//         0051d3ec     PUSH       EDX
//                               LAB_0051d3ed                                                 XREF[1]:     0051d3e1(j)
//         0051d3ed     MOV        this,dword ptr [EAX + 0x38]
//         0051d3f0     PUSH       this=>DAT_fffffff8
//         0051d3f1     CALL       dword ptr [->GDI32.DLL::SetTextColor]            = 0048b318
//                              tpnl_pop.cpp:278 (21)
//         0051d3f7     MOV        EDX,dword ptr [ESP + 0x18]
//         0051d3fb     DEC        EBX
//         0051d3fc     DEC        EDX
//         0051d3fd     PUSH       EBX
//         0051d3fe     PUSH       EDX=>DAT_fffffff8
//         0051d3ff     PUSH       EBP=>DAT_fffffff4
//         0051d400     LEA        EAX,[ESP + 0x2c]
//         0051d404     PUSH       EDI=>DAT_fffffff0
//         0051d405     PUSH       EAX
//         0051d406     CALL       dword ptr [->USER32.DLL::SetRect]                = 0048b002
//                              tpnl_pop.cpp:279 (27)
//         0051d40c     MOV        EAX,dword ptr [ESI + 0x20]
//         0051d40f     LEA        this,[ESP + 0x20]
//         0051d413     PUSH       0x21
//         0051d415     PUSH       this=>DAT_fffffff8
//         0051d416     MOV        this,dword ptr [EAX + 0x38]
//         0051d419     LEA        EDX,[ESP + 0x48]
//         0051d41d     PUSH       offset DAT_fffffff4
//         0051d41f     PUSH       EDX=>DAT_fffffff0
//         0051d420     PUSH       this
//         0051d421     CALL       dword ptr [->USER32.DLL::DrawTextA]              = 0048b10a
//                              tpnl_pop.cpp:285 (18)
//         0051d427     MOV        EAX,dword ptr [ESI + 0x20]
//         0051d42a     MOV        EDX,dword ptr [ESP + 0x3c]
//         0051d42e     PUSH       EDX
//         0051d42f     MOV        this,dword ptr [EAX + 0x38]
//         0051d432     PUSH       this=>DAT_fffffff8
//         0051d433     CALL       dword ptr [->GDI32.DLL::SelectObject]            = 0048b192
//                              tpnl_pop.cpp:286 (15)
//         0051d439     MOV        EDX,dword ptr [ESI + 0x20]
//         0051d43c     PUSH       0x0
//         0051d43e     MOV        EAX,dword ptr [EDX + 0x38]
//         0051d441     PUSH       EAX=>DAT_fffffff8
//         0051d442     CALL       dword ptr [->GDI32.DLL::SelectClipRgn]           = 0048b2fc
//                              tpnl_pop.cpp:287 (13)
//         0051d448     MOV        this,dword ptr [ESI + 0x20]
//         0051d44b     PUSH       s_tpnl_tim::draw                                 = "tpnl_tim::draw"
//         0051d450     CALL       TDrawArea::ReleaseDc                             void ReleaseDc(TDrawArea * this, char * param
//                              Symbol Ref: No symbol: finish_up
//                               LAB_0051d455                                                 XREF[1]:     0051d236(j)
//                              tpnl_pop.cpp:292 (11)
//         0051d455     MOV        EDX,dword ptr [ESP + 0x34]
//         0051d459     MOV        this,ESI
//         0051d45b     CALL       dword ptr [EDX + 0x2c]
//         0051d45e     POP        EBX
//         0051d45f     POP        EBP
//                               LAB_0051d460                                                 XREF[3]:     0051d06f(j), 0051d078(j),
//                                                                                                         0051d081(j)
//                              tpnl_pop.cpp:293 (9)
//         0051d460     POP        EDI
//         0051d461     POP        ESI
//         0051d462     ADD        ESP,0x130
//         0051d468     RET
//         0051d469     ??         90h
//         0051d46a     NOP
//         0051d46b     NOP
//         0051d46c     NOP
//         0051d46d     NOP
//         0051d46e     NOP
//         0051d46f     NOP
    return;
}

void TRIBE_Panel_Pop::get_true_render_rect(tagRECT* param_1) {
    /* TODO: Stub */
//                              void __thiscall get_true_render_rect(TRIBE_Panel_Pop * this, tagRECT
//              void              <VOID>         <RETURN>
//              TRIBE_Panel_Po    ECX:4 (auto)   this
//              tagRECT *         Stack[0x4]:4   param_1                   XREF[2]:     0051d48f(R), 0051d4b2(R)
//                               ?get_true_render_rect@TRIBE_Panel_Pop@@UAEXAAUtagRECT@@@Z    XREF[1]:     00576e78(*)
//                               TRIBE_Panel_Pop::get_true_render_rect
//                              tpnl_pop.cpp:299 (31)
//         0051d470     MOV        EAX,dword ptr [ECX + this->ImageBuffer]
//         0051d476     TEST       EAX,EAX
//         0051d478     JZ         LAB_0051d4b2
//         0051d47a     MOV        EAX,dword ptr [ECX + this->_padding_]
//         0051d47d     TEST       EAX,EAX
//         0051d47f     JZ         LAB_0051d4b2
//         0051d481     MOV        EAX,dword ptr [ECX + this->_padding_]
//         0051d484     TEST       EAX,EAX
//         0051d486     JZ         LAB_0051d4b2
//         0051d488     MOV        EAX,dword ptr [ECX + this->_padding_]
//         0051d48b     TEST       EAX,EAX
//         0051d48d     JZ         LAB_0051d4b2
//                              tpnl_pop.cpp:305 (32)
//         0051d48f     MOV        EAX,dword ptr [ESP + param_1]
//         0051d493     ADD        this,0x148
//         0051d499     MOV        EDX,dword ptr [this->_padding_]
//         0051d49b     MOV        dword ptr [EAX],EDX
//         0051d49d     MOV        EDX,dword ptr [ECX + this->_padding_]
//         0051d4a0     MOV        dword ptr [EAX + 0x4],EDX
//         0051d4a3     MOV        EDX,dword ptr [ECX + this->_padding_]
//         0051d4a6     MOV        dword ptr [EAX + 0x8],EDX
//         0051d4a9     MOV        this,dword ptr [ECX + this->_padding_]
//         0051d4ac     MOV        dword ptr [EAX + 0xc],this
//                              tpnl_pop.cpp:307 (3)
//         0051d4af     RET        0x4
//                               LAB_0051d4b2                                                 XREF[4]:     0051d478(j), 0051d47f(j),
//                                                                                                         0051d486(j), 0051d48d(j)
//                              tpnl_pop.cpp:303 (32)
//         0051d4b2     MOV        EDX,dword ptr [ESP + param_1]
//         0051d4b6     ADD        this,0x8c
//         0051d4bc     MOV        EAX,dword ptr [this->_padding_]
//         0051d4be     MOV        dword ptr [EDX],EAX
//         0051d4c0     MOV        EAX,dword ptr [ECX + this->_padding_]
//         0051d4c3     MOV        dword ptr [EDX + 0x4],EAX
//         0051d4c6     MOV        EAX,dword ptr [ECX + this->_padding_]
//         0051d4c9     MOV        dword ptr [EDX + 0x8],EAX
//         0051d4cc     MOV        this,dword ptr [ECX + this->_padding_]
//         0051d4cf     MOV        dword ptr [EDX + 0xc],this
//                              tpnl_pop.cpp:307 (3)
//         0051d4d2     RET        0x4
//         0051d4d5     ??         90h
//         0051d4d6     NOP
//         0051d4d7     NOP
//         0051d4d8     NOP
//         0051d4d9     NOP
//         0051d4da     NOP
//         0051d4db     NOP
//         0051d4dc     NOP
//         0051d4dd     NOP
//         0051d4de     NOP
//         0051d4df     NOP
    return;
}

long TRIBE_Panel_Pop::handle_idle() {
    /* TODO: Stub */
//                              long __thiscall handle_idle(TRIBE_Panel_Pop * this)
//              long              EAX:4          <RETURN>
//              TRIBE_Panel_Po    ECX:4 (auto)   this
//                               ?handle_idle@TRIBE_Panel_Pop@@UAEJXZ                         XREF[1]:     00576e0c(*)
//                               TRIBE_Panel_Pop::handle_idle
//                              tpnl_pop.cpp:313 (5)
//         0051d4e0     CALL       TPanel::handle_idle                              long handle_idle(TPanel * this)
//                              tpnl_pop.cpp:327 (2)
//         0051d4e5     XOR        EAX,EAX
//                              tpnl_pop.cpp:328 (1)
//         0051d4e7     RET
//         0051d4e8     ??         90h
//         0051d4e9     NOP
//         0051d4ea     NOP
//         0051d4eb     NOP
//         0051d4ec     NOP
//         0051d4ed     NOP
//         0051d4ee     NOP
//         0051d4ef     NOP
    return 0;
}

int TRIBE_Panel_Pop::render_to_image_buffer() {
    /* TODO: Stub */
//                              int __thiscall render_to_image_buffer(TRIBE_Panel_Pop * this)
//              int               EAX:4          <RETURN>
//              TRIBE_Panel_Po    ECX:4 (auto)   this
//              char[256]         Stack[-0x104   str
//              void *            Stack[-0x108   old_font
//              tagRECT           Stack[-0x118   rect
//                               ?render_to_image_buffer@TRIBE_Panel_Pop@@IAEHXZ              XREF[1]:     draw:0051d197(c)
//                               TRIBE_Panel_Pop::render_to_image_buffer
//                              tpnl_pop.cpp:334 (12)
//         0051d4f0     SUB        ESP,0x114
//         0051d4f6     PUSH       EBX
//         0051d4f7     PUSH       EBP
//         0051d4f8     PUSH       ESI
//         0051d4f9     MOV        ESI,this
//         0051d4fb     PUSH       EDI
//                              tpnl_pop.cpp:340 (12)
//         0051d4fc     MOV        this,dword ptr [ESI + 0x124]
//         0051d502     TEST       this,this
//         0051d504     JNZ        LAB_0051d513
//         0051d506     XOR        EAX,EAX
//                              tpnl_pop.cpp:412 (11)
//         0051d508     POP        EDI
//         0051d509     POP        ESI
//         0051d50a     POP        EBP
//         0051d50b     POP        EBX
//         0051d50c     ADD        ESP,0x114
//         0051d512     RET
//                               LAB_0051d513                                                 XREF[1]:     0051d504(j)
//                              tpnl_pop.cpp:345 (14)
//         0051d513     LEA        EDI,[ESI + 0x128]
//         0051d519     PUSH       0x1
//         0051d51b     PUSH       EDI
//         0051d51c     CALL       TDrawArea::PtrClear                              void PtrClear(TDrawArea * this, tagRECT * par
//                              tpnl_pop.cpp:349 (20)
//         0051d521     MOV        this,dword ptr [ESI + 0x124]
//         0051d527     PUSH       s_tpnl_tim::render_to_image_buffer               = "tpnl_tim::render_to_image_buffer"
//         0051d52c     CALL       TDrawArea::GetDc                                 void * GetDc(TDrawArea * this, char * param_1)
//         0051d531     TEST       EAX,EAX
//         0051d533     JNZ        LAB_0051d540
//                              tpnl_pop.cpp:412 (11)
//         0051d535     POP        EDI
//         0051d536     POP        ESI
//         0051d537     POP        EBP
//         0051d538     POP        EBX
//         0051d539     ADD        ESP,0x114
//         0051d53f     RET
//                               LAB_0051d540                                                 XREF[1]:     0051d533(j)
//                              tpnl_pop.cpp:353 (12)
//         0051d540     MOV        this,dword ptr [ESI + 0x124]
//         0051d546     PUSH       EDI
//         0051d547     CALL       TDrawArea::SetClipRect                           void SetClipRect(TDrawArea * this, tagRECT *
//                              tpnl_pop.cpp:354 (23)
//         0051d54c     MOV        this,dword ptr [ESI + 0x124]
//         0051d552     MOV        EAX,dword ptr [ESI + 0x120]
//         0051d558     PUSH       EAX
//         0051d559     MOV        EDX,dword ptr [ECX + this->_padding_]
//         0051d55c     PUSH       EDX
//         0051d55d     CALL       dword ptr [->GDI32.DLL::SelectClipRgn]           = 0048b2fc
//                              tpnl_pop.cpp:356 (27)
//         0051d563     MOV        this,dword ptr [ESI + 0x124]
//         0051d569     MOV        EAX,dword ptr [ESI + 0xf4]
//         0051d56f     PUSH       EAX
//         0051d570     MOV        EDX,dword ptr [ECX + this->_padding_]
//         0051d573     PUSH       EDX
//         0051d574     CALL       dword ptr [->GDI32.DLL::SelectObject]            = 0048b192
//         0051d57a     MOV        dword ptr [ESP + 0x20],EAX
//                              tpnl_pop.cpp:357 (18)
//         0051d57e     MOV        EAX,dword ptr [ESI + 0x124]
//         0051d584     PUSH       0x1
//         0051d586     MOV        this,dword ptr [EAX + 0x38]
//         0051d589     PUSH       this
//         0051d58a     CALL       dword ptr [->GDI32.DLL::SetBkMode]               = 0048b340
//                              tpnl_pop.cpp:359 (42)
//         0051d590     MOV        EDX,dword ptr [ESI + 0x114]
//         0051d596     MOV        EAX,dword ptr [ESI + 0x110]
//         0051d59c     PUSH       EDX
//         0051d59d     PUSH       EAX
//                              language.dll match for 0x2b2a: "pop: "
//         0051d59e     PUSH       0x2b2a
//         0051d5a3     MOV        this,ESI
//         0051d5a5     CALL       TPanel::get_string                               char * get_string(TPanel * this, int param_1)
//         0051d5aa     PUSH       EAX
//         0051d5ab     LEA        this,[ESP + 0x30]
//         0051d5af     PUSH       s_%s%ld/%ld                                      = "%s%ld/%ld"
//         0051d5b4     PUSH       this
//         0051d5b5     CALL       sprintf                                          undefined sprintf()
//                              tpnl_pop.cpp:362 (26)
//         0051d5ba     MOV        EAX,dword ptr [ESI + 0x124]
//         0051d5c0     MOV        EDX,dword ptr [ESI + 0xfc]
//         0051d5c6     ADD        ESP,0x14
//         0051d5c9     MOV        this,dword ptr [EAX + 0x38]
//         0051d5cc     PUSH       EDX
//         0051d5cd     PUSH       this
//         0051d5ce     CALL       dword ptr [->GDI32.DLL::SetTextColor]            = 0048b318
//                              tpnl_pop.cpp:368 (3)
//         0051d5d4     MOV        EBP,dword ptr [ESI + 0x14]
//                              tpnl_pop.cpp:369 (6)
//         0051d5d7     MOV        EDI,dword ptr [ESI + 0x18]
//         0051d5da     SUB        EBP,0x2
//                              tpnl_pop.cpp:371 (27)
//         0051d5dd     DEC        EDI
//         0051d5de     INC        EBP
//         0051d5df     MOV        EBX,dword ptr [->USER32.DLL::SetRect]            = 0048b002
//         0051d5e5     LEA        EAX,[EDI + -0x2]
//         0051d5e8     LEA        EDX,[ESP + 0x10]
//         0051d5ec     LEA        this,[EBP + -0x2]
//         0051d5ef     PUSH       EAX
//         0051d5f0     PUSH       this
//         0051d5f1     PUSH       0x0
//         0051d5f3     PUSH       0x0
//         0051d5f5     PUSH       EDX
//         0051d5f6     CALL       EBX=>USER32.DLL::SetRect
//                              tpnl_pop.cpp:372 (30)
//         0051d5f8     MOV        EDX,dword ptr [ESI + 0x124]
//         0051d5fe     LEA        EAX,[ESP + 0x10]
//         0051d602     PUSH       0x21
//         0051d604     PUSH       EAX
//         0051d605     MOV        EAX,dword ptr [EDX + 0x38]
//         0051d608     LEA        this,[ESP + 0x2c]
//         0051d60c     PUSH       -0x1
//         0051d60e     PUSH       this
//         0051d60f     PUSH       EAX
//         0051d610     CALL       dword ptr [->USER32.DLL::DrawTextA]              = 0048b10a
//                              tpnl_pop.cpp:374 (16)
//         0051d616     LEA        EAX,[EBP + -0x2]
//         0051d619     PUSH       EDI
//         0051d61a     PUSH       EAX
//         0051d61b     PUSH       0x2
//         0051d61d     LEA        this,[ESP + 0x1c]
//         0051d621     PUSH       0x0
//         0051d623     PUSH       this
//         0051d624     CALL       EBX=>USER32.DLL::SetRect
//                              tpnl_pop.cpp:375 (30)
//         0051d626     MOV        this,dword ptr [ESI + 0x124]
//         0051d62c     LEA        EDX,[ESP + 0x10]
//         0051d630     PUSH       0x21
//         0051d632     PUSH       EDX
//         0051d633     MOV        EDX,dword ptr [ECX + this->_padding_]
//         0051d636     LEA        EAX,[ESP + 0x2c]
//         0051d63a     PUSH       -0x1
//         0051d63c     PUSH       EAX
//         0051d63d     PUSH       EDX
//         0051d63e     CALL       dword ptr [->USER32.DLL::DrawTextA]              = 0048b10a
//                              tpnl_pop.cpp:377 (16)
//         0051d644     LEA        EAX,[EDI + -0x2]
//         0051d647     PUSH       EAX
//         0051d648     PUSH       EBP
//         0051d649     PUSH       0x0
//         0051d64b     LEA        EAX,[ESP + 0x1c]
//         0051d64f     PUSH       0x2
//         0051d651     PUSH       EAX
//         0051d652     CALL       EBX=>USER32.DLL::SetRect
//                              tpnl_pop.cpp:378 (30)
//         0051d654     MOV        EAX,dword ptr [ESI + 0x124]
//         0051d65a     LEA        this,[ESP + 0x10]
//         0051d65e     PUSH       0x21
//         0051d660     PUSH       this
//         0051d661     MOV        this,dword ptr [EAX + 0x38]
//         0051d664     LEA        EDX,[ESP + 0x2c]
//         0051d668     PUSH       -0x1
//         0051d66a     PUSH       EDX
//         0051d66b     PUSH       this
//         0051d66c     CALL       dword ptr [->USER32.DLL::DrawTextA]              = 0048b10a
//                              tpnl_pop.cpp:380 (13)
//         0051d672     PUSH       EDI
//         0051d673     PUSH       EBP
//         0051d674     PUSH       0x2
//         0051d676     LEA        EDX,[ESP + 0x1c]
//         0051d67a     PUSH       0x2
//         0051d67c     PUSH       EDX
//         0051d67d     CALL       EBX=>USER32.DLL::SetRect
//                              tpnl_pop.cpp:381 (30)
//         0051d67f     MOV        EDX,dword ptr [ESI + 0x124]
//         0051d685     LEA        EAX,[ESP + 0x10]
//         0051d689     PUSH       0x21
//         0051d68b     PUSH       EAX
//         0051d68c     MOV        EAX,dword ptr [EDX + 0x38]
//         0051d68f     LEA        this,[ESP + 0x2c]
//         0051d693     PUSH       -0x1
//         0051d695     PUSH       this
//         0051d696     PUSH       EAX
//         0051d697     CALL       dword ptr [->USER32.DLL::DrawTextA]              = 0048b10a
//                              tpnl_pop.cpp:385 (9)
//         0051d69d     CMP        byte ptr [ESI + 0x118],0x1
//         0051d6a4     JNZ        LAB_0051d6ae
//                              tpnl_pop.cpp:386 (6)
//         0051d6a6     MOV        this,dword ptr [ESI + 0x100]
//                              tpnl_pop.cpp:387 (2)
//         0051d6ac     JMP        LAB_0051d6b4
//                               LAB_0051d6ae                                                 XREF[1]:     0051d6a4(j)
//                              tpnl_pop.cpp:388 (23)
//         0051d6ae     MOV        this,dword ptr [ESI + 0xf8]
//                               LAB_0051d6b4                                                 XREF[1]:     0051d6ac(j)
//         0051d6b4     MOV        EDX,dword ptr [ESI + 0x124]
//         0051d6ba     PUSH       this
//         0051d6bb     MOV        EAX,dword ptr [EDX + 0x38]
//         0051d6be     PUSH       EAX
//         0051d6bf     CALL       dword ptr [->GDI32.DLL::SetTextColor]            = 0048b318
//                              tpnl_pop.cpp:390 (15)
//         0051d6c5     DEC        EDI
//         0051d6c6     DEC        EBP
//         0051d6c7     PUSH       EDI
//         0051d6c8     PUSH       EBP
//         0051d6c9     PUSH       0x1
//         0051d6cb     LEA        this,[ESP + 0x1c]
//         0051d6cf     PUSH       0x1
//         0051d6d1     PUSH       this
//         0051d6d2     CALL       EBX=>USER32.DLL::SetRect
//                              tpnl_pop.cpp:391 (30)
//         0051d6d4     MOV        this,dword ptr [ESI + 0x124]
//         0051d6da     LEA        EDX,[ESP + 0x10]
//         0051d6de     PUSH       0x21
//         0051d6e0     PUSH       EDX
//         0051d6e1     MOV        EDX,dword ptr [ECX + this->_padding_]
//         0051d6e4     LEA        EAX,[ESP + 0x2c]
//         0051d6e8     PUSH       -0x1
//         0051d6ea     PUSH       EAX
//         0051d6eb     PUSH       EDX
//         0051d6ec     CALL       dword ptr [->USER32.DLL::DrawTextA]              = 0048b10a
//                              tpnl_pop.cpp:394 (21)
//         0051d6f2     MOV        this,dword ptr [ESI + 0x124]
//         0051d6f8     MOV        EAX,dword ptr [ESP + 0x20]
//         0051d6fc     PUSH       EAX
//         0051d6fd     MOV        EDX,dword ptr [ECX + this->_padding_]
//         0051d700     PUSH       EDX
//         0051d701     CALL       dword ptr [->GDI32.DLL::SelectObject]            = 0048b192
//                              tpnl_pop.cpp:395 (19)
//         0051d707     MOV        EAX,dword ptr [ESI + 0x124]
//         0051d70d     XOR        EDI,EDI
//         0051d70f     PUSH       EDI
//         0051d710     MOV        this,dword ptr [EAX + 0x38]
//         0051d713     PUSH       this
//         0051d714     CALL       dword ptr [->GDI32.DLL::SelectClipRgn]           = 0048b2fc
//                              tpnl_pop.cpp:396 (16)
//         0051d71a     MOV        this,dword ptr [ESI + 0x124]
//         0051d720     PUSH       s_tpnl_tim::render_to_image_buffer               = "tpnl_tim::render_to_image_buffer"
//         0051d725     CALL       TDrawArea::ReleaseDc                             void ReleaseDc(TDrawArea * this, char * param
//                              tpnl_pop.cpp:400 (3)
//         0051d72a     MOV        EAX,dword ptr [ESI + 0x14]
//                              tpnl_pop.cpp:401 (3)
//         0051d72d     MOV        this,dword ptr [ESI + 0x18]
//                              tpnl_pop.cpp:404 (18)
//         0051d730     MOV        EDX,dword ptr [ESI + 0x8c]
//         0051d736     MOV        dword ptr [ESI + 0x138],EDI
//         0051d73c     MOV        dword ptr [ESI + 0x13c],EDI
//                              tpnl_pop.cpp:405 (20)
//         0051d742     MOV        EDI,dword ptr [ESI + 0x90]
//         0051d748     DEC        EAX
//         0051d749     DEC        this
//         0051d74a     MOV        dword ptr [ESI + 0x148],EDX
//         0051d750     MOV        dword ptr [ESI + 0x14c],EDI
//                              tpnl_pop.cpp:406 (2)
//         0051d756     ADD        EDX,EAX
//                              tpnl_pop.cpp:407 (26)
//         0051d758     ADD        EDI,this
//         0051d75a     MOV        dword ptr [ESI + 0x154],EDI
//         0051d760     MOV        dword ptr [ESI + 0x140],EAX
//         0051d766     MOV        dword ptr [ESI + 0x144],this
//         0051d76c     MOV        dword ptr [ESI + 0x150],EDX
//                              tpnl_pop.cpp:409 (10)
//         0051d772     MOV        dword ptr [ESI + 0x158],0x1
//                              tpnl_pop.cpp:412 (16)
//         0051d77c     POP        EDI
//         0051d77d     POP        ESI
//         0051d77e     POP        EBP
//         0051d77f     MOV        EAX,0x1
//         0051d784     POP        EBX
//         0051d785     ADD        ESP,0x114
//         0051d78b     RET
//         0051d78c     ??         90h
//         0051d78d     NOP
//         0051d78e     NOP
//         0051d78f     NOP
    return 0;
}

