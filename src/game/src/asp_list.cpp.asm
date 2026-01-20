// Auto-generated scaffold unit: asp_list.cpp.asm
// SourceMap: C:/msdev/work/age1_x1/asp_list.cpp
#include "../include/common.h"

// Offset: 0x0041A640
undefined RGE_Active_Sprite_List(RGE_Active_Sprite_List* this_, RGE_Static_Object* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall RGE_Active_Sprite_List::RGE_Active_Sprite_List(class RGE_Static_Object *)          *
    //                              *********************************************************************************************************
    //                              undefined __thiscall RGE_Active_Sprite_List(RGE_Active_Sprite_List *
    //              undefined         <UNASSIGNED>   <RETURN>
    //              RGE_Active_Spr    ECX:4 (auto)   this
    //              RGE_Static_Obj    Stack[0x4]:4   param_1                   XREF[1]:     0041a642(R)  
    //                               ??0RGE_Active_Sprite_List@@QAE@PAVRGE_Static_Object@@@Z      XREF[1]:     create_sprite_list:004c1df6(c)  
    //                               RGE_Active_Sprite_List::RGE_Active_Sprite_List
    //                              asp_list.cpp:23 (2)
    //         0041a640     MOV        EAX,this
    //                              asp_list.cpp:25 (20)
    //         0041a642     MOV        this,dword ptr [ESP + param_1]
    //         0041a646     MOV        dword ptr [EAX],RGE_Active_Sprite_List::`vftab   = 0041a660
    //         0041a64c     MOV        dword ptr [EAX + 0x4],0x0
    //         0041a653     MOV        dword ptr [EAX + 0x8],this
    //                              asp_list.cpp:27 (3)
    //         0041a656     RET        0x4
}

// Offset: 0x0041A680
void RGE_Active_Sprite_List(RGE_Active_Sprite_List* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual __thiscall RGE_Active_Sprite_List::~RGE_Active_Sprite_List(void)                      *
    //                              *********************************************************************************************************
    //                              void __thiscall ~RGE_Active_Sprite_List(RGE_Active_Sprite_List * this)
    //              void              <VOID>         <RETURN>
    //              RGE_Active_Spr    ECX:4 (auto)   this
    //                               ??1RGE_Active_Sprite_List@@UAE@XZ                            XREF[1]:     `vector_deleting_destructor':0041a
    //                               RGE_Active_Sprite_List::~RGE_Active_Sprite_List
    //                              asp_list.cpp:31 (6)
    //         0041a680     MOV        dword ptr [this->_padding_],RGE_Active_Sprite_   = 0041a660
    //                              asp_list.cpp:32 (5)
    //         0041a686     JMP        RGE_Active_Sprite_List::delete_list              void delete_list(RGE_Active_Sprite_List * this)
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
}

// Offset: 0x0041A690
void load(RGE_Active_Sprite_List* this_, int param_2, RGE_Sprite** param_3) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall RGE_Active_Sprite_List::load(int,class RGE_Sprite * *)                        *
    //                              *********************************************************************************************************
    //                              void __thiscall load(RGE_Active_Sprite_List * this, int param_1, RGE
    //              void              <VOID>         <RETURN>
    //              RGE_Active_Spr    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0041a69a(R)  
    //              RGE_Sprite * *    Stack[0x8]:4   param_2                   XREF[3]:     0041a692(R), 0041a6a3(*), 0041a6b0(R)  
    //                               ?load@RGE_Active_Sprite_List@@QAEXHPAPAVRGE_Sprite@@@Z       XREF[1]:     setup:004c1c83(c)  
    //                               RGE_Active_Sprite_List::load
    //                              asp_list.cpp:37 (2)
    //         0041a690     PUSH       EBX
    //         0041a691     PUSH       EBP
    //                              asp_list.cpp:46 (48)
    //         0041a692     MOV        EBX,dword ptr [ESP + param_2]
    //         0041a696     PUSH       ESI
    //         0041a697     MOV        ESI,this
    //         0041a699     PUSH       EDI
    //         0041a69a     MOV        EDI,dword ptr [ESP + param_1]
    //         0041a69e     MOV        EAX,dword ptr [ESI]
    //         0041a6a0     MOV        EBP,dword ptr [EAX + 0x2c]
    //                               LAB_0041a6a3                                                 XREF[1]:     0041a6c0(j)  
    //         0041a6a3     LEA        this=>param_2,[ESP + 0x18]
    //         0041a6a7     PUSH       0x1
    //         0041a6a9     PUSH       this=>DAT_fffffff8
    //         0041a6aa     PUSH       EDI=>DAT_fffffff4
    //         0041a6ab     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0041a6b0     MOV        EDX,dword ptr [ESP + param_2]
    //         0041a6b4     ADD        ESP,0xc
    //         0041a6b7     MOV        this,ESI
    //         0041a6b9     PUSH       EBX
    //         0041a6ba     PUSH       EDX
    //         0041a6bb     PUSH       EDI
    //         0041a6bc     CALL       EBP
    //         0041a6be     TEST       AL,AL
    //         0041a6c0     JNZ        LAB_0041a6a3
    //                              asp_list.cpp:51 (9)
    //         0041a6c2     MOV        EAX,dword ptr [ESI + 0x4]
    //         0041a6c5     XOR        this,this
    //         0041a6c7     TEST       EAX,EAX
    //         0041a6c9     JZ         LAB_0041a6e1
    //                               LAB_0041a6cb                                                 XREF[1]:     0041a6df(j)  
    //                              asp_list.cpp:53 (3)
    //         0041a6cb     MOV        EAX,dword ptr [ESI + 0x4]
    //                              asp_list.cpp:54 (9)
    //         0041a6ce     MOV        EDX,dword ptr [ESI + 0x4]
    //         0041a6d1     MOV        EAX,dword ptr [EAX + 0x8]
    //         0041a6d4     MOV        dword ptr [EDX + 0x8],this
    //                              asp_list.cpp:55 (3)
    //         0041a6d7     MOV        this,dword ptr [ESI + 0x4]
    //                              asp_list.cpp:56 (7)
    //         0041a6da     MOV        dword ptr [ESI + 0x4],EAX
    //         0041a6dd     TEST       EAX,EAX
    //         0041a6df     JNZ        LAB_0041a6cb
    //                               LAB_0041a6e1                                                 XREF[1]:     0041a6c9(j)  
    //                              asp_list.cpp:59 (3)
    //         0041a6e1     MOV        dword ptr [ESI + 0x4],this
    //                              asp_list.cpp:60 (7)
    //         0041a6e4     POP        EDI
    //         0041a6e5     POP        ESI
    //         0041a6e6     POP        EBP
    //         0041a6e7     POP        EBX
    //         0041a6e8     RET        0x8
}

