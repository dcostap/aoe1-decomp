// Auto-generated scaffold unit: bucket_054D.asm
#include "../include/common.h"

// Offset: 0x0054D000
undefined sopen() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined __sopen()
    //              undefined         <UNASSIGNED>   <RETURN>
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     0054d01f(W), 0054d02a(W)  
    //              undefined4        Stack[-0x8]:4  local_8                   XREF[1]:     0054d019(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[2]:     0054d011(W), 0054d1bc(*)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[6]:     0054d064(W), 0054d06e(W), 0054d078(W), 0054d151(R), 
    //                                                                                     0054d160(W), 0054d1b1(R)  
    //              undefined1        Stack[-0x11]:1 local_11                  XREF[3]:     0054d023(W), 0054d032(W), 0054d04d(RW)  
    //                               __sopen                                                      XREF[2]:     __open:0054cff1(c), 
    //                                                                                                         __openfile:005532e1(c)  
    //         0054d000     SUB        ESP,0x14
    //         0054d003     MOV        ECX,dword ptr [ESP + Stack[0x8]]
    //         0054d007     PUSH       EBX
    //         0054d008     PUSH       EBP
    //         0054d009     PUSH       ESI
    //         0054d00a     MOV        DL,0x80
    //         0054d00c     XOR        ESI,ESI
    //         0054d00e     TEST       DL,CL
    //         0054d010     PUSH       EDI
    //         0054d011     MOV        dword ptr [ESP + local_c],0xc
    //         0054d019     MOV        dword ptr [ESP + local_8],ESI
    //         0054d01d     JZ         LAB_0054d02a
    //         0054d01f     MOV        dword ptr [ESP + local_4],ESI
    //         0054d023     MOV        byte ptr [ESP + local_11],0x10
    //         0054d028     JMP        LAB_0054d037
    //                               LAB_0054d02a                                                 XREF[1]:     0054d01d(j)  
    //         0054d02a     MOV        dword ptr [ESP + local_4],0x1
    //         0054d032     MOV        byte ptr [ESP + local_11],0x0
    //                               LAB_0054d037                                                 XREF[1]:     0054d028(j)  
    //         0054d037     TEST       CH,0x80
    //         0054d03a     JNZ        LAB_0054d051
    //         0054d03c     TEST       CH,0x40
    //         0054d03f     JNZ        LAB_0054d04d
    //         0054d041     CMP        dword ptr [__fmode],0x8000
    //         0054d04b     JZ         LAB_0054d051
    //                               LAB_0054d04d                                                 XREF[1]:     0054d03f(j)  
    //         0054d04d     OR         byte ptr [ESP + local_11],DL
    //                               LAB_0054d051                                                 XREF[2]:     0054d03a(j), 0054d04b(j)  
    //         0054d051     MOV        EAX,ECX
    //         0054d053     AND        EAX,0x3
    //         0054d056     SUB        EAX,ESI
    //         0054d058     JZ         LAB_0054d078
    //         0054d05a     DEC        EAX
    //         0054d05b     JZ         LAB_0054d06e
    //         0054d05d     DEC        EAX
    //         0054d05e     JNZ        switchD_0054d098::caseD_11
    //         0054d064     MOV        dword ptr [ESP + local_10],0xc0000000
    //         0054d06c     JMP        LAB_0054d080
    //                               LAB_0054d06e                                                 XREF[1]:     0054d05b(j)  
    //         0054d06e     MOV        dword ptr [ESP + local_10],0x40000000
    //         0054d076     JMP        LAB_0054d080
    //                               LAB_0054d078                                                 XREF[1]:     0054d058(j)  
    //         0054d078     MOV        dword ptr [ESP + local_10],0x80000000
    //                               LAB_0054d080                                                 XREF[2]:     0054d06c(j), 0054d076(j)  
    //         0054d080     MOV        EAX,dword ptr [ESP + Stack[0xc]]
    //         0054d084     ADD        EAX,-0x10
    //         0054d087     CMP        EAX,0x30
    //         0054d08a     JA         switchD_0054d098::caseD_11
    //         0054d090     XOR        EBX,EBX
    //         0054d092     MOV        BL,byte ptr [EAX + 0x54d380]=>PTR_caseD_20_005   = 0054d0a3
    //                               switchD_0054d098::switchD
    //         0054d098     JMP        dword ptr [EBX*0x4 + switchD_0054d098::switchd   = 0054d09f
    //                               switchD_0054d098::caseD_10                                   XREF[2]:     0054d098(j), 0054d36c(*)  
    //         0054d09f     XOR        EBX,EBX
    //         0054d0a1     JMP        LAB_0054d0b6
    //                               switchD_0054d098::caseD_20                                   XREF[2]:     0054d098(j), 0054d370(*)  
    //         0054d0a3     MOV        EBX,0x1
    //         0054d0a8     JMP        LAB_0054d0b6
    //                               switchD_0054d098::caseD_30                                   XREF[2]:     0054d098(j), 0054d374(*)  
    //         0054d0aa     MOV        EBX,0x2
    //         0054d0af     JMP        LAB_0054d0b6
    //                               switchD_0054d098::caseD_40                                   XREF[2]:     0054d098(j), 0054d378(*)  
    //         0054d0b1     MOV        EBX,0x3
    //                               LAB_0054d0b6                                                 XREF[3]:     0054d0a1(j), 0054d0a8(j), 
    //                                                                                                         0054d0af(j)  
    //         0054d0b6     MOV        EAX,ECX
    //         0054d0b8     AND        EAX,0x700
    //         0054d0bd     CMP        EAX,0x100
    //         0054d0c2     JG         LAB_0054d0d6
    //         0054d0c4     JZ         LAB_0054d0cf
    //         0054d0c6     CMP        EAX,ESI
    //         0054d0c8     JZ         LAB_0054d106
    //         0054d0ca     JMP        switchD_0054d098::caseD_11
    //                               LAB_0054d0cf                                                 XREF[1]:     0054d0c4(j)  
    //         0054d0cf     MOV        EBP,0x4
    //         0054d0d4     JMP        LAB_0054d12b
    //                               LAB_0054d0d6                                                 XREF[1]:     0054d0c2(j)  
    //         0054d0d6     CMP        EAX,0x300
    //         0054d0db     JG         LAB_0054d0f2
    //         0054d0dd     JZ         LAB_0054d0eb
    //         0054d0df     CMP        EAX,0x200
    //         0054d0e4     JZ         LAB_0054d126
    //         0054d0e6     JMP        switchD_0054d098::caseD_11
    //                               LAB_0054d0eb                                                 XREF[1]:     0054d0dd(j)  
    //         0054d0eb     MOV        EBP,0x2
    //         0054d0f0     JMP        LAB_0054d12b
    //                               LAB_0054d0f2                                                 XREF[1]:     0054d0db(j)  
    //         0054d0f2     CMP        EAX,0x500
    //         0054d0f7     JG         LAB_0054d10d
    //         0054d0f9     JZ         LAB_0054d11f
    //         0054d0fb     CMP        EAX,0x400
    //         0054d100     JNZ        switchD_0054d098::caseD_11
    //                               LAB_0054d106                                                 XREF[1]:     0054d0c8(j)  
    //         0054d106     MOV        EBP,0x3
    //         0054d10b     JMP        LAB_0054d12b
    //                               LAB_0054d10d                                                 XREF[1]:     0054d0f7(j)  
    //         0054d10d     CMP        EAX,0x600
    //         0054d112     JZ         LAB_0054d126
    //         0054d114     CMP        EAX,0x700
    //         0054d119     JNZ        switchD_0054d098::caseD_11
    //                               LAB_0054d11f                                                 XREF[1]:     0054d0f9(j)  
    //         0054d11f     MOV        EBP,0x1
    //         0054d124     JMP        LAB_0054d12b
    //                               LAB_0054d126                                                 XREF[2]:     0054d0e4(j), 0054d112(j)  
    //         0054d126     MOV        EBP,0x5
    //                               LAB_0054d12b                                                 XREF[4]:     0054d0d4(j), 0054d0f0(j), 
    //                                                                                                         0054d10b(j), 0054d124(j)  
    //         0054d12b     TEST       CH,0x1
    //         0054d12e     MOV        EDI,0x80
    //         0054d133     JZ         LAB_0054d14c
    //         0054d135     MOV        ESI,dword ptr [__umaskval]
    //         0054d13b     MOV        EAX,dword ptr [ESP + Stack[0x10]]
    //         0054d13f     NOT        ESI
    //         0054d141     AND        EAX,ESI
    //         0054d143     TEST       DL,AL
    //         0054d145     JNZ        LAB_0054d14c
    //         0054d147     MOV        EDI,0x1
    //                               LAB_0054d14c                                                 XREF[2]:     0054d133(j), 0054d145(j)  
    //         0054d14c     TEST       CL,0x40
    //         0054d14f     JZ         LAB_0054d164
    //         0054d151     MOV        EAX,dword ptr [ESP + local_10]
    //         0054d155     OR         EDI,0x4000000
    //         0054d15b     OR         EAX,0x10000
    //         0054d160     MOV        dword ptr [ESP + local_10],EAX
    //                               LAB_0054d164                                                 XREF[1]:     0054d14f(j)  
    //         0054d164     TEST       CH,0x10
    //         0054d167     JZ         LAB_0054d16f
    //         0054d169     OR         EDI,0x100
    //                               LAB_0054d16f                                                 XREF[1]:     0054d167(j)  
    //         0054d16f     TEST       CL,0x20
    //         0054d172     JZ         LAB_0054d17c
    //         0054d174     OR         EDI,0x8000000
    //         0054d17a     JMP        LAB_0054d187
    //                               LAB_0054d17c                                                 XREF[1]:     0054d172(j)  
    //         0054d17c     TEST       CL,0x10
    //         0054d17f     JZ         LAB_0054d187
    //         0054d181     OR         EDI,0x10000000
    //                               LAB_0054d187                                                 XREF[2]:     0054d17a(j), 0054d17f(j)  
    //         0054d187     CALL       __alloc_osfhnd                                   undefined __alloc_osfhnd()
    //         0054d18c     MOV        ESI,EAX
    //         0054d18e     CMP        ESI,-0x1
    //         0054d191     JNZ        LAB_0054d1b1
    //         0054d193     MOV        dword ptr [_errno],0x18                          = align(4)
    //         0054d19d     MOV        dword ptr [__doserrno],0x0
    //         0054d1a7     OR         EAX,EAX
    //         0054d1a9     POP        EDI
    //         0054d1aa     POP        ESI
    //         0054d1ab     POP        EBP
    //         0054d1ac     POP        EBX
    //         0054d1ad     ADD        ESP,0x14
    //         0054d1b0     RET
    //                               LAB_0054d1b1                                                 XREF[1]:     0054d191(j)  
    //         0054d1b1     MOV        EDX,dword ptr [ESP + local_10]
    //         0054d1b5     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         0054d1b9     PUSH       0x0
    //         0054d1bb     PUSH       EDI
    //         0054d1bc     LEA        ECX=>local_c,[ESP + 0x20]
    //         0054d1c0     PUSH       EBP
    //         0054d1c1     PUSH       ECX
    //         0054d1c2     PUSH       EBX
    //         0054d1c3     PUSH       EDX
    //         0054d1c4     PUSH       EAX
    //         0054d1c5     CALL       dword ptr [->KERNEL32.DLL::CreateFileA]          = 0048ac1c
    //         0054d1cb     MOV        EDI,EAX
    //         0054d1cd     CMP        EDI,-0x1
    //         0054d1d0     JNZ        LAB_0054d1eb
    //         0054d1d2     CALL       dword ptr [->KERNEL32.DLL::GetLastError]         = 0048aa76
    //         0054d1d8     PUSH       EAX
    //         0054d1d9     CALL       __dosmaperr                                      undefined __dosmaperr()
    //         0054d1de     ADD        ESP,0x4
    //         0054d1e1     OR         EAX,EDI
    //         0054d1e3     POP        EDI
    //         0054d1e4     POP        ESI
    //         0054d1e5     POP        EBP
    //         0054d1e6     POP        EBX
    //         0054d1e7     ADD        ESP,0x14
    //         0054d1ea     RET
    //                               LAB_0054d1eb                                                 XREF[1]:     0054d1d0(j)  
    //         0054d1eb     PUSH       EDI
    //         0054d1ec     CALL       dword ptr [->KERNEL32.DLL::GetFileType]          = 0048b742
    //         0054d1f2     TEST       EAX,EAX
    //         0054d1f4     JNZ        LAB_0054d217
    //         0054d1f6     PUSH       EDI
    //         0054d1f7     CALL       dword ptr [->KERNEL32.DLL::CloseHandle]          = 0048aa26
    //         0054d1fd     CALL       dword ptr [->KERNEL32.DLL::GetLastError]         = 0048aa76
    //         0054d203     PUSH       EAX
    //         0054d204     CALL       __dosmaperr                                      undefined __dosmaperr()
    //         0054d209     ADD        ESP,0x4
    //         0054d20c     OR         EAX,0xffffffff
    //         0054d20f     POP        EDI
    //         0054d210     POP        ESI
    //         0054d211     POP        EBP
    //         0054d212     POP        EBX
    //         0054d213     ADD        ESP,0x14
    //         0054d216     RET
    //                               LAB_0054d217                                                 XREF[1]:     0054d1f4(j)  
    //         0054d217     CMP        EAX,0x2
    //         0054d21a     JNZ        LAB_0054d224
    //         0054d21c     MOV        AL,byte ptr [ESP + 0x13]
    //         0054d220     OR         AL,0x40
    //         0054d222     JMP        LAB_0054d22f
    //                               LAB_0054d224                                                 XREF[1]:     0054d21a(j)  
    //         0054d224     CMP        EAX,0x3
    //         0054d227     JNZ        LAB_0054d233
    //         0054d229     MOV        AL,byte ptr [ESP + 0x13]
    //         0054d22d     OR         AL,0x8
    //                               LAB_0054d22f                                                 XREF[1]:     0054d222(j)  
    //         0054d22f     MOV        byte ptr [ESP + 0x13],AL
    //                               LAB_0054d233                                                 XREF[1]:     0054d227(j)  
    //         0054d233     PUSH       EDI
    //         0054d234     PUSH       ESI=>DAT_fffffff8
    //         0054d235     CALL       __set_osfhnd                                     undefined __set_osfhnd()
    //         0054d23a     MOV        BL,byte ptr [ESP + 0x1b]
    //         0054d23e     MOV        ECX,ESI
    //         0054d240     OR         BL,0x1
    //         0054d243     MOV        EDI,ESI
    //         0054d245     SAR        ECX,0x5
    //         0054d248     MOV        byte ptr [ESP + 0x1b],BL
    //         0054d24c     AND        EDI,0x1f
    //         0054d24f     MOV        AL,byte ptr [ESP + 0x1b]
    //         0054d253     MOV        EDX,dword ptr [ECX*0x4 + ___pioinfo]
    //         0054d25a     LEA        EBX,[ECX*0x4 + ___pioinfo]
    //         0054d261     MOV        CL,AL
    //         0054d263     ADD        ESP,0x8
    //         0054d266     SHL        EDI,0x3
    //         0054d269     AND        CL,0x48
    //         0054d26c     MOV        byte ptr [EDI + EDX*0x1 + 0x4],AL
    //         0054d270     MOV        byte ptr [ESP + 0x28],CL
    //         0054d274     JNZ        LAB_0054d329
    //         0054d27a     TEST       AL,0x80
    //         0054d27c     JZ         LAB_0054d329
    //         0054d282     TEST       byte ptr [ESP + 0x2c],0x2
    //         0054d287     JZ         LAB_0054d329
    //         0054d28d     PUSH       0x2
    //         0054d28f     PUSH       offset DAT_fffffff8
    //         0054d291     PUSH       ESI=>DAT_fffffff4
    //         0054d292     CALL       lseek                                            undefined lseek()
    //         0054d297     MOV        EBP,EAX
    //         0054d299     ADD        ESP,0xc
    //         0054d29c     CMP        EBP,-0x1
    //         0054d29f     JNZ        LAB_0054d2c0
    //         0054d2a1     CMP        dword ptr [__doserrno],0x83
    //         0054d2ab     JZ         LAB_0054d329
    //         0054d2ad     PUSH       ESI
    //         0054d2ae     CALL       close                                            undefined close()
    //         0054d2b3     ADD        ESP,0x4
    //         0054d2b6     OR         EAX,EBP
    //         0054d2b8     POP        EDI
    //         0054d2b9     POP        ESI
    //         0054d2ba     POP        EBP
    //         0054d2bb     POP        EBX
    //         0054d2bc     ADD        ESP,0x14
    //         0054d2bf     RET
    //                               LAB_0054d2c0                                                 XREF[1]:     0054d29f(j)  
    //         0054d2c0     LEA        EAX,[ESP + 0x30]
    //         0054d2c4     PUSH       0x1
    //         0054d2c6     PUSH       EAX=>DAT_fffffff8
    //         0054d2c7     PUSH       ESI=>DAT_fffffff4
    //         0054d2c8     MOV        byte ptr [ESP + 0x3c],0x0
    //         0054d2cd     CALL       read                                             undefined read()
    //         0054d2d2     ADD        ESP,0xc
    //         0054d2d5     TEST       EAX,EAX
    //         0054d2d7     JNZ        LAB_0054d303
    //         0054d2d9     CMP        byte ptr [ESP + 0x30],0x1a
    //         0054d2de     JNZ        LAB_0054d303
    //         0054d2e0     PUSH       EBP
    //         0054d2e1     PUSH       ESI=>DAT_fffffff8
    //         0054d2e2     CALL       __chsize                                         undefined __chsize()
    //         0054d2e7     ADD        ESP,0x8
    //         0054d2ea     CMP        EAX,-0x1
    //         0054d2ed     JNZ        LAB_0054d303
    //         0054d2ef     PUSH       ESI
    //         0054d2f0     CALL       close                                            undefined close()
    //         0054d2f5     ADD        ESP,0x4
    //         0054d2f8     OR         EAX,0xffffffff
    //         0054d2fb     POP        EDI
    //         0054d2fc     POP        ESI
    //         0054d2fd     POP        EBP
    //         0054d2fe     POP        EBX
    //         0054d2ff     ADD        ESP,0x14
    //         0054d302     RET
    //                               LAB_0054d303                                                 XREF[3]:     0054d2d7(j), 0054d2de(j), 
    //                                                                                                         0054d2ed(j)  
    //         0054d303     PUSH       0x0
    //         0054d305     PUSH       0x0=>DAT_fffffff8
    //         0054d307     PUSH       ESI=>DAT_fffffff4
    //         0054d308     CALL       lseek                                            undefined lseek()
    //         0054d30d     ADD        ESP,0xc
    //         0054d310     CMP        EAX,-0x1
    //         0054d313     JNZ        LAB_0054d329
    //         0054d315     PUSH       ESI
    //         0054d316     CALL       close                                            undefined close()
    //         0054d31b     ADD        ESP,0x4
    //         0054d31e     OR         EAX,0xffffffff
    //         0054d321     POP        EDI
    //         0054d322     POP        ESI
    //         0054d323     POP        EBP
    //         0054d324     POP        EBX
    //         0054d325     ADD        ESP,0x14
    //         0054d328     RET
    //                               LAB_0054d329                                                 XREF[5]:     0054d274(j), 0054d27c(j), 
    //                                                                                                         0054d287(j), 0054d2ab(j), 
    //                                                                                                         0054d313(j)  
    //         0054d329     MOV        AL,byte ptr [ESP + 0x28]
    //         0054d32d     TEST       AL,AL
    //         0054d32f     JNZ        LAB_0054d347
    //         0054d331     TEST       byte ptr [ESP + 0x2c],0x8
    //         0054d336     JZ         LAB_0054d347
    //         0054d338     MOV        ECX,dword ptr [EBX]=>___pioinfo
    //         0054d33a     LEA        EAX,[EDI + ECX*0x1 + 0x4]
    //         0054d33e     MOV        CL,byte ptr [EDI + ECX*0x1 + 0x4]
    //         0054d342     OR         CL,0x20
    //         0054d345     MOV        byte ptr [EAX],CL
    //                               LAB_0054d347                                                 XREF[2]:     0054d32f(j), 0054d336(j)  
    //         0054d347     MOV        EAX,ESI
    //         0054d349     POP        EDI
    //         0054d34a     POP        ESI
    //         0054d34b     POP        EBP
    //         0054d34c     POP        EBX
    //         0054d34d     ADD        ESP,0x14
    //         0054d350     RET
    //                               switchD_0054d098::caseD_12                                   XREF[8]:     0054d05e(j), 0054d08a(j), 
    //                               switchD_0054d098::caseD_13                                                0054d098(j), 0054d0ca(j), 
    //                               switchD_0054d098::caseD_14                                                0054d0e6(j), 0054d100(j), 
    //                               switchD_0054d098::caseD_15                                                0054d119(j), 0054d37c(*)  
    //                               switchD_0054d098::caseD_16
    //                               switchD_0054d098::caseD_17
    //                               switchD_0054d098::caseD_18
    //                               switchD_0054d098::caseD_19
    //                               switchD_0054d098::caseD_1a
    //                               switchD_0054d098::caseD_1b
    //                               switchD_0054d098::caseD_1c
    //                               switchD_0054d098::caseD_1d
    //                               switchD_0054d098::caseD_1e
    //                               switchD_0054d098::caseD_1f
    //                               switchD_0054d098::caseD_21
    //                               switchD_0054d098::caseD_22
    //                               switchD_0054d098::caseD_23
    //                               switchD_0054d098::caseD_24
    //                               switchD_0054d098::caseD_25
    //                               switchD_0054d098::caseD_26
    //                               switchD_0054d098::caseD_27
    //                               switchD_0054d098::caseD_28
    //                               switchD_0054d098::caseD_29
    //                               switchD_0054d098::caseD_2a
    //                               switchD_0054d098::caseD_2b
    //                               switchD_0054d098::caseD_2c
    //                               switchD_0054d098::caseD_2d
    //                               switchD_0054d098::caseD_2e
    //                               switchD_0054d098::caseD_2f
    //                               switchD_0054d098::caseD_31
    //                               switchD_0054d098::caseD_32
    //                               switchD_0054d098::caseD_33
    //                               switchD_0054d098::caseD_34
    //                               switchD_0054d098::caseD_35
    //                               switchD_0054d098::caseD_36
    //                               switchD_0054d098::caseD_37
    //                               switchD_0054d098::caseD_38
    //                               switchD_0054d098::caseD_39
    //                               switchD_0054d098::caseD_3a
    //                               switchD_0054d098::caseD_3b
    //                               switchD_0054d098::caseD_3c
    //                               switchD_0054d098::caseD_3d
    //                               switchD_0054d098::caseD_3e
    //                               switchD_0054d098::caseD_3f
    //                               switchD_0054d098::caseD_11
    //         0054d351     MOV        dword ptr [__doserrno],ESI
    //         0054d357     POP        EDI
    //         0054d358     POP        ESI
    //         0054d359     POP        EBP
    //         0054d35a     MOV        dword ptr [_errno],0x16                          = align(4)
    //         0054d364     OR         EAX,0xffffffff
    //         0054d367     POP        EBX
    //         0054d368     ADD        ESP,0x14
    //         0054d36b     RET
    //                               switchD_0054d098::switchdataD_0054d36c                       XREF[1]:     __sopen:0054d098(*)  
}

