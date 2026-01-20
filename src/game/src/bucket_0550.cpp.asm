// Auto-generated scaffold unit: bucket_0550.cpp.asm
#include "../include/common.h"

// Offset: 0x00550000
undefined FUN_00550000() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00550000()
    //              undefined         <UNASSIGNED>   <RETURN>
    //              undefined4        Stack[-0x8]:4  local_8                   XREF[4]:     0055005e(W), 00550061(W), 00550083(W), 0055008a(W)  
    //              undefined4        Stack[-0x14]:4 local_14                  XREF[1]:     00550098(R)  
    //              undefined4        Stack[-0x1c]:4 local_1c                  XREF[1]:     00550023(W)  
    //              undefined4        Stack[-0x20]:4 local_20                  XREF[1]:     00550040(W)  
    //              undefined4        Stack[-0x24]:4 local_24                  XREF[1]:     00550049(W)  
    //              undefined4        Stack[-0x28]:4 local_28                  XREF[1]:     0055002e(W)  
    //              undefined4        Stack[-0x2c]:4 local_2c                  XREF[1]:     00550037(W)  
    //              undefined4        Stack[-0x30]:4 local_30                  XREF[2]:     00550029(W), 00550080(W)  
    //                               FUN_00550000                                                 XREF[1]:     FUN_0054ff70:0054ffe1(c)  
    //         00550000     PUSH       EBP
    //         00550001     MOV        EBP,ESP
    //         00550003     PUSH       -0x1
    //         00550005     PUSH       DAT_00577ab8                                     = FFh
    //         0055000a     PUSH       __except_handler3
    //         0055000f     MOV        EAX,FS:[0x0]
    //         00550015     PUSH       EAX
    //         00550016     MOV        dword ptr FS:[0x0],ESP
    //         0055001d     ADD        ESP,-0x1c
    //         00550020     PUSH       EBX
    //         00550021     PUSH       ESI
    //         00550022     PUSH       EDI
    //         00550023     MOV        dword ptr [EBP + local_1c],ESP
    //         00550026     MOV        EAX,dword ptr [EBP + Stack[0x14]]
    //         00550029     MOV        dword ptr [EBP + local_30],EAX
    //         0055002c     XOR        ECX,ECX
    //         0055002e     MOV        dword ptr [EBP + local_28],ECX
    //         00550031     MOV        ESI,dword ptr [EBP + Stack[0x8]]
    //         00550034     MOV        EDX,dword ptr [ESI + -0x4]
    //         00550037     MOV        dword ptr [EBP + local_2c],EDX
    //         0055003a     MOV        EDX,dword ptr [_pCurrentException]               = 00000000
    //         00550040     MOV        dword ptr [EBP + local_20],EDX
    //         00550043     MOV        EDX,dword ptr [_pCurrentExContext]               = 00000000
    //         00550049     MOV        dword ptr [EBP + local_24],EDX
    //         0055004c     MOV        EDI,dword ptr [EBP + Stack[0x4]]
    //         0055004f     MOV        dword ptr [_pCurrentException],EDI               = 00000000
    //         00550055     MOV        EDX,dword ptr [EBP + Stack[0xc]]
    //         00550058     MOV        dword ptr [_pCurrentExContext],EDX               = 00000000
    //         0055005e     MOV        dword ptr [EBP + local_8],ECX
    //         00550061     MOV        dword ptr [EBP + local_8],0x1
    //         00550068     MOV        ECX,dword ptr [EBP + Stack[0x1c]]
    //         0055006b     PUSH       ECX
    //         0055006c     MOV        EDX,dword ptr [EBP + Stack[0x18]]
    //         0055006f     PUSH       EDX
    //         00550070     PUSH       EAX
    //         00550071     MOV        EAX,dword ptr [EBP + Stack[0x10]]
    //         00550074     PUSH       EAX
    //         00550075     PUSH       ESI
    //         00550076     CALL       _CallCatchBlock2                                 void * _CallCatchBlock2(EHRegistrationNode * 
    //         0055007b     ADD        ESP,0x14
    //         0055007e     MOV        EBX,EAX
    //         00550080     MOV        dword ptr [EBP + local_30],EBX
    //         00550083     MOV        dword ptr [EBP + local_8],0x0
    //         0055008a     MOV        dword ptr [EBP + local_8],0xffffffff
    //         00550091     CALL       FUN_005500ea                                     undefined FUN_005500ea()
    //         00550096     MOV        EAX,EBX
    //         00550098     MOV        ECX,dword ptr [EBP + local_14]
    //         0055009b     MOV        dword ptr FS:[0x0],ECX
    //         005500a2     POP        EDI
    //         005500a3     POP        ESI
    //         005500a4     POP        EBX
    //         005500a5     MOV        ESP,EBP
    //         005500a7     POP        EBP
    //         005500a8     RET
}

// Offset: 0x005500A9
undefined FUN_005500a9() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_005500a9()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_005500a9
    //         005500a9     MOV        ECX,dword ptr [EBP + -0x14]
    //         005500ac     PUSH       ECX
    //         005500ad     CALL       FUN_00550150                                     undefined FUN_00550150()
    //         005500b2     ADD        ESP,0x4
    //         005500b5     RET
}

// Offset: 0x005500B6
undefined FUN_005500b6() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_005500b6()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_005500b6
    //         005500b6     MOV        ESP,dword ptr [EBP + -0x18]
    //         005500b9     MOV        dword ptr [EBP + -0x2c],0x0
    //         005500c0     PUSH       -0x1
    //         005500c2     LEA        EDX,[EBP + -0x10]
    //         005500c5     PUSH       EDX=>DAT_fffffff8
    //         005500c6     CALL       __local_unwind2                                  undefined __local_unwind2()
    //         005500cb     ADD        ESP,0x8
    //         005500ce     XOR        EAX,EAX
    //         005500d0     MOV        ECX,dword ptr [EBP + DAT_fffffff0]
    //         005500d3     MOV        dword ptr FS:[0x0],ECX
    //         005500da     POP        EDI
    //         005500db     POP        ESI
    //         005500dc     POP        EBX
    //         005500dd     MOV        ESP,EBP
    //         005500df     POP        EBP
    //         005500e0     RET
}

// Offset: 0x005500E1
undefined FUN_005500e1() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_005500e1()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_005500e1
    //         005500e1     MOV        ESI,dword ptr [EBP + 0xc]
    //         005500e4     MOV        EDI,dword ptr [EBP + 0x8]
    //         005500e7     MOV        EBX,dword ptr [EBP + -0x2c]
}

// Offset: 0x005500EA
undefined FUN_005500ea() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_005500ea()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_005500ea                                                 XREF[1]:     FUN_00550000:00550091(c)  
    //         005500ea     MOV        EAX,dword ptr [EBP + -0x28]
    //         005500ed     MOV        dword ptr [ESI + -0x4],EAX
    //         005500f0     MOV        ECX,dword ptr [EBP + -0x1c]
    //         005500f3     MOV        dword ptr [_pCurrentException],ECX               = 00000000
    //         005500f9     MOV        EDX,dword ptr [EBP + -0x20]
    //         005500fc     MOV        dword ptr [_pCurrentExContext],EDX               = 00000000
    //         00550102     CMP        dword ptr [EDI],0xe06d7363
    //         00550108     JNZ        LAB_00550133
    //         0055010a     CMP        dword ptr [EDI + 0x10],0x3
    //         0055010e     JNZ        LAB_00550133
    //         00550110     CMP        dword ptr [EDI + 0x14],0x19930520
    //         00550117     JNZ        LAB_00550133
    //         00550119     MOV        EAX,dword ptr [EBP + -0x24]
    //         0055011c     TEST       EAX,EAX
    //         0055011e     JNZ        LAB_00550133
    //         00550120     TEST       EBX,EBX
    //         00550122     JZ         LAB_00550133
    //         00550124     CALL       __abnormal_termination                           undefined __abnormal_termination()
    //         00550129     PUSH       EAX
    //         0055012a     PUSH       EDI
    //         0055012b     CALL       _DestructExceptionObject                         void _DestructExceptionObject(EHExceptionReco
    //         00550130     ADD        ESP,0x8
    //                               LAB_00550133                                                 XREF[5]:     00550108(j), 0055010e(j), 
    //                                                                                                         00550117(j), 0055011e(j), 
    //                                                                                                         00550122(j)  
    //         00550133     RET
}

// Offset: 0x00550134
undefined FUN_00550134() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00550134()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00550134
    //         00550134     MOV        EAX,EBX
    //         00550136     MOV        ECX,dword ptr [EBP + DAT_fffffff0]
    //         00550139     MOV        dword ptr FS:[0x0],ECX
    //         00550140     POP        EDI
    //         00550141     POP        ESI
    //         00550142     POP        EBX
    //         00550143     MOV        ESP,EBP
    //         00550145     POP        EBP
    //         00550146     RET
}

// Offset: 0x00550150
undefined FUN_00550150() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00550150()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00550150                                                 XREF[1]:     FUN_005500a9:005500ad(c)  
    //         00550150     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         00550154     MOV        EAX,dword ptr [EAX]
    //         00550156     CMP        dword ptr [EAX],0xe06d7363
    //         0055015c     JNZ        LAB_0055017a
    //         0055015e     CMP        dword ptr [EAX + 0x10],0x3
    //         00550162     JNZ        LAB_0055017a
    //         00550164     CMP        dword ptr [EAX + 0x14],0x19930520
    //         0055016b     JNZ        LAB_0055017a
    //         0055016d     MOV        ECX,dword ptr [EAX + 0x1c]
    //         00550170     TEST       ECX,ECX
    //         00550172     JNZ        LAB_0055017a
    //         00550174     MOV        EAX,0x1
    //         00550179     RET
    //                               LAB_0055017a                                                 XREF[4]:     0055015c(j), 00550162(j), 
    //                                                                                                         0055016b(j), 00550172(j)  
    //         0055017a     XOR        EAX,EAX
    //         0055017c     RET
}

// Offset: 0x00550180
undefined FUN_00550180() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00550180()
    //              undefined         <UNASSIGNED>   <RETURN>
    //              undefined4        Stack[-0x8]:4  local_8                   XREF[1]:     005501d1(W)  
    //              undefined4        Stack[-0x14]:4 local_14
    //              undefined4        Stack[-0x1c]:4 local_1c                  XREF[1]:     005501a3(W)  
    //                               FUN_00550180                                                 XREF[1]:     FUN_0054ff70:0054ff8c(c)  
    //         00550180     PUSH       EBP
    //         00550181     MOV        EBP,ESP
    //         00550183     PUSH       -0x1
    //         00550185     PUSH       DAT_00577ad0                                     = FFh
    //         0055018a     PUSH       __except_handler3
    //         0055018f     MOV        EAX,FS:[0x0]
    //         00550195     PUSH       EAX
    //         00550196     MOV        dword ptr FS:[0x0],ESP
    //         0055019d     ADD        ESP,-0xc
    //         005501a0     PUSH       EBX
    //         005501a1     PUSH       ESI
    //         005501a2     PUSH       EDI
    //         005501a3     MOV        dword ptr [EBP + local_1c],ESP
    //         005501a6     MOV        ECX,dword ptr [EBP + Stack[0xc]]
    //         005501a9     MOV        EAX,dword ptr [ECX + 0x4]
    //         005501ac     TEST       EAX,EAX
    //         005501ae     JZ         LAB_00550370
    //         005501b4     MOV        DL,byte ptr [EAX + 0x8]
    //         005501b7     TEST       DL,DL
    //         005501b9     JZ         LAB_00550370
    //         005501bf     MOV        EAX,dword ptr [ECX + 0x8]
    //         005501c2     TEST       EAX,EAX
    //         005501c4     JZ         LAB_00550370
    //         005501ca     MOV        EDX,dword ptr [EBP + Stack[0x8]]
    //         005501cd     LEA        ESI,[EDX + EAX*0x1 + 0xc]
    //         005501d1     MOV        dword ptr [EBP + local_8],0x0
    //         005501d8     TEST       byte ptr [ECX],0x8
    //         005501db     JZ         LAB_00550225
    //         005501dd     MOV        EDI,dword ptr [EBP + Stack[0x4]]
    //         005501e0     PUSH       0x1
    //         005501e2     MOV        EAX,dword ptr [EDI + 0x18]
    //         005501e5     PUSH       EAX
    //         005501e6     CALL       _ValidateRead                                    int _ValidateRead(void * param_1, uint param_2)
    //         005501eb     ADD        ESP,0x8
    //         005501ee     TEST       EAX,EAX
    //         005501f0     JZ         LAB_00550354
    //         005501f6     PUSH       0x1
    //         005501f8     PUSH       ESI
    //         005501f9     CALL       _ValidateWrite                                   int _ValidateWrite(void * param_1, uint param
    //         005501fe     ADD        ESP,0x8
    //         00550201     TEST       EAX,EAX
    //         00550203     JZ         LAB_00550354
    //         00550209     MOV        EAX,dword ptr [EDI + 0x18]
    //         0055020c     MOV        dword ptr [ESI],EAX
    //         0055020e     MOV        ECX,dword ptr [EBP + Stack[0x10]]
    //         00550211     ADD        ECX,0x8
    //         00550214     PUSH       ECX
    //         00550215     PUSH       EAX
    //         00550216     CALL       FUN_00550410                                     undefined FUN_00550410()
    //         0055021b     ADD        ESP,0x8
    //         0055021e     MOV        dword ptr [ESI],EAX
    //         00550220     JMP        LAB_00550369
    //                               LAB_00550225                                                 XREF[1]:     005501db(j)  
    //         00550225     MOV        EDI,dword ptr [EBP + Stack[0x10]]
    //         00550228     TEST       byte ptr [EDI],0x1
    //         0055022b     JZ         LAB_00550292
    //         0055022d     MOV        EBX,dword ptr [EBP + Stack[0x4]]
    //         00550230     PUSH       0x1
    //         00550232     MOV        EDX,dword ptr [EBX + 0x18]
    //         00550235     PUSH       EDX
    //         00550236     CALL       _ValidateRead                                    int _ValidateRead(void * param_1, uint param_2)
    //         0055023b     ADD        ESP,0x8
    //         0055023e     TEST       EAX,EAX
    //         00550240     JZ         LAB_00550354
    //         00550246     PUSH       0x1
    //         00550248     PUSH       ESI
    //         00550249     CALL       _ValidateWrite                                   int _ValidateWrite(void * param_1, uint param
    //         0055024e     ADD        ESP,0x8
    //         00550251     TEST       EAX,EAX
    //         00550253     JZ         LAB_00550354
    //         00550259     MOV        EAX,dword ptr [EDI + 0x14]
    //         0055025c     PUSH       EAX
    //         0055025d     MOV        ECX,dword ptr [EBX + 0x18]
    //         00550260     PUSH       ECX
    //         00550261     PUSH       ESI
    //         00550262     CALL       memmove                                          undefined memmove()
    //         00550267     ADD        ESP,0xc
    //         0055026a     CMP        dword ptr [EDI + 0x14],0x4
    //         0055026e     JNZ        LAB_00550369
    //         00550274     MOV        EAX,dword ptr [ESI]
    //         00550276     TEST       EAX,EAX
    //         00550278     JZ         LAB_00550369
    //         0055027e     ADD        EDI,0x8
    //         00550281     PUSH       EDI
    //         00550282     PUSH       EAX
    //         00550283     CALL       FUN_00550410                                     undefined FUN_00550410()
    //         00550288     ADD        ESP,0x8
    //         0055028b     MOV        dword ptr [ESI],EAX
    //         0055028d     JMP        LAB_00550369
    //                               LAB_00550292                                                 XREF[1]:     0055022b(j)  
    //         00550292     MOV        EAX,dword ptr [EDI + 0x18]
    //         00550295     TEST       EAX,EAX
    //         00550297     MOV        EBX,dword ptr [EBP + Stack[0x4]]
    //         0055029a     PUSH       0x1
    //         0055029c     MOV        EDX,dword ptr [EBX + 0x18]
    //         0055029f     PUSH       EDX
    //         005502a0     JNZ        LAB_005502e8
    //         005502a2     CALL       _ValidateRead                                    int _ValidateRead(void * param_1, uint param_2)
    //         005502a7     ADD        ESP,0x8
    //         005502aa     TEST       EAX,EAX
    //         005502ac     JZ         LAB_00550354
    //         005502b2     PUSH       0x1
    //         005502b4     PUSH       ESI
    //         005502b5     CALL       _ValidateWrite                                   int _ValidateWrite(void * param_1, uint param
    //         005502ba     ADD        ESP,0x8
    //         005502bd     TEST       EAX,EAX
    //         005502bf     JZ         LAB_00550354
    //         005502c5     MOV        EAX,dword ptr [EDI + 0x14]
    //         005502c8     PUSH       EAX
    //         005502c9     ADD        EDI,0x8
    //         005502cc     PUSH       EDI
    //         005502cd     MOV        ECX,dword ptr [EBX + 0x18]
    //         005502d0     PUSH       ECX
    //         005502d1     CALL       FUN_00550410                                     undefined FUN_00550410()
    //         005502d6     ADD        ESP,0x8
    //         005502d9     PUSH       EAX
    //         005502da     PUSH       ESI
    //         005502db     CALL       memmove                                          undefined memmove()
    //         005502e0     ADD        ESP,0xc
    //         005502e3     JMP        LAB_00550369
    //                               LAB_005502e8                                                 XREF[1]:     005502a0(j)  
    //         005502e8     CALL       _ValidateRead                                    int _ValidateRead(void * param_1, uint param_2)
    //         005502ed     ADD        ESP,0x8
    //         005502f0     TEST       EAX,EAX
    //         005502f2     JZ         LAB_00550354
    //         005502f4     PUSH       0x1
    //         005502f6     PUSH       ESI
    //         005502f7     CALL       _ValidateWrite                                   int _ValidateWrite(void * param_1, uint param
    //         005502fc     ADD        ESP,0x8
    //         005502ff     TEST       EAX,EAX
    //         00550301     JZ         LAB_00550354
    //         00550303     MOV        EAX,dword ptr [EDI + 0x18]
    //         00550306     PUSH       EAX
    //         00550307     CALL       _ValidateExecute                                 int _ValidateExecute(_func_int * param_1)
    //         0055030c     ADD        ESP,0x4
    //         0055030f     TEST       EAX,EAX
    //         00550311     JZ         LAB_00550354
    //         00550313     TEST       byte ptr [EDI],0x4
    //         00550316     JZ         LAB_00550337
    //         00550318     PUSH       0x1
    //         0055031a     LEA        ECX,[EDI + 0x8]
    //         0055031d     PUSH       ECX
    //         0055031e     MOV        EDX,dword ptr [EBX + 0x18]
    //         00550321     PUSH       EDX
    //         00550322     CALL       FUN_00550410                                     undefined FUN_00550410()
    //         00550327     ADD        ESP,0x8
    //         0055032a     PUSH       EAX
    //         0055032b     MOV        EAX,dword ptr [EDI + 0x18]
    //         0055032e     PUSH       EAX
    //         0055032f     PUSH       ESI
    //         00550330     CALL       _CallMemberFunction2                             void _CallMemberFunction2(void * param_1, voi
    //         00550335     JMP        LAB_00550369
    //                               LAB_00550337                                                 XREF[1]:     00550316(j)  
    //         00550337     LEA        ECX,[EDI + 0x8]
    //         0055033a     PUSH       ECX
    //         0055033b     MOV        EDX,dword ptr [EBX + 0x18]
    //         0055033e     PUSH       EDX
    //         0055033f     CALL       FUN_00550410                                     undefined FUN_00550410()
    //         00550344     ADD        ESP,0x8
    //         00550347     PUSH       EAX
    //         00550348     MOV        EAX,dword ptr [EDI + 0x18]
    //         0055034b     PUSH       EAX
    //         0055034c     PUSH       ESI
    //         0055034d     CALL       _CallMemberFunction1                             void _CallMemberFunction1(void * param_1, voi
    //         00550352     JMP        LAB_00550369
    //                               LAB_00550354                                                 XREF[9]:     005501f0(j), 00550203(j), 
    //                                                                                                         00550240(j), 00550253(j), 
    //                                                                                                         005502ac(j), 005502bf(j), 
    //                                                                                                         005502f2(j), 00550301(j), 
    //                                                                                                         00550311(j)  
    //         00550354     CALL       _inconsistency                                   void _inconsistency(void)
    //         00550359     JMP        LAB_00550369
}

