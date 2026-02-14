// Auto-generated scaffold unit: bucket_0554.asm
#include "../include/common.h"

// Offset: 0x005541C8
undefined FUN_005541c8() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_005541c8()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_005541c8
    //         005541c8     NOP
    //         005541c9     NOP
    //         005541ca     NOP
    //         005541cb     NOP
    //         005541cc     NOP
    //         005541cd     NOP
    //         005541ce     NOP
    //         005541cf     NOP
    //                               __ioterm
    //         005541d0     PUSH       ESI
    //         005541d1     MOV        ESI,___pioinfo
    //                               LAB_005541d6                                                 XREF[1]:     005541f4(j)  
    //         005541d6     MOV        EAX,dword ptr [ESI]=>___pioinfo
    //         005541d8     TEST       EAX,EAX
    //         005541da     JZ         LAB_005541eb
    //         005541dc     PUSH       EAX
    //         005541dd     CALL       free                                             undefined free()
    //         005541e2     ADD        ESP,0x4
    //         005541e5     MOV        dword ptr [ESI]=>___pioinfo,0x0
    //                               LAB_005541eb                                                 XREF[1]:     005541da(j)  
    //         005541eb     ADD        ESI,0x4
    //         005541ee     CMP        ESI,__nhandle
    //         005541f4     JL         LAB_005541d6
    //         005541f6     POP        ESI
    //         005541f7     RET
}

// Offset: 0x00554200
undefined isctype() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined __isctype()
    //              undefined         <UNASSIGNED>   <RETURN>
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     00554263(*), 00554281(R)  
    //                               __isctype                                                    XREF[36]:    atol:0054c668(c), 
    //                                                                                                         atol:0054c6b1(c), 
    //                                                                                                         __ismbcspace:0054c91c(c), 
    //                                                                                                         isupper:0054df50(c), 
    //                                                                                                         isspace:0054e010(c), 
    //                                                                                                         atof:0054e1f6(c), 
    //                                                                                                         toupper:0054e293(c), 
    //                                                                                                         tolower:0054e3a3(c), 
    //                                                                                                         __input:0055230e(c), 
    //                                                                                                         __input:005523ee(c), 
    //                                                                                                         __input:00552930(c), 
    //                                                                                                         __input:00552972(c), 
    //                                                                                                         __input:00552a7b(c), 
    //                                                                                                         __input:00552aba(c), 
    //                                                                                                         __input:00552c4a(c), 
    //                                                                                                         FUN_00553000:00553012(c), 
    //                                                                                                         ___strgtold12:00558a83(c), 
    //                                                                                                         ___strgtold12:00558b48(c), 
    //                                                                                                         ___strgtold12:00558be7(c), 
    //                                                                                                         ___strgtold12:00558cda(c), [more]
    //         00554200     PUSH       ECX
    //         00554201     MOV        ECX,dword ptr [ESP + Stack[0x4]]
    //         00554205     PUSH       ESI
    //         00554206     LEA        EAX,[ECX + 0x1]
    //         00554209     CMP        EAX,0x100
    //         0055420e     JA         LAB_00554225
    //         00554210     MOV        EDX,dword ptr [__pctype]                         = 005920da
    //         00554216     XOR        EAX,EAX
    //         00554218     MOV        AX,word ptr [EDX + ECX*0x2]=>DAT_005920da        = 20h     
    //         0055421c     MOV        ECX,dword ptr [ESP + Stack[0x8]]
    //         00554220     AND        EAX,ECX
    //         00554222     POP        ESI
    //         00554223     POP        ECX
    //         00554224     RET
    //                               LAB_00554225                                                 XREF[1]:     0055420e(j)  
    //         00554225     MOV        ESI,dword ptr [__pctype]                         = 005920da
    //         0055422b     MOV        EAX,ECX
    //         0055422d     SAR        EAX,0x8
    //         00554230     MOV        EDX,EAX
    //         00554232     AND        EDX,0xff
    //         00554238     TEST       byte ptr [ESI + EDX*0x2 + 0x1]=>DAT_005920db,0
    //         0055423d     JZ         LAB_00554253
    //         0055423f     MOV        byte ptr [ESP + Stack[0x4]],AL
    //         00554243     MOV        byte ptr [ESP + Stack[0x5]],CL
    //         00554247     MOV        byte ptr [ESP + Stack[0x6]],0x0
    //         0055424c     MOV        EAX,0x2
    //         00554251     JMP        LAB_00554261
    //                               LAB_00554253                                                 XREF[1]:     0055423d(j)  
    //         00554253     MOV        byte ptr [ESP + Stack[0x4]],CL
    //         00554257     MOV        byte ptr [ESP + Stack[0x5]],0x0
    //         0055425c     MOV        EAX,0x1
    //                               LAB_00554261                                                 XREF[1]:     00554251(j)  
    //         00554261     PUSH       0x0
    //         00554263     LEA        ECX=>local_4,[ESP + 0x8]
    //         00554267     PUSH       0x0
    //         00554269     PUSH       ECX
    //         0055426a     LEA        EDX=>Stack[0x4],[ESP + 0x18]
    //         0055426e     PUSH       EAX
    //         0055426f     PUSH       EDX
    //         00554270     PUSH       0x1
    //         00554272     CALL       ___crtGetStringTypeA                             undefined ___crtGetStringTypeA()
    //         00554277     ADD        ESP,0x18
    //         0055427a     TEST       EAX,EAX
    //         0055427c     JNZ        LAB_00554281
    //         0055427e     POP        ESI
    //         0055427f     POP        ECX
    //         00554280     RET
    //                               LAB_00554281                                                 XREF[1]:     0055427c(j)  
    //         00554281     MOV        EAX,dword ptr [ESP + local_4]
    //         00554285     MOV        ECX,dword ptr [ESP + Stack[0x8]]
    //         00554289     AND        EAX,0xffff
    //         0055428e     POP        ESI
    //         0055428f     AND        EAX,ECX
    //         00554291     POP        ECX
    //         00554292     RET
}

// Offset: 0x005542A0
undefined allmul() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined __allmul()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               __allmul                                                     XREF[2]:     __atoi64:0054c785(c), 
    //                                                                                                         __input:005529b2(c)  
    //         005542a0     MOV        EAX,dword ptr [ESP + Stack[0x8]]
    //         005542a4     MOV        ECX,dword ptr [ESP + Stack[0x10]]
    //         005542a8     OR         ECX,EAX
    //         005542aa     MOV        ECX,dword ptr [ESP + Stack[0xc]]
    //         005542ae     JNZ        LAB_005542b9
    //         005542b0     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         005542b4     MUL        ECX
    //         005542b6     RET        0x10
    //                               LAB_005542b9                                                 XREF[1]:     005542ae(j)  
    //         005542b9     PUSH       EBX
    //         005542ba     MUL        ECX
    //         005542bc     MOV        EBX,EAX
    //         005542be     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         005542c2     MUL        dword ptr [ESP + Stack[0x10]]
    //         005542c6     ADD        EBX,EAX
    //         005542c8     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         005542cc     MUL        ECX
    //         005542ce     ADD        EDX,EBX
    //         005542d0     POP        EBX
    //         005542d1     RET        0x10
}

// Offset: 0x005542E0
undefined mbsbtype() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined __mbsbtype()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               __mbsbtype                                                   XREF[1]:     __mbsncat:0054c873(c)  
    //         005542e0     MOV        EAX,[___mbcodepage]
    //         005542e5     PUSH       ESI
    //         005542e6     TEST       EAX,EAX
    //         005542e8     PUSH       EDI
    //         005542e9     JNZ        LAB_005542f0
    //         005542eb     XOR        EAX,EAX
    //         005542ed     POP        EDI
    //         005542ee     POP        ESI
    //         005542ef     RET
    //                               LAB_005542f0                                                 XREF[1]:     005542e9(j)  
    //         005542f0     MOV        ESI,dword ptr [ESP + Stack[0x4]]
    //         005542f4     OR         EAX,0xffffffff
    //         005542f7     MOV        CL,byte ptr [ESI]
    //         005542f9     TEST       CL,CL
    //         005542fb     JZ         LAB_00554319
    //         005542fd     MOV        EDI,dword ptr [ESP + Stack[0x8]]
    //                               LAB_00554301                                                 XREF[1]:     00554317(j)  
    //         00554301     PUSH       EAX
    //         00554302     PUSH       ECX
    //         00554303     INC        ESI
    //         00554304     CALL       __mbbtype                                        undefined __mbbtype()
    //         00554309     ADD        ESP,0x8
    //         0055430c     MOV        ECX,EDI
    //         0055430e     DEC        EDI
    //         0055430f     TEST       ECX,ECX
    //         00554311     JZ         LAB_0055431c
    //         00554313     MOV        CL,byte ptr [ESI]
    //         00554315     TEST       CL,CL
    //         00554317     JNZ        LAB_00554301
    //                               LAB_00554319                                                 XREF[1]:     005542fb(j)  
    //         00554319     OR         EAX,0xffffffff
    //                               LAB_0055431c                                                 XREF[1]:     00554311(j)  
    //         0055431c     POP        EDI
    //         0055431d     POP        ESI
    //         0055431e     RET
}

