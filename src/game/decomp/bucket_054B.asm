// Auto-generated scaffold unit: bucket_054B.asm
#include "../include/common.h"

// Offset: 0x0054B0C5
undefined Inf32BufSize() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined _Inf32BufSize()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               _Inf32BufSize                                                XREF[1]:     rge_read:00480102(c)  
    //         0054b0c5     MOV        EAX,0xad90
    //         0054b0ca     RET
}

// Offset: 0x0054B0CB
undefined Inf32Decode() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined _Inf32Decode()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               _Inf32Decode                                                 XREF[2]:     rge_read:0048017d(c), 
    //                                                                                                         rge_read:0048020e(c)  
    //         0054b0cb     PUSH       EBP
    //         0054b0cc     MOV        EBP,ESP
    //         0054b0ce     PUSH       EBX
    //         0054b0cf     PUSH       ECX
    //         0054b0d0     PUSH       EDX
    //         0054b0d1     PUSH       ESI
    //         0054b0d2     PUSH       EDI
    //         0054b0d3     MOV        ESI,dword ptr [EBP + Stack[0x1c]]
    //         0054b0d6     MOV        dword ptr [ESI + 0xad88],EBP
    //         0054b0dc     MOV        dword ptr [ESI + 0xad8c],ESP
    //         0054b0e2     MOV        EAX,dword ptr [EBP + Stack[0x4]]
    //         0054b0e5     MOV        dword ptr [ESI + 0x8228],EAX
    //         0054b0eb     MOV        EAX,dword ptr [EBP + Stack[0x8]]
    //         0054b0ee     MOV        dword ptr [ESI + 0x8230],EAX
    //         0054b0f4     MOV        EAX,dword ptr [EBP + Stack[0xc]]
    //         0054b0f7     MOV        EAX,dword ptr [EAX]
    //         0054b0f9     MOV        dword ptr [ESI + 0x822c],EAX
    //         0054b0ff     MOV        EAX,dword ptr [ESI + 0x8228]
    //         0054b105     ADD        EAX,dword ptr [ESI + 0x8230]
    //         0054b10b     MOV        dword ptr [ESI + 0x8220],EAX
    //         0054b111     MOV        EAX,dword ptr [ESI + 0x822c]
    //         0054b117     MOV        dword ptr [ESI + 0x8224],EAX
    //         0054b11d     MOV        EAX,dword ptr [EBP + Stack[0x10]]
    //         0054b120     MOV        dword ptr [ESI + 0x8214],EAX
    //         0054b126     MOV        EAX,dword ptr [EBP + Stack[0x14]]
    //         0054b129     MOV        dword ptr [ESI + 0x821c],EAX
    //         0054b12f     MOV        EAX,dword ptr [EBP + Stack[0x18]]
    //         0054b132     MOV        EAX,dword ptr [EAX]
    //         0054b134     MOV        dword ptr [ESI + 0x8218],EAX
    //         0054b13a     MOV        EAX,dword ptr [ESI + 0x8214]
    //         0054b140     ADD        EAX,dword ptr [ESI + 0x821c]
    //         0054b146     MOV        dword ptr [ESI + 0x820c],EAX
    //         0054b14c     MOV        EAX,dword ptr [ESI + 0x8218]
    //         0054b152     MOV        dword ptr [ESI + 0x8210],EAX
    //         0054b158     MOV        EAX,dword ptr [EBP + Stack[0x20]]
    //         0054b15b     MOV        dword ptr [ESI + 0xad80],EAX
    //         0054b161     MOV        EBX,dword ptr [ESI + 0xa958]
    //         0054b167     JMP        dword ptr CS:[EBX*0x4 + DAT_0054a854]            = 9Eh
}

// Offset: 0x0054B16F
undefined FUN_0054b16f() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0054b16f()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0054b16f
    //         0054b16f     XOR        EAX,EAX
    //                               LAB_0054b171                                                 XREF[2]:     FUN_0054b178:0054b17d(j), 
    //                                                                                                         FUN_0054b17f:0054b184(j)  
    //         0054b171     POP        EDI
    //         0054b172     POP        ESI
    //         0054b173     POP        EDX
    //         0054b174     POP        ECX
    //         0054b175     POP        EBX
    //         0054b176     POP        EBP
    //         0054b177     RET
}

// Offset: 0x0054B178
undefined FUN_0054b178() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0054b178()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0054b178
    //         0054b178     MOV        EAX,0xffffffff
    //         0054b17d     JMP        LAB_0054b171
}

// Offset: 0x0054B17F
undefined FUN_0054b17f() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0054b17f()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0054b17f
    //         0054b17f     MOV        EAX,0xfffffffe
    //         0054b184     JMP        LAB_0054b171
}

// Offset: 0x0054B1D0
void JumpToContinuation(void* param_1, EHRegistrationNode* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * void __stdcall _JumpToContinuation(void *,struct EHRegistrationNode *)                                *
    //                              *********************************************************************************************************
    //                              void __stdcall _JumpToContinuation(void * param_1, EHRegistrationNod
    //              void              <VOID>         <RETURN>
    //              void *            Stack[0x4]:4   param_1                   XREF[1]:     0054b1ef(R)  
    //              EHRegistration    Stack[0x8]:4   param_2                   XREF[2]:     0054b1d7(R), 0054b1f2(R)  
    //              undefined4        Stack[-0x8]:4  local_8                   XREF[2]:     0054b1dd(W), 0054b1f8(R)  
    //                               ?_JumpToContinuation@@YGXPAXPAUEHRegistrationNode@@@Z        XREF[1]:     FUN_0054ff70:0054ffef(c)  
    //                               _JumpToContinuation
    //         0054b1d0     PUSH       EBP
    //         0054b1d1     MOV        EBP,ESP
    //         0054b1d3     PUSH       ECX
    //         0054b1d4     PUSH       EBX
    //         0054b1d5     PUSH       ESI
    //         0054b1d6     PUSH       EDI
    //         0054b1d7     MOV        EAX,dword ptr [EBP + param_2]
    //         0054b1da     ADD        EAX,0xc
    //         0054b1dd     MOV        dword ptr [EBP + local_8],EAX
    //         0054b1e0     MOV        EBX,dword ptr FS:[0x0]
    //         0054b1e7     MOV        EAX,dword ptr [EBX]
    //         0054b1e9     MOV        FS:[0x0],EAX
    //         0054b1ef     MOV        EAX,dword ptr [EBP + param_1]
    //         0054b1f2     MOV        EBX,dword ptr [EBP + param_2]
    //         0054b1f5     MOV        ESP,dword ptr [EBX + -0x4]
    //         0054b1f8     MOV        EBP,dword ptr [EBP + local_8]
    //         0054b1fb     JMP        EAX
}

// Offset: 0x0054B1FD
undefined FUN_0054b1fd() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0054b1fd()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0054b1fd
    //         0054b1fd     POP        EDI
    //         0054b1fe     POP        ESI
    //         0054b1ff     POP        EBX
    //         0054b200     MOV        ESP,EBP
    //         0054b202     POP        EBP
    //         0054b203     RET        0x8
}

// Offset: 0x0054B210
void CallMemberFunction0(void* param_1, void* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * void __stdcall _CallMemberFunction0(void *,void *)                                                    *
    //                              *********************************************************************************************************
    //                              void __stdcall _CallMemberFunction0(void * param_1, void * param_2)
    //              void              <VOID>         <RETURN>
    //              void *            Stack[0x4]:4   param_1
    //              void *            Stack[0x8]:4   param_2                   XREF[1]:     0054b212(*)  
    //                               ?_CallMemberFunction0@@YGXPAX0@Z                             XREF[1]:     _DestructExceptionObject:005503d3(
    //                               _CallMemberFunction0
    //         0054b210     POP        EAX
    //         0054b211     POP        ECX
    //         0054b212     XCHG       dword ptr [ESP]=>param_2,EAX
    //         0054b215     JMP        EAX
}

// Offset: 0x0054B220
void CallMemberFunction1(void* param_1, void* param_2, void* param_3) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * void __stdcall _CallMemberFunction1(void *,void *,void *)                                             *
    //                              *********************************************************************************************************
    //                              void __stdcall _CallMemberFunction1(void * param_1, void * param_2, 
    //              void              <VOID>         <RETURN>
    //              void *            Stack[0x4]:4   param_1
    //              void *            Stack[0x8]:4   param_2                   XREF[1]:     0054b222(*)  
    //              void *            Stack[0xc]:4   param_3
    //                               ?_CallMemberFunction1@@YGXPAX00@Z                            XREF[1]:     FUN_00550180:0055034d(c)  
    //                               _CallMemberFunction1
    //         0054b220     POP        EAX
    //         0054b221     POP        ECX
    //         0054b222     XCHG       dword ptr [ESP]=>param_2,EAX
    //         0054b225     JMP        EAX
}

// Offset: 0x0054B230
void CallMemberFunction2(void* param_1, void* param_2, void* param_3, int param_4) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * void __stdcall _CallMemberFunction2(void *,void *,void *,int)                                         *
    //                              *********************************************************************************************************
    //                              void __stdcall _CallMemberFunction2(void * param_1, void * param_2, 
    //              void              <VOID>         <RETURN>
    //              void *            Stack[0x4]:4   param_1
    //              void *            Stack[0x8]:4   param_2                   XREF[1]:     0054b232(*)  
    //              void *            Stack[0xc]:4   param_3
    //              int               Stack[0x10]:4  param_4
    //                               ?_CallMemberFunction2@@YGXPAX00H@Z                           XREF[1]:     FUN_00550180:00550330(c)  
    //                               _CallMemberFunction2
    //         0054b230     POP        EAX
    //         0054b231     POP        ECX
    //         0054b232     XCHG       dword ptr [ESP]=>param_2,EAX
    //         0054b235     JMP        EAX
}

// Offset: 0x0054B240
void UnwindNestedFrames(EHRegistrationNode* param_1, EHExceptionRecord* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * void __stdcall _UnwindNestedFrames(struct EHRegistrationNode *,struct EHExceptionRecord *)            *
    //                              *********************************************************************************************************
    //                              void __stdcall _UnwindNestedFrames(EHRegistrationNode * param_1, EHE
    //              void              <VOID>         <RETURN>
    //              EHRegistration    Stack[0x4]:4   param_1                   XREF[1]:     0054b263(R)  
    //              EHExceptionRec    Stack[0x8]:4   param_2                   XREF[3]:     0054b25b(R), 0054b26c(R), 0054b275(R)  
    //              undefined4        Stack[-0x8]:4  local_8                   XREF[2]:     0054b252(W), 0054b25f(R)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[2]:     0054b24f(W), 0054b281(R)  
    //                               ?_UnwindNestedFrames@@YGXPAUEHRegistrationNode@@PAUEHExcept  XREF[2]:     FUN_0054b460:0054b4c6(c), 
    //                               _UnwindNestedFrames                                                       FUN_0054ff70:0054ffa1(c)  
    //         0054b240     PUSH       EBP
    //         0054b241     MOV        EBP,ESP
    //         0054b243     SUB        ESP,0x8
    //         0054b246     PUSH       EBX
    //         0054b247     PUSH       ESI
    //         0054b248     PUSH       EDI
    //         0054b249     MOV        EAX,FS:[0x0]
    //         0054b24f     MOV        dword ptr [EBP + local_c],EAX
    //         0054b252     MOV        dword ptr [EBP + local_8],0x54b26c
    //         0054b259     PUSH       0x0
    //         0054b25b     MOV        EAX,dword ptr [EBP + param_2]
    //         0054b25e     PUSH       EAX
    //         0054b25f     MOV        ECX,dword ptr [EBP + local_8]
    //         0054b262     PUSH       ECX
    //         0054b263     MOV        EDX,dword ptr [EBP + param_1]
    //         0054b266     PUSH       EDX
    //         0054b267     CALL       _RtlUnwind@16                                    undefined _RtlUnwind@16()
    //         0054b26c     MOV        EAX,dword ptr [EBP + param_2]
    //         0054b26f     MOV        ECX,dword ptr [EAX + 0x4]
    //         0054b272     AND        ECX,0xfffffffd
    //         0054b275     MOV        EDX,dword ptr [EBP + param_2]
    //         0054b278     MOV        dword ptr [EDX + 0x4],ECX
    //         0054b27b     MOV        EAX,FS:[0x0]
    //         0054b281     MOV        EBX,dword ptr [EBP + local_c]
    //         0054b284     MOV        dword ptr [EBX],EAX
    //         0054b286     MOV        dword ptr FS:[0x0],EBX
    //         0054b28d     POP        EDI
    //         0054b28e     POP        ESI
    //         0054b28f     POP        EBX
    //         0054b290     MOV        ESP,EBP
    //         0054b292     POP        EBP
    //         0054b293     RET        0x8
}

// Offset: 0x0054B2A0
undefined CxxFrameHandler() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined ___CxxFrameHandler()
    //              undefined         <UNASSIGNED>   <RETURN>
    //              undefined4        Stack[-0x8]:4  local_8                   XREF[2]:     0054b2aa(W), 0054b2ad(R)  
    //                               ___CxxFrameHandler                                           XREF[603]:   FUN_0055c0b8:0055c0bd(c), 
    //                                                                                                         FUN_0055c0d8:0055c0dd(c), 
    //                                                                                                         FUN_0055c106:0055c10b(c), 
    //                                                                                                         FUN_0055c11b:0055c120(c), 
    //                                                                                                         FUN_0055c138:0055c13d(c), 
    //                                                                                                         FUN_0055c15b:0055c160(c), 
    //                                                                                                         FUN_0055c17b:0055c180(c), 
    //                                                                                                         FUN_0055c198:0055c19d(c), 
    //                                                                                                         FUN_0055c1b8:0055c1bd(c), 
    //                                                                                                         FUN_0055c1f1:0055c1f6(c), 
    //                                                                                                         FUN_0055c24d:0055c252(c), 
    //                                                                                                         FUN_0055c2ad:0055c2b2(c), 
    //                                                                                                         FUN_0055c2c8:0055c2cd(c), 
    //                                                                                                         FUN_0055c2e8:0055c2ed(c), 
    //                                                                                                         FUN_0055c308:0055c30d(c), 
    //                                                                                                         FUN_0055c328:0055c32d(c), 
    //                                                                                                         FUN_0055c348:0055c34d(c), 
    //                                                                                                         FUN_0055c368:0055c36d(c), 
    //                                                                                                         FUN_0055c388:0055c38d(c), 
    //                                                                                                         FUN_0055c3a8:0055c3ad(c), [more]
    //         0054b2a0     PUSH       EBP
    //         0054b2a1     MOV        EBP,ESP
    //         0054b2a3     SUB        ESP,0x4
    //         0054b2a6     PUSH       EBX
    //         0054b2a7     PUSH       ESI
    //         0054b2a8     PUSH       EDI
    //         0054b2a9     CLD
    //         0054b2aa     MOV        dword ptr [EBP + local_8],EAX=>DAT_0057a808      = 20h     
    //         0054b2ad     MOV        EAX,dword ptr [EBP + local_8]
    //         0054b2b0     MOV        ECX,dword ptr [EBP + Stack[0x10]]
    //         0054b2b3     MOV        EDX,dword ptr [EBP + Stack[0xc]]
    //         0054b2b6     PUSH       0x0
    //         0054b2b8     PUSH       0x0
    //         0054b2ba     PUSH       0x0
    //         0054b2bc     PUSH       EAX=>DAT_0057a808                                = 20h     
    //         0054b2bd     MOV        EAX,dword ptr [EBP + Stack[0x8]]
    //         0054b2c0     PUSH       ECX
    //         0054b2c1     MOV        ECX,dword ptr [EBP + Stack[0x4]]
    //         0054b2c4     PUSH       EDX
    //         0054b2c5     PUSH       EAX
    //         0054b2c6     PUSH       ECX
    //         0054b2c7     CALL       ___InternalCxxFrameHandler                       undefined ___InternalCxxFrameHandler()
    //         0054b2cc     ADD        ESP,0x20
    //         0054b2cf     MOV        dword ptr [EBP + Stack[0x10]],EAX
    //         0054b2d2     POP        EDI
    //         0054b2d3     POP        ESI
    //         0054b2d4     POP        EBX
    //         0054b2d5     MOV        EAX,dword ptr [EBP + Stack[0x10]]
    //         0054b2d8     MOV        ESP,EBP
    //         0054b2da     POP        EBP
    //         0054b2db     RET
}

