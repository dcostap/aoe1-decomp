// Auto-generated scaffold unit: Cdaudio.cpp.asm
// SourceMap: C:/msdev/work/age1_x1/Cdaudio.cpp
#include "../include/common.h"

// Offset: 0x004237C0
undefined CCDAudio(CCDAudio* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall CCDAudio::CCDAudio(void)                                                           *
    //                              *********************************************************************************************************
    //                              undefined __thiscall CCDAudio(CCDAudio * this)
    //              undefined         <UNASSIGNED>   <RETURN>
    //              CCDAudio *        ECX:4 (auto)   this
    //                               ??0CCDAudio@@QAE@XZ
    //                               CCDAudio::CCDAudio
    //                              Cdaudio.cpp:18 (2)
    //         004237c0     MOV        EAX,this
    //                              Cdaudio.cpp:20 (6)
    //         004237c2     MOV        dword ptr [EAX],0x0
    //                              Cdaudio.cpp:21 (7)
    //         004237c8     MOV        dword ptr [EAX + 0x4],0x0
    //                              Cdaudio.cpp:22 (1)
    //         004237cf     RET
}

// Offset: 0x004237D0
void CCDAudio(CCDAudio* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall CCDAudio::~CCDAudio(void)                                                          *
    //                              *********************************************************************************************************
    //                              void __thiscall ~CCDAudio(CCDAudio * this)
    //              void              <VOID>         <RETURN>
    //              CCDAudio *        ECX:4 (auto)   this
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     004237d1(*), 004237de(R)  
    //              int               Stack[-0x8]:4  playing
    //                               ??1CCDAudio@@QAE@XZ
    //                               CCDAudio::~CCDAudio
    //                              Cdaudio.cpp:27 (1)
    //         004237d0     PUSH       this
    //                              Cdaudio.cpp:30 (13)
    //         004237d1     LEA        EAX=>local_4,[ESP]
    //         004237d5     PUSH       ESI
    //         004237d6     MOV        ESI,this
    //         004237d8     PUSH       EAX
    //         004237d9     CALL       CCDAudio::IsPlaying                              ulong IsPlaying(CCDAudio * this, int * param_1)
    //                              Cdaudio.cpp:31 (8)
    //         004237de     MOV        EAX,dword ptr [ESP + local_4]
    //         004237e2     TEST       EAX,EAX
    //         004237e4     JZ         LAB_004237ed
    //                              Cdaudio.cpp:32 (7)
    //         004237e6     MOV        this,ESI
    //         004237e8     CALL       CCDAudio::Stop                                   ulong Stop(CCDAudio * this)
    //                               LAB_004237ed                                                 XREF[1]:     004237e4(j)  
    //                              Cdaudio.cpp:34 (7)
    //         004237ed     MOV        this,ESI
    //         004237ef     CALL       CCDAudio::Close                                  ulong Close(CCDAudio * this)
    //                              Cdaudio.cpp:35 (3)
    //         004237f4     POP        ESI
    //         004237f5     POP        this
    //         004237f6     RET
}

