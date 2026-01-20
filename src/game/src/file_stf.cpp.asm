// Auto-generated scaffold unit: file_stf.cpp.asm
// SourceMap: C:/msdev/work/age1_x1/file_stf.cpp
#include "../include/common.h"

// Offset: 0x00449710
int compareFilenameStrings(void* param_1, void* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * int __cdecl compareFilenameStrings(void const *,void const *)                                         *
    //                              *********************************************************************************************************
    //                              int __cdecl compareFilenameStrings(void * param_1, void * param_2)
    //              int               EAX:4          <RETURN>
    //              void *            Stack[0x4]:4   param_1                   XREF[1]:     00449710(R)  
    //              void *            Stack[0x8]:4   param_2                   XREF[1]:     00449716(R)  
    //                               ?compareFilenameStrings@@YAHPBX0@Z
    //                               compareFilenameStrings
    //                              file_stf.cpp:20 (48)
    //         00449710     MOV        EAX,dword ptr [ESP + param_1]
    //         00449714     PUSH       EBX
    //         00449715     PUSH       ESI
    //         00449716     MOV        ESI,dword ptr [ESP + param_2]
    //                               LAB_0044971a                                                 XREF[1]:     0044973c(j)  
    //         0044971a     MOV        DL,byte ptr [EAX]
    //         0044971c     MOV        BL,byte ptr [ESI]
    //         0044971e     MOV        CL,DL
    //         00449720     CMP        DL,BL
    //         00449722     JNZ        LAB_00449743
    //         00449724     TEST       CL,CL
    //         00449726     JZ         LAB_0044973e
    //         00449728     MOV        DL,byte ptr [EAX + 0x1]
    //         0044972b     MOV        BL,byte ptr [ESI + 0x1]
    //         0044972e     MOV        CL,DL
    //         00449730     CMP        DL,BL
    //         00449732     JNZ        LAB_00449743
    //         00449734     ADD        EAX,0x2
    //         00449737     ADD        ESI,0x2
    //         0044973a     TEST       CL,CL
    //         0044973c     JNZ        LAB_0044971a
    //                               LAB_0044973e                                                 XREF[1]:     00449726(j)  
    //         0044973e     XOR        EAX,EAX
    //                              file_stf.cpp:22 (3)
    //         00449740     POP        ESI
    //         00449741     POP        EBX
    //         00449742     RET
    //                               LAB_00449743                                                 XREF[2]:     00449722(j), 00449732(j)  
    //                              file_stf.cpp:21 (2)
    //         00449743     SBB        EAX,EAX
    //                              file_stf.cpp:22 (6)
    //         00449745     POP        ESI
    //         00449746     SBB        EAX,-0x1
    //         00449749     POP        EBX
    //         0044974a     RET
}

// Offset: 0x00449750
char driveAsLetter(int param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * char __cdecl driveAsLetter(int)                                                                       *
    //                              *********************************************************************************************************
    //                              char __cdecl driveAsLetter(int param_1)
    //              char              AL:1           <RETURN>
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     00449750(R)  
    //                               ?driveAsLetter@@YADH@Z
    //                               driveAsLetter
    //                              file_stf.cpp:28 (7)
    //         00449750     MOV        EAX,dword ptr [ESP + param_1]
    //         00449754     ADD        EAX,0x40
    //                              file_stf.cpp:30 (1)
    //         00449757     RET
}

// Offset: 0x00449760
int driveAsInt(char param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * int __cdecl driveAsInt(char)                                                                          *
    //                              *********************************************************************************************************
    //                              int __cdecl driveAsInt(char param_1)
    //              int               EAX:4          <RETURN>
    //              char              Stack[0x4]:1   param_1                   XREF[1]:     00449760(R)  
    //                               ?driveAsInt@@YAHD@Z
    //                               driveAsInt
    //                              file_stf.cpp:35 (8)
    //         00449760     MOVSX      EAX,byte ptr [ESP + param_1]
    //         00449765     SUB        EAX,0x40
    //                              file_stf.cpp:37 (1)
    //         00449768     RET
}

