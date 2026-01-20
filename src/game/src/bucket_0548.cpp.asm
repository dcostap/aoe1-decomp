// Auto-generated scaffold unit: bucket_0548.cpp.asm
#include "../include/common.h"

// Offset: 0x00548030
undefined FUN_00548030() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00548030()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00548030                                                 XREF[1]:     FUN_00547b30:00547c3b(c)  
    //         00548030     MOV        EAX,[DAT_00887a80]
    //         00548035     MOV        EAX,dword ptr [EAX + 0x36710]
    //         0054803b     CMP        EAX,0x20
    //         0054803e     JZ         LAB_005480a5
    //         00548040     MOV        ECX,dword ptr [DAT_00887a80]
    //         00548046     MOV        EDX,0x20
    //         0054804b     SUB        EDX,EAX
    //         0054804d     ADD        dword ptr [ECX + 0x36108],EDX
    //         00548053     MOV        ECX,dword ptr [DAT_00887a80]
    //         00548059     CMP        dword ptr [ECX + 0x36710],0x0
    //         00548060     JZ         LAB_0054808a
    //         00548062     XOR        ECX,ECX
    //                               LAB_00548064                                                 XREF[1]:     00548088(j)  
    //         00548064     MOV        EAX,[DAT_00887a80]
    //         00548069     MOV        EDX,dword ptr [EAX + 0x3670c]
    //         0054806f     SHL        dword ptr [EDX],0x1
    //         00548072     MOV        EAX,[DAT_00887a80]
    //         00548077     DEC        dword ptr [EAX + 0x36710]
    //         0054807d     MOV        EAX,[DAT_00887a80]
    //         00548082     CMP        dword ptr [EAX + 0x36710],ECX
    //         00548088     JNZ        LAB_00548064
    //                               LAB_0054808a                                                 XREF[1]:     00548060(j)  
    //         0054808a     MOV        EAX,[DAT_00887a80]
    //         0054808f     ADD        dword ptr [EAX + 0x3670c],0x4
    //         00548096     MOV        EAX,[DAT_00887a80]
    //         0054809b     MOV        dword ptr [EAX + 0x36710],0x20
    //                               LAB_005480a5                                                 XREF[1]:     0054803e(j)  
    //         005480a5     PUSH       0x1
    //         005480a7     CALL       FUN_005480b0                                     undefined FUN_005480b0()
    //         005480ac     ADD        ESP,0x4
    //         005480af     RET
}

// Offset: 0x005480B0
undefined FUN_005480b0() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_005480b0()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_005480b0                                                 XREF[2]:     FUN_00548030:005480a7(c), 
    //                                                                                                         FUN_00549b20:00549b5a(c)  
    //         005480b0     PUSH       ESI
    //         005480b1     MOV        EAX,[DAT_00887a80]
    //         005480b6     MOV        EDX,dword ptr [EAX + 0x38120]
    //         005480bc     MOV        dword ptr [EAX + 0x36718],EDX
    //         005480c2     MOV        EAX,[DAT_00887a80]
    //         005480c7     CMP        dword ptr [EAX + 0x36108],0x0
    //         005480ce     JZ         LAB_00548360
    //         005480d4     PUSH       0x1
    //         005480d6     PUSH       0x0
    //         005480d8     CALL       FUN_00547d80                                     undefined FUN_00547d80()
    //         005480dd     ADD        ESP,0x8
    //         005480e0     TEST       EAX,EAX
    //         005480e2     JZ         LAB_005480eb
    //         005480e4     MOV        EAX,0x1
    //         005480e9     POP        ESI
    //         005480ea     RET
    //                               LAB_005480eb                                                 XREF[1]:     005480e2(j)  
    //         005480eb     MOV        EAX,[DAT_00887a80]
    //         005480f0     MOV        EAX,dword ptr [EAX + 0x38138]
    //         005480f6     TEST       EAX,EAX
    //         005480f8     JNZ        LAB_00548123
    //         005480fa     CALL       FUN_00548660                                     undefined FUN_00548660()
    //         005480ff     CALL       FUN_005488f0                                     undefined FUN_005488f0()
    //         00548104     TEST       EAX,EAX
    //         00548106     JZ         LAB_0054810f
    //         00548108     MOV        EAX,0x1
    //         0054810d     POP        ESI
    //         0054810e     RET
    //                               LAB_0054810f                                                 XREF[1]:     00548106(j)  
    //         0054810f     CALL       FUN_00548410                                     undefined FUN_00548410()
    //         00548114     TEST       EAX,EAX
    //         00548116     JZ         LAB_00548360
    //         0054811c     MOV        EAX,0x1
    //         00548121     POP        ESI
    //         00548122     RET
    //                               LAB_00548123                                                 XREF[1]:     005480f8(j)  
    //         00548123     CMP        EAX,0x1
    //         00548126     JNZ        LAB_00548151
    //         00548128     CALL       FUN_00548910                                     undefined FUN_00548910()
    //         0054812d     CALL       FUN_00549120                                     undefined FUN_00549120()
    //         00548132     TEST       EAX,EAX
    //         00548134     JZ         LAB_0054813d
    //         00548136     MOV        EAX,0x1
    //         0054813b     POP        ESI
    //         0054813c     RET
    //                               LAB_0054813d                                                 XREF[1]:     00548134(j)  
    //         0054813d     CALL       FUN_00548410                                     undefined FUN_00548410()
    //         00548142     TEST       EAX,EAX
    //         00548144     JZ         LAB_00548360
    //         0054814a     MOV        EAX,0x1
    //         0054814f     POP        ESI
    //         00548150     RET
    //                               LAB_00548151                                                 XREF[1]:     00548126(j)  
    //         00548151     MOV        EAX,[DAT_00887a80]
    //         00548156     CMP        dword ptr [EAX + 0x36108],0x80
    //         00548160     JGE        LAB_0054827f
    //         00548166     MOV        dword ptr [DAT_00887a84],0x1
    //         00548170     MOV        dword ptr [EAX + 0x3811c],0x0
    //         0054817a     CALL       FUN_00548660                                     undefined FUN_00548660()
    //         0054817f     CALL       FUN_005488f0                                     undefined FUN_005488f0()
    //         00548184     TEST       EAX,EAX
    //         00548186     JZ         LAB_0054818f
    //         00548188     MOV        EAX,0x1
    //         0054818d     POP        ESI
    //         0054818e     RET
    //                               LAB_0054818f                                                 XREF[1]:     00548186(j)  
    //         0054818f     CALL       FUN_00548410                                     undefined FUN_00548410()
    //         00548194     TEST       EAX,EAX
    //         00548196     JZ         LAB_0054819f
    //         00548198     MOV        EAX,0x1
    //         0054819d     POP        ESI
    //         0054819e     RET
    //                               LAB_0054819f                                                 XREF[1]:     00548196(j)  
    //         0054819f     MOV        EAX,[DAT_00887a80]
    //         005481a4     MOV        ESI,dword ptr [EAX + 0x3811c]
    //         005481aa     MOV        dword ptr [EAX + 0x3811c],0x0
    //         005481b4     ADD        EAX,0x3811c
    //         005481b9     CALL       FUN_00548910                                     undefined FUN_00548910()
    //         005481be     CALL       FUN_00549120                                     undefined FUN_00549120()
    //         005481c3     TEST       EAX,EAX
    //         005481c5     JZ         LAB_005481ce
    //         005481c7     MOV        EAX,0x1
    //         005481cc     POP        ESI
    //         005481cd     RET
    //                               LAB_005481ce                                                 XREF[1]:     005481c5(j)  
    //         005481ce     CALL       FUN_00548410                                     undefined FUN_00548410()
    //         005481d3     TEST       EAX,EAX
    //         005481d5     JZ         LAB_005481de
    //         005481d7     MOV        EAX,0x1
    //         005481dc     POP        ESI
    //         005481dd     RET
    //                               LAB_005481de                                                 XREF[1]:     005481d5(j)  
    //         005481de     MOV        EAX,[DAT_00887a80]
    //         005481e3     MOV        EDX,dword ptr [EAX + 0x3811c]
    //         005481e9     MOV        dword ptr [DAT_00887a84],0x0
    //         005481f3     MOV        EAX,dword ptr [EAX + 0x3671c]
    //         005481f9     LEA        ECX,[EAX*0x8 + 0x22]
    //         00548200     MOV        EAX,[DAT_00886cf4]
    //         00548205     ADD        EAX,0x2
    //         00548208     AND        EAX,0x7
    //         0054820b     JZ         LAB_00548212
    //         0054820d     SUB        ECX,EAX
    //         0054820f     ADD        ECX,0x8
    //                               LAB_00548212                                                 XREF[1]:     0054820b(j)  
    //         00548212     CMP        ECX,ESI
    //         00548214     JNC        LAB_0054822e
    //         00548216     CMP        ECX,EDX
    //         00548218     JNC        LAB_0054822e
    //         0054821a     CALL       FUN_005492f0                                     undefined FUN_005492f0()
    //         0054821f     TEST       EAX,EAX
    //         00548221     JZ         LAB_00548360
    //         00548227     MOV        EAX,0x1
    //         0054822c     POP        ESI
    //         0054822d     RET
    //                               LAB_0054822e                                                 XREF[2]:     00548214(j), 00548218(j)  
    //         0054822e     CMP        EDX,ESI
    //         00548230     JBE        LAB_0054825b
    //         00548232     CALL       FUN_00548660                                     undefined FUN_00548660()
    //         00548237     CALL       FUN_005488f0                                     undefined FUN_005488f0()
    //         0054823c     TEST       EAX,EAX
    //         0054823e     JZ         LAB_00548247
    //         00548240     MOV        EAX,0x1
    //         00548245     POP        ESI
    //         00548246     RET
    //                               LAB_00548247                                                 XREF[1]:     0054823e(j)  
    //         00548247     CALL       FUN_00548410                                     undefined FUN_00548410()
    //         0054824c     TEST       EAX,EAX
    //         0054824e     JZ         LAB_00548360
    //         00548254     MOV        EAX,0x1
    //         00548259     POP        ESI
    //         0054825a     RET
    //                               LAB_0054825b                                                 XREF[1]:     00548230(j)  
    //         0054825b     CALL       FUN_00549120                                     undefined FUN_00549120()
    //         00548260     TEST       EAX,EAX
    //         00548262     JZ         LAB_0054826b
    //         00548264     MOV        EAX,0x1
    //         00548269     POP        ESI
    //         0054826a     RET
    //                               LAB_0054826b                                                 XREF[1]:     00548262(j)  
    //         0054826b     CALL       FUN_00548410                                     undefined FUN_00548410()
    //         00548270     TEST       EAX,EAX
    //         00548272     JZ         LAB_00548360
    //         00548278     MOV        EAX,0x1
    //         0054827d     POP        ESI
    //         0054827e     RET
    //                               LAB_0054827f                                                 XREF[1]:     00548160(j)  
    //         0054827f     MOV        EAX,[DAT_00887a80]
    //         00548284     CMP        dword ptr [EAX + 0x3671c],0x3999
    //         0054828e     JL         LAB_005482b9
    //         00548290     CALL       FUN_00548910                                     undefined FUN_00548910()
    //         00548295     CALL       FUN_00549120                                     undefined FUN_00549120()
    //         0054829a     TEST       EAX,EAX
    //         0054829c     JZ         LAB_005482a5
    //         0054829e     MOV        EAX,0x1
    //         005482a3     POP        ESI
    //         005482a4     RET
    //                               LAB_005482a5                                                 XREF[1]:     0054829c(j)  
    //         005482a5     CALL       FUN_00548410                                     undefined FUN_00548410()
    //         005482aa     TEST       EAX,EAX
    //         005482ac     JZ         LAB_00548360
    //         005482b2     MOV        EAX,0x1
    //         005482b7     POP        ESI
    //         005482b8     RET
    //                               LAB_005482b9                                                 XREF[1]:     0054828e(j)  
    //         005482b9     MOV        EAX,[DAT_00887a80]
    //         005482be     MOV        dword ptr [DAT_00887a84],0x1
    //         005482c8     MOV        dword ptr [EAX + 0x3811c],0x0
    //         005482d2     CALL       FUN_00548910                                     undefined FUN_00548910()
    //         005482d7     CALL       FUN_00549120                                     undefined FUN_00549120()
    //         005482dc     TEST       EAX,EAX
    //         005482de     JZ         LAB_005482e7
    //         005482e0     MOV        EAX,0x1
    //         005482e5     POP        ESI
    //         005482e6     RET
    //                               LAB_005482e7                                                 XREF[1]:     005482de(j)  
    //         005482e7     CALL       FUN_00548410                                     undefined FUN_00548410()
    //         005482ec     TEST       EAX,EAX
    //         005482ee     JZ         LAB_005482f7
    //         005482f0     MOV        EAX,0x1
    //         005482f5     POP        ESI
    //         005482f6     RET
    //                               LAB_005482f7                                                 XREF[1]:     005482ee(j)  
    //         005482f7     MOV        EAX,[DAT_00887a80]
    //         005482fc     MOV        EDX,dword ptr [EAX + 0x3811c]
    //         00548302     MOV        dword ptr [DAT_00887a84],0x0
    //         0054830c     MOV        ECX,dword ptr [EAX + 0x3671c]
    //         00548312     LEA        EAX,[ECX*0x8 + 0x22]
    //         00548319     MOV        ECX,dword ptr [DAT_00886cf4]
    //         0054831f     ADD        ECX,0x2
    //         00548322     AND        ECX,0x7
    //         00548325     JZ         LAB_0054832c
    //         00548327     SUB        EAX,ECX
    //         00548329     ADD        EAX,0x8
    //                               LAB_0054832c                                                 XREF[1]:     00548325(j)  
    //         0054832c     CMP        EAX,EDX
    //         0054832e     JNC        LAB_00548340
    //         00548330     CALL       FUN_005492f0                                     undefined FUN_005492f0()
    //         00548335     TEST       EAX,EAX
    //         00548337     JZ         LAB_00548360
    //         00548339     MOV        EAX,0x1
    //         0054833e     POP        ESI
    //         0054833f     RET
    //                               LAB_00548340                                                 XREF[1]:     0054832e(j)  
    //         00548340     CALL       FUN_00549120                                     undefined FUN_00549120()
    //         00548345     TEST       EAX,EAX
    //         00548347     JZ         LAB_00548350
    //         00548349     MOV        EAX,0x1
    //         0054834e     POP        ESI
    //         0054834f     RET
    //                               LAB_00548350                                                 XREF[1]:     00548347(j)  
    //         00548350     CALL       FUN_00548410                                     undefined FUN_00548410()
    //         00548355     TEST       EAX,EAX
    //         00548357     JZ         LAB_00548360
    //         00548359     MOV        EAX,0x1
    //         0054835e     POP        ESI
    //         0054835f     RET
    //                               LAB_00548360                                                 XREF[9]:     005480ce(j), 00548116(j), 
    //                                                                                                         00548144(j), 00548221(j), 
    //                                                                                                         0054824e(j), 00548272(j), 
    //                                                                                                         005482ac(j), 00548337(j), 
    //                                                                                                         00548357(j)  
    //         00548360     MOV        EAX,[DAT_00887a80]
    //         00548365     MOV        ECX,dword ptr [DAT_00887a80]
    //         0054836b     ADD        EAX,0x3610c
    //         00548370     MOV        dword ptr [ECX + 0x3670c],EAX
    //         00548376     MOV        EAX,[DAT_00887a80]
    //         0054837b     XOR        EDX,EDX
    //         0054837d     MOV        dword ptr [EAX + 0x36710],0x20
    //         00548387     MOV        EAX,[DAT_00887a80]
    //         0054838c     MOV        ECX,dword ptr [DAT_00887a80]
    //         00548392     ADD        EAX,0x2d102
    //         00548397     MOV        dword ptr [ECX + 0x36104],EAX
    //         0054839d     MOV        EAX,[DAT_00887a80]
    //         005483a2     CMP        dword ptr [ESP + Stack[0x4]],EDX
    //         005483a6     MOV        dword ptr [EAX + 0x36108],EDX
    //         005483ac     MOV        EAX,[DAT_00887a80]
    //         005483b1     MOV        dword ptr [EAX + 0x3671c],EDX
    //         005483b7     MOV        EAX,[DAT_00887a80]
    //         005483bc     MOV        ESI,dword ptr [EAX + 0x36718]
    //         005483c2     MOV        dword ptr [EAX + 0x36714],ESI
    //         005483c8     JZ         LAB_00548406
    //         005483ca     PUSH       0x1
    //         005483cc     PUSH       0x1
    //         005483ce     CALL       FUN_00547d80                                     undefined FUN_00547d80()
    //         005483d3     ADD        ESP,0x8
    //         005483d6     TEST       EAX,EAX
    //         005483d8     JZ         LAB_005483e1
    //         005483da     MOV        EAX,0x1
    //         005483df     POP        ESI
    //         005483e0     RET
    //                               LAB_005483e1                                                 XREF[1]:     005483d8(j)  
    //         005483e1     CALL       FUN_00548660                                     undefined FUN_00548660()
    //         005483e6     CALL       FUN_005488f0                                     undefined FUN_005488f0()
    //         005483eb     TEST       EAX,EAX
    //         005483ed     JZ         LAB_005483f6
    //         005483ef     MOV        EAX,0x1
    //         005483f4     POP        ESI
    //         005483f5     RET
    //                               LAB_005483f6                                                 XREF[1]:     005483ed(j)  
    //         005483f6     CALL       FUN_00548410                                     undefined FUN_00548410()
    //         005483fb     TEST       EAX,EAX
    //         005483fd     JZ         LAB_00548406
    //         005483ff     MOV        EAX,0x1
    //         00548404     POP        ESI
    //         00548405     RET
    //                               LAB_00548406                                                 XREF[2]:     005483c8(j), 005483fd(j)  
    //         00548406     XOR        EAX,EAX
    //         00548408     POP        ESI
    //         00548409     RET
}

