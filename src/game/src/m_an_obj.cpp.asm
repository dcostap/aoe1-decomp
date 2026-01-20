// Auto-generated scaffold unit: m_an_obj.cpp.asm
// SourceMap: C:/msdev/work/age1_x1/m_an_obj.cpp
#include "../include/common.h"

// Offset: 0x0044F9C0
undefined RGE_Master_Animated_Object(RGE_Master_Animated_Object* this_, RGE_Master_Animated_Object* param_2, int param_3) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall RGE_Master_Animated_Object::RGE_Master_Animated_Object(class RGE_Master_Animate... *
    //                              *********************************************************************************************************
    //                              undefined __thiscall RGE_Master_Animated_Object(RGE_Master_Animated_
    //              undefined         <UNASSIGNED>   <RETURN>
    //              RGE_Master_Ani    ECX:4 (auto)   this
    //              RGE_Master_Ani    Stack[0x4]:4   param_1                   XREF[1]:     0044f9d8(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     0044f9ea(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     0044f9ee(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     0044fa08(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     0044f9e1(W)  
    //                               ??0RGE_Master_Animated_Object@@QAE@PAV0@H@Z                  XREF[3]:     make_new_master:0044fd0b(c), 
    //                               RGE_Master_Animated_Object::RGE_Master_Animated_Object                    RGE_Master_Doppleganger_Object:004
    //                                                                                                         RGE_Master_Moving_Object:00451a45(
    //                              m_an_obj.cpp:24 (42)
    //         0044f9c0     PUSH       -0x1
    //         0044f9c2     PUSH       FUN_0055d718
    //         0044f9c7     MOV        EAX,FS:[0x0]
    //         0044f9cd     PUSH       EAX
    //         0044f9ce     MOV        dword ptr FS:[0x0],ESP
    //         0044f9d5     PUSH       this
    //         0044f9d6     PUSH       ESI
    //         0044f9d7     PUSH       EDI
    //         0044f9d8     MOV        EDI,dword ptr [ESP + param_1]
    //         0044f9dc     MOV        ESI,this
    //         0044f9de     PUSH       0x0
    //         0044f9e0     PUSH       EDI
    //         0044f9e1     MOV        dword ptr [ESP + local_10],ESI
    //         0044f9e5     CALL       RGE_Master_Static_Object::RGE_Master_Static_Ob   undefined RGE_Master_Static_Object(RGE_Master
    //                              m_an_obj.cpp:25 (22)
    //         0044f9ea     MOV        EAX,dword ptr [ESP + param_2]
    //         0044f9ee     MOV        dword ptr [ESP + local_4],0x0
    //         0044f9f6     TEST       EAX,EAX
    //         0044f9f8     MOV        dword ptr [ESI],RGE_Master_Animated_Object::`v   = 0044fa20
    //         0044f9fe     JZ         LAB_0044fa08
    //                              m_an_obj.cpp:26 (8)
    //         0044fa00     PUSH       EDI
    //         0044fa01     MOV        this,ESI
    //         0044fa03     CALL       RGE_Master_Animated_Object::setup                int setup(RGE_Master_Animated_Object * this, 
    //                               LAB_0044fa08                                                 XREF[1]:     0044f9fe(j)  
    //                              m_an_obj.cpp:27 (21)
    //         0044fa08     MOV        this,dword ptr [ESP + local_c]
    //         0044fa0c     MOV        EAX,ESI
    //         0044fa0e     POP        EDI
    //         0044fa0f     MOV        dword ptr FS:[0x0],this
    //         0044fa16     POP        ESI
    //         0044fa17     ADD        ESP,0x10
    //         0044fa1a     RET        0x8
}

