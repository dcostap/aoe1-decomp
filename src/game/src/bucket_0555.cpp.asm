// Auto-generated scaffold unit: bucket_0555.cpp.asm
#include "../include/common.h"

// Offset: 0x00555190
undefined FUN_00555190() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00555190()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00555190                                                 XREF[1]:     FUN_00554f71:00554fea(c)  
    //         00555190     MOV        EDX,dword ptr [ESP + Stack[0x8]]
    //         00555194     PUSH       ESI
    //         00555195     MOV        ESI,dword ptr [ESP + Stack[0x4]]
    //         00555199     PUSH       EDI
    //         0055519a     TEST       EDX,EDX
    //         0055519c     MOV        EAX,ESI
    //         0055519e     LEA        ECX,[EDX + -0x1]
    //         005551a1     JZ         LAB_005551b3
    //                               LAB_005551a3                                                 XREF[1]:     005551b1(j)  
    //         005551a3     CMP        word ptr [EAX],0x0
    //         005551a7     JZ         LAB_005551b9
    //         005551a9     ADD        EAX,0x2
    //         005551ac     MOV        EDI,ECX
    //         005551ae     DEC        ECX
    //         005551af     TEST       EDI,EDI
    //         005551b1     JNZ        LAB_005551a3
    //                               LAB_005551b3                                                 XREF[1]:     005551a1(j)  
    //         005551b3     CMP        word ptr [EAX],0x0
    //         005551b7     JNZ        LAB_005551c0
    //                               LAB_005551b9                                                 XREF[1]:     005551a7(j)  
    //         005551b9     SUB        EAX,ESI
    //         005551bb     SAR        EAX,0x1
    //         005551bd     POP        EDI
    //         005551be     POP        ESI
    //         005551bf     RET
    //                               LAB_005551c0                                                 XREF[1]:     005551b7(j)  
    //         005551c0     POP        EDI
    //         005551c1     MOV        EAX,EDX
    //         005551c3     POP        ESI
    //         005551c4     RET
}

// Offset: 0x005551D0
undefined crtLCMapStringA() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined ___crtLCMapStringA()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               ___crtLCMapStringA                                           XREF[6]:     toupper:0054e309(c), 
    //                                                                                                         tolower:0054e419(c), 
    //                                                                                                         __mbsupr:0054f81d(c), 
    //                                                                                                         __mbctoupper:00555471(c), 
    //                                                                                                         strupr:0055bc8b(c), 
    //                                                                                                         strupr:0055bcba(c)  
    //         005551d0     MOV        EAX,[DAT_008882b4]
    //         005551d5     PUSH       EBX
    //         005551d6     MOV        EBX,dword ptr [->KERNEL32.DLL::LCMapStringA]     = 0048b910
    //         005551dc     PUSH       EBP
    //         005551dd     PUSH       ESI
    //         005551de     PUSH       EDI
    //         005551df     TEST       EAX,EAX
    //         005551e1     JNZ        LAB_0055522c
    //         005551e3     PUSH       0x0
    //         005551e5     PUSH       0x0
    //         005551e7     PUSH       0x1
    //         005551e9     PUSH       s_                                               = ""
    //         005551ee     PUSH       0x100
    //         005551f3     PUSH       0x0
    //         005551f5     CALL       EBX=>KERNEL32.DLL::LCMapStringA
    //         005551f7     TEST       EAX,EAX
    //         005551f9     JZ         LAB_00555202
    //         005551fb     MOV        EAX,0x2
    //         00555200     JMP        LAB_00555227
    //                               LAB_00555202                                                 XREF[1]:     005551f9(j)  
    //         00555202     PUSH       0x0
    //         00555204     PUSH       0x0=>DAT_fffffff8
    //         00555206     PUSH       offset DAT_fffffff4
    //         00555208     PUSH       u_                                               = u""
    //         0055520d     PUSH       0x100
    //         00555212     PUSH       0x0
    //         00555214     CALL       dword ptr [->KERNEL32.DLL::LCMapStringW]         = 0048b920
    //         0055521a     TEST       EAX,EAX
    //         0055521c     JZ         LAB_005553e5
    //         00555222     MOV        EAX,0x1
    //                               LAB_00555227                                                 XREF[1]:     00555200(j)  
    //         00555227     MOV        [DAT_008882b4],EAX
    //                               LAB_0055522c                                                 XREF[1]:     005551e1(j)  
    //         0055522c     MOV        ESI,dword ptr [ESP + Stack[0x10]]
    //         00555230     TEST       ESI,ESI
    //         00555232     JLE        LAB_0055524b
    //         00555234     MOV        EDI,dword ptr [ESP + Stack[0xc]]
    //         00555238     PUSH       ESI
    //         00555239     PUSH       EDI=>DAT_fffffff8
    //         0055523a     CALL       FUN_005553f0                                     undefined FUN_005553f0()
    //         0055523f     MOV        ESI,EAX
    //         00555241     MOV        EAX,[DAT_008882b4]
    //         00555246     ADD        ESP,0x8
    //         00555249     JMP        LAB_0055524f
    //                               LAB_0055524b                                                 XREF[1]:     00555232(j)  
    //         0055524b     MOV        EDI,dword ptr [ESP + 0x1c]
    //                               LAB_0055524f                                                 XREF[1]:     00555249(j)  
    //         0055524f     CMP        EAX,0x2
    //         00555252     JNZ        LAB_00555271
    //         00555254     MOV        EAX,dword ptr [ESP + 0x28]
    //         00555258     MOV        ECX,dword ptr [ESP + 0x24]
    //         0055525c     MOV        EDX,dword ptr [ESP + 0x18]
    //         00555260     PUSH       EAX
    //         00555261     MOV        EAX,dword ptr [ESP + 0x18]
    //         00555265     PUSH       ECX=>DAT_fffffff8
    //         00555266     PUSH       ESI=>DAT_fffffff4
    //         00555267     PUSH       EDI=>DAT_fffffff0
    //         00555268     PUSH       EDX
    //         00555269     PUSH       EAX
    //         0055526a     CALL       EBX=>KERNEL32.DLL::LCMapStringA
    //         0055526c     POP        EDI
    //         0055526d     POP        ESI
    //         0055526e     POP        EBP
    //         0055526f     POP        EBX
    //         00555270     RET
    //                               LAB_00555271                                                 XREF[1]:     00555252(j)  
    //         00555271     CMP        EAX,0x1
    //         00555274     JNZ        LAB_0055534c
    //         0055527a     MOV        EBP,dword ptr [ESP + 0x2c]
    //         0055527e     MOV        dword ptr [ESP + 0x20],0x0
    //         00555286     TEST       EBP,EBP
    //         00555288     JNZ        LAB_00555296
    //         0055528a     MOV        ECX,dword ptr [___lc_codepage]
    //         00555290     MOV        dword ptr [ESP + 0x2c],ECX
    //         00555294     MOV        EBP,ECX
    //                               LAB_00555296                                                 XREF[1]:     00555288(j)  
    //         00555296     PUSH       0x0
    //         00555298     PUSH       0x0=>DAT_fffffff8
    //         0055529a     PUSH       ESI=>DAT_fffffff4
    //         0055529b     PUSH       EDI=>DAT_fffffff0
    //         0055529c     PUSH       0x9
    //         0055529e     PUSH       EBP
    //         0055529f     CALL       dword ptr [->KERNEL32.DLL::MultiByteToWideChar]  = 0048b8da
    //         005552a5     MOV        EDI,EAX
    //         005552a7     TEST       EDI,EDI
    //         005552a9     JNZ        LAB_005552b0
    //         005552ab     POP        EDI
    //         005552ac     POP        ESI
    //         005552ad     POP        EBP
    //         005552ae     POP        EBX
    //         005552af     RET
    //                               LAB_005552b0                                                 XREF[1]:     005552a9(j)  
    //         005552b0     LEA        EDX,[EDI + EDI*0x1]
    //         005552b3     PUSH       EDX
    //         005552b4     CALL       malloc                                           undefined malloc()
    //         005552b9     MOV        EBX,EAX
    //         005552bb     ADD        ESP,0x4
    //         005552be     TEST       EBX,EBX
    //         005552c0     JNZ        LAB_005552c7
    //         005552c2     POP        EDI
    //         005552c3     POP        ESI
    //         005552c4     POP        EBP
    //         005552c5     POP        EBX
    //         005552c6     RET
    //                               LAB_005552c7                                                 XREF[1]:     005552c0(j)  
    //         005552c7     MOV        EAX,dword ptr [ESP + 0x1c]
    //         005552cb     PUSH       EDI
    //         005552cc     PUSH       EBX=>DAT_fffffff8
    //         005552cd     PUSH       ESI=>DAT_fffffff4
    //         005552ce     PUSH       EAX=>DAT_fffffff0
    //         005552cf     PUSH       0x1
    //         005552d1     PUSH       EBP
    //         005552d2     CALL       dword ptr [->KERNEL32.DLL::MultiByteToWideChar]  = 0048b8da
    //         005552d8     TEST       EAX,EAX
    //         005552da     JZ         LAB_005553cf
    //         005552e0     MOV        EBP,dword ptr [ESP + 0x18]
    //         005552e4     MOV        ECX,dword ptr [ESP + 0x14]
    //         005552e8     PUSH       0x0
    //         005552ea     PUSH       0x0=>DAT_fffffff8
    //         005552ec     PUSH       EDI=>DAT_fffffff4
    //         005552ed     PUSH       EBX=>DAT_fffffff0
    //         005552ee     PUSH       EBP
    //         005552ef     PUSH       ECX
    //         005552f0     CALL       dword ptr [->KERNEL32.DLL::LCMapStringW]         = 0048b920
    //         005552f6     MOV        ESI,EAX
    //         005552f8     TEST       ESI,ESI
    //         005552fa     JZ         LAB_005553cf
    //         00555300     TEST       EBP,0x400
    //         00555306     JZ         LAB_00555351
    //         00555308     MOV        EAX,dword ptr [ESP + 0x28]
    //         0055530c     TEST       EAX,EAX
    //         0055530e     JZ         LAB_00555334
    //         00555310     CMP        ESI,EAX
    //         00555312     JG         LAB_005553cf
    //         00555318     MOV        EDX,dword ptr [ESP + 0x24]
    //         0055531c     PUSH       EAX
    //         0055531d     MOV        EAX,dword ptr [ESP + 0x18]
    //         00555321     PUSH       EDX=>DAT_fffffff8
    //         00555322     PUSH       EDI=>DAT_fffffff4
    //         00555323     PUSH       EBX=>DAT_fffffff0
    //         00555324     PUSH       EBP
    //         00555325     PUSH       EAX
    //         00555326     CALL       dword ptr [->KERNEL32.DLL::LCMapStringW]         = 0048b920
    //         0055532c     TEST       EAX,EAX
    //         0055532e     JZ         LAB_005553cf
    //                               LAB_00555334                                                 XREF[3]:     0055530e(j), 005553a7(j), 
    //                                                                                                         005553c9(j)  
    //         00555334     PUSH       EBX
    //         00555335     CALL       free                                             undefined free()
    //         0055533a     MOV        ECX,dword ptr [ESP + 0x24]
    //         0055533e     ADD        ESP,0x4
    //         00555341     PUSH       ECX
    //         00555342     CALL       free                                             undefined free()
    //         00555347     ADD        ESP,0x4
    //         0055534a     MOV        EAX,ESI
    //                               LAB_0055534c                                                 XREF[1]:     00555274(j)  
    //         0055534c     POP        EDI
    //         0055534d     POP        ESI
    //         0055534e     POP        EBP
    //         0055534f     POP        EBX
    //         00555350     RET
    //                               LAB_00555351                                                 XREF[1]:     00555306(j)  
    //         00555351     LEA        ECX,[ESI + ESI*0x1]
    //         00555354     PUSH       ECX
    //         00555355     CALL       malloc                                           undefined malloc()
    //         0055535a     ADD        ESP,0x4
    //         0055535d     MOV        dword ptr [ESP + 0x20],EAX
    //         00555361     TEST       EAX,EAX
    //         00555363     JZ         LAB_005553cf
    //         00555365     MOV        EDX,EAX
    //         00555367     MOV        EAX,dword ptr [ESP + 0x14]
    //         0055536b     PUSH       ESI
    //         0055536c     PUSH       EDX=>DAT_fffffff8
    //         0055536d     PUSH       EDI=>DAT_fffffff4
    //         0055536e     PUSH       EBX=>DAT_fffffff0
    //         0055536f     PUSH       EBP
    //         00555370     PUSH       EAX
    //         00555371     CALL       dword ptr [->KERNEL32.DLL::LCMapStringW]         = 0048b920
    //         00555377     TEST       EAX,EAX
    //         00555379     JZ         LAB_005553cf
    //         0055537b     MOV        EAX,dword ptr [ESP + 0x28]
    //         0055537f     PUSH       0x0
    //         00555381     TEST       EAX,EAX
    //         00555383     PUSH       0x0=>DAT_fffffff8
    //         00555385     JNZ        LAB_005553a9
    //         00555387     MOV        ECX,dword ptr [ESP + 0x28]
    //         0055538b     MOV        EDX,dword ptr [ESP + 0x34]
    //         0055538f     PUSH       0x0=>DAT_fffffff4
    //         00555391     PUSH       0x0=>DAT_fffffff0
    //         00555393     PUSH       ESI
    //         00555394     PUSH       ECX
    //         00555395     PUSH       0x220
    //         0055539a     PUSH       EDX
    //         0055539b     CALL       dword ptr [->KERNEL32.DLL::WideCharToMultiByte]  = 0048b8a0
    //         005553a1     MOV        ESI,EAX
    //         005553a3     TEST       ESI,ESI
    //         005553a5     JZ         LAB_005553cf
    //         005553a7     JMP        LAB_00555334
    //                               LAB_005553a9                                                 XREF[1]:     00555385(j)  
    //         005553a9     MOV        ECX,dword ptr [ESP + 0x28]
    //         005553ad     MOV        EDX,dword ptr [ESP + 0x34]
    //         005553b1     PUSH       EAX=>DAT_fffffff4
    //         005553b2     MOV        EAX,dword ptr [ESP + 0x30]
    //         005553b6     PUSH       EAX=>DAT_fffffff0
    //         005553b7     PUSH       ESI
    //         005553b8     PUSH       ECX
    //         005553b9     PUSH       0x220
    //         005553be     PUSH       EDX
    //         005553bf     CALL       dword ptr [->KERNEL32.DLL::WideCharToMultiByte]  = 0048b8a0
    //         005553c5     MOV        ESI,EAX
    //         005553c7     TEST       ESI,ESI
    //         005553c9     JNZ        LAB_00555334
    //                               LAB_005553cf                                                 XREF[7]:     005552da(j), 005552fa(j), 
    //                                                                                                         00555312(j), 0055532e(j), 
    //                                                                                                         00555363(j), 00555379(j), 
    //                                                                                                         005553a5(j)  
    //         005553cf     PUSH       EBX
    //         005553d0     CALL       free                                             undefined free()
    //         005553d5     MOV        EAX,dword ptr [ESP + 0x24]
    //         005553d9     ADD        ESP,0x4
    //         005553dc     PUSH       EAX
    //         005553dd     CALL       free                                             undefined free()
    //         005553e2     ADD        ESP,0x4
    //                               LAB_005553e5                                                 XREF[1]:     0055521c(j)  
    //         005553e5     POP        EDI
    //         005553e6     POP        ESI
    //         005553e7     POP        EBP
    //         005553e8     XOR        EAX,EAX
    //         005553ea     POP        EBX
    //         005553eb     RET
}