// Offset: 0x00423800
ulong Open(CCDAudio* this_, void* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: unsigned long __thiscall CCDAudio::Open(void *)                                               *
    //                              *********************************************************************************************************
    //                              ulong __thiscall Open(CCDAudio * this, void * param_1)
    //              ulong             EAX:4          <RETURN>
    //              CCDAudio *        ECX:4 (auto)   this
    //              void *            Stack[0x4]:4   param_1                   XREF[1]:     00423800(R)  
    //              tagMCI_OPEN_PA    Stack[-0x18]   mciOpenParms              XREF[0,3]:   0042381f(*), 0042383e(R), 00423830(W)  
    //              tagMCI_SET_PAR    Stack[-0x24]   mciSetInfo                XREF[0,2]:   00423842(*), 0042385c(W)  
    //                               ?Open@CCDAudio@@QAEKPAX@Z
    //                               CCDAudio::Open
    //                              Cdaudio.cpp:57 (13)
    //         00423800     MOV        EAX,dword ptr [ESP + param_1]
    //         00423804     SUB        ESP,0x20
    //         00423807     PUSH       ESI
    //         00423808     MOV        ESI,this
    //         0042380a     PUSH       EDI
    //         0042380b     MOV        dword ptr [ESI],EAX
    //                              Cdaudio.cpp:62 (7)
    //         0042380d     MOV        EAX,dword ptr [ESI + 0x4]
    //         00423810     TEST       EAX,EAX
    //         00423812     JZ         LAB_00423819
    //                              Cdaudio.cpp:63 (5)
    //         00423814     CALL       CCDAudio::Close                                  ulong Close(CCDAudio * this)
    //                               LAB_00423819                                                 XREF[1]:     00423812(j)  
    //                              Cdaudio.cpp:69 (33)
    //         00423819     MOV        EDI,dword ptr [->WINMM.DLL::mciSendCommandA]     = 0048b432
    //         0042381f     LEA        this=>mciOpenParms.wDeviceID,[ESP + 0x14]
    //         00423823     PUSH       this
    //         00423824     PUSH       0x3102
    //         00423829     PUSH       0x803
    //         0042382e     PUSH       0x0
    //         00423830     MOV        dword ptr [ESP + mciOpenParms.lpstrElementName
    //         00423838     CALL       EDI=>WINMM.DLL::mciSendCommandA
    //                              Cdaudio.cpp:72 (4)
    //         0042383a     TEST       EAX,EAX
    //         0042383c     JNZ        LAB_00423866
    //                              Cdaudio.cpp:80 (4)
    //         0042383e     MOV        EAX,dword ptr [ESP + mciOpenParms.lpstrDeviceT
    //                              Cdaudio.cpp:88 (36)
    //         00423842     LEA        EDX=>mciSetInfo.dwTimeFormat,[ESP + 0x8]
    //         00423846     PUSH       EDX
    //         00423847     PUSH       0x402
    //         0042384c     PUSH       0x80d
    //         00423851     PUSH       EAX
    //         00423852     MOV        dword ptr [ESI + 0x4],0x1
    //         00423859     MOV        dword ptr [ESI + 0x8],EAX
    //         0042385c     MOV        dword ptr [ESP + mciSetInfo.dwAudio],0xa
    //         00423864     CALL       EDI=>WINMM.DLL::mciSendCommandA
    //                               LAB_00423866                                                 XREF[1]:     0042383c(j)  
    //                              Cdaudio.cpp:91 (8)
    //         00423866     PUSH       EAX
    //         00423867     MOV        this,ESI
    //         00423869     CALL       CCDAudio::DisplayErrorMsg                        ulong DisplayErrorMsg(CCDAudio * this, ulong 
    //                              Cdaudio.cpp:92 (8)
    //         0042386e     POP        EDI
    //         0042386f     POP        ESI
    //         00423870     ADD        ESP,0x20
    //         00423873     RET        0x4
}

// Offset: 0x00423880
ulong Close(CCDAudio* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: unsigned long __thiscall CCDAudio::Close(void)                                                *
    //                              *********************************************************************************************************
    //                              ulong __thiscall Close(CCDAudio * this)
    //              ulong             EAX:4          <RETURN>
    //              CCDAudio *        ECX:4 (auto)   this
    //                               ?Close@CCDAudio@@QAEKXZ                                      XREF[2]:     ~CCDAudio:004237ef(c), 
    //                               CCDAudio::Close                                                           Open:00423814(c)  
    //                              Cdaudio.cpp:106 (4)
    //         00423880     PUSH       ESI
    //         00423881     MOV        ESI,this
    //         00423883     PUSH       EDI
    //                              Cdaudio.cpp:108 (2)
    //         00423884     XOR        EDI,EDI
    //                              Cdaudio.cpp:111 (7)
    //         00423886     MOV        EAX,dword ptr [ESI + 0x4]
    //         00423889     TEST       EAX,EAX
    //         0042388b     JZ         LAB_004238b0
    //                              Cdaudio.cpp:114 (20)
    //         0042388d     MOV        EAX,dword ptr [ESI + 0x8]
    //         00423890     PUSH       EDI
    //         00423891     PUSH       0x2
    //         00423893     PUSH       0x804
    //         00423898     PUSH       EAX
    //         00423899     CALL       dword ptr [->WINMM.DLL::mciSendCommandA]         = 0048b432
    //         0042389f     MOV        EDI,EAX
    //                              Cdaudio.cpp:117 (8)
    //         004238a1     MOV        this,ESI
    //         004238a3     PUSH       EDI
    //         004238a4     CALL       CCDAudio::DisplayErrorMsg                        ulong DisplayErrorMsg(CCDAudio * this, ulong 
    //                              Cdaudio.cpp:120 (4)
    //         004238a9     TEST       EDI,EDI
    //         004238ab     JNZ        LAB_004238b0
    //                              Cdaudio.cpp:121 (3)
    //         004238ad     MOV        dword ptr [ESI + 0x4],EDI
    //                               LAB_004238b0                                                 XREF[2]:     0042388b(j), 004238ab(j)  
    //                              Cdaudio.cpp:123 (2)
    //         004238b0     MOV        EAX,EDI
    //                              Cdaudio.cpp:124 (3)
    //         004238b2     POP        EDI
    //         004238b3     POP        ESI
    //         004238b4     RET
}