// Offset: 0x00554320
undefined setmbcp() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined __setmbcp()
    //              undefined         <UNASSIGNED>   <RETURN>
    //              undefined         Stack[-0x14]:1 local_14                  XREF[1]:     0055437c(*)  
    //                               __setmbcp                                                    XREF[1]:     ___initmbctable:00554602(c)  
    //         00554320     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         00554324     SUB        ESP,0x14
    //         00554327     PUSH       EBX
    //         00554328     PUSH       EBP
    //         00554329     PUSH       ESI
    //         0055432a     PUSH       EDI
    //         0055432b     PUSH       EAX
    //         0055432c     CALL       FUN_00554510                                     undefined FUN_00554510()
    //         00554331     MOV        EBP,EAX
    //         00554333     MOV        EAX,[___mbcodepage]
    //         00554338     ADD        ESP,0x4
    //         0055433b     CMP        EBP,EAX
    //         0055433d     MOV        dword ptr [ESP + Stack[0x4]],EBP
    //         00554341     JNZ        LAB_0055434d
    //         00554343     XOR        EAX,EAX
    //         00554345     POP        EDI
    //         00554346     POP        ESI
    //         00554347     POP        EBP
    //         00554348     POP        EBX
    //         00554349     ADD        ESP,0x14
    //         0055434c     RET
    //                               LAB_0055434d                                                 XREF[1]:     00554341(j)  
    //         0055434d     XOR        ESI,ESI
    //         0055434f     CMP        EBP,ESI
    //         00554351     JNZ        LAB_00554362
    //         00554353     CALL       FUN_005545c0                                     undefined FUN_005545c0()
    //         00554358     XOR        EAX,EAX
    //         0055435a     POP        EDI
    //         0055435b     POP        ESI
    //         0055435c     POP        EBP
    //         0055435d     POP        EBX
    //         0055435e     ADD        ESP,0x14
    //         00554361     RET
    //                               LAB_00554362                                                 XREF[1]:     00554351(j)  
    //         00554362     XOR        EDX,EDX
    //         00554364     MOV        EAX,DAT_005922f8                                 = 000003A4h
    //                               LAB_00554369                                                 XREF[1]:     0055437a(j)  
    //         00554369     CMP        dword ptr [EAX]=>DAT_005922f8,EBP                = 000003A4h
    //                                                                                  = 000003A8h
    //         0055436b     JZ         LAB_00554464
    //         00554371     ADD        EAX,0x30
    //         00554374     INC        EDX
    //         00554375     CMP        EAX,__lpdays                                     = FFh
    //         0055437a     JC         LAB_00554369
    //         0055437c     LEA        ECX=>local_14,[ESP + 0x10]
    //         00554380     PUSH       ECX
    //         00554381     PUSH       EBP
    //         00554382     CALL       dword ptr [->KERNEL32.DLL::GetCPInfo]            = 0048b87e
    //         00554388     CMP        EAX,0x1
    //         0055438b     JNZ        LAB_00554442
    //         00554391     MOV        ECX,0x40
    //         00554396     XOR        EAX,EAX
    //         00554398     MOV        EDI,__mbctype
    //         0055439d     STOSD.REP  ES:EDI=>__mbctype
    //         0055439f     STOSB      ES:EDI=>DAT_0088816c
    //         005543a0     CMP        dword ptr [ESP + 0x10],0x1
    //         005543a5     JBE        LAB_00554418
    //         005543a7     MOV        AL,byte ptr [ESP + 0x16]
    //         005543ab     TEST       AL,AL
    //         005543ad     JZ         LAB_005543e6
    //         005543af     LEA        EDX,[ESP + 0x17]
    //                               LAB_005543b3                                                 XREF[1]:     005543e4(j)  
    //         005543b3     MOV        CL,byte ptr [EDX]
    //         005543b5     TEST       CL,CL
    //         005543b7     JZ         LAB_005543e6
    //         005543b9     XOR        EAX,EAX
    //         005543bb     AND        ECX,0xff
    //         005543c1     MOV        AL,byte ptr [EDX + -0x1]
    //         005543c4     CMP        EAX,ECX
    //         005543c6     JA         LAB_005543dc
    //                               LAB_005543c8                                                 XREF[1]:     005543da(j)  
    //         005543c8     MOV        BL,byte ptr [EAX + __mbctype+1]
    //         005543ce     OR         BL,0x4
    //         005543d1     MOV        byte ptr [EAX + __mbctype+1],BL=>__mbctype+2
    //         005543d7     INC        EAX
    //         005543d8     CMP        EAX,ECX
    //         005543da     JBE        LAB_005543c8
    //                               LAB_005543dc                                                 XREF[1]:     005543c6(j)  
    //         005543dc     MOV        AL,byte ptr [EDX + 0x1]
    //         005543df     ADD        EDX,0x2
    //         005543e2     TEST       AL,AL
    //         005543e4     JNZ        LAB_005543b3
    //                               LAB_005543e6                                                 XREF[2]:     005543ad(j), 005543b7(j)  
    //         005543e6     MOV        EAX,0x1
    //                               LAB_005543eb                                                 XREF[1]:     00554400(j)  
    //         005543eb     MOV        BL,byte ptr [EAX + 0x888169]=>__mbctype+2
    //         005543f1     OR         BL,0x8
    //         005543f4     MOV        byte ptr [EAX + 0x888169]=>__mbctype+2,BL
    //         005543fa     INC        EAX
    //         005543fb     CMP        EAX,0xff
    //         00554400     JC         LAB_005543eb
    //         00554402     PUSH       EBP
    //         00554403     MOV        dword ptr [___mbcodepage],EBP
    //         00554409     CALL       FUN_00554560                                     undefined FUN_00554560()
    //         0055440e     ADD        ESP,0x4
    //         00554411     MOV        [___mblcid],EAX
    //         00554416     JMP        LAB_00554424
    //                               LAB_00554418                                                 XREF[1]:     005543a5(j)  
    //         00554418     MOV        dword ptr [___mbcodepage],ESI
    //         0055441e     MOV        dword ptr [___mblcid],ESI
    //                               LAB_00554424                                                 XREF[1]:     00554416(j)  
    //         00554424     XOR        EDX,EDX
    //         00554426     XOR        EAX,EAX
    //         00554428     MOV        dword ptr [___mbulinfo],EDX                      = align(12)
    //         0055442e     MOV        dword ptr [null_0088827c],EDX                    = align(8)
    //         00554434     MOV        dword ptr [null_00888280],EDX                    = align(4)
    //         0055443a     POP        EDI
    //         0055443b     POP        ESI
    //         0055443c     POP        EBP
    //         0055443d     POP        EBX
    //         0055443e     ADD        ESP,0x14
    //         00554441     RET
    //                               LAB_00554442                                                 XREF[1]:     0055438b(j)  
    //         00554442     CMP        dword ptr [DAT_00888284],ESI
    //         00554448     JZ         LAB_00554459
    //         0055444a     CALL       FUN_005545c0                                     undefined FUN_005545c0()
    //         0055444f     XOR        EAX,EAX
    //         00554451     POP        EDI
    //         00554452     POP        ESI
    //         00554453     POP        EBP
    //         00554454     POP        EBX
    //         00554455     ADD        ESP,0x14
    //         00554458     RET
    //                               LAB_00554459                                                 XREF[1]:     00554448(j)  
    //         00554459     OR         EAX,0xffffffff
    //         0055445c     POP        EDI
    //         0055445d     POP        ESI
    //         0055445e     POP        EBP
    //         0055445f     POP        EBX
    //         00554460     ADD        ESP,0x14
    //         00554463     RET
    //                               LAB_00554464                                                 XREF[1]:     0055436b(j)  
    //         00554464     MOV        ECX,0x40
    //         00554469     XOR        EAX,EAX
    //         0055446b     MOV        EDI,__mbctype
    //         00554470     LEA        EBX,[EDX + EDX*0x2]
    //         00554473     STOSD.REP  ES:EDI=>__mbctype
    //         00554475     STOSB      ES:EDI=>DAT_0088816c
    //         00554476     XOR        EDI,EDI
    //         00554478     SHL        EBX,0x4
    //         0055447b     LEA        EBP,[EBX + 0x592308]=>DAT_00592338
    //                               LAB_00554481                                                 XREF[1]:     005544c1(j)  
    //         00554481     MOV        AL,byte ptr [EBP]=>DAT_00592338
    //         00554484     MOV        ESI,EBP
    //         00554486     TEST       AL,AL
    //         00554488     JZ         LAB_005544ba
    //                               LAB_0055448a                                                 XREF[1]:     005544b8(j)  
    //         0055448a     MOV        CL,byte ptr [ESI + 0x1]=>DAT_00592339
    //         0055448d     TEST       CL,CL
    //         0055448f     JZ         LAB_005544ba
    //         00554491     XOR        EAX,EAX
    //         00554493     AND        ECX,0xff
    //         00554499     MOV        AL,byte ptr [ESI]=>DAT_00592338
    //         0055449b     CMP        EAX,ECX
    //         0055449d     JA         LAB_005544b0
    //         0055449f     MOV        DL,byte ptr [EDI + DAT_005922f0]                 = 01h
    //                                                                                  = 02h
    //                               LAB_005544a5                                                 XREF[1]:     005544ae(j)  
    //         005544a5     OR         byte ptr [EAX + __mbctype+1],DL=>__mbctype+2
    //         005544ab     INC        EAX
    //         005544ac     CMP        EAX,ECX
    //         005544ae     JBE        LAB_005544a5
    //                               LAB_005544b0                                                 XREF[1]:     0055449d(j)  
    //         005544b0     MOV        AL,byte ptr [ESI + 0x2]=>DAT_0059233a
    //         005544b3     ADD        ESI,0x2
    //         005544b6     TEST       AL,AL
    //         005544b8     JNZ        LAB_0055448a
    //                               LAB_005544ba                                                 XREF[2]:     00554488(j), 0055448f(j)  
    //         005544ba     INC        EDI
    //         005544bb     ADD        EBP,0x8
    //         005544be     CMP        EDI,0x4
    //         005544c1     JC         LAB_00554481
    //         005544c3     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         005544c7     PUSH       EAX
    //         005544c8     MOV        [___mbcodepage],EAX
    //         005544cd     CALL       FUN_00554560                                     undefined FUN_00554560()
    //         005544d2     MOV        ECX,dword ptr [EBX + 0x5922fc]=>DAT_0059232c     = A3DAA3C1h
    //         005544d8     MOV        EDX,dword ptr [EBX + 0x592300]=>DAT_00592330     = 00000020h
    //         005544de     MOV        [___mblcid],EAX
    //         005544e3     LEA        EAX,[EBX + 0x5922fc]=>DAT_0059232c               = A3DAA3C1h
    //         005544e9     ADD        ESP,0x4
    //         005544ec     MOV        dword ptr [___mbulinfo],ECX                      = align(12)
    //         005544f2     MOV        EAX,dword ptr [EAX + 0x8]=>DAT_00592334
    //         005544f5     MOV        dword ptr [null_0088827c],EDX                    = align(8)
    //         005544fb     POP        EDI
    //         005544fc     POP        ESI
    //         005544fd     MOV        [null_00888280],EAX                              = align(4)
    //         00554502     POP        EBP
    //         00554503     XOR        EAX,EAX
    //         00554505     POP        EBX
    //         00554506     ADD        ESP,0x14
    //         00554509     RET
}

// Offset: 0x00554510
undefined FUN_00554510() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00554510()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00554510                                                 XREF[1]:     __setmbcp:0055432c(c)  
    //         00554510     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         00554514     MOV        dword ptr [DAT_00888284],0x0
    //         0055451e     CMP        EAX,-0x2
    //         00554521     JNZ        LAB_00554533
    //         00554523     MOV        dword ptr [DAT_00888284],0x1
    //         0055452d     JMP        dword ptr [->KERNEL32.DLL::GetOEMCP]
    //                               LAB_00554533                                                 XREF[1]:     00554521(j)  
    //         00554533     CMP        EAX,-0x3
    //         00554536     JNZ        LAB_00554548
    //         00554538     MOV        dword ptr [DAT_00888284],0x1
    //         00554542     JMP        dword ptr [->KERNEL32.DLL::GetACP]
    //                               LAB_00554548                                                 XREF[1]:     00554536(j)  
    //         00554548     CMP        EAX,-0x4
    //         0055454b     JNZ        LAB_0055455c
    //         0055454d     MOV        EAX,[___lc_codepage]
    //         00554552     MOV        dword ptr [DAT_00888284],0x1
    //                               LAB_0055455c                                                 XREF[1]:     0055454b(j)  
    //         0055455c     RET
}

// Offset: 0x00554560
undefined FUN_00554560() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00554560()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00554560                                                 XREF[2]:     __setmbcp:00554409(c), 
    //                                                                                                         __setmbcp:005544cd(c)  
    //         00554560     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         00554564     ADD        EAX,0xfffffc5c
    //         00554569     CMP        EAX,0x12
    //         0055456c     JA         switchD_00554576::caseD_3a5
    //         0055456e     XOR        ECX,ECX
    //         00554570     MOV        CL,byte ptr [EAX + switchD_00554576::switchdat
    //                               switchD_00554576::switchD
    //         00554576     JMP        dword ptr [ECX*0x4 + switchD_00554576::switchd   = 0055457d
    //                               switchD_00554576::caseD_3a4                                  XREF[2]:     00554576(j), 00554598(*)  
    //         0055457d     MOV        EAX,0x411
    //         00554582     RET
    //                               switchD_00554576::caseD_3a8                                  XREF[2]:     00554576(j), 0055459c(*)  
    //         00554583     MOV        EAX,0x804
    //         00554588     RET
    //                               switchD_00554576::caseD_3b5                                  XREF[2]:     00554576(j), 005545a0(*)  
    //         00554589     MOV        EAX,0x412
    //         0055458e     RET
    //                               switchD_00554576::caseD_3b6                                  XREF[2]:     00554576(j), 005545a4(*)  
    //         0055458f     MOV        EAX,0x404
    //         00554594     RET
    //                               switchD_00554576::caseD_3a6                                  XREF[3]:     0055456c(j), 00554576(j), 
    //                               switchD_00554576::caseD_3a7                                               005545a8(*)  
    //                               switchD_00554576::caseD_3a9
    //                               switchD_00554576::caseD_3aa
    //                               switchD_00554576::caseD_3ab
    //                               switchD_00554576::caseD_3ac
    //                               switchD_00554576::caseD_3ad
    //                               switchD_00554576::caseD_3ae
    //                               switchD_00554576::caseD_3af
    //                               switchD_00554576::caseD_3b0
    //                               switchD_00554576::caseD_3b1
    //                               switchD_00554576::caseD_3b2
    //                               switchD_00554576::caseD_3b3
    //                               switchD_00554576::caseD_3b4
    //                               switchD_00554576::caseD_3a5
    //         00554595     XOR        EAX,EAX
    //         00554597     RET
    //                               switchD_00554576::switchdataD_00554598                       XREF[1]:     FUN_00554560:00554576(*)  
}

// Offset: 0x005545C0
undefined FUN_005545c0() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_005545c0()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_005545c0                                                 XREF[2]:     __setmbcp:00554353(c), 
    //                                                                                                         __setmbcp:0055444a(c)  
    //         005545c0     PUSH       EDI
    //         005545c1     MOV        ECX,0x40
    //         005545c6     XOR        EAX,EAX
    //         005545c8     MOV        EDI,__mbctype
    //         005545cd     STOSD.REP  ES:EDI=>__mbctype
    //         005545cf     STOSB      ES:EDI=>DAT_0088816c
    //         005545d0     XOR        EAX,EAX
    //         005545d2     POP        EDI
    //         005545d3     MOV        [___mbcodepage],EAX
    //         005545d8     MOV        [___mblcid],EAX
    //         005545dd     MOV        [___mbulinfo],EAX                                = align(12)
    //         005545e2     MOV        [null_0088827c],EAX                              = align(8)
    //         005545e7     MOV        [null_00888280],EAX                              = align(4)
    //         005545ec     RET
}