// Offset: 0x0055035B
undefined FUN_0055035b() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0055035b()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0055035b
    //         0055035b     MOV        EAX,0x1
    //         00550360     RET
}

// Offset: 0x00550361
undefined FUN_00550361() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00550361()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00550361
    //         00550361     MOV        ESP,dword ptr [EBP + -0x18]
    //         00550364     CALL       terminate                                        void terminate(void)
    //                               LAB_00550369                                                 XREF[8]:     FUN_00550180:00550220(j), 
    //                                                                                                         FUN_00550180:0055026e(j), 
    //                                                                                                         FUN_00550180:00550278(j), 
    //                                                                                                         FUN_00550180:0055028d(j), 
    //                                                                                                         FUN_00550180:005502e3(j), 
    //                                                                                                         FUN_00550180:00550335(j), 
    //                                                                                                         FUN_00550180:00550352(j), 
    //                                                                                                         FUN_00550180:00550359(j)  
    //         00550369     MOV        dword ptr [EBP + -0x4],0xffffffff
    //                               LAB_00550370                                                 XREF[3]:     FUN_00550180:005501ae(j), 
    //                                                                                                         FUN_00550180:005501b9(j), 
    //                                                                                                         FUN_00550180:005501c4(j)  
    //         00550370     MOV        ECX,dword ptr [EBP + -0x10]
    //         00550373     MOV        dword ptr FS:[0x0],ECX
    //         0055037a     POP        EDI
    //         0055037b     POP        ESI
    //         0055037c     POP        EBX
    //         0055037d     MOV        ESP,EBP
    //         0055037f     POP        EBP
    //         00550380     RET
}

// Offset: 0x00550390
void DestructExceptionObject(EHExceptionRecord* param_1, uchar param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * void __cdecl _DestructExceptionObject(struct EHExceptionRecord *,unsigned char)                       *
    //                              *********************************************************************************************************
    //                              void __cdecl _DestructExceptionObject(EHExceptionRecord * param_1, u
    //              void              <VOID>         <RETURN>
    //              EHExceptionRec    Stack[0x4]:4   param_1                   XREF[1]:     005503b6(R)  
    //              uchar             Stack[0x8]:1   param_2
    //              undefined4        Stack[-0x8]:4  local_8                   XREF[1]:     005503c7(W)  
    //              undefined4        Stack[-0x14]:4 local_14
    //              undefined4        Stack[-0x1c]:4 local_1c                  XREF[1]:     005503b3(W)  
    //                               ?_DestructExceptionObject@@YAXPAUEHExceptionRecord@@E@Z      XREF[2]:     FUN_0054fb10:0054fd6b(c), 
    //                               _DestructExceptionObject                                                  FUN_005500ea:0055012b(c)  
    //         00550390     PUSH       EBP
    //         00550391     MOV        EBP,ESP
    //         00550393     PUSH       -0x1
    //         00550395     PUSH       DAT_00577ae0                                     = FFh
    //         0055039a     PUSH       __except_handler3
    //         0055039f     MOV        EAX,FS:[0x0]
    //         005503a5     PUSH       EAX
    //         005503a6     MOV        dword ptr FS:[0x0],ESP
    //         005503ad     SUB        ESP,0x8
    //         005503b0     PUSH       EBX
    //         005503b1     PUSH       ESI
    //         005503b2     PUSH       EDI
    //         005503b3     MOV        dword ptr [EBP + local_1c],ESP
    //         005503b6     MOV        ECX,dword ptr [EBP + param_1]
    //         005503b9     TEST       ECX,ECX
    //         005503bb     JZ         LAB_005503f4
    //         005503bd     MOV        EAX,dword ptr [ECX + 0x1c]
    //         005503c0     MOV        EAX,dword ptr [EAX + 0x4]
    //         005503c3     TEST       EAX,EAX
    //         005503c5     JZ         LAB_005503f4
    //         005503c7     MOV        dword ptr [EBP + local_8],0x0
    //         005503ce     PUSH       EAX
    //         005503cf     MOV        ECX,dword ptr [ECX + 0x18]
    //         005503d2     PUSH       ECX
    //         005503d3     CALL       _CallMemberFunction0                             void _CallMemberFunction0(void * param_1, voi
    //         005503d8     JMP        LAB_005503ed
}

// Offset: 0x005503DA
undefined FUN_005503da() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_005503da()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_005503da
    //         005503da     XOR        EAX,EAX
    //         005503dc     MOV        CL,byte ptr [EBP + 0xc]
    //         005503df     TEST       CL,CL
    //         005503e1     SETNZ      AL
    //         005503e4     RET
}

// Offset: 0x005503E5
undefined FUN_005503e5() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_005503e5()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_005503e5
    //         005503e5     MOV        ESP,dword ptr [EBP + -0x18]
    //         005503e8     CALL       terminate                                        void terminate(void)
    //                               LAB_005503ed                                                 XREF[1]:     _DestructExceptionObject:005503d8(
    //         005503ed     MOV        dword ptr [EBP + -0x4],0xffffffff
    //                               LAB_005503f4                                                 XREF[2]:     _DestructExceptionObject:005503bb(
    //                                                                                                         _DestructExceptionObject:005503c5(
    //         005503f4     MOV        ECX,dword ptr [EBP + -0x10]
    //         005503f7     MOV        dword ptr FS:[0x0],ECX
    //         005503fe     POP        EDI
    //         005503ff     POP        ESI
    //         00550400     POP        EBX
    //         00550401     MOV        ESP,EBP
    //         00550403     POP        EBP
    //         00550404     RET
}

// Offset: 0x00550410
undefined FUN_00550410() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00550410()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00550410                                                 XREF[5]:     FUN_00550180:00550216(c), 
    //                                                                                                         FUN_00550180:00550283(c), 
    //                                                                                                         FUN_00550180:005502d1(c), 
    //                                                                                                         FUN_00550180:00550322(c), 
    //                                                                                                         FUN_00550180:0055033f(c)  
    //         00550410     MOV        EDX,dword ptr [ESP + Stack[0x8]]
    //         00550414     PUSH       ESI
    //         00550415     MOV        ESI,dword ptr [ESP + Stack[0x4]]
    //         00550419     MOV        ECX,dword ptr [EDX]
    //         0055041b     MOV        EAX,ESI
    //         0055041d     ADD        EAX,ECX
    //         0055041f     MOV        ECX,dword ptr [EDX + 0x4]
    //         00550422     TEST       ECX,ECX
    //         00550424     JL         LAB_00550433
    //         00550426     MOV        ESI,dword ptr [ESI + ECX*0x1]
    //         00550429     MOV        EDX,dword ptr [EDX + 0x8]
    //         0055042c     MOV        EDX,dword ptr [ESI + EDX*0x1]
    //         0055042f     ADD        EDX,ECX
    //         00550431     ADD        EAX,EDX
    //                               LAB_00550433                                                 XREF[1]:     00550424(j)  
    //         00550433     POP        ESI
    //         00550434     RET
}

// Offset: 0x00550440
undefined CallSettingFrame_12() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined __CallSettingFrame@12()
    //              undefined         <UNASSIGNED>   <RETURN>
    //              undefined4        Stack[-0x8]:4  local_8                   XREF[2]:     0055044e(W), 0055045b(R)  
    //                               __CallSettingFrame@12                                        XREF[2]:     _CallCatchBlock2:0054b345(c), 
    //                                                                                                         ___FrameUnwindToState:0054feef(c)  
    //         00550440     PUSH       EBP
    //         00550441     MOV        EBP,ESP
    //         00550443     SUB        ESP,0x4
    //         00550446     PUSH       EBX
    //         00550447     PUSH       ECX
    //         00550448     MOV        EAX,dword ptr [EBP + Stack[0x8]]
    //         0055044b     ADD        EAX,0xc
    //         0055044e     MOV        dword ptr [EBP + local_8],EAX
    //         00550451     MOV        EAX,dword ptr [EBP + Stack[0x4]]
    //         00550454     PUSH       EBP
    //         00550455     PUSH       dword ptr [EBP + Stack[0xc]]
    //         00550458     MOV        ECX,dword ptr [EBP + Stack[0xc]]
    //         0055045b     MOV        EBP,dword ptr [EBP + local_8]
    //         0055045e     CALL       __NLG_Notify1                                    undefined __NLG_Notify1()
    //         00550463     PUSH       ESI
    //         00550464     PUSH       EDI
    //         00550465     CALL       EAX
    //                               __NLG_Return
    //         00550467     POP        EDI
    //         00550468     POP        ESI
    //         00550469     MOV        EBX,EBP
    //         0055046b     POP        EBP
    //         0055046c     MOV        ECX,dword ptr [EBP + 0x10]
    //         0055046f     PUSH       EBP
    //         00550470     MOV        EBP,EBX
    //         00550472     CMP        ECX,0x100
    //         00550478     JNZ        LAB_0055047f
    //         0055047a     MOV        ECX,0x2
    //                               LAB_0055047f                                                 XREF[1]:     00550478(j)  
    //         0055047f     PUSH       ECX
    //         00550480     CALL       __NLG_Notify1                                    undefined __NLG_Notify1()
    //         00550485     POP        EBP
    //         00550486     POP        ECX
    //         00550487     POP        EBX
    //         00550488     LEAVE
    //         00550489     RET        0xc
}

