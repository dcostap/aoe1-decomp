#include "common.h"
#include "tpnl_txl.h"

void TRIBE_Panel_Text_Line::set_info(uchar param_1, char* param_2, long param_3) {
    /* TODO: Stub */
    //                              void __thiscall set_info(TRIBE_Panel_Text_Line * this, uchar param_1
    //              void              <VOID>         <RETURN>
    //              TRIBE_Panel_Te    ECX:4 (auto)   this
    //              uchar             Stack[0x4]:1   param_1                   XREF[1]:     00520e30(R)  
    //              char *            Stack[0x8]:4   param_2                   XREF[1]:     00520e40(R)  
    //              long              Stack[0xc]:4   param_3                   XREF[2]:     00520e7d(R), 00520eb9(R)  
    //                               ?set_info@TRIBE_Panel_Text_Line@@QAEXEPADJ@Z
    //                               TRIBE_Panel_Text_Line::set_info
    //                              tpnl_txl.cpp:40 (91)
    //         00520e30     MOV        DL,byte ptr [ESP + param_1]
    //         00520e34     PUSH       EBX
    //         00520e35     PUSH       EBP
    //         00520e36     MOV        EBP,this
    //         00520e38     PUSH       ESI
    //         00520e39     PUSH       EDI
    //         00520e3a     MOV        AL,byte ptr [EBP + 0xf8]
    //         00520e40     MOV        EDI,dword ptr [ESP + param_2]
    //         00520e44     CMP        DL,AL
    //         00520e46     JNZ        LAB_00520e8b
    //         00520e48     LEA        ESI,[EBP + 0xf9]
    //         00520e4e     MOV        EAX,EDI
    //                               LAB_00520e50                                                 XREF[1]:     00520e6e(j)  
    //         00520e50     MOV        BL,byte ptr [EAX]
    //         00520e52     MOV        this,BL
    //         00520e54     CMP        BL,byte ptr [ESI]
    //         00520e56     JNZ        LAB_00520e74
    //         00520e58     TEST       this,this
    //         00520e5a     JZ         LAB_00520e70
    //         00520e5c     MOV        BL,byte ptr [EAX + 0x1]
    //         00520e5f     MOV        this,BL
    //         00520e61     CMP        BL,byte ptr [ESI + 0x1]
    //         00520e64     JNZ        LAB_00520e74
    //         00520e66     ADD        EAX,0x2
    //         00520e69     ADD        ESI,0x2
    //         00520e6c     TEST       this,this
    //         00520e6e     JNZ        LAB_00520e50
    //                               LAB_00520e70                                                 XREF[1]:     00520e5a(j)  
    //         00520e70     XOR        EAX,EAX
    //         00520e72     JMP        LAB_00520e79
    //                               LAB_00520e74                                                 XREF[2]:     00520e56(j), 00520e64(j)  
    //         00520e74     SBB        EAX,EAX
    //         00520e76     SBB        EAX,-0x1
    //                               LAB_00520e79                                                 XREF[1]:     00520e72(j)  
    //         00520e79     TEST       EAX,EAX
    //         00520e7b     JNZ        LAB_00520e8b
    //         00520e7d     MOV        EAX,dword ptr [ESP + param_3]
    //         00520e81     MOV        this,dword ptr [EBP + 0x1c4]
    //         00520e87     CMP        EAX,this
    //         00520e89     JZ         LAB_00520ec8
    //                               LAB_00520e8b                                                 XREF[2]:     00520e46(j), 00520e7b(j)  
    //                              tpnl_txl.cpp:44 (23)
    //         00520e8b     OR         this,0xffffffff
    //         00520e8e     XOR        EAX,EAX
    //         00520e90     MOV        byte ptr [EBP + 0xf8],DL
    //         00520e96     LEA        EDX,[EBP + 0xf9]
    //         00520e9c     SCASB.RE   ES:EDI
    //         00520e9e     NOT        this
    //         00520ea0     SUB        EDI,this
    //                              tpnl_txl.cpp:46 (38)
    //         00520ea2     PUSH       0x1
    //         00520ea4     MOV        EAX,this
    //         00520ea6     MOV        ESI,EDI
    //         00520ea8     MOV        EDI,EDX
    //         00520eaa     MOV        EDX,dword ptr [EBP]
    //         00520ead     SHR        this,0x2
    //         00520eb0     MOVSD.REP  ES:EDI,ESI
    //         00520eb2     MOV        this,EAX
    //         00520eb4     AND        this,0x3
    //         00520eb7     MOVSB.REP  ES:EDI,ESI
    //         00520eb9     MOV        this,dword ptr [ESP + param_3]
    //         00520ebd     MOV        dword ptr [EBP + 0x1c4],this
    //         00520ec3     MOV        this,EBP
    //         00520ec5     CALL       dword ptr [EDX + 0x20]
    //                               LAB_00520ec8                                                 XREF[1]:     00520e89(j)  
    //                              tpnl_txl.cpp:47 (7)
    //         00520ec8     POP        EDI
    //         00520ec9     POP        ESI
    //         00520eca     POP        EBP
    //         00520ecb     POP        EBX
    //         00520ecc     RET        0xc
    //         00520ecf     ??         90h
    return;
}