// Offset: 0x005545ED
undefined FUN_005545ed() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_005545ed()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_005545ed
    //         005545ed     NOP
    //         005545ee     NOP
    //         005545ef     NOP
    //                               __getmbcp
    //         005545f0     MOV        EAX,[___mbcodepage]
    //         005545f5     RET
}

// Offset: 0x00554600
undefined initmbctable() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined ___initmbctable()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               ___initmbctable                                              XREF[1]:     entry:0054f8e6(c)  
    //         00554600     PUSH       -0x3
    //         00554602     CALL       __setmbcp                                        undefined __setmbcp()
    //         00554607     ADD        ESP,0x4
    //         0055460a     RET
}

// Offset: 0x00554610
undefined ismbslead() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined __ismbslead()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               __ismbslead                                                  XREF[1]:     __mbsncat:0054c81e(c)  
    //         00554610     MOV        EAX,[___mbcodepage]
    //         00554615     PUSH       EBX
    //         00554616     TEST       EAX,EAX
    //         00554618     JZ         LAB_00554655
    //         0055461a     MOV        ECX,dword ptr [ESP + Stack[0x4]]
    //         0055461e     MOV        EDX,dword ptr [ESP + Stack[0x8]]
    //         00554622     CMP        ECX,EDX
    //         00554624     JA         LAB_00554655
    //         00554626     MOV        BL,0x4
    //                               LAB_00554628                                                 XREF[1]:     0055464a(j)  
    //         00554628     MOV        AL,byte ptr [ECX]
    //         0055462a     TEST       AL,AL
    //         0055462c     JZ         LAB_00554655
    //         0055462e     AND        EAX,0xff
    //         00554633     TEST       byte ptr [EAX + __mbctype+1],BL
    //         00554639     JZ         LAB_00554647
    //         0055463b     MOV        EAX,ECX
    //         0055463d     INC        ECX
    //         0055463e     CMP        EAX,EDX
    //         00554640     JZ         LAB_00554650
    //         00554642     CMP        byte ptr [ECX],0x0
    //         00554645     JZ         LAB_00554655
    //                               LAB_00554647                                                 XREF[1]:     00554639(j)  
    //         00554647     INC        ECX
    //         00554648     CMP        ECX,EDX
    //         0055464a     JBE        LAB_00554628
    //         0055464c     XOR        EAX,EAX
    //         0055464e     POP        EBX
    //         0055464f     RET
    //                               LAB_00554650                                                 XREF[1]:     00554640(j)  
    //         00554650     OR         EAX,0xffffffff
    //         00554653     POP        EBX
    //         00554654     RET
    //                               LAB_00554655                                                 XREF[4]:     00554618(j), 00554624(j), 
    //                                                                                                         0055462c(j), 00554645(j)  
    //         00554655     XOR        EAX,EAX
    //         00554657     POP        EBX
    //         00554658     RET
}

// Offset: 0x00554659
undefined FUN_00554659() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00554659()
    //              undefined         <UNASSIGNED>   <RETURN>
    //              undefined         Stack[-0x4]:1  local_4                   XREF[1]:     00554676(*)  
    //                               FUN_00554659
    //         00554659     NOP
    //         0055465a     NOP
    //         0055465b     NOP
    //         0055465c     NOP
    //         0055465d     NOP
    //         0055465e     NOP
    //         0055465f     NOP
    //                               ___crtGetStringTypeW
    //         00554660     PUSH       ECX
    //         00554661     MOV        EAX,[DAT_00888288]                               = align(4)
    //         00554666     PUSH       EBX
    //         00554667     XOR        EBX,EBX
    //         00554669     PUSH       EBP
    //         0055466a     PUSH       ESI
    //         0055466b     MOV        ESI,dword ptr [->KERNEL32.DLL::GetStringTypeW]   = 0048b8c8
    //         00554671     CMP        EAX,EBX
    //         00554673     PUSH       EDI
    //         00554674     JNZ        LAB_005546b8
    //         00554676     LEA        EAX=>local_4,[ESP + 0x10]
    //         0055467a     PUSH       EAX
    //         0055467b     PUSH       0x1
    //         0055467d     PUSH       u_                                               = u""
    //         00554682     PUSH       0x1
    //         00554684     CALL       ESI=>KERNEL32.DLL::GetStringTypeW
    //         00554686     TEST       EAX,EAX
    //         00554688     JZ         LAB_00554691
    //         0055468a     MOV        EAX,0x1
    //         0055468f     JMP        LAB_005546b3
    //                               LAB_00554691                                                 XREF[1]:     00554688(j)  
    //         00554691     LEA        ECX,[ESP + 0x10]
    //         00554695     PUSH       ECX
    //         00554696     PUSH       offset DAT_fffffff8
    //         00554698     PUSH       offset DAT_fffffff4                              = ""
    //         0055469d     PUSH       offset DAT_fffffff0
    //         0055469f     PUSH       EBX
    //         005546a0     CALL       dword ptr [->KERNEL32.DLL::GetStringTypeA]       = 0048b8b6
    //         005546a6     TEST       EAX,EAX
    //         005546a8     JZ         LAB_00554734
    //         005546ae     MOV        EAX,0x2
    //                               LAB_005546b3                                                 XREF[1]:     0055468f(j)  
    //         005546b3     MOV        [DAT_00888288],EAX                               = align(4)
    //                               LAB_005546b8                                                 XREF[1]:     00554674(j)  
    //         005546b8     CMP        EAX,0x1
    //         005546bb     JNZ        LAB_005546d9
    //         005546bd     MOV        EDX,dword ptr [ESP + Stack[0x10]]
    //         005546c1     MOV        EAX,dword ptr [ESP + Stack[0xc]]
    //         005546c5     MOV        ECX,dword ptr [ESP + Stack[0x8]]
    //         005546c9     PUSH       EDX
    //         005546ca     MOV        EDX,dword ptr [ESP + Stack[0x4]]
    //         005546ce     PUSH       EAX=>DAT_fffffff8
    //         005546cf     PUSH       ECX=>DAT_fffffff4
    //         005546d0     PUSH       EDX=>DAT_fffffff0
    //         005546d1     CALL       ESI=>KERNEL32.DLL::GetStringTypeW
    //         005546d3     POP        EDI
    //         005546d4     POP        ESI
    //         005546d5     POP        EBP
    //         005546d6     POP        EBX
    //         005546d7     POP        ECX
    //         005546d8     RET
    //                               LAB_005546d9                                                 XREF[1]:     005546bb(j)  
    //         005546d9     CMP        EAX,0x2
    //         005546dc     JNZ        LAB_005547de
    //         005546e2     MOV        EAX,dword ptr [ESP + 0x28]
    //         005546e6     MOV        dword ptr [ESP + 0x10],EBX
    //         005546ea     CMP        EAX,EBX
    //         005546ec     JNZ        LAB_005546f7
    //         005546ee     MOV        EAX,[___lc_codepage]
    //         005546f3     MOV        dword ptr [ESP + 0x28],EAX
    //                               LAB_005546f7                                                 XREF[1]:     005546ec(j)  
    //         005546f7     MOV        EDI,dword ptr [ESP + 0x20]
    //         005546fb     MOV        ECX,dword ptr [ESP + 0x1c]
    //         005546ff     MOV        EDX,dword ptr [ESP + 0x28]
    //         00554703     PUSH       EBX
    //         00554704     PUSH       EBX=>DAT_fffffff8
    //         00554705     PUSH       EBX=>DAT_fffffff4
    //         00554706     PUSH       EBX=>DAT_fffffff0
    //         00554707     PUSH       EDI
    //         00554708     PUSH       ECX
    //         00554709     PUSH       0x220
    //         0055470e     PUSH       EDX
    //         0055470f     CALL       dword ptr [->KERNEL32.DLL::WideCharToMultiByte]  = 0048b8a0
    //         00554715     MOV        ESI,EAX
    //         00554717     CMP        ESI,EBX
    //         00554719     JNZ        LAB_00554723
    //         0055471b     XOR        EAX,EAX
    //         0055471d     POP        EDI
    //         0055471e     POP        ESI
    //         0055471f     POP        EBP
    //         00554720     POP        EBX
    //         00554721     POP        ECX
    //         00554722     RET
    //                               LAB_00554723                                                 XREF[1]:     00554719(j)  
    //         00554723     PUSH       ESI
    //         00554724     PUSH       offset DAT_fffffff8
    //         00554726     CALL       calloc                                           undefined calloc()
    //         0055472b     MOV        EBP,EAX
    //         0055472d     ADD        ESP,0x8
    //         00554730     TEST       EBP,EBP
    //         00554732     JNZ        LAB_0055473c
    //                               LAB_00554734                                                 XREF[1]:     005546a8(j)  
    //         00554734     XOR        EAX,EAX
    //         00554736     POP        EDI
    //         00554737     POP        ESI
    //         00554738     POP        EBP
    //         00554739     POP        EBX
    //         0055473a     POP        ECX
    //         0055473b     RET
    //                               LAB_0055473c                                                 XREF[1]:     00554732(j)  
    //         0055473c     MOV        EAX,dword ptr [ESP + 0x1c]
    //         00554740     MOV        ECX,dword ptr [ESP + 0x28]
    //         00554744     PUSH       0x0
    //         00554746     PUSH       0x0=>DAT_fffffff8
    //         00554748     PUSH       ESI=>DAT_fffffff4
    //         00554749     PUSH       EBP=>DAT_fffffff0
    //         0055474a     PUSH       EDI
    //         0055474b     PUSH       EAX
    //         0055474c     PUSH       0x220
    //         00554751     PUSH       ECX
    //         00554752     CALL       dword ptr [->KERNEL32.DLL::WideCharToMultiByte]  = 0048b8a0
    //         00554758     TEST       EAX,EAX
    //         0055475a     JZ         LAB_005547c8
    //         0055475c     LEA        EDX,[ESI + ESI*0x1 + 0x2]
    //         00554760     PUSH       EDX
    //         00554761     CALL       malloc                                           undefined malloc()
    //         00554766     MOV        EBX,EAX
    //         00554768     ADD        ESP,0x4
    //         0055476b     TEST       EBX,EBX
    //         0055476d     JZ         LAB_005547c8
    //         0055476f     MOV        EAX,dword ptr [ESP + 0x2c]
    //         00554773     TEST       EAX,EAX
    //         00554775     JNZ        LAB_0055477c
    //         00554777     MOV        EAX,[DAT_008882c0]
    //                               LAB_0055477c                                                 XREF[1]:     00554775(j)  
    //         0055477c     MOV        ECX,dword ptr [ESP + 0x18]
    //         00554780     PUSH       EBX
    //         00554781     ADD        EDI,EDI
    //         00554783     PUSH       ESI=>DAT_fffffff8
    //         00554784     PUSH       EBP=>DAT_fffffff4
    //         00554785     PUSH       ECX=>DAT_fffffff0
    //         00554786     MOV        word ptr [EBX + EDI*0x1],0xffff
    //         0055478c     PUSH       EAX
    //         0055478d     MOV        word ptr [EBX + EDI*0x1 + -0x2],0xffff
    //         00554794     CALL       dword ptr [->KERNEL32.DLL::GetStringTypeA]       = 0048b8b6
    //         0055479a     CMP        word ptr [EBX + EDI*0x1 + -0x2],0xffff
    //         005547a1     MOV        dword ptr [ESP + 0x10],EAX
    //         005547a5     JZ         LAB_005547c0
    //         005547a7     CMP        word ptr [EBX + EDI*0x1],0xffff
    //         005547ad     JNZ        LAB_005547c0
    //         005547af     MOV        EDX,dword ptr [ESP + 0x24]
    //         005547b3     PUSH       EDI
    //         005547b4     PUSH       EBX=>DAT_fffffff8
    //         005547b5     PUSH       EDX=>DAT_fffffff4
    //         005547b6     CALL       memmove                                          undefined memmove()
    //         005547bb     ADD        ESP,0xc
    //         005547be     JMP        LAB_005547c8
    //                               LAB_005547c0                                                 XREF[2]:     005547a5(j), 005547ad(j)  
    //         005547c0     MOV        dword ptr [ESP + 0x10],0x0
    //                               LAB_005547c8                                                 XREF[3]:     0055475a(j), 0055476d(j), 
    //                                                                                                         005547be(j)  
    //         005547c8     PUSH       EBP
    //         005547c9     CALL       free                                             undefined free()
    //         005547ce     ADD        ESP,0x4
    //         005547d1     PUSH       EBX
    //         005547d2     CALL       free                                             undefined free()
    //         005547d7     MOV        EAX,dword ptr [ESP + 0x14]
    //         005547db     ADD        ESP,0x4
    //                               LAB_005547de                                                 XREF[1]:     005546dc(j)  
    //         005547de     POP        EDI
    //         005547df     POP        ESI
    //         005547e0     POP        EBP
    //         005547e1     POP        EBX
    //         005547e2     POP        ECX
    //         005547e3     RET
}

