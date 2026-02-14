// Auto-generated scaffold unit: bucket_0547.asm
#include "../include/common.h"

// Offset: 0x005479A0
undefined deflate_data() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * deflate_data                                                                                          *
    //                              *********************************************************************************************************
    //                              undefined __cdecl deflate_data()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               _deflate_data                                                XREF[2]:     rge_close:0047ff62(c), 
    //                               deflate_data                                                              rge_write:0048036b(c)  
    //         005479a0     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         005479a4     MOV        [DAT_00887a80],EAX
    //         005479a9     TEST       EAX,EAX
    //         005479ab     JZ         LAB_00547b25
    //         005479b1     CMP        dword ptr [EAX + 0x38178],0x12345678
    //         005479bb     JNZ        LAB_00547b25
    //         005479c1     MOV        ECX,dword ptr [ESP + Stack[0x8]]
    //         005479c5     MOV        dword ptr [EAX + 0x3815c],ECX
    //         005479cb     MOV        EAX,dword ptr [ESP + Stack[0xc]]
    //         005479cf     MOV        EDX,dword ptr [DAT_00887a80]
    //         005479d5     MOV        dword ptr [EDX + 0x38160],EAX
    //         005479db     MOV        EDX,dword ptr [DAT_00887a80]
    //         005479e1     MOV        EAX,dword ptr [EDX + 0x3815c]
    //         005479e7     MOV        dword ptr [EDX + 0x38154],EAX
    //         005479ed     MOV        EDX,dword ptr [DAT_00887a80]
    //         005479f3     MOV        EAX,dword ptr [EDX + 0x38160]
    //         005479f9     MOV        dword ptr [EDX + 0x38158],EAX
    //         005479ff     MOV        EDX,dword ptr [DAT_00887a80]
    //         00547a05     MOV        EAX,dword ptr [ESP + Stack[0x10]]
    //         00547a09     MOV        dword ptr [EDX + 0x38140],EAX
    //         00547a0f     MOV        EDX,dword ptr [DAT_00887a80]
    //         00547a15     MOV        dword ptr [DAT_00887a94],EDX
    //         00547a1b     LEA        EAX,[EDX + 0x9102]
    //         00547a21     MOV        [DAT_00887fa4],EAX
    //         00547a26     LEA        EAX,[EDX + 0xd102]
    //         00547a2c     MOV        [DAT_00886cf0],EAX
    //         00547a31     LEA        EAX,[EDX + 0x1d102]
    //         00547a37     MOV        [DAT_00886cec],EAX
    //         00547a3c     MOV        EAX,[DAT_00887a80]
    //         00547a41     MOV        ECX,dword ptr [EDX + 0x38134]
    //         00547a47     MOV        dword ptr [DAT_00886c60],ECX
    //         00547a4d     MOV        EDX,dword ptr [EDX + 0x3812c]
    //         00547a53     MOV        dword ptr [DAT_00887b1c],EDX
    //         00547a59     MOV        ECX,dword ptr [EAX + 0x38130]
    //         00547a5f     MOV        dword ptr [DAT_00887fa8],ECX
    //         00547a65     MOV        EDX,dword ptr [EAX + 0x38110]
    //         00547a6b     MOV        dword ptr [DAT_00887a8c],EDX
    //         00547a71     MOV        ECX,dword ptr [EAX + 0x38114]
    //         00547a77     MOV        dword ptr [DAT_00886cf4],ECX
    //         00547a7d     MOV        EDX,dword ptr [EAX + 0x38118]
    //         00547a83     MOV        dword ptr [DAT_00887a84],EDX
    //         00547a89     MOV        ECX,dword ptr [EAX + 0x38170]
    //         00547a8f     MOV        dword ptr [DAT_00887a90],ECX
    //         00547a95     MOV        EDX,dword ptr [EAX + 0x38174]
    //         00547a9b     MOV        dword ptr [DAT_00887a88],EDX
    //         00547aa1     CALL       FUN_00547b30                                     undefined FUN_00547b30()
    //         00547aa6     MOV        ECX,dword ptr [DAT_00887b1c]
    //         00547aac     MOV        EDX,dword ptr [DAT_00887a80]
    //         00547ab2     MOV        dword ptr [EDX + 0x3812c],ECX
    //         00547ab8     MOV        ECX,dword ptr [DAT_00887fa8]
    //         00547abe     MOV        EDX,dword ptr [DAT_00887a80]
    //         00547ac4     MOV        dword ptr [EDX + 0x38130],ECX
    //         00547aca     MOV        ECX,dword ptr [DAT_00887a8c]
    //         00547ad0     MOV        EDX,dword ptr [DAT_00887a80]
    //         00547ad6     MOV        dword ptr [EDX + 0x38110],ECX
    //         00547adc     MOV        ECX,dword ptr [DAT_00886cf4]
    //         00547ae2     MOV        EDX,dword ptr [DAT_00887a80]
    //         00547ae8     MOV        dword ptr [EDX + 0x38114],ECX
    //         00547aee     MOV        ECX,dword ptr [DAT_00887a84]
    //         00547af4     MOV        EDX,dword ptr [DAT_00887a80]
    //         00547afa     MOV        dword ptr [EDX + 0x38118],ECX
    //         00547b00     MOV        ECX,dword ptr [DAT_00887a90]
    //         00547b06     MOV        EDX,dword ptr [DAT_00887a80]
    //         00547b0c     MOV        dword ptr [EDX + 0x38170],ECX
    //         00547b12     MOV        ECX,dword ptr [DAT_00887a88]
    //         00547b18     MOV        EDX,dword ptr [DAT_00887a80]
    //         00547b1e     MOV        dword ptr [EDX + 0x38174],ECX
    //         00547b24     RET
    //                               LAB_00547b25                                                 XREF[2]:     005479ab(j), 005479bb(j)  
    //         00547b25     MOV        EAX,0x2
    //         00547b2a     RET
}

