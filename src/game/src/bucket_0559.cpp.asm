// Auto-generated scaffold unit: bucket_0559.cpp.asm
#include "../include/common.h"

// Offset: 0x005590D0
undefined matherr() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined __matherr()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               __matherr                                                    XREF[1]:     __umatherr:00555ec8(c)  
    //         005590d0     XOR        EAX,EAX
    //         005590d2     RET
}

// Offset: 0x005590E0
undefined wcslen() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * wcslen                                                                                                *
    //                              *********************************************************************************************************
    //                              undefined __cdecl wcslen()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               _wcslen                                                      XREF[2]:     FUN_00556d0f:00556ec2(c), 
    //                               wcslen                                                                    wcstombs:00558662(c)  
    //         005590e0     MOV        ECX,dword ptr [ESP + Stack[0x4]]
    //         005590e4     CMP        word ptr [ECX],0x0
    //         005590e8     LEA        EAX,[ECX + 0x2]
    //         005590eb     JZ         LAB_005590f8
    //                               LAB_005590ed                                                 XREF[1]:     005590f6(j)  
    //         005590ed     MOV        DX,word ptr [EAX]
    //         005590f0     ADD        EAX,0x2
    //         005590f3     TEST       DX,DX
    //         005590f6     JNZ        LAB_005590ed
    //                               LAB_005590f8                                                 XREF[1]:     005590eb(j)  
    //         005590f8     SUB        EAX,ECX
    //         005590fa     SAR        EAX,0x1
    //         005590fc     DEC        EAX
    //         005590fd     RET
}

// Offset: 0x00559100
undefined crtMessageBoxA() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined ___crtMessageBoxA()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               ___crtMessageBoxA                                            XREF[1]:     __NMSG_WRITE:0055722a(c)  
    //         00559100     MOV        EAX,[DAT_00888424]
    //         00559105     PUSH       EBX
    //         00559106     XOR        EBX,EBX
    //         00559108     PUSH       ESI
    //         00559109     TEST       EAX,EAX
    //         0055910b     PUSH       EDI
    //         0055910c     JNZ        LAB_00559150
    //         0055910e     PUSH       s_user32.dll                                     = "user32.dll"
    //         00559113     CALL       dword ptr [->KERNEL32.DLL::LoadLibraryA]         = 0048aa08
    //         00559119     MOV        ESI,EAX
    //         0055911b     TEST       ESI,ESI
    //         0055911d     JZ         LAB_00559189
    //         0055911f     MOV        EDI,dword ptr [->KERNEL32.DLL::GetProcAddress]   = 0048abb0
    //         00559125     PUSH       s_MessageBoxA                                    = "MessageBoxA"
    //         0055912a     PUSH       ESI=>DAT_fffffff8
    //         0055912b     CALL       EDI=>KERNEL32.DLL::GetProcAddress
    //         0055912d     TEST       EAX,EAX
    //         0055912f     MOV        [DAT_00888424],EAX
    //         00559134     JZ         LAB_00559189
    //         00559136     PUSH       s_GetActiveWindow                                = "GetActiveWindow"
    //         0055913b     PUSH       ESI=>DAT_fffffff8
    //         0055913c     CALL       EDI=>KERNEL32.DLL::GetProcAddress
    //         0055913e     PUSH       s_GetLastActivePopup                             = "GetLastActivePopup"
    //         00559143     PUSH       ESI=>DAT_fffffff8
    //         00559144     MOV        [DAT_00888428],EAX
    //         00559149     CALL       EDI=>KERNEL32.DLL::GetProcAddress
    //         0055914b     MOV        [DAT_0088842c],EAX
    //                               LAB_00559150                                                 XREF[1]:     0055910c(j)  
    //         00559150     MOV        EAX,[DAT_00888428]
    //         00559155     TEST       EAX,EAX
    //         00559157     JZ         LAB_0055915d
    //         00559159     CALL       EAX
    //         0055915b     MOV        EBX,EAX
    //                               LAB_0055915d                                                 XREF[1]:     00559157(j)  
    //         0055915d     TEST       EBX,EBX
    //         0055915f     JZ         LAB_0055916f
    //         00559161     MOV        EAX,[DAT_0088842c]
    //         00559166     TEST       EAX,EAX
    //         00559168     JZ         LAB_0055916f
    //         0055916a     PUSH       EBX
    //         0055916b     CALL       EAX
    //         0055916d     MOV        EBX,EAX
    //                               LAB_0055916f                                                 XREF[2]:     0055915f(j), 00559168(j)  
    //         0055916f     MOV        EAX,dword ptr [ESP + 0x18]
    //         00559173     MOV        ECX,dword ptr [ESP + 0x14]
    //         00559177     MOV        EDX,dword ptr [ESP + 0x10]
    //         0055917b     PUSH       EAX
    //         0055917c     PUSH       ECX=>DAT_fffffff8
    //         0055917d     PUSH       EDX=>DAT_fffffff4
    //         0055917e     PUSH       EBX=>DAT_fffffff0
    //         0055917f     CALL       dword ptr [DAT_00888424]
    //         00559185     POP        EDI
    //         00559186     POP        ESI
    //         00559187     POP        EBX
    //         00559188     RET
    //                               LAB_00559189                                                 XREF[2]:     0055911d(j), 00559134(j)  
    //         00559189     POP        EDI
    //         0055918a     POP        ESI
    //         0055918b     XOR        EAX,EAX
    //         0055918d     POP        EBX
    //         0055918e     RET
}

// Offset: 0x0055918F
undefined FUN_0055918f() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0055918f()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0055918f
    //         0055918f     NOP
    //                               _signal
    //         00559190     PUSH       ESI
    //         00559191     PUSH       EDI
    //         00559192     MOV        EDI,dword ptr [ESP + Stack[0x8]]
    //         00559196     CMP        EDI,0x4
    //         00559199     JZ         LAB_005592a8
    //         0055919f     CMP        EDI,0x3
    //         005591a2     JZ         LAB_005592a8
    //         005591a8     MOV        ESI,dword ptr [ESP + Stack[0x4]]
    //         005591ac     CMP        ESI,0x2
    //         005591af     JZ         LAB_00559224
    //         005591b1     CMP        ESI,0x15
    //         005591b4     JZ         LAB_0055921a
    //         005591b6     CMP        ESI,0x16
    //         005591b9     JZ         LAB_0055921a
    //         005591bb     CMP        ESI,0xf
    //         005591be     JZ         LAB_0055921a
    //         005591c0     CMP        ESI,0x8
    //         005591c3     JZ         LAB_005591d3
    //         005591c5     CMP        ESI,0x4
    //         005591c8     JZ         LAB_005591d3
    //         005591ca     CMP        ESI,0xb
    //         005591cd     JNZ        LAB_005592a8
    //                               LAB_005591d3                                                 XREF[2]:     005591c3(j), 005591c8(j)  
    //         005591d3     PUSH       ESI
    //         005591d4     CALL       FUN_005594d0                                     undefined FUN_005594d0()
    //         005591d9     ADD        ESP,0x4
    //         005591dc     TEST       EAX,EAX
    //         005591de     JZ         LAB_005592a8
    //         005591e4     MOV        ECX,dword ptr [EAX + 0x4]
    //         005591e7     MOV        EDX,dword ptr [EAX + 0x8]
    //         005591ea     CMP        ECX,ESI
    //         005591ec     JNZ        LAB_005592a3
    //                               LAB_005591f2                                                 XREF[1]:     00559213(j)  
    //         005591f2     MOV        dword ptr [EAX + 0x8],EDI
    //         005591f5     MOV        ECX,dword ptr [__XcptActTabCount]                = 0000000Ah
    //         005591fb     ADD        EAX,0xc
    //         005591fe     LEA        ECX,[ECX + ECX*0x2]
    //         00559201     LEA        ECX,[ECX*0x4 + 0x592578]=>__First_FPE_Indx       = 00000003h
    //         00559208     CMP        EAX,ECX
    //         0055920a     JNC        LAB_005592a3
    //         00559210     CMP        dword ptr [EAX + 0x4],ESI
    //         00559213     JZ         LAB_005591f2
    //         00559215     MOV        EAX,EDX
    //         00559217     POP        EDI
    //         00559218     POP        ESI
    //         00559219     RET
    //                               LAB_0055921a                                                 XREF[3]:     005591b4(j), 005591b9(j), 
    //                                                                                                         005591be(j)  
    //         0055921a     CMP        ESI,0x2
    //         0055921d     JZ         LAB_00559224
    //         0055921f     CMP        ESI,0x15
    //         00559222     JNZ        LAB_00559244
    //                               LAB_00559224                                                 XREF[2]:     005591af(j), 0055921d(j)  
    //         00559224     MOV        EAX,[DAT_00888440]                               = align(8)
    //         00559229     TEST       EAX,EAX
    //         0055922b     JNZ        LAB_00559244
    //         0055922d     PUSH       0x1
    //         0055922f     PUSH       0x559300
    //         00559234     CALL       dword ptr [->KERNEL32.DLL::SetConsoleCtrlHandl   = 0048ba42
    //         0055923a     CMP        EAX,0x1
    //         0055923d     JNZ        LAB_005592b8
    //         0055923f     MOV        [DAT_00888440],EAX                               = align(8)
    //                               LAB_00559244                                                 XREF[2]:     00559222(j), 0055922b(j)  
    //         00559244     LEA        EAX,[ESI + -0x2]
    //         00559247     CMP        EAX,0x14
    //         0055924a     JA         switchD_00559254::caseD_3
    //         0055924c     XOR        EDX,EDX
    //         0055924e     MOV        DL,byte ptr [EAX + 0x5592e8]
    //                               switchD_00559254::switchD
    //         00559254     JMP        dword ptr [EDX*0x4 + switchD_00559254::switchd
    //                               switchD_00559254::caseD_2                                    XREF[1]:     00559254(j)  
    //         0055925b     MOV        EDX,dword ptr [DAT_00888430]
    //         00559261     MOV        dword ptr [DAT_00888430],EDI
    //         00559267     MOV        EAX,EDX
    //         00559269     POP        EDI
    //         0055926a     POP        ESI
    //         0055926b     RET
    //                               switchD_00559254::caseD_15                                   XREF[1]:     00559254(j)  
    //         0055926c     MOV        EDX,dword ptr [DAT_00888434]
    //         00559272     MOV        dword ptr [DAT_00888434],EDI
    //         00559278     MOV        EAX,EDX
    //         0055927a     POP        EDI
    //         0055927b     POP        ESI
    //         0055927c     RET
    //                               switchD_00559254::caseD_16                                   XREF[1]:     00559254(j)  
    //         0055927d     MOV        EDX,dword ptr [DAT_00888438]
    //         00559283     MOV        dword ptr [DAT_00888438],EDI
    //         00559289     MOV        EAX,EDX
    //         0055928b     POP        EDI
    //         0055928c     POP        ESI
    //         0055928d     RET
    //                               switchD_00559254::caseD_f                                    XREF[1]:     00559254(j)  
    //         0055928e     MOV        EDX,dword ptr [DAT_0088843c]
    //         00559294     MOV        dword ptr [DAT_0088843c],EDI
    //         0055929a     MOV        EAX,EDX
    //         0055929c     POP        EDI
    //         0055929d     POP        ESI
    //         0055929e     RET
    //                               switchD_00559254::caseD_4                                    XREF[2]:     0055924a(j), 00559254(j)  
    //                               switchD_00559254::caseD_5
    //                               switchD_00559254::caseD_6
    //                               switchD_00559254::caseD_7
    //                               switchD_00559254::caseD_8
    //                               switchD_00559254::caseD_9
    //                               switchD_00559254::caseD_a
    //                               switchD_00559254::caseD_b
    //                               switchD_00559254::caseD_c
    //                               switchD_00559254::caseD_d
    //                               switchD_00559254::caseD_e
    //                               switchD_00559254::caseD_10
    //                               switchD_00559254::caseD_11
    //                               switchD_00559254::caseD_12
    //                               switchD_00559254::caseD_13
    //                               switchD_00559254::caseD_14
    //                               switchD_00559254::caseD_3
    //         0055929f     MOV        EDX,dword ptr [ESP + 0x10]
    //                               LAB_005592a3                                                 XREF[2]:     005591ec(j), 0055920a(j)  
    //         005592a3     MOV        EAX,EDX
    //         005592a5     POP        EDI
    //         005592a6     POP        ESI
    //         005592a7     RET
    //                               LAB_005592a8                                                 XREF[4]:     00559199(j), 005591a2(j), 
    //                                                                                                         005591cd(j), 005591de(j)  
    //         005592a8     MOV        dword ptr [_errno],0x16                          = align(4)
    //         005592b2     OR         EAX,0xffffffff
    //         005592b5     POP        EDI
    //         005592b6     POP        ESI
    //         005592b7     RET
    //                               LAB_005592b8                                                 XREF[1]:     0055923d(j)  
    //         005592b8     CALL       dword ptr [->KERNEL32.DLL::GetLastError]         = 0048aa76
    //         005592be     MOV        [__doserrno],EAX
    //         005592c3     POP        EDI
    //         005592c4     MOV        dword ptr [_errno],0x16                          = align(4)
    //         005592ce     OR         EAX,0xffffffff
    //         005592d1     POP        ESI
    //         005592d2     RET
}

