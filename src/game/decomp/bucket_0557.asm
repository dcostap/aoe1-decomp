// Auto-generated scaffold unit: bucket_0557.asm
#include "../include/common.h"

// Offset: 0x00557070
undefined FF_MSGBANNER() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined __FF_MSGBANNER()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               __FF_MSGBANNER                                               XREF[1]:     __amsg_exit:0054fa19(c)  
    //         00557070     MOV        EAX,[___error_mode]
    //         00557075     CMP        EAX,0x1
    //         00557078     JZ         LAB_00557087
    //         0055707a     TEST       EAX,EAX
    //         0055707c     JNZ        LAB_005570ac
    //         0055707e     CMP        dword ptr [___app_type],0x1                      = 00000002h
    //         00557085     JNZ        LAB_005570ac
    //                               LAB_00557087                                                 XREF[1]:     00557078(j)  
    //         00557087     PUSH       0xfc
    //         0055708c     CALL       __NMSG_WRITE                                     undefined __NMSG_WRITE()
    //         00557091     MOV        EAX,[__adbgmsg]
    //         00557096     ADD        ESP,0x4
    //         00557099     TEST       EAX,EAX
    //         0055709b     JZ         LAB_0055709f
    //         0055709d     CALL       EAX
    //                               LAB_0055709f                                                 XREF[1]:     0055709b(j)  
    //         0055709f     PUSH       0xff
    //         005570a4     CALL       __NMSG_WRITE                                     undefined __NMSG_WRITE()
    //         005570a9     ADD        ESP,0x4
    //                               LAB_005570ac                                                 XREF[2]:     0055707c(j), 00557085(j)  
    //         005570ac     RET
}

// Offset: 0x005570B0
undefined NMSG_WRITE() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined __NMSG_WRITE()
    //              undefined         <UNASSIGNED>   <RETURN>
    //              undefined         Stack[-0x104   local_104                 XREF[1]:     0055710c(*)  
    //              undefined         Stack[-0x1a8   local_1a8                 XREF[1]:     0055725f(*)  
    //                               __NMSG_WRITE                                                 XREF[4]:     __amsg_exit:0054fa23(c), 
    //                                                                                                         __FF_MSGBANNER:0055708c(c), 
    //                                                                                                         __FF_MSGBANNER:005570a4(c), 
    //                                                                                                         abort:005576f2(c)  
    //         005570b0     MOV        ECX,dword ptr [ESP + Stack[0x4]]
    //         005570b4     SUB        ESP,0x1a8
    //         005570ba     MOV        EAX,DAT_00592600                                 = 00000002h
    //         005570bf     PUSH       EBX
    //         005570c0     PUSH       EBP
    //         005570c1     PUSH       ESI
    //         005570c2     PUSH       EDI
    //         005570c3     XOR        EBP,EBP
    //                               LAB_005570c5                                                 XREF[1]:     005570d2(j)  
    //         005570c5     CMP        ECX,dword ptr [EAX]=>DAT_00592600                = 00000002h
    //                                                                                  = 00000008h
    //         005570c7     JZ         LAB_005570d4
    //         005570c9     ADD        EAX=>DAT_00592610,0x8                            = 00000009h
    //         005570cc     INC        EBP
    //         005570cd     CMP        EAX,DAT_00592690
    //         005570d2     JC         LAB_005570c5
    //                               LAB_005570d4                                                 XREF[1]:     005570c7(j)  
    //         005570d4     CMP        ECX,dword ptr [EBP*0x8 + 0x592600]=>DAT_00592610 = 00000008h
    //                                                                                  = 00000009h
    //         005570db     JNZ        LAB_0055727b
    //         005570e1     MOV        EAX,[___error_mode]
    //         005570e6     CMP        EAX,0x1
    //         005570e9     JZ         LAB_0055723d
    //         005570ef     TEST       EAX,EAX
    //         005570f1     JNZ        LAB_00557100
    //         005570f3     CMP        dword ptr [___app_type],0x1                      = 00000002h
    //         005570fa     JZ         LAB_0055723d
    //                               LAB_00557100                                                 XREF[1]:     005570f1(j)  
    //         00557100     CMP        ECX,0xfc
    //         00557106     JZ         LAB_0055727b
    //         0055710c     LEA        EAX=>local_104,[ESP + 0xb4]
    //         00557113     PUSH       0x104
    //         00557118     PUSH       EAX
    //         00557119     PUSH       0x0
    //         0055711b     CALL       dword ptr [->KERNEL32.DLL::GetModuleFileNameA]   = 0048b978
    //         00557121     TEST       EAX,EAX
    //         00557123     JNZ        LAB_0055713b
    //         00557125     MOV        ECX,0x5
    //         0055712a     MOV        ESI,s_<>                                         = 6F72703Ch
    //         0055712f     LEA        EDI,[ESP + 0xb4]
    //         00557136     MOVSD.REP  ES:EDI,ESI=>s_<>                                 = 6F72703Ch
    //                                                                                  = 7267h
    //         00557138     MOVSW      ES:EDI,ESI=>DAT_00577fc0                         = 7267h
    //         0055713a     MOVSB      ES:EDI,ESI=>s_am_name_unknown>_00577fc2          = "am name unknown>"
    //                               LAB_0055713b                                                 XREF[1]:     00557123(j)  
    //         0055713b     LEA        EDI,[ESP + 0xb4]
    //         00557142     OR         ECX,0xffffffff
    //         00557145     XOR        EAX,EAX
    //         00557147     LEA        EBX,[ESP + 0xb4]
    //         0055714e     SCASB.RE   ES:EDI
    //         00557150     NOT        ECX
    //         00557152     CMP        ECX,0x3c
    //         00557155     JBE        LAB_00557184
    //         00557157     LEA        EDI,[ESP + 0xb4]
    //         0055715e     OR         ECX,0xffffffff
    //         00557161     SCASB.RE   ES:EDI
    //         00557163     NOT        ECX
    //         00557165     DEC        ECX
    //         00557166     PUSH       0x3
    //         00557168     MOV        EBX,ECX
    //         0055716a     LEA        ECX,[ESP + 0xb8]
    //         00557171     SUB        ECX,0x3b
    //         00557174     PUSH       s_...                                            = "..."
    //         00557179     ADD        EBX,ECX
    //         0055717b     PUSH       EBX=>DAT_fffffff4
    //         0055717c     CALL       strncpy                                          undefined strncpy()
    //         00557181     ADD        ESP,0xc
    //                               LAB_00557184                                                 XREF[1]:     00557155(j)  
    //         00557184     MOV        ECX,0x6
    //         00557189     MOV        ESI,s_Runtime_Error!__Program:_                  = 746E7552h
    //         0055718e     LEA        EDI,[ESP + 0x14]
    //         00557192     XOR        EAX,EAX
    //         00557194     MOVSD.REP  ES:EDI,ESI=>s_Runtime_Error!__Program:_          = 746E7552h
    //                                                                                  = "ime Error!\n\nProgram: "
    //         00557196     MOVSW      ES:EDI,ESI=>s_ime_Error!_Program:_00577fa0       = "ime Error!\n\nProgram: "
    //         00557198     OR         ECX,0xffffffff
    //         0055719b     MOV        EDI,EBX
    //         0055719d     SCASB.RE   ES:EDI
    //         0055719f     NOT        ECX
    //         005571a1     SUB        EDI,ECX
    //         005571a3     LEA        EDX,[ESP + 0x14]
    //         005571a7     MOV        EBX,ECX
    //         005571a9     MOV        ESI,EDI
    //         005571ab     OR         ECX,0xffffffff
    //         005571ae     MOV        EDI,EDX
    //         005571b0     SCASB.RE   ES:EDI
    //         005571b2     MOV        ECX,EBX
    //         005571b4     DEC        EDI
    //         005571b5     SHR        ECX,0x2
    //         005571b8     MOVSD.REP  ES:EDI,ESI
    //         005571ba     MOV        ECX,EBX
    //         005571bc     LEA        EDX,[ESP + 0x14]
    //         005571c0     AND        ECX,0x3
    //         005571c3     PUSH       0x12010
    //         005571c8     MOVSB.REP  ES:EDI,ESI
    //         005571ca     MOV        EDI,s___                                         = 0Ah
    //         005571cf     OR         ECX,0xffffffff
    //         005571d2     SCASB.RE   ES:EDI=>s___                                     = 0Ah
    //         005571d4     NOT        ECX
    //         005571d6     SUB        EDI,ECX
    //         005571d8     PUSH       s_Microsoft_Visual_C++_Runtime_Lib               = "Microsoft Visual C++ Runtime Library"
    //         005571dd     MOV        ESI,EDI
    //         005571df     MOV        EBX,ECX
    //         005571e1     MOV        EDI,EDX
    //         005571e3     OR         ECX,0xffffffff
    //         005571e6     SCASB.RE   ES:EDI
    //         005571e8     MOV        ECX,EBX
    //         005571ea     DEC        EDI
    //         005571eb     SHR        ECX,0x2
    //         005571ee     MOVSD.REP  ES:EDI,ESI=>s___                                 = 0Ah
    //         005571f0     MOV        ECX,EBX
    //         005571f2     LEA        EDX,[ESP + 0x1c]
    //         005571f6     AND        ECX,0x3
    //         005571f9     MOVSB.REP  ES:EDI,ESI=>s___                                 = 0Ah
    //         005571fb     MOV        EDI,dword ptr [EBP*0x8 + 0x592604]=>->s_R6009_   = 00577ef4
    //         00557202     OR         ECX,0xffffffff
    //         00557205     SCASB.RE   ES:EDI=>s_R6009__-_not_enough_space_for_en       = 52h
    //                                                                                  = "6009\r\n- not enough space for environment
    //         00557207     NOT        ECX
    //         00557209     SUB        EDI,ECX
    //         0055720b     MOV        ESI,EDI
    //         0055720d     MOV        EBX,ECX
    //         0055720f     MOV        EDI,EDX
    //         00557211     OR         ECX,0xffffffff
    //         00557214     SCASB.RE   ES:EDI
    //         00557216     MOV        ECX,EBX
    //         00557218     DEC        EDI
    //         00557219     SHR        ECX,0x2
    //         0055721c     MOVSD.REP  ES:EDI,ESI=>s_R6009__-_not_enough_space_for_en   = 52h
    //         0055721e     MOV        ECX,EBX
    //         00557220     LEA        EAX,[ESP + 0x1c]
    //         00557224     AND        ECX,0x3
    //         00557227     PUSH       EAX=>DAT_fffffff4
    //         00557228     MOVSB.REP  ES:EDI,ESI=>s_R6009__-_not_enough_space_for_en   = 52h
    //         0055722a     CALL       ___crtMessageBoxA                                undefined ___crtMessageBoxA()
    //         0055722f     ADD        ESP,0xc
    //         00557232     POP        EDI
    //         00557233     POP        ESI
    //         00557234     POP        EBP
    //         00557235     POP        EBX
    //         00557236     ADD        ESP,0x1a8
    //         0055723c     RET
    //                               LAB_0055723d                                                 XREF[2]:     005570e9(j), 005570fa(j)  
    //         0055723d     MOV        EAX,[___pioinfo]
    //         00557242     TEST       EAX,EAX
    //         00557244     JZ         LAB_0055724e
    //         00557246     MOV        ESI,dword ptr [EAX + 0x10]
    //         00557249     CMP        ESI,-0x1
    //         0055724c     JNZ        LAB_00557258
    //                               LAB_0055724e                                                 XREF[1]:     00557244(j)  
    //         0055724e     PUSH       DAT_fffffff4
    //         00557250     CALL       dword ptr [->KERNEL32.DLL::GetStdHandle]         = 0048b86e
    //         00557256     MOV        ESI,EAX
    //                               LAB_00557258                                                 XREF[1]:     0055724c(j)  
    //         00557258     MOV        EDX,dword ptr [EBP*0x8 + 0x592604]=>->s_R6009_   = 00577ef4
    //         0055725f     LEA        ECX=>local_1a8,[ESP + 0x10]
    //         00557263     PUSH       0x0
    //         00557265     PUSH       ECX=>DAT_fffffff8
    //         00557266     MOV        EDI,EDX
    //         00557268     OR         ECX,0xffffffff
    //         0055726b     XOR        EAX,EAX
    //         0055726d     SCASB.RE   ES:EDI=>s_R6009__-_not_enough_space_for_en       = 52h
    //                                                                                  = "6009\r\n- not enough space for environment
    //         0055726f     NOT        ECX
    //         00557271     DEC        ECX
    //         00557272     PUSH       ECX=>DAT_fffffff4
    //         00557273     PUSH       EDX=>s_R6009__-_not_enough_space_for_en          = 52h
    //         00557274     PUSH       ESI
    //         00557275     CALL       dword ptr [->KERNEL32.DLL::WriteFile]            = 0048b762
    //                               LAB_0055727b                                                 XREF[2]:     005570db(j), 00557106(j)  
    //         0055727b     POP        EDI
    //         0055727c     POP        ESI
    //         0055727d     POP        EBP
    //         0055727e     POP        EBX
    //         0055727f     ADD        ESP,0x1a8
    //         00557285     RET
}

