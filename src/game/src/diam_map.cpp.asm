// Auto-generated scaffold unit: diam_map.cpp.asm
// SourceMap: C:/msdev/work/age1_x1/diam_map.cpp
#include "../include/common.h"

// Offset: 0x00436830
undefined RGE_Diamond_Map(RGE_Diamond_Map* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall RGE_Diamond_Map::RGE_Diamond_Map(void)                                             *
    //                              *********************************************************************************************************
    //                              undefined __thiscall RGE_Diamond_Map(RGE_Diamond_Map * this)
    //              undefined         <UNASSIGNED>   <RETURN>
    //              RGE_Diamond_Ma    ECX:4 (auto)   this
    //                               ??0RGE_Diamond_Map@@QAE@XZ                                   XREF[1]:     RGE_Diamond_Map_View:0053d363(c)  
    //                               RGE_Diamond_Map::RGE_Diamond_Map
    //                              diam_map.cpp:40 (8)
    //         00436830     PUSH       ESI
    //         00436831     MOV        ESI,this
    //         00436833     CALL       TPanel::TPanel                                   undefined TPanel(TPanel * this)
    //                              diam_map.cpp:41 (2)
    //         00436838     XOR        EAX,EAX
    //                              diam_map.cpp:64 (117)
    //         0043683a     OR         this,0xffffffff
    //         0043683d     MOV        dword ptr [ESI + 0xf4],EAX
    //         00436843     MOV        dword ptr [ESI + 0xf8],EAX
    //         00436849     MOV        dword ptr [ESI + 0xfc],EAX
    //         0043684f     MOV        dword ptr [ESI + 0x110],EAX
    //         00436855     MOV        dword ptr [ESI + 0x124],EAX
    //         0043685b     MOV        word ptr [ESI + 0x134],AX
    //         00436862     MOV        dword ptr [ESI + 0x128],EAX
    //         00436868     MOV        dword ptr [ESI + 0x12c],EAX
    //         0043686e     MOV        word ptr [ESI + 0x136],AX
    //         00436875     MOV        word ptr [ESI + 0x138],AX
    //         0043687c     MOV        word ptr [ESI + 0x13a],AX
    //         00436883     MOV        dword ptr [ESI + 0x13c],EAX
    //         00436889     MOV        word ptr [ESI + 0x148],AX
    //         00436890     MOV        word ptr [ESI + 0x14a],AX
    //         00436897     MOV        dword ptr [ESI + 0x140],EAX
    //         0043689d     MOV        dword ptr [ESI + 0x144],EAX
    //         004368a3     MOV        dword ptr [ESI + 0x168],EAX
    //         004368a9     MOV        dword ptr [ESI + 0x164],EAX
    //                              diam_map.cpp:66 (6)
    //         004368af     MOV        dword ptr [ESI + 0x114],EAX
    //                              diam_map.cpp:67 (6)
    //         004368b5     MOV        dword ptr [ESI + 0x118],EAX
    //                              diam_map.cpp:68 (6)
    //         004368bb     MOV        dword ptr [ESI + 0x11c],EAX
    //                              diam_map.cpp:69 (6)
    //         004368c1     MOV        dword ptr [ESI + 0x120],EAX
    //                              diam_map.cpp:70 (6)
    //         004368c7     MOV        dword ptr [ESI + 0x150],EAX
    //                              diam_map.cpp:71 (6)
    //         004368cd     MOV        dword ptr [ESI + 0x154],EAX
    //                              diam_map.cpp:74 (6)
    //         004368d3     MOV        dword ptr [ESI + 0x15c],EAX
    //                              diam_map.cpp:75 (43)
    //         004368d9     MOV        dword ptr [ESI + 0x160],EAX
    //         004368df     MOV        dword ptr [ESI],RGE_Diamond_Map::`vftable'       = 00436910
    //         004368e5     MOV        word ptr [ESI + 0x14c],this
    //         004368ec     MOV        word ptr [ESI + 0x14e],this
    //         004368f3     MOV        dword ptr [ESI + 0x104],0x1
    //         004368fd     MOV        byte ptr [ESI + 0x158],0xff
    //                              diam_map.cpp:76 (4)
    //         00436904     MOV        EAX,ESI
    //         00436906     POP        ESI
    //         00436907     RET
}