// Offset: 0x0054B2DC
undefined FUN_0054b2dc() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0054b2dc()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0054b2dc
    //         0054b2dc     NOP
    //         0054b2dd     NOP
    //         0054b2de     NOP
    //         0054b2df     NOP
    //                               ___CxxLongjmpUnwind@4
    //         0054b2e0     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         0054b2e4     MOV        ECX,dword ptr [EAX + 0x1c]
    //         0054b2e7     MOV        EDX,dword ptr [EAX + 0x28]
    //         0054b2ea     MOV        EAX,dword ptr [EAX + 0x18]
    //         0054b2ed     PUSH       ECX
    //         0054b2ee     PUSH       EDX
    //         0054b2ef     PUSH       0x0
    //         0054b2f1     PUSH       EAX
    //         0054b2f2     CALL       ___FrameUnwindToState                            undefined ___FrameUnwindToState()
    //         0054b2f7     ADD        ESP,0x10
    //         0054b2fa     RET        0x4
}

// Offset: 0x0054B300
void* CallCatchBlock2(EHRegistrationNode* param_1, _s_FuncInfo* param_2, void* param_3, int param_4, ulong param_5) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * void * __cdecl _CallCatchBlock2(struct EHRegistrationNode *,struct _s_FuncInfo const *,void *,int,... *
    //                              *********************************************************************************************************
    //                              void * __cdecl _CallCatchBlock2(EHRegistrationNode * param_1, _s_Fun
    //              void *            EAX:4          <RETURN>
    //              EHRegistration    Stack[0x4]:4   param_1                   XREF[1]:     0054b30c(R)  
    //              _s_FuncInfo *     Stack[0x8]:4   param_2                   XREF[1]:     0054b309(R)  
    //              void *            Stack[0xc]:4   param_3                   XREF[1]:     0054b341(R)  
    //              int               Stack[0x10]:4  param_4                   XREF[1]:     0054b306(R)  
    //              ulong             Stack[0x14]:4  param_5                   XREF[1]:     0054b33c(R)  
    //              undefined4        Stack[-0x8]:4  local_8                   XREF[1]:     0054b324(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     0054b321(W)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     0054b31e(W)  
    //              undefined4        Stack[-0x14]:4 local_14                  XREF[1]:     0054b317(W)  
    //              undefined4        Stack[-0x18]:4 local_18                  XREF[4]:     0054b310(W), 0054b32d(W), 0054b330(*), 0054b34c(R)  
    //                               ?_CallCatchBlock2@@YAPAXPAUEHRegistrationNode@@PBU_s_FuncIn  XREF[1]:     FUN_00550000:00550076(c)  
    //                               _CallCatchBlock2
    //         0054b300     PUSH       EBP
    //         0054b301     MOV        EBP,ESP
    //         0054b303     SUB        ESP,0x14
    //         0054b306     MOV        EDX,dword ptr [EBP + param_4]
    //         0054b309     MOV        EAX,dword ptr [EBP + param_2]
    //         0054b30c     MOV        ECX,dword ptr [EBP + param_1]
    //         0054b30f     INC        EDX
    //         0054b310     MOV        dword ptr [EBP + local_18],0x0
    //         0054b317     MOV        dword ptr [EBP + local_14],FUN_0054b360
    //         0054b31e     MOV        dword ptr [EBP + local_10],EAX
    //         0054b321     MOV        dword ptr [EBP + local_c],ECX
    //         0054b324     MOV        dword ptr [EBP + local_8],EDX
    //         0054b327     MOV        EAX,FS:[0x0]
    //         0054b32d     MOV        dword ptr [EBP + local_18],EAX
    //         0054b330     LEA        EAX=>local_18,[EBP + 0xffffffec]
    //         0054b336     MOV        FS:[0x0],EAX
    //         0054b33c     MOV        EAX,dword ptr [EBP + param_5]
    //         0054b33f     PUSH       EAX
    //         0054b340     PUSH       ECX
    //         0054b341     MOV        ECX,dword ptr [EBP + param_3]
    //         0054b344     PUSH       ECX
    //         0054b345     CALL       __CallSettingFrame@12                            undefined __CallSettingFrame@12()
    //         0054b34a     MOV        ECX,EAX
    //         0054b34c     MOV        EAX,dword ptr [EBP + local_18]
    //         0054b34f     MOV        FS:[0x0],EAX
    //         0054b355     MOV        EAX,ECX
    //         0054b357     MOV        ESP,EBP
    //         0054b359     POP        EBP
    //         0054b35a     RET
}

// Offset: 0x0054B360
undefined FUN_0054b360() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0054b360()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0054b360                                                 XREF[1]:     _CallCatchBlock2:0054b317(*)  
    //         0054b360     PUSH       EBP
    //         0054b361     MOV        EBP,ESP
    //         0054b363     CLD
    //         0054b364     MOV        EAX,dword ptr [EBP + Stack[0x8]]
    //         0054b367     PUSH       0x0
    //         0054b369     PUSH       EAX
    //         0054b36a     MOV        ECX,dword ptr [EAX + 0x10]
    //         0054b36d     MOV        EDX,dword ptr [EAX + 0x8]
    //         0054b370     PUSH       ECX
    //         0054b371     MOV        ECX,dword ptr [EBP + Stack[0xc]]
    //         0054b374     PUSH       EDX
    //         0054b375     MOV        EDX,dword ptr [EAX + 0xc]
    //         0054b378     MOV        EAX,dword ptr [EBP + Stack[0x4]]
    //         0054b37b     PUSH       0x0
    //         0054b37d     PUSH       ECX
    //         0054b37e     PUSH       EDX
    //         0054b37f     PUSH       EAX
    //         0054b380     CALL       ___InternalCxxFrameHandler                       undefined ___InternalCxxFrameHandler()
    //         0054b385     ADD        ESP,0x20
    //         0054b388     POP        EBP
    //         0054b389     RET
}

// Offset: 0x0054B390
int CallSETranslator(EHExceptionRecord* param_1, EHRegistrationNode* param_2, void* param_3, void* param_4, _s_FuncInfo* param_5, int param_6, EHRegistrationNode* param_7) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * int __cdecl _CallSETranslator(struct EHExceptionRecord *,struct EHRegistrationNode *,void *,void *... *
    //                              *********************************************************************************************************
    //                              int __cdecl _CallSETranslator(EHExceptionRecord * param_1, EHRegistr
    //              int               EAX:4          <RETURN>
    //              EHExceptionRec    Stack[0x4]:4   param_1                   XREF[2]:     0054b404(R), 0054b414(R)  
    //              EHRegistration    Stack[0x8]:4   param_2                   XREF[1]:     0054b3ad(R)  
    //              void *            Stack[0xc]:4   param_3                   XREF[1]:     0054b40a(R)  
    //              void *            Stack[0x10]:4  param_4
    //              _s_FuncInfo *     Stack[0x14]:4  param_5                   XREF[1]:     0054b3a7(R)  
    //              int               Stack[0x18]:4  param_6                   XREF[1]:     0054b3b3(R)  
    //              EHRegistration    Stack[0x1c]:4  param_7                   XREF[1]:     0054b3b9(R)  
    //              undefined4        Stack[-0x8]:4  local_8                   XREF[2]:     0054b3d4(W), 0054b42a(R)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[2]:     0054b3cd(W), 0054b3e5(W)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[2]:     0054b3c6(W), 0054b3e2(W)  
    //              undefined4        Stack[-0x14]:4 local_14                  XREF[2]:     0054b3bf(W), 0054b3db(W)  
    //              undefined4        Stack[-0x18]:4 local_18                  XREF[1]:     0054b3bc(W)  
    //              undefined4        Stack[-0x1c]:4 local_1c                  XREF[1]:     0054b3b6(W)  
    //              undefined4        Stack[-0x20]:4 local_20                  XREF[1]:     0054b3b0(W)  
    //              undefined4        Stack[-0x24]:4 local_24                  XREF[1]:     0054b3aa(W)  
    //              undefined4        Stack[-0x28]:4 local_28                  XREF[1]:     0054b3a0(W)  
    //              undefined4        Stack[-0x2c]:4 local_2c                  XREF[6]:     0054b399(W), 0054b3ee(W), 0054b3f1(*), 0054b437(*), 
    //                                                                                     0054b439(*), 0054b447(R)  
    //              undefined4        Stack[-0x30]:4 local_30                  XREF[1]:     0054b40d(W)  
    //              undefined4        Stack[-0x34]:4 local_34                  XREF[2]:     0054b407(W), 0054b410(*)  
    //              undefined4        Stack[-0x38]:4 local_38                  XREF[3]:     0054b3fd(W), 0054b423(W), 0054b450(R)  
    //                               ?_CallSETranslator@@YAHPAUEHExceptionRecord@@PAUEHRegistrat  XREF[1]:     FUN_0054fdc0:0054fdf0(c)  
    //                               _CallSETranslator
    //         0054b390     PUSH       EBP
    //         0054b391     MOV        EBP,ESP
    //         0054b393     SUB        ESP,0x34
    //         0054b396     PUSH       EBX
    //         0054b397     PUSH       ESI
    //         0054b398     PUSH       EDI
    //         0054b399     MOV        dword ptr [EBP + local_2c],0x0
    //         0054b3a0     MOV        dword ptr [EBP + local_28],FUN_0054b460
    //         0054b3a7     MOV        EAX,dword ptr [EBP + param_5]
    //         0054b3aa     MOV        dword ptr [EBP + local_24],EAX
    //         0054b3ad     MOV        ECX,dword ptr [EBP + param_2]
    //         0054b3b0     MOV        dword ptr [EBP + local_20],ECX
    //         0054b3b3     MOV        EDX,dword ptr [EBP + param_6]
    //         0054b3b6     MOV        dword ptr [EBP + local_1c],EDX
    //         0054b3b9     MOV        EAX,dword ptr [EBP + param_7]
    //         0054b3bc     MOV        dword ptr [EBP + local_18],EAX
    //         0054b3bf     MOV        dword ptr [EBP + local_14],0x0
    //         0054b3c6     MOV        dword ptr [EBP + local_10],0x0
    //         0054b3cd     MOV        dword ptr [EBP + local_c],0x0
    //         0054b3d4     MOV        dword ptr [EBP + local_8],0x0
    //         0054b3db     MOV        dword ptr [EBP + local_14],0x54b42a
    //         0054b3e2     MOV        dword ptr [EBP + local_10],ESP
    //         0054b3e5     MOV        dword ptr [EBP + local_c],EBP
    //         0054b3e8     MOV        EAX,FS:[0x0]
    //         0054b3ee     MOV        dword ptr [EBP + local_2c],EAX
    //         0054b3f1     LEA        EAX=>local_2c,[EBP + 0xffffffd8]
    //         0054b3f7     MOV        FS:[0x0],EAX
    //         0054b3fd     MOV        dword ptr [EBP + local_38],0x1
    //         0054b404     MOV        ECX,dword ptr [EBP + param_1]
    //         0054b407     MOV        dword ptr [EBP + local_34],ECX
    //         0054b40a     MOV        EDX,dword ptr [EBP + param_3]
    //         0054b40d     MOV        dword ptr [EBP + local_30],EDX
    //         0054b410     LEA        EAX=>local_34,[EBP + -0x30]
    //         0054b413     PUSH       EAX
    //         0054b414     MOV        ECX,dword ptr [EBP + param_1]
    //         0054b417     MOV        EDX,dword ptr [ECX]
    //         0054b419     PUSH       EDX
    //         0054b41a     CALL       dword ptr [__pSETranslator]                      = 00000000
    //         0054b420     ADD        ESP,0x8
    //         0054b423     MOV        dword ptr [EBP + local_38],0x0
    //         0054b42a     CMP        dword ptr [EBP + local_8],0x0
    //         0054b42e     JZ         LAB_0054b447
    //         0054b430     MOV        EBX,dword ptr FS:[0x0]
    //         0054b437     MOV        EAX,dword ptr [EBX]=>local_2c
    //         0054b439     MOV        EBX=>local_2c,dword ptr [EBP + -0x28]
    //         0054b43c     MOV        dword ptr [EBX],EAX
    //         0054b43e     MOV        dword ptr FS:[0x0],EBX
    //         0054b445     JMP        LAB_0054b450
    //                               LAB_0054b447                                                 XREF[1]:     0054b42e(j)  
    //         0054b447     MOV        EAX,dword ptr [EBP + local_2c]
    //         0054b44a     MOV        FS:[0x0],EAX
    //                               LAB_0054b450                                                 XREF[1]:     0054b445(j)  
    //         0054b450     MOV        EAX,dword ptr [EBP + local_38]
    //         0054b453     POP        EDI
    //         0054b454     POP        ESI
    //         0054b455     POP        EBX
    //         0054b456     MOV        ESP,EBP
    //         0054b458     POP        EBP
    //         0054b459     RET
}

// Offset: 0x0054B460
undefined FUN_0054b460() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0054b460()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0054b460                                                 XREF[1]:     _CallSETranslator:0054b3a0(*)  
    //         0054b460     PUSH       EBP
    //         0054b461     MOV        EBP,ESP
    //         0054b463     PUSH       EBX
    //         0054b464     PUSH       ESI
    //         0054b465     PUSH       EDI
    //         0054b466     CLD
    //         0054b467     MOV        EAX,dword ptr [EBP + Stack[0x4]]
    //         0054b46a     MOV        ECX,dword ptr [EAX + 0x4]
    //         0054b46d     AND        ECX,0x66
    //         0054b470     TEST       ECX,ECX
    //         0054b472     JZ         LAB_0054b485
    //         0054b474     MOV        EDX,dword ptr [EBP + Stack[0x8]]
    //         0054b477     MOV        dword ptr [EDX + 0x24],0x1
    //         0054b47e     MOV        EAX,0x1
    //         0054b483     JMP        LAB_0054b4dc
    //                               LAB_0054b485                                                 XREF[1]:     0054b472(j)  
    //         0054b485     PUSH       0x1
    //         0054b487     MOV        EAX,dword ptr [EBP + Stack[0x8]]
    //         0054b48a     MOV        ECX,dword ptr [EAX + 0x14]
    //         0054b48d     PUSH       ECX
    //         0054b48e     MOV        EDX,dword ptr [EBP + Stack[0x8]]
    //         0054b491     MOV        EAX,dword ptr [EDX + 0x10]
    //         0054b494     PUSH       EAX
    //         0054b495     MOV        ECX,dword ptr [EBP + Stack[0x8]]
    //         0054b498     MOV        EDX,dword ptr [ECX + 0x8]
    //         0054b49b     PUSH       EDX
    //         0054b49c     PUSH       0x0
    //         0054b49e     MOV        EAX,dword ptr [EBP + Stack[0xc]]
    //         0054b4a1     PUSH       EAX
    //         0054b4a2     MOV        ECX,dword ptr [EBP + Stack[0x8]]
    //         0054b4a5     MOV        EDX,dword ptr [ECX + 0xc]
    //         0054b4a8     PUSH       EDX
    //         0054b4a9     MOV        EAX,dword ptr [EBP + Stack[0x4]]
    //         0054b4ac     PUSH       EAX
    //         0054b4ad     CALL       ___InternalCxxFrameHandler                       undefined ___InternalCxxFrameHandler()
    //         0054b4b2     ADD        ESP,0x20
    //         0054b4b5     MOV        ECX,dword ptr [EBP + Stack[0x8]]
    //         0054b4b8     CMP        dword ptr [ECX + 0x24],0x0
    //         0054b4bc     JNZ        LAB_0054b4cb
    //         0054b4be     MOV        EDX,dword ptr [EBP + Stack[0x4]]
    //         0054b4c1     PUSH       EDX
    //         0054b4c2     MOV        EAX,dword ptr [EBP + Stack[0x8]]
    //         0054b4c5     PUSH       EAX
    //         0054b4c6     CALL       _UnwindNestedFrames                              void _UnwindNestedFrames(EHRegistrationNode *
    //                               LAB_0054b4cb                                                 XREF[1]:     0054b4bc(j)  
    //         0054b4cb     MOV        EBX,dword ptr [EBP + Stack[0x8]]
    //         0054b4ce     MOV        ESP,dword ptr [EBX + 0x1c]
    //         0054b4d1     MOV        EBP,dword ptr [EBX + 0x20]
    //         0054b4d4     JMP        dword ptr [EBX + 0x18]
}