// Offset: 0x005553F0
undefined FUN_005553f0() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_005553f0()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_005553f0                                                 XREF[1]:     ___crtLCMapStringA:0055523a(c)  
    //         005553f0     MOV        EDX,dword ptr [ESP + Stack[0x8]]
    //         005553f4     PUSH       ESI
    //         005553f5     MOV        ESI,dword ptr [ESP + Stack[0x4]]
    //         005553f9     TEST       EDX,EDX
    //         005553fb     PUSH       EDI
    //         005553fc     MOV        EAX,ESI
    //         005553fe     LEA        ECX,[EDX + -0x1]
    //         00555401     JZ         LAB_00555410
    //                               LAB_00555403                                                 XREF[1]:     0055540e(j)  
    //         00555403     CMP        byte ptr [EAX],0x0
    //         00555406     JZ         LAB_00555410
    //         00555408     INC        EAX
    //         00555409     MOV        EDI,ECX
    //         0055540b     DEC        ECX
    //         0055540c     TEST       EDI,EDI
    //         0055540e     JNZ        LAB_00555403
    //                               LAB_00555410                                                 XREF[2]:     00555401(j), 00555406(j)  
    //         00555410     CMP        byte ptr [EAX],0x0
    //         00555413     JNZ        LAB_0055541a
    //         00555415     SUB        EAX,ESI
    //         00555417     POP        EDI
    //         00555418     POP        ESI
    //         00555419     RET
    //                               LAB_0055541a                                                 XREF[1]:     00555413(j)  
    //         0055541a     POP        EDI
    //         0055541b     POP        ESI
    //         0055541c     MOV        EAX,EDX
    //         0055541e     RET
}

// Offset: 0x00555420
undefined mbctoupper() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined __mbctoupper()
    //              undefined         <UNASSIGNED>   <RETURN>
    //              undefined4        Stack[-0x8]:4  local_8                   XREF[2,1]:   00555456(*), 0055547d(R), 00555481(R)  
    //                               __mbctoupper                                                 XREF[1]:     __chdir:0054e55d(c)  
    //         00555420     SUB        ESP,0x8
    //         00555423     PUSH       EBX
    //         00555424     MOV        EBX,dword ptr [ESP + Stack[0x4]]
    //         00555428     CMP        EBX,0xff
    //         0055542e     JBE        LAB_0055549a
    //         00555430     MOV        EAX,EBX
    //         00555432     MOV        byte ptr [ESP + Stack[0x5]],BL
    //         00555436     SHR        EAX,0x8
    //         00555439     MOV        byte ptr [ESP + Stack[0x4]],AL
    //         0055543d     MOV        ECX,dword ptr [ESP + Stack[0x4]]
    //         00555441     AND        ECX,0xff
    //         00555447     TEST       byte ptr [ECX + __mbctype+1],0x4
    //         0055544e     JZ         LAB_005554a7
    //         00555450     MOV        EDX,dword ptr [___mbcodepage]
    //         00555456     LEA        EAX=>local_8,[ESP + 0x4]
    //         0055545a     PUSH       EDX
    //         0055545b     MOV        EDX,dword ptr [___mblcid]
    //         00555461     PUSH       0x2
    //         00555463     PUSH       EAX
    //         00555464     LEA        ECX=>Stack[0x4],[ESP + 0x1c]
    //         00555468     PUSH       0x2
    //         0055546a     PUSH       ECX
    //         0055546b     PUSH       0x200
    //         00555470     PUSH       EDX
    //         00555471     CALL       ___crtLCMapStringA                               undefined ___crtLCMapStringA()
    //         00555476     ADD        ESP,0x1c
    //         00555479     TEST       EAX,EAX
    //         0055547b     JZ         LAB_005554a7
    //         0055547d     MOV        EAX,dword ptr [ESP + local_8]
    //         00555481     MOV        ECX,dword ptr [ESP + local_8+0x1]
    //         00555485     AND        EAX,0xff
    //         0055548a     AND        ECX,0xff
    //         00555490     SHL        EAX,0x8
    //         00555493     ADD        EAX,ECX
    //         00555495     POP        EBX
    //         00555496     ADD        ESP,0x8
    //         00555499     RET
    //                               LAB_0055549a                                                 XREF[1]:     0055542e(j)  
    //         0055549a     CMP        EBX,0x61
    //         0055549d     JL         LAB_005554a7
    //         0055549f     CMP        EBX,0x7a
    //         005554a2     LEA        EAX,[EBX + -0x20]
    //         005554a5     JLE        LAB_005554a9
    //                               LAB_005554a7                                                 XREF[3]:     0055544e(j), 0055547b(j), 
    //                                                                                                         0055549d(j)  
    //         005554a7     MOV        EAX,EBX
    //                               LAB_005554a9                                                 XREF[1]:     005554a5(j)  
    //         005554a9     POP        EBX
    //         005554aa     ADD        ESP,0x8
    //         005554ad     RET
}