// Offset: 0x00550490
void terminate() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * void __cdecl terminate(void)                                                                          *
    //                              *********************************************************************************************************
    //                              void __cdecl terminate(void)
    //              void              <VOID>         <RETURN>
    //              undefined4        Stack[-0x8]:4  local_8                   XREF[2]:     005504b6(W), 005504c6(W)  
    //              undefined4        Stack[-0x14]:4 local_14
    //              undefined4        Stack[-0x1c]:4 local_1c                  XREF[1]:     005504b3(W)  
    //                               ?terminate@@YAXXZ                                            XREF[12]:    FUN_0054d8a0:0054d8ae(c), 
    //                               terminate                                                                 FUN_0054fb10:0054fdb3(c), 
    //                                                                                                         FUN_0054ff50:0054ff5e(c), 
    //                                                                                                         FUN_00550361:00550364(c), 
    //                                                                                                         FUN_005503e5:005503e8(c), 
    //                                                                                                         unexpected:00550529(c), 
    //                                                                                                         unexpected:0055052b(c), 
    //                                                                                                         _inconsistency:0055056d(c), 
    //                                                                                                         FUN_0055059e:0055059e(c), 
    //                                                                                                         __CxxUnhandledExceptionFilter:0055
    //                                                                                                         0058fbc0(*), 0058fbc4(*)  
    //         00550490     PUSH       EBP
    //         00550491     MOV        EBP,ESP
    //         00550493     PUSH       -0x1
    //         00550495     PUSH       DAT_00577af0                                     = FFh
    //         0055049a     PUSH       __except_handler3
    //         0055049f     MOV        EAX,FS:[0x0]
    //         005504a5     PUSH       EAX
    //         005504a6     MOV        dword ptr FS:[0x0],ESP
    //         005504ad     SUB        ESP,0x8
    //         005504b0     PUSH       EBX
    //         005504b1     PUSH       ESI
    //         005504b2     PUSH       EDI
    //         005504b3     MOV        dword ptr [EBP + local_1c],ESP
    //         005504b6     MOV        dword ptr [EBP + local_8],0x0
    //         005504bd     MOV        EAX,[__pTerminate]                               = 00000000
    //         005504c2     TEST       EAX,EAX
    //         005504c4     JZ         LAB_005504e1
    //         005504c6     MOV        dword ptr [EBP + local_8],0x1
    //         005504cd     CALL       EAX
    //         005504cf     JMP        LAB_005504da
}

// Offset: 0x005504D1
undefined FUN_005504d1() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_005504d1()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_005504d1
    //         005504d1     MOV        EAX,0x1
    //         005504d6     RET
}

// Offset: 0x005504D7
undefined FUN_005504d7() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_005504d7()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_005504d7
    //         005504d7     MOV        ESP,dword ptr [EBP + -0x18]
    //                               LAB_005504da                                                 XREF[1]:     terminate:005504cf(j)  
    //         005504da     MOV        dword ptr [EBP + -0x4],0x0
    //                               LAB_005504e1                                                 XREF[1]:     terminate:005504c4(j)  
    //         005504e1     MOV        dword ptr [EBP + -0x4],0xffffffff
    //         005504e8     CALL       FUN_005504fe                                     undefined FUN_005504fe()
    //         005504ed     MOV        ECX,dword ptr [EBP + -0x10]
    //         005504f0     MOV        dword ptr FS:[0x0],ECX
    //         005504f7     POP        EDI
    //         005504f8     POP        ESI
    //         005504f9     POP        EBX
    //         005504fa     MOV        ESP,EBP
    //         005504fc     POP        EBP
    //         005504fd     RET
}

// Offset: 0x005504FE
undefined FUN_005504fe() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_005504fe()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_005504fe                                                 XREF[1]:     FUN_005504d7:005504e8(c)  
    //         005504fe     CALL       abort                                            undefined abort()
    //         00550503     RET
}

// Offset: 0x00550504
undefined FUN_00550504() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00550504()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00550504
    //         00550504     MOV        ECX,dword ptr [EBP + DAT_fffffff0]
    //         00550507     MOV        dword ptr FS:[0x0],ECX
    //         0055050e     POP        EDI
    //         0055050f     POP        ESI
    //         00550510     POP        EBX
    //         00550511     MOV        ESP,EBP
    //         00550513     POP        EBP
    //         00550514     RET
}

// Offset: 0x00550520
void unexpected() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * void __cdecl unexpected(void)                                                                         *
    //                              *********************************************************************************************************
    //                              void __cdecl unexpected(void)
    //              void              <VOID>         <RETURN>
    //                               ?unexpected@@YAXXZ
    //                               unexpected
    //         00550520     MOV        EAX,[->terminate]                                = 00550490
    //         00550525     TEST       EAX,EAX
    //         00550527     JZ         LAB_0055052b
    //         00550529     CALL       EAX=>terminate                                   void terminate(void)
    //                               LAB_0055052b                                                 XREF[1]:     00550527(j)  
    //         0055052b     JMP        terminate                                        void terminate(void)
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
}

// Offset: 0x00550530
void inconsistency() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * void __cdecl _inconsistency(void)                                                                     *
    //                              *********************************************************************************************************
    //                              void __cdecl _inconsistency(void)
    //              void              <VOID>         <RETURN>
    //              undefined4        Stack[-0x8]:4  local_8                   XREF[2]:     00550556(W), 00550566(W)  
    //              undefined4        Stack[-0x14]:4 local_14
    //              undefined4        Stack[-0x1c]:4 local_1c                  XREF[1]:     00550553(W)  
    //                               ?_inconsistency@@YAXXZ                                       XREF[8]:     _GetRangeOfTrysToCheck:0054b514(c)
    //                               _inconsistency                                                            _GetRangeOfTrysToCheck:0054b55a(c)
    //                                                                                                         ___InternalCxxFrameHandler:0054fa4
    //                                                                                                         FUN_0054fb10:0054fb30(c), 
    //                                                                                                         FUN_0054fb10:0054fb8c(c), 
    //                                                                                                         FUN_0054fb10:0054fbae(c), 
    //                                                                                                         ___FrameUnwindToState:0054fed1(c), 
    //                                                                                                         FUN_00550180:00550354(c)  
    //         00550530     PUSH       EBP
    //         00550531     MOV        EBP,ESP
    //         00550533     PUSH       -0x1
    //         00550535     PUSH       DAT_00577b08                                     = FFh
    //         0055053a     PUSH       __except_handler3
    //         0055053f     MOV        EAX,FS:[0x0]
    //         00550545     PUSH       EAX
    //         00550546     MOV        dword ptr FS:[0x0],ESP
    //         0055054d     SUB        ESP,0x8
    //         00550550     PUSH       EBX
    //         00550551     PUSH       ESI
    //         00550552     PUSH       EDI
    //         00550553     MOV        dword ptr [EBP + local_1c],ESP
    //         00550556     MOV        dword ptr [EBP + local_8],0x0
    //         0055055d     MOV        EAX,[->terminate]                                = 00550490
    //         00550562     TEST       EAX,EAX
    //         00550564     JZ         LAB_00550581
    //         00550566     MOV        dword ptr [EBP + local_8],0x1
    //         0055056d     CALL       EAX=>terminate                                   void terminate(void)
    //         0055056f     JMP        LAB_0055057a
}

// Offset: 0x00550571
undefined FUN_00550571() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00550571()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00550571
    //         00550571     MOV        EAX,0x1
    //         00550576     RET
}

// Offset: 0x00550577
undefined FUN_00550577() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00550577()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00550577
    //         00550577     MOV        ESP,dword ptr [EBP + -0x18]
    //                               LAB_0055057a                                                 XREF[1]:     _inconsistency:0055056f(j)  
    //         0055057a     MOV        dword ptr [EBP + -0x4],0x0
    //                               LAB_00550581                                                 XREF[1]:     _inconsistency:00550564(j)  
    //         00550581     MOV        dword ptr [EBP + -0x4],0xffffffff
    //         00550588     CALL       FUN_0055059e                                     undefined FUN_0055059e()
    //         0055058d     MOV        ECX,dword ptr [EBP + -0x10]
    //         00550590     MOV        dword ptr FS:[0x0],ECX
    //         00550597     POP        EDI
    //         00550598     POP        ESI
    //         00550599     POP        EBX
    //         0055059a     MOV        ESP,EBP
    //         0055059c     POP        EBP
    //         0055059d     RET
}

// Offset: 0x0055059E
undefined FUN_0055059e() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0055059e()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0055059e                                                 XREF[1]:     FUN_00550577:00550588(c)  
    //         0055059e     CALL       terminate                                        void terminate(void)
    //         005505a3     RET
}

// Offset: 0x005505A4
undefined FUN_005505a4() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_005505a4()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_005505a4
    //         005505a4     MOV        ECX,dword ptr [EBP + DAT_fffffff0]
    //         005505a7     MOV        dword ptr FS:[0x0],ECX
    //         005505ae     POP        EDI
    //         005505af     POP        ESI
    //         005505b0     POP        EBX
    //         005505b1     MOV        ESP,EBP
    //         005505b3     POP        EBP
    //         005505b4     RET
}

// Offset: 0x005505C0
undefined setdefaultprecision() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined __setdefaultprecision()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               __setdefaultprecision                                        XREF[2]:     __fpmath:0054b67f(c), 
    //                                                                                                         FUN_005577a8:005577b9(c)  
    //         005505c0     PUSH       0x30000
    //         005505c5     PUSH       0x10000
    //         005505ca     CALL       __controlfp                                      undefined __controlfp()
    //         005505cf     ADD        ESP,0x8
    //         005505d2     RET
}

// Offset: 0x005505E0
undefined ms_p5_test_fdiv() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined __ms_p5_test_fdiv()
    //              undefined         <UNASSIGNED>   <RETURN>
    //              undefined4        Stack[-0x8]:4  local_8                   XREF[1]:     005505ed(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     005505e6(W)  
    //              undefined8        Stack[-0x14]:8 local_14                  XREF[3,1]:   005505f4(W), 00550602(R), 0055060b(R), 005505fb(W)  
    //              undefined8        Stack[-0x1c]:8 local_1c                  XREF[2]:     0055060e(W), 00550611(R)  
    //                               __ms_p5_test_fdiv                                            XREF[1]:     __ms_p5_mp_test_fdiv:00550654(c)  
    //         005505e0     PUSH       EBP
    //         005505e1     MOV        EBP,ESP
    //         005505e3     SUB        ESP,0x18
    //         005505e6     MOV        dword ptr [EBP + local_c],offset DAT_fffffff4
    //         005505ed     MOV        dword ptr [EBP + local_8],offset DAT_fffffff8
    //         005505f4     MOV        dword ptr [EBP + local_14],0xc0000000
    //         005505fb     MOV        dword ptr [EBP + local_14+0x4],offset DAT_ffff
    //         00550602     FLD        double ptr [EBP + local_14]
    //         00550605     FDIV       double ptr [EBP + -0x8]=>DAT_fffffff4
    //         00550608     FMUL       double ptr [EBP + -0x8]=>DAT_fffffff4
    //         0055060b     FSUBR      double ptr [EBP + local_14]
    //         0055060e     FSTP       double ptr [EBP + local_1c]
    //         00550611     FLD        double ptr [EBP + local_1c]
    //         00550614     FCOMP      double ptr [DAT_00577b20]
    //         0055061a     FNSTSW     AX
    //         0055061c     TEST       AH,0x41
    //         0055061f     JNZ        LAB_0055062a
    //         00550621     MOV        EAX,0x1
    //         00550626     MOV        ESP,EBP
    //         00550628     POP        EBP
    //         00550629     RET
    //                               LAB_0055062a                                                 XREF[1]:     0055061f(j)  
    //         0055062a     XOR        EAX,EAX
    //         0055062c     MOV        ESP,EBP
    //         0055062e     POP        EBP
    //         0055062f     RET
}

// Offset: 0x00550630
undefined ms_p5_mp_test_fdiv() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined __ms_p5_mp_test_fdiv()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               __ms_p5_mp_test_fdiv                                         XREF[1]:     __fpmath:0054b675(c)  
    //         00550630     PUSH       s_KERNEL32                                       = "KERNEL32"
    //         00550635     CALL       dword ptr [->KERNEL32.DLL::GetModuleHandleA]     = 0048ab4c
    //         0055063b     TEST       EAX,EAX
    //         0055063d     JZ         LAB_00550654
    //         0055063f     PUSH       s_IsProcessorFeaturePresent                      = "IsProcessorFeaturePresent"
    //         00550644     PUSH       EAX=>DAT_fffffff8
    //         00550645     CALL       dword ptr [->KERNEL32.DLL::GetProcAddress]       = 0048abb0
    //         0055064b     TEST       EAX,EAX
    //         0055064d     JZ         LAB_00550654
    //         0055064f     PUSH       0x0
    //         00550651     CALL       EAX
    //         00550653     RET
    //                               LAB_00550654                                                 XREF[2]:     0055063d(j), 0055064d(j)  
    //         00550654     JMP        __ms_p5_test_fdiv                                undefined __ms_p5_test_fdiv()
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
}

// Offset: 0x00550660
undefined forcdecpt() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined __forcdecpt()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               __forcdecpt                                                  XREF[1]:     __cfltcvt_init:0054b6be(*)  
    //         00550660     PUSH       ESI
    //         00550661     MOV        ESI,dword ptr [ESP + Stack[0x4]]
    //         00550665     MOVSX      EAX,byte ptr [ESI]
    //         00550668     PUSH       EAX
    //         00550669     CALL       tolower                                          undefined tolower()
    //         0055066e     ADD        ESP,0x4
    //         00550671     CMP        EAX,0x65
    //         00550674     JZ         LAB_005506a3
    //                               LAB_00550676                                                 XREF[1]:     005506a1(j)  
    //         00550676     MOV        EAX,[___mb_cur_max]                              = 00000001h
    //         0055067b     INC        ESI
    //         0055067c     CMP        EAX,0x1
    //         0055067f     JLE        LAB_00550691
    //         00550681     MOVSX      ECX,byte ptr [ESI]
    //         00550684     PUSH       0x4
    //         00550686     PUSH       ECX
    //         00550687     CALL       __isctype                                        undefined __isctype()
    //         0055068c     ADD        ESP,0x8
    //         0055068f     JMP        LAB_0055069f
    //                               LAB_00550691                                                 XREF[1]:     0055067f(j)  
    //         00550691     MOVSX      EDX,byte ptr [ESI]
    //         00550694     MOV        EAX,[__pctype]                                   = 005920da
    //         00550699     MOV        AL,byte ptr [EAX + EDX*0x2]=>DAT_005920da        = 20h     
    //         0055069c     AND        EAX,0x4
    //                               LAB_0055069f                                                 XREF[1]:     0055068f(j)  
    //         0055069f     TEST       EAX,EAX
    //         005506a1     JNZ        LAB_00550676
    //                               LAB_005506a3                                                 XREF[1]:     00550674(j)  
    //         005506a3     MOV        CL,byte ptr [___decimal_point]                   = 2Eh
    //         005506a9     MOV        AL,byte ptr [ESI]
    //         005506ab     MOV        byte ptr [ESI],CL
    //         005506ad     INC        ESI
    //                               LAB_005506ae                                                 XREF[1]:     005506b9(j)  
    //         005506ae     MOV        CL,byte ptr [ESI]
    //         005506b0     MOV        byte ptr [ESI],AL
    //         005506b2     MOV        DL,byte ptr [ESI]
    //         005506b4     INC        ESI
    //         005506b5     TEST       DL,DL
    //         005506b7     MOV        AL,CL
    //         005506b9     JNZ        LAB_005506ae
    //         005506bb     POP        ESI
    //         005506bc     RET
}