// Offset: 0x0044FA40
undefined RGE_Master_Animated_Object(RGE_Master_Animated_Object* this_, int param_2, RGE_Sprite** param_3, RGE_Sound** param_4, int param_5) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall RGE_Master_Animated_Object::RGE_Master_Animated_Object(int,class RGE_Sprite * *... *
    //                              *********************************************************************************************************
    //                              undefined __thiscall RGE_Master_Animated_Object(RGE_Master_Animated_
    //              undefined         <UNASSIGNED>   <RETURN>
    //              RGE_Master_Ani    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0044fa5c(R)  
    //              RGE_Sprite * *    Stack[0x8]:4   param_2                   XREF[1]:     0044fa57(R)  
    //              RGE_Sound * *     Stack[0xc]:4   param_3                   XREF[1]:     0044fa62(R)  
    //              int               Stack[0x10]:4  param_4                   XREF[1]:     0044fa76(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     0044fa7a(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     0044fa96(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     0044fa6d(W)  
    //                               ??0RGE_Master_Animated_Object@@QAE@HPAPAVRGE_Sprite@@PAPAVR  XREF[4]:     RGE_Master_Doppleganger_Object:004
    //                               RGE_Master_Animated_Object::RGE_Master_Animated_Object                    RGE_Master_Moving_Object:00451ad1(
    //                                                                                                         load_master_object:0046131e(c), 
    //                                                                                                         load_master_object:0046fcee(c)  
    //                              m_an_obj.cpp:33 (54)
    //         0044fa40     PUSH       -0x1
    //         0044fa42     PUSH       FUN_0055d738
    //         0044fa47     MOV        EAX,FS:[0x0]
    //         0044fa4d     PUSH       EAX
    //         0044fa4e     MOV        dword ptr FS:[0x0],ESP
    //         0044fa55     PUSH       this
    //         0044fa56     PUSH       EBX
    //         0044fa57     MOV        EBX,dword ptr [ESP + param_2]
    //         0044fa5b     PUSH       EBP
    //         0044fa5c     MOV        EBP,dword ptr [ESP + param_1]
    //         0044fa60     PUSH       ESI
    //         0044fa61     PUSH       EDI
    //         0044fa62     MOV        EDI,dword ptr [ESP + param_3]
    //         0044fa66     PUSH       0x0
    //         0044fa68     PUSH       EDI
    //         0044fa69     MOV        ESI,this
    //         0044fa6b     PUSH       EBX
    //         0044fa6c     PUSH       EBP
    //         0044fa6d     MOV        dword ptr [ESP + local_10],ESI
    //         0044fa71     CALL       RGE_Master_Static_Object::RGE_Master_Static_Ob   undefined RGE_Master_Static_Object(RGE_Master
    //                              m_an_obj.cpp:34 (22)
    //         0044fa76     MOV        EAX,dword ptr [ESP + param_4]
    //         0044fa7a     MOV        dword ptr [ESP + local_4],0x0
    //         0044fa82     TEST       EAX,EAX
    //         0044fa84     MOV        dword ptr [ESI],RGE_Master_Animated_Object::`v   = 0044fa20
    //         0044fa8a     JZ         LAB_0044fa96
    //                              m_an_obj.cpp:35 (10)
    //         0044fa8c     PUSH       EDI
    //         0044fa8d     PUSH       EBX
    //         0044fa8e     PUSH       EBP
    //         0044fa8f     MOV        this,ESI
    //         0044fa91     CALL       RGE_Master_Animated_Object::setup                int setup(RGE_Master_Animated_Object * this, 
    //                               LAB_0044fa96                                                 XREF[1]:     0044fa8a(j)  
    //                              m_an_obj.cpp:36 (23)
    //         0044fa96     MOV        this,dword ptr [ESP + local_c]
    //         0044fa9a     MOV        EAX,ESI
    //         0044fa9c     POP        EDI
    //         0044fa9d     POP        ESI
    //         0044fa9e     POP        EBP
    //         0044fa9f     MOV        dword ptr FS:[0x0],this
    //         0044faa6     POP        EBX
    //         0044faa7     ADD        ESP,0x10
    //         0044faaa     RET        0x10
}

