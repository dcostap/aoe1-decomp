// Auto-generated scaffold unit: bucket_054A.asm
#include "../include/common.h"

// Offset: 0x0054A360
undefined FUN_0054a360() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0054a360()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0054a360                                                 XREF[1]:     FUN_00547b30:00547c29(c)  
    //         0054a360     MOV        EAX,[DAT_00887a80]
    //         0054a365     MOV        dword ptr [EAX + 0x38128],0xffff
    //         0054a36f     JMP        FUN_005494a0                                     undefined FUN_005494a0()
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
}

// Offset: 0x0054A380
undefined FUN_0054a380() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0054a380()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0054a380                                                 XREF[1]:     FUN_00547b30:00547b3f(c)  
    //         0054a380     PUSH       ESI
    //         0054a381     MOV        EAX,[DAT_00887a80]
    //         0054a386     MOV        ESI,dword ptr [EAX + 0x38158]
    //         0054a38c     MOV        EAX,dword ptr [EAX + 0x38150]
    //         0054a392     CMP        ESI,EAX
    //         0054a394     JL         LAB_0054a398
    //         0054a396     MOV        ESI,EAX
    //                               LAB_0054a398                                                 XREF[1]:     0054a394(j)  
    //         0054a398     PUSH       ESI
    //         0054a399     MOV        EAX,[DAT_00887a80]
    //         0054a39e     MOV        ECX,dword ptr [EAX + 0x38154]
    //         0054a3a4     MOV        EAX,dword ptr [EAX + 0x3814c]
    //         0054a3aa     PUSH       ECX
    //         0054a3ab     ADD        EAX,dword ptr [DAT_00887a94]
    //         0054a3b1     PUSH       EAX
    //         0054a3b2     CALL       FUN_00547c90                                     undefined FUN_00547c90()
    //         0054a3b7     ADD        ESP,0xc
    //         0054a3ba     MOV        ECX,dword ptr [DAT_00887a80]
    //         0054a3c0     ADD        dword ptr [ECX + 0x38154],ESI
    //         0054a3c6     MOV        ECX,dword ptr [DAT_00887a80]
    //         0054a3cc     SUB        dword ptr [ECX + 0x38158],ESI
    //         0054a3d2     MOV        EAX,[DAT_00887a80]
    //         0054a3d7     MOV        ECX,dword ptr [EAX + 0x3814c]
    //         0054a3dd     ADD        EAX,0x3814c
    //         0054a3e2     ADD        ECX,ESI
    //         0054a3e4     AND        ECX,0x7fff
    //         0054a3ea     MOV        dword ptr [EAX],ECX
    //         0054a3ec     MOV        EAX,[DAT_00887a80]
    //         0054a3f1     SUB        dword ptr [EAX + 0x38150],ESI
    //         0054a3f7     MOV        EAX,[DAT_00887a80]
    //         0054a3fc     ADD        dword ptr [EAX + 0x38124],ESI
    //         0054a402     MOV        EAX,[DAT_00887a80]
    //         0054a407     MOV        ECX,dword ptr [EAX + 0x38150]
    //         0054a40d     ADD        EAX,0x38150
    //         0054a412     TEST       ECX,ECX
    //         0054a414     JZ         LAB_0054a443
    //         0054a416     MOV        EAX,[DAT_00887a80]
    //         0054a41b     CMP        dword ptr [EAX + 0x38140],0x0
    //         0054a422     JZ         LAB_0054a43c
    //         0054a424     PUSH       ECX
    //         0054a425     MOV        EAX,dword ptr [EAX + 0x3814c]
    //         0054a42b     PUSH       0x0
    //         0054a42d     ADD        EAX,dword ptr [DAT_00887a94]
    //         0054a433     PUSH       EAX
    //         0054a434     CALL       FUN_0054a450                                     undefined FUN_0054a450()
    //         0054a439     ADD        ESP,0xc
    //                               LAB_0054a43c                                                 XREF[1]:     0054a422(j)  
    //         0054a43c     MOV        EAX,0x1
    //         0054a441     POP        ESI
    //         0054a442     RET
    //                               LAB_0054a443                                                 XREF[1]:     0054a414(j)  
    //         0054a443     POP        ESI
    //         0054a444     MOV        dword ptr [EAX],0x1000
    //         0054a44a     XOR        EAX,EAX
    //         0054a44c     RET
}