// Offset: 0x005506BD
undefined FUN_005506bd() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_005506bd()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_005506bd
    //         005506bd     NOP
    //         005506be     NOP
    //         005506bf     NOP
    //                               __cropzeros                                                  XREF[1]:     __cfltcvt_init:0054b6a5(*)  
    //         005506c0     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         005506c4     PUSH       EBX
    //         005506c5     MOV        BL,byte ptr [___decimal_point]                   = 2Eh
    //         005506cb     MOV        CL,byte ptr [EAX]
    //         005506cd     TEST       CL,CL
    //         005506cf     JZ         LAB_005506dd
    //                               LAB_005506d1                                                 XREF[1]:     005506db(j)  
    //         005506d1     CMP        CL,BL
    //         005506d3     JZ         LAB_005506dd
    //         005506d5     MOV        CL,byte ptr [EAX + 0x1]
    //         005506d8     INC        EAX
    //         005506d9     TEST       CL,CL
    //         005506db     JNZ        LAB_005506d1
    //                               LAB_005506dd                                                 XREF[2]:     005506cf(j), 005506d3(j)  
    //         005506dd     MOV        CL,byte ptr [EAX]
    //         005506df     INC        EAX
    //         005506e0     TEST       CL,CL
    //         005506e2     JZ         LAB_00550729
    //         005506e4     MOV        CL,byte ptr [EAX]
    //         005506e6     TEST       CL,CL
    //         005506e8     JZ         LAB_005506fc
    //                               LAB_005506ea                                                 XREF[1]:     005506fa(j)  
    //         005506ea     CMP        CL,0x65
    //         005506ed     JZ         LAB_005506fc
    //         005506ef     CMP        CL,0x45
    //         005506f2     JZ         LAB_005506fc
    //         005506f4     MOV        CL,byte ptr [EAX + 0x1]
    //         005506f7     INC        EAX
    //         005506f8     TEST       CL,CL
    //         005506fa     JNZ        LAB_005506ea
    //                               LAB_005506fc                                                 XREF[3]:     005506e8(j), 005506ed(j), 
    //                                                                                                         005506f2(j)  
    //         005506fc     MOV        CL,byte ptr [EAX + -0x1]
    //         005506ff     MOV        EDX,EAX
    //         00550701     DEC        EAX
    //         00550702     CMP        CL,0x30
    //         00550705     JNZ        LAB_00550710
    //                               LAB_00550707                                                 XREF[1]:     0055070e(j)  
    //         00550707     MOV        CL,byte ptr [EAX + -0x1]
    //         0055070a     DEC        EAX
    //         0055070b     CMP        CL,0x30
    //         0055070e     JZ         LAB_00550707
    //                               LAB_00550710                                                 XREF[1]:     00550705(j)  
    //         00550710     CMP        byte ptr [EAX],BL
    //         00550712     JNZ        LAB_00550715
    //         00550714     DEC        EAX
    //                               LAB_00550715                                                 XREF[1]:     00550712(j)  
    //         00550715     MOV        CL,byte ptr [EDX]
    //         00550717     INC        EAX
    //         00550718     INC        EDX
    //         00550719     TEST       CL,CL
    //         0055071b     MOV        byte ptr [EAX],CL
    //         0055071d     JZ         LAB_00550729
    //                               LAB_0055071f                                                 XREF[1]:     00550727(j)  
    //         0055071f     MOV        CL,byte ptr [EDX]
    //         00550721     INC        EAX
    //         00550722     INC        EDX
    //         00550723     TEST       CL,CL
    //         00550725     MOV        byte ptr [EAX],CL
    //         00550727     JNZ        LAB_0055071f
    //                               LAB_00550729                                                 XREF[2]:     005506e2(j), 0055071d(j)  
    //         00550729     POP        EBX
    //         0055072a     RET
}

// Offset: 0x0055072B
undefined FUN_0055072b() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0055072b()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0055072b
    //         0055072b     NOP
    //         0055072c     NOP
    //         0055072d     NOP
    //         0055072e     NOP
    //         0055072f     NOP
    //                               __positive                                                   XREF[1]:     __cfltcvt_init:0054b6c8(*)  
    //         00550730     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         00550734     FLD        double ptr [EAX]
    //         00550736     FCOMP      double ptr [null_00577b50]                       = align(8)
    //         0055073c     FNSTSW     AX
    //         0055073e     TEST       AH,0x1
    //         00550741     JNZ        LAB_00550749
    //         00550743     MOV        EAX,0x1
    //         00550748     RET
    //                               LAB_00550749                                                 XREF[1]:     00550741(j)  
    //         00550749     XOR        EAX,EAX
    //         0055074b     RET
}

// Offset: 0x0055074C
undefined FUN_0055074c() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0055074c()
    //              undefined         <UNASSIGNED>   <RETURN>
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     00550772(R)  
    //              undefined4        Stack[-0x8]:4  local_8                   XREF[2]:     0055075f(*), 0055076e(R)  
    //                               FUN_0055074c
    //         0055074c     NOP
    //         0055074d     NOP
    //         0055074e     NOP
    //         0055074f     NOP
    //                               __fassign                                                    XREF[1]:     __cfltcvt_init:0054b6b4(*)  
    //         00550750     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         00550754     SUB        ESP,0x8
    //         00550757     TEST       EAX,EAX
    //         00550759     JZ         LAB_00550782
    //         0055075b     MOV        EAX,dword ptr [ESP + Stack[0xc]]
    //         0055075f     LEA        ECX=>local_8,[ESP]
    //         00550763     PUSH       EAX
    //         00550764     PUSH       ECX
    //         00550765     CALL       __atodbl                                         undefined __atodbl()
    //         0055076a     MOV        EAX,dword ptr [ESP + Stack[0x8]]
    //         0055076e     MOV        EDX,dword ptr [ESP + local_8]
    //         00550772     MOV        ECX,dword ptr [ESP + local_4]
    //         00550776     ADD        ESP,0x8
    //         00550779     MOV        dword ptr [EAX],EDX
    //         0055077b     MOV        dword ptr [EAX + 0x4],ECX
    //         0055077e     ADD        ESP,0x8
    //         00550781     RET
    //                               LAB_00550782                                                 XREF[1]:     00550759(j)  
    //         00550782     MOV        EDX,dword ptr [ESP + Stack[0xc]]
    //         00550786     LEA        EAX=>Stack[0xc],[ESP + 0x14]
    //         0055078a     PUSH       EDX
    //         0055078b     PUSH       EAX
    //         0055078c     CALL       __atoflt                                         undefined __atoflt()
    //         00550791     MOV        ECX,dword ptr [ESP + Stack[0x8]]
    //         00550795     MOV        EDX,dword ptr [ESP + Stack[0xc]]
    //         00550799     ADD        ESP,0x8
    //         0055079c     MOV        dword ptr [ECX],EDX
    //         0055079e     ADD        ESP,0x8
    //         005507a1     RET
}

// Offset: 0x005507B0
undefined cftoe() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined __cftoe()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               __cftoe                                                      XREF[2]:     FUN_00550aa0:00550abb(c), 
    //                                                                                                         FUN_00550af6:00550b5c(c)  
    //         005507b0     MOV        AL,[DAT_00888060]
    //         005507b5     PUSH       EBX
    //         005507b6     PUSH       ESI
    //         005507b7     PUSH       EDI
    //         005507b8     TEST       AL,AL
    //         005507ba     JZ         LAB_005507e9
    //         005507bc     MOV        ESI,dword ptr [ESP + Stack[0xc]]
    //         005507c0     MOV        EDI,dword ptr [DAT_0088805c]
    //         005507c6     MOV        EBX,dword ptr [ESP + Stack[0x8]]
    //         005507ca     XOR        EAX,EAX
    //         005507cc     MOV        EDX,dword ptr [EDI]
    //         005507ce     TEST       ESI,ESI
    //         005507d0     SETG       AL
    //         005507d3     XOR        ECX,ECX
    //         005507d5     CMP        EDX,0x2d
    //         005507d8     SETZ       CL
    //         005507db     ADD        ECX,EBX
    //         005507dd     PUSH       EAX
    //         005507de     PUSH       ECX
    //         005507df     CALL       FUN_00550b70                                     undefined FUN_00550b70()
    //         005507e4     ADD        ESP,0x8
    //         005507e7     JMP        LAB_0055082b
    //                               LAB_005507e9                                                 XREF[1]:     005507ba(j)  
    //         005507e9     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         005507ed     MOV        EDX,dword ptr [EAX + 0x4]
    //         005507f0     MOV        EAX,dword ptr [EAX]
    //         005507f2     PUSH       EDX
    //         005507f3     PUSH       EAX
    //         005507f4     CALL       __fltout                                         undefined __fltout()
    //         005507f9     MOV        ESI,dword ptr [ESP + Stack[0xc]]
    //         005507fd     MOV        EBX,dword ptr [ESP + Stack[0x8]]
    //         00550801     ADD        ESP,0x8
    //         00550804     MOV        EDI,EAX
    //         00550806     LEA        ECX,[ESI + 0x1]
    //         00550809     XOR        EDX,EDX
    //         0055080b     PUSH       EDI
    //         0055080c     PUSH       ECX
    //         0055080d     MOV        ECX,dword ptr [EDI]
    //         0055080f     TEST       ESI,ESI
    //         00550811     SETG       DL
    //         00550814     XOR        EAX,EAX
    //         00550816     CMP        ECX,0x2d
    //         00550819     MOV        ECX,EBX
    //         0055081b     SETZ       AL
    //         0055081e     ADD        ECX,EDX
    //         00550820     ADD        EAX,ECX
    //         00550822     PUSH       EAX
    //         00550823     CALL       __fptostr                                        undefined __fptostr()
    //         00550828     ADD        ESP,0xc
    //                               LAB_0055082b                                                 XREF[1]:     005507e7(j)  
    //         0055082b     MOV        ECX,dword ptr [EDI]
    //         0055082d     MOV        EAX,EBX
    //         0055082f     CMP        ECX,0x2d
    //         00550832     JNZ        LAB_0055083a
    //         00550834     MOV        byte ptr [EBX],0x2d
    //         00550837     LEA        EAX,[EBX + 0x1]
    //                               LAB_0055083a                                                 XREF[1]:     00550832(j)  
    //         0055083a     TEST       ESI,ESI
    //         0055083c     JLE        LAB_0055084c
    //         0055083e     MOV        DL,byte ptr [EAX + 0x1]
    //         00550841     MOV        byte ptr [EAX],DL
    //         00550843     MOV        CL,byte ptr [___decimal_point]                   = 2Eh
    //         00550849     INC        EAX
    //         0055084a     MOV        byte ptr [EAX],CL
    //                               LAB_0055084c                                                 XREF[1]:     0055083c(j)  
    //         0055084c     MOV        CL,byte ptr [DAT_00888060]
    //         00550852     XOR        EDX,EDX
    //         00550854     TEST       CL,CL
    //         00550856     MOV        ECX,dword ptr [s_e+000]                          = "e+000"
    //         0055085c     SETZ       DL
    //         0055085f     ADD        EDX,EAX
    //         00550861     ADD        ESI,EDX
    //         00550863     MOV        EAX,ESI
    //         00550865     MOV        dword ptr [EAX],ECX
    //         00550867     MOV        DX,word ptr [s_0_00577b58+4]                     = "0"
    //         0055086e     MOV        word ptr [EAX + 0x4],DX
    //         00550872     MOV        EAX,dword ptr [ESP + Stack[0x10]]
    //         00550876     TEST       EAX,EAX
    //         00550878     JZ         LAB_0055087d
    //         0055087a     MOV        byte ptr [ESI],0x45
    //                               LAB_0055087d                                                 XREF[1]:     00550878(j)  
    //         0055087d     MOV        EAX,dword ptr [EDI + 0xc]
    //         00550880     INC        ESI
    //         00550881     CMP        byte ptr [EAX],0x30
    //         00550884     JZ         LAB_005508e6
    //         00550886     MOV        ECX,dword ptr [EDI + 0x4]
    //         00550889     DEC        ECX
    //         0055088a     JNS        LAB_00550891
    //         0055088c     NEG        ECX
    //         0055088e     MOV        byte ptr [ESI],0x2d
    //                               LAB_00550891                                                 XREF[1]:     0055088a(j)  
    //         00550891     INC        ESI
    //         00550892     CMP        ECX,0x64
    //         00550895     JL         LAB_005508ba
    //         00550897     MOV        EAX,0x51eb851f
    //         0055089c     IMUL       ECX
    //         0055089e     SAR        EDX,0x5
    //         005508a1     MOV        EAX,EDX
    //         005508a3     SHR        EAX,0x1f
    //         005508a6     ADD        EDX,EAX
    //         005508a8     MOV        AL,byte ptr [ESI]
    //         005508aa     ADD        AL,DL
    //         005508ac     MOV        byte ptr [ESI],AL
    //         005508ae     MOV        EAX,ECX
    //         005508b0     CDQ
    //         005508b1     MOV        ECX,0x64
    //         005508b6     IDIV       ECX
    //         005508b8     MOV        ECX,EDX
    //                               LAB_005508ba                                                 XREF[1]:     00550895(j)  
    //         005508ba     INC        ESI
    //         005508bb     CMP        ECX,0xa
    //         005508be     JL         LAB_005508e3
    //         005508c0     MOV        EAX,0x66666667
    //         005508c5     IMUL       ECX
    //         005508c7     SAR        EDX,0x2
    //         005508ca     MOV        EAX,EDX
    //         005508cc     SHR        EAX,0x1f
    //         005508cf     ADD        EDX,EAX
    //         005508d1     MOV        AL,byte ptr [ESI]
    //         005508d3     ADD        AL,DL
    //         005508d5     MOV        byte ptr [ESI],AL
    //         005508d7     MOV        EAX,ECX
    //         005508d9     CDQ
    //         005508da     MOV        ECX,0xa
    //         005508df     IDIV       ECX
    //         005508e1     MOV        ECX,EDX
    //                               LAB_005508e3                                                 XREF[1]:     005508be(j)  
    //         005508e3     ADD        byte ptr [ESI + 0x1],CL
    //                               LAB_005508e6                                                 XREF[1]:     00550884(j)  
    //         005508e6     POP        EDI
    //         005508e7     MOV        EAX,EBX
    //         005508e9     POP        ESI
    //         005508ea     POP        EBX
    //         005508eb     RET
}