// Offset: 0x00436930
void RGE_Diamond_Map(RGE_Diamond_Map* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual __thiscall RGE_Diamond_Map::~RGE_Diamond_Map(void)                                    *
    //                              *********************************************************************************************************
    //                              void __thiscall ~RGE_Diamond_Map(RGE_Diamond_Map * this)
    //              void              <VOID>         <RETURN>
    //              RGE_Diamond_Ma    ECX:4 (auto)   this
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     00436953(W), 0043699c(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     004369a9(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     00436949(W)  
    //                               ??1RGE_Diamond_Map@@UAE@XZ                                   XREF[3]:     `vector_deleting_destructor':00436
    //                               RGE_Diamond_Map::~RGE_Diamond_Map                                         ~RGE_Diamond_Map:0052ca1e(T), 
    //                                                                                                         ~TRIBE_Diamond_Map_View:0052ca20(j
    //                                                                                                         ~RGE_Diamond_Map:0053d39e(T), 
    //                                                                                                         ~RGE_Diamond_Map_View:0053d3a0(j)  
    //                              diam_map.cpp:82 (43)
    //         00436930     PUSH       -0x1
    //         00436932     PUSH       FUN_0055cf18
    //         00436937     MOV        EAX,FS:[0x0]
    //         0043693d     PUSH       EAX
    //         0043693e     MOV        dword ptr FS:[0x0],ESP
    //         00436945     PUSH       this
    //         00436946     PUSH       ESI
    //         00436947     MOV        ESI,this
    //         00436949     MOV        dword ptr [ESP + local_10],ESI
    //         0043694d     MOV        dword ptr [ESI],RGE_Diamond_Map::`vftable'       = 00436910
    //         00436953     MOV        dword ptr [ESP + local_4],0x0
    //                              diam_map.cpp:83 (5)
    //         0043695b     CALL       RGE_Diamond_Map::delete_surfaces                 void delete_surfaces(RGE_Diamond_Map * this)
    //                              diam_map.cpp:85 (10)
    //         00436960     MOV        EAX,dword ptr [ESI + 0x12c]
    //         00436966     TEST       EAX,EAX
    //         00436968     JZ         LAB_0043697d
    //                              diam_map.cpp:87 (9)
    //         0043696a     PUSH       EAX
    //         0043696b     CALL       free                                             undefined free()
    //         00436970     ADD        ESP,0x4
    //                              diam_map.cpp:88 (10)
    //         00436973     MOV        dword ptr [ESI + 0x12c],0x0
    //                               LAB_0043697d                                                 XREF[1]:     00436968(j)  
    //                              diam_map.cpp:91 (10)
    //         0043697d     MOV        EAX,dword ptr [ESI + 0x128]
    //         00436983     TEST       EAX,EAX
    //         00436985     JZ         LAB_0043699a
    //                              diam_map.cpp:93 (9)
    //         00436987     PUSH       EAX
    //         00436988     CALL       free                                             undefined free()
    //         0043698d     ADD        ESP,0x4
    //                              diam_map.cpp:94 (12)
    //         00436990     MOV        dword ptr [ESI + 0x128],0x0
    //                               LAB_0043699a                                                 XREF[1]:     00436985(j)  
    //         0043699a     MOV        this,ESI
    //                              diam_map.cpp:96 (29)
    //         0043699c     MOV        dword ptr [ESP + local_4],0xffffffff
    //         004369a4     CALL       TPanel::~TPanel                                  void ~TPanel(TPanel * this)
    //         004369a9     MOV        this,dword ptr [ESP + local_c]
    //         004369ad     POP        ESI
    //         004369ae     MOV        dword ptr FS:[0x0],this
    //         004369b5     ADD        ESP,0x10
    //         004369b8     RET
}

// Offset: 0x004369C0
long setup(RGE_Diamond_Map* this_, TDrawArea* param_2, TPanel* param_3, long param_4, long param_5, long param_6, long param_7, uchar param_8, int param_9, TDrawArea* param_10) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: long __thiscall RGE_Diamond_Map::setup(class TDrawArea *,class TPanel *,long,long,long,lon... *
    //                              *********************************************************************************************************
    //                              long __thiscall setup(RGE_Diamond_Map * this, TDrawArea * param_1, T
    //              long              EAX:4          <RETURN>
    //              RGE_Diamond_Ma    ECX:4 (auto)   this
    //              TDrawArea *       Stack[0x4]:4   param_1                   XREF[1]:     004369e7(R)  
    //              TPanel *          Stack[0x8]:4   param_2                   XREF[1]:     004369e2(R)  
    //              long              Stack[0xc]:4   param_3                   XREF[1]:     004369dd(R)  
    //              long              Stack[0x10]:4  param_4                   XREF[1]:     004369d8(R)  
    //              long              Stack[0x14]:4  param_5                   XREF[1]:     004369d3(R)  
    //              long              Stack[0x18]:4  param_6                   XREF[1]:     004369ce(R)  
    //              uchar             Stack[0x1c]:1  param_7                   XREF[1]:     004369c4(R)  
    //              int               Stack[0x20]:4  param_8
    //              TDrawArea *       Stack[0x24]:4  param_9                   XREF[1]:     004369c0(R)  
    //                               ?setup@RGE_Diamond_Map@@QAEJPAVTDrawArea@@PAVTPanel@@JJJJEH  XREF[2]:     TRIBE_Screen_Game:00494386(c), 
    //                               RGE_Diamond_Map::setup                                                    TRIBE_Screen_Sed:004a848d(c)  
    //                              diam_map.cpp:103 (4)
    //         004369c0     MOV        EAX,dword ptr [ESP + param_9]
    //                              diam_map.cpp:107 (56)
    //         004369c4     MOV        EDX,dword ptr [ESP + param_7]
    //         004369c8     MOV        dword ptr [ECX + this->save_area],EAX
    //         004369ce     MOV        EAX,dword ptr [ESP + param_6]
    //         004369d2     PUSH       EDX
    //         004369d3     MOV        EDX,dword ptr [ESP + param_5]
    //         004369d7     PUSH       EAX
    //         004369d8     MOV        EAX,dword ptr [ESP + param_4]
    //         004369dc     PUSH       EDX
    //         004369dd     MOV        EDX,dword ptr [ESP + param_3]
    //         004369e1     PUSH       EAX
    //         004369e2     MOV        EAX,dword ptr [ESP + param_2]
    //         004369e6     PUSH       EDX
    //         004369e7     MOV        EDX,dword ptr [ESP + param_1]
    //         004369eb     PUSH       EAX
    //         004369ec     PUSH       EDX
    //         004369ed     MOV        dword ptr [ECX + this->own_save_area],0x0
    //         004369f7     CALL       TPanel::setup                                    long setup(TPanel * this, TDrawArea * param_1
    //                              diam_map.cpp:111 (5)
    //         004369fc     MOV        EAX,0x1
    //                              diam_map.cpp:112 (3)
    //         00436a01     RET        0x24
}

// Offset: 0x00436A10
int set_bitmap(RGE_Diamond_Map* this_, char* param_2, long param_3) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall RGE_Diamond_Map::set_bitmap(char *,long)                                       *
    //                              *********************************************************************************************************
    //                              int __thiscall set_bitmap(RGE_Diamond_Map * this, char * param_1, lo
    //              int               EAX:4          <RETURN>
    //              RGE_Diamond_Ma    ECX:4 (auto)   this
    //              char *            Stack[0x4]:4   param_1                   XREF[5]:     00436a7c(R), 00436b3b(W), 00436bc6(R), 00436bd9(R), 
    //                                                                                     00436be3(W)  
    //              long              Stack[0x8]:4   param_2                   XREF[6]:     00436a78(R), 00436a8e(W), 00436a94(W), 00436af0(R), 
    //                                                                                     00436b08(R), 00436bed(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     00436a72(W), 00436a9c(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     00436c18(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[4]:     00436a6c(W), 00436ad7(W), 00436b1f(R), 00436bde(R)  
    //              short             Stack[-0x14]:2 pic_hgt                   XREF[2]:     00436b19(W), 00436bd2(R)  
    //              short             Stack[-0x18]:2 pic_pitch
    //                               ?set_bitmap@RGE_Diamond_Map@@QAEHPADJ@Z                      XREF[2]:     TRIBE_Screen_Game:004943c7(c), 
    //                               RGE_Diamond_Map::set_bitmap                                               TRIBE_Screen_Sed:004a84aa(c)  
    //                              diam_map.cpp:118 (30)
    //         00436a10     MOV        EAX,FS:[0x0]
    //         00436a16     PUSH       -0x1
    //         00436a18     PUSH       FUN_0055cf3b
    //         00436a1d     PUSH       EAX
    //         00436a1e     MOV        dword ptr FS:[0x0],ESP
    //         00436a25     SUB        ESP,0x8
    //         00436a28     PUSH       EBX
    //         00436a29     PUSH       EBP
    //         00436a2a     PUSH       ESI
    //         00436a2b     MOV        ESI,this
    //         00436a2d     PUSH       EDI
    //                              diam_map.cpp:126 (12)
    //         00436a2e     XOR        EDI,EDI
    //         00436a30     MOV        EAX,dword ptr [ESI + 0x128]
    //         00436a36     CMP        EAX,EDI
    //         00436a38     JZ         LAB_00436a49
    //                              diam_map.cpp:128 (9)
    //         00436a3a     PUSH       EAX
    //         00436a3b     CALL       free                                             undefined free()
    //         00436a40     ADD        ESP,0x4
    //                              diam_map.cpp:129 (6)
    //         00436a43     MOV        dword ptr [ESI + 0x128],EDI
    //                               LAB_00436a49                                                 XREF[1]:     00436a38(j)  
    //                              diam_map.cpp:132 (10)
    //         00436a49     MOV        EAX,dword ptr [ESI + 0x12c]
    //         00436a4f     CMP        EAX,EDI
    //         00436a51     JZ         LAB_00436a62
    //                              diam_map.cpp:134 (9)
    //         00436a53     PUSH       EAX
    //         00436a54     CALL       free                                             undefined free()
    //         00436a59     ADD        ESP,0x4
    //                              diam_map.cpp:135 (6)
    //         00436a5c     MOV        dword ptr [ESI + 0x12c],EDI
    //                               LAB_00436a62                                                 XREF[1]:     00436a51(j)  
    //                              diam_map.cpp:139 (56)
    //         00436a62     PUSH       0x20
    //         00436a64     CALL       operator_new                                     void * operator_new(uint param_1)
    //         00436a69     ADD        ESP,0x4
    //         00436a6c     MOV        dword ptr [ESP + local_10],EAX
    //         00436a70     CMP        EAX,EDI
    //         00436a72     MOV        dword ptr [ESP + local_4],EDI
    //         00436a76     JZ         LAB_00436a94
    //         00436a78     MOV        this,dword ptr [ESP + param_2]
    //         00436a7c     MOV        EDX,dword ptr [ESP + param_1]
    //         00436a80     PUSH       EDI
    //         00436a81     PUSH       EDI
    //         00436a82     PUSH       EDI
    //         00436a83     PUSH       this
    //         00436a84     PUSH       EDX
    //         00436a85     MOV        this,EAX
    //         00436a87     CALL       TPicture::TPicture                               undefined TPicture(TPicture * this, char * pa
    //         00436a8c     MOV        EBP,EAX
    //         00436a8e     MOV        dword ptr [ESP + param_2],EBP
    //         00436a92     JMP        LAB_00436a9a
    //                               LAB_00436a94                                                 XREF[1]:     00436a76(j)  
    //         00436a94     MOV        dword ptr [ESP + param_2],EDI
    //         00436a98     MOV        EBP,EDI
    //                               LAB_00436a9a                                                 XREF[1]:     00436a92(j)  
    //                              diam_map.cpp:140 (12)
    //         00436a9a     CMP        EBP,EDI
    //         00436a9c     MOV        dword ptr [ESP + local_4],0xffffffff
    //         00436aa4     JNZ        LAB_00436aad
    //                              diam_map.cpp:141 (7)
    //         00436aa6     XOR        EAX,EAX
    //         00436aa8     JMP        LAB_00436c18
    //                               LAB_00436aad                                                 XREF[1]:     00436aa4(j)  
    //                              diam_map.cpp:142 (5)
    //         00436aad     CMP        dword ptr [EBP],EDI
    //         00436ab0     JNZ        LAB_00436ac9
    //                              diam_map.cpp:144 (16)
    //         00436ab2     MOV        this,EBP
    //         00436ab4     CALL       TPicture::~TPicture                              void ~TPicture(TPicture * this)
    //         00436ab9     PUSH       EBP
    //         00436aba     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         00436abf     ADD        ESP,0x4
    //                              diam_map.cpp:145 (7)
    //         00436ac2     XOR        EAX,EAX
    //         00436ac4     JMP        LAB_00436c18
    //                               LAB_00436ac9                                                 XREF[1]:     00436ab0(j)  
    //                              diam_map.cpp:150 (8)
    //         00436ac9     MOV        AX,word ptr [EBP + 0x18]
    //         00436acd     MOV        BX,word ptr [EBP + 0x14]
    //                              diam_map.cpp:152 (24)
    //         00436ad1     MOVSX      EDI,AX
    //         00436ad4     PUSH       0x6
    //         00436ad6     PUSH       EDI
    //         00436ad7     MOV        dword ptr [ESP + local_10],EAX
    //         00436adb     CALL       calloc                                           undefined calloc()
    //         00436ae0     ADD        ESP,0x8
    //         00436ae3     MOV        dword ptr [ESI + 0x128],EAX
    //                              diam_map.cpp:154 (7)
    //         00436ae9     CMP        word ptr [EBP + 0x1c],0x1
    //         00436aee     JNZ        LAB_00436afe
    //                              diam_map.cpp:157 (12)
    //         00436af0     MOV        this,dword ptr [ESP + param_2]
    //         00436af4     MOV        EBP,dword ptr [EBP + 0x8]
    //         00436af7     CALL       TPicture::AlignedWidth                           long AlignedWidth(TPicture * this)
    //                              diam_map.cpp:159 (2)
    //         00436afc     JMP        LAB_00436b19
    //                               LAB_00436afe                                                 XREF[1]:     00436aee(j)  
    //                              diam_map.cpp:161 (20)
    //         00436afe     MOV        this,EBP
    //         00436b00     CALL       TPicture::AlignedWidth                           long AlignedWidth(TPicture * this)
    //         00436b05     MOV        EBP,EAX
    //         00436b07     DEC        EDI
    //         00436b08     MOV        this,dword ptr [ESP + param_2]
    //         00436b0c     IMUL       EBP,EDI
    //         00436b0f     ADD        EBP,dword ptr [ECX + this->_padding_]
    //                              diam_map.cpp:162 (11)
    //         00436b12     CALL       TPicture::AlignedWidth                           long AlignedWidth(TPicture * this)
    //         00436b17     NEG        EAX
    //                               LAB_00436b19                                                 XREF[1]:     00436afc(j)  
    //         00436b19     MOV        dword ptr [ESP + pic_hgt],EAX
    //                              diam_map.cpp:166 (2)
    //         00436b1d     XOR        EAX,EAX
    //                              diam_map.cpp:169 (38)
    //         00436b1f     CMP        word ptr [ESP + local_10],AX
    //         00436b24     MOV        word ptr [ESI + 0x134],0xffff
    //         00436b2d     MOV        word ptr [ESI + 0x136],AX
    //         00436b34     MOV        word ptr [ESI + 0x138],AX
    //         00436b3b     MOV        dword ptr [ESP + param_1],EAX
    //         00436b3f     JLE        LAB_00436bed
    //                               LAB_00436b45                                                 XREF[1]:     00436be7(j)  
    //                              diam_map.cpp:172 (3)
    //         00436b45     OR         EAX,0xffffffff
    //                              diam_map.cpp:174 (9)
    //         00436b48     XOR        this,this
    //         00436b4a     TEST       BX,BX
    //         00436b4d     MOV        EDX,EBP
    //         00436b4f     JLE        LAB_00436b61
    //                               LAB_00436b51                                                 XREF[1]:     00436b5b(j)  
    //                              diam_map.cpp:176 (5)
    //         00436b51     CMP        byte ptr [EDX],0xff
    //         00436b54     JZ         LAB_00436b5f
    //                              diam_map.cpp:181 (9)
    //         00436b56     INC        EDX
    //         00436b57     INC        this
    //         00436b58     CMP        this,BX
    //         00436b5b     JL         LAB_00436b51
    //         00436b5d     JMP        LAB_00436b61
    //                               LAB_00436b5f                                                 XREF[1]:     00436b54(j)  
    //                              diam_map.cpp:178 (2)
    //         00436b5f     MOV        EAX,this
    //                               LAB_00436b61                                                 XREF[2]:     00436b4f(j), 00436b5d(j)  
    //                              diam_map.cpp:184 (6)
    //         00436b61     CMP        AX,0xffff
    //         00436b65     JZ         LAB_00436bd2
    //                              diam_map.cpp:187 (2)
    //         00436b67     XOR        EDI,EDI
    //                              diam_map.cpp:188 (5)
    //         00436b69     CMP        this,BX
    //         00436b6c     JGE        LAB_00436b7b
    //                               LAB_00436b6e                                                 XREF[1]:     00436b79(j)  
    //                              diam_map.cpp:190 (5)
    //         00436b6e     CMP        byte ptr [EDX],0xff
    //         00436b71     JNZ        LAB_00436b7b
    //                              diam_map.cpp:192 (1)
    //         00436b73     INC        EDI
    //                              diam_map.cpp:193 (7)
    //         00436b74     INC        EDX
    //         00436b75     INC        this
    //         00436b76     CMP        this,BX
    //         00436b79     JL         LAB_00436b6e
    //                               LAB_00436b7b                                                 XREF[2]:     00436b6c(j), 00436b71(j)  
    //                              diam_map.cpp:197 (21)
    //         00436b7b     MOVSX      this,word ptr [ESI + 0x138]
    //         00436b82     MOV        EDX,dword ptr [ESI + 0x128]
    //         00436b88     LEA        this,[ECX + ECX*0x2]
    //         00436b8b     MOV        word ptr [EDX + this->_padding_*0x2 + 0x2],AX
    //                              diam_map.cpp:198 (21)
    //         00436b90     MOVSX      this,word ptr [ESI + 0x138]
    //         00436b97     LEA        EAX,[ECX + ECX*0x2]
    //         00436b9a     MOV        this,dword ptr [ESI + 0x128]
    //         00436ba0     MOV        word ptr [ECX + EAX*0x2 + this->_padding_],DI
    //                              diam_map.cpp:201 (7)
    //         00436ba5     INC        word ptr [ESI + 0x138]
    //                              diam_map.cpp:202 (9)
    //         00436bac     CMP        DI,word ptr [ESI + 0x136]
    //         00436bb3     JLE        LAB_00436bbc
    //                              diam_map.cpp:203 (7)
    //         00436bb5     MOV        word ptr [ESI + 0x136],DI
    //                               LAB_00436bbc                                                 XREF[1]:     00436bb3(j)  
    //                              diam_map.cpp:206 (10)
    //         00436bbc     CMP        word ptr [ESI + 0x134],-0x1
    //         00436bc4     JNZ        LAB_00436bd2
    //                              diam_map.cpp:207 (12)
    //         00436bc6     MOV        DX,word ptr [ESP + param_1]
    //         00436bcb     MOV        word ptr [ESI + 0x134],DX
    //                               LAB_00436bd2                                                 XREF[2]:     00436b65(j), 00436bc4(j)  
    //                              diam_map.cpp:211 (27)
    //         00436bd2     MOVSX      EAX,word ptr [ESP + pic_hgt]
    //         00436bd7     ADD        EBP,EAX
    //         00436bd9     MOV        EAX,dword ptr [ESP + param_1]
    //         00436bdd     INC        EAX
    //         00436bde     CMP        AX,word ptr [ESP + local_10]
    //         00436be3     MOV        dword ptr [ESP + param_1],EAX
    //         00436be7     JL         LAB_00436b45
    //                               LAB_00436bed                                                 XREF[1]:     00436b3f(j)  
    //                              diam_map.cpp:214 (17)
    //         00436bed     MOV        EDI,dword ptr [ESP + param_2]
    //         00436bf1     MOV        this,EDI
    //         00436bf3     CALL       TPicture::~TPicture                              void ~TPicture(TPicture * this)
    //         00436bf8     PUSH       EDI
    //         00436bf9     CALL       operator_delete                                  void operator_delete(void * param_1)
    //                              diam_map.cpp:217 (13)
    //         00436bfe     MOV        EAX,dword ptr [ESI + 0xf4]
    //         00436c04     ADD        ESP,0x4
    //         00436c07     TEST       EAX,EAX
    //         00436c09     JZ         LAB_00436c13
    //                              diam_map.cpp:218 (8)
    //         00436c0b     PUSH       EAX
    //         00436c0c     MOV        this,ESI
    //         00436c0e     CALL       RGE_Diamond_Map::set_world                       void set_world(RGE_Diamond_Map * this, RGE_Ga
    //                               LAB_00436c13                                                 XREF[1]:     00436c09(j)  
    //                              diam_map.cpp:220 (5)
    //         00436c13     MOV        EAX,0x1
    //                               LAB_00436c18                                                 XREF[2]:     00436aa8(j), 00436ac4(j)  
    //                              diam_map.cpp:221 (21)
    //         00436c18     MOV        this,dword ptr [ESP + local_c]
    //         00436c1c     POP        EDI
    //         00436c1d     POP        ESI
    //         00436c1e     POP        EBP
    //         00436c1f     MOV        dword ptr FS:[0x0],this
    //         00436c26     POP        EBX
    //         00436c27     ADD        ESP,0x14
    //         00436c2a     RET        0x8
}

// Offset: 0x00436C30
void set_world(RGE_Diamond_Map* this_, RGE_Game_World* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall RGE_Diamond_Map::set_world(class RGE_Game_World *)                            *
    //                              *********************************************************************************************************
    //                              void __thiscall set_world(RGE_Diamond_Map * this, RGE_Game_World * p
    //              void              <VOID>         <RETURN>
    //              RGE_Diamond_Ma    ECX:4 (auto)   this
    //              RGE_Game_World    Stack[0x4]:4   param_1                   XREF[16]:    00436c30(R), 00436ccc(W), 00436cd3(R), 00436cda(W), 
    //                                                                                     00436ce6(R), 00436d0d(W), 00436d1b(R), 00436dd2(R), 
    //                                                                                     00436ecd(R), 00436ee1(W), 00436f0e(W), 00436f19(R), 
    //                                                                                     00436f3f(W), 00436f61(R), 00436f68(W), 00436f6f(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     00436d97(W), 00436e5a(R)  
    //              float             Stack[-0x8]:4  col_step                  XREF[4]:     00436d87(W), 00436d8f(R), 00436dab(W), 00436db3(R)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[8]:     00436cde(W), 00436cf8(W), 00436d17(R), 00436d83(W), 
    //                                                                                     00436d8b(R), 00436daf(W), 00436dc9(W), 00436ec1(R)  
    //              float             Stack[-0x10]:2 tile_row                  XREF[4]:     00436d09(W), 00436ec5(R), 00436ed6(W), 00436f30(R)  
    //              short             Stack[-0x14]:2 tot_draw_wid
    //                               ?set_world@RGE_Diamond_Map@@QAEXPAVRGE_Game_World@@@Z        XREF[3]:     set_bitmap:00436c0e(c), 
    //                               RGE_Diamond_Map::set_world                                                TRIBE_Screen_Game:004943b2(c), 
    //                                                                                                         set_panel_info:004a87a9(c)  
    //                              diam_map.cpp:227 (13)
    //         00436c30     MOV        EAX,dword ptr [ESP + param_1]
    //         00436c34     SUB        ESP,0x10
    //         00436c37     PUSH       EBX
    //         00436c38     PUSH       EBP
    //         00436c39     PUSH       ESI
    //         00436c3a     PUSH       EDI
    //         00436c3b     MOV        ESI,this
    //                              diam_map.cpp:236 (28)
    //         00436c3d     XOR        EDI,EDI
    //         00436c3f     CMP        EAX,EDI
    //         00436c41     MOV        dword ptr [ESI + 0xf4],EAX
    //         00436c47     JZ         LAB_00437059
    //         00436c4d     CMP        dword ptr [ESI + 0x128],EDI
    //         00436c53     JZ         LAB_00437059
    //                              diam_map.cpp:242 (9)
    //         00436c59     MOV        EAX,dword ptr [EAX + 0x28]
    //         00436c5c     MOV        dword ptr [ESI + 0xfc],EAX
    //                              diam_map.cpp:244 (21)
    //         00436c62     MOV        this,dword ptr [ESI + 0xfc]
    //         00436c68     MOV        AX,word ptr [EAX + 0x8]
    //         00436c6c     MOV        word ptr [ESI + 0x130],AX
    //         00436c73     MOV        AX,word ptr [ECX + this->_padding_]
    //                              diam_map.cpp:247 (17)
    //         00436c77     MOV        DX,word ptr [ESI + 0x130]
    //         00436c7e     MOV        word ptr [ESI + 0x132],AX
    //         00436c85     ADD        DX,AX
    //                              diam_map.cpp:248 (18)
    //         00436c88     MOV        EAX,dword ptr [ESI + 0x12c]
    //         00436c8e     DEC        EDX
    //         00436c8f     CMP        EAX,EDI
    //         00436c91     MOV        word ptr [ESI + 0x13a],DX
    //         00436c98     JZ         LAB_00436ca3
    //                              diam_map.cpp:249 (9)
    //         00436c9a     PUSH       EAX
    //         00436c9b     CALL       free                                             undefined free()
    //         00436ca0     ADD        ESP,0x4
    //                               LAB_00436ca3                                                 XREF[1]:     00436c98(j)  
    //                              diam_map.cpp:250 (15)
    //         00436ca3     MOVSX      EAX,word ptr [ESI + 0x13a]
    //         00436caa     PUSH       0x24
    //         00436cac     PUSH       EAX
    //         00436cad     CALL       calloc                                           undefined calloc()
    //                              diam_map.cpp:253 (30)
    //         00436cb2     MOV        this,word ptr [ESI + 0x13a]
    //         00436cb9     MOV        dword ptr [ESI + 0x12c],EAX
    //         00436cbf     MOV        AX,word ptr [ESI + 0x138]
    //         00436cc6     ADD        ESP,0x8
    //         00436cc9     MOVSX      EDX,this
    //         00436ccc     MOV        dword ptr [ESP + param_1],EDX
    //                              diam_map.cpp:254 (34)
    //         00436cd0     CMP        this,AX
    //         00436cd3     FILD       dword ptr [ESP + param_1]
    //         00436cd7     MOVSX      EDX,AX
    //         00436cda     MOV        dword ptr [ESP + param_1],EDX
    //         00436cde     MOV        dword ptr [ESP + local_c],0x0
    //         00436ce6     FIDIV      dword ptr [ESP + param_1]
    //         00436cea     FST        float ptr [ESI + 0x13c]
    //         00436cf0     JLE        LAB_00436cfe
    //                              diam_map.cpp:255 (12)
    //         00436cf2     FMUL       float ptr [null_0056f600]                        = align(3)
    //         00436cf8     FSTP       float ptr [ESP + local_c]
    //         00436cfc     JMP        LAB_00436d00
    //                               LAB_00436cfe                                                 XREF[1]:     00436cf0(j)  
    //                              diam_map.cpp:253 (2)
    //         00436cfe     FSTP       ST0
    //                               LAB_00436d00                                                 XREF[1]:     00436cfc(j)  
    //                              diam_map.cpp:258 (6)
    //         00436d00     FLD        float ptr [DAT_0056f5fc]                         = align(7)
    //                              diam_map.cpp:260 (21)
    //         00436d06     CMP        AX,DI
    //         00436d09     MOV        dword ptr [ESP + tile_row],EDI
    //         00436d0d     MOV        dword ptr [ESP + param_1],EDI
    //         00436d11     JLE        LAB_00436ef5
    //         00436d17     FLD        float ptr [ESP + local_c]
    //                               LAB_00436d1b                                                 XREF[1]:     00436eeb(j)  
    //                              diam_map.cpp:263 (5)
    //         00436d1b     MOVSX      EAX,word ptr [ESP + param_1]
    //                              diam_map.cpp:265 (26)
    //         00436d20     FLD        ST0
    //         00436d22     MOV        this,dword ptr [ESI + 0x128]
    //         00436d28     LEA        EAX,[EAX + EAX*0x2]
    //         00436d2b     MOV        DI,word ptr [ECX + EAX*0x2 + this->_padding_]
    //         00436d30     LEA        EBX,[this->_padding_ + EAX*0x2]
    //         00436d33     CALL       __ftol                                           undefined __ftol()
    //         00436d38     MOV        EBP,EAX
    //                              diam_map.cpp:266 (12)
    //         00436d3a     MOV        AX,word ptr [ESI + 0x13a]
    //         00436d41     CMP        BP,AX
    //         00436d44     JL         LAB_00436d49
    //                              diam_map.cpp:267 (3)
    //         00436d46     LEA        EBP,[EAX + -0x1]
    //                               LAB_00436d49                                                 XREF[1]:     00436d44(j)  
    //                              diam_map.cpp:269 (3)
    //         00436d49     MOV        word ptr [EBX],BP
    //                              diam_map.cpp:271 (12)
    //         00436d4c     MOV        AX,word ptr [ESI + 0x130]
    //         00436d53     CMP        BP,AX
    //         00436d56     JGE        LAB_00436d69
    //                              diam_map.cpp:273 (12)
    //         00436d58     MOV        BX,word ptr [ESI + 0x132]
    //         00436d5f     CMP        BP,BX
    //         00436d62     JGE        LAB_00436d77
    //                              diam_map.cpp:274 (3)
    //         00436d64     LEA        EBX,[EBP + 0x1]
    //                              diam_map.cpp:275 (2)
    //         00436d67     JMP        LAB_00436d77
    //                               LAB_00436d69                                                 XREF[1]:     00436d56(j)  
    //                              diam_map.cpp:279 (14)
    //         00436d69     MOV        DX,word ptr [ESI + 0x132]
    //         00436d70     SUB        DX,BP
    //         00436d73     LEA        EBX,[EDX + EAX*0x1 + -0x1]
    //                               LAB_00436d77                                                 XREF[2]:     00436d62(j), 00436d67(j)  
    //                              diam_map.cpp:283 (40)
    //         00436d77     FLD        float ptr [DAT_0056f604]
    //         00436d7d     MOVSX      EAX,BX
    //         00436d80     MOVSX      this,DI
    //         00436d83     MOV        dword ptr [ESP + local_c],EAX
    //         00436d87     MOV        dword ptr [ESP + col_step],this
    //         00436d8b     FILD       dword ptr [ESP + local_c]
    //         00436d8f     FILD       dword ptr [ESP + col_step]
    //         00436d93     FLD        ST1
    //         00436d95     FDIV       ST0,ST1
    //         00436d97     FST        float ptr [ESP + local_4]
    //         00436d9b     FXCH       ST3
    //         00436d9d     FDIV       ST0,ST3
    //                              diam_map.cpp:284 (9)
    //         00436d9f     FLD        ST0
    //         00436da1     CALL       __ftol                                           undefined __ftol()
    //         00436da6     MOV        this,EAX
    //                              diam_map.cpp:285 (32)
    //         00436da8     MOVSX      EDX,this
    //         00436dab     MOV        dword ptr [ESP + col_step],EDX
    //         00436daf     MOV        dword ptr [ESP + local_c],this
    //         00436db3     FILD       dword ptr [ESP + col_step]
    //         00436db7     FCOMP
    //         00436db9     FXCH       ST2
    //         00436dbb     FXCH       ST3
    //         00436dbd     FXCH
    //         00436dbf     FXCH       ST2
    //         00436dc1     FNSTSW     AX
    //         00436dc3     TEST       AH,0x40
    //         00436dc6     JNZ        LAB_00436dcd
    //                              diam_map.cpp:286 (5)
    //         00436dc8     INC        this
    //         00436dc9     MOV        dword ptr [ESP + local_c],this
    //                               LAB_00436dcd                                                 XREF[1]:     00436dc6(j)  
    //                              diam_map.cpp:288 (3)
    //         00436dcd     MOVSX      EAX,BP
    //                              diam_map.cpp:291 (55)
    //         00436dd0     FXCH
    //         00436dd2     MOV        DX,word ptr [ESP + param_1]
    //         00436dd7     LEA        EDI,[EAX + EAX*0x8]
    //         00436dda     MOV        EAX,dword ptr [ESI + 0x12c]
    //         00436de0     SHL        EDI,0x2
    //         00436de3     MOV        word ptr [EAX + EDI*0x1],DX
    //         00436de7     MOV        EAX,dword ptr [ESI + 0x12c]
    //         00436ded     MOV        byte ptr [EAX + EDI*0x1 + 0x2],0x1
    //         00436df2     MOV        EDX,dword ptr [ESI + 0x12c]
    //         00436df8     MOV        word ptr [EDX + EDI*0x1 + 0x4],BX
    //         00436dfd     MOV        EAX,dword ptr [ESI + 0x12c]
    //         00436e03     FSTP       float ptr [EAX + EDI*0x1 + 0x8]
    //                              diam_map.cpp:292 (11)
    //         00436e07     MOV        EDX,dword ptr [ESI + 0x12c]
    //         00436e0d     MOV        word ptr [EDX + EDI*0x1 + 0x14],this
    //                              diam_map.cpp:293 (10)
    //         00436e12     MOV        EAX,dword ptr [ESI + 0x12c]
    //         00436e18     FST        float ptr [EAX + EDI*0x1 + 0x18]
    //                              diam_map.cpp:294 (11)
    //         00436e1c     FLD        ST1
    //         00436e1e     FDIV       ST0,ST1
    //         00436e20     CALL       __ftol                                           undefined __ftol()
    //         00436e25     FSTP       ST0
    //                              diam_map.cpp:295 (23)
    //         00436e27     FDIV       ST0,ST1
    //         00436e29     MOV        this,dword ptr [ESI + 0x12c]
    //         00436e2f     MOV        word ptr [ECX + EDI*0x1 + this->_padding_],AX
    //         00436e34     MOV        EDX,dword ptr [ESI + 0x12c]
    //         00436e3a     FSTP       float ptr [EDX + EDI*0x1 + 0x20]
    //                              diam_map.cpp:296 (49)
    //         00436e3e     MOV        EAX,dword ptr [ESI + 0x12c]
    //         00436e44     FSTP       ST0
    //         00436e46     FLD        float ptr [EAX + EDI*0x1 + 0x20]
    //         00436e4a     FCOMP      float ptr [DAT_0056f604]
    //         00436e50     LEA        this,[EAX + EDI*0x1]
    //         00436e53     FNSTSW     AX
    //         00436e55     TEST       AH,0x1
    //         00436e58     JZ         LAB_00436e66
    //         00436e5a     FLD        float ptr [ESP + local_4]
    //         00436e5e     FMUL       float ptr [null_0056f600]                        = align(3)
    //         00436e64     JMP        LAB_00436e6c
    //                               LAB_00436e66                                                 XREF[1]:     00436e58(j)  
    //         00436e66     FLD        float ptr [DAT_0056f5fc]                         = align(7)
    //                               LAB_00436e6c                                                 XREF[1]:     00436e64(j)  
    //         00436e6c     FSTP       float ptr [ECX + this->_padding_]
    //                              diam_map.cpp:298 (12)
    //         00436e6f     MOV        AX,word ptr [ESI + 0x130]
    //         00436e76     CMP        BP,AX
    //         00436e79     JGE        LAB_00436ea0
    //                              diam_map.cpp:300 (13)
    //         00436e7b     MOV        this,dword ptr [ESI + 0x12c]
    //         00436e81     MOV        word ptr [ECX + EDI*0x1 + this+0x12],0x0
    //                              diam_map.cpp:301 (22)
    //         00436e88     MOV        DX,word ptr [ESI + 0x130]
    //         00436e8f     MOV        EAX,dword ptr [ESI + 0x12c]
    //         00436e95     SUB        DX,BP
    //         00436e98     DEC        EDX
    //         00436e99     MOV        word ptr [EAX + EDI*0x1 + 0x10],DX
    //                              diam_map.cpp:303 (2)
    //         00436e9e     JMP        LAB_00436ebb
    //                               LAB_00436ea0                                                 XREF[1]:     00436e79(j)  
    //                              diam_map.cpp:305 (14)
    //         00436ea0     MOV        this,dword ptr [ESI + 0x12c]
    //         00436ea6     SUB        EBP,EAX
    //         00436ea8     INC        EBP
    //         00436ea9     MOV        word ptr [ECX + EDI*0x1 + this+0x12],BP
    //                              diam_map.cpp:306 (13)
    //         00436eae     MOV        EDX,dword ptr [ESI + 0x12c]
    //         00436eb4     MOV        word ptr [EDX + EDI*0x1 + 0x10],0x0
    //                               LAB_00436ebb                                                 XREF[1]:     00436e9e(j)  
    //                              diam_map.cpp:310 (14)
    //         00436ebb     MOV        EAX,dword ptr [ESI + 0x12c]
    //         00436ec1     MOV        this,dword ptr [ESP + local_c]
    //         00436ec5     MOV        EBX,dword ptr [ESP + tile_row]
    //                              diam_map.cpp:312 (44)
    //         00436ec9     FLD        float ptr [EAX + EDI*0x1 + 0x20]
    //         00436ecd     MOV        EAX,dword ptr [ESP + param_1]
    //         00436ed1     ADD        EBX,this
    //         00436ed3     FADDP      ST2,ST0
    //         00436ed5     INC        EAX
    //         00436ed6     MOV        dword ptr [ESP + tile_row],EBX
    //         00436eda     CMP        AX,word ptr [ESI + 0x138]
    //         00436ee1     MOV        dword ptr [ESP + param_1],EAX
    //         00436ee5     FADD       float ptr [ESI + 0x13c]
    //         00436eeb     JL         LAB_00436d1b
    //         00436ef1     FSTP       ST0
    //         00436ef3     XOR        EDI,EDI
    //                               LAB_00436ef5                                                 XREF[1]:     00436d11(j)  
    //                              diam_map.cpp:316 (22)
    //         00436ef5     FLD        float ptr [DAT_0056f604]
    //         00436efb     FDIV       float ptr [ESI + 0x13c]
    //         00436f01     FLD        ST0
    //         00436f03     CALL       __ftol                                           undefined __ftol()
    //         00436f08     MOV        this,AX
    //                              diam_map.cpp:317 (29)
    //         00436f0b     MOVSX      EDX,this
    //         00436f0e     MOV        dword ptr [ESP + param_1],EDX
    //         00436f12     MOV        word ptr [ESI + 0x148],this
    //         00436f19     FILD       dword ptr [ESP + param_1]
    //         00436f1d     FCOMP
    //         00436f1f     FNSTSW     AX
    //         00436f21     TEST       AH,0x40
    //         00436f24     FSTP       ST0
    //         00436f26     JNZ        LAB_00436f30
    //                              diam_map.cpp:318 (8)
    //         00436f28     INC        this
    //         00436f29     MOV        word ptr [ESI + 0x148],this
    //                               LAB_00436f30                                                 XREF[1]:     00436f26(j)  
    //                              diam_map.cpp:320 (19)
    //         00436f30     MOVSX      EAX,word ptr [ESP + tile_row]
    //         00436f35     MOVSX      this,word ptr [ESI + 0x138]
    //         00436f3c     CDQ
    //         00436f3d     IDIV       this
    //         00436f3f     MOV        dword ptr [ESP + param_1],this
    //                              diam_map.cpp:321 (12)
    //         00436f43     CMP        AX,DI
    //         00436f46     MOV        word ptr [ESI + 0x14a],AX
    //         00436f4d     JNZ        LAB_00436f58
    //                              diam_map.cpp:322 (9)
    //         00436f4f     MOV        word ptr [ESI + 0x14a],0x1
    //                               LAB_00436f58                                                 XREF[1]:     00436f4d(j)  
    //                              diam_map.cpp:326 (7)
    //         00436f58     MOV        AX,word ptr [ESI + 0x13a]
    //                              diam_map.cpp:332 (52)
    //         00436f5f     XOR        EBX,EBX
    //         00436f61     FILD       dword ptr [ESP + param_1]
    //         00436f65     MOVSX      this,AX
    //         00436f68     MOV        dword ptr [ESP + param_1],this
    //         00436f6c     CMP        AX,DI
    //         00436f6f     FILD       dword ptr [ESP + param_1]
    //         00436f73     FXCH
    //         00436f75     FXCH       ST2
    //         00436f77     FDIV       ST0,ST2
    //         00436f79     FXCH
    //         00436f7b     FDIVR      ST0,ST2
    //         00436f7d     FXCH
    //         00436f7f     FSTP       float ptr [ESI + 0x140]
    //         00436f85     FSTP       float ptr [ESI + 0x144]
    //         00436f8b     FSTP       ST0
    //         00436f8d     JLE        LAB_00437035
    //                               LAB_00436f93                                                 XREF[1]:     0043702f(j)  
    //                              diam_map.cpp:334 (23)
    //         00436f93     MOV        EDX,dword ptr [ESI + 0x12c]
    //         00436f99     MOVSX      EAX,BX
    //         00436f9c     LEA        this,[EAX + EAX*0x8]
    //         00436f9f     SHL        this,0x2
    //         00436fa2     MOV        AL,byte ptr [ECX + EDX*0x1 + this+0x2]
    //         00436fa6     TEST       AL,AL
    //         00436fa8     JZ         LAB_00436fae
    //                              diam_map.cpp:335 (2)
    //         00436faa     MOV        EDI,EBX
    //                              diam_map.cpp:336 (2)
    //         00436fac     JMP        LAB_00437027
    //                               LAB_00436fae                                                 XREF[1]:     00436fa8(j)  
    //                              diam_map.cpp:338 (17)
    //         00436fae     MOVSX      EAX,DI
    //         00436fb1     LEA        EAX,[EAX + EAX*0x8]
    //         00436fb4     SHL        EAX,0x2
    //         00436fb7     MOV        BP,word ptr [EAX + EDX*0x1]
    //         00436fbb     MOV        word ptr [this->_padding_ + EDX*0x1],BP
    //                              diam_map.cpp:339 (16)
    //         00436fbf     MOV        EDX,dword ptr [ESI + 0x12c]
    //         00436fc5     MOV        BP,word ptr [EAX + EDX*0x1 + 0x4]
    //         00436fca     MOV        word ptr [ECX + EDX*0x1 + this->_padding_],BP
    //                              diam_map.cpp:340 (14)
    //         00436fcf     MOV        EDX,dword ptr [ESI + 0x12c]
    //         00436fd5     MOV        EBP,dword ptr [EAX + EDX*0x1 + 0x8]
    //         00436fd9     MOV        dword ptr [ECX + EDX*0x1 + this->_padding_],EBP
    //                              diam_map.cpp:341 (16)
    //         00436fdd     MOV        EDX,dword ptr [ESI + 0x12c]
    //         00436fe3     MOV        BP,word ptr [EAX + EDX*0x1 + 0x14]
    //         00436fe8     MOV        word ptr [ECX + EDX*0x1 + this->_padding_],BP
    //                              diam_map.cpp:342 (14)
    //         00436fed     MOV        EDX,dword ptr [ESI + 0x12c]
    //         00436ff3     MOV        EBP,dword ptr [EAX + EDX*0x1 + 0x18]
    //         00436ff7     MOV        dword ptr [ECX + EDX*0x1 + this->_padding_],EBP
    //                              diam_map.cpp:343 (16)
    //         00436ffb     MOV        EDX,dword ptr [ESI + 0x12c]
    //         00437001     MOV        BP,word ptr [EAX + EDX*0x1 + 0x1c]
    //         00437006     MOV        word ptr [ECX + EDX*0x1 + this->_padding_],BP
    //                              diam_map.cpp:344 (14)
    //         0043700b     MOV        EDX,dword ptr [ESI + 0x12c]
    //         00437011     MOV        EBP,dword ptr [EAX + EDX*0x1 + 0x20]
    //         00437015     MOV        dword ptr [ECX + EDX*0x1 + this->_padding_],EBP
    //                              diam_map.cpp:345 (28)
    //         00437019     MOV        EDX,dword ptr [ESI + 0x12c]
    //         0043701f     MOV        EAX,dword ptr [EAX + EDX*0x1 + 0xc]
    //         00437023     MOV        dword ptr [ECX + EDX*0x1 + this->_padding_],EAX
    //                               LAB_00437027                                                 XREF[1]:     00436fac(j)  
    //         00437027     INC        EBX
    //         00437028     CMP        BX,word ptr [ESI + 0x13a]
    //         0043702f     JL         LAB_00436f93
    //                               LAB_00437035                                                 XREF[1]:     00436f8d(j)  
    //                              diam_map.cpp:353 (26)
    //         00437035     MOV        EDX,dword ptr [ESI]
    //         00437037     OR         EAX,0xffffffff
    //         0043703a     PUSH       0x2
    //         0043703c     MOV        this,ESI
    //         0043703e     MOV        word ptr [ESI + 0x14c],AX
    //         00437045     MOV        word ptr [ESI + 0x14e],AX
    //         0043704c     CALL       dword ptr [EDX + 0x20]
    //                              diam_map.cpp:354 (10)
    //         0043704f     POP        EDI
    //         00437050     POP        ESI
    //         00437051     POP        EBP
    //         00437052     POP        EBX
    //         00437053     ADD        ESP,0x10
    //         00437056     RET        0x4
    //                               LAB_00437059                                                 XREF[2]:     00436c47(j), 00436c53(j)  
    //                              diam_map.cpp:238 (6)
    //         00437059     MOV        dword ptr [ESI + 0xfc],EDI
    //                              diam_map.cpp:354 (10)
    //         0043705f     POP        EDI
    //         00437060     POP        ESI
    //         00437061     POP        EBP
    //         00437062     POP        EBX
    //         00437063     ADD        ESP,0x10
    //         00437066     RET        0x4
}

// Offset: 0x00437070
void set_player(RGE_Diamond_Map* this_, RGE_Player* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall RGE_Diamond_Map::set_player(class RGE_Player *)                               *
    //                              *********************************************************************************************************
    //                              void __thiscall set_player(RGE_Diamond_Map * this, RGE_Player * para
    //              void              <VOID>         <RETURN>
    //              RGE_Diamond_Ma    ECX:4 (auto)   this
    //              RGE_Player *      Stack[0x4]:4   param_1                   XREF[1]:     00437070(R)  
    //                               ?set_player@RGE_Diamond_Map@@QAEXPAVRGE_Player@@@Z           XREF[4]:     TRIBE_Screen_Game:004943de(c), 
    //                               RGE_Diamond_Map::set_player                                               player_changed:00498a91(c), 
    //                                                                                                         set_panel_info:004a87c0(c), 
    //                                                                                                         set_unit_player:004ab390(c)  
    //                              diam_map.cpp:360 (4)
    //         00437070     MOV        EAX,dword ptr [ESP + param_1]
    //                              diam_map.cpp:362 (13)
    //         00437074     MOV        EDX,dword ptr [this->_padding_]
    //         00437076     PUSH       0x2
    //         00437078     MOV        dword ptr [ECX + this->player],EAX
    //         0043707e     CALL       dword ptr [EDX + 0x20]
    //                              diam_map.cpp:363 (3)
    //         00437081     RET        0x4
}

// Offset: 0x00437090
void RGE_Diamond_Map_View::set_redraw(RedrawMode param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void __thiscall RGE_Diamond_Map::set_redraw(enum TPanel::RedrawMode)                  *
    //                              *********************************************************************************************************
    //                              void __thiscall set_redraw(RGE_Diamond_Map * this, RedrawMode param_1)
    //              void              <VOID>         <RETURN>
    //              RGE_Diamond_Ma    ECX:4 (auto)   this
    //              RedrawMode        Stack[0x4]:4   param_1                   XREF[1]:     00437092(R)  
    //                               ?set_redraw@RGE_Diamond_Map@@UAEXW4RedrawMode@TPanel@@@Z     XREF[3]:     set_redraw:0052ca39(c), 
    //                               RGE_Diamond_Map::set_redraw                                               0056f528(*), 00577708(*)  
    //                              diam_map.cpp:380 (2)
    //         00437090     PUSH       ESI
    //         00437091     PUSH       EDI
    //                              diam_map.cpp:381 (12)
    //         00437092     MOV        EDI,dword ptr [ESP + param_1]
    //         00437096     MOV        ESI,this
    //         00437098     PUSH       EDI
    //         00437099     CALL       TPanel::set_redraw                               void set_redraw(TPanel * this, RedrawMode par
    //                              diam_map.cpp:382 (5)
    //         0043709e     CMP        EDI,0x2
    //         004370a1     JNZ        LAB_004370ad
    //                              diam_map.cpp:383 (10)
    //         004370a3     MOV        dword ptr [ESI + 0x104],0x1
    //                               LAB_004370ad                                                 XREF[1]:     004370a1(j)  
    //                              diam_map.cpp:384 (5)
    //         004370ad     POP        EDI
    //         004370ae     POP        ESI
    //         004370af     RET        0x4
}

// Offset: 0x004370C0
void delete_surfaces(RGE_Diamond_Map* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall RGE_Diamond_Map::delete_surfaces(void)                                        *
    //                              *********************************************************************************************************
    //                              void __thiscall delete_surfaces(RGE_Diamond_Map * this)
    //              void              <VOID>         <RETURN>
    //              RGE_Diamond_Ma    ECX:4 (auto)   this
    //                               ?delete_surfaces@RGE_Diamond_Map@@QAEXXZ                     XREF[1]:     ~RGE_Diamond_Map:0043695b(c)  
    //                               RGE_Diamond_Map::delete_surfaces
    //                              diam_map.cpp:390 (4)
    //         004370c0     PUSH       ESI
    //         004370c1     MOV        ESI,this
    //         004370c3     PUSH       EDI
    //                              diam_map.cpp:391 (20)
    //         004370c4     MOV        EDI,dword ptr [ESI + 0x168]
    //         004370ca     TEST       EDI,EDI
    //         004370cc     JZ         LAB_00437100
    //         004370ce     MOV        EAX,dword ptr [ESI + 0x164]
    //         004370d4     TEST       EAX,EAX
    //         004370d6     JZ         LAB_00437100
    //                              diam_map.cpp:393 (20)
    //         004370d8     TEST       EDI,EDI
    //         004370da     JZ         LAB_004370ec
    //         004370dc     MOV        this,EDI
    //         004370de     CALL       TDrawArea::~TDrawArea                            void ~TDrawArea(TDrawArea * this)
    //         004370e3     PUSH       EDI
    //         004370e4     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         004370e9     ADD        ESP,0x4
    //                               LAB_004370ec                                                 XREF[1]:     004370da(j)  
    //                              diam_map.cpp:394 (10)
    //         004370ec     MOV        dword ptr [ESI + 0x168],0x0
    //                              diam_map.cpp:395 (10)
    //         004370f6     MOV        dword ptr [ESI + 0x164],0x0
    //                               LAB_00437100                                                 XREF[2]:     004370cc(j), 004370d6(j)  
    //                              diam_map.cpp:397 (3)
    //         00437100     POP        EDI
    //         00437101     POP        ESI
    //         00437102     RET
}

// Offset: 0x00437120
int create_surfaces(RGE_Diamond_Map* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall RGE_Diamond_Map::create_surfaces(void)                                         *
    //                              *********************************************************************************************************
    //                              int __thiscall create_surfaces(RGE_Diamond_Map * this)
    //              int               EAX:4          <RETURN>
    //              RGE_Diamond_Ma    ECX:4 (auto)   this
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     0043715b(W), 00437179(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[3]:     00437189(R), 004371dd(R), 00437213(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     00437155(W)  
    //                               ?create_surfaces@RGE_Diamond_Map@@QAEHXZ                     XREF[1]:     handle_size:00438657(c)  
    //                               RGE_Diamond_Map::create_surfaces
    //                              diam_map.cpp:403 (26)
    //         00437120     PUSH       -0x1
    //         00437122     PUSH       FUN_0055cf5b
    //         00437127     MOV        EAX,FS:[0x0]
    //         0043712d     PUSH       EAX
    //         0043712e     MOV        dword ptr FS:[0x0],ESP
    //         00437135     PUSH       this
    //         00437136     PUSH       ESI
    //         00437137     MOV        ESI,this
    //         00437139     PUSH       EDI
    //                              diam_map.cpp:404 (14)
    //         0043713a     MOV        this,dword ptr [ESI + 0x168]
    //         00437140     TEST       this,this
    //         00437142     JNZ        LAB_004371fa
    //                              diam_map.cpp:406 (47)
    //         00437148     PUSH       0x100
    //         0043714d     CALL       operator_new                                     void * operator_new(uint param_1)
    //         00437152     ADD        ESP,0x4
    //         00437155     MOV        dword ptr [ESP + local_10],EAX
    //         00437159     TEST       EAX,EAX
    //         0043715b     MOV        dword ptr [ESP + local_4],0x0
    //         00437163     JZ         LAB_00437175
    //         00437165     PUSH       0x0
    //         00437167     PUSH       s_Diamond_map_(restored)                         = "Diamond map (restored)"
    //         0043716c     MOV        this,EAX
    //         0043716e     CALL       TDrawArea::TDrawArea                             undefined TDrawArea(TDrawArea * this, char * 
    //         00437173     JMP        LAB_00437177
    //                               LAB_00437175                                                 XREF[1]:     00437163(j)  
    //         00437175     XOR        EAX,EAX
    //                               LAB_00437177                                                 XREF[1]:     00437173(j)  
    //                              diam_map.cpp:407 (18)
    //         00437177     TEST       EAX,EAX
    //         00437179     MOV        dword ptr [ESP + local_4],0xffffffff
    //         00437181     MOV        dword ptr [ESI + 0x168],EAX
    //         00437187     JNZ        LAB_0043719a
    //                              diam_map.cpp:420 (17)
    //         00437189     MOV        this,dword ptr [ESP + local_c]
    //         0043718d     MOV        dword ptr FS:[0x0],this
    //         00437194     POP        EDI
    //         00437195     POP        ESI
    //         00437196     ADD        ESP,0x10
    //         00437199     RET
    //                               LAB_0043719a                                                 XREF[1]:     00437187(j)  
    //                              diam_map.cpp:409 (29)
    //         0043719a     MOV        this,dword ptr [ESI + 0x18]
    //         0043719d     MOV        EDX,dword ptr [ESI + 0x14]
    //         004371a0     PUSH       0x0
    //         004371a2     PUSH       0x0
    //         004371a4     PUSH       this
    //         004371a5     MOV        this,dword ptr [ESI + 0x20]
    //         004371a8     PUSH       EDX
    //         004371a9     MOV        EDX,dword ptr [this->_padding_]
    //         004371ab     MOV        this,EAX
    //         004371ad     PUSH       EDX
    //         004371ae     CALL       TDrawArea::Init                                  int Init(TDrawArea * this, TDrawSystem * para
    //         004371b3     TEST       EAX,EAX
    //         004371b5     JNZ        LAB_004371ee
    //                              diam_map.cpp:411 (26)
    //         004371b7     MOV        EDI,dword ptr [ESI + 0x168]
    //         004371bd     TEST       EDI,EDI
    //         004371bf     JZ         LAB_004371d1
    //         004371c1     MOV        this,EDI
    //         004371c3     CALL       TDrawArea::~TDrawArea                            void ~TDrawArea(TDrawArea * this)
    //         004371c8     PUSH       EDI
    //         004371c9     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         004371ce     ADD        ESP,0x4
    //                               LAB_004371d1                                                 XREF[1]:     004371bf(j)  
    //                              diam_map.cpp:412 (10)
    //         004371d1     MOV        dword ptr [ESI + 0x168],0x0
    //                              diam_map.cpp:413 (2)
    //         004371db     XOR        EAX,EAX
    //                              diam_map.cpp:420 (17)
    //         004371dd     MOV        this,dword ptr [ESP + local_c]
    //         004371e1     MOV        dword ptr FS:[0x0],this
    //         004371e8     POP        EDI
    //         004371e9     POP        ESI
    //         004371ea     ADD        ESP,0x10
    //         004371ed     RET
    //                               LAB_004371ee                                                 XREF[1]:     004371b5(j)  
    //                              diam_map.cpp:415 (10)
    //         004371ee     MOV        dword ptr [ESI + 0x164],0x1
    //                              diam_map.cpp:417 (12)
    //         004371f8     JMP        LAB_00437213
    //                               LAB_004371fa                                                 XREF[1]:     00437142(j)  
    //         004371fa     MOV        EAX,dword ptr [ESI + 0x164]
    //         00437200     TEST       EAX,EAX
    //         00437202     JZ         LAB_00437213
    //                              diam_map.cpp:418 (15)
    //         00437204     MOV        EAX,dword ptr [ESI + 0x18]
    //         00437207     MOV        EDX,dword ptr [ESI + 0x14]
    //         0043720a     PUSH       0x0
    //         0043720c     PUSH       EAX
    //         0043720d     PUSH       EDX
    //         0043720e     CALL       TDrawArea::SetSize                               void SetSize(TDrawArea * this, long param_1, 
    //                               LAB_00437213                                                 XREF[2]:     004371f8(j), 00437202(j)  
    //                              diam_map.cpp:420 (22)
    //         00437213     MOV        this,dword ptr [ESP + local_c]
    //         00437217     POP        EDI
    //         00437218     MOV        EAX,0x1
    //         0043721d     MOV        dword ptr FS:[0x0],this
    //         00437224     POP        ESI
    //         00437225     ADD        ESP,0x10
    //         00437228     RET
}

// Offset: 0x004372C0
void RGE_Diamond_Map::draw() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void __thiscall RGE_Diamond_Map::draw(void)                                           *
    //                              *********************************************************************************************************
    //                              void __thiscall draw(RGE_Diamond_Map * this)
    //              void              <VOID>         <RETURN>
    //              RGE_Diamond_Ma    ECX:4 (auto)   this
    //                               ?draw@RGE_Diamond_Map@@UAEXXZ                                XREF[2]:     draw:0053d8aa(c), 0056f538(*)  
    //                               RGE_Diamond_Map::draw
    //                              diam_map.cpp:426 (4)
    //         004372c0     PUSH       ESI
    //         004372c1     MOV        ESI,this
    //         004372c3     PUSH       EDI
    //                              diam_map.cpp:427 (47)
    //         004372c4     MOV        EAX,dword ptr [ESI + 0x20]
    //         004372c7     TEST       EAX,EAX
    //         004372c9     JZ         LAB_00437478
    //         004372cf     MOV        EAX,dword ptr [ESI + 0x168]
    //         004372d5     TEST       EAX,EAX
    //         004372d7     JZ         LAB_00437478
    //         004372dd     MOV        EAX,dword ptr [ESI + 0x70]
    //         004372e0     TEST       EAX,EAX
    //         004372e2     JZ         LAB_00437478
    //         004372e8     MOV        EAX,dword ptr [ESI + 0x6c]
    //         004372eb     TEST       EAX,EAX
    //         004372ed     JZ         LAB_00437478
    //                              diam_map.cpp:434 (56)
    //         004372f3     MOV        EAX,dword ptr [ESI + 0xfc]
    //         004372f9     TEST       EAX,EAX
    //         004372fb     JZ         LAB_0043741a
    //         00437301     MOV        EAX,dword ptr [ESI + 0xf8]
    //         00437307     TEST       EAX,EAX
    //         00437309     JZ         LAB_0043741a
    //         0043730f     MOV        EAX,dword ptr [ESI + 0x128]
    //         00437315     TEST       EAX,EAX
    //         00437317     JZ         LAB_0043741a
    //         0043731d     MOV        EAX,dword ptr [ESI + 0x12c]
    //         00437323     TEST       EAX,EAX
    //         00437325     JZ         LAB_0043741a
    //                              diam_map.cpp:464 (7)
    //         0043732b     MOV        EDI,dword ptr [ESI]
    //         0043732d     PUSH       0x0
    //         0043732f     CALL       dword ptr [EDI + 0x28]
    //                              diam_map.cpp:466 (14)
    //         00437332     MOV        EAX,dword ptr [ESI + 0xf4]
    //         00437338     MOV        EDX,0x1
    //         0043733d     MOV        this,byte ptr [EAX + 0x7c]
    //                              diam_map.cpp:469 (18)
    //         00437340     MOV        EAX,dword ptr [ESI + 0x104]
    //         00437346     SHL        EDX,this
    //         00437348     TEST       EAX,EAX
    //         0043734a     MOV        dword ptr [ESI + 0x160],EDX
    //         00437350     JZ         LAB_004373b0
    //                              diam_map.cpp:472 (7)
    //         00437352     MOV        this,dword ptr [ESI + 0x40]
    //         00437355     TEST       this,this
    //         00437357     JZ         LAB_00437387
    //                              diam_map.cpp:474 (9)
    //         00437359     MOV        EAX,dword ptr [this->_padding_]
    //         0043735b     LEA        EDX,[ESI + 0x24]
    //         0043735e     PUSH       EDX
    //         0043735f     CALL       dword ptr [EAX + 0x34]
    //                              diam_map.cpp:475 (28)
    //         00437362     MOV        this,dword ptr [ESI + 0x168]
    //         00437368     LEA        EAX,[ESI + 0x8c]
    //         0043736e     PUSH       0x0
    //         00437370     PUSH       EAX=>DAT_fffffff8
    //         00437371     PUSH       0x0=>DAT_fffffff4
    //         00437373     PUSH       0x0=>DAT_fffffff0
    //         00437375     PUSH       this
    //         00437376     MOV        this,dword ptr [ESI + 0x20]
    //         00437379     CALL       TDrawArea::Copy                                  void Copy(TDrawArea * this, TDrawArea * param
    //                              diam_map.cpp:476 (7)
    //         0043737e     MOV        this,ESI
    //         00437380     CALL       RGE_Diamond_Map::clear_image                     void clear_image(RGE_Diamond_Map * this)
    //                              diam_map.cpp:478 (2)
    //         00437385     JMP        LAB_0043739d
    //                               LAB_00437387                                                 XREF[1]:     00437357(j)  
    //                              diam_map.cpp:479 (22)
    //         00437387     MOV        this,dword ptr [ESI + 0x168]
    //         0043738d     XOR        EDX,EDX
    //         0043738f     MOV        DL,byte ptr [ESI + 0xef]
    //         00437395     PUSH       EDX
    //         00437396     PUSH       0x0=>DAT_fffffff8
    //         00437398     CALL       TDrawArea::Clear                                 void Clear(TDrawArea * this, tagRECT * param_
    //                               LAB_0043739d                                                 XREF[1]:     00437385(j)  
    //                              diam_map.cpp:482 (7)
    //         0043739d     MOV        this,ESI
    //         0043739f     CALL       RGE_Diamond_Map::draw_all_tiles                  void draw_all_tiles(RGE_Diamond_Map * this)
    //                              diam_map.cpp:483 (10)
    //         004373a4     MOV        dword ptr [ESI + 0x104],0x0
    //                              diam_map.cpp:485 (2)
    //         004373ae     JMP        LAB_004373b7
    //                               LAB_004373b0                                                 XREF[1]:     00437350(j)  
    //                              diam_map.cpp:486 (7)
    //         004373b0     MOV        this,ESI
    //         004373b2     CALL       RGE_Diamond_Map::draw_explored_tiles             void draw_explored_tiles(RGE_Diamond_Map * th
    //                               LAB_004373b7                                                 XREF[1]:     004373ae(j)  
    //                              diam_map.cpp:491 (7)
    //         004373b7     MOV        this,ESI
    //         004373b9     CALL       RGE_Diamond_Map::copy_image                      void copy_image(RGE_Diamond_Map * this)
    //                              diam_map.cpp:494 (14)
    //         004373be     MOV        EAX,[rge_base_game]                              = 00000000
    //         004373c3     CMP        dword ptr [EAX + 0x1b4],0x15
    //         004373ca     JZ         LAB_004373d4
    //                              diam_map.cpp:495 (8)
    //         004373cc     MOV        this,ESI
    //         004373ce     CALL       dword ptr [EDI + 0xe0]
    //                               LAB_004373d4                                                 XREF[1]:     004373ca(j)  
    //                              diam_map.cpp:498 (8)
    //         004373d4     MOV        this,ESI
    //         004373d6     CALL       dword ptr [EDI + 0xe4]
    //                              diam_map.cpp:501 (19)
    //         004373dc     MOV        this,dword ptr [ESI + 0x20]
    //         004373df     PUSH       0x1
    //         004373e1     PUSH       s_diam_map::draw                                 = "diam_map::draw"
    //         004373e6     CALL       TDrawArea::Lock                                  uchar * Lock(TDrawArea * this, char * param_1
    //         004373eb     TEST       EAX,EAX
    //         004373ed     JZ         LAB_00437404
    //                              diam_map.cpp:503 (8)
    //         004373ef     MOV        this,ESI
    //         004373f1     CALL       dword ptr [EDI + 0xf0]
    //                              diam_map.cpp:504 (13)
    //         004373f7     MOV        this,dword ptr [ESI + 0x20]
    //         004373fa     PUSH       s_diam_map::draw                                 = "diam_map::draw"
    //         004373ff     CALL       TDrawArea::Unlock                                void Unlock(TDrawArea * this, char * param_1)
    //                               LAB_00437404                                                 XREF[1]:     004373ed(j)  
    //                              diam_map.cpp:507 (5)
    //         00437404     MOV        this,ESI
    //         00437406     CALL       dword ptr [EDI + 0x2c]
    //                              diam_map.cpp:509 (14)
    //         00437409     MOV        this,dword ptr [ESI + 0xf8]
    //         0043740f     ADD        this,0x6c
    //         00437412     CALL       RGE_Tile_List::del_list                          void del_list(RGE_Tile_List * this)
    //                              diam_map.cpp:510 (3)
    //         00437417     POP        EDI
    //         00437418     POP        ESI
    //         00437419     RET
    //                               LAB_0043741a                                                 XREF[4]:     004372fb(j), 00437309(j), 
    //                                                                                                         00437317(j), 00437325(j)  
    //                              diam_map.cpp:436 (9)
    //         0043741a     MOV        EDI,dword ptr [ESI]
    //         0043741c     PUSH       0x0
    //         0043741e     MOV        this,ESI
    //         00437420     CALL       dword ptr [EDI + 0x28]
    //                              diam_map.cpp:438 (10)
    //         00437423     MOV        EAX,dword ptr [ESI + 0x128]
    //         00437429     TEST       EAX,EAX
    //         0043742b     JZ         LAB_00437443
    //                              diam_map.cpp:449 (7)
    //         0043742d     MOV        this,ESI
    //         0043742f     CALL       RGE_Diamond_Map::clear_image                     void clear_image(RGE_Diamond_Map * this)
    //                              diam_map.cpp:450 (7)
    //         00437434     MOV        this,ESI
    //         00437436     CALL       RGE_Diamond_Map::copy_image                      void copy_image(RGE_Diamond_Map * this)
    //                              diam_map.cpp:460 (5)
    //         0043743b     MOV        this,ESI
    //         0043743d     CALL       dword ptr [EDI + 0x2c]
    //                              diam_map.cpp:510 (3)
    //         00437440     POP        EDI
    //         00437441     POP        ESI
    //         00437442     RET
    //                               LAB_00437443                                                 XREF[1]:     0043742b(j)  
    //                              diam_map.cpp:454 (7)
    //         00437443     MOV        this,dword ptr [ESI + 0x40]
    //         00437446     TEST       this,this
    //         00437448     JZ         LAB_0043745b
    //                              diam_map.cpp:455 (9)
    //         0043744a     MOV        EDX,dword ptr [this->_padding_]
    //         0043744c     LEA        EAX,[ESI + 0x24]
    //         0043744f     PUSH       EAX
    //         00437450     CALL       dword ptr [EDX + 0x34]
    //                              diam_map.cpp:460 (5)
    //         00437453     MOV        this,ESI
    //         00437455     CALL       dword ptr [EDI + 0x2c]
    //                              diam_map.cpp:510 (3)
    //         00437458     POP        EDI
    //         00437459     POP        ESI
    //         0043745a     RET
    //                               LAB_0043745b                                                 XREF[1]:     00437448(j)  
    //                              diam_map.cpp:457 (21)
    //         0043745b     XOR        this,this
    //         0043745d     LEA        EDX,[ESI + 0x24]
    //         00437460     MOV        this,byte ptr [ESI + 0xef]
    //         00437466     PUSH       this
    //         00437467     MOV        this,dword ptr [ESI + 0x20]
    //         0043746a     PUSH       EDX=>DAT_fffffff8
    //         0043746b     CALL       TDrawArea::Clear                                 void Clear(TDrawArea * this, tagRECT * param_
    //                              diam_map.cpp:460 (5)
    //         00437470     MOV        this,ESI
    //         00437472     CALL       dword ptr [EDI + 0x2c]
    //                              diam_map.cpp:510 (3)
    //         00437475     POP        EDI
    //         00437476     POP        ESI
    //         00437477     RET
    //                               LAB_00437478                                                 XREF[4]:     004372c9(j), 004372d7(j), 
    //                                                                                                         004372e2(j), 004372ed(j)  
    //                              diam_map.cpp:429 (7)
    //         00437478     MOV        dword ptr [ESI + 0x38],0x0
    //                              diam_map.cpp:510 (3)
    //         0043747f     POP        EDI
    //         00437480     POP        ESI
    //         00437481     RET
}

// Offset: 0x004374C0
void clear_image(RGE_Diamond_Map* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * protected: void __thiscall RGE_Diamond_Map::clear_image(void)                                         *
    //                              *********************************************************************************************************
    //                              void __thiscall clear_image(RGE_Diamond_Map * this)
    //              void              <VOID>         <RETURN>
    //              RGE_Diamond_Ma    ECX:4 (auto)   this
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     00437546(W), 004375d5(R)  
    //              undefined4        Stack[-0x8]:4  local_8                   XREF[3]:     0043755d(W), 004375d9(R), 004375ec(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[3]:     00437555(W), 004375d1(R), 004375e4(W)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[3]:     00437559(W), 004375cd(R), 004375e8(W)  
    //                               ?clear_image@RGE_Diamond_Map@@IAEXXZ                         XREF[2]:     draw:00437380(c), 
    //                               RGE_Diamond_Map::clear_image                                              draw:0043742f(c)  
    //                              diam_map.cpp:519 (6)
    //         004374c0     SUB        ESP,0x10
    //         004374c3     PUSH       ESI
    //         004374c4     MOV        ESI,this
    //                              diam_map.cpp:526 (26)
    //         004374c6     PUSH       0x1
    //         004374c8     PUSH       s_diam_map::clear_image                          = "diam_map::clear_image"
    //         004374cd     MOV        this,dword ptr [ESI + 0x168]
    //         004374d3     CALL       TDrawArea::Lock                                  uchar * Lock(TDrawArea * this, char * param_1
    //         004374d8     TEST       EAX,EAX
    //         004374da     JZ         LAB_00437609
    //                              diam_map.cpp:530 (6)
    //         004374e0     MOV        EAX,dword ptr [ESI + 0x168]
    //                              diam_map.cpp:532 (28)
    //         004374e6     MOV        DX,word ptr [ESI + 0x134]
    //         004374ed     PUSH       EDI
    //         004374ee     PUSH       EBP
    //         004374ef     MOV        this,dword ptr [EAX + 0x24]
    //         004374f2     PUSH       EBX
    //         004374f3     CMP        this,0x1
    //         004374f6     JNZ        LAB_0043750a
    //         004374f8     MOVSX      EBX,DX
    //         004374fb     IMUL       EBX,dword ptr [EAX + 0x20]
    //         004374ff     MOV        this,dword ptr [EAX + 0x8]
    //                              diam_map.cpp:533 (6)
    //         00437502     MOV        AX,word ptr [EAX + 0x20]
    //         00437506     ADD        EBX,this
    //                              diam_map.cpp:535 (2)
    //         00437508     JMP        LAB_00437523
    //                               LAB_0043750a                                                 XREF[1]:     004374f6(j)  
    //                              diam_map.cpp:537 (16)
    //         0043750a     MOV        EBX,dword ptr [EAX + 0x1c]
    //         0043750d     MOV        EDI,dword ptr [EAX + 0x8]
    //         00437510     MOVSX      this,DX
    //         00437513     SUB        EBX,this
    //         00437515     DEC        EBX
    //         00437516     IMUL       EBX,dword ptr [EAX + 0x20]
    //                              diam_map.cpp:538 (9)
    //         0043751a     MOV        AX,word ptr [EAX + 0x20]
    //         0043751e     ADD        EBX,EDI
    //         00437520     NEG        AX
    //                               LAB_00437523                                                 XREF[1]:     00437508(j)  
    //                              diam_map.cpp:543 (32)
    //         00437523     MOV        this,word ptr [ESI + 0x10]
    //         00437527     MOV        EDI,dword ptr [ESI + 0x128]
    //         0043752d     ADD        this,DX
    //         00437530     MOV        DX,word ptr [ESI + 0x138]
    //         00437537     ADD        DX,this
    //         0043753a     CMP        this,DX
    //         0043753d     JGE        LAB_004375f6
    //                              diam_map.cpp:565 (90)
    //         00437543     MOVSX      EAX,AX
    //         00437546     MOV        dword ptr [ESP + local_4],EAX
    //         0043754a     ADD        EDI,0x4
    //         0043754d     MOVSX      EAX,this
    //         00437550     MOVSX      this,DX
    //         00437553     SUB        this,EAX
    //         00437555     MOV        dword ptr [ESP + local_c],EDI
    //         00437559     MOV        dword ptr [ESP + local_10],EAX
    //         0043755d     MOV        dword ptr [ESP + local_8],this
    //                               LAB_00437561                                                 XREF[1]:     004375f0(j)  
    //         00437561     CMP        EAX,dword ptr [ESI + 0x28]
    //         00437564     JL         LAB_004375d1
    //         00437566     CMP        EAX,dword ptr [ESI + 0x30]
    //         00437569     JG         LAB_004375d1
    //         0043756b     MOV        DX,word ptr [EDI + -0x2]
    //         0043756f     MOV        AX,word ptr [ESI + 0xc]
    //         00437573     ADD        AX,DX
    //         00437576     MOV        this,AX
    //         00437579     ADD        this,word ptr [EDI]
    //         0043757c     MOV        EDI,dword ptr [ESI + 0x24]
    //         0043757f     MOVSX      EBP,AX
    //         00437582     DEC        this
    //         00437583     CMP        EBP,EDI
    //         00437585     JGE        LAB_00437593
    //         00437587     MOV        DI,word ptr [ESI + 0x24]
    //         0043758b     MOV        EBP,EDI
    //         0043758d     SUB        EBP,EAX
    //         0043758f     MOV        EAX,EDI
    //         00437591     ADD        EDX,EBP
    //                               LAB_00437593                                                 XREF[1]:     00437585(j)  
    //         00437593     MOV        EBP,dword ptr [ESI + 0x2c]
    //         00437596     MOVSX      EDI,this
    //         00437599     CMP        EDI,EBP
    //         0043759b     JLE        LAB_004375a1
    //                              diam_map.cpp:559 (4)
    //         0043759d     MOV        this,word ptr [ESI + 0x2c]
    //                               LAB_004375a1                                                 XREF[1]:     0043759b(j)  
    //                              diam_map.cpp:561 (15)
    //         004375a1     MOVSX      EDI,AX
    //         004375a4     CMP        EDI,dword ptr [ESI + 0x24]
    //         004375a7     JL         LAB_004375cd
    //         004375a9     MOVSX      EAX,this
    //         004375ac     CMP        EAX,EBP
    //         004375ae     JG         LAB_004375cd
    //                              diam_map.cpp:562 (33)
    //         004375b0     SUB        EAX,EDI
    //         004375b2     XOR        this,this
    //         004375b4     MOV        this,byte ptr [ESI + 0xef]
    //         004375ba     INC        EAX
    //         004375bb     MOVSX      EDX,DX
    //         004375be     PUSH       EAX
    //         004375bf     MOV        EAX,EBX
    //         004375c1     ADD        EAX,EDX
    //         004375c3     PUSH       this
    //         004375c4     PUSH       EAX
    //         004375c5     CALL       memset                                           undefined memset()
    //         004375ca     ADD        ESP,0xc
    //                               LAB_004375cd                                                 XREF[2]:     004375a7(j), 004375ae(j)  
    //         004375cd     MOV        EAX,dword ptr [ESP + local_10]
    //                               LAB_004375d1                                                 XREF[2]:     00437564(j), 00437569(j)  
    //                              diam_map.cpp:564 (4)
    //         004375d1     MOV        EDI,dword ptr [ESP + local_c]
    //                              diam_map.cpp:565 (33)
    //         004375d5     MOV        EBP,dword ptr [ESP + local_4]
    //         004375d9     MOV        this,dword ptr [ESP + local_8]
    //         004375dd     ADD        EDI,0x6
    //         004375e0     ADD        EBX,EBP
    //         004375e2     INC        EAX
    //         004375e3     DEC        this
    //         004375e4     MOV        dword ptr [ESP + local_c],EDI
    //         004375e8     MOV        dword ptr [ESP + local_10],EAX
    //         004375ec     MOV        dword ptr [ESP + local_8],this
    //         004375f0     JNZ        LAB_00437561
    //                               LAB_004375f6                                                 XREF[1]:     0043753d(j)  
    //                              diam_map.cpp:568 (19)
    //         004375f6     MOV        this,dword ptr [ESI + 0x168]
    //         004375fc     PUSH       s_diam_map::clear_image                          = "diam_map::clear_image"
    //         00437601     CALL       TDrawArea::Unlock                                void Unlock(TDrawArea * this, char * param_1)
    //         00437606     POP        EBX
    //         00437607     POP        EBP
    //         00437608     POP        EDI
    //                               LAB_00437609                                                 XREF[1]:     004374da(j)  
    //                              diam_map.cpp:569 (5)
    //         00437609     POP        ESI
    //         0043760a     ADD        ESP,0x10
    //         0043760d     RET
}

// Offset: 0x00437620
void copy_image(RGE_Diamond_Map* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * protected: void __thiscall RGE_Diamond_Map::copy_image(void)                                          *
    //                              *********************************************************************************************************
    //                              void __thiscall copy_image(RGE_Diamond_Map * this)
    //              void              <VOID>         <RETURN>
    //              RGE_Diamond_Ma    ECX:4 (auto)   this
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     0043763a(W)  
    //              tagRECT           Stack[-0x14]   r                         XREF[0,4]:   00437629(*), 00437641(*), 00437635(W), 0043762d(W)  
    //                               ?copy_image@RGE_Diamond_Map@@IAEXXZ                          XREF[2]:     draw:004373b9(c), 
    //                               RGE_Diamond_Map::copy_image                                               draw:00437436(c)  
    //                              diam_map.cpp:575 (3)
    //         00437620     SUB        ESP,0x10
    //                              diam_map.cpp:579 (14)
    //         00437623     MOV        EDX,dword ptr [ECX + this->_padding_]
    //         00437626     XOR        EAX,EAX
    //         00437628     DEC        EDX
    //         00437629     MOV        dword ptr [ESP]=>r.top,EAX
    //         0043762d     MOV        dword ptr [ESP + r.bottom],EDX
    //                              diam_map.cpp:580 (8)
    //         00437631     MOV        EDX,dword ptr [ECX + this->_padding_]
    //         00437634     DEC        EDX
    //         00437635     MOV        dword ptr [ESP + r.right],EAX
    //                              diam_map.cpp:581 (33)
    //         00437639     PUSH       EAX
    //         0043763a     MOV        dword ptr [ESP + local_4],EDX
    //         0043763e     MOV        EDX,dword ptr [ECX + this->_padding_]
    //         00437641     LEA        EAX=>r.top,[ESP + 0x4]
    //         00437645     PUSH       EAX
    //         00437646     MOV        EAX,dword ptr [ECX + this->_padding_]
    //         00437649     PUSH       EDX
    //         0043764a     MOV        EDX,dword ptr [ECX + this->_padding_]
    //         0043764d     MOV        this,dword ptr [ECX + this->save_area]
    //         00437653     PUSH       EAX
    //         00437654     PUSH       EDX
    //         00437655     CALL       TDrawArea::Copy                                  void Copy(TDrawArea * this, TDrawArea * param
    //                              diam_map.cpp:654 (4)
    //         0043765a     ADD        ESP,0x10
    //         0043765d     RET
}

// Offset: 0x00437660
void draw_all_tiles(RGE_Diamond_Map* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * protected: void __thiscall RGE_Diamond_Map::draw_all_tiles(void)                                      *
    //                              *********************************************************************************************************
    //                              void __thiscall draw_all_tiles(RGE_Diamond_Map * this)
    //              void              <VOID>         <RETURN>
    //              RGE_Diamond_Ma    ECX:4 (auto)   this
    //                               ?draw_all_tiles@RGE_Diamond_Map@@IAEXXZ                      XREF[1]:     draw:0043739f(c)  
    //                               RGE_Diamond_Map::draw_all_tiles
    //                              diam_map.cpp:660 (3)
    //         00437660     PUSH       EDI
    //         00437661     MOV        EDI,this
    //                              diam_map.cpp:663 (23)
    //         00437663     PUSH       0x1
    //         00437665     PUSH       s_diam_map::draw_all_tiles                       = "diam_map::draw_all_tiles"
    //         0043766a     MOV        this,dword ptr [EDI + 0x168]
    //         00437670     CALL       TDrawArea::Lock                                  uchar * Lock(TDrawArea * this, char * param_1
    //         00437675     TEST       EAX,EAX
    //         00437677     JZ         LAB_004376c4
    //         00437679     PUSH       EBX
    //                              diam_map.cpp:666 (11)
    //         0043767a     XOR        EBX,EBX
    //         0043767c     CMP        word ptr [EDI + 0x132],BX
    //         00437683     JLE        LAB_004376b3
    //                              diam_map.cpp:660 (1)
    //         00437685     PUSH       ESI
    //                               LAB_00437686                                                 XREF[1]:     004376b0(j)  
    //                              diam_map.cpp:668 (11)
    //         00437686     XOR        ESI,ESI
    //         00437688     CMP        word ptr [EDI + 0x130],SI
    //         0043768f     JLE        LAB_004376a8
    //                               LAB_00437691                                                 XREF[1]:     004376a6(j)  
    //                              diam_map.cpp:669 (23)
    //         00437691     PUSH       0x0
    //         00437693     PUSH       0x0
    //         00437695     PUSH       EBX
    //         00437696     PUSH       ESI
    //         00437697     MOV        this,EDI
    //         00437699     CALL       RGE_Diamond_Map::draw_tile                       void draw_tile(RGE_Diamond_Map * this, short 
    //         0043769e     INC        ESI
    //         0043769f     CMP        SI,word ptr [EDI + 0x130]
    //         004376a6     JL         LAB_00437691
    //                               LAB_004376a8                                                 XREF[1]:     0043768f(j)  
    //                              diam_map.cpp:666 (10)
    //         004376a8     INC        EBX
    //         004376a9     CMP        BX,word ptr [EDI + 0x132]
    //         004376b0     JL         LAB_00437686
    //                              diam_map.cpp:660 (1)
    //         004376b2     POP        ESI
    //                               LAB_004376b3                                                 XREF[1]:     00437683(j)  
    //                              diam_map.cpp:672 (17)
    //         004376b3     MOV        this,dword ptr [EDI + 0x168]
    //         004376b9     PUSH       s_diam_map::draw_all_tiles                       = "diam_map::draw_all_tiles"
    //         004376be     CALL       TDrawArea::Unlock                                void Unlock(TDrawArea * this, char * param_1)
    //         004376c3     POP        EBX
    //                               LAB_004376c4                                                 XREF[1]:     00437677(j)  
    //                              diam_map.cpp:673 (2)
    //         004376c4     POP        EDI
    //         004376c5     RET
}

// Offset: 0x004376D0
void draw_explored_tiles(RGE_Diamond_Map* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * protected: void __thiscall RGE_Diamond_Map::draw_explored_tiles(void)                                 *
    //                              *********************************************************************************************************
    //                              void __thiscall draw_explored_tiles(RGE_Diamond_Map * this)
    //              void              <VOID>         <RETURN>
    //              RGE_Diamond_Ma    ECX:4 (auto)   this
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[4]:     004376d3(*), 004376ee(R), 0043770c(R), 00437733(R)  
    //              int               Stack[-0x8]:4  list_size                 XREF[4]:     004376da(*), 00437717(R), 0043772f(R), 0043773d(W)  
    //              RGE_Tile_List_    Stack[-0xc]:4  list
    //                               ?draw_explored_tiles@RGE_Diamond_Map@@IAEXXZ                 XREF[1]:     draw:004373b2(c)  
    //                               RGE_Diamond_Map::draw_explored_tiles
    //                              diam_map.cpp:679 (3)
    //         004376d0     SUB        ESP,0x8
    //                              diam_map.cpp:683 (27)
    //         004376d3     LEA        EAX=>local_4,[ESP + 0x4]
    //         004376d7     PUSH       EDI
    //         004376d8     MOV        EDI,this
    //         004376da     LEA        this=>list_size,[ESP + 0x4]
    //         004376de     PUSH       EAX
    //         004376df     PUSH       this
    //         004376e0     MOV        this,dword ptr [EDI + 0xf8]
    //         004376e6     ADD        this,0x6c
    //         004376e9     CALL       RGE_Tile_List::get_list_info                     void get_list_info(RGE_Tile_List * this, RGE_
    //                              diam_map.cpp:685 (8)
    //         004376ee     MOV        EAX,dword ptr [ESP + local_4]
    //         004376f2     TEST       EAX,EAX
    //         004376f4     JLE        LAB_00437754
    //                              diam_map.cpp:687 (22)
    //         004376f6     MOV        this,dword ptr [EDI + 0x168]
    //         004376fc     PUSH       0x1
    //         004376fe     PUSH       s_diam_map::draw_explored_tiles                  = "diam_map::draw_explored_tiles"
    //         00437703     CALL       TDrawArea::Lock                                  uchar * Lock(TDrawArea * this, char * param_1
    //         00437708     TEST       EAX,EAX
    //         0043770a     JZ         LAB_00437754
    //                              diam_map.cpp:689 (15)
    //         0043770c     MOV        EAX,dword ptr [ESP + local_4]
    //         00437710     PUSH       ESI
    //         00437711     XOR        ESI,ESI
    //         00437713     TEST       EAX,EAX
    //         00437715     JLE        LAB_00437743
    //         00437717     MOV        EAX,dword ptr [ESP + list_size]
    //                               LAB_0043771b                                                 XREF[1]:     00437741(j)  
    //                              diam_map.cpp:690 (40)
    //         0043771b     MOV        DX,word ptr [EAX + 0x4]
    //         0043771f     MOV        AX,word ptr [EAX]
    //         00437722     PUSH       0x0
    //         00437724     PUSH       0x0
    //         00437726     PUSH       EDX
    //         00437727     PUSH       EAX
    //         00437728     MOV        this,EDI
    //         0043772a     CALL       RGE_Diamond_Map::draw_tile                       void draw_tile(RGE_Diamond_Map * this, short 
    //         0043772f     MOV        EAX,dword ptr [ESP + list_size]
    //         00437733     MOV        this,dword ptr [ESP + local_4]
    //         00437737     INC        ESI
    //         00437738     ADD        EAX,0x8
    //         0043773b     CMP        ESI,this
    //         0043773d     MOV        dword ptr [ESP + list_size],EAX
    //         00437741     JL         LAB_0043771b
    //                               LAB_00437743                                                 XREF[1]:     00437715(j)  
    //                              diam_map.cpp:692 (17)
    //         00437743     MOV        this,dword ptr [EDI + 0x168]
    //         00437749     PUSH       s_diam_map::draw_explored_tiles                  = "diam_map::draw_explored_tiles"
    //         0043774e     CALL       TDrawArea::Unlock                                void Unlock(TDrawArea * this, char * param_1)
    //         00437753     POP        ESI
    //                               LAB_00437754                                                 XREF[2]:     004376f4(j), 0043770a(j)  
    //                              diam_map.cpp:693 (5)
    //         00437754     POP        EDI
    //         00437755     ADD        ESP,0x8
    //         00437758     RET
}

// Offset: 0x00437760
void draw_tile(RGE_Diamond_Map* this_, short param_2, short param_3, int param_4, uchar param_5) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * protected: void __thiscall RGE_Diamond_Map::draw_tile(short,short,int,unsigned char)                  *
    //                              *********************************************************************************************************
    //                              void __thiscall draw_tile(RGE_Diamond_Map * this, short param_1, sho
    //              void              <VOID>         <RETURN>
    //              RGE_Diamond_Ma    ECX:4 (auto)   this
    //              short             Stack[0x4]:2   param_1                   XREF[3]:     0043776c(R), 004377ed(R), 00437954(R)  
    //              short             Stack[0x8]:2   param_2                   XREF[9]:     00437765(R), 004377f1(R), 00437924(R), 0043792b(W), 
    //                                                                                     00437936(R), 004379df(W), 00437aae(R), 00437af3(W), 
    //                                                                                     00437bb9(R)  
    //              int               Stack[0xc]:4   param_3                   XREF[3]:     0043789c(R), 00437962(W), 00437966(R)  
    //              uchar             Stack[0x10]:1  param_4                   XREF[11]:    004378a8(R), 00437932(W), 004379a7(R), 004379bb(R), 
    //                                                                                     004379c3(W), 00437a78(W), 00437aaa(R), 00437abe(W), 
    //                                                                                     00437b88(W), 00437bb5(R), 00437bc9(W)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     004377b7(W), 00437983(R)  
    //              undefined4        Stack[-0x8]:4  local_8                   XREF[2]:     00437778(W), 0043795b(R)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[10]:    00437811(W), 00437815(R), 0043782c(W), 00437830(R), 
    //                                                                                     00437844(W), 00437848(R), 0043788a(W), 00437ab2(R), 
    //                                                                                     00437aeb(W), 00437bbd(R)  
    //              long              Stack[-0x10]:4 x                         XREF[6]:     004377c9(W), 00437886(R), 00437898(W), 004378c3(R), 
    //                                                                                     004378e4(R), 00437905(R)  
    //              uchar             Stack[-0x14]:1 terrain                   XREF[5]:     00437799(W), 00437825(R), 00437863(R), 004379cc(R), 
    //                                                                                     00437ad1(R)  
    //              RGE_Map_Tile_R    Stack[-0x18]:4 tile_row                  XREF[10]:    0043788e(W), 004379f2(R), 00437a18(R), 00437a53(R), 
    //                                                                                     00437a8a(R), 00437aef(W), 00437b08(R), 00437b2d(R), 
    //                                                                                     00437b66(R), 00437b93(R)  
    //              long              Stack[-0x1c]:4 y                         XREF[9]:     00437773(W), 004378de(W), 004378ff(W), 00437920(W), 
    //                                                                                     004379b7(W), 004379ee(R), 00437a14(R), 00437a4c(R), 
    //                                                                                     00437a94(R)  
    //              uchar             Stack[-0x20]:1 color
    //                               ?draw_tile@RGE_Diamond_Map@@IAEXFFHE@Z                       XREF[3]:     draw_all_tiles:00437699(c), 
    //                               RGE_Diamond_Map::draw_tile                                                draw_explored_tiles:0043772a(c), 
    //                                                                                                         draw_selected_area:00437c84(c)  
    //                              diam_map.cpp:699 (5)
    //         00437760     SUB        ESP,0x1c
    //         00437763     PUSH       EBX
    //         00437764     PUSH       EBP
    //                              diam_map.cpp:716 (56)
    //         00437765     MOVSX      EBP,word ptr [ESP + param_2]
    //         0043776a     PUSH       ESI
    //         0043776b     PUSH       EDI
    //         0043776c     MOVSX      ESI,word ptr [ESP + param_1]
    //         00437771     MOV        EDI,this
    //         00437773     MOV        byte ptr [ESP + y],0x0
    //         00437778     MOV        dword ptr [ESP + local_8],ESI
    //         0043777c     MOV        AX,word ptr [EDI + 0x130]
    //         00437783     MOVSX      this,AX
    //         00437786     MOV        EAX,EBP
    //         00437788     ADD        EAX,this
    //         0043778a     SUB        EAX,ESI
    //         0043778c     LEA        EDX,[EAX + EAX*0x8]
    //         0043778f     MOV        EAX,dword ptr [EDI + 0x12c]
    //         00437795     LEA        EDX,[EAX + EDX*0x4 + -0x24]
    //         00437799     MOV        dword ptr [ESP + terrain],EDX
    //                              diam_map.cpp:718 (11)
    //         0043779d     MOV        AL,byte ptr [EDX + 0x2]
    //         004377a0     TEST       AL,AL
    //         004377a2     JZ         LAB_00437bcf
    //                              diam_map.cpp:722 (25)
    //         004377a8     MOV        EBX,dword ptr [EDI + 0xfc]
    //         004377ae     LEA        this,[ESI + ESI*0x2]
    //         004377b1     MOV        EAX,dword ptr [EBX + 0x8d8c]
    //         004377b7     MOV        dword ptr [ESP + local_4],EAX
    //         004377bb     MOV        EAX,dword ptr [EAX + EBP*0x4]
    //         004377be     LEA        this,[EAX + this->_padding_*0x8]
    //                              diam_map.cpp:724 (44)
    //         004377c1     MOV        AL,byte ptr [EBX + 0x8db8]
    //         004377c7     TEST       AL,AL
    //         004377c9     MOV        dword ptr [ESP + x],this
    //         004377cd     JNZ        LAB_004377ed
    //         004377cf     MOV        EAX,dword ptr [EBP*0x4 + unified_map_offsets]    = 00000000
    //         004377d6     MOV        this,dword ptr [EDI + 0xf8]
    //         004377dc     MOV        EAX,dword ptr [EAX + ESI*0x4]
    //         004377df     MOV        ESI,dword ptr [ECX + this->_padding_]
    //         004377e5     TEST       ESI,EAX
    //         004377e7     JZ         LAB_00437bcf
    //                               LAB_004377ed                                                 XREF[1]:     004377cd(j)  
    //                              diam_map.cpp:730 (13)
    //         004377ed     MOV        EAX,dword ptr [ESP + param_1]
    //         004377f1     MOV        this,dword ptr [ESP + param_2]
    //         004377f5     CMP        AX,this
    //         004377f8     JGE        LAB_004377fc
    //                              diam_map.cpp:731 (2)
    //         004377fa     MOV        this,EAX
    //                               LAB_004377fc                                                 XREF[1]:     004377f8(j)  
    //                              diam_map.cpp:735 (11)
    //         004377fc     FLD        float ptr [EDX + 0x20]
    //         004377ff     FCOMP      float ptr [DAT_0056f604]
    //         00437805     XOR        ESI,ESI
    //                              diam_map.cpp:737 (21)
    //         00437807     MOVSX      this,this
    //         0043780a     FNSTSW     AX
    //         0043780c     TEST       AH,0x1
    //         0043780f     JZ         LAB_00437844
    //         00437811     MOV        dword ptr [ESP + local_c],this
    //         00437815     FILD       dword ptr [ESP + local_c]
    //         00437819     FMUL       float ptr [EDX + 0x20]
    //                              diam_map.cpp:738 (9)
    //         0043781c     FLD        ST0
    //         0043781e     CALL       __ftol                                           undefined __ftol()
    //         00437823     MOV        this,EAX
    //                              diam_map.cpp:740 (29)
    //         00437825     MOV        EAX,dword ptr [ESP + terrain]
    //         00437829     MOVSX      EDX,this
    //         0043782c     MOV        dword ptr [ESP + local_c],EDX
    //         00437830     FILD       dword ptr [ESP + local_c]
    //         00437834     FSUBR      ST0,ST1
    //         00437836     FCOMP      float ptr [EAX + 0x20]
    //         00437839     FNSTSW     AX
    //         0043783b     TEST       AH,0x1
    //         0043783e     FSTP       ST0
    //         00437840     JZ         LAB_0043785b
    //                              diam_map.cpp:743 (2)
    //         00437842     JMP        LAB_00437856
    //                               LAB_00437844                                                 XREF[1]:     0043780f(j)  
    //                              diam_map.cpp:746 (18)
    //         00437844     MOV        dword ptr [ESP + local_c],this
    //         00437848     FILD       dword ptr [ESP + local_c]
    //         0043784c     FMUL       float ptr [EDX + 0x18]
    //         0043784f     CALL       __ftol                                           undefined __ftol()
    //         00437854     MOV        this,EAX
    //                               LAB_00437856                                                 XREF[1]:     00437842(j)  
    //                              diam_map.cpp:747 (5)
    //         00437856     MOV        ESI,0x1
    //                               LAB_0043785b                                                 XREF[1]:     00437840(j)  
    //                              diam_map.cpp:749 (8)
    //         0043785b     TEST       ESI,ESI
    //         0043785d     JZ         LAB_00437bcf
    //                              diam_map.cpp:755 (26)
    //         00437863     MOV        EDX,dword ptr [ESP + terrain]
    //         00437867     MOV        ESI,dword ptr [EDI + 0x128]
    //         0043786d     MOVSX      this,this
    //         00437870     MOVSX      EAX,word ptr [EDX]
    //         00437873     LEA        EDX,[EAX + EAX*0x2]
    //         00437876     MOVSX      ESI,word ptr [ESI + EDX*0x2 + 0x2]
    //         0043787b     ADD        ESI,this
    //                              diam_map.cpp:756 (9)
    //         0043787d     MOVSX      this,word ptr [EDI + 0x134]
    //         00437884     ADD        this,EAX
    //                              diam_map.cpp:758 (22)
    //         00437886     MOV        EAX,dword ptr [ESP + x]
    //         0043788a     MOV        dword ptr [ESP + local_c],ESI
    //         0043788e     MOV        dword ptr [ESP + tile_row],this
    //         00437892     MOV        DL,byte ptr [EAX + 0x5]
    //         00437895     AND        DL,0x1f
    //         00437898     MOV        byte ptr [ESP + x],DL
    //                              diam_map.cpp:759 (12)
    //         0043789c     MOV        EDX,dword ptr [ESP + param_3]
    //         004378a0     TEST       EDX,EDX
    //         004378a2     JNZ        LAB_00437ace
    //                              diam_map.cpp:762 (6)
    //         004378a8     MOV        this,byte ptr [ESP + param_4]
    //         004378ac     TEST       this,this
    //                              diam_map.cpp:764 (2)
    //         004378ae     JA         LAB_00437920
    //                              diam_map.cpp:766 (19)
    //         004378b0     XOR        this,this
    //         004378b2     MOV        this,byte ptr [EAX + 0x4]
    //         004378b5     MOV        EAX,this
    //         004378b7     CMP        EAX,0x10
    //         004378ba     JA         switchD_004378bc::default
    //                               switchD_004378bc::switchD
    //         004378bc     JMP        dword ptr [EAX*0x4 + switchD_004378bc::switchd   = 004378c3
    //                               switchD_004378bc::caseD_0                                    XREF[2]:     004378bc(j), 00437bdc(*)  
    //                              diam_map.cpp:769 (31)
    //         004378c3     MOV        this,dword ptr [ESP + x]
    //         004378c7     AND        this,0xff
    //         004378cd     MOV        EAX,this
    //         004378cf     SHL        EAX,0x4
    //         004378d2     ADD        EAX,this
    //         004378d4     LEA        EDX,[EAX + EAX*0x2]
    //         004378d7     MOV        AL,byte ptr [EBX + EDX*0x8 + 0xb5]
    //         004378de     MOV        byte ptr [ESP + y],AL
    //                              diam_map.cpp:770 (2)
    //         004378e2     JMP        switchD_004378bc::default
    //                               switchD_004378bc::caseD_4                                    XREF[10]:    004378bc(j), 00437be0(*), 
    //                               switchD_004378bc::caseD_5                                                 00437bec(*), 00437bf0(*), 
    //                               switchD_004378bc::caseD_7                                                 00437bf8(*), 00437bfc(*), 
    //                               switchD_004378bc::caseD_8                                                 00437c00(*), 00437c0c(*), 
    //                               switchD_004378bc::caseD_9                                                 00437c10(*), 00437c18(*)  
    //                               switchD_004378bc::caseD_c
    //                               switchD_004378bc::caseD_d
    //                               switchD_004378bc::caseD_f
    //                               switchD_004378bc::caseD_1
    //                              diam_map.cpp:780 (31)
    //         004378e4     MOV        this,dword ptr [ESP + x]
    //         004378e8     AND        this,0xff
    //         004378ee     MOV        EAX,this
    //         004378f0     SHL        EAX,0x4
    //         004378f3     ADD        EAX,this
    //         004378f5     LEA        this,[EAX + EAX*0x2]
    //         004378f8     MOV        DL,byte ptr [EBX + this->_padding_*0x8 + 0xb6]
    //         004378ff     MOV        byte ptr [ESP + y],DL
    //                              diam_map.cpp:781 (2)
    //         00437903     JMP        switchD_004378bc::default
    //                               switchD_004378bc::caseD_3                                    XREF[8]:     004378bc(j), 00437be4(*), 
    //                               switchD_004378bc::caseD_6                                                 00437be8(*), 00437bf4(*), 
    //                               switchD_004378bc::caseD_a                                                 00437c04(*), 00437c08(*), 
    //                               switchD_004378bc::caseD_b                                                 00437c14(*), 00437c1c(*)  
    //                               switchD_004378bc::caseD_e
    //                               switchD_004378bc::caseD_10
    //                               switchD_004378bc::caseD_2
    //                              diam_map.cpp:790 (31)
    //         00437905     MOV        this,dword ptr [ESP + x]
    //         00437909     AND        this,0xff
    //         0043790f     MOV        EAX,this
    //         00437911     SHL        EAX,0x4
    //         00437914     ADD        EAX,this
    //         00437916     LEA        EAX,[EAX + EAX*0x2]
    //         00437919     MOV        this,byte ptr [EBX + EAX*0x8 + 0xb4]
    //                               LAB_00437920                                                 XREF[1]:     004378ae(j)  
    //         00437920     MOV        byte ptr [ESP + y],this
    //                               switchD_004378bc::default                                    XREF[3]:     004378ba(j), 004378e2(j), 
    //                                                                                                         00437903(j)  
    //                              diam_map.cpp:809 (33)
    //         00437924     MOV        EDX,dword ptr [ESP + param_2]
    //         00437928     ADD        EBP,0x2
    //         0043792b     MOV        dword ptr [ESP + param_2],EBP
    //         0043792f     LEA        this,[EDX + -0x1]
    //         00437932     MOV        dword ptr [ESP + param_4],this
    //                               LAB_00437936                                                 XREF[1]:     004379c7(j)  
    //         00437936     MOV        EAX,dword ptr [ESP + param_2]
    //         0043793a     MOVSX      EBP,this
    //         0043793d     CMP        EBP,EAX
    //         0043793f     JGE        LAB_004379cc
    //                              diam_map.cpp:811 (15)
    //         00437945     CMP        this,-0x1
    //         00437949     JLE        LAB_004379c2
    //         0043794b     CMP        this,word ptr [EDI + 0x132]
    //         00437952     JGE        LAB_004379c2
    //                              diam_map.cpp:813 (29)
    //         00437954     MOV        EAX,dword ptr [ESP + param_1]
    //         00437958     LEA        EDX,[EAX + -0x1]
    //         0043795b     MOV        EAX,dword ptr [ESP + local_8]
    //         0043795f     ADD        EAX,0x2
    //         00437962     MOV        dword ptr [ESP + param_3],EAX
    //                               LAB_00437966                                                 XREF[2]:     004379ac(j), 004379c0(j)  
    //         00437966     MOV        EBX,dword ptr [ESP + param_3]
    //         0043796a     MOVSX      EAX,DX
    //         0043796d     CMP        EAX,EBX
    //         0043796f     JGE        LAB_004379c2
    //                              diam_map.cpp:815 (15)
    //         00437971     CMP        DX,-0x1
    //         00437975     JLE        LAB_004379bb
    //         00437977     CMP        DX,word ptr [EDI + 0x130]
    //         0043797e     JGE        LAB_004379bb
    //                              diam_map.cpp:818 (18)
    //         00437980     LEA        this,[EAX + EAX*0x2]
    //         00437983     MOV        EAX,dword ptr [ESP + local_4]
    //         00437987     MOV        EAX,dword ptr [EAX + EBP*0x4]
    //         0043798a     MOV        EAX,dword ptr [EAX + this->_padding_*0x8 + 0x10]
    //         0043798e     TEST       EAX,EAX
    //         00437990     JZ         LAB_004379bb
    //                               LAB_00437992                                                 XREF[1]:     004379a5(j)  
    //                              diam_map.cpp:820 (2)
    //         00437992     MOV        this,dword ptr [EAX]
    //                              diam_map.cpp:822 (26)
    //         00437994     MOV        EBX,dword ptr [ECX + this->_padding_]
    //         00437997     CMP        byte ptr [EBX + 0x8e],0x4
    //         0043799e     JZ         LAB_004379ae
    //         004379a0     MOV        EAX,dword ptr [EAX + 0x4]
    //         004379a3     TEST       EAX,EAX
    //         004379a5     JNZ        LAB_00437992
    //         004379a7     MOV        this,dword ptr [ESP + param_4]
    //         004379ab     INC        EDX
    //         004379ac     JMP        LAB_00437966
    //                               LAB_004379ae                                                 XREF[1]:     0043799e(j)  
    //                              diam_map.cpp:824 (20)
    //         004379ae     MOV        this,dword ptr [ECX + this->_padding_]
    //         004379b1     MOV        AL,byte ptr [ECX + this->_padding_]
    //         004379b7     MOV        byte ptr [ESP + y],AL
    //                               LAB_004379bb                                                 XREF[3]:     00437975(j), 0043797e(j), 
    //                                                                                                         00437990(j)  
    //         004379bb     MOV        this,dword ptr [ESP + param_4]
    //         004379bf     INC        EDX
    //         004379c0     JMP        LAB_00437966
    //                               LAB_004379c2                                                 XREF[3]:     00437949(j), 00437952(j), 
    //                                                                                                         0043796f(j)  
    //                              diam_map.cpp:809 (10)
    //         004379c2     INC        this
    //         004379c3     MOV        dword ptr [ESP + param_4],this
    //         004379c7     JMP        LAB_00437936
    //                               LAB_004379cc                                                 XREF[1]:     0043793f(j)  
    //                              diam_map.cpp:833 (4)
    //         004379cc     MOV        this,dword ptr [ESP + terrain]
    //                              diam_map.cpp:835 (25)
    //         004379d0     MOV        DX,word ptr [EDI + 0x148]
    //         004379d7     CMP        DX,0x1
    //         004379db     MOV        AX,word ptr [ECX + this->_padding_]
    //         004379df     MOV        dword ptr [ESP + param_2],EAX
    //         004379e3     JNZ        LAB_00437a73
    //                              diam_map.cpp:837 (5)
    //         004379e9     CMP        AX,DX
    //         004379ec     JNZ        LAB_00437a0e
    //                              diam_map.cpp:838 (22)
    //         004379ee     MOV        EDX,dword ptr [ESP + y]
    //         004379f2     MOV        EAX,dword ptr [ESP + tile_row]
    //         004379f6     MOV        this,dword ptr [EDI + 0x168]
    //         004379fc     PUSH       EDX
    //         004379fd     PUSH       EAX
    //         004379fe     PUSH       ESI
    //         004379ff     CALL       TDrawArea::SetPixel                              void SetPixel(TDrawArea * this, long param_1,
    //                              diam_map.cpp:891 (10)
    //         00437a04     POP        EDI
    //         00437a05     POP        ESI
    //         00437a06     POP        EBP
    //         00437a07     POP        EBX
    //         00437a08     ADD        ESP,0x1c
    //         00437a0b     RET        0x10
    //                               LAB_00437a0e                                                 XREF[1]:     004379ec(j)  
    //                              diam_map.cpp:839 (6)
    //         00437a0e     CMP        AX,0x2
    //         00437a12     JNZ        LAB_00437a43
    //                              diam_map.cpp:841 (22)
    //         00437a14     MOV        EBX,dword ptr [ESP + y]
    //         00437a18     MOV        EBP,dword ptr [ESP + tile_row]
    //         00437a1c     MOV        this,dword ptr [EDI + 0x168]
    //         00437a22     PUSH       EBX
    //         00437a23     PUSH       EBP
    //         00437a24     PUSH       ESI
    //         00437a25     CALL       TDrawArea::SetPixel                              void SetPixel(TDrawArea * this, long param_1,
    //                              diam_map.cpp:842 (15)
    //         00437a2a     MOV        this,dword ptr [EDI + 0x168]
    //         00437a30     PUSH       EBX
    //         00437a31     INC        ESI
    //         00437a32     PUSH       EBP
    //         00437a33     PUSH       ESI
    //         00437a34     CALL       TDrawArea::SetPixel                              void SetPixel(TDrawArea * this, long param_1,
    //                              diam_map.cpp:891 (10)
    //         00437a39     POP        EDI
    //         00437a3a     POP        ESI
    //         00437a3b     POP        EBP
    //         00437a3c     POP        EBX
    //         00437a3d     ADD        ESP,0x1c
    //         00437a40     RET        0x10
    //                               LAB_00437a43                                                 XREF[1]:     00437a12(j)  
    //                              diam_map.cpp:846 (9)
    //         00437a43     TEST       AX,AX
    //         00437a46     JLE        LAB_00437bcf
    //                              diam_map.cpp:891 (39)
    //         00437a4c     MOV        EBP,dword ptr [ESP + y]
    //         00437a50     MOVSX      EBX,AX
    //                               LAB_00437a53                                                 XREF[1]:     00437a67(j)  
    //         00437a53     MOV        this,dword ptr [ESP + tile_row]
    //         00437a57     PUSH       EBP
    //         00437a58     PUSH       this
    //         00437a59     MOV        this,dword ptr [EDI + 0x168]
    //         00437a5f     PUSH       ESI
    //         00437a60     CALL       TDrawArea::SetPixel                              void SetPixel(TDrawArea * this, long param_1,
    //         00437a65     INC        ESI
    //         00437a66     DEC        EBX
    //         00437a67     JNZ        LAB_00437a53
    //         00437a69     POP        EDI
    //         00437a6a     POP        ESI
    //         00437a6b     POP        EBP
    //         00437a6c     POP        EBX
    //         00437a6d     ADD        ESP,0x1c
    //         00437a70     RET        0x10
    //                               LAB_00437a73                                                 XREF[1]:     004379e3(j)  
    //                              diam_map.cpp:852 (15)
    //         00437a73     XOR        this,this
    //         00437a75     TEST       DX,DX
    //         00437a78     MOV        dword ptr [ESP + param_4],this
    //         00437a7c     JLE        LAB_00437bcf
    //                               LAB_00437a82                                                 XREF[1]:     00437ac2(j)  
    //                              diam_map.cpp:854 (5)
    //         00437a82     TEST       AX,AX
    //         00437a85     JLE        LAB_00437ab6
    //                              diam_map.cpp:855 (61)
    //         00437a87     MOVSX      EDX,this
    //         00437a8a     MOV        this,dword ptr [ESP + tile_row]
    //         00437a8e     MOVSX      EBX,AX
    //         00437a91     LEA        EBP,[this->_padding_ + EDX*0x1]
    //                               LAB_00437a94                                                 XREF[1]:     00437aa8(j)  
    //         00437a94     MOV        EDX,dword ptr [ESP + y]
    //         00437a98     MOV        this,dword ptr [EDI + 0x168]
    //         00437a9e     PUSH       EDX
    //         00437a9f     PUSH       EBP
    //         00437aa0     PUSH       ESI
    //         00437aa1     CALL       TDrawArea::SetPixel                              void SetPixel(TDrawArea * this, long param_1,
    //         00437aa6     INC        ESI
    //         00437aa7     DEC        EBX
    //         00437aa8     JNZ        LAB_00437a94
    //         00437aaa     MOV        this,dword ptr [ESP + param_4]
    //         00437aae     MOV        EAX,dword ptr [ESP + param_2]
    //         00437ab2     MOV        ESI,dword ptr [ESP + local_c]
    //                               LAB_00437ab6                                                 XREF[1]:     00437a85(j)  
    //         00437ab6     INC        this
    //         00437ab7     CMP        this,word ptr [EDI + 0x148]
    //         00437abe     MOV        dword ptr [ESP + param_4],this
    //         00437ac2     JL         LAB_00437a82
    //                              diam_map.cpp:891 (10)
    //         00437ac4     POP        EDI
    //         00437ac5     POP        ESI
    //         00437ac6     POP        EBP
    //         00437ac7     POP        EBX
    //         00437ac8     ADD        ESP,0x1c
    //         00437acb     RET        0x10
    //                               LAB_00437ace                                                 XREF[1]:     004378a2(j)  
    //                              diam_map.cpp:863 (3)
    //         00437ace     MOV        EDX,dword ptr [EDI + 0x10]
    //                              diam_map.cpp:865 (9)
    //         00437ad1     MOV        EAX,dword ptr [ESP + terrain]
    //         00437ad5     MOV        EBX,dword ptr [EDI + 0xc]
    //         00437ad8     ADD        this,EDX
    //                              diam_map.cpp:867 (35)
    //         00437ada     MOV        DX,word ptr [EDI + 0x148]
    //         00437ae1     MOV        AX,word ptr [EAX + 0x14]
    //         00437ae5     ADD        ESI,EBX
    //         00437ae7     CMP        DX,0x1
    //         00437aeb     MOV        dword ptr [ESP + local_c],ESI
    //         00437aef     MOV        dword ptr [ESP + tile_row],this
    //         00437af3     MOV        dword ptr [ESP + param_2],EAX
    //         00437af7     JNZ        LAB_00437b83
    //                              diam_map.cpp:869 (5)
    //         00437afd     CMP        AX,DX
    //         00437b00     JNZ        LAB_00437b21
    //                              diam_map.cpp:870 (21)
    //         00437b02     MOV        this,byte ptr [EDI + 0x158]
    //         00437b08     MOV        EDX,dword ptr [ESP + tile_row]
    //         00437b0c     PUSH       this
    //         00437b0d     MOV        this,dword ptr [EDI + 0x20]
    //         00437b10     PUSH       EDX
    //         00437b11     PUSH       ESI
    //         00437b12     CALL       TDrawArea::SetPixel                              void SetPixel(TDrawArea * this, long param_1,
    //                              diam_map.cpp:891 (10)
    //         00437b17     POP        EDI
    //         00437b18     POP        ESI
    //         00437b19     POP        EBP
    //         00437b1a     POP        EBX
    //         00437b1b     ADD        ESP,0x1c
    //         00437b1e     RET        0x10
    //                               LAB_00437b21                                                 XREF[1]:     00437b00(j)  
    //                              diam_map.cpp:871 (6)
    //         00437b21     CMP        AX,0x2
    //         00437b25     JNZ        LAB_00437b58
    //                              diam_map.cpp:873 (21)
    //         00437b27     MOV        AL,byte ptr [EDI + 0x158]
    //         00437b2d     MOV        EBX,dword ptr [ESP + tile_row]
    //         00437b31     MOV        this,dword ptr [EDI + 0x20]
    //         00437b34     PUSH       EAX
    //         00437b35     PUSH       EBX
    //         00437b36     PUSH       ESI
    //         00437b37     CALL       TDrawArea::SetPixel                              void SetPixel(TDrawArea * this, long param_1,
    //                              diam_map.cpp:874 (18)
    //         00437b3c     MOV        this,byte ptr [EDI + 0x158]
    //         00437b42     INC        ESI
    //         00437b43     PUSH       this
    //         00437b44     MOV        this,dword ptr [EDI + 0x20]
    //         00437b47     PUSH       EBX
    //         00437b48     PUSH       ESI
    //         00437b49     CALL       TDrawArea::SetPixel                              void SetPixel(TDrawArea * this, long param_1,
    //                              diam_map.cpp:891 (10)
    //         00437b4e     POP        EDI
    //         00437b4f     POP        ESI
    //         00437b50     POP        EBP
    //         00437b51     POP        EBX
    //         00437b52     ADD        ESP,0x1c
    //         00437b55     RET        0x10
    //                               LAB_00437b58                                                 XREF[1]:     00437b25(j)  
    //                              diam_map.cpp:878 (5)
    //         00437b58     TEST       AX,AX
    //         00437b5b     JLE        LAB_00437bcf
    //                              diam_map.cpp:891 (3)
    //         00437b5d     MOVSX      EBX,AX
    //                               LAB_00437b60                                                 XREF[1]:     00437b77(j)  
    //                              diam_map.cpp:879 (25)
    //         00437b60     MOV        DL,byte ptr [EDI + 0x158]
    //         00437b66     MOV        EAX,dword ptr [ESP + tile_row]
    //         00437b6a     MOV        this,dword ptr [EDI + 0x20]
    //         00437b6d     PUSH       EDX
    //         00437b6e     PUSH       EAX
    //         00437b6f     PUSH       ESI
    //         00437b70     CALL       TDrawArea::SetPixel                              void SetPixel(TDrawArea * this, long param_1,
    //         00437b75     INC        ESI
    //         00437b76     DEC        EBX
    //         00437b77     JNZ        LAB_00437b60
    //                              diam_map.cpp:891 (10)
    //         00437b79     POP        EDI
    //         00437b7a     POP        ESI
    //         00437b7b     POP        EBP
    //         00437b7c     POP        EBX
    //         00437b7d     ADD        ESP,0x1c
    //         00437b80     RET        0x10
    //                               LAB_00437b83                                                 XREF[1]:     00437af7(j)  
    //                              diam_map.cpp:884 (11)
    //         00437b83     XOR        this,this
    //         00437b85     TEST       DX,DX
    //         00437b88     MOV        dword ptr [ESP + param_4],this
    //         00437b8c     JLE        LAB_00437bcf
    //                               LAB_00437b8e                                                 XREF[1]:     00437bcd(j)  
    //                              diam_map.cpp:886 (5)
    //         00437b8e     TEST       AX,AX
    //         00437b91     JLE        LAB_00437bc1
    //                              diam_map.cpp:887 (60)
    //         00437b93     MOV        EDX,dword ptr [ESP + tile_row]
    //         00437b97     MOVSX      this,this
    //         00437b9a     MOVSX      EBP,AX
    //         00437b9d     LEA        EBX,[EDX + this->_padding_*0x1]
    //                               LAB_00437ba0                                                 XREF[1]:     00437bb3(j)  
    //         00437ba0     MOV        AL,byte ptr [EDI + 0x158]
    //         00437ba6     MOV        this,dword ptr [EDI + 0x20]
    //         00437ba9     PUSH       EAX
    //         00437baa     PUSH       EBX
    //         00437bab     PUSH       ESI
    //         00437bac     CALL       TDrawArea::SetPixel                              void SetPixel(TDrawArea * this, long param_1,
    //         00437bb1     INC        ESI
    //         00437bb2     DEC        EBP
    //         00437bb3     JNZ        LAB_00437ba0
    //         00437bb5     MOV        this,dword ptr [ESP + param_4]
    //         00437bb9     MOV        EAX,dword ptr [ESP + param_2]
    //         00437bbd     MOV        ESI,dword ptr [ESP + local_c]
    //                               LAB_00437bc1                                                 XREF[1]:     00437b91(j)  
    //         00437bc1     INC        this
    //         00437bc2     CMP        this,word ptr [EDI + 0x148]
    //         00437bc9     MOV        dword ptr [ESP + param_4],this
    //         00437bcd     JL         LAB_00437b8e
    //                               LAB_00437bcf                                                 XREF[7]:     004377a2(j), 004377e7(j), 
    //                                                                                                         0043785d(j), 00437a46(j), 
    //                                                                                                         00437a7c(j), 00437b5b(j), 
    //                                                                                                         00437b8c(j)  
    //                              diam_map.cpp:891 (81)
    //         00437bcf     POP        EDI
    //         00437bd0     POP        ESI
    //         00437bd1     POP        EBP
    //         00437bd2     POP        EBX
    //         00437bd3     ADD        ESP,0x1c
    //         00437bd6     RET        0x10
}

// Offset: 0x00437BD9
undefined FUN_00437bd9() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00437bd9()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00437bd9
    //         00437bd9     NOP
    //         00437bda     MOV        EDI,EDI
    //                              Symbol Ref: No symbol: NONAME
    //                               switchD_004378bc::switchdataD_00437bdc                       XREF[1]:     draw_tile:004378bc(*)  
}

