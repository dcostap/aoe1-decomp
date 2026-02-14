// Auto-generated scaffold unit: m_s_obj.cpp.asm
// SourceMap: C:/msdev/work/age1_x1/m_s_obj.cpp
#include "../include/common.h"

// Offset: 0x0044FE20
void RGE_Master_Moving_Object::play_command_sound() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void __thiscall RGE_Master_Static_Object::play_command_sound(void)                    *
    //                              *********************************************************************************************************
    //                              void __thiscall play_command_sound(RGE_Master_Static_Object * this)
    //              void              <VOID>         <RETURN>
    //              RGE_Master_Sta    ECX:4 (auto)   this
    //                               ?play_command_sound@RGE_Master_Static_Object@@UAEXXZ         XREF[5]:     005704b4(*), 0057054c(*), 
    //                               RGE_Master_Static_Object::play_command_sound                              005705cc(*), 00570604(*), 
    //                                                                                                         005767bc(*)  
    //                              m_s_obj.h:210 (1)
    //         0044fe20     RET
}

// Offset: 0x0044FE30
void RGE_Master_Moving_Object::play_move_sound() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void __thiscall RGE_Master_Static_Object::play_move_sound(void)                       *
    //                              *********************************************************************************************************
    //                              void __thiscall play_move_sound(RGE_Master_Static_Object * this)
    //              void              <VOID>         <RETURN>
    //              RGE_Master_Sta    ECX:4 (auto)   this
    //                               ?play_move_sound@RGE_Master_Static_Object@@UAEXXZ            XREF[5]:     005704b8(*), 00570550(*), 
    //                               RGE_Master_Static_Object::play_move_sound                                 005705d0(*), 00570608(*), 
    //                                                                                                         005767c0(*)  
    //                              m_s_obj.h:211 (1)
    //         0044fe30     RET
}

// Offset: 0x00452120
undefined RGE_Master_Static_Object(RGE_Master_Static_Object* this_, RGE_Master_Static_Object* param_2, int param_3) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall RGE_Master_Static_Object::RGE_Master_Static_Object(class RGE_Master_Static_Obje... *
    //                              *********************************************************************************************************
    //                              undefined __thiscall RGE_Master_Static_Object(RGE_Master_Static_Obje
    //              undefined         <UNASSIGNED>   <RETURN>
    //              RGE_Master_Sta    ECX:4 (auto)   this
    //              RGE_Master_Sta    Stack[0x4]:4   param_1                   XREF[1]:     00452131(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     00452120(R)  
    //                               ??0RGE_Master_Static_Object@@QAE@PAV0@H@Z                    XREF[3]:     RGE_Master_Animated_Object:0044f9e
    //                               RGE_Master_Static_Object::RGE_Master_Static_Object                        make_new_master:004530eb(c), 
    //                                                                                                         TRIBE_Master_Tree_Object:0050f1a5(
    //                              m_s_obj.cpp:40 (17)
    //         00452120     MOV        EAX,dword ptr [ESP + param_2]
    //         00452124     PUSH       ESI
    //         00452125     MOV        ESI,this
    //         00452127     TEST       EAX,EAX
    //         00452129     MOV        dword ptr [ESI],RGE_Master_Static_Object::`vft   = 00452150
    //         0045212f     JZ         LAB_0045213b
    //                              m_s_obj.cpp:42 (10)
    //         00452131     MOV        EAX,dword ptr [ESP + param_1]
    //         00452135     PUSH       EAX
    //         00452136     CALL       RGE_Master_Static_Object::setup                  int setup(RGE_Master_Static_Object * this, RG
    //                               LAB_0045213b                                                 XREF[1]:     0045212f(j)  
    //                              m_s_obj.cpp:43 (6)
    //         0045213b     MOV        EAX,ESI
    //         0045213d     POP        ESI
    //         0045213e     RET        0x8
}

// Offset: 0x00452170
undefined RGE_Master_Static_Object(RGE_Master_Static_Object* this_, int param_2, RGE_Sprite** param_3, RGE_Sound** param_4, int param_5) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall RGE_Master_Static_Object::RGE_Master_Static_Object(int,class RGE_Sprite * *,cla... *
    //                              *********************************************************************************************************
    //                              undefined __thiscall RGE_Master_Static_Object(RGE_Master_Static_Obje
    //              undefined         <UNASSIGNED>   <RETURN>
    //              RGE_Master_Sta    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     00452189(R)  
    //              RGE_Sprite * *    Stack[0x8]:4   param_2                   XREF[1]:     00452185(R)  
    //              RGE_Sound * *     Stack[0xc]:4   param_3                   XREF[1]:     00452181(R)  
    //              int               Stack[0x10]:4  param_4                   XREF[1]:     00452170(R)  
    //                               ??0RGE_Master_Static_Object@@QAE@HPAPAVRGE_Sprite@@PAPAVRGE  XREF[4]:     RGE_Master_Animated_Object:0044fa7
    //                               RGE_Master_Static_Object::RGE_Master_Static_Object                        load_master_object:004612e0(c), 
    //                                                                                                         load_master_object:0046fcb0(c), 
    //                                                                                                         TRIBE_Master_Tree_Object:0050f251(
    //                              m_s_obj.cpp:48 (17)
    //         00452170     MOV        EAX,dword ptr [ESP + param_4]
    //         00452174     PUSH       ESI
    //         00452175     MOV        ESI,this
    //         00452177     TEST       EAX,EAX
    //         00452179     MOV        dword ptr [ESI],RGE_Master_Static_Object::`vft   = 00452150
    //         0045217f     JZ         LAB_00452197
    //                              m_s_obj.cpp:50 (22)
    //         00452181     MOV        EAX,dword ptr [ESP + param_3]
    //         00452185     MOV        this,dword ptr [ESP + param_2]
    //         00452189     MOV        EDX,dword ptr [ESP + param_1]
    //         0045218d     PUSH       EAX
    //         0045218e     PUSH       this
    //         0045218f     PUSH       EDX
    //         00452190     MOV        this,ESI
    //         00452192     CALL       RGE_Master_Static_Object::setup                  int setup(RGE_Master_Static_Object * this, in
    //                               LAB_00452197                                                 XREF[1]:     0045217f(j)  
    //                              m_s_obj.cpp:51 (6)
    //         00452197     MOV        EAX,ESI
    //         00452199     POP        ESI
    //         0045219a     RET        0x10
}

// Offset: 0x004521A0
undefined RGE_Master_Static_Object(RGE_Master_Static_Object* this_, FILE* param_2, RGE_Sprite** param_3, RGE_Sound** param_4, short param_5, int param_6) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall RGE_Master_Static_Object::RGE_Master_Static_Object(struct _iobuf *,class RGE_Sp... *
    //                              *********************************************************************************************************
    //                              undefined __thiscall RGE_Master_Static_Object(RGE_Master_Static_Obje
    //              undefined         <UNASSIGNED>   <RETURN>
    //              RGE_Master_Sta    ECX:4 (auto)   this
    //              _iobuf *          Stack[0x4]:4   param_1                   XREF[1]:     004521be(R)  
    //              RGE_Sprite * *    Stack[0x8]:4   param_2                   XREF[1]:     004521b9(R)  
    //              RGE_Sound * *     Stack[0xc]:4   param_3                   XREF[1]:     004521b5(R)  
    //              short             Stack[0x10]:2  param_4                   XREF[1]:     004521b1(R)  
    //              int               Stack[0x14]:4  param_5                   XREF[1]:     004521a0(R)  
    //                               ??0RGE_Master_Static_Object@@QAE@PAU_iobuf@@PAPAVRGE_Sprite  XREF[3]:     RGE_Master_Animated_Object:0044fae
    //                               RGE_Master_Static_Object::RGE_Master_Static_Object                        load_object:004615d6(c), 
    //                                                                                                         TRIBE_Master_Tree_Object:0050f2d6(
    //                              m_s_obj.cpp:56 (17)
    //         004521a0     MOV        EAX,dword ptr [ESP + param_5]
    //         004521a4     PUSH       ESI
    //         004521a5     MOV        ESI,this
    //         004521a7     TEST       EAX,EAX
    //         004521a9     MOV        dword ptr [ESI],RGE_Master_Static_Object::`vft   = 00452150
    //         004521af     JZ         LAB_004521cc
    //                              m_s_obj.cpp:58 (27)
    //         004521b1     MOV        EAX,dword ptr [ESP + param_4]
    //         004521b5     MOV        this,dword ptr [ESP + param_3]
    //         004521b9     MOV        EDX,dword ptr [ESP + param_2]
    //         004521bd     PUSH       EAX
    //         004521be     MOV        EAX,dword ptr [ESP + param_1]
    //         004521c2     PUSH       this
    //         004521c3     PUSH       EDX
    //         004521c4     PUSH       EAX
    //         004521c5     MOV        this,ESI
    //         004521c7     CALL       RGE_Master_Static_Object::setup                  int setup(RGE_Master_Static_Object * this, _i
    //                               LAB_004521cc                                                 XREF[1]:     004521af(j)  
    //                              m_s_obj.cpp:59 (6)
    //         004521cc     MOV        EAX,ESI
    //         004521ce     POP        ESI
    //         004521cf     RET        0x14
}

// Offset: 0x004521E0
int setup(RGE_Master_Static_Object* this_, RGE_Master_Static_Object* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * protected: int __thiscall RGE_Master_Static_Object::setup(class RGE_Master_Static_Object *)           *
    //                              *********************************************************************************************************
    //                              int __thiscall setup(RGE_Master_Static_Object * this, RGE_Master_Sta
    //              int               EAX:4          <RETURN>
    //              RGE_Master_Sta    ECX:4 (auto)   this
    //              RGE_Master_Sta    Stack[0x4]:4   param_1                   XREF[4]:     004521e6(R), 004523f8(W), 00452416(R), 0045241f(W)  
    //                               ?setup@RGE_Master_Static_Object@@IAEHPAV1@@Z                 XREF[3]:     setup:0044fb39(c), 
    //                               RGE_Master_Static_Object::setup                                           RGE_Master_Static_Object:00452136(
    //                                                                                                         TRIBE_Master_Tree_Object:0050f1c3(
    //                              m_s_obj.cpp:65 (6)
    //         004521e0     PUSH       EBX
    //         004521e1     PUSH       EBP
    //         004521e2     PUSH       ESI
    //         004521e3     MOV        ESI,this
    //         004521e5     PUSH       EDI
    //                              m_s_obj.cpp:71 (20)
    //         004521e6     MOV        EDI,dword ptr [ESP + param_1]
    //         004521ea     MOV        byte ptr [ESI + 0x4],0xa
    //         004521ee     MOV        AL,byte ptr [EDI + 0xa4]
    //         004521f4     MOV        byte ptr [ESI + 0xa4],AL
    //                              m_s_obj.cpp:72 (8)
    //         004521fa     MOV        this,word ptr [EDI + 0xc]
    //         004521fe     MOV        word ptr [ESI + 0xc],this
    //                              m_s_obj.cpp:73 (8)
    //         00452202     MOV        DX,word ptr [EDI + 0xe]
    //         00452206     MOV        word ptr [ESI + 0xe],DX
    //                              m_s_obj.cpp:74 (8)
    //         0045220a     MOV        AX,word ptr [EDI + 0x10]
    //         0045220e     MOV        word ptr [ESI + 0x10],AX
    //                              m_s_obj.cpp:75 (4)
    //         00452212     MOV        word ptr [ESI + 0x12],AX
    //                              m_s_obj.cpp:76 (8)
    //         00452216     MOV        AX,word ptr [EDI + 0x14]
    //         0045221a     MOV        word ptr [ESI + 0x14],AX
    //                              m_s_obj.cpp:77 (6)
    //         0045221e     MOV        this,dword ptr [EDI + 0x18]
    //         00452221     MOV        dword ptr [ESI + 0x18],this
    //                              m_s_obj.cpp:78 (6)
    //         00452224     MOV        EDX,dword ptr [EDI + 0x1c]
    //         00452227     MOV        dword ptr [ESI + 0x1c],EDX
    //                              m_s_obj.cpp:79 (6)
    //         0045222a     MOV        EAX,dword ptr [EDI + 0x20]
    //         0045222d     MOV        dword ptr [ESI + 0x20],EAX
    //                              m_s_obj.cpp:80 (6)
    //         00452230     MOV        this,byte ptr [EDI + 0x24]
    //         00452233     MOV        byte ptr [ESI + 0x24],this
    //                              m_s_obj.cpp:81 (8)
    //         00452236     MOV        DX,word ptr [EDI + 0x26]
    //         0045223a     MOV        word ptr [ESI + 0x26],DX
    //                              m_s_obj.cpp:82 (6)
    //         0045223e     MOV        EAX,dword ptr [EDI + 0x28]
    //         00452241     MOV        dword ptr [ESI + 0x28],EAX
    //                              m_s_obj.cpp:83 (6)
    //         00452244     MOV        this,byte ptr [EDI + 0x2c]
    //         00452247     MOV        byte ptr [ESI + 0x2c],this
    //                              m_s_obj.cpp:84 (6)
    //         0045224a     MOV        EDX,dword ptr [EDI + 0x30]
    //         0045224d     MOV        dword ptr [ESI + 0x30],EDX
    //                              m_s_obj.cpp:85 (6)
    //         00452250     MOV        EAX,dword ptr [EDI + 0x34]
    //         00452253     MOV        dword ptr [ESI + 0x34],EAX
    //                              m_s_obj.cpp:86 (6)
    //         00452256     MOV        this,dword ptr [EDI + 0x38]
    //         00452259     MOV        dword ptr [ESI + 0x38],this
    //                              m_s_obj.cpp:87 (6)
    //         0045225c     MOV        EDX,dword ptr [EDI + 0x40]
    //         0045225f     MOV        dword ptr [ESI + 0x40],EDX
    //                              m_s_obj.cpp:88 (8)
    //         00452262     MOV        AX,word ptr [EDI + 0x48]
    //         00452266     MOV        word ptr [ESI + 0x48],AX
    //                              m_s_obj.cpp:89 (6)
    //         0045226a     MOV        this,byte ptr [EDI + 0x4a]
    //         0045226d     MOV        byte ptr [ESI + 0x4a],this
    //                              m_s_obj.cpp:90 (6)
    //         00452270     MOV        DL,byte ptr [EDI + 0x4b]
    //         00452273     MOV        byte ptr [ESI + 0x4b],DL
    //                              m_s_obj.cpp:91 (8)
    //         00452276     MOV        AX,word ptr [EDI + 0x4c]
    //         0045227a     MOV        word ptr [ESI + 0x4c],AX
    //                              m_s_obj.cpp:92 (6)
    //         0045227e     MOV        this,byte ptr [EDI + 0x4e]
    //         00452281     MOV        byte ptr [ESI + 0x4e],this
    //                              m_s_obj.cpp:93 (8)
    //         00452284     MOV        DX,word ptr [EDI + 0x50]
    //         00452288     MOV        word ptr [ESI + 0x50],DX
    //                              m_s_obj.cpp:94 (6)
    //         0045228c     MOV        AL,byte ptr [EDI + 0x52]
    //         0045228f     MOV        byte ptr [ESI + 0x52],AL
    //                              m_s_obj.cpp:95 (8)
    //         00452292     MOV        this,word ptr [EDI + 0x54]
    //         00452296     MOV        word ptr [ESI + 0x54],this
    //                              m_s_obj.cpp:96 (8)
    //         0045229a     MOV        DX,word ptr [EDI + 0x56]
    //         0045229e     MOV        word ptr [ESI + 0x56],DX
    //                              m_s_obj.cpp:97 (8)
    //         004522a2     MOV        AX,word ptr [EDI + 0x58]
    //         004522a6     MOV        word ptr [ESI + 0x58],AX
    //                              m_s_obj.cpp:98 (8)
    //         004522aa     MOV        this,word ptr [EDI + 0x5a]
    //         004522ae     MOV        word ptr [ESI + 0x5a],this
    //                              m_s_obj.cpp:99 (6)
    //         004522b2     MOV        EDX,dword ptr [EDI + 0x5c]
    //         004522b5     MOV        dword ptr [ESI + 0x5c],EDX
    //                              m_s_obj.cpp:100 (6)
    //         004522b8     MOV        EAX,dword ptr [EDI + 0x60]
    //         004522bb     MOV        dword ptr [ESI + 0x60],EAX
    //                              m_s_obj.cpp:101 (6)
    //         004522be     MOV        this,byte ptr [EDI + 0x64]
    //         004522c1     MOV        byte ptr [ESI + 0x64],this
    //                              m_s_obj.cpp:102 (6)
    //         004522c4     MOV        DL,byte ptr [EDI + 0x65]
    //         004522c7     MOV        byte ptr [ESI + 0x65],DL
    //                              m_s_obj.cpp:103 (8)
    //         004522ca     MOV        AX,word ptr [EDI + 0x66]
    //         004522ce     MOV        word ptr [ESI + 0x66],AX
    //                              m_s_obj.cpp:104 (6)
    //         004522d2     MOV        this,byte ptr [EDI + 0x68]
    //         004522d5     MOV        byte ptr [ESI + 0x68],this
    //                              m_s_obj.cpp:105 (8)
    //         004522d8     MOV        DX,word ptr [EDI + 0x7c]
    //         004522dc     MOV        word ptr [ESI + 0x7c],DX
    //                              m_s_obj.cpp:106 (12)
    //         004522e0     MOV        EAX,dword ptr [EDI + 0x80]
    //         004522e6     MOV        dword ptr [ESI + 0x80],EAX
    //                              m_s_obj.cpp:107 (12)
    //         004522ec     MOV        this,byte ptr [EDI + 0x8b]
    //         004522f2     MOV        byte ptr [ESI + 0x8b],this
    //                              m_s_obj.cpp:108 (12)
    //         004522f8     MOV        DL,byte ptr [EDI + 0x8c]
    //         004522fe     MOV        byte ptr [ESI + 0x8c],DL
    //                              m_s_obj.cpp:109 (12)
    //         00452304     MOV        AL,byte ptr [EDI + 0x8d]
    //         0045230a     MOV        byte ptr [ESI + 0x8d],AL
    //                              m_s_obj.cpp:110 (12)
    //         00452310     MOV        this,byte ptr [EDI + 0x8e]
    //         00452316     MOV        byte ptr [ESI + 0x8e],this
    //                              m_s_obj.cpp:111 (12)
    //         0045231c     MOV        DL,byte ptr [EDI + 0x8f]
    //         00452322     MOV        byte ptr [ESI + 0x8f],DL
    //                              m_s_obj.cpp:112 (12)
    //         00452328     MOV        EAX,dword ptr [EDI + 0x84]
    //         0045232e     MOV        dword ptr [ESI + 0x84],EAX
    //                              m_s_obj.cpp:113 (6)
    //         00452334     MOV        this,dword ptr [EDI + 0x3c]
    //         00452337     MOV        dword ptr [ESI + 0x3c],this
    //                              m_s_obj.cpp:114 (6)
    //         0045233a     MOV        EDX,dword ptr [EDI + 0x44]
    //         0045233d     MOV        dword ptr [ESI + 0x44],EDX
    //                              m_s_obj.cpp:115 (12)
    //         00452340     MOV        AL,byte ptr [EDI + 0x91]
    //         00452346     MOV        byte ptr [ESI + 0x91],AL
    //                              m_s_obj.cpp:116 (12)
    //         0045234c     MOV        this,byte ptr [EDI + 0x92]
    //         00452352     MOV        byte ptr [ESI + 0x92],this
    //                              m_s_obj.cpp:117 (12)
    //         00452358     MOV        DL,byte ptr [EDI + 0x90]
    //         0045235e     MOV        byte ptr [ESI + 0x90],DL
    //                              m_s_obj.cpp:118 (12)
    //         00452364     MOV        EAX,dword ptr [EDI + 0x98]
    //         0045236a     MOV        dword ptr [ESI + 0x98],EAX
    //                              m_s_obj.cpp:119 (12)
    //         00452370     MOV        this,dword ptr [EDI + 0x9c]
    //         00452376     MOV        dword ptr [ESI + 0x9c],this
    //                              m_s_obj.cpp:120 (12)
    //         0045237c     MOV        EDX,dword ptr [EDI + 0xa0]
    //         00452382     MOV        dword ptr [ESI + 0xa0],EDX
    //                              m_s_obj.cpp:121 (12)
    //         00452388     MOV        AL,byte ptr [EDI + 0xa5]
    //         0045238e     MOV        byte ptr [ESI + 0xa5],AL
    //                              m_s_obj.cpp:122 (12)
    //         00452394     MOV        this,byte ptr [EDI + 0xa6]
    //         0045239a     MOV        byte ptr [ESI + 0xa6],this
    //                              m_s_obj.cpp:123 (12)
    //         004523a0     MOV        DL,byte ptr [EDI + 0xa7]
    //         004523a6     MOV        byte ptr [ESI + 0xa7],DL
    //                              m_s_obj.cpp:124 (12)
    //         004523ac     MOV        AL,byte ptr [EDI + 0xa8]
    //         004523b2     MOV        byte ptr [ESI + 0xa8],AL
    //                              m_s_obj.cpp:125 (12)
    //         004523b8     MOV        this,byte ptr [EDI + 0xa9]
    //         004523be     MOV        byte ptr [ESI + 0xa9],this
    //                              m_s_obj.cpp:126 (12)
    //         004523c4     MOV        EDX,dword ptr [EDI + 0xac]
    //         004523ca     MOV        dword ptr [ESI + 0xac],EDX
    //                              m_s_obj.cpp:127 (12)
    //         004523d0     MOV        EAX,dword ptr [EDI + 0xb0]
    //         004523d6     MOV        dword ptr [ESI + 0xb0],EAX
    //                              m_s_obj.cpp:128 (6)
    //         004523dc     MOV        this,dword ptr [EDI + 0xb4]
    //                              m_s_obj.cpp:130 (30)
    //         004523e2     MOV        EAX,EDI
    //         004523e4     MOV        dword ptr [ESI + 0xb4],this
    //         004523ea     LEA        EDX,[ESI + 0x88]
    //         004523f0     LEA        EBP,[ESI + 0x70]
    //         004523f3     LEA        this,[ESI + 0x6a]
    //         004523f6     SUB        EAX,ESI
    //         004523f8     MOV        dword ptr [ESP + param_1],0x3
    //                               LAB_00452400                                                 XREF[1]:     00452423(j)  
    //                              m_s_obj.cpp:132 (10)
    //         00452400     MOV        BX,word ptr [EAX + this->_padding_*0x1]
    //         00452404     ADD        EBP,0x4
    //         00452407     MOV        word ptr [this->_padding_],BX
    //                              m_s_obj.cpp:133 (7)
    //         0045240a     MOV        EBX,dword ptr [EAX + EBP*0x1 + -0x4]
    //         0045240e     MOV        dword ptr [EBP + -0x4],EBX
    //                              m_s_obj.cpp:134 (20)
    //         00452411     MOV        BL,byte ptr [EAX + EDX*0x1]
    //         00452414     MOV        byte ptr [EDX],BL
    //         00452416     MOV        EBX,dword ptr [ESP + param_1]
    //         0045241a     ADD        this,0x2
    //         0045241d     INC        EDX
    //         0045241e     DEC        EBX
    //         0045241f     MOV        dword ptr [ESP + param_1],EBX
    //         00452423     JNZ        LAB_00452400
    //                              m_s_obj.cpp:138 (6)
    //         00452425     MOV        AL,byte ptr [EDI + 0x93]
    //                              m_s_obj.cpp:139 (10)
    //         0045242b     TEST       AL,AL
    //         0045242d     MOV        byte ptr [ESI + 0x93],AL
    //         00452433     JBE        LAB_004524a7
    //                              m_s_obj.cpp:141 (19)
    //         00452435     AND        EAX,0xff
    //         0045243a     PUSH       0x8
    //         0045243c     PUSH       EAX
    //         0045243d     CALL       calloc                                           undefined calloc()
    //         00452442     MOV        dword ptr [ESI + 0x94],EAX
    //                              m_s_obj.cpp:142 (15)
    //         00452448     MOV        AL,byte ptr [ESI + 0x93]
    //         0045244e     ADD        ESP,0x8
    //         00452451     XOR        this,this
    //         00452453     TEST       AL,AL
    //         00452455     JBE        LAB_004524b1
    //                               LAB_00452457                                                 XREF[1]:     004524a3(j)  
    //                              m_s_obj.cpp:144 (25)
    //         00452457     MOV        EDX,dword ptr [EDI + 0x94]
    //         0045245d     MOV        EBX,dword ptr [ESI + 0x94]
    //         00452463     MOVSX      EAX,this
    //         00452466     SHL        EAX,0x3
    //         00452469     INC        this
    //         0045246a     MOV        EDX,dword ptr [EDX + EAX*0x1]
    //         0045246d     MOV        dword ptr [EBX + EAX*0x1],EDX
    //                              m_s_obj.cpp:145 (20)
    //         00452470     MOV        EDX,dword ptr [EDI + 0x94]
    //         00452476     MOV        EBX,dword ptr [ESI + 0x94]
    //         0045247c     MOV        DL,byte ptr [EDX + EAX*0x1 + 0x4]
    //         00452480     MOV        byte ptr [EBX + EAX*0x1 + 0x4],DL
    //                              m_s_obj.cpp:146 (33)
    //         00452484     MOV        EDX,dword ptr [EDI + 0x94]
    //         0045248a     MOV        EBX,dword ptr [ESI + 0x94]
    //         00452490     MOV        DL,byte ptr [EDX + EAX*0x1 + 0x5]
    //         00452494     MOV        byte ptr [EBX + EAX*0x1 + 0x5],DL
    //         00452498     MOVZX      AX,byte ptr [ESI + 0x93]
    //         004524a0     CMP        this,AX
    //         004524a3     JL         LAB_00452457
    //                              m_s_obj.cpp:149 (2)
    //         004524a5     JMP        LAB_004524b1
    //                               LAB_004524a7                                                 XREF[1]:     00452433(j)  
    //                              m_s_obj.cpp:150 (10)
    //         004524a7     MOV        dword ptr [ESI + 0x94],0x0
    //                               LAB_004524b1                                                 XREF[2]:     00452455(j), 004524a5(j)  
    //                              m_s_obj.cpp:153 (9)
    //         004524b1     LEA        EAX,[ESI + 0x8]
    //         004524b4     MOV        dword ptr [EAX],0x0
    //                              m_s_obj.cpp:154 (13)
    //         004524ba     MOV        this,dword ptr [EDI + 0x8]
    //         004524bd     PUSH       this
    //         004524be     PUSH       EAX
    //         004524bf     CALL       getstring                                        void getstring(char * * param_1, char * param
    //         004524c4     ADD        ESP,0x8
    //                              m_s_obj.cpp:156 (5)
    //         004524c7     MOV        EAX,0x1
    //                              m_s_obj.cpp:157 (7)
    //         004524cc     POP        EDI
    //         004524cd     POP        ESI
    //         004524ce     POP        EBP
    //         004524cf     POP        EBX
    //         004524d0     RET        0x4
}

