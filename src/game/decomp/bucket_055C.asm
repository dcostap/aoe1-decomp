// Auto-generated scaffold unit: bucket_055C.asm
#include "../include/common.h"

// Offset: 0x0055C020
int before(type_info* this_, type_info* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall type_info::before(class type_info const &)const                                *
    //                              *********************************************************************************************************
    //                              int __thiscall before(type_info * this, type_info * param_1)
    //              int               EAX:4          <RETURN>
    //              type_info *       ECX:4 (auto)   this
    //              type_info *       Stack[0x4]:4   param_1                   XREF[1]:     0055c020(R)  
    //                               ?before@type_info@@QBEHABV1@@Z
    //                               type_info::before
    //         0055c020     MOV        EAX,dword ptr [ESP + param_1]
    //         0055c024     PUSH       EBX
    //         0055c025     PUSH       ESI
    //         0055c026     LEA        ESI,[this + 0x9]
    //         0055c029     ADD        EAX,0x9
    //                               LAB_0055c02c                                                 XREF[1]:     0055c04e(j)  
    //         0055c02c     MOV        DL,byte ptr [EAX]
    //         0055c02e     MOV        BL,byte ptr [ESI]
    //         0055c030     MOV        this,DL
    //         0055c032     CMP        DL,BL
    //         0055c034     JNZ        LAB_0055c060
    //         0055c036     TEST       this,this
    //         0055c038     JZ         LAB_0055c050
    //         0055c03a     MOV        DL,byte ptr [EAX + 0x1]
    //         0055c03d     MOV        BL,byte ptr [ESI + 0x1]
    //         0055c040     MOV        this,DL
    //         0055c042     CMP        DL,BL
    //         0055c044     JNZ        LAB_0055c060
    //         0055c046     ADD        EAX,0x2
    //         0055c049     ADD        ESI,0x2
    //         0055c04c     TEST       this,this
    //         0055c04e     JNZ        LAB_0055c02c
    //                               LAB_0055c050                                                 XREF[1]:     0055c038(j)  
    //         0055c050     XOR        EAX,EAX
    //         0055c052     XOR        this,this
    //         0055c054     TEST       EAX,EAX
    //         0055c056     SETG       this
    //         0055c059     MOV        EAX,this
    //         0055c05b     POP        ESI
    //         0055c05c     POP        EBX
    //         0055c05d     RET        0x4
    //                               LAB_0055c060                                                 XREF[2]:     0055c034(j), 0055c044(j)  
    //         0055c060     SBB        EAX,EAX
    //         0055c062     POP        ESI
    //         0055c063     SBB        EAX,-0x1
    //         0055c066     XOR        this,this
    //         0055c068     TEST       EAX,EAX
    //         0055c06a     SETG       this
    //         0055c06d     MOV        EAX,this
    //         0055c06f     POP        EBX
    //         0055c070     RET        0x4
}

// Offset: 0x0055C080
char* raw_name(type_info* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: char const * __thiscall type_info::raw_name(void)const                                        *
    //                              *********************************************************************************************************
    //                              char * __thiscall raw_name(type_info * this)
    //              char *            EAX:4          <RETURN>
    //              type_info *       ECX:4 (auto)   this
    //                               ?raw_name@type_info@@QBEPBDXZ
    //                               type_info::raw_name
    //         0055c080     LEA        EAX,[this + 0x8]
    //         0055c083     RET
}

// Offset: 0x0055C090
undefined type_info(type_info* this_, type_info* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * private: __thiscall type_info::type_info(class type_info const &)                                     *
    //                              *********************************************************************************************************
    //                              undefined __thiscall type_info(type_info * this, type_info * param_1)
    //              undefined         <UNASSIGNED>   <RETURN>
    //              type_info *       ECX:4 (auto)   this
    //              type_info *       Stack[0x4]:4   param_1
    //                               ??0type_info@@AAE@ABV0@@Z
    //                               type_info::type_info
    //         0055c090     MOV        EAX,this
    //         0055c092     MOV        dword ptr [EAX],type_info::`vftable'             = 0055bf40
    //         0055c098     RET        0x4
}

// Offset: 0x0055C0A0
type_info* operator(type_info* this_, type_info* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * private: class type_info & __thiscall type_info::operator=(class type_info const &)                   *
    //                              *********************************************************************************************************
    //                              type_info * __thiscall operator=(type_info * this, type_info * param
    //              type_info *       EAX:4          <RETURN>
    //              type_info *       ECX:4 (auto)   this
    //              type_info *       Stack[0x4]:4   param_1
    //                               ??4type_info@@AAEAAV0@ABV0@@Z
    //                               type_info::operator=
    //         0055c0a0     MOV        EAX,this
    //         0055c0a2     RET        0x4
}

// Offset: 0x0055C0A5
undefined FUN_0055c0a5() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0055c0a5()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0055c0a5
    //         0055c0a5     NOP
    //         0055c0a6     NOP
    //         0055c0a7     NOP
    //         0055c0a8     NOP
    //         0055c0a9     NOP
    //         0055c0aa     NOP
    //         0055c0ab     NOP
    //         0055c0ac     NOP
    //         0055c0ad     NOP
    //         0055c0ae     NOP
    //         0055c0af     NOP
    //                              Symbol Ref: No symbol: $L35541
    //         0055c0b0     MOV        ECX,dword ptr [EBP + DAT_fffffff0]
    //         0055c0b3     JMP        RGE_Action::~RGE_Action                          void ~RGE_Action(RGE_Action * this)
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
}

// Offset: 0x0055C0B8
undefined FUN_0055c0b8() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0055c0b8()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                              Symbol Ref: No symbol: $L35546
    //                               FUN_0055c0b8                                                 XREF[1]:     RGE_Action_Attack:00401002(*)  
    //         0055c0b8     MOV        EAX,DAT_00578288                                 = 20h     
    //         0055c0bd     JMP        ___CxxFrameHandler                               undefined ___CxxFrameHandler()
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
}

// Offset: 0x0055C0D8
undefined FUN_0055c0d8() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0055c0d8()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                              Symbol Ref: No symbol: $L35565
    //                               FUN_0055c0d8                                                 XREF[1]:     RGE_Action_Attack:00401172(*)  
    //         0055c0d8     MOV        EAX,DAT_005782b0                                 = 20h     
    //         0055c0dd     JMP        ___CxxFrameHandler                               undefined ___CxxFrameHandler()
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
}

// Offset: 0x0055C106
undefined FUN_0055c106() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0055c106()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                              Symbol Ref: No symbol: $L35602
    //                               FUN_0055c106                                                 XREF[1]:     set_state:00401558(*)  
    //         0055c106     MOV        EAX,DAT_005782d8                                 = 20h     
    //         0055c10b     JMP        ___CxxFrameHandler                               undefined ___CxxFrameHandler()
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
}

// Offset: 0x0055C110
undefined FUN_0055c110() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0055c110()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                              Symbol Ref: No symbol: $L34845
    //                               FUN_0055c110
    //         0055c110     MOV        EAX,dword ptr [EBP + DAT_fffffff0]
    //         0055c113     PUSH       EAX
    //         0055c114     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         0055c119     POP        ECX
    //         0055c11a     RET
}

// Offset: 0x0055C11B
undefined FUN_0055c11b() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0055c11b()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                              Symbol Ref: No symbol: $L34851
    //                               FUN_0055c11b                                                 XREF[1]:     update:00402182(*)  
    //         0055c11b     MOV        EAX,DAT_00578308                                 = 20h     
    //         0055c120     JMP        ___CxxFrameHandler                               undefined ___CxxFrameHandler()
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
}

