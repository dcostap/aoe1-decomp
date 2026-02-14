// Auto-generated scaffold unit: sounddrv.cpp.asm
// SourceMap: C:/msdev/work/age1_x1/Sounddrv.cpp
#include "../include/common.h"

// Offset: 0x004BC590
undefined TSound_Driver(TSound_Driver* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall TSound_Driver::TSound_Driver(void)                                                 *
    //                              *********************************************************************************************************
    //                              undefined __thiscall TSound_Driver(TSound_Driver * this)
    //              undefined         <UNASSIGNED>   <RETURN>
    //              TSound_Driver *   ECX:4 (auto)   this
    //                               ??0TSound_Driver@@QAE@XZ
    //                               TSound_Driver::TSound_Driver
    //                              Sounddrv.cpp:33 (3)
    //         004bc590     PUSH       ESI
    //         004bc591     MOV        ESI,this
    //                              Sounddrv.cpp:34 (5)
    //         004bc593     CALL       TSound_Driver::init_vars                         void init_vars(TSound_Driver * this)
    //                              Sounddrv.cpp:35 (4)
    //         004bc598     MOV        EAX,ESI
    //         004bc59a     POP        ESI
    //         004bc59b     RET
}

// Offset: 0x004BC5A0
undefined TSound_Driver(TSound_Driver* this_, void* param_2, char* param_3) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall TSound_Driver::TSound_Driver(void *,char *)                                        *
    //                              *********************************************************************************************************
    //                              undefined __thiscall TSound_Driver(TSound_Driver * this, void * para
    //              undefined         <UNASSIGNED>   <RETURN>
    //              TSound_Driver *   ECX:4 (auto)   this
    //              void *            Stack[0x4]:4   param_1                   XREF[1]:     004bc5ac(R)  
    //              char *            Stack[0x8]:4   param_2                   XREF[1]:     004bc5a8(R)  
    //                               ??0TSound_Driver@@QAE@PAXPAD@Z                               XREF[1]:     setup_sound_system:0041f085(c)  
    //                               TSound_Driver::TSound_Driver
    //                              Sounddrv.cpp:39 (3)
    //         004bc5a0     PUSH       ESI
    //         004bc5a1     MOV        ESI,this
    //                              Sounddrv.cpp:40 (5)
    //         004bc5a3     CALL       TSound_Driver::init_vars                         void init_vars(TSound_Driver * this)
    //                              Sounddrv.cpp:41 (17)
    //         004bc5a8     MOV        EAX,dword ptr [ESP + param_2]
    //         004bc5ac     MOV        this,dword ptr [ESP + param_1]
    //         004bc5b0     PUSH       EAX
    //         004bc5b1     PUSH       this
    //         004bc5b2     MOV        this,ESI
    //         004bc5b4     CALL       TSound_Driver::init                              int init(TSound_Driver * this, void * param_1
    //                              Sounddrv.cpp:42 (6)
    //         004bc5b9     MOV        EAX,ESI
    //         004bc5bb     POP        ESI
    //         004bc5bc     RET        0x8
}

// Offset: 0x004BC5C0
void TSound_Driver(TSound_Driver* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall TSound_Driver::~TSound_Driver(void)                                                *
    //                              *********************************************************************************************************
    //                              void __thiscall ~TSound_Driver(TSound_Driver * this)
    //              void              <VOID>         <RETURN>
    //              TSound_Driver *   ECX:4 (auto)   this
    //                               ??1TSound_Driver@@QAE@XZ                                     XREF[2]:     setup_sound_system:0041f0b1(c), 
    //                               TSound_Driver::~TSound_Driver                                             stop_sound_system:0041f8f2(c)  
    //                              Sounddrv.cpp:46 (5)
    //         004bc5c0     JMP        TSound_Driver::exit
}

// Offset: 0x004BC5D0
void init_vars(TSound_Driver* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TSound_Driver::init_vars(void)                                                *
    //                              *********************************************************************************************************
    //                              void __thiscall init_vars(TSound_Driver * this)
    //              void              <VOID>         <RETURN>
    //              TSound_Driver *   ECX:4 (auto)   this
    //                               ?init_vars@TSound_Driver@@QAEXXZ                             XREF[2]:     TSound_Driver:004bc593(c), 
    //                               TSound_Driver::init_vars                                                  TSound_Driver:004bc5a3(c)  
    //                              Sounddrv.cpp:52 (2)
    //         004bc5d0     XOR        EAX,EAX
    //                              Sounddrv.cpp:60 (30)
    //         004bc5d2     MOV        dword ptr [ECX + this->start_volume],0x1
    //         004bc5d9     MOV        byte ptr [this->ready],AL
    //         004bc5db     MOV        dword ptr [ECX + this->main_wnd],EAX
    //         004bc5de     MOV        dword ptr [ECX + this->direct_sound],EAX
    //         004bc5e1     MOV        dword ptr [ECX + this->primary_buffer],EAX
    //         004bc5e4     MOV        dword ptr [ECX + this->dsrval],EAX
    //         004bc5e7     MOV        byte ptr [ECX + this->mute],AL
    //         004bc5ea     MOV        dword ptr [ECX + this->play_list_count],EAX
    //                              Sounddrv.cpp:61 (3)
    //         004bc5f0     MOV        dword ptr [ECX + this->volume],EAX
    //                              Sounddrv.cpp:62 (6)
    //         004bc5f3     MOV        dword ptr [ECX + this->mixer_open],EAX
    //                              Sounddrv.cpp:63 (6)
    //         004bc5f9     MOV        dword ptr [ECX + this->mixer_handle],EAX
    //                              Sounddrv.cpp:64 (3)
    //         004bc5ff     MOV        byte ptr [ECX + this->path[0]],AL
    //                              Sounddrv.cpp:65 (1)
    //         004bc602     RET
}

// Offset: 0x004BC610
int init(TSound_Driver* this_, void* param_2, char* param_3) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall TSound_Driver::init(void *,char *)                                             *
    //                              *********************************************************************************************************
    //                              int __thiscall init(TSound_Driver * this, void * param_1, char * par
    //              int               EAX:4          <RETURN>
    //              TSound_Driver *   ECX:4 (auto)   this
    //              void *            Stack[0x4]:4   param_1                   XREF[1]:     004bc626(R)  
    //              char *            Stack[0x8]:4   param_2                   XREF[1]:     004bc610(R)  
    //              _DSCAPS           Stack[-0x64]   dscaps                    XREF[0,2]:   004bc658(*), 004bc660(W)  
    //              _DSBUFFERDESC     Stack[-0x78]   dsBD
    //              tWAVEFORMATEX     Stack[-0x8c]   fmt
    //                               ?init@TSound_Driver@@QAEHPAXPAD@Z                            XREF[1]:     TSound_Driver:004bc5b4(c)  
    //                               TSound_Driver::init
    //                              Sounddrv.cpp:69 (22)
    //         004bc610     MOV        EAX,dword ptr [ESP + param_2]
    //         004bc614     SUB        ESP,0x88
    //         004bc61a     PUSH       EBX
    //         004bc61b     PUSH       EBP
    //         004bc61c     PUSH       ESI
    //         004bc61d     PUSH       EDI
    //         004bc61e     MOV        ESI,this
    //         004bc620     PUSH       EAX
    //         004bc621     CALL       TSound_Driver::set_path                          void set_path(TSound_Driver * this, char * pa
    //                              Sounddrv.cpp:75 (7)
    //         004bc626     MOV        this,dword ptr [ESP + param_1]
    //                              Sounddrv.cpp:78 (19)
    //         004bc62d     LEA        EDI,[ESI + 0x8]
    //         004bc630     PUSH       0x0
    //         004bc632     PUSH       EDI
    //         004bc633     PUSH       0x0
    //         004bc635     MOV        dword ptr [ESI + 0x4],this
    //         004bc638     MOV        byte ptr [ESI],0x0
    //         004bc63b     CALL       _DirectSoundCreate@12                            undefined _DirectSoundCreate@12()
    //                              Sounddrv.cpp:79 (7)
    //         004bc640     TEST       EAX,EAX
    //         004bc642     MOV        dword ptr [ESI + 0x10],EAX
    //         004bc645     JZ         LAB_004bc656
    //                              Sounddrv.cpp:80 (2)
    //         004bc647     XOR        EAX,EAX
    //                              Sounddrv.cpp:169 (13)
    //         004bc649     POP        EDI
    //         004bc64a     POP        ESI
    //         004bc64b     POP        EBP
    //         004bc64c     POP        EBX
    //         004bc64d     ADD        ESP,0x88
    //         004bc653     RET        0x8
    //                               LAB_004bc656                                                 XREF[1]:     004bc645(j)  
    //                              Sounddrv.cpp:82 (21)
    //         004bc656     MOV        EAX,dword ptr [EDI]
    //         004bc658     LEA        this=>dscaps.dwFlags,[ESP + 0x38]
    //         004bc65c     PUSH       this
    //         004bc65d     PUSH       EAX
    //         004bc65e     MOV        EDX,dword ptr [EAX]
    //         004bc660     MOV        dword ptr [ESP + dscaps.dwFlags],0x60
    //         004bc668     CALL       dword ptr [EDX + 0x10]
    //                              Sounddrv.cpp:86 (8)
    //         004bc66b     MOV        AL,byte ptr [ESP + 0x3c]
    //         004bc66f     XOR        EBP,EBP
    //         004bc671     TEST       AL,0x8
    //                              Sounddrv.cpp:89 (16)
    //         004bc673     MOV        EAX,dword ptr [EDI]
    //         004bc675     MOV        EDX,dword ptr [EAX]
    //         004bc677     JZ         LAB_004bc692
    //         004bc679     MOV        this,dword ptr [ESI + 0x4]
    //         004bc67c     PUSH       0x2
    //         004bc67e     PUSH       this=>DAT_fffffff8
    //         004bc67f     PUSH       EAX=>DAT_fffffff4
    //         004bc680     CALL       dword ptr [EDX + 0x18]
    //                              Sounddrv.cpp:90 (11)
    //         004bc683     TEST       EAX,EAX
    //         004bc685     MOV        dword ptr [ESI + 0x10],EAX
    //         004bc688     JZ         LAB_004bc7aa
    //                              Sounddrv.cpp:91 (4)
    //         004bc68e     MOV        EAX,dword ptr [EDI]
    //         004bc690     MOV        EDX,dword ptr [EAX]
    //                               LAB_004bc692                                                 XREF[1]:     004bc677(j)  
    //                              Sounddrv.cpp:98 (13)
    //         004bc692     MOV        this,dword ptr [ESI + 0x4]
    //         004bc695     PUSH       0x1
    //         004bc697     PUSH       this=>DAT_fffffff8
    //         004bc698     PUSH       EAX=>DAT_fffffff4
    //         004bc699     CALL       dword ptr [EDX + 0x18]
    //         004bc69c     MOV        dword ptr [ESI + 0x10],EAX
    //                               LAB_004bc69f                                                 XREF[1]:     004bc7af(j)  
    //                              Sounddrv.cpp:101 (7)
    //         004bc69f     MOV        EAX,dword ptr [ESI + 0x10]
    //         004bc6a2     TEST       EAX,EAX
    //         004bc6a4     JZ         LAB_004bc6c3
    //                              Sounddrv.cpp:103 (8)
    //         004bc6a6     MOV        EAX,dword ptr [EDI]
    //         004bc6a8     PUSH       EAX
    //         004bc6a9     MOV        EDX,dword ptr [EAX]
    //         004bc6ab     CALL       dword ptr [EDX + 0x8]
    //                              Sounddrv.cpp:104 (6)
    //         004bc6ae     MOV        dword ptr [EDI],0x0
    //                              Sounddrv.cpp:105 (2)
    //         004bc6b4     XOR        EAX,EAX
    //                              Sounddrv.cpp:169 (13)
    //         004bc6b6     POP        EDI
    //         004bc6b7     POP        ESI
    //         004bc6b8     POP        EBP
    //         004bc6b9     POP        EBX
    //         004bc6ba     ADD        ESP,0x88
    //         004bc6c0     RET        0x8
    //                               LAB_004bc6c3                                                 XREF[1]:     004bc6a4(j)  
    //                              Sounddrv.cpp:115 (2)
    //         004bc6c3     XOR        EAX,EAX
    //                              Sounddrv.cpp:119 (55)
    //         004bc6c5     LEA        EBX,[ESI + 0xc]
    //         004bc6c8     MOV        dword ptr [ESP + 0x24],EAX
    //         004bc6cc     PUSH       0x0
    //         004bc6ce     MOV        dword ptr [ESP + 0x2c],EAX
    //         004bc6d2     LEA        EDX,[ESP + 0x28]
    //         004bc6d6     MOV        dword ptr [ESP + 0x30],EAX
    //         004bc6da     PUSH       EBX=>DAT_fffffff8
    //         004bc6db     MOV        dword ptr [ESP + 0x38],EAX
    //         004bc6df     PUSH       EDX=>DAT_fffffff4
    //         004bc6e0     MOV        dword ptr [ESP + 0x40],EAX
    //         004bc6e4     MOV        EAX,dword ptr [EDI]
    //         004bc6e6     PUSH       EAX=>DAT_fffffff0
    //         004bc6e7     MOV        dword ptr [ESP + 0x34],0x14
    //         004bc6ef     MOV        this,dword ptr [EAX]
    //         004bc6f1     MOV        dword ptr [ESP + 0x38],0x1
    //         004bc6f9     CALL       dword ptr [ECX + this->primary_buffer]
    //                              Sounddrv.cpp:121 (5)
    //         004bc6fc     TEST       EAX,EAX
    //         004bc6fe     MOV        dword ptr [ESI + 0x10],EAX
    //                              Sounddrv.cpp:125 (2)
    //         004bc701     JNZ        LAB_004bc760
    //                              Sounddrv.cpp:128 (4)
    //         004bc703     TEST       EBP,EBP
    //         004bc705     JZ         LAB_004bc74b
    //                              Sounddrv.cpp:131 (5)
    //         004bc707     MOV        EAX,0x1
    //                              Sounddrv.cpp:139 (63)
    //         004bc70c     LEA        this,[ESP + 0x10]
    //         004bc710     MOV        word ptr [ESP + 0x10],AX
    //         004bc715     MOV        word ptr [ESP + 0x12],AX
    //         004bc71a     MOV        EAX,dword ptr [EBX]
    //         004bc71c     PUSH       this
    //         004bc71d     PUSH       EAX=>DAT_fffffff8
    //         004bc71e     MOV        dword ptr [ESP + 0x1c],0x5622
    //         004bc726     MOV        EDX,dword ptr [EAX]
    //         004bc728     MOV        dword ptr [ESP + 0x20],0xac44
    //         004bc730     MOV        word ptr [ESP + 0x24],0x2
    //         004bc737     MOV        word ptr [ESP + 0x26],0x10
    //         004bc73e     MOV        word ptr [ESP + 0x28],0x0
    //         004bc745     CALL       dword ptr [EDX + 0x38]
    //         004bc748     MOV        dword ptr [ESI + 0x10],EAX
    //                               LAB_004bc74b                                                 XREF[1]:     004bc705(j)  
    //                              Sounddrv.cpp:152 (14)
    //         004bc74b     MOV        EAX,dword ptr [EBX]
    //         004bc74d     PUSH       0x1
    //         004bc74f     PUSH       0x0=>DAT_fffffff8
    //         004bc751     PUSH       0x0=>DAT_fffffff4
    //         004bc753     MOV        EDX,dword ptr [EAX]
    //         004bc755     PUSH       EAX=>DAT_fffffff0
    //         004bc756     CALL       dword ptr [EDX + 0x30]
    //                              Sounddrv.cpp:153 (7)
    //         004bc759     TEST       EAX,EAX
    //         004bc75b     MOV        dword ptr [ESI + 0x10],EAX
    //         004bc75e     JZ         LAB_004bc77d
    //                               LAB_004bc760                                                 XREF[1]:     004bc701(j)  
    //                              Sounddrv.cpp:155 (8)
    //         004bc760     MOV        EAX,dword ptr [EDI]
    //         004bc762     PUSH       EAX
    //         004bc763     MOV        this,dword ptr [EAX]
    //         004bc765     CALL       dword ptr [ECX + this->direct_sound]
    //                              Sounddrv.cpp:156 (6)
    //         004bc768     MOV        dword ptr [EDI],0x0
    //                              Sounddrv.cpp:157 (2)
    //         004bc76e     XOR        EAX,EAX
    //                              Sounddrv.cpp:169 (13)
    //         004bc770     POP        EDI
    //         004bc771     POP        ESI
    //         004bc772     POP        EBP
    //         004bc773     POP        EBX
    //         004bc774     ADD        ESP,0x88
    //         004bc77a     RET        0x8
    //                               LAB_004bc77d                                                 XREF[1]:     004bc75e(j)  
    //                              Sounddrv.cpp:163 (21)
    //         004bc77d     MOV        EDX,dword ptr [EBX]
    //         004bc77f     MOV        EAX,dword ptr [EDI]
    //         004bc781     MOV        this,dword ptr [ESI + 0x4]
    //         004bc784     PUSH       EDX
    //         004bc785     PUSH       EAX=>DAT_fffffff8
    //         004bc786     PUSH       this=>DAT_fffffff4
    //         004bc787     MOV        byte ptr [ESI],0x1
    //         004bc78a     CALL       ds_stream_init                                   undefined ds_stream_init()
    //         004bc78f     ADD        ESP,0xc
    //                              Sounddrv.cpp:166 (7)
    //         004bc792     MOV        this,ESI
    //         004bc794     CALL       TSound_Driver::open_mixer                        int open_mixer(TSound_Driver * this)
    //                              Sounddrv.cpp:168 (2)
    //         004bc799     XOR        EAX,EAX
    //                              Sounddrv.cpp:169 (15)
    //         004bc79b     POP        EDI
    //         004bc79c     MOV        AL,byte ptr [ESI]
    //         004bc79e     POP        ESI
    //         004bc79f     POP        EBP
    //         004bc7a0     POP        EBX
    //         004bc7a1     ADD        ESP,0x88
    //         004bc7a7     RET        0x8
    //                               LAB_004bc7aa                                                 XREF[1]:     004bc688(j)  
    //                              Sounddrv.cpp:93 (5)
    //         004bc7aa     MOV        EBP,0x1
    //                              Sounddrv.cpp:95 (5)
    //         004bc7af     JMP        LAB_004bc69f
}