// Offset: 0x00449770
undefined DriveInformation(DriveInformation* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall DriveInformation::DriveInformation(void)                                           *
    //                              *********************************************************************************************************
    //                              undefined __thiscall DriveInformation(DriveInformation * this)
    //              undefined         <UNASSIGNED>   <RETURN>
    //              DriveInformati    ECX:4 (auto)   this
    //                               ??0DriveInformation@@QAE@XZ                                  XREF[1]:     setup:0041bf62(c)  
    //                               DriveInformation::DriveInformation
    //                              file_stf.cpp:43 (5)
    //         00449770     PUSH       EBX
    //         00449771     PUSH       ESI
    //         00449772     PUSH       EDI
    //         00449773     MOV        EBX,this
    //                              file_stf.cpp:45 (5)
    //         00449775     CALL       __getdrive                                       undefined __getdrive()
    //                              file_stf.cpp:48 (15)
    //         0044977a     MOV        this,EBX
    //         0044977c     MOV        dword ptr [EBX],EAX
    //         0044977e     MOV        dword ptr [EBX + 0x104],EAX
    //         00449784     CALL       DriveInformation::updateDirectory                void updateDirectory(DriveInformation * this)
    //                              file_stf.cpp:49 (33)
    //         00449789     LEA        EDI,[EBX + 0x108]
    //         0044978f     OR         this,0xffffffff
    //         00449792     XOR        EAX,EAX
    //         00449794     LEA        EDX,[EBX + 0x4]
    //         00449797     SCASB.RE   ES:EDI
    //         00449799     NOT        this
    //         0044979b     SUB        EDI,this
    //         0044979d     MOV        EAX,this
    //         0044979f     MOV        ESI,EDI
    //         004497a1     MOV        EDI,EDX
    //         004497a3     SHR        this,0x2
    //         004497a6     MOVSD.REP  ES:EDI,ESI
    //         004497a8     MOV        this,EAX
    //                              file_stf.cpp:53 (11)
    //         004497aa     MOV        EAX,EBX
    //         004497ac     AND        this,0x3
    //         004497af     MOVSB.REP  ES:EDI,ESI
    //         004497b1     POP        EDI
    //         004497b2     POP        ESI
    //         004497b3     POP        EBX
    //         004497b4     RET
}

// Offset: 0x004497C0
int initialDrive(DriveInformation* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall DriveInformation::initialDrive(void)const                                      *
    //                              *********************************************************************************************************
    //                              int __thiscall initialDrive(DriveInformation * this)
    //              int               EAX:4          <RETURN>
    //              DriveInformati    ECX:4 (auto)   this
    //                               ?initialDrive@DriveInformation@@QBEHXZ
    //                               DriveInformation::initialDrive
    //                              file_stf.cpp:58 (2)
    //         004497c0     MOV        EAX,dword ptr [this->initialDriveValue]
    //                              file_stf.cpp:60 (1)
    //         004497c2     RET
}

// Offset: 0x004497D0
char initialDriveAsLetter(DriveInformation* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: char __thiscall DriveInformation::initialDriveAsLetter(void)const                             *
    //                              *********************************************************************************************************
    //                              char __thiscall initialDriveAsLetter(DriveInformation * this)
    //              char              AL:1           <RETURN>
    //              DriveInformati    ECX:4 (auto)   this
    //                               ?initialDriveAsLetter@DriveInformation@@QBEDXZ
    //                               DriveInformation::initialDriveAsLetter
    //                              file_stf.cpp:65 (5)
    //         004497d0     MOV        EAX,dword ptr [this->initialDriveValue]
    //         004497d2     ADD        EAX,0x40
    //                              file_stf.cpp:67 (1)
    //         004497d5     RET
}

// Offset: 0x004497E0
char* initialDirectory(DriveInformation* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: char * __thiscall DriveInformation::initialDirectory(void)                                    *
    //                              *********************************************************************************************************
    //                              char * __thiscall initialDirectory(DriveInformation * this)
    //              char *            EAX:4          <RETURN>
    //              DriveInformati    ECX:4 (auto)   this
    //                               ?initialDirectory@DriveInformation@@QAEPADXZ
    //                               DriveInformation::initialDirectory
    //                              file_stf.cpp:72 (3)
    //         004497e0     LEA        EAX,[ECX + this->initialDirectoryValue[0]]
    //                              file_stf.cpp:74 (1)
    //         004497e3     RET
}

// Offset: 0x004497F0
int currentDrive(DriveInformation* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall DriveInformation::currentDrive(void)const                                      *
    //                              *********************************************************************************************************
    //                              int __thiscall currentDrive(DriveInformation * this)
    //              int               EAX:4          <RETURN>
    //              DriveInformati    ECX:4 (auto)   this
    //                               ?currentDrive@DriveInformation@@QBEHXZ
    //                               DriveInformation::currentDrive
    //                              file_stf.cpp:79 (6)
    //         004497f0     MOV        EAX,dword ptr [ECX + this->currentDriveValue]
    //                              file_stf.cpp:81 (1)
    //         004497f6     RET
}