// Offset: 0x0055C138
undefined FUN_0055c138() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0055c138()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                              Symbol Ref: No symbol: $L34529
    //                               FUN_0055c138                                                 XREF[1]:     RGE_Action_Enter:00402412(*)  
    //         0055c138     MOV        EAX,DAT_00578330                                 = 20h     
    //         0055c13d     JMP        ___CxxFrameHandler                               undefined ___CxxFrameHandler()
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
}

// Offset: 0x0055C15B
undefined FUN_0055c15b() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0055c15b()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                              Symbol Ref: No symbol: $L34551
    //                               FUN_0055c15b                                                 XREF[1]:     set_state:00402618(*)  
    //         0055c15b     MOV        EAX,DAT_00578358                                 = 20h     
    //         0055c160     JMP        ___CxxFrameHandler                               undefined ___CxxFrameHandler()
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
}

// Offset: 0x0055C17B
undefined FUN_0055c17b() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0055c17b()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                              Symbol Ref: No symbol: $L33615
    //                               FUN_0055c17b                                                 XREF[1]:     set_state:00402c08(*)  
    //         0055c17b     MOV        EAX,DAT_00578380                                 = 20h     
    //         0055c180     JMP        ___CxxFrameHandler                               undefined ___CxxFrameHandler()
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
}

// Offset: 0x0055C198
undefined FUN_0055c198() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0055c198()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                              Symbol Ref: No symbol: $L35503
    //                               FUN_0055c198                                                 XREF[1]:     RGE_Action_Gather:00402ea2(*)  
    //         0055c198     MOV        EAX,DAT_005783a8                                 = 20h     
    //         0055c19d     JMP        ___CxxFrameHandler                               undefined ___CxxFrameHandler()
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
}

// Offset: 0x0055C1B8
undefined FUN_0055c1b8() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0055c1b8()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                              Symbol Ref: No symbol: $L35525
    //                               FUN_0055c1b8                                                 XREF[1]:     RGE_Action_Gather:00402f42(*)  
    //         0055c1b8     MOV        EAX,DAT_005783d0                                 = 20h     
    //         0055c1bd     JMP        ___CxxFrameHandler                               undefined ___CxxFrameHandler()
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
}

// Offset: 0x0055C1F1
undefined FUN_0055c1f1() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0055c1f1()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                              Symbol Ref: No symbol: $L35560
    //                               FUN_0055c1f1                                                 XREF[1]:     set_state:00403118(*)  
    //         0055c1f1     MOV        EAX,DAT_005783f8                                 = 20h     
    //         0055c1f6     JMP        ___CxxFrameHandler                               undefined ___CxxFrameHandler()
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
}

// Offset: 0x0055C24D
undefined FUN_0055c24d() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0055c24d()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                              Symbol Ref: No symbol: $L34153
    //                               FUN_0055c24d                                                 XREF[1]:     create_action:00403fc8(*)  
    //         0055c24d     MOV        EAX,DAT_00578430                                 = 20h     
    //         0055c252     JMP        ___CxxFrameHandler                               undefined ___CxxFrameHandler()
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
}

// Offset: 0x0055C2AD
undefined FUN_0055c2ad() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0055c2ad()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                              Symbol Ref: No symbol: $L34207
    //                               FUN_0055c2ad                                                 XREF[1]:     create_task_action:00404208(*)  
    //         0055c2ad     MOV        EAX,DAT_00578488                                 = 20h     
    //         0055c2b2     JMP        ___CxxFrameHandler                               undefined ___CxxFrameHandler()
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
}

// Offset: 0x0055C2C8
undefined FUN_0055c2c8() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0055c2c8()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                              Symbol Ref: No symbol: $L34841
    //                               FUN_0055c2c8                                                 XREF[1]:     RGE_Action_Missile:00404bb2(*)  
    //         0055c2c8     MOV        EAX,DAT_005784e0                                 = 20h     
    //         0055c2cd     JMP        ___CxxFrameHandler                               undefined ___CxxFrameHandler()
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
}

// Offset: 0x0055C2E8
undefined FUN_0055c2e8() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0055c2e8()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                              Symbol Ref: No symbol: $L34863
    //                               FUN_0055c2e8                                                 XREF[1]:     RGE_Action_Missile:00404c92(*)  
    //         0055c2e8     MOV        EAX,DAT_00578508                                 = 20h     
    //         0055c2ed     JMP        ___CxxFrameHandler                               undefined ___CxxFrameHandler()
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
}

// Offset: 0x0055C308
undefined FUN_0055c308() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0055c308()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                              Symbol Ref: No symbol: $L34509
    //                               FUN_0055c308                                                 XREF[1]:     RGE_Action_Move_To:00405512(*)  
    //         0055c308     MOV        EAX,DAT_00578530                                 = 20h     
    //         0055c30d     JMP        ___CxxFrameHandler                               undefined ___CxxFrameHandler()
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
}

// Offset: 0x0055C328
undefined FUN_0055c328() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0055c328()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                              Symbol Ref: No symbol: $L34533
    //                               FUN_0055c328                                                 XREF[1]:     RGE_Action_Move_To:00405622(*)  
    //         0055c328     MOV        EAX,DAT_00578558                                 = 20h     
    //         0055c32d     JMP        ___CxxFrameHandler                               undefined ___CxxFrameHandler()
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
}

// Offset: 0x0055C348
undefined FUN_0055c348() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0055c348()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                              Symbol Ref: No symbol: $L34543
    //                               FUN_0055c348                                                 XREF[1]:     ~RGE_Action_Move_To:004056e2(*)  
    //         0055c348     MOV        EAX,DAT_00578580                                 = 20h     
    //         0055c34d     JMP        ___CxxFrameHandler                               undefined ___CxxFrameHandler()
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
}

// Offset: 0x0055C368
undefined FUN_0055c368() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0055c368()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                              Symbol Ref: No symbol: $L35401
    //                               FUN_0055c368                                                 XREF[1]:     RGE_Action_Object:00405c62(*)  
    //         0055c368     MOV        EAX,DAT_005785a8                                 = 20h     
    //         0055c36d     JMP        ___CxxFrameHandler                               undefined ___CxxFrameHandler()
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
}

// Offset: 0x0055C388
undefined FUN_0055c388() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0055c388()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                              Symbol Ref: No symbol: $L35497
    //                               FUN_0055c388                                                 XREF[1]:     RGE_Action_Object:00405f92(*)  
    //         0055c388     MOV        EAX,DAT_005785d0                                 = 20h     
    //         0055c38d     JMP        ___CxxFrameHandler                               undefined ___CxxFrameHandler()
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
}

// Offset: 0x0055C3A8
undefined FUN_0055c3a8() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0055c3a8()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                              Symbol Ref: No symbol: $L35513
    //                               FUN_0055c3a8                                                 XREF[1]:     ~RGE_Action_Object:00406012(*)  
    //         0055c3a8     MOV        EAX,DAT_005785f8                                 = 20h     
    //         0055c3ad     JMP        ___CxxFrameHandler                               undefined ___CxxFrameHandler()
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
}