// Offset: 0x00547B30
undefined FUN_00547b30() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00547b30()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00547b30                                                 XREF[1]:     deflate_data:00547aa1(c)  
    //         00547b30     PUSH       EBX
    //         00547b31     PUSH       ESI
    //         00547b32     PUSH       EDI
    //         00547b33     XOR        ESI,ESI
    //         00547b35     MOV        EDI,0x1000
    //         00547b3a     MOV        EBX,0x1
    //                               LAB_00547b3f                                                 XREF[1]:     00547c15(j)  
    //         00547b3f     CALL       FUN_0054a380                                     undefined FUN_0054a380()
    //         00547b44     TEST       EAX,EAX
    //         00547b46     JZ         LAB_00547b59
    //         00547b48     MOV        EAX,[DAT_00887a80]
    //         00547b4d     CMP        dword ptr [EAX + 0x38140],ESI
    //         00547b53     JZ         LAB_00547c1a
    //                               LAB_00547b59                                                 XREF[1]:     00547b46(j)  
    //         00547b59     MOV        EAX,[DAT_00887a80]
    //         00547b5e     CMP        dword ptr [EAX + 0x38144],ESI
    //         00547b64     JZ         LAB_00547b75
    //         00547b66     MOV        ECX,dword ptr [EAX + 0x38148]
    //         00547b6c     PUSH       ECX
    //         00547b6d     CALL       FUN_00547ef0                                     undefined FUN_00547ef0()
    //         00547b72     ADD        ESP,0x4
    //                               LAB_00547b75                                                 XREF[1]:     00547b64(j)  
    //         00547b75     MOV        EAX,[DAT_00887a80]
    //         00547b7a     MOV        ECX,dword ptr [EAX + 0x38124]
    //         00547b80     MOV        EDX,dword ptr [EAX + 0x38148]
    //         00547b86     PUSH       ECX
    //         00547b87     PUSH       EDX
    //         00547b88     CALL       FUN_00547f40                                     undefined FUN_00547f40()
    //         00547b8d     ADD        ESP,0x8
    //         00547b90     MOV        ECX,dword ptr [DAT_00887a80]
    //         00547b96     CMP        dword ptr [ECX + 0x38148],ESI
    //         00547b9c     JNZ        LAB_00547bb3
    //         00547b9e     PUSH       0x1102
    //         00547ba3     LEA        EAX,[ECX + 0x8000]
    //         00547ba9     PUSH       ECX
    //         00547baa     PUSH       EAX
    //         00547bab     CALL       FUN_00547c90                                     undefined FUN_00547c90()
    //         00547bb0     ADD        ESP,0xc
    //                               LAB_00547bb3                                                 XREF[1]:     00547b9c(j)  
    //         00547bb3     MOV        EAX,[DAT_00887a80]
    //         00547bb8     MOV        ECX,dword ptr [EAX + 0x38148]
    //         00547bbe     PUSH       ECX
    //         00547bbf     CALL       FUN_00549460                                     undefined FUN_00549460()
    //         00547bc4     ADD        ESP,0x4
    //         00547bc7     TEST       EAX,EAX
    //         00547bc9     JNZ        LAB_00547c20
    //         00547bcb     MOV        EAX,[DAT_00887a80]
    //         00547bd0     ADD        dword ptr [EAX + 0x38148],EDI
    //         00547bd6     MOV        EAX,[DAT_00887a80]
    //         00547bdb     ADD        EAX,0x38148
    //         00547be0     CMP        dword ptr [EAX],0x8000
    //         00547be6     JNZ        LAB_00547bf5
    //         00547be8     MOV        dword ptr [EAX],ESI
    //         00547bea     MOV        EAX,[DAT_00887a80]
    //         00547bef     MOV        dword ptr [EAX + 0x38144],EBX
    //                               LAB_00547bf5                                                 XREF[1]:     00547be6(j)  
    //         00547bf5     MOV        EAX,[DAT_00887a80]
    //         00547bfa     CMP        dword ptr [EAX + 0x38140],ESI
    //         00547c00     JZ         LAB_00547c0a
    //         00547c02     CMP        dword ptr [EAX + 0x38158],ESI
    //         00547c08     JZ         LAB_00547c29
    //                               LAB_00547c0a                                                 XREF[1]:     00547c00(j)  
    //         00547c0a     MOV        EAX,[DAT_00887a80]
    //         00547c0f     MOV        dword ptr [EAX + 0x38124],ESI
    //         00547c15     JMP        LAB_00547b3f
    //                               LAB_00547c1a                                                 XREF[1]:     00547b53(j)  
    //         00547c1a     XOR        EAX,EAX
    //         00547c1c     POP        EDI
    //         00547c1d     POP        ESI
    //         00547c1e     POP        EBX
    //         00547c1f     RET
    //                               LAB_00547c20                                                 XREF[1]:     00547bc9(j)  
    //         00547c20     MOV        EAX,0x1
    //         00547c25     POP        EDI
    //         00547c26     POP        ESI
    //         00547c27     POP        EBX
    //         00547c28     RET
    //                               LAB_00547c29                                                 XREF[1]:     00547c08(j)  
    //         00547c29     CALL       FUN_0054a360                                     undefined FUN_0054a360()
    //         00547c2e     TEST       EAX,EAX
    //         00547c30     JZ         LAB_00547c3b
    //         00547c32     MOV        EAX,0x1
    //         00547c37     POP        EDI
    //         00547c38     POP        ESI
    //         00547c39     POP        EBX
    //         00547c3a     RET
    //                               LAB_00547c3b                                                 XREF[1]:     00547c30(j)  
    //         00547c3b     CALL       FUN_00548030                                     undefined FUN_00548030()
    //         00547c40     TEST       EAX,EAX
    //         00547c42     JZ         LAB_00547c4d
    //         00547c44     MOV        EAX,0x1
    //         00547c49     POP        EDI
    //         00547c4a     POP        ESI
    //         00547c4b     POP        EBX
    //         00547c4c     RET
    //                               LAB_00547c4d                                                 XREF[1]:     00547c42(j)  
    //         00547c4d     CALL       FUN_00547d50                                     undefined FUN_00547d50()
    //         00547c52     TEST       EAX,EAX
    //         00547c54     JZ         LAB_00547c5f
    //         00547c56     MOV        EAX,0x1
    //         00547c5b     POP        EDI
    //         00547c5c     POP        ESI
    //         00547c5d     POP        EBX
    //         00547c5e     RET
    //                               LAB_00547c5f                                                 XREF[1]:     00547c54(j)  
    //         00547c5f     CALL       FUN_00547cf0                                     undefined FUN_00547cf0()
    //         00547c64     TEST       EAX,EAX
    //         00547c66     JZ         LAB_00547c71
    //         00547c68     MOV        EAX,0x1
    //         00547c6d     POP        EDI
    //         00547c6e     POP        ESI
    //         00547c6f     POP        EBX
    //         00547c70     RET
    //                               LAB_00547c71                                                 XREF[1]:     00547c66(j)  
    //         00547c71     MOV        EAX,[DAT_00887a80]
    //         00547c76     POP        EDI
    //         00547c77     POP        ESI
    //         00547c78     POP        EBX
    //         00547c79     MOV        dword ptr [EAX + 0x38178],0xabcd1234
    //         00547c83     MOV        EAX,0x1
    //         00547c88     RET
}