// Offset: 0x00449800
char currentDriveAsLetter(DriveInformation* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: char __thiscall DriveInformation::currentDriveAsLetter(void)const                             *
    //                              *********************************************************************************************************
    //                              char __thiscall currentDriveAsLetter(DriveInformation * this)
    //              char              AL:1           <RETURN>
    //              DriveInformati    ECX:4 (auto)   this
    //                               ?currentDriveAsLetter@DriveInformation@@QBEDXZ
    //                               DriveInformation::currentDriveAsLetter
    //                              file_stf.cpp:86 (9)
    //         00449800     MOV        EAX,dword ptr [ECX + this->currentDriveValue]
    //         00449806     ADD        EAX,0x40
    //                              file_stf.cpp:88 (1)
    //         00449809     RET
}

// Offset: 0x00449810
char* currentDirectory(DriveInformation* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: char * __thiscall DriveInformation::currentDirectory(void)                                    *
    //                              *********************************************************************************************************
    //                              char * __thiscall currentDirectory(DriveInformation * this)
    //              char *            EAX:4          <RETURN>
    //              DriveInformati    ECX:4 (auto)   this
    //                               ?currentDirectory@DriveInformation@@QAEPADXZ
    //                               DriveInformation::currentDirectory
    //                              file_stf.cpp:93 (6)
    //         00449810     LEA        EAX,[ECX + this->currentDirectoryValue[0]]
    //                              file_stf.cpp:95 (1)
    //         00449816     RET
}

// Offset: 0x00449820
int numberDrives(DriveInformation* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall DriveInformation::numberDrives(void)const                                      *
    //                              *********************************************************************************************************
    //                              int __thiscall numberDrives(DriveInformation * this)
    //              int               EAX:4          <RETURN>
    //              DriveInformati    ECX:4 (auto)   this
    //                               ?numberDrives@DriveInformation@@QBEHXZ
    //                               DriveInformation::numberDrives
    //                              file_stf.cpp:100 (6)
    //         00449820     MOV        EAX,dword ptr [ECX + this->driveValues[0]]
    //                              file_stf.cpp:102 (1)
    //         00449826     RET
}

// Offset: 0x00449830
int validDrive(DriveInformation* this_, int param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall DriveInformation::validDrive(int)const                                         *
    //                              *********************************************************************************************************
    //                              int __thiscall validDrive(DriveInformation * this, int param_1)
    //              int               EAX:4          <RETURN>
    //              DriveInformati    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     00449830(R)  
    //                               ?validDrive@DriveInformation@@QBEHH@Z
    //                               DriveInformation::validDrive
    //                              file_stf.cpp:107 (11)
    //         00449830     MOV        EAX,dword ptr [ESP + param_1]
    //         00449834     MOV        EAX,dword ptr [ECX + EAX*0x4 + this->driveValu
    //                              file_stf.cpp:109 (3)
    //         0044983b     RET        0x4
}

// Offset: 0x00449840
void checkDrives(DriveInformation* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall DriveInformation::checkDrives(void)                                           *
    //                              *********************************************************************************************************
    //                              void __thiscall checkDrives(DriveInformation * this)
    //              void              <VOID>         <RETURN>
    //              DriveInformati    ECX:4 (auto)   this
    //                               ?checkDrives@DriveInformation@@QAEXXZ
    //                               DriveInformation::checkDrives
    //                              file_stf.cpp:114 (5)
    //         00449840     PUSH       EBX
    //         00449841     MOV        EBX,this
    //         00449843     PUSH       ESI
    //         00449844     PUSH       EDI
    //                              file_stf.cpp:119 (10)
    //         00449845     MOV        dword ptr [EBX + 0x208],0x0
    //                              file_stf.cpp:120 (11)
    //         0044984f     MOV        EDI,0x1
    //         00449854     LEA        ESI,[EBX + 0x20c]
    //                               LAB_0044985a                                                 XREF[1]:     00449889(j)  
    //                              file_stf.cpp:121 (13)
    //         0044985a     PUSH       EDI
    //         0044985b     CALL       __chdrive                                        undefined __chdrive()
    //         00449860     ADD        ESP,0x4
    //         00449863     TEST       EAX,EAX
    //         00449865     JNZ        LAB_0044987c
    //                              file_stf.cpp:122 (13)
    //         00449867     MOV        EAX,dword ptr [EBX + 0x208]
    //         0044986d     INC        EAX
    //         0044986e     MOV        dword ptr [EBX + 0x208],EAX
    //                              file_stf.cpp:123 (6)
    //         00449874     MOV        dword ptr [ESI],0x1
    //                              file_stf.cpp:125 (2)
    //         0044987a     JMP        LAB_00449882
    //                               LAB_0044987c                                                 XREF[1]:     00449865(j)  
    //                              file_stf.cpp:126 (6)
    //         0044987c     MOV        dword ptr [ESI],0x0
    //                               LAB_00449882                                                 XREF[1]:     0044987a(j)  
    //                              file_stf.cpp:120 (9)
    //         00449882     INC        EDI
    //         00449883     ADD        ESI,0x4
    //         00449886     CMP        EDI,0x1a
    //         00449889     JLE        LAB_0044985a
    //                              file_stf.cpp:128 (15)
    //         0044988b     MOV        EAX,dword ptr [EBX + 0x104]
    //         00449891     PUSH       EAX
    //         00449892     CALL       __chdrive                                        undefined __chdrive()
    //         00449897     ADD        ESP,0x4
    //                              file_stf.cpp:129 (4)
    //         0044989a     POP        EDI
    //         0044989b     POP        ESI
    //         0044989c     POP        EBX
    //         0044989d     RET
}