// Offset: 0x00437C20
void RGE_Diamond_Map_View::draw_selected_area() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * protected: virtual void __thiscall RGE_Diamond_Map::draw_selected_area(void)                          *
    //                              *********************************************************************************************************
    //                              void __thiscall draw_selected_area(RGE_Diamond_Map * this)
    //              void              <VOID>         <RETURN>
    //              RGE_Diamond_Ma    ECX:4 (auto)   this
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     00437c3c(*), 00437c67(R)  
    //              long              Stack[-0x8]:4  sel_row1                  XREF[3]:     00437c30(*), 00437c62(R), 00437c96(R)  
    //              long              Stack[-0xc]:4  sel_row2                  XREF[3]:     00437c40(*), 00437c74(R), 00437c92(R)  
    //              long              Stack[-0x10]:4 sel_col1                  XREF[3]:     00437c36(*), 00437c6f(R), 00437c89(R)  
    //              long              Stack[-0x14]:4 sel_col2
    //                               ?draw_selected_area@RGE_Diamond_Map@@MAEXXZ                  XREF[3]:     0056f5e8(*), 00577430(*), 
    //                               RGE_Diamond_Map::draw_selected_area                                       005777c8(*)  
    //                              diam_map.cpp:897 (6)
    //         00437c20     SUB        ESP,0x10
    //         00437c23     PUSH       EBX
    //         00437c24     MOV        EBX,this
    //                              diam_map.cpp:901 (10)
    //         00437c26     MOV        this,dword ptr [EBX + 0x150]
    //         00437c2c     TEST       this,this
    //         00437c2e     JZ         LAB_00437cae
    //                              diam_map.cpp:904 (31)
    //         00437c30     LEA        EAX=>sel_row1,[ESP + 0xc]
    //         00437c34     PUSH       0x1
    //         00437c36     LEA        EDX=>sel_col1,[ESP + 0x8]
    //         00437c3a     PUSH       EAX
    //         00437c3b     PUSH       EDX
    //         00437c3c     LEA        EAX=>local_4,[ESP + 0x1c]
    //         00437c40     LEA        EDX=>sel_row2,[ESP + 0x14]
    //         00437c44     PUSH       EAX
    //         00437c45     PUSH       EDX
    //         00437c46     CALL       RGE_View::get_selection_area                     int get_selection_area(RGE_View * this, long 
    //         00437c4b     TEST       EAX,EAX
    //         00437c4d     JZ         LAB_00437cae
    //                              diam_map.cpp:907 (19)
    //         00437c4f     MOV        this,dword ptr [EBX + 0x20]
    //         00437c52     PUSH       0x1
    //         00437c54     PUSH       s_diam_map::draw_selected_area                   = "diam_map::draw_selected_area"
    //         00437c59     CALL       TDrawArea::Lock                                  uchar * Lock(TDrawArea * this, char * param_1
    //         00437c5e     TEST       EAX,EAX
    //         00437c60     JZ         LAB_00437cae
    //                              diam_map.cpp:910 (22)
    //         00437c62     MOV        EAX,dword ptr [ESP + sel_row1]
    //         00437c66     PUSH       EDI
    //         00437c67     MOV        EDI,dword ptr [ESP + local_4]
    //         00437c6b     CMP        EDI,EAX
    //         00437c6d     JG         LAB_00437ca0
    //         00437c6f     MOV        EAX,dword ptr [ESP + sel_col1]
    //         00437c73     PUSH       ESI
    //         00437c74     MOV        ESI,dword ptr [ESP + sel_row2]
    //                               LAB_00437c78                                                 XREF[1]:     00437c9d(j)  
    //                              diam_map.cpp:912 (4)
    //         00437c78     CMP        ESI,EAX
    //         00437c7a     JG         LAB_00437c96
    //                               LAB_00437c7c                                                 XREF[1]:     00437c90(j)  
    //                              diam_map.cpp:913 (22)
    //         00437c7c     PUSH       0x0
    //         00437c7e     PUSH       0x1
    //         00437c80     PUSH       EDI
    //         00437c81     PUSH       ESI
    //         00437c82     MOV        this,EBX
    //         00437c84     CALL       RGE_Diamond_Map::draw_tile                       void draw_tile(RGE_Diamond_Map * this, short 
    //         00437c89     MOV        EAX,dword ptr [ESP + sel_col1]
    //         00437c8d     INC        ESI
    //         00437c8e     CMP        ESI,EAX
    //         00437c90     JLE        LAB_00437c7c
    //                              diam_map.cpp:912 (4)
    //         00437c92     MOV        ESI,dword ptr [ESP + sel_row2]
    //                               LAB_00437c96                                                 XREF[1]:     00437c7a(j)  
    //                              diam_map.cpp:910 (9)
    //         00437c96     MOV        this,dword ptr [ESP + sel_row1]
    //         00437c9a     INC        EDI
    //         00437c9b     CMP        EDI,this
    //         00437c9d     JLE        LAB_00437c78
    //                              diam_map.cpp:897 (1)
    //         00437c9f     POP        ESI
    //                               LAB_00437ca0                                                 XREF[1]:     00437c6d(j)  
    //                              diam_map.cpp:916 (14)
    //         00437ca0     MOV        this,dword ptr [EBX + 0x20]
    //         00437ca3     PUSH       s_diam_map::draw_selected_area                   = "diam_map::draw_selected_area"
    //         00437ca8     CALL       TDrawArea::Unlock                                void Unlock(TDrawArea * this, char * param_1)
    //         00437cad     POP        EDI
    //                               LAB_00437cae                                                 XREF[3]:     00437c2e(j), 00437c4d(j), 
    //                                                                                                         00437c60(j)  
    //                              diam_map.cpp:917 (5)
    //         00437cae     POP        EBX
    //         00437caf     ADD        ESP,0x10
    //         00437cb2     RET
}