// Offset: 0x00548410
undefined FUN_00548410() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00548410()
    //              undefined         <UNASSIGNED>   <RETURN>
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[3]:     00548445(W), 005485ce(RW), 005485d2(R)  
    //              undefined4        Stack[-0x8]:4  local_8                   XREF[4]:     00548413(W), 00548455(R), 0054845c(W), 005485ca(RW)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[4]:     0054843b(W), 00548451(R), 00548464(R), 00548468(RW)  
    //                               FUN_00548410                                                 XREF[10]:    FUN_005480b0:0054810f(c), 
    //                                                                                                         FUN_005480b0:0054813d(c), 
    //                                                                                                         FUN_005480b0:0054818f(c), 
    //                                                                                                         FUN_005480b0:005481ce(c), 
    //                                                                                                         FUN_005480b0:00548247(c), 
    //                                                                                                         FUN_005480b0:0054826b(c), 
    //                                                                                                         FUN_005480b0:005482a5(c), 
    //                                                                                                         FUN_005480b0:005482e7(c), 
    //                                                                                                         FUN_005480b0:00548350(c), 
    //                                                                                                         FUN_005480b0:005483f6(c)  
    //         00548410     SUB        ESP,0xc
    //         00548413     MOV        dword ptr [ESP + local_8],0x0
    //         0054841b     PUSH       EBX
    //         0054841c     MOV        EAX,[DAT_00887a80]
    //         00548421     PUSH       ESI
    //         00548422     ADD        EAX,0x3610c
    //         00548427     PUSH       EDI
    //         00548428     MOV        ESI,dword ptr [DAT_00887a80]
    //         0054842e     PUSH       EBP
    //         0054842f     ADD        ESI,0x2d102
    //         00548435     MOV        ECX,dword ptr [DAT_00887a80]
    //         0054843b     MOV        dword ptr [ESP + local_c],EAX
    //         0054843f     MOV        EDX,dword ptr [ECX + 0x36108]
    //         00548445     MOV        dword ptr [ESP + local_4],EDX
    //         00548449     TEST       EDX,EDX
    //         0054844b     JLE        LAB_005485dd
    //         00548451     MOV        EBP,dword ptr [ESP + local_c]
    //                               LAB_00548455                                                 XREF[1]:     005485d7(j)  
    //         00548455     CMP        dword ptr [ESP + local_8],0x0
    //         0054845a     JNZ        LAB_0054846f
    //         0054845c     MOV        dword ptr [ESP + local_8],0x20
    //         00548464     MOV        EAX,dword ptr [ESP + local_c]
    //         00548468     ADD        dword ptr [ESP + local_c],0x4
    //         0054846d     MOV        EBP,dword ptr [EAX]
    //                               LAB_0054846f                                                 XREF[1]:     0054845a(j)  
    //         0054846f     TEST       EBP,0x80000000
    //         00548475     JZ         LAB_0054859e
    //         0054847b     XOR        EBX,EBX
    //         0054847d     XOR        EDI,EDI
    //         0054847f     MOV        DI,word ptr [ESI + 0x1]
    //         00548483     MOV        BL,byte ptr [ESI]
    //         00548485     DEC        EDI
    //         00548486     XOR        EAX,EAX
    //         00548488     MOV        AX,word ptr [EBX*0x2 + DAT_0058ef48]             = 01h
    //         00548490     SHL        EAX,0x2
    //         00548493     ADD        EAX,dword ptr [DAT_00887a80]
    //         00548499     MOV        ECX,dword ptr [EAX + 0x36c6c]
    //         0054849f     MOV        EDX,dword ptr [EAX + 0x371b8]
    //         005484a5     PUSH       ECX
    //         005484a6     PUSH       EDX
    //         005484a7     CALL       FUN_00547d80                                     undefined FUN_00547d80()
    //         005484ac     ADD        ESP,0x8
    //         005484af     TEST       EAX,EAX
    //         005484b1     JNZ        LAB_00548606
    //         005484b7     XOR        EAX,EAX
    //         005484b9     MOV        AL,byte ptr [EBX + DAT_0058f148]
    //         005484bf     PUSH       EAX
    //         005484c0     XOR        EAX,EAX
    //         005484c2     MOV        AL,byte ptr [EBX + DAT_0058f248]
    //         005484c8     AND        EAX,EBX
    //         005484ca     PUSH       EAX
    //         005484cb     CALL       FUN_00547d80                                     undefined FUN_00547d80()
    //         005484d0     ADD        ESP,0x8
    //         005484d3     TEST       EAX,EAX
    //         005484d5     JNZ        LAB_00548613
    //         005484db     CMP        EDI,0x200
    //         005484e1     JNC        LAB_0054853f
    //         005484e3     XOR        EAX,EAX
    //         005484e5     MOV        AL,byte ptr [EDI + 0x58f348]=>DAT_0058f347
    //         005484eb     SHL        EAX,0x2
    //         005484ee     ADD        EAX,dword ptr [DAT_00887a80]
    //         005484f4     MOV        ECX,dword ptr [EAX + 0x370ec]
    //         005484fa     MOV        EDX,dword ptr [EAX + 0x37638]
    //         00548500     PUSH       ECX
    //         00548501     PUSH       EDX
    //         00548502     CALL       FUN_00547d80                                     undefined FUN_00547d80()
    //         00548507     ADD        ESP,0x8
    //         0054850a     TEST       EAX,EAX
    //         0054850c     JNZ        LAB_00548620
    //         00548512     XOR        EAX,EAX
    //         00548514     MOV        AL,byte ptr [EDI + 0x58f548]=>DAT_0058f547       = 11h
    //         0054851a     PUSH       EAX
    //         0054851b     XOR        EAX,EAX
    //         0054851d     MOV        AL,byte ptr [EDI + 0x58f748]=>DAT_0058f747       = 07h
    //         00548523     AND        EAX,EDI
    //         00548525     PUSH       EAX
    //         00548526     CALL       FUN_00547d80                                     undefined FUN_00547d80()
    //         0054852b     ADD        ESP,0x8
    //         0054852e     TEST       EAX,EAX
    //         00548530     JZ         LAB_00548599
    //         00548532     MOV        EAX,0x1
    //         00548537     POP        EBP
    //         00548538     POP        EDI
    //         00548539     POP        ESI
    //         0054853a     POP        EBX
    //         0054853b     ADD        ESP,0xc
    //         0054853e     RET
    //                               LAB_0054853f                                                 XREF[1]:     005484e1(j)  
    //         0054853f     MOV        EBX,EDI
    //         00548541     XOR        EAX,EAX
    //         00548543     SHR        EBX,0x8
    //         00548546     MOV        AL,byte ptr [EBX + DAT_0058f948]
    //         0054854c     SHL        EAX,0x2
    //         0054854f     ADD        EAX,dword ptr [DAT_00887a80]
    //         00548555     MOV        ECX,dword ptr [EAX + 0x370ec]
    //         0054855b     MOV        EDX,dword ptr [EAX + 0x37638]
    //         00548561     PUSH       ECX
    //         00548562     PUSH       EDX
    //         00548563     CALL       FUN_00547d80                                     undefined FUN_00547d80()
    //         00548568     ADD        ESP,0x8
    //         0054856b     TEST       EAX,EAX
    //         0054856d     JNZ        LAB_0054862d
    //         00548573     XOR        EAX,EAX
    //         00548575     MOV        AL,byte ptr [EBX + DAT_0058f9c8]
    //         0054857b     PUSH       EAX
    //         0054857c     XOR        EAX,EAX
    //         0054857e     MOV        AX,word ptr [EBX*0x2 + DAT_0058fa48]
    //         00548586     AND        EAX,EDI
    //         00548588     PUSH       EAX
    //         00548589     CALL       FUN_00547d80                                     undefined FUN_00547d80()
    //         0054858e     ADD        ESP,0x8
    //         00548591     TEST       EAX,EAX
    //         00548593     JNZ        LAB_0054863a
    //                               LAB_00548599                                                 XREF[1]:     00548530(j)  
    //         00548599     ADD        ESI,0x3
    //         0054859c     JMP        LAB_005485c8
    //                               LAB_0054859e                                                 XREF[1]:     00548475(j)  
    //         0054859e     MOV        AL,byte ptr [ESI]
    //         005485a0     INC        ESI
    //         005485a1     XOR        ECX,ECX
    //         005485a3     MOV        CL,AL
    //         005485a5     SHL        ECX,0x2
    //         005485a8     ADD        ECX,dword ptr [DAT_00887a80]
    //         005485ae     MOV        EAX,dword ptr [ECX + 0x36c6c]
    //         005485b4     MOV        EDX,dword ptr [ECX + 0x371b8]
    //         005485ba     PUSH       EAX
    //         005485bb     PUSH       EDX
    //         005485bc     CALL       FUN_00547d80                                     undefined FUN_00547d80()
    //         005485c1     ADD        ESP,0x8
    //         005485c4     TEST       EAX,EAX
    //         005485c6     JNZ        LAB_00548647
    //                               LAB_005485c8                                                 XREF[1]:     0054859c(j)  
    //         005485c8     ADD        EBP,EBP
    //         005485ca     DEC        dword ptr [ESP + local_8]
    //         005485ce     DEC        dword ptr [ESP + local_4]
    //         005485d2     CMP        dword ptr [ESP + local_4],0x0
    //         005485d7     JG         LAB_00548455
    //                               LAB_005485dd                                                 XREF[1]:     0054844b(j)  
    //         005485dd     MOV        EAX,[DAT_00887a80]
    //         005485e2     MOV        ECX,dword ptr [EAX + 0x3706c]
    //         005485e8     MOV        EDX,dword ptr [EAX + 0x375b8]
    //         005485ee     PUSH       ECX
    //         005485ef     PUSH       EDX
    //         005485f0     CALL       FUN_00547d80                                     undefined FUN_00547d80()
    //         005485f5     ADD        ESP,0x8
    //         005485f8     CMP        EAX,0x1
    //         005485fb     SBB        EAX,EAX
    //         005485fd     POP        EBP
    //         005485fe     INC        EAX
    //         005485ff     POP        EDI
    //         00548600     POP        ESI
    //         00548601     POP        EBX
    //         00548602     ADD        ESP,0xc
    //         00548605     RET
    //                               LAB_00548606                                                 XREF[1]:     005484b1(j)  
    //         00548606     MOV        EAX,0x1
    //         0054860b     POP        EBP
    //         0054860c     POP        EDI
    //         0054860d     POP        ESI
    //         0054860e     POP        EBX
    //         0054860f     ADD        ESP,0xc
    //         00548612     RET
    //                               LAB_00548613                                                 XREF[1]:     005484d5(j)  
    //         00548613     MOV        EAX,0x1
    //         00548618     POP        EBP
    //         00548619     POP        EDI
    //         0054861a     POP        ESI
    //         0054861b     POP        EBX
    //         0054861c     ADD        ESP,0xc
    //         0054861f     RET
    //                               LAB_00548620                                                 XREF[1]:     0054850c(j)  
    //         00548620     MOV        EAX,0x1
    //         00548625     POP        EBP
    //         00548626     POP        EDI
    //         00548627     POP        ESI
    //         00548628     POP        EBX
    //         00548629     ADD        ESP,0xc
    //         0054862c     RET
    //                               LAB_0054862d                                                 XREF[1]:     0054856d(j)  
    //         0054862d     MOV        EAX,0x1
    //         00548632     POP        EBP
    //         00548633     POP        EDI
    //         00548634     POP        ESI
    //         00548635     POP        EBX
    //         00548636     ADD        ESP,0xc
    //         00548639     RET
    //                               LAB_0054863a                                                 XREF[1]:     00548593(j)  
    //         0054863a     MOV        EAX,0x1
    //         0054863f     POP        EBP
    //         00548640     POP        EDI
    //         00548641     POP        ESI
    //         00548642     POP        EBX
    //         00548643     ADD        ESP,0xc
    //         00548646     RET
    //                               LAB_00548647                                                 XREF[1]:     005485c6(j)  
    //         00548647     MOV        EAX,0x1
    //         0054864c     POP        EBP
    //         0054864d     POP        EDI
    //         0054864e     POP        ESI
    //         0054864f     POP        EBX
    //         00548650     ADD        ESP,0xc
    //         00548653     RET
}