// Offset: 0x0041A6F0
uchar RGE_Active_Sprite_List::load_node(int param_1, uchar param_2, RGE_Sprite** param_3) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * protected: virtual unsigned char __thiscall RGE_Active_Sprite_List::load_node(int,unsigned char,cl... *
    //                              *********************************************************************************************************
    //                              uchar __thiscall load_node(RGE_Active_Sprite_List * this, int param_
    //              uchar             AL:1           <RETURN>
    //              RGE_Active_Spr    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[2]:     0041a755(R), 0041a7ae(R)  
    //              uchar             Stack[0x8]:1   param_2                   XREF[3]:     0041a6fe(R), 0041a73d(W), 0041a79a(W)  
    //              RGE_Sprite * *    Stack[0xc]:4   param_3                   XREF[2]:     0041a751(R), 0041a7aa(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     0041a743(W), 0041a7a0(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[4]:     0041a770(R), 0041a7c9(R), 0041a7eb(R), 0041a7fd(R)  
    //                               ?load_node@RGE_Active_Sprite_List@@MAEEHEPAPAVRGE_Sprite@@@Z XREF[1]:     0056ee34(*)  
    //                               RGE_Active_Sprite_List::load_node
    //                              asp_list.cpp:64 (14)
    //         0041a6f0     MOV        EAX,FS:[0x0]
    //         0041a6f6     PUSH       -0x1
    //         0041a6f8     PUSH       FUN_0055c976
    //         0041a6fd     PUSH       EAX
    //                              asp_list.cpp:67 (39)
    //         0041a6fe     MOV        EAX,dword ptr [ESP + param_2]
    //         0041a702     MOV        dword ptr FS:[0x0],ESP
    //         0041a709     AND        EAX,0xff
    //         0041a70e     PUSH       EDI
    //         0041a70f     SUB        EAX,0x0
    //         0041a712     MOV        EDI,this
    //         0041a714     JZ         LAB_0041a7fd
    //         0041a71a     DEC        EAX
    //         0041a71b     PUSH       ESI
    //         0041a71c     JZ         LAB_0041a782
    //         0041a71e     DEC        EAX
    //         0041a71f     JNZ        LAB_0041a7e8
    //                              asp_list.cpp:76 (14)
    //         0041a725     PUSH       0x1
    //         0041a727     PUSH       0xc
    //         0041a729     CALL       calloc                                           undefined calloc()
    //         0041a72e     ADD        ESP,0x8
    //         0041a731     MOV        ESI,EAX
    //                              asp_list.cpp:77 (58)
    //         0041a733     PUSH       0x28
    //         0041a735     CALL       operator_new                                     void * operator_new(uint param_1)
    //         0041a73a     ADD        ESP,0x4
    //         0041a73d     MOV        dword ptr [ESP + param_2],EAX
    //         0041a741     TEST       EAX,EAX
    //         0041a743     MOV        dword ptr [ESP + local_4],0x1
    //         0041a74b     JZ         LAB_0041a7db
    //         0041a751     MOV        this,dword ptr [ESP + param_3]
    //         0041a755     MOV        EDX,dword ptr [ESP + param_1]
    //         0041a759     PUSH       this
    //         0041a75a     PUSH       EDX
    //         0041a75b     MOV        this,EAX
    //         0041a75d     CALL       RGE_Active_Animated_Sprite::RGE_Active_Animate   undefined RGE_Active_Animated_Sprite(RGE_Acti
    //         0041a762     MOV        dword ptr [ESI],EAX
    //         0041a764     MOV        EAX,dword ptr [EDI + 0x4]
    //         0041a767     MOV        dword ptr [ESI + 0x8],EAX
    //         0041a76a     MOV        dword ptr [EDI + 0x4],ESI
    //                              asp_list.cpp:89 (3)
    //         0041a76d     MOV        AL,0x1
    //         0041a76f     POP        ESI
    //                              asp_list.cpp:90 (18)
    //         0041a770     MOV        this,dword ptr [ESP + local_c]
    //         0041a774     MOV        dword ptr FS:[0x0],this
    //         0041a77b     POP        EDI
    //         0041a77c     ADD        ESP,0xc
    //         0041a77f     RET        0xc
    //                               LAB_0041a782                                                 XREF[1]:     0041a71c(j)  
    //                              asp_list.cpp:70 (14)
    //         0041a782     PUSH       0x1
    //         0041a784     PUSH       0xc
    //         0041a786     CALL       calloc                                           undefined calloc()
    //         0041a78b     ADD        ESP,0x8
    //         0041a78e     MOV        ESI,EAX
    //                              asp_list.cpp:71 (45)
    //         0041a790     PUSH       0x14
    //         0041a792     CALL       operator_new                                     void * operator_new(uint param_1)
    //         0041a797     ADD        ESP,0x4
    //         0041a79a     MOV        dword ptr [ESP + param_2],EAX
    //         0041a79e     TEST       EAX,EAX
    //         0041a7a0     MOV        dword ptr [ESP + local_4],0x0
    //         0041a7a8     JZ         LAB_0041a7db
    //         0041a7aa     MOV        this,dword ptr [ESP + param_3]
    //         0041a7ae     MOV        EDX,dword ptr [ESP + param_1]
    //         0041a7b2     PUSH       this
    //         0041a7b3     PUSH       EDX
    //         0041a7b4     MOV        this,EAX
    //         0041a7b6     CALL       RGE_Active_Sprite::RGE_Active_Sprite             undefined RGE_Active_Sprite(RGE_Active_Sprite
    //         0041a7bb     MOV        dword ptr [ESI],EAX
    //                              asp_list.cpp:72 (6)
    //         0041a7bd     MOV        EAX,dword ptr [EDI + 0x4]
    //         0041a7c0     MOV        dword ptr [ESI + 0x8],EAX
    //                              asp_list.cpp:73 (3)
    //         0041a7c3     MOV        dword ptr [EDI + 0x4],ESI
    //                              asp_list.cpp:89 (3)
    //         0041a7c6     MOV        AL,0x1
    //         0041a7c8     POP        ESI
    //                              asp_list.cpp:90 (18)
    //         0041a7c9     MOV        this,dword ptr [ESP + local_c]
    //         0041a7cd     MOV        dword ptr FS:[0x0],this
    //         0041a7d4     POP        EDI
    //         0041a7d5     ADD        ESP,0xc
    //         0041a7d8     RET        0xc
    //                               LAB_0041a7db                                                 XREF[2]:     0041a74b(j), 0041a7a8(j)  
    //                              asp_list.cpp:71 (4)
    //         0041a7db     XOR        EAX,EAX
    //         0041a7dd     MOV        dword ptr [ESI],EAX
    //                              asp_list.cpp:72 (6)
    //         0041a7df     MOV        EAX,dword ptr [EDI + 0x4]
    //         0041a7e2     MOV        dword ptr [ESI + 0x8],EAX
    //                              asp_list.cpp:73 (3)
    //         0041a7e5     MOV        dword ptr [EDI + 0x4],ESI
    //                               LAB_0041a7e8                                                 XREF[1]:     0041a71f(j)  
    //                              asp_list.cpp:89 (2)
    //         0041a7e8     MOV        AL,0x1
    //                              asp_list.cpp:64 (1)
    //         0041a7ea     POP        ESI
    //                              asp_list.cpp:90 (38)
    //         0041a7eb     MOV        this,dword ptr [ESP + local_c]
    //         0041a7ef     MOV        dword ptr FS:[0x0],this
    //         0041a7f6     POP        EDI
    //         0041a7f7     ADD        ESP,0xc
    //         0041a7fa     RET        0xc
    //                               LAB_0041a7fd                                                 XREF[1]:     0041a714(j)  
    //         0041a7fd     MOV        this,dword ptr [ESP + local_c]
    //         0041a801     XOR        AL,AL
    //         0041a803     MOV        dword ptr FS:[0x0],this
    //         0041a80a     POP        EDI
    //         0041a80b     ADD        ESP,0xc
    //         0041a80e     RET        0xc
}

// Offset: 0x0041A820
void save(RGE_Active_Sprite_List* this_, int param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall RGE_Active_Sprite_List::save(int)                                             *
    //                              *********************************************************************************************************
    //                              void __thiscall save(RGE_Active_Sprite_List * this, int param_1)
    //              void              <VOID>         <RETURN>
    //              RGE_Active_Spr    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0041a826(R)  
    //              undefined1        Stack[-0x1]:1  local_1                   XREF[2]:     0041a82c(W), 0041a842(*)  
    //              uchar             Stack[-0x5]:1  ender
    //                               ?save@RGE_Active_Sprite_List@@QAEXH@Z                        XREF[1]:     save:004c4670(c)  
    //                               RGE_Active_Sprite_List::save
    //                              asp_list.cpp:94 (2)
    //         0041a820     PUSH       this
    //         0041a821     PUSH       ESI
    //                              asp_list.cpp:98 (17)
    //         0041a822     MOV        ESI,dword ptr [ECX + this->list]
    //         0041a825     PUSH       EDI
    //         0041a826     MOV        EDI,dword ptr [ESP + param_1]
    //         0041a82a     TEST       ESI,ESI
    //         0041a82c     MOV        byte ptr [ESP + local_1],0x0
    //         0041a831     JZ         LAB_0041a842
    //                               LAB_0041a833                                                 XREF[1]:     0041a840(j)  
    //                              asp_list.cpp:99 (15)
    //         0041a833     MOV        this,dword ptr [ESI]
    //         0041a835     PUSH       EDI
    //         0041a836     MOV        EAX,dword ptr [this->_padding_]
    //         0041a838     CALL       dword ptr [EAX + 0x8]
    //         0041a83b     MOV        ESI,dword ptr [ESI + 0x8]
    //         0041a83e     TEST       ESI,ESI
    //         0041a840     JNZ        LAB_0041a833
    //                               LAB_0041a842                                                 XREF[1]:     0041a831(j)  
    //                              asp_list.cpp:101 (16)
    //         0041a842     LEA        this=>local_1,[ESP + 0xb]
    //         0041a846     PUSH       0x1
    //         0041a848     PUSH       this=>DAT_fffffff8
    //         0041a849     PUSH       EDI=>DAT_fffffff4
    //         0041a84a     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         0041a84f     ADD        ESP,0xc
    //                              asp_list.cpp:102 (6)
    //         0041a852     POP        EDI
    //         0041a853     POP        ESI
    //         0041a854     POP        this
    //         0041a855     RET        0x4
}