// Offset: 0x005554B0
undefined mbsnbcpy() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined __mbsnbcpy()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               __mbsnbcpy                                                   XREF[5]:     __splitpath:0054e5e4(c), 
    //                                                                                                         __splitpath:0054e66a(c), 
    //                                                                                                         __splitpath:0054e6ae(c), 
    //                                                                                                         __splitpath:0054e6d8(c), 
    //                                                                                                         __splitpath:0054e704(c)  
    //         005554b0     MOV        EAX,[___mbcodepage]
    //         005554b5     PUSH       ESI
    //         005554b6     PUSH       EDI
    //         005554b7     MOV        EDI,dword ptr [ESP + Stack[0x4]]
    //         005554bb     TEST       EAX,EAX
    //         005554bd     MOV        ESI,EDI
    //         005554bf     JNZ        LAB_005554d7
    //         005554c1     MOV        EAX,dword ptr [ESP + Stack[0xc]]
    //         005554c5     MOV        ECX,dword ptr [ESP + Stack[0x8]]
    //         005554c9     PUSH       EAX
    //         005554ca     PUSH       ECX
    //         005554cb     PUSH       EDI
    //         005554cc     CALL       strncpy                                          undefined strncpy()
    //         005554d1     ADD        ESP,0xc
    //         005554d4     POP        EDI
    //         005554d5     POP        ESI
    //         005554d6     RET
    //                               LAB_005554d7                                                 XREF[1]:     005554bf(j)  
    //         005554d7     MOV        EDX,dword ptr [ESP + Stack[0xc]]
    //         005554db     PUSH       EBP
    //         005554dc     TEST       EDX,EDX
    //         005554de     JZ         LAB_00555523
    //         005554e0     MOV        EAX,dword ptr [ESP + Stack[0x8]]
    //                               LAB_005554e4                                                 XREF[1]:     00555515(j)  
    //         005554e4     MOV        CL,byte ptr [EAX]
    //         005554e6     DEC        EDX
    //         005554e7     MOV        EBP,ECX
    //         005554e9     AND        EBP,0xff
    //         005554ef     TEST       byte ptr [EBP + __mbctype+1],0x4
    //         005554f6     MOV        byte ptr [EDI],CL
    //         005554f8     JZ         LAB_0055550d
    //         005554fa     INC        EDI
    //         005554fb     INC        EAX
    //         005554fc     TEST       EDX,EDX
    //         005554fe     JZ         LAB_00555519
    //         00555500     MOV        CL,byte ptr [EAX]
    //         00555502     DEC        EDX
    //         00555503     MOV        byte ptr [EDI],CL
    //         00555505     INC        EDI
    //         00555506     INC        EAX
    //         00555507     TEST       CL,CL
    //         00555509     JZ         LAB_0055551f
    //         0055550b     JMP        LAB_00555513
    //                               LAB_0055550d                                                 XREF[1]:     005554f8(j)  
    //         0055550d     INC        EDI
    //         0055550e     INC        EAX
    //         0055550f     TEST       CL,CL
    //         00555511     JZ         LAB_00555523
    //                               LAB_00555513                                                 XREF[1]:     0055550b(j)  
    //         00555513     TEST       EDX,EDX
    //         00555515     JNZ        LAB_005554e4
    //         00555517     JMP        LAB_00555523
    //                               LAB_00555519                                                 XREF[1]:     005554fe(j)  
    //         00555519     MOV        byte ptr [EDI + -0x1],0x0
    //         0055551d     JMP        LAB_00555523
    //                               LAB_0055551f                                                 XREF[1]:     00555509(j)  
    //         0055551f     MOV        byte ptr [EDI + -0x2],0x0
    //                               LAB_00555523                                                 XREF[4]:     005554de(j), 00555511(j), 
    //                                                                                                         00555517(j), 0055551d(j)  
    //         00555523     MOV        EAX,EDX
    //         00555525     DEC        EDX
    //         00555526     TEST       EAX,EAX
    //         00555528     JZ         LAB_0055553d
    //         0055552a     LEA        ECX,[EDX + 0x1]
    //         0055552d     XOR        EAX,EAX
    //         0055552f     MOV        EDX,ECX
    //         00555531     SHR        ECX,0x2
    //         00555534     STOSD.REP  ES:EDI
    //         00555536     MOV        ECX,EDX
    //         00555538     AND        ECX,0x3
    //         0055553b     STOSB.REP  ES:EDI
    //                               LAB_0055553d                                                 XREF[1]:     00555528(j)  
    //         0055553d     POP        EBP
    //         0055553e     MOV        EAX,ESI
    //         00555540     POP        EDI
    //         00555541     POP        ESI
    //         00555542     RET
}

// Offset: 0x00555550
undefined frnd() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined __frnd()
    //              undefined         <UNASSIGNED>   <RETURN>
    //              undefined8        Stack[-0xc]:8  local_c                   XREF[2]:     0055555b(W), 0055555e(R)  
    //                               __frnd                                                       XREF[2]:     floor:0054e960(c), 
    //                                                                                                         ceil:0054f4f0(c)  
    //         00555550     PUSH       EBP
    //         00555551     MOV        EBP,ESP
    //         00555553     SUB        ESP,0x8
    //         00555556     FLD        double ptr [EBP + Stack[0x4]]
    //         00555559     FRNDINT
    //         0055555b     FSTP       double ptr [EBP + local_c]
    //         0055555e     FLD        double ptr [EBP + local_c]
    //         00555561     MOV        ESP,EBP
    //         00555563     POP        EBP
    //         00555564     RET
}

// Offset: 0x00555570
undefined handle_qnan1() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined __handle_qnan1()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               __handle_qnan1                                               XREF[2]:     floor:0054e912(c), 
    //                                                                                                         ceil:0054f4a2(c)  
    //         00555570     MOV        EAX,[__matherr_flag]                             = 00002694h
    //         00555575     TEST       EAX,EAX
    //         00555577     JNZ        LAB_0055559e
    //         00555579     MOV        EAX,dword ptr [ESP + Stack[0x10]]
    //         0055557d     MOV        ECX,dword ptr [ESP + Stack[0x8]]
    //         00555581     PUSH       EAX
    //         00555582     MOV        EAX,dword ptr [ESP + Stack[0xc]]
    //         00555586     PUSH       EAX
    //         00555587     PUSH       ECX
    //         00555588     PUSH       0x0
    //         0055558a     PUSH       0x0
    //         0055558c     PUSH       EAX
    //         0055558d     PUSH       ECX
    //         0055558e     MOV        ECX,dword ptr [ESP + Stack[0x4]]
    //         00555592     PUSH       ECX
    //         00555593     PUSH       0x1
    //         00555595     CALL       __umatherr                                       undefined __umatherr()
    //         0055559a     ADD        ESP,0x24
    //         0055559d     RET
    //                               LAB_0055559e                                                 XREF[1]:     00555577(j)  
    //         0055559e     MOV        EDX,dword ptr [ESP + Stack[0x10]]
    //         005555a2     PUSH       0xffff
    //         005555a7     PUSH       EDX
    //         005555a8     MOV        dword ptr [_errno],0x21                          = align(4)
    //         005555b2     CALL       __ctrlfp                                         undefined __ctrlfp()
    //         005555b7     FLD        double ptr [ESP + Stack[0x8]]
    //         005555bb     ADD        ESP,0x8
    //         005555be     RET
}

// Offset: 0x005555BF
undefined FUN_005555bf() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_005555bf()
    //              undefined         <UNASSIGNED>   <RETURN>
    //              undefined8        Stack[-0x8]:8  local_8                   XREF[3,1]:   005555d2(*), 005555e0(*), 00555627(R), 005555dc(R)  
    //                               FUN_005555bf
    //         005555bf     NOP
    //                               __handle_qnan2
    //         005555c0     SUB        ESP,0x8
    //         005555c3     FLD        double ptr [ESP + Stack[0x10]]
    //         005555c7     FADD       double ptr [ESP + Stack[0x8]]
    //         005555cb     MOV        EAX,[__matherr_flag]                             = 00002694h
    //         005555d0     TEST       EAX,EAX
    //         005555d2     FSTP       double ptr [ESP]=>local_8
    //         005555d6     JNZ        LAB_0055560e
    //         005555d8     MOV        EAX,dword ptr [ESP + Stack[0x18]]
    //         005555dc     MOV        ECX,dword ptr [ESP + local_8+0x4]
    //         005555e0     MOV        EDX,dword ptr [ESP]=>local_8
    //         005555e4     PUSH       EAX
    //         005555e5     MOV        EAX,dword ptr [ESP + Stack[0x14]]
    //         005555e9     PUSH       ECX
    //         005555ea     MOV        ECX,dword ptr [ESP + Stack[0x10]]
    //         005555ee     PUSH       EDX
    //         005555ef     MOV        EDX,dword ptr [ESP + Stack[0xc]]
    //         005555f3     PUSH       EAX
    //         005555f4     MOV        EAX,dword ptr [ESP + Stack[0x8]]
    //         005555f8     PUSH       ECX
    //         005555f9     MOV        ECX,dword ptr [ESP + Stack[0x4]]
    //         005555fd     PUSH       EDX
    //         005555fe     PUSH       EAX
    //         005555ff     PUSH       ECX
    //         00555600     PUSH       0x1
    //         00555602     CALL       __umatherr                                       undefined __umatherr()
    //         00555607     ADD        ESP,0x24
    //         0055560a     ADD        ESP,0x8
    //         0055560d     RET
    //                               LAB_0055560e                                                 XREF[1]:     005555d6(j)  
    //         0055560e     MOV        EDX,dword ptr [ESP + Stack[0x18]]
    //         00555612     PUSH       0xffff
    //         00555617     PUSH       EDX
    //         00555618     MOV        dword ptr [_errno],0x21                          = align(4)
    //         00555622     CALL       __ctrlfp                                         undefined __ctrlfp()
    //         00555627     FLD        double ptr [ESP + local_8]
    //         0055562b     ADD        ESP,0x8
    //         0055562e     ADD        ESP,0x8
    //         00555631     RET
}

// Offset: 0x00555640
undefined except1() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined __except1()
    //              undefined         <UNASSIGNED>   <RETURN>
    //              undefined4        Stack[-0x20]:4 local_20                  XREF[2]:     00555664(R), 00555674(W)  
    //              undefined         Stack[-0x58]:1 local_58                  XREF[1]:     00555682(*)  
    //                               __except1                                                    XREF[4]:     floor:0054e951(c), 
    //                                                                                                         floor:0054e9aa(c), 
    //                                                                                                         ceil:0054f4e1(c), 
    //                                                                                                         ceil:0054f53a(c)  
    //         00555640     MOV        EAX,dword ptr [ESP + Stack[0x1c]]
    //         00555644     SUB        ESP,0x58
    //         00555647     LEA        ECX=>Stack[0x14],[ESP + 0x6c]
    //         0055564b     PUSH       ESI
    //         0055564c     MOV        ESI,dword ptr [ESP + Stack[0x4]]
    //         00555650     PUSH       EDI
    //         00555651     PUSH       EAX
    //         00555652     PUSH       ECX
    //         00555653     PUSH       ESI
    //         00555654     CALL       __handle_exc                                     undefined __handle_exc()
    //         00555659     MOV        EDI,dword ptr [ESP + Stack[0x8]]
    //         0055565d     ADD        ESP,0xc
    //         00555660     TEST       EAX,EAX
    //         00555662     JNZ        LAB_00555690
    //         00555664     MOV        ECX,dword ptr [ESP + local_20]
    //         00555668     LEA        EDX=>Stack[0x14],[ESP + 0x74]
    //         0055566c     AND        ECX,0xfffffffe
    //         0055566f     LEA        EAX=>Stack[0xc],[ESP + 0x6c]
    //         00555673     PUSH       EDX
    //         00555674     MOV        dword ptr [ESP + local_20],ECX
    //         00555678     PUSH       EAX
    //         00555679     PUSH       EDI
    //         0055567a     LEA        ECX=>Stack[0x1c],[ESP + 0x88]
    //         00555681     PUSH       ESI
    //         00555682     LEA        EDX=>local_58,[ESP + 0x18]
    //         00555686     PUSH       ECX
    //         00555687     PUSH       EDX
    //         00555688     CALL       __raise_exc                                      undefined __raise_exc()
    //         0055568d     ADD        ESP,0x18
    //                               LAB_00555690                                                 XREF[1]:     00555662(j)  
    //         00555690     PUSH       ESI
    //         00555691     CALL       __errcode                                        undefined __errcode()
    //         00555696     MOV        ECX,dword ptr [__matherr_flag]                   = 00002694h
    //         0055569c     ADD        ESP,0x4
    //         0055569f     TEST       ECX,ECX
    //         005556a1     JNZ        LAB_005556d4
    //         005556a3     TEST       EAX,EAX
    //         005556a5     JZ         LAB_005556d4
    //         005556a7     MOV        ECX,dword ptr [ESP + Stack[0x1c]]
    //         005556ab     MOV        EDX,dword ptr [ESP + Stack[0x18]]
    //         005556af     PUSH       ECX
    //         005556b0     MOV        ECX,dword ptr [ESP + Stack[0x14]]
    //         005556b4     PUSH       EDX
    //         005556b5     MOV        EDX,dword ptr [ESP + Stack[0x10]]
    //         005556b9     PUSH       ECX
    //         005556ba     MOV        ECX,dword ptr [ESP + Stack[0xc]]
    //         005556be     PUSH       0x0
    //         005556c0     PUSH       0x0
    //         005556c2     PUSH       EDX
    //         005556c3     PUSH       ECX
    //         005556c4     PUSH       EDI
    //         005556c5     PUSH       EAX
    //         005556c6     CALL       __umatherr                                       undefined __umatherr()
    //         005556cb     ADD        ESP,0x24
    //         005556ce     POP        EDI
    //         005556cf     POP        ESI
    //         005556d0     ADD        ESP,0x58
    //         005556d3     RET
    //                               LAB_005556d4                                                 XREF[2]:     005556a1(j), 005556a5(j)  
    //         005556d4     PUSH       EAX
    //         005556d5     CALL       __set_errno                                      undefined __set_errno()
    //         005556da     MOV        EDX,dword ptr [ESP + Stack[0x1c]]
    //         005556e1     ADD        ESP,0x4
    //         005556e4     PUSH       0xffff
    //         005556e9     PUSH       EDX
    //         005556ea     CALL       __ctrlfp                                         undefined __ctrlfp()
    //         005556ef     FLD        double ptr [ESP + Stack[0x14]]
    //         005556f3     ADD        ESP,0x8
    //         005556f6     POP        EDI
    //         005556f7     POP        ESI
    //         005556f8     ADD        ESP,0x58
    //         005556fb     RET
}

