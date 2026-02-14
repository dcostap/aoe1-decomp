// Auto-generated scaffold unit: bucket_044A.asm
#include "../include/common.h"

// Offset: 0x0044A4B9
undefined FUN_0044a4b9() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0044a4b9()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0044a4b9
    //         0044a4b9     NOP
    //         0044a4ba     NOP
    //         0044a4bb     NOP
    //         0044a4bc     NOP
    //         0044a4bd     NOP
    //         0044a4be     NOP
    //         0044a4bf     NOP
    //                               _x_CustomMemCopy
    //         0044a4c0     DEC        ESI
    //         0044a4c1     CMPSB      ES:EDI,ESI
    //         0044a4c2     INC        ESP
    //         0044a4c3     ADD        byte ptr [EAX + -0x5a],CL
    //         0044a4c6     INC        ESP
    //         0044a4c7     ADD        byte ptr [EDI + -0x5a],CL
    //         0044a4ca     INC        ESP
    //         0044a4cb     ADD        byte ptr [ESI + 0x44],BL
    //         0044a4cf     ADD        byte ptr [EBP + 0xe50044a9],AL
    //         0044a4d5     TEST       AL,0x44
    //         0044a4d7     ADD        byte ptr [EDX + -0x58],AL
    //         0044a4da     INC        ESP
    //         0044a4db     ADD        byte ptr [EDX + 0x20044a7],AH
    //         0044a4e1     CMPSD      ES:EDI,ESI
    //         0044a4e2     INC        ESP
    //         0044a4e3     ADD        byte ptr [EDX + -0x55],CL
    //         0044a4e6     INC        ESP
    //         0044a4e7     ADD        byte ptr [EBP + 0x130044aa],CH
    //         0044a4ed     STOSB      ES:EDI
    //         0044a4ee     INC        ESP
    //         0044a4ef     ADD        byte ptr [ECX + -0x57],BH
    //         0044a4f2     INC        ESP
    //         0044a4f3     ADD        CL,BL
    //         0044a4f5     TEST       AL,0x44
    //         0044a4f7     ADD        byte ptr [ESI],DH
    //         0044a4f9     TEST       AL,0x44
    //         0044a4fb     ADD        byte ptr [ESI + 0xf60044a7],DL
    //         0044a501     CMPSB      ES:EDI,ESI
    //         0044a502     INC        ESP
    //         0044a503     ADD        byte ptr [ESI],BH
    //         0044a505     STOSD      ES:EDI
    //         0044a506     INC        ESP
    //         0044a507     ADD        byte ptr [ECX + 0x70044aa],AH
    //         0044a50d     STOSB      ES:EDI
    //         0044a50e     INC        ESP
    //         0044a50f     ADD        byte ptr [EBP + -0x57],CH
    //         0044a512     INC        ESP
    //         0044a513     ADD        CH,CL
    //         0044a515     TEST       AL,0x44
    //         0044a517     ADD        byte ptr [EDX],CH
    //         0044a519     TEST       AL,0x44
    //         0044a51b     ADD        byte ptr [EDX + 0xea0044a7],CL
    //         0044a521     CMPSB      ES:EDI,ESI
    //         0044a522     INC        ESP
    //         0044a523     ADD        byte ptr [EDI],CH
    //         0044a525     STOSD      ES:EDI
    //         0044a526     INC        ESP
    //         0044a527     ADD        byte ptr [EDX + 0xf80044aa],DL
    //         0044a52d     TEST       EAX,0xa95e0044
    //         0044a532     INC        ESP
    //         0044a533     ADD        byte ptr [ESI + 0x1b0044a8],BH
    //         0044a539     TEST       AL,0x44
    //         0044a53b     ADD        byte ptr [EBX + -0x59],BH
    //         0044a53e     INC        ESP
    //         0044a53f     ADD        BL,BL
    //         0044a541     CMPSB      ES:EDI,ESI
    //         0044a542     INC        ESP
    //         0044a543     ADD        byte ptr [EBX],AH
    //         0044a545     STOSD      ES:EDI
    //         0044a546     INC        ESP
    //         0044a547     ADD        byte ptr [ESI + 0xec0044aa],AL
    //         0044a54d     TEST       EAX,0xa9520044
    //         0044a552     INC        ESP
    //         0044a553     ADD        byte ptr [EDX + 0xf0044a8],DH
    //         0044a559     TEST       AL,0x44
    //         0044a55b     ADD        byte ptr [EDI + -0x59],CH
    //         0044a55e     INC        ESP
    //         0044a55f     ADD        BH,CL
    //         0044a561     CMPSB      ES:EDI,ESI
    //         0044a562     INC        ESP
    //         0044a563     ADD        byte ptr [EBX + EBP*0x4],DL
    //         0044a566     INC        ESP
    //         0044a567     ADD        byte ptr [EDI + -0x56],DH
    //         0044a56a     INC        ESP
    //         0044a56b     ADD        CH,BL
    //         0044a56d     TEST       EAX,0xa9430044
    //         0044a572     INC        ESP
    //         0044a573     ADD        byte ptr [EBX + 0x44a8],AH
    //         0044a579     TEST       AL,0x44
    //         0044a57b     ADD        byte ptr [EAX + -0x59],AH
    //         0044a57e     INC        ESP
    //         0044a57f     ADD        AL,AL
    //         0044a581     CMPSB      ES:EDI,ESI
    //         0044a582     INC        ESP
    //         0044a583     ADD        byte ptr [EAX],CL
    //         0044a585     STOSD      ES:EDI
    //         0044a586     INC        ESP
    //         0044a587     ADD        byte ptr [EBX + -0x56],CH
    //         0044a58a     INC        ESP
    //         0044a58b     ADD        CL,DL
    //         0044a58d     TEST       EAX,0xa9370044
    //         0044a592     INC        ESP
    //         0044a593     ADD        byte ptr [EDI + 0xf40044a8],DL
    //         0044a599     CMPSD      ES:EDI,ESI
    //         0044a59a     INC        ESP
    //         0044a59b     ADD        byte ptr [EDI + 0x44],DL
    //         0044a59f     ADD        byte ptr [ESI + 0xaaf90044],DH
    //         0044a5a6     INC        ESP
    //         0044a5a7     ADD        byte ptr [EDX + EBP*0x4 + 0x44],BL
    //         0044a5ab     ADD        DL,AL
    //         0044a5ad     TEST       EAX,0xa9280044
    //         0044a5b2     INC        ESP
    //         0044a5b3     ADD        byte ptr [EAX + 0xe50044a8],CL
    //         0044a5b9     CMPSD      ES:EDI,ESI
    //         0044a5ba     INC        ESP
    //         0044a5bb     ADD        byte ptr [EBP + -0x59],AL
    //         0044a5be     INC        ESP
    //         0044a5bf     ADD        byte ptr [EBP + 0xed0044a6],AH
    //         0044a5c5     STOSB      ES:EDI
    //         0044a5c6     INC        ESP
    //         0044a5c7     ADD        byte ptr [EAX + -0x56],DL
    //         0044a5ca     INC        ESP
    //         0044a5cb     ADD        byte ptr [ESI + 0x1c0044a9],DH
    //         0044a5d1     TEST       EAX,0xa87c0044
    //         0044a5d6     INC        ESP
    //         0044a5d7     ADD        CL,BL
    //         0044a5d9     CMPSD      ES:EDI,ESI
    //         0044a5da     INC        ESP
    //         0044a5db     ADD        byte ptr [ECX],BH
    //         0044a5dd     CMPSD      ES:EDI,ESI
    //         0044a5de     INC        ESP
    //         0044a5df     ADD        byte ptr [ECX + 0xde0044a6],BL
    //         0044a5e5     STOSB      ES:EDI
    //         0044a5e6     INC        ESP
    //         0044a5e7     ADD        byte ptr [ECX + -0x56],AL
    //         0044a5ea     INC        ESP
    //         0044a5eb     ADD        byte ptr [EDI + 0xd0044a9],AH
    //         0044a5f1     TEST       EAX,0xa86d0044
    //         0044a5f6     INC        ESP
    //         0044a5f7     ADD        DL,CL
    //         0044a5f9     CMPSD      ES:EDI,ESI
    //         0044a5fa     INC        ESP
    //         0044a5fb     ADD        byte ptr [EDX],CH
    //         0044a5fd     CMPSD      ES:EDI,ESI
    //         0044a5fe     INC        ESP
    //         0044a5ff     ADD        byte ptr [EDX + 0xd20044a6],CL
    //         0044a605     STOSB      ES:EDI
    //         0044a606     INC        ESP
    //         0044a607     ADD        byte ptr [DAT_9b0044aa],DH
    //         0044a60d     TEST       EAX,0xa9010044
    //         0044a612     INC        ESP
    //         0044a613     ADD        byte ptr [ECX + -0x58],AH
    //         0044a616     INC        ESP
    //         0044a617     ADD        byte ptr [ESI + 0x1e0044a7],BH
    //         0044a61d     CMPSD      ES:EDI,ESI
    //         0044a61e     INC        ESP
    //         0044a61f     ADD        byte ptr [ESI + -0x5a],BH
    //         0044a622     INC        ESP
    //         0044a623     ADD        BL,AL
    //         0044a625     STOSB      ES:EDI
    //         0044a626     INC        ESP
    //         0044a627     ADD        byte ptr [ESI],AH
    //         0044a629     STOSB      ES:EDI
    //         0044a62a     INC        ESP
    //         0044a62b     ADD        byte ptr [ECX + EBP*0x4 + 0xa8f20044],CL
    //         0044a632     INC        ESP
    //         0044a633     ADD        byte ptr [EDX + -0x58],DL
    //         0044a636     INC        ESP
    //         0044a637     ADD        byte ptr [EDI + 0xf0044a7],CH
    //         0044a63d     CMPSD      ES:EDI,ESI
    //         0044a63e     INC        ESP
    //         0044a63f     ADD        byte ptr [EDI + -0x5a],CH
    //         0044a642     INC        ESP
    //                               _x_Copy_Threshold (0044a643+1)
    //         0044a643     ADD        byte ptr [EAX],AH
    //         0044a646     ADD        byte ptr [EAX],AL
    //         0044a648     MOV        AL,byte ptr [ESI + -0x1]
    //         0044a64b     MOV        byte ptr [EDI + -0x1],AL
    //         0044a64e     RET
}