// Offset: 0x005547F0
undefined crtGetStringTypeA() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined ___crtGetStringTypeA()
    //              undefined         <UNASSIGNED>   <RETURN>
    //              undefined         Stack[-0x2]:1  local_2                   XREF[1]:     00554806(*)  
    //                               ___crtGetStringTypeA                                         XREF[2]:     __ismbcspace:0054c8e8(c), 
    //                                                                                                         __isctype:00554272(c)  
    //         005547f0     PUSH       ECX
    //         005547f1     MOV        EAX,[DAT_0088828c]
    //         005547f6     PUSH       EBX
    //         005547f7     PUSH       EBP
    //         005547f8     PUSH       ESI
    //         005547f9     MOV        ESI,dword ptr [->KERNEL32.DLL::GetStringTypeA]   = 0048b8b6
    //         005547ff     PUSH       EDI
    //         00554800     XOR        EDI,EDI
    //         00554802     CMP        EAX,EDI
    //         00554804     JNZ        LAB_00554829
    //         00554806     LEA        EAX=>local_2,[ESP + 0x12]
    //         0055480a     PUSH       EAX
    //         0055480b     PUSH       0x1
    //         0055480d     PUSH       s_                                               = ""
    //         00554812     PUSH       0x1
    //         00554814     PUSH       EDI
    //         00554815     CALL       ESI=>KERNEL32.DLL::GetStringTypeA
    //         00554817     TEST       EAX,EAX
    //         00554819     JZ         LAB_005548ee
    //         0055481f     MOV        EAX,0x2
    //         00554824     MOV        [DAT_0088828c],EAX
    //                               LAB_00554829                                                 XREF[2]:     00554804(j), 00554910(j)  
    //         00554829     CMP        EAX,0x2
    //         0055482c     JNZ        LAB_00554858
    //         0055482e     MOV        EAX,dword ptr [ESP + Stack[0x18]]
    //         00554832     CMP        EAX,EDI
    //         00554834     JNZ        LAB_0055483b
    //         00554836     MOV        EAX,[DAT_008882c0]
    //                               LAB_0055483b                                                 XREF[1]:     00554834(j)  
    //         0055483b     MOV        EDX,dword ptr [ESP + Stack[0x10]]
    //         0055483f     MOV        ECX,dword ptr [ESP + Stack[0xc]]
    //         00554843     PUSH       EDX
    //         00554844     MOV        EDX,dword ptr [ESP + Stack[0x8]]
    //         00554848     PUSH       ECX
    //         00554849     MOV        ECX,dword ptr [ESP + Stack[0x4]]
    //         0055484d     PUSH       EDX
    //         0055484e     PUSH       ECX
    //         0055484f     PUSH       EAX
    //         00554850     CALL       ESI=>KERNEL32.DLL::GetStringTypeA
    //         00554852     POP        EDI
    //         00554853     POP        ESI
    //         00554854     POP        EBP
    //         00554855     POP        EBX
    //         00554856     POP        ECX
    //         00554857     RET
    //                               LAB_00554858                                                 XREF[1]:     0055482c(j)  
    //         00554858     CMP        EAX,0x1
    //         0055485b     JNZ        LAB_005548e8
    //         00554861     MOV        EBX,dword ptr [ESP + 0x28]
    //         00554865     MOV        dword ptr [ESP + 0x2c],EDI
    //         00554869     CMP        EBX,EDI
    //         0055486b     JNZ        LAB_00554873
    //         0055486d     MOV        EBX,dword ptr [___lc_codepage]
    //                               LAB_00554873                                                 XREF[1]:     0055486b(j)  
    //         00554873     MOV        EBP,dword ptr [ESP + 0x20]
    //         00554877     MOV        EDX,dword ptr [ESP + 0x1c]
    //         0055487b     PUSH       EDI
    //         0055487c     PUSH       EDI
    //         0055487d     PUSH       EBP
    //         0055487e     PUSH       EDX
    //         0055487f     PUSH       0x9
    //         00554881     PUSH       EBX
    //         00554882     CALL       dword ptr [->KERNEL32.DLL::MultiByteToWideChar]  = 0048b8da
    //         00554888     MOV        ESI,EAX
    //         0055488a     TEST       ESI,ESI
    //         0055488c     JZ         LAB_005548d9
    //         0055488e     PUSH       ESI
    //         0055488f     PUSH       0x2
    //         00554891     CALL       calloc                                           undefined calloc()
    //         00554896     MOV        EDI,EAX
    //         00554898     ADD        ESP,0x8
    //         0055489b     TEST       EDI,EDI
    //         0055489d     JZ         LAB_005548d9
    //         0055489f     MOV        EAX,dword ptr [ESP + 0x1c]
    //         005548a3     PUSH       ESI
    //         005548a4     PUSH       EDI
    //         005548a5     PUSH       EBP
    //         005548a6     PUSH       EAX
    //         005548a7     PUSH       0x1
    //         005548a9     PUSH       EBX
    //         005548aa     CALL       dword ptr [->KERNEL32.DLL::MultiByteToWideChar]  = 0048b8da
    //         005548b0     TEST       EAX,EAX
    //         005548b2     JZ         LAB_005548d9
    //         005548b4     MOV        ECX,dword ptr [ESP + 0x24]
    //         005548b8     MOV        EDX,dword ptr [ESP + 0x18]
    //         005548bc     PUSH       ECX
    //         005548bd     PUSH       EAX
    //         005548be     PUSH       EDI
    //         005548bf     PUSH       EDX
    //         005548c0     CALL       dword ptr [->KERNEL32.DLL::GetStringTypeW]       = 0048b8c8
    //         005548c6     PUSH       EDI
    //         005548c7     MOV        ESI,EAX
    //         005548c9     CALL       free                                             undefined free()
    //         005548ce     ADD        ESP,0x4
    //         005548d1     MOV        EAX,ESI
    //         005548d3     POP        EDI
    //         005548d4     POP        ESI
    //         005548d5     POP        EBP
    //         005548d6     POP        EBX
    //         005548d7     POP        ECX
    //         005548d8     RET
    //                               LAB_005548d9                                                 XREF[3]:     0055488c(j), 0055489d(j), 
    //                                                                                                         005548b2(j)  
    //         005548d9     MOV        ESI,dword ptr [ESP + 0x2c]
    //         005548dd     PUSH       EDI
    //         005548de     CALL       free                                             undefined free()
    //         005548e3     ADD        ESP,0x4
    //         005548e6     MOV        EAX,ESI
    //                               LAB_005548e8                                                 XREF[1]:     0055485b(j)  
    //         005548e8     POP        EDI
    //         005548e9     POP        ESI
    //         005548ea     POP        EBP
    //         005548eb     POP        EBX
    //         005548ec     POP        ECX
    //         005548ed     RET
    //                               LAB_005548ee                                                 XREF[1]:     00554819(j)  
    //         005548ee     LEA        ECX,[ESP + 0x12]
    //         005548f2     PUSH       ECX
    //         005548f3     PUSH       0x1
    //         005548f5     PUSH       u_                                               = u""
    //         005548fa     PUSH       0x1
    //         005548fc     CALL       dword ptr [->KERNEL32.DLL::GetStringTypeW]       = 0048b8c8
    //         00554902     TEST       EAX,EAX
    //         00554904     JZ         LAB_00554915
    //         00554906     MOV        EAX,0x1
    //         0055490b     MOV        [DAT_0088828c],EAX
    //         00554910     JMP        LAB_00554829
    //                               LAB_00554915                                                 XREF[1]:     00554904(j)  
    //         00554915     POP        EDI
    //         00554916     POP        ESI
    //         00554917     POP        EBP
    //         00554918     XOR        EAX,EAX
    //         0055491a     POP        EBX
    //         0055491b     POP        ECX
    //         0055491c     RET
}

// Offset: 0x00554920
undefined mbsnbcnt() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined __mbsnbcnt()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               __mbsnbcnt                                                   XREF[1]:     __mbsninc:0054c953(c)  
    //         00554920     MOV        EDX,dword ptr [ESP + Stack[0x8]]
    //         00554924     PUSH       EBX
    //         00554925     PUSH       ESI
    //         00554926     MOV        ESI,dword ptr [ESP + Stack[0x4]]
    //         0055492a     MOV        ECX,EDX
    //         0055492c     DEC        EDX
    //         0055492d     TEST       ECX,ECX
    //         0055492f     MOV        EAX,ESI
    //         00554931     JZ         LAB_0055495f
    //         00554933     MOV        BL,0x4
    //                               LAB_00554935                                                 XREF[1]:     00554957(j)  
    //         00554935     MOV        CL,byte ptr [EAX]
    //         00554937     TEST       CL,CL
    //         00554939     JZ         LAB_0055495f
    //         0055493b     AND        ECX,0xff
    //         00554941     TEST       byte ptr [ECX + __mbctype+1],BL
    //         00554947     JZ         LAB_00554951
    //         00554949     MOV        CL,byte ptr [EAX + 0x1]
    //         0055494c     INC        EAX
    //         0055494d     TEST       CL,CL
    //         0055494f     JZ         LAB_0055495e
    //                               LAB_00554951                                                 XREF[1]:     00554947(j)  
    //         00554951     INC        EAX
    //         00554952     MOV        ECX,EDX
    //         00554954     DEC        EDX
    //         00554955     TEST       ECX,ECX
    //         00554957     JNZ        LAB_00554935
    //         00554959     SUB        EAX,ESI
    //         0055495b     POP        ESI
    //         0055495c     POP        EBX
    //         0055495d     RET
    //                               LAB_0055495e                                                 XREF[1]:     0055494f(j)  
    //         0055495e     DEC        EAX
    //                               LAB_0055495f                                                 XREF[2]:     00554931(j), 00554939(j)  
    //         0055495f     SUB        EAX,ESI
    //         00554961     POP        ESI
    //         00554962     POP        EBX
    //         00554963     RET
}