// Offset: 0x00557286
undefined FUN_00557286() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00557286()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00557286
    //         00557286     NOP
    //         00557287     NOP
    //         00557288     NOP
    //         00557289     NOP
    //         0055728a     NOP
    //         0055728b     NOP
    //         0055728c     NOP
    //         0055728d     NOP
    //         0055728e     NOP
    //         0055728f     NOP
    //                               __GET_RTERRMSG
    //         00557290     MOV        EDX,dword ptr [ESP + Stack[0x4]]
    //         00557294     XOR        ECX,ECX
    //         00557296     MOV        EAX,DAT_00592600                                 = 00000002h
    //                               LAB_0055729b                                                 XREF[1]:     005572a8(j)  
    //         0055729b     CMP        EDX,dword ptr [EAX]=>DAT_00592600                = 00000002h
    //                                                                                  = 00000008h
    //         0055729d     JZ         LAB_005572aa
    //         0055729f     ADD        EAX,0x8
    //         005572a2     INC        ECX
    //         005572a3     CMP        EAX,DAT_00592690
    //         005572a8     JC         LAB_0055729b
    //                               LAB_005572aa                                                 XREF[1]:     0055729d(j)  
    //         005572aa     CMP        EDX,dword ptr [ECX*0x8 + 0x592600]=>DAT_00592610 = 00000008h
    //                                                                                  = 00000009h
    //         005572b1     JNZ        LAB_005572bb
    //         005572b3     MOV        EAX=>s_R6009__-_not_enough_space_for_en,dword    = 52h
    //                                                                                  = "R6008\r\n- not enough space for arguments\
    //                                                                                  = 00577f20
    //                                                                                  = 00577ef4
    //         005572ba     RET
    //                               LAB_005572bb                                                 XREF[1]:     005572b1(j)  
    //         005572bb     XOR        EAX,EAX
    //         005572bd     RET
}

// Offset: 0x005572C0
long CxxUnhandledExceptionFilter(_EXCEPTION_POINTERS* param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * long __stdcall __CxxUnhandledExceptionFilter(struct _EXCEPTION_POINTERS *)                            *
    //                              *********************************************************************************************************
    //                              long __stdcall __CxxUnhandledExceptionFilter(_EXCEPTION_POINTERS * p
    //              long              EAX:4          <RETURN>
    //              _EXCEPTION_POI    Stack[0x4]:4   param_1                   XREF[1]:     005572c1(R)  
    //                               ?__CxxUnhandledExceptionFilter@@YGJPAU_EXCEPTION_POINTERS@@@Z XREF[1]:     __CxxSetUnhandledExceptionFilter:0
    //                               __CxxUnhandledExceptionFilter
    //         005572c0     PUSH       ESI
    //         005572c1     MOV        ESI,dword ptr [ESP + param_1]
    //         005572c5     MOV        EAX,dword ptr [ESI]
    //         005572c7     CMP        dword ptr [EAX],0xe06d7363
    //         005572cd     JNZ        LAB_005572ec
    //         005572cf     CMP        dword ptr [EAX + 0x10],0x3
    //         005572d3     JNZ        LAB_005572ec
    //         005572d5     CMP        dword ptr [EAX + 0x14],0x19930520
    //         005572dc     JNZ        LAB_005572ec
    //         005572de     CALL       terminate                                        void terminate(void)
    //         005572e3     MOV        EAX,0x1
    //         005572e8     POP        ESI
    //         005572e9     RET        0x4
    //                               LAB_005572ec                                                 XREF[3]:     005572cd(j), 005572d3(j), 
    //                                                                                                         005572dc(j)  
    //         005572ec     MOV        EAX,[DAT_008883e8]
    //         005572f1     TEST       EAX,EAX
    //         005572f3     JZ         LAB_0055730d
    //         005572f5     PUSH       EAX
    //         005572f6     CALL       _ValidateExecute                                 int _ValidateExecute(_func_int * param_1)
    //         005572fb     ADD        ESP,0x4
    //         005572fe     TEST       EAX,EAX
    //         00557300     JZ         LAB_0055730d
    //         00557302     PUSH       ESI
    //         00557303     CALL       dword ptr [DAT_008883e8]
    //         00557309     POP        ESI
    //         0055730a     RET        0x4
    //                               LAB_0055730d                                                 XREF[2]:     005572f3(j), 00557300(j)  
    //         0055730d     XOR        EAX,EAX
    //         0055730f     POP        ESI
    //         00557310     RET        0x4
}

// Offset: 0x00557320
void CxxSetUnhandledExceptionFilter() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * void __cdecl __CxxSetUnhandledExceptionFilter(void)                                                   *
    //                              *********************************************************************************************************
    //                              void __cdecl __CxxSetUnhandledExceptionFilter(void)
    //              void              <VOID>         <RETURN>
    //                               ?__CxxSetUnhandledExceptionFilter@@YAXXZ
    //                               __CxxSetUnhandledExceptionFilter
    //         00557320     PUSH       __CxxUnhandledExceptionFilter
    //         00557325     CALL       dword ptr [->KERNEL32.DLL::SetUnhandledExcepti   = 0048b9f4
    //         0055732b     MOV        [DAT_008883e8],EAX
    //         00557330     RET
}

// Offset: 0x00557340
void CxxRestoreUnhandledExceptionFilter() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * void __cdecl __CxxRestoreUnhandledExceptionFilter(void)                                               *
    //                              *********************************************************************************************************
    //                              void __cdecl __CxxRestoreUnhandledExceptionFilter(void)
    //              void              <VOID>         <RETURN>
    //                               ?__CxxRestoreUnhandledExceptionFilter@@YAXXZ
    //                               __CxxRestoreUnhandledExceptionFilter
    //         00557340     MOV        EAX,[DAT_008883e8]
    //         00557345     PUSH       EAX
    //         00557346     CALL       dword ptr [->KERNEL32.DLL::SetUnhandledExcepti   = 0048b9f4
    //         0055734c     RET
}

// Offset: 0x00557350
int ValidateRead(void* param_1, uint param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * int __cdecl _ValidateRead(void const *,unsigned int)                                                  *
    //                              *********************************************************************************************************
    //                              int __cdecl _ValidateRead(void * param_1, uint param_2)
    //              int               EAX:4          <RETURN>
    //              void *            Stack[0x4]:4   param_1                   XREF[1]:     00557354(R)  
    //              uint              Stack[0x8]:4   param_2                   XREF[1]:     00557350(R)  
    //                               ?_ValidateRead@@YAHPBXI@Z                                    XREF[5]:     FUN_0054fb10:0054fb80(c), 
    //                               _ValidateRead                                                             FUN_00550180:005501e6(c), 
    //                                                                                                         FUN_00550180:00550236(c), 
    //                                                                                                         FUN_00550180:005502a2(c), 
    //                                                                                                         FUN_00550180:005502e8(c)  
    //         00557350     MOV        EAX,dword ptr [ESP + param_2]
    //         00557354     MOV        ECX,dword ptr [ESP + param_1]
    //         00557358     PUSH       ESI
    //         00557359     PUSH       EAX
    //         0055735a     PUSH       ECX
    //         0055735b     MOV        ESI,0x1
    //         00557360     CALL       dword ptr [->KERNEL32.DLL::IsBadReadPtr]         = 0048ba12
    //         00557366     TEST       EAX,EAX
    //         00557368     JZ         LAB_0055736c
    //         0055736a     XOR        ESI,ESI
    //                               LAB_0055736c                                                 XREF[1]:     00557368(j)  
    //         0055736c     MOV        EAX,ESI
    //         0055736e     POP        ESI
    //         0055736f     RET
}

// Offset: 0x00557370
int ValidateWrite(void* param_1, uint param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * int __cdecl _ValidateWrite(void *,unsigned int)                                                       *
    //                              *********************************************************************************************************
    //                              int __cdecl _ValidateWrite(void * param_1, uint param_2)
    //              int               EAX:4          <RETURN>
    //              void *            Stack[0x4]:4   param_1                   XREF[1]:     00557374(R)  
    //              uint              Stack[0x8]:4   param_2                   XREF[1]:     00557370(R)  
    //                               ?_ValidateWrite@@YAHPAXI@Z                                   XREF[4]:     FUN_00550180:005501f9(c), 
    //                               _ValidateWrite                                                            FUN_00550180:00550249(c), 
    //                                                                                                         FUN_00550180:005502b5(c), 
    //                                                                                                         FUN_00550180:005502f7(c)  
    //         00557370     MOV        EAX,dword ptr [ESP + param_2]
    //         00557374     MOV        ECX,dword ptr [ESP + param_1]
    //         00557378     PUSH       ESI
    //         00557379     PUSH       EAX
    //         0055737a     PUSH       ECX
    //         0055737b     MOV        ESI,0x1
    //         00557380     CALL       dword ptr [->KERNEL32.DLL::IsBadWritePtr]        = 0048ba22
    //         00557386     TEST       EAX,EAX
    //         00557388     JZ         LAB_0055738c
    //         0055738a     XOR        ESI,ESI
    //                               LAB_0055738c                                                 XREF[1]:     00557388(j)  
    //         0055738c     MOV        EAX,ESI
    //         0055738e     POP        ESI
    //         0055738f     RET
}

// Offset: 0x00557390
int ValidateExecute(_func_int* param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * int __cdecl _ValidateExecute(int (__stdcall*)(void))                                                  *
    //                              *********************************************************************************************************
    //                              int __cdecl _ValidateExecute(_func_int * param_1)
    //              int               EAX:4          <RETURN>
    //              _func_int *       Stack[0x4]:4   param_1                   XREF[1]:     00557390(R)  
    //                               ?_ValidateExecute@@YAHP6GHXZ@Z                               XREF[2]:     FUN_00550180:00550307(c), 
    //                               _ValidateExecute                                                          __CxxUnhandledExceptionFilter:0055
    //         00557390     MOV        EAX,dword ptr [ESP + param_1]
    //         00557394     PUSH       ESI
    //         00557395     PUSH       EAX
    //         00557396     MOV        ESI,0x1
    //         0055739b     CALL       dword ptr [->KERNEL32.DLL::IsBadCodePtr]         = 0048ba32
    //         005573a1     TEST       EAX,EAX
    //         005573a3     JZ         LAB_005573a7
    //         005573a5     XOR        ESI,ESI
    //                               LAB_005573a7                                                 XREF[1]:     005573a3(j)  
    //         005573a7     MOV        EAX,ESI
    //         005573a9     POP        ESI
    //         005573aa     RET
}

// Offset: 0x005573B0
undefined memmove() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * memmove                                                                                               *
    //                              *********************************************************************************************************
    //                              undefined __cdecl memmove()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               _memmove                                                     XREF[4]:     FUN_00550180:00550262(c), 
    //                               memmove                                                                   FUN_00550180:005502db(c), 
    //                                                                                                         FUN_00550b70:00550b8e(c), 
    //                                                                                                         FUN_00554659:005547b6(c)  
    //         005573b0     PUSH       EBP
    //         005573b1     MOV        EBP,ESP
    //         005573b3     PUSH       EDI
    //         005573b4     PUSH       ESI
    //         005573b5     MOV        ESI,dword ptr [EBP + Stack[0x8]]
    //         005573b8     MOV        ECX,dword ptr [EBP + Stack[0xc]]
    //         005573bb     MOV        EDI,dword ptr [EBP + Stack[0x4]]
    //         005573be     MOV        EAX,ECX
    //         005573c0     MOV        EDX,ECX
    //         005573c2     ADD        EAX,ESI
    //         005573c4     CMP        EDI,ESI
    //         005573c6     JBE        LAB_005573d0
    //         005573c8     CMP        EDI,EAX
    //         005573ca     JC         LAB_00557548
    //                               LAB_005573d0                                                 XREF[1]:     005573c6(j)  
    //         005573d0     TEST       EDI,0x3
    //         005573d6     JNZ        LAB_005573ec
    //         005573d8     SHR        ECX,0x2
    //         005573db     AND        EDX,0x3
    //         005573de     CMP        ECX,0x8
    //         005573e1     JC         switchD_0055740c::switchD
    //         005573e3     MOVSD.REP  ES:EDI,ESI
    //                               switchD_005573e5::switchD
    //         005573e5     JMP        dword ptr [EDX*0x4 + switchD_005573e5::switchd   = 00557508
    //                               LAB_005573ec                                                 XREF[1]:     005573d6(j)  
    //         005573ec     MOV        EAX,EDI
    //         005573ee     MOV        EDX,0x3
    //         005573f3     SUB        ECX,0x4
    //         005573f6     JC         switchD_00557404::switchD
    //                               switchD_00557404::default
    //         005573f8     AND        EAX,0x3
    //         005573fb     ADD        ECX,EAX
    //                               switchD_005573fd::switchD
    //         005573fd     JMP        dword ptr [EAX*0x4 + 0x557410]=>00557418-0x4     = 00557420
    //                               switchD_00557404::switchD                                    XREF[1]:     005573f6(j)  
    //         00557404     JMP        dword ptr [ECX*0x4 + 0x557508]
}

// Offset: 0x0055740B
undefined FUN_0055740b() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0055740b()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0055740b
    //         0055740b     NOP
    //                               switchD_0055740c::switchD                                    XREF[4]:     memmove:005573e1(j), 
    //                                                                                                         caseD_1:0055743e(j), 
    //                                                                                                         FUN_00557449:00557464(j), 
    //                                                                                                         FUN_0055746f:0055747e(j)  
    //         0055740c     JMP        dword ptr [ECX*0x4 + switchD_0055740c::switchd   = 005574ef
}