// Offset: 0x0044FAB0
undefined RGE_Master_Animated_Object(RGE_Master_Animated_Object* this_, FILE* param_2, RGE_Sprite** param_3, RGE_Sound** param_4, short param_5, int param_6) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall RGE_Master_Animated_Object::RGE_Master_Animated_Object(struct _iobuf *,class RG... *
    //                              *********************************************************************************************************
    //                              undefined __thiscall RGE_Master_Animated_Object(RGE_Master_Animated_
    //              undefined         <UNASSIGNED>   <RETURN>
    //              RGE_Master_Ani    ECX:4 (auto)   this
    //              _iobuf *          Stack[0x4]:4   param_1                   XREF[2]:     0044fac6(R), 0044fb01(R)  
    //              RGE_Sprite * *    Stack[0x8]:4   param_2                   XREF[1]:     0044fad0(R)  
    //              RGE_Sound * *     Stack[0xc]:4   param_3                   XREF[1]:     0044facb(R)  
    //              short             Stack[0x10]:2  param_4                   XREF[1]:     0044fad6(R)  
    //              int               Stack[0x14]:4  param_5                   XREF[1]:     0044faeb(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     0044faef(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     0044fb10(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     0044fae2(W)  
    //                               ??0RGE_Master_Animated_Object@@QAE@PAU_iobuf@@PAPAVRGE_Spri  XREF[3]:     RGE_Master_Doppleganger_Object:004
    //                               RGE_Master_Animated_Object::RGE_Master_Animated_Object                    RGE_Master_Moving_Object:00451b46(
    //                                                                                                         load_object:00461619(c)  
    //                              m_an_obj.cpp:42 (59)
    //         0044fab0     PUSH       -0x1
    //         0044fab2     PUSH       FUN_0055d758
    //         0044fab7     MOV        EAX,FS:[0x0]
    //         0044fabd     PUSH       EAX
    //         0044fabe     MOV        dword ptr FS:[0x0],ESP
    //         0044fac5     PUSH       this
    //         0044fac6     MOV        EAX,dword ptr [ESP + param_1]
    //         0044faca     PUSH       EBX
    //         0044facb     MOV        EBX,dword ptr [ESP + param_3]
    //         0044facf     PUSH       EBP
    //         0044fad0     MOV        EBP,dword ptr [ESP + param_2]
    //         0044fad4     PUSH       ESI
    //         0044fad5     PUSH       EDI
    //         0044fad6     MOV        EDI,dword ptr [ESP + param_4]
    //         0044fada     PUSH       0x0
    //         0044fadc     PUSH       EDI
    //         0044fadd     PUSH       EBX
    //         0044fade     MOV        ESI,this
    //         0044fae0     PUSH       EBP
    //         0044fae1     PUSH       EAX
    //         0044fae2     MOV        dword ptr [ESP + local_10],ESI
    //         0044fae6     CALL       RGE_Master_Static_Object::RGE_Master_Static_Ob   undefined RGE_Master_Static_Object(RGE_Master
    //                              m_an_obj.cpp:43 (22)
    //         0044faeb     MOV        EAX,dword ptr [ESP + param_5]
    //         0044faef     MOV        dword ptr [ESP + local_4],0x0
    //         0044faf7     TEST       EAX,EAX
    //         0044faf9     MOV        dword ptr [ESI],RGE_Master_Animated_Object::`v   = 0044fa20
    //         0044faff     JZ         LAB_0044fb10
    //                              m_an_obj.cpp:44 (15)
    //         0044fb01     MOV        this,dword ptr [ESP + param_1]
    //         0044fb05     PUSH       EDI
    //         0044fb06     PUSH       EBX
    //         0044fb07     PUSH       EBP
    //         0044fb08     PUSH       this
    //         0044fb09     MOV        this,ESI
    //         0044fb0b     CALL       RGE_Master_Animated_Object::setup                int setup(RGE_Master_Animated_Object * this, 
    //                               LAB_0044fb10                                                 XREF[1]:     0044faff(j)  
    //                              m_an_obj.cpp:45 (23)
    //         0044fb10     MOV        this,dword ptr [ESP + local_c]
    //         0044fb14     MOV        EAX,ESI
    //         0044fb16     POP        EDI
    //         0044fb17     POP        ESI
    //         0044fb18     POP        EBP
    //         0044fb19     MOV        dword ptr FS:[0x0],this
    //         0044fb20     POP        EBX
    //         0044fb21     ADD        ESP,0x10
    //         0044fb24     RET        0x14
}

// Offset: 0x0044FB30
int setup(RGE_Master_Animated_Object* this_, RGE_Master_Animated_Object* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * protected: int __thiscall RGE_Master_Animated_Object::setup(class RGE_Master_Animated_Object *)       *
    //                              *********************************************************************************************************
    //                              int __thiscall setup(RGE_Master_Animated_Object * this, RGE_Master_A
    //              int               EAX:4          <RETURN>
    //              RGE_Master_Ani    ECX:4 (auto)   this
    //              RGE_Master_Ani    Stack[0x4]:4   param_1                   XREF[1]:     0044fb32(R)  
    //                               ?setup@RGE_Master_Animated_Object@@IAEHPAV1@@Z               XREF[3]:     RGE_Master_Animated_Object:0044fa0
    //                               RGE_Master_Animated_Object::setup                                         setup:00451238(c), 
    //                                                                                                         setup:00451b99(c)  
    //                              m_an_obj.cpp:51 (2)
    //         0044fb30     PUSH       ESI
    //         0044fb31     PUSH       EDI
    //                              m_an_obj.cpp:52 (12)
    //         0044fb32     MOV        EDI,dword ptr [ESP + param_1]
    //         0044fb36     MOV        ESI,this
    //         0044fb38     PUSH       EDI
    //         0044fb39     CALL       RGE_Master_Static_Object::setup                  int setup(RGE_Master_Static_Object * this, RG
    //                              m_an_obj.cpp:54 (4)
    //         0044fb3e     MOV        byte ptr [ESI + 0x4],0x14
    //                              m_an_obj.cpp:57 (12)
    //         0044fb42     MOV        EAX,dword ptr [EDI + 0xb8]
    //         0044fb48     MOV        dword ptr [ESI + 0xb8],EAX
    //                              m_an_obj.cpp:60 (10)
    //         0044fb4e     POP        EDI
    //         0044fb4f     MOV        EAX,0x1
    //         0044fb54     POP        ESI
    //         0044fb55     RET        0x4
}