void TRIBE_Panel_Text_Line::draw() {
    /* TODO: Stub */
    //                              void __thiscall draw(TRIBE_Panel_Text_Line * this)
    //              void              <VOID>         <RETURN>
    //              TRIBE_Panel_Te    ECX:4 (auto)   this
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     00520f0e(W)  
    //                               ?draw@TRIBE_Panel_Text_Line@@UAEXXZ                          XREF[1]:     005770f8(*)  
    //                               TRIBE_Panel_Text_Line::draw
    //                              tpnl_txl.cpp:53 (4)
    //         00520ed0     PUSH       this
    //         00520ed1     PUSH       ESI
    //         00520ed2     MOV        ESI,this
    //                              tpnl_txl.cpp:56 (33)
    //         00520ed4     MOV        EAX,dword ptr [ESI + 0x20]
    //         00520ed7     TEST       EAX,EAX
    //         00520ed9     JZ         LAB_00520fb6
    //         00520edf     MOV        EAX,dword ptr [ESI + 0x70]
    //         00520ee2     TEST       EAX,EAX
    //         00520ee4     JZ         LAB_00520fb6
    //         00520eea     MOV        EAX,dword ptr [ESI + 0x6c]
    //         00520eed     TEST       EAX,EAX
    //         00520eef     JZ         LAB_00520fb6
    //                              tpnl_txl.cpp:59 (10)
    //         00520ef5     MOV        this,dword ptr [ESI + 0x40]
    //         00520ef8     PUSH       EDI
    //         00520ef9     PUSH       EBP
    //         00520efa     PUSH       EBX
    //         00520efb     TEST       this,this
    //         00520efd     JZ         LAB_00520f08
    //                              tpnl_txl.cpp:60 (9)
    //         00520eff     MOV        EAX,dword ptr [this->_padding_]
    //         00520f01     LEA        EDX,[ESI + 0x24]
    //         00520f04     PUSH       EDX
    //         00520f05     CALL       dword ptr [EAX + 0x34]
    //                               LAB_00520f08                                                 XREF[1]:     00520efd(j)  
    //                              tpnl_txl.cpp:62 (13)
    //         00520f08     MOV        EDI,dword ptr [ESI]
    //         00520f0a     PUSH       0x0
    //         00520f0c     MOV        this,ESI
    //         00520f0e     MOV        dword ptr [ESP + local_4],EDI
    //         00520f12     CALL       dword ptr [EDI + 0x28]
    //                              tpnl_txl.cpp:64 (21)
    //         00520f15     MOV        this,dword ptr [ESI + 0x20]
    //         00520f18     PUSH       s_tpnl_txl::draw                                 = "tpnl_txl::draw"
    //         00520f1d     CALL       TDrawArea::GetDc                                 void * GetDc(TDrawArea * this, char * param_1)
    //         00520f22     TEST       EAX,EAX
    //         00520f24     JZ         LAB_00520fae
    //                              tpnl_txl.cpp:66 (24)
    //         00520f2a     MOV        this,dword ptr [ESI + 0x20]
    //         00520f2d     MOV        EAX,dword ptr [ESI + 0xf4]
    //         00520f33     MOV        EBX,dword ptr [->GDI32.DLL::SelectObject]        = 0048b192
    //         00520f39     PUSH       EAX
    //         00520f3a     MOV        EDX,dword ptr [ECX + this->_padding_]
    //         00520f3d     PUSH       EDX=>DAT_fffffff8
    //         00520f3e     CALL       EBX=>GDI32.DLL::SelectObject
    //         00520f40     MOV        EBP,EAX
    //                              tpnl_txl.cpp:67 (15)
    //         00520f42     MOV        EAX,dword ptr [ESI + 0x20]
    //         00520f45     PUSH       0x1
    //         00520f47     MOV        this,dword ptr [EAX + 0x38]
    //         00520f4a     PUSH       this=>DAT_fffffff8
    //         00520f4b     CALL       dword ptr [->GDI32.DLL::SetBkMode]               = 0048b340
    //                              tpnl_txl.cpp:68 (15)
    //         00520f51     MOV        EDX,dword ptr [ESI + 0x20]
    //         00520f54     PUSH       0x0
    //         00520f56     MOV        EAX,dword ptr [EDX + 0x38]
    //         00520f59     PUSH       EAX=>DAT_fffffff8
    //         00520f5a     CALL       dword ptr [->GDI32.DLL::SetTextColor]            = 0048b318
    //                              tpnl_txl.cpp:70 (16)
    //         00520f60     MOV        AL,byte ptr [ESI + 0xf9]
    //         00520f66     LEA        EDX,[ESI + 0xf9]
    //         00520f6c     TEST       AL,AL
    //         00520f6e     JZ         LAB_00520f97
    //                              tpnl_txl.cpp:71 (39)
    //         00520f70     MOV        EDI,EDX
    //         00520f72     OR         this,0xffffffff
    //         00520f75     XOR        EAX,EAX
    //         00520f77     SCASB.RE   ES:EDI
    //         00520f79     MOV        EAX,dword ptr [ESI + 0x20]
    //         00520f7c     NOT        this
    //         00520f7e     DEC        this
    //         00520f7f     PUSH       this
    //         00520f80     MOV        this,dword ptr [ESI + 0x10]
    //         00520f83     PUSH       EDX=>DAT_fffffff8
    //         00520f84     MOV        EDX,dword ptr [ESI + 0xc]
    //         00520f87     PUSH       this=>DAT_fffffff4
    //         00520f88     MOV        this,dword ptr [EAX + 0x38]
    //         00520f8b     PUSH       EDX=>DAT_fffffff0
    //         00520f8c     PUSH       this
    //         00520f8d     CALL       dword ptr [->GDI32.DLL::TextOutA]                = 0048b30c
    //         00520f93     MOV        EDI,dword ptr [ESP + 0x10]
    //                               LAB_00520f97                                                 XREF[1]:     00520f6e(j)  
    //                              tpnl_txl.cpp:73 (10)
    //         00520f97     MOV        EDX,dword ptr [ESI + 0x20]
    //         00520f9a     PUSH       EBP
    //         00520f9b     MOV        EAX,dword ptr [EDX + 0x38]
    //         00520f9e     PUSH       EAX=>DAT_fffffff8
    //         00520f9f     CALL       EBX=>GDI32.DLL::SelectObject
    //                              tpnl_txl.cpp:75 (13)
    //         00520fa1     MOV        this,dword ptr [ESI + 0x20]
    //         00520fa4     PUSH       s_tpnl_txl::draw                                 = "tpnl_txl::draw"
    //         00520fa9     CALL       TDrawArea::ReleaseDc                             void ReleaseDc(TDrawArea * this, char * param
    //                               LAB_00520fae                                                 XREF[1]:     00520f24(j)  
    //                              tpnl_txl.cpp:78 (8)
    //         00520fae     MOV        this,ESI
    //         00520fb0     CALL       dword ptr [EDI + 0x2c]
    //         00520fb3     POP        EBX
    //         00520fb4     POP        EBP
    //         00520fb5     POP        EDI
    //                               LAB_00520fb6                                                 XREF[3]:     00520ed9(j), 00520ee4(j), 
    //                                                                                                         00520eef(j)  
    //                              tpnl_txl.cpp:79 (3)
    //         00520fb6     POP        ESI
    //         00520fb7     POP        this
    //         00520fb8     RET
    //         00520fb9     ??         90h
    //         00520fba     NOP
    //         00520fbb     NOP
    //         00520fbc     NOP
    //         00520fbd     NOP
    //         00520fbe     NOP
    //         00520fbf     NOP
    //                              * void __cdecl encrypt_codes(char *,char *,int)                                                         *
    //                              void __cdecl encrypt_codes(char * param_1, char * param_2, int param
    //              void              <VOID>         <RETURN>
    //              char *            Stack[0x4]:4   param_1                   XREF[1]:     00520fc0(R)  
    //              char *            Stack[0x8]:4   param_2                   XREF[1]:     00520fc4(R)  
    //              int               Stack[0xc]:4   param_3                   XREF[1]:     00520fd6(R)  
    //                               ?encrypt_codes@@YAXPAD0H@Z                                   XREF[2]:     setup_cmd_options:00521fed(c), 
    //                               encrypt_codes                                                             processCheatCode:00527af4(c)  
    //                              tribegam.cpp:160 (18)
    //         00520fc0     MOV        EDX,dword ptr [ESP + param_1]
    //         00520fc4     MOV        EAX,dword ptr [ESP + param_2]
    //         00520fc8     PUSH       EBP
    //         00520fc9     PUSH       ESI
    //         00520fca     MOV        CL,byte ptr [EDX]
    //         00520fcc     XOR        ESI,ESI
    //         00520fce     PUSH       EDI
    //         00520fcf     LEA        EDI,[EDX + 0x1]
    //                              tribegam.cpp:168 (12)
    //         00520fd2     TEST       CL,CL
    //         00520fd4     JZ         LAB_0052100d
    //         00520fd6     MOV        EBP,dword ptr [ESP + param_3]
    //                               LAB_00520fda                                                 XREF[1]:     0052100b(j)  
    //         00520fda     CMP        ESI,EBP
    //         00520fdc     JGE        LAB_0052100d
    //                              tribegam.cpp:170 (10)
    //         00520fde     CMP        CL,0x41
    //         00520fe1     JL         LAB_00521002
    //         00520fe3     CMP        CL,0x5f
    //         00520fe6     JG         LAB_00521002
    //                              tribegam.cpp:173 (10)
    //         00520fe8     MOVSX      ECX,CL
    //         00520feb     MOV        ECX,dword ptr [ECX*0x4 + s_1\tpnl_tim.cpp_0058   = "1\\tpnl_tim.cpp"
    //                              tribegam.cpp:174 (7)
    //         00520ff2     MOV        EDX,ECX
    //         00520ff4     SAR        EDX,0x8
    //         00520ff7     MOV        byte ptr [EAX],DL
    //                              tribegam.cpp:175 (1)
    //         00520ff9     INC        EAX
    //                              tribegam.cpp:176 (2)
    //         00520ffa     MOV        byte ptr [EAX],CL
    //                              tribegam.cpp:177 (1)
    //         00520ffc     INC        EAX
    //                              tribegam.cpp:178 (3)
    //         00520ffd     ADD        ESI,0x2
    //                              tribegam.cpp:180 (2)
    //         00521000     JMP        LAB_00521006
    //                               LAB_00521002                                                 XREF[2]:     00520fe1(j), 00520fe6(j)  
    //                              tribegam.cpp:182 (2)
    //         00521002     MOV        byte ptr [EAX],CL
    //                              tribegam.cpp:183 (1)
    //         00521004     INC        EAX
    //                              tribegam.cpp:184 (1)
    //         00521005     INC        ESI
    //                               LAB_00521006                                                 XREF[1]:     00521000(j)  
    //                              tribegam.cpp:186 (7)
    //         00521006     MOV        CL,byte ptr [EDI]
    //         00521008     INC        EDI
    //         00521009     TEST       CL,CL
    //         0052100b     JNZ        LAB_00520fda
    //                               LAB_0052100d                                                 XREF[2]:     00520fd4(j), 00520fdc(j)  
    //                              tribegam.cpp:191 (7)
    //         0052100d     POP        EDI
    //         0052100e     POP        ESI
    //         0052100f     MOV        byte ptr [EAX],0x0
    //         00521012     POP        EBP
    //         00521013     RET
    //         00521014     ??         90h
    //         00521015     NOP
    //         00521016     NOP
    //         00521017     NOP
    //         00521018     NOP
    //         00521019     NOP
    //         0052101a     NOP
    //         0052101b     NOP
    //         0052101c     NOP
    //         0052101d     NOP
    //         0052101e     NOP
    //         0052101f     NOP
    //                              * void __cdecl run_log(char *,int)                                                                      *
    //                              void __cdecl run_log(char * param_1, int param_2)
    //              void              <VOID>         <RETURN>
    //              char *            Stack[0x4]:4   param_1                   XREF[2]:     005210ba(R), 005210ef(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[3]:     0052107c(R), 00521084(*), 0052109e(*)  
    //              char[26]          Stack[-0x20]   stime                     XREF[0,3]:   00521095(*), 005210af(*), 005210c7(*)  
    //                               ?run_log@@YAXPADH@Z                                          XREF[10]:    setup:00521c9b(c), 
    //                               run_log                                                                   setup:00521ca9(c), 
    //                                                                                                         setup:00521d63(c), 
    //                                                                                                         setup:00521e1a(c), 
    //                                                                                                         setup:00521e4e(c), 
    //                                                                                                         let_game_begin:005286b2(c), 
    //                                                                                                         let_game_begin:0052881e(c), 
    //                                                                                                         let_game_begin:00528a44(c), 
    //                                                                                                         let_game_begin:00528a7b(c), 
    //                                                                                                         let_game_begin:00528c8d(c)  
    //                              tribegam.cpp:199 (17)
    //         00521020     MOV        EAX,[do_run_log]
    //         00521025     SUB        ESP,0x1c
    //         00521028     TEST       EAX,EAX
    //         0052102a     PUSH       EDI
    //         0052102b     JZ         LAB_00521111
    //                              tribegam.cpp:202 (9)
    //         00521031     MOV        EAX,[run_log_created]
    //         00521036     TEST       EAX,EAX
    //         00521038     JZ         LAB_00521053
    //                              tribegam.cpp:203 (23)
    //         0052103a     PUSH       s_a                                              = "a"
    //         0052103f     PUSH       s_c:\aoerun.txt                                  = "c:\\aoerun.txt"
    //         00521044     CALL       fopen                                            undefined fopen()
    //         00521049     ADD        ESP,0x8
    //         0052104c     MOV        [run_log_file],EAX                               = 00000000
    //                              tribegam.cpp:204 (2)
    //         00521051     JMP        LAB_00521074
    //                               LAB_00521053                                                 XREF[1]:     00521038(j)  
    //                              tribegam.cpp:206 (23)
    //         00521053     PUSH       s_w                                              = "w"
    //         00521058     PUSH       s_c:\aoerun.txt                                  = "c:\\aoerun.txt"
    //         0052105d     CALL       fopen                                            undefined fopen()
    //         00521062     ADD        ESP,0x8
    //         00521065     MOV        [run_log_file],EAX                               = 00000000
    //                              tribegam.cpp:207 (10)
    //         0052106a     MOV        dword ptr [run_log_created],0x1
    //                               LAB_00521074                                                 XREF[1]:     00521051(j)  
    //                              tribegam.cpp:209 (8)
    //         00521074     TEST       EAX,EAX
    //         00521076     JZ         LAB_00521111
    //                              tribegam.cpp:211 (8)
    //         0052107c     MOV        ECX,dword ptr [ESP + param_2]
    //         00521080     TEST       ECX,ECX
    //         00521082     JZ         LAB_005210ef
    //                              tribegam.cpp:214 (10)
    //         00521084     LEA        EAX=>param_2,[ESP + 0x28]
    //         00521088     PUSH       EAX
    //         00521089     CALL       time                                             undefined time()
    //                              tribegam.cpp:216 (16)
    //         0052108e     MOV        ECX,0x6
    //         00521093     XOR        EAX,EAX
    //         00521095     LEA        EDI=>stime[4],[ESP + 0x8]
    //         00521099     ADD        ESP,0x4
    //         0052109c     STOSD.REP  ES:EDI
    //                              tribegam.cpp:217 (28)
    //         0052109e     LEA        ECX=>param_2,[ESP + 0x28]
    //         005210a2     PUSH       0x18
    //         005210a4     PUSH       ECX
    //         005210a5     STOSW      ES:EDI
    //         005210a7     CALL       ctime                                            undefined ctime()
    //         005210ac     ADD        ESP,0x4
    //         005210af     LEA        EDX=>stime[4],[ESP + 0x8]
    //         005210b3     PUSH       EAX
    //         005210b4     PUSH       EDX
    //         005210b5     CALL       strncpy                                          undefined strncpy()
    //                              tribegam.cpp:218 (30)
    //         005210ba     MOV        EAX,dword ptr [ESP + param_1]
    //         005210be     MOV        EDX,dword ptr [run_log_file]                     = 00000000
    //         005210c4     ADD        ESP,0xc
    //         005210c7     LEA        ECX=>stime[4],[ESP + 0x4]
    //         005210cb     PUSH       EAX
    //         005210cc     PUSH       ECX
    //         005210cd     PUSH       s_%s_-_%s_                                       = "%s - %s\n"
    //         005210d2     PUSH       EDX
    //         005210d3     CALL       fprintf                                          undefined fprintf()
    //                              tribegam.cpp:222 (18)
    //         005210d8     MOV        EDX,dword ptr [run_log_file]                     = 00000000
    //         005210de     ADD        ESP,0x10
    //         005210e1     PUSH       EDX
    //         005210e2     CALL       fclose                                           undefined fclose()
    //         005210e7     ADD        ESP,0x4
    //                              tribegam.cpp:224 (5)
    //         005210ea     POP        EDI
    //         005210eb     ADD        ESP,0x1c
    //         005210ee     RET
    //                               LAB_005210ef                                                 XREF[1]:     00521082(j)  
    //                              tribegam.cpp:221 (16)
    //         005210ef     MOV        ECX,dword ptr [ESP + param_1]
    //         005210f3     PUSH       ECX
    //         005210f4     PUSH       s_%s_                                            = "%s\n"
    //         005210f9     PUSH       EAX
    //         005210fa     CALL       fprintf                                          undefined fprintf()
    //                              tribegam.cpp:222 (18)
    //         005210ff     MOV        EDX,dword ptr [run_log_file]                     = 00000000
    //         00521105     ADD        ESP,0xc
    //         00521108     PUSH       EDX
    //         00521109     CALL       fclose                                           undefined fclose()
    //         0052110e     ADD        ESP,0x4
    //                               LAB_00521111                                                 XREF[2]:     0052102b(j), 00521076(j)  
    //                              tribegam.cpp:224 (5)
    //         00521111     POP        EDI
    //         00521112     ADD        ESP,0x1c
    //         00521115     RET
    //         00521116     ??         90h
    //         00521117     NOP
    //         00521118     NOP
    //         00521119     NOP
    //         0052111a     NOP
    //         0052111b     NOP
    //         0052111c     NOP
    //         0052111d     NOP
    //         0052111e     NOP
    //         0052111f     NOP
    return;
}

TRIBE_Panel_Text_Line::TRIBE_Panel_Text_Line(TDrawArea* param_1, TPanel* param_2, void* param_3) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
}

TRIBE_Panel_Text_Line::~TRIBE_Panel_Text_Line() {
    /* TODO: Stub */
    //                              void __thiscall ~TRIBE_Panel_Text_Line(TRIBE_Panel_Text_Line * this)
    //              void              <VOID>         <RETURN>
    //              TRIBE_Panel_Te    ECX:4 (auto)   this
    //                               ??1TRIBE_Panel_Text_Line@@UAE@XZ                             XREF[1]:     `scalar_deleting_destructor':00520
    //                               TRIBE_Panel_Text_Line::~TRIBE_Panel_Text_Line
    //         00520e20     JMP        TPanel::~TPanel
    //         00520e25     ??         90h
    //         00520e26     NOP
    //         00520e27     NOP
    //         00520e28     NOP
    //         00520e29     NOP
    //         00520e2a     NOP
    //         00520e2b     NOP
    //         00520e2c     NOP
    //         00520e2d     NOP
    //         00520e2e     NOP
    //         00520e2f     NOP
}