// Offset: 0x00557420
undefined caseD_1() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined caseD_1()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               switchD_005573fd::caseD_1                                    XREF[2]:     memmove:005573fd(j), 00557414(*)  
    //         00557420     AND        EDX,ECX
    //         00557422     MOV        AL,byte ptr [ESI]
    //         00557424     MOV        byte ptr [EDI],AL
    //         00557426     MOV        AL,byte ptr [ESI + 0x1]
    //         00557429     MOV        byte ptr [EDI + 0x1],AL
    //         0055742c     MOV        AL,byte ptr [ESI + 0x2]
    //         0055742f     SHR        ECX,0x2
    //         00557432     MOV        byte ptr [EDI + 0x2],AL
    //         00557435     ADD        ESI,0x3
    //         00557438     ADD        EDI,0x3
    //         0055743b     CMP        ECX,0x8
    //         0055743e     JC         switchD_0055740c::switchD
    //         00557440     MOVSD.REP  ES:EDI,ESI
    //                               switchD_00557442::switchD
    //         00557442     JMP        dword ptr [EDX*0x4 + switchD_005573e5::switchd   = 00557508
}

// Offset: 0x00557449
undefined FUN_00557449() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00557449()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00557449
    //         00557449     MOV        EAX,EAX
    //                               switchD_005573fd::caseD_2                                    XREF[2]:     memmove:005573fd(j), 00557418(*)  
    //         0055744c     AND        EDX,ECX
    //         0055744e     MOV        AL,byte ptr [ESI]
    //         00557450     MOV        byte ptr [EDI],AL
    //         00557452     MOV        AL,byte ptr [ESI + 0x1]
    //         00557455     SHR        ECX,0x2
    //         00557458     MOV        byte ptr [EDI + 0x1],AL
    //         0055745b     ADD        ESI,0x2
    //         0055745e     ADD        EDI,0x2
    //         00557461     CMP        ECX,0x8
    //         00557464     JC         switchD_0055740c::switchD
    //         00557466     MOVSD.REP  ES:EDI,ESI
    //                               switchD_00557468::switchD
    //         00557468     JMP        dword ptr [EDX*0x4 + switchD_005573e5::switchd   = 00557508
}

// Offset: 0x0055746F
undefined FUN_0055746f() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0055746f()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0055746f
    //         0055746f     NOP
    //                               switchD_005573fd::caseD_3                                    XREF[2]:     memmove:005573fd(j), 0055741c(*)  
    //         00557470     AND        EDX,ECX
    //         00557472     MOV        AL,byte ptr [ESI]
    //         00557474     MOV        byte ptr [EDI],AL
    //         00557476     INC        ESI
    //         00557477     SHR        ECX,0x2
    //         0055747a     INC        EDI
    //         0055747b     CMP        ECX,0x8
    //         0055747e     JC         switchD_0055740c::switchD
    //         00557480     MOVSD.REP  ES:EDI,ESI
    //                               switchD_00557482::switchD
    //         00557482     JMP        dword ptr [EDX*0x4 + switchD_005573e5::switchd   = 00557508
}

// Offset: 0x00557489
undefined FUN_00557489() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00557489()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00557489
    //         00557489     MOV        EAX,EAX
    //                               switchD_0055740c::switchdataD_0055748c                       XREF[1]:     FUN_0055740b:0055740c(*)  
}

// Offset: 0x005574F6
undefined FUN_005574f6() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_005574f6()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_005574f6
    //         005574f6     MOV        EAX,EAX
    //                               switchD_005573e5::switchdataD_005574f8                       XREF[5]:     memmove:005573e5(*), 
    //                                                                                                         caseD_1:00557442(*), 
    //                                                                                                         FUN_00557449:00557468(*), 
    //                                                                                                         FUN_0055746f:00557482(*), 
    //                                                                                                         FUN_0055746f:005574ef(*)  
}

// Offset: 0x00557508
undefined caseD_0() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined caseD_0()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               switchD_005574ef::caseD_0                                    XREF[7]:     memmove:005573e5(j), 
    //                               switchD_00557482::caseD_0                                                 memmove:00557404(j), 
    //                               switchD_00557468::caseD_0                                                 caseD_1:00557442(j), 
    //                               switchD_00557442::caseD_0                                                 FUN_00557449:00557468(j), 
    //                               switchD_00557404::caseD_0                                                 FUN_0055746f:00557482(j), 
    //                               switchD_005573e5::caseD_0                                                 FUN_0055746f:005574ef(j), 
    //                                                                                                         005574f8(*)  
    //         00557508     MOV        EAX,dword ptr [EBP + 0x8]
    //         0055750b     POP        ESI
    //         0055750c     POP        EDI
    //         0055750d     LEAVE
    //         0055750e     RET
}

// Offset: 0x0055750F
undefined FUN_0055750f() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0055750f()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0055750f
    //         0055750f     NOP
    //                               switchD_00557404::caseD_1                                    XREF[7]:     memmove:005573e5(j), 
    //                               switchD_005574ef::caseD_1                                                 memmove:00557404(j), 
    //                               switchD_00557482::caseD_1                                                 caseD_1:00557442(j), 
    //                               switchD_00557468::caseD_1                                                 FUN_00557449:00557468(j), 
    //                               switchD_00557442::caseD_1                                                 FUN_0055746f:00557482(j), 
    //                               switchD_005573e5::caseD_1                                                 FUN_0055746f:005574ef(j), 
    //                                                                                                         005574fc(*)  
    //         00557510     MOV        AL,byte ptr [ESI]
    //         00557512     MOV        byte ptr [EDI],AL
    //         00557514     MOV        EAX,dword ptr [EBP + 0x8]
    //         00557517     POP        ESI
    //         00557518     POP        EDI
    //         00557519     LEAVE
    //         0055751a     RET
}

// Offset: 0x0055751B
undefined FUN_0055751b() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0055751b()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0055751b
    //         0055751b     NOP
    //                               switchD_00557404::caseD_2                                    XREF[7]:     memmove:005573e5(j), 
    //                               switchD_005574ef::caseD_2                                                 memmove:00557404(j), 
    //                               switchD_00557482::caseD_2                                                 caseD_1:00557442(j), 
    //                               switchD_00557468::caseD_2                                                 FUN_00557449:00557468(j), 
    //                               switchD_00557442::caseD_2                                                 FUN_0055746f:00557482(j), 
    //                               switchD_005573e5::caseD_2                                                 FUN_0055746f:005574ef(j), 
    //                                                                                                         00557500(*)  
    //         0055751c     MOV        AL,byte ptr [ESI]
    //         0055751e     MOV        byte ptr [EDI],AL
    //         00557520     MOV        AL,byte ptr [ESI + 0x1]
    //         00557523     MOV        byte ptr [EDI + 0x1],AL
    //         00557526     MOV        EAX,dword ptr [EBP + 0x8]
    //         00557529     POP        ESI
    //         0055752a     POP        EDI
    //         0055752b     LEAVE
    //         0055752c     RET
}

// Offset: 0x0055752D
undefined FUN_0055752d() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0055752d()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0055752d
    //         0055752d     MOV        EAX,EAX
    //                               switchD_00557404::caseD_3                                    XREF[7]:     memmove:005573e5(j), 
    //                               switchD_005574ef::caseD_3                                                 memmove:00557404(j), 
    //                               switchD_00557482::caseD_3                                                 caseD_1:00557442(j), 
    //                               switchD_00557468::caseD_3                                                 FUN_00557449:00557468(j), 
    //                               switchD_00557442::caseD_3                                                 FUN_0055746f:00557482(j), 
    //                               switchD_005573e5::caseD_3                                                 FUN_0055746f:005574ef(j), 
    //                                                                                                         00557504(*)  
    //         00557530     MOV        AL,byte ptr [ESI]
    //         00557532     MOV        byte ptr [EDI],AL
    //         00557534     MOV        AL,byte ptr [ESI + 0x1]
    //         00557537     MOV        byte ptr [EDI + 0x1],AL
    //         0055753a     MOV        AL,byte ptr [ESI + 0x2]
    //         0055753d     MOV        byte ptr [EDI + 0x2],AL
    //         00557540     MOV        EAX,dword ptr [EBP + 0x8]
    //         00557543     POP        ESI
    //         00557544     POP        EDI
    //         00557545     LEAVE
    //         00557546     RET
}

// Offset: 0x00557547
undefined FUN_00557547() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00557547()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00557547
    //         00557547     NOP
    //                               LAB_00557548                                                 XREF[1]:     memmove:005573ca(j)  
    //         00557548     LEA        ESI,[ECX + ESI*0x1 + -0x4]
    //         0055754c     LEA        EDI,[ECX + EDI*0x1 + -0x4]
    //         00557550     TEST       EDI,0x3
    //         00557556     JNZ        LAB_0055757c
    //         00557558     SHR        ECX,0x2
    //         0055755b     AND        EDX,0x3
    //         0055755e     CMP        ECX,0x8
    //         00557561     JC         LAB_00557570
    //         00557563     STD
    //         00557564     MOVSD.REP  ES:EDI,ESI
    //         00557566     CLD
    //                               switchD_00557567::switchD
    //         00557567     JMP        dword ptr [EDX*0x4 + switchD_00557567::switchd   = 005576a0
}

// Offset: 0x0055756E
undefined FUN_0055756e() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0055756e()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0055756e
    //         0055756e     MOV        EAX,EAX
    //                               LAB_00557570                                                 XREF[4]:     FUN_00557547:00557561(j), 
    //                                                                                                         caseD_1:005575b8(j), 
    //                                                                                                         FUN_005575c5:005575e2(j), 
    //                                                                                                         FUN_005575ef:00557610(j)  
    //         00557570     NEG        ECX
    //                               switchD_00557572::switchD
    //         00557572     JMP        dword ptr [ECX*0x4 + PTR_caseD_0_00557640]       = 00557687
}

// Offset: 0x00557579
undefined FUN_00557579() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00557579()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00557579
    //         00557579     MOV        EAX,EAX
    //                               LAB_0055757c                                                 XREF[1]:     FUN_00557547:00557556(j)  
    //         0055757c     MOV        EAX,EDI
    //         0055757e     MOV        EDX,0x3
    //         00557583     CMP        ECX,0x4
    //         00557586     JC         switchD_00557594::switchD
    //                               switchD_00557594::default
    //         00557588     AND        EAX,0x3
    //         0055758b     SUB        ECX,EAX
    //                               switchD_0055758d::switchD
    //         0055758d     JMP        dword ptr [EAX*0x4 + 0x557598]=>005575a0-0x4     = 005575a8
    //                               switchD_00557594::switchD                                    XREF[1]:     00557586(j)  
    //         00557594     JMP        dword ptr [ECX*0x4 + switchD_00557567::switchd   = 005576a0
}

// Offset: 0x005575A8
undefined caseD_1() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined caseD_1()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               switchD_0055758d::caseD_1                                    XREF[2]:     FUN_00557579:0055758d(j), 
    //                                                                                                         0055759c(*)  
    //         005575a8     MOV        AL,byte ptr [ESI + 0x3]
    //         005575ab     AND        EDX,ECX
    //         005575ad     MOV        byte ptr [EDI + 0x3],AL
    //         005575b0     DEC        ESI
    //         005575b1     SHR        ECX,0x2
    //         005575b4     DEC        EDI
    //         005575b5     CMP        ECX,0x8
    //         005575b8     JC         LAB_00557570
    //         005575ba     STD
    //         005575bb     MOVSD.REP  ES:EDI,ESI=>DAT_fffffffb
    //         005575bd     CLD
    //                               switchD_005575be::switchD
    //         005575be     JMP        dword ptr [EDX*0x4 + switchD_00557567::switchd   = 005576a0
}

// Offset: 0x005575C5
undefined FUN_005575c5() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_005575c5()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_005575c5
    //         005575c5     MOV        EAX,EAX
    //                               switchD_0055758d::caseD_2                                    XREF[2]:     FUN_00557579:0055758d(j), 
    //                                                                                                         005575a0(*)  
    //         005575c8     MOV        AL,byte ptr [ESI + 0x3]
    //         005575cb     AND        EDX,ECX
    //         005575cd     MOV        byte ptr [EDI + 0x3],AL
    //         005575d0     MOV        AL,byte ptr [ESI + 0x2]
    //         005575d3     SHR        ECX,0x2
    //         005575d6     MOV        byte ptr [EDI + 0x2],AL
    //         005575d9     SUB        ESI,0x2
    //         005575dc     SUB        EDI,0x2
    //         005575df     CMP        ECX,0x8
    //         005575e2     JC         LAB_00557570
    //         005575e4     STD
    //         005575e5     MOVSD.REP  ES:EDI,ESI=>DAT_fffffffa
    //         005575e7     CLD
    //                               switchD_005575e8::switchD
    //         005575e8     JMP        dword ptr [EDX*0x4 + switchD_00557567::switchd   = 005576a0
}