// Offset: 0x0054B4D7
undefined FUN_0054b4d7() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0054b4d7()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0054b4d7
    //         0054b4d7     MOV        EAX,0x1
    //                               LAB_0054b4dc                                                 XREF[1]:     FUN_0054b460:0054b483(j)  
    //         0054b4dc     POP        EDI
    //         0054b4dd     POP        ESI
    //         0054b4de     POP        EBX
    //         0054b4df     POP        EBP
    //         0054b4e0     RET
}

// Offset: 0x0054B4F0
_s_TryBlockMapEntry* GetRangeOfTrysToCheck(_s_FuncInfo* param_1, int param_2, int param_3, uint* param_4, uint* param_5) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * struct _s_TryBlockMapEntry const * __cdecl _GetRangeOfTrysToCheck(struct _s_FuncInfo const *,int,i... *
    //                              *********************************************************************************************************
    //                              _s_TryBlockMapEntry * __cdecl _GetRangeOfTrysToCheck(_s_FuncInfo * p
    //              _s_TryBlockMap    EAX:4          <RETURN>
    //              _s_FuncInfo *     Stack[0x4]:4   param_1                   XREF[2]:     0054b4f1(R), 0054b540(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     0054b4f6(R)  
    //              int               Stack[0xc]:4   param_3                   XREF[1]:     0054b51e(R)  
    //              uint *            Stack[0x10]:4  param_4                   XREF[1]:     0054b544(R)  
    //              uint *            Stack[0x14]:4  param_5                   XREF[1]:     0054b548(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[3]:     0054b505(W), 0054b519(R), 0054b55f(R)  
    //                               ?_GetRangeOfTrysToCheck@@YAPBU_s_TryBlockMapEntry@@PBU_s_Fu  XREF[2]:     FUN_0054fb10:0054fbe6(c), 
    //                               _GetRangeOfTrysToCheck                                                    FUN_0054fdc0:0054fe11(c)  
    //         0054b4f0     PUSH       ECX
    //         0054b4f1     MOV        EAX,dword ptr [ESP + param_1]
    //         0054b4f5     PUSH       EBX
    //         0054b4f6     MOV        EBX,dword ptr [ESP + param_2]
    //         0054b4fa     PUSH       EBP
    //         0054b4fb     MOV        ECX,dword ptr [EAX + 0x10]
    //         0054b4fe     PUSH       ESI
    //         0054b4ff     MOV        ESI,dword ptr [EAX + 0xc]
    //         0054b502     PUSH       EDI
    //         0054b503     TEST       EBX,EBX
    //         0054b505     MOV        dword ptr [ESP + local_4],ECX
    //         0054b509     MOV        EBP,ESI
    //         0054b50b     MOV        EDI,ESI
    //         0054b50d     JL         LAB_0054b544
    //                               LAB_0054b50f                                                 XREF[1]:     0054b53e(j)  
    //         0054b50f     CMP        ESI,-0x1
    //         0054b512     JNZ        LAB_0054b519
    //         0054b514     CALL       _inconsistency                                   void _inconsistency(void)
    //                               LAB_0054b519                                                 XREF[1]:     0054b512(j)  
    //         0054b519     MOV        EAX,dword ptr [ESP + local_4]
    //         0054b51d     DEC        ESI
    //         0054b51e     MOV        ECX,dword ptr [ESP + param_3]
    //         0054b522     LEA        EDX,[ESI + ESI*0x4]
    //         0054b525     LEA        EAX,[EAX + EDX*0x4]
    //         0054b528     CMP        dword ptr [EAX + 0x4],ECX
    //         0054b52b     JGE        LAB_0054b532
    //         0054b52d     CMP        ECX,dword ptr [EAX + 0x8]
    //         0054b530     JLE        LAB_0054b537
    //                               LAB_0054b532                                                 XREF[1]:     0054b52b(j)  
    //         0054b532     CMP        ESI,-0x1
    //         0054b535     JNZ        LAB_0054b53c
    //                               LAB_0054b537                                                 XREF[1]:     0054b530(j)  
    //         0054b537     MOV        EBP,EDI
    //         0054b539     DEC        EBX
    //         0054b53a     MOV        EDI,ESI
    //                               LAB_0054b53c                                                 XREF[1]:     0054b535(j)  
    //         0054b53c     TEST       EBX,EBX
    //         0054b53e     JGE        LAB_0054b50f
    //         0054b540     MOV        EAX,dword ptr [ESP + param_1]
    //                               LAB_0054b544                                                 XREF[1]:     0054b50d(j)  
    //         0054b544     MOV        ECX,dword ptr [ESP + param_4]
    //         0054b548     MOV        EDX,dword ptr [ESP + param_5]
    //         0054b54c     INC        ESI
    //         0054b54d     MOV        dword ptr [ECX],ESI
    //         0054b54f     MOV        dword ptr [EDX],EBP
    //         0054b551     CMP        EBP,dword ptr [EAX + 0xc]
    //         0054b554     JA         LAB_0054b55a
    //         0054b556     CMP        ESI,EBP
    //         0054b558     JBE        LAB_0054b55f
    //                               LAB_0054b55a                                                 XREF[1]:     0054b554(j)  
    //         0054b55a     CALL       _inconsistency                                   void _inconsistency(void)
    //                               LAB_0054b55f                                                 XREF[1]:     0054b558(j)  
    //         0054b55f     MOV        ECX,dword ptr [ESP + local_4]
    //         0054b563     LEA        EAX,[ESI + ESI*0x4]
    //         0054b566     POP        EDI
    //         0054b567     POP        ESI
    //         0054b568     POP        EBP
    //         0054b569     LEA        EAX,[ECX + EAX*0x4]
    //         0054b56c     POP        EBX
    //         0054b56d     POP        ECX
    //         0054b56e     RET
}

// Offset: 0x0054B570
undefined global_unwind2() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined __global_unwind2()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               __global_unwind2                                             XREF[1]:     FUN_00554dea:00554e52(c)  
    //         0054b570     PUSH       EBP
    //         0054b571     MOV        EBP,ESP
    //         0054b573     PUSH       EBX
    //         0054b574     PUSH       ESI
    //         0054b575     PUSH       EDI
    //         0054b576     PUSH       EBP
    //         0054b577     PUSH       0x0
    //         0054b579     PUSH       0x0
    //         0054b57b     PUSH       0x54b588
    //         0054b580     PUSH       dword ptr [EBP + Stack[0x4]]
    //         0054b583     CALL       _RtlUnwind@16                                    undefined _RtlUnwind@16()
    //         0054b588     POP        EBP
    //         0054b589     POP        EDI
    //         0054b58a     POP        ESI
    //         0054b58b     POP        EBX
    //         0054b58c     MOV        ESP,EBP
    //         0054b58e     POP        EBP
    //         0054b58f     RET
}

// Offset: 0x0054B590
undefined FUN_0054b590() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0054b590()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0054b590                                                 XREF[2]:     __local_unwind2:0054b5bc(*), 
    //                                                                                                         __abnormal_termination:0054b623(*)
    //         0054b590     MOV        ECX,dword ptr [ESP + Stack[0x4]]
    //         0054b594     TEST       dword ptr [ECX + 0x4],0x6
    //         0054b59b     MOV        EAX,0x1
    //         0054b5a0     JZ         LAB_0054b5b1
    //         0054b5a2     MOV        EAX,dword ptr [ESP + Stack[0x8]]
    //         0054b5a6     MOV        EDX,dword ptr [ESP + Stack[0x10]]
    //         0054b5aa     MOV        dword ptr [EDX],EAX
    //         0054b5ac     MOV        EAX,0x3
    //                               LAB_0054b5b1                                                 XREF[1]:     0054b5a0(j)  
    //         0054b5b1     RET
}

// Offset: 0x0054B5B2
undefined local_unwind2() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined __local_unwind2()
    //              undefined         <UNASSIGNED>   <RETURN>
    //              undefined4        Stack[-0x14]:4 local_14                  XREF[1]:     0054b5ea(W)  
    //                               __local_unwind2                                              XREF[4]:     FUN_005500b6:005500c6(c), 
    //                                                                                                         FUN_00554dea:00554e5f(c), 
    //                                                                                                         FUN_00554dea:00554e9f(c), 
    //                                                                                                         __seh_longjmp_unwind@4:00554ec4(c)
    //         0054b5b2     PUSH       EBX
    //         0054b5b3     PUSH       ESI
    //         0054b5b4     PUSH       EDI
    //         0054b5b5     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         0054b5b9     PUSH       EAX
    //         0054b5ba     PUSH       -0x2
    //         0054b5bc     PUSH       FUN_0054b590
    //         0054b5c1     PUSH       dword ptr FS:[0x0]
    //         0054b5c8     MOV        dword ptr FS:[0x0],ESP
    //                               LAB_0054b5cf                                                 XREF[1]:     0054b60a(j)  
    //         0054b5cf     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         0054b5d3     MOV        EBX,dword ptr [EAX + 0x8]
    //         0054b5d6     MOV        ESI,dword ptr [EAX + 0xc]
    //         0054b5d9     CMP        ESI,-0x1
    //         0054b5dc     JZ         LAB_0054b60c
    //         0054b5de     CMP        ESI,dword ptr [ESP + Stack[0x8]]
    //         0054b5e2     JZ         LAB_0054b60c
    //         0054b5e4     LEA        ESI,[ESI + ESI*0x2]
    //         0054b5e7     MOV        ECX,dword ptr [EBX + ESI*0x4]
    //         0054b5ea     MOV        dword ptr [ESP + local_14],ECX
    //         0054b5ee     MOV        dword ptr [EAX + 0xc],ECX
    //         0054b5f1     CMP        dword ptr [EBX + ESI*0x4 + 0x4],0x0
    //         0054b5f6     JNZ        __NLG_Return2
    //         0054b5f8     PUSH       0x101
    //         0054b5fd     MOV        EAX,dword ptr [EBX + ESI*0x4 + 0x8]
    //         0054b601     CALL       __NLG_Notify                                     undefined __NLG_Notify()
    //         0054b606     CALL       dword ptr [EBX + ESI*0x4 + 0x8]
    //                               __NLG_Return2                                                XREF[1]:     0054b5f6(j)  
    //         0054b60a     JMP        LAB_0054b5cf
    //                               LAB_0054b60c                                                 XREF[2]:     0054b5dc(j), 0054b5e2(j)  
    //         0054b60c     POP        dword ptr FS:[0x0]
    //         0054b613     ADD        ESP,0xc
    //         0054b616     POP        EDI
    //         0054b617     POP        ESI
    //         0054b618     POP        EBX
    //         0054b619     RET
}

// Offset: 0x0054B61A
undefined abnormal_termination() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined __abnormal_termination()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               __abnormal_termination                                       XREF[1]:     FUN_005500ea:00550124(c)  
    //         0054b61a     XOR        EAX,EAX
    //         0054b61c     MOV        ECX,dword ptr FS:[0x0]
    //         0054b623     CMP        dword ptr [ECX + 0x4],FUN_0054b590
    //         0054b62a     JNZ        LAB_0054b63c
    //         0054b62c     MOV        EDX,dword ptr [ECX + 0xc]
    //         0054b62f     MOV        EDX,dword ptr [EDX + 0xc]
    //         0054b632     CMP        dword ptr [ECX + 0x8],EDX
    //         0054b635     JNZ        LAB_0054b63c
    //         0054b637     MOV        EAX,0x1
    //                               LAB_0054b63c                                                 XREF[2]:     0054b62a(j), 0054b635(j)  
    //         0054b63c     RET
}

// Offset: 0x0054B63D
undefined NLG_Notify1() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined __NLG_Notify1()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               __NLG_Notify1                                                XREF[2]:     __CallSettingFrame@12:0055045e(c), 
    //                                                                                                         __CallSettingFrame@12:00550480(c)  
    //         0054b63d     PUSH       EBX
    //         0054b63e     PUSH       ECX
    //         0054b63f     MOV        EBX,__NLG_Destination                            = 20h     
    //         0054b644     JMP        LAB_0054b650
}

// Offset: 0x0054B646
undefined NLG_Notify() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined __NLG_Notify()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               __NLG_Notify                                                 XREF[2]:     __local_unwind2:0054b601(c), 
    //                                                                                                         FUN_00554dea:00554e70(c)  
    //         0054b646     PUSH       EBX
    //         0054b647     PUSH       ECX
    //         0054b648     MOV        EBX,__NLG_Destination                            = 20h     
    //         0054b64d     MOV        ECX,dword ptr [EBP + 0x8]
    //                               LAB_0054b650                                                 XREF[1]:     __NLG_Notify1:0054b644(j)  
    //         0054b650     MOV        dword ptr [EBX + 0x8]=>DAT_0058fb58,ECX
    //         0054b653     MOV        dword ptr [EBX + 0x4]=>DAT_0058fb54,EAX
    //         0054b656     MOV        dword ptr [EBX + 0xc]=>DAT_0058fb5c,EBP
    //                               __NLG_Dispatch
    //         0054b659     POP        ECX
    //         0054b65a     POP        EBX
    //         0054b65b     RET        0x4
}

// Offset: 0x0054B660
void operator_delete(void* param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * void __cdecl operator delete(void *)                                                                  *
    //                              *********************************************************************************************************
    //                              void __cdecl operator_delete(void * param_1)
    //              void              <VOID>         <RETURN>
    //              void *            Stack[0x4]:4   param_1                   XREF[1]:     0054b660(R)  
    //                               ??3@YAXPAX@Z                                                 XREF[836]:   save:0040d129(c), 
    //                               operator_delete                                                           ~AIPlayBook:00410208(c), 
    //                                                                                                         `vector_deleting_destructor':00426
    //                                                                                                         `vector_deleting_destructor':00426
    //                                                                                                         `vector_deleting_destructor':00426
    //                                                                                                         CommOut:0042b409(c), 
    //                                                                                                         CommOut:0042b830(c), 
    //                                                                                                         CommOut:0042b83d(c), 
    //                                                                                                         AllocateQueue:004319ad(c), 
    //                                                                                                         ~TDrawArea:00444016(c), 
    //                                                                                                         prepare_for_close:004672b9(c), 
    //                                                                                                         prepare_for_close:004672f8(c), 
    //                                                                                                         prepare_for_close:00467318(c), 
    //                                                                                                         prepare_for_close:00467369(c), 
    //                                                                                                         save:004d86b6(c), 
    //                                                                                                         save:004d8777(c), 
    //                                                                                                         save:004d8838(c), 
    //                                                                                                         save:004d88f9(c), 
    //                                                                                                         save:004d89ba(c), 
    //                                                                                                         save:004d8a7b(c), [more]
    //         0054b660     MOV        EAX,dword ptr [ESP + param_1]
    //         0054b664     PUSH       EAX
    //         0054b665     CALL       free                                             undefined free()
    //         0054b66a     ADD        ESP,0x4
    //         0054b66d     RET
}

// Offset: 0x0054B670
undefined fpmath() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined __fpmath()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               __fpmath                                                     XREF[2]:     __cinit:0054f689(c), 0058fb68(*)  
    //         0054b670     CALL       __cfltcvt_init                                   undefined __cfltcvt_init()
    //         0054b675     CALL       __ms_p5_mp_test_fdiv                             undefined __ms_p5_mp_test_fdiv()
    //         0054b67a     MOV        [__adjust_fdiv],EAX                              = align(40)
    //         0054b67f     CALL       __setdefaultprecision                            undefined __setdefaultprecision()
    //         0054b684     FNCLEX
    //         0054b686     RET
}