// Offset: 0x004238C0
ulong Stop(CCDAudio* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: unsigned long __thiscall CCDAudio::Stop(void)                                                 *
    //                              *********************************************************************************************************
    //                              ulong __thiscall Stop(CCDAudio * this)
    //              ulong             EAX:4          <RETURN>
    //              CCDAudio *        ECX:4 (auto)   this
    //                               ?Stop@CCDAudio@@QAEKXZ                                       XREF[1]:     ~CCDAudio:004237e8(c)  
    //                               CCDAudio::Stop
    //                              Cdaudio.cpp:138 (3)
    //         004238c0     PUSH       ESI
    //         004238c1     MOV        ESI,this
    //                              Cdaudio.cpp:140 (19)
    //         004238c3     PUSH       0x0
    //         004238c5     PUSH       0x2
    //         004238c7     MOV        EAX,dword ptr [ESI + 0x8]
    //         004238ca     PUSH       0x808
    //         004238cf     PUSH       EAX
    //         004238d0     CALL       dword ptr [->WINMM.DLL::mciSendCommandA]         = 0048b432
    //                              Cdaudio.cpp:142 (8)
    //         004238d6     PUSH       EAX
    //         004238d7     MOV        this,ESI
    //         004238d9     CALL       CCDAudio::DisplayErrorMsg                        ulong DisplayErrorMsg(CCDAudio * this, ulong 
    //                              Cdaudio.cpp:143 (2)
    //         004238de     POP        ESI
    //         004238df     RET
}

// Offset: 0x004238E0
ulong Play(CCDAudio* this_, uchar param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: unsigned long __thiscall CCDAudio::Play(unsigned char)                                        *
    //                              *********************************************************************************************************
    //                              ulong __thiscall Play(CCDAudio * this, uchar param_1)
    //              ulong             EAX:4          <RETURN>
    //              CCDAudio *        ECX:4 (auto)   this
    //              uchar             Stack[0x4]:1   param_1                   XREF[1]:     004238e0(R)  
    //                               ?Play@CCDAudio@@QAEKE@Z
    //                               CCDAudio::Play
    //                              Cdaudio.cpp:166 (9)
    //         004238e0     MOV        EAX,dword ptr [ESP + param_1]
    //         004238e4     PUSH       ESI
    //         004238e5     MOV        ESI,this
    //         004238e7     MOV        this,EAX
    //                              Cdaudio.cpp:172 (27)
    //         004238e9     MOV        EDX,dword ptr [ESI]
    //         004238eb     AND        this,0xff
    //         004238f1     INC        AL
    //         004238f3     MOV        dword ptr [ESI + 0xc],EDX
    //         004238f6     AND        EAX,0xff
    //         004238fb     MOV        dword ptr [ESI + 0x10],this
    //         004238fe     MOV        dword ptr [ESI + 0x14],EAX
    //         00423901     LEA        EAX,[ESI + 0xc]
    //                              Cdaudio.cpp:175 (18)
    //         00423904     PUSH       EAX
    //         00423905     MOV        EAX,dword ptr [ESI + 0x8]
    //         00423908     PUSH       0xd
    //         0042390a     PUSH       0x806
    //         0042390f     PUSH       EAX
    //         00423910     CALL       dword ptr [->WINMM.DLL::mciSendCommandA]         = 0048b432
    //                              Cdaudio.cpp:178 (8)
    //         00423916     PUSH       EAX
    //         00423917     MOV        this,ESI
    //         00423919     CALL       CCDAudio::DisplayErrorMsg                        ulong DisplayErrorMsg(CCDAudio * this, ulong 
    //                              Cdaudio.cpp:179 (4)
    //         0042391e     POP        ESI
    //         0042391f     RET        0x4
}

// Offset: 0x00423930
ulong Pause(CCDAudio* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: unsigned long __thiscall CCDAudio::Pause(void)                                                *
    //                              *********************************************************************************************************
    //                              ulong __thiscall Pause(CCDAudio * this)
    //              ulong             EAX:4          <RETURN>
    //              CCDAudio *        ECX:4 (auto)   this
    //                               ?Pause@CCDAudio@@QAEKXZ
    //                               CCDAudio::Pause
    //                              Cdaudio.cpp:193 (3)
    //         00423930     PUSH       ESI
    //         00423931     MOV        ESI,this
    //                              Cdaudio.cpp:195 (19)
    //         00423933     PUSH       0x0
    //         00423935     PUSH       0x2
    //         00423937     MOV        EAX,dword ptr [ESI + 0x8]
    //         0042393a     PUSH       0x809
    //         0042393f     PUSH       EAX
    //         00423940     CALL       dword ptr [->WINMM.DLL::mciSendCommandA]         = 0048b432
    //                              Cdaudio.cpp:197 (8)
    //         00423946     PUSH       EAX
    //         00423947     MOV        this,ESI
    //         00423949     CALL       CCDAudio::DisplayErrorMsg                        ulong DisplayErrorMsg(CCDAudio * this, ulong 
    //                              Cdaudio.cpp:198 (2)
    //         0042394e     POP        ESI
    //         0042394f     RET
}