// Offset: 0x004524E0
int setup(RGE_Master_Static_Object* this_, int param_2, RGE_Sprite** param_3, RGE_Sound** param_4) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * protected: int __thiscall RGE_Master_Static_Object::setup(int,class RGE_Sprite * *,class RGE_Sound... *
    //                              *********************************************************************************************************
    //                              int __thiscall setup(RGE_Master_Static_Object * this, int param_1, R
    //              int               EAX:4          <RETURN>
    //              RGE_Master_Sta    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[4]:     004524e3(*), 004524ea(R), 004529ed(R), 00452a05(R)  
    //              RGE_Sprite * *    Stack[0x8]:4   param_2                   XREF[3]:     0045297b(R), 00452a99(R), 00452aa5(R)  
    //              RGE_Sound * *     Stack[0xc]:4   param_3                   XREF[1]:     00452a4b(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[3]:     004528a9(W), 004528da(R), 004528ed(W)  
    //              undefined4        Stack[-0x8]:4  local_8                   XREF[4]:     004528a2(W), 004528c6(R), 004528d6(R), 004528e9(W)  
    //              undefined2        Stack[-0xa]:2  local_a                   XREF[2]:     0045255d(*), 00452ac5(R)  
    //              undefined2        Stack[-0xc]:2  local_c                   XREF[2]:     0045254d(*), 00452aae(R)  
    //              short             Stack[-0xe]:2  undead_sprite_num         XREF[2]:     0045253d(*), 00452a8f(R)  
    //              short             Stack[-0x10]:2 death_sprite_num          XREF[2]:     004525d6(*), 00452a78(R)  
    //              short             Stack[-0x12]:2 sprite_num                XREF[2]:     004529bc(*), 00452a61(R)  
    //              short             Stack[-0x14]:2 created_sound_num         XREF[2]:     004529ac(*), 00452a46(R)  
    //              short             Stack[-0x16]:2 death_sound_num           XREF[2]:     0045292f(*), 0045296e(R)  
    //              short             Stack[-0x18]:2 selected_sound_num
    //              short             Stack[-0x1a]:2 temp_damage_sprite
    //                               ?setup@RGE_Master_Static_Object@@IAEHHPAPAVRGE_Sprite@@PAPA  XREF[3]:     setup:0044fb75(c), 
    //                               RGE_Master_Static_Object::setup                                           RGE_Master_Static_Object:00452192(
    //                                                                                                         TRIBE_Master_Tree_Object:0050f271(
    //                              m_s_obj.cpp:162 (3)
    //         004524e0     SUB        ESP,0x18
    //                              m_s_obj.cpp:176 (30)
    //         004524e3     LEA        EAX=>param_1,[ESP + 0x1c]
    //         004524e7     PUSH       EBX
    //         004524e8     PUSH       EBP
    //         004524e9     PUSH       ESI
    //         004524ea     MOV        ESI,dword ptr [ESP + param_1]
    //         004524ee     PUSH       EDI
    //         004524ef     MOV        EDI,this
    //         004524f1     PUSH       0x2
    //         004524f3     PUSH       EAX
    //         004524f4     PUSH       ESI
    //         004524f5     MOV        byte ptr [EDI + 0x4],0xa
    //         004524f9     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         004524fe     ADD        ESP,0xc
    //                              m_s_obj.cpp:177 (15)
    //         00452501     LEA        this,[EDI + 0x10]
    //         00452504     PUSH       0x2
    //         00452506     PUSH       this
    //         00452507     PUSH       ESI
    //         00452508     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0045250d     ADD        ESP,0xc
    //                              m_s_obj.cpp:178 (15)
    //         00452510     LEA        EDX,[EDI + 0xc]
    //         00452513     PUSH       0x2
    //         00452515     PUSH       EDX
    //         00452516     PUSH       ESI
    //         00452517     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0045251c     ADD        ESP,0xc
    //                              m_s_obj.cpp:179 (15)
    //         0045251f     LEA        EAX,[EDI + 0xe]
    //         00452522     PUSH       0x2
    //         00452524     PUSH       EAX
    //         00452525     PUSH       ESI
    //         00452526     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0045252b     ADD        ESP,0xc
    //                              m_s_obj.cpp:180 (15)
    //         0045252e     LEA        this,[EDI + 0x14]
    //         00452531     PUSH       0x2
    //         00452533     PUSH       this
    //         00452534     PUSH       ESI
    //         00452535     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0045253a     ADD        ESP,0xc
    //                              m_s_obj.cpp:181 (16)
    //         0045253d     LEA        EDX=>undead_sprite_num,[ESP + 0x1a]
    //         00452541     PUSH       0x2
    //         00452543     PUSH       EDX
    //         00452544     PUSH       ESI
    //         00452545     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0045254a     ADD        ESP,0xc
    //                              m_s_obj.cpp:182 (16)
    //         0045254d     LEA        EAX=>local_c,[ESP + 0x1c]
    //         00452551     PUSH       0x2
    //         00452553     PUSH       EAX
    //         00452554     PUSH       ESI
    //         00452555     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0045255a     ADD        ESP,0xc
    //                              m_s_obj.cpp:183 (16)
    //         0045255d     LEA        this=>local_a,[ESP + 0x1e]
    //         00452561     PUSH       0x2
    //         00452563     PUSH       this
    //         00452564     PUSH       ESI
    //         00452565     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0045256a     ADD        ESP,0xc
    //                              m_s_obj.cpp:184 (15)
    //         0045256d     LEA        EDX,[EDI + 0x24]
    //         00452570     PUSH       0x1
    //         00452572     PUSH       EDX
    //         00452573     PUSH       ESI
    //         00452574     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         00452579     ADD        ESP,0xc
    //                              m_s_obj.cpp:185 (15)
    //         0045257c     LEA        EAX,[EDI + 0x26]
    //         0045257f     PUSH       0x2
    //         00452581     PUSH       EAX
    //         00452582     PUSH       ESI
    //         00452583     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         00452588     ADD        ESP,0xc
    //                              m_s_obj.cpp:186 (15)
    //         0045258b     LEA        this,[EDI + 0x28]
    //         0045258e     PUSH       0x4
    //         00452590     PUSH       this
    //         00452591     PUSH       ESI
    //         00452592     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         00452597     ADD        ESP,0xc
    //                              m_s_obj.cpp:187 (15)
    //         0045259a     LEA        EDX,[EDI + 0x2c]
    //         0045259d     PUSH       0x1
    //         0045259f     PUSH       EDX
    //         004525a0     PUSH       ESI
    //         004525a1     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         004525a6     ADD        ESP,0xc
    //                              m_s_obj.cpp:188 (15)
    //         004525a9     LEA        EBX,[EDI + 0x30]
    //         004525ac     PUSH       0x4
    //         004525ae     PUSH       EBX
    //         004525af     PUSH       ESI
    //         004525b0     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         004525b5     ADD        ESP,0xc
    //                              m_s_obj.cpp:189 (15)
    //         004525b8     LEA        EBP,[EDI + 0x34]
    //         004525bb     PUSH       0x4
    //         004525bd     PUSH       EBP
    //         004525be     PUSH       ESI
    //         004525bf     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         004525c4     ADD        ESP,0xc
    //                              m_s_obj.cpp:190 (15)
    //         004525c7     LEA        EAX,[EDI + 0x38]
    //         004525ca     PUSH       0x4
    //         004525cc     PUSH       EAX
    //         004525cd     PUSH       ESI
    //         004525ce     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         004525d3     ADD        ESP,0xc
    //                              m_s_obj.cpp:191 (16)
    //         004525d6     LEA        EAX=>death_sprite_num,[ESP + 0x18]
    //         004525da     PUSH       0x2
    //         004525dc     PUSH       EAX
    //         004525dd     PUSH       ESI
    //         004525de     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         004525e3     ADD        ESP,0xc
    //                              m_s_obj.cpp:192 (15)
    //         004525e6     LEA        this,[EDI + 0x48]
    //         004525e9     PUSH       0x2
    //         004525eb     PUSH       this
    //         004525ec     PUSH       ESI
    //         004525ed     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         004525f2     ADD        ESP,0xc
    //                              m_s_obj.cpp:193 (15)
    //         004525f5     LEA        EDX,[EDI + 0x4a]
    //         004525f8     PUSH       0x1
    //         004525fa     PUSH       EDX
    //         004525fb     PUSH       ESI
    //         004525fc     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         00452601     ADD        ESP,0xc
    //                              m_s_obj.cpp:194 (15)
    //         00452604     LEA        EAX,[EDI + 0x4b]
    //         00452607     PUSH       0x1
    //         00452609     PUSH       EAX
    //         0045260a     PUSH       ESI
    //         0045260b     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         00452610     ADD        ESP,0xc
    //                              m_s_obj.cpp:195 (15)
    //         00452613     LEA        this,[EDI + 0x4c]
    //         00452616     PUSH       0x2
    //         00452618     PUSH       this
    //         00452619     PUSH       ESI
    //         0045261a     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0045261f     ADD        ESP,0xc
    //                              m_s_obj.cpp:196 (15)
    //         00452622     LEA        EDX,[EDI + 0x4e]
    //         00452625     PUSH       0x1
    //         00452627     PUSH       EDX
    //         00452628     PUSH       ESI
    //         00452629     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0045262e     ADD        ESP,0xc
    //                              m_s_obj.cpp:197 (15)
    //         00452631     LEA        EAX,[EDI + 0x50]
    //         00452634     PUSH       0x2
    //         00452636     PUSH       EAX
    //         00452637     PUSH       ESI
    //         00452638     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0045263d     ADD        ESP,0xc
    //                              m_s_obj.cpp:198 (15)
    //         00452640     LEA        this,[EDI + 0x52]
    //         00452643     PUSH       0x1
    //         00452645     PUSH       this
    //         00452646     PUSH       ESI
    //         00452647     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0045264c     ADD        ESP,0xc
    //                              m_s_obj.cpp:199 (15)
    //         0045264f     LEA        EDX,[EDI + 0x54]
    //         00452652     PUSH       0x2
    //         00452654     PUSH       EDX
    //         00452655     PUSH       ESI
    //         00452656     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0045265b     ADD        ESP,0xc
    //                              m_s_obj.cpp:200 (15)
    //         0045265e     LEA        EAX,[EDI + 0x56]
    //         00452661     PUSH       0x2
    //         00452663     PUSH       EAX
    //         00452664     PUSH       ESI
    //         00452665     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0045266a     ADD        ESP,0xc
    //                              m_s_obj.cpp:201 (15)
    //         0045266d     LEA        this,[EDI + 0x58]
    //         00452670     PUSH       0x2
    //         00452672     PUSH       this
    //         00452673     PUSH       ESI
    //         00452674     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         00452679     ADD        ESP,0xc
    //                              m_s_obj.cpp:202 (15)
    //         0045267c     LEA        EDX,[EDI + 0x5a]
    //         0045267f     PUSH       0x2
    //         00452681     PUSH       EDX
    //         00452682     PUSH       ESI
    //         00452683     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         00452688     ADD        ESP,0xc
    //                              m_s_obj.cpp:203 (15)
    //         0045268b     LEA        EAX,[EDI + 0x5c]
    //         0045268e     PUSH       0x4
    //         00452690     PUSH       EAX
    //         00452691     PUSH       ESI
    //         00452692     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         00452697     ADD        ESP,0xc
    //                              m_s_obj.cpp:204 (15)
    //         0045269a     LEA        this,[EDI + 0x60]
    //         0045269d     PUSH       0x4
    //         0045269f     PUSH       this
    //         004526a0     PUSH       ESI
    //         004526a1     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         004526a6     ADD        ESP,0xc
    //                              m_s_obj.cpp:205 (15)
    //         004526a9     LEA        EDX,[EDI + 0x64]
    //         004526ac     PUSH       0x1
    //         004526ae     PUSH       EDX
    //         004526af     PUSH       ESI
    //         004526b0     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         004526b5     ADD        ESP,0xc
    //                              m_s_obj.cpp:206 (15)
    //         004526b8     LEA        EAX,[EDI + 0x65]
    //         004526bb     PUSH       0x1
    //         004526bd     PUSH       EAX
    //         004526be     PUSH       ESI
    //         004526bf     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         004526c4     ADD        ESP,0xc
    //                              m_s_obj.cpp:207 (15)
    //         004526c7     LEA        this,[EDI + 0x66]
    //         004526ca     PUSH       0x2
    //         004526cc     PUSH       this
    //         004526cd     PUSH       ESI
    //         004526ce     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         004526d3     ADD        ESP,0xc
    //                              m_s_obj.cpp:208 (15)
    //         004526d6     LEA        EDX,[EDI + 0x68]
    //         004526d9     PUSH       0x1
    //         004526db     PUSH       EDX
    //         004526dc     PUSH       ESI
    //         004526dd     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         004526e2     ADD        ESP,0xc
    //                              m_s_obj.cpp:209 (15)
    //         004526e5     LEA        EAX,[EDI + 0x7c]
    //         004526e8     PUSH       0x2
    //         004526ea     PUSH       EAX
    //         004526eb     PUSH       ESI
    //         004526ec     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         004526f1     ADD        ESP,0xc
    //                              m_s_obj.cpp:210 (18)
    //         004526f4     LEA        this,[EDI + 0x80]
    //         004526fa     PUSH       0x4
    //         004526fc     PUSH       this
    //         004526fd     PUSH       ESI
    //         004526fe     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         00452703     ADD        ESP,0xc
    //                              m_s_obj.cpp:211 (18)
    //         00452706     LEA        EDX,[EDI + 0x8b]
    //         0045270c     PUSH       0x1
    //         0045270e     PUSH       EDX
    //         0045270f     PUSH       ESI
    //         00452710     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         00452715     ADD        ESP,0xc
    //                              m_s_obj.cpp:212 (18)
    //         00452718     LEA        EAX,[EDI + 0x8c]
    //         0045271e     PUSH       0x1
    //         00452720     PUSH       EAX
    //         00452721     PUSH       ESI
    //         00452722     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         00452727     ADD        ESP,0xc
    //                              m_s_obj.cpp:213 (18)
    //         0045272a     LEA        this,[EDI + 0x8d]
    //         00452730     PUSH       0x1
    //         00452732     PUSH       this
    //         00452733     PUSH       ESI
    //         00452734     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         00452739     ADD        ESP,0xc
    //                              m_s_obj.cpp:214 (18)
    //         0045273c     LEA        EDX,[EDI + 0x8e]
    //         00452742     PUSH       0x1
    //         00452744     PUSH       EDX
    //         00452745     PUSH       ESI
    //         00452746     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0045274b     ADD        ESP,0xc
    //                              m_s_obj.cpp:215 (18)
    //         0045274e     PUSH       0x1
    //         00452750     LEA        EAX,[EDI + 0x8f]
    //         00452756     PUSH       EAX
    //         00452757     PUSH       ESI
    //         00452758     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0045275d     ADD        ESP,0xc
    //                              m_s_obj.cpp:216 (18)
    //         00452760     LEA        this,[EDI + 0x84]
    //         00452766     PUSH       0x4
    //         00452768     PUSH       this
    //         00452769     PUSH       ESI
    //         0045276a     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0045276f     ADD        ESP,0xc
    //                              m_s_obj.cpp:217 (18)
    //         00452772     LEA        EDX,[EDI + 0x90]
    //         00452778     PUSH       0x1
    //         0045277a     PUSH       EDX
    //         0045277b     PUSH       ESI
    //         0045277c     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         00452781     ADD        ESP,0xc
    //                              m_s_obj.cpp:218 (18)
    //         00452784     LEA        EAX,[EDI + 0x98]
    //         0045278a     PUSH       0x4
    //         0045278c     PUSH       EAX
    //         0045278d     PUSH       ESI
    //         0045278e     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         00452793     ADD        ESP,0xc
    //                              m_s_obj.cpp:219 (18)
    //         00452796     LEA        this,[EDI + 0x9c]
    //         0045279c     PUSH       0x4
    //         0045279e     PUSH       this
    //         0045279f     PUSH       ESI
    //         004527a0     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         004527a5     ADD        ESP,0xc
    //                              m_s_obj.cpp:220 (18)
    //         004527a8     LEA        EDX,[EDI + 0xa0]
    //         004527ae     PUSH       0x4
    //         004527b0     PUSH       EDX
    //         004527b1     PUSH       ESI
    //         004527b2     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         004527b7     ADD        ESP,0xc
    //                              m_s_obj.cpp:221 (18)
    //         004527ba     LEA        EAX,[EDI + 0xa4]
    //         004527c0     PUSH       0x1
    //         004527c2     PUSH       EAX
    //         004527c3     PUSH       ESI
    //         004527c4     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         004527c9     ADD        ESP,0xc
    //                              m_s_obj.cpp:222 (18)
    //         004527cc     LEA        this,[EDI + 0xa5]
    //         004527d2     PUSH       0x1
    //         004527d4     PUSH       this
    //         004527d5     PUSH       ESI
    //         004527d6     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         004527db     ADD        ESP,0xc
    //                              m_s_obj.cpp:223 (18)
    //         004527de     LEA        EDX,[EDI + 0xa6]
    //         004527e4     PUSH       0x1
    //         004527e6     PUSH       EDX
    //         004527e7     PUSH       ESI
    //         004527e8     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         004527ed     ADD        ESP,0xc
    //                              m_s_obj.cpp:224 (15)
    //         004527f0     LEA        EAX,[EDI + 0xa7]
    //         004527f6     PUSH       0x1
    //         004527f8     PUSH       EAX
    //         004527f9     PUSH       ESI
    //         004527fa     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //                              m_s_obj.cpp:226 (22)
    //         004527ff     FLD        float ptr [save_game_version]                    = 7.23
    //         00452805     FCOMP      float ptr [DAT_00570610]                         = AEh
    //         0045280b     ADD        ESP,0xc
    //         0045280e     FNSTSW     AX
    //         00452810     TEST       AH,0x1
    //         00452813     JNZ        LAB_00452871
    //                              m_s_obj.cpp:228 (18)
    //         00452815     LEA        this,[EDI + 0xa8]
    //         0045281b     PUSH       0x1
    //         0045281d     PUSH       this
    //         0045281e     PUSH       ESI
    //         0045281f     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         00452824     ADD        ESP,0xc
    //                              m_s_obj.cpp:229 (18)
    //         00452827     LEA        EDX,[EDI + 0xa9]
    //         0045282d     PUSH       0x1
    //         0045282f     PUSH       EDX
    //         00452830     PUSH       ESI
    //         00452831     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         00452836     ADD        ESP,0xc
    //                              m_s_obj.cpp:230 (18)
    //         00452839     LEA        EAX,[EDI + 0xac]
    //         0045283f     PUSH       0x4
    //         00452841     PUSH       EAX
    //         00452842     PUSH       ESI
    //         00452843     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         00452848     ADD        ESP,0xc
    //                              m_s_obj.cpp:231 (18)
    //         0045284b     LEA        this,[EDI + 0xb0]
    //         00452851     PUSH       0x4
    //         00452853     PUSH       this
    //         00452854     PUSH       ESI
    //         00452855     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0045285a     ADD        ESP,0xc
    //                              m_s_obj.cpp:232 (18)
    //         0045285d     LEA        EDX,[EDI + 0xb4]
    //         00452863     PUSH       0x4
    //         00452865     PUSH       EDX
    //         00452866     PUSH       ESI
    //         00452867     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0045286c     ADD        ESP,0xc
    //                              m_s_obj.cpp:234 (2)
    //         0045286f     JMP        LAB_00452899
    //                               LAB_00452871                                                 XREF[1]:     00452813(j)  
    //                              m_s_obj.cpp:238 (2)
    //         00452871     MOV        EAX,dword ptr [EBX]
    //                              m_s_obj.cpp:239 (3)
    //         00452873     MOV        this,dword ptr [EBP]
    //                              m_s_obj.cpp:240 (35)
    //         00452876     MOV        EDX,dword ptr [EDI + 0x38]
    //         00452879     MOV        byte ptr [EDI + 0xa8],0x0
    //         00452880     MOV        byte ptr [EDI + 0xa9],0x0
    //         00452887     MOV        dword ptr [EDI + 0xac],EAX
    //         0045288d     MOV        dword ptr [EDI + 0xb0],this
    //         00452893     MOV        dword ptr [EDI + 0xb4],EDX
    //                               LAB_00452899                                                 XREF[1]:     0045286f(j)  
    //                              m_s_obj.cpp:243 (24)
    //         00452899     LEA        EAX,[EDI + 0x88]
    //         0045289f     LEA        EBX,[EDI + 0x70]
    //         004528a2     MOV        dword ptr [ESP + local_8],EAX
    //         004528a6     LEA        EBP,[EDI + 0x6a]
    //         004528a9     MOV        dword ptr [ESP + local_4],0x3
    //                               LAB_004528b1                                                 XREF[1]:     004528f1(j)  
    //                              m_s_obj.cpp:245 (12)
    //         004528b1     PUSH       0x2
    //         004528b3     PUSH       EBP
    //         004528b4     PUSH       ESI
    //         004528b5     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         004528ba     ADD        ESP,0xc
    //                              m_s_obj.cpp:246 (9)
    //         004528bd     PUSH       0x4
    //         004528bf     PUSH       EBX
    //         004528c0     PUSH       ESI
    //         004528c1     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //                              m_s_obj.cpp:247 (45)
    //         004528c6     MOV        this,dword ptr [ESP + local_8]
    //         004528ca     ADD        ESP,0xc
    //         004528cd     PUSH       0x1
    //         004528cf     PUSH       this
    //         004528d0     PUSH       ESI
    //         004528d1     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         004528d6     MOV        this,dword ptr [ESP + local_8]
    //         004528da     MOV        EAX,dword ptr [ESP + local_4]
    //         004528de     ADD        ESP,0xc
    //         004528e1     ADD        EBP,0x2
    //         004528e4     ADD        EBX,0x4
    //         004528e7     INC        this
    //         004528e8     DEC        EAX
    //         004528e9     MOV        dword ptr [ESP + local_8],this
    //         004528ed     MOV        dword ptr [ESP + local_4],EAX
    //         004528f1     JNZ        LAB_004528b1
    //                              m_s_obj.cpp:250 (15)
    //         004528f3     LEA        EBP,[EDI + 0x93]
    //         004528f9     PUSH       0x1
    //         004528fb     PUSH       EBP
    //         004528fc     PUSH       ESI
    //         004528fd     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //                              m_s_obj.cpp:251 (14)
    //         00452902     MOV        AL,byte ptr [EBP]
    //         00452905     ADD        ESP,0xc
    //         00452908     TEST       AL,AL
    //         0045290a     JBE        LAB_004529a2
    //                              m_s_obj.cpp:253 (19)
    //         00452910     AND        EAX,0xff
    //         00452915     PUSH       0x8
    //         00452917     PUSH       EAX
    //         00452918     CALL       calloc                                           undefined calloc()
    //         0045291d     MOV        dword ptr [EDI + 0x94],EAX
    //                              m_s_obj.cpp:254 (12)
    //         00452923     MOV        AL,byte ptr [EBP]
    //         00452926     ADD        ESP,0x8
    //         00452929     XOR        EBX,EBX
    //         0045292b     TEST       AL,AL
    //         0045292d     JBE        LAB_004529ac
    //                               LAB_0045292f                                                 XREF[1]:     0045299e(j)  
    //                              m_s_obj.cpp:256 (13)
    //         0045292f     LEA        EDX=>death_sound_num,[ESP + 0x12]
    //         00452933     PUSH       0x2
    //         00452935     PUSH       EDX
    //         00452936     PUSH       ESI
    //         00452937     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //                              m_s_obj.cpp:257 (28)
    //         0045293c     MOV        EAX,dword ptr [EDI + 0x94]
    //         00452942     ADD        ESP,0xc
    //         00452945     MOVSX      EBP,BX
    //         00452948     SHL        EBP,0x3
    //         0045294b     PUSH       0x2
    //         0045294d     LEA        this,[EAX + EBP*0x1 + 0x4]
    //         00452951     PUSH       this
    //         00452952     PUSH       ESI
    //         00452953     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //                              m_s_obj.cpp:258 (22)
    //         00452958     MOV        EDX,dword ptr [EDI + 0x94]
    //         0045295e     ADD        ESP,0xc
    //         00452961     LEA        EAX,[EDX + EBP*0x1 + 0x5]
    //         00452965     PUSH       0x1
    //         00452967     PUSH       EAX
    //         00452968     PUSH       ESI
    //         00452969     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //                              m_s_obj.cpp:260 (50)
    //         0045296e     MOV        AX,word ptr [ESP + death_sound_num]
    //         00452973     ADD        ESP,0xc
    //         00452976     TEST       AX,AX
    //         00452979     JL         LAB_00452987
    //         0045297b     MOV        EDX,dword ptr [ESP + param_2]
    //         0045297f     MOVSX      this,AX
    //         00452982     MOV        EAX,dword ptr [EDX + this->_padding_*0x4]
    //         00452985     JMP        LAB_00452989
    //                               LAB_00452987                                                 XREF[1]:     00452979(j)  
    //         00452987     XOR        EAX,EAX
    //                               LAB_00452989                                                 XREF[1]:     00452985(j)  
    //         00452989     MOV        this,dword ptr [EDI + 0x94]
    //         0045298f     INC        EBX
    //         00452990     MOV        dword ptr [this->_padding_ + EBP*0x1],EAX
    //         00452993     MOVZX      DX,byte ptr [EDI + 0x93]
    //         0045299b     CMP        BX,DX
    //         0045299e     JL         LAB_0045292f
    //                              m_s_obj.cpp:263 (2)
    //         004529a0     JMP        LAB_004529ac
    //                               LAB_004529a2                                                 XREF[1]:     0045290a(j)  
    //                              m_s_obj.cpp:264 (10)
    //         004529a2     MOV        dword ptr [EDI + 0x94],0x0
    //                               LAB_004529ac                                                 XREF[2]:     0045292d(j), 004529a0(j)  
    //                              m_s_obj.cpp:266 (16)
    //         004529ac     LEA        EAX=>created_sound_num,[ESP + 0x14]
    //         004529b0     PUSH       0x2
    //         004529b2     PUSH       EAX
    //         004529b3     PUSH       ESI
    //         004529b4     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         004529b9     ADD        ESP,0xc
    //                              m_s_obj.cpp:267 (16)
    //         004529bc     LEA        this=>sprite_num,[ESP + 0x16]
    //         004529c0     PUSH       0x2
    //         004529c2     PUSH       this
    //         004529c3     PUSH       ESI
    //         004529c4     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         004529c9     ADD        ESP,0xc
    //                              m_s_obj.cpp:268 (18)
    //         004529cc     LEA        EDX,[EDI + 0x91]
    //         004529d2     PUSH       0x1
    //         004529d4     PUSH       EDX
    //         004529d5     PUSH       ESI
    //         004529d6     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         004529db     ADD        ESP,0xc
    //                              m_s_obj.cpp:269 (15)
    //         004529de     LEA        EAX,[EDI + 0x92]
    //         004529e4     PUSH       0x1
    //         004529e6     PUSH       EAX
    //         004529e7     PUSH       ESI
    //         004529e8     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //                              m_s_obj.cpp:272 (13)
    //         004529ed     MOV        AX,word ptr [ESP + param_1]
    //         004529f2     ADD        ESP,0xc
    //         004529f5     TEST       AX,AX
    //         004529f8     JLE        LAB_00452a1d
    //                              m_s_obj.cpp:274 (11)
    //         004529fa     MOVSX      this,AX
    //         004529fd     PUSH       0x1
    //         004529ff     PUSH       this
    //         00452a00     CALL       calloc                                           undefined calloc()
    //                              m_s_obj.cpp:275 (22)
    //         00452a05     MOVSX      EDX,word ptr [ESP + param_1]
    //         00452a0a     ADD        ESP,0x8
    //         00452a0d     MOV        dword ptr [EDI + 0x8],EAX
    //         00452a10     PUSH       EDX
    //         00452a11     PUSH       EAX
    //         00452a12     PUSH       ESI
    //         00452a13     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         00452a18     ADD        ESP,0xc
    //                              m_s_obj.cpp:277 (2)
    //         00452a1b     JMP        LAB_00452a24
    //                               LAB_00452a1d                                                 XREF[1]:     004529f8(j)  
    //                              m_s_obj.cpp:278 (7)
    //         00452a1d     MOV        dword ptr [EDI + 0x8],0x0
    //                               LAB_00452a24                                                 XREF[1]:     00452a1b(j)  
    //                              m_s_obj.cpp:280 (19)
    //         00452a24     FLD        float ptr [save_game_version]                    = 7.23
    //         00452a2a     FCOMP      float ptr [DAT_00570614]                         = 0Ah
    //         00452a30     FNSTSW     AX
    //         00452a32     TEST       AH,0x1
    //         00452a35     JNZ        LAB_00452a46
    //                              m_s_obj.cpp:281 (15)
    //         00452a37     LEA        EAX,[EDI + 0x12]
    //         00452a3a     PUSH       0x2
    //         00452a3c     PUSH       EAX
    //         00452a3d     PUSH       ESI
    //         00452a3e     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         00452a43     ADD        ESP,0xc
    //                               LAB_00452a46                                                 XREF[1]:     00452a35(j)  
    //                              m_s_obj.cpp:284 (27)
    //         00452a46     MOV        AX,word ptr [ESP + created_sound_num]
    //         00452a4b     MOV        this,dword ptr [ESP + param_3]
    //         00452a4f     TEST       AX,AX
    //         00452a52     JL         LAB_00452a5c
    //         00452a54     MOVSX      EDX,AX
    //         00452a57     MOV        EAX,dword ptr [this->_padding_ + EDX*0x4]
    //         00452a5a     JMP        LAB_00452a5e
    //                               LAB_00452a5c                                                 XREF[1]:     00452a52(j)  
    //         00452a5c     XOR        EAX,EAX
    //                               LAB_00452a5e                                                 XREF[1]:     00452a5a(j)  
    //         00452a5e     MOV        dword ptr [EDI + 0x3c],EAX
    //                              m_s_obj.cpp:285 (23)
    //         00452a61     MOV        AX,word ptr [ESP + sprite_num]
    //         00452a66     TEST       AX,AX
    //         00452a69     JL         LAB_00452a73
    //         00452a6b     MOVSX      EAX,AX
    //         00452a6e     MOV        EAX,dword ptr [this->_padding_ + EAX*0x4]
    //         00452a71     JMP        LAB_00452a75
    //                               LAB_00452a73                                                 XREF[1]:     00452a69(j)  
    //         00452a73     XOR        EAX,EAX
    //                               LAB_00452a75                                                 XREF[1]:     00452a71(j)  
    //         00452a75     MOV        dword ptr [EDI + 0x44],EAX
    //                              m_s_obj.cpp:286 (23)
    //         00452a78     MOV        AX,word ptr [ESP + death_sprite_num]
    //         00452a7d     TEST       AX,AX
    //         00452a80     JL         LAB_00452a8a
    //         00452a82     MOVSX      EDX,AX
    //         00452a85     MOV        EAX,dword ptr [this->_padding_ + EDX*0x4]
    //         00452a88     JMP        LAB_00452a8c
    //                               LAB_00452a8a                                                 XREF[1]:     00452a80(j)  
    //         00452a8a     XOR        EAX,EAX
    //                               LAB_00452a8c                                                 XREF[1]:     00452a88(j)  
    //         00452a8c     MOV        dword ptr [EDI + 0x40],EAX
    //                              m_s_obj.cpp:289 (31)
    //         00452a8f     MOV        AX,word ptr [ESP + undead_sprite_num]
    //         00452a94     TEST       AX,AX
    //         00452a97     JL         LAB_00452aa5
    //         00452a99     MOV        this,dword ptr [ESP + param_2]
    //         00452a9d     MOVSX      EAX,AX
    //         00452aa0     MOV        EAX,dword ptr [this->_padding_ + EAX*0x4]
    //         00452aa3     JMP        LAB_00452aab
    //                               LAB_00452aa5                                                 XREF[1]:     00452a97(j)  
    //         00452aa5     MOV        this,dword ptr [ESP + param_2]
    //         00452aa9     XOR        EAX,EAX
    //                               LAB_00452aab                                                 XREF[1]:     00452aa3(j)  
    //         00452aab     MOV        dword ptr [EDI + 0x18],EAX
    //                              m_s_obj.cpp:290 (23)
    //         00452aae     MOV        AX,word ptr [ESP + local_c]
    //         00452ab3     TEST       AX,AX
    //         00452ab6     JL         LAB_00452ac0
    //         00452ab8     MOVSX      EDX,AX
    //         00452abb     MOV        EAX,dword ptr [this->_padding_ + EDX*0x4]
    //         00452abe     JMP        LAB_00452ac2
    //                               LAB_00452ac0                                                 XREF[1]:     00452ab6(j)  
    //         00452ac0     XOR        EAX,EAX
    //                               LAB_00452ac2                                                 XREF[1]:     00452abe(j)  
    //         00452ac2     MOV        dword ptr [EDI + 0x1c],EAX
    //                              m_s_obj.cpp:291 (19)
    //         00452ac5     MOV        AX,word ptr [ESP + local_a]
    //         00452aca     TEST       AX,AX
    //         00452acd     JL         LAB_00452ae7
    //         00452acf     MOVSX      EAX,AX
    //         00452ad2     MOV        EAX,dword ptr [this->_padding_ + EAX*0x4]
    //         00452ad5     MOV        dword ptr [EDI + 0x20],EAX
    //                              m_s_obj.cpp:293 (5)
    //         00452ad8     MOV        EAX,0x1
    //                              m_s_obj.cpp:294 (10)
    //         00452add     POP        EDI
    //         00452ade     POP        ESI
    //         00452adf     POP        EBP
    //         00452ae0     POP        EBX
    //         00452ae1     ADD        ESP,0x18
    //         00452ae4     RET        0xc
    //                               LAB_00452ae7                                                 XREF[1]:     00452acd(j)  
    //                              m_s_obj.cpp:291 (5)
    //         00452ae7     XOR        EAX,EAX
    //         00452ae9     MOV        dword ptr [EDI + 0x20],EAX
    //                              m_s_obj.cpp:294 (15)
    //         00452aec     POP        EDI
    //         00452aed     POP        ESI
    //         00452aee     POP        EBP
    //         00452aef     MOV        EAX,0x1
    //         00452af4     POP        EBX
    //         00452af5     ADD        ESP,0x18
    //         00452af8     RET        0xc
}