// Offset: 0x0041A860
void delete_list(RGE_Active_Sprite_List* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall RGE_Active_Sprite_List::delete_list(void)                                     *
    //                              *********************************************************************************************************
    //                              void __thiscall delete_list(RGE_Active_Sprite_List * this)
    //              void              <VOID>         <RETURN>
    //              RGE_Active_Spr    ECX:4 (auto)   this
    //                               ?delete_list@RGE_Active_Sprite_List@@QAEXXZ                  XREF[3]:     ~RGE_Active_Sprite_List:0041a686(c
    //                               RGE_Active_Sprite_List::delete_list                                       use_sprite_list:0041a8f3(c), 
    //                                                                                                         recycle_out_of_game:004c15e4(c)  
    //                              asp_list.cpp:106 (4)
    //         0041a860     PUSH       EBX
    //         0041a861     MOV        EBX,this
    //         0041a863     PUSH       ESI
    //                              asp_list.cpp:107 (3)
    //         0041a864     MOV        ESI,dword ptr [EBX + 0x4]
    //                              asp_list.cpp:110 (4)
    //         0041a867     TEST       ESI,ESI
    //         0041a869     JZ         LAB_0041a8a2
    //                              asp_list.cpp:106 (1)
    //         0041a86b     PUSH       EDI
    //                               LAB_0041a86c                                                 XREF[1]:     0041a89f(j)  
    //                              asp_list.cpp:114 (14)
    //         0041a86c     MOV        this,dword ptr [ESI]
    //         0041a86e     MOV        EDI,dword ptr [ESI + 0x8]
    //         0041a871     CALL       RGE_Active_Sprite::check_for_shadows             int check_for_shadows(RGE_Active_Sprite * this)
    //         0041a876     TEST       EAX,EAX
    //         0041a878     JZ         LAB_0041a886
    //                              asp_list.cpp:115 (7)
    //         0041a87a     MOV        this,dword ptr [EBX + 0x8]
    //         0041a87d     TEST       this,this
    //         0041a87f     JZ         LAB_0041a886
    //                              asp_list.cpp:116 (5)
    //         0041a881     CALL       RGE_Static_Object::remove_shadows                void remove_shadows(RGE_Static_Object * this)
    //                               LAB_0041a886                                                 XREF[2]:     0041a878(j), 0041a87f(j)  
    //                              asp_list.cpp:118 (12)
    //         0041a886     MOV        this,dword ptr [ESI]
    //         0041a888     TEST       this,this
    //         0041a88a     JZ         LAB_0041a892
    //         0041a88c     MOV        EAX,dword ptr [this->_padding_]
    //         0041a88e     PUSH       0x1
    //         0041a890     CALL       dword ptr [EAX]
    //                               LAB_0041a892                                                 XREF[1]:     0041a88a(j)  
    //                              asp_list.cpp:119 (9)
    //         0041a892     PUSH       ESI
    //         0041a893     CALL       free                                             undefined free()
    //         0041a898     ADD        ESP,0x4
    //                              asp_list.cpp:120 (6)
    //         0041a89b     MOV        ESI,EDI
    //         0041a89d     TEST       EDI,EDI
    //         0041a89f     JNZ        LAB_0041a86c
    //                              asp_list.cpp:106 (1)
    //         0041a8a1     POP        EDI
    //                               LAB_0041a8a2                                                 XREF[1]:     0041a869(j)  
    //                              asp_list.cpp:123 (7)
    //         0041a8a2     MOV        dword ptr [EBX + 0x4],0x0
    //                              asp_list.cpp:124 (3)
    //         0041a8a9     POP        ESI
    //         0041a8aa     POP        EBX
    //         0041a8ab     RET
}

// Offset: 0x0041A8B0
RGE_Active_Sprite_Node* copy_sprite_list(RGE_Active_Sprite_List* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: struct RGE_Active_Sprite_Node * __thiscall RGE_Active_Sprite_List::copy_sprite_list(void)     *
    //                              *********************************************************************************************************
    //                              RGE_Active_Sprite_Node * __thiscall copy_sprite_list(RGE_Active_Spri
    //              RGE_Active_Spr    EAX:4          <RETURN>
    //              RGE_Active_Spr    ECX:4 (auto)   this
    //                               ?copy_sprite_list@RGE_Active_Sprite_List@@QAEPAURGE_Active_  XREF[2]:     RGE_Doppleganger_Object:00441987(c
    //                               RGE_Active_Sprite_List::copy_sprite_list                                  recycle_in_to_game:00441c55(c)  
    //                              asp_list.cpp:128 (5)
    //         0041a8b0     PUSH       EBX
    //         0041a8b1     PUSH       ESI
    //         0041a8b2     PUSH       EDI
    //         0041a8b3     MOV        EDI,this
    //                              asp_list.cpp:133 (3)
    //         0041a8b5     MOV        EBX,dword ptr [EDI + 0x4]
    //                              asp_list.cpp:134 (7)
    //         0041a8b8     MOV        dword ptr [EDI + 0x4],0x0
    //                              asp_list.cpp:136 (6)
    //         0041a8bf     TEST       EBX,EBX
    //         0041a8c1     MOV        ESI,EBX
    //         0041a8c3     JZ         LAB_0041a8e5
    //                               LAB_0041a8c5                                                 XREF[1]:     0041a8e3(j)  
    //                              asp_list.cpp:137 (32)
    //         0041a8c5     MOV        EAX,dword ptr [ESI]
    //         0041a8c7     MOV        this,dword ptr [EAX + 0x10]
    //         0041a8ca     MOV        EDX,dword ptr [EAX + 0xc]
    //         0041a8cd     PUSH       this
    //         0041a8ce     MOV        this,byte ptr [ESI + 0x4]
    //         0041a8d1     PUSH       EDX
    //         0041a8d2     MOV        EDX,dword ptr [EAX + 0x4]
    //         0041a8d5     PUSH       this
    //         0041a8d6     PUSH       EDX
    //         0041a8d7     MOV        this,EDI
    //         0041a8d9     CALL       RGE_Active_Sprite_List::add_sprite               void add_sprite(RGE_Active_Sprite_List * this
    //         0041a8de     MOV        ESI,dword ptr [ESI + 0x8]
    //         0041a8e1     TEST       ESI,ESI
    //         0041a8e3     JNZ        LAB_0041a8c5
    //                               LAB_0041a8e5                                                 XREF[1]:     0041a8c3(j)  
    //                              asp_list.cpp:139 (3)
    //         0041a8e5     MOV        EAX,dword ptr [EDI + 0x4]
    //                              asp_list.cpp:140 (3)
    //         0041a8e8     MOV        dword ptr [EDI + 0x4],EBX
    //                              asp_list.cpp:143 (4)
    //         0041a8eb     POP        EDI
    //         0041a8ec     POP        ESI
    //         0041a8ed     POP        EBX
    //         0041a8ee     RET
}

// Offset: 0x0041A8F0
void use_sprite_list(RGE_Active_Sprite_List* this_, RGE_Active_Sprite_Node* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall RGE_Active_Sprite_List::use_sprite_list(struct RGE_Active_Sprite_Node *)      *
    //                              *********************************************************************************************************
    //                              void __thiscall use_sprite_list(RGE_Active_Sprite_List * this, RGE_A
    //              void              <VOID>         <RETURN>
    //              RGE_Active_Spr    ECX:4 (auto)   this
    //              RGE_Active_Spr    Stack[0x4]:4   param_1                   XREF[1]:     0041a8f8(R)  
    //                               ?use_sprite_list@RGE_Active_Sprite_List@@QAEXPAURGE_Active_  XREF[2]:     RGE_Doppleganger_Object:00441990(c
    //                               RGE_Active_Sprite_List::use_sprite_list                                   recycle_in_to_game:00441c5e(c)  
    //                              asp_list.cpp:147 (3)
    //         0041a8f0     PUSH       ESI
    //         0041a8f1     MOV        ESI,this
    //                              asp_list.cpp:148 (5)
    //         0041a8f3     CALL       RGE_Active_Sprite_List::delete_list              void delete_list(RGE_Active_Sprite_List * this)
    //                              asp_list.cpp:149 (7)
    //         0041a8f8     MOV        EAX,dword ptr [ESP + param_1]
    //         0041a8fc     MOV        dword ptr [ESI + 0x4],EAX
    //                              asp_list.cpp:150 (4)
    //         0041a8ff     POP        ESI
    //         0041a900     RET        0x4
}