// Offset: 0x005556FC
undefined FUN_005556fc() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_005556fc()
    //              undefined         <UNASSIGNED>   <RETURN>
    //              undefined4        Stack[-0x20]:4 local_20                  XREF[2]:     00555734(R), 00555751(W)  
    //              undefined4        Stack[-0x2c]:4 local_2c                  XREF[1]:     00555762(W)  
    //              undefined4        Stack[-0x30]:4 local_30                  XREF[1]:     0055575e(W)  
    //              undefined         Stack[-0x58]:1 local_58                  XREF[1]:     0055574d(*)  
    //                               FUN_005556fc
    //         005556fc     NOP
    //         005556fd     NOP
    //         005556fe     NOP
    //         005556ff     NOP
    //                               __except2
    //         00555700     MOV        EAX,dword ptr [ESP + Stack[0x24]]
    //         00555704     SUB        ESP,0x58
    //         00555707     LEA        ECX=>Stack[0x1c],[ESP + 0x74]
    //         0055570b     PUSH       EBX
    //         0055570c     PUSH       EBP
    //         0055570d     PUSH       ESI
    //         0055570e     MOV        ESI,dword ptr [ESP + Stack[0x4]]
    //         00555712     PUSH       EDI
    //         00555713     PUSH       EAX
    //         00555714     PUSH       ECX
    //         00555715     PUSH       ESI
    //         00555716     CALL       __handle_exc                                     undefined __handle_exc()
    //         0055571b     MOV        EDI,dword ptr [ESP + Stack[0x18]]
    //         00555722     MOV        EBX,dword ptr [ESP + Stack[0x14]]
    //         00555729     MOV        EBP,dword ptr [ESP + Stack[0x8]]
    //         0055572d     ADD        ESP,0xc
    //         00555730     TEST       EAX,EAX
    //         00555732     JNZ        LAB_0055576e
    //         00555734     MOV        EAX,dword ptr [ESP + local_20]
    //         00555738     LEA        EDX=>Stack[0x1c],[ESP + 0x84]
    //         0055573f     OR         AL,0x1
    //         00555741     PUSH       EDX
    //         00555742     AND        AL,0xe3
    //         00555744     LEA        ECX=>Stack[0x24],[ESP + 0x90]
    //         0055574b     OR         AL,0x2
    //         0055574d     LEA        EDX=>local_58,[ESP + 0x14]
    //         00555751     MOV        dword ptr [ESP + local_20],EAX
    //         00555755     LEA        EAX=>Stack[0xc],[ESP + 0x78]
    //         00555759     PUSH       EAX
    //         0055575a     PUSH       EBP
    //         0055575b     PUSH       ESI
    //         0055575c     PUSH       ECX
    //         0055575d     PUSH       EDX
    //         0055575e     MOV        dword ptr [ESP + local_30],EBX
    //         00555762     MOV        dword ptr [ESP + local_2c],EDI
    //         00555766     CALL       __raise_exc                                      undefined __raise_exc()
    //         0055576b     ADD        ESP,0x18
    //                               LAB_0055576e                                                 XREF[1]:     00555732(j)  
    //         0055576e     PUSH       ESI
    //         0055576f     CALL       __errcode                                        undefined __errcode()
    //         00555774     MOV        ECX,dword ptr [__matherr_flag]                   = 00002694h
    //         0055577a     ADD        ESP,0x4
    //         0055577d     TEST       ECX,ECX
    //         0055577f     JNZ        LAB_005557c1
    //         00555781     TEST       EAX,EAX
    //         00555783     JZ         LAB_005557c1
    //         00555785     MOV        ECX,dword ptr [ESP + Stack[0x24]]
    //         0055578c     MOV        EDX,dword ptr [ESP + Stack[0x20]]
    //         00555793     PUSH       ECX
    //         00555794     MOV        ECX,dword ptr [ESP + Stack[0x1c]]
    //         0055579b     PUSH       EDX
    //         0055579c     MOV        EDX,dword ptr [ESP + Stack[0x10]]
    //         005557a3     PUSH       ECX
    //         005557a4     MOV        ECX,dword ptr [ESP + Stack[0xc]]
    //         005557ab     PUSH       EDI
    //         005557ac     PUSH       EBX
    //         005557ad     PUSH       EDX
    //         005557ae     PUSH       ECX
    //         005557af     PUSH       EBP
    //         005557b0     PUSH       EAX
    //         005557b1     CALL       __umatherr                                       undefined __umatherr()
    //         005557b6     ADD        ESP,0x24
    //         005557b9     POP        EDI
    //         005557ba     POP        ESI
    //         005557bb     POP        EBP
    //         005557bc     POP        EBX
    //         005557bd     ADD        ESP,0x58
    //         005557c0     RET
    //                               LAB_005557c1                                                 XREF[2]:     0055577f(j), 00555783(j)  
    //         005557c1     PUSH       EAX
    //         005557c2     CALL       __set_errno                                      undefined __set_errno()
    //         005557c7     MOV        EDX,dword ptr [ESP + Stack[0x24]]
    //         005557ce     ADD        ESP,0x4
    //         005557d1     PUSH       0xffff
    //         005557d6     PUSH       EDX
    //         005557d7     CALL       __ctrlfp                                         undefined __ctrlfp()
    //         005557dc     FLD        double ptr [ESP + Stack[0x1c]]
    //         005557e3     ADD        ESP,0x8
    //         005557e6     POP        EDI
    //         005557e7     POP        ESI
    //         005557e8     POP        EBP
    //         005557e9     POP        EBX
    //         005557ea     ADD        ESP,0x58
    //         005557ed     RET
}