// Offset: 0x0055C3CB
undefined FUN_0055c3cb() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0055c3cb()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                              Symbol Ref: No symbol: $L35536
    //                               FUN_0055c3cb                                                 XREF[1]:     create_action_list:004061a2(*)  
    //         0055c3cb     MOV        EAX,DAT_00578620                                 = 20h     
    //         0055c3d0     JMP        ___CxxFrameHandler                               undefined ___CxxFrameHandler()
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
}

// Offset: 0x0055C3F6
undefined FUN_0055c3f6() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0055c3f6()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                              Symbol Ref: No symbol: $L35566
    //                               FUN_0055c3f6                                                 XREF[1]:     move_to:00406308(*)  
    //         0055c3f6     MOV        EAX,DAT_00578648                                 = 20h     
    //         0055c3fb     JMP        ___CxxFrameHandler                               undefined ___CxxFrameHandler()
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
}

// Offset: 0x0055C400
undefined FUN_0055c400() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0055c400()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                              Symbol Ref: No symbol: $L35738
    //                               FUN_0055c400
    //         0055c400     MOV        EAX,dword ptr [EBP + 0x4]
    //         0055c403     PUSH       EAX
    //         0055c404     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         0055c409     POP        ECX
    //         0055c40a     RET
}

// Offset: 0x0055C40B
undefined FUN_0055c40b() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0055c40b()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                              Symbol Ref: No symbol: $L35739
    //                               FUN_0055c40b
    //         0055c40b     MOV        EAX,dword ptr [EBP + 0x4]
    //         0055c40e     PUSH       EAX
    //         0055c40f     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         0055c414     POP        ECX
    //         0055c415     RET
}

// Offset: 0x0055C416
undefined FUN_0055c416() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0055c416()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                              Symbol Ref: No symbol: $L35744
    //                               FUN_0055c416                                                 XREF[1]:     set_state:00406e58(*)  
    //         0055c416     MOV        EAX,DAT_00578678                                 = 20h     
    //         0055c41b     JMP        ___CxxFrameHandler                               undefined ___CxxFrameHandler()
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
}

// Offset: 0x0055C420
undefined FUN_0055c420() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0055c420()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                              Symbol Ref: No symbol: $L34795
    //                               FUN_0055c420
    //         0055c420     MOV        EAX,dword ptr [EBP + DAT_fffffff0]
    //         0055c423     PUSH       EAX
    //         0055c424     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         0055c429     POP        ECX
    //         0055c42a     RET
}

// Offset: 0x0055C42B
undefined FUN_0055c42b() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0055c42b()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                              Symbol Ref: No symbol: $L34800
    //                               FUN_0055c42b                                                 XREF[1]:     create_action_list:004076d2(*)  
    //         0055c42b     MOV        EAX,DAT_005786a8                                 = 20h     
    //         0055c430     JMP        ___CxxFrameHandler                               undefined ___CxxFrameHandler()
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
}

// Offset: 0x0055C456
undefined FUN_0055c456() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0055c456()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                              Symbol Ref: No symbol: $L31906
    //                               FUN_0055c456                                                 XREF[1]:     BuildAIModule:004086b2(*)  
    //         0055c456     MOV        EAX,DAT_005786d0                                 = 20h     
    //         0055c45b     JMP        ___CxxFrameHandler                               undefined ___CxxFrameHandler()
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
}

// Offset: 0x0055C460
undefined FUN_0055c460() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0055c460()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                              Symbol Ref: No symbol: $L31928
    //                               FUN_0055c460
    //         0055c460     MOV        ECX,dword ptr [EBP + 0xfffffee8]
    //         0055c466     JMP        AIModule::~AIModule                              void ~AIModule(AIModule * this)
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
}

// Offset: 0x0055C46B
undefined FUN_0055c46b() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0055c46b()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                              Symbol Ref: No symbol: $L31929
    //                               FUN_0055c46b
    //         0055c46b     MOV        ECX,dword ptr [EBP + 0xfffffee8]
    //         0055c471     ADD        ECX,0xf0
    //         0055c477     JMP        BuildItem::~BuildItem                            void ~BuildItem(BuildItem * this)
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
}

// Offset: 0x0055C47C
undefined FUN_0055c47c() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0055c47c()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                              Symbol Ref: No symbol: $L31930
    //                               FUN_0055c47c
    //         0055c47c     MOV        ECX,dword ptr [EBP + 0xfffffee8]
    //         0055c482     ADD        ECX,0x5ac
    //         0055c488     JMP        ManagedArray<int>::~ManagedArray<int>            void ~ManagedArray<int>(ManagedArray<int> * t
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
}

// Offset: 0x0055C48D
undefined FUN_0055c48d() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0055c48d()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                              Symbol Ref: No symbol: $L31931
    //                               FUN_0055c48d
    //         0055c48d     MOV        EAX,dword ptr [EBP + 0xfffffeec]
    //         0055c493     PUSH       EAX
    //         0055c494     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         0055c499     POP        ECX
    //         0055c49a     RET
}

// Offset: 0x0055C49B
undefined FUN_0055c49b() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0055c49b()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                              Symbol Ref: No symbol: $L31943
    //                               FUN_0055c49b                                                 XREF[1]:     BuildAIModule:00408842(*)  
    //         0055c49b     MOV        EAX,DAT_00578700                                 = 20h     
    //         0055c4a0     JMP        ___CxxFrameHandler                               undefined ___CxxFrameHandler()
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
}

// Offset: 0x0055C4D4
undefined FUN_0055c4d4() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0055c4d4()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                              Symbol Ref: No symbol: $L31964
    //                               FUN_0055c4d4                                                 XREF[1]:     ~BuildAIModule:00408d52(*)  
    //         0055c4d4     MOV        EAX,DAT_00578740                                 = 20h     
    //         0055c4d9     JMP        ___CxxFrameHandler                               undefined ___CxxFrameHandler()
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
}

// Offset: 0x0055C4EE
undefined FUN_0055c4ee() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0055c4ee()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                              Symbol Ref: No symbol: $L32016
    //                               FUN_0055c4ee                                                 XREF[1]:     loadBuildList:00409432(*)  
    //         0055c4ee     MOV        EAX,DAT_00578778                                 = 20h     
    //         0055c4f3     JMP        ___CxxFrameHandler                               undefined ___CxxFrameHandler()
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
}

// Offset: 0x0055C50B
undefined FUN_0055c50b() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0055c50b()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                              Symbol Ref: No symbol: $L32052
    //                               FUN_0055c50b                                                 XREF[1]:     insertItem:00409952(*)  
    //         0055c50b     MOV        EAX,DAT_005787a0                                 = 20h     
    //         0055c510     JMP        ___CxxFrameHandler                               undefined ___CxxFrameHandler()
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
}

// Offset: 0x0055C536
undefined FUN_0055c536() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0055c536()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                              Symbol Ref: No symbol: $L30902
    //                               FUN_0055c536                                                 XREF[1]:     ConstructionAIModule:0040aa92(*)  
    //         0055c536     MOV        EAX,DAT_005787c8                                 = 20h     
    //         0055c53b     JMP        ___CxxFrameHandler                               undefined ___CxxFrameHandler()
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
}

// Offset: 0x0055C540
undefined FUN_0055c540() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0055c540()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                              Symbol Ref: No symbol: $L30929
    //                               FUN_0055c540
    //         0055c540     MOV        ECX,dword ptr [EBP + 0xfffffeec]
    //         0055c546     JMP        AIModule::~AIModule                              void ~AIModule(AIModule * this)
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
}