// Offset: 0x0041A910
void add_sprite(RGE_Active_Sprite_List* this_, RGE_Sprite* param_2, uchar param_3, long param_4, long param_5) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall RGE_Active_Sprite_List::add_sprite(class RGE_Sprite *,unsigned char,long,l... *
    //                              *********************************************************************************************************
    //                              void __thiscall add_sprite(RGE_Active_Sprite_List * this, RGE_Sprite
    //              void              <VOID>         <RETURN>
    //              RGE_Active_Spr    ECX:4 (auto)   this
    //              RGE_Sprite *      Stack[0x4]:4   param_1                   XREF[1]:     0041a912(R)  
    //              uchar             Stack[0x8]:1   param_2                   XREF[1]:     0041a94f(R)  
    //              long              Stack[0xc]:4   param_3                   XREF[1]:     0041a982(R)  
    //              long              Stack[0x10]:4  param_4                   XREF[1]:     0041a97b(R)  
    //                               ?add_sprite@RGE_Active_Sprite_List@@QAEXPAVRGE_Sprite@@EJJ@Z XREF[4]:     copy_sprite_list:0041a8d9(c), 
    //                               RGE_Active_Sprite_List::add_sprite                                        check_damage_sprites:004c4152(c), 
    //                                                                                                         new_sprite:004c4c10(c), 
    //                                                                                                         add_overlay_sprite:004c4c31(c)  
    //                              asp_list.cpp:154 (2)
    //         0041a910     PUSH       EBX
    //         0041a911     PUSH       EBP
    //                              asp_list.cpp:159 (12)
    //         0041a912     MOV        EBP,dword ptr [ESP + param_1]
    //         0041a916     PUSH       ESI
    //         0041a917     TEST       EBP,EBP
    //         0041a919     PUSH       EDI
    //         0041a91a     MOV        ESI,this
    //         0041a91c     JZ         LAB_0041a998
    //                              asp_list.cpp:162 (11)
    //         0041a91e     MOV        this,EBP
    //         0041a920     CALL       RGE_Sprite::check_for_shadows                    int check_for_shadows(RGE_Sprite * this)
    //         0041a925     TEST       EAX,EAX
    //         0041a927     JZ         LAB_0041a935
    //                              asp_list.cpp:164 (7)
    //         0041a929     MOV        this,dword ptr [ESI + 0x8]
    //         0041a92c     TEST       this,this
    //         0041a92e     JZ         LAB_0041a935
    //                              asp_list.cpp:165 (5)
    //         0041a930     CALL       RGE_Static_Object::remove_shadows                void remove_shadows(RGE_Static_Object * this)
    //                               LAB_0041a935                                                 XREF[2]:     0041a927(j), 0041a92e(j)  
    //                              asp_list.cpp:168 (12)
    //         0041a935     MOV        this,dword ptr [ESI + 0x4]
    //         0041a938     LEA        EDI,[ESI + 0x4]
    //         0041a93b     MOV        EAX,this
    //         0041a93d     TEST       EAX,EAX
    //         0041a93f     JZ         LAB_0041a94f
    //                               LAB_0041a941                                                 XREF[1]:     0041a94d(j)  
    //                              asp_list.cpp:169 (14)
    //         0041a941     MOV        EDX,dword ptr [EAX]
    //         0041a943     CMP        dword ptr [EDX + 0x4],EBP
    //         0041a946     JZ         LAB_0041a99f
    //         0041a948     MOV        EAX,dword ptr [EAX + 0x8]
    //         0041a94b     TEST       EAX,EAX
    //         0041a94d     JNZ        LAB_0041a941
    //                               LAB_0041a94f                                                 XREF[1]:     0041a93f(j)  
    //                              asp_list.cpp:176 (6)
    //         0041a94f     MOV        BL,byte ptr [ESP + param_2]
    //         0041a953     MOV        EAX,this
    //                               LAB_0041a955                                                 XREF[1]:     0041a964(j)  
    //                              asp_list.cpp:179 (9)
    //         0041a955     TEST       EAX,EAX
    //         0041a957     JZ         LAB_0041a966
    //         0041a959     CMP        byte ptr [EAX + 0x4],BL
    //         0041a95c     JA         LAB_0041a966
    //                              asp_list.cpp:193 (3)
    //         0041a95e     LEA        EDI,[EAX + 0x8]
    //                              asp_list.cpp:194 (5)
    //         0041a961     MOV        EAX,dword ptr [EAX + 0x8]
    //         0041a964     JMP        LAB_0041a955
    //                               LAB_0041a966                                                 XREF[2]:     0041a957(j), 0041a95c(j)  
    //                              asp_list.cpp:181 (12)
    //         0041a966     PUSH       0x1
    //         0041a968     PUSH       0xc
    //         0041a96a     CALL       calloc                                           undefined calloc()
    //         0041a96f     ADD        ESP,0x8
    //                              asp_list.cpp:182 (9)
    //         0041a972     MOV        this,EBP
    //         0041a974     MOV        ESI,EAX
    //         0041a976     CALL       RGE_Sprite::make_active_sprite                   RGE_Active_Sprite * make_active_sprite(RGE_Sp
    //                              asp_list.cpp:183 (19)
    //         0041a97b     MOV        this,dword ptr [ESP + param_4]
    //         0041a97f     MOV        EDX,dword ptr [EAX]
    //         0041a981     PUSH       this
    //         0041a982     MOV        this,dword ptr [ESP + param_3]
    //         0041a986     PUSH       this
    //         0041a987     MOV        this,EAX
    //         0041a989     MOV        dword ptr [ESI],EAX
    //         0041a98b     CALL       dword ptr [EDX + 0x4]
    //                              asp_list.cpp:184 (3)
    //         0041a98e     MOV        byte ptr [ESI + 0x4],BL
    //                              asp_list.cpp:185 (5)
    //         0041a991     MOV        EDX,dword ptr [EDI]
    //         0041a993     MOV        dword ptr [ESI + 0x8],EDX
    //                              asp_list.cpp:186 (2)
    //         0041a996     MOV        dword ptr [EDI],ESI
    //                               LAB_0041a998                                                 XREF[1]:     0041a91c(j)  
    //                              asp_list.cpp:200 (7)
    //         0041a998     POP        EDI
    //         0041a999     POP        ESI
    //         0041a99a     POP        EBP
    //         0041a99b     POP        EBX
    //         0041a99c     RET        0x10
    //                               LAB_0041a99f                                                 XREF[1]:     0041a946(j)  
    //                              asp_list.cpp:171 (3)
    //         0041a99f     MOV        this,byte ptr [EAX + 0x5]
    //                              asp_list.cpp:200 (12)
    //         0041a9a2     POP        EDI
    //         0041a9a3     INC        this
    //         0041a9a5     POP        ESI
    //         0041a9a6     POP        EBP
    //         0041a9a7     MOV        byte ptr [EAX + 0x5],this
    //         0041a9aa     POP        EBX
    //         0041a9ab     RET        0x10
}

// Offset: 0x0041A9B0
void remove_sprite(RGE_Active_Sprite_List* this_, RGE_Sprite* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall RGE_Active_Sprite_List::remove_sprite(class RGE_Sprite *)                     *
    //                              *********************************************************************************************************
    //                              void __thiscall remove_sprite(RGE_Active_Sprite_List * this, RGE_Spr
    //              void              <VOID>         <RETURN>
    //              RGE_Active_Spr    ECX:4 (auto)   this
    //              RGE_Sprite *      Stack[0x4]:4   param_1                   XREF[1]:     0041a9be(R)  
    //                               ?remove_sprite@RGE_Active_Sprite_List@@QAEXPAVRGE_Sprite@@@Z XREF[3]:     check_damage_sprites:004c41ad(c), 
    //                               RGE_Active_Sprite_List::remove_sprite                                     new_sprite:004c4bfe(c), 
    //                                                                                                         remove_overlay_sprite:004c4c48(c)  
    //                              asp_list.cpp:204 (4)
    //         0041a9b0     PUSH       ESI
    //         0041a9b1     PUSH       EDI
    //         0041a9b2     MOV        EDI,this
    //                              asp_list.cpp:205 (6)
    //         0041a9b4     MOV        ESI,dword ptr [EDI + 0x4]
    //         0041a9b7     LEA        EAX,[EDI + 0x4]
    //                              asp_list.cpp:208 (8)
    //         0041a9ba     TEST       ESI,ESI
    //         0041a9bc     JZ         LAB_0041aa1a
    //         0041a9be     MOV        this,dword ptr [ESP + param_1]
    //                               LAB_0041a9c2                                                 XREF[1]:     0041a9d1(j)  
    //                              asp_list.cpp:210 (7)
    //         0041a9c2     MOV        EDX,dword ptr [ESI]
    //         0041a9c4     CMP        dword ptr [EDX + 0x4],this
    //         0041a9c7     JZ         LAB_0041a9d8
    //                              asp_list.cpp:233 (3)
    //         0041a9c9     LEA        EAX,[ESI + 0x8]
    //                              asp_list.cpp:234 (7)
    //         0041a9cc     MOV        ESI,dword ptr [ESI + 0x8]
    //         0041a9cf     TEST       ESI,ESI
    //         0041a9d1     JNZ        LAB_0041a9c2
    //                              asp_list.cpp:237 (5)
    //         0041a9d3     POP        EDI
    //         0041a9d4     POP        ESI
    //         0041a9d5     RET        0x4
    //                               LAB_0041a9d8                                                 XREF[1]:     0041a9c7(j)  
    //                              asp_list.cpp:212 (7)
    //         0041a9d8     MOV        this,byte ptr [ESI + 0x5]
    //         0041a9db     TEST       this,this
    //         0041a9dd     JBE        LAB_0041a9e9
    //                              asp_list.cpp:213 (5)
    //         0041a9df     DEC        this
    //         0041a9e1     MOV        byte ptr [ESI + 0x5],this
    //                              asp_list.cpp:237 (5)
    //         0041a9e4     POP        EDI
    //         0041a9e5     POP        ESI
    //         0041a9e6     RET        0x4
    //                               LAB_0041a9e9                                                 XREF[1]:     0041a9dd(j)  
    //                              asp_list.cpp:216 (5)
    //         0041a9e9     MOV        this,dword ptr [ESI + 0x8]
    //         0041a9ec     MOV        dword ptr [EAX],this
    //                              asp_list.cpp:220 (11)
    //         0041a9ee     MOV        this,dword ptr [ESI]
    //         0041a9f0     CALL       RGE_Active_Sprite::check_for_shadows             int check_for_shadows(RGE_Active_Sprite * this)
    //         0041a9f5     TEST       EAX,EAX
    //         0041a9f7     JZ         LAB_0041aa05
    //                              asp_list.cpp:222 (7)
    //         0041a9f9     MOV        this,dword ptr [EDI + 0x8]
    //         0041a9fc     TEST       this,this
    //         0041a9fe     JZ         LAB_0041aa05
    //                              asp_list.cpp:223 (5)
    //         0041aa00     CALL       RGE_Static_Object::remove_shadows                void remove_shadows(RGE_Static_Object * this)
    //                               LAB_0041aa05                                                 XREF[2]:     0041a9f7(j), 0041a9fe(j)  
    //                              asp_list.cpp:226 (12)
    //         0041aa05     MOV        this,dword ptr [ESI]
    //         0041aa07     TEST       this,this
    //         0041aa09     JZ         LAB_0041aa11
    //         0041aa0b     MOV        EDX,dword ptr [this->_padding_]
    //         0041aa0d     PUSH       0x1
    //         0041aa0f     CALL       dword ptr [EDX]
    //                               LAB_0041aa11                                                 XREF[1]:     0041aa09(j)  
    //                              asp_list.cpp:227 (9)
    //         0041aa11     PUSH       ESI
    //         0041aa12     CALL       free                                             undefined free()
    //         0041aa17     ADD        ESP,0x4
    //                               LAB_0041aa1a                                                 XREF[1]:     0041a9bc(j)  
    //                              asp_list.cpp:237 (5)
    //         0041aa1a     POP        EDI
    //         0041aa1b     POP        ESI
    //         0041aa1c     RET        0x4
}