// Offset: 0x00423950
ulong ResumePlay(CCDAudio* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: unsigned long __thiscall CCDAudio::ResumePlay(void)                                           *
    //                              *********************************************************************************************************
    //                              ulong __thiscall ResumePlay(CCDAudio * this)
    //              ulong             EAX:4          <RETURN>
    //              CCDAudio *        ECX:4 (auto)   this
    //                               ?ResumePlay@CCDAudio@@QAEKXZ
    //                               CCDAudio::ResumePlay
    //                              Cdaudio.cpp:213 (3)
    //         00423950     PUSH       ESI
    //         00423951     MOV        ESI,this
    //                              Cdaudio.cpp:216 (21)
    //         00423953     MOV        this,dword ptr [ESI + 0x8]
    //         00423956     LEA        EAX,[ESI + 0xc]
    //         00423959     PUSH       EAX
    //         0042395a     PUSH       0x0
    //         0042395c     PUSH       0x806
    //         00423961     PUSH       this
    //         00423962     CALL       dword ptr [->WINMM.DLL::mciSendCommandA]         = 0048b432
    //                              Cdaudio.cpp:218 (8)
    //         00423968     PUSH       EAX
    //         00423969     MOV        this,ESI
    //         0042396b     CALL       CCDAudio::DisplayErrorMsg                        ulong DisplayErrorMsg(CCDAudio * this, ulong 
    //                              Cdaudio.cpp:219 (2)
    //         00423970     POP        ESI
    //         00423971     RET
}

// Offset: 0x00423980
ulong Eject(CCDAudio* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: unsigned long __thiscall CCDAudio::Eject(void)                                                *
    //                              *********************************************************************************************************
    //                              ulong __thiscall Eject(CCDAudio * this)
    //              ulong             EAX:4          <RETURN>
    //              CCDAudio *        ECX:4 (auto)   this
    //                               ?Eject@CCDAudio@@QAEKXZ
    //                               CCDAudio::Eject
    //                              Cdaudio.cpp:232 (3)
    //         00423980     PUSH       ESI
    //         00423981     MOV        ESI,this
    //                              Cdaudio.cpp:234 (22)
    //         00423983     PUSH       0x0
    //         00423985     PUSH       0x100
    //         0042398a     MOV        EAX,dword ptr [ESI + 0x8]
    //         0042398d     PUSH       0x80d
    //         00423992     PUSH       EAX
    //         00423993     CALL       dword ptr [->WINMM.DLL::mciSendCommandA]         = 0048b432
    //                              Cdaudio.cpp:236 (8)
    //         00423999     PUSH       EAX
    //         0042399a     MOV        this,ESI
    //         0042399c     CALL       CCDAudio::DisplayErrorMsg                        ulong DisplayErrorMsg(CCDAudio * this, ulong 
    //                              Cdaudio.cpp:237 (2)
    //         004239a1     POP        ESI
    //         004239a2     RET
}

// Offset: 0x004239B0
ulong GetNumberOfTracks(CCDAudio* this_, uchar* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: unsigned long __thiscall CCDAudio::GetNumberOfTracks(unsigned char &)                         *
    //                              *********************************************************************************************************
    //                              ulong __thiscall GetNumberOfTracks(CCDAudio * this, uchar * param_1)
    //              ulong             EAX:4          <RETURN>
    //              CCDAudio *        ECX:4 (auto)   this
    //              uchar *           Stack[0x4]:4   param_1
    //              tagMCI_STATUS_    Stack[-0x14]   mciStatusInfo             XREF[0,2]:   004239b6(*), 004239ba(W)  
    //                               ?GetNumberOfTracks@CCDAudio@@QAEKAAE@Z
    //                               CCDAudio::GetNumberOfTracks
    //                              Cdaudio.cpp:253 (6)
    //         004239b0     SUB        ESP,0x10
    //         004239b3     PUSH       ESI
    //         004239b4     MOV        ESI,this
    //                              Cdaudio.cpp:258 (33)
    //         004239b6     LEA        EAX=>mciStatusInfo.dwReturn,[ESP + 0x4]
    //         004239ba     MOV        dword ptr [ESP + mciStatusInfo.dwTrack],0x3
    //         004239c2     MOV        this,dword ptr [ESI + 0x8]
    //         004239c5     PUSH       EAX
    //         004239c6     PUSH       0x102
    //         004239cb     PUSH       0x814
    //         004239d0     PUSH       this
    //         004239d1     CALL       dword ptr [->WINMM.DLL::mciSendCommandA]         = 0048b432
    //                              Cdaudio.cpp:261 (8)
    //         004239d7     MOV        EDX,dword ptr [ESP + 0x18]
    //         004239db     MOV        this,byte ptr [ESP + 0x8]
    //                              Cdaudio.cpp:263 (10)
    //         004239df     PUSH       EAX
    //         004239e0     MOV        byte ptr [EDX],this
    //         004239e2     MOV        this,ESI
    //         004239e4     CALL       CCDAudio::DisplayErrorMsg                        ulong DisplayErrorMsg(CCDAudio * this, ulong 
    //                              Cdaudio.cpp:264 (7)
    //         004239e9     POP        ESI
    //         004239ea     ADD        ESP,0x10
    //         004239ed     RET        0x4
}