// Offset: 0x00548660
undefined FUN_00548660() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00548660()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00548660                                                 XREF[4]:     FUN_005480b0:005480fa(c), 
    //                                                                                                         FUN_005480b0:0054817a(c), 
    //                                                                                                         FUN_005480b0:00548232(c), 
    //                                                                                                         FUN_005480b0:005483e1(c)  
    //         00548660     PUSH       0x90
    //         00548665     MOV        EAX,[DAT_00887a80]
    //         0054866a     PUSH       0x8
    //         0054866c     ADD        EAX,0x36c6c
    //         00548671     PUSH       EAX
    //         00548672     CALL       FUN_00548750                                     undefined FUN_00548750()
    //         00548677     ADD        ESP,0xc
    //         0054867a     MOV        EAX,[DAT_00887a80]
    //         0054867f     ADD        EAX,0x36eac
    //                              language.dll match for 0x70: "B"
    //         00548684     PUSH       0x70
    //         00548686     PUSH       0x9
    //         00548688     PUSH       EAX
    //         00548689     CALL       FUN_00548750                                     undefined FUN_00548750()
    //         0054868e     ADD        ESP,0xc
    //         00548691     MOV        EAX,[DAT_00887a80]
    //         00548696     ADD        EAX,0x3706c
    //         0054869b     PUSH       0x18
    //         0054869d     PUSH       0x7
    //         0054869f     PUSH       EAX
    //         005486a0     CALL       FUN_00548750                                     undefined FUN_00548750()
    //         005486a5     ADD        ESP,0xc
    //         005486a8     MOV        EAX,[DAT_00887a80]
    //         005486ad     ADD        EAX,0x370cc
    //         005486b2     PUSH       0x8
    //         005486b4     PUSH       0x8
    //         005486b6     PUSH       EAX
    //         005486b7     CALL       FUN_00548750                                     undefined FUN_00548750()
    //         005486bc     ADD        ESP,0xc
    //         005486bf     MOV        EAX,[DAT_00887a80]
    //         005486c4     ADD        EAX,0x36c6c
    //         005486c9     PUSH       EAX
    //         005486ca     PUSH       0x120
    //         005486cf     CALL       FUN_00548770                                     undefined FUN_00548770()
    //         005486d4     ADD        ESP,0x8
    //         005486d7     MOV        EAX,[DAT_00887a80]
    //         005486dc     LEA        ECX,[EAX + 0x371b8]
    //         005486e2     ADD        EAX,0x36c6c
    //         005486e7     PUSH       ECX
    //         005486e8     PUSH       0xf
    //         005486ea     PUSH       EAX
    //         005486eb     PUSH       0x120
    //         005486f0     CALL       FUN_00548800                                     undefined FUN_00548800()
    //         005486f5     ADD        ESP,0x10
    //         005486f8     MOV        EAX,[DAT_00887a80]
    //         005486fd     ADD        EAX,0x370ec
    //         00548702     PUSH       0x20
    //         00548704     PUSH       0x5
    //         00548706     PUSH       EAX
    //         00548707     CALL       FUN_00548750                                     undefined FUN_00548750()
    //         0054870c     ADD        ESP,0xc
    //         0054870f     MOV        EAX,[DAT_00887a80]
    //         00548714     ADD        EAX,0x370ec
    //         00548719     PUSH       EAX
    //         0054871a     PUSH       0x20
    //         0054871c     CALL       FUN_00548770                                     undefined FUN_00548770()
    //         00548721     ADD        ESP,0x8
    //         00548724     MOV        EAX,[DAT_00887a80]
    //         00548729     LEA        ECX,[EAX + 0x37638]
    //         0054872f     PUSH       ECX
    //         00548730     PUSH       0xf
    //         00548732     ADD        EAX,0x370ec
    //         00548737     PUSH       EAX
    //         00548738     PUSH       0x20
    //         0054873a     CALL       FUN_00548800                                     undefined FUN_00548800()
    //         0054873f     ADD        ESP,0x10
    //         00548742     RET
}