// Offset: 0x0041AA20
void RGE_Active_Sprite_List::update(float param_1, float param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void __thiscall RGE_Active_Sprite_List::update(float,float)                           *
    //                              *********************************************************************************************************
    //                              void __thiscall update(RGE_Active_Sprite_List * this, float param_1,
    //              void              <VOID>         <RETURN>
    //              RGE_Active_Spr    ECX:4 (auto)   this
    //              float             Stack[0x4]:4   param_1                   XREF[1]:     0041aa2e(R)  
    //              float             Stack[0x8]:4   param_2                   XREF[1]:     0041aa29(R)  
    //                               ?update@RGE_Active_Sprite_List@@UAEXMM@Z                     XREF[1]:     0056ee10(*)  
    //                               RGE_Active_Sprite_List::update
    //                              asp_list.cpp:241 (1)
    //         0041aa20     PUSH       ESI
    //                              asp_list.cpp:244 (17)
    //         0041aa21     MOV        ESI,dword ptr [ECX + this->list]
    //         0041aa24     TEST       ESI,ESI
    //         0041aa26     JZ         LAB_0041aa44
    //         0041aa28     PUSH       EDI
    //         0041aa29     MOV        EDI,dword ptr [ESP + param_2]
    //         0041aa2d     PUSH       EBX
    //         0041aa2e     MOV        EBX,dword ptr [ESP + param_1]
    //                               LAB_0041aa32                                                 XREF[1]:     0041aa40(j)  
    //                              asp_list.cpp:245 (18)
    //         0041aa32     MOV        this,dword ptr [ESI]
    //         0041aa34     PUSH       EDI
    //         0041aa35     PUSH       EBX=>DAT_fffffff8
    //         0041aa36     MOV        EAX,dword ptr [this->_padding_]
    //         0041aa38     CALL       dword ptr [EAX + 0xc]
    //         0041aa3b     MOV        ESI,dword ptr [ESI + 0x8]
    //         0041aa3e     TEST       ESI,ESI
    //         0041aa40     JNZ        LAB_0041aa32
    //         0041aa42     POP        EBX
    //         0041aa43     POP        EDI
    //                               LAB_0041aa44                                                 XREF[1]:     0041aa26(j)  
    //                              asp_list.cpp:246 (4)
    //         0041aa44     POP        ESI
    //         0041aa45     RET        0x8
}

// Offset: 0x0041AA50
void RGE_Active_Sprite_List::draw(short param_1, short param_2, short param_3, short param_4, short param_5, RGE_Color_Table* param_6, TDrawArea* param_7) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void __thiscall RGE_Active_Sprite_List::draw(short,short,short,short,short,class R... *
    //                              *********************************************************************************************************
    //                              void __thiscall draw(RGE_Active_Sprite_List * this, short param_1, s
    //              void              <VOID>         <RETURN>
    //              RGE_Active_Spr    ECX:4 (auto)   this
    //              short             Stack[0x4]:2   param_1                   XREF[1]:     0041aa81(R)  
    //              short             Stack[0x8]:2   param_2                   XREF[1]:     0041aa78(R)  
    //              short             Stack[0xc]:2   param_3                   XREF[1]:     0041aa5f(R)  
    //              short             Stack[0x10]:2  param_4                   XREF[1]:     0041aa65(R)  
    //              short             Stack[0x14]:2  param_5                   XREF[1]:     0041aa5a(R)  
    //              RGE_Color_Tabl    Stack[0x18]:4  param_6                   XREF[1]:     0041aa71(R)  
    //              TDrawArea *       Stack[0x1c]:4  param_7                   XREF[1]:     0041aa6a(R)  
    //                               ?draw@RGE_Active_Sprite_List@@UAEXFFFFFPAVRGE_Color_Table@@  XREF[1]:     0056ee14(*)  
    //                               RGE_Active_Sprite_List::draw
    //                              asp_list.cpp:250 (1)
    //         0041aa50     PUSH       ESI
    //                              asp_list.cpp:253 (9)
    //         0041aa51     MOV        ESI,dword ptr [ECX + this->list]
    //         0041aa54     TEST       ESI,ESI
    //         0041aa56     JZ         LAB_0041aa93
    //         0041aa58     PUSH       EDI
    //         0041aa59     PUSH       EBP
    //                              asp_list.cpp:254 (57)
    //         0041aa5a     MOVSX      EDI,word ptr [ESP + param_5]
    //         0041aa5f     MOVSX      EBP,word ptr [ESP + param_3]
    //         0041aa64     PUSH       EBX
    //         0041aa65     MOVSX      EBX,word ptr [ESP + param_4]
    //                               LAB_0041aa6a                                                 XREF[1]:     0041aa8e(j)  
    //         0041aa6a     MOV        EAX,dword ptr [ESP + param_7]
    //         0041aa6e     MOV        this,dword ptr [ESI]
    //         0041aa70     PUSH       EAX
    //         0041aa71     MOV        EAX,dword ptr [ESP + param_6]
    //         0041aa75     MOV        EDX,dword ptr [this->_padding_]
    //         0041aa77     PUSH       EAX=>DAT_fffffff8
    //         0041aa78     MOVSX      EAX,word ptr [ESP + param_2]
    //         0041aa7d     PUSH       EDI=>DAT_fffffff4
    //         0041aa7e     PUSH       EBX=>DAT_fffffff0
    //         0041aa7f     PUSH       EBP
    //         0041aa80     PUSH       EAX
    //         0041aa81     MOV        EAX,dword ptr [ESP + param_1]
    //         0041aa85     PUSH       EAX
    //         0041aa86     CALL       dword ptr [EDX + 0x10]
    //         0041aa89     MOV        ESI,dword ptr [ESI + 0x8]
    //         0041aa8c     TEST       ESI,ESI
    //         0041aa8e     JNZ        LAB_0041aa6a
    //         0041aa90     POP        EBX
    //         0041aa91     POP        EBP
    //         0041aa92     POP        EDI
    //                               LAB_0041aa93                                                 XREF[1]:     0041aa56(j)  
    //                              asp_list.cpp:255 (4)
    //         0041aa93     POP        ESI
    //         0041aa94     RET        0x1c
}

// Offset: 0x0041AAA0
void RGE_Active_Sprite_List::normal_draw(short param_1, short param_2, short param_3, RGE_Color_Table* param_4, TDrawArea* param_5) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void __thiscall RGE_Active_Sprite_List::normal_draw(short,short,short,class RGE_Co... *
    //                              *********************************************************************************************************
    //                              void __thiscall normal_draw(RGE_Active_Sprite_List * this, short par
    //              void              <VOID>         <RETURN>
    //              RGE_Active_Spr    ECX:4 (auto)   this
    //              short             Stack[0x4]:2   param_1                   XREF[1]:     0041aac1(R)  
    //              short             Stack[0x8]:2   param_2                   XREF[1]:     0041aab4(R)  
    //              short             Stack[0xc]:2   param_3                   XREF[1]:     0041aaaa(R)  
    //              RGE_Color_Tabl    Stack[0x10]:4  param_4                   XREF[1]:     0041aab9(R)  
    //              TDrawArea *       Stack[0x14]:4  param_5                   XREF[1]:     0041aaaf(R)  
    //                               ?normal_draw@RGE_Active_Sprite_List@@UAEXFFFPAVRGE_Color_Ta  XREF[1]:     0056ee18(*)  
    //                               RGE_Active_Sprite_List::normal_draw
    //                              asp_list.cpp:259 (1)
    //         0041aaa0     PUSH       ESI
    //                              asp_list.cpp:262 (9)
    //         0041aaa1     MOV        ESI,dword ptr [ECX + this->list]
    //         0041aaa4     TEST       ESI,ESI
    //         0041aaa6     JZ         LAB_0041aad7
    //         0041aaa8     PUSH       EDI
    //         0041aaa9     PUSH       EBP
    //                              asp_list.cpp:263 (45)
    //         0041aaaa     MOVSX      EDI,word ptr [ESP + param_3]
    //         0041aaaf     MOV        EBP,dword ptr [ESP + param_5]
    //         0041aab3     PUSH       EBX
    //         0041aab4     MOVSX      EBX,word ptr [ESP + param_2]
    //                               LAB_0041aab9                                                 XREF[1]:     0041aad2(j)  
    //         0041aab9     MOV        EDX,dword ptr [ESP + param_4]
    //         0041aabd     MOV        this,dword ptr [ESI]
    //         0041aabf     PUSH       EBP
    //         0041aac0     PUSH       EDX=>DAT_fffffff8
    //         0041aac1     MOV        EDX,dword ptr [ESP + param_1]
    //         0041aac5     MOV        EAX,dword ptr [this->_padding_]
    //         0041aac7     PUSH       EDI=>DAT_fffffff4
    //         0041aac8     PUSH       EBX=>DAT_fffffff0
    //         0041aac9     PUSH       EDX
    //         0041aaca     CALL       dword ptr [EAX + 0x14]
    //         0041aacd     MOV        ESI,dword ptr [ESI + 0x8]
    //         0041aad0     TEST       ESI,ESI
    //         0041aad2     JNZ        LAB_0041aab9
    //         0041aad4     POP        EBX
    //         0041aad5     POP        EBP
    //         0041aad6     POP        EDI
    //                               LAB_0041aad7                                                 XREF[1]:     0041aaa6(j)  
    //                              asp_list.cpp:264 (4)
    //         0041aad7     POP        ESI
    //         0041aad8     RET        0x14
}

