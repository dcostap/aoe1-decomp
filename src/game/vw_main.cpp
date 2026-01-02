#include "../common.h"
#include "vw_main.h"

RGE_Main_View::RGE_Main_View() {
    /* TODO: Stub */
//                              undefined __thiscall RGE_Main_View(RGE_Main_View * this)
//              undefined         <UNASSIGNED>   <RETURN>
//              RGE_Main_View *   ECX:4 (auto)   this
//                               ??0RGE_Main_View@@QAE@XZ                                     XREF[2]:     TRIBE_Screen_Game:004942a6(c),
//                               RGE_Main_View::RGE_Main_View                                              TRIBE_Screen_Sed:004a83d3(c)
//                              vw_main.cpp:48 (8)
//         0053dab0     PUSH       ESI
//         0053dab1     MOV        ESI,this
//         0053dab3     CALL       RGE_View::RGE_View                               undefined RGE_View(RGE_View * this)
//                              vw_main.cpp:51 (2)
//         0053dab8     XOR        EAX,EAX
//                              vw_main.cpp:55 (21)
//         0053daba     OR         this,0xffffffff
//         0053dabd     MOV        dword ptr [ESI + 0x360],EAX
//         0053dac3     MOV        dword ptr [ESI + 0x364],EAX
//         0053dac9     MOV        dword ptr [ESI + 0x368],EAX
//                              vw_main.cpp:58 (6)
//         0053dacf     MOV        dword ptr [ESI + 0x374],EAX
//                              vw_main.cpp:59 (6)
//         0053dad5     MOV        dword ptr [ESI + 0x378],EAX
//                              vw_main.cpp:61 (34)
//         0053dadb     MOV        dword ptr [ESI + 0x37c],EAX
//         0053dae1     MOV        dword ptr [ESI],RGE_Main_View::`vftable'         = 0053db10
//         0053dae7     MOV        dword ptr [ESI + 0xc0],0xa
//         0053daf1     MOV        dword ptr [ESI + 0x36c],this
//         0053daf7     MOV        dword ptr [ESI + 0x370],this
//                              vw_main.cpp:62 (4)
//         0053dafd     MOV        EAX,ESI
//         0053daff     POP        ESI
//         0053db00     RET
//         0053db01     ??         90h
//         0053db02     NOP
//         0053db03     NOP
//         0053db04     NOP
//         0053db05     NOP
//         0053db06     NOP
//         0053db07     NOP
//         0053db08     NOP
//         0053db09     NOP
//         0053db0a     NOP
//         0053db0b     NOP
//         0053db0c     NOP
//         0053db0d     NOP
//         0053db0e     NOP
//         0053db0f     NOP
}

long RGE_Main_View::handle_idle() {
    /* TODO: Stub */
//                              long __thiscall handle_idle(RGE_Main_View * this)
//              long              EAX:4          <RETURN>
//              RGE_Main_View *   ECX:4 (auto)   this
//                               ?handle_idle@RGE_Main_View@@UAEJXZ                           XREF[2]:     00572af4(*), 0057783c(*)
//                               RGE_Main_View::handle_idle
//                              vw_main.cpp:68 (1)
//         0053db40     PUSH       ESI
//                              vw_main.cpp:70 (16)
//         0053db41     PUSH       0x5
//         0053db43     PUSH       0x45
//         0053db45     MOV        ESI,this
//         0053db47     PUSH       0x45
//         0053db49     CALL       color_log                                        void color_log(uchar param_1, uchar param_2,
//         0053db4e     ADD        ESP,0xc
//                              vw_main.cpp:73 (7)
//         0053db51     MOV        this,ESI
//         0053db53     CALL       RGE_Main_View::do_auto_scroll                    int do_auto_scroll(RGE_Main_View * this)
//                              vw_main.cpp:75 (14)
//         0053db58     PUSH       0x5
//         0053db5a     PUSH       0x16
//         0053db5c     PUSH       0x45
//         0053db5e     CALL       color_log                                        void color_log(uchar param_1, uchar param_2,
//         0053db63     ADD        ESP,0xc
//                              vw_main.cpp:78 (7)
//         0053db66     MOV        this,ESI
//         0053db68     CALL       RGE_Main_View::handle_keys                       int handle_keys(RGE_Main_View * this)
//                              vw_main.cpp:80 (14)
//         0053db6d     PUSH       0x5
//         0053db6f     PUSH       0x24
//         0053db71     PUSH       0x45
//         0053db73     CALL       color_log                                        void color_log(uchar param_1, uchar param_2,
//         0053db78     ADD        ESP,0xc
//                              vw_main.cpp:83 (7)
//         0053db7b     MOV        this,ESI
//         0053db7d     CALL       TPanel::handle_idle                              long handle_idle(TPanel * this)
//                              vw_main.cpp:85 (16)
//         0053db82     PUSH       0x5
//         0053db84     PUSH       0x5f
//         0053db86     PUSH       0x45
//         0053db88     MOV        ESI,EAX
//         0053db8a     CALL       color_log                                        void color_log(uchar param_1, uchar param_2,
//         0053db8f     ADD        ESP,0xc
//                              vw_main.cpp:87 (2)
//         0053db92     MOV        EAX,ESI
//                              vw_main.cpp:88 (2)
//         0053db94     POP        ESI
//         0053db95     RET
//         0053db96     ??         90h
//         0053db97     NOP
//         0053db98     NOP
//         0053db99     NOP
//         0053db9a     NOP
//         0053db9b     NOP
//         0053db9c     NOP
//         0053db9d     NOP
//         0053db9e     NOP
//         0053db9f     NOP
    return 0;
}

int RGE_Main_View::do_auto_scroll() {
    /* TODO: Stub */
//                              int __thiscall do_auto_scroll(RGE_Main_View * this)
//              int               EAX:4          <RETURN>
//              RGE_Main_View *   ECX:4 (auto)   this
//              tagRECT           Stack[-0x14]   rect
//              tagPOINT          Stack[-0x24]:8 point
//              float             Stack[-0x2c]:4 scroll_dist2
//              short             Stack[-0x30]:2 vert_scroll
//                               ?do_auto_scroll@RGE_Main_View@@QAEHXZ                        XREF[1]:     handle_idle:0053db53(c)
//                               RGE_Main_View::do_auto_scroll
//                              vw_main.cpp:99 (8)
//         0053dba0     SUB        ESP,0x2c
//         0053dba3     PUSH       EBX
//         0053dba4     PUSH       EBP
//         0053dba5     PUSH       ESI
//         0053dba6     MOV        ESI,this
//                              vw_main.cpp:117 (152)
//         0053dba8     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0053dbae     PUSH       EDI
//         0053dbaf     MOV        EAX,dword ptr [ECX + this->_padding_]
//         0053dbb5     CMP        EAX,0x4
//         0053dbb8     JZ         LAB_0053dbcd
//         0053dbba     CMP        EAX,0x6
//         0053dbbd     JZ         LAB_0053dbcd
//         0053dbbf     CMP        EAX,0x7
//         0053dbc2     JZ         LAB_0053dbcd
//         0053dbc4     CMP        EAX,0x5
//         0053dbc7     JNZ        LAB_0053de91
//                               LAB_0053dbcd                                                 XREF[3]:     0053dbb8(j), 0053dbbd(j),
//                                                                                                         0053dbc2(j)
//         0053dbcd     CALL       RGE_Base_Game::get_paused                        int get_paused(RGE_Base_Game * this)
//         0053dbd2     TEST       EAX,EAX
//         0053dbd4     JNZ        LAB_0053de91
//         0053dbda     MOV        EAX,[rge_base_game]                              = 00000000
//         0053dbdf     XOR        EBP,EBP
//         0053dbe1     MOV        this,dword ptr [EAX + 0xc]
//         0053dbe4     CMP        dword ptr [this->_padding_ + 0x8c0],EBP
//         0053dbea     JZ         LAB_0053de91
//         0053dbf0     CALL       dword ptr [->USER32.DLL::GetForegroundWindow]    = 0048b116
//         0053dbf6     MOV        EDX,dword ptr [ESI + 0x20]
//         0053dbf9     CMP        EAX,dword ptr [EDX + 0x4]
//         0053dbfc     JNZ        LAB_0053de91
//         0053dc02     MOV        this,panel_system
//         0053dc07     CALL       TPanelSystem::modalPanel                         TPanel * modalPanel(TPanelSystem * this)
//         0053dc0c     TEST       EAX,EAX
//         0053dc0e     JNZ        LAB_0053de91
//         0053dc14     MOV        this,panel_system
//         0053dc19     CALL       TPanelSystem::mouseOwner                         TPanel * mouseOwner(TPanelSystem * this)
//         0053dc1e     TEST       EAX,EAX
//         0053dc20     JZ         LAB_0053dc34
//         0053dc22     MOV        this,panel_system
//         0053dc27     CALL       TPanelSystem::mouseOwner                         TPanel * mouseOwner(TPanelSystem * this)
//         0053dc2c     CMP        EAX,ESI
//         0053dc2e     JNZ        LAB_0053de91
//                               LAB_0053dc34                                                 XREF[1]:     0053dc20(j)
//         0053dc34     CMP        dword ptr [ESI + 0x378],EBP
//         0053dc3a     JNZ        LAB_0053de91
//                              vw_main.cpp:144 (18)
//         0053dc40     MOV        this,dword ptr [ESI + 0x20]
//         0053dc43     LEA        EAX,[ESP + 0x2c]
//         0053dc47     PUSH       EAX
//         0053dc48     MOV        EDX,dword ptr [ECX + this->_padding_]
//         0053dc4b     PUSH       EDX
//         0053dc4c     CALL       dword ptr [->USER32.DLL::GetWindowRect]          = 0048ade6
//                              vw_main.cpp:149 (11)
//         0053dc52     LEA        EAX,[ESP + 0x1c]
//         0053dc56     PUSH       EAX
//         0053dc57     CALL       dword ptr [->USER32.DLL::GetCursorPos]           = 0048aeba
//                              vw_main.cpp:154 (6)
//         0053dc5d     MOV        this,dword ptr [rge_base_game]                   = 00000000
//                              vw_main.cpp:156 (39)
//         0053dc63     MOV        EDI,dword ptr [->USER32.DLL::GetAsyncKeyState]   = 0048b12c
//         0053dc69     PUSH       0x1
//         0053dc6b     MOV        dword ptr [ESP + 0x14],EBP
//         0053dc6f     MOV        EBX,dword ptr [ECX + this->_padding_]
//         0053dc72     CALL       EDI=>USER32.DLL::GetAsyncKeyState
//         0053dc74     TEST       AX,AX
//         0053dc77     JL         LAB_0053de6d
//         0053dc7d     PUSH       0x2
//         0053dc7f     CALL       EDI=>USER32.DLL::GetAsyncKeyState
//         0053dc81     TEST       AX,AX
//         0053dc84     JL         LAB_0053de6d
//                              vw_main.cpp:158 (20)
//         0053dc8a     MOV        EAX,dword ptr [EBX + 0x8c4]
//         0053dc90     MOV        EDX,dword ptr [ESP + 0x2c]
//         0053dc94     MOV        this,dword ptr [ESP + 0x1c]
//         0053dc98     ADD        EDX,EAX
//         0053dc9a     CMP        this,EDX
//         0053dc9c     JGE        LAB_0053dca3
//                              vw_main.cpp:159 (3)
//         0053dc9e     OR         EBP,0xffffffff
//                              vw_main.cpp:160 (12)
//         0053dca1     JMP        LAB_0053dcb2
//                               LAB_0053dca3                                                 XREF[1]:     0053dc9c(j)
//         0053dca3     MOV        EDX,dword ptr [ESP + 0x34]
//         0053dca7     SUB        EDX,EAX
//         0053dca9     CMP        this,EDX
//         0053dcab     JLE        LAB_0053dcb2
//                              vw_main.cpp:161 (5)
//         0053dcad     MOV        EBP,0x1
//                               LAB_0053dcb2                                                 XREF[2]:     0053dca1(j), 0053dcab(j)
//                              vw_main.cpp:163 (15)
//         0053dcb2     MOV        this,dword ptr [ESP + 0x30]
//         0053dcb6     LEA        EDX,[this->_padding_ + EAX*0x1]
//         0053dcb9     MOV        this,dword ptr [ESP + 0x20]
//         0053dcbd     CMP        this,EDX
//         0053dcbf     JGE        LAB_0053dccb
//                              vw_main.cpp:164 (8)
//         0053dcc1     MOV        dword ptr [ESP + 0x10],0xffffffff
//                              vw_main.cpp:165 (12)
//         0053dcc9     JMP        LAB_0053dcdd
//                               LAB_0053dccb                                                 XREF[1]:     0053dcbf(j)
//         0053dccb     MOV        EDX,dword ptr [ESP + 0x38]
//         0053dccf     SUB        EDX,EAX
//         0053dcd1     CMP        this,EDX
//         0053dcd3     JLE        LAB_0053dcdd
//                              vw_main.cpp:166 (8)
//         0053dcd5     MOV        dword ptr [ESP + 0x10],0x1
//                               LAB_0053dcdd                                                 XREF[2]:     0053dcc9(j), 0053dcd3(j)
//                              vw_main.cpp:168 (16)
//         0053dcdd     TEST       BP,BP
//         0053dce0     JNZ        LAB_0053dced
//         0053dce2     CMP        word ptr [ESP + 0x10],BP
//         0053dce7     JZ         LAB_0053de6d
//                               LAB_0053dced                                                 XREF[1]:     0053dce0(j)
//                              vw_main.cpp:170 (15)
//         0053dced     PUSH       0xaa
//         0053dcf2     PUSH       s_C:\msdev\work\age1_x1\vw_main.cp               = "C:\\msdev\\work\\age1_x1\\vw_main.cpp"
//         0053dcf7     CALL       debug_timeGetTime                                ulong debug_timeGetTime(char * param_1, int p
//                              vw_main.cpp:171 (6)
//         0053dcfc     MOV        this,dword ptr [ESI + 0x364]
//                              vw_main.cpp:174 (19)
//         0053dd02     MOV        EDX,dword ptr [ESI + 0x368]
//         0053dd08     MOV        EDI,EAX
//         0053dd0a     SUB        EAX,this
//         0053dd0c     XOR        this,this
//         0053dd0e     ADD        ESP,0x8
//         0053dd11     CMP        EDX,this
//         0053dd13     JNZ        LAB_0053dd27
//                              vw_main.cpp:177 (16)
//         0053dd15     FLD        float ptr [DAT_00577900]                         = align(2)
//         0053dd1b     MOV        dword ptr [ESI + 0x368],0x1
//                              vw_main.cpp:179 (2)
//         0053dd25     JMP        LAB_0053dd75
//                               LAB_0053dd27                                                 XREF[1]:     0053dd13(j)
//                              vw_main.cpp:205 (30)
//         0053dd27     MOV        EDX,dword ptr [EBX + 0x8d0]
//         0053dd2d     MOV        dword ptr [ESP + 0x14],EAX
//         0053dd31     MOV        dword ptr [ESP + 0x18],this
//         0053dd35     MOV        dword ptr [ESP + 0x24],EDX
//         0053dd39     FILD       qword ptr [ESP + 0x14]
//         0053dd3d     MOV        dword ptr [ESP + 0x28],this
//         0053dd41     FIDIV      dword ptr [ESP + 0x24]
//                              vw_main.cpp:206 (15)
//         0053dd45     FLD        ST0
//         0053dd47     CALL       __ftol                                           undefined __ftol()
//         0053dd4c     MOV        dword ptr [ESP + 0x14],EAX
//         0053dd50     FILD       dword ptr [ESP + 0x14]
//                              vw_main.cpp:208 (17)
//         0053dd54     FXCH
//         0053dd56     FSUB       ST0,ST1
//         0053dd58     FCOMP      float ptr [DAT_00577904]
//         0053dd5e     FNSTSW     AX
//         0053dd60     TEST       AH,0x1
//         0053dd63     JZ         LAB_0053dd6d
//                              vw_main.cpp:209 (6)
//         0053dd65     FLD        float ptr [DAT_00577908]
//                              vw_main.cpp:210 (2)
//         0053dd6b     JMP        LAB_0053dd73
//                               LAB_0053dd6d                                                 XREF[1]:     0053dd63(j)
//                              vw_main.cpp:211 (6)
//         0053dd6d     FLD        float ptr [DAT_00577904]
//                               LAB_0053dd73                                                 XREF[1]:     0053dd6b(j)
//                              vw_main.cpp:212 (2)
//         0053dd73     FADDP
//                               LAB_0053dd75                                                 XREF[1]:     0053dd25(j)
//                              vw_main.cpp:216 (15)
//         0053dd75     FCOM       float ptr [EBX + 0x8cc]
//         0053dd7b     FNSTSW     AX
//         0053dd7d     TEST       AH,0x41
//         0053dd80     JNZ        LAB_0053dd8a
//         0053dd82     FSTP       ST0
//                              vw_main.cpp:217 (6)
//         0053dd84     FLD        float ptr [EBX + 0x8cc]
//                               LAB_0053dd8a                                                 XREF[1]:     0053dd80(j)
//                              vw_main.cpp:219 (17)
//         0053dd8a     FCOM       float ptr [DAT_00577908]
//         0053dd90     FNSTSW     AX
//         0053dd92     TEST       AH,0x41
//         0053dd95     JNZ        LAB_0053de6b
//                              vw_main.cpp:224 (4)
//         0053dd9b     FLD        ST0
//         0053dd9d     FADD       ST0,ST0
//                              vw_main.cpp:226 (10)
//         0053dd9f     CMP        BP,-0x1
//         0053dda3     FSTP       float ptr [ESP + 0x14]
//         0053dda7     JNZ        LAB_0053ddc2
//                              vw_main.cpp:227 (23)
//         0053dda9     MOV        this,dword ptr [ESI + 0x100]
//         0053ddaf     PUSH       this
//         0053ddb0     FLD        float ptr [ECX + this->_padding_]
//         0053ddb6     FSUB       ST0,ST1
//         0053ddb8     FLD        float ptr [ECX + this->_padding_]
//         0053ddbe     FSUB       ST0,ST2
//                              vw_main.cpp:228 (8)
//         0053ddc0     JMP        LAB_0053dddf
//                               LAB_0053ddc2                                                 XREF[1]:     0053dda7(j)
//         0053ddc2     CMP        BP,0x1
//         0053ddc6     JNZ        LAB_0053ddf1
//                              vw_main.cpp:229 (41)
//         0053ddc8     MOV        this,dword ptr [ESI + 0x100]
//         0053ddce     PUSH       this
//         0053ddcf     FLD        float ptr [ECX + this->_padding_]
//         0053ddd5     FADD       ST0,ST1
//         0053ddd7     FLD        float ptr [ECX + this->_padding_]
//         0053dddd     FADD       ST0,ST2
//                               LAB_0053dddf                                                 XREF[1]:     0053ddc0(j)
//         0053dddf     FXCH
//         0053dde1     FSTP       float ptr [ESP]
//         0053dde4     PUSH       this
//         0053dde5     FSTP       float ptr [ESP]
//         0053dde8     FSTP       ST0
//         0053ddea     CALL       RGE_Player::set_view_loc                         void set_view_loc(RGE_Player * this, float pa
//         0053ddef     JMP        LAB_0053ddf3
//                               LAB_0053ddf1                                                 XREF[1]:     0053ddc6(j)
//                              vw_main.cpp:227 (2)
//         0053ddf1     FSTP       ST0
//                               LAB_0053ddf3                                                 XREF[1]:     0053ddef(j)
//                              vw_main.cpp:231 (10)
//         0053ddf3     MOV        EAX,dword ptr [ESP + 0x10]
//         0053ddf7     CMP        AX,0xffff
//         0053ddfb     JNZ        LAB_0053de1a
//                              vw_main.cpp:232 (27)
//         0053ddfd     MOV        this,dword ptr [ESI + 0x100]
//         0053de03     PUSH       this
//         0053de04     FLD        float ptr [ECX + this->_padding_]
//         0053de0a     FSUB       float ptr [ESP + 0x18]
//         0053de0e     FLD        float ptr [ECX + this->_padding_]
//         0053de14     FADD       float ptr [ESP + 0x18]
//                              vw_main.cpp:233 (8)
//         0053de18     JMP        LAB_0053de3b
//                               LAB_0053de1a                                                 XREF[1]:     0053ddfb(j)
//         0053de1a     CMP        AX,0x1
//         0053de1e     JNZ        LAB_0053de49
//                              vw_main.cpp:234 (41)
//         0053de20     MOV        this,dword ptr [ESI + 0x100]
//         0053de26     PUSH       this
//         0053de27     FLD        float ptr [ECX + this->_padding_]
//         0053de2d     FADD       float ptr [ESP + 0x18]
//         0053de31     FLD        float ptr [ECX + this->_padding_]
//         0053de37     FSUB       float ptr [ESP + 0x18]
//                               LAB_0053de3b                                                 XREF[1]:     0053de18(j)
//         0053de3b     FXCH
//         0053de3d     FSTP       float ptr [ESP]
//         0053de40     PUSH       this
//         0053de41     FSTP       float ptr [ESP]
//         0053de44     CALL       RGE_Player::set_view_loc                         void set_view_loc(RGE_Player * this, float pa
//                               LAB_0053de49                                                 XREF[1]:     0053de1e(j)
//                              vw_main.cpp:236 (9)
//         0053de49     MOV        EAX,dword ptr [ESI]
//         0053de4b     PUSH       0x1
//         0053de4d     MOV        this,ESI
//         0053de4f     CALL       dword ptr [EAX + 0x20]
//                              vw_main.cpp:237 (10)
//         0053de52     MOV        this,dword ptr [ESI + 0x360]
//         0053de58     TEST       this,this
//         0053de5a     JZ         LAB_0053de63
//                              vw_main.cpp:238 (7)
//         0053de5c     MOV        EDX,dword ptr [this->_padding_]
//         0053de5e     PUSH       0x1
//         0053de60     CALL       dword ptr [EDX + 0x20]
//                               LAB_0053de63                                                 XREF[1]:     0053de5a(j)
//                              vw_main.cpp:240 (6)
//         0053de63     MOV        dword ptr [ESI + 0x364],EDI
//                              vw_main.cpp:219 (4)
//         0053de69     JMP        LAB_0053de6d
//                               LAB_0053de6b                                                 XREF[1]:     0053dd95(j)
//         0053de6b     FSTP       ST0
//                               LAB_0053de6d                                                 XREF[4]:     0053dc77(j), 0053dc84(j),
//                                                                                                         0053dce7(j), 0053de69(j)
//                              vw_main.cpp:246 (12)
//         0053de6d     TEST       BP,BP
//         0053de70     JNZ        LAB_0053de83
//         0053de72     CMP        word ptr [ESP + 0x10],BP
//         0053de77     JNZ        LAB_0053de83
//                              vw_main.cpp:247 (10)
//         0053de79     MOV        dword ptr [ESI + 0x368],0x0
//                               LAB_0053de83                                                 XREF[2]:     0053de70(j), 0053de77(j)
//                              vw_main.cpp:249 (6)
//         0053de83     MOV        EAX,dword ptr [ESI + 0x368]
//                              vw_main.cpp:250 (8)
//         0053de89     POP        EDI
//         0053de8a     POP        ESI
//         0053de8b     POP        EBP
//         0053de8c     POP        EBX
//         0053de8d     ADD        ESP,0x2c
//         0053de90     RET
//                               LAB_0053de91                                                 XREF[7]:     0053dbc7(j), 0053dbd4(j),
//                                                                                                         0053dbea(j), 0053dbfc(j),
//                                                                                                         0053dc0e(j), 0053dc2e(j),
//                                                                                                         0053dc3a(j)
//                              vw_main.cpp:119 (10)
//         0053de91     MOV        dword ptr [ESI + 0x368],0x0
//                              vw_main.cpp:250 (10)
//         0053de9b     POP        EDI
//         0053de9c     POP        ESI
//         0053de9d     POP        EBP
//         0053de9e     XOR        EAX,EAX
//         0053dea0     POP        EBX
//         0053dea1     ADD        ESP,0x2c
//         0053dea4     RET
//         0053dea5     ??         90h
//         0053dea6     NOP
//         0053dea7     NOP
//         0053dea8     NOP
//         0053dea9     NOP
//         0053deaa     NOP
//         0053deab     NOP
//         0053deac     NOP
//         0053dead     NOP
//         0053deae     NOP
//         0053deaf     NOP
    return 0;
}

int RGE_Main_View::handle_keys() {
    /* TODO: Stub */
//                              int __thiscall handle_keys(RGE_Main_View * this)
//              int               EAX:4          <RETURN>
//              RGE_Main_View *   ECX:4 (auto)   this
//              uchar[256]        Stack[-0x104   pbKeyState
//              float             Stack[-0x114   scroll_dist2
//              short             Stack[-0x118   vert_scroll
//              short             Stack[-0x11c   horz_scroll
//                               ?handle_keys@RGE_Main_View@@QAEHXZ                           XREF[1]:     handle_idle:0053db68(c)
//                               RGE_Main_View::handle_keys
//                              vw_main.cpp:258 (11)
//         0053deb0     SUB        ESP,0x118
//         0053deb6     PUSH       EBX
//         0053deb7     PUSH       EBP
//         0053deb8     MOV        EBP,this
//         0053deba     PUSH       ESI
//                              vw_main.cpp:274 (86)
//         0053debb     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0053dec1     PUSH       EDI
//         0053dec2     CALL       RGE_Base_Game::get_paused                        int get_paused(RGE_Base_Game * this)
//         0053dec7     TEST       EAX,EAX
//         0053dec9     JNZ        LAB_0053e25d
//         0053decf     MOV        EAX,[rge_base_game]                              = 00000000
//         0053ded4     MOV        EAX,dword ptr [EAX + 0x1b0]
//         0053deda     CMP        EAX,0x4
//         0053dedd     JZ         LAB_0053def2
//         0053dedf     CMP        EAX,0x6
//         0053dee2     JZ         LAB_0053def2
//         0053dee4     CMP        EAX,0x7
//         0053dee7     JZ         LAB_0053def2
//         0053dee9     CMP        EAX,0x5
//         0053deec     JNZ        LAB_0053e25d
//                               LAB_0053def2                                                 XREF[3]:     0053dedd(j), 0053dee2(j),
//                                                                                                         0053dee7(j)
//         0053def2     CALL       dword ptr [->USER32.DLL::GetForegroundWindow]    = 0048b116
//         0053def8     MOV        this,dword ptr [EBP + 0x20]
//         0053defb     CMP        EAX,dword ptr [ECX + this->_padding_]
//         0053defe     JNZ        LAB_0053e25d
//         0053df04     MOV        EAX,dword ptr [EBP + 0x78]
//         0053df07     XOR        EBX,EBX
//         0053df09     CMP        EAX,EBX
//         0053df0b     JZ         LAB_0053e25d
//                              vw_main.cpp:282 (11)
//         0053df11     LEA        EDX,[ESP + 0x28]
//         0053df15     PUSH       EDX
//         0053df16     CALL       dword ptr [->USER32.DLL::GetKeyboardState]       = 0048b140
//                              vw_main.cpp:288 (13)
//         0053df1c     MOV        EAX,[rge_base_game]                              = 00000000
//         0053df21     MOV        dword ptr [ESP + 0x10],EBX
//         0053df25     MOV        dword ptr [ESP + 0x14],EBX
//                              vw_main.cpp:293 (46)
//         0053df29     MOV        this,dword ptr [EAX + 0x1b4]
//         0053df2f     MOV        EDI,dword ptr [EAX + 0xc]
//         0053df32     CMP        this,0x12
//         0053df35     JNZ        LAB_0053e043
//         0053df3b     MOV        EAX,dword ptr [EBP + 0x100]
//         0053df41     CMP        EAX,EBX
//         0053df43     JZ         LAB_0053e043
//         0053df49     MOV        ESI,dword ptr [EAX + 0x130]
//         0053df4f     TEST       ESI,ESI
//         0053df51     JZ         LAB_0053e043
//                              vw_main.cpp:298 (7)
//         0053df57     CMP        byte ptr [ESP + 0x4e],0x1
//         0053df5c     JBE        LAB_0053df89
//                              vw_main.cpp:300 (38)
//         0053df5e     FLD        float ptr [ESI + 0x3c]
//         0053df61     FSUB       float ptr [EDI + 0x8d8]
//         0053df67     FLD        float ptr [ESI + 0x38]
//         0053df6a     FADD       float ptr [EDI + 0x8d8]
//         0053df70     FXCH
//         0053df72     MOV        EAX,dword ptr [ESI]
//         0053df74     MOV        this,ESI
//         0053df76     PUSH       EBX
//         0053df77     PUSH       this=>DAT_fffffff8
//         0053df78     FSTP       float ptr [ESP]=>DAT_fffffff8
//         0053df7b     PUSH       this=>DAT_fffffff4
//         0053df7c     FSTP       float ptr [ESP]=>DAT_fffffff4
//         0053df7f     CALL       dword ptr [EAX + 0x34]
//         0053df82     FSTP       ST0
//                              vw_main.cpp:301 (5)
//         0053df84     MOV        EBX,0x1
//                               LAB_0053df89                                                 XREF[1]:     0053df5c(j)
//                              vw_main.cpp:304 (7)
//         0053df89     CMP        byte ptr [ESP + 0x50],0x1
//         0053df8e     JBE        LAB_0053dfc4
//                              vw_main.cpp:306 (47)
//         0053df90     MOV        this,dword ptr [EBP + 0x100]
//         0053df96     PUSH       0x0
//         0053df98     FLD        float ptr [ESI + 0x3c]
//         0053df9b     MOV        this,dword ptr [ECX + this->_padding_]
//         0053dfa1     FADD       float ptr [EDI + 0x8d8]
//         0053dfa7     MOV        EDX,dword ptr [this->_padding_]
//         0053dfa9     PUSH       this=>DAT_fffffff8
//         0053dfaa     FSTP       float ptr [ESP]=>DAT_fffffff8
//         0053dfad     FLD        float ptr [ESI + 0x38]
//         0053dfb0     FSUB       float ptr [EDI + 0x8d8]
//         0053dfb6     PUSH       this=>DAT_fffffff4
//         0053dfb7     FSTP       float ptr [ESP]=>DAT_fffffff4
//         0053dfba     CALL       dword ptr [EDX + 0x34]
//         0053dfbd     FSTP       ST0
//                              vw_main.cpp:307 (5)
//         0053dfbf     MOV        EBX,0x1
//                               LAB_0053dfc4                                                 XREF[1]:     0053df8e(j)
//                              vw_main.cpp:310 (7)
//         0053dfc4     CMP        byte ptr [ESP + 0x4d],0x1
//         0053dfc9     JBE        LAB_0053dfff
//                              vw_main.cpp:312 (47)
//         0053dfcb     MOV        EAX,dword ptr [EBP + 0x100]
//         0053dfd1     PUSH       0x0
//         0053dfd3     FLD        float ptr [ESI + 0x3c]
//         0053dfd6     MOV        this,dword ptr [EAX + 0x130]
//         0053dfdc     FSUB       float ptr [EDI + 0x8d8]
//         0053dfe2     MOV        EDX,dword ptr [this->_padding_]
//         0053dfe4     PUSH       this=>DAT_fffffff8
//         0053dfe5     FSTP       float ptr [ESP]=>DAT_fffffff8
//         0053dfe8     FLD        float ptr [ESI + 0x38]
//         0053dfeb     FSUB       float ptr [EDI + 0x8d8]
//         0053dff1     PUSH       this=>DAT_fffffff4
//         0053dff2     FSTP       float ptr [ESP]=>DAT_fffffff4
//         0053dff5     CALL       dword ptr [EDX + 0x34]
//         0053dff8     FSTP       ST0
//                              vw_main.cpp:313 (5)
//         0053dffa     MOV        EBX,0x1
//                               LAB_0053dfff                                                 XREF[1]:     0053dfc9(j)
//                              vw_main.cpp:316 (11)
//         0053dfff     CMP        byte ptr [ESP + 0x4f],0x1
//         0053e004     JBE        LAB_0053e214
//                              vw_main.cpp:318 (47)
//         0053e00a     MOV        EAX,dword ptr [EBP + 0x100]
//         0053e010     PUSH       0x0
//         0053e012     FLD        float ptr [ESI + 0x3c]
//         0053e015     MOV        this,dword ptr [EAX + 0x130]
//         0053e01b     FADD       float ptr [EDI + 0x8d8]
//         0053e021     MOV        EDX,dword ptr [this->_padding_]
//         0053e023     PUSH       this=>DAT_fffffff8
//         0053e024     FSTP       float ptr [ESP]=>DAT_fffffff8
//         0053e027     FLD        float ptr [ESI + 0x38]
//         0053e02a     FADD       float ptr [EDI + 0x8d8]
//         0053e030     PUSH       this=>DAT_fffffff4
//         0053e031     FSTP       float ptr [ESP]=>DAT_fffffff4
//         0053e034     CALL       dword ptr [EDX + 0x34]
//         0053e037     FSTP       ST0
//                              vw_main.cpp:319 (5)
//         0053e039     MOV        EBX,0x1
//                              vw_main.cpp:325 (19)
//         0053e03e     JMP        LAB_0053e214
//                               LAB_0053e043                                                 XREF[3]:     0053df35(j), 0053df43(j),
//                                                                                                         0053df51(j)
//         0053e043     MOV        EAX,dword ptr [EBP + 0x100]
//         0053e049     TEST       EAX,EAX
//         0053e04b     JZ         LAB_0053e214
//                              vw_main.cpp:327 (7)
//         0053e051     CMP        byte ptr [ESP + 0x4d],0x1
//         0053e056     JBE        LAB_0053e062
//                              vw_main.cpp:328 (8)
//         0053e058     MOV        dword ptr [ESP + 0x10],0xffffffff
//                              vw_main.cpp:329 (9)
//         0053e060     JMP        LAB_0053e071
//                               LAB_0053e062                                                 XREF[1]:     0053e056(j)
//         0053e062     CMP        byte ptr [ESP + 0x4f],0x1
//         0053e067     JBE        LAB_0053e071
//                              vw_main.cpp:330 (8)
//         0053e069     MOV        dword ptr [ESP + 0x10],0x1
//                               LAB_0053e071                                                 XREF[2]:     0053e060(j), 0053e067(j)
//                              vw_main.cpp:332 (7)
//         0053e071     CMP        byte ptr [ESP + 0x4e],0x1
//         0053e076     JBE        LAB_0053e082
//                              vw_main.cpp:333 (8)
//         0053e078     MOV        dword ptr [ESP + 0x14],0xffffffff
//                              vw_main.cpp:334 (9)
//         0053e080     JMP        LAB_0053e091
//                               LAB_0053e082                                                 XREF[1]:     0053e076(j)
//         0053e082     CMP        byte ptr [ESP + 0x50],0x1
//         0053e087     JBE        LAB_0053e091
//                              vw_main.cpp:335 (8)
//         0053e089     MOV        dword ptr [ESP + 0x14],0x1
//                               LAB_0053e091                                                 XREF[2]:     0053e080(j), 0053e087(j)
//                              vw_main.cpp:337 (20)
//         0053e091     CMP        word ptr [ESP + 0x10],0x0
//         0053e097     JNZ        LAB_0053e0a5
//         0053e099     CMP        word ptr [ESP + 0x14],0x0
//         0053e09f     JZ         LAB_0053e214
//                               LAB_0053e0a5                                                 XREF[1]:     0053e097(j)
//                              vw_main.cpp:339 (15)
//         0053e0a5     PUSH       0x153
//         0053e0aa     PUSH       s_C:\msdev\work\age1_x1\vw_main.cp               = "C:\\msdev\\work\\age1_x1\\vw_main.cpp"
//         0053e0af     CALL       debug_timeGetTime                                ulong debug_timeGetTime(char * param_1, int p
//                              vw_main.cpp:340 (6)
//         0053e0b4     MOV        this,dword ptr [EBP + 0x374]
//                              vw_main.cpp:343 (19)
//         0053e0ba     MOV        EDX,dword ptr [EBP + 0x378]
//         0053e0c0     MOV        ESI,EAX
//         0053e0c2     SUB        EAX,this
//         0053e0c4     XOR        this,this
//         0053e0c6     ADD        ESP,0x8
//         0053e0c9     CMP        EDX,this
//         0053e0cb     JNZ        LAB_0053e0df
//                              vw_main.cpp:346 (16)
//         0053e0cd     FLD        float ptr [DAT_00577900]                         = align(2)
//         0053e0d3     MOV        dword ptr [EBP + 0x378],0x1
//                              vw_main.cpp:348 (2)
//         0053e0dd     JMP        LAB_0053e12d
//                               LAB_0053e0df                                                 XREF[1]:     0053e0cb(j)
//                              vw_main.cpp:374 (30)
//         0053e0df     MOV        EDX,dword ptr [EDI + 0x8d0]
//         0053e0e5     MOV        dword ptr [ESP + 0x18],EAX
//         0053e0e9     MOV        dword ptr [ESP + 0x1c],this
//         0053e0ed     MOV        dword ptr [ESP + 0x20],EDX
//         0053e0f1     FILD       qword ptr [ESP + 0x18]
//         0053e0f5     MOV        dword ptr [ESP + 0x24],this
//         0053e0f9     FIDIV      dword ptr [ESP + 0x20]
//                              vw_main.cpp:375 (15)
//         0053e0fd     FLD        ST0
//         0053e0ff     CALL       __ftol                                           undefined __ftol()
//         0053e104     MOV        dword ptr [ESP + 0x18],EAX
//         0053e108     FILD       dword ptr [ESP + 0x18]
//                              vw_main.cpp:377 (17)
//         0053e10c     FXCH
//         0053e10e     FSUB       ST0,ST1
//         0053e110     FCOMP      float ptr [DAT_00577904]
//         0053e116     FNSTSW     AX
//         0053e118     TEST       AH,0x1
//         0053e11b     JZ         LAB_0053e125
//                              vw_main.cpp:378 (6)
//         0053e11d     FLD        float ptr [DAT_00577908]
//                              vw_main.cpp:379 (2)
//         0053e123     JMP        LAB_0053e12b
//                               LAB_0053e125                                                 XREF[1]:     0053e11b(j)
//                              vw_main.cpp:380 (6)
//         0053e125     FLD        float ptr [DAT_00577904]
//                               LAB_0053e12b                                                 XREF[1]:     0053e123(j)
//                              vw_main.cpp:381 (2)
//         0053e12b     FADDP
//                               LAB_0053e12d                                                 XREF[1]:     0053e0dd(j)
//                              vw_main.cpp:385 (15)
//         0053e12d     FCOM       float ptr [EDI + 0x8d4]
//         0053e133     FNSTSW     AX
//         0053e135     TEST       AH,0x41
//         0053e138     JNZ        LAB_0053e142
//         0053e13a     FSTP       ST0
//                              vw_main.cpp:386 (6)
//         0053e13c     FLD        float ptr [EDI + 0x8d4]
//                               LAB_0053e142                                                 XREF[1]:     0053e138(j)
//                              vw_main.cpp:388 (17)
//         0053e142     FCOM       float ptr [DAT_00577908]
//         0053e148     FNSTSW     AX
//         0053e14a     TEST       AH,0x41
//         0053e14d     JNZ        LAB_0053e212
//                              vw_main.cpp:395 (18)
//         0053e153     MOV        EAX,dword ptr [ESP + 0x10]
//         0053e157     FLD        ST0
//         0053e159     FADD       ST0,ST0
//         0053e15b     CMP        AX,0xffff
//         0053e15f     FSTP       float ptr [ESP + 0x18]
//         0053e163     JNZ        LAB_0053e17e
//                              vw_main.cpp:396 (23)
//         0053e165     MOV        this,dword ptr [EBP + 0x100]
//         0053e16b     PUSH       this
//         0053e16c     FLD        float ptr [ECX + this->_padding_]
//         0053e172     FSUB       ST0,ST1
//         0053e174     FLD        float ptr [ECX + this->_padding_]
//         0053e17a     FSUB       ST0,ST2
//                              vw_main.cpp:397 (8)
//         0053e17c     JMP        LAB_0053e19b
//                               LAB_0053e17e                                                 XREF[1]:     0053e163(j)
//         0053e17e     CMP        AX,0x1
//         0053e182     JNZ        LAB_0053e1ad
//                              vw_main.cpp:398 (41)
//         0053e184     MOV        this,dword ptr [EBP + 0x100]
//         0053e18a     PUSH       this
//         0053e18b     FLD        float ptr [ECX + this->_padding_]
//         0053e191     FADD       ST0,ST1
//         0053e193     FLD        float ptr [ECX + this->_padding_]
//         0053e199     FADD       ST0,ST2
//                               LAB_0053e19b                                                 XREF[1]:     0053e17c(j)
//         0053e19b     FXCH
//         0053e19d     FSTP       float ptr [ESP]
//         0053e1a0     PUSH       this=>DAT_fffffff8
//         0053e1a1     FSTP       float ptr [ESP]=>DAT_fffffff8
//         0053e1a4     FSTP       ST0
//         0053e1a6     CALL       RGE_Player::set_view_loc                         void set_view_loc(RGE_Player * this, float pa
//         0053e1ab     JMP        LAB_0053e1af
//                               LAB_0053e1ad                                                 XREF[1]:     0053e182(j)
//                              vw_main.cpp:396 (2)
//         0053e1ad     FSTP       ST0
//                               LAB_0053e1af                                                 XREF[1]:     0053e1ab(j)
//                              vw_main.cpp:400 (10)
//         0053e1af     MOV        EAX,dword ptr [ESP + 0x14]
//         0053e1b3     CMP        AX,0xffff
//         0053e1b7     JNZ        LAB_0053e1d6
//                              vw_main.cpp:401 (27)
//         0053e1b9     MOV        this,dword ptr [EBP + 0x100]
//         0053e1bf     PUSH       this
//         0053e1c0     FLD        float ptr [ECX + this->_padding_]
//         0053e1c6     FSUB       float ptr [ESP + 0x1c]
//         0053e1ca     FLD        float ptr [ECX + this->_padding_]
//         0053e1d0     FADD       float ptr [ESP + 0x1c]
//                              vw_main.cpp:402 (8)
//         0053e1d4     JMP        LAB_0053e1f7
//                               LAB_0053e1d6                                                 XREF[1]:     0053e1b7(j)
//         0053e1d6     CMP        AX,0x1
//         0053e1da     JNZ        LAB_0053e205
//                              vw_main.cpp:403 (41)
//         0053e1dc     MOV        this,dword ptr [EBP + 0x100]
//         0053e1e2     PUSH       this
//         0053e1e3     FLD        float ptr [ECX + this->_padding_]
//         0053e1e9     FADD       float ptr [ESP + 0x1c]
//         0053e1ed     FLD        float ptr [ECX + this->_padding_]
//         0053e1f3     FSUB       float ptr [ESP + 0x1c]
//                               LAB_0053e1f7                                                 XREF[1]:     0053e1d4(j)
//         0053e1f7     FXCH
//         0053e1f9     FSTP       float ptr [ESP]
//         0053e1fc     PUSH       this=>DAT_fffffff8
//         0053e1fd     FSTP       float ptr [ESP]=>DAT_fffffff8
//         0053e200     CALL       RGE_Player::set_view_loc                         void set_view_loc(RGE_Player * this, float pa
//                               LAB_0053e205                                                 XREF[1]:     0053e1da(j)
//                              vw_main.cpp:405 (6)
//         0053e205     MOV        dword ptr [EBP + 0x374],ESI
//                              vw_main.cpp:406 (7)
//         0053e20b     MOV        EBX,0x1
//         0053e210     JMP        LAB_0053e214
//                               LAB_0053e212                                                 XREF[1]:     0053e14d(j)
//                              vw_main.cpp:388 (2)
//         0053e212     FSTP       ST0
//                               LAB_0053e214                                                 XREF[5]:     0053e004(j), 0053e03e(j),
//                                                                                                         0053e04b(j), 0053e09f(j),
//                                                                                                         0053e210(j)
//                              vw_main.cpp:412 (16)
//         0053e214     CMP        word ptr [ESP + 0x10],0x0
//         0053e21a     JNZ        LAB_0053e22e
//         0053e21c     CMP        word ptr [ESP + 0x14],0x0
//         0053e222     JNZ        LAB_0053e22e
//                              vw_main.cpp:413 (10)
//         0053e224     MOV        dword ptr [EBP + 0x378],0x0
//                               LAB_0053e22e                                                 XREF[2]:     0053e21a(j), 0053e222(j)
//                              vw_main.cpp:415 (4)
//         0053e22e     TEST       EBX,EBX
//         0053e230     JZ         LAB_0053e250
//                              vw_main.cpp:417 (10)
//         0053e232     MOV        EAX,dword ptr [EBP]
//         0053e235     PUSH       0x1
//         0053e237     MOV        this,EBP
//         0053e239     CALL       dword ptr [EAX + 0x20]
//                              vw_main.cpp:418 (10)
//         0053e23c     MOV        EBP,dword ptr [EBP + 0x360]
//         0053e242     TEST       EBP,EBP
//         0053e244     JZ         LAB_0053e250
//                              vw_main.cpp:419 (10)
//         0053e246     MOV        EDX,dword ptr [EBP]
//         0053e249     PUSH       0x1
//         0053e24b     MOV        this,EBP
//         0053e24d     CALL       dword ptr [EDX + 0x20]
//                               LAB_0053e250                                                 XREF[2]:     0053e230(j), 0053e244(j)
//                              vw_main.cpp:422 (2)
//         0053e250     MOV        EAX,EBX
//                              vw_main.cpp:423 (34)
//         0053e252     POP        EDI
//         0053e253     POP        ESI
//         0053e254     POP        EBP
//         0053e255     POP        EBX
//         0053e256     ADD        ESP,0x118
//         0053e25c     RET
//                               LAB_0053e25d                                                 XREF[4]:     0053dec9(j), 0053deec(j),
//                                                                                                         0053defe(j), 0053df0b(j)
//         0053e25d     POP        EDI
//         0053e25e     MOV        dword ptr [EBP + 0x378],0x0
//         0053e268     POP        ESI
//         0053e269     POP        EBP
//         0053e26a     XOR        EAX,EAX
//         0053e26c     POP        EBX
//         0053e26d     ADD        ESP,0x118
//         0053e273     RET
//         0053e274     ??         90h
//         0053e275     NOP
//         0053e276     NOP
//         0053e277     NOP
//         0053e278     NOP
//         0053e279     NOP
//         0053e27a     NOP
//         0053e27b     NOP
//         0053e27c     NOP
//         0053e27d     NOP
//         0053e27e     NOP
//         0053e27f     NOP
    return 0;
}