// Offset: 0x00452B00
int setup(RGE_Master_Static_Object* this_, FILE* param_2, RGE_Sprite** param_3, RGE_Sound** param_4, short param_5) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * protected: int __thiscall RGE_Master_Static_Object::setup(struct _iobuf *,class RGE_Sprite * *,cla... *
    //                              *********************************************************************************************************
    //                              int __thiscall setup(RGE_Master_Static_Object * this, _iobuf * param
    //              int               EAX:4          <RETURN>
    //              RGE_Master_Sta    ECX:4 (auto)   this
    //              _iobuf *          Stack[0x4]:4   param_1                   XREF[3]:     00452c3f(R), 00452c74(R), 00452ca9(R)  
    //              RGE_Sprite * *    Stack[0x8]:4   param_2                   XREF[1]:     00452cc4(R)  
    //              RGE_Sound * *     Stack[0xc]:4   param_3                   XREF[1]:     00452d98(R)  
    //              short             Stack[0x10]:2  param_4                   XREF[1]:     00452b06(R)  
    //              char[120]         Stack[-0x7c]   temp_name                 XREF[2,3]:   00452cb0(*), 00452cc0(R), 00452c46(*), 00452f63(*), 
    //                                                                                     00452f76(*)  
    //              short             Stack[-0x80]:2 temp_damage_sprite_num    XREF[3]:     00452c6c(W), 00452c91(R), 00452ca3(W)  
    //              undefined         Stack[-0x82]:1 local_82                  XREF[2]:     00452d02(*), 00452d45(R)  
    //              undefined         Stack[-0x84]:1 local_84                  XREF[2]:     00452bab(*), 00452e27(R)  
    //              short             Stack[-0x86]:2 temp_damage_percent       XREF[2]:     00452bed(*), 00452e4b(R)  
    //              short             Stack[-0x88]:2 temp_elevation_flag       XREF[2]:     00452b31(*), 00452ef0(R)  
    //              short             Stack[-0x8a]:2 temp_can_be_built_on      XREF[2]:     00452b96(*), 00452dcb(R)  
    //              short             Stack[-0x8c]:2 temp_draw_color           XREF[2]:     00452b35(*), 00452ec3(R)  
    //              short             Stack[-0x8e]:2 temp_created_sound        XREF[2]:     00452b8e(*), 00452e3d(R)  
    //              short             Stack[-0x90]:2 temp_draw_flag            XREF[2]:     00452b3a(*), 00452ee6(R)  
    //              short             Stack[-0x92]:2 temp_movement_type        XREF[2]:     00452c07(*), 00452e36(R)  
    //              short             Stack[-0x94]:2 temp_resource_group       XREF[2]:     00452b3f(*), 00452ed4(R)  
    //              short             Stack[-0x96]:2 temp_obj_max              XREF[2]:     00452c26(*), 00452df9(R)  
    //              short             Stack[-0x98]:2 temp_create_doppleganger  XREF[2]:     00452b44(*), 00452ea8(R)  
    //              short             Stack[-0x9a]:2 temp_death_sprite         XREF[2]:     00452d82(*), 00452d93(R)  
    //              short             Stack[-0x9c]:2 temp_track_as_resource    XREF[2]:     00452b5e(*), 00452eca(R)  
    //              short             Stack[-0x9e]:2 temp_selected_sound       XREF[2]:     00452c7b(*), 00452c8d(R)  
    //              short             Stack[-0xa0]:2 temp_map_color            XREF[2]:     00452d74(*), 00452eb9(R)  
    //              short             Stack[-0xa2]:2 temp_attribute_flag       XREF[2]:     00452bcb(*), 00452e6a(R)  
    //              short             Stack[-0xa4]:2 temp_convert_terrain_flag XREF[2]:     00452d78(*), 00452e8a(R)  
    //              short             Stack[-0xa6]:2 temp_available            XREF[2]:     00452bf4(*), 00452e32(R)  
    //              short             Stack[-0xa8]:2 temp_attack_reaction      XREF[2]:     00452bd7(*), 00452eb2(R)  
    //              short             Stack[-0xaa]:2 temp_sort_number          XREF[2]:     00452ba3(*), 00452e2b(R)  
    //              short             Stack[-0xac]:2 temp_hide_in_scenario_ed  XREF[2]:     00452c16(*), 00452e9e(R)  
    //              short             Stack[-0xae]:2 temp_fog_flag             XREF[2]:     00452c1e(*), 00452e10(R)  
    //              short             Stack[-0xb0]:2 temp_undead_flag          XREF[2]:     00452b9e(*), 00452e58(R)  
    //              short             Stack[-0xb2]:2 temp_undead_sprite        XREF[2]:     00452c2e(*), 00452de2(R)  
    //              short             Stack[-0xb4]:2 temp_terrain              XREF[2]:     00452b63(*), 00452e94(R)  
    //              short             Stack[-0xb6]:2 temp_sprite               XREF[2]:     00452d7d(*), 00452db4(R)  
    //              short             Stack[-0xb8]:2 temp_command_level        XREF[2]:     00452b68(*), 00452e82(R)  
    //              short             Stack[-0xba]:2 temp_death_sound          XREF[2]:     00452cfe(*), 00452d53(R)  
    //              short             Stack[-0xbc]:2 temp_map_draw_level       XREF[2]:     00452b6d(*), 00452e44(R)  
    //              short             Stack[-0xbe]:2 temp_flag                 XREF[2]:     00452d07(*), 00452d18(R)  
    //              short             Stack[-0xc0]:2 temp_select_level         XREF[2]:     00452b72(*), 00452e78(R)  
    //              short             Stack[-0xc2]:2 temp_damage_sprite        XREF[2]:     00452b77(*), 00452e71(R)  
    //              short             Stack[-0xc4]:2 temp_combat_level
    //              short             Stack[-0xc6]:2 temp_area_effect_object_
    //                               ?setup@RGE_Master_Static_Object@@IAEHPAU_iobuf@@PAPAVRGE_Sp  XREF[3]:     setup:0044fbba(c), 
    //                               RGE_Master_Static_Object::setup                                           RGE_Master_Static_Object:004521c7(
    //                                                                                                         TRIBE_Master_Tree_Object:0050f2fb(
    //                              m_s_obj.cpp:299 (6)
    //         00452b00     SUB        ESP,0xc4
    //                              m_s_obj.cpp:339 (22)
    //         00452b06     MOV        AX,word ptr [ESP + param_4]
    //         00452b0e     PUSH       EBX
    //         00452b0f     PUSH       EBP
    //         00452b10     PUSH       ESI
    //         00452b11     MOV        ESI,this
    //         00452b13     PUSH       EDI
    //         00452b14     MOV        byte ptr [ESI + 0x4],0xa
    //         00452b18     MOV        word ptr [ESI + 0x10],AX
    //                              m_s_obj.cpp:394 (344)
    //         00452b1c     LEA        EAX,[ESI + 0xb4]
    //         00452b22     LEA        this,[ESI + 0xb0]
    //         00452b28     PUSH       EAX
    //         00452b29     LEA        EDX,[ESI + 0xac]
    //         00452b2f     PUSH       this
    //         00452b30     PUSH       EDX
    //         00452b31     LEA        this=>temp_elevation_flag,[ESP + 0x58]
    //         00452b35     LEA        EDX=>temp_draw_color,[ESP + 0x54]
    //         00452b39     PUSH       this
    //         00452b3a     LEA        EAX=>temp_draw_flag,[ESP + 0x54]
    //         00452b3e     PUSH       EDX
    //         00452b3f     LEA        this=>temp_resource_group,[ESP + 0x54]
    //         00452b43     PUSH       EAX
    //         00452b44     LEA        EDX=>temp_create_doppleganger_on_death,[ESP + 
    //         00452b48     PUSH       this
    //         00452b49     LEA        EAX,[ESI + 0xa0]
    //         00452b4f     PUSH       EDX
    //         00452b50     LEA        this,[ESI + 0x9c]
    //         00452b56     PUSH       EAX
    //         00452b57     LEA        EDX,[ESI + 0x98]
    //         00452b5d     PUSH       this
    //         00452b5e     LEA        EAX=>temp_track_as_resource,[ESP + 0x60]
    //         00452b62     PUSH       EDX
    //         00452b63     LEA        this=>temp_terrain,[ESP + 0x4c]
    //         00452b67     PUSH       EAX
    //         00452b68     LEA        EDX=>temp_command_level,[ESP + 0x4c]
    //         00452b6c     PUSH       this
    //         00452b6d     LEA        EAX=>temp_map_draw_level,[ESP + 0x4c]
    //         00452b71     PUSH       EDX
    //         00452b72     LEA        this=>temp_select_level,[ESP + 0x4c]
    //         00452b76     PUSH       EAX
    //         00452b77     LEA        EDX=>temp_damage_sprite,[ESP + 0x4e]
    //         00452b7b     PUSH       this
    //         00452b7c     LEA        EAX,[ESI + 0x80]
    //         00452b82     PUSH       EDX
    //         00452b83     LEA        this,[ESI + 0x84]
    //         00452b89     PUSH       EAX
    //         00452b8a     LEA        EDX,[ESI + 0x7c]
    //         00452b8d     PUSH       this
    //         00452b8e     LEA        EAX=>temp_created_sound,[ESP + 0x92]
    //         00452b95     PUSH       EDX
    //         00452b96     LEA        this=>temp_can_be_built_on,[ESP + 0x9a]
    //         00452b9d     PUSH       EAX
    //         00452b9e     LEA        EDX=>temp_undead_flag,[ESP + 0x78]
    //         00452ba2     PUSH       this
    //         00452ba3     LEA        EAX=>temp_sort_number,[ESP + 0x82]
    //         00452baa     PUSH       EDX
    //         00452bab     LEA        this=>local_84,[ESP + 0xac]
    //         00452bb2     PUSH       EAX
    //         00452bb3     LEA        EDX,[ESI + 0x60]
    //         00452bb6     PUSH       this
    //         00452bb7     LEA        EAX,[ESI + 0x5c]
    //         00452bba     PUSH       EDX
    //         00452bbb     LEA        this,[ESI + 0x5a]
    //         00452bbe     PUSH       EAX
    //         00452bbf     LEA        EDX,[ESI + 0x58]
    //         00452bc2     PUSH       this
    //         00452bc3     LEA        EAX,[ESI + 0x56]
    //         00452bc6     PUSH       EDX
    //         00452bc7     LEA        this,[ESI + 0x54]
    //         00452bca     PUSH       EAX
    //         00452bcb     LEA        EDX=>temp_attribute_flag,[ESP + 0xaa]
    //         00452bd2     PUSH       this
    //         00452bd3     LEA        EAX,[ESI + 0x50]
    //         00452bd6     PUSH       EDX
    //         00452bd7     LEA        this=>temp_attack_reaction,[ESP + 0xac]
    //         00452bde     PUSH       EAX
    //         00452bdf     LEA        EDX,[ESI + 0x4c]
    //         00452be2     PUSH       this
    //         00452be3     LEA        EDI,[ESI + 0x38]
    //         00452be6     LEA        EBX,[ESI + 0x34]
    //         00452be9     LEA        EBP,[ESI + 0x14]
    //         00452bec     PUSH       EDX
    //         00452bed     LEA        EAX=>temp_damage_percent,[ESP + 0xda]
    //         00452bf4     LEA        this=>temp_available,[ESP + 0xba]
    //         00452bfb     PUSH       EAX
    //         00452bfc     LEA        EDX,[ESI + 0x48]
    //         00452bff     PUSH       this
    //         00452c00     PUSH       EDX
    //         00452c01     PUSH       EDI
    //         00452c02     LEA        EAX,[ESI + 0x30]
    //         00452c05     PUSH       EBX
    //         00452c06     PUSH       EAX
    //         00452c07     LEA        EAX=>temp_movement_type,[ESP + 0xe6]
    //         00452c0e     LEA        this,[ESI + 0x28]
    //         00452c11     PUSH       EAX
    //         00452c12     LEA        EDX,[ESI + 0x26]
    //         00452c15     PUSH       this
    //         00452c16     LEA        EAX=>temp_hide_in_scenario_editor,[ESP + 0xd4]
    //         00452c1d     PUSH       EDX
    //         00452c1e     LEA        this=>temp_fog_flag,[ESP + 0xd6]
    //         00452c25     PUSH       EAX
    //         00452c26     LEA        EDX=>temp_obj_max,[ESP + 0xf2]
    //         00452c2d     PUSH       this
    //         00452c2e     LEA        EAX=>temp_undead_sprite,[ESP + 0xda]
    //         00452c35     PUSH       EDX
    //         00452c36     PUSH       EAX
    //         00452c37     LEA        this,[ESI + 0xe]
    //         00452c3a     PUSH       EBP
    //         00452c3b     LEA        EDX,[ESI + 0xc]
    //         00452c3e     PUSH       this
    //         00452c3f     MOV        this,dword ptr [ESP + param_1]
    //         00452c46     LEA        EAX=>temp_name[4],[ESP + 0x124]
    //         00452c4d     PUSH       EDX
    //         00452c4e     PUSH       EAX
    //         00452c4f     PUSH       s_%s_%hd_%hd_%hd_%hd_%hd_%hd_%hd_%               = "%s %hd %hd %hd %hd %hd %hd %hd %hd %f %hd 
    //         00452c54     PUSH       this
    //         00452c55     CALL       fscanf                                           undefined fscanf()
    //         00452c5a     ADD        ESP,0xd8
    //         00452c60     LEA        EBP,[ESI + 0x88]
    //         00452c66     LEA        EBX,[ESI + 0x6a]
    //         00452c69     LEA        EDI,[ESI + 0x70]
    //         00452c6c     MOV        dword ptr [ESP + temp_damage_sprite_num],0x3
    //                               LAB_00452c74                                                 XREF[1]:     00452ca7(j)  
    //                              m_s_obj.cpp:403 (25)
    //         00452c74     MOV        EAX,dword ptr [ESP + param_1]
    //         00452c7b     LEA        EDX=>temp_selected_sound,[ESP + 0x36]
    //         00452c7f     PUSH       EDX
    //         00452c80     PUSH       EDI
    //         00452c81     PUSH       EBX
    //         00452c82     PUSH       s_%hd_%f_%hd                                     = "%hd %f %hd"
    //         00452c87     PUSH       EAX
    //         00452c88     CALL       fscanf                                           undefined fscanf()
    //                              m_s_obj.cpp:404 (28)
    //         00452c8d     MOV        this,byte ptr [ESP + temp_selected_sound]
    //         00452c91     MOV        EAX,dword ptr [ESP + temp_damage_sprite_num]
    //         00452c95     ADD        ESP,0x14
    //         00452c98     MOV        byte ptr [EBP],this
    //         00452c9b     ADD        EDI,0x4
    //         00452c9e     ADD        EBX,0x2
    //         00452ca1     INC        EBP
    //         00452ca2     DEC        EAX
    //         00452ca3     MOV        dword ptr [ESP + temp_damage_sprite_num],EAX
    //         00452ca7     JNZ        LAB_00452c74
    //                              m_s_obj.cpp:407 (23)
    //         00452ca9     MOV        EBP,dword ptr [ESP + param_1]
    //         00452cb0     LEA        EDX=>temp_name,[ESP + 0x58]
    //         00452cb4     PUSH       EDX
    //         00452cb5     PUSH       s_%hd                                            = "%hd"
    //         00452cba     PUSH       EBP
    //         00452cbb     CALL       fscanf                                           undefined fscanf()
    //                              m_s_obj.cpp:408 (4)
    //         00452cc0     MOV        EAX,dword ptr [ESP + temp_name[0]]
    //                              m_s_obj.cpp:409 (24)
    //         00452cc4     MOV        EBX,dword ptr [ESP + param_2]
    //         00452ccb     ADD        ESP,0xc
    //         00452cce     MOV        byte ptr [ESI + 0x93],AL
    //         00452cd4     TEST       AL,AL
    //         00452cd6     JBE        LAB_00452d6a
    //                              m_s_obj.cpp:411 (19)
    //         00452cdc     AND        EAX,0xff
    //         00452ce1     PUSH       0x8
    //         00452ce3     PUSH       EAX
    //         00452ce4     CALL       calloc                                           undefined calloc()
    //         00452ce9     MOV        dword ptr [ESI + 0x94],EAX
    //                              m_s_obj.cpp:412 (15)
    //         00452cef     MOV        AL,byte ptr [ESI + 0x93]
    //         00452cf5     ADD        ESP,0x8
    //         00452cf8     XOR        EDI,EDI
    //         00452cfa     TEST       AL,AL
    //         00452cfc     JBE        LAB_00452d74
    //                               LAB_00452cfe                                                 XREF[1]:     00452d66(j)  
    //                              m_s_obj.cpp:414 (26)
    //         00452cfe     LEA        EAX=>temp_death_sound,[ESP + 0x1a]
    //         00452d02     LEA        this=>local_82,[ESP + 0x52]
    //         00452d06     PUSH       EAX
    //         00452d07     LEA        EDX=>temp_flag,[ESP + 0x1a]
    //         00452d0b     PUSH       this
    //         00452d0c     PUSH       EDX
    //         00452d0d     PUSH       s_%hd_%hd_%hd                                    = "%hd %hd %hd"
    //         00452d12     PUSH       EBP
    //         00452d13     CALL       fscanf                                           undefined fscanf()
    //                              m_s_obj.cpp:416 (39)
    //         00452d18     MOV        AX,word ptr [ESP + temp_flag]
    //         00452d1d     ADD        ESP,0x14
    //         00452d20     TEST       AX,AX
    //         00452d23     JL         LAB_00452d2d
    //         00452d25     MOVSX      EAX,AX
    //         00452d28     MOV        this,dword ptr [EBX + EAX*0x4]
    //         00452d2b     JMP        LAB_00452d2f
    //                               LAB_00452d2d                                                 XREF[1]:     00452d23(j)  
    //         00452d2d     XOR        this,this
    //                               LAB_00452d2f                                                 XREF[1]:     00452d2b(j)  
    //         00452d2f     MOV        EDX,dword ptr [ESI + 0x94]
    //         00452d35     MOVSX      EAX,DI
    //         00452d38     SHL        EAX,0x3
    //         00452d3b     INC        EDI
    //         00452d3c     MOV        dword ptr [EAX + EDX*0x1],this
    //                              m_s_obj.cpp:417 (14)
    //         00452d3f     MOV        this,dword ptr [ESI + 0x94]
    //         00452d45     MOV        DL,byte ptr [ESP + local_82]
    //         00452d49     MOV        byte ptr [EAX + this->_padding_*0x1 + 0x4],DL
    //                              m_s_obj.cpp:418 (27)
    //         00452d4d     MOV        this,dword ptr [ESI + 0x94]
    //         00452d53     MOV        DL,byte ptr [ESP + temp_death_sound]
    //         00452d57     MOV        byte ptr [EAX + this->_padding_*0x1 + 0x5],DL
    //         00452d5b     MOVZX      AX,byte ptr [ESI + 0x93]
    //         00452d63     CMP        DI,AX
    //         00452d66     JL         LAB_00452cfe
    //                              m_s_obj.cpp:421 (2)
    //         00452d68     JMP        LAB_00452d74
    //                               LAB_00452d6a                                                 XREF[1]:     00452cd6(j)  
    //                              m_s_obj.cpp:422 (10)
    //         00452d6a     MOV        dword ptr [ESI + 0x94],0x0
    //                               LAB_00452d74                                                 XREF[2]:     00452cfc(j), 00452d68(j)  
    //                              m_s_obj.cpp:429 (31)
    //         00452d74     LEA        this=>temp_map_color,[ESP + 0x34]
    //         00452d78     LEA        EDX=>temp_convert_terrain_flag,[ESP + 0x30]
    //         00452d7c     PUSH       this
    //         00452d7d     LEA        EAX=>temp_sprite,[ESP + 0x22]
    //         00452d81     PUSH       EDX
    //         00452d82     LEA        this=>temp_death_sprite,[ESP + 0x42]
    //         00452d86     PUSH       EAX
    //         00452d87     PUSH       this
    //         00452d88     PUSH       s_%hd_%hd_%hd_%hd                                = "%hd %hd %hd %hd"
    //         00452d8d     PUSH       EBP
    //         00452d8e     CALL       fscanf                                           undefined fscanf()
    //                              m_s_obj.cpp:432 (33)
    //         00452d93     MOV        AX,word ptr [ESP + temp_death_sprite]
    //         00452d98     MOV        this,dword ptr [ESP + param_3]
    //         00452d9f     ADD        ESP,0x18
    //         00452da2     TEST       AX,AX
    //         00452da5     JL         LAB_00452daf
    //         00452da7     MOVSX      EDX,AX
    //         00452daa     MOV        EAX,dword ptr [this->_padding_ + EDX*0x4]
    //         00452dad     JMP        LAB_00452db1
    //                               LAB_00452daf                                                 XREF[1]:     00452da5(j)  
    //         00452daf     XOR        EAX,EAX
    //                               LAB_00452db1                                                 XREF[1]:     00452dad(j)  
    //         00452db1     MOV        dword ptr [ESI + 0x3c],EAX
    //                              m_s_obj.cpp:433 (23)
    //         00452db4     MOV        AX,word ptr [ESP + temp_sprite]
    //         00452db9     TEST       AX,AX
    //         00452dbc     JL         LAB_00452dc6
    //         00452dbe     MOVSX      EAX,AX
    //         00452dc1     MOV        EAX,dword ptr [this->_padding_ + EAX*0x4]
    //         00452dc4     JMP        LAB_00452dc8
    //                               LAB_00452dc6                                                 XREF[1]:     00452dbc(j)  
    //         00452dc6     XOR        EAX,EAX
    //                               LAB_00452dc8                                                 XREF[1]:     00452dc4(j)  
    //         00452dc8     MOV        dword ptr [ESI + 0x44],EAX
    //                              m_s_obj.cpp:434 (23)
    //         00452dcb     MOV        AX,word ptr [ESP + temp_can_be_built_on]
    //         00452dd0     TEST       AX,AX
    //         00452dd3     JL         LAB_00452ddd
    //         00452dd5     MOVSX      EDX,AX
    //         00452dd8     MOV        EAX,dword ptr [this->_padding_ + EDX*0x4]
    //         00452ddb     JMP        LAB_00452ddf
    //                               LAB_00452ddd                                                 XREF[1]:     00452dd3(j)  
    //         00452ddd     XOR        EAX,EAX
    //                               LAB_00452ddf                                                 XREF[1]:     00452ddb(j)  
    //         00452ddf     MOV        dword ptr [ESI + 0x40],EAX
    //                              m_s_obj.cpp:437 (23)
    //         00452de2     MOV        AX,word ptr [ESP + temp_undead_sprite]
    //         00452de7     TEST       AX,AX
    //         00452dea     JL         LAB_00452df4
    //         00452dec     MOVSX      EAX,AX
    //         00452def     MOV        EAX,dword ptr [EBX + EAX*0x4]
    //         00452df2     JMP        LAB_00452df6
    //                               LAB_00452df4                                                 XREF[1]:     00452dea(j)  
    //         00452df4     XOR        EAX,EAX
    //                               LAB_00452df6                                                 XREF[1]:     00452df2(j)  
    //         00452df6     MOV        dword ptr [ESI + 0x18],EAX
    //                              m_s_obj.cpp:438 (23)
    //         00452df9     MOV        AX,word ptr [ESP + temp_obj_max]
    //         00452dfe     TEST       AX,AX
    //         00452e01     JL         LAB_00452e0b
    //         00452e03     MOVSX      this,AX
    //         00452e06     MOV        EAX,dword ptr [EBX + this->_padding_*0x4]
    //         00452e09     JMP        LAB_00452e0d
    //                               LAB_00452e0b                                                 XREF[1]:     00452e01(j)  
    //         00452e0b     XOR        EAX,EAX
    //                               LAB_00452e0d                                                 XREF[1]:     00452e09(j)  
    //         00452e0d     MOV        dword ptr [ESI + 0x1c],EAX
    //                              m_s_obj.cpp:439 (23)
    //         00452e10     MOV        AX,word ptr [ESP + temp_fog_flag]
    //         00452e15     TEST       AX,AX
    //         00452e18     JL         LAB_00452e22
    //         00452e1a     MOVSX      EDX,AX
    //         00452e1d     MOV        EAX,dword ptr [EBX + EDX*0x4]
    //         00452e20     JMP        LAB_00452e24
    //                               LAB_00452e22                                                 XREF[1]:     00452e18(j)  
    //         00452e22     XOR        EAX,EAX
    //                               LAB_00452e24                                                 XREF[1]:     00452e20(j)  
    //         00452e24     MOV        dword ptr [ESI + 0x20],EAX
    //                              m_s_obj.cpp:442 (4)
    //         00452e27     MOV        AL,byte ptr [ESP + local_84]
    //                              m_s_obj.cpp:443 (7)
    //         00452e2b     MOV        this,byte ptr [ESP + temp_sort_number]
    //         00452e2f     MOV        byte ptr [ESI + 0x64],AL
    //                              m_s_obj.cpp:445 (11)
    //         00452e32     MOV        AL,byte ptr [ESP + temp_available]
    //         00452e36     MOV        DL,byte ptr [ESP + temp_movement_type]
    //         00452e3a     MOV        byte ptr [ESI + 0x4a],AL
    //                              m_s_obj.cpp:448 (7)
    //         00452e3d     MOV        AL,byte ptr [ESP + temp_created_sound]
    //         00452e41     MOV        byte ptr [ESI + 0x68],AL
    //                              m_s_obj.cpp:451 (20)
    //         00452e44     MOV        AL,byte ptr [ESP + temp_map_draw_level]
    //         00452e48     MOV        byte ptr [ESI + 0x65],this
    //         00452e4b     MOV        this,byte ptr [ESP + temp_damage_percent]
    //         00452e4f     MOV        byte ptr [ESI + 0x8d],AL
    //         00452e55     MOV        byte ptr [ESI + 0x2c],DL
    //                              m_s_obj.cpp:454 (6)
    //         00452e58     MOVZX      AX,byte ptr [ESP + temp_undead_flag]
    //                              m_s_obj.cpp:465 (176)
    //         00452e5e     FLD        float ptr [ESI + 0xac]
    //         00452e64     FCOMP      float ptr [DAT_00570618]
    //         00452e6a     MOV        DL,byte ptr [ESP + temp_attribute_flag]
    //         00452e6e     MOV        byte ptr [ESI + 0x4b],this
    //         00452e71     MOV        this,byte ptr [ESP + temp_damage_sprite]
    //         00452e75     MOV        byte ptr [ESI + 0x52],DL
    //         00452e78     MOV        DL,byte ptr [ESP + temp_select_level]
    //         00452e7c     MOV        byte ptr [ESI + 0x8b],this
    //         00452e82     MOV        this,byte ptr [ESP + temp_command_level]
    //         00452e86     MOV        word ptr [ESI + 0x66],AX
    //         00452e8a     MOV        AL,byte ptr [ESP + temp_convert_terrain_flag]
    //         00452e8e     MOV        byte ptr [ESI + 0x8c],DL
    //         00452e94     MOV        DL,byte ptr [ESP + temp_terrain]
    //         00452e98     MOV        byte ptr [ESI + 0x8e],this
    //         00452e9e     MOV        this,byte ptr [ESP + temp_hide_in_scenario_edi
    //         00452ea2     MOV        byte ptr [ESI + 0x91],AL
    //         00452ea8     MOV        AL,byte ptr [ESP + temp_create_doppleganger_on
    //         00452eac     MOV        byte ptr [ESI + 0x8f],DL
    //         00452eb2     MOV        DL,byte ptr [ESP + temp_attack_reaction]
    //         00452eb6     MOV        byte ptr [ESI + 0x24],this
    //         00452eb9     MOV        this,byte ptr [ESP + temp_map_color]
    //         00452ebd     MOV        byte ptr [ESI + 0xa5],AL
    //         00452ec3     MOV        AL,byte ptr [ESP + temp_draw_color]
    //         00452ec7     MOV        byte ptr [ESI + 0x4e],DL
    //         00452eca     MOV        DL,byte ptr [ESP + temp_track_as_resource]
    //         00452ece     MOV        byte ptr [ESI + 0x92],this
    //         00452ed4     MOV        this,byte ptr [ESP + temp_resource_group]
    //         00452ed8     MOV        byte ptr [ESI + 0xa8],AL
    //         00452ede     FNSTSW     AX
    //         00452ee0     MOV        byte ptr [ESI + 0x90],DL
    //         00452ee6     MOV        DL,byte ptr [ESP + temp_draw_flag]
    //         00452eea     MOV        byte ptr [ESI + 0xa6],this
    //         00452ef0     MOV        this,byte ptr [ESP + temp_elevation_flag]
    //         00452ef4     TEST       AH,0x40
    //         00452ef7     MOV        byte ptr [ESI + 0xa7],DL
    //         00452efd     MOV        byte ptr [ESI + 0xa9],this
    //         00452f03     JZ         LAB_00452f0e
    //         00452f05     MOV        EDX,dword ptr [ESI + 0x30]
    //         00452f08     MOV        dword ptr [ESI + 0xac],EDX
    //                               LAB_00452f0e                                                 XREF[1]:     00452f03(j)  
    //                              m_s_obj.cpp:466 (28)
    //         00452f0e     FLD        float ptr [ESI + 0xb0]
    //         00452f14     FCOMP      float ptr [DAT_00570618]
    //         00452f1a     FNSTSW     AX
    //         00452f1c     TEST       AH,0x40
    //         00452f1f     JZ         LAB_00452f2a
    //         00452f21     MOV        EAX,dword ptr [ESI + 0x34]
    //         00452f24     MOV        dword ptr [ESI + 0xb0],EAX
    //                               LAB_00452f2a                                                 XREF[1]:     00452f1f(j)  
    //                              m_s_obj.cpp:467 (28)
    //         00452f2a     FLD        float ptr [ESI + 0xb4]
    //         00452f30     FCOMP      float ptr [DAT_00570618]
    //         00452f36     FNSTSW     AX
    //         00452f38     TEST       AH,0x40
    //         00452f3b     JZ         LAB_00452f46
    //         00452f3d     MOV        this,dword ptr [ESI + 0x38]
    //         00452f40     MOV        dword ptr [ESI + 0xb4],this
    //                               LAB_00452f46                                                 XREF[1]:     00452f3b(j)  
    //                              m_s_obj.cpp:470 (4)
    //         00452f46     MOV        DX,word ptr [ESI + 0x10]
    //                              m_s_obj.cpp:473 (18)
    //         00452f4a     CMP        word ptr [ESI + 0x14],0xb
    //         00452f4f     MOV        byte ptr [ESI + 0xa4],0x0
    //         00452f56     MOV        word ptr [ESI + 0x12],DX
    //         00452f5a     JNZ        LAB_00452f63
    //                              m_s_obj.cpp:474 (7)
    //         00452f5c     MOV        byte ptr [ESI + 0xa4],0x1
    //                               LAB_00452f63                                                 XREF[1]:     00452f5a(j)  
    //                              m_s_obj.cpp:477 (14)
    //         00452f63     LEA        EDI=>temp_name[4],[ESP + 0x5c]
    //         00452f67     OR         this,0xffffffff
    //         00452f6a     XOR        EAX,EAX
    //         00452f6c     SCASB.RE   ES:EDI
    //         00452f6e     NOT        this
    //         00452f70     DEC        this
    //                              m_s_obj.cpp:478 (5)
    //         00452f71     TEST       this,this
    //         00452f74     JLE        LAB_00452f8d
    //                              m_s_obj.cpp:481 (23)
    //         00452f76     LEA        this=>temp_name[4],[ESP + 0x5c]
    //         00452f7a     LEA        EAX,[ESI + 0x8]
    //         00452f7d     PUSH       this
    //         00452f7e     PUSH       EAX
    //         00452f7f     MOV        dword ptr [EAX],0x0
    //         00452f85     CALL       getstring                                        void getstring(char * * param_1, char * param
    //         00452f8a     ADD        ESP,0x8
    //                               LAB_00452f8d                                                 XREF[1]:     00452f74(j)  
    //                              m_s_obj.cpp:485 (18)
    //         00452f8d     POP        EDI
    //         00452f8e     POP        ESI
    //         00452f8f     POP        EBP
    //         00452f90     MOV        EAX,0x1
    //         00452f95     POP        EBX
    //         00452f96     ADD        ESP,0xc4
    //         00452f9c     RET        0x10
}

// Offset: 0x00452FA0
void RGE_Master_Static_Object(RGE_Master_Static_Object* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual __thiscall RGE_Master_Static_Object::~RGE_Master_Static_Object(void)                  *
    //                              *********************************************************************************************************
    //                              void __thiscall ~RGE_Master_Static_Object(RGE_Master_Static_Object *
    //              void              <VOID>         <RETURN>
    //              RGE_Master_Sta    ECX:4 (auto)   this
    //                               ??1RGE_Master_Static_Object@@UAE@XZ                          XREF[3]:     ~RGE_Master_Animated_Object:0044fb
    //                               RGE_Master_Static_Object::~RGE_Master_Static_Object                       `scalar_deleting_destructor':00452
    //                                                                                                         ~RGE_Master_Static_Object:0050f20e
    //                                                                                                         ~TRIBE_Master_Tree_Object:0050f210
    //                              m_s_obj.cpp:492 (3)
    //         00452fa0     PUSH       ESI
    //         00452fa1     MOV        ESI,this
    //                              m_s_obj.cpp:493 (13)
    //         00452fa3     MOV        EAX,dword ptr [ESI + 0x8]
    //         00452fa6     MOV        dword ptr [ESI],RGE_Master_Static_Object::`vft   = 00452150
    //         00452fac     TEST       EAX,EAX
    //         00452fae     JZ         LAB_00452fc0
    //                              m_s_obj.cpp:495 (9)
    //         00452fb0     PUSH       EAX
    //         00452fb1     CALL       free                                             undefined free()
    //         00452fb6     ADD        ESP,0x4
    //                              m_s_obj.cpp:496 (7)
    //         00452fb9     MOV        dword ptr [ESI + 0x8],0x0
    //                               LAB_00452fc0                                                 XREF[1]:     00452fae(j)  
    //                              m_s_obj.cpp:499 (10)
    //         00452fc0     MOV        EAX,dword ptr [ESI + 0x94]
    //         00452fc6     TEST       EAX,EAX
    //         00452fc8     JZ         LAB_00452fdd
    //                              m_s_obj.cpp:501 (9)
    //         00452fca     PUSH       EAX
    //         00452fcb     CALL       free                                             undefined free()
    //         00452fd0     ADD        ESP,0x4
    //                              m_s_obj.cpp:502 (10)
    //         00452fd3     MOV        dword ptr [ESI + 0x94],0x0
    //                               LAB_00452fdd                                                 XREF[1]:     00452fc8(j)  
    //                              m_s_obj.cpp:504 (2)
    //         00452fdd     POP        ESI
    //         00452fde     RET
}

// Offset: 0x00452FE0
RGE_Static_Object* RGE_Master_Static_Object::make_new_obj(RGE_Player* param_1, float param_2, float param_3, float param_4) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual class RGE_Static_Object * __thiscall RGE_Master_Static_Object::make_new_obj(class ... *
    //                              *********************************************************************************************************
    //                              RGE_Static_Object * __thiscall make_new_obj(RGE_Master_Static_Object
    //              RGE_Static_Obj    EAX:4          <RETURN>
    //              RGE_Master_Sta    ECX:4 (auto)   this
    //              RGE_Player *      Stack[0x4]:4   param_1                   XREF[2]:     00452ff7(R), 00453055(W)  
    //              float             Stack[0x8]:4   param_2                   XREF[2]:     00453025(R), 00453070(R)  
    //              float             Stack[0xc]:4   param_3                   XREF[2]:     0045301e(R), 00453069(R)  
    //              float             Stack[0x10]:4  param_4                   XREF[2]:     0045301a(R), 00453065(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     0045305b(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[2]:     0045307f(R), 00453093(R)  
    //                               ?make_new_obj@RGE_Master_Static_Object@@UAEPAVRGE_Static_Ob  XREF[1]:     005705f0(*)  
    //                               RGE_Master_Static_Object::make_new_obj
    //                              m_s_obj.cpp:509 (23)
    //         00452fe0     MOV        EAX,FS:[0x0]
    //         00452fe6     PUSH       -0x1
    //         00452fe8     PUSH       FUN_0055da3b
    //         00452fed     PUSH       EAX
    //         00452fee     MOV        dword ptr FS:[0x0],ESP
    //         00452ff5     PUSH       EBX
    //         00452ff6     PUSH       ESI
    //                              m_s_obj.cpp:512 (17)
    //         00452ff7     MOV        EBX,dword ptr [ESP + param_1]
    //         00452ffb     PUSH       EDI
    //         00452ffc     MOV        EDI,this
    //         00452ffe     MOV        AL,byte ptr [EDI + 0xa4]
    //         00453004     TEST       AL,AL
    //         00453006     JZ         LAB_00453048
    //                              m_s_obj.cpp:514 (14)
    //         00453008     MOV        AL,byte ptr [EDI + 0x4]
    //         0045300b     MOV        this,dword ptr [EBX + 0x3c]
    //         0045300e     PUSH       EAX
    //         0045300f     CALL       RGE_Game_World::recycle_object_in_to_game        RGE_Static_Object * recycle_object_in_to_game
    //         00453014     MOV        ESI,EAX
    //                              m_s_obj.cpp:515 (4)
    //         00453016     TEST       ESI,ESI
    //         00453018     JZ         LAB_00453048
    //                              m_s_obj.cpp:517 (24)
    //         0045301a     MOV        EAX,dword ptr [ESP + param_4]
    //         0045301e     MOV        this,dword ptr [ESP + param_3]
    //         00453022     MOV        EDX,dword ptr [ESI]
    //         00453024     PUSH       EAX
    //         00453025     MOV        EAX,dword ptr [ESP + param_2]
    //         00453029     PUSH       this
    //         0045302a     PUSH       EAX
    //         0045302b     PUSH       EBX
    //         0045302c     PUSH       EDI
    //         0045302d     MOV        this,ESI
    //         0045302f     CALL       dword ptr [EDX + 0x4]
    //                              m_s_obj.cpp:518 (2)
    //         00453032     MOV        EAX,ESI
    //                              m_s_obj.cpp:522 (20)
    //         00453034     MOV        this,dword ptr [ESP + 0xc]
    //         00453038     MOV        dword ptr FS:[0x0],this
    //         0045303f     POP        EDI
    //         00453040     POP        ESI
    //         00453041     POP        EBX
    //         00453042     ADD        ESP,0xc
    //         00453045     RET        0x10
    //                               LAB_00453048                                                 XREF[2]:     00453006(j), 00453018(j)  
    //                              m_s_obj.cpp:521 (55)
    //         00453048     PUSH       0x88
    //         0045304d     CALL       operator_new                                     void * operator_new(uint param_1)
    //         00453052     ADD        ESP,0x4
    //         00453055     MOV        dword ptr [ESP + param_1],EAX
    //         00453059     TEST       EAX,EAX
    //         0045305b     MOV        dword ptr [ESP + local_4],0x0
    //         00453063     JZ         LAB_00453093
    //         00453065     MOV        this,dword ptr [ESP + param_4]
    //         00453069     MOV        EDX,dword ptr [ESP + param_3]
    //         0045306d     PUSH       0x1
    //         0045306f     PUSH       this
    //         00453070     MOV        this,dword ptr [ESP + param_2]
    //         00453074     PUSH       EDX
    //         00453075     PUSH       this
    //         00453076     PUSH       EBX
    //         00453077     PUSH       EDI
    //         00453078     MOV        this,EAX
    //         0045307a     CALL       RGE_Static_Object::RGE_Static_Object             undefined RGE_Static_Object(RGE_Static_Object
    //                              m_s_obj.cpp:522 (42)
    //         0045307f     MOV        this,dword ptr [ESP + local_c]
    //         00453083     MOV        dword ptr FS:[0x0],this
    //         0045308a     POP        EDI
    //         0045308b     POP        ESI
    //         0045308c     POP        EBX
    //         0045308d     ADD        ESP,0xc
    //         00453090     RET        0x10
    //                               LAB_00453093                                                 XREF[1]:     00453063(j)  
    //         00453093     MOV        this,dword ptr [ESP + local_c]
    //         00453097     POP        EDI
    //         00453098     POP        ESI
    //         00453099     XOR        EAX,EAX
    //         0045309b     MOV        dword ptr FS:[0x0],this
    //         004530a2     POP        EBX
    //         004530a3     ADD        ESP,0xc
    //         004530a6     RET        0x10
}