// Offset: 0x0044FB60
int setup(RGE_Master_Animated_Object* this_, int param_2, RGE_Sprite** param_3, RGE_Sound** param_4) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * protected: int __thiscall RGE_Master_Animated_Object::setup(int,class RGE_Sprite * *,class RGE_Sou... *
    //                              *********************************************************************************************************
    //                              int __thiscall setup(RGE_Master_Animated_Object * this, int param_1,
    //              int               EAX:4          <RETURN>
    //              RGE_Master_Ani    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0044fb6c(R)  
    //              RGE_Sprite * *    Stack[0x8]:4   param_2                   XREF[1]:     0044fb68(R)  
    //              RGE_Sound * *     Stack[0xc]:4   param_3                   XREF[1]:     0044fb60(R)  
    //                               ?setup@RGE_Master_Animated_Object@@IAEHHPAPAVRGE_Sprite@@PA  XREF[3]:     RGE_Master_Animated_Object:0044fa9
    //                               RGE_Master_Animated_Object::setup                                         setup:00451264(c), 
    //                                                                                                         setup:00451c24(c)  
    //                              m_an_obj.cpp:65 (26)
    //         0044fb60     MOV        EAX,dword ptr [ESP + param_3]
    //         0044fb64     PUSH       ESI
    //         0044fb65     MOV        ESI,this
    //         0044fb67     PUSH       EDI
    //         0044fb68     MOV        this,dword ptr [ESP + param_2]
    //         0044fb6c     MOV        EDI,dword ptr [ESP + param_1]
    //         0044fb70     PUSH       EAX
    //         0044fb71     PUSH       this
    //         0044fb72     PUSH       EDI
    //         0044fb73     MOV        this,ESI
    //         0044fb75     CALL       RGE_Master_Static_Object::setup                  int setup(RGE_Master_Static_Object * this, in
    //                              m_an_obj.cpp:68 (4)
    //         0044fb7a     MOV        byte ptr [ESI + 0x4],0x14
    //                              m_an_obj.cpp:71 (18)
    //         0044fb7e     ADD        ESI,0xb8
    //         0044fb84     PUSH       0x4
    //         0044fb86     PUSH       ESI
    //         0044fb87     PUSH       EDI
    //         0044fb88     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0044fb8d     ADD        ESP,0xc
    //                              m_an_obj.cpp:73 (5)
    //         0044fb90     MOV        EAX,0x1
    //                              m_an_obj.cpp:74 (5)
    //         0044fb95     POP        EDI
    //         0044fb96     POP        ESI
    //         0044fb97     RET        0xc
}

// Offset: 0x0044FBA0
int setup(RGE_Master_Animated_Object* this_, FILE* param_2, RGE_Sprite** param_3, RGE_Sound** param_4, short param_5) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * protected: int __thiscall RGE_Master_Animated_Object::setup(struct _iobuf *,class RGE_Sprite * *,c... *
    //                              *********************************************************************************************************
    //                              int __thiscall setup(RGE_Master_Animated_Object * this, _iobuf * par
    //              int               EAX:4          <RETURN>
    //              RGE_Master_Ani    ECX:4 (auto)   this
    //              _iobuf *          Stack[0x4]:4   param_1                   XREF[1]:     0044fbb0(R)  
    //              RGE_Sprite * *    Stack[0x8]:4   param_2                   XREF[1]:     0044fba4(R)  
    //              RGE_Sound * *     Stack[0xc]:4   param_3                   XREF[1]:     0044fbab(R)  
    //              short             Stack[0x10]:2  param_4                   XREF[1]:     0044fba0(R)  
    //                               ?setup@RGE_Master_Animated_Object@@IAEHPAU_iobuf@@PAPAVRGE_  XREF[3]:     RGE_Master_Animated_Object:0044fb0
    //                               RGE_Master_Animated_Object::setup                                         setup:00451299(c), 
    //                                                                                                         setup:00451d2c(c)  
    //                              m_an_obj.cpp:79 (31)
    //         0044fba0     MOV        EAX,dword ptr [ESP + param_4]
    //         0044fba4     MOV        EDX,dword ptr [ESP + param_2]
    //         0044fba8     PUSH       ESI
    //         0044fba9     MOV        ESI,this
    //         0044fbab     MOV        this,dword ptr [ESP + param_3]
    //         0044fbaf     PUSH       EDI
    //         0044fbb0     MOV        EDI,dword ptr [ESP + param_1]
    //         0044fbb4     PUSH       EAX
    //         0044fbb5     PUSH       this
    //         0044fbb6     PUSH       EDX
    //         0044fbb7     PUSH       EDI
    //         0044fbb8     MOV        this,ESI
    //         0044fbba     CALL       RGE_Master_Static_Object::setup                  int setup(RGE_Master_Static_Object * this, _i
    //                              m_an_obj.cpp:82 (4)
    //         0044fbbf     MOV        byte ptr [ESI + 0x4],0x14
    //                              m_an_obj.cpp:85 (21)
    //         0044fbc3     ADD        ESI,0xb8
    //         0044fbc9     PUSH       ESI
    //         0044fbca     PUSH       s_%f                                             = "%f"
    //         0044fbcf     PUSH       EDI
    //         0044fbd0     CALL       fscanf                                           undefined fscanf()
    //         0044fbd5     ADD        ESP,0xc
    //                              m_an_obj.cpp:88 (5)
    //         0044fbd8     MOV        EAX,0x1
    //                              m_an_obj.cpp:89 (5)
    //         0044fbdd     POP        EDI
    //         0044fbde     POP        ESI
    //         0044fbdf     RET        0x10
}