// Offset: 0x00437CC0
void RGE_Diamond_Map_View::draw_objects() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * protected: virtual void __thiscall RGE_Diamond_Map::draw_objects(void)                                *
    //                              *********************************************************************************************************
    //                              void __thiscall draw_objects(RGE_Diamond_Map * this)
    //              void              <VOID>         <RETURN>
    //              RGE_Diamond_Ma    ECX:4 (auto)   this
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     00437d37(W)  
    //              short             Stack[-0x8]:2  i                         XREF[2]:     00437d59(W), 00437d61(R)  
    //              uchar             Stack[-0xc]:1  color1                    XREF[1]:     00437d5d(W)  
    //              uchar             Stack[-0x10]:1 color2
    //                               ?draw_objects@RGE_Diamond_Map@@MAEXXZ                        XREF[3]:     draw_objects:0052ca9f(c), 
    //                               RGE_Diamond_Map::draw_objects                                             0056f5ec(*), 005777cc(*)  
    //                              diam_map.cpp:923 (7)
    //         00437cc0     SUB        ESP,0xc
    //         00437cc3     PUSH       EBX
    //         00437cc4     PUSH       ESI
    //         00437cc5     MOV        ESI,this
    //                              diam_map.cpp:930 (27)
    //         00437cc7     MOV        EBX,0x1
    //         00437ccc     PUSH       EBX
    //         00437ccd     PUSH       s_diam_map::draw_objects                         = "diam_map::draw_objects"
    //         00437cd2     MOV        this,dword ptr [ESI + 0x20]
    //         00437cd5     CALL       TDrawArea::Lock                                  uchar * Lock(TDrawArea * this, char * param_1
    //         00437cda     TEST       EAX,EAX
    //         00437cdc     JZ         LAB_00437eac
    //                              diam_map.cpp:937 (25)
    //         00437ce2     MOV        EAX,dword ptr [ESI + 0xf4]
    //         00437ce8     MOV        dword ptr [ESI + 0x15c],EBX
    //         00437cee     PUSH       EDI
    //         00437cef     PUSH       EBP
    //         00437cf0     MOV        this,dword ptr [EAX + 0x40]
    //         00437cf3     MOV        EDX,dword ptr [this->_padding_]
    //         00437cf5     MOV        EAX,dword ptr [EDX + 0x28]
    //         00437cf8     MOV        EDI,dword ptr [EAX + 0x4]
    //                              diam_map.cpp:938 (4)
    //         00437cfb     TEST       EDI,EDI
    //         00437cfd     JZ         LAB_00437d21
    //                               LAB_00437cff                                                 XREF[1]:     00437d1f(j)  
    //                              diam_map.cpp:940 (2)
    //         00437cff     MOV        EAX,dword ptr [EDI]
    //                              diam_map.cpp:941 (4)
    //         00437d01     TEST       EAX,EAX
    //         00437d03     JZ         LAB_00437d1a
    //                              diam_map.cpp:942 (21)
    //         00437d05     MOV        EDX,dword ptr [ESI]
    //         00437d07     PUSH       0xff
    //         00437d0c     PUSH       offset DAT_fffffff8
    //         00437d11     PUSH       EAX=>DAT_fffffff4
    //         00437d12     MOV        this,ESI
    //         00437d14     CALL       dword ptr [EDX + 0xe8]
    //                               LAB_00437d1a                                                 XREF[1]:     00437d03(j)  
    //                              diam_map.cpp:943 (7)
    //         00437d1a     MOV        EDI,dword ptr [EDI + 0x4]
    //         00437d1d     TEST       EDI,EDI
    //         00437d1f     JNZ        LAB_00437cff
    //                               LAB_00437d21                                                 XREF[1]:     00437cfd(j)  
    //                              diam_map.cpp:952 (32)
    //         00437d21     MOV        EAX,dword ptr [ESI + 0xf4]
    //         00437d27     MOV        dword ptr [ESI + 0x15c],0x2
    //         00437d31     MOV        this,EBX
    //         00437d33     CMP        word ptr [EAX + 0x3c],BX
    //         00437d37     MOV        dword ptr [ESP + local_4],this
    //         00437d3b     JLE        LAB_00437dea
    //                               LAB_00437d41                                                 XREF[1]:     00437de4(j)  
    //                              diam_map.cpp:954 (9)
    //         00437d41     MOV        EDX,dword ptr [EAX + 0x40]
    //         00437d44     MOVSX      this,this
    //         00437d47     MOV        EBP,dword ptr [EDX + this->_padding_*0x4]
    //                              diam_map.cpp:955 (6)
    //         00437d4a     MOV        EAX,dword ptr [EBP + 0x108]
    //                              diam_map.cpp:960 (17)
    //         00437d50     MOV        this,dword ptr [EBP + 0x30]
    //         00437d53     MOV        AL,byte ptr [EAX + 0x25]
    //         00437d56     MOV        EDI,dword ptr [ECX + this->_padding_]
    //         00437d59     MOV        byte ptr [ESP + i],AL
    //         00437d5d     MOV        byte ptr [ESP + color1],AL
    //                              diam_map.cpp:961 (8)
    //         00437d61     MOV        EBX,dword ptr [ESP + i]
    //         00437d65     TEST       EDI,EDI
    //         00437d67     JZ         LAB_00437d87
    //                               LAB_00437d69                                                 XREF[1]:     00437d85(j)  
    //                              diam_map.cpp:963 (2)
    //         00437d69     MOV        EAX,dword ptr [EDI]
    //                              diam_map.cpp:964 (4)
    //         00437d6b     TEST       EAX,EAX
    //         00437d6d     JZ         LAB_00437d80
    //                              diam_map.cpp:965 (17)
    //         00437d6f     MOV        this,dword ptr [ESP + 0x10]
    //         00437d73     MOV        EDX,dword ptr [ESI]
    //         00437d75     PUSH       this
    //         00437d76     PUSH       EBX=>DAT_fffffff8
    //         00437d77     PUSH       EAX=>DAT_fffffff4
    //         00437d78     MOV        this,ESI
    //         00437d7a     CALL       dword ptr [EDX + 0xe8]
    //                               LAB_00437d80                                                 XREF[1]:     00437d6d(j)  
    //                              diam_map.cpp:966 (7)
    //         00437d80     MOV        EDI,dword ptr [EDI + 0x4]
    //         00437d83     TEST       EDI,EDI
    //         00437d85     JNZ        LAB_00437d69
    //                               LAB_00437d87                                                 XREF[1]:     00437d67(j)  
    //                              diam_map.cpp:971 (6)
    //         00437d87     MOV        EDX,dword ptr [EBP + 0x28]
    //         00437d8a     MOV        EBP,dword ptr [EDX + 0x4]
    //                              diam_map.cpp:972 (4)
    //         00437d8d     TEST       EBP,EBP
    //         00437d8f     JZ         LAB_00437dd1
    //                               LAB_00437d91                                                 XREF[1]:     00437dcf(j)  
    //                              diam_map.cpp:974 (3)
    //         00437d91     MOV        EDI,dword ptr [EBP]
    //                              diam_map.cpp:975 (37)
    //         00437d94     TEST       EDI,EDI
    //         00437d96     JZ         LAB_00437dca
    //         00437d98     TEST       byte ptr [EDI + 0x36],0x1
    //         00437d9c     JNZ        LAB_00437dca
    //         00437d9e     MOV        EAX,dword ptr [EDI + 0xc]
    //         00437da1     MOV        this,dword ptr [ESI + 0xf8]
    //         00437da7     CMP        EAX,this
    //         00437da9     JNZ        LAB_00437db9
    //         00437dab     MOV        EDX,dword ptr [EDI]
    //         00437dad     MOV        this,EDI
    //         00437daf     CALL       dword ptr [EDX + 0xe8]
    //         00437db5     TEST       AL,AL
    //         00437db7     JNZ        LAB_00437dca
    //                               LAB_00437db9                                                 XREF[1]:     00437da9(j)  
    //                              diam_map.cpp:976 (17)
    //         00437db9     MOV        this,dword ptr [ESP + 0x10]
    //         00437dbd     MOV        EAX,dword ptr [ESI]
    //         00437dbf     PUSH       this
    //         00437dc0     PUSH       EBX=>DAT_fffffff8
    //         00437dc1     PUSH       EDI=>DAT_fffffff4
    //         00437dc2     MOV        this,ESI
    //         00437dc4     CALL       dword ptr [EAX + 0xe8]
    //                               LAB_00437dca                                                 XREF[3]:     00437d96(j), 00437d9c(j), 
    //                                                                                                         00437db7(j)  
    //                              diam_map.cpp:977 (7)
    //         00437dca     MOV        EBP,dword ptr [EBP + 0x4]
    //         00437dcd     TEST       EBP,EBP
    //         00437dcf     JNZ        LAB_00437d91
    //                               LAB_00437dd1                                                 XREF[1]:     00437d8f(j)  
    //                              diam_map.cpp:952 (25)
    //         00437dd1     MOV        this,dword ptr [ESP + 0x18]
    //         00437dd5     MOV        EAX,dword ptr [ESI + 0xf4]
    //         00437ddb     INC        this
    //         00437ddc     CMP        this,word ptr [EAX + 0x3c]
    //         00437de0     MOV        dword ptr [ESP + 0x18],this
    //         00437de4     JL         LAB_00437d41
    //                               LAB_00437dea                                                 XREF[1]:     00437d3b(j)  
    //                              diam_map.cpp:984 (16)
    //         00437dea     MOV        EDX,dword ptr [ESI + 0xf8]
    //         00437df0     CMP        word ptr [EDX + 0x19c],0x0
    //         00437df8     JLE        LAB_00437e42
    //                              diam_map.cpp:987 (29)
    //         00437dfa     XOR        EDI,EDI
    //         00437dfc     MOV        dword ptr [ESI + 0x15c],0x3
    //         00437e06     XOR        EBX,EBX
    //                               LAB_00437e08                                                 XREF[1]:     00437e40(j)  
    //         00437e08     MOV        EAX,dword ptr [ESI + 0xf8]
    //         00437e0e     CMP        BX,word ptr [EAX + 0x19c]
    //         00437e15     JGE        LAB_00437e42
    //                              diam_map.cpp:989 (10)
    //         00437e17     MOVSX      this,DI
    //         00437e1a     MOV        EAX,dword ptr [EAX + this->_padding_*0x4 + 0x1
    //                              diam_map.cpp:990 (4)
    //         00437e21     TEST       EAX,EAX
    //         00437e23     JZ         LAB_00437e3b
    //                              diam_map.cpp:992 (21)
    //         00437e25     MOV        EDX,dword ptr [ESI]
    //         00437e27     PUSH       0xff
    //         00437e2c     PUSH       offset DAT_fffffff8
    //         00437e31     PUSH       EAX=>DAT_fffffff4
    //         00437e32     MOV        this,ESI
    //         00437e34     CALL       dword ptr [EDX + 0xe8]
    //                              diam_map.cpp:993 (8)
    //         00437e3a     INC        EBX
    //                               LAB_00437e3b                                                 XREF[1]:     00437e23(j)  
    //         00437e3b     INC        EDI
    //         00437e3c     CMP        DI,0x19
    //         00437e40     JL         LAB_00437e08
    //                               LAB_00437e42                                                 XREF[2]:     00437df8(j), 00437e15(j)  
    //                              diam_map.cpp:1002 (16)
    //         00437e42     MOV        EAX,dword ptr [ESI + 0xf8]
    //         00437e48     MOV        dword ptr [ESI + 0x15c],0x4
    //                              diam_map.cpp:1004 (15)
    //         00437e52     MOV        EDX,dword ptr [EAX + 0x28]
    //         00437e55     MOV        this,dword ptr [EAX + 0x108]
    //         00437e5b     MOV        EBX,dword ptr [EDX + 0x4]
    //         00437e5e     MOV        this,byte ptr [ECX + this+0x25]
    //                              diam_map.cpp:1005 (16)
    //         00437e61     TEST       EBX,EBX
    //         00437e63     MOV        byte ptr [ESP + 0x14],this
    //         00437e67     MOV        byte ptr [ESP + 0x10],this
    //         00437e6b     JZ         LAB_00437e9d
    //         00437e6d     MOV        EBP,dword ptr [ESP + 0x14]
    //                               LAB_00437e71                                                 XREF[1]:     00437e9b(j)  
    //                              diam_map.cpp:1007 (2)
    //         00437e71     MOV        EDI,dword ptr [EBX]
    //                              diam_map.cpp:1008 (18)
    //         00437e73     TEST       EDI,EDI
    //         00437e75     JZ         LAB_00437e96
    //         00437e77     MOV        EAX,dword ptr [EDI]
    //         00437e79     MOV        this,EDI
    //         00437e7b     CALL       dword ptr [EAX + 0xe8]
    //         00437e81     TEST       AL,AL
    //         00437e83     JZ         LAB_00437e96
    //                              diam_map.cpp:1009 (17)
    //         00437e85     MOV        EAX,dword ptr [ESP + 0x10]
    //         00437e89     MOV        EDX,dword ptr [ESI]
    //         00437e8b     PUSH       EAX
    //         00437e8c     PUSH       EBP=>DAT_fffffff8
    //         00437e8d     PUSH       EDI=>DAT_fffffff4
    //         00437e8e     MOV        this,ESI
    //         00437e90     CALL       dword ptr [EDX + 0xe8]
    //                               LAB_00437e96                                                 XREF[2]:     00437e75(j), 00437e83(j)  
    //                              diam_map.cpp:1010 (7)
    //         00437e96     MOV        EBX,dword ptr [EBX + 0x4]
    //         00437e99     TEST       EBX,EBX
    //         00437e9b     JNZ        LAB_00437e71
    //                               LAB_00437e9d                                                 XREF[1]:     00437e6b(j)  
    //                              diam_map.cpp:1014 (15)
    //         00437e9d     MOV        this,dword ptr [ESI + 0x20]
    //         00437ea0     PUSH       s_diam_map::draw_objects                         = "diam_map::draw_objects"
    //         00437ea5     CALL       TDrawArea::Unlock                                void Unlock(TDrawArea * this, char * param_1)
    //         00437eaa     POP        EBP
    //         00437eab     POP        EDI
    //                               LAB_00437eac                                                 XREF[1]:     00437cdc(j)  
    //                              diam_map.cpp:1015 (6)
    //         00437eac     POP        ESI
    //         00437ead     POP        EBX
    //         00437eae     ADD        ESP,0xc
    //         00437eb1     RET
}