// Offset: 0x00554970
undefined alloc_osfhnd() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined __alloc_osfhnd()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               __alloc_osfhnd                                               XREF[2]:     __sopen:0054d187(c), 
    //                                                                                                         FUN_00554bc4:00554c1e(c)  
    //         00554970     PUSH       EBX
    //         00554971     PUSH       EBP
    //         00554972     PUSH       ESI
    //         00554973     PUSH       EDI
    //         00554974     OR         EBP,0xffffffff
    //         00554977     XOR        ESI,ESI
    //         00554979     XOR        EDI,EDI
    //         0055497b     MOV        ECX,___pioinfo
    //         00554980     MOV        BL,0x1
    //                               LAB_00554982                                                 XREF[1]:     005549c3(j)  
    //         00554982     MOV        EAX,dword ptr [ECX]=>___pioinfo
    //         00554984     TEST       EAX,EAX
    //         00554986     JZ         LAB_005549cc
    //         00554988     LEA        EDX,[EAX + 0x100]
    //         0055498e     CMP        EAX,EDX
    //         00554990     JNC        LAB_005549b1
    //                               LAB_00554992                                                 XREF[1]:     0055499c(j)  
    //         00554992     TEST       byte ptr [EAX + 0x4],BL
    //         00554995     JZ         LAB_005549a0
    //         00554997     ADD        EAX,0x8
    //         0055499a     CMP        EAX,EDX
    //         0055499c     JC         LAB_00554992
    //         0055499e     JMP        LAB_005549b1
    //                               LAB_005549a0                                                 XREF[1]:     00554995(j)  
    //         005549a0     MOV        dword ptr [EAX],0xffffffff
    //         005549a6     MOV        EDX,dword ptr [ECX]=>DAT_008884e4
    //         005549a8     SUB        EAX,EDX
    //         005549aa     SAR        EAX,0x3
    //         005549ad     ADD        EAX,EDI
    //         005549af     MOV        EBP,EAX
    //                               LAB_005549b1                                                 XREF[2]:     00554990(j), 0055499e(j)  
    //         005549b1     CMP        EBP,-0x1
    //         005549b4     JNZ        LAB_00554a25
    //         005549b6     ADD        ECX,0x4
    //         005549b9     INC        ESI
    //         005549ba     ADD        EDI,0x20
    //         005549bd     CMP        ECX,__nhandle
    //         005549c3     JL         LAB_00554982
    //         005549c5     MOV        EAX,EBP
    //         005549c7     POP        EDI
    //         005549c8     POP        ESI
    //         005549c9     POP        EBP
    //         005549ca     POP        EBX
    //         005549cb     RET
    //                               LAB_005549cc                                                 XREF[1]:     00554986(j)  
    //         005549cc     PUSH       0x100
    //         005549d1     CALL       malloc                                           undefined malloc()
    //         005549d6     ADD        ESP,0x4
    //         005549d9     TEST       EAX,EAX
    //         005549db     JZ         LAB_00554a25
    //         005549dd     MOV        EDI,dword ptr [__nhandle]
    //         005549e3     LEA        ECX,[EAX + 0x100]
    //         005549e9     ADD        EDI,0x20
    //         005549ec     CMP        EAX,ECX
    //         005549ee     MOV        dword ptr [ESI*0x4 + 0x8884e0]=>DAT_008884e4,EAX
    //         005549f5     MOV        dword ptr [__nhandle],EDI
    //         005549fb     JNC        LAB_00554a20
    //         005549fd     MOV        CL,0xa
    //                               LAB_005549ff                                                 XREF[1]:     00554a1e(j)  
    //         005549ff     MOV        byte ptr [EAX + 0x4],0x0
    //         00554a03     MOV        dword ptr [EAX],0xffffffff
    //         00554a09     MOV        byte ptr [EAX + 0x5],CL
    //         00554a0c     MOV        EDX,dword ptr [ESI*0x4 + 0x8884e0]=>DAT_008884e4
    //         00554a13     ADD        EAX,0x8
    //         00554a16     ADD        EDX,0x100
    //         00554a1c     CMP        EAX,EDX
    //         00554a1e     JC         LAB_005549ff
    //                               LAB_00554a20                                                 XREF[1]:     005549fb(j)  
    //         00554a20     SHL        ESI,0x5
    //         00554a23     MOV        EBP,ESI
    //                               LAB_00554a25                                                 XREF[2]:     005549b4(j), 005549db(j)  
    //         00554a25     POP        EDI
    //         00554a26     MOV        EAX,EBP
    //         00554a28     POP        ESI
    //         00554a29     POP        EBP
    //         00554a2a     POP        EBX
    //         00554a2b     RET
}

// Offset: 0x00554A30
undefined set_osfhnd() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined __set_osfhnd()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               __set_osfhnd                                                 XREF[2]:     __sopen:0054d235(c), 
    //                                                                                                         FUN_00554bc4:00554c46(c)  
    //         00554a30     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         00554a34     MOV        ECX,dword ptr [__nhandle]
    //         00554a3a     PUSH       EBX
    //         00554a3b     PUSH       ESI
    //         00554a3c     CMP        EAX,ECX
    //         00554a3e     PUSH       EDI
    //         00554a3f     JNC        LAB_00554ab8
    //         00554a41     MOV        ECX,EAX
    //         00554a43     MOV        ESI,EAX
    //         00554a45     SAR        ECX,0x5
    //         00554a48     AND        ESI,0x1f
    //         00554a4b     MOV        EDX,dword ptr [ECX*0x4 + ___pioinfo]
    //         00554a52     LEA        EDI,[ECX*0x4 + ___pioinfo]
    //         00554a59     SHL        ESI,0x3
    //         00554a5c     CMP        dword ptr [EDX + ESI*0x1],-0x1
    //         00554a60     JNZ        LAB_00554ab8
    //         00554a62     MOV        ECX,dword ptr [___app_type]                      = 00000002h
    //         00554a68     MOV        EBX,dword ptr [ESP + Stack[0x8]]
    //         00554a6c     CMP        ECX,0x1
    //         00554a6f     JNZ        LAB_00554aad
    //         00554a71     SUB        EAX,0x0
    //         00554a74     JZ         LAB_00554aa4
    //         00554a76     DEC        EAX
    //         00554a77     JZ         LAB_00554a90
    //         00554a79     DEC        EAX
    //         00554a7a     JNZ        LAB_00554aad
    //         00554a7c     PUSH       EBX
    //         00554a7d     PUSH       DAT_fffffff4
    //         00554a7f     CALL       dword ptr [->KERNEL32.DLL::SetStdHandle]         = 0048b8f0
    //         00554a85     MOV        EAX,dword ptr [EDI]=>___pioinfo
    //         00554a87     MOV        dword ptr [EAX + ESI*0x1],EBX
    //         00554a8a     XOR        EAX,EAX
    //         00554a8c     POP        EDI
    //         00554a8d     POP        ESI
    //         00554a8e     POP        EBX
    //         00554a8f     RET
    //                               LAB_00554a90                                                 XREF[1]:     00554a77(j)  
    //         00554a90     PUSH       EBX
    //         00554a91     PUSH       DAT_fffffff5
    //         00554a93     CALL       dword ptr [->KERNEL32.DLL::SetStdHandle]         = 0048b8f0
    //         00554a99     MOV        EAX,dword ptr [EDI]=>___pioinfo
    //         00554a9b     MOV        dword ptr [EAX + ESI*0x1],EBX
    //         00554a9e     XOR        EAX,EAX
    //         00554aa0     POP        EDI
    //         00554aa1     POP        ESI
    //         00554aa2     POP        EBX
    //         00554aa3     RET
    //                               LAB_00554aa4                                                 XREF[1]:     00554a74(j)  
    //         00554aa4     PUSH       EBX
    //         00554aa5     PUSH       DAT_fffffff6
    //         00554aa7     CALL       dword ptr [->KERNEL32.DLL::SetStdHandle]         = 0048b8f0
    //                               LAB_00554aad                                                 XREF[2]:     00554a6f(j), 00554a7a(j)  
    //         00554aad     MOV        EAX,dword ptr [EDI]=>___pioinfo
    //         00554aaf     MOV        dword ptr [EAX + ESI*0x1],EBX
    //         00554ab2     XOR        EAX,EAX
    //         00554ab4     POP        EDI
    //         00554ab5     POP        ESI
    //         00554ab6     POP        EBX
    //         00554ab7     RET
    //                               LAB_00554ab8                                                 XREF[2]:     00554a3f(j), 00554a60(j)  
    //         00554ab8     POP        EDI
    //         00554ab9     POP        ESI
    //         00554aba     MOV        dword ptr [_errno],0x9                           = align(4)
    //         00554ac4     MOV        dword ptr [__doserrno],0x0
    //         00554ace     OR         EAX,0xffffffff
    //         00554ad1     POP        EBX
    //         00554ad2     RET
}

// Offset: 0x00554AE0
undefined free_osfhnd() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined __free_osfhnd()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               __free_osfhnd                                                XREF[1]:     close:0054cd2a(c)  
    //         00554ae0     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         00554ae4     MOV        ECX,dword ptr [__nhandle]
    //         00554aea     PUSH       EBX
    //         00554aeb     PUSH       ESI
    //         00554aec     CMP        EAX,ECX
    //         00554aee     PUSH       EDI
    //         00554aef     JNC        LAB_00554b59
    //         00554af1     MOV        ECX,EAX
    //         00554af3     MOV        ESI,EAX
    //         00554af5     SAR        ECX,0x5
    //         00554af8     AND        ESI,0x1f
    //         00554afb     MOV        EDX,dword ptr [ECX*0x4 + ___pioinfo]
    //         00554b02     LEA        EDI,[ECX*0x4 + ___pioinfo]
    //         00554b09     SHL        ESI,0x3
    //         00554b0c     MOV        BL,byte ptr [EDX + ESI*0x1 + 0x4]
    //         00554b10     LEA        ECX,[EDX + ESI*0x1]
    //         00554b13     MOV        EDX,0x1
    //         00554b18     TEST       DL,BL
    //         00554b1a     JZ         LAB_00554b59
    //         00554b1c     CMP        dword ptr [ECX],-0x1
    //         00554b1f     JZ         LAB_00554b59
    //         00554b21     CMP        dword ptr [___app_type],EDX                      = 00000002h
    //         00554b27     JNZ        LAB_00554b4a
    //         00554b29     SUB        EAX,0x0
    //         00554b2c     JZ         LAB_00554b40
    //         00554b2e     DEC        EAX
    //         00554b2f     JZ         LAB_00554b3a
    //         00554b31     DEC        EAX
    //         00554b32     JNZ        LAB_00554b4a
    //         00554b34     PUSH       0x0
    //         00554b36     PUSH       DAT_fffffff4
    //         00554b38     JMP        LAB_00554b44
    //                               LAB_00554b3a                                                 XREF[1]:     00554b2f(j)  
    //         00554b3a     PUSH       0x0
    //         00554b3c     PUSH       DAT_fffffff5
    //         00554b3e     JMP        LAB_00554b44
    //                               LAB_00554b40                                                 XREF[1]:     00554b2c(j)  
    //         00554b40     PUSH       0x0
    //         00554b42     PUSH       DAT_fffffff6
    //                               LAB_00554b44                                                 XREF[2]:     00554b38(j), 00554b3e(j)  
    //         00554b44     CALL       dword ptr [->KERNEL32.DLL::SetStdHandle]         = 0048b8f0
    //                               LAB_00554b4a                                                 XREF[2]:     00554b27(j), 00554b32(j)  
    //         00554b4a     MOV        EAX,dword ptr [EDI]=>___pioinfo
    //         00554b4c     MOV        dword ptr [EAX + ESI*0x1],0xffffffff
    //         00554b53     XOR        EAX,EAX
    //         00554b55     POP        EDI
    //         00554b56     POP        ESI
    //         00554b57     POP        EBX
    //         00554b58     RET
    //                               LAB_00554b59                                                 XREF[3]:     00554aef(j), 00554b1a(j), 
    //                                                                                                         00554b1f(j)  
    //         00554b59     POP        EDI
    //         00554b5a     POP        ESI
    //         00554b5b     MOV        dword ptr [_errno],0x9                           = align(4)
    //         00554b65     MOV        dword ptr [__doserrno],0x0
    //         00554b6f     OR         EAX,0xffffffff
    //         00554b72     POP        EBX
    //         00554b73     RET
}

// Offset: 0x00554B80
undefined get_osfhandle() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined __get_osfhandle()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               __get_osfhandle                                              XREF[7]:     close:0054ccd8(c), 
    //                                                                                                         close:0054ccf1(c), 
    //                                                                                                         close:0054ccfd(c), 
    //                                                                                                         close:0054cd0a(c), 
    //                                                                                                         lseek:0054d418(c), 
    //                                                                                                         __commit:00553eb7(c), 
    //                                                                                                         __chsize:00554d87(c)  
    //         00554b80     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         00554b84     MOV        ECX,dword ptr [__nhandle]
    //         00554b8a     CMP        EAX,ECX
    //         00554b8c     JNC        LAB_00554bac
    //         00554b8e     MOV        ECX,EAX
    //         00554b90     AND        EAX,0x1f
    //         00554b93     SAR        ECX,0x5
    //         00554b96     MOV        EDX,dword ptr [ECX*0x4 + ___pioinfo]
    //         00554b9d     MOV        CL,byte ptr [EDX + EAX*0x8 + 0x4]
    //         00554ba1     TEST       CL,0x1
    //         00554ba4     LEA        EAX,[EDX + EAX*0x8]
    //         00554ba7     JZ         LAB_00554bac
    //         00554ba9     MOV        EAX,dword ptr [EAX]
    //         00554bab     RET
    //                               LAB_00554bac                                                 XREF[2]:     00554b8c(j), 00554ba7(j)  
    //         00554bac     MOV        dword ptr [_errno],0x9                           = align(4)
    //         00554bb6     MOV        dword ptr [__doserrno],0x0
    //         00554bc0     OR         EAX,0xffffffff
    //         00554bc3     RET
}

