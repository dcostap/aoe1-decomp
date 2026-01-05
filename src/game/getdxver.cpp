#include "getdxver.h"

void GetDXVersion(ulong* param_1, ulong* param_2) {
    /* TODO: Stub */
//                              void __cdecl GetDXVersion(ulong * param_1, ulong * param_2)
//              void              <VOID>         <RETURN>
//              ulong *           Stack[0x4]:4   param_1
//              ulong *           Stack[0x8]:4   param_2
//              _OSVERSIONINFOA   Stack[-0x98]   osVer                     XREF[0,2]:   0044dac9(*), 0044dae4(W)
//              _DDSURFACEDESC    Stack[-0x104   desc                      XREF[1]:     0044dae0(W)
//              IDirectDrawSur    Stack[-0x108   pSurf3                    XREF[1]:     0044dad8(W)
//              IDirectDraw2 *    Stack[-0x10c   pDDraw2                   XREF[1]:     0044dadc(W)
//              IDirectDrawSur    Stack[-0x110   pSurf
//              IDirectPlay3 *    Stack[-0x114   dp3                       XREF[1]:     0044dad4(W)
//              IDirectDraw *     Stack[-0x118   pDDraw
//                               ?GetDXVersion@@YAXPAK0@Z                                     XREF[1]:     setup:0041bdb8(c)
//                               GetDXVersion
//                              getdxver.cpp:54 (9)
//         0044dac0     SUB        ESP,0x114
//         0044dac6     PUSH       EBX
//         0044dac7     PUSH       EBP
//         0044dac8     PUSH       ESI
//                              getdxver.cpp:70 (48)
//         0044dac9     LEA        EAX=>osVer.dwMajorVersion,[ESP + 0x8c]
//         0044dad0     PUSH       EDI
//         0044dad1     XOR        EBX,EBX
//         0044dad3     PUSH       EAX
//         0044dad4     MOV        dword ptr [ESP + dp3],EBX
//         0044dad8     MOV        dword ptr [ESP + pSurf3],EBX
//         0044dadc     MOV        dword ptr [ESP + pDDraw2],EBX
//         0044dae0     MOV        dword ptr [ESP + desc.dwSize],EBX
//         0044dae4     MOV        dword ptr [ESP + osVer.dwMajorVersion],0x94
//         0044daef     CALL       dword ptr [->KERNEL32.DLL::GetVersionExA]        = 0048abc2
//         0044daf5     TEST       EAX,EAX
//         0044daf7     JNZ        LAB_0044db16
//                              getdxver.cpp:72 (7)
//         0044daf9     MOV        ECX,dword ptr [ESP + 0x128]
//                              getdxver.cpp:73 (11)
//         0044db00     MOV        EDX,dword ptr [ESP + 0x12c]
//         0044db07     MOV        dword ptr [ECX],EBX
//         0044db09     MOV        dword ptr [EDX],EBX
//                              getdxver.cpp:338 (11)
//         0044db0b     POP        EDI
//         0044db0c     POP        ESI
//         0044db0d     POP        EBP
//         0044db0e     POP        EBX
//         0044db0f     ADD        ESP,0x114
//         0044db15     RET
//                               LAB_0044db16                                                 XREF[1]:     0044daf7(j)
//                              getdxver.cpp:77 (14)
//         0044db16     CMP        dword ptr [ESP + 0xa0],0x2
//         0044db1e     JNZ        LAB_0044dc42
//                              getdxver.cpp:79 (7)
//         0044db24     MOV        EAX,dword ptr [ESP + 0x12c]
//                              getdxver.cpp:84 (18)
//         0044db2b     MOV        ECX,dword ptr [ESP + 0x94]
//         0044db32     CMP        ECX,0x4
//         0044db35     MOV        dword ptr [EAX],0x2
//         0044db3b     JNC        LAB_0044db4a
//                              getdxver.cpp:86 (2)
//         0044db3d     MOV        dword ptr [EAX],EBX
//                              getdxver.cpp:338 (11)
//         0044db3f     POP        EDI
//         0044db40     POP        ESI
//         0044db41     POP        EBP
//         0044db42     POP        EBX
//         0044db43     ADD        ESP,0x114
//         0044db49     RET
//                               LAB_0044db4a                                                 XREF[1]:     0044db3b(j)
//                              getdxver.cpp:90 (6)
//         0044db4a     JNZ        LAB_0044dc2a
//                              getdxver.cpp:95 (7)
//         0044db50     MOV        EBX,dword ptr [ESP + 0x128]
//                              getdxver.cpp:100 (19)
//         0044db57     PUSH       s_DINPUT.DLL                                     = "DINPUT.DLL"
//         0044db5c     MOV        dword ptr [EBX],0x200
//         0044db62     CALL       dword ptr [->KERNEL32.DLL::LoadLibraryA]         = 0048aa08
//         0044db68     MOV        ESI,EAX
//                              getdxver.cpp:101 (4)
//         0044db6a     TEST       ESI,ESI
//         0044db6c     JNZ        LAB_0044db84
//                              getdxver.cpp:106 (11)
//         0044db6e     PUSH       s_Couldn't_LoadLibrary_DInput__                  = "Couldn't LoadLibrary DInput\r\n"
//         0044db73     CALL       dword ptr [->KERNEL32.DLL::OutputDebugStringA]   = 0048aa96
//                              getdxver.cpp:338 (11)
//         0044db79     POP        EDI
//         0044db7a     POP        ESI
//         0044db7b     POP        EBP
//         0044db7c     POP        EBX
//         0044db7d     ADD        ESP,0x114
//         0044db83     RET
//                               LAB_0044db84                                                 XREF[1]:     0044db6c(j)
//                              getdxver.cpp:111 (12)
//         0044db84     PUSH       s_DirectInputCreateA                             = "DirectInputCreateA"
//         0044db89     PUSH       ESI=>DAT_fffffff8
//         0044db8a     CALL       dword ptr [->KERNEL32.DLL::GetProcAddress]       = 0048abb0
//                              getdxver.cpp:112 (9)
//         0044db90     PUSH       ESI
//         0044db91     MOV        EDI,EAX
//         0044db93     CALL       dword ptr [->KERNEL32.DLL::FreeLibrary]          = 0048aa18
//                              getdxver.cpp:114 (4)
//         0044db99     TEST       EDI,EDI
//         0044db9b     JNZ        LAB_0044dbb3
//                              getdxver.cpp:119 (11)
//         0044db9d     PUSH       s_Couldn't_GetProcAddress_DInputCr               = "Couldn't GetProcAddress DInputCreate\r\n"
//         0044dba2     CALL       dword ptr [->KERNEL32.DLL::OutputDebugStringA]   = 0048aa96
//                              getdxver.cpp:338 (11)
//         0044dba8     POP        EDI
//         0044dba9     POP        ESI
//         0044dbaa     POP        EBP
//         0044dbab     POP        EBX
//         0044dbac     ADD        ESP,0x114
//         0044dbb2     RET
//                               LAB_0044dbb3                                                 XREF[1]:     0044db9b(j)
//                              getdxver.cpp:133 (16)
//         0044dbb3     PUSH       0x0
//         0044dbb5     MOV        dword ptr [EBX],0x300
//         0044dbbb     CALL       dword ptr [->OLE32.DLL::CoInitialize]            = 0048b67a
//         0044dbc1     MOV        ESI,EAX
//                              getdxver.cpp:135 (25)
//         0044dbc3     LEA        EAX,[ESP + 0x14]
//         0044dbc7     PUSH       EAX
//         0044dbc8     PUSH       _IID_IDirectPlay3                                = 40h    @
//         0044dbcd     PUSH       offset DAT_fffffff4
//         0044dbcf     PUSH       0x0=>DAT_fffffff0
//         0044dbd1     PUSH       _CLSID_DirectPlay                                = 20h
//         0044dbd6     CALL       dword ptr [->OLE32.DLL::CoCreateInstance]        = 0048b666
//                              getdxver.cpp:136 (4)
//         0044dbdc     TEST       EAX,EAX
//         0044dbde     JGE        LAB_0044dbf9
//                              getdxver.cpp:139 (8)
//         0044dbe0     TEST       ESI,ESI
//         0044dbe2     JZ         LAB_0044ded2
//                              getdxver.cpp:140 (6)
//         0044dbe8     CALL       dword ptr [->OLE32.DLL::CoUninitialize]          = 0048b654
//                              getdxver.cpp:338 (11)
//         0044dbee     POP        EDI
//         0044dbef     POP        ESI
//         0044dbf0     POP        EBP
//         0044dbf1     POP        EBX
//         0044dbf2     ADD        ESP,0x114
//         0044dbf8     RET
//                               LAB_0044dbf9                                                 XREF[1]:     0044dbde(j)
//                              getdxver.cpp:143 (10)
//         0044dbf9     MOV        EAX,dword ptr [ESP + 0x14]
//         0044dbfd     PUSH       EAX
//         0044dbfe     MOV        ECX,dword ptr [EAX]
//         0044dc00     CALL       dword ptr [ECX + 0x8]
//                              getdxver.cpp:144 (4)
//         0044dc03     TEST       ESI,ESI
//         0044dc05     JZ         LAB_0044dc0d
//                              getdxver.cpp:145 (6)
//         0044dc07     CALL       dword ptr [->OLE32.DLL::CoUninitialize]          = 0048b654
//                               LAB_0044dc0d                                                 XREF[1]:     0044dc05(j)
//                              getdxver.cpp:148 (18)
//         0044dc0d     CALL       IsDPlay501a                                      int IsDPlay501a(void)
//         0044dc12     NEG        EAX
//         0044dc14     SBB        EAX,EAX
//         0044dc16     NEG        EAX
//         0044dc18     ADD        EAX,0x500
//         0044dc1d     MOV        dword ptr [EBX],EAX
//                              getdxver.cpp:338 (11)
//         0044dc1f     POP        EDI
//         0044dc20     POP        ESI
//         0044dc21     POP        EBP
//         0044dc22     POP        EBX
//         0044dc23     ADD        ESP,0x114
//         0044dc29     RET
//                               LAB_0044dc2a                                                 XREF[1]:     0044db4a(j)
//                              getdxver.cpp:158 (13)
//         0044dc2a     MOV        EDX,dword ptr [ESP + 0x128]
//         0044dc31     MOV        dword ptr [EDX],0x501
//                              getdxver.cpp:338 (11)
//         0044dc37     POP        EDI
//         0044dc38     POP        ESI
//         0044dc39     POP        EBP
//         0044dc3a     POP        EBX
//         0044dc3b     ADD        ESP,0x114
//         0044dc41     RET
//                               LAB_0044dc42                                                 XREF[1]:     0044db1e(j)
//                              getdxver.cpp:170 (32)
//         0044dc42     MOV        EAX,dword ptr [ESP + 0x9c]
//         0044dc49     MOV        EDI,dword ptr [ESP + 0x12c]
//         0044dc50     AND        EAX,0xffff
//         0044dc55     CMP        EAX,0x549
//         0044dc5a     MOV        dword ptr [EDI],0x1
//         0044dc60     JBE        LAB_0044dc7a
//                              getdxver.cpp:172 (13)
//         0044dc62     MOV        ECX,dword ptr [ESP + 0x128]
//         0044dc69     MOV        dword ptr [ECX],0x501
//                              getdxver.cpp:338 (11)
//         0044dc6f     POP        EDI
//         0044dc70     POP        ESI
//         0044dc71     POP        EBP
//         0044dc72     POP        EBX
//         0044dc73     ADD        ESP,0x114
//         0044dc79     RET
//                               LAB_0044dc7a                                                 XREF[1]:     0044dc60(j)
//                              getdxver.cpp:180 (15)
//         0044dc7a     MOV        EBP,dword ptr [->KERNEL32.DLL::LoadLibraryA]     = 0048aa08
//         0044dc80     PUSH       s_DDRAW.DLL                                      = "DDRAW.DLL"
//         0044dc85     CALL       EBP=>KERNEL32.DLL::LoadLibraryA
//         0044dc87     MOV        ESI,EAX
//                              getdxver.cpp:181 (4)
//         0044dc89     CMP        ESI,EBX
//         0044dc8b     JNZ        LAB_0044dcaa
//                              getdxver.cpp:183 (7)
//         0044dc8d     MOV        EDX,dword ptr [ESP + 0x128]
//                              getdxver.cpp:185 (11)
//         0044dc94     PUSH       EBX
//         0044dc95     MOV        dword ptr [EDX],EBX
//         0044dc97     MOV        dword ptr [EDI],EBX
//         0044dc99     CALL       dword ptr [->KERNEL32.DLL::FreeLibrary]          = 0048aa18
//                              getdxver.cpp:338 (11)
//         0044dc9f     POP        EDI
//         0044dca0     POP        ESI
//         0044dca1     POP        EBP
//         0044dca2     POP        EBX
//         0044dca3     ADD        ESP,0x114
//         0044dca9     RET
//                               LAB_0044dcaa                                                 XREF[1]:     0044dc8b(j)
//                              getdxver.cpp:193 (12)
//         0044dcaa     PUSH       s_DirectDrawCreate                               = "DirectDrawCreate"
//         0044dcaf     PUSH       ESI=>DAT_fffffff8
//         0044dcb0     CALL       dword ptr [->KERNEL32.DLL::GetProcAddress]       = 0048abb0
//                              getdxver.cpp:194 (4)
//         0044dcb6     CMP        EAX,EBX
//         0044dcb8     JNZ        LAB_0044dce2
//                              getdxver.cpp:196 (7)
//         0044dcba     MOV        EAX,dword ptr [ESP + 0x128]
//                              getdxver.cpp:198 (11)
//         0044dcc1     PUSH       ESI
//         0044dcc2     MOV        dword ptr [EAX],EBX
//         0044dcc4     MOV        dword ptr [EDI],EBX
//         0044dcc6     CALL       dword ptr [->KERNEL32.DLL::FreeLibrary]          = 0048aa18
//                              getdxver.cpp:199 (11)
//         0044dccc     PUSH       s_Couldn't_LoadLibrary_DDraw__                   = "Couldn't LoadLibrary DDraw\r\n"
//         0044dcd1     CALL       dword ptr [->KERNEL32.DLL::OutputDebugStringA]   = 0048aa96
//                              getdxver.cpp:338 (11)
//         0044dcd7     POP        EDI
//         0044dcd8     POP        ESI
//         0044dcd9     POP        EBP
//         0044dcda     POP        EBX
//         0044dcdb     ADD        ESP,0x114
//         0044dce1     RET
//                               LAB_0044dce2                                                 XREF[1]:     0044dcb8(j)
//                              getdxver.cpp:203 (9)
//         0044dce2     LEA        ECX,[ESP + 0x10]
//         0044dce6     PUSH       EBX
//         0044dce7     PUSH       ECX=>DAT_fffffff8
//         0044dce8     PUSH       EBX=>DAT_fffffff4
//         0044dce9     CALL       EAX
//                              getdxver.cpp:204 (4)
//         0044dceb     CMP        EAX,EBX
//         0044dced     JGE        LAB_0044dd17
//                              getdxver.cpp:206 (7)
//         0044dcef     MOV        EDX,dword ptr [ESP + 0x128]
//                              getdxver.cpp:208 (11)
//         0044dcf6     PUSH       ESI
//         0044dcf7     MOV        dword ptr [EDX],EBX
//         0044dcf9     MOV        dword ptr [EDI],EBX
//         0044dcfb     CALL       dword ptr [->KERNEL32.DLL::FreeLibrary]          = 0048aa18
//                              getdxver.cpp:209 (11)
//         0044dd01     PUSH       s_Couldn't_create_DDraw__                        = "Couldn't create DDraw\r\n"
//         0044dd06     CALL       dword ptr [->KERNEL32.DLL::OutputDebugStringA]   = 0048aa96
//                              getdxver.cpp:338 (11)
//         0044dd0c     POP        EDI
//         0044dd0d     POP        ESI
//         0044dd0e     POP        EBP
//         0044dd0f     POP        EBX
//         0044dd10     ADD        ESP,0x114
//         0044dd16     RET
//                               LAB_0044dd17                                                 XREF[1]:     0044dced(j)
//                              getdxver.cpp:221 (32)
//         0044dd17     MOV        EAX,dword ptr [ESP + 0x10]
//         0044dd1b     MOV        EBX,dword ptr [ESP + 0x128]
//         0044dd22     LEA        EDX,[ESP + 0x1c]
//         0044dd26     MOV        ECX,dword ptr [EAX]
//         0044dd28     PUSH       EDX
//         0044dd29     PUSH       _IID_IDirectDraw2                                = E0h
//         0044dd2e     PUSH       EAX=>DAT_fffffff4
//         0044dd2f     MOV        dword ptr [EBX],0x100
//         0044dd35     CALL       dword ptr [ECX]
//                              getdxver.cpp:222 (4)
//         0044dd37     TEST       EAX,EAX
//         0044dd39     JGE        LAB_0044dd62
//                              getdxver.cpp:227 (10)
//         0044dd3b     MOV        EAX,dword ptr [ESP + 0x10]
//         0044dd3f     PUSH       EAX
//         0044dd40     MOV        ECX,dword ptr [EAX]
//         0044dd42     CALL       dword ptr [ECX + 0x8]
//                              getdxver.cpp:228 (7)
//         0044dd45     PUSH       ESI
//         0044dd46     CALL       dword ptr [->KERNEL32.DLL::FreeLibrary]          = 0048aa18
//                              getdxver.cpp:229 (11)
//         0044dd4c     PUSH       s_Couldn't_QI_DDraw2__                           = "Couldn't QI DDraw2\r\n"
//         0044dd51     CALL       dword ptr [->KERNEL32.DLL::OutputDebugStringA]   = 0048aa96
//                              getdxver.cpp:338 (11)
//         0044dd57     POP        EDI
//         0044dd58     POP        ESI
//         0044dd59     POP        EBP
//         0044dd5a     POP        EBX
//         0044dd5b     ADD        ESP,0x114
//         0044dd61     RET
//                               LAB_0044dd62                                                 XREF[1]:     0044dd39(j)
//                              getdxver.cpp:235 (10)
//         0044dd62     MOV        EAX,dword ptr [ESP + 0x1c]
//         0044dd66     PUSH       EAX
//         0044dd67     MOV        EDX,dword ptr [EAX]
//         0044dd69     CALL       dword ptr [EDX + 0x8]
//                              getdxver.cpp:241 (15)
//         0044dd6c     PUSH       s_DINPUT.DLL                                     = "DINPUT.DLL"
//         0044dd71     MOV        dword ptr [EBX],0x200
//         0044dd77     CALL       EBP=>KERNEL32.DLL::LoadLibraryA
//         0044dd79     MOV        EDI,EAX
//                              getdxver.cpp:242 (4)
//         0044dd7b     TEST       EDI,EDI
//         0044dd7d     JNZ        LAB_0044dda6
//                              getdxver.cpp:247 (11)
//         0044dd7f     PUSH       s_Couldn't_LoadLibrary_DInput__                  = "Couldn't LoadLibrary DInput\r\n"
//         0044dd84     CALL       dword ptr [->KERNEL32.DLL::OutputDebugStringA]   = 0048aa96
//                              getdxver.cpp:248 (10)
//         0044dd8a     MOV        EAX,dword ptr [ESP + 0x10]
//         0044dd8e     PUSH       EAX
//         0044dd8f     MOV        ECX,dword ptr [EAX]
//         0044dd91     CALL       dword ptr [ECX + 0x8]
//                              getdxver.cpp:249 (7)
//         0044dd94     PUSH       ESI
//         0044dd95     CALL       dword ptr [->KERNEL32.DLL::FreeLibrary]          = 0048aa18
//                              getdxver.cpp:338 (11)
//         0044dd9b     POP        EDI
//         0044dd9c     POP        ESI
//         0044dd9d     POP        EBP
//         0044dd9e     POP        EBX
//         0044dd9f     ADD        ESP,0x114
//         0044dda5     RET
//                               LAB_0044dda6                                                 XREF[1]:     0044dd7d(j)
//                              getdxver.cpp:254 (12)
//         0044dda6     PUSH       s_DirectInputCreateA                             = "DirectInputCreateA"
//         0044ddab     PUSH       EDI=>DAT_fffffff8
//         0044ddac     CALL       dword ptr [->KERNEL32.DLL::GetProcAddress]       = 0048abb0
//                              getdxver.cpp:255 (13)
//         0044ddb2     MOV        EBP,dword ptr [->KERNEL32.DLL::FreeLibrary]      = 0048aa18
//         0044ddb8     PUSH       EDI
//         0044ddb9     MOV        dword ptr [ESP + 0x18],EAX
//         0044ddbd     CALL       EBP=>KERNEL32.DLL::FreeLibrary
//                              getdxver.cpp:257 (8)
//         0044ddbf     MOV        EAX,dword ptr [ESP + 0x14]
//         0044ddc3     TEST       EAX,EAX
//         0044ddc5     JNZ        LAB_0044ddea
//                              getdxver.cpp:262 (3)
//         0044ddc7     PUSH       ESI
//         0044ddc8     CALL       EBP=>KERNEL32.DLL::FreeLibrary
//                              getdxver.cpp:263 (10)
//         0044ddca     MOV        EAX,dword ptr [ESP + 0x10]
//         0044ddce     PUSH       EAX
//         0044ddcf     MOV        EDX,dword ptr [EAX]
//         0044ddd1     CALL       dword ptr [EDX + 0x8]
//                              getdxver.cpp:264 (11)
//         0044ddd4     PUSH       s_Couldn't_GetProcAddress_DInputCr               = "Couldn't GetProcAddress DInputCreate\r\n"
//         0044ddd9     CALL       dword ptr [->KERNEL32.DLL::OutputDebugStringA]   = 0048aa96
//                              getdxver.cpp:338 (11)
//         0044dddf     POP        EDI
//         0044dde0     POP        ESI
//         0044dde1     POP        EBP
//         0044dde2     POP        EBX
//         0044dde3     ADD        ESP,0x114
//         0044dde9     RET
//                               LAB_0044ddea                                                 XREF[1]:     0044ddc5(j)
//                              getdxver.cpp:283 (11)
//         0044ddea     MOV        ECX,0x1b
//         0044ddef     XOR        EAX,EAX
//         0044ddf1     LEA        EDI,[ESP + 0x24]
//                              getdxver.cpp:288 (49)
//         0044ddf5     PUSH       0x8
//         0044ddf7     STOSD.REP  ES:EDI
//         0044ddf9     MOV        EAX,dword ptr [ESP + 0x14]
//         0044ddfd     PUSH       0x0=>DAT_fffffff8
//         0044ddff     PUSH       EAX=>DAT_fffffff4
//         0044de00     MOV        dword ptr [EBX],0x300
//         0044de06     MOV        ECX,dword ptr [EAX]
//         0044de08     MOV        dword ptr [ESP + 0x30],0x6c
//         0044de10     MOV        dword ptr [ESP + 0x34],0x1
//         0044de18     MOV        dword ptr [ESP + 0x98],0x200
//         0044de23     CALL       dword ptr [ECX + 0x50]
//                              getdxver.cpp:289 (2)
//         0044de26     TEST       EAX,EAX
//                              getdxver.cpp:294 (12)
//         0044de28     MOV        EAX,dword ptr [ESP + 0x10]
//         0044de2c     JGE        LAB_0044de53
//         0044de2e     MOV        EDX,dword ptr [EAX]
//         0044de30     PUSH       EAX
//         0044de31     CALL       dword ptr [EDX + 0x8]
//                              getdxver.cpp:295 (3)
//         0044de34     PUSH       ESI
//         0044de35     CALL       EBP=>KERNEL32.DLL::FreeLibrary
//                              getdxver.cpp:297 (17)
//         0044de37     PUSH       s_Couldn't_Set_coop_level__                      = "Couldn't Set coop level\r\n"
//         0044de3c     MOV        dword ptr [EBX],0x0
//         0044de42     CALL       dword ptr [->KERNEL32.DLL::OutputDebugStringA]   = 0048aa96
//                              getdxver.cpp:338 (11)
//         0044de48     POP        EDI
//         0044de49     POP        ESI
//         0044de4a     POP        EBP
//         0044de4b     POP        EBX
//         0044de4c     ADD        ESP,0x114
//         0044de52     RET
//                               LAB_0044de53                                                 XREF[1]:     0044de2c(j)
//                              getdxver.cpp:301 (18)
//         0044de53     MOV        ECX,dword ptr [EAX]
//         0044de55     LEA        EDX,[ESP + 0x18]
//         0044de59     PUSH       0x0
//         0044de5b     PUSH       EDX=>DAT_fffffff8
//         0044de5c     LEA        EDX,[ESP + 0x2c]
//         0044de60     PUSH       EDX=>DAT_fffffff4
//         0044de61     PUSH       EAX=>DAT_fffffff0
//         0044de62     CALL       dword ptr [ECX + 0x18]
//                              getdxver.cpp:302 (4)
//         0044de65     TEST       EAX,EAX
//         0044de67     JGE        LAB_0044de92
//                              getdxver.cpp:307 (10)
//         0044de69     MOV        EAX,dword ptr [ESP + 0x10]
//         0044de6d     PUSH       EAX
//         0044de6e     MOV        ECX,dword ptr [EAX]
//         0044de70     CALL       dword ptr [ECX + 0x8]
//                              getdxver.cpp:308 (3)
//         0044de73     PUSH       ESI
//         0044de74     CALL       EBP=>KERNEL32.DLL::FreeLibrary
//                              getdxver.cpp:310 (17)
//         0044de76     PUSH       s_Couldn't_CreateSurface__                       = "Couldn't CreateSurface\r\n"
//         0044de7b     MOV        dword ptr [EBX],0x0
//         0044de81     CALL       dword ptr [->KERNEL32.DLL::OutputDebugStringA]   = 0048aa96
//                              getdxver.cpp:338 (11)
//         0044de87     POP        EDI
//         0044de88     POP        ESI
//         0044de89     POP        EBP
//         0044de8a     POP        EBX
//         0044de8b     ADD        ESP,0x114
//         0044de91     RET
//                               LAB_0044de92                                                 XREF[1]:     0044de67(j)
//                              getdxver.cpp:317 (21)
//         0044de92     MOV        EAX,dword ptr [ESP + 0x18]
//         0044de96     LEA        ECX,[ESP + 0x20]
//         0044de9a     PUSH       ECX
//         0044de9b     PUSH       _IID_IDirectDrawSurface3                         = align(1)
//         0044dea0     MOV        EDX,dword ptr [EAX]
//         0044dea2     PUSH       EAX=>DAT_fffffff4
//         0044dea3     CALL       dword ptr [EDX]
//         0044dea5     TEST       EAX,EAX
//                              getdxver.cpp:322 (2)
//         0044dea7     JL         LAB_0044dec5
//                              getdxver.cpp:328 (18)
//         0044dea9     CALL       IsDPlay501a                                      int IsDPlay501a(void)
//         0044deae     NEG        EAX
//         0044deb0     SBB        EAX,EAX
//         0044deb2     NEG        EAX
//         0044deb4     ADD        EAX,0x500
//         0044deb9     MOV        dword ptr [EBX],EAX
//                              getdxver.cpp:333 (10)
//         0044debb     MOV        EAX,dword ptr [ESP + 0x18]
//         0044debf     PUSH       EAX
//         0044dec0     MOV        ECX,dword ptr [EAX]
//         0044dec2     CALL       dword ptr [ECX + 0x8]
//                               LAB_0044dec5                                                 XREF[1]:     0044dea7(j)
//                              getdxver.cpp:334 (10)
//         0044dec5     MOV        EAX,dword ptr [ESP + 0x10]
//         0044dec9     PUSH       EAX
//         0044deca     MOV        EDX,dword ptr [EAX]
//         0044decc     CALL       dword ptr [EDX + 0x8]
//                              getdxver.cpp:335 (3)
//         0044decf     PUSH       ESI
//         0044ded0     CALL       EBP=>KERNEL32.DLL::FreeLibrary
//                               LAB_0044ded2                                                 XREF[1]:     0044dbe2(j)
//                              getdxver.cpp:338 (11)
//         0044ded2     POP        EDI
//         0044ded3     POP        ESI
//         0044ded4     POP        EBP
//         0044ded5     POP        EBX
//         0044ded6     ADD        ESP,0x114
//         0044dedc     RET
//         0044dedd     ??         90h
//         0044dede     NOP
//         0044dedf     NOP
    return;
}