// Offset: 0x0054D3C0
undefined tell() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined __tell()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               __tell                                                       XREF[14]:    create_file:004235a3(c), 
    //                                                                                                         ReadPalette:004397a2(c), 
    //                                                                                                         RGE_Flic_Player:00449b5d(c), 
    //                                                                                                         setup:00466c4e(c), 
    //                                                                                                         rge_open:0047fdf1(c), 
    //                                                                                                         rge_open:0047fe86(c), 
    //                                                                                                         save:0048c96d(c), 
    //                                                                                                         save:0048ca26(c), 
    //                                                                                                         save:0048cadf(c), 
    //                                                                                                         TRIBE_Credits_Screen:004927df(c), 
    //                                                                                                         TShape:004b8c28(c), 
    //                                                                                                         TShape:004b8cd7(c), 
    //                                                                                                         Init_Tile_Edge_Tables:00533b24(c), 
    //                                                                                                         Init_Tile_Edge_Tables:00533be3(c)  
    //         0054d3c0     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         0054d3c4     PUSH       0x1
    //         0054d3c6     PUSH       0x0
    //         0054d3c8     PUSH       EAX
    //         0054d3c9     CALL       lseek                                            undefined lseek()
    //         0054d3ce     ADD        ESP,0xc
    //         0054d3d1     RET
}

// Offset: 0x0054D3E0
undefined lseek() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * lseek                                                                                                 *
    //                              *********************************************************************************************************
    //                              undefined __cdecl lseek()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               _lseek                                                       XREF[53]:    ReadPalette:00439799(c), 
    //                               __lseek                                                                   ReadPalette:004397c2(c), 
    //                               lseek                                                                     draw:00449ebd(c), 
    //                                                                                                         setup:00466c45(c), 
    //                                                                                                         setup:00466c6c(c), 
    //                                                                                                         RESFILE_load:0047f426(c), 
    //                                                                                                         TShape:004b8c1f(c), 
    //                                                                                                         TShape:004b8c43(c), 
    //                                                                                                         TShape:004b8cce(c), 
    //                                                                                                         TShape:004b8cf2(c), 
    //                                                                                                         Init_Tile_Edge_Tables:00533b1b(c), 
    //                                                                                                         Init_Tile_Edge_Tables:00533b44(c), 
    //                                                                                                         Init_Tile_Edge_Tables:00533bda(c), 
    //                                                                                                         Init_Tile_Edge_Tables:00533c03(c), 
    //                                                                                                         read:0054cf55(c), 
    //                                                                                                         __tell:0054d3c9(c), 
    //                                                                                                         write:0054d517(c), 
    //                                                                                                         fseek:0054f2d3(c), 
    //                                                                                                         __flsbuf:00553505(c), 
    //                                                                                                         ftell:005564a1(c), [more]
    //         0054d3e0     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         0054d3e4     MOV        ECX,dword ptr [__nhandle]
    //         0054d3ea     PUSH       EBX
    //         0054d3eb     PUSH       ESI
    //         0054d3ec     CMP        EAX,ECX
    //         0054d3ee     PUSH       EDI
    //         0054d3ef     JNC        LAB_0054d482
    //         0054d3f5     MOV        ECX,EAX
    //         0054d3f7     MOV        ESI,EAX
    //         0054d3f9     SAR        ECX,0x5
    //         0054d3fc     AND        ESI,0x1f
    //         0054d3ff     MOV        EDX,dword ptr [ECX*0x4 + ___pioinfo]
    //         0054d406     LEA        EBX,[ECX*0x4 + ___pioinfo]
    //         0054d40d     SHL        ESI,0x3
    //         0054d410     TEST       byte ptr [EDX + ESI*0x1 + 0x4],0x1
    //         0054d415     JZ         LAB_0054d482
    //         0054d417     PUSH       EAX
    //         0054d418     CALL       __get_osfhandle                                  undefined __get_osfhandle()
    //         0054d41d     ADD        ESP,0x4
    //         0054d420     CMP        EAX,-0x1
    //         0054d423     JNZ        LAB_0054d435
    //         0054d425     MOV        dword ptr [_errno],0x9                           = align(4)
    //         0054d42f     OR         EAX,EAX
    //         0054d431     POP        EDI
    //         0054d432     POP        ESI
    //         0054d433     POP        EBX
    //         0054d434     RET
    //                               LAB_0054d435                                                 XREF[1]:     0054d423(j)  
    //         0054d435     MOV        ECX,dword ptr [ESP + Stack[0xc]]
    //         0054d439     MOV        EDX,dword ptr [ESP + Stack[0x8]]
    //         0054d43d     PUSH       ECX
    //         0054d43e     PUSH       0x0
    //         0054d440     PUSH       EDX
    //         0054d441     PUSH       EAX
    //         0054d442     CALL       dword ptr [->KERNEL32.DLL::SetFilePointer]       = 0048b750
    //         0054d448     MOV        EDI,EAX
    //         0054d44a     CMP        EDI,-0x1
    //         0054d44d     JNZ        LAB_0054d457
    //         0054d44f     CALL       dword ptr [->KERNEL32.DLL::GetLastError]         = 0048aa76
    //         0054d455     JMP        LAB_0054d459
    //                               LAB_0054d457                                                 XREF[1]:     0054d44d(j)  
    //         0054d457     XOR        EAX,EAX
    //                               LAB_0054d459                                                 XREF[1]:     0054d455(j)  
    //         0054d459     TEST       EAX,EAX
    //         0054d45b     JZ         LAB_0054d46d
    //         0054d45d     PUSH       EAX
    //         0054d45e     CALL       __dosmaperr                                      undefined __dosmaperr()
    //         0054d463     ADD        ESP,0x4
    //         0054d466     OR         EAX,0xffffffff
    //         0054d469     POP        EDI
    //         0054d46a     POP        ESI
    //         0054d46b     POP        EBX
    //         0054d46c     RET
    //                               LAB_0054d46d                                                 XREF[1]:     0054d45b(j)  
    //         0054d46d     MOV        EAX,dword ptr [EBX]=>___pioinfo
    //         0054d46f     MOV        CL,byte ptr [EAX + ESI*0x1 + 0x4]
    //         0054d473     LEA        EAX,[EAX + ESI*0x1 + 0x4]
    //         0054d477     AND        CL,0xfd
    //         0054d47a     MOV        byte ptr [EAX],CL
    //         0054d47c     MOV        EAX,EDI
    //         0054d47e     POP        EDI
    //         0054d47f     POP        ESI
    //         0054d480     POP        EBX
    //         0054d481     RET
    //                               LAB_0054d482                                                 XREF[2]:     0054d3ef(j), 0054d415(j)  
    //         0054d482     POP        EDI
    //         0054d483     POP        ESI
    //         0054d484     MOV        dword ptr [_errno],0x9                           = align(4)
    //         0054d48e     MOV        dword ptr [__doserrno],0x0
    //         0054d498     OR         EAX,0xffffffff
    //         0054d49b     POP        EBX
    //         0054d49c     RET
}