// Offset: 0x004498A0
int numberOfFilesWithFilename(DriveInformation* this_, char* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall DriveInformation::numberOfFilesWithFilename(char *)                            *
    //                              *********************************************************************************************************
    //                              int __thiscall numberOfFilesWithFilename(DriveInformation * this, ch
    //              int               EAX:4          <RETURN>
    //              DriveInformati    ECX:4 (auto)   this
    //              char *            Stack[0x4]:4   param_1                   XREF[1]:     004498a0(R)  
    //              _finddata_t       Stack[-0x11c   fileInfo                  XREF[0,3]:   004498aa(*), 004498cc(*), 004498e5(*)  
    //                               ?numberOfFilesWithFilename@DriveInformation@@QAEHPAD@Z
    //                               DriveInformation::numberOfFilesWithFilename
    //                              file_stf.cpp:134 (32)
    //         004498a0     MOV        this,dword ptr [ESP + param_1]
    //         004498a4     SUB        ESP,0x118
    //         004498aa     LEA        EAX=>fileInfo.time_create,[ESP]
    //         004498ae     PUSH       ESI
    //         004498af     PUSH       EAX
    //         004498b0     PUSH       this
    //         004498b1     CALL       __findfirst                                      undefined __findfirst()
    //         004498b6     MOV        ESI,EAX
    //         004498b8     ADD        ESP,0x8
    //         004498bb     CMP        ESI,-0x1
    //         004498be     JNZ        LAB_004498cc
    //                              file_stf.cpp:140 (2)
    //         004498c0     XOR        EAX,EAX
    //                              file_stf.cpp:145 (10)
    //         004498c2     POP        ESI
    //         004498c3     ADD        ESP,0x118
    //         004498c9     RET        0x4
    //                               LAB_004498cc                                                 XREF[1]:     004498be(j)  
    //                              file_stf.cpp:142 (29)
    //         004498cc     LEA        EDX=>fileInfo.time_create,[ESP + 0x4]
    //         004498d0     PUSH       EDI
    //         004498d1     PUSH       EDX
    //         004498d2     PUSH       ESI
    //         004498d3     MOV        EDI,0x1
    //         004498d8     CALL       __findnext                                       undefined __findnext()
    //         004498dd     ADD        ESP,0x8
    //         004498e0     CMP        EAX,-0x1
    //         004498e3     JZ         LAB_004498f9
    //                               LAB_004498e5                                                 XREF[1]:     004498f7(j)  
    //         004498e5     LEA        EAX=>fileInfo.time_create,[ESP + 0x8]
    //                              file_stf.cpp:143 (16)
    //         004498e9     INC        EDI
    //         004498ea     PUSH       EAX
    //         004498eb     PUSH       ESI
    //         004498ec     CALL       __findnext                                       undefined __findnext()
    //         004498f1     ADD        ESP,0x8
    //         004498f4     CMP        EAX,-0x1
    //         004498f7     JNZ        LAB_004498e5
    //                               LAB_004498f9                                                 XREF[1]:     004498e3(j)  
    //                              file_stf.cpp:144 (3)
    //         004498f9     MOV        EAX,EDI
    //         004498fb     POP        EDI
    //                              file_stf.cpp:145 (10)
    //         004498fc     POP        ESI
    //         004498fd     ADD        ESP,0x118
    //         00449903     RET        0x4
}