long RGE_Main_View::handle_mouse_up(uchar param_1, long param_2, long param_3, int param_4, int param_5) {
    /* TODO: Stub */
//                              long __thiscall handle_mouse_up(RGE_Main_View * this, uchar param_1,
//              long              EAX:4          <RETURN>
//              RGE_Main_View *   ECX:4 (auto)   this
//              uchar             Stack[0x4]:1   param_1                   XREF[1]:     0053e2aa(R)
//              long              Stack[0x8]:4   param_2                   XREF[1]:     0053e2a5(R)
//              long              Stack[0xc]:4   param_3                   XREF[1]:     0053e297(R)
//              int               Stack[0x10]:4  param_4                   XREF[1]:     0053e293(R)
//              int               Stack[0x14]:4  param_5                   XREF[1]:     0053e2a0(R)
//                               ?handle_mouse_up@RGE_Main_View@@UAEJEJJHH@Z                  XREF[2]:     00572b20(*), 00577868(*)
//                               RGE_Main_View::handle_mouse_up
//                              vw_main.cpp:429 (2)
//         0053e280     PUSH       ESI
//         0053e281     PUSH       EDI
//                              vw_main.cpp:430 (17)
//         0053e282     PUSH       0x1ae
//         0053e287     MOV        ESI,this
//         0053e289     PUSH       s_C:\msdev\work\age1_x1\vw_main.cp               = "C:\\msdev\\work\\age1_x1\\vw_main.cpp"
//         0053e28e     CALL       debug_timeGetTime                                ulong debug_timeGetTime(char * param_1, int p
//                              vw_main.cpp:431 (37)
//         0053e293     MOV        this,dword ptr [ESP + param_4]
//         0053e297     MOV        EDX,dword ptr [ESP + param_3]
//         0053e29b     ADD        ESP,0x8
//         0053e29e     MOV        EDI,EAX
//         0053e2a0     MOV        EAX,dword ptr [ESP + param_5]
//         0053e2a4     PUSH       EAX
//         0053e2a5     MOV        EAX,dword ptr [ESP + param_2]
//         0053e2a9     PUSH       this
//         0053e2aa     MOV        this,dword ptr [ESP + param_1]
//         0053e2ae     PUSH       EDX
//         0053e2af     PUSH       EAX
//         0053e2b0     PUSH       this
//         0053e2b1     MOV        this,ESI
//         0053e2b3     CALL       TPanel::handle_mouse_up                          long handle_mouse_up(TPanel * this, uchar par
//                              vw_main.cpp:432 (36)
//         0053e2b8     PUSH       0x1b0
//         0053e2bd     PUSH       s_C:\msdev\work\age1_x1\vw_main.cp               = "C:\\msdev\\work\\age1_x1\\vw_main.cpp"
//         0053e2c2     MOV        ESI,EAX
//         0053e2c4     CALL       debug_timeGetTime                                ulong debug_timeGetTime(char * param_1, int p
//         0053e2c9     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0053e2cf     ADD        ESP,0x8
//         0053e2d2     SUB        EAX,EDI
//         0053e2d4     PUSH       EAX
//         0053e2d5     PUSH       0xd
//         0053e2d7     CALL       RGE_Base_Game::add_to_timing                     void add_to_timing(RGE_Base_Game * this, int
//                              vw_main.cpp:433 (2)
//         0053e2dc     MOV        EAX,ESI
//                              vw_main.cpp:434 (5)
//         0053e2de     POP        EDI
//         0053e2df     POP        ESI
//         0053e2e0     RET        0x14
//         0053e2e3     ??         90h
//         0053e2e4     NOP
//         0053e2e5     NOP
//         0053e2e6     NOP
//         0053e2e7     NOP
//         0053e2e8     NOP
//         0053e2e9     NOP
//         0053e2ea     NOP
//         0053e2eb     NOP
//         0053e2ec     NOP
//         0053e2ed     NOP
//         0053e2ee     NOP
//         0053e2ef     NOP
    return 0;
}

long RGE_Main_View::mouse_move_action(long param_1, long param_2, int param_3, int param_4) {
    /* TODO: Stub */
//                              long __thiscall mouse_move_action(RGE_Main_View * this, long param_1
//              long              EAX:4          <RETURN>
//              RGE_Main_View *   ECX:4 (auto)   this
//              long              Stack[0x4]:4   param_1
//              long              Stack[0x8]:4   param_2
//              int               Stack[0xc]:4   param_3
//              int               Stack[0x10]:4  param_4
//                               ?mouse_move_action@RGE_Main_View@@UAEJJJHH@Z                 XREF[2]:     00572b28(*), 00577870(*)
//                               RGE_Main_View::mouse_move_action
//                              vw_main.cpp:440 (32)
//         0053e2f0     MOV        EDX,dword ptr [rge_base_game]                    = 00000000
//         0053e2f6     MOV        EAX,dword ptr [EDX + 0x1b0]
//         0053e2fc     CMP        EAX,0x4
//         0053e2ff     JZ         LAB_0053e315
//         0053e301     CMP        EAX,0x6
//         0053e304     JZ         LAB_0053e315
//         0053e306     CMP        EAX,0x7
//         0053e309     JZ         LAB_0053e315
//         0053e30b     CMP        EAX,0x5
//         0053e30e     JZ         LAB_0053e315
//                              vw_main.cpp:442 (2)
//         0053e310     XOR        EAX,EAX
//                              vw_main.cpp:455 (3)
//         0053e312     RET        0x10
//                               LAB_0053e315                                                 XREF[4]:     0053e2ff(j), 0053e304(j),
//                                                                                                         0053e309(j), 0053e30e(j)
//                              vw_main.cpp:444 (21)
//         0053e315     MOV        EAX,dword ptr [EDX + 0x1b4]
//         0053e31b     CMP        EAX,0x1
//         0053e31e     JZ         LAB_0053e32a
//         0053e320     CMP        EAX,0x6
//         0053e323     JLE        LAB_0053e331
//         0053e325     CMP        EAX,0x8
//         0053e328     JG         LAB_0053e331
//                               LAB_0053e32a                                                 XREF[1]:     0053e31e(j)
//                              vw_main.cpp:450 (7)
//         0053e32a     MOV        EAX,dword ptr [this->_padding_]
//         0053e32c     PUSH       0x1
//         0053e32e     CALL       dword ptr [EAX + 0x20]
//                               LAB_0053e331                                                 XREF[2]:     0053e323(j), 0053e328(j)
//                              vw_main.cpp:454 (5)
//         0053e331     MOV        EAX,0x1
//                              vw_main.cpp:455 (3)
//         0053e336     RET        0x10
//         0053e339     ??         90h
//         0053e33a     NOP
//         0053e33b     NOP
//         0053e33c     NOP
//         0053e33d     NOP
//         0053e33e     NOP
//         0053e33f     NOP
    return 0;
}

long RGE_Main_View::mouse_left_down_action(long param_1, long param_2, int param_3, int param_4) {
    /* TODO: Stub */
//                              long __thiscall mouse_left_down_action(RGE_Main_View * this, long pa
//              long              EAX:4          <RETURN>
//              RGE_Main_View *   ECX:4 (auto)   this
//              long              Stack[0x4]:4   param_1                   XREF[4]:     0053e3c9(R), 0053e4ba(R), 0053e623(R), 0053e642(R)
//              long              Stack[0x8]:4   param_2                   XREF[4]:     0053e3c4(R), 0053e4b6(R), 0053e61e(R), 0053e63e(R)
//              int               Stack[0xc]:4   param_3                   XREF[1]:     0053e617(R)
//              int               Stack[0x10]:4  param_4                   XREF[1]:     0053e613(R)
//              RGE_Pick_Info     Stack[-0x18]   pick_info                 XREF[0,11]:  0053e3ba(*), 0053e4c0(*), 0053e4dc(*), 0053e51e(*),
//                                                                                     0053e572(*), 0053e64e(*), 0053e519(*), 0053e56d(*),
//                                                                                     0053e3ee(R), 0053e669(R), 0053e6a8(R)
//              tagPOINT          Stack[-0x20]:8 point
//              short             Stack[-0x22]:2 max_x
//              short             Stack[-0x24]:2 max_y
//              short             Stack[-0x26]:2 min_y
//              short             Stack[-0x28]:2 min_x
//                               ?mouse_left_down_action@RGE_Main_View@@UAEJJJHH@Z            XREF[2]:     00572b2c(*), 00577874(*)
//                               RGE_Main_View::mouse_left_down_action
//                              vw_main.cpp:461 (8)
//         0053e340     SUB        ESP,0x24
//         0053e343     PUSH       EBX
//         0053e344     PUSH       EBP
//         0053e345     PUSH       ESI
//         0053e346     MOV        ESI,this
//                              vw_main.cpp:470 (56)
//         0053e348     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0053e34e     PUSH       EDI
//         0053e34f     CALL       RGE_Base_Game::get_paused                        int get_paused(RGE_Base_Game * this)
//         0053e354     TEST       EAX,EAX
//         0053e356     JNZ        LAB_0053e7a7
//         0053e35c     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0053e362     MOV        EAX,dword ptr [ECX + this->_padding_]
//         0053e368     CMP        EAX,0x4
//         0053e36b     JZ         LAB_0053e380
//         0053e36d     CMP        EAX,0x6
//         0053e370     JZ         LAB_0053e380
//         0053e372     CMP        EAX,0x7
//         0053e375     JZ         LAB_0053e380
//         0053e377     CMP        EAX,0x5
//         0053e37a     JNZ        LAB_0053e7a7
//                               LAB_0053e380                                                 XREF[3]:     0053e36b(j), 0053e370(j),
//                                                                                                         0053e375(j)
//                              vw_main.cpp:473 (6)
//         0053e380     MOV        EDI,dword ptr [ECX + this->_padding_]
//                              vw_main.cpp:475 (14)
//         0053e386     PUSH       0x1
//         0053e388     PUSH       0xba
//         0053e38d     PUSH       0x4c
//         0053e38f     CALL       color_log                                        void color_log(uchar param_1, uchar param_2,
//                              vw_main.cpp:477 (30)
//         0053e394     LEA        EAX,[EDI + -0x1]
//         0053e397     ADD        ESP,0xc
//         0053e39a     CMP        EAX,0x14
//         0053e39d     JA         switchD_0053e3ab::caseD_4
//         0053e3a3     XOR        this,this
//         0053e3a5     MOV        this,byte ptr [EAX + 0x53e7d8]=>PTR_caseD_4_00
//                               switchD_0053e3ab::switchD
//         0053e3ab     JMP        dword ptr [this->_padding_*0x4 + switchD_0053e   = 0053e4b6
//                               switchD_0053e3ab::caseD_12                                   XREF[2]:     0053e3ab(j), 0053e7c8(*)
//                              vw_main.cpp:482 (41)
//         0053e3b2     MOV        EDX,dword ptr [ESI + 0x100]
//         0053e3b8     PUSH       0x1
//         0053e3ba     LEA        this=>pick_info.y,[ESP + 0x24]
//         0053e3be     MOV        EAX,dword ptr [EDX + 0x130]
//         0053e3c4     MOV        EDX,dword ptr [ESP + param_2]
//         0053e3c8     PUSH       EAX
//         0053e3c9     MOV        EAX,dword ptr [ESP + param_1]
//         0053e3cd     PUSH       this
//         0053e3ce     PUSH       EDX
//         0053e3cf     PUSH       EAX
//         0053e3d0     PUSH       0x0
//         0053e3d2     PUSH       0x29
//         0053e3d4     MOV        this,ESI
//         0053e3d6     CALL       RGE_Main_View::pick1                             uchar pick1(RGE_Main_View * this, uchar param
//                              vw_main.cpp:485 (8)
//         0053e3db     CMP        AL,0x34
//         0053e3dd     JNZ        LAB_0053e78a
//                              vw_main.cpp:488 (11)
//         0053e3e3     MOV        this,dword ptr [ESI + 0x100]
//         0053e3e9     CALL       RGE_Player::unselect_object                      void unselect_object(RGE_Player * this)
//                              vw_main.cpp:489 (18)
//         0053e3ee     MOV        this,dword ptr [ESP + pick_info.tile]
//         0053e3f2     PUSH       0x1
//         0053e3f4     PUSH       this
//         0053e3f5     MOV        this,dword ptr [ESI + 0x100]
//         0053e3fb     CALL       RGE_Player::select_one_object                    int select_one_object(RGE_Player * this, RGE_
//                              vw_main.cpp:490 (9)
//         0053e400     MOV        EDI,dword ptr [ESI]
//         0053e402     PUSH       0x1
//         0053e404     MOV        this,ESI
//         0053e406     CALL       dword ptr [EDI + 0x20]
//                              vw_main.cpp:492 (15)
//         0053e409     MOV        this,dword ptr [ESP + 0x2c]
//         0053e40d     MOV        EAX,dword ptr [ECX + this->_padding_]
//         0053e410     TEST       EAX,EAX
//         0053e412     JZ         LAB_0053e78a
//                              vw_main.cpp:495 (25)
//         0053e418     LEA        EDX,[ESP + 0x14]
//         0053e41c     LEA        EAX,[ESP + 0x16]
//         0053e420     PUSH       EDX
//         0053e421     PUSH       EAX=>DAT_fffffff8
//         0053e422     LEA        EDX,[ESP + 0x1a]
//         0053e426     LEA        EAX,[ESP + 0x18]
//         0053e42a     PUSH       EDX=>DAT_fffffff4
//         0053e42b     PUSH       EAX=>DAT_fffffff0
//         0053e42c     CALL       RGE_Static_Object::get_frame                     int get_frame(RGE_Static_Object * this, short
//                              vw_main.cpp:496 (10)
//         0053e431     MOVSX      this,word ptr [ESP + 0x28]
//         0053e436     MOVSX      EDX,word ptr [ESP + 0x10]
//                              vw_main.cpp:497 (14)
//         0053e43b     MOVSX      EAX,word ptr [ESP + 0x2a]
//         0053e440     SUB        this,EDX
//         0053e442     MOVSX      EDX,word ptr [ESP + 0x12]
//         0053e447     SUB        EAX,EDX
//                              vw_main.cpp:498 (22)
//         0053e449     MOV        EDX,dword ptr [ESI + 0x20]
//         0053e44c     MOV        dword ptr [ESP + 0x18],this
//         0053e450     MOV        dword ptr [ESP + 0x1c],EAX
//         0053e454     MOV        EBX,dword ptr [EDX]
//         0053e456     CMP        byte ptr [EBX + 0x479],0x1
//         0053e45d     JNZ        LAB_0053e476
//                              vw_main.cpp:499 (23)
//         0053e45f     MOV        this,dword ptr [EDX + 0x4]
//         0053e462     LEA        EAX,[ESP + 0x18]
//         0053e466     PUSH       EAX
//         0053e467     PUSH       this=>DAT_fffffff8
//         0053e468     CALL       dword ptr [->USER32.DLL::ClientToScreen]         = 0048afd2
//         0053e46e     MOV        EAX,dword ptr [ESP + 0x1c]
//         0053e472     MOV        this,dword ptr [ESP + 0x18]
//                               LAB_0053e476                                                 XREF[1]:     0053e45d(j)
//                              vw_main.cpp:503 (14)
//         0053e476     MOV        EDX,dword ptr [ESI + 0x20]
//         0053e479     MOV        EBX,dword ptr [EDX]
//         0053e47b     CMP        byte ptr [EBX + 0x479],0x1
//         0053e482     JNZ        LAB_0053e49b
//                              vw_main.cpp:504 (23)
//         0053e484     MOV        this,dword ptr [EDX + 0x4]
//         0053e487     LEA        EAX,[ESP + 0x18]
//         0053e48b     PUSH       EAX
//         0053e48c     PUSH       this=>DAT_fffffff8
//         0053e48d     CALL       dword ptr [->USER32.DLL::ScreenToClient]         = 0048aea8
//         0053e493     MOV        EAX,dword ptr [ESP + 0x1c]
//         0053e497     MOV        this,dword ptr [ESP + 0x18]
//                               LAB_0053e49b                                                 XREF[1]:     0053e482(j)
//                              vw_main.cpp:505 (22)
//         0053e49b     MOV        EDX,dword ptr [ESP + 0x44]
//         0053e49f     PUSH       EDX
//         0053e4a0     MOV        EDX,dword ptr [ESP + 0x44]
//         0053e4a4     PUSH       EDX=>DAT_fffffff8
//         0053e4a5     PUSH       EAX=>DAT_fffffff4
//         0053e4a6     PUSH       this=>DAT_fffffff0
//         0053e4a7     PUSH       0x4
//         0053e4a9     MOV        this,ESI
//         0053e4ab     CALL       dword ptr [EDI + 0xe8]
//                              vw_main.cpp:509 (5)
//         0053e4b1     JMP        LAB_0053e78a
//                               switchD_0053e3ab::caseD_1                                    XREF[2]:     0053e3ab(j), 0053e7b4(*)
//                              vw_main.cpp:512 (30)
//         0053e4b6     MOV        this,dword ptr [ESP + param_2]
//         0053e4ba     MOV        EDX,dword ptr [ESP + param_1]
//         0053e4be     PUSH       0x1
//         0053e4c0     LEA        EAX=>pick_info.y,[ESP + 0x24]
//         0053e4c4     PUSH       0x0
//         0053e4c6     PUSH       EAX
//         0053e4c7     PUSH       this
//         0053e4c8     PUSH       EDX
//         0053e4c9     PUSH       0x0
//         0053e4cb     PUSH       0x28
//         0053e4cd     MOV        this,ESI
//         0053e4cf     CALL       RGE_Main_View::pick1                             uchar pick1(RGE_Main_View * this, uchar param
//                              vw_main.cpp:513 (8)
//         0053e4d4     CMP        AL,0x33
//         0053e4d6     JNZ        LAB_0053e78a
//                              vw_main.cpp:515 (12)
//         0053e4dc     LEA        EAX=>pick_info.y,[ESP + 0x20]
//         0053e4e0     MOV        this,ESI
//         0053e4e2     PUSH       EAX
//         0053e4e3     CALL       RGE_Main_View::fixup_pick_info                   void fixup_pick_info(RGE_Main_View * this, RG
//                              vw_main.cpp:520 (13)
//         0053e4e8     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0053e4ee     MOVSX      EDI,word ptr [this->_padding_ + 0x3fc]
//                              vw_main.cpp:521 (25)
//         0053e4f5     CMP        EDI,-0x1
//         0053e4f8     JZ         LAB_0053e78a
//         0053e4fe     MOV        EDX,dword ptr [ESI + 0x100]
//         0053e504     MOV        EAX,dword ptr [EDX + 0x24]
//         0053e507     MOV        this,dword ptr [EAX + EDI*0x4]
//         0053e50a     TEST       this,this
//         0053e50c     JZ         LAB_0053e546
//                              vw_main.cpp:524 (24)
//         0053e50e     MOV        EAX,dword ptr [ESI + 0xfc]
//         0053e514     MOV        EDX,dword ptr [this->_padding_]
//         0053e516     PUSH       0x0
//         0053e518     PUSH       EAX
//         0053e519     LEA        EAX=>pick_info.scr_x,[ESP + 0x2c]
//         0053e51d     PUSH       EAX
//         0053e51e     LEA        EAX=>pick_info.y,[ESP + 0x2c]
//         0053e522     PUSH       EAX
//         0053e523     CALL       dword ptr [EDX + 0x24]
//                              vw_main.cpp:525 (27)
//         0053e526     MOV        EAX,dword ptr [ESP + 0x24]
//         0053e52a     MOV        this,dword ptr [ESI + 0x100]
//         0053e530     PUSH       0x0
//         0053e532     PUSH       EAX=>DAT_fffffff8
//         0053e533     MOV        EAX,dword ptr [ESP + 0x28]
//         0053e537     MOV        EDX,dword ptr [this->_padding_]
//         0053e539     PUSH       EAX=>DAT_fffffff4
//         0053e53a     PUSH       EDI=>DAT_fffffff0
//         0053e53b     CALL       dword ptr [EDX + 0xb0]
//                              vw_main.cpp:527 (39)
//         0053e541     JMP        LAB_0053e78a
//                               LAB_0053e546                                                 XREF[1]:     0053e50c(j)
//         0053e546     CMP        EDI,-0x1
//         0053e549     JZ         LAB_0053e78a
//         0053e54f     MOV        EAX,dword ptr [ESI + 0xfc]
//         0053e555     MOV        this,dword ptr [EAX + 0x40]
//         0053e558     MOV        EDX,dword ptr [this->_padding_]
//         0053e55a     MOV        this,dword ptr [EDX + 0x24]
//         0053e55d     MOV        this,dword ptr [this->_padding_ + EDI*0x4]
//         0053e560     TEST       this,this
//         0053e562     JZ         LAB_0053e78a
//                              vw_main.cpp:530 (18)
//         0053e568     MOV        EDX,dword ptr [this->_padding_]
//         0053e56a     PUSH       0x0
//         0053e56c     PUSH       EAX
//         0053e56d     LEA        EAX=>pick_info.scr_x,[ESP + 0x2c]
//         0053e571     PUSH       EAX
//         0053e572     LEA        EAX=>pick_info.y,[ESP + 0x2c]
//         0053e576     PUSH       EAX
//         0053e577     CALL       dword ptr [EDX + 0x24]
//                              vw_main.cpp:531 (32)
//         0053e57a     MOV        this,dword ptr [ESI + 0xfc]
//         0053e580     PUSH       0x0
//         0053e582     MOV        EDX,dword ptr [ECX + this->_padding_]
//         0053e585     MOV        this,dword ptr [EDX]
//         0053e587     MOV        EDX,dword ptr [ESP + 0x28]
//         0053e58b     PUSH       EDX=>DAT_fffffff8
//         0053e58c     MOV        EDX,dword ptr [ESP + 0x28]
//         0053e590     MOV        EAX,dword ptr [this->_padding_]
//         0053e592     PUSH       EDX=>DAT_fffffff4
//         0053e593     PUSH       EDI=>DAT_fffffff0
//         0053e594     CALL       dword ptr [EAX + 0xb0]
//                              vw_main.cpp:535 (5)
//         0053e59a     JMP        LAB_0053e78a
//                               switchD_0053e3ab::caseD_a                                    XREF[3]:     0053e3ab(j), 0053e7bc(*),
//                               switchD_0053e3ab::caseD_13                                                0053e7cc(*)
//                               switchD_0053e3ab::caseD_9
//                              vw_main.cpp:541 (16)
//         0053e59f     MOV        this,dword ptr [ESI + 0x100]
//         0053e5a5     MOV        EAX,dword ptr [ECX + this->_padding_]
//         0053e5ab     TEST       EAX,EAX
//         0053e5ad     JZ         LAB_0053e5bd
//                              vw_main.cpp:543 (5)
//         0053e5af     CALL       RGE_Player::unselect_object                      void unselect_object(RGE_Player * this)
//                              vw_main.cpp:544 (9)
//         0053e5b4     MOV        EAX,dword ptr [ESI]
//         0053e5b6     PUSH       0x1
//         0053e5b8     MOV        this,ESI
//         0053e5ba     CALL       dword ptr [EAX + 0x20]
//                               LAB_0053e5bd                                                 XREF[1]:     0053e5ad(j)
//                              vw_main.cpp:548 (5)
//         0053e5bd     CMP        EDI,0x13
//         0053e5c0     JNZ        LAB_0053e5d0
//                              vw_main.cpp:549 (14)
//         0053e5c2     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0053e5c8     PUSH       0x0
//         0053e5ca     PUSH       EDI=>DAT_fffffff8
//         0053e5cb     MOV        EDX,dword ptr [this->_padding_]
//         0053e5cd     CALL       dword ptr [EDX + 0x10]
//                               LAB_0053e5d0                                                 XREF[1]:     0053e5c0(j)
//                              vw_main.cpp:551 (32)
//         0053e5d0     MOV        this,dword ptr [ESP + 0x44]
//         0053e5d4     MOV        EDX,dword ptr [ESP + 0x40]
//         0053e5d8     MOV        EAX,dword ptr [ESI]
//         0053e5da     PUSH       this
//         0053e5db     MOV        this,dword ptr [ESP + 0x40]
//         0053e5df     PUSH       EDX=>DAT_fffffff8
//         0053e5e0     MOV        EDX,dword ptr [ESP + 0x40]
//         0053e5e4     PUSH       this=>DAT_fffffff4
//         0053e5e5     PUSH       EDX=>DAT_fffffff0
//         0053e5e6     PUSH       0x9
//         0053e5e8     MOV        this,ESI
//         0053e5ea     CALL       dword ptr [EAX + 0xe8]
//                              vw_main.cpp:553 (5)
//         0053e5f0     JMP        LAB_0053e78a
//                               switchD_0053e3ab::caseD_3                                    XREF[3]:     0053e3ab(j), 0053e7b8(*),
//                               switchD_0053e3ab::caseD_11                                                0053e7c4(*)
//                               switchD_0053e3ab::caseD_2
//                              vw_main.cpp:559 (16)
//         0053e5f5     MOV        this,dword ptr [ESI + 0x100]
//         0053e5fb     MOV        EAX,dword ptr [ECX + this->_padding_]
//         0053e601     TEST       EAX,EAX
//         0053e603     JZ         switchD_0053e3ab::caseD_15
//                              vw_main.cpp:561 (5)
//         0053e605     CALL       RGE_Player::unselect_object                      void unselect_object(RGE_Player * this)
//                              vw_main.cpp:562 (9)
//         0053e60a     MOV        EAX,dword ptr [ESI]
//         0053e60c     PUSH       0x1
//         0053e60e     MOV        this,ESI
//         0053e610     CALL       dword ptr [EAX + 0x20]
//                               switchD_0053e3ab::caseD_15                                   XREF[3]:     0053e3ab(j), 0053e603(j),
//                                                                                                         0053e7d0(*)
//                              vw_main.cpp:572 (32)
//         0053e613     MOV        EAX,dword ptr [ESP + param_4]
//         0053e617     MOV        this,dword ptr [ESP + param_3]
//         0053e61b     MOV        EDX,dword ptr [ESI]
//         0053e61d     PUSH       EAX
//         0053e61e     MOV        EAX,dword ptr [ESP + param_2]
//         0053e622     PUSH       this=>DAT_fffffff8
//         0053e623     MOV        this,dword ptr [ESP + param_1]
//         0053e627     PUSH       EAX=>DAT_fffffff4
//         0053e628     PUSH       this=>DAT_fffffff0
//         0053e629     PUSH       0x3
//         0053e62b     MOV        this,ESI
//         0053e62d     CALL       dword ptr [EDX + 0xe8]
//                              vw_main.cpp:574 (5)
//         0053e633     JMP        LAB_0053e78a
//                               switchD_0053e3ab::caseD_f                                    XREF[2]:     0053e3ab(j), 0053e7c0(*)
//                              vw_main.cpp:577 (41)
//         0053e638     MOV        EDX,dword ptr [ESI + 0x100]
//         0053e63e     MOV        EDI,dword ptr [ESP + param_2]
//         0053e642     MOV        EBP,dword ptr [ESP + param_1]
//         0053e646     PUSH       0x1
//         0053e648     MOV        EAX,dword ptr [EDX + 0x130]
//         0053e64e     LEA        this=>pick_info.y,[ESP + 0x24]
//         0053e652     PUSH       EAX
//         0053e653     PUSH       this
//         0053e654     PUSH       EDI
//         0053e655     PUSH       EBP
//         0053e656     PUSH       0x0
//         0053e658     PUSH       0x29
//         0053e65a     MOV        this,ESI
//         0053e65c     CALL       RGE_Main_View::pick1                             uchar pick1(RGE_Main_View * this, uchar param
//                              vw_main.cpp:578 (26)
//         0053e661     CMP        AL,0x34
//         0053e663     JNZ        LAB_0053e78a
//         0053e669     MOV        EAX,dword ptr [ESP + pick_info.tile]
//         0053e66d     MOV        EDX,dword ptr [EAX + 0x8]
//         0053e670     CMP        word ptr [EDX + 0x14],0x22
//         0053e675     JZ         LAB_0053e78a
//                              vw_main.cpp:582 (7)
//         0053e67b     MOV        this,dword ptr [EAX + 0x18]
//         0053e67e     TEST       this,this
//         0053e680     JZ         LAB_0053e68b
//                              vw_main.cpp:583 (7)
//         0053e682     CALL       RGE_Active_Sprite_List::get_lowest_draw_level    uchar get_lowest_draw_level(RGE_Active_Sprite
//         0053e687     MOV        BL,AL
//                              vw_main.cpp:584 (9)
//         0053e689     JMP        LAB_0053e69d
//                               LAB_0053e68b                                                 XREF[1]:     0053e680(j)
//         0053e68b     MOV        this,dword ptr [EAX + 0x10]
//         0053e68e     TEST       this,this
//         0053e690     JZ         LAB_0053e69b
//                              vw_main.cpp:585 (7)
//         0053e692     CALL       RGE_Sprite::get_lowest_draw_level                uchar get_lowest_draw_level(RGE_Sprite * this)
//         0053e697     MOV        BL,AL
//                              vw_main.cpp:586 (2)
//         0053e699     JMP        LAB_0053e69d
//                               LAB_0053e69b                                                 XREF[1]:     0053e690(j)
//                              vw_main.cpp:587 (2)
//         0053e69b     MOV        BL,0x14
//                               LAB_0053e69d                                                 XREF[2]:     0053e689(j), 0053e699(j)
//                              vw_main.cpp:589 (11)
//         0053e69d     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0053e6a3     CALL       RGE_Base_Game::get_player                        RGE_Player * get_player(RGE_Base_Game * this)
//                              vw_main.cpp:590 (29)
//         0053e6a8     MOV        EDX,dword ptr [ESP + pick_info.tile]
//         0053e6ac     MOV        dword ptr [ESI + 0x37c],EAX
//         0053e6b2     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0053e6b8     MOV        EDX,dword ptr [EDX + 0xc]
//         0053e6bb     MOV        EAX,dword ptr [this->_padding_]
//         0053e6bd     MOV        DX,word ptr [EDX + 0x4a]
//         0053e6c1     PUSH       EDX
//         0053e6c2     CALL       dword ptr [EAX + 0x14]
//                              vw_main.cpp:591 (9)
//         0053e6c5     MOV        this,dword ptr [ESP + 0x2c]
//         0053e6c9     MOV        EAX,[rge_base_game]                              = 00000000
//                              vw_main.cpp:598 (32)
//         0053e6ce     TEST       BL,BL
//         0053e6d0     MOV        EDX,dword ptr [ECX + this->_padding_]
//         0053e6d3     MOV        this,word ptr [EDX + 0x10]
//         0053e6d7     MOV        word ptr [EAX + 0x3fc],this
//         0053e6de     MOV        EAX,dword ptr [ESP + 0x2c]
//         0053e6e2     MOV        dword ptr [ESI + 0x174],EAX
//         0053e6e8     MOV        byte ptr [EAX + 0x48],0x7
//         0053e6ec     JNZ        LAB_0053e6f7
//                              vw_main.cpp:599 (9)
//         0053e6ee     MOV        EDX,dword ptr [ESI]
//         0053e6f0     PUSH       0x2
//         0053e6f2     MOV        this,ESI
//         0053e6f4     CALL       dword ptr [EDX + 0x20]
//                               LAB_0053e6f7                                                 XREF[1]:     0053e6ec(j)
//                              vw_main.cpp:601 (15)
//         0053e6f7     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0053e6fd     PUSH       0x1
//         0053e6ff     PUSH       offset DAT_fffffff8
//         0053e701     MOV        EAX,dword ptr [this->_padding_]
//         0053e703     CALL       dword ptr [EAX + 0x10]
//                              vw_main.cpp:604 (13)
//         0053e706     MOV        this,dword ptr [ESI + 0x174]
//         0053e70c     MOV        EAX,dword ptr [ECX + this->_padding_]
//         0053e70f     TEST       EAX,EAX
//         0053e711     JZ         LAB_0053e769
//                              vw_main.cpp:606 (25)
//         0053e713     LEA        EDX,[ESP + 0x14]
//         0053e717     LEA        EAX,[ESP + 0x16]
//         0053e71b     PUSH       EDX
//         0053e71c     PUSH       EAX=>DAT_fffffff8
//         0053e71d     LEA        EDX,[ESP + 0x1a]
//         0053e721     LEA        EAX,[ESP + 0x18]
//         0053e725     PUSH       EDX=>DAT_fffffff4
//         0053e726     PUSH       EAX=>DAT_fffffff0
//         0053e727     CALL       RGE_Static_Object::get_frame                     int get_frame(RGE_Static_Object * this, short
//                              vw_main.cpp:607 (10)
//         0053e72c     MOVSX      this,word ptr [ESP + 0x28]
//         0053e731     MOVSX      EDX,word ptr [ESP + 0x10]
//                              vw_main.cpp:608 (22)
//         0053e736     MOVSX      EAX,word ptr [ESP + 0x2a]
//         0053e73b     SUB        this,EDX
//         0053e73d     MOV        dword ptr [ESP + 0x18],this
//         0053e741     MOVSX      this,word ptr [ESP + 0x12]
//         0053e746     SUB        EAX,this
//         0053e748     MOV        dword ptr [ESP + 0x1c],EAX
//                              vw_main.cpp:609 (14)
//         0053e74c     MOV        EAX,dword ptr [ESI + 0x20]
//         0053e74f     MOV        EDX,dword ptr [EAX]
//         0053e751     CMP        byte ptr [EDX + 0x479],0x1
//         0053e758     JNZ        LAB_0053e769
//                              vw_main.cpp:610 (15)
//         0053e75a     MOV        EDX,dword ptr [EAX + 0x4]
//         0053e75d     LEA        this,[ESP + 0x18]
//         0053e761     PUSH       this
//         0053e762     PUSH       EDX=>DAT_fffffff8
//         0053e763     CALL       dword ptr [->USER32.DLL::ClientToScreen]         = 0048afd2
//                               LAB_0053e769                                                 XREF[2]:     0053e711(j), 0053e758(j)
//                              vw_main.cpp:615 (24)
//         0053e769     MOV        this,dword ptr [ESP + 0x44]
//         0053e76d     MOV        EDX,dword ptr [ESP + 0x40]
//         0053e771     MOV        EAX,dword ptr [ESI]
//         0053e773     PUSH       this
//         0053e774     PUSH       EDX=>DAT_fffffff8
//         0053e775     PUSH       EDI=>DAT_fffffff4
//         0053e776     PUSH       EBP=>DAT_fffffff0
//         0053e777     PUSH       0x9
//         0053e779     MOV        this,ESI
//         0053e77b     CALL       dword ptr [EAX + 0xe8]
//                              vw_main.cpp:619 (2)
//         0053e781     JMP        LAB_0053e78a
//                               switchD_0053e3ab::caseD_5                                    XREF[3]:     0053e39d(j), 0053e3ab(j),
//                               switchD_0053e3ab::caseD_6                                                 0053e7d4(*)
//                               switchD_0053e3ab::caseD_7
//                               switchD_0053e3ab::caseD_8
//                               switchD_0053e3ab::caseD_b
//                               switchD_0053e3ab::caseD_c
//                               switchD_0053e3ab::caseD_d
//                               switchD_0053e3ab::caseD_e
//                               switchD_0053e3ab::caseD_10
//                               switchD_0053e3ab::caseD_14
//                               switchD_0053e3ab::caseD_4
//                              vw_main.cpp:623 (7)
//         0053e783     MOV        this,ESI
//         0053e785     CALL       TPanel::capture_mouse                            int capture_mouse(TPanel * this)
//                               LAB_0053e78a                                                 XREF[14]:    0053e3dd(j), 0053e412(j),
//                                                                                                         0053e4b1(j), 0053e4d6(j),
//                                                                                                         0053e4f8(j), 0053e541(j),
//                                                                                                         0053e549(j), 0053e562(j),
//                                                                                                         0053e59a(j), 0053e5f0(j),
//                                                                                                         0053e633(j), 0053e663(j),
//                                                                                                         0053e675(j), 0053e781(j)
//                              vw_main.cpp:624 (14)
//         0053e78a     PUSH       0x1
//         0053e78c     PUSH       offset DAT_fffffff8
//         0053e78e     PUSH       offset DAT_fffffff4
//         0053e790     CALL       color_log                                        void color_log(uchar param_1, uchar param_2,
//         0053e795     ADD        ESP,0xc
//                              vw_main.cpp:625 (5)
//         0053e798     MOV        EAX,0x1
//                              vw_main.cpp:630 (80)
//         0053e79d     POP        EDI
//         0053e79e     POP        ESI
//         0053e79f     POP        EBP
//         0053e7a0     POP        EBX
//         0053e7a1     ADD        ESP,0x24
//         0053e7a4     RET        0x10
//                               LAB_0053e7a7                                                 XREF[2]:     0053e356(j), 0053e37a(j)
//         0053e7a7     POP        EDI
//         0053e7a8     POP        ESI
//         0053e7a9     POP        EBP
//         0053e7aa     XOR        EAX,EAX
//         0053e7ac     POP        EBX
//         0053e7ad     ADD        ESP,0x24
//         0053e7b0     RET        0x10
//         0053e7b3     ??         90h
//                              Symbol Ref: No symbol: NONAME
//                               switchD_0053e3ab::switchdataD_0053e7b4                       XREF[1]:     mouse_left_down_action:0053e3ab(*)
//         0053e7b4     addr       switchD_0053e3ab::caseD_1
//         0053e7b8     addr       switchD_0053e3ab::caseD_2
//         0053e7bc     addr       switchD_0053e3ab::caseD_9
//         0053e7c0     addr       switchD_0053e3ab::caseD_f
//         0053e7c4     addr       switchD_0053e3ab::caseD_2
//         0053e7c8     addr       switchD_0053e3ab::caseD_12
//         0053e7cc     addr       switchD_0053e3ab::caseD_9
//         0053e7d0     addr       switchD_0053e3ab::caseD_15
//                               PTR_caseD_4_0053e7d4+3                                       XREF[0,1]:   mouse_left_down_action:0053e3a5(*)
//         0053e7d4     addr       switchD_0053e3ab::caseD_4
//                              Symbol Ref: No symbol: NONAME
//                               switchD_0053e3ab::switchdataD_0053e7d8
//         0053e7d8     db         0h
//         0053e7d9     db         1h
//         0053e7da     db         1h
//         0053e7db     db         8h
//         0053e7dc     db         8h
//         0053e7dd     db         8h
//         0053e7de     db         8h
//         0053e7df     db         8h
//         0053e7e0     db         2h
//         0053e7e1     db         2h
//         0053e7e2     db         8h
//         0053e7e3     db         8h
//         0053e7e4     db         8h
//         0053e7e5     db         8h
//         0053e7e6     db         3h
//         0053e7e7     db         8h
//         0053e7e8     db         4h
//         0053e7e9     db         5h
//         0053e7ea     db         6h
//         0053e7eb     db         8h
//         0053e7ec     db         7h
//         0053e7ed     ??         90h
//         0053e7ee     ??         90h
//         0053e7ef     ??         90h
    return 0;
}