// Offset: 0x005557F0
undefined raise_exc() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined __raise_exc()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               __raise_exc                                                  XREF[2]:     __except1:00555688(c), 
    //                                                                                                         FUN_005556fc:00555766(c)  
    //         005557f0     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         005557f4     PUSH       EBX
    //         005557f5     PUSH       EBP
    //         005557f6     PUSH       ESI
    //         005557f7     PUSH       EDI
    //         005557f8     XOR        EDI,EDI
    //         005557fa     MOV        dword ptr [EAX + 0x4],EDI
    //         005557fd     MOV        ECX,dword ptr [ESP + Stack[0x4]]
    //         00555801     MOV        AL,byte ptr [ESP + Stack[0xc]]
    //         00555805     MOV        EBX,0x1
    //         0055580a     MOV        dword ptr [ECX + 0x8],EDI
    //         0055580d     MOV        EDX,dword ptr [ESP + Stack[0x4]]
    //         00555811     TEST       AL,0x10
    //         00555813     MOV        dword ptr [EDX + 0xc],EDI
    //         00555816     JZ         LAB_00555826
    //         00555818     MOV        ECX,dword ptr [ESP + Stack[0x4]]
    //         0055581c     MOV        EBP,0xc000008f
    //         00555821     OR         dword ptr [ECX + 0x4],EBX
    //         00555824     JMP        LAB_0055582a
    //                               LAB_00555826                                                 XREF[1]:     00555816(j)  
    //         00555826     MOV        EBP,dword ptr [ESP + Stack[0x4]]
    //                               LAB_0055582a                                                 XREF[1]:     00555824(j)  
    //         0055582a     TEST       AL,0x2
    //         0055582c     JZ         LAB_0055583b
    //         0055582e     MOV        ECX,dword ptr [ESP + Stack[0x4]]
    //         00555832     MOV        EBP,0xc0000093
    //         00555837     OR         dword ptr [ECX + 0x4],0x2
    //                               LAB_0055583b                                                 XREF[1]:     0055582c(j)  
    //         0055583b     TEST       BL,AL
    //         0055583d     JZ         LAB_0055584c
    //         0055583f     MOV        ECX,dword ptr [ESP + Stack[0x4]]
    //         00555843     MOV        EBP,0xc0000091
    //         00555848     OR         dword ptr [ECX + 0x4],0x4
    //                               LAB_0055584c                                                 XREF[1]:     0055583d(j)  
    //         0055584c     TEST       AL,0x4
    //         0055584e     JZ         LAB_0055585d
    //         00555850     MOV        ECX,dword ptr [ESP + Stack[0x4]]
    //         00555854     MOV        EBP,0xc000008e
    //         00555859     OR         dword ptr [ECX + 0x4],0x8
    //                               LAB_0055585d                                                 XREF[1]:     0055584e(j)  
    //         0055585d     TEST       AL,0x8
    //         0055585f     JZ         LAB_0055586e
    //         00555861     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         00555865     MOV        EBP,0xc0000090
    //         0055586a     OR         dword ptr [EAX + 0x4],0x10
    //                               LAB_0055586e                                                 XREF[1]:     0055585f(j)  
    //         0055586e     MOV        ESI,dword ptr [ESP + Stack[0x8]]
    //         00555872     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         00555876     MOV        ECX,dword ptr [ESI]
    //         00555878     MOV        EDX,dword ptr [EAX + 0x8]
    //         0055587b     NOT        ECX
    //         0055587d     AND        ECX,EBX
    //         0055587f     AND        EDX,0xffffffef
    //         00555882     SHL        ECX,0x4
    //         00555885     OR         ECX,EDX
    //         00555887     MOV        dword ptr [EAX + 0x8],ECX
    //         0055588a     MOV        ECX,dword ptr [ESI]
    //         0055588c     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         00555890     NOT        ECX
    //         00555892     MOV        EDX,dword ptr [EAX + 0x8]
    //         00555895     AND        ECX,0x4
    //         00555898     SHL        ECX,0x1
    //         0055589a     AND        EDX,0xfffffff7
    //         0055589d     OR         ECX,EDX
    //         0055589f     MOV        dword ptr [EAX + 0x8],ECX
    //         005558a2     MOV        ECX,dword ptr [ESI]
    //         005558a4     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         005558a8     NOT        ECX
    //         005558aa     MOV        EDX,dword ptr [EAX + 0x8]
    //         005558ad     SHR        ECX,0x1
    //         005558af     AND        ECX,0x4
    //         005558b2     AND        EDX,0xfffffffb
    //         005558b5     OR         ECX,EDX
    //         005558b7     MOV        dword ptr [EAX + 0x8],ECX
    //         005558ba     MOV        ECX,dword ptr [ESI]
    //         005558bc     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         005558c0     NOT        ECX
    //         005558c2     MOV        EDX,dword ptr [EAX + 0x8]
    //         005558c5     SHR        ECX,0x3
    //         005558c8     AND        ECX,0x2
    //         005558cb     AND        EDX,0xfffffffd
    //         005558ce     OR         ECX,EDX
    //         005558d0     MOV        dword ptr [EAX + 0x8],ECX
    //         005558d3     MOV        ECX,dword ptr [ESI]
    //         005558d5     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         005558d9     NOT        ECX
    //         005558db     MOV        EDX,dword ptr [EAX + 0x8]
    //         005558de     SHR        ECX,0x5
    //         005558e1     AND        ECX,EBX
    //         005558e3     AND        EDX,0xfffffffe
    //         005558e6     OR         ECX,EDX
    //         005558e8     MOV        dword ptr [EAX + 0x8],ECX
    //         005558eb     CALL       __statfp                                         undefined __statfp()
    //         005558f0     TEST       BL,AL
    //         005558f2     JZ         LAB_005558fc
    //         005558f4     MOV        ECX,dword ptr [ESP + Stack[0x4]]
    //         005558f8     OR         dword ptr [ECX + 0xc],0x10
    //                               LAB_005558fc                                                 XREF[1]:     005558f2(j)  
    //         005558fc     TEST       AL,0x4
    //         005558fe     JZ         LAB_00555908
    //         00555900     MOV        ECX,dword ptr [ESP + Stack[0x4]]
    //         00555904     OR         dword ptr [ECX + 0xc],0x8
    //                               LAB_00555908                                                 XREF[1]:     005558fe(j)  
    //         00555908     TEST       AL,0x8
    //         0055590a     JZ         LAB_00555914
    //         0055590c     MOV        ECX,dword ptr [ESP + Stack[0x4]]
    //         00555910     OR         dword ptr [ECX + 0xc],0x4
    //                               LAB_00555914                                                 XREF[1]:     0055590a(j)  
    //         00555914     TEST       AL,0x10
    //         00555916     JZ         LAB_00555920
    //         00555918     MOV        ECX,dword ptr [ESP + Stack[0x4]]
    //         0055591c     OR         dword ptr [ECX + 0xc],0x2
    //                               LAB_00555920                                                 XREF[1]:     00555916(j)  
    //         00555920     TEST       AL,0x20
    //         00555922     JZ         LAB_0055592b
    //         00555924     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         00555928     OR         dword ptr [EAX + 0xc],EBX
    //                               LAB_0055592b                                                 XREF[1]:     00555922(j)  
    //         0055592b     MOV        EAX,dword ptr [ESI]
    //         0055592d     AND        EAX,0xc00
    //         00555932     CMP        EAX,0x400
    //         00555937     JA         LAB_00555957
    //         00555939     JZ         LAB_00555948
    //         0055593b     CMP        EAX,EDI
    //         0055593d     JNZ        LAB_0055597c
    //         0055593f     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         00555943     AND        dword ptr [EAX],0xfffffffc
    //         00555946     JMP        LAB_0055597c
    //                               LAB_00555948                                                 XREF[1]:     00555939(j)  
    //         00555948     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         0055594c     MOV        ECX,dword ptr [EAX]
    //         0055594e     AND        ECX,0xfffffffd
    //         00555951     OR         ECX,EBX
    //         00555953     MOV        dword ptr [EAX],ECX
    //         00555955     JMP        LAB_0055597c
    //                               LAB_00555957                                                 XREF[1]:     00555937(j)  
    //         00555957     CMP        EAX,0x800
    //         0055595c     JZ         LAB_0055596e
    //         0055595e     CMP        EAX,0xc00
    //         00555963     JNZ        LAB_0055597c
    //         00555965     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         00555969     OR         dword ptr [EAX],0x3
    //         0055596c     JMP        LAB_0055597c
    //                               LAB_0055596e                                                 XREF[1]:     0055595c(j)  
    //         0055596e     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         00555972     MOV        EDX,dword ptr [EAX]
    //         00555974     AND        EDX,0xfffffffe
    //         00555977     OR         EDX,0x2
    //         0055597a     MOV        dword ptr [EAX],EDX
    //                               LAB_0055597c                                                 XREF[5]:     0055593d(j), 00555946(j), 
    //                                                                                                         00555955(j), 00555963(j), 
    //                                                                                                         0055596c(j)  
    //         0055597c     MOV        EAX,dword ptr [ESI]
    //         0055597e     AND        EAX,0x300
    //         00555983     JZ         LAB_005559ac
    //         00555985     CMP        EAX,0x200
    //         0055598a     JZ         LAB_0055599c
    //         0055598c     CMP        EAX,0x300
    //         00555991     JNZ        LAB_005559ba
    //         00555993     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         00555997     AND        dword ptr [EAX],0xffffffe3
    //         0055599a     JMP        LAB_005559ba
    //                               LAB_0055599c                                                 XREF[1]:     0055598a(j)  
    //         0055599c     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         005559a0     MOV        ECX,dword ptr [EAX]
    //         005559a2     AND        ECX,0xffffffe7
    //         005559a5     OR         ECX,0x4
    //         005559a8     MOV        dword ptr [EAX],ECX
    //         005559aa     JMP        LAB_005559ba
    //                               LAB_005559ac                                                 XREF[1]:     00555983(j)  
    //         005559ac     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         005559b0     MOV        EDX,dword ptr [EAX]
    //         005559b2     AND        EDX,0xffffffeb
    //         005559b5     OR         EDX,0x8
    //         005559b8     MOV        dword ptr [EAX],EDX
    //                               LAB_005559ba                                                 XREF[3]:     00555991(j), 0055599a(j), 
    //                                                                                                         005559aa(j)  
    //         005559ba     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         005559be     MOV        EDX,dword ptr [ESP + Stack[0x10]]
    //         005559c2     AND        EDX,0xfff
    //         005559c8     MOV        ECX,dword ptr [EAX]
    //         005559ca     AND        ECX,0xfffe001f
    //         005559d0     SHL        EDX,0x5
    //         005559d3     OR         ECX,EDX
    //         005559d5     MOV        dword ptr [EAX],ECX
    //         005559d7     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         005559db     MOV        ECX,dword ptr [EAX + 0x20]
    //         005559de     OR         ECX,EBX
    //         005559e0     MOV        dword ptr [EAX + 0x20],ECX
    //         005559e3     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         005559e7     MOV        ECX,dword ptr [EAX + 0x20]
    //         005559ea     AND        ECX,0xffffffe3
    //         005559ed     OR         ECX,0x2
    //         005559f0     MOV        dword ptr [EAX + 0x20],ECX
    //         005559f3     MOV        EAX,dword ptr [ESP + Stack[0x14]]
    //         005559f7     MOV        ECX,dword ptr [ESP + Stack[0x4]]
    //         005559fb     MOV        EDX,dword ptr [EAX]
    //         005559fd     MOV        dword ptr [ECX + 0x10],EDX
    //         00555a00     MOV        EDX,dword ptr [EAX + 0x4]
    //         00555a03     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         00555a07     MOV        dword ptr [EAX + 0x14],EDX
    //         00555a0a     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         00555a0e     MOV        EDI,dword ptr [EAX + 0x50]
    //         00555a11     OR         EDI,EBX
    //         00555a13     MOV        dword ptr [EAX + 0x50],EDI
    //         00555a16     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         00555a1a     MOV        EDI,dword ptr [ESP + Stack[0x18]]
    //         00555a1e     MOV        ECX,dword ptr [EAX + 0x50]
    //         00555a21     AND        ECX,0xffffffe3
    //         00555a24     OR         ECX,0x2
    //         00555a27     MOV        dword ptr [EAX + 0x50],ECX
    //         00555a2a     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         00555a2e     MOV        EDX,dword ptr [EDI]
    //         00555a30     MOV        dword ptr [EAX + 0x40],EDX
    //         00555a33     MOV        EDX,dword ptr [ESP + Stack[0x4]]
    //         00555a37     MOV        ECX,dword ptr [EDI + 0x4]
    //         00555a3a     MOV        dword ptr [EDX + 0x44],ECX
    //         00555a3d     CALL       __clrfp                                          undefined __clrfp()
    //         00555a42     LEA        EAX=>Stack[0x4],[ESP + 0x14]
    //         00555a46     PUSH       EAX
    //         00555a47     PUSH       EBX
    //         00555a48     PUSH       0x0
    //         00555a4a     PUSH       EBP
    //         00555a4b     CALL       dword ptr [->KERNEL32.DLL::RaiseException]       = 0048b930
    //         00555a51     MOV        EAX,dword ptr [ESP + 0x14]
    //         00555a55     TEST       byte ptr [EAX + 0x8],0x10
    //         00555a59     JZ         LAB_00555a5e
    //         00555a5b     AND        dword ptr [ESI],0xfffffffe
    //                               LAB_00555a5e                                                 XREF[1]:     00555a59(j)  
    //         00555a5e     TEST       byte ptr [EAX + 0x8],0x8
    //         00555a62     JZ         LAB_00555a67
    //         00555a64     AND        dword ptr [ESI],0xfffffffb
    //                               LAB_00555a67                                                 XREF[1]:     00555a62(j)  
    //         00555a67     TEST       byte ptr [EAX + 0x8],0x4
    //         00555a6b     JZ         LAB_00555a70
    //         00555a6d     AND        dword ptr [ESI],0xfffffff7
    //                               LAB_00555a70                                                 XREF[1]:     00555a6b(j)  
    //         00555a70     TEST       byte ptr [EAX + 0x8],0x2
    //         00555a74     JZ         LAB_00555a79
    //         00555a76     AND        dword ptr [ESI],0xffffffef
    //                               LAB_00555a79                                                 XREF[1]:     00555a74(j)  
    //         00555a79     TEST       byte ptr [EAX + 0x8],BL
    //         00555a7c     JZ         LAB_00555a81
    //         00555a7e     AND        dword ptr [ESI],0xffffffdf
    //                               LAB_00555a81                                                 XREF[1]:     00555a7c(j)  
    //         00555a81     MOV        ECX,dword ptr [EAX]
    //         00555a83     AND        ECX,0x3
    //         00555a86     CMP        ECX,0x3
    //         00555a89     JA         switchD_00555a8b::default
    //                               switchD_00555a8b::switchD
    //         00555a8b     JMP        dword ptr [ECX*0x4 + switchD_00555a8b::switchd   = 00555aaf
    //                               switchD_00555a8b::caseD_3                                    XREF[2]:     00555a8b(j), 00555b20(*)  
    //         00555a92     MOV        ECX,dword ptr [ESI]
    //         00555a94     OR         CH,0xc
    //         00555a97     JMP        LAB_00555ab4
    //                               switchD_00555a8b::caseD_2                                    XREF[2]:     00555a8b(j), 00555b1c(*)  
    //         00555a99     MOV        ECX,dword ptr [ESI]
    //         00555a9b     AND        CH,0xfb
    //         00555a9e     OR         CH,0x8
    //         00555aa1     JMP        LAB_00555ab4
    //                               switchD_00555a8b::caseD_1                                    XREF[2]:     00555a8b(j), 00555b18(*)  
    //         00555aa3     MOV        EDX,dword ptr [ESI]
    //         00555aa5     AND        DH,0xf7
    //         00555aa8     OR         DH,0x4
    //         00555aab     MOV        dword ptr [ESI],EDX
    //         00555aad     JMP        switchD_00555a8b::default
    //                               switchD_00555a8b::caseD_0                                    XREF[2]:     00555a8b(j), 00555b14(*)  
    //         00555aaf     MOV        ECX,dword ptr [ESI]
    //         00555ab1     AND        CH,0xf3
    //                               LAB_00555ab4                                                 XREF[2]:     00555a97(j), 00555aa1(j)  
    //         00555ab4     MOV        dword ptr [ESI],ECX
    //                               switchD_00555a8b::default                                    XREF[2]:     00555a89(j), 00555aad(j)  
    //         00555ab6     MOV        ECX,dword ptr [EAX]
    //         00555ab8     SHR        ECX,0x2
    //         00555abb     AND        ECX,0x7
    //         00555abe     SUB        ECX,0x0
    //         00555ac1     JZ         LAB_00555afa
    //         00555ac3     DEC        ECX
    //         00555ac4     JZ         LAB_00555ae0
    //         00555ac6     DEC        ECX
    //         00555ac7     JNZ        LAB_00555b04
    //         00555ac9     MOV        ECX,dword ptr [ESI]
    //         00555acb     AND        CH,0xf3
    //         00555ace     MOV        dword ptr [ESI],ECX
    //         00555ad0     MOV        ECX,dword ptr [EAX + 0x40]
    //         00555ad3     MOV        dword ptr [EDI],ECX
    //         00555ad5     MOV        EDX,dword ptr [EAX + 0x44]
    //         00555ad8     MOV        dword ptr [EDI + 0x4],EDX
    //         00555adb     POP        EDI
    //         00555adc     POP        ESI
    //         00555add     POP        EBP
    //         00555ade     POP        EBX
    //         00555adf     RET
    //                               LAB_00555ae0                                                 XREF[1]:     00555ac4(j)  
    //         00555ae0     MOV        ECX,dword ptr [ESI]
    //         00555ae2     AND        CH,0xf3
    //         00555ae5     OR         CH,0x2
    //         00555ae8     MOV        dword ptr [ESI],ECX
    //         00555aea     MOV        ECX,dword ptr [EAX + 0x40]
    //         00555aed     MOV        dword ptr [EDI],ECX
    //         00555aef     MOV        EDX,dword ptr [EAX + 0x44]
    //         00555af2     MOV        dword ptr [EDI + 0x4],EDX
    //         00555af5     POP        EDI
    //         00555af6     POP        ESI
    //         00555af7     POP        EBP
    //         00555af8     POP        EBX
    //         00555af9     RET
    //                               LAB_00555afa                                                 XREF[1]:     00555ac1(j)  
    //         00555afa     MOV        EDX,dword ptr [ESI]
    //         00555afc     AND        DH,0xf3
    //         00555aff     OR         DH,0x3
    //         00555b02     MOV        dword ptr [ESI],EDX
    //                               LAB_00555b04                                                 XREF[1]:     00555ac7(j)  
    //         00555b04     MOV        ECX,dword ptr [EAX + 0x40]
    //         00555b07     MOV        dword ptr [EDI],ECX
    //         00555b09     MOV        EDX,dword ptr [EAX + 0x44]
    //         00555b0c     MOV        dword ptr [EDI + 0x4],EDX
    //         00555b0f     POP        EDI
    //         00555b10     POP        ESI
    //         00555b11     POP        EBP
    //         00555b12     POP        EBX
    //         00555b13     RET
    //                               switchD_00555a8b::switchdataD_00555b14                       XREF[1]:     __raise_exc:00555a8b(*)  
}