// Offset: 0x0054D4A0
undefined write() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * write                                                                                                 *
    //                              *********************************************************************************************************
    //                              undefined __cdecl write()
    //              undefined         <UNASSIGNED>   <RETURN>
    //              undefined1        Stack[-0x403   local_403                 XREF[1]:     0054d567(*)  
    //              undefined         Stack[-0x404   local_404                 XREF[5]:     0054d546(*), 0054d55e(*), 0054d56c(*), 0054d57c(*), 
    //                                                                                     0054d58d(*)  
    //              undefined4        Stack[-0x408   local_408                 XREF[2]:     0054d4d7(W), 0054d586(R)  
    //              undefined4        Stack[-0x40c   local_40c                 XREF[3]:     0054d4fb(W), 0054d55a(R), 0054d563(W)  
    //              undefined         Stack[-0x410   local_410                 XREF[2]:     0054d580(*), 0054d680(*)  
    //              undefined4        Stack[-0x414   local_414                 XREF[2]:     0054d534(W), 0054d5d1(R)  
    //              undefined4        Stack[-0x418   local_418                 XREF[2]:     0054d4db(W), 0054d595(R)  
    //              undefined4        Stack[-0x41c   local_41c                 XREF[2]:     0054d4f7(W), 0054d5c9(R)  
    //                               __write                                                      XREF[27]:    take_snapshot:00446524(c), 
    //                               _write                                                                    take_snapshot:00446534(c), 
    //                               write                                                                     take_snapshot:0044654a(c), 
    //                                                                                                         take_snapshot:00446596(c), 
    //                                                                                                         RESFILE_build_res_file:0047fa7b(c)
    //                                                                                                         RESFILE_build_res_file:0047fabb(c)
    //                                                                                                         RESFILE_build_res_file:0047fb06(c)
    //                                                                                                         RESFILE_build_res_file:0047fb7a(c)
    //                                                                                                         rge_write_uncompressed:0048005b(c)
    //                                                                                                         rge_write:004802ec(c), 
    //                                                                                                         Get_BuildList:0048bdac(c), 
    //                                                                                                         Get_CityPlan:0048bfac(c), 
    //                                                                                                         Get_player_AI:0048c1cc(c), 
    //                                                                                                         take_snapshot:004becc3(c), 
    //                                                                                                         take_snapshot:004becd3(c), 
    //                                                                                                         take_snapshot:004bece9(c), 
    //                                                                                                         take_snapshot:004bed7f(c), 
    //                                                                                                         __flush:0054c0fe(c), 
    //                                                                                                         fwrite:0054f3c1(c), 
    //                                                                                                         __flsbuf:005534c6(c), [more]
    //         0054d4a0     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         0054d4a4     MOV        ECX,dword ptr [__nhandle]
    //         0054d4aa     SUB        ESP,0x41c
    //         0054d4b0     CMP        EAX,ECX
    //         0054d4b2     PUSH       EBX
    //         0054d4b3     PUSH       EBP
    //         0054d4b4     PUSH       ESI
    //         0054d4b5     PUSH       EDI
    //         0054d4b6     JNC        LAB_0054d64d
    //         0054d4bc     MOV        ECX,EAX
    //         0054d4be     MOV        ESI,EAX
    //         0054d4c0     SAR        ECX,0x5
    //         0054d4c3     AND        ESI,0x1f
    //         0054d4c6     MOV        EDX,dword ptr [ECX*0x4 + ___pioinfo]
    //         0054d4cd     LEA        EDI,[ECX*0x4 + ___pioinfo]
    //         0054d4d4     SHL        ESI,0x3
    //         0054d4d7     MOV        dword ptr [ESP + local_408],EDI
    //         0054d4db     MOV        dword ptr [ESP + local_418],ESI
    //         0054d4df     MOV        CL,byte ptr [ESI + EDX*0x1 + 0x4]
    //         0054d4e3     TEST       CL,0x1
    //         0054d4e6     JZ         LAB_0054d64d
    //         0054d4ec     MOV        EBX,dword ptr [ESP + Stack[0xc]]
    //         0054d4f3     XOR        EBP,EBP
    //         0054d4f5     CMP        EBX,EBP
    //         0054d4f7     MOV        dword ptr [ESP + local_41c],EBP
    //         0054d4fb     MOV        dword ptr [ESP + local_40c],EBP
    //         0054d4ff     JNZ        LAB_0054d50e
    //         0054d501     XOR        EAX,EAX
    //         0054d503     POP        EDI
    //         0054d504     POP        ESI
    //         0054d505     POP        EBP
    //         0054d506     POP        EBX
    //         0054d507     ADD        ESP,0x41c
    //         0054d50d     RET
    //                               LAB_0054d50e                                                 XREF[1]:     0054d4ff(j)  
    //         0054d50e     TEST       CL,0x20
    //         0054d511     JZ         LAB_0054d51f
    //         0054d513     PUSH       0x2
    //         0054d515     PUSH       EBP
    //         0054d516     PUSH       EAX
    //         0054d517     CALL       lseek                                            undefined lseek()
    //         0054d51c     ADD        ESP,0xc
    //                               LAB_0054d51f                                                 XREF[1]:     0054d511(j)  
    //         0054d51f     MOV        EAX,dword ptr [EDI]=>___pioinfo
    //         0054d521     ADD        EAX,ESI
    //         0054d523     TEST       byte ptr [EAX + 0x4],0x80
    //         0054d527     JZ         LAB_0054d67e
    //         0054d52d     MOV        EBP,dword ptr [ESP + Stack[0x8]]
    //         0054d534     MOV        dword ptr [ESP + local_414],0x0
    //         0054d53c     TEST       EBX,EBX
    //         0054d53e     MOV        EDI,EBP
    //         0054d540     JBE        LAB_0054d5c9
    //                               LAB_0054d546                                                 XREF[1]:     0054d5c3(j)  
    //         0054d546     LEA        EAX=>local_404,[ESP + 0x28]
    //                               LAB_0054d54a                                                 XREF[1]:     0054d578(j)  
    //         0054d54a     MOV        ECX,EDI
    //         0054d54c     SUB        ECX,EBP
    //         0054d54e     CMP        ECX,EBX
    //         0054d550     JNC        LAB_0054d57a
    //         0054d552     MOV        CL,byte ptr [EDI]
    //         0054d554     INC        EDI
    //         0054d555     CMP        CL,0xa
    //         0054d558     JNZ        LAB_0054d567
    //         0054d55a     MOV        ESI,dword ptr [ESP + local_40c]
    //         0054d55e     MOV        byte ptr [EAX]=>local_404,0xd
    //         0054d561     INC        ESI
    //         0054d562     INC        EAX
    //         0054d563     MOV        dword ptr [ESP + local_40c],ESI
    //                               LAB_0054d567                                                 XREF[1]:     0054d558(j)  
    //         0054d567     MOV        byte ptr [EAX]=>local_403,CL
    //         0054d569     INC        EAX
    //         0054d56a     MOV        EDX,EAX
    //         0054d56c     LEA        ECX=>local_404,[ESP + 0x28]
    //         0054d570     SUB        EDX,ECX
    //         0054d572     CMP        EDX,0x400
    //         0054d578     JL         LAB_0054d54a
    //                               LAB_0054d57a                                                 XREF[1]:     0054d550(j)  
    //         0054d57a     MOV        ESI,EAX
    //         0054d57c     LEA        EDX=>local_404,[ESP + 0x28]
    //         0054d580     LEA        EAX=>local_410,[ESP + 0x1c]
    //         0054d584     SUB        ESI,EDX
    //         0054d586     MOV        EDX,dword ptr [ESP + local_408]
    //         0054d58a     PUSH       0x0
    //         0054d58c     PUSH       EAX
    //         0054d58d     LEA        ECX=>local_404,[ESP + 0x30]
    //         0054d591     MOV        EAX,dword ptr [EDX]=>___pioinfo
    //         0054d593     PUSH       ESI
    //         0054d594     PUSH       ECX
    //         0054d595     MOV        ECX,dword ptr [ESP + local_418]
    //         0054d599     MOV        EDX,dword ptr [ECX + EAX*0x1]
    //         0054d59c     PUSH       EDX
    //         0054d59d     CALL       dword ptr [->KERNEL32.DLL::WriteFile]            = 0048b762
    //         0054d5a3     TEST       EAX,EAX
    //         0054d5a5     JZ         LAB_0054d66f
    //         0054d5ab     MOV        EAX,dword ptr [ESP + 0x1c]
    //         0054d5af     MOV        EDX,dword ptr [ESP + 0x10]
    //         0054d5b3     ADD        EDX,EAX
    //         0054d5b5     CMP        EAX,ESI
    //         0054d5b7     MOV        dword ptr [ESP + 0x10],EDX
    //         0054d5bb     JL         LAB_0054d5c5
    //         0054d5bd     MOV        EAX,EDI
    //         0054d5bf     SUB        EAX,EBP
    //         0054d5c1     CMP        EAX,EBX
    //         0054d5c3     JC         LAB_0054d546
    //                               LAB_0054d5c5                                                 XREF[2]:     0054d5bb(j), 0054d679(j)  
    //         0054d5c5     MOV        ESI,dword ptr [ESP + 0x14]
    //                               LAB_0054d5c9                                                 XREF[3]:     0054d540(j), 0054d6aa(j), 
    //                                                                                                         0054d6b9(j)  
    //         0054d5c9     MOV        EAX,dword ptr [ESP + local_41c]
    //         0054d5cd     TEST       EAX,EAX
    //         0054d5cf     JNZ        LAB_0054d63e
    //         0054d5d1     MOV        EAX,dword ptr [ESP + local_414]
    //         0054d5d5     TEST       EAX,EAX
    //         0054d5d7     JZ         LAB_0054d612
    //         0054d5d9     CMP        EAX,0x5
    //         0054d5dc     JNZ        LAB_0054d5fb
    //         0054d5de     MOV        [__doserrno],EAX
    //         0054d5e3     MOV        dword ptr [_errno],0x9                           = align(4)
    //         0054d5ed     OR         EAX,0xffffffff
    //         0054d5f0     POP        EDI
    //         0054d5f1     POP        ESI
    //         0054d5f2     POP        EBP
    //         0054d5f3     POP        EBX
    //         0054d5f4     ADD        ESP,0x41c
    //         0054d5fa     RET
    //                               LAB_0054d5fb                                                 XREF[1]:     0054d5dc(j)  
    //         0054d5fb     PUSH       EAX
    //         0054d5fc     CALL       __dosmaperr                                      undefined __dosmaperr()
    //         0054d601     ADD        ESP,0x4
    //         0054d604     OR         EAX,0xffffffff
    //         0054d607     POP        EDI
    //         0054d608     POP        ESI
    //         0054d609     POP        EBP
    //         0054d60a     POP        EBX
    //         0054d60b     ADD        ESP,0x41c
    //         0054d611     RET
    //                               LAB_0054d612                                                 XREF[1]:     0054d5d7(j)  
    //         0054d612     MOV        ECX,dword ptr [ESP + 0x24]
    //         0054d616     MOV        EDX,dword ptr [ECX]
    //         0054d618     TEST       byte ptr [ESI + EDX*0x1 + 0x4],0x40
    //         0054d61d     JZ         LAB_0054d632
    //         0054d61f     CMP        byte ptr [EBP],0x1a
    //         0054d623     JNZ        LAB_0054d632
    //         0054d625     XOR        EAX,EAX
    //         0054d627     POP        EDI
    //         0054d628     POP        ESI
    //         0054d629     POP        EBP
    //         0054d62a     POP        EBX
    //         0054d62b     ADD        ESP,0x41c
    //         0054d631     RET
    //                               LAB_0054d632                                                 XREF[2]:     0054d61d(j), 0054d623(j)  
    //         0054d632     MOV        dword ptr [_errno],0x1c                          = align(4)
    //         0054d63c     JMP        LAB_0054d657
    //                               LAB_0054d63e                                                 XREF[1]:     0054d5cf(j)  
    //         0054d63e     SUB        EAX,dword ptr [ESP + 0x20]
    //         0054d642     POP        EDI
    //         0054d643     POP        ESI
    //         0054d644     POP        EBP
    //         0054d645     POP        EBX
    //         0054d646     ADD        ESP,0x41c
    //         0054d64c     RET
    //                               LAB_0054d64d                                                 XREF[2]:     0054d4b6(j), 0054d4e6(j)  
    //         0054d64d     MOV        dword ptr [_errno],0x9                           = align(4)
    //                               LAB_0054d657                                                 XREF[1]:     0054d63c(j)  
    //         0054d657     POP        EDI
    //         0054d658     POP        ESI
    //         0054d659     POP        EBP
    //         0054d65a     MOV        dword ptr [__doserrno],0x0
    //         0054d664     OR         EAX,0xffffffff
    //         0054d667     POP        EBX
    //         0054d668     ADD        ESP,0x41c
    //         0054d66e     RET
    //                               LAB_0054d66f                                                 XREF[1]:     0054d5a5(j)  
    //         0054d66f     CALL       dword ptr [->KERNEL32.DLL::GetLastError]         = 0048aa76
    //         0054d675     MOV        dword ptr [ESP + 0x18],EAX
    //         0054d679     JMP        LAB_0054d5c5
    //                               LAB_0054d67e                                                 XREF[1]:     0054d527(j)  
    //         0054d67e     MOV        EDX,dword ptr [EAX]
    //         0054d680     LEA        ECX=>local_410,[ESP + 0x1c]
    //         0054d684     PUSH       EBP
    //         0054d685     MOV        EBP,dword ptr [ESP + Stack[0x8]]
    //         0054d68c     PUSH       ECX
    //         0054d68d     PUSH       EBX
    //         0054d68e     PUSH       EBP
    //         0054d68f     PUSH       EDX
    //         0054d690     CALL       dword ptr [->KERNEL32.DLL::WriteFile]            = 0048b762
    //         0054d696     TEST       EAX,EAX
    //         0054d698     JZ         LAB_0054d6af
    //         0054d69a     MOV        EAX,dword ptr [ESP + 0x1c]
    //         0054d69e     MOV        dword ptr [ESP + 0x18],0x0
    //         0054d6a6     MOV        dword ptr [ESP + 0x10],EAX
    //         0054d6aa     JMP        LAB_0054d5c9
    //                               LAB_0054d6af                                                 XREF[1]:     0054d698(j)  
    //         0054d6af     CALL       dword ptr [->KERNEL32.DLL::GetLastError]         = 0048aa76
    //         0054d6b5     MOV        dword ptr [ESP + 0x18],EAX
    //         0054d6b9     JMP        LAB_0054d5c9
}

