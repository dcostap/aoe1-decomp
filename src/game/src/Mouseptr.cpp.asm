// Auto-generated scaffold unit: Mouseptr.cpp.asm
// SourceMap: C:/msdev/work/age1_x1/Mouseptr.cpp
#include "../include/common.h"

// Offset: 0x0045AE50
undefined TMousePointer(TMousePointer* this_, int param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall TMousePointer::TMousePointer(int)                                                  *
    //                              *********************************************************************************************************
    //                              undefined __thiscall TMousePointer(TMousePointer * this, int param_1)
    //              undefined         <UNASSIGNED>   <RETURN>
    //              TMousePointer *   ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0045af7e(R)  
    //                               ??0TMousePointer@@QAE@H@Z                                    XREF[1]:     setup_mouse:0041ec5b(c)  
    //                               TMousePointer::TMousePointer
    //                              Mouseptr.cpp:27 (4)
    //         0045ae50     PUSH       EBX
    //         0045ae51     PUSH       ESI
    //         0045ae52     MOV        ESI,this
    //                              Mouseptr.cpp:28 (3)
    //         0045ae54     XOR        EBX,EBX
    //         0045ae56     PUSH       EDI
    //                              Mouseptr.cpp:62 (6)
    //         0045ae57     LEA        EAX,[ESI + 0xbc]
    //                              Mouseptr.cpp:63 (6)
    //         0045ae5d     MOV        dword ptr [ESI + 0xc0],EBX
    //                              Mouseptr.cpp:67 (67)
    //         0045ae63     MOV        EDX,EAX
    //         0045ae65     MOV        dword ptr [ESI + 0xc4],EBX
    //         0045ae6b     MOV        dword ptr [EAX],EBX
    //         0045ae6d     MOV        dword ptr [ESI + 0xc8],EBX
    //         0045ae73     MOV        EDI,dword ptr [EDX]
    //         0045ae75     LEA        this,[ESI + 0xcc]
    //         0045ae7b     MOV        dword ptr [ESI],EBX
    //         0045ae7d     MOV        dword ptr [ESI + 0x4],EBX
    //         0045ae80     MOV        dword ptr [this->custom_draw],EDI
    //         0045ae82     MOV        EDI,dword ptr [EDX + 0x4]
    //         0045ae85     MOV        dword ptr [ESI + 0x8],EBX
    //         0045ae88     MOV        dword ptr [ESI + 0xc],EBX
    //         0045ae8b     MOV        dword ptr [ECX + this->render_area],EDI
    //         0045ae8e     MOV        EDI,dword ptr [EDX + 0x8]
    //         0045ae91     MOV        dword ptr [ESI + 0x58],EBX
    //         0045ae94     MOV        dword ptr [ESI + 0x60],EBX
    //         0045ae97     MOV        EDX,dword ptr [EDX + 0xc]
    //         0045ae9a     MOV        dword ptr [ECX + this->save_area],EDI
    //         0045ae9d     MOV        dword ptr [ESI + 0x64],EBX
    //         0045aea0     MOV        dword ptr [ESI + 0x68],EBX
    //         0045aea3     MOV        dword ptr [ECX + this->primary_area],EDX
    //                              Mouseptr.cpp:68 (63)
    //         0045aea6     MOV        EDX,EAX
    //         0045aea8     LEA        this,[ESI + 0xdc]
    //         0045aeae     MOV        dword ptr [ESI + 0x6c],EBX
    //         0045aeb1     MOV        EDI,dword ptr [EDX]
    //         0045aeb3     MOV        dword ptr [ESI + 0x70],EBX
    //         0045aeb6     MOV        dword ptr [this->custom_draw],EDI
    //         0045aeb8     MOV        dword ptr [ESI + 0x74],EBX
    //         0045aebb     MOV        EDI,dword ptr [EDX + 0x4]
    //         0045aebe     MOV        dword ptr [ESI + 0x78],EBX
    //         0045aec1     MOV        dword ptr [ECX + this->render_area],EDI
    //         0045aec4     MOV        dword ptr [ESI + 0x7c],EBX
    //         0045aec7     MOV        EDI,dword ptr [EDX + 0x8]
    //         0045aeca     MOV        dword ptr [ESI + 0x88],EBX
    //         0045aed0     MOV        dword ptr [ECX + this->save_area],EDI
    //         0045aed3     MOV        dword ptr [ESI + 0x8c],EBX
    //         0045aed9     MOV        EDX,dword ptr [EDX + 0xc]
    //         0045aedc     MOV        dword ptr [ESI + 0x90],EBX
    //         0045aee2     MOV        dword ptr [ECX + this->primary_area],EDX
    //                              Mouseptr.cpp:69 (78)
    //         0045aee5     MOV        EDX,EAX
    //         0045aee7     LEA        this,[ESI + 0xec]
    //         0045aeed     MOV        dword ptr [ESI + 0x94],EBX
    //         0045aef3     MOV        EDI,dword ptr [EDX]
    //         0045aef5     MOV        dword ptr [ESI + 0x98],EBX
    //         0045aefb     MOV        dword ptr [this->custom_draw],EDI
    //         0045aefd     MOV        dword ptr [ESI + 0x9c],EBX
    //         0045af03     MOV        EDI,dword ptr [EDX + 0x4]
    //         0045af06     MOV        dword ptr [ESI + 0xa0],EBX
    //         0045af0c     MOV        dword ptr [ECX + this->render_area],EDI
    //         0045af0f     MOV        dword ptr [ESI + 0xa4],EBX
    //         0045af15     MOV        EDI,dword ptr [EDX + 0x8]
    //         0045af18     MOV        dword ptr [ESI + 0xa8],EBX
    //         0045af1e     MOV        dword ptr [ECX + this->save_area],EDI
    //         0045af21     MOV        dword ptr [ESI + 0xac],EBX
    //         0045af27     MOV        EDX,dword ptr [EDX + 0xc]
    //         0045af2a     MOV        dword ptr [ESI + 0xb0],EBX
    //         0045af30     MOV        dword ptr [ECX + this->primary_area],EDX
    //                              Mouseptr.cpp:70 (19)
    //         0045af33     LEA        this,[ESI + 0xfc]
    //         0045af39     MOV        EDX,EBX
    //         0045af3b     MOV        dword ptr [ESI + 0xb4],EBX
    //         0045af41     MOV        dword ptr [this->custom_draw],EDX
    //         0045af43     MOV        EDX,dword ptr [EAX + 0x4]
    //                              Mouseptr.cpp:75 (6)
    //         0045af46     MOV        dword ptr [ESI + 0x128],EBX
    //                              Mouseptr.cpp:76 (15)
    //         0045af4c     MOV        dword ptr [ESI + 0x12c],EBX
    //         0045af52     MOV        dword ptr [ECX + this->render_area],EDX
    //         0045af55     MOV        EDX,dword ptr [EAX + 0x8]
    //         0045af58     MOV        EAX,dword ptr [EAX + 0xc]
    //                              Mouseptr.cpp:77 (9)
    //         0045af5b     MOV        dword ptr [ESI + 0x130],EBX
    //         0045af61     MOV        dword ptr [ECX + this->save_area],EDX
    //                              Mouseptr.cpp:78 (26)
    //         0045af64     MOV        dword ptr [ESI + 0x134],EBX
    //         0045af6a     MOV        dword ptr [ECX + this->primary_area],EAX
    //         0045af6d     MOV        EAX,0xffff8001
    //         0045af72     MOV        dword ptr [ESI + 0x80],EAX
    //         0045af78     MOV        dword ptr [ESI + 0x84],EAX
    //                              Mouseptr.cpp:93 (10)
    //         0045af7e     MOV        this,dword ptr [ESP + param_1]
    //         0045af82     LEA        EDI,[ESI + 0x18]
    //         0045af85     MOV        dword ptr [ESI + 0x5c],this
    //                              Mouseptr.cpp:97 (59)
    //         0045af88     MOV        this,0x10
    //         0045af8d     XOR        EAX,EAX
    //         0045af8f     MOV        dword ptr [ESI + 0x11c],EBX
    //         0045af95     MOV        dword ptr [ESI + 0x120],EBX
    //         0045af9b     MOV        dword ptr [ESI + 0x138],EBX
    //         0045afa1     MOV        dword ptr [ESI + 0x13c],EBX
    //         0045afa7     MOV        dword ptr [ESI + 0x140],EBX
    //         0045afad     MOV        dword ptr [ESI + 0x10],EBX
    //         0045afb0     MOV        dword ptr [ESI + 0x14],EBX
    //         0045afb3     MOV        dword ptr [ESI + 0x250],0xffffffff
    //         0045afbd     MOV        byte ptr [ESI + 0x14c],BL
    //                              Mouseptr.cpp:100 (26)
    //         0045afc3     PUSH       0x64
    //         0045afc5     PUSH       s_C:\msdev\work\age1_x1\Mouseptr.c               = "C:\\msdev\\work\\age1_x1\\Mouseptr.cpp"
    //         0045afca     STOSD.REP  ES:EDI
    //         0045afcc     CALL       debug_timeGetTime                                ulong debug_timeGetTime(char * param_1, int p
    //         0045afd1     ADD        ESP,0x8
    //         0045afd4     SUB        EAX,0x24
    //         0045afd7     MOV        dword ptr [ESI + 0x144],EAX
    //                              Mouseptr.cpp:102 (6)
    //         0045afdd     MOV        dword ptr [ESI + 0xb8],EBX
    //                              Mouseptr.cpp:104 (6)
    //         0045afe3     MOV        dword ptr [ESI + 0x148],EBX
    //                              Mouseptr.cpp:106 (8)
    //         0045afe9     MOV        EAX,ESI
    //         0045afeb     POP        EDI
    //         0045afec     POP        ESI
    //         0045afed     POP        EBX
    //         0045afee     RET        0x4
}

// Offset: 0x0045B000
void TMousePointer(TMousePointer* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall TMousePointer::~TMousePointer(void)                                                *
    //                              *********************************************************************************************************
    //                              void __thiscall ~TMousePointer(TMousePointer * this)
    //              void              <VOID>         <RETURN>
    //              TMousePointer *   ECX:4 (auto)   this
    //                               ??1TMousePointer@@QAE@XZ                                     XREF[1]:     ~RGE_Base_Game:0041c4ad(c)  
    //                               TMousePointer::~TMousePointer
    //                              Mouseptr.cpp:112 (4)
    //         0045b000     PUSH       ESI
    //         0045b001     PUSH       EDI
    //         0045b002     MOV        EDI,this
    //                              Mouseptr.cpp:113 (7)
    //         0045b004     MOV        ESI,dword ptr [EDI + 0x58]
    //         0045b007     TEST       ESI,ESI
    //         0045b009     JZ         LAB_0045b022
    //                              Mouseptr.cpp:115 (16)
    //         0045b00b     MOV        this,ESI
    //         0045b00d     CALL       TShape::~TShape                                  void ~TShape(TShape * this)
    //         0045b012     PUSH       ESI
    //         0045b013     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         0045b018     ADD        ESP,0x4
    //                              Mouseptr.cpp:116 (7)
    //         0045b01b     MOV        dword ptr [EDI + 0x58],0x0
    //                               LAB_0045b022                                                 XREF[1]:     0045b009(j)  
    //                              Mouseptr.cpp:118 (7)
    //         0045b022     MOV        this,EDI
    //         0045b024     CALL       TMousePointer::delete_surfaces                   void delete_surfaces(TMousePointer * this)
    //                              Mouseptr.cpp:122 (13)
    //         0045b029     POP        EDI
    //         0045b02a     MOV        dword ptr [MouseSystem],0x0                      = 00000000
    //         0045b034     POP        ESI
    //         0045b035     RET
}

// Offset: 0x0045B040
int Shutdown_Mouse(TMousePointer* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall TMousePointer::Shutdown_Mouse(void)                                            *
    //                              *********************************************************************************************************
    //                              int __thiscall Shutdown_Mouse(TMousePointer * this)
    //              int               EAX:4          <RETURN>
    //              TMousePointer *   ECX:4 (auto)   this
    //                               ?Shutdown_Mouse@TMousePointer@@QAEHXZ                        XREF[3]:     wnd_proc:00420a88(c), 
    //                               TMousePointer::Shutdown_Mouse                                             set_screen_size:00422b63(c), 
    //                                                                                                         setup_video_system:0052a2da(c)  
    //                              Mouseptr.cpp:129 (4)
    //         0045b040     PUSH       ESI
    //         0045b041     MOV        ESI,this
    //         0045b043     PUSH       EDI
    //                              Mouseptr.cpp:133 (12)
    //         0045b044     XOR        EDI,EDI
    //         0045b046     CMP        dword ptr [ESI + 0x130],EDI
    //         0045b04c     JZ         LAB_0045b053
    //         0045b04e     XOR        EAX,EAX
    //                              Mouseptr.cpp:157 (3)
    //         0045b050     POP        EDI
    //         0045b051     POP        ESI
    //         0045b052     RET
    //                               LAB_0045b053                                                 XREF[1]:     0045b04c(j)  
    //                              Mouseptr.cpp:134 (9)
    //         0045b053     CMP        dword ptr [ESI],EDI
    //         0045b055     JNZ        LAB_0045b05f
    //         0045b057     MOV        EAX,0x1
    //                              Mouseptr.cpp:157 (3)
    //         0045b05c     POP        EDI
    //         0045b05d     POP        ESI
    //         0045b05e     RET
    //                               LAB_0045b05f                                                 XREF[1]:     0045b055(j)  
    //                              Mouseptr.cpp:135 (10)
    //         0045b05f     CMP        dword ptr [ESI + 0x134],EDI
    //         0045b065     JNZ        LAB_0045b06c
    //         0045b067     XOR        EAX,EAX
    //                              Mouseptr.cpp:157 (3)
    //         0045b069     POP        EDI
    //         0045b06a     POP        ESI
    //         0045b06b     RET
    //                               LAB_0045b06c                                                 XREF[1]:     0045b065(j)  
    //                              Mouseptr.cpp:140 (7)
    //         0045b06c     MOV        this,ESI
    //         0045b06e     CALL       TMousePointer::reset                             void reset(TMousePointer * this)
    //                              Mouseptr.cpp:152 (29)
    //         0045b073     MOV        EAX,0x1
    //         0045b078     MOV        dword ptr [ESI + 0x4],EDI
    //         0045b07b     MOV        dword ptr [ESI + 0x11c],EDI
    //         0045b081     MOV        dword ptr [ESI + 0x120],EDI
    //         0045b087     MOV        dword ptr [ESI + 0x124],EDI
    //         0045b08d     MOV        dword ptr [ESI + 0xc],EDI
    //                              Mouseptr.cpp:153 (12)
    //         0045b090     MOV        dword ptr [ESI + 0x128],EDI
    //         0045b096     MOV        dword ptr [ESI + 0x130],EAX
    //                              Mouseptr.cpp:157 (3)
    //         0045b09c     POP        EDI
    //         0045b09d     POP        ESI
    //         0045b09e     RET
}

// Offset: 0x0045B0A0
int Restore_Mouse(TMousePointer* this_, TDrawArea* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall TMousePointer::Restore_Mouse(class TDrawArea *)                                *
    //                              *********************************************************************************************************
    //                              int __thiscall Restore_Mouse(TMousePointer * this, TDrawArea * param
    //              int               EAX:4          <RETURN>
    //              TMousePointer *   ECX:4 (auto)   this
    //              TDrawArea *       Stack[0x4]:4   param_1                   XREF[1]:     0045b0c8(R)  
    //                               ?Restore_Mouse@TMousePointer@@QAEHPAVTDrawArea@@@Z           XREF[1]:     handle_paint:004217b5(c)  
    //                               TMousePointer::Restore_Mouse
    //                              Mouseptr.cpp:163 (3)
    //         0045b0a0     PUSH       ESI
    //         0045b0a1     MOV        ESI,this
    //                              Mouseptr.cpp:166 (12)
    //         0045b0a3     MOV        EAX,dword ptr [ESI + 0x130]
    //         0045b0a9     TEST       EAX,EAX
    //         0045b0ab     JNZ        LAB_0045b0b3
    //         0045b0ad     XOR        EAX,EAX
    //                              Mouseptr.cpp:185 (4)
    //         0045b0af     POP        ESI
    //         0045b0b0     RET        0x4
    //                               LAB_0045b0b3                                                 XREF[1]:     0045b0ab(j)  
    //                              Mouseptr.cpp:167 (5)
    //         0045b0b3     CMP        dword ptr [ESI],0x0
    //         0045b0b6     JZ         LAB_0045b10a
    //                              Mouseptr.cpp:168 (12)
    //         0045b0b8     MOV        EAX,dword ptr [ESI + 0x134]
    //         0045b0be     TEST       EAX,EAX
    //         0045b0c0     JNZ        LAB_0045b0c8
    //         0045b0c2     XOR        EAX,EAX
    //                              Mouseptr.cpp:185 (4)
    //         0045b0c4     POP        ESI
    //         0045b0c5     RET        0x4
    //                               LAB_0045b0c8                                                 XREF[1]:     0045b0c0(j)  
    //                              Mouseptr.cpp:170 (4)
    //         0045b0c8     MOV        EAX,dword ptr [ESP + param_1]
    //                              Mouseptr.cpp:178 (48)
    //         0045b0cc     PUSH       0x1
    //         0045b0ce     MOV        dword ptr [ESI + 0x4],EAX
    //         0045b0d1     PUSH       -0x1
    //         0045b0d3     MOV        this,dword ptr [EAX + 0x3c]
    //         0045b0d6     PUSH       0x0
    //         0045b0d8     MOV        dword ptr [ESI + 0x120],this
    //         0045b0de     MOV        EDX,dword ptr [EAX]
    //         0045b0e0     MOV        this,dword ptr [EDX + 0x1c]
    //         0045b0e3     MOV        dword ptr [ESI + 0x124],this
    //         0045b0e9     MOV        EDX,dword ptr [EAX]
    //         0045b0eb     MOV        this,ESI
    //         0045b0ed     MOV        EAX,dword ptr [EDX + 0x10]
    //         0045b0f0     MOV        dword ptr [ESI + 0xc],EAX
    //         0045b0f3     CALL       TMousePointer::LoadCursors                       int LoadCursors(TMousePointer * this, char * 
    //         0045b0f8     TEST       EAX,EAX
    //         0045b0fa     JNZ        LAB_0045b100
    //                              Mouseptr.cpp:185 (4)
    //         0045b0fc     POP        ESI
    //         0045b0fd     RET        0x4
    //                               LAB_0045b100                                                 XREF[1]:     0045b0fa(j)  
    //                              Mouseptr.cpp:182 (10)
    //         0045b100     MOV        dword ptr [ESI + 0x130],0x0
    //                               LAB_0045b10a                                                 XREF[1]:     0045b0b6(j)  
    //                              Mouseptr.cpp:184 (5)
    //         0045b10a     MOV        EAX,0x1
    //                              Mouseptr.cpp:185 (4)
    //         0045b10f     POP        ESI
    //         0045b110     RET        0x4
}