// Offset: 0x00449910
int numberOfFilesWithAttribute(DriveInformation* this_, int param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall DriveInformation::numberOfFilesWithAttribute(int)                              *
    //                              *********************************************************************************************************
    //                              int __thiscall numberOfFilesWithAttribute(DriveInformation * this, i
    //              int               EAX:4          <RETURN>
    //              DriveInformati    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     00449956(R)  
    //              _finddata_t       Stack[-0x11c   fileInfo                  XREF[0,4]:   00449916(*), 0044993c(*), 0044995d(R), 00449964(*)  
    //                               ?numberOfFilesWithAttribute@DriveInformation@@QAEHH@Z
    //                               DriveInformation::numberOfFilesWithAttribute
    //                              file_stf.cpp:150 (6)
    //         00449910     SUB        ESP,0x118
    //                              file_stf.cpp:155 (26)
    //         00449916     LEA        EAX=>fileInfo.time_create,[ESP]
    //         0044991a     PUSH       ESI
    //         0044991b     PUSH       EAX
    //         0044991c     PUSH       s_*.*                                            = "*.*"
    //         00449921     CALL       __findfirst                                      undefined __findfirst()
    //         00449926     MOV        ESI,EAX
    //         00449928     ADD        ESP,0x8
    //         0044992b     CMP        ESI,-0x1
    //         0044992e     JNZ        LAB_0044993c
    //                              file_stf.cpp:156 (2)
    //         00449930     XOR        EAX,EAX
    //                              file_stf.cpp:162 (10)
    //         00449932     POP        ESI
    //         00449933     ADD        ESP,0x118
    //         00449939     RET        0x4
    //                               LAB_0044993c                                                 XREF[1]:     0044992e(j)  
    //                              file_stf.cpp:158 (33)
    //         0044993c     LEA        this=>fileInfo.time_create,[ESP + 0x4]
    //         00449940     PUSH       EDI
    //         00449941     PUSH       this
    //         00449942     PUSH       ESI
    //         00449943     MOV        EDI,0x1
    //         00449948     CALL       __findnext                                       undefined __findnext()
    //         0044994d     ADD        ESP,0x8
    //         00449950     CMP        EAX,-0x1
    //         00449953     JZ         LAB_00449978
    //         00449955     PUSH       EBX
    //         00449956     MOV        EBX,dword ptr [ESP + param_1]
    //                               LAB_0044995d                                                 XREF[1]:     00449975(j)  
    //                              file_stf.cpp:159 (6)
    //         0044995d     TEST       dword ptr [ESP + fileInfo.time_create],EBX
    //         00449961     JZ         LAB_00449964
    //                              file_stf.cpp:160 (1)
    //         00449963     INC        EDI
    //                               LAB_00449964                                                 XREF[1]:     00449961(j)  
    //                              file_stf.cpp:158 (19)
    //         00449964     LEA        EDX=>fileInfo.time_create,[ESP + 0xc]
    //         00449968     PUSH       EDX
    //         00449969     PUSH       ESI
    //         0044996a     CALL       __findnext                                       undefined __findnext()
    //         0044996f     ADD        ESP,0x8
    //         00449972     CMP        EAX,-0x1
    //         00449975     JNZ        LAB_0044995d
    //                              file_stf.cpp:150 (1)
    //         00449977     POP        EBX
    //                               LAB_00449978                                                 XREF[1]:     00449953(j)  
    //                              file_stf.cpp:161 (3)
    //         00449978     MOV        EAX,EDI
    //         0044997a     POP        EDI
    //                              file_stf.cpp:162 (10)
    //         0044997b     POP        ESI
    //         0044997c     ADD        ESP,0x118
    //         00449982     RET        0x4
}