// Offset: 0x004BC7C0
void exit(TSound_Driver* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TSound_Driver::exit(void)                                                     *
    //                              *********************************************************************************************************
    //                              void __thiscall exit(TSound_Driver * this)
    //              void              <VOID>         <RETURN>
    //              TSound_Driver *   ECX:4 (auto)   this
    //                               ?exit@TSound_Driver@@QAEXXZ                                  XREF[1]:     exit:004bc5bf(T), 
    //                               TSound_Driver::exit                                                       ~TSound_Driver:004bc5c0(j)  
    //                              Sounddrv.cpp:173 (3)
    //         004bc7c0     PUSH       ESI
    //         004bc7c1     MOV        ESI,this
    //                              Sounddrv.cpp:174 (5)
    //         004bc7c3     CALL       TSound_Driver::close_mixer                       void close_mixer(TSound_Driver * this)
    //                              Sounddrv.cpp:176 (5)
    //         004bc7c8     CMP        byte ptr [ESI],0x0
    //         004bc7cb     JZ         LAB_004bc806
    //                              Sounddrv.cpp:179 (5)
    //         004bc7cd     CALL       ds_stream_exit                                   undefined ds_stream_exit()
    //                              Sounddrv.cpp:182 (7)
    //         004bc7d2     MOV        EAX,dword ptr [ESI + 0xc]
    //         004bc7d5     TEST       EAX,EAX
    //         004bc7d7     JZ         LAB_004bc7ef
    //                              Sounddrv.cpp:184 (6)
    //         004bc7d9     MOV        this,dword ptr [EAX]
    //         004bc7db     PUSH       EAX
    //         004bc7dc     CALL       dword ptr [ECX + this+0x48]
    //                              Sounddrv.cpp:185 (9)
    //         004bc7df     MOV        EAX,dword ptr [ESI + 0xc]
    //         004bc7e2     PUSH       EAX
    //         004bc7e3     MOV        EDX,dword ptr [EAX]
    //         004bc7e5     CALL       dword ptr [EDX + 0x8]
    //                              Sounddrv.cpp:186 (7)
    //         004bc7e8     MOV        dword ptr [ESI + 0xc],0x0
    //                               LAB_004bc7ef                                                 XREF[1]:     004bc7d7(j)  
    //                              Sounddrv.cpp:189 (7)
    //         004bc7ef     MOV        EAX,dword ptr [ESI + 0x8]
    //         004bc7f2     TEST       EAX,EAX
    //         004bc7f4     JZ         LAB_004bc803
    //                              Sounddrv.cpp:191 (6)
    //         004bc7f6     MOV        this,dword ptr [EAX]
    //         004bc7f8     PUSH       EAX
    //         004bc7f9     CALL       dword ptr [ECX + this->direct_sound]
    //                              Sounddrv.cpp:192 (7)
    //         004bc7fc     MOV        dword ptr [ESI + 0x8],0x0
    //                               LAB_004bc803                                                 XREF[1]:     004bc7f4(j)  
    //                              Sounddrv.cpp:195 (3)
    //         004bc803     MOV        byte ptr [ESI],0x0
    //                               LAB_004bc806                                                 XREF[1]:     004bc7cb(j)  
    //                              Sounddrv.cpp:197 (2)
    //         004bc806     POP        ESI
    //         004bc807     RET
}

// Offset: 0x004BC810
void set_path(TSound_Driver* this_, char* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TSound_Driver::set_path(char *)                                               *
    //                              *********************************************************************************************************
    //                              void __thiscall set_path(TSound_Driver * this, char * param_1)
    //              void              <VOID>         <RETURN>
    //              TSound_Driver *   ECX:4 (auto)   this
    //              char *            Stack[0x4]:4   param_1                   XREF[1]:     004bc811(R)  
    //                               ?set_path@TSound_Driver@@QAEXPAD@Z                           XREF[1]:     init:004bc621(c)  
    //                               TSound_Driver::set_path
    //                              Sounddrv.cpp:201 (1)
    //         004bc810     PUSH       EDI
    //                              Sounddrv.cpp:202 (8)
    //         004bc811     MOV        EDI,dword ptr [ESP + param_1]
    //         004bc815     TEST       EDI,EDI
    //         004bc817     JZ         LAB_004bc83f
    //                              Sounddrv.cpp:203 (34)
    //         004bc819     LEA        EDX,[ECX + this->path[0]]
    //         004bc81c     OR         this,0xffffffff
    //         004bc81f     XOR        EAX,EAX
    //         004bc821     PUSH       ESI
    //         004bc822     SCASB.RE   ES:EDI
    //         004bc824     NOT        this
    //         004bc826     SUB        EDI,this
    //         004bc828     MOV        EAX,this
    //         004bc82a     MOV        ESI,EDI
    //         004bc82c     MOV        EDI,EDX
    //         004bc82e     SHR        this,0x2
    //         004bc831     MOVSD.REP  ES:EDI,ESI
    //         004bc833     MOV        this,EAX
    //         004bc835     AND        this,0x3
    //         004bc838     MOVSB.REP  ES:EDI,ESI
    //         004bc83a     POP        ESI
    //                              Sounddrv.cpp:206 (4)
    //         004bc83b     POP        EDI
    //         004bc83c     RET        0x4
    //                               LAB_004bc83f                                                 XREF[1]:     004bc817(j)  
    //                              Sounddrv.cpp:205 (4)
    //         004bc83f     MOV        byte ptr [ECX + this->path[0]],0x0
    //                              Sounddrv.cpp:206 (4)
    //         004bc843     POP        EDI
    //         004bc844     RET        0x4
}

// Offset: 0x004BC850
int driver_active(TSound_Driver* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall TSound_Driver::driver_active(void)                                             *
    //                              *********************************************************************************************************
    //                              int __thiscall driver_active(TSound_Driver * this)
    //              int               EAX:4          <RETURN>
    //              TSound_Driver *   ECX:4 (auto)   this
    //                               ?driver_active@TSound_Driver@@QAEHXZ                         XREF[1]:     setup_sound_system:0041f09f(c)  
    //                               TSound_Driver::driver_active
    //                              Sounddrv.cpp:210 (4)
    //         004bc850     XOR        EAX,EAX
    //         004bc852     MOV        AL,byte ptr [this->ready]
    //                              Sounddrv.cpp:212 (1)
    //         004bc854     RET
}

// Offset: 0x004BC860
long get_volume(TSound_Driver* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: long __thiscall TSound_Driver::get_volume(void)                                               *
    //                              *********************************************************************************************************
    //                              long __thiscall get_volume(TSound_Driver * this)
    //              long              EAX:4          <RETURN>
    //              TSound_Driver *   ECX:4 (auto)   this
    //                               ?get_volume@TSound_Driver@@QAEJXZ                            XREF[2]:     stop_sound_system:0041f8cf(c), 
    //                               TSound_Driver::get_volume                                                 TribeConfigDialog:0043ba1c(c)  
    //                              Sounddrv.cpp:216 (3)
    //         004bc860     MOV        EAX,dword ptr [ECX + this->volume]
    //                              Sounddrv.cpp:218 (1)
    //         004bc863     RET
}

// Offset: 0x004BC870
void set_volume(TSound_Driver* this_, long param_2, int param_3) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TSound_Driver::set_volume(long,int)                                           *
    //                              *********************************************************************************************************
    //                              void __thiscall set_volume(TSound_Driver * this, long param_1, int p
    //              void              <VOID>         <RETURN>
    //              TSound_Driver *   ECX:4 (auto)   this
    //              long              Stack[0x4]:4   param_1                   XREF[1]:     004bc877(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     004bc870(R)  
    //                               ?set_volume@TSound_Driver@@QAEXJH@Z                          XREF[5]:     setup_sound_system:0041f0ed(c), 
    //                               TSound_Driver::set_volume                                                 action:0043c601(c), 
    //                                                                                                         action:0043c7d2(c), 
    //                                                                                                         action:0043c886(c), 
    //                                                                                                         close_mixer:004bcc08(c)  
    //                              Sounddrv.cpp:223 (15)
    //         004bc870     MOV        EAX,dword ptr [ESP + param_2]
    //         004bc874     PUSH       ESI
    //         004bc875     TEST       EAX,EAX
    //         004bc877     MOV        EAX,dword ptr [ESP + param_1]
    //         004bc87b     MOV        ESI,this
    //         004bc87d     JZ         LAB_004bc882
    //                              Sounddrv.cpp:225 (3)
    //         004bc87f     MOV        dword ptr [ESI + 0x18],EAX
    //                               LAB_004bc882                                                 XREF[1]:     004bc87d(j)  
    //                              Sounddrv.cpp:245 (10)
    //         004bc882     MOV        this,dword ptr [ESI + 0x120]
    //         004bc888     TEST       this,this
    //         004bc88a     JZ         LAB_004bc8cb
    //                              Sounddrv.cpp:249 (27)
    //         004bc88c     MOV        this,dword ptr [ESI + 0x250]
    //         004bc892     MOV        EDX,dword ptr [ESI + 0x24c]
    //         004bc898     SUB        this,EDX
    //         004bc89a     ADD        EAX,0x2710
    //         004bc89f     IMUL       this,EAX
    //         004bc8a2     MOV        EAX,0xd1b71759
    //                              Sounddrv.cpp:250 (36)
    //         004bc8a7     PUSH       0x0
    //         004bc8a9     MUL        this
    //         004bc8ab     MOV        EAX,dword ptr [ESI + 0x124]
    //         004bc8b1     SHR        EDX,0xd
    //         004bc8b4     MOV        dword ptr [ESI + 0x294],EDX
    //         004bc8ba     LEA        EDX,[ESI + 0x27c]
    //         004bc8c0     PUSH       EDX
    //         004bc8c1     PUSH       EAX
    //         004bc8c2     CALL       dword ptr [->WINMM.DLL::mixerSetControlDetails]  = 0048b5a2
    //         004bc8c8     MOV        dword ptr [ESI + 0x10],EAX
    //                               LAB_004bc8cb                                                 XREF[1]:     004bc88a(j)  
    //                              Sounddrv.cpp:252 (4)
    //         004bc8cb     POP        ESI
    //         004bc8cc     RET        0x8
}

// Offset: 0x004BC8D0
int stream_file(TSound_Driver* this_, char* param_2, int param_3, long param_4) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall TSound_Driver::stream_file(char *,int,long)                                    *
    //                              *********************************************************************************************************
    //                              int __thiscall stream_file(TSound_Driver * this, char * param_1, int
    //              int               EAX:4          <RETURN>
    //              TSound_Driver *   ECX:4 (auto)   this
    //              char *            Stack[0x4]:4   param_1                   XREF[1]:     004bc8e7(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     004bc909(R)  
    //              long              Stack[0xc]:4   param_3                   XREF[1]:     004bc902(R)  
    //              char[260]         Stack[-0x108   file_name2                XREF[0,2]:   004bc8f3(*), 004bc913(*)  
    //                               ?stream_file@TSound_Driver@@QAEHPADHJ@Z                      XREF[3]:     play:004622ec(c), 
    //                               TSound_Driver::stream_file                                                handle_terrain_sound:0049ba9b(c), 
    //                                                                                                         key_down_action:004b8b1b(c)  
    //                              Sounddrv.cpp:256 (12)
    //         004bc8d0     MOV        AL,byte ptr [this->ready]
    //         004bc8d2     SUB        ESP,0x104
    //         004bc8d8     TEST       AL,AL
    //         004bc8da     JNZ        LAB_004bc8e7
    //                              Sounddrv.cpp:261 (2)
    //         004bc8dc     XOR        EAX,EAX
    //                              Sounddrv.cpp:266 (9)
    //         004bc8de     ADD        ESP,0x104
    //         004bc8e4     RET        0xc
    //                               LAB_004bc8e7                                                 XREF[1]:     004bc8da(j)  
    //                              Sounddrv.cpp:263 (27)
    //         004bc8e7     MOV        EAX,dword ptr [ESP + param_1]
    //         004bc8ee     ADD        this,0x1c
    //         004bc8f1     PUSH       EAX
    //         004bc8f2     PUSH       this
    //         004bc8f3     LEA        this=>file_name2[4],[ESP + 0x8]
    //         004bc8f7     PUSH       s_%s%s                                           = "%s%s"
    //         004bc8fc     PUSH       this
    //         004bc8fd     CALL       sprintf                                          undefined sprintf()
    //                              Sounddrv.cpp:264 (32)
    //         004bc902     MOV        EDX,dword ptr [ESP + param_3]
    //         004bc909     MOV        EAX,dword ptr [ESP + param_2]
    //         004bc910     ADD        ESP,0x10
    //         004bc913     LEA        this=>file_name2[4],[ESP]
    //         004bc917     PUSH       EDX
    //         004bc918     PUSH       EAX
    //         004bc919     PUSH       this
    //         004bc91a     CALL       ds_stream_file                                   undefined ds_stream_file()
    //         004bc91f     ADD        ESP,0xc
    //                              Sounddrv.cpp:266 (9)
    //         004bc922     ADD        ESP,0x104
    //         004bc928     RET        0xc
}

// Offset: 0x004BC930
int set_stream_volume(TSound_Driver* this_, long param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall TSound_Driver::set_stream_volume(long)                                         *
    //                              *********************************************************************************************************
    //                              int __thiscall set_stream_volume(TSound_Driver * this, long param_1)
    //              int               EAX:4          <RETURN>
    //              TSound_Driver *   ECX:4 (auto)   this
    //              long              Stack[0x4]:4   param_1                   XREF[1]:     004bc93a(R)  
    //                               ?set_stream_volume@TSound_Driver@@QAEHJ@Z                    XREF[1]:     set_volume:00461fad(c)  
    //                               TSound_Driver::set_stream_volume
    //                              Sounddrv.cpp:271 (5)
    //         004bc930     CMP        byte ptr [this->ready],0x0
    //         004bc933     JNZ        LAB_004bc93a
    //                              Sounddrv.cpp:273 (2)
    //         004bc935     XOR        EAX,EAX
    //                              Sounddrv.cpp:275 (3)
    //         004bc937     RET        0x4
    //                               LAB_004bc93a                                                 XREF[1]:     004bc933(j)  
    //                              Sounddrv.cpp:274 (13)
    //         004bc93a     MOV        EAX,dword ptr [ESP + param_1]
    //         004bc93e     PUSH       EAX
    //         004bc93f     CALL       ds_stream_volume                                 undefined ds_stream_volume()
    //         004bc944     ADD        ESP,0x4
    //                              Sounddrv.cpp:275 (3)
    //         004bc947     RET        0x4
}

// Offset: 0x004BC950
int pause_stream(TSound_Driver* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall TSound_Driver::pause_stream(void)                                              *
    //                              *********************************************************************************************************
    //                              int __thiscall pause_stream(TSound_Driver * this)
    //              int               EAX:4          <RETURN>
    //              TSound_Driver *   ECX:4 (auto)   this
    //                               ?pause_stream@TSound_Driver@@QAEHXZ                          XREF[1]:     pause_play:0046262b(c)  
    //                               TSound_Driver::pause_stream
    //                              Sounddrv.cpp:279 (5)
    //         004bc950     CMP        byte ptr [this->ready],0x0
    //         004bc953     JNZ        LAB_004bc958
    //                              Sounddrv.cpp:281 (2)
    //         004bc955     XOR        EAX,EAX
    //                              Sounddrv.cpp:283 (1)
    //         004bc957     RET
    //                               LAB_004bc958                                                 XREF[1]:     004bc953(j)  
    //                              Sounddrv.cpp:282 (5)
    //         004bc958     JMP        ds_stream_pause                                  undefined ds_stream_pause()
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
}

// Offset: 0x004BC960
int resume_stream(TSound_Driver* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall TSound_Driver::resume_stream(void)                                             *
    //                              *********************************************************************************************************
    //                              int __thiscall resume_stream(TSound_Driver * this)
    //              int               EAX:4          <RETURN>
    //              TSound_Driver *   ECX:4 (auto)   this
    //                               ?resume_stream@TSound_Driver@@QAEHXZ                         XREF[1]:     resume_play:004626e2(c)  
    //                               TSound_Driver::resume_stream
    //                              Sounddrv.cpp:287 (5)
    //         004bc960     CMP        byte ptr [this->ready],0x0
    //         004bc963     JNZ        LAB_004bc968
    //                              Sounddrv.cpp:289 (2)
    //         004bc965     XOR        EAX,EAX
    //                              Sounddrv.cpp:291 (1)
    //         004bc967     RET
    //                               LAB_004bc968                                                 XREF[1]:     004bc963(j)  
    //                              Sounddrv.cpp:290 (5)
    //         004bc968     JMP        ds_stream_resume                                 undefined ds_stream_resume()
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
}