// Offset: 0x004239F0
ulong IsMediaPresent(CCDAudio* this_, int* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: unsigned long __thiscall CCDAudio::IsMediaPresent(int &)                                      *
    //                              *********************************************************************************************************
    //                              ulong __thiscall IsMediaPresent(CCDAudio * this, int * param_1)
    //              ulong             EAX:4          <RETURN>
    //              CCDAudio *        ECX:4 (auto)   this
    //              int *             Stack[0x4]:4   param_1
    //              tagMCI_STATUS_    Stack[-0x14]   mciStatusParms            XREF[0,2]:   004239f6(*), 004239fa(W)  
    //                               ?IsMediaPresent@CCDAudio@@QAEKAAH@Z
    //                               CCDAudio::IsMediaPresent
    //                              Cdaudio.cpp:280 (6)
    //         004239f0     SUB        ESP,0x10
    //         004239f3     PUSH       ESI
    //         004239f4     MOV        ESI,this
    //                              Cdaudio.cpp:285 (33)
    //         004239f6     LEA        EAX=>mciStatusParms.dwReturn,[ESP + 0x4]
    //         004239fa     MOV        dword ptr [ESP + mciStatusParms.dwTrack],0x5
    //         00423a02     MOV        this,dword ptr [ESI + 0x8]
    //         00423a05     PUSH       EAX
    //         00423a06     PUSH       0x102
    //         00423a0b     PUSH       0x814
    //         00423a10     PUSH       this
    //         00423a11     CALL       dword ptr [->WINMM.DLL::mciSendCommandA]         = 0048b432
    //                              Cdaudio.cpp:288 (12)
    //         00423a17     MOV        this,dword ptr [ESP + 0x8]
    //         00423a1b     XOR        EDX,EDX
    //         00423a1d     TEST       this,this
    //         00423a1f     MOV        this,dword ptr [ESP + 0x18]
    //                              Cdaudio.cpp:290 (13)
    //         00423a23     PUSH       EAX
    //         00423a24     SETNZ      DL
    //         00423a27     MOV        dword ptr [this->m_Wnd],EDX
    //         00423a29     MOV        this,ESI
    //         00423a2b     CALL       CCDAudio::DisplayErrorMsg                        ulong DisplayErrorMsg(CCDAudio * this, ulong 
    //                              Cdaudio.cpp:291 (7)
    //         00423a30     POP        ESI
    //         00423a31     ADD        ESP,0x10
    //         00423a34     RET        0x4
}

// Offset: 0x00423A40
ulong IsPlaying(CCDAudio* this_, int* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: unsigned long __thiscall CCDAudio::IsPlaying(int &)                                           *
    //                              *********************************************************************************************************
    //                              ulong __thiscall IsPlaying(CCDAudio * this, int * param_1)
    //              ulong             EAX:4          <RETURN>
    //              CCDAudio *        ECX:4 (auto)   this
    //              int *             Stack[0x4]:4   param_1                   XREF[1]:     00423a77(R)  
    //              tagMCI_STATUS_    Stack[-0x14]   mciStatusParms            XREF[0,6]:   00423a47(*), 00423a87(*), 00423a6b(R), 00423aa1(R), 
    //                                                                                     00423a61(W), 00423a97(W)  
    //                               ?IsPlaying@CCDAudio@@QAEKAAH@Z                               XREF[1]:     ~CCDAudio:004237d9(c)  
    //                               CCDAudio::IsPlaying
    //                              Cdaudio.cpp:307 (7)
    //         00423a40     SUB        ESP,0x10
    //         00423a43     PUSH       EBX
    //         00423a44     PUSH       ESI
    //         00423a45     MOV        ESI,this
    //                              Cdaudio.cpp:314 (36)
    //         00423a47     LEA        EAX=>mciStatusParms.dwReturn,[ESP + 0x8]
    //         00423a4b     PUSH       EDI
    //         00423a4c     MOV        EDI,dword ptr [->WINMM.DLL::mciSendCommandA]     = 0048b432
    //         00423a52     MOV        this,dword ptr [ESI + 0x8]
    //         00423a55     PUSH       EAX
    //         00423a56     PUSH       0x102
    //         00423a5b     PUSH       0x814
    //         00423a60     PUSH       this
    //         00423a61     MOV        dword ptr [ESP + mciStatusParms.dwTrack],0x4
    //         00423a69     CALL       EDI=>WINMM.DLL::mciSendCommandA
    //                              Cdaudio.cpp:317 (19)
    //         00423a6b     MOV        EBX,dword ptr [ESP + mciStatusParms.dwItem]
    //         00423a6f     XOR        this,this
    //         00423a71     CMP        EBX,0x20e
    //         00423a77     MOV        EBX,dword ptr [ESP + param_1]
    //         00423a7b     SETZ       this
    //                              Cdaudio.cpp:318 (6)
    //         00423a7e     TEST       this,this
    //         00423a80     MOV        dword ptr [EBX],this
    //         00423a82     JZ         LAB_00423aa7
    //                              Cdaudio.cpp:322 (29)
    //         00423a84     MOV        EAX,dword ptr [ESI + 0x8]
    //         00423a87     LEA        EDX=>mciStatusParms.dwReturn,[ESP + 0xc]
    //         00423a8b     PUSH       EDX
    //         00423a8c     PUSH       0x102
    //         00423a91     PUSH       0x814
    //         00423a96     PUSH       EAX
    //         00423a97     MOV        dword ptr [ESP + mciStatusParms.dwTrack],0x8
    //         00423a9f     CALL       EDI=>WINMM.DLL::mciSendCommandA
    //                              Cdaudio.cpp:323 (6)
    //         00423aa1     MOV        this,dword ptr [ESP + mciStatusParms.dwItem]
    //         00423aa5     MOV        dword ptr [EBX],this
    //                               LAB_00423aa7                                                 XREF[1]:     00423a82(j)  
    //                              Cdaudio.cpp:326 (8)
    //         00423aa7     PUSH       EAX
    //         00423aa8     MOV        this,ESI
    //         00423aaa     CALL       CCDAudio::DisplayErrorMsg                        ulong DisplayErrorMsg(CCDAudio * this, ulong 
    //                              Cdaudio.cpp:327 (9)
    //         00423aaf     POP        EDI
    //         00423ab0     POP        ESI
    //         00423ab1     POP        EBX
    //         00423ab2     ADD        ESP,0x10
    //         00423ab5     RET        0x4
}