// Offset: 0x0055C54B
undefined FUN_0055c54b() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0055c54b()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                              Symbol Ref: No symbol: $L30930
    //                               FUN_0055c54b
    //         0055c54b     MOV        ECX,dword ptr [EBP + 0xfffffeec]
    //         0055c551     ADD        ECX,0xf4
    //         0055c557     JMP        ConstructionItem::~ConstructionItem              void ~ConstructionItem(ConstructionItem * this)
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
}

// Offset: 0x0055C55C
undefined FUN_0055c55c() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0055c55c()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                              Symbol Ref: No symbol: $L30931
    //                               FUN_0055c55c
    //         0055c55c     MOV        ECX,dword ptr [EBP + 0xfffffeec]
    //         0055c562     ADD        ECX,0x178
    //         0055c568     JMP        ConstructionItem::~ConstructionItem              void ~ConstructionItem(ConstructionItem * this)
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
}

// Offset: 0x0055C56D
undefined FUN_0055c56d() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0055c56d()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                              Symbol Ref: No symbol: $L30932
    //                               FUN_0055c56d
    //         0055c56d     MOV        EAX,dword ptr [EBP + 0xfffffee8]
    //         0055c573     PUSH       EAX
    //         0055c574     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         0055c579     POP        ECX
    //         0055c57a     RET
}

// Offset: 0x0055C57B
undefined FUN_0055c57b() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0055c57b()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                              Symbol Ref: No symbol: $L30933
    //                               FUN_0055c57b
    //         0055c57b     MOV        EAX,dword ptr [EBP + 0xfffffee8]
    //         0055c581     PUSH       EAX
    //         0055c582     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         0055c587     POP        ECX
    //         0055c588     RET
}

// Offset: 0x0055C589
undefined FUN_0055c589() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0055c589()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                              Symbol Ref: No symbol: $L30942
    //                               FUN_0055c589                                                 XREF[1]:     ConstructionAIModule:0040abb2(*)  
    //         0055c589     MOV        EAX,DAT_005787f8                                 = 20h     
    //         0055c58e     JMP        ___CxxFrameHandler                               undefined ___CxxFrameHandler()
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
}

// Offset: 0x0055C5C4
undefined FUN_0055c5c4() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0055c5c4()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                              Symbol Ref: No symbol: $L30954
    //                               FUN_0055c5c4                                                 XREF[1]:     ~ConstructionAIModule:0040b122(*)  
    //         0055c5c4     MOV        EAX,DAT_00578840                                 = 20h     
    //         0055c5c9     JMP        ___CxxFrameHandler                               undefined ___CxxFrameHandler()
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
}

// Offset: 0x0055C5DE
undefined FUN_0055c5de() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0055c5de()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                              Symbol Ref: No symbol: $L30983
    //                               FUN_0055c5de                                                 XREF[1]:     loadConstructionPlan:0040b698(*)  
    //         0055c5de     MOV        EAX,DAT_00578878                                 = 20h     
    //         0055c5e3     JMP        ___CxxFrameHandler                               undefined ___CxxFrameHandler()
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
}

// Offset: 0x0055C5F8
undefined FUN_0055c5f8() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0055c5f8()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                              Symbol Ref: No symbol: $L32373
    //                               FUN_0055c5f8                                                 XREF[1]:     DiplomacyAIModule:0040bf42(*)  
    //         0055c5f8     MOV        EAX,DAT_005788a0                                 = 20h     
    //         0055c5fd     JMP        ___CxxFrameHandler                               undefined ___CxxFrameHandler()
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
}

// Offset: 0x0055C618
undefined FUN_0055c618() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0055c618()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                              Symbol Ref: No symbol: $L30415
    //                               FUN_0055c618                                                 XREF[1]:     EmotionalAIModule:0040c922(*)  
    //         0055c618     MOV        EAX,DAT_005788c8                                 = 20h     
    //         0055c61d     JMP        ___CxxFrameHandler                               undefined ___CxxFrameHandler()
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
}

// Offset: 0x0055C638
undefined FUN_0055c638() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0055c638()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                              Symbol Ref: No symbol: $L33669
    //                               FUN_0055c638                                                 XREF[1]:     MainDecisionAIModule:0040cdf8(*)  
    //         0055c638     MOV        EAX,DAT_005788f0                                 = 20h     
    //         0055c63d     JMP        ___CxxFrameHandler                               undefined ___CxxFrameHandler()
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
}

// Offset: 0x0055C666
undefined FUN_0055c666() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0055c666()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                              Symbol Ref: No symbol: $L33741
    //                               FUN_0055c666                                                 XREF[1]:     MainDecisionAIModule:0040ce92(*)  
    //         0055c666     MOV        EAX,DAT_00578918                                 = 20h     
    //         0055c66b     JMP        ___CxxFrameHandler                               undefined ___CxxFrameHandler()
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
}

// Offset: 0x0055C670
undefined FUN_0055c670() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0055c670()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                              Symbol Ref: No symbol: $L33751
    //                               FUN_0055c670
    //         0055c670     MOV        ECX,dword ptr [EBP + -0x18]
    //         0055c673     JMP        AIModule::~AIModule                              void ~AIModule(AIModule * this)
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
}

// Offset: 0x0055C678
undefined FUN_0055c678() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0055c678()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                              Symbol Ref: No symbol: $L33760
    //                               FUN_0055c678                                                 XREF[1]:     ~MainDecisionAIModule:0040d028(*)  
    //         0055c678     MOV        EAX,DAT_00578948                                 = 20h     
    //         0055c67d     JMP        ___CxxFrameHandler                               undefined ___CxxFrameHandler()
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
}

// Offset: 0x0055C69E
undefined FUN_0055c69e() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0055c69e()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                              Symbol Ref: No symbol: $L30686
    //                               FUN_0055c69e                                                 XREF[1]:     AIModuleMessage:0040de72(*)  
    //         0055c69e     MOV        EAX,DAT_00578970                                 = 20h     
    //         0055c6a3     JMP        ___CxxFrameHandler                               undefined ___CxxFrameHandler()
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
}

// Offset: 0x0055C6BE
undefined FUN_0055c6be() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0055c6be()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                              Symbol Ref: No symbol: $L30701
    //                               FUN_0055c6be                                                 XREF[1]:     AIModuleMessage:0040df52(*)  
    //         0055c6be     MOV        EAX,DAT_00578998                                 = 20h     
    //         0055c6c3     JMP        ___CxxFrameHandler                               undefined ___CxxFrameHandler()
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
}

// Offset: 0x0055C6EC
undefined FUN_0055c6ec() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0055c6ec()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                              Symbol Ref: No symbol: $L30712
    //                               FUN_0055c6ec                                                 XREF[1]:     AIModuleMessage:0040e032(*)  
    //         0055c6ec     MOV        EAX,DAT_005789c0                                 = 20h     
    //         0055c6f1     JMP        ___CxxFrameHandler                               undefined ___CxxFrameHandler()
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
}

// Offset: 0x0055C71C
undefined FUN_0055c71c() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0055c71c()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                              Symbol Ref: No symbol: $L30727
    //                               FUN_0055c71c                                                 XREF[1]:     ~AIModuleMessage:0040e122(*)  
    //         0055c71c     MOV        EAX,DAT_005789f0                                 = 20h     
    //         0055c721     JMP        ___CxxFrameHandler                               undefined ___CxxFrameHandler()
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
}