// Offset: 0x004BC970
int stop_stream(TSound_Driver* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall TSound_Driver::stop_stream(void)                                               *
    //                              *********************************************************************************************************
    //                              int __thiscall stop_stream(TSound_Driver * this)
    //              int               EAX:4          <RETURN>
    //              TSound_Driver *   ECX:4 (auto)   this
    //                               ?stop_stream@TSound_Driver@@QAEHXZ                           XREF[4]:     stop_playing:004627a2(c), 
    //                               TSound_Driver::stop_stream                                                handle_terrain_sound:0049b9ab(c), 
    //                                                                                                         handle_terrain_sound:0049ba88(c), 
    //                                                                                                         ~TRIBE_Mission_Screen:004b8820(c)  
    //                              Sounddrv.cpp:295 (5)
    //         004bc970     CMP        byte ptr [this->ready],0x0
    //         004bc973     JNZ        LAB_004bc978
    //                              Sounddrv.cpp:297 (2)
    //         004bc975     XOR        EAX,EAX
    //                              Sounddrv.cpp:299 (1)
    //         004bc977     RET
    //                               LAB_004bc978                                                 XREF[1]:     004bc973(j)  
    //                              Sounddrv.cpp:298 (5)
    //         004bc978     JMP        ds_stream_stop                                   undefined ds_stream_stop()
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
}

// Offset: 0x004BC980
uint handle_messages(TSound_Driver* this_, void* param_2, uint param_3, uint param_4, long param_5) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: unsigned int __thiscall TSound_Driver::handle_messages(void *,unsigned int,unsigned int,long) *
    //                              *********************************************************************************************************
    //                              uint __thiscall handle_messages(TSound_Driver * this, void * param_1
    //              uint              EAX:4          <RETURN>
    //              TSound_Driver *   ECX:4 (auto)   this
    //              void *            Stack[0x4]:4   param_1                   XREF[1]:     004bc997(R)  
    //              uint              Stack[0x8]:4   param_2                   XREF[1]:     004bc992(R)  
    //              uint              Stack[0xc]:4   param_3                   XREF[1]:     004bc98e(R)  
    //              long              Stack[0x10]:4  param_4                   XREF[1]:     004bc98a(R)  
    //                               ?handle_messages@TSound_Driver@@QAEIPAXIIJ@Z                 XREF[2]:     wnd_proc:00420732(c), 
    //                               TSound_Driver::handle_messages                                            handle_idle:00421034(c)  
    //                              Sounddrv.cpp:303 (5)
    //         004bc980     CMP        byte ptr [this->ready],0x0
    //         004bc983     JNZ        LAB_004bc98a
    //                              Sounddrv.cpp:305 (2)
    //         004bc985     XOR        EAX,EAX
    //                              Sounddrv.cpp:307 (3)
    //         004bc987     RET        0x10
    //                               LAB_004bc98a                                                 XREF[1]:     004bc983(j)  
    //                              Sounddrv.cpp:306 (28)
    //         004bc98a     MOV        EAX,dword ptr [ESP + param_4]
    //         004bc98e     MOV        this,dword ptr [ESP + param_3]
    //         004bc992     MOV        EDX,dword ptr [ESP + param_2]
    //         004bc996     PUSH       EAX
    //         004bc997     MOV        EAX,dword ptr [ESP + param_1]
    //         004bc99b     PUSH       this
    //         004bc99c     PUSH       EDX
    //         004bc99d     PUSH       EAX
    //         004bc99e     CALL       ds_stream_messages                               undefined ds_stream_messages()
    //         004bc9a3     ADD        ESP,0x10
    //                              Sounddrv.cpp:307 (3)
    //         004bc9a6     RET        0x10
}

// Offset: 0x004BC9B0
int add_to_play_list(TSound_Driver* this_, TDigital* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall TSound_Driver::add_to_play_list(class TDigital *)                              *
    //                              *********************************************************************************************************
    //                              int __thiscall add_to_play_list(TSound_Driver * this, TDigital * par
    //              int               EAX:4          <RETURN>
    //              TSound_Driver *   ECX:4 (auto)   this
    //              TDigital *        Stack[0x4]:4   param_1                   XREF[1]:     004bc9c4(R)  
    //                               ?add_to_play_list@TSound_Driver@@QAEHPAVTDigital@@@Z         XREF[1]:     add_to_play_list:004bd5d0(c)  
    //                               TSound_Driver::add_to_play_list
    //                              Sounddrv.cpp:311 (20)
    //         004bc9b0     MOV        EAX,dword ptr [ECX + this->play_list_count]
    //         004bc9b6     CMP        EAX,0xff
    //         004bc9bb     JZ         LAB_004bc9e4
    //         004bc9bd     MOV        DL,byte ptr [ECX + this->mute]
    //         004bc9c0     TEST       DL,DL
    //         004bc9c2     JNZ        LAB_004bc9e4
    //                              Sounddrv.cpp:314 (11)
    //         004bc9c4     MOV        EDX,dword ptr [ESP + param_1]
    //         004bc9c8     MOV        dword ptr [ECX + EAX*0x4 + this->sound_play_li
    //                              Sounddrv.cpp:315 (13)
    //         004bc9cf     MOV        EAX,dword ptr [ECX + this->play_list_count]
    //         004bc9d5     INC        EAX
    //         004bc9d6     MOV        dword ptr [ECX + this->play_list_count],EAX
    //                              Sounddrv.cpp:316 (5)
    //         004bc9dc     MOV        EAX,0x1
    //                              Sounddrv.cpp:317 (3)
    //         004bc9e1     RET        0x4
    //                               LAB_004bc9e4                                                 XREF[2]:     004bc9bb(j), 004bc9c2(j)  
    //                              Sounddrv.cpp:313 (2)
    //         004bc9e4     XOR        EAX,EAX
    //                              Sounddrv.cpp:317 (3)
    //         004bc9e6     RET        0x4
}

// Offset: 0x004BC9F0
void play_list(TSound_Driver* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TSound_Driver::play_list(void)                                                *
    //                              *********************************************************************************************************
    //                              void __thiscall play_list(TSound_Driver * this)
    //              void              <VOID>         <RETURN>
    //              TSound_Driver *   ECX:4 (auto)   this
    //                               ?play_list@TSound_Driver@@QAEXXZ                             XREF[1]:     handle_paint:00421510(c)  
    //                               TSound_Driver::play_list
    //                              Sounddrv.cpp:321 (4)
    //         004bc9f0     PUSH       EBX
    //         004bc9f1     MOV        EBX,this
    //         004bc9f3     PUSH       ESI
    //                              Sounddrv.cpp:322 (19)
    //         004bc9f4     XOR        ESI,ESI
    //         004bc9f6     MOV        EAX,dword ptr [EBX + 0x698]
    //         004bc9fc     TEST       EAX,EAX
    //         004bc9fe     JLE        LAB_004bca1d
    //         004bca00     PUSH       EDI
    //         004bca01     LEA        EDI,[EBX + 0x298]
    //                               LAB_004bca07                                                 XREF[1]:     004bca1a(j)  
    //                              Sounddrv.cpp:323 (21)
    //         004bca07     MOV        this,dword ptr [EDI]
    //         004bca09     CALL       TDigital::play                                   int play(TDigital * this)
    //         004bca0e     MOV        EAX,dword ptr [EBX + 0x698]
    //         004bca14     INC        ESI
    //         004bca15     ADD        EDI,0x4
    //         004bca18     CMP        ESI,EAX
    //         004bca1a     JL         LAB_004bca07
    //                              Sounddrv.cpp:321 (1)
    //         004bca1c     POP        EDI
    //                               LAB_004bca1d                                                 XREF[1]:     004bc9fe(j)  
    //                              Sounddrv.cpp:324 (3)
    //         004bca1d     POP        ESI
    //         004bca1e     POP        EBX
    //         004bca1f     RET
}

// Offset: 0x004BCA20
void reset_play_list(TSound_Driver* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TSound_Driver::reset_play_list(void)                                          *
    //                              *********************************************************************************************************
    //                              void __thiscall reset_play_list(TSound_Driver * this)
    //              void              <VOID>         <RETURN>
    //              TSound_Driver *   ECX:4 (auto)   this
    //                               ?reset_play_list@TSound_Driver@@QAEXXZ                       XREF[1]:     handle_paint:00421517(c)  
    //                               TSound_Driver::reset_play_list
    //                              Sounddrv.cpp:328 (10)
    //         004bca20     MOV        dword ptr [ECX + this->play_list_count],0x0
    //                              Sounddrv.cpp:330 (1)
    //         004bca2a     RET
}

// Offset: 0x004BCA30
int open_mixer(TSound_Driver* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall TSound_Driver::open_mixer(void)                                                *
    //                              *********************************************************************************************************
    //                              int __thiscall open_mixer(TSound_Driver * this)
    //              int               EAX:4          <RETURN>
    //              TSound_Driver *   ECX:4 (auto)   this
    //              uint              Stack[-0x8]:4  num_dev
    //              uint              Stack[-0xc]:4  mixer_id
    //                               ?open_mixer@TSound_Driver@@QAEHXZ                            XREF[1]:     init:004bc794(c)  
    //                               TSound_Driver::open_mixer
    //                              Sounddrv.cpp:334 (9)
    //         004bca30     SUB        ESP,0x8
    //         004bca33     PUSH       EBX
    //         004bca34     PUSH       EBP
    //         004bca35     PUSH       ESI
    //         004bca36     PUSH       EDI
    //         004bca37     MOV        ESI,this
    //                              Sounddrv.cpp:339 (8)
    //         004bca39     CALL       dword ptr [->WINMM.DLL::mixerGetNumDevs]         = 0048b590
    //         004bca3f     MOV        EDI,EAX
    //                              Sounddrv.cpp:340 (12)
    //         004bca41     TEST       EDI,EDI
    //         004bca43     MOV        dword ptr [ESP + 0x14],EDI
    //         004bca47     JBE        LAB_004bcbdc
    //                              Sounddrv.cpp:343 (14)
    //         004bca4d     XOR        EBP,EBP
    //         004bca4f     TEST       EDI,EDI
    //         004bca51     MOV        dword ptr [ESP + 0x10],EBP
    //         004bca55     JBE        LAB_004bcbdc
    //                              Sounddrv.cpp:345 (20)
    //         004bca5b     LEA        EBX,[ESI + 0x124]
    //                               LAB_004bca61                                                 XREF[1]:     004bcb83(j)  
    //         004bca61     PUSH       0x0
    //         004bca63     PUSH       0x0=>DAT_fffffff8
    //         004bca65     PUSH       0x0=>DAT_fffffff4
    //         004bca67     PUSH       EBP=>DAT_fffffff0
    //         004bca68     PUSH       EBX
    //         004bca69     CALL       dword ptr [->WINMM.DLL::mixerOpen]               = 0048b584
    //                              Sounddrv.cpp:346 (8)
    //         004bca6f     TEST       EAX,EAX
    //         004bca71     JNZ        LAB_004bcb7c
    //                              Sounddrv.cpp:349 (13)
    //         004bca77     LEA        EDX,[ESI + 0x128]
    //         004bca7d     MOV        this,0x2a
    //         004bca82     MOV        EDI,EDX
    //                              Sounddrv.cpp:352 (30)
    //         004bca84     PUSH       0x3
    //         004bca86     STOSD.REP  ES:EDI
    //         004bca88     MOV        EAX,dword ptr [EBX]
    //         004bca8a     PUSH       EDX=>DAT_fffffff8
    //         004bca8b     PUSH       EAX=>DAT_fffffff4
    //         004bca8c     MOV        dword ptr [EDX],0xa8
    //                              language.dll match for 0x1008: "Trade"
    //         004bca92     MOV        dword ptr [ESI + 0x140],0x1008
    //         004bca9c     CALL       dword ptr [->WINMM.DLL::mixerGetLineInfoA]       = 0048b570
    //                              Sounddrv.cpp:353 (8)
    //         004bcaa2     TEST       EAX,EAX
    //         004bcaa4     JNZ        LAB_004bcb69
    //                              Sounddrv.cpp:356 (13)
    //         004bcaaa     LEA        EDX,[ESI + 0x1d0]
    //         004bcab0     MOV        this,0x6
    //         004bcab5     MOV        EDI,EDX
    //                              Sounddrv.cpp:357 (17)
    //         004bcab7     LEA        EBP,[ESI + 0x1e8]
    //         004bcabd     STOSD.REP  ES:EDI
    //         004bcabf     MOV        this,0x25
    //         004bcac4     MOV        EDI,EBP
    //         004bcac6     STOSD.REP  ES:EDI
    //                              Sounddrv.cpp:359 (6)
    //         004bcac8     MOV        this,dword ptr [ESI + 0x134]
    //                              Sounddrv.cpp:364 (60)
    //         004bcace     PUSH       0x2
    //         004bcad0     MOV        dword ptr [EDX],0x18
    //         004bcad6     PUSH       EDX=>DAT_fffffff8
    //         004bcad7     MOV        EDX,dword ptr [EBX]
    //         004bcad9     MOV        dword ptr [ESI + 0x1d4],this
    //         004bcadf     PUSH       EDX=>DAT_fffffff4
    //         004bcae0     MOV        dword ptr [ESI + 0x1d8],0x50030001
    //         004bcaea     MOV        dword ptr [ESI + 0x1dc],0x1
    //         004bcaf4     MOV        dword ptr [ESI + 0x1e0],0x94
    //         004bcafe     MOV        dword ptr [ESI + 0x1e4],EBP
    //         004bcb04     CALL       dword ptr [->WINMM.DLL::mixerGetLineControlsA]   = 0048b558
    //                              Sounddrv.cpp:365 (4)
    //         004bcb0a     TEST       EAX,EAX
    //         004bcb0c     JNZ        LAB_004bcb65
    //                              Sounddrv.cpp:368 (13)
    //         004bcb0e     LEA        EDX,[ESI + 0x27c]
    //         004bcb14     MOV        this,0x6
    //         004bcb19     MOV        EDI,EDX
    //                              Sounddrv.cpp:375 (70)
    //         004bcb1b     PUSH       0x0
    //         004bcb1d     STOSD.REP  ES:EDI
    //         004bcb1f     LEA        EAX,[ESI + 0x294]
    //         004bcb25     PUSH       EDX=>DAT_fffffff8
    //         004bcb26     MOV        dword ptr [EAX],0x0
    //         004bcb2c     MOV        this,dword ptr [ESI + 0x1ec]
    //         004bcb32     MOV        dword ptr [EDX],0x18
    //         004bcb38     MOV        EDX,dword ptr [EBX]
    //         004bcb3a     PUSH       EDX=>DAT_fffffff4
    //         004bcb3b     MOV        dword ptr [ESI + 0x280],this
    //         004bcb41     MOV        dword ptr [ESI + 0x284],0x1
    //         004bcb4b     MOV        dword ptr [ESI + 0x28c],0x4
    //         004bcb55     MOV        dword ptr [ESI + 0x290],EAX
    //         004bcb5b     CALL       dword ptr [->WINMM.DLL::mixerGetControlDetailsA] = 0048b53e
    //                              Sounddrv.cpp:376 (8)
    //         004bcb61     TEST       EAX,EAX
    //         004bcb63     JZ         LAB_004bcb93
    //                               LAB_004bcb65                                                 XREF[1]:     004bcb0c(j)  
    //         004bcb65     MOV        EBP,dword ptr [ESP + 0x10]
    //                               LAB_004bcb69                                                 XREF[1]:     004bcaa4(j)  
    //                              Sounddrv.cpp:392 (9)
    //         004bcb69     MOV        EAX,dword ptr [EBX]
    //         004bcb6b     PUSH       EAX
    //         004bcb6c     CALL       dword ptr [->WINMM.DLL::mixerClose]              = 0048b530
    //                              Sounddrv.cpp:393 (23)
    //         004bcb72     MOV        EDI,dword ptr [ESP + 0x14]
    //         004bcb76     MOV        dword ptr [EBX],0x0
    //                               LAB_004bcb7c                                                 XREF[1]:     004bca71(j)  
    //         004bcb7c     INC        EBP
    //         004bcb7d     CMP        EBP,EDI
    //         004bcb7f     MOV        dword ptr [ESP + 0x10],EBP
    //         004bcb83     JC         LAB_004bca61
    //                              Sounddrv.cpp:398 (2)
    //         004bcb89     XOR        EAX,EAX
    //                              Sounddrv.cpp:399 (8)
    //         004bcb8b     POP        EDI
    //         004bcb8c     POP        ESI
    //         004bcb8d     POP        EBP
    //         004bcb8e     POP        EBX
    //         004bcb8f     ADD        ESP,0x8
    //         004bcb92     RET
    //                               LAB_004bcb93                                                 XREF[1]:     004bcb63(j)  
    //                              Sounddrv.cpp:385 (57)
    //         004bcb93     MOV        EAX,dword ptr [ESI + 0x294]
    //         004bcb99     MOV        this,dword ptr [ESI + 0x250]
    //         004bcb9f     MOV        EDI,dword ptr [ESI + 0x24c]
    //         004bcba5     XOR        EDX,EDX
    //         004bcba7     LEA        EAX,[EAX + EAX*0x4]
    //         004bcbaa     SUB        this,EDI
    //         004bcbac     MOV        dword ptr [ESI + 0x120],0x1
    //         004bcbb6     LEA        EAX,[EAX + EAX*0x4]
    //         004bcbb9     LEA        EAX,[EAX + EAX*0x4]
    //         004bcbbc     LEA        EAX,[EAX + EAX*0x4]
    //         004bcbbf     SHL        EAX,0x4
    //         004bcbc2     DIV        this
    //         004bcbc4     ADD        EAX,0xffffd8f0
    //         004bcbc9     MOV        dword ptr [ESI + 0x14],EAX
    //                              Sounddrv.cpp:386 (3)
    //         004bcbcc     MOV        dword ptr [ESI + 0x18],EAX
    //                              Sounddrv.cpp:388 (5)
    //         004bcbcf     MOV        EAX,0x1
    //                              Sounddrv.cpp:399 (18)
    //         004bcbd4     POP        EDI
    //         004bcbd5     POP        ESI
    //         004bcbd6     POP        EBP
    //         004bcbd7     POP        EBX
    //         004bcbd8     ADD        ESP,0x8
    //         004bcbdb     RET
    //                               LAB_004bcbdc                                                 XREF[2]:     004bca47(j), 004bca55(j)  
    //         004bcbdc     POP        EDI
    //         004bcbdd     POP        ESI
    //         004bcbde     POP        EBP
    //         004bcbdf     XOR        EAX,EAX
    //         004bcbe1     POP        EBX
    //         004bcbe2     ADD        ESP,0x8
    //         004bcbe5     RET
}

