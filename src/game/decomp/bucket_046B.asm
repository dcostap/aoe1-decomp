// Auto-generated scaffold unit: bucket_046B.asm
#include "../include/common.h"

// Offset: 0x0046B050
undefined E12() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined $E12()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               $E12
    //         0046b050     CALL       $E9                                              undefined $E9()
    //         0046b055     JMP        $E11                                             undefined $E11()
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
}

// Offset: 0x0046B080
undefined E11() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined $E11()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               $E11                                                         XREF[1]:     $E12:0046b055(c)  
    //         0046b080     PUSH       $E10
    //         0046b085     CALL       atexit                                           undefined atexit()
    //         0046b08a     ADD        ESP,0x4
    //         0046b08d     RET
}

// Offset: 0x0046B090
undefined E10() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined $E10()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               $E10                                                         XREF[1]:     $E11:0046b080(*)  
    //         0046b090     MOV        ECX,pathSystem
    //         0046b095     JMP        PathingSystem::~PathingSystem                    void ~PathingSystem(PathingSystem * this)
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
}

// Offset: 0x0046B0A0
undefined E17() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined $E17()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               $E17
    //         0046b0a0     CALL       $E14                                             undefined $E14()
    //         0046b0a5     JMP        $E16                                             undefined $E16()
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
}

// Offset: 0x0046B0D0
undefined E16() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined $E16()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               $E16                                                         XREF[1]:     $E17:0046b0a5(c)  
    //         0046b0d0     PUSH       $E15
    //         0046b0d5     CALL       atexit                                           undefined atexit()
    //         0046b0da     ADD        ESP,0x4
    //         0046b0dd     RET
}

// Offset: 0x0046B0E0
undefined E15() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined $E15()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               $E15                                                         XREF[1]:     $E16:0046b0d0(*)  
    //         0046b0e0     MOV        ECX,aiPathSystem
    //         0046b0e5     JMP        PathingSystem::~PathingSystem                    void ~PathingSystem(PathingSystem * this)
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
}