// Offset: 0x0044FBF0
void RGE_Master_Animated_Object(RGE_Master_Animated_Object* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual __thiscall RGE_Master_Animated_Object::~RGE_Master_Animated_Object(void)              *
    //                              *********************************************************************************************************
    //                              void __thiscall ~RGE_Master_Animated_Object(RGE_Master_Animated_Obje
    //              void              <VOID>         <RETURN>
    //              RGE_Master_Ani    ECX:4 (auto)   this
    //                               ??1RGE_Master_Animated_Object@@UAE@XZ                        XREF[3]:     `vector_deleting_destructor':0044f
    //                               RGE_Master_Animated_Object::~RGE_Master_Animated_Object                   ~RGE_Master_Doppleganger_Object:00
    //                                                                                                         ~RGE_Master_Moving_Object:00451de6
    //                              m_an_obj.cpp:94 (11)
    //         0044fbf0     MOV        dword ptr [this->_padding_],RGE_Master_Animate   = 0044fa20
    //         0044fbf6     JMP        RGE_Master_Static_Object::~RGE_Master_Static_O   void ~RGE_Master_Static_Object(RGE_Master_Sta
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
}

// Offset: 0x0044FC00
RGE_Static_Object* RGE_Master_Doppleganger_Object::make_new_obj(RGE_Player* param_1, float param_2, float param_3, float param_4) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual class RGE_Static_Object * __thiscall RGE_Master_Animated_Object::make_new_obj(clas... *
    //                              *********************************************************************************************************
    //                              RGE_Static_Object * __thiscall make_new_obj(RGE_Master_Animated_Obje
    //              RGE_Static_Obj    EAX:4          <RETURN>
    //              RGE_Master_Ani    ECX:4 (auto)   this
    //              RGE_Player *      Stack[0x4]:4   param_1                   XREF[2]:     0044fc17(R), 0044fc75(W)  
    //              float             Stack[0x8]:4   param_2                   XREF[2]:     0044fc45(R), 0044fc90(R)  
    //              float             Stack[0xc]:4   param_3                   XREF[2]:     0044fc3e(R), 0044fc89(R)  
    //              float             Stack[0x10]:4  param_4                   XREF[2]:     0044fc3a(R), 0044fc85(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     0044fc7b(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[2]:     0044fc9f(R), 0044fcb3(R)  
    //                               ?make_new_obj@RGE_Master_Animated_Object@@UAEPAVRGE_Static_  XREF[2]:     005704a0(*), 00570538(*)  
    //                               RGE_Master_Animated_Object::make_new_obj
    //                              m_an_obj.cpp:100 (23)
    //         0044fc00     MOV        EAX,FS:[0x0]
    //         0044fc06     PUSH       -0x1
    //         0044fc08     PUSH       FUN_0055d77b
    //         0044fc0d     PUSH       EAX
    //         0044fc0e     MOV        dword ptr FS:[0x0],ESP
    //         0044fc15     PUSH       EBX
    //         0044fc16     PUSH       ESI
    //                              m_an_obj.cpp:103 (17)
    //         0044fc17     MOV        EBX,dword ptr [ESP + param_1]
    //         0044fc1b     PUSH       EDI
    //         0044fc1c     MOV        EDI,this
    //         0044fc1e     MOV        AL,byte ptr [EDI + 0xa4]
    //         0044fc24     TEST       AL,AL
    //         0044fc26     JZ         LAB_0044fc68
    //                              m_an_obj.cpp:105 (14)
    //         0044fc28     MOV        AL,byte ptr [EDI + 0x4]
    //         0044fc2b     MOV        this,dword ptr [EBX + 0x3c]
    //         0044fc2e     PUSH       EAX
    //         0044fc2f     CALL       RGE_Game_World::recycle_object_in_to_game        RGE_Static_Object * recycle_object_in_to_game
    //         0044fc34     MOV        ESI,EAX
    //                              m_an_obj.cpp:106 (4)
    //         0044fc36     TEST       ESI,ESI
    //         0044fc38     JZ         LAB_0044fc68
    //                              m_an_obj.cpp:108 (24)
    //         0044fc3a     MOV        EAX,dword ptr [ESP + param_4]
    //         0044fc3e     MOV        this,dword ptr [ESP + param_3]
    //         0044fc42     MOV        EDX,dword ptr [ESI]
    //         0044fc44     PUSH       EAX
    //         0044fc45     MOV        EAX,dword ptr [ESP + param_2]
    //         0044fc49     PUSH       this
    //         0044fc4a     PUSH       EAX
    //         0044fc4b     PUSH       EBX
    //         0044fc4c     PUSH       EDI
    //         0044fc4d     MOV        this,ESI
    //         0044fc4f     CALL       dword ptr [EDX + 0x4]
    //                              m_an_obj.cpp:109 (2)
    //         0044fc52     MOV        EAX,ESI
    //                              m_an_obj.cpp:114 (20)
    //         0044fc54     MOV        this,dword ptr [ESP + 0xc]
    //         0044fc58     MOV        dword ptr FS:[0x0],this
    //         0044fc5f     POP        EDI
    //         0044fc60     POP        ESI
    //         0044fc61     POP        EBX
    //         0044fc62     ADD        ESP,0xc
    //         0044fc65     RET        0x10
    //                               LAB_0044fc68                                                 XREF[2]:     0044fc26(j), 0044fc38(j)  
    //                              m_an_obj.cpp:113 (55)
    //         0044fc68     PUSH       0x8c
    //         0044fc6d     CALL       operator_new                                     void * operator_new(uint param_1)
    //         0044fc72     ADD        ESP,0x4
    //         0044fc75     MOV        dword ptr [ESP + param_1],EAX
    //         0044fc79     TEST       EAX,EAX
    //         0044fc7b     MOV        dword ptr [ESP + local_4],0x0
    //         0044fc83     JZ         LAB_0044fcb3
    //         0044fc85     MOV        this,dword ptr [ESP + param_4]
    //         0044fc89     MOV        EDX,dword ptr [ESP + param_3]
    //         0044fc8d     PUSH       0x1
    //         0044fc8f     PUSH       this
    //         0044fc90     MOV        this,dword ptr [ESP + param_2]
    //         0044fc94     PUSH       EDX
    //         0044fc95     PUSH       this
    //         0044fc96     PUSH       EBX
    //         0044fc97     PUSH       EDI
    //         0044fc98     MOV        this,EAX
    //         0044fc9a     CALL       RGE_Animated_Object::RGE_Animated_Object         undefined RGE_Animated_Object(RGE_Animated_Ob
    //                              m_an_obj.cpp:114 (42)
    //         0044fc9f     MOV        this,dword ptr [ESP + local_c]
    //         0044fca3     MOV        dword ptr FS:[0x0],this
    //         0044fcaa     POP        EDI
    //         0044fcab     POP        ESI
    //         0044fcac     POP        EBX
    //         0044fcad     ADD        ESP,0xc
    //         0044fcb0     RET        0x10
    //                               LAB_0044fcb3                                                 XREF[1]:     0044fc83(j)  
    //         0044fcb3     MOV        this,dword ptr [ESP + local_c]
    //         0044fcb7     POP        EDI
    //         0044fcb8     POP        ESI
    //         0044fcb9     XOR        EAX,EAX
    //         0044fcbb     MOV        dword ptr FS:[0x0],this
    //         0044fcc2     POP        EBX
    //         0044fcc3     ADD        ESP,0xc
    //         0044fcc6     RET        0x10
}