// Offset: 0x005592D3
undefined FUN_005592d3() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_005592d3()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_005592d3
    //         005592d3     NOP
    //                               switchD_00559254::switchdataD_005592d4                       XREF[1]:     FUN_0055918f:00559254(*)  
    //         005592d4     POP        EBX
    //         005592d5     XCHG       EAX,EDX
    //         005592d6     PUSH       EBP
    //         005592d7     ADD        byte ptr [ESI + 0x6c005592],CL
    //         005592dd     XCHG       EAX,EDX
    //         005592de     PUSH       EBP
    //         005592df     ADD        byte ptr [EBP + -0x6e],BH
    //         005592e2     PUSH       EBP
    //                               switchdataD_005592e8 (005592e3+5)
    //         005592e3     ADD        byte ptr [EDI + 0x5592],BL
    //         005592e9     ADD        AL,0x4
    //         005592eb     ADD        AL,0x4
    //         005592ed     ADD        AL,0x4
    //         005592ef     ADD        AL,0x4
    //         005592f1     ADD        AL,0x4
    //         005592f3     ADD        AL,0x4
    //         005592f5     ADD        dword ptr [ESP + EAX*0x1],EAX
    //         005592f8     ADD        AL,0x4
    //         005592fa     ADD        AL,0x2
    //         005592fc     ADD        EDX,dword ptr [EAX + 0x448b9090]
    //         00559302     AND        AL,0x4
    //         00559304     TEST       EAX,EAX
    //         00559306     JNZ        LAB_00559319
    //         00559308     MOV        EAX,[DAT_00888430]
    //         0055930d     MOV        ECX,DAT_00888430
    //         00559312     MOV        EDX,0x2
    //         00559317     JMP        LAB_00559328
    //                               LAB_00559319                                                 XREF[1]:     00559306(j)  
    //         00559319     MOV        EAX,[DAT_00888434]
    //         0055931e     MOV        ECX,DAT_00888434
    //         00559323     MOV        EDX,0x15
    //                               LAB_00559328                                                 XREF[1]:     00559317(j)  
    //         00559328     TEST       EAX,EAX
    //         0055932a     JNZ        LAB_0055932f
    //         0055932c     RET        0x4
    //                               LAB_0055932f                                                 XREF[1]:     0055932a(j)  
    //         0055932f     CMP        EAX,0x1
    //         00559332     JZ         LAB_00559340
    //         00559334     PUSH       EDX
    //         00559335     MOV        dword ptr [ECX]=>DAT_00888430,0x0
    //         0055933b     CALL       EAX
    //         0055933d     ADD        ESP,0x4
    //                               LAB_00559340                                                 XREF[1]:     00559332(j)  
    //         00559340     MOV        EAX,0x1
    //         00559345     RET        0x4
}

// Offset: 0x00559350
undefined raise() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * raise                                                                                                 *
    //                              *********************************************************************************************************
    //                              undefined __cdecl raise()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               _raise                                                       XREF[1]:     abort:005576fc(c)  
    //                               raise
    //         00559350     PUSH       EBX
    //         00559351     PUSH       EBP
    //         00559352     PUSH       ESI
    //         00559353     PUSH       EDI
    //         00559354     MOV        EDI,dword ptr [ESP + Stack[0x4]]
    //         00559358     LEA        EAX,[EDI + -0x2]
    //         0055935b     CMP        EAX,0x14
    //         0055935e     JA         switchD_0055936c::caseD_3
    //         00559364     XOR        ECX,ECX
    //         00559366     MOV        CL,byte ptr [EAX + 0x5594b4]=>PTR_caseD_3_0055
    //                               switchD_0055936c::switchD
    //         0055936c     JMP        dword ptr [ECX*0x4 + switchD_0055936c::switchd   = 00559373
    //                               switchD_0055936c::caseD_2                                    XREF[2]:     0055936c(j), 00559494(*)  
    //         00559373     MOV        EBX,dword ptr [DAT_00888430]
    //         00559379     MOV        ESI,DAT_00888430
    //         0055937e     JMP        LAB_005593b7
    //                               switchD_0055936c::caseD_15                                   XREF[2]:     0055936c(j), 005594a8(*)  
    //         00559380     MOV        EBX,dword ptr [DAT_00888434]
    //         00559386     MOV        ESI,DAT_00888434
    //         0055938b     JMP        LAB_005593b7
    //                               switchD_0055936c::caseD_16                                   XREF[2]:     0055936c(j), 005594ac(*)  
    //         0055938d     MOV        EBX,dword ptr [DAT_00888438]
    //         00559393     MOV        ESI,DAT_00888438
    //         00559398     JMP        LAB_005593b7
    //                               switchD_0055936c::caseD_f                                    XREF[2]:     0055936c(j), 005594a4(*)  
    //         0055939a     MOV        EBX,dword ptr [DAT_0088843c]
    //         005593a0     MOV        ESI,DAT_0088843c
    //         005593a5     JMP        LAB_005593b7
    //                               switchD_0055936c::caseD_8                                    XREF[4]:     0055936c(j), 00559498(*), 
    //                               switchD_0055936c::caseD_b                                                 0055949c(*), 005594a0(*)  
    //                               switchD_0055936c::caseD_4
    //         005593a7     PUSH       EDI
    //         005593a8     CALL       FUN_005594d0                                     undefined FUN_005594d0()
    //         005593ad     MOV        ESI,EAX
    //         005593af     ADD        ESP,0x4
    //         005593b2     ADD        ESI,0x8
    //         005593b5     MOV        EBX,dword ptr [ESI]
    //                               LAB_005593b7                                                 XREF[4]:     0055937e(j), 0055938b(j), 
    //                                                                                                         00559398(j), 005593a5(j)  
    //         005593b7     CMP        EBX,0x1
    //         005593ba     JNZ        LAB_005593c3
    //         005593bc     XOR        EAX,EAX
    //         005593be     POP        EDI
    //         005593bf     POP        ESI
    //         005593c0     POP        EBP
    //         005593c1     POP        EBX
    //         005593c2     RET
    //                               LAB_005593c3                                                 XREF[1]:     005593ba(j)  
    //         005593c3     TEST       EBX,EBX
    //         005593c5     JNZ        LAB_005593d1
    //         005593c7     PUSH       0x3
    //         005593c9     CALL       __exit                                           undefined __exit()
    //         005593ce     ADD        ESP,0x4
    //                               LAB_005593d1                                                 XREF[1]:     005593c5(j)  
    //         005593d1     CMP        EDI,0x8
    //         005593d4     JZ         LAB_005593e0
    //         005593d6     CMP        EDI,0xb
    //         005593d9     JZ         LAB_005593e0
    //         005593db     CMP        EDI,0x4
    //         005593de     JNZ        LAB_0055940b
    //                               LAB_005593e0                                                 XREF[2]:     005593d4(j), 005593d9(j)  
    //         005593e0     MOV        EBP,dword ptr [__pxcptinfoptrs]
    //         005593e6     CMP        EDI,0x8
    //         005593e9     MOV        dword ptr [__pxcptinfoptrs],0x0
    //         005593f3     JNZ        LAB_00559440
    //         005593f5     MOV        EDX,dword ptr [__fpecode]                        = 0000008Ch
    //         005593fb     MOV        dword ptr [__fpecode],0x8c                       = 0000008Ch
    //         00559405     MOV        dword ptr [ESP + Stack[0x4]],EDX
    //         00559409     JMP        LAB_0055940f
    //                               LAB_0055940b                                                 XREF[1]:     005593de(j)  
    //         0055940b     MOV        EBP,dword ptr [ESP + Stack[0x4]]
    //                               LAB_0055940f                                                 XREF[1]:     00559409(j)  
    //         0055940f     CMP        EDI,0x8
    //         00559412     JNZ        LAB_00559440
    //         00559414     MOV        EDX,dword ptr [__First_FPE_Indx]                 = 00000003h
    //         0055941a     MOV        EAX,[__Num_FPE]                                  = 00000007h
    //         0055941f     LEA        ECX,[EAX + EDX*0x1]
    //         00559422     CMP        EDX,ECX
    //         00559424     JGE        LAB_00559446
    //         00559426     LEA        EAX,[EDX + EDX*0x2]
    //         00559429     SUB        ECX,EDX
    //         0055942b     LEA        EAX,[EAX*0x4 + 0x592580]=>DAT_005925a4
    //                               LAB_00559432                                                 XREF[1]:     0055943c(j)  
    //         00559432     MOV        dword ptr [EAX]=>DAT_005925a4,0x0
    //         00559438     ADD        EAX,0xc
    //         0055943b     DEC        ECX
    //         0055943c     JNZ        LAB_00559432
    //         0055943e     JMP        LAB_00559446
    //                               LAB_00559440                                                 XREF[2]:     005593f3(j), 00559412(j)  
    //         00559440     MOV        dword ptr [ESI]=>DAT_00888438,0x0
    //                               LAB_00559446                                                 XREF[2]:     00559424(j), 0055943e(j)  
    //         00559446     CMP        EDI,0x8
    //         00559449     JNZ        LAB_0055945a
    //         0055944b     MOV        ECX,dword ptr [__fpecode]                        = 0000008Ch
    //         00559451     PUSH       ECX
    //         00559452     PUSH       EDI
    //         00559453     CALL       EBX
    //         00559455     ADD        ESP,0x8
    //         00559458     JMP        LAB_00559460
    //                               LAB_0055945a                                                 XREF[1]:     00559449(j)  
    //         0055945a     PUSH       EDI
    //         0055945b     CALL       EBX
    //         0055945d     ADD        ESP,0x4
    //                               LAB_00559460                                                 XREF[1]:     00559458(j)  
    //         00559460     CMP        EDI,0x8
    //         00559463     JZ         LAB_0055946f
    //         00559465     CMP        EDI,0xb
    //         00559468     JZ         LAB_0055946f
    //         0055946a     CMP        EDI,0x4
    //         0055946d     JNZ        LAB_00559484
    //                               LAB_0055946f                                                 XREF[2]:     00559463(j), 00559468(j)  
    //         0055946f     CMP        EDI,0x8
    //         00559472     MOV        dword ptr [__pxcptinfoptrs],EBP
    //         00559478     JNZ        LAB_00559484
    //         0055947a     MOV        EDX,dword ptr [ESP + 0x14]
    //         0055947e     MOV        dword ptr [__fpecode],EDX                        = 0000008Ch
    //                               LAB_00559484                                                 XREF[2]:     0055946d(j), 00559478(j)  
    //         00559484     XOR        EAX,EAX
    //         00559486     POP        EDI
    //         00559487     POP        ESI
    //         00559488     POP        EBP
    //         00559489     POP        EBX
    //         0055948a     RET
    //                               switchD_0055936c::caseD_5                                    XREF[3]:     0055935e(j), 0055936c(j), 
    //                               switchD_0055936c::caseD_6                                                 005594b0(*)  
    //                               switchD_0055936c::caseD_7
    //                               switchD_0055936c::caseD_9
    //                               switchD_0055936c::caseD_a
    //                               switchD_0055936c::caseD_c
    //                               switchD_0055936c::caseD_d
    //                               switchD_0055936c::caseD_e
    //                               switchD_0055936c::caseD_10
    //                               switchD_0055936c::caseD_11
    //                               switchD_0055936c::caseD_12
    //                               switchD_0055936c::caseD_13
    //                               switchD_0055936c::caseD_14
    //                               switchD_0055936c::caseD_3
    //         0055948b     POP        EDI
    //         0055948c     POP        ESI
    //         0055948d     POP        EBP
    //         0055948e     OR         EAX,0xffffffff
    //         00559491     POP        EBX
    //         00559492     RET
}

// Offset: 0x005594D0
undefined FUN_005594d0() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_005594d0()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_005594d0                                                 XREF[2]:     FUN_0055918f:005591d4(c), 
    //                                                                                                         raise:005593a8(c)  
    //         005594d0     MOV        EDX,dword ptr [ESP + Stack[0x4]]
    //         005594d4     MOV        ECX,dword ptr [DAT_0059257c]                     = 0000000Bh
    //         005594da     PUSH       ESI
    //         005594db     MOV        ESI,dword ptr [__XcptActTabCount]                = 0000000Ah
    //         005594e1     CMP        ECX,EDX
    //         005594e3     MOV        EAX,__XcptActTab                                 = C0000005h
    //         005594e8     JZ         LAB_00559500
    //         005594ea     LEA        ECX,[ESI + ESI*0x2]
    //         005594ed     LEA        ECX,[ECX*0x4 + 0x592578]=>__First_FPE_Indx       = 00000003h
    //                               LAB_005594f4                                                 XREF[1]:     005594fe(j)  
    //         005594f4     ADD        EAX=>DAT_00592584,0xc                            = C000001Dh
    //         005594f7     CMP        EAX,ECX
    //         005594f9     JNC        LAB_00559500
    //         005594fb     CMP        dword ptr [EAX + 0x4]=>DAT_00592588,EDX          = 00000004h
    //         005594fe     JNZ        LAB_005594f4
    //                               LAB_00559500                                                 XREF[2]:     005594e8(j), 005594f9(j)  
    //         00559500     LEA        ECX,[ESI + ESI*0x2]
    //         00559503     LEA        ECX,[ECX*0x4 + 0x592578]=>__First_FPE_Indx       = 00000003h
    //         0055950a     CMP        EAX,ECX
    //         0055950c     JNC        LAB_00559513
    //         0055950e     CMP        dword ptr [EAX + 0x4]=>DAT_00592588,EDX          = 0000000Bh
    //                                                                                  = 00000004h
    //         00559511     JZ         LAB_00559515
    //                               LAB_00559513                                                 XREF[1]:     0055950c(j)  
    //         00559513     XOR        EAX,EAX
    //                               LAB_00559515                                                 XREF[1]:     00559511(j)  
    //         00559515     POP        ESI
    //         00559516     RET
}