// Offset: 0x0055C73E
undefined FUN_0055c73e() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0055c73e()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                              Symbol Ref: No symbol: $L33850
    //                               FUN_0055c73e                                                 XREF[1]:     loadPlays:00410228(*)  
    //         0055c73e     MOV        EAX,DAT_00578a20                                 = 20h     
    //         0055c743     JMP        ___CxxFrameHandler                               undefined ___CxxFrameHandler()
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
}

// Offset: 0x0055C758
undefined FUN_0055c758() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0055c758()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                              Symbol Ref: No symbol: $L30745
    //                               FUN_0055c758                                                 XREF[1]:     ResearchAIModule:00411672(*)  
    //         0055c758     MOV        EAX,DAT_00578a48                                 = 20h     
    //         0055c75d     JMP        ___CxxFrameHandler                               undefined ___CxxFrameHandler()
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
}

// Offset: 0x0055C7A5
undefined FUN_0055c7a5() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0055c7a5()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                              Symbol Ref: No symbol: $L30774
    //                               FUN_0055c7a5                                                 XREF[1]:     ResearchAIModule:00411742(*)  
    //         0055c7a5     MOV        EAX,DAT_00578a70                                 = 20h     
    //         0055c7aa     JMP        ___CxxFrameHandler                               undefined ___CxxFrameHandler()
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
}

// Offset: 0x0055C7C6
undefined FUN_0055c7c6() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0055c7c6()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                              Symbol Ref: No symbol: $L30785
    //                               FUN_0055c7c6                                                 XREF[1]:     ~ResearchAIModule:00411942(*)  
    //         0055c7c6     MOV        EAX,DAT_00578ab0                                 = 20h     
    //         0055c7cb     JMP        ___CxxFrameHandler                               undefined ___CxxFrameHandler()
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
}

// Offset: 0x0055C7D0
undefined FUN_0055c7d0() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0055c7d0()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                              Symbol Ref: No symbol: $L30810
    //                               FUN_0055c7d0
    //         0055c7d0     LEA        ECX,[EBP + 0xfffffe84]
    //         0055c7d6     JMP        ResourceItem::~ResourceItem                      void ~ResourceItem(ResourceItem * this)
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
}

// Offset: 0x0055C7DB
undefined FUN_0055c7db() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0055c7db()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                              Symbol Ref: No symbol: $L30811
    //                               FUN_0055c7db
    //         0055c7db     MOV        EAX,dword ptr [EBP + 0xfffffe40]
    //         0055c7e1     PUSH       EAX
    //         0055c7e2     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         0055c7e7     POP        ECX
    //         0055c7e8     RET
}

// Offset: 0x0055C7E9
undefined FUN_0055c7e9() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0055c7e9()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                              Symbol Ref: No symbol: $L30821
    //                               FUN_0055c7e9                                                 XREF[1]:     loadTechnologyTree:00411b88(*)  
    //         0055c7e9     MOV        EAX,DAT_00578ae0                                 = 20h     
    //         0055c7ee     JMP        ___CxxFrameHandler                               undefined ___CxxFrameHandler()
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
}

// Offset: 0x0055C808
undefined FUN_0055c808() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0055c808()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                              Symbol Ref: No symbol: $L30572
    //                               FUN_0055c808                                                 XREF[1]:     ResourceAIModule:00412312(*)  
    //         0055c808     MOV        EAX,DAT_00578b10                                 = 20h     
    //         0055c80d     JMP        ___CxxFrameHandler                               undefined ___CxxFrameHandler()
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
}

// Offset: 0x0055C828
undefined FUN_0055c828() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0055c828()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                              Symbol Ref: No symbol: $L30594
    //                               FUN_0055c828                                                 XREF[1]:     ~ResourceAIModule:00412482(*)  
    //         0055c828     MOV        EAX,DAT_00578b38                                 = 20h     
    //         0055c82d     JMP        ___CxxFrameHandler                               undefined ___CxxFrameHandler()
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
}

// Offset: 0x0055C853
undefined FUN_0055c853() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0055c853()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                              Symbol Ref: No symbol: $L30183
    //                               FUN_0055c853                                                 XREF[1]:     TechnologyItem:00412c28(*)  
    //         0055c853     MOV        EAX,DAT_00578b60                                 = 20h     
    //         0055c858     JMP        ___CxxFrameHandler                               undefined ___CxxFrameHandler()
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
}

// Offset: 0x0055C86B
undefined FUN_0055c86b() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0055c86b()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                              Symbol Ref: No symbol: $L30199
    //                               FUN_0055c86b                                                 XREF[1]:     TechnologyItem:00412cd8(*)  
    //         0055c86b     MOV        EAX,DAT_00578b90                                 = 20h     
    //         0055c870     JMP        ___CxxFrameHandler                               undefined ___CxxFrameHandler()
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
}

// Offset: 0x0055C88B
undefined FUN_0055c88b() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0055c88b()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                              Symbol Ref: No symbol: $L38368
    //                               FUN_0055c88b                                                 XREF[1]:     UnitAIModule:00412f02(*)  
    //         0055c88b     MOV        EAX,DAT_00578bb8                                 = 20h     
    //         0055c890     JMP        ___CxxFrameHandler                               undefined ___CxxFrameHandler()
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
}

// Offset: 0x0055C8AB
undefined FUN_0055c8ab() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0055c8ab()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                              Symbol Ref: No symbol: $L38392
    //                               FUN_0055c8ab                                                 XREF[1]:     ~UnitAIModule:00413092(*)  
    //         0055c8ab     MOV        EAX,DAT_00578be0                                 = 20h     
    //         0055c8b0     JMP        ___CxxFrameHandler                               undefined ___CxxFrameHandler()
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
}

// Offset: 0x0055C8CB
undefined FUN_0055c8cb() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0055c8cb()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                              Symbol Ref: No symbol: $L38494
    //                               FUN_0055c8cb                                                 XREF[1]:     load:00413458(*)  
    //         0055c8cb     MOV        EAX,DAT_00578c08                                 = 20h     
    //         0055c8d0     JMP        ___CxxFrameHandler                               undefined ___CxxFrameHandler()
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
}

// Offset: 0x0055C8EB
undefined FUN_0055c8eb() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0055c8eb()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                              Symbol Ref: No symbol: $L39279
    //                               FUN_0055c8eb                                                 XREF[1]:     setPlayStatus:004177d2(*)  
    //         0055c8eb     MOV        EAX,DAT_00578c30                                 = 20h     
    //         0055c8f0     JMP        ___CxxFrameHandler                               undefined ___CxxFrameHandler()
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
}

// Offset: 0x0055C90B
undefined FUN_0055c90b() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0055c90b()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                              Symbol Ref: No symbol: $L39353
    //                               FUN_0055c90b                                                 XREF[1]:     processOrder:00417b52(*)  
    //         0055c90b     MOV        EAX,DAT_00578c58                                 = 20h     
    //         0055c910     JMP        ___CxxFrameHandler                               undefined ___CxxFrameHandler()
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
}

// Offset: 0x0055C928
undefined FUN_0055c928() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0055c928()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                              Symbol Ref: No symbol: $L33060
    //                               FUN_0055c928                                                 XREF[1]:     RGE_Animated_Object:0041a152(*)  
    //         0055c928     MOV        EAX,DAT_00578c80                                 = 20h     
    //         0055c92d     JMP        ___CxxFrameHandler                               undefined ___CxxFrameHandler()
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
}