// Offset: 0x00547C90
undefined FUN_00547c90() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00547c90()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00547c90                                                 XREF[2]:     FUN_00547b30:00547bab(c), 
    //                                                                                                         FUN_0054a380:0054a3b2(c)  
    //         00547c90     PUSH       ESI
    //         00547c91     PUSH       EDI
    //         00547c92     MOV        ESI,dword ptr [ESP + Stack[0xc]]
    //         00547c96     CMP        ESI,0x10
    //         00547c99     JL         LAB_00547cd0
    //         00547c9b     MOV        EDX,ESI
    //         00547c9d     MOV        ECX,dword ptr [ESP + Stack[0x4]]
    //         00547ca1     SHR        EDX,0x4
    //         00547ca4     MOV        EDI,dword ptr [ESP + Stack[0x8]]
    //         00547ca8     MOV        EAX,EDX
    //         00547caa     SHL        EAX,0x4
    //         00547cad     SUB        ESI,EAX
    //                               LAB_00547caf                                                 XREF[1]:     00547ccc(j)  
    //         00547caf     MOV        EAX,dword ptr [EDI]
    //         00547cb1     ADD        EDI,0x10
    //         00547cb4     MOV        dword ptr [ECX],EAX
    //         00547cb6     ADD        ECX,0x10
    //         00547cb9     MOV        EAX,dword ptr [EDI + -0xc]
    //         00547cbc     DEC        EDX
    //         00547cbd     MOV        dword ptr [ECX + -0xc],EAX
    //         00547cc0     MOV        EAX,dword ptr [EDI + -0x8]
    //         00547cc3     MOV        dword ptr [ECX + -0x8],EAX
    //         00547cc6     MOV        EAX,dword ptr [EDI + -0x4]
    //         00547cc9     MOV        dword ptr [ECX + -0x4],EAX
    //         00547ccc     JNZ        LAB_00547caf
    //         00547cce     JMP        LAB_00547cd8
    //                               LAB_00547cd0                                                 XREF[1]:     00547c99(j)  
    //         00547cd0     MOV        ECX,dword ptr [ESP + Stack[0x4]]
    //         00547cd4     MOV        EDI,dword ptr [ESP + Stack[0x8]]
    //                               LAB_00547cd8                                                 XREF[1]:     00547cce(j)  
    //         00547cd8     TEST       ESI,ESI
    //         00547cda     JZ         LAB_00547ce5
    //                               LAB_00547cdc                                                 XREF[1]:     00547ce3(j)  
    //         00547cdc     MOV        AL,byte ptr [EDI]
    //         00547cde     INC        EDI
    //         00547cdf     MOV        byte ptr [ECX],AL
    //         00547ce1     INC        ECX
    //         00547ce2     DEC        ESI
    //         00547ce3     JNZ        LAB_00547cdc
    //                               LAB_00547ce5                                                 XREF[1]:     00547cda(j)  
    //         00547ce5     POP        EDI
    //         00547ce6     POP        ESI
    //         00547ce7     RET
}