// Offset: 0x0054A450
undefined FUN_0054a450() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0054a450()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0054a450                                                 XREF[1]:     FUN_0054a380:0054a434(c)  
    //         0054a450     MOV        EDX,dword ptr [ESP + Stack[0xc]]
    //         0054a454     PUSH       EDI
    //         0054a455     TEST       EDX,EDX
    //         0054a457     JZ         LAB_0054a47f
    //         0054a459     XOR        EAX,EAX
    //         0054a45b     MOV        AL,byte ptr [ESP + Stack[0x8]]
    //         0054a45f     MOV        EDI,dword ptr [ESP + Stack[0x4]]
    //         0054a463     MOV        CL,AL
    //         0054a465     MOV        CH,CL
    //         0054a467     MOV        CL,AL
    //         0054a469     MOV        EAX,ECX
    //         0054a46b     SHL        EAX,0x10
    //         0054a46e     MOV        AX,CX
    //         0054a471     MOV        ECX,EDX
    //         0054a473     SHR        ECX,0x2
    //         0054a476     STOSD.REP  ES:EDI
    //         0054a478     MOV        ECX,EDX
    //         0054a47a     AND        ECX,0x3
    //         0054a47d     STOSB.REP  ES:EDI
    //                               LAB_0054a47f                                                 XREF[1]:     0054a457(j)  
    //         0054a47f     POP        EDI
    //         0054a480     RET
}

// Offset: 0x0054A490
undefined deflate_deinit() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * deflate_deinit                                                                                        *
    //                              *********************************************************************************************************
    //                              undefined __cdecl deflate_deinit()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               _deflate_deinit                                              XREF[1]:     rge_close:0047ff7f(c)  
    //                               deflate_deinit
    //         0054a490     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         0054a494     MOV        [DAT_00887a80],EAX
    //         0054a499     MOV        dword ptr [EAX + 0x38178],0xabcd1234
    //         0054a4a3     RET
}

// Offset: 0x0054A4B0
undefined deflate_init() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * deflate_init                                                                                          *
    //                              *********************************************************************************************************
    //                              undefined __cdecl deflate_init()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               _deflate_init                                                XREF[1]:     rge_write:00480350(c)  
    //                               deflate_init
    //         0054a4b0     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         0054a4b4     MOV        ECX,dword ptr [ESP + Stack[0x8]]
    //         0054a4b8     MOV        [DAT_00887a80],EAX
    //         0054a4bd     CMP        ECX,0x1
    //         0054a4c0     JG         LAB_0054a4c7
    //         0054a4c2     MOV        ECX,0x1
    //                               LAB_0054a4c7                                                 XREF[1]:     0054a4c0(j)  
    //         0054a4c7     CMP        ECX,0x5dc
    //         0054a4cd     JL         LAB_0054a4d4
    //         0054a4cf     MOV        ECX,0x5dc
    //                               LAB_0054a4d4                                                 XREF[1]:     0054a4cd(j)  
    //         0054a4d4     MOV        EDX,dword ptr [ESP + Stack[0x10]]
    //         0054a4d8     MOV        dword ptr [EAX + 0x38134],ECX
    //         0054a4de     MOV        ECX,dword ptr [DAT_00887a80]
    //         0054a4e4     MOV        EAX,dword ptr [ESP + Stack[0xc]]
    //         0054a4e8     MOV        dword ptr [ECX + 0x38138],EAX
    //         0054a4ee     MOV        ECX,dword ptr [DAT_00887a80]
    //         0054a4f4     MOV        EAX,dword ptr [ESP + Stack[0x14]]
    //         0054a4f8     MOV        dword ptr [ECX + 0x3813c],EDX
    //         0054a4fe     MOV        ECX,dword ptr [DAT_00887a80]
    //         0054a504     MOV        EDX,dword ptr [ESP + Stack[0x18]]
    //         0054a508     MOV        dword ptr [ECX + 0x38164],EAX
    //         0054a50e     MOV        ECX,dword ptr [DAT_00887a80]
    //         0054a514     MOV        dword ptr [ECX + 0x38168],EDX
    //         0054a51a     MOV        ECX,dword ptr [DAT_00887a80]
    //         0054a520     MOV        EAX,dword ptr [ECX + 0x38164]
    //         0054a526     MOV        dword ptr [ECX + 0x38170],EAX
    //         0054a52c     MOV        ECX,dword ptr [DAT_00887a80]
    //         0054a532     MOV        EAX,dword ptr [ESP + Stack[0x1c]]
    //         0054a536     MOV        EDX,dword ptr [ECX + 0x38168]
    //         0054a53c     MOV        dword ptr [ECX + 0x38174],EDX
    //         0054a542     MOV        ECX,dword ptr [DAT_00887a80]
    //         0054a548     MOV        dword ptr [ECX + 0x3816c],EAX
    //         0054a54e     MOV        ECX,dword ptr [DAT_00887a80]
    //         0054a554     MOV        dword ptr [ECX + 0x38150],0x1000
    //         0054a55e     CALL       FUN_0054a580                                     undefined FUN_0054a580()
    //         0054a563     MOV        ECX,dword ptr [DAT_00887a80]
    //         0054a569     XOR        EAX,EAX
    //         0054a56b     MOV        dword ptr [ECX + 0x38178],0x12345678
    //         0054a575     RET
}