// Offset: 0x0054D6C0
undefined fscanf() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * fscanf                                                                                                *
    //                              *********************************************************************************************************
    //                              undefined __cdecl fscanf()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               _fscanf                                                      XREF[86]:    setup:0044f419(c), 
    //                               fscanf                                                                    setup:0044fbd0(c), 
    //                                                                                                         setup:004504e9(c), 
    //                                                                                                         setup:0045052d(c), 
    //                                                                                                         setup:00450586(c), 
    //                                                                                                         RGE_RMM_Database_Controller:00482b
    //                                                                                                         RGE_RMM_Database_Controller:00482c
    //                                                                                                         RGE_RMM_Database_Controller:00482c
    //                                                                                                         RGE_RMM_Database_Controller:00482c
    //                                                                                                         RGE_RMM_Database_Controller:00482c
    //                                                                                                         RGE_RMM_Database_Controller:00482d
    //                                                                                                         RGE_RMM_Database_Controller:00482d
    //                                                                                                         RGE_RMM_Database_Controller:00482e
    //                                                                                                         RGE_RMM_Database_Controller:00482e
    //                                                                                                         RGE_RMM_Database_Controller:00482e
    //                                                                                                         RGE_RMM_Database_Controller:00482e
    //                                                                                                         RGE_RMM_Database_Controller:00482f
    //                                                                                                         RGE_RMM_Database_Controller:00482f
    //                                                                                                         RGE_RMM_Database_Controller:00482f
    //                                                                                                         setup:0050e3c0(c), [more]
    //         0054d6c0     MOV        ECX,dword ptr [ESP + Stack[0x8]]
    //         0054d6c4     MOV        EDX,dword ptr [ESP + Stack[0x4]]
    //         0054d6c8     LEA        EAX=>Stack[0xc],[ESP + 0xc]
    //         0054d6cc     PUSH       EAX
    //         0054d6cd     PUSH       ECX
    //         0054d6ce     PUSH       EDX
    //         0054d6cf     CALL       __input                                          undefined __input()
    //         0054d6d4     ADD        ESP,0xc
    //         0054d6d7     RET
}

// Offset: 0x0054D6E0
void eh_vector_constructor_iterator(void* param_1, uint param_2, int param_3, _func_void_void_ptr* param_4, _func_void_void_ptr* param_5) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * void __stdcall `eh vector constructor iterator'(void *,unsigned int,int,void (__thiscall*)(void *)... *
    //                              *********************************************************************************************************
    //                              void __stdcall `eh_vector_constructor_iterator'(void * param_1, uint
    //              void              <VOID>         <RETURN>
    //              void *            Stack[0x4]:4   param_1                   XREF[2]:     0054d711(R), 0054d720(W)  
    //              uint              Stack[0x8]:4   param_2                   XREF[1]:     0054d70e(R)  
    //              int               Stack[0xc]:4   param_3                   XREF[1]:     0054d714(R)  
    //              _func_void_voi    Stack[0x10]:4  param_4                   XREF[1]:     0054d71b(R)  
    //              _func_void_voi    Stack[0x14]:4  param_5
    //              undefined4        Stack[-0x8]:4  local_8                   XREF[2]:     0054d708(W), 0054d730(W)  
    //              undefined4        Stack[-0x14]:4 local_14                  XREF[1]:     0054d73c(R)  
    //              undefined4        Stack[-0x20]:4 local_20                  XREF[2]:     0054d70b(W), 0054d724(W)  
    //              undefined4        Stack[-0x24]:4 local_24                  XREF[2]:     0054d705(W), 0054d729(W)  
    //                               ??_L@YGXPAXIHP6EX0@Z1@Z                                      XREF[4]:     RGE_Communications_Addresses:00424
    //                               `eh_vector_constructor_iterator'                                          TCommunications_Handler:00425d3c(c
    //                                                                                                         TCommunications_Handler:00425d89(c
    //                                                                                                         AllocateQueue:0043187b(c)  
    //         0054d6e0     PUSH       EBP
    //         0054d6e1     MOV        EBP,ESP
    //         0054d6e3     PUSH       -0x1
    //         0054d6e5     PUSH       DAT_00577a58                                     = FFh
    //         0054d6ea     PUSH       __except_handler3
    //         0054d6ef     MOV        EAX,FS:[0x0]
    //         0054d6f5     PUSH       EAX
    //         0054d6f6     MOV        dword ptr FS:[0x0],ESP
    //         0054d6fd     ADD        ESP,-0x10
    //         0054d700     PUSH       EBX
    //         0054d701     PUSH       ESI
    //         0054d702     PUSH       EDI
    //         0054d703     XOR        ESI,ESI
    //         0054d705     MOV        dword ptr [EBP + local_24],ESI
    //         0054d708     MOV        dword ptr [EBP + local_8],ESI
    //         0054d70b     MOV        dword ptr [EBP + local_20],ESI
    //         0054d70e     MOV        EBX,dword ptr [EBP + param_2]
    //         0054d711     MOV        EDI,dword ptr [EBP + param_1]
    //                               LAB_0054d714                                                 XREF[1]:     0054d727(j)  
    //         0054d714     CMP        ESI,dword ptr [EBP + param_3]
    //         0054d717     JGE        LAB_0054d729
    //         0054d719     MOV        ECX,EDI
    //         0054d71b     CALL       dword ptr [EBP + param_4]
    //         0054d71e     ADD        EDI,EBX
    //         0054d720     MOV        dword ptr [EBP + param_1],EDI
    //         0054d723     INC        ESI
    //         0054d724     MOV        dword ptr [EBP + local_20],ESI
    //         0054d727     JMP        LAB_0054d714
    //                               LAB_0054d729                                                 XREF[1]:     0054d717(j)  
    //         0054d729     MOV        dword ptr [EBP + local_24],0x1
    //         0054d730     MOV        dword ptr [EBP + local_8],0xffffffff
    //         0054d737     CALL       FUN_0054d758                                     undefined FUN_0054d758()
    //         0054d73c     MOV        ECX,dword ptr [EBP + local_14]
    //         0054d73f     MOV        dword ptr FS:[0x0],ECX
    //         0054d746     POP        EDI
    //         0054d747     POP        ESI
    //         0054d748     POP        EBX
    //         0054d749     MOV        ESP,EBP
    //         0054d74b     POP        EBP
    //         0054d74c     RET        0x14
}

// Offset: 0x0054D74F
undefined FUN_0054d74f() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0054d74f()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0054d74f
    //         0054d74f     MOV        EBX,dword ptr [EBP + 0xc]
    //         0054d752     MOV        EDI,dword ptr [EBP + 0x8]
    //         0054d755     MOV        ESI,dword ptr [EBP + -0x1c]
}

// Offset: 0x0054D758
undefined FUN_0054d758() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0054d758()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0054d758                                                 XREF[1]:     `eh_vector_constructor_iterator':0
    //         0054d758     MOV        EAX,dword ptr [EBP + -0x20]
    //         0054d75b     TEST       EAX,EAX
    //         0054d75d     JNZ        LAB_0054d76b
    //         0054d75f     MOV        EAX,dword ptr [EBP + 0x18]
    //         0054d762     PUSH       EAX
    //         0054d763     PUSH       ESI
    //         0054d764     PUSH       EBX
    //         0054d765     PUSH       EDI
    //         0054d766     CALL       __ArrayUnwind                                    void __ArrayUnwind(void * param_1, uint param
    //                               LAB_0054d76b                                                 XREF[1]:     0054d75d(j)  
    //         0054d76b     RET
}

// Offset: 0x0054D76C
undefined FUN_0054d76c() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0054d76c()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0054d76c
    //         0054d76c     MOV        ECX,dword ptr [EBP + DAT_fffffff0]
    //         0054d76f     MOV        dword ptr FS:[0x0],ECX
    //         0054d776     POP        EDI
    //         0054d777     POP        ESI
    //         0054d778     POP        EBX
    //         0054d779     MOV        ESP,EBP
    //         0054d77b     POP        EBP
    //         0054d77c     RET        0x14
}

// Offset: 0x0054D780
void eh_vector_destructor_iterator(void* param_1, uint param_2, int param_3, _func_void_void_ptr* param_4) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * void __stdcall `eh vector destructor iterator'(void *,unsigned int,int,void (__thiscall*)(void *))    *
    //                              *********************************************************************************************************
    //                              void __stdcall `eh_vector_destructor_iterator'(void * param_1, uint 
    //              void              <VOID>         <RETURN>
    //              void *            Stack[0x4]:4   param_1                   XREF[3]:     0054d7b1(R), 0054d7b6(W), 0054d7c3(W)  
    //              uint              Stack[0x8]:4   param_2                   XREF[1]:     0054d7ab(R)  
    //              int               Stack[0xc]:4   param_3                   XREF[2]:     0054d7a8(R), 0054d7bc(RW)  
    //              _func_void_voi    Stack[0x10]:4  param_4                   XREF[1]:     0054d7c8(R)  
    //              undefined4        Stack[-0x8]:4  local_8                   XREF[2]:     0054d7b9(W), 0054d7d4(W)  
    //              undefined4        Stack[-0x14]:4 local_14                  XREF[1]:     0054d7e0(R)  
    //              undefined4        Stack[-0x20]:4 local_20                  XREF[2]:     0054d7a5(W), 0054d7cd(W)  
    //                               ??_M@YGXPAXIHP6EX0@Z@Z                                       XREF[9]:     `vector_deleting_destructor':00424
    //                               `eh_vector_destructor_iterator'                                           ~RGE_Communications_Addresses:0042
    //                                                                                                         `vector_deleting_destructor':00426
    //                                                                                                         `vector_deleting_destructor':00426
    //                                                                                                         ~TCommunications_Handler:00426291(
    //                                                                                                         ~TCommunications_Handler:004262b8(
    //                                                                                                         ~RGE_Communications_Queue:0043177a
    //                                                                                                         `vector_deleting_destructor':00431
    //                                                                                                         AllocateQueue:004319a7(c)  
    //         0054d780     PUSH       EBP
    //         0054d781     MOV        EBP,ESP
    //         0054d783     PUSH       -0x1
    //         0054d785     PUSH       DAT_00577a68                                     = FFh
    //         0054d78a     PUSH       __except_handler3
    //         0054d78f     MOV        EAX,FS:[0x0]
    //         0054d795     PUSH       EAX
    //         0054d796     MOV        dword ptr FS:[0x0],ESP
    //         0054d79d     ADD        ESP,-0xc
    //         0054d7a0     PUSH       EBX
    //         0054d7a1     PUSH       ESI
    //         0054d7a2     PUSH       EDI
    //         0054d7a3     XOR        EAX,EAX
    //         0054d7a5     MOV        dword ptr [EBP + local_20],EAX
    //         0054d7a8     MOV        ECX,dword ptr [EBP + param_3]
    //         0054d7ab     MOV        EDI,dword ptr [EBP + param_2]
    //         0054d7ae     IMUL       ECX,EDI
    //         0054d7b1     MOV        ESI,dword ptr [EBP + param_1]
    //         0054d7b4     ADD        ESI,ECX
    //         0054d7b6     MOV        dword ptr [EBP + param_1],ESI
    //         0054d7b9     MOV        dword ptr [EBP + local_8],EAX
    //                               LAB_0054d7bc                                                 XREF[1]:     0054d7cb(j)  
    //         0054d7bc     DEC        dword ptr [EBP + param_3]
    //         0054d7bf     JS         LAB_0054d7cd
    //         0054d7c1     SUB        ESI,EDI
    //         0054d7c3     MOV        dword ptr [EBP + param_1],ESI
    //         0054d7c6     MOV        ECX,ESI
    //         0054d7c8     CALL       dword ptr [EBP + param_4]
    //         0054d7cb     JMP        LAB_0054d7bc
    //                               LAB_0054d7cd                                                 XREF[1]:     0054d7bf(j)  
    //         0054d7cd     MOV        dword ptr [EBP + local_20],0x1
    //         0054d7d4     MOV        dword ptr [EBP + local_8],0xffffffff
    //         0054d7db     CALL       FUN_0054d7f9                                     undefined FUN_0054d7f9()
    //         0054d7e0     MOV        ECX,dword ptr [EBP + local_14]
    //         0054d7e3     MOV        dword ptr FS:[0x0],ECX
    //         0054d7ea     POP        EDI
    //         0054d7eb     POP        ESI
    //         0054d7ec     POP        EBX
    //         0054d7ed     MOV        ESP,EBP
    //         0054d7ef     POP        EBP
    //         0054d7f0     RET        0x10
}

// Offset: 0x0054D7F3
undefined FUN_0054d7f3() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0054d7f3()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0054d7f3
    //         0054d7f3     MOV        EDI,dword ptr [EBP + 0xc]
    //         0054d7f6     MOV        ESI,dword ptr [EBP + 0x8]
}