int IsDPlay501a() {
    /* TODO: Stub */
//                              int __cdecl IsDPlay501a(void)
//              int               EAX:4          <RETURN>
//              uint              Stack[-0x8]:4  verSize                   XREF[1]:     0044dee3(*)
//              ulong             Stack[-0xc]:4  zero
//              tagVS_FIXEDFIL    Stack[-0x10]:4 verInfo
//                               ?IsDPlay501a@@YAHXZ                                          XREF[2]:     GetDXVersion:0044dc0d(c),
//                               IsDPlay501a                                                               GetDXVersion:0044dea9(c)
//                              getdxver.cpp:342 (3)
//         0044dee0     SUB        ESP,0xc
//                              getdxver.cpp:344 (19)
//         0044dee3     LEA        EAX=>verSize,[ESP + 0x4]
//         0044dee7     PUSH       ESI
//         0044dee8     PUSH       EDI
//         0044dee9     PUSH       EAX
//         0044deea     PUSH       s_dplayx.dll                                     = "dplayx.dll"
//         0044deef     CALL       _GetFileVersionInfoSizeA@8                       undefined _GetFileVersionInfoSizeA@8()
//         0044def4     MOV        EDI,EAX
//                              getdxver.cpp:345 (4)
//         0044def6     TEST       EDI,EDI
//         0044def8     JNZ        LAB_0044df08
//                              getdxver.cpp:347 (6)
//         0044defa     CALL       dword ptr [->KERNEL32.DLL::GetLastError]         = 0048aa76
//                              getdxver.cpp:388 (2)
//         0044df00     XOR        EAX,EAX
//                              getdxver.cpp:389 (6)
//         0044df02     POP        EDI
//         0044df03     POP        ESI
//         0044df04     ADD        ESP,0xc
//         0044df07     RET
//                               LAB_0044df08                                                 XREF[1]:     0044def8(j)
//                              getdxver.cpp:352 (11)
//         0044df08     PUSH       EDI
//         0044df09     CALL       operator_new                                     void * operator_new(uint param_1)
//         0044df0e     MOV        ESI,EAX
//         0044df10     ADD        ESP,0x4
//                              getdxver.cpp:353 (2)
//         0044df13     TEST       ESI,ESI
//                              getdxver.cpp:356 (2)
//         0044df15     JZ         LAB_0044df78
//                              getdxver.cpp:359 (14)
//         0044df17     PUSH       ESI
//         0044df18     PUSH       EDI=>DAT_fffffff8
//         0044df19     PUSH       0x0=>DAT_fffffff4
//         0044df1b     PUSH       s_dplayx.dll                                     = "dplayx.dll"
//         0044df20     CALL       _GetFileVersionInfoA@16                          undefined _GetFileVersionInfoA@16()
//                              getdxver.cpp:360 (4)
//         0044df25     TEST       EAX,EAX
//         0044df27     JNZ        LAB_0044df37
//                              getdxver.cpp:362 (6)
//         0044df29     CALL       dword ptr [->KERNEL32.DLL::GetLastError]         = 0048aa76
//                              getdxver.cpp:388 (2)
//         0044df2f     XOR        EAX,EAX
//                              getdxver.cpp:389 (6)
//         0044df31     POP        EDI
//         0044df32     POP        ESI
//         0044df33     ADD        ESP,0xc
//         0044df36     RET
//                               LAB_0044df37                                                 XREF[1]:     0044df27(j)
//                              getdxver.cpp:369 (21)
//         0044df37     LEA        ECX,[ESP + 0x10]
//         0044df3b     LEA        EDX,[ESP + 0x8]
//         0044df3f     PUSH       ECX
//         0044df40     PUSH       EDX=>DAT_fffffff8
//         0044df41     PUSH       s_\                                              = "\\"
//         0044df46     PUSH       ESI=>DAT_fffffff0
//         0044df47     CALL       _VerQueryValueA@16                               undefined _VerQueryValueA@16()
//                              getdxver.cpp:370 (2)
//         0044df4c     TEST       EAX,EAX
//                              getdxver.cpp:373 (2)
//         0044df4e     JZ         LAB_0044df78
//                              getdxver.cpp:377 (7)
//         0044df50     MOV        ECX,dword ptr [ESP + 0x8]
//         0044df54     MOV        EAX,dword ptr [ECX + 0x8]
//                              getdxver.cpp:378 (3)
//         0044df57     MOV        ECX,dword ptr [ECX + 0xc]
//                              getdxver.cpp:385 (19)
//         0044df5a     CMP        EAX,0x40005
//         0044df5f     JNZ        LAB_0044df6b
//         0044df61     CMP        ECX,0x1062f
//         0044df67     JNC        LAB_0044df6d
//         0044df69     CMP        EAX,EAX
//                               LAB_0044df6b                                                 XREF[1]:     0044df5f(j)
//         0044df6b     JBE        LAB_0044df78
//                               LAB_0044df6d                                                 XREF[1]:     0044df67(j)
//                              getdxver.cpp:386 (5)
//         0044df6d     MOV        EAX,0x1
//                              getdxver.cpp:389 (14)
//         0044df72     POP        EDI
//         0044df73     POP        ESI
//         0044df74     ADD        ESP,0xc
//         0044df77     RET
//                               LAB_0044df78                                                 XREF[3]:     0044df15(j), 0044df4e(j),
//                                                                                                         0044df6b(j)
//         0044df78     POP        EDI
//         0044df79     XOR        EAX,EAX
//         0044df7b     POP        ESI
//         0044df7c     ADD        ESP,0xc
//         0044df7f     RET
    return 0;
}