// Offset: 0x00559520
undefined addl() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined ___addl()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               ___addl                                                      XREF[7]:     __IncMan:005579fd(c), 
    //                                                                                                         __IncMan:00557a15(c), 
    //                                                                                                         ___add_12:00559561(c), 
    //                                                                                                         ___add_12:00559577(c), 
    //                                                                                                         ___add_12:00559592(c), 
    //                                                                                                         ___add_12:005595ad(c), 
    //                                                                                                         ___ld12mul:00559c85(c)  
    //         00559520     MOV        EDX,dword ptr [ESP + Stack[0x4]]
    //         00559524     PUSH       ESI
    //         00559525     MOV        ESI,dword ptr [ESP + Stack[0x8]]
    //         00559529     XOR        EAX,EAX
    //         0055952b     LEA        ECX,[ESI + EDX*0x1]
    //         0055952e     CMP        ECX,EDX
    //         00559530     JC         LAB_00559536
    //         00559532     CMP        ECX,ESI
    //         00559534     JNC        LAB_0055953b
    //                               LAB_00559536                                                 XREF[1]:     00559530(j)  
    //         00559536     MOV        EAX,0x1
    //                               LAB_0055953b                                                 XREF[1]:     00559534(j)  
    //         0055953b     MOV        EDX,dword ptr [ESP + Stack[0xc]]
    //         0055953f     POP        ESI
    //         00559540     MOV        dword ptr [EDX],ECX
    //         00559542     RET
}

// Offset: 0x00559550
undefined add_12() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined ___add_12()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               ___add_12                                                    XREF[3]:     ___mtold12:00559678(c), 
    //                                                                                                         ___mtold12:0055969e(c), 
    //                                                                                                         _$I10_OUTPUT:005599ea(c)  
    //         00559550     PUSH       ESI
    //         00559551     MOV        ESI,dword ptr [ESP + Stack[0x4]]
    //         00559555     PUSH       EDI
    //         00559556     MOV        EDI,dword ptr [ESP + Stack[0x8]]
    //         0055955a     MOV        ECX,dword ptr [ESI]
    //         0055955c     PUSH       ESI
    //         0055955d     MOV        EAX,dword ptr [EDI]
    //         0055955f     PUSH       EAX
    //         00559560     PUSH       ECX
    //         00559561     CALL       ___addl                                          undefined ___addl()
    //         00559566     ADD        ESP,0xc
    //         00559569     TEST       EAX,EAX
    //         0055956b     JZ         LAB_00559586
    //         0055956d     MOV        EDX,dword ptr [ESI + 0x4]
    //         00559570     LEA        EAX,[ESI + 0x4]
    //         00559573     PUSH       EAX
    //         00559574     PUSH       0x1
    //         00559576     PUSH       EDX
    //         00559577     CALL       ___addl                                          undefined ___addl()
    //         0055957c     ADD        ESP,0xc
    //         0055957f     TEST       EAX,EAX
    //         00559581     JZ         LAB_00559586
    //         00559583     INC        dword ptr [ESI + 0x8]
    //                               LAB_00559586                                                 XREF[2]:     0055956b(j), 00559581(j)  
    //         00559586     MOV        ECX,dword ptr [EDI + 0x4]
    //         00559589     MOV        EDX,dword ptr [ESI + 0x4]
    //         0055958c     LEA        EAX,[ESI + 0x4]
    //         0055958f     PUSH       EAX
    //         00559590     PUSH       ECX
    //         00559591     PUSH       EDX
    //         00559592     CALL       ___addl                                          undefined ___addl()
    //         00559597     ADD        ESP,0xc
    //         0055959a     TEST       EAX,EAX
    //         0055959c     JZ         LAB_005595a1
    //         0055959e     INC        dword ptr [ESI + 0x8]
    //                               LAB_005595a1                                                 XREF[1]:     0055959c(j)  
    //         005595a1     MOV        ECX,dword ptr [EDI + 0x8]
    //         005595a4     MOV        EDX,dword ptr [ESI + 0x8]
    //         005595a7     LEA        EAX,[ESI + 0x8]
    //         005595aa     PUSH       EAX
    //         005595ab     PUSH       ECX
    //         005595ac     PUSH       EDX
    //         005595ad     CALL       ___addl                                          undefined ___addl()
    //         005595b2     ADD        ESP,0xc
    //         005595b5     POP        EDI
    //         005595b6     POP        ESI
    //         005595b7     RET
}

// Offset: 0x005595C0
undefined shl_12() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined ___shl_12()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               ___shl_12                                                    XREF[9]:     ___mtold12:00559661(c), 
    //                                                                                                         ___mtold12:0055966a(c), 
    //                                                                                                         ___mtold12:00559681(c), 
    //                                                                                                         ___mtold12:005596f0(c), 
    //                                                                                                         _$I10_OUTPUT:00559979(c), 
    //                                                                                                         _$I10_OUTPUT:005599cb(c), 
    //                                                                                                         _$I10_OUTPUT:005599d8(c), 
    //                                                                                                         _$I10_OUTPUT:005599f7(c), 
    //                                                                                                         ___ld12mul:00559cf1(c)  
    //         005595c0     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         005595c4     PUSH       ESI
    //         005595c5     PUSH       EDI
    //         005595c6     MOV        ESI,dword ptr [EAX]
    //         005595c8     MOV        EDI,dword ptr [EAX + 0x4]
    //         005595cb     MOV        ECX,ESI
    //         005595cd     ADD        ESI,ESI
    //         005595cf     MOV        dword ptr [EAX],ESI
    //         005595d1     LEA        ESI,[EDI + EDI*0x1]
    //         005595d4     SHR        ECX,0x1f
    //         005595d7     OR         ESI,ECX
    //         005595d9     MOV        ECX,dword ptr [EAX + 0x8]
    //         005595dc     MOV        EDX,EDI
    //         005595de     MOV        dword ptr [EAX + 0x4],ESI
    //         005595e1     SHR        EDX,0x1f
    //         005595e4     SHL        ECX,0x1
    //         005595e6     OR         ECX,EDX
    //         005595e8     POP        EDI
    //         005595e9     MOV        dword ptr [EAX + 0x8],ECX
    //         005595ec     POP        ESI
    //         005595ed     RET
}

// Offset: 0x005595F0
undefined shr_12() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined ___shr_12()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               ___shr_12                                                    XREF[2]:     _$I10_OUTPUT:00559997(c), 
    //                                                                                                         ___ld12mul:00559d44(c)  
    //         005595f0     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         005595f4     PUSH       ESI
    //         005595f5     PUSH       EDI
    //         005595f6     MOV        EDX,dword ptr [EAX + 0x8]
    //         005595f9     MOV        ECX,dword ptr [EAX + 0x4]
    //         005595fc     MOV        ESI,EDX
    //         005595fe     MOV        EDI,ECX
    //         00559600     SHL        ESI,0x1f
    //         00559603     SHR        ECX,0x1
    //         00559605     OR         ECX,ESI
    //         00559607     MOV        dword ptr [EAX + 0x4],ECX
    //         0055960a     MOV        ECX,dword ptr [EAX]
    //         0055960c     SHL        EDI,0x1f
    //         0055960f     SHR        ECX,0x1
    //         00559611     SHR        EDX,0x1
    //         00559613     OR         ECX,EDI
    //         00559615     POP        EDI
    //         00559616     MOV        dword ptr [EAX + 0x8],EDX
    //         00559619     MOV        dword ptr [EAX],ECX
    //         0055961b     POP        ESI
    //         0055961c     RET
}

// Offset: 0x00559620
undefined mtold12() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined ___mtold12()
    //              undefined         <UNASSIGNED>   <RETURN>
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     0055965d(W), 0055969a(W)  
    //              undefined4        Stack[-0x8]:4  local_8                   XREF[2]:     00559656(W), 00559694(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[4]:     0055964f(W), 00559672(*), 0055968c(*), 00559690(W)  
    //                               ___mtold12                                                   XREF[1]:     ___strgtold12:00558e37(c)  
    //         00559620     MOV        EAX,dword ptr [ESP + Stack[0x8]]
    //         00559624     SUB        ESP,0xc
    //         00559627     PUSH       EBX
    //         00559628     PUSH       EBP
    //         00559629     PUSH       ESI
    //         0055962a     MOV        ESI,dword ptr [ESP + Stack[0xc]]
    //         0055962e     XOR        EBP,EBP
    //         00559630     PUSH       EDI
    //         00559631     CMP        EAX,EBP
    //         00559633     MOV        EDI,0x404e
    //         00559638     MOV        dword ptr [ESI],EBP
    //         0055963a     MOV        dword ptr [ESI + 0x4],EBP
    //         0055963d     MOV        dword ptr [ESI + 0x8],EBP
    //         00559640     JBE        LAB_005596b2
    //         00559642     MOV        EBX,dword ptr [ESP + Stack[0x4]]
    //         00559646     MOV        dword ptr [ESP + Stack[0xc]],EAX
    //                               LAB_0055964a                                                 XREF[1]:     005596b0(j)  
    //         0055964a     MOV        EAX,ESI
    //         0055964c     PUSH       ESI
    //         0055964d     MOV        ECX,dword ptr [EAX]
    //         0055964f     MOV        dword ptr [ESP + local_c],ECX
    //         00559653     MOV        EDX,dword ptr [EAX + 0x4]
    //         00559656     MOV        dword ptr [ESP + local_8],EDX
    //         0055965a     MOV        EAX,dword ptr [EAX + 0x8]
    //         0055965d     MOV        dword ptr [ESP + local_4],EAX
    //         00559661     CALL       ___shl_12                                        undefined ___shl_12()
    //         00559666     ADD        ESP,0x4
    //         00559669     PUSH       ESI
    //         0055966a     CALL       ___shl_12                                        undefined ___shl_12()
    //         0055966f     ADD        ESP,0x4
    //         00559672     LEA        ECX=>local_c,[ESP + 0x10]
    //         00559676     PUSH       ECX
    //         00559677     PUSH       ESI
    //         00559678     CALL       ___add_12                                        undefined ___add_12()
    //         0055967d     ADD        ESP,0x8
    //         00559680     PUSH       ESI
    //         00559681     CALL       ___shl_12                                        undefined ___shl_12()
    //         00559686     MOVSX      EDX,byte ptr [EBX]
    //         00559689     ADD        ESP,0x4
    //         0055968c     LEA        EAX=>local_c,[ESP + 0x10]
    //         00559690     MOV        dword ptr [ESP + local_c],EDX
    //         00559694     MOV        dword ptr [ESP + local_8],EBP
    //         00559698     PUSH       EAX
    //         00559699     PUSH       ESI
    //         0055969a     MOV        dword ptr [ESP + local_4],EBP
    //         0055969e     CALL       ___add_12                                        undefined ___add_12()
    //         005596a3     MOV        EAX,dword ptr [ESP + Stack[0xc]]
    //         005596a7     ADD        ESP,0x8
    //         005596aa     INC        EBX
    //         005596ab     DEC        EAX
    //         005596ac     MOV        dword ptr [ESP + Stack[0xc]],EAX
    //         005596b0     JNZ        LAB_0055964a
    //                               LAB_005596b2                                                 XREF[1]:     00559640(j)  
    //         005596b2     CMP        dword ptr [ESI + 0x8],EBP
    //         005596b5     JNZ        LAB_005596e3
    //                               LAB_005596b7                                                 XREF[1]:     005596e1(j)  
    //         005596b7     MOV        EAX,dword ptr [ESI + 0x4]
    //         005596ba     ADD        EDI,0xfff0
    //         005596c0     MOV        ECX,EAX
    //         005596c2     SHR        ECX,0x10
    //         005596c5     MOV        dword ptr [ESI + 0x8],ECX
    //         005596c8     MOV        ECX,dword ptr [ESI]
    //         005596ca     MOV        EDX,ECX
    //         005596cc     SHR        EDX,0x10
    //         005596cf     SHL        EAX,0x10
    //         005596d2     OR         EDX,EAX
    //         005596d4     MOV        EAX,dword ptr [ESI + 0x8]
    //         005596d7     SHL        ECX,0x10
    //         005596da     CMP        EAX,EBP
    //         005596dc     MOV        dword ptr [ESI + 0x4],EDX
    //         005596df     MOV        dword ptr [ESI],ECX
    //         005596e1     JZ         LAB_005596b7
    //                               LAB_005596e3                                                 XREF[1]:     005596b5(j)  
    //         005596e3     MOV        EAX,dword ptr [ESI + 0x8]
    //         005596e6     MOV        EBX,0x8000
    //         005596eb     TEST       EBX,EAX
    //         005596ed     JNZ        LAB_00559705
    //                               LAB_005596ef                                                 XREF[1]:     00559703(j)  
    //         005596ef     PUSH       ESI
    //         005596f0     CALL       ___shl_12                                        undefined ___shl_12()
    //         005596f5     MOV        EAX,dword ptr [ESI + 0x8]
    //         005596f8     ADD        ESP,0x4
    //         005596fb     ADD        EDI,0xffff
    //         00559701     TEST       EBX,EAX
    //         00559703     JZ         LAB_005596ef
    //                               LAB_00559705                                                 XREF[1]:     005596ed(j)  
    //         00559705     MOV        word ptr [ESI + 0xa],DI
    //         00559709     POP        EDI
    //         0055970a     POP        ESI
    //         0055970b     POP        EBP
    //         0055970c     POP        EBX
    //         0055970d     ADD        ESP,0xc
    //         00559710     RET
}