// Offset: 0x00548750
undefined FUN_00548750() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00548750()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00548750                                                 XREF[9]:     FUN_00548660:00548672(c), 
    //                                                                                                         FUN_00548660:00548689(c), 
    //                                                                                                         FUN_00548660:005486a0(c), 
    //                                                                                                         FUN_00548660:005486b7(c), 
    //                                                                                                         FUN_00548660:00548707(c), 
    //                                                                                                         FUN_00548770:00548785(c), 
    //                                                                                                         FUN_00548910:00548942(c), 
    //                                                                                                         FUN_00548910:00548958(c), 
    //                                                                                                         FUN_00548d60:00548d80(c)  
    //         00548750     MOV        ECX,dword ptr [ESP + Stack[0xc]]
    //         00548754     PUSH       EDI
    //         00548755     TEST       ECX,ECX
    //         00548757     JZ         LAB_00548763
    //         00548759     MOV        EDI,dword ptr [ESP + Stack[0x4]]
    //         0054875d     MOV        EAX,dword ptr [ESP + Stack[0x8]]
    //         00548761     STOSD.REP  ES:EDI
    //                               LAB_00548763                                                 XREF[1]:     00548757(j)  
    //         00548763     POP        EDI
    //         00548764     RET
}

// Offset: 0x00548770
undefined FUN_00548770() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00548770()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00548770                                                 XREF[5]:     FUN_00548660:005486cf(c), 
    //                                                                                                         FUN_00548660:0054871c(c), 
    //                                                                                                         FUN_00548910:00548a4d(c), 
    //                                                                                                         FUN_00548910:00548ab1(c), 
    //                                                                                                         FUN_00548d60:00548fd9(c)  
    //         00548770     MOV        dword ptr [DAT_008875f8],0x0
    //         0054877a     PUSH       ESI
    //         0054877b     PUSH       EDI
    //         0054877c     PUSH       0x21
    //         0054877e     PUSH       0x0
    //         00548780     PUSH       DAT_00887a98                                     = align(4)
    //         00548785     CALL       FUN_00548750                                     undefined FUN_00548750()
    //         0054878a     MOV        EDX,dword ptr [ESP + Stack[0x4]]
    //         0054878e     MOV        ESI,dword ptr [ESP + Stack[0x8]]
    //         00548792     ADD        ESP,0xc
    //         00548795     TEST       EDX,EDX
    //         00548797     JLE        LAB_005487ac
    //         00548799     MOV        ECX,ESI
    //         0054879b     MOV        EAX,EDX
    //                               LAB_0054879d                                                 XREF[1]:     005487aa(j)  
    //         0054879d     MOV        EDI,dword ptr [ECX]
    //         0054879f     ADD        ECX,0x4
    //         005487a2     INC        dword ptr [EDI*0x4 + DAT_00887a98]               = align(4)
    //         005487a9     DEC        EAX
    //         005487aa     JNZ        LAB_0054879d
    //                               LAB_005487ac                                                 XREF[1]:     00548797(j)  
    //         005487ac     XOR        EAX,EAX
    //         005487ae     MOV        ECX,0x4
    //                               LAB_005487b3                                                 XREF[1]:     005487c8(j)  
    //         005487b3     MOV        dword ptr [ECX + 0x886c68]=>DAT_00886c6c,EAX
    //         005487b9     ADD        EAX,dword ptr [ECX + 0x887a98]=>DAT_00887a9c
    //         005487bf     ADD        ECX,0x4
    //         005487c2     CMP        ECX,0x80
    //         005487c8     JLE        LAB_005487b3
    //         005487ca     XOR        EDI,EDI
    //         005487cc     TEST       EDX,EDX
    //         005487ce     JLE        LAB_005487f5
    //                               LAB_005487d0                                                 XREF[1]:     005487f3(j)  
    //         005487d0     MOV        EAX,dword ptr [ESI + EDI*0x4]
    //         005487d3     TEST       EAX,EAX
    //         005487d5     JZ         LAB_005487f0
    //         005487d7     LEA        ECX,[EAX*0x4 + null_00886c68]                    = align(4)
    //         005487de     INC        dword ptr [DAT_008875f8]
    //         005487e4     MOV        EAX,dword ptr [ECX]=>null_00886c68               = align(4)
    //         005487e6     INC        EAX
    //         005487e7     MOV        dword ptr [ECX],EAX=>null_00886c68               = align(4)
    //         005487e9     MOV        dword ptr [EAX*0x4 + null_00887174],EDI          = align(4)
    //                               LAB_005487f0                                                 XREF[1]:     005487d5(j)  
    //         005487f0     INC        EDI
    //         005487f1     CMP        EDI,EDX
    //         005487f3     JL         LAB_005487d0
    //                               LAB_005487f5                                                 XREF[1]:     005487ce(j)  
    //         005487f5     POP        EDI
    //         005487f6     POP        ESI
    //         005487f7     RET
}

// Offset: 0x00548800
undefined FUN_00548800() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00548800()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00548800                                                 XREF[5]:     FUN_00548660:005486f0(c), 
    //                                                                                                         FUN_00548660:0054873a(c), 
    //                                                                                                         FUN_00548910:00548a7c(c), 
    //                                                                                                         FUN_00548910:00548add(c), 
    //                                                                                                         FUN_00548d60:00549005(c)  
    //         00548800     CMP        dword ptr [DAT_008875f8],0x0
    //         00548807     PUSH       EBX
    //         00548808     PUSH       ESI
    //         00548809     PUSH       EDI
    //         0054880a     PUSH       EBP
    //         0054880b     JZ         LAB_005488e5
    //         00548811     MOV        EDX,dword ptr [ESP + Stack[0x4]]
    //         00548815     TEST       EDX,EDX
    //         00548817     JLE        LAB_00548823
    //         00548819     MOV        EDI,dword ptr [ESP + Stack[0x10]]
    //         0054881d     XOR        EAX,EAX
    //         0054881f     MOV        ECX,EDX
    //         00548821     STOSD.REP  ES:EDI
    //                               LAB_00548823                                                 XREF[1]:     00548817(j)  
    //         00548823     MOV        EAX,0x1
    //         00548828     XOR        EBP,EBP
    //         0054882a     MOV        ESI,dword ptr [ESP + Stack[0xc]]
    //         0054882e     CMP        ESI,EAX
    //         00548830     JL         LAB_0054884f
    //                               LAB_00548832                                                 XREF[1]:     0054884d(j)  
    //         00548832     MOV        EBX,dword ptr [EAX*0x4 + 0x887a98]=>DAT_00887a9c
    //         00548839     TEST       EBX,EBX
    //         0054883b     JLE        LAB_0054884a
    //         0054883d     LEA        EDI,[EBP*0x4 + DAT_00886cf8]
    //         00548844     MOV        ECX,EBX
    //         00548846     STOSD.REP  ES:EDI=>DAT_00886cf8
    //         00548848     ADD        EBP,EBX
    //                               LAB_0054884a                                                 XREF[1]:     0054883b(j)  
    //         0054884a     INC        EAX
    //         0054884b     CMP        ESI,EAX
    //         0054884d     JGE        LAB_00548832
    //                               LAB_0054884f                                                 XREF[1]:     00548830(j)  
    //         0054884f     XOR        EAX,EAX
    //         00548851     CMP        ESI,0x2
    //         00548854     MOV        [DAT_00886c6c],EAX
    //         00548859     JL         LAB_0054887c
    //         0054885b     MOV        ECX,0x8
    //         00548860     DEC        ESI
    //                               LAB_00548861                                                 XREF[1]:     0054887a(j)  
    //         00548861     MOV        EDI,dword ptr [ECX + 0x887a94]=>DAT_00887a9c
    //         00548867     ADD        ECX,0x4
    //         0054886a     ADD        EDI,EAX
    //         0054886c     DEC        ESI
    //         0054886d     LEA        EAX,[EDI*0x2 + 0x0]
    //         00548874     MOV        dword ptr [ECX + 0x886c64]=>DAT_00886c70,EAX
    //         0054887a     JNZ        LAB_00548861
    //                               LAB_0054887c                                                 XREF[1]:     00548859(j)  
    //         0054887c     XOR        ECX,ECX
    //         0054887e     XOR        EAX,EAX
    //         00548880     MOV        ESI,dword ptr [ESP + Stack[0x8]]
    //         00548884     CMP        dword ptr [DAT_008875f8],ECX
    //         0054888a     JLE        LAB_005488a7
    //                               LAB_0054888c                                                 XREF[1]:     005488a5(j)  
    //         0054888c     MOV        EDI,dword ptr [ECX + DAT_00886cf8]
    //         00548892     MOV        EBX,dword ptr [ECX + DAT_00887178]
    //         00548898     ADD        ECX,0x4
    //         0054889b     INC        EAX
    //         0054889c     MOV        dword ptr [ESI + EBX*0x4],EDI
    //         0054889f     CMP        dword ptr [DAT_008875f8],EAX
    //         005488a5     JG         LAB_0054888c
    //                               LAB_005488a7                                                 XREF[1]:     0054888a(j)  
    //         005488a7     TEST       EDX,EDX
    //         005488a9     JLE        LAB_005488e5
    //         005488ab     MOV        EDI,dword ptr [ESP + Stack[0x10]]
    //                               LAB_005488af                                                 XREF[1]:     005488e3(j)  
    //         005488af     MOV        EAX,dword ptr [ESI]
    //         005488b1     TEST       EAX,EAX
    //         005488b3     JZ         LAB_005488dc
    //         005488b5     LEA        EAX,[EAX*0x4 + null_00886c68]                    = align(4)
    //         005488bc     MOV        EBX,dword ptr [EAX]=>null_00886c68               = align(4)
    //         005488be     LEA        ECX,[EBX + 0x1]
    //         005488c1     MOV        dword ptr [EAX],ECX=>null_00886c68               = align(4)
    //         005488c3     MOV        EAX,dword ptr [ESI]
    //         005488c5     XOR        ECX,ECX
    //         005488c7     TEST       EAX,EAX
    //         005488c9     JLE        LAB_005488da
    //                               LAB_005488cb                                                 XREF[1]:     005488d8(j)  
    //         005488cb     ADD        ECX,ECX
    //         005488cd     MOV        EBP,EBX
    //         005488cf     SHR        EBX,0x1
    //         005488d2     AND        EBP,0x1
    //         005488d5     OR         ECX,EBP
    //         005488d7     DEC        EAX
    //         005488d8     JNZ        LAB_005488cb
    //                               LAB_005488da                                                 XREF[1]:     005488c9(j)  
    //         005488da     MOV        dword ptr [EDI],ECX
    //                               LAB_005488dc                                                 XREF[1]:     005488b3(j)  
    //         005488dc     ADD        EDI,0x4
    //         005488df     ADD        ESI,0x4
    //         005488e2     DEC        EDX
    //         005488e3     JNZ        LAB_005488af
    //                               LAB_005488e5                                                 XREF[2]:     0054880b(j), 005488a9(j)  
    //         005488e5     POP        EBP
    //         005488e6     POP        EDI
    //         005488e7     POP        ESI
    //         005488e8     POP        EBX
    //         005488e9     RET
}