long RGE_Main_View::mouse_left_move_action(long param_1, long param_2, int param_3, int param_4) {
    /* TODO: Stub */
//                              long __thiscall mouse_left_move_action(RGE_Main_View * this, long pa
//              long              EAX:4          <RETURN>
//              RGE_Main_View *   ECX:4 (auto)   this
//              long              Stack[0x4]:4   param_1                   XREF[1]:     0053e855(R)
//              long              Stack[0x8]:4   param_2                   XREF[1]:     0053e851(R)
//              int               Stack[0xc]:4   param_3                   XREF[1]:     0053e89a(R)
//              int               Stack[0x10]:4  param_4                   XREF[1]:     0053e896(R)
//                               ?mouse_left_move_action@RGE_Main_View@@UAEJJJHH@Z            XREF[2]:     00572b34(*), 0057787c(*)
//                               RGE_Main_View::mouse_left_move_action
//                              vw_main.cpp:636 (3)
//         0053e7f0     PUSH       ESI
//         0053e7f1     MOV        ESI,this
//                              vw_main.cpp:637 (33)
//         0053e7f3     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0053e7f9     PUSH       EDI
//         0053e7fa     MOV        EAX,dword ptr [ECX + this->_padding_]
//         0053e800     CMP        EAX,0x4
//         0053e803     JZ         LAB_0053e81b
//         0053e805     CMP        EAX,0x6
//         0053e808     JZ         LAB_0053e81b
//         0053e80a     CMP        EAX,0x7
//         0053e80d     JZ         LAB_0053e81b
//         0053e80f     CMP        EAX,0x5
//         0053e812     JZ         LAB_0053e81b
//                              vw_main.cpp:638 (2)
//         0053e814     XOR        EAX,EAX
//                              vw_main.cpp:675 (5)
//         0053e816     POP        EDI
//         0053e817     POP        ESI
//         0053e818     RET        0x10
//                               LAB_0053e81b                                                 XREF[4]:     0053e803(j), 0053e808(j),
//                                                                                                         0053e80d(j), 0053e812(j)
//                              vw_main.cpp:640 (7)
//         0053e81b     CALL       RGE_Base_Game::get_paused                        int get_paused(RGE_Base_Game * this)
//         0053e820     TEST       EAX,EAX
//                              vw_main.cpp:642 (12)
//         0053e822     MOV        AL,byte ptr [ESI + 0x168]
//         0053e828     JZ         LAB_0053e84d
//         0053e82a     TEST       AL,AL
//         0053e82c     JZ         LAB_0053e83f
//                              vw_main.cpp:643 (10)
//         0053e82e     MOV        EAX,dword ptr [ESI]
//         0053e830     MOV        this,ESI
//         0053e832     CALL       dword ptr [EAX + 0xf0]
//                              vw_main.cpp:646 (2)
//         0053e838     XOR        EAX,EAX
//                              vw_main.cpp:675 (5)
//         0053e83a     POP        EDI
//         0053e83b     POP        ESI
//         0053e83c     RET        0x10
//                               LAB_0053e83f                                                 XREF[1]:     0053e82c(j)
//                              vw_main.cpp:645 (7)
//         0053e83f     MOV        this,ESI
//         0053e841     CALL       TPanel::release_mouse                            void release_mouse(TPanel * this)
//                              vw_main.cpp:646 (2)
//         0053e846     XOR        EAX,EAX
//                              vw_main.cpp:675 (5)
//         0053e848     POP        EDI
//         0053e849     POP        ESI
//         0053e84a     RET        0x10
//                               LAB_0053e84d                                                 XREF[1]:     0053e828(j)
//                              vw_main.cpp:649 (4)
//         0053e84d     TEST       AL,AL
//         0053e84f     JZ         LAB_0053e86f
//                              vw_main.cpp:651 (20)
//         0053e851     MOV        EAX,dword ptr [ESP + param_2]
//         0053e855     MOV        this,dword ptr [ESP + param_1]
//         0053e859     MOV        EDX,dword ptr [ESI]
//         0053e85b     PUSH       EAX
//         0053e85c     PUSH       this
//         0053e85d     MOV        this,ESI
//         0053e85f     CALL       dword ptr [EDX + 0xec]
//                              vw_main.cpp:674 (5)
//         0053e865     MOV        EAX,0x1
//                              vw_main.cpp:675 (5)
//         0053e86a     POP        EDI
//         0053e86b     POP        ESI
//         0053e86c     RET        0x10
//                               LAB_0053e86f                                                 XREF[1]:     0053e84f(j)
//                              vw_main.cpp:655 (32)
//         0053e86f     MOV        EDX,dword ptr [rge_base_game]                    = 00000000
//         0053e875     MOV        EAX,dword ptr [EDX + 0x1b4]
//         0053e87b     CMP        EAX,0x8
//         0053e87e     JA         switchD_0053e888::caseD_2
//         0053e880     XOR        this,this
//         0053e882     MOV        this,byte ptr [EAX + switchD_0053e888::switchd
//                               switchD_0053e888::switchD
//         0053e888     JMP        dword ptr [this->_padding_*0x4 + switchD_0053e   = 0053e88f
//                               switchD_0053e888::caseD_0                                    XREF[2]:     0053e888(j), 0053e8ec(*)
//                              vw_main.cpp:661 (7)
//         0053e88f     MOV        this,ESI
//         0053e891     CALL       TPanel::release_mouse                            void release_mouse(TPanel * this)
//                              vw_main.cpp:662 (36)
//         0053e896     MOV        EDX,dword ptr [ESP + param_4]
//         0053e89a     MOV        EAX,dword ptr [ESP + param_3]
//         0053e89e     MOV        this,dword ptr [ESI + 0xc8]
//         0053e8a4     MOV        EDI,dword ptr [ESI]
//         0053e8a6     PUSH       EDX
//         0053e8a7     MOV        EDX,dword ptr [ESI + 0xc4]
//         0053e8ad     PUSH       EAX
//         0053e8ae     PUSH       this
//         0053e8af     PUSH       EDX
//         0053e8b0     PUSH       0x2
//         0053e8b2     MOV        this,ESI
//         0053e8b4     CALL       dword ptr [EDI + 0xe8]
//                              vw_main.cpp:663 (18)
//         0053e8ba     MOV        EAX,dword ptr [ESP + 0x10]
//         0053e8be     MOV        this,dword ptr [ESP + 0xc]
//         0053e8c2     PUSH       EAX
//         0053e8c3     PUSH       this
//         0053e8c4     MOV        this,ESI
//         0053e8c6     CALL       dword ptr [EDI + 0xec]
//                              vw_main.cpp:674 (5)
//         0053e8cc     MOV        EAX,0x1
//                              vw_main.cpp:675 (5)
//         0053e8d1     POP        EDI
//         0053e8d2     POP        ESI
//         0053e8d3     RET        0x10
//                               switchD_0053e888::caseD_7                                    XREF[3]:     0053e888(j), 0053e8f0(*),
//                               switchD_0053e888::caseD_8                                                 0053e8f4(*)
//                               switchD_0053e888::caseD_1
//                              vw_main.cpp:670 (9)
//         0053e8d6     MOV        EDX,dword ptr [ESI]
//         0053e8d8     PUSH       0x1
//         0053e8da     MOV        this,ESI
//         0053e8dc     CALL       dword ptr [EDX + 0x20]
//                               switchD_0053e888::caseD_3                                    XREF[3]:     0053e87e(j), 0053e888(j),
//                               switchD_0053e888::caseD_4                                                 0053e8f8(*)
//                               switchD_0053e888::caseD_5
//                               switchD_0053e888::caseD_6
//                               switchD_0053e888::caseD_2
//                              vw_main.cpp:675 (38)
//         0053e8df     POP        EDI
//         0053e8e0     MOV        EAX,0x1
//         0053e8e5     POP        ESI
//         0053e8e6     RET        0x10
    return 0;
}