// Offset: 0x00559720
undefined I10_OUTPUT() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined _$I10_OUTPUT()
    //              undefined         <UNASSIGNED>   <RETURN>
    //              undefined4        Stack[-0x6]:4  local_6                   XREF[4,2]:   005598a2(W), 005598f8(R), 0055995a(R), 0055995e(W), 
    //                                                                                     005599fc(R), 00559a06(W)  
    //              undefined8        Stack[-0x10]:8 local_10                  XREF[10,3]:  005598b4(*), 005598bd(W), 00559905(*), 00559974(*), 
    //                                                                                     00559992(*), 005599ae(R), 005599be(*), 005599d3(*), 
    //                                                                                     005599e4(*), 005599f2(*), 005598ae(W), 005599b2(R), 
    //                                                                                     005598a7(W)  
    //              undefined1        Stack[-0x11]:1 local_11                  XREF[1]:     0055976a(W)  
    //              undefined1        Stack[-0x12]:1 local_12                  XREF[1]:     00559765(W)  
    //              undefined1        Stack[-0x13]:1 local_13                  XREF[1]:     0055974d(W)  
    //              undefined1        Stack[-0x14]:1 local_14                  XREF[1]:     00559749(W)  
    //              undefined1        Stack[-0x15]:1 local_15                  XREF[1]:     00559745(W)  
    //              undefined1        Stack[-0x16]:1 local_16                  XREF[1]:     00559741(W)  
    //              undefined1        Stack[-0x17]:1 local_17                  XREF[1]:     0055973d(W)  
    //              undefined1        Stack[-0x18]:1 local_18                  XREF[1]:     00559739(W)  
    //              undefined1        Stack[-0x19]:1 local_19                  XREF[1]:     00559735(W)  
    //              undefined1        Stack[-0x1a]:1 local_1a                  XREF[1]:     00559731(W)  
    //              undefined1        Stack[-0x1b]:1 local_1b                  XREF[1]:     0055972d(W)  
    //              undefined1        Stack[-0x1c]:1 local_1c                  XREF[2]:     00559729(W), 00559901(*)  
    //              undefined4        Stack[-0x20]:4 local_20                  XREF[2]:     0055976f(W), 00559a99(R)  
    //                               _$I10_OUTPUT                                                 XREF[1]:     __fltout:00558009(c)  
    //         00559720     SUB        ESP,0x20
    //         00559723     MOV        ECX,dword ptr [ESP + Stack[0xc]]
    //         00559727     MOV        AL,0xcc
    //         00559729     MOV        byte ptr [ESP + local_1c],AL
    //         0055972d     MOV        byte ptr [ESP + local_1b],AL
    //         00559731     MOV        byte ptr [ESP + local_1a],AL
    //         00559735     MOV        byte ptr [ESP + local_19],AL
    //         00559739     MOV        byte ptr [ESP + local_18],AL
    //         0055973d     MOV        byte ptr [ESP + local_17],AL
    //         00559741     MOV        byte ptr [ESP + local_16],AL
    //         00559745     MOV        byte ptr [ESP + local_15],AL
    //         00559749     MOV        byte ptr [ESP + local_14],AL
    //         0055974d     MOV        byte ptr [ESP + local_13],AL
    //         00559751     MOV        EAX,ECX
    //         00559753     PUSH       EBX
    //         00559754     AND        EAX,0x8000
    //         00559759     PUSH       EBP
    //         0055975a     AND        ECX,0x7fff
    //         00559760     PUSH       ESI
    //         00559761     TEST       AX,AX
    //         00559764     PUSH       EDI
    //         00559765     MOV        byte ptr [ESP + local_12],0xfb
    //         0055976a     MOV        byte ptr [ESP + local_11],0x3f
    //         0055976f     MOV        dword ptr [ESP + local_20],0x1
    //         00559777     JZ         LAB_00559783
    //         00559779     MOV        EDI,dword ptr [ESP + Stack[0x18]]
    //         0055977d     MOV        byte ptr [EDI + 0x2],0x2d
    //         00559781     JMP        LAB_0055978d
    //                               LAB_00559783                                                 XREF[1]:     00559777(j)  
    //         00559783     MOV        EDX,dword ptr [ESP + Stack[0x18]]
    //         00559787     MOV        EDI,EDX
    //         00559789     MOV        byte ptr [EDX + 0x2],0x20
    //                               LAB_0055978d                                                 XREF[1]:     00559781(j)  
    //         0055978d     MOV        EDX,dword ptr [ESP + Stack[0x8]]
    //         00559791     MOV        EBX,dword ptr [ESP + Stack[0x4]]
    //         00559795     TEST       CX,CX
    //         00559798     JNZ        LAB_005597aa
    //         0055979a     TEST       EDX,EDX
    //         0055979c     JNZ        LAB_005597aa
    //         0055979e     TEST       EBX,EBX
    //         005597a0     JNZ        LAB_005597aa
    //         005597a2     MOV        word ptr [EDI],BX
    //         005597a5     JMP        LAB_0055992f
    //                               LAB_005597aa                                                 XREF[3]:     00559798(j), 0055979c(j), 
    //                                                                                                         005597a0(j)  
    //         005597aa     CMP        CX,0x7fff
    //         005597af     JNZ        LAB_0055988d
    //         005597b5     CMP        EDX,0x80000000
    //         005597bb     MOV        word ptr [EDI],0x1
    //         005597c0     JNZ        LAB_005597c6
    //         005597c2     TEST       EBX,EBX
    //         005597c4     JZ         LAB_005597fc
    //                               LAB_005597c6                                                 XREF[1]:     005597c0(j)  
    //         005597c6     TEST       EDX,0x40000000
    //         005597cc     JNZ        LAB_005597fc
    //         005597ce     MOV        ECX,dword ptr [s_1#SNAN]                         = "1#SNAN"
    //         005597d4     LEA        EAX,[EDI + 0x4]
    //         005597d7     MOV        dword ptr [EDI + 0x4],ECX
    //         005597da     MOV        DX,word ptr [s_AN_00578028+4]                    = "AN"
    //         005597e1     MOV        word ptr [EAX + 0x4],DX
    //         005597e5     MOV        CL,byte ptr [s__00578028+6]                      = ""
    //         005597eb     MOV        byte ptr [EDI + 0x3],0x6
    //         005597ef     MOV        byte ptr [EAX + 0x6],CL
    //         005597f2     XOR        EAX,EAX
    //         005597f4     POP        EDI
    //         005597f5     POP        ESI
    //         005597f6     POP        EBP
    //         005597f7     POP        EBX
    //         005597f8     ADD        ESP,0x20
    //         005597fb     RET
    //                               LAB_005597fc                                                 XREF[2]:     005597c4(j), 005597cc(j)  
    //         005597fc     TEST       AX,AX
    //         005597ff     JZ         LAB_00559831
    //         00559801     CMP        EDX,0xc0000000
    //         00559807     JNZ        LAB_00559831
    //         00559809     TEST       EBX,EBX
    //         0055980b     JNZ        LAB_00559831
    //         0055980d     MOV        EAX,[s_1#IND]                                    = "1#IND"
    //         00559812     LEA        EDX,[EDI + 0x4]
    //         00559815     MOV        dword ptr [EDI + 0x4],EAX
    //         00559818     MOV        CX,word ptr [s_D_00578020+4]                     = "D"
    //         0055981f     MOV        byte ptr [EDI + 0x3],0x5
    //         00559823     XOR        EAX,EAX
    //         00559825     MOV        word ptr [EDX + 0x4],CX
    //         00559829     POP        EDI
    //         0055982a     POP        ESI
    //         0055982b     POP        EBP
    //         0055982c     POP        EBX
    //         0055982d     ADD        ESP,0x20
    //         00559830     RET
    //                               LAB_00559831                                                 XREF[3]:     005597ff(j), 00559807(j), 
    //                                                                                                         0055980b(j)  
    //         00559831     CMP        EDX,0x80000000
    //         00559837     JNZ        LAB_00559861
    //         00559839     TEST       EBX,EBX
    //         0055983b     JNZ        LAB_00559861
    //         0055983d     MOV        EAX,[s_1#INF]                                    = "1#INF"
    //         00559842     LEA        EDX,[EDI + 0x4]
    //         00559845     MOV        dword ptr [EDI + 0x4],EAX
    //         00559848     MOV        CX,word ptr [s_F_00578018+4]                     = "F"
    //         0055984f     MOV        byte ptr [EDI + 0x3],0x5
    //         00559853     XOR        EAX,EAX
    //         00559855     MOV        word ptr [EDX + 0x4],CX
    //         00559859     POP        EDI
    //         0055985a     POP        ESI
    //         0055985b     POP        EBP
    //         0055985c     POP        EBX
    //         0055985d     ADD        ESP,0x20
    //         00559860     RET
    //                               LAB_00559861                                                 XREF[2]:     00559837(j), 0055983b(j)  
    //         00559861     MOV        EAX,[s_1#QNAN]                                   = "1#QNAN"
    //         00559866     LEA        EDX,[EDI + 0x4]
    //         00559869     MOV        dword ptr [EDI + 0x4],EAX
    //         0055986c     MOV        CX,word ptr [s_AN_00578010+4]                    = "AN"
    //         00559873     MOV        word ptr [EDX + 0x4],CX
    //         00559877     MOV        AL,[s__00578010+6]                               = ""
    //         0055987c     MOV        byte ptr [EDI + 0x3],0x6
    //         00559880     MOV        byte ptr [EDX + 0x6],AL
    //         00559883     XOR        EAX,EAX
    //         00559885     POP        EDI
    //         00559886     POP        ESI
    //         00559887     POP        EBP
    //         00559888     POP        EBX
    //         00559889     ADD        ESP,0x20
    //         0055988c     RET
    //                               LAB_0055988d                                                 XREF[1]:     005597af(j)  
    //         0055988d     MOV        EAX,EDX
    //         0055988f     MOV        ESI,ECX
    //         00559891     SHR        EAX,0x18
    //         00559894     AND        ESI,0xffff
    //         0055989a     AND        EAX,0xffff
    //         0055989f     SHR        ESI,0x8
    //         005598a2     MOV        word ptr [ESP + local_6],CX
    //         005598a7     MOV        dword ptr [ESP + local_10+0x6],EDX
    //         005598ab     LEA        EAX,[ESI + EAX*0x2]
    //         005598ae     MOV        dword ptr [ESP + local_10+0x2],EBX
    //         005598b2     PUSH       0x1
    //         005598b4     LEA        EDX=>local_10,[ESP + 0x24]
    //         005598b8     LEA        ESI,[EAX + EAX*0x8]
    //         005598bb     XOR        EBX,EBX
    //         005598bd     MOV        word ptr [ESP + local_10],BX
    //         005598c2     LEA        ESI,[EAX + ESI*0x2]
    //         005598c5     LEA        ESI,[EAX + ESI*0x4]
    //         005598c8     MOV        EAX,ECX
    //         005598ca     AND        EAX,0xffff
    //         005598cf     MOV        EBP,EAX
    //         005598d1     SHL        EBP,0x4
    //         005598d4     ADD        EBP,EAX
    //         005598d6     LEA        EAX,[EAX + EBP*0x8]
    //         005598d9     LEA        EAX,[EAX + EAX*0x8]
    //         005598dc     SHL        EAX,0x4
    //         005598df     LEA        ESI,[ESI + EAX*0x1 + 0xecbced0c]
    //         005598e6     SAR        ESI,0x10
    //         005598e9     MOVSX      ECX,SI
    //         005598ec     NEG        ECX
    //         005598ee     PUSH       ECX
    //         005598ef     PUSH       EDX
    //         005598f0     CALL       ___multtenpow12                                  undefined ___multtenpow12()
    //         005598f5     ADD        ESP,0xc
    //         005598f8     CMP        word ptr [ESP + local_6],0x3fff
    //         005598ff     JC         LAB_00559914
    //         00559901     LEA        EAX=>local_1c,[ESP + 0x14]
    //         00559905     LEA        ECX=>local_10,[ESP + 0x20]
    //         00559909     PUSH       EAX
    //         0055990a     PUSH       ECX
    //         0055990b     INC        ESI
    //         0055990c     CALL       ___ld12mul                                       undefined ___ld12mul()
    //         00559911     ADD        ESP,0x8
    //                               LAB_00559914                                                 XREF[1]:     005598ff(j)  
    //         00559914     MOV        AL,byte ptr [ESP + Stack[0x14]]
    //         00559918     MOV        word ptr [EDI],SI
    //         0055991b     TEST       AL,0x1
    //         0055991d     JZ         LAB_0055994c
    //         0055991f     MOV        EBP,dword ptr [ESP + Stack[0x10]]
    //         00559923     MOVSX      EDX,SI
    //         00559926     ADD        EBP,EDX
    //         00559928     CMP        EBP,EBX
    //         0055992a     JG         LAB_00559950
    //         0055992c     MOV        word ptr [EDI],BX
    //                               LAB_0055992f                                                 XREF[1]:     005597a5(j)  
    //         0055992f     MOV        byte ptr [EDI + 0x2],0x20
    //         00559933     MOV        byte ptr [EDI + 0x3],0x1
    //         00559937     MOV        byte ptr [EDI + 0x4],0x30
    //         0055993b     MOV        byte ptr [EDI + 0x5],0x0
    //         0055993f     MOV        EAX,0x1
    //         00559944     POP        EDI
    //         00559945     POP        ESI
    //         00559946     POP        EBP
    //         00559947     POP        EBX
    //         00559948     ADD        ESP,0x20
    //         0055994b     RET
    //                               LAB_0055994c                                                 XREF[1]:     0055991d(j)  
    //         0055994c     MOV        EBP,dword ptr [ESP + Stack[0x10]]
    //                               LAB_00559950                                                 XREF[1]:     0055992a(j)  
    //         00559950     CMP        EBP,0x15
    //         00559953     JLE        LAB_0055995a
    //         00559955     MOV        EBP,0x15
    //                               LAB_0055995a                                                 XREF[1]:     00559953(j)  
    //         0055995a     MOV        ESI,dword ptr [ESP + local_6]
    //         0055995e     MOV        word ptr [ESP + local_6],BX
    //         00559963     AND        ESI,0xffff
    //         00559969     MOV        EBX,0x8
    //         0055996e     SUB        ESI,0x3ffe
    //                               LAB_00559974                                                 XREF[1]:     00559982(j)  
    //         00559974     LEA        EAX=>local_10,[ESP + 0x20]
    //         00559978     PUSH       EAX
    //         00559979     CALL       ___shl_12                                        undefined ___shl_12()
    //         0055997e     ADD        ESP,0x4
    //         00559981     DEC        EBX
    //         00559982     JNZ        LAB_00559974
    //         00559984     TEST       ESI,ESI
    //         00559986     JGE        LAB_005599a2
    //         00559988     NEG        ESI
    //         0055998a     AND        ESI,0xff
    //         00559990     JLE        LAB_005599a2
    //                               LAB_00559992                                                 XREF[1]:     005599a0(j)  
    //         00559992     LEA        ECX=>local_10,[ESP + 0x20]
    //         00559996     PUSH       ECX
    //         00559997     CALL       ___shr_12                                        undefined ___shr_12()
    //         0055999c     ADD        ESP,0x4
    //         0055999f     DEC        ESI
    //         005599a0     JNZ        LAB_00559992
    //                               LAB_005599a2                                                 XREF[2]:     00559986(j), 00559990(j)  
    //         005599a2     LEA        ESI,[EDI + 0x4]
    //         005599a5     LEA        EDI,[EBP + 0x1]
    //         005599a8     TEST       EDI,EDI
    //         005599aa     MOV        EBX,ESI
    //         005599ac     JLE        LAB_00559a11
    //                               LAB_005599ae                                                 XREF[1]:     00559a0f(j)  
    //         005599ae     MOV        EDX,dword ptr [ESP + local_10]
    //         005599b2     MOV        EAX,dword ptr [ESP + local_10+0x4]
    //         005599b6     MOV        ECX,dword ptr [ESP + Stack[-0x8]]
    //         005599ba     MOV        dword ptr [ESP + Stack[0x4]],EDX
    //         005599be     LEA        EDX=>local_10,[ESP + 0x20]
    //         005599c2     MOV        dword ptr [ESP + Stack[0x8]],EAX
    //         005599c6     PUSH       EDX
    //         005599c7     MOV        dword ptr [ESP + Stack[0xc]],ECX
    //         005599cb     CALL       ___shl_12                                        undefined ___shl_12()
    //         005599d0     ADD        ESP,0x4
    //         005599d3     LEA        EAX=>local_10,[ESP + 0x20]
    //         005599d7     PUSH       EAX
    //         005599d8     CALL       ___shl_12                                        undefined ___shl_12()
    //         005599dd     ADD        ESP,0x4
    //         005599e0     LEA        ECX=>Stack[0x4],[ESP + 0x34]
    //         005599e4     LEA        EDX=>local_10,[ESP + 0x20]
    //         005599e8     PUSH       ECX
    //         005599e9     PUSH       EDX
    //         005599ea     CALL       ___add_12                                        undefined ___add_12()
    //         005599ef     ADD        ESP,0x8
    //         005599f2     LEA        EAX=>local_10,[ESP + 0x20]
    //         005599f6     PUSH       EAX
    //         005599f7     CALL       ___shl_12                                        undefined ___shl_12()
    //         005599fc     MOV        CL,byte ptr [ESP + local_6+0x1]
    //         00559a00     ADD        ESP,0x4
    //         00559a03     ADD        CL,0x30
    //         00559a06     MOV        byte ptr [ESP + local_6+0x1],0x0
    //         00559a0b     MOV        byte ptr [EBX],CL
    //         00559a0d     INC        EBX
    //         00559a0e     DEC        EDI
    //         00559a0f     JNZ        LAB_005599ae
    //                               LAB_00559a11                                                 XREF[1]:     005599ac(j)  
    //         00559a11     MOV        AL,byte ptr [EBX + -0x1]
    //         00559a14     DEC        EBX
    //         00559a15     DEC        EBX
    //         00559a16     CMP        AL,0x35
    //         00559a18     JL         LAB_00559a4b
    //         00559a1a     CMP        EBX,ESI
    //         00559a1c     JC         LAB_00559a2f
    //                               LAB_00559a1e                                                 XREF[1]:     00559a29(j)  
    //         00559a1e     CMP        byte ptr [EBX],0x39
    //         00559a21     JNZ        LAB_00559a2b
    //         00559a23     MOV        byte ptr [EBX],0x30
    //         00559a26     DEC        EBX
    //         00559a27     CMP        EBX,ESI
    //         00559a29     JNC        LAB_00559a1e
    //                               LAB_00559a2b                                                 XREF[1]:     00559a21(j)  
    //         00559a2b     CMP        EBX,ESI
    //         00559a2d     JNC        LAB_00559a3f
    //                               LAB_00559a2f                                                 XREF[1]:     00559a1c(j)  
    //         00559a2f     MOV        EAX,dword ptr [ESP + Stack[0x18]]
    //         00559a33     INC        EBX
    //         00559a34     INC        word ptr [EAX]
    //         00559a37     MOV        CL,byte ptr [EBX]
    //         00559a39     INC        CL
    //         00559a3b     MOV        byte ptr [EBX],CL
    //         00559a3d     JMP        LAB_00559a86
    //                               LAB_00559a3f                                                 XREF[1]:     00559a2d(j)  
    //         00559a3f     MOV        CL,byte ptr [EBX]
    //         00559a41     MOV        EAX,dword ptr [ESP + Stack[0x18]]
    //         00559a45     INC        CL
    //         00559a47     MOV        byte ptr [EBX],CL
    //         00559a49     JMP        LAB_00559a86
    //                               LAB_00559a4b                                                 XREF[1]:     00559a18(j)  
    //         00559a4b     CMP        EBX,ESI
    //         00559a4d     JC         LAB_00559a5d
    //                               LAB_00559a4f                                                 XREF[1]:     00559a57(j)  
    //         00559a4f     CMP        byte ptr [EBX],0x30
    //         00559a52     JNZ        LAB_00559a59
    //         00559a54     DEC        EBX
    //         00559a55     CMP        EBX,ESI
    //         00559a57     JNC        LAB_00559a4f
    //                               LAB_00559a59                                                 XREF[1]:     00559a52(j)  
    //         00559a59     CMP        EBX,ESI
    //         00559a5b     JNC        LAB_00559a82
    //                               LAB_00559a5d                                                 XREF[1]:     00559a4d(j)  
    //         00559a5d     MOV        EAX,dword ptr [ESP + Stack[0x18]]
    //         00559a61     MOV        byte ptr [ESI],0x30
    //         00559a64     MOV        word ptr [EAX],0x0
    //         00559a69     MOV        byte ptr [EAX + 0x2],0x20
    //         00559a6d     MOV        byte ptr [EAX + 0x3],0x1
    //         00559a71     MOV        byte ptr [EAX + 0x5],0x0
    //         00559a75     MOV        EAX,0x1
    //         00559a7a     POP        EDI
    //         00559a7b     POP        ESI
    //         00559a7c     POP        EBP
    //         00559a7d     POP        EBX
    //         00559a7e     ADD        ESP,0x20
    //         00559a81     RET
    //                               LAB_00559a82                                                 XREF[1]:     00559a5b(j)  
    //         00559a82     MOV        EAX,dword ptr [ESP + Stack[0x18]]
    //                               LAB_00559a86                                                 XREF[2]:     00559a3d(j), 00559a49(j)  
    //         00559a86     SUB        BL,AL
    //         00559a88     POP        EDI
    //         00559a89     SUB        BL,0x3
    //         00559a8c     POP        ESI
    //         00559a8d     MOVSX      EDX,BL
    //         00559a90     MOV        byte ptr [EAX + 0x3],BL
    //         00559a93     POP        EBP
    //         00559a94     MOV        byte ptr [EAX + EDX*0x1 + 0x4],0x0
    //         00559a99     MOV        EAX,dword ptr [ESP + local_20]
    //         00559a9d     POP        EBX
    //         00559a9e     ADD        ESP,0x20
    //         00559aa1     RET
}