// Offset: 0x005488F0
undefined FUN_005488f0() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_005488f0()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_005488f0                                                 XREF[4]:     FUN_005480b0:005480ff(c), 
    //                                                                                                         FUN_005480b0:0054817f(c), 
    //                                                                                                         FUN_005480b0:00548237(c), 
    //                                                                                                         FUN_005480b0:005483e6(c)  
    //         005488f0     PUSH       0x2
    //         005488f2     PUSH       0x1
    //         005488f4     CALL       FUN_00547d80                                     undefined FUN_00547d80()
    //         005488f9     ADD        ESP,0x8
    //         005488fc     CMP        EAX,0x1
    //         005488ff     SBB        EAX,EAX
    //         00548901     INC        EAX
    //         00548902     RET
}

// Offset: 0x00548910
undefined FUN_00548910() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00548910()
    //              undefined         <UNASSIGNED>   <RETURN>
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[3]:     0054896c(W), 00548978(R), 00548a05(RW)  
    //                               FUN_00548910                                                 XREF[4]:     FUN_005480b0:00548128(c), 
    //                                                                                                         FUN_005480b0:005481b9(c), 
    //                                                                                                         FUN_005480b0:00548290(c), 
    //                                                                                                         FUN_005480b0:005482d2(c)  
    //         00548910     SUB        ESP,0x4
    //         00548913     PUSH       EBX
    //         00548914     PUSH       ESI
    //         00548915     PUSH       EDI
    //         00548916     MOV        ESI,dword ptr [DAT_00887a80]
    //         0054891c     PUSH       EBP
    //         0054891d     ADD        ESI,0x2d102
    //         00548923     XOR        EBX,EBX
    //         00548925     MOV        EDI,dword ptr [DAT_00887a80]
    //         0054892b     ADD        EDI,0x3610c
    //         00548931     PUSH       0x120
    //         00548936     PUSH       EBX
    //         00548937     MOV        EAX,[DAT_00887a80]
    //         0054893c     ADD        EAX,0x36720
    //         00548941     PUSH       EAX
    //         00548942     CALL       FUN_00548750                                     undefined FUN_00548750()
    //         00548947     ADD        ESP,0xc
    //         0054894a     MOV        EAX,[DAT_00887a80]
    //         0054894f     ADD        EAX,0x36ba0
    //         00548954     PUSH       0x20
    //         00548956     PUSH       EBX
    //         00548957     PUSH       EAX
    //         00548958     CALL       FUN_00548750                                     undefined FUN_00548750()
    //         0054895d     ADD        ESP,0xc
    //         00548960     MOV        ECX,dword ptr [DAT_00887a80]
    //         00548966     MOV        EDX,dword ptr [ECX + 0x36108]
    //         0054896c     MOV        dword ptr [ESP + local_4],EDX
    //         00548970     CMP        EDX,EBX
    //         00548972     JLE        LAB_00548a0f
    //         00548978     MOV        EDX,dword ptr [ESP + local_4]
    //                               LAB_0054897c                                                 XREF[1]:     00548a09(j)  
    //         0054897c     TEST       EBX,EBX
    //         0054897e     JNZ        LAB_0054898a
    //         00548980     MOV        EDX,dword ptr [EDI]
    //         00548982     ADD        EDI,0x4
    //         00548985     MOV        EBX,0x20
    //                               LAB_0054898a                                                 XREF[1]:     0054897e(j)  
    //         0054898a     TEST       EDX,0x80000000
    //         00548990     JZ         LAB_005489f0
    //         00548992     XOR        EAX,EAX
    //         00548994     XOR        ECX,ECX
    //         00548996     MOV        AX,word ptr [ESI + 0x1]
    //         0054899a     MOV        CL,byte ptr [ESI]
    //         0054899c     DEC        EAX
    //         0054899d     XOR        EBP,EBP
    //         0054899f     MOV        BP,word ptr [ECX*0x2 + DAT_0058ef48]             = 01h
    //         005489a7     MOV        ECX,dword ptr [DAT_00887a80]
    //         005489ad     INC        dword ptr [ECX + EBP*0x4 + 0x36720]
    //         005489b4     CMP        EAX,0x200
    //         005489b9     JNC        LAB_005489d4
    //         005489bb     XOR        ECX,ECX
    //         005489bd     ADD        ESI,0x3
    //         005489c0     MOV        CL,byte ptr [EAX + 0x58f348]=>DAT_0058f347
    //         005489c6     MOV        EAX,[DAT_00887a80]
    //         005489cb     INC        dword ptr [EAX + ECX*0x4 + 0x36ba0]
    //         005489d2     JMP        LAB_00548a02
    //                               LAB_005489d4                                                 XREF[1]:     005489b9(j)  
    //         005489d4     SHR        EAX,0x8
    //         005489d7     XOR        ECX,ECX
    //         005489d9     ADD        ESI,0x3
    //         005489dc     MOV        CL,byte ptr [EAX + DAT_0058f948]
    //         005489e2     MOV        EAX,[DAT_00887a80]
    //         005489e7     INC        dword ptr [EAX + ECX*0x4 + 0x36ba0]
    //         005489ee     JMP        LAB_00548a02
    //                               LAB_005489f0                                                 XREF[1]:     00548990(j)  
    //         005489f0     XOR        EAX,EAX
    //         005489f2     MOV        ECX,dword ptr [DAT_00887a80]
    //         005489f8     MOV        AL,byte ptr [ESI]
    //         005489fa     INC        ESI
    //         005489fb     INC        dword ptr [ECX + EAX*0x4 + 0x36720]
    //                               LAB_00548a02                                                 XREF[2]:     005489d2(j), 005489ee(j)  
    //         00548a02     ADD        EDX,EDX
    //         00548a04     DEC        EBX
    //         00548a05     DEC        dword ptr [ESP + local_4]
    //         00548a09     JNZ        LAB_0054897c
    //                               LAB_00548a0f                                                 XREF[1]:     00548972(j)  
    //         00548a0f     MOV        EAX,[DAT_00887a80]
    //         00548a14     INC        dword ptr [EAX + 0x36b20]
    //         00548a1a     MOV        EAX,[DAT_00887a80]
    //         00548a1f     ADD        EAX,0x36c6c
    //         00548a24     PUSH       EAX
    //         00548a25     MOV        EAX,[DAT_00887a80]
    //         00548a2a     ADD        EAX,0x36720
    //         00548a2f     PUSH       EAX
    //         00548a30     PUSH       0x120
    //         00548a35     CALL       FUN_00548b00                                     undefined FUN_00548b00()
    //         00548a3a     ADD        ESP,0xc
    //         00548a3d     MOV        EAX,[DAT_00887a80]
    //         00548a42     ADD        EAX,0x36c6c
    //         00548a47     PUSH       EAX
    //         00548a48     PUSH       0x120
    //         00548a4d     CALL       FUN_00548770                                     undefined FUN_00548770()
    //         00548a52     ADD        ESP,0x8
    //         00548a55     PUSH       0xf
    //         00548a57     CALL       FUN_00548cb0                                     undefined FUN_00548cb0()
    //         00548a5c     ADD        ESP,0x4
    //         00548a5f     MOV        EAX,[DAT_00887a80]
    //         00548a64     ADD        EAX,0x371b8
    //         00548a69     PUSH       EAX
    //         00548a6a     PUSH       0xf
    //         00548a6c     MOV        EAX,[DAT_00887a80]
    //         00548a71     ADD        EAX,0x36c6c
    //         00548a76     PUSH       EAX
    //         00548a77     PUSH       0x120
    //         00548a7c     CALL       FUN_00548800                                     undefined FUN_00548800()
    //         00548a81     ADD        ESP,0x10
    //         00548a84     MOV        EAX,[DAT_00887a80]
    //         00548a89     ADD        EAX,0x370ec
    //         00548a8e     PUSH       EAX
    //         00548a8f     MOV        EAX,[DAT_00887a80]
    //         00548a94     ADD        EAX,0x36ba0
    //         00548a99     PUSH       EAX
    //         00548a9a     PUSH       0x20
    //         00548a9c     CALL       FUN_00548b00                                     undefined FUN_00548b00()
    //         00548aa1     ADD        ESP,0xc
    //         00548aa4     MOV        EAX,[DAT_00887a80]
    //         00548aa9     ADD        EAX,0x370ec
    //         00548aae     PUSH       EAX
    //         00548aaf     PUSH       0x20
    //         00548ab1     CALL       FUN_00548770                                     undefined FUN_00548770()
    //         00548ab6     ADD        ESP,0x8
    //         00548ab9     PUSH       0xf
    //         00548abb     CALL       FUN_00548cb0                                     undefined FUN_00548cb0()
    //         00548ac0     ADD        ESP,0x4
    //         00548ac3     MOV        EAX,[DAT_00887a80]
    //         00548ac8     ADD        EAX,0x37638
    //         00548acd     PUSH       EAX
    //         00548ace     PUSH       0xf
    //         00548ad0     MOV        EAX,[DAT_00887a80]
    //         00548ad5     ADD        EAX,0x370ec
    //         00548ada     PUSH       EAX
    //         00548adb     PUSH       0x20
    //         00548add     CALL       FUN_00548800                                     undefined FUN_00548800()
    //         00548ae2     ADD        ESP,0x10
    //         00548ae5     CALL       FUN_00548d60                                     undefined FUN_00548d60()
    //         00548aea     POP        EBP
    //         00548aeb     POP        EDI
    //         00548aec     POP        ESI
    //         00548aed     POP        EBX
    //         00548aee     ADD        ESP,0x4
    //         00548af1     RET
}