// Offset: 0x0054A580
undefined FUN_0054a580() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0054a580()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0054a580                                                 XREF[1]:     deflate_init:0054a55e(c)  
    //         0054a580     XOR        ECX,ECX
    //         0054a582     MOV        EDX,0xffff
    //                               LAB_0054a587                                                 XREF[1]:     0054a5aa(j)  
    //         0054a587     MOV        EAX,[DAT_00887a80]
    //         0054a58c     ADD        ECX,0x2
    //         0054a58f     MOV        word ptr [EAX + ECX*0x1 + 0x1d100],DX
    //         0054a597     CMP        ECX,0x10000
    //         0054a59d     MOV        EAX,[DAT_00887a80]
    //         0054a5a2     MOV        word ptr [EAX + ECX*0x1 + 0xd100],DX
    //         0054a5aa     JL         LAB_0054a587
    //         0054a5ac     XOR        EAX,EAX
    //         0054a5ae     MOV        ECX,0xffff
    //                               LAB_0054a5b3                                                 XREF[1]:     0054a5c9(j)  
    //         0054a5b3     MOV        EDX,dword ptr [DAT_00887a80]
    //         0054a5b9     ADD        EAX,0x2
    //         0054a5bc     MOV        word ptr [EDX + EAX*0x1 + 0x9100],CX
    //         0054a5c4     CMP        EAX,0x4000
    //         0054a5c9     JL         LAB_0054a5b3
    //         0054a5cb     MOV        EAX,[DAT_00887a80]
    //         0054a5d0     MOV        ECX,dword ptr [DAT_00887a80]
    //         0054a5d6     ADD        EAX,0x3610c
    //         0054a5db     MOV        dword ptr [ECX + 0x3670c],EAX
    //         0054a5e1     MOV        EAX,[DAT_00887a80]
    //         0054a5e6     MOV        dword ptr [EAX + 0x36710],0x20
    //         0054a5f0     MOV        EAX,[DAT_00887a80]
    //         0054a5f5     MOV        ECX,dword ptr [DAT_00887a80]
    //         0054a5fb     ADD        EAX,0x2d102
    //         0054a600     MOV        dword ptr [ECX + 0x36104],EAX
    //         0054a606     RET
}

// Offset: 0x0054A610
undefined deflate_buf_size() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * deflate_buf_size                                                                                      *
    //                              *********************************************************************************************************
    //                              undefined __cdecl deflate_buf_size()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               _deflate_buf_size                                            XREF[1]:     rge_write:00480323(c)  
    //                               deflate_buf_size
    //         0054a610     MOV        EAX,0x3817c
    //         0054a615     RET
}