// Offset: 0x0044FCD0
RGE_Master_Static_Object* RGE_Master_Animated_Object::make_new_master() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual class RGE_Master_Static_Object * __thiscall RGE_Master_Animated_Object::make_new_m... *
    //                              *********************************************************************************************************
    //                              RGE_Master_Static_Object * __thiscall make_new_master(RGE_Master_Ani
    //              RGE_Master_Sta    EAX:4          <RETURN>
    //              RGE_Master_Ani    ECX:4 (auto)   this
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     0044fcfc(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[2]:     0044fd10(R), 0044fd20(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     0044fcf6(W)  
    //                               ?make_new_master@RGE_Master_Animated_Object@@UAEPAVRGE_Mast  XREF[1]:     005704a4(*)  
    //                               RGE_Master_Animated_Object::make_new_master
    //                              m_an_obj.cpp:119 (25)
    //         0044fcd0     PUSH       -0x1
    //         0044fcd2     PUSH       FUN_0055d79b
    //         0044fcd7     MOV        EAX,FS:[0x0]
    //         0044fcdd     PUSH       EAX
    //         0044fcde     MOV        dword ptr FS:[0x0],ESP
    //         0044fce5     PUSH       this
    //         0044fce6     PUSH       ESI
    //         0044fce7     MOV        ESI,this
    //                              m_an_obj.cpp:120 (39)
    //         0044fce9     PUSH       0xbc
    //         0044fcee     CALL       operator_new                                     void * operator_new(uint param_1)
    //         0044fcf3     ADD        ESP,0x4
    //         0044fcf6     MOV        dword ptr [ESP + local_10],EAX
    //         0044fcfa     TEST       EAX,EAX
    //         0044fcfc     MOV        dword ptr [ESP + local_4],0x0
    //         0044fd04     JZ         LAB_0044fd20
    //         0044fd06     PUSH       0x1
    //         0044fd08     PUSH       ESI
    //         0044fd09     MOV        this,EAX
    //         0044fd0b     CALL       RGE_Master_Animated_Object::RGE_Master_Animate   undefined RGE_Master_Animated_Object(RGE_Mast
    //                              m_an_obj.cpp:121 (34)
    //         0044fd10     MOV        this,dword ptr [ESP + local_c]
    //         0044fd14     MOV        dword ptr FS:[0x0],this
    //         0044fd1b     POP        ESI
    //         0044fd1c     ADD        ESP,0x10
    //         0044fd1f     RET
    //                               LAB_0044fd20                                                 XREF[1]:     0044fd04(j)  
    //         0044fd20     MOV        this,dword ptr [ESP + local_c]
    //         0044fd24     XOR        EAX,EAX
    //         0044fd26     MOV        dword ptr FS:[0x0],this
    //         0044fd2d     POP        ESI
    //         0044fd2e     ADD        ESP,0x10
    //         0044fd31     RET
}

// Offset: 0x0044FD40
void RGE_Master_Animated_Object::copy_obj(RGE_Master_Static_Object* param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void __thiscall RGE_Master_Animated_Object::copy_obj(class RGE_Master_Static_Objec... *
    //                              *********************************************************************************************************
    //                              void __thiscall copy_obj(RGE_Master_Animated_Object * this, RGE_Mast
    //              void              <VOID>         <RETURN>
    //              RGE_Master_Ani    ECX:4 (auto)   this
    //              RGE_Master_Sta    Stack[0x4]:4   param_1                   XREF[1]:     0044fd42(R)  
    //                               ?copy_obj@RGE_Master_Animated_Object@@UAEXPAVRGE_Master_Sta  XREF[3]:     copy_obj:00451425(c), 
    //                               RGE_Master_Animated_Object::copy_obj                                      copy_obj:00451f39(c), 0057048c(*)  
    //                              m_an_obj.cpp:126 (2)
    //         0044fd40     PUSH       ESI
    //         0044fd41     PUSH       EDI
    //                              m_an_obj.cpp:129 (12)
    //         0044fd42     MOV        EDI,dword ptr [ESP + param_1]
    //         0044fd46     MOV        ESI,this
    //         0044fd48     PUSH       EDI
    //         0044fd49     CALL       RGE_Master_Static_Object::copy_obj               void copy_obj(RGE_Master_Static_Object * this
    //                              m_an_obj.cpp:131 (6)
    //         0044fd4e     MOV        EAX,dword ptr [EDI + 0xb8]
    //                              m_an_obj.cpp:132 (11)
    //         0044fd54     POP        EDI
    //         0044fd55     MOV        dword ptr [ESI + 0xb8],EAX
    //         0044fd5b     POP        ESI
    //         0044fd5c     RET        0x4
}

// Offset: 0x0044FD60
void RGE_Master_Doppleganger_Object::modify(float param_1, uchar param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void __thiscall RGE_Master_Animated_Object::modify(float,unsigned char)               *
    //                              *********************************************************************************************************
    //                              void __thiscall modify(RGE_Master_Animated_Object * this, float para
    //              void              <VOID>         <RETURN>
    //              RGE_Master_Ani    ECX:4 (auto)   this
    //              float             Stack[0x4]:4   param_1                   XREF[2]:     0044fd69(R), 0044fd76(R)  
    //              uchar             Stack[0x8]:1   param_2                   XREF[1]:     0044fd60(R)  
    //                               ?modify@RGE_Master_Animated_Object@@UAEXME@Z                 XREF[3]:     modify:00451fbe(c), 00570490(*), 
    //                               RGE_Master_Animated_Object::modify                                        00570528(*)  
    //                              m_an_obj.cpp:136 (8)
    //         0044fd60     MOV        EAX,dword ptr [ESP + param_2]
    //         0044fd64     CMP        AL,0x5
    //         0044fd66     JZ         LAB_0044fd76
    //                              m_an_obj.cpp:143 (11)
    //         0044fd68     PUSH       EAX
    //         0044fd69     MOV        EAX,dword ptr [ESP + param_1]
    //         0044fd6d     PUSH       EAX
    //         0044fd6e     CALL       RGE_Master_Static_Object::modify                 void modify(RGE_Master_Static_Object * this, 
    //                              m_an_obj.cpp:170 (3)
    //         0044fd73     RET        0x8
    //                               LAB_0044fd76                                                 XREF[1]:     0044fd66(j)  
    //                              m_an_obj.cpp:140 (10)
    //         0044fd76     MOV        EDX,dword ptr [ESP + param_1]
    //         0044fd7a     MOV        dword ptr [ECX + this->speed],EDX
    //                              m_an_obj.cpp:170 (3)
    //         0044fd80     RET        0x8
}

// Offset: 0x0044FD90
void RGE_Master_Doppleganger_Object::modify_delta(float param_1, uchar param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void __thiscall RGE_Master_Animated_Object::modify_delta(float,unsigned char)         *
    //                              *********************************************************************************************************
    //                              void __thiscall modify_delta(RGE_Master_Animated_Object * this, floa
    //              void              <VOID>         <RETURN>
    //              RGE_Master_Ani    ECX:4 (auto)   this
    //              float             Stack[0x4]:4   param_1                   XREF[2]:     0044fd99(R), 0044fda6(R)  
    //              uchar             Stack[0x8]:1   param_2                   XREF[1]:     0044fd90(R)  
    //                               ?modify_delta@RGE_Master_Animated_Object@@UAEXME@Z           XREF[3]:     modify_delta:00451fee(c), 
    //                               RGE_Master_Animated_Object::modify_delta                                  00570494(*), 0057052c(*)  
    //                              m_an_obj.cpp:174 (8)
    //         0044fd90     MOV        EAX,dword ptr [ESP + param_2]
    //         0044fd94     CMP        AL,0x5
    //         0044fd96     JZ         LAB_0044fda6
    //                              m_an_obj.cpp:181 (11)
    //         0044fd98     PUSH       EAX
    //         0044fd99     MOV        EAX,dword ptr [ESP + param_1]
    //         0044fd9d     PUSH       EAX
    //         0044fd9e     CALL       RGE_Master_Static_Object::modify_delta           void modify_delta(RGE_Master_Static_Object * 
    //                              m_an_obj.cpp:208 (3)
    //         0044fda3     RET        0x8
    //                               LAB_0044fda6                                                 XREF[1]:     0044fd96(j)  
    //                              m_an_obj.cpp:178 (16)
    //         0044fda6     FLD        float ptr [ESP + param_1]
    //         0044fdaa     FADD       float ptr [ECX + this->speed]
    //         0044fdb0     FSTP       float ptr [ECX + this->speed]
    //                              m_an_obj.cpp:208 (3)
    //         0044fdb6     RET        0x8
}

// Offset: 0x0044FDC0
void RGE_Master_Doppleganger_Object::modify_percent(float param_1, uchar param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void __thiscall RGE_Master_Animated_Object::modify_percent(float,unsigned char)       *
    //                              *********************************************************************************************************
    //                              void __thiscall modify_percent(RGE_Master_Animated_Object * this, fl
    //              void              <VOID>         <RETURN>
    //              RGE_Master_Ani    ECX:4 (auto)   this
    //              float             Stack[0x4]:4   param_1                   XREF[2]:     0044fdc9(R), 0044fdd6(R)  
    //              uchar             Stack[0x8]:1   param_2                   XREF[1]:     0044fdc0(R)  
    //                               ?modify_percent@RGE_Master_Animated_Object@@UAEXME@Z         XREF[3]:     modify_percent:0045201e(c), 
    //                               RGE_Master_Animated_Object::modify_percent                                00570498(*), 00570530(*)  
    //                              m_an_obj.cpp:212 (8)
    //         0044fdc0     MOV        EAX,dword ptr [ESP + param_2]
    //         0044fdc4     CMP        AL,0x5
    //         0044fdc6     JZ         LAB_0044fdd6
    //                              m_an_obj.cpp:219 (11)
    //         0044fdc8     PUSH       EAX
    //         0044fdc9     MOV        EAX,dword ptr [ESP + param_1]
    //         0044fdcd     PUSH       EAX
    //         0044fdce     CALL       RGE_Master_Static_Object::modify_percent         void modify_percent(RGE_Master_Static_Object 
    //                              m_an_obj.cpp:246 (3)
    //         0044fdd3     RET        0x8
    //                               LAB_0044fdd6                                                 XREF[1]:     0044fdc6(j)  
    //                              m_an_obj.cpp:216 (16)
    //         0044fdd6     FLD        float ptr [ESP + param_1]
    //         0044fdda     FMUL       float ptr [ECX + this->speed]
    //         0044fde0     FSTP       float ptr [ECX + this->speed]
    //                              m_an_obj.cpp:246 (3)
    //         0044fde6     RET        0x8
}

// Offset: 0x0044FDF0
void RGE_Master_Animated_Object::save(int param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void __thiscall RGE_Master_Animated_Object::save(int)                                 *
    //                              *********************************************************************************************************
    //                              void __thiscall save(RGE_Master_Animated_Object * this, int param_1)
    //              void              <VOID>         <RETURN>
    //              RGE_Master_Ani    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0044fdf2(R)  
    //                               ?save@RGE_Master_Animated_Object@@UAEXH@Z                    XREF[3]:     save:00451435(c), 
    //                               RGE_Master_Animated_Object::save                                          save:0045207b(c), 0057049c(*)  
    //                              m_an_obj.cpp:251 (2)
    //         0044fdf0     PUSH       ESI
    //         0044fdf1     PUSH       EDI
    //                              m_an_obj.cpp:252 (12)
    //         0044fdf2     MOV        EDI,dword ptr [ESP + param_1]
    //         0044fdf6     MOV        ESI,this
    //         0044fdf8     PUSH       EDI
    //         0044fdf9     CALL       RGE_Master_Static_Object::save                   void save(RGE_Master_Static_Object * this, in
    //                              m_an_obj.cpp:254 (18)
    //         0044fdfe     ADD        ESI,0xb8
    //         0044fe04     PUSH       0x4
    //         0044fe06     PUSH       ESI
    //         0044fe07     PUSH       EDI
    //         0044fe08     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         0044fe0d     ADD        ESP,0xc
    //                              m_an_obj.cpp:255 (5)
    //         0044fe10     POP        EDI
    //         0044fe11     POP        ESI
    //         0044fe12     RET        0x4
}