long RGE_Main_View::mouse_left_up_action(long param_1, long param_2, int param_3, int param_4) {
    /* TODO: Stub */
//                              long __thiscall mouse_left_up_action(RGE_Main_View * this, long para
//              long              EAX:4          <RETURN>
//              RGE_Main_View *   ECX:4 (auto)   this
//              long              Stack[0x4]:4   param_1                   XREF[1]:     0053ea72(R)
//              long              Stack[0x8]:4   param_2                   XREF[1]:     0053ea6e(R)
//              int               Stack[0xc]:4   param_3                   XREF[3]:     0053ea80(R), 0053eb08(R), 0053eb35(R)
//              int               Stack[0x10]:4  param_4                   XREF[1]:     0053ea6a(R)
//              RGE_Pick_Info     Stack[-0x18]   pick_info                 XREF[0,4]:   0053eaa0(*), 0053eab8(R), 0053eaea(R), 0053eb04(R)
//                               ?mouse_left_up_action@RGE_Main_View@@UAEJJJHH@Z              XREF[2]:     mouse_left_up_action:0052d780(c),
//                               RGE_Main_View::mouse_left_up_action                                       00577880(*)
//                              vw_main.cpp:681 (40)
//         0053e910     MOV        EAX,[rge_base_game]                              = 00000000
//         0053e915     SUB        ESP,0x14
//         0053e918     MOV        EAX,dword ptr [EAX + 0x1b0]
//         0053e91e     PUSH       EBX
//         0053e91f     PUSH       EBP
//         0053e920     PUSH       ESI
//         0053e921     CMP        EAX,0x4
//         0053e924     PUSH       EDI
//         0053e925     MOV        ESI,this
//         0053e927     JZ         LAB_0053e944
//         0053e929     CMP        EAX,0x6
//         0053e92c     JZ         LAB_0053e944
//         0053e92e     CMP        EAX,0x7
//         0053e931     JZ         LAB_0053e944
//         0053e933     CMP        EAX,0x5
//         0053e936     JZ         LAB_0053e944
//                              vw_main.cpp:689 (2)
//         0053e938     XOR        EAX,EAX
//                              vw_main.cpp:1076 (10)
//         0053e93a     POP        EDI
//         0053e93b     POP        ESI
//         0053e93c     POP        EBP
//         0053e93d     POP        EBX
//         0053e93e     ADD        ESP,0x14
//         0053e941     RET        0x10
//                               LAB_0053e944                                                 XREF[4]:     0053e927(j), 0053e92c(j),
//                                                                                                         0053e931(j), 0053e936(j)
//                              vw_main.cpp:691 (11)
//         0053e944     PUSH       0x1
//         0053e946     PUSH       0x16
//         0053e948     PUSH       0x4c
//         0053e94a     CALL       color_log                                        void color_log(uchar param_1, uchar param_2,
//                              vw_main.cpp:693 (19)
//         0053e94f     MOV        AL,byte ptr [ESI + 0x168]
//         0053e955     ADD        ESP,0xc
//         0053e958     XOR        EBX,EBX
//         0053e95a     TEST       AL,AL
//         0053e95c     JZ         LAB_0053ea34
//                              vw_main.cpp:695 (10)
//         0053e962     MOV        EDI,dword ptr [ESI]
//         0053e964     MOV        this,ESI
//         0053e966     CALL       dword ptr [EDI + 0xf0]
//                              vw_main.cpp:697 (15)
//         0053e96c     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0053e972     CMP        dword ptr [ECX + this->_padding_],0x15
//         0053e979     JNZ        LAB_0053e9b5
//                              vw_main.cpp:698 (58)
//         0053e97b     CMP        dword ptr [ESP + 0x30],EBX
//         0053e97f     JNZ        LAB_0053e98e
//         0053e981     CMP        dword ptr [ESP + 0x34],EBX
//         0053e985     JNZ        LAB_0053e98e
//         0053e987     MOV        EAX,0x1
//         0053e98c     JMP        LAB_0053e990
//                               LAB_0053e98e                                                 XREF[2]:     0053e97f(j), 0053e985(j)
//         0053e98e     XOR        EAX,EAX
//                               LAB_0053e990                                                 XREF[1]:     0053e98c(j)
//         0053e990     MOV        EDX,dword ptr [ESI + 0x150]
//         0053e996     MOV        this,dword ptr [ESI + 0x148]
//         0053e99c     PUSH       EAX
//         0053e99d     MOV        EAX,dword ptr [ESI + 0x14c]
//         0053e9a3     PUSH       EDX
//         0053e9a4     MOV        EDX,dword ptr [ESI + 0x144]
//         0053e9aa     PUSH       EAX
//         0053e9ab     PUSH       this
//         0053e9ac     PUSH       EDX
//         0053e9ad     MOV        this,ESI
//         0053e9af     CALL       dword ptr [EDI + 0x10c]
//                               LAB_0053e9b5                                                 XREF[1]:     0053e979(j)
//                              vw_main.cpp:700 (18)
//         0053e9b5     MOV        EAX,[rge_base_game]                              = 00000000
//         0053e9ba     CMP        dword ptr [EAX + 0x1b4],0x8
//         0053e9c1     JNZ        switchD_0053eb69::caseD_1
//                              vw_main.cpp:704 (20)
//         0053e9c7     MOV        this,dword ptr [ESP + 0x2c]
//         0053e9cb     MOV        EDX,dword ptr [ESP + 0x28]
//         0053e9cf     PUSH       0x1
//         0053e9d1     PUSH       this
//         0053e9d2     PUSH       EDX
//         0053e9d3     MOV        this,ESI
//         0053e9d5     CALL       dword ptr [EDI + 0xfc]
//                              vw_main.cpp:705 (18)
//         0053e9db     MOV        EAX,[rge_base_game]                              = 00000000
//         0053e9e0     CMP        dword ptr [EAX + 0x1b8],0x1
//         0053e9e7     JNZ        switchD_0053eb69::caseD_1
//                              vw_main.cpp:707 (6)
//         0053e9ed     MOV        this,dword ptr [ESI + 0x174]
//                              vw_main.cpp:709 (24)
//         0053e9f3     PUSH       EBX
//         0053e9f4     PUSH       0xf
//         0053e9f6     MOV        byte ptr [ECX + this->_padding_],0x2
//         0053e9fa     MOV        dword ptr [ESI + 0x174],EBX
//         0053ea00     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0053ea06     MOV        EDX,dword ptr [this->_padding_]
//         0053ea08     CALL       dword ptr [EDX + 0x10]
//                              vw_main.cpp:711 (14)
//         0053ea0b     MOV        EAX,dword ptr [ESI + 0x37c]
//         0053ea11     CMP        EAX,EBX
//         0053ea13     JZ         switchD_0053eb69::caseD_1
//                              vw_main.cpp:713 (16)
//         0053ea19     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0053ea1f     MOV        AX,word ptr [EAX + 0x4a]
//         0053ea23     PUSH       EAX
//         0053ea24     MOV        EDX,dword ptr [this->_padding_]
//         0053ea26     CALL       dword ptr [EDX + 0x14]
//                              vw_main.cpp:714 (6)
//         0053ea29     MOV        dword ptr [ESI + 0x37c],EBX
//                              vw_main.cpp:720 (5)
//         0053ea2f     JMP        switchD_0053eb69::caseD_1
//                               LAB_0053ea34                                                 XREF[1]:     0053e95c(j)
//                              vw_main.cpp:724 (7)
//         0053ea34     MOV        this,ESI
//         0053ea36     CALL       TPanel::release_mouse                            void release_mouse(TPanel * this)
//                              vw_main.cpp:726 (15)
//         0053ea3b     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0053ea41     CALL       RGE_Base_Game::get_paused                        int get_paused(RGE_Base_Game * this)
//         0053ea46     TEST       EAX,EAX
//         0053ea48     JZ         LAB_0053ea64
//                              vw_main.cpp:728 (14)
//         0053ea4a     PUSH       0x1
//         0053ea4c     PUSH       0x5f
//         0053ea4e     PUSH       0x4c
//         0053ea50     CALL       color_log                                        void color_log(uchar param_1, uchar param_2,
//         0053ea55     ADD        ESP,0xc
//                              vw_main.cpp:729 (2)
//         0053ea58     XOR        EAX,EAX
//                              vw_main.cpp:1076 (10)
//         0053ea5a     POP        EDI
//         0053ea5b     POP        ESI
//         0053ea5c     POP        EBP
//         0053ea5d     POP        EBX
//         0053ea5e     ADD        ESP,0x14
//         0053ea61     RET        0x10
//                               LAB_0053ea64                                                 XREF[1]:     0053ea48(j)
//                              vw_main.cpp:733 (6)
//         0053ea64     MOV        this,dword ptr [rge_base_game]                   = 00000000
//                              vw_main.cpp:737 (52)
//         0053ea6a     MOV        EAX,dword ptr [ESP + param_4]
//         0053ea6e     MOV        EDI,dword ptr [ESP + param_2]
//         0053ea72     MOV        EBP,dword ptr [ESP + param_1]
//         0053ea76     MOV        EBX,dword ptr [ECX + this->_padding_]
//         0053ea7c     TEST       EAX,EAX
//         0053ea7e     JNZ        LAB_0053ea8c
//         0053ea80     MOV        EAX,dword ptr [ESP + param_3]
//         0053ea84     TEST       EAX,EAX
//         0053ea86     JZ         LAB_0053eb58
//                               LAB_0053ea8c                                                 XREF[1]:     0053ea7e(j)
//         0053ea8c     CMP        EBX,0x7
//         0053ea8f     JZ         LAB_0053eb58
//         0053ea95     CMP        EBX,0x15
//         0053ea98     JZ         LAB_0053eb58
//                              vw_main.cpp:750 (22)
//         0053ea9e     PUSH       0x0
//         0053eaa0     LEA        this=>pick_info.y,[ESP + 0x14]
//         0053eaa4     PUSH       0x0
//         0053eaa6     PUSH       this
//         0053eaa7     PUSH       EDI
//         0053eaa8     PUSH       EBP
//         0053eaa9     PUSH       0x2
//         0053eaab     PUSH       0x29
//         0053eaad     MOV        this,ESI
//         0053eaaf     CALL       RGE_Main_View::pick1                             uchar pick1(RGE_Main_View * this, uchar param
//                              vw_main.cpp:751 (4)
//         0053eab4     CMP        AL,0x34
//         0053eab6     JNZ        LAB_0053eb35
//                              vw_main.cpp:753 (10)
//         0053eab8     MOV        EDX,dword ptr [ESP + pick_info.tile]
//         0053eabc     TEST       byte ptr [EDX + 0x36],0x1
//         0053eac0     JZ         LAB_0053ead0
//                              vw_main.cpp:755 (12)
//         0053eac2     MOV        this,dword ptr [ESI + 0x100]
//         0053eac8     PUSH       EDX
//         0053eac9     CALL       RGE_Player::unselect_one_object                  void unselect_one_object(RGE_Player * this, R
//                              vw_main.cpp:758 (2)
//         0053eace     JMP        LAB_0053eb2c
//                               LAB_0053ead0                                                 XREF[1]:     0053eac0(j)
//                              vw_main.cpp:760 (41)
//         0053ead0     MOV        this,dword ptr [ESI + 0x100]
//         0053ead6     MOV        EAX,dword ptr [ECX + this->_padding_]
//         0053eadc     TEST       EAX,EAX
//         0053eade     JZ         LAB_0053eb08
//         0053eae0     CMP        dword ptr [EAX + 0xc],this
//         0053eae3     JNZ        LAB_0053eaf9
//         0053eae5     CALL       RGE_Player::get_select_level                     uchar get_select_level(RGE_Player * this)
//         0053eaea     MOV        EDX,dword ptr [ESP + pick_info.tile]
//         0053eaee     MOV        this,dword ptr [EDX + 0x8]
//         0053eaf1     CMP        AL,byte ptr [ECX + this+0x8d]
//         0053eaf7     JZ         LAB_0053eb08
//                               LAB_0053eaf9                                                 XREF[1]:     0053eae3(j)
//                              vw_main.cpp:761 (15)
//         0053eaf9     MOV        this,dword ptr [ESI + 0x100]
//         0053eaff     CALL       RGE_Player::unselect_object                      void unselect_object(RGE_Player * this)
//         0053eb04     MOV        EDX,dword ptr [ESP + pick_info.tile]
//                               LAB_0053eb08                                                 XREF[2]:     0053eade(j), 0053eaf7(j)
//                              vw_main.cpp:763 (8)
//         0053eb08     MOV        EAX,dword ptr [ESP + param_3]
//         0053eb0c     TEST       EAX,EAX
//         0053eb0e     JZ         LAB_0053eb20
//                              vw_main.cpp:764 (14)
//         0053eb10     MOV        this,dword ptr [ESI + 0x100]
//         0053eb16     PUSH       0x1
//         0053eb18     PUSH       EDX
//         0053eb19     CALL       RGE_Player::select_one_object                    int select_one_object(RGE_Player * this, RGE_
//                              vw_main.cpp:765 (2)
//         0053eb1e     JMP        LAB_0053eb2c
//                               LAB_0053eb20                                                 XREF[1]:     0053eb0e(j)
//                              vw_main.cpp:766 (12)
//         0053eb20     MOV        this,dword ptr [ESI + 0x100]
//         0053eb26     PUSH       EDX
//         0053eb27     CALL       RGE_Player::select_object                        int select_object(RGE_Player * this, RGE_Stat
//                               LAB_0053eb2c                                                 XREF[2]:     0053eace(j), 0053eb1e(j)
//                              vw_main.cpp:768 (9)
//         0053eb2c     MOV        EDX,dword ptr [ESI]
//         0053eb2e     PUSH       0x1
//         0053eb30     MOV        this,ESI
//         0053eb32     CALL       dword ptr [EDX + 0x20]
//                               LAB_0053eb35                                                 XREF[1]:     0053eab6(j)
//                              vw_main.cpp:771 (29)
//         0053eb35     MOV        EAX,dword ptr [ESP + param_3]
//         0053eb39     TEST       EAX,EAX
//         0053eb3b     JNZ        switchD_0053eb69::caseD_1
//         0053eb41     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0053eb47     MOV        EAX,dword ptr [ECX + this->_padding_]
//         0053eb4a     CMP        word ptr [EAX + 0x8dc],0x2
//                              vw_main.cpp:774 (6)
//         0053eb52     JZ         switchD_0053eb69::caseD_1
//                               LAB_0053eb58                                                 XREF[3]:     0053ea86(j), 0053ea8f(j),
//                                                                                                         0053ea98(j)
//                              vw_main.cpp:779 (24)
//         0053eb58     CMP        EBX,0x14
//         0053eb5b     JA         switchD_0053eb69::caseD_1
//         0053eb61     XOR        EDX,EDX
//         0053eb63     MOV        DL,byte ptr [EBX + switchD_0053eb69::switchdat
//                               switchD_0053eb69::switchD
//         0053eb69     JMP        dword ptr [EDX*0x4 + switchD_0053eb69::switchd   = 0053ed6d
//                               switchD_0053eb69::caseD_4                                    XREF[2]:     0053eb69(j), 0053f1e0(*)
//                              vw_main.cpp:782 (12)
//         0053eb70     MOV        EAX,dword ptr [ESI]
//         0053eb72     PUSH       EDI
//         0053eb73     PUSH       EBP
//         0053eb74     MOV        this,ESI
//         0053eb76     CALL       dword ptr [EAX + 0x104]
//                              vw_main.cpp:784 (5)
//         0053eb7c     JMP        switchD_0053eb69::caseD_1
//                               switchD_0053eb69::caseD_5                                    XREF[2]:     0053eb69(j), 0053f1e4(*)
//                              vw_main.cpp:787 (12)
//         0053eb81     MOV        EDX,dword ptr [ESI]
//         0053eb83     PUSH       EDI
//         0053eb84     PUSH       EBP
//         0053eb85     MOV        this,ESI
//         0053eb87     CALL       dword ptr [EDX + 0x108]
//                              vw_main.cpp:789 (5)
//         0053eb8d     JMP        switchD_0053eb69::caseD_1
//                               switchD_0053eb69::caseD_7                                    XREF[2]:     0053eb69(j), 0053f1ec(*)
//                              vw_main.cpp:792 (34)
//         0053eb92     MOV        EAX,dword ptr [ESP + 0x30]
//         0053eb96     TEST       EAX,EAX
//         0053eb98     JNZ        LAB_0053ebb9
//         0053eb9a     MOV        EAX,dword ptr [ESP + 0x34]
//         0053eb9e     TEST       EAX,EAX
//         0053eba0     JNZ        LAB_0053ebb9
//         0053eba2     MOV        EDX,dword ptr [ESI]
//         0053eba4     MOV        EAX,0x1
//         0053eba9     PUSH       EAX
//         0053ebaa     PUSH       EDI
//         0053ebab     PUSH       EBP
//         0053ebac     MOV        this,ESI
//         0053ebae     CALL       dword ptr [EDX + 0xfc]
//                              vw_main.cpp:794 (5)
//         0053ebb4     JMP        switchD_0053eb69::caseD_1
//                               LAB_0053ebb9                                                 XREF[2]:     0053eb98(j), 0053eba0(j)
//                              vw_main.cpp:792 (15)
//         0053ebb9     MOV        EDX,dword ptr [ESI]
//         0053ebbb     XOR        EAX,EAX
//         0053ebbd     PUSH       EAX
//         0053ebbe     PUSH       EDI
//         0053ebbf     PUSH       EBP
//         0053ebc0     MOV        this,ESI
//         0053ebc2     CALL       dword ptr [EDX + 0xfc]
//                              vw_main.cpp:794 (5)
//         0053ebc8     JMP        switchD_0053eb69::caseD_1
//                               switchD_0053eb69::caseD_8                                    XREF[2]:     0053eb69(j), 0053f1f0(*)
//                              vw_main.cpp:799 (14)
//         0053ebcd     MOV        EAX,dword ptr [ESI]
//         0053ebcf     PUSH       0x1
//         0053ebd1     PUSH       EDI
//         0053ebd2     PUSH       EBP
//         0053ebd3     MOV        this,ESI
//         0053ebd5     CALL       dword ptr [EAX + 0xfc]
//                              vw_main.cpp:800 (19)
//         0053ebdb     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0053ebe1     CMP        dword ptr [ECX + this->_padding_],0x1
//         0053ebe8     JNZ        switchD_0053eb69::caseD_1
//                              vw_main.cpp:802 (6)
//         0053ebee     MOV        EDX,dword ptr [ESI + 0x174]
//                              vw_main.cpp:803 (2)
//         0053ebf4     XOR        EDI,EDI
//                              vw_main.cpp:804 (24)
//         0053ebf6     PUSH       EDI
//         0053ebf7     PUSH       0xf
//         0053ebf9     MOV        byte ptr [EDX + 0x48],0x2
//         0053ebfd     MOV        dword ptr [ESI + 0x174],EDI
//         0053ec03     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0053ec09     MOV        EAX,dword ptr [this->_padding_]
//         0053ec0b     CALL       dword ptr [EAX + 0x10]
//                              vw_main.cpp:806 (14)
//         0053ec0e     MOV        EAX,dword ptr [ESI + 0x37c]
//         0053ec14     CMP        EAX,EDI
//         0053ec16     JZ         switchD_0053eb69::caseD_1
//                              vw_main.cpp:808 (16)
//         0053ec1c     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0053ec22     MOV        AX,word ptr [EAX + 0x4a]
//         0053ec26     PUSH       EAX
//         0053ec27     MOV        EDX,dword ptr [this->_padding_]
//         0053ec29     CALL       dword ptr [EDX + 0x14]
//                              vw_main.cpp:809 (6)
//         0053ec2c     MOV        dword ptr [ESI + 0x37c],EDI
//                              vw_main.cpp:813 (5)
//         0053ec32     JMP        switchD_0053eb69::caseD_1
//                               switchD_0053eb69::caseD_e                                    XREF[2]:     0053eb69(j), 0053f1f4(*)
//                              vw_main.cpp:816 (33)
//         0053ec37     MOV        this,dword ptr [ESI + 0x100]
//         0053ec3d     PUSH       0x1
//         0053ec3f     LEA        EAX,[ESP + 0x14]
//         0053ec43     MOV        EDX,dword ptr [ECX + this->_padding_]
//         0053ec49     MOV        this,ESI
//         0053ec4b     PUSH       EDX
//         0053ec4c     PUSH       EAX
//         0053ec4d     PUSH       EDI
//         0053ec4e     PUSH       EBP
//         0053ec4f     PUSH       0x0
//         0053ec51     PUSH       0x29
//         0053ec53     CALL       RGE_Main_View::pick1                             uchar pick1(RGE_Main_View * this, uchar param
//                              vw_main.cpp:817 (8)
//         0053ec58     CMP        AL,0x34
//         0053ec5a     JNZ        switchD_0053eb69::caseD_1
//                              vw_main.cpp:819 (11)
//         0053ec60     MOV        EAX,dword ptr [ESP + 0x1c]
//         0053ec64     MOV        this,dword ptr [EAX + 0x18]
//         0053ec67     TEST       this,this
//         0053ec69     JZ         LAB_0053ec78
//                              vw_main.cpp:820 (7)
//         0053ec6b     CALL       RGE_Active_Sprite_List::get_lowest_draw_level    uchar get_lowest_draw_level(RGE_Active_Sprite
//         0053ec70     MOV        BL,AL
//                              vw_main.cpp:821 (13)
//         0053ec72     MOV        EAX,dword ptr [ESP + 0x1c]
//         0053ec76     JMP        LAB_0053ec8e
//                               LAB_0053ec78                                                 XREF[1]:     0053ec69(j)
//         0053ec78     MOV        this,dword ptr [EAX + 0x10]
//         0053ec7b     TEST       this,this
//         0053ec7d     JZ         LAB_0053ec8c
//                              vw_main.cpp:822 (7)
//         0053ec7f     CALL       RGE_Sprite::get_lowest_draw_level                uchar get_lowest_draw_level(RGE_Sprite * this)
//         0053ec84     MOV        BL,AL
//                              vw_main.cpp:823 (6)
//         0053ec86     MOV        EAX,dword ptr [ESP + 0x1c]
//         0053ec8a     JMP        LAB_0053ec8e
//                               LAB_0053ec8c                                                 XREF[1]:     0053ec7d(j)
//                              vw_main.cpp:824 (2)
//         0053ec8c     MOV        BL,0x14
//                               LAB_0053ec8e                                                 XREF[2]:     0053ec76(j), 0053ec8a(j)
//                              vw_main.cpp:826 (15)
//         0053ec8e     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0053ec94     CMP        dword ptr [ECX + this->_padding_],0x7
//         0053ec9b     JNZ        LAB_0053ecab
//                              vw_main.cpp:827 (12)
//         0053ec9d     TEST       EAX,EAX
//         0053ec9f     JZ         LAB_0053ecb2
//         0053eca1     MOV        EDX,dword ptr [EAX]
//         0053eca3     PUSH       0x1
//         0053eca5     MOV        this,EAX
//         0053eca7     CALL       dword ptr [EDX]
//                              vw_main.cpp:828 (2)
//         0053eca9     JMP        LAB_0053ecb2
//                               LAB_0053ecab                                                 XREF[1]:     0053ec9b(j)
//                              vw_main.cpp:829 (7)
//         0053ecab     MOV        EDX,dword ptr [EAX]
//         0053ecad     MOV        this,EAX
//         0053ecaf     CALL       dword ptr [EDX + 0x68]
//                               LAB_0053ecb2                                                 XREF[2]:     0053ec9f(j), 0053eca9(j)
//                              vw_main.cpp:831 (8)
//         0053ecb2     TEST       BL,BL
//         0053ecb4     JNZ        switchD_0053eb69::caseD_1
//                              vw_main.cpp:832 (4)
//         0053ecba     MOV        EAX,dword ptr [ESI]
//         0053ecbc     PUSH       0x2
//                              vw_main.cpp:835 (5)
//         0053ecbe     JMP        LAB_0053f1ba
//                               switchD_0053eb69::caseD_10                                   XREF[2]:     0053eb69(j), 0053f1fc(*)
//                              vw_main.cpp:838 (33)
//         0053ecc3     MOV        this,dword ptr [ESI + 0x100]
//         0053ecc9     PUSH       0x1
//         0053eccb     LEA        EAX,[ESP + 0x14]
//         0053eccf     MOV        EDX,dword ptr [ECX + this->_padding_]
//         0053ecd5     MOV        this,ESI
//         0053ecd7     PUSH       EDX
//         0053ecd8     PUSH       EAX
//         0053ecd9     PUSH       EDI
//         0053ecda     PUSH       EBP
//         0053ecdb     PUSH       0x1
//         0053ecdd     PUSH       0x29
//         0053ecdf     CALL       RGE_Main_View::pick1                             uchar pick1(RGE_Main_View * this, uchar param
//                              vw_main.cpp:839 (8)
//         0053ece4     CMP        AL,0x34
//         0053ece6     JNZ        switchD_0053eb69::caseD_1
//                              vw_main.cpp:841 (7)
//         0053ecec     MOV        this,dword ptr [ESI + 0x40]
//         0053ecef     TEST       this,this
//         0053ecf1     JZ         LAB_0053ed20
//                              vw_main.cpp:843 (18)
//         0053ecf3     MOV        EAX,dword ptr [ESP + 0x1c]
//         0053ecf7     MOV        EDX,dword ptr [this->_padding_]
//         0053ecf9     PUSH       0x0
//         0053ecfb     PUSH       EAX
//         0053ecfc     PUSH       0x10
//         0053ecfe     PUSH       ESI
//         0053ecff     CALL       dword ptr [EDX + 0xb4]
//                              vw_main.cpp:844 (18)
//         0053ed05     MOV        this,dword ptr [ESP + 0x1c]
//         0053ed09     PUSH       0x1
//         0053ed0b     PUSH       this
//         0053ed0c     MOV        this,dword ptr [ESI + 0x100]
//         0053ed12     CALL       RGE_Player::select_one_object                    int select_one_object(RGE_Player * this, RGE_
//                              vw_main.cpp:845 (9)
//         0053ed17     MOV        EDX,dword ptr [ESI]
//         0053ed19     PUSH       0x1
//         0053ed1b     MOV        this,ESI
//         0053ed1d     CALL       dword ptr [EDX + 0x20]
//                               LAB_0053ed20                                                 XREF[1]:     0053ecf1(j)
//                              vw_main.cpp:847 (15)
//         0053ed20     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0053ed26     PUSH       0x0
//         0053ed28     PUSH       0x0
//         0053ed2a     MOV        EAX,dword ptr [this->_padding_]
//         0053ed2c     CALL       dword ptr [EAX + 0x10]
//                              vw_main.cpp:850 (5)
//         0053ed2f     JMP        switchD_0053eb69::caseD_1
//                               switchD_0053eb69::caseD_14                                   XREF[2]:     0053eb69(j), 0053f200(*)
//                              vw_main.cpp:858 (33)
//         0053ed34     MOV        this,dword ptr [ESI + 0x100]
//         0053ed3a     PUSH       0x1
//         0053ed3c     LEA        EAX,[ESP + 0x14]
//         0053ed40     MOV        EDX,dword ptr [ECX + this->_padding_]
//         0053ed46     MOV        this,ESI
//         0053ed48     PUSH       EDX
//         0053ed49     PUSH       EAX
//         0053ed4a     PUSH       EDI
//         0053ed4b     PUSH       EBP
//         0053ed4c     PUSH       0x2
//         0053ed4e     PUSH       0x29
//         0053ed50     CALL       RGE_Main_View::pick1                             uchar pick1(RGE_Main_View * this, uchar param
//                              vw_main.cpp:859 (8)
//         0053ed55     CMP        AL,0x34
//         0053ed57     JNZ        switchD_0053eb69::caseD_1
//                              vw_main.cpp:860 (11)
//         0053ed5d     MOV        this,dword ptr [ESP + 0x1c]
//         0053ed61     PUSH       0x1
//         0053ed63     MOV        EDX,dword ptr [this->_padding_]
//         0053ed65     CALL       dword ptr [EDX + 0x78]
//                              vw_main.cpp:863 (5)
//         0053ed68     JMP        switchD_0053eb69::caseD_1
//                               switchD_0053eb69::caseD_6                                    XREF[3]:     0053eb69(j), 0053f1dc(*),
//                               switchD_0053eb69::caseD_0                                                 0053f1e8(*)
//                              vw_main.cpp:868 (5)
//         0053ed6d     CMP        EBX,0x6
//         0053ed70     JNZ        LAB_0053ed81
//                              vw_main.cpp:869 (15)
//         0053ed72     MOV        EAX,dword ptr [this->_padding_]
//         0053ed74     PUSH       0x0
//         0053ed76     PUSH       0x0
//         0053ed78     CALL       dword ptr [EAX + 0x10]
//         0053ed7b     MOV        this,dword ptr [rge_base_game]                   = 00000000
//                               LAB_0053ed81                                                 XREF[1]:     0053ed70(j)
//                              vw_main.cpp:875 (3)
//         0053ed81     MOV        this,dword ptr [ECX + this->_padding_]
//                              vw_main.cpp:878 (32)
//         0053ed84     MOV        EAX,dword ptr [ESI + 0x36c]
//         0053ed8a     CMP        word ptr [this->_padding_ + 0x8dc],0x2
//         0053ed92     JNZ        LAB_0053ee59
//         0053ed98     CMP        EBP,EAX
//         0053ed9a     JNZ        LAB_0053edba
//         0053ed9c     CMP        EDI,dword ptr [ESI + 0x370]
//         0053eda2     JNZ        LAB_0053edba
//                              vw_main.cpp:879 (20)
//         0053eda4     MOV        EDX,dword ptr [ESI + 0x100]
//         0053edaa     PUSH       0x0
//         0053edac     LEA        this,[ESP + 0x14]
//         0053edb0     MOV        EAX,dword ptr [EDX + 0x130]
//         0053edb6     PUSH       EAX
//         0053edb7     PUSH       this
//                              vw_main.cpp:880 (2)
//         0053edb8     JMP        LAB_0053edc3
//                               LAB_0053edba                                                 XREF[2]:     0053ed9a(j), 0053eda2(j)
//                              vw_main.cpp:881 (22)
//         0053edba     PUSH       0x0
//         0053edbc     LEA        EDX,[ESP + 0x14]
//         0053edc0     PUSH       0x0
//         0053edc2     PUSH       EDX
//                               LAB_0053edc3                                                 XREF[1]:     0053edb8(j)
//         0053edc3     PUSH       EDI
//         0053edc4     PUSH       EBP
//         0053edc5     PUSH       0x2
//         0053edc7     PUSH       0x29
//         0053edc9     MOV        this,ESI
//         0053edcb     CALL       RGE_Main_View::pick1                             uchar pick1(RGE_Main_View * this, uchar param
//                              vw_main.cpp:884 (3)
//         0053edd0     OR         this,0xffffffff
//                              vw_main.cpp:887 (16)
//         0053edd3     CMP        AL,0x34
//         0053edd5     MOV        dword ptr [ESI + 0x36c],this
//         0053eddb     MOV        dword ptr [ESI + 0x370],this
//         0053ede1     JNZ        LAB_0053ee49
//                              vw_main.cpp:894 (8)
//         0053ede3     MOV        EAX,dword ptr [ESP + 0x1c]
//         0053ede7     TEST       byte ptr [EAX + 0x36],0x1
//                              vw_main.cpp:896 (22)
//         0053edeb     MOV        this,dword ptr [ESI + 0x100]
//         0053edf1     JZ         LAB_0053ee1a
//         0053edf3     CMP        word ptr [ECX + this->_padding_],0x1
//         0053edfb     JLE        switchD_0053eb69::caseD_1
//                              vw_main.cpp:898 (5)
//         0053ee01     CALL       RGE_Player::unselect_object                      void unselect_object(RGE_Player * this)
//                              vw_main.cpp:899 (18)
//         0053ee06     MOV        this,dword ptr [ESP + 0x1c]
//         0053ee0a     PUSH       0x1
//         0053ee0c     PUSH       this
//         0053ee0d     MOV        this,dword ptr [ESI + 0x100]
//         0053ee13     CALL       RGE_Player::select_one_object                    int select_one_object(RGE_Player * this, RGE_
//                              vw_main.cpp:909 (2)
//         0053ee18     JMP        LAB_0053ee2f
//                               LAB_0053ee1a                                                 XREF[1]:     0053edf1(j)
//                              vw_main.cpp:911 (5)
//         0053ee1a     CALL       RGE_Player::unselect_object                      void unselect_object(RGE_Player * this)
//                              vw_main.cpp:912 (16)
//         0053ee1f     MOV        EAX,dword ptr [ESP + 0x1c]
//         0053ee23     MOV        this,dword ptr [ESI + 0x100]
//         0053ee29     PUSH       EAX
//         0053ee2a     CALL       RGE_Player::select_object                        int select_object(RGE_Player * this, RGE_Stat
//                               LAB_0053ee2f                                                 XREF[1]:     0053ee18(j)
//                              vw_main.cpp:913 (9)
//         0053ee2f     MOV        EDX,dword ptr [ESI]
//         0053ee31     PUSH       0x1
//         0053ee33     MOV        this,ESI
//         0053ee35     CALL       dword ptr [EDX + 0x20]
//                              vw_main.cpp:914 (6)
//         0053ee38     MOV        dword ptr [ESI + 0x36c],EBP
//                              vw_main.cpp:915 (6)
//         0053ee3e     MOV        dword ptr [ESI + 0x370],EDI
//                              vw_main.cpp:918 (5)
//         0053ee44     JMP        switchD_0053eb69::caseD_1
//                               LAB_0053ee49                                                 XREF[1]:     0053ede1(j)
//                              vw_main.cpp:920 (11)
//         0053ee49     MOV        this,dword ptr [ESI + 0x100]
//         0053ee4f     CALL       RGE_Player::unselect_object                      void unselect_object(RGE_Player * this)
//                              vw_main.cpp:924 (5)
//         0053ee54     JMP        LAB_0053f1b6
//                               LAB_0053ee59                                                 XREF[1]:     0053ed92(j)
//                              vw_main.cpp:932 (12)
//         0053ee59     CMP        EBP,EAX
//         0053ee5b     JNZ        LAB_0053ee7b
//         0053ee5d     CMP        EDI,dword ptr [ESI + 0x370]
//         0053ee63     JNZ        LAB_0053ee7b
//                              vw_main.cpp:933 (20)
//         0053ee65     MOV        this,dword ptr [ESI + 0x100]
//         0053ee6b     PUSH       0x1
//         0053ee6d     LEA        EAX,[ESP + 0x14]
//         0053ee71     MOV        EDX,dword ptr [ECX + this->_padding_]
//         0053ee77     PUSH       EDX
//         0053ee78     PUSH       EAX
//                              vw_main.cpp:934 (2)
//         0053ee79     JMP        LAB_0053ee84
//                               LAB_0053ee7b                                                 XREF[2]:     0053ee5b(j), 0053ee63(j)
//                              vw_main.cpp:935 (22)
//         0053ee7b     PUSH       0x1
//         0053ee7d     LEA        this,[ESP + 0x14]
//         0053ee81     PUSH       0x0
//         0053ee83     PUSH       this
//                               LAB_0053ee84                                                 XREF[1]:     0053ee79(j)
//         0053ee84     PUSH       EDI
//         0053ee85     PUSH       EBP
//         0053ee86     PUSH       0x1
//         0053ee88     PUSH       0x2a
//         0053ee8a     MOV        this,ESI
//         0053ee8c     CALL       RGE_Main_View::pick1                             uchar pick1(RGE_Main_View * this, uchar param
//                              vw_main.cpp:936 (8)
//         0053ee91     CMP        AL,0x34
//         0053ee93     MOV        byte ptr [ESP + 0x30],AL
//         0053ee97     JNZ        LAB_0053eec9
//                              vw_main.cpp:940 (34)
//         0053ee99     CMP        EBP,dword ptr [ESI + 0x36c]
//         0053ee9f     JNZ        LAB_0053eec9
//         0053eea1     CMP        EDI,dword ptr [ESI + 0x370]
//         0053eea7     JNZ        LAB_0053eec9
//         0053eea9     MOV        this,dword ptr [ESI + 0x100]
//         0053eeaf     MOV        EBX,dword ptr [ESP + 0x1c]
//         0053eeb3     CMP        EBX,dword ptr [ECX + this->_padding_]
//         0053eeb9     JZ         LAB_0053eecd
//                              vw_main.cpp:942 (5)
//         0053eebb     CALL       RGE_Player::unselect_object                      void unselect_object(RGE_Player * this)
//                              vw_main.cpp:943 (13)
//         0053eec0     MOV        EDX,dword ptr [ESI]
//         0053eec2     PUSH       0x1
//         0053eec4     MOV        this,ESI
//         0053eec6     CALL       dword ptr [EDX + 0x20]
//                               LAB_0053eec9                                                 XREF[3]:     0053ee97(j), 0053ee9f(j),
//                                                                                                         0053eea7(j)
//         0053eec9     MOV        EBX,dword ptr [ESP + 0x1c]
//                               LAB_0053eecd                                                 XREF[1]:     0053eeb9(j)
//                              vw_main.cpp:948 (9)
//         0053eecd     OR         EAX,0xffffffff
//         0053eed0     MOV        dword ptr [ESI + 0x36c],EAX
//                              vw_main.cpp:949 (6)
//         0053eed6     MOV        dword ptr [ESI + 0x370],EAX
//                              vw_main.cpp:951 (11)
//         0053eedc     CMP        byte ptr [ESP + 0x30],0x34
//         0053eee1     JNZ        LAB_0053f0c7
//                              vw_main.cpp:955 (37)
//         0053eee7     MOV        EAX,[rge_base_game]                              = 00000000
//         0053eeec     MOV        EAX,dword ptr [EAX + 0x1b0]
//         0053eef2     CMP        EAX,0x5
//         0053eef5     JZ         LAB_0053ef28
//         0053eef7     MOV        this,dword ptr [ESI + 0x100]
//         0053eefd     CMP        word ptr [ECX + this->_padding_],0x0
//         0053ef05     JLE        LAB_0053ef28
//         0053ef07     CMP        EAX,0x7
//         0053ef0a     JZ         LAB_0053ef28
//                              vw_main.cpp:957 (18)
//         0053ef0c     MOV        EDX,dword ptr [ESI]
//         0053ef0e     PUSH       -0x1
//         0053ef10     PUSH       0x0
//         0053ef12     PUSH       EDI
//         0053ef13     PUSH       EBP
//         0053ef14     MOV        this,ESI
//         0053ef16     CALL       dword ptr [EDX + 0x100]
//         0053ef1c     TEST       EAX,EAX
//                              vw_main.cpp:958 (10)
//         0053ef1e     JNZ        LAB_0053f1cd
//         0053ef24     MOV        EBX,dword ptr [ESP + 0x1c]
//                               LAB_0053ef28                                                 XREF[3]:     0053eef5(j), 0053ef05(j),
//                                                                                                         0053ef0a(j)
//                              vw_main.cpp:962 (6)
//         0053ef28     TEST       byte ptr [EBX + 0x36],0x1
//         0053ef2c     JZ         LAB_0053ef7d
//                              vw_main.cpp:975 (20)
//         0053ef2e     MOV        this,dword ptr [ESI + 0x100]
//         0053ef34     CMP        word ptr [ECX + this->_padding_],0x1
//         0053ef3c     JLE        LAB_0053f1cd
//                              vw_main.cpp:977 (5)
//         0053ef42     CALL       RGE_Player::unselect_object                      void unselect_object(RGE_Player * this)
//                              vw_main.cpp:978 (18)
//         0053ef47     MOV        EAX,dword ptr [ESP + 0x1c]
//         0053ef4b     MOV        this,dword ptr [ESI + 0x100]
//         0053ef51     PUSH       0x1
//         0053ef53     PUSH       EAX
//         0053ef54     CALL       RGE_Player::select_one_object                    int select_one_object(RGE_Player * this, RGE_
//                              vw_main.cpp:979 (9)
//         0053ef59     MOV        EDX,dword ptr [ESI]
//         0053ef5b     PUSH       0x1
//         0053ef5d     MOV        this,ESI
//         0053ef5f     CALL       dword ptr [EDX + 0x20]
//                              vw_main.cpp:980 (6)
//         0053ef62     MOV        dword ptr [ESI + 0x36c],EBP
//                              vw_main.cpp:981 (6)
//         0053ef68     MOV        dword ptr [ESI + 0x370],EDI
//                              vw_main.cpp:1075 (5)
//         0053ef6e     MOV        EAX,0x1
//                              vw_main.cpp:1076 (10)
//         0053ef73     POP        EDI
//         0053ef74     POP        ESI
//         0053ef75     POP        EBP
//         0053ef76     POP        EBX
//         0053ef77     ADD        ESP,0x14
//         0053ef7a     RET        0x10
//                               LAB_0053ef7d                                                 XREF[1]:     0053ef2c(j)
//                              vw_main.cpp:992 (31)
//         0053ef7d     MOV        EAX,dword ptr [ESI + 0x100]
//         0053ef83     MOV        this,dword ptr [EBX + 0xc]
//         0053ef86     CMP        this,EAX
//         0053ef88     JZ         LAB_0053f04a
//         0053ef8e     CMP        word ptr [EAX + 0x19c],0x0
//         0053ef96     JZ         LAB_0053f04a
//                              vw_main.cpp:1007 (21)
//         0053ef9c     MOV        EAX,[rge_base_game]                              = 00000000
//         0053efa1     MOV        EAX,dword ptr [EAX + 0x1b0]
//         0053efa7     CMP        EAX,0x5
//         0053efaa     JZ         LAB_0053efcd
//         0053efac     CMP        EAX,0x7
//         0053efaf     JZ         LAB_0053efcd
//                              vw_main.cpp:1009 (18)
//         0053efb1     MOV        EDX,dword ptr [ESI]
//         0053efb3     PUSH       -0x1
//         0053efb5     PUSH       0x1
//         0053efb7     PUSH       EDI
//         0053efb8     PUSH       EBP
//         0053efb9     MOV        this,ESI
//         0053efbb     CALL       dword ptr [EDX + 0x100]
//         0053efc1     TEST       EAX,EAX
//                              vw_main.cpp:1012 (10)
//         0053efc3     JNZ        switchD_0053eb69::caseD_1
//         0053efc9     MOV        EBX,dword ptr [ESP + 0x1c]
//                               LAB_0053efcd                                                 XREF[2]:     0053efaa(j), 0053efaf(j)
//                              vw_main.cpp:1017 (72)
//         0053efcd     MOV        EAX,dword ptr [EBX + 0x8]
//         0053efd0     CMP        byte ptr [EAX + 0x8d],0x2
//         0053efd7     JC         LAB_0053f0c7
//         0053efdd     MOV        this,dword ptr [ESI + 0x104]
//         0053efe3     MOV        AL,byte ptr [this->_padding_ + 0x8db8]
//         0053efe9     TEST       AL,AL
//         0053efeb     JNZ        LAB_0053f015
//         0053efed     FLD        float ptr [EBX + 0x3c]
//         0053eff0     CALL       __ftol                                           undefined __ftol()
//         0053eff5     FLD        float ptr [EBX + 0x38]
//         0053eff8     PUSH       EAX
//         0053eff9     CALL       __ftol                                           undefined __ftol()
//         0053effe     MOV        EDX,dword ptr [ESI + 0x100]
//         0053f004     PUSH       EAX
//         0053f005     MOV        this,dword ptr [EDX + 0x38]
//         0053f008     CALL       RGE_Visible_Map::get_visible                     uchar get_visible(RGE_Visible_Map * this, int
//         0053f00d     CMP        AL,0xf
//         0053f00f     JNZ        LAB_0053f0c7
//                               LAB_0053f015                                                 XREF[1]:     0053efeb(j)
//                              vw_main.cpp:1019 (11)
//         0053f015     MOV        this,dword ptr [ESI + 0x100]
//         0053f01b     CALL       RGE_Player::unselect_object                      void unselect_object(RGE_Player * this)
//                              vw_main.cpp:1020 (16)
//         0053f020     MOV        EAX,dword ptr [ESP + 0x1c]
//         0053f024     MOV        this,dword ptr [ESI + 0x100]
//         0053f02a     PUSH       EAX
//         0053f02b     CALL       RGE_Player::select_object                        int select_object(RGE_Player * this, RGE_Stat
//                              vw_main.cpp:1021 (9)
//         0053f030     MOV        EDX,dword ptr [ESI]
//         0053f032     PUSH       0x1
//         0053f034     MOV        this,ESI
//         0053f036     CALL       dword ptr [EDX + 0x20]
//                              vw_main.cpp:1022 (6)
//         0053f039     MOV        dword ptr [ESI + 0x36c],EBP
//                              vw_main.cpp:1023 (6)
//         0053f03f     MOV        dword ptr [ESI + 0x370],EDI
//                              vw_main.cpp:1025 (5)
//         0053f045     JMP        switchD_0053eb69::caseD_1
//                               LAB_0053f04a                                                 XREF[2]:     0053ef88(j), 0053ef96(j)
//                              vw_main.cpp:994 (72)
//         0053f04a     MOV        EAX,dword ptr [EBX + 0x8]
//         0053f04d     CMP        byte ptr [EAX + 0x8d],0x2
//         0053f054     JC         switchD_0053eb69::caseD_1
//         0053f05a     MOV        this,dword ptr [ESI + 0x104]
//         0053f060     MOV        AL,byte ptr [this->_padding_ + 0x8db8]
//         0053f066     TEST       AL,AL
//         0053f068     JNZ        LAB_0053f092
//         0053f06a     FLD        float ptr [EBX + 0x3c]
//         0053f06d     CALL       __ftol                                           undefined __ftol()
//         0053f072     FLD        float ptr [EBX + 0x38]
//         0053f075     PUSH       EAX
//         0053f076     CALL       __ftol                                           undefined __ftol()
//         0053f07b     PUSH       EAX
//         0053f07c     MOV        EAX,dword ptr [ESI + 0x100]
//         0053f082     MOV        this,dword ptr [EAX + 0x38]
//         0053f085     CALL       RGE_Visible_Map::get_visible                     uchar get_visible(RGE_Visible_Map * this, int
//         0053f08a     CMP        AL,0xf
//         0053f08c     JNZ        switchD_0053eb69::caseD_1
//                               LAB_0053f092                                                 XREF[1]:     0053f068(j)
//                              vw_main.cpp:996 (11)
//         0053f092     MOV        this,dword ptr [ESI + 0x100]
//         0053f098     CALL       RGE_Player::unselect_object                      void unselect_object(RGE_Player * this)
//                              vw_main.cpp:997 (16)
//         0053f09d     MOV        EDX,dword ptr [ESP + 0x1c]
//         0053f0a1     MOV        this,dword ptr [ESI + 0x100]
//         0053f0a7     PUSH       EDX
//         0053f0a8     CALL       RGE_Player::select_object                        int select_object(RGE_Player * this, RGE_Stat
//                              vw_main.cpp:998 (9)
//         0053f0ad     MOV        EAX,dword ptr [ESI]
//         0053f0af     PUSH       0x1
//         0053f0b1     MOV        this,ESI
//         0053f0b3     CALL       dword ptr [EAX + 0x20]
//                              vw_main.cpp:999 (6)
//         0053f0b6     MOV        dword ptr [ESI + 0x36c],EBP
//                              vw_main.cpp:1000 (6)
//         0053f0bc     MOV        dword ptr [ESI + 0x370],EDI
//                              vw_main.cpp:1003 (5)
//         0053f0c2     JMP        switchD_0053eb69::caseD_1
//                               LAB_0053f0c7                                                 XREF[3]:     0053eee1(j), 0053efd7(j),
//                                                                                                         0053f00f(j)
//                              vw_main.cpp:1029 (11)
//         0053f0c7     CMP        byte ptr [ESP + 0x30],0x33
//         0053f0cc     JNZ        switchD_0053eb69::caseD_1
//                              vw_main.cpp:1032 (30)
//         0053f0d2     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0053f0d8     MOV        EAX,dword ptr [ECX + this->_padding_]
//         0053f0de     CMP        EAX,0x5
//         0053f0e1     JZ         switchD_0053eb69::caseD_1
//         0053f0e7     CMP        EAX,0x7
//         0053f0ea     JZ         switchD_0053eb69::caseD_1
//                              vw_main.cpp:1034 (8)
//         0053f0f0     MOV        EAX,dword ptr [ESP + 0x34]
//         0053f0f4     TEST       EAX,EAX
//         0053f0f6     JNZ        LAB_0053f115
//                              vw_main.cpp:1036 (24)
//         0053f0f8     MOV        EDX,dword ptr [ESI]
//         0053f0fa     PUSH       -0x1
//         0053f0fc     PUSH       0x1
//         0053f0fe     PUSH       EDI
//         0053f0ff     PUSH       EBP
//         0053f100     MOV        this,ESI
//         0053f102     CALL       dword ptr [EDX + 0x100]
//         0053f108     TEST       EAX,EAX
//         0053f10a     JZ         switchD_0053eb69::caseD_1
//                              vw_main.cpp:1039 (5)
//         0053f110     JMP        switchD_0053eb69::caseD_1
//                               LAB_0053f115                                                 XREF[1]:     0053f0f6(j)
//                              vw_main.cpp:1049 (37)
//         0053f115     PUSH       -0x1
//         0053f117     PUSH       -0x1
//         0053f119     PUSH       -0x1
//         0053f11b     LEA        EAX,[ESP + 0x3c]
//         0053f11f     PUSH       -0x1
//         0053f121     LEA        this,[ESP + 0x44]
//         0053f125     PUSH       EAX
//         0053f126     PUSH       this
//         0053f127     MOV        this,dword ptr [ESI + 0x100]
//         0053f12d     CALL       RGE_Player::get_selected_objects_to_command      uchar get_selected_objects_to_command(RGE_Pla
//         0053f132     TEST       AL,AL
//         0053f134     JZ         switchD_0053eb69::caseD_1
//                              vw_main.cpp:1051 (10)
//         0053f13a     MOV        EDX,dword ptr [ESP + 0x34]
//         0053f13e     PUSH       EDX
//         0053f13f     CALL       free                                             undefined free()
//                              vw_main.cpp:1057 (12)
//         0053f144     MOV        EAX,[allow_user_commands]                        = 1h
//         0053f149     ADD        ESP,0x4
//         0053f14c     TEST       EAX,EAX
//         0053f14e     JZ         switchD_0053eb69::caseD_1
//                              vw_main.cpp:1059 (12)
//         0053f150     LEA        EAX,[ESP + 0x10]
//         0053f154     MOV        this,ESI
//         0053f156     PUSH       EAX
//         0053f157     CALL       RGE_Main_View::fixup_pick_info                   void fixup_pick_info(RGE_Main_View * this, RG
//                              vw_main.cpp:1060 (29)
//         0053f15c     MOV        EAX,dword ptr [ESP + 0x14]
//         0053f160     MOV        this,dword ptr [ESI + 0x100]
//         0053f166     PUSH       0x3f800000
//         0053f16b     PUSH       EAX
//         0053f16c     MOV        EAX,dword ptr [ESP + 0x18]
//         0053f170     MOV        EDX,dword ptr [this->_padding_]
//         0053f172     PUSH       EAX
//         0053f173     CALL       dword ptr [EDX + 0xd8]
//                              vw_main.cpp:1061 (9)
//         0053f179     PUSH       0x2
//         0053f17b     MOV        this,ESI
//         0053f17d     CALL       RGE_Main_View::reset_display_object_selection    void reset_display_object_selection(RGE_Main_
//                              vw_main.cpp:1062 (52)
//         0053f182     MOV        this,dword ptr [ESI + 0x134]
//         0053f188     MOV        EAX,[rge_base_game]                              = 00000000
//         0053f18d     MOV        EDX,dword ptr [ESI + 0x130]
//         0053f193     PUSH       0xfa
//         0053f198     PUSH       0x1
//         0053f19a     PUSH       0x0
//         0053f19c     PUSH       0xf
//         0053f19e     ADD        this,EDI
//         0053f1a0     PUSH       0x0
//         0053f1a2     PUSH       this
//         0053f1a3     MOV        this,dword ptr [EAX + 0x5c]
//         0053f1a6     ADD        EDX,EBP
//         0053f1a8     PUSH       EDX
//         0053f1a9     PUSH       0x0
//         0053f1ab     MOV        EDX,dword ptr [ECX + this->_padding_]
//         0053f1ae     MOV        this,ESI
//         0053f1b0     PUSH       EDX
//         0053f1b1     CALL       RGE_View::add_overlay_sprite                     void add_overlay_sprite(RGE_View * this, TSha
//                               LAB_0053f1b6                                                 XREF[1]:     0053ee54(j)
//                              vw_main.cpp:1063 (9)
//         0053f1b6     MOV        EAX,dword ptr [ESI]
//         0053f1b8     PUSH       0x1
//                               LAB_0053f1ba                                                 XREF[1]:     0053ecbe(j)
//         0053f1ba     MOV        this,ESI
//         0053f1bc     CALL       dword ptr [EAX + 0x20]
//                               switchD_0053eb69::caseD_2                                    XREF[37]:    0053e9c1(j), 0053e9e7(j),
//                               switchD_0053eb69::caseD_3                                                 0053ea13(j), 0053ea2f(j),
//                               switchD_0053eb69::caseD_9                                                 0053eb3b(j), 0053eb52(j),
//                               switchD_0053eb69::caseD_a                                                 0053eb5b(j), 0053eb69(j),
//                               switchD_0053eb69::caseD_b                                                 0053eb7c(j), 0053eb8d(j),
//                               switchD_0053eb69::caseD_c                                                 0053ebb4(j), 0053ebc8(j),
//                               switchD_0053eb69::caseD_d                                                 0053ebe8(j), 0053ec16(j),
//                               switchD_0053eb69::caseD_f                                                 0053ec32(j), 0053ec5a(j),
//                               switchD_0053eb69::caseD_11                                                0053ecb4(j), 0053ece6(j),
//                               switchD_0053eb69::caseD_12                                                0053ed2f(j), 0053f1f8(*), [more]
//                               switchD_0053eb69::caseD_13
//                               switchD_0053eb69::caseD_1
//                              vw_main.cpp:1074 (14)
//         0053f1bf     PUSH       0x1
//         0053f1c1     PUSH       0x5f
//         0053f1c3     PUSH       0x4c
//         0053f1c5     CALL       color_log                                        void color_log(uchar param_1, uchar param_2,
//         0053f1ca     ADD        ESP,0xc
//                               LAB_0053f1cd                                                 XREF[2]:     0053ef1e(j), 0053ef3c(j)
//                              vw_main.cpp:1076 (80)
//         0053f1cd     POP        EDI
//         0053f1ce     POP        ESI
//         0053f1cf     POP        EBP
//         0053f1d0     MOV        EAX,0x1
//         0053f1d5     POP        EBX
//         0053f1d6     ADD        ESP,0x14
//         0053f1d9     RET        0x10
//                              Symbol Ref: No symbol: NONAME
//                               switchD_0053eb69::switchdataD_0053f1dc                       XREF[1]:     mouse_left_up_action:0053eb69(*)
//         0053f1dc     addr       switchD_0053eb69::caseD_0
//         0053f1e0     addr       switchD_0053eb69::caseD_4
//         0053f1e4     addr       switchD_0053eb69::caseD_5
//         0053f1e8     addr       switchD_0053eb69::caseD_0
//         0053f1ec     addr       switchD_0053eb69::caseD_7
//         0053f1f0     addr       switchD_0053eb69::caseD_8
//         0053f1f4     addr       switchD_0053eb69::caseD_e
//         0053f1f8     addr       switchD_0053eb69::caseD_1
//         0053f1fc     addr       switchD_0053eb69::caseD_10
//         0053f200     addr       switchD_0053eb69::caseD_14
//         0053f204     addr       switchD_0053eb69::caseD_1
//                              Symbol Ref: No symbol: NONAME
//                               switchD_0053eb69::switchdataD_0053f208                       XREF[1]:     mouse_left_up_action:0053eb63(*)
//         0053f208     db         0h
//         0053f209     db         Ah
//         0053f20a     db         Ah
//         0053f20b     db         Ah
//         0053f20c     db         1h
//         0053f20d     db         2h
//         0053f20e     db         3h
//         0053f20f     db         4h
//         0053f210     db         5h
//         0053f211     db         Ah
//         0053f212     db         Ah
//         0053f213     db         Ah
//         0053f214     db         Ah
//         0053f215     db         Ah
//         0053f216     db         6h
//         0053f217     db         7h
//         0053f218     db         8h
//         0053f219     db         Ah
//         0053f21a     db         Ah
//         0053f21b     db         Ah
//         0053f21c     db         9h
//         0053f21d     ??         90h
//         0053f21e     ??         90h
//         0053f21f     ??         90h
    return 0;
}