// Offset: 0x00559AB0
undefined mbsnbicoll() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined __mbsnbicoll()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               __mbsnbicoll                                                 XREF[2]:     getenv:0055875f(c), 
    //                                                                                                         FUN_0055a620:0055a63a(c)  
    //         00559ab0     MOV        EAX,dword ptr [ESP + Stack[0xc]]
    //         00559ab4     TEST       EAX,EAX
    //         00559ab6     JNZ        LAB_00559ab9
    //         00559ab8     RET
    //                               LAB_00559ab9                                                 XREF[1]:     00559ab6(j)  
    //         00559ab9     MOV        ECX,dword ptr [___mbcodepage]
    //         00559abf     MOV        EDX,dword ptr [ESP + Stack[0x8]]
    //         00559ac3     PUSH       ECX
    //         00559ac4     MOV        ECX,dword ptr [___mblcid]
    //         00559aca     PUSH       EAX
    //         00559acb     PUSH       EDX
    //         00559acc     PUSH       EAX
    //         00559acd     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         00559ad1     PUSH       EAX
    //         00559ad2     PUSH       0x1
    //         00559ad4     PUSH       ECX
    //         00559ad5     CALL       ___crtCompareStringA                             undefined ___crtCompareStringA()
    //         00559ada     ADD        ESP,0x1c
    //         00559add     TEST       EAX,EAX
    //         00559adf     JNZ        LAB_00559ae7
    //         00559ae1     MOV        EAX,0x7fffffff
    //         00559ae6     RET
    //                               LAB_00559ae7                                                 XREF[1]:     00559adf(j)  
    //         00559ae7     ADD        EAX,-0x2
    //         00559aea     RET
}