// Offset: 0x00548B00
undefined FUN_00548b00() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00548b00()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00548b00                                                 XREF[3]:     FUN_00548910:00548a35(c), 
    //                                                                                                         FUN_00548910:00548a9c(c), 
    //                                                                                                         FUN_00548d60:00548fc4(c)  
    //         00548b00     MOV        EDX,dword ptr [ESP + Stack[0x4]]
    //         00548b04     PUSH       EBX
    //         00548b05     PUSH       ESI
    //         00548b06     TEST       EDX,EDX
    //         00548b08     PUSH       EDI
    //         00548b09     PUSH       EBP
    //         00548b0a     JLE        LAB_00548b2c
    //         00548b0c     MOV        EDI,DAT_00887600
    //         00548b11     MOV        EAX,0xffffffff
    //         00548b16     MOV        ECX,EDX
    //         00548b18     TEST       EDX,EDX
    //         00548b1a     STOSD.REP  ES:EDI=>DAT_00887600
    //         00548b1c     JLE        LAB_00548b2c
    //         00548b1e     MOV        ESI,dword ptr [ESP + Stack[0xc]]
    //         00548b22     XOR        EAX,EAX
    //         00548b24     MOV        EDI,ESI
    //         00548b26     MOV        ECX,EDX
    //         00548b28     STOSD.REP  ES:EDI
    //         00548b2a     JMP        LAB_00548b30
    //                               LAB_00548b2c                                                 XREF[2]:     00548b0a(j), 00548b1c(j)  
    //         00548b2c     MOV        ESI,dword ptr [ESP + Stack[0xc]]
    //                               LAB_00548b30                                                 XREF[1]:     00548b2a(j)  
    //         00548b30     MOV        EDI,0x1
    //         00548b35     XOR        EAX,EAX
    //         00548b37     TEST       EDX,EDX
    //         00548b39     JLE        LAB_00548b57
    //         00548b3b     MOV        EBX,DAT_00887b24
    //         00548b40     MOV        ECX,dword ptr [ESP + Stack[0x8]]
    //                               LAB_00548b44                                                 XREF[1]:     00548b55(j)  
    //         00548b44     CMP        dword ptr [ECX],0x0
    //         00548b47     JZ         LAB_00548b4f
    //         00548b49     MOV        dword ptr [EBX]=>DAT_00887b24,EAX
    //         00548b4b     ADD        EBX,0x4
    //         00548b4e     INC        EDI
    //                               LAB_00548b4f                                                 XREF[1]:     00548b47(j)  
    //         00548b4f     ADD        ECX,0x4
    //         00548b52     INC        EAX
    //         00548b53     CMP        EDX,EAX
    //         00548b55     JG         LAB_00548b44
    //                               LAB_00548b57                                                 XREF[1]:     00548b39(j)  
    //         00548b57     DEC        EDI
    //         00548b58     CMP        EDI,0x1
    //         00548b5b     JG         LAB_00548b76
    //         00548b5d     TEST       EDI,EDI
    //         00548b5f     JZ         LAB_00548c0f
    //         00548b65     MOV        EAX,[DAT_00887b24]
    //         00548b6a     POP        EBP
    //         00548b6b     POP        EDI
    //         00548b6c     MOV        dword ptr [ESI + EAX*0x4],0x1
    //         00548b73     POP        ESI
    //         00548b74     POP        EBX
    //         00548b75     RET
    //                               LAB_00548b76                                                 XREF[1]:     00548b5b(j)  
    //         00548b76     MOV        EBX,EDI
    //         00548b78     SAR        EBX,0x1
    //         00548b7b     TEST       EBX,EBX
    //         00548b7d     JZ         LAB_00548b9a
    //                               LAB_00548b7f                                                 XREF[1]:     00548b98(j)  
    //         00548b7f     PUSH       EBX
    //         00548b80     MOV        EAX,EBX
    //         00548b82     DEC        EBX
    //         00548b83     PUSH       EDI
    //         00548b84     MOV        ECX,dword ptr [ESP + Stack[0x8]]
    //         00548b88     PUSH       ECX
    //         00548b89     PUSH       DAT_00887b20
    //         00548b8e     CALL       FUN_00548c20                                     undefined FUN_00548c20()
    //         00548b93     ADD        ESP,0x10
    //         00548b96     TEST       EBX,EBX
    //         00548b98     JNZ        LAB_00548b7f
    //                               LAB_00548b9a                                                 XREF[2]:     00548b7d(j), 00548c0d(j)  
    //         00548b9a     MOV        EAX,dword ptr [EDI*0x4 + 0x887b20]=>DAT_00887b24
    //         00548ba1     MOV        EBX,dword ptr [DAT_00887b24]
    //         00548ba7     DEC        EDI
    //         00548ba8     PUSH       0x1
    //         00548baa     MOV        ECX,dword ptr [ESP + Stack[0x8]]
    //         00548bae     PUSH       EDI
    //         00548baf     PUSH       ECX
    //         00548bb0     MOV        [DAT_00887b24],EAX
    //         00548bb5     PUSH       DAT_00887b20
    //         00548bba     CALL       FUN_00548c20                                     undefined FUN_00548c20()
    //         00548bbf     MOV        ECX,dword ptr [ESP + Stack[0x8]]
    //         00548bc3     ADD        ESP,0x10
    //         00548bc6     MOV        EBP,dword ptr [DAT_00887b24]
    //         00548bcc     MOV        EAX,dword ptr [ECX + EBX*0x4]
    //         00548bcf     PUSH       0x1
    //         00548bd1     PUSH       EDI
    //         00548bd2     PUSH       ECX
    //         00548bd3     ADD        dword ptr [ECX + EBP*0x4],EAX
    //         00548bd6     PUSH       DAT_00887b20
    //         00548bdb     CALL       FUN_00548c20                                     undefined FUN_00548c20()
    //         00548be0     ADD        ESP,0x10
    //                               LAB_00548be3                                                 XREF[1]:     00548bf2(j)  
    //         00548be3     MOV        EAX,EBP
    //         00548be5     INC        dword ptr [ESI + EBP*0x4]
    //         00548be8     MOV        EBP,dword ptr [EBP*0x4 + DAT_00887600]
    //         00548bef     CMP        EBP,-0x1
    //         00548bf2     JNZ        LAB_00548be3
    //         00548bf4     MOV        dword ptr [EAX*0x4 + DAT_00887600],EBX
    //                               LAB_00548bfb                                                 XREF[1]:     00548c08(j)  
    //         00548bfb     INC        dword ptr [ESI + EBX*0x4]
    //         00548bfe     MOV        EBX,dword ptr [EBX*0x4 + DAT_00887600]
    //         00548c05     CMP        EBX,-0x1
    //         00548c08     JNZ        LAB_00548bfb
    //         00548c0a     CMP        EDI,0x1
    //         00548c0d     JNZ        LAB_00548b9a
    //                               LAB_00548c0f                                                 XREF[1]:     00548b5f(j)  
    //         00548c0f     POP        EBP
    //         00548c10     POP        EDI
    //         00548c11     POP        ESI
    //         00548c12     POP        EBX
    //         00548c13     RET
}