// Offset: 0x00437EC0
void RGE_Diamond_Map_View::draw_visible_object(RGE_Static_Object* param_1, uchar param_2, uchar param_3) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * protected: virtual void __thiscall RGE_Diamond_Map::draw_visible_object(class RGE_Static_Object *,... *
    //                              *********************************************************************************************************
    //                              void __thiscall draw_visible_object(RGE_Diamond_Map * this, RGE_Stat
    //              void              <VOID>         <RETURN>
    //              RGE_Diamond_Ma    ECX:4 (auto)   this
    //              RGE_Static_Obj    Stack[0x4]:4   param_1                   XREF[5]:     00437ec4(R), 00437ee1(W), 00437f17(R), 0043800f(R), 
    //                                                                                     00438037(R)  
    //              uchar             Stack[0x8]:1   param_2                   XREF[1]:     00437fe5(R)  
    //              uchar             Stack[0xc]:1   param_3                   XREF[1]:     00437fef(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[3]:     00437ef2(W), 00438005(R), 00438033(R)  
    //              short             Stack[-0x8]:2  row
    //                               ?draw_visible_object@RGE_Diamond_Map@@MAEXPAVRGE_Static_Obj  XREF[3]:     0056f5f0(*), 00577438(*), 
    //                               RGE_Diamond_Map::draw_visible_object                                      005777d0(*)  
    //                              diam_map.cpp:1021 (4)
    //         00437ec0     PUSH       this
    //         00437ec1     PUSH       EBX
    //         00437ec2     PUSH       EBP
    //         00437ec3     PUSH       ESI
    //                              diam_map.cpp:1029 (18)
    //         00437ec4     MOV        ESI,dword ptr [ESP + param_1]
    //         00437ec8     PUSH       EDI
    //         00437ec9     MOV        EBX,this
    //         00437ecb     MOV        EAX,dword ptr [ESI + 0x1c]
    //         00437ece     TEST       EAX,EAX
    //         00437ed0     JZ         switchD_00437ffe::caseD_0
    //                              diam_map.cpp:1032 (8)
    //         00437ed6     FLD        float ptr [ESI + 0x38]
    //         00437ed9     CALL       __ftol                                           undefined __ftol()
    //                              diam_map.cpp:1033 (12)
    //         00437ede     FLD        float ptr [ESI + 0x3c]
    //         00437ee1     MOV        dword ptr [ESP + param_1],EAX
    //         00437ee5     CALL       __ftol                                           undefined __ftol()
    //                              diam_map.cpp:1035 (17)
    //         00437eea     MOV        EDI,dword ptr [EBX + 0xf8]
    //         00437ef0     MOV        this,EAX
    //         00437ef2     MOV        dword ptr [ESP + local_4],this
    //         00437ef6     MOV        EAX,dword ptr [EDI + 0x38]
    //         00437ef9     TEST       EAX,EAX
    //                              diam_map.cpp:1037 (26)
    //         00437efb     JZ         LAB_00437f58
    //         00437efd     MOV        EBP,dword ptr [EBX + 0xfc]
    //         00437f03     MOV        AL,byte ptr [EBP + 0x8db8]
    //         00437f09     TEST       AL,AL
    //         00437f0b     JZ         LAB_00437f17
    //         00437f0d     MOV        DL,byte ptr [EBP + 0x8db9]
    //         00437f13     TEST       DL,DL
    //                              diam_map.cpp:1039 (2)
    //         00437f15     JZ         LAB_00437f58
    //                               LAB_00437f17                                                 XREF[1]:     00437f0b(j)  
    //                              diam_map.cpp:1041 (18)
    //         00437f17     MOVSX      EDX,word ptr [ESP + param_1]
    //         00437f1c     MOVSX      this,this
    //         00437f1f     MOV        this,dword ptr [this->_padding_*0x4 + unified_   = 00000000
    //         00437f26     MOV        EDX,dword ptr [this->_padding_ + EDX*0x4]
    //                              diam_map.cpp:1045 (2)
    //         00437f29     XOR        this,this
    //                              diam_map.cpp:1047 (8)
    //         00437f2b     TEST       dword ptr [EDI + 0xd0],EDX
    //         00437f31     JZ         LAB_00437f35
    //                              diam_map.cpp:1048 (2)
    //         00437f33     MOV        this,0x80
    //                               LAB_00437f35                                                 XREF[1]:     00437f31(j)  
    //                              diam_map.cpp:1050 (8)
    //         00437f35     TEST       dword ptr [EDI + 0xd4],EDX
    //         00437f3b     JZ         LAB_00437f3f
    //                              diam_map.cpp:1051 (2)
    //         00437f3d     MOV        this,0xf
    //                               LAB_00437f3f                                                 XREF[1]:     00437f3b(j)  
    //                              diam_map.cpp:1053 (8)
    //         00437f3f     TEST       AL,AL
    //         00437f41     JZ         LAB_00437f49
    //         00437f43     TEST       this,this
    //         00437f45     JNZ        LAB_00437f49
    //                              diam_map.cpp:1054 (2)
    //         00437f47     MOV        this,0x80
    //                               LAB_00437f49                                                 XREF[2]:     00437f41(j), 00437f45(j)  
    //                              diam_map.cpp:1056 (15)
    //         00437f49     MOV        AL,byte ptr [EBP + 0x8db9]
    //         00437f4f     TEST       AL,AL
    //         00437f51     JNZ        LAB_00437f5a
    //         00437f53     CMP        this,0x80
    //         00437f56     JNZ        LAB_00437f5a
    //                               LAB_00437f58                                                 XREF[2]:     00437efb(j), 00437f15(j)  
    //                              diam_map.cpp:1057 (2)
    //         00437f58     MOV        this,0xf
    //                               LAB_00437f5a                                                 XREF[2]:     00437f51(j), 00437f56(j)  
    //                              diam_map.cpp:1061 (28)
    //         00437f5a     CMP        this,0xf
    //         00437f5d     JZ         LAB_00437f76
    //         00437f5f     CMP        this,0x80
    //         00437f62     JNZ        switchD_00437ffe::caseD_0
    //         00437f68     MOV        EDX,dword ptr [ESI + 0x8]
    //         00437f6b     MOV        AL,byte ptr [EDX + 0x65]
    //         00437f6e     TEST       AL,AL
    //         00437f70     JZ         switchD_00437ffe::caseD_0
    //                               LAB_00437f76                                                 XREF[1]:     00437f5d(j)  
    //                              diam_map.cpp:1065 (6)
    //         00437f76     CMP        byte ptr [ESI + 0x4e],0x19
    //         00437f7a     JNZ        LAB_00437fc7
    //                              diam_map.cpp:1067 (9)
    //         00437f7c     CMP        this,0xf
    //         00437f7f     JZ         switchD_00437ffe::caseD_0
    //                              diam_map.cpp:1069 (33)
    //         00437f85     MOV        EAX,dword ptr [ESI + 0xc]
    //         00437f88     MOVSX      this,word ptr [EAX + 0x4a]
    //         00437f8c     CMP        dword ptr [EDI + this->_padding_*0x4 + 0xac],0x1
    //         00437f94     JNZ        LAB_00437fbc
    //         00437f96     MOV        EDX,dword ptr [ESI + 0xa4]
    //         00437f9c     MOV        EAX,dword ptr [EBX + 0x160]
    //         00437fa2     TEST       EAX,EDX
    //         00437fa4     JNZ        LAB_00437fbc
    //                              diam_map.cpp:1071 (2)
    //         00437fa6     XOR        EAX,EAX
    //                              diam_map.cpp:1072 (16)
    //         00437fa8     XOR        this,this
    //         00437faa     MOV        AL,byte ptr [ESI + 0xa8]
    //         00437fb0     MOV        this,byte ptr [ESI + 0xa9]
    //         00437fb6     MOV        EDI,EAX
    //                              diam_map.cpp:1073 (2)
    //         00437fb8     MOV        EDX,this
    //                              diam_map.cpp:1075 (2)
    //         00437fba     JMP        LAB_00437ff9
    //                               LAB_00437fbc                                                 XREF[2]:     00437f94(j), 00437fa4(j)  
    //                              diam_map.cpp:1078 (7)
    //         00437fbc     MOV        this,0xff
    //         00437fc1     XOR        EDI,EDI
    //                              diam_map.cpp:1079 (2)
    //         00437fc3     MOV        EDX,this
    //                              diam_map.cpp:1082 (2)
    //         00437fc5     JMP        LAB_00437ff9
    //                               LAB_00437fc7                                                 XREF[1]:     00437f7a(j)  
    //                              diam_map.cpp:1084 (13)
    //         00437fc7     MOV        this,dword ptr [ESI + 0x8]
    //         00437fca     XOR        EDX,EDX
    //         00437fcc     MOV        DL,byte ptr [ECX + this+0x8e]
    //         00437fd2     MOV        EDI,EDX
    //                              diam_map.cpp:1085 (5)
    //         00437fd4     CMP        EDI,0x3
    //         00437fd7     JNZ        LAB_00437fe5
    //                              diam_map.cpp:1087 (10)
    //         00437fd9     XOR        EAX,EAX
    //         00437fdb     MOV        AL,byte ptr [ECX + this->_padding_]
    //         00437fe1     MOV        this,EAX
    //                              diam_map.cpp:1090 (2)
    //         00437fe3     JMP        LAB_00437fef
    //                               LAB_00437fe5                                                 XREF[1]:     00437fd7(j)  
    //                              diam_map.cpp:1092 (10)
    //         00437fe5     MOV        this,dword ptr [ESP + param_2]
    //         00437fe9     AND        this,0xff
    //                               LAB_00437fef                                                 XREF[1]:     00437fe3(j)  
    //                              diam_map.cpp:1093 (10)
    //         00437fef     MOV        EDX,dword ptr [ESP + param_3]
    //         00437ff3     AND        EDX,0xff
    //                               LAB_00437ff9                                                 XREF[2]:     00437fba(j), 00437fc5(j)  
    //                              diam_map.cpp:1097 (12)
    //         00437ff9     CMP        EDI,0x3
    //         00437ffc     JA         switchD_00437ffe::caseD_0
    //                               switchD_00437ffe::switchD
    //         00437ffe     JMP        dword ptr [EDI*0x4 + ->switchD_00437ffe::caseD   = 00438045
    //                               switchD_00437ffe::caseD_2                                    XREF[2]:     00437ffe(j), 00438058(*)  
    //                              diam_map.cpp:1100 (24)
    //         00438005     MOV        EAX,dword ptr [ESP + local_4]
    //         00438009     MOV        EDX,dword ptr [EBX]
    //         0043800b     PUSH       ESI
    //         0043800c     PUSH       0x2
    //         0043800e     PUSH       this
    //         0043800f     MOV        this,dword ptr [ESP + param_1]
    //         00438013     PUSH       EAX
    //         00438014     PUSH       this
    //         00438015     MOV        this,EBX
    //         00438017     CALL       dword ptr [EDX + 0xec]
    //                              diam_map.cpp:1112 (8)
    //         0043801d     POP        EDI
    //         0043801e     POP        ESI
    //         0043801f     POP        EBP
    //         00438020     POP        EBX
    //         00438021     POP        this
    //         00438022     RET        0xc
    //                               switchD_00437ffe::caseD_1                                    XREF[2]:     00437ffe(j), 00438054(*)  
    //                              diam_map.cpp:1103 (6)
    //         00438025     MOV        EAX,dword ptr [EBX]
    //         00438027     PUSH       ESI
    //         00438028     PUSH       0x1
    //         0043802a     PUSH       EDX
    //                              diam_map.cpp:1104 (2)
    //         0043802b     JMP        LAB_00438033
    //                               switchD_00437ffe::caseD_3                                    XREF[2]:     00437ffe(j), 0043805c(*)  
    //                              diam_map.cpp:1106 (24)
    //         0043802d     MOV        EAX,dword ptr [EBX]
    //         0043802f     PUSH       ESI
    //         00438030     PUSH       0x2
    //         00438032     PUSH       this
    //                               LAB_00438033                                                 XREF[1]:     0043802b(j)  
    //         00438033     MOV        this,dword ptr [ESP + local_4]
    //         00438037     MOV        EDX,dword ptr [ESP + param_1]
    //         0043803b     PUSH       this
    //         0043803c     PUSH       EDX
    //         0043803d     MOV        this,EBX
    //         0043803f     CALL       dword ptr [EAX + 0xec]
    //                               switchD_00437ffe::caseD_0                                    XREF[7]:     00437ed0(j), 00437f62(j), 
    //                                                                                                         00437f70(j), 00437f7f(j), 
    //                                                                                                         00437ffc(j), 00437ffe(j), 
    //                                                                                                         00438050(*)  
    //                              diam_map.cpp:1112 (27)
    //         00438045     POP        EDI
    //         00438046     POP        ESI
    //         00438047     POP        EBP
    //         00438048     POP        EBX
    //         00438049     POP        this
    //         0043804a     RET        0xc
}