// Offset: 0x004530B0
RGE_Master_Static_Object* RGE_Master_Static_Object::make_new_master() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual class RGE_Master_Static_Object * __thiscall RGE_Master_Static_Object::make_new_mas... *
    //                              *********************************************************************************************************
    //                              RGE_Master_Static_Object * __thiscall make_new_master(RGE_Master_Sta
    //              RGE_Master_Sta    EAX:4          <RETURN>
    //              RGE_Master_Sta    ECX:4 (auto)   this
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     004530dc(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[2]:     004530f0(R), 00453100(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     004530d6(W)  
    //                               ?make_new_master@RGE_Master_Static_Object@@UAEPAV1@XZ        XREF[1]:     005705f4(*)  
    //                               RGE_Master_Static_Object::make_new_master
    //                              m_s_obj.cpp:527 (25)
    //         004530b0     PUSH       -0x1
    //         004530b2     PUSH       FUN_0055da5b
    //         004530b7     MOV        EAX,FS:[0x0]
    //         004530bd     PUSH       EAX
    //         004530be     MOV        dword ptr FS:[0x0],ESP
    //         004530c5     PUSH       this
    //         004530c6     PUSH       ESI
    //         004530c7     MOV        ESI,this
    //                              m_s_obj.cpp:528 (39)
    //         004530c9     PUSH       0xb8
    //         004530ce     CALL       operator_new                                     void * operator_new(uint param_1)
    //         004530d3     ADD        ESP,0x4
    //         004530d6     MOV        dword ptr [ESP + local_10],EAX
    //         004530da     TEST       EAX,EAX
    //         004530dc     MOV        dword ptr [ESP + local_4],0x0
    //         004530e4     JZ         LAB_00453100
    //         004530e6     PUSH       0x1
    //         004530e8     PUSH       ESI
    //         004530e9     MOV        this,EAX
    //         004530eb     CALL       RGE_Master_Static_Object::RGE_Master_Static_Ob   undefined RGE_Master_Static_Object(RGE_Master
    //                              m_s_obj.cpp:529 (34)
    //         004530f0     MOV        this,dword ptr [ESP + local_c]
    //         004530f4     MOV        dword ptr FS:[0x0],this
    //         004530fb     POP        ESI
    //         004530fc     ADD        ESP,0x10
    //         004530ff     RET
    //                               LAB_00453100                                                 XREF[1]:     004530e4(j)  
    //         00453100     MOV        this,dword ptr [ESP + local_c]
    //         00453104     XOR        EAX,EAX
    //         00453106     MOV        dword ptr FS:[0x0],this
    //         0045310d     POP        ESI
    //         0045310e     ADD        ESP,0x10
    //         00453111     RET
}

// Offset: 0x00453120
void TRIBE_Master_Tree_Object::copy_obj(RGE_Master_Static_Object* param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void __thiscall RGE_Master_Static_Object::copy_obj(class RGE_Master_Static_Object *)  *
    //                              *********************************************************************************************************
    //                              void __thiscall copy_obj(RGE_Master_Static_Object * this, RGE_Master
    //              void              <VOID>         <RETURN>
    //              RGE_Master_Sta    ECX:4 (auto)   this
    //              RGE_Master_Sta    Stack[0x4]:4   param_1                   XREF[1]:     0045315e(R)  
    //              undefined2        Stack[-0x4]:2  local_4                   XREF[2]:     00453134(W), 00453476(R)  
    //              short             Stack[-0x8]:2  object_type2              XREF[2]:     00453141(W), 004533dd(R)  
    //              short             Stack[-0xc]:2  hide_in_scenario_editor2  XREF[2]:     00453146(W), 004533d4(R)  
    //              undefined1        Stack[-0xd]:1  local_d                   XREF[2]:     0045314b(W), 0045347b(R)  
    //              short             Stack[-0x10]:2 copy_id2
    //              uchar             Stack[-0x11]:1 available2
    //                               ?copy_obj@RGE_Master_Static_Object@@UAEXPAV1@@Z              XREF[3]:     copy_obj:0044fd49(c), 005705dc(*), 
    //                               RGE_Master_Static_Object::copy_obj                                        00576794(*)  
    //                              m_s_obj.cpp:534 (9)
    //         00453120     SUB        ESP,0x10
    //         00453123     PUSH       EBX
    //         00453124     PUSH       EBP
    //         00453125     PUSH       ESI
    //         00453126     MOV        ESI,this
    //         00453128     PUSH       EDI
    //                              m_s_obj.cpp:535 (4)
    //         00453129     MOV        AX,word ptr [ESI + 0x10]
    //                              m_s_obj.cpp:536 (4)
    //         0045312d     MOV        this,word ptr [ESI + 0x12]
    //                              m_s_obj.cpp:538 (8)
    //         00453131     MOV        DL,byte ptr [ESI + 0x52]
    //         00453134     MOV        word ptr [ESP + local_4],AX
    //                              m_s_obj.cpp:540 (5)
    //         00453139     MOVZX      AX,byte ptr [ESI + 0x4e]
    //                              m_s_obj.cpp:542 (23)
    //         0045313e     LEA        EBX,[ESI + 0x8]
    //         00453141     MOV        word ptr [ESP + object_type2],AX
    //         00453146     MOV        word ptr [ESP + hide_in_scenario_editor2],this
    //         0045314b     MOV        byte ptr [ESP + local_d],DL
    //         0045314f     MOV        EAX,dword ptr [EBX]
    //         00453151     TEST       EAX,EAX
    //         00453153     JZ         LAB_0045315e
    //                              m_s_obj.cpp:543 (9)
    //         00453155     PUSH       EAX
    //         00453156     CALL       free                                             undefined free()
    //         0045315b     ADD        ESP,0x4
    //                               LAB_0045315e                                                 XREF[1]:     00453153(j)  
    //                              m_s_obj.cpp:545 (278)
    //         0045315e     MOV        EDI,dword ptr [ESP + param_1]
    //         00453162     MOV        this,byte ptr [EDI + 0x4]
    //         00453165     MOV        byte ptr [ESI + 0x4],this
    //         00453168     MOV        EDX,dword ptr [EDI + 0x8]
    //         0045316b     MOV        dword ptr [EBX],EDX
    //         0045316d     MOV        AX,word ptr [EDI + 0xc]
    //         00453171     MOV        word ptr [ESI + 0xc],AX
    //         00453175     MOV        this,word ptr [EDI + 0xe]
    //         00453179     MOV        word ptr [ESI + 0xe],this
    //         0045317d     MOV        DX,word ptr [EDI + 0x10]
    //         00453181     MOV        word ptr [ESI + 0x10],DX
    //         00453185     MOV        AX,word ptr [EDI + 0x12]
    //         00453189     MOV        word ptr [ESI + 0x12],AX
    //         0045318d     MOV        this,word ptr [EDI + 0x14]
    //         00453191     MOV        word ptr [ESI + 0x14],this
    //         00453195     MOV        EDX,dword ptr [EDI + 0x18]
    //         00453198     MOV        dword ptr [ESI + 0x18],EDX
    //         0045319b     MOV        EAX,dword ptr [EDI + 0x1c]
    //         0045319e     MOV        dword ptr [ESI + 0x1c],EAX
    //         004531a1     MOV        this,dword ptr [EDI + 0x20]
    //         004531a4     MOV        dword ptr [ESI + 0x20],this
    //         004531a7     MOV        DL,byte ptr [EDI + 0x24]
    //         004531aa     MOV        byte ptr [ESI + 0x24],DL
    //         004531ad     MOV        AX,word ptr [EDI + 0x26]
    //         004531b1     MOV        word ptr [ESI + 0x26],AX
    //         004531b5     MOV        this,dword ptr [EDI + 0x28]
    //         004531b8     MOV        dword ptr [ESI + 0x28],this
    //         004531bb     MOV        DL,byte ptr [EDI + 0x2c]
    //         004531be     MOV        byte ptr [ESI + 0x2c],DL
    //         004531c1     MOV        EAX,dword ptr [EDI + 0x30]
    //         004531c4     MOV        dword ptr [ESI + 0x30],EAX
    //         004531c7     MOV        this,dword ptr [EDI + 0x34]
    //         004531ca     MOV        dword ptr [ESI + 0x34],this
    //         004531cd     MOV        EDX,dword ptr [EDI + 0x38]
    //         004531d0     MOV        dword ptr [ESI + 0x38],EDX
    //         004531d3     MOV        EAX,dword ptr [EDI + 0x3c]
    //         004531d6     MOV        dword ptr [ESI + 0x3c],EAX
    //         004531d9     MOV        this,dword ptr [EDI + 0x40]
    //         004531dc     MOV        dword ptr [ESI + 0x40],this
    //         004531df     MOV        EDX,dword ptr [EDI + 0x44]
    //         004531e2     MOV        dword ptr [ESI + 0x44],EDX
    //         004531e5     MOV        AX,word ptr [EDI + 0x48]
    //         004531e9     MOV        word ptr [ESI + 0x48],AX
    //         004531ed     MOV        this,byte ptr [EDI + 0x4a]
    //         004531f0     MOV        byte ptr [ESI + 0x4a],this
    //         004531f3     MOV        DL,byte ptr [EDI + 0x4b]
    //         004531f6     MOV        byte ptr [ESI + 0x4b],DL
    //         004531f9     MOV        AX,word ptr [EDI + 0x4c]
    //         004531fd     MOV        word ptr [ESI + 0x4c],AX
    //         00453201     MOV        this,byte ptr [EDI + 0x4e]
    //         00453204     MOV        byte ptr [ESI + 0x4e],this
    //         00453207     MOV        DX,word ptr [EDI + 0x50]
    //         0045320b     MOV        word ptr [ESI + 0x50],DX
    //         0045320f     MOV        AL,byte ptr [EDI + 0x52]
    //         00453212     MOV        byte ptr [ESI + 0x52],AL
    //         00453215     MOV        this,word ptr [EDI + 0x54]
    //         00453219     MOV        word ptr [ESI + 0x54],this
    //         0045321d     MOV        DX,word ptr [EDI + 0x56]
    //         00453221     MOV        word ptr [ESI + 0x56],DX
    //         00453225     MOV        AX,word ptr [EDI + 0x58]
    //         00453229     MOV        word ptr [ESI + 0x58],AX
    //         0045322d     MOV        this,word ptr [EDI + 0x5a]
    //         00453231     MOV        word ptr [ESI + 0x5a],this
    //         00453235     MOV        EDX,dword ptr [EDI + 0x5c]
    //         00453238     MOV        dword ptr [ESI + 0x5c],EDX
    //         0045323b     MOV        EAX,dword ptr [EDI + 0x60]
    //         0045323e     MOV        dword ptr [ESI + 0x60],EAX
    //         00453241     MOV        this,byte ptr [EDI + 0x64]
    //         00453244     MOV        byte ptr [ESI + 0x64],this
    //         00453247     MOV        DL,byte ptr [EDI + 0x65]
    //         0045324a     MOV        byte ptr [ESI + 0x65],DL
    //         0045324d     MOV        AX,word ptr [EDI + 0x66]
    //         00453251     MOV        word ptr [ESI + 0x66],AX
    //         00453255     MOV        this,byte ptr [EDI + 0x68]
    //         00453258     MOV        byte ptr [ESI + 0x68],this
    //         0045325b     MOV        this,EDI
    //         0045325d     LEA        EAX,[ESI + 0x6a]
    //         00453260     SUB        this,ESI
    //         00453262     MOV        EDX,0x3
    //                               LAB_00453267                                                 XREF[1]:     00453272(j)  
    //         00453267     MOV        BP,word ptr [this->_padding_ + EAX*0x1]
    //         0045326b     MOV        word ptr [EAX],BP
    //         0045326e     ADD        EAX,0x2
    //         00453271     DEC        EDX
    //         00453272     JNZ        LAB_00453267
    //                              m_s_obj.cpp:574 (415)
    //         00453274     LEA        EAX,[ESI + 0x70]
    //         00453277     MOV        EDX,0x3
    //                               LAB_0045327c                                                 XREF[1]:     00453285(j)  
    //         0045327c     MOV        EBP,dword ptr [EAX + this->_padding_*0x1]
    //         0045327f     MOV        dword ptr [EAX],EBP
    //         00453281     ADD        EAX,0x4
    //         00453284     DEC        EDX
    //         00453285     JNZ        LAB_0045327c
    //         00453287     MOV        DX,word ptr [EDI + 0x7c]
    //         0045328b     MOV        EBP,0xffffff78
    //         00453290     MOV        word ptr [ESI + 0x7c],DX
    //         00453294     MOV        EAX,dword ptr [EDI + 0x80]
    //         0045329a     MOV        dword ptr [ESI + 0x80],EAX
    //         004532a0     MOV        EDX,dword ptr [EDI + 0x84]
    //         004532a6     MOV        dword ptr [ESI + 0x84],EDX
    //         004532ac     LEA        EAX,[ESI + 0x88]
    //         004532b2     SUB        EBP,ESI
    //                               LAB_004532b4                                                 XREF[1]:     004532c1(j)  
    //         004532b4     MOV        DL,byte ptr [EAX + this->_padding_*0x1]
    //         004532b7     MOV        byte ptr [EAX],DL
    //         004532b9     INC        EAX
    //         004532ba     LEA        EDX,[EBP + EAX*0x1]
    //         004532be     CMP        EDX,0x3
    //         004532c1     JC         LAB_004532b4
    //         004532c3     MOV        AL,byte ptr [EDI + 0x8b]
    //         004532c9     MOV        byte ptr [ESI + 0x8b],AL
    //         004532cf     MOV        this,byte ptr [EDI + 0x8c]
    //         004532d5     MOV        byte ptr [ESI + 0x8c],this
    //         004532db     MOV        DL,byte ptr [EDI + 0x8d]
    //         004532e1     MOV        byte ptr [ESI + 0x8d],DL
    //         004532e7     MOV        AL,byte ptr [EDI + 0x8e]
    //         004532ed     MOV        byte ptr [ESI + 0x8e],AL
    //         004532f3     MOV        this,byte ptr [EDI + 0x8f]
    //         004532f9     MOV        byte ptr [ESI + 0x8f],this
    //         004532ff     MOV        DL,byte ptr [EDI + 0x90]
    //         00453305     MOV        byte ptr [ESI + 0x90],DL
    //         0045330b     MOV        AL,byte ptr [EDI + 0x91]
    //         00453311     MOV        byte ptr [ESI + 0x91],AL
    //         00453317     MOV        this,byte ptr [EDI + 0x92]
    //         0045331d     MOV        byte ptr [ESI + 0x92],this
    //         00453323     MOV        DL,byte ptr [EDI + 0x93]
    //         00453329     MOV        byte ptr [ESI + 0x93],DL
    //         0045332f     MOV        EAX,dword ptr [EDI + 0x94]
    //         00453335     MOV        dword ptr [ESI + 0x94],EAX
    //         0045333b     MOV        this,dword ptr [EDI + 0x98]
    //         00453341     MOV        dword ptr [ESI + 0x98],this
    //         00453347     MOV        EDX,dword ptr [EDI + 0x9c]
    //         0045334d     MOV        dword ptr [ESI + 0x9c],EDX
    //         00453353     MOV        EAX,dword ptr [EDI + 0xa0]
    //         00453359     MOV        dword ptr [ESI + 0xa0],EAX
    //         0045335f     MOV        this,byte ptr [EDI + 0xa4]
    //         00453365     MOV        byte ptr [ESI + 0xa4],this
    //         0045336b     MOV        DL,byte ptr [EDI + 0xa5]
    //         00453371     MOV        byte ptr [ESI + 0xa5],DL
    //         00453377     MOV        AL,byte ptr [EDI + 0xa6]
    //         0045337d     MOV        byte ptr [ESI + 0xa6],AL
    //         00453383     MOV        this,byte ptr [EDI + 0xa7]
    //         00453389     MOV        byte ptr [ESI + 0xa7],this
    //         0045338f     MOV        DL,byte ptr [EDI + 0xa8]
    //         00453395     MOV        byte ptr [ESI + 0xa8],DL
    //         0045339b     MOV        AL,byte ptr [EDI + 0xa9]
    //         004533a1     MOV        byte ptr [ESI + 0xa9],AL
    //         004533a7     MOV        this,dword ptr [EDI + 0xac]
    //         004533ad     MOV        dword ptr [ESI + 0xac],this
    //         004533b3     MOV        EDX,dword ptr [EDI + 0xb0]
    //         004533b9     MOV        dword ptr [ESI + 0xb0],EDX
    //         004533bf     MOV        EAX,dword ptr [EDI + 0xb4]
    //         004533c5     MOV        dword ptr [ESI + 0xb4],EAX
    //         004533cb     MOV        this,byte ptr [EDI + 0x4e]
    //         004533ce     MOV        AL,0x1
    //         004533d0     CMP        this,AL
    //         004533d2     JNZ        LAB_004533dd
    //         004533d4     MOV        this,word ptr [ESP + hide_in_scenario_editor2]
    //         004533d9     MOV        word ptr [ESI + 0x12],this
    //                               LAB_004533dd                                                 XREF[1]:     004533d2(j)  
    //         004533dd     MOV        DL,byte ptr [ESP + object_type2]
    //         004533e1     MOV        byte ptr [ESI + 0x4e],DL
    //         004533e4     MOV        byte ptr [EDI + 0x4e],AL
    //         004533e7     MOV        AL,byte ptr [ESI + 0x93]
    //         004533ed     TEST       AL,AL
    //         004533ef     JBE        LAB_0045345c
    //         004533f1     AND        EAX,0xff
    //         004533f6     PUSH       0x8
    //         004533f8     PUSH       EAX
    //         004533f9     CALL       calloc                                           undefined calloc()
    //         004533fe     MOV        this,byte ptr [ESI + 0x93]
    //         00453404     MOV        dword ptr [ESI + 0x94],EAX
    //         0045340a     ADD        ESP,0x8
    //         0045340d     XOR        EAX,EAX
    //         0045340f     TEST       this,this
    //         00453411     JBE        LAB_00453466
    //                               LAB_00453413                                                 XREF[1]:     00453458(j)  
    //                              m_s_obj.cpp:560 (18)
    //         00453413     MOV        this,dword ptr [EDI + 0x94]
    //         00453419     MOV        EDX,dword ptr [ESI + 0x94]
    //         0045341f     MOV        this,dword ptr [this->_padding_ + EAX*0x8]
    //         00453422     MOV        dword ptr [EDX + EAX*0x8],this
    //                              m_s_obj.cpp:561 (20)
    //         00453425     MOV        EDX,dword ptr [EDI + 0x94]
    //         0045342b     MOV        this,dword ptr [ESI + 0x94]
    //         00453431     MOV        DL,byte ptr [EDX + EAX*0x8 + 0x4]
    //         00453435     MOV        byte ptr [ECX + EAX*0x8 + this->master_type],DL
    //                              m_s_obj.cpp:562 (33)
    //         00453439     MOV        this,dword ptr [EDI + 0x94]
    //         0045343f     MOV        EDX,dword ptr [ESI + 0x94]
    //         00453445     MOV        this,byte ptr [ECX + EAX*0x8 + this+0x5]
    //         00453449     MOV        byte ptr [EDX + EAX*0x8 + 0x5],this
    //         0045344d     XOR        EDX,EDX
    //         0045344f     MOV        DL,byte ptr [ESI + 0x93]
    //         00453455     INC        EAX
    //         00453456     CMP        EAX,EDX
    //         00453458     JL         LAB_00453413
    //                              m_s_obj.cpp:565 (2)
    //         0045345a     JMP        LAB_00453466
    //                               LAB_0045345c                                                 XREF[1]:     004533ef(j)  
    //                              m_s_obj.cpp:566 (10)
    //         0045345c     MOV        dword ptr [ESI + 0x94],0x0
    //                               LAB_00453466                                                 XREF[2]:     00453411(j), 0045345a(j)  
    //                              m_s_obj.cpp:568 (6)
    //         00453466     MOV        dword ptr [EBX],0x0
    //                              m_s_obj.cpp:569 (10)
    //         0045346c     MOV        EAX,dword ptr [EDI + 0x8]
    //         0045346f     PUSH       EAX
    //         00453470     PUSH       EBX
    //         00453471     CALL       getstring                                        void getstring(char * * param_1, char * param
    //                              m_s_obj.cpp:571 (5)
    //         00453476     MOV        this,word ptr [ESP + local_4]
    //                              m_s_obj.cpp:573 (14)
    //         0045347b     MOV        DL,byte ptr [ESP + local_d]
    //         0045347f     ADD        ESP,0x8
    //         00453482     MOV        word ptr [ESI + 0x10],this
    //         00453486     MOV        byte ptr [ESI + 0x52],DL
    //                              m_s_obj.cpp:574 (10)
    //         00453489     POP        EDI
    //         0045348a     POP        ESI
    //         0045348b     POP        EBP
    //         0045348c     POP        EBX
    //         0045348d     ADD        ESP,0x10
    //         00453490     RET        0x4
}

// Offset: 0x004534A0
void TRIBE_Master_Tree_Object::modify(float param_1, uchar param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void __thiscall RGE_Master_Static_Object::modify(float,unsigned char)                 *
    //                              *********************************************************************************************************
    //                              void __thiscall modify(RGE_Master_Static_Object * this, float param_
    //              void              <VOID>         <RETURN>
    //              RGE_Master_Sta    ECX:4 (auto)   this
    //              float             Stack[0x4]:4   param_1                   XREF[6]:     004534c0(R), 004534d1(R), 004534dc(R), 004534ec(R), 
    //                                                                                     004534f7(R), 00453502(R)  
    //              uchar             Stack[0x8]:1   param_2                   XREF[1]:     004534a0(R)  
    //                               ?modify@RGE_Master_Static_Object@@UAEXME@Z                   XREF[3]:     modify:0044fd6e(c), 005705e0(*), 
    //                               RGE_Master_Static_Object::modify                                          00576798(*)  
    //                              m_s_obj.cpp:578 (32)
    //         004534a0     MOV        EAX,dword ptr [ESP + param_2]
    //         004534a4     PUSH       ESI
    //         004534a5     AND        EAX,0xff
    //         004534aa     MOV        ESI,this
    //         004534ac     CMP        EAX,0xe
    //         004534af     JA         switchD_004534b9::caseD_5
    //         004534b1     XOR        this,this
    //         004534b3     MOV        this,byte ptr [EAX + switchD_004534b9::switchd
    //                               switchD_004534b9::switchD
    //         004534b9     JMP        dword ptr [this->_padding_*0x4 + switchD_00453   = 004534c0
    //                               switchD_004534b9::caseD_0                                    XREF[2]:     004534b9(j), 00453514(*)  
    //                              m_s_obj.cpp:582 (13)
    //         004534c0     FLD        float ptr [ESP + param_1]
    //         004534c4     CALL       __ftol                                           undefined __ftol()
    //         004534c9     MOV        word ptr [ESI + 0x26],AX
    //                              m_s_obj.cpp:600 (4)
    //         004534cd     POP        ESI
    //         004534ce     RET        0x8
    //                               switchD_004534b9::caseD_1                                    XREF[2]:     004534b9(j), 00453518(*)  
    //                              m_s_obj.cpp:585 (7)
    //         004534d1     MOV        EDX,dword ptr [ESP + param_1]
    //         004534d5     MOV        dword ptr [ESI + 0x28],EDX
    //                              m_s_obj.cpp:600 (4)
    //         004534d8     POP        ESI
    //         004534d9     RET        0x8
    //                               switchD_004534b9::caseD_2                                    XREF[2]:     004534b9(j), 0045351c(*)  
    //                              m_s_obj.cpp:588 (12)
    //         004534dc     FLD        float ptr [ESP + param_1]
    //         004534e0     CALL       __ftol                                           undefined __ftol()
    //         004534e5     MOV        byte ptr [ESI + 0x2c],AL
    //                              m_s_obj.cpp:600 (4)
    //         004534e8     POP        ESI
    //         004534e9     RET        0x8
    //                               switchD_004534b9::caseD_3                                    XREF[2]:     004534b9(j), 00453520(*)  
    //                              m_s_obj.cpp:591 (7)
    //         004534ec     MOV        EAX,dword ptr [ESP + param_1]
    //         004534f0     MOV        dword ptr [ESI + 0x30],EAX
    //                              m_s_obj.cpp:600 (4)
    //         004534f3     POP        ESI
    //         004534f4     RET        0x8
    //                               switchD_004534b9::caseD_4                                    XREF[2]:     004534b9(j), 00453524(*)  
    //                              m_s_obj.cpp:594 (7)
    //         004534f7     MOV        this,dword ptr [ESP + param_1]
    //         004534fb     MOV        dword ptr [ESI + 0x34],this
    //                              m_s_obj.cpp:600 (4)
    //         004534fe     POP        ESI
    //         004534ff     RET        0x8
    //                               switchD_004534b9::caseD_e                                    XREF[2]:     004534b9(j), 00453528(*)  
    //                              m_s_obj.cpp:597 (13)
    //         00453502     FLD        float ptr [ESP + param_1]
    //         00453506     CALL       __ftol                                           undefined __ftol()
    //         0045350b     MOV        word ptr [ESI + 0x7c],AX
    //                               switchD_004534b9::caseD_6                                    XREF[3]:     004534af(j), 004534b9(j), 
    //                               switchD_004534b9::caseD_7                                                 0045352c(*)  
    //                               switchD_004534b9::caseD_8
    //                               switchD_004534b9::caseD_9
    //                               switchD_004534b9::caseD_a
    //                               switchD_004534b9::caseD_b
    //                               switchD_004534b9::caseD_c
    //                               switchD_004534b9::caseD_d
    //                               switchD_004534b9::caseD_5
    //                              m_s_obj.cpp:600 (48)
    //         0045350f     POP        ESI
    //         00453510     RET        0x8
}

// Offset: 0x00453540
void TRIBE_Master_Tree_Object::modify_delta(float param_1, uchar param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void __thiscall RGE_Master_Static_Object::modify_delta(float,unsigned char)           *
    //                              *********************************************************************************************************
    //                              void __thiscall modify_delta(RGE_Master_Static_Object * this, float 
    //              void              <VOID>         <RETURN>
    //              RGE_Master_Sta    ECX:4 (auto)   this
    //              float             Stack[0x4]:4   param_1                   XREF[6]:     00453560(R), 00453571(R), 0045357f(R), 0045358f(R), 
    //                                                                                     0045359d(R), 004535ab(R)  
    //              uchar             Stack[0x8]:1   param_2                   XREF[1]:     00453540(R)  
    //                               ?modify_delta@RGE_Master_Static_Object@@UAEXME@Z             XREF[3]:     modify_delta:0044fd9e(c), 
    //                               RGE_Master_Static_Object::modify_delta                                    005705e4(*), 0057679c(*)  
    //                              m_s_obj.cpp:604 (32)
    //         00453540     MOV        EAX,dword ptr [ESP + param_2]
    //         00453544     PUSH       ESI
    //         00453545     AND        EAX,0xff
    //         0045354a     MOV        ESI,this
    //         0045354c     CMP        EAX,0xe
    //         0045354f     JA         switchD_00453559::caseD_5
    //         00453551     XOR        this,this
    //         00453553     MOV        this,byte ptr [EAX + switchD_00453559::switchd
    //                               switchD_00453559::switchD
    //         00453559     JMP        dword ptr [this->_padding_*0x4 + switchD_00453   = 00453560
    //                               switchD_00453559::caseD_0                                    XREF[2]:     00453559(j), 004535bc(*)  
    //                              m_s_obj.cpp:608 (13)
    //         00453560     FLD        float ptr [ESP + param_1]
    //         00453564     CALL       __ftol                                           undefined __ftol()
    //         00453569     ADD        word ptr [ESI + 0x26],AX
    //                              m_s_obj.cpp:626 (4)
    //         0045356d     POP        ESI
    //         0045356e     RET        0x8
    //                               switchD_00453559::caseD_1                                    XREF[2]:     00453559(j), 004535c0(*)  
    //                              m_s_obj.cpp:611 (10)
    //         00453571     FLD        float ptr [ESP + param_1]
    //         00453575     FADD       float ptr [ESI + 0x28]
    //         00453578     FSTP       float ptr [ESI + 0x28]
    //                              m_s_obj.cpp:626 (4)
    //         0045357b     POP        ESI
    //         0045357c     RET        0x8
    //                               switchD_00453559::caseD_2                                    XREF[2]:     00453559(j), 004535c4(*)  
    //                              m_s_obj.cpp:614 (12)
    //         0045357f     FLD        float ptr [ESP + param_1]
    //         00453583     CALL       __ftol                                           undefined __ftol()
    //         00453588     ADD        byte ptr [ESI + 0x2c],AL
    //                              m_s_obj.cpp:626 (4)
    //         0045358b     POP        ESI
    //         0045358c     RET        0x8
    //                               switchD_00453559::caseD_3                                    XREF[2]:     00453559(j), 004535c8(*)  
    //                              m_s_obj.cpp:617 (10)
    //         0045358f     FLD        float ptr [ESP + param_1]
    //         00453593     FADD       float ptr [ESI + 0x30]
    //         00453596     FSTP       float ptr [ESI + 0x30]
    //                              m_s_obj.cpp:626 (4)
    //         00453599     POP        ESI
    //         0045359a     RET        0x8
    //                               switchD_00453559::caseD_4                                    XREF[2]:     00453559(j), 004535cc(*)  
    //                              m_s_obj.cpp:620 (10)
    //         0045359d     FLD        float ptr [ESP + param_1]
    //         004535a1     FADD       float ptr [ESI + 0x34]
    //         004535a4     FSTP       float ptr [ESI + 0x34]
    //                              m_s_obj.cpp:626 (4)
    //         004535a7     POP        ESI
    //         004535a8     RET        0x8
    //                               switchD_00453559::caseD_e                                    XREF[2]:     00453559(j), 004535d0(*)  
    //                              m_s_obj.cpp:623 (13)
    //         004535ab     FLD        float ptr [ESP + param_1]
    //         004535af     CALL       __ftol                                           undefined __ftol()
    //         004535b4     ADD        word ptr [ESI + 0x7c],AX
    //                               switchD_00453559::caseD_6                                    XREF[3]:     0045354f(j), 00453559(j), 
    //                               switchD_00453559::caseD_7                                                 004535d4(*)  
    //                               switchD_00453559::caseD_8
    //                               switchD_00453559::caseD_9
    //                               switchD_00453559::caseD_a
    //                               switchD_00453559::caseD_b
    //                               switchD_00453559::caseD_c
    //                               switchD_00453559::caseD_d
    //                               switchD_00453559::caseD_5
    //                              m_s_obj.cpp:626 (47)
    //         004535b8     POP        ESI
    //         004535b9     RET        0x8
    //                              Symbol Ref: No symbol: NONAME
    //                               switchD_00453559::switchdataD_004535bc                       XREF[1]:     modify_delta:00453559(*)  
}

// Offset: 0x004535F0
void TRIBE_Master_Tree_Object::modify_percent(float param_1, uchar param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void __thiscall RGE_Master_Static_Object::modify_percent(float,unsigned char)         *
    //                              *********************************************************************************************************
    //                              void __thiscall modify_percent(RGE_Master_Static_Object * this, floa
    //              void              <VOID>         <RETURN>
    //              RGE_Master_Sta    ECX:4 (auto)   this
    //              float             Stack[0x4]:4   param_1                   XREF[6]:     00453620(R), 00453631(R), 0045364c(R), 0045365c(R), 
    //                                                                                     0045366a(R), 00453684(R)  
    //              uchar             Stack[0x8]:1   param_2                   XREF[7]:     004535f0(R), 00453618(W), 0045361c(R), 00453644(W), 
    //                                                                                     00453648(R), 0045367c(W), 00453680(R)  
    //                               ?modify_percent@RGE_Master_Static_Object@@UAEXME@Z           XREF[3]:     modify_percent:0044fdce(c), 
    //                               RGE_Master_Static_Object::modify_percent                                  005705e8(*), 005767a0(*)  
    //                              m_s_obj.cpp:630 (36)
    //         004535f0     MOV        EAX,dword ptr [ESP + param_2]
    //         004535f4     PUSH       ESI
    //         004535f5     AND        EAX,0xff
    //         004535fa     MOV        ESI,this
    //         004535fc     CMP        EAX,0xe
    //         004535ff     JA         switchD_0045360d::caseD_5
    //         00453605     XOR        this,this
    //         00453607     MOV        this,byte ptr [EAX + switchD_0045360d::switchd
    //                               switchD_0045360d::switchD
    //         0045360d     JMP        dword ptr [this->_padding_*0x4 + switchD_00453   = 00453614
    //                               switchD_0045360d::caseD_0                                    XREF[2]:     0045360d(j), 00453698(*)  
    //                              m_s_obj.cpp:634 (25)
    //         00453614     MOVSX      EDX,word ptr [ESI + 0x26]
    //         00453618     MOV        dword ptr [ESP + param_2],EDX
    //         0045361c     FILD       dword ptr [ESP + param_2]
    //         00453620     FMUL       float ptr [ESP + param_1]
    //         00453624     CALL       __ftol                                           undefined __ftol()
    //         00453629     MOV        word ptr [ESI + 0x26],AX
    //                              m_s_obj.cpp:652 (4)
    //         0045362d     POP        ESI
    //         0045362e     RET        0x8
    //                               switchD_0045360d::caseD_1                                    XREF[2]:     0045360d(j), 0045369c(*)  
    //                              m_s_obj.cpp:637 (10)
    //         00453631     FLD        float ptr [ESP + param_1]
    //         00453635     FMUL       float ptr [ESI + 0x28]
    //         00453638     FSTP       float ptr [ESI + 0x28]
    //                              m_s_obj.cpp:652 (4)
    //         0045363b     POP        ESI
    //         0045363c     RET        0x8
    //                               switchD_0045360d::caseD_2                                    XREF[2]:     0045360d(j), 004536a0(*)  
    //                              m_s_obj.cpp:640 (25)
    //         0045363f     XOR        EAX,EAX
    //         00453641     MOV        AL,byte ptr [ESI + 0x2c]
    //         00453644     MOV        dword ptr [ESP + param_2],EAX
    //         00453648     FILD       dword ptr [ESP + param_2]
    //         0045364c     FMUL       float ptr [ESP + param_1]
    //         00453650     CALL       __ftol                                           undefined __ftol()
    //         00453655     MOV        byte ptr [ESI + 0x2c],AL
    //                              m_s_obj.cpp:652 (4)
    //         00453658     POP        ESI
    //         00453659     RET        0x8
    //                               switchD_0045360d::caseD_3                                    XREF[2]:     0045360d(j), 004536a4(*)  
    //                              m_s_obj.cpp:643 (10)
    //         0045365c     FLD        float ptr [ESP + param_1]
    //         00453660     FMUL       float ptr [ESI + 0x30]
    //         00453663     FSTP       float ptr [ESI + 0x30]
    //                              m_s_obj.cpp:652 (4)
    //         00453666     POP        ESI
    //         00453667     RET        0x8
    //                               switchD_0045360d::caseD_4                                    XREF[2]:     0045360d(j), 004536a8(*)  
    //                              m_s_obj.cpp:646 (10)
    //         0045366a     FLD        float ptr [ESP + param_1]
    //         0045366e     FMUL       float ptr [ESI + 0x34]
    //         00453671     FSTP       float ptr [ESI + 0x34]
    //                              m_s_obj.cpp:652 (4)
    //         00453674     POP        ESI
    //         00453675     RET        0x8
    //                               switchD_0045360d::caseD_e                                    XREF[2]:     0045360d(j), 004536ac(*)  
    //                              m_s_obj.cpp:649 (25)
    //         00453678     MOVSX      this,word ptr [ESI + 0x7c]
    //         0045367c     MOV        dword ptr [ESP + param_2],this
    //         00453680     FILD       dword ptr [ESP + param_2]
    //         00453684     FMUL       float ptr [ESP + param_1]
    //         00453688     CALL       __ftol                                           undefined __ftol()
    //         0045368d     MOV        word ptr [ESI + 0x7c],AX
    //                               switchD_0045360d::caseD_6                                    XREF[3]:     004535ff(j), 0045360d(j), 
    //                               switchD_0045360d::caseD_7                                                 004536b0(*)  
    //                               switchD_0045360d::caseD_8
    //                               switchD_0045360d::caseD_9
    //                               switchD_0045360d::caseD_a
    //                               switchD_0045360d::caseD_b
    //                               switchD_0045360d::caseD_c
    //                               switchD_0045360d::caseD_d
    //                               switchD_0045360d::caseD_5
    //                              m_s_obj.cpp:652 (50)
    //         00453691     POP        ESI
    //         00453692     RET        0x8
}

// Offset: 0x00453695
undefined FUN_00453695() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00453695()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00453695
    //         00453695     NOP
    //         00453696     MOV        EDI,EDI
    //                              Symbol Ref: No symbol: NONAME
    //                               switchD_0045360d::switchdataD_00453698                       XREF[1]:     modify_percent:0045360d(*)  
}