// Offset: 0x00559AF0
undefined wtomb_environ() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined ___wtomb_environ()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               ___wtomb_environ                                             XREF[2]:     getenv:00558717(c), 
    //                                                                                                         ___crtsetenv:0055a47c(c)  
    //         00559af0     PUSH       EBX
    //         00559af1     MOV        EBX,dword ptr [__wenviron]
    //         00559af7     PUSH       EBP
    //         00559af8     PUSH       ESI
    //         00559af9     MOV        EAX,dword ptr [EBX]
    //         00559afb     PUSH       EDI
    //         00559afc     TEST       EAX,EAX
    //         00559afe     JZ         LAB_00559b63
    //         00559b00     MOV        EBP,dword ptr [->KERNEL32.DLL::WideCharToMulti   = 0048b8a0
    //                               LAB_00559b06                                                 XREF[1]:     00559b54(j)  
    //         00559b06     PUSH       0x0
    //         00559b08     PUSH       0x0=>DAT_fffffff8
    //         00559b0a     PUSH       0x0=>DAT_fffffff4
    //         00559b0c     PUSH       0x0=>DAT_fffffff0
    //         00559b0e     PUSH       -0x1
    //         00559b10     PUSH       EAX
    //         00559b11     PUSH       0x0
    //         00559b13     PUSH       0x1
    //         00559b15     CALL       EBP=>KERNEL32.DLL::WideCharToMultiByte
    //         00559b17     MOV        ESI,EAX
    //         00559b19     TEST       ESI,ESI
    //         00559b1b     JZ         LAB_00559b5b
    //         00559b1d     PUSH       ESI
    //         00559b1e     CALL       malloc                                           undefined malloc()
    //         00559b23     MOV        EDI,EAX
    //         00559b25     ADD        ESP,0x4
    //         00559b28     TEST       EDI,EDI
    //         00559b2a     JZ         LAB_00559b5b
    //         00559b2c     MOV        EAX,dword ptr [EBX]
    //         00559b2e     PUSH       0x0
    //         00559b30     PUSH       0x0=>DAT_fffffff8
    //         00559b32     PUSH       ESI=>DAT_fffffff4
    //         00559b33     PUSH       EDI=>DAT_fffffff0
    //         00559b34     PUSH       -0x1
    //         00559b36     PUSH       EAX
    //         00559b37     PUSH       0x0
    //         00559b39     PUSH       0x1
    //         00559b3b     CALL       EBP=>KERNEL32.DLL::WideCharToMultiByte
    //         00559b3d     TEST       EAX,EAX
    //         00559b3f     JZ         LAB_00559b5b
    //         00559b41     PUSH       0x0
    //         00559b43     PUSH       EDI=>DAT_fffffff8
    //         00559b44     CALL       ___crtsetenv                                     undefined ___crtsetenv()
    //         00559b49     MOV        EAX,dword ptr [EBX + 0x4]
    //         00559b4c     ADD        EBX,0x4
    //         00559b4f     ADD        ESP,0x8
    //         00559b52     TEST       EAX,EAX
    //         00559b54     JNZ        LAB_00559b06
    //         00559b56     POP        EDI
    //         00559b57     POP        ESI
    //         00559b58     POP        EBP
    //         00559b59     POP        EBX
    //         00559b5a     RET
    //                               LAB_00559b5b                                                 XREF[3]:     00559b1b(j), 00559b2a(j), 
    //                                                                                                         00559b3f(j)  
    //         00559b5b     OR         EAX,0xffffffff
    //         00559b5e     POP        EDI
    //         00559b5f     POP        ESI
    //         00559b60     POP        EBP
    //         00559b61     POP        EBX
    //         00559b62     RET
    //                               LAB_00559b63                                                 XREF[1]:     00559afe(j)  
    //         00559b63     POP        EDI
    //         00559b64     POP        ESI
    //         00559b65     POP        EBP
    //         00559b66     XOR        EAX,EAX
    //         00559b68     POP        EBX
    //         00559b69     RET
}

// Offset: 0x00559B70
undefined ld12mul() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined ___ld12mul()
    //              undefined         <UNASSIGNED>   <RETURN>
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[3,3]:   00559bb1(W), 00559ce6(R), 00559def(R), 00559d99(R), 
    //                                                                                     00559da6(W), 00559dae(RW)  
    //              undefined4        Stack[-0x8]:4  local_8                   XREF[4,3]:   00559b91(W), 00559c46(*), 00559c95(*), 00559de8(R), 
    //                                                                                     00559d8f(R), 00559da0(W), 00559db5(RW)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[9,4]:   00559b89(W), 00559c70(*), 00559c80(*), 00559cec(*), 
    //                                                                                     00559d34(R), 00559d3f(*), 00559d65(RW), 00559d6f(R), 
    //                                                                                     00559d76(R), 00559d89(R), 00559d93(W), 00559dbb(RW), 
    //                                                                                     00559de3(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[3]:     00559c6c(W), 00559c98(R), 00559ca3(W)  
    //              undefined4        Stack[-0x14]:4 local_14                  XREF[3]:     00559b85(W), 00559d3b(RW), 00559d5b(R)  
    //              undefined4        Stack[-0x18]:4 local_18                  XREF[4]:     00559c4a(W), 00559c57(R), 00559cbd(R), 00559ccc(W)  
    //              undefined4        Stack[-0x1c]:4 local_1c                  XREF[4]:     00559bb5(W), 00559cb5(R), 00559cfe(R), 00559d57(R)  
    //              undefined4        Stack[-0x20]:4 local_20                  XREF[5]:     00559c4e(W), 00559c62(R), 00559c91(R), 00559cb9(R), 
    //                                                                                     00559cc6(W)  
    //              undefined4        Stack[-0x24]:4 local_24                  XREF[9]:     00559bb9(W), 00559bfe(W), 00559c27(W), 00559cb1(R), 
    //                                                                                     00559ce0(W), 00559cf6(R), 00559d0a(W), 00559d30(W), 
    //                                                                                     00559d53(R)  
    //                               ___ld12mul                                                   XREF[2]:     _$I10_OUTPUT:0055990c(c), 
    //                                                                                                         ___multtenpow12:00559ea7(c)  
    //         00559b70     SUB        ESP,0x24
    //         00559b73     MOV        EDX,dword ptr [ESP + Stack[0x4]]
    //         00559b77     PUSH       EBX
    //         00559b78     PUSH       EBP
    //         00559b79     PUSH       ESI
    //         00559b7a     MOV        AX,word ptr [EDX + 0xa]
    //         00559b7e     PUSH       EDI
    //         00559b7f     MOV        EDI,dword ptr [ESP + Stack[0x8]]
    //         00559b83     XOR        EBP,EBP
    //         00559b85     MOV        dword ptr [ESP + local_14],EBP
    //         00559b89     MOV        dword ptr [ESP + local_c],EBP
    //         00559b8d     MOV        CX,word ptr [EDI + 0xa]
    //         00559b91     MOV        dword ptr [ESP + local_8],EBP
    //         00559b95     MOV        ESI,ECX
    //         00559b97     AND        ECX,0x7fff
    //         00559b9d     XOR        ESI,EAX
    //         00559b9f     AND        EAX,0x7fff
    //         00559ba4     AND        ESI,0x8000
    //         00559baa     CMP        AX,0x7fff
    //         00559bae     LEA        EBX,[ECX + EAX*0x1]
    //         00559bb1     MOV        dword ptr [ESP + local_4],EBP
    //         00559bb5     MOV        dword ptr [ESP + local_1c],ESI
    //         00559bb9     MOV        dword ptr [ESP + local_24],EBX
    //         00559bbd     JNC        LAB_00559e07
    //         00559bc3     CMP        CX,0x7fff
    //         00559bc8     JNC        LAB_00559e07
    //         00559bce     CMP        BX,0xbffd
    //         00559bd3     JA         LAB_00559e07
    //         00559bd9     CMP        BX,0x3fbf
    //         00559bde     JA         LAB_00559bf0
    //         00559be0     MOV        dword ptr [EDX + 0x8],EBP
    //         00559be3     MOV        dword ptr [EDX + 0x4],EBP
    //         00559be6     MOV        dword ptr [EDX],EBP
    //         00559be8     POP        EDI
    //         00559be9     POP        ESI
    //         00559bea     POP        EBP
    //         00559beb     POP        EBX
    //         00559bec     ADD        ESP,0x24
    //         00559bef     RET
    //                               LAB_00559bf0                                                 XREF[1]:     00559bde(j)  
    //         00559bf0     CMP        AX,BP
    //         00559bf3     JNZ        LAB_00559c19
    //         00559bf5     MOV        EAX,dword ptr [EDX + 0x8]
    //         00559bf8     INC        EBX
    //         00559bf9     TEST       EAX,0x7fffffff
    //         00559bfe     MOV        dword ptr [ESP + local_24],EBX
    //         00559c02     JNZ        LAB_00559c19
    //         00559c04     CMP        dword ptr [EDX + 0x4],EBP
    //         00559c07     JNZ        LAB_00559c19
    //         00559c09     CMP        dword ptr [EDX],EBP
    //         00559c0b     JNZ        LAB_00559c19
    //         00559c0d     MOV        word ptr [EDX + 0xa],BP
    //         00559c11     POP        EDI
    //         00559c12     POP        ESI
    //         00559c13     POP        EBP
    //         00559c14     POP        EBX
    //         00559c15     ADD        ESP,0x24
    //         00559c18     RET
    //                               LAB_00559c19                                                 XREF[4]:     00559bf3(j), 00559c02(j), 
    //                                                                                                         00559c07(j), 00559c0b(j)  
    //         00559c19     CMP        CX,BP
    //         00559c1c     JNZ        LAB_00559c46
    //         00559c1e     MOV        EAX,dword ptr [EDI + 0x8]
    //         00559c21     INC        EBX
    //         00559c22     TEST       EAX,0x7fffffff
    //         00559c27     MOV        dword ptr [ESP + local_24],EBX
    //         00559c2b     JNZ        LAB_00559c46
    //         00559c2d     CMP        dword ptr [EDI + 0x4],EBP
    //         00559c30     JNZ        LAB_00559c46
    //         00559c32     CMP        dword ptr [EDI],EBP
    //         00559c34     JNZ        LAB_00559c46
    //         00559c36     MOV        dword ptr [EDX + 0x8],EBP
    //         00559c39     MOV        dword ptr [EDX + 0x4],EBP
    //         00559c3c     MOV        dword ptr [EDX],EBP
    //         00559c3e     POP        EDI
    //         00559c3f     POP        ESI
    //         00559c40     POP        EBP
    //         00559c41     POP        EBX
    //         00559c42     ADD        ESP,0x24
    //         00559c45     RET
    //                               LAB_00559c46                                                 XREF[4]:     00559c1c(j), 00559c2b(j), 
    //                                                                                                         00559c30(j), 00559c34(j)  
    //         00559c46     LEA        EAX=>local_8,[ESP + 0x2c]
    //         00559c4a     MOV        dword ptr [ESP + local_18],EBP
    //         00559c4e     MOV        dword ptr [ESP + local_20],EAX
    //         00559c52     MOV        EBP,0x5
    //                               LAB_00559c57                                                 XREF[1]:     00559cd0(j)  
    //         00559c57     MOV        ECX,dword ptr [ESP + local_18]
    //         00559c5b     TEST       EBP,EBP
    //         00559c5d     LEA        EAX,[ECX + ECX*0x1]
    //         00559c60     JLE        LAB_00559cb9
    //         00559c62     MOV        ECX,dword ptr [ESP + local_20]
    //         00559c66     ADD        EDI,0x8
    //         00559c69     LEA        ESI,[EAX + EDX*0x1]
    //         00559c6c     MOV        dword ptr [ESP + local_10],EBP
    //         00559c70     LEA        EBX=>local_c,[ECX + -0x4]
    //                               LAB_00559c73                                                 XREF[1]:     00559ca7(j)  
    //         00559c73     XOR        EDX,EDX
    //         00559c75     XOR        EAX,EAX
    //         00559c77     MOV        DX,word ptr [EDI]
    //         00559c7a     MOV        AX,word ptr [ESI]
    //         00559c7d     IMUL       EDX,EAX
    //         00559c80     MOV        ECX,dword ptr [EBX]=>local_c
    //         00559c82     PUSH       EBX
    //         00559c83     PUSH       EDX
    //         00559c84     PUSH       ECX
    //         00559c85     CALL       ___addl                                          undefined ___addl()
    //         00559c8a     ADD        ESP,0xc
    //         00559c8d     TEST       EAX,EAX
    //         00559c8f     JZ         LAB_00559c98
    //         00559c91     MOV        EAX,dword ptr [ESP + local_20]
    //         00559c95     INC        word ptr [EAX]=>local_8
    //                               LAB_00559c98                                                 XREF[1]:     00559c8f(j)  
    //         00559c98     MOV        EAX,dword ptr [ESP + local_10]
    //         00559c9c     ADD        ESI,0x2
    //         00559c9f     SUB        EDI,0x2
    //         00559ca2     DEC        EAX
    //         00559ca3     MOV        dword ptr [ESP + local_10],EAX
    //         00559ca7     JNZ        LAB_00559c73
    //         00559ca9     MOV        EDI,dword ptr [ESP + Stack[0x8]]
    //         00559cad     MOV        EDX,dword ptr [ESP + Stack[0x4]]
    //         00559cb1     MOV        EBX,dword ptr [ESP + local_24]
    //         00559cb5     MOV        ESI,dword ptr [ESP + local_1c]
    //                               LAB_00559cb9                                                 XREF[1]:     00559c60(j)  
    //         00559cb9     MOV        ECX,dword ptr [ESP + local_20]
    //         00559cbd     MOV        EAX,dword ptr [ESP + local_18]
    //         00559cc1     ADD        ECX,0x2
    //         00559cc4     INC        EAX
    //         00559cc5     DEC        EBP
    //         00559cc6     MOV        dword ptr [ESP + local_20],ECX
    //         00559cca     TEST       EBP,EBP
    //         00559ccc     MOV        dword ptr [ESP + local_18],EAX
    //         00559cd0     JG         LAB_00559c57
    //         00559cd2     ADD        EBX,0xc002
    //         00559cd8     MOV        EBP,0x80000000
    //         00559cdd     TEST       BX,BX
    //         00559ce0     MOV        dword ptr [ESP + local_24],EBX
    //         00559ce4     JLE        LAB_00559d15
    //                               LAB_00559ce6                                                 XREF[1]:     00559d13(j)  
    //         00559ce6     TEST       dword ptr [ESP + local_4],EBP
    //         00559cea     JNZ        LAB_00559d15
    //         00559cec     LEA        EDX=>local_c,[ESP + 0x28]
    //         00559cf0     PUSH       EDX
    //         00559cf1     CALL       ___shl_12                                        undefined ___shl_12()
    //         00559cf6     MOV        EAX,dword ptr [ESP + local_24]
    //         00559cfa     MOV        EDX,dword ptr [ESP + Stack[0x4]]
    //         00559cfe     MOV        ESI,dword ptr [ESP + local_1c]
    //         00559d02     ADD        EAX,0xffff
    //         00559d07     ADD        ESP,0x4
    //         00559d0a     MOV        dword ptr [ESP + local_24],EAX
    //         00559d0e     TEST       AX,AX
    //         00559d11     MOV        EBX,EAX
    //         00559d13     JG         LAB_00559ce6
    //                               LAB_00559d15                                                 XREF[2]:     00559ce4(j), 00559cea(j)  
    //         00559d15     XOR        ECX,ECX
    //         00559d17     CMP        BX,CX
    //         00559d1a     JG         LAB_00559d6a
    //         00559d1c     ADD        EBX,0xffff
    //         00559d22     CMP        BX,CX
    //         00559d25     JGE        LAB_00559d5b
    //         00559d27     MOVSX      EAX,BX
    //         00559d2a     NEG        EAX
    //         00559d2c     ADD        EBX,EAX
    //         00559d2e     MOV        ESI,EAX
    //         00559d30     MOV        dword ptr [ESP + local_24],EBX
    //                               LAB_00559d34                                                 XREF[1]:     00559d4d(j)  
    //         00559d34     TEST       byte ptr [ESP + local_c],0x1
    //         00559d39     JZ         LAB_00559d3f
    //         00559d3b     INC        dword ptr [ESP + local_14]
    //                               LAB_00559d3f                                                 XREF[1]:     00559d39(j)  
    //         00559d3f     LEA        EAX=>local_c,[ESP + 0x28]
    //         00559d43     PUSH       EAX
    //         00559d44     CALL       ___shr_12                                        undefined ___shr_12()
    //         00559d49     ADD        ESP,0x4
    //         00559d4c     DEC        ESI
    //         00559d4d     JNZ        LAB_00559d34
    //         00559d4f     MOV        EDX,dword ptr [ESP + Stack[0x4]]
    //         00559d53     MOV        EBX,dword ptr [ESP + local_24]
    //         00559d57     MOV        ESI,dword ptr [ESP + local_1c]
    //                               LAB_00559d5b                                                 XREF[1]:     00559d25(j)  
    //         00559d5b     MOV        EAX,dword ptr [ESP + local_14]
    //         00559d5f     XOR        ECX,ECX
    //         00559d61     CMP        EAX,ECX
    //         00559d63     JZ         LAB_00559d6a
    //         00559d65     OR         byte ptr [ESP + local_c],0x1
    //                               LAB_00559d6a                                                 XREF[2]:     00559d1a(j), 00559d63(j)  
    //         00559d6a     MOV        EDI,0x8000
    //         00559d6f     CMP        word ptr [ESP + local_c],DI
    //         00559d74     JA         LAB_00559d86
    //         00559d76     MOV        EAX,dword ptr [ESP + local_c]
    //         00559d7a     AND        EAX,0x1ffff
    //         00559d7f     CMP        EAX,0x18000
    //         00559d84     JNZ        LAB_00559dbf
    //                               LAB_00559d86                                                 XREF[1]:     00559d74(j)  
    //         00559d86     OR         EAX,0xffffffff
    //         00559d89     CMP        dword ptr [ESP + local_c+0x2],EAX
    //         00559d8d     JNZ        LAB_00559dbb
    //         00559d8f     CMP        dword ptr [ESP + local_8+0x2],EAX
    //         00559d93     MOV        dword ptr [ESP + local_c+0x2],ECX
    //         00559d97     JNZ        LAB_00559db5
    //         00559d99     CMP        word ptr [ESP + local_4+0x2],0xffff
    //         00559da0     MOV        dword ptr [ESP + local_8+0x2],ECX
    //         00559da4     JNZ        LAB_00559dae
    //         00559da6     MOV        word ptr [ESP + local_4+0x2],DI
    //         00559dab     INC        EBX
    //         00559dac     JMP        LAB_00559dbf
    //                               LAB_00559dae                                                 XREF[1]:     00559da4(j)  
    //         00559dae     INC        word ptr [ESP + local_4+0x2]
    //         00559db3     JMP        LAB_00559dbf
    //                               LAB_00559db5                                                 XREF[1]:     00559d97(j)  
    //         00559db5     INC        dword ptr [ESP + local_8+0x2]
    //         00559db9     JMP        LAB_00559dbf
    //                               LAB_00559dbb                                                 XREF[1]:     00559d8d(j)  
    //         00559dbb     INC        dword ptr [ESP + local_c+0x2]
    //                               LAB_00559dbf                                                 XREF[4]:     00559d84(j), 00559dac(j), 
    //                                                                                                         00559db3(j), 00559db9(j)  
    //         00559dbf     CMP        BX,0x7fff
    //         00559dc4     JC         LAB_00559de3
    //         00559dc6     NEG        SI
    //         00559dc9     SBB        ESI,ESI
    //         00559dcb     MOV        dword ptr [EDX + 0x4],ECX
    //         00559dce     AND        ESI,EBP
    //         00559dd0     MOV        dword ptr [EDX],ECX
    //         00559dd2     ADD        ESI,0x7fff8000
    //         00559dd8     MOV        dword ptr [EDX + 0x8],ESI
    //         00559ddb     POP        EDI
    //         00559ddc     POP        ESI
    //         00559ddd     POP        EBP
    //         00559dde     POP        EBX
    //         00559ddf     ADD        ESP,0x24
    //         00559de2     RET
    //                               LAB_00559de3                                                 XREF[1]:     00559dc4(j)  
    //         00559de3     MOV        CX,word ptr [ESP + local_c+0x2]
    //         00559de8     MOV        EAX,dword ptr [ESP + local_8]
    //         00559dec     MOV        word ptr [EDX],CX
    //         00559def     MOV        ECX,dword ptr [ESP + local_4]
    //         00559df3     OR         EBX,ESI
    //         00559df5     MOV        dword ptr [EDX + 0x2],EAX
    //         00559df8     MOV        dword ptr [EDX + 0x6],ECX
    //         00559dfb     MOV        word ptr [EDX + 0xa],BX
    //         00559dff     POP        EDI
    //         00559e00     POP        ESI
    //         00559e01     POP        EBP
    //         00559e02     POP        EBX
    //         00559e03     ADD        ESP,0x24
    //         00559e06     RET
    //                               LAB_00559e07                                                 XREF[3]:     00559bbd(j), 00559bc8(j), 
    //                                                                                                         00559bd3(j)  
    //         00559e07     NEG        SI
    //         00559e0a     SBB        ESI,ESI
    //         00559e0c     POP        EDI
    //         00559e0d     AND        ESI,0x80000000
    //         00559e13     MOV        dword ptr [EDX + 0x4],EBP
    //         00559e16     ADD        ESI,0x7fff8000
    //         00559e1c     MOV        dword ptr [EDX],EBP
    //         00559e1e     MOV        dword ptr [EDX + 0x8],ESI
    //         00559e21     POP        ESI
    //         00559e22     POP        EBP
    //         00559e23     POP        EBX
    //         00559e24     ADD        ESP,0x24
    //         00559e27     RET
}