// Offset: 0x00554BC4
undefined FUN_00554bc4() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00554bc4()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00554bc4
    //         00554bc4     NOP
    //         00554bc5     NOP
    //         00554bc6     NOP
    //         00554bc7     NOP
    //         00554bc8     NOP
    //         00554bc9     NOP
    //         00554bca     NOP
    //         00554bcb     NOP
    //         00554bcc     NOP
    //         00554bcd     NOP
    //         00554bce     NOP
    //         00554bcf     NOP
    //                               __open_osfhandle
    //         00554bd0     MOV        EAX,dword ptr [ESP + Stack[0x8]]
    //         00554bd4     PUSH       EBX
    //         00554bd5     XOR        BL,BL
    //         00554bd7     PUSH       ESI
    //         00554bd8     TEST       AL,0x8
    //         00554bda     PUSH       EDI
    //         00554bdb     JZ         LAB_00554bdf
    //         00554bdd     MOV        BL,0x20
    //                               LAB_00554bdf                                                 XREF[1]:     00554bdb(j)  
    //         00554bdf     TEST       AH,0x40
    //         00554be2     JZ         LAB_00554be7
    //         00554be4     OR         BL,0x80
    //                               LAB_00554be7                                                 XREF[1]:     00554be2(j)  
    //         00554be7     MOV        EDI,dword ptr [ESP + Stack[0x4]]
    //         00554beb     PUSH       EDI
    //         00554bec     CALL       dword ptr [->KERNEL32.DLL::GetFileType]          = 0048b742
    //         00554bf2     TEST       EAX,EAX
    //         00554bf4     JNZ        LAB_00554c0c
    //         00554bf6     CALL       dword ptr [->KERNEL32.DLL::GetLastError]         = 0048aa76
    //         00554bfc     PUSH       EAX
    //         00554bfd     CALL       __dosmaperr                                      undefined __dosmaperr()
    //         00554c02     ADD        ESP,0x4
    //         00554c05     OR         EAX,0xffffffff
    //         00554c08     POP        EDI
    //         00554c09     POP        ESI
    //         00554c0a     POP        EBX
    //         00554c0b     RET
    //                               LAB_00554c0c                                                 XREF[1]:     00554bf4(j)  
    //         00554c0c     CMP        EAX,0x2
    //         00554c0f     JNZ        LAB_00554c16
    //         00554c11     OR         BL,0x40
    //         00554c14     JMP        LAB_00554c1e
    //                               LAB_00554c16                                                 XREF[1]:     00554c0f(j)  
    //         00554c16     CMP        EAX,0x3
    //         00554c19     JNZ        LAB_00554c1e
    //         00554c1b     OR         BL,0x8
    //                               LAB_00554c1e                                                 XREF[2]:     00554c14(j), 00554c19(j)  
    //         00554c1e     CALL       __alloc_osfhnd                                   undefined __alloc_osfhnd()
    //         00554c23     MOV        ESI,EAX
    //         00554c25     CMP        ESI,-0x1
    //         00554c28     JNZ        LAB_00554c44
    //         00554c2a     MOV        dword ptr [_errno],0x18                          = align(4)
    //         00554c34     MOV        dword ptr [__doserrno],0x0
    //         00554c3e     OR         EAX,EAX
    //         00554c40     POP        EDI
    //         00554c41     POP        ESI
    //         00554c42     POP        EBX
    //         00554c43     RET
    //                               LAB_00554c44                                                 XREF[1]:     00554c28(j)  
    //         00554c44     PUSH       EDI
    //         00554c45     PUSH       ESI=>DAT_fffffff8
    //         00554c46     CALL       __set_osfhnd                                     undefined __set_osfhnd()
    //         00554c4b     MOV        EAX,ESI
    //         00554c4d     MOV        ECX,ESI
    //         00554c4f     SAR        EAX,0x5
    //         00554c52     ADD        ESP,0x8
    //         00554c55     AND        ECX,0x1f
    //         00554c58     MOV        EDX,dword ptr [EAX*0x4 + ___pioinfo]
    //         00554c5f     OR         BL,0x1
    //         00554c62     MOV        EAX,ESI
    //         00554c64     POP        EDI
    //         00554c65     MOV        byte ptr [EDX + ECX*0x8 + 0x4],BL
    //         00554c69     POP        ESI
    //         00554c6a     POP        EBX
    //         00554c6b     RET
}

// Offset: 0x00554C70
undefined chsize() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined __chsize()
    //              undefined         <UNASSIGNED>   <RETURN>
    //              undefined         Stack[-0x100   local_1000                XREF[2]:     00554cfa(*), 00554d20(*)  
    //              undefined4        Stack[-0x100   local_1004                XREF[2]:     00554cc1(W), 00554d58(R)  
    //                               __chsize                                                     XREF[1]:     __sopen:0054d2e2(c)  
    //         00554c70     MOV        EAX,0x1004
    //         00554c75     CALL       __alloca_probe                                   undefined __alloca_probe()
    //         00554c7a     MOV        EAX,[__nhandle]
    //         00554c7f     PUSH       EBX
    //         00554c80     MOV        EBX,dword ptr [ESP + Stack[0x4]]
    //         00554c87     PUSH       EBP
    //         00554c88     XOR        EBP,EBP
    //         00554c8a     PUSH       ESI
    //         00554c8b     CMP        EBX,EAX
    //         00554c8d     PUSH       EDI
    //         00554c8e     JNC        LAB_00554dd2
    //         00554c94     MOV        EAX,EBX
    //         00554c96     MOV        ECX,EBX
    //         00554c98     SAR        EAX,0x5
    //         00554c9b     AND        ECX,0x1f
    //         00554c9e     MOV        EDX,dword ptr [EAX*0x4 + ___pioinfo]
    //         00554ca5     TEST       byte ptr [EDX + ECX*0x8 + 0x4],0x1
    //         00554caa     JZ         LAB_00554dd2
    //         00554cb0     PUSH       0x1
    //         00554cb2     PUSH       EBP
    //         00554cb3     PUSH       EBX
    //         00554cb4     CALL       lseek                                            undefined lseek()
    //         00554cb9     MOV        EDI,EAX
    //         00554cbb     ADD        ESP,0xc
    //         00554cbe     CMP        EDI,-0x1
    //         00554cc1     MOV        dword ptr [ESP + local_1004],EDI
    //         00554cc5     JZ         LAB_00554ddc
    //         00554ccb     PUSH       0x2
    //         00554ccd     PUSH       EBP
    //         00554cce     PUSH       EBX
    //         00554ccf     CALL       lseek                                            undefined lseek()
    //         00554cd4     ADD        ESP,0xc
    //         00554cd7     CMP        EAX,-0x1
    //         00554cda     JZ         LAB_00554ddc
    //         00554ce0     MOV        ECX,dword ptr [ESP + Stack[0x8]]
    //         00554ce7     MOV        ESI,ECX
    //         00554ce9     SUB        ESI,EAX
    //         00554ceb     TEST       ESI,ESI
    //         00554ced     JLE        LAB_00554d78
    //         00554cf3     MOV        ECX,0x400
    //         00554cf8     XOR        EAX,EAX
    //         00554cfa     LEA        EDI=>local_1000,[ESP + 0x14]
    //         00554cfe     PUSH       0x8000
    //         00554d03     STOSD.REP  ES:EDI
    //         00554d05     PUSH       EBX
    //         00554d06     CALL       __setmode                                        undefined __setmode()
    //         00554d0b     ADD        ESP,0x8
    //         00554d0e     MOV        EDI,EAX
    //                               LAB_00554d10                                                 XREF[1]:     00554d39(j)  
    //         00554d10     CMP        ESI,0x1000
    //         00554d16     MOV        EAX,0x1000
    //         00554d1b     JGE        LAB_00554d1f
    //         00554d1d     MOV        EAX,ESI
    //                               LAB_00554d1f                                                 XREF[1]:     00554d1b(j)  
    //         00554d1f     PUSH       EAX
    //         00554d20     LEA        EAX=>local_1000,[ESP + 0x18]
    //         00554d24     PUSH       EAX
    //         00554d25     PUSH       EBX
    //         00554d26     CALL       write                                            undefined write()
    //         00554d2b     ADD        ESP,0xc
    //         00554d2e     CMP        EAX,-0x1
    //         00554d31     JZ         LAB_00554d3b
    //         00554d33     SUB        ESI,EAX
    //         00554d35     TEST       ESI,ESI
    //         00554d37     JLE        LAB_00554d51
    //         00554d39     JMP        LAB_00554d10
    //                               LAB_00554d3b                                                 XREF[1]:     00554d31(j)  
    //         00554d3b     CMP        dword ptr [__doserrno],0x5
    //         00554d42     JNZ        LAB_00554d4e
    //         00554d44     MOV        dword ptr [_errno],0xd                           = align(4)
    //                               LAB_00554d4e                                                 XREF[1]:     00554d42(j)  
    //         00554d4e     OR         EBP,0xffffffff
    //                               LAB_00554d51                                                 XREF[1]:     00554d37(j)  
    //         00554d51     PUSH       EDI
    //         00554d52     PUSH       EBX
    //         00554d53     CALL       __setmode                                        undefined __setmode()
    //         00554d58     MOV        EDI,dword ptr [ESP + local_1004]
    //         00554d5c     ADD        ESP,0x8
    //         00554d5f     PUSH       0x0
    //         00554d61     PUSH       EDI
    //         00554d62     PUSH       EBX
    //         00554d63     CALL       lseek                                            undefined lseek()
    //         00554d68     ADD        ESP,0xc
    //         00554d6b     MOV        EAX,EBP
    //         00554d6d     POP        EDI
    //         00554d6e     POP        ESI
    //         00554d6f     POP        EBP
    //         00554d70     POP        EBX
    //         00554d71     ADD        ESP,0x1004
    //         00554d77     RET
    //                               LAB_00554d78                                                 XREF[1]:     00554ced(j)  
    //         00554d78     JGE        LAB_00554db9
    //         00554d7a     PUSH       0x0
    //         00554d7c     PUSH       ECX
    //         00554d7d     PUSH       EBX
    //         00554d7e     CALL       lseek                                            undefined lseek()
    //         00554d83     ADD        ESP,0xc
    //         00554d86     PUSH       EBX
    //         00554d87     CALL       __get_osfhandle                                  undefined __get_osfhandle()
    //         00554d8c     ADD        ESP,0x4
    //         00554d8f     PUSH       EAX
    //         00554d90     CALL       dword ptr [->KERNEL32.DLL::SetEndOfFile]         = 0048b900
    //         00554d96     MOV        EBP,EAX
    //         00554d98     NEG        EBP
    //         00554d9a     SBB        EBP,EBP
    //         00554d9c     NEG        EBP
    //         00554d9e     DEC        EBP
    //         00554d9f     CMP        EBP,-0x1
    //         00554da2     JNZ        LAB_00554db9
    //         00554da4     MOV        dword ptr [_errno],0xd                           = align(4)
    //         00554dae     CALL       dword ptr [->KERNEL32.DLL::GetLastError]         = 0048aa76
    //         00554db4     MOV        [__doserrno],EAX
    //                               LAB_00554db9                                                 XREF[2]:     00554d78(j), 00554da2(j)  
    //         00554db9     PUSH       0x0
    //         00554dbb     PUSH       EDI
    //         00554dbc     PUSH       EBX
    //         00554dbd     CALL       lseek                                            undefined lseek()
    //         00554dc2     ADD        ESP,0xc
    //         00554dc5     MOV        EAX,EBP
    //         00554dc7     POP        EDI
    //         00554dc8     POP        ESI
    //         00554dc9     POP        EBP
    //         00554dca     POP        EBX
    //         00554dcb     ADD        ESP,0x1004
    //         00554dd1     RET
    //                               LAB_00554dd2                                                 XREF[2]:     00554c8e(j), 00554caa(j)  
    //         00554dd2     MOV        dword ptr [_errno],0x9                           = align(4)
    //                               LAB_00554ddc                                                 XREF[2]:     00554cc5(j), 00554cda(j)  
    //         00554ddc     POP        EDI
    //         00554ddd     POP        ESI
    //         00554dde     POP        EBP
    //         00554ddf     OR         EAX,0xffffffff
    //         00554de2     POP        EBX
    //         00554de3     ADD        ESP,0x1004
    //         00554de9     RET
}