// Offset: 0x0043804D
undefined FUN_0043804d() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0043804d()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0043804d
    //         0043804d     NOP
    //         0043804e     MOV        EDI,EDI
    //                              Symbol Ref: No symbol: NONAME
    //                               switchD_00437ffe::switchdataD_00438050                       XREF[1]:     draw_visible_object:00437ffe(R)  
}

// Offset: 0x00438060
void RGE_Diamond_Map_View::draw_object(short param_1, short param_2, uchar param_3, short param_4, RGE_Static_Object* param_5) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * protected: virtual void __thiscall RGE_Diamond_Map::draw_object(short,short,unsigned char,short,cl... *
    //                              *********************************************************************************************************
    //                              void __thiscall draw_object(RGE_Diamond_Map * this, short param_1, s
    //              void              <VOID>         <RETURN>
    //              RGE_Diamond_Ma    ECX:4 (auto)   this
    //              short             Stack[0x4]:2   param_1                   XREF[1]:     00438076(R)  
    //              short             Stack[0x8]:2   param_2                   XREF[5]:     00438065(R), 004380a6(W), 004380aa(R), 004380b6(W), 
    //                                                                                     004380ba(R)  
    //              uchar             Stack[0xc]:1   param_3                   XREF[4]:     004380f8(R), 00438124(R), 0043815f(R), 004381a3(R)  
    //              short             Stack[0x10]:2  param_4                   XREF[1]:     004380ed(R)  
    //              RGE_Static_Obj    Stack[0x14]:4  param_5
    //                               ?draw_object@RGE_Diamond_Map@@MAEXFFEFPAVRGE_Static_Object@  XREF[3]:     draw_object:0052cae4(c), 
    //                               RGE_Diamond_Map::draw_object                                              0056f5f4(*), 005777d4(*)  
    //                              diam_map.cpp:1118 (5)
    //         00438060     PUSH       EBX
    //         00438061     PUSH       EBP
    //         00438062     PUSH       ESI
    //         00438063     MOV        ESI,this
    //                              diam_map.cpp:1126 (32)
    //         00438065     MOV        this,dword ptr [ESP + param_2]
    //         00438069     PUSH       EDI
    //         0043806a     MOVSX      EAX,word ptr [ESI + 0x130]
    //         00438071     MOVSX      EDX,this
    //         00438074     ADD        EAX,EDX
    //         00438076     MOV        EDX,dword ptr [ESP + param_1]
    //         0043807a     MOVSX      EDI,DX
    //         0043807d     SUB        EAX,EDI
    //         0043807f     MOV        EDI,dword ptr [ESI + 0x12c]
    //                              diam_map.cpp:1129 (12)
    //         00438085     CMP        DX,this
    //         00438088     LEA        EAX,[EAX + EAX*0x8]
    //         0043808b     LEA        EDI,[EDI + EAX*0x4 + -0x24]
    //         0043808f     JGE        LAB_00438093
    //                              diam_map.cpp:1130 (2)
    //         00438091     MOV        this,EDX
    //                               LAB_00438093                                                 XREF[1]:     0043808f(j)  
    //                              diam_map.cpp:1133 (16)
    //         00438093     FLD        float ptr [EDI + 0x20]
    //         00438096     FCOMP      float ptr [DAT_0056f604]
    //         0043809c     FNSTSW     AX
    //         0043809e     TEST       AH,0x1
    //         004380a1     JZ         LAB_004380b3
    //                              diam_map.cpp:1134 (14)
    //         004380a3     MOVSX      this,this
    //         004380a6     MOV        dword ptr [ESP + param_2],this
    //         004380aa     FILD       dword ptr [ESP + param_2]
    //         004380ae     FMUL       float ptr [EDI + 0x20]
    //                              diam_map.cpp:1135 (2)
    //         004380b1     JMP        LAB_004380c1
    //                               LAB_004380b3                                                 XREF[1]:     004380a1(j)  
    //                              diam_map.cpp:1136 (19)
    //         004380b3     MOVSX      EDX,this
    //         004380b6     MOV        dword ptr [ESP + param_2],EDX
    //         004380ba     FILD       dword ptr [ESP + param_2]
    //         004380be     FMUL       float ptr [EDI + 0x18]
    //                               LAB_004380c1                                                 XREF[1]:     004380b1(j)  
    //         004380c1     CALL       __ftol                                           undefined __ftol()
    //                              diam_map.cpp:1140 (26)
    //         004380c6     MOV        DX,word ptr [EDI]
    //         004380c9     MOV        EDI,dword ptr [ESI + 0x128]
    //         004380cf     MOVSX      this,DX
    //         004380d2     LEA        this,[ECX + ECX*0x2]
    //         004380d5     MOV        this,word ptr [EDI + this->_padding_*0x2 + 0x2]
    //         004380da     ADD        this,word ptr [ESI + 0xc]
    //         004380de     ADD        this,EAX
    //                              diam_map.cpp:1141 (13)
    //         004380e0     MOV        AX,word ptr [ESI + 0x10]
    //         004380e4     ADD        AX,word ptr [ESI + 0x134]
    //         004380eb     ADD        EAX,EDX
    //                              diam_map.cpp:1172 (11)
    //         004380ed     MOV        DX,word ptr [ESP + param_4]
    //         004380f2     CMP        DX,0x1
    //         004380f6     JNZ        LAB_0043811e
    //                              diam_map.cpp:1173 (22)
    //         004380f8     MOV        EDX,dword ptr [ESP + param_3]
    //         004380fc     MOVSX      EAX,AX
    //         004380ff     MOVSX      this,this
    //         00438102     PUSH       EDX
    //         00438103     LEA        EDX,[EAX + 0x1]
    //         00438106     PUSH       EDX
    //         00438107     LEA        EDX,[ECX + this+0x1]
    //         0043810a     DEC        EAX
    //         0043810b     PUSH       EDX
    //         0043810c     DEC        this
    //         0043810d     PUSH       EAX
    //                              diam_map.cpp:1185 (9)
    //         0043810e     PUSH       this
    //         0043810f     MOV        this,dword ptr [ESI + 0x20]
    //         00438112     CALL       TDrawArea::FillRect                              void FillRect(TDrawArea * this, long param_1,
    //                              diam_map.cpp:1186 (7)
    //         00438117     POP        EDI
    //         00438118     POP        ESI
    //         00438119     POP        EBP
    //         0043811a     POP        EBX
    //         0043811b     RET        0x14
    //                               LAB_0043811e                                                 XREF[1]:     004380f6(j)  
    //                              diam_map.cpp:1174 (6)
    //         0043811e     CMP        DX,0x2
    //         00438122     JNZ        LAB_00438159
    //                              diam_map.cpp:1176 (29)
    //         00438124     MOV        EBP,dword ptr [ESP + param_3]
    //         00438128     MOVSX      EDI,AX
    //         0043812b     MOVSX      EBX,this
    //         0043812e     LEA        EAX,[EDI + 0x1]
    //         00438131     PUSH       EBP
    //         00438132     PUSH       EAX
    //         00438133     LEA        this,[EDI + -0x1]
    //         00438136     PUSH       EBX
    //         00438137     PUSH       this
    //         00438138     MOV        this,dword ptr [ESI + 0x20]
    //         0043813b     PUSH       EBX
    //         0043813c     CALL       TDrawArea::FillRect                              void FillRect(TDrawArea * this, long param_1,
    //                              diam_map.cpp:1185 (17)
    //         00438141     MOV        this,dword ptr [ESI + 0x20]
    //         00438144     PUSH       EBP
    //         00438145     LEA        EDX,[EBX + 0x1]
    //         00438148     PUSH       EDI
    //         00438149     PUSH       EDX
    //         0043814a     DEC        EBX
    //         0043814b     PUSH       EDI
    //         0043814c     PUSH       EBX
    //         0043814d     CALL       TDrawArea::FillRect                              void FillRect(TDrawArea * this, long param_1,
    //                              diam_map.cpp:1186 (7)
    //         00438152     POP        EDI
    //         00438153     POP        ESI
    //         00438154     POP        EBP
    //         00438155     POP        EBX
    //         00438156     RET        0x14
    //                               LAB_00438159                                                 XREF[1]:     00438122(j)  
    //                              diam_map.cpp:1179 (6)
    //         00438159     CMP        DX,0x3
    //         0043815d     JNZ        LAB_0043819d
    //                              diam_map.cpp:1181 (32)
    //         0043815f     MOV        EBP,dword ptr [ESP + param_3]
    //         00438163     MOVSX      EDI,AX
    //         00438166     MOVSX      EBX,this
    //         00438169     LEA        EAX,[EDI + 0x1]
    //         0043816c     PUSH       EBP
    //         0043816d     LEA        this,[EBX + 0x3]
    //         00438170     PUSH       EAX
    //         00438171     PUSH       this
    //         00438172     MOV        this,dword ptr [ESI + 0x20]
    //         00438175     LEA        EDX,[EBX + -0x3]
    //         00438178     PUSH       EDI
    //         00438179     PUSH       EDX
    //         0043817a     CALL       TDrawArea::FillRect                              void FillRect(TDrawArea * this, long param_1,
    //                              diam_map.cpp:1182 (10)
    //         0043817f     LEA        EAX,[EDI + 0x2]
    //         00438182     PUSH       EBP
    //         00438183     LEA        this,[EBX + 0x2]
    //         00438186     PUSH       EAX
    //         00438187     DEC        EDI
    //         00438188     PUSH       this
    //                              diam_map.cpp:1185 (13)
    //         00438189     MOV        this,dword ptr [ESI + 0x20]
    //         0043818c     ADD        EBX,-0x2
    //         0043818f     PUSH       EDI
    //         00438190     PUSH       EBX
    //         00438191     CALL       TDrawArea::FillRect                              void FillRect(TDrawArea * this, long param_1,
    //                              diam_map.cpp:1186 (7)
    //         00438196     POP        EDI
    //         00438197     POP        ESI
    //         00438198     POP        EBP
    //         00438199     POP        EBX
    //         0043819a     RET        0x14
    //                               LAB_0043819d                                                 XREF[1]:     0043815d(j)  
    //                              diam_map.cpp:1184 (6)
    //         0043819d     CMP        DX,0x4
    //         004381a1     JNZ        LAB_004381c6
    //                              diam_map.cpp:1185 (35)
    //         004381a3     MOV        EDX,dword ptr [ESP + param_3]
    //         004381a7     MOVSX      EAX,AX
    //         004381aa     MOVSX      this,this
    //         004381ad     PUSH       EDX
    //         004381ae     LEA        EDX,[EAX + 0x2]
    //         004381b1     PUSH       EDX
    //         004381b2     LEA        EDX,[ECX + this+0x2]
    //         004381b5     ADD        EAX,-0x2
    //         004381b8     PUSH       EDX
    //         004381b9     ADD        this,-0x2
    //         004381bc     PUSH       EAX
    //         004381bd     PUSH       this
    //         004381be     MOV        this,dword ptr [ESI + 0x20]
    //         004381c1     CALL       TDrawArea::FillRect                              void FillRect(TDrawArea * this, long param_1,
    //                               LAB_004381c6                                                 XREF[1]:     004381a1(j)  
    //                              diam_map.cpp:1186 (7)
    //         004381c6     POP        EDI
    //         004381c7     POP        ESI
    //         004381c8     POP        EBP
    //         004381c9     POP        EBX
    //         004381ca     RET        0x14
}