long RGE_Main_View::mouse_right_down_action(long param_1, long param_2, int param_3, int param_4) {
    /* TODO: Stub */
//                              long __thiscall mouse_right_down_action(RGE_Main_View * this, long p
//              long              EAX:4          <RETURN>
//              RGE_Main_View *   ECX:4 (auto)   this
//              long              Stack[0x4]:4   param_1
//              long              Stack[0x8]:4   param_2
//              int               Stack[0xc]:4   param_3
//              int               Stack[0x10]:4  param_4
//                               ?mouse_right_down_action@RGE_Main_View@@UAEJJJHH@Z           XREF[2]:     00572b40(*), 00577888(*)
//                               RGE_Main_View::mouse_right_down_action
//                              vw_main.cpp:1082 (3)
//         0053f220     PUSH       ESI
//         0053f221     MOV        ESI,this
//                              vw_main.cpp:1083 (54)
//         0053f223     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0053f229     CALL       RGE_Base_Game::get_paused                        int get_paused(RGE_Base_Game * this)
//         0053f22e     TEST       EAX,EAX
//         0053f230     JNZ        LAB_0053f2e3
//         0053f236     MOV        EAX,[rge_base_game]                              = 00000000
//         0053f23b     MOV        EAX,dword ptr [EAX + 0x1b0]
//         0053f241     CMP        EAX,0x4
//         0053f244     JZ         LAB_0053f259
//         0053f246     CMP        EAX,0x6
//         0053f249     JZ         LAB_0053f259
//         0053f24b     CMP        EAX,0x7
//         0053f24e     JZ         LAB_0053f259
//         0053f250     CMP        EAX,0x5
//         0053f253     JNZ        LAB_0053f2e3
//                               LAB_0053f259                                                 XREF[3]:     0053f244(j), 0053f249(j),
//                                                                                                         0053f24e(j)
//                              vw_main.cpp:1086 (11)
//         0053f259     PUSH       0x1
//         0053f25b     PUSH       0x24
//         0053f25d     PUSH       0x4c
//         0053f25f     CALL       color_log                                        void color_log(uchar param_1, uchar param_2,
//                              vw_main.cpp:1088 (17)
//         0053f264     MOV        EAX,[rge_base_game]                              = 00000000
//         0053f269     ADD        ESP,0xc
//         0053f26c     CMP        dword ptr [EAX + 0x1b4],0x13
//         0053f273     JZ         LAB_0053f27e
//                              vw_main.cpp:1104 (7)
//         0053f275     MOV        this,ESI
//         0053f277     CALL       TPanel::capture_mouse                            int capture_mouse(TPanel * this)
//                              vw_main.cpp:1105 (2)
//         0053f27c     JMP        LAB_0053f2cc
//                               LAB_0053f27e                                                 XREF[1]:     0053f273(j)
//                              vw_main.cpp:1092 (16)
//         0053f27e     MOV        this,dword ptr [ESI + 0x100]
//         0053f284     MOV        EDX,dword ptr [ECX + this->_padding_]
//         0053f28a     TEST       EDX,EDX
//         0053f28c     JZ         LAB_0053f2a1
//                              vw_main.cpp:1094 (5)
//         0053f28e     CALL       RGE_Player::unselect_object                      void unselect_object(RGE_Player * this)
//                              vw_main.cpp:1095 (14)
//         0053f293     MOV        EDX,dword ptr [ESI]
//         0053f295     PUSH       0x1
//         0053f297     MOV        this,ESI
//         0053f299     CALL       dword ptr [EDX + 0x20]
//         0053f29c     MOV        EAX,[rge_base_game]                              = 00000000
//                               LAB_0053f2a1                                                 XREF[1]:     0053f28c(j)
//                              vw_main.cpp:1099 (11)
//         0053f2a1     MOV        EDX,dword ptr [EAX]
//         0053f2a3     PUSH       0x1
//         0053f2a5     PUSH       0x13
//         0053f2a7     MOV        this,EAX
//         0053f2a9     CALL       dword ptr [EDX + 0x10]
//                              vw_main.cpp:1100 (32)
//         0053f2ac     MOV        this,dword ptr [ESP + 0x14]
//         0053f2b0     MOV        EDX,dword ptr [ESP + 0x10]
//         0053f2b4     MOV        EAX,dword ptr [ESI]
//         0053f2b6     PUSH       this
//         0053f2b7     MOV        this,dword ptr [ESP + 0x10]
//         0053f2bb     PUSH       EDX
//         0053f2bc     MOV        EDX,dword ptr [ESP + 0x10]
//         0053f2c0     PUSH       this
//         0053f2c1     PUSH       EDX
//         0053f2c2     PUSH       0x9
//         0053f2c4     MOV        this,ESI
//         0053f2c6     CALL       dword ptr [EAX + 0xe8]
//                               LAB_0053f2cc                                                 XREF[1]:     0053f27c(j)
//                              vw_main.cpp:1108 (14)
//         0053f2cc     PUSH       0x1
//         0053f2ce     PUSH       0x5f
//         0053f2d0     PUSH       0x4c
//         0053f2d2     CALL       color_log                                        void color_log(uchar param_1, uchar param_2,
//         0053f2d7     ADD        ESP,0xc
//                              vw_main.cpp:1110 (5)
//         0053f2da     MOV        EAX,0x1
//                              vw_main.cpp:1111 (4)
//         0053f2df     POP        ESI
//         0053f2e0     RET        0x10
//                               LAB_0053f2e3                                                 XREF[2]:     0053f230(j), 0053f253(j)
//                              vw_main.cpp:1084 (2)
//         0053f2e3     XOR        EAX,EAX
//                              vw_main.cpp:1111 (4)
//         0053f2e5     POP        ESI
//         0053f2e6     RET        0x10
//         0053f2e9     ??         90h
//         0053f2ea     NOP
//         0053f2eb     NOP
//         0053f2ec     NOP
//         0053f2ed     NOP
//         0053f2ee     NOP
//         0053f2ef     NOP
    return 0;
}

long RGE_Main_View::mouse_right_move_action(long param_1, long param_2, int param_3, int param_4) {
    /* TODO: Stub */
//                              long __thiscall mouse_right_move_action(RGE_Main_View * this, long p
//              long              EAX:4          <RETURN>
//              RGE_Main_View *   ECX:4 (auto)   this
//              long              Stack[0x4]:4   param_1                   XREF[1]:     0053f352(R)
//              long              Stack[0x8]:4   param_2                   XREF[1]:     0053f34e(R)
//              int               Stack[0xc]:4   param_3                   XREF[1]:     0053f387(R)
//              int               Stack[0x10]:4  param_4                   XREF[1]:     0053f383(R)
//                               ?mouse_right_move_action@RGE_Main_View@@UAEJJJHH@Z           XREF[2]:     00572b48(*), 00577890(*)
//                               RGE_Main_View::mouse_right_move_action
//                              vw_main.cpp:1117 (3)
//         0053f2f0     PUSH       ESI
//         0053f2f1     MOV        ESI,this
//                              vw_main.cpp:1118 (31)
//         0053f2f3     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0053f2f9     PUSH       EDI
//         0053f2fa     MOV        EAX,dword ptr [ECX + this->_padding_]
//         0053f300     CMP        EAX,0x4
//         0053f303     JZ         LAB_0053f318
//         0053f305     CMP        EAX,0x6
//         0053f308     JZ         LAB_0053f318
//         0053f30a     CMP        EAX,0x7
//         0053f30d     JZ         LAB_0053f318
//         0053f30f     CMP        EAX,0x5
//                              vw_main.cpp:1119 (6)
//         0053f312     JNZ        LAB_0053f3c3
//                               LAB_0053f318                                                 XREF[3]:     0053f303(j), 0053f308(j),
//                                                                                                         0053f30d(j)
//                              vw_main.cpp:1121 (7)
//         0053f318     CALL       RGE_Base_Game::get_paused                        int get_paused(RGE_Base_Game * this)
//         0053f31d     TEST       EAX,EAX
//                              vw_main.cpp:1123 (12)
//         0053f31f     MOV        AL,byte ptr [ESI + 0x168]
//         0053f325     JZ         LAB_0053f34a
//         0053f327     TEST       AL,AL
//         0053f329     JZ         LAB_0053f33c
//                              vw_main.cpp:1124 (10)
//         0053f32b     MOV        EAX,dword ptr [ESI]
//         0053f32d     MOV        this,ESI
//         0053f32f     CALL       dword ptr [EAX + 0xf0]
//                              vw_main.cpp:1150 (2)
//         0053f335     XOR        EAX,EAX
//                              vw_main.cpp:1151 (5)
//         0053f337     POP        EDI
//         0053f338     POP        ESI
//         0053f339     RET        0x10
//                               LAB_0053f33c                                                 XREF[1]:     0053f329(j)
//                              vw_main.cpp:1126 (7)
//         0053f33c     MOV        this,ESI
//         0053f33e     CALL       TPanel::release_mouse                            void release_mouse(TPanel * this)
//                              vw_main.cpp:1150 (2)
//         0053f343     XOR        EAX,EAX
//                              vw_main.cpp:1151 (5)
//         0053f345     POP        EDI
//         0053f346     POP        ESI
//         0053f347     RET        0x10
//                               LAB_0053f34a                                                 XREF[1]:     0053f325(j)
//                              vw_main.cpp:1130 (4)
//         0053f34a     TEST       AL,AL
//         0053f34c     JZ         LAB_0053f36c
//                              vw_main.cpp:1132 (20)
//         0053f34e     MOV        EAX,dword ptr [ESP + param_2]
//         0053f352     MOV        this,dword ptr [ESP + param_1]
//         0053f356     MOV        EDX,dword ptr [ESI]
//         0053f358     PUSH       EAX
//         0053f359     PUSH       this
//         0053f35a     MOV        this,ESI
//         0053f35c     CALL       dword ptr [EDX + 0xec]
//                              vw_main.cpp:1133 (5)
//         0053f362     MOV        EAX,0x1
//                              vw_main.cpp:1151 (5)
//         0053f367     POP        EDI
//         0053f368     POP        ESI
//         0053f369     RET        0x10
//                               LAB_0053f36c                                                 XREF[1]:     0053f34c(j)
//                              vw_main.cpp:1141 (16)
//         0053f36c     MOV        EDX,dword ptr [ESI + 0x100]
//         0053f372     CMP        word ptr [EDX + 0x19c],0x0
//         0053f37a     JNZ        LAB_0053f3c3
//                              vw_main.cpp:1144 (7)
//         0053f37c     MOV        this,ESI
//         0053f37e     CALL       TPanel::release_mouse                            void release_mouse(TPanel * this)
//                              vw_main.cpp:1145 (36)
//         0053f383     MOV        EAX,dword ptr [ESP + param_4]
//         0053f387     MOV        this,dword ptr [ESP + param_3]
//         0053f38b     MOV        EDX,dword ptr [ESI + 0xc8]
//         0053f391     MOV        EDI,dword ptr [ESI]
//         0053f393     PUSH       EAX
//         0053f394     MOV        EAX,dword ptr [ESI + 0xc4]
//         0053f39a     PUSH       this
//         0053f39b     PUSH       EDX
//         0053f39c     PUSH       EAX
//         0053f39d     PUSH       0x1
//         0053f39f     MOV        this,ESI
//         0053f3a1     CALL       dword ptr [EDI + 0xe8]
//                              vw_main.cpp:1146 (18)
//         0053f3a7     MOV        this,dword ptr [ESP + 0x10]
//         0053f3ab     MOV        EDX,dword ptr [ESP + 0xc]
//         0053f3af     PUSH       this
//         0053f3b0     PUSH       EDX=>DAT_fffffff8
//         0053f3b1     MOV        this,ESI
//         0053f3b3     CALL       dword ptr [EDI + 0xec]
//                              vw_main.cpp:1147 (5)
//         0053f3b9     MOV        EAX,0x1
//                              vw_main.cpp:1151 (12)
//         0053f3be     POP        EDI
//         0053f3bf     POP        ESI
//         0053f3c0     RET        0x10
//                               LAB_0053f3c3                                                 XREF[2]:     0053f312(j), 0053f37a(j)
//         0053f3c3     POP        EDI
//         0053f3c4     XOR        EAX,EAX
//         0053f3c6     POP        ESI
//         0053f3c7     RET        0x10
//         0053f3ca     ??         90h
//         0053f3cb     NOP
//         0053f3cc     NOP
//         0053f3cd     NOP
//         0053f3ce     NOP
//         0053f3cf     NOP
    return 0;
}

long RGE_Main_View::mouse_right_up_action(long param_1, long param_2, int param_3, int param_4) {
    /* TODO: Stub */
//                              long __thiscall mouse_right_up_action(RGE_Main_View * this, long par
//              long              EAX:4          <RETURN>
//              RGE_Main_View *   ECX:4 (auto)   this
//              long              Stack[0x4]:4   param_1                   XREF[3]:     0053f456(R), 0053f4f9(R), 0053f555(R)
//              long              Stack[0x8]:4   param_2                   XREF[3]:     0053f451(R), 0053f4f5(R), 0053f551(R)
//              int               Stack[0xc]:4   param_3
//              int               Stack[0x10]:4  param_4                   XREF[2]:     0053f4ed(R), 0053f51e(*)
//              RGE_Pick_Info     Stack[-0x18]   pick_info                 XREF[2,6]:   0053f524(*), 0053f537(R), 0053f447(*), 0053f55b(*),
//                                                                                     0053f577(*), 0053f593(R), 0053f583(R), 0053f470(R)
//              RGE_Static_Obj    Stack[-0x1c]:4 list
//                               ?mouse_right_up_action@RGE_Main_View@@UAEJJJHH@Z             XREF[2]:     mouse_right_up_action:0052daf0(c),
//                               RGE_Main_View::mouse_right_up_action                                      00577894(*)
//                              vw_main.cpp:1157 (39)
//         0053f3d0     MOV        EAX,[rge_base_game]                              = 00000000
//         0053f3d5     SUB        ESP,0x18
//         0053f3d8     MOV        EAX,dword ptr [EAX + 0x1b0]
//         0053f3de     PUSH       EBX
//         0053f3df     PUSH       ESI
//         0053f3e0     CMP        EAX,0x4
//         0053f3e3     PUSH       EDI
//         0053f3e4     MOV        ESI,this
//         0053f3e6     JZ         LAB_0053f402
//         0053f3e8     CMP        EAX,0x6
//         0053f3eb     JZ         LAB_0053f402
//         0053f3ed     CMP        EAX,0x7
//         0053f3f0     JZ         LAB_0053f402
//         0053f3f2     CMP        EAX,0x5
//         0053f3f5     JZ         LAB_0053f402
//                              vw_main.cpp:1164 (2)
//         0053f3f7     XOR        EAX,EAX
//                              vw_main.cpp:1274 (9)
//         0053f3f9     POP        EDI
//         0053f3fa     POP        ESI
//         0053f3fb     POP        EBX
//         0053f3fc     ADD        ESP,0x18
//         0053f3ff     RET        0x10
//                               LAB_0053f402                                                 XREF[4]:     0053f3e6(j), 0053f3eb(j),
//                                                                                                         0053f3f0(j), 0053f3f5(j)
//                              vw_main.cpp:1166 (11)
//         0053f402     PUSH       0x1
//         0053f404     PUSH       0x32
//         0053f406     PUSH       0x4c
//         0053f408     CALL       color_log                                        void color_log(uchar param_1, uchar param_2,
//                              vw_main.cpp:1168 (13)
//         0053f40d     MOV        AL,byte ptr [ESI + 0x168]
//         0053f413     ADD        ESP,0xc
//         0053f416     TEST       AL,AL
//         0053f418     JZ         LAB_0053f429
//                              vw_main.cpp:1170 (10)
//         0053f41a     MOV        EDX,dword ptr [ESI]
//         0053f41c     MOV        this,ESI
//         0053f41e     CALL       dword ptr [EDX + 0xf0]
//                              vw_main.cpp:1172 (5)
//         0053f424     JMP        LAB_0053f63b
//                               LAB_0053f429                                                 XREF[1]:     0053f418(j)
//                              vw_main.cpp:1175 (7)
//         0053f429     MOV        this,ESI
//         0053f42b     CALL       TPanel::release_mouse                            void release_mouse(TPanel * this)
//                              vw_main.cpp:1178 (15)
//         0053f430     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0053f436     CMP        dword ptr [ECX + this->_padding_],0x14
//         0053f43d     JNZ        LAB_0053f480
//                              vw_main.cpp:1180 (41)
//         0053f43f     MOV        EAX,dword ptr [ESI + 0x100]
//         0053f445     PUSH       0x1
//         0053f447     LEA        EDX=>pick_info.y,[ESP + 0x14]
//         0053f44b     MOV        this,dword ptr [EAX + 0x130]
//         0053f451     MOV        EAX,dword ptr [ESP + param_2]
//         0053f455     PUSH       this
//         0053f456     MOV        this,dword ptr [ESP + param_1]
//         0053f45a     PUSH       EDX
//         0053f45b     PUSH       EAX
//         0053f45c     PUSH       this
//         0053f45d     PUSH       0x2
//         0053f45f     PUSH       0x29
//         0053f461     MOV        this,ESI
//         0053f463     CALL       RGE_Main_View::pick1                             uchar pick1(RGE_Main_View * this, uchar param
//                              vw_main.cpp:1181 (8)
//         0053f468     CMP        AL,0x34
//         0053f46a     JNZ        LAB_0053f63b
//                              vw_main.cpp:1182 (11)
//         0053f470     MOV        this,dword ptr [ESP + pick_info.tile]
//         0053f474     PUSH       -0x1
//         0053f476     MOV        EDX,dword ptr [this->_padding_]
//         0053f478     CALL       dword ptr [EDX + 0x78]
//                              vw_main.cpp:1184 (5)
//         0053f47b     JMP        LAB_0053f63b
//                               LAB_0053f480                                                 XREF[1]:     0053f43d(j)
//                              vw_main.cpp:1187 (7)
//         0053f480     CALL       RGE_Base_Game::get_paused                        int get_paused(RGE_Base_Game * this)
//         0053f485     TEST       EAX,EAX
//                              vw_main.cpp:1190 (2)
//         0053f487     JNZ        LAB_0053f497
//                              vw_main.cpp:1194 (14)
//         0053f489     MOV        AL,byte ptr [ESI + 0xec]
//         0053f48f     CMP        AL,0x1
//         0053f491     JZ         LAB_0053f4b0
//         0053f493     CMP        AL,0x2
//         0053f495     JZ         LAB_0053f4b0
//                               LAB_0053f497                                                 XREF[1]:     0053f487(j)
//                              vw_main.cpp:1272 (14)
//         0053f497     PUSH       0x1
//         0053f499     PUSH       0x5f
//         0053f49b     PUSH       0x4c
//         0053f49d     CALL       color_log                                        void color_log(uchar param_1, uchar param_2,
//         0053f4a2     ADD        ESP,0xc
//                              vw_main.cpp:1273 (2)
//         0053f4a5     XOR        EAX,EAX
//                              vw_main.cpp:1274 (9)
//         0053f4a7     POP        EDI
//         0053f4a8     POP        ESI
//         0053f4a9     POP        EBX
//         0053f4aa     ADD        ESP,0x18
//         0053f4ad     RET        0x10
//                               LAB_0053f4b0                                                 XREF[2]:     0053f491(j), 0053f495(j)
//                              vw_main.cpp:1203 (17)
//         0053f4b0     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0053f4b6     MOV        EAX,dword ptr [ECX + this->_padding_]
//         0053f4b9     CMP        word ptr [EAX + 0x8dc],0x2
//                              vw_main.cpp:1205 (30)
//         0053f4c1     MOV        EAX,dword ptr [ECX + this->_padding_]
//         0053f4c7     JNZ        LAB_0053f60d
//         0053f4cd     CMP        EAX,0x5
//         0053f4d0     JZ         LAB_0053f63b
//         0053f4d6     CMP        EAX,0x7
//         0053f4d9     JZ         LAB_0053f63b
//                              vw_main.cpp:1207 (14)
//         0053f4df     MOV        EAX,dword ptr [ECX + this->_padding_]
//         0053f4e5     TEST       EAX,EAX
//         0053f4e7     JNZ        LAB_0053f5df
//                              vw_main.cpp:1209 (8)
//         0053f4ed     MOV        EAX,dword ptr [ESP + param_4]
//         0053f4f1     TEST       EAX,EAX
//         0053f4f3     JNZ        LAB_0053f512
//                              vw_main.cpp:1210 (24)
//         0053f4f5     MOV        EAX,dword ptr [ESP + param_2]
//         0053f4f9     MOV        this,dword ptr [ESP + param_1]
//         0053f4fd     MOV        EDX,dword ptr [ESI]
//         0053f4ff     PUSH       -0x1
//         0053f501     PUSH       0x1
//         0053f503     PUSH       EAX
//         0053f504     PUSH       this
//         0053f505     MOV        this,ESI
//         0053f507     CALL       dword ptr [EDX + 0x100]
//                              vw_main.cpp:1211 (5)
//         0053f50d     JMP        LAB_0053f63b
//                               LAB_0053f512                                                 XREF[1]:     0053f4f3(j)
//                              vw_main.cpp:1218 (37)
//         0053f512     MOV        this,dword ptr [ESI + 0x100]
//         0053f518     PUSH       -0x1
//         0053f51a     PUSH       -0x1
//         0053f51c     PUSH       -0x1
//         0053f51e     LEA        EDX=>param_4,[ESP + 0x40]
//         0053f522     PUSH       -0x1
//         0053f524     LEA        EAX=>pick_info,[ESP + 0x1c]
//         0053f528     PUSH       EDX
//         0053f529     PUSH       EAX
//         0053f52a     CALL       RGE_Player::get_selected_objects_to_command      uchar get_selected_objects_to_command(RGE_Pla
//         0053f52f     TEST       AL,AL
//         0053f531     JZ         LAB_0053f63b
//                              vw_main.cpp:1220 (10)
//         0053f537     MOV        this,dword ptr [ESP + pick_info.x]
//         0053f53b     PUSH       this
//         0053f53c     CALL       free                                             undefined free()
//                              vw_main.cpp:1226 (16)
//         0053f541     MOV        EAX,[allow_user_commands]                        = 1h
//         0053f546     ADD        ESP,0x4
//         0053f549     TEST       EAX,EAX
//         0053f54b     JZ         LAB_0053f63b
//                              vw_main.cpp:1228 (38)
//         0053f551     MOV        EDI,dword ptr [ESP + param_2]
//         0053f555     MOV        EBX,dword ptr [ESP + param_1]
//         0053f559     PUSH       0x1
//         0053f55b     LEA        EDX=>pick_info.y,[ESP + 0x14]
//         0053f55f     PUSH       0x0
//         0053f561     PUSH       EDX
//         0053f562     PUSH       EDI
//         0053f563     PUSH       EBX
//         0053f564     PUSH       0x0
//         0053f566     PUSH       0x28
//         0053f568     MOV        this,ESI
//         0053f56a     CALL       RGE_Main_View::pick1                             uchar pick1(RGE_Main_View * this, uchar param
//         0053f56f     CMP        AL,0x33
//         0053f571     JNZ        LAB_0053f63b
//                              vw_main.cpp:1230 (12)
//         0053f577     LEA        EAX=>pick_info.y,[ESP + 0x10]
//         0053f57b     MOV        this,ESI
//         0053f57d     PUSH       EAX
//         0053f57e     CALL       RGE_Main_View::fixup_pick_info                   void fixup_pick_info(RGE_Main_View * this, RG
//                              vw_main.cpp:1231 (29)
//         0053f583     MOV        EAX,dword ptr [ESP + pick_info.scr_x]
//         0053f587     MOV        this,dword ptr [ESI + 0x100]
//         0053f58d     PUSH       0x3f800000
//         0053f592     PUSH       EAX
//         0053f593     MOV        EAX,dword ptr [ESP + pick_info.y]
//         0053f597     MOV        EDX,dword ptr [this->_padding_]
//         0053f599     PUSH       EAX
//         0053f59a     CALL       dword ptr [EDX + 0xd8]
//                              vw_main.cpp:1232 (9)
//         0053f5a0     PUSH       0x2
//         0053f5a2     MOV        this,ESI
//         0053f5a4     CALL       RGE_Main_View::reset_display_object_selection    void reset_display_object_selection(RGE_Main_
//                              vw_main.cpp:1233 (52)
//         0053f5a9     MOV        this,dword ptr [ESI + 0x134]
//         0053f5af     MOV        EAX,[rge_base_game]                              = 00000000
//         0053f5b4     MOV        EDX,dword ptr [ESI + 0x130]
//         0053f5ba     PUSH       0xfa
//         0053f5bf     PUSH       offset DAT_fffffff8
//         0053f5c1     PUSH       0x0=>DAT_fffffff4
//         0053f5c3     PUSH       offset DAT_fffffff0
//         0053f5c5     ADD        this,EDI
//         0053f5c7     PUSH       0x0
//         0053f5c9     PUSH       this
//         0053f5ca     MOV        this,dword ptr [EAX + 0x5c]
//         0053f5cd     ADD        EDX,EBX
//         0053f5cf     PUSH       EDX
//         0053f5d0     PUSH       0x0
//         0053f5d2     MOV        EDX,dword ptr [ECX + this->_padding_]
//         0053f5d5     MOV        this,ESI
//         0053f5d7     PUSH       EDX
//         0053f5d8     CALL       RGE_View::add_overlay_sprite                     void add_overlay_sprite(RGE_View * this, TSha
//                              vw_main.cpp:1239 (2)
//         0053f5dd     JMP        LAB_0053f632
//                               LAB_0053f5df                                                 XREF[1]:     0053f4e7(j)
//                              vw_main.cpp:1241 (5)
//         0053f5df     CMP        EAX,0x15
//         0053f5e2     JNZ        LAB_0053f602
//                              vw_main.cpp:1243 (15)
//         0053f5e4     PUSH       -0x1
//         0053f5e6     PUSH       -0x1
//         0053f5e8     PUSH       -0x1
//         0053f5ea     PUSH       -0x1
//         0053f5ec     MOV        this,ESI
//         0053f5ee     CALL       RGE_View::set_selection_area                     void set_selection_area(RGE_View * this, long
//                              vw_main.cpp:1244 (15)
//         0053f5f3     MOV        EDX,dword ptr [ESI]
//         0053f5f5     PUSH       0x1
//         0053f5f7     MOV        this,ESI
//         0053f5f9     CALL       dword ptr [EDX + 0x20]
//         0053f5fc     MOV        this,dword ptr [rge_base_game]                   = 00000000
//                               LAB_0053f602                                                 XREF[1]:     0053f5e2(j)
//                              vw_main.cpp:1246 (9)
//         0053f602     MOV        EAX,dword ptr [this->_padding_]
//         0053f604     PUSH       0x0
//         0053f606     PUSH       0x0=>DAT_fffffff8
//         0053f608     CALL       dword ptr [EAX + 0x10]
//                              vw_main.cpp:1251 (2)
//         0053f60b     JMP        LAB_0053f63b
//                               LAB_0053f60d                                                 XREF[1]:     0053f4c7(j)
//                              vw_main.cpp:1258 (5)
//         0053f60d     CMP        EAX,0x7
//         0053f610     JZ         LAB_0053f63b
//                              vw_main.cpp:1260 (10)
//         0053f612     MOV        EAX,dword ptr [ECX + this->_padding_]
//         0053f618     TEST       EAX,EAX
//         0053f61a     JZ         LAB_0053f627
//                              vw_main.cpp:1261 (9)
//         0053f61c     MOV        EDX,dword ptr [this->_padding_]
//         0053f61e     PUSH       0x0
//         0053f620     PUSH       0x0
//         0053f622     CALL       dword ptr [EDX + 0x10]
//                              vw_main.cpp:1262 (2)
//         0053f625     JMP        LAB_0053f63b
//                               LAB_0053f627                                                 XREF[1]:     0053f61a(j)
//                              vw_main.cpp:1264 (11)
//         0053f627     MOV        this,dword ptr [ESI + 0x100]
//         0053f62d     CALL       RGE_Player::unselect_object                      void unselect_object(RGE_Player * this)
//                               LAB_0053f632                                                 XREF[1]:     0053f5dd(j)
//                              vw_main.cpp:1265 (9)
//         0053f632     MOV        EAX,dword ptr [ESI]
//         0053f634     PUSH       0x1
//         0053f636     MOV        this,ESI
//         0053f638     CALL       dword ptr [EAX + 0x20]
//                               LAB_0053f63b                                                 XREF[12]:    0053f424(j), 0053f46a(j),
//                                                                                                         0053f47b(j), 0053f4d0(j),
//                                                                                                         0053f4d9(j), 0053f50d(j),
//                                                                                                         0053f531(j), 0053f54b(j),
//                                                                                                         0053f571(j), 0053f60b(j),
//                                                                                                         0053f610(j), 0053f625(j)
//                              vw_main.cpp:1268 (14)
//         0053f63b     PUSH       0x1
//         0053f63d     PUSH       offset DAT_fffffff8
//         0053f63f     PUSH       offset DAT_fffffff4
//         0053f641     CALL       color_log                                        void color_log(uchar param_1, uchar param_2,
//         0053f646     ADD        ESP,0xc
//                              vw_main.cpp:1269 (5)
//         0053f649     MOV        EAX,0x1
//                              vw_main.cpp:1274 (9)
//         0053f64e     POP        EDI
//         0053f64f     POP        ESI
//         0053f650     POP        EBX
//         0053f651     ADD        ESP,0x18
//         0053f654     RET        0x10
//         0053f657     ??         90h
//         0053f658     NOP
//         0053f659     NOP
//         0053f65a     NOP
//         0053f65b     NOP
//         0053f65c     NOP
//         0053f65d     NOP
//         0053f65e     NOP
//         0053f65f     NOP
    return 0;
}

int RGE_Main_View::start_scroll_view(uchar param_1, long param_2, long param_3, int param_4, int param_5) {
    /* TODO: Stub */
//                              int __thiscall start_scroll_view(RGE_Main_View * this, uchar param_1
//              int               EAX:4          <RETURN>
//              RGE_Main_View *   ECX:4 (auto)   this
//              uchar             Stack[0x4]:1   param_1                   XREF[1]:     0053f675(R)
//              long              Stack[0x8]:4   param_2                   XREF[1]:     0053f670(R)
//              long              Stack[0xc]:4   param_3                   XREF[1]:     0053f664(R)
//              int               Stack[0x10]:4  param_4                   XREF[1]:     0053f66b(R)
//              int               Stack[0x14]:4  param_5                   XREF[1]:     0053f660(R)
//                               ?start_scroll_view@RGE_Main_View@@UAEHEJJHH@Z                XREF[2]:     00572b90(*), 005778d8(*)
//                               RGE_Main_View::start_scroll_view
//                              vw_main.cpp:1280 (39)
//         0053f660     MOV        EAX,dword ptr [ESP + param_5]
//         0053f664     MOV        EDX,dword ptr [ESP + param_3]
//         0053f668     PUSH       ESI
//         0053f669     MOV        ESI,this
//         0053f66b     MOV        this,dword ptr [ESP + param_4]
//         0053f66f     PUSH       EAX
//         0053f670     MOV        EAX,dword ptr [ESP + param_2]
//         0053f674     PUSH       this
//         0053f675     MOV        this,dword ptr [ESP + param_1]
//         0053f679     PUSH       EDX
//         0053f67a     PUSH       EAX
//         0053f67b     PUSH       this
//         0053f67c     MOV        this,ESI
//         0053f67e     CALL       RGE_View::start_scroll_view                      int start_scroll_view(RGE_View * this, uchar
//         0053f683     TEST       EAX,EAX
//         0053f685     JZ         LAB_0053f6a1
//                              vw_main.cpp:1283 (10)
//         0053f687     MOV        this,dword ptr [ESI + 0x360]
//         0053f68d     TEST       this,this
//         0053f68f     JZ         LAB_0053f698
//                              vw_main.cpp:1284 (7)
//         0053f691     MOV        EDX,dword ptr [this->_padding_]
//         0053f693     PUSH       0x1
//         0053f695     CALL       dword ptr [EDX + 0x20]
//                               LAB_0053f698                                                 XREF[1]:     0053f68f(j)
//                              vw_main.cpp:1285 (5)
//         0053f698     MOV        EAX,0x1
//                              vw_main.cpp:1289 (4)
//         0053f69d     POP        ESI
//         0053f69e     RET        0x14
//                               LAB_0053f6a1                                                 XREF[1]:     0053f685(j)
//                              vw_main.cpp:1288 (2)
//         0053f6a1     XOR        EAX,EAX
//                              vw_main.cpp:1289 (4)
//         0053f6a3     POP        ESI
//         0053f6a4     RET        0x14
//         0053f6a7     ??         90h
//         0053f6a8     NOP
//         0053f6a9     NOP
//         0053f6aa     NOP
//         0053f6ab     NOP
//         0053f6ac     NOP
//         0053f6ad     NOP
//         0053f6ae     NOP
//         0053f6af     NOP
    return 0;
}

int RGE_Main_View::handle_scroll_view(long param_1, long param_2) {
    /* TODO: Stub */
//                              int __thiscall handle_scroll_view(RGE_Main_View * this, long param_1
//              int               EAX:4          <RETURN>
//              RGE_Main_View *   ECX:4 (auto)   this
//              long              Stack[0x4]:4   param_1                   XREF[1]:     0053f6b8(R)
//              long              Stack[0x8]:4   param_2                   XREF[1]:     0053f6b0(R)
//                               ?handle_scroll_view@RGE_Main_View@@UAEHJJ@Z                  XREF[2]:     00572b94(*), 005778dc(*)
//                               RGE_Main_View::handle_scroll_view
//                              vw_main.cpp:1295 (24)
//         0053f6b0     MOV        EAX,dword ptr [ESP + param_2]
//         0053f6b4     PUSH       ESI
//         0053f6b5     MOV        ESI,this
//         0053f6b7     PUSH       EAX
//         0053f6b8     MOV        this,dword ptr [ESP + param_1]
//         0053f6bc     PUSH       this
//         0053f6bd     MOV        this,ESI
//         0053f6bf     CALL       RGE_View::handle_scroll_view                     int handle_scroll_view(RGE_View * this, long
//         0053f6c4     TEST       EAX,EAX
//         0053f6c6     JZ         LAB_0053f6e2
//                              vw_main.cpp:1298 (10)
//         0053f6c8     MOV        this,dword ptr [ESI + 0x360]
//         0053f6ce     TEST       this,this
//         0053f6d0     JZ         LAB_0053f6d9
//                              vw_main.cpp:1299 (7)
//         0053f6d2     MOV        EDX,dword ptr [this->_padding_]
//         0053f6d4     PUSH       0x1
//         0053f6d6     CALL       dword ptr [EDX + 0x20]
//                               LAB_0053f6d9                                                 XREF[1]:     0053f6d0(j)
//                              vw_main.cpp:1300 (5)
//         0053f6d9     MOV        EAX,0x1
//                              vw_main.cpp:1304 (4)
//         0053f6de     POP        ESI
//         0053f6df     RET        0x8
//                               LAB_0053f6e2                                                 XREF[1]:     0053f6c6(j)
//                              vw_main.cpp:1303 (2)
//         0053f6e2     XOR        EAX,EAX
//                              vw_main.cpp:1304 (4)
//         0053f6e4     POP        ESI
//         0053f6e5     RET        0x8
//         0053f6e8     ??         90h
//         0053f6e9     NOP
//         0053f6ea     NOP
//         0053f6eb     NOP
//         0053f6ec     NOP
//         0053f6ed     NOP
//         0053f6ee     NOP
//         0053f6ef     NOP
    return 0;
}

void RGE_Main_View::draw() {
    /* TODO: Stub */
//                              void __thiscall draw(RGE_Main_View * this)
//              void              <VOID>         <RETURN>
//              RGE_Main_View *   ECX:4 (auto)   this
//                               ?draw@RGE_Main_View@@UAEXXZ                                  XREF[2]:     00572ad8(*), 00577820(*)
//                               RGE_Main_View::draw
//                              vw_main.cpp:1310 (4)
//         0053f6f0     PUSH       EBX
//         0053f6f1     PUSH       EBP
//         0053f6f2     PUSH       ESI
//         0053f6f3     PUSH       EDI
//                              vw_main.cpp:1314 (17)
//         0053f6f4     PUSH       0x522
//         0053f6f9     MOV        ESI,this
//         0053f6fb     PUSH       s_C:\msdev\work\age1_x1\vw_main.cp               = "C:\\msdev\\work\\age1_x1\\vw_main.cpp"
//         0053f700     CALL       debug_timeGetTime                                ulong debug_timeGetTime(char * param_1, int p
//                              vw_main.cpp:1316 (20)
//         0053f705     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0053f70b     ADD        ESP,0x8
//         0053f70e     MOV        EBX,EAX
//         0053f710     PUSH       0xb
//         0053f712     CALL       RGE_Base_Game::get_accum_time                    ulong get_accum_time(RGE_Base_Game * this, in
//         0053f717     MOV        EBP,EAX
//                              vw_main.cpp:1318 (20)
//         0053f719     MOV        EAX,dword ptr [ESI + 0xfc]
//         0053f71f     TEST       EAX,EAX
//         0053f721     JZ         LAB_0053f77e
//         0053f723     MOV        EAX,dword ptr [ESI + 0x100]
//         0053f729     TEST       EAX,EAX
//         0053f72b     JZ         LAB_0053f77e
//                              vw_main.cpp:1326 (9)
//         0053f72d     MOV        EAX,[do_draw_log]
//         0053f732     TEST       EAX,EAX
//         0053f734     JZ         LAB_0053f743
//                              vw_main.cpp:1327 (13)
//         0053f736     PUSH       s_<vs>                                           = "<vs>"
//         0053f73b     CALL       write_draw_log2                                  void write_draw_log2(char * param_1)
//         0053f740     ADD        ESP,0x4
//                               LAB_0053f743                                                 XREF[1]:     0053f734(j)
//                              vw_main.cpp:1330 (14)
//         0053f743     PUSH       0x1
//         0053f745     PUSH       0x4c
//         0053f747     PUSH       0x4c
//         0053f749     CALL       color_log                                        void color_log(uchar param_1, uchar param_2,
//         0053f74e     ADD        ESP,0xc
//                              vw_main.cpp:1333 (7)
//         0053f751     MOV        this,ESI
//         0053f753     CALL       RGE_View::draw                                   void draw(RGE_View * this)
//                              vw_main.cpp:1337 (11)
//         0053f758     PUSH       0x1
//         0053f75a     PUSH       0x5f
//         0053f75c     PUSH       0x4c
//         0053f75e     CALL       color_log                                        void color_log(uchar param_1, uchar param_2,
//                              vw_main.cpp:1340 (12)
//         0053f763     MOV        EAX,[do_draw_log]
//         0053f768     ADD        ESP,0xc
//         0053f76b     TEST       EAX,EAX
//         0053f76d     JZ         LAB_0053f7a1
//                              vw_main.cpp:1341 (15)
//         0053f76f     PUSH       s_<vf>_                                          = "<vf>\n"
//         0053f774     CALL       write_draw_log2                                  void write_draw_log2(char * param_1)
//         0053f779     ADD        ESP,0x4
//         0053f77c     JMP        LAB_0053f7a1
//                               LAB_0053f77e                                                 XREF[2]:     0053f721(j), 0053f72b(j)
//                              vw_main.cpp:1320 (9)
//         0053f77e     MOV        EDI,dword ptr [ESI]
//         0053f780     PUSH       0x0
//         0053f782     MOV        this,ESI
//         0053f784     CALL       dword ptr [EDI + 0x28]
//                              vw_main.cpp:1321 (21)
//         0053f787     XOR        EAX,EAX
//         0053f789     LEA        this,[ESI + 0x24]
//         0053f78c     MOV        AL,byte ptr [ESI + 0xef]
//         0053f792     PUSH       EAX
//         0053f793     PUSH       this=>DAT_fffffff8
//         0053f794     MOV        this,dword ptr [ESI + 0x20]
//         0053f797     CALL       TDrawArea::Clear                                 void Clear(TDrawArea * this, tagRECT * param_
//                              vw_main.cpp:1322 (5)
//         0053f79c     MOV        this,ESI
//         0053f79e     CALL       dword ptr [EDI + 0x2c]
//                               LAB_0053f7a1                                                 XREF[2]:     0053f76d(j), 0053f77c(j)
//                              vw_main.cpp:1344 (15)
//         0053f7a1     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0053f7a7     PUSH       0xb
//         0053f7a9     CALL       RGE_Base_Game::get_accum_time                    ulong get_accum_time(RGE_Base_Game * this, in
//         0053f7ae     MOV        ESI,EAX
//                              vw_main.cpp:1346 (17)
//         0053f7b0     PUSH       0x542
//         0053f7b5     PUSH       s_C:\msdev\work\age1_x1\vw_main.cp               = "C:\\msdev\\work\\age1_x1\\vw_main.cpp"
//         0053f7ba     SUB        ESI,EBP
//         0053f7bc     CALL       debug_timeGetTime                                ulong debug_timeGetTime(char * param_1, int p
//                              vw_main.cpp:1347 (21)
//         0053f7c1     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0053f7c7     SUB        EAX,EBX
//         0053f7c9     ADD        ESP,0x8
//         0053f7cc     SUB        EAX,ESI
//         0053f7ce     PUSH       EAX
//         0053f7cf     PUSH       0x6
//         0053f7d1     CALL       RGE_Base_Game::add_to_timing                     void add_to_timing(RGE_Base_Game * this, int
//                              vw_main.cpp:1348 (11)
//         0053f7d6     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0053f7dc     CALL       RGE_Base_Game::increment_view_update_count       void increment_view_update_count(RGE_Base_Gam
//                              vw_main.cpp:1351 (14)
//         0053f7e1     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0053f7e7     PUSH       ESI
//         0053f7e8     PUSH       0xc
//         0053f7ea     CALL       RGE_Base_Game::add_to_timing                     void add_to_timing(RGE_Base_Game * this, int
//                              vw_main.cpp:1352 (5)
//         0053f7ef     POP        EDI
//         0053f7f0     POP        ESI
//         0053f7f1     POP        EBP
//         0053f7f2     POP        EBX
//         0053f7f3     RET
//         0053f7f4     ??         90h
//         0053f7f5     NOP
//         0053f7f6     NOP
//         0053f7f7     NOP
//         0053f7f8     NOP
//         0053f7f9     NOP
//         0053f7fa     NOP
//         0053f7fb     NOP
//         0053f7fc     NOP
//         0053f7fd     NOP
//         0053f7fe     NOP
//         0053f7ff     NOP
    return;
}