// Offset: 0x00555B30
undefined handle_exc() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined __handle_exc()
    //              undefined         <UNASSIGNED>   <RETURN>
    //              undefined8        Stack[-0x10]:8 local_10                  XREF[20,12]: 00555bf8(W), 00555bfc(R), 00555c49(W), 00555c4d(R), 
    //                                                                                     00555cac(W), 00555cb0(R), 00555cfd(W), 00555d01(R), 
    //                                                                                     00555d3a(W), 00555d42(R), 00555d6a(W), 00555d86(W), 
    //                                                                                     00555d96(R), 00555dca(R), 00555dd6(R), 00555ddc(W), 
    //                                                                                     00555de8(RW), 00555e01(R), 00555e07(W), 00555e0b(R)  
    //              undefined4        Stack[-0x14]:4 local_14                  XREF[2]:     00555d57(*), 00555d63(R)  
    //              undefined4        Stack[-0x18]:4 local_18                  XREF[4]:     00555b46(W), 00555e2a(R), 00555e30(W), 00555e37(R)  
    //                               __handle_exc                                                 XREF[2]:     __except1:00555654(c), 
    //                                                                                                         FUN_005556fc:00555716(c)  
    //         00555b30     PUSH       EBP
    //         00555b31     MOV        EBP,ESP
    //         00555b33     AND        ESP,0xfffffff8
    //         00555b36     SUB        ESP,0x14
    //         00555b39     MOV        EAX,dword ptr [EBP + Stack[0x4]]
    //         00555b3c     PUSH       EBX
    //         00555b3d     PUSH       ESI
    //         00555b3e     MOV        ESI,EAX
    //         00555b40     AND        ESI,0x1f
    //         00555b43     PUSH       EDI
    //         00555b44     TEST       AL,0x8
    //         00555b46     MOV        dword ptr [ESP + local_18],ESI
    //         00555b4a     MOV        EBX,0x1
    //         00555b4f     JZ         LAB_00555b6a
    //         00555b51     TEST       byte ptr [EBP + Stack[0xc]],BL
    //         00555b54     JZ         LAB_00555b6a
    //         00555b56     PUSH       EBX
    //         00555b57     CALL       __set_statfp                                     undefined __set_statfp()
    //         00555b5c     MOV        EAX,dword ptr [EBP + Stack[0x4]]
    //         00555b5f     ADD        ESP,0x4
    //         00555b62     AND        ESI,0xfffffff7
    //         00555b65     JMP        LAB_00555e3b
    //                               LAB_00555b6a                                                 XREF[2]:     00555b4f(j), 00555b54(j)  
    //         00555b6a     MOV        CL,byte ptr [EBP + Stack[0xc]]
    //         00555b6d     TEST       AL,0x4
    //         00555b6f     JZ         LAB_00555b8b
    //         00555b71     TEST       CL,0x4
    //         00555b74     JZ         LAB_00555b8b
    //         00555b76     PUSH       0x4
    //         00555b78     CALL       __set_statfp                                     undefined __set_statfp()
    //         00555b7d     MOV        EAX,dword ptr [EBP + Stack[0x4]]
    //         00555b80     ADD        ESP,0x4
    //         00555b83     AND        ESI,0xfffffffb
    //         00555b86     JMP        LAB_00555e3b
    //                               LAB_00555b8b                                                 XREF[2]:     00555b6f(j), 00555b74(j)  
    //         00555b8b     TEST       BL,AL
    //         00555b8d     JZ         LAB_00555d19
    //         00555b93     TEST       CL,0x8
    //         00555b96     JZ         LAB_00555d19
    //         00555b9c     PUSH       0x8
    //         00555b9e     CALL       __set_statfp                                     undefined __set_statfp()
    //         00555ba3     MOV        EAX,dword ptr [EBP + Stack[0xc]]
    //         00555ba6     ADD        ESP,0x4
    //         00555ba9     AND        EAX,0xc00
    //         00555bae     CMP        EAX,0x400
    //         00555bb3     JA         LAB_00555c65
    //         00555bb9     JZ         LAB_00555c14
    //         00555bbb     TEST       EAX,EAX
    //         00555bbd     JNZ        LAB_00555d0e
    //         00555bc3     MOV        EDX,dword ptr [EBP + Stack[0x8]]
    //         00555bc6     FLD        double ptr [EDX]
    //         00555bc8     FCOMP      double ptr [DAT_00577cd8]                        = align(16)
    //         00555bce     FNSTSW     AX
    //         00555bd0     TEST       AH,0x41
    //         00555bd3     JNZ        LAB_00555bf0
    //         00555bd5     MOV        ECX,dword ptr [__d_inf]
    //         00555bdb     MOV        EAX,[DAT_00592534]                               = 7FF00000h
    //         00555be0     MOV        dword ptr [EDX],ECX
    //         00555be2     MOV        dword ptr [EDX + 0x4],EAX
    //         00555be5     MOV        EAX,dword ptr [EBP + Stack[0x4]]
    //         00555be8     AND        ESI,0xfffffffe
    //         00555beb     JMP        LAB_00555e3b
    //                               LAB_00555bf0                                                 XREF[1]:     00555bd3(j)  
    //         00555bf0     FLD        double ptr [__d_inf]
    //         00555bf6     FCHS
    //         00555bf8     FSTP       double ptr [ESP + local_10]
    //         00555bfc     MOV        ECX,dword ptr [ESP + local_10]
    //         00555c00     MOV        EAX,dword ptr [ESP + local_10+0x4]
    //         00555c04     MOV        dword ptr [EDX],ECX
    //         00555c06     MOV        dword ptr [EDX + 0x4],EAX
    //         00555c09     MOV        EAX,dword ptr [EBP + Stack[0x4]]
    //         00555c0c     AND        ESI,0xfffffffe
    //         00555c0f     JMP        LAB_00555e3b
    //                               LAB_00555c14                                                 XREF[1]:     00555bb9(j)  
    //         00555c14     MOV        EDX,dword ptr [EBP + Stack[0x8]]
    //         00555c17     FLD        double ptr [EDX]
    //         00555c19     FCOMP      double ptr [DAT_00577cd8]                        = align(16)
    //         00555c1f     FNSTSW     AX
    //         00555c21     TEST       AH,0x41
    //         00555c24     JNZ        LAB_00555c41
    //         00555c26     MOV        ECX,dword ptr [__d_max]                          = FFFFFFFFh
    //         00555c2c     MOV        EAX,[DAT_00592544]                               = 7FEFFFFFh
    //         00555c31     MOV        dword ptr [EDX],ECX
    //         00555c33     MOV        dword ptr [EDX + 0x4],EAX
    //         00555c36     MOV        EAX,dword ptr [EBP + Stack[0x4]]
    //         00555c39     AND        ESI,0xfffffffe
    //         00555c3c     JMP        LAB_00555e3b
    //                               LAB_00555c41                                                 XREF[1]:     00555c24(j)  
    //         00555c41     FLD        double ptr [__d_inf]
    //         00555c47     FCHS
    //         00555c49     FSTP       double ptr [ESP + local_10]
    //         00555c4d     MOV        ECX,dword ptr [ESP + local_10]
    //         00555c51     MOV        EAX,dword ptr [ESP + local_10+0x4]
    //         00555c55     MOV        dword ptr [EDX],ECX
    //         00555c57     MOV        dword ptr [EDX + 0x4],EAX
    //         00555c5a     MOV        EAX,dword ptr [EBP + Stack[0x4]]
    //         00555c5d     AND        ESI,0xfffffffe
    //         00555c60     JMP        LAB_00555e3b
    //                               LAB_00555c65                                                 XREF[1]:     00555bb3(j)  
    //         00555c65     CMP        EAX,0x800
    //         00555c6a     JZ         LAB_00555cc8
    //         00555c6c     CMP        EAX,0xc00
    //         00555c71     JNZ        LAB_00555d0e
    //         00555c77     MOV        EDX,dword ptr [EBP + Stack[0x8]]
    //         00555c7a     FLD        double ptr [EDX]
    //         00555c7c     FCOMP      double ptr [DAT_00577cd8]                        = align(16)
    //         00555c82     FNSTSW     AX
    //         00555c84     TEST       AH,0x41
    //         00555c87     JNZ        LAB_00555ca4
    //         00555c89     MOV        ECX,dword ptr [__d_max]                          = FFFFFFFFh
    //         00555c8f     MOV        EAX,[DAT_00592544]                               = 7FEFFFFFh
    //         00555c94     MOV        dword ptr [EDX],ECX
    //         00555c96     MOV        dword ptr [EDX + 0x4],EAX
    //         00555c99     MOV        EAX,dword ptr [EBP + Stack[0x4]]
    //         00555c9c     AND        ESI,0xfffffffe
    //         00555c9f     JMP        LAB_00555e3b
    //                               LAB_00555ca4                                                 XREF[1]:     00555c87(j)  
    //         00555ca4     FLD        double ptr [__d_max]                             = FFFFFFFFh
    //         00555caa     FCHS
    //         00555cac     FSTP       double ptr [ESP + local_10]
    //         00555cb0     MOV        ECX,dword ptr [ESP + local_10]
    //         00555cb4     MOV        EAX,dword ptr [ESP + local_10+0x4]
    //         00555cb8     MOV        dword ptr [EDX],ECX
    //         00555cba     MOV        dword ptr [EDX + 0x4],EAX
    //         00555cbd     MOV        EAX,dword ptr [EBP + Stack[0x4]]
    //         00555cc0     AND        ESI,0xfffffffe
    //         00555cc3     JMP        LAB_00555e3b
    //                               LAB_00555cc8                                                 XREF[1]:     00555c6a(j)  
    //         00555cc8     MOV        EDX,dword ptr [EBP + Stack[0x8]]
    //         00555ccb     FLD        double ptr [EDX]
    //         00555ccd     FCOMP      double ptr [DAT_00577cd8]                        = align(16)
    //         00555cd3     FNSTSW     AX
    //         00555cd5     TEST       AH,0x41
    //         00555cd8     JNZ        LAB_00555cf5
    //         00555cda     MOV        ECX,dword ptr [__d_inf]
    //         00555ce0     MOV        EAX,[DAT_00592534]                               = 7FF00000h
    //         00555ce5     MOV        dword ptr [EDX],ECX
    //         00555ce7     MOV        dword ptr [EDX + 0x4],EAX
    //         00555cea     MOV        EAX,dword ptr [EBP + Stack[0x4]]
    //         00555ced     AND        ESI,0xfffffffe
    //         00555cf0     JMP        LAB_00555e3b
    //                               LAB_00555cf5                                                 XREF[1]:     00555cd8(j)  
    //         00555cf5     FLD        double ptr [__d_max]                             = FFFFFFFFh
    //         00555cfb     FCHS
    //         00555cfd     FSTP       double ptr [ESP + local_10]
    //         00555d01     MOV        ECX,dword ptr [ESP + local_10]
    //         00555d05     MOV        EAX,dword ptr [ESP + local_10+0x4]
    //         00555d09     MOV        dword ptr [EDX],ECX
    //         00555d0b     MOV        dword ptr [EDX + 0x4],EAX
    //                               LAB_00555d0e                                                 XREF[2]:     00555bbd(j), 00555c71(j)  
    //         00555d0e     MOV        EAX,dword ptr [EBP + Stack[0x4]]
    //         00555d11     AND        ESI,0xfffffffe
    //         00555d14     JMP        LAB_00555e3b
    //                               LAB_00555d19                                                 XREF[2]:     00555b8d(j), 00555b96(j)  
    //         00555d19     TEST       AL,0x2
    //         00555d1b     JZ         LAB_00555e3b
    //         00555d21     TEST       CL,0x10
    //         00555d24     JZ         LAB_00555e3b
    //         00555d2a     XOR        ESI,ESI
    //         00555d2c     TEST       AL,0x10
    //         00555d2e     JZ         LAB_00555d32
    //         00555d30     MOV        ESI,EBX
    //                               LAB_00555d32                                                 XREF[1]:     00555d2e(j)  
    //         00555d32     MOV        EDI,dword ptr [EBP + Stack[0x8]]
    //         00555d35     MOV        ECX,dword ptr [EDI]
    //         00555d37     MOV        EDX,dword ptr [EDI + 0x4]
    //         00555d3a     MOV        dword ptr [ESP + local_10],ECX
    //         00555d3e     MOV        dword ptr [ESP + local_10+0x4],EDX
    //         00555d42     FLD        double ptr [ESP + local_10]
    //         00555d46     FCOMP      double ptr [DAT_00577cd8]                        = align(16)
    //         00555d4c     FNSTSW     AX
    //         00555d4e     TEST       AH,0x40
    //         00555d51     JNZ        LAB_00555e1a
    //         00555d57     LEA        EAX=>local_14,[ESP + 0x14]
    //         00555d5b     PUSH       EAX
    //         00555d5c     PUSH       EDX
    //         00555d5d     PUSH       ECX
    //         00555d5e     CALL       __decomp                                         undefined __decomp()
    //         00555d63     MOV        ECX,dword ptr [ESP + local_14]
    //         00555d67     ADD        ESP,0xc
    //         00555d6a     FSTP       double ptr [ESP + local_10]
    //         00555d6e     ADD        ECX,0xfffffa00
    //         00555d74     CMP        ECX,0xfffffbce
    //         00555d7a     JGE        LAB_00555d96
    //         00555d7c     XOR        EAX,EAX
    //         00555d7e     MOV        ESI,EBX
    //         00555d80     MOV        ECX,EAX
    //         00555d82     MOV        EDX,EAX
    //         00555d84     MOV        dword ptr [EDI],ECX
    //         00555d86     MOV        dword ptr [ESP + local_10],EAX
    //         00555d8a     MOV        dword ptr [ESP + local_10+0x4],EAX
    //         00555d8e     MOV        dword ptr [EDI + 0x4],EDX
    //         00555d91     JMP        LAB_00555e1c
    //                               LAB_00555d96                                                 XREF[1]:     00555d7a(j)  
    //         00555d96     FLD        double ptr [ESP + local_10]
    //         00555d9a     FCOMP      double ptr [DAT_00577cd8]                        = align(16)
    //         00555da0     FNSTSW     AX
    //         00555da2     TEST       AH,0x1
    //         00555da5     JZ         LAB_00555dab
    //         00555da7     MOV        EDX,EBX
    //         00555da9     JMP        LAB_00555dad
    //                               LAB_00555dab                                                 XREF[1]:     00555da5(j)  
    //         00555dab     XOR        EDX,EDX
    //                               LAB_00555dad                                                 XREF[1]:     00555da9(j)  
    //         00555dad     MOV        AL,byte ptr [ESP + local_10+0x6]
    //         00555db1     AND        EAX,0xf
    //         00555db4     OR         AL,0x10
    //         00555db6     CMP        ECX,0xfffffc03
    //         00555dbc     MOV        word ptr [ESP + local_10+0x6],AX
    //         00555dc1     JGE        LAB_00555dfd
    //         00555dc3     MOV        EAX,0xfffffc03
    //         00555dc8     SUB        EAX,ECX
    //                               LAB_00555dca                                                 XREF[1]:     00555dfb(j)  
    //         00555dca     TEST       byte ptr [ESP + local_10],BL
    //         00555dce     JZ         LAB_00555dd6
    //         00555dd0     TEST       ESI,ESI
    //         00555dd2     JNZ        LAB_00555dd6
    //         00555dd4     MOV        ESI,EBX
    //                               LAB_00555dd6                                                 XREF[2]:     00555dce(j), 00555dd2(j)  
    //         00555dd6     MOV        ECX,dword ptr [ESP + local_10]
    //         00555dda     SHR        ECX,0x1
    //         00555ddc     MOV        dword ptr [ESP + local_10],ECX
    //         00555de0     MOV        CL,byte ptr [ESP + local_10+0x4]
    //         00555de4     TEST       BL,CL
    //         00555de6     JZ         LAB_00555df0
    //         00555de8     OR         dword ptr [ESP + local_10],0x80000000
    //                               LAB_00555df0                                                 XREF[1]:     00555de6(j)  
    //         00555df0     MOV        ECX,dword ptr [ESP + local_10+0x4]
    //         00555df4     SHR        ECX,0x1
    //         00555df6     DEC        EAX
    //         00555df7     MOV        dword ptr [ESP + local_10+0x4],ECX
    //         00555dfb     JNZ        LAB_00555dca
    //                               LAB_00555dfd                                                 XREF[1]:     00555dc1(j)  
    //         00555dfd     TEST       EDX,EDX
    //         00555dff     JZ         LAB_00555e0b
    //         00555e01     FLD        double ptr [ESP + local_10]
    //         00555e05     FCHS
    //         00555e07     FSTP       double ptr [ESP + local_10]
    //                               LAB_00555e0b                                                 XREF[1]:     00555dff(j)  
    //         00555e0b     MOV        ECX,dword ptr [ESP + local_10]
    //         00555e0f     MOV        EDX,dword ptr [ESP + local_10+0x4]
    //         00555e13     MOV        dword ptr [EDI],ECX
    //         00555e15     MOV        dword ptr [EDI + 0x4],EDX
    //         00555e18     JMP        LAB_00555e1c
    //                               LAB_00555e1a                                                 XREF[1]:     00555d51(j)  
    //         00555e1a     MOV        ESI,EBX
    //                               LAB_00555e1c                                                 XREF[2]:     00555d91(j), 00555e18(j)  
    //         00555e1c     TEST       ESI,ESI
    //         00555e1e     JZ         LAB_00555e2a
    //         00555e20     PUSH       0x10
    //         00555e22     CALL       __set_statfp                                     undefined __set_statfp()
    //         00555e27     ADD        ESP,0x4
    //                               LAB_00555e2a                                                 XREF[1]:     00555e1e(j)  
    //         00555e2a     MOV        EAX,dword ptr [ESP + local_18]
    //         00555e2e     AND        AL,0xfd
    //         00555e30     MOV        dword ptr [ESP + local_18],EAX
    //         00555e34     MOV        EAX,dword ptr [EBP + Stack[0x4]]
    //         00555e37     MOV        ESI,dword ptr [ESP + local_18]
    //                               LAB_00555e3b                                                 XREF[12]:    00555b65(j), 00555b86(j), 
    //                                                                                                         00555beb(j), 00555c0f(j), 
    //                                                                                                         00555c3c(j), 00555c60(j), 
    //                                                                                                         00555c9f(j), 00555cc3(j), 
    //                                                                                                         00555cf0(j), 00555d14(j), 
    //                                                                                                         00555d1b(j), 00555d24(j)  
    //         00555e3b     TEST       AL,0x10
    //         00555e3d     JZ         LAB_00555e52
    //         00555e3f     TEST       byte ptr [EBP + Stack[0xc]],0x20
    //         00555e43     JZ         LAB_00555e52
    //         00555e45     PUSH       0x20
    //         00555e47     CALL       __set_statfp                                     undefined __set_statfp()
    //         00555e4c     ADD        ESP,0x4
    //         00555e4f     AND        ESI,0xffffffef
    //                               LAB_00555e52                                                 XREF[2]:     00555e3d(j), 00555e43(j)  
    //         00555e52     XOR        EAX,EAX
    //         00555e54     POP        EDI
    //         00555e55     TEST       ESI,ESI
    //         00555e57     POP        ESI
    //         00555e58     POP        EBX
    //         00555e59     SETZ       AL
    //         00555e5c     MOV        ESP,EBP
    //         00555e5e     POP        EBP
    //         00555e5f     RET
}