// Offset: 0x004BCBF0
void close_mixer(TSound_Driver* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TSound_Driver::close_mixer(void)                                              *
    //                              *********************************************************************************************************
    //                              void __thiscall close_mixer(TSound_Driver * this)
    //              void              <VOID>         <RETURN>
    //              TSound_Driver *   ECX:4 (auto)   this
    //                               ?close_mixer@TSound_Driver@@QAEXXZ                           XREF[1]:     exit:004bc7c3(c)  
    //                               TSound_Driver::close_mixer
    //                              Sounddrv.cpp:403 (3)
    //         004bcbf0     PUSH       ESI
    //         004bcbf1     MOV        ESI,this
    //                              Sounddrv.cpp:404 (10)
    //         004bcbf3     MOV        EAX,dword ptr [ESI + 0x120]
    //         004bcbf9     TEST       EAX,EAX
    //         004bcbfb     JZ         LAB_004bcc39
    //                              Sounddrv.cpp:407 (8)
    //         004bcbfd     MOV        EAX,dword ptr [ESI + 0x14]
    //         004bcc00     CMP        EAX,0x1
    //         004bcc03     JZ         LAB_004bcc14
    //                              Sounddrv.cpp:409 (8)
    //         004bcc05     PUSH       0x0
    //         004bcc07     PUSH       EAX
    //         004bcc08     CALL       TSound_Driver::set_volume                        void set_volume(TSound_Driver * this, long pa
    //                              Sounddrv.cpp:410 (7)
    //         004bcc0d     MOV        dword ptr [ESI + 0x14],0x1
    //                               LAB_004bcc14                                                 XREF[1]:     004bcc03(j)  
    //                              Sounddrv.cpp:413 (10)
    //         004bcc14     MOV        EAX,dword ptr [ESI + 0x124]
    //         004bcc1a     TEST       EAX,EAX
    //         004bcc1c     JZ         LAB_004bcc2f
    //                              Sounddrv.cpp:415 (7)
    //         004bcc1e     PUSH       EAX
    //         004bcc1f     CALL       dword ptr [->WINMM.DLL::mixerClose]              = 0048b530
    //                              Sounddrv.cpp:416 (10)
    //         004bcc25     MOV        dword ptr [ESI + 0x124],0x0
    //                               LAB_004bcc2f                                                 XREF[1]:     004bcc1c(j)  
    //                              Sounddrv.cpp:419 (10)
    //         004bcc2f     MOV        dword ptr [ESI + 0x120],0x0
    //                               LAB_004bcc39                                                 XREF[1]:     004bcbfb(j)  
    //                              Sounddrv.cpp:420 (2)
    //         004bcc39     POP        ESI
    //         004bcc3a     RET
}

// Offset: 0x004BCC40
undefined TDigital(TDigital* this_, TSound_Driver* param_2, char* param_3, long param_4) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall TDigital::TDigital(class TSound_Driver *,char *,long)                              *
    //                              *********************************************************************************************************
    //                              undefined __thiscall TDigital(TDigital * this, TSound_Driver * param
    //              undefined         <UNASSIGNED>   <RETURN>
    //              TDigital *        ECX:4 (auto)   this
    //              TSound_Driver *   Stack[0x4]:4   param_1                   XREF[1]:     004bcc48(R)  
    //              char *            Stack[0x8]:4   param_2                   XREF[1]:     004bcc52(R)  
    //              long              Stack[0xc]:4   param_3                   XREF[1]:     004bcc4c(R)  
    //                               ??0TDigital@@QAE@PAVTSound_Driver@@PADJ@Z                    XREF[24]:    handle_game_update:00496d4a(c), 
    //                               TDigital::TDigital                                                        RGE_Sound:004bc016(c), 
    //                                                                                                         restart_sound:004bc206(c), 
    //                                                                                                         RestartSoundSystem:005096ea(c), 
    //                                                                                                         setup_sounds:0052234a(c), 
    //                                                                                                         setup_sounds:00522389(c), 
    //                                                                                                         setup_sounds:005223c6(c), 
    //                                                                                                         setup_sounds:00522403(c), 
    //                                                                                                         setup_sounds:00522440(c), 
    //                                                                                                         setup_sounds:0052247d(c), 
    //                                                                                                         setup_sounds:005224ba(c), 
    //                                                                                                         setup_sounds:005224f7(c), 
    //                                                                                                         setup_sounds:00522534(c), 
    //                                                                                                         setup_sounds:00522571(c), 
    //                                                                                                         setup_sounds:005225ae(c), 
    //                                                                                                         setup_sounds:005225eb(c), 
    //                                                                                                         setup_sounds:00522628(c), 
    //                                                                                                         setup_sounds:00522665(c), 
    //                                                                                                         setup_sounds:005226a2(c), 
    //                                                                                                         setup_sounds:005226df(c), [more]
    //                              Sounddrv.cpp:424 (3)
    //         004bcc40     PUSH       ESI
    //         004bcc41     MOV        ESI,this
    //                              Sounddrv.cpp:425 (5)
    //         004bcc43     CALL       TDigital::init_vars                              void init_vars(TDigital * this)
    //                              Sounddrv.cpp:427 (4)
    //         004bcc48     MOV        EAX,dword ptr [ESP + param_1]
    //                              Sounddrv.cpp:429 (6)
    //         004bcc4c     MOV        this,dword ptr [ESP + param_3]
    //         004bcc50     MOV        dword ptr [ESI],EAX
    //                              Sounddrv.cpp:431 (11)
    //         004bcc52     MOV        EAX,dword ptr [ESP + param_2]
    //         004bcc56     TEST       EAX,EAX
    //         004bcc58     MOV        dword ptr [ESI + 0x18],this
    //         004bcc5b     JZ         LAB_004bcc70
    //                              Sounddrv.cpp:433 (15)
    //         004bcc5d     PUSH       0xc
    //         004bcc5f     LEA        EDX,[ESI + 0xa]
    //         004bcc62     PUSH       EAX
    //         004bcc63     PUSH       EDX
    //         004bcc64     CALL       strncpy                                          undefined strncpy()
    //         004bcc69     ADD        ESP,0xc
    //                              Sounddrv.cpp:434 (4)
    //         004bcc6c     MOV        byte ptr [ESI + 0x16],0x0
    //                               LAB_004bcc70                                                 XREF[1]:     004bcc5b(j)  
    //                              Sounddrv.cpp:440 (6)
    //         004bcc70     MOV        EAX,ESI
    //         004bcc72     POP        ESI
    //         004bcc73     RET        0xc
}

// Offset: 0x004BCC80
undefined TDigital(TDigital* this_, TDigital* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall TDigital::TDigital(class TDigital *)                                               *
    //                              *********************************************************************************************************
    //                              undefined __thiscall TDigital(TDigital * this, TDigital * param_1)
    //              undefined         <UNASSIGNED>   <RETURN>
    //              TDigital *        ECX:4 (auto)   this
    //              TDigital *        Stack[0x4]:4   param_1                   XREF[1]:     004bcc88(R)  
    //                               ??0TDigital@@QAE@PAV0@@Z
    //                               TDigital::TDigital
    //                              Sounddrv.cpp:444 (3)
    //         004bcc80     PUSH       ESI
    //         004bcc81     MOV        ESI,this
    //                              Sounddrv.cpp:445 (5)
    //         004bcc83     CALL       TDigital::init_vars                              void init_vars(TDigital * this)
    //                              Sounddrv.cpp:447 (7)
    //         004bcc88     MOV        EAX,dword ptr [ESP + param_1]
    //         004bcc8c     MOV        dword ptr [ESI + 0x4],EAX
    //                              Sounddrv.cpp:449 (6)
    //         004bcc8f     MOV        this,dword ptr [EAX + 0x1c]
    //         004bcc92     MOV        dword ptr [ESI + 0x1c],this
    //                              Sounddrv.cpp:450 (6)
    //         004bcc95     MOV        EDX,dword ptr [EAX + 0x20]
    //         004bcc98     MOV        dword ptr [ESI + 0x20],EDX
    //                              Sounddrv.cpp:451 (6)
    //         004bcc9b     MOV        this,dword ptr [EAX + 0x24]
    //         004bcc9e     MOV        dword ptr [ESI + 0x24],this
    //                              Sounddrv.cpp:452 (6)
    //         004bcca1     MOV        EDX,dword ptr [EAX + 0x28]
    //         004bcca4     MOV        dword ptr [ESI + 0x28],EDX
    //                              Sounddrv.cpp:453 (6)
    //         004bcca7     MOV        EAX,ESI
    //         004bcca9     POP        ESI
    //         004bccaa     RET        0x4
}

// Offset: 0x004BCCB0
void TDigital(TDigital* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall TDigital::~TDigital(void)                                                          *
    //                              *********************************************************************************************************
    //                              void __thiscall ~TDigital(TDigital * this)
    //              void              <VOID>         <RETURN>
    //              TDigital *        ECX:4 (auto)   this
    //                               ??1TDigital@@QAE@XZ                                          XREF[7]:     stop_sound_system:0041f897(c), 
    //                               TDigital::~TDigital                                                       ~TRIBE_Screen_Game:00495505(c), 
    //                                                                                                         handle_game_update:00496cd2(c), 
    //                                                                                                         stop_sound_system:0049d500(c), 
    //                                                                                                         ~RGE_Sound:004bc0b0(c), 
    //                                                                                                         restart_sound:004bc1c7(c), 
    //                                                                                                         StopSoundSystem:00509682(c)  
    //                              Sounddrv.cpp:457 (5)
    //         004bccb0     JMP        TDigital::exit
}

// Offset: 0x004BCCC0
void init_vars(TDigital* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TDigital::init_vars(void)                                                     *
    //                              *********************************************************************************************************
    //                              void __thiscall init_vars(TDigital * this)
    //              void              <VOID>         <RETURN>
    //              TDigital *        ECX:4 (auto)   this
    //                               ?init_vars@TDigital@@QAEXXZ                                  XREF[4]:     TDigital:004bcc43(c), 
    //                               TDigital::init_vars                                                       TDigital:004bcc83(c), 
    //                                                                                                         exit:004bcd01(c), 
    //                                                                                                         exit:004bcd1f(c)  
    //                              Sounddrv.cpp:465 (4)
    //         004bccc0     XOR        EAX,EAX
    //         004bccc2     MOV        dword ptr [this->sound_system],EAX
    //                              Sounddrv.cpp:467 (3)
    //         004bccc4     MOV        dword ptr [ECX + this->owner],EAX
    //                              Sounddrv.cpp:468 (3)
    //         004bccc7     MOV        byte ptr [ECX + this->loaded],AL
    //                              Sounddrv.cpp:469 (3)
    //         004bccca     MOV        byte ptr [ECX + this->failed],AL
    //                              Sounddrv.cpp:470 (3)
    //         004bcccd     MOV        byte ptr [ECX + this->sound_file[0]],AL
    //                              Sounddrv.cpp:472 (3)
    //         004bccd0     MOV        dword ptr [ECX + this->wave_data],EAX
    //                              Sounddrv.cpp:473 (3)
    //         004bccd3     MOV        dword ptr [ECX + this->wave_info],EAX
    //                              Sounddrv.cpp:474 (3)
    //         004bccd6     MOV        dword ptr [ECX + this->sound_buffer],EAX
    //                              Sounddrv.cpp:475 (3)
    //         004bccd9     MOV        dword ptr [ECX + this->data_size],EAX
    //                              Sounddrv.cpp:477 (3)
    //         004bccdc     MOV        dword ptr [ECX + this->volume],EAX
    //                              Sounddrv.cpp:478 (3)
    //         004bccdf     MOV        dword ptr [ECX + this->pitch],EAX
    //                              Sounddrv.cpp:479 (3)
    //         004bcce2     MOV        dword ptr [ECX + this->pan],EAX
    //                              Sounddrv.cpp:480 (3)
    //         004bcce5     MOV        dword ptr [ECX + this->loop],EAX
    //                              Sounddrv.cpp:481 (1)
    //         004bcce8     RET
}

// Offset: 0x004BCCF0
void exit(TDigital* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TDigital::exit(void)                                                          *
    //                              *********************************************************************************************************
    //                              void __thiscall exit(TDigital * this)
    //              void              <VOID>         <RETURN>
    //              TDigital *        ECX:4 (auto)   this
    //                               ?exit@TDigital@@QAEXXZ                                       XREF[2]:     exit:004bccad(T), 
    //                               TDigital::exit                                                            ~TDigital:004bccb0(j), 
    //                                                                                                         004bccfa(c)  
    //                              Sounddrv.cpp:487 (3)
    //         004bccf0     PUSH       ESI
    //         004bccf1     MOV        ESI,this
    //                              Sounddrv.cpp:488 (7)
    //         004bccf3     MOV        this,dword ptr [ESI + 0x4]
    //         004bccf6     TEST       this,this
    //         004bccf8     JZ         LAB_004bcd08
    //                              Sounddrv.cpp:490 (5)
    //         004bccfa     CALL       TDigital::exit                                   void exit(TDigital * this)
    //                              Sounddrv.cpp:499 (7)
    //         004bccff     MOV        this,ESI
    //         004bcd01     CALL       TDigital::init_vars                              void init_vars(TDigital * this)
    //                              Sounddrv.cpp:501 (2)
    //         004bcd06     POP        ESI
    //         004bcd07     RET
    //                               LAB_004bcd08                                                 XREF[1]:     004bccf8(j)  
    //                              Sounddrv.cpp:495 (7)
    //         004bcd08     MOV        AL,byte ptr [ESI + 0x8]
    //         004bcd0b     TEST       AL,AL
    //         004bcd0d     JZ         LAB_004bcd24
    //                              Sounddrv.cpp:497 (7)
    //         004bcd0f     MOV        this,ESI
    //         004bcd11     CALL       TDigital::stop                                   void stop(TDigital * this)
    //                              Sounddrv.cpp:498 (7)
    //         004bcd16     MOV        this,ESI
    //         004bcd18     CALL       TDigital::unload                                 void unload(TDigital * this)
    //                              Sounddrv.cpp:499 (7)
    //         004bcd1d     MOV        this,ESI
    //         004bcd1f     CALL       TDigital::init_vars                              void init_vars(TDigital * this)
    //                               LAB_004bcd24                                                 XREF[1]:     004bcd0d(j)  
    //                              Sounddrv.cpp:501 (2)
    //         004bcd24     POP        ESI
    //         004bcd25     RET
}