void RGE_Main_View::draw_multi_object_outline() {
    /* TODO: Stub */
//                              void __thiscall draw_multi_object_outline(RGE_Main_View * this)
//              void              <VOID>         <RETURN>
//              RGE_Main_View *   ECX:4 (auto)   this
//                               ?draw_multi_object_outline@RGE_Main_View@@UAEXXZ             XREF[1]:     005778e8(*)
//                               RGE_Main_View::draw_multi_object_outline
//                              vw_main.cpp:1358 (1)
//         0053f800     RET
//         0053f801     ??         90h
//         0053f802     NOP
//         0053f803     NOP
//         0053f804     NOP
//         0053f805     NOP
//         0053f806     NOP
//         0053f807     NOP
//         0053f808     NOP
//         0053f809     NOP
//         0053f80a     NOP
//         0053f80b     NOP
//         0053f80c     NOP
//         0053f80d     NOP
//         0053f80e     NOP
//         0053f80f     NOP
    return;
}

int RGE_Main_View::command_place_object(long param_1, long param_2, int param_3) {
    /* TODO: Stub */
//                              int __thiscall command_place_object(RGE_Main_View * this, long param
//              int               EAX:4          <RETURN>
//              RGE_Main_View *   ECX:4 (auto)   this
//              long              Stack[0x4]:4   param_1                   XREF[1]:     0053f82a(R)
//              long              Stack[0x8]:4   param_2                   XREF[1]:     0053f826(R)
//              int               Stack[0xc]:4   param_3
//              RGE_Pick_Info     Stack[-0x18]   pick_info                 XREF[0,4]:   0053f830(*), 0053f84c(*), 0053f8b7(*), 0053f8b2(*)
//                               ?command_place_object@RGE_Main_View@@UAEHJJH@Z               XREF[2]:     command_place_object:0052d222(c),
//                               RGE_Main_View::command_place_object                                       005778ec(*)
//                              vw_main.cpp:1365 (16)
//         0053f810     MOV        EAX,[allow_user_commands]                        = 1h
//         0053f815     SUB        ESP,0x14
//         0053f818     TEST       EAX,EAX
//         0053f81a     PUSH       EBX
//         0053f81b     PUSH       EBP
//         0053f81c     PUSH       ESI
//         0053f81d     PUSH       EDI
//         0053f81e     MOV        EBP,this
//                              vw_main.cpp:1374 (6)
//         0053f820     JZ         LAB_0053fa04
//                              vw_main.cpp:1376 (30)
//         0053f826     MOV        this,dword ptr [ESP + param_2]
//         0053f82a     MOV        EDX,dword ptr [ESP + param_1]
//         0053f82e     PUSH       0x1
//         0053f830     LEA        EAX=>pick_info.y,[ESP + 0x14]
//         0053f834     PUSH       0x0
//         0053f836     PUSH       EAX
//         0053f837     PUSH       this
//         0053f838     PUSH       EDX
//         0053f839     PUSH       0x0
//         0053f83b     PUSH       0x28
//         0053f83d     MOV        this,EBP
//         0053f83f     CALL       RGE_Main_View::pick1                             uchar pick1(RGE_Main_View * this, uchar param
//                              vw_main.cpp:1377 (8)
//         0053f844     CMP        AL,0x33
//         0053f846     JNZ        LAB_0053fa04
//                              vw_main.cpp:1379 (12)
//         0053f84c     LEA        EAX=>pick_info.y,[ESP + 0x10]
//         0053f850     MOV        this,EBP
//         0053f852     PUSH       EAX
//         0053f853     CALL       RGE_Main_View::fixup_pick_info                   void fixup_pick_info(RGE_Main_View * this, RG
//                              vw_main.cpp:1381 (13)
//         0053f858     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0053f85e     MOVSX      EBX,word ptr [this->_padding_ + 0x3fc]
//                              vw_main.cpp:1382 (27)
//         0053f865     CMP        EBX,-0x1
//         0053f868     JZ         LAB_0053fa04
//         0053f86e     CALL       RGE_Base_Game::get_player                        RGE_Player * get_player(RGE_Base_Game * this)
//         0053f873     MOV        this,dword ptr [EAX + 0x24]
//         0053f876     CMP        dword ptr [this->_padding_ + EBX*0x4],0x0
//         0053f87a     JZ         LAB_0053fa04
//                              vw_main.cpp:1384 (14)
//         0053f880     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0053f886     CALL       RGE_Base_Game::get_player                        RGE_Player * get_player(RGE_Base_Game * this)
//         0053f88b     MOV        EDX,dword ptr [EAX + 0x24]
//                              vw_main.cpp:1386 (25)
//         0053f88e     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0053f894     MOV        EAX,0x1
//         0053f899     MOV        ESI,dword ptr [EDX + EBX*0x4]
//         0053f89c     MOV        EDX,dword ptr [ECX + this->_padding_]
//         0053f8a2     CMP        EDX,0x3
//         0053f8a5     JNZ        LAB_0053f8a9
//                              vw_main.cpp:1387 (2)
//         0053f8a7     XOR        EAX,EAX
//                               LAB_0053f8a9                                                 XREF[1]:     0053f8a5(j)
//                              vw_main.cpp:1388 (25)
//         0053f8a9     MOV        EDX,dword ptr [EBP + 0xfc]
//         0053f8af     MOV        EDI,dword ptr [ESI]
//         0053f8b1     PUSH       EAX
//         0053f8b2     LEA        EAX=>pick_info.scr_x,[ESP + 0x18]
//         0053f8b6     PUSH       EDX
//         0053f8b7     LEA        this=>pick_info.y,[ESP + 0x18]
//         0053f8bb     PUSH       EAX
//         0053f8bc     PUSH       this
//         0053f8bd     MOV        this,ESI
//         0053f8bf     CALL       dword ptr [EDI + 0x24]
//                              vw_main.cpp:1391 (52)
//         0053f8c2     MOV        DL,byte ptr [ESI + 0x64]
//         0053f8c5     MOV        EAX,dword ptr [ESP + 0x14]
//         0053f8c9     MOV        this,dword ptr [ESP + 0x10]
//         0053f8cd     PUSH       0x1
//         0053f8cf     PUSH       offset DAT_fffffff8
//         0053f8d1     PUSH       offset DAT_fffffff4
//         0053f8d3     PUSH       0x0=>DAT_fffffff0
//         0053f8d5     PUSH       EDX
//         0053f8d6     PUSH       0x1
//         0053f8d8     PUSH       0x0
//         0053f8da     PUSH       EAX
//         0053f8db     PUSH       this
//         0053f8dc     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0053f8e2     CALL       RGE_Base_Game::get_player                        RGE_Player * get_player(RGE_Base_Game * this)
//         0053f8e7     PUSH       EAX
//         0053f8e8     MOV        this,ESI
//         0053f8ea     CALL       dword ptr [EDI + 0x20]
//         0053f8ed     AND        EAX,0xff
//         0053f8f2     MOV        dword ptr [ESP + 0x2c],EAX
//                              vw_main.cpp:1392 (6)
//         0053f8f6     JNZ        LAB_0053fa04
//                              vw_main.cpp:1394 (17)
//         0053f8fc     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0053f902     MOV        EAX,dword ptr [ECX + this->_padding_]
//         0053f908     CMP        EAX,0x1
//         0053f90b     JNZ        LAB_0053f95b
//                              vw_main.cpp:1396 (36)
//         0053f90d     CALL       RGE_Base_Game::get_player                        RGE_Player * get_player(RGE_Base_Game * this)
//         0053f912     MOV        this,dword ptr [ESP + 0x14]
//         0053f916     MOV        EDX,dword ptr [EAX]
//         0053f918     PUSH       0x0
//         0053f91a     PUSH       this=>DAT_fffffff8
//         0053f91b     MOV        this,dword ptr [ESP + 0x18]
//         0053f91f     PUSH       this=>DAT_fffffff4
//         0053f920     PUSH       EBX=>DAT_fffffff0
//         0053f921     MOV        this,EAX
//         0053f923     CALL       dword ptr [EDX + 0xb0]
//         0053f929     TEST       AL,AL
//         0053f92b     JZ         LAB_0053fa04
//                              vw_main.cpp:1398 (12)
//         0053f931     MOV        EAX,dword ptr [ESP + 0x30]
//         0053f935     TEST       EAX,EAX
//         0053f937     JZ         LAB_0053f9f5
//                              vw_main.cpp:1399 (15)
//         0053f93d     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0053f943     PUSH       0x0
//         0053f945     PUSH       0x0=>DAT_fffffff8
//         0053f947     MOV        EDX,dword ptr [this->_padding_]
//         0053f949     CALL       dword ptr [EDX + 0x10]
//                              vw_main.cpp:1400 (5)
//         0053f94c     MOV        EAX,0x1
//                              vw_main.cpp:1433 (10)
//         0053f951     POP        EDI
//         0053f952     POP        ESI
//         0053f953     POP        EBP
//         0053f954     POP        EBX
//         0053f955     ADD        ESP,0x14
//         0053f958     RET        0xc
//                               LAB_0053f95b                                                 XREF[1]:     0053f90b(j)
//                              vw_main.cpp:1403 (9)
//         0053f95b     CMP        EAX,0x8
//         0053f95e     JNZ        LAB_0053fa04
//                              vw_main.cpp:1405 (9)
//         0053f964     CMP        dword ptr [ECX + this->_padding_],0x1
//         0053f96b     JNZ        LAB_0053f98a
//                              vw_main.cpp:1407 (6)
//         0053f96d     MOV        ESI,dword ptr [EBP + 0x174]
//                              vw_main.cpp:1408 (21)
//         0053f973     MOV        this,dword ptr [ESP + 0x14]
//         0053f977     MOV        EDX,dword ptr [ESP + 0x10]
//         0053f97b     PUSH       0x0
//         0053f97d     MOV        EAX,dword ptr [ESI]
//         0053f97f     PUSH       this=>DAT_fffffff8
//         0053f980     PUSH       EDX=>DAT_fffffff4
//         0053f981     MOV        this,ESI
//         0053f983     CALL       dword ptr [EAX + 0x34]
//         0053f986     FSTP       ST0
//                              vw_main.cpp:1410 (2)
//         0053f988     JMP        LAB_0053f9aa
//                               LAB_0053f98a                                                 XREF[1]:     0053f96b(j)
//                              vw_main.cpp:1411 (32)
//         0053f98a     CALL       RGE_Base_Game::get_player                        RGE_Player * get_player(RGE_Base_Game * this)
//         0053f98f     MOV        this,dword ptr [ESP + 0x14]
//         0053f993     MOV        EDX,dword ptr [EAX]
//         0053f995     PUSH       0x1
//         0053f997     PUSH       0x0=>DAT_fffffff8
//         0053f999     PUSH       this=>DAT_fffffff4
//         0053f99a     MOV        this,dword ptr [ESP + 0x1c]
//         0053f99e     PUSH       this=>DAT_fffffff0
//         0053f99f     PUSH       EBX
//         0053f9a0     MOV        this,EAX
//         0053f9a2     CALL       dword ptr [EDX + 0x94]
//         0053f9a8     MOV        ESI,EAX
//                               LAB_0053f9aa                                                 XREF[1]:     0053f988(j)
//                              vw_main.cpp:1412 (4)
//         0053f9aa     TEST       ESI,ESI
//         0053f9ac     JZ         LAB_0053fa04
//                              vw_main.cpp:1415 (7)
//         0053f9ae     MOV        this,dword ptr [ESI + 0x18]
//         0053f9b1     TEST       this,this
//         0053f9b3     JZ         LAB_0053f9bc
//                              vw_main.cpp:1416 (5)
//         0053f9b5     CALL       RGE_Active_Sprite_List::get_lowest_draw_level    uchar get_lowest_draw_level(RGE_Active_Sprite
//                              vw_main.cpp:1417 (9)
//         0053f9ba     JMP        LAB_0053f9ce
//                               LAB_0053f9bc                                                 XREF[1]:     0053f9b3(j)
//         0053f9bc     MOV        ESI,dword ptr [ESI + 0x10]
//         0053f9bf     TEST       ESI,ESI
//         0053f9c1     JZ         LAB_0053f9cc
//                              vw_main.cpp:1418 (7)
//         0053f9c3     MOV        this,ESI
//         0053f9c5     CALL       RGE_Sprite::get_lowest_draw_level                uchar get_lowest_draw_level(RGE_Sprite * this)
//                              vw_main.cpp:1419 (2)
//         0053f9ca     JMP        LAB_0053f9ce
//                               LAB_0053f9cc                                                 XREF[1]:     0053f9c1(j)
//                              vw_main.cpp:1420 (2)
//         0053f9cc     MOV        AL,0x14
//                               LAB_0053f9ce                                                 XREF[2]:     0053f9ba(j), 0053f9ca(j)
//                              vw_main.cpp:1421 (4)
//         0053f9ce     TEST       AL,AL
//         0053f9d0     JNZ        LAB_0053f9eb
//                              vw_main.cpp:1422 (10)
//         0053f9d2     MOV        EDX,dword ptr [EBP]
//         0053f9d5     PUSH       0x2
//         0053f9d7     MOV        this,EBP
//         0053f9d9     CALL       dword ptr [EDX + 0x20]
//                              vw_main.cpp:1425 (5)
//         0053f9dc     MOV        EAX,0x1
//                              vw_main.cpp:1433 (10)
//         0053f9e1     POP        EDI
//         0053f9e2     POP        ESI
//         0053f9e3     POP        EBP
//         0053f9e4     POP        EBX
//         0053f9e5     ADD        ESP,0x14
//         0053f9e8     RET        0xc
//                               LAB_0053f9eb                                                 XREF[1]:     0053f9d0(j)
//                              vw_main.cpp:1424 (10)
//         0053f9eb     MOV        EAX,dword ptr [EBP]
//         0053f9ee     PUSH       0x1
//         0053f9f0     MOV        this,EBP
//         0053f9f2     CALL       dword ptr [EAX + 0x20]
//                               LAB_0053f9f5                                                 XREF[1]:     0053f937(j)
//                              vw_main.cpp:1425 (5)
//         0053f9f5     MOV        EAX,0x1
//                              vw_main.cpp:1433 (22)
//         0053f9fa     POP        EDI
//         0053f9fb     POP        ESI
//         0053f9fc     POP        EBP
//         0053f9fd     POP        EBX
//         0053f9fe     ADD        ESP,0x14
//         0053fa01     RET        0xc
//                               LAB_0053fa04                                                 XREF[8]:     0053f820(j), 0053f846(j),
//                                                                                                         0053f868(j), 0053f87a(j),
//                                                                                                         0053f8f6(j), 0053f92b(j),
//                                                                                                         0053f95e(j), 0053f9ac(j)
//         0053fa04     POP        EDI
//         0053fa05     POP        ESI
//         0053fa06     POP        EBP
//         0053fa07     XOR        EAX,EAX
//         0053fa09     POP        EBX
//         0053fa0a     ADD        ESP,0x14
//         0053fa0d     RET        0xc
    return 0;
}

int RGE_Main_View::command_make_do(long param_1, long param_2, int param_3, short param_4) {
    /* TODO: Stub */
//                              int __thiscall command_make_do(RGE_Main_View * this, long param_1, l
//              int               EAX:4          <RETURN>
//              RGE_Main_View *   ECX:4 (auto)   this
//              long              Stack[0x4]:4   param_1                   XREF[1]:     0053fa6e(R)
//              long              Stack[0x8]:4   param_2                   XREF[1]:     0053fa6a(R)
//              int               Stack[0xc]:4   param_3                   XREF[1]:     0053fae8(R)
//              short             Stack[0x10]:2  param_4                   XREF[1]:     0053fa66(R)
//              RGE_Pick_Info     Stack[-0x18]   pick_info                 XREF[1,4]:   0053fa75(*), 0053faf6(*), 0053fb12(*), 0053fb29(R),
//                                                                                     0053fb1e(R)
//              int               Stack[-0x1c]:4 attacking                 XREF[2]:     0053fa32(*), 0053fa4b(R)
//              RGE_Static_Obj    Stack[-0x20]:4 list                      XREF[0,1]:   0053fa2c(*)
//              short             Stack[-0x22]:2 list_num
//                               ?command_make_do@RGE_Main_View@@UAEHJJHF@Z                   XREF[2]:     command_make_do:0052de34(c),
//                               RGE_Main_View::command_make_do                                            005778f0(*)
//                              vw_main.cpp:1439 (16)
//         0053fa10     MOV        EAX,[allow_user_commands]                        = 1h
//         0053fa15     SUB        ESP,0x20
//         0053fa18     TEST       EAX,EAX
//         0053fa1a     PUSH       EBX
//         0053fa1b     PUSH       EBP
//         0053fa1c     PUSH       ESI
//         0053fa1d     PUSH       EDI
//         0053fa1e     MOV        ESI,this
//                              vw_main.cpp:1446 (6)
//         0053fa20     JZ         LAB_0053fbbc
//                              vw_main.cpp:1451 (37)
//         0053fa26     PUSH       -0x1
//         0053fa28     PUSH       -0x1
//         0053fa2a     PUSH       -0x1
//         0053fa2c     LEA        EAX=>list+0x2,[ESP + 0x1e]
//         0053fa30     PUSH       -0x1
//         0053fa32     LEA        this=>attacking,[ESP + 0x24]
//         0053fa36     PUSH       EAX
//         0053fa37     PUSH       this
//         0053fa38     MOV        this,dword ptr [ESI + 0x100]
//         0053fa3e     CALL       RGE_Player::get_selected_objects_to_command      uchar get_selected_objects_to_command(RGE_Pla
//         0053fa43     TEST       AL,AL
//         0053fa45     JZ         LAB_0053fbbc
//                              vw_main.cpp:1452 (13)
//         0053fa4b     MOV        EDX,dword ptr [ESP + attacking]
//         0053fa4f     PUSH       EDX
//         0053fa50     CALL       free                                             undefined free()
//         0053fa55     ADD        ESP,0x4
//                              vw_main.cpp:1456 (14)
//         0053fa58     PUSH       0x2
//         0053fa5a     PUSH       0xba
//         0053fa5f     PUSH       0x4c
//         0053fa61     CALL       color_log                                        void color_log(uchar param_1, uchar param_2,
//                              vw_main.cpp:1458 (32)
//         0053fa66     MOV        EAX,dword ptr [ESP + param_4]
//         0053fa6a     MOV        EBX,dword ptr [ESP + param_2]
//         0053fa6e     MOV        EBP,dword ptr [ESP + param_1]
//         0053fa72     ADD        ESP,0xc
//         0053fa75     LEA        this=>pick_info,[ESP + 0x18]
//         0053fa79     PUSH       EAX
//         0053fa7a     PUSH       this
//         0053fa7b     PUSH       EBX
//         0053fa7c     PUSH       EBP
//         0053fa7d     MOV        this,ESI
//         0053fa7f     CALL       RGE_Main_View::pick_best_target                  RGE_Static_Object * pick_best_target(RGE_Main
//         0053fa84     MOV        EDI,EAX
//                              vw_main.cpp:1459 (4)
//         0053fa86     TEST       EDI,EDI
//         0053fa88     JZ         LAB_0053fae8
//                              vw_main.cpp:1461 (30)
//         0053fa8a     MOV        EAX,dword ptr [EDI + 0x3c]
//         0053fa8d     MOV        this,dword ptr [ESI + 0x100]
//         0053fa93     PUSH       EAX
//         0053fa94     MOV        EAX,dword ptr [EDI + 0x38]
//         0053fa97     MOV        EDX,dword ptr [this->_padding_]
//         0053fa99     PUSH       EAX
//         0053fa9a     PUSH       EDI
//         0053fa9b     CALL       dword ptr [EDX + 0xa8]
//         0053faa1     AND        EAX,0xff
//         0053faa6     MOV        EBX,EAX
//                              vw_main.cpp:1463 (2)
//         0053faa8     JZ         LAB_0053fabe
//                              vw_main.cpp:1467 (20)
//         0053faaa     MOV        this,dword ptr [EDI + 0x4]
//         0053faad     PUSH       0x2
//         0053faaf     PUSH       0x2
//         0053fab1     PUSH       0x5dc
//         0053fab6     PUSH       this
//         0053fab7     MOV        this,ESI
//         0053fab9     CALL       RGE_View::display_object_selection               void display_object_selection(RGE_View * this
//                               LAB_0053fabe                                                 XREF[1]:     0053faa8(j)
//                              vw_main.cpp:1470 (7)
//         0053fabe     MOV        this,ESI
//         0053fac0     CALL       RGE_View::reset_overlay_sprites                  void reset_overlay_sprites(RGE_View * this)
//                              vw_main.cpp:1471 (9)
//         0053fac5     MOV        EDX,dword ptr [ESI]
//         0053fac7     PUSH       0x1
//         0053fac9     MOV        this,ESI
//         0053facb     CALL       dword ptr [EDX + 0x20]
//                              vw_main.cpp:1472 (14)
//         0053face     PUSH       0x2
//         0053fad0     PUSH       0x5f
//         0053fad2     PUSH       0x4c
//         0053fad4     CALL       color_log                                        void color_log(uchar param_1, uchar param_2,
//         0053fad9     ADD        ESP,0xc
//                              vw_main.cpp:1474 (2)
//         0053fadc     MOV        EAX,EBX
//                              vw_main.cpp:1502 (10)
//         0053fade     POP        EDI
//         0053fadf     POP        ESI
//         0053fae0     POP        EBP
//         0053fae1     POP        EBX
//         0053fae2     ADD        ESP,0x20
//         0053fae5     RET        0x10
//                               LAB_0053fae8                                                 XREF[1]:     0053fa88(j)
//                              vw_main.cpp:1477 (12)
//         0053fae8     MOV        EAX,dword ptr [ESP + param_3]
//         0053faec     TEST       EAX,EAX
//         0053faee     JZ         LAB_0053fb9e
//                              vw_main.cpp:1479 (30)
//         0053faf4     PUSH       0x1
//         0053faf6     LEA        EAX=>pick_info.y,[ESP + 0x20]
//         0053fafa     PUSH       0x0
//         0053fafc     PUSH       EAX
//         0053fafd     PUSH       EBX
//         0053fafe     PUSH       EBP
//         0053faff     PUSH       0x0
//         0053fb01     PUSH       0x28
//         0053fb03     MOV        this,ESI
//         0053fb05     CALL       RGE_Main_View::pick1                             uchar pick1(RGE_Main_View * this, uchar param
//         0053fb0a     CMP        AL,0x33
//         0053fb0c     JNZ        LAB_0053fb9e
//                              vw_main.cpp:1481 (12)
//         0053fb12     LEA        this=>pick_info.y,[ESP + 0x1c]
//         0053fb16     PUSH       this
//         0053fb17     MOV        this,ESI
//         0053fb19     CALL       RGE_Main_View::fixup_pick_info                   void fixup_pick_info(RGE_Main_View * this, RG
//                              vw_main.cpp:1482 (33)
//         0053fb1e     MOV        EAX,dword ptr [ESP + pick_info.scr_x]
//         0053fb22     MOV        this,dword ptr [ESI + 0x100]
//         0053fb28     PUSH       EAX
//         0053fb29     MOV        EAX,dword ptr [ESP + pick_info.y]
//         0053fb2d     MOV        EDX,dword ptr [this->_padding_]
//         0053fb2f     PUSH       EAX
//         0053fb30     PUSH       0x0
//         0053fb32     CALL       dword ptr [EDX + 0xa0]
//         0053fb38     AND        EAX,0xff
//         0053fb3d     MOV        EDI,EAX
//                              vw_main.cpp:1485 (2)
//         0053fb3f     JZ         LAB_0053fb84
//                              vw_main.cpp:1487 (9)
//         0053fb41     PUSH       0x2
//         0053fb43     MOV        this,ESI
//         0053fb45     CALL       RGE_Main_View::reset_display_object_selection    void reset_display_object_selection(RGE_Main_
//                              vw_main.cpp:1488 (49)
//         0053fb4a     MOV        this,dword ptr [ESI + 0x134]
//         0053fb50     MOV        EAX,[rge_base_game]                              = 00000000
//         0053fb55     MOV        EDX,dword ptr [ESI + 0x130]
//         0053fb5b     PUSH       0x5a
//         0053fb5d     PUSH       0x2
//         0053fb5f     PUSH       0x0
//         0053fb61     PUSH       0xf
//         0053fb63     ADD        this,EBX
//         0053fb65     PUSH       0x0
//         0053fb67     PUSH       this
//         0053fb68     MOV        this,dword ptr [EAX + 0x5c]
//         0053fb6b     ADD        EDX,EBP
//         0053fb6d     PUSH       EDX
//         0053fb6e     PUSH       0x0
//         0053fb70     MOV        EDX,dword ptr [ECX + this->_padding_]
//         0053fb73     MOV        this,ESI
//         0053fb75     PUSH       EDX
//         0053fb76     CALL       RGE_View::add_overlay_sprite                     void add_overlay_sprite(RGE_View * this, TSha
//                              vw_main.cpp:1489 (9)
//         0053fb7b     MOV        EAX,dword ptr [ESI]
//         0053fb7d     PUSH       0x1
//         0053fb7f     MOV        this,ESI
//         0053fb81     CALL       dword ptr [EAX + 0x20]
//                               LAB_0053fb84                                                 XREF[1]:     0053fb3f(j)
//                              vw_main.cpp:1492 (14)
//         0053fb84     PUSH       0x2
//         0053fb86     PUSH       0x5f
//         0053fb88     PUSH       0x4c
//         0053fb8a     CALL       color_log                                        void color_log(uchar param_1, uchar param_2,
//         0053fb8f     ADD        ESP,0xc
//                              vw_main.cpp:1493 (2)
//         0053fb92     MOV        EAX,EDI
//                              vw_main.cpp:1502 (10)
//         0053fb94     POP        EDI
//         0053fb95     POP        ESI
//         0053fb96     POP        EBP
//         0053fb97     POP        EBX
//         0053fb98     ADD        ESP,0x20
//         0053fb9b     RET        0x10
//                               LAB_0053fb9e                                                 XREF[2]:     0053faee(j), 0053fb0c(j)
//                              vw_main.cpp:1497 (7)
//         0053fb9e     MOV        this,ESI
//         0053fba0     CALL       RGE_View::reset_overlay_sprites                  void reset_overlay_sprites(RGE_View * this)
//                              vw_main.cpp:1498 (9)
//         0053fba5     MOV        EDX,dword ptr [ESI]
//         0053fba7     PUSH       0x1
//         0053fba9     MOV        this,ESI
//         0053fbab     CALL       dword ptr [EDX + 0x20]
//                              vw_main.cpp:1500 (14)
//         0053fbae     PUSH       0x2
//         0053fbb0     PUSH       0x5f
//         0053fbb2     PUSH       0x4c
//         0053fbb4     CALL       color_log                                        void color_log(uchar param_1, uchar param_2,
//         0053fbb9     ADD        ESP,0xc
//                               LAB_0053fbbc                                                 XREF[2]:     0053fa20(j), 0053fa45(j)
//                              vw_main.cpp:1502 (12)
//         0053fbbc     POP        EDI
//         0053fbbd     POP        ESI
//         0053fbbe     POP        EBP
//         0053fbbf     XOR        EAX,EAX
//         0053fbc1     POP        EBX
//         0053fbc2     ADD        ESP,0x20
//         0053fbc5     RET        0x10
//         0053fbc8     ??         90h
//         0053fbc9     NOP
//         0053fbca     NOP
//         0053fbcb     NOP
//         0053fbcc     NOP
//         0053fbcd     NOP
//         0053fbce     NOP
//         0053fbcf     NOP
    return 0;
}