// Offset: 0x00547CF0
undefined FUN_00547cf0() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00547cf0()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00547cf0                                                 XREF[9]:     FUN_00547b30:00547c5f(c), 
    //                                                                                                         FUN_00547d80:00547def(c), 
    //                                                                                                         FUN_00547d80:00547e1f(c), 
    //                                                                                                         FUN_00547d80:00547e94(c), 
    //                                                                                                         FUN_005492f0:00549329(c), 
    //                                                                                                         FUN_005492f0:00549361(c), 
    //                                                                                                         FUN_005492f0:00549399(c), 
    //                                                                                                         FUN_005492f0:005493d2(c), 
    //                                                                                                         FUN_005492f0:00549424(c)  
    //         00547cf0     MOV        EAX,[DAT_00887a80]
    //         00547cf5     MOV        ECX,dword ptr [DAT_00887a80]
    //         00547cfb     MOV        EAX,dword ptr [EAX + 0x38168]
    //         00547d01     MOV        EDX,dword ptr [ECX + 0x38164]
    //         00547d07     SUB        EAX,dword ptr [DAT_00887a88]
    //         00547d0d     PUSH       EAX
    //         00547d0e     PUSH       EDX
    //         00547d0f     CALL       dword ptr [ECX + 0x3816c]
    //         00547d15     ADD        ESP,0x8
    //         00547d18     TEST       EAX,EAX
    //         00547d1a     JZ         LAB_00547d22
    //         00547d1c     MOV        EAX,0x1
    //         00547d21     RET
    //                               LAB_00547d22                                                 XREF[1]:     00547d1a(j)  
    //         00547d22     MOV        EAX,[DAT_00887a80]
    //         00547d27     MOV        ECX,dword ptr [EAX + 0x38164]
    //         00547d2d     MOV        dword ptr [DAT_00887a90],ECX
    //         00547d33     MOV        EDX,dword ptr [EAX + 0x38168]
    //         00547d39     XOR        EAX,EAX
    //         00547d3b     MOV        dword ptr [DAT_00887a88],EDX
    //         00547d41     RET
}