// Offset: 0x0044A64F
undefined FUN_0044a64f() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0044a64f()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0044a64f
    //         0044a64f     MOV        AL,byte ptr [ESI + -0x2]
    //         0044a652     MOV        AH,byte ptr [ESI + -0x1]
    //         0044a655     MOV        byte ptr [EDI + -0x2],AL
    //         0044a658     MOV        byte ptr [EDI + -0x1],AH
    //         0044a65b     RET
}

// Offset: 0x0044A65C
undefined FUN_0044a65c() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0044a65c()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0044a65c
    //         0044a65c     MOV        AL,byte ptr [ESI + -0x3]
    //         0044a65f     MOV        AH,byte ptr [ESI + -0x2]
    //         0044a662     MOV        BL,byte ptr [ESI + -0x1]
    //         0044a665     MOV        byte ptr [EDI + -0x3],AL
    //         0044a668     MOV        byte ptr [EDI + -0x2],AH
    //         0044a66b     MOV        byte ptr [EDI + -0x1],BL
    //         0044a66e     RET
}

// Offset: 0x0044A66F
undefined FUN_0044a66f() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0044a66f()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0044a66f
    //         0044a66f     MOV        CL,byte ptr [EDI + -0x50]
    //         0044a672     MOV        EAX,dword ptr [ESI + -0x60]
    //         0044a675     MOV        EBX,dword ptr [ESI + -0x5c]
    //         0044a678     MOV        dword ptr [EDI + -0x60],EAX
    //         0044a67b     MOV        dword ptr [EDI + -0x5c],EBX
    //         0044a67e     MOV        EAX,dword ptr [ESI + -0x58]
    //         0044a681     MOV        EBX,dword ptr [ESI + -0x54]
    //         0044a684     MOV        dword ptr [EDI + -0x58],EAX
    //         0044a687     MOV        dword ptr [EDI + -0x54],EBX
    //         0044a68a     MOV        CL,byte ptr [EDI + -0x40]
    //         0044a68d     MOV        EAX,dword ptr [ESI + -0x50]
    //         0044a690     MOV        EBX,dword ptr [ESI + -0x4c]
    //         0044a693     MOV        dword ptr [EDI + -0x50],EAX
    //         0044a696     MOV        dword ptr [EDI + -0x4c],EBX
    //         0044a699     MOV        EAX,dword ptr [ESI + -0x48]
    //         0044a69c     MOV        EBX,dword ptr [ESI + -0x44]
    //         0044a69f     MOV        dword ptr [EDI + -0x48],EAX
    //         0044a6a2     MOV        dword ptr [EDI + -0x44],EBX
    //         0044a6a5     MOV        CL,byte ptr [EDI + -0x30]
    //         0044a6a8     MOV        EAX,dword ptr [ESI + -0x40]
    //         0044a6ab     MOV        EBX,dword ptr [ESI + -0x3c]
    //         0044a6ae     MOV        dword ptr [EDI + -0x40],EAX
    //         0044a6b1     MOV        dword ptr [EDI + -0x3c],EBX
    //         0044a6b4     MOV        EAX,dword ptr [ESI + -0x38]
    //         0044a6b7     MOV        EBX,dword ptr [ESI + -0x34]
    //         0044a6ba     MOV        dword ptr [EDI + -0x38],EAX
    //         0044a6bd     MOV        dword ptr [EDI + -0x34],EBX
    //         0044a6c0     MOV        CL,byte ptr [EDI + -0x20]
    //         0044a6c3     MOV        EAX,dword ptr [ESI + -0x30]
    //         0044a6c6     MOV        EBX,dword ptr [ESI + -0x2c]
    //         0044a6c9     MOV        dword ptr [EDI + -0x30],EAX
    //         0044a6cc     MOV        dword ptr [EDI + -0x2c],EBX
    //         0044a6cf     MOV        EAX,dword ptr [ESI + -0x28]
    //         0044a6d2     MOV        EBX,dword ptr [ESI + -0x24]
    //         0044a6d5     MOV        dword ptr [EDI + -0x28],EAX
    //         0044a6d8     MOV        dword ptr [EDI + -0x24],EBX
    //         0044a6db     MOV        CL,byte ptr [EDI + DAT_fffffff0]
    //         0044a6de     MOV        EAX,dword ptr [ESI + -0x20]
    //         0044a6e1     MOV        EBX,dword ptr [ESI + -0x1c]
    //         0044a6e4     MOV        dword ptr [EDI + -0x20],EAX
    //         0044a6e7     MOV        dword ptr [EDI + -0x1c],EBX
    //         0044a6ea     MOV        EAX,dword ptr [ESI + -0x18]
    //         0044a6ed     MOV        EBX,dword ptr [ESI + -0x14]
    //         0044a6f0     MOV        dword ptr [EDI + -0x18],EAX
    //         0044a6f3     MOV        dword ptr [EDI + -0x14],EBX
    //         0044a6f6     MOV        EAX,dword ptr [ESI + DAT_fffffff0]
    //         0044a6f9     MOV        EBX,dword ptr [ESI + DAT_fffffff4]
    //         0044a6fc     MOV        dword ptr [EDI + DAT_fffffff0],EAX
    //         0044a6ff     MOV        dword ptr [EDI + DAT_fffffff4],EBX
    //         0044a702     MOV        EAX,dword ptr [ESI + DAT_fffffff8]
    //         0044a705     MOV        EBX,dword ptr [ESI + -0x4]
    //         0044a708     MOV        dword ptr [EDI + DAT_fffffff8],EAX
    //         0044a70b     MOV        dword ptr [EDI + -0x4],EBX
    //         0044a70e     RET
}