// Offset: 0x0054B687
undefined FUN_0054b687() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0054b687()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0054b687
    //         0054b687     NOP
    //         0054b688     NOP
    //         0054b689     NOP
    //         0054b68a     NOP
    //         0054b68b     NOP
    //         0054b68c     NOP
    //         0054b68d     NOP
    //         0054b68e     NOP
    //         0054b68f     NOP
    //                               __fpclear
    //         0054b690     RET
}

// Offset: 0x0054B6A0
undefined cfltcvt_init() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined __cfltcvt_init()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               __cfltcvt_init                                               XREF[1]:     __fpmath:0054b670(c)  
    //         0054b6a0     MOV        EAX,__cfltcvt
    //         0054b6a5     MOV        dword ptr [PTR___fptrap_0058fbcc],__cropzeros    = 00558110
    //         0054b6af     MOV        [__cfltcvt_tab],EAX                              = 00558110
    //         0054b6b4     MOV        dword ptr [PTR___fptrap_0058fbd0],__fassign      = 00558110
    //         0054b6be     MOV        dword ptr [PTR___fptrap_0058fbd4],__forcdecpt    = 00558110
    //         0054b6c8     MOV        dword ptr [PTR___fptrap_0058fbd8],__positive     = 00558110
    //         0054b6d2     MOV        [PTR___fptrap_0058fbdc],EAX                      = 00558110
    //         0054b6d7     RET
}

// Offset: 0x0054B6D8
undefined FUN_0054b6d8() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0054b6d8()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0054b6d8
    //         0054b6d8     NOP
    //         0054b6d9     NOP
    //         0054b6da     NOP
    //         0054b6db     NOP
    //         0054b6dc     NOP
    //         0054b6dd     NOP
    //         0054b6de     NOP
    //         0054b6df     NOP
    //                               ___setfflag
    //         0054b6e0     MOV        ECX,dword ptr [ESP + Stack[0x4]]
    //         0054b6e4     MOV        EAX,[___fastflag]                                = align(44)
    //         0054b6e9     MOV        dword ptr [___fastflag],ECX                      = align(44)
    //         0054b6ef     RET
}

// Offset: 0x0054B6F0
void* operator_new(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * void * __cdecl operator new(unsigned int)                                                             *
    //                              *********************************************************************************************************
    //                              void * __cdecl operator_new(uint param_1)
    //              void *            EAX:4          <RETURN>
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     0054b6f0(R)  
    //                               ??2@YAPAXI@Z                                                 XREF[992]:   save:0040d0eb(c), 
    //                               operator_new                                                              StoreForResend:0042a425(c), 
    //                                                                                                         CommOut:0042b2cc(c), 
    //                                                                                                         CommOut:0042b440(c), 
    //                                                                                                         AllocateQueue:00431852(c), 
    //                                                                                                         AllocateQueue:00431921(c), 
    //                                                                                                         AddItem:00431c68(c), 
    //                                                                                                         set_current_campaign:0044cfcd(c), 
    //                                                                                                         add_new_person:0044d76a(c), 
    //                                                                                                         setup_shadow_area:00467408(c), 
    //                                                                                                         action:004a7093(c), 
    //                                                                                                         action:004a7140(c), 
    //                                                                                                         shape_hit_test:004c0de4(c), 
    //                                                                                                         build:004cb6a5(c), 
    //                                                                                                         save:004d8675(c), 
    //                                                                                                         save:004d8736(c), 
    //                                                                                                         save:004d87f7(c), 
    //                                                                                                         save:004d88b8(c), 
    //                                                                                                         save:004d8979(c), 
    //                                                                                                         save:004d8a3a(c), [more]
    //         0054b6f0     MOV        EAX,dword ptr [ESP + param_1]
    //         0054b6f4     PUSH       0x1
    //         0054b6f6     PUSH       EAX
    //         0054b6f7     CALL       __nh_malloc                                      undefined __nh_malloc()
    //         0054b6fc     ADD        ESP,0x8
    //         0054b6ff     RET
}

// Offset: 0x0054B700
undefined ftol() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined __ftol()
    //              undefined         <UNASSIGNED>   <RETURN>
    //              undefined2        Stack[-0x6]:2  local_6                   XREF[3]:     0054b706(W), 0054b70b(R), 0054b71c(R)  
    //              undefined2        Stack[-0x8]:2  local_8                   XREF[2]:     0054b712(W), 0054b716(R)  
    //              undefined8        Stack[-0x10]:8 local_10                  XREF[2,1]:   0054b719(W), 0054b71f(R), 0054b722(R)  
    //                               __ftol                                                       XREF[1129]:  command_ai_order:00435e4f(c), 
    //                                                                                                         command_ai_order:00435e59(c), 
    //                                                                                                         check_terrain_and_zone:00485328(c)
    //                                                                                                         remove_visible_resource:004c5133(c
    //                                                                                                         remove_visible_resource:004c513d(c
    //                                                                                                         get_move_sprite:004cff3a(c), 
    //                                                                                                         resource:004e6c92(c), 
    //                                                                                                         tech_cost:0050c834(c), 
    //                                                                                                         tech_cost:0050c85b(c), 
    //                                                                                                         tech_cost:0050c8e8(c), 
    //                                                                                                         tech_cost:0050c90f(c), 
    //                                                                                                         tech_cost:0050c99b(c), 
    //                                                                                                         tech_cost:0050c9c2(c), 
    //                                                                                                         obj_cost:00512cd8(c), 
    //                                                                                                         obj_cost:00512d12(c), 
    //                                                                                                         obj_cost:00512d56(c), 
    //                                                                                                         obj_cost:00512d90(c), 
    //                                                                                                         obj_cost:00512dd1(c), 
    //                                                                                                         obj_cost:00512e08(c), 
    //                                                                                                         view_function:005360a0(c), [more]
    //         0054b700     PUSH       EBP
    //         0054b701     MOV        EBP,ESP
    //         0054b703     ADD        ESP,-0xc
    //         0054b706     FSTCW      word ptr [EBP + local_6]
    //         0054b70a     WAIT
    //         0054b70b     MOV        AX,word ptr [EBP + local_6]
    //         0054b70f     OR         AH,0xc
    //         0054b712     MOV        word ptr [EBP + local_8],AX
    //         0054b716     FLDCW      word ptr [EBP + local_8]
    //         0054b719     FISTP      qword ptr [EBP + local_10]
    //         0054b71c     FLDCW      word ptr [EBP + local_6]
    //         0054b71f     MOV        EAX,dword ptr [EBP + local_10]
    //         0054b722     MOV        EDX,dword ptr [EBP + local_10+0x4]
    //         0054b725     LEAVE
    //         0054b726     RET
}

// Offset: 0x0054B730
undefined calloc() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * calloc                                                                                                *
    //                              *********************************************************************************************************
    //                              undefined __cdecl calloc()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               _calloc                                                      XREF[316]:   command_ai_order:00435d9a(c), 
    //                               calloc                                                                    draw:00449ea9(c), 
    //                                                                                                         draw:00449eda(c), 
    //                                                                                                         RGE_Campaign_Info:0044c7e2(c), 
    //                                                                                                         set_current_campaign:0044cf80(c), 
    //                                                                                                         addstring:00462ddd(c), 
    //                                                                                                         sort:004632a8(c), 
    //                                                                                                         add_node:00471d84(c), 
    //                                                                                                         insert_line:0047dd7f(c), 
    //                                                                                                         insert_line:0047ddc4(c), 
    //                                                                                                         insert_line:0047ddfb(c), 
    //                                                                                                         rge_write:0048032b(c), 
    //                                                                                                         SetNumZones:004bd6a2(c), 
    //                                                                                                         SetNumZones:004bd6b3(c), 
    //                                                                                                         command_cancel_build:0050afd8(c), 
    //                                                                                                         zone_push:00546774(c), 
    //                                                                                                         RGE_Zone_Map:005468d9(c), 
    //                                                                                                         RGE_Zone_Map:00546913(c), 
    //                                                                                                         RGE_Zone_Map:0054697e(c), 
    //                                                                                                         get_zone_map:00547400(c), [more]
    //         0054b730     PUSH       EBX
    //         0054b731     PUSH       EBP
    //         0054b732     PUSH       ESI
    //         0054b733     MOV        ESI,dword ptr [ESP + Stack[0x8]]
    //         0054b737     IMUL       ESI,dword ptr [ESP + Stack[0x4]]
    //         0054b73c     CMP        ESI,-0x20
    //         0054b73f     PUSH       EDI
    //         0054b740     JA         LAB_0054b753
    //         0054b742     TEST       ESI,ESI
    //         0054b744     JBE        LAB_0054b74e
    //         0054b746     ADD        ESI,0xf
    //         0054b749     AND        ESI,0xfffffff0
    //         0054b74c     JMP        LAB_0054b753
    //                               LAB_0054b74e                                                 XREF[1]:     0054b744(j)  
    //         0054b74e     MOV        ESI,0x10
    //                               LAB_0054b753                                                 XREF[2]:     0054b740(j), 0054b74c(j)  
    //         0054b753     MOV        EBX,dword ptr [->KERNEL32.DLL::HeapAlloc]        = 0048b6ac
    //                               LAB_0054b759                                                 XREF[1]:     0054b7ba(j)  
    //         0054b759     XOR        EDX,EDX
    //         0054b75b     CMP        ESI,-0x20
    //         0054b75e     JA         LAB_0054b7a2
    //         0054b760     CMP        ESI,dword ptr [___sbh_threshold]                 = 000001E0h
    //         0054b766     JA         LAB_0054b790
    //         0054b768     MOV        EAX,ESI
    //         0054b76a     SHR        EAX,0x4
    //         0054b76d     PUSH       EAX
    //         0054b76e     CALL       ___sbh_alloc_block                               undefined ___sbh_alloc_block()
    //         0054b773     MOV        EDX,EAX
    //         0054b775     ADD        ESP,0x4
    //         0054b778     TEST       EDX,EDX
    //         0054b77a     JZ         LAB_0054b794
    //         0054b77c     MOV        ECX,ESI
    //         0054b77e     XOR        EAX,EAX
    //         0054b780     MOV        EBP,ECX
    //         0054b782     MOV        EDI,EDX
    //         0054b784     SHR        ECX,0x2
    //         0054b787     STOSD.REP  ES:EDI
    //         0054b789     MOV        ECX,EBP
    //         0054b78b     AND        ECX,0x3
    //         0054b78e     STOSB.REP  ES:EDI
    //                               LAB_0054b790                                                 XREF[1]:     0054b766(j)  
    //         0054b790     TEST       EDX,EDX
    //         0054b792     JNZ        LAB_0054b7c1
    //                               LAB_0054b794                                                 XREF[1]:     0054b77a(j)  
    //         0054b794     MOV        ECX,dword ptr [__crtheap]
    //         0054b79a     PUSH       ESI
    //         0054b79b     PUSH       0x8
    //         0054b79d     PUSH       ECX
    //         0054b79e     CALL       EBX=>KERNEL32.DLL::HeapAlloc
    //         0054b7a0     MOV        EDX,EAX
    //                               LAB_0054b7a2                                                 XREF[1]:     0054b75e(j)  
    //         0054b7a2     TEST       EDX,EDX
    //         0054b7a4     JNZ        LAB_0054b7c1
    //         0054b7a6     MOV        EAX,[__newmode]
    //         0054b7ab     TEST       EAX,EAX
    //         0054b7ad     JZ         LAB_0054b7c1
    //         0054b7af     PUSH       ESI
    //         0054b7b0     CALL       __callnewh                                       undefined __callnewh()
    //         0054b7b5     ADD        ESP,0x4
    //         0054b7b8     TEST       EAX,EAX
    //         0054b7ba     JNZ        LAB_0054b759
    //         0054b7bc     POP        EDI
    //         0054b7bd     POP        ESI
    //         0054b7be     POP        EBP
    //         0054b7bf     POP        EBX
    //         0054b7c0     RET
    //                               LAB_0054b7c1                                                 XREF[3]:     0054b792(j), 0054b7a4(j), 
    //                                                                                                         0054b7ad(j)  
    //         0054b7c1     POP        EDI
    //         0054b7c2     POP        ESI
    //         0054b7c3     POP        EBP
    //         0054b7c4     MOV        EAX,EDX
    //         0054b7c6     POP        EBX
    //         0054b7c7     RET
}

// Offset: 0x0054B7D0
undefined free() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * free                                                                                                  *
    //                              *********************************************************************************************************
    //                              undefined __cdecl free()
    //              undefined         <UNASSIGNED>   <RETURN>
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     0054b7de(*), 0054b7f6(R)  
    //                               _free                                                        XREF[382]:   submit:004352ea(c), 
    //                               free                                                                      ~TDrawArea:00443f5c(c), 
    //                                                                                                         ~TDrawArea:00443fd6(c), 
    //                                                                                                         ~TDrawArea:00443fe9(c), 
    //                                                                                                         ~TDrawArea:00443ffc(c), 
    //                                                                                                         ~TDrawArea:00444029(c), 
    //                                                                                                         removePanel:00463e49(c), 
    //                                                                                                         ~TPanel:00464a2e(c), 
    //                                                                                                         ~TPanel:00464a75(c), 
    //                                                                                                         add_node:00471daa(c), 
    //                                                                                                         ~TShape:004b8de4(c), 
    //                                                                                                         ~TShape:004b8e0e(c), 
    //                                                                                                         ~TSpan_Node_List:004bd657(c), 
    //                                                                                                         ~TSpan_Node_List:004bd66e(c), 
    //                                                                                                         ~TSpan_Node_List:004bd67e(c), 
    //                                                                                                         ~TSpan_List_Manager:004bd9ab(c), 
    //                                                                                                         ~TSpan_List_Manager:004bd9bb(c), 
    //                                                                                                         ~TSpan_List_Manager:004bd9cb(c), 
    //                                                                                                         ~TSpan_List_Manager:004bd9db(c), 
    //                                                                                                         ~TSpan_List_Manager:004bd9eb(c), 
    //                                                                                                         [more]
    //         0054b7d0     PUSH       ECX
    //         0054b7d1     PUSH       ESI
    //         0054b7d2     MOV        ESI,dword ptr [ESP + Stack[0x4]]
    //         0054b7d6     TEST       ESI,ESI
    //         0054b7d8     JZ         LAB_0054b817
    //         0054b7da     LEA        EAX=>Stack[0x4],[ESP + 0xc]
    //         0054b7de     LEA        ECX=>local_4,[ESP + 0x4]
    //         0054b7e2     PUSH       EAX
    //         0054b7e3     PUSH       ECX
    //         0054b7e4     PUSH       ESI
    //         0054b7e5     CALL       ___sbh_find_block                                undefined ___sbh_find_block()
    //         0054b7ea     ADD        ESP,0xc
    //         0054b7ed     TEST       EAX,EAX
    //         0054b7ef     JZ         LAB_0054b807
    //         0054b7f1     MOV        EDX,dword ptr [ESP + Stack[0x4]]
    //         0054b7f5     PUSH       EAX
    //         0054b7f6     MOV        EAX,dword ptr [ESP + local_4]
    //         0054b7fa     PUSH       EDX
    //         0054b7fb     PUSH       EAX
    //         0054b7fc     CALL       ___sbh_free_block                                undefined ___sbh_free_block()
    //         0054b801     ADD        ESP,0xc
    //         0054b804     POP        ESI
    //         0054b805     POP        ECX
    //         0054b806     RET
    //                               LAB_0054b807                                                 XREF[1]:     0054b7ef(j)  
    //         0054b807     MOV        ECX,dword ptr [__crtheap]
    //         0054b80d     PUSH       ESI
    //         0054b80e     PUSH       0x0
    //         0054b810     PUSH       ECX
    //         0054b811     CALL       dword ptr [->KERNEL32.DLL::HeapFree]             = 0048b6b8
    //                               LAB_0054b817                                                 XREF[1]:     0054b7d8(j)  
    //         0054b817     POP        ESI
    //         0054b818     POP        ECX
    //         0054b819     RET
}