// Offset: 0x004BCD30
int load(TDigital* this_, char* param_2, long param_3) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall TDigital::load(char *,long)                                                    *
    //                              *********************************************************************************************************
    //                              int __thiscall load(TDigital * this, char * param_1, long param_2)
    //              int               EAX:4          <RETURN>
    //              TDigital *        ECX:4 (auto)   this
    //              char *            Stack[0x4]:4   param_1                   XREF[2]:     004bcd66(R), 004bcdad(R)  
    //              long              Stack[0x8]:4   param_2                   XREF[1]:     004bcdd9(R)  
    //              char[260]         Stack[-0x108   file_with_path            XREF[1,2]:   004bd0a7(*), 004bce01(*), 004bce14(*)  
    //              int               Stack[-0x10c   resDataSize               XREF[2]:     004bce7c(R), 004bd0d6(R)  
    //              _tag_wavheader    Stack[-0x138   wave_hdr                  XREF[3,16]:  004bcd49(W), 004bcf79(W), 004bd1d5(W), 004bce2e(*), 
    //                                                                                     004bce56(*), 004bd0d0(*), 004bce70(R), 004bcf0a(R), 
    //                                                                                     004bd166(R), 004bcf17(R), 004bd173(R), 004bcf26(R), 
    //                                                                                     004bd182(R), 004bcf31(R), 004bd18d(R), 004bcf3c(R), 
    //                                                                                     004bd198(R), 004bcf48(R), 004bd1a4(R)  
    //              _DSBUFFERDESC     Stack[-0x14c   buffer_desc               XREF[4,14]:  004bd0ab(*), 004bd0ed(R), 004bd122(R), 004bd14b(R), 
    //                                                                                     004bcd55(W), 004bcf61(W), 004bcf80(*), 004bd1c1(W), 
    //                                                                                     004bd1dc(*), 004bcd39(W), 004bcf69(W), 004bd1c9(W), 
    //                                                                                     004bcd3e(W), 004bcf71(W), 004bd1d1(W), 004bcd44(W), 
    //                                                                                     004bcf75(W), 004bd1ba(W)  
    //              int               Stack[-0x150   load_type
    //              void *            Stack[-0x154   mem1
    //              void *            Stack[-0x158   mem2
    //              ulong             Stack[-0x15c   size2
    //              ulong             Stack[-0x160   size1
    //                               ?load@TDigital@@QAEHPADJ@Z                                   XREF[7]:     setup_sounds:0041f537(c), 
    //                               TDigital::load                                                            handle_game_update:00496d66(c), 
    //                                                                                                         004bcd70(c), play:004bd3ac(c), 
    //                                                                                                         play:004bd42c(c), 
    //                                                                                                         PlayTauntNo:005095d1(c), 
    //                                                                                                         setup_sounds:0052273e(c)  
    //                              Sounddrv.cpp:507 (6)
    //         004bcd30     SUB        ESP,0x15c
    //                              Sounddrv.cpp:512 (23)
    //         004bcd36     XOR        EAX,EAX
    //         004bcd38     PUSH       EBX
    //         004bcd39     MOV        dword ptr [ESP + buffer_desc.dwBufferBytes],EAX
    //         004bcd3d     PUSH       EBP
    //         004bcd3e     MOV        dword ptr [ESP + buffer_desc.dwReserved],EAX
    //         004bcd42     MOV        EBP,this
    //         004bcd44     MOV        dword ptr [ESP + buffer_desc.lpwfxFormat],EAX
    //         004bcd48     PUSH       ESI
    //         004bcd49     MOV        dword ptr [ESP + wave_hdr.szRIFF[0]],EAX
    //                              Sounddrv.cpp:523 (12)
    //         004bcd4d     MOV        AL,byte ptr [EBP + 0x9]
    //         004bcd50     PUSH       EDI
    //         004bcd51     XOR        EDI,EDI
    //         004bcd53     TEST       AL,AL
    //         004bcd55     MOV        dword ptr [ESP + buffer_desc.dwFlags],EDI
    //                              Sounddrv.cpp:524 (6)
    //         004bcd59     JNZ        LAB_004bd2e4
    //                              Sounddrv.cpp:526 (7)
    //         004bcd5f     MOV        this,dword ptr [EBP + 0x4]
    //         004bcd62     CMP        this,EDI
    //         004bcd64     JZ         LAB_004bcd82
    //                              Sounddrv.cpp:527 (15)
    //         004bcd66     MOV        EDX,dword ptr [ESP + param_1]
    //         004bcd6d     PUSH       -0x1
    //         004bcd6f     PUSH       EDX
    //         004bcd70     CALL       TDigital::load                                   int load(TDigital * this, char * param_1, lon
    //                              Sounddrv.cpp:826 (13)
    //         004bcd75     POP        EDI
    //         004bcd76     POP        ESI
    //         004bcd77     POP        EBP
    //         004bcd78     POP        EBX
    //         004bcd79     ADD        ESP,0x15c
    //         004bcd7f     RET        0x8
    //                               LAB_004bcd82                                                 XREF[1]:     004bcd64(j)  
    //                              Sounddrv.cpp:529 (3)
    //         004bcd82     CMP        dword ptr [EBP],EDI
    //                              Sounddrv.cpp:530 (6)
    //         004bcd85     JZ         LAB_004bd2e4
    //                              Sounddrv.cpp:533 (17)
    //         004bcd8b     PUSH       0x1
    //         004bcd8d     PUSH       0xba
    //         004bcd92     PUSH       0xba
    //         004bcd97     CALL       color_log                                        void color_log(uchar param_1, uchar param_2, 
    //                              Sounddrv.cpp:535 (10)
    //         004bcd9c     MOV        AL,byte ptr [EBP + 0x8]
    //         004bcd9f     ADD        ESP,0xc
    //         004bcda2     TEST       AL,AL
    //         004bcda4     JZ         LAB_004bcdad
    //                              Sounddrv.cpp:536 (7)
    //         004bcda6     MOV        this,EBP
    //         004bcda8     CALL       TDigital::unload                                 void unload(TDigital * this)
    //                               LAB_004bcdad                                                 XREF[1]:     004bcda4(j)  
    //                              Sounddrv.cpp:538 (11)
    //         004bcdad     MOV        EAX,dword ptr [ESP + param_1]
    //         004bcdb4     CMP        EAX,EDI
    //         004bcdb6     JZ         LAB_004bcdcb
    //                              Sounddrv.cpp:540 (15)
    //         004bcdb8     PUSH       0xc
    //         004bcdba     PUSH       EAX
    //         004bcdbb     LEA        EAX,[EBP + 0xa]
    //         004bcdbe     PUSH       EAX
    //         004bcdbf     CALL       strncpy                                          undefined strncpy()
    //         004bcdc4     ADD        ESP,0xc
    //                              Sounddrv.cpp:541 (4)
    //         004bcdc7     MOV        byte ptr [EBP + 0x16],0x0
    //                               LAB_004bcdcb                                                 XREF[1]:     004bcdb6(j)  
    //                              Sounddrv.cpp:544 (8)
    //         004bcdcb     MOV        this,byte ptr [EBP + 0xa]
    //         004bcdce     LEA        EAX,[EBP + 0xa]
    //         004bcdd1     TEST       this,this
    //                              Sounddrv.cpp:548 (6)
    //         004bcdd3     JZ         LAB_004bd2d3
    //                              Sounddrv.cpp:557 (10)
    //         004bcdd9     MOV        EBX,dword ptr [ESP + param_2]
    //         004bcde0     CMP        EBX,-0x1
    //                              Sounddrv.cpp:559 (2)
    //         004bcde3     JG         LAB_004bcde8
    //                              Sounddrv.cpp:560 (3)
    //         004bcde5     MOV        EBX,dword ptr [EBP + 0x18]
    //                               LAB_004bcde8                                                 XREF[1]:     004bcde3(j)  
    //                              Sounddrv.cpp:562 (18)
    //         004bcde8     MOV        this,byte ptr [sound_file_first]                 = 00h
    //         004bcdee     TEST       this,this
    //         004bcdf0     JNZ        LAB_004bcdfa
    //         004bcdf2     CMP        EBX,EDI
    //         004bcdf4     JGE        LAB_004bd09e
    //                               LAB_004bcdfa                                                 XREF[1]:     004bcdf0(j)  
    //                              Sounddrv.cpp:564 (26)
    //         004bcdfa     MOV        this,dword ptr [EBP]
    //         004bcdfd     PUSH       EAX
    //         004bcdfe     ADD        this,0x1c
    //         004bce01     LEA        EDX=>file_with_path[4],[ESP + 0x6c]
    //         004bce05     PUSH       this
    //         004bce06     PUSH       s_%s%s                                           = "%s%s"
    //         004bce0b     PUSH       EDX
    //         004bce0c     CALL       sprintf                                          undefined sprintf()
    //         004bce11     ADD        ESP,0x10
    //                              Sounddrv.cpp:566 (17)
    //         004bce14     LEA        EAX=>file_with_path[4],[ESP + 0x68]
    //         004bce18     PUSH       EDI
    //         004bce19     PUSH       EDI
    //         004bce1a     PUSH       EAX
    //         004bce1b     CALL       __open                                           undefined __open()
    //         004bce20     MOV        ESI,EAX
    //         004bce22     ADD        ESP,0xc
    //                              Sounddrv.cpp:569 (9)
    //         004bce25     CMP        ESI,-0x1
    //         004bce28     JZ         LAB_004bd09e
    //                              Sounddrv.cpp:572 (16)
    //         004bce2e     LEA        this=>wave_hdr.dwFormatLength,[ESP + 0x38]
    //         004bce32     PUSH       0x2c
    //         004bce34     PUSH       this
    //         004bce35     PUSH       ESI
    //         004bce36     CALL       read                                             undefined read()
    //         004bce3b     ADD        ESP,0xc
    //                              Sounddrv.cpp:573 (4)
    //         004bce3e     CMP        EAX,EDI
    //         004bce40     JA         LAB_004bce54
    //                              Sounddrv.cpp:577 (13)
    //         004bce42     PUSH       ESI
    //         004bce43     MOV        byte ptr [EBP + 0x9],0x1
    //         004bce47     CALL       close                                            undefined close()
    //         004bce4c     ADD        ESP,0x4
    //                              Sounddrv.cpp:580 (5)
    //         004bce4f     JMP        LAB_004bd2d3
    //                               LAB_004bce54                                                 XREF[1]:     004bce40(j)  
    //                              Sounddrv.cpp:583 (40)
    //         004bce54     PUSH       0x4
    //         004bce56     LEA        EDX=>wave_hdr.dwFormatLength,[ESP + 0x3c]
    //         004bce5a     PUSH       s_RIFF                                           = "RIFF"
    //         004bce5f     PUSH       EDX
    //         004bce60     CALL       strncmp                                          undefined strncmp()
    //         004bce65     ADD        ESP,0xc
    //         004bce68     TEST       EAX,EAX
    //         004bce6a     JNZ        LAB_004bd08c
    //         004bce70     CMP        word ptr [ESP + wave_hdr.nSamplesPerSec],0x1
    //         004bce76     JNZ        LAB_004bd08c
    //                              Sounddrv.cpp:593 (4)
    //         004bce7c     MOV        EAX,dword ptr [ESP + resDataSize]
    //                              Sounddrv.cpp:596 (12)
    //         004bce80     PUSH       EAX
    //         004bce81     MOV        dword ptr [EBP + 0x38],EAX
    //         004bce84     CALL       malloc                                           undefined malloc()
    //         004bce89     ADD        ESP,0x4
    //                              Sounddrv.cpp:597 (7)
    //         004bce8c     CMP        EAX,EDI
    //         004bce8e     MOV        dword ptr [EBP + 0x2c],EAX
    //         004bce91     JNZ        LAB_004bcea5
    //                              Sounddrv.cpp:601 (13)
    //         004bce93     PUSH       ESI
    //         004bce94     MOV        byte ptr [EBP + 0x9],0x1
    //         004bce98     CALL       close                                            undefined close()
    //         004bce9d     ADD        ESP,0x4
    //                              Sounddrv.cpp:604 (5)
    //         004bcea0     JMP        LAB_004bd2d3
    //                               LAB_004bcea5                                                 XREF[1]:     004bce91(j)  
    //                              Sounddrv.cpp:608 (14)
    //         004bcea5     MOV        this,dword ptr [EBP + 0x38]
    //         004bcea8     PUSH       this
    //         004bcea9     PUSH       EAX
    //         004bceaa     PUSH       ESI
    //         004bceab     CALL       read                                             undefined read()
    //         004bceb0     ADD        ESP,0xc
    //                              Sounddrv.cpp:609 (4)
    //         004bceb3     CMP        EAX,EDI
    //         004bceb5     JA         LAB_004bced8
    //                              Sounddrv.cpp:612 (16)
    //         004bceb7     MOV        EDX,dword ptr [EBP + 0x2c]
    //         004bceba     MOV        byte ptr [EBP + 0x9],0x1
    //         004bcebe     PUSH       EDX
    //         004bcebf     CALL       free                                             undefined free()
    //         004bcec4     ADD        ESP,0x4
    //                              Sounddrv.cpp:613 (3)
    //         004bcec7     MOV        dword ptr [EBP + 0x2c],EDI
    //                              Sounddrv.cpp:615 (9)
    //         004bceca     PUSH       ESI
    //         004bcecb     CALL       close                                            undefined close()
    //         004bced0     ADD        ESP,0x4
    //                              Sounddrv.cpp:618 (5)
    //         004bced3     JMP        LAB_004bd2d3
    //                               LAB_004bced8                                                 XREF[1]:     004bceb5(j)  
    //                              Sounddrv.cpp:623 (9)
    //         004bced8     PUSH       ESI
    //         004bced9     CALL       close                                            undefined close()
    //         004bcede     ADD        ESP,0x4
    //                              Sounddrv.cpp:626 (10)
    //         004bcee1     PUSH       0x12
    //         004bcee3     CALL       malloc                                           undefined malloc()
    //         004bcee8     ADD        ESP,0x4
    //                              Sounddrv.cpp:627 (7)
    //         004bceeb     CMP        EAX,EDI
    //         004bceed     MOV        dword ptr [EBP + 0x30],EAX
    //         004bcef0     JNZ        LAB_004bcf0a
    //                              Sounddrv.cpp:630 (16)
    //         004bcef2     MOV        EAX,dword ptr [EBP + 0x2c]
    //         004bcef5     MOV        byte ptr [EBP + 0x9],0x1
    //         004bcef9     PUSH       EAX
    //         004bcefa     CALL       free                                             undefined free()
    //         004bceff     ADD        ESP,0x4
    //                              Sounddrv.cpp:631 (3)
    //         004bcf02     MOV        dword ptr [EBP + 0x2c],EDI
    //                              Sounddrv.cpp:634 (5)
    //         004bcf05     JMP        LAB_004bd2d3
    //                               LAB_004bcf0a                                                 XREF[1]:     004bcef0(j)  
    //                              Sounddrv.cpp:637 (5)
    //         004bcf0a     MOV        this,word ptr [ESP + wave_hdr.nSamplesPerSec]
    //                              Sounddrv.cpp:652 (128)
    //         004bcf0f     XOR        ESI,ESI
    //         004bcf11     MOV        word ptr [EAX],this
    //         004bcf14     MOV        EDX,dword ptr [EBP + 0x30]
    //         004bcf17     MOV        AX,word ptr [ESP + wave_hdr+0x1a]
    //         004bcf1c     LEA        EBX,[EBP + 0x34]
    //         004bcf1f     MOV        word ptr [EDX + 0x2],AX
    //         004bcf23     MOV        this,dword ptr [EBP + 0x30]
    //         004bcf26     MOV        EDX,dword ptr [ESP + wave_hdr.nAvgBytesPerSec]
    //         004bcf2a     PUSH       ESI
    //         004bcf2b     MOV        dword ptr [ECX + this->owner],EDX
    //         004bcf2e     MOV        EAX,dword ptr [EBP + 0x30]
    //         004bcf31     MOV        this,dword ptr [ESP + wave_hdr.nBlockAlign]
    //         004bcf35     PUSH       EBX
    //         004bcf36     MOV        dword ptr [EAX + 0x8],this
    //         004bcf39     MOV        EDX,dword ptr [EBP + 0x30]
    //         004bcf3c     MOV        AX,word ptr [ESP + wave_hdr.szDATA[0]]
    //         004bcf41     MOV        word ptr [EDX + 0xc],AX
    //         004bcf45     MOV        this,dword ptr [EBP + 0x30]
    //         004bcf48     MOV        DX,word ptr [ESP + wave_hdr+0x26]
    //         004bcf4d     MOV        word ptr [ECX + this+0xe],DX
    //         004bcf51     MOV        EAX,dword ptr [EBP + 0x30]
    //         004bcf54     MOV        word ptr [EAX + 0x10],DI
    //         004bcf58     MOV        this,dword ptr [EBP + 0x38]
    //         004bcf5b     MOV        EDX,dword ptr [EBP + 0x30]
    //         004bcf5e     MOV        EAX,dword ptr [EBP]
    //         004bcf61     MOV        dword ptr [ESP + buffer_desc.dwFlags],0x14
    //         004bcf69     MOV        dword ptr [ESP + buffer_desc.dwBufferBytes],0xe2
    //         004bcf71     MOV        dword ptr [ESP + buffer_desc.dwReserved],this
    //         004bcf75     MOV        dword ptr [ESP + buffer_desc.lpwfxFormat],EDI
    //         004bcf79     MOV        dword ptr [ESP + wave_hdr.szRIFF[0]],EDX
    //         004bcf7d     MOV        EAX,dword ptr [EAX + 0x8]
    //         004bcf80     LEA        EDX=>buffer_desc.dwFlags,[ESP + 0x2c]
    //         004bcf84     MOV        this,dword ptr [EAX]
    //         004bcf86     PUSH       EDX
    //         004bcf87     PUSH       EAX
    //         004bcf88     CALL       dword ptr [ECX + this+0xc]
    //         004bcf8b     TEST       EAX,EAX
    //         004bcf8d     JZ         LAB_004bcfb8
    //                              Sounddrv.cpp:657 (15)
    //         004bcf8f     MOV        EAX,dword ptr [EBP + 0x30]
    //         004bcf92     MOV        byte ptr [EBP + 0x9],0x1
    //         004bcf96     PUSH       EAX
    //         004bcf97     MOV        dword ptr [EBX],ESI
    //         004bcf99     CALL       free                                             undefined free()
    //                              Sounddrv.cpp:660 (18)
    //         004bcf9e     MOV        this,dword ptr [EBP + 0x2c]
    //         004bcfa1     ADD        ESP,0x4
    //         004bcfa4     MOV        dword ptr [EBP + 0x30],ESI
    //         004bcfa7     PUSH       this
    //         004bcfa8     CALL       free                                             undefined free()
    //         004bcfad     ADD        ESP,0x4
    //                              Sounddrv.cpp:661 (3)
    //         004bcfb0     MOV        dword ptr [EBP + 0x2c],ESI
    //                              Sounddrv.cpp:665 (5)
    //         004bcfb3     JMP        LAB_004bd2d3
    //                               LAB_004bcfb8                                                 XREF[1]:     004bcf8d(j)  
    //                              Sounddrv.cpp:669 (38)
    //         004bcfb8     LEA        this,[ESP + 0x14]
    //         004bcfbc     PUSH       ESI
    //         004bcfbd     PUSH       this=>DAT_fffffff8
    //         004bcfbe     LEA        this,[ESP + 0x20]
    //         004bcfc2     MOV        EAX,dword ptr [EBX]
    //         004bcfc4     PUSH       this=>DAT_fffffff4
    //         004bcfc5     LEA        this,[ESP + 0x1c]
    //         004bcfc9     MOV        EDX,dword ptr [EAX]
    //         004bcfcb     PUSH       this=>DAT_fffffff0
    //         004bcfcc     LEA        this,[ESP + 0x2c]
    //         004bcfd0     PUSH       this
    //         004bcfd1     MOV        this,dword ptr [EBP + 0x38]
    //         004bcfd4     PUSH       this
    //         004bcfd5     PUSH       ESI
    //         004bcfd6     PUSH       EAX
    //         004bcfd7     CALL       dword ptr [EDX + 0x2c]
    //         004bcfda     TEST       EAX,EAX
    //         004bcfdc     JNZ        LAB_004bd05b
    //                              Sounddrv.cpp:671 (25)
    //         004bcfde     MOV        this,dword ptr [ESP + 0x10]
    //         004bcfe2     MOV        ESI,dword ptr [EBP + 0x2c]
    //         004bcfe5     MOV        EDI,dword ptr [ESP + 0x1c]
    //         004bcfe9     MOV        EDX,this
    //         004bcfeb     SHR        this,0x2
    //         004bcfee     MOVSD.REP  ES:EDI,ESI
    //         004bcff0     MOV        this,EDX
    //         004bcff2     AND        this,0x3
    //         004bcff5     MOVSB.REP  ES:EDI,ESI
    //                              Sounddrv.cpp:673 (8)
    //         004bcff7     MOV        this,dword ptr [ESP + 0x14]
    //         004bcffb     TEST       this,this
    //         004bcffd     JZ         LAB_004bd01e
    //                              Sounddrv.cpp:674 (31)
    //         004bcfff     MOV        ESI,dword ptr [ESP + 0x10]
    //         004bd003     MOV        EDI,dword ptr [EBP + 0x2c]
    //         004bd006     MOV        EAX,this
    //         004bd008     ADD        ESI,EDI
    //         004bd00a     MOV        EDI,dword ptr [ESP + 0x18]
    //         004bd00e     SHR        this,0x2
    //         004bd011     MOVSD.REP  ES:EDI,ESI
    //         004bd013     MOV        this,EAX
    //         004bd015     AND        this,0x3
    //         004bd018     MOVSB.REP  ES:EDI,ESI
    //         004bd01a     MOV        this,dword ptr [ESP + 0x14]
    //                               LAB_004bd01e                                                 XREF[1]:     004bcffd(j)  
    //                              Sounddrv.cpp:676 (24)
    //         004bd01e     MOV        EAX,dword ptr [ESP + 0x18]
    //         004bd022     MOV        EBX,dword ptr [EBX]
    //         004bd024     PUSH       this
    //         004bd025     MOV        this,dword ptr [ESP + 0x14]
    //         004bd029     MOV        EDX,dword ptr [EBX]
    //         004bd02b     PUSH       EAX=>DAT_fffffff8
    //         004bd02c     MOV        EAX,dword ptr [ESP + 0x24]
    //         004bd030     PUSH       this=>DAT_fffffff4
    //         004bd031     PUSH       EAX=>DAT_fffffff0
    //         004bd032     PUSH       EBX
    //         004bd033     CALL       dword ptr [EDX + 0x4c]
    //                              Sounddrv.cpp:696 (9)
    //         004bd036     MOV        this,dword ptr [EBP + 0x30]
    //         004bd039     PUSH       this
    //         004bd03a     CALL       free                                             undefined free()
    //                              Sounddrv.cpp:699 (20)
    //         004bd03f     MOV        EDX,dword ptr [EBP + 0x2c]
    //         004bd042     ADD        ESP,0x4
    //         004bd045     XOR        ESI,ESI
    //         004bd047     PUSH       EDX
    //         004bd048     MOV        dword ptr [EBP + 0x30],ESI
    //         004bd04b     CALL       free                                             undefined free()
    //         004bd050     ADD        ESP,0x4
    //                              Sounddrv.cpp:700 (3)
    //         004bd053     MOV        dword ptr [EBP + 0x2c],ESI
    //                              Sounddrv.cpp:706 (5)
    //         004bd056     JMP        LAB_004bd289
    //                               LAB_004bd05b                                                 XREF[1]:     004bcfdc(j)  
    //                              Sounddrv.cpp:681 (12)
    //         004bd05b     MOV        EAX,dword ptr [EBX]
    //         004bd05d     MOV        byte ptr [EBP + 0x9],0x1
    //         004bd061     PUSH       EAX
    //         004bd062     MOV        this,dword ptr [EAX]
    //         004bd064     CALL       dword ptr [ECX + this->loaded]
    //                              Sounddrv.cpp:684 (11)
    //         004bd067     MOV        EDX,dword ptr [EBP + 0x30]
    //         004bd06a     MOV        dword ptr [EBX],ESI
    //         004bd06c     PUSH       EDX
    //         004bd06d     CALL       free                                             undefined free()
    //                              Sounddrv.cpp:687 (18)
    //         004bd072     MOV        EAX,dword ptr [EBP + 0x2c]
    //         004bd075     ADD        ESP,0x4
    //         004bd078     MOV        dword ptr [EBP + 0x30],ESI
    //         004bd07b     PUSH       EAX
    //         004bd07c     CALL       free                                             undefined free()
    //         004bd081     ADD        ESP,0x4
    //                              Sounddrv.cpp:688 (3)
    //         004bd084     MOV        dword ptr [EBP + 0x2c],ESI
    //                              Sounddrv.cpp:692 (5)
    //         004bd087     JMP        LAB_004bd2d3
    //                               LAB_004bd08c                                                 XREF[2]:     004bce6a(j), 004bce76(j)  
    //                              Sounddrv.cpp:587 (13)
    //         004bd08c     PUSH       ESI
    //         004bd08d     MOV        byte ptr [EBP + 0x9],0x1
    //         004bd091     CALL       close                                            undefined close()
    //         004bd096     ADD        ESP,0x4
    //                              Sounddrv.cpp:590 (5)
    //         004bd099     JMP        LAB_004bd2d3
    //                               LAB_004bd09e                                                 XREF[2]:     004bcdf4(j), 004bce28(j)  
    //                              Sounddrv.cpp:712 (9)
    //         004bd09e     CMP        EBX,-0x1
    //         004bd0a1     JLE        LAB_004bd2cf
    //                              Sounddrv.cpp:715 (26)
    //         004bd0a7     LEA        this=>file_with_path,[ESP + 0x64]
    //         004bd0ab     LEA        EDX=>buffer_desc,[ESP + 0x20]
    //         004bd0af     PUSH       this
    //         004bd0b0     PUSH       EDX
    //         004bd0b1     PUSH       EBX
    //         004bd0b2     PUSH       0x77617620
    //         004bd0b7     CALL       RESFILE_load                                     uchar * RESFILE_load(ulong param_1, ulong par
    //         004bd0bc     MOV        EBX,EAX
    //         004bd0be     ADD        ESP,0x10
    //                              Sounddrv.cpp:717 (2)
    //         004bd0c1     CMP        EBX,EDI
    //                              Sounddrv.cpp:722 (6)
    //         004bd0c3     JZ         LAB_004bd2cf
    //                              Sounddrv.cpp:725 (13)
    //         004bd0c9     MOV        this,0xb
    //         004bd0ce     MOV        ESI,EBX
    //         004bd0d0     LEA        EDI=>wave_hdr.dwFormatLength,[ESP + 0x38]
    //         004bd0d4     MOVSD.REP  ES:EDI,ESI
    //                              Sounddrv.cpp:726 (4)
    //         004bd0d6     MOV        EAX,dword ptr [ESP + resDataSize]
    //                              Sounddrv.cpp:731 (15)
    //         004bd0da     PUSH       EAX
    //         004bd0db     MOV        dword ptr [EBP + 0x38],EAX
    //         004bd0de     CALL       malloc                                           undefined malloc()
    //         004bd0e3     ADD        ESP,0x4
    //         004bd0e6     MOV        dword ptr [EBP + 0x2c],EAX
    //                              Sounddrv.cpp:732 (4)
    //         004bd0e9     TEST       EAX,EAX
    //         004bd0eb     JNZ        LAB_004bd10c
    //                              Sounddrv.cpp:735 (17)
    //         004bd0ed     MOV        EAX,dword ptr [ESP + buffer_desc.dwSize]
    //         004bd0f1     MOV        byte ptr [EBP + 0x9],0x1
    //         004bd0f5     CMP        EAX,0x1
    //         004bd0f8     JNZ        LAB_004bd2d3
    //                              Sounddrv.cpp:736 (9)
    //         004bd0fe     PUSH       EBX
    //         004bd0ff     CALL       free                                             undefined free()
    //         004bd104     ADD        ESP,0x4
    //                              Sounddrv.cpp:739 (5)
    //         004bd107     JMP        LAB_004bd2d3
    //                               LAB_004bd10c                                                 XREF[1]:     004bd0eb(j)  
    //                              Sounddrv.cpp:741 (22)
    //         004bd10c     MOV        this,dword ptr [EBP + 0x38]
    //         004bd10f     MOV        EDI,EAX
    //         004bd111     MOV        EAX,this
    //         004bd113     LEA        ESI,[EBX + 0x2c]
    //         004bd116     SHR        this,0x2
    //         004bd119     MOVSD.REP  ES:EDI,ESI
    //         004bd11b     MOV        this,EAX
    //         004bd11d     AND        this,0x3
    //         004bd120     MOVSB.REP  ES:EDI,ESI
    //                              Sounddrv.cpp:744 (13)
    //         004bd122     MOV        EAX,dword ptr [ESP + buffer_desc.dwSize]
    //         004bd126     MOV        ESI,0x1
    //         004bd12b     CMP        EAX,ESI
    //         004bd12d     JNZ        LAB_004bd138
    //                              Sounddrv.cpp:745 (9)
    //         004bd12f     PUSH       EBX
    //         004bd130     CALL       free                                             undefined free()
    //         004bd135     ADD        ESP,0x4
    //                               LAB_004bd138                                                 XREF[1]:     004bd12d(j)  
    //                              Sounddrv.cpp:748 (7)
    //         004bd138     PUSH       0x12
    //         004bd13a     CALL       malloc                                           undefined malloc()
    //                              Sounddrv.cpp:749 (12)
    //         004bd13f     XOR        this,this
    //         004bd141     ADD        ESP,0x4
    //         004bd144     CMP        EAX,this
    //         004bd146     MOV        dword ptr [EBP + 0x30],EAX
    //         004bd149     JNZ        LAB_004bd166
    //                              Sounddrv.cpp:752 (12)
    //         004bd14b     MOV        EAX,dword ptr [ESP + buffer_desc.dwSize]
    //         004bd14f     MOV        byte ptr [EBP + 0x9],0x1
    //         004bd153     CMP        EAX,ESI
    //         004bd155     JNZ        LAB_004bd160
    //                              Sounddrv.cpp:753 (9)
    //         004bd157     PUSH       EBX
    //         004bd158     CALL       free                                             undefined free()
    //         004bd15d     ADD        ESP,0x4
    //                               LAB_004bd160                                                 XREF[1]:     004bd155(j)  
    //                              Sounddrv.cpp:754 (1)
    //         004bd160     PUSH       ESI
    //                              Sounddrv.cpp:756 (5)
    //         004bd161     JMP        LAB_004bd2d5
    //                               LAB_004bd166                                                 XREF[1]:     004bd149(j)  
    //                              Sounddrv.cpp:759 (5)
    //         004bd166     MOV        DX,word ptr [ESP + wave_hdr.nSamplesPerSec]
    //                              Sounddrv.cpp:774 (128)
    //         004bd16b     XOR        ESI,ESI
    //         004bd16d     MOV        word ptr [EAX],DX
    //         004bd170     MOV        EAX,dword ptr [EBP + 0x30]
    //         004bd173     MOV        DX,word ptr [ESP + wave_hdr+0x1a]
    //         004bd178     LEA        EBX,[EBP + 0x34]
    //         004bd17b     MOV        word ptr [EAX + 0x2],DX
    //         004bd17f     MOV        EAX,dword ptr [EBP + 0x30]
    //         004bd182     MOV        EDX,dword ptr [ESP + wave_hdr.nAvgBytesPerSec]
    //         004bd186     PUSH       ESI
    //         004bd187     MOV        dword ptr [EAX + 0x4],EDX
    //         004bd18a     MOV        EAX,dword ptr [EBP + 0x30]
    //         004bd18d     MOV        EDX,dword ptr [ESP + wave_hdr.nBlockAlign]
    //         004bd191     PUSH       EBX
    //         004bd192     MOV        dword ptr [EAX + 0x8],EDX
    //         004bd195     MOV        EAX,dword ptr [EBP + 0x30]
    //         004bd198     MOV        DX,word ptr [ESP + wave_hdr.szDATA[0]]
    //         004bd19d     MOV        word ptr [EAX + 0xc],DX
    //         004bd1a1     MOV        EAX,dword ptr [EBP + 0x30]
    //         004bd1a4     MOV        DX,word ptr [ESP + wave_hdr+0x26]
    //         004bd1a9     MOV        word ptr [EAX + 0xe],DX
    //         004bd1ad     MOV        EAX,dword ptr [EBP + 0x30]
    //         004bd1b0     MOV        word ptr [EAX + 0x10],this
    //         004bd1b4     MOV        EDX,dword ptr [EBP + 0x38]
    //         004bd1b7     MOV        EAX,dword ptr [EBP + 0x30]
    //         004bd1ba     MOV        dword ptr [ESP + buffer_desc.lpwfxFormat],this
    //         004bd1be     MOV        this,dword ptr [EBP]
    //         004bd1c1     MOV        dword ptr [ESP + buffer_desc.dwFlags],0x14
    //         004bd1c9     MOV        dword ptr [ESP + buffer_desc.dwBufferBytes],0xe2
    //         004bd1d1     MOV        dword ptr [ESP + buffer_desc.dwReserved],EDX
    //         004bd1d5     MOV        dword ptr [ESP + wave_hdr.szRIFF[0]],EAX
    //         004bd1d9     MOV        EAX,dword ptr [ECX + this->loaded]
    //         004bd1dc     LEA        this=>buffer_desc.dwFlags,[ESP + 0x2c]
    //         004bd1e0     MOV        EDX,dword ptr [EAX]
    //         004bd1e2     PUSH       this
    //         004bd1e3     PUSH       EAX
    //         004bd1e4     CALL       dword ptr [EDX + 0xc]
    //         004bd1e7     TEST       EAX,EAX
    //         004bd1e9     JZ         LAB_004bd1f4
    //                              Sounddrv.cpp:776 (4)
    //         004bd1eb     MOV        byte ptr [EBP + 0x9],0x1
    //                              Sounddrv.cpp:784 (5)
    //         004bd1ef     JMP        LAB_004bd2bc
    //                               LAB_004bd1f4                                                 XREF[1]:     004bd1e9(j)  
    //                              Sounddrv.cpp:788 (42)
    //         004bd1f4     LEA        EDX,[ESP + 0x14]
    //         004bd1f8     PUSH       ESI
    //         004bd1f9     PUSH       EDX=>DAT_fffffff8
    //         004bd1fa     LEA        EDX,[ESP + 0x20]
    //         004bd1fe     MOV        EAX,dword ptr [EBX]
    //         004bd200     PUSH       EDX=>DAT_fffffff4
    //         004bd201     LEA        EDX,[ESP + 0x1c]
    //         004bd205     MOV        this,dword ptr [EAX]
    //         004bd207     PUSH       EDX=>DAT_fffffff0
    //         004bd208     LEA        EDX,[ESP + 0x2c]
    //         004bd20c     PUSH       EDX
    //         004bd20d     MOV        EDX,dword ptr [EBP + 0x38]
    //         004bd210     PUSH       EDX
    //         004bd211     PUSH       ESI
    //         004bd212     PUSH       EAX
    //         004bd213     CALL       dword ptr [ECX + this->wave_data]
    //         004bd216     TEST       EAX,EAX
    //         004bd218     JNZ        LAB_004bd2b0
    //                              Sounddrv.cpp:790 (25)
    //         004bd21e     MOV        this,dword ptr [ESP + 0x10]
    //         004bd222     MOV        ESI,dword ptr [EBP + 0x2c]
    //         004bd225     MOV        EDI,dword ptr [ESP + 0x1c]
    //         004bd229     MOV        EAX,this
    //         004bd22b     SHR        this,0x2
    //         004bd22e     MOVSD.REP  ES:EDI,ESI
    //         004bd230     MOV        this,EAX
    //         004bd232     AND        this,0x3
    //         004bd235     MOVSB.REP  ES:EDI,ESI
    //                              Sounddrv.cpp:792 (8)
    //         004bd237     MOV        this,dword ptr [ESP + 0x14]
    //         004bd23b     TEST       this,this
    //         004bd23d     JZ         LAB_004bd25e
    //                              Sounddrv.cpp:793 (31)
    //         004bd23f     MOV        ESI,dword ptr [ESP + 0x10]
    //         004bd243     MOV        EDX,dword ptr [EBP + 0x2c]
    //         004bd246     MOV        EDI,dword ptr [ESP + 0x18]
    //         004bd24a     ADD        ESI,EDX
    //         004bd24c     MOV        EDX,this
    //         004bd24e     SHR        this,0x2
    //         004bd251     MOVSD.REP  ES:EDI,ESI
    //         004bd253     MOV        this,EDX
    //         004bd255     AND        this,0x3
    //         004bd258     MOVSB.REP  ES:EDI,ESI
    //         004bd25a     MOV        this,dword ptr [ESP + 0x14]
    //                               LAB_004bd25e                                                 XREF[1]:     004bd23d(j)  
    //                              Sounddrv.cpp:795 (24)
    //         004bd25e     MOV        EBX,dword ptr [EBX]
    //         004bd260     MOV        EDX,dword ptr [ESP + 0x10]
    //         004bd264     PUSH       this
    //         004bd265     MOV        this,dword ptr [ESP + 0x1c]
    //         004bd269     MOV        EAX,dword ptr [EBX]
    //         004bd26b     PUSH       this=>DAT_fffffff8
    //         004bd26c     MOV        this,dword ptr [ESP + 0x24]
    //         004bd270     PUSH       EDX=>DAT_fffffff4
    //         004bd271     PUSH       this=>DAT_fffffff0
    //         004bd272     PUSH       EBX
    //         004bd273     CALL       dword ptr [EAX + 0x4c]
    //                              Sounddrv.cpp:812 (12)
    //         004bd276     MOV        EDX,dword ptr [EBP + 0x30]
    //         004bd279     PUSH       EDX
    //         004bd27a     CALL       free                                             undefined free()
    //         004bd27f     ADD        ESP,0x4
    //                              Sounddrv.cpp:813 (7)
    //         004bd282     MOV        dword ptr [EBP + 0x30],0x0
    //                               LAB_004bd289                                                 XREF[1]:     004bd056(j)  
    //                              Sounddrv.cpp:817 (21)
    //         004bd289     PUSH       0x1
    //         004bd28b     PUSH       offset DAT_fffffff8
    //         004bd28d     PUSH       offset DAT_fffffff4
    //         004bd292     MOV        byte ptr [EBP + 0x8],0x1
    //         004bd296     CALL       color_log                                        void color_log(uchar param_1, uchar param_2, 
    //         004bd29b     ADD        ESP,0xc
    //                              Sounddrv.cpp:819 (5)
    //         004bd29e     MOV        EAX,0x1
    //                              Sounddrv.cpp:826 (13)
    //         004bd2a3     POP        EDI
    //         004bd2a4     POP        ESI
    //         004bd2a5     POP        EBP
    //         004bd2a6     POP        EBX
    //         004bd2a7     ADD        ESP,0x15c
    //         004bd2ad     RET        0x8
    //                               LAB_004bd2b0                                                 XREF[1]:     004bd218(j)  
    //                              Sounddrv.cpp:800 (12)
    //         004bd2b0     MOV        EAX,dword ptr [EBX]
    //         004bd2b2     MOV        byte ptr [EBP + 0x9],0x1
    //         004bd2b6     PUSH       EAX
    //         004bd2b7     MOV        this,dword ptr [EAX]
    //         004bd2b9     CALL       dword ptr [ECX + this->loaded]
    //                               LAB_004bd2bc                                                 XREF[1]:     004bd1ef(j)  
    //                              Sounddrv.cpp:803 (14)
    //         004bd2bc     MOV        EDX,dword ptr [EBP + 0x30]
    //         004bd2bf     MOV        dword ptr [EBX],ESI
    //         004bd2c1     PUSH       EDX
    //         004bd2c2     CALL       free                                             undefined free()
    //         004bd2c7     ADD        ESP,0x4
    //                              Sounddrv.cpp:804 (3)
    //         004bd2ca     MOV        dword ptr [EBP + 0x30],ESI
    //                              Sounddrv.cpp:808 (2)
    //         004bd2cd     JMP        LAB_004bd2d3
    //                               LAB_004bd2cf                                                 XREF[2]:     004bd0a1(j), 004bd0c3(j)  
    //                              Sounddrv.cpp:822 (4)
    //         004bd2cf     MOV        byte ptr [EBP + 0x9],0x1
    //                               LAB_004bd2d3                                                 XREF[11]:    004bcdd3(j), 004bce4f(j), 
    //                                                                                                         004bcea0(j), 004bced3(j), 
    //                                                                                                         004bcf05(j), 004bcfb3(j), 
    //                                                                                                         004bd087(j), 004bd099(j), 
    //                                                                                                         004bd0f8(j), 004bd107(j), 
    //                                                                                                         004bd2cd(j)  
    //                              Sounddrv.cpp:823 (17)
    //         004bd2d3     PUSH       0x1
    //                               LAB_004bd2d5                                                 XREF[1]:     004bd161(j)  
    //         004bd2d5     PUSH       offset DAT_fffffff8
    //         004bd2d7     PUSH       offset DAT_fffffff4
    //         004bd2dc     CALL       color_log                                        void color_log(uchar param_1, uchar param_2, 
    //         004bd2e1     ADD        ESP,0xc
    //                               LAB_004bd2e4                                                 XREF[2]:     004bcd59(j), 004bcd85(j)  
    //                              Sounddrv.cpp:826 (15)
    //         004bd2e4     POP        EDI
    //         004bd2e5     POP        ESI
    //         004bd2e6     POP        EBP
    //         004bd2e7     XOR        EAX,EAX
    //         004bd2e9     POP        EBX
    //         004bd2ea     ADD        ESP,0x15c
    //         004bd2f0     RET        0x8
}