// Offset: 0x0044A70F
undefined FUN_0044a70f() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0044a70f()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0044a70f
    //         0044a70f     MOV        CL,byte ptr [EDI + -0x50]
    //         0044a712     MOV        EAX,dword ptr [ESI + -0x5f]
    //         0044a715     MOV        EBX,dword ptr [ESI + -0x5b]
    //         0044a718     MOV        dword ptr [EDI + -0x5f],EAX
    //         0044a71b     MOV        dword ptr [EDI + -0x5b],EBX
    //         0044a71e     MOV        EAX,dword ptr [ESI + -0x57]
    //         0044a721     MOV        EBX,dword ptr [ESI + -0x53]
    //         0044a724     MOV        dword ptr [EDI + -0x57],EAX
    //         0044a727     MOV        dword ptr [EDI + -0x53],EBX
    //         0044a72a     MOV        CL,byte ptr [EDI + -0x40]
    //         0044a72d     MOV        EAX,dword ptr [ESI + -0x4f]
    //         0044a730     MOV        EBX,dword ptr [ESI + -0x4b]
    //         0044a733     MOV        dword ptr [EDI + -0x4f],EAX
    //         0044a736     MOV        dword ptr [EDI + -0x4b],EBX
    //         0044a739     MOV        EAX,dword ptr [ESI + -0x47]
    //         0044a73c     MOV        EBX,dword ptr [ESI + -0x43]
    //         0044a73f     MOV        dword ptr [EDI + -0x47],EAX
    //         0044a742     MOV        dword ptr [EDI + -0x43],EBX
    //         0044a745     MOV        CL,byte ptr [EDI + -0x30]
    //         0044a748     MOV        EAX,dword ptr [ESI + -0x3f]
    //         0044a74b     MOV        EBX,dword ptr [ESI + -0x3b]
    //         0044a74e     MOV        dword ptr [EDI + -0x3f],EAX
    //         0044a751     MOV        dword ptr [EDI + -0x3b],EBX
    //         0044a754     MOV        EAX,dword ptr [ESI + -0x37]
    //         0044a757     MOV        EBX,dword ptr [ESI + -0x33]
    //         0044a75a     MOV        dword ptr [EDI + -0x37],EAX
    //         0044a75d     MOV        dword ptr [EDI + -0x33],EBX
    //         0044a760     MOV        CL,byte ptr [EDI + -0x20]
    //         0044a763     MOV        EAX,dword ptr [ESI + -0x2f]
    //         0044a766     MOV        EBX,dword ptr [ESI + -0x2b]
    //         0044a769     MOV        dword ptr [EDI + -0x2f],EAX
    //         0044a76c     MOV        dword ptr [EDI + -0x2b],EBX
    //         0044a76f     MOV        EAX,dword ptr [ESI + -0x27]
    //         0044a772     MOV        EBX,dword ptr [ESI + -0x23]
    //         0044a775     MOV        dword ptr [EDI + -0x27],EAX
    //         0044a778     MOV        dword ptr [EDI + -0x23],EBX
    //         0044a77b     MOV        CL,byte ptr [EDI + DAT_fffffff0]
    //         0044a77e     MOV        EAX,dword ptr [ESI + -0x1f]
    //         0044a781     MOV        EBX,dword ptr [ESI + -0x1b]
    //         0044a784     MOV        dword ptr [EDI + -0x1f],EAX
    //         0044a787     MOV        dword ptr [EDI + -0x1b],EBX
    //         0044a78a     MOV        EAX,dword ptr [ESI + -0x17]
    //         0044a78d     MOV        EBX,dword ptr [ESI + -0x13]
    //         0044a790     MOV        dword ptr [EDI + -0x17],EAX
    //         0044a793     MOV        dword ptr [EDI + -0x13],EBX
    //         0044a796     MOV        EAX,dword ptr [ESI + DAT_fffffff1]
    //         0044a799     MOV        EBX,dword ptr [ESI + DAT_fffffff5]
    //         0044a79c     MOV        dword ptr [EDI + DAT_fffffff1],EAX
    //         0044a79f     MOV        dword ptr [EDI + DAT_fffffff5],EBX
    //         0044a7a2     MOV        EAX,dword ptr [ESI + DAT_fffffff9]
    //         0044a7a5     MOV        EBX,dword ptr [ESI + -0x4]
    //         0044a7a8     MOV        dword ptr [EDI + DAT_fffffff9],EAX
    //         0044a7ab     MOV        dword ptr [EDI + -0x4],EBX
    //         0044a7ae     RET
}