// Offset: 0x00554DEA
undefined FUN_00554dea() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00554dea()
    //              undefined         <UNASSIGNED>   <RETURN>
    //              undefined4        Stack[-0x8]:4  local_8                   XREF[1]:     00554e1c(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[2]:     00554e16(W), 00554e1f(*)  
    //                               FUN_00554dea
    //         00554dea     NOP
    //         00554deb     NOP
    //         00554dec     NOP
    //         00554ded     NOP
    //         00554dee     NOP
    //         00554def     NOP
    //         00554df0     PUSH       ESI
    //         00554df1     INC        EBX
    //         00554df2     XOR        DH,byte ptr [EAX]
    //         00554df4     POP        EAX
    //         00554df5     INC        EBX
    //         00554df6     XOR        byte ptr [EAX],DH
    //                               __except_handler3                                            XREF[10]:    `eh_vector_constructor_iterator':0
    //                                                                                                         `eh_vector_destructor_iterator':00
    //                                                                                                         __ArrayUnwind:0054d83a(*), 
    //                                                                                                         entry:0054f87a(*), 
    //                                                                                                         ___FrameUnwindToState:0054fe9a(*), 
    //                                                                                                         FUN_00550000:0055000a(*), 
    //                                                                                                         FUN_00550180:0055018a(*), 
    //                                                                                                         _DestructExceptionObject:0055039a(
    //                                                                                                         terminate:0055049a(*), 
    //                                                                                                         _inconsistency:0055053a(*)  
    //         00554df8     PUSH       EBP
    //         00554df9     MOV        EBP,ESP
    //         00554dfb     SUB        ESP,0x8
    //         00554dfe     PUSH       EBX
    //         00554dff     PUSH       ESI
    //         00554e00     PUSH       EDI
    //         00554e01     PUSH       EBP
    //         00554e02     CLD
    //         00554e03     MOV        EBX,dword ptr [EBP + Stack[0x8]]
    //         00554e06     MOV        EAX,dword ptr [EBP + Stack[0x4]]
    //         00554e09     TEST       dword ptr [EAX + 0x4],0x6
    //         00554e10     JNZ        LAB_00554e98
    //         00554e16     MOV        dword ptr [EBP + local_c],EAX
    //         00554e19     MOV        EAX,dword ptr [EBP + Stack[0xc]]
    //         00554e1c     MOV        dword ptr [EBP + local_8],EAX
    //         00554e1f     LEA        EAX=>local_c,[EBP + -0x8]
    //         00554e22     MOV        dword ptr [EBX + -0x4],EAX
    //         00554e25     MOV        ESI,dword ptr [EBX + 0xc]
    //         00554e28     MOV        EDI,dword ptr [EBX + 0x8]
    //                               LAB_00554e2b                                                 XREF[1]:     00554e88(j)  
    //         00554e2b     CMP        ESI,-0x1
    //         00554e2e     JZ         LAB_00554e91
    //         00554e30     LEA        ECX,[ESI + ESI*0x2]
    //         00554e33     CMP        dword ptr [EDI + ECX*0x4 + 0x4],0x0
    //         00554e38     JZ         LAB_00554e7f
    //         00554e3a     PUSH       ESI
    //         00554e3b     PUSH       EBP=>DAT_fffffff8
    //         00554e3c     LEA        EBP,[EBX + 0x10]
    //         00554e3f     CALL       dword ptr [EDI + ECX*0x4 + 0x4]
    //         00554e43     POP        EBP
    //         00554e44     POP        ESI
    //         00554e45     MOV        EBX,dword ptr [EBP + 0xc]
    //         00554e48     OR         EAX,EAX
    //         00554e4a     JZ         LAB_00554e7f
    //         00554e4c     JS         LAB_00554e8a
    //         00554e4e     MOV        EDI,dword ptr [EBX + 0x8]
    //         00554e51     PUSH       EBX
    //         00554e52     CALL       __global_unwind2                                 undefined __global_unwind2()
    //         00554e57     ADD        ESP,0x4
    //         00554e5a     LEA        EBP,[EBX + 0x10]
    //         00554e5d     PUSH       ESI
    //         00554e5e     PUSH       EBX
    //         00554e5f     CALL       __local_unwind2                                  undefined __local_unwind2()
    //         00554e64     ADD        ESP,0x8
    //         00554e67     LEA        ECX,[ESI + ESI*0x2]
    //         00554e6a     PUSH       0x1
    //         00554e6c     MOV        EAX,dword ptr [EDI + ECX*0x4 + 0x8]
    //         00554e70     CALL       __NLG_Notify                                     undefined __NLG_Notify()
    //         00554e75     MOV        EAX,dword ptr [EDI + ECX*0x4]
    //         00554e78     MOV        dword ptr [EBX + 0xc],EAX
    //         00554e7b     CALL       dword ptr [EDI + ECX*0x4 + 0x8]
    //                               LAB_00554e7f                                                 XREF[2]:     00554e38(j), 00554e4a(j)  
    //         00554e7f     MOV        EDI,dword ptr [EBX + 0x8]
    //         00554e82     LEA        ECX,[ESI + ESI*0x2]
    //         00554e85     MOV        ESI,dword ptr [EDI + ECX*0x4]
    //         00554e88     JMP        LAB_00554e2b
    //                               LAB_00554e8a                                                 XREF[1]:     00554e4c(j)  
    //         00554e8a     MOV        EAX,0x0
    //         00554e8f     JMP        LAB_00554ead
    //                               LAB_00554e91                                                 XREF[1]:     00554e2e(j)  
    //         00554e91     MOV        EAX,0x1
    //         00554e96     JMP        LAB_00554ead
    //                               LAB_00554e98                                                 XREF[1]:     00554e10(j)  
    //         00554e98     PUSH       EBP
    //         00554e99     LEA        EBP,[EBX + 0x10]
    //         00554e9c     PUSH       -0x1
    //         00554e9e     PUSH       EBX
    //         00554e9f     CALL       __local_unwind2                                  undefined __local_unwind2()
    //         00554ea4     ADD        ESP,0x8
    //         00554ea7     POP        EBP
    //         00554ea8     MOV        EAX,0x1
    //                               LAB_00554ead                                                 XREF[2]:     00554e8f(j), 00554e96(j)  
    //         00554ead     POP        EBP
    //         00554eae     POP        EDI
    //         00554eaf     POP        ESI
    //         00554eb0     POP        EBX
    //         00554eb1     MOV        ESP,EBP
    //         00554eb3     POP        EBP
    //         00554eb4     RET
}

// Offset: 0x00554EB5
undefined seh_longjmp_unwind_4() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined __seh_longjmp_unwind@4()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               __seh_longjmp_unwind@4
    //         00554eb5     PUSH       EBP
    //         00554eb6     MOV        ECX,dword ptr [ESP + Stack[0x4]]
    //         00554eba     MOV        EBP,dword ptr [ECX]
    //         00554ebc     MOV        EAX,dword ptr [ECX + 0x1c]
    //         00554ebf     PUSH       EAX
    //         00554ec0     MOV        EAX,dword ptr [ECX + 0x18]
    //         00554ec3     PUSH       EAX
    //         00554ec4     CALL       __local_unwind2                                  undefined __local_unwind2()
    //         00554ec9     ADD        ESP,0x8
    //         00554ecc     POP        EBP
    //         00554ecd     RET        0x4
}

// Offset: 0x00554ED0
undefined fltin() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined __fltin()
    //              undefined         <UNASSIGNED>   <RETURN>
    //              undefined         Stack[-0xc]:1  local_c                   XREF[2]:     00554ed7(*), 00554f15(*)  
    //              undefined8        Stack[-0x14]:8 local_14                  XREF[3,1]:   00554eff(W), 00554f11(*), 00554f60(R), 00554f07(W)  
    //                               __fltin                                                      XREF[1]:     atof:0054e229(c)  
    //         00554ed0     SUB        ESP,0x14
    //         00554ed3     LEA        EAX=>Stack[0x4],[ESP + 0x18]
    //         00554ed7     LEA        ECX=>local_c,[ESP + 0x8]
    //         00554edb     PUSH       EBX
    //         00554edc     PUSH       EBP
    //         00554edd     MOV        EBP,dword ptr [ESP + Stack[0x4]]
    //         00554ee1     PUSH       ESI
    //         00554ee2     XOR        ESI,ESI
    //         00554ee4     PUSH       ESI
    //         00554ee5     PUSH       ESI
    //         00554ee6     PUSH       ESI
    //         00554ee7     PUSH       ESI
    //         00554ee8     PUSH       EBP
    //         00554ee9     PUSH       EAX
    //         00554eea     PUSH       ECX
    //         00554eeb     CALL       ___strgtold12                                    undefined ___strgtold12()
    //         00554ef0     MOV        EBX,EAX
    //         00554ef2     ADD        ESP,0x1c
    //         00554ef5     TEST       BL,0x4
    //         00554ef8     JZ         LAB_00554f11
    //         00554efa     MOV        ESI,0x200
    //         00554eff     MOV        dword ptr [ESP + local_14],0x0
    //         00554f07     MOV        dword ptr [ESP + local_14+0x4],0x0
    //         00554f0f     JMP        LAB_00554f42
    //                               LAB_00554f11                                                 XREF[1]:     00554ef8(j)  
    //         00554f11     LEA        EDX=>local_14,[ESP + 0xc]
    //         00554f15     LEA        EAX=>local_c,[ESP + 0x14]
    //         00554f19     PUSH       EDX
    //         00554f1a     PUSH       EAX
    //         00554f1b     CALL       __ld12tod                                        undefined __ld12tod()
    //         00554f20     ADD        ESP,0x8
    //         00554f23     TEST       BL,0x2
    //         00554f26     JNZ        LAB_00554f2d
    //         00554f28     CMP        EAX,0x1
    //         00554f2b     JNZ        LAB_00554f32
    //                               LAB_00554f2d                                                 XREF[1]:     00554f26(j)  
    //         00554f2d     MOV        ESI,0x80
    //                               LAB_00554f32                                                 XREF[1]:     00554f2b(j)  
    //         00554f32     TEST       BL,0x1
    //         00554f35     JNZ        LAB_00554f3c
    //         00554f37     CMP        EAX,0x2
    //         00554f3a     JNZ        LAB_00554f42
    //                               LAB_00554f3c                                                 XREF[1]:     00554f35(j)  
    //         00554f3c     OR         ESI,0x100
    //                               LAB_00554f42                                                 XREF[2]:     00554f0f(j), 00554f3a(j)  
    //         00554f42     MOV        ECX,dword ptr [PTR_DAT_00592454]                 = 00888298
    //         00554f48     MOV        dword ptr [ECX]=>DAT_00888298,ESI
    //         00554f4a     MOV        EDX,dword ptr [ESP + Stack[0x4]]
    //         00554f4e     MOV        EAX,[PTR_DAT_00592454]                           = 00888298
    //         00554f53     SUB        EDX,EBP
    //         00554f55     POP        ESI
    //         00554f56     POP        EBP
    //         00554f57     MOV        dword ptr [EAX + 0x4]=>DAT_0088829c,EDX
    //         00554f5a     MOV        ECX,dword ptr [PTR_DAT_00592454]                 = 00888298
    //         00554f60     FLD        double ptr [ESP + local_14]
    //         00554f64     POP        EBX
    //         00554f65     FSTP       double ptr [ECX + 0x10]=>DAT_008882a8
    //         00554f68     MOV        EAX=>DAT_00888298,[PTR_DAT_00592454]             = 00888298
    //         00554f6d     ADD        ESP,0x14
    //         00554f70     RET
}