// Offset: 0x004536D0
void TRIBE_Master_Tree_Object::save(int param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void __thiscall RGE_Master_Static_Object::save(int)                                   *
    //                              *********************************************************************************************************
    //                              void __thiscall save(RGE_Master_Static_Object * this, int param_1)
    //              void              <VOID>         <RETURN>
    //              RGE_Master_Sta    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[5]:     0045376e(R), 00453af2(W), 00453b19(R), 00453b29(R), 
    //                                                                                     00453b3c(W)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[3]:     004536f9(W), 00453725(W), 00453bcc(*)  
    //              short             Stack[-0x8]:2  death_sound_num           XREF[3]:     004536fd(W), 00453716(W), 00453bbc(*)  
    //              short             Stack[-0xc]:2  selected_sound_num        XREF[3]:     00453afc(W), 00453b2d(R), 00453b40(W)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[3]:     004536f5(W), 00453707(W), 00453866(*)  
    //              short             Stack[-0x14]:2 created_sound_num         XREF[3]:     004536f1(W), 00453752(W), 004537ed(*)  
    //              short             Stack[-0x18]:2 temp_undead_sprite        XREF[3]:     004536ed(W), 00453743(W), 004537dd(*)  
    //              short             Stack[-0x1c]:2 temp_death_sprite         XREF[3]:     004536e9(W), 00453734(W), 004537cd(*)  
    //              short             Stack[-0x20]:2 temp_sprite               XREF[5]:     004536e1(W), 00453763(W), 0045376a(W), 00453781(*), 
    //                                                                                     00453bfd(R)  
    //              short             Stack[-0x24]:2 name_size
    //                               ?save@RGE_Master_Static_Object@@UAEXH@Z                      XREF[3]:     save:0044fdf9(c), 005705ec(*), 
    //                               RGE_Master_Static_Object::save                                            005767a4(*)  
    //                              m_s_obj.cpp:656 (7)
    //         004536d0     SUB        ESP,0x20
    //         004536d3     PUSH       EBX
    //         004536d4     MOV        EBX,this
    //         004536d6     PUSH       EBP
    //                              m_s_obj.cpp:659 (3)
    //         004536d7     OR         this,0xffffffff
    //                              m_s_obj.cpp:666 (41)
    //         004536da     MOV        EAX,dword ptr [EBX + 0x40]
    //         004536dd     PUSH       ESI
    //         004536de     TEST       EAX,EAX
    //         004536e0     PUSH       EDI
    //         004536e1     MOV        dword ptr [ESP + temp_sprite],0x0
    //         004536e9     MOV        dword ptr [ESP + temp_death_sprite],this
    //         004536ed     MOV        dword ptr [ESP + temp_undead_sprite],this
    //         004536f1     MOV        dword ptr [ESP + created_sound_num],this
    //         004536f5     MOV        dword ptr [ESP + local_10],this
    //         004536f9     MOV        dword ptr [ESP + local_4],this
    //         004536fd     MOV        dword ptr [ESP + death_sound_num],this
    //         00453701     JZ         LAB_0045370b
    //                              m_s_obj.cpp:667 (8)
    //         00453703     MOV        AX,word ptr [EAX + 0xc]
    //         00453707     MOV        dword ptr [ESP + local_10],EAX
    //                               LAB_0045370b                                                 XREF[1]:     00453701(j)  
    //                              m_s_obj.cpp:669 (7)
    //         0045370b     MOV        EAX,dword ptr [EBX + 0x3c]
    //         0045370e     TEST       EAX,EAX
    //         00453710     JZ         LAB_0045371a
    //                              m_s_obj.cpp:670 (8)
    //         00453712     MOV        DX,word ptr [EAX + 0xc]
    //         00453716     MOV        dword ptr [ESP + death_sound_num],EDX
    //                               LAB_0045371a                                                 XREF[1]:     00453710(j)  
    //                              m_s_obj.cpp:672 (7)
    //         0045371a     MOV        EAX,dword ptr [EBX + 0x44]
    //         0045371d     TEST       EAX,EAX
    //         0045371f     JZ         LAB_00453729
    //                              m_s_obj.cpp:673 (8)
    //         00453721     MOV        AX,word ptr [EAX + 0xc]
    //         00453725     MOV        dword ptr [ESP + local_4],EAX
    //                               LAB_00453729                                                 XREF[1]:     0045371f(j)  
    //                              m_s_obj.cpp:676 (15)
    //         00453729     MOV        EAX,dword ptr [EBX + 0x18]
    //         0045372c     TEST       EAX,EAX
    //         0045372e     JZ         LAB_00453738
    //         00453730     MOV        DX,word ptr [EAX + 0x72]
    //         00453734     MOV        dword ptr [ESP + temp_death_sprite],EDX
    //                               LAB_00453738                                                 XREF[1]:     0045372e(j)  
    //                              m_s_obj.cpp:677 (15)
    //         00453738     MOV        EAX,dword ptr [EBX + 0x1c]
    //         0045373b     TEST       EAX,EAX
    //         0045373d     JZ         LAB_00453747
    //         0045373f     MOV        AX,word ptr [EAX + 0x72]
    //         00453743     MOV        dword ptr [ESP + temp_undead_sprite],EAX
    //                               LAB_00453747                                                 XREF[1]:     0045373d(j)  
    //                              m_s_obj.cpp:678 (15)
    //         00453747     MOV        EAX,dword ptr [EBX + 0x20]
    //         0045374a     TEST       EAX,EAX
    //         0045374c     JZ         LAB_00453756
    //         0045374e     MOV        DX,word ptr [EAX + 0x72]
    //         00453752     MOV        dword ptr [ESP + created_sound_num],EDX
    //                               LAB_00453756                                                 XREF[1]:     0045374c(j)  
    //                              m_s_obj.cpp:681 (10)
    //         00453756     MOV        EDI,dword ptr [EBX + 0x8]
    //         00453759     XOR        EAX,EAX
    //         0045375b     SCASB.RE   ES:EDI
    //         0045375d     NOT        this
    //         0045375f     DEC        this
    //                              m_s_obj.cpp:682 (9)
    //         00453760     TEST       this,this
    //         00453763     MOV        dword ptr [ESP + temp_sprite],this
    //         00453767     JLE        LAB_0045376e
    //                              m_s_obj.cpp:683 (5)
    //         00453769     INC        this
    //         0045376a     MOV        dword ptr [ESP + temp_sprite],this
    //                               LAB_0045376e                                                 XREF[1]:     00453767(j)  
    //                              m_s_obj.cpp:685 (19)
    //         0045376e     MOV        ESI,dword ptr [ESP + param_1]
    //         00453772     LEA        EAX,[EBX + 0x4]
    //         00453775     PUSH       0x1
    //         00453777     PUSH       EAX
    //         00453778     PUSH       ESI
    //         00453779     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         0045377e     ADD        ESP,0xc
    //                              m_s_obj.cpp:688 (16)
    //         00453781     LEA        this=>temp_sprite,[ESP + 0x10]
    //         00453785     PUSH       0x2
    //         00453787     PUSH       this
    //         00453788     PUSH       ESI
    //         00453789     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         0045378e     ADD        ESP,0xc
    //                              m_s_obj.cpp:689 (15)
    //         00453791     LEA        EDX,[EBX + 0x10]
    //         00453794     PUSH       0x2
    //         00453796     PUSH       EDX
    //         00453797     PUSH       ESI
    //         00453798     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         0045379d     ADD        ESP,0xc
    //                              m_s_obj.cpp:690 (15)
    //         004537a0     LEA        EAX,[EBX + 0xc]
    //         004537a3     PUSH       0x2
    //         004537a5     PUSH       EAX
    //         004537a6     PUSH       ESI
    //         004537a7     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         004537ac     ADD        ESP,0xc
    //                              m_s_obj.cpp:691 (15)
    //         004537af     LEA        this,[EBX + 0xe]
    //         004537b2     PUSH       0x2
    //         004537b4     PUSH       this
    //         004537b5     PUSH       ESI
    //         004537b6     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         004537bb     ADD        ESP,0xc
    //                              m_s_obj.cpp:692 (15)
    //         004537be     LEA        EDX,[EBX + 0x14]
    //         004537c1     PUSH       0x2
    //         004537c3     PUSH       EDX
    //         004537c4     PUSH       ESI
    //         004537c5     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         004537ca     ADD        ESP,0xc
    //                              m_s_obj.cpp:693 (16)
    //         004537cd     LEA        EAX=>temp_death_sprite,[ESP + 0x14]
    //         004537d1     PUSH       0x2
    //         004537d3     PUSH       EAX
    //         004537d4     PUSH       ESI
    //         004537d5     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         004537da     ADD        ESP,0xc
    //                              m_s_obj.cpp:694 (16)
    //         004537dd     LEA        this=>temp_undead_sprite,[ESP + 0x18]
    //         004537e1     PUSH       0x2
    //         004537e3     PUSH       this
    //         004537e4     PUSH       ESI
    //         004537e5     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         004537ea     ADD        ESP,0xc
    //                              m_s_obj.cpp:695 (16)
    //         004537ed     LEA        EDX=>created_sound_num,[ESP + 0x1c]
    //         004537f1     PUSH       0x2
    //         004537f3     PUSH       EDX
    //         004537f4     PUSH       ESI
    //         004537f5     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         004537fa     ADD        ESP,0xc
    //                              m_s_obj.cpp:696 (15)
    //         004537fd     LEA        EAX,[EBX + 0x24]
    //         00453800     PUSH       0x1
    //         00453802     PUSH       EAX
    //         00453803     PUSH       ESI
    //         00453804     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         00453809     ADD        ESP,0xc
    //                              m_s_obj.cpp:697 (15)
    //         0045380c     LEA        this,[EBX + 0x26]
    //         0045380f     PUSH       0x2
    //         00453811     PUSH       this
    //         00453812     PUSH       ESI
    //         00453813     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         00453818     ADD        ESP,0xc
    //                              m_s_obj.cpp:698 (15)
    //         0045381b     LEA        EDX,[EBX + 0x28]
    //         0045381e     PUSH       0x4
    //         00453820     PUSH       EDX
    //         00453821     PUSH       ESI
    //         00453822     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         00453827     ADD        ESP,0xc
    //                              m_s_obj.cpp:699 (15)
    //         0045382a     LEA        EAX,[EBX + 0x2c]
    //         0045382d     PUSH       0x1
    //         0045382f     PUSH       EAX
    //         00453830     PUSH       ESI
    //         00453831     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         00453836     ADD        ESP,0xc
    //                              m_s_obj.cpp:700 (15)
    //         00453839     LEA        this,[EBX + 0x30]
    //         0045383c     PUSH       0x4
    //         0045383e     PUSH       this
    //         0045383f     PUSH       ESI
    //         00453840     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         00453845     ADD        ESP,0xc
    //                              m_s_obj.cpp:701 (15)
    //         00453848     LEA        EDX,[EBX + 0x34]
    //         0045384b     PUSH       0x4
    //         0045384d     PUSH       EDX
    //         0045384e     PUSH       ESI
    //         0045384f     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         00453854     ADD        ESP,0xc
    //                              m_s_obj.cpp:702 (15)
    //         00453857     LEA        EAX,[EBX + 0x38]
    //         0045385a     PUSH       0x4
    //         0045385c     PUSH       EAX
    //         0045385d     PUSH       ESI
    //         0045385e     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         00453863     ADD        ESP,0xc
    //                              m_s_obj.cpp:703 (16)
    //         00453866     LEA        this=>local_10,[ESP + 0x20]
    //         0045386a     PUSH       0x2
    //         0045386c     PUSH       this
    //         0045386d     PUSH       ESI
    //         0045386e     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         00453873     ADD        ESP,0xc
    //                              m_s_obj.cpp:704 (15)
    //         00453876     LEA        EDX,[EBX + 0x48]
    //         00453879     PUSH       0x2
    //         0045387b     PUSH       EDX
    //         0045387c     PUSH       ESI
    //         0045387d     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         00453882     ADD        ESP,0xc
    //                              m_s_obj.cpp:705 (15)
    //         00453885     LEA        EAX,[EBX + 0x4a]
    //         00453888     PUSH       0x1
    //         0045388a     PUSH       EAX
    //         0045388b     PUSH       ESI
    //         0045388c     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         00453891     ADD        ESP,0xc
    //                              m_s_obj.cpp:706 (15)
    //         00453894     LEA        this,[EBX + 0x4b]
    //         00453897     PUSH       0x1
    //         00453899     PUSH       this
    //         0045389a     PUSH       ESI
    //         0045389b     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         004538a0     ADD        ESP,0xc
    //                              m_s_obj.cpp:707 (15)
    //         004538a3     LEA        EDX,[EBX + 0x4c]
    //         004538a6     PUSH       0x2
    //         004538a8     PUSH       EDX
    //         004538a9     PUSH       ESI
    //         004538aa     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         004538af     ADD        ESP,0xc
    //                              m_s_obj.cpp:708 (15)
    //         004538b2     LEA        EAX,[EBX + 0x4e]
    //         004538b5     PUSH       0x1
    //         004538b7     PUSH       EAX
    //         004538b8     PUSH       ESI
    //         004538b9     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         004538be     ADD        ESP,0xc
    //                              m_s_obj.cpp:709 (15)
    //         004538c1     LEA        this,[EBX + 0x50]
    //         004538c4     PUSH       0x2
    //         004538c6     PUSH       this
    //         004538c7     PUSH       ESI
    //         004538c8     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         004538cd     ADD        ESP,0xc
    //                              m_s_obj.cpp:710 (15)
    //         004538d0     LEA        EDX,[EBX + 0x52]
    //         004538d3     PUSH       0x1
    //         004538d5     PUSH       EDX
    //         004538d6     PUSH       ESI
    //         004538d7     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         004538dc     ADD        ESP,0xc
    //                              m_s_obj.cpp:711 (15)
    //         004538df     LEA        EAX,[EBX + 0x54]
    //         004538e2     PUSH       0x2
    //         004538e4     PUSH       EAX
    //         004538e5     PUSH       ESI
    //         004538e6     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         004538eb     ADD        ESP,0xc
    //                              m_s_obj.cpp:712 (15)
    //         004538ee     LEA        this,[EBX + 0x56]
    //         004538f1     PUSH       0x2
    //         004538f3     PUSH       this
    //         004538f4     PUSH       ESI
    //         004538f5     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         004538fa     ADD        ESP,0xc
    //                              m_s_obj.cpp:713 (15)
    //         004538fd     LEA        EDX,[EBX + 0x58]
    //         00453900     PUSH       0x2
    //         00453902     PUSH       EDX
    //         00453903     PUSH       ESI
    //         00453904     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         00453909     ADD        ESP,0xc
    //                              m_s_obj.cpp:714 (15)
    //         0045390c     LEA        EAX,[EBX + 0x5a]
    //         0045390f     PUSH       0x2
    //         00453911     PUSH       EAX
    //         00453912     PUSH       ESI
    //         00453913     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         00453918     ADD        ESP,0xc
    //                              m_s_obj.cpp:715 (15)
    //         0045391b     LEA        this,[EBX + 0x5c]
    //         0045391e     PUSH       0x4
    //         00453920     PUSH       this
    //         00453921     PUSH       ESI
    //         00453922     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         00453927     ADD        ESP,0xc
    //                              m_s_obj.cpp:716 (15)
    //         0045392a     LEA        EDX,[EBX + 0x60]
    //         0045392d     PUSH       0x4
    //         0045392f     PUSH       EDX
    //         00453930     PUSH       ESI
    //         00453931     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         00453936     ADD        ESP,0xc
    //                              m_s_obj.cpp:717 (15)
    //         00453939     LEA        EAX,[EBX + 0x64]
    //         0045393c     PUSH       0x1
    //         0045393e     PUSH       EAX
    //         0045393f     PUSH       ESI
    //         00453940     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         00453945     ADD        ESP,0xc
    //                              m_s_obj.cpp:718 (15)
    //         00453948     LEA        this,[EBX + 0x65]
    //         0045394b     PUSH       0x1
    //         0045394d     PUSH       this
    //         0045394e     PUSH       ESI
    //         0045394f     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         00453954     ADD        ESP,0xc
    //                              m_s_obj.cpp:719 (15)
    //         00453957     LEA        EDX,[EBX + 0x66]
    //         0045395a     PUSH       0x2
    //         0045395c     PUSH       EDX
    //         0045395d     PUSH       ESI
    //         0045395e     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         00453963     ADD        ESP,0xc
    //                              m_s_obj.cpp:720 (15)
    //         00453966     LEA        EAX,[EBX + 0x68]
    //         00453969     PUSH       0x1
    //         0045396b     PUSH       EAX
    //         0045396c     PUSH       ESI
    //         0045396d     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         00453972     ADD        ESP,0xc
    //                              m_s_obj.cpp:721 (15)
    //         00453975     LEA        this,[EBX + 0x7c]
    //         00453978     PUSH       0x2
    //         0045397a     PUSH       this
    //         0045397b     PUSH       ESI
    //         0045397c     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         00453981     ADD        ESP,0xc
    //                              m_s_obj.cpp:722 (18)
    //         00453984     LEA        EDX,[EBX + 0x80]
    //         0045398a     PUSH       0x4
    //         0045398c     PUSH       EDX
    //         0045398d     PUSH       ESI
    //         0045398e     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         00453993     ADD        ESP,0xc
    //                              m_s_obj.cpp:723 (18)
    //         00453996     LEA        EAX,[EBX + 0x8b]
    //         0045399c     PUSH       0x1
    //         0045399e     PUSH       EAX
    //         0045399f     PUSH       ESI
    //         004539a0     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         004539a5     ADD        ESP,0xc
    //                              m_s_obj.cpp:724 (18)
    //         004539a8     LEA        this,[EBX + 0x8c]
    //         004539ae     PUSH       0x1
    //         004539b0     PUSH       this
    //         004539b1     PUSH       ESI
    //         004539b2     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         004539b7     ADD        ESP,0xc
    //                              m_s_obj.cpp:725 (18)
    //         004539ba     LEA        EDX,[EBX + 0x8d]
    //         004539c0     PUSH       0x1
    //         004539c2     PUSH       EDX
    //         004539c3     PUSH       ESI
    //         004539c4     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         004539c9     ADD        ESP,0xc
    //                              m_s_obj.cpp:726 (18)
    //         004539cc     LEA        EAX,[EBX + 0x8e]
    //         004539d2     PUSH       0x1
    //         004539d4     PUSH       EAX
    //         004539d5     PUSH       ESI
    //         004539d6     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         004539db     ADD        ESP,0xc
    //                              m_s_obj.cpp:727 (18)
    //         004539de     LEA        this,[EBX + 0x8f]
    //         004539e4     PUSH       0x1
    //         004539e6     PUSH       this
    //         004539e7     PUSH       ESI
    //         004539e8     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         004539ed     ADD        ESP,0xc
    //                              m_s_obj.cpp:728 (18)
    //         004539f0     LEA        EDX,[EBX + 0x84]
    //         004539f6     PUSH       0x4
    //         004539f8     PUSH       EDX
    //         004539f9     PUSH       ESI
    //         004539fa     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         004539ff     ADD        ESP,0xc
    //                              m_s_obj.cpp:729 (18)
    //         00453a02     LEA        EAX,[EBX + 0x90]
    //         00453a08     PUSH       0x1
    //         00453a0a     PUSH       EAX
    //         00453a0b     PUSH       ESI
    //         00453a0c     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         00453a11     ADD        ESP,0xc
    //                              m_s_obj.cpp:730 (18)
    //         00453a14     LEA        this,[EBX + 0x98]
    //         00453a1a     PUSH       0x4
    //         00453a1c     PUSH       this
    //         00453a1d     PUSH       ESI
    //         00453a1e     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         00453a23     ADD        ESP,0xc
    //                              m_s_obj.cpp:731 (18)
    //         00453a26     LEA        EDX,[EBX + 0x9c]
    //         00453a2c     PUSH       0x4
    //         00453a2e     PUSH       EDX
    //         00453a2f     PUSH       ESI
    //         00453a30     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         00453a35     ADD        ESP,0xc
    //                              m_s_obj.cpp:732 (18)
    //         00453a38     LEA        EAX,[EBX + 0xa0]
    //         00453a3e     PUSH       0x4
    //         00453a40     PUSH       EAX
    //         00453a41     PUSH       ESI
    //         00453a42     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         00453a47     ADD        ESP,0xc
    //                              m_s_obj.cpp:733 (18)
    //         00453a4a     LEA        this,[EBX + 0xa4]
    //         00453a50     PUSH       0x1
    //         00453a52     PUSH       this
    //         00453a53     PUSH       ESI
    //         00453a54     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         00453a59     ADD        ESP,0xc
    //                              m_s_obj.cpp:734 (18)
    //         00453a5c     LEA        EDX,[EBX + 0xa5]
    //         00453a62     PUSH       0x1
    //         00453a64     PUSH       EDX
    //         00453a65     PUSH       ESI
    //         00453a66     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         00453a6b     ADD        ESP,0xc
    //                              m_s_obj.cpp:735 (18)
    //         00453a6e     LEA        EAX,[EBX + 0xa6]
    //         00453a74     PUSH       0x1
    //         00453a76     PUSH       EAX
    //         00453a77     PUSH       ESI
    //         00453a78     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         00453a7d     ADD        ESP,0xc
    //                              m_s_obj.cpp:736 (18)
    //         00453a80     LEA        this,[EBX + 0xa7]
    //         00453a86     PUSH       0x1
    //         00453a88     PUSH       this
    //         00453a89     PUSH       ESI
    //         00453a8a     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         00453a8f     ADD        ESP,0xc
    //                              m_s_obj.cpp:738 (18)
    //         00453a92     LEA        EDX,[EBX + 0xa8]
    //         00453a98     PUSH       0x1
    //         00453a9a     PUSH       EDX
    //         00453a9b     PUSH       ESI
    //         00453a9c     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         00453aa1     ADD        ESP,0xc
    //                              m_s_obj.cpp:739 (18)
    //         00453aa4     LEA        EAX,[EBX + 0xa9]
    //         00453aaa     PUSH       0x1
    //         00453aac     PUSH       EAX
    //         00453aad     PUSH       ESI
    //         00453aae     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         00453ab3     ADD        ESP,0xc
    //                              m_s_obj.cpp:740 (18)
    //         00453ab6     LEA        this,[EBX + 0xac]
    //         00453abc     PUSH       0x4
    //         00453abe     PUSH       this
    //         00453abf     PUSH       ESI
    //         00453ac0     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         00453ac5     ADD        ESP,0xc
    //                              m_s_obj.cpp:741 (18)
    //         00453ac8     LEA        EDX,[EBX + 0xb0]
    //         00453ace     PUSH       0x4
    //         00453ad0     PUSH       EDX
    //         00453ad1     PUSH       ESI
    //         00453ad2     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         00453ad7     ADD        ESP,0xc
    //                              m_s_obj.cpp:742 (42)
    //         00453ada     LEA        EAX,[EBX + 0xb4]
    //         00453ae0     PUSH       0x4
    //         00453ae2     PUSH       EAX
    //         00453ae3     PUSH       ESI
    //         00453ae4     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         00453ae9     LEA        this,[EBX + 0x88]
    //         00453aef     ADD        ESP,0xc
    //         00453af2     MOV        dword ptr [ESP + param_1],this
    //         00453af6     LEA        EBP,[EBX + 0x70]
    //         00453af9     LEA        EDI,[EBX + 0x6a]
    //         00453afc     MOV        dword ptr [ESP + selected_sound_num],0x3
    //                               LAB_00453b04                                                 XREF[1]:     00453b44(j)  
    //                              m_s_obj.cpp:746 (12)
    //         00453b04     PUSH       0x2
    //         00453b06     PUSH       EDI
    //         00453b07     PUSH       ESI
    //         00453b08     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         00453b0d     ADD        ESP,0xc
    //                              m_s_obj.cpp:747 (9)
    //         00453b10     PUSH       0x4
    //         00453b12     PUSH       EBP
    //         00453b13     PUSH       ESI
    //         00453b14     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //                              m_s_obj.cpp:748 (45)
    //         00453b19     MOV        EDX,dword ptr [ESP + param_1]
    //         00453b1d     ADD        ESP,0xc
    //         00453b20     PUSH       0x1
    //         00453b22     PUSH       EDX
    //         00453b23     PUSH       ESI
    //         00453b24     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         00453b29     MOV        this,dword ptr [ESP + param_1]
    //         00453b2d     MOV        EAX,dword ptr [ESP + selected_sound_num]
    //         00453b31     ADD        ESP,0xc
    //         00453b34     ADD        EDI,0x2
    //         00453b37     ADD        EBP,0x4
    //         00453b3a     INC        this
    //         00453b3b     DEC        EAX
    //         00453b3c     MOV        dword ptr [ESP + param_1],this
    //         00453b40     MOV        dword ptr [ESP + selected_sound_num],EAX
    //         00453b44     JNZ        LAB_00453b04
    //                              m_s_obj.cpp:752 (15)
    //         00453b46     LEA        EDI,[EBX + 0x93]
    //         00453b4c     PUSH       0x1
    //         00453b4e     PUSH       EDI
    //         00453b4f     PUSH       ESI
    //         00453b50     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //                              m_s_obj.cpp:753 (9)
    //         00453b55     MOV        AL,byte ptr [EDI]
    //         00453b57     ADD        ESP,0xc
    //         00453b5a     TEST       AL,AL
    //         00453b5c     JBE        LAB_00453bbc
    //                              m_s_obj.cpp:755 (6)
    //         00453b5e     XOR        EBP,EBP
    //         00453b60     TEST       AL,AL
    //         00453b62     JBE        LAB_00453bbc
    //                               LAB_00453b64                                                 XREF[1]:     00453bba(j)  
    //                              m_s_obj.cpp:757 (27)
    //         00453b64     MOV        EAX,dword ptr [EBX + 0x94]
    //         00453b6a     PUSH       0x2
    //         00453b6c     MOVSX      EDI,BP
    //         00453b6f     SHL        EDI,0x3
    //         00453b72     MOV        this,dword ptr [EAX + EDI*0x1]
    //         00453b75     ADD        this,0x72
    //         00453b78     PUSH       this
    //         00453b79     PUSH       ESI
    //         00453b7a     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //                              m_s_obj.cpp:758 (22)
    //         00453b7f     MOV        EDX,dword ptr [EBX + 0x94]
    //         00453b85     ADD        ESP,0xc
    //         00453b88     LEA        EAX,[EDX + EDI*0x1 + 0x4]
    //         00453b8c     PUSH       0x2
    //         00453b8e     PUSH       EAX
    //         00453b8f     PUSH       ESI
    //         00453b90     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //                              m_s_obj.cpp:759 (39)
    //         00453b95     MOV        this,dword ptr [EBX + 0x94]
    //         00453b9b     ADD        ESP,0xc
    //         00453b9e     LEA        EDX,[ECX + EDI*0x1 + this+0x5]
    //         00453ba2     PUSH       0x1
    //         00453ba4     PUSH       EDX
    //         00453ba5     PUSH       ESI
    //         00453ba6     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         00453bab     MOVZX      AX,byte ptr [EBX + 0x93]
    //         00453bb3     ADD        ESP,0xc
    //         00453bb6     INC        EBP
    //         00453bb7     CMP        BP,AX
    //         00453bba     JL         LAB_00453b64
    //                               LAB_00453bbc                                                 XREF[2]:     00453b5c(j), 00453b62(j)  
    //                              m_s_obj.cpp:763 (16)
    //         00453bbc     LEA        this=>death_sound_num,[ESP + 0x28]
    //         00453bc0     PUSH       0x2
    //         00453bc2     PUSH       this
    //         00453bc3     PUSH       ESI
    //         00453bc4     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         00453bc9     ADD        ESP,0xc
    //                              m_s_obj.cpp:764 (16)
    //         00453bcc     LEA        EDX=>local_4,[ESP + 0x2c]
    //         00453bd0     PUSH       0x2
    //         00453bd2     PUSH       EDX
    //         00453bd3     PUSH       ESI
    //         00453bd4     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         00453bd9     ADD        ESP,0xc
    //                              m_s_obj.cpp:765 (18)
    //         00453bdc     LEA        EAX,[EBX + 0x91]
    //         00453be2     PUSH       0x1
    //         00453be4     PUSH       EAX
    //         00453be5     PUSH       ESI
    //         00453be6     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         00453beb     ADD        ESP,0xc
    //                              m_s_obj.cpp:766 (15)
    //         00453bee     LEA        this,[EBX + 0x92]
    //         00453bf4     PUSH       0x1
    //         00453bf6     PUSH       this
    //         00453bf7     PUSH       ESI
    //         00453bf8     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //                              m_s_obj.cpp:768 (12)
    //         00453bfd     MOV        EAX,dword ptr [ESP + temp_sprite]
    //         00453c01     ADD        ESP,0xc
    //         00453c04     TEST       AX,AX
    //         00453c07     JZ         LAB_00453c1a
    //                              m_s_obj.cpp:769 (17)
    //         00453c09     MOVSX      EDX,AX
    //         00453c0c     MOV        EAX,dword ptr [EBX + 0x8]
    //         00453c0f     PUSH       EDX
    //         00453c10     PUSH       EAX
    //         00453c11     PUSH       ESI
    //         00453c12     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         00453c17     ADD        ESP,0xc
    //                               LAB_00453c1a                                                 XREF[1]:     00453c07(j)  
    //                              m_s_obj.cpp:771 (15)
    //         00453c1a     ADD        EBX,0x12
    //         00453c1d     PUSH       0x2
    //         00453c1f     PUSH       EBX
    //         00453c20     PUSH       ESI
    //         00453c21     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         00453c26     ADD        ESP,0xc
    //                              m_s_obj.cpp:772 (10)
    //         00453c29     POP        EDI
    //         00453c2a     POP        ESI
    //         00453c2b     POP        EBP
    //         00453c2c     POP        EBX
    //         00453c2d     ADD        ESP,0x20
    //         00453c30     RET        0x4
}