// Offset: 0x004BD300
void unload(TDigital* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TDigital::unload(void)                                                        *
    //                              *********************************************************************************************************
    //                              void __thiscall unload(TDigital * this)
    //              void              <VOID>         <RETURN>
    //              TDigital *        ECX:4 (auto)   this
    //                               ?unload@TDigital@@QAEXXZ                                     XREF[5]:     update:004bc2af(c), 
    //                               TDigital::unload                                                          exit:004bcd18(c), 
    //                                                                                                         load:004bcda8(c), 
    //                                                                                                         PlayTauntNo:00509592(c), 
    //                                                                                                         PlayTauntNo:005095ee(c)  
    //                              Sounddrv.cpp:832 (4)
    //         004bd300     PUSH       EBX
    //         004bd301     PUSH       ESI
    //         004bd302     MOV        ESI,this
    //                              Sounddrv.cpp:833 (9)
    //         004bd304     XOR        EBX,EBX
    //         004bd306     MOV        EAX,dword ptr [ESI + 0x4]
    //         004bd309     CMP        EAX,EBX
    //         004bd30b     JZ         LAB_004bd316
    //                               LAB_004bd30d                                                 XREF[1]:     004bd314(j)  
    //                              Sounddrv.cpp:835 (9)
    //         004bd30d     MOV        ESI,EAX
    //         004bd30f     MOV        EAX,dword ptr [ESI + 0x4]
    //         004bd312     CMP        EAX,EBX
    //         004bd314     JNZ        LAB_004bd30d
    //                               LAB_004bd316                                                 XREF[1]:     004bd30b(j)  
    //                              Sounddrv.cpp:839 (5)
    //         004bd316     CMP        byte ptr [ESI + 0x8],BL
    //         004bd319     JZ         LAB_004bd35b
    //                              Sounddrv.cpp:841 (7)
    //         004bd31b     MOV        this,ESI
    //         004bd31d     CALL       TDigital::stop                                   void stop(TDigital * this)
    //                              Sounddrv.cpp:843 (7)
    //         004bd322     MOV        EAX,dword ptr [ESI + 0x34]
    //         004bd325     CMP        EAX,EBX
    //         004bd327     JZ         LAB_004bd332
    //                              Sounddrv.cpp:845 (6)
    //         004bd329     MOV        this,dword ptr [EAX]
    //         004bd32b     PUSH       EAX
    //         004bd32c     CALL       dword ptr [ECX + this->loaded]
    //                              Sounddrv.cpp:846 (3)
    //         004bd32f     MOV        dword ptr [ESI + 0x34],EBX
    //                               LAB_004bd332                                                 XREF[1]:     004bd327(j)  
    //                              Sounddrv.cpp:849 (7)
    //         004bd332     MOV        EAX,dword ptr [ESI + 0x2c]
    //         004bd335     CMP        EAX,EBX
    //         004bd337     JZ         LAB_004bd345
    //                              Sounddrv.cpp:851 (9)
    //         004bd339     PUSH       EAX
    //         004bd33a     CALL       free                                             undefined free()
    //         004bd33f     ADD        ESP,0x4
    //                              Sounddrv.cpp:852 (3)
    //         004bd342     MOV        dword ptr [ESI + 0x2c],EBX
    //                               LAB_004bd345                                                 XREF[1]:     004bd337(j)  
    //                              Sounddrv.cpp:855 (7)
    //         004bd345     MOV        EAX,dword ptr [ESI + 0x30]
    //         004bd348     CMP        EAX,EBX
    //         004bd34a     JZ         LAB_004bd358
    //                              Sounddrv.cpp:857 (9)
    //         004bd34c     PUSH       EAX
    //         004bd34d     CALL       free                                             undefined free()
    //         004bd352     ADD        ESP,0x4
    //                              Sounddrv.cpp:858 (3)
    //         004bd355     MOV        dword ptr [ESI + 0x30],EBX
    //                               LAB_004bd358                                                 XREF[1]:     004bd34a(j)  
    //                              Sounddrv.cpp:861 (3)
    //         004bd358     MOV        byte ptr [ESI + 0x8],BL
    //                               LAB_004bd35b                                                 XREF[1]:     004bd319(j)  
    //                              Sounddrv.cpp:864 (3)
    //         004bd35b     MOV        byte ptr [ESI + 0x9],BL
    //                              Sounddrv.cpp:865 (3)
    //         004bd35e     POP        ESI
    //         004bd35f     POP        EBX
    //         004bd360     RET
}