// Offset: 0x005508F0
undefined cftof() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined __cftof()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               __cftof                                                      XREF[2]:     FUN_00550ad0:00550ae6(c), 
    //                                                                                                         FUN_00550af6:00550b22(c)  
    //         005508f0     MOV        AL,[DAT_00888060]
    //         005508f5     PUSH       EBX
    //         005508f6     PUSH       EBP
    //         005508f7     PUSH       ESI
    //         005508f8     TEST       AL,AL
    //         005508fa     PUSH       EDI
    //         005508fb     JZ         LAB_0055092c
    //         005508fd     MOV        ESI,dword ptr [DAT_0088805c]
    //         00550903     MOV        EBP,dword ptr [ESP + Stack[0x8]]
    //         00550907     MOV        ECX,dword ptr [DAT_00888064]
    //         0055090d     XOR        EAX,EAX
    //         0055090f     MOV        EBX,dword ptr [ESI]
    //         00550911     CMP        EBX,0x2d
    //         00550914     MOV        EBX,dword ptr [ESP + Stack[0xc]]
    //         00550918     SETZ       AL
    //         0055091b     ADD        EAX,EBP
    //         0055091d     CMP        ECX,EBX
    //         0055091f     JNZ        LAB_00550965
    //         00550921     ADD        EAX,ECX
    //         00550923     MOV        byte ptr [EAX],0x30
    //         00550926     MOV        byte ptr [EAX + 0x1],0x0
    //         0055092a     JMP        LAB_00550965
    //                               LAB_0055092c                                                 XREF[1]:     005508fb(j)  
    //         0055092c     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         00550930     MOV        ECX,dword ptr [EAX + 0x4]
    //         00550933     MOV        EDX,dword ptr [EAX]
    //         00550935     PUSH       ECX
    //         00550936     PUSH       EDX
    //         00550937     CALL       __fltout                                         undefined __fltout()
    //         0055093c     MOV        EBX,dword ptr [ESP + Stack[0xc]]
    //         00550940     MOV        ESI,EAX
    //         00550942     ADD        ESP,0x8
    //         00550945     XOR        ECX,ECX
    //         00550947     MOV        EAX,dword ptr [ESI + 0x4]
    //         0055094a     MOV        EBP,dword ptr [ESI]
    //         0055094c     ADD        EAX,EBX
    //         0055094e     CMP        EBP,0x2d
    //         00550951     MOV        EBP,dword ptr [ESP + Stack[0x8]]
    //         00550955     PUSH       ESI
    //         00550956     SETZ       CL
    //         00550959     ADD        ECX,EBP
    //         0055095b     PUSH       EAX
    //         0055095c     PUSH       ECX
    //         0055095d     CALL       __fptostr                                        undefined __fptostr()
    //         00550962     ADD        ESP,0xc
    //                               LAB_00550965                                                 XREF[2]:     0055091f(j), 0055092a(j)  
    //         00550965     MOV        EAX,dword ptr [ESI]
    //         00550967     MOV        EDI,EBP
    //         00550969     CMP        EAX,0x2d
    //         0055096c     JNZ        LAB_00550975
    //         0055096e     MOV        byte ptr [EBP],0x2d
    //         00550972     LEA        EDI,[EBP + 0x1]
    //                               LAB_00550975                                                 XREF[1]:     0055096c(j)  
    //         00550975     MOV        EAX,dword ptr [ESI + 0x4]
    //         00550978     TEST       EAX,EAX
    //         0055097a     JG         LAB_0055098d
    //         0055097c     PUSH       0x1
    //         0055097e     PUSH       EDI
    //         0055097f     CALL       FUN_00550b70                                     undefined FUN_00550b70()
    //         00550984     ADD        ESP,0x8
    //         00550987     MOV        byte ptr [EDI],0x30
    //         0055098a     INC        EDI
    //         0055098b     JMP        LAB_0055098f
    //                               LAB_0055098d                                                 XREF[1]:     0055097a(j)  
    //         0055098d     ADD        EDI,EAX
    //                               LAB_0055098f                                                 XREF[1]:     0055098b(j)  
    //         0055098f     TEST       EBX,EBX
    //         00550991     JLE        LAB_005509e2
    //         00550993     PUSH       0x1
    //         00550995     PUSH       EDI
    //         00550996     CALL       FUN_00550b70                                     undefined FUN_00550b70()
    //         0055099b     MOV        DL,byte ptr [___decimal_point]                   = 2Eh
    //         005509a1     ADD        ESP,0x8
    //         005509a4     MOV        byte ptr [EDI],DL
    //         005509a6     MOV        ESI,dword ptr [ESI + 0x4]
    //         005509a9     INC        EDI
    //         005509aa     TEST       ESI,ESI
    //         005509ac     JGE        LAB_005509e2
    //         005509ae     MOV        AL,[DAT_00888060]
    //         005509b3     TEST       AL,AL
    //         005509b5     JZ         LAB_005509bb
    //         005509b7     NEG        ESI
    //         005509b9     JMP        LAB_005509c1
    //                               LAB_005509bb                                                 XREF[1]:     005509b5(j)  
    //         005509bb     NEG        ESI
    //         005509bd     CMP        EBX,ESI
    //         005509bf     JL         LAB_005509c3
    //                               LAB_005509c1                                                 XREF[1]:     005509b9(j)  
    //         005509c1     MOV        EBX,ESI
    //                               LAB_005509c3                                                 XREF[1]:     005509bf(j)  
    //         005509c3     PUSH       EBX
    //         005509c4     PUSH       EDI
    //         005509c5     CALL       FUN_00550b70                                     undefined FUN_00550b70()
    //         005509ca     MOV        ECX,EBX
    //         005509cc     MOV        EAX,0x30303030
    //         005509d1     MOV        EDX,ECX
    //         005509d3     ADD        ESP,0x8
    //         005509d6     SHR        ECX,0x2
    //         005509d9     STOSD.REP  ES:EDI
    //         005509db     MOV        ECX,EDX
    //         005509dd     AND        ECX,0x3
    //         005509e0     STOSB.REP  ES:EDI
    //                               LAB_005509e2                                                 XREF[2]:     00550991(j), 005509ac(j)  
    //         005509e2     POP        EDI
    //         005509e3     MOV        EAX,EBP
    //         005509e5     POP        ESI
    //         005509e6     POP        EBP
    //         005509e7     POP        EBX
    //         005509e8     RET
}

// Offset: 0x005509F0
undefined cftog() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined __cftog()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               __cftog                                                      XREF[1]:     FUN_00550af6:00550b3f(c)  
    //         005509f0     PUSH       EBX
    //         005509f1     PUSH       EBP
    //         005509f2     PUSH       ESI
    //         005509f3     PUSH       EDI
    //         005509f4     MOV        EDI,dword ptr [ESP + Stack[0x4]]
    //         005509f8     MOV        EAX,dword ptr [EDI + 0x4]
    //         005509fb     MOV        ECX,dword ptr [EDI]
    //         005509fd     PUSH       EAX
    //         005509fe     PUSH       ECX
    //         005509ff     CALL       __fltout                                         undefined __fltout()
    //         00550a04     MOV        [DAT_0088805c],EAX
    //         00550a09     MOV        EDX,dword ptr [EAX + 0x4]
    //         00550a0c     ADD        ESP,0x8
    //         00550a0f     MOV        EBP,dword ptr [ESP + Stack[0x8]]
    //         00550a13     DEC        EDX
    //         00550a14     XOR        ECX,ECX
    //         00550a16     MOV        dword ptr [DAT_00888064],EDX
    //         00550a1c     MOV        EBX,dword ptr [EAX]
    //         00550a1e     CMP        EBX,0x2d
    //         00550a21     MOV        EBX,dword ptr [ESP + Stack[0xc]]
    //         00550a25     SETZ       CL
    //         00550a28     ADD        ECX,EBP
    //         00550a2a     PUSH       EAX
    //         00550a2b     MOV        ESI,ECX
    //         00550a2d     PUSH       EBX
    //         00550a2e     PUSH       ESI
    //         00550a2f     CALL       __fptostr                                        undefined __fptostr()
    //         00550a34     MOV        EAX,[DAT_0088805c]
    //         00550a39     ADD        ESP,0xc
    //         00550a3c     XOR        ECX,ECX
    //         00550a3e     MOV        EDX,dword ptr [EAX + 0x4]
    //         00550a41     DEC        EDX
    //         00550a42     CMP        dword ptr [DAT_00888064],EDX
    //         00550a48     SETL       CL
    //         00550a4b     MOV        byte ptr [DAT_00888068],CL                       = align(4)
    //         00550a51     MOV        EAX,dword ptr [EAX + 0x4]
    //         00550a54     DEC        EAX
    //         00550a55     CMP        EAX,-0x4
    //         00550a58     MOV        [DAT_00888064],EAX
    //         00550a5d     JL         LAB_00550a89
    //         00550a5f     CMP        EAX,EBX
    //         00550a61     JGE        LAB_00550a89
    //         00550a63     TEST       CL,CL
    //         00550a65     JZ         LAB_00550a79
    //         00550a67     MOV        AL,byte ptr [ESI]
    //         00550a69     INC        ESI
    //         00550a6a     TEST       AL,AL
    //         00550a6c     JZ         LAB_00550a75
    //                               LAB_00550a6e                                                 XREF[1]:     00550a73(j)  
    //         00550a6e     MOV        CL,byte ptr [ESI]
    //         00550a70     INC        ESI
    //         00550a71     TEST       CL,CL
    //         00550a73     JNZ        LAB_00550a6e
    //                               LAB_00550a75                                                 XREF[1]:     00550a6c(j)  
    //         00550a75     MOV        byte ptr [ESI + -0x2],0x0
    //                               LAB_00550a79                                                 XREF[1]:     00550a65(j)  
    //         00550a79     PUSH       EBX
    //         00550a7a     PUSH       EBP
    //         00550a7b     PUSH       EDI
    //         00550a7c     CALL       FUN_00550ad0                                     undefined FUN_00550ad0()
    //         00550a81     ADD        ESP,0xc
    //         00550a84     POP        EDI
    //         00550a85     POP        ESI
    //         00550a86     POP        EBP
    //         00550a87     POP        EBX
    //         00550a88     RET
    //                               LAB_00550a89                                                 XREF[2]:     00550a5d(j), 00550a61(j)  
    //         00550a89     MOV        EDX,dword ptr [ESP + Stack[0x10]]
    //         00550a8d     PUSH       EDX
    //         00550a8e     PUSH       EBX
    //         00550a8f     PUSH       EBP
    //         00550a90     PUSH       EDI
    //         00550a91     CALL       FUN_00550aa0                                     undefined FUN_00550aa0()
    //         00550a96     ADD        ESP,0x10
    //         00550a99     POP        EDI
    //         00550a9a     POP        ESI
    //         00550a9b     POP        EBP
    //         00550a9c     POP        EBX
    //         00550a9d     RET
}

// Offset: 0x00550AA0
undefined FUN_00550aa0() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00550aa0()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00550aa0                                                 XREF[1]:     __cftog:00550a91(c)  
    //         00550aa0     MOV        EAX,dword ptr [ESP + Stack[0x10]]
    //         00550aa4     MOV        ECX,dword ptr [ESP + Stack[0xc]]
    //         00550aa8     MOV        EDX,dword ptr [ESP + Stack[0x8]]
    //         00550aac     PUSH       EAX
    //         00550aad     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         00550ab1     PUSH       ECX
    //         00550ab2     PUSH       EDX
    //         00550ab3     PUSH       EAX
    //         00550ab4     MOV        byte ptr [DAT_00888060],0x1
    //         00550abb     CALL       __cftoe                                          undefined __cftoe()
    //         00550ac0     ADD        ESP,0x10
    //         00550ac3     MOV        byte ptr [DAT_00888060],0x0
    //         00550aca     RET
}

// Offset: 0x00550AD0
undefined FUN_00550ad0() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00550ad0()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00550ad0                                                 XREF[1]:     __cftog:00550a7c(c)  
    //         00550ad0     MOV        EAX,dword ptr [ESP + Stack[0xc]]
    //         00550ad4     MOV        ECX,dword ptr [ESP + Stack[0x8]]
    //         00550ad8     MOV        EDX,dword ptr [ESP + Stack[0x4]]
    //         00550adc     PUSH       EAX
    //         00550add     PUSH       ECX
    //         00550ade     PUSH       EDX
    //         00550adf     MOV        byte ptr [DAT_00888060],0x1
    //         00550ae6     CALL       __cftof                                          undefined __cftof()
    //         00550aeb     ADD        ESP,0xc
    //         00550aee     MOV        byte ptr [DAT_00888060],0x0
    //         00550af5     RET
}

// Offset: 0x00550AF6
undefined FUN_00550af6() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00550af6()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00550af6
    //         00550af6     NOP
    //         00550af7     NOP
    //         00550af8     NOP
    //         00550af9     NOP
    //         00550afa     NOP
    //         00550afb     NOP
    //         00550afc     NOP
    //         00550afd     NOP
    //         00550afe     NOP
    //         00550aff     NOP
    //                               __cfltcvt                                                    XREF[1]:     __cfltcvt_init:0054b6a0(*)  
    //         00550b00     MOV        EAX,dword ptr [ESP + Stack[0xc]]
    //         00550b04     CMP        EAX,0x65
    //         00550b07     JZ         LAB_00550b48
    //         00550b09     CMP        EAX,0x45
    //         00550b0c     JZ         LAB_00550b48
    //         00550b0e     CMP        EAX,0x66
    //         00550b11     JNZ        LAB_00550b2b
    //         00550b13     MOV        EAX,dword ptr [ESP + Stack[0x10]]
    //         00550b17     MOV        ECX,dword ptr [ESP + Stack[0x8]]
    //         00550b1b     MOV        EDX,dword ptr [ESP + Stack[0x4]]
    //         00550b1f     PUSH       EAX
    //         00550b20     PUSH       ECX
    //         00550b21     PUSH       EDX
    //         00550b22     CALL       __cftof                                          undefined __cftof()
    //         00550b27     ADD        ESP,0xc
    //         00550b2a     RET
    //                               LAB_00550b2b                                                 XREF[1]:     00550b11(j)  
    //         00550b2b     MOV        EAX,dword ptr [ESP + Stack[0x14]]
    //         00550b2f     MOV        ECX,dword ptr [ESP + Stack[0x10]]
    //         00550b33     MOV        EDX,dword ptr [ESP + Stack[0x8]]
    //         00550b37     PUSH       EAX
    //         00550b38     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         00550b3c     PUSH       ECX
    //         00550b3d     PUSH       EDX
    //         00550b3e     PUSH       EAX
    //         00550b3f     CALL       __cftog                                          undefined __cftog()
    //         00550b44     ADD        ESP,0x10
    //         00550b47     RET
    //                               LAB_00550b48                                                 XREF[2]:     00550b07(j), 00550b0c(j)  
    //         00550b48     MOV        ECX,dword ptr [ESP + Stack[0x14]]
    //         00550b4c     MOV        EDX,dword ptr [ESP + Stack[0x10]]
    //         00550b50     MOV        EAX,dword ptr [ESP + Stack[0x8]]
    //         00550b54     PUSH       ECX
    //         00550b55     MOV        ECX,dword ptr [ESP + Stack[0x4]]
    //         00550b59     PUSH       EDX
    //         00550b5a     PUSH       EAX
    //         00550b5b     PUSH       ECX
    //         00550b5c     CALL       __cftoe                                          undefined __cftoe()
    //         00550b61     ADD        ESP,0x10
    //         00550b64     RET
}