// Offset: 0x0044A7AF
undefined FUN_0044a7af() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0044a7af()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0044a7af
    //         0044a7af     MOV        CL,byte ptr [EDI + -0x50]
    //         0044a7b2     MOV        EAX,dword ptr [ESI + -0x5e]
    //         0044a7b5     MOV        EBX,dword ptr [ESI + -0x5a]
    //         0044a7b8     MOV        dword ptr [EDI + -0x5e],EAX
    //         0044a7bb     MOV        dword ptr [EDI + -0x5a],EBX
    //         0044a7be     MOV        EAX,dword ptr [ESI + -0x56]
    //         0044a7c1     MOV        EBX,dword ptr [ESI + -0x52]
    //         0044a7c4     MOV        dword ptr [EDI + -0x56],EAX
    //         0044a7c7     MOV        dword ptr [EDI + -0x52],EBX
    //         0044a7ca     MOV        CL,byte ptr [EDI + -0x40]
    //         0044a7cd     MOV        EAX,dword ptr [ESI + -0x4e]
    //         0044a7d0     MOV        EBX,dword ptr [ESI + -0x4a]
    //         0044a7d3     MOV        dword ptr [EDI + -0x4e],EAX
    //         0044a7d6     MOV        dword ptr [EDI + -0x4a],EBX
    //         0044a7d9     MOV        EAX,dword ptr [ESI + -0x46]
    //         0044a7dc     MOV        EBX,dword ptr [ESI + -0x42]
    //         0044a7df     MOV        dword ptr [EDI + -0x46],EAX
    //         0044a7e2     MOV        dword ptr [EDI + -0x42],EBX
    //         0044a7e5     MOV        CL,byte ptr [EDI + -0x30]
    //         0044a7e8     MOV        EAX,dword ptr [ESI + -0x3e]
    //         0044a7eb     MOV        EBX,dword ptr [ESI + -0x3a]
    //         0044a7ee     MOV        dword ptr [EDI + -0x3e],EAX
    //         0044a7f1     MOV        dword ptr [EDI + -0x3a],EBX
    //         0044a7f4     MOV        EAX,dword ptr [ESI + -0x36]
    //         0044a7f7     MOV        EBX,dword ptr [ESI + -0x32]
    //         0044a7fa     MOV        dword ptr [EDI + -0x36],EAX
    //         0044a7fd     MOV        dword ptr [EDI + -0x32],EBX
    //         0044a800     MOV        CL,byte ptr [EDI + -0x20]
    //         0044a803     MOV        EAX,dword ptr [ESI + -0x2e]
    //         0044a806     MOV        EBX,dword ptr [ESI + -0x2a]
    //         0044a809     MOV        dword ptr [EDI + -0x2e],EAX
    //         0044a80c     MOV        dword ptr [EDI + -0x2a],EBX
    //         0044a80f     MOV        EAX,dword ptr [ESI + -0x26]
    //         0044a812     MOV        EBX,dword ptr [ESI + -0x22]
    //         0044a815     MOV        dword ptr [EDI + -0x26],EAX
    //         0044a818     MOV        dword ptr [EDI + -0x22],EBX
    //         0044a81b     MOV        CL,byte ptr [EDI + DAT_fffffff0]
    //         0044a81e     MOV        EAX,dword ptr [ESI + -0x1e]
    //         0044a821     MOV        EBX,dword ptr [ESI + -0x1a]
    //         0044a824     MOV        dword ptr [EDI + -0x1e],EAX
    //         0044a827     MOV        dword ptr [EDI + -0x1a],EBX
    //         0044a82a     MOV        EAX,dword ptr [ESI + -0x16]
    //         0044a82d     MOV        EBX,dword ptr [ESI + -0x12]
    //         0044a830     MOV        dword ptr [EDI + -0x16],EAX
    //         0044a833     MOV        dword ptr [EDI + -0x12],EBX
    //         0044a836     MOV        EAX,dword ptr [ESI + DAT_fffffff2]
    //         0044a839     MOV        EBX,dword ptr [ESI + DAT_fffffff6]
    //         0044a83c     MOV        dword ptr [EDI + DAT_fffffff2],EAX
    //         0044a83f     MOV        dword ptr [EDI + DAT_fffffff6],EBX
    //         0044a842     MOV        EAX,dword ptr [ESI + DAT_fffffffa]
    //         0044a845     MOV        EBX,dword ptr [ESI + -0x2]
    //         0044a848     MOV        dword ptr [EDI + DAT_fffffffa],EAX
    //         0044a84b     MOV        byte ptr [EDI + -0x2],BL
    //         0044a84e     MOV        byte ptr [EDI + -0x1],BH
    //         0044a851     RET
}