// Offset: 0x00559E30
undefined multtenpow12() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined ___multtenpow12()
    //              undefined         <UNASSIGNED>   <RETURN>
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     00559e94(W)  
    //              undefined4        Stack[-0x8]:4  local_8                   XREF[1]:     00559e8d(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[2,2]:   00559e86(W), 00559ea1(*), 00559e98(R), 00559e9d(W)  
    //                               ___multtenpow12                                              XREF[2]:     ___strgtold12:00558f26(c), 
    //                                                                                                         _$I10_OUTPUT:005598f0(c)  
    //         00559e30     SUB        ESP,0xc
    //         00559e33     PUSH       EBX
    //         00559e34     PUSH       ESI
    //         00559e35     MOV        ESI,dword ptr [ESP + Stack[0x8]]
    //         00559e39     PUSH       EDI
    //         00559e3a     MOV        EDI,__pow10pos                                   = align(9)
    //         00559e3f     SUB        EDI,0x60
    //         00559e42     TEST       ESI,ESI
    //         00559e44     JZ         LAB_00559eb3
    //         00559e46     JGE        LAB_00559e52
    //         00559e48     MOV        EDI,__pow10neg                                   = CDh
    //         00559e4d     NEG        ESI
    //         00559e4f     SUB        EDI,0x60
    //                               LAB_00559e52                                                 XREF[1]:     00559e46(j)  
    //         00559e52     MOV        EAX,dword ptr [ESP + Stack[0xc]]
    //         00559e56     MOV        EBX,dword ptr [ESP + Stack[0x4]]
    //         00559e5a     TEST       EAX,EAX
    //         00559e5c     JNZ        LAB_00559e63
    //         00559e5e     MOV        word ptr [EBX],0x0
    //                               LAB_00559e63                                                 XREF[1]:     00559e5c(j)  
    //         00559e63     TEST       ESI,ESI
    //         00559e65     JZ         LAB_00559eb3
    //                               LAB_00559e67                                                 XREF[1]:     00559eb1(j)  
    //         00559e67     MOV        EAX,ESI
    //         00559e69     ADD        EDI,0x54
    //         00559e6c     AND        EAX,0x7
    //         00559e6f     SAR        ESI,0x3
    //         00559e72     TEST       EAX,EAX
    //         00559e74     JZ         LAB_00559eaf
    //         00559e76     LEA        EAX,[EAX + EAX*0x2]
    //         00559e79     CMP        word ptr [EDI + EAX*0x4]=>DAT_0059281c,0x8000    = 7Fh    
    //                                                                                  = 20h     
    //                                                                                  = 33h    3
    //         00559e7f     LEA        EAX,[EDI + EAX*0x4]
    //         00559e82     JC         LAB_00559ea5
    //         00559e84     MOV        ECX,dword ptr [EAX]=>DAT_0059281c                = 20h     
    //                                                                                  = 33h    3
    //         00559e86     MOV        dword ptr [ESP + local_c],ECX
    //         00559e8a     MOV        EDX,dword ptr [EAX + 0x4]=>DAT_00592820          = 60h    `
    //                                                                                  = 7Ah    z
    //         00559e8d     MOV        dword ptr [ESP + local_8],EDX
    //         00559e91     MOV        EAX,dword ptr [EAX + 0x8]=>DAT_00592824          = BFh
    //         00559e94     MOV        dword ptr [ESP + local_4],EAX
    //         00559e98     MOV        EAX,dword ptr [ESP + local_c+0x2]
    //         00559e9c     DEC        EAX
    //         00559e9d     MOV        dword ptr [ESP + local_c+0x2],EAX
    //         00559ea1     LEA        EAX=>local_c,[ESP + 0xc]
    //                               LAB_00559ea5                                                 XREF[1]:     00559e82(j)  
    //         00559ea5     PUSH       EAX
    //         00559ea6     PUSH       EBX
    //         00559ea7     CALL       ___ld12mul                                       undefined ___ld12mul()
    //         00559eac     ADD        ESP,0x8
    //                               LAB_00559eaf                                                 XREF[1]:     00559e74(j)  
    //         00559eaf     TEST       ESI,ESI
    //         00559eb1     JNZ        LAB_00559e67
    //                               LAB_00559eb3                                                 XREF[2]:     00559e44(j), 00559e65(j)  
    //         00559eb3     POP        EDI
    //         00559eb4     POP        ESI
    //         00559eb5     POP        EBX
    //         00559eb6     ADD        ESP,0xc
    //         00559eb9     RET
}