// Offset: 0x005575EF
undefined FUN_005575ef() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_005575ef()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_005575ef
    //         005575ef     NOP
    //                               switchD_0055758d::caseD_3                                    XREF[2]:     FUN_00557579:0055758d(j), 
    //                                                                                                         005575a4(*)  
    //         005575f0     MOV        AL,byte ptr [ESI + 0x3]
    //         005575f3     AND        EDX,ECX
    //         005575f5     MOV        byte ptr [EDI + 0x3],AL
    //         005575f8     MOV        AL,byte ptr [ESI + 0x2]
    //         005575fb     MOV        byte ptr [EDI + 0x2],AL
    //         005575fe     MOV        AL,byte ptr [ESI + 0x1]
    //         00557601     SHR        ECX,0x2
    //         00557604     MOV        byte ptr [EDI + 0x1],AL
    //         00557607     SUB        ESI,0x3
    //         0055760a     SUB        EDI,0x3
    //         0055760d     CMP        ECX,0x8
    //         00557610     JC         LAB_00557570
    //         00557616     STD
    //         00557617     MOVSD.REP  ES:EDI,ESI=>DAT_fffffff9
    //         00557619     CLD
    //                               switchD_0055761a::switchD
    //         0055761a     JMP        dword ptr [EDX*0x4 + switchD_00557567::switchd   = 005576a0
}

// Offset: 0x00557621
undefined FUN_00557621() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00557621()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00557621
    //         00557621     MOV        EAX,EAX
    //                               switchD_00557572::switchdataD_00557624
}

// Offset: 0x0055768E
undefined FUN_0055768e() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0055768e()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0055768e
    //         0055768e     MOV        EAX,EAX
    //                               switchD_00557567::switchdataD_00557690                       XREF[6]:     FUN_00557547:00557567(*), 
    //                                                                                                         FUN_00557579:00557594(*), 
    //                                                                                                         caseD_1:005575be(*), 
    //                                                                                                         FUN_005575c5:005575e8(*), 
    //                                                                                                         FUN_005575ef:0055761a(*), 
    //                                                                                                         FUN_005575ef:00557687(*)  
}

// Offset: 0x005576A0
undefined caseD_0() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined caseD_0()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               switchD_00557687::caseD_0                                    XREF[7]:     FUN_00557547:00557567(j), 
    //                               switchD_0055761a::caseD_0                                                 FUN_00557579:00557594(j), 
    //                               switchD_005575e8::caseD_0                                                 caseD_1:005575be(j), 
    //                               switchD_005575be::caseD_0                                                 FUN_005575c5:005575e8(j), 
    //                               switchD_00557594::caseD_0                                                 FUN_005575ef:0055761a(j), 
    //                               switchD_00557567::caseD_0                                                 FUN_005575ef:00557687(j), 
    //                                                                                                         00557690(*)  
    //         005576a0     MOV        EAX,dword ptr [EBP + 0x8]
    //         005576a3     POP        ESI
    //         005576a4     POP        EDI
    //         005576a5     LEAVE
    //         005576a6     RET
}

// Offset: 0x005576A7
undefined FUN_005576a7() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_005576a7()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_005576a7
    //         005576a7     NOP
    //                               switchD_00557594::caseD_1                                    XREF[7]:     FUN_00557547:00557567(j), 
    //                               switchD_00557687::caseD_1                                                 FUN_00557579:00557594(j), 
    //                               switchD_0055761a::caseD_1                                                 caseD_1:005575be(j), 
    //                               switchD_005575e8::caseD_1                                                 FUN_005575c5:005575e8(j), 
    //                               switchD_005575be::caseD_1                                                 FUN_005575ef:0055761a(j), 
    //                               switchD_00557567::caseD_1                                                 FUN_005575ef:00557687(j), 
    //                                                                                                         00557694(*)  
    //         005576a8     MOV        AL,byte ptr [ESI + 0x3]
    //         005576ab     MOV        byte ptr [EDI + 0x3],AL
    //         005576ae     MOV        EAX,dword ptr [EBP + 0x8]
    //         005576b1     POP        ESI
    //         005576b2     POP        EDI
    //         005576b3     LEAVE
    //         005576b4     RET
}

// Offset: 0x005576B5
undefined FUN_005576b5() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_005576b5()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_005576b5
    //         005576b5     MOV        EAX,EAX
    //                               switchD_00557594::caseD_2                                    XREF[7]:     FUN_00557547:00557567(j), 
    //                               switchD_00557687::caseD_2                                                 FUN_00557579:00557594(j), 
    //                               switchD_0055761a::caseD_2                                                 caseD_1:005575be(j), 
    //                               switchD_005575e8::caseD_2                                                 FUN_005575c5:005575e8(j), 
    //                               switchD_005575be::caseD_2                                                 FUN_005575ef:0055761a(j), 
    //                               switchD_00557567::caseD_2                                                 FUN_005575ef:00557687(j), 
    //                                                                                                         00557698(*)  
    //         005576b8     MOV        AL,byte ptr [ESI + 0x3]
    //         005576bb     MOV        byte ptr [EDI + 0x3],AL
    //         005576be     MOV        AL,byte ptr [ESI + 0x2]=>DAT_fffffffb
    //         005576c1     MOV        byte ptr [EDI + 0x2],AL=>DAT_fffffffb
    //         005576c4     MOV        EAX,dword ptr [EBP + 0x8]
    //         005576c7     POP        ESI
    //         005576c8     POP        EDI
    //         005576c9     LEAVE
    //         005576ca     RET
}

// Offset: 0x005576CB
undefined FUN_005576cb() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_005576cb()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_005576cb
    //         005576cb     NOP
    //                               switchD_00557594::caseD_3                                    XREF[7]:     FUN_00557547:00557567(j), 
    //                               switchD_00557687::caseD_3                                                 FUN_00557579:00557594(j), 
    //                               switchD_0055761a::caseD_3                                                 caseD_1:005575be(j), 
    //                               switchD_005575e8::caseD_3                                                 FUN_005575c5:005575e8(j), 
    //                               switchD_005575be::caseD_3                                                 FUN_005575ef:0055761a(j), 
    //                               switchD_00557567::caseD_3                                                 FUN_005575ef:00557687(j), 
    //                                                                                                         0055769c(*)  
    //         005576cc     MOV        AL,byte ptr [ESI + 0x3]
    //         005576cf     MOV        byte ptr [EDI + 0x3],AL
    //         005576d2     MOV        AL,byte ptr [ESI + 0x2]=>DAT_fffffffb
    //         005576d5     MOV        byte ptr [EDI + 0x2],AL=>DAT_fffffffb
    //         005576d8     MOV        AL,byte ptr [ESI + 0x1]=>DAT_fffffffa
    //         005576db     MOV        byte ptr [EDI + 0x1],AL=>DAT_fffffffa
    //         005576de     MOV        EAX,dword ptr [EBP + 0x8]
    //         005576e1     POP        ESI
    //         005576e2     POP        EDI
    //         005576e3     LEAVE
    //         005576e4     RET
}

// Offset: 0x005576F0
undefined abort() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * abort                                                                                                 *
    //                              *********************************************************************************************************
    //                              undefined __cdecl abort()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               _abort                                                       XREF[1]:     FUN_005504fe:005504fe(c)  
    //                               abort
    //         005576f0     PUSH       0xa
    //         005576f2     CALL       __NMSG_WRITE                                     undefined __NMSG_WRITE()
    //         005576f7     ADD        ESP,0x4
    //         005576fa     PUSH       0x16
    //         005576fc     CALL       raise                                            undefined raise()
    //         00557701     ADD        ESP,0x4
    //         00557704     PUSH       0x3
    //         00557706     CALL       __exit                                           undefined __exit()
    //         0055770b     ADD        ESP,0x4
    //         0055770e     RET
}

// Offset: 0x00557710
undefined statusfp() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined __statusfp()
    //              undefined         <UNASSIGNED>   <RETURN>
    //              undefined4        Stack[-0x8]:4  local_8                   XREF[2]:     00557714(W), 00557718(R)  
    //                               __statusfp
    //         00557710     PUSH       EBP
    //         00557711     MOV        EBP,ESP
    //         00557713     PUSH       ECX
    //         00557714     FSTSW      word ptr [EBP + local_8]
    //         00557718     MOV        EAX,dword ptr [EBP + local_8]
    //         0055771b     PUSH       EAX
    //         0055771c     CALL       FUN_00557910                                     undefined FUN_00557910()
    //         00557721     ADD        ESP,0x4
    //         00557724     MOV        ESP,EBP
    //         00557726     POP        EBP
    //         00557727     RET
}

// Offset: 0x00557730
undefined clearfp() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined __clearfp()
    //              undefined         <UNASSIGNED>   <RETURN>
    //              undefined4        Stack[-0x8]:4  local_8                   XREF[2]:     00557734(W), 00557739(R)  
    //                               __clearfp
    //         00557730     PUSH       EBP
    //         00557731     MOV        EBP,ESP
    //         00557733     PUSH       ECX
    //         00557734     FNSTSW     word ptr [EBP + local_8]
    //         00557737     FNCLEX
    //         00557739     MOV        EAX,dword ptr [EBP + local_8]
    //         0055773c     PUSH       EAX
    //         0055773d     CALL       FUN_00557910                                     undefined FUN_00557910()
    //         00557742     ADD        ESP,0x4
    //         00557745     MOV        ESP,EBP
    //         00557747     POP        EBP
    //         00557748     RET
}

// Offset: 0x00557750
undefined control87() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined __control87()
    //              undefined         <UNASSIGNED>   <RETURN>
    //              undefined4        Stack[-0x8]:4  local_8                   XREF[2]:     00557755(W), 00557759(R)  
    //                               __control87                                                  XREF[1]:     __controlfp:0055779f(c)  
    //         00557750     PUSH       EBP
    //         00557751     MOV        EBP,ESP
    //         00557753     PUSH       ECX
    //         00557754     PUSH       ESI
    //         00557755     FSTCW      word ptr [EBP + local_8]
    //         00557759     MOV        EAX,dword ptr [EBP + local_8]
    //         0055775c     PUSH       EAX
    //         0055775d     CALL       FUN_005577e0                                     undefined FUN_005577e0()
    //         00557762     MOV        ECX,dword ptr [EBP + Stack[0x8]]
    //         00557765     MOV        EDX,dword ptr [EBP + Stack[0x4]]
    //         00557768     MOV        ESI,ECX
    //         0055776a     ADD        ESP,0x4
    //         0055776d     NOT        ECX
    //         0055776f     AND        ESI,EDX
    //         00557771     AND        ECX,EAX
    //         00557773     OR         ESI,ECX
    //         00557775     PUSH       ESI
    //         00557776     CALL       FUN_00557880                                     undefined FUN_00557880()
    //         0055777b     ADD        ESP,0x4
    //         0055777e     MOV        dword ptr [EBP + Stack[0x8]],EAX
    //         00557781     FLDCW      word ptr [EBP + Stack[0x8]]
    //         00557784     MOV        EAX,ESI
    //         00557786     POP        ESI
    //         00557787     MOV        ESP,EBP
    //         00557789     POP        EBP
    //         0055778a     RET
}

// Offset: 0x00557790
undefined controlfp() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined __controlfp()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               __controlfp                                                  XREF[1]:     __setdefaultprecision:005505ca(c)  
    //         00557790     MOV        EAX,dword ptr [ESP + Stack[0x8]]
    //         00557794     MOV        ECX,dword ptr [ESP + Stack[0x4]]
    //         00557798     AND        EAX,0xfff7ffff
    //         0055779d     PUSH       EAX
    //         0055779e     PUSH       ECX
    //         0055779f     CALL       __control87                                      undefined __control87()
    //         005577a4     ADD        ESP,0x8
    //         005577a7     RET
}

// Offset: 0x005577A8
undefined FUN_005577a8() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_005577a8()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_005577a8
    //         005577a8     NOP
    //         005577a9     NOP
    //         005577aa     NOP
    //         005577ab     NOP
    //         005577ac     NOP
    //         005577ad     NOP
    //         005577ae     NOP
    //         005577af     NOP
    //                               __fpreset
    //         005577b0     PUSH       ESI
    //         005577b1     MOV        ESI,dword ptr [__pxcptinfoptrs]
    //         005577b7     FNINIT
    //         005577b9     CALL       __setdefaultprecision                            undefined __setdefaultprecision()
    //         005577be     TEST       ESI,ESI
    //         005577c0     JZ         LAB_005577db
    //         005577c2     MOV        EAX,dword ptr [ESI + 0x4]
    //         005577c5     TEST       dword ptr [EAX],0x10008
    //         005577cb     JZ         LAB_005577db
    //         005577cd     MOV        dword ptr [EAX + 0x20],0x0
    //         005577d4     MOV        dword ptr [EAX + 0x24],0xffff
    //                               LAB_005577db                                                 XREF[2]:     005577c0(j), 005577cb(j)  
    //         005577db     POP        ESI
    //         005577dc     RET
}