// Offset: 0x00547D50
undefined FUN_00547d50() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00547d50()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00547d50                                                 XREF[2]:     FUN_00547b30:00547c4d(c), 
    //                                                                                                         FUN_005492f0:0054930a(c)  
    //         00547d50     PUSH       0x7
    //         00547d52     PUSH       0x0
    //         00547d54     CALL       FUN_00547d80                                     undefined FUN_00547d80()
    //         00547d59     ADD        ESP,0x8
    //         00547d5c     TEST       EAX,EAX
    //         00547d5e     JZ         LAB_00547d66
    //         00547d60     MOV        EAX,0x1
    //         00547d65     RET
    //                               LAB_00547d66                                                 XREF[1]:     00547d5e(j)  
    //         00547d66     MOV        dword ptr [DAT_00886cf4],0x0
    //         00547d70     XOR        EAX,EAX
    //         00547d72     RET
}

// Offset: 0x00547D80
undefined FUN_00547d80() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00547d80()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00547d80                                                 XREF[22]:    FUN_00547d50:00547d54(c), 
    //                                                                                                         FUN_005480b0:005480d8(c), 
    //                                                                                                         FUN_005480b0:005483ce(c), 
    //                                                                                                         FUN_00548410:005484a7(c), 
    //                                                                                                         FUN_00548410:005484cb(c), 
    //                                                                                                         FUN_00548410:00548502(c), 
    //                                                                                                         FUN_00548410:00548526(c), 
    //                                                                                                         FUN_00548410:00548563(c), 
    //                                                                                                         FUN_00548410:00548589(c), 
    //                                                                                                         FUN_00548410:005485bc(c), 
    //                                                                                                         FUN_00548410:005485f0(c), 
    //                                                                                                         FUN_005488f0:005488f4(c), 
    //                                                                                                         FUN_00549120:00549124(c), 
    //                                                                                                         FUN_00549150:00549165(c), 
    //                                                                                                         FUN_00549150:00549188(c), 
    //                                                                                                         FUN_00549150:005491ce(c), 
    //                                                                                                         FUN_00549150:005491ff(c), 
    //                                                                                                         FUN_00549150:0054924d(c), 
    //                                                                                                         FUN_00549150:00549268(c), 
    //                                                                                                         FUN_00549150:00549293(c), [more]
    //         00547d80     CMP        dword ptr [DAT_00887a84],0x0
    //         00547d87     JZ         LAB_00547d9c
    //         00547d89     MOV        ECX,dword ptr [DAT_00887a80]
    //         00547d8f     MOV        EAX,dword ptr [ESP + Stack[0x8]]
    //         00547d93     ADD        dword ptr [ECX + 0x3811c],EAX
    //         00547d99     XOR        EAX,EAX
    //         00547d9b     RET
    //                               LAB_00547d9c                                                 XREF[1]:     00547d87(j)  
    //         00547d9c     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         00547da0     MOV        CL,byte ptr [DAT_00886cf4]
    //         00547da6     SHL        EAX,CL
    //         00547da8     MOV        ECX,dword ptr [ESP + Stack[0x8]]
    //         00547dac     OR         dword ptr [DAT_00887a8c],EAX
    //         00547db2     ADD        dword ptr [DAT_00886cf4],ECX
    //         00547db8     CMP        dword ptr [DAT_00886cf4],0x8
    //         00547dbf     JGE        LAB_00547dc4
    //         00547dc1     XOR        EAX,EAX
    //         00547dc3     RET
    //                               LAB_00547dc4                                                 XREF[1]:     00547dbf(j)  
    //         00547dc4     CMP        dword ptr [DAT_00886cf4],0x10
    //         00547dcb     JL         LAB_00547e78
    //         00547dd1     SUB        dword ptr [DAT_00887a88],0x2
    //         00547dd8     JNS        LAB_00547e52
    //         00547dda     ADD        dword ptr [DAT_00887a88],0x2
    //                               LAB_00547de1                                                 XREF[1]:     00547df6(j)  
    //         00547de1     DEC        dword ptr [DAT_00887a88]
    //         00547de7     JNS        LAB_00547dfe
    //         00547de9     INC        dword ptr [DAT_00887a88]
    //         00547def     CALL       FUN_00547cf0                                     undefined FUN_00547cf0()
    //         00547df4     TEST       EAX,EAX
    //         00547df6     JZ         LAB_00547de1
    //         00547df8     MOV        EAX,0x1
    //         00547dfd     RET
    //                               LAB_00547dfe                                                 XREF[1]:     00547de7(j)  
    //         00547dfe     MOV        CL,byte ptr [DAT_00887a8c]
    //         00547e04     MOV        EAX,[DAT_00887a90]
    //         00547e09     MOV        byte ptr [EAX],CL
    //         00547e0b     INC        dword ptr [DAT_00887a90]
    //                               LAB_00547e11                                                 XREF[1]:     00547e26(j)  
    //         00547e11     DEC        dword ptr [DAT_00887a88]
    //         00547e17     JNS        LAB_00547e2e
    //         00547e19     INC        dword ptr [DAT_00887a88]
    //         00547e1f     CALL       FUN_00547cf0                                     undefined FUN_00547cf0()
    //         00547e24     TEST       EAX,EAX
    //         00547e26     JZ         LAB_00547e11
    //         00547e28     MOV        EAX,0x1
    //         00547e2d     RET
    //                               LAB_00547e2e                                                 XREF[1]:     00547e17(j)  
    //         00547e2e     MOV        ECX,dword ptr [DAT_00887a8c]
    //         00547e34     MOV        EAX,[DAT_00887a90]
    //         00547e39     MOV        byte ptr [EAX],CH
    //         00547e3b     XOR        EAX,EAX
    //         00547e3d     SHR        dword ptr [DAT_00887a8c],0x10
    //         00547e44     SUB        dword ptr [DAT_00886cf4],0x10
    //         00547e4b     INC        dword ptr [DAT_00887a90]
    //         00547e51     RET
    //                               LAB_00547e52                                                 XREF[1]:     00547dd8(j)  
    //         00547e52     MOV        EAX,[DAT_00887a8c]
    //         00547e57     MOV        ECX,dword ptr [DAT_00887a90]
    //         00547e5d     MOV        word ptr [ECX],AX
    //         00547e60     XOR        EAX,EAX
    //         00547e62     ADD        dword ptr [DAT_00887a90],0x2
    //         00547e69     SHR        dword ptr [DAT_00887a8c],0x10
    //         00547e70     SUB        dword ptr [DAT_00886cf4],0x10
    //         00547e77     RET
    //                               LAB_00547e78                                                 XREF[1]:     00547dcb(j)  
    //         00547e78     DEC        dword ptr [DAT_00887a88]
    //         00547e7e     JNS        LAB_00547ec7
    //         00547e80     INC        dword ptr [DAT_00887a88]
    //                               LAB_00547e86                                                 XREF[1]:     00547e9b(j)  
    //         00547e86     DEC        dword ptr [DAT_00887a88]
    //         00547e8c     JNS        LAB_00547ea3
    //         00547e8e     INC        dword ptr [DAT_00887a88]
    //         00547e94     CALL       FUN_00547cf0                                     undefined FUN_00547cf0()
    //         00547e99     TEST       EAX,EAX
    //         00547e9b     JZ         LAB_00547e86
    //         00547e9d     MOV        EAX,0x1
    //         00547ea2     RET
    //                               LAB_00547ea3                                                 XREF[1]:     00547e8c(j)  
    //         00547ea3     MOV        CL,byte ptr [DAT_00887a8c]
    //         00547ea9     MOV        EAX,[DAT_00887a90]
    //         00547eae     MOV        byte ptr [EAX],CL
    //         00547eb0     XOR        EAX,EAX
    //         00547eb2     SHR        dword ptr [DAT_00887a8c],0x8
    //         00547eb9     SUB        dword ptr [DAT_00886cf4],0x8
    //         00547ec0     INC        dword ptr [DAT_00887a90]
    //         00547ec6     RET
    //                               LAB_00547ec7                                                 XREF[1]:     00547e7e(j)  
    //         00547ec7     MOV        CL,byte ptr [DAT_00887a8c]
    //         00547ecd     MOV        EAX,[DAT_00887a90]
    //         00547ed2     MOV        byte ptr [EAX],CL
    //         00547ed4     XOR        EAX,EAX
    //         00547ed6     SHR        dword ptr [DAT_00887a8c],0x8
    //         00547edd     SUB        dword ptr [DAT_00886cf4],0x8
    //         00547ee4     INC        dword ptr [DAT_00887a90]
    //         00547eea     RET
}