// Offset: 0x00559EBA
undefined FUN_00559eba() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00559eba()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00559eba
    //         00559eba     NOP
    //         00559ebb     NOP
    //         00559ebc     NOP
    //         00559ebd     NOP
    //         00559ebe     NOP
    //         00559ebf     NOP
    //                               ___crtCompareStringW
    //         00559ec0     MOV        EAX,[null_00888444]                              = align(4)
    //         00559ec5     PUSH       EBX
    //         00559ec6     PUSH       EBP
    //         00559ec7     PUSH       ESI
    //         00559ec8     PUSH       EDI
    //         00559ec9     MOV        EDI,dword ptr [->KERNEL32.DLL::CompareStringW]   = 0048ba5a
    //         00559ecf     TEST       EAX,EAX
    //         00559ed1     JNZ        LAB_00559f21
    //         00559ed3     PUSH       0x1
    //         00559ed5     PUSH       u_                                               = u""
    //         00559eda     PUSH       0x1
    //         00559edc     PUSH       u_                                               = u""
    //         00559ee1     PUSH       0x0
    //         00559ee3     PUSH       0x0
    //         00559ee5     CALL       EDI=>KERNEL32.DLL::CompareStringW
    //         00559ee7     TEST       EAX,EAX
    //         00559ee9     JZ         LAB_00559ef7
    //         00559eeb     MOV        dword ptr [null_00888444],0x1                    = align(4)
    //         00559ef5     JMP        LAB_00559f21
    //                               LAB_00559ef7                                                 XREF[1]:     00559ee9(j)  
    //         00559ef7     PUSH       0x1
    //         00559ef9     PUSH       offset DAT_fffffff8                              = ""
    //         00559efe     PUSH       offset DAT_fffffff4
    //         00559f00     PUSH       offset DAT_fffffff0                              = ""
    //         00559f05     PUSH       0x0
    //         00559f07     PUSH       0x0
    //         00559f09     CALL       dword ptr [->KERNEL32.DLL::CompareStringA]       = 0048abe4
    //         00559f0f     TEST       EAX,EAX
    //         00559f11     JZ         LAB_0055a064
    //         00559f17     MOV        dword ptr [null_00888444],0x2                    = align(4)
    //                               LAB_00559f21                                                 XREF[2]:     00559ed1(j), 00559ef5(j)  
    //         00559f21     MOV        ESI,dword ptr [ESP + Stack[0x10]]
    //         00559f25     TEST       ESI,ESI
    //         00559f27     JLE        LAB_00559f3b
    //         00559f29     MOV        EBX,dword ptr [ESP + Stack[0xc]]
    //         00559f2d     PUSH       ESI
    //         00559f2e     PUSH       EBX=>DAT_fffffff8
    //         00559f2f     CALL       FUN_0055a0d0                                     undefined FUN_0055a0d0()
    //         00559f34     ADD        ESP,0x8
    //         00559f37     MOV        ESI,EAX
    //         00559f39     JMP        LAB_00559f3f
    //                               LAB_00559f3b                                                 XREF[1]:     00559f27(j)  
    //         00559f3b     MOV        EBX,dword ptr [ESP + 0x1c]
    //                               LAB_00559f3f                                                 XREF[1]:     00559f39(j)  
    //         00559f3f     MOV        EAX,dword ptr [ESP + 0x28]
    //         00559f43     TEST       EAX,EAX
    //         00559f45     JLE        LAB_00559f59
    //         00559f47     PUSH       EAX
    //         00559f48     MOV        EAX,dword ptr [ESP + 0x28]
    //         00559f4c     PUSH       EAX=>DAT_fffffff8
    //         00559f4d     CALL       FUN_0055a0d0                                     undefined FUN_0055a0d0()
    //         00559f52     ADD        ESP,0x8
    //         00559f55     MOV        dword ptr [ESP + 0x28],EAX
    //                               LAB_00559f59                                                 XREF[1]:     00559f45(j)  
    //         00559f59     TEST       ESI,ESI
    //         00559f5b     JZ         LAB_0055a0a2
    //         00559f61     TEST       EAX,EAX
    //         00559f63     JZ         LAB_0055a0a2
    //         00559f69     MOV        ECX,dword ptr [null_00888444]                    = align(4)
    //         00559f6f     CMP        ECX,0x1
    //         00559f72     JNZ        LAB_00559f8d
    //         00559f74     MOV        ECX,dword ptr [ESP + 0x24]
    //         00559f78     MOV        EDX,dword ptr [ESP + 0x18]
    //         00559f7c     PUSH       EAX
    //         00559f7d     MOV        EAX,dword ptr [ESP + 0x18]
    //         00559f81     PUSH       ECX=>DAT_fffffff8
    //         00559f82     PUSH       ESI=>DAT_fffffff4
    //         00559f83     PUSH       EBX=>DAT_fffffff0
    //         00559f84     PUSH       EDX
    //         00559f85     PUSH       EAX
    //         00559f86     CALL       EDI=>KERNEL32.DLL::CompareStringW
    //         00559f88     POP        EDI
    //         00559f89     POP        ESI
    //         00559f8a     POP        EBP
    //         00559f8b     POP        EBX
    //         00559f8c     RET
    //                               LAB_00559f8d                                                 XREF[1]:     00559f72(j)  
    //         00559f8d     CMP        ECX,0x2
    //         00559f90     JNZ        LAB_0055a0bd
    //         00559f96     MOV        EDI,dword ptr [ESP + 0x2c]
    //         00559f9a     MOV        dword ptr [ESP + 0x20],0x0
    //         00559fa2     TEST       EDI,EDI
    //         00559fa4     JNZ        LAB_00559fac
    //         00559fa6     MOV        EDI,dword ptr [___lc_codepage]
    //                               LAB_00559fac                                                 XREF[1]:     00559fa4(j)  
    //         00559fac     PUSH       0x0
    //         00559fae     PUSH       0x0=>DAT_fffffff8
    //         00559fb0     PUSH       0x0=>DAT_fffffff4
    //         00559fb2     PUSH       0x0=>DAT_fffffff0
    //         00559fb4     PUSH       ESI
    //         00559fb5     PUSH       EBX
    //         00559fb6     MOV        EBX,dword ptr [->KERNEL32.DLL::WideCharToMulti   = 0048b8a0
    //         00559fbc     PUSH       0x220
    //         00559fc1     PUSH       EDI
    //         00559fc2     CALL       EBX=>KERNEL32.DLL::WideCharToMultiByte
    //         00559fc4     MOV        EBP,EAX
    //         00559fc6     TEST       EBP,EBP
    //         00559fc8     JNZ        LAB_00559fcf
    //         00559fca     POP        EDI
    //         00559fcb     POP        ESI
    //         00559fcc     POP        EBP
    //         00559fcd     POP        EBX
    //         00559fce     RET
    //                               LAB_00559fcf                                                 XREF[1]:     00559fc8(j)  
    //         00559fcf     PUSH       EBP
    //         00559fd0     CALL       malloc                                           undefined malloc()
    //         00559fd5     ADD        ESP,0x4
    //         00559fd8     MOV        dword ptr [ESP + 0x2c],EAX
    //         00559fdc     TEST       EAX,EAX
    //         00559fde     JNZ        LAB_00559fe5
    //         00559fe0     POP        EDI
    //         00559fe1     POP        ESI
    //         00559fe2     POP        EBP
    //         00559fe3     POP        EBX
    //         00559fe4     RET
    //                               LAB_00559fe5                                                 XREF[1]:     00559fde(j)  
    //         00559fe5     MOV        ECX,dword ptr [ESP + 0x1c]
    //         00559fe9     PUSH       0x0
    //         00559feb     PUSH       0x0=>DAT_fffffff8
    //         00559fed     PUSH       EBP=>DAT_fffffff4
    //         00559fee     PUSH       EAX=>DAT_fffffff0
    //         00559fef     PUSH       ESI
    //         00559ff0     PUSH       ECX
    //         00559ff1     PUSH       0x220
    //         00559ff6     PUSH       EDI
    //         00559ff7     CALL       EBX=>KERNEL32.DLL::WideCharToMultiByte
    //         00559ff9     TEST       EAX,EAX
    //         00559ffb     JZ         LAB_0055a04a
    //         00559ffd     MOV        EDX,dword ptr [ESP + 0x28]
    //         0055a001     MOV        EAX,dword ptr [ESP + 0x24]
    //         0055a005     PUSH       0x0
    //         0055a007     PUSH       0x0=>DAT_fffffff8
    //         0055a009     PUSH       0x0=>DAT_fffffff4
    //         0055a00b     PUSH       0x0=>DAT_fffffff0
    //         0055a00d     PUSH       EDX
    //         0055a00e     PUSH       EAX
    //         0055a00f     PUSH       0x220
    //         0055a014     PUSH       EDI
    //         0055a015     CALL       EBX=>KERNEL32.DLL::WideCharToMultiByte
    //         0055a017     MOV        ESI,EAX
    //         0055a019     TEST       ESI,ESI
    //         0055a01b     JZ         LAB_0055a04a
    //         0055a01d     PUSH       ESI
    //         0055a01e     CALL       malloc                                           undefined malloc()
    //         0055a023     ADD        ESP,0x4
    //         0055a026     MOV        dword ptr [ESP + 0x20],EAX
    //         0055a02a     TEST       EAX,EAX
    //         0055a02c     JZ         LAB_0055a04a
    //         0055a02e     MOV        ECX,dword ptr [ESP + 0x28]
    //         0055a032     MOV        EDX,dword ptr [ESP + 0x24]
    //         0055a036     PUSH       0x0
    //         0055a038     PUSH       0x0=>DAT_fffffff8
    //         0055a03a     PUSH       ESI=>DAT_fffffff4
    //         0055a03b     PUSH       EAX=>DAT_fffffff0
    //         0055a03c     PUSH       ECX
    //         0055a03d     PUSH       EDX
    //         0055a03e     PUSH       0x220
    //         0055a043     PUSH       EDI
    //         0055a044     CALL       EBX=>KERNEL32.DLL::WideCharToMultiByte
    //         0055a046     TEST       EAX,EAX
    //         0055a048     JNZ        LAB_0055a06b
    //                               LAB_0055a04a                                                 XREF[3]:     00559ffb(j), 0055a01b(j), 
    //                                                                                                         0055a02c(j)  
    //         0055a04a     MOV        EAX,dword ptr [ESP + 0x2c]
    //         0055a04e     PUSH       EAX
    //         0055a04f     CALL       free                                             undefined free()
    //         0055a054     MOV        ECX,dword ptr [ESP + 0x24]
    //         0055a058     ADD        ESP,0x4
    //         0055a05b     PUSH       ECX
    //         0055a05c     CALL       free                                             undefined free()
    //         0055a061     ADD        ESP,0x4
    //                               LAB_0055a064                                                 XREF[1]:     00559f11(j)  
    //         0055a064     XOR        EAX,EAX
    //         0055a066     POP        EDI
    //         0055a067     POP        ESI
    //         0055a068     POP        EBP
    //         0055a069     POP        EBX
    //         0055a06a     RET
    //                               LAB_0055a06b                                                 XREF[1]:     0055a048(j)  
    //         0055a06b     MOV        EDI,dword ptr [ESP + 0x20]
    //         0055a06f     MOV        EBX,dword ptr [ESP + 0x2c]
    //         0055a073     MOV        EDX,dword ptr [ESP + 0x18]
    //         0055a077     MOV        EAX,dword ptr [ESP + 0x14]
    //         0055a07b     PUSH       ESI
    //         0055a07c     PUSH       EDI=>DAT_fffffff8
    //         0055a07d     PUSH       EBP=>DAT_fffffff4
    //         0055a07e     PUSH       EBX=>DAT_fffffff0
    //         0055a07f     PUSH       EDX
    //         0055a080     PUSH       EAX
    //         0055a081     CALL       dword ptr [->KERNEL32.DLL::CompareStringA]       = 0048abe4
    //         0055a087     PUSH       EBX
    //         0055a088     MOV        ESI,EAX
    //         0055a08a     CALL       free                                             undefined free()
    //         0055a08f     ADD        ESP,0x4
    //         0055a092     PUSH       EDI
    //         0055a093     CALL       free                                             undefined free()
    //         0055a098     ADD        ESP,0x4
    //         0055a09b     MOV        EAX,ESI
    //         0055a09d     POP        EDI
    //         0055a09e     POP        ESI
    //         0055a09f     POP        EBP
    //         0055a0a0     POP        EBX
    //         0055a0a1     RET
    //                               LAB_0055a0a2                                                 XREF[2]:     00559f5b(j), 00559f63(j)  
    //         0055a0a2     SUB        ESI,EAX
    //         0055a0a4     JNZ        LAB_0055a0b0
    //         0055a0a6     MOV        EAX,0x2
    //         0055a0ab     POP        EDI
    //         0055a0ac     POP        ESI
    //         0055a0ad     POP        EBP
    //         0055a0ae     POP        EBX
    //         0055a0af     RET
    //                               LAB_0055a0b0                                                 XREF[1]:     0055a0a4(j)  
    //         0055a0b0     XOR        EAX,EAX
    //         0055a0b2     TEST       ESI,ESI
    //         0055a0b4     SETGE      AL
    //         0055a0b7     DEC        EAX
    //         0055a0b8     AND        AL,0xfe
    //         0055a0ba     ADD        EAX,0x3
    //                               LAB_0055a0bd                                                 XREF[1]:     00559f90(j)  
    //         0055a0bd     POP        EDI
    //         0055a0be     POP        ESI
    //         0055a0bf     POP        EBP
    //         0055a0c0     POP        EBX
    //         0055a0c1     RET
}