// Offset: 0x005577E0
undefined FUN_005577e0() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_005577e0()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_005577e0                                                 XREF[1]:     __control87:0055775d(c)  
    //         005577e0     PUSH       EBX
    //         005577e1     MOV        EBX,dword ptr [ESP + Stack[0x4]]
    //         005577e5     XOR        EAX,EAX
    //         005577e7     TEST       BL,0x1
    //         005577ea     JZ         LAB_005577f1
    //         005577ec     MOV        EAX,0x10
    //                               LAB_005577f1                                                 XREF[1]:     005577ea(j)  
    //         005577f1     TEST       BL,0x4
    //         005577f4     JZ         LAB_005577f8
    //         005577f6     OR         AL,0x8
    //                               LAB_005577f8                                                 XREF[1]:     005577f4(j)  
    //         005577f8     TEST       BL,0x8
    //         005577fb     JZ         LAB_005577ff
    //         005577fd     OR         AL,0x4
    //                               LAB_005577ff                                                 XREF[1]:     005577fb(j)  
    //         005577ff     TEST       BL,0x10
    //         00557802     JZ         LAB_00557806
    //         00557804     OR         AL,0x2
    //                               LAB_00557806                                                 XREF[1]:     00557802(j)  
    //         00557806     TEST       BL,0x20
    //         00557809     JZ         LAB_0055780d
    //         0055780b     OR         AL,0x1
    //                               LAB_0055780d                                                 XREF[1]:     00557809(j)  
    //         0055780d     TEST       BL,0x2
    //         00557810     JZ         LAB_00557817
    //         00557812     OR         EAX,0x80000
    //                               LAB_00557817                                                 XREF[1]:     00557810(j)  
    //         00557817     MOV        EDX,EBX
    //         00557819     AND        EDX,0xffff
    //         0055781f     MOV        ECX,EDX
    //         00557821     AND        ECX,0xc00
    //         00557827     CMP        ECX,0x400
    //         0055782d     JG         LAB_00557836
    //         0055782f     JNZ        LAB_0055784e
    //         00557831     OR         AH,0x1
    //         00557834     JMP        LAB_0055784e
    //                               LAB_00557836                                                 XREF[1]:     0055782d(j)  
    //         00557836     CMP        ECX,0x800
    //         0055783c     JZ         LAB_0055784b
    //         0055783e     CMP        ECX,0xc00
    //         00557844     JNZ        LAB_0055784e
    //         00557846     OR         AH,0x3
    //         00557849     JMP        LAB_0055784e
    //                               LAB_0055784b                                                 XREF[1]:     0055783c(j)  
    //         0055784b     OR         AH,0x2
    //                               LAB_0055784e                                                 XREF[4]:     0055782f(j), 00557834(j), 
    //                                                                                                         00557844(j), 00557849(j)  
    //         0055784e     AND        EDX,0x300
    //         00557854     JZ         LAB_00557865
    //         00557856     CMP        EDX,0x200
    //         0055785c     JNZ        LAB_0055786a
    //         0055785e     OR         EAX,0x10000
    //         00557863     JMP        LAB_0055786a
    //                               LAB_00557865                                                 XREF[1]:     00557854(j)  
    //         00557865     OR         EAX,0x20000
    //                               LAB_0055786a                                                 XREF[2]:     0055785c(j), 00557863(j)  
    //         0055786a     TEST       BH,0x10
    //         0055786d     JZ         LAB_00557874
    //         0055786f     OR         EAX,0x40000
    //                               LAB_00557874                                                 XREF[1]:     0055786d(j)  
    //         00557874     POP        EBX
    //         00557875     RET
}

// Offset: 0x00557880
undefined FUN_00557880() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00557880()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00557880                                                 XREF[1]:     __control87:00557776(c)  
    //         00557880     MOV        EDX,dword ptr [ESP + Stack[0x4]]
    //         00557884     XOR        EAX,EAX
    //         00557886     TEST       DL,0x10
    //         00557889     JZ         LAB_00557890
    //         0055788b     MOV        EAX,0x1
    //                               LAB_00557890                                                 XREF[1]:     00557889(j)  
    //         00557890     TEST       DL,0x8
    //         00557893     JZ         LAB_00557897
    //         00557895     OR         AL,0x4
    //                               LAB_00557897                                                 XREF[1]:     00557893(j)  
    //         00557897     TEST       DL,0x4
    //         0055789a     JZ         LAB_0055789e
    //         0055789c     OR         AL,0x8
    //                               LAB_0055789e                                                 XREF[1]:     0055789a(j)  
    //         0055789e     TEST       DL,0x2
    //         005578a1     JZ         LAB_005578a5
    //         005578a3     OR         AL,0x10
    //                               LAB_005578a5                                                 XREF[1]:     005578a1(j)  
    //         005578a5     TEST       DL,0x1
    //         005578a8     JZ         LAB_005578ac
    //         005578aa     OR         AL,0x20
    //                               LAB_005578ac                                                 XREF[1]:     005578a8(j)  
    //         005578ac     TEST       EDX,0x80000
    //         005578b2     JZ         LAB_005578b6
    //         005578b4     OR         AL,0x2
    //                               LAB_005578b6                                                 XREF[1]:     005578b2(j)  
    //         005578b6     MOV        ECX,EDX
    //         005578b8     AND        ECX,0x300
    //         005578be     CMP        ECX,0x100
    //         005578c4     JA         LAB_005578cd
    //         005578c6     JNZ        LAB_005578e5
    //         005578c8     OR         AH,0x4
    //         005578cb     JMP        LAB_005578e5
    //                               LAB_005578cd                                                 XREF[1]:     005578c4(j)  
    //         005578cd     CMP        ECX,0x200
    //         005578d3     JZ         LAB_005578e2
    //         005578d5     CMP        ECX,0x300
    //         005578db     JNZ        LAB_005578e5
    //         005578dd     OR         AH,0xc
    //         005578e0     JMP        LAB_005578e5
    //                               LAB_005578e2                                                 XREF[1]:     005578d3(j)  
    //         005578e2     OR         AH,0x8
    //                               LAB_005578e5                                                 XREF[4]:     005578c6(j), 005578cb(j), 
    //                                                                                                         005578db(j), 005578e0(j)  
    //         005578e5     MOV        ECX,EDX
    //         005578e7     AND        ECX,0x30000
    //         005578ed     JZ         LAB_005578fc
    //         005578ef     CMP        ECX,0x10000
    //         005578f5     JNZ        LAB_005578ff
    //         005578f7     OR         AH,0x2
    //         005578fa     JMP        LAB_005578ff
    //                               LAB_005578fc                                                 XREF[1]:     005578ed(j)  
    //         005578fc     OR         AH,0x3
    //                               LAB_005578ff                                                 XREF[2]:     005578f5(j), 005578fa(j)  
    //         005578ff     TEST       EDX,0x40000
    //         00557905     JZ         LAB_0055790a
    //         00557907     OR         AH,0x10
    //                               LAB_0055790a                                                 XREF[1]:     00557905(j)  
    //         0055790a     RET
}

// Offset: 0x00557910
undefined FUN_00557910() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00557910()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00557910                                                 XREF[2]:     __statusfp:0055771c(c), 
    //                                                                                                         __clearfp:0055773d(c)  
    //         00557910     MOV        CL,byte ptr [ESP + Stack[0x4]]
    //         00557914     XOR        EAX,EAX
    //         00557916     TEST       CL,0x1
    //         00557919     JZ         LAB_00557920
    //         0055791b     MOV        EAX,0x10
    //                               LAB_00557920                                                 XREF[1]:     00557919(j)  
    //         00557920     TEST       CL,0x4
    //         00557923     JZ         LAB_00557927
    //         00557925     OR         AL,0x8
    //                               LAB_00557927                                                 XREF[1]:     00557923(j)  
    //         00557927     TEST       CL,0x8
    //         0055792a     JZ         LAB_0055792e
    //         0055792c     OR         AL,0x4
    //                               LAB_0055792e                                                 XREF[1]:     0055792a(j)  
    //         0055792e     TEST       CL,0x10
    //         00557931     JZ         LAB_00557935
    //         00557933     OR         AL,0x2
    //                               LAB_00557935                                                 XREF[1]:     00557931(j)  
    //         00557935     TEST       CL,0x20
    //         00557938     JZ         LAB_0055793c
    //         0055793a     OR         AL,0x1
    //                               LAB_0055793c                                                 XREF[1]:     00557938(j)  
    //         0055793c     TEST       CL,0x2
    //         0055793f     JZ         LAB_00557946
    //         00557941     OR         EAX,0x80000
    //                               LAB_00557946                                                 XREF[1]:     0055793f(j)  
    //         00557946     RET
}

// Offset: 0x00557950
undefined ZeroTail() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined __ZeroTail()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               __ZeroTail                                                   XREF[1]:     __RoundMan:00557a80(c)  
    //         00557950     MOV        ECX,dword ptr [ESP + Stack[0x8]]
    //         00557954     PUSH       ESI
    //         00557955     MOV        EAX,ECX
    //         00557957     CDQ
    //         00557958     AND        EDX,0x1f
    //         0055795b     ADD        EAX,EDX
    //         0055795d     MOV        ESI,EAX
    //         0055795f     MOV        EAX,ECX
    //         00557961     CDQ
    //         00557962     XOR        EAX,EDX
    //         00557964     MOV        ECX,0x1f
    //         00557969     SUB        EAX,EDX
    //         0055796b     AND        EAX,0x1f
    //         0055796e     XOR        EAX,EDX
    //         00557970     SUB        EAX,EDX
    //         00557972     OR         EDX,0xffffffff
    //         00557975     SUB        ECX,EAX
    //         00557977     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         0055797b     SHL        EDX,CL
    //         0055797d     SAR        ESI,0x5
    //         00557980     MOV        ECX,dword ptr [EAX + ESI*0x4]
    //         00557983     NOT        EDX
    //         00557985     TEST       ECX,EDX
    //         00557987     JZ         LAB_0055798d
    //         00557989     XOR        EAX,EAX
    //         0055798b     POP        ESI
    //         0055798c     RET
    //                               LAB_0055798d                                                 XREF[1]:     00557987(j)  
    //         0055798d     INC        ESI
    //         0055798e     CMP        ESI,0x3
    //         00557991     JGE        LAB_005579af
    //         00557993     LEA        EAX,[EAX + ESI*0x4]
    //                               LAB_00557996                                                 XREF[1]:     005579a2(j)  
    //         00557996     CMP        dword ptr [EAX],0x0
    //         00557999     JNZ        LAB_005579ab
    //         0055799b     INC        ESI
    //         0055799c     ADD        EAX,0x4
    //         0055799f     CMP        ESI,0x3
    //         005579a2     JL         LAB_00557996
    //         005579a4     MOV        EAX,0x1
    //         005579a9     POP        ESI
    //         005579aa     RET
    //                               LAB_005579ab                                                 XREF[1]:     00557999(j)  
    //         005579ab     XOR        EAX,EAX
    //         005579ad     POP        ESI
    //         005579ae     RET
    //                               LAB_005579af                                                 XREF[1]:     00557991(j)  
    //         005579af     MOV        EAX,0x1
    //         005579b4     POP        ESI
    //         005579b5     RET
}

// Offset: 0x005579C0
undefined IncMan() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined __IncMan()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               __IncMan                                                     XREF[1]:     __RoundMan:00557a92(c)  
    //         005579c0     MOV        ECX,dword ptr [ESP + Stack[0x8]]
    //         005579c4     PUSH       EBX
    //         005579c5     MOV        EAX,ECX
    //         005579c7     PUSH       ESI
    //         005579c8     CDQ
    //         005579c9     AND        EDX,0x1f
    //         005579cc     MOV        EBX,dword ptr [ESP + Stack[0x4]]
    //         005579d0     ADD        EAX,EDX
    //         005579d2     PUSH       EDI
    //         005579d3     MOV        ESI,EAX
    //         005579d5     MOV        EAX,ECX
    //         005579d7     CDQ
    //         005579d8     XOR        EAX,EDX
    //         005579da     MOV        ECX,0x1f
    //         005579df     SUB        EAX,EDX
    //         005579e1     AND        EAX,0x1f
    //         005579e4     XOR        EAX,EDX
    //         005579e6     SUB        EAX,EDX
    //         005579e8     SUB        ECX,EAX
    //         005579ea     MOV        EAX,0x1
    //         005579ef     SAR        ESI,0x5
    //         005579f2     SHL        EAX,CL
    //         005579f4     MOV        ECX,dword ptr [EBX + ESI*0x4]
    //         005579f7     LEA        EDI,[EBX + ESI*0x4]
    //         005579fa     PUSH       EDI
    //         005579fb     PUSH       EAX
    //         005579fc     PUSH       ECX
    //         005579fd     CALL       ___addl                                          undefined ___addl()
    //         00557a02     ADD        ESP,0xc
    //         00557a05     DEC        ESI
    //         00557a06     JS         LAB_00557a25
    //         00557a08     LEA        EDI,[EBX + ESI*0x4]
    //                               LAB_00557a0b                                                 XREF[1]:     00557a23(j)  
    //         00557a0b     TEST       EAX,EAX
    //         00557a0d     JZ         LAB_00557a25
    //         00557a0f     MOV        EDX,dword ptr [EDI]
    //         00557a11     PUSH       EDI
    //         00557a12     PUSH       0x1
    //         00557a14     PUSH       EDX
    //         00557a15     CALL       ___addl                                          undefined ___addl()
    //         00557a1a     ADD        ESP,0xc
    //         00557a1d     DEC        ESI
    //         00557a1e     SUB        EDI,0x4
    //         00557a21     TEST       ESI,ESI
    //         00557a23     JGE        LAB_00557a0b
    //                               LAB_00557a25                                                 XREF[2]:     00557a06(j), 00557a0d(j)  
    //         00557a25     POP        EDI
    //         00557a26     POP        ESI
    //         00557a27     POP        EBX
    //         00557a28     RET
}