// Offset: 0x00453C40
uchar RGE_Master_Combat_Object::check_placement(RGE_Player* param_1, float param_2, float param_3, int* param_4, uchar param_5, uchar param_6, uchar param_7, uchar param_8, uchar param_9, uchar param_10) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual unsigned char __thiscall RGE_Master_Static_Object::check_placement(class RGE_Playe... *
    //                              *********************************************************************************************************
    //                              uchar __thiscall check_placement(RGE_Master_Static_Object * this, RG
    //              uchar             AL:1           <RETURN>
    //              RGE_Master_Sta    ECX:4 (auto)   this
    //              RGE_Player *      Stack[0x4]:4   param_1                   XREF[4]:     00453c43(R), 0045404a(R), 004541f9(W), 0045420d(R)  
    //              float             Stack[0x8]:4   param_2                   XREF[6]:     00453c8f(R), 00453c9f(R), 00453d9c(R), 00454123(R), 
    //                                                                                     00454147(R), 004542e8(R)  
    //              float             Stack[0xc]:4   param_3                   XREF[6]:     00453cab(R), 00453cb7(R), 00453d93(R), 00454132(R), 
    //                                                                                     00454158(R), 004542e1(R)  
    //              int *             Stack[0x10]:4  param_4                   XREF[1]:     00454378(R)  
    //              uchar             Stack[0x14]:1  param_5                   XREF[5]:     00454033(R), 004540da(R), 00454278(W), 0045429c(R), 
    //                                                                                     004542bd(R)  
    //              uchar             Stack[0x18]:1  param_6                   XREF[4]:     00454060(R), 00454274(W), 00454287(R), 00454323(R)  
    //              uchar             Stack[0x1c]:1  param_7
    //              uchar             Stack[0x20]:1  param_8                   XREF[15]:    00453c59(R), 00453ca5(W), 00453d31(R), 00453df2(W), 
    //                                                                                     00453e5b(W), 00453ecd(W), 00453f2f(W), 00453f98(W), 
    //                                                                                     00453fad(R), 00453fcd(W), 0045405b(W), 004540e1(R), 
    //                                                                                     00454260(W), 00454267(R), 00454310(R)  
    //              uchar             Stack[0x24]:1  param_9                   XREF[2]:     004541bb(R), 0045423e(R)  
    //              uchar             Stack[0x28]:1  param_10                  XREF[4]:     004541af(R), 004541e2(W), 00454354(R), 00454362(W)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[4]:     00453c67(W), 00454018(R), 00454203(W), 00454358(R)  
    //              float *           Stack[-0x8]:4  terrain_table             XREF[3]:     00453e18(W), 00453f44(R), 00453f58(R)  
    //              short             Stack[-0xc]:2  req_x1                    XREF[3]:     00453d1a(W), 00453d1e(R), 00453ef0(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[3]:     00453d85(W), 00453de2(W), 00453ec9(R)  
    //              short             Stack[-0x14]:2 edge_x1                   XREF[3]:     00453ceb(W), 00453cef(R), 00453e78(R)  
    //              undefined4        Stack[-0x18]:4 local_18                  XREF[7]:     00453cd7(W), 00453cf3(R), 00453d3a(R), 00453d5a(W), 
    //                                                                                     00453d7b(R), 00453fe1(R), 004540c2(R)  
    //              float             Stack[-0x1c]:2 tx2                       XREF[6]:     00453c7b(W), 00453c8b(W), 00453c97(R), 00453cbb(R), 
    //                                                                                     00454106(R), 00454327(R)  
    //              float             Stack[-0x20]:4 ry                        XREF[6]:     00453c77(W), 00453c87(W), 00453c93(R), 00453c9b(R), 
    //                                                                                     004540f5(R), 00454314(R)  
    //              float             Stack[-0x24]:4 rx                        XREF[10]:    00453d40(W), 00453fc9(R), 00453fd7(W), 00453ff2(R), 
    //                                                                                     004540c6(R), 004540d0(W), 0045413e(W), 00454176(W), 
    //                                                                                     004541ec(R), 00454209(R)  
    //              short             Stack[-0x28]:2 x1                        XREF[9]:     00453cd1(W), 00453d02(R), 00453d49(R), 00453d81(W), 
    //                                                                                     00453de6(W), 00453e21(R), 00453e46(R), 00453e74(R), 
    //                                                                                     00453ef6(R)  
    //              float             Stack[-0x2c]:2 ty1                       XREF[10]:    00453cde(W), 00453d22(R), 00453d56(R), 00453d67(W), 
    //                                                                                     00453fe5(R), 004540b7(R), 00454170(W), 004541ab(W), 
    //                                                                                     004541db(R), 0045435d(R)  
    //              float             Stack[-0x30]:2 ty2                       XREF[7]:     00453d89(W), 00453dde(W), 00453e10(R), 00453e84(R), 
    //                                                                                     00453eaa(R), 00453f4c(R), 00453f65(R)  
    //              short             Stack[-0x34]:2 edge_y1                   XREF[7]:     00453d8d(W), 00453dea(W), 00453e89(R), 00453e98(R), 
    //                                                                                     00453ee6(R), 00453f51(R), 00453f73(R)  
    //              short             Stack[-0x38]:2 edge_y2                   XREF[8]:     00453d4d(W), 00453d77(R), 00453fd2(R), 004540cb(R), 
    //                                                                                     00454164(W), 00454190(W), 00454219(R), 00454349(R)  
    //              short             Stack[-0x3c]:2 x2                        XREF[8]:     00453c6b(W), 00453e2f(R), 00453e90(R), 00453f03(R), 
    //                                                                                     00453f5d(R), 00453ffd(R), 00454068(R), 0045417e(R)  
    //              RGE_Map *         Stack[-0x40]:4 map                       XREF[8]:     00453c61(W), 00453dee(R), 00453e70(R), 00453e94(R), 
    //                                                                                     00453ee2(R), 00453f61(R), 00454072(R), 004541bf(R)  
    //              undefined1        Stack[-0x41]:1 local_41                  XREF[6]:     00453df7(W), 00453e65(W), 00453ed7(W), 00453f39(W), 
    //                                                                                     00453fa2(W), 00453fb5(R)  
    //              uchar             Stack[-0x45]:1 req_terr2
    //                               ?check_placement@RGE_Master_Static_Object@@UAEEPAVRGE_Playe  XREF[10]:    00570468(*), 005704a8(*), 
    //                               RGE_Master_Static_Object::check_placement                                 005704e0(*), 00570540(*), 
    //                                                                                                         00570580(*), 005705c0(*), 
    //                                                                                                         005705f8(*), 00576720(*), 
    //                                                                                                         00576760(*), 005767b0(*)  
    //                              m_s_obj.cpp:778 (3)
    //         00453c40     SUB        ESP,0x44
    //                              m_s_obj.cpp:779 (12)
    //         00453c43     MOV        EAX,dword ptr [ESP + param_1]
    //         00453c47     PUSH       EBX
    //         00453c48     PUSH       EBP
    //         00453c49     MOV        EBP,this
    //         00453c4b     MOV        EAX,dword ptr [EAX + 0x3c]
    //         00453c4e     PUSH       ESI
    //                              m_s_obj.cpp:806 (7)
    //         00453c4f     MOVSX      this,word ptr [EBP + 0x66]
    //         00453c53     MOV        EDX,dword ptr [EAX + 0x54]
    //                              m_s_obj.cpp:807 (3)
    //         00453c56     MOV        EBX,dword ptr [EAX + 0x28]
    //                              m_s_obj.cpp:817 (24)
    //         00453c59     MOV        AL,byte ptr [ESP + param_8]
    //         00453c5d     PUSH       EDI
    //         00453c5e     MOV        this,dword ptr [EDX + this->_padding_*0x4]
    //         00453c61     MOV        dword ptr [ESP + map],EBP
    //         00453c65     TEST       AL,AL
    //         00453c67     MOV        dword ptr [ESP + local_4],this
    //         00453c6b     MOV        dword ptr [ESP + x2],EBX
    //         00453c6f     JZ         LAB_00453c81
    //                              m_s_obj.cpp:819 (3)
    //         00453c71     MOV        EDX,dword ptr [EBP + 0x5c]
    //                              m_s_obj.cpp:820 (11)
    //         00453c74     MOV        EAX,dword ptr [EBP + 0x60]
    //         00453c77     MOV        dword ptr [ESP + ry],EDX
    //         00453c7b     MOV        dword ptr [ESP + tx2],EAX
    //                              m_s_obj.cpp:822 (2)
    //         00453c7f     JMP        LAB_00453c8f
    //                               LAB_00453c81                                                 XREF[1]:     00453c6f(j)  
    //                              m_s_obj.cpp:824 (3)
    //         00453c81     MOV        this,dword ptr [EBP + 0x30]
    //                              m_s_obj.cpp:825 (11)
    //         00453c84     MOV        EDX,dword ptr [EBP + 0x34]
    //         00453c87     MOV        dword ptr [ESP + ry],this
    //         00453c8b     MOV        dword ptr [ESP + tx2],EDX
    //                               LAB_00453c8f                                                 XREF[1]:     00453c7f(j)  
    //                              m_s_obj.cpp:828 (8)
    //         00453c8f     FLD        float ptr [ESP + param_2]
    //         00453c93     FSUB       float ptr [ESP + ry]
    //                              m_s_obj.cpp:831 (20)
    //         00453c97     FLD        float ptr [ESP + tx2]
    //         00453c9b     FLD        float ptr [ESP + ry]
    //         00453c9f     FADD       float ptr [ESP + param_2]
    //         00453ca3     FXCH       ST2
    //         00453ca5     FST        float ptr [ESP + param_8]
    //         00453ca9     FXCH
    //                              m_s_obj.cpp:833 (134)
    //         00453cab     FADD       float ptr [ESP + param_3]
    //         00453caf     FXCH
    //         00453cb1     FCOMP      double ptr [DAT_00570620]
    //         00453cb7     FLD        float ptr [ESP + param_3]
    //         00453cbb     FSUB       float ptr [ESP + tx2]
    //         00453cbf     FXCH       ST2
    //         00453cc1     FSUB       float ptr [DAT_0057061c]                         = 6Fh    o
    //         00453cc7     FXCH
    //         00453cc9     FSUB       float ptr [DAT_0057061c]                         = 6Fh    o
    //         00453ccf     FXCH       ST2
    //         00453cd1     FSTP       float ptr [ESP + x1]
    //         00453cd5     FNSTSW     AX
    //         00453cd7     FSTP       float ptr [ESP + local_18]
    //         00453cdb     TEST       AH,0x1
    //         00453cde     FSTP       float ptr [ESP + ty1]
    //         00453ce2     JNZ        LAB_00454391
    //         00453ce8     MOV        EAX,dword ptr [EBX + 0x8]
    //         00453ceb     MOV        dword ptr [ESP + edge_x1],EAX
    //         00453cef     FILD       dword ptr [ESP + edge_x1]
    //         00453cf3     FCOMP      float ptr [ESP + local_18]
    //         00453cf7     FNSTSW     AX
    //         00453cf9     TEST       AH,0x41
    //         00453cfc     JNZ        LAB_00454391
    //         00453d02     FLD        float ptr [ESP + x1]
    //         00453d06     FCOMP      double ptr [DAT_00570620]
    //         00453d0c     FNSTSW     AX
    //         00453d0e     TEST       AH,0x1
    //         00453d11     JNZ        LAB_00454391
    //         00453d17     MOV        this,dword ptr [EBX + 0xc]
    //         00453d1a     MOV        dword ptr [ESP + req_x1],this
    //         00453d1e     FILD       dword ptr [ESP + req_x1]
    //         00453d22     FCOMP      float ptr [ESP + ty1]
    //         00453d26     FNSTSW     AX
    //         00453d28     TEST       AH,0x41
    //         00453d2b     JNZ        LAB_00454391
    //                              m_s_obj.cpp:836 (9)
    //         00453d31     FLD        float ptr [ESP + param_8]
    //         00453d35     CALL       __ftol                                           undefined __ftol()
    //                              m_s_obj.cpp:837 (15)
    //         00453d3a     FLD        float ptr [ESP + local_18]
    //         00453d3e     MOV        EDI,EAX
    //         00453d40     MOV        dword ptr [ESP + rx],EDI
    //         00453d44     CALL       __ftol                                           undefined __ftol()
    //                              m_s_obj.cpp:838 (13)
    //         00453d49     FLD        float ptr [ESP + x1]
    //         00453d4d     MOV        dword ptr [ESP + edge_y2],EAX
    //         00453d51     CALL       __ftol                                           undefined __ftol()
    //                              m_s_obj.cpp:839 (13)
    //         00453d56     FLD        float ptr [ESP + ty1]
    //         00453d5a     MOV        dword ptr [ESP + local_18],EAX
    //         00453d5e     CALL       __ftol                                           undefined __ftol()
    //                              m_s_obj.cpp:842 (20)
    //         00453d63     MOV        SI,word ptr [EBP + 0x58]
    //         00453d67     MOV        dword ptr [ESP + ty1],EAX
    //         00453d6b     TEST       SI,SI
    //         00453d6e     JGE        LAB_00453d93
    //         00453d70     CMP        word ptr [EBP + 0x5a],0x0
    //         00453d75     JGE        LAB_00453d93
    //                              m_s_obj.cpp:860 (4)
    //         00453d77     MOV        EDX,dword ptr [ESP + edge_y2]
    //                              m_s_obj.cpp:861 (18)
    //         00453d7b     MOV        this,dword ptr [ESP + local_18]
    //         00453d7f     MOV        EBX,EDI
    //         00453d81     MOV        dword ptr [ESP + x1],EDX
    //         00453d85     MOV        dword ptr [ESP + local_10],EBX
    //         00453d89     MOV        dword ptr [ESP + ty2],this
    //                              m_s_obj.cpp:862 (6)
    //         00453d8d     MOV        dword ptr [ESP + edge_y1],EAX
    //         00453d91     JMP        LAB_00453dee
    //                               LAB_00453d93                                                 XREF[2]:     00453d6e(j), 00453d75(j)  
    //                              m_s_obj.cpp:844 (46)
    //         00453d93     FLD        float ptr [ESP + param_3]
    //         00453d97     CALL       __ftol                                           undefined __ftol()
    //         00453d9c     FLD        float ptr [ESP + param_2]
    //         00453da0     MOV        DI,AX
    //         00453da3     CALL       __ftol                                           undefined __ftol()
    //         00453da8     MOV        EBX,dword ptr [EBX + 0x8d8c]
    //         00453dae     MOVSX      EDX,DI
    //         00453db1     MOVSX      this,AX
    //         00453db4     MOV        EDX,dword ptr [EBX + EDX*0x4]
    //         00453db7     LEA        this,[ECX + ECX*0x2]
    //         00453dba     MOV        this,byte ptr [EDX + this->_padding_*0x8 + 0x5]
    //         00453dbe     AND        this,0x1f
    //                              m_s_obj.cpp:845 (15)
    //         00453dc1     MOVZX      this,this
    //         00453dc5     CMP        this,SI
    //         00453dc8     JZ         LAB_00453ddc
    //         00453dca     CMP        this,word ptr [EBP + 0x5a]
    //         00453dce     JZ         LAB_00453ddc
    //                              m_s_obj.cpp:846 (2)
    //         00453dd0     MOV        AL,0x1
    //                              m_s_obj.cpp:1011 (10)
    //         00453dd2     POP        EDI
    //         00453dd3     POP        ESI
    //         00453dd4     POP        EBP
    //         00453dd5     POP        EBX
    //         00453dd6     ADD        ESP,0x44
    //         00453dd9     RET        0x28
    //                               LAB_00453ddc                                                 XREF[2]:     00453dc8(j), 00453dce(j)  
    //                              m_s_obj.cpp:852 (2)
    //         00453ddc     MOV        EBX,EAX
    //                              m_s_obj.cpp:854 (12)
    //         00453dde     MOV        dword ptr [ESP + ty2],EDI
    //         00453de2     MOV        dword ptr [ESP + local_10],EBX
    //         00453de6     MOV        dword ptr [ESP + x1],EBX
    //                              m_s_obj.cpp:855 (4)
    //         00453dea     MOV        dword ptr [ESP + edge_y1],EDI
    //                               LAB_00453dee                                                 XREF[1]:     00453d91(j)  
    //                              m_s_obj.cpp:870 (34)
    //         00453dee     MOV        EDX,dword ptr [ESP + map]
    //         00453df2     MOV        byte ptr [ESP + param_8],0x0
    //         00453df7     MOV        byte ptr [ESP + local_41],0x0
    //         00453dfc     MOV        BP,word ptr [EDX + 0x54]
    //         00453e00     TEST       BP,BP
    //         00453e03     JGE        LAB_00453e10
    //         00453e05     CMP        word ptr [EDX + 0x56],0x0
    //         00453e0a     JL         LAB_00453fc9
    //                               LAB_00453e10                                                 XREF[1]:     00453e03(j)  
    //                              m_s_obj.cpp:874 (12)
    //         00453e10     MOV        this,dword ptr [ESP + ty2]
    //         00453e14     LEA        EAX,[EBX + -0x1]
    //         00453e17     DEC        this
    //         00453e18     MOV        dword ptr [ESP + terrain_table],EAX
    //                              m_s_obj.cpp:878 (5)
    //         00453e1c     TEST       this,this
    //         00453e1f     JL         LAB_00453e74
    //                              m_s_obj.cpp:879 (7)
    //         00453e21     CMP        BX,word ptr [ESP + x1]
    //         00453e26     JG         LAB_00453e74
    //                              m_s_obj.cpp:883 (4)
    //         00453e28     MOV        DI,word ptr [EDX + 0x56]
    //                              m_s_obj.cpp:1011 (47)
    //         00453e2c     MOVSX      EDX,this
    //         00453e2f     MOV        this,dword ptr [ESP + x2]
    //         00453e33     MOVSX      EAX,BX
    //         00453e36     MOV        this,dword ptr [this->_padding_ + 0x8d8c]
    //         00453e3c     LEA        ESI,[EAX + EAX*0x2]
    //         00453e3f     MOV        EDX,dword ptr [this->_padding_ + EDX*0x4]
    //         00453e42     LEA        this,[EDX + ESI*0x8 + 0x5]
    //         00453e46     MOVSX      ESI,word ptr [ESP + x1]
    //         00453e4b     SUB        ESI,EAX
    //         00453e4d     INC        ESI
    //                               LAB_00453e4e                                                 XREF[1]:     00453e6e(j)  
    //         00453e4e     MOV        AL,byte ptr [this->_padding_]
    //         00453e50     AND        AL,0x1f
    //         00453e52     MOVZX      AX,AL
    //         00453e56     CMP        AX,BP
    //         00453e59     JNZ        LAB_00453e60
    //                              m_s_obj.cpp:882 (5)
    //         00453e5b     MOV        byte ptr [ESP + param_8],0x1
    //                               LAB_00453e60                                                 XREF[1]:     00453e59(j)  
    //                              m_s_obj.cpp:883 (10)
    //         00453e60     CMP        AX,DI
    //         00453e63     JNZ        LAB_00453e6a
    //         00453e65     MOV        byte ptr [ESP + local_41],0x1
    //                               LAB_00453e6a                                                 XREF[1]:     00453e63(j)  
    //                              m_s_obj.cpp:879 (10)
    //         00453e6a     ADD        this,0x18
    //         00453e6d     DEC        ESI
    //         00453e6e     JNZ        LAB_00453e4e
    //         00453e70     MOV        EDX,dword ptr [ESP + map]
    //                               LAB_00453e74                                                 XREF[2]:     00453e1f(j), 00453e26(j)  
    //                              m_s_obj.cpp:886 (16)
    //         00453e74     MOV        EAX,dword ptr [ESP + x1]
    //         00453e78     MOV        this,dword ptr [ESP + edge_x1]
    //         00453e7c     INC        EAX
    //         00453e7d     MOVSX      EAX,AX
    //         00453e80     CMP        EAX,this
    //         00453e82     JGE        LAB_00453ee6
    //                              m_s_obj.cpp:887 (12)
    //         00453e84     MOV        this,word ptr [ESP + ty2]
    //         00453e89     CMP        this,word ptr [ESP + edge_y1]
    //         00453e8e     JG         LAB_00453ee6
    //                              m_s_obj.cpp:1011 (66)
    //         00453e90     MOV        ESI,dword ptr [ESP + x2]
    //         00453e94     MOV        EDX,dword ptr [ESP + map]
    //         00453e98     MOVSX      EDI,word ptr [ESP + edge_y1]
    //         00453e9d     MOV        ESI,dword ptr [ESI + 0x8d8c]
    //         00453ea3     MOV        DX,word ptr [EDX + 0x56]
    //         00453ea7     LEA        this,[EAX + EAX*0x2]
    //         00453eaa     MOVSX      EAX,word ptr [ESP + ty2]
    //         00453eaf     SUB        EDI,EAX
    //         00453eb1     SHL        this,0x3
    //         00453eb4     LEA        ESI,[ESI + EAX*0x4]
    //         00453eb7     INC        EDI
    //                               LAB_00453eb8                                                 XREF[1]:     00453ee0(j)  
    //         00453eb8     MOV        EAX,dword ptr [ESI]
    //         00453eba     MOV        AL,byte ptr [EAX + this->_padding_*0x1 + 0x5]
    //         00453ebe     AND        AL,0x1f
    //         00453ec0     MOVZX      AX,AL
    //         00453ec4     CMP        AX,BP
    //         00453ec7     JNZ        LAB_00453ed2
    //         00453ec9     MOV        EBX,dword ptr [ESP + local_10]
    //         00453ecd     MOV        byte ptr [ESP + param_8],0x1
    //                               LAB_00453ed2                                                 XREF[1]:     00453ec7(j)  
    //                              m_s_obj.cpp:891 (10)
    //         00453ed2     CMP        AX,DX
    //         00453ed5     JNZ        LAB_00453edc
    //         00453ed7     MOV        byte ptr [ESP + local_41],0x1
    //                               LAB_00453edc                                                 XREF[1]:     00453ed5(j)  
    //                              m_s_obj.cpp:887 (10)
    //         00453edc     ADD        ESI,0x4
    //         00453edf     DEC        EDI
    //         00453ee0     JNZ        LAB_00453eb8
    //         00453ee2     MOV        EDX,dword ptr [ESP + map]
    //                               LAB_00453ee6                                                 XREF[2]:     00453e82(j), 00453e8e(j)  
    //                              m_s_obj.cpp:894 (16)
    //         00453ee6     MOV        this,dword ptr [ESP + edge_y1]
    //         00453eea     LEA        EAX,[ECX + this+0x1]
    //         00453eed     MOVSX      this,AX
    //         00453ef0     CMP        this,dword ptr [ESP + req_x1]
    //         00453ef4     JGE        LAB_00453f44
    //                              m_s_obj.cpp:895 (9)
    //         00453ef6     MOV        EAX,dword ptr [ESP + x1]
    //         00453efa     CMP        AX,BX
    //         00453efd     JL         LAB_00453f44
    //                              m_s_obj.cpp:899 (4)
    //         00453eff     MOV        DI,word ptr [EDX + 0x56]
    //                              m_s_obj.cpp:1011 (44)
    //         00453f03     MOV        EDX,dword ptr [ESP + x2]
    //         00453f07     MOVSX      EAX,AX
    //         00453f0a     MOV        EDX,dword ptr [EDX + 0x8d8c]
    //         00453f10     LEA        ESI,[EAX + EAX*0x2]
    //         00453f13     MOV        this,dword ptr [EDX + this->_padding_*0x4]
    //         00453f16     MOVSX      EDX,BX
    //         00453f19     SUB        EAX,EDX
    //         00453f1b     LEA        this,[ECX + ESI*0x8 + this+0x5]
    //         00453f1f     INC        EAX
    //         00453f20     MOV        ESI,EAX
    //                               LAB_00453f22                                                 XREF[1]:     00453f42(j)  
    //         00453f22     MOV        AL,byte ptr [this->_padding_]
    //         00453f24     AND        AL,0x1f
    //         00453f26     MOVZX      AX,AL
    //         00453f2a     CMP        AX,BP
    //         00453f2d     JNZ        LAB_00453f34
    //                              m_s_obj.cpp:898 (5)
    //         00453f2f     MOV        byte ptr [ESP + param_8],0x1
    //                               LAB_00453f34                                                 XREF[1]:     00453f2d(j)  
    //                              m_s_obj.cpp:899 (10)
    //         00453f34     CMP        AX,DI
    //         00453f37     JNZ        LAB_00453f3e
    //         00453f39     MOV        byte ptr [ESP + local_41],0x1
    //                               LAB_00453f3e                                                 XREF[1]:     00453f37(j)  
    //                              m_s_obj.cpp:895 (6)
    //         00453f3e     SUB        this,0x18
    //         00453f41     DEC        ESI
    //         00453f42     JNZ        LAB_00453f22
    //                               LAB_00453f44                                                 XREF[2]:     00453ef4(j), 00453efd(j)  
    //                              m_s_obj.cpp:902 (8)
    //         00453f44     CMP        word ptr [ESP + terrain_table],0x0
    //         00453f4a     JL         LAB_00453fad
    //                              m_s_obj.cpp:903 (12)
    //         00453f4c     MOV        AX,word ptr [ESP + ty2]
    //         00453f51     CMP        word ptr [ESP + edge_y1],AX
    //         00453f56     JL         LAB_00453fad
    //                              m_s_obj.cpp:905 (5)
    //         00453f58     MOVSX      EAX,word ptr [ESP + terrain_table]
    //                              m_s_obj.cpp:1011 (59)
    //         00453f5d     MOV        ESI,dword ptr [ESP + x2]
    //         00453f61     MOV        EDX,dword ptr [ESP + map]
    //         00453f65     MOVSX      EDI,word ptr [ESP + ty2]
    //         00453f6a     MOV        ESI,dword ptr [ESI + 0x8d8c]
    //         00453f70     LEA        this,[EAX + EAX*0x2]
    //         00453f73     MOVSX      EAX,word ptr [ESP + edge_y1]
    //         00453f78     MOV        DX,word ptr [EDX + 0x56]
    //         00453f7c     LEA        ESI,[ESI + EAX*0x4]
    //         00453f7f     SUB        EAX,EDI
    //         00453f81     SHL        this,0x3
    //         00453f84     INC        EAX
    //         00453f85     MOV        EDI,EAX
    //                               LAB_00453f87                                                 XREF[1]:     00453fab(j)  
    //         00453f87     MOV        EAX,dword ptr [ESI]
    //         00453f89     MOV        AL,byte ptr [EAX + this->_padding_*0x1 + 0x5]
    //         00453f8d     AND        AL,0x1f
    //         00453f8f     MOVZX      AX,AL
    //         00453f93     CMP        AX,BP
    //         00453f96     JNZ        LAB_00453f9d
    //                              m_s_obj.cpp:906 (5)
    //         00453f98     MOV        byte ptr [ESP + param_8],0x1
    //                               LAB_00453f9d                                                 XREF[1]:     00453f96(j)  
    //                              m_s_obj.cpp:907 (10)
    //         00453f9d     CMP        AX,DX
    //         00453fa0     JNZ        LAB_00453fa7
    //         00453fa2     MOV        byte ptr [ESP + local_41],0x1
    //                               LAB_00453fa7                                                 XREF[1]:     00453fa0(j)  
    //                              m_s_obj.cpp:903 (6)
    //         00453fa7     SUB        ESI,0x4
    //         00453faa     DEC        EDI
    //         00453fab     JNZ        LAB_00453f87
    //                               LAB_00453fad                                                 XREF[2]:     00453f4a(j), 00453f56(j)  
    //                              m_s_obj.cpp:910 (16)
    //         00453fad     MOV        AL,byte ptr [ESP + param_8]
    //         00453fb1     TEST       AL,AL
    //         00453fb3     JNZ        LAB_00453fc9
    //         00453fb5     MOV        AL,byte ptr [ESP + local_41]
    //         00453fb9     TEST       AL,AL
    //         00453fbb     JNZ        LAB_00453fc9
    //                              m_s_obj.cpp:911 (2)
    //         00453fbd     MOV        AL,0x1
    //                              m_s_obj.cpp:1011 (10)
    //         00453fbf     POP        EDI
    //         00453fc0     POP        ESI
    //         00453fc1     POP        EBP
    //         00453fc2     POP        EBX
    //         00453fc3     ADD        ESP,0x44
    //         00453fc6     RET        0x28
    //                               LAB_00453fc9                                                 XREF[3]:     00453e0a(j), 00453fb3(j), 
    //                                                                                                         00453fbb(j)  
    //                              m_s_obj.cpp:916 (28)
    //         00453fc9     MOV        EAX,dword ptr [ESP + rx]
    //         00453fcd     MOV        byte ptr [ESP + param_8],0x0
    //         00453fd2     CMP        AX,word ptr [ESP + edge_y2]
    //         00453fd7     MOV        dword ptr [ESP + rx],EAX
    //         00453fdb     JG         LAB_004540da
    //         00453fe1     MOV        EAX,dword ptr [ESP + local_18]
    //                               LAB_00453fe5                                                 XREF[1]:     004540d4(j)  
    //                              m_s_obj.cpp:917 (13)
    //         00453fe5     CMP        AX,word ptr [ESP + ty1]
    //         00453fea     MOV        EBP,EAX
    //         00453fec     JG         LAB_004540c6
    //                              m_s_obj.cpp:919 (65)
    //         00453ff2     MOVSX      EBX,word ptr [ESP + rx]
    //         00453ff7     LEA        EDI,[EBX + EBX*0x2]
    //         00453ffa     SHL        EDI,0x3
    //                               LAB_00453ffd                                                 XREF[1]:     004540bc(j)  
    //         00453ffd     MOV        EDX,dword ptr [ESP + x2]
    //         00454001     MOVSX      this,BP
    //         00454004     MOV        EAX,dword ptr [EDX + 0x8d8c]
    //         0045400a     LEA        ESI,[this->_padding_*0x4 + 0x0]
    //         00454011     MOV        EDX,dword ptr [EAX + ESI*0x1]
    //         00454014     MOV        AL,byte ptr [EDX + EDI*0x1 + 0x5]
    //         00454018     MOV        EDX,dword ptr [ESP + local_4]
    //         0045401c     AND        EAX,0x1f
    //         0045401f     FLD        float ptr [EDX + EAX*0x4]
    //         00454022     FCOMP      float ptr [DAT_00570618]
    //         00454028     FNSTSW     AX
    //         0045402a     TEST       AH,0x41
    //         0045402d     JNZ        LAB_0045439d
    //                              m_s_obj.cpp:924 (8)
    //         00454033     MOV        AL,byte ptr [ESP + param_5]
    //         00454037     TEST       AL,AL
    //         00454039     JZ         LAB_00454060
    //                              m_s_obj.cpp:926 (12)
    //         0045403b     MOV        EAX,[rge_base_game]                              = 00000000
    //         00454040     CMP        dword ptr [EAX + 0x1b0],0x7
    //                              m_s_obj.cpp:928 (20)
    //         00454047     JZ         LAB_0045405b
    //         00454049     PUSH       this
    //         0045404a     MOV        this,dword ptr [ESP + param_1]
    //         0045404e     PUSH       EBX
    //         0045404f     MOV        this,dword ptr [ECX + this->radius_z]
    //         00454052     CALL       RGE_Visible_Map::get_visible                     uchar get_visible(RGE_Visible_Map * this, int
    //         00454057     TEST       AL,AL
    //         00454059     JZ         LAB_00454060
    //                               LAB_0045405b                                                 XREF[1]:     00454047(j)  
    //                              m_s_obj.cpp:929 (5)
    //         0045405b     MOV        byte ptr [ESP + param_8],0x1
    //                               LAB_00454060                                                 XREF[2]:     00454039(j), 00454059(j)  
    //                              m_s_obj.cpp:931 (8)
    //         00454060     MOV        AL,byte ptr [ESP + param_6]
    //         00454064     TEST       AL,AL
    //         00454066     JZ         LAB_004540b6
    //                              m_s_obj.cpp:933 (10)
    //         00454068     MOV        EDX,dword ptr [ESP + x2]
    //         0045406c     MOV        EAX,dword ptr [EDX + 0x8d8c]
    //                              m_s_obj.cpp:935 (24)
    //         00454072     MOV        EDX,dword ptr [ESP + map]
    //         00454076     MOV        this,dword ptr [EAX + ESI*0x1]
    //         00454079     MOVZX      AX,byte ptr [ECX + EDI*0x1 + this->master_type]
    //         0045407f     XOR        this,this
    //         00454081     MOV        this,byte ptr [EDX + 0x64]
    //         00454084     DEC        this
    //         00454085     JZ         LAB_00454095
    //         00454087     DEC        this
    //         00454088     JNZ        LAB_004540b6
    //                              m_s_obj.cpp:942 (9)
    //         0045408a     TEST       AX,AX
    //         0045408d     JNZ        LAB_004543a9
    //                              m_s_obj.cpp:944 (2)
    //         00454093     JMP        LAB_004540b6
    //                               LAB_00454095                                                 XREF[1]:     00454085(j)  
    //                              m_s_obj.cpp:938 (33)
    //         00454095     TEST       AX,AX
    //         00454098     JZ         LAB_004540b6
    //         0045409a     CMP        AX,0x5
    //         0045409e     JZ         LAB_004540b6
    //         004540a0     CMP        AX,0x7
    //         004540a4     JZ         LAB_004540b6
    //         004540a6     CMP        AX,0x6
    //         004540aa     JZ         LAB_004540b6
    //         004540ac     CMP        AX,0x8
    //         004540b0     JNZ        LAB_004543a9
    //                               LAB_004540b6                                                 XREF[7]:     00454066(j), 00454088(j), 
    //                                                                                                         00454093(j), 00454098(j), 
    //                                                                                                         0045409e(j), 004540a4(j), 
    //                                                                                                         004540aa(j)  
    //                              m_s_obj.cpp:917 (16)
    //         004540b6     INC        EBP
    //         004540b7     CMP        BP,word ptr [ESP + ty1]
    //         004540bc     JLE        LAB_00453ffd
    //         004540c2     MOV        EAX,dword ptr [ESP + local_18]
    //                               LAB_004540c6                                                 XREF[1]:     00453fec(j)  
    //                              m_s_obj.cpp:916 (20)
    //         004540c6     MOV        this,dword ptr [ESP + rx]
    //         004540ca     INC        this
    //         004540cb     CMP        this,word ptr [ESP + edge_y2]
    //         004540d0     MOV        dword ptr [ESP + rx],this
    //         004540d4     JLE        LAB_00453fe5
    //                               LAB_004540da                                                 XREF[1]:     00453fdb(j)  
    //                              m_s_obj.cpp:950 (15)
    //         004540da     CMP        byte ptr [ESP + param_5],0x1
    //         004540df     JNZ        LAB_004540f5
    //         004540e1     MOV        AL,byte ptr [ESP + param_8]
    //         004540e5     TEST       AL,AL
    //         004540e7     JNZ        LAB_004540f5
    //                              m_s_obj.cpp:951 (2)
    //         004540e9     MOV        AL,0x5
    //                              m_s_obj.cpp:1011 (10)
    //         004540eb     POP        EDI
    //         004540ec     POP        ESI
    //         004540ed     POP        EBP
    //         004540ee     POP        EBX
    //         004540ef     ADD        ESP,0x44
    //         004540f2     RET        0x28
    //                               LAB_004540f5                                                 XREF[2]:     004540df(j), 004540e7(j)  
    //                              m_s_obj.cpp:954 (34)
    //         004540f5     FLD        float ptr [ESP + ry]
    //         004540f9     FCOMP      float ptr [DAT_00570618]
    //         004540ff     FNSTSW     AX
    //         00454101     TEST       AH,0x41
    //         00454104     JZ         LAB_00454123
    //         00454106     FLD        float ptr [ESP + tx2]
    //         0045410a     FCOMP      float ptr [DAT_00570618]
    //         00454110     FNSTSW     AX
    //         00454112     TEST       AH,0x41
    //         00454115     JZ         LAB_00454123
    //                              m_s_obj.cpp:955 (2)
    //         00454117     XOR        AL,AL
    //                              m_s_obj.cpp:1011 (10)
    //         00454119     POP        EDI
    //         0045411a     POP        ESI
    //         0045411b     POP        EBP
    //         0045411c     POP        EBX
    //         0045411d     ADD        ESP,0x44
    //         00454120     RET        0x28
    //                               LAB_00454123                                                 XREF[2]:     00454104(j), 00454115(j)  
    //                              m_s_obj.cpp:957 (15)
    //         00454123     FLD        float ptr [ESP + param_2]
    //         00454127     FSUB       float ptr [DAT_00570628]
    //         0045412d     CALL       __ftol                                           undefined __ftol()
    //                              m_s_obj.cpp:958 (21)
    //         00454132     FLD        float ptr [ESP + param_3]
    //         00454136     FSUB       float ptr [DAT_00570628]
    //         0045413c     MOV        EDI,EAX
    //         0045413e     MOV        dword ptr [ESP + rx],EDI
    //         00454142     CALL       __ftol                                           undefined __ftol()
    //                              m_s_obj.cpp:959 (17)
    //         00454147     FLD        float ptr [ESP + param_2]
    //         0045414b     FSUB       float ptr [DAT_0057062c]
    //         00454151     MOV        ESI,EAX
    //         00454153     CALL       __ftol                                           undefined __ftol()
    //                              m_s_obj.cpp:960 (21)
    //         00454158     FLD        float ptr [ESP + param_3]
    //         0045415c     FSUB       float ptr [DAT_0057062c]
    //         00454162     MOV        EBX,EAX
    //         00454164     MOV        dword ptr [ESP + edge_y2],EBX
    //         00454168     CALL       __ftol                                           undefined __ftol()
    //                              m_s_obj.cpp:962 (17)
    //         0045416d     TEST       DI,DI
    //         00454170     MOV        dword ptr [ESP + ty1],EAX
    //         00454174     JGE        LAB_0045417e
    //         00454176     MOV        dword ptr [ESP + rx],0x0
    //                               LAB_0045417e                                                 XREF[1]:     00454174(j)  
    //                              m_s_obj.cpp:963 (22)
    //         0045417e     MOV        this,dword ptr [ESP + x2]
    //         00454182     MOVSX      EDX,BX
    //         00454185     CMP        EDX,dword ptr [ECX + this->name]
    //         00454188     JL         LAB_00454194
    //         0045418a     MOV        DX,word ptr [ECX + this->name]
    //         0045418e     DEC        DX
    //         00454190     MOV        dword ptr [ESP + edge_y2],EDX
    //                               LAB_00454194                                                 XREF[1]:     00454188(j)  
    //                              m_s_obj.cpp:964 (7)
    //         00454194     TEST       SI,SI
    //         00454197     JGE        LAB_0045419b
    //         00454199     XOR        ESI,ESI
    //                               LAB_0045419b                                                 XREF[1]:     00454197(j)  
    //                              m_s_obj.cpp:965 (20)
    //         0045419b     MOV        EDX,dword ptr [ECX + this->string_id]
    //         0045419e     MOVSX      EAX,AX
    //         004541a1     CMP        EAX,EDX
    //         004541a3     JL         LAB_004541af
    //         004541a5     MOV        AX,word ptr [ECX + this->string_id]
    //         004541a9     DEC        AX
    //         004541ab     MOV        dword ptr [ESP + ty1],EAX
    //                               LAB_004541af                                                 XREF[1]:     004541a3(j)  
    //                              m_s_obj.cpp:967 (44)
    //         004541af     MOV        AL,byte ptr [ESP + param_10]
    //         004541b3     TEST       AL,AL
    //         004541b5     JZ         LAB_0045436c
    //         004541bb     MOV        AL,byte ptr [ESP + param_9]
    //         004541bf     MOV        EBX,dword ptr [ESP + map]
    //         004541c3     TEST       AL,AL
    //         004541c5     JNZ        LAB_004541db
    //         004541c7     FLD        float ptr [EBX + 0x38]
    //         004541ca     FCOMP      double ptr [DAT_00570620]
    //         004541d0     FNSTSW     AX
    //         004541d2     TEST       AH,0x41
    //         004541d5     JNZ        LAB_0045436c
    //                               LAB_004541db                                                 XREF[1]:     004541c5(j)  
    //                              m_s_obj.cpp:968 (17)
    //         004541db     CMP        SI,word ptr [ESP + ty1]
    //         004541e0     MOV        EDX,ESI
    //         004541e2     MOV        dword ptr [ESP + param_10],EDX
    //         004541e6     JG         LAB_0045436c
    //                              m_s_obj.cpp:970 (45)
    //         004541ec     MOV        EDI,dword ptr [ESP + rx]
    //         004541f0     MOV        this,dword ptr [this->_padding_ + 0x8d8c]
    //         004541f6     MOVSX      EAX,DI
    //         004541f9     MOV        dword ptr [ESP + param_1],this
    //         004541fd     LEA        this,[EAX + EAX*0x2]
    //         00454200     SHL        this,0x3
    //         00454203     MOV        dword ptr [ESP + local_4],this
    //         00454207     JMP        LAB_0045420d
    //                               LAB_00454209                                                 XREF[1]:     00454366(j)  
    //         00454209     MOV        EDI,dword ptr [ESP + rx]
    //                               LAB_0045420d                                                 XREF[1]:     00454207(j)  
    //         0045420d     MOV        ESI,dword ptr [ESP + param_1]
    //         00454211     MOVSX      EAX,DX
    //         00454214     MOV        EAX,dword ptr [ESI + EAX*0x4]
    //         00454217     ADD        EAX,this
    //                              m_s_obj.cpp:971 (11)
    //         00454219     CMP        DI,word ptr [ESP + edge_y2]
    //         0045421e     JG         LAB_0045435c
    //                              m_s_obj.cpp:970 (3)
    //         00454224     LEA        EBP,[EAX + 0x10]
    //                               LAB_00454227                                                 XREF[1]:     0045434e(j)  
    //                              m_s_obj.cpp:972 (11)
    //         00454227     MOV        EDX,dword ptr [EBP]
    //         0045422a     TEST       EDX,EDX
    //         0045422c     JZ         LAB_00454345
    //                               LAB_00454232                                                 XREF[1]:     0045433f(j)  
    //                              m_s_obj.cpp:974 (2)
    //         00454232     MOV        this,dword ptr [EDX]
    //                              m_s_obj.cpp:975 (10)
    //         00454234     CMP        byte ptr [ECX + this->death_spawn_obj_id],0x7
    //         00454238     JNC        LAB_0045433a
    //                              m_s_obj.cpp:977 (28)
    //         0045423e     MOV        AL,byte ptr [ESP + param_9]
    //         00454242     TEST       AL,AL
    //         00454244     JZ         LAB_0045425a
    //         00454246     MOV        EAX,dword ptr [ECX + this->name]
    //         00454249     CMP        byte ptr [EAX + 0x4b],0x1
    //         0045424d     JNZ        LAB_0045425a
    //         0045424f     MOV        AL,byte ptr [EBX + 0x4b]
    //         00454252     TEST       AL,AL
    //         00454254     JZ         LAB_0045433a
    //                               LAB_0045425a                                                 XREF[2]:     00454244(j), 0045424d(j)  
    //                              m_s_obj.cpp:981 (3)
    //         0045425a     MOV        EAX,dword ptr [ECX + this->name]
    //                              m_s_obj.cpp:982 (7)
    //         0045425d     MOV        ESI,dword ptr [EAX + 0x30]
    //         00454260     MOV        dword ptr [ESP + param_8],ESI
    //                              m_s_obj.cpp:984 (122)
    //         00454264     MOV        ESI,dword ptr [EAX + 0x34]
    //         00454267     FLD        float ptr [ESP + param_8]
    //         0045426b     FCOMP      double ptr [DAT_00570620]
    //         00454271     MOV        EAX,dword ptr [EAX + 0x38]
    //         00454274     MOV        dword ptr [ESP + param_6],ESI
    //         00454278     MOV        dword ptr [ESP + param_5],EAX
    //         0045427c     FNSTSW     AX
    //         0045427e     TEST       AH,0x41
    //         00454281     JNZ        LAB_0045433a
    //         00454287     FLD        float ptr [ESP + param_6]
    //         0045428b     FCOMP      double ptr [DAT_00570620]
    //         00454291     FNSTSW     AX
    //         00454293     TEST       AH,0x41
    //         00454296     JNZ        LAB_0045433a
    //         0045429c     FLD        float ptr [ESP + param_5]
    //         004542a0     FCOMP      double ptr [DAT_00570620]
    //         004542a6     FNSTSW     AX
    //         004542a8     TEST       AH,0x41
    //         004542ab     JNZ        LAB_004542bd
    //         004542ad     FLD        float ptr [EBX + 0x38]
    //         004542b0     FCOMP      double ptr [DAT_00570620]
    //         004542b6     FNSTSW     AX
    //         004542b8     TEST       AH,0x41
    //         004542bb     JZ         LAB_004542de
    //                               LAB_004542bd                                                 XREF[1]:     004542ab(j)  
    //         004542bd     FLD        float ptr [ESP + param_5]
    //         004542c1     FCOMP      double ptr [DAT_00570620]
    //         004542c7     FNSTSW     AX
    //         004542c9     TEST       AH,0x41
    //         004542cc     JZ         LAB_0045433a
    //         004542ce     FLD        float ptr [EBX + 0x38]
    //         004542d1     FCOMP      double ptr [DAT_00570620]
    //         004542d7     FNSTSW     AX
    //         004542d9     TEST       AH,0x41
    //         004542dc     JZ         LAB_0045433a
    //                               LAB_004542de                                                 XREF[1]:     004542bb(j)  
    //                              m_s_obj.cpp:987 (14)
    //         004542de     FLD        float ptr [ECX + this->selected_sound]
    //         004542e1     FSUB       float ptr [ESP + param_3]
    //         004542e5     FLD        float ptr [ECX + this->radius_z]
    //         004542e8     FSUB       float ptr [ESP + param_2]
    //                              m_s_obj.cpp:988 (21)
    //         004542ec     FLD        ST1
    //         004542ee     FCOMP      float ptr [DAT_00570618]
    //         004542f4     FNSTSW     AX
    //         004542f6     TEST       AH,0x1
    //         004542f9     JZ         LAB_00454301
    //         004542fb     FXCH
    //         004542fd     FCHS
    //         004542ff     FXCH
    //                               LAB_00454301                                                 XREF[1]:     004542f9(j)  
    //                              m_s_obj.cpp:989 (15)
    //         00454301     FCOM       float ptr [DAT_00570618]
    //         00454307     FNSTSW     AX
    //         00454309     TEST       AH,0x1
    //         0045430c     JZ         LAB_00454310
    //         0045430e     FCHS
    //                               LAB_00454310                                                 XREF[1]:     0045430c(j)  
    //                              m_s_obj.cpp:990 (42)
    //         00454310     FLD        float ptr [ESP + param_8]
    //         00454314     FADD       float ptr [ESP + ry]
    //         00454318     FXCH
    //         0045431a     FCOMPP
    //         0045431c     FNSTSW     AX
    //         0045431e     TEST       AH,0x1
    //         00454321     JZ         LAB_00454338
    //         00454323     FLD        float ptr [ESP + param_6]
    //         00454327     FADD       float ptr [ESP + tx2]
    //         0045432b     FXCH
    //         0045432d     FCOMPP
    //         0045432f     FNSTSW     AX
    //         00454331     TEST       AH,0x1
    //         00454334     JNZ        LAB_00454378
    //         00454336     JMP        LAB_0045433a
    //                               LAB_00454338                                                 XREF[1]:     00454321(j)  
    //         00454338     FSTP       ST0
    //                               LAB_0045433a                                                 XREF[7]:     00454238(j), 00454254(j), 
    //                                                                                                         00454281(j), 00454296(j), 
    //                                                                                                         004542cc(j), 004542dc(j), 
    //                                                                                                         00454336(j)  
    //                              m_s_obj.cpp:972 (11)
    //         0045433a     MOV        EDX,dword ptr [EDX + 0x4]
    //         0045433d     TEST       EDX,EDX
    //         0045433f     JNZ        LAB_00454232
    //                               LAB_00454345                                                 XREF[1]:     0045422c(j)  
    //                              m_s_obj.cpp:971 (39)
    //         00454345     ADD        EBP,0x18
    //         00454348     INC        EDI
    //         00454349     CMP        DI,word ptr [ESP + edge_y2]
    //         0045434e     JLE        LAB_00454227
    //         00454354     MOV        EDX,dword ptr [ESP + param_10]
    //         00454358     MOV        this,dword ptr [ESP + local_4]
    //                               LAB_0045435c                                                 XREF[1]:     0045421e(j)  
    //         0045435c     INC        EDX
    //         0045435d     CMP        DX,word ptr [ESP + ty1]
    //         00454362     MOV        dword ptr [ESP + param_10],EDX
    //         00454366     JLE        LAB_00454209
    //                               LAB_0045436c                                                 XREF[3]:     004541b5(j), 004541d5(j), 
    //                                                                                                         004541e6(j)  
    //                              m_s_obj.cpp:1010 (2)
    //         0045436c     XOR        AL,AL
    //                              m_s_obj.cpp:1011 (10)
    //         0045436e     POP        EDI
    //         0045436f     POP        ESI
    //         00454370     POP        EBP
    //         00454371     POP        EBX
    //         00454372     ADD        ESP,0x44
    //         00454375     RET        0x28
    //                               LAB_00454378                                                 XREF[1]:     00454334(j)  
    //                              m_s_obj.cpp:1002 (8)
    //         00454378     MOV        EAX,dword ptr [ESP + param_4]
    //         0045437c     TEST       EAX,EAX
    //         0045437e     JZ         LAB_00454385
    //                              m_s_obj.cpp:1003 (5)
    //         00454380     MOV        this,dword ptr [ECX + this->master_type]
    //         00454383     MOV        dword ptr [EAX],this
    //                               LAB_00454385                                                 XREF[1]:     0045437e(j)  
    //                              m_s_obj.cpp:1004 (2)
    //         00454385     MOV        AL,0x6
    //                              m_s_obj.cpp:1011 (10)
    //         00454387     POP        EDI
    //         00454388     POP        ESI
    //         00454389     POP        EBP
    //         0045438a     POP        EBX
    //         0045438b     ADD        ESP,0x44
    //         0045438e     RET        0x28
    //                               LAB_00454391                                                 XREF[4]:     00453ce2(j), 00453cfc(j), 
    //                                                                                                         00453d11(j), 00453d2b(j)  
    //                              m_s_obj.cpp:834 (2)
    //         00454391     MOV        AL,0x7
    //                              m_s_obj.cpp:1011 (10)
    //         00454393     POP        EDI
    //         00454394     POP        ESI
    //         00454395     POP        EBP
    //         00454396     POP        EBX
    //         00454397     ADD        ESP,0x44
    //         0045439a     RET        0x28
    //                               LAB_0045439d                                                 XREF[1]:     0045402d(j)  
    //                              m_s_obj.cpp:920 (2)
    //         0045439d     MOV        AL,0x2
    //                              m_s_obj.cpp:1011 (22)
    //         0045439f     POP        EDI
    //         004543a0     POP        ESI
    //         004543a1     POP        EBP
    //         004543a2     POP        EBX
    //         004543a3     ADD        ESP,0x44
    //         004543a6     RET        0x28
    //                               LAB_004543a9                                                 XREF[2]:     0045408d(j), 004540b0(j)  
    //         004543a9     POP        EDI
    //         004543aa     POP        ESI
    //         004543ab     POP        EBP
    //         004543ac     MOV        AL,0x3
    //         004543ae     POP        EBX
    //         004543af     ADD        ESP,0x44
    //         004543b2     RET        0x28
}