// Offset: 0x0054B820
undefined fprintf() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * fprintf                                                                                               *
    //                              *********************************************************************************************************
    //                              undefined __cdecl fprintf()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               _fprintf                                                     XREF[199]:   logCommonHistory:0040e89c(c), 
    //                               fprintf                                                                   logCommonHistory:0040e8b6(c), 
    //                                                                                                         write_draw_log:0041b634(c), 
    //                                                                                                         write_draw_log2:0041b664(c), 
    //                                                                                                         remove_doppleganger_check:004422db
    //                                                                                                         logDebug:004c739a(c), 
    //                                                                                                         logDebug:004c73e4(c), 
    //                                                                                                         logDebug:004c7404(c), 
    //                                                                                                         run_log:005210d3(c), 
    //                                                                                                         run_log:005210fa(c), 
    //                                                                                                         logStatus:0052e0dd(c), 
    //                                                                                                         logStatus:0052e10f(c), 
    //                                                                                                         logStatus:0052e123(c), 
    //                                                                                                         logStatus:0052e14d(c), 
    //                                                                                                         logStatus:0052e191(c), 
    //                                                                                                         logStatus:0052e1ca(c), 
    //                                                                                                         logStatus:0052e203(c), 
    //                                                                                                         update_mutual_allies:005462e9(c), 
    //                                                                                                         update_mutual_allies:0054652c(c), 
    //                                                                                                         update_mutual_allies:0054655b(c), 
    //                                                                                                         [more]
    //         0054b820     PUSH       EBX
    //         0054b821     PUSH       ESI
    //         0054b822     MOV        ESI,dword ptr [ESP + Stack[0x4]]
    //         0054b826     PUSH       EDI
    //         0054b827     PUSH       ESI
    //         0054b828     CALL       __stbuf                                          undefined __stbuf()
    //         0054b82d     MOV        ECX,dword ptr [ESP + Stack[0x8]]
    //         0054b831     ADD        ESP,0x4
    //         0054b834     MOV        EDI,EAX
    //         0054b836     LEA        EAX=>Stack[0xc],[ESP + 0x18]
    //         0054b83a     PUSH       EAX
    //         0054b83b     PUSH       ECX
    //         0054b83c     PUSH       ESI
    //         0054b83d     CALL       __output                                         undefined __output()
    //         0054b842     ADD        ESP,0xc
    //         0054b845     MOV        EBX,EAX
    //         0054b847     PUSH       ESI
    //         0054b848     PUSH       EDI
    //         0054b849     CALL       __ftbuf                                          undefined __ftbuf()
    //         0054b84e     ADD        ESP,0x8
    //         0054b851     MOV        EAX,EBX
    //         0054b853     POP        EDI
    //         0054b854     POP        ESI
    //         0054b855     POP        EBX
    //         0054b856     RET
}

// Offset: 0x0054B860
undefined strncpy() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * strncpy                                                                                               *
    //                              *********************************************************************************************************
    //                              undefined __cdecl strncpy()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               _strncpy                                                     XREF[64]:    BaseItem:00407e5a(c), 
    //                               strncpy                                                                   loadConstructionPlan:0040b703(c), 
    //                                                                                                         setScenarioName:004226e4(c), 
    //                                                                                                         check_prog_argument:00422cd9(c), 
    //                                                                                                         set_text:004723cc(c), 
    //                                                                                                         set_text:004759b9(c), 
    //                                                                                                         show_message:0047932d(c), 
    //                                                                                                         insert_line:0047de4b(c), 
    //                                                                                                         fillList:004a7733(c), 
    //                                                                                                         fillList:004a7803(c), 
    //                                                                                                         MakeFileList:004b2b6e(c), 
    //                                                                                                         fillList:004b37c9(c), 
    //                                                                                                         fillList:004b3860(c), 
    //                                                                                                         TDigital:004bcc64(c), 
    //                                                                                                         load:004bcdbf(c), 
    //                                                                                                         get_info:004d1669(c), 
    //                                                                                                         get_info:004d2645(c), 
    //                                                                                                         set_text_msg:00519ec2(c), 
    //                                                                                                         __tzset:00553726(c), 
    //                                                                                                         __tzset:00553807(c), [more]
    //         0054b860     MOV        ECX,dword ptr [ESP + Stack[0xc]]
    //         0054b864     PUSH       EDI
    //         0054b865     TEST       ECX,ECX
    //         0054b867     JZ         LAB_0054b8e3
    //         0054b869     PUSH       ESI
    //         0054b86a     PUSH       EBX
    //         0054b86b     MOV        EBX,ECX
    //         0054b86d     MOV        ESI,dword ptr [ESP + Stack[0x8]]
    //         0054b871     TEST       ESI,0x3
    //         0054b877     MOV        EDI,dword ptr [ESP + Stack[0x4]]
    //         0054b87b     JNZ        LAB_0054b884
    //         0054b87d     SHR        ECX,0x2
    //         0054b880     JNZ        LAB_0054b8f1
    //         0054b882     JMP        LAB_0054b8a5
    //                               LAB_0054b884                                                 XREF[2]:     0054b87b(j), 0054b897(j)  
    //         0054b884     MOV        AL,byte ptr [ESI]
    //         0054b886     INC        ESI
    //         0054b887     MOV        byte ptr [EDI],AL
    //         0054b889     INC        EDI
    //         0054b88a     DEC        ECX
    //         0054b88b     JZ         LAB_0054b8b2
    //         0054b88d     TEST       AL,AL
    //         0054b88f     JZ         LAB_0054b8ba
    //         0054b891     TEST       ESI,0x3
    //         0054b897     JNZ        LAB_0054b884
    //         0054b899     MOV        EBX,ECX
    //         0054b89b     SHR        ECX,0x2
    //         0054b89e     JNZ        LAB_0054b8f1
    //                               LAB_0054b8a0                                                 XREF[1]:     0054b8ef(j)  
    //         0054b8a0     AND        EBX,0x3
    //         0054b8a3     JZ         LAB_0054b8b2
    //                               LAB_0054b8a5                                                 XREF[2]:     0054b882(j), 0054b8b0(j)  
    //         0054b8a5     MOV        AL,byte ptr [ESI]
    //         0054b8a7     INC        ESI
    //         0054b8a8     MOV        byte ptr [EDI],AL
    //         0054b8aa     INC        EDI
    //         0054b8ab     TEST       AL,AL
    //         0054b8ad     JZ         LAB_0054b8de
    //         0054b8af     DEC        EBX
    //         0054b8b0     JNZ        LAB_0054b8a5
    //                               LAB_0054b8b2                                                 XREF[2]:     0054b88b(j), 0054b8a3(j)  
    //         0054b8b2     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         0054b8b6     POP        EBX
    //         0054b8b7     POP        ESI
    //         0054b8b8     POP        EDI
    //         0054b8b9     RET
    //                               LAB_0054b8ba                                                 XREF[1]:     0054b88f(j)  
    //         0054b8ba     TEST       EDI,0x3
    //         0054b8c0     JZ         LAB_0054b8d4
    //                               LAB_0054b8c2                                                 XREF[1]:     0054b8d2(j)  
    //         0054b8c2     MOV        byte ptr [EDI],AL
    //         0054b8c4     INC        EDI
    //         0054b8c5     DEC        ECX
    //         0054b8c6     JZ         LAB_0054b956
    //         0054b8cc     TEST       EDI,0x3
    //         0054b8d2     JNZ        LAB_0054b8c2
    //                               LAB_0054b8d4                                                 XREF[1]:     0054b8c0(j)  
    //         0054b8d4     MOV        EBX,ECX
    //         0054b8d6     SHR        ECX,0x2
    //         0054b8d9     JNZ        LAB_0054b947
    //                               LAB_0054b8db                                                 XREF[2]:     0054b8df(j), 0054b954(j)  
    //         0054b8db     MOV        byte ptr [EDI],AL
    //         0054b8dd     INC        EDI
    //                               LAB_0054b8de                                                 XREF[1]:     0054b8ad(j)  
    //         0054b8de     DEC        EBX
    //         0054b8df     JNZ        LAB_0054b8db
    //         0054b8e1     POP        EBX
    //         0054b8e2     POP        ESI
    //                               LAB_0054b8e3                                                 XREF[1]:     0054b867(j)  
    //         0054b8e3     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         0054b8e7     POP        EDI
    //         0054b8e8     RET
    //                               LAB_0054b8e9                                                 XREF[2]:     0054b909(j), 0054b921(j)  
    //         0054b8e9     MOV        dword ptr [EDI],EDX
    //         0054b8eb     ADD        EDI,0x4
    //         0054b8ee     DEC        ECX
    //         0054b8ef     JZ         LAB_0054b8a0
    //                               LAB_0054b8f1                                                 XREF[2]:     0054b880(j), 0054b89e(j)  
    //         0054b8f1     MOV        EDX,0x7efefeff
    //         0054b8f6     MOV        EAX,dword ptr [ESI]
    //         0054b8f8     ADD        EDX,EAX
    //         0054b8fa     XOR        EAX,0xffffffff
    //         0054b8fd     XOR        EAX,EDX
    //         0054b8ff     MOV        EDX,dword ptr [ESI]
    //         0054b901     ADD        ESI,0x4
    //         0054b904     TEST       EAX,0x81010100
    //         0054b909     JZ         LAB_0054b8e9
    //         0054b90b     TEST       DL,DL
    //         0054b90d     JZ         LAB_0054b93b
    //         0054b90f     TEST       DH,DH
    //         0054b911     JZ         LAB_0054b931
    //         0054b913     TEST       EDX,0xff0000
    //         0054b919     JZ         LAB_0054b927
    //         0054b91b     TEST       EDX,0xff000000
    //         0054b921     JNZ        LAB_0054b8e9
    //         0054b923     MOV        dword ptr [EDI],EDX
    //         0054b925     JMP        LAB_0054b93f
    //                               LAB_0054b927                                                 XREF[1]:     0054b919(j)  
    //         0054b927     AND        EDX,0xffff
    //         0054b92d     MOV        dword ptr [EDI],EDX
    //         0054b92f     JMP        LAB_0054b93f
    //                               LAB_0054b931                                                 XREF[1]:     0054b911(j)  
    //         0054b931     AND        EDX,0xff
    //         0054b937     MOV        dword ptr [EDI],EDX
    //         0054b939     JMP        LAB_0054b93f
    //                               LAB_0054b93b                                                 XREF[1]:     0054b90d(j)  
    //         0054b93b     XOR        EDX,EDX
    //         0054b93d     MOV        dword ptr [EDI],EDX
    //                               LAB_0054b93f                                                 XREF[3]:     0054b925(j), 0054b92f(j), 
    //                                                                                                         0054b939(j)  
    //         0054b93f     ADD        EDI,0x4
    //         0054b942     XOR        EAX,EAX
    //         0054b944     DEC        ECX
    //         0054b945     JZ         LAB_0054b951
    //                               LAB_0054b947                                                 XREF[1]:     0054b8d9(j)  
    //         0054b947     XOR        EAX,EAX
    //                               LAB_0054b949                                                 XREF[1]:     0054b94f(j)  
    //         0054b949     MOV        dword ptr [EDI],EAX
    //         0054b94b     ADD        EDI,0x4
    //         0054b94e     DEC        ECX
    //         0054b94f     JNZ        LAB_0054b949
    //                               LAB_0054b951                                                 XREF[1]:     0054b945(j)  
    //         0054b951     AND        EBX,0x3
    //         0054b954     JNZ        LAB_0054b8db
    //                               LAB_0054b956                                                 XREF[1]:     0054b8c6(j)  
    //         0054b956     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         0054b95a     POP        EBX
    //         0054b95b     POP        ESI
    //         0054b95c     POP        EDI
    //         0054b95d     RET
}

// Offset: 0x0054B960
undefined remove() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * remove                                                                                                *
    //                              *********************************************************************************************************
    //                              undefined __cdecl remove()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               _remove                                                      XREF[1]:     __unlink:0054b995(c)  
    //                               remove
    //         0054b960     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         0054b964     PUSH       EAX
    //         0054b965     CALL       dword ptr [->KERNEL32.DLL::DeleteFileA]          = 0048b6c4
    //         0054b96b     TEST       EAX,EAX
    //         0054b96d     JNZ        LAB_0054b977
    //         0054b96f     CALL       dword ptr [->KERNEL32.DLL::GetLastError]         = 0048aa76
    //         0054b975     JMP        LAB_0054b979
    //                               LAB_0054b977                                                 XREF[1]:     0054b96d(j)  
    //         0054b977     XOR        EAX,EAX
    //                               LAB_0054b979                                                 XREF[1]:     0054b975(j)  
    //         0054b979     TEST       EAX,EAX
    //         0054b97b     JZ         LAB_0054b98a
    //         0054b97d     PUSH       EAX
    //         0054b97e     CALL       __dosmaperr                                      undefined __dosmaperr()
    //         0054b983     ADD        ESP,0x4
    //         0054b986     OR         EAX,0xffffffff
    //         0054b989     RET
    //                               LAB_0054b98a                                                 XREF[1]:     0054b97b(j)  
    //         0054b98a     XOR        EAX,EAX
    //         0054b98c     RET
}

// Offset: 0x0054B990
undefined unlink() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined __unlink()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               __unlink                                                     XREF[18]:    loadBuildList:004097c5(c), 
    //                                                                                                         loadConstructionPlan:0040b90d(c), 
    //                                                                                                         loadTechnologyTree:00411d9f(c), 
    //                                                                                                         Load:0046e13e(c), 
    //                                                                                                         action:0049e3b3(c), 
    //                                                                                                         action:0049e3ed(c), 
    //                                                                                                         action:004a7940(c), 
    //                                                                                                         action:004a799f(c), 
    //                                                                                                         action:004a7ed8(c), 
    //                                                                                                         action:004a7f67(c), 
    //                                                                                                         action:004a7ff3(c), 
    //                                                                                                         action:004b3973(c), 
    //                                                                                                         action:004b39ad(c), 
    //                                                                                                         loadRules:004d6a69(c), 
    //                                                                                                         loadRules:004e75a1(c), 
    //                                                                                                         save_game:00543815(c), 
    //                                                                                                         save_scenario:00543a6c(c), 
    //                                                                                                         save_scenario:00543dc7(c)  
    //         0054b990     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         0054b994     PUSH       EAX
    //         0054b995     CALL       remove                                           undefined remove()
    //         0054b99a     ADD        ESP,0x4
    //         0054b99d     RET
}