// Offset: 0x0045B120
int setup(TMousePointer* this_, int param_2, TDrawArea* param_3, char* param_4, int param_5, int param_6) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall TMousePointer::setup(int,class TDrawArea *,char *,int,int)                     *
    //                              *********************************************************************************************************
    //                              int __thiscall setup(TMousePointer * this, int param_1, TDrawArea * 
    //              int               EAX:4          <RETURN>
    //              TMousePointer *   ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0045b147(R)  
    //              TDrawArea *       Stack[0x8]:4   param_2                   XREF[1]:     0045b13b(R)  
    //              char *            Stack[0xc]:4   param_3
    //              int               Stack[0x10]:4  param_4
    //              int               Stack[0x14]:4  param_5
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     0045b267(R)  
    //              char[260]         Stack[-0x114   file_name
    //                               ?setup@TMousePointer@@QAEHHPAVTDrawArea@@PADHH@Z             XREF[1]:     setup_mouse:0041eca2(c)  
    //                               TMousePointer::setup
    //                              Mouseptr.cpp:192 (27)
    //         0045b120     MOV        EAX,FS:[0x0]
    //         0045b126     PUSH       -0x1
    //         0045b128     PUSH       FUN_0055dc0e
    //         0045b12d     PUSH       EAX
    //         0045b12e     MOV        dword ptr FS:[0x0],ESP
    //         0045b135     SUB        ESP,0x108
    //                              Mouseptr.cpp:205 (25)
    //         0045b13b     MOV        EAX,dword ptr [ESP + param_2]
    //         0045b142     PUSH       EBP
    //         0045b143     PUSH       ESI
    //         0045b144     MOV        ESI,this
    //         0045b146     PUSH       EDI
    //         0045b147     MOV        this,dword ptr [ESP + param_1]
    //         0045b14e     MOV        dword ptr [MouseSystem],ESI                      = 00000000
    //                              Mouseptr.cpp:209 (19)
    //         0045b154     TEST       this,this
    //         0045b156     MOV        dword ptr [ESI],this
    //         0045b158     MOV        dword ptr [ESI + 0x4],EAX
    //         0045b15b     JNZ        LAB_0045b167
    //         0045b15d     MOV        EAX,0x1
    //         0045b162     JMP        LAB_0045b267
    //                               LAB_0045b167                                                 XREF[1]:     0045b15b(j)  
    //                              Mouseptr.cpp:210 (15)
    //         0045b167     MOV        this,dword ptr [EAX]
    //         0045b169     CMP        byte ptr [this->custom_draw + 0x478],0x1
    //         0045b170     JZ         LAB_0045b265
    //                              Mouseptr.cpp:212 (3)
    //         0045b176     MOV        EDX,dword ptr [EAX + 0x3c]
    //                              Mouseptr.cpp:219 (33)
    //         0045b179     PUSH       0x0
    //         0045b17b     MOV        dword ptr [ESI + 0x120],EDX
    //         0045b181     MOV        this,dword ptr [EAX]
    //         0045b183     MOV        EDX,dword ptr [ECX + this+0x1c]
    //         0045b186     MOV        dword ptr [ESI + 0x124],EDX
    //         0045b18c     MOV        EAX,dword ptr [EAX]
    //         0045b18e     MOV        this,dword ptr [EAX + 0x10]
    //         0045b191     MOV        dword ptr [ESI + 0xc],this
    //         0045b194     CALL       dword ptr [->USER32.DLL::SetCursor]              = 0048aeda
    //                              Mouseptr.cpp:223 (26)
    //         0045b19a     MOV        EDI,dword ptr [ESP + 0x12c]
    //         0045b1a1     LEA        EDX,[ESP + 0x10]
    //         0045b1a5     PUSH       EDI
    //         0045b1a6     PUSH       s_%s.slp                                         = "%s.slp"
    //         0045b1ab     PUSH       EDX=>DAT_fffffff4
    //         0045b1ac     CALL       sprintf                                          undefined sprintf()
    //         0045b1b1     ADD        ESP,0xc
    //                              Mouseptr.cpp:224 (53)
    //         0045b1b4     PUSH       0x20
    //         0045b1b6     CALL       operator_new                                     void * operator_new(uint param_1)
    //         0045b1bb     ADD        ESP,0x4
    //         0045b1be     MOV        dword ptr [ESP + 0xc],EAX
    //         0045b1c2     MOV        EBP,dword ptr [ESP + 0x130]
    //         0045b1c9     MOV        dword ptr [ESP + 0x11c],0x0
    //         0045b1d4     TEST       EAX,EAX
    //         0045b1d6     JZ         LAB_0045b1e7
    //         0045b1d8     LEA        this,[ESP + 0x10]
    //         0045b1dc     PUSH       EBP
    //         0045b1dd     PUSH       this=>DAT_fffffff8
    //         0045b1de     MOV        this,EAX
    //         0045b1e0     CALL       TShape::TShape                                   undefined TShape(TShape * this, char * param_
    //         0045b1e5     JMP        LAB_0045b1e9
    //                               LAB_0045b1e7                                                 XREF[1]:     0045b1d6(j)  
    //         0045b1e7     XOR        EAX,EAX
    //                               LAB_0045b1e9                                                 XREF[1]:     0045b1e5(j)  
    //                              Mouseptr.cpp:226 (18)
    //         0045b1e9     TEST       EAX,EAX
    //         0045b1eb     MOV        dword ptr [ESP + 0x11c],0xffffffff
    //         0045b1f6     MOV        dword ptr [ESI + 0x58],EAX
    //         0045b1f9     JZ         LAB_0045b265
    //                              Mouseptr.cpp:227 (11)
    //         0045b1fb     MOV        this,EAX
    //         0045b1fd     CALL       TShape::is_loaded                                int is_loaded(TShape * this)
    //         0045b202     TEST       EAX,EAX
    //         0045b204     JZ         LAB_0045b265
    //                              Mouseptr.cpp:228 (10)
    //         0045b206     MOV        this,dword ptr [ESI + 0x58]
    //         0045b209     MOV        EAX,dword ptr [ECX + this->cursors[0]]
    //         0045b20c     TEST       EAX,EAX
    //         0045b20e     JZ         LAB_0045b265
    //                              Mouseptr.cpp:232 (7)
    //         0045b210     MOV        EAX,dword ptr [ESP + 0x134]
    //                              Mouseptr.cpp:233 (13)
    //         0045b217     CMP        EAX,0x1
    //         0045b21a     MOV        dword ptr [ESI + 0x14],EAX
    //         0045b21d     JL         LAB_0045b265
    //         0045b21f     CMP        EAX,0x10
    //         0045b222     JG         LAB_0045b265
    //                              Mouseptr.cpp:235 (5)
    //         0045b224     CALL       TShape::shape_count                              long shape_count(TShape * this)
    //                              Mouseptr.cpp:236 (10)
    //         0045b229     MOV        this,dword ptr [ESI + 0x14]
    //         0045b22c     MOV        dword ptr [ESI + 0x10],EAX
    //         0045b22f     CMP        EAX,this
    //         0045b231     JG         LAB_0045b265
    //                              Mouseptr.cpp:265 (15)
    //         0045b233     PUSH       0x0
    //         0045b235     PUSH       EBP=>DAT_fffffff8
    //         0045b236     PUSH       EDI=>DAT_fffffff4
    //         0045b237     MOV        this,ESI
    //         0045b239     CALL       TMousePointer::LoadCursors                       int LoadCursors(TMousePointer * this, char * 
    //         0045b23e     TEST       EAX,EAX
    //         0045b240     JZ         LAB_0045b265
    //                              Mouseptr.cpp:269 (9)
    //         0045b242     PUSH       0x0
    //         0045b244     MOV        this,ESI
    //         0045b246     CALL       TMousePointer::set_facet                         void set_facet(TMousePointer * this, int para
    //                              Mouseptr.cpp:270 (9)
    //         0045b24b     PUSH       0x0
    //         0045b24d     MOV        this,ESI
    //         0045b24f     CALL       TMousePointer::set_game_facet                    void set_game_facet(TMousePointer * this, int
    //                              Mouseptr.cpp:272 (10)
    //         0045b254     MOV        dword ptr [ESI + 0x134],0x1
    //                              Mouseptr.cpp:274 (7)
    //         0045b25e     MOV        EAX,0x1
    //         0045b263     JMP        LAB_0045b267
    //                               LAB_0045b265                                                 XREF[8]:     0045b170(j), 0045b1f9(j), 
    //                                                                                                         0045b204(j), 0045b20e(j), 
    //                                                                                                         0045b21d(j), 0045b222(j), 
    //                                                                                                         0045b231(j), 0045b240(j)  
    //                              Mouseptr.cpp:233 (2)
    //         0045b265     XOR        EAX,EAX
    //                               LAB_0045b267                                                 XREF[2]:     0045b162(j), 0045b263(j)  
    //                              Mouseptr.cpp:275 (26)
    //         0045b267     MOV        this,dword ptr [ESP + local_c]
    //         0045b26e     POP        EDI
    //         0045b26f     POP        ESI
    //         0045b270     MOV        dword ptr FS:[0x0],this
    //         0045b277     POP        EBP
    //         0045b278     ADD        ESP,0x114
    //         0045b27e     RET        0x14
}

// Offset: 0x0045B290
void set_game_mode(TMousePointer* this_, int param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TMousePointer::set_game_mode(int)                                             *
    //                              *********************************************************************************************************
    //                              void __thiscall set_game_mode(TMousePointer * this, int param_1)
    //              void              <VOID>         <RETURN>
    //              TMousePointer *   ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0045b290(R)  
    //                               ?set_game_mode@TMousePointer@@QAEXH@Z                        XREF[2]:     ~RGE_View:005338e0(c), 
    //                               TMousePointer::set_game_mode                                              set_rect:005340d8(c)  
    //                              Mouseptr.cpp:281 (10)
    //         0045b290     MOV        EAX,dword ptr [ESP + param_1]
    //         0045b294     MOV        dword ptr [ECX + this->GameMode],EAX
    //                              Mouseptr.cpp:283 (3)
    //         0045b29a     RET        0x4
}

// Offset: 0x0045B2A0
void set_game_enable(TMousePointer* this_, int param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TMousePointer::set_game_enable(int)                                           *
    //                              *********************************************************************************************************
    //                              void __thiscall set_game_enable(TMousePointer * this, int param_1)
    //              void              <VOID>         <RETURN>
    //              TMousePointer *   ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0045b2a0(R)  
    //                               ?set_game_enable@TMousePointer@@QAEXH@Z                      XREF[5]:     setup_popup_help:0046a3b4(c), 
    //                               TMousePointer::set_game_enable                                            clear_popup_help:0046a403(c), 
    //                                                                                                         command_do_popup_help:0046a471(c), 
    //                                                                                                         ~RGE_View:005338ed(c), 
    //                                                                                                         set_focus:00533adb(c)  
    //                              Mouseptr.cpp:289 (10)
    //         0045b2a0     MOV        EAX,dword ptr [ESP + param_1]
    //         0045b2a4     MOV        dword ptr [ECX + this->GameEnabled],EAX
    //                              Mouseptr.cpp:291 (3)
    //         0045b2aa     RET        0x4
}

// Offset: 0x0045B2B0
int get_game_enable(TMousePointer* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall TMousePointer::get_game_enable(void)                                           *
    //                              *********************************************************************************************************
    //                              int __thiscall get_game_enable(TMousePointer * this)
    //              int               EAX:4          <RETURN>
    //              TMousePointer *   ECX:4 (auto)   this
    //                               ?get_game_enable@TMousePointer@@QAEHXZ                       XREF[2]:     setup_popup_help:0046a39b(c), 
    //                               TMousePointer::get_game_enable                                            view_function_terrain:00537982(c)  
    //                              Mouseptr.cpp:298 (6)
    //         0045b2b0     MOV        EAX,dword ptr [ECX + this->GameEnabled]
    //                              Mouseptr.cpp:300 (1)
    //         0045b2b6     RET
}

// Offset: 0x0045B2C0
int in_game_mode(TMousePointer* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall TMousePointer::in_game_mode(void)                                              *
    //                              *********************************************************************************************************
    //                              int __thiscall in_game_mode(TMousePointer * this)
    //              int               EAX:4          <RETURN>
    //              TMousePointer *   ECX:4 (auto)   this
    //                               ?in_game_mode@TMousePointer@@QAEHXZ                          XREF[1]:     handle_mouse_move:00421141(c)  
    //                               TMousePointer::in_game_mode
    //                              Mouseptr.cpp:306 (25)
    //         0045b2c0     MOV        EAX,dword ptr [ECX + this->GameMode]
    //         0045b2c6     TEST       EAX,EAX
    //         0045b2c8     JZ         LAB_0045b2da
    //         0045b2ca     MOV        EAX,dword ptr [ECX + this->GameEnabled]
    //         0045b2d0     TEST       EAX,EAX
    //         0045b2d2     JZ         LAB_0045b2da
    //         0045b2d4     MOV        EAX,0x1
    //                              Mouseptr.cpp:310 (1)
    //         0045b2d9     RET
    //                               LAB_0045b2da                                                 XREF[2]:     0045b2c8(j), 0045b2d2(j)  
    //                              Mouseptr.cpp:309 (2)
    //         0045b2da     XOR        EAX,EAX
    //                              Mouseptr.cpp:310 (1)
    //         0045b2dc     RET
}

// Offset: 0x0045B2E0
void set_game_window(TMousePointer* this_, int param_2, int param_3, int param_4, int param_5) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TMousePointer::set_game_window(int,int,int,int)                               *
    //                              *********************************************************************************************************
    //                              void __thiscall set_game_window(TMousePointer * this, int param_1, i
    //              void              <VOID>         <RETURN>
    //              TMousePointer *   ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0045b2e0(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     0045b2e4(R)  
    //              int               Stack[0xc]:4   param_3                   XREF[1]:     0045b2ee(R)  
    //              int               Stack[0x10]:4  param_4                   XREF[1]:     0045b2f8(R)  
    //                               ?set_game_window@TMousePointer@@QAEXHHHH@Z                   XREF[1]:     set_rect:005340cb(c)  
    //                               TMousePointer::set_game_window
    //                              Mouseptr.cpp:316 (4)
    //         0045b2e0     MOV        EAX,dword ptr [ESP + param_1]
    //                              Mouseptr.cpp:318 (10)
    //         0045b2e4     MOV        EDX,dword ptr [ESP + param_2]
    //         0045b2e8     MOV        dword ptr [ECX + this->game_window.left],EAX
    //                              Mouseptr.cpp:319 (10)
    //         0045b2ee     MOV        EAX,dword ptr [ESP + param_3]
    //         0045b2f2     MOV        dword ptr [ECX + this+0x110],EDX
    //                              Mouseptr.cpp:320 (16)
    //         0045b2f8     MOV        EDX,dword ptr [ESP + param_4]
    //         0045b2fc     MOV        dword ptr [ECX + this+0x114],EAX
    //         0045b302     MOV        dword ptr [ECX + this+0x118],EDX
    //                              Mouseptr.cpp:322 (3)
    //         0045b308     RET        0x10
}