// Offset: 0x004543C0
void make_available(RGE_Master_Static_Object* this_, uchar param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall RGE_Master_Static_Object::make_available(unsigned char)                       *
    //                              *********************************************************************************************************
    //                              void __thiscall make_available(RGE_Master_Static_Object * this, ucha
    //              void              <VOID>         <RETURN>
    //              RGE_Master_Sta    ECX:4 (auto)   this
    //              uchar             Stack[0x4]:1   param_1                   XREF[1]:     004543c0(R)  
    //                               ?make_available@RGE_Master_Static_Object@@QAEXE@Z            XREF[2]:     make_available:00470114(c), 
    //                               RGE_Master_Static_Object::make_available                                  scenario_load:005126ee(c)  
    //                              m_s_obj.cpp:1015 (7)
    //         004543c0     MOV        AL,byte ptr [ESP + param_1]
    //         004543c4     MOV        byte ptr [ECX + this->available],AL
    //                              m_s_obj.cpp:1017 (3)
    //         004543c7     RET        0x4
}

// Offset: 0x004543D0
uchar RGE_Master_Combat_Object::alignment(float* param_1, float* param_2, RGE_Game_World* param_3, uchar param_4) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual unsigned char __thiscall RGE_Master_Static_Object::alignment(float &,float &,class... *
    //                              *********************************************************************************************************
    //                              uchar __thiscall alignment(RGE_Master_Static_Object * this, float * 
    //              uchar             AL:1           <RETURN>
    //              RGE_Master_Sta    ECX:4 (auto)   this
    //              float *           Stack[0x4]:4   param_1                   XREF[13]:    004543d8(R), 004543f3(W), 0045443d(R), 00454455(W), 
    //                                                                                     004544ab(R), 004544c7(R), 004544e6(W), 004544ec(R), 
    //                                                                                     004544f2(R), 0045456c(W), 004545b5(R), 004545e1(R), 
    //                                                                                     004545f6(R)  
    //              float *           Stack[0x8]:4   param_2                   XREF[7]:     004543e0(R), 00454422(W), 00454469(R), 00454586(W), 
    //                                                                                     0045460c(R), 0045461d(R), 00454632(R)  
    //              RGE_Game_World    Stack[0xc]:4   param_3                   XREF[8]:     004543d3(R), 00454428(W), 00454441(R), 00454465(R), 
    //                                                                                     004545a6(W), 004545b1(R), 004545e5(R), 004545fe(R)  
    //              uchar             Stack[0x10]:1  param_4                   XREF[13]:    004544fc(R), 00454562(W), 00454566(R), 0045457c(W), 
    //                                                                                     00454580(R), 00454596(W), 0045459a(R), 004545bc(W), 
    //                                                                                     004545c0(R), 004545d9(W), 00454608(R), 00454621(R), 
    //                                                                                     00454648(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[4]:     00454434(W), 004544cd(R), 004544d8(R), 004544e0(R)  
    //              float             Stack[-0x8]:4  map_h                     XREF[4]:     0045442e(W), 0045449a(R), 004544a5(R), 004544b1(R)  
    //              float             Stack[-0xc]:4  map_w
    //                               ?alignment@RGE_Master_Static_Object@@UAEEAAM0PAVRGE_Game_Wo  XREF[10]:    alignment:0050e961(c), 
    //                               RGE_Master_Static_Object::alignment                                       0057046c(*), 005704ac(*), 
    //                                                                                                         005704e4(*), 00570544(*), 
    //                                                                                                         00570584(*), 005705c4(*), 
    //                                                                                                         005705fc(*), 00576764(*), 
    //                                                                                                         005767b4(*)  
    //                              m_s_obj.cpp:1021 (3)
    //         004543d0     SUB        ESP,0x8
    //                              m_s_obj.cpp:1028 (13)
    //         004543d3     MOV        EAX,dword ptr [ESP + param_3]
    //         004543d7     PUSH       ESI
    //         004543d8     MOV        ESI,dword ptr [ESP + param_1]
    //         004543dc     PUSH       EDI
    //         004543dd     MOV        EAX,dword ptr [EAX + 0x28]
    //                              m_s_obj.cpp:1029 (17)
    //         004543e0     MOV        EDI,dword ptr [ESP + param_2]
    //         004543e4     FLD        float ptr [ESI]
    //         004543e6     FSUB       float ptr [ECX + this->radius_x]
    //         004543e9     FILD       dword ptr [EAX + 0x8]
    //         004543ec     FILD       dword ptr [EAX + 0xc]
    //         004543ef     FLD        float ptr [EDI]
    //                              m_s_obj.cpp:1087 (116)
    //         004543f1     FXCH       ST3
    //         004543f3     FST        float ptr [ESP + param_1]
    //         004543f7     FCOMP      float ptr [DAT_00570618]
    //         004543fd     FLD        float ptr [ESI]
    //         004543ff     FLD        float ptr [EDI]
    //         00454401     FXCH       ST4
    //         00454403     FSUB       float ptr [ECX + this->radius_y]
    //         00454406     FXCH
    //         00454408     FADD       float ptr [ECX + this->radius_x]
    //         0045440b     FXCH       ST4
    //         0045440d     FADD       float ptr [ECX + this->radius_y]
    //         00454410     FXCH       ST3
    //         00454412     FSUB       float ptr [DAT_00570630]                         = ACh
    //         00454418     FXCH       ST2
    //         0045441a     FSUB       float ptr [DAT_00570630]                         = ACh
    //         00454420     FXCH
    //         00454422     FSTP       float ptr [ESP + param_2]
    //         00454426     FXCH       ST3
    //         00454428     FSTP       float ptr [ESP + param_3]
    //         0045442c     FNSTSW     AX
    //         0045442e     FSTP       float ptr [ESP + map_h]
    //         00454432     FXCH
    //         00454434     FSTP       float ptr [ESP + local_4]
    //         00454438     TEST       AH,0x1
    //         0045443b     JZ         LAB_00454465
    //         0045443d     FLD        float ptr [ESP + param_1]
    //         00454441     FLD        float ptr [ESP + param_3]
    //         00454445     FLD        float ptr [ESI]
    //         00454447     FXCH       ST2
    //         00454449     FCHS
    //         0045444b     FXCH
    //         0045444d     FADD       ST0,ST1
    //         0045444f     FXCH       ST2
    //         00454451     FADD       ST0,ST1
    //         00454453     FXCH       ST2
    //         00454455     MOV        dword ptr [ESP + param_1],0x0
    //         0045445d     FSTP       ST1
    //         0045445f     FXCH
    //         00454461     FSTP       float ptr [ESI]
    //         00454463     JMP        LAB_00454469
    //                               LAB_00454465                                                 XREF[1]:     0045443b(j)  
    //                              m_s_obj.cpp:1036 (4)
    //         00454465     FLD        float ptr [ESP + param_3]
    //                               LAB_00454469                                                 XREF[1]:     00454463(j)  
    //                              m_s_obj.cpp:1039 (17)
    //         00454469     FLD        float ptr [ESP + param_2]
    //         0045446d     FCOM       float ptr [DAT_00570618]
    //         00454473     FNSTSW     AX
    //         00454475     TEST       AH,0x1
    //         00454478     JZ         LAB_00454498
    //                              m_s_obj.cpp:1042 (14)
    //         0045447a     FLD        float ptr [EDI]
    //         0045447c     FXCH
    //         0045447e     FCHS
    //         00454480     FXCH       ST3
    //         00454482     FADD       ST0,ST3
    //         00454484     FXCH
    //         00454486     FADD       ST0,ST3
    //                              m_s_obj.cpp:1043 (14)
    //         00454488     FLD        float ptr [DAT_00570618]
    //         0045448e     FXCH       ST2
    //         00454490     FXCH       ST4
    //         00454492     FXCH
    //         00454494     FSTP       float ptr [EDI]
    //                              m_s_obj.cpp:1050 (31)
    //         00454496     FSTP       ST0
    //                               LAB_00454498                                                 XREF[1]:     00454478(j)  
    //         00454498     FLD        ST1
    //         0045449a     FCOMP      float ptr [ESP + map_h]
    //         0045449e     FNSTSW     AX
    //         004544a0     TEST       AH,0x1
    //         004544a3     JNZ        LAB_004544c7
    //         004544a5     FLD        float ptr [ESP + map_h]
    //         004544a9     FSUB       ST0,ST2
    //         004544ab     FLD        float ptr [ESP + param_1]
    //         004544af     FLD        float ptr [ESI]
    //         004544b1     FLD        float ptr [ESP + map_h]
    //                              m_s_obj.cpp:1087 (18)
    //         004544b5     FXCH       ST2
    //         004544b7     FADD       ST0,ST3
    //         004544b9     FXCH
    //         004544bb     FADD       ST0,ST3
    //         004544bd     FXCH       ST2
    //         004544bf     FSTP       ST5
    //         004544c1     FSTP       ST2
    //         004544c3     FSTP       float ptr [ESI]
    //         004544c5     JMP        LAB_004544cb
    //                               LAB_004544c7                                                 XREF[1]:     004544a3(j)  
    //                              m_s_obj.cpp:1050 (4)
    //         004544c7     FLD        float ptr [ESP + param_1]
    //                               LAB_004544cb                                                 XREF[1]:     004544c5(j)  
    //                              m_s_obj.cpp:1053 (13)
    //         004544cb     FLD        ST3
    //         004544cd     FCOMP      float ptr [ESP + local_4]
    //         004544d1     FNSTSW     AX
    //         004544d3     TEST       AH,0x1
    //         004544d6     JNZ        LAB_004544fc
    //                              m_s_obj.cpp:1055 (6)
    //         004544d8     FLD        float ptr [ESP + local_4]
    //         004544dc     FSUB       ST0,ST4
    //                              m_s_obj.cpp:1056 (2)
    //         004544de     FLD        float ptr [EDI]
    //                              m_s_obj.cpp:1057 (28)
    //         004544e0     FLD        float ptr [ESP + local_4]
    //         004544e4     FXCH       ST2
    //         004544e6     FSTP       float ptr [ESP + param_1]
    //         004544ea     FXCH       ST3
    //         004544ec     FADD       float ptr [ESP + param_1]
    //         004544f0     FXCH       ST3
    //         004544f2     FADD       float ptr [ESP + param_1]
    //         004544f6     FXCH
    //         004544f8     FSTP       ST5
    //         004544fa     FSTP       float ptr [EDI]
    //                               LAB_004544fc                                                 XREF[1]:     004544d6(j)  
    //                              m_s_obj.cpp:1060 (12)
    //         004544fc     MOV        AL,byte ptr [ESP + param_4]
    //         00454500     TEST       AL,AL
    //         00454502     JZ         LAB_00454670
    //                              m_s_obj.cpp:1063 (15)
    //         00454508     FCOM       float ptr [DAT_00570618]
    //         0045450e     FNSTSW     AX
    //         00454510     TEST       AH,0x1
    //         00454513     JZ         LAB_00454517
    //         00454515     FCHS
    //                               LAB_00454517                                                 XREF[1]:     00454513(j)  
    //                              m_s_obj.cpp:1064 (21)
    //         00454517     FLD        ST1
    //         00454519     FCOMP      float ptr [DAT_00570618]
    //         0045451f     FNSTSW     AX
    //         00454521     TEST       AH,0x1
    //         00454524     JZ         LAB_0045452c
    //         00454526     FXCH
    //         00454528     FCHS
    //         0045452a     FXCH
    //                               LAB_0045452c                                                 XREF[1]:     00454524(j)  
    //                              m_s_obj.cpp:1065 (21)
    //         0045452c     FLD        ST2
    //         0045452e     FCOMP      float ptr [DAT_00570618]
    //         00454534     FNSTSW     AX
    //         00454536     TEST       AH,0x1
    //         00454539     JZ         LAB_00454541
    //         0045453b     FXCH       ST2
    //         0045453d     FCHS
    //         0045453f     FXCH       ST2
    //                               LAB_00454541                                                 XREF[1]:     00454539(j)  
    //                              m_s_obj.cpp:1066 (21)
    //         00454541     FLD        ST3
    //         00454543     FCOMP      float ptr [DAT_00570618]
    //         00454549     FNSTSW     AX
    //         0045454b     TEST       AH,0x1
    //         0045454e     JZ         LAB_00454556
    //         00454550     FXCH       ST3
    //         00454552     FCHS
    //         00454554     FXCH       ST3
    //                               LAB_00454556                                                 XREF[1]:     0045454e(j)  
    //                              m_s_obj.cpp:1068 (10)
    //         00454556     FLD        ST0
    //         00454558     CALL       __ftol                                           undefined __ftol()
    //         0045455d     MOVSX      this,AX
    //                              m_s_obj.cpp:1069 (26)
    //         00454560     FLD        ST1
    //         00454562     MOV        dword ptr [ESP + param_4],this
    //         00454566     FILD       dword ptr [ESP + param_4]
    //         0045456a     FSUBR      ST0,ST2
    //         0045456c     FSTP       float ptr [ESP + param_1]
    //         00454570     CALL       __ftol                                           undefined __ftol()
    //         00454575     MOVSX      EDX,AX
    //         00454578     FSTP       ST0
    //                              m_s_obj.cpp:1070 (26)
    //         0045457a     FLD        ST1
    //         0045457c     MOV        dword ptr [ESP + param_4],EDX
    //         00454580     FILD       dword ptr [ESP + param_4]
    //         00454584     FSUBR      ST0,ST2
    //         00454586     FSTP       float ptr [ESP + param_2]
    //         0045458a     CALL       __ftol                                           undefined __ftol()
    //         0045458f     MOVSX      EAX,AX
    //         00454592     FSTP       ST0
    //                              m_s_obj.cpp:1071 (29)
    //         00454594     FLD        ST1
    //         00454596     MOV        dword ptr [ESP + param_4],EAX
    //         0045459a     FILD       dword ptr [ESP + param_4]
    //         0045459e     FSUBR      ST0,ST2
    //         004545a0     FSUBR      float ptr [DAT_00570634]
    //         004545a6     FSTP       float ptr [ESP + param_3]
    //         004545aa     CALL       __ftol                                           undefined __ftol()
    //         004545af     FSTP       ST0
    //                              m_s_obj.cpp:1073 (48)
    //         004545b1     FLD        float ptr [ESP + param_3]
    //         004545b5     FADD       float ptr [ESP + param_1]
    //         004545b9     MOVSX      this,AX
    //         004545bc     MOV        dword ptr [ESP + param_4],this
    //         004545c0     FILD       dword ptr [ESP + param_4]
    //         004545c4     FXCH
    //         004545c6     FCOMP      float ptr [DAT_00570634]
    //         004545cc     FSUBR      ST0,ST1
    //         004545ce     FNSTSW     AX
    //         004545d0     FSUBR      float ptr [DAT_00570634]
    //         004545d6     TEST       AH,0x1
    //         004545d9     FSTP       float ptr [ESP + param_4]
    //         004545dd     FSTP       ST0
    //         004545df     JNZ        LAB_00454606
    //                              m_s_obj.cpp:1074 (35)
    //         004545e1     FLD        float ptr [ESP + param_1]
    //         004545e5     FCOMP      float ptr [ESP + param_3]
    //         004545e9     FLD        float ptr [DAT_00570634]
    //         004545ef     FNSTSW     AX
    //         004545f1     TEST       AH,0x41
    //         004545f4     JNZ        LAB_004545fe
    //         004545f6     FSUB       float ptr [ESP + param_1]
    //         004545fa     FADD       float ptr [ESI]
    //         004545fc     JMP        LAB_00454608
    //                               LAB_004545fe                                                 XREF[1]:     004545f4(j)  
    //         004545fe     FSUB       float ptr [ESP + param_3]
    //         00454602     FSUBR      float ptr [ESI]
    //                              m_s_obj.cpp:1075 (2)
    //         00454604     JMP        LAB_00454608
    //                               LAB_00454606                                                 XREF[1]:     004545df(j)  
    //                              m_s_obj.cpp:1076 (2)
    //         00454606     FLD        float ptr [ESI]
    //                               LAB_00454608                                                 XREF[2]:     004545fc(j), 00454604(j)  
    //                              m_s_obj.cpp:1078 (21)
    //         00454608     FLD        float ptr [ESP + param_4]
    //         0045460c     FADD       float ptr [ESP + param_2]
    //         00454610     FCOMP      float ptr [DAT_00570634]
    //         00454616     FNSTSW     AX
    //         00454618     TEST       AH,0x1
    //         0045461b     JNZ        LAB_0045465e
    //                              m_s_obj.cpp:1079 (25)
    //         0045461d     FLD        float ptr [ESP + param_2]
    //         00454621     FCOMP      float ptr [ESP + param_4]
    //         00454625     FLD        float ptr [DAT_00570634]
    //         0045462b     FNSTSW     AX
    //         0045462d     TEST       AH,0x41
    //         00454630     JNZ        LAB_00454648
    //         00454632     FSUB       float ptr [ESP + param_2]
    //                              m_s_obj.cpp:1087 (10)
    //         00454636     MOV        AL,0x1
    //         00454638     FADD       float ptr [EDI]
    //         0045463a     FXCH
    //         0045463c     FSTP       float ptr [ESI]
    //         0045463e     FSTP       float ptr [EDI]
    //                              m_s_obj.cpp:1088 (8)
    //         00454640     POP        EDI
    //         00454641     POP        ESI
    //         00454642     ADD        ESP,0x8
    //         00454645     RET        0x10
    //                               LAB_00454648                                                 XREF[1]:     00454630(j)  
    //                              m_s_obj.cpp:1079 (4)
    //         00454648     FSUB       float ptr [ESP + param_4]
    //                              m_s_obj.cpp:1087 (10)
    //         0045464c     MOV        AL,0x1
    //         0045464e     FSUBR      float ptr [EDI]
    //         00454650     FXCH
    //         00454652     FSTP       float ptr [ESI]
    //         00454654     FSTP       float ptr [EDI]
    //                              m_s_obj.cpp:1088 (8)
    //         00454656     POP        EDI
    //         00454657     POP        ESI
    //         00454658     ADD        ESP,0x8
    //         0045465b     RET        0x10
    //                               LAB_0045465e                                                 XREF[1]:     0045461b(j)  
    //                              m_s_obj.cpp:1081 (2)
    //         0045465e     FLD        float ptr [EDI]
    //                              m_s_obj.cpp:1083 (4)
    //         00454660     FXCH
    //         00454662     FSTP       float ptr [ESI]
    //                              m_s_obj.cpp:1087 (4)
    //         00454664     MOV        AL,0x1
    //         00454666     FSTP       float ptr [EDI]
    //                              m_s_obj.cpp:1088 (8)
    //         00454668     POP        EDI
    //         00454669     POP        ESI
    //         0045466a     ADD        ESP,0x8
    //         0045466d     RET        0x10
    //                               LAB_00454670                                                 XREF[1]:     00454502(j)  
    //                              m_s_obj.cpp:1057 (6)
    //         00454670     FSTP       ST0
    //         00454672     FSTP       ST0
    //         00454674     FSTP       ST0
    //                              m_s_obj.cpp:1088 (12)
    //         00454676     POP        EDI
    //         00454677     MOV        AL,0x1
    //         00454679     FSTP       ST0
    //         0045467b     POP        ESI
    //         0045467c     ADD        ESP,0x8
    //         0045467f     RET        0x10
}