// Offset: 0x0054B9A0
undefined strstr() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * strstr                                                                                                *
    //                              *********************************************************************************************************
    //                              undefined __cdecl strstr()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               _strstr                                                      XREF[148]:   loadBuildList:004097b8(c), 
    //                               strstr                                                                    loadConstructionPlan:0040b900(c), 
    //                                                                                                         loadTechnologyTree:00411d92(c), 
    //                                                                                                         setup_cmd_options:0041d0e5(c), 
    //                                                                                                         setup_cmd_options:0041d100(c), 
    //                                                                                                         setup_cmd_options:0041d116(c), 
    //                                                                                                         setup_cmd_options:0041d135(c), 
    //                                                                                                         setup_cmd_options:0041d14b(c), 
    //                                                                                                         setup_cmd_options:0041d161(c), 
    //                                                                                                         make_font:0041fb64(c), 
    //                                                                                                         make_font:0041fb7a(c), 
    //                                                                                                         check_prog_argument:00422d01(c), 
    //                                                                                                         contains:00446d8d(c), 
    //                                                                                                         contains:00446de8(c), 
    //                                                                                                         TRIBE_Screen_Sed:004a85e4(c), 
    //                                                                                                         TRIBE_Screen_Sed:004a85f6(c), 
    //                                                                                                         loadRules:004e7594(c), 
    //                                                                                                         setup:005217cd(c), 
    //                                                                                                         setup:005217e8(c), 
    //                                                                                                         setup:00521803(c), [more]
    //         0054b9a0     MOV        ECX,dword ptr [ESP + Stack[0x8]]
    //         0054b9a4     PUSH       EDI
    //         0054b9a5     PUSH       EBX
    //         0054b9a6     PUSH       ESI
    //         0054b9a7     MOV        DL,byte ptr [ECX]
    //         0054b9a9     MOV        EDI,dword ptr [ESP + Stack[0x4]]
    //         0054b9ad     TEST       DL,DL
    //         0054b9af     JZ         LAB_0054ba1a
    //         0054b9b1     MOV        DH,byte ptr [ECX + 0x1]
    //         0054b9b4     TEST       DH,DH
    //         0054b9b6     JZ         LAB_0054ba07
    //                               LAB_0054b9b8                                                 XREF[2]:     0054b9f2(j), 0054ba05(j)  
    //         0054b9b8     MOV        ESI,EDI
    //         0054b9ba     MOV        ECX,dword ptr [ESP + Stack[0x8]]
    //         0054b9be     MOV        AL,byte ptr [EDI]
    //         0054b9c0     INC        ESI
    //         0054b9c1     CMP        AL,DL
    //         0054b9c3     JZ         LAB_0054b9da
    //         0054b9c5     TEST       AL,AL
    //         0054b9c7     JZ         LAB_0054b9d4
    //                               LAB_0054b9c9                                                 XREF[1]:     0054b9d2(j)  
    //         0054b9c9     MOV        AL,byte ptr [ESI]
    //         0054b9cb     INC        ESI
    //                               LAB_0054b9cc                                                 XREF[1]:     0054b9df(j)  
    //         0054b9cc     CMP        AL,DL
    //         0054b9ce     JZ         LAB_0054b9da
    //         0054b9d0     TEST       AL,AL
    //         0054b9d2     JNZ        LAB_0054b9c9
    //                               LAB_0054b9d4                                                 XREF[1]:     0054b9c7(j)  
    //         0054b9d4     POP        ESI
    //         0054b9d5     POP        EBX
    //         0054b9d6     POP        EDI
    //         0054b9d7     XOR        EAX,EAX
    //         0054b9d9     RET
    //                               LAB_0054b9da                                                 XREF[2]:     0054b9c3(j), 0054b9ce(j)  
    //         0054b9da     MOV        AL,byte ptr [ESI]
    //         0054b9dc     INC        ESI
    //         0054b9dd     CMP        AL,DH
    //         0054b9df     JNZ        LAB_0054b9cc
    //         0054b9e1     LEA        EDI,[ESI + -0x1]
    //                               LAB_0054b9e4                                                 XREF[1]:     0054ba03(j)  
    //         0054b9e4     MOV        AH,byte ptr [ECX + 0x2]
    //         0054b9e7     TEST       AH,AH
    //         0054b9e9     JZ         LAB_0054ba13
    //         0054b9eb     MOV        AL,byte ptr [ESI]
    //         0054b9ed     ADD        ESI,0x2
    //         0054b9f0     CMP        AL,AH
    //         0054b9f2     JNZ        LAB_0054b9b8
    //         0054b9f4     MOV        AL,byte ptr [ECX + 0x3]
    //         0054b9f7     TEST       AL,AL
    //         0054b9f9     JZ         LAB_0054ba13
    //         0054b9fb     MOV        AH,byte ptr [ESI + -0x1]
    //         0054b9fe     ADD        ECX,0x2
    //         0054ba01     CMP        AL,AH
    //         0054ba03     JZ         LAB_0054b9e4
    //         0054ba05     JMP        LAB_0054b9b8
    //                               LAB_0054ba07                                                 XREF[1]:     0054b9b6(j)  
    //         0054ba07     XOR        EAX,EAX
    //         0054ba09     POP        ESI
    //         0054ba0a     POP        EBX
    //         0054ba0b     POP        EDI
    //         0054ba0c     MOV        AL,DL
    //         0054ba0e     JMP        ___from_strstr_to_strchr
    //                               LAB_0054ba13                                                 XREF[2]:     0054b9e9(j), 0054b9f9(j)  
    //         0054ba13     LEA        EAX,[EDI + -0x1]
    //         0054ba16     POP        ESI
    //         0054ba17     POP        EBX
    //         0054ba18     POP        EDI
    //         0054ba19     RET
    //                               LAB_0054ba1a                                                 XREF[1]:     0054b9af(j)  
    //         0054ba1a     MOV        EAX,EDI
    //         0054ba1c     POP        ESI
    //         0054ba1d     POP        EBX
    //         0054ba1e     POP        EDI
    //         0054ba1f     RET
}

// Offset: 0x0054BA20
undefined fclose() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * fclose                                                                                                *
    //                              *********************************************************************************************************
    //                              undefined __cdecl fclose()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               _fclose                                                      XREF[57]:    loadConstructionPlan:0040b8f2(c), 
    //                               fclose                                                                    ~AIModule:0040e37d(c), 
    //                                                                                                         setLogCommonHistory:0040e59f(c), 
    //                                                                                                         write_draw_log2:0041b673(c), 
    //                                                                                                         debug_random_write:00423083(c), 
    //                                                                                                         LogChecksums:00433a76(c), 
    //                                                                                                         ~RGE_Doppleganger_Creator:004421cd
    //                                                                                                         load_terrain_types:00458268(c), 
    //                                                                                                         load_border_types:004585e5(c), 
    //                                                                                                         Load:0046e122(c), 
    //                                                                                                         RESFILE_build_res_file:0047f932(c)
    //                                                                                                         RGE_RMM_Database_Controller:00482c
    //                                                                                                         RGE_RMM_Database_Controller:00482c
    //                                                                                                         RGE_RMM_Database_Controller:00482d
    //                                                                                                         RGE_RMM_Database_Controller:00482e
    //                                                                                                         RGE_RMM_Database_Controller:00482f
    //                                                                                                         run_log:005210e2(c), 
    //                                                                                                         run_log:00521109(c), 
    //                                                                                                         load_game:00526d9b(c), 
    //                                                                                                         dump_vismap_log:0053d230(c), [more]
    //         0054ba20     PUSH       ESI
    //         0054ba21     MOV        ESI,dword ptr [ESP + Stack[0x4]]
    //         0054ba25     PUSH       EDI
    //         0054ba26     OR         EDI,0xffffffff
    //         0054ba29     MOV        EAX,dword ptr [ESI + 0xc]
    //         0054ba2c     TEST       AL,0x40
    //         0054ba2e     JZ         LAB_0054ba3d
    //         0054ba30     MOV        dword ptr [ESI + 0xc],0x0
    //         0054ba37     OR         EAX,0xffffffff
    //         0054ba3a     POP        EDI
    //         0054ba3b     POP        ESI
    //         0054ba3c     RET
    //                               LAB_0054ba3d                                                 XREF[1]:     0054ba2e(j)  
    //         0054ba3d     TEST       AL,0x83
    //         0054ba3f     JZ         LAB_0054ba8b
    //         0054ba41     PUSH       ESI
    //         0054ba42     CALL       __flush                                          undefined __flush()
    //         0054ba47     ADD        ESP,0x4
    //         0054ba4a     MOV        EDI,EAX
    //         0054ba4c     PUSH       ESI
    //         0054ba4d     CALL       __freebuf                                        undefined __freebuf()
    //         0054ba52     MOV        EAX,dword ptr [ESI + 0x10]
    //         0054ba55     ADD        ESP,0x4
    //         0054ba58     PUSH       EAX
    //         0054ba59     CALL       close                                            undefined close()
    //         0054ba5e     ADD        ESP,0x4
    //         0054ba61     TEST       EAX,EAX
    //         0054ba63     JGE        LAB_0054ba74
    //         0054ba65     OR         EDI,0xffffffff
    //         0054ba68     MOV        dword ptr [ESI + 0xc],0x0
    //         0054ba6f     MOV        EAX,EDI
    //         0054ba71     POP        EDI
    //         0054ba72     POP        ESI
    //         0054ba73     RET
    //                               LAB_0054ba74                                                 XREF[1]:     0054ba63(j)  
    //         0054ba74     MOV        EAX,dword ptr [ESI + 0x1c]
    //         0054ba77     TEST       EAX,EAX
    //         0054ba79     JZ         LAB_0054ba8b
    //         0054ba7b     PUSH       EAX
    //         0054ba7c     CALL       free                                             undefined free()
    //         0054ba81     ADD        ESP,0x4
    //         0054ba84     MOV        dword ptr [ESI + 0x1c],0x0
    //                               LAB_0054ba8b                                                 XREF[2]:     0054ba3f(j), 0054ba79(j)  
    //         0054ba8b     MOV        EAX,EDI
    //         0054ba8d     MOV        dword ptr [ESI + 0xc],0x0
    //         0054ba94     POP        EDI
    //         0054ba95     POP        ESI
    //         0054ba96     RET
}

// Offset: 0x0054BAA0
undefined sscanf() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * sscanf                                                                                                *
    //                              *********************************************************************************************************
    //                              undefined __cdecl sscanf()
    //              undefined         <UNASSIGNED>   <RETURN>
    //              undefined4        Stack[-0x14]:4 local_14                  XREF[1]:     0054bacd(W)  
    //              undefined4        Stack[-0x18]:4 local_18                  XREF[1]:     0054baad(W)  
    //              undefined4        Stack[-0x1c]:4 local_1c                  XREF[1]:     0054babe(W)  
    //              undefined4        Stack[-0x20]:4 local_20                  XREF[2]:     0054bab1(W), 0054bac7(*)  
    //                               _sscanf                                                      XREF[33]:    loadBuildList:0040958a(c), 
    //                               sscanf                                                                    loadBuildList:004095cb(c), 
    //                                                                                                         loadConstructionPlan:0040b7bd(c), 
    //                                                                                                         loadConstructionPlan:0040b80c(c), 
    //                                                                                                         loadPlays:0041032f(c), 
    //                                                                                                         loadPlays:004104cb(c), 
    //                                                                                                         loadPlays:00410500(c), 
    //                                                                                                         loadPlays:00410632(c), 
    //                                                                                                         loadPlays:004106ae(c), 
    //                                                                                                         loadPlays:00410722(c), 
    //                                                                                                         loadPlays:00410796(c), 
    //                                                                                                         loadPlays:00410812(c), 
    //                                                                                                         loadPlays:00410913(c), 
    //                                                                                                         loadPlays:004109bc(c), 
    //                                                                                                         loadPlays:00410a68(c), 
    //                                                                                                         loadPlays:00410af5(c), 
    //                                                                                                         loadPlays:00410b7f(c), 
    //                                                                                                         loadTechnologyTree:00411cb8(c), 
    //                                                                                                         setup:00466eb1(c), 
    //                                                                                                         loadRules:004e7503(c), [more]
    //         0054baa0     SUB        ESP,0x20
    //         0054baa3     PUSH       EDI
    //         0054baa4     MOV        EDI,dword ptr [ESP + Stack[0x4]]
    //         0054baa8     OR         ECX,0xffffffff
    //         0054baab     XOR        EAX,EAX
    //         0054baad     MOV        dword ptr [ESP + local_18],EDI
    //         0054bab1     MOV        dword ptr [ESP + local_20],EDI
    //         0054bab5     SCASB.RE   ES:EDI
    //         0054bab7     NOT        ECX
    //         0054bab9     DEC        ECX
    //         0054baba     LEA        EAX=>Stack[0xc],[ESP + 0x30]
    //         0054babe     MOV        dword ptr [ESP + local_1c],ECX
    //         0054bac2     MOV        ECX,dword ptr [ESP + Stack[0x8]]
    //         0054bac6     PUSH       EAX
    //         0054bac7     LEA        EDX=>local_20,[ESP + 0x8]
    //         0054bacb     PUSH       ECX
    //         0054bacc     PUSH       EDX
    //         0054bacd     MOV        dword ptr [ESP + local_14],0x49
    //         0054bad5     CALL       __input                                          undefined __input()
    //         0054bada     ADD        ESP,0xc
    //         0054badd     POP        EDI
    //         0054bade     ADD        ESP,0x20
    //         0054bae1     RET
}

// Offset: 0x0054BAF0
undefined fgets() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * fgets                                                                                                 *
    //                              *********************************************************************************************************
    //                              undefined __cdecl fgets()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               _fgets                                                       XREF[13]:    loadBuildList:0040954b(c), 
    //                               fgets                                                                     loadBuildList:00409795(c), 
    //                                                                                                         loadConstructionPlan:0040b794(c), 
    //                                                                                                         loadConstructionPlan:0040b8dd(c), 
    //                                                                                                         loadPlays:004102fa(c), 
    //                                                                                                         loadPlays:00410383(c), 
    //                                                                                                         loadPlays:0041042a(c), 
    //                                                                                                         loadTechnologyTree:00411c77(c), 
    //                                                                                                         loadTechnologyTree:00411d6f(c), 
    //                                                                                                         loadRules:004d69ac(c), 
    //                                                                                                         loadRules:004d6a36(c), 
    //                                                                                                         loadRules:004e74df(c), 
    //                                                                                                         loadRules:004e7575(c)  
    //         0054baf0     PUSH       EBX
    //         0054baf1     MOV        EBX,dword ptr [ESP + Stack[0x8]]
    //         0054baf5     PUSH       EBP
    //         0054baf6     MOV        EBP,dword ptr [ESP + Stack[0x4]]
    //         0054bafa     PUSH       EDI
    //         0054bafb     MOV        EDI,EBP
    //         0054bafd     TEST       EBX,EBX
    //         0054baff     MOV        dword ptr [ESP + Stack[0x4]],EBP
    //         0054bb03     JG         LAB_0054bb0b
    //         0054bb05     XOR        EAX,EAX
    //         0054bb07     POP        EDI
    //         0054bb08     POP        EBP
    //         0054bb09     POP        EBX
    //         0054bb0a     RET
    //                               LAB_0054bb0b                                                 XREF[1]:     0054bb03(j)  
    //         0054bb0b     DEC        EBX
    //         0054bb0c     PUSH       ESI
    //         0054bb0d     JZ         LAB_0054bb56
    //         0054bb0f     MOV        ESI,dword ptr [ESP + Stack[0xc]]
    //                               LAB_0054bb13                                                 XREF[1]:     0054bb3d(j)  
    //         0054bb13     MOV        EAX,dword ptr [ESI + 0x4]
    //         0054bb16     DEC        EAX
    //         0054bb17     MOV        dword ptr [ESI + 0x4],EAX
    //         0054bb1a     JS         LAB_0054bb27
    //         0054bb1c     MOV        ECX,dword ptr [ESI]
    //         0054bb1e     XOR        EAX,EAX
    //         0054bb20     MOV        AL,byte ptr [ECX]
    //         0054bb22     INC        ECX
    //         0054bb23     MOV        dword ptr [ESI],ECX
    //         0054bb25     JMP        LAB_0054bb30
    //                               LAB_0054bb27                                                 XREF[1]:     0054bb1a(j)  
    //         0054bb27     PUSH       ESI
    //         0054bb28     CALL       __filbuf                                         undefined __filbuf()
    //         0054bb2d     ADD        ESP,0x4
    //                               LAB_0054bb30                                                 XREF[1]:     0054bb25(j)  
    //         0054bb30     CMP        EAX,-0x1
    //         0054bb33     JZ         LAB_0054bb4b
    //         0054bb35     MOV        byte ptr [EDI],AL
    //         0054bb37     INC        EDI
    //         0054bb38     CMP        AL,0xa
    //         0054bb3a     JZ         LAB_0054bb56
    //         0054bb3c     DEC        EBX
    //         0054bb3d     JNZ        LAB_0054bb13
    //         0054bb3f     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         0054bb43     MOV        byte ptr [EDI],0x0
    //         0054bb46     POP        ESI
    //         0054bb47     POP        EDI
    //         0054bb48     POP        EBP
    //         0054bb49     POP        EBX
    //         0054bb4a     RET
    //                               LAB_0054bb4b                                                 XREF[1]:     0054bb33(j)  
    //         0054bb4b     CMP        EDI,EBP
    //         0054bb4d     JNZ        LAB_0054bb56
    //         0054bb4f     XOR        EAX,EAX
    //         0054bb51     POP        ESI
    //         0054bb52     POP        EDI
    //         0054bb53     POP        EBP
    //         0054bb54     POP        EBX
    //         0054bb55     RET
    //                               LAB_0054bb56                                                 XREF[3]:     0054bb0d(j), 0054bb3a(j), 
    //                                                                                                         0054bb4d(j)  
    //         0054bb56     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         0054bb5a     MOV        byte ptr [EDI],0x0
    //         0054bb5d     POP        ESI
    //         0054bb5e     POP        EDI
    //         0054bb5f     POP        EBP
    //         0054bb60     POP        EBX
    //         0054bb61     RET
}