// Offset: 0x0044A852
undefined FUN_0044a852() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0044a852()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0044a852
    //         0044a852     MOV        CL,byte ptr [EDI + -0x50]
    //         0044a855     MOV        EAX,dword ptr [ESI + -0x5d]
    //         0044a858     MOV        EBX,dword ptr [ESI + -0x59]
    //         0044a85b     MOV        dword ptr [EDI + -0x5d],EAX
    //         0044a85e     MOV        dword ptr [EDI + -0x59],EBX
    //         0044a861     MOV        EAX,dword ptr [ESI + -0x55]
    //         0044a864     MOV        EBX,dword ptr [ESI + -0x51]
    //         0044a867     MOV        dword ptr [EDI + -0x55],EAX
    //         0044a86a     MOV        dword ptr [EDI + -0x51],EBX
    //         0044a86d     MOV        CL,byte ptr [EDI + -0x40]
    //         0044a870     MOV        EAX,dword ptr [ESI + -0x4d]
    //         0044a873     MOV        EBX,dword ptr [ESI + -0x49]
    //         0044a876     MOV        dword ptr [EDI + -0x4d],EAX
    //         0044a879     MOV        dword ptr [EDI + -0x49],EBX
    //         0044a87c     MOV        EAX,dword ptr [ESI + -0x45]
    //         0044a87f     MOV        EBX,dword ptr [ESI + -0x41]
    //         0044a882     MOV        dword ptr [EDI + -0x45],EAX
    //         0044a885     MOV        dword ptr [EDI + -0x41],EBX
    //         0044a888     MOV        CL,byte ptr [EDI + -0x30]
    //         0044a88b     MOV        EAX,dword ptr [ESI + -0x3d]
    //         0044a88e     MOV        EBX,dword ptr [ESI + -0x39]
    //         0044a891     MOV        dword ptr [EDI + -0x3d],EAX
    //         0044a894     MOV        dword ptr [EDI + -0x39],EBX
    //         0044a897     MOV        EAX,dword ptr [ESI + -0x35]
    //         0044a89a     MOV        EBX,dword ptr [ESI + -0x31]
    //         0044a89d     MOV        dword ptr [EDI + -0x35],EAX
    //         0044a8a0     MOV        dword ptr [EDI + -0x31],EBX
    //         0044a8a3     MOV        CL,byte ptr [EDI + -0x20]
    //         0044a8a6     MOV        EAX,dword ptr [ESI + -0x2d]
    //         0044a8a9     MOV        EBX,dword ptr [ESI + -0x29]
    //         0044a8ac     MOV        dword ptr [EDI + -0x2d],EAX
    //         0044a8af     MOV        dword ptr [EDI + -0x29],EBX
    //         0044a8b2     MOV        EAX,dword ptr [ESI + -0x25]
    //         0044a8b5     MOV        EBX,dword ptr [ESI + -0x21]
    //         0044a8b8     MOV        dword ptr [EDI + -0x25],EAX
    //         0044a8bb     MOV        dword ptr [EDI + -0x21],EBX
    //         0044a8be     MOV        CL,byte ptr [EDI + DAT_fffffff0]
    //         0044a8c1     MOV        EAX,dword ptr [ESI + -0x1d]
    //         0044a8c4     MOV        EBX,dword ptr [ESI + -0x19]
    //         0044a8c7     MOV        dword ptr [EDI + -0x1d],EAX
    //         0044a8ca     MOV        dword ptr [EDI + -0x19],EBX
    //         0044a8cd     MOV        EAX,dword ptr [ESI + -0x15]
    //         0044a8d0     MOV        EBX,dword ptr [ESI + -0x11]
    //         0044a8d3     MOV        dword ptr [EDI + -0x15],EAX
    //         0044a8d6     MOV        dword ptr [EDI + -0x11],EBX
    //         0044a8d9     MOV        EAX,dword ptr [ESI + DAT_fffffff3]
    //         0044a8dc     MOV        EBX,dword ptr [ESI + DAT_fffffff7]
    //         0044a8df     MOV        dword ptr [EDI + DAT_fffffff3],EAX
    //         0044a8e2     MOV        dword ptr [EDI + DAT_fffffff7],EBX
    //         0044a8e5     MOV        EAX,dword ptr [ESI + DAT_fffffffb]
    //         0044a8e8     MOV        BL,byte ptr [ESI + -0x1]
    //         0044a8eb     MOV        dword ptr [EDI + DAT_fffffffb],EAX
    //         0044a8ee     MOV        byte ptr [EDI + -0x1],BL
    //         0044a8f1     RET
}