// Offset: 0x00550B70
undefined FUN_00550b70() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00550b70()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00550b70                                                 XREF[4]:     __cftoe:005507df(c), 
    //                                                                                                         __cftof:0055097f(c), 
    //                                                                                                         __cftof:00550996(c), 
    //                                                                                                         __cftof:005509c5(c)  
    //         00550b70     PUSH       ESI
    //         00550b71     MOV        ESI,dword ptr [ESP + Stack[0x8]]
    //         00550b75     TEST       ESI,ESI
    //         00550b77     JZ         LAB_00550b97
    //         00550b79     MOV        EDX,dword ptr [ESP + Stack[0x4]]
    //         00550b7d     PUSH       EDI
    //         00550b7e     MOV        EDI,EDX
    //         00550b80     OR         ECX,0xffffffff
    //         00550b83     XOR        EAX,EAX
    //         00550b85     ADD        ESI,EDX
    //         00550b87     SCASB.RE   ES:EDI
    //         00550b89     NOT        ECX
    //         00550b8b     PUSH       ECX
    //         00550b8c     PUSH       EDX
    //         00550b8d     PUSH       ESI
    //         00550b8e     CALL       memmove                                          undefined memmove()
    //         00550b93     ADD        ESP,0xc
    //         00550b96     POP        EDI
    //                               LAB_00550b97                                                 XREF[1]:     00550b77(j)  
    //         00550b97     POP        ESI
    //         00550b98     RET
}

// Offset: 0x00550BA0
_func_int_uint* set_new_handler(_func_int_uint* param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * int (__cdecl*__cdecl _set_new_handler(int (__cdecl*)(unsigned int)))(unsigned int)                    *
    //                              *********************************************************************************************************
    //                              _func_int_uint * __cdecl _set_new_handler(_func_int_uint * param_1)
    //              _func_int_uint    EAX:4          <RETURN>
    //              _func_int_uint    Stack[0x4]:4   param_1                   XREF[1]:     00550ba0(R)  
    //                               ?_set_new_handler@@YAP6AHI@ZP6AHI@Z@Z
    //                               _set_new_handler
    //         00550ba0     MOV        ECX,dword ptr [ESP + param_1]
    //         00550ba4     MOV        EAX,[_pnhHeap]                                   = 00000000
    //         00550ba9     MOV        dword ptr [_pnhHeap],ECX                         = 00000000
    //         00550baf     RET
}

// Offset: 0x00550BB0
_func_int_uint* query_new_handler() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * int (__cdecl*__cdecl _query_new_handler(void))(unsigned int)                                          *
    //                              *********************************************************************************************************
    //                              _func_int_uint * __cdecl _query_new_handler(void)
    //              _func_int_uint    EAX:4          <RETURN>
    //                               ?_query_new_handler@@YAP6AHI@ZXZ
    //                               _query_new_handler
    //         00550bb0     MOV        EAX,[_pnhHeap]                                   = 00000000
    //         00550bb5     RET
}

// Offset: 0x00550BC0
undefined callnewh() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined __callnewh()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               __callnewh                                                   XREF[3]:     calloc:0054b7b0(c), 
    //                                                                                                         __nh_malloc:0054c5f3(c), 
    //                                                                                                         realloc:00556418(c)  
    //         00550bc0     MOV        EAX,[_pnhHeap]                                   = 00000000
    //         00550bc5     TEST       EAX,EAX
    //         00550bc7     JZ         LAB_00550bdd
    //         00550bc9     MOV        ECX,dword ptr [ESP + Stack[0x4]]
    //         00550bcd     PUSH       ECX
    //         00550bce     CALL       EAX
    //         00550bd0     ADD        ESP,0x4
    //         00550bd3     TEST       EAX,EAX
    //         00550bd5     JZ         LAB_00550bdd
    //         00550bd7     MOV        EAX,0x1
    //         00550bdc     RET
    //                               LAB_00550bdd                                                 XREF[2]:     00550bc7(j), 00550bd5(j)  
    //         00550bdd     XOR        EAX,EAX
    //         00550bdf     RET
}

// Offset: 0x00550BE0
undefined heap_init() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined __heap_init()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               __heap_init                                                  XREF[1]:     entry:0054f8c7(c)  
    //         00550be0     PUSH       0x0
    //         00550be2     PUSH       0x1000
    //         00550be7     PUSH       0x1
    //         00550be9     CALL       dword ptr [->KERNEL32.DLL::HeapCreate]           = 0048b82a
    //         00550bef     TEST       EAX,EAX
    //         00550bf1     MOV        [__crtheap],EAX
    //         00550bf6     JNZ        LAB_00550bf9
    //         00550bf8     RET
    //                               LAB_00550bf9                                                 XREF[1]:     00550bf6(j)  
    //         00550bf9     CALL       ___sbh_new_region                                undefined ___sbh_new_region()
    //         00550bfe     TEST       EAX,EAX
    //         00550c00     JNZ        LAB_00550c11
    //         00550c02     MOV        EAX,[__crtheap]
    //         00550c07     PUSH       EAX
    //         00550c08     CALL       dword ptr [->KERNEL32.DLL::HeapDestroy]          = 0048b81c
    //         00550c0e     XOR        EAX,EAX
    //         00550c10     RET
    //                               LAB_00550c11                                                 XREF[1]:     00550c00(j)  
    //         00550c11     MOV        EAX,0x1
    //         00550c16     RET
}

// Offset: 0x00550C17
undefined FUN_00550c17() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00550c17()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00550c17
    //         00550c17     NOP
    //         00550c18     NOP
    //         00550c19     NOP
    //         00550c1a     NOP
    //         00550c1b     NOP
    //         00550c1c     NOP
    //         00550c1d     NOP
    //         00550c1e     NOP
    //         00550c1f     NOP
    //                               __heap_term
    //         00550c20     PUSH       ESI
    //         00550c21     PUSH       EDI
    //         00550c22     MOV        EDI,dword ptr [->KERNEL32.DLL::VirtualFree]      = 0048ac60
    //         00550c28     MOV        ESI,___small_block_heap                          = 0058fbe8
    //                               LAB_00550c2d                                                 XREF[1]:     00550c46(j)  
    //         00550c2d     MOV        EAX,dword ptr [ESI + 0x10]=>DAT_0058fbf8         = FFFFFFFFh
    //         00550c30     TEST       EAX,EAX
    //         00550c32     JZ         LAB_00550c3e
    //         00550c34     PUSH       0x8000
    //         00550c39     PUSH       0x0=>DAT_fffffff8
    //         00550c3b     PUSH       EAX=>DAT_fffffff4
    //         00550c3c     CALL       EDI=>KERNEL32.DLL::VirtualFree
    //                               LAB_00550c3e                                                 XREF[1]:     00550c32(j)  
    //         00550c3e     MOV        ESI=>->___small_block_heap,dword ptr [ESI]       = 0058fbe8
    //         00550c40     CMP        ESI,___small_block_heap                          = 0058fbe8
    //         00550c46     JNZ        LAB_00550c2d
    //         00550c48     MOV        EAX,[__crtheap]
    //         00550c4d     PUSH       EAX
    //         00550c4e     CALL       dword ptr [->KERNEL32.DLL::HeapDestroy]          = 0048b81c
    //         00550c54     POP        EDI
    //         00550c55     POP        ESI
    //         00550c56     RET
}

// Offset: 0x00550C57
undefined FUN_00550c57() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00550c57()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00550c57
    //         00550c57     NOP
    //         00550c58     NOP
    //         00550c59     NOP
    //         00550c5a     NOP
    //         00550c5b     NOP
    //         00550c5c     NOP
    //         00550c5d     NOP
    //         00550c5e     NOP
    //         00550c5f     NOP
    //                               __get_sbh_threshold
    //         00550c60     MOV        EAX,[___sbh_threshold]                           = 000001E0h
    //         00550c65     RET
}

// Offset: 0x00550C66
undefined FUN_00550c66() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00550c66()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00550c66
    //         00550c66     NOP
    //         00550c67     NOP
    //         00550c68     NOP
    //         00550c69     NOP
    //         00550c6a     NOP
    //         00550c6b     NOP
    //         00550c6c     NOP
    //         00550c6d     NOP
    //         00550c6e     NOP
    //         00550c6f     NOP
    //                               __set_sbh_threshold
    //         00550c70     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         00550c74     ADD        EAX,0xf
    //         00550c77     AND        AL,0xf0
    //         00550c79     CMP        EAX,0x780
    //         00550c7e     JA         LAB_00550c8b
    //         00550c80     MOV        [___sbh_threshold],EAX                           = 000001E0h
    //         00550c85     MOV        EAX,0x1
    //         00550c8a     RET
    //                               LAB_00550c8b                                                 XREF[1]:     00550c7e(j)  
    //         00550c8b     XOR        EAX,EAX
    //         00550c8d     RET
}

// Offset: 0x00550C90
undefined sbh_new_region() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined ___sbh_new_region()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               ___sbh_new_region                                            XREF[2]:     __heap_init:00550bf9(c), 
    //                                                                                                         ___sbh_alloc_block:005511dd(c)  
    //         00550c90     MOV        EAX,[DAT_0058fbf8]                               = FFFFFFFFh
    //         00550c95     PUSH       EBP
    //         00550c96     PUSH       ESI
    //         00550c97     CMP        EAX,-0x1
    //         00550c9a     PUSH       EDI
    //         00550c9b     JNZ        LAB_00550ca4
    //         00550c9d     MOV        EBP,___small_block_heap                          = 0058fbe8
    //         00550ca2     JMP        LAB_00550cc1
    //                               LAB_00550ca4                                                 XREF[1]:     00550c9b(j)  
    //         00550ca4     MOV        EAX,[__crtheap]
    //         00550ca9     PUSH       0x2020
    //         00550cae     PUSH       0x0
    //         00550cb0     PUSH       EAX
    //         00550cb1     CALL       dword ptr [->KERNEL32.DLL::HeapAlloc]            = 0048b6ac
    //         00550cb7     MOV        EBP,EAX
    //         00550cb9     TEST       EBP,EBP
    //         00550cbb     JZ         LAB_00550dec
    //                               LAB_00550cc1                                                 XREF[1]:     00550ca2(j)  
    //         00550cc1     MOV        EDI,dword ptr [->KERNEL32.DLL::VirtualAlloc]     = 0048b838
    //         00550cc7     PUSH       0x4
    //         00550cc9     PUSH       0x2000
    //         00550cce     PUSH       IMAGE_DOS_HEADER_00400000
    //         00550cd3     PUSH       0x0
    //         00550cd5     CALL       EDI=>KERNEL32.DLL::VirtualAlloc
    //         00550cd7     MOV        ESI,EAX
    //         00550cd9     TEST       ESI,ESI
    //         00550cdb     JZ         LAB_00550dd5
    //         00550ce1     PUSH       0x4
    //         00550ce3     PUSH       0x1000
    //         00550ce8     PUSH       0x10000
    //         00550ced     PUSH       ESI
    //         00550cee     CALL       EDI=>KERNEL32.DLL::VirtualAlloc
    //         00550cf0     TEST       EAX,EAX
    //         00550cf2     JZ         LAB_00550dc7
    //         00550cf8     CMP        EBP,___small_block_heap                          = 0058fbe8
    //         00550cfe     JNZ        LAB_00550d28
    //         00550d00     MOV        EAX,[->___small_block_heap]                      = 0058fbe8
    //         00550d05     TEST       EAX,EAX
    //         00550d07     JNZ        LAB_00550d13
    //         00550d09     MOV        dword ptr [___small_block_heap],___small_block   = 0058fbe8
    //                               LAB_00550d13                                                 XREF[1]:     00550d07(j)  
    //         00550d13     MOV        EAX,[->___small_block_heap]                      = 0058fbe8
    //         00550d18     TEST       EAX,EAX
    //         00550d1a     JNZ        LAB_00550d43
    //         00550d1c     MOV        dword ptr [PTR____small_block_heap_0058fbec],_   = 0058fbe8
    //         00550d26     JMP        LAB_00550d43
    //                               LAB_00550d28                                                 XREF[1]:     00550cfe(j)  
    //         00550d28     MOV        dword ptr [EBP]=>___small_block_heap,___small_   = 0058fbe8
    //         00550d2f     MOV        ECX,dword ptr [->___small_block_heap]            = 0058fbe8
    //         00550d35     MOV        dword ptr [EBP + 0x4]=>PTR____small_block_heap   = 0058fbe8
    //         00550d38     MOV        dword ptr [PTR____small_block_heap_0058fbec],EBP = 0058fbe8
    //         00550d3e     MOV        EDX,dword ptr [EBP + 0x4]=>->___small_block_heap = 0058fbe8
    //         00550d41     MOV        dword ptr [EDX]=>___small_block_heap,EBP         = 0058fbe8
    //                               LAB_00550d43                                                 XREF[2]:     00550d1a(j), 00550d26(j)  
    //         00550d43     LEA        EAX,[ESI + IMAGE_DOS_HEADER_00400000]
    //         00550d49     LEA        ECX,[EBP + 0x18]=>DAT_0058fc00                   = 000000F0h
    //         00550d4c     LEA        EDX,[EBP + 0x98]=>null_0058fc80                  = align(8048)
    //         00550d52     MOV        dword ptr [EBP + 0x14]=>DAT_0058fbfc,EAX         = FFFFFFFFh
    //         00550d55     MOV        dword ptr [EBP + 0x10]=>DAT_0058fbf8,ESI         = FFFFFFFFh
    //         00550d58     MOV        dword ptr [EBP + 0x8]=>PTR_DAT_0058fbf0,ECX=>D   = 0058fc00
    //                                                                                  = 000000F0h
    //         00550d5b     MOV        dword ptr [EBP + 0xc]=>PTR_DAT_0058fbf4,EDX=>n   = 0058fc00
    //                                                                                  = align(8048)
    //         00550d5e     XOR        EAX,EAX
    //         00550d60     MOV        EDI,0xf1
    //                               LAB_00550d65                                                 XREF[1]:     00550d80(j)  
    //         00550d65     XOR        EDX,EDX
    //         00550d67     CMP        EAX,0x10
    //         00550d6a     SETGE      DL
    //         00550d6d     DEC        EDX
    //         00550d6e     ADD        ECX,0x8
    //         00550d71     AND        EDX,EDI
    //         00550d73     DEC        EDX
    //         00550d74     INC        EAX
    //         00550d75     MOV        dword ptr [ECX + -0x8]=>DAT_0058fc00,EDX         = 000000F0h
    //         00550d78     MOV        dword ptr [ECX + -0x4]=>DAT_0058fc04,EDI         = 000000F1h
    //         00550d7b     CMP        EAX,0x400
    //         00550d80     JL         LAB_00550d65
    //         00550d82     MOV        ECX,0x4000
    //         00550d87     XOR        EAX,EAX
    //         00550d89     MOV        EDI,ESI
    //         00550d8b     STOSD.REP  ES:EDI
    //         00550d8d     MOV        EAX,dword ptr [EBP + 0x10]=>DAT_0058fbf8         = FFFFFFFFh
    //         00550d90     ADD        EAX,0x10000
    //         00550d95     CMP        ESI,EAX
    //         00550d97     JNC        LAB_00550dc1
    //         00550d99     MOV        ECX,0xf0
    //         00550d9e     MOV        AL,0xff
    //                               LAB_00550da0                                                 XREF[1]:     00550dbf(j)  
    //         00550da0     LEA        EDX,[ESI + 0x8]
    //         00550da3     MOV        dword ptr [ESI + 0x4],ECX
    //         00550da6     MOV        dword ptr [ESI],EDX
    //         00550da8     MOV        byte ptr [ESI + 0xf8],AL
    //         00550dae     MOV        EDX,dword ptr [EBP + 0x10]=>DAT_0058fbf8         = FFFFFFFFh
    //         00550db1     ADD        ESI,0x1000
    //         00550db7     ADD        EDX,0x10000
    //         00550dbd     CMP        ESI,EDX
    //         00550dbf     JC         LAB_00550da0
    //                               LAB_00550dc1                                                 XREF[1]:     00550d97(j)  
    //         00550dc1     MOV        EAX=>___small_block_heap,EBP                     = 0058fbe8
    //         00550dc3     POP        EDI
    //         00550dc4     POP        ESI
    //         00550dc5     POP        EBP
    //         00550dc6     RET
    //                               LAB_00550dc7                                                 XREF[1]:     00550cf2(j)  
    //         00550dc7     PUSH       0x8000
    //         00550dcc     PUSH       0x0
    //         00550dce     PUSH       ESI
    //         00550dcf     CALL       dword ptr [->KERNEL32.DLL::VirtualFree]          = 0048ac60
    //                               LAB_00550dd5                                                 XREF[1]:     00550cdb(j)  
    //         00550dd5     CMP        EBP,___small_block_heap                          = 0058fbe8
    //         00550ddb     JZ         LAB_00550dec
    //         00550ddd     MOV        EAX,[__crtheap]
    //         00550de2     PUSH       EBP=>___small_block_heap                         = 0058fbe8
    //         00550de3     PUSH       0x0
    //         00550de5     PUSH       EAX
    //         00550de6     CALL       dword ptr [->KERNEL32.DLL::HeapFree]             = 0048b6b8
    //                               LAB_00550dec                                                 XREF[2]:     00550cbb(j), 00550ddb(j)  
    //         00550dec     POP        EDI
    //         00550ded     POP        ESI
    //         00550dee     XOR        EAX,EAX
    //         00550df0     POP        EBP
    //         00550df1     RET
}