// Offset: 0x00449990
int numberOfFilesWithFilenameOrAttribute(DriveInformation* this_, char* param_2, int param_3) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall DriveInformation::numberOfFilesWithFilenameOrAttribute(char *,int)             *
    //                              *********************************************************************************************************
    //                              int __thiscall numberOfFilesWithFilenameOrAttribute(DriveInformation
    //              int               EAX:4          <RETURN>
    //              DriveInformati    ECX:4 (auto)   this
    //              char *            Stack[0x4]:4   param_1                   XREF[1]:     004499d6(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     004499de(R)  
    //              _finddata_t       Stack[-0x11c   fileInfo                  XREF[0,5]:   00449996(*), 004499bc(*), 004499e5(R), 004499fe(*), 
    //                                                                                     004499eb(*)  
    //                               ?numberOfFilesWithFilenameOrAttribute@DriveInformation@@QAE
    //                               DriveInformation::numberOfFilesWithFilenameOrAttribute
    //                              file_stf.cpp:167 (6)
    //         00449990     SUB        ESP,0x118
    //                              file_stf.cpp:173 (26)
    //         00449996     LEA        EAX=>fileInfo.time_create,[ESP]
    //         0044999a     PUSH       ESI
    //         0044999b     PUSH       EAX
    //         0044999c     PUSH       s_*.*                                            = "*.*"
    //         004499a1     CALL       __findfirst                                      undefined __findfirst()
    //         004499a6     MOV        ESI,EAX
    //         004499a8     ADD        ESP,0x8
    //         004499ab     CMP        ESI,-0x1
    //         004499ae     JNZ        LAB_004499bc
    //                              file_stf.cpp:174 (2)
    //         004499b0     XOR        EAX,EAX
    //                              file_stf.cpp:180 (10)
    //         004499b2     POP        ESI
    //         004499b3     ADD        ESP,0x118
    //         004499b9     RET        0x8
    //                               LAB_004499bc                                                 XREF[1]:     004499ae(j)  
    //                              file_stf.cpp:176 (41)
    //         004499bc     LEA        this=>fileInfo.time_create,[ESP + 0x4]
    //         004499c0     PUSH       EDI
    //         004499c1     PUSH       this
    //         004499c2     PUSH       ESI
    //         004499c3     MOV        EDI,0x1
    //         004499c8     CALL       __findnext                                       undefined __findnext()
    //         004499cd     ADD        ESP,0x8
    //         004499d0     CMP        EAX,-0x1
    //         004499d3     JZ         LAB_00449a13
    //         004499d5     PUSH       EBP
    //         004499d6     MOV        EBP,dword ptr [ESP + param_1]
    //         004499dd     PUSH       EBX
    //         004499de     MOV        EBX,dword ptr [ESP + param_2]
    //                               LAB_004499e5                                                 XREF[1]:     00449a0f(j)  
    //                              file_stf.cpp:177 (24)
    //         004499e5     TEST       dword ptr [ESP + fileInfo.time_create],EBX
    //         004499e9     JNZ        LAB_004499fd
    //         004499eb     LEA        EDX=>fileInfo+0x18,[ESP + 0x24]
    //         004499ef     PUSH       EBP
    //         004499f0     PUSH       EDX
    //         004499f1     CALL       strstr                                           undefined strstr()
    //         004499f6     ADD        ESP,0x8
    //         004499f9     TEST       EAX,EAX
    //         004499fb     JZ         LAB_004499fe
    //                               LAB_004499fd                                                 XREF[1]:     004499e9(j)  
    //                              file_stf.cpp:178 (1)
    //         004499fd     INC        EDI
    //                               LAB_004499fe                                                 XREF[1]:     004499fb(j)  
    //                              file_stf.cpp:176 (21)
    //         004499fe     LEA        EAX=>fileInfo.time_create,[ESP + 0x10]
    //         00449a02     PUSH       EAX
    //         00449a03     PUSH       ESI
    //         00449a04     CALL       __findnext                                       undefined __findnext()
    //         00449a09     ADD        ESP,0x8
    //         00449a0c     CMP        EAX,-0x1
    //         00449a0f     JNZ        LAB_004499e5
    //         00449a11     POP        EBX
    //         00449a12     POP        EBP
    //                               LAB_00449a13                                                 XREF[1]:     004499d3(j)  
    //                              file_stf.cpp:179 (3)
    //         00449a13     MOV        EAX,EDI
    //         00449a15     POP        EDI
    //                              file_stf.cpp:180 (10)
    //         00449a16     POP        ESI
    //         00449a17     ADD        ESP,0x118
    //         00449a1d     RET        0x8
}

// Offset: 0x00449A20
int resetCurrentDriveAndDirectory(DriveInformation* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall DriveInformation::resetCurrentDriveAndDirectory(void)                          *
    //                              *********************************************************************************************************
    //                              int __thiscall resetCurrentDriveAndDirectory(DriveInformation * this)
    //              int               EAX:4          <RETURN>
    //              DriveInformati    ECX:4 (auto)   this
    //                               ?resetCurrentDriveAndDirectory@DriveInformation@@QAEHXZ
    //                               DriveInformation::resetCurrentDriveAndDirectory
    //                              file_stf.cpp:185 (3)
    //         00449a20     PUSH       ESI
    //         00449a21     MOV        ESI,this
    //                              file_stf.cpp:186 (9)
    //         00449a23     CALL       DriveInformation::resetCurrentDrive              int resetCurrentDrive(DriveInformation * this)
    //         00449a28     TEST       EAX,EAX
    //         00449a2a     JZ         LAB_00449a35
    //                              file_stf.cpp:187 (7)
    //         00449a2c     MOV        this,ESI
    //         00449a2e     CALL       DriveInformation::resetCurrentDirectory          int resetCurrentDirectory(DriveInformation * 
    //                              file_stf.cpp:189 (2)
    //         00449a33     POP        ESI
    //         00449a34     RET
    //                               LAB_00449a35                                                 XREF[1]:     00449a2a(j)  
    //                              file_stf.cpp:188 (2)
    //         00449a35     XOR        EAX,EAX
    //                              file_stf.cpp:189 (2)
    //         00449a37     POP        ESI
    //         00449a38     RET
}