// Offset: 0x0055C948
undefined FUN_0055c948() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0055c948()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                              Symbol Ref: No symbol: $L33079
    //                               FUN_0055c948                                                 XREF[1]:     RGE_Animated_Object:0041a212(*)  
    //         0055c948     MOV        EAX,DAT_00578ca8                                 = 20h     
    //         0055c94d     JMP        ___CxxFrameHandler                               undefined ___CxxFrameHandler()
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
}

// Offset: 0x0055C976
undefined FUN_0055c976() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0055c976()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                              Symbol Ref: No symbol: $L31971
    //                               FUN_0055c976                                                 XREF[1]:     load_node:0041a6f8(*)  
    //         0055c976     MOV        EAX,DAT_00578cd0                                 = 20h     
    //         0055c97b     JMP        ___CxxFrameHandler                               undefined ___CxxFrameHandler()
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
}

// Offset: 0x0055C980
undefined FUN_0055c980() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0055c980()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                              Symbol Ref: No symbol: $L30565
    //                               FUN_0055c980
    //         0055c980     MOV        ECX,dword ptr [EBP + DAT_fffffff0]
    //         0055c983     JMP        RGE_Active_Sprite::~RGE_Active_Sprite            void ~RGE_Active_Sprite(RGE_Active_Sprite * t
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
}

// Offset: 0x0055C988
undefined FUN_0055c988() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0055c988()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                              Symbol Ref: No symbol: $L30574
    //                               FUN_0055c988                                                 XREF[1]:     RGE_Active_Animated_Sprite:0041b01
    //         0055c988     MOV        EAX,DAT_00578d00                                 = 20h     
    //         0055c98d     JMP        ___CxxFrameHandler                               undefined ___CxxFrameHandler()
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
}

// Offset: 0x0055C9A8
undefined FUN_0055c9a8() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0055c9a8()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                              Symbol Ref: No symbol: $L30589
    //                               FUN_0055c9a8                                                 XREF[1]:     RGE_Active_Animated_Sprite:0041b14
    //         0055c9a8     MOV        EAX,DAT_00578d28                                 = 20h     
    //         0055c9ad     JMP        ___CxxFrameHandler                               undefined ___CxxFrameHandler()
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
}

// Offset: 0x0055C9F8
undefined FUN_0055c9f8() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0055c9f8()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                              Symbol Ref: No symbol: $L44035
    //                               FUN_0055c9f8                                                 XREF[1]:     setup:0041baa8(*)  
    //         0055c9f8     MOV        EAX,DAT_00578d50                                 = 20h     
    //         0055c9fd     JMP        ___CxxFrameHandler                               undefined ___CxxFrameHandler()
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
}

// Offset: 0x0055CA1B
undefined FUN_0055ca1b() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0055ca1b()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                              Symbol Ref: No symbol: $L44223
    //                               FUN_0055ca1b                                                 XREF[1]:     new_scenario_header:0041ce02(*)  
    //         0055ca1b     MOV        EAX,DAT_00578d90                                 = 20h     
    //         0055ca20     JMP        ___CxxFrameHandler                               undefined ___CxxFrameHandler()
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
}

// Offset: 0x0055CA3B
undefined FUN_0055ca3b() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0055ca3b()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                              Symbol Ref: No symbol: $L44237
    //                               FUN_0055ca3b                                                 XREF[1]:     new_scenario_header:0041ce62(*)  
    //         0055ca3b     MOV        EAX,DAT_00578db8                                 = 20h     
    //         0055ca40     JMP        ___CxxFrameHandler                               undefined ___CxxFrameHandler()
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
}

// Offset: 0x0055CA5B
undefined FUN_0055ca5b() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0055ca5b()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                              Symbol Ref: No symbol: $L44251
    //                               FUN_0055ca5b                                                 XREF[1]:     new_scenario_info:0041cec2(*)  
    //         0055ca5b     MOV        EAX,DAT_00578de0                                 = 20h     
    //         0055ca60     JMP        ___CxxFrameHandler                               undefined ___CxxFrameHandler()
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
}

// Offset: 0x0055CA7B
undefined FUN_0055ca7b() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0055ca7b()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                              Symbol Ref: No symbol: $L44349
    //                               FUN_0055ca7b                                                 XREF[1]:     setup_graphics_system:0041e928(*)  
    //         0055ca7b     MOV        EAX,DAT_00578e08                                 = 20h     
    //         0055ca80     JMP        ___CxxFrameHandler                               undefined ___CxxFrameHandler()
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
}

// Offset: 0x0055CA9B
undefined FUN_0055ca9b() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0055ca9b()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                              Symbol Ref: No symbol: $L44364
    //                               FUN_0055ca9b                                                 XREF[1]:     setup_mouse:0041ebf2(*)  
    //         0055ca9b     MOV        EAX,DAT_00578e30                                 = 20h     
    //         0055caa0     JMP        ___CxxFrameHandler                               undefined ___CxxFrameHandler()
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
}

// Offset: 0x0055CABB
undefined FUN_0055cabb() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0055cabb()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                              Symbol Ref: No symbol: $L44377
    //                               FUN_0055cabb                                                 XREF[1]:     setup_chat:0041ed02(*)  
    //         0055cabb     MOV        EAX,DAT_00578e58                                 = 20h     
    //         0055cac0     JMP        ___CxxFrameHandler                               undefined ___CxxFrameHandler()
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
}

// Offset: 0x0055CADB
undefined FUN_0055cadb() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0055cadb()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                              Symbol Ref: No symbol: $L44390
    //                               FUN_0055cadb                                                 XREF[1]:     setup_registry:0041ed72(*)  
    //         0055cadb     MOV        EAX,DAT_00578e80                                 = 20h     
    //         0055cae0     JMP        ___CxxFrameHandler                               undefined ___CxxFrameHandler()
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
}

// Offset: 0x0055CAFB
undefined FUN_0055cafb() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0055cafb()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                              Symbol Ref: No symbol: $L44403
    //                               FUN_0055cafb                                                 XREF[1]:     setup_debugging_log:0041ede2(*)  
    //         0055cafb     MOV        EAX,DAT_00578ea8                                 = 20h     
    //         0055cb00     JMP        ___CxxFrameHandler                               undefined ___CxxFrameHandler()
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
}

// Offset: 0x0055CB1B
undefined FUN_0055cb1b() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0055cb1b()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                              Symbol Ref: No symbol: $L44416
    //                               FUN_0055cb1b                                                 XREF[1]:     setup_comm:0041ee92(*)  
    //         0055cb1b     MOV        EAX,DAT_00578ed0                                 = 20h     
    //         0055cb20     JMP        ___CxxFrameHandler                               undefined ___CxxFrameHandler()
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
}

// Offset: 0x0055CB3B
undefined FUN_0055cb3b() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0055cb3b()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                              Symbol Ref: No symbol: $L44444
    //                               FUN_0055cb3b                                                 XREF[1]:     setup_sound_system:0041f032(*)  
    //         0055cb3b     MOV        EAX,DAT_00578ef8                                 = 20h     
    //         0055cb40     JMP        ___CxxFrameHandler                               undefined ___CxxFrameHandler()
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
}

// Offset: 0x0055CB5E
undefined FUN_0055cb5e() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0055cb5e()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                              Symbol Ref: No symbol: $L44471
    //                               FUN_0055cb5e                                                 XREF[1]:     setup_music_system:0041f118(*)  
    //         0055cb5e     MOV        EAX,DAT_00578f20                                 = 20h     
    //         0055cb63     JMP        ___CxxFrameHandler                               undefined ___CxxFrameHandler()
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
}

