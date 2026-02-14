// Auto-generated scaffold unit: drawarea.cpp.asm
// SourceMap: C:/msdev/work/age1_x1/Drawarea.cpp
#include "../include/common.h"

// Offset: 0x00442680
undefined TDrawSystem(TDrawSystem* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall TDrawSystem::TDrawSystem(void)                                                     *
    //                              *********************************************************************************************************
    //                              undefined __thiscall TDrawSystem(TDrawSystem * this)
    //              undefined         <UNASSIGNED>   <RETURN>
    //              TDrawSystem *     ECX:4 (auto)   this
    //                               ??0TDrawSystem@@QAE@XZ                                       XREF[1]:     setup_graphics_system:0041e9db(c)  
    //                               TDrawSystem::TDrawSystem
    //                              Drawarea.cpp:316 (5)
    //         00442680     XOR        EAX,EAX
    //         00442682     PUSH       ESI
    //         00442683     MOV        ESI,this
    //                              Drawarea.cpp:357 (130)
    //         00442685     PUSH       EAX
    //         00442686     PUSH       DAT_ff00ff00
    //         0044268b     PUSH       EAX
    //         0044268c     MOV        dword ptr [ESI],EAX
    //         0044268e     MOV        dword ptr [ESI + 0x4],EAX
    //         00442691     MOV        dword ptr [ESI + 0x8],EAX
    //         00442694     MOV        dword ptr [ESI + 0xc],EAX
    //         00442697     MOV        dword ptr [ESI + 0x10],EAX
    //         0044269a     MOV        dword ptr [ESI + 0x18],EAX
    //         0044269d     MOV        dword ptr [ESI + 0x1c],EAX
    //         004426a0     MOV        dword ptr [ESI + 0x20],EAX
    //         004426a3     MOV        dword ptr [ESI + 0x24],EAX
    //         004426a6     MOV        dword ptr [ESI + 0x3c],EAX
    //         004426a9     MOV        byte ptr [ESI + 0x478],AL
    //         004426af     MOV        byte ptr [ESI + 0x479],AL
    //         004426b5     MOV        dword ptr [ESI + 0x2c],EAX
    //         004426b8     MOV        dword ptr [ESI + 0x30],EAX
    //         004426bb     MOV        dword ptr [ESI + 0x34],0x8
    //         004426c2     MOV        dword ptr [ESI + 0x28],EAX
    //         004426c5     MOV        dword ptr [ESI + 0x40],EAX
    //         004426c8     MOV        dword ptr [ESI + 0x44],EAX
    //         004426cb     MOV        dword ptr [ESI + 0x14],EAX
    //         004426ce     MOV        dword ptr [ESI + 0x48],EAX
    //         004426d1     MOV        dword ptr [ESI + 0x4c],EAX
    //         004426d4     MOV        dword ptr [ESI + 0x50],EAX
    //         004426d7     MOV        dword ptr [ESI + 0x54],EAX
    //         004426da     MOV        dword ptr [ESI + 0x58],EAX
    //         004426dd     MOV        dword ptr [ESI + 0x5c],EAX
    //         004426e0     MOV        dword ptr [ESI + 0x60],EAX
    //         004426e3     MOV        dword ptr [ESI + 0x64],EAX
    //         004426e6     MOV        dword ptr [ESI + 0x68],EAX
    //         004426e9     MOV        dword ptr [ESI + 0x6c],EAX
    //         004426ec     MOV        dword ptr [ESI + 0x70],EAX
    //         004426ef     MOV        dword ptr [ESI + 0x74],EAX
    //         004426f2     MOV        dword ptr [ESI + 0x38],EAX
    //         004426f5     PUSH       0xff00ff
    //         004426fa     MOV        [system_ignore_size_messages],EAX
    //         004426ff     CALL       _ASMSet_Shadowing                                undefined _ASMSet_Shadowing()
    //         00442704     ADD        ESP,0x10
    //                              Drawarea.cpp:378 (4)
    //         00442707     MOV        EAX,ESI
    //         00442709     POP        ESI
    //         0044270a     RET
}

// Offset: 0x00442710
void TDrawSystem(TDrawSystem* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall TDrawSystem::~TDrawSystem(void)                                                    *
    //                              *********************************************************************************************************
    //                              void __thiscall ~TDrawSystem(TDrawSystem * this)
    //              void              <VOID>         <RETURN>
    //              TDrawSystem *     ECX:4 (auto)   this
    //              _DDBLTFX          Stack[-0x68]   ddbltfx                   XREF[0,3]:   0044272b(*), 00442739(W), 00442741(W)  
    //                               ??1TDrawSystem@@QAE@XZ                                       XREF[1]:     ~RGE_Base_Game:0041c589(c)  
    //                               TDrawSystem::~TDrawSystem
    //                              Drawarea.cpp:384 (7)
    //         00442710     SUB        ESP,0x64
    //         00442713     PUSH       ESI
    //         00442714     MOV        ESI,this
    //         00442716     PUSH       EDI
    //                              Drawarea.cpp:397 (18)
    //         00442717     XOR        EDI,EDI
    //         00442719     CMP        byte ptr [ESI + 0x479],0x2
    //         00442720     JNZ        LAB_00442748
    //         00442722     MOV        EAX,dword ptr [ESI + 0x1c]
    //         00442725     CMP        EAX,EDI
    //         00442727     JZ         LAB_00442748
    //                              Drawarea.cpp:402 (31)
    //         00442729     MOV        this,dword ptr [EAX]
    //         0044272b     LEA        EDX=>ddbltfx.dwDDFX,[ESP + 0x8]
    //         0044272f     PUSH       EDX
    //         00442730     PUSH       0x1000400
    //         00442735     PUSH       EDI
    //         00442736     PUSH       EDI
    //         00442737     PUSH       EDI
    //         00442738     PUSH       EAX
    //         00442739     MOV        dword ptr [ESP + ddbltfx.dwDDFX],0x64
    //         00442741     MOV        dword ptr [ESP + ddbltfx.ddckDestColorkey.dwCo
    //         00442745     CALL       dword ptr [ECX + this->DrawAreaList]
    //                               LAB_00442748                                                 XREF[2]:     00442720(j), 00442727(j)  
    //                              Drawarea.cpp:406 (7)
    //         00442748     MOV        this,ESI
    //         0044274a     CALL       TDrawSystem::DeleteSurfaces                      void DeleteSurfaces(TDrawSystem * this)
    //                              Drawarea.cpp:408 (5)
    //         0044274f     CMP        dword ptr [ESI + 0x18],EDI
    //         00442752     JZ         LAB_00442791
    //                              Drawarea.cpp:410 (7)
    //         00442754     MOV        EAX,dword ptr [ESI + 0x24]
    //         00442757     CMP        EAX,EDI
    //         00442759     JZ         LAB_00442764
    //                              Drawarea.cpp:412 (6)
    //         0044275b     MOV        this,dword ptr [EAX]
    //         0044275d     PUSH       EAX
    //         0044275e     CALL       dword ptr [ECX + this->Pal]
    //                              Drawarea.cpp:414 (3)
    //         00442761     MOV        dword ptr [ESI + 0x24],EDI
    //                               LAB_00442764                                                 XREF[1]:     00442759(j)  
    //                              Drawarea.cpp:417 (7)
    //         00442764     MOV        EAX,dword ptr [ESI + 0x20]
    //         00442767     CMP        EAX,EDI
    //         00442769     JZ         LAB_00442774
    //                              Drawarea.cpp:419 (6)
    //         0044276b     MOV        EDX,dword ptr [EAX]
    //         0044276d     PUSH       EAX
    //         0044276e     CALL       dword ptr [EDX + 0x8]
    //                              Drawarea.cpp:421 (3)
    //         00442771     MOV        dword ptr [ESI + 0x20],EDI
    //                               LAB_00442774                                                 XREF[1]:     00442769(j)  
    //                              Drawarea.cpp:424 (5)
    //         00442774     CMP        dword ptr [ESI + 0x3c],EDI
    //         00442777     JZ         LAB_00442785
    //                              Drawarea.cpp:426 (9)
    //         00442779     MOV        EAX,dword ptr [ESI + 0x18]
    //         0044277c     PUSH       EAX
    //         0044277d     MOV        this,dword ptr [EAX]
    //         0044277f     CALL       dword ptr [ECX + this->ModeAvail640]
    //                              Drawarea.cpp:428 (3)
    //         00442782     MOV        dword ptr [ESI + 0x3c],EDI
    //                               LAB_00442785                                                 XREF[1]:     00442777(j)  
    //                              Drawarea.cpp:431 (9)
    //         00442785     MOV        EAX,dword ptr [ESI + 0x18]
    //         00442788     PUSH       EAX
    //         00442789     MOV        EDX,dword ptr [EAX]
    //         0044278b     CALL       dword ptr [EDX + 0x8]
    //                              Drawarea.cpp:433 (3)
    //         0044278e     MOV        dword ptr [ESI + 0x18],EDI
    //                               LAB_00442791                                                 XREF[1]:     00442752(j)  
    //                              Drawarea.cpp:438 (6)
    //         00442791     POP        EDI
    //         00442792     POP        ESI
    //         00442793     ADD        ESP,0x64
    //         00442796     RET
}

// Offset: 0x004427A0
void CheckAvailModes(TDrawSystem* this_, int param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TDrawSystem::CheckAvailModes(int)                                             *
    //                              *********************************************************************************************************
    //                              void __thiscall CheckAvailModes(TDrawSystem * this, int param_1)
    //              void              <VOID>         <RETURN>
    //              TDrawSystem *     ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     004427a0(R)  
    //                               ?CheckAvailModes@TDrawSystem@@QAEXH@Z                        XREF[2]:     setup_graphics_system:0041ea12(c), 
    //                               TDrawSystem::CheckAvailModes                                              Init:00442b33(c)  
    //                              Drawarea.cpp:444 (14)
    //         004427a0     MOV        EAX,dword ptr [ESP + param_1]
    //         004427a4     PUSH       EBX
    //         004427a5     PUSH       EBP
    //         004427a6     PUSH       ESI
    //         004427a7     PUSH       EDI
    //         004427a8     MOV        EDI,this
    //         004427aa     TEST       EAX,EAX
    //         004427ac     JNZ        LAB_00442816
    //                              Drawarea.cpp:457 (26)
    //         004427ae     PUSH       0x0
    //         004427b0     PUSH       0x0
    //         004427b2     PUSH       0x0
    //         004427b4     PUSH       s_DISPLAY                                        = "DISPLAY"
    //         004427b9     MOV        dword ptr [EDI + 0x4c],0x1
    //         004427c0     CALL       dword ptr [->GDI32.DLL::CreateICA]               = 0048b1f8
    //         004427c6     MOV        ESI,EAX
    //                              Drawarea.cpp:458 (8)
    //         004427c8     TEST       ESI,ESI
    //         004427ca     JZ         LAB_00442857
    //                              Drawarea.cpp:460 (11)
    //         004427d0     MOV        EBX,dword ptr [->GDI32.DLL::GetDeviceCaps]       = 0048b170
    //         004427d6     PUSH       0x8
    //         004427d8     PUSH       ESI=>DAT_fffffff8
    //         004427d9     CALL       EBX=>GDI32.DLL::GetDeviceCaps
    //                              Drawarea.cpp:461 (7)
    //         004427db     PUSH       0xa
    //         004427dd     PUSH       ESI=>DAT_fffffff8
    //         004427de     MOV        EBP,EAX
    //         004427e0     CALL       EBX=>GDI32.DLL::GetDeviceCaps
    //                              Drawarea.cpp:462 (7)
    //         004427e2     PUSH       ESI
    //         004427e3     CALL       dword ptr [->GDI32.DLL::DeleteDC]                = 0048b1ec
    //                              Drawarea.cpp:464 (6)
    //         004427e9     CMP        EBP,0x320
    //                              Drawarea.cpp:465 (10)
    //         004427ef     MOV        EAX,0x1
    //         004427f4     JL         LAB_004427f9
    //         004427f6     MOV        dword ptr [EDI + 0x50],EAX
    //                               LAB_004427f9                                                 XREF[1]:     004427f4(j)  
    //                              Drawarea.cpp:467 (8)
    //         004427f9     CMP        EBP,0x400
    //         004427ff     JL         LAB_00442804
    //                              Drawarea.cpp:468 (3)
    //         00442801     MOV        dword ptr [EDI + 0x54],EAX
    //                               LAB_00442804                                                 XREF[1]:     004427ff(j)  
    //                              Drawarea.cpp:470 (8)
    //         00442804     CMP        EBP,0x500
    //         0044280a     JL         LAB_00442857
    //                              Drawarea.cpp:471 (3)
    //         0044280c     MOV        dword ptr [EDI + 0x58],EAX
    //                              Drawarea.cpp:498 (7)
    //         0044280f     POP        EDI
    //         00442810     POP        ESI
    //         00442811     POP        EBP
    //         00442812     POP        EBX
    //         00442813     RET        0x4
    //                               LAB_00442816                                                 XREF[1]:     004427ac(j)  
    //                              Drawarea.cpp:476 (10)
    //         00442816     MOV        EAX,dword ptr [EDI + 0x18]
    //         00442819     LEA        ESI,[EDI + 0x18]
    //         0044281c     TEST       EAX,EAX
    //         0044281e     JNZ        LAB_00442832
    //                              Drawarea.cpp:478 (10)
    //         00442820     PUSH       0x0
    //         00442822     PUSH       ESI
    //         00442823     PUSH       0x0
    //         00442825     CALL       _DirectDrawCreate@12                             undefined _DirectDrawCreate@12()
    //                              Drawarea.cpp:481 (4)
    //         0044282a     TEST       EAX,EAX
    //         0044282c     JNZ        LAB_00442857
    //                              Drawarea.cpp:483 (2)
    //         0044282e     XOR        EBX,EBX
    //                              Drawarea.cpp:485 (2)
    //         00442830     JMP        LAB_00442837
    //                               LAB_00442832                                                 XREF[1]:     0044281e(j)  
    //                              Drawarea.cpp:486 (5)
    //         00442832     MOV        EBX,0x1
    //                               LAB_00442837                                                 XREF[1]:     00442830(j)  
    //                              Drawarea.cpp:489 (18)
    //         00442837     MOV        EAX,dword ptr [ESI]
    //         00442839     PUSH       TDrawSystem::CheckAvailModesCallback
    //         0044283e     PUSH       EDI
    //         0044283f     PUSH       0x0
    //         00442841     MOV        this,dword ptr [EAX]
    //         00442843     PUSH       0x0
    //         00442845     PUSH       EAX
    //         00442846     CALL       dword ptr [ECX + this->Clipper]
    //                              Drawarea.cpp:491 (4)
    //         00442849     TEST       EBX,EBX
    //         0044284b     JNZ        LAB_00442857
    //                              Drawarea.cpp:493 (8)
    //         0044284d     MOV        EAX,dword ptr [ESI]
    //         0044284f     PUSH       EAX
    //         00442850     MOV        EDX,dword ptr [EAX]
    //         00442852     CALL       dword ptr [EDX + 0x8]
    //                              Drawarea.cpp:495 (2)
    //         00442855     MOV        dword ptr [ESI],EBX
    //                               LAB_00442857                                                 XREF[4]:     004427ca(j), 0044280a(j), 
    //                                                                                                         0044282c(j), 0044284b(j)  
    //                              Drawarea.cpp:498 (7)
    //         00442857     POP        EDI
    //         00442858     POP        ESI
    //         00442859     POP        EBP
    //         0044285a     POP        EBX
    //         0044285b     RET        0x4
}

// Offset: 0x00442860
long CheckAvailModesCallback(_DDSURFACEDESC* param_1, void* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: static long __stdcall TDrawSystem::CheckAvailModesCallback(struct _DDSURFACEDESC *,void *)    *
    //                              *********************************************************************************************************
    //                              long __stdcall CheckAvailModesCallback(_DDSURFACEDESC * param_1, voi
    //              long              EAX:4          <RETURN>
    //              _DDSURFACEDESC    Stack[0x4]:4   param_1                   XREF[1]:     00442860(R)  
    //              void *            Stack[0x8]:4   param_2                   XREF[11]:    00442889(R), 004428a4(R), 004428bf(R), 004428da(R), 
    //                                                                                     004428f9(R), 0044291c(R), 00442943(R), 0044295e(R), 
    //                                                                                     00442979(R), 00442994(R), 004429af(R)  
    //                               ?CheckAvailModesCallback@TDrawSystem@@SGJPAU_DDSURFACEDESC@  XREF[1]:     CheckAvailModes:00442839(*)  
    //                               TDrawSystem::CheckAvailModesCallback
    //                              Drawarea.cpp:504 (21)
    //         00442860     MOV        ECX,dword ptr [ESP + param_1]
    //         00442864     MOV        EAX,0x1
    //         00442869     MOV        EDX,dword ptr [ECX + 0x54]
    //         0044286c     CMP        EDX,0x8
    //         0044286f     JNZ        LAB_00442926
    //                              Drawarea.cpp:511 (20)
    //         00442875     MOV        EDX,dword ptr [ECX + 0xc]
    //         00442878     CMP        EDX,0x280
    //         0044287e     JNZ        LAB_00442893
    //         00442880     CMP        dword ptr [ECX + 0x8],0x1e0
    //         00442887     JNZ        LAB_00442893
    //                              Drawarea.cpp:513 (7)
    //         00442889     MOV        ECX,dword ptr [ESP + param_2]
    //         0044288d     MOV        dword ptr [ECX + 0x4c],EAX
    //                              Drawarea.cpp:574 (3)
    //         00442890     RET        0x8
    //                               LAB_00442893                                                 XREF[2]:     0044287e(j), 00442887(j)  
    //                              Drawarea.cpp:516 (17)
    //         00442893     CMP        EDX,0x320
    //         00442899     JNZ        LAB_004428ae
    //         0044289b     CMP        dword ptr [ECX + 0x8],0x258
    //         004428a2     JNZ        LAB_004428ae
    //                              Drawarea.cpp:518 (7)
    //         004428a4     MOV        EDX,dword ptr [ESP + param_2]
    //         004428a8     MOV        dword ptr [EDX + 0x50],EAX
    //                              Drawarea.cpp:574 (3)
    //         004428ab     RET        0x8
    //                               LAB_004428ae                                                 XREF[2]:     00442899(j), 004428a2(j)  
    //                              Drawarea.cpp:521 (17)
    //         004428ae     CMP        EDX,0x400
    //         004428b4     JNZ        LAB_004428c9
    //         004428b6     CMP        dword ptr [ECX + 0x8],0x300
    //         004428bd     JNZ        LAB_004428c9
    //                              Drawarea.cpp:523 (7)
    //         004428bf     MOV        ECX,dword ptr [ESP + param_2]
    //         004428c3     MOV        dword ptr [ECX + 0x54],EAX
    //                              Drawarea.cpp:574 (3)
    //         004428c6     RET        0x8
    //                               LAB_004428c9                                                 XREF[2]:     004428b4(j), 004428bd(j)  
    //                              Drawarea.cpp:526 (17)
    //         004428c9     CMP        EDX,0x500
    //         004428cf     JNZ        LAB_004428e4
    //         004428d1     CMP        dword ptr [ECX + 0x8],0x400
    //         004428d8     JNZ        LAB_004428e4
    //                              Drawarea.cpp:528 (7)
    //         004428da     MOV        EDX,dword ptr [ESP + param_2]
    //         004428de     MOV        dword ptr [EDX + 0x58],EAX
    //                              Drawarea.cpp:574 (3)
    //         004428e1     RET        0x8
    //                               LAB_004428e4                                                 XREF[2]:     004428cf(j), 004428d8(j)  
    //                              Drawarea.cpp:531 (21)
    //         004428e4     CMP        EDX,0x140
    //         004428ea     JNZ        LAB_004429b6
    //         004428f0     CMP        dword ptr [ECX + 0x8],0xc8
    //         004428f7     JNZ        LAB_00442903
    //                              Drawarea.cpp:533 (7)
    //         004428f9     MOV        ECX,dword ptr [ESP + param_2]
    //         004428fd     MOV        dword ptr [ECX + 0x5c],EAX
    //                              Drawarea.cpp:574 (3)
    //         00442900     RET        0x8
    //                               LAB_00442903                                                 XREF[1]:     004428f7(j)  
    //                              Drawarea.cpp:536 (25)
    //         00442903     CMP        EDX,0x140
    //         00442909     JNZ        LAB_004429b6
    //         0044290f     CMP        dword ptr [ECX + 0x8],0xf0
    //         00442916     JNZ        LAB_004429b6
    //                              Drawarea.cpp:538 (7)
    //         0044291c     MOV        EDX,dword ptr [ESP + param_2]
    //         00442920     MOV        dword ptr [EDX + 0x60],EAX
    //                              Drawarea.cpp:574 (3)
    //         00442923     RET        0x8
    //                               LAB_00442926                                                 XREF[1]:     0044286f(j)  
    //                              Drawarea.cpp:542 (9)
    //         00442926     CMP        EDX,0x10
    //         00442929     JNZ        LAB_004429b6
    //                              Drawarea.cpp:546 (20)
    //         0044292f     MOV        EDX,dword ptr [ECX + 0xc]
    //         00442932     CMP        EDX,0x280
    //         00442938     JNZ        LAB_0044294d
    //         0044293a     CMP        dword ptr [ECX + 0x8],0x1e0
    //         00442941     JNZ        LAB_0044294d
    //                              Drawarea.cpp:548 (7)
    //         00442943     MOV        ECX,dword ptr [ESP + param_2]
    //         00442947     MOV        dword ptr [ECX + 0x6c],EAX
    //                              Drawarea.cpp:574 (3)
    //         0044294a     RET        0x8
    //                               LAB_0044294d                                                 XREF[2]:     00442938(j), 00442941(j)  
    //                              Drawarea.cpp:551 (17)
    //         0044294d     CMP        EDX,0x320
    //         00442953     JNZ        LAB_00442968
    //         00442955     CMP        dword ptr [ECX + 0x8],0x258
    //         0044295c     JNZ        LAB_00442968
    //                              Drawarea.cpp:553 (7)
    //         0044295e     MOV        EDX,dword ptr [ESP + param_2]
    //         00442962     MOV        dword ptr [EDX + 0x70],EAX
    //                              Drawarea.cpp:574 (3)
    //         00442965     RET        0x8
    //                               LAB_00442968                                                 XREF[2]:     00442953(j), 0044295c(j)  
    //                              Drawarea.cpp:556 (17)
    //         00442968     CMP        EDX,0x400
    //         0044296e     JNZ        LAB_00442983
    //         00442970     CMP        dword ptr [ECX + 0x8],0x300
    //         00442977     JNZ        LAB_00442983
    //                              Drawarea.cpp:558 (7)
    //         00442979     MOV        ECX,dword ptr [ESP + param_2]
    //         0044297d     MOV        dword ptr [ECX + 0x74],EAX
    //                              Drawarea.cpp:574 (3)
    //         00442980     RET        0x8
    //                               LAB_00442983                                                 XREF[2]:     0044296e(j), 00442977(j)  
    //                              Drawarea.cpp:561 (17)
    //         00442983     CMP        EDX,0x140
    //         00442989     JNZ        LAB_004429b6
    //         0044298b     CMP        dword ptr [ECX + 0x8],0xc8
    //         00442992     JNZ        LAB_0044299e
    //                              Drawarea.cpp:563 (7)
    //         00442994     MOV        EDX,dword ptr [ESP + param_2]
    //         00442998     MOV        dword ptr [EDX + 0x64],EAX
    //                              Drawarea.cpp:574 (3)
    //         0044299b     RET        0x8
    //                               LAB_0044299e                                                 XREF[1]:     00442992(j)  
    //                              Drawarea.cpp:566 (17)
    //         0044299e     CMP        EDX,0x140
    //         004429a4     JNZ        LAB_004429b6
    //         004429a6     CMP        dword ptr [ECX + 0x8],0xf0
    //         004429ad     JNZ        LAB_004429b6
    //                              Drawarea.cpp:568 (7)
    //         004429af     MOV        ECX,dword ptr [ESP + param_2]
    //         004429b3     MOV        dword ptr [ECX + 0x68],EAX
    //                               LAB_004429b6                                                 XREF[7]:     004428ea(j), 00442909(j), 
    //                                                                                                         00442916(j), 00442929(j), 
    //                                                                                                         00442989(j), 004429a4(j), 
    //                                                                                                         004429ad(j)  
    //                              Drawarea.cpp:574 (3)
    //         004429b6     RET        0x8
}

// Offset: 0x004429C0
int IsModeAvail(TDrawSystem* this_, long param_2, long param_3, int param_4) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall TDrawSystem::IsModeAvail(long,long,int)                                        *
    //                              *********************************************************************************************************
    //                              int __thiscall IsModeAvail(TDrawSystem * this, long param_1, long pa
    //              int               EAX:4          <RETURN>
    //              TDrawSystem *     ECX:4 (auto)   this
    //              long              Stack[0x4]:4   param_1                   XREF[2]:     004429c9(R), 00442a35(R)  
    //              long              Stack[0x8]:4   param_2                   XREF[2]:     004429e1(R), 00442a49(R)  
    //              int               Stack[0xc]:4   param_3                   XREF[1]:     004429c0(R)  
    //                               ?IsModeAvail@TDrawSystem@@QAEHJJH@Z                          XREF[10]:    setup_graphics_system:0041ea28(c), 
    //                               TDrawSystem::IsModeAvail                                                  setup_graphics_system:0041ea4d(c), 
    //                                                                                                         setup_graphics_system:0041ea89(c), 
    //                                                                                                         setup_graphics_system:0041eac2(c), 
    //                                                                                                         setup_graphics_system:0041eafb(c), 
    //                                                                                                         TribeConfigDialog:0043bc4a(c), 
    //                                                                                                         TribeConfigDialog:0043bc6a(c), 
    //                                                                                                         TribeConfigDialog:0043bc8e(c), 
    //                                                                                                         setup_video_system:0052a317(c), 
    //                                                                                                         setup_video_system:0052a391(c)  
    //                              Drawarea.cpp:580 (9)
    //         004429c0     MOV        EAX,dword ptr [ESP + param_3]
    //         004429c4     CMP        EAX,0x8
    //         004429c7     JNZ        LAB_00442a30
    //                              Drawarea.cpp:583 (24)
    //         004429c9     MOV        EAX,dword ptr [ESP + param_1]
    //         004429cd     CMP        EAX,0x280
    //         004429d2     JG         LAB_00442a09
    //         004429d4     JZ         LAB_00442a03
    //         004429d6     CMP        EAX,0x140
    //         004429db     JNZ        LAB_00442a87
    //                              Drawarea.cpp:590 (11)
    //         004429e1     MOV        EAX,dword ptr [ESP + param_2]
    //         004429e5     CMP        EAX,0xc8
    //         004429ea     JNZ        LAB_004429f2
    //                              Drawarea.cpp:591 (3)
    //         004429ec     MOV        EAX,dword ptr [ECX + this->ModeAvail320_200]
    //                              Drawarea.cpp:615 (3)
    //         004429ef     RET        0xc
    //                               LAB_004429f2                                                 XREF[1]:     004429ea(j)  
    //                              Drawarea.cpp:592 (11)
    //         004429f2     CMP        EAX,0xf0
    //         004429f7     JNZ        LAB_00442a87
    //                              Drawarea.cpp:593 (3)
    //         004429fd     MOV        EAX,dword ptr [ECX + this->ModeAvail320_240]
    //                              Drawarea.cpp:615 (3)
    //         00442a00     RET        0xc
    //                               LAB_00442a03                                                 XREF[1]:     004429d4(j)  
    //                              Drawarea.cpp:585 (3)
    //         00442a03     MOV        EAX,dword ptr [ECX + this->ModeAvail640]
    //                              Drawarea.cpp:615 (3)
    //         00442a06     RET        0xc
    //                               LAB_00442a09                                                 XREF[1]:     004429d2(j)  
    //                              Drawarea.cpp:583 (19)
    //         00442a09     CMP        EAX,0x320
    //         00442a0e     JZ         LAB_00442a2a
    //         00442a10     CMP        EAX,0x400
    //         00442a15     JZ         LAB_00442a24
    //         00442a17     CMP        EAX,0x500
    //                              Drawarea.cpp:598 (2)
    //         00442a1c     JNZ        LAB_00442a87
    //                              Drawarea.cpp:588 (3)
    //         00442a1e     MOV        EAX,dword ptr [ECX + this->ModeAvail1280]
    //                              Drawarea.cpp:615 (3)
    //         00442a21     RET        0xc
    //                               LAB_00442a24                                                 XREF[1]:     00442a15(j)  
    //                              Drawarea.cpp:587 (3)
    //         00442a24     MOV        EAX,dword ptr [ECX + this->ModeAvail1024]
    //                              Drawarea.cpp:615 (3)
    //         00442a27     RET        0xc
    //                               LAB_00442a2a                                                 XREF[1]:     00442a0e(j)  
    //                              Drawarea.cpp:586 (3)
    //         00442a2a     MOV        EAX,dword ptr [ECX + this->ModeAvail800]
    //                              Drawarea.cpp:615 (3)
    //         00442a2d     RET        0xc
    //                               LAB_00442a30                                                 XREF[1]:     004429c7(j)  
    //                              Drawarea.cpp:598 (5)
    //         00442a30     CMP        EAX,0x10
    //         00442a33     JNZ        LAB_00442a87
    //                              Drawarea.cpp:600 (20)
    //         00442a35     MOV        EAX,dword ptr [ESP + param_1]
    //         00442a39     CMP        EAX,0x280
    //         00442a3e     JG         LAB_00442a6d
    //         00442a40     JZ         LAB_00442a67
    //         00442a42     CMP        EAX,0x140
    //         00442a47     JNZ        LAB_00442a87
    //                              Drawarea.cpp:606 (11)
    //         00442a49     MOV        EAX,dword ptr [ESP + param_2]
    //         00442a4d     CMP        EAX,0xc8
    //         00442a52     JNZ        LAB_00442a5a
    //                              Drawarea.cpp:607 (3)
    //         00442a54     MOV        EAX,dword ptr [ECX + this->ModeAvail320_200_16]
    //                              Drawarea.cpp:615 (3)
    //         00442a57     RET        0xc
    //                               LAB_00442a5a                                                 XREF[1]:     00442a52(j)  
    //                              Drawarea.cpp:608 (7)
    //         00442a5a     CMP        EAX,0xf0
    //         00442a5f     JNZ        LAB_00442a87
    //                              Drawarea.cpp:609 (3)
    //         00442a61     MOV        EAX,dword ptr [ECX + this->ModeAvail320_240_16]
    //                              Drawarea.cpp:615 (3)
    //         00442a64     RET        0xc
    //                               LAB_00442a67                                                 XREF[1]:     00442a40(j)  
    //                              Drawarea.cpp:602 (3)
    //         00442a67     MOV        EAX,dword ptr [ECX + this->ModeAvail640_16]
    //                              Drawarea.cpp:615 (3)
    //         00442a6a     RET        0xc
    //                               LAB_00442a6d                                                 XREF[1]:     00442a3e(j)  
    //                              Drawarea.cpp:600 (14)
    //         00442a6d     CMP        EAX,0x320
    //         00442a72     JZ         LAB_00442a81
    //         00442a74     CMP        EAX,0x400
    //         00442a79     JNZ        LAB_00442a87
    //                              Drawarea.cpp:604 (3)
    //         00442a7b     MOV        EAX,dword ptr [ECX + this->ModeAvail1024_16]
    //                              Drawarea.cpp:615 (3)
    //         00442a7e     RET        0xc
    //                               LAB_00442a81                                                 XREF[1]:     00442a72(j)  
    //                              Drawarea.cpp:603 (3)
    //         00442a81     MOV        EAX,dword ptr [ECX + this->ModeAvail800_16]
    //                              Drawarea.cpp:615 (3)
    //         00442a84     RET        0xc
    //                               LAB_00442a87                                                 XREF[7]:     004429db(j), 004429f7(j), 
    //                                                                                                         00442a1c(j), 00442a33(j), 
    //                                                                                                         00442a47(j), 00442a5f(j), 
    //                                                                                                         00442a79(j)  
    //                              Drawarea.cpp:614 (2)
    //         00442a87     XOR        EAX,EAX
    //                              Drawarea.cpp:615 (3)
    //         00442a89     RET        0xc
}

// Offset: 0x00442A90
int Init(TDrawSystem* this_, void* param_2, void* param_3, void* param_4, uchar param_5, uchar err, long param_7, long param_8, ulong param_9) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall TDrawSystem::Init(void *,void *,void *,unsigned char,unsigned char,long,lon... *
    //                              *********************************************************************************************************
    //                              int __thiscall Init(TDrawSystem * this, void * param_1, void * param
    //              int               EAX:4          <RETURN>
    //              TDrawSystem *     ECX:4 (auto)   this
    //              void *            Stack[0x4]:4   param_1                   XREF[1]:     00442a9d(R)  
    //              void *            Stack[0x8]:4   param_2                   XREF[1]:     00442aa9(R)  
    //              void *            Stack[0xc]:4   param_3                   XREF[1]:     00442a96(R)  
    //              uchar             Stack[0x10]:1  param_4                   XREF[1]:     00442ac7(R)  
    //              uchar             Stack[0x14]:1  param_5                   XREF[1]:     00442ab4(R)  
    //              long              Stack[0x18]:4  param_6                   XREF[1]:     00442abe(R)  
    //              long              Stack[0x1c]:4  param_7                   XREF[1]:     00442ad4(R)  
    //              ulong             Stack[0x20]:4  param_8                   XREF[1]:     00442ade(R)  
    //              tagPALETTEENTR    Stack[-0x404   color_table
    //              _DDCAPS           Stack[-0x540   ddcaps
    //              _DDBLTFX          Stack[-0x5a4   ddbltfx
    //              _DDSURFACEDESC    Stack[-0x610   ddsd
    //                               ?Init@TDrawSystem@@QAEHPAX00EEJJK@Z                          XREF[1]:     setup_graphics_system:0041eb44(c)  
    //                               TDrawSystem::Init
    //                              Drawarea.cpp:621 (6)
    //         00442a90     SUB        ESP,0x60c
    //                              Drawarea.cpp:627 (30)
    //         00442a96     MOV        EDX,dword ptr [ESP + param_3]
    //         00442a9d     MOV        EAX,dword ptr [ESP + param_1]
    //         00442aa4     PUSH       EBX
    //         00442aa5     PUSH       EBP
    //         00442aa6     PUSH       ESI
    //         00442aa7     MOV        ESI,this
    //         00442aa9     MOV        this,dword ptr [ESP + param_2]
    //         00442ab0     PUSH       EDI
    //         00442ab1     MOV        dword ptr [ESI + 0x4],this
    //                              Drawarea.cpp:629 (10)
    //         00442ab4     MOV        this,byte ptr [ESP + param_5]
    //         00442abb     MOV        dword ptr [ESI + 0x8],EDX
    //                              Drawarea.cpp:630 (22)
    //         00442abe     MOV        EDX,dword ptr [ESP + param_6]
    //         00442ac5     MOV        dword ptr [ESI],EAX
    //         00442ac7     MOV        AL,byte ptr [ESP + param_4]
    //         00442ace     MOV        byte ptr [ESI + 0x479],this
    //                              Drawarea.cpp:631 (10)
    //         00442ad4     MOV        this,dword ptr [ESP + param_7]
    //         00442adb     MOV        dword ptr [ESI + 0x2c],EDX
    //                              Drawarea.cpp:632 (7)
    //         00442ade     MOV        EDX,dword ptr [ESP + param_8]
    //                              Drawarea.cpp:636 (16)
    //         00442ae5     CMP        AL,0x1
    //         00442ae7     MOV        byte ptr [ESI + 0x478],AL
    //         00442aed     MOV        dword ptr [ESI + 0x30],this
    //         00442af0     MOV        dword ptr [ESI + 0x28],EDX
    //         00442af3     JNZ        LAB_00442b04
    //                              Drawarea.cpp:656 (2)
    //         00442af5     XOR        EAX,EAX
    //                              Drawarea.cpp:839 (13)
    //         00442af7     POP        EDI
    //         00442af8     POP        ESI
    //         00442af9     POP        EBP
    //         00442afa     POP        EBX
    //         00442afb     ADD        ESP,0x60c
    //         00442b01     RET        0x20
    //                               LAB_00442b04                                                 XREF[1]:     00442af3(j)  
    //                              Drawarea.cpp:666 (13)
    //         00442b04     XOR        EBX,EBX
    //         00442b06     LEA        EBP,[ESI + 0x18]
    //         00442b09     PUSH       EBX
    //         00442b0a     PUSH       EBP
    //         00442b0b     PUSH       EBX
    //         00442b0c     CALL       _DirectDrawCreate@12                             undefined _DirectDrawCreate@12()
    //                              Drawarea.cpp:669 (4)
    //         00442b11     CMP        EAX,EBX
    //         00442b13     JZ         LAB_00442b2b
    //                              Drawarea.cpp:672 (7)
    //         00442b15     MOV        dword ptr [ESI + 0x38],0x1
    //                              Drawarea.cpp:673 (2)
    //         00442b1c     XOR        EAX,EAX
    //                              Drawarea.cpp:839 (13)
    //         00442b1e     POP        EDI
    //         00442b1f     POP        ESI
    //         00442b20     POP        EBP
    //         00442b21     POP        EBX
    //         00442b22     ADD        ESP,0x60c
    //         00442b28     RET        0x20
    //                               LAB_00442b2b                                                 XREF[1]:     00442b13(j)  
    //                              Drawarea.cpp:677 (13)
    //         00442b2b     MOV        EDI,0x1
    //         00442b30     MOV        this,ESI
    //         00442b32     PUSH       EDI
    //         00442b33     CALL       TDrawSystem::CheckAvailModes                     void CheckAvailModes(TDrawSystem * this, int 
    //                              Drawarea.cpp:680 (8)
    //         00442b38     MOV        AL,byte ptr [ESI + 0x479]
    //         00442b3e     CMP        AL,0x1
    //                              Drawarea.cpp:684 (17)
    //         00442b40     MOV        EAX,dword ptr [EBP]
    //         00442b43     MOV        this,dword ptr [EAX]
    //         00442b45     JNZ        LAB_00442bc0
    //         00442b47     MOV        EDX,dword ptr [ESI + 0x4]
    //         00442b4a     PUSH       0x8
    //         00442b4c     PUSH       EDX
    //         00442b4d     PUSH       EAX
    //         00442b4e     CALL       dword ptr [ECX + this->ModeAvail800]
    //                              Drawarea.cpp:686 (4)
    //         00442b51     CMP        EAX,EBX
    //         00442b53     JZ         LAB_00442b67
    //                              Drawarea.cpp:688 (3)
    //         00442b55     MOV        dword ptr [ESI + 0x38],EDI
    //                              Drawarea.cpp:690 (2)
    //         00442b58     XOR        EAX,EAX
    //                              Drawarea.cpp:839 (13)
    //         00442b5a     POP        EDI
    //         00442b5b     POP        ESI
    //         00442b5c     POP        EBP
    //         00442b5d     POP        EBX
    //         00442b5e     ADD        ESP,0x60c
    //         00442b64     RET        0x20
    //                               LAB_00442b67                                                 XREF[1]:     00442b53(j)  
    //                              Drawarea.cpp:693 (13)
    //         00442b67     PUSH       0x6c
    //         00442b69     LEA        EAX,[ESP + 0x14]
    //         00442b6d     PUSH       EBX=>DAT_fffffff8
    //         00442b6e     PUSH       EAX=>DAT_fffffff4
    //         00442b6f     CALL       memset                                           undefined memset()
    //                              Drawarea.cpp:695 (25)
    //         00442b74     MOV        EAX,dword ptr [EBP]
    //         00442b77     ADD        ESP,0xc
    //         00442b7a     LEA        EDX,[ESP + 0x10]
    //         00442b7e     MOV        dword ptr [ESP + 0x10],0x6c
    //         00442b86     MOV        this,dword ptr [EAX]
    //         00442b88     PUSH       EDX
    //         00442b89     PUSH       EAX=>DAT_fffffff8
    //         00442b8a     CALL       dword ptr [ECX + this->ScreenHeight]
    //                              Drawarea.cpp:697 (4)
    //         00442b8d     CMP        EAX,EBX
    //         00442b8f     JZ         LAB_00442ba3
    //                              Drawarea.cpp:699 (3)
    //         00442b91     MOV        dword ptr [ESI + 0x38],EDI
    //                              Drawarea.cpp:701 (2)
    //         00442b94     XOR        EAX,EAX
    //                              Drawarea.cpp:839 (13)
    //         00442b96     POP        EDI
    //         00442b97     POP        ESI
    //         00442b98     POP        EBP
    //         00442b99     POP        EBX
    //         00442b9a     ADD        ESP,0x60c
    //         00442ba0     RET        0x20
    //                               LAB_00442ba3                                                 XREF[1]:     00442b8f(j)  
    //                              Drawarea.cpp:703 (7)
    //         00442ba3     CMP        dword ptr [ESP + 0x64],0x8
    //         00442ba8     JZ         LAB_00442c13
    //                              Drawarea.cpp:706 (7)
    //         00442baa     MOV        dword ptr [ESI + 0x38],0x2
    //                              Drawarea.cpp:707 (2)
    //         00442bb1     XOR        EAX,EAX
    //                              Drawarea.cpp:839 (13)
    //         00442bb3     POP        EDI
    //         00442bb4     POP        ESI
    //         00442bb5     POP        EBP
    //         00442bb6     POP        EBX
    //         00442bb7     ADD        ESP,0x60c
    //         00442bbd     RET        0x20
    //                               LAB_00442bc0                                                 XREF[1]:     00442b45(j)  
    //                              Drawarea.cpp:714 (10)
    //         00442bc0     MOV        EDX,dword ptr [ESI + 0x4]
    //         00442bc3     PUSH       0x11
    //         00442bc5     PUSH       EDX
    //         00442bc6     PUSH       EAX
    //         00442bc7     CALL       dword ptr [ECX + this->ModeAvail800]
    //                              Drawarea.cpp:716 (4)
    //         00442bca     CMP        EAX,EBX
    //         00442bcc     JZ         LAB_00442be0
    //                              Drawarea.cpp:718 (3)
    //         00442bce     MOV        dword ptr [ESI + 0x38],EDI
    //                              Drawarea.cpp:720 (2)
    //         00442bd1     XOR        EAX,EAX
    //                              Drawarea.cpp:839 (13)
    //         00442bd3     POP        EDI
    //         00442bd4     POP        ESI
    //         00442bd5     POP        EBP
    //         00442bd6     POP        EBX
    //         00442bd7     ADD        ESP,0x60c
    //         00442bdd     RET        0x20
    //                               LAB_00442be0                                                 XREF[1]:     00442bcc(j)  
    //                              Drawarea.cpp:725 (26)
    //         00442be0     MOV        EDX,dword ptr [ESI + 0x30]
    //         00442be3     MOV        EAX,dword ptr [EBP]
    //         00442be6     PUSH       0x8
    //         00442be8     PUSH       EDX=>DAT_fffffff8
    //         00442be9     MOV        EDX,dword ptr [ESI + 0x2c]
    //         00442bec     MOV        this,dword ptr [EAX]
    //         00442bee     PUSH       EDX=>DAT_fffffff4
    //         00442bef     PUSH       EAX=>DAT_fffffff0
    //         00442bf0     MOV        dword ptr [ESI + 0x34],0x8
    //         00442bf7     CALL       dword ptr [ECX + this->ModeAvail1024]
    //                              Drawarea.cpp:727 (4)
    //         00442bfa     CMP        EAX,EBX
    //         00442bfc     JZ         LAB_00442c10
    //                              Drawarea.cpp:731 (3)
    //         00442bfe     MOV        dword ptr [ESI + 0x38],EDI
    //                              Drawarea.cpp:732 (2)
    //         00442c01     XOR        EAX,EAX
    //                              Drawarea.cpp:839 (13)
    //         00442c03     POP        EDI
    //         00442c04     POP        ESI
    //         00442c05     POP        EBP
    //         00442c06     POP        EBX
    //         00442c07     ADD        ESP,0x60c
    //         00442c0d     RET        0x20
    //                               LAB_00442c10                                                 XREF[1]:     00442bfc(j)  
    //                              Drawarea.cpp:734 (3)
    //         00442c10     MOV        dword ptr [ESI + 0x3c],EDI
    //                               LAB_00442c13                                                 XREF[1]:     00442ba8(j)  
    //                              Drawarea.cpp:738 (7)
    //         00442c13     MOV        EAX,dword ptr [ESI + 0x8]
    //         00442c16     CMP        EAX,EBX
    //         00442c18     JZ         LAB_00442c31
    //                              Drawarea.cpp:739 (21)
    //         00442c1a     LEA        this,[ESP + 0x21c]
    //         00442c21     PUSH       this
    //         00442c22     PUSH       offset DAT_fffffff8
    //         00442c27     PUSH       EBX=>DAT_fffffff4
    //         00442c28     PUSH       EAX=>DAT_fffffff0
    //         00442c29     CALL       dword ptr [->GDI32.DLL::GetPaletteEntries]       = 0048b270
    //                              Drawarea.cpp:740 (2)
    //         00442c2f     JMP        LAB_00442c4e
    //                               LAB_00442c31                                                 XREF[1]:     00442c18(j)  
    //                              Drawarea.cpp:839 (29)
    //         00442c31     LEA        EAX,[ESP + 0x21d]
    //         00442c38     MOV        this,0x100
    //                               LAB_00442c3d                                                 XREF[1]:     00442c4c(j)  
    //         00442c3d     MOV        byte ptr [EAX + -0x1],BL
    //         00442c40     MOV        byte ptr [EAX],BL
    //         00442c42     MOV        byte ptr [EAX + 0x1],BL
    //         00442c45     MOV        byte ptr [EAX + 0x2],BL
    //         00442c48     ADD        EAX,0x4
    //         00442c4b     DEC        this
    //         00442c4c     JNZ        LAB_00442c3d
    //                               LAB_00442c4e                                                 XREF[1]:     00442c2f(j)  
    //                              Drawarea.cpp:751 (8)
    //         00442c4e     LEA        EAX,[ESI + 0x7a]
    //         00442c51     MOV        this,0x100
    //                               LAB_00442c56                                                 XREF[1]:     00442c65(j)  
    //                              Drawarea.cpp:753 (3)
    //         00442c56     MOV        byte ptr [EAX + -0x2],BL
    //                              Drawarea.cpp:754 (2)
    //         00442c59     MOV        byte ptr [EAX],BL
    //                              Drawarea.cpp:755 (3)
    //         00442c5b     MOV        byte ptr [EAX + -0x1],BL
    //                              Drawarea.cpp:756 (9)
    //         00442c5e     MOV        byte ptr [EAX + 0x1],BL
    //         00442c61     ADD        EAX,0x4
    //         00442c64     DEC        this
    //         00442c65     JNZ        LAB_00442c56
    //                              Drawarea.cpp:759 (24)
    //         00442c67     MOV        EAX,dword ptr [EBP]
    //         00442c6a     LEA        EDI,[ESI + 0x24]
    //         00442c6d     PUSH       EBX
    //         00442c6e     LEA        this,[ESP + 0x220]
    //         00442c75     MOV        EDX,dword ptr [EAX]
    //         00442c77     PUSH       EDI=>DAT_fffffff8
    //         00442c78     PUSH       this=>DAT_fffffff4
    //         00442c79     PUSH       offset DAT_fffffff0
    //         00442c7b     PUSH       EAX
    //         00442c7c     CALL       dword ptr [EDX + 0x14]
    //                              Drawarea.cpp:761 (4)
    //         00442c7f     CMP        EAX,EBX
    //         00442c81     JZ         LAB_00442c99
    //                              Drawarea.cpp:763 (7)
    //         00442c83     MOV        dword ptr [ESI + 0x38],0x1
    //                              Drawarea.cpp:765 (2)
    //         00442c8a     XOR        EAX,EAX
    //                              Drawarea.cpp:839 (13)
    //         00442c8c     POP        EDI
    //         00442c8d     POP        ESI
    //         00442c8e     POP        EBP
    //         00442c8f     POP        EBX
    //         00442c90     ADD        ESP,0x60c
    //         00442c96     RET        0x20
    //                               LAB_00442c99                                                 XREF[1]:     00442c81(j)  
    //                              Drawarea.cpp:768 (19)
    //         00442c99     MOV        EAX,dword ptr [EDI]
    //         00442c9b     LEA        this,[ESI + 0x78]
    //         00442c9e     PUSH       this
    //         00442c9f     PUSH       offset DAT_fffffff8
    //         00442ca4     MOV        EDX,dword ptr [EAX]
    //         00442ca6     PUSH       EBX=>DAT_fffffff4
    //         00442ca7     PUSH       EBX=>DAT_fffffff0
    //         00442ca8     PUSH       EAX
    //         00442ca9     CALL       dword ptr [EDX + 0x18]
    //                              Drawarea.cpp:773 (15)
    //         00442cac     MOV        EAX,dword ptr [EBP]
    //         00442caf     LEA        EDI,[ESI + 0x20]
    //         00442cb2     PUSH       EBX
    //         00442cb3     PUSH       EDI=>DAT_fffffff8
    //         00442cb4     MOV        EDX,dword ptr [EAX]
    //         00442cb6     PUSH       EBX=>DAT_fffffff4
    //         00442cb7     PUSH       EAX=>DAT_fffffff0
    //         00442cb8     CALL       dword ptr [EDX + 0x10]
    //                              Drawarea.cpp:775 (4)
    //         00442cbb     CMP        EAX,EBX
    //         00442cbd     JZ         LAB_00442cd5
    //                              Drawarea.cpp:777 (7)
    //         00442cbf     MOV        dword ptr [ESI + 0x38],0x1
    //                              Drawarea.cpp:779 (2)
    //         00442cc6     XOR        EAX,EAX
    //                              Drawarea.cpp:839 (13)
    //         00442cc8     POP        EDI
    //         00442cc9     POP        ESI
    //         00442cca     POP        EBP
    //         00442ccb     POP        EBX
    //         00442ccc     ADD        ESP,0x60c
    //         00442cd2     RET        0x20
    //                               LAB_00442cd5                                                 XREF[1]:     00442cbd(j)  
    //                              Drawarea.cpp:782 (13)
    //         00442cd5     MOV        EDI,dword ptr [EDI]
    //         00442cd7     MOV        this,dword ptr [ESI + 0x4]
    //         00442cda     PUSH       this
    //         00442cdb     PUSH       EBX=>DAT_fffffff8
    //         00442cdc     MOV        EAX,dword ptr [EDI]
    //         00442cde     PUSH       EDI=>DAT_fffffff4
    //         00442cdf     CALL       dword ptr [EAX + 0x20]
    //                              Drawarea.cpp:784 (4)
    //         00442ce2     CMP        EAX,EBX
    //         00442ce4     JZ         LAB_00442cfc
    //                              Drawarea.cpp:786 (7)
    //         00442ce6     MOV        dword ptr [ESI + 0x38],0x1
    //                              Drawarea.cpp:788 (2)
    //         00442ced     XOR        EAX,EAX
    //                              Drawarea.cpp:839 (13)
    //         00442cef     POP        EDI
    //         00442cf0     POP        ESI
    //         00442cf1     POP        EBP
    //         00442cf2     POP        EBX
    //         00442cf3     ADD        ESP,0x60c
    //         00442cf9     RET        0x20
    //                               LAB_00442cfc                                                 XREF[1]:     00442ce4(j)  
    //                              Drawarea.cpp:792 (11)
    //         00442cfc     MOV        this,ESI
    //         00442cfe     CALL       TDrawSystem::CreateSurfaces                      int CreateSurfaces(TDrawSystem * this)
    //         00442d03     TEST       EAX,EAX
    //         00442d05     JNZ        LAB_00442d1b
    //                              Drawarea.cpp:794 (7)
    //         00442d07     MOV        dword ptr [ESI + 0x38],0x1
    //                              Drawarea.cpp:839 (13)
    //         00442d0e     POP        EDI
    //         00442d0f     POP        ESI
    //         00442d10     POP        EBP
    //         00442d11     POP        EBX
    //         00442d12     ADD        ESP,0x60c
    //         00442d18     RET        0x20
    //                               LAB_00442d1b                                                 XREF[1]:     00442d05(j)  
    //                              Drawarea.cpp:804 (33)
    //         00442d1b     MOV        EBP,dword ptr [EBP]
    //         00442d1e     LEA        EAX,[ESP + 0xe0]
    //         00442d25     PUSH       EBX
    //         00442d26     PUSH       EAX=>DAT_fffffff8
    //         00442d27     MOV        EDX,dword ptr [EBP]
    //         00442d2a     PUSH       EBP=>DAT_fffffff4
    //         00442d2b     MOV        dword ptr [ESI + 0x40],EBX
    //         00442d2e     MOV        dword ptr [ESP + 0xec],0x13c
    //         00442d39     CALL       dword ptr [EDX + 0x2c]
    //                              Drawarea.cpp:807 (4)
    //         00442d3c     CMP        EAX,EBX
    //         00442d3e     JNZ        LAB_00442d6f
    //                              Drawarea.cpp:809 (14)
    //         00442d40     MOV        EAX,dword ptr [ESP + 0xe4]
    //         00442d47     TEST       EAX,0x8000000
    //         00442d4c     JZ         LAB_00442d55
    //                              Drawarea.cpp:811 (7)
    //         00442d4e     MOV        dword ptr [ESI + 0x40],0x1
    //                               LAB_00442d55                                                 XREF[1]:     00442d4c(j)  
    //                              Drawarea.cpp:817 (7)
    //         00442d55     TEST       EAX,IMAGE_DOS_HEADER_00400000
    //         00442d5a     JZ         LAB_00442d6f
    //                              Drawarea.cpp:819 (12)
    //         00442d5c     MOV        EAX,dword ptr [ESP + 0xec]
    //         00442d63     TEST       AH,0x2
    //         00442d66     JZ         LAB_00442d6f
    //                              Drawarea.cpp:821 (7)
    //         00442d68     MOV        dword ptr [ESI + 0x44],0x1
    //                               LAB_00442d6f                                                 XREF[3]:     00442d3e(j), 00442d5a(j), 
    //                                                                                                         00442d66(j)  
    //                              Drawarea.cpp:828 (9)
    //         00442d6f     CMP        byte ptr [ESI + 0x479],0x2
    //         00442d76     JNZ        LAB_00442da0
    //                              Drawarea.cpp:833 (40)
    //         00442d78     MOV        ESI,dword ptr [ESI + 0x1c]
    //         00442d7b     LEA        EDX,[ESP + 0x7c]
    //         00442d7f     PUSH       EDX
    //         00442d80     PUSH       offset DAT_fffffff8
    //         00442d85     MOV        this,dword ptr [ESI]
    //         00442d87     PUSH       EBX=>DAT_fffffff4
    //         00442d88     PUSH       EBX=>DAT_fffffff0
    //         00442d89     PUSH       EBX
    //         00442d8a     PUSH       ESI
    //         00442d8b     MOV        dword ptr [ESP + 0x94],0x64
    //         00442d96     MOV        dword ptr [ESP + 0xe4],EBX
    //         00442d9d     CALL       dword ptr [ECX + this->DrawAreaList]
    //                               LAB_00442da0                                                 XREF[1]:     00442d76(j)  
    //                              Drawarea.cpp:839 (18)
    //         00442da0     POP        EDI
    //         00442da1     POP        ESI
    //         00442da2     POP        EBP
    //         00442da3     MOV        EAX,0x1
    //         00442da8     POP        EBX
    //         00442da9     ADD        ESP,0x60c
    //         00442daf     RET        0x20
}

// Offset: 0x00442DC0
int SetDisplaySize(TDrawSystem* this_, long param_2, long param_3, int param_4) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall TDrawSystem::SetDisplaySize(long,long,int)                                     *
    //                              *********************************************************************************************************
    //                              int __thiscall SetDisplaySize(TDrawSystem * this, long param_1, long
    //              int               EAX:4          <RETURN>
    //              TDrawSystem *     ECX:4 (auto)   this
    //              long              Stack[0x4]:4   param_1
    //              long              Stack[0x8]:4   param_2
    //              int               Stack[0xc]:4   param_3
    //              _DDBLTFX          Stack[-0x68]   ddbltfx                   XREF[0,3]:   00442de3(*), 00442e03(W), 00442e0b(W)  
    //              long              Stack[-0x6c]:4 save_hgt
    //              long              Stack[-0x70]:4 save_wid
    //                               ?SetDisplaySize@TDrawSystem@@QAEHJJH@Z                       XREF[4]:     set_screen_size:00422b6f(c), 
    //                               TDrawSystem::SetDisplaySize                                               setup_video_system:0052a342(c), 
    //                                                                                                         setup_video_system:0052a3bd(c), 
    //                                                                                                         shutdown_video_system:0052a45f(c)  
    //                              Drawarea.cpp:845 (3)
    //         00442dc0     SUB        ESP,0x6c
    //                              Drawarea.cpp:852 (32)
    //         00442dc3     MOV        AL,0x2
    //         00442dc5     PUSH       EBX
    //         00442dc6     PUSH       EBP
    //         00442dc7     PUSH       ESI
    //         00442dc8     MOV        ESI,this
    //         00442dca     PUSH       EDI
    //         00442dcb     CMP        byte ptr [ESI + 0x478],AL
    //         00442dd1     JNZ        LAB_00442ee0
    //         00442dd7     CMP        byte ptr [ESI + 0x479],AL
    //         00442ddd     JNZ        LAB_00442ee0
    //                              Drawarea.cpp:864 (54)
    //         00442de3     LEA        EDX=>ddbltfx.dwDDFX,[ESP + 0x18]
    //         00442de7     MOV        dword ptr [system_ignore_size_messages],0x1
    //         00442df1     MOV        EAX,dword ptr [ESI + 0x1c]
    //         00442df4     PUSH       EDX
    //         00442df5     PUSH       0x1000400
    //         00442dfa     PUSH       0x0
    //         00442dfc     MOV        this,dword ptr [EAX]
    //         00442dfe     PUSH       0x0
    //         00442e00     PUSH       0x0
    //         00442e02     PUSH       EAX
    //         00442e03     MOV        dword ptr [ESP + ddbltfx.dwDDFX],0x64
    //         00442e0b     MOV        dword ptr [ESP + ddbltfx.ddckDestColorkey.dwCo
    //         00442e16     CALL       dword ptr [ECX + this->DrawAreaList]
    //                              Drawarea.cpp:868 (3)
    //         00442e19     MOV        EAX,dword ptr [ESI + 0x2c]
    //                              Drawarea.cpp:874 (50)
    //         00442e1c     MOV        EBP,dword ptr [ESP + 0x88]
    //         00442e23     MOV        EDI,dword ptr [ESP + 0x84]
    //         00442e2a     MOV        EBX,dword ptr [ESP + 0x80]
    //         00442e31     MOV        this,dword ptr [ESI + 0x30]
    //         00442e34     MOV        dword ptr [ESP + 0x10],EAX
    //         00442e38     MOV        EAX,dword ptr [ESI + 0x18]
    //         00442e3b     PUSH       EBP
    //         00442e3c     PUSH       EDI=>DAT_fffffff8
    //         00442e3d     PUSH       EBX=>DAT_fffffff4
    //         00442e3e     MOV        EDX,dword ptr [EAX]
    //         00442e40     PUSH       EAX=>DAT_fffffff0
    //         00442e41     MOV        dword ptr [ESP + 0x24],this
    //         00442e45     MOV        dword ptr [ESI + 0x2c],EBX
    //         00442e48     MOV        dword ptr [ESI + 0x30],EDI
    //         00442e4b     CALL       dword ptr [EDX + 0x54]
    //                              Drawarea.cpp:879 (14)
    //         00442e4e     TEST       EAX,EAX
    //         00442e50     MOV        dword ptr [system_ignore_size_messages],0x0
    //         00442e5a     JZ         LAB_00442e76
    //                              Drawarea.cpp:881 (4)
    //         00442e5c     MOV        EAX,dword ptr [ESP + 0x10]
    //                              Drawarea.cpp:882 (12)
    //         00442e60     MOV        this,dword ptr [ESP + 0x14]
    //         00442e64     MOV        dword ptr [ESI + 0x2c],EAX
    //         00442e67     MOV        dword ptr [ESI + 0x30],this
    //         00442e6a     XOR        EAX,EAX
    //                              Drawarea.cpp:906 (10)
    //         00442e6c     POP        EDI
    //         00442e6d     POP        ESI
    //         00442e6e     POP        EBP
    //         00442e6f     POP        EBX
    //         00442e70     ADD        ESP,0x6c
    //         00442e73     RET        0xc
    //                               LAB_00442e76                                                 XREF[1]:     00442e5a(j)  
    //                              Drawarea.cpp:891 (17)
    //         00442e76     MOV        EAX,dword ptr [ESI + 0x1c]
    //         00442e79     MOV        dword ptr [ESI + 0x34],EBP
    //         00442e7c     TEST       EAX,EAX
    //         00442e7e     MOV        dword ptr [ESI + 0x3c],0x1
    //         00442e85     JZ         LAB_00442e94
    //                              Drawarea.cpp:893 (6)
    //         00442e87     MOV        EDX,dword ptr [EAX]
    //         00442e89     PUSH       EAX
    //         00442e8a     CALL       dword ptr [EDX + 0x8]
    //                              Drawarea.cpp:895 (7)
    //         00442e8d     MOV        dword ptr [ESI + 0x1c],0x0
    //                               LAB_00442e94                                                 XREF[1]:     00442e85(j)  
    //                              Drawarea.cpp:898 (7)
    //         00442e94     MOV        this,ESI
    //         00442e96     CALL       TDrawSystem::CreateSurfaces                      int CreateSurfaces(TDrawSystem * this)
    //                              Drawarea.cpp:900 (7)
    //         00442e9b     MOV        this,dword ptr [ESI + 0xc]
    //         00442e9e     TEST       this,this
    //         00442ea0     JZ         LAB_00442eb1
    //                              Drawarea.cpp:901 (15)
    //         00442ea2     MOV        EAX,dword ptr [ESI + 0x30]
    //         00442ea5     MOV        EDX,dword ptr [ESI + 0x2c]
    //         00442ea8     PUSH       0x0
    //         00442eaa     PUSH       EAX=>DAT_fffffff8
    //         00442eab     PUSH       EDX=>DAT_fffffff4
    //         00442eac     CALL       TDrawArea::SetSize                               void SetSize(TDrawArea * this, long param_1, 
    //                               LAB_00442eb1                                                 XREF[1]:     00442ea0(j)  
    //                              Drawarea.cpp:903 (32)
    //         00442eb1     MOV        EAX,dword ptr [ESI + 0x4]
    //         00442eb4     AND        EDI,0xffff
    //         00442eba     SHL        EDI,0x10
    //         00442ebd     AND        EBX,0xffff
    //         00442ec3     OR         EDI,EBX
    //         00442ec5     PUSH       EDI
    //         00442ec6     PUSH       0x0=>DAT_fffffff8
    //         00442ec8     PUSH       offset DAT_fffffff4
    //         00442eca     PUSH       EAX=>DAT_fffffff0
    //         00442ecb     CALL       dword ptr [->USER32.DLL::SendMessageA]           = 0048ad08
    //                              Drawarea.cpp:905 (5)
    //         00442ed1     MOV        EAX,0x1
    //                              Drawarea.cpp:906 (22)
    //         00442ed6     POP        EDI
    //         00442ed7     POP        ESI
    //         00442ed8     POP        EBP
    //         00442ed9     POP        EBX
    //         00442eda     ADD        ESP,0x6c
    //         00442edd     RET        0xc
    //                               LAB_00442ee0                                                 XREF[2]:     00442dd1(j), 00442ddd(j)  
    //         00442ee0     POP        EDI
    //         00442ee1     POP        ESI
    //         00442ee2     POP        EBP
    //         00442ee3     XOR        EAX,EAX
    //         00442ee5     POP        EBX
    //         00442ee6     ADD        ESP,0x6c
    //         00442ee9     RET        0xc
}

// Offset: 0x00442EF0
void ClearPrimarySurface(TDrawSystem* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TDrawSystem::ClearPrimarySurface(void)                                        *
    //                              *********************************************************************************************************
    //                              void __thiscall ClearPrimarySurface(TDrawSystem * this)
    //              void              <VOID>         <RETURN>
    //              TDrawSystem *     ECX:4 (auto)   this
    //              _DDBLTFX          Stack[-0x68]   ddbltfx                   XREF[0,3]:   00442f06(*), 00442f17(W), 00442f1f(W)  
    //                               ?ClearPrimarySurface@TDrawSystem@@QAEXXZ                     XREF[6]:     wnd_proc:004209eb(c), 
    //                               TDrawSystem::ClearPrimarySurface                                          start_video:00523a56(c), 
    //                                                                                                         stop_video:00523bd0(c), 
    //                                                                                                         stop_video:00523c05(c), 
    //                                                                                                         shutdown_video_system:0052a467(c), 
    //                                                                                                         shutdown_video_system:0052a4a9(c)  
    //                              Drawarea.cpp:912 (20)
    //         00442ef0     MOV        AL,byte ptr [ECX + this->ScreenMode]
    //         00442ef6     SUB        ESP,0x64
    //         00442ef9     CMP        AL,0x2
    //         00442efb     JNZ        LAB_00442f2a
    //         00442efd     MOV        EAX,dword ptr [ECX + this->PrimarySurface]
    //         00442f00     TEST       EAX,EAX
    //         00442f02     JZ         LAB_00442f2a
    //                              Drawarea.cpp:918 (38)
    //         00442f04     MOV        this,dword ptr [EAX]
    //         00442f06     LEA        EDX=>ddbltfx.dwDDFX,[ESP]
    //         00442f0a     PUSH       EDX
    //         00442f0b     PUSH       0x1000400
    //         00442f10     PUSH       0x0
    //         00442f12     PUSH       0x0
    //         00442f14     PUSH       0x0
    //         00442f16     PUSH       EAX
    //         00442f17     MOV        dword ptr [ESP + ddbltfx.dwDDFX],0x64
    //         00442f1f     MOV        dword ptr [ESP + ddbltfx.ddckDestColorkey.dwCo
    //         00442f27     CALL       dword ptr [ECX + this->DrawAreaList]
    //                               LAB_00442f2a                                                 XREF[2]:     00442efb(j), 00442f02(j)  
    //                              Drawarea.cpp:921 (4)
    //         00442f2a     ADD        ESP,0x64
    //         00442f2d     RET
}

// Offset: 0x00442F30
uchar CheckSurfaces(TDrawSystem* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: unsigned char __thiscall TDrawSystem::CheckSurfaces(void)                                     *
    //                              *********************************************************************************************************
    //                              uchar __thiscall CheckSurfaces(TDrawSystem * this)
    //              uchar             AL:1           <RETURN>
    //              TDrawSystem *     ECX:4 (auto)   this
    //              _DDBLTFX          Stack[-0x68]   ddbltfx
    //              _DDSURFACEDESC    Stack[-0xd4]   ddsd
    //                               ?CheckSurfaces@TDrawSystem@@QAEEXZ                           XREF[4]:     check_paint:0041ffa5(c), 
    //                               TDrawSystem::CheckSurfaces                                                wnd_proc:004209c3(c), 
    //                                                                                                         set_screen_size:00422b77(c), 
    //                                                                                                         shutdown_video_system:0052a488(c)  
    //                              Drawarea.cpp:927 (11)
    //         00442f30     SUB        ESP,0xd0
    //         00442f36     PUSH       EBX
    //         00442f37     PUSH       ESI
    //         00442f38     MOV        ESI,this
    //         00442f3a     PUSH       EDI
    //                              Drawarea.cpp:936 (9)
    //         00442f3b     CMP        byte ptr [ESI + 0x478],0x2
    //         00442f42     JZ         LAB_00442f50
    //                              Drawarea.cpp:937 (2)
    //         00442f44     XOR        AL,AL
    //                              Drawarea.cpp:1012 (10)
    //         00442f46     POP        EDI
    //         00442f47     POP        ESI
    //         00442f48     POP        EBX
    //         00442f49     ADD        ESP,0xd0
    //         00442f4f     RET
    //                               LAB_00442f50                                                 XREF[1]:     00442f42(j)  
    //                              Drawarea.cpp:939 (33)
    //         00442f50     MOV        EAX,dword ptr [ESI + 0x1c]
    //         00442f53     TEST       EAX,EAX
    //         00442f55     JZ         LAB_00443062
    //         00442f5b     MOV        this,dword ptr [ESI + 0xc]
    //         00442f5e     TEST       this,this
    //         00442f60     JZ         LAB_00443062
    //         00442f66     MOV        EDX,dword ptr [ECX + this->ChangedMode]
    //         00442f69     TEST       EDX,EDX
    //         00442f6b     JZ         LAB_00443062
    //                              Drawarea.cpp:944 (8)
    //         00442f71     MOV        this,dword ptr [EAX]
    //         00442f73     PUSH       EAX
    //         00442f74     XOR        BL,BL
    //         00442f76     CALL       dword ptr [ECX + this->ModeAvail320_240]
    //                              Drawarea.cpp:946 (8)
    //         00442f79     TEST       EAX,EAX
    //         00442f7b     JZ         LAB_00443036
    //                              Drawarea.cpp:948 (8)
    //         00442f81     PUSH       EAX
    //         00442f82     MOV        this,ESI
    //         00442f84     CALL       TDrawSystem::GetIsLostErrorNum                   int GetIsLostErrorNum(TDrawSystem * this, lon
    //                              Drawarea.cpp:953 (14)
    //         00442f89     PUSH       0x6c
    //         00442f8b     LEA        EDX,[ESP + 0x10]
    //         00442f8f     PUSH       0x0=>DAT_fffffff8
    //         00442f91     PUSH       EDX=>DAT_fffffff4
    //         00442f92     CALL       memset                                           undefined memset()
    //                              Drawarea.cpp:955 (25)
    //         00442f97     MOV        EAX,dword ptr [ESI + 0x18]
    //         00442f9a     ADD        ESP,0xc
    //         00442f9d     LEA        EDX,[ESP + 0xc]
    //         00442fa1     MOV        dword ptr [ESP + 0xc],0x6c
    //         00442fa9     MOV        this,dword ptr [EAX]
    //         00442fab     PUSH       EDX
    //         00442fac     PUSH       EAX=>DAT_fffffff8
    //         00442fad     CALL       dword ptr [ECX + this->ScreenHeight]
    //                              Drawarea.cpp:958 (4)
    //         00442fb0     TEST       EAX,EAX
    //         00442fb2     JNZ        LAB_00442fdd
    //                              Drawarea.cpp:960 (29)
    //         00442fb4     MOV        EAX,dword ptr [ESP + 0x18]
    //         00442fb8     MOV        this,dword ptr [ESI + 0x2c]
    //         00442fbb     CMP        EAX,this
    //         00442fbd     JNZ        LAB_00442fd1
    //         00442fbf     MOV        this,dword ptr [ESP + 0x14]
    //         00442fc3     MOV        EAX,dword ptr [ESI + 0x30]
    //         00442fc6     CMP        this,EAX
    //         00442fc8     JNZ        LAB_00442fd1
    //         00442fca     CMP        dword ptr [ESP + 0x60],0x8
    //         00442fcf     JZ         LAB_00442fdd
    //                               LAB_00442fd1                                                 XREF[2]:     00442fbd(j), 00442fc8(j)  
    //                              Drawarea.cpp:961 (2)
    //         00442fd1     MOV        AL,0x1
    //                              Drawarea.cpp:1012 (10)
    //         00442fd3     POP        EDI
    //         00442fd4     POP        ESI
    //         00442fd5     POP        EBX
    //         00442fd6     ADD        ESP,0xd0
    //         00442fdc     RET
    //                               LAB_00442fdd                                                 XREF[2]:     00442fb2(j), 00442fcf(j)  
    //                              Drawarea.cpp:968 (9)
    //         00442fdd     MOV        EAX,dword ptr [ESI + 0x1c]
    //         00442fe0     PUSH       EAX
    //         00442fe1     MOV        EDX,dword ptr [EAX]
    //         00442fe3     CALL       dword ptr [EDX + 0x6c]
    //                              Drawarea.cpp:970 (4)
    //         00442fe6     TEST       EAX,EAX
    //         00442fe8     JZ         LAB_00442ffe
    //                              Drawarea.cpp:972 (10)
    //         00442fea     PUSH       EAX
    //         00442feb     MOV        this,ESI
    //         00442fed     CALL       TDrawSystem::GetRestoreErrorNum                  int GetRestoreErrorNum(TDrawSystem * this, lo
    //         00442ff2     MOV        AL,0x3
    //                              Drawarea.cpp:1012 (10)
    //         00442ff4     POP        EDI
    //         00442ff5     POP        ESI
    //         00442ff6     POP        EBX
    //         00442ff7     ADD        ESP,0xd0
    //         00442ffd     RET
    //                               LAB_00442ffe                                                 XREF[1]:     00442fe8(j)  
    //                              Drawarea.cpp:987 (56)
    //         00442ffe     MOV        EAX,dword ptr [ESI + 0x1c]
    //         00443001     LEA        EDX,[ESP + 0x78]
    //         00443005     PUSH       EDX
    //         00443006     PUSH       offset DAT_fffffff8
    //         0044300b     MOV        this,dword ptr [EAX]
    //         0044300d     PUSH       0x0=>DAT_fffffff4
    //         0044300f     PUSH       0x0=>DAT_fffffff0
    //         00443011     PUSH       0x0
    //         00443013     PUSH       EAX
    //         00443014     MOV        dword ptr [ESI + 0x48],0x1
    //         0044301b     MOV        BL,0x2
    //         0044301d     MOV        dword ptr [ESP + 0x90],0x64
    //         00443028     MOV        dword ptr [ESP + 0xe0],0x0
    //         00443033     CALL       dword ptr [ECX + this->DrawAreaList]
    //                               LAB_00443036                                                 XREF[1]:     00442f7b(j)  
    //                              Drawarea.cpp:993 (3)
    //         00443036     MOV        EDI,dword ptr [ESI + 0x14]
    //                              Drawarea.cpp:994 (4)
    //         00443039     TEST       EDI,EDI
    //         0044303b     JZ         LAB_00443056
    //                               LAB_0044303d                                                 XREF[1]:     00443054(j)  
    //                              Drawarea.cpp:996 (9)
    //         0044303d     MOV        this,dword ptr [EDI]
    //         0044303f     MOV        EAX,dword ptr [ESI + 0x10]
    //         00443042     CMP        this,EAX
    //         00443044     JZ         LAB_0044304f
    //                              Drawarea.cpp:998 (5)
    //         00443046     CALL       TDrawArea::CheckSurface                          uchar CheckSurface(TDrawArea * this)
    //                              Drawarea.cpp:999 (4)
    //         0044304b     CMP        AL,0x3
    //         0044304d     JZ         LAB_00443062
    //                               LAB_0044304f                                                 XREF[1]:     00443044(j)  
    //                              Drawarea.cpp:1007 (7)
    //         0044304f     MOV        EDI,dword ptr [EDI + 0x8]
    //         00443052     TEST       EDI,EDI
    //         00443054     JNZ        LAB_0044303d
    //                               LAB_00443056                                                 XREF[1]:     0044303b(j)  
    //                              Drawarea.cpp:1011 (2)
    //         00443056     MOV        AL,BL
    //                              Drawarea.cpp:1012 (22)
    //         00443058     POP        EDI
    //         00443059     POP        ESI
    //         0044305a     POP        EBX
    //         0044305b     ADD        ESP,0xd0
    //         00443061     RET
    //                               LAB_00443062                                                 XREF[4]:     00442f55(j), 00442f60(j), 
    //                                                                                                         00442f6b(j), 0044304d(j)  
    //         00443062     POP        EDI
    //         00443063     POP        ESI
    //         00443064     MOV        AL,0x3
    //         00443066     POP        EBX
    //         00443067     ADD        ESP,0xd0
    //         0044306d     RET
}

// Offset: 0x00443070
void ClearRestored(TDrawSystem* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TDrawSystem::ClearRestored(void)                                              *
    //                              *********************************************************************************************************
    //                              void __thiscall ClearRestored(TDrawSystem * this)
    //              void              <VOID>         <RETURN>
    //              TDrawSystem *     ECX:4 (auto)   this
    //                               ?ClearRestored@TDrawSystem@@QAEXXZ                           XREF[4]:     check_paint:0041ffe0(c), 
    //                               TDrawSystem::ClearRestored                                                wnd_proc:004209cb(c), 
    //                                                                                                         set_screen_size:00422b7f(c), 
    //                                                                                                         shutdown_video_system:0052a490(c)  
    //                              Drawarea.cpp:1018 (5)
    //         00443070     MOV        EAX,dword ptr [ECX + this->DrawAreaList]
    //         00443073     XOR        EDX,EDX
    //                              Drawarea.cpp:1026 (7)
    //         00443075     CMP        EAX,EDX
    //         00443077     MOV        dword ptr [ECX + this->Restored],EDX
    //         0044307a     JZ         LAB_0044308b
    //                               LAB_0044307c                                                 XREF[1]:     00443089(j)  
    //                              Drawarea.cpp:1028 (8)
    //         0044307c     MOV        this,dword ptr [EAX]
    //         0044307e     MOV        dword ptr [ECX + this+0xf4],EDX
    //                              Drawarea.cpp:1029 (7)
    //         00443084     MOV        EAX,dword ptr [EAX + 0x8]
    //         00443087     CMP        EAX,EDX
    //         00443089     JNZ        LAB_0044307c
    //                               LAB_0044308b                                                 XREF[1]:     0044307a(j)  
    //                              Drawarea.cpp:1031 (1)
    //         0044308b     RET
}

// Offset: 0x00443090
void DeleteSurfaces(TDrawSystem* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TDrawSystem::DeleteSurfaces(void)                                             *
    //                              *********************************************************************************************************
    //                              void __thiscall DeleteSurfaces(TDrawSystem * this)
    //              void              <VOID>         <RETURN>
    //              TDrawSystem *     ECX:4 (auto)   this
    //                               ?DeleteSurfaces@TDrawSystem@@QAEXXZ                          XREF[1]:     ~TDrawSystem:0044274a(c)  
    //                               TDrawSystem::DeleteSurfaces
    //                              Drawarea.cpp:1037 (4)
    //         00443090     PUSH       ESI
    //         00443091     MOV        ESI,this
    //         00443093     PUSH       EDI
    //                              Drawarea.cpp:1042 (7)
    //         00443094     MOV        EDI,dword ptr [ESI + 0xc]
    //         00443097     TEST       EDI,EDI
    //         00443099     JZ         LAB_004430b2
    //                              Drawarea.cpp:1044 (16)
    //         0044309b     MOV        this,EDI
    //         0044309d     CALL       TDrawArea::~TDrawArea                            void ~TDrawArea(TDrawArea * this)
    //         004430a2     PUSH       EDI
    //         004430a3     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         004430a8     ADD        ESP,0x4
    //                              Drawarea.cpp:1045 (7)
    //         004430ab     MOV        dword ptr [ESI + 0xc],0x0
    //                               LAB_004430b2                                                 XREF[1]:     00443099(j)  
    //                              Drawarea.cpp:1048 (7)
    //         004430b2     MOV        EAX,dword ptr [ESI + 0x1c]
    //         004430b5     TEST       EAX,EAX
    //         004430b7     JZ         LAB_004430e7
    //                              Drawarea.cpp:1050 (23)
    //         004430b9     MOV        EDI,dword ptr [ESI + 0x10]
    //         004430bc     TEST       EDI,EDI
    //         004430be     JZ         LAB_004430d0
    //         004430c0     MOV        this,EDI
    //         004430c2     CALL       TDrawArea::~TDrawArea                            void ~TDrawArea(TDrawArea * this)
    //         004430c7     PUSH       EDI
    //         004430c8     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         004430cd     ADD        ESP,0x4
    //                               LAB_004430d0                                                 XREF[1]:     004430be(j)  
    //                              Drawarea.cpp:1052 (16)
    //         004430d0     MOV        EAX,dword ptr [ESI + 0x1c]
    //         004430d3     MOV        dword ptr [ESI + 0x10],0x0
    //         004430da     PUSH       EAX
    //         004430db     MOV        this,dword ptr [EAX]
    //         004430dd     CALL       dword ptr [ECX + this->Pal]
    //                              Drawarea.cpp:1054 (7)
    //         004430e0     MOV        dword ptr [ESI + 0x1c],0x0
    //                               LAB_004430e7                                                 XREF[1]:     004430b7(j)  
    //                              Drawarea.cpp:1056 (3)
    //         004430e7     POP        EDI
    //         004430e8     POP        ESI
    //         004430e9     RET
}

// Offset: 0x004430F0
int CreateSurfaces(TDrawSystem* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall TDrawSystem::CreateSurfaces(void)                                              *
    //                              *********************************************************************************************************
    //                              int __thiscall CreateSurfaces(TDrawSystem * this)
    //              int               EAX:4          <RETURN>
    //              TDrawSystem *     ECX:4 (auto)   this
    //              _DDBLTFX          Stack[-0x74]   ddbltfx                   XREF[1]:     00443159(W)  
    //              _DDSURFACEDESC    Stack[-0xe0]   ddsd                      XREF[0,4]:   0044312c(*), 0044313e(*), 00443142(W), 00443151(W)  
    //              tagRECT           Stack[-0xf0]   wnd_rect
    //                               ?CreateSurfaces@TDrawSystem@@QAEHXZ                          XREF[2]:     Init:00442cfe(c), 
    //                               TDrawSystem::CreateSurfaces                                               SetDisplaySize:00442e96(c)  
    //                              Drawarea.cpp:1062 (31)
    //         004430f0     MOV        EAX,FS:[0x0]
    //         004430f6     PUSH       -0x1
    //         004430f8     PUSH       FUN_0055d2ec
    //         004430fd     PUSH       EAX
    //         004430fe     MOV        dword ptr FS:[0x0],ESP
    //         00443105     SUB        ESP,0xe4
    //         0044310b     PUSH       ESI
    //         0044310c     MOV        ESI,this
    //         0044310e     PUSH       EDI
    //                              Drawarea.cpp:1069 (13)
    //         0044310f     CMP        byte ptr [ESI + 0x478],0x2
    //         00443116     JNZ        LAB_004432f5
    //                              Drawarea.cpp:1072 (14)
    //         0044311c     MOV        EAX,dword ptr [ESI + 0x1c]
    //         0044311f     LEA        EDI,[ESI + 0x1c]
    //         00443122     TEST       EAX,EAX
    //         00443124     JNZ        LAB_00443216
    //                              Drawarea.cpp:1074 (14)
    //         0044312a     PUSH       0x6c
    //         0044312c     LEA        EAX=>ddsd.dwFlags,[ESP + 0x20]
    //         00443130     PUSH       0x0
    //         00443132     PUSH       EAX
    //         00443133     CALL       memset                                           undefined memset()
    //                              Drawarea.cpp:1078 (47)
    //         00443138     MOV        EAX,dword ptr [ESI + 0x18]
    //         0044313b     ADD        ESP,0xc
    //         0044313e     LEA        EDX=>ddsd.dwFlags,[ESP + 0x1c]
    //         00443142     MOV        dword ptr [ESP + ddsd.dwFlags],0x6c
    //         0044314a     MOV        this,dword ptr [EAX]
    //         0044314c     PUSH       0x0
    //         0044314e     PUSH       EDI
    //         0044314f     PUSH       EDX
    //         00443150     PUSH       EAX
    //         00443151     MOV        dword ptr [ESP + ddsd.dwHeight],0x1
    //         00443159     MOV        dword ptr [ESP + ddbltfx.dwSize],0x200
    //         00443164     CALL       dword ptr [ECX + this->DirDraw]
    //                              Drawarea.cpp:1081 (4)
    //         00443167     TEST       EAX,EAX
    //         00443169     JZ         LAB_00443184
    //                              Drawarea.cpp:1082 (2)
    //         0044316b     XOR        EAX,EAX
    //                              Drawarea.cpp:1149 (23)
    //         0044316d     MOV        this,dword ptr [ESP + 0xec]
    //         00443174     MOV        dword ptr FS:[0x0],this
    //         0044317b     POP        EDI
    //         0044317c     POP        ESI
    //         0044317d     ADD        ESP,0xf0
    //         00443183     RET
    //                               LAB_00443184                                                 XREF[1]:     00443169(j)  
    //                              Drawarea.cpp:1085 (9)
    //         00443184     CMP        byte ptr [ESI + 0x479],0x2
    //         0044318b     JNZ        LAB_004431be
    //                              Drawarea.cpp:1090 (49)
    //         0044318d     MOV        EAX,dword ptr [EDI]
    //         0044318f     LEA        EDX,[ESP + 0x88]
    //         00443196     PUSH       EDX
    //         00443197     PUSH       offset DAT_fffffff8
    //         0044319c     MOV        this,dword ptr [EAX]
    //         0044319e     PUSH       0x0=>DAT_fffffff4
    //         004431a0     PUSH       0x0=>DAT_fffffff0
    //         004431a2     PUSH       0x0
    //         004431a4     PUSH       EAX
    //         004431a5     MOV        dword ptr [ESP + 0xa0],0x64
    //         004431b0     MOV        dword ptr [ESP + 0xf0],0x0
    //         004431bb     CALL       dword ptr [ECX + this->DrawAreaList]
    //                               LAB_004431be                                                 XREF[1]:     0044318b(j)  
    //                              Drawarea.cpp:1094 (6)
    //         004431be     CMP        dword ptr [ESI + 0x34],0x8
    //         004431c2     JNZ        LAB_004431ed
    //                              Drawarea.cpp:1096 (12)
    //         004431c4     MOV        EAX,dword ptr [EDI]
    //         004431c6     MOV        EDX,dword ptr [ESI + 0x24]
    //         004431c9     PUSH       EDX
    //         004431ca     PUSH       EAX=>DAT_fffffff8
    //         004431cb     MOV        this,dword ptr [EAX]
    //         004431cd     CALL       dword ptr [ECX + this+0x7c]
    //                              Drawarea.cpp:1098 (4)
    //         004431d0     TEST       EAX,EAX
    //         004431d2     JZ         LAB_004431ed
    //                              Drawarea.cpp:1099 (2)
    //         004431d4     XOR        EAX,EAX
    //                              Drawarea.cpp:1149 (23)
    //         004431d6     MOV        this,dword ptr [ESP + 0xec]
    //         004431dd     MOV        dword ptr FS:[0x0],this
    //         004431e4     POP        EDI
    //         004431e5     POP        ESI
    //         004431e6     ADD        ESP,0xf0
    //         004431ec     RET
    //                               LAB_004431ed                                                 XREF[2]:     004431c2(j), 004431d2(j)  
    //                              Drawarea.cpp:1102 (12)
    //         004431ed     MOV        EDI,dword ptr [EDI]
    //         004431ef     MOV        this,dword ptr [ESI + 0x20]
    //         004431f2     PUSH       this
    //         004431f3     PUSH       EDI=>DAT_fffffff8
    //         004431f4     MOV        EAX,dword ptr [EDI]
    //         004431f6     CALL       dword ptr [EAX + 0x70]
    //                              Drawarea.cpp:1104 (4)
    //         004431f9     TEST       EAX,EAX
    //         004431fb     JZ         LAB_00443216
    //                              Drawarea.cpp:1105 (2)
    //         004431fd     XOR        EAX,EAX
    //                              Drawarea.cpp:1149 (23)
    //         004431ff     MOV        this,dword ptr [ESP + 0xec]
    //         00443206     MOV        dword ptr FS:[0x0],this
    //         0044320d     POP        EDI
    //         0044320e     POP        ESI
    //         0044320f     ADD        ESP,0xf0
    //         00443215     RET
    //                               LAB_00443216                                                 XREF[2]:     00443124(j), 004431fb(j)  
    //                              Drawarea.cpp:1110 (11)
    //         00443216     MOV        EAX,dword ptr [ESI + 0x10]
    //         00443219     TEST       EAX,EAX
    //         0044321b     JNZ        LAB_004432f5
    //                              Drawarea.cpp:1112 (50)
    //         00443221     PUSH       0x100
    //         00443226     CALL       operator_new                                     void * operator_new(uint param_1)
    //         0044322b     ADD        ESP,0x4
    //         0044322e     MOV        dword ptr [ESP + 0x8],EAX
    //         00443232     TEST       EAX,EAX
    //         00443234     MOV        dword ptr [ESP + 0xf4],0x0
    //         0044323f     JZ         LAB_00443251
    //         00443241     PUSH       0x0
    //         00443243     PUSH       s_Primary_Surface                                = "Primary Surface"
    //         00443248     MOV        this,EAX
    //         0044324a     CALL       TDrawArea::TDrawArea                             undefined TDrawArea(TDrawArea * this, char * 
    //         0044324f     JMP        LAB_00443253
    //                               LAB_00443251                                                 XREF[1]:     0044323f(j)  
    //         00443251     XOR        EAX,EAX
    //                               LAB_00443253                                                 XREF[1]:     0044324f(j)  
    //                              Drawarea.cpp:1114 (18)
    //         00443253     TEST       EAX,EAX
    //         00443255     MOV        dword ptr [ESP + 0xf4],0xffffffff
    //         00443260     MOV        dword ptr [ESI + 0x10],EAX
    //         00443263     JNZ        LAB_0044327c
    //                              Drawarea.cpp:1149 (23)
    //         00443265     MOV        this,dword ptr [ESP + 0xec]
    //         0044326c     MOV        dword ptr FS:[0x0],this
    //         00443273     POP        EDI
    //         00443274     POP        ESI
    //         00443275     ADD        ESP,0xf0
    //         0044327b     RET
    //                               LAB_0044327c                                                 XREF[1]:     00443263(j)  
    //                              Drawarea.cpp:1116 (9)
    //         0044327c     CMP        byte ptr [ESI + 0x479],0x1
    //         00443283     JNZ        LAB_004432c6
    //                              Drawarea.cpp:1118 (15)
    //         00443285     MOV        EAX,dword ptr [ESI + 0x4]
    //         00443288     LEA        EDX,[ESP + 0xc]
    //         0044328c     PUSH       EDX
    //         0044328d     PUSH       EAX=>DAT_fffffff8
    //         0044328e     CALL       dword ptr [->USER32.DLL::GetClientRect]          = 0048add6
    //                              Drawarea.cpp:1119 (27)
    //         00443294     MOV        this,dword ptr [ESP + 0x18]
    //         00443298     MOV        EDX,dword ptr [ESP + 0x14]
    //         0044329c     PUSH       0x1
    //         0044329e     PUSH       0x0=>DAT_fffffff8
    //         004432a0     PUSH       this=>DAT_fffffff4
    //         004432a1     MOV        this,dword ptr [ESI + 0x10]
    //         004432a4     PUSH       EDX=>DAT_fffffff0
    //         004432a5     PUSH       ESI
    //         004432a6     CALL       TDrawArea::Init                                  int Init(TDrawArea * this, TDrawSystem * para
    //         004432ab     TEST       EAX,EAX
    //         004432ad     JNZ        LAB_004432f5
    //                              Drawarea.cpp:1149 (23)
    //         004432af     MOV        this,dword ptr [ESP + 0xec]
    //         004432b6     MOV        dword ptr FS:[0x0],this
    //         004432bd     POP        EDI
    //         004432be     POP        ESI
    //         004432bf     ADD        ESP,0xf0
    //         004432c5     RET
    //                               LAB_004432c6                                                 XREF[1]:     00443283(j)  
    //                              Drawarea.cpp:1123 (24)
    //         004432c6     MOV        this,dword ptr [ESI + 0x30]
    //         004432c9     MOV        EDX,dword ptr [ESI + 0x2c]
    //         004432cc     PUSH       0x1
    //         004432ce     PUSH       0x0=>DAT_fffffff8
    //         004432d0     PUSH       this=>DAT_fffffff4
    //         004432d1     PUSH       EDX=>DAT_fffffff0
    //         004432d2     PUSH       ESI
    //         004432d3     MOV        this,EAX
    //         004432d5     CALL       TDrawArea::Init                                  int Init(TDrawArea * this, TDrawSystem * para
    //         004432da     TEST       EAX,EAX
    //         004432dc     JNZ        LAB_004432f5
    //                              Drawarea.cpp:1149 (23)
    //         004432de     MOV        this,dword ptr [ESP + 0xec]
    //         004432e5     MOV        dword ptr FS:[0x0],this
    //         004432ec     POP        EDI
    //         004432ed     POP        ESI
    //         004432ee     ADD        ESP,0xf0
    //         004432f4     RET
    //                               LAB_004432f5                                                 XREF[4]:     00443116(j), 0044321b(j), 
    //                                                                                                         004432ad(j), 004432dc(j)  
    //                              Drawarea.cpp:1131 (11)
    //         004432f5     MOV        EAX,dword ptr [ESI + 0xc]
    //         004432f8     TEST       EAX,EAX
    //         004432fa     JNZ        LAB_004433d4
    //                              Drawarea.cpp:1133 (50)
    //         00443300     PUSH       0x100
    //         00443305     CALL       operator_new                                     void * operator_new(uint param_1)
    //         0044330a     ADD        ESP,0x4
    //         0044330d     MOV        dword ptr [ESP + 0x8],EAX
    //         00443311     TEST       EAX,EAX
    //         00443313     MOV        dword ptr [ESP + 0xf4],0x1
    //         0044331e     JZ         LAB_00443330
    //         00443320     PUSH       0x0
    //         00443322     PUSH       s_Back_Buffer                                    = "Back Buffer"
    //         00443327     MOV        this,EAX
    //         00443329     CALL       TDrawArea::TDrawArea                             undefined TDrawArea(TDrawArea * this, char * 
    //         0044332e     JMP        LAB_00443332
    //                               LAB_00443330                                                 XREF[1]:     0044331e(j)  
    //         00443330     XOR        EAX,EAX
    //                               LAB_00443332                                                 XREF[1]:     0044332e(j)  
    //                              Drawarea.cpp:1135 (18)
    //         00443332     TEST       EAX,EAX
    //         00443334     MOV        dword ptr [ESP + 0xf4],0xffffffff
    //         0044333f     MOV        dword ptr [ESI + 0xc],EAX
    //         00443342     JNZ        LAB_0044335b
    //                              Drawarea.cpp:1149 (23)
    //         00443344     MOV        this,dword ptr [ESP + 0xec]
    //         0044334b     MOV        dword ptr FS:[0x0],this
    //         00443352     POP        EDI
    //         00443353     POP        ESI
    //         00443354     ADD        ESP,0xf0
    //         0044335a     RET
    //                               LAB_0044335b                                                 XREF[1]:     00443342(j)  
    //                              Drawarea.cpp:1137 (9)
    //         0044335b     CMP        byte ptr [ESI + 0x479],0x1
    //         00443362     JNZ        LAB_004433a5
    //                              Drawarea.cpp:1139 (15)
    //         00443364     MOV        this,dword ptr [ESI + 0x4]
    //         00443367     LEA        EAX,[ESP + 0xc]
    //         0044336b     PUSH       EAX
    //         0044336c     PUSH       this=>DAT_fffffff8
    //         0044336d     CALL       dword ptr [->USER32.DLL::GetClientRect]          = 0048add6
    //                              Drawarea.cpp:1140 (27)
    //         00443373     MOV        EDX,dword ptr [ESP + 0x18]
    //         00443377     MOV        EAX,dword ptr [ESP + 0x14]
    //         0044337b     MOV        this,dword ptr [ESI + 0xc]
    //         0044337e     PUSH       0x0
    //         00443380     PUSH       0x0=>DAT_fffffff8
    //         00443382     PUSH       EDX=>DAT_fffffff4
    //         00443383     PUSH       EAX=>DAT_fffffff0
    //         00443384     PUSH       ESI
    //         00443385     CALL       TDrawArea::Init                                  int Init(TDrawArea * this, TDrawSystem * para
    //         0044338a     TEST       EAX,EAX
    //         0044338c     JNZ        LAB_004433d4
    //                              Drawarea.cpp:1149 (23)
    //         0044338e     MOV        this,dword ptr [ESP + 0xec]
    //         00443395     MOV        dword ptr FS:[0x0],this
    //         0044339c     POP        EDI
    //         0044339d     POP        ESI
    //         0044339e     ADD        ESP,0xf0
    //         004433a4     RET
    //                               LAB_004433a5                                                 XREF[1]:     00443362(j)  
    //                              Drawarea.cpp:1144 (24)
    //         004433a5     MOV        this,dword ptr [ESI + 0x30]
    //         004433a8     MOV        EDX,dword ptr [ESI + 0x2c]
    //         004433ab     PUSH       0x0
    //         004433ad     PUSH       0x0=>DAT_fffffff8
    //         004433af     PUSH       this=>DAT_fffffff4
    //         004433b0     PUSH       EDX=>DAT_fffffff0
    //         004433b1     PUSH       ESI
    //         004433b2     MOV        this,EAX
    //         004433b4     CALL       TDrawArea::Init                                  int Init(TDrawArea * this, TDrawSystem * para
    //         004433b9     TEST       EAX,EAX
    //         004433bb     JNZ        LAB_004433d4
    //                              Drawarea.cpp:1149 (51)
    //         004433bd     MOV        this,dword ptr [ESP + 0xec]
    //         004433c4     MOV        dword ptr FS:[0x0],this
    //         004433cb     POP        EDI
    //         004433cc     POP        ESI
    //         004433cd     ADD        ESP,0xf0
    //         004433d3     RET
    //                               LAB_004433d4                                                 XREF[3]:     004432fa(j), 0044338c(j), 
    //                                                                                                         004433bb(j)  
    //         004433d4     MOV        this,dword ptr [ESP + 0xec]
    //         004433db     POP        EDI
    //         004433dc     MOV        EAX,0x1
    //         004433e1     MOV        dword ptr FS:[0x0],this
    //         004433e8     POP        ESI
    //         004433e9     ADD        ESP,0xf0
    //         004433ef     RET
}

// Offset: 0x004433F0
void HandleSize(TDrawSystem* this_, void* param_2, uint param_3, uint param_4, long param_5) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TDrawSystem::HandleSize(void *,unsigned int,unsigned int,long)                *
    //                              *********************************************************************************************************
    //                              void __thiscall HandleSize(TDrawSystem * this, void * param_1, uint 
    //              void              <VOID>         <RETURN>
    //              TDrawSystem *     ECX:4 (auto)   this
    //              void *            Stack[0x4]:4   param_1
    //              uint              Stack[0x8]:4   param_2
    //              uint              Stack[0xc]:4   param_3
    //              long              Stack[0x10]:4  param_4
    //              tagRECT           Stack[-0x14]   wnd_rect                  XREF[0,1]:   00443414(*)  
    //                               ?HandleSize@TDrawSystem@@QAEXPAXIIJ@Z                        XREF[1]:     handle_size:00421978(c)  
    //                               TDrawSystem::HandleSize
    //                              Drawarea.cpp:1155 (6)
    //         004433f0     SUB        ESP,0x10
    //         004433f3     PUSH       ESI
    //         004433f4     MOV        ESI,this
    //                              Drawarea.cpp:1160 (7)
    //         004433f6     MOV        EAX,dword ptr [ESI + 0xc]
    //         004433f9     TEST       EAX,EAX
    //         004433fb     JZ         LAB_00443456
    //                              Drawarea.cpp:1163 (20)
    //         004433fd     MOV        this,byte ptr [ESI + 0x478]
    //         00443403     MOV        AL,0x1
    //         00443405     CMP        this,AL
    //         00443407     JZ         LAB_00443411
    //         00443409     CMP        byte ptr [ESI + 0x479],AL
    //         0044340f     JNZ        LAB_0044342e
    //                               LAB_00443411                                                 XREF[1]:     00443407(j)  
    //                              Drawarea.cpp:1165 (15)
    //         00443411     MOV        this,dword ptr [ESI + 0x4]
    //         00443414     LEA        EAX=>wnd_rect.top,[ESP + 0x4]
    //         00443418     PUSH       EAX
    //         00443419     PUSH       this
    //         0044341a     CALL       dword ptr [->USER32.DLL::GetClientRect]          = 0048add6
    //                              Drawarea.cpp:1166 (4)
    //         00443420     MOV        EDX,dword ptr [ESP + 0xc]
    //                              Drawarea.cpp:1167 (10)
    //         00443424     MOV        EAX,dword ptr [ESP + 0x10]
    //         00443428     MOV        dword ptr [ESI + 0x2c],EDX
    //         0044342b     MOV        dword ptr [ESI + 0x30],EAX
    //                               LAB_0044342e                                                 XREF[1]:     0044340f(j)  
    //                              Drawarea.cpp:1170 (22)
    //         0044342e     MOV        this,dword ptr [ESI + 0x10]
    //         00443431     TEST       this,this
    //         00443433     JZ         LAB_00443444
    //         00443435     MOV        EDX,dword ptr [ESI + 0x30]
    //         00443438     MOV        EAX,dword ptr [ESI + 0x2c]
    //         0044343b     PUSH       0x0
    //         0044343d     PUSH       EDX
    //         0044343e     PUSH       EAX
    //         0044343f     CALL       TDrawArea::SetSize                               void SetSize(TDrawArea * this, long param_1, 
    //                               LAB_00443444                                                 XREF[1]:     00443433(j)  
    //                              Drawarea.cpp:1171 (18)
    //         00443444     MOV        this,dword ptr [ESI + 0x30]
    //         00443447     MOV        EDX,dword ptr [ESI + 0x2c]
    //         0044344a     PUSH       0x0
    //         0044344c     PUSH       this
    //         0044344d     MOV        this,dword ptr [ESI + 0xc]
    //         00443450     PUSH       EDX
    //         00443451     CALL       TDrawArea::SetSize                               void SetSize(TDrawArea * this, long param_1, 
    //                               LAB_00443456                                                 XREF[1]:     004433fb(j)  
    //                              Drawarea.cpp:1172 (7)
    //         00443456     POP        ESI
    //         00443457     ADD        ESP,0x10
    //         0044345a     RET        0x10
}

// Offset: 0x00443460
void HandlePaletteChanged(TDrawSystem* this_, void* param_2, uint param_3, uint param_4, long param_5) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TDrawSystem::HandlePaletteChanged(void *,unsigned int,unsigned int,long)      *
    //                              *********************************************************************************************************
    //                              void __thiscall HandlePaletteChanged(TDrawSystem * this, void * para
    //              void              <VOID>         <RETURN>
    //              TDrawSystem *     ECX:4 (auto)   this
    //              void *            Stack[0x4]:4   param_1                   XREF[1]:     00443460(R)  
    //              uint              Stack[0x8]:4   param_2                   XREF[1]:     00443475(R)  
    //              uint              Stack[0xc]:4   param_3                   XREF[1]:     00443470(R)  
    //              long              Stack[0x10]:4  param_4                   XREF[1]:     0044346b(R)  
    //                               ?HandlePaletteChanged@TDrawSystem@@QAEXPAXIIJ@Z              XREF[1]:     handle_palette_changed:00421a11(c)
    //                               TDrawSystem::HandlePaletteChanged
    //                              Drawarea.cpp:1178 (11)
    //         00443460     MOV        EAX,dword ptr [ESP + param_1]
    //         00443464     MOV        EDX,dword ptr [ECX + this->Wnd]
    //         00443467     CMP        EAX,EDX
    //         00443469     JZ         LAB_00443480
    //                              Drawarea.cpp:1183 (21)
    //         0044346b     MOV        EDX,dword ptr [ESP + param_4]
    //         0044346f     PUSH       EDX
    //         00443470     MOV        EDX,dword ptr [ESP + param_3]
    //         00443474     PUSH       EDX
    //         00443475     MOV        EDX,dword ptr [ESP + param_2]
    //         00443479     PUSH       EDX
    //         0044347a     PUSH       EAX
    //         0044347b     CALL       TDrawSystem::HandleQueryNewPalette               int HandleQueryNewPalette(TDrawSystem * this,
    //                               LAB_00443480                                                 XREF[1]:     00443469(j)  
    //                              Drawarea.cpp:1184 (3)
    //         00443480     RET        0x10
}

// Offset: 0x00443490
int HandleQueryNewPalette(TDrawSystem* this_, void* param_2, uint param_3, uint param_4, long param_5) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall TDrawSystem::HandleQueryNewPalette(void *,unsigned int,unsigned int,long)      *
    //                              *********************************************************************************************************
    //                              int __thiscall HandleQueryNewPalette(TDrawSystem * this, void * para
    //              int               EAX:4          <RETURN>
    //              TDrawSystem *     ECX:4 (auto)   this
    //              void *            Stack[0x4]:4   param_1
    //              uint              Stack[0x8]:4   param_2
    //              uint              Stack[0xc]:4   param_3
    //              long              Stack[0x10]:4  param_4
    //                               ?HandleQueryNewPalette@TDrawSystem@@QAEHPAXIIJ@Z             XREF[3]:     handle_query_new_palette:00421ac1(
    //                               TDrawSystem::HandleQueryNewPalette                                        handle_query_new_palette:00421b52(
    //                                                                                                         HandlePaletteChanged:0044347b(c)  
    //                              Drawarea.cpp:1190 (5)
    //         00443490     PUSH       EBX
    //         00443491     PUSH       ESI
    //         00443492     MOV        ESI,this
    //         00443494     PUSH       EDI
    //                              Drawarea.cpp:1196 (25)
    //         00443495     MOV        EAX,dword ptr [ESI + 0x8]
    //         00443498     TEST       EAX,EAX
    //         0044349a     JZ         LAB_004434fc
    //         0044349c     CMP        byte ptr [ESI + 0x478],0x1
    //         004434a3     JZ         LAB_004434ae
    //         004434a5     CMP        byte ptr [ESI + 0x479],0x1
    //         004434ac     JNZ        LAB_004434fc
    //                               LAB_004434ae                                                 XREF[1]:     004434a3(j)  
    //                              Drawarea.cpp:1198 (12)
    //         004434ae     MOV        EAX,dword ptr [ESI + 0x4]
    //         004434b1     PUSH       EAX
    //         004434b2     CALL       dword ptr [->USER32.DLL::GetDC]                  = 0048ae28
    //         004434b8     MOV        EDI,EAX
    //                              Drawarea.cpp:1199 (7)
    //         004434ba     MOV        EAX,dword ptr [ESI + 0x8]
    //         004434bd     TEST       EAX,EAX
    //         004434bf     JZ         LAB_004434cb
    //                              Drawarea.cpp:1200 (10)
    //         004434c1     PUSH       0x0
    //         004434c3     PUSH       EAX
    //         004434c4     PUSH       EDI
    //         004434c5     CALL       dword ptr [->GDI32.DLL::SelectPalette]           = 0048b1dc
    //                               LAB_004434cb                                                 XREF[1]:     004434bf(j)  
    //                              Drawarea.cpp:1203 (7)
    //         004434cb     PUSH       EDI
    //         004434cc     CALL       dword ptr [->GDI32.DLL::RealizePalette]          = 0048b1ca
    //                              Drawarea.cpp:1204 (13)
    //         004434d2     MOV        this,dword ptr [ESI + 0x4]
    //         004434d5     PUSH       EDI
    //         004434d6     PUSH       this
    //         004434d7     MOV        BL,AL
    //         004434d9     CALL       dword ptr [->USER32.DLL::ReleaseDC]              = 0048ae1c
    //                              Drawarea.cpp:1205 (4)
    //         004434df     TEST       BL,BL
    //         004434e1     JZ         LAB_004434fc
    //                              Drawarea.cpp:1208 (14)
    //         004434e3     MOV        EDX,dword ptr [ESI + 0x4]
    //         004434e6     PUSH       0x0
    //         004434e8     PUSH       0x0
    //         004434ea     PUSH       EDX
    //         004434eb     CALL       dword ptr [->USER32.DLL::InvalidateRect]         = 0048af16
    //                              Drawarea.cpp:1209 (5)
    //         004434f1     MOV        EAX,0x1
    //                              Drawarea.cpp:1218 (6)
    //         004434f6     POP        EDI
    //         004434f7     POP        ESI
    //         004434f8     POP        EBX
    //         004434f9     RET        0x10
    //                               LAB_004434fc                                                 XREF[3]:     0044349a(j), 004434ac(j), 
    //                                                                                                         004434e1(j)  
    //                              Drawarea.cpp:1215 (18)
    //         004434fc     LEA        EAX,[ESI + 0x78]
    //         004434ff     MOV        this,ESI
    //         00443501     PUSH       EAX
    //         00443502     PUSH       0x100
    //         00443507     PUSH       0x0
    //         00443509     CALL       TDrawSystem::ModifyPalette                       void ModifyPalette(TDrawSystem * this, int pa
    //                              Drawarea.cpp:1218 (8)
    //         0044350e     POP        EDI
    //         0044350f     POP        ESI
    //         00443510     XOR        EAX,EAX
    //         00443512     POP        EBX
    //         00443513     RET        0x10
}

// Offset: 0x00443520
void Paint(TDrawSystem* this_, tagRECT* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TDrawSystem::Paint(struct tagRECT *)                                          *
    //                              *********************************************************************************************************
    //                              void __thiscall Paint(TDrawSystem * this, tagRECT * param_1)
    //              void              <VOID>         <RETURN>
    //              TDrawSystem *     ECX:4 (auto)   this
    //              tagRECT *         Stack[0x4]:4   param_1                   XREF[1]:     004435d7(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     004435c3(W)  
    //              tagRECT           Stack[-0x14]   src                       XREF[1,8]:   004435d3(W), 00443563(*), 004435b7(W), 004435ec(W), 
    //                                                                                     004435f8(W), 004435bb(W), 004435f0(W), 00443602(W), 
    //                                                                                     004435bf(W)  
    //              tagRECT           Stack[-0x24]   dest                      XREF[0,3]:   004435c7(W), 004435cb(W), 004435cf(W)  
    //                               ?Paint@TDrawSystem@@QAEXPAUtagRECT@@@Z                       XREF[11]:    setup_graphics_system:0041eba3(c), 
    //                               TDrawSystem::Paint                                                        check_paint:0041ff8a(c), 
    //                                                                                                         handle_paint:0042170a(c), 
    //                                                                                                         handle_close:00421b9f(c), 
    //                                                                                                         off:0045bf17(c), 
    //                                                                                                         paint:004653bf(c), 
    //                                                                                                         set_focus:00469e9b(c), 
    //                                                                                                         set_focus:0047bc27(c), 
    //                                                                                                         set_focus:0047bc9d(c), 
    //                                                                                                         handle_idle:00492b71(c), 
    //                                                                                                         handle_idle:00492c0d(c)  
    //                              Drawarea.cpp:1224 (8)
    //         00443520     SUB        ESP,0x20
    //         00443523     PUSH       EBX
    //         00443524     PUSH       EBP
    //         00443525     PUSH       ESI
    //         00443526     MOV        ESI,this
    //                              Drawarea.cpp:1227 (15)
    //         00443528     MOV        this,0x1
    //         0044352a     PUSH       EDI
    //         0044352b     CMP        byte ptr [ESI + 0x478],this
    //         00443531     JZ         LAB_0044366c
    //                              Drawarea.cpp:1253 (33)
    //         00443537     MOV        EAX,dword ptr [ESI + 0x1c]
    //         0044353a     TEST       EAX,EAX
    //         0044353c     JZ         LAB_0044366c
    //         00443542     MOV        EAX,dword ptr [ESI + 0xc]
    //         00443545     TEST       EAX,EAX
    //         00443547     JZ         LAB_0044366c
    //         0044354d     MOV        EDX,dword ptr [EAX + 0x3c]
    //         00443550     TEST       EDX,EDX
    //         00443552     JZ         LAB_0044366c
    //                              Drawarea.cpp:1257 (8)
    //         00443558     CMP        byte ptr [ESI + 0x479],this
    //         0044355e     JNZ        LAB_004435ad
    //                              Drawarea.cpp:1259 (15)
    //         00443560     MOV        this,dword ptr [ESI + 0x4]
    //         00443563     LEA        EAX=>src.top,[ESP + 0x20]
    //         00443567     PUSH       EAX
    //         00443568     PUSH       this
    //         00443569     CALL       dword ptr [->USER32.DLL::GetClientRect]          = 0048add6
    //                              Drawarea.cpp:1260 (12)
    //         0044356f     MOV        EAX,dword ptr [ESP + 0x24]
    //         00443573     MOV        this,dword ptr [ESP + 0x28]
    //         00443577     MOV        EDX,dword ptr [ESP + 0x20]
    //                              Drawarea.cpp:1261 (37)
    //         0044357b     MOV        EDI,dword ptr [->USER32.DLL::ClientToScreen]     = 0048afd2
    //         00443581     MOV        dword ptr [ESP + 0x14],EAX
    //         00443585     MOV        dword ptr [ESP + 0x18],this
    //         00443589     MOV        this,dword ptr [ESI + 0x4]
    //         0044358c     LEA        EAX,[ESP + 0x10]
    //         00443590     MOV        dword ptr [ESP + 0x10],EDX
    //         00443594     MOV        EDX,dword ptr [ESP + 0x2c]
    //         00443598     PUSH       EAX
    //         00443599     PUSH       this
    //         0044359a     MOV        dword ptr [ESP + 0x24],EDX
    //         0044359e     CALL       EDI=>USER32.DLL::ClientToScreen
    //                              Drawarea.cpp:1262 (11)
    //         004435a0     MOV        EAX,dword ptr [ESI + 0x4]
    //         004435a3     LEA        EDX,[ESP + 0x18]
    //         004435a7     PUSH       EDX
    //         004435a8     PUSH       EAX
    //         004435a9     CALL       EDI=>USER32.DLL::ClientToScreen
    //                              Drawarea.cpp:1264 (2)
    //         004435ab     JMP        LAB_004435d7
    //                               LAB_004435ad                                                 XREF[1]:     0044355e(j)  
    //                              Drawarea.cpp:1268 (3)
    //         004435ad     MOV        EDX,dword ptr [ESI + 0x2c]
    //                              Drawarea.cpp:1269 (23)
    //         004435b0     MOV        EDI,dword ptr [ESI + 0x30]
    //         004435b3     XOR        EAX,EAX
    //         004435b5     XOR        this,this
    //         004435b7     MOV        dword ptr [ESP + src.top],EAX
    //         004435bb     MOV        dword ptr [ESP + src.right],this
    //         004435bf     MOV        dword ptr [ESP + src.bottom],EDX
    //         004435c3     MOV        dword ptr [ESP + local_4],EDI
    //                              Drawarea.cpp:1270 (16)
    //         004435c7     MOV        dword ptr [ESP + dest.top],EAX
    //         004435cb     MOV        dword ptr [ESP + dest.right],this
    //         004435cf     MOV        dword ptr [ESP + dest.bottom],EDX
    //         004435d3     MOV        dword ptr [ESP + src.left],EDI
    //                               LAB_004435d7                                                 XREF[1]:     004435ab(j)  
    //                              Drawarea.cpp:1274 (6)
    //         004435d7     MOV        EAX,dword ptr [ESP + param_1]
    //         004435db     TEST       EAX,EAX
    //                              Drawarea.cpp:1285 (2)
    //         004435dd     JZ         LAB_0044364b
    //                              Drawarea.cpp:1288 (11)
    //         004435df     MOV        this,dword ptr [EAX]
    //         004435e1     MOV        EBX,dword ptr [EAX + 0x4]
    //         004435e4     MOV        EDX,dword ptr [EAX + 0x8]
    //         004435e7     MOV        EDI,dword ptr [EAX + 0xc]
    //                              Drawarea.cpp:1291 (12)
    //         004435ea     TEST       this,this
    //         004435ec     MOV        dword ptr [ESP + src.top],this
    //         004435f0     MOV        dword ptr [ESP + src.right],EBX
    //         004435f4     JGE        LAB_004435fc
    //                              Drawarea.cpp:1292 (6)
    //         004435f6     XOR        this,this
    //         004435f8     MOV        dword ptr [ESP + src.top],this
    //                               LAB_004435fc                                                 XREF[1]:     004435f4(j)  
    //                              Drawarea.cpp:1293 (4)
    //         004435fc     TEST       EBX,EBX
    //         004435fe     JGE        LAB_00443606
    //                              Drawarea.cpp:1294 (6)
    //         00443600     XOR        EBX,EBX
    //         00443602     MOV        dword ptr [ESP + src.right],EBX
    //                               LAB_00443606                                                 XREF[1]:     004435fe(j)  
    //                              Drawarea.cpp:1295 (7)
    //         00443606     MOV        EAX,dword ptr [ESI + 0x2c]
    //         00443609     CMP        EDX,EAX
    //         0044360b     JL         LAB_00443610
    //                              Drawarea.cpp:1296 (3)
    //         0044360d     LEA        EDX,[EAX + -0x1]
    //                               LAB_00443610                                                 XREF[1]:     0044360b(j)  
    //                              Drawarea.cpp:1297 (7)
    //         00443610     MOV        EAX,dword ptr [ESI + 0x30]
    //         00443613     CMP        EDI,EAX
    //         00443615     JL         LAB_0044361a
    //                              Drawarea.cpp:1298 (3)
    //         00443617     LEA        EDI,[EAX + -0x1]
    //                               LAB_0044361a                                                 XREF[1]:     00443615(j)  
    //                              Drawarea.cpp:1301 (4)
    //         0044361a     MOV        EAX,dword ptr [ESP + 0x10]
    //                              Drawarea.cpp:1302 (12)
    //         0044361e     MOV        EBP,dword ptr [ESP + 0x14]
    //         00443622     ADD        EAX,this
    //         00443624     ADD        EBP,EBX
    //         00443626     MOV        dword ptr [ESP + 0x10],EAX
    //                              Drawarea.cpp:1303 (4)
    //         0044362a     ADD        EAX,EDX
    //         0044362c     SUB        EAX,this
    //                              Drawarea.cpp:1304 (5)
    //         0044362e     LEA        this,[EDI + EBP*0x1]
    //         00443631     SUB        this,EBX
    //                              Drawarea.cpp:1308 (1)
    //         00443633     INC        EDX
    //                              Drawarea.cpp:1309 (1)
    //         00443634     INC        EDI
    //                              Drawarea.cpp:1311 (1)
    //         00443635     INC        EAX
    //                              Drawarea.cpp:1312 (21)
    //         00443636     INC        this
    //         00443637     MOV        dword ptr [ESP + 0x14],EBP
    //         0044363b     MOV        dword ptr [ESP + 0x28],EDX
    //         0044363f     MOV        dword ptr [ESP + 0x2c],EDI
    //         00443643     MOV        dword ptr [ESP + 0x18],EAX
    //         00443647     MOV        dword ptr [ESP + 0x1c],this
    //                               LAB_0044364b                                                 XREF[1]:     004435dd(j)  
    //                              Drawarea.cpp:1318 (33)
    //         0044364b     MOV        EAX,dword ptr [ESI + 0x1c]
    //         0044364e     PUSH       0x0
    //         00443650     LEA        EDX,[ESP + 0x24]
    //         00443654     PUSH       0x1000000
    //         00443659     PUSH       EDX
    //         0044365a     MOV        EDX,dword ptr [ESI + 0xc]
    //         0044365d     MOV        this,dword ptr [EAX]
    //         0044365f     MOV        EDX,dword ptr [EDX + 0x3c]
    //         00443662     PUSH       EDX
    //         00443663     LEA        EDX,[ESP + 0x20]
    //         00443667     PUSH       EDX
    //         00443668     PUSH       EAX
    //         00443669     CALL       dword ptr [ECX + this->DrawAreaList]
    //                               LAB_0044366c                                                 XREF[4]:     00443531(j), 0044353c(j), 
    //                                                                                                         00443547(j), 00443552(j)  
    //                              Drawarea.cpp:1328 (10)
    //         0044366c     POP        EDI
    //         0044366d     POP        ESI
    //         0044366e     POP        EBP
    //         0044366f     POP        EBX
    //         00443670     ADD        ESP,0x20
    //         00443673     RET        0x4
}

// Offset: 0x00443680
int GetIsLostErrorNum(TDrawSystem* this_, long param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall TDrawSystem::GetIsLostErrorNum(long)                                           *
    //                              *********************************************************************************************************
    //                              int __thiscall GetIsLostErrorNum(TDrawSystem * this, long param_1)
    //              int               EAX:4          <RETURN>
    //              TDrawSystem *     ECX:4 (auto)   this
    //              long              Stack[0x4]:4   param_1                   XREF[1]:     00443680(R)  
    //                               ?GetIsLostErrorNum@TDrawSystem@@QAEHJ@Z                      XREF[2]:     CheckSurfaces:00442f84(c), 
    //                               TDrawSystem::GetIsLostErrorNum                                            CheckSurface:00444154(c)  
    //                              Drawarea.cpp:1335 (20)
    //         00443680     MOV        EAX,dword ptr [ESP + param_1]
    //         00443684     CMP        EAX,0x88760082
    //         00443689     JG         LAB_004436a4
    //         0044368b     JZ         LAB_0044369c
    //         0044368d     CMP        EAX,0x80070057
    //         00443692     JNZ        LAB_004436af
    //                              Drawarea.cpp:1343 (5)
    //         00443694     MOV        EAX,0x6a5
    //                              Drawarea.cpp:1350 (3)
    //         00443699     RET        0x4
    //                               LAB_0044369c                                                 XREF[1]:     0044368b(j)  
    //                              Drawarea.cpp:1342 (5)
    //         0044369c     MOV        EAX,0x6a4
    //                              Drawarea.cpp:1350 (3)
    //         004436a1     RET        0x4
    //                               LAB_004436a4                                                 XREF[1]:     00443689(j)  
    //                              Drawarea.cpp:1338 (11)
    //         004436a4     CMP        EAX,0x887601c2
    //         004436a9     JZ         LAB_004436bc
    //         004436ab     TEST       EAX,EAX
    //         004436ad     JZ         LAB_004436b7
    //                               LAB_004436af                                                 XREF[1]:     00443692(j)  
    //                              Drawarea.cpp:1346 (5)
    //         004436af     MOV        EAX,0x707
    //                              Drawarea.cpp:1350 (3)
    //         004436b4     RET        0x4
    //                               LAB_004436b7                                                 XREF[1]:     004436ad(j)  
    //                              Drawarea.cpp:1340 (2)
    //         004436b7     XOR        EAX,EAX
    //                              Drawarea.cpp:1350 (3)
    //         004436b9     RET        0x4
    //                               LAB_004436bc                                                 XREF[1]:     004436a9(j)  
    //                              Drawarea.cpp:1344 (5)
    //         004436bc     MOV        EAX,0x6a6
    //                              Drawarea.cpp:1350 (3)
    //         004436c1     RET        0x4
}

// Offset: 0x004436D0
int GetRestoreErrorNum(TDrawSystem* this_, long param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall TDrawSystem::GetRestoreErrorNum(long)                                          *
    //                              *********************************************************************************************************
    //                              int __thiscall GetRestoreErrorNum(TDrawSystem * this, long param_1)
    //              int               EAX:4          <RETURN>
    //              TDrawSystem *     ECX:4 (auto)   this
    //              long              Stack[0x4]:4   param_1                   XREF[1]:     004436d0(R)  
    //                               ?GetRestoreErrorNum@TDrawSystem@@QAEHJ@Z                     XREF[2]:     CheckSurfaces:00442fed(c), 
    //                               TDrawSystem::GetRestoreErrorNum                                           CheckSurface:00444203(c)  
    //                              Drawarea.cpp:1356 (20)
    //         004436d0     MOV        EAX,dword ptr [ESP + param_1]
    //         004436d4     CMP        EAX,0x80004005
    //         004436d9     JG         LAB_004436f4
    //         004436db     JZ         LAB_004436ec
    //         004436dd     CMP        EAX,0x80004001
    //         004436e2     JNZ        LAB_0044375f
    //                              Drawarea.cpp:1370 (5)
    //         004436e4     MOV        EAX,0x70f
    //                              Drawarea.cpp:1377 (3)
    //         004436e9     RET        0x4
    //                               LAB_004436ec                                                 XREF[1]:     004436db(j)  
    //                              Drawarea.cpp:1363 (5)
    //         004436ec     MOV        EAX,0x708
    //                              Drawarea.cpp:1377 (3)
    //         004436f1     RET        0x4
    //                               LAB_004436f4                                                 XREF[1]:     004436d9(j)  
    //                              Drawarea.cpp:1359 (16)
    //         004436f4     CMP        EAX,0x80070057
    //         004436f9     JG         LAB_00443714
    //         004436fb     JZ         LAB_0044370c
    //         004436fd     CMP        EAX,0x8007000e
    //         00443702     JNZ        LAB_0044375f
    //                              Drawarea.cpp:1369 (5)
    //         00443704     MOV        EAX,0x70e
    //                              Drawarea.cpp:1377 (3)
    //         00443709     RET        0x4
    //                               LAB_0044370c                                                 XREF[1]:     004436fb(j)  
    //                              Drawarea.cpp:1367 (5)
    //         0044370c     MOV        EAX,0x70c
    //                              Drawarea.cpp:1377 (3)
    //         00443711     RET        0x4
    //                               LAB_00443714                                                 XREF[1]:     004436f9(j)  
    //                              Drawarea.cpp:1359 (16)
    //         00443714     CMP        EAX,0x88760082
    //         00443719     JG         LAB_00443734
    //         0044371b     JZ         LAB_0044372c
    //         0044371d     CMP        EAX,0x8876005f
    //         00443722     JNZ        LAB_0044375f
    //                              Drawarea.cpp:1365 (5)
    //         00443724     MOV        EAX,0x70a
    //                              Drawarea.cpp:1377 (3)
    //         00443729     RET        0x4
    //                               LAB_0044372c                                                 XREF[1]:     0044371b(j)  
    //                              Drawarea.cpp:1366 (5)
    //         0044372c     MOV        EAX,0x70b
    //                              Drawarea.cpp:1377 (3)
    //         00443731     RET        0x4
    //                               LAB_00443734                                                 XREF[1]:     00443719(j)  
    //                              Drawarea.cpp:1359 (16)
    //         00443734     CMP        EAX,0x8876024b
    //         00443739     JG         LAB_00443754
    //         0044373b     JZ         LAB_0044374c
    //         0044373d     CMP        EAX,0x887600e1
    //         00443742     JNZ        LAB_0044375f
    //                              Drawarea.cpp:1368 (5)
    //         00443744     MOV        EAX,0x70d
    //                              Drawarea.cpp:1377 (3)
    //         00443749     RET        0x4
    //                               LAB_0044374c                                                 XREF[1]:     0044373b(j)  
    //                              Drawarea.cpp:1371 (5)
    //         0044374c     MOV        EAX,0x710
    //                              Drawarea.cpp:1377 (3)
    //         00443751     RET        0x4
    //                               LAB_00443754                                                 XREF[1]:     00443739(j)  
    //                              Drawarea.cpp:1359 (11)
    //         00443754     CMP        EAX,0x8876024c
    //         00443759     JZ         LAB_0044376c
    //         0044375b     TEST       EAX,EAX
    //         0044375d     JZ         LAB_00443767
    //                               LAB_0044375f                                                 XREF[4]:     004436e2(j), 00443702(j), 
    //                                                                                                         00443722(j), 00443742(j)  
    //                              Drawarea.cpp:1373 (5)
    //         0044375f     MOV        EAX,0x76b
    //                              Drawarea.cpp:1377 (3)
    //         00443764     RET        0x4
    //                               LAB_00443767                                                 XREF[1]:     0044375d(j)  
    //                              Drawarea.cpp:1361 (2)
    //         00443767     XOR        EAX,EAX
    //                              Drawarea.cpp:1377 (3)
    //         00443769     RET        0x4
    //                               LAB_0044376c                                                 XREF[1]:     00443759(j)  
    //                              Drawarea.cpp:1364 (5)
    //         0044376c     MOV        EAX,0x709
    //                              Drawarea.cpp:1377 (3)
    //         00443771     RET        0x4
}

// Offset: 0x00443780
int GetSetDispModeErrorNum(TDrawSystem* this_, long param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall TDrawSystem::GetSetDispModeErrorNum(long)                                      *
    //                              *********************************************************************************************************
    //                              int __thiscall GetSetDispModeErrorNum(TDrawSystem * this, long param
    //              int               EAX:4          <RETURN>
    //              TDrawSystem *     ECX:4 (auto)   this
    //              long              Stack[0x4]:4   param_1                   XREF[1]:     00443780(R)  
    //                               ?GetSetDispModeErrorNum@TDrawSystem@@QAEHJ@Z
    //                               TDrawSystem::GetSetDispModeErrorNum
    //                              Drawarea.cpp:1383 (24)
    //         00443780     MOV        EAX,dword ptr [ESP + param_1]
    //         00443784     CMP        EAX,0x80004005
    //         00443789     JG         LAB_004437a8
    //         0044378b     JZ         LAB_004437a0
    //         0044378d     CMP        EAX,0x80004001
    //         00443792     JNZ        LAB_0044381a
    //                              Drawarea.cpp:1397 (5)
    //         00443798     MOV        EAX,0x773
    //                              Drawarea.cpp:1405 (3)
    //         0044379d     RET        0x4
    //                               LAB_004437a0                                                 XREF[1]:     0044378b(j)  
    //                              Drawarea.cpp:1390 (5)
    //         004437a0     MOV        EAX,0x76c
    //                              Drawarea.cpp:1405 (3)
    //         004437a5     RET        0x4
    //                               LAB_004437a8                                                 XREF[1]:     00443789(j)  
    //                              Drawarea.cpp:1386 (16)
    //         004437a8     CMP        EAX,0x88760078
    //         004437ad     JG         LAB_004437c8
    //         004437af     JZ         LAB_004437c0
    //         004437b1     CMP        EAX,0x80070057
    //         004437b6     JNZ        LAB_0044381a
    //                              Drawarea.cpp:1393 (5)
    //         004437b8     MOV        EAX,0x76f
    //                              Drawarea.cpp:1405 (3)
    //         004437bd     RET        0x4
    //                               LAB_004437c0                                                 XREF[1]:     004437af(j)  
    //                              Drawarea.cpp:1391 (5)
    //         004437c0     MOV        EAX,0x76d
    //                              Drawarea.cpp:1405 (3)
    //         004437c5     RET        0x4
    //                               LAB_004437c8                                                 XREF[1]:     004437ad(j)  
    //                              Drawarea.cpp:1386 (16)
    //         004437c8     CMP        EAX,0x887600a0
    //         004437cd     JG         LAB_004437e8
    //         004437cf     JZ         LAB_004437e0
    //         004437d1     CMP        EAX,0x88760082
    //         004437d6     JNZ        LAB_0044381a
    //                              Drawarea.cpp:1392 (5)
    //         004437d8     MOV        EAX,0x76e
    //                              Drawarea.cpp:1405 (3)
    //         004437dd     RET        0x4
    //                               LAB_004437e0                                                 XREF[1]:     004437cf(j)  
    //                              Drawarea.cpp:1394 (5)
    //         004437e0     MOV        EAX,0x770
    //                              Drawarea.cpp:1405 (3)
    //         004437e5     RET        0x4
    //                               LAB_004437e8                                                 XREF[1]:     004437cd(j)  
    //                              Drawarea.cpp:1386 (16)
    //         004437e8     CMP        EAX,0x887601ae
    //         004437ed     JG         LAB_00443808
    //         004437ef     JZ         LAB_00443800
    //         004437f1     CMP        EAX,0x887600e1
    //         004437f6     JNZ        LAB_0044381a
    //                              Drawarea.cpp:1395 (5)
    //         004437f8     MOV        EAX,0x771
    //                              Drawarea.cpp:1405 (3)
    //         004437fd     RET        0x4
    //                               LAB_00443800                                                 XREF[1]:     004437ef(j)  
    //                              Drawarea.cpp:1396 (5)
    //         00443800     MOV        EAX,0x772
    //                              Drawarea.cpp:1405 (3)
    //         00443805     RET        0x4
    //                               LAB_00443808                                                 XREF[1]:     004437ed(j)  
    //                              Drawarea.cpp:1386 (18)
    //         00443808     CMP        EAX,0x8876021c
    //         0044380d     JZ         LAB_0044382f
    //         0044380f     CMP        EAX,0x8876024e
    //         00443814     JZ         LAB_00443827
    //         00443816     TEST       EAX,EAX
    //         00443818     JZ         LAB_00443822
    //                               LAB_0044381a                                                 XREF[4]:     00443792(j), 004437b6(j), 
    //                                                                                                         004437d6(j), 004437f6(j)  
    //                              Drawarea.cpp:1401 (5)
    //         0044381a     MOV        EAX,0x7cf
    //                              Drawarea.cpp:1405 (3)
    //         0044381f     RET        0x4
    //                               LAB_00443822                                                 XREF[1]:     00443818(j)  
    //                              Drawarea.cpp:1388 (2)
    //         00443822     XOR        EAX,EAX
    //                              Drawarea.cpp:1405 (3)
    //         00443824     RET        0x4
    //                               LAB_00443827                                                 XREF[1]:     00443814(j)  
    //                              Drawarea.cpp:1398 (5)
    //         00443827     MOV        EAX,0x774
    //                              Drawarea.cpp:1405 (3)
    //         0044382c     RET        0x4
    //                               LAB_0044382f                                                 XREF[1]:     0044380d(j)  
    //                              Drawarea.cpp:1399 (5)
    //         0044382f     MOV        EAX,0x775
    //                              Drawarea.cpp:1405 (3)
    //         00443834     RET        0x4
}

// Offset: 0x00443840
int GetLockErrorNum(TDrawSystem* this_, long param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall TDrawSystem::GetLockErrorNum(long)                                             *
    //                              *********************************************************************************************************
    //                              int __thiscall GetLockErrorNum(TDrawSystem * this, long param_1)
    //              int               EAX:4          <RETURN>
    //              TDrawSystem *     ECX:4 (auto)   this
    //              long              Stack[0x4]:4   param_1                   XREF[1]:     00443840(R)  
    //                               ?GetLockErrorNum@TDrawSystem@@QAEHJ@Z
    //                               TDrawSystem::GetLockErrorNum
    //                              Drawarea.cpp:1414 (20)
    //         00443840     MOV        EAX,dword ptr [ESP + param_1]
    //         00443844     CMP        EAX,0x8007000e
    //         00443849     JG         LAB_00443864
    //         0044384b     JZ         LAB_0044385c
    //         0044384d     CMP        EAX,0x80004005
    //         00443852     JNZ        LAB_004438cf
    //                              Drawarea.cpp:1421 (5)
    //         00443854     MOV        EAX,0x7d0
    //                              Drawarea.cpp:1436 (3)
    //         00443859     RET        0x4
    //                               LAB_0044385c                                                 XREF[1]:     0044384b(j)  
    //                              Drawarea.cpp:1427 (5)
    //         0044385c     MOV        EAX,0x7d6
    //                              Drawarea.cpp:1436 (3)
    //         00443861     RET        0x4
    //                               LAB_00443864                                                 XREF[1]:     00443849(j)  
    //                              Drawarea.cpp:1417 (16)
    //         00443864     CMP        EAX,0x88760082
    //         00443869     JG         LAB_00443884
    //         0044386b     JZ         LAB_0044387c
    //         0044386d     CMP        EAX,0x80070057
    //         00443872     JNZ        LAB_004438cf
    //                              Drawarea.cpp:1423 (5)
    //         00443874     MOV        EAX,0x7d2
    //                              Drawarea.cpp:1436 (3)
    //         00443879     RET        0x4
    //                               LAB_0044387c                                                 XREF[1]:     0044386b(j)  
    //                              Drawarea.cpp:1422 (5)
    //         0044387c     MOV        EAX,0x7d1
    //                              Drawarea.cpp:1436 (3)
    //         00443881     RET        0x4
    //                               LAB_00443884                                                 XREF[1]:     00443869(j)  
    //                              Drawarea.cpp:1417 (16)
    //         00443884     CMP        EAX,0x887601ae
    //         00443889     JG         LAB_004438a4
    //         0044388b     JZ         LAB_0044389c
    //         0044388d     CMP        EAX,0x88760096
    //         00443892     JNZ        LAB_004438cf
    //                              Drawarea.cpp:1429 (5)
    //         00443894     MOV        EAX,0x7d8
    //                              Drawarea.cpp:1436 (3)
    //         00443899     RET        0x4
    //                               LAB_0044389c                                                 XREF[1]:     0044388b(j)  
    //                              Drawarea.cpp:1424 (5)
    //         0044389c     MOV        EAX,0x7d3
    //                              Drawarea.cpp:1436 (3)
    //         004438a1     RET        0x4
    //                               LAB_004438a4                                                 XREF[1]:     00443889(j)  
    //                              Drawarea.cpp:1417 (16)
    //         004438a4     CMP        EAX,0x8876021c
    //         004438a9     JG         LAB_004438c4
    //         004438ab     JZ         LAB_004438bc
    //         004438ad     CMP        EAX,0x887601c2
    //         004438b2     JNZ        LAB_004438cf
    //                              Drawarea.cpp:1425 (5)
    //         004438b4     MOV        EAX,0x7d4
    //                              Drawarea.cpp:1436 (3)
    //         004438b9     RET        0x4
    //                               LAB_004438bc                                                 XREF[1]:     004438ab(j)  
    //                              Drawarea.cpp:1426 (5)
    //         004438bc     MOV        EAX,0x7d5
    //                              Drawarea.cpp:1436 (3)
    //         004438c1     RET        0x4
    //                               LAB_004438c4                                                 XREF[1]:     004438a9(j)  
    //                              Drawarea.cpp:1417 (11)
    //         004438c4     CMP        EAX,0x88760248
    //         004438c9     JZ         LAB_004438dc
    //         004438cb     TEST       EAX,EAX
    //         004438cd     JZ         LAB_004438d7
    //                               LAB_004438cf                                                 XREF[4]:     00443852(j), 00443872(j), 
    //                                                                                                         00443892(j), 004438b2(j)  
    //                              Drawarea.cpp:1431 (5)
    //         004438cf     MOV        EAX,0x833
    //                              Drawarea.cpp:1436 (3)
    //         004438d4     RET        0x4
    //                               LAB_004438d7                                                 XREF[1]:     004438cd(j)  
    //                              Drawarea.cpp:1419 (2)
    //         004438d7     XOR        EAX,EAX
    //                              Drawarea.cpp:1436 (3)
    //         004438d9     RET        0x4
    //                               LAB_004438dc                                                 XREF[1]:     004438c9(j)  
    //                              Drawarea.cpp:1428 (5)
    //         004438dc     MOV        EAX,0x7d7
    //                              Drawarea.cpp:1436 (3)
    //         004438e1     RET        0x4
}

// Offset: 0x004438F0
int GetDCErrorNum(TDrawSystem* this_, long param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall TDrawSystem::GetDCErrorNum(long)                                               *
    //                              *********************************************************************************************************
    //                              int __thiscall GetDCErrorNum(TDrawSystem * this, long param_1)
    //              int               EAX:4          <RETURN>
    //              TDrawSystem *     ECX:4 (auto)   this
    //              long              Stack[0x4]:4   param_1                   XREF[1]:     004438f0(R)  
    //                               ?GetDCErrorNum@TDrawSystem@@QAEHJ@Z
    //                               TDrawSystem::GetDCErrorNum
    //                              Drawarea.cpp:1443 (20)
    //         004438f0     MOV        EAX,dword ptr [ESP + param_1]
    //         004438f4     CMP        EAX,0x80004005
    //         004438f9     JG         LAB_00443914
    //         004438fb     JZ         LAB_0044390c
    //         004438fd     CMP        EAX,0x80004001
    //         00443902     JNZ        LAB_00443966
    //                              Drawarea.cpp:1457 (5)
    //         00443904     MOV        EAX,0x83a
    //                              Drawarea.cpp:1465 (3)
    //         00443909     RET        0x4
    //                               LAB_0044390c                                                 XREF[1]:     004438fb(j)  
    //                              Drawarea.cpp:1451 (5)
    //         0044390c     MOV        EAX,0x834
    //                              Drawarea.cpp:1465 (3)
    //         00443911     RET        0x4
    //                               LAB_00443914                                                 XREF[1]:     004438f9(j)  
    //                              Drawarea.cpp:1446 (16)
    //         00443914     CMP        EAX,0x88760082
    //         00443919     JG         LAB_00443934
    //         0044391b     JZ         LAB_0044392c
    //         0044391d     CMP        EAX,0x80070057
    //         00443922     JNZ        LAB_00443966
    //                              Drawarea.cpp:1454 (5)
    //         00443924     MOV        EAX,0x837
    //                              Drawarea.cpp:1465 (3)
    //         00443929     RET        0x4
    //                               LAB_0044392c                                                 XREF[1]:     0044391b(j)  
    //                              Drawarea.cpp:1453 (5)
    //         0044392c     MOV        EAX,0x836
    //                              Drawarea.cpp:1465 (3)
    //         00443931     RET        0x4
    //                               LAB_00443934                                                 XREF[1]:     00443919(j)  
    //                              Drawarea.cpp:1446 (16)
    //         00443934     CMP        EAX,0x8876021c
    //         00443939     JG         LAB_00443954
    //         0044393b     JZ         LAB_0044394c
    //         0044393d     CMP        EAX,0x887601c2
    //         00443942     JNZ        LAB_00443966
    //                              Drawarea.cpp:1456 (5)
    //         00443944     MOV        EAX,0x839
    //                              Drawarea.cpp:1465 (3)
    //         00443949     RET        0x4
    //                               LAB_0044394c                                                 XREF[1]:     0044393b(j)  
    //                              Drawarea.cpp:1458 (5)
    //         0044394c     MOV        EAX,0x83b
    //                              Drawarea.cpp:1465 (3)
    //         00443951     RET        0x4
    //                               LAB_00443954                                                 XREF[1]:     00443939(j)  
    //                              Drawarea.cpp:1446 (18)
    //         00443954     CMP        EAX,0x88760250
    //         00443959     JZ         LAB_0044397b
    //         0044395b     CMP        EAX,0x8876026c
    //         00443960     JZ         LAB_00443973
    //         00443962     TEST       EAX,EAX
    //         00443964     JZ         LAB_0044396e
    //                               LAB_00443966                                                 XREF[3]:     00443902(j), 00443922(j), 
    //                                                                                                         00443942(j)  
    //                              Drawarea.cpp:1460 (5)
    //         00443966     MOV        EAX,0x897
    //                              Drawarea.cpp:1465 (3)
    //         0044396b     RET        0x4
    //                               LAB_0044396e                                                 XREF[1]:     00443964(j)  
    //                              Drawarea.cpp:1449 (2)
    //         0044396e     XOR        EAX,EAX
    //                              Drawarea.cpp:1465 (3)
    //         00443970     RET        0x4
    //                               LAB_00443973                                                 XREF[1]:     00443960(j)  
    //                              Drawarea.cpp:1452 (5)
    //         00443973     MOV        EAX,0x835
    //                              Drawarea.cpp:1465 (3)
    //         00443978     RET        0x4
    //                               LAB_0044397b                                                 XREF[1]:     00443959(j)  
    //                              Drawarea.cpp:1455 (5)
    //         0044397b     MOV        EAX,0x838
    //                              Drawarea.cpp:1465 (3)
    //         00443980     RET        0x4
}

// Offset: 0x00443990
int GetBlitErrorNum(TDrawSystem* this_, long param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall TDrawSystem::GetBlitErrorNum(long)                                             *
    //                              *********************************************************************************************************
    //                              int __thiscall GetBlitErrorNum(TDrawSystem * this, long param_1)
    //              int               EAX:4          <RETURN>
    //              TDrawSystem *     ECX:4 (auto)   this
    //              long              Stack[0x4]:4   param_1                   XREF[1]:     00443990(R)  
    //                               ?GetBlitErrorNum@TDrawSystem@@QAEHJ@Z                        XREF[1]:     Copy:00445090(c)  
    //                               TDrawSystem::GetBlitErrorNum
    //                              Drawarea.cpp:1472 (24)
    //         00443990     MOV        EAX,dword ptr [ESP + param_1]
    //         00443994     CMP        EAX,0x80004005
    //         00443999     JG         LAB_004439b8
    //         0044399b     JZ         LAB_004439b0
    //         0044399d     CMP        EAX,0x80004001
    //         004439a2     JNZ        LAB_00443aaf
    //                              Drawarea.cpp:1490 (5)
    //         004439a8     MOV        EAX,0x8a3
    //                              Drawarea.cpp:1502 (3)
    //         004439ad     RET        0x4
    //                               LAB_004439b0                                                 XREF[1]:     0044399b(j)  
    //                              Drawarea.cpp:1479 (5)
    //         004439b0     MOV        EAX,0x898
    //                              Drawarea.cpp:1502 (3)
    //         004439b5     RET        0x4
    //                               LAB_004439b8                                                 XREF[1]:     00443999(j)  
    //                              Drawarea.cpp:1475 (20)
    //         004439b8     CMP        EAX,0x8876006e
    //         004439bd     JG         LAB_004439dc
    //         004439bf     JZ         LAB_004439d4
    //         004439c1     CMP        EAX,0x80070057
    //         004439c6     JNZ        LAB_00443aaf
    //                              Drawarea.cpp:1481 (5)
    //         004439cc     MOV        EAX,0x89a
    //                              Drawarea.cpp:1502 (3)
    //         004439d1     RET        0x4
    //                               LAB_004439d4                                                 XREF[1]:     004439bf(j)  
    //                              Drawarea.cpp:1483 (5)
    //         004439d4     MOV        EAX,0x89c
    //                              Drawarea.cpp:1502 (3)
    //         004439d9     RET        0x4
    //                               LAB_004439dc                                                 XREF[1]:     004439bd(j)  
    //                              Drawarea.cpp:1475 (20)
    //         004439dc     CMP        EAX,0x88760096
    //         004439e1     JG         LAB_00443a00
    //         004439e3     JZ         LAB_004439f8
    //         004439e5     CMP        EAX,0x88760082
    //         004439ea     JNZ        LAB_00443aaf
    //                              Drawarea.cpp:1480 (5)
    //         004439f0     MOV        EAX,0x899
    //                              Drawarea.cpp:1502 (3)
    //         004439f5     RET        0x4
    //                               LAB_004439f8                                                 XREF[1]:     004439e3(j)  
    //                              Drawarea.cpp:1484 (5)
    //         004439f8     MOV        EAX,0x89d
    //                              Drawarea.cpp:1502 (3)
    //         004439fd     RET        0x4
    //                               LAB_00443a00                                                 XREF[1]:     004439e1(j)  
    //                              Drawarea.cpp:1475 (20)
    //         00443a00     CMP        EAX,0x887600cd
    //         00443a05     JG         LAB_00443a24
    //         00443a07     JZ         LAB_00443a1c
    //         00443a09     CMP        EAX,0x887600b4
    //         00443a0e     JNZ        LAB_00443aaf
    //                              Drawarea.cpp:1485 (5)
    //         00443a14     MOV        EAX,0x89e
    //                              Drawarea.cpp:1502 (3)
    //         00443a19     RET        0x4
    //                               LAB_00443a1c                                                 XREF[1]:     00443a07(j)  
    //                              Drawarea.cpp:1487 (5)
    //         00443a1c     MOV        EAX,0x8a0
    //                              Drawarea.cpp:1502 (3)
    //         00443a21     RET        0x4
    //                               LAB_00443a24                                                 XREF[1]:     00443a05(j)  
    //                              Drawarea.cpp:1475 (16)
    //         00443a24     CMP        EAX,0x88760118
    //         00443a29     JG         LAB_00443a44
    //         00443a2b     JZ         LAB_00443a3c
    //         00443a2d     CMP        EAX,0x887600fa
    //         00443a32     JNZ        LAB_00443aaf
    //                              Drawarea.cpp:1491 (5)
    //         00443a34     MOV        EAX,0x8a4
    //                              Drawarea.cpp:1502 (3)
    //         00443a39     RET        0x4
    //                               LAB_00443a3c                                                 XREF[1]:     00443a2b(j)  
    //                              Drawarea.cpp:1492 (5)
    //         00443a3c     MOV        EAX,0x8a5
    //                              Drawarea.cpp:1502 (3)
    //         00443a41     RET        0x4
    //                               LAB_00443a44                                                 XREF[1]:     00443a29(j)  
    //                              Drawarea.cpp:1475 (16)
    //         00443a44     CMP        EAX,0x88760136
    //         00443a49     JG         LAB_00443a64
    //         00443a4b     JZ         LAB_00443a5c
    //         00443a4d     CMP        EAX,0x88760122
    //         00443a52     JNZ        LAB_00443aaf
    //                              Drawarea.cpp:1493 (5)
    //         00443a54     MOV        EAX,0x8a6
    //                              Drawarea.cpp:1502 (3)
    //         00443a59     RET        0x4
    //                               LAB_00443a5c                                                 XREF[1]:     00443a4b(j)  
    //                              Drawarea.cpp:1494 (5)
    //         00443a5c     MOV        EAX,0x8a7
    //                              Drawarea.cpp:1502 (3)
    //         00443a61     RET        0x4
    //                               LAB_00443a64                                                 XREF[1]:     00443a49(j)  
    //                              Drawarea.cpp:1475 (16)
    //         00443a64     CMP        EAX,0x887601ae
    //         00443a69     JG         LAB_00443a84
    //         00443a6b     JZ         LAB_00443a7c
    //         00443a6d     CMP        EAX,0x88760154
    //         00443a72     JNZ        LAB_00443aaf
    //                              Drawarea.cpp:1482 (5)
    //         00443a74     MOV        EAX,0x89b
    //                              Drawarea.cpp:1502 (3)
    //         00443a79     RET        0x4
    //                               LAB_00443a7c                                                 XREF[1]:     00443a6b(j)  
    //                              Drawarea.cpp:1495 (5)
    //         00443a7c     MOV        EAX,0x8a8
    //                              Drawarea.cpp:1502 (3)
    //         00443a81     RET        0x4
    //                               LAB_00443a84                                                 XREF[1]:     00443a69(j)  
    //                              Drawarea.cpp:1475 (16)
    //         00443a84     CMP        EAX,0x8876023f
    //         00443a89     JG         LAB_00443aa4
    //         00443a8b     JZ         LAB_00443a9c
    //         00443a8d     CMP        EAX,0x887601c2
    //         00443a92     JNZ        LAB_00443aaf
    //                              Drawarea.cpp:1489 (5)
    //         00443a94     MOV        EAX,0x8a2
    //                              Drawarea.cpp:1502 (3)
    //         00443a99     RET        0x4
    //                               LAB_00443a9c                                                 XREF[1]:     00443a8b(j)  
    //                              Drawarea.cpp:1486 (5)
    //         00443a9c     MOV        EAX,0x89f
    //                              Drawarea.cpp:1502 (3)
    //         00443aa1     RET        0x4
    //                               LAB_00443aa4                                                 XREF[1]:     00443a89(j)  
    //                              Drawarea.cpp:1475 (11)
    //         00443aa4     CMP        EAX,0x88760240
    //         00443aa9     JZ         LAB_00443abc
    //         00443aab     TEST       EAX,EAX
    //         00443aad     JZ         LAB_00443ab7
    //                               LAB_00443aaf                                                 XREF[8]:     004439a2(j), 004439c6(j), 
    //                                                                                                         004439ea(j), 00443a0e(j), 
    //                                                                                                         00443a32(j), 00443a52(j), 
    //                                                                                                         00443a72(j), 00443a92(j)  
    //                              Drawarea.cpp:1497 (5)
    //         00443aaf     MOV        EAX,0x8fb
    //                              Drawarea.cpp:1502 (3)
    //         00443ab4     RET        0x4
    //                               LAB_00443ab7                                                 XREF[1]:     00443aad(j)  
    //                              Drawarea.cpp:1477 (2)
    //         00443ab7     XOR        EAX,EAX
    //                              Drawarea.cpp:1502 (3)
    //         00443ab9     RET        0x4
    //                               LAB_00443abc                                                 XREF[1]:     00443aa9(j)  
    //                              Drawarea.cpp:1488 (5)
    //         00443abc     MOV        EAX,0x8a1
    //                              Drawarea.cpp:1502 (3)
    //         00443ac1     RET        0x4
}

// Offset: 0x00443AD0
int GetCreateErrorNum(TDrawSystem* this_, long param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall TDrawSystem::GetCreateErrorNum(long)                                           *
    //                              *********************************************************************************************************
    //                              int __thiscall GetCreateErrorNum(TDrawSystem * this, long param_1)
    //              int               EAX:4          <RETURN>
    //              TDrawSystem *     ECX:4 (auto)   this
    //              long              Stack[0x4]:4   param_1                   XREF[1]:     00443ad0(R)  
    //                               ?GetCreateErrorNum@TDrawSystem@@QAEHJ@Z                      XREF[1]:     SetSize:004445ad(c)  
    //                               TDrawSystem::GetCreateErrorNum
    //                              Drawarea.cpp:1509 (24)
    //         00443ad0     MOV        EAX,dword ptr [ESP + param_1]
    //         00443ad4     CMP        EAX,0x8007000e
    //         00443ad9     JG         LAB_00443af8
    //         00443adb     JZ         LAB_00443af0
    //         00443add     CMP        EAX,0x80004005
    //         00443ae2     JNZ        LAB_00443bd6
    //                              Drawarea.cpp:1516 (5)
    //         00443ae8     MOV        EAX,0x8fc
    //                              Drawarea.cpp:1538 (3)
    //         00443aed     RET        0x4
    //                               LAB_00443af0                                                 XREF[1]:     00443adb(j)  
    //                              Drawarea.cpp:1529 (5)
    //         00443af0     MOV        EAX,0x908
    //                              Drawarea.cpp:1538 (3)
    //         00443af5     RET        0x4
    //                               LAB_00443af8                                                 XREF[1]:     00443ad9(j)  
    //                              Drawarea.cpp:1512 (20)
    //         00443af8     CMP        EAX,0x8876005f
    //         00443afd     JG         LAB_00443b1c
    //         00443aff     JZ         LAB_00443b14
    //         00443b01     CMP        EAX,0x80070057
    //         00443b06     JNZ        LAB_00443bd6
    //                              Drawarea.cpp:1519 (5)
    //         00443b0c     MOV        EAX,0x8fe
    //                              Drawarea.cpp:1538 (3)
    //         00443b11     RET        0x4
    //                               LAB_00443b14                                                 XREF[1]:     00443aff(j)  
    //                              Drawarea.cpp:1532 (5)
    //         00443b14     MOV        EAX,0x90b
    //                              Drawarea.cpp:1538 (3)
    //         00443b19     RET        0x4
    //                               LAB_00443b1c                                                 XREF[1]:     00443afd(j)  
    //                              Drawarea.cpp:1512 (20)
    //         00443b1c     CMP        EAX,0x88760082
    //         00443b21     JG         LAB_00443b40
    //         00443b23     JZ         LAB_00443b38
    //         00443b25     CMP        EAX,0x88760064
    //         00443b2a     JNZ        LAB_00443bd6
    //                              Drawarea.cpp:1523 (5)
    //         00443b30     MOV        EAX,0x902
    //                              Drawarea.cpp:1538 (3)
    //         00443b35     RET        0x4
    //                               LAB_00443b38                                                 XREF[1]:     00443b23(j)  
    //                              Drawarea.cpp:1518 (5)
    //         00443b38     MOV        EAX,0x8fd
    //                              Drawarea.cpp:1538 (3)
    //         00443b3d     RET        0x4
    //                               LAB_00443b40                                                 XREF[1]:     00443b21(j)  
    //                              Drawarea.cpp:1512 (20)
    //         00443b40     CMP        EAX,0x887600b4
    //         00443b45     JG         LAB_00443b64
    //         00443b47     JZ         LAB_00443b5c
    //         00443b49     CMP        EAX,0x88760091
    //         00443b4e     JNZ        LAB_00443bd6
    //                              Drawarea.cpp:1524 (5)
    //         00443b54     MOV        EAX,0x903
    //                              Drawarea.cpp:1538 (3)
    //         00443b59     RET        0x4
    //                               LAB_00443b5c                                                 XREF[1]:     00443b47(j)  
    //                              Drawarea.cpp:1525 (5)
    //         00443b5c     MOV        EAX,0x904
    //                              Drawarea.cpp:1538 (3)
    //         00443b61     RET        0x4
    //                               LAB_00443b64                                                 XREF[1]:     00443b45(j)  
    //                              Drawarea.cpp:1512 (16)
    //         00443b64     CMP        EAX,0x887600e1
    //         00443b69     JG         LAB_00443b84
    //         00443b6b     JZ         LAB_00443b7c
    //         00443b6d     CMP        EAX,0x887600d4
    //         00443b72     JNZ        LAB_00443bd6
    //                              Drawarea.cpp:1522 (5)
    //         00443b74     MOV        EAX,0x901
    //                              Drawarea.cpp:1538 (3)
    //         00443b79     RET        0x4
    //                               LAB_00443b7c                                                 XREF[1]:     00443b6b(j)  
    //                              Drawarea.cpp:1528 (5)
    //         00443b7c     MOV        EAX,0x907
    //                              Drawarea.cpp:1538 (3)
    //         00443b81     RET        0x4
    //                               LAB_00443b84                                                 XREF[1]:     00443b69(j)  
    //                              Drawarea.cpp:1512 (16)
    //         00443b84     CMP        EAX,0x88760154
    //         00443b89     JG         LAB_00443ba4
    //         00443b8b     JZ         LAB_00443b9c
    //         00443b8d     CMP        EAX,0x887600e6
    //         00443b92     JNZ        LAB_00443bd6
    //                              Drawarea.cpp:1526 (5)
    //         00443b94     MOV        EAX,0x905
    //                              Drawarea.cpp:1538 (3)
    //         00443b99     RET        0x4
    //                               LAB_00443b9c                                                 XREF[1]:     00443b8b(j)  
    //                              Drawarea.cpp:1527 (5)
    //         00443b9c     MOV        EAX,0x906
    //                              Drawarea.cpp:1538 (3)
    //         00443ba1     RET        0x4
    //                               LAB_00443ba4                                                 XREF[1]:     00443b89(j)  
    //                              Drawarea.cpp:1512 (16)
    //         00443ba4     CMP        EAX,0x88760233
    //         00443ba9     JG         LAB_00443bc4
    //         00443bab     JZ         LAB_00443bbc
    //         00443bad     CMP        EAX,0x8876017c
    //         00443bb2     JNZ        LAB_00443bd6
    //                              Drawarea.cpp:1520 (5)
    //         00443bb4     MOV        EAX,0x8ff
    //                              Drawarea.cpp:1538 (3)
    //         00443bb9     RET        0x4
    //                               LAB_00443bbc                                                 XREF[1]:     00443bab(j)  
    //                              Drawarea.cpp:1521 (5)
    //         00443bbc     MOV        EAX,0x900
    //                              Drawarea.cpp:1538 (3)
    //         00443bc1     RET        0x4
    //                               LAB_00443bc4                                                 XREF[1]:     00443ba9(j)  
    //                              Drawarea.cpp:1512 (18)
    //         00443bc4     CMP        EAX,0x88760234
    //         00443bc9     JZ         LAB_00443beb
    //         00443bcb     CMP        EAX,0x88760235
    //         00443bd0     JZ         LAB_00443be3
    //         00443bd2     TEST       EAX,EAX
    //         00443bd4     JZ         LAB_00443bde
    //                               LAB_00443bd6                                                 XREF[7]:     00443ae2(j), 00443b06(j), 
    //                                                                                                         00443b2a(j), 00443b4e(j), 
    //                                                                                                         00443b72(j), 00443b92(j), 
    //                                                                                                         00443bb2(j)  
    //                              Drawarea.cpp:1534 (5)
    //         00443bd6     MOV        EAX,0x95f
    //                              Drawarea.cpp:1538 (3)
    //         00443bdb     RET        0x4
    //                               LAB_00443bde                                                 XREF[1]:     00443bd4(j)  
    //                              Drawarea.cpp:1514 (2)
    //         00443bde     XOR        EAX,EAX
    //                              Drawarea.cpp:1538 (3)
    //         00443be0     RET        0x4
    //                               LAB_00443be3                                                 XREF[1]:     00443bd0(j)  
    //                              Drawarea.cpp:1531 (5)
    //         00443be3     MOV        EAX,0x90a
    //                              Drawarea.cpp:1538 (3)
    //         00443be8     RET        0x4
    //                               LAB_00443beb                                                 XREF[1]:     00443bc9(j)  
    //                              Drawarea.cpp:1530 (5)
    //         00443beb     MOV        EAX,0x909
    //                              Drawarea.cpp:1538 (3)
    //         00443bf0     RET        0x4
}

// Offset: 0x00443C00
int GetColorKeyErrorNum(TDrawSystem* this_, long param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall TDrawSystem::GetColorKeyErrorNum(long)                                         *
    //                              *********************************************************************************************************
    //                              int __thiscall GetColorKeyErrorNum(TDrawSystem * this, long param_1)
    //              int               EAX:4          <RETURN>
    //              TDrawSystem *     ECX:4 (auto)   this
    //              long              Stack[0x4]:4   param_1                   XREF[1]:     00443c00(R)  
    //                               ?GetColorKeyErrorNum@TDrawSystem@@QAEHJ@Z
    //                               TDrawSystem::GetColorKeyErrorNum
    //                              Drawarea.cpp:1545 (20)
    //         00443c00     MOV        EAX,dword ptr [ESP + param_1]
    //         00443c04     CMP        EAX,0x80004005
    //         00443c09     JG         LAB_00443c24
    //         00443c0b     JZ         LAB_00443c1c
    //         00443c0d     CMP        EAX,0x80004001
    //         00443c12     JNZ        LAB_00443c8f
    //                              Drawarea.cpp:1559 (5)
    //         00443c14     MOV        EAX,0x967
    //                              Drawarea.cpp:1566 (3)
    //         00443c19     RET        0x4
    //                               LAB_00443c1c                                                 XREF[1]:     00443c0b(j)  
    //                              Drawarea.cpp:1552 (5)
    //         00443c1c     MOV        EAX,0x960
    //                              Drawarea.cpp:1566 (3)
    //         00443c21     RET        0x4
    //                               LAB_00443c24                                                 XREF[1]:     00443c09(j)  
    //                              Drawarea.cpp:1548 (16)
    //         00443c24     CMP        EAX,0x88760082
    //         00443c29     JG         LAB_00443c44
    //         00443c2b     JZ         LAB_00443c3c
    //         00443c2d     CMP        EAX,0x80070057
    //         00443c32     JNZ        LAB_00443c8f
    //                              Drawarea.cpp:1554 (5)
    //         00443c34     MOV        EAX,0x962
    //                              Drawarea.cpp:1566 (3)
    //         00443c39     RET        0x4
    //                               LAB_00443c3c                                                 XREF[1]:     00443c2b(j)  
    //                              Drawarea.cpp:1553 (5)
    //         00443c3c     MOV        EAX,0x961
    //                              Drawarea.cpp:1566 (3)
    //         00443c41     RET        0x4
    //                               LAB_00443c44                                                 XREF[1]:     00443c29(j)  
    //                              Drawarea.cpp:1548 (16)
    //         00443c44     CMP        EAX,0x887601c2
    //         00443c49     JG         LAB_00443c64
    //         00443c4b     JZ         LAB_00443c5c
    //         00443c4d     CMP        EAX,0x88760104
    //         00443c52     JNZ        LAB_00443c8f
    //                              Drawarea.cpp:1556 (5)
    //         00443c54     MOV        EAX,0x964
    //                              Drawarea.cpp:1566 (3)
    //         00443c59     RET        0x4
    //                               LAB_00443c5c                                                 XREF[1]:     00443c4b(j)  
    //                              Drawarea.cpp:1558 (5)
    //         00443c5c     MOV        EAX,0x966
    //                              Drawarea.cpp:1566 (3)
    //         00443c61     RET        0x4
    //                               LAB_00443c64                                                 XREF[1]:     00443c49(j)  
    //                              Drawarea.cpp:1548 (16)
    //         00443c64     CMP        EAX,0x88760244
    //         00443c69     JG         LAB_00443c84
    //         00443c6b     JZ         LAB_00443c7c
    //         00443c6d     CMP        EAX,0x8876021c
    //         00443c72     JNZ        LAB_00443c8f
    //                              Drawarea.cpp:1560 (5)
    //         00443c74     MOV        EAX,0x968
    //                              Drawarea.cpp:1566 (3)
    //         00443c79     RET        0x4
    //                               LAB_00443c7c                                                 XREF[1]:     00443c6b(j)  
    //                              Drawarea.cpp:1557 (5)
    //         00443c7c     MOV        EAX,0x965
    //                              Drawarea.cpp:1566 (3)
    //         00443c81     RET        0x4
    //                               LAB_00443c84                                                 XREF[1]:     00443c69(j)  
    //                              Drawarea.cpp:1548 (11)
    //         00443c84     CMP        EAX,0x88760250
    //         00443c89     JZ         LAB_00443c9c
    //         00443c8b     TEST       EAX,EAX
    //         00443c8d     JZ         LAB_00443c97
    //                               LAB_00443c8f                                                 XREF[4]:     00443c12(j), 00443c32(j), 
    //                                                                                                         00443c52(j), 00443c72(j)  
    //                              Drawarea.cpp:1562 (5)
    //         00443c8f     MOV        EAX,0x9c3
    //                              Drawarea.cpp:1566 (3)
    //         00443c94     RET        0x4
    //                               LAB_00443c97                                                 XREF[1]:     00443c8d(j)  
    //                              Drawarea.cpp:1550 (2)
    //         00443c97     XOR        EAX,EAX
    //                              Drawarea.cpp:1566 (3)
    //         00443c99     RET        0x4
    //                               LAB_00443c9c                                                 XREF[1]:     00443c89(j)  
    //                              Drawarea.cpp:1555 (5)
    //         00443c9c     MOV        EAX,0x963
    //                              Drawarea.cpp:1566 (3)
    //         00443ca1     RET        0x4
}

// Offset: 0x00443CB0
void SetPalette(TDrawSystem* this_, void* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TDrawSystem::SetPalette(void *)                                               *
    //                              *********************************************************************************************************
    //                              void __thiscall SetPalette(TDrawSystem * this, void * param_1)
    //              void              <VOID>         <RETURN>
    //              TDrawSystem *     ECX:4 (auto)   this
    //              void *            Stack[0x4]:4   param_1                   XREF[1]:     00443cb0(R)  
    //              undefined1        Stack[-0x4]:1  local_4                   XREF[1]:     00443d14(W)  
    //              tagPALETTEENTR    Stack[-0x404   color_table               XREF[0,11]:  00443cc7(*), 00443ce4(W), 00443cf5(*), 00443d04(W), 
    //                                                                                     00443cdb(*), 00443ce7(*), 00443d08(W), 00443ce9(W), 
    //                                                                                     00443d0c(W), 00443cec(W), 00443d10(W)  
    //                               ?SetPalette@TDrawSystem@@QAEXPAX@Z                           XREF[6]:     set_focus:00469ea6(c), 
    //                               TDrawSystem::SetPalette                                                   do_command_game:0050a3ae(c), 
    //                                                                                                         start_video:005239ab(c), 
    //                                                                                                         stop_video:00523bdc(c), 
    //                                                                                                         shutdown_video_system:0052a476(c), 
    //                                                                                                         shutdown_video_system:0052a4b8(c)  
    //                              Drawarea.cpp:1572 (14)
    //         00443cb0     MOV        EAX,dword ptr [ESP + param_1]
    //         00443cb4     SUB        ESP,0x400
    //         00443cba     PUSH       EBX
    //         00443cbb     PUSH       ESI
    //         00443cbc     MOV        ESI,this
    //                              Drawarea.cpp:1579 (9)
    //         00443cbe     XOR        EBX,EBX
    //         00443cc0     CMP        EAX,EBX
    //         00443cc2     MOV        dword ptr [ESI + 0x8],EAX
    //         00443cc5     JZ         LAB_00443cdb
    //                              Drawarea.cpp:1580 (18)
    //         00443cc7     LEA        this=>color_table[1],[ESP + 0x8]
    //         00443ccb     PUSH       this
    //         00443ccc     PUSH       0x100
    //         00443cd1     PUSH       EBX
    //         00443cd2     PUSH       EAX
    //         00443cd3     CALL       dword ptr [->GDI32.DLL::GetPaletteEntries]       = 0048b270
    //                              Drawarea.cpp:1581 (2)
    //         00443cd9     JMP        LAB_00443cf5
    //                               LAB_00443cdb                                                 XREF[1]:     00443cc5(j)  
    //                              Drawarea.cpp:1603 (26)
    //         00443cdb     LEA        EAX=>color_table[1].peGreen,[ESP + 0x9]
    //         00443cdf     MOV        this,0x100
    //                               LAB_00443ce4                                                 XREF[1]:     00443cf3(j)  
    //         00443ce4     MOV        byte ptr [EAX + color_table[1].peRed],BL
    //         00443ce7     MOV        byte ptr [EAX]=>color_table[1].peGreen,BL
    //         00443ce9     MOV        byte ptr [EAX + color_table[1].peBlue],BL
    //         00443cec     MOV        byte ptr [EAX + color_table[1].peFlags],BL
    //         00443cef     ADD        EAX,0x4
    //         00443cf2     DEC        this
    //         00443cf3     JNZ        LAB_00443ce4
    //                               LAB_00443cf5                                                 XREF[1]:     00443cd9(j)  
    //                              Drawarea.cpp:1602 (64)
    //         00443cf5     LEA        EDX=>color_table[1],[ESP + 0x8]
    //         00443cf9     MOV        AL,0xff
    //         00443cfb     PUSH       EDX
    //         00443cfc     PUSH       0x100
    //         00443d01     PUSH       EBX
    //         00443d02     MOV        this,ESI
    //         00443d04     MOV        byte ptr [ESP + color_table[1].peRed],BL
    //         00443d08     MOV        byte ptr [ESP + color_table[1].peGreen],BL
    //         00443d0c     MOV        byte ptr [ESP + color_table[1].peBlue],BL
    //         00443d10     MOV        byte ptr [ESP + color_table[1].peFlags],BL
    //         00443d14     MOV        byte ptr [ESP + local_4],AL
    //         00443d1b     MOV        byte ptr [ESP + 0x411],AL
    //         00443d22     MOV        byte ptr [ESP + 0x412],AL
    //         00443d29     MOV        byte ptr [ESP + 0x413],BL
    //         00443d30     CALL       TDrawSystem::ModifyPalette                       void ModifyPalette(TDrawSystem * this, int pa
    //                              Drawarea.cpp:1603 (11)
    //         00443d35     POP        ESI
    //         00443d36     POP        EBX
    //         00443d37     ADD        ESP,0x400
    //         00443d3d     RET        0x4
}

// Offset: 0x00443D40
void ModifyPalette(TDrawSystem* this_, int param_2, int param_3, tagPALETTEENTRY* param_4) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TDrawSystem::ModifyPalette(int,int,struct tagPALETTEENTRY *)                  *
    //                              *********************************************************************************************************
    //                              void __thiscall ModifyPalette(TDrawSystem * this, int param_1, int p
    //              void              <VOID>         <RETURN>
    //              TDrawSystem *     ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     00443d66(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[3]:     00443d41(R), 00443d9c(R), 00443dbe(R)  
    //              tagPALETTEENTR    Stack[0xc]:4   param_3                   XREF[1]:     00443d6a(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     00443d50(W), 00443d98(R)  
    //                               ?ModifyPalette@TDrawSystem@@QAEXHHPAUtagPALETTEENTRY@@@Z     XREF[7]:     wnd_proc:004209fe(c), 
    //                               TDrawSystem::ModifyPalette                                                handle_idle:00420fd7(c), 
    //                                                                                                         handle_palette_changed:00421a47(c)
    //                                                                                                         HandleQueryNewPalette:00443509(c), 
    //                                                                                                         SetPalette:00443d30(c), 
    //                                                                                                         SetPalette:004463a5(c), 
    //                                                                                                         handle_anim_pal:0049b8ed(c)  
    //                              Drawarea.cpp:1610 (1)
    //         00443d40     PUSH       this
    //                              Drawarea.cpp:1623 (37)
    //         00443d41     MOV        EAX,dword ptr [ESP + param_2]
    //         00443d45     PUSH       EBX
    //         00443d46     PUSH       EBP
    //         00443d47     PUSH       ESI
    //         00443d48     MOV        ESI,this
    //         00443d4a     CMP        EAX,0x100
    //         00443d4f     PUSH       EDI
    //         00443d50     MOV        dword ptr [ESP + local_4],ESI
    //         00443d54     MOV        dword ptr [PalSetRes],0xffffff9d
    //         00443d5e     JNZ        LAB_00443d66
    //         00443d60     INC        dword ptr [FullPalSets]
    //                               LAB_00443d66                                                 XREF[1]:     00443d5e(j)  
    //                              Drawarea.cpp:1627 (30)
    //         00443d66     MOV        this,dword ptr [ESP + param_1]
    //         00443d6a     MOV        EBP,dword ptr [ESP + param_3]
    //         00443d6e     LEA        EBX,[EAX + this->Inst*0x1]
    //         00443d71     CMP        this,EBX
    //         00443d73     JGE        LAB_00443da0
    //         00443d75     LEA        EDI,[this->Inst*0x4 + 0x0]
    //         00443d7c     LEA        ESI,[ESI + this->Inst*0x4 + 0x78]
    //         00443d80     MOV        EDX,EDI
    //         00443d82     SUB        EBX,this
    //                               LAB_00443d84                                                 XREF[1]:     00443d96(j)  
    //                              Drawarea.cpp:1629 (28)
    //         00443d84     MOV        EAX,EDX
    //         00443d86     ADD        EDX,0x4
    //         00443d89     SUB        EAX,EDI
    //         00443d8b     ADD        ESI,0x4
    //         00443d8e     DEC        EBX
    //         00443d8f     MOV        EAX,dword ptr [EBP + EAX*0x1]
    //         00443d93     MOV        dword ptr [ESI + -0x4],EAX
    //         00443d96     JNZ        LAB_00443d84
    //         00443d98     MOV        ESI,dword ptr [ESP + local_4]
    //         00443d9c     MOV        EAX,dword ptr [ESP + param_2]
    //                               LAB_00443da0                                                 XREF[1]:     00443d73(j)  
    //                              Drawarea.cpp:1632 (9)
    //         00443da0     CMP        byte ptr [ESI + 0x478],0x1
    //         00443da7     JZ         LAB_00443dcd
    //                              Drawarea.cpp:1654 (7)
    //         00443da9     MOV        EDX,dword ptr [ESI + 0x24]
    //         00443dac     TEST       EDX,EDX
    //         00443dae     JZ         LAB_00443dcd
    //                              Drawarea.cpp:1656 (11)
    //         00443db0     CMP        EAX,0x7
    //         00443db3     JNZ        LAB_00443dbb
    //         00443db5     INC        dword ptr [AniPalSets]
    //                               LAB_00443dbb                                                 XREF[1]:     00443db3(j)  
    //                              Drawarea.cpp:1674 (18)
    //         00443dbb     MOV        EAX,dword ptr [ESI + 0x24]
    //         00443dbe     MOV        ESI,dword ptr [ESP + param_2]
    //         00443dc2     PUSH       EBP
    //         00443dc3     PUSH       ESI
    //         00443dc4     MOV        EDX,dword ptr [EAX]
    //         00443dc6     PUSH       this
    //         00443dc7     PUSH       0x0
    //         00443dc9     PUSH       EAX
    //         00443dca     CALL       dword ptr [EDX + 0x18]
    //                               LAB_00443dcd                                                 XREF[2]:     00443da7(j), 00443dae(j)  
    //                              Drawarea.cpp:1680 (8)
    //         00443dcd     POP        EDI
    //         00443dce     POP        ESI
    //         00443dcf     POP        EBP
    //         00443dd0     POP        EBX
    //         00443dd1     POP        this
    //         00443dd2     RET        0xc
}

// Offset: 0x00443DE0
undefined TDrawArea(TDrawArea* this_, char* param_2, int param_3) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall TDrawArea::TDrawArea(char *,int)                                                   *
    //                              *********************************************************************************************************
    //                              undefined __thiscall TDrawArea(TDrawArea * this, char * param_1, int
    //              undefined         <UNASSIGNED>   <RETURN>
    //              TDrawArea *       ECX:4 (auto)   this
    //              char *            Stack[0x4]:4   param_1                   XREF[1]:     00443e94(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     00443de0(R)  
    //                               ??0TDrawArea@@QAE@PADH@Z                                     XREF[11]:    setup_map_save_area:00422f30(c), 
    //                               TDrawArea::TDrawArea                                                      create_surfaces:0043716e(c), 
    //                                                                                                         CreateSurfaces:0044324a(c), 
    //                                                                                                         CreateSurfaces:00443329(c), 
    //                                                                                                         create_surfaces:0045b644(c), 
    //                                                                                                         create_surfaces:0045b6f1(c), 
    //                                                                                                         setup_shadow_area:0046742c(c), 
    //                                                                                                         set_rect:00479197(c), 
    //                                                                                                         set_rect:0051cef7(c), 
    //                                                                                                         set_rect:0051d9f7(c), 
    //                                                                                                         create_surfaces:0053419e(c)  
    //                              Drawarea.cpp:1686 (17)
    //         00443de0     MOV        EAX,dword ptr [ESP + param_2]
    //         00443de4     PUSH       EBX
    //         00443de5     PUSH       EBP
    //         00443de6     MOV        EBX,this
    //         00443de8     PUSH       ESI
    //         00443de9     XOR        ESI,ESI
    //         00443deb     PUSH       EDI
    //         00443dec     MOV        dword ptr [EBX],ESI
    //         00443dee     MOV        dword ptr [EBX + 0x4],ESI
    //                              Drawarea.cpp:1724 (151)
    //         00443df1     PUSH       0x6c
    //         00443df3     LEA        this,[EBX + 0x40]
    //         00443df6     MOV        dword ptr [EBX + 0x3c],ESI
    //         00443df9     PUSH       ESI
    //         00443dfa     MOV        dword ptr [EBX + 0xe8],ESI
    //         00443e00     PUSH       this
    //         00443e01     MOV        dword ptr [EBX + 0x38],ESI
    //         00443e04     MOV        dword ptr [EBX + 0xc],ESI
    //         00443e07     MOV        dword ptr [EBX + 0x10],ESI
    //         00443e0a     MOV        dword ptr [EBX + 0x14],ESI
    //         00443e0d     MOV        dword ptr [EBX + 0x8],ESI
    //         00443e10     MOV        dword ptr [EBX + 0x18],ESI
    //         00443e13     MOV        dword ptr [EBX + 0x1c],ESI
    //         00443e16     MOV        dword ptr [EBX + 0x20],ESI
    //         00443e19     MOV        dword ptr [EBX + 0xec],ESI
    //         00443e1f     MOV        byte ptr [EBX + 0xfc],0xff
    //         00443e26     MOV        dword ptr [EBX + 0xac],ESI
    //         00443e2c     MOV        dword ptr [EBX + 0xf4],ESI
    //         00443e32     MOV        dword ptr [EBX + 0xf0],ESI
    //         00443e38     MOV        dword ptr [EBX + 0xe4],EAX
    //         00443e3e     MOV        dword ptr [EBX + 0x28],ESI
    //         00443e41     MOV        dword ptr [EBX + 0x2c],ESI
    //         00443e44     MOV        dword ptr [EBX + 0x30],ESI
    //         00443e47     MOV        dword ptr [EBX + 0x34],ESI
    //         00443e4a     MOV        dword ptr [EBX + 0xb4],ESI
    //         00443e50     MOV        dword ptr [EBX + 0xbc],ESI
    //         00443e56     MOV        dword ptr [EBX + 0xc0],ESI
    //         00443e5c     MOV        dword ptr [EBX + 0xdc],ESI
    //         00443e62     MOV        dword ptr [EBX + 0xf8],ESI
    //         00443e68     MOV        dword ptr [EBX + 0xc4],ESI
    //         00443e6e     MOV        dword ptr [EBX + 0xd4],ESI
    //         00443e74     MOV        dword ptr [EBX + 0xd8],ESI
    //         00443e7a     MOV        dword ptr [EBX + 0xe0],ESI
    //         00443e80     CALL       memset                                           undefined memset()
    //         00443e85     ADD        ESP,0xc
    //                              Drawarea.cpp:1726 (12)
    //         00443e88     PUSH       0x428
    //         00443e8d     PUSH       0x1
    //         00443e8f     CALL       calloc                                           undefined calloc()
    //                              Drawarea.cpp:1734 (47)
    //         00443e94     MOV        EBP,dword ptr [ESP + param_1]
    //         00443e98     MOV        dword ptr [EBX + 0xc],EAX
    //         00443e9b     MOV        EDI,EBP
    //         00443e9d     OR         this,0xffffffff
    //         00443ea0     XOR        EAX,EAX
    //         00443ea2     ADD        ESP,0x8
    //         00443ea5     MOV        dword ptr [EBX + 0x24],0x1
    //         00443eac     MOV        dword ptr [EBX + 0xcc],ESI
    //         00443eb2     MOV        dword ptr [EBX + 0xd0],ESI
    //         00443eb8     MOV        dword ptr [EBX + 0xc8],ESI
    //         00443ebe     SCASB.RE   ES:EDI
    //         00443ec0     NOT        this
    //         00443ec2     DEC        this
    //                              Drawarea.cpp:1735 (4)
    //         00443ec3     CMP        this,ESI
    //         00443ec5     JLE        LAB_00443f01
    //                              Drawarea.cpp:1737 (9)
    //         00443ec7     INC        this
    //         00443ec8     PUSH       this
    //         00443ec9     CALL       malloc                                           undefined malloc()
    //         00443ece     MOV        EDX,EAX
    //                              Drawarea.cpp:1738 (35)
    //         00443ed0     MOV        EDI,EBP
    //         00443ed2     OR         this,0xffffffff
    //         00443ed5     XOR        EAX,EAX
    //         00443ed7     ADD        ESP,0x4
    //         00443eda     MOV        dword ptr [EBX + 0xb0],EDX
    //         00443ee0     SCASB.RE   ES:EDI
    //         00443ee2     NOT        this
    //         00443ee4     SUB        EDI,this
    //         00443ee6     MOV        EAX,this
    //         00443ee8     MOV        ESI,EDI
    //         00443eea     MOV        EDI,EDX
    //         00443eec     SHR        this,0x2
    //         00443eef     MOVSD.REP  ES:EDI,ESI
    //         00443ef1     MOV        this,EAX
    //                              Drawarea.cpp:1745 (14)
    //         00443ef3     MOV        EAX,EBX
    //         00443ef5     AND        this,0x3
    //         00443ef8     MOVSB.REP  ES:EDI,ESI
    //         00443efa     POP        EDI
    //         00443efb     POP        ESI
    //         00443efc     POP        EBP
    //         00443efd     POP        EBX
    //         00443efe     RET        0x8
    //                               LAB_00443f01                                                 XREF[1]:     00443ec5(j)  
    //                              Drawarea.cpp:1741 (6)
    //         00443f01     MOV        dword ptr [EBX + 0xb0],ESI
    //                              Drawarea.cpp:1745 (9)
    //         00443f07     POP        EDI
    //         00443f08     POP        ESI
    //         00443f09     MOV        EAX,EBX
    //         00443f0b     POP        EBP
    //         00443f0c     POP        EBX
    //         00443f0d     RET        0x8
}

// Offset: 0x00443F10
void TDrawArea(TDrawArea* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall TDrawArea::~TDrawArea(void)                                                        *
    //                              *********************************************************************************************************
    //                              void __thiscall ~TDrawArea(TDrawArea * this)
    //              void              <VOID>         <RETURN>
    //              TDrawArea *       ECX:4 (auto)   this
    //                               ??1TDrawArea@@QAE@XZ                                         XREF[16]:    ~RGE_Base_Game:0041c48d(c), 
    //                               TDrawArea::~TDrawArea                                                     setup_map_save_area:00422f85(c), 
    //                                                                                                         delete_surfaces:004370de(c), 
    //                                                                                                         create_surfaces:004371c3(c), 
    //                                                                                                         DeleteSurfaces:0044309d(c), 
    //                                                                                                         DeleteSurfaces:004430c2(c), 
    //                                                                                                         delete_surfaces:0045b576(c), 
    //                                                                                                         delete_surfaces:0045b597(c), 
    //                                                                                                         prepare_for_close:004672b3(c), 
    //                                                                                                         ~TMessagePanel:004790a3(c), 
    //                                                                                                         set_rect:00479162(c), 
    //                                                                                                         ~TRIBE_Panel_Pop:0051ce03(c), 
    //                                                                                                         set_rect:0051cec2(c), 
    //                                                                                                         ~TRIBE_Panel_Time:0051d903(c), 
    //                                                                                                         set_rect:0051d9c2(c), 
    //                                                                                                         delete_surfaces:00534110(c)  
    //                              Drawarea.cpp:1751 (4)
    //         00443f10     PUSH       ESI
    //         00443f11     MOV        ESI,this
    //         00443f13     PUSH       EDI
    //                              Drawarea.cpp:1763 (10)
    //         00443f14     MOV        this,dword ptr [ESI + 0xac]
    //         00443f1a     TEST       this,this
    //         00443f1c     JZ         LAB_00443f6e
    //                              Drawarea.cpp:1765 (11)
    //         00443f1e     MOV        EAX,dword ptr [ESI]
    //         00443f20     TEST       EAX,EAX
    //         00443f22     JZ         LAB_00443f2f
    //         00443f24     CMP        this,dword ptr [EAX + 0x14]
    //         00443f27     JNZ        LAB_00443f2f
    //                              Drawarea.cpp:1766 (6)
    //         00443f29     MOV        this,dword ptr [ECX + this->Bits]
    //         00443f2c     MOV        dword ptr [EAX + 0x14],this
    //                               LAB_00443f2f                                                 XREF[2]:     00443f22(j), 00443f27(j)  
    //                              Drawarea.cpp:1768 (13)
    //         00443f2f     MOV        EAX,dword ptr [ESI + 0xac]
    //         00443f35     MOV        this,dword ptr [EAX + 0x4]
    //         00443f38     TEST       this,this
    //         00443f3a     JZ         LAB_00443f42
    //                              Drawarea.cpp:1769 (6)
    //         00443f3c     MOV        EDX,dword ptr [EAX + 0x8]
    //         00443f3f     MOV        dword ptr [ECX + this->Bits],EDX
    //                               LAB_00443f42                                                 XREF[1]:     00443f3a(j)  
    //                              Drawarea.cpp:1771 (13)
    //         00443f42     MOV        EAX,dword ptr [ESI + 0xac]
    //         00443f48     MOV        this,dword ptr [EAX + 0x8]
    //         00443f4b     TEST       this,this
    //         00443f4d     JZ         LAB_00443f55
    //                              Drawarea.cpp:1772 (6)
    //         00443f4f     MOV        EAX,dword ptr [EAX + 0x4]
    //         00443f52     MOV        dword ptr [ECX + this->Wnd],EAX
    //                               LAB_00443f55                                                 XREF[1]:     00443f4d(j)  
    //                              Drawarea.cpp:1774 (15)
    //         00443f55     MOV        this,dword ptr [ESI + 0xac]
    //         00443f5b     PUSH       this
    //         00443f5c     CALL       free                                             undefined free()
    //         00443f61     ADD        ESP,0x4
    //                              Drawarea.cpp:1775 (10)
    //         00443f64     MOV        dword ptr [ESI + 0xac],0x0
    //                               LAB_00443f6e                                                 XREF[1]:     00443f1c(j)  
    //                              Drawarea.cpp:1778 (15)
    //         00443f6e     MOV        EAX,dword ptr [ESI]
    //         00443f70     TEST       EAX,EAX
    //         00443f72     JZ         LAB_00443fb0
    //         00443f74     CMP        byte ptr [EAX + 0x478],0x1
    //         00443f7b     JNZ        LAB_00443fb0
    //                              Drawarea.cpp:1780 (7)
    //         00443f7d     MOV        this,dword ptr [ESI + 0x38]
    //         00443f80     TEST       this,this
    //         00443f82     JZ         LAB_00443fce
    //                              Drawarea.cpp:1782 (7)
    //         00443f84     MOV        EAX,dword ptr [ESI + 0x10]
    //         00443f87     TEST       EAX,EAX
    //         00443f89     JZ         LAB_00443fa4
    //                              Drawarea.cpp:1784 (7)
    //         00443f8b     MOV        EAX,dword ptr [ESI + 0x14]
    //         00443f8e     TEST       EAX,EAX
    //         00443f90     JZ         LAB_00443f9a
    //                              Drawarea.cpp:1785 (8)
    //         00443f92     PUSH       EAX
    //         00443f93     PUSH       this
    //         00443f94     CALL       dword ptr [->GDI32.DLL::SelectObject]            = 0048b192
    //                               LAB_00443f9a                                                 XREF[1]:     00443f90(j)  
    //                              Drawarea.cpp:1786 (10)
    //         00443f9a     MOV        EDX,dword ptr [ESI + 0x10]
    //         00443f9d     PUSH       EDX
    //         00443f9e     CALL       dword ptr [->GDI32.DLL::DeleteObject]            = 0048b160
    //                               LAB_00443fa4                                                 XREF[1]:     00443f89(j)  
    //                              Drawarea.cpp:1788 (10)
    //         00443fa4     MOV        EAX,dword ptr [ESI + 0x38]
    //         00443fa7     PUSH       EAX
    //         00443fa8     CALL       dword ptr [->GDI32.DLL::DeleteDC]                = 0048b1ec
    //                              Drawarea.cpp:1791 (2)
    //         00443fae     JMP        LAB_00443fce
    //                               LAB_00443fb0                                                 XREF[2]:     00443f72(j), 00443f7b(j)  
    //                              Drawarea.cpp:1793 (17)
    //         00443fb0     MOV        EAX,dword ptr [ESI + 0x3c]
    //         00443fb3     TEST       EAX,EAX
    //         00443fb5     JZ         LAB_00443fce
    //         00443fb7     MOV        this,dword ptr [ESI + 0xf0]
    //         00443fbd     TEST       this,this
    //         00443fbf     JNZ        LAB_00443fce
    //                              Drawarea.cpp:1795 (6)
    //         00443fc1     MOV        this,dword ptr [EAX]
    //         00443fc3     PUSH       EAX
    //         00443fc4     CALL       dword ptr [ECX + this->Bits]
    //                              Drawarea.cpp:1797 (7)
    //         00443fc7     MOV        dword ptr [ESI + 0x3c],0x0
    //                               LAB_00443fce                                                 XREF[4]:     00443f82(j), 00443fae(j), 
    //                                                                                                         00443fb5(j), 00443fbf(j)  
    //                              Drawarea.cpp:1801 (7)
    //         00443fce     MOV        EAX,dword ptr [ESI + 0xc]
    //         00443fd1     TEST       EAX,EAX
    //         00443fd3     JZ         LAB_00443fde
    //                              Drawarea.cpp:1802 (9)
    //         00443fd5     PUSH       EAX
    //         00443fd6     CALL       free                                             undefined free()
    //         00443fdb     ADD        ESP,0x4
    //                               LAB_00443fde                                                 XREF[1]:     00443fd3(j)  
    //                              Drawarea.cpp:1804 (19)
    //         00443fde     MOV        EAX,dword ptr [ESI + 0xbc]
    //         00443fe4     TEST       EAX,EAX
    //         00443fe6     JZ         LAB_00443ff1
    //         00443fe8     PUSH       EAX
    //         00443fe9     CALL       free                                             undefined free()
    //         00443fee     ADD        ESP,0x4
    //                               LAB_00443ff1                                                 XREF[1]:     00443fe6(j)  
    //                              Drawarea.cpp:1806 (19)
    //         00443ff1     MOV        EAX,dword ptr [ESI + 0xc4]
    //         00443ff7     TEST       EAX,EAX
    //         00443ff9     JZ         LAB_00444004
    //         00443ffb     PUSH       EAX
    //         00443ffc     CALL       free                                             undefined free()
    //         00444001     ADD        ESP,0x4
    //                               LAB_00444004                                                 XREF[1]:     00443ff9(j)  
    //                              Drawarea.cpp:1808 (26)
    //         00444004     MOV        EDI,dword ptr [ESI + 0xcc]
    //         0044400a     TEST       EDI,EDI
    //         0044400c     JZ         LAB_0044401e
    //         0044400e     MOV        this,EDI
    //         00444010     CALL       TSpan_List_Manager::~TSpan_List_Manager          void ~TSpan_List_Manager(TSpan_List_Manager *
    //         00444015     PUSH       EDI
    //         00444016     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         0044401b     ADD        ESP,0x4
    //                               LAB_0044401e                                                 XREF[1]:     0044400c(j)  
    //                              Drawarea.cpp:1810 (19)
    //         0044401e     MOV        ESI,dword ptr [ESI + 0xb0]
    //         00444024     TEST       ESI,ESI
    //         00444026     JZ         LAB_00444031
    //         00444028     PUSH       ESI
    //         00444029     CALL       free                                             undefined free()
    //         0044402e     ADD        ESP,0x4
    //                               LAB_00444031                                                 XREF[1]:     00444026(j)  
    //                              Drawarea.cpp:1812 (3)
    //         00444031     POP        EDI
    //         00444032     POP        ESI
    //         00444033     RET
}

// Offset: 0x00444040
int Init(TDrawArea* this_, TDrawSystem* param_2, long param_3, long param_4, int param_5, int err) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall TDrawArea::Init(class TDrawSystem *,long,long,int,int)                         *
    //                              *********************************************************************************************************
    //                              int __thiscall Init(TDrawArea * this, TDrawSystem * param_1, long pa
    //              int               EAX:4          <RETURN>
    //              TDrawArea *       ECX:4 (auto)   this
    //              TDrawSystem *     Stack[0x4]:4   param_1                   XREF[1]:     00444040(R)  
    //              long              Stack[0x8]:4   param_2                   XREF[1]:     004440f0(R)  
    //              long              Stack[0xc]:4   param_3                   XREF[1]:     004440ec(R)  
    //              int               Stack[0x10]:4  param_4                   XREF[1]:     004440e8(R)  
    //              int               Stack[0x14]:4  param_5                   XREF[1]:     00444047(R)  
    //                               ?Init@TDrawArea@@QAEHPAVTDrawSystem@@JJHH@Z                  XREF[13]:    setup_map_save_area:00422f70(c), 
    //                               TDrawArea::Init                                                           create_surfaces:004371ae(c), 
    //                                                                                                         CreateSurfaces:004432a6(c), 
    //                                                                                                         CreateSurfaces:004432d5(c), 
    //                                                                                                         CreateSurfaces:00443385(c), 
    //                                                                                                         CreateSurfaces:004433b4(c), 
    //                                                                                                         create_surfaces:0045b683(c), 
    //                                                                                                         create_surfaces:0045b71c(c), 
    //                                                                                                         setup_shadow_area:004674af(c), 
    //                                                                                                         set_rect:004791c0(c), 
    //                                                                                                         set_rect:0051cf20(c), 
    //                                                                                                         set_rect:0051da20(c), 
    //                                                                                                         create_surfaces:005341cd(c)  
    //                              Drawarea.cpp:1818 (7)
    //         00444040     MOV        EAX,dword ptr [ESP + param_1]
    //         00444044     PUSH       ESI
    //         00444045     MOV        ESI,this
    //                              Drawarea.cpp:1824 (4)
    //         00444047     MOV        this,dword ptr [ESP + param_5]
    //                              Drawarea.cpp:1826 (16)
    //         0044404b     TEST       EAX,EAX
    //         0044404d     MOV        dword ptr [ESI],EAX
    //         0044404f     MOV        dword ptr [ESI + 0xf0],this
    //         00444055     JZ         LAB_004440e8
    //                              Drawarea.cpp:1828 (3)
    //         0044405b     MOV        EDX,dword ptr [EAX + 0x4]
    //                              Drawarea.cpp:1830 (13)
    //         0044405e     MOV        EAX,dword ptr [ESI + 0xac]
    //         00444064     TEST       EAX,EAX
    //         00444066     MOV        dword ptr [ESI + 0x4],EDX
    //         00444069     JNZ        LAB_004440d7
    //                              Drawarea.cpp:1833 (18)
    //         0044406b     PUSH       0xc
    //         0044406d     PUSH       0x1
    //         0044406f     CALL       calloc                                           undefined calloc()
    //         00444074     ADD        ESP,0x8
    //         00444077     MOV        dword ptr [ESI + 0xac],EAX
    //                              Drawarea.cpp:1834 (4)
    //         0044407d     TEST       EAX,EAX
    //         0044407f     JNZ        LAB_00444085
    //                              Drawarea.cpp:1874 (4)
    //         00444081     POP        ESI
    //         00444082     RET        0x14
    //                               LAB_00444085                                                 XREF[1]:     0044407f(j)  
    //                              Drawarea.cpp:1836 (2)
    //         00444085     MOV        dword ptr [EAX],ESI
    //                              Drawarea.cpp:1837 (13)
    //         00444087     MOV        EAX,dword ptr [ESI + 0xac]
    //         0044408d     MOV        dword ptr [EAX + 0x4],0x0
    //                              Drawarea.cpp:1838 (13)
    //         00444094     MOV        this,dword ptr [ESI + 0xac]
    //         0044409a     MOV        dword ptr [ECX + this->Bits],0x0
    //                              Drawarea.cpp:1839 (9)
    //         004440a1     MOV        EAX,dword ptr [ESI]
    //         004440a3     MOV        this,dword ptr [EAX + 0x14]
    //         004440a6     TEST       this,this
    //         004440a8     JNZ        LAB_004440b5
    //                              Drawarea.cpp:1840 (9)
    //         004440aa     MOV        EDX,dword ptr [ESI + 0xac]
    //         004440b0     MOV        dword ptr [EAX + 0x14],EDX
    //                              Drawarea.cpp:1841 (2)
    //         004440b3     JMP        LAB_004440d7
    //                               LAB_004440b5                                                 XREF[1]:     004440a8(j)  
    //                              Drawarea.cpp:1844 (7)
    //         004440b5     MOV        EAX,dword ptr [ECX + this->Bits]
    //         004440b8     TEST       EAX,EAX
    //         004440ba     JZ         LAB_004440c5
    //                               LAB_004440bc                                                 XREF[1]:     004440c3(j)  
    //                              Drawarea.cpp:1845 (9)
    //         004440bc     MOV        this,EAX
    //         004440be     MOV        EAX,dword ptr [ECX + this->Bits]
    //         004440c1     TEST       EAX,EAX
    //         004440c3     JNZ        LAB_004440bc
    //                               LAB_004440c5                                                 XREF[1]:     004440ba(j)  
    //                              Drawarea.cpp:1846 (9)
    //         004440c5     MOV        EAX,dword ptr [ESI + 0xac]
    //         004440cb     MOV        dword ptr [ECX + this->Bits],EAX
    //                              Drawarea.cpp:1847 (9)
    //         004440ce     MOV        EDX,dword ptr [ESI + 0xac]
    //         004440d4     MOV        dword ptr [EDX + 0x4],this
    //                               LAB_004440d7                                                 XREF[2]:     00444069(j), 004440b3(j)  
    //                              Drawarea.cpp:1851 (11)
    //         004440d7     MOV        EAX,dword ptr [ESI]
    //         004440d9     CMP        byte ptr [EAX + 0x478],0x1
    //         004440e0     JNZ        LAB_004440e8
    //                              Drawarea.cpp:1866 (2)
    //         004440e2     XOR        EAX,EAX
    //                              Drawarea.cpp:1874 (4)
    //         004440e4     POP        ESI
    //         004440e5     RET        0x14
    //                               LAB_004440e8                                                 XREF[2]:     00444055(j), 004440e0(j)  
    //                              Drawarea.cpp:1871 (22)
    //         004440e8     MOV        this,dword ptr [ESP + param_4]
    //         004440ec     MOV        EDX,dword ptr [ESP + param_3]
    //         004440f0     MOV        EAX,dword ptr [ESP + param_2]
    //         004440f4     PUSH       this
    //         004440f5     PUSH       EDX
    //         004440f6     PUSH       EAX
    //         004440f7     MOV        this,ESI
    //         004440f9     CALL       TDrawArea::SetSize                               void SetSize(TDrawArea * this, long param_1, 
    //                              Drawarea.cpp:1873 (5)
    //         004440fe     MOV        EAX,0x1
    //                              Drawarea.cpp:1874 (4)
    //         00444103     POP        ESI
    //         00444104     RET        0x14
}

// Offset: 0x00444110
uchar CheckSurface(TDrawArea* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: unsigned char __thiscall TDrawArea::CheckSurface(void)                                        *
    //                              *********************************************************************************************************
    //                              uchar __thiscall CheckSurface(TDrawArea * this)
    //              uchar             AL:1           <RETURN>
    //              TDrawArea *       ECX:4 (auto)   this
    //              _DDBLTFX          Stack[-0x68]   ddbltfx
    //              _DDSURFACEDESC    Stack[-0xd4]   ddsd
    //                               ?CheckSurface@TDrawArea@@QAEEXZ                              XREF[1]:     CheckSurfaces:00443046(c)  
    //                               TDrawArea::CheckSurface
    //                              Drawarea.cpp:1880 (10)
    //         00444110     SUB        ESP,0xd0
    //         00444116     PUSH       ESI
    //         00444117     MOV        ESI,this
    //         00444119     PUSH       EDI
    //                              Drawarea.cpp:1887 (4)
    //         0044411a     MOV        EAX,dword ptr [ESI]
    //         0044411c     TEST       EAX,EAX
    //                              Drawarea.cpp:1888 (6)
    //         0044411e     JZ         LAB_00444257
    //                              Drawarea.cpp:1890 (7)
    //         00444124     CMP        byte ptr [EAX + 0x478],0x2
    //                              Drawarea.cpp:1891 (6)
    //         0044412b     JNZ        LAB_00444257
    //                              Drawarea.cpp:1893 (7)
    //         00444131     MOV        EAX,dword ptr [ESI + 0x3c]
    //         00444134     TEST       EAX,EAX
    //         00444136     JNZ        LAB_00444143
    //                              Drawarea.cpp:1894 (2)
    //         00444138     MOV        AL,0x3
    //                              Drawarea.cpp:1949 (9)
    //         0044413a     POP        EDI
    //         0044413b     POP        ESI
    //         0044413c     ADD        ESP,0xd0
    //         00444142     RET
    //                               LAB_00444143                                                 XREF[1]:     00444136(j)  
    //                              Drawarea.cpp:1896 (6)
    //         00444143     MOV        this,dword ptr [EAX]
    //         00444145     PUSH       EAX
    //         00444146     CALL       dword ptr [ECX + this+0x60]
    //                              Drawarea.cpp:1898 (8)
    //         00444149     TEST       EAX,EAX
    //         0044414b     JZ         LAB_00444257
    //                              Drawarea.cpp:1900 (8)
    //         00444151     MOV        this,dword ptr [ESI]
    //         00444153     PUSH       EAX
    //         00444154     CALL       TDrawSystem::GetIsLostErrorNum                   int GetIsLostErrorNum(TDrawSystem * this, lon
    //                              Drawarea.cpp:1905 (14)
    //         00444159     PUSH       0x6c
    //         0044415b     LEA        EDX,[ESP + 0xc]
    //         0044415f     PUSH       0x0=>DAT_fffffff8
    //         00444161     PUSH       EDX=>DAT_fffffff4
    //         00444162     CALL       memset                                           undefined memset()
    //                              Drawarea.cpp:1907 (27)
    //         00444167     MOV        EAX,dword ptr [ESI]
    //         00444169     MOV        dword ptr [ESP + 0x14],0x6c
    //         00444171     ADD        ESP,0xc
    //         00444174     LEA        EDX,[ESP + 0x8]
    //         00444178     MOV        EAX,dword ptr [EAX + 0x18]
    //         0044417b     PUSH       EDX
    //         0044417c     PUSH       EAX=>DAT_fffffff8
    //         0044417d     MOV        this,dword ptr [EAX]
    //         0044417f     CALL       dword ptr [ECX + this+0x30]
    //                              Drawarea.cpp:1909 (4)
    //         00444182     TEST       EAX,EAX
    //         00444184     JNZ        LAB_004441ae
    //                              Drawarea.cpp:1911 (29)
    //         00444186     MOV        EAX,dword ptr [ESI]
    //         00444188     MOV        this,dword ptr [ESP + 0x14]
    //         0044418c     CMP        this,dword ptr [EAX + 0x2c]
    //         0044418f     JNZ        LAB_004441a3
    //         00444191     MOV        EDX,dword ptr [ESP + 0x10]
    //         00444195     MOV        this,dword ptr [EAX + 0x30]
    //         00444198     CMP        EDX,this
    //         0044419a     JNZ        LAB_004441a3
    //         0044419c     CMP        dword ptr [ESP + 0x5c],0x8
    //         004441a1     JZ         LAB_004441ae
    //                               LAB_004441a3                                                 XREF[2]:     0044418f(j), 0044419a(j)  
    //                              Drawarea.cpp:1912 (2)
    //         004441a3     MOV        AL,0x1
    //                              Drawarea.cpp:1949 (9)
    //         004441a5     POP        EDI
    //         004441a6     POP        ESI
    //         004441a7     ADD        ESP,0xd0
    //         004441ad     RET
    //                               LAB_004441ae                                                 XREF[2]:     00444184(j), 004441a1(j)  
    //                              Drawarea.cpp:1915 (11)
    //         004441ae     MOV        EAX,dword ptr [ESI + 0x3c]
    //         004441b1     PUSH       EAX
    //         004441b2     MOV        this,dword ptr [EAX]
    //         004441b4     CALL       dword ptr [ECX + this+0x6c]
    //         004441b7     MOV        EDI,EAX
    //                              Drawarea.cpp:1917 (4)
    //         004441b9     TEST       EDI,EDI
    //         004441bb     JZ         LAB_00444213
    //                              Drawarea.cpp:1919 (16)
    //         004441bd     CMP        EDI,0x8876024b
    //         004441c3     JZ         LAB_004441cd
    //         004441c5     CMP        EDI,0x8007000e
    //         004441cb     JNZ        LAB_00444200
    //                               LAB_004441cd                                                 XREF[1]:     004441c3(j)  
    //                              Drawarea.cpp:1922 (9)
    //         004441cd     MOV        EAX,dword ptr [ESI + 0x3c]
    //         004441d0     PUSH       EAX
    //         004441d1     MOV        EDX,dword ptr [EAX]
    //         004441d3     CALL       dword ptr [EDX + 0x8]
    //                              Drawarea.cpp:1925 (24)
    //         004441d6     MOV        EAX,dword ptr [ESI + 0x1c]
    //         004441d9     MOV        this,dword ptr [ESI + 0x18]
    //         004441dc     PUSH       0x0
    //         004441de     PUSH       EAX=>DAT_fffffff8
    //         004441df     PUSH       this=>DAT_fffffff4
    //         004441e0     MOV        this,ESI
    //         004441e2     MOV        dword ptr [ESI + 0x3c],0x0
    //         004441e9     CALL       TDrawArea::SetSize                               void SetSize(TDrawArea * this, long param_1, 
    //                              Drawarea.cpp:1926 (7)
    //         004441ee     MOV        EAX,dword ptr [ESI + 0x3c]
    //         004441f1     TEST       EAX,EAX
    //         004441f3     JZ         LAB_00444200
    //                              Drawarea.cpp:1927 (2)
    //         004441f5     MOV        AL,0x2
    //                              Drawarea.cpp:1949 (9)
    //         004441f7     POP        EDI
    //         004441f8     POP        ESI
    //         004441f9     ADD        ESP,0xd0
    //         004441ff     RET
    //                               LAB_00444200                                                 XREF[2]:     004441cb(j), 004441f3(j)  
    //                              Drawarea.cpp:1929 (8)
    //         00444200     MOV        this,dword ptr [ESI]
    //         00444202     PUSH       EDI
    //         00444203     CALL       TDrawSystem::GetRestoreErrorNum                  int GetRestoreErrorNum(TDrawSystem * this, lo
    //                              Drawarea.cpp:1935 (2)
    //         00444208     MOV        AL,0x3
    //                              Drawarea.cpp:1949 (9)
    //         0044420a     POP        EDI
    //         0044420b     POP        ESI
    //         0044420c     ADD        ESP,0xd0
    //         00444212     RET
    //                               LAB_00444213                                                 XREF[1]:     004441bb(j)  
    //                              Drawarea.cpp:1941 (47)
    //         00444213     MOV        EAX,dword ptr [ESI + 0x3c]
    //         00444216     LEA        this,[ESP + 0x74]
    //         0044421a     PUSH       this
    //         0044421b     PUSH       offset DAT_fffffff8
    //         00444220     MOV        EDX,dword ptr [EAX]
    //         00444222     PUSH       0x0=>DAT_fffffff4
    //         00444224     PUSH       0x0=>DAT_fffffff0
    //         00444226     PUSH       0x0
    //         00444228     PUSH       EAX
    //         00444229     MOV        dword ptr [ESP + 0x8c],0x64
    //         00444234     MOV        dword ptr [ESP + 0xdc],0x0
    //         0044423f     CALL       dword ptr [EDX + 0x14]
    //                              Drawarea.cpp:1944 (10)
    //         00444242     MOV        dword ptr [ESI + 0xf4],0x1
    //                              Drawarea.cpp:1945 (2)
    //         0044424c     MOV        AL,0x2
    //                              Drawarea.cpp:1949 (20)
    //         0044424e     POP        EDI
    //         0044424f     POP        ESI
    //         00444250     ADD        ESP,0xd0
    //         00444256     RET
    //                               LAB_00444257                                                 XREF[3]:     0044411e(j), 0044412b(j), 
    //                                                                                                         0044414b(j)  
    //         00444257     POP        EDI
    //         00444258     XOR        AL,AL
    //         0044425a     POP        ESI
    //         0044425b     ADD        ESP,0xd0
    //         00444261     RET
}

// Offset: 0x00444270
uchar* Lock(TDrawArea* this_, char* param_2, int param_3) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: unsigned char * __thiscall TDrawArea::Lock(char *,int)                                        *
    //                              *********************************************************************************************************
    //                              uchar * __thiscall Lock(TDrawArea * this, char * param_1, int param_2)
    //              uchar *           EAX:4          <RETURN>
    //              TDrawArea *       ECX:4 (auto)   this
    //              char *            Stack[0x4]:4   param_1
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     004442a3(R)  
    //                               ?Lock@TDrawArea@@QAEPAEPADH@Z                                XREF[55]:    draw:004373e6(c), 
    //                               TDrawArea::Lock                                                           clear_image:004374d3(c), 
    //                                                                                                         draw_all_tiles:00437670(c), 
    //                                                                                                         draw_explored_tiles:00437703(c), 
    //                                                                                                         draw_objects:00437cd5(c), 
    //                                                                                                         PtrClear:00444904(c), 
    //                                                                                                         PtrCopy:0044517f(c), 
    //                                                                                                         PtrCopy:00445196(c), 
    //                                                                                                         LoadCursors:0045b4db(c), 
    //                                                                                                         Poll:0045c261(c), 
    //                                                                                                         setup_shadow_area:004674db(c), 
    //                                                                                                         draw:00472972(c), 
    //                                                                                                         draw:00472e11(c), 
    //                                                                                                         draw:0047789c(c), 
    //                                                                                                         draw_background:0047d3f3(c), 
    //                                                                                                         draw_background:0047d4e2(c), 
    //                                                                                                         draw_border:0047d58b(c), 
    //                                                                                                         draw:004ad16f(c), 
    //                                                                                                         draw_frame_3d_square_front:004c2d2
    //                                                                                                         draw_item:0051c246(c), [more]
    //                              Drawarea.cpp:1955 (3)
    //         00444270     PUSH       ESI
    //         00444271     MOV        ESI,this
    //                              Drawarea.cpp:1956 (13)
    //         00444273     MOV        EAX,dword ptr [ESI]
    //         00444275     TEST       EAX,EAX
    //         00444277     JZ         LAB_00444282
    //         00444279     CMP        byte ptr [EAX + 0x478],0x1
    //                              Drawarea.cpp:1957 (2)
    //         00444280     JZ         LAB_004442ea
    //                               LAB_00444282                                                 XREF[1]:     00444277(j)  
    //                              Drawarea.cpp:1978 (7)
    //         00444282     MOV        this,dword ptr [ESI + 0x3c]
    //         00444285     TEST       this,this
    //         00444287     JNZ        LAB_0044428f
    //                              Drawarea.cpp:1993 (2)
    //         00444289     XOR        EAX,EAX
    //                              Drawarea.cpp:2083 (4)
    //         0044428b     POP        ESI
    //         0044428c     RET        0x8
    //                               LAB_0044428f                                                 XREF[1]:     00444287(j)  
    //                              Drawarea.cpp:1996 (5)
    //         0044428f     MOV        EAX,dword ptr [ESI + 0x8]
    //         00444292     TEST       EAX,EAX
    //                              Drawarea.cpp:2011 (2)
    //         00444294     JNZ        LAB_004442ed
    //                              Drawarea.cpp:2014 (7)
    //         00444296     MOV        EAX,dword ptr [ESI + 0x38]
    //         00444299     TEST       EAX,EAX
    //         0044429b     JZ         LAB_004442a3
    //                              Drawarea.cpp:2029 (2)
    //         0044429d     XOR        EAX,EAX
    //                              Drawarea.cpp:2083 (4)
    //         0044429f     POP        ESI
    //         004442a0     RET        0x8
    //                               LAB_004442a3                                                 XREF[1]:     0044429b(j)  
    //                              Drawarea.cpp:2032 (4)
    //         004442a3     MOV        EAX,dword ptr [ESP + param_2]
    //                              Drawarea.cpp:2033 (10)
    //         004442a7     PUSH       0x0
    //         004442a9     TEST       EAX,EAX
    //         004442ab     MOV        EAX,dword ptr [this->DrawSystem]
    //         004442ad     JZ         LAB_004442b3
    //         004442af     PUSH       0x1
    //                              Drawarea.cpp:2034 (2)
    //         004442b1     JMP        LAB_004442b5
    //                               LAB_004442b3                                                 XREF[1]:     004442ad(j)  
    //                              Drawarea.cpp:2035 (12)
    //         004442b3     PUSH       0x0
    //                               LAB_004442b5                                                 XREF[1]:     004442b1(j)  
    //         004442b5     LEA        EDX,[ESI + 0x40]
    //         004442b8     PUSH       EDX
    //         004442b9     PUSH       0x0
    //         004442bb     PUSH       this
    //         004442bc     CALL       dword ptr [EAX + 0x64]
    //                              Drawarea.cpp:2039 (4)
    //         004442bf     TEST       EAX,EAX
    //         004442c1     JZ         LAB_004442c9
    //                              Drawarea.cpp:2065 (2)
    //         004442c3     XOR        EAX,EAX
    //                              Drawarea.cpp:2083 (4)
    //         004442c5     POP        ESI
    //         004442c6     RET        0x8
    //                               LAB_004442c9                                                 XREF[1]:     004442c1(j)  
    //                              Drawarea.cpp:2068 (3)
    //         004442c9     MOV        EAX,dword ptr [ESI + 0x64]
    //                              Drawarea.cpp:2074 (10)
    //         004442cc     MOV        this,ESI
    //         004442ce     MOV        dword ptr [ESI + 0x8],EAX
    //         004442d1     CALL       TDrawArea::SetInfo                               void SetInfo(TDrawArea * this)
    //                              Drawarea.cpp:2076 (13)
    //         004442d6     MOV        this,dword ptr [ESI + 0x8]
    //         004442d9     MOV        EAX,dword ptr [ESI + 0xb4]
    //         004442df     CMP        this,EAX
    //         004442e1     JZ         LAB_004442ea
    //                              Drawarea.cpp:2078 (7)
    //         004442e3     MOV        this,ESI
    //         004442e5     CALL       TDrawArea::SetAccessOffsets                      void SetAccessOffsets(TDrawArea * this)
    //                               LAB_004442ea                                                 XREF[2]:     00444280(j), 004442e1(j)  
    //                              Drawarea.cpp:2081 (3)
    //         004442ea     MOV        EAX,dword ptr [ESI + 0x8]
    //                               LAB_004442ed                                                 XREF[1]:     00444294(j)  
    //                              Drawarea.cpp:2083 (4)
    //         004442ed     POP        ESI
    //         004442ee     RET        0x8
}

// Offset: 0x00444300
void Unlock(TDrawArea* this_, char* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TDrawArea::Unlock(char *)                                                     *
    //                              *********************************************************************************************************
    //                              void __thiscall Unlock(TDrawArea * this, char * param_1)
    //              void              <VOID>         <RETURN>
    //              TDrawArea *       ECX:4 (auto)   this
    //              char *            Stack[0x4]:4   param_1
    //                               ?Unlock@TDrawArea@@QAEXPAD@Z                                 XREF[61]:    draw:004373ff(c), 
    //                               TDrawArea::Unlock                                                         clear_image:00437601(c), 
    //                                                                                                         draw_all_tiles:004376be(c), 
    //                                                                                                         draw_explored_tiles:0043774e(c), 
    //                                                                                                         draw_objects:00437ea5(c), 
    //                                                                                                         PtrClear:00444976(c), 
    //                                                                                                         PtrCopy:00445230(c), 
    //                                                                                                         PtrCopy:0044523d(c), 
    //                                                                                                         LoadCursors:0045b51d(c), 
    //                                                                                                         Poll:0045c2a3(c), 
    //                                                                                                         setup_shadow_area:00467530(c), 
    //                                                                                                         draw:00472a6f(c), 
    //                                                                                                         draw:004730d4(c), 
    //                                                                                                         draw:004778f4(c), 
    //                                                                                                         draw_background:0047d4c1(c), 
    //                                                                                                         draw_background:0047d51a(c), 
    //                                                                                                         draw_border:0047d72e(c), 
    //                                                                                                         draw:004ad221(c), 
    //                                                                                                         draw_frame_3d_square_front:004c2ba
    //                                                                                                         draw_item:0051c281(c), [more]
    //                              Drawarea.cpp:2089 (3)
    //         00444300     PUSH       ESI
    //         00444301     MOV        ESI,this
    //                              Drawarea.cpp:2090 (15)
    //         00444303     MOV        EAX,dword ptr [ESI]
    //         00444305     TEST       EAX,EAX
    //         00444307     JZ         LAB_00444312
    //         00444309     CMP        byte ptr [EAX + 0x478],0x1
    //         00444310     JZ         LAB_00444331
    //                               LAB_00444312                                                 XREF[1]:     00444307(j)  
    //                              Drawarea.cpp:2112 (7)
    //         00444312     MOV        EAX,dword ptr [ESI + 0x3c]
    //         00444315     TEST       EAX,EAX
    //         00444317     JZ         LAB_00444331
    //                              Drawarea.cpp:2130 (7)
    //         00444319     MOV        this,dword ptr [ESI + 0x8]
    //         0044431c     TEST       this,this
    //         0044431e     JZ         LAB_00444331
    //                              Drawarea.cpp:2148 (10)
    //         00444320     MOV        EDX,dword ptr [EAX]
    //         00444322     PUSH       this
    //         00444323     PUSH       EAX
    //         00444324     CALL       dword ptr [EDX + 0x80]
    //                              Drawarea.cpp:2169 (7)
    //         0044432a     MOV        dword ptr [ESI + 0x8],0x0
    //                               LAB_00444331                                                 XREF[3]:     00444310(j), 00444317(j), 
    //                                                                                                         0044431e(j)  
    //                              Drawarea.cpp:2171 (4)
    //         00444331     POP        ESI
    //         00444332     RET        0x4
}

// Offset: 0x00444340
void* GetDc(TDrawArea* this_, char* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void * __thiscall TDrawArea::GetDc(char *)                                                    *
    //                              *********************************************************************************************************
    //                              void * __thiscall GetDc(TDrawArea * this, char * param_1)
    //              void *            EAX:4          <RETURN>
    //              TDrawArea *       ECX:4 (auto)   this
    //              char *            Stack[0x4]:4   param_1
    //                               ?GetDc@TDrawArea@@QAEPAXPAD@Z                                XREF[33]:    draw:00472a95(c), 
    //                               TDrawArea::GetDc                                                          draw:0047783e(c), 
    //                                                                                                         draw_highlight_bar:00478d10(c), 
    //                                                                                                         render_to_image_buffer:00479b73(c)
    //                                                                                                         word_wrap_append:0047c694(c), 
    //                                                                                                         draw:0047d304(c), 
    //                                                                                                         get_text_rect:0047e41c(c), 
    //                                                                                                         draw:0048a789(c), 
    //                                                                                                         draw:004930ba(c), 
    //                                                                                                         draw_frame_3d_square_back:004c29c5
    //                                                                                                         draw_frame_3d_square_front:004c2bc
    //                                                                                                         draw:0051a7c6(c), 
    //                                                                                                         draw:0051b3b6(c), 
    //                                                                                                         draw_score:0051bfda(c), 
    //                                                                                                         draw_item:0051c33c(c), 
    //                                                                                                         draw:0051ddd2(c), 
    //                                                                                                         render_to_image_buffer:0051e2ec(c)
    //                                                                                                         draw_axis:0051fc2c(c), 
    //                                                                                                         draw_special_events:0051fe4b(c), 
    //                                                                                                         draw_civilization_names:00520251(c
    //                                                                                                         [more]
    //                              Drawarea.cpp:2177 (16)
    //         00444340     MOV        EAX,dword ptr [this->DrawSystem]
    //         00444342     PUSH       ESI
    //         00444343     TEST       EAX,EAX
    //         00444345     JZ         LAB_00444357
    //         00444347     CMP        byte ptr [EAX + 0x478],0x1
    //         0044434e     JNZ        LAB_00444357
    //                              Drawarea.cpp:2179 (3)
    //         00444350     MOV        EAX,dword ptr [ECX + this->DrawDc]
    //                              Drawarea.cpp:2278 (4)
    //         00444353     POP        ESI
    //         00444354     RET        0x4
    //                               LAB_00444357                                                 XREF[2]:     00444345(j), 0044434e(j)  
    //                              Drawarea.cpp:2200 (7)
    //         00444357     MOV        EDX,dword ptr [ECX + this->DrawSurface]
    //         0044435a     TEST       EDX,EDX
    //         0044435c     JNZ        LAB_00444364
    //                              Drawarea.cpp:2215 (2)
    //         0044435e     XOR        EAX,EAX
    //                              Drawarea.cpp:2278 (4)
    //         00444360     POP        ESI
    //         00444361     RET        0x4
    //                               LAB_00444364                                                 XREF[1]:     0044435c(j)  
    //                              Drawarea.cpp:2218 (8)
    //         00444364     MOV        EAX,dword ptr [ECX + this->DrawDc]
    //         00444367     LEA        ESI,[ECX + this->DrawDc]
    //         0044436a     TEST       EAX,EAX
    //                              Drawarea.cpp:2233 (2)
    //         0044436c     JNZ        LAB_00444384
    //                              Drawarea.cpp:2236 (7)
    //         0044436e     MOV        EAX,dword ptr [ECX + this->Bits]
    //         00444371     TEST       EAX,EAX
    //         00444373     JZ         LAB_0044437b
    //                              Drawarea.cpp:2251 (2)
    //         00444375     XOR        EAX,EAX
    //                              Drawarea.cpp:2278 (4)
    //         00444377     POP        ESI
    //         00444378     RET        0x4
    //                               LAB_0044437b                                                 XREF[1]:     00444373(j)  
    //                              Drawarea.cpp:2254 (7)
    //         0044437b     MOV        EAX,dword ptr [EDX]
    //         0044437d     PUSH       ESI
    //         0044437e     PUSH       EDX
    //         0044437f     CALL       dword ptr [EAX + 0x44]
    //                              Drawarea.cpp:2276 (2)
    //         00444382     MOV        EAX,dword ptr [ESI]
    //                               LAB_00444384                                                 XREF[1]:     0044436c(j)  
    //                              Drawarea.cpp:2278 (4)
    //         00444384     POP        ESI
    //         00444385     RET        0x4
}

// Offset: 0x00444390
void ReleaseDc(TDrawArea* this_, char* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TDrawArea::ReleaseDc(char *)                                                  *
    //                              *********************************************************************************************************
    //                              void __thiscall ReleaseDc(TDrawArea * this, char * param_1)
    //              void              <VOID>         <RETURN>
    //              TDrawArea *       ECX:4 (auto)   this
    //              char *            Stack[0x4]:4   param_1
    //                               ?ReleaseDc@TDrawArea@@QAEXPAD@Z                              XREF[33]:    draw:00472de0(c), 
    //                               TDrawArea::ReleaseDc                                                      draw:0047788d(c), 
    //                                                                                                         draw_highlight_bar:00478d44(c), 
    //                                                                                                         render_to_image_buffer:0047a107(c)
    //                                                                                                         word_wrap_append:0047ca51(c), 
    //                                                                                                         draw:0047d3b1(c), 
    //                                                                                                         get_text_rect:0047e45a(c), 
    //                                                                                                         draw:0048aa53(c), 
    //                                                                                                         draw:00493137(c), 
    //                                                                                                         draw_frame_3d_square_back:004c2b2a
    //                                                                                                         draw_frame_3d_square_front:004c2d1
    //                                                                                                         draw:0051aaaa(c), 
    //                                                                                                         draw:0051b659(c), 
    //                                                                                                         draw_score:0051c1cf(c), 
    //                                                                                                         draw_item:0051c3cb(c), 
    //                                                                                                         draw:0051e0c5(c), 
    //                                                                                                         render_to_image_buffer:0051e5b9(c)
    //                                                                                                         draw_axis:0051fd7b(c), 
    //                                                                                                         draw_special_events:00520027(c), 
    //                                                                                                         draw_civilization_names:00520482(c
    //                                                                                                         [more]
    //                              Drawarea.cpp:2284 (3)
    //         00444390     PUSH       ESI
    //         00444391     MOV        ESI,this
    //                              Drawarea.cpp:2285 (15)
    //         00444393     MOV        EAX,dword ptr [ESI]
    //         00444395     TEST       EAX,EAX
    //         00444397     JZ         LAB_004443a2
    //         00444399     CMP        byte ptr [EAX + 0x478],0x1
    //         004443a0     JZ         LAB_004443be
    //                               LAB_004443a2                                                 XREF[1]:     00444397(j)  
    //                              Drawarea.cpp:2307 (7)
    //         004443a2     MOV        EAX,dword ptr [ESI + 0x3c]
    //         004443a5     TEST       EAX,EAX
    //         004443a7     JZ         LAB_004443be
    //                              Drawarea.cpp:2325 (7)
    //         004443a9     MOV        this,dword ptr [ESI + 0x38]
    //         004443ac     TEST       this,this
    //         004443ae     JZ         LAB_004443be
    //                              Drawarea.cpp:2343 (7)
    //         004443b0     MOV        EDX,dword ptr [EAX]
    //         004443b2     PUSH       this
    //         004443b3     PUSH       EAX
    //         004443b4     CALL       dword ptr [EDX + 0x68]
    //                              Drawarea.cpp:2366 (7)
    //         004443b7     MOV        dword ptr [ESI + 0x38],0x0
    //                               LAB_004443be                                                 XREF[3]:     004443a0(j), 004443a7(j), 
    //                                                                                                         004443ae(j)  
    //                              Drawarea.cpp:2368 (4)
    //         004443be     POP        ESI
    //         004443bf     RET        0x4
}

// Offset: 0x004443D0
void SetSize(TDrawArea* this_, long param_2, long param_3, int param_4) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TDrawArea::SetSize(long,long,int)                                             *
    //                              *********************************************************************************************************
    //                              void __thiscall SetSize(TDrawArea * this, long param_1, long param_2
    //              void              <VOID>         <RETURN>
    //              TDrawArea *       ECX:4 (auto)   this
    //              long              Stack[0x4]:4   param_1                   XREF[4]:     0044441b(R), 00444457(W), 0044447d(R), 004445d9(R)  
    //              long              Stack[0x8]:4   param_2                   XREF[2]:     00444422(R), 004445d2(R)  
    //              int               Stack[0xc]:4   param_3                   XREF[1]:     00444464(R)  
    //              _DDBLTFX          Stack[-0x74]   ddbltfx
    //              _DDSURFACEDESC    Stack[-0xe0]   ddsd                      XREF[0,1]:   004444e7(*)  
    //                               ?SetSize@TDrawArea@@QAEXJJH@Z                                XREF[7]:     create_surfaces:0043720e(c), 
    //                               TDrawArea::SetSize                                                        SetDisplaySize:00442eac(c), 
    //                                                                                                         HandleSize:0044343f(c), 
    //                                                                                                         HandleSize:00443451(c), 
    //                                                                                                         Init:004440f9(c), 
    //                                                                                                         CheckSurface:004441e9(c), 
    //                                                                                                         create_surfaces:005341f2(c)  
    //                              Drawarea.cpp:2374 (33)
    //         004443d0     MOV        EAX,FS:[0x0]
    //         004443d6     PUSH       -0x1
    //         004443d8     PUSH       FUN_0055d30e
    //         004443dd     PUSH       EAX
    //         004443de     MOV        dword ptr FS:[0x0],ESP
    //         004443e5     SUB        ESP,0xd4
    //         004443eb     PUSH       EBX
    //         004443ec     PUSH       EBP
    //         004443ed     PUSH       ESI
    //         004443ee     MOV        ESI,this
    //         004443f0     PUSH       EDI
    //                              Drawarea.cpp:2380 (23)
    //         004443f1     MOV        EAX,dword ptr [ESI]
    //         004443f3     TEST       EAX,EAX
    //         004443f5     JZ         LAB_004445d2
    //         004443fb     CMP        byte ptr [EAX + 0x478],0x1
    //         00444402     JZ         LAB_004445d2
    //                              Drawarea.cpp:2475 (70)
    //         00444408     TEST       EAX,EAX
    //         0044440a     JZ         LAB_004445d2
    //         00444410     MOV        this,dword ptr [EAX + 0x18]
    //         00444413     TEST       this,this
    //         00444415     JZ         LAB_004445d2
    //         0044441b     MOV        EBX,dword ptr [ESP + param_1]
    //         00444422     MOV        EBP,dword ptr [ESP + param_2]
    //         00444429     TEST       EBX,EBX
    //         0044442b     JZ         LAB_004445e0
    //         00444431     TEST       EBP,EBP
    //         00444433     JZ         LAB_004445e0
    //         00444439     CMP        EBX,dword ptr [ESI + 0x18]
    //         0044443c     JNZ        LAB_0044444e
    //         0044443e     CMP        EBP,dword ptr [ESI + 0x1c]
    //         00444441     JNZ        LAB_0044444e
    //         00444443     MOV        EAX,dword ptr [ESI + 0x3c]
    //         00444446     TEST       EAX,EAX
    //         00444448     JNZ        LAB_004445e0
    //                               LAB_0044444e                                                 XREF[2]:     0044443c(j), 00444441(j)  
    //                              Drawarea.cpp:2478 (9)
    //         0044444e     MOV        this,0x1
    //         00444453     CMP        EBX,this
    //         00444455     JGE        LAB_0044445e
    //                              Drawarea.cpp:2479 (7)
    //         00444457     MOV        dword ptr [ESP + param_1],this
    //                               LAB_0044445e                                                 XREF[1]:     00444455(j)  
    //                              Drawarea.cpp:2481 (4)
    //         0044445e     CMP        EBP,this
    //         00444460     JGE        LAB_00444464
    //                              Drawarea.cpp:2482 (2)
    //         00444462     MOV        EBP,this
    //                               LAB_00444464                                                 XREF[1]:     00444460(j)  
    //                              Drawarea.cpp:2484 (7)
    //         00444464     MOV        EAX,dword ptr [ESP + param_3]
    //                              Drawarea.cpp:2485 (7)
    //         0044446b     LEA        EBX,[EBP + 0xa]
    //         0044446e     TEST       EAX,EAX
    //         00444470     JNZ        LAB_00444474
    //                              Drawarea.cpp:2487 (2)
    //         00444472     MOV        EBX,EBP
    //                               LAB_00444474                                                 XREF[1]:     00444470(j)  
    //                              Drawarea.cpp:2491 (19)
    //         00444474     MOV        EDX,dword ptr [ESI + 0xc]
    //         00444477     MOV        dword ptr [ESI + 0xf8],EAX
    //         0044447d     MOV        EAX,dword ptr [ESP + param_1]
    //         00444484     MOV        dword ptr [EDX + 0x4],EAX
    //                              Drawarea.cpp:2493 (7)
    //         00444487     MOV        EDX,dword ptr [ESI + 0x24]
    //         0044448a     CMP        EDX,this
    //         0044448c     JNZ        LAB_0044449a
    //                              Drawarea.cpp:2494 (10)
    //         0044448e     MOV        EDX,dword ptr [ESI + 0xc]
    //         00444491     MOV        this,EBX
    //         00444493     NEG        this
    //         00444495     MOV        dword ptr [EDX + 0x8],this=>DAT_fffffff5
    //                              Drawarea.cpp:2495 (2)
    //         00444498     JMP        LAB_004444a0
    //                               LAB_0044449a                                                 XREF[1]:     0044448c(j)  
    //                              Drawarea.cpp:2496 (6)
    //         0044449a     MOV        this,dword ptr [ESI + 0xc]
    //         0044449d     MOV        dword ptr [ECX + this->Bits],EBX
    //                               LAB_004444a0                                                 XREF[1]:     00444498(j)  
    //                              Drawarea.cpp:2498 (3)
    //         004444a0     MOV        dword ptr [ESI + 0x18],EAX
    //                              Drawarea.cpp:2501 (17)
    //         004444a3     MOV        EAX,dword ptr [ESI + 0xf0]
    //         004444a9     TEST       EAX,EAX
    //         004444ab     MOV        dword ptr [ESI + 0x1c],EBP
    //         004444ae     JNZ        LAB_004445b4
    //                              Drawarea.cpp:2506 (10)
    //         004444b4     MOV        EAX,dword ptr [ESI + 0x3c]
    //         004444b7     LEA        EDI,[ESI + 0x3c]
    //         004444ba     TEST       EAX,EAX
    //         004444bc     JZ         LAB_004444e5
    //                              Drawarea.cpp:2508 (6)
    //         004444be     MOV        EDX,dword ptr [EAX]
    //         004444c0     PUSH       EAX
    //         004444c1     CALL       dword ptr [EDX + 0x8]
    //                              Drawarea.cpp:2511 (22)
    //         004444c4     PUSH       0x6c
    //         004444c6     LEA        EAX,[ESI + 0x40]
    //         004444c9     PUSH       0x0=>DAT_fffffff8
    //         004444cb     PUSH       EAX=>DAT_fffffff4
    //         004444cc     MOV        dword ptr [EDI],0x0
    //         004444d2     CALL       memset                                           undefined memset()
    //         004444d7     ADD        ESP,0xc
    //                              Drawarea.cpp:2512 (5)
    //         004444da     XOR        EAX,EAX
    //         004444dc     MOV        dword ptr [ESI + 0x20],EAX
    //                              Drawarea.cpp:2513 (6)
    //         004444df     MOV        dword ptr [ESI + 0xe8],EAX
    //                               LAB_004444e5                                                 XREF[1]:     004444bc(j)  
    //                              Drawarea.cpp:2517 (14)
    //         004444e5     PUSH       0x6c
    //         004444e7     LEA        this=>ddsd.dwFlags,[ESP + 0x18]
    //         004444eb     PUSH       0x0=>DAT_fffffff8
    //         004444ed     PUSH       this=>DAT_fffffff4
    //         004444ee     CALL       memset                                           undefined memset()
    //                              Drawarea.cpp:2522 (44)
    //         004444f3     MOV        EAX,dword ptr [ESI]
    //         004444f5     MOV        dword ptr [ESP + 0x20],0x6c
    //         004444fd     MOV        dword ptr [ESP + 0x24],0x7
    //         00444505     ADD        ESP,0xc
    //         00444508     TEST       byte ptr [EAX + 0x28],0x1
    //         0044450c     JNZ        LAB_0044452b
    //         0044450e     MOV        this,dword ptr [ESP + 0xfc]
    //         00444515     TEST       this,this
    //         00444517     JNZ        LAB_0044452b
    //         00444519     MOV        this,dword ptr [ESI + 0xe4]
    //                              Drawarea.cpp:2525 (12)
    //         0044451f     MOV        dword ptr [ESP + 0x7c],0x40
    //         00444527     TEST       this,this
    //         00444529     JZ         LAB_00444533
    //                               LAB_0044452b                                                 XREF[2]:     0044450c(j), 00444517(j)  
    //                              Drawarea.cpp:2523 (8)
    //         0044452b     MOV        dword ptr [ESP + 0x7c],0x840
    //                               LAB_00444533                                                 XREF[1]:     00444529(j)  
    //                              Drawarea.cpp:2527 (3)
    //         00444533     MOV        EDX,dword ptr [ESI + 0x18]
    //                              Drawarea.cpp:2528 (8)
    //         00444536     MOV        dword ptr [ESP + 0x1c],EBX
    //         0044453a     MOV        dword ptr [ESP + 0x20],EDX
    //                              Drawarea.cpp:2529 (17)
    //         0044453e     MOV        EAX,dword ptr [EAX + 0x18]
    //         00444541     PUSH       0x0
    //         00444543     LEA        EDX,[ESP + 0x18]
    //         00444547     MOV        this,dword ptr [EAX]
    //         00444549     PUSH       EDI=>DAT_fffffff8
    //         0044454a     PUSH       EDX=>DAT_fffffff4
    //         0044454b     PUSH       EAX=>DAT_fffffff0
    //         0044454c     CALL       dword ptr [ECX + this->Width]
    //                              Drawarea.cpp:2534 (4)
    //         0044454f     TEST       EAX,EAX
    //         00444551     JNZ        LAB_004445bc
    //                              Drawarea.cpp:2537 (18)
    //         00444553     MOV        this,dword ptr [EDI]
    //         00444555     LEA        EAX,[ESI + 0x40]
    //         00444558     PUSH       EAX
    //         00444559     PUSH       this=>DAT_fffffff8
    //         0044455a     MOV        EDX,dword ptr [this->DrawSystem]
    //         0044455c     MOV        dword ptr [EAX],0x6c
    //         00444562     CALL       dword ptr [EDX + 0x58]
    //                              Drawarea.cpp:2539 (4)
    //         00444565     TEST       EAX,EAX
    //         00444567     JNZ        LAB_004445aa
    //                              Drawarea.cpp:2541 (7)
    //         00444569     MOV        this,ESI
    //         0044456b     CALL       TDrawArea::SetInfo                               void SetInfo(TDrawArea * this)
    //                              Drawarea.cpp:2542 (7)
    //         00444570     MOV        this,ESI
    //         00444572     CALL       TDrawArea::SetAccessOffsets                      void SetAccessOffsets(TDrawArea * this)
    //                              Drawarea.cpp:2547 (49)
    //         00444577     MOV        EDI,dword ptr [EDI]
    //         00444579     LEA        this,[ESP + 0x80]
    //         00444580     PUSH       this
    //         00444581     PUSH       offset DAT_fffffff8
    //         00444586     MOV        EAX,dword ptr [EDI]
    //         00444588     PUSH       0x0=>DAT_fffffff4
    //         0044458a     PUSH       0x0=>DAT_fffffff0
    //         0044458c     PUSH       0x0
    //         0044458e     PUSH       EDI
    //         0044458f     MOV        dword ptr [ESP + 0x98],0x64
    //         0044459a     MOV        dword ptr [ESP + 0xe8],0x0
    //         004445a5     CALL       dword ptr [EAX + 0x14]
    //                              Drawarea.cpp:2550 (2)
    //         004445a8     JMP        LAB_004445bc
    //                               LAB_004445aa                                                 XREF[1]:     00444567(j)  
    //                              Drawarea.cpp:2551 (8)
    //         004445aa     MOV        this,dword ptr [ESI]
    //         004445ac     PUSH       EAX
    //         004445ad     CALL       TDrawSystem::GetCreateErrorNum                   int GetCreateErrorNum(TDrawSystem * this, lon
    //                              Drawarea.cpp:2554 (2)
    //         004445b2     JMP        LAB_004445bc
    //                               LAB_004445b4                                                 XREF[1]:     004444ae(j)  
    //                              Drawarea.cpp:2556 (8)
    //         004445b4     MOV        EDX,dword ptr [ESI]
    //         004445b6     MOV        EAX,dword ptr [EDX + 0x1c]
    //         004445b9     MOV        dword ptr [ESI + 0x3c],EAX
    //                               LAB_004445bc                                                 XREF[3]:     00444551(j), 004445a8(j), 
    //                                                                                                         004445b2(j)  
    //                              Drawarea.cpp:2560 (9)
    //         004445bc     PUSH       0x0
    //         004445be     MOV        this,ESI
    //         004445c0     CALL       TDrawArea::SetClipRect                           void SetClipRect(TDrawArea * this, tagRECT * 
    //                              Drawarea.cpp:2561 (27)
    //         004445c5     PUSH       0x0
    //         004445c7     PUSH       0x0=>DAT_fffffff8
    //         004445c9     MOV        this,ESI
    //         004445cb     CALL       TDrawArea::Clear                                 void Clear(TDrawArea * this, tagRECT * param_
    //         004445d0     JMP        LAB_004445d9
    //                               LAB_004445d2                                                 XREF[4]:     004443f5(j), 00444402(j), 
    //                                                                                                         0044440a(j), 00444415(j)  
    //         004445d2     MOV        EBP,dword ptr [ESP + param_2]
    //                               LAB_004445d9                                                 XREF[1]:     004445d0(j)  
    //         004445d9     MOV        EBX,dword ptr [ESP + param_1]
    //                               LAB_004445e0                                                 XREF[3]:     0044442b(j), 00444433(j), 
    //                                                                                                         00444448(j)  
    //                              Drawarea.cpp:2569 (26)
    //         004445e0     MOV        EDI,dword ptr [ESI + 0xcc]
    //         004445e6     TEST       EDI,EDI
    //         004445e8     JZ         LAB_004445fa
    //         004445ea     MOV        this,EDI
    //         004445ec     CALL       TSpan_List_Manager::~TSpan_List_Manager          void ~TSpan_List_Manager(TSpan_List_Manager *
    //         004445f1     PUSH       EDI
    //         004445f2     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         004445f7     ADD        ESP,0x4
    //                              language.dll match for 0x68: "Arial"
    //                               LAB_004445fa                                                 XREF[1]:     004445e8(j)  
    //                              Drawarea.cpp:2571 (40)
    //         004445fa     PUSH       0x68
    //         004445fc     CALL       operator_new                                     void * operator_new(uint param_1)
    //         00444601     ADD        ESP,0x4
    //         00444604     MOV        dword ptr [ESP + 0x10],EAX
    //         00444608     XOR        EDI,EDI
    //         0044460a     CMP        EAX,EDI
    //         0044460c     MOV        dword ptr [ESP + 0xec],EDI
    //         00444613     JZ         LAB_00444620
    //         00444615     PUSH       EBP
    //         00444616     PUSH       EBX=>DAT_fffffff8
    //         00444617     MOV        this,EAX
    //         00444619     CALL       TSpan_List_Manager::TSpan_List_Manager           undefined TSpan_List_Manager(TSpan_List_Manag
    //         0044461e     JMP        LAB_00444622
    //                               LAB_00444620                                                 XREF[1]:     00444613(j)  
    //         00444620     XOR        EAX,EAX
    //                               LAB_00444622                                                 XREF[1]:     0044461e(j)  
    //                              Drawarea.cpp:2572 (21)
    //         00444622     TEST       EBP,EBP
    //         00444624     MOV        dword ptr [ESP + 0xec],0xffffffff
    //         0044462f     MOV        dword ptr [ESI + 0xcc],EAX
    //         00444635     JLE        LAB_0044464c
    //                              Drawarea.cpp:2573 (21)
    //         00444637     DEC        EBX
    //                               LAB_00444638                                                 XREF[1]:     0044464a(j)  
    //         00444638     MOV        this,dword ptr [ESI + 0xcc]
    //         0044463e     PUSH       EDI
    //         0044463f     PUSH       EBX=>DAT_fffffff8
    //         00444640     PUSH       0x0=>DAT_fffffff4
    //         00444642     CALL       TSpan_List_Manager::AddSpan                      void AddSpan(TSpan_List_Manager * this, int p
    //         00444647     INC        EDI
    //         00444648     CMP        EDI,EBP
    //         0044464a     JL         LAB_00444638
    //                               LAB_0044464c                                                 XREF[1]:     00444635(j)  
    //                              Drawarea.cpp:2575 (6)
    //         0044464c     MOV        this,dword ptr [ESI + 0xcc]
    //                              Drawarea.cpp:2577 (33)
    //         00444652     POP        EDI
    //         00444653     MOV        dword ptr [ESI + 0xd0],this
    //         00444659     MOV        this,dword ptr [ESP + 0xe0]
    //         00444660     POP        ESI
    //         00444661     POP        EBP
    //         00444662     MOV        dword ptr FS:[0x0],this
    //         00444669     POP        EBX
    //         0044466a     ADD        ESP,0xe0
    //         00444670     RET        0xc
}

// Offset: 0x00444680
void Clear(TDrawArea* this_, tagRECT* param_2, int param_3) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TDrawArea::Clear(struct tagRECT *,int)                                        *
    //                              *********************************************************************************************************
    //                              void __thiscall Clear(TDrawArea * this, tagRECT * param_1, int param
    //              void              <VOID>         <RETURN>
    //              TDrawArea *       ECX:4 (auto)   this
    //              tagRECT *         Stack[0x4]:4   param_1                   XREF[3]:     00444697(R), 004446d1(R), 004447df(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[4]:     00444690(R), 004446e3(R), 0044479f(R), 004447cc(R)  
    //              _DDBLTFX          Stack[-0x68]   ddbltfx                   XREF[1,4]:   00444833(W), 004447d3(W), 004447ec(*), 00444822(*), 
    //                                                                                     004447db(W)  
    //              tagRECT           Stack[-0x78]   dest                      XREF[2,4]:   0044476b(W), 004447a7(R), 0044480c(W), 0044482f(*), 
    //                                                                                     00444813(W), 0044481e(W)  
    //              int               Stack[-0x7c]:4 wid
    //                               ?Clear@TDrawArea@@QAEXPAUtagRECT@@H@Z                        XREF[23]:    handle_close:00421b95(c), 
    //                               TDrawArea::Clear                                                          draw:00437398(c), 
    //                                                                                                         draw:0043746b(c), 
    //                                                                                                         SetSize:004445cb(c), 
    //                                                                                                         LoadCursors:0045b4bd(c), 
    //                                                                                                         draw:004651ba(c), 
    //                                                                                                         draw_setup:0046535d(c), 
    //                                                                                                         setup_shadow_area:004674c9(c), 
    //                                                                                                         draw_background:00467604(c), 
    //                                                                                                         draw_background:00467737(c), 
    //                                                                                                         set_focus:00469e8f(c), 
    //                                                                                                         draw:00472909(c), 
    //                                                                                                         set_focus:0047bc1b(c), 
    //                                                                                                         draw:0048a669(c), 
    //                                                                                                         draw:00492cec(c), 
    //                                                                                                         draw:004b8916(c), 
    //                                                                                                         draw:004beef1(c), 
    //                                                                                                         draw:0051b211(c), 
    //                                                                                                         draw_score:0051bfcd(c), 
    //                                                                                                         draw:00534b3f(c), [more]
    //                              Drawarea.cpp:2583 (16)
    //         00444680     MOV        EAX,[DDSys_CanColorFill]                         = 1h
    //         00444685     SUB        ESP,0x78
    //         00444688     TEST       EAX,EAX
    //         0044468a     PUSH       EBX
    //         0044468b     PUSH       EBP
    //         0044468c     PUSH       ESI
    //         0044468d     PUSH       EDI
    //         0044468e     JNZ        LAB_004446af
    //                              Drawarea.cpp:2589 (21)
    //         00444690     MOV        EAX,dword ptr [ESP + param_2]
    //         00444697     MOV        EDX,dword ptr [ESP + param_1]
    //         0044469e     PUSH       EAX
    //         0044469f     PUSH       EDX
    //         004446a0     CALL       TDrawArea::PtrClear                              void PtrClear(TDrawArea * this, tagRECT * par
    //                              Drawarea.cpp:2687 (10)
    //         004446a5     POP        EDI
    //         004446a6     POP        ESI
    //         004446a7     POP        EBP
    //         004446a8     POP        EBX
    //         004446a9     ADD        ESP,0x78
    //         004446ac     RET        0x8
    //                               LAB_004446af                                                 XREF[1]:     0044468e(j)  
    //                              Drawarea.cpp:2593 (23)
    //         004446af     MOV        EAX,dword ptr [this->DrawSystem]
    //         004446b1     TEST       EAX,EAX
    //         004446b3     JZ         LAB_004447c5
    //         004446b9     CMP        byte ptr [EAX + 0x478],0x1
    //         004446c0     JNZ        LAB_004447c5
    //                              Drawarea.cpp:2600 (11)
    //         004446c6     MOV        EDI,dword ptr [ECX + this->Bits]
    //         004446c9     TEST       EDI,EDI
    //         004446cb     JZ         LAB_00444840
    //                              Drawarea.cpp:2603 (11)
    //         004446d1     MOV        EAX,dword ptr [ESP + param_1]
    //         004446d8     TEST       EAX,EAX
    //         004446da     JNZ        LAB_004446ff
    //                              Drawarea.cpp:2604 (25)
    //         004446dc     MOV        EAX,dword ptr [ECX + this->Height]
    //         004446df     IMUL       EAX,dword ptr [ECX + this->Pitch]
    //         004446e3     MOV        this,dword ptr [ESP + param_2]
    //         004446ea     PUSH       EAX
    //         004446eb     PUSH       this
    //         004446ec     PUSH       EDI
    //         004446ed     CALL       memset                                           undefined memset()
    //         004446f2     ADD        ESP,0xc
    //                              Drawarea.cpp:2687 (10)
    //         004446f5     POP        EDI
    //         004446f6     POP        ESI
    //         004446f7     POP        EBP
    //         004446f8     POP        EBX
    //         004446f9     ADD        ESP,0x78
    //         004446fc     RET        0x8
    //                               LAB_004446ff                                                 XREF[1]:     004446da(j)  
    //                              Drawarea.cpp:2607 (2)
    //         004446ff     MOV        EDX,dword ptr [EAX]
    //                              Drawarea.cpp:2608 (3)
    //         00444701     MOV        EBP,dword ptr [EAX + 0x4]
    //                              Drawarea.cpp:2610 (3)
    //         00444704     MOV        ESI,dword ptr [EAX + 0x8]
    //                              Drawarea.cpp:2611 (3)
    //         00444707     MOV        EBX,dword ptr [EAX + 0xc]
    //                              Drawarea.cpp:2613 (4)
    //         0044470a     TEST       EDX,EDX
    //         0044470c     JGE        LAB_00444712
    //                              Drawarea.cpp:2614 (2)
    //         0044470e     XOR        EDX,EDX
    //                              Drawarea.cpp:2615 (9)
    //         00444710     JMP        LAB_0044471c
    //                               LAB_00444712                                                 XREF[1]:     0044470c(j)  
    //         00444712     MOV        EAX,dword ptr [ECX + this->Width]
    //         00444715     CMP        EDX,EAX
    //         00444717     JL         LAB_0044471c
    //                              Drawarea.cpp:2616 (3)
    //         00444719     LEA        EDX,[EAX + -0x1]
    //                               LAB_0044471c                                                 XREF[2]:     00444710(j), 00444717(j)  
    //                              Drawarea.cpp:2618 (4)
    //         0044471c     TEST       EBP,EBP
    //         0044471e     JGE        LAB_00444724
    //                              Drawarea.cpp:2619 (2)
    //         00444720     XOR        EBP,EBP
    //                              Drawarea.cpp:2620 (9)
    //         00444722     JMP        LAB_0044472e
    //                               LAB_00444724                                                 XREF[1]:     0044471e(j)  
    //         00444724     MOV        EAX,dword ptr [ECX + this->Height]
    //         00444727     CMP        EBP,EAX
    //         00444729     JL         LAB_0044472e
    //                              Drawarea.cpp:2621 (3)
    //         0044472b     LEA        EBP,[EAX + -0x1]
    //                               LAB_0044472e                                                 XREF[2]:     00444722(j), 00444729(j)  
    //                              Drawarea.cpp:2623 (4)
    //         0044472e     TEST       ESI,ESI
    //         00444730     JGE        LAB_00444736
    //                              Drawarea.cpp:2624 (2)
    //         00444732     XOR        ESI,ESI
    //                              Drawarea.cpp:2625 (9)
    //         00444734     JMP        LAB_00444740
    //                               LAB_00444736                                                 XREF[1]:     00444730(j)  
    //         00444736     MOV        EAX,dword ptr [ECX + this->Width]
    //         00444739     CMP        ESI,EAX
    //         0044473b     JL         LAB_00444740
    //                              Drawarea.cpp:2626 (3)
    //         0044473d     LEA        ESI,[EAX + -0x1]
    //                               LAB_00444740                                                 XREF[2]:     00444734(j), 0044473b(j)  
    //                              Drawarea.cpp:2628 (4)
    //         00444740     TEST       EBX,EBX
    //         00444742     JGE        LAB_00444748
    //                              Drawarea.cpp:2629 (2)
    //         00444744     XOR        EBX,EBX
    //                              Drawarea.cpp:2630 (9)
    //         00444746     JMP        LAB_00444752
    //                               LAB_00444748                                                 XREF[1]:     00444742(j)  
    //         00444748     MOV        EAX,dword ptr [ECX + this->Height]
    //         0044474b     CMP        EBX,EAX
    //         0044474d     JL         LAB_00444752
    //                              Drawarea.cpp:2631 (3)
    //         0044474f     LEA        EBX,[EAX + -0x1]
    //                               LAB_00444752                                                 XREF[2]:     00444746(j), 0044474d(j)  
    //                              Drawarea.cpp:2633 (16)
    //         00444752     CMP        ESI,EDX
    //         00444754     JLE        LAB_00444840
    //         0044475a     CMP        EBX,EBP
    //         0044475c     JLE        LAB_00444840
    //                              Drawarea.cpp:2637 (15)
    //         00444762     MOV        EAX,dword ptr [ECX + this->Orien]
    //         00444765     SUB        ESI,EDX
    //         00444767     INC        ESI
    //         00444768     CMP        EAX,0x1
    //         0044476b     MOV        dword ptr [ESP + dest.left],ESI
    //         0044476f     JNZ        LAB_00444781
    //                              Drawarea.cpp:2639 (12)
    //         00444771     MOV        this,dword ptr [ECX + this->Pitch]
    //         00444774     MOV        ESI,EBP
    //         00444776     IMUL       ESI,this
    //         00444779     ADD        ESI,EDX
    //         0044477b     ADD        ESI,EDI
    //                              Drawarea.cpp:2640 (2)
    //         0044477d     MOV        EDI,this
    //                              Drawarea.cpp:2642 (2)
    //         0044477f     JMP        LAB_00444795
    //                               LAB_00444781                                                 XREF[1]:     0044476f(j)  
    //                              Drawarea.cpp:2644 (16)
    //         00444781     MOV        ESI,dword ptr [ECX + this->Height]
    //         00444784     MOV        EAX,dword ptr [ECX + this->Pitch]
    //         00444787     SUB        ESI,EBP
    //         00444789     DEC        ESI
    //         0044478a     IMUL       ESI,EAX
    //         0044478d     ADD        ESI,EDX
    //         0044478f     ADD        ESI,EDI
    //                              Drawarea.cpp:2645 (4)
    //         00444791     NEG        EAX
    //         00444793     MOV        EDI,EAX
    //                               LAB_00444795                                                 XREF[1]:     0044477f(j)  
    //                              Drawarea.cpp:2648 (18)
    //         00444795     CMP        EBP,EBX
    //         00444797     JG         LAB_00444840
    //         0044479d     SUB        EBX,EBP
    //         0044479f     MOV        EBP,dword ptr [ESP + param_2]
    //         004447a6     INC        EBX
    //                               LAB_004447a7                                                 XREF[1]:     004447b9(j)  
    //                              Drawarea.cpp:2650 (15)
    //         004447a7     MOV        EDX,dword ptr [ESP + dest.left]
    //         004447ab     PUSH       EDX
    //         004447ac     PUSH       EBP
    //         004447ad     PUSH       ESI
    //         004447ae     CALL       memset                                           undefined memset()
    //         004447b3     ADD        ESP,0xc
    //                              Drawarea.cpp:2651 (5)
    //         004447b6     ADD        ESI,EDI
    //         004447b8     DEC        EBX
    //         004447b9     JNZ        LAB_004447a7
    //                              Drawarea.cpp:2687 (10)
    //         004447bb     POP        EDI
    //         004447bc     POP        ESI
    //         004447bd     POP        EBP
    //         004447be     POP        EBX
    //         004447bf     ADD        ESP,0x78
    //         004447c2     RET        0x8
    //                               LAB_004447c5                                                 XREF[2]:     004446b3(j), 004446c0(j)  
    //                              Drawarea.cpp:2661 (7)
    //         004447c5     MOV        this,dword ptr [ECX + this->DrawSurface]
    //         004447c8     TEST       this,this
    //         004447ca     JZ         LAB_00444840
    //                              Drawarea.cpp:2665 (19)
    //         004447cc     MOV        EAX,dword ptr [ESP + param_2]
    //         004447d3     MOV        dword ptr [ESP + ddbltfx.dwDDFX],0x64
    //         004447db     MOV        dword ptr [ESP + ddbltfx.ddckDestColorkey.dwCo
    //                              Drawarea.cpp:2667 (11)
    //         004447df     MOV        EAX,dword ptr [ESP + param_1]
    //         004447e6     TEST       EAX,EAX
    //         004447e8     JNZ        LAB_0044480a
    //                              Drawarea.cpp:2669 (22)
    //         004447ea     MOV        EDX,dword ptr [this->DrawSystem]
    //         004447ec     LEA        EAX=>ddbltfx.dwDDFX,[ESP + 0x24]
    //         004447f0     PUSH       EAX
    //         004447f1     PUSH       0x1000400
    //         004447f6     PUSH       0x0
    //         004447f8     PUSH       0x0
    //         004447fa     PUSH       0x0
    //         004447fc     PUSH       this
    //         004447fd     CALL       dword ptr [EDX + 0x14]
    //                              Drawarea.cpp:2687 (10)
    //         00444800     POP        EDI
    //         00444801     POP        ESI
    //         00444802     POP        EBP
    //         00444803     POP        EBX
    //         00444804     ADD        ESP,0x78
    //         00444807     RET        0x8
    //                               LAB_0044480a                                                 XREF[1]:     004447e8(j)  
    //                              Drawarea.cpp:2674 (19)
    //         0044480a     MOV        EDX,dword ptr [EAX]
    //         0044480c     MOV        dword ptr [ESP + dest.top],EDX
    //         00444810     MOV        EDX,dword ptr [EAX + 0x4]
    //         00444813     MOV        dword ptr [ESP + dest.right],EDX
    //         00444817     MOV        EDX,dword ptr [EAX + 0x8]
    //         0044481a     MOV        EAX,dword ptr [EAX + 0xc]
    //                              Drawarea.cpp:2676 (5)
    //         0044481d     INC        EDX
    //         0044481e     MOV        dword ptr [ESP + dest.bottom],EDX
    //                              Drawarea.cpp:2679 (30)
    //         00444822     LEA        EDX=>ddbltfx.dwDDFX,[ESP + 0x24]
    //         00444826     PUSH       EDX
    //         00444827     INC        EAX
    //         00444828     PUSH       0x1000400
    //         0044482d     PUSH       0x0
    //         0044482f     LEA        EDX=>dest.top,[ESP + 0x20]
    //         00444833     MOV        dword ptr [ESP + ddbltfx.dwSize],EAX
    //         00444837     MOV        EAX,dword ptr [this->DrawSystem]
    //         00444839     PUSH       0x0
    //         0044483b     PUSH       EDX
    //         0044483c     PUSH       this
    //         0044483d     CALL       dword ptr [EAX + 0x14]
    //                               LAB_00444840                                                 XREF[5]:     004446cb(j), 00444754(j), 
    //                                                                                                         0044475c(j), 00444797(j), 
    //                                                                                                         004447ca(j)  
    //                              Drawarea.cpp:2687 (10)
    //         00444840     POP        EDI
    //         00444841     POP        ESI
    //         00444842     POP        EBP
    //         00444843     POP        EBX
    //         00444844     ADD        ESP,0x78
    //         00444847     RET        0x8
}

// Offset: 0x00444850
void PtrClear(TDrawArea* this_, tagRECT* param_2, int param_3) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TDrawArea::PtrClear(struct tagRECT *,int)                                     *
    //                              *********************************************************************************************************
    //                              void __thiscall PtrClear(TDrawArea * this, tagRECT * param_1, int pa
    //              void              <VOID>         <RETURN>
    //              TDrawArea *       ECX:4 (auto)   this
    //              tagRECT *         Stack[0x4]:4   param_1                   XREF[6]:     00444856(R), 00444873(W), 00444885(W), 004448d3(W), 
    //                                                                                     00444928(R), 00444954(RW)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     0044491a(R)  
    //              int               Stack[-0x8]:4  x1                        XREF[4]:     00444870(W), 00444882(W), 004448c0(W), 00444931(R)  
    //              int               Stack[-0xc]:4  nLines                    XREF[2]:     004448e6(W), 00444957(RW)  
    //              int               Stack[-0x10]:4 nWidth                    XREF[2]:     004448ed(W), 00444934(R)  
    //              void * *          Stack[-0x14]:4 SrcP                      XREF[2]:     00444913(W), 0044492b(R)  
    //              undefined4        Stack[-0x18]:4 local_18                  XREF[2]:     00444860(W), 0044495f(R)  
    //                               ?PtrClear@TDrawArea@@QAEXPAUtagRECT@@H@Z                     XREF[7]:     Clear:004446a0(c), 
    //                               TDrawArea::PtrClear                                                       render_to_image_buffer:00479b06(c)
    //                                                                                                         render_to_image_buffer:0051d51c(c)
    //                                                                                                         render_to_image_buffer:0051e2dc(c)
    //                                                                                                         draw:005350a4(c), 
    //                                                                                                         draw:005350f3(c), 
    //                                                                                                         draw:00535199(c)  
    //                              Drawarea.cpp:2694 (6)
    //         00444850     PUSH       EBP
    //         00444851     MOV        EBP,ESP
    //         00444853     SUB        ESP,0x14
    //                              Drawarea.cpp:2703 (15)
    //         00444856     MOV        EAX,dword ptr [EBP + param_1]
    //         00444859     PUSH       EBX
    //         0044485a     PUSH       ESI
    //         0044485b     PUSH       EDI
    //         0044485c     MOV        EDI,this
    //         0044485e     TEST       EAX,EAX
    //         00444860     MOV        dword ptr [EBP + local_18],EDI
    //         00444863     JZ         LAB_00444878
    //                              Drawarea.cpp:2705 (5)
    //         00444865     MOV        ESI,dword ptr [EAX]
    //         00444867     MOV        EDX,dword ptr [EAX + 0x4]
    //                              Drawarea.cpp:2706 (12)
    //         0044486a     MOV        this,dword ptr [EAX + 0x8]
    //         0044486d     MOV        EAX,dword ptr [EAX + 0xc]
    //         00444870     MOV        dword ptr [EBP + x1],ESI
    //         00444873     MOV        dword ptr [EBP + param_1],EDX
    //                              Drawarea.cpp:2708 (2)
    //         00444876     JMP        LAB_00444888
    //                               LAB_00444878                                                 XREF[1]:     00444863(j)  
    //                              Drawarea.cpp:2711 (16)
    //         00444878     MOV        this,dword ptr [EDI + 0x18]
    //         0044487b     MOV        EAX,dword ptr [EDI + 0x1c]
    //         0044487e     XOR        ESI,ESI
    //         00444880     XOR        EDX,EDX
    //         00444882     MOV        dword ptr [EBP + x1],ESI
    //         00444885     MOV        dword ptr [EBP + param_1],EDX
    //                               LAB_00444888                                                 XREF[1]:     00444876(j)  
    //                              Drawarea.cpp:2714 (25)
    //         00444888     TEST       this,this
    //         0044488a     JL         LAB_0044497b
    //         00444890     CMP        ESI,this
    //         00444892     JG         LAB_0044497b
    //         00444898     CMP        ESI,dword ptr [EDI + 0x18]
    //         0044489b     JGE        LAB_0044497b
    //                              Drawarea.cpp:2715 (25)
    //         004448a1     TEST       EAX,EAX
    //         004448a3     JL         LAB_0044497b
    //         004448a9     CMP        EDX,EAX
    //         004448ab     JG         LAB_0044497b
    //         004448b1     CMP        EDX,dword ptr [EDI + 0x1c]
    //         004448b4     JGE        LAB_0044497b
    //                              Drawarea.cpp:2717 (9)
    //         004448ba     TEST       ESI,ESI
    //         004448bc     JGE        LAB_004448c3
    //         004448be     XOR        ESI,ESI
    //         004448c0     MOV        dword ptr [EBP + x1],ESI
    //                               LAB_004448c3                                                 XREF[1]:     004448bc(j)  
    //                              Drawarea.cpp:2718 (10)
    //         004448c3     MOV        EBX,dword ptr [EDI + 0x18]
    //         004448c6     CMP        this,EBX
    //         004448c8     JL         LAB_004448cd
    //         004448ca     LEA        this,[EBX + -0x1]
    //                               LAB_004448cd                                                 XREF[1]:     004448c8(j)  
    //                              Drawarea.cpp:2719 (9)
    //         004448cd     TEST       EDX,EDX
    //         004448cf     JGE        LAB_004448d6
    //         004448d1     XOR        EDX,EDX
    //         004448d3     MOV        dword ptr [EBP + param_1],EDX
    //                               LAB_004448d6                                                 XREF[1]:     004448cf(j)  
    //                              Drawarea.cpp:2720 (10)
    //         004448d6     MOV        EBX,dword ptr [EDI + 0x1c]
    //         004448d9     CMP        EAX,EBX
    //         004448db     JL         LAB_004448e0
    //         004448dd     LEA        EAX,[EBX + -0x1]
    //                               LAB_004448e0                                                 XREF[1]:     004448db(j)  
    //                              Drawarea.cpp:2722 (2)
    //         004448e0     SUB        EAX,EDX
    //                              Drawarea.cpp:2723 (7)
    //         004448e2     SUB        this,ESI
    //         004448e4     INC        EAX
    //         004448e5     INC        this
    //         004448e6     MOV        dword ptr [EBP + nLines],EAX
    //                              Drawarea.cpp:2726 (18)
    //         004448e9     MOV        EAX,dword ptr [EDI]
    //         004448eb     TEST       EAX,EAX
    //         004448ed     MOV        dword ptr [EBP + nWidth],this
    //         004448f0     JZ         LAB_0044490d
    //         004448f2     CMP        byte ptr [EAX + 0x478],0x2
    //         004448f9     JNZ        LAB_0044490d
    //                              Drawarea.cpp:2728 (18)
    //         004448fb     PUSH       0x1
    //         004448fd     PUSH       s_PtrClear                                       = "PtrClear"
    //         00444902     MOV        this,EDI
    //         00444904     CALL       TDrawArea::Lock                                  uchar * Lock(TDrawArea * this, char * param_1
    //         00444909     TEST       EAX,EAX
    //         0044490b     JZ         LAB_0044497b
    //                               LAB_0044490d                                                 XREF[2]:     004448f0(j), 004448f9(j)  
    //                              Drawarea.cpp:2732 (9)
    //         0044490d     MOV        EAX,dword ptr [EDI + 0xc0]
    //         00444913     MOV        dword ptr [EBP + SrcP],EAX
    //                              Drawarea.cpp:2736 (1)
    //         00444916     PUSH       ESI
    //                              Drawarea.cpp:2737 (1)
    //         00444917     PUSH       EDI
    //                              Drawarea.cpp:2738 (1)
    //         00444918     PUSH       EBX
    //                              Drawarea.cpp:2739 (1)
    //         00444919     CLD
    //                              Drawarea.cpp:2741 (3)
    //         0044491a     MOV        EDX,dword ptr [EBP + param_2]
    //                              Drawarea.cpp:2742 (2)
    //         0044491d     MOV        AL,DL
    //                              Drawarea.cpp:2743 (2)
    //         0044491f     MOV        AH,DL
    //                              Drawarea.cpp:2744 (3)
    //         00444921     SHL        EAX,0x10
    //                              Drawarea.cpp:2745 (2)
    //         00444924     MOV        AL,DL
    //                              Drawarea.cpp:2746 (2)
    //         00444926     MOV        AH,AL
    //                              Symbol Ref: No symbol: PtrClearLoop
    //                               LAB_00444928                                                 XREF[1]:     0044495a(j)  
    //                              Drawarea.cpp:2750 (3)
    //         00444928     MOV        EBX,dword ptr [EBP + param_1]
    //                              Drawarea.cpp:2751 (3)
    //         0044492b     MOV        EDI,dword ptr [EBP + SrcP]
    //                              Drawarea.cpp:2752 (3)
    //         0044492e     MOV        EDI,dword ptr [EDI + EBX*0x4]
    //                              Drawarea.cpp:2753 (3)
    //         00444931     ADD        EDI,dword ptr [EBP + x1]
    //                              Drawarea.cpp:2755 (3)
    //         00444934     MOV        this,dword ptr [EBP + nWidth]
    //                              Drawarea.cpp:2759 (2)
    //         00444937     MOV        EDX,this
    //                              Drawarea.cpp:2760 (2)
    //         00444939     SUB        this,EDI
    //                              Drawarea.cpp:2761 (2)
    //         0044493b     SUB        this,EDX
    //                              Drawarea.cpp:2762 (3)
    //         0044493d     AND        this,0x3
    //                              Drawarea.cpp:2763 (2)
    //         00444940     SUB        EDX,this
    //                              Drawarea.cpp:2764 (2)
    //         00444942     JLE        LAB_00444950
    //                              Drawarea.cpp:2765 (2)
    //         00444944     STOSB.REP  ES:EDI
    //                              Drawarea.cpp:2766 (2)
    //         00444946     MOV        this,EDX
    //                              Drawarea.cpp:2767 (3)
    //         00444948     AND        EDX,0x3
    //                              Drawarea.cpp:2768 (3)
    //         0044494b     SHR        this,0x2
    //                              Drawarea.cpp:2769 (2)
    //         0044494e     STOSD.REP  ES:EDI
    //                              Symbol Ref: No symbol: PtrClearLEndBytes
    //                               LAB_00444950                                                 XREF[1]:     00444942(j)  
    //                              Drawarea.cpp:2771 (2)
    //         00444950     ADD        this,EDX
    //                              Drawarea.cpp:2772 (2)
    //         00444952     STOSB.REP  ES:EDI
    //                              Drawarea.cpp:2776 (3)
    //         00444954     INC        dword ptr [EBP + param_1]
    //                              Drawarea.cpp:2778 (3)
    //         00444957     DEC        dword ptr [EBP + nLines]
    //                              Drawarea.cpp:2779 (2)
    //         0044495a     JNZ        LAB_00444928
    //                              Drawarea.cpp:2781 (1)
    //         0044495c     POP        EBX
    //                              Drawarea.cpp:2782 (1)
    //         0044495d     POP        EDI
    //                              Drawarea.cpp:2783 (1)
    //         0044495e     POP        ESI
    //                              Drawarea.cpp:2787 (18)
    //         0044495f     MOV        this,dword ptr [EBP + local_18]
    //         00444962     MOV        EAX,dword ptr [this->DrawSystem]
    //         00444964     TEST       EAX,EAX
    //         00444966     JZ         LAB_0044497b
    //         00444968     CMP        byte ptr [EAX + 0x478],0x2
    //         0044496f     JNZ        LAB_0044497b
    //                              Drawarea.cpp:2789 (10)
    //         00444971     PUSH       s_PtrClear                                       = "PtrClear"
    //         00444976     CALL       TDrawArea::Unlock                                void Unlock(TDrawArea * this, char * param_1)
    //                               LAB_0044497b                                                 XREF[9]:     0044488a(j), 00444892(j), 
    //                                                                                                         0044489b(j), 004448a3(j), 
    //                                                                                                         004448ab(j), 004448b4(j), 
    //                                                                                                         0044490b(j), 00444966(j), 
    //                                                                                                         0044496f(j)  
    //                              Drawarea.cpp:2793 (9)
    //         0044497b     POP        EDI
    //         0044497c     POP        ESI
    //         0044497d     POP        EBX
    //         0044497e     MOV        ESP,EBP
    //         00444980     POP        EBP
    //         00444981     RET        0x8
}

// Offset: 0x00444990
void SetAccessOffsets(TDrawArea* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TDrawArea::SetAccessOffsets(void)                                             *
    //                              *********************************************************************************************************
    //                              void __thiscall SetAccessOffsets(TDrawArea * this)
    //              void              <VOID>         <RETURN>
    //              TDrawArea *       ECX:4 (auto)   this
    //                               ?SetAccessOffsets@TDrawArea@@QAEXXZ                          XREF[2]:     Lock:004442e5(c), 
    //                               TDrawArea::SetAccessOffsets                                               SetSize:00444572(c)  
    //                              Drawarea.cpp:2804 (4)
    //         00444990     PUSH       ESI
    //         00444991     MOV        ESI,this
    //         00444993     PUSH       EDI
    //                              Drawarea.cpp:2808 (3)
    //         00444994     MOV        EDI,dword ptr [ESI + 0x1c]
    //                              Drawarea.cpp:2809 (13)
    //         00444997     MOV        EAX,dword ptr [ESI + 0xdc]
    //         0044499d     SHL        EDI,0x2
    //         004449a0     CMP        EDI,EAX
    //         004449a2     JZ         LAB_004449d2
    //                              Drawarea.cpp:2811 (19)
    //         004449a4     MOV        EAX,dword ptr [ESI + 0xbc]
    //         004449aa     TEST       EAX,EAX
    //         004449ac     JZ         LAB_004449b7
    //         004449ae     PUSH       EAX
    //         004449af     CALL       free                                             undefined free()
    //         004449b4     ADD        ESP,0x4
    //                               LAB_004449b7                                                 XREF[1]:     004449ac(j)  
    //                              Drawarea.cpp:2813 (15)
    //         004449b7     PUSH       EDI
    //         004449b8     CALL       malloc                                           undefined malloc()
    //         004449bd     ADD        ESP,0x4
    //         004449c0     MOV        dword ptr [ESI + 0xbc],EAX
    //                              Drawarea.cpp:2814 (6)
    //         004449c6     MOV        dword ptr [ESI + 0xdc],EDI
    //                              Drawarea.cpp:2815 (6)
    //         004449cc     MOV        dword ptr [ESI + 0xc0],EAX
    //                               LAB_004449d2                                                 XREF[1]:     004449a2(j)  
    //                              Drawarea.cpp:2822 (16)
    //         004449d2     CMP        dword ptr [ESI + 0x24],0x1
    //         004449d6     JZ         LAB_004449f5
    //         004449d8     MOV        EAX,dword ptr [ESI + 0xf8]
    //         004449de     TEST       EAX,EAX
    //         004449e0     JNZ        LAB_004449f5
    //                              Drawarea.cpp:2835 (15)
    //         004449e2     MOV        EAX,dword ptr [ESI + 0x1c]
    //         004449e5     MOV        EDX,dword ptr [ESI + 0x20]
    //         004449e8     DEC        EAX
    //         004449e9     MOV        EDI,dword ptr [ESI + 0x8]
    //         004449ec     IMUL       EAX,EDX
    //         004449ef     ADD        EAX,EDI
    //                              Drawarea.cpp:2839 (4)
    //         004449f1     NEG        EDX
    //         004449f3     JMP        LAB_00444a19
    //                               LAB_004449f5                                                 XREF[2]:     004449d6(j), 004449e0(j)  
    //                              Drawarea.cpp:2824 (10)
    //         004449f5     MOV        this,dword ptr [ESI + 0xf8]
    //         004449fb     TEST       this,this
    //         004449fd     JNZ        LAB_00444a04
    //                              Drawarea.cpp:2825 (3)
    //         004449ff     MOV        EAX,dword ptr [ESI + 0x8]
    //                              Drawarea.cpp:2826 (2)
    //         00444a02     JMP        LAB_00444a0f
    //                               LAB_00444a04                                                 XREF[1]:     004449fd(j)  
    //                              Drawarea.cpp:2827 (11)
    //         00444a04     MOV        EAX,dword ptr [ESI + 0x20]
    //         00444a07     MOV        EDX,dword ptr [ESI + 0x8]
    //         00444a0a     LEA        EAX,[EAX + EAX*0x4]
    //         00444a0d     ADD        EAX,EDX
    //                               LAB_00444a0f                                                 XREF[1]:     00444a02(j)  
    //                              Drawarea.cpp:2829 (3)
    //         00444a0f     MOV        EDX,dword ptr [ESI + 0x20]
    //                              Drawarea.cpp:2830 (7)
    //         00444a12     TEST       this,this
    //         00444a14     JZ         LAB_00444a19
    //         00444a16     MOV        EDX,dword ptr [ESI + 0x18]
    //                               LAB_00444a19                                                 XREF[2]:     004449f3(j), 00444a14(j)  
    //                              Drawarea.cpp:2842 (9)
    //         00444a19     MOV        EDI,dword ptr [ESI + 0x1c]
    //         00444a1c     XOR        this,this
    //         00444a1e     TEST       EDI,EDI
    //         00444a20     JLE        LAB_00444a35
    //                               LAB_00444a22                                                 XREF[1]:     00444a33(j)  
    //                              Drawarea.cpp:2844 (12)
    //         00444a22     MOV        EDI,dword ptr [ESI + 0xbc]
    //         00444a28     MOV        dword ptr [EDI + this->DrawSystem*0x4],EAX
    //         00444a2b     MOV        EDI,dword ptr [ESI + 0x1c]
    //                              Drawarea.cpp:2845 (7)
    //         00444a2e     ADD        EAX,EDX
    //         00444a30     INC        this
    //         00444a31     CMP        this,EDI
    //         00444a33     JL         LAB_00444a22
    //                               LAB_00444a35                                                 XREF[1]:     00444a20(j)  
    //                              Drawarea.cpp:2849 (31)
    //         00444a35     MOV        EAX,dword ptr [ESI + 0xc4]
    //         00444a3b     TEST       EAX,EAX
    //         00444a3d     JZ         LAB_00444a54
    //         00444a3f     MOV        EAX,dword ptr [ESI + 0xd8]
    //         00444a45     MOV        this,dword ptr [ESI + 0xd4]
    //         00444a4b     PUSH       EAX
    //         00444a4c     PUSH       this
    //         00444a4d     MOV        this,ESI
    //         00444a4f     CALL       TDrawArea::SetFloatOffsets                       void SetFloatOffsets(TDrawArea * this, int pa
    //                               LAB_00444a54                                                 XREF[1]:     00444a3d(j)  
    //                              Drawarea.cpp:2853 (3)
    //         00444a54     MOV        EDX,dword ptr [ESI + 0x8]
    //                              Drawarea.cpp:2855 (9)
    //         00444a57     POP        EDI
    //         00444a58     MOV        dword ptr [ESI + 0xb4],EDX
    //         00444a5e     POP        ESI
    //         00444a5f     RET
}

// Offset: 0x00444A60
void SetFloatOffsets(TDrawArea* this_, int param_2, int param_3) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TDrawArea::SetFloatOffsets(int,int)                                           *
    //                              *********************************************************************************************************
    //                              void __thiscall SetFloatOffsets(TDrawArea * this, int param_1, int p
    //              void              <VOID>         <RETURN>
    //              TDrawArea *       ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     00444a80(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     00444a88(R)  
    //                               ?SetFloatOffsets@TDrawArea@@QAEXHH@Z                         XREF[4]:     SetAccessOffsets:00444a4f(c), 
    //                               TDrawArea::SetFloatOffsets                                                create_surfaces:00534215(c), 
    //                                                                                                         draw:00534f61(c), 
    //                                                                                                         draw:00535189(c)  
    //                              Drawarea.cpp:2862 (6)
    //         00444a60     PUSH       EBX
    //         00444a61     PUSH       EBP
    //         00444a62     PUSH       ESI
    //         00444a63     MOV        ESI,this
    //         00444a65     PUSH       EDI
    //                              Drawarea.cpp:2867 (6)
    //         00444a66     MOV        EBX,dword ptr [ESI + 0x1c]
    //         00444a69     SHL        EBX,0x2
    //                              Drawarea.cpp:2869 (6)
    //         00444a6c     JZ         LAB_00444b06
    //                              Drawarea.cpp:2871 (14)
    //         00444a72     MOV        EAX,dword ptr [ESI + 0xf8]
    //         00444a78     TEST       EAX,EAX
    //         00444a7a     JZ         LAB_00444b06
    //                              Drawarea.cpp:2872 (8)
    //         00444a80     MOV        EDI,dword ptr [ESP + param_1]
    //         00444a84     TEST       EDI,EDI
    //         00444a86     JL         LAB_00444b06
    //                              Drawarea.cpp:2873 (8)
    //         00444a88     MOV        EBP,dword ptr [ESP + param_2]
    //         00444a8c     TEST       EBP,EBP
    //         00444a8e     JL         LAB_00444b06
    //                              Drawarea.cpp:2875 (8)
    //         00444a90     CMP        EBX,dword ptr [ESI + 0xe0]
    //         00444a96     JZ         LAB_00444ac0
    //                              Drawarea.cpp:2877 (19)
    //         00444a98     MOV        EAX,dword ptr [ESI + 0xc4]
    //         00444a9e     TEST       EAX,EAX
    //         00444aa0     JZ         LAB_00444aab
    //         00444aa2     PUSH       EAX
    //         00444aa3     CALL       free                                             undefined free()
    //         00444aa8     ADD        ESP,0x4
    //                               LAB_00444aab                                                 XREF[1]:     00444aa0(j)  
    //                              Drawarea.cpp:2879 (15)
    //         00444aab     PUSH       EBX
    //         00444aac     CALL       malloc                                           undefined malloc()
    //         00444ab1     ADD        ESP,0x4
    //         00444ab4     MOV        dword ptr [ESI + 0xc4],EAX
    //                              Drawarea.cpp:2880 (6)
    //         00444aba     MOV        dword ptr [ESI + 0xe0],EBX
    //                               LAB_00444ac0                                                 XREF[1]:     00444a96(j)  
    //                              Drawarea.cpp:2883 (11)
    //         00444ac0     MOV        this,dword ptr [ESI + 0x1c]
    //         00444ac3     XOR        EDX,EDX
    //         00444ac5     TEST       this,this
    //         00444ac7     MOV        EAX,EBP
    //         00444ac9     JLE        LAB_00444aee
    //                               LAB_00444acb                                                 XREF[1]:     00444aec(j)  
    //                              Drawarea.cpp:2885 (17)
    //         00444acb     MOV        this,dword ptr [ESI + 0xbc]
    //         00444ad1     MOV        EBX,dword ptr [ESI + 0xc4]
    //         00444ad7     MOV        this,dword ptr [this->DrawSystem + EAX*0x4]
    //         00444ada     ADD        this,EDI
    //                              Drawarea.cpp:2886 (4)
    //         00444adc     INC        EAX
    //         00444add     MOV        dword ptr [EBX + EDX*0x4],this
    //                              Drawarea.cpp:2887 (9)
    //         00444ae0     MOV        this,dword ptr [ESI + 0x1c]
    //         00444ae3     CMP        EAX,this
    //         00444ae5     JL         LAB_00444ae9
    //         00444ae7     XOR        EAX,EAX
    //                               LAB_00444ae9                                                 XREF[1]:     00444ae5(j)  
    //                              Drawarea.cpp:2883 (5)
    //         00444ae9     INC        EDX
    //         00444aea     CMP        EDX,this
    //         00444aec     JL         LAB_00444acb
    //                               LAB_00444aee                                                 XREF[1]:     00444ac9(j)  
    //                              Drawarea.cpp:2893 (24)
    //         00444aee     MOV        EDX,dword ptr [ESI + 0xc4]
    //         00444af4     MOV        dword ptr [ESI + 0xd4],EDI
    //         00444afa     MOV        dword ptr [ESI + 0xd8],EBP
    //         00444b00     MOV        dword ptr [ESI + 0xc0],EDX
    //                               LAB_00444b06                                                 XREF[4]:     00444a6c(j), 00444a7a(j), 
    //                                                                                                         00444a86(j), 00444a8e(j)  
    //                              Drawarea.cpp:2895 (7)
    //         00444b06     POP        EDI
    //         00444b07     POP        ESI
    //         00444b08     POP        EBP
    //         00444b09     POP        EBX
    //         00444b0a     RET        0x8
}

// Offset: 0x00444B10
void SetInfo(TDrawArea* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TDrawArea::SetInfo(void)                                                      *
    //                              *********************************************************************************************************
    //                              void __thiscall SetInfo(TDrawArea * this)
    //              void              <VOID>         <RETURN>
    //              TDrawArea *       ECX:4 (auto)   this
    //                               ?SetInfo@TDrawArea@@QAEXXZ                                   XREF[2]:     Lock:004442d1(c), 
    //                               TDrawArea::SetInfo                                                        SetSize:0044456b(c)  
    //                              Drawarea.cpp:2904 (3)
    //         00444b10     MOV        EAX,dword ptr [ECX + this+0x50]
    //                              Drawarea.cpp:2907 (9)
    //         00444b13     MOV        EDX,dword ptr [ECX + this->BitmapInfo]
    //         00444b16     MOV        dword ptr [ECX + this->Pitch],EAX
    //         00444b19     MOV        dword ptr [EDX + 0x4],EAX
    //                              Drawarea.cpp:2909 (11)
    //         00444b1c     MOV        EAX,dword ptr [ECX + this+0xa8]
    //         00444b22     TEST       AH,0x8
    //         00444b25     JZ         LAB_00444b32
    //                              Drawarea.cpp:2910 (10)
    //         00444b27     MOV        dword ptr [ECX + this->UsingVidMem],0x0
    //                              Drawarea.cpp:2913 (1)
    //         00444b31     RET
    //                               LAB_00444b32                                                 XREF[1]:     00444b25(j)  
    //                              Drawarea.cpp:2912 (10)
    //         00444b32     MOV        dword ptr [ECX + this->UsingVidMem],0x1
    //                              Drawarea.cpp:2913 (1)
    //         00444b3c     RET
}

// Offset: 0x00444B40
long AlignedWidth(TDrawArea* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: long __thiscall TDrawArea::AlignedWidth(void)                                                 *
    //                              *********************************************************************************************************
    //                              long __thiscall AlignedWidth(TDrawArea * this)
    //              long              EAX:4          <RETURN>
    //              TDrawArea *       ECX:4 (auto)   this
    //                               ?AlignedWidth@TDrawArea@@QAEJXZ                              XREF[16]:    DrawShadowBox:004462cc(c), 
    //                               TDrawArea::AlignedWidth                                                   draw:00449f39(c), 
    //                                                                                                         shape_draw_unclipped:004b980d(c), 
    //                                                                                                         shape_color_trans_unclipped:004b98
    //                                                                                                         shape_shadow_unclipped:004b9a0d(c)
    //                                                                                                         shape_draw_clipped:004b9b02(c), 
    //                                                                                                         shape_color_trans_clipped:004b9e32
    //                                                                                                         shape_shadow_clipped:004ba1d2(c), 
    //                                                                                                         shape_mirror_unclipped:004ba90f(c)
    //                                                                                                         shape_mirror_color_trans_unclipped
    //                                                                                                         shape_mirror_shadow_unclipped:004b
    //                                                                                                         shape_mirror_clipped:004bac12(c), 
    //                                                                                                         shape_mirror_color_trans_clipped:0
    //                                                                                                         shape_mirror_shadow_clipped:004bb2
    //                                                                                                         shape_dithered_unclipped:004bb782(
    //                                                                                                         shape_dithered_clipped:004bb922(c)
    //                              Drawarea.cpp:2919 (3)
    //         00444b40     MOV        EAX,dword ptr [ECX + this->Pitch]
    //                              Drawarea.cpp:2921 (1)
    //         00444b43     RET
}

// Offset: 0x00444B50
void SetClipRect(TDrawArea* this_, tagRECT* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TDrawArea::SetClipRect(struct tagRECT *)                                      *
    //                              *********************************************************************************************************
    //                              void __thiscall SetClipRect(TDrawArea * this, tagRECT * param_1)
    //              void              <VOID>         <RETURN>
    //              TDrawArea *       ECX:4 (auto)   this
    //              tagRECT *         Stack[0x4]:4   param_1                   XREF[1]:     00444b50(R)  
    //                               ?SetClipRect@TDrawArea@@QAEXPAUtagRECT@@@Z                   XREF[18]:    SetSize:004445c0(c), 
    //                               TDrawArea::SetClipRect                                                    draw_setup:00465343(c), 
    //                                                                                                         draw_finish:00465392(c), 
    //                                                                                                         render_to_image_buffer:00479b8b(c)
    //                                                                                                         draw_button_pic:0047b99c(c), 
    //                                                                                                         draw:0049b5fb(c), 
    //                                                                                                         draw:0049b708(c), 
    //                                                                                                         render_to_image_buffer:0051d547(c)
    //                                                                                                         render_to_image_buffer:0051e307(c)
    //                                                                                                         draw_multi_object_outline:0052cb31
    //                                                                                                         draw_multi_object_outline:0052cc58
    //                                                                                                         draw_multi_object_outline:0052cc92
    //                                                                                                         draw_multi_object_outline:0052ccca
    //                                                                                                         draw_multi_object_outline:0052cd00
    //                                                                                                         draw_multi_object_outline:0052ce02
    //                                                                                                         draw_multi_object_outline:0052ceac
    //                                                                                                         draw_multi_object_outline:0052cfa6
    //                                                                                                         draw_multi_object_outline:0052d04c
    //                              Drawarea.cpp:2927 (15)
    //         00444b50     MOV        EAX,dword ptr [ESP + param_1]
    //         00444b54     PUSH       ESI
    //         00444b55     XOR        ESI,ESI
    //         00444b57     CMP        EAX,ESI
    //         00444b59     JZ         LAB_00444bf4
    //                              Drawarea.cpp:2932 (5)
    //         00444b5f     MOV        EDX,dword ptr [EAX]
    //         00444b61     MOV        dword ptr [ECX + this->ClipRect.left],EDX
    //                              Drawarea.cpp:2933 (6)
    //         00444b64     MOV        EDX,dword ptr [EAX + 0x4]
    //         00444b67     MOV        dword ptr [ECX + this+0x2c],EDX
    //                              Drawarea.cpp:2934 (6)
    //         00444b6a     MOV        EDX,dword ptr [EAX + 0x8]
    //         00444b6d     MOV        dword ptr [ECX + this+0x30],EDX
    //                              Drawarea.cpp:2935 (6)
    //         00444b70     MOV        EAX,dword ptr [EAX + 0xc]
    //         00444b73     MOV        dword ptr [ECX + this+0x34],EAX
    //                              Drawarea.cpp:2937 (7)
    //         00444b76     MOV        EAX,dword ptr [ECX + this->ClipRect.left]
    //         00444b79     CMP        EAX,ESI
    //         00444b7b     JGE        LAB_00444b82
    //                              Drawarea.cpp:2938 (3)
    //         00444b7d     MOV        dword ptr [ECX + this->ClipRect.left],ESI
    //                              Drawarea.cpp:2939 (10)
    //         00444b80     JMP        LAB_00444b8d
    //                               LAB_00444b82                                                 XREF[1]:     00444b7b(j)  
    //         00444b82     MOV        EDX,dword ptr [ECX + this->Width]
    //         00444b85     DEC        EDX
    //         00444b86     CMP        EAX,EDX
    //         00444b88     JLE        LAB_00444b8d
    //                              Drawarea.cpp:2940 (3)
    //         00444b8a     MOV        dword ptr [ECX + this->ClipRect.left],EDX
    //                               LAB_00444b8d                                                 XREF[2]:     00444b80(j), 00444b88(j)  
    //                              Drawarea.cpp:2942 (7)
    //         00444b8d     MOV        EDX,dword ptr [ECX + this+0x30]
    //         00444b90     CMP        EDX,ESI
    //         00444b92     JGE        LAB_00444b99
    //                              Drawarea.cpp:2943 (3)
    //         00444b94     MOV        dword ptr [ECX + this+0x30],ESI
    //                              Drawarea.cpp:2944 (10)
    //         00444b97     JMP        LAB_00444ba4
    //                               LAB_00444b99                                                 XREF[1]:     00444b92(j)  
    //         00444b99     MOV        EAX,dword ptr [ECX + this->Width]
    //         00444b9c     DEC        EAX
    //         00444b9d     CMP        EDX,EAX
    //         00444b9f     JLE        LAB_00444ba4
    //                              Drawarea.cpp:2945 (3)
    //         00444ba1     MOV        dword ptr [ECX + this+0x30],EAX
    //                               LAB_00444ba4                                                 XREF[2]:     00444b97(j), 00444b9f(j)  
    //                              Drawarea.cpp:2947 (7)
    //         00444ba4     MOV        EDX,dword ptr [ECX + this+0x2c]
    //         00444ba7     CMP        EDX,ESI
    //         00444ba9     JGE        LAB_00444bb0
    //                              Drawarea.cpp:2948 (3)
    //         00444bab     MOV        dword ptr [ECX + this+0x2c],ESI
    //                              Drawarea.cpp:2949 (10)
    //         00444bae     JMP        LAB_00444bbb
    //                               LAB_00444bb0                                                 XREF[1]:     00444ba9(j)  
    //         00444bb0     MOV        EAX,dword ptr [ECX + this->Height]
    //         00444bb3     DEC        EAX
    //         00444bb4     CMP        EDX,EAX
    //         00444bb6     JLE        LAB_00444bbb
    //                              Drawarea.cpp:2950 (3)
    //         00444bb8     MOV        dword ptr [ECX + this+0x2c],EAX
    //                               LAB_00444bbb                                                 XREF[2]:     00444bae(j), 00444bb6(j)  
    //                              Drawarea.cpp:2952 (7)
    //         00444bbb     MOV        EDX,dword ptr [ECX + this+0x34]
    //         00444bbe     CMP        EDX,ESI
    //         00444bc0     JGE        LAB_00444bc7
    //                              Drawarea.cpp:2953 (3)
    //         00444bc2     MOV        dword ptr [ECX + this+0x34],ESI
    //                              Drawarea.cpp:2954 (10)
    //         00444bc5     JMP        LAB_00444bd2
    //                               LAB_00444bc7                                                 XREF[1]:     00444bc0(j)  
    //         00444bc7     MOV        EAX,dword ptr [ECX + this->Height]
    //         00444bca     DEC        EAX
    //         00444bcb     CMP        EDX,EAX
    //         00444bcd     JLE        LAB_00444bd2
    //                              Drawarea.cpp:2955 (3)
    //         00444bcf     MOV        dword ptr [ECX + this+0x34],EAX
    //                               LAB_00444bd2                                                 XREF[2]:     00444bc5(j), 00444bcd(j)  
    //                              Drawarea.cpp:2957 (10)
    //         00444bd2     MOV        EAX,dword ptr [ECX + this+0x30]
    //         00444bd5     MOV        EDX,dword ptr [ECX + this->ClipRect.left]
    //         00444bd8     CMP        EAX,EDX
    //         00444bda     JGE        LAB_00444be2
    //                              Drawarea.cpp:2960 (3)
    //         00444bdc     MOV        dword ptr [ECX + this+0x30],EDX
    //                              Drawarea.cpp:2961 (3)
    //         00444bdf     MOV        dword ptr [ECX + this->ClipRect.left],EAX
    //                               LAB_00444be2                                                 XREF[1]:     00444bda(j)  
    //                              Drawarea.cpp:2964 (10)
    //         00444be2     MOV        EAX,dword ptr [ECX + this+0x34]
    //         00444be5     MOV        EDX,dword ptr [ECX + this+0x2c]
    //         00444be8     CMP        EAX,EDX
    //         00444bea     JGE        LAB_00444c08
    //                              Drawarea.cpp:2967 (3)
    //         00444bec     MOV        dword ptr [ECX + this+0x34],EDX
    //                              Drawarea.cpp:2968 (3)
    //         00444bef     MOV        dword ptr [ECX + this+0x2c],EAX
    //                              Drawarea.cpp:2971 (2)
    //         00444bf2     JMP        LAB_00444c08
    //                               LAB_00444bf4                                                 XREF[1]:     00444b59(j)  
    //                              Drawarea.cpp:2975 (3)
    //         00444bf4     MOV        EDX,dword ptr [ECX + this->Width]
    //                              Drawarea.cpp:2976 (17)
    //         00444bf7     MOV        EAX,dword ptr [ECX + this->Height]
    //         00444bfa     DEC        EDX
    //         00444bfb     DEC        EAX
    //         00444bfc     MOV        dword ptr [ECX + this->ClipRect.left],ESI
    //         00444bff     MOV        dword ptr [ECX + this+0x2c],ESI
    //         00444c02     MOV        dword ptr [ECX + this+0x30],EDX
    //         00444c05     MOV        dword ptr [ECX + this+0x34],EAX
    //                               LAB_00444c08                                                 XREF[2]:     00444bea(j), 00444bf2(j)  
    //                              Drawarea.cpp:2979 (21)
    //         00444c08     MOV        EDX,dword ptr [ECX + this+0x34]
    //         00444c0b     MOV        EAX,dword ptr [ECX + this+0x30]
    //         00444c0e     PUSH       EDX
    //         00444c0f     MOV        EDX,dword ptr [ECX + this+0x2c]
    //         00444c12     PUSH       EAX
    //         00444c13     MOV        EAX,dword ptr [ECX + this->ClipRect.left]
    //         00444c16     PUSH       EDX
    //         00444c17     PUSH       EAX
    //         00444c18     CALL       TDrawArea::SetClipRect                           void SetClipRect(TDrawArea * this, long param
    //                              Drawarea.cpp:2980 (4)
    //         00444c1d     POP        ESI
    //         00444c1e     RET        0x4
}

// Offset: 0x00444C30
void SetClipRect(TDrawArea* this_, long param_2, long param_3, long param_4, long param_5) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TDrawArea::SetClipRect(long,long,long,long)                                   *
    //                              *********************************************************************************************************
    //                              void __thiscall SetClipRect(TDrawArea * this, long param_1, long par
    //              void              <VOID>         <RETURN>
    //              TDrawArea *       ECX:4 (auto)   this
    //              long              Stack[0x4]:4   param_1                   XREF[2]:     00444c3e(R), 00444cab(W)  
    //              long              Stack[0x8]:4   param_2                   XREF[1]:     00444c51(R)  
    //              long              Stack[0xc]:4   param_3                   XREF[1]:     00444c42(R)  
    //              long              Stack[0x10]:4  param_4                   XREF[1]:     00444c5e(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     00444cb1(W), 00444cce(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     00444d2e(R)  
    //                               ?SetClipRect@TDrawArea@@QAEXJJJJ@Z                           XREF[4]:     SetClipRect:00444c18(c), 
    //                               TDrawArea::SetClipRect                                                    draw:0051a345(c), 
    //                                                                                                         draw:0051a374(c), 
    //                                                                                                         draw:0051a39e(c)  
    //                              Drawarea.cpp:2986 (14)
    //         00444c30     MOV        EAX,FS:[0x0]
    //         00444c36     PUSH       -0x1
    //         00444c38     PUSH       FUN_0055d32b
    //         00444c3d     PUSH       EAX
    //                              Drawarea.cpp:2989 (4)
    //         00444c3e     MOV        EAX,dword ptr [ESP + param_1]
    //                              Drawarea.cpp:2991 (19)
    //         00444c42     MOV        EDX,dword ptr [ESP + param_3]
    //         00444c46     MOV        dword ptr FS:[0x0],ESP
    //         00444c4d     PUSH       ESI
    //         00444c4e     MOV        ESI,this
    //         00444c50     PUSH       EDI
    //         00444c51     MOV        this,dword ptr [ESP + param_2]
    //                              Drawarea.cpp:2996 (26)
    //         00444c55     MOV        EDI,dword ptr [ESI + 0xcc]
    //         00444c5b     MOV        dword ptr [ESI + 0x28],EAX
    //         00444c5e     MOV        EAX,dword ptr [ESP + param_4]
    //         00444c62     MOV        dword ptr [ESI + 0x2c],this
    //         00444c65     TEST       EDI,EDI
    //         00444c67     MOV        dword ptr [ESI + 0x30],EDX
    //         00444c6a     MOV        dword ptr [ESI + 0x34],EAX
    //         00444c6d     JZ         LAB_00444c97
    //                              Drawarea.cpp:2998 (10)
    //         00444c6f     MOV        EAX,dword ptr [EDI + 0x50]
    //         00444c72     MOV        this,dword ptr [ESI + 0x1c]
    //         00444c75     CMP        this,EAX
    //         00444c77     JZ         LAB_00444c97
    //                              Drawarea.cpp:3000 (20)
    //         00444c79     TEST       EDI,EDI
    //         00444c7b     JZ         LAB_00444c8d
    //         00444c7d     MOV        this,EDI
    //         00444c7f     CALL       TSpan_List_Manager::~TSpan_List_Manager          void ~TSpan_List_Manager(TSpan_List_Manager *
    //         00444c84     PUSH       EDI
    //         00444c85     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         00444c8a     ADD        ESP,0x4
    //                               LAB_00444c8d                                                 XREF[1]:     00444c7b(j)  
    //                              Drawarea.cpp:3001 (10)
    //         00444c8d     MOV        dword ptr [ESI + 0xcc],0x0
    //                               LAB_00444c97                                                 XREF[2]:     00444c6d(j), 00444c77(j)  
    //                              Drawarea.cpp:3005 (69)
    //         00444c97     MOV        EAX,dword ptr [ESI + 0xcc]
    //         00444c9d     TEST       EAX,EAX
    //         00444c9f     JNZ        LAB_00444cdc
    //                              language.dll match for 0x68: "Arial"
    //         00444ca1     PUSH       0x68
    //         00444ca3     CALL       operator_new                                     void * operator_new(uint param_1)
    //         00444ca8     ADD        ESP,0x4
    //         00444cab     MOV        dword ptr [ESP + param_1],EAX
    //         00444caf     TEST       EAX,EAX
    //         00444cb1     MOV        dword ptr [ESP + local_4],0x0
    //         00444cb9     JZ         LAB_00444ccc
    //         00444cbb     MOV        this,dword ptr [ESI + 0x1c]
    //         00444cbe     MOV        EDX,dword ptr [ESI + 0x18]
    //         00444cc1     PUSH       this
    //         00444cc2     PUSH       EDX
    //         00444cc3     MOV        this,EAX
    //         00444cc5     CALL       TSpan_List_Manager::TSpan_List_Manager           undefined TSpan_List_Manager(TSpan_List_Manag
    //         00444cca     JMP        LAB_00444cce
    //                               LAB_00444ccc                                                 XREF[1]:     00444cb9(j)  
    //         00444ccc     XOR        EAX,EAX
    //                               LAB_00444cce                                                 XREF[1]:     00444cca(j)  
    //         00444cce     MOV        dword ptr [ESP + local_4],0xffffffff
    //         00444cd6     MOV        dword ptr [ESI + 0xcc],EAX
    //                               LAB_00444cdc                                                 XREF[1]:     00444c9f(j)  
    //                              Drawarea.cpp:3007 (11)
    //         00444cdc     MOV        this,dword ptr [ESI + 0xcc]
    //         00444ce2     CALL       TSpan_List_Manager::ResetAll                     void ResetAll(TSpan_List_Manager * this)
    //                              Drawarea.cpp:3008 (27)
    //         00444ce7     MOV        EAX,dword ptr [ESI + 0x34]
    //         00444cea     MOV        this,dword ptr [ESI + 0x30]
    //         00444ced     MOV        EDX,dword ptr [ESI + 0x2c]
    //         00444cf0     PUSH       EAX
    //         00444cf1     MOV        EAX,dword ptr [ESI + 0x28]
    //         00444cf4     PUSH       this
    //         00444cf5     MOV        this,dword ptr [ESI + 0xcc]
    //         00444cfb     PUSH       EDX
    //         00444cfc     PUSH       EAX
    //         00444cfd     CALL       TSpan_List_Manager::SetSpanRegions               void SetSpanRegions(TSpan_List_Manager * this
    //                              Drawarea.cpp:3010 (10)
    //         00444d02     MOV        EDI,dword ptr [ESI + 0x2c]
    //         00444d05     MOV        EAX,dword ptr [ESI + 0x34]
    //         00444d08     CMP        EDI,EAX
    //         00444d0a     JG         LAB_00444d28
    //                               LAB_00444d0c                                                 XREF[1]:     00444d26(j)  
    //                              Drawarea.cpp:3011 (28)
    //         00444d0c     MOV        this,dword ptr [ESI + 0x30]
    //         00444d0f     MOV        EDX,dword ptr [ESI + 0x28]
    //         00444d12     PUSH       EDI
    //         00444d13     PUSH       this
    //         00444d14     MOV        this,dword ptr [ESI + 0xcc]
    //         00444d1a     PUSH       EDX
    //         00444d1b     CALL       TSpan_List_Manager::AddSpan                      void AddSpan(TSpan_List_Manager * this, int p
    //         00444d20     MOV        EAX,dword ptr [ESI + 0x34]
    //         00444d23     INC        EDI
    //         00444d24     CMP        EDI,EAX
    //         00444d26     JLE        LAB_00444d0c
    //                               LAB_00444d28                                                 XREF[1]:     00444d0a(j)  
    //                              Drawarea.cpp:3013 (6)
    //         00444d28     MOV        EAX,dword ptr [ESI + 0xcc]
    //                              Drawarea.cpp:3015 (25)
    //         00444d2e     MOV        this,dword ptr [ESP + local_c]
    //         00444d32     MOV        dword ptr [ESI + 0xd0],EAX
    //         00444d38     POP        EDI
    //         00444d39     MOV        dword ptr FS:[0x0],this
    //         00444d40     POP        ESI
    //         00444d41     ADD        ESP,0xc
    //         00444d44     RET        0x10
}

// Offset: 0x00444D50
void Copy(TDrawArea* this_, TDrawArea* param_2, long param_3, long param_4, tagRECT* param_5, int param_6) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TDrawArea::Copy(class TDrawArea *,long,long,struct tagRECT *,int)             *
    //                              *********************************************************************************************************
    //                              void __thiscall Copy(TDrawArea * this, TDrawArea * param_1, long par
    //              void              <VOID>         <RETURN>
    //              TDrawArea *       ECX:4 (auto)   this
    //              TDrawArea *       Stack[0x4]:4   param_1                   XREF[4]:     00444d7b(R), 00444e09(R), 00444e53(R), 00444e89(R)  
    //              long              Stack[0x8]:4   param_2                   XREF[3]:     00444e04(R), 00444e4e(R), 00444ee4(R)  
    //              long              Stack[0xc]:4   param_3                   XREF[3]:     00444dff(R), 00444e49(R), 00444ed7(R)  
    //              tagRECT *         Stack[0x10]:4  param_4                   XREF[2]:     00444d90(R), 00444e9e(R)  
    //              int               Stack[0x14]:4  param_5                   XREF[1]:     00444dd9(R)  
    //              tagRECT           Stack[-0x14]   dest_rect2                XREF[1,1]:   00444ed1(W), 00444eed(*)  
    //              tagRECT           Stack[-0x24]   src_rect2                 XREF[0,5]:   00444eb1(W), 00444ec7(W), 00444eb5(W), 00444ecb(W), 
    //                                                                                     00444edb(W)  
    //                               ?Copy@TDrawArea@@QAEXPAV1@JJPAUtagRECT@@H@Z                  XREF[8]:     draw:00437379(c), 
    //                               TDrawArea::Copy                                                           copy_image:00437655(c), 
    //                                                                                                         draw_background:00467666(c), 
    //                                                                                                         draw_background:004676c6(c), 
    //                                                                                                         draw_background:004676e0(c), 
    //                                                                                                         draw:00479636(c), 
    //                                                                                                         draw:0051d1ff(c), 
    //                                                                                                         draw:0051dda6(c)  
    //                              Drawarea.cpp:3021 (8)
    //         00444d50     SUB        ESP,0x20
    //         00444d53     PUSH       EBX
    //         00444d54     PUSH       EBP
    //         00444d55     PUSH       ESI
    //         00444d56     MOV        ESI,this
    //                              Drawarea.cpp:3027 (26)
    //         00444d58     XOR        EBP,EBP
    //         00444d5a     PUSH       EDI
    //         00444d5b     MOV        EAX,dword ptr [ESI]
    //         00444d5d     CMP        EAX,EBP
    //         00444d5f     JZ         LAB_00444e80
    //         00444d65     CMP        byte ptr [EAX + 0x478],0x1
    //         00444d6c     JNZ        LAB_00444e80
    //                              Drawarea.cpp:3031 (30)
    //         00444d72     CMP        dword ptr [ESI + 0x8],EBP
    //         00444d75     JZ         LAB_004450a7
    //         00444d7b     MOV        EAX,dword ptr [ESP + param_1]
    //         00444d7f     CMP        EAX,EBP
    //         00444d81     JZ         LAB_004450a7
    //         00444d87     CMP        dword ptr [EAX + 0x8],EBP
    //         00444d8a     JZ         LAB_004450a7
    //                              Drawarea.cpp:3034 (8)
    //         00444d90     MOV        EAX,dword ptr [ESP + param_4]
    //         00444d94     CMP        EAX,EBP
    //         00444d96     JNZ        LAB_00444da2
    //                              Drawarea.cpp:3038 (3)
    //         00444d98     MOV        this,dword ptr [ESI + 0x18]
    //                              Drawarea.cpp:3039 (5)
    //         00444d9b     MOV        EAX,dword ptr [ESI + 0x1c]
    //         00444d9e     XOR        EDI,EDI
    //                              Drawarea.cpp:3041 (2)
    //         00444da0     JMP        LAB_00444db3
    //                               LAB_00444da2                                                 XREF[1]:     00444d96(j)  
    //                              Drawarea.cpp:3043 (2)
    //         00444da2     MOV        EDI,dword ptr [EAX]
    //                              Drawarea.cpp:3044 (3)
    //         00444da4     MOV        EBP,dword ptr [EAX + 0x4]
    //                              Drawarea.cpp:3045 (3)
    //         00444da7     MOV        this,dword ptr [EAX + 0x8]
    //                              Drawarea.cpp:3046 (9)
    //         00444daa     MOV        EAX,dword ptr [EAX + 0xc]
    //         00444dad     SUB        this,EDI
    //         00444daf     SUB        EAX,EBP
    //         00444db1     INC        this
    //         00444db2     INC        EAX
    //                               LAB_00444db3                                                 XREF[1]:     00444da0(j)  
    //                              Drawarea.cpp:3049 (10)
    //         00444db3     MOV        EDX,dword ptr [ESI + 0x18]
    //         00444db6     LEA        EBX,[this->DrawSystem + EDI*0x1]
    //         00444db9     CMP        EBX,EDX
    //         00444dbb     JLE        LAB_00444dc1
    //                              Drawarea.cpp:3050 (4)
    //         00444dbd     SUB        EDX,EDI
    //         00444dbf     MOV        this,EDX
    //                               LAB_00444dc1                                                 XREF[1]:     00444dbb(j)  
    //                              Drawarea.cpp:3052 (10)
    //         00444dc1     MOV        EDX,dword ptr [ESI + 0x1c]
    //         00444dc4     LEA        EBX,[EAX + EBP*0x1]
    //         00444dc7     CMP        EBX,EDX
    //         00444dc9     JLE        LAB_00444dcf
    //                              Drawarea.cpp:3053 (4)
    //         00444dcb     SUB        EDX,EBP
    //         00444dcd     MOV        EAX,EDX
    //                               LAB_00444dcf                                                 XREF[1]:     00444dc9(j)  
    //                              Drawarea.cpp:3055 (18)
    //         00444dcf     MOV        EDX,dword ptr [ESI + 0xec]
    //         00444dd5     TEST       EDX,EDX
    //         00444dd7     JZ         LAB_00444e36
    //         00444dd9     MOV        EDX,dword ptr [ESP + param_5]
    //         00444ddd     TEST       EDX,EDX
    //         00444ddf     JZ         LAB_00444e36
    //                              Drawarea.cpp:3061 (65)
    //         00444de1     XOR        EDX,EDX
    //         00444de3     MOV        DL,byte ptr [ESI + 0xfc]
    //         00444de9     PUSH       EDX
    //         00444dea     MOV        EDX,dword ptr [ESI + 0x8]
    //         00444ded     PUSH       0x0
    //         00444def     PUSH       0x0
    //         00444df1     PUSH       0x1
    //         00444df3     PUSH       EAX
    //         00444df4     PUSH       this
    //         00444df5     PUSH       EBP
    //         00444df6     PUSH       EDI
    //         00444df7     PUSH       0x0
    //         00444df9     PUSH       EDX
    //         00444dfa     MOV        EDX,dword ptr [ESI + 0xc]
    //         00444dfd     PUSH       EDX
    //         00444dfe     PUSH       EAX
    //         00444dff     MOV        EAX,dword ptr [ESP + param_3]
    //         00444e03     PUSH       this
    //         00444e04     MOV        this,dword ptr [ESP + param_2]
    //         00444e08     PUSH       EAX
    //         00444e09     MOV        EAX,dword ptr [ESP + param_1]
    //         00444e0d     PUSH       this
    //         00444e0e     MOV        this,dword ptr [EAX + 0x8]
    //         00444e11     LEA        EDX,[EAX + 0x28]
    //         00444e14     MOV        EAX,dword ptr [EAX + 0xc]
    //         00444e17     PUSH       EDX
    //         00444e18     PUSH       this
    //         00444e19     PUSH       EAX
    //         00444e1a     CALL       TransDibBlt                                      void TransDibBlt(BITMAPINFO256 * param_1, uch
    //         00444e1f     ADD        ESP,0x48
    //                              Drawarea.cpp:3219 (10)
    //         00444e22     MOV        dword ptr [null_0062e650],0x0                    = align(4)
    //                              Drawarea.cpp:3220 (10)
    //         00444e2c     POP        EDI
    //         00444e2d     POP        ESI
    //         00444e2e     POP        EBP
    //         00444e2f     POP        EBX
    //         00444e30     ADD        ESP,0x20
    //         00444e33     RET        0x14
    //                               LAB_00444e36                                                 XREF[2]:     00444dd7(j), 00444ddf(j)  
    //                              Drawarea.cpp:3069 (54)
    //         00444e36     MOV        EDX,dword ptr [ESI + 0x8]
    //         00444e39     PUSH       0x0
    //         00444e3b     PUSH       0x0
    //         00444e3d     PUSH       0x1
    //         00444e3f     PUSH       EAX
    //         00444e40     PUSH       this
    //         00444e41     PUSH       EBP
    //         00444e42     PUSH       EDI
    //         00444e43     PUSH       EDX
    //         00444e44     MOV        EDX,dword ptr [ESI + 0xc]
    //         00444e47     PUSH       EDX
    //         00444e48     PUSH       EAX
    //         00444e49     MOV        EAX,dword ptr [ESP + param_3]
    //         00444e4d     PUSH       this
    //         00444e4e     MOV        this,dword ptr [ESP + param_2]
    //         00444e52     PUSH       EAX
    //         00444e53     MOV        EAX,dword ptr [ESP + param_1]
    //         00444e57     PUSH       this
    //         00444e58     MOV        this,dword ptr [EAX + 0x8]
    //         00444e5b     LEA        EDX,[EAX + 0x28]
    //         00444e5e     MOV        EAX,dword ptr [EAX + 0xc]
    //         00444e61     PUSH       EDX
    //         00444e62     PUSH       this
    //         00444e63     PUSH       EAX
    //         00444e64     CALL       DibBlt                                           void DibBlt(BITMAPINFO256 * param_1, uchar * 
    //         00444e69     ADD        ESP,0x40
    //                              Drawarea.cpp:3219 (10)
    //         00444e6c     MOV        dword ptr [null_0062e650],0x0                    = align(4)
    //                              Drawarea.cpp:3220 (10)
    //         00444e76     POP        EDI
    //         00444e77     POP        ESI
    //         00444e78     POP        EBP
    //         00444e79     POP        EBX
    //         00444e7a     ADD        ESP,0x20
    //         00444e7d     RET        0x14
    //                               LAB_00444e80                                                 XREF[2]:     00444d5f(j), 00444d6c(j)  
    //                              Drawarea.cpp:3077 (30)
    //         00444e80     CMP        dword ptr [ESI + 0x3c],EBP
    //         00444e83     JZ         LAB_004450a7
    //         00444e89     MOV        EAX,dword ptr [ESP + param_1]
    //         00444e8d     CMP        EAX,EBP
    //         00444e8f     JZ         LAB_004450a7
    //         00444e95     CMP        dword ptr [EAX + 0x3c],EBP
    //         00444e98     JZ         LAB_004450a7
    //                              Drawarea.cpp:3081 (8)
    //         00444e9e     MOV        this,dword ptr [ESP + param_4]
    //         00444ea2     CMP        this,EBP
    //         00444ea4     JNZ        LAB_00444ebc
    //                              Drawarea.cpp:3085 (3)
    //         00444ea6     MOV        EAX,dword ptr [ESI + 0x18]
    //                              Drawarea.cpp:3086 (17)
    //         00444ea9     MOV        this,dword ptr [ESI + 0x1c]
    //         00444eac     XOR        EDX,EDX
    //         00444eae     XOR        EDI,EDI
    //         00444eb0     DEC        EAX
    //         00444eb1     MOV        dword ptr [ESP + src_rect2.top],EDX
    //         00444eb5     MOV        dword ptr [ESP + src_rect2.right],EDI
    //         00444eb9     DEC        this
    //                              Drawarea.cpp:3088 (2)
    //         00444eba     JMP        LAB_00444ecf
    //                               LAB_00444ebc                                                 XREF[1]:     00444ea4(j)  
    //                              Drawarea.cpp:3089 (19)
    //         00444ebc     MOV        EDX,dword ptr [this->DrawSystem]
    //         00444ebe     MOV        EDI,dword ptr [ECX + this->Wnd]
    //         00444ec1     MOV        EAX,dword ptr [ECX + this->Bits]
    //         00444ec4     MOV        this,dword ptr [ECX + this->BitmapInfo]
    //         00444ec7     MOV        dword ptr [ESP + src_rect2.top],EDX
    //         00444ecb     MOV        dword ptr [ESP + src_rect2.right],EDI
    //                               LAB_00444ecf                                                 XREF[1]:     00444eba(j)  
    //                              Drawarea.cpp:3091 (1)
    //         00444ecf     INC        EAX
    //                              Drawarea.cpp:3092 (5)
    //         00444ed0     INC        this
    //         00444ed1     MOV        dword ptr [ESP + dest_rect2.left],this
    //                              Drawarea.cpp:3095 (35)
    //         00444ed5     SUB        this,EDI
    //         00444ed7     MOV        EDI,dword ptr [ESP + param_3]
    //         00444edb     MOV        dword ptr [ESP + src_rect2.bottom],EAX
    //         00444edf     ADD        this,EDI
    //         00444ee1     SUB        EAX,EDX
    //         00444ee3     PUSH       this
    //         00444ee4     MOV        this,dword ptr [ESP + param_2]
    //         00444ee8     ADD        EAX,this
    //         00444eea     PUSH       EAX
    //         00444eeb     PUSH       EDI
    //         00444eec     PUSH       this
    //         00444eed     LEA        this=>dest_rect2.top,[ESP + 0x30]
    //         00444ef1     PUSH       this
    //         00444ef2     CALL       dword ptr [->USER32.DLL::SetRect]                = 0048b002
    //                              Drawarea.cpp:3098 (8)
    //         00444ef8     MOV        EAX,dword ptr [ESP + 0x10]
    //         00444efc     CMP        EAX,EBP
    //         00444efe     JGE        LAB_00444f10
    //                              Drawarea.cpp:3102 (16)
    //         00444f00     MOV        this,dword ptr [ESP + 0x20]
    //         00444f04     MOV        dword ptr [ESP + 0x10],EBP
    //         00444f08     NEG        EAX
    //         00444f0a     ADD        this,EAX
    //         00444f0c     MOV        dword ptr [ESP + 0x20],this
    //                               LAB_00444f10                                                 XREF[1]:     00444efe(j)  
    //                              Drawarea.cpp:3105 (8)
    //         00444f10     MOV        EAX,dword ptr [ESP + 0x14]
    //         00444f14     CMP        EAX,EBP
    //         00444f16     JGE        LAB_00444f28
    //                              Drawarea.cpp:3109 (16)
    //         00444f18     MOV        this,dword ptr [ESP + 0x24]
    //         00444f1c     MOV        dword ptr [ESP + 0x14],EBP
    //         00444f20     NEG        EAX
    //         00444f22     ADD        this,EAX
    //         00444f24     MOV        dword ptr [ESP + 0x24],this
    //                               LAB_00444f28                                                 XREF[1]:     00444f16(j)  
    //                              Drawarea.cpp:3112 (11)
    //         00444f28     MOV        this,dword ptr [ESI + 0x18]
    //         00444f2b     MOV        EBX,dword ptr [ESP + 0x18]
    //         00444f2f     CMP        EBX,this
    //         00444f31     JLE        LAB_00444f49
    //                              Drawarea.cpp:3116 (26)
    //         00444f33     MOV        EDI,dword ptr [ESP + 0x28]
    //         00444f37     MOV        EAX,EBX
    //         00444f39     SUB        EAX,this
    //         00444f3b     SUB        EBX,EAX
    //         00444f3d     SUB        EDI,EAX
    //         00444f3f     MOV        dword ptr [ESP + 0x18],EBX
    //         00444f43     MOV        dword ptr [ESP + 0x28],EDI
    //         00444f47     JMP        LAB_00444f4d
    //                               LAB_00444f49                                                 XREF[1]:     00444f31(j)  
    //         00444f49     MOV        EDI,dword ptr [ESP + 0x28]
    //                               LAB_00444f4d                                                 XREF[1]:     00444f47(j)  
    //                              Drawarea.cpp:3119 (11)
    //         00444f4d     MOV        this,dword ptr [ESI + 0x1c]
    //         00444f50     MOV        EBP,dword ptr [ESP + 0x1c]
    //         00444f54     CMP        EBP,this
    //         00444f56     JLE        LAB_00444f6e
    //                              Drawarea.cpp:3123 (26)
    //         00444f58     MOV        EDX,dword ptr [ESP + 0x2c]
    //         00444f5c     MOV        EAX,EBP
    //         00444f5e     SUB        EAX,this
    //         00444f60     SUB        EBP,EAX
    //         00444f62     SUB        EDX,EAX
    //         00444f64     MOV        dword ptr [ESP + 0x1c],EBP
    //         00444f68     MOV        dword ptr [ESP + 0x2c],EDX
    //         00444f6c     JMP        LAB_00444f72
    //                               LAB_00444f6e                                                 XREF[1]:     00444f56(j)  
    //         00444f6e     MOV        EDX,dword ptr [ESP + 0x2c]
    //                               LAB_00444f72                                                 XREF[1]:     00444f6c(j)  
    //                              Drawarea.cpp:3157 (15)
    //         00444f72     MOV        EAX,dword ptr [ESP + 0x34]
    //         00444f76     MOV        this,dword ptr [ESP + 0x20]
    //         00444f7a     MOV        EAX,dword ptr [EAX + 0x28]
    //         00444f7d     CMP        this,EAX
    //         00444f7f     JGE        LAB_00444f93
    //                              Drawarea.cpp:3159 (2)
    //         00444f81     SUB        EAX,this
    //                              Drawarea.cpp:3160 (6)
    //         00444f83     ADD        this,EAX
    //         00444f85     MOV        dword ptr [ESP + 0x20],this
    //                              Drawarea.cpp:3161 (10)
    //         00444f89     MOV        this,dword ptr [ESP + 0x10]
    //         00444f8d     ADD        this,EAX
    //         00444f8f     MOV        dword ptr [ESP + 0x10],this
    //                               LAB_00444f93                                                 XREF[1]:     00444f7f(j)  
    //                              Drawarea.cpp:3164 (15)
    //         00444f93     MOV        this,dword ptr [ESP + 0x34]
    //         00444f97     MOV        EAX,dword ptr [ECX + this+0x2c]
    //         00444f9a     MOV        this,dword ptr [ESP + 0x24]
    //         00444f9e     CMP        this,EAX
    //         00444fa0     JGE        LAB_00444fb4
    //                              Drawarea.cpp:3166 (2)
    //         00444fa2     SUB        EAX,this
    //                              Drawarea.cpp:3167 (6)
    //         00444fa4     ADD        this,EAX
    //         00444fa6     MOV        dword ptr [ESP + 0x24],this
    //                              Drawarea.cpp:3168 (10)
    //         00444faa     MOV        this,dword ptr [ESP + 0x14]
    //         00444fae     ADD        this,EAX
    //         00444fb0     MOV        dword ptr [ESP + 0x14],this
    //                               LAB_00444fb4                                                 XREF[1]:     00444fa0(j)  
    //                              Drawarea.cpp:3171 (14)
    //         00444fb4     MOV        EAX,dword ptr [ESP + 0x34]
    //         00444fb8     MOV        this,dword ptr [EAX + 0x30]
    //         00444fbb     LEA        EAX,[ECX + this+0x1]
    //         00444fbe     CMP        EDI,EAX
    //         00444fc0     JLE        LAB_00444fd3
    //                              Drawarea.cpp:3173 (5)
    //         00444fc2     MOV        EAX,EDI
    //         00444fc4     SUB        EAX,this
    //         00444fc6     DEC        EAX
    //                              Drawarea.cpp:3174 (2)
    //         00444fc7     SUB        EDI,EAX
    //                              Drawarea.cpp:3175 (10)
    //         00444fc9     SUB        EBX,EAX
    //         00444fcb     MOV        dword ptr [ESP + 0x28],EDI
    //         00444fcf     MOV        dword ptr [ESP + 0x18],EBX
    //                               LAB_00444fd3                                                 XREF[1]:     00444fc0(j)  
    //                              Drawarea.cpp:3178 (14)
    //         00444fd3     MOV        this,dword ptr [ESP + 0x34]
    //         00444fd7     MOV        this,dword ptr [ECX + this+0x34]
    //         00444fda     LEA        EAX,[ECX + this+0x1]
    //         00444fdd     CMP        EDX,EAX
    //         00444fdf     JLE        LAB_00444ff2
    //                              Drawarea.cpp:3180 (5)
    //         00444fe1     MOV        EAX,EDX
    //         00444fe3     SUB        EAX,this
    //         00444fe5     DEC        EAX
    //                              Drawarea.cpp:3181 (2)
    //         00444fe6     SUB        EDX,EAX
    //                              Drawarea.cpp:3182 (10)
    //         00444fe8     SUB        EBP,EAX
    //         00444fea     MOV        dword ptr [ESP + 0x2c],EDX
    //         00444fee     MOV        dword ptr [ESP + 0x1c],EBP
    //                               LAB_00444ff2                                                 XREF[1]:     00444fdf(j)  
    //                              Drawarea.cpp:3186 (20)
    //         00444ff2     CMP        dword ptr [ESP + 0x20],EDI
    //         00444ff6     JGE        LAB_004450a7
    //         00444ffc     CMP        dword ptr [ESP + 0x24],EDX
    //         00445000     JGE        LAB_004450a7
    //                              Drawarea.cpp:3189 (20)
    //         00445006     CMP        dword ptr [ESP + 0x10],EBX
    //         0044500a     JGE        LAB_004450a7
    //         00445010     CMP        dword ptr [ESP + 0x14],EBP
    //         00445014     JGE        LAB_004450a7
    //                              Drawarea.cpp:3193 (10)
    //         0044501a     MOV        dword ptr [DAT_0062e64c],0x1                     = align(8)
    //                              Drawarea.cpp:3195 (18)
    //         00445024     MOV        EAX,dword ptr [ESI + 0xec]
    //         0044502a     TEST       EAX,EAX
    //         0044502c     JZ         LAB_0044505a
    //         0044502e     MOV        EAX,dword ptr [ESP + 0x44]
    //         00445032     TEST       EAX,EAX
    //         00445034     JZ         LAB_0044505a
    //                              Drawarea.cpp:3198 (34)
    //         00445036     MOV        this,dword ptr [ESP + 0x34]
    //         0044503a     PUSH       0x0
    //         0044503c     PUSH       0x1008000
    //         00445041     MOV        EAX,dword ptr [ECX + this->DrawSurface]
    //         00445044     LEA        this,[ESP + 0x18]
    //         00445048     PUSH       this
    //         00445049     MOV        this,dword ptr [ESI + 0x3c]
    //         0044504c     MOV        EDX,dword ptr [EAX]
    //         0044504e     PUSH       this
    //         0044504f     LEA        this,[ESP + 0x30]
    //         00445053     PUSH       this
    //         00445054     PUSH       EAX
    //         00445055     CALL       dword ptr [EDX + 0x14]
    //                              Drawarea.cpp:3201 (2)
    //         00445058     JMP        LAB_0044507c
    //                               LAB_0044505a                                                 XREF[2]:     0044502c(j), 00445034(j)  
    //                              Drawarea.cpp:3204 (34)
    //         0044505a     MOV        EDX,dword ptr [ESP + 0x34]
    //         0044505e     PUSH       0x0
    //         00445060     PUSH       0x1000000
    //         00445065     MOV        EAX,dword ptr [EDX + 0x3c]
    //         00445068     LEA        EDX,[ESP + 0x18]
    //         0044506c     PUSH       EDX
    //         0044506d     MOV        EDX,dword ptr [ESI + 0x3c]
    //         00445070     MOV        this,dword ptr [EAX]
    //         00445072     PUSH       EDX
    //         00445073     LEA        EDX,[ESP + 0x30]
    //         00445077     PUSH       EDX
    //         00445078     PUSH       EAX
    //         00445079     CALL       dword ptr [ECX + this->OldBitmap]
    //                               LAB_0044507c                                                 XREF[1]:     00445058(j)  
    //                              Drawarea.cpp:3208 (7)
    //         0044507c     XOR        this,this
    //         0044507e     MOV        [DAT_0062e64c],EAX                               = align(8)
    //                              Drawarea.cpp:3209 (10)
    //         00445083     TEST       EAX,EAX
    //         00445085     MOV        dword ptr [null_0062e650],this                   = align(4)
    //         0044508b     JZ         LAB_0044509d
    //                              Drawarea.cpp:3211 (16)
    //         0044508d     MOV        this,dword ptr [ESI]
    //         0044508f     PUSH       EAX
    //         00445090     CALL       TDrawSystem::GetBlitErrorNum                     int GetBlitErrorNum(TDrawSystem * this, long 
    //         00445095     MOV        this,EAX
    //         00445097     MOV        dword ptr [null_0062e650],this                   = align(4)
    //                               LAB_0044509d                                                 XREF[1]:     0044508b(j)  
    //                              Drawarea.cpp:3214 (4)
    //         0044509d     TEST       this,this
    //         0044509f     JNZ        LAB_004450a7
    //                              Drawarea.cpp:3219 (6)
    //         004450a1     MOV        dword ptr [null_0062e650],this                   = align(4)
    //                               LAB_004450a7                                                 XREF[11]:    00444d75(j), 00444d81(j), 
    //                                                                                                         00444d8a(j), 00444e83(j), 
    //                                                                                                         00444e8f(j), 00444e98(j), 
    //                                                                                                         00444ff6(j), 00445000(j), 
    //                                                                                                         0044500a(j), 00445014(j), 
    //                                                                                                         0044509f(j)  
    //                              Drawarea.cpp:3220 (10)
    //         004450a7     POP        EDI
    //         004450a8     POP        ESI
    //         004450a9     POP        EBP
    //         004450aa     POP        EBX
    //         004450ab     ADD        ESP,0x20
    //         004450ae     RET        0x14
}

// Offset: 0x004450C0
void PtrCopy(TDrawArea* this_, TDrawArea* param_2, long param_3, long param_4, tagRECT* param_5) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TDrawArea::PtrCopy(class TDrawArea *,long,long,struct tagRECT *)              *
    //                              *********************************************************************************************************
    //                              void __thiscall PtrCopy(TDrawArea * this, TDrawArea * param_1, long 
    //              void              <VOID>         <RETURN>
    //              TDrawArea *       ECX:4 (auto)   this
    //              TDrawArea *       Stack[0x4]:4   param_1                   XREF[4]:     00445127(R), 0044518c(R), 004451b1(R), 00445235(R)  
    //              long              Stack[0x8]:4   param_2                   XREF[3]:     0044510e(R), 004451c6(W), 004451e8(R)  
    //              long              Stack[0xc]:4   param_3                   XREF[5]:     00445135(R), 004451a3(R), 004451ae(W), 004451d6(R), 
    //                                                                                     0044520e(RW)  
    //              tagRECT *         Stack[0x10]:4  param_4                   XREF[5]:     004450c6(R), 004451a6(R), 004451bd(W), 004451d3(R), 
    //                                                                                     0044520b(RW)  
    //              int               Stack[-0x8]:4  nLines                    XREF[4]:     00445117(W), 00445156(R), 00445161(W), 00445211(RW)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[3]:     004450d2(W), 00445164(R), 00445219(R)  
    //              int               Stack[-0x10]:4 nWidth                    XREF[3]:     0044511e(W), 00445153(W), 004451eb(R)  
    //              int               Stack[-0x14]:4 XofS                      XREF[2]:     004451b4(W), 004451e5(R)  
    //              void * *          Stack[-0x18]:4 DestP                     XREF[2]:     004451cc(W), 004451dc(R)  
    //              void * *          Stack[-0x1c]:4 SrcP                      XREF[2]:     004451c9(W), 004451d9(R)  
    //                               ?PtrCopy@TDrawArea@@QAEXPAV1@JJPAUtagRECT@@@Z
    //                               TDrawArea::PtrCopy
    //                              Drawarea.cpp:3226 (6)
    //         004450c0     PUSH       EBP
    //         004450c1     MOV        EBP,ESP
    //         004450c3     SUB        ESP,0x18
    //                              Drawarea.cpp:3234 (41)
    //         004450c6     MOV        EDX,dword ptr [EBP + param_4]
    //         004450c9     PUSH       EBX
    //         004450ca     PUSH       ESI
    //         004450cb     PUSH       EDI
    //         004450cc     MOV        EDI,dword ptr [EDX]
    //         004450ce     MOV        EBX,this
    //         004450d0     TEST       EDI,EDI
    //         004450d2     MOV        dword ptr [EBP + local_c],EBX
    //         004450d5     JL         LAB_00445242
    //         004450db     MOV        this,dword ptr [EDX + 0x8]
    //         004450de     CMP        EDI,this
    //         004450e0     JG         LAB_00445242
    //         004450e6     CMP        this,dword ptr [EBX + 0x18]
    //         004450e9     JGE        LAB_00445242
    //                              Drawarea.cpp:3235 (31)
    //         004450ef     MOV        ESI,dword ptr [EDX + 0x4]
    //         004450f2     TEST       ESI,ESI
    //         004450f4     JL         LAB_00445242
    //         004450fa     MOV        EAX,dword ptr [EDX + 0xc]
    //         004450fd     CMP        ESI,EAX
    //         004450ff     JG         LAB_00445242
    //         00445105     CMP        EAX,dword ptr [EBX + 0x1c]
    //         00445108     JGE        LAB_00445242
    //                              Drawarea.cpp:3242 (61)
    //         0044510e     MOV        EBX,dword ptr [EBP + param_2]
    //         00445111     SUB        EAX,ESI
    //         00445113     SUB        this,EDI
    //         00445115     INC        EAX
    //         00445116     INC        this
    //         00445117     MOV        dword ptr [EBP + nLines],EAX
    //         0044511a     MOV        EAX,this
    //         0044511c     TEST       EBX,EBX
    //         0044511e     MOV        dword ptr [EBP + nWidth],EAX
    //         00445121     JL         LAB_00445242
    //         00445127     MOV        ESI,dword ptr [EBP + param_1]
    //         0044512a     MOV        EDI,dword ptr [ESI + 0x18]
    //         0044512d     CMP        EBX,EDI
    //         0044512f     JGE        LAB_00445242
    //         00445135     MOV        this,dword ptr [EBP + param_3]
    //         00445138     TEST       this,this
    //         0044513a     JL         LAB_00445242
    //         00445140     MOV        ESI,dword ptr [ESI + 0x1c]
    //         00445143     CMP        this,ESI
    //         00445145     JGE        LAB_00445242
    //                              Drawarea.cpp:3244 (11)
    //         0044514b     ADD        EAX,EBX
    //         0044514d     CMP        EAX,EDI
    //         0044514f     JLE        LAB_00445156
    //         00445151     SUB        EDI,EBX
    //         00445153     MOV        dword ptr [EBP + nWidth],EDI
    //                               LAB_00445156                                                 XREF[1]:     0044514f(j)  
    //                              Drawarea.cpp:3245 (14)
    //         00445156     MOV        EAX,dword ptr [EBP + nLines]
    //         00445159     ADD        EAX,this
    //         0044515b     CMP        EAX,ESI
    //         0044515d     JLE        LAB_00445164
    //         0044515f     SUB        ESI,this
    //         00445161     MOV        dword ptr [EBP + nLines],ESI
    //                               LAB_00445164                                                 XREF[1]:     0044515d(j)  
    //                              Drawarea.cpp:3248 (18)
    //         00445164     MOV        ESI,dword ptr [EBP + local_c]
    //         00445167     MOV        EAX,dword ptr [ESI]
    //         00445169     TEST       EAX,EAX
    //         0044516b     JZ         LAB_004451a9
    //         0044516d     CMP        byte ptr [EAX + 0x478],0x2
    //         00445174     JNZ        LAB_004451a9
    //                              Drawarea.cpp:3250 (22)
    //         00445176     PUSH       0x1
    //         00445178     PUSH       s_PtrCopy1                                       = "PtrCopy1"
    //         0044517d     MOV        this,ESI
    //         0044517f     CALL       TDrawArea::Lock                                  uchar * Lock(TDrawArea * this, char * param_1
    //         00445184     TEST       EAX,EAX
    //         00445186     JZ         LAB_00445242
    //                              Drawarea.cpp:3251 (29)
    //         0044518c     MOV        this,dword ptr [EBP + param_1]
    //         0044518f     PUSH       0x1
    //         00445191     PUSH       s_PtrCopy2                                       = "PtrCopy2"
    //         00445196     CALL       TDrawArea::Lock                                  uchar * Lock(TDrawArea * this, char * param_1
    //         0044519b     TEST       EAX,EAX
    //         0044519d     JZ         LAB_00445242
    //         004451a3     MOV        this,dword ptr [EBP + param_3]
    //         004451a6     MOV        EDX,dword ptr [EBP + param_4]
    //                               LAB_004451a9                                                 XREF[2]:     0044516b(j), 00445174(j)  
    //                              Drawarea.cpp:3254 (2)
    //         004451a9     MOV        EAX,dword ptr [EDX]
    //                              Drawarea.cpp:3256 (3)
    //         004451ab     MOV        EDX,dword ptr [EDX + 0x4]
    //                              Drawarea.cpp:3257 (3)
    //         004451ae     MOV        dword ptr [EBP + param_3],this
    //                              Drawarea.cpp:3260 (30)
    //         004451b1     MOV        this,dword ptr [EBP + param_1]
    //         004451b4     MOV        dword ptr [EBP + XofS],EAX
    //         004451b7     MOV        EAX,dword ptr [ESI + 0xc0]
    //         004451bd     MOV        dword ptr [EBP + param_4],EDX
    //         004451c0     MOV        EDX,dword ptr [ECX + this->CurDisplayOffsets]
    //         004451c6     MOV        dword ptr [EBP + param_2],EBX
    //         004451c9     MOV        dword ptr [EBP + SrcP],EAX
    //         004451cc     MOV        dword ptr [EBP + DestP],EDX
    //                              Drawarea.cpp:3264 (1)
    //         004451cf     PUSH       ESI
    //                              Drawarea.cpp:3265 (1)
    //         004451d0     PUSH       EDI
    //                              Drawarea.cpp:3266 (1)
    //         004451d1     PUSH       EBX
    //                              Drawarea.cpp:3267 (1)
    //         004451d2     CLD
    //                              Symbol Ref: No symbol: PtrCpyLoop
    //                               LAB_004451d3                                                 XREF[1]:     00445214(j)  
    //                              Drawarea.cpp:3270 (3)
    //         004451d3     MOV        EAX,dword ptr [EBP + param_4]
    //                              Drawarea.cpp:3271 (3)
    //         004451d6     MOV        EBX,dword ptr [EBP + param_3]
    //                              Drawarea.cpp:3273 (3)
    //         004451d9     MOV        ESI,dword ptr [EBP + SrcP]
    //                              Drawarea.cpp:3274 (3)
    //         004451dc     MOV        EDI,dword ptr [EBP + DestP]
    //                              Drawarea.cpp:3276 (3)
    //         004451df     MOV        ESI,dword ptr [ESI + EAX*0x4]
    //                              Drawarea.cpp:3277 (3)
    //         004451e2     MOV        EDI,dword ptr [EDI + EBX*0x4]
    //                              Drawarea.cpp:3279 (3)
    //         004451e5     ADD        ESI,dword ptr [EBP + XofS]
    //                              Drawarea.cpp:3280 (3)
    //         004451e8     ADD        EDI,dword ptr [EBP + param_2]
    //                              Drawarea.cpp:3282 (3)
    //         004451eb     MOV        this,dword ptr [EBP + nWidth]
    //                              Drawarea.cpp:3286 (2)
    //         004451ee     MOV        EAX,this
    //                              Drawarea.cpp:3287 (2)
    //         004451f0     SUB        this,EDI
    //                              Drawarea.cpp:3288 (2)
    //         004451f2     SUB        this,EAX
    //                              Drawarea.cpp:3289 (3)
    //         004451f4     AND        this,0x3
    //                              Drawarea.cpp:3290 (2)
    //         004451f7     SUB        EAX,this
    //                              Drawarea.cpp:3291 (2)
    //         004451f9     JLE        LAB_00445207
    //                              Drawarea.cpp:3292 (2)
    //         004451fb     MOVSB.REP  ES:EDI,ESI
    //                              Drawarea.cpp:3293 (2)
    //         004451fd     MOV        this,EAX
    //                              Drawarea.cpp:3294 (3)
    //         004451ff     AND        EAX,0x3
    //                              Drawarea.cpp:3295 (3)
    //         00445202     SHR        this,0x2
    //                              Drawarea.cpp:3296 (2)
    //         00445205     MOVSD.REP  ES:EDI,ESI
    //                              Symbol Ref: No symbol: PtrCpyLEndBytes
    //                               LAB_00445207                                                 XREF[1]:     004451f9(j)  
    //                              Drawarea.cpp:3298 (2)
    //         00445207     ADD        this,EAX
    //                              Drawarea.cpp:3299 (2)
    //         00445209     MOVSB.REP  ES:EDI,ESI
    //                              Drawarea.cpp:3303 (3)
    //         0044520b     INC        dword ptr [EBP + param_4]
    //                              Drawarea.cpp:3304 (3)
    //         0044520e     INC        dword ptr [EBP + param_3]
    //                              Drawarea.cpp:3306 (3)
    //         00445211     DEC        dword ptr [EBP + nLines]
    //                              Drawarea.cpp:3307 (2)
    //         00445214     JNZ        LAB_004451d3
    //                              Drawarea.cpp:3309 (1)
    //         00445216     POP        EBX
    //                              Drawarea.cpp:3310 (1)
    //         00445217     POP        EDI
    //                              Drawarea.cpp:3311 (1)
    //         00445218     POP        ESI
    //                              Drawarea.cpp:3315 (18)
    //         00445219     MOV        this,dword ptr [EBP + local_c]
    //         0044521c     MOV        EAX,dword ptr [this->DrawSystem]
    //         0044521e     TEST       EAX,EAX
    //         00445220     JZ         LAB_00445242
    //         00445222     CMP        byte ptr [EAX + 0x478],0x2
    //         00445229     JNZ        LAB_00445242
    //                              Drawarea.cpp:3317 (10)
    //         0044522b     PUSH       s_PtrCopy1                                       = "PtrCopy1"
    //         00445230     CALL       TDrawArea::Unlock                                void Unlock(TDrawArea * this, char * param_1)
    //                              Drawarea.cpp:3318 (13)
    //         00445235     MOV        this,dword ptr [EBP + param_1]
    //         00445238     PUSH       s_PtrCopy2                                       = "PtrCopy2"
    //         0044523d     CALL       TDrawArea::Unlock                                void Unlock(TDrawArea * this, char * param_1)
    //                               LAB_00445242                                                 XREF[14]:    004450d5(j), 004450e0(j), 
    //                                                                                                         004450e9(j), 004450f4(j), 
    //                                                                                                         004450ff(j), 00445108(j), 
    //                                                                                                         00445121(j), 0044512f(j), 
    //                                                                                                         0044513a(j), 00445145(j), 
    //                                                                                                         00445186(j), 0044519d(j), 
    //                                                                                                         00445220(j), 00445229(j)  
    //                              Drawarea.cpp:3322 (9)
    //         00445242     POP        EDI
    //         00445243     POP        ESI
    //         00445244     POP        EBX
    //         00445245     MOV        ESP,EBP
    //         00445247     POP        EBP
    //         00445248     RET        0x10
}

// Offset: 0x00445250
void PtrSpanCopy(TDrawArea* this_, TDrawArea* param_2, long param_3, long param_4, tagRECT* param_5, uchar** param_6) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TDrawArea::PtrSpanCopy(class TDrawArea *,long,long,struct tagRECT *,unsign... *
    //                              *********************************************************************************************************
    //                              void __thiscall PtrSpanCopy(TDrawArea * this, TDrawArea * param_1, l
    //              void              <VOID>         <RETURN>
    //              TDrawArea *       ECX:4 (auto)   this
    //              TDrawArea *       Stack[0x4]:4   param_1                   XREF[4]:     004452af(R), 0044531b(W), 00445331(R), 00445387(RW)  
    //              long              Stack[0x8]:4   param_2                   XREF[5]:     0044529e(R), 00445304(R), 00445324(W), 00445334(R), 
    //                                                                                     0044538a(RW)  
    //              long              Stack[0xc]:4   param_3                   XREF[3]:     004452bb(R), 0044530c(W), 00445346(R)  
    //              tagRECT *         Stack[0x10]:4  param_4                   XREF[4]:     00445259(R), 004452a6(W), 004452d9(W), 0044538d(RW)  
    //              uchar * *         Stack[0x14]:4  param_5                   XREF[1]:     00445349(R)  
    //              void * *          Stack[-0x8]:4  DestP                     XREF[5]:     00445260(W), 004452dc(R), 00445309(R), 0044532a(W), 
    //                                                                                     0044533a(R)  
    //              int               Stack[-0xc]:4  XofS                      XREF[2]:     00445312(W), 00445343(R)  
    //              void * *          Stack[-0x10]:4 SrcP                      XREF[2]:     00445327(W), 00445337(R)  
    //                               ?PtrSpanCopy@TDrawArea@@QAEXPAV1@JJPAUtagRECT@@PAPAE@Z       XREF[1]:     view_function_terrain:00537f37(c)  
    //                               TDrawArea::PtrSpanCopy
    //                              Drawarea.cpp:3330 (9)
    //         00445250     PUSH       EBP
    //         00445251     MOV        EBP,ESP
    //         00445253     SUB        ESP,0xc
    //         00445256     PUSH       EBX
    //         00445257     PUSH       ESI
    //         00445258     PUSH       EDI
    //                              Drawarea.cpp:3338 (38)
    //         00445259     MOV        EDI,dword ptr [EBP + param_4]
    //         0044525c     MOV        EDX,this
    //         0044525e     MOV        EAX,dword ptr [EDI]
    //         00445260     MOV        dword ptr [EBP + DestP],EDX
    //         00445263     TEST       EAX,EAX
    //         00445265     JL         LAB_00445395
    //         0044526b     MOV        this,dword ptr [EDI + 0x8]
    //         0044526e     CMP        EAX,this
    //         00445270     JG         LAB_00445395
    //         00445276     CMP        this,dword ptr [EDX + 0x18]
    //         00445279     JGE        LAB_00445395
    //                              Drawarea.cpp:3339 (31)
    //         0044527f     MOV        this,dword ptr [EDI + 0x4]
    //         00445282     TEST       this,this
    //         00445284     JL         LAB_00445395
    //         0044528a     MOV        EAX,dword ptr [EDI + 0xc]
    //         0044528d     CMP        this,EAX
    //         0044528f     JG         LAB_00445395
    //         00445295     CMP        EAX,dword ptr [EDX + 0x1c]
    //         00445298     JGE        LAB_00445395
    //                              Drawarea.cpp:3346 (51)
    //         0044529e     MOV        EDX,dword ptr [EBP + param_2]
    //         004452a1     SUB        EAX,this
    //         004452a3     INC        EAX
    //         004452a4     TEST       EDX,EDX
    //         004452a6     MOV        dword ptr [EBP + param_4],EAX
    //         004452a9     JL         LAB_00445395
    //         004452af     MOV        EBX,dword ptr [EBP + param_1]
    //         004452b2     CMP        EDX,dword ptr [EBX + 0x18]
    //         004452b5     JGE        LAB_00445395
    //         004452bb     MOV        ESI,dword ptr [EBP + param_3]
    //         004452be     TEST       ESI,ESI
    //         004452c0     JL         LAB_00445395
    //         004452c6     MOV        this,dword ptr [EBX + 0x1c]
    //         004452c9     CMP        ESI,this
    //         004452cb     JGE        LAB_00445395
    //                              Drawarea.cpp:3349 (11)
    //         004452d1     ADD        EAX,ESI
    //         004452d3     CMP        EAX,this
    //         004452d5     JLE        LAB_004452dc
    //         004452d7     SUB        this,ESI
    //         004452d9     MOV        dword ptr [EBP + param_4],this
    //                               LAB_004452dc                                                 XREF[1]:     004452d5(j)  
    //                              Drawarea.cpp:3352 (18)
    //         004452dc     MOV        EAX,dword ptr [EBP + DestP]
    //         004452df     MOV        EAX,dword ptr [EAX]
    //         004452e1     TEST       EAX,EAX
    //         004452e3     JZ         LAB_00445307
    //         004452e5     CMP        byte ptr [EAX + 0x478],0x2
    //         004452ec     JNZ        LAB_00445307
    //                              Drawarea.cpp:3356 (25)
    //         004452ee     PUSH       0x1
    //         004452f0     PUSH       s_PtrSpanCopy                                    = "PtrSpanCopy"
    //         004452f5     MOV        this,EBX
    //         004452f7     CALL       TDrawArea::Lock                                  uchar * Lock(TDrawArea * this, char * param_1
    //         004452fc     TEST       EAX,EAX
    //         004452fe     JZ         LAB_00445395
    //         00445304     MOV        EDX,dword ptr [EBP + param_2]
    //                               LAB_00445307                                                 XREF[2]:     004452e3(j), 004452ec(j)  
    //                              Drawarea.cpp:3359 (2)
    //         00445307     MOV        this,dword ptr [EDI]
    //                              Drawarea.cpp:3364 (21)
    //         00445309     MOV        EAX,dword ptr [EBP + DestP]
    //         0044530c     MOV        dword ptr [EBP + param_3],EDX
    //         0044530f     MOV        EDX,dword ptr [EDI + 0x4]
    //         00445312     MOV        dword ptr [EBP + XofS],this
    //         00445315     MOV        this,dword ptr [EAX + 0xc0]
    //         0044531b     MOV        dword ptr [EBP + param_1],EDX
    //                              Drawarea.cpp:3365 (15)
    //         0044531e     MOV        EDX,dword ptr [EBX + 0xc0]
    //         00445324     MOV        dword ptr [EBP + param_2],ESI
    //         00445327     MOV        dword ptr [EBP + SrcP],this
    //         0044532a     MOV        dword ptr [EBP + DestP],EDX
    //                              Drawarea.cpp:3369 (1)
    //         0044532d     PUSH       ESI
    //                              Drawarea.cpp:3370 (1)
    //         0044532e     PUSH       EDI
    //                              Drawarea.cpp:3371 (1)
    //         0044532f     PUSH       EBX
    //                              Drawarea.cpp:3372 (1)
    //         00445330     CLD
    //                              Symbol Ref: No symbol: PtrSpanCpyLoop
    //                               LAB_00445331                                                 XREF[1]:     00445390(j)  
    //                              Drawarea.cpp:3375 (3)
    //         00445331     MOV        EAX,dword ptr [EBP + param_1]
    //                              Drawarea.cpp:3376 (3)
    //         00445334     MOV        EBX,dword ptr [EBP + param_2]
    //                              Drawarea.cpp:3378 (3)
    //         00445337     MOV        ESI,dword ptr [EBP + SrcP]
    //                              Drawarea.cpp:3379 (3)
    //         0044533a     MOV        EDI,dword ptr [EBP + DestP]
    //                              Drawarea.cpp:3381 (3)
    //         0044533d     MOV        ESI,dword ptr [ESI + EAX*0x4]
    //                              Drawarea.cpp:3382 (3)
    //         00445340     MOV        EDI,dword ptr [EDI + EBX*0x4]
    //                              Drawarea.cpp:3384 (3)
    //         00445343     ADD        ESI,dword ptr [EBP + XofS]
    //                              Drawarea.cpp:3385 (3)
    //         00445346     ADD        EDI,dword ptr [EBP + param_3]
    //                              Drawarea.cpp:3387 (3)
    //         00445349     MOV        EBX,dword ptr [EBP + param_5]
    //                              Drawarea.cpp:3388 (3)
    //         0044534c     MOV        EBX,dword ptr [EBX + EAX*0x4]
    //                              Drawarea.cpp:3390 (2)
    //         0044534f     OR         EBX,EBX
    //                              Drawarea.cpp:3391 (2)
    //         00445351     JZ         LAB_00445387
    //                              Symbol Ref: No symbol: PtrSpanProc
    //                               LAB_00445353                                                 XREF[1]:     00445385(j)  
    //                              Drawarea.cpp:3395 (1)
    //         00445353     PUSH       ESI
    //                              Drawarea.cpp:3396 (1)
    //         00445354     PUSH       EDI
    //                              Drawarea.cpp:3398 (3)
    //         00445355     MOV        EAX,dword ptr [EBX + 0x8]
    //                              Drawarea.cpp:3400 (2)
    //         00445358     ADD        ESI,EAX
    //                              Drawarea.cpp:3401 (2)
    //         0044535a     ADD        EDI,EAX
    //                              Drawarea.cpp:3403 (3)
    //         0044535c     MOV        this,dword ptr [EBX + 0xc]
    //                              Drawarea.cpp:3404 (2)
    //         0044535f     SUB        this,EAX
    //                              Drawarea.cpp:3405 (1)
    //         00445361     INC        this
    //                              Drawarea.cpp:3409 (2)
    //         00445362     MOV        EAX,this
    //                              Drawarea.cpp:3410 (2)
    //         00445364     SUB        this,EDI
    //                              Drawarea.cpp:3411 (2)
    //         00445366     SUB        this,EAX
    //                              Drawarea.cpp:3412 (3)
    //         00445368     AND        this,0x3
    //                              Drawarea.cpp:3413 (2)
    //         0044536b     SUB        EAX,this
    //                              Drawarea.cpp:3414 (2)
    //         0044536d     JLE        LAB_0044537b
    //                              Drawarea.cpp:3415 (2)
    //         0044536f     MOVSB.REP  ES:EDI,ESI
    //                              Drawarea.cpp:3416 (2)
    //         00445371     MOV        this,EAX
    //                              Drawarea.cpp:3417 (3)
    //         00445373     AND        EAX,0x3
    //                              Drawarea.cpp:3418 (3)
    //         00445376     SHR        this,0x2
    //                              Drawarea.cpp:3419 (2)
    //         00445379     MOVSD.REP  ES:EDI,ESI
    //                              Symbol Ref: No symbol: PtrSpanCpyLEndBytes
    //                               LAB_0044537b                                                 XREF[1]:     0044536d(j)  
    //                              Drawarea.cpp:3421 (2)
    //         0044537b     ADD        this,EAX
    //                              Drawarea.cpp:3422 (2)
    //         0044537d     MOVSB.REP  ES:EDI,ESI
    //                              Drawarea.cpp:3426 (1)
    //         0044537f     POP        EDI
    //                              Drawarea.cpp:3427 (1)
    //         00445380     POP        ESI
    //                              Drawarea.cpp:3429 (2)
    //         00445381     MOV        EBX,dword ptr [EBX]
    //                              Drawarea.cpp:3431 (2)
    //         00445383     OR         EBX,EBX
    //                              Drawarea.cpp:3432 (2)
    //         00445385     JNZ        LAB_00445353
    //                              Symbol Ref: No symbol: PtrSpanSkip1
    //                               LAB_00445387                                                 XREF[1]:     00445351(j)  
    //                              Drawarea.cpp:3436 (3)
    //         00445387     INC        dword ptr [EBP + param_1]
    //                              Drawarea.cpp:3437 (3)
    //         0044538a     INC        dword ptr [EBP + param_2]
    //                              Drawarea.cpp:3439 (3)
    //         0044538d     DEC        dword ptr [EBP + param_4]
    //                              Drawarea.cpp:3440 (2)
    //         00445390     JNZ        LAB_00445331
    //                              Drawarea.cpp:3442 (1)
    //         00445392     POP        EBX
    //                              Drawarea.cpp:3443 (1)
    //         00445393     POP        EDI
    //                              Drawarea.cpp:3444 (1)
    //         00445394     POP        ESI
    //                               LAB_00445395                                                 XREF[11]:    00445265(j), 00445270(j), 
    //                                                                                                         00445279(j), 00445284(j), 
    //                                                                                                         0044528f(j), 00445298(j), 
    //                                                                                                         004452a9(j), 004452b5(j), 
    //                                                                                                         004452c0(j), 004452cb(j), 
    //                                                                                                         004452fe(j)  
    //                              Drawarea.cpp:3455 (9)
    //         00445395     POP        EDI
    //         00445396     POP        ESI
    //         00445397     POP        EBX
    //         00445398     MOV        ESP,EBP
    //         0044539a     POP        EBP
    //         0044539b     RET        0x14
}

// Offset: 0x004453A0
void PtrSurfaceCopy(TDrawArea* this_, TDrawArea* param_2, long param_3, long param_4, tagRECT* param_5, int param_6, int param_7) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TDrawArea::PtrSurfaceCopy(class TDrawArea *,long,long,struct tagRECT *,int... *
    //                              *********************************************************************************************************
    //                              void __thiscall PtrSurfaceCopy(TDrawArea * this, TDrawArea * param_1
    //              void              <VOID>         <RETURN>
    //              TDrawArea *       ECX:4 (auto)   this
    //              TDrawArea *       Stack[0x4]:4   param_1                   XREF[4]:     00445407(R), 0044547d(R), 004454cb(R), 00445560(R)  
    //              long              Stack[0x8]:4   param_2                   XREF[3]:     004453ee(R), 004454c0(W), 004454f6(R)  
    //              long              Stack[0xc]:4   param_3                   XREF[6]:     00445415(R), 00445473(R), 004454b1(R), 004454b7(W), 
    //                                                                                     004454e4(R), 0044552c(RW)  
    //              tagRECT *         Stack[0x10]:4  param_4                   XREF[5]:     004453a6(R), 004454b4(R), 004454c8(W), 004454e1(R), 
    //                                                                                     00445529(RW)  
    //              int               Stack[0x14]:4  param_5                   XREF[2]:     00445453(R), 00445546(R)  
    //              int               Stack[0x18]:4  param_6                   XREF[2]:     00445476(R), 00445559(R)  
    //              int               Stack[-0x8]:4  nLines                    XREF[4]:     004453f7(W), 00445436(R), 00445441(W), 0044552f(RW)  
    //              int               Stack[-0xc]:4  XofS                      XREF[6]:     004453b2(W), 00445470(R), 00445498(R), 004454ae(R), 
    //                                                                                     004454d1(W), 004454f3(R)  
    //              int               Stack[-0x10]:4 nWidth                    XREF[4]:     004453fe(W), 00445433(W), 00445502(R), 00445524(R)  
    //              void * *          Stack[-0x14]:4 DestP                     XREF[2]:     004454da(W), 004454ea(R)  
    //              void * *          Stack[-0x18]:4 SrcP                      XREF[2]:     004454ce(W), 004454e7(R)  
    //                               ?PtrSurfaceCopy@TDrawArea@@QAEXPAV1@JJPAUtagRECT@@HH@Z
    //                               TDrawArea::PtrSurfaceCopy
    //                              Drawarea.cpp:3464 (6)
    //         004453a0     PUSH       EBP
    //         004453a1     MOV        EBP,ESP
    //         004453a3     SUB        ESP,0x14
    //                              Drawarea.cpp:3472 (41)
    //         004453a6     MOV        EAX,dword ptr [EBP + param_4]
    //         004453a9     PUSH       EBX
    //         004453aa     PUSH       ESI
    //         004453ab     PUSH       EDI
    //         004453ac     MOV        EDI,dword ptr [EAX]
    //         004453ae     MOV        EDX,this
    //         004453b0     TEST       EDI,EDI
    //         004453b2     MOV        dword ptr [EBP + XofS],EDX
    //         004453b5     JL         LAB_0044556d
    //         004453bb     MOV        this,dword ptr [EAX + 0x8]
    //         004453be     CMP        EDI,this
    //         004453c0     JG         LAB_0044556d
    //         004453c6     CMP        this,dword ptr [EDX + 0x18]
    //         004453c9     JGE        LAB_0044556d
    //                              Drawarea.cpp:3473 (31)
    //         004453cf     MOV        ESI,dword ptr [EAX + 0x4]
    //         004453d2     TEST       ESI,ESI
    //         004453d4     JL         LAB_0044556d
    //         004453da     MOV        EAX,dword ptr [EAX + 0xc]
    //         004453dd     CMP        ESI,EAX
    //         004453df     JG         LAB_0044556d
    //         004453e5     CMP        EAX,dword ptr [EDX + 0x1c]
    //         004453e8     JGE        LAB_0044556d
    //                              Drawarea.cpp:3480 (61)
    //         004453ee     MOV        EBX,dword ptr [EBP + param_2]
    //         004453f1     SUB        EAX,ESI
    //         004453f3     SUB        this,EDI
    //         004453f5     INC        EAX
    //         004453f6     INC        this
    //         004453f7     MOV        dword ptr [EBP + nLines],EAX
    //         004453fa     MOV        EAX,this
    //         004453fc     TEST       EBX,EBX
    //         004453fe     MOV        dword ptr [EBP + nWidth],EAX
    //         00445401     JL         LAB_0044556d
    //         00445407     MOV        ESI,dword ptr [EBP + param_1]
    //         0044540a     MOV        EDI,dword ptr [ESI + 0x18]
    //         0044540d     CMP        EBX,EDI
    //         0044540f     JGE        LAB_0044556d
    //         00445415     MOV        this,dword ptr [EBP + param_3]
    //         00445418     TEST       this,this
    //         0044541a     JL         LAB_0044556d
    //         00445420     MOV        ESI,dword ptr [ESI + 0x1c]
    //         00445423     CMP        this,ESI
    //         00445425     JGE        LAB_0044556d
    //                              Drawarea.cpp:3482 (11)
    //         0044542b     ADD        EAX,EBX
    //         0044542d     CMP        EAX,EDI
    //         0044542f     JLE        LAB_00445436
    //         00445431     SUB        EDI,EBX
    //         00445433     MOV        dword ptr [EBP + nWidth],EDI
    //                               LAB_00445436                                                 XREF[1]:     0044542f(j)  
    //                              Drawarea.cpp:3483 (14)
    //         00445436     MOV        EAX,dword ptr [EBP + nLines]
    //         00445439     ADD        EAX,this
    //         0044543b     CMP        EAX,ESI
    //         0044543d     JLE        LAB_00445444
    //         0044543f     SUB        ESI,this
    //         00445441     MOV        dword ptr [EBP + nLines],ESI
    //                               LAB_00445444                                                 XREF[1]:     0044543d(j)  
    //                              Drawarea.cpp:3486 (15)
    //         00445444     MOV        EAX,dword ptr [EDX]
    //         00445446     TEST       EAX,EAX
    //         00445448     JZ         LAB_004454b4
    //         0044544a     CMP        byte ptr [EAX + 0x478],0x2
    //         00445451     JNZ        LAB_004454b4
    //                              Drawarea.cpp:3488 (7)
    //         00445453     MOV        ESI,dword ptr [EBP + param_5]
    //         00445456     TEST       ESI,ESI
    //         00445458     JZ         LAB_00445476
    //                              Drawarea.cpp:3490 (28)
    //         0044545a     PUSH       0x1
    //         0044545c     PUSH       s_PtrSurfaceCopy1                                = "PtrSurfaceCopy1"
    //         00445461     MOV        this,EDX
    //         00445463     CALL       TDrawArea::Lock                                  uchar * Lock(TDrawArea * this, char * param_1
    //         00445468     TEST       EAX,EAX
    //         0044546a     JZ         LAB_0044556d
    //         00445470     MOV        EDX,dword ptr [EBP + XofS]
    //         00445473     MOV        this,dword ptr [EBP + param_3]
    //                               LAB_00445476                                                 XREF[1]:     00445458(j)  
    //                              Drawarea.cpp:3492 (7)
    //         00445476     MOV        EAX,dword ptr [EBP + param_6]
    //         00445479     TEST       EAX,EAX
    //         0044547b     JZ         LAB_004454b4
    //                              Drawarea.cpp:3494 (19)
    //         0044547d     MOV        this,dword ptr [EBP + param_1]
    //         00445480     PUSH       0x1
    //         00445482     PUSH       s_PtrSurfaceCopy2                                = "PtrSurfaceCopy2"
    //         00445487     CALL       TDrawArea::Lock                                  uchar * Lock(TDrawArea * this, char * param_1
    //         0044548c     TEST       EAX,EAX
    //         0044548e     JNZ        LAB_004454ae
    //                              Drawarea.cpp:3496 (16)
    //         00445490     TEST       ESI,ESI
    //         00445492     JZ         LAB_0044556d
    //         00445498     MOV        this,dword ptr [EBP + XofS]
    //         0044549b     PUSH       s_PtrSurfaceCopy1                                = "PtrSurfaceCopy1"
    //                              Drawarea.cpp:3589 (5)
    //         004454a0     CALL       TDrawArea::Unlock                                void Unlock(TDrawArea * this, char * param_1)
    //                              Drawarea.cpp:3594 (9)
    //         004454a5     POP        EDI
    //         004454a6     POP        ESI
    //         004454a7     POP        EBX
    //         004454a8     MOV        ESP,EBP
    //         004454aa     POP        EBP
    //         004454ab     RET        0x18
    //                               LAB_004454ae                                                 XREF[1]:     0044548e(j)  
    //                              Drawarea.cpp:3497 (6)
    //         004454ae     MOV        EDX,dword ptr [EBP + XofS]
    //         004454b1     MOV        this,dword ptr [EBP + param_3]
    //                               LAB_004454b4                                                 XREF[3]:     00445448(j), 00445451(j), 
    //                                                                                                         0044547b(j)  
    //                              Drawarea.cpp:3502 (3)
    //         004454b4     MOV        EAX,dword ptr [EBP + param_4]
    //                              Drawarea.cpp:3505 (3)
    //         004454b7     MOV        dword ptr [EBP + param_3],this
    //                              Drawarea.cpp:3507 (17)
    //         004454ba     MOV        this,dword ptr [EDX + 0xc0]
    //         004454c0     MOV        dword ptr [EBP + param_2],EBX
    //         004454c3     MOV        ESI,dword ptr [EAX]
    //         004454c5     MOV        EAX,dword ptr [EAX + 0x4]
    //         004454c8     MOV        dword ptr [EBP + param_4],EAX
    //                              Drawarea.cpp:3508 (18)
    //         004454cb     MOV        EAX,dword ptr [EBP + param_1]
    //         004454ce     MOV        dword ptr [EBP + SrcP],this
    //         004454d1     MOV        dword ptr [EBP + XofS],ESI
    //         004454d4     MOV        this,dword ptr [EAX + 0xc0]
    //         004454da     MOV        dword ptr [EBP + DestP],this
    //                              Drawarea.cpp:3513 (1)
    //         004454dd     PUSH       ESI
    //                              Drawarea.cpp:3514 (1)
    //         004454de     PUSH       EDI
    //                              Drawarea.cpp:3515 (1)
    //         004454df     PUSH       EBX
    //                              Drawarea.cpp:3516 (1)
    //         004454e0     CLD
    //                              Symbol Ref: No symbol: PtrSCpyLoop
    //                               LAB_004454e1                                                 XREF[1]:     00445532(j)  
    //                              Drawarea.cpp:3519 (3)
    //         004454e1     MOV        EAX,dword ptr [EBP + param_4]
    //                              Drawarea.cpp:3520 (3)
    //         004454e4     MOV        EBX,dword ptr [EBP + param_3]
    //                              Drawarea.cpp:3522 (3)
    //         004454e7     MOV        ESI,dword ptr [EBP + SrcP]
    //                              Drawarea.cpp:3523 (3)
    //         004454ea     MOV        EDI,dword ptr [EBP + DestP]
    //                              Drawarea.cpp:3525 (3)
    //         004454ed     MOV        ESI,dword ptr [ESI + EAX*0x4]
    //                              Drawarea.cpp:3526 (3)
    //         004454f0     MOV        EDI,dword ptr [EDI + EBX*0x4]
    //                              Drawarea.cpp:3528 (3)
    //         004454f3     ADD        ESI,dword ptr [EBP + XofS]
    //                              Drawarea.cpp:3529 (3)
    //         004454f6     ADD        EDI,dword ptr [EBP + param_2]
    //                              Drawarea.cpp:3533 (2)
    //         004454f9     MOV        this,ESI
    //                              Drawarea.cpp:3534 (2)
    //         004454fb     XOR        this,EDI
    //                              Drawarea.cpp:3535 (3)
    //         004454fd     AND        this,0x3
    //                              Drawarea.cpp:3536 (2)
    //         00445500     JNZ        LAB_00445524
    //                              Drawarea.cpp:3538 (3)
    //         00445502     MOV        this,dword ptr [EBP + nWidth]
    //                              Drawarea.cpp:3542 (2)
    //         00445505     MOV        EAX,this
    //                              Drawarea.cpp:3543 (2)
    //         00445507     SUB        this,EDI
    //                              Drawarea.cpp:3544 (2)
    //         00445509     SUB        this,EAX
    //                              Drawarea.cpp:3545 (3)
    //         0044550b     AND        this,0x3
    //                              Drawarea.cpp:3546 (2)
    //         0044550e     SUB        EAX,this
    //                              Drawarea.cpp:3547 (2)
    //         00445510     JLE        LAB_0044551e
    //                              Drawarea.cpp:3548 (2)
    //         00445512     MOVSB.REP  ES:EDI,ESI
    //                              Drawarea.cpp:3549 (2)
    //         00445514     MOV        this,EAX
    //                              Drawarea.cpp:3550 (3)
    //         00445516     AND        EAX,0x3
    //                              Drawarea.cpp:3551 (3)
    //         00445519     SHR        this,0x2
    //                              Drawarea.cpp:3552 (2)
    //         0044551c     MOVSD.REP  ES:EDI,ESI
    //                              Symbol Ref: No symbol: PtrSCpyLEndBytes
    //                               LAB_0044551e                                                 XREF[1]:     00445510(j)  
    //                              Drawarea.cpp:3554 (2)
    //         0044551e     ADD        this,EAX
    //                              Drawarea.cpp:3555 (2)
    //         00445520     MOVSB.REP  ES:EDI,ESI
    //                              Drawarea.cpp:3557 (2)
    //         00445522     JMP        LAB_00445529
    //                              Symbol Ref: No symbol: PtrSByteCopy
    //                               LAB_00445524                                                 XREF[1]:     00445500(j)  
    //                              Drawarea.cpp:3563 (3)
    //         00445524     MOV        this,dword ptr [EBP + nWidth]
    //                              Drawarea.cpp:3564 (2)
    //         00445527     MOVSB.REP  ES:EDI,ESI
    //                              Symbol Ref: No symbol: PtrSDone
    //                               LAB_00445529                                                 XREF[1]:     00445522(j)  
    //                              Drawarea.cpp:3569 (3)
    //         00445529     INC        dword ptr [EBP + param_4]
    //                              Drawarea.cpp:3570 (3)
    //         0044552c     INC        dword ptr [EBP + param_3]
    //                              Drawarea.cpp:3572 (3)
    //         0044552f     DEC        dword ptr [EBP + nLines]
    //                              Drawarea.cpp:3573 (2)
    //         00445532     JNZ        LAB_004454e1
    //                              Drawarea.cpp:3575 (1)
    //         00445534     POP        EBX
    //                              Drawarea.cpp:3576 (1)
    //         00445535     POP        EDI
    //                              Drawarea.cpp:3577 (1)
    //         00445536     POP        ESI
    //                              Drawarea.cpp:3581 (15)
    //         00445537     MOV        EAX,dword ptr [EDX]
    //         00445539     TEST       EAX,EAX
    //         0044553b     JZ         LAB_0044556d
    //         0044553d     CMP        byte ptr [EAX + 0x478],0x2
    //         00445544     JNZ        LAB_0044556d
    //                              Drawarea.cpp:3583 (7)
    //         00445546     MOV        EAX,dword ptr [EBP + param_5]
    //         00445549     TEST       EAX,EAX
    //         0044554b     JZ         LAB_00445559
    //                              Drawarea.cpp:3585 (12)
    //         0044554d     PUSH       s_PtrSurfaceCopy1                                = "PtrSurfaceCopy1"
    //         00445552     MOV        this,EDX
    //         00445554     CALL       TDrawArea::Unlock                                void Unlock(TDrawArea * this, char * param_1)
    //                               LAB_00445559                                                 XREF[1]:     0044554b(j)  
    //                              Drawarea.cpp:3587 (7)
    //         00445559     MOV        EAX,dword ptr [EBP + param_6]
    //         0044555c     TEST       EAX,EAX
    //         0044555e     JZ         LAB_0044556d
    //                              Drawarea.cpp:3589 (13)
    //         00445560     MOV        this,dword ptr [EBP + param_1]
    //         00445563     PUSH       s_PtrSurfaceCopy2                                = "PtrSurfaceCopy2"
    //         00445568     CALL       TDrawArea::Unlock                                void Unlock(TDrawArea * this, char * param_1)
    //                               LAB_0044556d                                                 XREF[15]:    004453b5(j), 004453c0(j), 
    //                                                                                                         004453c9(j), 004453d4(j), 
    //                                                                                                         004453df(j), 004453e8(j), 
    //                                                                                                         00445401(j), 0044540f(j), 
    //                                                                                                         0044541a(j), 00445425(j), 
    //                                                                                                         0044546a(j), 00445492(j), 
    //                                                                                                         0044553b(j), 00445544(j), 
    //                                                                                                         0044555e(j)  
    //                              Drawarea.cpp:3594 (9)
    //         0044556d     POP        EDI
    //         0044556e     POP        ESI
    //         0044556f     POP        EBX
    //         00445570     MOV        ESP,EBP
    //         00445572     POP        EBP
    //         00445573     RET        0x18
}

// Offset: 0x00445580
void OverlayMemCopy(TDrawArea* this_, tagRECT* param_2, tagRECT* param_3, int param_4, int param_5, int param_6, int param_7) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TDrawArea::OverlayMemCopy(struct tagRECT &,struct tagRECT &,int,int,int,int)  *
    //                              *********************************************************************************************************
    //                              void __thiscall OverlayMemCopy(TDrawArea * this, tagRECT * param_1, 
    //              void              <VOID>         <RETURN>
    //              TDrawArea *       ECX:4 (auto)   this
    //              tagRECT *         Stack[0x4]:4   param_1                   XREF[8]:     004455c1(R), 00445609(W), 00445625(W), 00445655(W), 
    //                                                                                     0044569f(R), 004456a2(R), 004456cd(R), 004456d0(R)  
    //              tagRECT *         Stack[0x8]:4   param_2                   XREF[6]:     004455ed(R), 00445610(W), 0044562c(W), 00445645(W), 
    //                                                                                     00445688(R), 004456b6(R)  
    //              int               Stack[0xc]:4   param_3                   XREF[2]:     00445586(R), 0044564b(R)  
    //              int               Stack[0x10]:4  param_4                   XREF[7]:     00445593(R), 004455fd(R), 0044561b(R), 00445637(R), 
    //                                                                                     0044567c(W), 00445685(R), 004456b3(R)  
    //              int               Stack[0x14]:4  param_5                   XREF[6]:     004455c4(R), 00445618(W), 00445634(W), 00445648(W), 
    //                                                                                     0044568b(R), 004456b9(R)  
    //              int               Stack[0x18]:4  param_6                   XREF[1]:     00445602(R)  
    //              int               Stack[-0x8]:4  Lines                     XREF[3]:     004455de(W), 004456a5(RW), 004456d3(RW)  
    //              int               Stack[-0xc]:4  DstXStart                 XREF[4]:     004455fa(W), 0044566b(W), 00445697(R), 004456c5(R)  
    //              int               Stack[-0x10]:4 SrcXStart                 XREF[4]:     004455ea(W), 00445668(W), 00445694(R), 004456c2(R)  
    //              int               Stack[-0x14]:4 BackCopy                  XREF[3]:     004455c7(W), 0044565d(W), 00445671(R)  
    //              int               Stack[-0x18]:4 LineLen                   XREF[3]:     004455f3(W), 0044569a(R), 004456c8(R)  
    //              undefined4        Stack[-0x1c]:4 local_1c                  XREF[3]:     0044558e(W), 0044566e(R), 004456dc(R)  
    //                               ?OverlayMemCopy@TDrawArea@@QAEXAAUtagRECT@@0HHHH@Z           XREF[1]:     draw:00534de0(c)  
    //                               TDrawArea::OverlayMemCopy
    //                              Drawarea.cpp:3604 (6)
    //         00445580     PUSH       EBP
    //         00445581     MOV        EBP,ESP
    //         00445583     SUB        ESP,0x18
    //                              Drawarea.cpp:3612 (24)
    //         00445586     MOV        EAX,dword ptr [EBP + param_3]
    //         00445589     PUSH       EBX
    //         0044558a     PUSH       ESI
    //         0044558b     PUSH       EDI
    //         0044558c     TEST       EAX,EAX
    //         0044558e     MOV        dword ptr [EBP + local_1c],this
    //         00445591     JNZ        LAB_0044559e
    //         00445593     MOV        EAX,dword ptr [EBP + param_4]
    //         00445596     TEST       EAX,EAX
    //         00445598     JZ         LAB_004456f8
    //                               LAB_0044559e                                                 XREF[1]:     00445591(j)  
    //                              Drawarea.cpp:3615 (15)
    //         0044559e     MOV        EAX,dword ptr [this->DrawSystem]
    //         004455a0     TEST       EAX,EAX
    //         004455a2     JZ         LAB_004455c1
    //         004455a4     CMP        byte ptr [EAX + 0x478],0x2
    //         004455ab     JNZ        LAB_004455c1
    //                              Drawarea.cpp:3619 (20)
    //         004455ad     PUSH       0x1
    //         004455af     PUSH       s_OverlayMemCopy                                 = "OverlayMemCopy"
    //         004455b4     CALL       TDrawArea::Lock                                  uchar * Lock(TDrawArea * this, char * param_1
    //         004455b9     TEST       EAX,EAX
    //         004455bb     JZ         LAB_004456f8
    //                               LAB_004455c1                                                 XREF[2]:     004455a2(j), 004455ab(j)  
    //                              Drawarea.cpp:3623 (3)
    //         004455c1     MOV        EAX,dword ptr [EBP + param_1]
    //                              Drawarea.cpp:3627 (41)
    //         004455c4     MOV        EDI,dword ptr [EBP + param_5]
    //         004455c7     MOV        dword ptr [EBP + BackCopy],0x0
    //         004455ce     MOV        EDX,dword ptr [EAX + 0xc]
    //         004455d1     MOV        this,dword ptr [EAX + 0x4]
    //         004455d4     MOV        EBX,dword ptr [EAX + 0x8]
    //         004455d7     MOV        EAX,dword ptr [EAX]
    //         004455d9     MOV        ESI,EDX
    //         004455db     SUB        ESI,this
    //         004455dd     INC        ESI
    //         004455de     MOV        dword ptr [EBP + Lines],ESI
    //         004455e1     MOV        ESI,EBX
    //         004455e3     SUB        ESI,EAX
    //         004455e5     ADD        EAX,EDI
    //         004455e7     ADD        ESI,0x4
    //         004455ea     MOV        dword ptr [EBP + SrcXStart],EAX
    //                              Drawarea.cpp:3628 (16)
    //         004455ed     MOV        EAX,dword ptr [EBP + param_2]
    //         004455f0     SAR        ESI,0x2
    //         004455f3     MOV        dword ptr [EBP + LineLen],ESI
    //         004455f6     MOV        ESI,EDI
    //         004455f8     ADD        ESI,dword ptr [EAX]
    //         004455fa     MOV        dword ptr [EBP + DstXStart],ESI
    //                              Drawarea.cpp:3630 (10)
    //         004455fd     MOV        ESI,dword ptr [EBP + param_4]
    //         00445600     TEST       ESI,ESI
    //         00445602     MOV        ESI,dword ptr [EBP + param_6]
    //         00445605     JGE        LAB_0044561b
    //                              Drawarea.cpp:3632 (2)
    //         00445607     ADD        EDX,ESI
    //                              Drawarea.cpp:3634 (18)
    //         00445609     MOV        dword ptr [EBP + param_1],0xffffffff
    //         00445610     MOV        dword ptr [EBP + param_2],EDX
    //         00445613     MOV        EDX,dword ptr [EAX + 0xc]
    //         00445616     ADD        EDX,ESI
    //         00445618     MOV        dword ptr [EBP + param_5],EDX
    //                               LAB_0044561b                                                 XREF[1]:     00445605(j)  
    //                              Drawarea.cpp:3636 (7)
    //         0044561b     MOV        EDX,dword ptr [EBP + param_4]
    //         0044561e     TEST       EDX,EDX
    //         00445620     JLE        LAB_0044563c
    //                              Drawarea.cpp:3638 (3)
    //         00445622     LEA        EDX,[ESI + this->DrawSystem*0x1]
    //                              Drawarea.cpp:3640 (18)
    //         00445625     MOV        dword ptr [EBP + param_1],0x1
    //         0044562c     MOV        dword ptr [EBP + param_2],EDX
    //         0044562f     MOV        EDX,dword ptr [EAX + 0x4]
    //         00445632     ADD        EDX,ESI
    //         00445634     MOV        dword ptr [EBP + param_5],EDX
    //                              Drawarea.cpp:3642 (7)
    //         00445637     MOV        EDX,dword ptr [EBP + param_4]
    //         0044563a     TEST       EDX,EDX
    //                               LAB_0044563c                                                 XREF[1]:     00445620(j)  
    //         0044563c     JNZ        LAB_0044566e
    //                              Drawarea.cpp:3646 (13)
    //         0044563e     MOV        EDX,dword ptr [EAX + 0x4]
    //         00445641     ADD        this,ESI
    //         00445643     ADD        EDX,ESI
    //         00445645     MOV        dword ptr [EBP + param_2],this
    //         00445648     MOV        dword ptr [EBP + param_5],EDX
    //                              Drawarea.cpp:3649 (15)
    //         0044564b     MOV        EDX,dword ptr [EBP + param_3]
    //         0044564e     MOV        this,0x1
    //         00445653     TEST       EDX,EDX
    //         00445655     MOV        dword ptr [EBP + param_1],this
    //         00445658     JGE        LAB_0044566e
    //                              Drawarea.cpp:3653 (20)
    //         0044565a     MOV        EDX,dword ptr [EAX + 0x8]
    //         0044565d     MOV        dword ptr [EBP + BackCopy],this
    //         00445660     LEA        this,[EDI + EBX*0x1 + -0x3]
    //         00445664     LEA        EAX,[EDX + EDI*0x1 + -0x3]
    //         00445668     MOV        dword ptr [EBP + SrcXStart],this
    //         0044566b     MOV        dword ptr [EBP + DstXStart],EAX
    //                               LAB_0044566e                                                 XREF[2]:     0044563c(j), 00445658(j)  
    //                              Drawarea.cpp:3657 (3)
    //         0044566e     MOV        this,dword ptr [EBP + local_1c]
    //                              Drawarea.cpp:3661 (16)
    //         00445671     MOV        EAX,dword ptr [EBP + BackCopy]
    //         00445674     TEST       EAX,EAX
    //         00445676     MOV        EDX,dword ptr [ECX + this->CurDisplayOffsets]
    //         0044567c     MOV        dword ptr [EBP + param_4],EDX
    //         0044567f     JNZ        LAB_004456af
    //                              Drawarea.cpp:3665 (1)
    //         00445681     PUSH       ESI
    //                              Drawarea.cpp:3666 (1)
    //         00445682     PUSH       EDI
    //                              Drawarea.cpp:3667 (1)
    //         00445683     PUSH       EBX
    //                              Drawarea.cpp:3668 (1)
    //         00445684     CLD
    //                              Drawarea.cpp:3671 (3)
    //         00445685     MOV        EBX,dword ptr [EBP + param_4]
    //                              Drawarea.cpp:3672 (3)
    //         00445688     MOV        EAX,dword ptr [EBP + param_2]
    //                              Drawarea.cpp:3673 (3)
    //         0044568b     MOV        EDX,dword ptr [EBP + param_5]
    //                              Symbol Ref: No symbol: OverlayCpyLoop1
    //                               LAB_0044568e                                                 XREF[1]:     004456a8(j)  
    //                              Drawarea.cpp:3676 (3)
    //         0044568e     MOV        ESI,dword ptr [EBX + EAX*0x4]
    //                              Drawarea.cpp:3677 (3)
    //         00445691     MOV        EDI,dword ptr [EBX + EDX*0x4]
    //                              Drawarea.cpp:3678 (3)
    //         00445694     ADD        ESI,dword ptr [EBP + SrcXStart]
    //                              Drawarea.cpp:3679 (3)
    //         00445697     ADD        EDI,dword ptr [EBP + DstXStart]
    //                              Drawarea.cpp:3680 (3)
    //         0044569a     MOV        this,dword ptr [EBP + LineLen]
    //                              Drawarea.cpp:3682 (2)
    //         0044569d     MOVSD.REP  ES:EDI,ESI
    //                              Drawarea.cpp:3684 (3)
    //         0044569f     ADD        EAX,dword ptr [EBP + param_1]
    //                              Drawarea.cpp:3685 (3)
    //         004456a2     ADD        EDX,dword ptr [EBP + param_1]
    //                              Drawarea.cpp:3686 (3)
    //         004456a5     DEC        dword ptr [EBP + Lines]
    //                              Drawarea.cpp:3687 (2)
    //         004456a8     JNZ        LAB_0044568e
    //                              Drawarea.cpp:3689 (1)
    //         004456aa     POP        EBX
    //                              Drawarea.cpp:3690 (1)
    //         004456ab     POP        EDI
    //                              Drawarea.cpp:3691 (1)
    //         004456ac     POP        ESI
    //                              Drawarea.cpp:3694 (2)
    //         004456ad     JMP        LAB_004456dc
    //                               LAB_004456af                                                 XREF[1]:     0044567f(j)  
    //                              Drawarea.cpp:3698 (1)
    //         004456af     PUSH       ESI
    //                              Drawarea.cpp:3699 (1)
    //         004456b0     PUSH       EDI
    //                              Drawarea.cpp:3700 (1)
    //         004456b1     PUSH       EBX
    //                              Drawarea.cpp:3701 (1)
    //         004456b2     STD
    //                              Drawarea.cpp:3704 (3)
    //         004456b3     MOV        EBX,dword ptr [EBP + param_4]
    //                              Drawarea.cpp:3705 (3)
    //         004456b6     MOV        EAX,dword ptr [EBP + param_2]
    //                              Drawarea.cpp:3706 (3)
    //         004456b9     MOV        EDX,dword ptr [EBP + param_5]
    //                              Symbol Ref: No symbol: OverlayCpyLoop2
    //                               LAB_004456bc                                                 XREF[1]:     004456d6(j)  
    //                              Drawarea.cpp:3709 (3)
    //         004456bc     MOV        ESI,dword ptr [EBX + EAX*0x4]
    //                              Drawarea.cpp:3710 (3)
    //         004456bf     MOV        EDI,dword ptr [EBX + EDX*0x4]
    //                              Drawarea.cpp:3711 (3)
    //         004456c2     ADD        ESI,dword ptr [EBP + SrcXStart]
    //                              Drawarea.cpp:3712 (3)
    //         004456c5     ADD        EDI,dword ptr [EBP + DstXStart]
    //                              Drawarea.cpp:3713 (3)
    //         004456c8     MOV        this,dword ptr [EBP + LineLen]
    //                              Drawarea.cpp:3715 (2)
    //         004456cb     MOVSD.REP  ES:EDI,ESI
    //                              Drawarea.cpp:3717 (3)
    //         004456cd     ADD        EAX,dword ptr [EBP + param_1]
    //                              Drawarea.cpp:3718 (3)
    //         004456d0     ADD        EDX,dword ptr [EBP + param_1]
    //                              Drawarea.cpp:3719 (3)
    //         004456d3     DEC        dword ptr [EBP + Lines]
    //                              Drawarea.cpp:3720 (2)
    //         004456d6     JNZ        LAB_004456bc
    //                              Drawarea.cpp:3722 (1)
    //         004456d8     CLD
    //                              Drawarea.cpp:3724 (1)
    //         004456d9     POP        EBX
    //                              Drawarea.cpp:3725 (1)
    //         004456da     POP        EDI
    //                              Drawarea.cpp:3726 (1)
    //         004456db     POP        ESI
    //                               LAB_004456dc                                                 XREF[1]:     004456ad(j)  
    //                              Drawarea.cpp:3731 (18)
    //         004456dc     MOV        this,dword ptr [EBP + local_1c]
    //         004456df     MOV        EAX,dword ptr [this->DrawSystem]
    //         004456e1     TEST       EAX,EAX
    //         004456e3     JZ         LAB_004456f8
    //         004456e5     CMP        byte ptr [EAX + 0x478],0x2
    //         004456ec     JNZ        LAB_004456f8
    //                              Drawarea.cpp:3733 (10)
    //         004456ee     PUSH       s_OverlayMemCopy                                 = "OverlayMemCopy"
    //         004456f3     CALL       TDrawArea::Unlock                                void Unlock(TDrawArea * this, char * param_1)
    //                               LAB_004456f8                                                 XREF[4]:     00445598(j), 004455bb(j), 
    //                                                                                                         004456e3(j), 004456ec(j)  
    //                              Drawarea.cpp:3737 (9)
    //         004456f8     POP        EDI
    //         004456f9     POP        ESI
    //         004456fa     POP        EBX
    //         004456fb     MOV        ESP,EBP
    //         004456fd     POP        EBP
    //         004456fe     RET        0x18
}

// Offset: 0x00445710
void SetTrans(TDrawArea* this_, int param_2, uchar param_3) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TDrawArea::SetTrans(int,unsigned char)                                        *
    //                              *********************************************************************************************************
    //                              void __thiscall SetTrans(TDrawArea * this, int param_1, uchar param_2)
    //              void              <VOID>         <RETURN>
    //              TDrawArea *       ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     00445710(R)  
    //              uchar             Stack[0x8]:1   param_2                   XREF[1]:     00445721(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     00445760(W)  
    //              _DDCOLORKEY       Stack[-0xc]:8  ddck                      XREF[0,2]:   00445758(*), 0044575c(*)  
    //                               ?SetTrans@TDrawArea@@QAEXHE@Z                                XREF[9]:     LoadCursors:0045b4c8(c), 
    //                               TDrawArea::SetTrans                                                       draw:0045bc98(c), 
    //                                                                                                         Poll:0045c212(c), 
    //                                                                                                         draw:00479610(c), 
    //                                                                                                         draw:00479645(c), 
    //                                                                                                         draw:0051d1d9(c), 
    //                                                                                                         draw:0051d20e(c), 
    //                                                                                                         draw:0051dd80(c), 
    //                                                                                                         draw:0051ddb5(c)  
    //                              Drawarea.cpp:3746 (7)
    //         00445710     MOV        EAX,dword ptr [ESP + param_1]
    //         00445714     SUB        ESP,0x8
    //                              Drawarea.cpp:3752 (10)
    //         00445717     TEST       EAX,EAX
    //         00445719     MOV        dword ptr [ECX + this->UseTrans],EAX
    //         0044571f     JZ         LAB_0044572d
    //                              Drawarea.cpp:3753 (10)
    //         00445721     MOV        DL,byte ptr [ESP + param_2]
    //         00445725     MOV        byte ptr [ECX + this->TransColor],DL
    //                              Drawarea.cpp:3754 (2)
    //         0044572b     JMP        LAB_00445734
    //                               LAB_0044572d                                                 XREF[1]:     0044571f(j)  
    //                              Drawarea.cpp:3755 (7)
    //         0044572d     MOV        byte ptr [ECX + this->TransColor],0xff
    //                               LAB_00445734                                                 XREF[1]:     0044572b(j)  
    //                              Drawarea.cpp:3757 (26)
    //         00445734     TEST       EAX,EAX
    //         00445736     JZ         LAB_0044576d
    //         00445738     MOV        EAX,dword ptr [ECX + this->DrawSurface]
    //         0044573b     TEST       EAX,EAX
    //         0044573d     JZ         LAB_0044576d
    //         0044573f     MOV        EDX,dword ptr [this->DrawSystem]
    //         00445741     TEST       EDX,EDX
    //         00445743     JZ         LAB_0044576d
    //         00445745     CMP        byte ptr [EDX + 0x478],0x2
    //         0044574c     JNZ        LAB_0044576d
    //                              Drawarea.cpp:3759 (10)
    //         0044574e     XOR        EDX,EDX
    //         00445750     MOV        DL,byte ptr [ECX + this->TransColor]
    //         00445756     MOV        this,EDX
    //                              Drawarea.cpp:3761 (21)
    //         00445758     LEA        EDX=>ddck.dwColorSpaceHighValue,[ESP]
    //         0044575c     MOV        dword ptr [ESP]=>ddck.dwColorSpaceHighValue,this
    //         00445760     MOV        dword ptr [ESP + local_4],this
    //         00445764     MOV        this,dword ptr [EAX]
    //         00445766     PUSH       EDX
    //         00445767     PUSH       0x8
    //         00445769     PUSH       EAX
    //         0044576a     CALL       dword ptr [ECX + this+0x74]
    //                               LAB_0044576d                                                 XREF[4]:     00445736(j), 0044573d(j), 
    //                                                                                                         00445743(j), 0044574c(j)  
    //                              Drawarea.cpp:3768 (6)
    //         0044576d     ADD        ESP,0x8
    //         00445770     RET        0x8
}

// Offset: 0x00445780
void SetOverlayTrans(TDrawArea* this_, int param_2, uchar param_3) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TDrawArea::SetOverlayTrans(int,unsigned char)                                 *
    //                              *********************************************************************************************************
    //                              void __thiscall SetOverlayTrans(TDrawArea * this, int param_1, uchar
    //              void              <VOID>         <RETURN>
    //              TDrawArea *       ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     00445780(R)  
    //              uchar             Stack[0x8]:1   param_2                   XREF[1]:     00445784(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     004457be(W)  
    //              _DDCOLORKEY       Stack[-0xc]:8  ddck                      XREF[0,2]:   004457b6(*), 004457ba(*)  
    //                               ?SetOverlayTrans@TDrawArea@@QAEXHE@Z
    //                               TDrawArea::SetOverlayTrans
    //                              Drawarea.cpp:3775 (4)
    //         00445780     MOV        EDX,dword ptr [ESP + param_1]
    //                              Drawarea.cpp:3780 (13)
    //         00445784     MOV        EAX,dword ptr [ESP + param_2]
    //         00445788     SUB        ESP,0x8
    //         0044578b     MOV        dword ptr [ECX + this->UseTrans],EDX
    //                              Drawarea.cpp:3782 (32)
    //         00445791     TEST       EDX,EDX
    //         00445793     MOV        byte ptr [ECX + this->TransColor],AL
    //         00445799     JZ         LAB_004457cb
    //         0044579b     MOV        EDX,dword ptr [ECX + this->DrawSurface]
    //         0044579e     TEST       EDX,EDX
    //         004457a0     JZ         LAB_004457cb
    //         004457a2     MOV        this,dword ptr [this->DrawSystem]
    //         004457a4     TEST       this,this
    //         004457a6     JZ         LAB_004457cb
    //         004457a8     CMP        byte ptr [this->DrawSystem + 0x478],0x2
    //         004457af     JNZ        LAB_004457cb
    //                              Drawarea.cpp:3784 (5)
    //         004457b1     AND        EAX,0xff
    //                              Drawarea.cpp:3786 (21)
    //         004457b6     LEA        this=>ddck.dwColorSpaceHighValue,[ESP]
    //         004457ba     MOV        dword ptr [ESP]=>ddck.dwColorSpaceHighValue,EAX
    //         004457be     MOV        dword ptr [ESP + local_4],EAX
    //         004457c2     MOV        EAX,dword ptr [EDX]
    //         004457c4     PUSH       this
    //         004457c5     PUSH       0x10
    //         004457c7     PUSH       EDX
    //         004457c8     CALL       dword ptr [EAX + 0x74]
    //                               LAB_004457cb                                                 XREF[4]:     00445799(j), 004457a0(j), 
    //                                                                                                         004457a6(j), 004457af(j)  
    //                              Drawarea.cpp:3793 (6)
    //         004457cb     ADD        ESP,0x8
    //         004457ce     RET        0x8
}

// Offset: 0x004457E0
void SetPixel(TDrawArea* this_, long param_2, long param_3, uchar param_4) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TDrawArea::SetPixel(long,long,unsigned char)                                  *
    //                              *********************************************************************************************************
    //                              void __thiscall SetPixel(TDrawArea * this, long param_1, long param_
    //              void              <VOID>         <RETURN>
    //              TDrawArea *       ECX:4 (auto)   this
    //              long              Stack[0x4]:4   param_1                   XREF[1]:     004457e9(R)  
    //              long              Stack[0x8]:4   param_2                   XREF[1]:     004457f9(R)  
    //              uchar             Stack[0xc]:1   param_3                   XREF[2]:     00445817(R), 00445828(R)  
    //                               ?SetPixel@TDrawArea@@QAEXJJE@Z                               XREF[12]:    draw_tile:004379ff(c), 
    //                               TDrawArea::SetPixel                                                       draw_tile:00437a25(c), 
    //                                                                                                         draw_tile:00437a34(c), 
    //                                                                                                         draw_tile:00437a60(c), 
    //                                                                                                         draw_tile:00437aa1(c), 
    //                                                                                                         draw_tile:00437b12(c), 
    //                                                                                                         draw_tile:00437b37(c), 
    //                                                                                                         draw_tile:00437b49(c), 
    //                                                                                                         draw_tile:00437b70(c), 
    //                                                                                                         draw_tile:00437bac(c), 
    //                                                                                                         draw_view_rect:004384b1(c), 
    //                                                                                                         draw_view_rect:004384d7(c)  
    //                              Drawarea.cpp:3799 (1)
    //         004457e0     PUSH       ESI
    //                              Drawarea.cpp:3800 (8)
    //         004457e1     MOV        ESI,dword ptr [ECX + this->Bits]
    //         004457e4     TEST       ESI,ESI
    //         004457e6     PUSH       EDI
    //         004457e7     JZ         LAB_00445836
    //                              Drawarea.cpp:3803 (32)
    //         004457e9     MOV        EDX,dword ptr [ESP + param_1]
    //         004457ed     MOV        EAX,dword ptr [ECX + this->ClipRect.left]
    //         004457f0     CMP        EDX,EAX
    //         004457f2     JL         LAB_00445836
    //         004457f4     CMP        EDX,dword ptr [ECX + this+0x30]
    //         004457f7     JG         LAB_00445836
    //         004457f9     MOV        EAX,dword ptr [ESP + param_2]
    //         004457fd     MOV        EDI,dword ptr [ECX + this+0x2c]
    //         00445800     CMP        EAX,EDI
    //         00445802     JL         LAB_00445836
    //         00445804     CMP        EAX,dword ptr [ECX + this+0x34]
    //         00445807     JG         LAB_00445836
    //                              Drawarea.cpp:3805 (6)
    //         00445809     CMP        dword ptr [ECX + this->Orien],0x1
    //         0044580d     JNZ        LAB_00445823
    //                              Drawarea.cpp:3806 (15)
    //         0044580f     MOV        this,dword ptr [ECX + this->Pitch]
    //         00445812     IMUL       this,EAX
    //         00445815     ADD        this,EDX
    //         00445817     MOV        DL,byte ptr [ESP + param_3]
    //         0044581b     MOV        byte ptr [this->DrawSystem + ESI*0x1],DL
    //                              Drawarea.cpp:3810 (5)
    //         0044581e     POP        EDI
    //         0044581f     POP        ESI
    //         00445820     RET        0xc
    //                               LAB_00445823                                                 XREF[1]:     0044580d(j)  
    //                              Drawarea.cpp:3808 (19)
    //         00445823     MOV        EDI,dword ptr [ECX + this->Height]
    //         00445826     SUB        EDI,EAX
    //         00445828     MOV        AL,byte ptr [ESP + param_3]
    //         0044582c     DEC        EDI
    //         0044582d     IMUL       EDI,dword ptr [ECX + this->Pitch]
    //         00445831     ADD        EDI,EDX
    //         00445833     MOV        byte ptr [EDI + ESI*0x1],AL
    //                               LAB_00445836                                                 XREF[5]:     004457e7(j), 004457f2(j), 
    //                                                                                                         004457f7(j), 00445802(j), 
    //                                                                                                         00445807(j)  
    //                              Drawarea.cpp:3810 (5)
    //         00445836     POP        EDI
    //         00445837     POP        ESI
    //         00445838     RET        0xc
}

// Offset: 0x00445840
void DrawLine(TDrawArea* this_, int param_2, int param_3, int param_4, int param_5, uchar param_6) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TDrawArea::DrawLine(int,int,int,int,unsigned char)                            *
    //                              *********************************************************************************************************
    //                              void __thiscall DrawLine(TDrawArea * this, int param_1, int param_2,
    //              void              <VOID>         <RETURN>
    //              TDrawArea *       ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[5]:     00445847(R), 004458dd(W), 004458ee(W), 00445926(R), 
    //                                                                                     00445990(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[6]:     00445850(R), 00445891(R), 004458e6(W), 004458f7(W), 
    //                                                                                     0044592f(R), 00445983(R)  
    //              int               Stack[0xc]:4   param_3                   XREF[8]:     00445842(R), 0044586f(W), 00445875(R), 004458c6(W), 
    //                                                                                     00445901(R), 00445938(R), 00445969(W), 00445996(R)  
    //              int               Stack[0x10]:4  param_4                   XREF[4]:     00445854(R), 00445895(R), 004458cc(W), 00445979(R)  
    //              uchar             Stack[0x14]:1  param_5                   XREF[5]:     00445866(R), 0044589d(R), 00445913(R), 00445941(R), 
    //                                                                                     0044595e(R)  
    //                               ?DrawLine@TDrawArea@@QAEXHHHHE@Z                             XREF[11]:    view_function_terrain:0053810d(c), 
    //                               TDrawArea::DrawLine                                                       Draw_GDI_Object:00538451(c), 
    //                                                                                                         Draw_GDI_Object:00538470(c), 
    //                                                                                                         Draw_GDI_Object:0053848f(c), 
    //                                                                                                         Draw_GDI_Object:005384ae(c), 
    //                                                                                                         Draw_GDI_Object:005384e5(c), 
    //                                                                                                         Draw_GDI_Object:00538504(c), 
    //                                                                                                         Draw_GDI_Object:0053852f(c), 
    //                                                                                                         Draw_GDI_Object:0053854b(c), 
    //                                                                                                         Draw_GDI_Object:00538567(c), 
    //                                                                                                         Draw_GDI_Object:00538583(c)  
    //                              Drawarea.cpp:3817 (2)
    //         00445840     PUSH       EBX
    //         00445841     PUSH       EBP
    //                              Drawarea.cpp:3821 (14)
    //         00445842     MOV        EBP,dword ptr [ESP + param_3]
    //         00445846     PUSH       ESI
    //         00445847     MOV        ESI,dword ptr [ESP + param_1]
    //         0044584b     PUSH       EDI
    //         0044584c     CMP        ESI,EBP
    //         0044584e     JNZ        LAB_00445891
    //                              Drawarea.cpp:3823 (18)
    //         00445850     MOV        EDI,dword ptr [ESP + param_2]
    //         00445854     MOV        EBX,dword ptr [ESP + param_4]
    //         00445858     CMP        EDI,EBX
    //         0044585a     JLE        LAB_00445866
    //         0044585c     MOV        EAX,EDI
    //         0044585e     MOV        EDI,EBX
    //         00445860     MOV        EBX,EAX
    //                              Drawarea.cpp:3825 (4)
    //         00445862     CMP        EDI,EBX
    //         00445864     JG         LAB_0044588a
    //                               LAB_00445866                                                 XREF[1]:     0044585a(j)  
    //                              Drawarea.cpp:3826 (36)
    //         00445866     MOV        EAX,dword ptr [ESP + param_5]
    //         0044586a     AND        EAX,0xff
    //         0044586f     MOV        dword ptr [ESP + param_3],EAX
    //         00445873     JMP        LAB_00445879
    //                               LAB_00445875                                                 XREF[1]:     00445888(j)  
    //         00445875     MOV        EAX,dword ptr [ESP + param_3]
    //                               LAB_00445879                                                 XREF[1]:     00445873(j)  
    //         00445879     PUSH       EAX
    //         0044587a     PUSH       EDI
    //         0044587b     PUSH       EBP
    //         0044587c     PUSH       ESI
    //         0044587d     CALL       _ASMDraw_HLine                                   undefined _ASMDraw_HLine()
    //         00445882     ADD        ESP,0x10
    //         00445885     INC        EDI
    //         00445886     CMP        EDI,EBX
    //         00445888     JLE        LAB_00445875
    //                               LAB_0044588a                                                 XREF[2]:     00445864(j), 0044597d(j)  
    //                              Drawarea.cpp:3907 (7)
    //         0044588a     POP        EDI
    //         0044588b     POP        ESI
    //         0044588c     POP        EBP
    //         0044588d     POP        EBX
    //         0044588e     RET        0x14
    //                               LAB_00445891                                                 XREF[1]:     0044584e(j)  
    //                              Drawarea.cpp:3831 (12)
    //         00445891     MOV        EAX,dword ptr [ESP + param_2]
    //         00445895     MOV        this,dword ptr [ESP + param_4]
    //         00445899     CMP        EAX,this
    //         0044589b     JNZ        LAB_004458ba
    //                              Drawarea.cpp:3833 (22)
    //         0044589d     MOV        this,dword ptr [ESP + param_5]
    //         004458a1     AND        this,0xff
    //         004458a7     PUSH       this
    //         004458a8     PUSH       EAX
    //         004458a9     PUSH       EBP
    //         004458aa     PUSH       ESI
    //         004458ab     CALL       _ASMDraw_HLine                                   undefined _ASMDraw_HLine()
    //         004458b0     ADD        ESP,0x10
    //                              Drawarea.cpp:3907 (7)
    //         004458b3     POP        EDI
    //         004458b4     POP        ESI
    //         004458b5     POP        EBP
    //         004458b6     POP        EBX
    //         004458b7     RET        0x14
    //                               LAB_004458ba                                                 XREF[1]:     0044589b(j)  
    //                              Drawarea.cpp:3839 (4)
    //         004458ba     CMP        EBP,ESI
    //         004458bc     JGE        LAB_004458d2
    //                              Drawarea.cpp:3841 (4)
    //         004458be     MOV        EDX,EAX
    //         004458c0     MOV        EAX,this
    //                              Drawarea.cpp:3842 (16)
    //         004458c2     MOV        this,ESI
    //         004458c4     MOV        ESI,EBP
    //         004458c6     MOV        dword ptr [ESP + param_3],this
    //         004458ca     MOV        EBP,this
    //         004458cc     MOV        dword ptr [ESP + param_4],EDX
    //         004458d0     MOV        this,EDX
    //                               LAB_004458d2                                                 XREF[1]:     004458bc(j)  
    //                              Drawarea.cpp:3847 (2)
    //         004458d2     SUB        EBP,ESI
    //                              Drawarea.cpp:3848 (3)
    //         004458d4     MOV        EDI,EAX
    //         004458d6     INC        EBP
    //                              Drawarea.cpp:3850 (4)
    //         004458d7     CMP        EAX,this
    //         004458d9     JGE        LAB_004458ec
    //                              Drawarea.cpp:3852 (2)
    //         004458db     SUB        this,EAX
    //                              Drawarea.cpp:3853 (13)
    //         004458dd     MOV        dword ptr [ESP + param_1],0x1
    //         004458e5     INC        this
    //         004458e6     MOV        dword ptr [ESP + param_2],this
    //                              Drawarea.cpp:3855 (2)
    //         004458ea     JMP        LAB_004458fd
    //                               LAB_004458ec                                                 XREF[1]:     004458d9(j)  
    //                              Drawarea.cpp:3857 (2)
    //         004458ec     SUB        EAX,this
    //                              Drawarea.cpp:3858 (15)
    //         004458ee     MOV        dword ptr [ESP + param_1],0xffffffff
    //         004458f6     INC        EAX
    //         004458f7     MOV        dword ptr [ESP + param_2],EAX
    //         004458fb     MOV        this,EAX
    //                               LAB_004458fd                                                 XREF[1]:     004458ea(j)  
    //                              Drawarea.cpp:3861 (4)
    //         004458fd     CMP        EBP,this
    //         004458ff     JL         LAB_0044595e
    //                              Drawarea.cpp:3868 (12)
    //         00445901     MOV        EDX,dword ptr [ESP + param_3]
    //         00445905     XOR        EBX,EBX
    //         00445907     CMP        ESI,EDX
    //         00445909     MOV        EAX,ESI
    //         0044590b     JGE        LAB_00445941
    //                               LAB_0044590d                                                 XREF[1]:     0044593f(j)  
    //                              Drawarea.cpp:3870 (2)
    //         0044590d     ADD        EBX,this
    //                              Drawarea.cpp:3871 (4)
    //         0044590f     CMP        EBX,EBP
    //         00445911     JL         LAB_00445938
    //                              Drawarea.cpp:3873 (19)
    //         00445913     MOV        EDX,dword ptr [ESP + param_5]
    //         00445917     AND        EDX,0xff
    //         0044591d     PUSH       EDX
    //         0044591e     PUSH       EDI
    //         0044591f     PUSH       ESI
    //         00445920     PUSH       EAX
    //         00445921     CALL       _ASMDraw_HLine                                   undefined _ASMDraw_HLine()
    //                              Drawarea.cpp:3874 (9)
    //         00445926     MOV        this,dword ptr [ESP + param_1]
    //         0044592a     ADD        ESP,0x10
    //         0044592d     ADD        EDI,this
    //                              Drawarea.cpp:3876 (13)
    //         0044592f     MOV        this,dword ptr [ESP + param_2]
    //         00445933     SUB        EBX,EBP
    //         00445935     LEA        EAX,[ESI + 0x1]
    //                               LAB_00445938                                                 XREF[1]:     00445911(j)  
    //         00445938     MOV        EDX,dword ptr [ESP + param_3]
    //                              Drawarea.cpp:3879 (5)
    //         0044593c     INC        ESI
    //         0044593d     CMP        ESI,EDX
    //         0044593f     JL         LAB_0044590d
    //                               LAB_00445941                                                 XREF[1]:     0044590b(j)  
    //                              Drawarea.cpp:3881 (22)
    //         00445941     MOV        this,dword ptr [ESP + param_5]
    //         00445945     AND        this,0xff
    //         0044594b     PUSH       this
    //         0044594c     PUSH       EDI
    //         0044594d     PUSH       ESI
    //         0044594e     PUSH       EAX
    //         0044594f     CALL       _ASMDraw_HLine                                   undefined _ASMDraw_HLine()
    //         00445954     ADD        ESP,0x10
    //                              Drawarea.cpp:3907 (31)
    //         00445957     POP        EDI
    //         00445958     POP        ESI
    //         00445959     POP        EBP
    //         0044595a     POP        EBX
    //         0044595b     RET        0x14
    //                               LAB_0044595e                                                 XREF[1]:     004458ff(j)  
    //         0044595e     MOV        EAX,dword ptr [ESP + param_5]
    //         00445962     XOR        EBX,EBX
    //         00445964     AND        EAX,0xff
    //         00445969     MOV        dword ptr [ESP + param_3],EAX
    //                               LAB_0044596d                                                 XREF[1]:     0044599a(j)  
    //         0044596d     PUSH       EAX
    //         0044596e     PUSH       EDI
    //         0044596f     PUSH       ESI
    //         00445970     PUSH       ESI
    //         00445971     CALL       _ASMDraw_HLine                                   undefined _ASMDraw_HLine()
    //                              Drawarea.cpp:3892 (3)
    //         00445976     ADD        ESP,0x10
    //                              Drawarea.cpp:3894 (10)
    //         00445979     CMP        EDI,dword ptr [ESP + param_4]
    //         0044597d     JZ         LAB_0044588a
    //                              Drawarea.cpp:3898 (10)
    //         00445983     MOV        EAX,dword ptr [ESP + param_2]
    //         00445987     ADD        EBX,EBP
    //         00445989     CMP        EBX,EAX
    //         0044598b     JL         LAB_00445990
    //                              Drawarea.cpp:3900 (1)
    //         0044598d     INC        ESI
    //                              Drawarea.cpp:3901 (2)
    //         0044598e     SUB        EBX,EAX
    //                               LAB_00445990                                                 XREF[1]:     0044598b(j)  
    //                              Drawarea.cpp:3903 (12)
    //         00445990     MOV        EAX,dword ptr [ESP + param_1]
    //         00445994     ADD        EDI,EAX
    //         00445996     MOV        EAX,dword ptr [ESP + param_3]
    //         0044599a     JMP        LAB_0044596d
}

// Offset: 0x004459A0
void DrawRect(TDrawArea* this_, long param_2, long param_3, long param_4, long param_5, uchar param_6) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TDrawArea::DrawRect(long,long,long,long,unsigned char)                        *
    //                              *********************************************************************************************************
    //                              void __thiscall DrawRect(TDrawArea * this, long param_1, long param_
    //              void              <VOID>         <RETURN>
    //              TDrawArea *       ECX:4 (auto)   this
    //              long              Stack[0x4]:4   param_1                   XREF[1]:     004459a3(R)  
    //              long              Stack[0x8]:4   param_2                   XREF[1]:     004459bf(R)  
    //              long              Stack[0xc]:4   param_3                   XREF[3]:     004459a9(R), 004459b9(W), 00445a1c(R)  
    //              long              Stack[0x10]:4  param_4                   XREF[3]:     004459c3(R), 004459cf(W), 004459f6(R)  
    //              uchar             Stack[0x14]:1  param_5                   XREF[4]:     004459e5(R), 004459f2(R), 00445a09(R), 00445a18(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     004459af(W), 004459fc(R)  
    //                               ?DrawRect@TDrawArea@@QAEXJJJJE@Z                             XREF[14]:    DrawRect:00445a58(c), 
    //                               TDrawArea::DrawRect                                                       draw:00472e4a(c), 
    //                                                                                                         draw:00472e73(c), 
    //                                                                                                         draw:00472ee0(c), 
    //                                                                                                         draw:00473007(c), 
    //                                                                                                         draw:00476786(c), 
    //                                                                                                         draw_highlight_bar:00478da9(c), 
    //                                                                                                         draw_border:0047b6f3(c), 
    //                                                                                                         draw_border:0047b7db(c), 
    //                                                                                                         draw_border:0047b7ef(c), 
    //                                                                                                         draw_border:0047d5d1(c), 
    //                                                                                                         draw_frame:004c3bcf(c), 
    //                                                                                                         draw_frame:004c3c1e(c), 
    //                                                                                                         draw_border:0051f181(c)  
    //                              Drawarea.cpp:3915 (3)
    //         004459a0     PUSH       this
    //         004459a1     PUSH       EBX
    //         004459a2     PUSH       EBP
    //                              Drawarea.cpp:3919 (18)
    //         004459a3     MOV        EBP,dword ptr [ESP + param_1]
    //         004459a7     PUSH       ESI
    //         004459a8     PUSH       EDI
    //         004459a9     MOV        EDI,dword ptr [ESP + param_3]
    //         004459ad     CMP        EBP,EDI
    //         004459af     MOV        dword ptr [ESP + local_4],this
    //         004459b3     JLE        LAB_004459bf
    //                              Drawarea.cpp:3921 (2)
    //         004459b5     MOV        EAX,EBP
    //                              Drawarea.cpp:3922 (2)
    //         004459b7     MOV        EBP,EDI
    //                              Drawarea.cpp:3923 (6)
    //         004459b9     MOV        dword ptr [ESP + param_3],EAX
    //         004459bd     MOV        EDI,EAX
    //                               LAB_004459bf                                                 XREF[1]:     004459b3(j)  
    //                              Drawarea.cpp:3926 (12)
    //         004459bf     MOV        EBX,dword ptr [ESP + param_2]
    //         004459c3     MOV        ESI,dword ptr [ESP + param_4]
    //         004459c7     CMP        EBX,ESI
    //         004459c9     JLE        LAB_004459d5
    //                              Drawarea.cpp:3928 (2)
    //         004459cb     MOV        EAX,EBX
    //                              Drawarea.cpp:3929 (2)
    //         004459cd     MOV        EBX,ESI
    //                              Drawarea.cpp:3930 (6)
    //         004459cf     MOV        dword ptr [ESP + param_4],EAX
    //         004459d3     MOV        ESI,EAX
    //                               LAB_004459d5                                                 XREF[1]:     004459c9(j)  
    //                              Drawarea.cpp:3933 (3)
    //         004459d5     SUB        EDI,EBP
    //         004459d7     INC        EDI
    //                              Drawarea.cpp:3934 (5)
    //         004459d8     CMP        EDI,0x1
    //         004459db     JL         LAB_00445a2b
    //                              Drawarea.cpp:3937 (3)
    //         004459dd     SUB        ESI,EBX
    //         004459df     INC        ESI
    //                              Drawarea.cpp:3938 (5)
    //         004459e0     CMP        ESI,0x1
    //         004459e3     JL         LAB_00445a2b
    //                              Drawarea.cpp:3941 (13)
    //         004459e5     MOV        EAX,dword ptr [ESP + param_5]
    //         004459e9     PUSH       EAX
    //         004459ea     PUSH       EDI
    //         004459eb     PUSH       EBX
    //         004459ec     PUSH       EBP
    //         004459ed     CALL       TDrawArea::DrawHorzLine                          void DrawHorzLine(TDrawArea * this, long para
    //                              Drawarea.cpp:3942 (23)
    //         004459f2     MOV        this,dword ptr [ESP + param_5]
    //         004459f6     MOV        EDX,dword ptr [ESP + param_4]
    //         004459fa     PUSH       this
    //         004459fb     PUSH       EDI
    //         004459fc     MOV        EDI,dword ptr [ESP + local_4]
    //         00445a00     PUSH       EDX
    //         00445a01     PUSH       EBP
    //         00445a02     MOV        this,EDI
    //         00445a04     CALL       TDrawArea::DrawHorzLine                          void DrawHorzLine(TDrawArea * this, long para
    //                              Drawarea.cpp:3943 (15)
    //         00445a09     MOV        EAX,dword ptr [ESP + param_5]
    //         00445a0d     MOV        this,EDI
    //         00445a0f     PUSH       EAX
    //         00445a10     PUSH       ESI
    //         00445a11     PUSH       EBX
    //         00445a12     PUSH       EBP
    //         00445a13     CALL       TDrawArea::DrawVertLine                          void DrawVertLine(TDrawArea * this, long para
    //                              Drawarea.cpp:3944 (19)
    //         00445a18     MOV        this,dword ptr [ESP + param_5]
    //         00445a1c     MOV        EDX,dword ptr [ESP + param_3]
    //         00445a20     PUSH       this
    //         00445a21     PUSH       ESI
    //         00445a22     PUSH       EBX
    //         00445a23     PUSH       EDX
    //         00445a24     MOV        this,EDI
    //         00445a26     CALL       TDrawArea::DrawVertLine                          void DrawVertLine(TDrawArea * this, long para
    //                               LAB_00445a2b                                                 XREF[2]:     004459db(j), 004459e3(j)  
    //                              Drawarea.cpp:3945 (8)
    //         00445a2b     POP        EDI
    //         00445a2c     POP        ESI
    //         00445a2d     POP        EBP
    //         00445a2e     POP        EBX
    //         00445a2f     POP        this
    //         00445a30     RET        0x14
}

// Offset: 0x00445A40
void DrawRect(TDrawArea* this_, tagRECT* param_2, uchar param_3) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TDrawArea::DrawRect(struct tagRECT *,unsigned char)                           *
    //                              *********************************************************************************************************
    //                              void __thiscall DrawRect(TDrawArea * this, tagRECT * param_1, uchar 
    //              void              <VOID>         <RETURN>
    //              TDrawArea *       ECX:4 (auto)   this
    //              tagRECT *         Stack[0x4]:4   param_1                   XREF[1]:     00445a45(R)  
    //              uchar             Stack[0x8]:1   param_2                   XREF[1]:     00445a40(R)  
    //                               ?DrawRect@TDrawArea@@QAEXPAUtagRECT@@E@Z
    //                               TDrawArea::DrawRect
    //                              Drawarea.cpp:3951 (29)
    //         00445a40     MOV        EAX,dword ptr [ESP + param_2]
    //         00445a44     PUSH       EAX
    //         00445a45     MOV        EAX,dword ptr [ESP + param_1]
    //         00445a49     MOV        EDX,dword ptr [EAX + 0xc]
    //         00445a4c     PUSH       EDX
    //         00445a4d     MOV        EDX,dword ptr [EAX + 0x8]
    //         00445a50     PUSH       EDX
    //         00445a51     MOV        EDX,dword ptr [EAX + 0x4]
    //         00445a54     MOV        EAX,dword ptr [EAX]
    //         00445a56     PUSH       EDX
    //         00445a57     PUSH       EAX
    //         00445a58     CALL       TDrawArea::DrawRect                              void DrawRect(TDrawArea * this, long param_1,
    //                              Drawarea.cpp:3953 (3)
    //         00445a5d     RET        0x8
}

// Offset: 0x00445A60
void DrawHorzLine(TDrawArea* this_, long param_2, long param_3, long param_4, uchar param_5) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TDrawArea::DrawHorzLine(long,long,long,unsigned char)                         *
    //                              *********************************************************************************************************
    //                              void __thiscall DrawHorzLine(TDrawArea * this, long param_1, long pa
    //              void              <VOID>         <RETURN>
    //              TDrawArea *       ECX:4 (auto)   this
    //              long              Stack[0x4]:4   param_1                   XREF[1]:     00445a6e(R)  
    //              long              Stack[0x8]:4   param_2                   XREF[1]:     00445a76(R)  
    //              long              Stack[0xc]:4   param_3                   XREF[2]:     00445a8d(R), 00445a99(R)  
    //              uchar             Stack[0x10]:1  param_4                   XREF[1]:     00445ac7(R)  
    //                               ?DrawHorzLine@TDrawArea@@QAEXJJJE@Z                          XREF[26]:    draw_clipped_horz_line:0043823f(c)
    //                               TDrawArea::DrawHorzLine                                                   DrawRect:004459ed(c), 
    //                                                                                                         DrawRect:00445a04(c), 
    //                                                                                                         DrawBevel2:00445d81(c), 
    //                                                                                                         DrawBevel2:00445dbb(c), 
    //                                                                                                         DrawBevel2:00445dec(c), 
    //                                                                                                         DrawBevel2:00445e1d(c), 
    //                                                                                                         DrawBevel3:00445ea3(c), 
    //                                                                                                         DrawBevel3:00445ee1(c), 
    //                                                                                                         DrawBevel3:00445f1c(c), 
    //                                                                                                         DrawBevel3:00445f4f(c), 
    //                                                                                                         DrawBevel3:00445f80(c), 
    //                                                                                                         DrawBevel3:00445fb3(c), 
    //                                                                                                         DrawBevel21:00446040(c), 
    //                                                                                                         DrawBevel21:00446072(c), 
    //                                                                                                         DrawBevel21:004460a3(c), 
    //                                                                                                         DrawBevel32:00446121(c), 
    //                                                                                                         DrawBevel32:0044615f(c), 
    //                                                                                                         DrawBevel32:00446192(c), 
    //                                                                                                         DrawBevel32:004461c5(c), [more]
    //                              Drawarea.cpp:3959 (2)
    //         00445a60     PUSH       EBX
    //         00445a61     PUSH       EBP
    //                              Drawarea.cpp:3962 (9)
    //         00445a62     MOV        EBP,dword ptr [ECX + this->Bits]
    //         00445a65     PUSH       ESI
    //         00445a66     TEST       EBP,EBP
    //         00445a68     PUSH       EDI
    //         00445a69     JZ         LAB_00445ae0
    //                              Drawarea.cpp:3965 (27)
    //         00445a6b     MOV        EAX,dword ptr [ECX + this+0x30]
    //         00445a6e     MOV        EDX,dword ptr [ESP + param_1]
    //         00445a72     CMP        EDX,EAX
    //         00445a74     JG         LAB_00445ae0
    //         00445a76     MOV        EBX,dword ptr [ESP + param_2]
    //         00445a7a     MOV        ESI,dword ptr [ECX + this+0x2c]
    //         00445a7d     CMP        EBX,ESI
    //         00445a7f     JL         LAB_00445ae0
    //         00445a81     CMP        EBX,dword ptr [ECX + this+0x34]
    //         00445a84     JG         LAB_00445ae0
    //                              Drawarea.cpp:3968 (7)
    //         00445a86     MOV        ESI,dword ptr [ECX + this->ClipRect.left]
    //         00445a89     CMP        EDX,ESI
    //         00445a8b     JGE        LAB_00445a99
    //                              Drawarea.cpp:3970 (8)
    //         00445a8d     MOV        EDI,dword ptr [ESP + param_3]
    //         00445a91     SUB        EDX,ESI
    //         00445a93     ADD        EDI,EDX
    //                              Drawarea.cpp:3971 (8)
    //         00445a95     MOV        EDX,ESI
    //         00445a97     JMP        LAB_00445a9d
    //                               LAB_00445a99                                                 XREF[1]:     00445a8b(j)  
    //         00445a99     MOV        EDI,dword ptr [ESP + param_3]
    //                               LAB_00445a9d                                                 XREF[1]:     00445a97(j)  
    //                              Drawarea.cpp:3974 (8)
    //         00445a9d     LEA        ESI,[EDI + EDX*0x1 + -0x1]
    //         00445aa1     CMP        ESI,EAX
    //         00445aa3     JLE        LAB_00445aaa
    //                              Drawarea.cpp:3975 (5)
    //         00445aa5     SUB        EAX,EDX
    //         00445aa7     INC        EAX
    //         00445aa8     MOV        EDI,EAX
    //                               LAB_00445aaa                                                 XREF[1]:     00445aa3(j)  
    //                              Drawarea.cpp:3977 (5)
    //         00445aaa     CMP        EDI,0x1
    //         00445aad     JL         LAB_00445ae0
    //                              Drawarea.cpp:3980 (6)
    //         00445aaf     CMP        dword ptr [ECX + this->Orien],0x1
    //         00445ab3     JNZ        LAB_00445abd
    //                              Drawarea.cpp:3981 (6)
    //         00445ab5     MOV        EAX,dword ptr [ECX + this->Pitch]
    //         00445ab8     IMUL       EAX,EBX
    //                              Drawarea.cpp:3982 (2)
    //         00445abb     JMP        LAB_00445ac7
    //                               LAB_00445abd                                                 XREF[1]:     00445ab3(j)  
    //                              Drawarea.cpp:3983 (10)
    //         00445abd     MOV        EAX,dword ptr [ECX + this->Height]
    //         00445ac0     SUB        EAX,EBX
    //         00445ac2     DEC        EAX
    //         00445ac3     IMUL       EAX,dword ptr [ECX + this->Pitch]
    //                               LAB_00445ac7                                                 XREF[1]:     00445abb(j)  
    //                              Drawarea.cpp:3985 (25)
    //         00445ac7     MOV        this,dword ptr [ESP + param_4]
    //         00445acb     ADD        EAX,EDX
    //         00445acd     AND        this,0xff
    //         00445ad3     ADD        EAX,EBP
    //         00445ad5     PUSH       EDI
    //         00445ad6     PUSH       this
    //         00445ad7     PUSH       EAX
    //         00445ad8     CALL       memset                                           undefined memset()
    //         00445add     ADD        ESP,0xc
    //                               LAB_00445ae0                                                 XREF[5]:     00445a69(j), 00445a74(j), 
    //                                                                                                         00445a7f(j), 00445a84(j), 
    //                                                                                                         00445aad(j)  
    //                              Drawarea.cpp:3986 (7)
    //         00445ae0     POP        EDI
    //         00445ae1     POP        ESI
    //         00445ae2     POP        EBP
    //         00445ae3     POP        EBX
    //         00445ae4     RET        0x10
}

// Offset: 0x00445AF0
void DrawVertLine(TDrawArea* this_, long param_2, long param_3, long param_4, uchar param_5) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TDrawArea::DrawVertLine(long,long,long,unsigned char)                         *
    //                              *********************************************************************************************************
    //                              void __thiscall DrawVertLine(TDrawArea * this, long param_1, long pa
    //              void              <VOID>         <RETURN>
    //              TDrawArea *       ECX:4 (auto)   this
    //              long              Stack[0x4]:4   param_1                   XREF[1]:     00445afb(R)  
    //              long              Stack[0x8]:4   param_2                   XREF[1]:     00445b0e(R)  
    //              long              Stack[0xc]:4   param_3                   XREF[2]:     00445b1d(R), 00445b29(R)  
    //              uchar             Stack[0x10]:1  param_4                   XREF[1]:     00445b6b(R)  
    //                               ?DrawVertLine@TDrawArea@@QAEXJJJE@Z                          XREF[30]:    DrawRect:00445a13(c), 
    //                               TDrawArea::DrawVertLine                                                   DrawRect:00445a26(c), 
    //                                                                                                         DrawBevel2:00445d9e(c), 
    //                                                                                                         DrawBevel2:00445dd5(c), 
    //                                                                                                         DrawBevel2:00445e02(c), 
    //                                                                                                         DrawBevel3:00445ec0(c), 
    //                                                                                                         DrawBevel3:00445eff(c), 
    //                                                                                                         DrawBevel3:00445f38(c), 
    //                                                                                                         DrawBevel3:00445f65(c), 
    //                                                                                                         DrawBevel3:00445f96(c), 
    //                                                                                                         DrawBevel3:00445fc5(c), 
    //                                                                                                         DrawBevel21:00446059(c), 
    //                                                                                                         DrawBevel21:0044608c(c), 
    //                                                                                                         DrawBevel21:004460b3(c), 
    //                                                                                                         DrawBevel32:0044613e(c), 
    //                                                                                                         DrawBevel32:00446179(c), 
    //                                                                                                         DrawBevel32:004461ae(c), 
    //                                                                                                         DrawBevel32:004461db(c), 
    //                                                                                                         DrawBevel32:00446208(c), 
    //                                                                                                         draw:004778d4(c), [more]
    //                              Drawarea.cpp:3992 (1)
    //         00445af0     PUSH       EBX
    //                              Drawarea.cpp:3997 (10)
    //         00445af1     MOV        EBX,dword ptr [ECX + this->Bits]
    //         00445af4     PUSH       EBP
    //         00445af5     PUSH       ESI
    //         00445af6     TEST       EBX,EBX
    //         00445af8     PUSH       EDI
    //         00445af9     JZ         LAB_00445b78
    //                              Drawarea.cpp:4000 (16)
    //         00445afb     MOV        EDI,dword ptr [ESP + param_1]
    //         00445aff     MOV        EAX,dword ptr [ECX + this->ClipRect.left]
    //         00445b02     CMP        EDI,EAX
    //         00445b04     JL         LAB_00445b78
    //         00445b06     CMP        EDI,dword ptr [ECX + this+0x30]
    //         00445b09     JG         LAB_00445b78
    //                              Drawarea.cpp:4003 (11)
    //         00445b0b     MOV        EAX,dword ptr [ECX + this+0x34]
    //         00445b0e     MOV        EDX,dword ptr [ESP + param_2]
    //         00445b12     CMP        EDX,EAX
    //         00445b14     JG         LAB_00445b78
    //                              Drawarea.cpp:4006 (7)
    //         00445b16     MOV        ESI,dword ptr [ECX + this+0x2c]
    //         00445b19     CMP        EDX,ESI
    //         00445b1b     JGE        LAB_00445b29
    //                              Drawarea.cpp:4008 (8)
    //         00445b1d     MOV        EBP,dword ptr [ESP + param_3]
    //         00445b21     SUB        EDX,ESI
    //         00445b23     ADD        EBP,EDX
    //                              Drawarea.cpp:4009 (8)
    //         00445b25     MOV        EDX,ESI
    //         00445b27     JMP        LAB_00445b2d
    //                               LAB_00445b29                                                 XREF[1]:     00445b1b(j)  
    //         00445b29     MOV        EBP,dword ptr [ESP + param_3]
    //                               LAB_00445b2d                                                 XREF[1]:     00445b27(j)  
    //                              Drawarea.cpp:4012 (8)
    //         00445b2d     LEA        ESI,[EBP + EDX*0x1 + -0x1]
    //         00445b31     CMP        ESI,EAX
    //         00445b33     JLE        LAB_00445b3a
    //                              Drawarea.cpp:4013 (5)
    //         00445b35     SUB        EAX,EDX
    //         00445b37     INC        EAX
    //         00445b38     MOV        EBP,EAX
    //                               LAB_00445b3a                                                 XREF[1]:     00445b33(j)  
    //                              Drawarea.cpp:4015 (5)
    //         00445b3a     CMP        EBP,0x1
    //         00445b3d     JL         LAB_00445b78
    //                              Drawarea.cpp:4018 (6)
    //         00445b3f     CMP        dword ptr [ECX + this->Orien],0x1
    //         00445b43     JNZ        LAB_00445b55
    //                              Drawarea.cpp:4020 (8)
    //         00445b45     MOV        this,dword ptr [ECX + this->Pitch]
    //         00445b48     IMUL       EDX,this
    //         00445b4b     ADD        EDX,EDI
    //                              Drawarea.cpp:4021 (6)
    //         00445b4d     MOV        ESI,this
    //         00445b4f     ADD        EDX,EBX
    //         00445b51     MOV        EAX,EDX
    //                              Drawarea.cpp:4023 (2)
    //         00445b53     JMP        LAB_00445b67
    //                               LAB_00445b55                                                 XREF[1]:     00445b43(j)  
    //                              Drawarea.cpp:4025 (16)
    //         00445b55     MOV        EAX,dword ptr [ECX + this->Height]
    //         00445b58     MOV        ESI,dword ptr [ECX + this->Pitch]
    //         00445b5b     SUB        EAX,EDX
    //         00445b5d     DEC        EAX
    //         00445b5e     IMUL       EAX,ESI
    //         00445b61     ADD        EAX,EDI
    //         00445b63     ADD        EAX,EBX
    //                              Drawarea.cpp:4026 (2)
    //         00445b65     NEG        ESI
    //                               LAB_00445b67                                                 XREF[1]:     00445b53(j)  
    //                              Drawarea.cpp:4029 (10)
    //         00445b67     TEST       EBP,EBP
    //         00445b69     JLE        LAB_00445b78
    //         00445b6b     MOV        DL,byte ptr [ESP + param_4]
    //         00445b6f     MOV        this,EBP
    //                               LAB_00445b71                                                 XREF[1]:     00445b76(j)  
    //                              Drawarea.cpp:4031 (2)
    //         00445b71     MOV        byte ptr [EAX],DL
    //                              Drawarea.cpp:4032 (5)
    //         00445b73     ADD        EAX,ESI
    //         00445b75     DEC        this
    //         00445b76     JNZ        LAB_00445b71
    //                               LAB_00445b78                                                 XREF[6]:     00445af9(j), 00445b04(j), 
    //                                                                                                         00445b09(j), 00445b14(j), 
    //                                                                                                         00445b3d(j), 00445b69(j)  
    //                              Drawarea.cpp:4034 (7)
    //         00445b78     POP        EDI
    //         00445b79     POP        ESI
    //         00445b7a     POP        EBP
    //         00445b7b     POP        EBX
    //         00445b7c     RET        0x10
}

// Offset: 0x00445B80
void FillRect(TDrawArea* this_, long param_2, long param_3, long param_4, long param_5, uchar param_6) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TDrawArea::FillRect(long,long,long,long,unsigned char)                        *
    //                              *********************************************************************************************************
    //                              void __thiscall FillRect(TDrawArea * this, long param_1, long param_
    //              void              <VOID>         <RETURN>
    //              TDrawArea *       ECX:4 (auto)   this
    //              long              Stack[0x4]:4   param_1                   XREF[3]:     00445b94(R), 00445c07(W), 00445c54(R)  
    //              long              Stack[0x8]:4   param_2                   XREF[1]:     00445ba6(R)  
    //              long              Stack[0xc]:4   param_3                   XREF[1]:     00445b98(R)  
    //              long              Stack[0x10]:4  param_4                   XREF[1]:     00445baa(R)  
    //              uchar             Stack[0x14]:1  param_5                   XREF[1]:     00445c4a(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[3]:     00445b8a(W), 00445c1d(R), 00445c36(R)  
    //                               ?FillRect@TDrawArea@@QAEXJJJJE@Z                             XREF[19]:    draw_object:00438112(c), 
    //                               TDrawArea::FillRect                                                       draw_object:0043813c(c), 
    //                                                                                                         draw_object:0043814d(c), 
    //                                                                                                         draw_object:0043817a(c), 
    //                                                                                                         draw_object:00438191(c), 
    //                                                                                                         draw_object:004381c1(c), 
    //                                                                                                         LoadCursors:0045b4f4(c), 
    //                                                                                                         draw_background:0047d50d(c), 
    //                                                                                                         draw:0049b5dd(c), 
    //                                                                                                         draw_frame_3d_square_front:004c2db
    //                                                                                                         draw_frame_3d_square_front:004c2dd
    //                                                                                                         draw_frame:004c3c37(c), 
    //                                                                                                         draw_frame:004c3c5a(c), 
    //                                                                                                         draw_axis:0051fb22(c), 
    //                                                                                                         draw_axis:0051fb6c(c), 
    //                                                                                                         draw_axis:0051fbb8(c), 
    //                                                                                                         draw_axis:0051fc12(c), 
    //                                                                                                         draw_background:005201bf(c), 
    //                                                                                                         view_function_terrain:00538158(c)  
    //                              Drawarea.cpp:4040 (1)
    //         00445b80     PUSH       this
    //                              Drawarea.cpp:4045 (19)
    //         00445b81     MOV        EAX,dword ptr [ECX + this->Bits]
    //         00445b84     PUSH       EBX
    //         00445b85     PUSH       EBP
    //         00445b86     PUSH       ESI
    //         00445b87     TEST       EAX,EAX
    //         00445b89     PUSH       EDI
    //         00445b8a     MOV        dword ptr [ESP + local_4],EAX
    //         00445b8e     JZ         LAB_00445c68
    //                              Drawarea.cpp:4048 (12)
    //         00445b94     MOV        EDI,dword ptr [ESP + param_1]
    //         00445b98     MOV        ESI,dword ptr [ESP + param_3]
    //         00445b9c     CMP        EDI,ESI
    //         00445b9e     JLE        LAB_00445ba6
    //                              Drawarea.cpp:4050 (2)
    //         00445ba0     MOV        EAX,EDI
    //                              Drawarea.cpp:4051 (2)
    //         00445ba2     MOV        EDI,ESI
    //                              Drawarea.cpp:4052 (2)
    //         00445ba4     MOV        ESI,EAX
    //                               LAB_00445ba6                                                 XREF[1]:     00445b9e(j)  
    //                              Drawarea.cpp:4055 (12)
    //         00445ba6     MOV        EAX,dword ptr [ESP + param_2]
    //         00445baa     MOV        EDX,dword ptr [ESP + param_4]
    //         00445bae     CMP        EAX,EDX
    //         00445bb0     JLE        LAB_00445bb8
    //                              Drawarea.cpp:4057 (2)
    //         00445bb2     MOV        EBX,EAX
    //                              Drawarea.cpp:4058 (2)
    //         00445bb4     MOV        EAX,EDX
    //                              Drawarea.cpp:4059 (2)
    //         00445bb6     MOV        EDX,EBX
    //                               LAB_00445bb8                                                 XREF[1]:     00445bb0(j)  
    //                              Drawarea.cpp:4062 (40)
    //         00445bb8     CMP        EDI,dword ptr [ECX + this+0x30]
    //         00445bbb     JG         LAB_00445c68
    //         00445bc1     MOV        EBX,dword ptr [ECX + this->ClipRect.left]
    //         00445bc4     CMP        ESI,EBX
    //         00445bc6     JL         LAB_00445c68
    //         00445bcc     CMP        EAX,dword ptr [ECX + this+0x34]
    //         00445bcf     JG         LAB_00445c68
    //         00445bd5     MOV        EBP,dword ptr [ECX + this+0x2c]
    //         00445bd8     CMP        EDX,EBP
    //         00445bda     JL         LAB_00445c68
    //                              Drawarea.cpp:4065 (4)
    //         00445be0     CMP        EDI,EBX
    //         00445be2     JGE        LAB_00445be6
    //                              Drawarea.cpp:4066 (2)
    //         00445be4     MOV        EDI,EBX
    //                               LAB_00445be6                                                 XREF[1]:     00445be2(j)  
    //                              Drawarea.cpp:4068 (7)
    //         00445be6     MOV        EBX,dword ptr [ECX + this+0x30]
    //         00445be9     CMP        ESI,EBX
    //         00445beb     JLE        LAB_00445bef
    //                              Drawarea.cpp:4069 (2)
    //         00445bed     MOV        ESI,EBX
    //                               LAB_00445bef                                                 XREF[1]:     00445beb(j)  
    //                              Drawarea.cpp:4071 (4)
    //         00445bef     CMP        EAX,EBP
    //         00445bf1     JGE        LAB_00445bf5
    //                              Drawarea.cpp:4072 (2)
    //         00445bf3     MOV        EAX,EBP
    //                               LAB_00445bf5                                                 XREF[1]:     00445bf1(j)  
    //                              Drawarea.cpp:4074 (7)
    //         00445bf5     MOV        EBX,dword ptr [ECX + this+0x34]
    //         00445bf8     CMP        EDX,EBX
    //         00445bfa     JLE        LAB_00445bfe
    //                              Drawarea.cpp:4075 (2)
    //         00445bfc     MOV        EDX,EBX
    //                               LAB_00445bfe                                                 XREF[1]:     00445bfa(j)  
    //                              Drawarea.cpp:4077 (2)
    //         00445bfe     SUB        ESI,EDI
    //                              Drawarea.cpp:4078 (4)
    //         00445c00     SUB        EDX,EAX
    //         00445c02     INC        ESI
    //         00445c03     INC        EDX
    //                              Drawarea.cpp:4080 (16)
    //         00445c04     CMP        ESI,0x1
    //         00445c07     MOV        dword ptr [ESP + param_1],ESI
    //         00445c0b     MOV        EBP,EDX
    //         00445c0d     JL         LAB_00445c68
    //         00445c0f     CMP        EBP,0x1
    //         00445c12     JL         LAB_00445c68
    //                              Drawarea.cpp:4083 (6)
    //         00445c14     CMP        dword ptr [ECX + this->Orien],0x1
    //         00445c18     JNZ        LAB_00445c2e
    //                              Drawarea.cpp:4085 (12)
    //         00445c1a     MOV        this,dword ptr [ECX + this->Pitch]
    //         00445c1d     MOV        EDX,dword ptr [ESP + local_4]
    //         00445c21     IMUL       EAX,this
    //         00445c24     ADD        EAX,EDI
    //                              Drawarea.cpp:4086 (6)
    //         00445c26     MOV        EDI,this
    //         00445c28     ADD        EAX,EDX
    //         00445c2a     MOV        ESI,EAX
    //                              Drawarea.cpp:4088 (2)
    //         00445c2c     JMP        LAB_00445c46
    //                               LAB_00445c2e                                                 XREF[1]:     00445c18(j)  
    //                              Drawarea.cpp:4090 (20)
    //         00445c2e     MOV        ESI,dword ptr [ECX + this->Height]
    //         00445c31     MOV        EDX,dword ptr [ECX + this->Pitch]
    //         00445c34     SUB        ESI,EAX
    //         00445c36     MOV        this,dword ptr [ESP + local_4]
    //         00445c3a     DEC        ESI
    //         00445c3b     IMUL       ESI,EDX
    //         00445c3e     ADD        ESI,EDI
    //         00445c40     ADD        ESI,this
    //                              Drawarea.cpp:4091 (4)
    //         00445c42     NEG        EDX
    //         00445c44     MOV        EDI,EDX
    //                               LAB_00445c46                                                 XREF[1]:     00445c2c(j)  
    //                              Drawarea.cpp:4094 (4)
    //         00445c46     TEST       EBP,EBP
    //         00445c48     JLE        LAB_00445c68
    //                              Drawarea.cpp:4096 (25)
    //         00445c4a     MOV        EBX,dword ptr [ESP + param_5]
    //         00445c4e     AND        EBX,0xff
    //                               LAB_00445c54                                                 XREF[1]:     00445c66(j)  
    //         00445c54     MOV        EAX,dword ptr [ESP + param_1]
    //         00445c58     PUSH       EAX
    //         00445c59     PUSH       EBX
    //         00445c5a     PUSH       ESI
    //         00445c5b     CALL       memset                                           undefined memset()
    //         00445c60     ADD        ESP,0xc
    //                              Drawarea.cpp:4097 (5)
    //         00445c63     ADD        ESI,EDI
    //         00445c65     DEC        EBP
    //         00445c66     JNZ        LAB_00445c54
    //                               LAB_00445c68                                                 XREF[8]:     00445b8e(j), 00445bbb(j), 
    //                                                                                                         00445bc6(j), 00445bcf(j), 
    //                                                                                                         00445bda(j), 00445c0d(j), 
    //                                                                                                         00445c12(j), 00445c48(j)  
    //                              Drawarea.cpp:4099 (8)
    //         00445c68     POP        EDI
    //         00445c69     POP        ESI
    //         00445c6a     POP        EBP
    //         00445c6b     POP        EBX
    //         00445c6c     POP        this
    //         00445c6d     RET        0x14
}

// Offset: 0x00445C70
void DrawBevel(TDrawArea* this_, long param_2, long param_3, long param_4, long param_5, uchar param_6, uchar param_7) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TDrawArea::DrawBevel(long,long,long,long,unsigned char,unsigned char)         *
    //                              *********************************************************************************************************
    //                              void __thiscall DrawBevel(TDrawArea * this, long param_1, long param
    //              void              <VOID>         <RETURN>
    //              TDrawArea *       ECX:4 (auto)   this
    //              long              Stack[0x4]:4   param_1                   XREF[5]:     00445c78(R), 00445cb0(W), 00445ccb(R), 00445cd5(W), 
    //                                                                                     00445d01(R)  
    //              long              Stack[0x8]:4   param_2                   XREF[1]:     00445c8c(R)  
    //              long              Stack[0xc]:4   param_3                   XREF[3]:     00445c71(R), 00445c86(W), 00445cda(R)  
    //              long              Stack[0x10]:4  param_4                   XREF[3]:     00445c90(R), 00445c9c(W), 00445cee(R)  
    //              uchar             Stack[0x14]:1  param_5                   XREF[2]:     00445cb6(R), 00445ccf(R)  
    //              uchar             Stack[0x18]:1  param_6                   XREF[2]:     00445cea(R), 00445cfd(R)  
    //                               ?DrawBevel@TDrawArea@@QAEXJJJJEE@Z                           XREF[8]:     draw:0047303a(c), 
    //                               TDrawArea::DrawBevel                                                      draw:00476828(c), 
    //                                                                                                         draw_highlight_bar:00478dc8(c), 
    //                                                                                                         draw_highlight_bar:00478e3f(c), 
    //                                                                                                         draw_border:0047b714(c), 
    //                                                                                                         draw_border:0047b810(c), 
    //                                                                                                         draw_border:0047d67d(c), 
    //                                                                                                         draw_border:0051f22d(c)  
    //                              Drawarea.cpp:4105 (1)
    //         00445c70     PUSH       EBX
    //                              Drawarea.cpp:4109 (17)
    //         00445c71     MOV        EBX,dword ptr [ESP + param_3]
    //         00445c75     PUSH       EBP
    //         00445c76     PUSH       ESI
    //         00445c77     PUSH       EDI
    //         00445c78     MOV        EDI,dword ptr [ESP + param_1]
    //         00445c7c     CMP        EDI,EBX
    //         00445c7e     MOV        EBP,this
    //         00445c80     JLE        LAB_00445c8c
    //                              Drawarea.cpp:4111 (2)
    //         00445c82     MOV        EAX,EDI
    //                              Drawarea.cpp:4112 (2)
    //         00445c84     MOV        EDI,EBX
    //                              Drawarea.cpp:4113 (6)
    //         00445c86     MOV        dword ptr [ESP + param_3],EAX
    //         00445c8a     MOV        EBX,EAX
    //                               LAB_00445c8c                                                 XREF[1]:     00445c80(j)  
    //                              Drawarea.cpp:4116 (12)
    //         00445c8c     MOV        ESI,dword ptr [ESP + param_2]
    //         00445c90     MOV        EAX,dword ptr [ESP + param_4]
    //         00445c94     CMP        ESI,EAX
    //         00445c96     JLE        LAB_00445ca2
    //                              Drawarea.cpp:4118 (2)
    //         00445c98     MOV        this,ESI
    //                              Drawarea.cpp:4119 (2)
    //         00445c9a     MOV        ESI,EAX
    //                              Drawarea.cpp:4120 (6)
    //         00445c9c     MOV        dword ptr [ESP + param_4],this
    //         00445ca0     MOV        EAX,this
    //                               LAB_00445ca2                                                 XREF[1]:     00445c96(j)  
    //                              Drawarea.cpp:4123 (3)
    //         00445ca2     SUB        EBX,EDI
    //         00445ca4     INC        EBX
    //                              Drawarea.cpp:4124 (5)
    //         00445ca5     CMP        EBX,0x1
    //         00445ca8     JL         LAB_00445d10
    //                              Drawarea.cpp:4127 (3)
    //         00445caa     SUB        EAX,ESI
    //         00445cac     INC        EAX
    //                              Drawarea.cpp:4128 (9)
    //         00445cad     CMP        EAX,0x1
    //         00445cb0     MOV        dword ptr [ESP + param_1],EAX
    //         00445cb4     JL         LAB_00445d10
    //                              Drawarea.cpp:4132 (21)
    //         00445cb6     MOV        EAX,dword ptr [ESP + param_5]
    //         00445cba     LEA        this,[EBX + -0x1]
    //         00445cbd     PUSH       EAX
    //         00445cbe     PUSH       this
    //         00445cbf     LEA        EDX,[EDI + 0x1]
    //         00445cc2     PUSH       ESI
    //         00445cc3     PUSH       EDX
    //         00445cc4     MOV        this,EBP
    //         00445cc6     CALL       TDrawArea::DrawHorzLine                          void DrawHorzLine(TDrawArea * this, long para
    //                              Drawarea.cpp:4133 (31)
    //         00445ccb     MOV        EAX,dword ptr [ESP + param_1]
    //         00445ccf     MOV        this,dword ptr [ESP + param_5]
    //         00445cd3     DEC        EAX
    //         00445cd4     PUSH       this
    //         00445cd5     MOV        dword ptr [ESP + param_1],EAX
    //         00445cd9     PUSH       EAX
    //         00445cda     MOV        EAX,dword ptr [ESP + param_3]
    //         00445cde     LEA        EDX,[ESI + 0x1]
    //         00445ce1     PUSH       EDX
    //         00445ce2     PUSH       EAX
    //         00445ce3     MOV        this,EBP
    //         00445ce5     CALL       TDrawArea::DrawVertLine                          void DrawVertLine(TDrawArea * this, long para
    //                              Drawarea.cpp:4136 (19)
    //         00445cea     MOV        this,dword ptr [ESP + param_6]
    //         00445cee     MOV        EDX,dword ptr [ESP + param_4]
    //         00445cf2     PUSH       this
    //         00445cf3     PUSH       EBX
    //         00445cf4     PUSH       EDX
    //         00445cf5     PUSH       EDI
    //         00445cf6     MOV        this,EBP
    //         00445cf8     CALL       TDrawArea::DrawHorzLine                          void DrawHorzLine(TDrawArea * this, long para
    //                              Drawarea.cpp:4137 (19)
    //         00445cfd     MOV        EAX,dword ptr [ESP + param_6]
    //         00445d01     MOV        this,dword ptr [ESP + param_1]
    //         00445d05     PUSH       EAX
    //         00445d06     PUSH       this
    //         00445d07     PUSH       ESI
    //         00445d08     PUSH       EDI
    //         00445d09     MOV        this,EBP
    //         00445d0b     CALL       TDrawArea::DrawVertLine                          void DrawVertLine(TDrawArea * this, long para
    //                               LAB_00445d10                                                 XREF[2]:     00445ca8(j), 00445cb4(j)  
    //                              Drawarea.cpp:4138 (7)
    //         00445d10     POP        EDI
    //         00445d11     POP        ESI
    //         00445d12     POP        EBP
    //         00445d13     POP        EBX
    //         00445d14     RET        0x18
}

// Offset: 0x00445D20
void DrawBevel2(TDrawArea* this_, long param_2, long param_3, long param_4, long param_5, uchar param_6, uchar param_7, uchar param_8, uchar param_9) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TDrawArea::DrawBevel2(long,long,long,long,unsigned char,unsigned char,unsi... *
    //                              *********************************************************************************************************
    //                              void __thiscall DrawBevel2(TDrawArea * this, long param_1, long para
    //              void              <VOID>         <RETURN>
    //              TDrawArea *       ECX:4 (auto)   this
    //              long              Stack[0x4]:4   param_1                   XREF[6]:     00445d21(R), 00445d33(W), 00445d3d(R), 00445dac(R), 
    //                                                                                     00445de2(R), 00445df5(R)  
    //              long              Stack[0x8]:4   param_2                   XREF[4]:     00445d41(R), 00445d92(W), 00445da7(R), 00445e22(R)  
    //              long              Stack[0xc]:4   param_3                   XREF[4]:     00445d26(R), 00445d37(W), 00445d97(R), 00445dc8(R)  
    //              long              Stack[0x10]:4  param_4                   XREF[4]:     00445d45(R), 00445d51(W), 00445dde(R), 00445e0b(R)  
    //              uchar             Stack[0x14]:1  param_5                   XREF[2]:     00445d6f(R), 00445d86(R)  
    //              uchar             Stack[0x18]:1  param_6                   XREF[2]:     00445da3(R), 00445dc0(R)  
    //              uchar             Stack[0x1c]:1  param_7                   XREF[1]:     00445e07(R)  
    //              uchar             Stack[0x20]:1  param_8                   XREF[2]:     00445dda(R), 00445df1(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     00445d7d(W), 00445e14(R)  
    //                               ?DrawBevel2@TDrawArea@@QAEXJJJJEEEE@Z                        XREF[8]:     draw:0047307b(c), 
    //                               TDrawArea::DrawBevel2                                                     draw:00476869(c), 
    //                                                                                                         draw_highlight_bar:00478df5(c), 
    //                                                                                                         draw_highlight_bar:00478e69(c), 
    //                                                                                                         draw_border:0047b743(c), 
    //                                                                                                         draw_border:0047b83f(c), 
    //                                                                                                         draw_border:0047d6c8(c), 
    //                                                                                                         draw_border:0051f278(c)  
    //                              Drawarea.cpp:4144 (1)
    //         00445d20     PUSH       this
    //                              Drawarea.cpp:4148 (18)
    //         00445d21     MOV        EAX,dword ptr [ESP + param_1]
    //         00445d25     PUSH       EBX
    //         00445d26     MOV        EBX,dword ptr [ESP + param_3]
    //         00445d2a     PUSH       EBP
    //         00445d2b     PUSH       ESI
    //         00445d2c     CMP        EAX,EBX
    //         00445d2e     PUSH       EDI
    //         00445d2f     MOV        ESI,this
    //         00445d31     JLE        LAB_00445d41
    //                              Drawarea.cpp:4151 (4)
    //         00445d33     MOV        dword ptr [ESP + param_1],EBX
    //                              Drawarea.cpp:4152 (10)
    //         00445d37     MOV        dword ptr [ESP + param_3],EAX
    //         00445d3b     MOV        EBX,EAX
    //         00445d3d     MOV        EAX,dword ptr [ESP + param_1]
    //                               LAB_00445d41                                                 XREF[1]:     00445d31(j)  
    //                              Drawarea.cpp:4155 (12)
    //         00445d41     MOV        EBP,dword ptr [ESP + param_2]
    //         00445d45     MOV        EDI,dword ptr [ESP + param_4]
    //         00445d49     CMP        EBP,EDI
    //         00445d4b     JLE        LAB_00445d57
    //                              Drawarea.cpp:4157 (2)
    //         00445d4d     MOV        this,EBP
    //                              Drawarea.cpp:4158 (2)
    //         00445d4f     MOV        EBP,EDI
    //                              Drawarea.cpp:4159 (6)
    //         00445d51     MOV        dword ptr [ESP + param_4],this
    //         00445d55     MOV        EDI,this
    //                               LAB_00445d57                                                 XREF[1]:     00445d4b(j)  
    //                              Drawarea.cpp:4162 (3)
    //         00445d57     SUB        EBX,EAX
    //         00445d59     INC        EBX
    //                              Drawarea.cpp:4163 (9)
    //         00445d5a     CMP        EBX,0x1
    //         00445d5d     JL         LAB_00445e34
    //                              Drawarea.cpp:4166 (3)
    //         00445d63     SUB        EDI,EBP
    //         00445d65     INC        EDI
    //                              Drawarea.cpp:4167 (9)
    //         00445d66     CMP        EDI,0x1
    //         00445d69     JL         LAB_00445e34
    //                              Drawarea.cpp:4171 (23)
    //         00445d6f     MOV        this,dword ptr [ESP + param_5]
    //         00445d73     LEA        EDX,[EBX + -0x1]
    //         00445d76     PUSH       this
    //         00445d77     INC        EAX
    //         00445d78     PUSH       EDX
    //         00445d79     PUSH       EBP
    //         00445d7a     PUSH       EAX
    //         00445d7b     MOV        this,ESI
    //         00445d7d     MOV        dword ptr [ESP + local_4],EAX
    //         00445d81     CALL       TDrawArea::DrawHorzLine                          void DrawHorzLine(TDrawArea * this, long para
    //                              Drawarea.cpp:4172 (29)
    //         00445d86     MOV        this,dword ptr [ESP + param_5]
    //         00445d8a     LEA        EDX,[EDI + -0x2]
    //         00445d8d     LEA        EAX,[EBP + 0x1]
    //         00445d90     PUSH       this
    //         00445d91     PUSH       EDX
    //         00445d92     MOV        dword ptr [ESP + param_2],EAX
    //         00445d96     PUSH       EAX
    //         00445d97     MOV        EAX,dword ptr [ESP + param_3]
    //         00445d9b     PUSH       EAX
    //         00445d9c     MOV        this,ESI
    //         00445d9e     CALL       TDrawArea::DrawVertLine                          void DrawVertLine(TDrawArea * this, long para
    //                              Drawarea.cpp:4175 (29)
    //         00445da3     MOV        this,dword ptr [ESP + param_6]
    //         00445da7     MOV        EAX,dword ptr [ESP + param_2]
    //         00445dab     PUSH       this
    //         00445dac     MOV        this,dword ptr [ESP + param_1]
    //         00445db0     LEA        EDX,[EBX + -0x3]
    //         00445db3     ADD        this,0x2
    //         00445db6     PUSH       EDX
    //         00445db7     PUSH       EAX
    //         00445db8     PUSH       this
    //         00445db9     MOV        this,ESI
    //         00445dbb     CALL       TDrawArea::DrawHorzLine                          void DrawHorzLine(TDrawArea * this, long para
    //                              Drawarea.cpp:4176 (26)
    //         00445dc0     MOV        EDX,dword ptr [ESP + param_6]
    //         00445dc4     LEA        EAX,[EDI + -0x4]
    //         00445dc7     PUSH       EDX
    //         00445dc8     MOV        EDX,dword ptr [ESP + param_3]
    //         00445dcc     LEA        this,[EBP + 0x2]
    //         00445dcf     PUSH       EAX
    //         00445dd0     DEC        EDX
    //         00445dd1     PUSH       this
    //         00445dd2     PUSH       EDX
    //         00445dd3     MOV        this,ESI
    //         00445dd5     CALL       TDrawArea::DrawVertLine                          void DrawVertLine(TDrawArea * this, long para
    //                              Drawarea.cpp:4179 (23)
    //         00445dda     MOV        EAX,dword ptr [ESP + param_8]
    //         00445dde     MOV        this,dword ptr [ESP + param_4]
    //         00445de2     MOV        EDX,dword ptr [ESP + param_1]
    //         00445de6     PUSH       EAX
    //         00445de7     PUSH       EBX
    //         00445de8     PUSH       this
    //         00445de9     PUSH       EDX
    //         00445dea     MOV        this,ESI
    //         00445dec     CALL       TDrawArea::DrawHorzLine                          void DrawHorzLine(TDrawArea * this, long para
    //                              Drawarea.cpp:4180 (22)
    //         00445df1     MOV        EAX,dword ptr [ESP + param_8]
    //         00445df5     MOV        EDX,dword ptr [ESP + param_1]
    //         00445df9     LEA        this,[EDI + -0x1]
    //         00445dfc     PUSH       EAX
    //         00445dfd     PUSH       this
    //         00445dfe     PUSH       EBP
    //         00445dff     PUSH       EDX
    //         00445e00     MOV        this,ESI
    //         00445e02     CALL       TDrawArea::DrawVertLine                          void DrawVertLine(TDrawArea * this, long para
    //                              Drawarea.cpp:4183 (27)
    //         00445e07     MOV        EBP,dword ptr [ESP + param_7]
    //         00445e0b     MOV        EAX,dword ptr [ESP + param_4]
    //         00445e0f     ADD        EBX,-0x2
    //         00445e12     PUSH       EBP
    //         00445e13     PUSH       EBX
    //         00445e14     MOV        EBX,dword ptr [ESP + local_4]
    //         00445e18     DEC        EAX
    //         00445e19     MOV        this,ESI
    //         00445e1b     PUSH       EAX
    //         00445e1c     PUSH       EBX
    //         00445e1d     CALL       TDrawArea::DrawHorzLine                          void DrawHorzLine(TDrawArea * this, long para
    //                              Drawarea.cpp:4184 (18)
    //         00445e22     MOV        this,dword ptr [ESP + param_2]
    //         00445e26     ADD        EDI,-0x3
    //         00445e29     PUSH       EBP
    //         00445e2a     PUSH       EDI
    //         00445e2b     PUSH       this
    //         00445e2c     PUSH       EBX
    //         00445e2d     MOV        this,ESI
    //         00445e2f     CALL       TDrawArea::DrawVertLine                          void DrawVertLine(TDrawArea * this, long para
    //                               LAB_00445e34                                                 XREF[2]:     00445d5d(j), 00445d69(j)  
    //                              Drawarea.cpp:4185 (8)
    //         00445e34     POP        EDI
    //         00445e35     POP        ESI
    //         00445e36     POP        EBP
    //         00445e37     POP        EBX
    //         00445e38     POP        this
    //         00445e39     RET        0x20
}

// Offset: 0x00445E40
void DrawBevel3(TDrawArea* this_, long param_2, long param_3, long param_4, long param_5, uchar param_6, uchar param_7, uchar param_8, uchar param_9, uchar param_10, uchar param_11) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TDrawArea::DrawBevel3(long,long,long,long,unsigned char,unsigned char,unsi... *
    //                              *********************************************************************************************************
    //                              void __thiscall DrawBevel3(TDrawArea * this, long param_1, long para
    //              void              <VOID>         <RETURN>
    //              TDrawArea *       ECX:4 (auto)   this
    //              long              Stack[0x4]:4   param_1                   XREF[7]:     00445e40(R), 00445e55(W), 00445e5f(R), 00445ec5(R), 
    //                                                                                     00445f0d(R), 00445f45(R), 00445f5e(R)  
    //              long              Stack[0x8]:4   param_2                   XREF[4]:     00445e63(R), 00445eb4(W), 00445ece(R), 00445f85(R)  
    //              long              Stack[0xc]:4   param_3                   XREF[5]:     00445e48(R), 00445e59(W), 00445eb9(R), 00445ef7(R), 
    //                                                                                     00445f29(R)  
    //              long              Stack[0x10]:4  param_4                   XREF[5]:     00445e67(R), 00445e73(W), 00445f41(R), 00445f6e(R), 
    //                                                                                     00445f9f(R)  
    //              uchar             Stack[0x14]:1  param_5                   XREF[5]:     00445e91(R), 00445ea8(R), 00445ef2(W), 00445f08(R), 
    //                                                                                     00445fb8(R)  
    //              uchar             Stack[0x18]:1  param_6                   XREF[2]:     00445ec9(R), 00445ee6(R)  
    //              uchar             Stack[0x1c]:1  param_7                   XREF[2]:     00445f04(R), 00445f21(R)  
    //              uchar             Stack[0x20]:1  param_8                   XREF[1]:     00445f9b(R)  
    //              uchar             Stack[0x24]:1  param_9                   XREF[1]:     00445f6a(R)  
    //              uchar             Stack[0x28]:1  param_10                  XREF[2]:     00445f3d(R), 00445f54(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     00445edd(W), 00445fa8(R)  
    //              undefined4        Stack[-0x8]:4  local_8                   XREF[3]:     00445e9f(W), 00445f72(R), 00445f89(R)  
    //                               ?DrawBevel3@TDrawArea@@QAEXJJJJEEEEEE@Z                      XREF[10]:    draw_background:0046796e(c), 
    //                               TDrawArea::DrawBevel3                                                     draw:004730c7(c), 
    //                                                                                                         draw:004768b5(c), 
    //                                                                                                         draw_highlight_bar:00478ea1(c), 
    //                                                                                                         draw_border:0047b780(c), 
    //                                                                                                         draw_border:0047b87c(c), 
    //                                                                                                         draw_border:0047d721(c), 
    //                                                                                                         draw:004ad1d4(c), 
    //                                                                                                         draw:004ad214(c), 
    //                                                                                                         draw_border:0051f2d1(c)  
    //                              Drawarea.cpp:4191 (21)
    //         00445e40     MOV        EAX,dword ptr [ESP + param_1]
    //         00445e44     SUB        ESP,0x8
    //         00445e47     PUSH       EBX
    //         00445e48     MOV        EBX,dword ptr [ESP + param_3]
    //         00445e4c     PUSH       EBP
    //         00445e4d     PUSH       ESI
    //         00445e4e     CMP        EAX,EBX
    //         00445e50     PUSH       EDI
    //         00445e51     MOV        ESI,this
    //         00445e53     JLE        LAB_00445e63
    //                              Drawarea.cpp:4198 (4)
    //         00445e55     MOV        dword ptr [ESP + param_1],EBX
    //                              Drawarea.cpp:4199 (10)
    //         00445e59     MOV        dword ptr [ESP + param_3],EAX
    //         00445e5d     MOV        EBX,EAX
    //         00445e5f     MOV        EAX,dword ptr [ESP + param_1]
    //                               LAB_00445e63                                                 XREF[1]:     00445e53(j)  
    //                              Drawarea.cpp:4202 (12)
    //         00445e63     MOV        EBP,dword ptr [ESP + param_2]
    //         00445e67     MOV        EDI,dword ptr [ESP + param_4]
    //         00445e6b     CMP        EBP,EDI
    //         00445e6d     JLE        LAB_00445e79
    //                              Drawarea.cpp:4204 (2)
    //         00445e6f     MOV        this,EBP
    //                              Drawarea.cpp:4205 (2)
    //         00445e71     MOV        EBP,EDI
    //                              Drawarea.cpp:4206 (6)
    //         00445e73     MOV        dword ptr [ESP + param_4],this
    //         00445e77     MOV        EDI,this
    //                               LAB_00445e79                                                 XREF[1]:     00445e6d(j)  
    //                              Drawarea.cpp:4209 (3)
    //         00445e79     SUB        EBX,EAX
    //         00445e7b     INC        EBX
    //                              Drawarea.cpp:4210 (9)
    //         00445e7c     CMP        EBX,0x1
    //         00445e7f     JL         LAB_00445fca
    //                              Drawarea.cpp:4213 (3)
    //         00445e85     SUB        EDI,EBP
    //         00445e87     INC        EDI
    //                              Drawarea.cpp:4214 (9)
    //         00445e88     CMP        EDI,0x1
    //         00445e8b     JL         LAB_00445fca
    //                              Drawarea.cpp:4218 (23)
    //         00445e91     MOV        this,dword ptr [ESP + param_5]
    //         00445e95     LEA        EDX,[EBX + -0x1]
    //         00445e98     PUSH       this
    //         00445e99     INC        EAX
    //         00445e9a     PUSH       EDX
    //         00445e9b     PUSH       EBP
    //         00445e9c     PUSH       EAX
    //         00445e9d     MOV        this,ESI
    //         00445e9f     MOV        dword ptr [ESP + local_8],EAX
    //         00445ea3     CALL       TDrawArea::DrawHorzLine                          void DrawHorzLine(TDrawArea * this, long para
    //                              Drawarea.cpp:4219 (29)
    //         00445ea8     MOV        this,dword ptr [ESP + param_5]
    //         00445eac     LEA        EDX,[EDI + -0x2]
    //         00445eaf     LEA        EAX,[EBP + 0x1]
    //         00445eb2     PUSH       this
    //         00445eb3     PUSH       EDX
    //         00445eb4     MOV        dword ptr [ESP + param_2],EAX
    //         00445eb8     PUSH       EAX
    //         00445eb9     MOV        EAX,dword ptr [ESP + param_3]
    //         00445ebd     PUSH       EAX
    //         00445ebe     MOV        this,ESI
    //         00445ec0     CALL       TDrawArea::DrawVertLine                          void DrawVertLine(TDrawArea * this, long para
    //                              Drawarea.cpp:4222 (33)
    //         00445ec5     MOV        this,dword ptr [ESP + param_1]
    //         00445ec9     MOV        EDX,dword ptr [ESP + param_6]
    //         00445ecd     PUSH       EDX
    //         00445ece     MOV        EDX,dword ptr [ESP + param_2]
    //         00445ed2     LEA        EAX,[ECX + this+0x2]
    //         00445ed5     LEA        this,[EBX + -0x3]
    //         00445ed8     PUSH       this
    //         00445ed9     PUSH       EDX
    //         00445eda     PUSH       EAX
    //         00445edb     MOV        this,ESI
    //         00445edd     MOV        dword ptr [ESP + local_4],EAX
    //         00445ee1     CALL       TDrawArea::DrawHorzLine                          void DrawHorzLine(TDrawArea * this, long para
    //                              Drawarea.cpp:4223 (30)
    //         00445ee6     MOV        this,dword ptr [ESP + param_6]
    //         00445eea     LEA        EDX,[EDI + -0x4]
    //         00445eed     LEA        EAX,[EBP + 0x2]
    //         00445ef0     PUSH       this
    //         00445ef1     PUSH       EDX
    //         00445ef2     MOV        dword ptr [ESP + param_5],EAX
    //         00445ef6     PUSH       EAX
    //         00445ef7     MOV        EAX,dword ptr [ESP + param_3]
    //         00445efb     DEC        EAX
    //         00445efc     MOV        this,ESI
    //         00445efe     PUSH       EAX
    //         00445eff     CALL       TDrawArea::DrawVertLine                          void DrawVertLine(TDrawArea * this, long para
    //                              Drawarea.cpp:4226 (29)
    //         00445f04     MOV        this,dword ptr [ESP + param_7]
    //         00445f08     MOV        EAX,dword ptr [ESP + param_5]
    //         00445f0c     PUSH       this
    //         00445f0d     MOV        this,dword ptr [ESP + param_1]
    //         00445f11     LEA        EDX,[EBX + -0x5]
    //         00445f14     ADD        this,0x3
    //         00445f17     PUSH       EDX
    //         00445f18     PUSH       EAX
    //         00445f19     PUSH       this
    //         00445f1a     MOV        this,ESI
    //         00445f1c     CALL       TDrawArea::DrawHorzLine                          void DrawHorzLine(TDrawArea * this, long para
    //                              Drawarea.cpp:4227 (28)
    //         00445f21     MOV        EDX,dword ptr [ESP + param_7]
    //         00445f25     LEA        EAX,[EDI + -0x6]
    //         00445f28     PUSH       EDX
    //         00445f29     MOV        EDX,dword ptr [ESP + param_3]
    //         00445f2d     LEA        this,[EBP + 0x3]
    //         00445f30     PUSH       EAX
    //         00445f31     ADD        EDX,-0x2
    //         00445f34     PUSH       this
    //         00445f35     PUSH       EDX
    //         00445f36     MOV        this,ESI
    //         00445f38     CALL       TDrawArea::DrawVertLine                          void DrawVertLine(TDrawArea * this, long para
    //                              Drawarea.cpp:4230 (23)
    //         00445f3d     MOV        EAX,dword ptr [ESP + param_10]
    //         00445f41     MOV        this,dword ptr [ESP + param_4]
    //         00445f45     MOV        EDX,dword ptr [ESP + param_1]
    //         00445f49     PUSH       EAX
    //         00445f4a     PUSH       EBX
    //         00445f4b     PUSH       this
    //         00445f4c     PUSH       EDX
    //         00445f4d     MOV        this,ESI
    //         00445f4f     CALL       TDrawArea::DrawHorzLine                          void DrawHorzLine(TDrawArea * this, long para
    //                              Drawarea.cpp:4231 (22)
    //         00445f54     MOV        EAX,dword ptr [ESP + param_10]
    //         00445f58     LEA        this,[EDI + -0x1]
    //         00445f5b     PUSH       EAX
    //         00445f5c     PUSH       this
    //         00445f5d     PUSH       EBP
    //         00445f5e     MOV        EDX,dword ptr [ESP + param_1]
    //         00445f62     MOV        this,ESI
    //         00445f64     PUSH       EDX
    //         00445f65     CALL       TDrawArea::DrawVertLine                          void DrawVertLine(TDrawArea * this, long para
    //                              Drawarea.cpp:4234 (27)
    //         00445f6a     MOV        EBP,dword ptr [ESP + param_9]
    //         00445f6e     MOV        this,dword ptr [ESP + param_4]
    //         00445f72     MOV        EDX,dword ptr [ESP + local_8]
    //         00445f76     LEA        EAX,[EBX + -0x2]
    //         00445f79     PUSH       EBP
    //         00445f7a     DEC        this
    //         00445f7b     PUSH       EAX
    //         00445f7c     PUSH       this
    //         00445f7d     PUSH       EDX
    //         00445f7e     MOV        this,ESI
    //         00445f80     CALL       TDrawArea::DrawHorzLine                          void DrawHorzLine(TDrawArea * this, long para
    //                              Drawarea.cpp:4235 (22)
    //         00445f85     MOV        this,dword ptr [ESP + param_2]
    //         00445f89     MOV        EDX,dword ptr [ESP + local_8]
    //         00445f8d     LEA        EAX,[EDI + -0x3]
    //         00445f90     PUSH       EBP
    //         00445f91     PUSH       EAX
    //         00445f92     PUSH       this
    //         00445f93     PUSH       EDX
    //         00445f94     MOV        this,ESI
    //         00445f96     CALL       TDrawArea::DrawVertLine                          void DrawVertLine(TDrawArea * this, long para
    //                              Drawarea.cpp:4238 (29)
    //         00445f9b     MOV        EBP,dword ptr [ESP + param_8]
    //         00445f9f     MOV        EAX,dword ptr [ESP + param_4]
    //         00445fa3     ADD        EBX,-0x4
    //         00445fa6     PUSH       EBP
    //         00445fa7     PUSH       EBX
    //         00445fa8     MOV        EBX,dword ptr [ESP + local_4]
    //         00445fac     ADD        EAX,-0x2
    //         00445faf     MOV        this,ESI
    //         00445fb1     PUSH       EAX
    //         00445fb2     PUSH       EBX
    //         00445fb3     CALL       TDrawArea::DrawHorzLine                          void DrawHorzLine(TDrawArea * this, long para
    //                              Drawarea.cpp:4239 (18)
    //         00445fb8     MOV        this,dword ptr [ESP + param_5]
    //         00445fbc     ADD        EDI,-0x5
    //         00445fbf     PUSH       EBP
    //         00445fc0     PUSH       EDI
    //         00445fc1     PUSH       this
    //         00445fc2     PUSH       EBX
    //         00445fc3     MOV        this,ESI
    //         00445fc5     CALL       TDrawArea::DrawVertLine                          void DrawVertLine(TDrawArea * this, long para
    //                               LAB_00445fca                                                 XREF[2]:     00445e7f(j), 00445e8b(j)  
    //                              Drawarea.cpp:4240 (10)
    //         00445fca     POP        EDI
    //         00445fcb     POP        ESI
    //         00445fcc     POP        EBP
    //         00445fcd     POP        EBX
    //         00445fce     ADD        ESP,0x8
    //         00445fd1     RET        0x28
}

// Offset: 0x00445FE0
void DrawBevel21(TDrawArea* this_, long param_2, long param_3, long param_4, long param_5, uchar param_6, uchar param_7, uchar param_8, uchar param_9) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TDrawArea::DrawBevel21(long,long,long,long,unsigned char,unsigned char,uns... *
    //                              *********************************************************************************************************
    //                              void __thiscall DrawBevel21(TDrawArea * this, long param_1, long par
    //              void              <VOID>         <RETURN>
    //              TDrawArea *       ECX:4 (auto)   this
    //              long              Stack[0x4]:4   param_1                   XREF[4]:     00445fe0(R), 00445ff2(W), 00445ffc(R), 0044609b(R)  
    //              long              Stack[0x8]:4   param_2                   XREF[3]:     00446000(R), 0044603c(W), 0044606b(R)  
    //              long              Stack[0xc]:4   param_3                   XREF[4]:     00445fe6(R), 00445ff6(W), 00446052(R), 0044607f(R)  
    //              long              Stack[0x10]:4  param_4                   XREF[3]:     00446004(R), 00446010(W), 00446095(R)  
    //              uchar             Stack[0x14]:1  param_5                   XREF[2]:     0044602e(R), 00446045(R)  
    //              uchar             Stack[0x18]:1  param_6                   XREF[2]:     0044605e(R), 00446077(R)  
    //              uchar             Stack[0x1c]:1  param_7
    //              uchar             Stack[0x20]:1  param_8                   XREF[2]:     00446091(R), 004460a8(R)  
    //                               ?DrawBevel21@TDrawArea@@QAEXJJJJEEEE@Z                       XREF[1]:     draw:00472f39(c)  
    //                               TDrawArea::DrawBevel21
    //                              Drawarea.cpp:4246 (18)
    //         00445fe0     MOV        EAX,dword ptr [ESP + param_1]
    //         00445fe4     PUSH       EBX
    //         00445fe5     PUSH       EBP
    //         00445fe6     MOV        EBP,dword ptr [ESP + param_3]
    //         00445fea     PUSH       ESI
    //         00445feb     CMP        EAX,EBP
    //         00445fed     PUSH       EDI
    //         00445fee     MOV        ESI,this
    //         00445ff0     JLE        LAB_00446000
    //                              Drawarea.cpp:4253 (4)
    //         00445ff2     MOV        dword ptr [ESP + param_1],EBP
    //                              Drawarea.cpp:4254 (10)
    //         00445ff6     MOV        dword ptr [ESP + param_3],EAX
    //         00445ffa     MOV        EBP,EAX
    //         00445ffc     MOV        EAX,dword ptr [ESP + param_1]
    //                               LAB_00446000                                                 XREF[1]:     00445ff0(j)  
    //                              Drawarea.cpp:4257 (12)
    //         00446000     MOV        EDI,dword ptr [ESP + param_2]
    //         00446004     MOV        EBX,dword ptr [ESP + param_4]
    //         00446008     CMP        EDI,EBX
    //         0044600a     JLE        LAB_00446016
    //                              Drawarea.cpp:4259 (2)
    //         0044600c     MOV        this,EDI
    //                              Drawarea.cpp:4260 (2)
    //         0044600e     MOV        EDI,EBX
    //                              Drawarea.cpp:4261 (6)
    //         00446010     MOV        dword ptr [ESP + param_4],this
    //         00446014     MOV        EBX,this
    //                               LAB_00446016                                                 XREF[1]:     0044600a(j)  
    //                              Drawarea.cpp:4264 (3)
    //         00446016     SUB        EBP,EAX
    //         00446018     INC        EBP
    //                              Drawarea.cpp:4265 (9)
    //         00446019     CMP        EBP,0x1
    //         0044601c     JL         LAB_004460b8
    //                              Drawarea.cpp:4268 (3)
    //         00446022     SUB        EBX,EDI
    //         00446024     INC        EBX
    //                              Drawarea.cpp:4269 (9)
    //         00446025     CMP        EBX,0x1
    //         00446028     JL         LAB_004460b8
    //                              Drawarea.cpp:4273 (23)
    //         0044602e     MOV        this,dword ptr [ESP + param_5]
    //         00446032     LEA        EDX,[EBP + -0x1]
    //         00446035     PUSH       this
    //         00446036     INC        EAX
    //         00446037     PUSH       EDX
    //         00446038     PUSH       EDI
    //         00446039     PUSH       EAX
    //         0044603a     MOV        this,ESI
    //         0044603c     MOV        dword ptr [ESP + param_2],EAX
    //         00446040     CALL       TDrawArea::DrawHorzLine                          void DrawHorzLine(TDrawArea * this, long para
    //                              Drawarea.cpp:4274 (25)
    //         00446045     MOV        this,dword ptr [ESP + param_5]
    //         00446049     LEA        EDX,[EBX + -0x2]
    //         0044604c     LEA        EAX,[EDI + 0x1]
    //         0044604f     PUSH       this
    //         00446050     PUSH       EDX
    //         00446051     PUSH       EAX
    //         00446052     MOV        EAX,dword ptr [ESP + param_3]
    //         00446056     MOV        this,ESI
    //         00446058     PUSH       EAX
    //         00446059     CALL       TDrawArea::DrawVertLine                          void DrawVertLine(TDrawArea * this, long para
    //                              Drawarea.cpp:4277 (25)
    //         0044605e     MOV        this,dword ptr [ESP + param_6]
    //         00446062     LEA        EDX,[EBP + -0x2]
    //         00446065     PUSH       this
    //         00446066     LEA        EAX,[EDI + 0x1]
    //         00446069     PUSH       EDX
    //         0044606a     PUSH       EAX
    //         0044606b     MOV        EAX,dword ptr [ESP + param_2]
    //         0044606f     MOV        this,ESI
    //         00446071     PUSH       EAX
    //         00446072     CALL       TDrawArea::DrawHorzLine                          void DrawHorzLine(TDrawArea * this, long para
    //                              Drawarea.cpp:4278 (26)
    //         00446077     MOV        this,dword ptr [ESP + param_6]
    //         0044607b     LEA        EDX,[EBX + -0x3]
    //         0044607e     PUSH       this
    //         0044607f     MOV        this,dword ptr [ESP + param_3]
    //         00446083     LEA        EAX,[EDI + 0x2]
    //         00446086     PUSH       EDX
    //         00446087     DEC        this
    //         00446088     PUSH       EAX
    //         00446089     PUSH       this
    //         0044608a     MOV        this,ESI
    //         0044608c     CALL       TDrawArea::DrawVertLine                          void DrawVertLine(TDrawArea * this, long para
    //                              Drawarea.cpp:4281 (23)
    //         00446091     MOV        EDX,dword ptr [ESP + param_8]
    //         00446095     MOV        EAX,dword ptr [ESP + param_4]
    //         00446099     PUSH       EDX
    //         0044609a     PUSH       EBP
    //         0044609b     MOV        EBP,dword ptr [ESP + param_1]
    //         0044609f     PUSH       EAX
    //         004460a0     PUSH       EBP
    //         004460a1     MOV        this,ESI
    //         004460a3     CALL       TDrawArea::DrawHorzLine                          void DrawHorzLine(TDrawArea * this, long para
    //                              Drawarea.cpp:4282 (16)
    //         004460a8     MOV        this,dword ptr [ESP + param_8]
    //         004460ac     DEC        EBX
    //         004460ad     PUSH       this
    //         004460ae     PUSH       EBX
    //         004460af     PUSH       EDI
    //         004460b0     PUSH       EBP
    //         004460b1     MOV        this,ESI
    //         004460b3     CALL       TDrawArea::DrawVertLine                          void DrawVertLine(TDrawArea * this, long para
    //                               LAB_004460b8                                                 XREF[2]:     0044601c(j), 00446028(j)  
    //                              Drawarea.cpp:4287 (7)
    //         004460b8     POP        EDI
    //         004460b9     POP        ESI
    //         004460ba     POP        EBP
    //         004460bb     POP        EBX
    //         004460bc     RET        0x20
}

// Offset: 0x004460C0
void DrawBevel32(TDrawArea* this_, long param_2, long param_3, long param_4, long param_5, uchar param_6, uchar param_7, uchar param_8, uchar param_9, uchar param_10, uchar param_11) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TDrawArea::DrawBevel32(long,long,long,long,unsigned char,unsigned char,uns... *
    //                              *********************************************************************************************************
    //                              void __thiscall DrawBevel32(TDrawArea * this, long param_1, long par
    //              void              <VOID>         <RETURN>
    //              TDrawArea *       ECX:4 (auto)   this
    //              long              Stack[0x4]:4   param_1                   XREF[6]:     004460c1(R), 004460d3(W), 004460dd(R), 00446143(R), 
    //                                                                                     004461bb(R), 004461ce(R)  
    //              long              Stack[0x8]:4   param_2                   XREF[4]:     004460e1(R), 00446132(W), 0044614c(R), 004461fb(R)  
    //              long              Stack[0xc]:4   param_3                   XREF[5]:     004460c6(R), 004460d7(W), 00446137(R), 00446171(R), 
    //                                                                                     0044619f(R)  
    //              long              Stack[0x10]:4  param_4                   XREF[4]:     004460e5(R), 004460f1(W), 004461b7(R), 004461e4(R)  
    //              uchar             Stack[0x14]:1  param_5                   XREF[4]:     0044610f(R), 00446126(R), 0044615b(W), 0044618b(R)  
    //              uchar             Stack[0x18]:1  param_6                   XREF[2]:     00446147(R), 00446164(R)  
    //              uchar             Stack[0x1c]:1  param_7                   XREF[2]:     0044617e(R), 00446197(R)  
    //              uchar             Stack[0x20]:1  param_8
    //              uchar             Stack[0x24]:1  param_9                   XREF[1]:     004461e0(R)  
    //              uchar             Stack[0x28]:1  param_10                  XREF[2]:     004461b3(R), 004461ca(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     0044611d(W), 004461ed(R)  
    //                               ?DrawBevel32@TDrawArea@@QAEXJJJJEEEEEE@Z                     XREF[1]:     draw:00472f88(c)  
    //                               TDrawArea::DrawBevel32
    //                              Drawarea.cpp:4293 (1)
    //         004460c0     PUSH       this
    //                              Drawarea.cpp:4297 (18)
    //         004460c1     MOV        EAX,dword ptr [ESP + param_1]
    //         004460c5     PUSH       EBX
    //         004460c6     MOV        EBX,dword ptr [ESP + param_3]
    //         004460ca     PUSH       EBP
    //         004460cb     PUSH       ESI
    //         004460cc     CMP        EAX,EBX
    //         004460ce     PUSH       EDI
    //         004460cf     MOV        ESI,this
    //         004460d1     JLE        LAB_004460e1
    //                              Drawarea.cpp:4300 (4)
    //         004460d3     MOV        dword ptr [ESP + param_1],EBX
    //                              Drawarea.cpp:4301 (10)
    //         004460d7     MOV        dword ptr [ESP + param_3],EAX
    //         004460db     MOV        EBX,EAX
    //         004460dd     MOV        EAX,dword ptr [ESP + param_1]
    //                               LAB_004460e1                                                 XREF[1]:     004460d1(j)  
    //                              Drawarea.cpp:4304 (12)
    //         004460e1     MOV        EBP,dword ptr [ESP + param_2]
    //         004460e5     MOV        EDI,dword ptr [ESP + param_4]
    //         004460e9     CMP        EBP,EDI
    //         004460eb     JLE        LAB_004460f7
    //                              Drawarea.cpp:4306 (2)
    //         004460ed     MOV        this,EBP
    //                              Drawarea.cpp:4307 (2)
    //         004460ef     MOV        EBP,EDI
    //                              Drawarea.cpp:4308 (6)
    //         004460f1     MOV        dword ptr [ESP + param_4],this
    //         004460f5     MOV        EDI,this
    //                               LAB_004460f7                                                 XREF[1]:     004460eb(j)  
    //                              Drawarea.cpp:4311 (3)
    //         004460f7     SUB        EBX,EAX
    //         004460f9     INC        EBX
    //                              Drawarea.cpp:4312 (9)
    //         004460fa     CMP        EBX,0x1
    //         004460fd     JL         LAB_0044620d
    //                              Drawarea.cpp:4315 (3)
    //         00446103     SUB        EDI,EBP
    //         00446105     INC        EDI
    //                              Drawarea.cpp:4316 (9)
    //         00446106     CMP        EDI,0x1
    //         00446109     JL         LAB_0044620d
    //                              Drawarea.cpp:4320 (23)
    //         0044610f     MOV        this,dword ptr [ESP + param_5]
    //         00446113     LEA        EDX,[EBX + -0x1]
    //         00446116     PUSH       this
    //         00446117     INC        EAX
    //         00446118     PUSH       EDX
    //         00446119     PUSH       EBP
    //         0044611a     PUSH       EAX
    //         0044611b     MOV        this,ESI
    //         0044611d     MOV        dword ptr [ESP + local_4],EAX
    //         00446121     CALL       TDrawArea::DrawHorzLine                          void DrawHorzLine(TDrawArea * this, long para
    //                              Drawarea.cpp:4321 (29)
    //         00446126     MOV        this,dword ptr [ESP + param_5]
    //         0044612a     LEA        EDX,[EDI + -0x2]
    //         0044612d     LEA        EAX,[EBP + 0x1]
    //         00446130     PUSH       this
    //         00446131     PUSH       EDX
    //         00446132     MOV        dword ptr [ESP + param_2],EAX
    //         00446136     PUSH       EAX
    //         00446137     MOV        EAX,dword ptr [ESP + param_3]
    //         0044613b     PUSH       EAX
    //         0044613c     MOV        this,ESI
    //         0044613e     CALL       TDrawArea::DrawVertLine                          void DrawVertLine(TDrawArea * this, long para
    //                              Drawarea.cpp:4324 (33)
    //         00446143     MOV        this,dword ptr [ESP + param_1]
    //         00446147     MOV        EDX,dword ptr [ESP + param_6]
    //         0044614b     PUSH       EDX
    //         0044614c     MOV        EDX,dword ptr [ESP + param_2]
    //         00446150     LEA        EAX,[ECX + this+0x2]
    //         00446153     LEA        this,[EBX + -0x3]
    //         00446156     PUSH       this
    //         00446157     PUSH       EDX
    //         00446158     PUSH       EAX
    //         00446159     MOV        this,ESI
    //         0044615b     MOV        dword ptr [ESP + param_5],EAX
    //         0044615f     CALL       TDrawArea::DrawHorzLine                          void DrawHorzLine(TDrawArea * this, long para
    //                              Drawarea.cpp:4325 (26)
    //         00446164     MOV        this,dword ptr [ESP + param_6]
    //         00446168     LEA        EDX,[EDI + -0x4]
    //         0044616b     LEA        EAX,[EBP + 0x2]
    //         0044616e     PUSH       this
    //         0044616f     PUSH       EDX
    //         00446170     PUSH       EAX
    //         00446171     MOV        EAX,dword ptr [ESP + param_3]
    //         00446175     MOV        this,ESI
    //         00446177     DEC        EAX
    //         00446178     PUSH       EAX
    //         00446179     CALL       TDrawArea::DrawVertLine                          void DrawVertLine(TDrawArea * this, long para
    //                              Drawarea.cpp:4328 (25)
    //         0044617e     MOV        this,dword ptr [ESP + param_7]
    //         00446182     LEA        EDX,[EBX + -0x4]
    //         00446185     PUSH       this
    //         00446186     LEA        EAX,[EBP + 0x2]
    //         00446189     PUSH       EDX
    //         0044618a     PUSH       EAX
    //         0044618b     MOV        EAX,dword ptr [ESP + param_5]
    //         0044618f     MOV        this,ESI
    //         00446191     PUSH       EAX
    //         00446192     CALL       TDrawArea::DrawHorzLine                          void DrawHorzLine(TDrawArea * this, long para
    //                              Drawarea.cpp:4329 (28)
    //         00446197     MOV        this,dword ptr [ESP + param_7]
    //         0044619b     LEA        EDX,[EDI + -0x5]
    //         0044619e     PUSH       this
    //         0044619f     MOV        this,dword ptr [ESP + param_3]
    //         004461a3     LEA        EAX,[EBP + 0x3]
    //         004461a6     PUSH       EDX
    //         004461a7     ADD        this,-0x2
    //         004461aa     PUSH       EAX
    //         004461ab     PUSH       this
    //         004461ac     MOV        this,ESI
    //         004461ae     CALL       TDrawArea::DrawVertLine                          void DrawVertLine(TDrawArea * this, long para
    //                              Drawarea.cpp:4332 (23)
    //         004461b3     MOV        EDX,dword ptr [ESP + param_10]
    //         004461b7     MOV        EAX,dword ptr [ESP + param_4]
    //         004461bb     MOV        this,dword ptr [ESP + param_1]
    //         004461bf     PUSH       EDX
    //         004461c0     PUSH       EBX
    //         004461c1     PUSH       EAX
    //         004461c2     PUSH       this
    //         004461c3     MOV        this,ESI
    //         004461c5     CALL       TDrawArea::DrawHorzLine                          void DrawHorzLine(TDrawArea * this, long para
    //                              Drawarea.cpp:4333 (22)
    //         004461ca     MOV        EDX,dword ptr [ESP + param_10]
    //         004461ce     MOV        this,dword ptr [ESP + param_1]
    //         004461d2     LEA        EAX,[EDI + -0x1]
    //         004461d5     PUSH       EDX
    //         004461d6     PUSH       EAX
    //         004461d7     PUSH       EBP
    //         004461d8     PUSH       this
    //         004461d9     MOV        this,ESI
    //         004461db     CALL       TDrawArea::DrawVertLine                          void DrawVertLine(TDrawArea * this, long para
    //                              Drawarea.cpp:4336 (27)
    //         004461e0     MOV        EBP,dword ptr [ESP + param_9]
    //         004461e4     MOV        EDX,dword ptr [ESP + param_4]
    //         004461e8     ADD        EBX,-0x2
    //         004461eb     PUSH       EBP
    //         004461ec     PUSH       EBX
    //         004461ed     MOV        EBX,dword ptr [ESP + local_4]
    //         004461f1     DEC        EDX
    //         004461f2     MOV        this,ESI
    //         004461f4     PUSH       EDX
    //         004461f5     PUSH       EBX
    //         004461f6     CALL       TDrawArea::DrawHorzLine                          void DrawHorzLine(TDrawArea * this, long para
    //                              Drawarea.cpp:4337 (18)
    //         004461fb     MOV        EAX,dword ptr [ESP + param_2]
    //         004461ff     ADD        EDI,-0x3
    //         00446202     PUSH       EBP
    //         00446203     PUSH       EDI
    //         00446204     PUSH       EAX
    //         00446205     PUSH       EBX
    //         00446206     MOV        this,ESI
    //         00446208     CALL       TDrawArea::DrawVertLine                          void DrawVertLine(TDrawArea * this, long para
    //                               LAB_0044620d                                                 XREF[2]:     004460fd(j), 00446109(j)  
    //                              Drawarea.cpp:4342 (8)
    //         0044620d     POP        EDI
    //         0044620e     POP        ESI
    //         0044620f     POP        EBP
    //         00446210     POP        EBX
    //         00446211     POP        this
    //         00446212     RET        0x28
}

// Offset: 0x00446220
void SetShadowTable(TDrawArea* this_, RGE_Color_Table* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TDrawArea::SetShadowTable(class RGE_Color_Table *)                            *
    //                              *********************************************************************************************************
    //                              void __thiscall SetShadowTable(TDrawArea * this, RGE_Color_Table * p
    //              void              <VOID>         <RETURN>
    //              TDrawArea *       ECX:4 (auto)   this
    //              RGE_Color_Tabl    Stack[0x4]:4   param_1                   XREF[1]:     00446220(R)  
    //                               ?SetShadowTable@TDrawArea@@QAEXPAVRGE_Color_Table@@@Z        XREF[4]:     setup_shadow_area:0046750d(c), 
    //                               TDrawArea::SetShadowTable                                                 draw_background:004677d9(c), 
    //                                                                                                         draw_background:0046785e(c), 
    //                                                                                                         draw_background:004678e2(c)  
    //                              Drawarea.cpp:4348 (10)
    //         00446220     MOV        EAX,dword ptr [ESP + param_1]
    //         00446224     MOV        dword ptr [ECX + this->shadow_color_table],EAX
    //                              Drawarea.cpp:4350 (3)
    //         0044622a     RET        0x4
}

// Offset: 0x00446230
void DrawShadowBox(TDrawArea* this_, long param_2, long param_3, long param_4, long param_5) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TDrawArea::DrawShadowBox(long,long,long,long)                                 *
    //                              *********************************************************************************************************
    //                              void __thiscall DrawShadowBox(TDrawArea * this, long param_1, long p
    //              void              <VOID>         <RETURN>
    //              TDrawArea *       ECX:4 (auto)   this
    //              long              Stack[0x4]:4   param_1                   XREF[6]:     00446250(R), 00446258(W), 00446287(R), 0044628d(W), 
    //                                                                                     004462b5(R), 004462f1(R)  
    //              long              Stack[0x8]:4   param_2                   XREF[8]:     0044625f(R), 00446267(W), 00446291(R), 00446297(W), 
    //                                                                                     004462c1(R), 004462db(R), 004462ec(R), 0044630c(R)  
    //              long              Stack[0xc]:4   param_3                   XREF[6]:     0044626e(R), 00446276(W), 0044629e(R), 004462a7(W), 
    //                                                                                     004462b9(R), 00446304(R)  
    //              long              Stack[0x10]:4  param_4                   XREF[1]:     0044627d(R)  
    //                               ?DrawShadowBox@TDrawArea@@QAEXJJJJ@Z                         XREF[2]:     setup_shadow_area:00467520(c), 
    //                               TDrawArea::DrawShadowBox                                                  draw_background:004678fa(c)  
    //                              Drawarea.cpp:4356 (6)
    //         00446230     PUSH       EBX
    //         00446231     PUSH       EBP
    //         00446232     PUSH       ESI
    //         00446233     PUSH       EDI
    //         00446234     MOV        EDI,this
    //                              Drawarea.cpp:4365 (23)
    //         00446236     XOR        this,this
    //         00446238     CMP        dword ptr [EDI + 0xc8],this
    //         0044623e     JZ         LAB_00446338
    //         00446244     CMP        dword ptr [EDI + 0x8],this
    //         00446247     JZ         LAB_00446338
    //                              Drawarea.cpp:4369 (15)
    //         0044624d     MOV        EAX,dword ptr [EDI + 0x28]
    //         00446250     MOV        EDX,dword ptr [ESP + param_1]
    //         00446254     CMP        EDX,EAX
    //         00446256     JGE        LAB_0044625c
    //         00446258     MOV        dword ptr [ESP + param_1],EAX
    //                               LAB_0044625c                                                 XREF[1]:     00446256(j)  
    //                              Drawarea.cpp:4370 (15)
    //         0044625c     MOV        EAX,dword ptr [EDI + 0x2c]
    //         0044625f     MOV        EDX,dword ptr [ESP + param_2]
    //         00446263     CMP        EDX,EAX
    //         00446265     JGE        LAB_0044626b
    //         00446267     MOV        dword ptr [ESP + param_2],EAX
    //                               LAB_0044626b                                                 XREF[1]:     00446265(j)  
    //                              Drawarea.cpp:4371 (15)
    //         0044626b     MOV        EAX,dword ptr [EDI + 0x30]
    //         0044626e     MOV        EDX,dword ptr [ESP + param_3]
    //         00446272     CMP        EDX,EAX
    //         00446274     JLE        LAB_0044627a
    //         00446276     MOV        dword ptr [ESP + param_3],EAX
    //                               LAB_0044627a                                                 XREF[1]:     00446274(j)  
    //                              Drawarea.cpp:4372 (13)
    //         0044627a     MOV        EAX,dword ptr [EDI + 0x34]
    //         0044627d     MOV        EBX,dword ptr [ESP + param_4]
    //         00446281     CMP        EBX,EAX
    //         00446283     JLE        LAB_00446287
    //         00446285     MOV        EBX,EAX
    //                               LAB_00446287                                                 XREF[1]:     00446283(j)  
    //                              Drawarea.cpp:4375 (10)
    //         00446287     CMP        dword ptr [ESP + param_1],this
    //         0044628b     JGE        LAB_00446291
    //         0044628d     MOV        dword ptr [ESP + param_1],this
    //                               LAB_00446291                                                 XREF[1]:     0044628b(j)  
    //                              Drawarea.cpp:4376 (10)
    //         00446291     CMP        dword ptr [ESP + param_2],this
    //         00446295     JGE        LAB_0044629b
    //         00446297     MOV        dword ptr [ESP + param_2],this
    //                               LAB_0044629b                                                 XREF[1]:     00446295(j)  
    //                              Drawarea.cpp:4377 (16)
    //         0044629b     MOV        EAX,dword ptr [EDI + 0x18]
    //         0044629e     MOV        this,dword ptr [ESP + param_3]
    //         004462a2     CMP        this,EAX
    //         004462a4     JL         LAB_004462ab
    //         004462a6     DEC        EAX
    //         004462a7     MOV        dword ptr [ESP + param_3],EAX
    //                               LAB_004462ab                                                 XREF[1]:     004462a4(j)  
    //                              Drawarea.cpp:4378 (10)
    //         004462ab     MOV        EAX,dword ptr [EDI + 0x1c]
    //         004462ae     CMP        EBX,EAX
    //         004462b0     JL         LAB_004462b5
    //         004462b2     LEA        EBX,[EAX + -0x1]
    //                               LAB_004462b5                                                 XREF[1]:     004462b0(j)  
    //                              Drawarea.cpp:4380 (18)
    //         004462b5     MOV        EAX,dword ptr [ESP + param_1]
    //         004462b9     MOV        this,dword ptr [ESP + param_3]
    //         004462bd     CMP        this,EAX
    //         004462bf     JL         LAB_00446338
    //         004462c1     CMP        EBX,dword ptr [ESP + param_2]
    //         004462c5     JL         LAB_00446338
    //                              Drawarea.cpp:4384 (15)
    //         004462c7     MOV        ESI,dword ptr [EDI + 0x24]
    //         004462ca     MOV        this,EDI
    //         004462cc     CALL       TDrawArea::AlignedWidth                          long AlignedWidth(TDrawArea * this)
    //         004462d1     MOV        EBP,EAX
    //         004462d3     IMUL       EBP,ESI
    //                              Drawarea.cpp:4385 (5)
    //         004462d6     CMP        ESI,0x1
    //         004462d9     JGE        LAB_004462ea
    //                              Drawarea.cpp:4386 (13)
    //         004462db     MOV        this,dword ptr [ESP + param_2]
    //         004462df     MOV        EAX,dword ptr [EDI + 0x1c]
    //         004462e2     SUB        this,EAX
    //         004462e4     INC        this
    //         004462e5     IMUL       this,EBP
    //                              Drawarea.cpp:4387 (2)
    //         004462e8     JMP        LAB_004462f1
    //                               LAB_004462ea                                                 XREF[1]:     004462d9(j)  
    //                              Drawarea.cpp:4388 (14)
    //         004462ea     MOV        this,EBP
    //         004462ec     IMUL       this,dword ptr [ESP + param_2]
    //                               LAB_004462f1                                                 XREF[1]:     004462e8(j)  
    //         004462f1     MOV        EDX,dword ptr [ESP + param_1]
    //         004462f5     MOV        EAX,dword ptr [EDI + 0x8]
    //                              Drawarea.cpp:4393 (20)
    //         004462f8     MOV        EDI,dword ptr [EDI + 0xc8]
    //         004462fe     ADD        this,EDX
    //         00446300     ADD        this,EAX
    //         00446302     MOV        EAX,EDX
    //         00446304     MOV        EDX,dword ptr [ESP + param_3]
    //         00446308     MOV        ESI,this
    //         0044630a     SUB        ESI,EAX
    //                              Drawarea.cpp:4396 (16)
    //         0044630c     MOV        EAX,dword ptr [ESP + param_2]
    //         00446310     ADD        ESI,EDX
    //         00446312     ADD        EDI,0x28
    //         00446315     CMP        EAX,EBX
    //         00446317     JG         LAB_00446338
    //         00446319     SUB        EBX,EAX
    //         0044631b     INC        EBX
    //                               LAB_0044631c                                                 XREF[1]:     00446336(j)  
    //                              Drawarea.cpp:4402 (6)
    //         0044631c     CMP        this,ESI
    //         0044631e     MOV        EDX,this
    //         00446320     JA         LAB_00446331
    //                               LAB_00446322                                                 XREF[1]:     0044632f(j)  
    //                              Drawarea.cpp:4403 (15)
    //         00446322     XOR        EAX,EAX
    //         00446324     MOV        AL,byte ptr [EDX]
    //         00446326     INC        EDX
    //         00446327     CMP        EDX,ESI
    //         00446329     MOV        AL,byte ptr [EDI + EAX*0x1]
    //         0044632c     MOV        byte ptr [EDX + -0x1],AL
    //         0044632f     JBE        LAB_00446322
    //                               LAB_00446331                                                 XREF[1]:     00446320(j)  
    //                              Drawarea.cpp:4406 (2)
    //         00446331     ADD        this,EBP
    //                              Drawarea.cpp:4407 (5)
    //         00446333     ADD        ESI,EBP
    //         00446335     DEC        EBX
    //         00446336     JNZ        LAB_0044631c
    //                               LAB_00446338                                                 XREF[5]:     0044623e(j), 00446247(j), 
    //                                                                                                         004462bf(j), 004462c5(j), 
    //                                                                                                         00446317(j)  
    //                              Drawarea.cpp:4409 (7)
    //         00446338     POP        EDI
    //         00446339     POP        ESI
    //         0044633a     POP        EBP
    //         0044633b     POP        EBX
    //         0044633c     RET        0x10
}

// Offset: 0x00446340
void GetPalette(TDrawArea* this_, tagPALETTEENTRY* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TDrawArea::GetPalette(struct tagPALETTEENTRY *)                               *
    //                              *********************************************************************************************************
    //                              void __thiscall GetPalette(TDrawArea * this, tagPALETTEENTRY * param
    //              void              <VOID>         <RETURN>
    //              TDrawArea *       ECX:4 (auto)   this
    //              tagPALETTEENTR    Stack[0x4]:4   param_1                   XREF[1]:     00446340(R)  
    //                               ?GetPalette@TDrawArea@@QAEXPAUtagPALETTEENTRY@@@Z            XREF[7]:     RGE_fade_palette:00424119(c), 
    //                               TDrawArea::GetPalette                                                     RGE_Color_Table:0042461f(c), 
    //                                                                                                         take_snapshot:0044643d(c), 
    //                                                                                                         set_focus:0047bbdc(c), 
    //                                                                                                         handle_idle:00492af2(c), 
    //                                                                                                         RGE_fade_palette_start:004934a8(c)
    //                                                                                                         take_snapshot:004bebd0(c)  
    //                              Drawarea.cpp:4415 (18)
    //         00446340     MOV        EAX,dword ptr [ESP + param_1]
    //         00446344     MOV        EDX,0x78
    //         00446349     PUSH       ESI
    //         0044634a     PUSH       EDI
    //         0044634b     SUB        EDX,EAX
    //         0044634d     MOV        ESI,0x100
    //                               LAB_00446352                                                 XREF[1]:     00446361(j)  
    //                              Drawarea.cpp:4420 (17)
    //         00446352     MOV        EDI,dword ptr [this->DrawSystem]
    //         00446354     ADD        EAX,0x4
    //         00446357     ADD        EDI,EDX
    //         00446359     DEC        ESI
    //         0044635a     MOV        EDI,dword ptr [EDI + EAX*0x1 + -0x4]
    //         0044635e     MOV        dword ptr [EAX + -0x4],EDI
    //         00446361     JNZ        LAB_00446352
    //                              Drawarea.cpp:4421 (5)
    //         00446363     POP        EDI
    //         00446364     POP        ESI
    //         00446365     RET        0x4
}

// Offset: 0x00446370
void SetPalette(TDrawArea* this_, tagPALETTEENTRY* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TDrawArea::SetPalette(struct tagPALETTEENTRY *)                               *
    //                              *********************************************************************************************************
    //                              void __thiscall SetPalette(TDrawArea * this, tagPALETTEENTRY * param
    //              void              <VOID>         <RETURN>
    //              TDrawArea *       ECX:4 (auto)   this
    //              tagPALETTEENTR    Stack[0x4]:4   param_1                   XREF[1]:     00446370(R)  
    //                               ?SetPalette@TDrawArea@@QAEXPAUtagPALETTEENTRY@@@Z            XREF[3]:     RGE_fade_palette:00424260(c), 
    //                               TDrawArea::SetPalette                                                     RGE_fade_palette:0042432d(c), 
    //                                                                                                         RGE_fade_palette_step:004936b9(c)  
    //                              Drawarea.cpp:4427 (6)
    //         00446370     MOV        EAX,dword ptr [ESP + param_1]
    //         00446374     XOR        EDX,EDX
    //                              Drawarea.cpp:4439 (52)
    //         00446376     PUSH       EAX
    //         00446377     PUSH       0x100
    //         0044637c     MOV        byte ptr [EAX],DL
    //         0044637e     MOV        byte ptr [EAX + 0x1],DL
    //         00446381     MOV        byte ptr [EAX + 0x2],DL
    //         00446384     MOV        byte ptr [EAX + 0x3],DL
    //         00446387     MOV        byte ptr [EAX + 0x3fc],0xff
    //         0044638e     MOV        byte ptr [EAX + 0x3fd],0xff
    //         00446395     MOV        byte ptr [EAX + 0x3fe],0xff
    //         0044639c     MOV        byte ptr [EAX + 0x3ff],DL
    //         004463a2     MOV        this,dword ptr [this->DrawSystem]
    //         004463a4     PUSH       EDX
    //         004463a5     CALL       TDrawSystem::ModifyPalette                       void ModifyPalette(TDrawSystem * this, int pa
    //                              Drawarea.cpp:4440 (3)
    //         004463aa     RET        0x4
}

// Offset: 0x004463B0
void take_snapshot(TDrawArea* this_, char* param_2, int* param_3) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TDrawArea::take_snapshot(char *,int &)                                        *
    //                              *********************************************************************************************************
    //                              void __thiscall take_snapshot(TDrawArea * this, char * param_1, int 
    //              void              <VOID>         <RETURN>
    //              TDrawArea *       ECX:4 (auto)   this
    //              char *            Stack[0x4]:4   param_1                   XREF[1]:     00446489(R)  
    //              int *             Stack[0x8]:4   param_2                   XREF[1]:     00446480(R)  
    //              tagPALETTEENTR    Stack[-0x404   thePal                    XREF[0,1]:   004463cd(*)  
    //              tagRGBQUAD[256]   Stack[-0x804   bmPAL                     XREF[0,1]:   0044653c(*)  
    //              char[60]          Stack[-0x840   BMPFile                   XREF[1,4]:   00446439(W), 00446496(*), 004464a5(*), 004464b4(*), 
    //                                                                                     004464f8(*)  
    //              tagBITMAPINFOH    Stack[-0x868   bmIH                      XREF[0,11]:  0044640f(W), 0044652c(*), 004463c6(W), 004463e7(W), 
    //                                                                                     00446417(W), 0044641e(W), 00446425(W), 00446429(W), 
    //                                                                                     0044642d(W), 00446431(W), 00446435(W)  
    //              tagBITMAPFILEH    Stack[-0x878   bmFH                      XREF[2,5]:   004463da(W), 00446564(R), 004463f2(W), 0044651c(*), 
    //                                                                                     004463f9(W), 004463fd(W), 00446402(W)  
    //              undefined4        Stack[-0x87c   local_87c                 XREF[3]:     004463ee(W), 004464eb(R), 0044658f(R)  
    //              int               Stack[-0x880   bmWide
    //                               ?take_snapshot@TDrawArea@@QAEXPADAAH@Z                       XREF[1]:     handle_key_down:004212a5(c)  
    //                               TDrawArea::take_snapshot
    //                              Drawarea.cpp:4449 (12)
    //         004463b0     SUB        ESP,0x87c
    //         004463b6     PUSH       EBX
    //         004463b7     PUSH       EBP
    //         004463b8     PUSH       ESI
    //         004463b9     MOV        ESI,this
    //         004463bb     PUSH       EDI
    //                              Drawarea.cpp:4475 (10)
    //         004463bc     XOR        EBX,EBX
    //         004463be     MOV        EAX,dword ptr [ESI + 0x18]
    //         004463c1     MOV        this,dword ptr [ESI + 0x1c]
    //         004463c4     MOV        EDI,this
    //                              Drawarea.cpp:4482 (7)
    //         004463c6     MOV        dword ptr [ESP + bmIH.biHeight],EAX
    //         004463ca     LEA        EDX,[EAX + 0x3]
    //                              Drawarea.cpp:4495 (117)
    //         004463cd     LEA        EAX=>thePal[1],[ESP + 0x48c]
    //         004463d4     AND        EDX,0xfffc
    //         004463da     MOV        dword ptr [ESP + bmFH.bfType],this
    //         004463de     IMUL       EDI,EDX
    //         004463e1     ADD        EDI,0x436
    //         004463e7     MOV        dword ptr [ESP + bmIH.biPlanes],this
    //         004463eb     PUSH       EAX
    //         004463ec     MOV        this,ESI
    //         004463ee     MOV        dword ptr [ESP + local_87c],EDX
    //         004463f2     MOV        word ptr [ESP + bmFH+0x4],0x4d42
    //         004463f9     MOV        dword ptr [ESP + bmFH.bfReserved1],EDI
    //         004463fd     MOV        word ptr [ESP + bmFH.bfOffBits],BX
    //         00446402     MOV        word ptr [ESP + bmFH+0xc],BX
    //         00446407     MOV        dword ptr [ESP + Stack[-0x86a]],0x436
    //         0044640f     MOV        dword ptr [ESP + bmIH.biWidth],0x28
    //         00446417     MOV        word ptr [ESP + bmIH.biCompression],0x1
    //         0044641e     MOV        word ptr [ESP + bmIH+0x12],0x8
    //         00446425     MOV        dword ptr [ESP + bmIH.biSizeImage],EBX
    //         00446429     MOV        dword ptr [ESP + bmIH.biXPelsPerMeter],EBX
    //         0044642d     MOV        dword ptr [ESP + bmIH.biYPelsPerMeter],EBX
    //         00446431     MOV        dword ptr [ESP + bmIH.biClrUsed],EBX
    //         00446435     MOV        dword ptr [ESP + bmIH.biClrImportant],EBX
    //         00446439     MOV        dword ptr [ESP + BMPFile[0]],EBX
    //         0044643d     CALL       TDrawArea::GetPalette                            void GetPalette(TDrawArea * this, tagPALETTEE
    //                              Drawarea.cpp:4499 (9)
    //         00446442     XOR        EAX,EAX
    //                               LAB_00446444                                                 XREF[1]:     0044647e(j)  
    //         00446444     MOV        this,byte ptr [ESP + EAX*0x1 + 0x48e]
    //                              Drawarea.cpp:4500 (14)
    //         0044644b     MOV        DL,byte ptr [ESP + EAX*0x1 + 0x48d]
    //         00446452     MOV        byte ptr [ESP + EAX*0x1 + 0x8c],this
    //                              Drawarea.cpp:4501 (21)
    //         00446459     MOV        this,byte ptr [ESP + EAX*0x1 + 0x48c]
    //         00446460     MOV        byte ptr [ESP + EAX*0x1 + 0x8d],DL
    //         00446467     MOV        byte ptr [ESP + EAX*0x1 + 0x8e],this
    //                              Drawarea.cpp:4502 (18)
    //         0044646e     MOV        byte ptr [ESP + EAX*0x1 + 0x8f],0x0
    //         00446476     ADD        EAX,0x4
    //         00446479     CMP        EAX,0x400
    //         0044647e     JL         LAB_00446444
    //                              Drawarea.cpp:4507 (9)
    //         00446480     MOV        EDI,dword ptr [ESP + param_2]
    //         00446487     XOR        EBP,EBP
    //                               LAB_00446489                                                 XREF[1]:     004464dc(j)  
    //                              Drawarea.cpp:4511 (11)
    //         00446489     MOV        EAX,dword ptr [ESP + param_1]
    //         00446490     CMP        EAX,EBX
    //         00446492     JNZ        LAB_004464a3
    //                              Drawarea.cpp:4512 (13)
    //         00446494     MOV        EDX,dword ptr [EDI]
    //         00446496     LEA        EAX=>BMPFile[4],[ESP + 0x50]
    //         0044649a     PUSH       EDX
    //         0044649b     PUSH       s_C:\AOE_%03d.BMP                                = "C:\\AOE_%03d.BMP"
    //         004464a0     PUSH       EAX
    //                              Drawarea.cpp:4513 (2)
    //         004464a1     JMP        LAB_004464ac
    //                               LAB_004464a3                                                 XREF[1]:     00446492(j)  
    //                              Drawarea.cpp:4514 (17)
    //         004464a3     MOV        this,dword ptr [EDI]
    //         004464a5     LEA        EDX=>BMPFile[4],[ESP + 0x50]
    //         004464a9     PUSH       this
    //         004464aa     PUSH       EAX
    //         004464ab     PUSH       EDX
    //                               LAB_004464ac                                                 XREF[1]:     004464a1(j)  
    //         004464ac     CALL       sprintf                                          undefined sprintf()
    //         004464b1     ADD        ESP,0xc
    //                              Drawarea.cpp:4518 (20)
    //         004464b4     LEA        EAX=>BMPFile[4],[ESP + 0x50]
    //         004464b8     INC        EBP
    //         004464b9     PUSH       EBX
    //         004464ba     PUSH       EAX
    //         004464bb     CALL       __open                                           undefined __open()
    //         004464c0     ADD        ESP,0x8
    //         004464c3     CMP        EAX,-0x1
    //         004464c6     JZ         LAB_004464eb
    //                              Drawarea.cpp:4520 (2)
    //         004464c8     MOV        this,dword ptr [EDI]
    //                              Drawarea.cpp:4521 (12)
    //         004464ca     PUSH       EAX
    //         004464cb     INC        this
    //         004464cc     MOV        dword ptr [EDI],this
    //         004464ce     CALL       close                                            undefined close()
    //         004464d3     ADD        ESP,0x4
    //                              Drawarea.cpp:4526 (8)
    //         004464d6     CMP        EBP,0x3e8
    //         004464dc     JLE        LAB_00446489
    //                              Drawarea.cpp:4563 (13)
    //         004464de     POP        EDI
    //         004464df     POP        ESI
    //         004464e0     POP        EBP
    //         004464e1     POP        EBX
    //         004464e2     ADD        ESP,0x87c
    //         004464e8     RET        0x8
    //                               LAB_004464eb                                                 XREF[1]:     004464c6(j)  
    //                              Drawarea.cpp:4531 (13)
    //         004464eb     MOV        this,dword ptr [ESP + local_87c]
    //         004464ef     PUSH       this
    //         004464f0     CALL       malloc                                           undefined malloc()
    //         004464f5     ADD        ESP,0x4
    //                              Drawarea.cpp:4533 (36)
    //         004464f8     LEA        EDX=>BMPFile[4],[ESP + 0x50]
    //         004464fc     MOV        EDI,EAX
    //         004464fe     PUSH       0x180
    //         00446503     PUSH       0x8301
    //         00446508     PUSH       EDX
    //         00446509     CALL       __open                                           undefined __open()
    //         0044650e     MOV        EBX,EAX
    //         00446510     ADD        ESP,0xc
    //         00446513     CMP        EBX,-0x1
    //         00446516     JZ         LAB_004465b6
    //                              Drawarea.cpp:4535 (16)
    //         0044651c     LEA        EAX=>bmFH+0x4,[ESP + 0x18]
    //         00446520     PUSH       0xe
    //         00446522     PUSH       EAX
    //         00446523     PUSH       EBX
    //         00446524     CALL       write                                            undefined write()
    //         00446529     ADD        ESP,0xc
    //                              Drawarea.cpp:4536 (16)
    //         0044652c     LEA        this=>bmIH.biWidth,[ESP + 0x28]
    //         00446530     PUSH       0x28
    //         00446532     PUSH       this
    //         00446533     PUSH       EBX
    //         00446534     CALL       write                                            undefined write()
    //         00446539     ADD        ESP,0xc
    //                              Drawarea.cpp:4537 (22)
    //         0044653c     LEA        EDX=>bmPAL[1],[ESP + 0x8c]
    //         00446543     PUSH       0x400
    //         00446548     PUSH       EDX
    //         00446549     PUSH       EBX
    //         0044654a     CALL       write                                            undefined write()
    //         0044654f     ADD        ESP,0xc
    //                              Drawarea.cpp:4539 (18)
    //         00446552     MOV        this,ESI
    //         00446554     PUSH       0x1
    //         00446556     PUSH       s_take_snapshot                                  = "take_snapshot"
    //         0044655b     CALL       TDrawArea::Lock                                  uchar * Lock(TDrawArea * this, char * param_1
    //         00446560     TEST       EAX,EAX
    //         00446562     JZ         LAB_004465ad
    //                              Drawarea.cpp:4543 (11)
    //         00446564     MOV        EAX,dword ptr [ESP + bmFH.bfType]
    //         00446568     LEA        EBP,[EAX + -0x1]
    //         0044656b     TEST       EBP,EBP
    //         0044656d     JL         LAB_004465a1
    //                               LAB_0044656f                                                 XREF[1]:     0044659f(j)  
    //                              Drawarea.cpp:4545 (6)
    //         0044656f     MOV        this,dword ptr [ESI + 0xc0]
    //                              Drawarea.cpp:4546 (12)
    //         00446575     MOV        EDX,dword ptr [ESI + 0x18]
    //         00446578     XOR        EAX,EAX
    //         0044657a     MOV        this,dword ptr [this->DrawSystem + EBP*0x4]
    //         0044657d     TEST       EDX,EDX
    //         0044657f     JLE        LAB_0044658f
    //                               LAB_00446581                                                 XREF[1]:     0044658d(j)  
    //                              Drawarea.cpp:4548 (14)
    //         00446581     MOV        DL,byte ptr [this->DrawSystem]
    //         00446583     MOV        byte ptr [EAX + EDI*0x1],DL
    //         00446586     MOV        EDX,dword ptr [ESI + 0x18]
    //         00446589     INC        EAX
    //         0044658a     INC        this
    //         0044658b     CMP        EAX,EDX
    //         0044658d     JL         LAB_00446581
    //                               LAB_0044658f                                                 XREF[1]:     0044657f(j)  
    //                              Drawarea.cpp:4550 (18)
    //         0044658f     MOV        EAX,dword ptr [ESP + local_87c]
    //         00446593     PUSH       EAX
    //         00446594     PUSH       EDI
    //         00446595     PUSH       EBX
    //         00446596     CALL       write                                            undefined write()
    //         0044659b     ADD        ESP,0xc
    //         0044659e     DEC        EBP
    //         0044659f     JNS        LAB_0044656f
    //                               LAB_004465a1                                                 XREF[1]:     0044656d(j)  
    //                              Drawarea.cpp:4552 (12)
    //         004465a1     PUSH       s_take_snapshot                                  = "take_snapshot"
    //         004465a6     MOV        this,ESI
    //         004465a8     CALL       TDrawArea::Unlock                                void Unlock(TDrawArea * this, char * param_1)
    //                               LAB_004465ad                                                 XREF[1]:     00446562(j)  
    //                              Drawarea.cpp:4556 (9)
    //         004465ad     PUSH       EBX
    //         004465ae     CALL       close                                            undefined close()
    //         004465b3     ADD        ESP,0x4
    //                               LAB_004465b6                                                 XREF[1]:     00446516(j)  
    //                              Drawarea.cpp:4559 (9)
    //         004465b6     PUSH       EDI
    //         004465b7     CALL       free                                             undefined free()
    //         004465bc     ADD        ESP,0x4
    //                              Drawarea.cpp:4563 (13)
    //         004465bf     POP        EDI
    //         004465c0     POP        ESI
    //         004465c1     POP        EBP
    //         004465c2     POP        EBX
    //         004465c3     ADD        ESP,0x87c
    //         004465c9     RET        0x8
}