// Offset: 0x004381D0
void draw_clipped_horz_line(RGE_Diamond_Map* this_, short param_2, short param_3, short param_4, uchar param_5, RGE_Map_Image_Line* param_6) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * protected: void __thiscall RGE_Diamond_Map::draw_clipped_horz_line(short,short,short,unsigned char... *
    //                              *********************************************************************************************************
    //                              void __thiscall draw_clipped_horz_line(RGE_Diamond_Map * this, short
    //              void              <VOID>         <RETURN>
    //              RGE_Diamond_Ma    ECX:4 (auto)   this
    //              short             Stack[0x4]:2   param_1                   XREF[3]:     004381e4(R), 00438208(W), 00438239(R)  
    //              short             Stack[0x8]:2   param_2                   XREF[1]:     00438234(R)  
    //              short             Stack[0xc]:2   param_3                   XREF[1]:     004381fa(R)  
    //              uchar             Stack[0x10]:1  param_4                   XREF[1]:     00438228(R)  
    //              RGE_Map_Image_    Stack[0x14]:4  param_5                   XREF[3]:     004381d3(R), 004381ed(W), 00438220(R)  
    //                               ?draw_clipped_horz_line@RGE_Diamond_Map@@IAEXFFFEPAURGE_Map
    //                               RGE_Diamond_Map::draw_clipped_horz_line
    //                              diam_map.cpp:1192 (3)
    //         004381d0     PUSH       EBX
    //         004381d1     PUSH       EBP
    //         004381d2     PUSH       ESI
    //                              diam_map.cpp:1193 (32)
    //         004381d3     MOV        ESI,dword ptr [ESP + param_5]
    //         004381d7     PUSH       EDI
    //         004381d8     MOV        EDI,dword ptr [ECX + this->_padding_]
    //         004381db     MOV        AX,word ptr [ESI + 0x2]
    //         004381df     MOVSX      EDX,AX
    //         004381e2     ADD        EDI,EDX
    //         004381e4     MOV        EDX,dword ptr [ESP + param_1]
    //         004381e8     MOVSX      EBX,DX
    //         004381eb     CMP        EBX,EDI
    //         004381ed     MOV        dword ptr [ESP + param_5],EAX
    //         004381f1     JGE        LAB_004381fa
    //                              diam_map.cpp:1194 (7)
    //         004381f3     MOV        DX,word ptr [ECX + this->_padding_]
    //         004381f7     ADD        DX,AX
    //                               LAB_004381fa                                                 XREF[1]:     004381f1(j)  
    //                              diam_map.cpp:1196 (31)
    //         004381fa     MOV        EAX,dword ptr [ESP + param_3]
    //         004381fe     MOV        SI,word ptr [ESI + 0x4]
    //         00438202     MOVSX      EBX,DX
    //         00438205     MOVSX      EBP,AX
    //         00438208     MOV        dword ptr [ESP + param_1],EBX
    //         0043820c     LEA        EBX,[EBP + EBX*0x1 + -0x1]
    //         00438210     MOVSX      EBP,SI
    //         00438213     ADD        EBP,EDI
    //         00438215     CMP        EBX,EBP
    //         00438217     JL         LAB_00438228
    //                              diam_map.cpp:1197 (15)
    //         00438219     MOV        AX,word ptr [ECX + this->_padding_]
    //         0043821d     SUB        AX,DX
    //         00438220     MOV        EDX,dword ptr [ESP + param_5]
    //         00438224     ADD        EAX,ESI
    //         00438226     ADD        EAX,EDX
    //                               LAB_00438228                                                 XREF[1]:     00438217(j)  
    //                              diam_map.cpp:1199 (28)
    //         00438228     MOV        EDX,dword ptr [ESP + param_4]
    //         0043822c     MOV        this,dword ptr [ECX + this->_padding_]
    //         0043822f     MOVSX      EAX,AX
    //         00438232     PUSH       EDX
    //         00438233     PUSH       EAX
    //         00438234     MOVSX      EDX,word ptr [ESP + param_2]
    //         00438239     MOV        EAX,dword ptr [ESP + param_1]
    //         0043823d     PUSH       EDX
    //         0043823e     PUSH       EAX
    //         0043823f     CALL       TDrawArea::DrawHorzLine                          void DrawHorzLine(TDrawArea * this, long para
    //                              diam_map.cpp:1200 (7)
    //         00438244     POP        EDI
    //         00438245     POP        ESI
    //         00438246     POP        EBP
    //         00438247     POP        EBX
    //         00438248     RET        0x14
}

// Offset: 0x00438250
void RGE_Diamond_Map_View::draw_view_rect() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * protected: virtual void __thiscall RGE_Diamond_Map::draw_view_rect(void)                              *
    //                              *********************************************************************************************************
    //                              void __thiscall draw_view_rect(RGE_Diamond_Map * this)
    //              void              <VOID>         <RETURN>
    //              RGE_Diamond_Ma    ECX:4 (auto)   this
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[12]:    0043837a(W), 0043837e(R), 00438389(W), 0043838d(R), 
    //                                                                                     004383ac(W), 004383b0(R), 004383b4(W), 004383bc(R), 
    //                                                                                     004383d8(W), 004383dc(R), 004383f8(W), 004383fc(R)  
    //              undefined4        Stack[-0x8]:4  local_8                   XREF[3]:     0043827e(W), 004382f8(R), 0043840f(R)  
    //              short             Stack[-0xc]:2  row                       XREF[6]:     00438316(W), 0043831a(R), 00438326(W), 0043832a(R), 
    //                                                                                     00438361(*), 004383a7(R)  
    //              short             Stack[-0x10]:2 vhgt                      XREF[5]:     0043835b(*), 00438372(R), 004383b8(W), 004383c6(R), 
    //                                                                                     00438406(R)  
    //              short             Stack[-0x14]:2 vwid
    //                               ?draw_view_rect@RGE_Diamond_Map@@MAEXXZ                      XREF[3]:     0056f5f8(*), 00577440(*), 
    //                               RGE_Diamond_Map::draw_view_rect                                           005777d8(*)  
    //                              diam_map.cpp:1206 (9)
    //         00438250     SUB        ESP,0x10
    //         00438253     PUSH       EBX
    //         00438254     PUSH       EBP
    //         00438255     PUSH       ESI
    //         00438256     MOV        ESI,this
    //         00438258     PUSH       EDI
    //                              diam_map.cpp:1215 (17)
    //         00438259     MOV        EDI,dword ptr [ESI + 0xf8]
    //         0043825f     FLD        float ptr [EDI + 0x114]
    //         00438265     CALL       __ftol                                           undefined __ftol()
    //                              diam_map.cpp:1216 (13)
    //         0043826a     FLD        float ptr [EDI + 0x118]
    //         00438270     MOV        EBP,EAX
    //         00438272     CALL       __ftol                                           undefined __ftol()
    //                              diam_map.cpp:1219 (26)
    //         00438277     CMP        BP,word ptr [ESI + 0x14c]
    //         0043827e     MOV        dword ptr [ESP + local_8],EAX
    //         00438282     JNZ        LAB_00438291
    //         00438284     CMP        AX,word ptr [ESI + 0x14e]
    //         0043828b     JZ         LAB_00438428
    //                               LAB_00438291                                                 XREF[1]:     00438282(j)  
    //                              diam_map.cpp:1221 (50)
    //         00438291     TEST       BP,BP
    //         00438294     JL         LAB_00438524
    //         0043829a     MOV        this,dword ptr [ESI + 0xfc]
    //         004382a0     MOVSX      EDX,BP
    //         004382a3     CMP        EDX,dword ptr [ECX + this->_padding_]
    //         004382a6     JGE        LAB_00438524
    //         004382ac     TEST       AX,AX
    //         004382af     JL         LAB_00438524
    //         004382b5     MOV        EDX,dword ptr [ECX + this->_padding_]
    //         004382b8     MOVSX      EAX,AX
    //         004382bb     CMP        EAX,EDX
    //         004382bd     JGE        LAB_00438524
    //                              diam_map.cpp:1225 (53)
    //         004382c3     FLD        float ptr [EDI + 0x114]
    //         004382c9     MOVSX      EBX,word ptr [ESI + 0x130]
    //         004382d0     CALL       __ftol                                           undefined __ftol()
    //         004382d5     FLD        float ptr [EDI + 0x118]
    //         004382db     MOVSX      this,AX
    //         004382de     SUB        EBX,this
    //         004382e0     CALL       __ftol                                           undefined __ftol()
    //         004382e5     MOVSX      EDX,AX
    //         004382e8     MOV        this,dword ptr [ESI + 0x12c]
    //         004382ee     LEA        EAX,[EBX + EDX*0x1 + -0x1]
    //         004382f2     LEA        EAX,[EAX + EAX*0x8]
    //         004382f5     LEA        EDI,[this->_padding_ + EAX*0x4]
    //                              diam_map.cpp:1228 (9)
    //         004382f8     MOV        this,dword ptr [ESP + local_8]
    //         004382fc     CMP        BP,this
    //         004382ff     JGE        LAB_00438303
    //                              diam_map.cpp:1229 (2)
    //         00438301     MOV        this,EBP
    //                               LAB_00438303                                                 XREF[1]:     004382ff(j)  
    //                              diam_map.cpp:1232 (16)
    //         00438303     FLD        float ptr [EDI + 0x20]
    //         00438306     FCOMP      float ptr [DAT_0056f604]
    //         0043830c     FNSTSW     AX
    //         0043830e     TEST       AH,0x1
    //         00438311     JZ         LAB_00438323
    //                              diam_map.cpp:1233 (14)
    //         00438313     MOVSX      EDX,this
    //         00438316     MOV        dword ptr [ESP + row],EDX
    //         0043831a     FILD       dword ptr [ESP + row]
    //         0043831e     FMUL       float ptr [EDI + 0x20]
    //                              diam_map.cpp:1234 (2)
    //         00438321     JMP        LAB_00438331
    //                               LAB_00438323                                                 XREF[1]:     00438311(j)  
    //                              diam_map.cpp:1235 (19)
    //         00438323     MOVSX      EAX,this
    //         00438326     MOV        dword ptr [ESP + row],EAX
    //         0043832a     FILD       dword ptr [ESP + row]
    //         0043832e     FMUL       float ptr [EDI + 0x18]
    //                               LAB_00438331                                                 XREF[1]:     00438321(j)  
    //         00438331     CALL       __ftol                                           undefined __ftol()
    //                              diam_map.cpp:1239 (12)
    //         00438336     MOV        this,word ptr [EDI]
    //         00438339     MOV        EDI,dword ptr [ESI + 0x128]
    //         0043833f     MOVSX      EDX,this
    //                              diam_map.cpp:1240 (25)
    //         00438342     MOV        BX,word ptr [ESI + 0x10]
    //         00438346     ADD        BX,word ptr [ESI + 0x134]
    //         0043834d     LEA        EDX,[EDX + EDX*0x2]
    //         00438350     MOV        DI,word ptr [EDI + EDX*0x2 + 0x2]
    //         00438355     ADD        EBX,this
    //         00438357     ADD        DI,word ptr [ESI + 0xc]
    //                              diam_map.cpp:1263 (23)
    //         0043835b     LEA        this=>vhgt,[ESP + 0x10]
    //         0043835f     ADD        EDI,EAX
    //         00438361     LEA        EAX=>row,[ESP + 0x14]
    //         00438365     PUSH       EAX
    //         00438366     PUSH       this
    //         00438367     MOV        this,dword ptr [ESI + 0x150]
    //         0043836d     CALL       RGE_View::get_max_size                           void get_max_size(RGE_View * this, short * pa
    //                              diam_map.cpp:1264 (50)
    //         00438372     MOVSX      EAX,word ptr [ESP + vhgt]
    //         00438377     MOVSX      EDX,DI
    //         0043837a     MOV        dword ptr [ESP + local_4],EDX
    //         0043837e     FILD       dword ptr [ESP + local_4]
    //         00438382     CDQ
    //         00438383     SUB        EAX,EDX
    //         00438385     MOV        EDI,EAX
    //         00438387     SAR        EDI,0x1
    //         00438389     MOV        dword ptr [ESP + local_4],EDI
    //         0043838d     FILD       dword ptr [ESP + local_4]
    //         00438391     FMUL       float ptr [ESI + 0x140]
    //         00438397     FSUBR      ST0,ST1
    //         00438399     CALL       __ftol                                           undefined __ftol()
    //         0043839e     MOV        dword ptr [ESI + 0x114],EAX
    //                              diam_map.cpp:1265 (43)
    //         004383a4     MOVSX      EAX,BX
    //         004383a7     MOVSX      EBX,word ptr [ESP + row]
    //         004383ac     MOV        dword ptr [ESP + local_4],EAX
    //         004383b0     FILD       dword ptr [ESP + local_4]
    //         004383b4     MOV        dword ptr [ESP + local_4],EBX
    //         004383b8     FSTP       float ptr [ESP + vhgt]
    //         004383bc     FILD       dword ptr [ESP + local_4]
    //         004383c0     FMUL       float ptr [ESI + 0x144]
    //         004383c6     FSUBR      float ptr [ESP + vhgt]
    //         004383ca     CALL       __ftol                                           undefined __ftol()
    //                              diam_map.cpp:1266 (30)
    //         004383cf     ADD        EDI,0x2
    //         004383d2     MOV        dword ptr [ESI + 0x118],EAX
    //         004383d8     MOV        dword ptr [ESP + local_4],EDI
    //         004383dc     FILD       dword ptr [ESP + local_4]
    //         004383e0     FMUL       float ptr [ESI + 0x140]
    //         004383e6     FADD       ST0,ST1
    //         004383e8     CALL       __ftol                                           undefined __ftol()
    //                              diam_map.cpp:1267 (34)
    //         004383ed     ADD        EBX,0x4
    //         004383f0     MOV        dword ptr [ESI + 0x11c],EAX
    //         004383f6     FSTP       ST0
    //         004383f8     MOV        dword ptr [ESP + local_4],EBX
    //         004383fc     FILD       dword ptr [ESP + local_4]
    //         00438400     FMUL       float ptr [ESI + 0x144]
    //         00438406     FADD       float ptr [ESP + vhgt]
    //         0043840a     CALL       __ftol                                           undefined __ftol()
    //                              diam_map.cpp:1271 (25)
    //         0043840f     MOV        this,word ptr [ESP + local_8]
    //         00438414     MOV        dword ptr [ESI + 0x120],EAX
    //         0043841a     MOV        word ptr [ESI + 0x14c],BP
    //         00438421     MOV        word ptr [ESI + 0x14e],this
    //                               LAB_00438428                                                 XREF[1]:     0043828b(j)  
    //                              diam_map.cpp:1283 (20)
    //         00438428     MOV        EBX,dword ptr [ESI + 0x118]
    //         0043842e     MOV        EDX,dword ptr [ESI + 0x120]
    //         00438434     CMP        EBX,EDX
    //         00438436     JG         LAB_00438524
    //                               LAB_0043843c                                                 XREF[1]:     0043851e(j)  
    //                              diam_map.cpp:1285 (40)
    //         0043843c     MOVSX      this,word ptr [ESI + 0x134]
    //         00438443     MOV        EDI,dword ptr [ESI + 0x10]
    //         00438446     LEA        EAX,[EDI + this->_padding_*0x1]
    //         00438449     CMP        EBX,EAX
    //         0043844b     JL         LAB_00438515
    //         00438451     MOVSX      EBP,word ptr [ESI + 0x138]
    //         00438458     LEA        EAX,[EBP + EAX*0x1 + -0x1]
    //         0043845c     CMP        EBX,EAX
    //         0043845e     JG         LAB_00438515
    //                              diam_map.cpp:1287 (6)
    //         00438464     MOV        EAX,EBX
    //         00438466     SUB        EAX,this
    //         00438468     SUB        EAX,EDI
    //                              diam_map.cpp:1289 (18)
    //         0043846a     MOV        EDI,dword ptr [ESI + 0x11c]
    //         00438470     LEA        this,[EAX + EAX*0x2]
    //         00438473     MOV        EAX,dword ptr [ESI + 0x128]
    //         00438479     LEA        EBP,[EAX + this->_padding_*0x2]
    //                              diam_map.cpp:1290 (20)
    //         0043847c     MOV        this,dword ptr [ESI + 0x118]
    //         00438482     MOV        EAX,dword ptr [ESI + 0x114]
    //         00438488     CMP        EBX,this
    //         0043848a     JZ         LAB_004384de
    //         0043848c     CMP        EBX,EDX
    //         0043848e     JZ         LAB_004384de
    //                              diam_map.cpp:1303 (23)
    //         00438490     MOVSX      this,word ptr [EBP + 0x2]
    //         00438494     MOV        EDX,dword ptr [ESI + 0xc]
    //         00438497     ADD        this,EDX
    //         00438499     MOVSX      EDX,word ptr [EBP + 0x4]
    //         0043849d     ADD        EDX,this
    //         0043849f     CMP        EAX,EDX
    //         004384a1     JGE        LAB_004384b6
    //         004384a3     CMP        EAX,this
    //         004384a5     JL         LAB_004384b6
    //                              diam_map.cpp:1304 (15)
    //         004384a7     MOV        this,dword ptr [ESI + 0x20]
    //         004384aa     PUSH       0xff
    //         004384af     PUSH       EBX
    //         004384b0     PUSH       EAX
    //         004384b1     CALL       TDrawArea::SetPixel                              void SetPixel(TDrawArea * this, long param_1,
    //                               LAB_004384b6                                                 XREF[2]:     004384a1(j), 004384a5(j)  
    //                              diam_map.cpp:1305 (23)
    //         004384b6     MOVSX      EAX,word ptr [EBP + 0x2]
    //         004384ba     MOV        this,dword ptr [ESI + 0xc]
    //         004384bd     MOVSX      EDX,word ptr [EBP + 0x4]
    //         004384c1     ADD        EAX,this
    //         004384c3     ADD        EDX,EAX
    //         004384c5     CMP        EDI,EDX
    //         004384c7     JGE        LAB_00438515
    //         004384c9     CMP        EDI,EAX
    //         004384cb     JL         LAB_00438515
    //                              diam_map.cpp:1306 (17)
    //         004384cd     MOV        this,dword ptr [ESI + 0x20]
    //         004384d0     PUSH       0xff
    //         004384d5     PUSH       EBX
    //         004384d6     PUSH       EDI
    //         004384d7     CALL       TDrawArea::SetPixel                              void SetPixel(TDrawArea * this, long param_1,
    //         004384dc     JMP        LAB_00438515
    //                               LAB_004384de                                                 XREF[2]:     0043848a(j), 0043848e(j)  
    //                              diam_map.cpp:1292 (23)
    //         004384de     MOVSX      this,word ptr [EBP + 0x2]
    //         004384e2     MOV        EDX,dword ptr [ESI + 0xc]
    //         004384e5     ADD        this,EDX
    //         004384e7     MOVSX      EDX,word ptr [EBP + 0x4]
    //         004384eb     ADD        EDX,this
    //         004384ed     CMP        EAX,EDX
    //         004384ef     JGE        LAB_00438515
    //         004384f1     CMP        EDI,this
    //         004384f3     JL         LAB_00438515
    //                              diam_map.cpp:1294 (4)
    //         004384f5     CMP        EAX,this
    //         004384f7     JGE        LAB_004384fb
    //                              diam_map.cpp:1295 (2)
    //         004384f9     MOV        EAX,this
    //                               LAB_004384fb                                                 XREF[1]:     004384f7(j)  
    //                              diam_map.cpp:1296 (4)
    //         004384fb     CMP        EDI,EDX
    //         004384fd     JL         LAB_00438502
    //                              diam_map.cpp:1297 (3)
    //         004384ff     LEA        EDI,[EDX + -0x1]
    //                               LAB_00438502                                                 XREF[1]:     004384fd(j)  
    //                              diam_map.cpp:1298 (34)
    //         00438502     MOV        this,dword ptr [ESI + 0x20]
    //         00438505     SUB        EDI,EAX
    //         00438507     INC        EDI
    //         00438508     PUSH       0xff
    //         0043850d     PUSH       EDI
    //         0043850e     PUSH       EBX
    //         0043850f     PUSH       EAX
    //         00438510     CALL       TDrawArea::DrawHorzLine                          void DrawHorzLine(TDrawArea * this, long para
    //                               LAB_00438515                                                 XREF[7]:     0043844b(j), 0043845e(j), 
    //                                                                                                         004384c7(j), 004384cb(j), 
    //                                                                                                         004384dc(j), 004384ef(j), 
    //                                                                                                         004384f3(j)  
    //         00438515     MOV        EDX,dword ptr [ESI + 0x120]
    //         0043851b     INC        EBX
    //         0043851c     CMP        EBX,EDX
    //         0043851e     JLE        LAB_0043843c
    //                               LAB_00438524                                                 XREF[5]:     00438294(j), 004382a6(j), 
    //                                                                                                         004382af(j), 004382bd(j), 
    //                                                                                                         00438436(j)  
    //                              diam_map.cpp:1310 (8)
    //         00438524     POP        EDI
    //         00438525     POP        ESI
    //         00438526     POP        EBP
    //         00438527     POP        EBX
    //         00438528     ADD        ESP,0x10
    //         0043852b     RET
}