// Offset: 0x00423AC0
ulong GetLength(CCDAudio* this_, uchar* param_2, uchar* param_3) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: unsigned long __thiscall CCDAudio::GetLength(unsigned char &,unsigned char &)                 *
    //                              *********************************************************************************************************
    //                              ulong __thiscall GetLength(CCDAudio * this, uchar * param_1, uchar *
    //              ulong             EAX:4          <RETURN>
    //              CCDAudio *        ECX:4 (auto)   this
    //              uchar *           Stack[0x4]:4   param_1
    //              uchar *           Stack[0x8]:4   param_2
    //              tagMCI_STATUS_    Stack[-0x14]   mciStatusParms            XREF[0,2]:   00423ac6(*), 00423aca(W)  
    //                               ?GetLength@CCDAudio@@QAEKAAE0@Z
    //                               CCDAudio::GetLength
    //                              Cdaudio.cpp:345 (6)
    //         00423ac0     SUB        ESP,0x10
    //         00423ac3     PUSH       ESI
    //         00423ac4     MOV        ESI,this
    //                              Cdaudio.cpp:350 (33)
    //         00423ac6     LEA        EAX=>mciStatusParms.dwReturn,[ESP + 0x4]
    //         00423aca     MOV        dword ptr [ESP + mciStatusParms.dwTrack],0x1
    //         00423ad2     MOV        this,dword ptr [ESI + 0x8]
    //         00423ad5     PUSH       EAX
    //         00423ad6     PUSH       0x102
    //         00423adb     PUSH       0x814
    //         00423ae0     PUSH       this
    //         00423ae1     CALL       dword ptr [->WINMM.DLL::mciSendCommandA]         = 0048b432
    //                              Cdaudio.cpp:353 (8)
    //         00423ae7     MOV        EDX,dword ptr [ESP + 0x18]
    //         00423aeb     MOV        this,dword ptr [ESP + 0x8]
    //                              Cdaudio.cpp:356 (20)
    //         00423aef     PUSH       EAX
    //         00423af0     MOV        byte ptr [EDX],this
    //         00423af2     XOR        EDX,EDX
    //         00423af4     MOV        DL,this
    //         00423af6     MOV        this,dword ptr [ESP + 0x20]
    //         00423afa     MOV        byte ptr [this->m_Wnd],DL
    //         00423afc     MOV        this,ESI
    //         00423afe     CALL       CCDAudio::DisplayErrorMsg                        ulong DisplayErrorMsg(CCDAudio * this, ulong 
    //                              Cdaudio.cpp:357 (7)
    //         00423b03     POP        ESI
    //         00423b04     ADD        ESP,0x10
    //         00423b07     RET        0x8
}