// Offset: 0x00550E00
undefined sbh_release_region() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined ___sbh_release_region()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               ___sbh_release_region                                        XREF[1]:     ___sbh_decommit_pages:00550f0c(c)  
    //         00550e00     PUSH       ESI
    //         00550e01     MOV        ESI,dword ptr [ESP + Stack[0x4]]
    //         00550e05     PUSH       0x8000
    //         00550e0a     PUSH       0x0
    //         00550e0c     MOV        EAX,dword ptr [ESI + 0x10]
    //         00550e0f     PUSH       EAX
    //         00550e10     CALL       dword ptr [->KERNEL32.DLL::VirtualFree]          = 0048ac60
    //         00550e16     CMP        dword ptr [->___small_block_heap],ESI            = 0058fbe8
    //         00550e1c     JNZ        LAB_00550e27
    //         00550e1e     MOV        ECX,dword ptr [ESI + 0x4]
    //         00550e21     MOV        dword ptr [PTR____small_block_heap_00591c08],ECX = 0058fbe8
    //                               LAB_00550e27                                                 XREF[1]:     00550e1c(j)  
    //         00550e27     CMP        ESI,___small_block_heap                          = 0058fbe8
    //         00550e2d     JZ         LAB_00550e4f
    //         00550e2f     MOV        EDX,dword ptr [ESI + 0x4]
    //         00550e32     MOV        EAX,dword ptr [ESI]
    //         00550e34     PUSH       ESI
    //         00550e35     PUSH       0x0=>DAT_fffffff8
    //         00550e37     MOV        dword ptr [EDX],EAX
    //         00550e39     MOV        ECX,dword ptr [ESI]
    //         00550e3b     MOV        EDX,dword ptr [ESI + 0x4]
    //         00550e3e     MOV        dword ptr [ECX + 0x4],EDX
    //         00550e41     MOV        EAX,[__crtheap]
    //         00550e46     PUSH       EAX=>DAT_fffffff4
    //         00550e47     CALL       dword ptr [->KERNEL32.DLL::HeapFree]             = 0048b6b8
    //         00550e4d     POP        ESI
    //         00550e4e     RET
    //                               LAB_00550e4f                                                 XREF[1]:     00550e2d(j)  
    //         00550e4f     MOV        dword ptr [DAT_0058fbf8],0xffffffff              = FFFFFFFFh
    //         00550e59     POP        ESI
    //         00550e5a     RET
}

// Offset: 0x00550E60
undefined sbh_decommit_pages() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined ___sbh_decommit_pages()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               ___sbh_decommit_pages                                        XREF[1]:     ___sbh_free_block:00550fd9(c)  
    //         00550e60     PUSH       EBX
    //         00550e61     PUSH       EBP
    //         00550e62     PUSH       ESI
    //         00550e63     PUSH       EDI
    //         00550e64     MOV        EDI,dword ptr [->___small_block_heap]            = 0058fbe8
    //                               LAB_00550e6a                                                 XREF[1]:     00550f22(j)  
    //         00550e6a     CMP        dword ptr [EDI + 0x10]=>DAT_0058fbf8,-0x1        = FFFFFFFFh
    //         00550e6e     JZ         LAB_00550f14
    //         00550e74     XOR        EBP,EBP
    //         00550e76     LEA        ESI,[EDI + 0x2010]=>DAT_00591bf8
    //         00550e7c     MOV        EBX,0x3ff000
    //                               LAB_00550e81                                                 XREF[1]:     00550edb(j)  
    //         00550e81     CMP        dword ptr [ESI]=>DAT_00591bf8,0xf0
    //         00550e87     JNZ        LAB_00550ed0
    //         00550e89     MOV        EAX,dword ptr [EDI + 0x10]=>DAT_0058fbf8         = FFFFFFFFh
    //         00550e8c     PUSH       0x4000
    //         00550e91     ADD        EAX,EBX
    //         00550e93     PUSH       offset DAT_fffffff8
    //         00550e98     PUSH       EAX=>DAT_fffffff4
    //         00550e99     CALL       dword ptr [->KERNEL32.DLL::VirtualFree]          = 0048ac60
    //         00550e9f     TEST       EAX,EAX
    //         00550ea1     JZ         LAB_00550ed0
    //         00550ea3     MOV        dword ptr [ESI]=>DAT_00591bf8,0xffffffff
    //         00550ea9     MOV        EDX,dword ptr [DAT_00888074]
    //         00550eaf     DEC        EDX
    //         00550eb0     MOV        dword ptr [DAT_00888074],EDX
    //         00550eb6     MOV        EAX,dword ptr [EDI + 0xc]=>PTR_DAT_0058fbf4      = 0058fc00
    //         00550eb9     TEST       EAX,EAX
    //         00550ebb     JZ         LAB_00550ec1
    //         00550ebd     CMP        EAX,ESI
    //         00550ebf     JBE        LAB_00550ec4
    //                               LAB_00550ec1                                                 XREF[1]:     00550ebb(j)  
    //         00550ec1     MOV        dword ptr [EDI + 0xc]=>PTR_DAT_0058fbf4,ESI=>D   = 0058fc00
    //                               LAB_00550ec4                                                 XREF[1]:     00550ebf(j)  
    //         00550ec4     MOV        EAX,dword ptr [ESP + 0x14]
    //         00550ec8     INC        EBP
    //         00550ec9     DEC        EAX
    //         00550eca     MOV        dword ptr [ESP + 0x14],EAX
    //         00550ece     JZ         LAB_00550edd
    //                               LAB_00550ed0                                                 XREF[2]:     00550e87(j), 00550ea1(j)  
    //         00550ed0     SUB        EBX,0x1000
    //         00550ed6     SUB        ESI,0x8
    //         00550ed9     TEST       EBX,EBX
    //         00550edb     JGE        LAB_00550e81
    //                               LAB_00550edd                                                 XREF[1]:     00550ece(j)  
    //         00550edd     MOV        EDX,EDI
    //         00550edf     MOV        EDI,dword ptr [EDI + 0x4]=>->___small_block_heap = 0058fbe8
    //         00550ee2     TEST       EBP,EBP
    //         00550ee4     JZ         LAB_00550f14
    //         00550ee6     CMP        dword ptr [EDX + 0x18]=>DAT_0058fc00,-0x1        = 000000F0h
    //         00550eea     JNZ        LAB_00550f14
    //         00550eec     MOV        EAX,0x1
    //         00550ef1     LEA        ECX,[EDX + 0x20]=>DAT_0058fc08
    //                               LAB_00550ef4                                                 XREF[1]:     00550f02(j)  
    //         00550ef4     CMP        dword ptr [ECX]=>DAT_0058fc08,-0x1
    //         00550ef7     JNZ        LAB_00550f04
    //         00550ef9     INC        EAX
    //         00550efa     ADD        ECX,0x8
    //         00550efd     CMP        EAX,0x400
    //         00550f02     JL         LAB_00550ef4
    //                               LAB_00550f04                                                 XREF[1]:     00550ef7(j)  
    //         00550f04     CMP        EAX,0x400
    //         00550f09     JNZ        LAB_00550f14
    //         00550f0b     PUSH       EDX=>___small_block_heap                         = 0058fbe8
    //         00550f0c     CALL       ___sbh_release_region                            undefined ___sbh_release_region()
    //         00550f11     ADD        ESP,0x4
    //                               LAB_00550f14                                                 XREF[4]:     00550e6e(j), 00550ee4(j), 
    //                                                                                                         00550eea(j), 00550f09(j)  
    //         00550f14     CMP        EDI,dword ptr [->___small_block_heap]            = 0058fbe8
    //         00550f1a     JZ         LAB_00550f28
    //         00550f1c     MOV        EAX,dword ptr [ESP + 0x14]
    //         00550f20     TEST       EAX,EAX
    //         00550f22     JG         LAB_00550e6a
    //                               LAB_00550f28                                                 XREF[1]:     00550f1a(j)  
    //         00550f28     POP        EDI
    //         00550f29     POP        ESI
    //         00550f2a     POP        EBP
    //         00550f2b     POP        EBX
    //         00550f2c     RET
}

// Offset: 0x00550F30
undefined sbh_find_block() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined ___sbh_find_block()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               ___sbh_find_block                                            XREF[3]:     free:0054b7e5(c), 
    //                                                                                                         realloc:00556311(c), 
    //                                                                                                         __msize:00556451(c)  
    //         00550f30     MOV        ECX,dword ptr [ESP + Stack[0x4]]
    //         00550f34     MOV        EAX,___small_block_heap                          = 0058fbe8
    //                               LAB_00550f39                                                 XREF[1]:     00550f4c(j)  
    //         00550f39     CMP        ECX,dword ptr [EAX + 0x10]=>DAT_0058fbf8         = FFFFFFFFh
    //         00550f3c     JBE        LAB_00550f43
    //         00550f3e     CMP        ECX,dword ptr [EAX + 0x14]=>DAT_0058fbfc         = FFFFFFFFh
    //         00550f41     JC         LAB_00550f4e
    //                               LAB_00550f43                                                 XREF[1]:     00550f3c(j)  
    //         00550f43     MOV        EAX=>->___small_block_heap,dword ptr [EAX]       = 0058fbe8
    //         00550f45     CMP        EAX,___small_block_heap                          = 0058fbe8
    //         00550f4a     JZ         LAB_00550f86
    //         00550f4c     JMP        LAB_00550f39
    //                               LAB_00550f4e                                                 XREF[1]:     00550f41(j)  
    //         00550f4e     TEST       CL,0xf
    //         00550f51     JNZ        LAB_00550f86
    //         00550f53     MOV        EDX,ECX
    //         00550f55     AND        EDX,0xfff
    //         00550f5b     CMP        EDX,0x100
    //         00550f61     JC         LAB_00550f86
    //         00550f63     MOV        EDX,dword ptr [ESP + Stack[0x8]]
    //         00550f67     MOV        dword ptr [EDX],EAX=>___small_block_heap         = 0058fbe8
    //         00550f69     MOV        EDX,dword ptr [ESP + Stack[0xc]]
    //         00550f6d     MOV        EAX,ECX
    //         00550f6f     AND        EAX,0xfffff000
    //         00550f74     SUB        ECX,EAX
    //         00550f76     MOV        dword ptr [EDX],EAX
    //         00550f78     SUB        ECX,0x100
    //         00550f7e     SAR        ECX,0x4
    //         00550f81     LEA        EAX,[ECX + EAX*0x1 + 0x8]
    //         00550f85     RET
    //                               LAB_00550f86                                                 XREF[3]:     00550f4a(j), 00550f51(j), 
    //                                                                                                         00550f61(j)  
    //         00550f86     XOR        EAX,EAX
    //         00550f88     RET
}

// Offset: 0x00550F90
undefined sbh_free_block() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined ___sbh_free_block()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               ___sbh_free_block                                            XREF[3]:     free:0054b7fc(c), 
    //                                                                                                         realloc:00556393(c), 
    //                                                                                                         realloc:005563ee(c)  
    //         00550f90     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         00550f94     MOV        ECX,dword ptr [ESP + Stack[0x8]]
    //         00550f98     PUSH       ESI
    //         00550f99     XOR        EDX,EDX
    //         00550f9b     SUB        ECX,dword ptr [EAX + 0x10]
    //         00550f9e     SAR        ECX,0xc
    //         00550fa1     MOV        ESI,dword ptr [EAX + ECX*0x8 + 0x18]
    //         00550fa5     LEA        EAX,[EAX + ECX*0x8 + 0x18]
    //         00550fa9     MOV        ECX,dword ptr [ESP + Stack[0xc]]
    //         00550fad     MOV        DL,byte ptr [ECX]
    //         00550faf     ADD        ESI,EDX
    //         00550fb1     MOV        dword ptr [EAX],ESI
    //         00550fb3     MOV        byte ptr [ECX],0x0
    //         00550fb6     MOV        ECX,dword ptr [EAX]
    //         00550fb8     MOV        dword ptr [EAX + 0x4],0xf1
    //         00550fbf     CMP        ECX,0xf0
    //         00550fc5     JNZ        LAB_00550fe1
    //         00550fc7     MOV        EAX,[DAT_00888074]
    //         00550fcc     INC        EAX
    //         00550fcd     CMP        EAX,0x20
    //         00550fd0     MOV        [DAT_00888074],EAX
    //         00550fd5     JNZ        LAB_00550fe1
    //         00550fd7     PUSH       0x10
    //         00550fd9     CALL       ___sbh_decommit_pages                            undefined ___sbh_decommit_pages()
    //         00550fde     ADD        ESP,0x4
    //                               LAB_00550fe1                                                 XREF[2]:     00550fc5(j), 00550fd5(j)  
    //         00550fe1     POP        ESI
    //         00550fe2     RET
}

