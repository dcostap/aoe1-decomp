// Auto-generated scaffold unit: Colorlog.cpp.asm
// SourceMap: C:/msdev/work/age1_x1/Colorlog.cpp
#include "../include/common.h"

// Offset: 0x00424810
void color_log(uchar param_1, uchar param_2, int param_3) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * void __cdecl color_log(unsigned char,unsigned char,int)                                               *
    //                              *********************************************************************************************************
    //                              void __cdecl color_log(uchar param_1, uchar param_2, int param_3)
    //              void              <VOID>         <RETURN>
    //              uchar             Stack[0x4]:1   param_1                   XREF[1]:     004248c0(R)  
    //              uchar             Stack[0x8]:1   param_2
    //              int               Stack[0xc]:4   param_3                   XREF[1]:     0042485b(R)  
    //              _DDBLTFX          Stack[-0x68]   ddbltfx                   XREF[1,3]:   0042489b(W), 004248e0(*), 004248ec(W), 004248f0(W)  
    //              tagPOINT          Stack[-0x70]:8 point                     XREF[1,2]:   00424883(W), 0042488e(W), 004248ac(*)  
    //              tagRECT           Stack[-0x80]   back_dest                 XREF[1,3]:   004248e8(W), 0042488a(W), 00424879(W), 00424895(W)  
    //              tagRECT           Stack[-0x90]   scr_dest                  XREF[0,3]:   004248c7(W), 004248cb(W), 004248e4(W)  
    //                               ?color_log@@YAXEEH@Z                                         XREF[133]:   handle_idle:00420f80(c), 
    //                               color_log                                                                 handle_idle:00421004(c), 
    //                                                                                                         handle_idle:0042101c(c), 
    //                                                                                                         handle_idle:0042104d(c), 
    //                                                                                                         handle_idle:00421081(c), 
    //                                                                                                         handle_idle:0042109a(c), 
    //                                                                                                         handle_idle:004210b2(c), 
    //                                                                                                         handle_idle:004210d4(c), 
    //                                                                                                         handle_idle:004210ec(c), 
    //                                                                                                         handle_idle:004210fa(c), 
    //                                                                                                         TShape:004b8b90(c), 
    //                                                                                                         TShape:004b8d28(c), 
    //                                                                                                         load:004bcd97(c), 
    //                                                                                                         load:004bd296(c), 
    //                                                                                                         load:004bd2dc(c), 
    //                                                                                                         handle_idle:0052967a(c), 
    //                                                                                                         handle_idle:00529688(c), 
    //                                                                                                         handle_idle:005297c7(c), 
    //                                                                                                         handle_idle:005297df(c), 
    //                                                                                                         handle_idle:0052992c(c), [more]
    //                              Colorlog.cpp:13 (21)
    //         00424810     MOV        AL,[do_color_log]                                = 00h
    //         00424815     SUB        ESP,0x8c
    //         0042481b     TEST       AL,AL
    //         0042481d     PUSH       EBX
    //         0042481e     PUSH       ESI
    //         0042481f     JZ         LAB_004249c1
    //                              Colorlog.cpp:19 (32)
    //         00424825     MOV        EAX,[rge_base_game]                              = 00000000
    //         0042482a     TEST       EAX,EAX
    //         0042482c     JZ         LAB_004249c1
    //         00424832     MOV        ECX,dword ptr [EAX + 0x1b0]
    //         00424838     MOV        EBX,0x2
    //         0042483d     CMP        ECX,EBX
    //         0042483f     JL         LAB_004249c1
    //                              Colorlog.cpp:21 (3)
    //         00424845     MOV        ESI,dword ptr [EAX + 0x48]
    //                              Colorlog.cpp:22 (19)
    //         00424848     TEST       ESI,ESI
    //         0042484a     JZ         LAB_004249c1
    //         00424850     MOV        EAX,dword ptr [ESI + 0x1c]
    //         00424853     TEST       EAX,EAX
    //         00424855     JZ         LAB_004249c1
    //                              Colorlog.cpp:30 (16)
    //         0042485b     MOV        ECX,dword ptr [ESP + param_3]
    //         00424862     MOV        EDX,dword ptr [ESI + 0xc]
    //         00424865     MOV        EAX,EBX
    //         00424867     PUSH       EDI
    //         00424868     SUB        EAX,ECX
    //         0042486a     PUSH       EBP
    //                              Colorlog.cpp:33 (35)
    //         0042486b     MOV        EBP,0xa
    //         00424870     LEA        ECX,[EAX + EAX*0x4]
    //         00424873     MOV        EAX,dword ptr [EDX + 0x18]
    //         00424876     CDQ
    //         00424877     SUB        EAX,EDX
    //         00424879     MOV        dword ptr [ESP + back_dest.right],0x0
    //         00424881     SAR        EAX,0x1
    //         00424883     MOV        dword ptr [ESP + point.x],EBP
    //         00424887     LEA        ECX,[EAX + ECX*0x4]
    //         0042488a     MOV        dword ptr [ESP + back_dest.top],ECX
    //                              Colorlog.cpp:36 (11)
    //         0042488e     MOV        dword ptr [ESP + point.y],ECX
    //         00424892     LEA        EAX,[ECX + 0xa]
    //         00424895     MOV        dword ptr [ESP + back_dest.bottom],EAX
    //                              Colorlog.cpp:37 (6)
    //         00424899     XOR        EAX,EAX
    //         0042489b     MOV        dword ptr [ESP + ddbltfx.dwSize],EAX
    //                              Colorlog.cpp:38 (10)
    //         0042489f     MOV        DL,byte ptr [ESI + 0x479]
    //         004248a5     CMP        DL,BL
    //         004248a7     JNZ        LAB_004248c0
    //                              Colorlog.cpp:39 (23)
    //         004248a9     MOV        EDX,dword ptr [ESI + 0x4]
    //         004248ac     LEA        ECX=>point.y,[ESP + 0x30]
    //         004248b0     PUSH       ECX
    //         004248b1     PUSH       EDX
    //         004248b2     CALL       dword ptr [->USER32.DLL::ClientToScreen]         = 0048afd2
    //         004248b8     MOV        EAX,dword ptr [ESP + 0x34]
    //         004248bc     MOV        ECX,dword ptr [ESP + 0x30]
    //                               LAB_004248c0                                                 XREF[1]:     004248a7(j)  
    //                              Colorlog.cpp:47 (32)
    //         004248c0     MOV        EDI,dword ptr [ESP + param_1]
    //         004248c7     MOV        dword ptr [ESP + scr_dest.top],ECX
    //         004248cb     MOV        dword ptr [ESP + scr_dest.right],EAX
    //         004248cf     ADD        ECX,0xa
    //         004248d2     ADD        EAX,0xa
    //         004248d5     MOV        EBX,0x64
    //         004248da     AND        EDI,0xff
    //                              Colorlog.cpp:48 (47)
    //         004248e0     LEA        EDX=>ddbltfx.dwDDFX,[ESP + 0x38]
    //         004248e4     MOV        dword ptr [ESP + scr_dest.bottom],ECX
    //         004248e8     MOV        dword ptr [ESP + back_dest.left],EAX
    //         004248ec     MOV        dword ptr [ESP + ddbltfx.dwDDFX],EBX
    //         004248f0     MOV        dword ptr [ESP + ddbltfx.ddckDestColorkey.dwCo
    //         004248f7     MOV        EAX,dword ptr [ESI + 0x1c]
    //         004248fa     PUSH       EDX
    //         004248fb     PUSH       0x1000400
    //         00424900     PUSH       0x0
    //         00424902     MOV        ECX,dword ptr [EAX]
    //         00424904     LEA        EDX,[ESP + 0x1c]
    //         00424908     PUSH       0x0
    //         0042490a     PUSH       EDX
    //         0042490b     PUSH       EAX
    //         0042490c     CALL       dword ptr [ECX + 0x14]
    //                              Colorlog.cpp:50 (4)
    //         0042490f     MOV        dword ptr [ESP + 0x38],EBX
    //                              Colorlog.cpp:51 (7)
    //         00424913     MOV        dword ptr [ESP + 0x88],EDI
    //                              Colorlog.cpp:52 (31)
    //         0042491a     MOV        EAX,dword ptr [ESI + 0xc]
    //         0042491d     LEA        EDX,[ESP + 0x38]
    //         00424921     PUSH       EDX
    //         00424922     PUSH       offset DAT_fffffff8
    //         00424927     MOV        EAX,dword ptr [EAX + 0x3c]
    //         0042492a     PUSH       0x0=>DAT_fffffff4
    //         0042492c     LEA        EDX,[ESP + 0x2c]
    //         00424930     PUSH       0x0=>DAT_fffffff0
    //         00424932     MOV        ECX,dword ptr [EAX]
    //         00424934     PUSH       EDX
    //         00424935     PUSH       EAX
    //         00424936     CALL       dword ptr [ECX + 0x14]
    //                              Colorlog.cpp:56 (4)
    //         00424939     MOV        EDI,dword ptr [ESP + 0x2c]
    //                              Colorlog.cpp:58 (8)
    //         0042493d     MOV        EDX,dword ptr [ESP + 0x14]
    //         00424941     MOV        EAX,dword ptr [ESP + 0x24]
    //                              Colorlog.cpp:59 (12)
    //         00424945     MOV        ECX,dword ptr [ESP + 0x1c]
    //         00424949     ADD        EDI,EBP
    //         0042494b     ADD        EDX,EBP
    //         0042494d     MOV        dword ptr [ESP + 0x2c],EDI
    //                              Colorlog.cpp:62 (21)
    //         00424951     MOV        EDI,dword ptr [ESP + 0xa4]
    //         00424958     MOV        dword ptr [ESP + 0x14],EDX
    //         0042495c     ADD        EAX,EBP
    //         0042495e     ADD        ECX,EBP
    //         00424960     AND        EDI,0xff
    //                              Colorlog.cpp:63 (47)
    //         00424966     LEA        EDX,[ESP + 0x38]
    //         0042496a     MOV        dword ptr [ESP + 0x24],EAX
    //         0042496e     MOV        dword ptr [ESP + 0x1c],ECX
    //         00424972     MOV        dword ptr [ESP + 0x38],EBX
    //         00424976     MOV        dword ptr [ESP + 0x88],EDI
    //         0042497d     MOV        EAX,dword ptr [ESI + 0x1c]
    //         00424980     PUSH       EDX
    //         00424981     PUSH       offset DAT_fffffff8
    //         00424986     MOV        ECX,dword ptr [EAX]
    //         00424988     PUSH       0x0=>DAT_fffffff4
    //         0042498a     LEA        EDX,[ESP + 0x1c]
    //         0042498e     PUSH       0x0=>DAT_fffffff0
    //         00424990     PUSH       EDX
    //         00424991     PUSH       EAX
    //         00424992     CALL       dword ptr [ECX + 0x14]
    //                              Colorlog.cpp:65 (4)
    //         00424995     MOV        dword ptr [ESP + 0x38],EBX
    //                              Colorlog.cpp:66 (7)
    //         00424999     MOV        dword ptr [ESP + 0x88],EDI
    //                              Colorlog.cpp:67 (33)
    //         004249a0     MOV        EAX,dword ptr [ESI + 0xc]
    //         004249a3     LEA        EDX,[ESP + 0x38]
    //         004249a7     PUSH       EDX
    //         004249a8     PUSH       offset DAT_fffffff8
    //         004249ad     MOV        EAX,dword ptr [EAX + 0x3c]
    //         004249b0     PUSH       0x0=>DAT_fffffff4
    //         004249b2     LEA        EDX,[ESP + 0x2c]
    //         004249b6     PUSH       0x0=>DAT_fffffff0
    //         004249b8     MOV        ECX,dword ptr [EAX]
    //         004249ba     PUSH       EDX
    //         004249bb     PUSH       EAX
    //         004249bc     CALL       dword ptr [ECX + 0x14]
    //         004249bf     POP        EBP
    //         004249c0     POP        EDI
    //                               LAB_004249c1                                                 XREF[5]:     0042481f(j), 0042482c(j), 
    //                                                                                                         0042483f(j), 0042484a(j), 
    //                                                                                                         00424855(j)  
    //                              Colorlog.cpp:68 (9)
    //         004249c1     POP        ESI
    //         004249c2     POP        EBX
    //         004249c3     ADD        ESP,0x8c
    //         004249c9     RET
}