// Offset: 0x00454690
uchar alignment_box(RGE_Master_Static_Object* this_, RGE_Game_World* param_2, float param_3, float param_4, short* param_5, short* param_6, short* param_7, short* param_8, short* param_9, short* param_10, short* param_11, short* param_12) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: unsigned char __thiscall RGE_Master_Static_Object::alignment_box(class RGE_Game_World *,fl... *
    //                              *********************************************************************************************************
    //                              uchar __thiscall alignment_box(RGE_Master_Static_Object * this, RGE_
    //              uchar             AL:1           <RETURN>
    //              RGE_Master_Sta    ECX:4 (auto)   this
    //              RGE_Game_World    Stack[0x4]:4   param_1                   XREF[1]:     004546bf(R)  
    //              float             Stack[0x8]:4   param_2                   XREF[10]:    00454693(R), 004546af(R), 004546c9(W), 004546cd(R), 
    //                                                                                     004546e6(W), 004546ed(R), 004546f3(W), 00454702(R), 
    //                                                                                     0045473f(R), 00454774(R)  
    //              float             Stack[0xc]:4   param_3                   XREF[4]:     004546a0(R), 004546e2(R), 00454713(W), 0045471b(R)  
    //              short *           Stack[0x10]:4  param_4                   XREF[1]:     00454717(R)  
    //              short *           Stack[0x14]:4  param_5                   XREF[1]:     00454733(R)  
    //              short *           Stack[0x18]:4  param_6                   XREF[1]:     00454754(R)  
    //              short *           Stack[0x1c]:4  param_7                   XREF[1]:     00454768(R)  
    //              short *           Stack[0x20]:4  param_8                   XREF[1]:     00454783(R)  
    //              short *           Stack[0x24]:4  param_9                   XREF[1]:     0045479d(R)  
    //              short *           Stack[0x28]:4  param_10                  XREF[1]:     004547b6(R)  
    //              short *           Stack[0x2c]:4  param_11                  XREF[1]:     004547c8(R)  
    //              undefined8        Stack[-0x8]:8  local_8                   XREF[3]:     00454721(W), 00454725(R), 0045475a(R)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[6]:     004546a7(W), 004546ab(R), 004546b6(W), 004546f7(R), 
    //                                                                                     0045470c(R), 00454745(R)  
    //              float             Stack[-0x10]:4 tx
    //                               ?alignment_box@RGE_Master_Static_Object@@QAEEPAVRGE_Game_Wo  XREF[2]:     draw_wall_outline:0052d0e9(c), 
    //                               RGE_Master_Static_Object::alignment_box                                   draw_object_outline:0053573c(c)  
    //                              m_s_obj.cpp:1092 (3)
    //         00454690     SUB        ESP,0xc
    //                              m_s_obj.cpp:1099 (13)
    //         00454693     FLD        float ptr [ESP + param_2]
    //         00454697     PUSH       ESI
    //         00454698     MOV        ESI,this
    //         0045469a     PUSH       EDI
    //         0045469b     CALL       __ftol                                           undefined __ftol()
    //                              m_s_obj.cpp:1100 (31)
    //         004546a0     FLD        float ptr [ESP + param_3]
    //         004546a4     MOVSX      EAX,AX
    //         004546a7     MOV        dword ptr [ESP + local_c],EAX
    //         004546ab     FILD       dword ptr [ESP + local_c]
    //         004546af     FSUBR      float ptr [ESP + param_2]
    //         004546b3     FADD       float ptr [ESI + 0x30]
    //         004546b6     FSTP       float ptr [ESP + local_c]
    //         004546ba     CALL       __ftol                                           undefined __ftol()
    //                              m_s_obj.cpp:1103 (25)
    //         004546bf     MOV        EDX,dword ptr [ESP + param_1]
    //         004546c3     MOVSX      this,AX
    //         004546c6     MOV        EAX,dword ptr [EDX + 0x28]
    //         004546c9     MOV        dword ptr [ESP + param_2],this
    //         004546cd     FILD       dword ptr [ESP + param_2]
    //         004546d1     MOV        this,word ptr [EAX + 0x8d9c]
    //                              m_s_obj.cpp:1104 (7)
    //         004546d8     MOV        DI,word ptr [EAX + 0x8d9a]
    //                              m_s_obj.cpp:1106 (35)
    //         004546df     MOVSX      EAX,this
    //         004546e2     FSUBR      float ptr [ESP + param_3]
    //         004546e6     MOV        dword ptr [ESP + param_2],EAX
    //         004546ea     FADD       float ptr [ESI + 0x34]
    //         004546ed     FILD       dword ptr [ESP + param_2]
    //         004546f1     FXCH
    //         004546f3     FST        float ptr [ESP + param_2]
    //         004546f7     FADD       float ptr [ESP + local_c]
    //         004546fb     FMUL       ST1
    //         004546fd     CALL       __ftol                                           undefined __ftol()
    //                              m_s_obj.cpp:1107 (56)
    //         00454702     FLD        float ptr [ESP + param_2]
    //         00454706     FSUB       double ptr [DAT_00570638]
    //         0045470c     FLD        float ptr [ESP + local_c]
    //         00454710     MOVSX      this,DI
    //         00454713     MOV        dword ptr [ESP + param_3],this
    //         00454717     MOV        EDX,dword ptr [ESP + param_4]
    //         0045471b     FILD       dword ptr [ESP + param_3]
    //         0045471f     FXCH       ST2
    //         00454721     FSTP       double ptr [ESP + local_8]
    //         00454725     FSUBR      double ptr [ESP + local_8]
    //         00454729     MOV        word ptr [EDX],AX
    //         0045472c     FMUL       ST1
    //         0045472e     CALL       __ftol                                           undefined __ftol()
    //         00454733     MOV        this,dword ptr [ESP + param_5]
    //         00454737     MOV        word ptr [this->_padding_],AX
    //                              m_s_obj.cpp:1109 (5)
    //         0045473a     FLD        float ptr [ESI + 0x30]
    //         0045473d     FADD       ST0,ST0
    //                              m_s_obj.cpp:1110 (21)
    //         0045473f     FLD        float ptr [ESP + param_2]
    //         00454743     FXCH
    //         00454745     FSUBR      float ptr [ESP + local_c]
    //         00454749     FXCH
    //         0045474b     FADD       ST0,ST1
    //         0045474d     FMUL       ST3
    //         0045474f     CALL       __ftol                                           undefined __ftol()
    //                              m_s_obj.cpp:1111 (27)
    //         00454754     MOV        EDX,dword ptr [ESP + param_6]
    //         00454758     FLD        ST0
    //         0045475a     FSUBR      double ptr [ESP + local_8]
    //         0045475e     MOV        word ptr [EDX],AX
    //         00454761     FMUL       ST2
    //         00454763     CALL       __ftol                                           undefined __ftol()
    //         00454768     MOV        this,dword ptr [ESP + param_7]
    //         0045476c     MOV        word ptr [this->_padding_],AX
    //                              m_s_obj.cpp:1113 (9)
    //         0045476f     FLD        float ptr [ESI + 0x34]
    //         00454772     FADD       ST0,ST0
    //         00454774     FSUBR      float ptr [ESP + param_2]
    //                              m_s_obj.cpp:1114 (11)
    //         00454778     FLD        ST0
    //         0045477a     FADD       ST0,ST2
    //         0045477c     FMUL       ST4
    //         0045477e     CALL       __ftol                                           undefined __ftol()
    //                              m_s_obj.cpp:1115 (33)
    //         00454783     MOV        EDX,dword ptr [ESP + param_8]
    //         00454787     FLD        ST0
    //         00454789     FSUB       double ptr [DAT_00570638]
    //         0045478f     FLD        ST2
    //         00454791     MOV        word ptr [EDX],AX
    //         00454794     FSUBR      ST0,ST1
    //         00454796     FMUL       ST4
    //         00454798     CALL       __ftol                                           undefined __ftol()
    //         0045479d     MOV        this,dword ptr [ESP + param_9]
    //         004547a1     MOV        word ptr [this->_padding_],AX
    //                              m_s_obj.cpp:1117 (5)
    //         004547a4     FLD        float ptr [ESI + 0x30]
    //         004547a7     FADD       ST0,ST0
    //                              m_s_obj.cpp:1118 (13)
    //         004547a9     FADD       ST0,ST3
    //         004547ab     FXCH       ST2
    //         004547ad     FADD       ST0,ST2
    //         004547af     FMUL       ST5
    //         004547b1     CALL       __ftol                                           undefined __ftol()
    //                              m_s_obj.cpp:1119 (22)
    //         004547b6     MOV        EDX,dword ptr [ESP + param_10]
    //         004547ba     FXCH
    //         004547bc     FSUBR      ST0,ST1
    //         004547be     MOV        word ptr [EDX],AX
    //         004547c1     FMUL       ST3
    //         004547c3     CALL       __ftol                                           undefined __ftol()
    //         004547c8     MOV        this,dword ptr [ESP + param_11]
    //                              m_s_obj.cpp:1122 (21)
    //         004547cc     POP        EDI
    //         004547cd     FSTP       ST0
    //         004547cf     FSTP       ST0
    //         004547d1     FSTP       ST0
    //         004547d3     MOV        word ptr [this->_padding_],AX
    //         004547d6     MOV        AL,0x1
    //         004547d8     FSTP       ST0
    //         004547da     POP        ESI
    //         004547db     ADD        ESP,0xc
    //         004547de     RET        0x2c
}

// Offset: 0x004547F0
void RGE_Master_Combat_Object::draw(TDrawArea* param_1, short param_2, short param_3, RGE_Color_Table* param_4, long param_5, long param_6, int param_7, uchar param_8) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void __thiscall RGE_Master_Static_Object::draw(class TDrawArea *,short,short,class... *
    //                              *********************************************************************************************************
    //                              void __thiscall draw(RGE_Master_Static_Object * this, TDrawArea * pa
    //              void              <VOID>         <RETURN>
    //              RGE_Master_Sta    ECX:4 (auto)   this
    //              TDrawArea *       Stack[0x4]:4   param_1                   XREF[3]:     00454809(R), 004548c0(*), 0045490e(R)  
    //              short             Stack[0x8]:2   param_2                   XREF[3]:     0045480d(R), 004548e4(*), 00454906(R)  
    //              short             Stack[0xc]:2   param_3                   XREF[3]:     00454805(R), 004548df(*), 004548fb(R)  
    //              RGE_Color_Tabl    Stack[0x10]:4  param_4                   XREF[3]:     00454817(R), 004548c5(*), 00454915(R)  
    //              long              Stack[0x14]:4  param_5                   XREF[3]:     0045481f(R), 0045489c(*), 00454921(R)  
    //              long              Stack[0x18]:4  param_6                   XREF[3]:     00454827(R), 00454897(*), 0045491a(R)  
    //              int               Stack[0x1c]:4  param_7                   XREF[3]:     00454832(R), 00454873(*), 00454926(R)  
    //              uchar             Stack[0x20]:1  param_8                   XREF[1]:     004548f1(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[5]:     004547f3(W), 0045484c(R), 0045486b(W), 0045486f(R), 
    //                                                                                     004548d2(R)  
    //              undefined4        Stack[-0x8]:4  local_8                   XREF[4]:     00454861(W), 00454865(R), 0045488a(R), 004548ad(R)  
    //              float             Stack[-0xc]:4  ry1                       XREF[6]:     00454881(W), 0045488e(R), 004548a9(R), 004548b4(W), 
    //                                                                                     004548b8(R), 004548d6(R)  
    //              float             Stack[-0x10]:4 rx1                       XREF[0,2]:   00454879(*), 0045492d(R)  
    //              short             Stack[-0x12]:2 x1
    //                               ?draw@RGE_Master_Static_Object@@UAEXPAVTDrawArea@@FFPAVRGE_  XREF[9]:     0057047c(*), 005704bc(*), 
    //                               RGE_Master_Static_Object::draw                                            005704f4(*), 00570554(*), 
    //                                                                                                         00570594(*), 005705d4(*), 
    //                                                                                                         0057060c(*), 00576774(*), 
    //                                                                                                         005767c4(*)  
    //                              m_s_obj.cpp:1126 (7)
    //         004547f0     SUB        ESP,0x10
    //         004547f3     MOV        dword ptr [ESP + local_4],this
    //                              m_s_obj.cpp:1127 (14)
    //         004547f7     MOV        this,dword ptr [ECX + this->sprite]
    //         004547fa     PUSH       EBX
    //         004547fb     PUSH       EBP
    //         004547fc     TEST       this,this
    //         004547fe     PUSH       EDI
    //         004547ff     JZ         LAB_00454943
    //                              m_s_obj.cpp:1131 (45)
    //         00454805     MOV        EDI,dword ptr [ESP + param_3]
    //         00454809     MOV        EDX,dword ptr [ESP + param_1]
    //         0045480d     MOV        EBX,dword ptr [ESP + param_2]
    //         00454811     PUSH       0xa
    //         00454813     MOVSX      EBP,DI
    //         00454816     PUSH       EDX
    //         00454817     MOV        EDX,dword ptr [ESP + param_4]
    //         0045481b     MOVSX      EAX,BX
    //         0045481e     PUSH       EDX
    //         0045481f     MOV        EDX,dword ptr [ESP + param_5]
    //         00454823     PUSH       EBP
    //         00454824     PUSH       EAX
    //         00454825     PUSH       EBP
    //         00454826     PUSH       EAX
    //         00454827     MOV        EAX,dword ptr [ESP + param_6]
    //         0045482b     PUSH       EAX
    //         0045482c     PUSH       EDX
    //         0045482d     CALL       RGE_Sprite::draw                                 uchar draw(RGE_Sprite * this, long param_1, l
    //                              m_s_obj.cpp:1134 (12)
    //         00454832     MOV        EAX,dword ptr [ESP + param_7]
    //         00454836     TEST       EAX,EAX
    //         00454838     JZ         LAB_00454943
    //                              m_s_obj.cpp:1136 (6)
    //         0045483e     MOV        EAX,[rge_base_game]                              = 00000000
    //         00454843     PUSH       ESI
    //                              m_s_obj.cpp:1141 (70)
    //         00454844     PUSH       EDI
    //         00454845     PUSH       EBX
    //         00454846     MOV        this,dword ptr [EAX + 0x3f4]
    //         0045484c     MOV        EAX,dword ptr [ESP + local_4]
    //         00454850     PUSH       0x0
    //         00454852     MOV        EDX,dword ptr [EAX + 0xac]
    //         00454858     MOV        EAX,dword ptr [EAX + 0xb0]
    //         0045485e     MOV        ESI,dword ptr [ECX + this->los]
    //         00454861     MOV        dword ptr [ESP + local_8],EAX
    //         00454865     FLD        float ptr [ESP + local_8]
    //         00454869     FCHS
    //         0045486b     FSTP       float ptr [ESP + local_4]
    //         0045486f     MOV        this,dword ptr [ESP + local_4]
    //         00454873     LEA        EAX=>param_7,[ESP + 0x48]
    //         00454877     PUSH       this
    //         00454878     PUSH       EDX
    //         00454879     LEA        this=>rx1+0x2,[ESP + 0x26]
    //         0045487d     PUSH       EAX
    //         0045487e     PUSH       this
    //         0045487f     MOV        this,ESI
    //         00454881     MOV        dword ptr [ESP + ry1],EDX
    //         00454885     CALL       RGE_Map::get_point                               void get_point(RGE_Map * this, short * param_
    //                              m_s_obj.cpp:1142 (31)
    //         0045488a     MOV        EDX,dword ptr [ESP + local_8]
    //         0045488e     MOV        EAX,dword ptr [ESP + ry1]
    //         00454892     PUSH       EDI
    //         00454893     PUSH       EBX
    //         00454894     PUSH       0x0
    //         00454896     PUSH       EDX
    //         00454897     LEA        this=>param_6,[ESP + 0x48]
    //         0045489b     PUSH       EAX
    //         0045489c     LEA        EDX=>param_5,[ESP + 0x48]
    //         004548a0     PUSH       this
    //         004548a1     PUSH       EDX
    //         004548a2     MOV        this,ESI
    //         004548a4     CALL       RGE_Map::get_point                               void get_point(RGE_Map * this, short * param_
    //                              m_s_obj.cpp:1143 (41)
    //         004548a9     FLD        float ptr [ESP + ry1]
    //         004548ad     MOV        EAX,dword ptr [ESP + local_8]
    //         004548b1     PUSH       EDI
    //         004548b2     FCHS
    //         004548b4     FSTP       float ptr [ESP + ry1]
    //         004548b8     MOV        this,dword ptr [ESP + ry1]
    //         004548bc     PUSH       EBX
    //         004548bd     PUSH       0x0
    //         004548bf     PUSH       EAX
    //         004548c0     LEA        EDX=>param_1,[ESP + 0x34]
    //         004548c4     PUSH       this
    //         004548c5     LEA        EAX=>param_4,[ESP + 0x44]
    //         004548c9     PUSH       EDX
    //         004548ca     PUSH       EAX
    //         004548cb     MOV        this,ESI
    //         004548cd     CALL       RGE_Map::get_point                               void get_point(RGE_Map * this, short * param_
    //                              m_s_obj.cpp:1144 (31)
    //         004548d2     MOV        this,dword ptr [ESP + local_4]
    //         004548d6     MOV        EDX,dword ptr [ESP + ry1]
    //         004548da     PUSH       EDI
    //         004548db     PUSH       EBX
    //         004548dc     PUSH       0x0
    //         004548de     PUSH       this
    //         004548df     LEA        EAX=>param_3,[ESP + 0x3c]
    //         004548e3     PUSH       EDX
    //         004548e4     LEA        this=>param_2,[ESP + 0x3c]
    //         004548e8     PUSH       EAX
    //         004548e9     PUSH       this
    //         004548ea     MOV        this,ESI
    //         004548ec     CALL       RGE_Map::get_point                               void get_point(RGE_Map * this, short * param_
    //                              m_s_obj.cpp:1145 (82)
    //         004548f1     MOV        EAX,dword ptr [ESP + param_8]
    //         004548f5     MOV        EDX,dword ptr [SDI_Object_ID]
    //         004548fb     MOVSX      this,word ptr [ESP + param_3]
    //         00454900     AND        EAX,0xff
    //         00454905     PUSH       EDX
    //         00454906     MOVSX      EDX,word ptr [ESP + param_2]
    //         0045490b     PUSH       EAX
    //         0045490c     PUSH       0xa
    //         0045490e     MOVSX      EAX,word ptr [ESP + param_1]
    //         00454913     PUSH       this
    //         00454914     PUSH       EDX
    //         00454915     MOVSX      this,word ptr [ESP + param_4]
    //         0045491a     MOVSX      EDX,word ptr [ESP + param_6]
    //         0045491f     PUSH       EAX
    //         00454920     PUSH       this
    //         00454921     MOVSX      EAX,word ptr [ESP + param_5]
    //         00454926     MOVSX      this,word ptr [ESP + param_7]
    //         0045492b     PUSH       EDX
    //         0045492c     PUSH       EAX
    //         0045492d     MOVSX      EDX,word ptr [ESP + rx1+0x2]
    //         00454932     PUSH       this
    //         00454933     MOV        this,dword ptr [SDI_List]                        = 00000000
    //         00454939     PUSH       EDX
    //         0045493a     PUSH       EBP
    //         0045493b     PUSH       0x1
    //         0045493d     CALL       DClipInfo_List::AddGDINode                       DClipInfo_Node * AddGDINode(DClipInfo_List * 
    //         00454942     POP        ESI
    //                               LAB_00454943                                                 XREF[2]:     004547ff(j), 00454838(j)  
    //                              m_s_obj.cpp:1147 (9)
    //         00454943     POP        EDI
    //         00454944     POP        EBP
    //         00454945     POP        EBX
    //         00454946     ADD        ESP,0x10
    //         00454949     RET        0x20
}

// Offset: 0x00454950
long get_help_message(RGE_Master_Static_Object* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: long __thiscall RGE_Master_Static_Object::get_help_message(void)                              *
    //                              *********************************************************************************************************
    //                              long __thiscall get_help_message(RGE_Master_Static_Object * this)
    //              long              EAX:4          <RETURN>
    //              RGE_Master_Sta    ECX:4 (auto)   this
    //                               ?get_help_message@RGE_Master_Static_Object@@QAEJXZ           XREF[3]:     interface_item_avail:005133aa(c), 
    //                               RGE_Master_Static_Object::get_help_message                                interface_item_avail:005134bb(c), 
    //                                                                                                         get_help_info:0054060f(c)  
    //                              m_s_obj.cpp:1153 (6)
    //         00454950     MOV        EAX,dword ptr [ECX + this->help_string_id]
    //                              m_s_obj.cpp:1155 (1)
    //         00454956     RET
}

// Offset: 0x00454960
long get_help_page(RGE_Master_Static_Object* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: long __thiscall RGE_Master_Static_Object::get_help_page(void)                                 *
    //                              *********************************************************************************************************
    //                              long __thiscall get_help_page(RGE_Master_Static_Object * this)
    //              long              EAX:4          <RETURN>
    //              RGE_Master_Sta    ECX:4 (auto)   this
    //                               ?get_help_page@RGE_Master_Static_Object@@QAEJXZ              XREF[3]:     interface_item_avail:005133bb(c), 
    //                               RGE_Master_Static_Object::get_help_page                                   interface_item_avail:005134cf(c), 
    //                                                                                                         get_help_info:00540646(c)  
    //                              m_s_obj.cpp:1161 (6)
    //         00454960     MOV        EAX,dword ptr [ECX + this->help_page_id]
    //                              m_s_obj.cpp:1163 (1)
    //         00454966     RET
}

// Offset: 0x00454970
long get_hotkey(RGE_Master_Static_Object* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: long __thiscall RGE_Master_Static_Object::get_hotkey(void)                                    *
    //                              *********************************************************************************************************
    //                              long __thiscall get_hotkey(RGE_Master_Static_Object * this)
    //              long              EAX:4          <RETURN>
    //              RGE_Master_Sta    ECX:4 (auto)   this
    //                               ?get_hotkey@RGE_Master_Static_Object@@QAEJXZ
    //                               RGE_Master_Static_Object::get_hotkey
    //                              m_s_obj.cpp:1169 (6)
    //         00454970     MOV        EAX,dword ptr [ECX + this->hotkey_id]
    //                              m_s_obj.cpp:1171 (1)
    //         00454976     RET
}

// Offset: 0x00454980
long RGE_Master_Action_Object::calc_base_damage_ability(RGE_Master_Combat_Object* param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual long __thiscall RGE_Master_Static_Object::calc_base_damage_ability(class RGE_Maste... *
    //                              *********************************************************************************************************
    //                              long __thiscall calc_base_damage_ability(RGE_Master_Static_Object * 
    //              long              EAX:4          <RETURN>
    //              RGE_Master_Sta    ECX:4 (auto)   this
    //              RGE_Master_Com    Stack[0x4]:4   param_1                   XREF[3]:     00454980(R), 004549a1(W), 004549a5(R)  
    //                               ?calc_base_damage_ability@RGE_Master_Static_Object@@UAEJPAV  XREF[6]:     00570470(*), 005704b0(*), 
    //                               RGE_Master_Static_Object::calc_base_damage_ability                        00570548(*), 005705c8(*), 
    //                                                                                                         00570600(*), 005767b8(*)  
    //                              m_s_obj.cpp:1177 (4)
    //         00454980     MOV        EAX,dword ptr [ESP + param_1]
    //                              m_s_obj.cpp:1181 (19)
    //         00454984     FLD        float ptr [DAT_00570618]
    //         0045498a     MOVSX      EDX,word ptr [EAX + 0x108]
    //         00454991     MOV        EAX,dword ptr [EAX + 0x10c]
    //                              m_s_obj.cpp:1184 (4)
    //         00454997     TEST       EDX,EDX
    //         00454999     JLE        LAB_004549c2
    //                              m_s_obj.cpp:1178 (3)
    //         0045499b     LEA        this,[EAX + 0x2]
    //                               LAB_0045499e                                                 XREF[1]:     004549c0(j)  
    //                              m_s_obj.cpp:1188 (11)
    //         0045499e     MOVSX      EAX,word ptr [this->_padding_]
    //         004549a1     MOV        dword ptr [ESP + param_1],EAX
    //         004549a5     FILD       dword ptr [ESP + param_1]
    //                              m_s_obj.cpp:1189 (13)
    //         004549a9     FCOM       double ptr [DAT_00570620]
    //         004549af     FNSTSW     AX
    //         004549b1     TEST       AH,0x41
    //         004549b4     JNZ        LAB_004549ba
    //                              m_s_obj.cpp:1190 (2)
    //         004549b6     FADDP
    //                              m_s_obj.cpp:1189 (4)
    //         004549b8     JMP        LAB_004549bc
    //                               LAB_004549ba                                                 XREF[1]:     004549b4(j)  
    //         004549ba     FSTP       ST0
    //                               LAB_004549bc                                                 XREF[1]:     004549b8(j)  
    //                              m_s_obj.cpp:1190 (6)
    //         004549bc     ADD        this,0x4
    //         004549bf     DEC        EDX
    //         004549c0     JNZ        LAB_0045499e
    //                               LAB_004549c2                                                 XREF[1]:     00454999(j)  
    //                              m_s_obj.cpp:1193 (15)
    //         004549c2     FCOM       double ptr [DAT_00570648]
    //         004549c8     FNSTSW     AX
    //         004549ca     TEST       AH,0x1
    //         004549cd     JZ         LAB_004549d7
    //         004549cf     FSTP       ST0
    //                              m_s_obj.cpp:1194 (6)
    //         004549d1     FLD        float ptr [DAT_00570634]
    //                               LAB_004549d7                                                 XREF[1]:     004549cd(j)  
    //                              m_s_obj.cpp:1196 (5)
    //         004549d7     CALL       __ftol                                           undefined __ftol()
    //                              m_s_obj.cpp:1197 (3)
    //         004549dc     RET        0x4
}