// Offset: 0x0054BB70
undefined fsopen() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined __fsopen()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               __fsopen                                                     XREF[1]:     fopen:0054bbac(c)  
    //         0054bb70     CALL       __getstream                                      undefined __getstream()
    //         0054bb75     TEST       EAX,EAX
    //         0054bb77     JNZ        LAB_0054bb7a
    //         0054bb79     RET
    //                               LAB_0054bb7a                                                 XREF[1]:     0054bb77(j)  
    //         0054bb7a     MOV        ECX,dword ptr [ESP + Stack[0x8]]
    //         0054bb7e     MOV        EDX,dword ptr [ESP + Stack[0x4]]
    //         0054bb82     PUSH       EAX
    //         0054bb83     MOV        EAX,dword ptr [ESP + Stack[0xc]]
    //         0054bb87     PUSH       EAX
    //         0054bb88     PUSH       ECX
    //         0054bb89     PUSH       EDX
    //         0054bb8a     CALL       __openfile                                       undefined __openfile()
    //         0054bb8f     ADD        ESP,0x10
    //         0054bb92     RET
}

// Offset: 0x0054BBA0
undefined fopen() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * fopen                                                                                                 *
    //                              *********************************************************************************************************
    //                              undefined __cdecl fopen()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               _fopen                                                       XREF[49]:    loadConstructionPlan:0040b777(c), 
    //                               fopen                                                                     write_draw_log2:0041b685(c), 
    //                                                                                                         setup:0041bd49(c), 
    //                                                                                                         setup:0041c1a1(c), 
    //                                                                                                         setup:0041c1e0(c), 
    //                                                                                                         setup:0041c200(c), 
    //                                                                                                         debug_random_write:0042303b(c), 
    //                                                                                                         LogChecksums:0043347a(c), 
    //                                                                                                         OpenLog:0043653d(c), 
    //                                                                                                         RGE_Doppleganger_Creator:00442163(
    //                                                                                                         RESFILE_Extract_to_File:0047f521(c
    //                                                                                                         RESFILE_build_res_file:0047f606(c)
    //                                                                                                         RGE_RMM_Database_Controller:00482b
    //                                                                                                         RGE_RMM_Database_Controller:00482c
    //                                                                                                         RGE_RMM_Database_Controller:00482d
    //                                                                                                         RGE_RMM_Database_Controller:00482e
    //                                                                                                         logDebug:004c7375(c), 
    //                                                                                                         run_log:00521044(c), 
    //                                                                                                         run_log:0052105d(c), 
    //                                                                                                         load_game:005264a8(c), [more]
    //         0054bba0     MOV        EAX,dword ptr [ESP + Stack[0x8]]
    //         0054bba4     MOV        ECX,dword ptr [ESP + Stack[0x4]]
    //         0054bba8     PUSH       0x40
    //         0054bbaa     PUSH       EAX
    //         0054bbab     PUSH       ECX
    //         0054bbac     CALL       __fsopen                                         undefined __fsopen()
    //         0054bbb1     ADD        ESP,0xc
    //         0054bbb4     RET
}

// Offset: 0x0054BBC0
undefined sprintf() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * sprintf                                                                                               *
    //                              *********************************************************************************************************
    //                              undefined __cdecl sprintf()
    //              undefined         <UNASSIGNED>   <RETURN>
    //              undefined4        Stack[-0x14]:4 local_14                  XREF[1]:     0054bbdf(W)  
    //              undefined4        Stack[-0x18]:4 local_18                  XREF[1]:     0054bbcb(W)  
    //              undefined4        Stack[-0x1c]:4 local_1c                  XREF[3]:     0054bbe7(W), 0054bbf6(R), 0054bbfe(W)  
    //              undefined4        Stack[-0x20]:4 local_20                  XREF[4]:     0054bbcf(*), 0054bbd9(*), 0054bc04(R), 0054bc12(*)  
    //                               _sprintf                                                     XREF[437]:   debug_rand:0042312a(c), 
    //                               sprintf                                                                   OpenLog:0043652f(c), 
    //                                                                                                         Log:004366e0(c), Log:0043675e(c), 
    //                                                                                                         Log:004367b0(c), 
    //                                                                                                         get_palette:004642f5(c), 
    //                                                                                                         setup:00466c1c(c), 
    //                                                                                                         setup_shadow_area:004673fb(c), 
    //                                                                                                         set_background:00467afb(c), 
    //                                                                                                         set_background2:00467c6b(c), 
    //                                                                                                         set_button_pics:004680eb(c), 
    //                                                                                                         RESFILE_load:0047f384(c), 
    //                                                                                                         player_changed:00498b1e(c), 
    //                                                                                                         player_changed:00498b73(c), 
    //                                                                                                         player_changed:00498d85(c), 
    //                                                                                                         player_changed:00498e29(c), 
    //                                                                                                         play:004bc3b1(c), 
    //                                                                                                         load:004bce0c(c), 
    //                                                                                                         show_ai:00524b56(c), 
    //                                                                                                         show_ai:00524b76(c), [more]
    //         0054bbc0     SUB        ESP,0x20
    //         0054bbc3     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         0054bbc7     MOV        ECX,dword ptr [ESP + Stack[0x8]]
    //         0054bbcb     MOV        dword ptr [ESP + local_18],EAX
    //         0054bbcf     MOV        dword ptr [ESP]=>local_20,EAX
    //         0054bbd3     LEA        EAX=>Stack[0xc],[ESP + 0x2c]
    //         0054bbd7     PUSH       ESI
    //         0054bbd8     PUSH       EAX
    //         0054bbd9     LEA        EDX=>local_20,[ESP + 0x8]
    //         0054bbdd     PUSH       ECX
    //         0054bbde     PUSH       EDX
    //         0054bbdf     MOV        dword ptr [ESP + local_14],0x42
    //         0054bbe7     MOV        dword ptr [ESP + local_1c],0x7fffffff
    //         0054bbef     CALL       __output                                         undefined __output()
    //         0054bbf4     MOV        ESI,EAX
    //         0054bbf6     MOV        EAX,dword ptr [ESP + local_1c]
    //         0054bbfa     ADD        ESP,0xc
    //         0054bbfd     DEC        EAX
    //         0054bbfe     MOV        dword ptr [ESP + local_1c],EAX
    //         0054bc02     JS         LAB_0054bc12
    //         0054bc04     MOV        EAX,dword ptr [ESP + local_20]
    //         0054bc08     MOV        byte ptr [EAX],0x0
    //         0054bc0b     MOV        EAX,ESI
    //         0054bc0d     POP        ESI
    //         0054bc0e     ADD        ESP,0x20
    //         0054bc11     RET
    //                               LAB_0054bc12                                                 XREF[1]:     0054bc02(j)  
    //         0054bc12     LEA        ECX=>local_20,[ESP + 0x4]
    //         0054bc16     PUSH       ECX
    //         0054bc17     PUSH       0x0
    //         0054bc19     CALL       __flsbuf                                         undefined __flsbuf()
    //         0054bc1e     ADD        ESP,0x8
    //         0054bc21     MOV        EAX,ESI
    //         0054bc23     POP        ESI
    //         0054bc24     ADD        ESP,0x20
    //         0054bc27     RET
}

// Offset: 0x0054BC30
undefined asctime() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * asctime                                                                                               *
    //                              *********************************************************************************************************
    //                              undefined __cdecl asctime()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               _asctime                                                     XREF[4]:     setLogCommonHistory:0040e56d(c), 
    //                               asctime                                                                   Time:004363fd(c), 
    //                                                                                                         logStatus:0052e100(c), 
    //                                                                                                         ctime:0054da52(c)  
    //         0054bc30     PUSH       ESI
    //         0054bc31     MOV        ESI,dword ptr [ESP + Stack[0x4]]
    //         0054bc35     MOV        EAX,dword ptr [ESI + 0x18]
    //         0054bc38     LEA        ECX,[EAX + EAX*0x2]
    //         0054bc3b     MOV        EAX,dword ptr [ESI + 0x10]
    //         0054bc3e     MOV        byte ptr [null_00887fbb],0x20                    = align(29)
    //         0054bc45     MOV        byte ptr [null_00887fbf],0x20                    = align(25)
    //         0054bc4c     LEA        EAX,[EAX + EAX*0x2]
    //         0054bc4f     LEA        ECX,[ECX + ___dnames]                            = 53h    S
    //         0054bc55     MOV        DX,word ptr [EAX + ___mnames]                    = 4Ah    J
    //         0054bc5c     LEA        EAX,[EAX + ___mnames]                            = 4Ah    J
    //         0054bc62     MOV        word ptr [null_00887fbc],DX                      = align(28)
    //         0054bc69     MOV        DX,word ptr [ECX]=>___dnames                     = 53h    S
    //         0054bc6c     MOV        AL,byte ptr [EAX + 0x2]=>s_nFebMarAprMayJunJul   = "nFebMarAprMayJunJulAugSepOctNovDec"
    //         0054bc6f     MOV        word ptr [null_00887fb8],DX                      = align(32)
    //         0054bc76     MOV        [null_00887fbe],AL                               = align(26)
    //         0054bc7b     MOV        AL,byte ptr [ECX + 0x2]=>s_nMonTueWedThuFriSat   = "nMonTueWedThuFriSat"
    //         0054bc7e     MOV        [null_00887fba],AL                               = align(30)
    //         0054bc83     MOV        ECX,dword ptr [ESI + 0xc]
    //         0054bc86     PUSH       ECX
    //         0054bc87     PUSH       null_00887fc0                                    = align(24)
    //         0054bc8c     CALL       FUN_0054bd20                                     undefined FUN_0054bd20()
    //         0054bc91     ADD        ESP,0x8
    //         0054bc94     MOV        byte ptr [EAX],0x20
    //         0054bc97     MOV        EDX,dword ptr [ESI + 0x8]
    //         0054bc9a     INC        EAX
    //         0054bc9b     PUSH       EDX
    //         0054bc9c     PUSH       EAX
    //         0054bc9d     CALL       FUN_0054bd20                                     undefined FUN_0054bd20()
    //         0054bca2     ADD        ESP,0x8
    //         0054bca5     MOV        byte ptr [EAX],0x3a
    //         0054bca8     MOV        ECX,dword ptr [ESI + 0x4]
    //         0054bcab     INC        EAX
    //         0054bcac     PUSH       ECX
    //         0054bcad     PUSH       EAX
    //         0054bcae     CALL       FUN_0054bd20                                     undefined FUN_0054bd20()
    //         0054bcb3     ADD        ESP,0x8
    //         0054bcb6     MOV        byte ptr [EAX],0x3a
    //         0054bcb9     MOV        EDX,dword ptr [ESI]
    //         0054bcbb     INC        EAX
    //         0054bcbc     PUSH       EDX
    //         0054bcbd     PUSH       EAX
    //         0054bcbe     CALL       FUN_0054bd20                                     undefined FUN_0054bd20()
    //         0054bcc3     MOV        ECX,EAX
    //         0054bcc5     MOV        EAX,0x51eb851f
    //         0054bcca     ADD        ESP,0x8
    //         0054bccd     MOV        byte ptr [ECX],0x20
    //         0054bcd0     MOV        EDX,dword ptr [ESI + 0x14]
    //         0054bcd3     IMUL       EDX
    //         0054bcd5     SAR        EDX,0x5
    //         0054bcd8     MOV        EAX,EDX
    //         0054bcda     SHR        EAX,0x1f
    //         0054bcdd     INC        ECX
    //         0054bcde     LEA        EDX,[EDX + EAX*0x1 + 0x13]
    //         0054bce2     PUSH       EDX
    //         0054bce3     PUSH       ECX
    //         0054bce4     CALL       FUN_0054bd20                                     undefined FUN_0054bd20()
    //         0054bce9     MOV        ECX,EAX
    //         0054bceb     MOV        EAX,dword ptr [ESI + 0x14]
    //         0054bcee     CDQ
    //         0054bcef     MOV        ESI,0x64
    //         0054bcf4     ADD        ESP,0x8
    //         0054bcf7     IDIV       ESI
    //         0054bcf9     PUSH       EDX
    //         0054bcfa     PUSH       ECX
    //         0054bcfb     CALL       FUN_0054bd20                                     undefined FUN_0054bd20()
    //         0054bd00     ADD        ESP,0x8
    //         0054bd03     MOV        byte ptr [EAX],0xa
    //         0054bd06     MOV        byte ptr [EAX + 0x1],0x0
    //         0054bd0a     MOV        EAX,null_00887fb8                                = align(32)
    //         0054bd0f     POP        ESI
    //         0054bd10     RET
}

// Offset: 0x0054BD20
undefined FUN_0054bd20() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0054bd20()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0054bd20                                                 XREF[6]:     asctime:0054bc8c(c), 
    //                                                                                                         asctime:0054bc9d(c), 
    //                                                                                                         asctime:0054bcae(c), 
    //                                                                                                         asctime:0054bcbe(c), 
    //                                                                                                         asctime:0054bce4(c), 
    //                                                                                                         asctime:0054bcfb(c)  
    //         0054bd20     PUSH       ESI
    //         0054bd21     MOV        ESI,dword ptr [ESP + Stack[0x8]]
    //         0054bd25     MOV        EAX,0x66666667
    //         0054bd2a     MOV        ECX,dword ptr [ESP + Stack[0x4]]
    //         0054bd2e     IMUL       ESI
    //         0054bd30     SAR        EDX,0x2
    //         0054bd33     MOV        EAX,EDX
    //         0054bd35     SHR        EAX,0x1f
    //         0054bd38     ADD        EDX,EAX
    //         0054bd3a     MOV        EAX,ESI
    //         0054bd3c     ADD        DL,0x30
    //         0054bd3f     MOV        ESI,0xa
    //         0054bd44     MOV        byte ptr [ECX],DL
    //         0054bd46     INC        ECX
    //         0054bd47     CDQ
    //         0054bd48     IDIV       ESI
    //         0054bd4a     LEA        EAX,[ECX + 0x1]
    //         0054bd4d     POP        ESI
    //         0054bd4e     ADD        DL,0x30
    //         0054bd51     MOV        byte ptr [ECX],DL
    //         0054bd53     RET
}