uchar RGE_Main_View::pick1(uchar param_1, uchar param_2, long param_3, long param_4, RGE_Pick_Info* param_5, RGE_Static_Object* param_6, int param_7) {
    /* TODO: Stub */
//                              uchar __thiscall pick1(RGE_Main_View * this, uchar param_1, uchar pa
//              uchar             AL:1           <RETURN>
//              RGE_Main_View *   ECX:4 (auto)   this
//              uchar             Stack[0x4]:1   param_1                   XREF[8]:     0053fbd0(R), 0053fc56(W), 0053fd84(W), 0053fd96(R),
//                                                                                     0053fed4(R), 0053fee0(R), 0053fef0(W), 0053ff16(R)
//              uchar             Stack[0x8]:1   param_2                   XREF[5]:     0053fbe9(R), 0053fca0(R), 0053fdd1(R), 0053ff64(R),
//                                                                                     0053ff8a(R)
//              long              Stack[0xc]:4   param_3                   XREF[7]:     0053fc10(R), 0053fc1f(R), 0053fc5e(W), 0053fd88(W),
//                                                                                     0053fee8(R), 0053ff60(R), 0053ff86(R)
//              long              Stack[0x10]:4  param_4                   XREF[5]:     0053fc0c(R), 0053fc1b(R), 0053fc6d(W), 0053fd9f(W),
//                                                                                     0053ff58(R)
//              RGE_Pick_Info *   Stack[0x14]:4  param_5                   XREF[2]:     0053fbe5(R), 0053ff54(R)
//              RGE_Static_Obj    Stack[0x18]:4  param_6                   XREF[7]:     0053fc46(R), 0053fc5a(W), 0053fd57(R), 0053fd92(R),
//                                                                                     0053fed0(R), 0053feec(R), 0053ff50(R)
//              int               Stack[0x1c]:4  param_7                   XREF[1]:     0053fcb0(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     0053fd80(W), 0053fed8(R)
//              int               Stack[-0x8]:4  found_last                XREF[1]:     0053fc32(W)
//              int               Stack[-0xc]:4  target_count
//                               ?pick1@RGE_Main_View@@QAEEEEJJPAURGE_Pick_Info@@PAVRGE_Stat  XREF[24]:    draw_multi_object_outline:0052cbb1
//                               RGE_Main_View::pick1                                                      command_place_object:0052d248(c),
//                                                                                                         mouse_left_up_action:0052d690(c),
//                                                                                                         mouse_left_up_action:0052d8ce(c),
//                                                                                                         mouse_right_up_action:0052da00(c),
//                                                                                                         mouse_right_up_action:0052dc3e(c),
//                                                                                                         mouse_left_dbl_click_action:0052de
//                                                                                                         mouse_left_down_action:0053e3d6(c)
//                                                                                                         mouse_left_down_action:0053e4cf(c)
//                                                                                                         mouse_left_down_action:0053e65c(c)
//                                                                                                         mouse_left_up_action:0053eaaf(c),
//                                                                                                         mouse_left_up_action:0053ec53(c),
//                                                                                                         mouse_left_up_action:0053ecdf(c),
//                                                                                                         mouse_right_up_action:0053f463(c),
//                                                                                                         mouse_right_up_action:0053f56a(c),
//                                                                                                         command_place_object:0053f83f(c),
//                                                                                                         command_make_do:0053fb05(c),
//                                                                                                         0053ff73(c),
//                                                                                                         command_make_move:005403b0(c),
//                                                                                                         command_make_work:005404f6(c),
//                                                                                                         [more]
//                              vw_main.cpp:1508 (21)
//         0053fbd0     MOV        AL,byte ptr [ESP + param_1]
//         0053fbd4     SUB        ESP,0x8
//         0053fbd7     CMP        AL,0x29
//         0053fbd9     PUSH       EBX
//         0053fbda     PUSH       EBP
//         0053fbdb     PUSH       ESI
//         0053fbdc     PUSH       EDI
//         0053fbdd     MOV        ESI,this
//         0053fbdf     JNZ        LAB_0053ff50
//                              vw_main.cpp:1520 (4)
//         0053fbe5     MOV        EDI,dword ptr [ESP + param_5]
//                              vw_main.cpp:1558 (6)
//         0053fbe9     MOV        AL,byte ptr [ESP + param_2]
//         0053fbed     XOR        EBP,EBP
//                              vw_main.cpp:1559 (42)
//         0053fbef     PUSH       0x1
//         0053fbf1     TEST       AL,AL
//         0053fbf3     PUSH       0x4
//         0053fbf5     MOV        dword ptr [EDI],EBP
//         0053fbf7     MOV        dword ptr [EDI + 0x4],EBP
//         0053fbfa     MOV        word ptr [EDI + 0x8],BP
//         0053fbfe     MOV        word ptr [EDI + 0xa],BP
//         0053fc02     MOV        dword ptr [EDI + 0xc],EBP
//         0053fc05     MOV        dword ptr [EDI + 0x10],EBP
//         0053fc08     PUSH       0xf
//         0053fc0a     JNZ        LAB_0053fc1b
//         0053fc0c     MOV        EAX,dword ptr [ESP + param_4]
//         0053fc10     MOV        this,dword ptr [ESP + param_3]
//         0053fc14     PUSH       0x28
//         0053fc16     PUSH       EBP
//         0053fc17     PUSH       EAX
//         0053fc18     PUSH       this
//                              vw_main.cpp:1560 (2)
//         0053fc19     JMP        LAB_0053fc29
//                               LAB_0053fc1b                                                 XREF[1]:     0053fc0a(j)
//                              vw_main.cpp:1561 (21)
//         0053fc1b     MOV        EDX,dword ptr [ESP + param_4]
//         0053fc1f     MOV        EAX,dword ptr [ESP + param_3]
//         0053fc23     PUSH       0x14
//         0053fc25     PUSH       0xa
//         0053fc27     PUSH       EDX
//         0053fc28     PUSH       EAX
//                               LAB_0053fc29                                                 XREF[1]:     0053fc19(j)
//         0053fc29     MOV        this,ESI
//         0053fc2b     CALL       RGE_View::pick_objects                           int pick_objects(RGE_View * this, int param_1
//                              vw_main.cpp:1563 (10)
//         0053fc30     MOV        this,EAX
//         0053fc32     MOV        dword ptr [ESP + found_last],EAX
//         0053fc36     CMP        this,EBP
//         0053fc38     JNZ        LAB_0053fc46
//                              vw_main.cpp:1564 (2)
//         0053fc3a     MOV        AL,0x32
//                              vw_main.cpp:1668 (10)
//         0053fc3c     POP        EDI
//         0053fc3d     POP        ESI
//         0053fc3e     POP        EBP
//         0053fc3f     POP        EBX
//         0053fc40     ADD        ESP,0x8
//         0053fc43     RET        0x1c
//                               LAB_0053fc46                                                 XREF[1]:     0053fc38(j)
//                              vw_main.cpp:1567 (10)
//         0053fc46     CMP        dword ptr [ESP + param_6],EBP
//         0053fc4a     JNZ        LAB_0053fd7e
//                              vw_main.cpp:1569 (2)
//         0053fc50     XOR        EAX,EAX
//                              vw_main.cpp:1570 (2)
//         0053fc52     XOR        EBX,EBX
//                              vw_main.cpp:1573 (20)
//         0053fc54     CMP        this,EBP
//         0053fc56     MOV        dword ptr [ESP + param_1],EAX
//         0053fc5a     MOV        dword ptr [ESP + param_6],EBP
//         0053fc5e     MOV        dword ptr [ESP + param_3],EBP
//         0053fc62     JLE        LAB_0053fd4f
//                              vw_main.cpp:1668 (147)
//         0053fc68     MOV        EBP,Picked_Objects                               = 00000000
//         0053fc6d     MOV        dword ptr [ESP + param_4],this
//                               LAB_0053fc71                                                 XREF[1]:     0053fd3f(j)
//         0053fc71     MOV        EAX,dword ptr [EBP]=>Picked_Objects              = 00000000
//         0053fc74     TEST       EAX,EAX
//         0053fc76     JL         LAB_0053fd33
//         0053fc7c     MOV        this,dword ptr [ESI + 0xfc]
//         0053fc82     MOV        EDX,dword ptr [ECX + this->_padding_]
//         0053fc88     MOV        EDI,dword ptr [EDX + EAX*0x4]
//         0053fc8b     TEST       EDI,EDI
//         0053fc8d     JZ         LAB_0053fd33
//         0053fc93     CMP        byte ptr [EDI + 0x48],0x7
//         0053fc97     JNC        LAB_0053fd33
//         0053fc9d     MOV        EAX,dword ptr [EDI + 0x8]
//         0053fca0     MOV        this,byte ptr [ESP + param_2]
//         0053fca4     CMP        byte ptr [EAX + 0x8d],this
//         0053fcaa     JC         LAB_0053fd33
//         0053fcb0     MOV        EAX,dword ptr [ESP + param_7]
//         0053fcb4     TEST       EAX,EAX
//         0053fcb6     JNZ        LAB_0053fcfb
//         0053fcb8     MOV        EDX,dword ptr [ESI + 0x104]
//         0053fcbe     MOV        AL,byte ptr [EDX + 0x8db8]
//         0053fcc4     TEST       AL,AL
//         0053fcc6     JNZ        LAB_0053fcfb
//         0053fcc8     MOV        EAX,dword ptr [ESI]
//         0053fcca     PUSH       EDI
//         0053fccb     MOV        this,ESI
//         0053fccd     CALL       dword ptr [EAX + 0xe0]
//         0053fcd3     TEST       EAX,EAX
//         0053fcd5     JNZ        LAB_0053fcfb
//         0053fcd7     FLD        float ptr [EDI + 0x3c]
//         0053fcda     CALL       __ftol                                           undefined __ftol()
//         0053fcdf     FLD        float ptr [EDI + 0x38]
//         0053fce2     PUSH       EAX
//         0053fce3     CALL       __ftol                                           undefined __ftol()
//         0053fce8     MOV        this,dword ptr [ESI + 0x100]
//         0053fcee     PUSH       EAX=>DAT_fffffff8
//         0053fcef     MOV        this,dword ptr [ECX + this->_padding_]
//         0053fcf2     CALL       RGE_Visible_Map::get_visible                     uchar get_visible(RGE_Visible_Map * this, int
//         0053fcf7     CMP        AL,0xf
//         0053fcf9     JNZ        LAB_0053fd33
//                               LAB_0053fcfb                                                 XREF[3]:     0053fcb6(j), 0053fcc6(j),
//                                                                                                         0053fcd5(j)
//                              vw_main.cpp:1580 (16)
//         0053fcfb     MOVSX      EAX,word ptr [EBP + 0x4]=>DAT_0087d4a4
//         0053fcff     MOV        EDX,dword ptr [ESI]
//         0053fd01     PUSH       EAX
//         0053fd02     PUSH       EDI=>DAT_fffffff8
//         0053fd03     MOV        this,ESI
//         0053fd05     CALL       dword ptr [EDX + 0xe4]
//                              vw_main.cpp:1581 (6)
//         0053fd0b     CMP        EAX,dword ptr [ESP + 0x24]
//         0053fd0f     JLE        LAB_0053fd33
//                              vw_main.cpp:1584 (7)
//         0053fd11     MOV        BX,word ptr [ESI + 0x8c]
//                              vw_main.cpp:1585 (19)
//         0053fd18     MOV        this,word ptr [ESI + 0x90]
//         0053fd1f     ADD        BX,word ptr [EBP + 0x8]=>DAT_0087d4a8
//         0053fd23     ADD        this,word ptr [EBP + 0xa]=>DAT_0087d4aa
//         0053fd27     MOV        dword ptr [ESP + 0x1c],EDI
//                              vw_main.cpp:1586 (36)
//         0053fd2b     MOV        dword ptr [ESP + 0x24],EAX
//         0053fd2f     MOV        dword ptr [ESP + 0x30],this
//                               LAB_0053fd33                                                 XREF[6]:     0053fc76(j), 0053fc8d(j),
//                                                                                                         0053fc97(j), 0053fcaa(j),
//                                                                                                         0053fcf9(j), 0053fd0f(j)
//         0053fd33     MOV        EAX,dword ptr [ESP + 0x28]
//         0053fd37     ADD        EBP,0xc
//         0053fd3a     DEC        EAX
//         0053fd3b     MOV        dword ptr [ESP + 0x28],EAX
//         0053fd3f     JNZ        LAB_0053fc71
//         0053fd45     MOV        EAX,dword ptr [ESP + 0x1c]
//         0053fd49     MOV        EDI,dword ptr [ESP + 0x2c]
//         0053fd4d     XOR        EBP,EBP
//                               LAB_0053fd4f                                                 XREF[1]:     0053fc62(j)
//                              vw_main.cpp:1591 (8)
//         0053fd4f     CMP        EAX,EBP
//         0053fd51     JZ         LAB_0053ff44
//                              vw_main.cpp:1595 (16)
//         0053fd57     MOV        this,word ptr [ESP + param_6]
//         0053fd5c     MOV        dword ptr [EDI + 0xc],EAX
//         0053fd5f     MOV        word ptr [EDI + 0x8],BX
//         0053fd63     MOV        word ptr [EDI + 0xa],this
//                              vw_main.cpp:1596 (5)
//         0053fd67     MOV        EDX,dword ptr [EAX + 0x38]
//         0053fd6a     MOV        dword ptr [EDI],EDX
//                              vw_main.cpp:1597 (6)
//         0053fd6c     MOV        EAX,dword ptr [EAX + 0x3c]
//         0053fd6f     MOV        dword ptr [EDI + 0x4],EAX
//                              vw_main.cpp:1598 (2)
//         0053fd72     MOV        AL,0x34
//                              vw_main.cpp:1668 (10)
//         0053fd74     POP        EDI
//         0053fd75     POP        ESI
//         0053fd76     POP        EBP
//         0053fd77     POP        EBX
//         0053fd78     ADD        ESP,0x8
//         0053fd7b     RET        0x1c
//                               LAB_0053fd7e                                                 XREF[1]:     0053fc4a(j)
//                              vw_main.cpp:1611 (20)
//         0053fd7e     CMP        this,EBP
//         0053fd80     MOV        dword ptr [ESP + local_4],EBP
//         0053fd84     MOV        dword ptr [ESP + param_1],EBP
//         0053fd88     MOV        dword ptr [ESP + param_3],EBP
//         0053fd8c     JLE        LAB_0053fed0
//                              vw_main.cpp:1668 (178)
//         0053fd92     MOV        EBX,dword ptr [ESP + param_6]
//         0053fd96     MOV        EBP,dword ptr [ESP + param_1]
//         0053fd9a     MOV        this,Picked_Objects                              = 00000000
//         0053fd9f     MOV        dword ptr [ESP + param_4],this=>Picked_Objects   = 00000000
//                               LAB_0053fda3                                                 XREF[1]:     0053fe9c(j)
//         0053fda3     MOV        EAX,dword ptr [this->_padding_]=>Picked_Objects  = 00000000
//         0053fda5     TEST       EAX,EAX
//         0053fda7     JL         LAB_0053fe82
//         0053fdad     MOV        EDX,dword ptr [ESI + 0xfc]
//         0053fdb3     MOV        EDX,dword ptr [EDX + 0x88]
//         0053fdb9     MOV        EDI,dword ptr [EDX + EAX*0x4]
//         0053fdbc     TEST       EDI,EDI
//         0053fdbe     JZ         LAB_0053fe82
//         0053fdc4     CMP        byte ptr [EDI + 0x48],0x7
//         0053fdc8     JNC        LAB_0053fe82
//         0053fdce     MOV        EAX,dword ptr [EDI + 0x8]
//         0053fdd1     MOV        DL,byte ptr [ESP + param_2]
//         0053fdd5     CMP        byte ptr [EAX + 0x8d],DL
//         0053fddb     JC         LAB_0053fe82
//         0053fde1     MOVSX      this,word ptr [ECX + this->_padding_]=>DAT_008
//         0053fde5     MOV        EAX,dword ptr [ESI]
//         0053fde7     PUSH       this
//         0053fde8     PUSH       EDI
//         0053fde9     MOV        this,ESI
//         0053fdeb     CALL       dword ptr [EAX + 0xe4]
//         0053fdf1     TEST       EAX,EAX
//         0053fdf3     JLE        LAB_0053fe82
//         0053fdf9     MOV        EAX,dword ptr [ESP + 0x34]
//         0053fdfd     TEST       EAX,EAX
//         0053fdff     JNZ        LAB_0053fe44
//         0053fe01     MOV        EDX,dword ptr [ESI + 0x104]
//         0053fe07     MOV        AL,byte ptr [EDX + 0x8db8]
//         0053fe0d     TEST       AL,AL
//         0053fe0f     JNZ        LAB_0053fe44
//         0053fe11     MOV        EAX,dword ptr [ESI]
//         0053fe13     PUSH       EDI
//         0053fe14     MOV        this,ESI
//         0053fe16     CALL       dword ptr [EAX + 0xe0]
//         0053fe1c     TEST       EAX,EAX
//         0053fe1e     JNZ        LAB_0053fe44
//         0053fe20     FLD        float ptr [EDI + 0x3c]
//         0053fe23     CALL       __ftol                                           undefined __ftol()
//         0053fe28     FLD        float ptr [EDI + 0x38]
//         0053fe2b     PUSH       EAX
//         0053fe2c     CALL       __ftol                                           undefined __ftol()
//         0053fe31     PUSH       EAX=>DAT_fffffff8
//         0053fe32     MOV        EAX,dword ptr [ESI + 0x100]
//         0053fe38     MOV        this,dword ptr [EAX + 0x38]
//         0053fe3b     CALL       RGE_Visible_Map::get_visible                     uchar get_visible(RGE_Visible_Map * this, int
//         0053fe40     CMP        AL,0xf
//         0053fe42     JNZ        LAB_0053fe82
//                               LAB_0053fe44                                                 XREF[3]:     0053fdff(j), 0053fe0f(j),
//                                                                                                         0053fe1e(j)
//                              vw_main.cpp:1622 (6)
//         0053fe44     CMP        EDI,dword ptr [ESP + 0x30]
//         0053fe48     JNZ        LAB_0053fe54
//                              vw_main.cpp:1623 (8)
//         0053fe4a     MOV        dword ptr [ESP + 0x14],0x1
//                              vw_main.cpp:1624 (10)
//         0053fe52     JMP        LAB_0053fe82
//                               LAB_0053fe54                                                 XREF[1]:     0053fe48(j)
//         0053fe54     MOV        EAX,dword ptr [ESP + 0x14]
//         0053fe58     TEST       EAX,EAX
//         0053fe5a     JNZ        LAB_0053fea4
//                              vw_main.cpp:1631 (8)
//         0053fe5c     MOV        EAX,dword ptr [ESP + 0x1c]
//         0053fe60     TEST       EAX,EAX
//         0053fe62     JNZ        LAB_0053fe82
//                              vw_main.cpp:1634 (11)
//         0053fe64     MOV        EAX,dword ptr [ESP + 0x28]
//         0053fe68     MOV        BP,word ptr [ESI + 0x8c]
//                              vw_main.cpp:1635 (53)
//         0053fe6f     MOV        BX,word ptr [ESI + 0x90]
//         0053fe76     MOV        dword ptr [ESP + 0x1c],EDI
//         0053fe7a     ADD        BP,word ptr [EAX + 0x8]
//         0053fe7e     ADD        BX,word ptr [EAX + 0xa]
//                               LAB_0053fe82                                                 XREF[8]:     0053fda7(j), 0053fdbe(j),
//                                                                                                         0053fdc8(j), 0053fddb(j),
//                                                                                                         0053fdf3(j), 0053fe42(j),
//                                                                                                         0053fe52(j), 0053fe62(j)
//         0053fe82     MOV        EAX,dword ptr [ESP + 0x24]
//         0053fe86     MOV        this,dword ptr [ESP + 0x28]
//         0053fe8a     MOV        EDX,dword ptr [ESP + 0x10]
//         0053fe8e     INC        EAX
//         0053fe8f     ADD        this,0xc
//         0053fe92     CMP        EAX,EDX
//         0053fe94     MOV        dword ptr [ESP + 0x24],EAX
//         0053fe98     MOV        dword ptr [ESP + 0x28],this
//         0053fe9c     JL         LAB_0053fda3
//         0053fea2     JMP        LAB_0053fed8
//                               LAB_0053fea4                                                 XREF[1]:     0053fe5a(j)
//                              vw_main.cpp:1627 (21)
//         0053fea4     MOV        EAX,dword ptr [ESP + 0x24]
//         0053fea8     MOV        dword ptr [ESP + 0x1c],EDI
//         0053feac     LEA        EAX,[EAX + EAX*0x2]
//         0053feaf     SHL        EAX,0x2
//         0053feb2     MOV        BP,word ptr [EAX + DAT_0087d4a8]
//                              vw_main.cpp:1628 (31)
//         0053feb9     MOV        BX,word ptr [EAX + DAT_0087d4aa]
//         0053fec0     ADD        BP,word ptr [ESI + 0x8c]
//         0053fec7     ADD        BX,word ptr [ESI + 0x90]
//         0053fece     JMP        LAB_0053fed8
//                               LAB_0053fed0                                                 XREF[1]:     0053fd8c(j)
//         0053fed0     MOV        EBX,dword ptr [ESP + param_6]
//         0053fed4     MOV        EBP,dword ptr [ESP + param_1]
//                               LAB_0053fed8                                                 XREF[2]:     0053fea2(j), 0053fece(j)
//                              vw_main.cpp:1641 (16)
//         0053fed8     MOV        EAX,dword ptr [ESP + local_4]
//         0053fedc     TEST       EAX,EAX
//         0053fede     JZ         LAB_0053ff16
//         0053fee0     MOV        EAX,dword ptr [ESP + param_1]
//         0053fee4     TEST       EAX,EAX
//         0053fee6     JNZ        LAB_0053ff16
//                              vw_main.cpp:1644 (25)
//         0053fee8     MOV        EAX,dword ptr [ESP + param_3]
//         0053feec     MOV        this,dword ptr [ESP + param_6]
//         0053fef0     MOV        dword ptr [ESP + param_1],this
//         0053fef4     LEA        EAX,[EAX + EAX*0x2]
//         0053fef7     SHL        EAX,0x2
//         0053fefa     MOV        BP,word ptr [EAX + DAT_0087d4a8]
//                              vw_main.cpp:1645 (21)
//         0053ff01     MOV        BX,word ptr [EAX + DAT_0087d4aa]
//         0053ff08     ADD        BP,word ptr [ESI + 0x8c]
//         0053ff0f     ADD        BX,word ptr [ESI + 0x90]
//                               LAB_0053ff16                                                 XREF[2]:     0053fede(j), 0053fee6(j)
//                              vw_main.cpp:1648 (8)
//         0053ff16     MOV        this,dword ptr [ESP + param_1]
//         0053ff1a     TEST       this,this
//         0053ff1c     JZ         LAB_0053ff44
//                              vw_main.cpp:1650 (7)
//         0053ff1e     MOV        EAX,dword ptr [ESP + 0x2c]
//         0053ff22     MOV        dword ptr [EAX + 0xc],this
//                              vw_main.cpp:1651 (4)
//         0053ff25     MOV        word ptr [EAX + 0x8],BP
//                              vw_main.cpp:1652 (4)
//         0053ff29     MOV        word ptr [EAX + 0xa],BX
//                              vw_main.cpp:1653 (5)
//         0053ff2d     MOV        EDX,dword ptr [ECX + this->_padding_]
//         0053ff30     MOV        dword ptr [EAX],EDX
//                              vw_main.cpp:1654 (6)
//         0053ff32     MOV        this,dword ptr [ECX + this->_padding_]
//         0053ff35     MOV        dword ptr [EAX + 0x4],this
//                              vw_main.cpp:1655 (2)
//         0053ff38     MOV        AL,0x34
//                              vw_main.cpp:1668 (10)
//         0053ff3a     POP        EDI
//         0053ff3b     POP        ESI
//         0053ff3c     POP        EBP
//         0053ff3d     POP        EBX
//         0053ff3e     ADD        ESP,0x8
//         0053ff41     RET        0x1c
//                               LAB_0053ff44                                                 XREF[2]:     0053fd51(j), 0053ff1c(j)
//                              vw_main.cpp:1658 (2)
//         0053ff44     MOV        AL,0x32
//                              vw_main.cpp:1668 (10)
//         0053ff46     POP        EDI
//         0053ff47     POP        ESI
//         0053ff48     POP        EBP
//         0053ff49     POP        EBX
//         0053ff4a     ADD        ESP,0x8
//         0053ff4d     RET        0x1c
//                               LAB_0053ff50                                                 XREF[1]:     0053fbdf(j)
//                              vw_main.cpp:1660 (16)
//         0053ff50     MOV        EDI,dword ptr [ESP + param_6]
//         0053ff54     MOV        EBX,dword ptr [ESP + param_5]
//         0053ff58     MOV        EBP,dword ptr [ESP + param_4]
//         0053ff5c     CMP        AL,0x2a
//         0053ff5e     JNZ        LAB_0053ff86
//                              vw_main.cpp:1662 (28)
//         0053ff60     MOV        EDX,dword ptr [ESP + param_3]
//         0053ff64     MOV        EAX,dword ptr [ESP + param_2]
//         0053ff68     PUSH       0x1
//         0053ff6a     PUSH       EDI
//         0053ff6b     PUSH       EBX
//         0053ff6c     PUSH       EBP
//         0053ff6d     PUSH       EDX
//         0053ff6e     PUSH       EAX
//         0053ff6f     PUSH       0x29
//         0053ff71     MOV        this,ESI
//         0053ff73     CALL       RGE_Main_View::pick1                             uchar pick1(RGE_Main_View * this, uchar param
//         0053ff78     CMP        AL,0x34
//         0053ff7a     JNZ        LAB_0053ff86
//                              vw_main.cpp:1668 (10)
//         0053ff7c     POP        EDI
//         0053ff7d     POP        ESI
//         0053ff7e     POP        EBP
//         0053ff7f     POP        EBX
//         0053ff80     ADD        ESP,0x8
//         0053ff83     RET        0x1c
//                               LAB_0053ff86                                                 XREF[2]:     0053ff5e(j), 0053ff7a(j)
//                              vw_main.cpp:1666 (22)
//         0053ff86     MOV        this,dword ptr [ESP + param_3]
//         0053ff8a     MOV        EDX,dword ptr [ESP + param_2]
//         0053ff8e     PUSH       EDI
//         0053ff8f     PUSH       EBX
//         0053ff90     PUSH       EBP
//         0053ff91     PUSH       this
//         0053ff92     PUSH       EDX
//         0053ff93     PUSH       0x28
//         0053ff95     MOV        this,ESI
//         0053ff97     CALL       RGE_View::pick                                   uchar pick(RGE_View * this, uchar param_1, uc
//                              vw_main.cpp:1668 (10)
//         0053ff9c     POP        EDI
//         0053ff9d     POP        ESI
//         0053ff9e     POP        EBP
//         0053ff9f     POP        EBX
//         0053ffa0     ADD        ESP,0x8
//         0053ffa3     RET        0x1c
//         0053ffa6     ??         90h
//         0053ffa7     NOP
//         0053ffa8     NOP
//         0053ffa9     NOP
//         0053ffaa     NOP
//         0053ffab     NOP
//         0053ffac     NOP
//         0053ffad     NOP
//         0053ffae     NOP
//         0053ffaf     NOP
    return 0;
}

int RGE_Main_View::pick_objects1(long param_1, long param_2, RGE_Static_Object** param_3, int param_4) {
    /* TODO: Stub */
//                              int __thiscall pick_objects1(RGE_Main_View * this, long param_1, lon
//              int               EAX:4          <RETURN>
//              RGE_Main_View *   ECX:4 (auto)   this
//              long              Stack[0x4]:4   param_1                   XREF[1]:     0053ffcb(R)
//              long              Stack[0x8]:4   param_2                   XREF[1]:     0053ffb7(R)
//              RGE_Static_Obj    Stack[0xc]:4   param_3                   XREF[2]:     0053ffbd(R), 0053ffee(R)
//              int               Stack[0x10]:4  param_4                   XREF[1]:     0053ffc5(R)
//              RGE_Pick_Info     Stack[-0x18]   pick_info                 XREF[0,2]:   0053ffd0(*), 0053ffe6(R)
//                               ?pick_objects1@RGE_Main_View@@QAEHJJPAPAVRGE_Static_Object@
//                               RGE_Main_View::pick_objects1
//                              vw_main.cpp:1674 (3)
//         0053ffb0     SUB        ESP,0x14
//                              vw_main.cpp:1679 (16)
//         0053ffb3     XOR        EAX,EAX
//         0053ffb5     PUSH       EBX
//         0053ffb6     PUSH       EBP
//         0053ffb7     MOV        EBP,dword ptr [ESP + param_2]
//         0053ffbb     PUSH       ESI
//         0053ffbc     PUSH       EDI
//         0053ffbd     MOV        EDI,dword ptr [ESP + param_3]
//         0053ffc1     MOV        EBX,this
//                              vw_main.cpp:1680 (2)
//         0053ffc3     XOR        ESI,ESI
//                               LAB_0053ffc5                                                 XREF[1]:     0053fffc(j)
//                              vw_main.cpp:1684 (6)
//         0053ffc5     CMP        ESI,dword ptr [ESP + param_4]
//         0053ffc9     JZ         LAB_0053fffe
//                              vw_main.cpp:1686 (27)
//         0053ffcb     MOV        this,dword ptr [ESP + param_1]
//         0053ffcf     PUSH       EAX
//         0053ffd0     LEA        EAX=>pick_info.y,[ESP + 0x14]
//         0053ffd4     PUSH       EAX
//         0053ffd5     PUSH       EBP
//         0053ffd6     PUSH       this
//         0053ffd7     PUSH       0x0
//         0053ffd9     PUSH       0x29
//         0053ffdb     MOV        this,EBX
//         0053ffdd     CALL       RGE_View::pick                                   uchar pick(RGE_View * this, uchar param_1, uc
//         0053ffe2     CMP        AL,0x34
//         0053ffe4     JNZ        LAB_0053fffe
//                              vw_main.cpp:1688 (16)
//         0053ffe6     MOV        EAX,dword ptr [ESP + pick_info.tile]
//         0053ffea     TEST       ESI,ESI
//         0053ffec     JLE        LAB_0053fff6
//         0053ffee     MOV        EDX,dword ptr [ESP + param_3]
//         0053fff2     CMP        EAX,dword ptr [EDX]
//         0053fff4     JZ         LAB_0053fffe
//                               LAB_0053fff6                                                 XREF[1]:     0053ffec(j)
//                              vw_main.cpp:1690 (2)
//         0053fff6     MOV        dword ptr [EDI],EAX
//                              vw_main.cpp:1691 (6)
//         0053fff8     INC        ESI
//         0053fff9     ADD        EDI,0x4
//         0053fffc     JMP        LAB_0053ffc5
//                               LAB_0053fffe                                                 XREF[3]:     0053ffc9(j), 0053ffe4(j),
//                                                                                                         0053fff4(j)
//                              vw_main.cpp:1695 (2)
//         0053fffe     MOV        EAX,ESI
//                              vw_main.cpp:1696 (10)
//         00540000     POP        EDI
//         00540001     POP        ESI
//         00540002     POP        EBP
//         00540003     POP        EBX
//         00540004     ADD        ESP,0x14
//         00540007     RET        0x10
//         0054000a     ??         90h
//         0054000b     NOP
//         0054000c     NOP
//         0054000d     NOP
//         0054000e     NOP
//         0054000f     NOP
    return 0;
}

RGE_Static_Object* RGE_Main_View::pick_best_target(long param_1, long param_2, int* param_3, short param_4) {
    /* TODO: Stub */
//                              RGE_Static_Object * __thiscall pick_best_target(RGE_Main_View * this
//              RGE_Static_Obj    EAX:4          <RETURN>
//              RGE_Main_View *   ECX:4 (auto)   this
//              long              Stack[0x4]:4   param_1                   XREF[1]:     00540038(R)
//              long              Stack[0x8]:4   param_2                   XREF[1]:     00540031(R)
//              int *             Stack[0xc]:4   param_3                   XREF[1]:     00540016(R)
//              short             Stack[0x10]:2  param_4
//              int[64]           Stack[-0x104   attacking                 XREF[0,1]:   005400a8(*)
//              int[64]           Stack[-0x204   valid_target_count        XREF[0,1]:   005400b6(*)
//              undefined4        Stack[-0x208   local_208                 XREF[1]:     005400e4(W)
//              RGE_Master_Act    Stack[-0x20c   master_obj                XREF[1]:     00540056(W)
//              int               Stack[-0x210   target_count              XREF[1]:     005400d4(W)
//              int               Stack[-0x214   j                         XREF[1]:     005400c6(W)
//              int               Stack[-0x218   i                         XREF[4]:     0054007b(*), 005400d0(R), 00540134(R), 005402e3(R)
//              RGE_Static_Obj    Stack[-0x21c   selected_objects          XREF[1]:     00540025(W)
//              undefined2        Stack[-0x21e   local_21e                 XREF[2]:     00540075(*), 005400c1(R)
//              short             Stack[-0x222   selected_count
//                               ?pick_best_target@RGE_Main_View@@QAEPAVRGE_Static_Object@@J  XREF[4]:     mouse_left_up_action:0052d850(c),
//                               RGE_Main_View::pick_best_target                                           mouse_right_up_action:0052dbc0(c),
//                                                                                                         command_make_do:0053fa7f(c),
//                                                                                                         command_make_work:0054047b(c)
//                              vw_main.cpp:1702 (6)
//         00540010     SUB        ESP,0x224
//                              vw_main.cpp:1716 (21)
//         00540016     MOV        EAX,dword ptr [ESP + param_3]
//         0054001d     PUSH       EBX
//         0054001e     PUSH       EBP
//         0054001f     MOV        EBX,this
//         00540021     PUSH       ESI
//         00540022     PUSH       EDI
//         00540023     TEST       EAX,EAX
//         00540025     MOV        dword ptr [ESP + selected_objects],EBX
//         00540029     JZ         LAB_00540031
//                              vw_main.cpp:1717 (6)
//         0054002b     MOV        dword ptr [EAX],0x0
//                               LAB_00540031                                                 XREF[1]:     00540029(j)
//                              vw_main.cpp:1728 (35)
//         00540031     MOV        EAX,dword ptr [ESP + param_2]
//         00540038     MOV        this,dword ptr [ESP + param_1]
//         0054003f     PUSH       0x1
//         00540041     PUSH       0x4
//         00540043     PUSH       0xf
//         00540045     PUSH       0x14
//         00540047     PUSH       0xa
//         00540049     PUSH       EAX
//         0054004a     PUSH       this
//         0054004b     MOV        this,EBX
//         0054004d     CALL       RGE_View::pick_objects                           int pick_objects(RGE_View * this, int param_1
//         00540052     MOV        EBP,EAX
//                              vw_main.cpp:1730 (8)
//         00540054     TEST       EBP,EBP
//         00540056     MOV        dword ptr [ESP + master_obj],EBP
//         0054005a     JNZ        LAB_00540069
//                              vw_main.cpp:1812 (13)
//         0054005c     POP        EDI
//         0054005d     POP        ESI
//         0054005e     POP        EBP
//         0054005f     POP        EBX
//         00540060     ADD        ESP,0x224
//         00540066     RET        0x10
//                               LAB_00540069                                                 XREF[1]:     0054005a(j)
//                              vw_main.cpp:1734 (33)
//         00540069     MOV        this,dword ptr [EBX + 0x100]
//         0054006f     PUSH       -0x1
//         00540071     PUSH       -0x1
//         00540073     PUSH       -0x1
//         00540075     LEA        EDX=>local_21e,[ESP + 0x22]
//         00540079     PUSH       -0x1
//         0054007b     LEA        EAX=>i,[ESP + 0x2c]
//         0054007f     PUSH       EDX
//         00540080     PUSH       EAX
//         00540081     CALL       RGE_Player::get_selected_objects_to_command      uchar get_selected_objects_to_command(RGE_Pla
//         00540086     TEST       AL,AL
//         00540088     JNZ        LAB_00540099
//                              vw_main.cpp:1735 (2)
//         0054008a     XOR        EAX,EAX
//                              vw_main.cpp:1812 (13)
//         0054008c     POP        EDI
//         0054008d     POP        ESI
//         0054008e     POP        EBP
//         0054008f     POP        EBX
//         00540090     ADD        ESP,0x224
//         00540096     RET        0x10
//                               LAB_00540099                                                 XREF[1]:     00540088(j)
//                              vw_main.cpp:1739 (13)
//         00540099     TEST       EBP,EBP
//         0054009b     JLE        LAB_005400bf
//         0054009d     LEA        EDX,[EBP*0x4 + 0x0]
//         005400a4     XOR        EAX,EAX
//                              vw_main.cpp:1812 (42)
//         005400a6     MOV        this,EDX
//         005400a8     LEA        EDI=>attacking[1],[ESP + 0x134]
//         005400af     SHR        this,0x2
//         005400b2     STOSD.REP  ES:EDI
//         005400b4     MOV        this,EDX
//         005400b6     LEA        EDI=>valid_target_count[1],[ESP + 0x34]
//         005400ba     SHR        this,0x2
//         005400bd     STOSD.REP  ES:EDI
//                               LAB_005400bf                                                 XREF[1]:     0054009b(j)
//         005400bf     XOR        EDX,EDX
//         005400c1     CMP        word ptr [ESP + local_21e],DX
//         005400c6     MOV        dword ptr [ESP + j],EDX
//         005400ca     JLE        LAB_005402e3
//                               LAB_005400d0                                                 XREF[1]:     005402dd(j)
//                              vw_main.cpp:1747 (4)
//         005400d0     MOV        this,dword ptr [ESP + i]
//                              vw_main.cpp:1748 (26)
//         005400d4     MOV        dword ptr [ESP + target_count],0x0
//         005400dc     TEST       EBP,EBP
//         005400de     MOV        EAX,dword ptr [this->_padding_ + EDX*0x4]
//         005400e1     MOV        EDI,dword ptr [EAX + 0x8]
//         005400e4     MOV        dword ptr [ESP + local_208],EDI
//         005400e8     JLE        LAB_005402d1
//                              vw_main.cpp:1747 (22)
//         005400ee     MOV        dword ptr [ESP + Stack[-0x224]],DAT_0087d4a4
//         005400f6     JMP        LAB_00540104
//                               LAB_005400f8                                                 XREF[1]:     005402c3(j)
//         005400f8     MOV        EDI,dword ptr [ESP + 0x2c]
//         005400fc     MOV        EDX,dword ptr [ESP + 0x20]
//         00540100     MOV        EBX,dword ptr [ESP + 0x18]
//                               LAB_00540104                                                 XREF[1]:     005400f6(j)
//                              vw_main.cpp:1750 (15)
//         00540104     MOV        this,dword ptr [ESP + Stack[-0x224]]
//         00540108     MOV        EAX,dword ptr [this->_padding_ + -0x4]=>Picked   = 00000000
//         0054010b     TEST       EAX,EAX
//         0054010d     JL         LAB_005402a9
//                              vw_main.cpp:1752 (15)
//         00540113     MOV        this,dword ptr [EBX + 0xfc]
//         00540119     MOV        this,dword ptr [ECX + this->_padding_]
//         0054011f     MOV        EBP,dword ptr [this->_padding_ + EAX*0x4]
//                              vw_main.cpp:1753 (18)
//         00540122     TEST       EBP,EBP
//         00540124     JZ         LAB_005402a9
//         0054012a     CMP        byte ptr [EBP + 0x48],0x7
//         0054012e     JNC        LAB_005402a9
//                              vw_main.cpp:1755 (28)
//         00540134     MOV        ESI,dword ptr [ESP + i]
//         00540138     MOV        this,dword ptr [EDI + 0xd8]
//         0054013e     PUSH       0x0
//         00540140     PUSH       0x0=>DAT_fffffff8
//         00540142     MOV        EDX,dword ptr [ESI + EDX*0x4]
//         00540145     MOV        EAX,dword ptr [this->_padding_]
//         00540147     PUSH       0x0
//         00540149     PUSH       EBP
//         0054014a     PUSH       EDX
//         0054014b     CALL       dword ptr [EAX + 0x4]
//         0054014e     MOV        ESI,EAX
//                              vw_main.cpp:1756 (24)
//         00540150     TEST       ESI,ESI
//         00540152     JZ         LAB_005401b7
//         00540154     MOV        AX,word ptr [ESP + 0x244]
//         0054015c     CMP        AX,0xffff
//         00540160     JZ         LAB_0054016a
//         00540162     CMP        word ptr [ESI + 0x6],AX
//         00540166     JZ         LAB_0054016a
//                              vw_main.cpp:1757 (2)
//         00540168     XOR        ESI,ESI
//                               LAB_0054016a                                                 XREF[2]:     00540160(j), 00540166(j)
//                              vw_main.cpp:1758 (8)
//         0054016a     TEST       ESI,ESI
//         0054016c     JZ         LAB_005401b7
//         0054016e     MOV        EAX,dword ptr [ESP + 0x24]
//                              vw_main.cpp:1760 (34)
//         00540172     MOV        EDX,dword ptr [EBX]
//         00540174     LEA        this,[EAX*0x4 + 0x0]
//         0054017b     MOV        EAX,dword ptr [ESP + 0x10]
//         0054017f     MOV        dword ptr [ESP + 0x30],this
//         00540183     MOVSX      this,word ptr [EAX]
//         00540186     PUSH       this
//         00540187     PUSH       EBP=>DAT_fffffff8
//         00540188     MOV        this,EBX
//         0054018a     CALL       dword ptr [EDX + 0xe4]
//         00540190     MOV        EBX,dword ptr [ESP + 0x30]
//                              vw_main.cpp:1761 (30)
//         00540194     MOV        this,dword ptr [EDI + 0xd8]
//         0054019a     PUSH       ESI
//         0054019b     MOV        EBP,dword ptr [ESP + EBX*0x1 + 0x38]
//         0054019f     MOV        EDX,dword ptr [this->_padding_]
//         005401a1     ADD        EBP,EAX
//         005401a3     MOV        dword ptr [ESP + EBX*0x1 + 0x38],EBP
//         005401a7     CALL       dword ptr [EDX + 0x8]
//         005401aa     TEST       EAX,EAX
//         005401ac     JZ         LAB_005402a9
//                              vw_main.cpp:1764 (19)
//         005401b2     JMP        LAB_0054029e
//                               LAB_005401b7                                                 XREF[2]:     00540152(j), 0054016c(j)
//         005401b7     MOV        AL,byte ptr [EDI + 0xec]
//         005401bd     TEST       AL,AL
//         005401bf     JZ         LAB_005402a9
//                              vw_main.cpp:1768 (22)
//         005401c5     MOV        EAX,dword ptr [ESP + 0x18]
//         005401c9     XOR        EBX,EBX
//         005401cb     MOV        EAX,dword ptr [EAX + 0x100]
//         005401d1     CMP        word ptr [EAX + 0x22],BX
//         005401d5     JLE        LAB_005402a9
//                               LAB_005401db                                                 XREF[1]:     0054025c(j)
//                              vw_main.cpp:1770 (6)
//         005401db     MOV        this,dword ptr [EAX + 0x24]
//         005401de     MOV        EDI,dword ptr [this->_padding_ + EBX*0x4]
//                              vw_main.cpp:1774 (44)
//         005401e1     TEST       EDI,EDI
//         005401e3     JZ         LAB_0054024b
//         005401e5     MOV        EAX,dword ptr [ESP + 0x2c]
//         005401e9     MOV        DX,word ptr [EDI + 0x14]
//         005401ed     CMP        DX,word ptr [EAX + 0x14]
//         005401f1     JNZ        LAB_0054024b
//         005401f3     MOV        this,byte ptr [EDI + 0x4]
//         005401f6     MOV        DL,byte ptr [EAX + 0x4]
//         005401f9     CMP        this,DL
//         005401fb     JNZ        LAB_0054024b
//         005401fd     MOV        DL,byte ptr [EDI + 0xec]
//         00540203     MOV        this,byte ptr [EAX + 0xec]
//         00540209     CMP        DL,this
//         0054020b     JNZ        LAB_0054024b
//                              vw_main.cpp:1776 (32)
//         0054020d     MOV        EDX,dword ptr [ESP + 0x1c]
//         00540211     MOV        ESI,dword ptr [ESP + 0x20]
//         00540215     MOV        this,dword ptr [EDI + 0xd8]
//         0054021b     PUSH       0x0
//         0054021d     MOV        EDX,dword ptr [EDX + ESI*0x4]
//         00540220     PUSH       0x0=>DAT_fffffff8
//         00540222     MOV        EAX,dword ptr [this->_padding_]
//         00540224     PUSH       0x0=>DAT_fffffff4
//         00540226     PUSH       EBP=>DAT_fffffff0
//         00540227     PUSH       EDX
//         00540228     CALL       dword ptr [EAX + 0x4]
//         0054022b     MOV        ESI,EAX
//                              vw_main.cpp:1777 (24)
//         0054022d     TEST       ESI,ESI
//         0054022f     JZ         LAB_0054024b
//         00540231     MOV        AX,word ptr [ESP + 0x244]
//         00540239     CMP        AX,0xffff
//         0054023d     JZ         LAB_00540247
//         0054023f     CMP        word ptr [ESI + 0x6],AX
//         00540243     JZ         LAB_00540247
//                              vw_main.cpp:1778 (2)
//         00540245     XOR        ESI,ESI
//                               LAB_00540247                                                 XREF[2]:     0054023d(j), 00540243(j)
//                              vw_main.cpp:1779 (4)
//         00540247     TEST       ESI,ESI
//         00540249     JNZ        LAB_00540264
//                               LAB_0054024b                                                 XREF[5]:     005401e3(j), 005401f1(j),
//                                                                                                         005401fb(j), 0054020b(j),
//                                                                                                         0054022f(j)
//                              vw_main.cpp:1768 (25)
//         0054024b     MOV        EAX,dword ptr [ESP + 0x18]
//         0054024f     INC        EBX
//         00540250     MOV        EAX,dword ptr [EAX + 0x100]
//         00540256     MOVSX      this,word ptr [EAX + 0x22]
//         0054025a     CMP        EBX,this
//         0054025c     JL         LAB_005401db
//         00540262     JMP        LAB_005402a9
//                               LAB_00540264                                                 XREF[1]:     00540249(j)
//                              vw_main.cpp:1748 (4)
//         00540264     MOV        EDX,dword ptr [ESP + 0x24]
//                              vw_main.cpp:1781 (32)
//         00540268     MOV        this,dword ptr [ESP + 0x18]
//         0054026c     LEA        EBX,[EDX*0x4 + 0x0]
//         00540273     MOV        EDX,dword ptr [ESP + 0x10]
//         00540277     MOV        EAX,dword ptr [this->_padding_]
//         00540279     MOVSX      EDX,word ptr [EDX]
//         0054027c     PUSH       EDX
//         0054027d     PUSH       EBP=>DAT_fffffff8
//         0054027e     CALL       dword ptr [EAX + 0xe4]
//         00540284     MOV        EBP,dword ptr [ESP + EBX*0x1 + 0x34]
//                              vw_main.cpp:1782 (22)
//         00540288     MOV        this,dword ptr [EDI + 0xd8]
//         0054028e     ADD        EBP,EAX
//         00540290     PUSH       ESI
//         00540291     MOV        EAX,dword ptr [this->_padding_]
//         00540293     MOV        dword ptr [ESP + EBX*0x1 + 0x38],EBP
//         00540297     CALL       dword ptr [EAX + 0x8]
//         0054029a     TEST       EAX,EAX
//         0054029c     JZ         LAB_005402a9
//                               LAB_0054029e                                                 XREF[1]:     005401b2(j)
//                              vw_main.cpp:1783 (11)
//         0054029e     MOV        dword ptr [ESP + EBX*0x1 + 0x134],0x1
//                               LAB_005402a9                                                 XREF[8]:     0054010d(j), 00540124(j),
//                                                                                                         0054012e(j), 005401ac(j),
//                                                                                                         005401bf(j), 005401d5(j),
//                                                                                                         00540262(j), 0054029c(j)
//                              vw_main.cpp:1748 (58)
//         005402a9     MOV        EAX,dword ptr [ESP + 0x24]
//         005402ad     MOV        EDX,dword ptr [ESP + 0x10]
//         005402b1     MOV        EBP,dword ptr [ESP + 0x28]
//         005402b5     INC        EAX
//         005402b6     ADD        EDX,0xc
//         005402b9     CMP        EAX,EBP
//         005402bb     MOV        dword ptr [ESP + 0x24],EAX
//         005402bf     MOV        dword ptr [ESP + 0x10],EDX
//         005402c3     JL         LAB_005400f8
//         005402c9     MOV        EDX,dword ptr [ESP + 0x20]
//         005402cd     MOV        EBX,dword ptr [ESP + 0x18]
//                               LAB_005402d1                                                 XREF[1]:     005400e8(j)
//         005402d1     MOVSX      this,word ptr [ESP + 0x16]
//         005402d6     INC        EDX
//         005402d7     CMP        EDX,this
//         005402d9     MOV        dword ptr [ESP + 0x20],EDX
//         005402dd     JL         LAB_005400d0
//                               LAB_005402e3                                                 XREF[1]:     005400ca(j)
//                              vw_main.cpp:1795 (13)
//         005402e3     MOV        EDX,dword ptr [ESP + i]
//         005402e7     PUSH       EDX
//         005402e8     CALL       free                                             undefined free()
//         005402ed     ADD        ESP,0x4
//                              vw_main.cpp:1798 (2)
//         005402f0     XOR        ESI,ESI
//                              vw_main.cpp:1799 (2)
//         005402f2     XOR        EAX,EAX
//                              vw_main.cpp:1800 (6)
//         005402f4     XOR        this,this
//         005402f6     TEST       EBP,EBP
//         005402f8     JLE        LAB_0054033a
//                              vw_main.cpp:1795 (5)
//         005402fa     MOV        EDI,Picked_Objects                               = 00000000
//                               LAB_005402ff                                                 XREF[1]:     00540338(j)
//                              vw_main.cpp:1802 (8)
//         005402ff     MOV        EDX,dword ptr [ESP + this->_padding_*0x4 + 0x34]
//         00540303     CMP        EDX,ESI
//         00540305     JLE        LAB_00540332
//                              vw_main.cpp:1804 (17)
//         00540307     MOV        EAX,dword ptr [EBX + 0xfc]
//         0054030d     MOV        ESI,dword ptr [EDI]=>Picked_Objects              = 00000000
//         0054030f     MOV        EAX,dword ptr [EAX + 0x88]
//         00540315     MOV        EAX,dword ptr [EAX + ESI*0x4]
//                              vw_main.cpp:1805 (11)
//         00540318     MOV        ESI,dword ptr [ESP + 0x240]
//         0054031f     TEST       ESI,ESI
//         00540321     JZ         LAB_00540330
//                              vw_main.cpp:1806 (13)
//         00540323     MOV        EBP,dword ptr [ESP + this->_padding_*0x4 + 0x1
//         0054032a     MOV        dword ptr [ESI],EBP
//         0054032c     MOV        EBP,dword ptr [ESP + 0x28]
//                               LAB_00540330                                                 XREF[1]:     00540321(j)
//                              vw_main.cpp:1807 (2)
//         00540330     MOV        ESI,EDX
//                               LAB_00540332                                                 XREF[1]:     00540305(j)
//                              vw_main.cpp:1800 (8)
//         00540332     INC        this
//         00540333     ADD        EDI,0xc
//         00540336     CMP        this,EBP
//         00540338     JL         LAB_005402ff
//                               LAB_0054033a                                                 XREF[1]:     005402f8(j)
//                              vw_main.cpp:1812 (13)
//         0054033a     POP        EDI
//         0054033b     POP        ESI
//         0054033c     POP        EBP
//         0054033d     POP        EBX
//         0054033e     ADD        ESP,0x224
//         00540344     RET        0x10
//         00540347     ??         90h
//         00540348     NOP
//         00540349     NOP
//         0054034a     NOP
//         0054034b     NOP
//         0054034c     NOP
//         0054034d     NOP
//         0054034e     NOP
//         0054034f     NOP
    return 0;
}