// Offset: 0x00557A30
undefined RoundMan() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined __RoundMan()
    //              undefined         <UNASSIGNED>   <RETURN>
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     00557a52(W), 00557a9e(R)  
    //                               __RoundMan                                                   XREF[3]:     __ld12cvt:00557c75(c), 
    //                                                                                                         __ld12cvt:00557cda(c), 
    //                                                                                                         __ld12told:00557e30(c)  
    //         00557a30     PUSH       ECX
    //         00557a31     MOV        EAX,dword ptr [ESP + Stack[0x8]]
    //         00557a35     PUSH       EBX
    //         00557a36     PUSH       EBP
    //         00557a37     PUSH       ESI
    //         00557a38     LEA        EBP,[EAX + -0x1]
    //         00557a3b     MOV        EBX,dword ptr [ESP + Stack[0x4]]
    //         00557a3f     MOV        dword ptr [ESP + Stack[0x8]],EBP
    //         00557a43     INC        EBP
    //         00557a44     MOV        EAX,EBP
    //         00557a46     PUSH       EDI
    //         00557a47     CDQ
    //         00557a48     AND        EDX,0x1f
    //         00557a4b     MOV        EDI,0x1f
    //         00557a50     ADD        EAX,EDX
    //         00557a52     MOV        dword ptr [ESP + local_4],0x0
    //         00557a5a     MOV        ESI,EAX
    //         00557a5c     MOV        EAX,EBP
    //         00557a5e     CDQ
    //         00557a5f     XOR        EAX,EDX
    //         00557a61     SUB        EAX,EDX
    //         00557a63     AND        EAX,0x1f
    //         00557a66     XOR        EAX,EDX
    //         00557a68     SUB        EAX,EDX
    //         00557a6a     MOV        EDX,0x1
    //         00557a6f     SUB        EDI,EAX
    //         00557a71     MOV        ECX,EDI
    //         00557a73     SAR        ESI,0x5
    //         00557a76     SHL        EDX,CL
    //         00557a78     TEST       dword ptr [EBX + ESI*0x4],EDX
    //         00557a7b     JZ         LAB_00557a9e
    //         00557a7d     INC        EBP
    //         00557a7e     PUSH       EBP
    //         00557a7f     PUSH       EBX
    //         00557a80     CALL       __ZeroTail                                       undefined __ZeroTail()
    //         00557a85     ADD        ESP,0x8
    //         00557a88     TEST       EAX,EAX
    //         00557a8a     JNZ        LAB_00557a9e
    //         00557a8c     MOV        EAX,dword ptr [ESP + Stack[0x8]]
    //         00557a90     PUSH       EAX
    //         00557a91     PUSH       EBX
    //         00557a92     CALL       __IncMan                                         undefined __IncMan()
    //         00557a97     ADD        ESP,0x8
    //         00557a9a     MOV        EDX,EAX
    //         00557a9c     JMP        LAB_00557aa2
    //                               LAB_00557a9e                                                 XREF[2]:     00557a7b(j), 00557a8a(j)  
    //         00557a9e     MOV        EDX,dword ptr [ESP + local_4]
    //                               LAB_00557aa2                                                 XREF[1]:     00557a9c(j)  
    //         00557aa2     OR         EAX,0xffffffff
    //         00557aa5     MOV        ECX,EDI
    //         00557aa7     SHL        EAX,CL
    //         00557aa9     MOV        ECX,dword ptr [EBX + ESI*0x4]
    //         00557aac     AND        ECX,EAX
    //         00557aae     MOV        dword ptr [EBX + ESI*0x4],ECX
    //         00557ab1     INC        ESI
    //         00557ab2     CMP        ESI,0x3
    //         00557ab5     JGE        LAB_00557ac5
    //         00557ab7     MOV        ECX,0x3
    //         00557abc     LEA        EDI,[EBX + ESI*0x4]
    //         00557abf     SUB        ECX,ESI
    //         00557ac1     XOR        EAX,EAX
    //         00557ac3     STOSD.REP  ES:EDI
    //                               LAB_00557ac5                                                 XREF[1]:     00557ab5(j)  
    //         00557ac5     POP        EDI
    //         00557ac6     POP        ESI
    //         00557ac7     POP        EBP
    //         00557ac8     MOV        EAX,EDX
    //         00557aca     POP        EBX
    //         00557acb     POP        ECX
    //         00557acc     RET
}

// Offset: 0x00557AD0
undefined CopyMan() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined __CopyMan()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               __CopyMan                                                    XREF[2]:     __ld12cvt:00557c64(c), 
    //                                                                                                         __ld12cvt:00557cbb(c)  
    //         00557ad0     MOV        EAX,dword ptr [ESP + Stack[0x8]]
    //         00557ad4     MOV        ECX,dword ptr [ESP + Stack[0x4]]
    //         00557ad8     PUSH       ESI
    //         00557ad9     SUB        ECX,EAX
    //         00557adb     MOV        EDX,0x3
    //                               LAB_00557ae0                                                 XREF[1]:     00557ae9(j)  
    //         00557ae0     MOV        ESI,dword ptr [EAX]
    //         00557ae2     MOV        dword ptr [EAX + ECX*0x1],ESI
    //         00557ae5     ADD        EAX,0x4
    //         00557ae8     DEC        EDX
    //         00557ae9     JNZ        LAB_00557ae0
    //         00557aeb     POP        ESI
    //         00557aec     RET
}

// Offset: 0x00557AF0
undefined FillZeroMan() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined __FillZeroMan()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               __FillZeroMan                                                XREF[3]:     __ld12cvt:00557c48(c), 
    //                                                                                                         __ld12cvt:00557c95(c), 
    //                                                                                                         __ld12cvt:00557d06(c)  
    //         00557af0     MOV        ECX,dword ptr [ESP + Stack[0x4]]
    //         00557af4     XOR        EAX,EAX
    //         00557af6     MOV        dword ptr [ECX],EAX
    //         00557af8     MOV        dword ptr [ECX + 0x4],EAX
    //         00557afb     MOV        dword ptr [ECX + 0x8],EAX
    //         00557afe     RET
}

// Offset: 0x00557B00
undefined IsZeroMan() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined __IsZeroMan()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               __IsZeroMan                                                  XREF[1]:     __ld12cvt:00557c33(c)  
    //         00557b00     MOV        ECX,dword ptr [ESP + Stack[0x4]]
    //         00557b04     XOR        EAX,EAX
    //                               LAB_00557b06                                                 XREF[1]:     00557b12(j)  
    //         00557b06     CMP        dword ptr [ECX],0x0
    //         00557b09     JNZ        LAB_00557b1a
    //         00557b0b     INC        EAX
    //         00557b0c     ADD        ECX,0x4
    //         00557b0f     CMP        EAX,0x3
    //         00557b12     JL         LAB_00557b06
    //         00557b14     MOV        EAX,0x1
    //         00557b19     RET
    //                               LAB_00557b1a                                                 XREF[1]:     00557b09(j)  
    //         00557b1a     XOR        EAX,EAX
    //         00557b1c     RET
}

// Offset: 0x00557B20
undefined ShrMan() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined __ShrMan()
    //              undefined         <UNASSIGNED>   <RETURN>
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     00557b36(W), 00557b8f(R)  
    //              undefined4        Stack[-0x8]:4  local_8                   XREF[2]:     00557b6f(W), 00557b7b(R)  
    //                               __ShrMan                                                     XREF[4]:     __ld12cvt:00557cc9(c), 
    //                                                                                                         __ld12cvt:00557cec(c), 
    //                                                                                                         __ld12cvt:00557d25(c), 
    //                                                                                                         __ld12cvt:00557d57(c)  
    //         00557b20     SUB        ESP,0x8
    //         00557b23     MOV        ECX,dword ptr [ESP + Stack[0x8]]
    //         00557b27     PUSH       EBX
    //         00557b28     MOV        EAX,ECX
    //         00557b2a     PUSH       EBP
    //         00557b2b     CDQ
    //         00557b2c     AND        EDX,0x1f
    //         00557b2f     PUSH       ESI
    //         00557b30     ADD        EAX,EDX
    //         00557b32     PUSH       EDI
    //         00557b33     SAR        EAX,0x5
    //         00557b36     MOV        dword ptr [ESP + local_4],EAX
    //         00557b3a     MOV        EAX,ECX
    //         00557b3c     CDQ
    //         00557b3d     XOR        EAX,EDX
    //         00557b3f     MOV        ESI,dword ptr [ESP + Stack[0x4]]
    //         00557b43     SUB        EAX,EDX
    //         00557b45     OR         EDI,0xffffffff
    //         00557b48     AND        EAX,0x1f
    //         00557b4b     MOV        EBP,0x20
    //         00557b50     XOR        EAX,EDX
    //         00557b52     XOR        EBX,EBX
    //         00557b54     SUB        EAX,EDX
    //         00557b56     MOV        dword ptr [ESP + Stack[0x8]],0x3
    //         00557b5e     MOV        ECX,EAX
    //         00557b60     SHL        EDI,CL
    //         00557b62     SUB        EBP,EAX
    //         00557b64     NOT        EDI
    //                               LAB_00557b66                                                 XREF[1]:     00557b8d(j)  
    //         00557b66     MOV        EDX,dword ptr [ESI]
    //         00557b68     MOV        ECX,EDI
    //         00557b6a     AND        ECX,EDX
    //         00557b6c     ADD        ESI,0x4
    //         00557b6f     MOV        dword ptr [ESP + local_8],ECX
    //         00557b73     MOV        ECX,EAX
    //         00557b75     SHR        EDX,CL
    //         00557b77     MOV        ECX,EBP
    //         00557b79     OR         EDX,EBX
    //         00557b7b     MOV        EBX,dword ptr [ESP + local_8]
    //         00557b7f     SHL        EBX,CL
    //         00557b81     MOV        ECX,dword ptr [ESP + Stack[0x8]]
    //         00557b85     MOV        dword ptr [ESI + -0x4],EDX
    //         00557b88     DEC        ECX
    //         00557b89     MOV        dword ptr [ESP + Stack[0x8]],ECX
    //         00557b8d     JNZ        LAB_00557b66
    //         00557b8f     MOV        EBX,dword ptr [ESP + local_4]
    //         00557b93     MOV        ESI,0x2
    //         00557b98     MOV        ECX,0x8
    //         00557b9d     LEA        EDI,[EBX*0x4 + 0x0]
    //                               LAB_00557ba4                                                 XREF[1]:     00557bc7(j)  
    //         00557ba4     CMP        ESI,EBX
    //         00557ba6     JL         LAB_00557bb8
    //         00557ba8     MOV        EDX,dword ptr [ESP + Stack[0x4]]
    //         00557bac     MOV        EAX,ECX
    //         00557bae     SUB        EAX,EDI
    //         00557bb0     MOV        EAX,dword ptr [EDX + EAX*0x1]
    //         00557bb3     MOV        dword ptr [EDX + ECX*0x1],EAX
    //         00557bb6     JMP        LAB_00557bc3
    //                               LAB_00557bb8                                                 XREF[1]:     00557ba6(j)  
    //         00557bb8     MOV        EDX,dword ptr [ESP + Stack[0x4]]
    //         00557bbc     MOV        dword ptr [EDX + ECX*0x1],0x0
    //                               LAB_00557bc3                                                 XREF[1]:     00557bb6(j)  
    //         00557bc3     DEC        ESI
    //         00557bc4     SUB        ECX,0x4
    //         00557bc7     JNS        LAB_00557ba4
    //         00557bc9     POP        EDI
    //         00557bca     POP        ESI
    //         00557bcb     POP        EBP
    //         00557bcc     POP        EBX
    //         00557bcd     ADD        ESP,0x8
    //         00557bd0     RET
}