// Offset: 0x0041AAE0
void RGE_Active_Sprite_List::shadow_draw(short param_1, short param_2, short param_3, RGE_Color_Table* param_4, TDrawArea* param_5, uchar param_6) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void __thiscall RGE_Active_Sprite_List::shadow_draw(short,short,short,class RGE_Co... *
    //                              *********************************************************************************************************
    //                              void __thiscall shadow_draw(RGE_Active_Sprite_List * this, short par
    //              void              <VOID>         <RETURN>
    //              RGE_Active_Spr    ECX:4 (auto)   this
    //              short             Stack[0x4]:2   param_1                   XREF[1]:     0041aaee(R)  
    //              short             Stack[0x8]:2   param_2                   XREF[1]:     0041ab08(R)  
    //              short             Stack[0xc]:2   param_3                   XREF[1]:     0041aaff(R)  
    //              RGE_Color_Tabl    Stack[0x10]:4  param_4                   XREF[1]:     0041aaf3(R)  
    //              TDrawArea *       Stack[0x14]:4  param_5                   XREF[1]:     0041aae9(R)  
    //              uchar             Stack[0x18]:1  param_6                   XREF[1]:     0041aaf7(R)  
    //                               ?shadow_draw@RGE_Active_Sprite_List@@UAEXFFFPAVRGE_Color_Ta  XREF[1]:     0056ee1c(*)  
    //                               RGE_Active_Sprite_List::shadow_draw
    //                              asp_list.cpp:268 (1)
    //         0041aae0     PUSH       ESI
    //                              asp_list.cpp:271 (8)
    //         0041aae1     MOV        ESI,dword ptr [ECX + this->list]
    //         0041aae4     TEST       ESI,ESI
    //         0041aae6     JZ         LAB_0041ab1c
    //         0041aae8     PUSH       EDI
    //                              asp_list.cpp:272 (51)
    //         0041aae9     MOV        EDI,dword ptr [ESP + param_5]
    //         0041aaed     PUSH       EBP
    //         0041aaee     MOV        EBP,dword ptr [ESP + param_1]
    //         0041aaf2     PUSH       EBX
    //         0041aaf3     MOV        EBX,dword ptr [ESP + param_4]
    //                               LAB_0041aaf7                                                 XREF[1]:     0041ab17(j)  
    //         0041aaf7     MOV        EAX,dword ptr [ESP + param_6]
    //         0041aafb     MOV        this,dword ptr [ESI]
    //         0041aafd     PUSH       EAX
    //         0041aafe     PUSH       EDI=>DAT_fffffff8
    //         0041aaff     MOVSX      EAX,word ptr [ESP + param_3]
    //         0041ab04     MOV        EDX,dword ptr [this->_padding_]
    //         0041ab06     PUSH       EBX=>DAT_fffffff4
    //         0041ab07     PUSH       EAX=>DAT_fffffff0
    //         0041ab08     MOVSX      EAX,word ptr [ESP + param_2]
    //         0041ab0d     PUSH       EAX
    //         0041ab0e     PUSH       EBP
    //         0041ab0f     CALL       dword ptr [EDX + 0x18]
    //         0041ab12     MOV        ESI,dword ptr [ESI + 0x8]
    //         0041ab15     TEST       ESI,ESI
    //         0041ab17     JNZ        LAB_0041aaf7
    //         0041ab19     POP        EBX
    //         0041ab1a     POP        EBP
    //         0041ab1b     POP        EDI
    //                               LAB_0041ab1c                                                 XREF[1]:     0041aae6(j)  
    //                              asp_list.cpp:273 (4)
    //         0041ab1c     POP        ESI
    //         0041ab1d     RET        0x18
}

// Offset: 0x0041AB20
short RGE_Active_Sprite_List::frame(RGE_Sprite* param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual short __thiscall RGE_Active_Sprite_List::frame(class RGE_Sprite *)                    *
    //                              *********************************************************************************************************
    //                              short __thiscall frame(RGE_Active_Sprite_List * this, RGE_Sprite * p
    //              short             AX:2           <RETURN>
    //              RGE_Active_Spr    ECX:4 (auto)   this
    //              RGE_Sprite *      Stack[0x4]:4   param_1                   XREF[1]:     0041ab27(R)  
    //                               ?frame@RGE_Active_Sprite_List@@UAEFPAVRGE_Sprite@@@Z         XREF[1]:     0056ee0c(*)  
    //                               RGE_Active_Sprite_List::frame
    //                              asp_list.cpp:277 (11)
    //         0041ab20     MOV        EAX,dword ptr [ECX + this->list]
    //         0041ab23     TEST       EAX,EAX
    //         0041ab25     JZ         LAB_0041ab4b
    //         0041ab27     MOV        this,dword ptr [ESP + param_1]
    //                               LAB_0041ab2b                                                 XREF[1]:     0041ab37(j)  
    //                              asp_list.cpp:281 (14)
    //         0041ab2b     MOV        EDX,dword ptr [EAX]
    //         0041ab2d     CMP        dword ptr [EDX + 0x4],this
    //         0041ab30     JZ         LAB_0041ab3f
    //         0041ab32     MOV        EAX,dword ptr [EAX + 0x8]
    //         0041ab35     TEST       EAX,EAX
    //         0041ab37     JNZ        LAB_0041ab2b
    //                              asp_list.cpp:284 (3)
    //         0041ab39     XOR        AX,AX
    //                              asp_list.cpp:285 (3)
    //         0041ab3c     RET        0x4
    //                               LAB_0041ab3f                                                 XREF[1]:     0041ab30(j)  
    //                              asp_list.cpp:282 (9)
    //         0041ab3f     MOV        EAX,dword ptr [EAX]
    //         0041ab41     MOV        this,EAX
    //         0041ab43     MOV        EDX,dword ptr [EAX]
    //         0041ab45     CALL       dword ptr [EDX + 0x1c]
    //                              asp_list.cpp:285 (3)
    //         0041ab48     RET        0x4
    //                               LAB_0041ab4b                                                 XREF[1]:     0041ab25(j)  
    //                              asp_list.cpp:284 (3)
    //         0041ab4b     XOR        AX,AX
    //                              asp_list.cpp:285 (3)
    //         0041ab4e     RET        0x4
}

// Offset: 0x0041AB60
uchar RGE_Active_Sprite_List::is_animating(RGE_Sprite* param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual unsigned char __thiscall RGE_Active_Sprite_List::is_animating(class RGE_Sprite *)     *
    //                              *********************************************************************************************************
    //                              uchar __thiscall is_animating(RGE_Active_Sprite_List * this, RGE_Spr
    //              uchar             AL:1           <RETURN>
    //              RGE_Active_Spr    ECX:4 (auto)   this
    //              RGE_Sprite *      Stack[0x4]:4   param_1                   XREF[1]:     0041ab67(R)  
    //                               ?is_animating@RGE_Active_Sprite_List@@UAEEPAVRGE_Sprite@@@Z  XREF[1]:     0056ee20(*)  
    //                               RGE_Active_Sprite_List::is_animating
    //                              asp_list.cpp:289 (11)
    //         0041ab60     MOV        EAX,dword ptr [ECX + this->list]
    //         0041ab63     TEST       EAX,EAX
    //         0041ab65     JZ         LAB_0041ab8a
    //         0041ab67     MOV        this,dword ptr [ESP + param_1]
    //                               LAB_0041ab6b                                                 XREF[1]:     0041ab77(j)  
    //                              asp_list.cpp:293 (14)
    //         0041ab6b     MOV        EDX,dword ptr [EAX]
    //         0041ab6d     CMP        dword ptr [EDX + 0x4],this
    //         0041ab70     JZ         LAB_0041ab7e
    //         0041ab72     MOV        EAX,dword ptr [EAX + 0x8]
    //         0041ab75     TEST       EAX,EAX
    //         0041ab77     JNZ        LAB_0041ab6b
    //                              asp_list.cpp:296 (2)
    //         0041ab79     XOR        AL,AL
    //                              asp_list.cpp:297 (3)
    //         0041ab7b     RET        0x4
    //                               LAB_0041ab7e                                                 XREF[1]:     0041ab70(j)  
    //                              asp_list.cpp:294 (9)
    //         0041ab7e     MOV        EAX,dword ptr [EAX]
    //         0041ab80     MOV        this,EAX
    //         0041ab82     MOV        EDX,dword ptr [EAX]
    //         0041ab84     CALL       dword ptr [EDX + 0x20]
    //                              asp_list.cpp:297 (3)
    //         0041ab87     RET        0x4
    //                               LAB_0041ab8a                                                 XREF[1]:     0041ab65(j)  
    //                              asp_list.cpp:296 (2)
    //         0041ab8a     XOR        AL,AL
    //                              asp_list.cpp:297 (3)
    //         0041ab8c     RET        0x4
}