// Offset: 0x00548C20
undefined FUN_00548c20() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00548c20()
    //              undefined         <UNASSIGNED>   <RETURN>
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     00548c4e(W), 00548c71(R)  
    //              undefined4        Stack[-0x8]:4  local_8                   XREF[3]:     00548c39(W), 00548c80(R), 00548c99(R)  
    //                               FUN_00548c20                                                 XREF[3]:     FUN_00548b00:00548b8e(c), 
    //                                                                                                         FUN_00548b00:00548bba(c), 
    //                                                                                                         FUN_00548b00:00548bdb(c)  
    //         00548c20     MOV        ECX,dword ptr [ESP + Stack[0x4]]
    //         00548c24     MOV        EAX,dword ptr [ESP + Stack[0x10]]
    //         00548c28     SUB        ESP,0x8
    //         00548c2b     PUSH       EBX
    //         00548c2c     PUSH       ESI
    //         00548c2d     PUSH       EDI
    //         00548c2e     LEA        ESI,[EAX*0x2 + 0x0]
    //         00548c35     PUSH       EBP
    //         00548c36     MOV        EDI,dword ptr [ECX + EAX*0x4]
    //         00548c39     MOV        dword ptr [ESP + local_8],EDI
    //         00548c3d     CMP        ESI,dword ptr [ESP + Stack[0xc]]
    //         00548c41     JG         LAB_00548c99
    //         00548c43     MOV        EDX,dword ptr [ESP + Stack[0x8]]
    //         00548c47     CMP        ESI,dword ptr [ESP + Stack[0xc]]
    //         00548c4b     LEA        EAX,[EDX + EDI*0x4]
    //         00548c4e     MOV        dword ptr [ESP + local_4],EAX
    //                               LAB_00548c52                                                 XREF[1]:     00548c97(j)  
    //         00548c52     JGE        LAB_00548c6e
    //         00548c54     MOV        EBX,dword ptr [ECX + ESI*0x4 + 0x4]
    //         00548c58     LEA        EAX,[ECX + ESI*0x4]
    //         00548c5b     MOV        EDI,dword ptr [EDX + EBX*0x4]
    //         00548c5e     MOV        EBP,dword ptr [EAX]
    //         00548c60     MOV        EAX,dword ptr [EDX + EBP*0x4]
    //         00548c63     CMP        EDI,EAX
    //         00548c65     JL         LAB_00548c6d
    //         00548c67     JNZ        LAB_00548c6e
    //         00548c69     CMP        EBX,EBP
    //         00548c6b     JLE        LAB_00548c6e
    //                               LAB_00548c6d                                                 XREF[1]:     00548c65(j)  
    //         00548c6d     INC        ESI
    //                               LAB_00548c6e                                                 XREF[3]:     00548c52(j), 00548c67(j), 
    //                                                                                                         00548c6b(j)  
    //         00548c6e     MOV        EDI,dword ptr [ECX + ESI*0x4]
    //         00548c71     MOV        EAX,dword ptr [ESP + local_4]
    //         00548c75     MOV        EBX,dword ptr [EDX + EDI*0x4]
    //         00548c78     MOV        EAX,dword ptr [EAX]
    //         00548c7a     CMP        EBX,EAX
    //         00548c7c     JG         LAB_00548c99
    //         00548c7e     JNZ        LAB_00548c86
    //         00548c80     CMP        dword ptr [ESP + local_8],EDI
    //         00548c84     JG         LAB_00548c99
    //                               LAB_00548c86                                                 XREF[1]:     00548c7e(j)  
    //         00548c86     MOV        EAX,dword ptr [ESP + Stack[0x10]]
    //         00548c8a     MOV        dword ptr [ESP + Stack[0x10]],ESI
    //         00548c8e     ADD        ESI,ESI
    //         00548c90     MOV        dword ptr [ECX + EAX*0x4],EDI
    //         00548c93     CMP        ESI,dword ptr [ESP + Stack[0xc]]
    //         00548c97     JLE        LAB_00548c52
    //                               LAB_00548c99                                                 XREF[3]:     00548c41(j), 00548c7c(j), 
    //                                                                                                         00548c84(j)  
    //         00548c99     MOV        EDI,dword ptr [ESP + local_8]
    //         00548c9d     MOV        EAX,dword ptr [ESP + Stack[0x10]]
    //         00548ca1     POP        EBP
    //         00548ca2     MOV        dword ptr [ECX + EAX*0x4],EDI
    //         00548ca5     POP        EDI
    //         00548ca6     POP        ESI
    //         00548ca7     POP        EBX
    //         00548ca8     ADD        ESP,0x8
    //         00548cab     RET
}

// Offset: 0x00548CB0
undefined FUN_00548cb0() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00548cb0()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00548cb0                                                 XREF[3]:     FUN_00548910:00548a57(c), 
    //                                                                                                         FUN_00548910:00548abb(c), 
    //                                                                                                         FUN_00548d60:00548fe3(c)  
    //         00548cb0     CMP        dword ptr [DAT_008875f8],0x1
    //         00548cb7     PUSH       ESI
    //         00548cb8     PUSH       EDI
    //         00548cb9     JLE        LAB_00548d5d
    //         00548cbf     MOV        EDX,dword ptr [ESP + Stack[0x4]]
    //         00548cc3     LEA        EAX,[EDX + 0x1]
    //         00548cc6     CMP        EAX,0x20
    //         00548cc9     JG         LAB_00548ce8
    //         00548ccb     LEA        ECX,[EAX*0x4 + DAT_00887a98]                     = align(4)
    //         00548cd2     LEA        EAX,[EDX*0x4 + DAT_00887a98]                     = align(4)
    //                               LAB_00548cd9                                                 XREF[1]:     00548ce6(j)  
    //         00548cd9     MOV        ESI,dword ptr [ECX]=>DAT_00887a98                = align(4)
    //         00548cdb     ADD        ECX,0x4
    //         00548cde     ADD        dword ptr [EAX],ESI=>DAT_00887a98                = align(4)
    //         00548ce0     CMP        ECX,null_00887b18                                = align(4)
    //         00548ce6     JBE        LAB_00548cd9
    //                               LAB_00548ce8                                                 XREF[1]:     00548cc9(j)  
    //         00548ce8     XOR        EDI,EDI
    //         00548cea     MOV        EAX,EDX
    //         00548cec     TEST       EDX,EDX
    //         00548cee     JLE        LAB_00548d02
    //                               LAB_00548cf0                                                 XREF[1]:     00548d00(j)  
    //         00548cf0     MOV        ESI,dword ptr [EAX*0x4 + DAT_00887a98]           = align(4)
    //         00548cf7     MOV        CL,DL
    //         00548cf9     SUB        CL,AL
    //         00548cfb     SHL        ESI,CL
    //         00548cfd     ADD        EDI,ESI
    //         00548cff     DEC        EAX
    //         00548d00     JNZ        LAB_00548cf0
    //                               LAB_00548d02                                                 XREF[1]:     00548cee(j)  
    //         00548d02     MOV        CL,DL
    //         00548d04     MOV        EAX,0x1
    //         00548d09     SHL        EAX,CL
    //         00548d0b     CMP        EDI,EAX
    //         00548d0d     JZ         LAB_00548d5d
    //         00548d0f     LEA        ESI,[EDX*0x4 + DAT_00887a98]                     = align(4)
    //         00548d16     DEC        EDX
    //         00548d17     MOV        EAX,0xffffffff
    //         00548d1c     SHL        EAX,CL
    //         00548d1e     ADD        EDI,EAX
    //                               LAB_00548d20                                                 XREF[2]:     00548d40(j), 00548d5b(j)  
    //         00548d20     MOV        ECX,EDX
    //         00548d22     DEC        dword ptr [ESI]=>DAT_00887a98                    = align(4)
    //         00548d24     TEST       EDX,EDX
    //         00548d26     JLE        LAB_00548d5a
    //         00548d28     LEA        EAX,[EDX*0x4 + DAT_00887a98]                     = align(4)
    //                               LAB_00548d2f                                                 XREF[1]:     00548d3d(j)  
    //         00548d2f     CMP        dword ptr [EAX],0x0=>DAT_00887a98                = align(4)
    //         00548d32     JNZ        LAB_00548d45
    //         00548d34     SUB        EAX,0x4
    //         00548d37     DEC        ECX
    //         00548d38     CMP        EAX,DAT_00887a98                                 = align(4)
    //         00548d3d     JA         LAB_00548d2f
    //         00548d3f     DEC        EDI
    //         00548d40     JNZ        LAB_00548d20
    //         00548d42     POP        EDI
    //         00548d43     POP        ESI
    //         00548d44     RET
    //                               LAB_00548d45                                                 XREF[1]:     00548d32(j)  
    //         00548d45     DEC        dword ptr [ECX*0x4 + DAT_00887a98]               = align(4)
    //         00548d4c     LEA        EAX,[ECX*0x4 + 0x0]
    //         00548d53     ADD        dword ptr [EAX + DAT_00887a9c],0x2
    //                               LAB_00548d5a                                                 XREF[1]:     00548d26(j)  
    //         00548d5a     DEC        EDI
    //         00548d5b     JNZ        LAB_00548d20
    //                               LAB_00548d5d                                                 XREF[2]:     00548cb9(j), 00548d0d(j)  
    //         00548d5d     POP        EDI
    //         00548d5e     POP        ESI
    //         00548d5f     RET
}