// Offset: 0x00423B10
ulong GetTrackLength(CCDAudio* this_, uchar param_2, uchar* param_3, uchar* param_4) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: unsigned long __thiscall CCDAudio::GetTrackLength(unsigned char,unsigned char &,unsigned c... *
    //                              *********************************************************************************************************
    //                              ulong __thiscall GetTrackLength(CCDAudio * this, uchar param_1, ucha
    //              ulong             EAX:4          <RETURN>
    //              CCDAudio *        ECX:4 (auto)   this
    //              uchar             Stack[0x4]:1   param_1                   XREF[1]:     00423b13(R)  
    //              uchar *           Stack[0x8]:4   param_2
    //              uchar *           Stack[0xc]:4   param_3
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     00423b3a(W)  
    //              tagMCI_STATUS_    Stack[-0x14]   mciStatusParms            XREF[0,2]:   00423b1f(*), 00423b23(W)  
    //                               ?GetTrackLength@CCDAudio@@QAEKEAAE0@Z
    //                               CCDAudio::GetTrackLength
    //                              Cdaudio.cpp:379 (3)
    //         00423b10     SUB        ESP,0x10
    //                              Cdaudio.cpp:383 (12)
    //         00423b13     MOV        EAX,dword ptr [ESP + param_1]
    //         00423b17     PUSH       ESI
    //         00423b18     MOV        ESI,this
    //         00423b1a     AND        EAX,0xff
    //                              Cdaudio.cpp:385 (37)
    //         00423b1f     LEA        this=>mciStatusParms.dwReturn,[ESP + 0x4]
    //         00423b23     MOV        dword ptr [ESP + mciStatusParms.dwTrack],0x1
    //         00423b2b     MOV        EDX,dword ptr [ESI + 0x8]
    //         00423b2e     PUSH       this
    //         00423b2f     PUSH       0x112
    //         00423b34     PUSH       0x814
    //         00423b39     PUSH       EDX
    //         00423b3a     MOV        dword ptr [ESP + local_4],EAX
    //         00423b3e     CALL       dword ptr [->WINMM.DLL::mciSendCommandA]         = 0048b432
    //                              Cdaudio.cpp:388 (8)
    //         00423b44     MOV        EDX,dword ptr [ESP + 0x1c]
    //         00423b48     MOV        this,dword ptr [ESP + 0x8]
    //                              Cdaudio.cpp:391 (20)
    //         00423b4c     PUSH       EAX
    //         00423b4d     MOV        byte ptr [EDX],this
    //         00423b4f     XOR        EDX,EDX
    //         00423b51     MOV        DL,this
    //         00423b53     MOV        this,dword ptr [ESP + 0x24]
    //         00423b57     MOV        byte ptr [this->m_Wnd],DL
    //         00423b59     MOV        this,ESI
    //         00423b5b     CALL       CCDAudio::DisplayErrorMsg                        ulong DisplayErrorMsg(CCDAudio * this, ulong 
    //                              Cdaudio.cpp:392 (7)
    //         00423b60     POP        ESI
    //         00423b61     ADD        ESP,0x10
    //         00423b64     RET        0xc
}

// Offset: 0x00423B70
ulong GetPosition(CCDAudio* this_, uchar* param_2, uchar* param_3, uchar* param_4) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: unsigned long __thiscall CCDAudio::GetPosition(unsigned char &,unsigned char &,unsigned ch... *
    //                              *********************************************************************************************************
    //                              ulong __thiscall GetPosition(CCDAudio * this, uchar * param_1, uchar
    //              ulong             EAX:4          <RETURN>
    //              CCDAudio *        ECX:4 (auto)   this
    //              uchar *           Stack[0x4]:4   param_1
    //              uchar *           Stack[0x8]:4   param_2
    //              uchar *           Stack[0xc]:4   param_3
    //              tagMCI_STATUS_    Stack[-0x14]   mciStatusParms            XREF[0,2]:   00423b76(*), 00423b8a(W)  
    //                               ?GetPosition@CCDAudio@@QAEKAAE00@Z
    //                               CCDAudio::GetPosition
    //                              Cdaudio.cpp:412 (6)
    //         00423b70     SUB        ESP,0x10
    //         00423b73     PUSH       ESI
    //         00423b74     MOV        ESI,this
    //                              Cdaudio.cpp:417 (34)
    //         00423b76     LEA        EAX=>mciStatusParms.dwReturn,[ESP + 0x4]
    //         00423b7a     PUSH       EDI
    //         00423b7b     MOV        this,dword ptr [ESI + 0x8]
    //         00423b7e     PUSH       EAX
    //         00423b7f     PUSH       0x102
    //         00423b84     PUSH       0x814
    //         00423b89     PUSH       this
    //         00423b8a     MOV        dword ptr [ESP + mciStatusParms.dwTrack],0x2
    //         00423b92     CALL       dword ptr [->WINMM.DLL::mciSendCommandA]         = 0048b432
    //                              Cdaudio.cpp:420 (8)
    //         00423b98     MOV        EDX,dword ptr [ESP + 0x1c]
    //         00423b9c     MOV        this,dword ptr [ESP + 0xc]
    //                              Cdaudio.cpp:421 (4)
    //         00423ba0     MOV        EDI,dword ptr [ESP + 0x20]
    //                              Cdaudio.cpp:424 (25)
    //         00423ba4     PUSH       EAX
    //         00423ba5     MOV        byte ptr [EDX],this
    //         00423ba7     XOR        EDX,EDX
    //         00423ba9     MOV        DL,this
    //         00423bab     MOV        byte ptr [EDI],DL
    //         00423bad     MOV        EDX,dword ptr [ESP + 0x28]
    //         00423bb1     SHR        this,0x10
    //         00423bb4     MOV        byte ptr [EDX],this
    //         00423bb6     MOV        this,ESI
    //         00423bb8     CALL       CCDAudio::DisplayErrorMsg                        ulong DisplayErrorMsg(CCDAudio * this, ulong 
    //                              Cdaudio.cpp:425 (8)
    //         00423bbd     POP        EDI
    //         00423bbe     POP        ESI
    //         00423bbf     ADD        ESP,0x10
    //         00423bc2     RET        0xc
}