// Offset: 0x0054BD60
undefined localtime() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * localtime                                                                                             *
    //                              *********************************************************************************************************
    //                              undefined __cdecl localtime()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               _localtime                                                   XREF[6]:     setLogCommonHistory:0040e564(c), 
    //                               localtime                                                                 Time:004363ca(c), 
    //                                                                                                         logStatus:0052e0f7(c), 
    //                                                                                                         FUN_0054ca20:0054cbe9(c), 
    //                                                                                                         FUN_0054ca20:0054cc1a(c), 
    //                                                                                                         ctime:0054da45(c)  
    //         0054bd60     PUSH       ESI
    //         0054bd61     MOV        ESI,dword ptr [ESP + Stack[0x4]]
    //         0054bd65     CMP        dword ptr [ESI],0x0
    //         0054bd68     JGE        LAB_0054bd6e
    //         0054bd6a     XOR        EAX,EAX
    //         0054bd6c     POP        ESI
    //         0054bd6d     RET
    //                               LAB_0054bd6e                                                 XREF[1]:     0054bd68(j)  
    //         0054bd6e     CALL       ___tzset                                         undefined ___tzset()
    //         0054bd73     MOV        EAX,dword ptr [ESI]
    //         0054bd75     CMP        EAX,0x3f480
    //         0054bd7a     JLE        LAB_0054bde2
    //         0054bd7c     CMP        EAX,0x7ffc0b7f
    //         0054bd81     JGE        LAB_0054bde2
    //         0054bd83     SUB        EAX,dword ptr [__timezone]                       = 00007080h
    //         0054bd89     MOV        dword ptr [ESP + Stack[0x4]],EAX
    //         0054bd8d     LEA        EAX=>Stack[0x4],[ESP + 0x8]
    //         0054bd91     PUSH       EAX
    //         0054bd92     CALL       gmtime                                           undefined gmtime()
    //         0054bd97     MOV        ESI,EAX
    //         0054bd99     MOV        EAX,[__daylight]                                 = 00000001h
    //         0054bd9e     ADD        ESP,0x4
    //         0054bda1     TEST       EAX,EAX
    //         0054bda3     JZ         LAB_0054bf42
    //         0054bda9     PUSH       ESI
    //         0054bdaa     CALL       __isindst                                        undefined __isindst()
    //         0054bdaf     ADD        ESP,0x4
    //         0054bdb2     TEST       EAX,EAX
    //         0054bdb4     JZ         LAB_0054bf42
    //         0054bdba     MOV        ECX,dword ptr [__dstbias]                        = FFFFF1F0h
    //         0054bdc0     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         0054bdc4     LEA        EDX=>Stack[0x4],[ESP + 0x8]
    //         0054bdc8     SUB        EAX,ECX
    //         0054bdca     PUSH       EDX
    //         0054bdcb     MOV        dword ptr [ESP + Stack[0x4]],EAX
    //         0054bdcf     CALL       gmtime                                           undefined gmtime()
    //         0054bdd4     MOV        ESI,EAX
    //         0054bdd6     ADD        ESP,0x4
    //         0054bdd9     MOV        dword ptr [ESI + 0x20],0x1
    //         0054bde0     POP        ESI
    //         0054bde1     RET
    //                               LAB_0054bde2                                                 XREF[2]:     0054bd7a(j), 0054bd81(j)  
    //         0054bde2     PUSH       ESI
    //         0054bde3     CALL       gmtime                                           undefined gmtime()
    //         0054bde8     ADD        ESP,0x4
    //         0054bdeb     MOV        ESI,EAX
    //         0054bded     PUSH       ESI
    //         0054bdee     CALL       __isindst                                        undefined __isindst()
    //         0054bdf3     ADD        ESP,0x4
    //         0054bdf6     TEST       EAX,EAX
    //         0054bdf8     MOV        EAX,dword ptr [ESI]
    //         0054bdfa     JZ         LAB_0054be02
    //         0054bdfc     SUB        EAX,dword ptr [__dstbias]                        = FFFFF1F0h
    //                               LAB_0054be02                                                 XREF[1]:     0054bdfa(j)  
    //         0054be02     MOV        ECX,dword ptr [__timezone]                       = 00007080h
    //         0054be08     SUB        EAX,ECX
    //         0054be0a     MOV        ECX,0x3c
    //         0054be0f     MOV        dword ptr [ESP + Stack[0x4]],EAX
    //         0054be13     CDQ
    //         0054be14     IDIV       ECX
    //         0054be16     TEST       EDX,EDX
    //         0054be18     MOV        dword ptr [ESI],EDX
    //         0054be1a     JGE        LAB_0054be2a
    //         0054be1c     ADD        EDX,ECX
    //         0054be1e     MOV        dword ptr [ESI],EDX
    //         0054be20     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         0054be24     SUB        EAX,ECX
    //         0054be26     MOV        dword ptr [ESP + Stack[0x4]],EAX
    //                               LAB_0054be2a                                                 XREF[1]:     0054be1a(j)  
    //         0054be2a     MOV        ECX,dword ptr [ESP + Stack[0x4]]
    //         0054be2e     MOV        EAX,0x88888889
    //         0054be33     IMUL       ECX
    //         0054be35     ADD        EDX,ECX
    //         0054be37     MOV        ECX,dword ptr [ESI + 0x4]
    //         0054be3a     SAR        EDX,0x5
    //         0054be3d     MOV        EAX,EDX
    //         0054be3f     SHR        EAX,0x1f
    //         0054be42     ADD        EDX,EAX
    //         0054be44     ADD        EDX,ECX
    //         0054be46     MOV        ECX,0x3c
    //         0054be4b     MOV        EAX,EDX
    //         0054be4d     MOV        dword ptr [ESP + Stack[0x4]],EAX
    //         0054be51     CDQ
    //         0054be52     IDIV       ECX
    //         0054be54     TEST       EDX,EDX
    //         0054be56     MOV        dword ptr [ESI + 0x4],EDX
    //         0054be59     JGE        LAB_0054be6a
    //         0054be5b     ADD        EDX,ECX
    //         0054be5d     MOV        dword ptr [ESI + 0x4],EDX
    //         0054be60     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         0054be64     SUB        EAX,ECX
    //         0054be66     MOV        dword ptr [ESP + Stack[0x4]],EAX
    //                               LAB_0054be6a                                                 XREF[1]:     0054be59(j)  
    //         0054be6a     MOV        ECX,dword ptr [ESP + Stack[0x4]]
    //         0054be6e     MOV        EAX,0x88888889
    //         0054be73     IMUL       ECX
    //         0054be75     ADD        EDX,ECX
    //         0054be77     MOV        ECX,dword ptr [ESI + 0x8]
    //         0054be7a     SAR        EDX,0x5
    //         0054be7d     MOV        EAX,EDX
    //         0054be7f     SHR        EAX,0x1f
    //         0054be82     ADD        EDX,EAX
    //         0054be84     ADD        EDX,ECX
    //         0054be86     MOV        ECX,0x18
    //         0054be8b     MOV        EAX,EDX
    //         0054be8d     MOV        dword ptr [ESP + Stack[0x4]],EAX
    //         0054be91     CDQ
    //         0054be92     IDIV       ECX
    //         0054be94     TEST       EDX,EDX
    //         0054be96     MOV        dword ptr [ESI + 0x8],EDX
    //         0054be99     JGE        LAB_0054beaa
    //         0054be9b     ADD        EDX,ECX
    //         0054be9d     MOV        dword ptr [ESI + 0x8],EDX
    //         0054bea0     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         0054bea4     SUB        EAX,ECX
    //         0054bea6     MOV        dword ptr [ESP + Stack[0x4]],EAX
    //                               LAB_0054beaa                                                 XREF[1]:     0054be99(j)  
    //         0054beaa     MOV        EAX,0x2aaaaaab
    //         0054beaf     IMUL       dword ptr [ESP + Stack[0x4]]
    //         0054beb3     SAR        EDX,0x2
    //         0054beb6     MOV        EAX,EDX
    //         0054beb8     SHR        EAX,0x1f
    //         0054bebb     ADD        EDX,EAX
    //         0054bebd     MOV        EAX,EDX
    //         0054bebf     TEST       EAX,EAX
    //         0054bec1     MOV        dword ptr [ESP + Stack[0x4]],EAX
    //         0054bec5     JLE        LAB_0054bef3
    //         0054bec7     MOV        ECX,dword ptr [ESI + 0x18]
    //         0054beca     ADD        EAX,ECX
    //         0054becc     MOV        ECX,0x7
    //         0054bed1     CDQ
    //         0054bed2     IDIV       ECX
    //         0054bed4     MOV        EAX,dword ptr [ESI + 0xc]
    //         0054bed7     MOV        ECX,dword ptr [ESI + 0x1c]
    //         0054beda     MOV        dword ptr [ESI + 0x18],EDX
    //         0054bedd     MOV        EDX,dword ptr [ESP + Stack[0x4]]
    //         0054bee1     ADD        EAX,EDX
    //         0054bee3     MOV        dword ptr [ESI + 0xc],EAX
    //         0054bee6     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         0054beea     ADD        ECX,EAX
    //         0054beec     MOV        EAX,ESI
    //         0054beee     MOV        dword ptr [ESI + 0x1c],ECX
    //         0054bef1     POP        ESI
    //         0054bef2     RET
    //                               LAB_0054bef3                                                 XREF[1]:     0054bec5(j)  
    //         0054bef3     JGE        LAB_0054bf42
    //         0054bef5     MOV        ECX,dword ptr [ESI + 0x18]
    //         0054bef8     LEA        EAX,[EAX + ECX*0x1 + 0x7]
    //         0054befc     MOV        ECX,0x7
    //         0054bf01     CDQ
    //         0054bf02     IDIV       ECX
    //         0054bf04     MOV        EAX,dword ptr [ESI + 0xc]
    //         0054bf07     MOV        dword ptr [ESI + 0x18],EDX
    //         0054bf0a     MOV        EDX,dword ptr [ESP + Stack[0x4]]
    //         0054bf0e     ADD        EAX,EDX
    //         0054bf10     TEST       EAX,EAX
    //         0054bf12     MOV        dword ptr [ESI + 0xc],EAX
    //         0054bf15     JG         LAB_0054bf36
    //         0054bf17     ADD        EAX,0x1f
    //         0054bf1a     MOV        dword ptr [ESI + 0x1c],0x16c
    //         0054bf21     MOV        dword ptr [ESI + 0xc],EAX
    //         0054bf24     MOV        EAX,dword ptr [ESI + 0x14]
    //         0054bf27     DEC        EAX
    //         0054bf28     MOV        dword ptr [ESI + 0x10],0xb
    //         0054bf2f     MOV        dword ptr [ESI + 0x14],EAX
    //         0054bf32     MOV        EAX,ESI
    //         0054bf34     POP        ESI
    //         0054bf35     RET
    //                               LAB_0054bf36                                                 XREF[1]:     0054bf15(j)  
    //         0054bf36     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         0054bf3a     MOV        ECX,dword ptr [ESI + 0x1c]
    //         0054bf3d     ADD        ECX,EAX
    //         0054bf3f     MOV        dword ptr [ESI + 0x1c],ECX
    //                               LAB_0054bf42                                                 XREF[3]:     0054bda3(j), 0054bdb4(j), 
    //                                                                                                         0054bef3(j)  
    //         0054bf42     MOV        EAX,ESI
    //         0054bf44     POP        ESI
    //         0054bf45     RET
}

// Offset: 0x0054BF50
undefined time() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * time                                                                                                  *
    //                              *********************************************************************************************************
    //                              undefined __cdecl time()
    //              undefined         <UNASSIGNED>   <RETURN>
    //              undefined         Stack[-0xbc]:1 local_bc                  XREF[1]:     0054bf56(*)  
    //                               _time                                                        XREF[7]:     setLogCommonHistory:0040e557(c), 
    //                               time                                                                      check_expiration:0041fe2d(c), 
    //                                                                                                         Time:004363bd(c), Log:004366f6(c), 
    //                                                                                                         RGE_Scenario_Header:0048ab2a(c), 
    //                                                                                                         run_log:00521089(c), 
    //                                                                                                         logStatus:0052e0ea(c)  
    //         0054bf50     SUB        ESP,0xcc
    //         0054bf56     LEA        EAX=>local_bc,[ESP + 0x10]
    //         0054bf5a     PUSH       EAX
    //         0054bf5b     CALL       dword ptr [->KERNEL32.DLL::GetLocalTime]         = 0048b6fc
    //         0054bf61     LEA        ECX,[ESP]
    //         0054bf65     PUSH       ECX
    //         0054bf66     CALL       dword ptr [->KERNEL32.DLL::GetSystemTime]        = 0048b6ec
    //         0054bf6c     MOV        DX,word ptr [ESP + 0xa]
    //         0054bf71     CMP        DX,word ptr [DAT_00887fea]
    //         0054bf78     JNZ        LAB_0054bfb9
    //         0054bf7a     MOV        AX,word ptr [ESP + 0x8]
    //         0054bf7f     CMP        AX,word ptr [DAT_00887fe8]
    //         0054bf86     JNZ        LAB_0054bfb9
    //         0054bf88     MOV        CX,word ptr [ESP + 0x6]
    //         0054bf8d     CMP        CX,word ptr [DAT_00887fe6]
    //         0054bf94     JNZ        LAB_0054bfb9
    //         0054bf96     MOV        DX,word ptr [ESP + 0x2]
    //         0054bf9b     CMP        DX,word ptr [DAT_00887fe2]
    //         0054bfa2     JNZ        LAB_0054bfb9
    //         0054bfa4     MOV        AX,word ptr [ESP]
    //         0054bfa9     CMP        AX,word ptr [DAT_00887fe0]
    //         0054bfb0     JNZ        LAB_0054bfb9
    //         0054bfb2     MOV        EAX,[DAT_00887fd8]
    //         0054bfb7     JMP        LAB_0054c01f
    //                               LAB_0054bfb9                                                 XREF[5]:     0054bf78(j), 0054bf86(j), 
    //                                                                                                         0054bf94(j), 0054bfa2(j), 
    //                                                                                                         0054bfb0(j)  
    //         0054bfb9     LEA        ECX,[ESP + 0x20]
    //         0054bfbd     PUSH       ECX
    //         0054bfbe     CALL       dword ptr [->KERNEL32.DLL::GetTimeZoneInformat   = 0048b6d2
    //         0054bfc4     CMP        EAX,-0x1
    //         0054bfc7     JZ         LAB_0054bfef
    //         0054bfc9     CMP        EAX,0x2
    //         0054bfcc     JNZ        LAB_0054bfeb
    //         0054bfce     CMP        word ptr [ESP + 0xba],0x0
    //         0054bfd7     JZ         LAB_0054bfeb
    //         0054bfd9     MOV        EAX,dword ptr [ESP + 0xc8]
    //         0054bfe0     TEST       EAX,EAX
    //         0054bfe2     JZ         LAB_0054bfeb
    //         0054bfe4     MOV        EAX,0x1
    //         0054bfe9     JMP        LAB_0054bff2
    //                               LAB_0054bfeb                                                 XREF[3]:     0054bfcc(j), 0054bfd7(j), 
    //                                                                                                         0054bfe2(j)  
    //         0054bfeb     XOR        EAX,EAX
    //         0054bfed     JMP        LAB_0054bff2
    //                               LAB_0054bfef                                                 XREF[1]:     0054bfc7(j)  
    //         0054bfef     OR         EAX,0xffffffff
    //                               LAB_0054bff2                                                 XREF[2]:     0054bfe9(j), 0054bfed(j)  
    //         0054bff2     MOV        EDX,dword ptr [ESP]
    //         0054bff6     MOV        ECX,dword ptr [ESP + 0x4]
    //         0054bffa     MOV        dword ptr [DAT_00887fe0],EDX
    //         0054c000     MOV        EDX,dword ptr [ESP + 0x8]
    //         0054c004     MOV        dword ptr [DAT_00887fe4],ECX                     = align(2)
    //         0054c00a     MOV        ECX,dword ptr [ESP + 0xc]
    //         0054c00e     MOV        [DAT_00887fd8],EAX
    //         0054c013     MOV        dword ptr [DAT_00887fe8],EDX
    //         0054c019     MOV        dword ptr [DAT_00887fec],ECX                     = align(4)
    //                               LAB_0054c01f                                                 XREF[1]:     0054bfb7(j)  
    //         0054c01f     MOV        EDX,dword ptr [ESP + 0x1c]
    //         0054c023     MOV        ECX,dword ptr [ESP + 0x18]
    //         0054c027     PUSH       EAX
    //         0054c028     MOV        EAX,dword ptr [ESP + 0x1e]
    //         0054c02c     AND        EDX,0xffff
    //         0054c032     AND        EAX,0xffff
    //         0054c037     PUSH       EDX=>DAT_fffffff8
    //         0054c038     MOV        EDX,dword ptr [ESP + 0x1e]
    //         0054c03c     AND        ECX,0xffff
    //         0054c042     PUSH       EAX=>DAT_fffffff4
    //         0054c043     MOV        EAX,dword ptr [ESP + 0x1e]
    //         0054c047     PUSH       ECX=>DAT_fffffff0
    //         0054c048     MOV        ECX,dword ptr [ESP + 0x20]
    //         0054c04c     AND        EDX,0xffff
    //         0054c052     AND        EAX,0xffff
    //         0054c057     PUSH       EDX
    //         0054c058     AND        ECX,0xffff
    //         0054c05e     PUSH       EAX
    //         0054c05f     PUSH       ECX
    //         0054c060     CALL       ___loctotime_t                                   undefined ___loctotime_t()
    //         0054c065     MOV        ECX,dword ptr [ESP + 0xec]
    //         0054c06c     ADD        ESP,0x1c
    //         0054c06f     TEST       ECX,ECX
    //         0054c071     JZ         LAB_0054c075
    //         0054c073     MOV        dword ptr [ECX],EAX
    //                               LAB_0054c075                                                 XREF[1]:     0054c071(j)  
    //         0054c075     ADD        ESP,0xcc
    //         0054c07b     RET
}