// Offset: 0x00550FF0
undefined sbh_alloc_block() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined ___sbh_alloc_block()
    //              undefined         <UNASSIGNED>   <RETURN>
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[7]:     00550fff(W), 00551045(R), 00551080(R), 0055109d(W), 
    //                                                                                     005510a8(R), 005510c1(R), 0055113e(W)  
    //                               ___sbh_alloc_block                                           XREF[3]:     calloc:0054b76e(c), 
    //                                                                                                         __heap_alloc:0054c62a(c), 
    //                                                                                                         realloc:00556353(c)  
    //         00550ff0     PUSH       ECX
    //         00550ff1     MOV        ECX,dword ptr [->___small_block_heap]            = 0058fbe8
    //         00550ff7     PUSH       EBX
    //         00550ff8     MOV        EBX,dword ptr [ESP + Stack[0x4]]
    //         00550ffc     PUSH       EBP
    //         00550ffd     PUSH       ESI
    //         00550ffe     PUSH       EDI
    //         00550fff     MOV        dword ptr [ESP + local_4],ECX=>___small_block_   = 0058fbe8
    //                               LAB_00551003                                                 XREF[1]:     005510a3(j)  
    //         00551003     MOV        EAX,dword ptr [ECX + 0x10]=>DAT_0058fbf8         = FFFFFFFFh
    //         00551006     CMP        EAX,-0x1
    //         00551009     JZ         LAB_00551094
    //         0055100f     MOV        EDI,dword ptr [ECX + 0x8]=>PTR_DAT_0058fbf0      = 0058fc00
    //         00551012     LEA        EBP,[ECX + 0x2018]=>null_00591c00                = align(8)
    //         00551018     MOV        ESI,EDI
    //         0055101a     SUB        ESI,ECX
    //         0055101c     SUB        ESI,0x18
    //         0055101f     SAR        ESI,0x3
    //         00551022     SHL        ESI,0xc
    //         00551025     ADD        ESI,EAX
    //         00551027     CMP        EDI,EBP
    //         00551029     JNC        LAB_00551059
    //                               LAB_0055102b                                                 XREF[1]:     00551057(j)  
    //         0055102b     MOV        EAX,dword ptr [EDI]=>DAT_0058fc00                = 000000F0h
    //         0055102d     CMP        EAX,EBX
    //         0055102f     JL         LAB_0055104c
    //         00551031     CMP        dword ptr [EDI + 0x4]=>DAT_0058fc04,EBX          = 000000F1h
    //         00551034     JBE        LAB_0055104c
    //         00551036     PUSH       EBX
    //         00551037     PUSH       EAX
    //         00551038     PUSH       ESI
    //         00551039     CALL       ___sbh_alloc_block_from_page                     undefined ___sbh_alloc_block_from_page()
    //         0055103e     ADD        ESP,0xc
    //         00551041     TEST       EAX,EAX
    //         00551043     JNZ        LAB_005510a8
    //         00551045     MOV        ECX,dword ptr [ESP + local_4]
    //         00551049     MOV        dword ptr [EDI + 0x4]=>DAT_0058fc04,EBX          = 000000F1h
    //                               LAB_0055104c                                                 XREF[2]:     0055102f(j), 00551034(j)  
    //         0055104c     ADD        EDI,0x8
    //         0055104f     ADD        ESI,0x1000
    //         00551055     CMP        EDI,EBP
    //         00551057     JC         LAB_0055102b
    //                               LAB_00551059                                                 XREF[1]:     00551029(j)  
    //         00551059     MOV        EBP,dword ptr [ECX + 0x8]=>PTR_DAT_0058fbf0      = 0058fc00
    //         0055105c     MOV        EDI,dword ptr [ECX + 0x10]=>DAT_0058fbf8         = FFFFFFFFh
    //         0055105f     LEA        ESI,[ECX + 0x18]=>DAT_0058fc00                   = 000000F0h
    //         00551062     CMP        ESI,EBP
    //         00551064     JNC        LAB_00551094
    //                               LAB_00551066                                                 XREF[1]:     00551092(j)  
    //         00551066     MOV        EAX,dword ptr [ESI]=>DAT_0058fc00                = 000000F0h
    //         00551068     CMP        EAX,EBX
    //         0055106a     JL         LAB_00551087
    //         0055106c     CMP        dword ptr [ESI + 0x4]=>DAT_0058fc04,EBX          = 000000F1h
    //         0055106f     JBE        LAB_00551087
    //         00551071     PUSH       EBX
    //         00551072     PUSH       EAX
    //         00551073     PUSH       EDI
    //         00551074     CALL       ___sbh_alloc_block_from_page                     undefined ___sbh_alloc_block_from_page()
    //         00551079     ADD        ESP,0xc
    //         0055107c     TEST       EAX,EAX
    //         0055107e     JNZ        LAB_005510c1
    //         00551080     MOV        ECX,dword ptr [ESP + local_4]
    //         00551084     MOV        dword ptr [ESI + 0x4]=>DAT_0058fc04,EBX          = 000000F1h
    //                               LAB_00551087                                                 XREF[2]:     0055106a(j), 0055106f(j)  
    //         00551087     ADD        ESI,0x8
    //         0055108a     ADD        EDI,0x1000
    //         00551090     CMP        ESI,EBP
    //         00551092     JC         LAB_00551066
    //                               LAB_00551094                                                 XREF[2]:     00551009(j), 00551064(j)  
    //         00551094     MOV        ECX=>->___small_block_heap,dword ptr [ECX]       = 0058fbe8
    //         00551096     MOV        EAX,[->___small_block_heap]                      = 0058fbe8
    //         0055109b     CMP        ECX,EAX
    //         0055109d     MOV        dword ptr [ESP + local_4],ECX=>___small_block_   = 0058fbe8
    //         005510a1     JZ         LAB_005510da
    //         005510a3     JMP        LAB_00551003
    //                               LAB_005510a8                                                 XREF[1]:     00551043(j)  
    //         005510a8     MOV        ECX,dword ptr [ESP + local_4]
    //         005510ac     MOV        dword ptr [PTR____small_block_heap_00591c08],ECX = 0058fbe8
    //         005510b2     MOV        EDX,dword ptr [EDI]=>DAT_0058fc00                = 000000F0h
    //         005510b4     SUB        EDX,EBX
    //         005510b6     MOV        dword ptr [EDI]=>DAT_0058fc00,EDX                = 000000F0h
    //         005510b8     MOV        dword ptr [ECX + 0x8]=>PTR_DAT_0058fbf0,EDI=>D   = 0058fc00
    //                                                                                  = 000000F0h
    //         005510bb     POP        EDI
    //         005510bc     POP        ESI
    //         005510bd     POP        EBP
    //         005510be     POP        EBX
    //         005510bf     POP        ECX
    //         005510c0     RET
    //                               LAB_005510c1                                                 XREF[1]:     0055107e(j)  
    //         005510c1     MOV        ECX,dword ptr [ESP + local_4]
    //         005510c5     MOV        dword ptr [PTR____small_block_heap_00591c08],ECX = 0058fbe8
    //         005510cb     MOV        EDX,dword ptr [ESI]=>DAT_0058fc00                = 000000F0h
    //         005510cd     SUB        EDX,EBX
    //         005510cf     MOV        dword ptr [ESI]=>DAT_0058fc00,EDX                = 000000F0h
    //         005510d1     MOV        dword ptr [ECX + 0x8]=>PTR_DAT_0058fbf0,ESI=>D   = 0058fc00
    //                                                                                  = 000000F0h
    //         005510d4     POP        EDI
    //         005510d5     POP        ESI
    //         005510d6     POP        EBP
    //         005510d7     POP        EBX
    //         005510d8     POP        ECX
    //         005510d9     RET
    //                               LAB_005510da                                                 XREF[1]:     005510a1(j)  
    //         005510da     MOV        EBP,___small_block_heap                          = 0058fbe8
    //         005510df     OR         ECX,0xffffffff
    //                               LAB_005510e2                                                 XREF[1]:     005510fd(j)  
    //         005510e2     CMP        dword ptr [EBP + 0x10]=>DAT_0058fbf8,ECX         = FFFFFFFFh
    //         005510e5     JZ         LAB_005510ee
    //         005510e7     MOV        EAX,dword ptr [EBP + 0xc]=>PTR_DAT_0058fbf4      = 0058fc00
    //         005510ea     TEST       EAX,EAX
    //         005510ec     JNZ        LAB_005510ff
    //                               LAB_005510ee                                                 XREF[1]:     005510e5(j)  
    //         005510ee     MOV        EBP=>->___small_block_heap,dword ptr [EBP]       = 0058fbe8
    //         005510f1     CMP        EBP,___small_block_heap                          = 0058fbe8
    //         005510f7     JZ         LAB_005511dd
    //         005510fd     JMP        LAB_005510e2
    //                               LAB_005510ff                                                 XREF[1]:     005510ec(j)  
    //         005510ff     MOV        EAX,dword ptr [EBP + 0xc]=>PTR_DAT_0058fbf4      = 0058fc00
    //         00551102     MOV        ESI,dword ptr [EBP + 0x10]=>DAT_0058fbf8         = FFFFFFFFh
    //         00551105     MOV        EDI,EAX
    //         00551107     MOV        dword ptr [ESP + Stack[0x4]],EAX=>DAT_0058fc00   = 000000F0h
    //         0055110b     SUB        EDI,EBP
    //         0055110d     MOV        EDX,dword ptr [EAX]=>DAT_0058fc00                = 000000F0h
    //         0055110f     SUB        EDI,0x18
    //         00551112     SAR        EDI,0x3
    //         00551115     SHL        EDI,0xc
    //         00551118     ADD        EDI,ESI
    //         0055111a     XOR        ESI,ESI
    //         0055111c     CMP        EDX,ECX
    //         0055111e     JNZ        LAB_00551130
    //                               LAB_00551120                                                 XREF[1]:     0055112e(j)  
    //         00551120     CMP        ESI,0x10
    //         00551123     JGE        LAB_00551130
    //         00551125     MOV        EDX,dword ptr [EAX + 0x8]=>DAT_0058fc08
    //         00551128     ADD        EAX,0x8
    //         0055112b     INC        ESI
    //         0055112c     CMP        EDX,ECX
    //         0055112e     JZ         LAB_00551120
    //                               LAB_00551130                                                 XREF[2]:     0055111e(j), 00551123(j)  
    //         00551130     MOV        EAX,ESI
    //         00551132     PUSH       0x4
    //         00551134     SHL        EAX,0xc
    //         00551137     PUSH       0x1000
    //         0055113c     PUSH       EAX
    //         0055113d     PUSH       EDI
    //         0055113e     MOV        dword ptr [ESP + local_4],EAX
    //         00551142     CALL       dword ptr [->KERNEL32.DLL::VirtualAlloc]         = 0048b838
    //         00551148     CMP        EAX,EDI
    //         0055114a     JNZ        LAB_0055121b
    //         00551150     MOV        EDX,dword ptr [ESP + 0x18]
    //         00551154     MOV        EAX,dword ptr [ESP + 0x10]
    //         00551158     XOR        ECX,ECX
    //         0055115a     TEST       ESI,ESI
    //         0055115c     MOV        ECX,EDX
    //         0055115e     JLE        LAB_00551192
    //         00551160     LEA        EAX,[EDI + 0x4]
    //                               LAB_00551163                                                 XREF[1]:     0055118c(j)  
    //         00551163     LEA        EDX,[EAX + 0x4]
    //         00551166     MOV        dword ptr [EAX],0xf0
    //         0055116c     MOV        dword ptr [EAX + -0x4],EDX
    //         0055116f     MOV        byte ptr [EAX + 0xf4],0xff
    //         00551176     MOV        dword ptr [ECX],0xf0
    //         0055117c     MOV        dword ptr [ECX + 0x4],0xf1
    //         00551183     ADD        EAX,0x1000
    //         00551188     ADD        ECX,0x8
    //         0055118b     DEC        ESI
    //         0055118c     JNZ        LAB_00551163
    //         0055118e     MOV        EDX,dword ptr [ESP + 0x18]
    //                               LAB_00551192                                                 XREF[1]:     0055115e(j)  
    //         00551192     LEA        EAX,[EBP + 0x2018]=>null_00591c00                = align(8)
    //         00551198     MOV        dword ptr [PTR____small_block_heap_00591c08],EBP = 0058fbe8
    //         0055119e     CMP        ECX,EAX
    //         005511a0     JNC        LAB_005511b0
    //                               LAB_005511a2                                                 XREF[1]:     005511ac(j)  
    //         005511a2     CMP        dword ptr [ECX],-0x1
    //         005511a5     JZ         LAB_005511ae
    //         005511a7     ADD        ECX,0x8
    //         005511aa     CMP        ECX,EAX
    //         005511ac     JC         LAB_005511a2
    //                               LAB_005511ae                                                 XREF[1]:     005511a5(j)  
    //         005511ae     CMP        ECX,EAX
    //                               LAB_005511b0                                                 XREF[1]:     005511a0(j)  
    //         005511b0     SBB        EAX,EAX
    //         005511b2     AND        EAX,ECX
    //         005511b4     MOV        dword ptr [EBP + 0xc]=>PTR_DAT_0058fbf4,EAX      = 0058fc00
    //         005511b7     MOV        byte ptr [EDI + 0x8],BL
    //         005511ba     MOV        dword ptr [EBP + 0x8]=>PTR_DAT_0058fbf0,EDX      = 0058fc00
    //         005511bd     MOV        ECX,dword ptr [EDX]
    //         005511bf     SUB        ECX,EBX
    //         005511c1     MOV        dword ptr [EDX],ECX
    //         005511c3     MOV        EAX,dword ptr [EDI + 0x4]
    //         005511c6     SUB        EAX,EBX
    //         005511c8     LEA        ECX,[EDI + EBX*0x1 + 0x8]
    //         005511cc     MOV        dword ptr [EDI + 0x4],EAX
    //         005511cf     MOV        dword ptr [EDI],ECX
    //         005511d1     LEA        EAX,[EDI + 0x100]
    //         005511d7     POP        EDI
    //         005511d8     POP        ESI
    //         005511d9     POP        EBP
    //         005511da     POP        EBX
    //         005511db     POP        ECX
    //         005511dc     RET
    //                               LAB_005511dd                                                 XREF[1]:     005510f7(j)  
    //         005511dd     CALL       ___sbh_new_region                                undefined ___sbh_new_region()
    //         005511e2     TEST       EAX,EAX
    //         005511e4     JZ         LAB_0055121b
    //         005511e6     MOV        ECX,dword ptr [EAX + 0x10]
    //         005511e9     MOV        byte ptr [ECX + 0x8],BL
    //         005511ec     LEA        EDX,[ECX + EBX*0x1 + 0x8]
    //         005511f0     MOV        [PTR____small_block_heap_00591c08],EAX           = 0058fbe8
    //         005511f5     MOV        dword ptr [ECX],EDX
    //         005511f7     MOV        EDX,0xf0
    //         005511fc     SUB        EDX,EBX
    //         005511fe     AND        EBX,0xff
    //         00551204     MOV        dword ptr [ECX + 0x4],EDX
    //         00551207     MOV        EDX,dword ptr [EAX + 0x18]
    //         0055120a     SUB        EDX,EBX
    //         0055120c     MOV        dword ptr [EAX + 0x18],EDX
    //         0055120f     LEA        EAX,[ECX + 0x100]
    //         00551215     POP        EDI
    //         00551216     POP        ESI
    //         00551217     POP        EBP
    //         00551218     POP        EBX
    //         00551219     POP        ECX
    //         0055121a     RET
    //                               LAB_0055121b                                                 XREF[2]:     0055114a(j), 005511e4(j)  
    //         0055121b     POP        EDI
    //         0055121c     POP        ESI
    //         0055121d     POP        EBP
    //         0055121e     XOR        EAX,EAX
    //         00551220     POP        EBX
    //         00551221     POP        ECX
    //         00551222     RET
}