// Offset: 0x00449A40
int resetCurrentDrive(DriveInformation* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall DriveInformation::resetCurrentDrive(void)                                      *
    //                              *********************************************************************************************************
    //                              int __thiscall resetCurrentDrive(DriveInformation * this)
    //              int               EAX:4          <RETURN>
    //              DriveInformati    ECX:4 (auto)   this
    //                               ?resetCurrentDrive@DriveInformation@@QAEHXZ                  XREF[1]:     resetCurrentDriveAndDirectory:0044
    //                               DriveInformation::resetCurrentDrive
    //                              file_stf.cpp:194 (8)
    //         00449a40     MOV        EAX,dword ptr [this->initialDriveValue]
    //         00449a42     PUSH       EAX
    //         00449a43     CALL       DriveInformation::changeDrive                    int changeDrive(DriveInformation * this, int 
    //                              file_stf.cpp:196 (1)
    //         00449a48     RET
}

// Offset: 0x00449A50
int resetCurrentDirectory(DriveInformation* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall DriveInformation::resetCurrentDirectory(void)                                  *
    //                              *********************************************************************************************************
    //                              int __thiscall resetCurrentDirectory(DriveInformation * this)
    //              int               EAX:4          <RETURN>
    //              DriveInformati    ECX:4 (auto)   this
    //                               ?resetCurrentDirectory@DriveInformation@@QAEHXZ              XREF[1]:     resetCurrentDriveAndDirectory:0044
    //                               DriveInformation::resetCurrentDirectory
    //                              file_stf.cpp:201 (9)
    //         00449a50     LEA        EAX,[ECX + this->initialDirectoryValue[0]]
    //         00449a53     PUSH       EAX
    //         00449a54     CALL       DriveInformation::changeDirectory                int changeDirectory(DriveInformation * this, 
    //                              file_stf.cpp:203 (1)
    //         00449a59     RET
}

// Offset: 0x00449A60
int changeDrive(DriveInformation* this_, int param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall DriveInformation::changeDrive(int)                                             *
    //                              *********************************************************************************************************
    //                              int __thiscall changeDrive(DriveInformation * this, int param_1)
    //              int               EAX:4          <RETURN>
    //              DriveInformati    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     00449a62(R)  
    //                               ?changeDrive@DriveInformation@@QAEHH@Z                       XREF[1]:     resetCurrentDrive:00449a43(c)  
    //                               DriveInformation::changeDrive
    //                              file_stf.cpp:208 (2)
    //         00449a60     PUSH       ESI
    //         00449a61     PUSH       EDI
    //                              file_stf.cpp:209 (19)
    //         00449a62     MOV        EDI,dword ptr [ESP + param_1]
    //         00449a66     MOV        ESI,this
    //         00449a68     PUSH       EDI
    //         00449a69     CALL       __chdrive                                        undefined __chdrive()
    //         00449a6e     ADD        ESP,0x4
    //         00449a71     TEST       EAX,EAX
    //         00449a73     JNZ        LAB_00449a85
    //                              file_stf.cpp:210 (6)
    //         00449a75     MOV        dword ptr [ESI + 0x104],EDI
    //                              file_stf.cpp:211 (5)
    //         00449a7b     MOV        EAX,0x1
    //                              file_stf.cpp:214 (12)
    //         00449a80     POP        EDI
    //         00449a81     POP        ESI
    //         00449a82     RET        0x4
    //                               LAB_00449a85                                                 XREF[1]:     00449a73(j)  
    //         00449a85     POP        EDI
    //         00449a86     XOR        EAX,EAX
    //         00449a88     POP        ESI
    //         00449a89     RET        0x4
}