int RGE_Main_View::command_make_move(long param_1, long param_2) {
    /* TODO: Stub */
//                              int __thiscall command_make_move(RGE_Main_View * this, long param_1,
//              int               EAX:4          <RETURN>
//              RGE_Main_View *   ECX:4 (auto)   this
//              long              Stack[0x4]:4   param_1                   XREF[1]:     00540397(R)
//              long              Stack[0x8]:4   param_2                   XREF[1]:     00540393(R)
//              RGE_Pick_Info     Stack[-0x18]   pick_info                 XREF[2,5]:   00540370(*), 00540389(R), 005403a0(*), 005403b9(*),
//                                                                                     005403d0(R), 005403c5(R), 005403d7(R)
//              RGE_Static_Obj    Stack[-0x1c]:4 list                      XREF[0,1]:   0054036a(*)
//              short             Stack[-0x1e]:2 list_num
//                               ?command_make_move@RGE_Main_View@@UAEHJJ@Z                   XREF[2]:     00572bac(*), 005778f4(*)
//                               RGE_Main_View::command_make_move
//                              vw_main.cpp:1818 (14)
//         00540350     MOV        EAX,[allow_user_commands]                        = 1h
//         00540355     SUB        ESP,0x1c
//         00540358     TEST       EAX,EAX
//         0054035a     PUSH       ESI
//         0054035b     PUSH       EDI
//         0054035c     MOV        ESI,this
//                              vw_main.cpp:1824 (6)
//         0054035e     JZ         LAB_0054040b
//                              vw_main.cpp:1829 (37)
//         00540364     PUSH       -0x1
//         00540366     PUSH       -0x1
//         00540368     PUSH       -0x1
//         0054036a     LEA        EAX=>list+0x2,[ESP + 0x16]
//         0054036e     PUSH       -0x1
//         00540370     LEA        this=>pick_info,[ESP + 0x1c]
//         00540374     PUSH       EAX
//         00540375     PUSH       this
//         00540376     MOV        this,dword ptr [ESI + 0x100]
//         0054037c     CALL       RGE_Player::get_selected_objects_to_command      uchar get_selected_objects_to_command(RGE_Pla
//         00540381     TEST       AL,AL
//         00540383     JZ         LAB_0054040b
//                              vw_main.cpp:1830 (10)
//         00540389     MOV        EDX,dword ptr [ESP + pick_info.x]
//         0054038d     PUSH       EDX
//         0054038e     CALL       free                                             undefined free()
//                              vw_main.cpp:1836 (34)
//         00540393     MOV        this,dword ptr [ESP + param_2]
//         00540397     MOV        EDX,dword ptr [ESP + param_1]
//         0054039b     ADD        ESP,0x4
//         0054039e     XOR        EDI,EDI
//         005403a0     LEA        EAX=>pick_info.y,[ESP + 0x10]
//         005403a4     PUSH       0x1
//         005403a6     PUSH       EDI
//         005403a7     PUSH       EAX
//         005403a8     PUSH       this
//         005403a9     PUSH       EDX
//         005403aa     PUSH       0x1
//         005403ac     PUSH       0x2a
//         005403ae     MOV        this,ESI
//         005403b0     CALL       RGE_Main_View::pick1                             uchar pick1(RGE_Main_View * this, uchar param
//                              vw_main.cpp:1837 (4)
//         005403b5     CMP        AL,0x32
//         005403b7     JZ         LAB_005403f2
//                              vw_main.cpp:1839 (12)
//         005403b9     LEA        EAX=>pick_info.y,[ESP + 0x10]
//         005403bd     MOV        this,ESI
//         005403bf     PUSH       EAX
//         005403c0     CALL       RGE_Main_View::fixup_pick_info                   void fixup_pick_info(RGE_Main_View * this, RG
//                              vw_main.cpp:1840 (29)
//         005403c5     MOV        EAX,dword ptr [ESP + pick_info.scr_x]
//         005403c9     MOV        this,dword ptr [ESI + 0x100]
//         005403cf     PUSH       EAX
//         005403d0     MOV        EAX,dword ptr [ESP + pick_info.y]
//         005403d4     MOV        EDX,dword ptr [this->_padding_]
//         005403d6     PUSH       EAX
//         005403d7     MOV        EAX,dword ptr [ESP + pick_info.tile]
//         005403db     PUSH       EAX
//         005403dc     CALL       dword ptr [EDX + 0xa0]
//                              vw_main.cpp:1841 (16)
//         005403e2     MOV        EDX,dword ptr [ESI]
//         005403e4     AND        EAX,0xff
//         005403e9     PUSH       0x1
//         005403eb     MOV        this,ESI
//         005403ed     MOV        EDI,EAX
//         005403ef     CALL       dword ptr [EDX + 0x20]
//                               LAB_005403f2                                                 XREF[1]:     005403b7(j)
//                              vw_main.cpp:1844 (15)
//         005403f2     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         005403f8     PUSH       0x0
//         005403fa     PUSH       0x0=>DAT_fffffff8
//         005403fc     MOV        EAX,dword ptr [this->_padding_]
//         005403fe     CALL       dword ptr [EAX + 0x10]
//                              vw_main.cpp:1845 (2)
//         00540401     MOV        EAX,EDI
//                              vw_main.cpp:1846 (18)
//         00540403     POP        EDI
//         00540404     POP        ESI
//         00540405     ADD        ESP,0x1c
//         00540408     RET        0x8
//                               LAB_0054040b                                                 XREF[2]:     0054035e(j), 00540383(j)
//         0054040b     POP        EDI
//         0054040c     XOR        EAX,EAX
//         0054040e     POP        ESI
//         0054040f     ADD        ESP,0x1c
//         00540412     RET        0x8
//         00540415     ??         90h
//         00540416     NOP
//         00540417     NOP
//         00540418     NOP
//         00540419     NOP
//         0054041a     NOP
//         0054041b     NOP
//         0054041c     NOP
//         0054041d     NOP
//         0054041e     NOP
//         0054041f     NOP
    return 0;
}

int RGE_Main_View::command_make_work(long param_1, long param_2) {
    /* TODO: Stub */
//                              int __thiscall command_make_work(RGE_Main_View * this, long param_1,
//              int               EAX:4          <RETURN>
//              RGE_Main_View *   ECX:4 (auto)   this
//              long              Stack[0x4]:4   param_1                   XREF[1]:     00540469(R)
//              long              Stack[0x8]:4   param_2                   XREF[1]:     00540465(R)
//              RGE_Pick_Info     Stack[-0x18]   pick_info                 XREF[1,4]:   00540470(*), 005404e7(*), 00540503(*), 0054051a(R),
//                                                                                     0054050f(R)
//              int               Stack[-0x1c]:4 attacking                 XREF[2]:     00540442(*), 0054045b(R)
//              RGE_Static_Obj    Stack[-0x20]:4 list                      XREF[0,1]:   0054043c(*)
//              short             Stack[-0x22]:2 list_num
//                               ?command_make_work@RGE_Main_View@@UAEHJJ@Z                   XREF[2]:     00572bb0(*), 005778f8(*)
//                               RGE_Main_View::command_make_work
//                              vw_main.cpp:1852 (16)
//         00540420     MOV        EAX,[allow_user_commands]                        = 1h
//         00540425     SUB        ESP,0x20
//         00540428     TEST       EAX,EAX
//         0054042a     PUSH       EBX
//         0054042b     PUSH       EBP
//         0054042c     PUSH       ESI
//         0054042d     PUSH       EDI
//         0054042e     MOV        ESI,this
//                              vw_main.cpp:1859 (6)
//         00540430     JZ         LAB_005405b0
//                              vw_main.cpp:1864 (37)
//         00540436     PUSH       -0x1
//         00540438     PUSH       -0x1
//         0054043a     PUSH       -0x1
//         0054043c     LEA        EAX=>list+0x2,[ESP + 0x1e]
//         00540440     PUSH       -0x1
//         00540442     LEA        this=>attacking,[ESP + 0x24]
//         00540446     PUSH       EAX
//         00540447     PUSH       this
//         00540448     MOV        this,dword ptr [ESI + 0x100]
//         0054044e     CALL       RGE_Player::get_selected_objects_to_command      uchar get_selected_objects_to_command(RGE_Pla
//         00540453     TEST       AL,AL
//         00540455     JZ         LAB_005405b0
//                              vw_main.cpp:1865 (10)
//         0054045b     MOV        EDX,dword ptr [ESP + attacking]
//         0054045f     PUSH       EDX
//         00540460     CALL       free                                             undefined free()
//                              vw_main.cpp:1869 (29)
//         00540465     MOV        EBX,dword ptr [ESP + param_2]
//         00540469     MOV        EBP,dword ptr [ESP + param_1]
//         0054046d     ADD        ESP,0x4
//         00540470     LEA        EAX=>pick_info,[ESP + 0x18]
//         00540474     MOV        this,ESI
//         00540476     PUSH       -0x1
//         00540478     PUSH       EAX
//         00540479     PUSH       EBX
//         0054047a     PUSH       EBP
//         0054047b     CALL       RGE_Main_View::pick_best_target                  RGE_Static_Object * pick_best_target(RGE_Main
//         00540480     MOV        EDI,EAX
//                              vw_main.cpp:1870 (4)
//         00540482     TEST       EDI,EDI
//         00540484     JZ         LAB_005404e5
//                              vw_main.cpp:1872 (30)
//         00540486     MOV        EAX,dword ptr [EDI + 0x3c]
//         00540489     MOV        this,dword ptr [ESI + 0x100]
//         0054048f     PUSH       EAX
//         00540490     MOV        EAX,dword ptr [EDI + 0x38]
//         00540493     MOV        EDX,dword ptr [this->_padding_]
//         00540495     PUSH       EAX
//         00540496     PUSH       EDI
//         00540497     CALL       dword ptr [EDX + 0xa4]
//         0054049d     AND        EAX,0xff
//         005404a2     MOV        EBX,EAX
//                              vw_main.cpp:1874 (2)
//         005404a4     JZ         LAB_005404ba
//                              vw_main.cpp:1878 (20)
//         005404a6     MOV        this,dword ptr [EDI + 0x4]
//         005404a9     PUSH       0x2
//         005404ab     PUSH       offset DAT_fffffff8
//         005404ad     PUSH       offset DAT_fffffff4
//         005404b2     PUSH       this=>DAT_fffffff0
//         005404b3     MOV        this,ESI
//         005404b5     CALL       RGE_View::display_object_selection               void display_object_selection(RGE_View * this
//                               LAB_005404ba                                                 XREF[1]:     005404a4(j)
//                              vw_main.cpp:1881 (7)
//         005404ba     MOV        this,ESI
//         005404bc     CALL       RGE_View::reset_overlay_sprites                  void reset_overlay_sprites(RGE_View * this)
//                              vw_main.cpp:1882 (9)
//         005404c1     MOV        EDX,dword ptr [ESI]
//         005404c3     PUSH       0x1
//         005404c5     MOV        this,ESI
//         005404c7     CALL       dword ptr [EDX + 0x20]
//                              vw_main.cpp:1883 (15)
//         005404ca     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         005404d0     PUSH       0x0
//         005404d2     PUSH       0x0=>DAT_fffffff8
//         005404d4     MOV        EAX,dword ptr [this->_padding_]
//         005404d6     CALL       dword ptr [EAX + 0x10]
//                              vw_main.cpp:1884 (2)
//         005404d9     MOV        EAX,EBX
//                              vw_main.cpp:1909 (10)
//         005404db     POP        EDI
//         005404dc     POP        ESI
//         005404dd     POP        EBP
//         005404de     POP        EBX
//         005404df     ADD        ESP,0x20
//         005404e2     RET        0x8
//                               LAB_005404e5                                                 XREF[1]:     00540484(j)
//                              vw_main.cpp:1887 (30)
//         005404e5     PUSH       0x1
//         005404e7     LEA        this=>pick_info.y,[ESP + 0x20]
//         005404eb     PUSH       0x0
//         005404ed     PUSH       this
//         005404ee     PUSH       EBX
//         005404ef     PUSH       EBP
//         005404f0     PUSH       0x0
//         005404f2     PUSH       0x28
//         005404f4     MOV        this,ESI
//         005404f6     CALL       RGE_Main_View::pick1                             uchar pick1(RGE_Main_View * this, uchar param
//         005404fb     CMP        AL,0x33
//         005404fd     JNZ        LAB_00540591
//                              vw_main.cpp:1889 (12)
//         00540503     LEA        EDX=>pick_info.y,[ESP + 0x1c]
//         00540507     MOV        this,ESI
//         00540509     PUSH       EDX
//         0054050a     CALL       RGE_Main_View::fixup_pick_info                   void fixup_pick_info(RGE_Main_View * this, RG
//                              vw_main.cpp:1890 (33)
//         0054050f     MOV        EDX,dword ptr [ESP + pick_info.scr_x]
//         00540513     MOV        this,dword ptr [ESI + 0x100]
//         00540519     PUSH       EDX
//         0054051a     MOV        EDX,dword ptr [ESP + pick_info.y]
//         0054051e     MOV        EAX,dword ptr [this->_padding_]
//         00540520     PUSH       EDX
//         00540521     PUSH       0x0
//         00540523     CALL       dword ptr [EAX + 0xa4]
//         00540529     AND        EAX,0xff
//         0054052e     MOV        EDI,EAX
//                              vw_main.cpp:1893 (2)
//         00540530     JZ         LAB_0054056d
//                              vw_main.cpp:1895 (9)
//         00540532     PUSH       0x2
//         00540534     MOV        this,ESI
//         00540536     CALL       RGE_Main_View::reset_display_object_selection    void reset_display_object_selection(RGE_Main_
//                              vw_main.cpp:1896 (50)
//         0054053b     MOV        EAX,dword ptr [ESI + 0x134]
//         00540541     MOV        EDX,dword ptr [rge_base_game]                    = 00000000
//         00540547     MOV        this,dword ptr [ESI + 0x130]
//         0054054d     PUSH       0x5a
//         0054054f     PUSH       offset DAT_fffffff8
//         00540551     PUSH       0x0=>DAT_fffffff4
//         00540553     PUSH       offset DAT_fffffff0
//         00540555     ADD        EAX,EBX
//         00540557     PUSH       0x0
//         00540559     PUSH       EAX
//         0054055a     MOV        EAX,dword ptr [EDX + 0x5c]
//         0054055d     ADD        this,EBP
//         0054055f     PUSH       this
//         00540560     PUSH       0x0
//         00540562     MOV        this,dword ptr [EAX + 0x8]
//         00540565     PUSH       this
//         00540566     MOV        this,ESI
//         00540568     CALL       RGE_View::add_overlay_sprite                     void add_overlay_sprite(RGE_View * this, TSha
//                               LAB_0054056d                                                 XREF[1]:     00540530(j)
//                              vw_main.cpp:1899 (9)
//         0054056d     MOV        EDX,dword ptr [ESI]
//         0054056f     PUSH       0x1
//         00540571     MOV        this,ESI
//         00540573     CALL       dword ptr [EDX + 0x20]
//                              vw_main.cpp:1900 (15)
//         00540576     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0054057c     PUSH       0x0
//         0054057e     PUSH       0x0=>DAT_fffffff8
//         00540580     MOV        EAX,dword ptr [this->_padding_]
//         00540582     CALL       dword ptr [EAX + 0x10]
//                              vw_main.cpp:1901 (2)
//         00540585     MOV        EAX,EDI
//                              vw_main.cpp:1909 (10)
//         00540587     POP        EDI
//         00540588     POP        ESI
//         00540589     POP        EBP
//         0054058a     POP        EBX
//         0054058b     ADD        ESP,0x20
//         0054058e     RET        0x8
//                               LAB_00540591                                                 XREF[1]:     005404fd(j)
//                              vw_main.cpp:1904 (7)
//         00540591     MOV        this,ESI
//         00540593     CALL       RGE_View::reset_overlay_sprites                  void reset_overlay_sprites(RGE_View * this)
//                              vw_main.cpp:1905 (9)
//         00540598     MOV        EDX,dword ptr [ESI]
//         0054059a     PUSH       0x1
//         0054059c     MOV        this,ESI
//         0054059e     CALL       dword ptr [EDX + 0x20]
//                              vw_main.cpp:1907 (15)
//         005405a1     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         005405a7     PUSH       0x0
//         005405a9     PUSH       0x0=>DAT_fffffff8
//         005405ab     MOV        EAX,dword ptr [this->_padding_]
//         005405ad     CALL       dword ptr [EAX + 0x10]
//                               LAB_005405b0                                                 XREF[2]:     00540430(j), 00540455(j)
//                              vw_main.cpp:1909 (12)
//         005405b0     POP        EDI
//         005405b1     POP        ESI
//         005405b2     POP        EBP
//         005405b3     XOR        EAX,EAX
//         005405b5     POP        EBX
//         005405b6     ADD        ESP,0x20
//         005405b9     RET        0x8
//         005405bc     ??         90h
//         005405bd     NOP
//         005405be     NOP
//         005405bf     NOP
    return 0;
}

int RGE_Main_View::command_place_multi_object(long param_1, long param_2, long param_3, long param_4, int param_5) {
    /* TODO: Stub */
//                              int __thiscall command_place_multi_object(RGE_Main_View * this, long
//              int               EAX:4          <RETURN>
//              RGE_Main_View *   ECX:4 (auto)   this
//              long              Stack[0x4]:4   param_1
//              long              Stack[0x8]:4   param_2
//              long              Stack[0xc]:4   param_3
//              long              Stack[0x10]:4  param_4
//              int               Stack[0x14]:4  param_5
//                               ?command_place_multi_object@RGE_Main_View@@UAEHJJJJH@Z       XREF[1]:     005778fc(*)
//                               RGE_Main_View::command_place_multi_object
//                              vw_main.cpp:1915 (1)
//         005405c0     PUSH       ESI
//                              vw_main.cpp:1916 (15)
//         005405c1     PUSH       -0x1
//         005405c3     PUSH       -0x1
//         005405c5     PUSH       -0x1
//         005405c7     MOV        ESI,this
//         005405c9     PUSH       -0x1
//         005405cb     CALL       RGE_View::set_selection_area                     void set_selection_area(RGE_View * this, long
//                              vw_main.cpp:1917 (9)
//         005405d0     MOV        EAX,dword ptr [ESI]
//         005405d2     PUSH       0x1
//         005405d4     MOV        this,ESI
//         005405d6     CALL       dword ptr [EAX + 0x20]
//                              vw_main.cpp:1919 (2)
//         005405d9     XOR        EAX,EAX
//                              vw_main.cpp:1920 (4)
//         005405db     POP        ESI
//         005405dc     RET        0x14
//         005405df     ??         90h
    return 0;
}

uchar RGE_Main_View::get_help_info(char** param_1, long* param_2, long param_3, long param_4) {
    /* TODO: Stub */
//                              uchar __thiscall get_help_info(RGE_Main_View * this, char * * param_
//              uchar             AL:1           <RETURN>
//              RGE_Main_View *   ECX:4 (auto)   this
//              char * *          Stack[0x4]:4   param_1                   XREF[2]:     00540625(R), 00540660(R)
//              long *            Stack[0x8]:4   param_2                   XREF[2]:     0054064b(R), 0054065c(R)
//              long              Stack[0xc]:4   param_3                   XREF[1]:     005405e8(R)
//              long              Stack[0x10]:4  param_4                   XREF[1]:     005405ee(R)
//              RGE_Pick_Info     Stack[-0x18]   pick_info                 XREF[0,3]:   005405e3(*), 00540608(R), 0054063f(R)
//                               ?get_help_info@RGE_Main_View@@MAEEAAPADAAJJJ@Z               XREF[2]:     00572b74(*), 005778bc(*)
//                               RGE_Main_View::get_help_info
//                              vw_main.cpp:1926 (3)
//         005405e0     SUB        ESP,0x14
//                              vw_main.cpp:1930 (33)
//         005405e3     LEA        EAX=>pick_info.y,[ESP]
//         005405e7     PUSH       EBX
//         005405e8     MOV        EBX,dword ptr [ESP + param_3]
//         005405ec     PUSH       ESI
//         005405ed     PUSH       EDI
//         005405ee     MOV        EDI,dword ptr [ESP + param_4]
//         005405f2     PUSH       0x1
//         005405f4     PUSH       0x0
//         005405f6     PUSH       EAX
//         005405f7     PUSH       EDI
//         005405f8     PUSH       EBX
//         005405f9     PUSH       0x2
//         005405fb     MOV        ESI,this
//         005405fd     PUSH       0x29
//         005405ff     CALL       RGE_Main_View::pick1                             uchar pick1(RGE_Main_View * this, uchar param
//                              vw_main.cpp:1932 (4)
//         00540604     CMP        AL,0x34
//         00540606     JNZ        LAB_0054065c
//                              vw_main.cpp:1934 (55)
//         00540608     MOV        this,dword ptr [ESP + pick_info.tile]
//         0054060c     MOV        this,dword ptr [ECX + this->_padding_]
//         0054060f     CALL       RGE_Master_Static_Object::get_help_message       long get_help_message(RGE_Master_Static_Objec
//         00540614     PUSH       EAX
//         00540615     MOV        this,ESI
//         00540617     CALL       TPanel::get_string                               char * get_string(TPanel * this, int param_1)
//         0054061c     MOV        EDI,EAX
//         0054061e     OR         this,0xffffffff
//         00540621     XOR        EAX,EAX
//         00540623     SCASB.RE   ES:EDI
//         00540625     MOV        EAX,dword ptr [ESP + param_1]
//         00540629     NOT        this
//         0054062b     SUB        EDI,this
//         0054062d     MOV        EDX,this
//         0054062f     MOV        ESI,EDI
//         00540631     MOV        EDI,dword ptr [EAX]
//         00540633     SHR        this,0x2
//         00540636     MOVSD.REP  ES:EDI,ESI
//         00540638     MOV        this,EDX
//         0054063a     AND        this,0x3
//         0054063d     MOVSB.REP  ES:EDI,ESI
//                              vw_main.cpp:1935 (18)
//         0054063f     MOV        this,dword ptr [ESP + pick_info.tile]
//         00540643     MOV        this,dword ptr [ECX + this->_padding_]
//         00540646     CALL       RGE_Master_Static_Object::get_help_page          long get_help_page(RGE_Master_Static_Object *
//         0054064b     MOV        EDX,dword ptr [ESP + param_2]
//         0054064f     MOV        dword ptr [EDX],EAX
//                              vw_main.cpp:1936 (2)
//         00540651     MOV        AL,0x1
//                              vw_main.cpp:1940 (9)
//         00540653     POP        EDI
//         00540654     POP        ESI
//         00540655     POP        EBX
//         00540656     ADD        ESP,0x14
//         00540659     RET        0x10
//                               LAB_0054065c                                                 XREF[1]:     00540606(j)
//                              vw_main.cpp:1939 (19)
//         0054065c     MOV        EAX,dword ptr [ESP + param_2]
//         00540660     MOV        this,dword ptr [ESP + param_1]
//         00540664     PUSH       EDI
//         00540665     PUSH       EBX
//         00540666     PUSH       EAX
//         00540667     PUSH       this
//         00540668     MOV        this,ESI
//         0054066a     CALL       TPanel::get_help_info                            uchar get_help_info(TPanel * this, char * * p
//                              vw_main.cpp:1940 (9)
//         0054066f     POP        EDI
//         00540670     POP        ESI
//         00540671     POP        EBX
//         00540672     ADD        ESP,0x14
//         00540675     RET        0x10
//         00540678     ??         90h
//         00540679     NOP
//         0054067a     NOP
//         0054067b     NOP
//         0054067c     NOP
//         0054067d     NOP
//         0054067e     NOP
//         0054067f     NOP
    return 0;
}

void RGE_Main_View::fixup_pick_info(RGE_Pick_Info* param_1) {
    /* TODO: Stub */
//                              void __thiscall fixup_pick_info(RGE_Main_View * this, RGE_Pick_Info
//              void              <VOID>         <RETURN>
//              RGE_Main_View *   ECX:4 (auto)   this
//              RGE_Pick_Info *   Stack[0x4]:4   param_1                   XREF[1]:     00540680(R)
//                               ?fixup_pick_info@RGE_Main_View@@IAEXPAURGE_Pick_Info@@@Z     XREF[13]:    draw_multi_object_outline:0052cbc5
//                               RGE_Main_View::fixup_pick_info                                            command_place_object:0052d25c(c),
//                                                                                                         mouse_left_up_action:0052d6a4(c),
//                                                                                                         mouse_left_up_action:0052d8e2(c),
//                                                                                                         mouse_right_up_action:0052da14(c),
//                                                                                                         mouse_right_up_action:0052dc52(c),
//                                                                                                         mouse_left_down_action:0053e4e3(c)
//                                                                                                         mouse_left_up_action:0053f157(c),
//                                                                                                         mouse_right_up_action:0053f57e(c),
//                                                                                                         command_place_object:0053f853(c),
//                                                                                                         command_make_do:0053fb19(c),
//                                                                                                         command_make_move:005403c0(c),
//                                                                                                         command_make_work:0054050a(c)
//                              vw_main.cpp:1946 (19)
//         00540680     MOV        EDX,dword ptr [ESP + param_1]
//         00540684     FLD        float ptr [EDX]
//         00540686     FCOMP      float ptr [DAT_00577908]
//         0054068c     FNSTSW     AX
//         0054068e     TEST       AH,0x1
//         00540691     JZ         LAB_0054069b
//                              vw_main.cpp:1948 (6)
//         00540693     MOV        dword ptr [EDX],0x0
//                              vw_main.cpp:1949 (20)
//         00540699     JMP        LAB_005406b9
//                               LAB_0054069b                                                 XREF[1]:     00540691(j)
//         0054069b     MOV        EAX,dword ptr [ECX + this->_padding_]
//         005406a1     FILD       dword ptr [EAX + 0x8]
//         005406a4     FCOM       float ptr [EDX]
//         005406a6     FNSTSW     AX
//         005406a8     TEST       AH,0x41
//         005406ab     JZ         LAB_005406b7
//                              vw_main.cpp:1950 (10)
//         005406ad     FSUB       float ptr [DAT_00577900]                         = align(2)
//         005406b3     FSTP       float ptr [EDX]
//         005406b5     JMP        LAB_005406b9
//                               LAB_005406b7                                                 XREF[1]:     005406ab(j)
//                              vw_main.cpp:1949 (2)
//         005406b7     FSTP       ST0
//                               LAB_005406b9                                                 XREF[2]:     00540699(j), 005406b5(j)
//                              vw_main.cpp:1952 (16)
//         005406b9     FLD        float ptr [EDX + 0x4]
//         005406bc     FCOMP      float ptr [DAT_00577908]
//         005406c2     FNSTSW     AX
//         005406c4     TEST       AH,0x1
//         005406c7     JZ         LAB_005406d3
//                              vw_main.cpp:1953 (7)
//         005406c9     MOV        dword ptr [EDX + 0x4],0x0
//                              vw_main.cpp:1956 (3)
//         005406d0     RET        0x4
//                               LAB_005406d3                                                 XREF[1]:     005406c7(j)
//                              vw_main.cpp:1954 (19)
//         005406d3     MOV        this,dword ptr [ECX + this->_padding_]
//         005406d9     FILD       dword ptr [ECX + this->_padding_]
//         005406dc     FCOM       float ptr [EDX + 0x4]
//         005406df     FNSTSW     AX
//         005406e1     TEST       AH,0x41
//         005406e4     JZ         LAB_005406f2
//                              vw_main.cpp:1955 (9)
//         005406e6     FSUB       float ptr [DAT_00577900]                         = align(2)
//         005406ec     FSTP       float ptr [EDX + 0x4]
//                              vw_main.cpp:1956 (3)
//         005406ef     RET        0x4
//                               LAB_005406f2                                                 XREF[1]:     005406e4(j)
//                              vw_main.cpp:1954 (2)
//         005406f2     FSTP       ST0
//                              vw_main.cpp:1956 (3)
//         005406f4     RET        0x4
//         005406f7     ??         90h
//         005406f8     NOP
//         005406f9     NOP
//         005406fa     NOP
//         005406fb     NOP
//         005406fc     NOP
//         005406fd     NOP
//         005406fe     NOP
//         005406ff     NOP
    return;
}

void RGE_Main_View::reset_display_object_selection(int param_1) {
    /* TODO: Stub */
//                              void __thiscall reset_display_object_selection(RGE_Main_View * this,
//              void              <VOID>         <RETURN>
//              RGE_Main_View *   ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     0054070e(R)
//                               ?reset_display_object_selection@RGE_Main_View@@QAEXH@Z       XREF[8]:     mouse_left_up_action:0052d6ca(c),
//                               RGE_Main_View::reset_display_object_selection                             mouse_left_up_action:0052d908(c),
//                                                                                                         mouse_right_up_action:0052da3a(c),
//                                                                                                         mouse_right_up_action:0052dc78(c),
//                                                                                                         mouse_left_up_action:0053f17d(c),
//                                                                                                         mouse_right_up_action:0053f5a4(c),
//                                                                                                         command_make_do:0053fb45(c),
//                                                                                                         command_make_work:00540536(c)
//                              vw_main.cpp:1963 (22)
//         00540700     MOV        EAX,dword ptr [ECX + this->_padding_]
//         00540706     PUSH       ESI
//         00540707     XOR        ESI,ESI
//         00540709     TEST       EAX,EAX
//         0054070b     JLE        LAB_00540744
//         0054070d     PUSH       EDI
//         0054070e     MOV        EDI,dword ptr [ESP + param_1]
//         00540712     PUSH       EBP
//         00540713     PUSH       EBX
//         00540714     XOR        EDX,EDX
//                               LAB_00540716                                                 XREF[1]:     0054073f(j)
//                              vw_main.cpp:1970 (8)
//         00540716     MOV        EAX,dword ptr [ECX + this->_padding_]
//         0054071c     ADD        EAX,EDX
//                              vw_main.cpp:1971 (5)
//         0054071e     CMP        dword ptr [EAX],0x1
//         00540721     JNZ        LAB_00540733
//                              vw_main.cpp:1973 (5)
//         00540723     CMP        dword ptr [EAX + 0x10],EDI
//         00540726     JNZ        LAB_00540733
//                              vw_main.cpp:1974 (28)
//         00540728     MOV        EBX,dword ptr [EAX + 0xc]
//         0054072b     MOV        EBP,dword ptr [EAX + 0x8]
//         0054072e     SUB        EBP,EBX
//         00540730     MOV        dword ptr [EAX + 0x8],EBP
//                               LAB_00540733                                                 XREF[2]:     00540721(j), 00540726(j)
//         00540733     MOV        EAX,dword ptr [ECX + this->_padding_]
//         00540739     INC        ESI
//         0054073a     ADD        EDX,0x14
//         0054073d     CMP        ESI,EAX
//         0054073f     JL         LAB_00540716
//         00540741     POP        EBX
//         00540742     POP        EBP
//         00540743     POP        EDI
//                               LAB_00540744                                                 XREF[1]:     0054070b(j)
//                              vw_main.cpp:1977 (4)
//         00540744     POP        ESI
//         00540745     RET        0x4
//         00540748     ??         90h
//         00540749     NOP
//         0054074a     NOP
//         0054074b     NOP
//         0054074c     NOP
//         0054074d     NOP
//         0054074e     NOP
//         0054074f     NOP
    return;
}

RGE_Main_View::~RGE_Main_View() {
    /* TODO: Stub */
//                              void __thiscall ~RGE_Main_View(RGE_Main_View * this)
//              void              <VOID>         <RETURN>
//              RGE_Main_View *   ECX:4 (auto)   this
//                               ??1RGE_Main_View@@UAE@XZ                                     XREF[1]:     `vector_deleting_destructor':0053d
//                               RGE_Main_View::~RGE_Main_View
//         0053db30     JMP        RGE_View::~RGE_View
//         0053db35     ??         90h
//         0053db36     NOP
//         0053db37     NOP
//         0053db38     NOP
//         0053db39     NOP
//         0053db3a     NOP
//         0053db3b     NOP
//         0053db3c     NOP
//         0053db3d     NOP
//         0053db3e     NOP
//         0053db3f     NOP
}