// Offset: 0x00547EF0
undefined FUN_00547ef0() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00547ef0()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00547ef0                                                 XREF[1]:     FUN_00547b30:00547b6d(c)  
    //         00547ef0     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         00547ef4     PUSH       ESI
    //         00547ef5     LEA        EDX,[EAX + 0x1000]
    //         00547efb     CMP        EDX,EAX
    //         00547efd     JBE        LAB_00547f3e
    //         00547eff     LEA        ESI,[EAX*0x2 + 0x0]
    //         00547f06     SUB        EDX,EAX
    //                               LAB_00547f08                                                 XREF[1]:     00547f3c(j)  
    //         00547f08     MOV        EAX,[DAT_00886cec]
    //         00547f0d     XOR        ECX,ECX
    //         00547f0f     MOV        CX,word ptr [EAX + ESI*0x1]
    //         00547f13     TEST       CH,0x80
    //         00547f16     JZ         LAB_00547f2d
    //         00547f18     CMP        ECX,0xffff
    //         00547f1e     JZ         LAB_00547f38
    //         00547f20     AND        ECX,0x7fff
    //         00547f26     MOV        EAX,[DAT_00887fa4]
    //         00547f2b     JMP        LAB_00547f32
    //                               LAB_00547f2d                                                 XREF[1]:     00547f16(j)  
    //         00547f2d     MOV        EAX,[DAT_00886cf0]
    //                               LAB_00547f32                                                 XREF[1]:     00547f2b(j)  
    //         00547f32     MOV        word ptr [EAX + ECX*0x2],0xffff
    //                               LAB_00547f38                                                 XREF[1]:     00547f1e(j)  
    //         00547f38     ADD        ESI,0x2
    //         00547f3b     DEC        EDX
    //         00547f3c     JNZ        LAB_00547f08
    //                               LAB_00547f3e                                                 XREF[1]:     00547efd(j)  
    //         00547f3e     POP        ESI
    //         00547f3f     RET
}