// Offset: 0x00557BE0
undefined ld12cvt() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined __ld12cvt()
    //              undefined         <UNASSIGNED>   <RETURN>
    //              undefined         Stack[-0xc]:1  local_c                   XREF[2]:     00557c5e(*), 00557cb5(*)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     00557c26(W)  
    //              undefined4        Stack[-0x14]:4 local_14                  XREF[2]:     00557c22(W), 00557d8b(R)  
    //              undefined4        Stack[-0x18]:4 local_18                  XREF[18]:    00557bfe(W), 00557c2c(*), 00557c43(*), 00557c5a(*), 
    //                                                                                     00557c6f(*), 00557c90(*), 00557caf(*), 00557cc3(*), 
    //                                                                                     00557cd4(*), 00557ce6(*), 00557d01(*), 00557d0b(R), 
    //                                                                                     00557d15(*), 00557d21(W), 00557d43(R), 00557d47(*), 
    //                                                                                     00557d53(W), 00557d6b(R)  
    //                               __ld12cvt                                                    XREF[2]:     __ld12tod:00557dbf(c), 
    //                                                                                                         __ld12tof:00557ddf(c)  
    //         00557be0     SUB        ESP,0x18
    //         00557be3     MOV        ECX,dword ptr [ESP + Stack[0x4]]
    //         00557be7     XOR        EAX,EAX
    //         00557be9     PUSH       EBX
    //         00557bea     PUSH       EBP
    //         00557beb     MOV        AX,word ptr [ECX + 0xa]
    //         00557bef     MOV        EDX,dword ptr [ECX + 0x2]
    //         00557bf2     MOV        EBX,EAX
    //         00557bf4     AND        EAX,0x8000
    //         00557bf9     MOV        EBP,EAX
    //         00557bfb     MOV        EAX,dword ptr [ECX + 0x6]
    //         00557bfe     MOV        dword ptr [ESP + local_18],EAX
    //         00557c02     XOR        EAX,EAX
    //         00557c04     MOV        AX,word ptr [ECX]
    //         00557c07     AND        EBX,0x7fff
    //         00557c0d     SUB        EBX,0x3fff
    //         00557c13     PUSH       ESI
    //         00557c14     SHL        EAX,0x10
    //         00557c17     PUSH       EDI
    //         00557c18     MOV        EDI,dword ptr [ESP + Stack[0xc]]
    //         00557c1c     CMP        EBX,0xffffc001
    //         00557c22     MOV        dword ptr [ESP + local_14],EDX
    //         00557c26     MOV        dword ptr [ESP + local_10],EAX
    //         00557c2a     JNZ        LAB_00557c5a
    //         00557c2c     LEA        ECX=>local_18,[ESP + 0x10]
    //         00557c30     XOR        ESI,ESI
    //         00557c32     PUSH       ECX
    //         00557c33     CALL       __IsZeroMan                                      undefined __IsZeroMan()
    //         00557c38     ADD        ESP,0x4
    //         00557c3b     TEST       EAX,EAX
    //         00557c3d     JNZ        LAB_00557d5f
    //         00557c43     LEA        EDX=>local_18,[ESP + 0x10]
    //         00557c47     PUSH       EDX
    //         00557c48     CALL       __FillZeroMan                                    undefined __FillZeroMan()
    //         00557c4d     ADD        ESP,0x4
    //         00557c50     MOV        EAX,0x2
    //         00557c55     JMP        LAB_00557d61
    //                               LAB_00557c5a                                                 XREF[1]:     00557c2a(j)  
    //         00557c5a     LEA        EAX=>local_18,[ESP + 0x10]
    //         00557c5e     LEA        ECX=>local_c,[ESP + 0x1c]
    //         00557c62     PUSH       EAX
    //         00557c63     PUSH       ECX
    //         00557c64     CALL       __CopyMan                                        undefined __CopyMan()
    //         00557c69     MOV        EDX,dword ptr [EDI + 0x8]
    //         00557c6c     ADD        ESP,0x8
    //         00557c6f     LEA        EAX=>local_18,[ESP + 0x10]
    //         00557c73     PUSH       EDX
    //         00557c74     PUSH       EAX
    //         00557c75     CALL       __RoundMan                                       undefined __RoundMan()
    //         00557c7a     ADD        ESP,0x8
    //         00557c7d     TEST       EAX,EAX
    //         00557c7f     JZ         LAB_00557c82
    //         00557c81     INC        EBX
    //                               LAB_00557c82                                                 XREF[1]:     00557c7f(j)  
    //         00557c82     MOV        EAX,dword ptr [EDI + 0x4]
    //         00557c85     MOV        ESI,dword ptr [EDI + 0x8]
    //         00557c88     MOV        ECX,EAX
    //         00557c8a     SUB        ECX,ESI
    //         00557c8c     CMP        EBX,ECX
    //         00557c8e     JGE        LAB_00557ca9
    //         00557c90     LEA        EDX=>local_18,[ESP + 0x10]
    //         00557c94     PUSH       EDX
    //         00557c95     CALL       __FillZeroMan                                    undefined __FillZeroMan()
    //         00557c9a     ADD        ESP,0x4
    //         00557c9d     XOR        ESI,ESI
    //         00557c9f     MOV        EAX,0x2
    //         00557ca4     JMP        LAB_00557d61
    //                               LAB_00557ca9                                                 XREF[1]:     00557c8e(j)  
    //         00557ca9     CMP        EBX,EAX
    //         00557cab     JG         LAB_00557cfd
    //         00557cad     SUB        EAX,EBX
    //         00557caf     LEA        ECX=>local_18,[ESP + 0x10]
    //         00557cb3     MOV        ESI,EAX
    //         00557cb5     LEA        EAX=>local_c,[ESP + 0x1c]
    //         00557cb9     PUSH       EAX
    //         00557cba     PUSH       ECX
    //         00557cbb     CALL       __CopyMan                                        undefined __CopyMan()
    //         00557cc0     ADD        ESP,0x8
    //         00557cc3     LEA        EDX=>local_18,[ESP + 0x10]
    //         00557cc7     PUSH       ESI
    //         00557cc8     PUSH       EDX
    //         00557cc9     CALL       __ShrMan                                         undefined __ShrMan()
    //         00557cce     MOV        EAX,dword ptr [EDI + 0x8]
    //         00557cd1     ADD        ESP,0x8
    //         00557cd4     LEA        ECX=>local_18,[ESP + 0x10]
    //         00557cd8     PUSH       EAX
    //         00557cd9     PUSH       ECX
    //         00557cda     CALL       __RoundMan                                       undefined __RoundMan()
    //         00557cdf     MOV        EDX,dword ptr [EDI + 0xc]
    //         00557ce2     ADD        ESP,0x8
    //         00557ce5     INC        EDX
    //         00557ce6     LEA        EAX=>local_18,[ESP + 0x10]
    //         00557cea     PUSH       EDX
    //         00557ceb     PUSH       EAX
    //         00557cec     CALL       __ShrMan                                         undefined __ShrMan()
    //         00557cf1     ADD        ESP,0x8
    //         00557cf4     XOR        ESI,ESI
    //         00557cf6     MOV        EAX,0x2
    //         00557cfb     JMP        LAB_00557d61
    //                               LAB_00557cfd                                                 XREF[1]:     00557cab(j)  
    //         00557cfd     CMP        EBX,dword ptr [EDI]
    //         00557cff     JL         LAB_00557d3b
    //         00557d01     LEA        ECX=>local_18,[ESP + 0x10]
    //         00557d05     PUSH       ECX
    //         00557d06     CALL       __FillZeroMan                                    undefined __FillZeroMan()
    //         00557d0b     MOV        EBX,dword ptr [ESP + local_18]
    //         00557d0f     MOV        EDX,dword ptr [EDI + 0xc]
    //         00557d12     ADD        ESP,0x4
    //         00557d15     LEA        EAX=>local_18,[ESP + 0x10]
    //         00557d19     OR         EBX,0x80000000
    //         00557d1f     PUSH       EDX
    //         00557d20     PUSH       EAX
    //         00557d21     MOV        dword ptr [ESP + local_18],EBX
    //         00557d25     CALL       __ShrMan                                         undefined __ShrMan()
    //         00557d2a     MOV        ESI,dword ptr [EDI + 0x14]
    //         00557d2d     MOV        EAX,dword ptr [EDI]
    //         00557d2f     ADD        ESP,0x8
    //         00557d32     ADD        ESI,EAX
    //         00557d34     MOV        EAX,0x1
    //         00557d39     JMP        LAB_00557d61
    //                               LAB_00557d3b                                                 XREF[1]:     00557cff(j)  
    //         00557d3b     MOV        ESI,dword ptr [EDI + 0x14]
    //         00557d3e     MOV        ECX,dword ptr [EDI + 0xc]
    //         00557d41     ADD        ESI,EBX
    //         00557d43     MOV        EBX,dword ptr [ESP + local_18]
    //         00557d47     LEA        EDX=>local_18,[ESP + 0x10]
    //         00557d4b     AND        EBX,0x7fffffff
    //         00557d51     PUSH       ECX
    //         00557d52     PUSH       EDX
    //         00557d53     MOV        dword ptr [ESP + local_18],EBX
    //         00557d57     CALL       __ShrMan                                         undefined __ShrMan()
    //         00557d5c     ADD        ESP,0x8
    //                               LAB_00557d5f                                                 XREF[1]:     00557c3d(j)  
    //         00557d5f     XOR        EAX,EAX
    //                               LAB_00557d61                                                 XREF[4]:     00557c55(j), 00557ca4(j), 
    //                                                                                                         00557cfb(j), 00557d39(j)  
    //         00557d61     MOV        EDX,dword ptr [EDI + 0xc]
    //         00557d64     MOV        ECX,0x1f
    //         00557d69     SUB        ECX,EDX
    //         00557d6b     MOV        EDX,dword ptr [ESP + local_18]
    //         00557d6f     SHL        ESI,CL
    //         00557d71     MOV        EDI,dword ptr [EDI + 0x10]
    //         00557d74     NEG        EBP
    //         00557d76     SBB        EBP,EBP
    //         00557d78     AND        EBP,0x80000000
    //         00557d7e     OR         ESI,EBP
    //         00557d80     OR         ESI,EDX
    //         00557d82     CMP        EDI,0x40
    //         00557d85     JNZ        LAB_00557d9c
    //         00557d87     MOV        ECX,dword ptr [ESP + Stack[0x8]]
    //         00557d8b     MOV        EDX,dword ptr [ESP + local_14]
    //         00557d8f     MOV        dword ptr [ECX + 0x4],ESI
    //         00557d92     MOV        dword ptr [ECX],EDX
    //         00557d94     POP        EDI
    //         00557d95     POP        ESI
    //         00557d96     POP        EBP
    //         00557d97     POP        EBX
    //         00557d98     ADD        ESP,0x18
    //         00557d9b     RET
    //                               LAB_00557d9c                                                 XREF[1]:     00557d85(j)  
    //         00557d9c     CMP        EDI,0x20
    //         00557d9f     JNZ        LAB_00557da7
    //         00557da1     MOV        ECX,dword ptr [ESP + Stack[0x8]]
    //         00557da5     MOV        dword ptr [ECX],ESI
    //                               LAB_00557da7                                                 XREF[1]:     00557d9f(j)  
    //         00557da7     POP        EDI
    //         00557da8     POP        ESI
    //         00557da9     POP        EBP
    //         00557daa     POP        EBX
    //         00557dab     ADD        ESP,0x18
    //         00557dae     RET
}

// Offset: 0x00557DB0
undefined ld12tod() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined __ld12tod()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               __ld12tod                                                    XREF[2]:     __fltin:00554f1b(c), 
    //                                                                                                         __atodbl:00557e9c(c)  
    //         00557db0     MOV        EAX,dword ptr [ESP + Stack[0x8]]
    //         00557db4     MOV        ECX,dword ptr [ESP + Stack[0x4]]
    //         00557db8     PUSH       DAT_00592690
    //         00557dbd     PUSH       EAX
    //         00557dbe     PUSH       ECX
    //         00557dbf     CALL       __ld12cvt                                        undefined __ld12cvt()
    //         00557dc4     ADD        ESP,0xc
    //         00557dc7     RET
}

// Offset: 0x00557DD0
undefined ld12tof() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined __ld12tof()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               __ld12tof                                                    XREF[1]:     __atoflt:00557f1c(c)  
    //         00557dd0     MOV        EAX,dword ptr [ESP + Stack[0x8]]
    //         00557dd4     MOV        ECX,dword ptr [ESP + Stack[0x4]]
    //         00557dd8     PUSH       DAT_005926a8                                     = 80h
    //         00557ddd     PUSH       EAX
    //         00557dde     PUSH       ECX
    //         00557ddf     CALL       __ld12cvt                                        undefined __ld12cvt()
    //         00557de4     ADD        ESP,0xc
    //         00557de7     RET
}

// Offset: 0x00557DF0
undefined ld12told() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined __ld12told()
    //              undefined         <UNASSIGNED>   <RETURN>
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     00557e2c(W)  
    //              undefined4        Stack[-0x8]:4  local_8                   XREF[2]:     00557e28(W), 00557e58(R)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[3]:     00557e0d(W), 00557e16(*), 00557e44(R)  
    //                               __ld12told                                                   XREF[1]:     FUN_00557ea8:00557edc(c)  
    //         00557df0     SUB        ESP,0xc
    //         00557df3     MOV        ECX,dword ptr [ESP + Stack[0x4]]
    //         00557df7     PUSH       EBX
    //         00557df8     PUSH       ESI
    //         00557df9     PUSH       EDI
    //         00557dfa     MOV        AX,word ptr [ECX + 0xa]
    //         00557dfe     MOV        EDX,dword ptr [ECX + 0x2]
    //         00557e01     MOV        ESI,EAX
    //         00557e03     AND        EAX,0x8000
    //         00557e08     MOV        EDI,EAX
    //         00557e0a     MOV        EAX,dword ptr [ECX + 0x6]
    //         00557e0d     MOV        dword ptr [ESP + local_c],EAX
    //         00557e11     XOR        EAX,EAX
    //         00557e13     MOV        AX,word ptr [ECX]
    //         00557e16     LEA        ECX=>local_c,[ESP + 0xc]
    //         00557e1a     SHL        EAX,0x10
    //         00557e1d     PUSH       0x40
    //         00557e1f     PUSH       ECX
    //         00557e20     XOR        EBX,EBX
    //         00557e22     AND        ESI,0x7fff
    //         00557e28     MOV        dword ptr [ESP + local_8],EDX
    //         00557e2c     MOV        dword ptr [ESP + local_4],EAX
    //         00557e30     CALL       __RoundMan                                       undefined __RoundMan()
    //         00557e35     ADD        ESP,0x8
    //         00557e38     TEST       EAX,EAX
    //         00557e3a     JZ         LAB_00557e44
    //         00557e3c     MOV        ECX,0x80000000
    //         00557e41     INC        ESI
    //         00557e42     JMP        LAB_00557e48
    //                               LAB_00557e44                                                 XREF[1]:     00557e3a(j)  
    //         00557e44     MOV        ECX,dword ptr [ESP + local_c]
    //                               LAB_00557e48                                                 XREF[1]:     00557e42(j)  
    //         00557e48     CMP        SI,0x7fff
    //         00557e4d     JNZ        LAB_00557e54
    //         00557e4f     MOV        EBX,0x1
    //                               LAB_00557e54                                                 XREF[1]:     00557e4d(j)  
    //         00557e54     MOV        EAX,dword ptr [ESP + Stack[0x8]]
    //         00557e58     MOV        EDX,dword ptr [ESP + local_8]
    //         00557e5c     OR         EDI,ESI
    //         00557e5e     MOV        word ptr [EAX + 0x8],DI
    //         00557e62     MOV        dword ptr [EAX + 0x4],ECX
    //         00557e65     MOV        dword ptr [EAX],EDX
    //         00557e67     POP        EDI
    //         00557e68     MOV        EAX,EBX
    //         00557e6a     POP        ESI
    //         00557e6b     POP        EBX
    //         00557e6c     ADD        ESP,0xc
    //         00557e6f     RET
}