// Offset: 0x0054D7F9
undefined FUN_0054d7f9() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0054d7f9()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0054d7f9                                                 XREF[1]:     `eh_vector_destructor_iterator':00
    //         0054d7f9     MOV        EAX,dword ptr [EBP + -0x1c]
    //         0054d7fc     TEST       EAX,EAX
    //         0054d7fe     JNZ        LAB_0054d80f
    //         0054d800     MOV        EDX,dword ptr [EBP + 0x14]
    //         0054d803     PUSH       EDX
    //         0054d804     MOV        EAX,dword ptr [EBP + 0x10]
    //         0054d807     PUSH       EAX
    //         0054d808     PUSH       EDI
    //         0054d809     PUSH       ESI
    //         0054d80a     CALL       __ArrayUnwind                                    void __ArrayUnwind(void * param_1, uint param
    //                               LAB_0054d80f                                                 XREF[1]:     0054d7fe(j)  
    //         0054d80f     RET
}

// Offset: 0x0054D810
undefined FUN_0054d810() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0054d810()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0054d810
    //         0054d810     MOV        ECX,dword ptr [EBP + DAT_fffffff0]
    //         0054d813     MOV        dword ptr FS:[0x0],ECX
    //         0054d81a     POP        EDI
    //         0054d81b     POP        ESI
    //         0054d81c     POP        EBX
    //         0054d81d     MOV        ESP,EBP
    //         0054d81f     POP        EBP
    //         0054d820     RET        0x10
}

// Offset: 0x0054D830
void ArrayUnwind(void* param_1, uint param_2, int param_3, _func_void_void_ptr* param_4) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * void __stdcall __ArrayUnwind(void *,unsigned int,int,void (__thiscall*)(void *))                      *
    //                              *********************************************************************************************************
    //                              void __stdcall __ArrayUnwind(void * param_1, uint param_2, int param
    //              void              <VOID>         <RETURN>
    //              void *            Stack[0x4]:4   param_1                   XREF[2]:     0054d862(R), 0054d868(W)  
    //              uint              Stack[0x8]:4   param_2                   XREF[1]:     0054d865(R)  
    //              int               Stack[0xc]:4   param_3                   XREF[1]:     0054d85d(RW)  
    //              _func_void_voi    Stack[0x10]:4  param_4                   XREF[1]:     0054d86b(R)  
    //              undefined4        Stack[-0x8]:4  local_8                   XREF[1]:     0054d856(W)  
    //              undefined4        Stack[-0x14]:4 local_14
    //              undefined4        Stack[-0x1c]:4 local_1c                  XREF[1]:     0054d853(W)  
    //                               ?__ArrayUnwind@@YGXPAXIHP6EX0@Z@Z                            XREF[2]:     FUN_0054d758:0054d766(c), 
    //                               __ArrayUnwind                                                             FUN_0054d7f9:0054d80a(c)  
    //         0054d830     PUSH       EBP
    //         0054d831     MOV        EBP,ESP
    //         0054d833     PUSH       -0x1
    //         0054d835     PUSH       DAT_00577a78                                     = FFh
    //         0054d83a     PUSH       __except_handler3
    //         0054d83f     MOV        EAX,FS:[0x0]
    //         0054d845     PUSH       EAX
    //         0054d846     MOV        dword ptr FS:[0x0],ESP
    //         0054d84d     SUB        ESP,0x8
    //         0054d850     PUSH       EBX
    //         0054d851     PUSH       ESI
    //         0054d852     PUSH       EDI
    //         0054d853     MOV        dword ptr [EBP + local_1c],ESP
    //         0054d856     MOV        dword ptr [EBP + local_8],0x0
    //                               LAB_0054d85d                                                 XREF[1]:     0054d86e(j)  
    //         0054d85d     DEC        dword ptr [EBP + param_3]
    //         0054d860     JS         LAB_0054d880
    //         0054d862     MOV        ECX,dword ptr [EBP + param_1]
    //         0054d865     SUB        ECX,dword ptr [EBP + param_2]
    //         0054d868     MOV        dword ptr [EBP + param_1],ECX
    //         0054d86b     CALL       dword ptr [EBP + param_4]
    //         0054d86e     JMP        LAB_0054d85d
}

// Offset: 0x0054D870
undefined FUN_0054d870() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0054d870()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0054d870
    //         0054d870     MOV        EAX,dword ptr [EBP + -0x14]
    //         0054d873     PUSH       EAX
    //         0054d874     CALL       FUN_0054d8a0                                     undefined FUN_0054d8a0()
    //         0054d879     ADD        ESP,0x4
    //         0054d87c     RET
}

// Offset: 0x0054D87D
undefined FUN_0054d87d() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0054d87d()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0054d87d
    //         0054d87d     MOV        ESP,dword ptr [EBP + -0x18]
    //                               LAB_0054d880                                                 XREF[1]:     __ArrayUnwind:0054d860(j)  
    //         0054d880     MOV        dword ptr [EBP + -0x4],0xffffffff
    //         0054d887     MOV        ECX,dword ptr [EBP + -0x10]
    //         0054d88a     MOV        dword ptr FS:[0x0],ECX
    //         0054d891     POP        EDI
    //         0054d892     POP        ESI
    //         0054d893     POP        EBX
    //         0054d894     MOV        ESP,EBP
    //         0054d896     POP        EBP
    //         0054d897     RET        0x10
}

// Offset: 0x0054D8A0
undefined FUN_0054d8a0() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0054d8a0()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0054d8a0                                                 XREF[1]:     FUN_0054d870:0054d874(c)  
    //         0054d8a0     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         0054d8a4     MOV        ECX,dword ptr [EAX]
    //         0054d8a6     CMP        dword ptr [ECX],0xe06d7363
    //         0054d8ac     JNZ        LAB_0054d8b3
    //         0054d8ae     CALL       terminate                                        void terminate(void)
    //                               LAB_0054d8b3                                                 XREF[1]:     0054d8ac(j)  
    //         0054d8b3     XOR        EAX,EAX
    //         0054d8b5     RET
}

// Offset: 0x0054D8C0
undefined fputs() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * fputs                                                                                                 *
    //                              *********************************************************************************************************
    //                              undefined __cdecl fputs()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               _fputs                                                       XREF[33]:    LogChecksums:004334fb(c), 
    //                               fputs                                                                     LogChecksums:00433509(c), 
    //                                                                                                         LogChecksums:00433541(c), 
    //                                                                                                         LogChecksums:0043354f(c), 
    //                                                                                                         LogChecksums:004335b5(c), 
    //                                                                                                         LogChecksums:004335c3(c), 
    //                                                                                                         LogChecksums:00433611(c), 
    //                                                                                                         LogChecksums:0043361f(c), 
    //                                                                                                         LogChecksums:00433668(c), 
    //                                                                                                         LogChecksums:00433676(c), 
    //                                                                                                         LogChecksums:004336bb(c), 
    //                                                                                                         LogChecksums:004336c9(c), 
    //                                                                                                         LogChecksums:0043370f(c), 
    //                                                                                                         LogChecksums:0043371d(c), 
    //                                                                                                         LogChecksums:00433763(c), 
    //                                                                                                         LogChecksums:00433771(c), 
    //                                                                                                         LogChecksums:004337b6(c), 
    //                                                                                                         LogChecksums:004337c4(c), 
    //                                                                                                         LogChecksums:0043380a(c), 
    //                                                                                                         LogChecksums:00433818(c), [more]
    //         0054d8c0     PUSH       EBX
    //         0054d8c1     MOV        EBX,dword ptr [ESP + Stack[0x4]]
    //         0054d8c5     PUSH       EBP
    //         0054d8c6     PUSH       ESI
    //         0054d8c7     PUSH       EDI
    //         0054d8c8     MOV        EDI,EBX
    //         0054d8ca     OR         ECX,0xffffffff
    //         0054d8cd     XOR        EAX,EAX
    //         0054d8cf     SCASB.RE   ES:EDI
    //         0054d8d1     MOV        EDI,dword ptr [ESP + Stack[0x8]]
    //         0054d8d5     NOT        ECX
    //         0054d8d7     DEC        ECX
    //         0054d8d8     PUSH       EDI
    //         0054d8d9     MOV        ESI,ECX
    //         0054d8db     CALL       __stbuf                                          undefined __stbuf()
    //         0054d8e0     ADD        ESP,0x4
    //         0054d8e3     MOV        EBP,EAX
    //         0054d8e5     PUSH       EDI
    //         0054d8e6     PUSH       ESI
    //         0054d8e7     PUSH       0x1
    //         0054d8e9     PUSH       EBX
    //         0054d8ea     CALL       fwrite                                           undefined fwrite()
    //         0054d8ef     ADD        ESP,0x10
    //         0054d8f2     MOV        EBX,EAX
    //         0054d8f4     PUSH       EDI
    //         0054d8f5     PUSH       EBP
    //         0054d8f6     CALL       __ftbuf                                          undefined __ftbuf()
    //         0054d8fb     ADD        ESP,0x8
    //         0054d8fe     MOV        EAX,EBX
    //         0054d900     SUB        EAX,ESI
    //         0054d902     POP        EDI
    //         0054d903     POP        ESI
    //         0054d904     NEG        EAX
    //         0054d906     POP        EBP
    //         0054d907     POP        EBX
    //         0054d908     SBB        EAX,EAX
    //         0054d90a     RET
}

// Offset: 0x0054D910
undefined strncat() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * strncat                                                                                               *
    //                              *********************************************************************************************************
    //                              undefined __cdecl strncat()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               _strncat                                                     XREF[2]:     Log:00436713(c), 
    //                               strncat                                                                   __mbsncat:0054c7f7(c)  
    //         0054d910     MOV        ECX,dword ptr [ESP + Stack[0xc]]
    //         0054d914     PUSH       EDI
    //         0054d915     TEST       ECX,ECX
    //         0054d917     JZ         LAB_0054d9c4
    //         0054d91d     MOV        EDI,dword ptr [ESP + Stack[0x4]]
    //         0054d921     PUSH       ESI
    //         0054d922     TEST       EDI,0x3
    //         0054d928     PUSH       EBX
    //         0054d929     JZ         LAB_0054d93a
    //                               LAB_0054d92b                                                 XREF[1]:     0054d938(j)  
    //         0054d92b     MOV        AL,byte ptr [EDI]
    //         0054d92d     INC        EDI
    //         0054d92e     TEST       AL,AL
    //         0054d930     JZ         LAB_0054d96b
    //         0054d932     TEST       EDI,0x3
    //         0054d938     JNZ        LAB_0054d92b
    //                               LAB_0054d93a                                                 XREF[3]:     0054d929(j), 0054d950(j), 
    //                                                                                                         0054d969(j)  
    //         0054d93a     MOV        EAX,dword ptr [EDI]
    //         0054d93c     MOV        EDX,0x7efefeff
    //         0054d941     ADD        EDX,EAX
    //         0054d943     XOR        EAX,0xffffffff
    //         0054d946     XOR        EAX,EDX
    //         0054d948     ADD        EDI,0x4
    //         0054d94b     TEST       EAX,0x81010100
    //         0054d950     JZ         LAB_0054d93a
    //         0054d952     MOV        EAX,dword ptr [EDI + -0x4]
    //         0054d955     TEST       AL,AL
    //         0054d957     JZ         LAB_0054d978
    //         0054d959     TEST       AH,AH
    //         0054d95b     JZ         LAB_0054d973
    //         0054d95d     TEST       EAX,0xff0000
    //         0054d962     JZ         LAB_0054d96e
    //         0054d964     TEST       EAX,0xff000000
    //         0054d969     JNZ        LAB_0054d93a
    //                               LAB_0054d96b                                                 XREF[1]:     0054d930(j)  
    //         0054d96b     DEC        EDI
    //         0054d96c     JMP        LAB_0054d97b
    //                               LAB_0054d96e                                                 XREF[1]:     0054d962(j)  
    //         0054d96e     SUB        EDI,0x2
    //         0054d971     JMP        LAB_0054d97b
    //                               LAB_0054d973                                                 XREF[1]:     0054d95b(j)  
    //         0054d973     SUB        EDI,0x3
    //         0054d976     JMP        LAB_0054d97b
    //                               LAB_0054d978                                                 XREF[1]:     0054d957(j)  
    //         0054d978     SUB        EDI,0x4
    //                               LAB_0054d97b                                                 XREF[3]:     0054d96c(j), 0054d971(j), 
    //                                                                                                         0054d976(j)  
    //         0054d97b     MOV        ESI,dword ptr [ESP + Stack[0x8]]
    //         0054d97f     TEST       ESI,0x3
    //         0054d985     JNZ        LAB_0054d990
    //         0054d987     MOV        EBX,ECX
    //         0054d989     SHR        ECX,0x2
    //         0054d98c     JNZ        LAB_0054d9dc
    //         0054d98e     JMP        LAB_0054d9ac
    //                               LAB_0054d990                                                 XREF[2]:     0054d985(j), 0054d9a3(j)  
    //         0054d990     MOV        DL,byte ptr [ESI]
    //         0054d992     INC        ESI
    //         0054d993     TEST       DL,DL
    //         0054d995     JZ         LAB_0054d9ca
    //         0054d997     MOV        byte ptr [EDI],DL
    //         0054d999     INC        EDI
    //         0054d99a     DEC        ECX
    //         0054d99b     JZ         LAB_0054d9c0
    //         0054d99d     TEST       ESI,0x3
    //         0054d9a3     JNZ        LAB_0054d990
    //         0054d9a5     MOV        EBX,ECX
    //         0054d9a7     SHR        ECX,0x2
    //         0054d9aa     JNZ        LAB_0054d9dc
    //                               LAB_0054d9ac                                                 XREF[2]:     0054d98e(j), 0054d9da(j)  
    //         0054d9ac     MOV        ECX,EBX
    //         0054d9ae     AND        ECX,0x3
    //         0054d9b1     JZ         LAB_0054d9c0
    //                               LAB_0054d9b3                                                 XREF[1]:     0054d9be(j)  
    //         0054d9b3     MOV        DL,byte ptr [ESI]
    //         0054d9b5     INC        ESI
    //         0054d9b6     MOV        byte ptr [EDI],DL
    //         0054d9b8     INC        EDI
    //         0054d9b9     TEST       DL,DL
    //         0054d9bb     JZ         LAB_0054d9c2
    //         0054d9bd     DEC        ECX
    //         0054d9be     JNZ        LAB_0054d9b3
    //                               LAB_0054d9c0                                                 XREF[2]:     0054d99b(j), 0054d9b1(j)  
    //         0054d9c0     MOV        byte ptr [EDI],CL
    //                               LAB_0054d9c2                                                 XREF[1]:     0054d9bb(j)  
    //         0054d9c2     POP        EBX
    //         0054d9c3     POP        ESI
    //                               LAB_0054d9c4                                                 XREF[1]:     0054d917(j)  
    //         0054d9c4     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         0054d9c8     POP        EDI
    //         0054d9c9     RET
    //                               LAB_0054d9ca                                                 XREF[2]:     0054d995(j), 0054d9f8(j)  
    //         0054d9ca     MOV        byte ptr [EDI],DL
    //         0054d9cc     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         0054d9d0     POP        EBX
    //         0054d9d1     POP        ESI
    //         0054d9d2     POP        EDI
    //         0054d9d3     RET
    //                               LAB_0054d9d4                                                 XREF[2]:     0054d9f4(j), 0054da0c(j)  
    //         0054d9d4     MOV        dword ptr [EDI],EDX
    //         0054d9d6     ADD        EDI,0x4
    //         0054d9d9     DEC        ECX
    //         0054d9da     JZ         LAB_0054d9ac
    //                               LAB_0054d9dc                                                 XREF[2]:     0054d98c(j), 0054d9aa(j)  
    //         0054d9dc     MOV        EDX,0x7efefeff
    //         0054d9e1     MOV        EAX,dword ptr [ESI]
    //         0054d9e3     ADD        EDX,EAX
    //         0054d9e5     XOR        EAX,0xffffffff
    //         0054d9e8     XOR        EAX,EDX
    //         0054d9ea     MOV        EDX,dword ptr [ESI]
    //         0054d9ec     ADD        ESI,0x4
    //         0054d9ef     TEST       EAX,0x81010100
    //         0054d9f4     JZ         LAB_0054d9d4
    //         0054d9f6     TEST       DL,DL
    //         0054d9f8     JZ         LAB_0054d9ca
    //         0054d9fa     TEST       DH,DH
    //         0054d9fc     JZ         LAB_0054da28
    //         0054d9fe     TEST       EDX,0xff0000
    //         0054da04     JZ         LAB_0054da18
    //         0054da06     TEST       EDX,0xff000000
    //         0054da0c     JNZ        LAB_0054d9d4
    //         0054da0e     MOV        dword ptr [EDI],EDX
    //         0054da10     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         0054da14     POP        EBX
    //         0054da15     POP        ESI
    //         0054da16     POP        EDI
    //         0054da17     RET
    //                               LAB_0054da18                                                 XREF[1]:     0054da04(j)  
    //         0054da18     MOV        word ptr [EDI],DX
    //         0054da1b     XOR        EDX,EDX
    //         0054da1d     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         0054da21     MOV        byte ptr [EDI + 0x2],DL
    //         0054da24     POP        EBX
    //         0054da25     POP        ESI
    //         0054da26     POP        EDI
    //         0054da27     RET
    //                               LAB_0054da28                                                 XREF[1]:     0054d9fc(j)  
    //         0054da28     MOV        word ptr [EDI],DX
    //         0054da2b     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         0054da2f     POP        EBX
    //         0054da30     POP        ESI
    //         0054da31     POP        EDI
    //         0054da32     RET
}

// Offset: 0x0054DA40
undefined ctime() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * ctime                                                                                                 *
    //                              *********************************************************************************************************
    //                              undefined __cdecl ctime()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               _ctime                                                       XREF[2]:     Log:00436705(c), 
    //                               ctime                                                                     run_log:005210a7(c)  
    //         0054da40     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         0054da44     PUSH       EAX
    //         0054da45     CALL       localtime                                        undefined localtime()
    //         0054da4a     ADD        ESP,0x4
    //         0054da4d     TEST       EAX,EAX
    //         0054da4f     JZ         LAB_0054da5b
    //         0054da51     PUSH       EAX
    //         0054da52     CALL       asctime                                          undefined asctime()
    //         0054da57     ADD        ESP,0x4
    //         0054da5a     RET
    //                               LAB_0054da5b                                                 XREF[1]:     0054da4f(j)  
    //         0054da5b     XOR        EAX,EAX
    //         0054da5d     RET
}

// Offset: 0x0054DA60
undefined memset() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * memset                                                                                                *
    //                              *********************************************************************************************************
    //                              undefined __cdecl memset()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               _memset                                                      XREF[31]:    CheckSurfaces:00442f92(c), 
    //                               memset                                                                    CreateSurfaces:00443133(c), 
    //                                                                                                         TDrawArea:00443e80(c), 
    //                                                                                                         CheckSurface:00444162(c), 
    //                                                                                                         SetSize:004444d2(c), 
    //                                                                                                         SetSize:004444ee(c), 
    //                                                                                                         Clear:004446ed(c), 
    //                                                                                                         Clear:004447ae(c), 
    //                                                                                                         DrawHorzLine:00445ad8(c), 
    //                                                                                                         FillRect:00445c5b(c), 
    //                                                                                                         ds_stream_file:004487e9(c), 
    //                                                                                                         ds_stream_file:00448949(c), 
    //                                                                                                         shape_draw_unclipped:004b98a6(c), 
    //                                                                                                         shape_color_trans_unclipped:004b99
    //                                                                                                         shape_draw_clipped:004b9cb4(c), 
    //                                                                                                         shape_draw_clipped:004b9d97(c), 
    //                                                                                                         shape_color_trans_clipped:004ba01e
    //                                                                                                         shape_color_trans_clipped:004ba12f
    //                                                                                                         shape_mirror_unclipped:004ba9b1(c)
    //                                                                                                         shape_mirror_color_trans_unclipped
    //                                                                                                         [more]
    //         0054da60     MOV        EDX,dword ptr [ESP + Stack[0xc]]
    //         0054da64     MOV        ECX,dword ptr [ESP + Stack[0x4]]
    //         0054da68     TEST       EDX,EDX
    //         0054da6a     JZ         LAB_0054dab3
    //         0054da6c     XOR        EAX,EAX
    //         0054da6e     MOV        AL,byte ptr [ESP + Stack[0x8]]
    //         0054da72     PUSH       EDI
    //         0054da73     MOV        EDI,ECX
    //         0054da75     CMP        EDX,0x4
    //         0054da78     JC         LAB_0054daa7
    //         0054da7a     NEG        ECX
    //         0054da7c     AND        ECX,0x3
    //         0054da7f     JZ         LAB_0054da89
    //         0054da81     SUB        EDX,ECX
    //                               LAB_0054da83                                                 XREF[1]:     0054da87(j)  
    //         0054da83     MOV        byte ptr [EDI],AL
    //         0054da85     INC        EDI
    //         0054da86     DEC        ECX
    //         0054da87     JNZ        LAB_0054da83
    //                               LAB_0054da89                                                 XREF[1]:     0054da7f(j)  
    //         0054da89     MOV        ECX,EAX
    //         0054da8b     SHL        EAX,0x8
    //         0054da8e     ADD        EAX,ECX
    //         0054da90     MOV        ECX,EAX
    //         0054da92     SHL        EAX,0x10
    //         0054da95     ADD        EAX,ECX
    //         0054da97     MOV        ECX,EDX
    //         0054da99     AND        EDX,0x3
    //         0054da9c     SHR        ECX,0x2
    //         0054da9f     JZ         LAB_0054daa7
    //         0054daa1     STOSD.REP  ES:EDI
    //         0054daa3     TEST       EDX,EDX
    //         0054daa5     JZ         LAB_0054daad
    //                               LAB_0054daa7                                                 XREF[3]:     0054da78(j), 0054da9f(j), 
    //                                                                                                         0054daab(j)  
    //         0054daa7     MOV        byte ptr [EDI],AL
    //         0054daa9     INC        EDI
    //         0054daaa     DEC        EDX
    //         0054daab     JNZ        LAB_0054daa7
    //                               LAB_0054daad                                                 XREF[1]:     0054daa5(j)  
    //         0054daad     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         0054dab1     POP        EDI
    //         0054dab2     RET
    //                               LAB_0054dab3                                                 XREF[1]:     0054da6a(j)  
    //         0054dab3     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         0054dab7     RET
}

// Offset: 0x0054DAC0
undefined memcpy() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * memcpy                                                                                                *
    //                              *********************************************************************************************************
    //                              undefined __cdecl memcpy()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               _memcpy                                                      XREF[14]:    DibBlt:00438984(c), 
    //                               memcpy                                                                    TransDibBlt:00438d56(c), 
    //                                                                                                         ReadPalette:0043982f(c), 
    //                                                                                                         DibWriteClipped:00439c30(c), 
    //                                                                                                         DibCopy:0043a4f1(c), 
    //                                                                                                         DibMapToPalette:0043a94b(c), 
    //                                                                                                         _DSFillSoundBuffer:00447c0d(c), 
    //                                                                                                         _DSFillSoundBuffer:00447c2a(c), 
    //                                                                                                         _WaveOpenFile:00447e56(c), 
    //                                                                                                         _WaveReadFile:00447fcd(c), 
    //                                                                                                         shape_draw_unclipped:004b987b(c), 
    //                                                                                                         shape_draw_clipped:004b9c57(c), 
    //                                                                                                         shape_draw_clipped:004b9d3b(c), 
    //                                                                                                         shape_draw_clipped:004b9d4c(c)  
    //         0054dac0     PUSH       EBP
    //         0054dac1     MOV        EBP,ESP
    //         0054dac3     PUSH       EDI
    //         0054dac4     PUSH       ESI
    //         0054dac5     MOV        ESI,dword ptr [EBP + Stack[0x8]]
    //         0054dac8     MOV        ECX,dword ptr [EBP + Stack[0xc]]
    //         0054dacb     MOV        EDI,dword ptr [EBP + Stack[0x4]]
    //         0054dace     MOV        EAX,ECX
    //         0054dad0     MOV        EDX,ECX
    //         0054dad2     ADD        EAX,ESI
    //         0054dad4     CMP        EDI,ESI
    //         0054dad6     JBE        LAB_0054dae0
    //         0054dad8     CMP        EDI,EAX
    //         0054dada     JC         LAB_0054dc58
    //                               LAB_0054dae0                                                 XREF[1]:     0054dad6(j)  
    //         0054dae0     TEST       EDI,0x3
    //         0054dae6     JNZ        LAB_0054dafc
    //         0054dae8     SHR        ECX,0x2
    //         0054daeb     AND        EDX,0x3
    //         0054daee     CMP        ECX,0x8
    //         0054daf1     JC         switchD_0054db1c::switchD
    //         0054daf3     MOVSD.REP  ES:EDI,ESI
    //                               switchD_0054daf5::switchD
    //         0054daf5     JMP        dword ptr [EDX*0x4 + switchD_0054daf5::switchd   = 0054dc18
    //                               LAB_0054dafc                                                 XREF[1]:     0054dae6(j)  
    //         0054dafc     MOV        EAX,EDI
    //         0054dafe     MOV        EDX,0x3
    //         0054db03     SUB        ECX,0x4
    //         0054db06     JC         switchD_0054db14::switchD
    //                               switchD_0054db14::default
    //         0054db08     AND        EAX,0x3
    //         0054db0b     ADD        ECX,EAX
    //                               switchD_0054db0d::switchD
    //         0054db0d     JMP        dword ptr [EAX*0x4 + 0x54db20]=>0054db28-0x4     = 0054db30
    //                               switchD_0054db14::switchD                                    XREF[1]:     0054db06(j)  
    //         0054db14     JMP        dword ptr [ECX*0x4 + 0x54dc18]
}

// Offset: 0x0054DB1B
undefined FUN_0054db1b() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0054db1b()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0054db1b
    //         0054db1b     NOP
    //                               switchD_0054db1c::switchD                                    XREF[4]:     memcpy:0054daf1(j), 
    //                                                                                                         caseD_1:0054db4e(j), 
    //                                                                                                         FUN_0054db59:0054db74(j), 
    //                                                                                                         FUN_0054db7f:0054db8e(j)  
    //         0054db1c     JMP        dword ptr [ECX*0x4 + switchD_0054db1c::switchd   = 0054dbff
}

// Offset: 0x0054DB30
undefined caseD_1() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined caseD_1()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               switchD_0054db0d::caseD_1                                    XREF[2]:     memcpy:0054db0d(j), 0054db24(*)  
    //         0054db30     AND        EDX,ECX
    //         0054db32     MOV        AL,byte ptr [ESI]
    //         0054db34     MOV        byte ptr [EDI],AL
    //         0054db36     MOV        AL,byte ptr [ESI + 0x1]
    //         0054db39     MOV        byte ptr [EDI + 0x1],AL
    //         0054db3c     MOV        AL,byte ptr [ESI + 0x2]
    //         0054db3f     SHR        ECX,0x2
    //         0054db42     MOV        byte ptr [EDI + 0x2],AL
    //         0054db45     ADD        ESI,0x3
    //         0054db48     ADD        EDI,0x3
    //         0054db4b     CMP        ECX,0x8
    //         0054db4e     JC         switchD_0054db1c::switchD
    //         0054db50     MOVSD.REP  ES:EDI,ESI
    //                               switchD_0054db52::switchD
    //         0054db52     JMP        dword ptr [EDX*0x4 + switchD_0054daf5::switchd   = 0054dc18
}

// Offset: 0x0054DB59
undefined FUN_0054db59() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0054db59()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0054db59
    //         0054db59     MOV        EAX,EAX
    //                               switchD_0054db0d::caseD_2                                    XREF[2]:     memcpy:0054db0d(j), 0054db28(*)  
    //         0054db5c     AND        EDX,ECX
    //         0054db5e     MOV        AL,byte ptr [ESI]
    //         0054db60     MOV        byte ptr [EDI],AL
    //         0054db62     MOV        AL,byte ptr [ESI + 0x1]
    //         0054db65     SHR        ECX,0x2
    //         0054db68     MOV        byte ptr [EDI + 0x1],AL
    //         0054db6b     ADD        ESI,0x2
    //         0054db6e     ADD        EDI,0x2
    //         0054db71     CMP        ECX,0x8
    //         0054db74     JC         switchD_0054db1c::switchD
    //         0054db76     MOVSD.REP  ES:EDI,ESI
    //                               switchD_0054db78::switchD
    //         0054db78     JMP        dword ptr [EDX*0x4 + switchD_0054daf5::switchd   = 0054dc18
}

// Offset: 0x0054DB7F
undefined FUN_0054db7f() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0054db7f()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0054db7f
    //         0054db7f     NOP
    //                               switchD_0054db0d::caseD_3                                    XREF[2]:     memcpy:0054db0d(j), 0054db2c(*)  
    //         0054db80     AND        EDX,ECX
    //         0054db82     MOV        AL,byte ptr [ESI]
    //         0054db84     MOV        byte ptr [EDI],AL
    //         0054db86     INC        ESI
    //         0054db87     SHR        ECX,0x2
    //         0054db8a     INC        EDI
    //         0054db8b     CMP        ECX,0x8
    //         0054db8e     JC         switchD_0054db1c::switchD
    //         0054db90     MOVSD.REP  ES:EDI,ESI
    //                               switchD_0054db92::switchD
    //         0054db92     JMP        dword ptr [EDX*0x4 + switchD_0054daf5::switchd   = 0054dc18
}

// Offset: 0x0054DB99
undefined FUN_0054db99() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0054db99()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0054db99
    //         0054db99     MOV        EAX,EAX
    //                               switchD_0054db1c::switchdataD_0054db9c                       XREF[1]:     FUN_0054db1b:0054db1c(*)  
}

// Offset: 0x0054DC06
undefined FUN_0054dc06() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0054dc06()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0054dc06
    //         0054dc06     MOV        EAX,EAX
    //                               switchD_0054daf5::switchdataD_0054dc08                       XREF[5]:     memcpy:0054daf5(*), 
    //                                                                                                         caseD_1:0054db52(*), 
    //                                                                                                         FUN_0054db59:0054db78(*), 
    //                                                                                                         FUN_0054db7f:0054db92(*), 
    //                                                                                                         FUN_0054db7f:0054dbff(*)  
}

// Offset: 0x0054DC18
undefined caseD_0() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined caseD_0()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               switchD_0054dbff::caseD_0                                    XREF[7]:     memcpy:0054daf5(j), 
    //                               switchD_0054db92::caseD_0                                                 memcpy:0054db14(j), 
    //                               switchD_0054db78::caseD_0                                                 caseD_1:0054db52(j), 
    //                               switchD_0054db52::caseD_0                                                 FUN_0054db59:0054db78(j), 
    //                               switchD_0054db14::caseD_0                                                 FUN_0054db7f:0054db92(j), 
    //                               switchD_0054daf5::caseD_0                                                 FUN_0054db7f:0054dbff(j), 
    //                                                                                                         0054dc08(*)  
    //         0054dc18     MOV        EAX,dword ptr [EBP + 0x8]
    //         0054dc1b     POP        ESI
    //         0054dc1c     POP        EDI
    //         0054dc1d     LEAVE
    //         0054dc1e     RET
}

// Offset: 0x0054DC1F
undefined FUN_0054dc1f() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0054dc1f()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0054dc1f
    //         0054dc1f     NOP
    //                               switchD_0054db14::caseD_1                                    XREF[7]:     memcpy:0054daf5(j), 
    //                               switchD_0054dbff::caseD_1                                                 memcpy:0054db14(j), 
    //                               switchD_0054db92::caseD_1                                                 caseD_1:0054db52(j), 
    //                               switchD_0054db78::caseD_1                                                 FUN_0054db59:0054db78(j), 
    //                               switchD_0054db52::caseD_1                                                 FUN_0054db7f:0054db92(j), 
    //                               switchD_0054daf5::caseD_1                                                 FUN_0054db7f:0054dbff(j), 
    //                                                                                                         0054dc0c(*)  
    //         0054dc20     MOV        AL,byte ptr [ESI]
    //         0054dc22     MOV        byte ptr [EDI],AL
    //         0054dc24     MOV        EAX,dword ptr [EBP + 0x8]
    //         0054dc27     POP        ESI
    //         0054dc28     POP        EDI
    //         0054dc29     LEAVE
    //         0054dc2a     RET
}

// Offset: 0x0054DC2B
undefined FUN_0054dc2b() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0054dc2b()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0054dc2b
    //         0054dc2b     NOP
    //                               switchD_0054db14::caseD_2                                    XREF[7]:     memcpy:0054daf5(j), 
    //                               switchD_0054dbff::caseD_2                                                 memcpy:0054db14(j), 
    //                               switchD_0054db92::caseD_2                                                 caseD_1:0054db52(j), 
    //                               switchD_0054db78::caseD_2                                                 FUN_0054db59:0054db78(j), 
    //                               switchD_0054db52::caseD_2                                                 FUN_0054db7f:0054db92(j), 
    //                               switchD_0054daf5::caseD_2                                                 FUN_0054db7f:0054dbff(j), 
    //                                                                                                         0054dc10(*)  
    //         0054dc2c     MOV        AL,byte ptr [ESI]
    //         0054dc2e     MOV        byte ptr [EDI],AL
    //         0054dc30     MOV        AL,byte ptr [ESI + 0x1]
    //         0054dc33     MOV        byte ptr [EDI + 0x1],AL
    //         0054dc36     MOV        EAX,dword ptr [EBP + 0x8]
    //         0054dc39     POP        ESI
    //         0054dc3a     POP        EDI
    //         0054dc3b     LEAVE
    //         0054dc3c     RET
}

// Offset: 0x0054DC3D
undefined FUN_0054dc3d() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0054dc3d()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0054dc3d
    //         0054dc3d     MOV        EAX,EAX
    //                               switchD_0054db14::caseD_3                                    XREF[7]:     memcpy:0054daf5(j), 
    //                               switchD_0054dbff::caseD_3                                                 memcpy:0054db14(j), 
    //                               switchD_0054db92::caseD_3                                                 caseD_1:0054db52(j), 
    //                               switchD_0054db78::caseD_3                                                 FUN_0054db59:0054db78(j), 
    //                               switchD_0054db52::caseD_3                                                 FUN_0054db7f:0054db92(j), 
    //                               switchD_0054daf5::caseD_3                                                 FUN_0054db7f:0054dbff(j), 
    //                                                                                                         0054dc14(*)  
    //         0054dc40     MOV        AL,byte ptr [ESI]
    //         0054dc42     MOV        byte ptr [EDI],AL
    //         0054dc44     MOV        AL,byte ptr [ESI + 0x1]
    //         0054dc47     MOV        byte ptr [EDI + 0x1],AL
    //         0054dc4a     MOV        AL,byte ptr [ESI + 0x2]
    //         0054dc4d     MOV        byte ptr [EDI + 0x2],AL
    //         0054dc50     MOV        EAX,dword ptr [EBP + 0x8]
    //         0054dc53     POP        ESI
    //         0054dc54     POP        EDI
    //         0054dc55     LEAVE
    //         0054dc56     RET
}

// Offset: 0x0054DC57
undefined FUN_0054dc57() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0054dc57()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0054dc57
    //         0054dc57     NOP
    //                               LAB_0054dc58                                                 XREF[1]:     memcpy:0054dada(j)  
    //         0054dc58     LEA        ESI,[ECX + ESI*0x1 + -0x4]
    //         0054dc5c     LEA        EDI,[ECX + EDI*0x1 + -0x4]
    //         0054dc60     TEST       EDI,0x3
    //         0054dc66     JNZ        LAB_0054dc8c
    //         0054dc68     SHR        ECX,0x2
    //         0054dc6b     AND        EDX,0x3
    //         0054dc6e     CMP        ECX,0x8
    //         0054dc71     JC         LAB_0054dc80
    //         0054dc73     STD
    //         0054dc74     MOVSD.REP  ES:EDI,ESI
    //         0054dc76     CLD
    //                               switchD_0054dc77::switchD
    //         0054dc77     JMP        dword ptr [EDX*0x4 + switchD_0054dc77::switchd   = 0054ddb0
}

// Offset: 0x0054DC7E
undefined FUN_0054dc7e() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0054dc7e()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0054dc7e
    //         0054dc7e     MOV        EAX,EAX
    //                               LAB_0054dc80                                                 XREF[4]:     FUN_0054dc57:0054dc71(j), 
    //                                                                                                         caseD_1:0054dcc8(j), 
    //                                                                                                         FUN_0054dcd5:0054dcf2(j), 
    //                                                                                                         FUN_0054dcff:0054dd20(j)  
    //         0054dc80     NEG        ECX
    //                               switchD_0054dc82::switchD
    //         0054dc82     JMP        dword ptr [ECX*0x4 + PTR_caseD_0_0054dd50]       = 0054dd97
}

// Offset: 0x0054DC89
undefined FUN_0054dc89() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0054dc89()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0054dc89
    //         0054dc89     MOV        EAX,EAX
    //                               LAB_0054dc8c                                                 XREF[1]:     FUN_0054dc57:0054dc66(j)  
    //         0054dc8c     MOV        EAX,EDI
    //         0054dc8e     MOV        EDX,0x3
    //         0054dc93     CMP        ECX,0x4
    //         0054dc96     JC         switchD_0054dca4::switchD
    //                               switchD_0054dca4::default
    //         0054dc98     AND        EAX,0x3
    //         0054dc9b     SUB        ECX,EAX
    //                               switchD_0054dc9d::switchD
    //         0054dc9d     JMP        dword ptr [EAX*0x4 + 0x54dca8]=>0054dcb0-0x4     = 0054dcb8
    //                               switchD_0054dca4::switchD                                    XREF[1]:     0054dc96(j)  
    //         0054dca4     JMP        dword ptr [ECX*0x4 + switchD_0054dc77::switchd   = 0054ddb0
}

// Offset: 0x0054DCB8
undefined caseD_1() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined caseD_1()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               switchD_0054dc9d::caseD_1                                    XREF[2]:     FUN_0054dc89:0054dc9d(j), 
    //                                                                                                         0054dcac(*)  
    //         0054dcb8     MOV        AL,byte ptr [ESI + 0x3]
    //         0054dcbb     AND        EDX,ECX
    //         0054dcbd     MOV        byte ptr [EDI + 0x3],AL
    //         0054dcc0     DEC        ESI
    //         0054dcc1     SHR        ECX,0x2
    //         0054dcc4     DEC        EDI
    //         0054dcc5     CMP        ECX,0x8
    //         0054dcc8     JC         LAB_0054dc80
    //         0054dcca     STD
    //         0054dccb     MOVSD.REP  ES:EDI,ESI=>DAT_fffffffb
    //         0054dccd     CLD
    //                               switchD_0054dcce::switchD
    //         0054dcce     JMP        dword ptr [EDX*0x4 + switchD_0054dc77::switchd   = 0054ddb0
}

// Offset: 0x0054DCD5
undefined FUN_0054dcd5() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0054dcd5()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0054dcd5
    //         0054dcd5     MOV        EAX,EAX
    //                               switchD_0054dc9d::caseD_2                                    XREF[2]:     FUN_0054dc89:0054dc9d(j), 
    //                                                                                                         0054dcb0(*)  
    //         0054dcd8     MOV        AL,byte ptr [ESI + 0x3]
    //         0054dcdb     AND        EDX,ECX
    //         0054dcdd     MOV        byte ptr [EDI + 0x3],AL
    //         0054dce0     MOV        AL,byte ptr [ESI + 0x2]
    //         0054dce3     SHR        ECX,0x2
    //         0054dce6     MOV        byte ptr [EDI + 0x2],AL
    //         0054dce9     SUB        ESI,0x2
    //         0054dcec     SUB        EDI,0x2
    //         0054dcef     CMP        ECX,0x8
    //         0054dcf2     JC         LAB_0054dc80
    //         0054dcf4     STD
    //         0054dcf5     MOVSD.REP  ES:EDI,ESI=>DAT_fffffffa
    //         0054dcf7     CLD
    //                               switchD_0054dcf8::switchD
    //         0054dcf8     JMP        dword ptr [EDX*0x4 + switchD_0054dc77::switchd   = 0054ddb0
}

// Offset: 0x0054DCFF
undefined FUN_0054dcff() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0054dcff()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0054dcff
    //         0054dcff     NOP
    //                               switchD_0054dc9d::caseD_3                                    XREF[2]:     FUN_0054dc89:0054dc9d(j), 
    //                                                                                                         0054dcb4(*)  
    //         0054dd00     MOV        AL,byte ptr [ESI + 0x3]
    //         0054dd03     AND        EDX,ECX
    //         0054dd05     MOV        byte ptr [EDI + 0x3],AL
    //         0054dd08     MOV        AL,byte ptr [ESI + 0x2]
    //         0054dd0b     MOV        byte ptr [EDI + 0x2],AL
    //         0054dd0e     MOV        AL,byte ptr [ESI + 0x1]
    //         0054dd11     SHR        ECX,0x2
    //         0054dd14     MOV        byte ptr [EDI + 0x1],AL
    //         0054dd17     SUB        ESI,0x3
    //         0054dd1a     SUB        EDI,0x3
    //         0054dd1d     CMP        ECX,0x8
    //         0054dd20     JC         LAB_0054dc80
    //         0054dd26     STD
    //         0054dd27     MOVSD.REP  ES:EDI,ESI=>DAT_fffffff9
    //         0054dd29     CLD
    //                               switchD_0054dd2a::switchD
    //         0054dd2a     JMP        dword ptr [EDX*0x4 + switchD_0054dc77::switchd   = 0054ddb0
}

// Offset: 0x0054DD31
undefined FUN_0054dd31() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0054dd31()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0054dd31
    //         0054dd31     MOV        EAX,EAX
    //                               switchD_0054dc82::switchdataD_0054dd34
}

// Offset: 0x0054DD9E
undefined FUN_0054dd9e() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0054dd9e()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0054dd9e
    //         0054dd9e     MOV        EAX,EAX
    //                               switchD_0054dc77::switchdataD_0054dda0                       XREF[6]:     FUN_0054dc57:0054dc77(*), 
    //                                                                                                         FUN_0054dc89:0054dca4(*), 
    //                                                                                                         caseD_1:0054dcce(*), 
    //                                                                                                         FUN_0054dcd5:0054dcf8(*), 
    //                                                                                                         FUN_0054dcff:0054dd2a(*), 
    //                                                                                                         FUN_0054dcff:0054dd97(*)  
}

// Offset: 0x0054DDB0
undefined caseD_0() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined caseD_0()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               switchD_0054dd97::caseD_0                                    XREF[7]:     FUN_0054dc57:0054dc77(j), 
    //                               switchD_0054dd2a::caseD_0                                                 FUN_0054dc89:0054dca4(j), 
    //                               switchD_0054dcf8::caseD_0                                                 caseD_1:0054dcce(j), 
    //                               switchD_0054dcce::caseD_0                                                 FUN_0054dcd5:0054dcf8(j), 
    //                               switchD_0054dca4::caseD_0                                                 FUN_0054dcff:0054dd2a(j), 
    //                               switchD_0054dc77::caseD_0                                                 FUN_0054dcff:0054dd97(j), 
    //                                                                                                         0054dda0(*)  
    //         0054ddb0     MOV        EAX,dword ptr [EBP + 0x8]
    //         0054ddb3     POP        ESI
    //         0054ddb4     POP        EDI
    //         0054ddb5     LEAVE
    //         0054ddb6     RET
}

// Offset: 0x0054DDB7
undefined FUN_0054ddb7() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0054ddb7()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0054ddb7
    //         0054ddb7     NOP
    //                               switchD_0054dca4::caseD_1                                    XREF[7]:     FUN_0054dc57:0054dc77(j), 
    //                               switchD_0054dd97::caseD_1                                                 FUN_0054dc89:0054dca4(j), 
    //                               switchD_0054dd2a::caseD_1                                                 caseD_1:0054dcce(j), 
    //                               switchD_0054dcf8::caseD_1                                                 FUN_0054dcd5:0054dcf8(j), 
    //                               switchD_0054dcce::caseD_1                                                 FUN_0054dcff:0054dd2a(j), 
    //                               switchD_0054dc77::caseD_1                                                 FUN_0054dcff:0054dd97(j), 
    //                                                                                                         0054dda4(*)  
    //         0054ddb8     MOV        AL,byte ptr [ESI + 0x3]
    //         0054ddbb     MOV        byte ptr [EDI + 0x3],AL
    //         0054ddbe     MOV        EAX,dword ptr [EBP + 0x8]
    //         0054ddc1     POP        ESI
    //         0054ddc2     POP        EDI
    //         0054ddc3     LEAVE
    //         0054ddc4     RET
}

// Offset: 0x0054DDC5
undefined FUN_0054ddc5() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0054ddc5()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0054ddc5
    //         0054ddc5     MOV        EAX,EAX
    //                               switchD_0054dca4::caseD_2                                    XREF[7]:     FUN_0054dc57:0054dc77(j), 
    //                               switchD_0054dd97::caseD_2                                                 FUN_0054dc89:0054dca4(j), 
    //                               switchD_0054dd2a::caseD_2                                                 caseD_1:0054dcce(j), 
    //                               switchD_0054dcf8::caseD_2                                                 FUN_0054dcd5:0054dcf8(j), 
    //                               switchD_0054dcce::caseD_2                                                 FUN_0054dcff:0054dd2a(j), 
    //                               switchD_0054dc77::caseD_2                                                 FUN_0054dcff:0054dd97(j), 
    //                                                                                                         0054dda8(*)  
    //         0054ddc8     MOV        AL,byte ptr [ESI + 0x3]
    //         0054ddcb     MOV        byte ptr [EDI + 0x3],AL
    //         0054ddce     MOV        AL,byte ptr [ESI + 0x2]=>DAT_fffffffb
    //         0054ddd1     MOV        byte ptr [EDI + 0x2],AL=>DAT_fffffffb
    //         0054ddd4     MOV        EAX,dword ptr [EBP + 0x8]
    //         0054ddd7     POP        ESI
    //         0054ddd8     POP        EDI
    //         0054ddd9     LEAVE
    //         0054ddda     RET
}

// Offset: 0x0054DDDB
undefined FUN_0054dddb() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0054dddb()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0054dddb
    //         0054dddb     NOP
    //                               switchD_0054dca4::caseD_3                                    XREF[7]:     FUN_0054dc57:0054dc77(j), 
    //                               switchD_0054dd97::caseD_3                                                 FUN_0054dc89:0054dca4(j), 
    //                               switchD_0054dd2a::caseD_3                                                 caseD_1:0054dcce(j), 
    //                               switchD_0054dcf8::caseD_3                                                 FUN_0054dcd5:0054dcf8(j), 
    //                               switchD_0054dcce::caseD_3                                                 FUN_0054dcff:0054dd2a(j), 
    //                               switchD_0054dc77::caseD_3                                                 FUN_0054dcff:0054dd97(j), 
    //                                                                                                         0054ddac(*)  
    //         0054dddc     MOV        AL,byte ptr [ESI + 0x3]
    //         0054dddf     MOV        byte ptr [EDI + 0x3],AL
    //         0054dde2     MOV        AL,byte ptr [ESI + 0x2]=>DAT_fffffffb
    //         0054dde5     MOV        byte ptr [EDI + 0x2],AL=>DAT_fffffffb
    //         0054dde8     MOV        AL,byte ptr [ESI + 0x1]=>DAT_fffffffa
    //         0054ddeb     MOV        byte ptr [EDI + 0x1],AL=>DAT_fffffffa
    //         0054ddee     MOV        EAX,dword ptr [EBP + 0x8]
    //         0054ddf1     POP        ESI
    //         0054ddf2     POP        EDI
    //         0054ddf3     LEAVE
    //         0054ddf4     RET
}

// Offset: 0x0054DE00
undefined strtok() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * strtok                                                                                                *
    //                              *********************************************************************************************************
    //                              undefined __cdecl strtok()
    //              undefined         <UNASSIGNED>   <RETURN>
    //              undefined         Stack[-0x20]:1 local_20                  XREF[1]:     0054de12(*)  
    //                               _strtok                                                      XREF[6]:     ReadPalette:00439873(c), 
    //                               strtok                                                                    ReadPalette:00439889(c), 
    //                                                                                                         ReadPalette:0043989f(c), 
    //                                                                                                         ReadPalette:004398f1(c), 
    //                                                                                                         ReadPalette:00439910(c), 
    //                                                                                                         ReadPalette:0043992e(c)  
    //         0054de00     SUB        ESP,0x20
    //         0054de03     MOV        ECX,0x8
    //         0054de08     XOR        EAX,EAX
    //         0054de0a     PUSH       EBX
    //         0054de0b     PUSH       EBP
    //         0054de0c     MOV        EBP,dword ptr [ESP + Stack[0x8]]
    //         0054de10     PUSH       ESI
    //         0054de11     PUSH       EDI
    //         0054de12     LEA        EDI=>local_20,[ESP + 0x10]
    //         0054de16     STOSD.REP  ES:EDI
    //                               LAB_0054de18                                                 XREF[1]:     0054de3e(j)  
    //         0054de18     MOV        AL,byte ptr [EBP]
    //         0054de1b     MOV        ECX,EAX
    //         0054de1d     AND        ECX,0xff
    //         0054de23     MOV        EDX,ECX
    //         0054de25     AND        ECX,0x7
    //         0054de28     SHR        EDX,0x3
    //         0054de2b     MOV        BL,byte ptr [ESP + EDX*0x1 + 0x10]
    //         0054de2f     LEA        ESI,[ESP + EDX*0x1 + 0x10]
    //         0054de33     MOV        DL,0x1
    //         0054de35     SHL        DL,CL
    //         0054de37     OR         BL,DL
    //         0054de39     INC        EBP
    //         0054de3a     TEST       AL,AL
    //         0054de3c     MOV        byte ptr [ESI],BL
    //         0054de3e     JNZ        LAB_0054de18
    //         0054de40     MOV        ESI,dword ptr [ESP + Stack[0x4]]
    //         0054de44     TEST       ESI,ESI
    //         0054de46     JNZ        LAB_0054de4e
    //         0054de48     MOV        ESI,dword ptr [DAT_00887ff0]
    //                               LAB_0054de4e                                                 XREF[1]:     0054de46(j)  
    //         0054de4e     MOV        DL,byte ptr [ESI]
    //         0054de50     MOV        EAX,0x1
    //         0054de55     MOV        EDI,EDX
    //         0054de57     AND        EDI,0xff
    //         0054de5d     MOV        ECX,EDI
    //         0054de5f     AND        ECX,0x7
    //         0054de62     SHL        EAX,CL
    //         0054de64     SHR        EDI,0x3
    //         0054de67     MOV        CL,byte ptr [ESP + EDI*0x1 + 0x10]
    //         0054de6b     TEST       CL,AL
    //         0054de6d     JZ         LAB_0054de95
    //                               LAB_0054de6f                                                 XREF[1]:     0054de93(j)  
    //         0054de6f     TEST       DL,DL
    //         0054de71     JZ         LAB_0054de95
    //         0054de73     MOV        DL,byte ptr [ESI + 0x1]
    //         0054de76     INC        ESI
    //         0054de77     MOV        EAX,EDX
    //         0054de79     MOV        EBX,0x1
    //         0054de7e     AND        EAX,0xff
    //         0054de83     MOV        ECX,EAX
    //         0054de85     AND        ECX,0x7
    //         0054de88     SHL        EBX,CL
    //         0054de8a     SHR        EAX,0x3
    //         0054de8d     MOV        AL,byte ptr [ESP + EAX*0x1 + 0x10]
    //         0054de91     TEST       AL,BL
    //         0054de93     JNZ        LAB_0054de6f
    //                               LAB_0054de95                                                 XREF[2]:     0054de6d(j), 0054de71(j)  
    //         0054de95     MOV        AL,byte ptr [ESI]
    //         0054de97     MOV        EDI,ESI
    //         0054de99     TEST       AL,AL
    //         0054de9b     JZ         LAB_0054dec7
    //                               LAB_0054de9d                                                 XREF[1]:     0054debf(j)  
    //         0054de9d     AND        EAX,0xff
    //         0054dea2     MOV        EDX,0x1
    //         0054dea7     MOV        ECX,EAX
    //         0054dea9     AND        ECX,0x7
    //         0054deac     SHL        EDX,CL
    //         0054deae     SHR        EAX,0x3
    //         0054deb1     MOV        AL,byte ptr [ESP + EAX*0x1 + 0x10]
    //         0054deb5     TEST       AL,DL
    //         0054deb7     JNZ        LAB_0054dec3
    //         0054deb9     MOV        AL,byte ptr [ESI + 0x1]
    //         0054debc     INC        ESI
    //         0054debd     TEST       AL,AL
    //         0054debf     JNZ        LAB_0054de9d
    //         0054dec1     JMP        LAB_0054dec7
    //                               LAB_0054dec3                                                 XREF[1]:     0054deb7(j)  
    //         0054dec3     MOV        byte ptr [ESI],0x0
    //         0054dec6     INC        ESI
    //                               LAB_0054dec7                                                 XREF[2]:     0054de9b(j), 0054dec1(j)  
    //         0054dec7     MOV        EAX,EDI
    //         0054dec9     MOV        dword ptr [DAT_00887ff0],ESI
    //         0054decf     SUB        EAX,ESI
    //         0054ded1     NEG        EAX
    //         0054ded3     SBB        EAX,EAX
    //         0054ded5     AND        EAX,EDI
    //         0054ded7     POP        EDI
    //         0054ded8     POP        ESI
    //         0054ded9     POP        EBP
    //         0054deda     POP        EBX
    //         0054dedb     ADD        ESP,0x20
    //         0054dede     RET
}

// Offset: 0x0054DEE0
undefined alloca_probe() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined __alloca_probe()
    //                                Call-Fixup: alloca_probe
    //              undefined         <UNASSIGNED>   <RETURN>
    //              undefined4        Stack[0x0]:4   local_res0                XREF[1]:     0054df0a(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     0054df08(*)  
    //              undefined4        Stack[-0xffc   local_ffc                 XREF[1]:     0054def7(*)  
    //                               __chkstk                                                     XREF[12]:    TribeAboutDialog:0043ad8a(c), 
    //                               __alloca_probe                                                            _WinMain@16:004549fa(c), 
    //                                                                                                         paste:00477cb5(c), 
    //                                                                                                         setup:0047c1e5(c), 
    //                                                                                                         set_text:0047ca75(c), 
    //                                                                                                         RGE_RMM_Controller:004821ba(c), 
    //                                                                                                         add_object_module:004828ca(c), 
    //                                                                                                         action:0049f9ea(c), 
    //                                                                                                         fillList:0049feea(c), 
    //                                                                                                         new_game:0052ef4a(c), 
    //                                                                                                         __chsize:00554c75(c), 
    //                                                                                                         operator<<:0055afd5(c)  
    //         0054dee0     PUSH       ECX
    //         0054dee1     CMP        EAX,0x1000
    //         0054dee6     LEA        ECX=>Stack[0x4],[ESP + 0x8]
    //         0054deea     JC         LAB_0054df00
    //                               LAB_0054deec                                                 XREF[1]:     0054defe(j)  
    //         0054deec     SUB        ECX,0x1000
    //         0054def2     SUB        EAX,0x1000
    //         0054def7     TEST       dword ptr [ECX]=>local_ffc,EAX
    //         0054def9     CMP        EAX,0x1000
    //         0054defe     JNC        LAB_0054deec
    //                               LAB_0054df00                                                 XREF[1]:     0054deea(j)  
    //         0054df00     SUB        ECX,EAX
    //         0054df02     MOV        EAX,ESP
    //         0054df04     TEST       dword ptr [ECX],EAX
    //         0054df06     MOV        ESP,ECX
    //         0054df08     MOV        ECX,dword ptr [EAX]=>local_4
    //         0054df0a     MOV        EAX,dword ptr [EAX + local_res0]
    //         0054df0d     PUSH       EAX
    //         0054df0e     RET
}

// Offset: 0x0054DF40
undefined isupper() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * isupper                                                                                               *
    //                              *********************************************************************************************************
    //                              undefined __cdecl isupper()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               _isupper                                                     XREF[1]:     BUILDRES_get_files_resource_type:0
    //                               isupper
    //         0054df40     CMP        dword ptr [___mb_cur_max],0x1                    = 00000001h
    //         0054df47     JLE        LAB_0054df59
    //         0054df49     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         0054df4d     PUSH       0x1
    //         0054df4f     PUSH       EAX
    //         0054df50     CALL       __isctype                                        undefined __isctype()
    //         0054df55     ADD        ESP,0x8
    //         0054df58     RET
    //                               LAB_0054df59                                                 XREF[1]:     0054df47(j)  
    //         0054df59     MOV        ECX,dword ptr [ESP + Stack[0x4]]
    //         0054df5d     MOV        EDX,dword ptr [__pctype]                         = 005920da
    //         0054df63     MOV        AL,byte ptr [EDX + ECX*0x2]=>DAT_005920da        = 20h     
    //         0054df66     AND        EAX,0x1
    //         0054df69     RET
}

// Offset: 0x0054DF6A
undefined FUN_0054df6a() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0054df6a()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0054df6a
    //         0054df6a     NOP
    //         0054df6b     NOP
    //         0054df6c     NOP
    //         0054df6d     NOP
    //         0054df6e     NOP
    //         0054df6f     NOP
    //                               _islower
    //         0054df70     CMP        dword ptr [___mb_cur_max],0x1                    = 00000001h
    //         0054df77     JLE        LAB_0054df89
    //         0054df79     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         0054df7d     PUSH       0x2
    //         0054df7f     PUSH       EAX
    //         0054df80     CALL       __isctype                                        undefined __isctype()
    //         0054df85     ADD        ESP,0x8
    //         0054df88     RET
    //                               LAB_0054df89                                                 XREF[1]:     0054df77(j)  
    //         0054df89     MOV        ECX,dword ptr [ESP + Stack[0x4]]
    //         0054df8d     MOV        EDX,dword ptr [__pctype]                         = 005920da
    //         0054df93     MOV        AL,byte ptr [EDX + ECX*0x2]=>DAT_005920da        = 20h     
    //         0054df96     AND        EAX,0x2
    //         0054df99     RET
}

// Offset: 0x0054DF9A
undefined FUN_0054df9a() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0054df9a()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0054df9a
    //         0054df9a     NOP
    //         0054df9b     NOP
    //         0054df9c     NOP
    //         0054df9d     NOP
    //         0054df9e     NOP
    //         0054df9f     NOP
    //                               _isdigit
    //         0054dfa0     CMP        dword ptr [___mb_cur_max],0x1                    = 00000001h
    //         0054dfa7     JLE        LAB_0054dfb9
    //         0054dfa9     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         0054dfad     PUSH       0x4
    //         0054dfaf     PUSH       EAX
    //         0054dfb0     CALL       __isctype                                        undefined __isctype()
    //         0054dfb5     ADD        ESP,0x8
    //         0054dfb8     RET
    //                               LAB_0054dfb9                                                 XREF[1]:     0054dfa7(j)  
    //         0054dfb9     MOV        ECX,dword ptr [ESP + Stack[0x4]]
    //         0054dfbd     MOV        EDX,dword ptr [__pctype]                         = 005920da
    //         0054dfc3     MOV        AL,byte ptr [EDX + ECX*0x2]=>DAT_005920da        = 20h     
    //         0054dfc6     AND        EAX,0x4
    //         0054dfc9     RET
}

// Offset: 0x0054DFCA
undefined FUN_0054dfca() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0054dfca()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0054dfca
    //         0054dfca     NOP
    //         0054dfcb     NOP
    //         0054dfcc     NOP
    //         0054dfcd     NOP
    //         0054dfce     NOP
    //         0054dfcf     NOP
    //                               _isxdigit
    //         0054dfd0     CMP        dword ptr [___mb_cur_max],0x1                    = 00000001h
    //         0054dfd7     JLE        LAB_0054dfec
    //         0054dfd9     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //                              language.dll match for 0x80: "Arial"
    //         0054dfdd     PUSH       0x80
    //         0054dfe2     PUSH       EAX
    //         0054dfe3     CALL       __isctype                                        undefined __isctype()
    //         0054dfe8     ADD        ESP,0x8
    //         0054dfeb     RET
    //                               LAB_0054dfec                                                 XREF[1]:     0054dfd7(j)  
    //         0054dfec     MOV        ECX,dword ptr [ESP + Stack[0x4]]
    //         0054dff0     MOV        EDX,dword ptr [__pctype]                         = 005920da
    //         0054dff6     MOV        AL,byte ptr [EDX + ECX*0x2]=>DAT_005920da        = 20h     
    //         0054dff9     AND        EAX,0x80
    //         0054dffe     RET
}