// Offset: 0x00554F71
undefined FUN_00554f71() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00554f71()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00554f71
    //         00554f71     NOP
    //         00554f72     NOP
    //         00554f73     NOP
    //         00554f74     NOP
    //         00554f75     NOP
    //         00554f76     NOP
    //         00554f77     NOP
    //         00554f78     NOP
    //         00554f79     NOP
    //         00554f7a     NOP
    //         00554f7b     NOP
    //         00554f7c     NOP
    //         00554f7d     NOP
    //         00554f7e     NOP
    //         00554f7f     NOP
    //                               ___crtLCMapStringW
    //         00554f80     MOV        EAX,[DAT_008882b0]                               = align(4)
    //         00554f85     PUSH       EBX
    //         00554f86     MOV        EBX,dword ptr [->KERNEL32.DLL::LCMapStringW]     = 0048b920
    //         00554f8c     PUSH       EBP
    //         00554f8d     PUSH       ESI
    //         00554f8e     PUSH       EDI
    //         00554f8f     TEST       EAX,EAX
    //         00554f91     JNZ        LAB_00554fdc
    //         00554f93     PUSH       0x0
    //         00554f95     PUSH       0x0
    //         00554f97     PUSH       0x1
    //         00554f99     PUSH       u_                                               = u""
    //         00554f9e     PUSH       0x100
    //         00554fa3     PUSH       0x0
    //         00554fa5     CALL       EBX=>KERNEL32.DLL::LCMapStringW
    //         00554fa7     TEST       EAX,EAX
    //         00554fa9     JZ         LAB_00554fb2
    //         00554fab     MOV        EAX,0x1
    //         00554fb0     JMP        LAB_00554fd7
    //                               LAB_00554fb2                                                 XREF[1]:     00554fa9(j)  
    //         00554fb2     PUSH       0x0
    //         00554fb4     PUSH       0x0=>DAT_fffffff8
    //         00554fb6     PUSH       offset DAT_fffffff4
    //         00554fb8     PUSH       offset DAT_fffffff0                              = ""
    //         00554fbd     PUSH       0x100
    //         00554fc2     PUSH       0x0
    //         00554fc4     CALL       dword ptr [->KERNEL32.DLL::LCMapStringA]         = 0048b910
    //         00554fca     TEST       EAX,EAX
    //         00554fcc     JZ         LAB_00555180
    //         00554fd2     MOV        EAX,0x2
    //                               LAB_00554fd7                                                 XREF[1]:     00554fb0(j)  
    //         00554fd7     MOV        [DAT_008882b0],EAX                               = align(4)
    //                               LAB_00554fdc                                                 XREF[1]:     00554f91(j)  
    //         00554fdc     MOV        ESI,dword ptr [ESP + Stack[0x10]]
    //         00554fe0     TEST       ESI,ESI
    //         00554fe2     JLE        LAB_00554ffb
    //         00554fe4     MOV        EDI,dword ptr [ESP + Stack[0xc]]
    //         00554fe8     PUSH       ESI
    //         00554fe9     PUSH       EDI=>DAT_fffffff8
    //         00554fea     CALL       FUN_00555190                                     undefined FUN_00555190()
    //         00554fef     MOV        ESI,EAX
    //         00554ff1     MOV        EAX,[DAT_008882b0]                               = align(4)
    //         00554ff6     ADD        ESP,0x8
    //         00554ff9     JMP        LAB_00554fff
    //                               LAB_00554ffb                                                 XREF[1]:     00554fe2(j)  
    //         00554ffb     MOV        EDI,dword ptr [ESP + 0x1c]
    //                               LAB_00554fff                                                 XREF[1]:     00554ff9(j)  
    //         00554fff     CMP        EAX,0x1
    //         00555002     JNZ        LAB_00555021
    //         00555004     MOV        EAX,dword ptr [ESP + 0x28]
    //         00555008     MOV        ECX,dword ptr [ESP + 0x24]
    //         0055500c     MOV        EDX,dword ptr [ESP + 0x18]
    //         00555010     PUSH       EAX
    //         00555011     MOV        EAX,dword ptr [ESP + 0x18]
    //         00555015     PUSH       ECX=>DAT_fffffff8
    //         00555016     PUSH       ESI=>DAT_fffffff4
    //         00555017     PUSH       EDI=>DAT_fffffff0
    //         00555018     PUSH       EDX
    //         00555019     PUSH       EAX
    //         0055501a     CALL       EBX=>KERNEL32.DLL::LCMapStringW
    //         0055501c     POP        EDI
    //         0055501d     POP        ESI
    //         0055501e     POP        EBP
    //         0055501f     POP        EBX
    //         00555020     RET
    //                               LAB_00555021                                                 XREF[1]:     00555002(j)  
    //         00555021     CMP        EAX,0x2
    //         00555024     JNZ        LAB_00555129
    //         0055502a     MOV        EBX,dword ptr [ESP + 0x2c]
    //         0055502e     MOV        dword ptr [ESP + 0x20],0x0
    //         00555036     TEST       EBX,EBX
    //         00555038     JNZ        LAB_00555040
    //         0055503a     MOV        EBX,dword ptr [___lc_codepage]
    //                               LAB_00555040                                                 XREF[1]:     00555038(j)  
    //         00555040     PUSH       0x0
    //         00555042     PUSH       0x0=>DAT_fffffff8
    //         00555044     PUSH       0x0=>DAT_fffffff4
    //         00555046     PUSH       0x0=>DAT_fffffff0
    //         00555048     PUSH       ESI
    //         00555049     PUSH       EDI
    //         0055504a     PUSH       0x220
    //         0055504f     PUSH       EBX
    //         00555050     CALL       dword ptr [->KERNEL32.DLL::WideCharToMultiByte]  = 0048b8a0
    //         00555056     MOV        EDI,EAX
    //         00555058     TEST       EDI,EDI
    //         0055505a     JNZ        LAB_00555061
    //         0055505c     POP        EDI
    //         0055505d     POP        ESI
    //         0055505e     POP        EBP
    //         0055505f     POP        EBX
    //         00555060     RET
    //                               LAB_00555061                                                 XREF[1]:     0055505a(j)  
    //         00555061     PUSH       EDI
    //         00555062     CALL       malloc                                           undefined malloc()
    //         00555067     MOV        EBP,EAX
    //         00555069     ADD        ESP,0x4
    //         0055506c     TEST       EBP,EBP
    //         0055506e     JNZ        LAB_00555075
    //         00555070     POP        EDI
    //         00555071     POP        ESI
    //         00555072     POP        EBP
    //         00555073     POP        EBX
    //         00555074     RET
    //                               LAB_00555075                                                 XREF[1]:     0055506e(j)  
    //         00555075     MOV        ECX,dword ptr [ESP + 0x1c]
    //         00555079     PUSH       0x0
    //         0055507b     PUSH       0x0=>DAT_fffffff8
    //         0055507d     PUSH       EDI=>DAT_fffffff4
    //         0055507e     PUSH       EBP=>DAT_fffffff0
    //         0055507f     PUSH       ESI
    //         00555080     PUSH       ECX
    //         00555081     PUSH       0x220
    //         00555086     PUSH       EBX
    //         00555087     CALL       dword ptr [->KERNEL32.DLL::WideCharToMultiByte]  = 0048b8a0
    //         0055508d     TEST       EAX,EAX
    //         0055508f     JZ         LAB_0055516a
    //         00555095     MOV        EDX,dword ptr [ESP + 0x18]
    //         00555099     MOV        EAX,dword ptr [ESP + 0x14]
    //         0055509d     PUSH       0x0
    //         0055509f     PUSH       0x0=>DAT_fffffff8
    //         005550a1     PUSH       EDI=>DAT_fffffff4
    //         005550a2     PUSH       EBP=>DAT_fffffff0
    //         005550a3     PUSH       EDX
    //         005550a4     PUSH       EAX
    //         005550a5     CALL       dword ptr [->KERNEL32.DLL::LCMapStringA]         = 0048b910
    //         005550ab     MOV        ESI,EAX
    //         005550ad     TEST       ESI,ESI
    //         005550af     JZ         LAB_0055516a
    //         005550b5     PUSH       ESI
    //         005550b6     CALL       malloc                                           undefined malloc()
    //         005550bb     ADD        ESP,0x4
    //         005550be     MOV        dword ptr [ESP + 0x20],EAX
    //         005550c2     TEST       EAX,EAX
    //         005550c4     JZ         LAB_0055516a
    //         005550ca     MOV        ECX,dword ptr [ESP + 0x14]
    //         005550ce     PUSH       ESI
    //         005550cf     PUSH       EAX=>DAT_fffffff8
    //         005550d0     PUSH       EDI=>DAT_fffffff4
    //         005550d1     MOV        EDI,dword ptr [ESP + 0x24]
    //         005550d5     PUSH       EBP=>DAT_fffffff0
    //         005550d6     PUSH       EDI
    //         005550d7     PUSH       ECX
    //         005550d8     CALL       dword ptr [->KERNEL32.DLL::LCMapStringA]         = 0048b910
    //         005550de     TEST       EAX,EAX
    //         005550e0     JZ         LAB_0055516a
    //         005550e6     TEST       EDI,0x400
    //         005550ec     JZ         LAB_0055512e
    //         005550ee     MOV        EAX,dword ptr [ESP + 0x28]
    //         005550f2     MOV        EDI,ESI
    //         005550f4     TEST       EAX,EAX
    //         005550f6     JZ         LAB_00555111
    //         005550f8     CMP        EAX,ESI
    //         005550fa     JL         LAB_005550fe
    //         005550fc     MOV        EAX,ESI
    //                               LAB_005550fe                                                 XREF[1]:     005550fa(j)  
    //         005550fe     MOV        EDX,dword ptr [ESP + 0x20]
    //         00555102     PUSH       EAX
    //         00555103     MOV        EAX,dword ptr [ESP + 0x28]
    //         00555107     PUSH       EDX=>DAT_fffffff8
    //         00555108     PUSH       EAX=>DAT_fffffff4
    //         00555109     CALL       strncpy                                          undefined strncpy()
    //         0055510e     ADD        ESP,0xc
    //                               LAB_00555111                                                 XREF[3]:     005550f6(j), 0055514d(j), 
    //                                                                                                         00555168(j)  
    //         00555111     PUSH       EBP
    //         00555112     CALL       free                                             undefined free()
    //         00555117     MOV        EDX,dword ptr [ESP + 0x24]
    //         0055511b     ADD        ESP,0x4
    //         0055511e     PUSH       EDX
    //         0055511f     CALL       free                                             undefined free()
    //         00555124     ADD        ESP,0x4
    //         00555127     MOV        EAX,EDI
    //                               LAB_00555129                                                 XREF[1]:     00555024(j)  
    //         00555129     POP        EDI
    //         0055512a     POP        ESI
    //         0055512b     POP        EBP
    //         0055512c     POP        EBX
    //         0055512d     RET
    //                               LAB_0055512e                                                 XREF[1]:     005550ec(j)  
    //         0055512e     MOV        EAX,dword ptr [ESP + 0x28]
    //         00555132     TEST       EAX,EAX
    //         00555134     JNZ        LAB_0055514f
    //         00555136     MOV        ECX,dword ptr [ESP + 0x20]
    //         0055513a     PUSH       EAX
    //         0055513b     PUSH       EAX=>DAT_fffffff8
    //         0055513c     PUSH       ESI=>DAT_fffffff4
    //         0055513d     PUSH       ECX=>DAT_fffffff0
    //         0055513e     PUSH       0x1
    //         00555140     PUSH       EBX
    //         00555141     CALL       dword ptr [->KERNEL32.DLL::MultiByteToWideChar]  = 0048b8da
    //         00555147     MOV        EDI,EAX
    //         00555149     TEST       EDI,EDI
    //         0055514b     JZ         LAB_0055516a
    //         0055514d     JMP        LAB_00555111
    //                               LAB_0055514f                                                 XREF[1]:     00555134(j)  
    //         0055514f     MOV        EDX,dword ptr [ESP + 0x24]
    //         00555153     PUSH       EAX
    //         00555154     MOV        EAX,dword ptr [ESP + 0x24]
    //         00555158     PUSH       EDX=>DAT_fffffff8
    //         00555159     PUSH       ESI=>DAT_fffffff4
    //         0055515a     PUSH       EAX=>DAT_fffffff0
    //         0055515b     PUSH       0x1
    //         0055515d     PUSH       EBX
    //         0055515e     CALL       dword ptr [->KERNEL32.DLL::MultiByteToWideChar]  = 0048b8da
    //         00555164     MOV        EDI,EAX
    //         00555166     TEST       EDI,EDI
    //         00555168     JNZ        LAB_00555111
    //                               LAB_0055516a                                                 XREF[5]:     0055508f(j), 005550af(j), 
    //                                                                                                         005550c4(j), 005550e0(j), 
    //                                                                                                         0055514b(j)  
    //         0055516a     PUSH       EBP
    //         0055516b     CALL       free                                             undefined free()
    //         00555170     MOV        ECX,dword ptr [ESP + 0x24]
    //         00555174     ADD        ESP,0x4
    //         00555177     PUSH       ECX
    //         00555178     CALL       free                                             undefined free()
    //         0055517d     ADD        ESP,0x4
    //                               LAB_00555180                                                 XREF[1]:     00554fcc(j)  
    //         00555180     POP        EDI
    //         00555181     POP        ESI
    //         00555182     POP        EBP
    //         00555183     XOR        EAX,EAX
    //         00555185     POP        EBX
    //         00555186     RET
}