// Offset: 0x0044A8F2
undefined FUN_0044a8f2() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0044a8f2()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0044a8f2
    //         0044a8f2     MOV        CL,byte ptr [EDI + -0x50]
    //         0044a8f5     MOV        EAX,dword ptr [ESI + -0x5c]
    //         0044a8f8     MOV        EBX,dword ptr [ESI + -0x58]
    //         0044a8fb     MOV        dword ptr [EDI + -0x5c],EAX
    //         0044a8fe     MOV        dword ptr [EDI + -0x58],EBX
    //         0044a901     MOV        EAX,dword ptr [ESI + -0x54]
    //         0044a904     MOV        EBX,dword ptr [ESI + -0x50]
    //         0044a907     MOV        dword ptr [EDI + -0x54],EAX
    //         0044a90a     MOV        dword ptr [EDI + -0x50],EBX
    //         0044a90d     MOV        CL,byte ptr [EDI + -0x40]
    //         0044a910     MOV        EAX,dword ptr [ESI + -0x4c]
    //         0044a913     MOV        EBX,dword ptr [ESI + -0x48]
    //         0044a916     MOV        dword ptr [EDI + -0x4c],EAX
    //         0044a919     MOV        dword ptr [EDI + -0x48],EBX
    //         0044a91c     MOV        EAX,dword ptr [ESI + -0x44]
    //         0044a91f     MOV        EBX,dword ptr [ESI + -0x40]
    //         0044a922     MOV        dword ptr [EDI + -0x44],EAX
    //         0044a925     MOV        dword ptr [EDI + -0x40],EBX
    //         0044a928     MOV        CL,byte ptr [EDI + -0x30]
    //         0044a92b     MOV        EAX,dword ptr [ESI + -0x3c]
    //         0044a92e     MOV        EBX,dword ptr [ESI + -0x38]
    //         0044a931     MOV        dword ptr [EDI + -0x3c],EAX
    //         0044a934     MOV        dword ptr [EDI + -0x38],EBX
    //         0044a937     MOV        EAX,dword ptr [ESI + -0x34]
    //         0044a93a     MOV        EBX,dword ptr [ESI + -0x30]
    //         0044a93d     MOV        dword ptr [EDI + -0x34],EAX
    //         0044a940     MOV        dword ptr [EDI + -0x30],EBX
    //         0044a943     MOV        CL,byte ptr [EDI + -0x20]
    //         0044a946     MOV        EAX,dword ptr [ESI + -0x2c]
    //         0044a949     MOV        EBX,dword ptr [ESI + -0x28]
    //         0044a94c     MOV        dword ptr [EDI + -0x2c],EAX
    //         0044a94f     MOV        dword ptr [EDI + -0x28],EBX
    //         0044a952     MOV        EAX,dword ptr [ESI + -0x24]
    //         0044a955     MOV        EBX,dword ptr [ESI + -0x20]
    //         0044a958     MOV        dword ptr [EDI + -0x24],EAX
    //         0044a95b     MOV        dword ptr [EDI + -0x20],EBX
    //         0044a95e     MOV        CL,byte ptr [EDI + DAT_fffffff0]
    //         0044a961     MOV        EAX,dword ptr [ESI + -0x1c]
    //         0044a964     MOV        EBX,dword ptr [ESI + -0x18]
    //         0044a967     MOV        dword ptr [EDI + -0x1c],EAX
    //         0044a96a     MOV        dword ptr [EDI + -0x18],EBX
    //         0044a96d     MOV        EAX,dword ptr [ESI + -0x14]
    //         0044a970     MOV        EBX,dword ptr [ESI + DAT_fffffff0]
    //         0044a973     MOV        dword ptr [EDI + -0x14],EAX
    //         0044a976     MOV        dword ptr [EDI + DAT_fffffff0],EBX
    //         0044a979     MOV        EAX,dword ptr [ESI + DAT_fffffff4]
    //         0044a97c     MOV        EBX,dword ptr [ESI + DAT_fffffff8]
    //         0044a97f     MOV        dword ptr [EDI + DAT_fffffff4],EAX
    //         0044a982     MOV        dword ptr [EDI + DAT_fffffff8],EBX
    //         0044a985     MOV        EAX,dword ptr [ESI + -0x4]
    //         0044a988     MOV        dword ptr [EDI + -0x4],EAX
    //         0044a98b     RET
}

// Offset: 0x0044A98C
undefined FUN_0044a98c() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0044a98c()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0044a98c
    //         0044a98c     MOV        CL,byte ptr [EDI + -0x50]
    //         0044a98f     MOV        EAX,dword ptr [ESI + -0x5b]
    //         0044a992     MOV        EBX,dword ptr [ESI + -0x57]
    //         0044a995     MOV        dword ptr [EDI + -0x5b],EAX
    //         0044a998     MOV        dword ptr [EDI + -0x57],EBX
    //         0044a99b     MOV        EAX,dword ptr [ESI + -0x53]
    //         0044a99e     MOV        EBX,dword ptr [ESI + -0x4f]
    //         0044a9a1     MOV        dword ptr [EDI + -0x53],EAX
    //         0044a9a4     MOV        dword ptr [EDI + -0x4f],EBX
    //         0044a9a7     MOV        CL,byte ptr [EDI + -0x40]
    //         0044a9aa     MOV        EAX,dword ptr [ESI + -0x4b]
    //         0044a9ad     MOV        EBX,dword ptr [ESI + -0x47]
    //         0044a9b0     MOV        dword ptr [EDI + -0x4b],EAX
    //         0044a9b3     MOV        dword ptr [EDI + -0x47],EBX
    //         0044a9b6     MOV        EAX,dword ptr [ESI + -0x43]
    //         0044a9b9     MOV        EBX,dword ptr [ESI + -0x3f]
    //         0044a9bc     MOV        dword ptr [EDI + -0x43],EAX
    //         0044a9bf     MOV        dword ptr [EDI + -0x3f],EBX
    //         0044a9c2     MOV        CL,byte ptr [EDI + -0x30]
    //         0044a9c5     MOV        EAX,dword ptr [ESI + -0x3b]
    //         0044a9c8     MOV        EBX,dword ptr [ESI + -0x37]
    //         0044a9cb     MOV        dword ptr [EDI + -0x3b],EAX
    //         0044a9ce     MOV        dword ptr [EDI + -0x37],EBX
    //         0044a9d1     MOV        EAX,dword ptr [ESI + -0x33]
    //         0044a9d4     MOV        EBX,dword ptr [ESI + -0x2f]
    //         0044a9d7     MOV        dword ptr [EDI + -0x33],EAX
    //         0044a9da     MOV        dword ptr [EDI + -0x2f],EBX
    //         0044a9dd     MOV        CL,byte ptr [EDI + -0x20]
    //         0044a9e0     MOV        EAX,dword ptr [ESI + -0x2b]
    //         0044a9e3     MOV        EBX,dword ptr [ESI + -0x27]
    //         0044a9e6     MOV        dword ptr [EDI + -0x2b],EAX
    //         0044a9e9     MOV        dword ptr [EDI + -0x27],EBX
    //         0044a9ec     MOV        EAX,dword ptr [ESI + -0x23]
    //         0044a9ef     MOV        EBX,dword ptr [ESI + -0x1f]
    //         0044a9f2     MOV        dword ptr [EDI + -0x23],EAX
    //         0044a9f5     MOV        dword ptr [EDI + -0x1f],EBX
    //         0044a9f8     MOV        CL,byte ptr [EDI + DAT_fffffff0]
    //         0044a9fb     MOV        EAX,dword ptr [ESI + -0x1b]
    //         0044a9fe     MOV        EBX,dword ptr [ESI + -0x17]
    //         0044aa01     MOV        dword ptr [EDI + -0x1b],EAX
    //         0044aa04     MOV        dword ptr [EDI + -0x17],EBX
    //         0044aa07     MOV        EAX,dword ptr [ESI + -0x13]
    //         0044aa0a     MOV        EBX,dword ptr [ESI + DAT_fffffff1]
    //         0044aa0d     MOV        dword ptr [EDI + -0x13],EAX
    //         0044aa10     MOV        dword ptr [EDI + DAT_fffffff1],EBX
    //         0044aa13     MOV        EAX,dword ptr [ESI + DAT_fffffff5]
    //         0044aa16     MOV        EBX,dword ptr [ESI + DAT_fffffff9]
    //         0044aa19     MOV        ECX,dword ptr [ESI + -0x4]
    //         0044aa1c     MOV        dword ptr [EDI + DAT_fffffff5],EAX
    //         0044aa1f     MOV        dword ptr [EDI + DAT_fffffff9],EBX
    //         0044aa22     MOV        dword ptr [EDI + -0x4],ECX
    //         0044aa25     RET
}