// Offset: 0x004BD370
int play(TDigital* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall TDigital::play(void)                                                           *
    //                              *********************************************************************************************************
    //                              int __thiscall play(TDigital * this)
    //              int               EAX:4          <RETURN>
    //              TDigital *        ECX:4 (auto)   this
    //              undefined         Stack[-0x4]:1  local_4                   XREF[1]:     004bd3cc(*)  
    //              ulong             Stack[-0x8]:4  status
    //                               ?play@TDigital@@QAEHXZ                                       XREF[15]:    play_sound:00422ea2(c), 
    //                               TDigital::play                                                            mouse_left_down_action:004731c8(c)
    //                                                                                                         mouse_right_down_action:004733d8(c
    //                                                                                                         handle_key_down:00473663(c), 
    //                                                                                                         key_down_action:004737e7(c), 
    //                                                                                                         char_action:0047719d(c), 
    //                                                                                                         char_action:004771b8(c), 
    //                                                                                                         char_action:004771d3(c), 
    //                                                                                                         insert_character:004779ed(c), 
    //                                                                                                         paste:00477d7d(c), 
    //                                                                                                         handle_game_update:00496d71(c), 
    //                                                                                                         key_down_action:004979b4(c), 
    //                                                                                                         play:004bc3fb(c), 
    //                                                                                                         play_list:004bca09(c), 
    //                                                                                                         PlayTauntNo:005095dd(c)  
    //                              Sounddrv.cpp:869 (6)
    //         004bd370     PUSH       this
    //         004bd371     PUSH       EBX
    //         004bd372     PUSH       ESI
    //         004bd373     PUSH       EDI
    //         004bd374     MOV        EDI,this
    //                              Sounddrv.cpp:875 (7)
    //         004bd376     MOV        ESI,dword ptr [EDI + 0x4]
    //         004bd379     TEST       ESI,ESI
    //         004bd37b     JNZ        LAB_004bd37f
    //                              Sounddrv.cpp:876 (2)
    //         004bd37d     MOV        ESI,EDI
    //                               LAB_004bd37f                                                 XREF[1]:     004bd37b(j)  
    //                              Sounddrv.cpp:880 (30)
    //         004bd37f     MOV        EAX,dword ptr [ESI]
    //         004bd381     TEST       EAX,EAX
    //         004bd383     JZ         LAB_004bd47a
    //         004bd389     CMP        byte ptr [EAX],0x0
    //         004bd38c     JZ         LAB_004bd47a
    //         004bd392     MOV        this,byte ptr [EAX + 0x1]
    //         004bd395     TEST       this,this
    //         004bd397     JNZ        LAB_004bd47a
    //                              Sounddrv.cpp:882 (7)
    //         004bd39d     MOV        AL,byte ptr [ESI + 0x8]
    //         004bd3a0     TEST       AL,AL
    //         004bd3a2     JNZ        LAB_004bd3ba
    //                              Sounddrv.cpp:884 (17)
    //         004bd3a4     LEA        EAX,[EDI + 0xa]
    //         004bd3a7     PUSH       -0x1
    //         004bd3a9     PUSH       EAX
    //         004bd3aa     MOV        this,ESI
    //         004bd3ac     CALL       TDigital::load                                   int load(TDigital * this, char * param_1, lon
    //         004bd3b1     TEST       EAX,EAX
    //         004bd3b3     JNZ        LAB_004bd3ba
    //                              Sounddrv.cpp:930 (5)
    //         004bd3b5     POP        EDI
    //         004bd3b6     POP        ESI
    //         004bd3b7     POP        EBX
    //         004bd3b8     POP        this
    //         004bd3b9     RET
    //                               LAB_004bd3ba                                                 XREF[2]:     004bd3a2(j), 004bd3b3(j)  
    //                              Sounddrv.cpp:888 (7)
    //         004bd3ba     MOV        EAX,dword ptr [ESI + 0x34]
    //         004bd3bd     TEST       EAX,EAX
    //         004bd3bf     JNZ        LAB_004bd3ca
    //                              Sounddrv.cpp:890 (4)
    //         004bd3c1     MOV        byte ptr [ESI + 0x9],0x1
    //                              Sounddrv.cpp:930 (5)
    //         004bd3c5     POP        EDI
    //         004bd3c6     POP        ESI
    //         004bd3c7     POP        EBX
    //         004bd3c8     POP        this
    //         004bd3c9     RET
    //                               LAB_004bd3ca                                                 XREF[1]:     004bd3bf(j)  
    //                              Sounddrv.cpp:894 (11)
    //         004bd3ca     MOV        this,dword ptr [EAX]
    //         004bd3cc     LEA        EDX=>local_4,[ESP + 0xc]
    //         004bd3d0     PUSH       EDX
    //         004bd3d1     PUSH       EAX
    //         004bd3d2     CALL       dword ptr [ECX + this->pan]
    //                              Sounddrv.cpp:904 (3)
    //         004bd3d5     MOV        EAX,dword ptr [ESI + 0x28]
    //                              Sounddrv.cpp:909 (20)
    //         004bd3d8     MOV        EDX,dword ptr [EDI + 0x1c]
    //         004bd3db     XOR        EBX,EBX
    //         004bd3dd     PUSH       EDX
    //         004bd3de     TEST       EAX,EAX
    //         004bd3e0     MOV        EAX,dword ptr [ESI + 0x34]
    //         004bd3e3     PUSH       EAX=>DAT_fffffff8
    //         004bd3e4     MOV        this,dword ptr [EAX]
    //         004bd3e6     SETNZ      BL
    //         004bd3e9     CALL       dword ptr [ECX + this+0x3c]
    //                              Sounddrv.cpp:910 (13)
    //         004bd3ec     MOV        EAX,dword ptr [ESI + 0x34]
    //         004bd3ef     MOV        EDX,dword ptr [EDI + 0x20]
    //         004bd3f2     PUSH       EDX
    //         004bd3f3     PUSH       EAX=>DAT_fffffff8
    //         004bd3f4     MOV        this,dword ptr [EAX]
    //         004bd3f6     CALL       dword ptr [this->sound_system + 0x44]
    //                              Sounddrv.cpp:911 (13)
    //         004bd3f9     MOV        EAX,dword ptr [ESI + 0x34]
    //         004bd3fc     MOV        EDX,dword ptr [EDI + 0x24]
    //         004bd3ff     PUSH       EDX
    //         004bd400     PUSH       EAX=>DAT_fffffff8
    //         004bd401     MOV        this,dword ptr [EAX]
    //         004bd403     CALL       dword ptr [this->sound_system + 0x40]
    //                              Sounddrv.cpp:912 (11)
    //         004bd406     MOV        EAX,dword ptr [ESI + 0x34]
    //         004bd409     PUSH       0x0
    //         004bd40b     PUSH       EAX=>DAT_fffffff8
    //         004bd40c     MOV        this,dword ptr [EAX]
    //         004bd40e     CALL       dword ptr [ECX + this->sound_buffer]
    //                              Sounddrv.cpp:913 (14)
    //         004bd411     MOV        EAX,dword ptr [ESI + 0x34]
    //         004bd414     PUSH       EBX
    //         004bd415     PUSH       0x0=>DAT_fffffff8
    //         004bd417     PUSH       0x0=>DAT_fffffff4
    //         004bd419     MOV        EDX,dword ptr [EAX]
    //         004bd41b     PUSH       EAX=>DAT_fffffff0
    //         004bd41c     CALL       dword ptr [EDX + 0x30]
    //                              Sounddrv.cpp:915 (7)
    //         004bd41f     CMP        EAX,0x88780096
    //         004bd424     JNZ        LAB_004bd47a
    //                              Sounddrv.cpp:918 (15)
    //         004bd426     PUSH       -0x1
    //         004bd428     PUSH       0x0=>DAT_fffffff8
    //         004bd42a     MOV        this,ESI
    //         004bd42c     CALL       TDigital::load                                   int load(TDigital * this, char * param_1, lon
    //         004bd431     TEST       EAX,EAX
    //         004bd433     JNZ        LAB_004bd43a
    //                              Sounddrv.cpp:930 (5)
    //         004bd435     POP        EDI
    //         004bd436     POP        ESI
    //         004bd437     POP        EBX
    //         004bd438     POP        this
    //         004bd439     RET
    //                               LAB_004bd43a                                                 XREF[1]:     004bd433(j)  
    //                              Sounddrv.cpp:921 (13)
    //         004bd43a     MOV        EAX,dword ptr [ESI + 0x34]
    //         004bd43d     MOV        EDX,dword ptr [EDI + 0x1c]
    //         004bd440     PUSH       EDX
    //         004bd441     PUSH       EAX=>DAT_fffffff8
    //         004bd442     MOV        this,dword ptr [EAX]
    //         004bd444     CALL       dword ptr [ECX + this+0x3c]
    //                              Sounddrv.cpp:922 (13)
    //         004bd447     MOV        EAX,dword ptr [ESI + 0x34]
    //         004bd44a     MOV        EDX,dword ptr [EDI + 0x20]
    //         004bd44d     PUSH       EDX
    //         004bd44e     PUSH       EAX=>DAT_fffffff8
    //         004bd44f     MOV        this,dword ptr [EAX]
    //         004bd451     CALL       dword ptr [this->sound_system + 0x44]
    //                              Sounddrv.cpp:923 (13)
    //         004bd454     MOV        EAX,dword ptr [ESI + 0x34]
    //         004bd457     MOV        EDX,dword ptr [EDI + 0x24]
    //         004bd45a     PUSH       EDX
    //         004bd45b     PUSH       EAX=>DAT_fffffff8
    //         004bd45c     MOV        this,dword ptr [EAX]
    //         004bd45e     CALL       dword ptr [this->sound_system + 0x40]
    //                              Sounddrv.cpp:924 (11)
    //         004bd461     MOV        EAX,dword ptr [ESI + 0x34]
    //         004bd464     PUSH       0x0
    //         004bd466     PUSH       EAX=>DAT_fffffff8
    //         004bd467     MOV        this,dword ptr [EAX]
    //         004bd469     CALL       dword ptr [ECX + this->sound_buffer]
    //                              Sounddrv.cpp:925 (14)
    //         004bd46c     MOV        ESI,dword ptr [ESI + 0x34]
    //         004bd46f     PUSH       EBX
    //         004bd470     PUSH       0x0=>DAT_fffffff8
    //         004bd472     PUSH       0x0=>DAT_fffffff4
    //         004bd474     MOV        EDX,dword ptr [ESI]
    //         004bd476     PUSH       ESI=>DAT_fffffff0
    //         004bd477     CALL       dword ptr [EDX + 0x30]
    //                               LAB_004bd47a                                                 XREF[4]:     004bd383(j), 004bd38c(j), 
    //                                                                                                         004bd397(j), 004bd424(j)  
    //                              Sounddrv.cpp:930 (10)
    //         004bd47a     POP        EDI
    //         004bd47b     POP        ESI
    //         004bd47c     MOV        EAX,0x1
    //         004bd481     POP        EBX
    //         004bd482     POP        this
    //         004bd483     RET
}