// Offset: 0x00423BD0
ulong DisplayErrorMsg(CCDAudio* this_, ulong param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * private: unsigned long __thiscall CCDAudio::DisplayErrorMsg(unsigned long)                            *
    //                              *********************************************************************************************************
    //                              ulong __thiscall DisplayErrorMsg(CCDAudio * this, ulong param_1)
    //              ulong             EAX:4          <RETURN>
    //              CCDAudio *        ECX:4 (auto)   this
    //              ulong             Stack[0x4]:4   param_1                   XREF[1]:     00423bd7(R)  
    //              char[256]         Stack[-0x104   szErrorMsg                XREF[0,1]:   00423be2(*)  
    //                               ?DisplayErrorMsg@CCDAudio@@AAEKK@Z                           XREF[13]:    Open:00423869(c), 
    //                               CCDAudio::DisplayErrorMsg                                                 Close:004238a4(c), 
    //                                                                                                         Stop:004238d9(c), 
    //                                                                                                         Play:00423919(c), 
    //                                                                                                         Pause:00423949(c), 
    //                                                                                                         ResumePlay:0042396b(c), 
    //                                                                                                         Eject:0042399c(c), 
    //                                                                                                         GetNumberOfTracks:004239e4(c), 
    //                                                                                                         IsMediaPresent:00423a2b(c), 
    //                                                                                                         IsPlaying:00423aaa(c), 
    //                                                                                                         GetLength:00423afe(c), 
    //                                                                                                         GetTrackLength:00423b5b(c), 
    //                                                                                                         GetPosition:00423bb8(c)  
    //                              Cdaudio.cpp:440 (7)
    //         00423bd0     SUB        ESP,0x100
    //         00423bd6     PUSH       EBX
    //                              Cdaudio.cpp:442 (11)
    //         00423bd7     MOV        EBX,dword ptr [ESP + param_1]
    //         00423bde     TEST       EBX,EBX
    //         00423be0     JZ         LAB_00423c1f
    //                              Cdaudio.cpp:448 (22)
    //         00423be2     LEA        EAX=>szErrorMsg[4],[ESP + 0x4]
    //         00423be6     PUSH       0x100
    //         00423beb     PUSH       EAX
    //         00423bec     PUSH       EBX
    //         00423bed     CALL       dword ptr [->WINMM.DLL::mciGetErrorStringA]      = 0048b444
    //         00423bf3     TEST       EAX,EAX
    //         00423bf5     JNZ        LAB_00423c1f
    //         00423bf7     PUSH       EDI
    //                              Cdaudio.cpp:449 (39)
    //         00423bf8     MOV        EDI,s_Unknow_Error                               = 55h
    //         00423bfd     OR         this,0xffffffff
    //         00423c00     PUSH       ESI
    //         00423c01     SCASB.RE   ES:EDI=>s_Unknow_Error                           = 55h
    //                                                                                  = "nknow Error"
    //         00423c03     NOT        this
    //         00423c05     SUB        EDI,this
    //         00423c07     LEA        EDX,[ESP + 0xc]
    //         00423c0b     MOV        EAX,this
    //         00423c0d     MOV        ESI,EDI
    //         00423c0f     MOV        EDI,EDX
    //         00423c11     SHR        this,0x2
    //         00423c14     MOVSD.REP  ES:EDI,ESI
    //         00423c16     MOV        this,EAX
    //         00423c18     AND        this,0x3
    //         00423c1b     MOVSB.REP  ES:EDI,ESI
    //         00423c1d     POP        ESI
    //         00423c1e     POP        EDI
    //                               LAB_00423c1f                                                 XREF[2]:     00423be0(j), 00423bf5(j)  
    //                              Cdaudio.cpp:454 (2)
    //         00423c1f     MOV        EAX,EBX
    //                              Cdaudio.cpp:455 (10)
    //         00423c21     POP        EBX
    //         00423c22     ADD        ESP,0x100
    //         00423c28     RET        0x4
}

