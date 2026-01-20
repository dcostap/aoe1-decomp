// Auto-generated scaffold unit: bucket_0463.cpp.asm
#include "../include/common.h"

// Offset: 0x00463BA0
undefined E4() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined $E4()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               $E4
    //         00463ba0     CALL       $E1                                              undefined $E1()
    //         00463ba5     JMP        $E3                                              undefined $E3()
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
}

// Offset: 0x00463BC0
undefined E3() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined $E3()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               $E3                                                          XREF[1]:     $E4:00463ba5(c)  
    //         00463bc0     PUSH       $E2
    //         00463bc5     CALL       atexit                                           undefined atexit()
    //         00463bca     ADD        ESP,0x4
    //         00463bcd     RET
}

// Offset: 0x00463BD0
undefined E2() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined $E2()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               $E2                                                          XREF[1]:     $E3:00463bc0(*)  
    //         00463bd0     MOV        ECX,panel_system
    //         00463bd5     JMP        TPanelSystem::~TPanelSystem                      void ~TPanelSystem(TPanelSystem * this)
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
}