// Offset: 0x004BD490
void stop(TDigital* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TDigital::stop(void)                                                          *
    //                              *********************************************************************************************************
    //                              void __thiscall stop(TDigital * this)
    //              void              <VOID>         <RETURN>
    //              TDigital *        ECX:4 (auto)   this
    //                               ?stop@TDigital@@QAEXXZ                                       XREF[8]:     mouse_left_down_action:004731bd(c)
    //                               TDigital::stop                                                            mouse_right_down_action:004733cd(c
    //                                                                                                         handle_key_down:00473658(c), 
    //                                                                                                         key_down_action:004737dc(c), 
    //                                                                                                         ~TRIBE_Screen_Game:004954f4(c), 
    //                                                                                                         stop:004bc522(c), 
    //                                                                                                         exit:004bcd11(c), 
    //                                                                                                         unload:004bd31d(c)  
    //                              Sounddrv.cpp:934 (7)
    //         004bd490     MOV        EAX,dword ptr [ECX + this->owner]
    //         004bd493     TEST       EAX,EAX
    //         004bd495     JZ         LAB_004bd4a0
    //                               LAB_004bd497                                                 XREF[1]:     004bd49e(j)  
    //                              Sounddrv.cpp:937 (9)
    //         004bd497     MOV        this,EAX
    //         004bd499     MOV        EAX,dword ptr [ECX + this->owner]
    //         004bd49c     TEST       EAX,EAX
    //         004bd49e     JNZ        LAB_004bd497
    //                               LAB_004bd4a0                                                 XREF[1]:     004bd495(j)  
    //                              Sounddrv.cpp:941 (25)
    //         004bd4a0     MOV        EAX,dword ptr [this->sound_system]
    //         004bd4a2     TEST       EAX,EAX
    //         004bd4a4     JZ         LAB_004bd4bf
    //         004bd4a6     CMP        byte ptr [EAX],0x0
    //         004bd4a9     JZ         LAB_004bd4bf
    //         004bd4ab     MOV        AL,byte ptr [ECX + this->loaded]
    //         004bd4ae     TEST       AL,AL
    //         004bd4b0     JZ         LAB_004bd4bf
    //         004bd4b2     MOV        this,dword ptr [ECX + this->sound_buffer]
    //         004bd4b5     TEST       this,this
    //         004bd4b7     JZ         LAB_004bd4bf
    //                              Sounddrv.cpp:942 (6)
    //         004bd4b9     MOV        EAX,dword ptr [this->sound_system]
    //         004bd4bb     PUSH       this
    //         004bd4bc     CALL       dword ptr [EAX + 0x48]
    //                               LAB_004bd4bf                                                 XREF[4]:     004bd4a4(j), 004bd4a9(j), 
    //                                                                                                         004bd4b0(j), 004bd4b7(j)  
    //                              Sounddrv.cpp:943 (1)
    //         004bd4bf     RET
}

// Offset: 0x004BD4C0
void set_loop(TDigital* this_, short param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TDigital::set_loop(short)                                                     *
    //                              *********************************************************************************************************
    //                              void __thiscall set_loop(TDigital * this, short param_1)
    //              void              <VOID>         <RETURN>
    //              TDigital *        ECX:4 (auto)   this
    //              short             Stack[0x4]:2   param_1                   XREF[1]:     004bd4c0(R)  
    //                               ?set_loop@TDigital@@QAEXF@Z
    //                               TDigital::set_loop
    //                              Sounddrv.cpp:947 (8)
    //         004bd4c0     CMP        word ptr [ESP + param_1],0x0
    //         004bd4c6     JNZ        LAB_004bd4d2
    //                              Sounddrv.cpp:949 (7)
    //         004bd4c8     MOV        dword ptr [ECX + this->loop],0x0
    //                              Sounddrv.cpp:952 (3)
    //         004bd4cf     RET        0x4
    //                               LAB_004bd4d2                                                 XREF[1]:     004bd4c6(j)  
    //                              Sounddrv.cpp:951 (7)
    //         004bd4d2     MOV        dword ptr [ECX + this->loop],0x1
    //                              Sounddrv.cpp:952 (3)
    //         004bd4d9     RET        0x4
}

// Offset: 0x004BD4E0
void set_volume(TDigital* this_, long param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TDigital::set_volume(long)                                                    *
    //                              *********************************************************************************************************
    //                              void __thiscall set_volume(TDigital * this, long param_1)
    //              void              <VOID>         <RETURN>
    //              TDigital *        ECX:4 (auto)   this
    //              long              Stack[0x4]:4   param_1                   XREF[1]:     004bd4e3(R)  
    //                               ?set_volume@TDigital@@QAEXJ@Z
    //                               TDigital::set_volume
    //                              Sounddrv.cpp:957 (14)
    //         004bd4e0     MOV        EAX,dword ptr [ECX + this->owner]
    //         004bd4e3     MOV        EDX,dword ptr [ESP + param_1]
    //         004bd4e7     TEST       EAX,EAX
    //         004bd4e9     MOV        dword ptr [ECX + this->volume],EDX
    //         004bd4ec     JNZ        LAB_004bd4f0
    //                              Sounddrv.cpp:963 (2)
    //         004bd4ee     MOV        EAX,this
    //                               LAB_004bd4f0                                                 XREF[1]:     004bd4ec(j)  
    //                              Sounddrv.cpp:967 (7)
    //         004bd4f0     MOV        this,byte ptr [EAX + 0x8]
    //         004bd4f3     TEST       this,this
    //         004bd4f5     JZ         LAB_004bd501
    //                              Sounddrv.cpp:968 (10)
    //         004bd4f7     MOV        EAX,dword ptr [EAX + 0x34]
    //         004bd4fa     PUSH       EDX
    //         004bd4fb     PUSH       EAX
    //         004bd4fc     MOV        this,dword ptr [EAX]
    //         004bd4fe     CALL       dword ptr [ECX + this+0x3c]
    //                               LAB_004bd501                                                 XREF[1]:     004bd4f5(j)  
    //                              Sounddrv.cpp:969 (3)
    //         004bd501     RET        0x4
}

// Offset: 0x004BD510
void set_pitch(TDigital* this_, ulong param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TDigital::set_pitch(unsigned long)                                            *
    //                              *********************************************************************************************************
    //                              void __thiscall set_pitch(TDigital * this, ulong param_1)
    //              void              <VOID>         <RETURN>
    //              TDigital *        ECX:4 (auto)   this
    //              ulong             Stack[0x4]:4   param_1                   XREF[1]:     004bd513(R)  
    //                               ?set_pitch@TDigital@@QAEXK@Z
    //                               TDigital::set_pitch
    //                              Sounddrv.cpp:974 (14)
    //         004bd510     MOV        EAX,dword ptr [ECX + this->owner]
    //         004bd513     MOV        EDX,dword ptr [ESP + param_1]
    //         004bd517     TEST       EAX,EAX
    //         004bd519     MOV        dword ptr [ECX + this->pitch],EDX
    //         004bd51c     JNZ        LAB_004bd520
    //                              Sounddrv.cpp:980 (2)
    //         004bd51e     MOV        EAX,this
    //                               LAB_004bd520                                                 XREF[1]:     004bd51c(j)  
    //                              Sounddrv.cpp:984 (7)
    //         004bd520     MOV        this,byte ptr [EAX + 0x8]
    //         004bd523     TEST       this,this
    //         004bd525     JZ         LAB_004bd531
    //                              Sounddrv.cpp:985 (10)
    //         004bd527     MOV        EAX,dword ptr [EAX + 0x34]
    //         004bd52a     PUSH       EDX
    //         004bd52b     PUSH       EAX
    //         004bd52c     MOV        this,dword ptr [EAX]
    //         004bd52e     CALL       dword ptr [this->sound_system + 0x44]
    //                               LAB_004bd531                                                 XREF[1]:     004bd525(j)  
    //                              Sounddrv.cpp:986 (3)
    //         004bd531     RET        0x4
}

// Offset: 0x004BD540
void set_pan(TDigital* this_, long param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TDigital::set_pan(long)                                                       *
    //                              *********************************************************************************************************
    //                              void __thiscall set_pan(TDigital * this, long param_1)
    //              void              <VOID>         <RETURN>
    //              TDigital *        ECX:4 (auto)   this
    //              long              Stack[0x4]:4   param_1                   XREF[1]:     004bd543(R)  
    //                               ?set_pan@TDigital@@QAEXJ@Z
    //                               TDigital::set_pan
    //                              Sounddrv.cpp:991 (14)
    //         004bd540     MOV        EAX,dword ptr [ECX + this->owner]
    //         004bd543     MOV        EDX,dword ptr [ESP + param_1]
    //         004bd547     TEST       EAX,EAX
    //         004bd549     MOV        dword ptr [ECX + this->pan],EDX
    //         004bd54c     JNZ        LAB_004bd550
    //                              Sounddrv.cpp:997 (2)
    //         004bd54e     MOV        EAX,this
    //                               LAB_004bd550                                                 XREF[1]:     004bd54c(j)  
    //                              Sounddrv.cpp:1001 (7)
    //         004bd550     MOV        this,byte ptr [EAX + 0x8]
    //         004bd553     TEST       this,this
    //         004bd555     JZ         LAB_004bd561
    //                              Sounddrv.cpp:1002 (10)
    //         004bd557     MOV        EAX,dword ptr [EAX + 0x34]
    //         004bd55a     PUSH       EDX
    //         004bd55b     PUSH       EAX
    //         004bd55c     MOV        this,dword ptr [EAX]
    //         004bd55e     CALL       dword ptr [this->sound_system + 0x40]
    //                               LAB_004bd561                                                 XREF[1]:     004bd555(j)  
    //                              Sounddrv.cpp:1003 (3)
    //         004bd561     RET        0x4
}

// Offset: 0x004BD570
int is_playing(TDigital* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall TDigital::is_playing(void)                                                     *
    //                              *********************************************************************************************************
    //                              int __thiscall is_playing(TDigital * this)
    //              int               EAX:4          <RETURN>
    //              TDigital *        ECX:4 (auto)   this
    //              undefined         Stack[-0x4]:1  local_4                   XREF[1]:     004bd58f(*)  
    //              ulong             Stack[-0x8]:4  status
    //                               ?is_playing@TDigital@@QAEHXZ                                 XREF[10]:    play_sound:00422e89(c), 
    //                               TDigital::is_playing                                                      mouse_left_down_action:004731ae(c)
    //                                                                                                         mouse_right_down_action:004733be(c
    //                                                                                                         handle_key_down:00473649(c), 
    //                                                                                                         key_down_action:004737cd(c), 
    //                                                                                                         ~TRIBE_Screen_Game:004954e5(c), 
    //                                                                                                         stop:004bc512(c), 
    //                                                                                                         is_playing:004bc562(c), 
    //                                                                                                         PlayTauntNo:00509587(c), 
    //                                                                                                         PlayTauntNo:005095a7(c)  
    //                              Sounddrv.cpp:1007 (1)
    //         004bd570     PUSH       this
    //                              Sounddrv.cpp:1011 (7)
    //         004bd571     MOV        EAX,dword ptr [ECX + this->owner]
    //         004bd574     TEST       EAX,EAX
    //         004bd576     JNZ        LAB_004bd57a
    //                              Sounddrv.cpp:1012 (2)
    //         004bd578     MOV        EAX,this
    //                               LAB_004bd57a                                                 XREF[1]:     004bd576(j)  
    //                              Sounddrv.cpp:1016 (3)
    //         004bd57a     CMP        dword ptr [this->sound_system],0x0
    //                              Sounddrv.cpp:1017 (2)
    //         004bd57d     JZ         LAB_004bd5b1
    //                              Sounddrv.cpp:1019 (14)
    //         004bd57f     MOV        this,byte ptr [EAX + 0x8]
    //         004bd582     TEST       this,this
    //         004bd584     JZ         LAB_004bd5b1
    //         004bd586     MOV        EAX,dword ptr [EAX + 0x34]
    //         004bd589     TEST       EAX,EAX
    //         004bd58b     JZ         LAB_004bd5b1
    //                              Sounddrv.cpp:1022 (13)
    //         004bd58d     MOV        this,dword ptr [EAX]
    //         004bd58f     LEA        EDX=>local_4,[ESP]
    //         004bd593     PUSH       EDX
    //         004bd594     PUSH       EAX
    //         004bd595     CALL       dword ptr [ECX + this->pan]
    //         004bd598     TEST       EAX,EAX
    //                              Sounddrv.cpp:1023 (2)
    //         004bd59a     JNZ        LAB_004bd5b1
    //                              Sounddrv.cpp:1025 (12)
    //         004bd59c     MOV        EAX,dword ptr [ESP]
    //         004bd5a0     CMP        EAX,0x1
    //         004bd5a3     JZ         LAB_004bd5aa
    //         004bd5a5     CMP        EAX,0x4
    //                              Sounddrv.cpp:1028 (2)
    //         004bd5a8     JNZ        LAB_004bd5b1
    //                               LAB_004bd5aa                                                 XREF[1]:     004bd5a3(j)  
    //                              Sounddrv.cpp:1026 (5)
    //         004bd5aa     MOV        EAX,0x1
    //                              Sounddrv.cpp:1029 (2)
    //         004bd5af     POP        this
    //         004bd5b0     RET
    //                               LAB_004bd5b1                                                 XREF[5]:     004bd57d(j), 004bd584(j), 
    //                                                                                                         004bd58b(j), 004bd59a(j), 
    //                                                                                                         004bd5a8(j)  
    //                              Sounddrv.cpp:1020 (2)
    //         004bd5b1     XOR        EAX,EAX
    //                              Sounddrv.cpp:1029 (2)
    //         004bd5b3     POP        this
    //         004bd5b4     RET
}

// Offset: 0x004BD5C0
int add_to_play_list(TDigital* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall TDigital::add_to_play_list(void)                                               *
    //                              *********************************************************************************************************
    //                              int __thiscall add_to_play_list(TDigital * this)
    //              int               EAX:4          <RETURN>
    //              TDigital *        ECX:4 (auto)   this
    //                               ?add_to_play_list@TDigital@@QAEHXZ                           XREF[1]:     play:004bc3ed(c)  
    //                               TDigital::add_to_play_list
    //                              Sounddrv.cpp:1033 (13)
    //         004bd5c0     MOV        EAX,dword ptr [this->sound_system]
    //         004bd5c2     TEST       EAX,EAX
    //         004bd5c4     JZ         LAB_004bd5d6
    //         004bd5c6     MOV        DL,byte ptr [EAX + 0x1]
    //         004bd5c9     TEST       DL,DL
    //         004bd5cb     JNZ        LAB_004bd5d6
    //                              Sounddrv.cpp:1036 (8)
    //         004bd5cd     PUSH       this
    //         004bd5ce     MOV        this,EAX
    //         004bd5d0     CALL       TSound_Driver::add_to_play_list                  int add_to_play_list(TSound_Driver * this, TD
    //                              Sounddrv.cpp:1037 (1)
    //         004bd5d5     RET
    //                               LAB_004bd5d6                                                 XREF[2]:     004bd5c4(j), 004bd5cb(j)  
    //                              Sounddrv.cpp:1035 (2)
    //         004bd5d6     XOR        EAX,EAX
    //                              Sounddrv.cpp:1037 (1)
    //         004bd5d8     RET
}