// Offset: 0x00438530
int pick_tile(RGE_Diamond_Map* this_, long param_2, long param_3, short* param_4, short* param_5, RGE_Tile** param_6) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall RGE_Diamond_Map::pick_tile(long,long,short *,short *,struct RGE_Tile * *)      *
    //                              *********************************************************************************************************
    //                              int __thiscall pick_tile(RGE_Diamond_Map * this, long param_1, long 
    //              int               EAX:4          <RETURN>
    //              RGE_Diamond_Ma    ECX:4 (auto)   this
    //              long              Stack[0x4]:4   param_1                   XREF[3]:     00438558(R), 004385b4(W), 004385b8(R)  
    //              long              Stack[0x8]:4   param_2                   XREF[1]:     00438551(R)  
    //              short *           Stack[0xc]:4   param_3                   XREF[1]:     004385d8(R)  
    //              short *           Stack[0x10]:4  param_4                   XREF[1]:     004385e3(R)  
    //              RGE_Tile * *      Stack[0x14]:4  param_5                   XREF[1]:     004385ee(R)  
    //                               ?pick_tile@RGE_Diamond_Map@@QAEHJJPAF0PAPAURGE_Tile@@@Z      XREF[10]:    start_scroll_view:00438693(c), 
    //                               RGE_Diamond_Map::pick_tile                                                handle_scroll_view:00438743(c), 
    //                                                                                                         is_inside:004387fc(c), 
    //                                                                                                         handle_mouse_pointing_at:0049bbca(
    //                                                                                                         handle_mouse_down:0053d3d1(c), 
    //                                                                                                         mouse_left_up_action:0053d590(c), 
    //                                                                                                         mouse_right_up_action:0053d807(c), 
    //                                                                                                         command_make_do:0053d916(c), 
    //                                                                                                         command_make_move:0053d9a6(c), 
    //                                                                                                         command_make_work:0053da46(c)  
    //                              diam_map.cpp:1317 (5)
    //         00438530     PUSH       EBX
    //         00438531     PUSH       ESI
    //         00438532     PUSH       EDI
    //         00438533     MOV        EDI,this
    //                              diam_map.cpp:1322 (28)
    //         00438535     MOV        EAX,dword ptr [EDI + 0xfc]
    //         0043853b     TEST       EAX,EAX
    //         0043853d     JZ         LAB_0043861e
    //         00438543     MOV        ESI,dword ptr [EDI + 0x128]
    //         00438549     TEST       ESI,ESI
    //         0043854b     JZ         LAB_0043861e
    //                              diam_map.cpp:1326 (18)
    //         00438551     MOV        this,dword ptr [ESP + param_2]
    //         00438555     MOV        EDX,dword ptr [EDI + 0x10]
    //         00438558     MOV        EAX,dword ptr [ESP + param_1]
    //         0043855c     MOV        EBX,dword ptr [EDI + 0xc]
    //         0043855f     SUB        this,EDX
    //         00438561     SUB        EAX,EBX
    //                              diam_map.cpp:1328 (34)
    //         00438563     MOVSX      EDX,word ptr [EDI + 0x134]
    //         0043856a     CMP        this,EDX
    //         0043856c     JL         LAB_0043861e
    //         00438572     MOVSX      EBX,word ptr [EDI + 0x138]
    //         00438579     LEA        EBX,[EBX + EDX*0x1 + -0x1]
    //         0043857d     CMP        this,EBX
    //         0043857f     JG         LAB_0043861e
    //                              diam_map.cpp:1332 (5)
    //         00438585     SUB        this,EDX
    //         00438587     LEA        this,[ECX + ECX*0x2]
    //                              diam_map.cpp:1334 (28)
    //         0043858a     MOVSX      EDX,word ptr [ESI + this->_padding_*0x2 + 0x2]
    //         0043858f     LEA        this,[ESI + this->_padding_*0x2]
    //         00438592     CMP        EAX,EDX
    //         00438594     JL         LAB_0043861e
    //         0043859a     MOVSX      ESI,word ptr [ECX + this->_padding_]
    //         0043859e     LEA        ESI,[ESI + EDX*0x1 + -0x1]
    //         004385a2     CMP        EAX,ESI
    //         004385a4     JG         LAB_0043861e
    //                              diam_map.cpp:1338 (9)
    //         004385a6     MOVSX      this,word ptr [this->_padding_]
    //         004385a9     MOV        ESI,dword ptr [EDI + 0x12c]
    //                              diam_map.cpp:1339 (27)
    //         004385af     SUB        EAX,EDX
    //         004385b1     LEA        this,[ECX + ECX*0x8]
    //         004385b4     MOV        dword ptr [ESP + param_1],EAX
    //         004385b8     FILD       dword ptr [ESP + param_1]
    //         004385bc     LEA        ESI,[ESI + this->_padding_*0x4]
    //         004385bf     FMUL       float ptr [ESI + 0x8]
    //         004385c2     FADD       float ptr [ESI + 0xc]
    //         004385c5     CALL       __ftol                                           undefined __ftol()
    //                              diam_map.cpp:1341 (4)
    //         004385ca     MOV        this,word ptr [ESI + 0x10]
    //                              diam_map.cpp:1342 (10)
    //         004385ce     MOV        SI,word ptr [ESI + 0x12]
    //         004385d2     ADD        this,AX
    //         004385d5     ADD        SI,AX
    //                              diam_map.cpp:1344 (8)
    //         004385d8     MOV        EAX,dword ptr [ESP + param_3]
    //         004385dc     TEST       EAX,EAX
    //         004385de     JZ         LAB_004385e3
    //                              diam_map.cpp:1345 (3)
    //         004385e0     MOV        word ptr [EAX],this
    //                               LAB_004385e3                                                 XREF[1]:     004385de(j)  
    //                              diam_map.cpp:1347 (8)
    //         004385e3     MOV        EAX,dword ptr [ESP + param_4]
    //         004385e7     TEST       EAX,EAX
    //         004385e9     JZ         LAB_004385ee
    //                              diam_map.cpp:1348 (3)
    //         004385eb     MOV        word ptr [EAX],SI
    //                               LAB_004385ee                                                 XREF[1]:     004385e9(j)  
    //                              diam_map.cpp:1350 (8)
    //         004385ee     MOV        EDX,dword ptr [ESP + param_5]
    //         004385f2     TEST       EDX,EDX
    //         004385f4     JZ         LAB_00438613
    //                              diam_map.cpp:1351 (29)
    //         004385f6     MOV        EAX,dword ptr [EDI + 0xfc]
    //         004385fc     MOVSX      ESI,SI
    //         004385ff     MOV        EDI,dword ptr [EAX + 0x8d8c]
    //         00438605     MOVSX      EAX,this
    //         00438608     LEA        this,[EAX + EAX*0x2]
    //         0043860b     MOV        EAX,dword ptr [EDI + ESI*0x4]
    //         0043860e     LEA        this,[EAX + this->_padding_*0x8]
    //         00438611     MOV        dword ptr [EDX],this
    //                               LAB_00438613                                                 XREF[1]:     004385f4(j)  
    //                              diam_map.cpp:1353 (5)
    //         00438613     MOV        EAX,0x1
    //                              diam_map.cpp:1354 (14)
    //         00438618     POP        EDI
    //         00438619     POP        ESI
    //         0043861a     POP        EBX
    //         0043861b     RET        0x14
    //                               LAB_0043861e                                                 XREF[6]:     0043853d(j), 0043854b(j), 
    //                                                                                                         0043856c(j), 0043857f(j), 
    //                                                                                                         00438594(j), 004385a4(j)  
    //         0043861e     POP        EDI
    //         0043861f     POP        ESI
    //         00438620     XOR        EAX,EAX
    //         00438622     POP        EBX
    //         00438623     RET        0x14
}

// Offset: 0x00438630
long RGE_Diamond_Map_View::handle_size(long param_1, long param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual long __thiscall RGE_Diamond_Map::handle_size(long,long)                               *
    //                              *********************************************************************************************************
    //                              long __thiscall handle_size(RGE_Diamond_Map * this, long param_1, lo
    //              long              EAX:4          <RETURN>
    //              RGE_Diamond_Ma    ECX:4 (auto)   this
    //              long              Stack[0x4]:4   param_1                   XREF[1]:     00438638(R)  
    //              long              Stack[0x8]:4   param_2                   XREF[1]:     00438630(R)  
    //                               ?handle_size@RGE_Diamond_Map@@UAEJJJ@Z                       XREF[3]:     0056f558(*), 005773a0(*), 
    //                               RGE_Diamond_Map::handle_size                                              00577738(*)  
    //                              diam_map.cpp:1360 (20)
    //         00438630     MOV        EAX,dword ptr [ESP + param_2]
    //         00438634     PUSH       ESI
    //         00438635     MOV        ESI,this
    //         00438637     PUSH       EAX
    //         00438638     MOV        this,dword ptr [ESP + param_1]
    //         0043863c     PUSH       this
    //         0043863d     MOV        this,ESI
    //         0043863f     CALL       TPanel::handle_size                              long handle_size(TPanel * this, long param_1,
    //                              diam_map.cpp:1363 (3)
    //         00438644     OR         EAX,0xffffffff
    //                              diam_map.cpp:1367 (21)
    //         00438647     MOV        this,ESI
    //         00438649     MOV        word ptr [ESI + 0x14c],AX
    //         00438650     MOV        word ptr [ESI + 0x14e],AX
    //         00438657     CALL       RGE_Diamond_Map::create_surfaces                 int create_surfaces(RGE_Diamond_Map * this)
    //                              diam_map.cpp:1369 (2)
    //         0043865c     XOR        EAX,EAX
    //                              diam_map.cpp:1370 (4)
    //         0043865e     POP        ESI
    //         0043865f     RET        0x8
}

// Offset: 0x00438670
void start_scroll_view(RGE_Diamond_Map* this_, long param_2, long param_3) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall RGE_Diamond_Map::start_scroll_view(long,long)                                 *
    //                              *********************************************************************************************************
    //                              void __thiscall start_scroll_view(RGE_Diamond_Map * this, long param
    //              void              <VOID>         <RETURN>
    //              RGE_Diamond_Ma    ECX:4 (auto)   this
    //              long              Stack[0x4]:4   param_1                   XREF[3]:     00438677(*), 0043867c(R), 004386b1(R)  
    //              long              Stack[0x8]:4   param_2                   XREF[3]:     00438684(R), 00438688(*), 004386a3(R)  
    //              undefined         Stack[-0x4]:1  local_4                   XREF[1]:     00438673(*)  
    //              RGE_Tile *        Stack[-0x8]:4  tile                      XREF[4]:     004386a8(W), 004386ad(R), 004386bc(W), 004386cd(R)  
    //              undefined4        Stack[-0x18]:4 local_18                  XREF[1]:     004386ca(*)  
    //              undefined4        Stack[-0x1c]:4 local_1c                  XREF[1]:     004386de(*)  
    //                               ?start_scroll_view@RGE_Diamond_Map@@QAEXJJ@Z                 XREF[2]:     mouse_left_down_action:0053d44b(c)
    //                               RGE_Diamond_Map::start_scroll_view                                        mouse_right_down_action:0053d68a(c
    //                              diam_map.cpp:1376 (3)
    //         00438670     SUB        ESP,0x8
    //                              diam_map.cpp:1381 (41)
    //         00438673     LEA        EAX=>local_4,[ESP + 0x4]
    //         00438677     LEA        EDX=>param_1,[ESP + 0xc]
    //         0043867b     PUSH       EBX
    //         0043867c     MOV        EBX,dword ptr [ESP + param_1]
    //         00438680     PUSH       ESI
    //         00438681     MOV        ESI,this
    //         00438683     PUSH       EDI
    //         00438684     MOV        EDI,dword ptr [ESP + param_2]
    //         00438688     LEA        this=>param_2,[ESP + 0x1c]
    //         0043868c     PUSH       EAX
    //         0043868d     PUSH       this
    //         0043868e     PUSH       EDX
    //         0043868f     PUSH       EDI
    //         00438690     PUSH       EBX
    //         00438691     MOV        this,ESI
    //         00438693     CALL       RGE_Diamond_Map::pick_tile                       int pick_tile(RGE_Diamond_Map * this, long pa
    //         00438698     TEST       EAX,EAX
    //         0043869a     JZ         LAB_0043870c
    //                              diam_map.cpp:1383 (7)
    //         0043869c     MOV        this,ESI
    //         0043869e     CALL       TPanel::capture_mouse                            int capture_mouse(TPanel * this)
    //                              diam_map.cpp:1387 (67)
    //         004386a3     MOVSX      EAX,word ptr [ESP + param_2]
    //         004386a8     MOV        dword ptr [ESP + tile],EAX
    //         004386ac     PUSH       this
    //         004386ad     FILD       dword ptr [ESP + tile]
    //         004386b1     MOVSX      this,word ptr [ESP + param_1]
    //         004386b6     FSUB       float ptr [DAT_0056f608]
    //         004386bc     MOV        dword ptr [ESP + tile],this
    //         004386c0     MOV        dword ptr [ESI + 0x154],0x1
    //         004386ca     FSTP       float ptr [ESP]=>local_18
    //         004386cd     FILD       dword ptr [ESP + tile]
    //         004386d1     PUSH       this
    //         004386d2     MOV        this,dword ptr [ESI + 0xf8]
    //         004386d8     FSUB       float ptr [DAT_0056f608]
    //         004386de     FSTP       float ptr [ESP]=>local_1c
    //         004386e1     CALL       RGE_Player::set_view_loc                         void set_view_loc(RGE_Player * this, float pa
    //                              diam_map.cpp:1389 (9)
    //         004386e6     MOV        EDX,dword ptr [ESI]
    //         004386e8     PUSH       0x1
    //         004386ea     MOV        this,ESI
    //         004386ec     CALL       dword ptr [EDX + 0x20]
    //                              diam_map.cpp:1390 (10)
    //         004386ef     MOV        this,dword ptr [ESI + 0x150]
    //         004386f5     TEST       this,this
    //         004386f7     JZ         LAB_00438700
    //                              diam_map.cpp:1391 (7)
    //         004386f9     MOV        EAX,dword ptr [this->_padding_]
    //         004386fb     PUSH       0x1
    //         004386fd     CALL       dword ptr [EAX + 0x20]
    //                               LAB_00438700                                                 XREF[1]:     004386f7(j)  
    //                              diam_map.cpp:1393 (6)
    //         00438700     MOV        dword ptr [ESI + 0x108],EBX
    //                              diam_map.cpp:1394 (6)
    //         00438706     MOV        dword ptr [ESI + 0x10c],EDI
    //                               LAB_0043870c                                                 XREF[1]:     0043869a(j)  
    //                              diam_map.cpp:1396 (9)
    //         0043870c     POP        EDI
    //         0043870d     POP        ESI
    //         0043870e     POP        EBX
    //         0043870f     ADD        ESP,0x8
    //         00438712     RET        0x8
}

// Offset: 0x00438720
void handle_scroll_view(RGE_Diamond_Map* this_, long param_2, long param_3) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall RGE_Diamond_Map::handle_scroll_view(long,long)                                *
    //                              *********************************************************************************************************
    //                              void __thiscall handle_scroll_view(RGE_Diamond_Map * this, long para
    //              void              <VOID>         <RETURN>
    //              RGE_Diamond_Ma    ECX:4 (auto)   this
    //              long              Stack[0x4]:4   param_1                   XREF[3]:     00438727(*), 0043872c(R), 0043875a(R)  
    //              long              Stack[0x8]:4   param_2                   XREF[3]:     00438734(R), 00438738(*), 0043874c(R)  
    //              undefined         Stack[-0x4]:1  local_4                   XREF[1]:     00438723(*)  
    //              RGE_Tile *        Stack[-0x8]:4  tile                      XREF[4]:     00438751(W), 00438756(R), 00438765(W), 0043876c(R)  
    //              undefined4        Stack[-0x18]:4 local_18                  XREF[1]:     00438769(*)  
    //              undefined4        Stack[-0x1c]:4 local_1c                  XREF[1]:     0043877d(*)  
    //                               ?handle_scroll_view@RGE_Diamond_Map@@QAEXJJ@Z                XREF[2]:     mouse_left_move_action:0053d4de(c)
    //                               RGE_Diamond_Map::handle_scroll_view                                       mouse_right_move_action:0053d6fe(c
    //                              diam_map.cpp:1402 (3)
    //         00438720     SUB        ESP,0x8
    //                              diam_map.cpp:1406 (41)
    //         00438723     LEA        EAX=>local_4,[ESP + 0x4]
    //         00438727     LEA        EDX=>param_1,[ESP + 0xc]
    //         0043872b     PUSH       EBX
    //         0043872c     MOV        EBX,dword ptr [ESP + param_1]
    //         00438730     PUSH       ESI
    //         00438731     MOV        ESI,this
    //         00438733     PUSH       EDI
    //         00438734     MOV        EDI,dword ptr [ESP + param_2]
    //         00438738     LEA        this=>param_2,[ESP + 0x1c]
    //         0043873c     PUSH       EAX
    //         0043873d     PUSH       this
    //         0043873e     PUSH       EDX
    //         0043873f     PUSH       EDI
    //         00438740     PUSH       EBX
    //         00438741     MOV        this,ESI
    //         00438743     CALL       RGE_Diamond_Map::pick_tile                       int pick_tile(RGE_Diamond_Map * this, long pa
    //         00438748     TEST       EAX,EAX
    //         0043874a     JZ         LAB_004387ab
    //                              diam_map.cpp:1408 (57)
    //         0043874c     MOVSX      EAX,word ptr [ESP + param_2]
    //         00438751     MOV        dword ptr [ESP + tile],EAX
    //         00438755     PUSH       this
    //         00438756     FILD       dword ptr [ESP + tile]
    //         0043875a     MOVSX      this,word ptr [ESP + param_1]
    //         0043875f     FSUB       float ptr [DAT_0056f608]
    //         00438765     MOV        dword ptr [ESP + tile],this
    //         00438769     FSTP       float ptr [ESP]=>local_18
    //         0043876c     FILD       dword ptr [ESP + tile]
    //         00438770     PUSH       this
    //         00438771     MOV        this,dword ptr [ESI + 0xf8]
    //         00438777     FSUB       float ptr [DAT_0056f608]
    //         0043877d     FSTP       float ptr [ESP]=>local_1c
    //         00438780     CALL       RGE_Player::set_view_loc                         void set_view_loc(RGE_Player * this, float pa
    //                              diam_map.cpp:1409 (9)
    //         00438785     MOV        EDX,dword ptr [ESI]
    //         00438787     PUSH       0x1
    //         00438789     MOV        this,ESI
    //         0043878b     CALL       dword ptr [EDX + 0x20]
    //                              diam_map.cpp:1410 (10)
    //         0043878e     MOV        this,dword ptr [ESI + 0x150]
    //         00438794     TEST       this,this
    //         00438796     JZ         LAB_0043879f
    //                              diam_map.cpp:1411 (7)
    //         00438798     MOV        EAX,dword ptr [this->_padding_]
    //         0043879a     PUSH       0x1
    //         0043879c     CALL       dword ptr [EAX + 0x20]
    //                               LAB_0043879f                                                 XREF[1]:     00438796(j)  
    //                              diam_map.cpp:1412 (6)
    //         0043879f     MOV        dword ptr [ESI + 0x108],EBX
    //                              diam_map.cpp:1413 (6)
    //         004387a5     MOV        dword ptr [ESI + 0x10c],EDI
    //                               LAB_004387ab                                                 XREF[1]:     0043874a(j)  
    //                              diam_map.cpp:1423 (9)
    //         004387ab     POP        EDI
    //         004387ac     POP        ESI
    //         004387ad     POP        EBX
    //         004387ae     ADD        ESP,0x8
    //         004387b1     RET        0x8
}

// Offset: 0x004387C0
void end_scroll_view(RGE_Diamond_Map* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall RGE_Diamond_Map::end_scroll_view(void)                                        *
    //                              *********************************************************************************************************
    //                              void __thiscall end_scroll_view(RGE_Diamond_Map * this)
    //              void              <VOID>         <RETURN>
    //              RGE_Diamond_Ma    ECX:4 (auto)   this
    //                               ?end_scroll_view@RGE_Diamond_Map@@QAEXXZ                     XREF[4]:     mouse_left_move_action:0053d4b8(c)
    //                               RGE_Diamond_Map::end_scroll_view                                          mouse_left_up_action:0053d537(c), 
    //                                                                                                         mouse_right_move_action:0053d6d8(c
    //                                                                                                         mouse_right_up_action:0053d753(c)  
    //                              diam_map.cpp:1429 (10)
    //         004387c0     MOV        dword ptr [ECX + this->scrolling],0x0
    //                              diam_map.cpp:1432 (5)
    //         004387ca     JMP        TPanel::release_mouse                            void release_mouse(TPanel * this)
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
}

// Offset: 0x004387D0
int RGE_Diamond_Map_View::is_inside(long param_1, long param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual int __thiscall RGE_Diamond_Map::is_inside(long,long)                                  *
    //                              *********************************************************************************************************
    //                              int __thiscall is_inside(RGE_Diamond_Map * this, long param_1, long 
    //              int               EAX:4          <RETURN>
    //              RGE_Diamond_Ma    ECX:4 (auto)   this
    //              long              Stack[0x4]:4   param_1                   XREF[2]:     004387d2(R), 004387f2(*)  
    //              long              Stack[0x8]:4   param_2                   XREF[2]:     004387d8(R), 004387ed(*)  
    //              undefined         Stack[-0x4]:1  local_4                   XREF[1]:     004387e9(*)  
    //              RGE_Tile *        Stack[-0x8]:4  tile
    //                               ?is_inside@RGE_Diamond_Map@@UAEHJJ@Z                         XREF[3]:     0056f5c4(*), 0057740c(*), 
    //                               RGE_Diamond_Map::is_inside                                                005777a4(*)  
    //                              diam_map.cpp:1439 (2)
    //         004387d0     PUSH       this
    //         004387d1     PUSH       EBX
    //                              diam_map.cpp:1443 (23)
    //         004387d2     MOV        EBX,dword ptr [ESP + param_1]
    //         004387d6     PUSH       ESI
    //         004387d7     PUSH       EDI
    //         004387d8     MOV        EDI,dword ptr [ESP + param_2]
    //         004387dc     MOV        ESI,this
    //         004387de     PUSH       EDI
    //         004387df     PUSH       EBX
    //         004387e0     CALL       TPanel::is_inside                                int is_inside(TPanel * this, long param_1, lo
    //         004387e5     TEST       EAX,EAX
    //         004387e7     JZ         LAB_00438808
    //                              diam_map.cpp:1447 (24)
    //         004387e9     LEA        EAX=>local_4,[ESP + 0xc]
    //         004387ed     LEA        this=>param_2,[ESP + 0x18]
    //         004387f1     PUSH       EAX
    //         004387f2     LEA        EDX=>param_1,[ESP + 0x18]
    //         004387f6     PUSH       this
    //         004387f7     PUSH       EDX
    //         004387f8     PUSH       EDI
    //         004387f9     PUSH       EBX
    //         004387fa     MOV        this,ESI
    //         004387fc     CALL       RGE_Diamond_Map::pick_tile                       int pick_tile(RGE_Diamond_Map * this, long pa
    //                              diam_map.cpp:1450 (16)
    //         00438801     POP        EDI
    //         00438802     POP        ESI
    //         00438803     POP        EBX
    //         00438804     POP        this
    //         00438805     RET        0x8
    //                               LAB_00438808                                                 XREF[1]:     004387e7(j)  
    //         00438808     POP        EDI
    //         00438809     POP        ESI
    //         0043880a     XOR        EAX,EAX
    //         0043880c     POP        EBX
    //         0043880d     POP        this
    //         0043880e     RET        0x8
}