// Offset: 0x0044AA26
undefined FUN_0044aa26() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0044aa26()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0044aa26
    //         0044aa26     MOV        CL,byte ptr [EDI + -0x4c]
    //         0044aa29     MOV        EAX,dword ptr [ESI + -0x5a]
    //         0044aa2c     MOV        EBX,dword ptr [ESI + -0x56]
    //         0044aa2f     MOV        dword ptr [EDI + -0x5a],EAX
    //         0044aa32     MOV        dword ptr [EDI + -0x56],EBX
    //         0044aa35     MOV        EAX,dword ptr [ESI + -0x52]
    //         0044aa38     MOV        EBX,dword ptr [ESI + -0x4e]
    //         0044aa3b     MOV        dword ptr [EDI + -0x52],EAX
    //         0044aa3e     MOV        dword ptr [EDI + -0x4e],EBX
    //         0044aa41     MOV        CL,byte ptr [EDI + -0x3c]
    //         0044aa44     MOV        EAX,dword ptr [ESI + -0x4a]
    //         0044aa47     MOV        EBX,dword ptr [ESI + -0x46]
    //         0044aa4a     MOV        dword ptr [EDI + -0x4a],EAX
    //         0044aa4d     MOV        dword ptr [EDI + -0x46],EBX
    //         0044aa50     MOV        EAX,dword ptr [ESI + -0x42]
    //         0044aa53     MOV        EBX,dword ptr [ESI + -0x3e]
    //         0044aa56     MOV        dword ptr [EDI + -0x42],EAX
    //         0044aa59     MOV        dword ptr [EDI + -0x3e],EBX
    //         0044aa5c     MOV        CL,byte ptr [EDI + -0x2c]
    //         0044aa5f     MOV        EAX,dword ptr [ESI + -0x3a]
    //         0044aa62     MOV        EBX,dword ptr [ESI + -0x36]
    //         0044aa65     MOV        dword ptr [EDI + -0x3a],EAX
    //         0044aa68     MOV        dword ptr [EDI + -0x36],EBX
    //         0044aa6b     MOV        EAX,dword ptr [ESI + -0x32]
    //         0044aa6e     MOV        EBX,dword ptr [ESI + -0x2e]
    //         0044aa71     MOV        dword ptr [EDI + -0x32],EAX
    //         0044aa74     MOV        dword ptr [EDI + -0x2e],EBX
    //         0044aa77     MOV        CL,byte ptr [EDI + -0x1c]
    //         0044aa7a     MOV        EAX,dword ptr [ESI + -0x2a]
    //         0044aa7d     MOV        EBX,dword ptr [ESI + -0x26]
    //         0044aa80     MOV        dword ptr [EDI + -0x2a],EAX
    //         0044aa83     MOV        dword ptr [EDI + -0x26],EBX
    //         0044aa86     MOV        EAX,dword ptr [ESI + -0x22]
    //         0044aa89     MOV        EBX,dword ptr [ESI + -0x1e]
    //         0044aa8c     MOV        dword ptr [EDI + -0x22],EAX
    //         0044aa8f     MOV        dword ptr [EDI + -0x1e],EBX
    //         0044aa92     MOV        CL,byte ptr [EDI + DAT_fffffff4]
    //         0044aa95     MOV        EAX,dword ptr [ESI + -0x1a]
    //         0044aa98     MOV        EBX,dword ptr [ESI + -0x16]
    //         0044aa9b     MOV        dword ptr [EDI + -0x1a],EAX
    //         0044aa9e     MOV        dword ptr [EDI + -0x16],EBX
    //         0044aaa1     MOV        EAX,dword ptr [ESI + -0x12]
    //         0044aaa4     MOV        EBX,dword ptr [ESI + DAT_fffffff2]
    //         0044aaa7     MOV        dword ptr [EDI + -0x12],EAX
    //         0044aaaa     MOV        dword ptr [EDI + DAT_fffffff2],EBX
    //         0044aaad     MOV        EAX,dword ptr [ESI + DAT_fffffff6]
    //         0044aab0     MOV        EBX,dword ptr [ESI + DAT_fffffffa]
    //         0044aab3     MOV        dword ptr [EDI + DAT_fffffff6],EAX
    //         0044aab6     MOV        dword ptr [EDI + DAT_fffffffa],EBX
    //         0044aab9     MOV        EAX,dword ptr [ESI + -0x2]
    //         0044aabc     MOV        byte ptr [EDI + -0x2],AL
    //         0044aabf     MOV        byte ptr [EDI + -0x1],AH
    //         0044aac2     RET
}