// Offset: 0x00449A90
int changeDirectory(DriveInformation* this_, char* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall DriveInformation::changeDirectory(char *)                                      *
    //                              *********************************************************************************************************
    //                              int __thiscall changeDirectory(DriveInformation * this, char * param
    //              int               EAX:4          <RETURN>
    //              DriveInformati    ECX:4 (auto)   this
    //              char *            Stack[0x4]:4   param_1                   XREF[1]:     00449a90(R)  
    //                               ?changeDirectory@DriveInformation@@QAEHPAD@Z                 XREF[1]:     resetCurrentDirectory:00449a54(c)  
    //                               DriveInformation::changeDirectory
    //                              file_stf.cpp:219 (20)
    //         00449a90     MOV        EAX,dword ptr [ESP + param_1]
    //         00449a94     PUSH       ESI
    //         00449a95     MOV        ESI,this
    //         00449a97     PUSH       EAX
    //         00449a98     CALL       __chdir                                          undefined __chdir()
    //         00449a9d     ADD        ESP,0x4
    //         00449aa0     TEST       EAX,EAX
    //         00449aa2     JNZ        LAB_00449ab4
    //                              file_stf.cpp:221 (7)
    //         00449aa4     MOV        this,ESI
    //         00449aa6     CALL       DriveInformation::updateDirectory                void updateDirectory(DriveInformation * this)
    //                              file_stf.cpp:222 (5)
    //         00449aab     MOV        EAX,0x1
    //                              file_stf.cpp:225 (4)
    //         00449ab0     POP        ESI
    //         00449ab1     RET        0x4
    //                               LAB_00449ab4                                                 XREF[1]:     00449aa2(j)  
    //                              file_stf.cpp:224 (2)
    //         00449ab4     XOR        EAX,EAX
    //                              file_stf.cpp:225 (4)
    //         00449ab6     POP        ESI
    //         00449ab7     RET        0x4
}

// Offset: 0x00449AC0
void updateDirectory(DriveInformation* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * protected: void __thiscall DriveInformation::updateDirectory(void)                                    *
    //                              *********************************************************************************************************
    //                              void __thiscall updateDirectory(DriveInformation * this)
    //              void              <VOID>         <RETURN>
    //              DriveInformati    ECX:4 (auto)   this
    //              char[260]         Stack[-0x108   fullPath                  XREF[0,2]:   00449ac6(*), 00449af6(*)  
    //              char[256]         Stack[-0x208   filename                  XREF[0,2]:   00449ae2(*), 00449b0b(*)  
    //              char[256]         Stack[-0x308   extension                 XREF[1,2]:   00449af1(*), 00449ade(*), 00449b07(*)  
    //              char[3]           Stack[-0x30c   cDrive
    //                               ?updateDirectory@DriveInformation@@IAEXXZ                    XREF[2]:     DriveInformation:00449784(c), 
    //                               DriveInformation::updateDirectory                                         changeDirectory:00449aa6(c)  
    //                              file_stf.cpp:230 (6)
    //         00449ac0     SUB        ESP,0x308
    //                              file_stf.cpp:235 (24)
    //         00449ac6     LEA        EAX=>fullPath[4],[ESP + 0x204]
    //         00449acd     PUSH       ESI
    //         00449ace     PUSH       0x104
    //         00449ad3     MOV        ESI,this
    //         00449ad5     PUSH       EAX
    //         00449ad6     CALL       __getcwd                                         undefined __getcwd()
    //         00449adb     ADD        ESP,0x8
    //                              file_stf.cpp:236 (41)
    //         00449ade     LEA        this=>extension[4],[ESP + 0x8]
    //         00449ae2     LEA        EDX=>filename[4],[ESP + 0x108]
    //         00449ae9     ADD        ESI,0x108
    //         00449aef     PUSH       this
    //         00449af0     PUSH       EDX
    //         00449af1     LEA        EAX=>extension,[ESP + 0xc]
    //         00449af5     PUSH       ESI
    //         00449af6     LEA        this=>fullPath[4],[ESP + 0x214]
    //         00449afd     PUSH       EAX
    //         00449afe     PUSH       this
    //         00449aff     CALL       __splitpath                                      undefined __splitpath()
    //         00449b04     ADD        ESP,0x14
    //                              file_stf.cpp:238 (28)
    //         00449b07     LEA        EDX=>extension[4],[ESP + 0x8]
    //         00449b0b     LEA        EAX=>filename[4],[ESP + 0x108]
    //         00449b12     PUSH       EDX
    //         00449b13     PUSH       EAX
    //         00449b14     PUSH       ESI
    //         00449b15     PUSH       s_%s%s%s                                         = "%s%s%s"
    //         00449b1a     PUSH       ESI
    //         00449b1b     CALL       sprintf                                          undefined sprintf()
    //         00449b20     ADD        ESP,0x14
    //                              file_stf.cpp:239 (8)
    //         00449b23     POP        ESI
    //         00449b24     ADD        ESP,0x308
    //         00449b2a     RET
}