// Offset: 0x0055CB91
undefined FUN_0055cb91() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0055cb91()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                              Symbol Ref: No symbol: $L44497
    //                               FUN_0055cb91                                                 XREF[1]:     setup_shapes:0041f2d2(*)  
    //         0055cb91     MOV        EAX,DAT_00578f48                                 = 20h     
    //         0055cb96     JMP        ___CxxFrameHandler                               undefined ___CxxFrameHandler()
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
}

// Offset: 0x0055CBC1
undefined FUN_0055cbc1() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0055cbc1()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                              Symbol Ref: No symbol: $L44524
    //                               FUN_0055cbc1                                                 XREF[1]:     setup_sounds:0041f402(*)  
    //         0055cbc1     MOV        EAX,DAT_00578f80                                 = 20h     
    //         0055cbc6     JMP        ___CxxFrameHandler                               undefined ___CxxFrameHandler()
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
}

// Offset: 0x0055CBDB
undefined FUN_0055cbdb() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0055cbdb()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                              Symbol Ref: No symbol: $L44544
    //                               FUN_0055cbdb                                                 XREF[1]:     setup_blank_screen:0041f732(*)  
    //         0055cbdb     MOV        EAX,DAT_00578fb8                                 = 20h     
    //         0055cbe0     JMP        ___CxxFrameHandler                               undefined ___CxxFrameHandler()
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
}

// Offset: 0x0055CBFB
undefined FUN_0055cbfb() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0055cbfb()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                              Symbol Ref: No symbol: $L44614
    //                               FUN_0055cbfb                                                 XREF[1]:     create_world:00420052(*)  
    //         0055cbfb     MOV        EAX,DAT_00578fe0                                 = 20h     
    //         0055cc00     JMP        ___CxxFrameHandler                               undefined ___CxxFrameHandler()
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
}

// Offset: 0x0055CC1B
undefined FUN_0055cc1b() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0055cc1b()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                              Symbol Ref: No symbol: $L44985
    //                               FUN_0055cc1b                                                 XREF[1]:     setup_map_save_area:00422ef2(*)  
    //         0055cc1b     MOV        EAX,DAT_00579008                                 = 20h     
    //         0055cc20     JMP        ___CxxFrameHandler                               undefined ___CxxFrameHandler()
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
}

// Offset: 0x0055CC3B
undefined FUN_0055cc3b() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0055cc3b()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                              Symbol Ref: No symbol: $L30992
    //                               FUN_0055cc3b                                                 XREF[1]:     TChat:00423c32(*)  
    //         0055cc3b     MOV        EAX,DAT_00579030                                 = 20h     
    //         0055cc40     JMP        ___CxxFrameHandler                               undefined ___CxxFrameHandler()
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
}

// Offset: 0x0055CC5B
undefined FUN_0055cc5b() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0055cc5b()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                              Symbol Ref: No symbol: $L32555
    //                               FUN_0055cc5b                                                 XREF[1]:     RGE_Communications_Addresses:00424
    //         0055cc5b     MOV        EAX,DAT_00579058                                 = 20h     
    //         0055cc60     JMP        ___CxxFrameHandler                               undefined ___CxxFrameHandler()
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
}

// Offset: 0x0055CCBD
undefined FUN_0055ccbd() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0055ccbd()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                              Symbol Ref: No symbol: $L37634
    //                               FUN_0055ccbd                                                 XREF[1]:     TCommunications_Handler:00425a48(*
    //         0055ccbd     MOV        EAX,DAT_00579080                                 = 20h     
    //         0055ccc2     JMP        ___CxxFrameHandler                               undefined ___CxxFrameHandler()
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
}

// Offset: 0x0055CCDB
undefined FUN_0055ccdb() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0055ccdb()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                              Symbol Ref: No symbol: $L38030
    //                               FUN_0055ccdb                                                 XREF[1]:     TEST:004289a2(*)  
    //         0055ccdb     MOV        EAX,DAT_005790d8                                 = 20h     
    //         0055cce0     JMP        ___CxxFrameHandler                               undefined ___CxxFrameHandler()
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
}

// Offset: 0x0055CD1C
undefined FUN_0055cd1c() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0055cd1c()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                              Symbol Ref: No symbol: $L38486
    //                               FUN_0055cd1c                                                 XREF[1]:     UnlinkCurrentLevel:0042bae2(*)  
    //         0055cd1c     MOV        EAX,DAT_00579100                                 = 20h     
    //         0055cd21     JMP        ___CxxFrameHandler                               undefined ___CxxFrameHandler()
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
}

// Offset: 0x0055CD3B
undefined FUN_0055cd3b() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0055cd3b()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                              Symbol Ref: No symbol: $L33463
    //                               FUN_0055cd3b                                                 XREF[1]:     RGE_Lobby:0042f298(*)  
    //         0055cd3b     MOV        EAX,DAT_00579140                                 = 20h     
    //         0055cd40     JMP        ___CxxFrameHandler                               undefined ___CxxFrameHandler()
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
}

// Offset: 0x0055CD58
undefined FUN_0055cd58() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0055cd58()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                              Symbol Ref: No symbol: $L36440
    //                               FUN_0055cd58                                                 XREF[1]:     RGE_Combat_Object:0042f932(*)  
    //         0055cd58     MOV        EAX,DAT_00579168                                 = 20h     
    //         0055cd5d     JMP        ___CxxFrameHandler                               undefined ___CxxFrameHandler()
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
}

// Offset: 0x0055CD78
undefined FUN_0055cd78() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0055cd78()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                              Symbol Ref: No symbol: $L36455
    //                               FUN_0055cd78                                                 XREF[1]:     RGE_Combat_Object:0042f9e2(*)  
    //         0055cd78     MOV        EAX,DAT_00579190                                 = 20h     
    //         0055cd7d     JMP        ___CxxFrameHandler                               undefined ___CxxFrameHandler()
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
}

// Offset: 0x0055CD98
undefined FUN_0055cd98() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0055cd98()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                              Symbol Ref: No symbol: $L36466
    //                               FUN_0055cd98                                                 XREF[1]:     ~RGE_Combat_Object:0042fa52(*)  
    //         0055cd98     MOV        EAX,DAT_005791b8                                 = 20h     
    //         0055cd9d     JMP        ___CxxFrameHandler                               undefined ___CxxFrameHandler()
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
}

// Offset: 0x0055CDBB
undefined FUN_0055cdbb() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0055cdbb()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                              Symbol Ref: No symbol: $L36593
    //                               FUN_0055cdbb                                                 XREF[1]:     attack:004308c8(*)  
    //         0055cdbb     MOV        EAX,DAT_005791e0                                 = 20h     
    //         0055cdc0     JMP        ___CxxFrameHandler                               undefined ___CxxFrameHandler()
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
}

// Offset: 0x0055CDDB
undefined FUN_0055cddb() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0055cddb()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                              Symbol Ref: No symbol: $L36606
    //                               FUN_0055cddb                                                 XREF[1]:     attack:00430a98(*)  
    //         0055cddb     MOV        EAX,DAT_00579208                                 = 20h     
    //         0055cde0     JMP        ___CxxFrameHandler                               undefined ___CxxFrameHandler()
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
}