// Offset: 0x0041AB90
void RGE_Active_Sprite_List::set_frame(RGE_Sprite* param_1, short param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void __thiscall RGE_Active_Sprite_List::set_frame(class RGE_Sprite *,short)           *
    //                              *********************************************************************************************************
    //                              void __thiscall set_frame(RGE_Active_Sprite_List * this, RGE_Sprite 
    //              void              <VOID>         <RETURN>
    //              RGE_Active_Spr    ECX:4 (auto)   this
    //              RGE_Sprite *      Stack[0x4]:4   param_1                   XREF[1]:     0041ab99(R)  
    //              short             Stack[0x8]:2   param_2                   XREF[1]:     0041ab9e(R)  
    //                               ?set_frame@RGE_Active_Sprite_List@@UAEXPAVRGE_Sprite@@F@Z    XREF[1]:     0056ee24(*)  
    //                               RGE_Active_Sprite_List::set_frame
    //                              asp_list.cpp:301 (1)
    //         0041ab90     PUSH       ESI
    //                              asp_list.cpp:304 (17)
    //         0041ab91     MOV        ESI,dword ptr [ECX + this->list]
    //         0041ab94     TEST       ESI,ESI
    //         0041ab96     JZ         LAB_0041abb8
    //         0041ab98     PUSH       EDI
    //         0041ab99     MOV        EDI,dword ptr [ESP + param_1]
    //         0041ab9d     PUSH       EBX
    //         0041ab9e     MOV        EBX,dword ptr [ESP + param_2]
    //                               LAB_0041aba2                                                 XREF[1]:     0041abb4(j)  
    //                              asp_list.cpp:305 (7)
    //         0041aba2     MOV        this,dword ptr [ESI]
    //         0041aba4     CMP        dword ptr [ECX + this->list],EDI
    //         0041aba7     JNZ        LAB_0041abaf
    //                              asp_list.cpp:306 (15)
    //         0041aba9     MOV        EAX,dword ptr [this->_padding_]
    //         0041abab     PUSH       EBX
    //         0041abac     CALL       dword ptr [EAX + 0x24]
    //                               LAB_0041abaf                                                 XREF[1]:     0041aba7(j)  
    //         0041abaf     MOV        ESI,dword ptr [ESI + 0x8]
    //         0041abb2     TEST       ESI,ESI
    //         0041abb4     JNZ        LAB_0041aba2
    //         0041abb6     POP        EBX
    //         0041abb7     POP        EDI
    //                               LAB_0041abb8                                                 XREF[1]:     0041ab96(j)  
    //                              asp_list.cpp:307 (4)
    //         0041abb8     POP        ESI
    //         0041abb9     RET        0x8
}