// Offset: 0x0045B310
int LoadCursors(TMousePointer* this_, char* param_2, int param_3, int param_4) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall TMousePointer::LoadCursors(char *,int,int)                                     *
    //                              *********************************************************************************************************
    //                              int __thiscall LoadCursors(TMousePointer * this, char * param_1, int
    //              int               EAX:4          <RETURN>
    //              TMousePointer *   ECX:4 (auto)   this
    //              char *            Stack[0x4]:4   param_1                   XREF[1]:     0045b353(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     0045b357(R)  
    //              int               Stack[0xc]:4   param_3                   XREF[2]:     0045b34d(R), 0045b380(W)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     0045b386(W), 0045b3a7(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     0045b546(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[3]:     0045b331(W), 0045b524(W), 0045b53e(R)  
    //              int               Stack[-0x14]:4 LoadOk
    //                               ?LoadCursors@TMousePointer@@QAEHPADHH@Z                      XREF[3]:     Restore_Mouse:0045b0f3(c), 
    //                               TMousePointer::LoadCursors                                                setup:0045b239(c), 
    //                                                                                                         set_focus:00469e5d(c)  
    //                              Mouseptr.cpp:372 (28)
    //         0045b310     PUSH       -0x1
    //         0045b312     PUSH       FUN_0055dc2b
    //         0045b317     MOV        EAX,FS:[0x0]
    //         0045b31d     PUSH       EAX
    //         0045b31e     MOV        dword ptr FS:[0x0],ESP
    //         0045b325     PUSH       this
    //         0045b326     PUSH       EBX
    //         0045b327     PUSH       EBP
    //         0045b328     PUSH       ESI
    //         0045b329     MOV        ESI,this
    //         0045b32b     PUSH       EDI
    //                              Mouseptr.cpp:379 (17)
    //         0045b32c     XOR        EBP,EBP
    //         0045b32e     MOV        EDI,dword ptr [ESI + 0x58]
    //         0045b331     MOV        dword ptr [ESP + local_10],0x1
    //         0045b339     CMP        EDI,EBP
    //         0045b33b     JZ         LAB_0045b34d
    //                              Mouseptr.cpp:381 (16)
    //         0045b33d     MOV        this,EDI
    //         0045b33f     CALL       TShape::~TShape                                  void ~TShape(TShape * this)
    //         0045b344     PUSH       EDI
    //         0045b345     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         0045b34a     ADD        ESP,0x4
    //                               LAB_0045b34d                                                 XREF[1]:     0045b33b(j)  
    //                              Mouseptr.cpp:386 (6)
    //         0045b34d     CMP        dword ptr [ESP + param_3],EBP
    //         0045b351     JNZ        LAB_0045b376
    //                              Mouseptr.cpp:389 (35)
    //         0045b353     MOV        this,dword ptr [ESP + param_1]
    //         0045b357     MOV        EAX,dword ptr [ESP + param_2]
    //         0045b35b     PUSH       this
    //         0045b35c     LEA        EDX,[ESI + 0x14c]
    //         0045b362     PUSH       s_%s.slp                                         = "%s.slp"
    //         0045b367     PUSH       EDX
    //         0045b368     MOV        dword ptr [ESI + 0x250],EAX
    //         0045b36e     CALL       sprintf                                          undefined sprintf()
    //         0045b373     ADD        ESP,0xc
    //                               LAB_0045b376                                                 XREF[1]:     0045b351(j)  
    //                              Mouseptr.cpp:394 (47)
    //         0045b376     PUSH       0x20
    //         0045b378     CALL       operator_new                                     void * operator_new(uint param_1)
    //         0045b37d     ADD        ESP,0x4
    //         0045b380     MOV        dword ptr [ESP + param_3],EAX
    //         0045b384     CMP        EAX,EBP
    //         0045b386     MOV        dword ptr [ESP + local_4],EBP
    //         0045b38a     JZ         LAB_0045b3a3
    //         0045b38c     MOV        this,dword ptr [ESI + 0x250]
    //         0045b392     LEA        EDX,[ESI + 0x14c]
    //         0045b398     PUSH       this
    //         0045b399     PUSH       EDX
    //         0045b39a     MOV        this,EAX
    //         0045b39c     CALL       TShape::TShape                                   undefined TShape(TShape * this, char * param_
    //         0045b3a1     JMP        LAB_0045b3a5
    //                               LAB_0045b3a3                                                 XREF[1]:     0045b38a(j)  
    //         0045b3a3     XOR        EAX,EAX
    //                               LAB_0045b3a5                                                 XREF[1]:     0045b3a1(j)  
    //                              Mouseptr.cpp:396 (19)
    //         0045b3a5     CMP        EAX,EBP
    //         0045b3a7     MOV        dword ptr [ESP + local_4],0xffffffff
    //         0045b3af     MOV        dword ptr [ESI + 0x58],EAX
    //         0045b3b2     JZ         LAB_0045b544
    //                              Mouseptr.cpp:397 (15)
    //         0045b3b8     MOV        this,EAX
    //         0045b3ba     CALL       TShape::is_loaded                                int is_loaded(TShape * this)
    //         0045b3bf     TEST       EAX,EAX
    //         0045b3c1     JZ         LAB_0045b544
    //                              Mouseptr.cpp:398 (12)
    //         0045b3c7     MOV        this,dword ptr [ESI + 0x58]
    //         0045b3ca     CMP        dword ptr [ECX + this->cursors[0]],EBP
    //         0045b3cd     JZ         LAB_0045b544
    //                              Mouseptr.cpp:407 (5)
    //         0045b3d3     CALL       TShape::shape_count                              long shape_count(TShape * this)
    //                              Mouseptr.cpp:412 (13)
    //         0045b3d8     CMP        EAX,EBP
    //         0045b3da     MOV        dword ptr [ESI + 0x10],EAX
    //         0045b3dd     MOV        dword ptr [ESI + 0x60],EBP
    //         0045b3e0     MOV        dword ptr [ESI + 0x64],EBP
    //         0045b3e3     JLE        LAB_0045b411
    //                              Mouseptr.cpp:414 (3)
    //         0045b3e5     MOV        EDI,dword ptr [ESI + 0x58]
    //                              Mouseptr.cpp:484 (19)
    //         0045b3e8     XOR        EDX,EDX
    //         0045b3ea     MOV        EBX,EAX
    //                               LAB_0045b3ec                                                 XREF[1]:     0045b40f(j)  
    //         0045b3ec     MOV        this,dword ptr [EDI + 0x1c]
    //         0045b3ef     MOV        EAX,EDX
    //         0045b3f1     ADD        EAX,this
    //         0045b3f3     MOV        this,dword ptr [EAX + 0x10]
    //         0045b3f6     CMP        this,dword ptr [ESI + 0x60]
    //         0045b3f9     JLE        LAB_0045b3fe
    //                              Mouseptr.cpp:415 (3)
    //         0045b3fb     MOV        dword ptr [ESI + 0x60],this
    //                               LAB_0045b3fe                                                 XREF[1]:     0045b3f9(j)  
    //                              Mouseptr.cpp:416 (13)
    //         0045b3fe     MOV        EAX,dword ptr [EAX + 0x14]
    //         0045b401     MOV        this,dword ptr [ESI + 0x64]
    //         0045b404     CMP        EAX,this
    //         0045b406     JLE        LAB_0045b40b
    //         0045b408     MOV        dword ptr [ESI + 0x64],EAX
    //                               LAB_0045b40b                                                 XREF[1]:     0045b406(j)  
    //                              Mouseptr.cpp:412 (6)
    //         0045b40b     ADD        EDX,0x20
    //         0045b40e     DEC        EBX
    //         0045b40f     JNZ        LAB_0045b3ec
    //                               LAB_0045b411                                                 XREF[1]:     0045b3e3(j)  
    //                              Mouseptr.cpp:419 (18)
    //         0045b411     CMP        dword ptr [ESI + 0x60],EBP
    //         0045b414     JZ         LAB_0045b544
    //         0045b41a     CMP        dword ptr [ESI + 0x64],EBP
    //         0045b41d     JZ         LAB_0045b544
    //                              Mouseptr.cpp:431 (21)
    //         0045b423     MOV        EAX,dword ptr [ESI + 0x8]
    //         0045b426     MOV        dword ptr [ESI + 0x60],0x40
    //         0045b42d     CMP        EAX,EBP
    //         0045b42f     MOV        dword ptr [ESI + 0x64],0x30
    //         0045b436     JNZ        LAB_0045b447
    //                              Mouseptr.cpp:433 (15)
    //         0045b438     MOV        this,ESI
    //         0045b43a     CALL       TMousePointer::create_surfaces                   int create_surfaces(TMousePointer * this)
    //         0045b43f     TEST       EAX,EAX
    //         0045b441     JZ         LAB_0045b544
    //                               LAB_0045b447                                                 XREF[1]:     0045b436(j)  
    //                              Mouseptr.cpp:436 (14)
    //         0045b447     MOV        EAX,dword ptr [ESI + 0x88]
    //         0045b44d     MOV        this,ESI
    //         0045b44f     PUSH       EAX
    //         0045b450     CALL       TMousePointer::set_facet                         void set_facet(TMousePointer * this, int para
    //                              Mouseptr.cpp:437 (14)
    //         0045b455     MOV        this,dword ptr [ESI + 0x8c]
    //         0045b45b     PUSH       this
    //         0045b45c     MOV        this,ESI
    //         0045b45e     CALL       TMousePointer::set_game_facet                    void set_game_facet(TMousePointer * this, int
    //                              Mouseptr.cpp:441 (9)
    //         0045b463     CMP        dword ptr [ESI + 0x5c],EBP
    //         0045b466     JNZ        LAB_0045b53e
    //                              Mouseptr.cpp:443 (14)
    //         0045b46c     MOV        EDX,dword ptr [ESI + 0x10]
    //         0045b46f     MOV        EBP,dword ptr [ESI + 0x14]
    //         0045b472     CMP        EDX,EBP
    //         0045b474     JG         LAB_0045b544
    //                              Mouseptr.cpp:445 (6)
    //         0045b47a     XOR        this,this
    //         0045b47c     TEST       EDX,EDX
    //         0045b47e     JLE        LAB_0045b4a8
    //                              Mouseptr.cpp:484 (40)
    //         0045b480     MOV        EAX,dword ptr [ESI + 0x58]
    //         0045b483     MOV        EDI,dword ptr [ESI + 0x60]
    //         0045b486     MOV        EAX,dword ptr [EAX + 0x1c]
    //         0045b489     ADD        EAX,0x14
    //                               LAB_0045b48c                                                 XREF[1]:     0045b4a6(j)  
    //         0045b48c     CMP        dword ptr [EAX + -0x4],EDI
    //         0045b48f     JG         LAB_0045b544
    //         0045b495     MOV        EBX,dword ptr [EAX]
    //         0045b497     CMP        EBX,dword ptr [ESI + 0x64]
    //         0045b49a     JG         LAB_0045b544
    //         0045b4a0     INC        this
    //         0045b4a1     ADD        EAX,0x20
    //         0045b4a4     CMP        this,EDX
    //         0045b4a6     JL         LAB_0045b48c
    //                               LAB_0045b4a8                                                 XREF[1]:     0045b47e(j)  
    //                              Mouseptr.cpp:454 (15)
    //         0045b4a8     XOR        EBX,EBX
    //         0045b4aa     TEST       EBP,EBP
    //         0045b4ac     JLE        LAB_0045b53e
    //         0045b4b2     XOR        EBP,EBP
    //         0045b4b4     LEA        EDI,[ESI + 0x18]
    //                               LAB_0045b4b7                                                 XREF[1]:     0045b538(j)  
    //                              Mouseptr.cpp:458 (11)
    //         0045b4b7     MOV        this,dword ptr [EDI]
    //         0045b4b9     PUSH       0x0
    //         0045b4bb     PUSH       0x0
    //         0045b4bd     CALL       TDrawArea::Clear                                 void Clear(TDrawArea * this, tagRECT * param_
    //                              Mouseptr.cpp:459 (11)
    //         0045b4c2     MOV        this,dword ptr [EDI]
    //         0045b4c4     PUSH       0x0
    //         0045b4c6     PUSH       0x1
    //         0045b4c8     CALL       TDrawArea::SetTrans                              void SetTrans(TDrawArea * this, int param_1, 
    //                              Mouseptr.cpp:463 (5)
    //         0045b4cd     CMP        EBX,dword ptr [ESI + 0x10]
    //         0045b4d0     JGE        LAB_0045b52c
    //                              Mouseptr.cpp:465 (18)
    //         0045b4d2     MOV        this,dword ptr [EDI]
    //         0045b4d4     PUSH       0x1
    //         0045b4d6     PUSH       s_mouseptr::LoadCursors                          = "mouseptr::LoadCursors"
    //         0045b4db     CALL       TDrawArea::Lock                                  uchar * Lock(TDrawArea * this, char * param_1
    //         0045b4e0     TEST       EAX,EAX
    //         0045b4e2     JZ         LAB_0045b524
    //                              Mouseptr.cpp:467 (21)
    //         0045b4e4     MOV        this,dword ptr [ESI + 0x64]
    //         0045b4e7     MOV        EDX,dword ptr [ESI + 0x60]
    //         0045b4ea     PUSH       0x0
    //         0045b4ec     PUSH       this
    //         0045b4ed     MOV        this,dword ptr [EDI]
    //         0045b4ef     PUSH       EDX
    //         0045b4f0     PUSH       0x0
    //         0045b4f2     PUSH       0x0
    //         0045b4f4     CALL       TDrawArea::FillRect                              void FillRect(TDrawArea * this, long param_1,
    //                              Mouseptr.cpp:469 (3)
    //         0045b4f9     MOV        this,dword ptr [ESI + 0x58]
    //                              Mouseptr.cpp:471 (26)
    //         0045b4fc     PUSH       0x0
    //         0045b4fe     PUSH       0x0
    //         0045b500     PUSH       EBX
    //         0045b501     MOV        EAX,dword ptr [ECX + this+0x1c]
    //         0045b504     ADD        EAX,EBP
    //         0045b506     MOV        EDX,dword ptr [EAX + 0x1c]
    //         0045b509     MOV        EAX,dword ptr [EAX + 0x18]
    //         0045b50c     PUSH       EDX
    //         0045b50d     MOV        EDX,dword ptr [EDI]
    //         0045b50f     PUSH       EAX
    //         0045b510     PUSH       EDX
    //         0045b511     CALL       TShape::shape_draw                               uchar shape_draw(TShape * this, TDrawArea * p
    //                              Mouseptr.cpp:473 (12)
    //         0045b516     MOV        this,dword ptr [EDI]
    //         0045b518     PUSH       s_mouseptr::LoadCursors                          = "mouseptr::LoadCursors"
    //         0045b51d     CALL       TDrawArea::Unlock                                void Unlock(TDrawArea * this, char * param_1)
    //                              Mouseptr.cpp:475 (2)
    //         0045b522     JMP        LAB_0045b52c
    //                               LAB_0045b524                                                 XREF[1]:     0045b4e2(j)  
    //                              Mouseptr.cpp:477 (8)
    //         0045b524     MOV        dword ptr [ESP + local_10],0x0
    //                               LAB_0045b52c                                                 XREF[2]:     0045b4d0(j), 0045b522(j)  
    //                              Mouseptr.cpp:454 (18)
    //         0045b52c     MOV        EAX,dword ptr [ESI + 0x14]
    //         0045b52f     INC        EBX
    //         0045b530     ADD        EDI,0x4
    //         0045b533     ADD        EBP,0x20
    //         0045b536     CMP        EBX,EAX
    //         0045b538     JL         LAB_0045b4b7
    //                               LAB_0045b53e                                                 XREF[2]:     0045b466(j), 0045b4ac(j)  
    //                              Mouseptr.cpp:483 (6)
    //         0045b53e     MOV        EAX,dword ptr [ESP + local_10]
    //         0045b542     JMP        LAB_0045b546
    //                               LAB_0045b544                                                 XREF[9]:     0045b3b2(j), 0045b3c1(j), 
    //                                                                                                         0045b3cd(j), 0045b414(j), 
    //                                                                                                         0045b41d(j), 0045b441(j), 
    //                                                                                                         0045b474(j), 0045b48f(j), 
    //                                                                                                         0045b49a(j)  
    //                              Mouseptr.cpp:419 (2)
    //         0045b544     XOR        EAX,EAX
    //                               LAB_0045b546                                                 XREF[1]:     0045b542(j)  
    //                              Mouseptr.cpp:484 (21)
    //         0045b546     MOV        this,dword ptr [ESP + local_c]
    //         0045b54a     POP        EDI
    //         0045b54b     POP        ESI
    //         0045b54c     POP        EBP
    //         0045b54d     MOV        dword ptr FS:[0x0],this
    //         0045b554     POP        EBX
    //         0045b555     ADD        ESP,0x10
    //         0045b558     RET        0xc
}

// Offset: 0x0045B560
void delete_surfaces(TMousePointer* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TMousePointer::delete_surfaces(void)                                          *
    //                              *********************************************************************************************************
    //                              void __thiscall delete_surfaces(TMousePointer * this)
    //              void              <VOID>         <RETURN>
    //              TMousePointer *   ECX:4 (auto)   this
    //                               ?delete_surfaces@TMousePointer@@QAEXXZ                       XREF[1]:     ~TMousePointer:0045b024(c)  
    //                               TMousePointer::delete_surfaces
    //                              Mouseptr.cpp:494 (4)
    //         0045b560     PUSH       EBX
    //         0045b561     PUSH       EBP
    //         0045b562     MOV        EBP,this
    //                              Mouseptr.cpp:496 (9)
    //         0045b564     XOR        EBX,EBX
    //         0045b566     CMP        dword ptr [EBP],EBX
    //         0045b569     JZ         LAB_0045b5c6
    //         0045b56b     PUSH       EDI
    //         0045b56c     PUSH       ESI
    //                              Mouseptr.cpp:500 (7)
    //         0045b56d     MOV        ESI,dword ptr [EBP + 0x8]
    //         0045b570     CMP        ESI,EBX
    //         0045b572     JZ         LAB_0045b587
    //                              Mouseptr.cpp:502 (16)
    //         0045b574     MOV        this,ESI
    //         0045b576     CALL       TDrawArea::~TDrawArea                            void ~TDrawArea(TDrawArea * this)
    //         0045b57b     PUSH       ESI
    //         0045b57c     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         0045b581     ADD        ESP,0x4
    //                              Mouseptr.cpp:503 (3)
    //         0045b584     MOV        dword ptr [EBP + 0x8],EBX
    //                               LAB_0045b587                                                 XREF[1]:     0045b572(j)  
    //                              Mouseptr.cpp:508 (8)
    //         0045b587     CMP        dword ptr [EBP + 0x14],EBX
    //         0045b58a     JLE        LAB_0045b5b6
    //         0045b58c     LEA        EDI,[EBP + 0x18]
    //                               LAB_0045b58f                                                 XREF[1]:     0045b5b4(j)  
    //                              Mouseptr.cpp:510 (6)
    //         0045b58f     MOV        ESI,dword ptr [EDI]
    //         0045b591     TEST       ESI,ESI
    //         0045b593     JZ         LAB_0045b5ab
    //                              Mouseptr.cpp:512 (16)
    //         0045b595     MOV        this,ESI
    //         0045b597     CALL       TDrawArea::~TDrawArea                            void ~TDrawArea(TDrawArea * this)
    //         0045b59c     PUSH       ESI
    //         0045b59d     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         0045b5a2     ADD        ESP,0x4
    //                              Mouseptr.cpp:513 (17)
    //         0045b5a5     MOV        dword ptr [EDI],0x0
    //                               LAB_0045b5ab                                                 XREF[1]:     0045b593(j)  
    //         0045b5ab     MOV        EAX,dword ptr [EBP + 0x14]
    //         0045b5ae     INC        EBX
    //         0045b5af     ADD        EDI,0x4
    //         0045b5b2     CMP        EBX,EAX
    //         0045b5b4     JL         LAB_0045b58f
    //                               LAB_0045b5b6                                                 XREF[1]:     0045b58a(j)  
    //                              Mouseptr.cpp:519 (16)
    //         0045b5b6     MOV        this,EBP
    //         0045b5b8     MOV        dword ptr [EBP + 0x10],0x0
    //         0045b5bf     CALL       TMousePointer::reset                             void reset(TMousePointer * this)
    //         0045b5c4     POP        ESI
    //         0045b5c5     POP        EDI
    //                               LAB_0045b5c6                                                 XREF[1]:     0045b569(j)  
    //                              Mouseptr.cpp:520 (3)
    //         0045b5c6     POP        EBP
    //         0045b5c7     POP        EBX
    //         0045b5c8     RET
}