// Offset: 0x0055CDFB
undefined FUN_0055cdfb() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0055cdfb()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                              Symbol Ref: No symbol: $L36622
    //                               FUN_0055cdfb                                                 XREF[1]:     moveTo:00430c38(*)  
    //         0055cdfb     MOV        EAX,DAT_00579230                                 = 20h     
    //         0055ce00     JMP        ___CxxFrameHandler                               undefined ___CxxFrameHandler()
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
}

// Offset: 0x0055CE1B
undefined FUN_0055ce1b() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0055ce1b()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                              Symbol Ref: No symbol: $L36639
    //                               FUN_0055ce1b                                                 XREF[1]:     moveTo:00430d58(*)  
    //         0055ce1b     MOV        EAX,DAT_00579258                                 = 20h     
    //         0055ce20     JMP        ___CxxFrameHandler                               undefined ___CxxFrameHandler()
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
}

// Offset: 0x0055CE3B
undefined FUN_0055ce3b() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0055ce3b()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                              Symbol Ref: No symbol: $L36655
    //                               FUN_0055ce3b                                                 XREF[1]:     gather:00430ed8(*)  
    //         0055ce3b     MOV        EAX,DAT_00579280                                 = 20h     
    //         0055ce40     JMP        ___CxxFrameHandler                               undefined ___CxxFrameHandler()
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
}

// Offset: 0x0055CE5B
undefined FUN_0055ce5b() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0055ce5b()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                              Symbol Ref: No symbol: $L36669
    //                               FUN_0055ce5b                                                 XREF[1]:     explore:00431028(*)  
    //         0055ce5b     MOV        EAX,DAT_005792a8                                 = 20h     
    //         0055ce60     JMP        ___CxxFrameHandler                               undefined ___CxxFrameHandler()
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
}

// Offset: 0x0055CE7B
undefined FUN_0055ce7b() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0055ce7b()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                              Symbol Ref: No symbol: $L36683
    //                               FUN_0055ce7b                                                 XREF[1]:     enter:00431158(*)  
    //         0055ce7b     MOV        EAX,DAT_005792d0                                 = 20h     
    //         0055ce80     JMP        ___CxxFrameHandler                               undefined ___CxxFrameHandler()
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
}

// Offset: 0x0055CE9B
undefined FUN_0055ce9b() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0055ce9b()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                              Symbol Ref: No symbol: $L36697
    //                               FUN_0055ce9b                                                 XREF[1]:     transport:00431252(*)  
    //         0055ce9b     MOV        EAX,DAT_005792f8                                 = 20h     
    //         0055cea0     JMP        ___CxxFrameHandler                               undefined ___CxxFrameHandler()
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
}

// Offset: 0x0055CEBB
undefined FUN_0055cebb() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0055cebb()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                              Symbol Ref: No symbol: $L36711
    //                               FUN_0055cebb                                                 XREF[1]:     unload:00431342(*)  
    //         0055cebb     MOV        EAX,DAT_00579320                                 = 20h     
    //         0055cec0     JMP        ___CxxFrameHandler                               undefined ___CxxFrameHandler()
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
}

// Offset: 0x0055CEDB
undefined FUN_0055cedb() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0055cedb()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                              Symbol Ref: No symbol: $L32736
    //                               FUN_0055cedb                                                 XREF[1]:     AllocateQueue:00431812(*)  
    //         0055cedb     MOV        EAX,DAT_00579348                                 = 20h     
    //         0055cee0     JMP        ___CxxFrameHandler                               undefined ___CxxFrameHandler()
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
}

// Offset: 0x0055CF06
undefined FUN_0055cf06() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0055cf06()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                              Symbol Ref: No symbol: $L34335
    //                               FUN_0055cf06                                                 XREF[1]:     RGE_Communications_Speed:00432628(
    //         0055cf06     MOV        EAX,DAT_00579370                                 = 20h     
    //         0055cf0b     JMP        ___CxxFrameHandler                               undefined ___CxxFrameHandler()
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
}

// Offset: 0x0055CF10
undefined FUN_0055cf10() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0055cf10()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                              Symbol Ref: No symbol: $L37725
    //                               FUN_0055cf10
    //         0055cf10     MOV        ECX,dword ptr [EBP + DAT_fffffff0]
    //         0055cf13     JMP        TPanel::~TPanel                                  void ~TPanel(TPanel * this)
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
}

// Offset: 0x0055CF18
undefined FUN_0055cf18() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0055cf18()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                              Symbol Ref: No symbol: $L37730
    //                               FUN_0055cf18                                                 XREF[1]:     ~RGE_Diamond_Map:00436932(*)  
    //         0055cf18     MOV        EAX,DAT_005793a0                                 = 20h     
    //         0055cf1d     JMP        ___CxxFrameHandler                               undefined ___CxxFrameHandler()
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
}

// Offset: 0x0055CF3B
undefined FUN_0055cf3b() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0055cf3b()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                              Symbol Ref: No symbol: $L37769
    //                               FUN_0055cf3b                                                 XREF[1]:     set_bitmap:00436a18(*)  
    //         0055cf3b     MOV        EAX,DAT_005793c8                                 = 20h     
    //         0055cf40     JMP        ___CxxFrameHandler                               undefined ___CxxFrameHandler()
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
}

// Offset: 0x0055CF5B
undefined FUN_0055cf5b() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0055cf5b()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                              Symbol Ref: No symbol: $L37817
    //                               FUN_0055cf5b                                                 XREF[1]:     create_surfaces:00437122(*)  
    //         0055cf5b     MOV        EAX,DAT_005793f0                                 = 20h     
    //         0055cf60     JMP        ___CxxFrameHandler                               undefined ___CxxFrameHandler()
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
}

// Offset: 0x0055CF89
undefined FUN_0055cf89() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0055cf89()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                              Symbol Ref: No symbol: $L33221
    //                               FUN_0055cf89                                                 XREF[1]:     TribeAboutDialog:0043ad78(*)  
    //         0055cf89     MOV        EAX,DAT_00579418                                 = 20h     
    //         0055cf8e     JMP        ___CxxFrameHandler                               undefined ___CxxFrameHandler()
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
}

// Offset: 0x0055CFA8
undefined FUN_0055cfa8() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0055cfa8()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                              Symbol Ref: No symbol: $L33237
    //                               FUN_0055cfa8                                                 XREF[1]:     ~TribeAboutDialog:0043b302(*)  
    //         0055cfa8     MOV        EAX,DAT_00579448                                 = 20h     
    //         0055cfad     JMP        ___CxxFrameHandler                               undefined ___CxxFrameHandler()
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
}

// Offset: 0x0055CFCB
undefined FUN_0055cfcb() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0055cfcb()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                              Symbol Ref: No symbol: $L33252
    //                               FUN_0055cfcb                                                 XREF[1]:     action:0043b408(*)  
    //         0055cfcb     MOV        EAX,DAT_00579470                                 = 20h     
    //         0055cfd0     JMP        ___CxxFrameHandler                               undefined ___CxxFrameHandler()
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
}

// Offset: 0x0055CFE8
undefined FUN_0055cfe8() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0055cfe8()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                              Symbol Ref: No symbol: $L44204
    //                               FUN_0055cfe8                                                 XREF[1]:     TribeConfigDialog:0043b562(*)  
    //         0055cfe8     MOV        EAX,DAT_00579498                                 = 20h     
    //         0055cfed     JMP        ___CxxFrameHandler                               undefined ___CxxFrameHandler()
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
}