// Offset: 0x0044AAC3
undefined FUN_0044aac3() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0044aac3()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0044aac3
    //         0044aac3     MOV        CL,byte ptr [EDI + -0x4c]
    //         0044aac6     MOV        EAX,dword ptr [ESI + -0x59]
    //         0044aac9     MOV        EBX,dword ptr [ESI + -0x55]
    //         0044aacc     MOV        dword ptr [EDI + -0x59],EAX
    //         0044aacf     MOV        dword ptr [EDI + -0x55],EBX
    //         0044aad2     MOV        EAX,dword ptr [ESI + -0x51]
    //         0044aad5     MOV        EBX,dword ptr [ESI + -0x4d]
    //         0044aad8     MOV        dword ptr [EDI + -0x51],EAX
    //         0044aadb     MOV        dword ptr [EDI + -0x4d],EBX
    //         0044aade     MOV        CL,byte ptr [EDI + -0x3c]
    //         0044aae1     MOV        EAX,dword ptr [ESI + -0x49]
    //         0044aae4     MOV        EBX,dword ptr [ESI + -0x45]
    //         0044aae7     MOV        dword ptr [EDI + -0x49],EAX
    //         0044aaea     MOV        dword ptr [EDI + -0x45],EBX
    //         0044aaed     MOV        EAX,dword ptr [ESI + -0x41]
    //         0044aaf0     MOV        EBX,dword ptr [ESI + -0x3d]
    //         0044aaf3     MOV        dword ptr [EDI + -0x41],EAX
    //         0044aaf6     MOV        dword ptr [EDI + -0x3d],EBX
    //         0044aaf9     MOV        CL,byte ptr [EDI + -0x2c]
    //         0044aafc     MOV        EAX,dword ptr [ESI + -0x39]
    //         0044aaff     MOV        EBX,dword ptr [ESI + -0x35]
    //         0044ab02     MOV        dword ptr [EDI + -0x39],EAX
    //         0044ab05     MOV        dword ptr [EDI + -0x35],EBX
    //         0044ab08     MOV        EAX,dword ptr [ESI + -0x31]
    //         0044ab0b     MOV        EBX,dword ptr [ESI + -0x2d]
    //         0044ab0e     MOV        dword ptr [EDI + -0x31],EAX
    //         0044ab11     MOV        dword ptr [EDI + -0x2d],EBX
    //         0044ab14     MOV        CL,byte ptr [EDI + -0x1c]
    //         0044ab17     MOV        EAX,dword ptr [ESI + -0x29]
    //         0044ab1a     MOV        EBX,dword ptr [ESI + -0x25]
    //         0044ab1d     MOV        dword ptr [EDI + -0x29],EAX
    //         0044ab20     MOV        dword ptr [EDI + -0x25],EBX
    //         0044ab23     MOV        EAX,dword ptr [ESI + -0x21]
    //         0044ab26     MOV        EBX,dword ptr [ESI + -0x1d]
    //         0044ab29     MOV        dword ptr [EDI + -0x21],EAX
    //         0044ab2c     MOV        dword ptr [EDI + -0x1d],EBX
    //         0044ab2f     MOV        CL,byte ptr [EDI + DAT_fffffff4]
    //         0044ab32     MOV        EAX,dword ptr [ESI + -0x19]
    //         0044ab35     MOV        EBX,dword ptr [ESI + -0x15]
    //         0044ab38     MOV        dword ptr [EDI + -0x19],EAX
    //         0044ab3b     MOV        dword ptr [EDI + -0x15],EBX
    //         0044ab3e     MOV        EAX,dword ptr [ESI + -0x11]
    //         0044ab41     MOV        EBX,dword ptr [ESI + DAT_fffffff3]
    //         0044ab44     MOV        dword ptr [EDI + -0x11],EAX
    //         0044ab47     MOV        dword ptr [EDI + DAT_fffffff3],EBX
    //         0044ab4a     MOV        EAX,dword ptr [ESI + DAT_fffffff7]
    //         0044ab4d     MOV        EBX,dword ptr [ESI + DAT_fffffffb]
    //         0044ab50     MOV        CL,byte ptr [ESI + -0x1]
    //         0044ab53     MOV        dword ptr [EDI + DAT_fffffff7],EAX
    //         0044ab56     MOV        dword ptr [EDI + DAT_fffffffb],EBX
    //         0044ab59     MOV        byte ptr [EDI + -0x1],CL
    //         0044ab5c     RET
}

// Offset: 0x0044AB5D
undefined x_StandardMemCopy() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined _x_StandardMemCopy()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               _x_StandardMemCopy
    //         0044ab5d     MOV        EAX,ECX
    //         0044ab5f     SUB        ECX,EDI
    //         0044ab61     SUB        ECX,EAX
    //         0044ab63     AND        ECX,0x3
    //         0044ab66     SUB        EAX,ECX
    //         0044ab68     MOV        EDX,dword ptr [ESI]
    //         0044ab6a     ADD        ESI,ECX
    //         0044ab6c     MOV        dword ptr [EDI],EDX
    //         0044ab6e     ADD        EDI,ECX
    //         0044ab70     MOV        ECX,EAX
    //         0044ab72     AND        EAX,0x3
    //         0044ab75     SHR        ECX,0x2
    //         0044ab78     MOVSD.REP  ES:EDI,ESI
    //         0044ab7a     ADD        ECX,EAX
    //         0044ab7c     MOV        EDX,dword ptr [EAX + ESI*0x1 + -0x4]
    //         0044ab80     MOV        dword ptr [EAX + EDI*0x1 + -0x4],EDX
    //         0044ab84     RET
}

