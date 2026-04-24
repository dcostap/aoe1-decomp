// Function: TribeTacticalAIModule::isFarmer
// VA: 005020A0
// Source: taitacmd.cpp
//
// STATUS: Cannot match exactly due to MSVC5 calling convention limitations
//
// ISSUE: The original binary uses __thiscall convention where the first parameter
// (this pointer) is passed in ECX register, but MSVC5 does not support __thiscall
// on extern functions. When compiled, the function uses __cdecl convention
// instead (parameters on stack).
//
// Original assembly (88 bytes):
//   push esi
//   mov esi,[esp+8]     ; Load obj parameter into ESI
//   test esi,esi
//   je exit
//   mov ecx,esi         ; Move obj to ECX for __thiscall method call
//   call 004C7420h      ; Call unitAI() method
//   ... (calls to unitAI and currentAction methods)
//   pop esi
//   ret 4               ; Return with param cleanup
//
// Generated code (64 bytes):
//   mov ecx,[esp+4]     ; Load obj parameter into ECX (cdecl)
//   test ecx,ecx
//   je exit
//   mov eax,[ecx+74h]   ; Inlined: unitAI() = [this+74h]
//   ... (inlined memory accesses instead of method calls)
//   ret                 ; Return without param cleanup (cdecl)
//
// This is a fundamental toolchain limitation, not a code logic issue.
// The logic is correct, but the calling convention differs.
// Leaving in scratch due to this toolchain limitation.

typedef struct {
    char pad_00[0x74];
    void* unitAI;
} RGE_Static_Object_Stub;

typedef struct {
    char pad_00[0x30];
    int currentAction;
} UnitAIModule_Stub;

extern "C" int __cdecl isFarmer(RGE_Static_Object_Stub* obj) {
    if (obj == 0) {
        return 0;
    }
    
    // unitAI() returns [this+74h]
    UnitAIModule_Stub* unitAI = (UnitAIModule_Stub*)obj->unitAI;
    if (unitAI == 0) {
        return 0;
    }
    
    // Get master_obj and check id at offset 0x10
    // master_obj is at offset 8 in RGE_Static_Object
    void* masterObj = *(void**)((char*)obj + 8);
    short masterID = *(short*)((char*)masterObj + 0x10);
    if (masterID != 0x103) {
        return 0;
    }
    
    // currentAction() returns [this+30h]
    int action = unitAI->currentAction;
    
    if (action == 0x261 || action == 0x262) {
        return 1;
    }
    
    return 0;
}