// Offset: 0x0045B5D0
int create_surfaces(TMousePointer* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall TMousePointer::create_surfaces(void)                                           *
    //                              *********************************************************************************************************
    //                              int __thiscall create_surfaces(TMousePointer * this)
    //              int               EAX:4          <RETURN>
    //              TMousePointer *   ECX:4 (auto)   this
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[4]:     0045b636(W), 0045b64f(W), 0045b6e2(W), 0045b6fc(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[5]:     0045b5f9(R), 0045b65e(R), 0045b68c(R), 0045b732(R), 
    //                                                                                     0045b745(R)  
    //              char[32]          Stack[-0x30]   NameBuf                   XREF[2,2]:   0045b630(W), 0045b6dc(W), 0045b6bd(*), 0045b6e8(*)  
    //                               ?create_surfaces@TMousePointer@@QAEHXZ                       XREF[1]:     LoadCursors:0045b43a(c)  
    //                               TMousePointer::create_surfaces
    //                              Mouseptr.cpp:528 (30)
    //         0045b5d0     MOV        EAX,FS:[0x0]
    //         0045b5d6     PUSH       -0x1
    //         0045b5d8     PUSH       FUN_0055dc56
    //         0045b5dd     PUSH       EAX
    //         0045b5de     MOV        dword ptr FS:[0x0],ESP
    //         0045b5e5     SUB        ESP,0x24
    //         0045b5e8     PUSH       EBX
    //         0045b5e9     PUSH       EBP
    //         0045b5ea     PUSH       ESI
    //         0045b5eb     MOV        ESI,this
    //         0045b5ed     PUSH       EDI
    //                              Mouseptr.cpp:533 (11)
    //         0045b5ee     XOR        EDI,EDI
    //         0045b5f0     CMP        dword ptr [ESI],EDI
    //         0045b5f2     JNZ        LAB_0045b60c
    //         0045b5f4     MOV        EAX,0x1
    //                              Mouseptr.cpp:559 (19)
    //         0045b5f9     MOV        this,dword ptr [ESP + local_c]
    //         0045b5fd     MOV        dword ptr FS:[0x0],this
    //         0045b604     POP        EDI
    //         0045b605     POP        ESI
    //         0045b606     POP        EBP
    //         0045b607     POP        EBX
    //         0045b608     ADD        ESP,0x30
    //         0045b60b     RET
    //                               LAB_0045b60c                                                 XREF[1]:     0045b5f2(j)  
    //                              Mouseptr.cpp:535 (23)
    //         0045b60c     CMP        dword ptr [ESI + 0x8],EDI
    //         0045b60f     JNZ        LAB_0045b69f
    //         0045b615     CMP        dword ptr [ESI + 0x60],EDI
    //         0045b618     JLE        LAB_0045b69f
    //         0045b61e     CMP        dword ptr [ESI + 0x64],EDI
    //         0045b621     JLE        LAB_0045b69f
    //                              Mouseptr.cpp:537 (42)
    //         0045b623     PUSH       0x100
    //         0045b628     CALL       operator_new                                     void * operator_new(uint param_1)
    //         0045b62d     ADD        ESP,0x4
    //         0045b630     MOV        dword ptr [ESP + NameBuf[0]],EAX
    //         0045b634     CMP        EAX,EDI
    //         0045b636     MOV        dword ptr [ESP + local_4],EDI
    //         0045b63a     JZ         LAB_0045b64b
    //         0045b63c     PUSH       EDI
    //         0045b63d     PUSH       s_Mouse_Save_area                                = "Mouse Save area"
    //         0045b642     MOV        this,EAX
    //         0045b644     CALL       TDrawArea::TDrawArea                             undefined TDrawArea(TDrawArea * this, char * 
    //         0045b649     JMP        LAB_0045b64d
    //                               LAB_0045b64b                                                 XREF[1]:     0045b63a(j)  
    //         0045b64b     XOR        EAX,EAX
    //                               LAB_0045b64d                                                 XREF[1]:     0045b649(j)  
    //                              Mouseptr.cpp:538 (17)
    //         0045b64d     CMP        EAX,EDI
    //         0045b64f     MOV        dword ptr [ESP + local_4],0xffffffff
    //         0045b657     MOV        dword ptr [ESI + 0x8],EAX
    //         0045b65a     JNZ        LAB_0045b671
    //         0045b65c     XOR        EAX,EAX
    //                              Mouseptr.cpp:559 (19)
    //         0045b65e     MOV        this,dword ptr [ESP + local_c]
    //         0045b662     MOV        dword ptr FS:[0x0],this
    //         0045b669     POP        EDI
    //         0045b66a     POP        ESI
    //         0045b66b     POP        EBP
    //         0045b66c     POP        EBX
    //         0045b66d     ADD        ESP,0x30
    //         0045b670     RET
    //                               LAB_0045b671                                                 XREF[1]:     0045b65a(j)  
    //                              Mouseptr.cpp:539 (27)
    //         0045b671     MOV        this,dword ptr [ESI + 0x64]
    //         0045b674     MOV        EDX,dword ptr [ESI + 0x60]
    //         0045b677     PUSH       EDI
    //         0045b678     PUSH       EDI
    //         0045b679     PUSH       this
    //         0045b67a     MOV        this,dword ptr [ESI + 0x4]
    //         0045b67d     PUSH       EDX
    //         0045b67e     MOV        EDX,dword ptr [this->custom_draw]
    //         0045b680     MOV        this,EAX
    //         0045b682     PUSH       EDX
    //         0045b683     CALL       TDrawArea::Init                                  int Init(TDrawArea * this, TDrawSystem * para
    //         0045b688     TEST       EAX,EAX
    //         0045b68a     JNZ        LAB_0045b69f
    //                              Mouseptr.cpp:559 (19)
    //         0045b68c     MOV        this,dword ptr [ESP + local_c]
    //         0045b690     MOV        dword ptr FS:[0x0],this
    //         0045b697     POP        EDI
    //         0045b698     POP        ESI
    //         0045b699     POP        EBP
    //         0045b69a     POP        EBX
    //         0045b69b     ADD        ESP,0x30
    //         0045b69e     RET
    //                               LAB_0045b69f                                                 XREF[4]:     0045b60f(j), 0045b618(j), 
    //                                                                                                         0045b621(j), 0045b68a(j)  
    //                              Mouseptr.cpp:544 (16)
    //         0045b69f     MOV        EAX,dword ptr [ESI + 0x5c]
    //         0045b6a2     MOV        EBP,0x1
    //         0045b6a7     CMP        EAX,EDI
    //         0045b6a9     JNZ        LAB_0045b730
    //                              Mouseptr.cpp:546 (5)
    //         0045b6af     CMP        dword ptr [ESI + 0x14],EDI
    //         0045b6b2     JLE        LAB_0045b730
    //                              Mouseptr.cpp:559 (3)
    //         0045b6b4     LEA        EBX,[ESI + 0x18]
    //                               LAB_0045b6b7                                                 XREF[1]:     0045b72e(j)  
    //                              Mouseptr.cpp:548 (5)
    //         0045b6b7     CMP        dword ptr [EBX],0x0
    //         0045b6ba     JNZ        LAB_0045b725
    //                              Mouseptr.cpp:550 (19)
    //         0045b6bc     PUSH       EDI
    //         0045b6bd     LEA        EAX=>NameBuf[4],[ESP + 0x18]
    //         0045b6c1     PUSH       s_Mouse_Cursor_#%d                               = "Mouse Cursor #%d"
    //         0045b6c6     PUSH       EAX
    //         0045b6c7     CALL       sprintf                                          undefined sprintf()
    //         0045b6cc     ADD        ESP,0xc
    //                              Mouseptr.cpp:551 (43)
    //         0045b6cf     PUSH       0x100
    //         0045b6d4     CALL       operator_new                                     void * operator_new(uint param_1)
    //         0045b6d9     ADD        ESP,0x4
    //         0045b6dc     MOV        dword ptr [ESP + NameBuf[0]],EAX
    //         0045b6e0     TEST       EAX,EAX
    //         0045b6e2     MOV        dword ptr [ESP + local_4],EBP
    //         0045b6e6     JZ         LAB_0045b6f8
    //         0045b6e8     LEA        this=>NameBuf[4],[ESP + 0x14]
    //         0045b6ec     PUSH       0x0
    //         0045b6ee     PUSH       this
    //         0045b6ef     MOV        this,EAX
    //         0045b6f1     CALL       TDrawArea::TDrawArea                             undefined TDrawArea(TDrawArea * this, char * 
    //         0045b6f6     JMP        LAB_0045b6fa
    //                               LAB_0045b6f8                                                 XREF[1]:     0045b6e6(j)  
    //         0045b6f8     XOR        EAX,EAX
    //                               LAB_0045b6fa                                                 XREF[1]:     0045b6f6(j)  
    //                              Mouseptr.cpp:552 (14)
    //         0045b6fa     TEST       EAX,EAX
    //         0045b6fc     MOV        dword ptr [ESP + local_4],0xffffffff
    //         0045b704     MOV        dword ptr [EBX],EAX
    //         0045b706     JZ         LAB_0045b745
    //                              Mouseptr.cpp:553 (29)
    //         0045b708     MOV        EDX,dword ptr [ESI + 0x64]
    //         0045b70b     MOV        this,dword ptr [ESI + 0x60]
    //         0045b70e     PUSH       0x0
    //         0045b710     PUSH       0x0
    //         0045b712     PUSH       EDX
    //         0045b713     MOV        EDX,dword ptr [ESI + 0x4]
    //         0045b716     PUSH       this
    //         0045b717     MOV        this,dword ptr [EDX]
    //         0045b719     PUSH       this
    //         0045b71a     MOV        this,EAX
    //         0045b71c     CALL       TDrawArea::Init                                  int Init(TDrawArea * this, TDrawSystem * para
    //         0045b721     TEST       EAX,EAX
    //         0045b723     JZ         LAB_0045b745
    //                               LAB_0045b725                                                 XREF[1]:     0045b6ba(j)  
    //                              Mouseptr.cpp:546 (11)
    //         0045b725     MOV        EAX,dword ptr [ESI + 0x14]
    //         0045b728     INC        EDI
    //         0045b729     ADD        EBX,0x4
    //         0045b72c     CMP        EDI,EAX
    //         0045b72e     JL         LAB_0045b6b7
    //                               LAB_0045b730                                                 XREF[2]:     0045b6a9(j), 0045b6b2(j)  
    //                              Mouseptr.cpp:558 (2)
    //         0045b730     MOV        EAX,EBP
    //                              Mouseptr.cpp:559 (40)
    //         0045b732     MOV        this,dword ptr [ESP + local_c]
    //         0045b736     MOV        dword ptr FS:[0x0],this
    //         0045b73d     POP        EDI
    //         0045b73e     POP        ESI
    //         0045b73f     POP        EBP
    //         0045b740     POP        EBX
    //         0045b741     ADD        ESP,0x30
    //         0045b744     RET
    //                               LAB_0045b745                                                 XREF[2]:     0045b706(j), 0045b723(j)  
    //         0045b745     MOV        this,dword ptr [ESP + local_c]
    //         0045b749     POP        EDI
    //         0045b74a     POP        ESI
    //         0045b74b     POP        EBP
    //         0045b74c     XOR        EAX,EAX
    //         0045b74e     MOV        dword ptr FS:[0x0],this
    //         0045b755     POP        EBX
    //         0045b756     ADD        ESP,0x30
    //         0045b759     RET
}

// Offset: 0x0045B760
int update_mouse_position(TMousePointer* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall TMousePointer::update_mouse_position(void)                                     *
    //                              *********************************************************************************************************
    //                              int __thiscall update_mouse_position(TMousePointer * this)
    //              int               EAX:4          <RETURN>
    //              TMousePointer *   ECX:4 (auto)   this
    //              tagPOINT          Stack[-0xc]:8  point                     XREF[0,1]:   0045b779(*)  
    //                               ?update_mouse_position@TMousePointer@@QAEHXZ                 XREF[2]:     draw:0045bacb(c), 
    //                               TMousePointer::update_mouse_position                                      Poll:0045c078(c)  
    //                              Mouseptr.cpp:567 (9)
    //         0045b760     SUB        ESP,0x8
    //         0045b763     PUSH       EBX
    //         0045b764     PUSH       EBP
    //         0045b765     PUSH       ESI
    //         0045b766     MOV        ESI,this
    //         0045b768     PUSH       EDI
    //                              Mouseptr.cpp:572 (8)
    //         0045b769     XOR        EDI,EDI
    //         0045b76b     CMP        dword ptr [ESI],EDI
    //         0045b76d     JNZ        LAB_0045b779
    //         0045b76f     XOR        EAX,EAX
    //                              Mouseptr.cpp:717 (8)
    //         0045b771     POP        EDI
    //         0045b772     POP        ESI
    //         0045b773     POP        EBP
    //         0045b774     POP        EBX
    //         0045b775     ADD        ESP,0x8
    //         0045b778     RET
    //                               LAB_0045b779                                                 XREF[1]:     0045b76d(j)  
    //                              Mouseptr.cpp:576 (11)
    //         0045b779     LEA        EAX=>point.y,[ESP + 0x10]
    //         0045b77d     PUSH       EAX
    //         0045b77e     CALL       dword ptr [->USER32.DLL::GetCursorPos]           = 0048aeba
    //                              Mouseptr.cpp:578 (14)
    //         0045b784     MOV        EAX,dword ptr [ESI + 0x4]
    //         0045b787     MOV        this,dword ptr [EAX]
    //         0045b789     CMP        byte ptr [this->custom_draw + 0x479],0x1
    //         0045b790     JNZ        LAB_0045b7cd
    //                              Mouseptr.cpp:580 (15)
    //         0045b792     MOV        EAX,dword ptr [EAX + 0x4]
    //         0045b795     LEA        EDX,[ESP + 0x10]
    //         0045b799     PUSH       EDX
    //         0045b79a     PUSH       EAX
    //         0045b79b     CALL       dword ptr [->USER32.DLL::ScreenToClient]         = 0048aea8
    //                              Mouseptr.cpp:581 (22)
    //         0045b7a1     MOV        EDX,dword ptr [ESP + 0x10]
    //         0045b7a5     CMP        EDX,0x8000
    //         0045b7ab     JLE        LAB_0045b7b7
    //         0045b7ad     SUB        EDX,0x10000
    //         0045b7b3     MOV        dword ptr [ESP + 0x10],EDX
    //                               LAB_0045b7b7                                                 XREF[1]:     0045b7ab(j)  
    //                              Mouseptr.cpp:582 (30)
    //         0045b7b7     MOV        EAX,dword ptr [ESP + 0x14]
    //         0045b7bb     CMP        EAX,0x8000
    //         0045b7c0     JLE        LAB_0045b7d5
    //         0045b7c2     SUB        EAX,0x10000
    //         0045b7c7     MOV        dword ptr [ESP + 0x14],EAX
    //         0045b7cb     JMP        LAB_0045b7d5
    //                               LAB_0045b7cd                                                 XREF[1]:     0045b790(j)  
    //         0045b7cd     MOV        EAX,dword ptr [ESP + 0x14]
    //         0045b7d1     MOV        EDX,dword ptr [ESP + 0x10]
    //                               LAB_0045b7d5                                                 XREF[2]:     0045b7c0(j), 0045b7cb(j)  
    //                              Mouseptr.cpp:586 (3)
    //         0045b7d5     MOV        dword ptr [ESI + 0x78],EDX
    //                              Mouseptr.cpp:587 (3)
    //         0045b7d8     MOV        dword ptr [ESI + 0x7c],EAX
    //                              Mouseptr.cpp:593 (53)
    //         0045b7db     CMP        dword ptr [ESI + 0x138],EDI
    //         0045b7e1     JZ         LAB_0045b823
    //         0045b7e3     CMP        dword ptr [ESI + 0x13c],EDI
    //         0045b7e9     JZ         LAB_0045b823
    //         0045b7eb     MOV        this,dword ptr [ESI + 0x78]
    //         0045b7ee     MOV        EBX,dword ptr [ESI + 0x10c]
    //         0045b7f4     CMP        this,EBX
    //         0045b7f6     JL         LAB_0045b823
    //         0045b7f8     CMP        this,dword ptr [ESI + 0x114]
    //         0045b7fe     JGE        LAB_0045b823
    //         0045b800     CMP        EAX,dword ptr [ESI + 0x110]
    //         0045b806     JL         LAB_0045b823
    //         0045b808     CMP        EAX,dword ptr [ESI + 0x118]
    //         0045b80e     JGE        LAB_0045b823
    //                              Mouseptr.cpp:595 (12)
    //         0045b810     MOV        this,dword ptr [ESI + 0x8c]
    //         0045b816     MOV        dword ptr [ESI + 0x90],this
    //                              Mouseptr.cpp:596 (5)
    //         0045b81c     MOV        this,0x1
    //                              Mouseptr.cpp:598 (2)
    //         0045b821     JMP        LAB_0045b831
    //                               LAB_0045b823                                                 XREF[6]:     0045b7e1(j), 0045b7e9(j), 
    //                                                                                                         0045b7f6(j), 0045b7fe(j), 
    //                                                                                                         0045b806(j), 0045b80e(j)  
    //                              Mouseptr.cpp:600 (12)
    //         0045b823     MOV        this,dword ptr [ESI + 0x88]
    //         0045b829     MOV        dword ptr [ESI + 0x90],this
    //                              Mouseptr.cpp:601 (2)
    //         0045b82f     XOR        this,this
    //                               LAB_0045b831                                                 XREF[1]:     0045b821(j)  
    //                              Mouseptr.cpp:606 (42)
    //         0045b831     CMP        dword ptr [ESI + 0xb8],EDI
    //         0045b837     JZ         LAB_0045b863
    //         0045b839     CMP        EDX,dword ptr [ESI + 0x80]
    //         0045b83f     JNZ        LAB_0045b863
    //         0045b841     CMP        EAX,dword ptr [ESI + 0x84]
    //         0045b847     JNZ        LAB_0045b863
    //         0045b849     MOV        EBX,dword ptr [ESI + 0x90]
    //         0045b84f     MOV        EBP,dword ptr [ESI + 0x94]
    //         0045b855     CMP        EBX,EBP
    //         0045b857     JNZ        LAB_0045b863
    //         0045b859     XOR        EAX,EAX
    //                              Mouseptr.cpp:717 (8)
    //         0045b85b     POP        EDI
    //         0045b85c     POP        ESI
    //         0045b85d     POP        EBP
    //         0045b85e     POP        EBX
    //         0045b85f     ADD        ESP,0x8
    //         0045b862     RET
    //                               LAB_0045b863                                                 XREF[4]:     0045b837(j), 0045b83f(j), 
    //                                                                                                         0045b847(j), 0045b857(j)  
    //                              Mouseptr.cpp:613 (14)
    //         0045b863     CMP        this,EDI
    //         0045b865     MOV        dword ptr [ESI + 0x80],EDX
    //         0045b86b     MOV        dword ptr [ESI + 0x84],EAX
    //                              Mouseptr.cpp:615 (6)
    //         0045b871     MOV        dword ptr [ESI + 0xec],EDI
    //                              Mouseptr.cpp:616 (8)
    //         0045b877     MOV        dword ptr [ESI + 0xf0],EDI
    //         0045b87d     JZ         LAB_0045b8cd
    //                              Mouseptr.cpp:618 (12)
    //         0045b87f     MOV        EAX,dword ptr [ESI + 0x74]
    //         0045b882     MOV        EDX,dword ptr [ESI + 0x70]
    //         0045b885     MOV        dword ptr [ESI + 0xf8],EAX
    //                              Mouseptr.cpp:620 (15)
    //         0045b88b     MOV        EAX,dword ptr [ESI + 0x78]
    //         0045b88e     MOV        dword ptr [ESI + 0xf4],EDX
    //         0045b894     MOV        EDX,dword ptr [ESI + 0xac]
    //                              Mouseptr.cpp:621 (29)
    //         0045b89a     MOV        EBP,dword ptr [ESI + 0xa8]
    //         0045b8a0     MOV        this,EAX
    //         0045b8a2     SUB        this,EDX
    //         0045b8a4     MOV        dword ptr [ESI + 0xcc],this
    //         0045b8aa     MOV        this,dword ptr [ESI + 0x7c]
    //         0045b8ad     MOV        EDX,this
    //         0045b8af     SUB        EDX,EBP
    //         0045b8b1     MOV        dword ptr [ESI + 0xd0],EDX
    //                              Mouseptr.cpp:622 (8)
    //         0045b8b7     MOV        EDX,dword ptr [ESI + 0xb4]
    //         0045b8bd     ADD        EDX,EAX
    //                              Mouseptr.cpp:623 (12)
    //         0045b8bf     MOV        EAX,dword ptr [ESI + 0xb0]
    //         0045b8c5     MOV        dword ptr [ESI + 0xd4],EDX
    //                              Mouseptr.cpp:625 (2)
    //         0045b8cb     JMP        LAB_0045b919
    //                               LAB_0045b8cd                                                 XREF[1]:     0045b87d(j)  
    //                              Mouseptr.cpp:629 (3)
    //         0045b8cd     MOV        this,dword ptr [ESI + 0x68]
    //                              Mouseptr.cpp:630 (3)
    //         0045b8d0     MOV        EDX,dword ptr [ESI + 0x6c]
    //                              Mouseptr.cpp:632 (21)
    //         0045b8d3     MOV        EAX,dword ptr [ESI + 0x78]
    //         0045b8d6     MOV        dword ptr [ESI + 0xf4],this
    //         0045b8dc     MOV        dword ptr [ESI + 0xf8],EDX
    //         0045b8e2     MOV        EDX,dword ptr [ESI + 0x9c]
    //                              Mouseptr.cpp:633 (29)
    //         0045b8e8     MOV        EBP,dword ptr [ESI + 0x98]
    //         0045b8ee     MOV        this,EAX
    //         0045b8f0     SUB        this,EDX
    //         0045b8f2     MOV        dword ptr [ESI + 0xcc],this
    //         0045b8f8     MOV        this,dword ptr [ESI + 0x7c]
    //         0045b8fb     MOV        EDX,this
    //         0045b8fd     SUB        EDX,EBP
    //         0045b8ff     MOV        dword ptr [ESI + 0xd0],EDX
    //                              Mouseptr.cpp:634 (8)
    //         0045b905     MOV        EDX,dword ptr [ESI + 0xa4]
    //         0045b90b     ADD        EDX,EAX
    //                              Mouseptr.cpp:635 (12)
    //         0045b90d     MOV        EAX,dword ptr [ESI + 0xa0]
    //         0045b913     MOV        dword ptr [ESI + 0xd4],EDX
    //                               LAB_0045b919                                                 XREF[1]:     0045b8cb(j)  
    //                              Mouseptr.cpp:638 (51)
    //         0045b919     MOV        EDX,dword ptr [ESI + 0xec]
    //         0045b91f     LEA        EBX,[ESI + 0xdc]
    //         0045b925     ADD        EAX,this
    //         0045b927     MOV        this,EBX
    //         0045b929     MOV        dword ptr [ESI + 0xd8],EAX
    //         0045b92f     MOV        EAX,dword ptr [ESI + 0xf0]
    //         0045b935     MOV        dword ptr [this->custom_draw],EDX
    //         0045b937     MOV        EDX,dword ptr [ESI + 0xf4]
    //         0045b93d     MOV        dword ptr [ECX + this->render_area],EAX
    //         0045b940     MOV        EAX,dword ptr [ESI + 0xf8]
    //         0045b946     MOV        dword ptr [ECX + this->save_area],EDX
    //         0045b949     MOV        dword ptr [ECX + this->primary_area],EAX
    //                              Mouseptr.cpp:643 (61)
    //         0045b94c     MOV        this,dword ptr [ESI + 0xd4]
    //         0045b952     CMP        this,EDI
    //         0045b954     JL         LAB_0045ba40
    //         0045b95a     MOV        EBP,dword ptr [ESI + 0xd8]
    //         0045b960     CMP        EBP,EDI
    //         0045b962     JL         LAB_0045ba40
    //         0045b968     MOV        EDX,dword ptr [ESI + 0x4]
    //         0045b96b     MOV        EAX,dword ptr [ESI + 0xcc]
    //         0045b971     CMP        EAX,dword ptr [EDX + 0x18]
    //         0045b974     JG         LAB_0045ba40
    //         0045b97a     MOV        EDI,dword ptr [ESI + 0xd0]
    //         0045b980     CMP        EDI,dword ptr [EDX + 0x1c]
    //         0045b983     JG         LAB_0045ba3e
    //                              Mouseptr.cpp:651 (4)
    //         0045b989     TEST       EAX,EAX
    //         0045b98b     JGE        LAB_0045b9a9
    //                              Mouseptr.cpp:653 (2)
    //         0045b98d     NEG        EAX
    //                              Mouseptr.cpp:655 (2)
    //         0045b98f     MOV        dword ptr [EBX],EAX
    //                              Mouseptr.cpp:656 (8)
    //         0045b991     MOV        EBX,dword ptr [ESI + 0xf4]
    //         0045b997     SUB        EBX,EAX
    //                              Mouseptr.cpp:657 (16)
    //         0045b999     MOV        dword ptr [ESI + 0xcc],0x0
    //         0045b9a3     MOV        dword ptr [ESI + 0xf4],EBX
    //                               LAB_0045b9a9                                                 XREF[1]:     0045b98b(j)  
    //                              Mouseptr.cpp:660 (7)
    //         0045b9a9     MOV        EAX,dword ptr [EDX + 0x18]
    //         0045b9ac     CMP        this,EAX
    //         0045b9ae     JLE        LAB_0045b9d7
    //                              Mouseptr.cpp:664 (8)
    //         0045b9b0     MOV        EBX,dword ptr [ESI + 0xe4]
    //         0045b9b6     SUB        this,EAX
    //                              Mouseptr.cpp:665 (22)
    //         0045b9b8     MOV        EAX,dword ptr [ESI + 0xf4]
    //         0045b9be     SUB        EBX,this
    //         0045b9c0     SUB        EAX,this
    //         0045b9c2     MOV        dword ptr [ESI + 0xe4],EBX
    //         0045b9c8     MOV        dword ptr [ESI + 0xf4],EAX
    //                              Mouseptr.cpp:666 (9)
    //         0045b9ce     MOV        this,dword ptr [EDX + 0x18]
    //         0045b9d1     MOV        dword ptr [ESI + 0xd4],this
    //                               LAB_0045b9d7                                                 XREF[1]:     0045b9ae(j)  
    //                              Mouseptr.cpp:669 (4)
    //         0045b9d7     TEST       EDI,EDI
    //         0045b9d9     JGE        LAB_0045b9fb
    //                              Mouseptr.cpp:674 (6)
    //         0045b9db     MOV        EAX,dword ptr [ESI + 0xf8]
    //                              Mouseptr.cpp:675 (26)
    //         0045b9e1     MOV        dword ptr [ESI + 0xd0],0x0
    //         0045b9eb     NEG        EDI
    //         0045b9ed     SUB        EAX,EDI
    //         0045b9ef     MOV        dword ptr [ESI + 0xe0],EDI
    //         0045b9f5     MOV        dword ptr [ESI + 0xf8],EAX
    //                               LAB_0045b9fb                                                 XREF[1]:     0045b9d9(j)  
    //                              Mouseptr.cpp:678 (7)
    //         0045b9fb     MOV        EAX,dword ptr [EDX + 0x1c]
    //         0045b9fe     CMP        EBP,EAX
    //         0045ba00     JLE        LAB_0045ba2b
    //                              Mouseptr.cpp:682 (6)
    //         0045ba02     MOV        EDI,dword ptr [ESI + 0xe8]
    //                              Mouseptr.cpp:683 (26)
    //         0045ba08     MOV        this,dword ptr [ESI + 0xf8]
    //         0045ba0e     SUB        EBP,EAX
    //         0045ba10     MOV        EAX,EBP
    //         0045ba12     SUB        EDI,EAX
    //         0045ba14     SUB        this,EAX
    //         0045ba16     MOV        dword ptr [ESI + 0xe8],EDI
    //         0045ba1c     MOV        dword ptr [ESI + 0xf8],this
    //                              Mouseptr.cpp:684 (9)
    //         0045ba22     MOV        EDX,dword ptr [EDX + 0x1c]
    //         0045ba25     MOV        dword ptr [ESI + 0xd8],EDX
    //                               LAB_0045ba2b                                                 XREF[1]:     0045ba00(j)  
    //                              Mouseptr.cpp:714 (11)
    //         0045ba2b     MOV        EAX,0x1
    //         0045ba30     MOV        dword ptr [ESI + 0x140],EAX
    //                              Mouseptr.cpp:717 (8)
    //         0045ba36     POP        EDI
    //         0045ba37     POP        ESI
    //         0045ba38     POP        EBP
    //         0045ba39     POP        EBX
    //         0045ba3a     ADD        ESP,0x8
    //         0045ba3d     RET
    //                               LAB_0045ba3e                                                 XREF[1]:     0045b983(j)  
    //                              Mouseptr.cpp:716 (2)
    //         0045ba3e     XOR        EDI,EDI
    //                               LAB_0045ba40                                                 XREF[3]:     0045b954(j), 0045b962(j), 
    //                                                                                                         0045b974(j)  
    //                              Mouseptr.cpp:645 (6)
    //         0045ba40     MOV        dword ptr [ESI + 0x140],EDI
    //                              Mouseptr.cpp:717 (13)
    //         0045ba46     POP        EDI
    //         0045ba47     POP        ESI
    //         0045ba48     POP        EBP
    //         0045ba49     MOV        EAX,0x1
    //         0045ba4e     POP        EBX
    //         0045ba4f     ADD        ESP,0x8
    //         0045ba52     RET
}

// Offset: 0x0045BA60
void draw(TMousePointer* this_, int param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TMousePointer::draw(int)                                                      *
    //                              *********************************************************************************************************
    //                              void __thiscall draw(TMousePointer * this, int param_1)
    //              void              <VOID>         <RETURN>
    //              TMousePointer *   ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0045ba95(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     0045ba67(W)  
    //              IDirectDrawCli    Stack[-0x8]:4  lplpDDClipper
    //                               ?draw@TMousePointer@@QAEXH@Z                                 XREF[3]:     handle_mouse_move:0042115f(c), 
    //                               TMousePointer::draw                                                       handle_paint:004216b5(c), 
    //                                                                                                         handle_paint:004217e2(c)  
    //                              Mouseptr.cpp:724 (7)
    //         0045ba60     PUSH       this
    //         0045ba61     PUSH       EBX
    //         0045ba62     PUSH       EBP
    //         0045ba63     PUSH       ESI
    //         0045ba64     MOV        ESI,this
    //         0045ba66     PUSH       EDI
    //                              Mouseptr.cpp:729 (8)
    //         0045ba67     MOV        dword ptr [ESP + local_4],0x0
    //                              Mouseptr.cpp:735 (23)
    //         0045ba6f     MOV        EAX,dword ptr [ESI + 0x128]
    //         0045ba75     TEST       EAX,EAX
    //         0045ba77     JZ         LAB_0045bd50
    //         0045ba7d     CMP        dword ptr [ESI],0x0
    //         0045ba80     JZ         LAB_0045bd50
    //                              Mouseptr.cpp:739 (15)
    //         0045ba86     PUSH       0x2e3
    //         0045ba8b     PUSH       s_C:\msdev\work\age1_x1\Mouseptr.c               = "C:\\msdev\\work\\age1_x1\\Mouseptr.cpp"
    //         0045ba90     CALL       debug_timeGetTime                                ulong debug_timeGetTime(char * param_1, int p
    //                              Mouseptr.cpp:741 (33)
    //         0045ba95     MOV        EBX,dword ptr [ESP + param_1]
    //         0045ba99     MOV        EDI,EAX
    //         0045ba9b     MOV        EAX,dword ptr [ESI + 0x138]
    //         0045baa1     ADD        ESP,0x8
    //         0045baa4     TEST       EAX,EAX
    //         0045baa6     JZ         LAB_0045bac9
    //         0045baa8     MOV        EAX,dword ptr [ESI + 0x13c]
    //         0045baae     TEST       EAX,EAX
    //         0045bab0     JZ         LAB_0045bac9
    //         0045bab2     TEST       EBX,EBX
    //         0045bab4     JNZ        LAB_0045bac9
    //                              Mouseptr.cpp:743 (19)
    //         0045bab6     MOV        EDX,dword ptr [ESI + 0x144]
    //         0045babc     MOV        EAX,EDI
    //         0045babe     SUB        EAX,EDX
    //         0045bac0     CMP        EAX,0x22
    //         0045bac3     JC         LAB_0045bd50
    //                               LAB_0045bac9                                                 XREF[3]:     0045baa6(j), 0045bab0(j), 
    //                                                                                                         0045bab4(j)  
    //                              Mouseptr.cpp:748 (19)
    //         0045bac9     MOV        this,ESI
    //         0045bacb     CALL       TMousePointer::update_mouse_position             int update_mouse_position(TMousePointer * this)
    //         0045bad0     TEST       EAX,EAX
    //         0045bad2     JNZ        LAB_0045badc
    //         0045bad4     TEST       EBX,EBX
    //         0045bad6     JZ         LAB_0045bd50
    //                               LAB_0045badc                                                 XREF[1]:     0045bad2(j)  
    //                              Mouseptr.cpp:756 (32)
    //         0045badc     MOV        EAX,dword ptr [ESI + 0xb8]
    //         0045bae2     MOV        dword ptr [ESI + 0x144],EDI
    //         0045bae8     TEST       EAX,EAX
    //         0045baea     JZ         LAB_0045bb30
    //         0045baec     MOV        EAX,dword ptr [ESI + 0x11c]
    //         0045baf2     MOV        this,dword ptr [ESI + 0x124]
    //         0045baf8     CMP        EAX,this
    //         0045bafa     JZ         LAB_0045bb30
    //                              Mouseptr.cpp:758 (34)
    //         0045bafc     PUSH       0x0
    //         0045bafe     LEA        EDX,[ESI + 0xbc]
    //         0045bb04     PUSH       0x1000000
    //         0045bb09     PUSH       EDX
    //         0045bb0a     MOV        EDX,dword ptr [ESI + 0x8]
    //         0045bb0d     MOV        this,dword ptr [EAX]
    //         0045bb0f     MOV        EDX,dword ptr [EDX + 0x3c]
    //         0045bb12     PUSH       EDX
    //         0045bb13     LEA        EDX,[ESI + 0xfc]
    //         0045bb19     PUSH       EDX
    //         0045bb1a     PUSH       EAX
    //         0045bb1b     CALL       dword ptr [ECX + this->Max_Cursors]
    //                              Mouseptr.cpp:759 (4)
    //         0045bb1e     TEST       EAX,EAX
    //         0045bb20     JZ         LAB_0045bb30
    //                              Mouseptr.cpp:761 (6)
    //         0045bb22     MOV        dword ptr [ESI + 0x148],EAX
    //                              Mouseptr.cpp:875 (8)
    //         0045bb28     POP        EDI
    //         0045bb29     POP        ESI
    //         0045bb2a     POP        EBP
    //         0045bb2b     POP        EBX
    //         0045bb2c     POP        this
    //         0045bb2d     RET        0x4
    //                               LAB_0045bb30                                                 XREF[3]:     0045baea(j), 0045bafa(j), 
    //                                                                                                         0045bb20(j)  
    //                              Mouseptr.cpp:768 (19)
    //         0045bb30     MOV        EAX,dword ptr [ESI + 0x140]
    //         0045bb36     MOV        EDI,0x1
    //         0045bb3b     TEST       EAX,EAX
    //         0045bb3d     JZ         LAB_0045bd16
    //                              Mouseptr.cpp:772 (40)
    //         0045bb43     MOV        EAX,dword ptr [ESI + 0x8]
    //         0045bb46     MOV        EDX,dword ptr [ESI + 0x120]
    //         0045bb4c     LEA        EBX,[ESI + 0xcc]
    //         0045bb52     PUSH       0x0
    //         0045bb54     MOV        EAX,dword ptr [EAX + 0x3c]
    //         0045bb57     PUSH       offset DAT_fffffff8
    //         0045bb5c     LEA        EDI,[ESI + 0xec]
    //         0045bb62     PUSH       EBX=>DAT_fffffff4
    //         0045bb63     MOV        this,dword ptr [EAX]
    //         0045bb65     PUSH       EDX=>DAT_fffffff0
    //         0045bb66     PUSH       EDI
    //         0045bb67     PUSH       EAX
    //         0045bb68     CALL       dword ptr [ECX + this->Max_Cursors]
    //                              Mouseptr.cpp:773 (4)
    //         0045bb6b     TEST       EAX,EAX
    //         0045bb6d     JZ         LAB_0045bb7d
    //                              Mouseptr.cpp:775 (6)
    //         0045bb6f     MOV        dword ptr [ESI + 0x148],EAX
    //                              Mouseptr.cpp:875 (8)
    //         0045bb75     POP        EDI
    //         0045bb76     POP        ESI
    //         0045bb77     POP        EBP
    //         0045bb78     POP        EBX
    //         0045bb79     POP        this
    //         0045bb7a     RET        0x4
    //                               LAB_0045bb7d                                                 XREF[1]:     0045bb6d(j)  
    //                              Mouseptr.cpp:782 (42)
    //         0045bb7d     MOV        EDX,EBX
    //         0045bb7f     LEA        this,[ESI + 0xfc]
    //         0045bb85     MOV        EAX,dword ptr [ESI + 0x120]
    //         0045bb8b     MOV        EBP,dword ptr [EDX]
    //         0045bb8d     MOV        dword ptr [ESI + 0x11c],EAX
    //         0045bb93     MOV        dword ptr [this->custom_draw],EBP
    //         0045bb95     MOV        EBP,dword ptr [EDX + 0x4]
    //         0045bb98     MOV        dword ptr [ECX + this->render_area],EBP
    //         0045bb9b     MOV        EBP,dword ptr [EDX + 0x8]
    //         0045bb9e     MOV        dword ptr [ECX + this->save_area],EBP
    //         0045bba1     MOV        EDX,dword ptr [EDX + 0xc]
    //         0045bba4     MOV        dword ptr [ECX + this->primary_area],EDX
    //                              Mouseptr.cpp:783 (29)
    //         0045bba7     MOV        EDX,dword ptr [EDI]
    //         0045bba9     LEA        this,[ESI + 0xbc]
    //         0045bbaf     MOV        dword ptr [ESI + 0xbc],EDX
    //         0045bbb5     MOV        EDX,dword ptr [EDI + 0x4]
    //         0045bbb8     MOV        dword ptr [ECX + this->render_area],EDX
    //         0045bbbb     MOV        EDX,dword ptr [EDI + 0x8]
    //         0045bbbe     MOV        dword ptr [ECX + this->save_area],EDX
    //         0045bbc1     MOV        EDX,dword ptr [EDI + 0xc]
    //                              Mouseptr.cpp:784 (8)
    //         0045bbc4     MOV        EDI,0x1
    //         0045bbc9     MOV        dword ptr [ECX + this->primary_area],EDX
    //                              Mouseptr.cpp:788 (13)
    //         0045bbcc     MOV        this,dword ptr [ESI + 0x5c]
    //         0045bbcf     TEST       this,this
    //         0045bbd1     MOV        dword ptr [ESI + 0xb8],EDI
    //         0045bbd7     JNZ        LAB_0045bc2b
    //                              Mouseptr.cpp:790 (11)
    //         0045bbd9     MOV        this,dword ptr [EAX]
    //         0045bbdb     LEA        EDX,[ESP + 0x10]
    //         0045bbdf     PUSH       EDX
    //         0045bbe0     PUSH       EAX=>DAT_fffffff8
    //         0045bbe1     CALL       dword ptr [ECX + this+0x3c]
    //                              Mouseptr.cpp:791 (7)
    //         0045bbe4     CMP        EAX,0x88760238
    //         0045bbe9     JNZ        LAB_0045bbf1
    //                              Mouseptr.cpp:793 (2)
    //         0045bbeb     XOR        EAX,EAX
    //                              Mouseptr.cpp:794 (4)
    //         0045bbed     MOV        dword ptr [ESP + 0x10],EAX
    //                               LAB_0045bbf1                                                 XREF[1]:     0045bbe9(j)  
    //                              Mouseptr.cpp:797 (4)
    //         0045bbf1     TEST       EAX,EAX
    //         0045bbf3     JZ         LAB_0045bc03
    //                              Mouseptr.cpp:799 (6)
    //         0045bbf5     MOV        dword ptr [ESI + 0x148],EAX
    //                              Mouseptr.cpp:875 (8)
    //         0045bbfb     POP        EDI
    //         0045bbfc     POP        ESI
    //         0045bbfd     POP        EBP
    //         0045bbfe     POP        EBX
    //         0045bbff     POP        this
    //         0045bc00     RET        0x4
    //                               LAB_0045bc03                                                 XREF[1]:     0045bbf3(j)  
    //                              Mouseptr.cpp:803 (8)
    //         0045bc03     MOV        EAX,dword ptr [ESP + 0x10]
    //         0045bc07     TEST       EAX,EAX
    //         0045bc09     JZ         LAB_0045bc2b
    //                              Mouseptr.cpp:805 (14)
    //         0045bc0b     MOV        EAX,dword ptr [ESI + 0x120]
    //         0045bc11     PUSH       0x0
    //         0045bc13     PUSH       EAX=>DAT_fffffff8
    //         0045bc14     MOV        this,dword ptr [EAX]
    //         0045bc16     CALL       dword ptr [ECX + this->gWidth]
    //                              Mouseptr.cpp:807 (4)
    //         0045bc19     TEST       EAX,EAX
    //         0045bc1b     JZ         LAB_0045bc2b
    //                              Mouseptr.cpp:809 (6)
    //         0045bc1d     MOV        dword ptr [ESI + 0x148],EAX
    //                              Mouseptr.cpp:875 (8)
    //         0045bc23     POP        EDI
    //         0045bc24     POP        ESI
    //         0045bc25     POP        EBP
    //         0045bc26     POP        EBX
    //         0045bc27     POP        this
    //         0045bc28     RET        0x4
    //                               LAB_0045bc2b                                                 XREF[3]:     0045bbd7(j), 0045bc09(j), 
    //                                                                                                         0045bc1b(j)  
    //                              Mouseptr.cpp:817 (5)
    //         0045bc2b     CMP        dword ptr [ESI + 0x5c],EDI
    //         0045bc2e     JNZ        LAB_0045bc84
    //                              Mouseptr.cpp:819 (18)
    //         0045bc30     MOV        this,dword ptr [ESI + 0x4]
    //         0045bc33     PUSH       EDI
    //         0045bc34     PUSH       s_mouseptr::draw                                 = "mouseptr::draw"
    //         0045bc39     CALL       TDrawArea::Lock                                  uchar * Lock(TDrawArea * this, char * param_1
    //         0045bc3e     TEST       EAX,EAX
    //         0045bc40     JZ         LAB_0045bc84
    //                              Mouseptr.cpp:821 (11)
    //         0045bc42     MOV        EDX,dword ptr [ESI + 0x90]
    //         0045bc48     MOV        this,dword ptr [ESI + 0x58]
    //         0045bc4b     MOV        EBP,EDX
    //                              Mouseptr.cpp:823 (42)
    //         0045bc4d     PUSH       0x0
    //         0045bc4f     MOV        EAX,dword ptr [ECX + this+0x1c]
    //         0045bc52     PUSH       0x0=>DAT_fffffff8
    //         0045bc54     SHL        EBP,0x5
    //         0045bc57     ADD        EAX,EBP
    //         0045bc59     MOV        EBP,dword ptr [ESI + 0xd0]
    //         0045bc5f     PUSH       EDX=>DAT_fffffff4
    //         0045bc60     MOV        EDX,dword ptr [EAX + 0x1c]
    //         0045bc63     MOV        EAX,dword ptr [EAX + 0x18]
    //         0045bc66     ADD        EDX,EBP
    //         0045bc68     MOV        EBP,dword ptr [EBX]
    //         0045bc6a     PUSH       EDX=>DAT_fffffff0
    //         0045bc6b     MOV        EDX,dword ptr [ESI + 0x4]
    //         0045bc6e     ADD        EAX,EBP
    //         0045bc70     PUSH       EAX
    //         0045bc71     PUSH       EDX
    //         0045bc72     CALL       TShape::shape_draw                               uchar shape_draw(TShape * this, TDrawArea * p
    //                              Mouseptr.cpp:825 (13)
    //         0045bc77     MOV        this,dword ptr [ESI + 0x4]
    //         0045bc7a     PUSH       s_mouseptr::draw                                 = "mouseptr::draw"
    //         0045bc7f     CALL       TDrawArea::Unlock                                void Unlock(TDrawArea * this, char * param_1)
    //                               LAB_0045bc84                                                 XREF[2]:     0045bc2e(j), 0045bc40(j)  
    //                              Mouseptr.cpp:829 (7)
    //         0045bc84     MOV        EAX,dword ptr [ESI + 0x5c]
    //         0045bc87     TEST       EAX,EAX
    //         0045bc89     JNZ        LAB_0045bcdc
    //                              Mouseptr.cpp:831 (18)
    //         0045bc8b     MOV        EAX,dword ptr [ESI + 0x90]
    //         0045bc91     PUSH       0x0
    //         0045bc93     PUSH       EDI=>DAT_fffffff8
    //         0045bc94     MOV        this,dword ptr [ESI + EAX*0x4 + 0x18]
    //         0045bc98     CALL       TDrawArea::SetTrans                              void SetTrans(TDrawArea * this, int param_1, 
    //                              Mouseptr.cpp:833 (45)
    //         0045bc9d     LEA        EDX,[ESI + 0xdc]
    //         0045bca3     PUSH       0x11
    //         0045bca5     PUSH       EDX=>DAT_fffffff8
    //         0045bca6     MOV        EDX,dword ptr [ESI + 0x90]
    //         0045bcac     MOV        EAX,dword ptr [ESI + 0x120]
    //         0045bcb2     MOV        EDX,dword ptr [ESI + EDX*0x4 + 0x18]
    //         0045bcb6     MOV        this,dword ptr [EAX]
    //         0045bcb8     MOV        EDX,dword ptr [EDX + 0x3c]
    //         0045bcbb     PUSH       EDX=>DAT_fffffff4
    //         0045bcbc     MOV        EDX,dword ptr [ESI + 0xd0]
    //         0045bcc2     PUSH       EDX=>DAT_fffffff0
    //         0045bcc3     MOV        EDX,dword ptr [EBX]
    //         0045bcc5     PUSH       EDX
    //         0045bcc6     PUSH       EAX
    //         0045bcc7     CALL       dword ptr [ECX + this+0x1c]
    //                              Mouseptr.cpp:835 (4)
    //         0045bcca     TEST       EAX,EAX
    //         0045bccc     JZ         LAB_0045bcdc
    //                              Mouseptr.cpp:837 (6)
    //         0045bcce     MOV        dword ptr [ESI + 0x148],EAX
    //                              Mouseptr.cpp:875 (8)
    //         0045bcd4     POP        EDI
    //         0045bcd5     POP        ESI
    //         0045bcd6     POP        EBP
    //         0045bcd7     POP        EBX
    //         0045bcd8     POP        this
    //         0045bcd9     RET        0x4
    //                               LAB_0045bcdc                                                 XREF[2]:     0045bc89(j), 0045bccc(j)  
    //                              Mouseptr.cpp:842 (12)
    //         0045bcdc     MOV        EAX,dword ptr [ESI + 0x90]
    //         0045bce2     MOV        dword ptr [ESI + 0x94],EAX
    //                              Mouseptr.cpp:846 (7)
    //         0045bce8     MOV        EAX,dword ptr [ESI + 0x5c]
    //         0045bceb     TEST       EAX,EAX
    //         0045bced     JNZ        LAB_0045bd20
    //                              Mouseptr.cpp:848 (8)
    //         0045bcef     MOV        this,dword ptr [ESP + 0x10]
    //         0045bcf3     TEST       this,this
    //         0045bcf5     JZ         LAB_0045bd20
    //                              Mouseptr.cpp:850 (13)
    //         0045bcf7     MOV        EAX,dword ptr [ESI + 0x120]
    //         0045bcfd     PUSH       this
    //         0045bcfe     PUSH       EAX=>DAT_fffffff8
    //         0045bcff     MOV        EDX,dword ptr [EAX]
    //         0045bd01     CALL       dword ptr [EDX + 0x70]
    //                              Mouseptr.cpp:851 (4)
    //         0045bd04     TEST       EAX,EAX
    //         0045bd06     JZ         LAB_0045bd20
    //                              Mouseptr.cpp:853 (6)
    //         0045bd08     MOV        dword ptr [ESI + 0x148],EAX
    //                              Mouseptr.cpp:875 (8)
    //         0045bd0e     POP        EDI
    //         0045bd0f     POP        ESI
    //         0045bd10     POP        EBP
    //         0045bd11     POP        EBX
    //         0045bd12     POP        this
    //         0045bd13     RET        0x4
    //                               LAB_0045bd16                                                 XREF[1]:     0045bb3d(j)  
    //                              Mouseptr.cpp:862 (10)
    //         0045bd16     MOV        dword ptr [ESI + 0xb8],0x0
    //                               LAB_0045bd20                                                 XREF[3]:     0045bced(j), 0045bcf5(j), 
    //                                                                                                         0045bd06(j)  
    //                              Mouseptr.cpp:869 (20)
    //         0045bd20     MOV        EAX,dword ptr [ESI + 0x138]
    //         0045bd26     TEST       EAX,EAX
    //         0045bd28     JZ         LAB_0045bd34
    //         0045bd2a     MOV        EAX,dword ptr [ESI + 0x13c]
    //         0045bd30     TEST       EAX,EAX
    //         0045bd32     JNZ        LAB_0045bd4a
    //                               LAB_0045bd34                                                 XREF[1]:     0045bd28(j)  
    //                              Mouseptr.cpp:871 (22)
    //         0045bd34     MOV        this,dword ptr [ESI + 0x4]
    //         0045bd37     LEA        EAX,[ESI + 0xcc]
    //         0045bd3d     PUSH       0x0
    //         0045bd3f     PUSH       EAX=>DAT_fffffff8
    //         0045bd40     MOV        EDX,dword ptr [ECX + this->render_area]
    //         0045bd43     PUSH       EDX=>DAT_fffffff4
    //         0045bd44     CALL       dword ptr [->USER32.DLL::InvalidateRect]         = 0048af16
    //                               LAB_0045bd4a                                                 XREF[1]:     0045bd32(j)  
    //                              Mouseptr.cpp:874 (6)
    //         0045bd4a     MOV        dword ptr [ESI + 0x12c],EDI
    //                               LAB_0045bd50                                                 XREF[4]:     0045ba77(j), 0045ba80(j), 
    //                                                                                                         0045bac3(j), 0045bad6(j)  
    //                              Mouseptr.cpp:875 (8)
    //         0045bd50     POP        EDI
    //         0045bd51     POP        ESI
    //         0045bd52     POP        EBP
    //         0045bd53     POP        EBX
    //         0045bd54     POP        this
    //         0045bd55     RET        0x4
}

// Offset: 0x0045BD60
void erase(TMousePointer* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TMousePointer::erase(void)                                                    *
    //                              *********************************************************************************************************
    //                              void __thiscall erase(TMousePointer * this)
    //              void              <VOID>         <RETURN>
    //              TMousePointer *   ECX:4 (auto)   this
    //                               ?erase@TMousePointer@@QAEXXZ                                 XREF[2]:     handle_paint:0042157b(c), 
    //                               TMousePointer::erase                                                      off:0045bf06(c)  
    //                              Mouseptr.cpp:882 (4)
    //         0045bd60     PUSH       ESI
    //         0045bd61     MOV        ESI,this
    //         0045bd63     PUSH       EDI
    //                              Mouseptr.cpp:885 (37)
    //         0045bd64     MOV        EAX,dword ptr [ESI + 0x128]
    //         0045bd6a     TEST       EAX,EAX
    //         0045bd6c     JZ         LAB_0045be1d
    //         0045bd72     CMP        dword ptr [ESI],0x0
    //         0045bd75     JZ         LAB_0045be1d
    //         0045bd7b     MOV        EAX,dword ptr [ESI + 0x12c]
    //         0045bd81     TEST       EAX,EAX
    //         0045bd83     JZ         LAB_0045be1d
    //                              Mouseptr.cpp:887 (30)
    //         0045bd89     MOV        EAX,dword ptr [ESI + 0xb8]
    //         0045bd8f     TEST       EAX,EAX
    //         0045bd91     JZ         LAB_0045be1d
    //         0045bd97     MOV        EAX,dword ptr [ESI + 0x11c]
    //         0045bd9d     MOV        this,dword ptr [ESI + 0x124]
    //         0045bda3     CMP        EAX,this
    //         0045bda5     JZ         LAB_0045be1d
    //                              Mouseptr.cpp:889 (34)
    //         0045bda7     PUSH       0x0
    //         0045bda9     LEA        EDX,[ESI + 0xbc]
    //         0045bdaf     MOV        this,dword ptr [EAX]
    //         0045bdb1     PUSH       0x1000000
    //         0045bdb6     PUSH       EDX
    //         0045bdb7     MOV        EDX,dword ptr [ESI + 0x8]
    //         0045bdba     LEA        EDI,[ESI + 0xfc]
    //         0045bdc0     MOV        EDX,dword ptr [EDX + 0x3c]
    //         0045bdc3     PUSH       EDX
    //         0045bdc4     PUSH       EDI
    //         0045bdc5     PUSH       EAX
    //         0045bdc6     CALL       dword ptr [ECX + this->Max_Cursors]
    //                              Mouseptr.cpp:890 (4)
    //         0045bdc9     TEST       EAX,EAX
    //         0045bdcb     JZ         LAB_0045bdd6
    //                              Mouseptr.cpp:892 (6)
    //         0045bdcd     MOV        dword ptr [ESI + 0x148],EAX
    //                              Mouseptr.cpp:912 (3)
    //         0045bdd3     POP        EDI
    //         0045bdd4     POP        ESI
    //         0045bdd5     RET
    //                               LAB_0045bdd6                                                 XREF[1]:     0045bdcb(j)  
    //                              Mouseptr.cpp:899 (20)
    //         0045bdd6     MOV        EAX,dword ptr [ESI + 0x138]
    //         0045bddc     TEST       EAX,EAX
    //         0045bdde     JZ         LAB_0045be03
    //         0045bde0     MOV        EAX,dword ptr [ESI + 0x13c]
    //         0045bde6     TEST       EAX,EAX
    //         0045bde8     JZ         LAB_0045be03
    //                              Mouseptr.cpp:907 (22)
    //         0045bdea     MOV        EAX,dword ptr [ESI + 0x124]
    //         0045bdf0     MOV        dword ptr [ESI + 0xb8],0x1
    //         0045bdfa     MOV        dword ptr [ESI + 0x11c],EAX
    //                              Mouseptr.cpp:912 (3)
    //         0045be00     POP        EDI
    //         0045be01     POP        ESI
    //         0045be02     RET
    //                               LAB_0045be03                                                 XREF[2]:     0045bdde(j), 0045bde8(j)  
    //                              Mouseptr.cpp:901 (16)
    //         0045be03     MOV        this,dword ptr [ESI + 0x4]
    //         0045be06     PUSH       0x0
    //         0045be08     PUSH       EDI=>DAT_fffffff8
    //         0045be09     MOV        EDX,dword ptr [ECX + this->render_area]
    //         0045be0c     PUSH       EDX=>DAT_fffffff4
    //         0045be0d     CALL       dword ptr [->USER32.DLL::InvalidateRect]         = 0048af16
    //                              Mouseptr.cpp:902 (10)
    //         0045be13     MOV        dword ptr [ESI + 0xb8],0x0
    //                               LAB_0045be1d                                                 XREF[5]:     0045bd6c(j), 0045bd75(j), 
    //                                                                                                         0045bd83(j), 0045bd91(j), 
    //                                                                                                         0045bda5(j)  
    //                              Mouseptr.cpp:912 (3)
    //         0045be1d     POP        EDI
    //         0045be1e     POP        ESI
    //         0045be1f     RET
}

// Offset: 0x0045BE20
void set_facet(TMousePointer* this_, int param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TMousePointer::set_facet(int)                                                 *
    //                              *********************************************************************************************************
    //                              void __thiscall set_facet(TMousePointer * this, int param_1)
    //              void              <VOID>         <RETURN>
    //              TMousePointer *   ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0045be20(R)  
    //                               ?set_facet@TMousePointer@@QAEXH@Z                            XREF[3]:     set_mouse_facet:0042056b(c), 
    //                               TMousePointer::set_facet                                                  setup:0045b246(c), 
    //                                                                                                         LoadCursors:0045b450(c)  
    //                              Mouseptr.cpp:918 (13)
    //         0045be20     MOV        EDX,dword ptr [ESP + param_1]
    //         0045be24     TEST       EDX,EDX
    //         0045be26     JL         LAB_0045be78
    //         0045be28     CMP        EDX,dword ptr [ECX + this->Num_Cursors]
    //         0045be2b     JGE        LAB_0045be78
    //                              Mouseptr.cpp:929 (18)
    //         0045be2d     MOV        EAX,dword ptr [ECX + this->Cursor_Shape]
    //         0045be30     MOV        dword ptr [ECX + this->facet],EDX
    //         0045be36     SHL        EDX,0x5
    //         0045be39     MOV        EAX,dword ptr [EAX + 0x1c]
    //         0045be3c     PUSH       ESI
    //         0045be3d     ADD        EAX,EDX
    //                              Mouseptr.cpp:931 (6)
    //         0045be3f     MOV        EDX,dword ptr [EAX + 0x10]
    //         0045be42     MOV        dword ptr [ECX + this->cWidth],EDX
    //                              Mouseptr.cpp:932 (6)
    //         0045be45     MOV        EDX,dword ptr [EAX + 0x14]
    //         0045be48     MOV        dword ptr [ECX + this->cHeight],EDX
    //                              Mouseptr.cpp:934 (9)
    //         0045be4b     MOV        EDX,dword ptr [EAX + 0x1c]
    //         0045be4e     MOV        dword ptr [ECX + this->d_top],EDX
    //                              Mouseptr.cpp:935 (9)
    //         0045be54     MOV        EDX,dword ptr [EAX + 0x18]
    //         0045be57     MOV        dword ptr [ECX + this->d_left],EDX
    //                              Mouseptr.cpp:936 (12)
    //         0045be5d     MOV        EDX,dword ptr [ECX + this->cWidth]
    //         0045be60     SUB        EDX,dword ptr [EAX + 0x18]
    //         0045be63     MOV        dword ptr [ECX + this->d_right],EDX
    //                              Mouseptr.cpp:937 (15)
    //         0045be69     MOV        EDX,dword ptr [ECX + this->cHeight]
    //         0045be6c     MOV        ESI,dword ptr [EAX + 0x1c]
    //         0045be6f     SUB        EDX,ESI
    //         0045be71     POP        ESI
    //         0045be72     MOV        dword ptr [ECX + this->d_bottom],EDX
    //                               LAB_0045be78                                                 XREF[2]:     0045be26(j), 0045be2b(j)  
    //                              Mouseptr.cpp:939 (3)
    //         0045be78     RET        0x4
}

// Offset: 0x0045BE80
void set_game_facet(TMousePointer* this_, int param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TMousePointer::set_game_facet(int)                                            *
    //                              *********************************************************************************************************
    //                              void __thiscall set_game_facet(TMousePointer * this, int param_1)
    //              void              <VOID>         <RETURN>
    //              TMousePointer *   ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0045be80(R)  
    //                               ?set_game_facet@TMousePointer@@QAEXH@Z                       XREF[5]:     setup:0045b24f(c), 
    //                               TMousePointer::set_game_facet                                             LoadCursors:0045b45e(c), 
    //                                                                                                         view_function_terrain:00537a73(c), 
    //                                                                                                         view_function_terrain:00537acf(c), 
    //                                                                                                         view_function_terrain:00537b09(c)  
    //                              Mouseptr.cpp:945 (13)
    //         0045be80     MOV        EDX,dword ptr [ESP + param_1]
    //         0045be84     TEST       EDX,EDX
    //         0045be86     JL         LAB_0045bed8
    //         0045be88     CMP        EDX,dword ptr [ECX + this->Num_Cursors]
    //         0045be8b     JGE        LAB_0045bed8
    //                              Mouseptr.cpp:956 (18)
    //         0045be8d     MOV        EAX,dword ptr [ECX + this->Cursor_Shape]
    //         0045be90     MOV        dword ptr [ECX + this->game_facet],EDX
    //         0045be96     SHL        EDX,0x5
    //         0045be99     MOV        EAX,dword ptr [EAX + 0x1c]
    //         0045be9c     PUSH       ESI
    //         0045be9d     ADD        EAX,EDX
    //                              Mouseptr.cpp:958 (6)
    //         0045be9f     MOV        EDX,dword ptr [EAX + 0x10]
    //         0045bea2     MOV        dword ptr [ECX + this->gWidth],EDX
    //                              Mouseptr.cpp:959 (6)
    //         0045bea5     MOV        EDX,dword ptr [EAX + 0x14]
    //         0045bea8     MOV        dword ptr [ECX + this->gHeight],EDX
    //                              Mouseptr.cpp:961 (9)
    //         0045beab     MOV        EDX,dword ptr [EAX + 0x1c]
    //         0045beae     MOV        dword ptr [ECX + this->g_top],EDX
    //                              Mouseptr.cpp:962 (9)
    //         0045beb4     MOV        EDX,dword ptr [EAX + 0x18]
    //         0045beb7     MOV        dword ptr [ECX + this->g_left],EDX
    //                              Mouseptr.cpp:963 (12)
    //         0045bebd     MOV        EDX,dword ptr [ECX + this->gWidth]
    //         0045bec0     SUB        EDX,dword ptr [EAX + 0x18]
    //         0045bec3     MOV        dword ptr [ECX + this->g_right],EDX
    //                              Mouseptr.cpp:964 (15)
    //         0045bec9     MOV        EDX,dword ptr [ECX + this->gHeight]
    //         0045becc     MOV        ESI,dword ptr [EAX + 0x1c]
    //         0045becf     SUB        EDX,ESI
    //         0045bed1     POP        ESI
    //         0045bed2     MOV        dword ptr [ECX + this->g_bottom],EDX
    //                               LAB_0045bed8                                                 XREF[2]:     0045be86(j), 0045be8b(j)  
    //                              Mouseptr.cpp:966 (3)
    //         0045bed8     RET        0x4
}

// Offset: 0x0045BEE0
void off(TMousePointer* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TMousePointer::off(void)                                                      *
    //                              *********************************************************************************************************
    //                              void __thiscall off(TMousePointer * this)
    //              void              <VOID>         <RETURN>
    //              TMousePointer *   ECX:4 (auto)   this
    //                               ?off@TMousePointer@@QAEXXZ                                   XREF[3]:     mouse_off:00420404(c), 
    //                               TMousePointer::off                                                        set_windows_mouse:0042049d(c), 
    //                                                                                                         set_windows_mouse:004204ac(c)  
    //                              Mouseptr.cpp:976 (3)
    //         0045bee0     PUSH       ESI
    //         0045bee1     MOV        ESI,this
    //                              Mouseptr.cpp:980 (10)
    //         0045bee3     MOV        EAX,dword ptr [ESI + 0x130]
    //         0045bee9     TEST       EAX,EAX
    //         0045beeb     JNZ        LAB_0045bf35
    //                              Mouseptr.cpp:982 (5)
    //         0045beed     CMP        dword ptr [ESI],0x0
    //         0045bef0     JZ         LAB_0045bf1c
    //                              Mouseptr.cpp:984 (10)
    //         0045bef2     MOV        EAX,dword ptr [ESI + 0x12c]
    //         0045bef8     TEST       EAX,EAX
    //         0045befa     JZ         LAB_0045bf1c
    //                              Mouseptr.cpp:986 (10)
    //         0045befc     MOV        EAX,dword ptr [ESI + 0xb8]
    //         0045bf02     TEST       EAX,EAX
    //         0045bf04     JZ         LAB_0045bf1c
    //                              Mouseptr.cpp:988 (5)
    //         0045bf06     CALL       TMousePointer::erase                             void erase(TMousePointer * this)
    //                              Mouseptr.cpp:989 (17)
    //         0045bf0b     MOV        this,dword ptr [ESI + 0x4]
    //         0045bf0e     LEA        EAX,[ESI + 0xfc]
    //         0045bf14     PUSH       EAX
    //         0045bf15     MOV        this,dword ptr [this->custom_draw]
    //         0045bf17     CALL       TDrawSystem::Paint                               void Paint(TDrawSystem * this, tagRECT * para
    //                               LAB_0045bf1c                                                 XREF[3]:     0045bef0(j), 0045befa(j), 
    //                                                                                                         0045bf04(j)  
    //                              Mouseptr.cpp:993 (8)
    //         0045bf1c     PUSH       0x0
    //         0045bf1e     CALL       dword ptr [->USER32.DLL::SetCursor]              = 0048aeda
    //                              Mouseptr.cpp:995 (17)
    //         0045bf24     MOV        this,ESI
    //         0045bf26     MOV        dword ptr [ESI + 0x128],0x0
    //         0045bf30     CALL       TMousePointer::reset                             void reset(TMousePointer * this)
    //                               LAB_0045bf35                                                 XREF[1]:     0045beeb(j)  
    //                              Mouseptr.cpp:996 (2)
    //         0045bf35     POP        ESI
    //         0045bf36     RET
}

// Offset: 0x0045BF40
void on(TMousePointer* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TMousePointer::on(void)                                                       *
    //                              *********************************************************************************************************
    //                              void __thiscall on(TMousePointer * this)
    //              void              <VOID>         <RETURN>
    //              TMousePointer *   ECX:4 (auto)   this
    //                               ?on@TMousePointer@@QAEXXZ                                    XREF[3]:     mouse_on:00420394(c), 
    //                               TMousePointer::on                                                         set_windows_mouse:00420494(c), 
    //                                                                                                         handle_paint:004217d5(c)  
    //                              Mouseptr.cpp:1002 (3)
    //         0045bf40     PUSH       ESI
    //         0045bf41     MOV        ESI,this
    //                              Mouseptr.cpp:1005 (10)
    //         0045bf43     MOV        EAX,dword ptr [ESI + 0x130]
    //         0045bf49     TEST       EAX,EAX
    //         0045bf4b     JNZ        LAB_0045bf70
    //                              Mouseptr.cpp:1008 (5)
    //         0045bf4d     CMP        dword ptr [ESI],0x0
    //         0045bf50     JNZ        LAB_0045bf66
    //                              Mouseptr.cpp:1010 (20)
    //         0045bf52     PUSH       0x7f00
    //         0045bf57     PUSH       0x0
    //         0045bf59     CALL       dword ptr [->USER32.DLL::LoadCursorA]            = 0048acbc
    //         0045bf5f     PUSH       EAX
    //         0045bf60     CALL       dword ptr [->USER32.DLL::SetCursor]              = 0048aeda
    //                               LAB_0045bf66                                                 XREF[1]:     0045bf50(j)  
    //                              Mouseptr.cpp:1013 (10)
    //         0045bf66     MOV        dword ptr [ESI + 0x128],0x1
    //                               LAB_0045bf70                                                 XREF[1]:     0045bf4b(j)  
    //                              Mouseptr.cpp:1014 (2)
    //         0045bf70     POP        ESI
    //         0045bf71     RET
}

// Offset: 0x0045BF80
void reset(TMousePointer* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TMousePointer::reset(void)                                                    *
    //                              *********************************************************************************************************
    //                              void __thiscall reset(TMousePointer * this)
    //              void              <VOID>         <RETURN>
    //              TMousePointer *   ECX:4 (auto)   this
    //                               ?reset@TMousePointer@@QAEXXZ                                 XREF[3]:     Shutdown_Mouse:0045b06e(c), 
    //                               TMousePointer::reset                                                      delete_surfaces:0045b5bf(c), 
    //                                                                                                         off:0045bf30(c)  
    //                              Mouseptr.cpp:1020 (8)
    //         0045bf80     XOR        EAX,EAX
    //         0045bf82     MOV        dword ptr [ECX + this->save_area_valid],EAX
    //                              Mouseptr.cpp:1022 (6)
    //         0045bf88     MOV        dword ptr [ECX + this->drawn],EAX
    //                              Mouseptr.cpp:1023 (1)
    //         0045bf8e     RET
}

// Offset: 0x0045BF90
void center(TMousePointer* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TMousePointer::center(void)                                                   *
    //                              *********************************************************************************************************
    //                              void __thiscall center(TMousePointer * this)
    //              void              <VOID>         <RETURN>
    //              TMousePointer *   ECX:4 (auto)   this
    //              tagRECT           Stack[-0x14]   win_rect                  XREF[0,1]:   0045bfa5(*)  
    //                               ?center@TMousePointer@@QAEXXZ                                XREF[2]:     let_game_begin:00528d4c(c), 
    //                               TMousePointer::center                                                     start_scenario_editor:00528eb3(c)  
    //                              Mouseptr.cpp:1029 (18)
    //         0045bf90     MOV        EAX,dword ptr [ECX + this->render_area]
    //         0045bf93     SUB        ESP,0x10
    //         0045bf96     PUSH       ESI
    //         0045bf97     MOV        ESI,dword ptr [EAX]
    //         0045bf99     CMP        byte ptr [ESI + 0x479],0x1
    //         0045bfa0     JNZ        LAB_0045bfe2
    //                              Mouseptr.cpp:1037 (15)
    //         0045bfa2     MOV        EDX,dword ptr [ESI + 0x4]
    //         0045bfa5     LEA        this=>win_rect.top,[ESP + 0x4]
    //         0045bfa9     PUSH       this
    //         0045bfaa     PUSH       EDX
    //         0045bfab     CALL       dword ptr [->USER32.DLL::GetWindowRect]          = 0048ade6
    //                              Mouseptr.cpp:1038 (15)
    //         0045bfb1     MOV        EAX,dword ptr [ESP + 0xc]
    //         0045bfb5     MOV        ESI,dword ptr [ESP + 0x4]
    //         0045bfb9     SUB        EAX,ESI
    //         0045bfbb     CDQ
    //         0045bfbc     SUB        EAX,EDX
    //         0045bfbe     MOV        this,EAX
    //                              Mouseptr.cpp:1039 (21)
    //         0045bfc0     MOV        EAX,dword ptr [ESP + 0x10]
    //         0045bfc4     SAR        this,0x1
    //         0045bfc6     ADD        this,ESI
    //         0045bfc8     MOV        ESI,dword ptr [ESP + 0x8]
    //         0045bfcc     SUB        EAX,ESI
    //         0045bfce     CDQ
    //         0045bfcf     SUB        EAX,EDX
    //         0045bfd1     SAR        EAX,0x1
    //         0045bfd3     ADD        EAX,ESI
    //                              Mouseptr.cpp:1046 (8)
    //         0045bfd5     PUSH       EAX
    //         0045bfd6     PUSH       this
    //         0045bfd7     CALL       dword ptr [->USER32.DLL::SetCursorPos]           = 0048b01a
    //                              Mouseptr.cpp:1047 (5)
    //         0045bfdd     POP        ESI
    //         0045bfde     ADD        ESP,0x10
    //         0045bfe1     RET
    //                               LAB_0045bfe2                                                 XREF[1]:     0045bfa0(j)  
    //                              Mouseptr.cpp:1043 (8)
    //         0045bfe2     MOV        EAX,dword ptr [ESI + 0x2c]
    //         0045bfe5     CDQ
    //         0045bfe6     SUB        EAX,EDX
    //         0045bfe8     MOV        this,EAX
    //                              Mouseptr.cpp:1044 (10)
    //         0045bfea     MOV        EAX,dword ptr [ESI + 0x30]
    //         0045bfed     CDQ
    //         0045bfee     SUB        EAX,EDX
    //         0045bff0     SAR        EAX,0x1
    //         0045bff2     SAR        this,0x1
    //                              Mouseptr.cpp:1046 (8)
    //         0045bff4     PUSH       EAX
    //         0045bff5     PUSH       this
    //         0045bff6     CALL       dword ptr [->USER32.DLL::SetCursorPos]           = 0048b01a
    //                              Mouseptr.cpp:1047 (5)
    //         0045bffc     POP        ESI
    //         0045bffd     ADD        ESP,0x10
    //         0045c000     RET
}

// Offset: 0x0045C010
void Poll(TMousePointer* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TMousePointer::Poll(void)                                                     *
    //                              *********************************************************************************************************
    //                              void __thiscall Poll(TMousePointer * this)
    //              void              <VOID>         <RETURN>
    //              TMousePointer *   ECX:4 (auto)   this
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     0045c016(W), 0045c098(*)  
    //              IDirectDrawCli    Stack[-0x8]:4  lplpDDClipper
    //                               ?Poll@TMousePointer@@QAEXXZ                                  XREF[11]:    handle_mouse_move:00421150(c), 
    //                               TMousePointer::Poll                                                       update:00463247(c), 
    //                                                                                                         update:0047012d(c), 
    //                                                                                                         update_dopplegangers:0047018d(c), 
    //                                                                                                         update:00512613(c), 
    //                                                                                                         draw:00534daf(c), 
    //                                                                                                         draw:00535135(c), 
    //                                                                                                         view_function_terrain:00536c74(c), 
    //                                                                                                         view_function_terrain:0053751d(c), 
    //                                                                                                         view_function_terrain:0053795b(c), 
    //                                                                                                         update:005430bd(c)  
    //                              Mouseptr.cpp:1052 (6)
    //         0045c010     PUSH       this
    //         0045c011     PUSH       EBX
    //         0045c012     PUSH       ESI
    //         0045c013     MOV        ESI,this
    //         0045c015     PUSH       EDI
    //                              Mouseptr.cpp:1056 (8)
    //         0045c016     MOV        dword ptr [ESP + local_4],0x0
    //                              Mouseptr.cpp:1064 (23)
    //         0045c01e     MOV        EAX,dword ptr [ESI + 0x128]
    //         0045c024     TEST       EAX,EAX
    //         0045c026     JZ         LAB_0045c2f6
    //         0045c02c     CMP        dword ptr [ESI],0x0
    //         0045c02f     JZ         LAB_0045c2f6
    //                              Mouseptr.cpp:1066 (28)
    //         0045c035     MOV        EAX,dword ptr [ESI + 0x138]
    //         0045c03b     TEST       EAX,EAX
    //         0045c03d     JZ         LAB_0045c2f6
    //         0045c043     MOV        EAX,dword ptr [ESI + 0x13c]
    //         0045c049     TEST       EAX,EAX
    //         0045c04b     JZ         LAB_0045c2f6
    //                              Mouseptr.cpp:1070 (15)
    //         0045c051     PUSH       0x42e
    //         0045c056     PUSH       s_C:\msdev\work\age1_x1\Mouseptr.c               = "C:\\msdev\\work\\age1_x1\\Mouseptr.cpp"
    //         0045c05b     CALL       debug_timeGetTime                                ulong debug_timeGetTime(char * param_1, int p
    //                              Mouseptr.cpp:1072 (22)
    //         0045c060     MOV        EDX,dword ptr [ESI + 0x144]
    //         0045c066     MOV        EDI,EAX
    //         0045c068     SUB        EAX,EDX
    //         0045c06a     ADD        ESP,0x8
    //         0045c06d     CMP        EAX,0x22
    //         0045c070     JC         LAB_0045c2f6
    //                              Mouseptr.cpp:1076 (15)
    //         0045c076     MOV        this,ESI
    //         0045c078     CALL       TMousePointer::update_mouse_position             int update_mouse_position(TMousePointer * this)
    //         0045c07d     TEST       EAX,EAX
    //         0045c07f     JZ         LAB_0045c2f6
    //                              Mouseptr.cpp:1082 (13)
    //         0045c085     MOV        EAX,dword ptr [ESI + 0x5c]
    //         0045c088     MOV        dword ptr [ESI + 0x144],EDI
    //         0045c08e     TEST       EAX,EAX
    //         0045c090     JNZ        LAB_0045c0e4
    //                              Mouseptr.cpp:1084 (17)
    //         0045c092     MOV        EAX,dword ptr [ESI + 0x124]
    //         0045c098     LEA        EDX=>local_4,[ESP + 0xc]
    //         0045c09c     PUSH       EDX
    //         0045c09d     PUSH       EAX
    //         0045c09e     MOV        this,dword ptr [EAX]
    //         0045c0a0     CALL       dword ptr [ECX + this+0x3c]
    //                              Mouseptr.cpp:1085 (7)
    //         0045c0a3     CMP        EAX,0x88760238
    //         0045c0a8     JNZ        LAB_0045c0b0
    //                              Mouseptr.cpp:1087 (2)
    //         0045c0aa     XOR        EAX,EAX
    //                              Mouseptr.cpp:1088 (4)
    //         0045c0ac     MOV        dword ptr [ESP + 0xc],EAX
    //                               LAB_0045c0b0                                                 XREF[1]:     0045c0a8(j)  
    //                              Mouseptr.cpp:1091 (4)
    //         0045c0b0     TEST       EAX,EAX
    //         0045c0b2     JZ         LAB_0045c0bf
    //                              Mouseptr.cpp:1093 (6)
    //         0045c0b4     MOV        dword ptr [ESI + 0x148],EAX
    //                              Mouseptr.cpp:1211 (5)
    //         0045c0ba     POP        EDI
    //         0045c0bb     POP        ESI
    //         0045c0bc     POP        EBX
    //         0045c0bd     POP        this
    //         0045c0be     RET
    //                               LAB_0045c0bf                                                 XREF[1]:     0045c0b2(j)  
    //                              Mouseptr.cpp:1099 (8)
    //         0045c0bf     MOV        EAX,dword ptr [ESP + 0xc]
    //         0045c0c3     TEST       EAX,EAX
    //         0045c0c5     JZ         LAB_0045c0e4
    //                              Mouseptr.cpp:1101 (14)
    //         0045c0c7     MOV        EAX,dword ptr [ESI + 0x124]
    //         0045c0cd     PUSH       0x0
    //         0045c0cf     PUSH       EAX=>DAT_fffffff8
    //         0045c0d0     MOV        this,dword ptr [EAX]
    //         0045c0d2     CALL       dword ptr [ECX + this->gWidth]
    //                              Mouseptr.cpp:1103 (4)
    //         0045c0d5     TEST       EAX,EAX
    //         0045c0d7     JZ         LAB_0045c0e4
    //                              Mouseptr.cpp:1105 (6)
    //         0045c0d9     MOV        dword ptr [ESI + 0x148],EAX
    //                              Mouseptr.cpp:1211 (5)
    //         0045c0df     POP        EDI
    //         0045c0e0     POP        ESI
    //         0045c0e1     POP        EBX
    //         0045c0e2     POP        this
    //         0045c0e3     RET
    //                               LAB_0045c0e4                                                 XREF[3]:     0045c090(j), 0045c0c5(j), 
    //                                                                                                         0045c0d7(j)  
    //                              Mouseptr.cpp:1113 (10)
    //         0045c0e4     MOV        EAX,dword ptr [ESI + 0xb8]
    //         0045c0ea     TEST       EAX,EAX
    //         0045c0ec     JZ         LAB_0045c15a
    //                              Mouseptr.cpp:1115 (40)
    //         0045c0ee     MOV        this,dword ptr [ESI + 0x8]
    //         0045c0f1     MOV        EAX,dword ptr [ESI + 0x11c]
    //         0045c0f7     LEA        EDI,[ESI + 0xbc]
    //         0045c0fd     PUSH       0x0
    //         0045c0ff     MOV        this,dword ptr [ECX + this+0x3c]
    //         0045c102     MOV        EDX,dword ptr [EAX]
    //         0045c104     PUSH       offset DAT_fffffff8
    //         0045c109     LEA        EBX,[ESI + 0xfc]
    //         0045c10f     PUSH       EDI=>DAT_fffffff4
    //         0045c110     PUSH       this=>DAT_fffffff0
    //         0045c111     PUSH       EBX
    //         0045c112     PUSH       EAX
    //         0045c113     CALL       dword ptr [EDX + 0x14]
    //                              Mouseptr.cpp:1116 (4)
    //         0045c116     TEST       EAX,EAX
    //         0045c118     JZ         LAB_0045c125
    //                              Mouseptr.cpp:1118 (6)
    //         0045c11a     MOV        dword ptr [ESI + 0x148],EAX
    //                              Mouseptr.cpp:1211 (5)
    //         0045c120     POP        EDI
    //         0045c121     POP        ESI
    //         0045c122     POP        EBX
    //         0045c123     POP        this
    //         0045c124     RET
    //                               LAB_0045c125                                                 XREF[1]:     0045c118(j)  
    //                              Mouseptr.cpp:1122 (16)
    //         0045c125     MOV        EAX,dword ptr [ESI + 0x124]
    //         0045c12b     MOV        this,dword ptr [ESI + 0x11c]
    //         0045c131     CMP        this,EAX
    //         0045c133     JZ         LAB_0045c15a
    //                              Mouseptr.cpp:1124 (22)
    //         0045c135     MOV        this,dword ptr [ESI + 0x8]
    //         0045c138     MOV        EDX,dword ptr [EAX]
    //         0045c13a     PUSH       0x0
    //         0045c13c     PUSH       offset DAT_fffffff8
    //         0045c141     MOV        this,dword ptr [ECX + this+0x3c]
    //         0045c144     PUSH       EDI=>DAT_fffffff4
    //         0045c145     PUSH       this=>DAT_fffffff0
    //         0045c146     PUSH       EBX
    //         0045c147     PUSH       EAX
    //         0045c148     CALL       dword ptr [EDX + 0x14]
    //                              Mouseptr.cpp:1125 (4)
    //         0045c14b     TEST       EAX,EAX
    //         0045c14d     JZ         LAB_0045c15a
    //                              Mouseptr.cpp:1127 (6)
    //         0045c14f     MOV        dword ptr [ESI + 0x148],EAX
    //                              Mouseptr.cpp:1211 (5)
    //         0045c155     POP        EDI
    //         0045c156     POP        ESI
    //         0045c157     POP        EBX
    //         0045c158     POP        this
    //         0045c159     RET
    //                               LAB_0045c15a                                                 XREF[3]:     0045c0ec(j), 0045c133(j), 
    //                                                                                                         0045c14d(j)  
    //                              Mouseptr.cpp:1136 (14)
    //         0045c15a     MOV        EAX,dword ptr [ESI + 0x140]
    //         0045c160     TEST       EAX,EAX
    //         0045c162     JZ         LAB_0045c2b6
    //                              Mouseptr.cpp:1140 (40)
    //         0045c168     MOV        EDX,dword ptr [ESI + 0x8]
    //         0045c16b     LEA        EBX,[ESI + 0xcc]
    //         0045c171     PUSH       0x0
    //         0045c173     PUSH       offset DAT_fffffff8
    //         0045c178     MOV        EAX,dword ptr [EDX + 0x3c]
    //         0045c17b     MOV        EDX,dword ptr [ESI + 0x124]
    //         0045c181     LEA        EDI,[ESI + 0xec]
    //         0045c187     PUSH       EBX=>DAT_fffffff4
    //         0045c188     MOV        this,dword ptr [EAX]
    //         0045c18a     PUSH       EDX=>DAT_fffffff0
    //         0045c18b     PUSH       EDI
    //         0045c18c     PUSH       EAX
    //         0045c18d     CALL       dword ptr [ECX + this->Max_Cursors]
    //                              Mouseptr.cpp:1141 (4)
    //         0045c190     TEST       EAX,EAX
    //         0045c192     JZ         LAB_0045c1ad
    //                              Mouseptr.cpp:1145 (14)
    //         0045c194     PUSH       EAX
    //         0045c195     MOV        this,ESI
    //         0045c197     MOV        dword ptr [ESI + 0x148],EAX
    //         0045c19d     CALL       TMousePointer::GetDDBltError                     int GetDDBltError(TMousePointer * this, long 
    //                              Mouseptr.cpp:1146 (6)
    //         0045c1a2     MOV        dword ptr [ESI + 0x148],EAX
    //                              Mouseptr.cpp:1211 (5)
    //         0045c1a8     POP        EDI
    //         0045c1a9     POP        ESI
    //         0045c1aa     POP        EBX
    //         0045c1ab     POP        this
    //         0045c1ac     RET
    //                               LAB_0045c1ad                                                 XREF[1]:     0045c192(j)  
    //                              Mouseptr.cpp:1152 (6)
    //         0045c1ad     MOV        EAX,dword ptr [ESI + 0x124]
    //                              Mouseptr.cpp:1153 (30)
    //         0045c1b3     MOV        EDX,EBX
    //         0045c1b5     MOV        dword ptr [ESI + 0x11c],EAX
    //         0045c1bb     LEA        this,[ESI + 0xfc]
    //         0045c1c1     MOV        EAX,dword ptr [EDX]
    //         0045c1c3     MOV        dword ptr [this->custom_draw],EAX
    //         0045c1c5     MOV        EAX,dword ptr [EDX + 0x4]
    //         0045c1c8     MOV        dword ptr [ECX + this->render_area],EAX
    //         0045c1cb     MOV        EAX,dword ptr [EDX + 0x8]
    //         0045c1ce     MOV        dword ptr [ECX + this->save_area],EAX
    //                              Mouseptr.cpp:1154 (28)
    //         0045c1d1     LEA        EAX,[ESI + 0xbc]
    //         0045c1d7     MOV        EDX,dword ptr [EDX + 0xc]
    //         0045c1da     MOV        dword ptr [ECX + this->primary_area],EDX
    //         0045c1dd     MOV        this,dword ptr [EDI]
    //         0045c1df     MOV        EDX,dword ptr [EDI + 0x4]
    //         0045c1e2     MOV        dword ptr [EAX],this
    //         0045c1e4     MOV        this,dword ptr [EDI + 0x8]
    //         0045c1e7     MOV        dword ptr [EAX + 0x4],EDX
    //         0045c1ea     MOV        EDX,dword ptr [EDI + 0xc]
    //                              Mouseptr.cpp:1155 (17)
    //         0045c1ed     MOV        EDI,0x1
    //         0045c1f2     MOV        dword ptr [EAX + 0x8],this
    //         0045c1f5     MOV        dword ptr [ESI + 0xb8],EDI
    //         0045c1fb     MOV        dword ptr [EAX + 0xc],EDX
    //                              Mouseptr.cpp:1159 (7)
    //         0045c1fe     MOV        EAX,dword ptr [ESI + 0x5c]
    //         0045c201     TEST       EAX,EAX
    //         0045c203     JNZ        LAB_0045c253
    //                              Mouseptr.cpp:1161 (18)
    //         0045c205     MOV        EAX,dword ptr [ESI + 0x90]
    //         0045c20b     PUSH       0x0
    //         0045c20d     PUSH       EDI=>DAT_fffffff8
    //         0045c20e     MOV        this,dword ptr [ESI + EAX*0x4 + 0x18]
    //         0045c212     CALL       TDrawArea::SetTrans                              void SetTrans(TDrawArea * this, int param_1, 
    //                              Mouseptr.cpp:1163 (45)
    //         0045c217     LEA        EDX,[ESI + 0xdc]
    //         0045c21d     PUSH       0x11
    //         0045c21f     PUSH       EDX=>DAT_fffffff8
    //         0045c220     MOV        EDX,dword ptr [ESI + 0x90]
    //         0045c226     MOV        EAX,dword ptr [ESI + 0x124]
    //         0045c22c     MOV        EDX,dword ptr [ESI + EDX*0x4 + 0x18]
    //         0045c230     MOV        this,dword ptr [EAX]
    //         0045c232     MOV        EDX,dword ptr [EDX + 0x3c]
    //         0045c235     PUSH       EDX=>DAT_fffffff4
    //         0045c236     MOV        EDX,dword ptr [ESI + 0xd0]
    //         0045c23c     PUSH       EDX=>DAT_fffffff0
    //         0045c23d     MOV        EDX,dword ptr [EBX]
    //         0045c23f     PUSH       EDX
    //         0045c240     PUSH       EAX
    //         0045c241     CALL       dword ptr [ECX + this+0x1c]
    //                              Mouseptr.cpp:1165 (4)
    //         0045c244     TEST       EAX,EAX
    //         0045c246     JZ         LAB_0045c253
    //                              Mouseptr.cpp:1167 (6)
    //         0045c248     MOV        dword ptr [ESI + 0x148],EAX
    //                              Mouseptr.cpp:1211 (5)
    //         0045c24e     POP        EDI
    //         0045c24f     POP        ESI
    //         0045c250     POP        EBX
    //         0045c251     POP        this
    //         0045c252     RET
    //                               LAB_0045c253                                                 XREF[2]:     0045c203(j), 0045c246(j)  
    //                              Mouseptr.cpp:1172 (5)
    //         0045c253     CMP        dword ptr [ESI + 0x5c],EDI
    //         0045c256     JNZ        LAB_0045c2a8
    //                              Mouseptr.cpp:1174 (18)
    //         0045c258     MOV        this,dword ptr [ESI + 0xc]
    //         0045c25b     PUSH       EDI
    //         0045c25c     PUSH       s_mouseptr::poll                                 = "mouseptr::poll"
    //         0045c261     CALL       TDrawArea::Lock                                  uchar * Lock(TDrawArea * this, char * param_1
    //         0045c266     TEST       EAX,EAX
    //         0045c268     JZ         LAB_0045c2a8
    //                              Mouseptr.cpp:1176 (11)
    //         0045c26a     MOV        EDX,dword ptr [ESI + 0x90]
    //         0045c270     MOV        this,dword ptr [ESI + 0x58]
    //         0045c273     MOV        EAX,EDX
    //                              Mouseptr.cpp:1178 (38)
    //         0045c275     PUSH       0x0
    //         0045c277     SHL        EAX,0x5
    //         0045c27a     ADD        EAX,dword ptr [ECX + this+0x1c]
    //         0045c27d     PUSH       0x0=>DAT_fffffff8
    //         0045c27f     PUSH       EDX=>DAT_fffffff4
    //         0045c280     MOV        EDX,dword ptr [ESI + 0xd0]
    //         0045c286     ADD        EDX,dword ptr [EAX + 0x1c]
    //         0045c289     MOV        EAX,dword ptr [EAX + 0x18]
    //         0045c28c     PUSH       EDX=>DAT_fffffff0
    //         0045c28d     MOV        EDX,dword ptr [EBX]
    //         0045c28f     ADD        EAX,EDX
    //         0045c291     MOV        EDX,dword ptr [ESI + 0xc]
    //         0045c294     PUSH       EAX
    //         0045c295     PUSH       EDX
    //         0045c296     CALL       TShape::shape_draw                               uchar shape_draw(TShape * this, TDrawArea * p
    //                              Mouseptr.cpp:1180 (13)
    //         0045c29b     MOV        this,dword ptr [ESI + 0xc]
    //         0045c29e     PUSH       s_mouseptr::poll                                 = "mouseptr::poll"
    //         0045c2a3     CALL       TDrawArea::Unlock                                void Unlock(TDrawArea * this, char * param_1)
    //                               LAB_0045c2a8                                                 XREF[2]:     0045c256(j), 0045c268(j)  
    //                              Mouseptr.cpp:1184 (12)
    //         0045c2a8     MOV        EAX,dword ptr [ESI + 0x90]
    //         0045c2ae     MOV        dword ptr [ESI + 0x94],EAX
    //                              Mouseptr.cpp:1189 (2)
    //         0045c2b4     JMP        LAB_0045c2c5
    //                               LAB_0045c2b6                                                 XREF[1]:     0045c162(j)  
    //                              Mouseptr.cpp:1191 (15)
    //         0045c2b6     MOV        dword ptr [ESI + 0xb8],0x0
    //         0045c2c0     MOV        EDI,0x1
    //                               LAB_0045c2c5                                                 XREF[1]:     0045c2b4(j)  
    //                              Mouseptr.cpp:1194 (7)
    //         0045c2c5     MOV        EAX,dword ptr [ESI + 0x5c]
    //         0045c2c8     TEST       EAX,EAX
    //         0045c2ca     JNZ        LAB_0045c2f0
    //                              Mouseptr.cpp:1196 (8)
    //         0045c2cc     MOV        this,dword ptr [ESP + 0xc]
    //         0045c2d0     TEST       this,this
    //         0045c2d2     JZ         LAB_0045c2f0
    //                              Mouseptr.cpp:1198 (13)
    //         0045c2d4     MOV        EAX,dword ptr [ESI + 0x124]
    //         0045c2da     PUSH       this
    //         0045c2db     PUSH       EAX=>DAT_fffffff8
    //         0045c2dc     MOV        EDX,dword ptr [EAX]
    //         0045c2de     CALL       dword ptr [EDX + 0x70]
    //                              Mouseptr.cpp:1199 (4)
    //         0045c2e1     TEST       EAX,EAX
    //         0045c2e3     JZ         LAB_0045c2f0
    //                              Mouseptr.cpp:1201 (6)
    //         0045c2e5     MOV        dword ptr [ESI + 0x148],EAX
    //                              Mouseptr.cpp:1211 (5)
    //         0045c2eb     POP        EDI
    //         0045c2ec     POP        ESI
    //         0045c2ed     POP        EBX
    //         0045c2ee     POP        this
    //         0045c2ef     RET
    //                               LAB_0045c2f0                                                 XREF[3]:     0045c2ca(j), 0045c2d2(j), 
    //                                                                                                         0045c2e3(j)  
    //                              Mouseptr.cpp:1209 (6)
    //         0045c2f0     MOV        dword ptr [ESI + 0x12c],EDI
    //                               LAB_0045c2f6                                                 XREF[6]:     0045c026(j), 0045c02f(j), 
    //                                                                                                         0045c03d(j), 0045c04b(j), 
    //                                                                                                         0045c070(j), 0045c07f(j)  
    //                              Mouseptr.cpp:1211 (5)
    //         0045c2f6     POP        EDI
    //         0045c2f7     POP        ESI
    //         0045c2f8     POP        EBX
    //         0045c2f9     POP        this
    //         0045c2fa     RET
}

// Offset: 0x0045C300
int GetDDBltError(TMousePointer* this_, long param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall TMousePointer::GetDDBltError(long)                                             *
    //                              *********************************************************************************************************
    //                              int __thiscall GetDDBltError(TMousePointer * this, long param_1)
    //              int               EAX:4          <RETURN>
    //              TMousePointer *   ECX:4 (auto)   this
    //              long              Stack[0x4]:4   param_1                   XREF[1]:     0045c300(R)  
    //                               ?GetDDBltError@TMousePointer@@QAEHJ@Z                        XREF[1]:     Poll:0045c19d(c)  
    //                               TMousePointer::GetDDBltError
    //                              Mouseptr.cpp:1215 (24)
    //         0045c300     MOV        EAX,dword ptr [ESP + param_1]
    //         0045c304     CMP        EAX,0x80004005
    //         0045c309     JG         LAB_0045c328
    //         0045c30b     JZ         LAB_0045c320
    //         0045c30d     CMP        EAX,0x80004001
    //         0045c312     JNZ        LAB_0045c42a
    //                              Mouseptr.cpp:1235 (5)
    //         0045c318     MOV        EAX,0x11
    //                              Mouseptr.cpp:1242 (3)
    //         0045c31d     RET        0x4
    //                               LAB_0045c320                                                 XREF[1]:     0045c30b(j)  
    //                              Mouseptr.cpp:1219 (5)
    //         0045c320     MOV        EAX,0x1
    //                              Mouseptr.cpp:1242 (3)
    //         0045c325     RET        0x4
    //                               LAB_0045c328                                                 XREF[1]:     0045c309(j)  
    //                              Mouseptr.cpp:1217 (20)
    //         0045c328     CMP        EAX,0x88760037
    //         0045c32d     JG         LAB_0045c34c
    //         0045c32f     JZ         LAB_0045c344
    //         0045c331     CMP        EAX,0x80070057
    //         0045c336     JNZ        LAB_0045c42a
    //                              Mouseptr.cpp:1222 (5)
    //         0045c33c     MOV        EAX,0x4
    //                              Mouseptr.cpp:1242 (3)
    //         0045c341     RET        0x4
    //                               LAB_0045c344                                                 XREF[1]:     0045c32f(j)  
    //                              Mouseptr.cpp:1236 (5)
    //         0045c344     MOV        EAX,0x12
    //                              Mouseptr.cpp:1242 (3)
    //         0045c349     RET        0x4
    //                               LAB_0045c34c                                                 XREF[1]:     0045c32d(j)  
    //                              Mouseptr.cpp:1217 (20)
    //         0045c34c     CMP        EAX,0x88760082
    //         0045c351     JG         LAB_0045c370
    //         0045c353     JZ         LAB_0045c368
    //         0045c355     CMP        EAX,0x8876006e
    //         0045c35a     JNZ        LAB_0045c42a
    //                              Mouseptr.cpp:1220 (5)
    //         0045c360     MOV        EAX,0x2
    //                              Mouseptr.cpp:1242 (3)
    //         0045c365     RET        0x4
    //                               LAB_0045c368                                                 XREF[1]:     0045c353(j)  
    //                              Mouseptr.cpp:1221 (5)
    //         0045c368     MOV        EAX,0x3
    //                              Mouseptr.cpp:1242 (3)
    //         0045c36d     RET        0x4
    //                               LAB_0045c370                                                 XREF[1]:     0045c351(j)  
    //                              Mouseptr.cpp:1217 (20)
    //         0045c370     CMP        EAX,0x887600b4
    //         0045c375     JG         LAB_0045c394
    //         0045c377     JZ         LAB_0045c38c
    //         0045c379     CMP        EAX,0x88760096
    //         0045c37e     JNZ        LAB_0045c42a
    //                              Mouseptr.cpp:1223 (5)
    //         0045c384     MOV        EAX,0x5
    //                              Mouseptr.cpp:1242 (3)
    //         0045c389     RET        0x4
    //                               LAB_0045c38c                                                 XREF[1]:     0045c377(j)  
    //                              Mouseptr.cpp:1224 (5)
    //         0045c38c     MOV        EAX,0x6
    //                              Mouseptr.cpp:1242 (3)
    //         0045c391     RET        0x4
    //                               LAB_0045c394                                                 XREF[1]:     0045c375(j)  
    //                              Mouseptr.cpp:1217 (20)
    //         0045c394     CMP        EAX,0x887600fa
    //         0045c399     JG         LAB_0045c3b8
    //         0045c39b     JZ         LAB_0045c3b0
    //         0045c39d     CMP        EAX,0x887600cd
    //         0045c3a2     JNZ        LAB_0045c42a
    //                              Mouseptr.cpp:1226 (5)
    //         0045c3a8     MOV        EAX,0x8
    //                              Mouseptr.cpp:1242 (3)
    //         0045c3ad     RET        0x4
    //                               LAB_0045c3b0                                                 XREF[1]:     0045c39b(j)  
    //                              Mouseptr.cpp:1228 (5)
    //         0045c3b0     MOV        EAX,0xa
    //                              Mouseptr.cpp:1242 (3)
    //         0045c3b5     RET        0x4
    //                               LAB_0045c3b8                                                 XREF[1]:     0045c399(j)  
    //                              Mouseptr.cpp:1217 (16)
    //         0045c3b8     CMP        EAX,0x88760122
    //         0045c3bd     JG         LAB_0045c3d8
    //         0045c3bf     JZ         LAB_0045c3d0
    //         0045c3c1     CMP        EAX,0x88760118
    //         0045c3c6     JNZ        LAB_0045c42a
    //                              Mouseptr.cpp:1229 (5)
    //         0045c3c8     MOV        EAX,0xb
    //                              Mouseptr.cpp:1242 (3)
    //         0045c3cd     RET        0x4
    //                               LAB_0045c3d0                                                 XREF[1]:     0045c3bf(j)  
    //                              Mouseptr.cpp:1230 (5)
    //         0045c3d0     MOV        EAX,0xc
    //                              Mouseptr.cpp:1242 (3)
    //         0045c3d5     RET        0x4
    //                               LAB_0045c3d8                                                 XREF[1]:     0045c3bd(j)  
    //                              Mouseptr.cpp:1217 (16)
    //         0045c3d8     CMP        EAX,0x88760154
    //         0045c3dd     JG         LAB_0045c3f8
    //         0045c3df     JZ         LAB_0045c3f0
    //         0045c3e1     CMP        EAX,0x88760136
    //         0045c3e6     JNZ        LAB_0045c42a
    //                              Mouseptr.cpp:1231 (5)
    //         0045c3e8     MOV        EAX,0xd
    //                              Mouseptr.cpp:1242 (3)
    //         0045c3ed     RET        0x4
    //                               LAB_0045c3f0                                                 XREF[1]:     0045c3df(j)  
    //                              Mouseptr.cpp:1232 (5)
    //         0045c3f0     MOV        EAX,0xe
    //                              Mouseptr.cpp:1242 (3)
    //         0045c3f5     RET        0x4
    //                               LAB_0045c3f8                                                 XREF[1]:     0045c3dd(j)  
    //                              Mouseptr.cpp:1217 (16)
    //         0045c3f8     CMP        EAX,0x887601c2
    //         0045c3fd     JG         LAB_0045c418
    //         0045c3ff     JZ         LAB_0045c410
    //         0045c401     CMP        EAX,0x887601ae
    //         0045c406     JNZ        LAB_0045c42a
    //                              Mouseptr.cpp:1233 (5)
    //         0045c408     MOV        EAX,0xf
    //                              Mouseptr.cpp:1242 (3)
    //         0045c40d     RET        0x4
    //                               LAB_0045c410                                                 XREF[1]:     0045c3ff(j)  
    //                              Mouseptr.cpp:1234 (5)
    //         0045c410     MOV        EAX,0x10
    //                              Mouseptr.cpp:1242 (3)
    //         0045c415     RET        0x4
    //                               LAB_0045c418                                                 XREF[1]:     0045c3fd(j)  
    //                              Mouseptr.cpp:1217 (18)
    //         0045c418     CMP        EAX,0x8876023f
    //         0045c41d     JZ         LAB_0045c43d
    //         0045c41f     CMP        EAX,0x88760240
    //         0045c424     JZ         LAB_0045c435
    //         0045c426     TEST       EAX,EAX
    //         0045c428     JZ         LAB_0045c430
    //                               LAB_0045c42a                                                 XREF[8]:     0045c312(j), 0045c336(j), 
    //                                                                                                         0045c35a(j), 0045c37e(j), 
    //                                                                                                         0045c3a2(j), 0045c3c6(j), 
    //                                                                                                         0045c3e6(j), 0045c406(j)  
    //                              Mouseptr.cpp:1240 (3)
    //         0045c42a     OR         EAX,0xffffffff
    //                              Mouseptr.cpp:1242 (3)
    //         0045c42d     RET        0x4
    //                               LAB_0045c430                                                 XREF[1]:     0045c428(j)  
    //                              Mouseptr.cpp:1237 (2)
    //         0045c430     XOR        EAX,EAX
    //                              Mouseptr.cpp:1242 (3)
    //         0045c432     RET        0x4
    //                               LAB_0045c435                                                 XREF[1]:     0045c424(j)  
    //                              Mouseptr.cpp:1227 (5)
    //         0045c435     MOV        EAX,0x9
    //                              Mouseptr.cpp:1242 (3)
    //         0045c43a     RET        0x4
    //                               LAB_0045c43d                                                 XREF[1]:     0045c41d(j)  
    //                              Mouseptr.cpp:1225 (5)
    //         0045c43d     MOV        EAX,0x7
    //                              Mouseptr.cpp:1242 (3)
    //         0045c442     RET        0x4
}