// Offset: 0x00555E60
undefined umatherr() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined __umatherr()
    //              undefined         <UNASSIGNED>   <RETURN>
    //              undefined8        Stack[-0x8]:8  local_8                   XREF[2,1]:   00555eb3(W), 00555edd(R), 00555eb7(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     00555e91(W)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     00555ea1(W)  
    //              undefined4        Stack[-0x14]:4 local_14                  XREF[1]:     00555e99(W)  
    //              undefined4        Stack[-0x18]:4 local_18                  XREF[1]:     00555e84(W)  
    //              undefined4        Stack[-0x1c]:4 local_1c                  XREF[1]:     00555e70(W)  
    //              undefined4        Stack[-0x20]:4 local_20                  XREF[2]:     00555eaf(W), 00555ec3(*)  
    //                               __umatherr                                                   XREF[4]:     __handle_qnan1:00555595(c), 
    //                                                                                                         FUN_005555bf:00555602(c), 
    //                                                                                                         __except1:005556c6(c), 
    //                                                                                                         FUN_005556fc:005557b1(c)  
    //         00555e60     SUB        ESP,0x20
    //         00555e63     MOV        EAX,dword ptr [ESP + Stack[0x8]]
    //         00555e67     PUSH       EAX
    //         00555e68     CALL       FUN_00555f40                                     undefined FUN_00555f40()
    //         00555e6d     ADD        ESP,0x4
    //         00555e70     MOV        dword ptr [ESP + local_1c],EAX
    //         00555e74     TEST       EAX,EAX
    //         00555e76     JZ         LAB_00555ee6
    //         00555e78     MOV        ECX,dword ptr [ESP + Stack[0xc]]
    //         00555e7c     MOV        EDX,dword ptr [ESP + Stack[0x10]]
    //         00555e80     MOV        EAX,dword ptr [ESP + Stack[0x14]]
    //         00555e84     MOV        dword ptr [ESP + local_18],ECX
    //         00555e88     MOV        ECX,dword ptr [ESP + Stack[0x18]]
    //         00555e8c     PUSH       ESI
    //         00555e8d     MOV        ESI,dword ptr [ESP + Stack[0x4]]
    //         00555e91     MOV        dword ptr [ESP + local_c],ECX
    //         00555e95     MOV        ECX,dword ptr [ESP + Stack[0x24]]
    //         00555e99     MOV        dword ptr [ESP + local_14],EDX
    //         00555e9d     MOV        EDX,dword ptr [ESP + Stack[0x1c]]
    //         00555ea1     MOV        dword ptr [ESP + local_10],EAX
    //         00555ea5     MOV        EAX,dword ptr [ESP + Stack[0x20]]
    //         00555ea9     PUSH       0xffff
    //         00555eae     PUSH       ECX
    //         00555eaf     MOV        dword ptr [ESP + local_20],ESI
    //         00555eb3     MOV        dword ptr [ESP + local_8],EDX
    //         00555eb7     MOV        dword ptr [ESP + local_8+0x4],EAX
    //         00555ebb     CALL       __ctrlfp                                         undefined __ctrlfp()
    //         00555ec0     ADD        ESP,0x8
    //         00555ec3     LEA        EDX=>local_20,[ESP + 0x4]
    //         00555ec7     PUSH       EDX
    //         00555ec8     CALL       __matherr                                        undefined __matherr()
    //         00555ecd     ADD        ESP,0x4
    //         00555ed0     TEST       EAX,EAX
    //         00555ed2     JNZ        LAB_00555edd
    //         00555ed4     PUSH       ESI
    //         00555ed5     CALL       __set_errno                                      undefined __set_errno()
    //         00555eda     ADD        ESP,0x4
    //                               LAB_00555edd                                                 XREF[1]:     00555ed2(j)  
    //         00555edd     FLD        double ptr [ESP + local_8]
    //         00555ee1     POP        ESI
    //         00555ee2     ADD        ESP,0x20
    //         00555ee5     RET
    //                               LAB_00555ee6                                                 XREF[1]:     00555e76(j)  
    //         00555ee6     MOV        EAX,dword ptr [ESP + Stack[0x24]]
    //         00555eea     PUSH       0xffff
    //         00555eef     PUSH       EAX
    //         00555ef0     CALL       __ctrlfp                                         undefined __ctrlfp()
    //         00555ef5     MOV        ECX,dword ptr [ESP + Stack[0x4]]
    //         00555ef9     ADD        ESP,0x8
    //         00555efc     PUSH       ECX
    //         00555efd     CALL       __set_errno                                      undefined __set_errno()
    //         00555f02     FLD        double ptr [ESP + Stack[0x1c]]
    //         00555f06     ADD        ESP,0x4
    //         00555f09     ADD        ESP,0x20
    //         00555f0c     RET
}

