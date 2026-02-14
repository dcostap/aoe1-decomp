// Auto-generated scaffold unit: bucket_04D6.asm
#include "../include/common.h"

// Offset: 0x004D6AC0
undefined E12() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined $E12()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               $E12
    //         004d6ac0     CALL       $E9                                              undefined $E9()
    //         004d6ac5     JMP        $E11                                             undefined $E11()
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
}

// Offset: 0x004D6AF0
undefined E11() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined $E11()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               $E11                                                         XREF[1]:     $E12:004d6ac5(c)  
    //         004d6af0     PUSH       $E10
    //         004d6af5     CALL       atexit                                           undefined atexit()
    //         004d6afa     ADD        ESP,0x4
    //         004d6afd     RET
}

// Offset: 0x004D6B00
undefined E10() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined $E10()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               $E10                                                         XREF[1]:     $E11:004d6af0(*)  
    //         004d6b00     MOV        ECX,iMap
    //         004d6b05     JMP        InfluenceMap::~InfluenceMap                      void ~InfluenceMap(InfluenceMap * this)
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
}

// Offset: 0x004D6B10
undefined E17() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined $E17()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               $E17
    //         004d6b10     CALL       $E14                                             undefined $E14()
    //         004d6b15     JMP        $E16                                             undefined $E16()
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
}

// Offset: 0x004D6B40
undefined E16() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined $E16()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               $E16                                                         XREF[1]:     $E17:004d6b15(c)  
    //         004d6b40     PUSH       $E15
    //         004d6b45     CALL       atexit                                           undefined atexit()
    //         004d6b4a     ADD        ESP,0x4
    //         004d6b4d     RET
}

// Offset: 0x004D6B50
undefined E15() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined $E15()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               $E15                                                         XREF[1]:     $E16:004d6b40(*)  
    //         004d6b50     MOV        ECX,losMap
    //         004d6b55     JMP        InfluenceMap::~InfluenceMap                      void ~InfluenceMap(InfluenceMap * this)
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
}

// Offset: 0x004D6B60
undefined E22() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined $E22()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               $E22
    //         004d6b60     CALL       $E19                                             undefined $E19()
    //         004d6b65     JMP        $E21                                             undefined $E21()
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
}

// Offset: 0x004D6B90
undefined E21() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined $E21()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               $E21                                                         XREF[1]:     $E22:004d6b65(c)  
    //         004d6b90     PUSH       $E20
    //         004d6b95     CALL       atexit                                           undefined atexit()
    //         004d6b9a     ADD        ESP,0x4
    //         004d6b9d     RET
}

// Offset: 0x004D6BA0
undefined E20() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined $E20()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               $E20                                                         XREF[1]:     $E21:004d6b90(*)  
    //         004d6ba0     MOV        ECX,attackMap
    //         004d6ba5     JMP        InfluenceMap::~InfluenceMap                      void ~InfluenceMap(InfluenceMap * this)
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
}