// Offset: 0x00547F40
undefined FUN_00547f40() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00547f40()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00547f40                                                 XREF[1]:     FUN_00547b30:00547b88(c)  
    //         00547f40     PUSH       EBX
    //         00547f41     PUSH       ESI
    //         00547f42     MOV        ESI,dword ptr [ESP + Stack[0x8]]
    //         00547f46     PUSH       EDI
    //         00547f47     LEA        EBX,[ESI + -0x2]
    //         00547f4a     TEST       EBX,EBX
    //         00547f4c     JG         LAB_00547f50
    //         00547f4e     XOR        EBX,EBX
    //                               LAB_00547f50                                                 XREF[1]:     00547f4c(j)  
    //         00547f50     MOV        ECX,dword ptr [ESP + Stack[0x4]]
    //         00547f54     CMP        ESI,EBX
    //         00547f56     JBE        LAB_00547f8d
    //         00547f58     LEA        EAX,[EBX + ECX*0x1]
    //         00547f5b     MOV        EDX,ESI
    //         00547f5d     SUB        EDX,EBX
    //         00547f5f     LEA        EDI,[EAX*0x2 + 0x0]
    //                               LAB_00547f66                                                 XREF[1]:     00547f8b(j)  
    //         00547f66     MOV        EAX,[DAT_00886cec]
    //         00547f6b     ADD        EDI,0x2
    //         00547f6e     MOV        word ptr [EAX + EDI*0x1 + -0x2],0xffff
    //         00547f75     MOV        EAX,[DAT_00886cec]
    //         00547f7a     MOV        EBX,dword ptr [DAT_00886cf0]
    //         00547f80     MOV        AX,word ptr [EAX + EDI*0x1 + -0x2]
    //         00547f85     DEC        EDX
    //         00547f86     MOV        word ptr [EBX + EDI*0x1 + -0x2],AX
    //         00547f8b     JNZ        LAB_00547f66
    //                               LAB_00547f8d                                                 XREF[1]:     00547f56(j)  
    //         00547f8d     CMP        ESI,0x2
    //         00547f90     JLE        LAB_00548022
    //         00547f96     MOV        EDI,dword ptr [DAT_00887a94]
    //         00547f9c     XOR        EDX,EDX
    //         00547f9e     ADD        EDI,ECX
    //         00547fa0     XOR        EAX,EAX
    //         00547fa2     MOV        DL,byte ptr [EDI]
    //         00547fa4     MOV        AL,byte ptr [EDI + 0x1]
    //         00547fa7     SHL        EDX,0x5
    //         00547faa     LEA        EDI,[ESI + ECX*0x1 + -0x2]
    //         00547fae     XOR        EDX,EAX
    //         00547fb0     CMP        ECX,EDI
    //         00547fb2     JNC        LAB_00548022
    //         00547fb4     LEA        ESI,[ECX*0x2 + 0x0]
    //                               LAB_00547fbb                                                 XREF[1]:     00548020(j)  
    //         00547fbb     MOV        EBX,dword ptr [DAT_00887a94]
    //         00547fc1     XOR        EAX,EAX
    //         00547fc3     AND        EDX,0xff
    //         00547fc9     MOV        AL,byte ptr [EBX + ECX*0x1 + 0x2]
    //         00547fcd     SHL        EDX,0x5
    //         00547fd0     MOV        EBX,dword ptr [DAT_00886cec]
    //         00547fd6     XOR        EAX,EDX
    //         00547fd8     MOV        EDX,EAX
    //         00547fda     OR         AH,0x80
    //         00547fdd     MOV        word ptr [EBX + ESI*0x1],AX
    //         00547fe1     MOV        EAX,[DAT_00887fa4]
    //         00547fe6     MOV        AX,word ptr [EAX + EDX*0x2]
    //         00547fea     MOV        EBX,dword ptr [DAT_00886cf0]
    //         00547ff0     MOV        word ptr [EBX + ESI*0x1],AX
    //         00547ff4     MOV        EBX,dword ptr [DAT_00886cf0]
    //         00547ffa     MOV        AX,word ptr [EBX + ESI*0x1]
    //         00547ffe     CMP        AX,0xffff
    //         00548002     JZ         LAB_00548011
    //         00548004     MOV        EBX,dword ptr [DAT_00886cec]
    //         0054800a     MOVZX      EAX,AX
    //         0054800d     MOV        word ptr [EBX + EAX*0x2],CX
    //                               LAB_00548011                                                 XREF[1]:     00548002(j)  
    //         00548011     MOV        EAX,[DAT_00887fa4]
    //         00548016     ADD        ESI,0x2
    //         00548019     MOV        word ptr [EAX + EDX*0x2],CX
    //         0054801d     INC        ECX
    //         0054801e     CMP        EDI,ECX
    //         00548020     JA         LAB_00547fbb
    //                               LAB_00548022                                                 XREF[2]:     00547f90(j), 00547fb2(j)  
    //         00548022     POP        EDI
    //         00548023     POP        ESI
    //         00548024     POP        EBX
    //         00548025     RET
}