// Offset: 0x0041ABC0
uchar RGE_Active_Sprite_List::frame_passed(RGE_Sprite* param_1, short param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual unsigned char __thiscall RGE_Active_Sprite_List::frame_passed(class RGE_Sprite *,s... *
    //                              *********************************************************************************************************
    //                              uchar __thiscall frame_passed(RGE_Active_Sprite_List * this, RGE_Spr
    //              uchar             AL:1           <RETURN>
    //              RGE_Active_Spr    ECX:4 (auto)   this
    //              RGE_Sprite *      Stack[0x4]:4   param_1                   XREF[1]:     0041abc7(R)  
    //              short             Stack[0x8]:2   param_2                   XREF[1]:     0041abe0(R)  
    //                               ?frame_passed@RGE_Active_Sprite_List@@UAEEPAVRGE_Sprite@@F@Z XREF[1]:     0056ee28(*)  
    //                               RGE_Active_Sprite_List::frame_passed
    //                              asp_list.cpp:311 (11)
    //         0041abc0     MOV        EAX,dword ptr [ECX + this->list]
    //         0041abc3     TEST       EAX,EAX
    //         0041abc5     JZ         LAB_0041abef
    //         0041abc7     MOV        this,dword ptr [ESP + param_1]
    //                               LAB_0041abcb                                                 XREF[1]:     0041abd7(j)  
    //                              asp_list.cpp:315 (14)
    //         0041abcb     MOV        EDX,dword ptr [EAX]
    //         0041abcd     CMP        dword ptr [EDX + 0x4],this
    //         0041abd0     JZ         LAB_0041abde
    //         0041abd2     MOV        EAX,dword ptr [EAX + 0x8]
    //         0041abd5     TEST       EAX,EAX
    //         0041abd7     JNZ        LAB_0041abcb
    //                              asp_list.cpp:318 (2)
    //         0041abd9     XOR        AL,AL
    //                              asp_list.cpp:319 (3)
    //         0041abdb     RET        0x8
    //                               LAB_0041abde                                                 XREF[1]:     0041abd0(j)  
    //                              asp_list.cpp:316 (14)
    //         0041abde     MOV        EAX,dword ptr [EAX]
    //         0041abe0     MOV        this,dword ptr [ESP + param_2]
    //         0041abe4     PUSH       this
    //         0041abe5     MOV        this,EAX
    //         0041abe7     MOV        EDX,dword ptr [EAX]
    //         0041abe9     CALL       dword ptr [EDX + 0x28]
    //                              asp_list.cpp:319 (3)
    //         0041abec     RET        0x8
    //                               LAB_0041abef                                                 XREF[1]:     0041abc5(j)  
    //                              asp_list.cpp:318 (2)
    //         0041abef     XOR        AL,AL
    //                              asp_list.cpp:319 (3)
    //         0041abf1     RET        0x8
}

// Offset: 0x0041AC00
uchar RGE_Active_Sprite_List::looped(RGE_Sprite* param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual unsigned char __thiscall RGE_Active_Sprite_List::looped(class RGE_Sprite *)           *
    //                              *********************************************************************************************************
    //                              uchar __thiscall looped(RGE_Active_Sprite_List * this, RGE_Sprite * 
    //              uchar             AL:1           <RETURN>
    //              RGE_Active_Spr    ECX:4 (auto)   this
    //              RGE_Sprite *      Stack[0x4]:4   param_1                   XREF[1]:     0041ac07(R)  
    //                               ?looped@RGE_Active_Sprite_List@@UAEEPAVRGE_Sprite@@@Z        XREF[1]:     0056ee2c(*)  
    //                               RGE_Active_Sprite_List::looped
    //                              asp_list.cpp:323 (11)
    //         0041ac00     MOV        EAX,dword ptr [ECX + this->list]
    //         0041ac03     TEST       EAX,EAX
    //         0041ac05     JZ         LAB_0041ac2a
    //         0041ac07     MOV        this,dword ptr [ESP + param_1]
    //                               LAB_0041ac0b                                                 XREF[1]:     0041ac17(j)  
    //                              asp_list.cpp:327 (14)
    //         0041ac0b     MOV        EDX,dword ptr [EAX]
    //         0041ac0d     CMP        dword ptr [EDX + 0x4],this
    //         0041ac10     JZ         LAB_0041ac1e
    //         0041ac12     MOV        EAX,dword ptr [EAX + 0x8]
    //         0041ac15     TEST       EAX,EAX
    //         0041ac17     JNZ        LAB_0041ac0b
    //                              asp_list.cpp:330 (2)
    //         0041ac19     XOR        AL,AL
    //                              asp_list.cpp:331 (3)
    //         0041ac1b     RET        0x4
    //                               LAB_0041ac1e                                                 XREF[1]:     0041ac10(j)  
    //                              asp_list.cpp:328 (9)
    //         0041ac1e     MOV        EAX,dword ptr [EAX]
    //         0041ac20     MOV        this,EAX
    //         0041ac22     MOV        EDX,dword ptr [EAX]
    //         0041ac24     CALL       dword ptr [EDX + 0x2c]
    //                              asp_list.cpp:331 (3)
    //         0041ac27     RET        0x4
    //                               LAB_0041ac2a                                                 XREF[1]:     0041ac05(j)  
    //                              asp_list.cpp:330 (2)
    //         0041ac2a     XOR        AL,AL
    //                              asp_list.cpp:331 (3)
    //         0041ac2c     RET        0x4
}

// Offset: 0x0041AC30
short RGE_Active_Sprite_List::get_facetindex(RGE_Sprite* param_1, short param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual short __thiscall RGE_Active_Sprite_List::get_facetindex(class RGE_Sprite *,short)     *
    //                              *********************************************************************************************************
    //                              short __thiscall get_facetindex(RGE_Active_Sprite_List * this, RGE_S
    //              short             AX:2           <RETURN>
    //              RGE_Active_Spr    ECX:4 (auto)   this
    //              RGE_Sprite *      Stack[0x4]:4   param_1                   XREF[1]:     0041ac37(R)  
    //              short             Stack[0x8]:2   param_2                   XREF[1]:     0041ac51(R)  
    //                               ?get_facetindex@RGE_Active_Sprite_List@@UAEFPAVRGE_Sprite@@  XREF[1]:     0056ee30(*)  
    //                               RGE_Active_Sprite_List::get_facetindex
    //                              asp_list.cpp:335 (11)
    //         0041ac30     MOV        EAX,dword ptr [ECX + this->list]
    //         0041ac33     TEST       EAX,EAX
    //         0041ac35     JZ         LAB_0041ac60
    //         0041ac37     MOV        this,dword ptr [ESP + param_1]
    //                               LAB_0041ac3b                                                 XREF[1]:     0041ac47(j)  
    //                              asp_list.cpp:339 (14)
    //         0041ac3b     MOV        EDX,dword ptr [EAX]
    //         0041ac3d     CMP        dword ptr [EDX + 0x4],this
    //         0041ac40     JZ         LAB_0041ac4f
    //         0041ac42     MOV        EAX,dword ptr [EAX + 0x8]
    //         0041ac45     TEST       EAX,EAX
    //         0041ac47     JNZ        LAB_0041ac3b
    //                              asp_list.cpp:342 (3)
    //         0041ac49     XOR        AX,AX
    //                              asp_list.cpp:343 (3)
    //         0041ac4c     RET        0x8
    //                               LAB_0041ac4f                                                 XREF[1]:     0041ac40(j)  
    //                              asp_list.cpp:340 (14)
    //         0041ac4f     MOV        EAX,dword ptr [EAX]
    //         0041ac51     MOV        this,dword ptr [ESP + param_2]
    //         0041ac55     PUSH       this
    //         0041ac56     MOV        this,EAX
    //         0041ac58     MOV        EDX,dword ptr [EAX]
    //         0041ac5a     CALL       dword ptr [EDX + 0x30]
    //                              asp_list.cpp:343 (3)
    //         0041ac5d     RET        0x8
    //                               LAB_0041ac60                                                 XREF[1]:     0041ac35(j)  
    //                              asp_list.cpp:342 (3)
    //         0041ac60     XOR        AX,AX
    //                              asp_list.cpp:343 (3)
    //         0041ac63     RET        0x8
}

// Offset: 0x0041AC70
uchar get_frame(RGE_Active_Sprite_List* this_, short* param_2, short* param_3, short* param_4, short* param_5, RGE_Sprite* param_6, long param_7) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: unsigned char __thiscall RGE_Active_Sprite_List::get_frame(short &,short &,short &,short &... *
    //                              *********************************************************************************************************
    //                              uchar __thiscall get_frame(RGE_Active_Sprite_List * this, short * pa
    //              uchar             AL:1           <RETURN>
    //              RGE_Active_Spr    ECX:4 (auto)   this
    //              short *           Stack[0x4]:4   param_1                   XREF[1]:     0041aca6(R)  
    //              short *           Stack[0x8]:4   param_2                   XREF[1]:     0041aca1(R)  
    //              short *           Stack[0xc]:4   param_3                   XREF[1]:     0041ac9a(R)  
    //              short *           Stack[0x10]:4  param_4                   XREF[1]:     0041ac95(R)  
    //              RGE_Sprite *      Stack[0x14]:4  param_5                   XREF[1]:     0041ac77(R)  
    //              long              Stack[0x18]:4  param_6                   XREF[1]:     0041ac8e(R)  
    //                               ?get_frame@RGE_Active_Sprite_List@@QAEEAAF000PAVRGE_Sprite@  XREF[1]:     get_frame:004c58ac(c)  
    //                               RGE_Active_Sprite_List::get_frame
    //                              asp_list.cpp:347 (11)
    //         0041ac70     MOV        EAX,dword ptr [ECX + this->list]
    //         0041ac73     TEST       EAX,EAX
    //         0041ac75     JZ         LAB_0041acb3
    //         0041ac77     MOV        this,dword ptr [ESP + param_5]
    //                               LAB_0041ac7b                                                 XREF[1]:     0041ac87(j)  
    //                              asp_list.cpp:351 (14)
    //         0041ac7b     MOV        EDX,dword ptr [EAX]
    //         0041ac7d     CMP        dword ptr [EDX + 0x4],this
    //         0041ac80     JZ         LAB_0041ac8e
    //         0041ac82     MOV        EAX,dword ptr [EAX + 0x8]
    //         0041ac85     TEST       EAX,EAX
    //         0041ac87     JNZ        LAB_0041ac7b
    //                              asp_list.cpp:354 (2)
    //         0041ac89     XOR        AL,AL
    //                              asp_list.cpp:355 (3)
    //         0041ac8b     RET        0x18
    //                               LAB_0041ac8e                                                 XREF[1]:     0041ac80(j)  
    //                              asp_list.cpp:352 (34)
    //         0041ac8e     MOV        this,dword ptr [ESP + param_6]
    //         0041ac92     MOV        EAX,dword ptr [EAX]
    //         0041ac94     PUSH       this
    //         0041ac95     MOV        this,dword ptr [ESP + param_4]
    //         0041ac99     PUSH       this
    //         0041ac9a     MOV        this,dword ptr [ESP + param_3]
    //         0041ac9e     MOV        EDX,dword ptr [EAX]
    //         0041aca0     PUSH       this
    //         0041aca1     MOV        this,dword ptr [ESP + param_2]
    //         0041aca5     PUSH       this
    //         0041aca6     MOV        this,dword ptr [ESP + param_1]
    //         0041acaa     PUSH       this
    //         0041acab     MOV        this,EAX
    //         0041acad     CALL       dword ptr [EDX + 0x34]
    //                              asp_list.cpp:355 (3)
    //         0041acb0     RET        0x18
    //                               LAB_0041acb3                                                 XREF[1]:     0041ac75(j)  
    //                              asp_list.cpp:354 (2)
    //         0041acb3     XOR        AL,AL
    //                              asp_list.cpp:355 (3)
    //         0041acb5     RET        0x18
}

// Offset: 0x0041ACC0
uchar get_lowest_draw_level(RGE_Active_Sprite_List* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: unsigned char __thiscall RGE_Active_Sprite_List::get_lowest_draw_level(void)                  *
    //                              *********************************************************************************************************
    //                              uchar __thiscall get_lowest_draw_level(RGE_Active_Sprite_List * this)
    //              uchar             AL:1           <RETURN>
    //              RGE_Active_Spr    ECX:4 (auto)   this
    //                               ?get_lowest_draw_level@RGE_Active_Sprite_List@@QAEEXZ        XREF[6]:     key_down_action:0048a39a(c), 
    //                               RGE_Active_Sprite_List::get_lowest_draw_level                             key_down_action:004abbea(c), 
    //                                                                                                         handle_scroll_view:0053a8f7(c), 
    //                                                                                                         mouse_left_down_action:0053e682(c)
    //                                                                                                         mouse_left_up_action:0053ec6b(c), 
    //                                                                                                         command_place_object:0053f9b5(c)  
    //                              asp_list.cpp:359 (2)
    //         0041acc0     PUSH       EBX
    //         0041acc1     PUSH       ESI
    //                              asp_list.cpp:366 (9)
    //         0041acc2     MOV        ESI,dword ptr [ECX + this->list]
    //         0041acc5     MOV        BL,0x14
    //         0041acc7     TEST       ESI,ESI
    //         0041acc9     JZ         LAB_0041acdf
    //                               LAB_0041accb                                                 XREF[1]:     0041acdd(j)  
    //                              asp_list.cpp:368 (7)
    //         0041accb     MOV        this,dword ptr [ESI]
    //         0041accd     CALL       RGE_Active_Sprite::get_lowest_draw_level         uchar get_lowest_draw_level(RGE_Active_Sprite
    //                              asp_list.cpp:369 (4)
    //         0041acd2     CMP        AL,BL
    //         0041acd4     JNC        LAB_0041acd8
    //                              asp_list.cpp:370 (2)
    //         0041acd6     MOV        BL,AL
    //                               LAB_0041acd8                                                 XREF[1]:     0041acd4(j)  
    //                              asp_list.cpp:366 (7)
    //         0041acd8     MOV        ESI,dword ptr [ESI + 0x8]
    //         0041acdb     TEST       ESI,ESI
    //         0041acdd     JNZ        LAB_0041accb
    //                               LAB_0041acdf                                                 XREF[1]:     0041acc9(j)  
    //                              asp_list.cpp:373 (2)
    //         0041acdf     MOV        AL,BL
    //                              asp_list.cpp:374 (3)
    //         0041ace1     POP        ESI
    //         0041ace2     POP        EBX
    //         0041ace3     RET
}

// Offset: 0x0041ACF0
int check_for_shadows(RGE_Active_Sprite_List* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall RGE_Active_Sprite_List::check_for_shadows(void)                                *
    //                              *********************************************************************************************************
    //                              int __thiscall check_for_shadows(RGE_Active_Sprite_List * this)
    //              int               EAX:4          <RETURN>
    //              RGE_Active_Spr    ECX:4 (auto)   this
    //                               ?check_for_shadows@RGE_Active_Sprite_List@@QAEHXZ
    //                               RGE_Active_Sprite_List::check_for_shadows
    //                              asp_list.cpp:378 (1)
    //         0041acf0     PUSH       ESI
    //                              asp_list.cpp:384 (7)
    //         0041acf1     MOV        ESI,dword ptr [ECX + this->list]
    //         0041acf4     TEST       ESI,ESI
    //         0041acf6     JZ         LAB_0041ad13
    //                               LAB_0041acf8                                                 XREF[1]:     0041ad08(j)  
    //                              asp_list.cpp:386 (18)
    //         0041acf8     MOV        this,dword ptr [ESI]
    //         0041acfa     CALL       RGE_Active_Sprite::check_for_shadows             int check_for_shadows(RGE_Active_Sprite * this)
    //         0041acff     TEST       EAX,EAX
    //         0041ad01     JNZ        LAB_0041ad0c
    //         0041ad03     MOV        ESI,dword ptr [ESI + 0x8]
    //         0041ad06     TEST       ESI,ESI
    //         0041ad08     JNZ        LAB_0041acf8
    //                              asp_list.cpp:390 (2)
    //         0041ad0a     POP        ESI
    //         0041ad0b     RET
    //                               LAB_0041ad0c                                                 XREF[1]:     0041ad01(j)  
    //                              asp_list.cpp:386 (5)
    //         0041ad0c     MOV        EAX,0x1
    //                              asp_list.cpp:390 (2)
    //         0041ad11     POP        ESI
    //         0041ad12     RET
    //                               LAB_0041ad13                                                 XREF[1]:     0041acf6(j)  
    //                              asp_list.cpp:389 (2)
    //         0041ad13     XOR        EAX,EAX
    //                              asp_list.cpp:390 (2)
    //         0041ad15     POP        ESI
    //         0041ad16     RET
}