// Offset: 0x00557E70
undefined atodbl() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined __atodbl()
    //              undefined         <UNASSIGNED>   <RETURN>
    //              undefined         Stack[-0xc]:1  local_c                   XREF[2]:     00557e7b(*), 00557e96(*)  
    //                               __atodbl                                                     XREF[1]:     FUN_0055074c:00550765(c)  
    //         00557e70     MOV        EAX,dword ptr [ESP + Stack[0x8]]
    //         00557e74     SUB        ESP,0xc
    //         00557e77     LEA        ECX=>Stack[0x8],[ESP + 0x14]
    //         00557e7b     LEA        EDX=>local_c,[ESP]
    //         00557e7f     PUSH       0x0
    //         00557e81     PUSH       0x0
    //         00557e83     PUSH       0x0
    //         00557e85     PUSH       0x0
    //         00557e87     PUSH       EAX
    //         00557e88     PUSH       ECX
    //         00557e89     PUSH       EDX
    //         00557e8a     CALL       ___strgtold12                                    undefined ___strgtold12()
    //         00557e8f     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         00557e93     ADD        ESP,0x1c
    //         00557e96     LEA        ECX=>local_c,[ESP]
    //         00557e9a     PUSH       EAX
    //         00557e9b     PUSH       ECX
    //         00557e9c     CALL       __ld12tod                                        undefined __ld12tod()
    //         00557ea1     ADD        ESP,0x8
    //         00557ea4     ADD        ESP,0xc
    //         00557ea7     RET
}

// Offset: 0x00557EA8
undefined FUN_00557ea8() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00557ea8()
    //              undefined         <UNASSIGNED>   <RETURN>
    //              undefined         Stack[-0xc]:1  local_c                   XREF[2]:     00557ebb(*), 00557ed6(*)  
    //                               FUN_00557ea8
    //         00557ea8     NOP
    //         00557ea9     NOP
    //         00557eaa     NOP
    //         00557eab     NOP
    //         00557eac     NOP
    //         00557ead     NOP
    //         00557eae     NOP
    //         00557eaf     NOP
    //                               __atoldbl
    //         00557eb0     MOV        EAX,dword ptr [ESP + Stack[0x8]]
    //         00557eb4     SUB        ESP,0xc
    //         00557eb7     LEA        ECX=>Stack[0x8],[ESP + 0x14]
    //         00557ebb     LEA        EDX=>local_c,[ESP]
    //         00557ebf     PUSH       0x0
    //         00557ec1     PUSH       0x0
    //         00557ec3     PUSH       0x0
    //         00557ec5     PUSH       0x1
    //         00557ec7     PUSH       EAX
    //         00557ec8     PUSH       ECX
    //         00557ec9     PUSH       EDX
    //         00557eca     CALL       ___strgtold12                                    undefined ___strgtold12()
    //         00557ecf     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         00557ed3     ADD        ESP,0x1c
    //         00557ed6     LEA        ECX=>local_c,[ESP]
    //         00557eda     PUSH       EAX
    //         00557edb     PUSH       ECX
    //         00557edc     CALL       __ld12told                                       undefined __ld12told()
    //         00557ee1     ADD        ESP,0x8
    //         00557ee4     ADD        ESP,0xc
    //         00557ee7     RET
}

// Offset: 0x00557EF0
undefined atoflt() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined __atoflt()
    //              undefined         <UNASSIGNED>   <RETURN>
    //              undefined         Stack[-0xc]:1  local_c                   XREF[2]:     00557efb(*), 00557f16(*)  
    //                               __atoflt                                                     XREF[1]:     FUN_0055074c:0055078c(c)  
    //         00557ef0     MOV        EAX,dword ptr [ESP + Stack[0x8]]
    //         00557ef4     SUB        ESP,0xc
    //         00557ef7     LEA        ECX=>Stack[0x8],[ESP + 0x14]
    //         00557efb     LEA        EDX=>local_c,[ESP]
    //         00557eff     PUSH       0x0
    //         00557f01     PUSH       0x0
    //         00557f03     PUSH       0x0
    //         00557f05     PUSH       0x0
    //         00557f07     PUSH       EAX
    //         00557f08     PUSH       ECX
    //         00557f09     PUSH       EDX
    //         00557f0a     CALL       ___strgtold12                                    undefined ___strgtold12()
    //         00557f0f     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         00557f13     ADD        ESP,0x1c
    //         00557f16     LEA        ECX=>local_c,[ESP]
    //         00557f1a     PUSH       EAX
    //         00557f1b     PUSH       ECX
    //         00557f1c     CALL       __ld12tof                                        undefined __ld12tof()
    //         00557f21     ADD        ESP,0x8
    //         00557f24     ADD        ESP,0xc
    //         00557f27     RET
}

// Offset: 0x00557F30
undefined fptostr() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined __fptostr()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               __fptostr                                                    XREF[3]:     __cftoe:00550823(c), 
    //                                                                                                         __cftof:0055095d(c), 
    //                                                                                                         __cftog:00550a2f(c)  
    //         00557f30     MOV        ECX,dword ptr [ESP + Stack[0xc]]
    //         00557f34     PUSH       EBX
    //         00557f35     PUSH       EBP
    //         00557f36     MOV        EBP,dword ptr [ESP + Stack[0x4]]
    //         00557f3a     MOV        EDX,dword ptr [ECX + 0xc]
    //         00557f3d     PUSH       ESI
    //         00557f3e     MOV        ESI,dword ptr [ESP + Stack[0x8]]
    //         00557f42     PUSH       EDI
    //         00557f43     LEA        EDI,[EBP + 0x1]
    //         00557f46     MOV        byte ptr [EBP],0x30
    //         00557f4a     TEST       ESI,ESI
    //         00557f4c     MOV        EAX,EDI
    //         00557f4e     JLE        LAB_00557f6e
    //         00557f50     MOV        EBX,ESI
    //                               LAB_00557f52                                                 XREF[1]:     00557f68(j)  
    //         00557f52     MOV        CL,byte ptr [EDX]
    //         00557f54     TEST       CL,CL
    //         00557f56     JZ         LAB_00557f5e
    //         00557f58     MOVSX      ECX,CL
    //         00557f5b     INC        EDX
    //         00557f5c     JMP        LAB_00557f63
    //                               LAB_00557f5e                                                 XREF[1]:     00557f56(j)  
    //         00557f5e     MOV        ECX,0x30
    //                               LAB_00557f63                                                 XREF[1]:     00557f5c(j)  
    //         00557f63     MOV        byte ptr [EAX],CL
    //         00557f65     INC        EAX
    //         00557f66     DEC        ESI
    //         00557f67     DEC        EBX
    //         00557f68     JNZ        LAB_00557f52
    //         00557f6a     MOV        ECX,dword ptr [ESP + Stack[0xc]]
    //                               LAB_00557f6e                                                 XREF[1]:     00557f4e(j)  
    //         00557f6e     TEST       ESI,ESI
    //         00557f70     MOV        byte ptr [EAX],0x0
    //         00557f73     JL         LAB_00557f91
    //         00557f75     CMP        byte ptr [EDX],0x35
    //         00557f78     JL         LAB_00557f91
    //         00557f7a     MOV        DL,byte ptr [EAX + -0x1]
    //         00557f7d     DEC        EAX
    //         00557f7e     CMP        DL,0x39
    //         00557f81     JNZ        LAB_00557f8f
    //                               LAB_00557f83                                                 XREF[1]:     00557f8d(j)  
    //         00557f83     MOV        byte ptr [EAX],0x30
    //         00557f86     MOV        DL,byte ptr [EAX + -0x1]
    //         00557f89     DEC        EAX
    //         00557f8a     CMP        DL,0x39
    //         00557f8d     JZ         LAB_00557f83
    //                               LAB_00557f8f                                                 XREF[1]:     00557f81(j)  
    //         00557f8f     INC        byte ptr [EAX]
    //                               LAB_00557f91                                                 XREF[2]:     00557f73(j), 00557f78(j)  
    //         00557f91     CMP        byte ptr [EBP],0x31
    //         00557f95     JNZ        LAB_00557f9f
    //         00557f97     INC        dword ptr [ECX + 0x4]
    //         00557f9a     POP        EDI
    //         00557f9b     POP        ESI
    //         00557f9c     POP        EBP
    //         00557f9d     POP        EBX
    //         00557f9e     RET
    //                               LAB_00557f9f                                                 XREF[1]:     00557f95(j)  
    //         00557f9f     OR         ECX,0xffffffff
    //         00557fa2     XOR        EAX,EAX
    //         00557fa4     SCASB.RE   ES:EDI
    //         00557fa6     NOT        ECX
    //         00557fa8     SUB        EDI,ECX
    //         00557faa     MOV        EAX,ECX
    //         00557fac     MOV        ESI,EDI
    //         00557fae     MOV        EDI,EBP
    //         00557fb0     SHR        ECX,0x2
    //         00557fb3     MOVSD.REP  ES:EDI,ESI
    //         00557fb5     MOV        ECX,EAX
    //         00557fb7     AND        ECX,0x3
    //         00557fba     MOVSB.REP  ES:EDI,ESI
    //         00557fbc     POP        EDI
    //         00557fbd     POP        ESI
    //         00557fbe     POP        EBP
    //         00557fbf     POP        EBX
    //         00557fc0     RET
}

// Offset: 0x00557FD0
undefined fltout() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined __fltout()
    //              undefined         <UNASSIGNED>   <RETURN>
    //              undefined2        Stack[-0x4]:2  local_4                   XREF[1]:     00557ffd(R)  
    //              undefined4        Stack[-0x8]:4  local_8                   XREF[1]:     00557fe9(R)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[2]:     00557fd7(*), 00557fe5(*)  
    //              undefined2        Stack[-0x1c]:2 local_1c                  XREF[1]:     00558005(W)  
    //              undefined4        Stack[-0x20]:4 local_20                  XREF[1]:     00558002(W)  
    //              undefined4        Stack[-0x24]:4 local_24                  XREF[1]:     00557ffb(*)  
    //                               __fltout                                                     XREF[3]:     __cftoe:005507f4(c), 
    //                                                                                                         __cftof:00550937(c), 
    //                                                                                                         __cftog:005509ff(c)  
    //         00557fd0     SUB        ESP,0xc
    //         00557fd3     LEA        EAX=>Stack[0x4],[ESP + 0x10]
    //         00557fd7     LEA        ECX=>local_c,[ESP]
    //         00557fdb     PUSH       EAX
    //         00557fdc     PUSH       ECX
    //         00557fdd     CALL       ___dtold                                         undefined ___dtold()
    //         00557fe2     ADD        ESP,0x8
    //         00557fe5     MOV        EAX,dword ptr [ESP]=>local_c
    //         00557fe9     MOV        ECX,dword ptr [ESP + local_8]
    //         00557fed     PUSH       DAT_008883f0
    //         00557ff2     PUSH       0x0
    //         00557ff4     PUSH       0x11
    //         00557ff6     SUB        ESP,0xc
    //         00557ff9     MOV        EDX,ESP
    //         00557ffb     MOV        dword ptr [EDX]=>local_24,EAX
    //         00557ffd     MOV        AX,word ptr [ESP + local_4]
    //         00558002     MOV        dword ptr [EDX + local_20],ECX
    //         00558005     MOV        word ptr [EDX + local_1c],AX
    //         00558009     CALL       _$I10_OUTPUT                                     undefined _$I10_OUTPUT()
    //         0055800e     MOVSX      ECX,byte ptr [DAT_008883f2]
    //         00558015     MOVSX      EDX,word ptr [DAT_008883f0]
    //         0055801c     MOV        [null_00888418],EAX                              = align(8)
    //         00558021     ADD        ESP,0x18
    //         00558024     MOV        dword ptr [null_00888410],ECX                    = align(16)
    //         0055802a     MOV        dword ptr [null_00888414],EDX                    = align(12)
    //         00558030     MOV        dword ptr [null_0088841c],null_008883f4          = align(4)
    //                                                                                  = align(44)
    //         0055803a     MOV        EAX,null_00888410                                = align(16)
    //         0055803f     ADD        ESP,0xc
    //         00558042     RET
}