// Offset: 0x00555F10
undefined set_errno() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined __set_errno()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               __set_errno                                                  XREF[4]:     __except1:005556d5(c), 
    //                                                                                                         FUN_005556fc:005557c2(c), 
    //                                                                                                         __umatherr:00555ed5(c), 
    //                                                                                                         __umatherr:00555efd(c)  
    //         00555f10     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         00555f14     CMP        EAX,0x1
    //         00555f17     JZ         LAB_00555f2b
    //         00555f19     JLE        LAB_00555f35
    //         00555f1b     CMP        EAX,0x3
    //         00555f1e     JG         LAB_00555f35
    //         00555f20     MOV        dword ptr [_errno],0x22                          = align(4)
    //         00555f2a     RET
    //                               LAB_00555f2b                                                 XREF[1]:     00555f17(j)  
    //         00555f2b     MOV        dword ptr [_errno],0x21                          = align(4)
    //                               LAB_00555f35                                                 XREF[2]:     00555f19(j), 00555f1e(j)  
    //         00555f35     RET
}

// Offset: 0x00555F40
undefined FUN_00555f40() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00555f40()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00555f40                                                 XREF[1]:     __umatherr:00555e68(c)  
    //         00555f40     MOV        EDX,dword ptr [ESP + Stack[0x4]]
    //         00555f44     XOR        ECX,ECX
    //         00555f46     MOV        EAX,DAT_00592458                                 = 00000014h
    //                               LAB_00555f4b                                                 XREF[1]:     00555f58(j)  
    //         00555f4b     CMP        dword ptr [EAX]=>DAT_00592458,EDX                = 00000014h
    //                                                                                  = 0000001Dh
    //         00555f4d     JZ         LAB_00555f5d
    //         00555f4f     ADD        EAX,0x8
    //         00555f52     INC        ECX
    //         00555f53     CMP        EAX,__d_inf
    //         00555f58     JL         LAB_00555f4b
    //         00555f5a     XOR        EAX,EAX
    //         00555f5c     RET
    //                               LAB_00555f5d                                                 XREF[1]:     00555f4d(j)  
    //         00555f5d     MOV        EAX=>s_pow,dword ptr [ECX*0x8 + 0x59245c]=>->s   = "pow"
    //                                                                                  = 00577cd0
    //         00555f64     RET
}

// Offset: 0x00555F70
undefined errcode() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined __errcode()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               __errcode                                                    XREF[2]:     __except1:00555691(c), 
    //                                                                                                         FUN_005556fc:0055576f(c)  
    //         00555f70     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         00555f74     TEST       AL,0x20
    //         00555f76     JZ         LAB_00555f7e
    //         00555f78     MOV        EAX,0x5
    //         00555f7d     RET
    //                               LAB_00555f7e                                                 XREF[1]:     00555f76(j)  
    //         00555f7e     TEST       AL,0x8
    //         00555f80     JZ         LAB_00555f88
    //         00555f82     MOV        EAX,0x1
    //         00555f87     RET
    //                               LAB_00555f88                                                 XREF[1]:     00555f80(j)  
    //         00555f88     TEST       AL,0x4
    //         00555f8a     JZ         LAB_00555f92
    //         00555f8c     MOV        EAX,0x2
    //         00555f91     RET
    //                               LAB_00555f92                                                 XREF[1]:     00555f8a(j)  
    //         00555f92     TEST       AL,0x1
    //         00555f94     JZ         LAB_00555f9c
    //         00555f96     MOV        EAX,0x3
    //         00555f9b     RET
    //                               LAB_00555f9c                                                 XREF[1]:     00555f94(j)  
    //         00555f9c     AND        EAX,0xff
    //         00555fa1     AND        EAX,0x2
    //         00555fa4     SHL        EAX,0x1
    //         00555fa6     RET
}

// Offset: 0x00555FB0
undefined set_exp() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined __set_exp()
    //              undefined         <UNASSIGNED>   <RETURN>
    //              undefined8        Stack[-0x8]:8  local_8                   XREF[2,2]:   00555fbf(*), 00555fe1(*), 00555fc3(W), 00555fdc(W)  
    //                               __set_exp                                                    XREF[3]:     FUN_00556005:00556032(c), 
    //                                                                                                         __decomp:00556199(c), 
    //                                                                                                         __decomp:005561b7(c)  
    //         00555fb0     SUB        ESP,0x8
    //         00555fb3     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         00555fb7     MOV        ECX,dword ptr [ESP + Stack[0x8]]
    //         00555fbb     MOV        EDX,dword ptr [ESP + Stack[0xc]]
    //         00555fbf     MOV        dword ptr [ESP]=>local_8,EAX
    //         00555fc3     MOV        dword ptr [ESP + local_8+0x4],ECX
    //         00555fc7     MOV        ECX,dword ptr [ESP + Stack[0xa]]
    //         00555fcb     LEA        EAX,[EDX + 0x3fe]
    //         00555fd1     AND        ECX,0x800f
    //         00555fd7     SHL        EAX,0x4
    //         00555fda     OR         ECX,EAX
    //         00555fdc     MOV        word ptr [ESP + local_8+0x6],CX
    //         00555fe1     FLD        double ptr [ESP]=>local_8
    //         00555fe5     ADD        ESP,0x8
    //         00555fe8     RET
}

// Offset: 0x00555FE9
undefined FUN_00555fe9() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00555fe9()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00555fe9
    //         00555fe9     NOP
    //         00555fea     NOP
    //         00555feb     NOP
    //         00555fec     NOP
    //         00555fed     NOP
    //         00555fee     NOP
    //         00555fef     NOP
    //                               __get_exp
    //         00555ff0     MOV        EAX,dword ptr [ESP + Stack[0xa]]
    //         00555ff4     SHR        EAX,0x4
    //         00555ff7     AND        EAX,0x7ff
    //         00555ffc     SUB        EAX,0x3fe
    //         00556001     MOVSX      EAX,AX
    //         00556004     RET
}