// Offset: 0x00548D60
undefined FUN_00548d60() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00548d60()
    //              undefined         <UNASSIGNED>   <RETURN>
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     00548ee5(W), 00548f77(RW)  
    //              undefined4        Stack[-0x8]:4  local_8                   XREF[3]:     00548ecf(W), 00548ef1(R), 00548ef5(RW)  
    //                               FUN_00548d60                                                 XREF[1]:     FUN_00548910:00548ae5(c)  
    //         00548d60     SUB        ESP,0x8
    //         00548d63     PUSH       EBX
    //         00548d64     PUSH       ESI
    //         00548d65     PUSH       EDI
    //         00548d66     MOV        EBX,0xff
    //         00548d6b     PUSH       EBP
    //         00548d6c     XOR        ESI,ESI
    //         00548d6e     XOR        EBP,EBP
    //         00548d70     XOR        EDI,EDI
    //         00548d72     PUSH       0x13
    //         00548d74     MOV        EAX,[DAT_00887a80]
    //         00548d79     PUSH       EBP
    //         00548d7a     ADD        EAX,0x36c20
    //         00548d7f     PUSH       EAX
    //         00548d80     CALL       FUN_00548750                                     undefined FUN_00548750()
    //         00548d85     ADD        ESP,0xc
    //         00548d88     MOV        ECX,dword ptr [DAT_00887a80]
    //         00548d8e     MOV        dword ptr [ECX + 0x38108],0x11d
    //         00548d98     MOV        ECX,dword ptr [DAT_00887a80]
    //         00548d9e     CMP        dword ptr [ECX + 0x38108],EBP
    //         00548da4     JL         LAB_00548dd5
    //                               LAB_00548da6                                                 XREF[1]:     00548dd3(j)  
    //         00548da6     MOV        EAX,[DAT_00887a80]
    //         00548dab     MOV        EDX,dword ptr [DAT_00887a80]
    //         00548db1     MOV        ECX,dword ptr [EAX + 0x38108]
    //         00548db7     ADD        EAX,0x38108
    //         00548dbc     CMP        dword ptr [EDX + ECX*0x4 + 0x36c6c],EBP
    //         00548dc3     JNZ        LAB_00548dd5
    //         00548dc5     DEC        ECX
    //         00548dc6     MOV        dword ptr [EAX],ECX
    //         00548dc8     MOV        EAX,[DAT_00887a80]
    //         00548dcd     CMP        dword ptr [EAX + 0x38108],EBP
    //         00548dd3     JGE        LAB_00548da6
    //                               LAB_00548dd5                                                 XREF[2]:     00548da4(j), 00548dc3(j)  
    //         00548dd5     MOV        EAX,[DAT_00887a80]
    //         00548dda     MOV        ECX,dword ptr [EAX + 0x38108]
    //         00548de0     ADD        EAX,0x38108
    //         00548de5     INC        ECX
    //         00548de6     CMP        ECX,0x101
    //         00548dec     JG         LAB_00548df3
    //         00548dee     MOV        ECX,0x101
    //                               LAB_00548df3                                                 XREF[1]:     00548dec(j)  
    //         00548df3     MOV        dword ptr [EAX],ECX
    //         00548df5     MOV        EAX,[DAT_00887a80]
    //         00548dfa     MOV        dword ptr [EAX + 0x3810c],0x1d
    //         00548e04     MOV        EAX,[DAT_00887a80]
    //         00548e09     CMP        dword ptr [EAX + 0x3810c],0x0
    //         00548e10     JL         LAB_00548e46
    //         00548e12     XOR        EDX,EDX
    //                               LAB_00548e14                                                 XREF[1]:     00548e44(j)  
    //         00548e14     MOV        ECX,dword ptr [DAT_00887a80]
    //         00548e1a     MOV        EBP,dword ptr [DAT_00887a80]
    //         00548e20     MOV        EAX,dword ptr [ECX + 0x3810c]
    //         00548e26     ADD        ECX,0x3810c
    //         00548e2c     CMP        dword ptr [EBP + EAX*0x4 + 0x370ec],EDX
    //         00548e33     JNZ        LAB_00548e46
    //         00548e35     DEC        EAX
    //         00548e36     MOV        dword ptr [ECX],EAX
    //         00548e38     MOV        ECX,dword ptr [DAT_00887a80]
    //         00548e3e     CMP        dword ptr [ECX + 0x3810c],EDX
    //         00548e44     JGE        LAB_00548e14
    //                               LAB_00548e46                                                 XREF[2]:     00548e10(j), 00548e33(j)  
    //         00548e46     MOV        EAX,[DAT_00887a80]
    //         00548e4b     MOV        ECX,dword ptr [EAX + 0x3810c]
    //         00548e51     ADD        EAX,0x3810c
    //         00548e56     INC        ECX
    //         00548e57     CMP        ECX,0x1
    //         00548e5a     JG         LAB_00548e61
    //         00548e5c     MOV        ECX,0x1
    //                               LAB_00548e61                                                 XREF[1]:     00548e5a(j)  
    //         00548e61     MOV        dword ptr [EAX],ECX
    //         00548e63     MOV        EAX,[DAT_00887a80]
    //         00548e68     MOV        ECX,dword ptr [EAX + 0x38108]
    //         00548e6e     ADD        EAX,0x36c6c
    //         00548e73     PUSH       ECX
    //         00548e74     PUSH       EAX
    //         00548e75     MOV        EAX,[DAT_00887a80]
    //         00548e7a     ADD        EAX,0x37704
    //         00548e7f     PUSH       EAX
    //         00548e80     CALL       FUN_00549020                                     undefined FUN_00549020()
    //         00548e85     ADD        ESP,0xc
    //         00548e88     MOV        ECX,dword ptr [DAT_00887a80]
    //         00548e8e     MOV        EDX,dword ptr [ECX + 0x3810c]
    //         00548e94     LEA        EAX,[ECX + 0x370ec]
    //         00548e9a     PUSH       EDX
    //         00548e9b     PUSH       EAX
    //         00548e9c     MOV        EAX,dword ptr [ECX + 0x38108]
    //         00548ea2     LEA        EAX,[ECX + EAX*0x4]
    //         00548ea5     ADD        EAX,0x37704
    //         00548eaa     PUSH       EAX
    //         00548eab     CALL       FUN_00549020                                     undefined FUN_00549020()
    //         00548eb0     ADD        ESP,0xc
    //         00548eb3     MOV        EDX,dword ptr [DAT_00887a80]
    //         00548eb9     ADD        EDX,0x37704
    //         00548ebf     MOV        EAX,[DAT_00887a80]
    //         00548ec4     ADD        EAX,0x37c04
    //         00548ec9     MOV        ECX,dword ptr [DAT_00887a80]
    //         00548ecf     MOV        dword ptr [ESP + local_8],EDX
    //         00548ed3     MOV        ECX,dword ptr [ECX + 0x38108]
    //         00548ed9     MOV        EDX,dword ptr [DAT_00887a80]
    //         00548edf     ADD        ECX,dword ptr [EDX + 0x3810c]
    //         00548ee5     MOV        dword ptr [ESP + local_4],ECX
    //         00548ee9     TEST       ECX,ECX
    //         00548eeb     JLE        LAB_00548f81
    //                               LAB_00548ef1                                                 XREF[1]:     00548f7b(j)  
    //         00548ef1     MOV        ECX,dword ptr [ESP + local_8]
    //         00548ef5     ADD        dword ptr [ESP + local_8],0x4
    //         00548efa     MOV        EBP,dword ptr [ECX]
    //         00548efc     TEST       EBP,EBP
    //         00548efe     JNZ        LAB_00548f28
    //         00548f00     TEST       EDI,EDI
    //         00548f02     JZ         LAB_00548f11
    //         00548f04     PUSH       EDI
    //         00548f05     PUSH       EBX
    //         00548f06     PUSH       EAX
    //         00548f07     XOR        EDI,EDI
    //         00548f09     CALL       FUN_00549040                                     undefined FUN_00549040()
    //         00548f0e     ADD        ESP,0xc
    //                               LAB_00548f11                                                 XREF[1]:     00548f02(j)  
    //         00548f11     INC        ESI
    //         00548f12     CMP        ESI,0x8a
    //         00548f18     JNZ        LAB_00548f75
    //         00548f1a     PUSH       ESI
    //         00548f1b     PUSH       EAX
    //         00548f1c     XOR        ESI,ESI
    //         00548f1e     CALL       FUN_005490a0                                     undefined FUN_005490a0()
    //         00548f23     ADD        ESP,0x8
    //         00548f26     JMP        LAB_00548f75
    //                               LAB_00548f28                                                 XREF[1]:     00548efe(j)  
    //         00548f28     TEST       ESI,ESI
    //         00548f2a     JZ         LAB_00548f38
    //         00548f2c     PUSH       ESI
    //         00548f2d     PUSH       EAX
    //         00548f2e     XOR        ESI,ESI
    //         00548f30     CALL       FUN_005490a0                                     undefined FUN_005490a0()
    //         00548f35     ADD        ESP,0x8
    //                               LAB_00548f38                                                 XREF[1]:     00548f2a(j)  
    //         00548f38     CMP        EBX,EBP
    //         00548f3a     JZ         LAB_00548f62
    //         00548f3c     TEST       EDI,EDI
    //         00548f3e     JZ         LAB_00548f4d
    //         00548f40     PUSH       EDI
    //         00548f41     PUSH       EBX
    //         00548f42     PUSH       EAX
    //         00548f43     XOR        EDI,EDI
    //         00548f45     CALL       FUN_00549040                                     undefined FUN_00549040()
    //         00548f4a     ADD        ESP,0xc
    //                               LAB_00548f4d                                                 XREF[1]:     00548f3e(j)  
    //         00548f4d     MOV        ECX,dword ptr [DAT_00887a80]
    //         00548f53     ADD        EAX,0x4
    //         00548f56     INC        dword ptr [ECX + EBP*0x4 + 0x36c20]
    //         00548f5d     MOV        dword ptr [EAX + -0x4],EBP
    //         00548f60     JMP        LAB_00548f75
    //                               LAB_00548f62                                                 XREF[1]:     00548f3a(j)  
    //         00548f62     INC        EDI
    //         00548f63     CMP        EDI,0x6
    //         00548f66     JNZ        LAB_00548f75
    //         00548f68     PUSH       EDI
    //         00548f69     PUSH       EBX
    //         00548f6a     PUSH       EAX
    //         00548f6b     XOR        EDI,EDI
    //         00548f6d     CALL       FUN_00549040                                     undefined FUN_00549040()
    //         00548f72     ADD        ESP,0xc
    //                               LAB_00548f75                                                 XREF[4]:     00548f18(j), 00548f26(j), 
    //                                                                                                         00548f60(j), 00548f66(j)  
    //         00548f75     MOV        EBX,EBP
    //         00548f77     DEC        dword ptr [ESP + local_4]
    //         00548f7b     JNZ        LAB_00548ef1
    //                               LAB_00548f81                                                 XREF[1]:     00548eeb(j)  
    //         00548f81     TEST       EDI,EDI
    //         00548f83     JZ         LAB_00548f92
    //         00548f85     PUSH       EDI
    //         00548f86     PUSH       EBX
    //         00548f87     PUSH       EAX
    //         00548f88     CALL       FUN_00549040                                     undefined FUN_00549040()
    //         00548f8d     ADD        ESP,0xc
    //         00548f90     JMP        LAB_00548fa0
    //                               LAB_00548f92                                                 XREF[1]:     00548f83(j)  
    //         00548f92     TEST       ESI,ESI
    //         00548f94     JZ         LAB_00548fa0
    //         00548f96     PUSH       ESI
    //         00548f97     PUSH       EAX
    //         00548f98     CALL       FUN_005490a0                                     undefined FUN_005490a0()
    //         00548f9d     ADD        ESP,0x8
    //                               LAB_00548fa0                                                 XREF[2]:     00548f90(j), 00548f94(j)  
    //         00548fa0     MOV        ECX,dword ptr [DAT_00887a80]
    //         00548fa6     MOV        dword ptr [ECX + 0x38104],EAX
    //         00548fac     MOV        EAX,[DAT_00887a80]
    //         00548fb1     ADD        EAX,0x3716c
    //         00548fb6     PUSH       EAX
    //         00548fb7     MOV        EAX,[DAT_00887a80]
    //         00548fbc     ADD        EAX,0x36c20
    //         00548fc1     PUSH       EAX
    //         00548fc2     PUSH       0x13
    //         00548fc4     CALL       FUN_00548b00                                     undefined FUN_00548b00()
    //         00548fc9     ADD        ESP,0xc
    //         00548fcc     MOV        EAX,[DAT_00887a80]
    //         00548fd1     ADD        EAX,0x3716c
    //         00548fd6     PUSH       EAX
    //         00548fd7     PUSH       0x13
    //         00548fd9     CALL       FUN_00548770                                     undefined FUN_00548770()
    //         00548fde     ADD        ESP,0x8
    //         00548fe1     PUSH       0x7
    //         00548fe3     CALL       FUN_00548cb0                                     undefined FUN_00548cb0()
    //         00548fe8     ADD        ESP,0x4
    //         00548feb     MOV        EAX,[DAT_00887a80]
    //         00548ff0     ADD        EAX,0x376b8
    //         00548ff5     PUSH       EAX
    //         00548ff6     PUSH       0x7
    //         00548ff8     MOV        EAX,[DAT_00887a80]
    //         00548ffd     ADD        EAX,0x3716c
    //         00549002     PUSH       EAX
    //         00549003     PUSH       0x13
    //         00549005     CALL       FUN_00548800                                     undefined FUN_00548800()
    //         0054900a     ADD        ESP,0x10
    //         0054900d     POP        EBP
    //         0054900e     POP        EDI
    //         0054900f     POP        ESI
    //         00549010     POP        EBX
    //         00549011     ADD        ESP,0x8
    //         00549014     RET
}

