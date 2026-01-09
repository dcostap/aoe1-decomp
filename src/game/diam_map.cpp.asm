#include "common.h"
#include "diam_map.h"

RGE_Diamond_Map::RGE_Diamond_Map() {
    /* TODO: Stub */
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
    //         00436908     ??         90h
    //         00436909     NOP
    //         0043690a     NOP
    //         0043690b     NOP
    //         0043690c     NOP
    //         0043690d     NOP
    //         0043690e     NOP
    //         0043690f     NOP
}

RGE_Diamond_Map::~RGE_Diamond_Map() {
    /* TODO: Stub */
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
    //         004369b9     ??         90h
    //         004369ba     NOP
    //         004369bb     NOP
    //         004369bc     NOP
    //         004369bd     NOP
    //         004369be     NOP
    //         004369bf     NOP
    //                              * public: long __thiscall RGE_Diamond_Map::setup(class TDrawArea *,class TPanel *,long,long,long,lon... *
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
    //         00436a04     ??         90h
    //         00436a05     NOP
    //         00436a06     NOP
    //         00436a07     NOP
    //         00436a08     NOP
    //         00436a09     NOP
    //         00436a0a     NOP
    //         00436a0b     NOP
    //         00436a0c     NOP
    //         00436a0d     NOP
    //         00436a0e     NOP
    //         00436a0f     NOP
}

int RGE_Diamond_Map::set_bitmap(char* param_1, long param_2) {
    /* TODO: Stub */
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
    //         00436c2d     ??         90h
    //         00436c2e     NOP
    //         00436c2f     NOP
    return 0;
}

void RGE_Diamond_Map::set_world(RGE_Game_World* param_1) {
    /* TODO: Stub */
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
    //         00437069     ??         90h
    //         0043706a     NOP
    //         0043706b     NOP
    //         0043706c     NOP
    //         0043706d     NOP
    //         0043706e     NOP
    //         0043706f     NOP
    return;
}

void RGE_Diamond_Map::set_player(RGE_Player* param_1) {
    /* TODO: Stub */
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
    //         00437084     ??         90h
    //         00437085     NOP
    //         00437086     NOP
    //         00437087     NOP
    //         00437088     NOP
    //         00437089     NOP
    //         0043708a     NOP
    //         0043708b     NOP
    //         0043708c     NOP
    //         0043708d     NOP
    //         0043708e     NOP
    //         0043708f     NOP
    return;
}

void RGE_Diamond_Map::set_redraw(RedrawMode param_1) {
    /* TODO: Stub */
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
    //         004370b2     ??         90h
    //         004370b3     NOP
    //         004370b4     NOP
    //         004370b5     NOP
    //         004370b6     NOP
    //         004370b7     NOP
    //         004370b8     NOP
    //         004370b9     NOP
    //         004370ba     NOP
    //         004370bb     NOP
    //         004370bc     NOP
    //         004370bd     NOP
    //         004370be     NOP
    //         004370bf     NOP
    return;
}

void RGE_Diamond_Map::delete_surfaces() {
    /* TODO: Stub */
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
    //         00437103     ??         90h
    //         00437104     NOP
    //         00437105     NOP
    //         00437106     NOP
    //         00437107     NOP
    //         00437108     NOP
    //         00437109     NOP
    //         0043710a     NOP
    //         0043710b     NOP
    //         0043710c     NOP
    //         0043710d     NOP
    //         0043710e     NOP
    //         0043710f     NOP
    return;
}

int RGE_Diamond_Map::create_surfaces() {
    /* TODO: Stub */
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
    //         00437229     ??         90h
    //         0043722a     NOP
    //         0043722b     NOP
    //         0043722c     NOP
    //         0043722d     NOP
    //         0043722e     NOP
    //         0043722f     NOP
    return 0;
}

void RGE_Diamond_Map::draw() {
    /* TODO: Stub */
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
    //         00437482     ??         90h
    //         00437483     NOP
    //         00437484     NOP
    //         00437485     NOP
    //         00437486     NOP
    //         00437487     NOP
    //         00437488     NOP
    //         00437489     NOP
    //         0043748a     NOP
    //         0043748b     NOP
    //         0043748c     NOP
    //         0043748d     NOP
    //         0043748e     NOP
    //         0043748f     NOP
    return;
}

void RGE_Diamond_Map::clear_image() {
    /* TODO: Stub */
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
    //         0043760e     ??         90h
    //         0043760f     NOP
    return;
}

void RGE_Diamond_Map::copy_image() {
    /* TODO: Stub */
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
    //         0043765e     ??         90h
    //         0043765f     NOP
    return;
}

void RGE_Diamond_Map::draw_all_tiles() {
    /* TODO: Stub */
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
    //         004376c6     ??         90h
    //         004376c7     NOP
    //         004376c8     NOP
    //         004376c9     NOP
    //         004376ca     NOP
    //         004376cb     NOP
    //         004376cc     NOP
    //         004376cd     NOP
    //         004376ce     NOP
    //         004376cf     NOP
    return;
}

void RGE_Diamond_Map::draw_explored_tiles() {
    /* TODO: Stub */
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
    //         00437759     ??         90h
    //         0043775a     NOP
    //         0043775b     NOP
    //         0043775c     NOP
    //         0043775d     NOP
    //         0043775e     NOP
    //         0043775f     NOP
    return;
}

void RGE_Diamond_Map::draw_tile(short param_1, short param_2, int param_3, uchar param_4) {
    /* TODO: Stub */
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
    //                              *                                               FUNCTION                                                *
    //                              undefined FUN_00437bd9()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00437bd9
    //         00437bd9     NOP
    //         00437bda     MOV        EDI,EDI
    //                              Symbol Ref: No symbol: NONAME
    //                               switchD_004378bc::switchdataD_00437bdc                       XREF[1]:     draw_tile:004378bc(*)  
    //         00437bdc     addr       switchD_004378bc::caseD_0
    //         00437be0     addr       switchD_004378bc::caseD_1
    //         00437be4     addr       switchD_004378bc::caseD_2
    //         00437be8     addr       switchD_004378bc::caseD_2
    //         00437bec     addr       switchD_004378bc::caseD_1
    //         00437bf0     addr       switchD_004378bc::caseD_1
    //         00437bf4     addr       switchD_004378bc::caseD_2
    //         00437bf8     addr       switchD_004378bc::caseD_1
    //         00437bfc     addr       switchD_004378bc::caseD_1
    //         00437c00     addr       switchD_004378bc::caseD_1
    //         00437c04     addr       switchD_004378bc::caseD_2
    //         00437c08     addr       switchD_004378bc::caseD_2
    //         00437c0c     addr       switchD_004378bc::caseD_1
    //         00437c10     addr       switchD_004378bc::caseD_1
    //         00437c14     addr       switchD_004378bc::caseD_2
    //         00437c18     addr       switchD_004378bc::caseD_1
    //         00437c1c     addr       switchD_004378bc::caseD_2
    return;
}

void RGE_Diamond_Map::draw_selected_area() {
    /* TODO: Stub */
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
    //         00437cb3     ??         90h
    //         00437cb4     NOP
    //         00437cb5     NOP
    //         00437cb6     NOP
    //         00437cb7     NOP
    //         00437cb8     NOP
    //         00437cb9     NOP
    //         00437cba     NOP
    //         00437cbb     NOP
    //         00437cbc     NOP
    //         00437cbd     NOP
    //         00437cbe     NOP
    //         00437cbf     NOP
    return;
}

void RGE_Diamond_Map::draw_objects() {
    /* TODO: Stub */
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
    //         00437eb2     ??         90h
    //         00437eb3     NOP
    //         00437eb4     NOP
    //         00437eb5     NOP
    //         00437eb6     NOP
    //         00437eb7     NOP
    //         00437eb8     NOP
    //         00437eb9     NOP
    //         00437eba     NOP
    //         00437ebb     NOP
    //         00437ebc     NOP
    //         00437ebd     NOP
    //         00437ebe     NOP
    //         00437ebf     NOP
    //                              * protected: virtual void __thiscall RGE_Diamond_Map::draw_visible_object(class RGE_Static_Object *,... *
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
    //                              *                                               FUNCTION                                                *
    //                              undefined FUN_0043804d()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0043804d
    //         0043804d     NOP
    //         0043804e     MOV        EDI,EDI
    //                              Symbol Ref: No symbol: NONAME
    //                               switchD_00437ffe::switchdataD_00438050                       XREF[1]:     draw_visible_object:00437ffe(R)  
    //         00438050     addr       switchD_00437ffe::caseD_0
    //         00438054     addr       switchD_00437ffe::caseD_1
    //         00438058     addr       switchD_00437ffe::caseD_2
    //         0043805c     addr       switchD_00437ffe::caseD_3
    //                              * protected: virtual void __thiscall RGE_Diamond_Map::draw_object(short,short,unsigned char,short,cl... *
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
    //         004381cd     ??         90h
    //         004381ce     NOP
    //         004381cf     NOP
    //                              * protected: void __thiscall RGE_Diamond_Map::draw_clipped_horz_line(short,short,short,unsigned char... *
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
    //         0043824b     ??         90h
    //         0043824c     NOP
    //         0043824d     NOP
    //         0043824e     NOP
    //         0043824f     NOP
    return;
}

void RGE_Diamond_Map::draw_view_rect() {
    /* TODO: Stub */
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
    //         0043852c     ??         90h
    //         0043852d     NOP
    //         0043852e     NOP
    //         0043852f     NOP
    return;
}

int RGE_Diamond_Map::pick_tile(long param_1, long param_2, short* param_3, short* param_4, RGE_Tile** param_5) {
    /* TODO: Stub */
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
    //         00438626     ??         90h
    //         00438627     NOP
    //         00438628     NOP
    //         00438629     NOP
    //         0043862a     NOP
    //         0043862b     NOP
    //         0043862c     NOP
    //         0043862d     NOP
    //         0043862e     NOP
    //         0043862f     NOP
    return 0;
}

long RGE_Diamond_Map::handle_size(long param_1, long param_2) {
    /* TODO: Stub */
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
    //         00438662     ??         90h
    //         00438663     NOP
    //         00438664     NOP
    //         00438665     NOP
    //         00438666     NOP
    //         00438667     NOP
    //         00438668     NOP
    //         00438669     NOP
    //         0043866a     NOP
    //         0043866b     NOP
    //         0043866c     NOP
    //         0043866d     NOP
    //         0043866e     NOP
    //         0043866f     NOP
    return 0;
}

void RGE_Diamond_Map::start_scroll_view(long param_1, long param_2) {
    /* TODO: Stub */
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
    //         00438715     ??         90h
    //         00438716     NOP
    //         00438717     NOP
    //         00438718     NOP
    //         00438719     NOP
    //         0043871a     NOP
    //         0043871b     NOP
    //         0043871c     NOP
    //         0043871d     NOP
    //         0043871e     NOP
    //         0043871f     NOP
    return;
}

void RGE_Diamond_Map::handle_scroll_view(long param_1, long param_2) {
    /* TODO: Stub */
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
    //         004387b4     ??         90h
    //         004387b5     NOP
    //         004387b6     NOP
    //         004387b7     NOP
    //         004387b8     NOP
    //         004387b9     NOP
    //         004387ba     NOP
    //         004387bb     NOP
    //         004387bc     NOP
    //         004387bd     NOP
    //         004387be     NOP
    //         004387bf     NOP
    return;
}

void RGE_Diamond_Map::end_scroll_view() {
    /* TODO: Stub */
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
    //         004387cf     ??         90h
    return;
}

int RGE_Diamond_Map::is_inside(long param_1, long param_2) {
    /* TODO: Stub */
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
    //         00438811     ??         90h
    //         00438812     NOP
    //         00438813     NOP
    //         00438814     NOP
    //         00438815     NOP
    //         00438816     NOP
    //         00438817     NOP
    //         00438818     NOP
    //         00438819     NOP
    //         0043881a     NOP
    //         0043881b     NOP
    //         0043881c     NOP
    //         0043881d     NOP
    //         0043881e     NOP
    //         0043881f     NOP
    //                              * void __cdecl DibBlt(struct BITMAPINFO256 *,unsigned char *,struct tagRECT *,long,long,long,long,st... *
    //                              void __cdecl DibBlt(BITMAPINFO256 * param_1, uchar * param_2, tagREC
    //              void              <VOID>         <RETURN>
    //              BITMAPINFO256 *   Stack[0x4]:4   param_1                   XREF[5]:     00438831(R), 00438893(*), 004388ac(R), 004388b9(W), 
    //                                                                                     00438a28(R)  
    //              uchar *           Stack[0x8]:4   param_2                   XREF[1]:     00438907(R)  
    //              tagRECT *         Stack[0xc]:4   param_3                   XREF[4]:     0043885f(R), 00438897(*), 0043893f(R), 00438a36(R)  
    //              long              Stack[0x10]:4  param_4                   XREF[2]:     00438863(*), 00438901(R)  
    //              long              Stack[0x14]:4  param_5                   XREF[3]:     0043885a(*), 004388ea(R), 004388f5(R)  
    //              long              Stack[0x18]:4  param_6                   XREF[6]:     00438855(*), 004388c1(R), 0043897d(R), 004389bb(R), 
    //                                                                                     00438a4b(R), 00438a63(R)  
    //              long              Stack[0x1c]:4  param_7                   XREF[6]:     00438850(*), 004388d9(R), 0043895d(R), 00438991(R), 
    //                                                                                     00438a09(R), 00438a83(R)  
    //              BITMAPINFO256 *   Stack[0x20]:4  param_8                   XREF[3]:     004388a0(R), 004388e0(W), 00438a73(R)  
    //              uchar *           Stack[0x24]:4  param_9                   XREF[2]:     00438963(R), 00438a20(R)  
    //              long              Stack[0x28]:4  param_10                  XREF[6]:     0043884b(*), 00438959(R), 004389b1(R), 004389d6(R), 
    //                                                                                     004389fc(R), 00438a6b(R)  
    //              long              Stack[0x2c]:4  param_11                  XREF[4]:     00438846(*), 00438938(R), 00438943(R), 00438a05(R)  
    //              long              Stack[0x30]:4  param_12                  XREF[2]:     00438841(*), 004388bd(R)  
    //              long              Stack[0x34]:4  param_13                  XREF[2]:     0043883c(*), 004388d1(R)  
    //              int               Stack[0x38]:4  param_14                  XREF[10]:    00438820(R), 00438884(*), 004388e6(R), 004388fc(R), 
    //                                                                                     00438951(R), 0043896f(W), 00438989(R), 00438a00(R), 
    //                                                                                     00438a12(W), 00438a77(R)  
    //              int               Stack[0x3c]:4  param_15                  XREF[6]:     00438837(R), 00438921(R), 004389a9(R), 00438a16(W), 
    //                                                                                     00438a7d(R), 00438a8a(W)  
    //              int               Stack[0x40]:4  param_16                  XREF[8]:     0043882c(R), 0043889b(*), 00438932(R), 00438947(R), 
    //                                                                                     00438967(W), 0043898d(R), 00438a24(R), 00438a6f(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     0043887f(*), 004388f1(R)  
    //              long              Stack[-0x8]:4  DestTotHgt                XREF[2]:     0043887b(*), 004388cb(R)  
    //              long              Stack[-0xc]:4  DestOrien
    //                               ?DibBlt@@YAXPAUBITMAPINFO256@@PAEPAUtagRECT@@JJJJ01JJJJHHH@Z XREF[8]:     TransDibBlt:00438b05(c), 
    //                               DibBlt                                                                    TileDibBlt:0043943b(c), 
    //                                                                                                         TileDibBlt:00439494(c), 
    //                                                                                                         TileDibBlt:004394ec(c), 
    //                                                                                                         TileDibBlt:0043953f(c), 
    //                                                                                                         DibWriteClipped:00439c8b(c), 
    //                                                                                                         Copy:00444e64(c), 
    //                                                                                                         Draw:0046e361(c)  
    //                              Dib.cpp:72 (91)
    //         00438820     MOV        EAX,dword ptr [ESP + param_14]
    //         00438824     SUB        ESP,0x8
    //         00438827     TEST       EAX,EAX
    //         00438829     PUSH       EBX
    //         0043882a     PUSH       EBP
    //         0043882b     PUSH       ESI
    //         0043882c     MOV        ESI,dword ptr [ESP + param_16]
    //         00438830     PUSH       EDI
    //         00438831     MOV        EDI,dword ptr [ESP + param_1]
    //         00438835     JZ         LAB_0043887b
    //         00438837     MOV        EAX,dword ptr [ESP + param_15]
    //         0043883b     PUSH       ESI
    //         0043883c     LEA        ECX=>param_13,[ESP + 0x50]
    //         00438840     PUSH       EAX
    //         00438841     LEA        EDX=>param_12,[ESP + 0x50]
    //         00438845     PUSH       ECX
    //         00438846     LEA        EAX=>param_11,[ESP + 0x50]
    //         0043884a     PUSH       EDX
    //         0043884b     LEA        ECX=>param_10,[ESP + 0x50]
    //         0043884f     PUSH       EAX
    //         00438850     LEA        EDX=>param_7,[ESP + 0x48]
    //         00438854     PUSH       ECX
    //         00438855     LEA        EAX=>param_6,[ESP + 0x48]
    //         00438859     PUSH       EDX
    //         0043885a     LEA        ECX=>param_5,[ESP + 0x48]
    //         0043885e     PUSH       EAX
    //         0043885f     MOV        EAX,dword ptr [ESP + param_3]
    //         00438863     LEA        EDX=>param_4,[ESP + 0x48]
    //         00438867     PUSH       ECX
    //         00438868     PUSH       EDX
    //         00438869     PUSH       EAX
    //         0043886a     PUSH       EDI
    //         0043886b     CALL       ClipDibBlt                                       int ClipDibBlt(BITMAPINFO256 * param_1, tagRE
    //         00438870     ADD        ESP,0x30
    //         00438873     TEST       EAX,EAX
    //         00438875     JZ         LAB_00438a90
    //                               LAB_0043887b                                                 XREF[1]:     00438835(j)  
    //                              Dib.cpp:80 (24)
    //         0043887b     LEA        ECX=>DestTotHgt,[ESP + 0x10]
    //         0043887f     LEA        EDX=>local_4,[ESP + 0x14]
    //         00438883     PUSH       ECX
    //         00438884     LEA        EAX=>param_14,[ESP + 0x54]
    //         00438888     PUSH       EDX
    //         00438889     PUSH       EAX
    //         0043888a     PUSH       EDI
    //         0043888b     CALL       GetDibDim                                        void GetDibDim(BITMAPINFO256 * param_1, long 
    //         00438890     ADD        ESP,0x10
    //                              Dib.cpp:81 (25)
    //         00438893     LEA        ECX=>param_1,[ESP + 0x1c]
    //         00438897     LEA        EDX=>param_3,[ESP + 0x24]
    //         0043889b     LEA        EAX=>param_16,[ESP + 0x58]
    //         0043889f     PUSH       ECX
    //         004388a0     MOV        ECX,dword ptr [ESP + param_8]
    //         004388a4     PUSH       EDX
    //         004388a5     PUSH       EAX
    //         004388a6     PUSH       ECX
    //         004388a7     CALL       GetDibDim                                        void GetDibDim(BITMAPINFO256 * param_1, long 
    //                              Dib.cpp:84 (17)
    //         004388ac     MOV        EBP,dword ptr [ESP + param_1]
    //         004388b0     ADD        ESP,0x10
    //         004388b3     TEST       ESI,ESI
    //         004388b5     JZ         LAB_004388bd
    //         004388b7     NEG        EBP
    //         004388b9     MOV        dword ptr [ESP + param_1],EBP
    //                               LAB_004388bd                                                 XREF[1]:     004388b5(j)  
    //                              Dib.cpp:87 (14)
    //         004388bd     MOV        EAX,dword ptr [ESP + param_12]
    //         004388c1     MOV        ECX,dword ptr [ESP + param_6]
    //         004388c5     SHL        EAX,0x8
    //         004388c8     CDQ
    //         004388c9     IDIV       ECX
    //                              Dib.cpp:95 (27)
    //         004388cb     MOV        EBX,dword ptr [ESP + DestTotHgt]
    //         004388cf     MOV        ESI,EAX
    //         004388d1     MOV        EAX,dword ptr [ESP + param_13]
    //         004388d5     SHL        EAX,0x8
    //         004388d8     CDQ
    //         004388d9     IDIV       dword ptr [ESP + param_7]
    //         004388dd     CMP        EBX,0x1
    //         004388e0     MOV        dword ptr [ESP + param_8],EAX
    //         004388e4     JNZ        LAB_004388f1
    //                              Dib.cpp:96 (9)
    //         004388e6     MOV        EDI,dword ptr [ESP + param_14]
    //         004388ea     IMUL       EDI,dword ptr [ESP + param_5]
    //                              Dib.cpp:97 (2)
    //         004388ef     JMP        LAB_00438901
    //                               LAB_004388f1                                                 XREF[1]:     004388e4(j)  
    //                              Dib.cpp:98 (28)
    //         004388f1     MOV        EDI,dword ptr [ESP + local_4]
    //         004388f5     MOV        EDX,dword ptr [ESP + param_5]
    //         004388f9     SUB        EDI,EDX
    //         004388fb     DEC        EDI
    //         004388fc     IMUL       EDI,dword ptr [ESP + param_14]
    //                               LAB_00438901                                                 XREF[1]:     004388ef(j)  
    //         00438901     MOV        EDX,dword ptr [ESP + param_4]
    //         00438905     ADD        EDI,EDX
    //         00438907     MOV        EDX,dword ptr [ESP + param_2]
    //         0043890b     ADD        EDI,EDX
    //                              Dib.cpp:101 (32)
    //         0043890d     CMP        ESI,0x100
    //         00438913     JNZ        LAB_004389a9
    //         00438919     CMP        EAX,ESI
    //         0043891b     JNZ        LAB_004389a9
    //         00438921     MOV        EAX,dword ptr [ESP + param_15]
    //         00438925     TEST       EAX,EAX
    //         00438927     JNZ        LAB_004389d6
    //                              Dib.cpp:103 (5)
    //         0043892d     CMP        EBP,0x1
    //         00438930     JNZ        LAB_0043893f
    //                              Dib.cpp:104 (11)
    //         00438932     MOV        EAX,dword ptr [ESP + param_16]
    //         00438936     MOV        ESI,EAX
    //         00438938     IMUL       ESI,dword ptr [ESP + param_11]
    //                              Dib.cpp:105 (2)
    //         0043893d     JMP        LAB_00438951
    //                               LAB_0043893f                                                 XREF[1]:     00438930(j)  
    //                              Dib.cpp:106 (18)
    //         0043893f     MOV        ESI,dword ptr [ESP + param_3]
    //         00438943     MOV        EDX,dword ptr [ESP + param_11]
    //         00438947     MOV        EAX,dword ptr [ESP + param_16]
    //         0043894b     SUB        ESI,EDX
    //         0043894d     DEC        ESI
    //         0043894e     IMUL       ESI,EAX
    //                               LAB_00438951                                                 XREF[1]:     0043893d(j)  
    //                              Dib.cpp:107 (5)
    //         00438951     IMUL       EBX,dword ptr [ESP + param_14]
    //                              Dib.cpp:108 (7)
    //         00438956     IMUL       EBP,EAX
    //         00438959     MOV        EDX,dword ptr [ESP + param_10]
    //                              Dib.cpp:109 (36)
    //         0043895d     MOV        EAX,dword ptr [ESP + param_7]
    //         00438961     ADD        ESI,EDX
    //         00438963     MOV        EDX,dword ptr [ESP + param_9]
    //         00438967     MOV        dword ptr [ESP + param_16],EBP
    //         0043896b     ADD        ESI,EDX
    //         0043896d     XOR        EBP,EBP
    //         0043896f     MOV        dword ptr [ESP + param_14],EBX
    //         00438973     TEST       EAX,EAX
    //         00438975     JLE        LAB_00438a90
    //         0043897b     JMP        LAB_00438981
    //                               LAB_0043897d                                                 XREF[1]:     0043899f(j)  
    //         0043897d     MOV        ECX,dword ptr [ESP + param_6]
    //                               LAB_00438981                                                 XREF[1]:     0043897b(j)  
    //                              Dib.cpp:111 (8)
    //         00438981     PUSH       ECX
    //         00438982     PUSH       ESI
    //         00438983     PUSH       EDI
    //         00438984     CALL       memcpy                                           undefined memcpy()
    //                              Dib.cpp:112 (4)
    //         00438989     MOV        EBX,dword ptr [ESP + param_14]
    //                              Dib.cpp:113 (20)
    //         0043898d     MOV        EDX,dword ptr [ESP + param_16]
    //         00438991     MOV        EAX,dword ptr [ESP + param_7]
    //         00438995     ADD        ESP,0xc
    //         00438998     ADD        EDI,EBX
    //         0043899a     ADD        ESI,EDX
    //         0043899c     INC        EBP
    //         0043899d     CMP        EBP,EAX
    //         0043899f     JL         LAB_0043897d
    //                              Dib.cpp:145 (8)
    //         004389a1     POP        EDI
    //         004389a2     POP        ESI
    //         004389a3     POP        EBP
    //         004389a4     POP        EBX
    //         004389a5     ADD        ESP,0x8
    //         004389a8     RET
    //                               LAB_004389a9                                                 XREF[2]:     00438913(j), 0043891b(j)  
    //                              Dib.cpp:121 (8)
    //         004389a9     MOV        EAX,dword ptr [ESP + param_15]
    //         004389ad     TEST       EAX,EAX
    //         004389af     JNZ        LAB_004389d6
    //                              Dib.cpp:123 (10)
    //         004389b1     MOV        EAX,dword ptr [ESP + param_10]
    //         004389b5     TEST       ECX,ECX
    //         004389b7     MOV        EDX,EAX
    //         004389b9     JLE        LAB_00438a00
    //                              Dib.cpp:145 (25)
    //         004389bb     MOV        EBP,dword ptr [ESP + param_6]
    //         004389bf     MOV        ECX,SrcXTbl                                      = 00000000
    //                               LAB_004389c4                                                 XREF[1]:     004389d2(j)  
    //         004389c4     MOV        EAX,EDX
    //         004389c6     ADD        ECX,0x4
    //         004389c9     SAR        EAX,0x8
    //         004389cc     MOV        dword ptr [ECX + -0x4]=>SrcXTbl,EAX              = 00000000
    //         004389cf     ADD        EDX,ESI
    //         004389d1     DEC        EBP
    //         004389d2     JNZ        LAB_004389c4
    //                              Dib.cpp:126 (2)
    //         004389d4     JMP        LAB_004389fc
    //                               LAB_004389d6                                                 XREF[2]:     00438927(j), 004389af(j)  
    //                              Dib.cpp:128 (14)
    //         004389d6     MOV        EAX,dword ptr [ESP + param_10]
    //         004389da     LEA        EBP,[ECX + -0x1]
    //         004389dd     CMP        EBP,-0x1
    //         004389e0     MOV        EDX,EAX
    //         004389e2     JLE        LAB_00438a00
    //                              Dib.cpp:145 (24)
    //         004389e4     LEA        ECX,[EBP*0x4 + SrcXTbl]                          = 00000000
    //         004389eb     INC        EBP
    //                               LAB_004389ec                                                 XREF[1]:     004389fa(j)  
    //         004389ec     MOV        EAX,EDX
    //         004389ee     SUB        ECX,0x4
    //         004389f1     SAR        EAX,0x8
    //         004389f4     MOV        dword ptr [ECX + 0x4],EAX=>SrcXTbl               = 00000000
    //         004389f7     ADD        EDX,ESI
    //         004389f9     DEC        EBP
    //         004389fa     JNZ        LAB_004389ec
    //                               LAB_004389fc                                                 XREF[1]:     004389d4(j)  
    //                              Dib.cpp:128 (4)
    //         004389fc     MOV        EAX,dword ptr [ESP + param_10]
    //                               LAB_00438a00                                                 XREF[2]:     004389b9(j), 004389e2(j)  
    //                              Dib.cpp:132 (5)
    //         00438a00     IMUL       EBX,dword ptr [ESP + param_14]
    //                              Dib.cpp:133 (4)
    //         00438a05     MOV        EBP,dword ptr [ESP + param_11]
    //                              Dib.cpp:134 (31)
    //         00438a09     MOV        ECX,dword ptr [ESP + param_7]
    //         00438a0d     SHL        EBP,0x8
    //         00438a10     TEST       ECX,ECX
    //         00438a12     MOV        dword ptr [ESP + param_14],EBX
    //         00438a16     MOV        dword ptr [ESP + param_15],0x0
    //         00438a1e     JLE        LAB_00438a90
    //         00438a20     MOV        EBX,dword ptr [ESP + param_9]
    //         00438a24     MOV        ESI,dword ptr [ESP + param_16]
    //                               LAB_00438a28                                                 XREF[1]:     00438a8e(j)  
    //                              Dib.cpp:136 (7)
    //         00438a28     CMP        dword ptr [ESP + param_1],0x1
    //         00438a2d     JNZ        LAB_00438a36
    //                              Dib.cpp:137 (5)
    //         00438a2f     MOV        ECX,EBP
    //         00438a31     SAR        ECX,0x8
    //                              Dib.cpp:138 (2)
    //         00438a34     JMP        LAB_00438a42
    //                               LAB_00438a36                                                 XREF[1]:     00438a2d(j)  
    //                              Dib.cpp:139 (17)
    //         00438a36     MOV        ECX,dword ptr [ESP + param_3]
    //         00438a3a     MOV        EDX,EBP
    //         00438a3c     SAR        EDX,0x8
    //         00438a3f     SUB        ECX,EDX
    //         00438a41     DEC        ECX
    //                               LAB_00438a42                                                 XREF[1]:     00438a34(j)  
    //         00438a42     IMUL       ECX,ESI
    //         00438a45     ADD        ECX,EAX
    //                              Dib.cpp:140 (15)
    //         00438a47     XOR        EDX,EDX
    //         00438a49     ADD        ECX,EBX
    //         00438a4b     CMP        dword ptr [ESP + param_6],EDX
    //         00438a4f     JLE        LAB_00438a73
    //         00438a51     MOV        ESI,SrcXTbl                                      = 00000000
    //                               LAB_00438a56                                                 XREF[1]:     00438a69(j)  
    //                              Dib.cpp:141 (29)
    //         00438a56     MOV        EAX,dword ptr [ESI]=>SrcXTbl                     = 00000000
    //         00438a58     INC        EDX
    //         00438a59     ADD        ESI,0x4
    //         00438a5c     MOV        AL,byte ptr [ECX + EAX*0x1]
    //         00438a5f     MOV        byte ptr [EDX + EDI*0x1 + -0x1],AL
    //         00438a63     MOV        EAX,dword ptr [ESP + param_6]
    //         00438a67     CMP        EDX,EAX
    //         00438a69     JL         LAB_00438a56
    //         00438a6b     MOV        EAX,dword ptr [ESP + param_10]
    //         00438a6f     MOV        ESI,dword ptr [ESP + param_16]
    //                               LAB_00438a73                                                 XREF[1]:     00438a4f(j)  
    //                              Dib.cpp:143 (29)
    //         00438a73     MOV        ECX,dword ptr [ESP + param_8]
    //         00438a77     MOV        EDX,dword ptr [ESP + param_14]
    //         00438a7b     ADD        EBP,ECX
    //         00438a7d     MOV        ECX,dword ptr [ESP + param_15]
    //         00438a81     ADD        EDI,EDX
    //         00438a83     MOV        EDX,dword ptr [ESP + param_7]
    //         00438a87     INC        ECX
    //         00438a88     CMP        ECX,EDX
    //         00438a8a     MOV        dword ptr [ESP + param_15],ECX
    //         00438a8e     JL         LAB_00438a28
    //                               LAB_00438a90                                                 XREF[3]:     00438875(j), 00438975(j), 
    //                                                                                                         00438a1e(j)  
    //                              Dib.cpp:145 (8)
    //         00438a90     POP        EDI
    //         00438a91     POP        ESI
    //         00438a92     POP        EBP
    //         00438a93     POP        EBX
    //         00438a94     ADD        ESP,0x8
    //         00438a97     RET
    //         00438a98     ??         90h
    //         00438a99     NOP
    //         00438a9a     NOP
    //         00438a9b     NOP
    //         00438a9c     NOP
    //         00438a9d     NOP
    //         00438a9e     NOP
    //         00438a9f     NOP
    //                              * void __cdecl TransDibBlt(struct BITMAPINFO256 *,unsigned char *,struct tagRECT *,long,long,long,lo... *
    //                              void __cdecl TransDibBlt(BITMAPINFO256 * param_1, uchar * param_2, t
    //              void              <VOID>         <RETURN>
    //              BITMAPINFO256 *   Stack[0x4]:4   param_1                   XREF[6]:     00438afe(R), 00438b2d(R), 00438bb7(*), 00438ccf(R), 
    //                                                                                     00438cef(R), 00438e04(R)  
    //              uchar *           Stack[0x8]:4   param_2                   XREF[6]:     00438af9(R), 00438c11(R), 00438d72(W), 00438d76(R), 
    //                                                                                     00438e25(W), 00438e29(R)  
    //              tagRECT *         Stack[0xc]:4   param_3                   XREF[5]:     00438af4(R), 00438b5d(R), 00438bec(W), 00438d10(R), 
    //                                                                                     00438d18(R)  
    //              long              Stack[0x10]:4  param_4                   XREF[3]:     00438aef(R), 00438b61(*), 00438c0d(R)  
    //              long              Stack[0x14]:4  param_5                   XREF[4]:     00438aea(R), 00438b58(*), 00438bf6(R), 00438c01(R)  
    //              long              Stack[0x18]:4  param_6                   XREF[9]:     00438ae5(R), 00438b53(*), 00438b85(R), 00438bd9(R), 
    //                                                                                     00438c25(R), 00438c44(R), 00438d29(R), 00438e11(R), 
    //                                                                                     00438e3c(R)  
    //              long              Stack[0x1c]:4  param_7                   XREF[7]:     00438ae0(R), 00438b4e(*), 00438b93(R), 00438c98(R), 
    //                                                                                     00438da1(R), 00438dc7(R), 00438e54(R)  
    //              BITMAPINFO256 *   Stack[0x20]:4  param_8                   XREF[4]:     00438adb(R), 00438bbc(R), 00438c85(W), 00438cb9(R)  
    //              uchar *           Stack[0x24]:4  param_9                   XREF[5]:     00438ad6(R), 00438cd4(R), 00438ce8(R), 00438de6(R), 
    //                                                                                     00438e48(R)  
    //              TRANSINFO *       Stack[0x28]:4  param_10                  XREF[5]:     00438aa5(R), 00438c68(R), 00438ca5(W), 00438d95(R), 
    //                                                                                     00438dac(W)  
    //              long              Stack[0x2c]:4  param_11                  XREF[6]:     00438ad1(R), 00438b49(*), 00438c17(R), 00438ccb(R), 
    //                                                                                     00438ce2(R), 00438e09(R)  
    //              long              Stack[0x30]:4  param_12                  XREF[4]:     00438acc(R), 00438b44(*), 00438c94(R), 00438dcf(R)  
    //              long              Stack[0x34]:4  param_13                  XREF[4]:     00438ac7(R), 00438b3f(*), 00438b79(R), 00438be5(R)  
    //              long              Stack[0x38]:4  param_14                  XREF[3]:     00438ac2(R), 00438b3a(*), 00438b8b(R)  
    //              int               Stack[0x3c]:4  param_15                  XREF[11]:    00438abd(R), 00438b25(R), 00438b7d(*), 00438bf2(R), 
    //                                                                                     00438c08(R), 00438c8f(R), 00438ca1(W), 00438d91(R), 
    //                                                                                     00438dc2(R), 00438dcb(W), 00438e4c(R)  
    //              int               Stack[0x40]:4  param_16                  XREF[10]:    00438ab9(R), 00438b35(R), 00438c1d(R), 00438c6c(R), 
    //                                                                                     00438ca9(W), 00438d9d(R), 00438db0(W), 00438dd3(W), 
    //                                                                                     00438e5a(R), 00438e63(W)  
    //              int               Stack[0x44]:4  param_17                  XREF[7]:     00438ab5(R), 00438b29(R), 00438baf(*), 00438bcf(R), 
    //                                                                                     00438bd5(W), 00438cbd(R), 00438dea(R)  
    //              int               Stack[0x48]:4  param_18                  XREF[4]:     00438b15(R), 00438b1d(W), 00438d80(R), 00438e33(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     00438ba0(*), 00438bfd(R)  
    //              long              Stack[-0x8]:4  DestTotHgt                XREF[2]:     00438b97(*), 00438bdd(R)  
    //              long              Stack[-0xc]:4  DestOrien                 XREF[3]:     00438b9c(W), 00438d99(R), 00438e50(R)  
    //              long              Stack[-0x10]:4 sySkip                    XREF[3]:     00438bb3(*), 00438cde(R), 00438df8(R)  
    //              long              Stack[-0x14]:4 SrcTotHgt
    //                               ?TransDibBlt@@YAXPAUBITMAPINFO256@@PAEPAUtagRECT@@JJJJ01PAU  XREF[6]:     TileDibBlt:0043924b(c), 
    //                               TransDibBlt                                                               TileDibBlt:004392a8(c), 
    //                                                                                                         TileDibBlt:0043930a(c), 
    //                                                                                                         TileDibBlt:00439367(c), 
    //                                                                                                         Copy:00444e1a(c), 
    //                                                                                                         Draw:0046e318(c)  
    //                              Dib.cpp:155 (5)
    //         00438aa0     SUB        ESP,0x10
    //         00438aa3     PUSH       EBX
    //         00438aa4     PUSH       EBP
    //                              Dib.cpp:157 (16)
    //         00438aa5     MOV        EBP,dword ptr [ESP + param_10]
    //         00438aa9     PUSH       ESI
    //         00438aaa     TEST       EBP,EBP
    //         00438aac     PUSH       EDI
    //         00438aad     JZ         LAB_00438b15
    //         00438aaf     CMP        dword ptr [EBP],0x0
    //         00438ab3     JNZ        LAB_00438b15
    //                              Dib.cpp:161 (88)
    //         00438ab5     MOV        EAX,dword ptr [ESP + param_17]
    //         00438ab9     MOV        ECX,dword ptr [ESP + param_16]
    //         00438abd     MOV        EDX,dword ptr [ESP + param_15]
    //         00438ac1     PUSH       EAX
    //         00438ac2     MOV        EAX,dword ptr [ESP + param_14]
    //         00438ac6     PUSH       ECX
    //         00438ac7     MOV        ECX,dword ptr [ESP + param_13]
    //         00438acb     PUSH       EDX
    //         00438acc     MOV        EDX,dword ptr [ESP + param_12]
    //         00438ad0     PUSH       EAX
    //         00438ad1     MOV        EAX,dword ptr [ESP + param_11]
    //         00438ad5     PUSH       ECX
    //         00438ad6     MOV        ECX,dword ptr [ESP + param_9]
    //         00438ada     PUSH       EDX
    //         00438adb     MOV        EDX,dword ptr [ESP + param_8]
    //         00438adf     PUSH       EAX
    //         00438ae0     MOV        EAX,dword ptr [ESP + param_7]
    //         00438ae4     PUSH       ECX
    //         00438ae5     MOV        ECX,dword ptr [ESP + param_6]
    //         00438ae9     PUSH       EDX
    //         00438aea     MOV        EDX,dword ptr [ESP + param_5]
    //         00438aee     PUSH       EAX
    //         00438aef     MOV        EAX,dword ptr [ESP + param_4]
    //         00438af3     PUSH       ECX
    //         00438af4     MOV        ECX,dword ptr [ESP + param_3]
    //         00438af8     PUSH       EDX
    //         00438af9     MOV        EDX,dword ptr [ESP + param_2]
    //         00438afd     PUSH       EAX
    //         00438afe     MOV        EAX,dword ptr [ESP + param_1]
    //         00438b02     PUSH       ECX
    //         00438b03     PUSH       EDX
    //         00438b04     PUSH       EAX
    //         00438b05     CALL       DibBlt                                           void DibBlt(BITMAPINFO256 * param_1, uchar * 
    //         00438b0a     ADD        ESP,0x40
    //                              Dib.cpp:273 (8)
    //         00438b0d     POP        EDI
    //         00438b0e     POP        ESI
    //         00438b0f     POP        EBP
    //         00438b10     POP        EBX
    //         00438b11     ADD        ESP,0x10
    //         00438b14     RET
    //                               LAB_00438b15                                                 XREF[2]:     00438aad(j), 00438ab3(j)  
    //                              Dib.cpp:166 (16)
    //         00438b15     MOV        EAX,dword ptr [ESP + param_18]
    //         00438b19     TEST       EAX,EAX
    //         00438b1b     JGE        LAB_00438b25
    //         00438b1d     MOV        dword ptr [ESP + param_18],0x0
    //                               LAB_00438b25                                                 XREF[1]:     00438b1b(j)  
    //                              Dib.cpp:170 (84)
    //         00438b25     MOV        EAX,dword ptr [ESP + param_15]
    //         00438b29     MOV        EDI,dword ptr [ESP + param_17]
    //         00438b2d     MOV        EBX,dword ptr [ESP + param_1]
    //         00438b31     TEST       EAX,EAX
    //         00438b33     JZ         LAB_00438b79
    //         00438b35     MOV        ECX,dword ptr [ESP + param_16]
    //         00438b39     PUSH       EDI
    //         00438b3a     LEA        EDX=>param_14,[ESP + 0x5c]
    //         00438b3e     PUSH       ECX
    //         00438b3f     LEA        EAX=>param_13,[ESP + 0x5c]
    //         00438b43     PUSH       EDX
    //         00438b44     LEA        ECX=>param_12,[ESP + 0x5c]
    //         00438b48     PUSH       EAX
    //         00438b49     LEA        EDX=>param_11,[ESP + 0x5c]
    //         00438b4d     PUSH       ECX
    //         00438b4e     LEA        EAX=>param_7,[ESP + 0x50]
    //         00438b52     PUSH       EDX
    //         00438b53     LEA        ECX=>param_6,[ESP + 0x50]
    //         00438b57     PUSH       EAX
    //         00438b58     LEA        EDX=>param_5,[ESP + 0x50]
    //         00438b5c     PUSH       ECX
    //         00438b5d     MOV        ECX,dword ptr [ESP + param_3]
    //         00438b61     LEA        EAX=>param_4,[ESP + 0x50]
    //         00438b65     PUSH       EDX
    //         00438b66     PUSH       EAX
    //         00438b67     PUSH       ECX
    //         00438b68     PUSH       EBX
    //         00438b69     CALL       ClipDibBlt                                       int ClipDibBlt(BITMAPINFO256 * param_1, tagRE
    //         00438b6e     ADD        ESP,0x30
    //         00438b71     TEST       EAX,EAX
    //         00438b73     JZ         LAB_00438e69
    //                               LAB_00438b79                                                 XREF[1]:     00438b33(j)  
    //                              Dib.cpp:174 (4)
    //         00438b79     MOV        EAX,dword ptr [ESP + param_13]
    //                              Dib.cpp:179 (50)
    //         00438b7d     LEA        ECX=>param_15,[ESP + 0x5c]
    //         00438b81     SHL        EAX,0x8
    //         00438b84     CDQ
    //         00438b85     IDIV       dword ptr [ESP + param_6]
    //         00438b89     MOV        ESI,EAX
    //         00438b8b     MOV        EAX,dword ptr [ESP + param_14]
    //         00438b8f     SHL        EAX,0x8
    //         00438b92     CDQ
    //         00438b93     IDIV       dword ptr [ESP + param_7]
    //         00438b97     LEA        EDX=>DestTotHgt,[ESP + 0x18]
    //         00438b9b     PUSH       EDX
    //         00438b9c     MOV        dword ptr [ESP + DestOrien],EAX
    //         00438ba0     LEA        EAX=>local_4,[ESP + 0x20]
    //         00438ba4     PUSH       EAX
    //         00438ba5     PUSH       ECX
    //         00438ba6     PUSH       EBX
    //         00438ba7     CALL       GetDibDim                                        void GetDibDim(BITMAPINFO256 * param_1, long 
    //         00438bac     ADD        ESP,0x10
    //                              Dib.cpp:180 (28)
    //         00438baf     LEA        EDX=>param_17,[ESP + 0x64]
    //         00438bb3     LEA        EAX=>sySkip,[ESP + 0x10]
    //         00438bb7     LEA        ECX=>param_1,[ESP + 0x24]
    //         00438bbb     PUSH       EDX
    //         00438bbc     MOV        EDX,dword ptr [ESP + param_8]
    //         00438bc0     PUSH       EAX
    //         00438bc1     PUSH       ECX
    //         00438bc2     PUSH       EDX
    //         00438bc3     CALL       GetDibDim                                        void GetDibDim(BITMAPINFO256 * param_1, long 
    //         00438bc8     ADD        ESP,0x10
    //                              Dib.cpp:182 (4)
    //         00438bcb     TEST       EDI,EDI
    //         00438bcd     JZ         LAB_00438bd9
    //                              Dib.cpp:183 (10)
    //         00438bcf     MOV        EAX,dword ptr [ESP + param_17]
    //         00438bd3     NEG        EAX
    //         00438bd5     MOV        dword ptr [ESP + param_17],EAX
    //                               LAB_00438bd9                                                 XREF[1]:     00438bcd(j)  
    //                              Dib.cpp:190 (4)
    //         00438bd9     MOV        EAX,dword ptr [ESP + param_6]
    //                              Dib.cpp:193 (21)
    //         00438bdd     MOV        EBX,dword ptr [ESP + DestTotHgt]
    //         00438be1     SHL        EAX,0x8
    //         00438be4     CDQ
    //         00438be5     IDIV       dword ptr [ESP + param_13]
    //         00438be9     CMP        EBX,0x1
    //         00438bec     MOV        dword ptr [ESP + param_3],EAX
    //         00438bf0     JNZ        LAB_00438bfd
    //                              Dib.cpp:194 (9)
    //         00438bf2     MOV        EDI,dword ptr [ESP + param_15]
    //         00438bf6     IMUL       EDI,dword ptr [ESP + param_5]
    //                              Dib.cpp:195 (2)
    //         00438bfb     JMP        LAB_00438c0d
    //                               LAB_00438bfd                                                 XREF[1]:     00438bf0(j)  
    //                              Dib.cpp:196 (26)
    //         00438bfd     MOV        EDI,dword ptr [ESP + local_4]
    //         00438c01     MOV        EAX,dword ptr [ESP + param_5]
    //         00438c05     SUB        EDI,EAX
    //         00438c07     DEC        EDI
    //         00438c08     IMUL       EDI,dword ptr [ESP + param_15]
    //                               LAB_00438c0d                                                 XREF[1]:     00438bfb(j)  
    //         00438c0d     MOV        ECX,dword ptr [ESP + param_4]
    //         00438c11     MOV        EAX,dword ptr [ESP + param_2]
    //         00438c15     ADD        EDI,ECX
    //                              Dib.cpp:201 (22)
    //         00438c17     MOV        ECX,dword ptr [ESP + param_11]
    //         00438c1b     ADD        EDI,EAX
    //         00438c1d     MOV        EAX,dword ptr [ESP + param_16]
    //         00438c21     TEST       EAX,EAX
    //         00438c23     JNZ        LAB_00438c44
    //         00438c25     MOV        EDX,dword ptr [ESP + param_6]
    //         00438c29     TEST       EDX,EDX
    //         00438c2b     JLE        LAB_00438c6c
    //                              Dib.cpp:273 (5)
    //         00438c2d     MOV        EAX,SrcXTbl                                      = 00000000
    //                               LAB_00438c32                                                 XREF[1]:     00438c40(j)  
    //                              Dib.cpp:202 (16)
    //         00438c32     MOV        EBP,ECX
    //         00438c34     ADD        EAX,0x4
    //         00438c37     SAR        EBP,0x8
    //         00438c3a     MOV        dword ptr [EAX + -0x4]=>SrcXTbl,EBP              = 00000000
    //         00438c3d     ADD        ECX,ESI
    //         00438c3f     DEC        EDX
    //         00438c40     JNZ        LAB_00438c32
    //                              Dib.cpp:204 (2)
    //         00438c42     JMP        LAB_00438c68
    //                               LAB_00438c44                                                 XREF[1]:     00438c23(j)  
    //                              Dib.cpp:206 (12)
    //         00438c44     MOV        EAX,dword ptr [ESP + param_6]
    //         00438c48     LEA        EDX,[EAX + -0x1]
    //         00438c4b     CMP        EDX,-0x1
    //         00438c4e     JLE        LAB_00438c6c
    //                              Dib.cpp:273 (24)
    //         00438c50     LEA        EAX,[EDX*0x4 + SrcXTbl]                          = 00000000
    //         00438c57     INC        EDX
    //                               LAB_00438c58                                                 XREF[1]:     00438c66(j)  
    //         00438c58     MOV        EBP,ECX
    //         00438c5a     SUB        EAX,0x4
    //         00438c5d     SAR        EBP,0x8
    //         00438c60     MOV        dword ptr [EAX + 0x4],EBP=>SrcXTbl               = 00000000
    //         00438c63     ADD        ECX,ESI
    //         00438c65     DEC        EDX
    //         00438c66     JNZ        LAB_00438c58
    //                               LAB_00438c68                                                 XREF[1]:     00438c42(j)  
    //                              Dib.cpp:206 (4)
    //         00438c68     MOV        EBP,dword ptr [ESP + param_10]
    //                               LAB_00438c6c                                                 XREF[2]:     00438c2b(j), 00438c4e(j)  
    //                              Dib.cpp:210 (35)
    //         00438c6c     MOV        EAX,dword ptr [ESP + param_16]
    //         00438c70     TEST       EAX,EAX
    //         00438c72     JNZ        LAB_00438dc2
    //         00438c78     TEST       EBP,EBP
    //         00438c7a     JZ         LAB_00438dc2
    //         00438c80     MOV        EBP,dword ptr [EBP + 0x14]
    //         00438c83     TEST       EBP,EBP
    //         00438c85     MOV        dword ptr [ESP + param_8],EBP
    //         00438c89     JZ         LAB_00438dc2
    //                              Dib.cpp:234 (5)
    //         00438c8f     IMUL       EBX,dword ptr [ESP + param_15]
    //                              Dib.cpp:235 (4)
    //         00438c94     MOV        EAX,dword ptr [ESP + param_12]
    //                              Dib.cpp:236 (37)
    //         00438c98     MOV        ECX,dword ptr [ESP + param_7]
    //         00438c9c     SHL        EAX,0x8
    //         00438c9f     TEST       ECX,ECX
    //         00438ca1     MOV        dword ptr [ESP + param_15],EBX
    //         00438ca5     MOV        dword ptr [ESP + param_10],EAX
    //         00438ca9     MOV        dword ptr [ESP + param_16],0x0
    //         00438cb1     JLE        LAB_00438e69
    //         00438cb7     JMP        LAB_00438cbd
    //                               LAB_00438cb9                                                 XREF[1]:     00438db4(j)  
    //         00438cb9     MOV        EBP,dword ptr [ESP + param_8]
    //                               LAB_00438cbd                                                 XREF[1]:     00438cb7(j)  
    //                              Dib.cpp:239 (12)
    //         00438cbd     MOV        ECX,dword ptr [ESP + param_17]
    //         00438cc1     SAR        EAX,0x8
    //         00438cc4     CMP        ECX,0x1
    //         00438cc7     JNZ        LAB_00438cde
    //                              Dib.cpp:240 (19)
    //         00438cc9     MOV        ECX,EAX
    //         00438ccb     MOV        EBX,dword ptr [ESP + param_11]
    //         00438ccf     IMUL       ECX,dword ptr [ESP + param_1]
    //         00438cd4     MOV        EDX,dword ptr [ESP + param_9]
    //         00438cd8     ADD        ECX,EBX
    //         00438cda     ADD        ECX,EDX
    //                              Dib.cpp:241 (2)
    //         00438cdc     JMP        LAB_00438cf8
    //                               LAB_00438cde                                                 XREF[1]:     00438cc7(j)  
    //                              Dib.cpp:242 (26)
    //         00438cde     MOV        ECX,dword ptr [ESP + sySkip]
    //         00438ce2     MOV        ESI,dword ptr [ESP + param_11]
    //         00438ce6     SUB        ECX,EAX
    //         00438ce8     MOV        EDX,dword ptr [ESP + param_9]
    //         00438cec     DEC        ECX
    //         00438ced     MOV        EBX,ESI
    //         00438cef     IMUL       ECX,dword ptr [ESP + param_1]
    //         00438cf4     ADD        ECX,ESI
    //         00438cf6     ADD        ECX,EDX
    //                               LAB_00438cf8                                                 XREF[1]:     00438cdc(j)  
    //                              Dib.cpp:243 (17)
    //         00438cf8     SHL        EAX,0x4
    //         00438cfb     LEA        ESI,[EAX + EBP*0x1]
    //         00438cfe     MOV        EAX,dword ptr [EAX + EBP*0x1]
    //         00438d01     TEST       EAX,EAX
    //         00438d03     JNZ        LAB_00438d91
    //                              Dib.cpp:245 (3)
    //         00438d09     MOV        EDX,dword ptr [ESI + 0x8]
    //                              Dib.cpp:246 (4)
    //         00438d0c     CMP        EDX,EBX
    //         00438d0e     JGE        LAB_00438d18
    //                              Dib.cpp:248 (8)
    //         00438d10     MOV        EBP,dword ptr [ESP + param_3]
    //         00438d14     XOR        EDX,EDX
    //         00438d16     JMP        LAB_00438d24
    //                               LAB_00438d18                                                 XREF[1]:     00438d0e(j)  
    //                              Dib.cpp:249 (12)
    //         00438d18     MOV        EBP,dword ptr [ESP + param_3]
    //         00438d1c     SUB        EDX,EBX
    //         00438d1e     IMUL       EDX,EBP
    //         00438d21     SAR        EDX,0x8
    //                               LAB_00438d24                                                 XREF[1]:     00438d16(j)  
    //                              Dib.cpp:251 (5)
    //         00438d24     MOV        EAX,dword ptr [ESI + 0xc]
    //         00438d27     SUB        EAX,EBX
    //                              Dib.cpp:252 (15)
    //         00438d29     MOV        EBX,dword ptr [ESP + param_6]
    //         00438d2d     INC        EAX
    //         00438d2e     IMUL       EAX,EBP
    //         00438d31     SAR        EAX,0x8
    //         00438d34     CMP        EAX,EBX
    //         00438d36     JLE        LAB_00438d3a
    //                              Dib.cpp:253 (2)
    //         00438d38     MOV        EAX,EBX
    //                               LAB_00438d3a                                                 XREF[1]:     00438d36(j)  
    //                              Dib.cpp:255 (4)
    //         00438d3a     CMP        EAX,EDX
    //         00438d3c     JLE        LAB_00438d91
    //                              Dib.cpp:257 (15)
    //         00438d3e     CMP        EBP,0x100
    //         00438d44     JNZ        LAB_00438d60
    //         00438d46     MOV        EBX,dword ptr [ESI + 0x4]
    //         00438d49     TEST       EBX,EBX
    //         00438d4b     JZ         LAB_00438d60
    //                              Dib.cpp:258 (17)
    //         00438d4d     SUB        EAX,EDX
    //         00438d4f     ADD        ECX,EDX
    //         00438d51     PUSH       EAX
    //         00438d52     ADD        EDX,EDI
    //         00438d54     PUSH       ECX
    //         00438d55     PUSH       EDX
    //         00438d56     CALL       memcpy                                           undefined memcpy()
    //         00438d5b     ADD        ESP,0xc
    //                              Dib.cpp:259 (2)
    //         00438d5e     JMP        LAB_00438d91
    //                               LAB_00438d60                                                 XREF[2]:     00438d44(j), 00438d4b(j)  
    //                              Dib.cpp:261 (13)
    //         00438d60     CMP        EDX,EAX
    //         00438d62     MOV        ESI,EDX
    //         00438d64     JGE        LAB_00438d91
    //         00438d66     LEA        EBX,[EDX*0x4 + SrcXTbl]                          = 00000000
    //                               LAB_00438d6d                                                 XREF[1]:     00438d8f(j)  
    //                              Dib.cpp:263 (25)
    //         00438d6d     MOV        EDX,dword ptr [EBX]=>SrcXTbl                     = 00000000
    //         00438d6f     MOV        DL,byte ptr [ECX + EDX*0x1]
    //         00438d72     MOV        byte ptr [ESP + param_2],DL
    //         00438d76     MOV        EBP,dword ptr [ESP + param_2]
    //         00438d7a     AND        EBP,0xff
    //         00438d80     CMP        EBP,dword ptr [ESP + param_18]
    //         00438d84     JZ         LAB_00438d89
    //                              Dib.cpp:264 (3)
    //         00438d86     MOV        byte ptr [ESI + EDI*0x1],DL
    //                               LAB_00438d89                                                 XREF[1]:     00438d84(j)  
    //                              Dib.cpp:261 (8)
    //         00438d89     INC        ESI
    //         00438d8a     ADD        EBX,0x4
    //         00438d8d     CMP        ESI,EAX
    //         00438d8f     JL         LAB_00438d6d
    //                               LAB_00438d91                                                 XREF[4]:     00438d03(j), 00438d3c(j), 
    //                                                                                                         00438d5e(j), 00438d64(j)  
    //                              Dib.cpp:269 (4)
    //         00438d91     MOV        EBP,dword ptr [ESP + param_15]
    //                              Dib.cpp:270 (37)
    //         00438d95     MOV        EAX,dword ptr [ESP + param_10]
    //         00438d99     MOV        EBX,dword ptr [ESP + DestOrien]
    //         00438d9d     MOV        ECX,dword ptr [ESP + param_16]
    //         00438da1     MOV        EDX,dword ptr [ESP + param_7]
    //         00438da5     ADD        EDI,EBP
    //         00438da7     ADD        EAX,EBX
    //         00438da9     INC        ECX
    //         00438daa     CMP        ECX,EDX
    //         00438dac     MOV        dword ptr [ESP + param_10],EAX
    //         00438db0     MOV        dword ptr [ESP + param_16],ECX
    //         00438db4     JL         LAB_00438cb9
    //                              Dib.cpp:273 (8)
    //         00438dba     POP        EDI
    //         00438dbb     POP        ESI
    //         00438dbc     POP        EBP
    //         00438dbd     POP        EBX
    //         00438dbe     ADD        ESP,0x10
    //         00438dc1     RET
    //                               LAB_00438dc2                                                 XREF[3]:     00438c72(j), 00438c7a(j), 
    //                                                                                                         00438c89(j)  
    //                              Dib.cpp:213 (5)
    //         00438dc2     IMUL       EBX,dword ptr [ESP + param_15]
    //                              Dib.cpp:215 (35)
    //         00438dc7     MOV        EAX,dword ptr [ESP + param_7]
    //         00438dcb     MOV        dword ptr [ESP + param_15],EBX
    //         00438dcf     MOV        EBX,dword ptr [ESP + param_12]
    //         00438dd3     MOV        dword ptr [ESP + param_16],0x0
    //         00438ddb     SHL        EBX,0x8
    //         00438dde     TEST       EAX,EAX
    //         00438de0     JLE        LAB_00438e69
    //         00438de6     MOV        EDX,dword ptr [ESP + param_9]
    //                               LAB_00438dea                                                 XREF[1]:     00438e67(j)  
    //                              Dib.cpp:217 (7)
    //         00438dea     CMP        dword ptr [ESP + param_17],0x1
    //         00438def     JNZ        LAB_00438df8
    //                              Dib.cpp:218 (5)
    //         00438df1     MOV        EAX,EBX
    //         00438df3     SAR        EAX,0x8
    //                              Dib.cpp:219 (2)
    //         00438df6     JMP        LAB_00438e04
    //                               LAB_00438df8                                                 XREF[1]:     00438def(j)  
    //                              Dib.cpp:220 (21)
    //         00438df8     MOV        EAX,dword ptr [ESP + sySkip]
    //         00438dfc     MOV        ECX,EBX
    //         00438dfe     SAR        ECX,0x8
    //         00438e01     SUB        EAX,ECX
    //         00438e03     DEC        EAX
    //                               LAB_00438e04                                                 XREF[1]:     00438df6(j)  
    //         00438e04     IMUL       EAX,dword ptr [ESP + param_1]
    //         00438e09     MOV        ESI,dword ptr [ESP + param_11]
    //                              Dib.cpp:221 (19)
    //         00438e0d     XOR        ECX,ECX
    //         00438e0f     ADD        EAX,ESI
    //         00438e11     MOV        ESI,dword ptr [ESP + param_6]
    //         00438e15     ADD        EAX,EDX
    //         00438e17     TEST       ESI,ESI
    //         00438e19     JLE        LAB_00438e4c
    //         00438e1b     MOV        ESI,SrcXTbl                                      = 00000000
    //                               LAB_00438e20                                                 XREF[1]:     00438e46(j)  
    //                              Dib.cpp:223 (25)
    //         00438e20     MOV        EDX,dword ptr [ESI]=>SrcXTbl                     = 00000000
    //         00438e22     MOV        DL,byte ptr [EAX + EDX*0x1]
    //         00438e25     MOV        byte ptr [ESP + param_2],DL
    //         00438e29     MOV        EBP,dword ptr [ESP + param_2]
    //         00438e2d     AND        EBP,0xff
    //         00438e33     CMP        EBP,dword ptr [ESP + param_18]
    //         00438e37     JZ         LAB_00438e3c
    //                              Dib.cpp:224 (3)
    //         00438e39     MOV        byte ptr [ECX + EDI*0x1],DL
    //                               LAB_00438e3c                                                 XREF[1]:     00438e37(j)  
    //                              Dib.cpp:221 (16)
    //         00438e3c     MOV        EDX,dword ptr [ESP + param_6]
    //         00438e40     INC        ECX
    //         00438e41     ADD        ESI,0x4
    //         00438e44     CMP        ECX,EDX
    //         00438e46     JL         LAB_00438e20
    //         00438e48     MOV        EDX,dword ptr [ESP + param_9]
    //                               LAB_00438e4c                                                 XREF[1]:     00438e19(j)  
    //                              Dib.cpp:226 (4)
    //         00438e4c     MOV        EAX,dword ptr [ESP + param_15]
    //                              Dib.cpp:227 (25)
    //         00438e50     MOV        EBP,dword ptr [ESP + DestOrien]
    //         00438e54     MOV        ECX,dword ptr [ESP + param_7]
    //         00438e58     ADD        EDI,EAX
    //         00438e5a     MOV        EAX,dword ptr [ESP + param_16]
    //         00438e5e     ADD        EBX,EBP
    //         00438e60     INC        EAX
    //         00438e61     CMP        EAX,ECX
    //         00438e63     MOV        dword ptr [ESP + param_16],EAX
    //         00438e67     JL         LAB_00438dea
    //                               LAB_00438e69                                                 XREF[3]:     00438b73(j), 00438cb1(j), 
    //                                                                                                         00438de0(j)  
    //                              Dib.cpp:273 (8)
    //         00438e69     POP        EDI
    //         00438e6a     POP        ESI
    //         00438e6b     POP        EBP
    //         00438e6c     POP        EBX
    //         00438e6d     ADD        ESP,0x10
    //         00438e70     RET
    //         00438e71     ??         90h
    //         00438e72     NOP
    //         00438e73     NOP
    //         00438e74     NOP
    //         00438e75     NOP
    //         00438e76     NOP
    //         00438e77     NOP
    //         00438e78     NOP
    //         00438e79     NOP
    //         00438e7a     NOP
    //         00438e7b     NOP
    //         00438e7c     NOP
    //         00438e7d     NOP
    //         00438e7e     NOP
    //         00438e7f     NOP
    //                              * int __cdecl ClipDibBlt(struct BITMAPINFO256 *,struct tagRECT *,long &,long &,long &,long &,long &,... *
    //                              int __cdecl ClipDibBlt(BITMAPINFO256 * param_1, tagRECT * param_2, l
    //              int               EAX:4          <RETURN>
    //              BITMAPINFO256 *   Stack[0x4]:4   param_1                   XREF[3]:     00438e9c(R), 00438eb6(W), 00438faa(R)  
    //              tagRECT *         Stack[0x8]:4   param_2                   XREF[4]:     00438e81(R), 00438f28(W), 00438f80(R), 00439008(R)  
    //              long *            Stack[0xc]:4   param_3                   XREF[3]:     00438eb0(R), 00438f2e(R), 00438fa4(R)  
    //              long *            Stack[0x10]:4  param_4                   XREF[3]:     00438ec8(R), 00438f65(R), 00438fe7(R)  
    //              long *            Stack[0x14]:4  param_5                   XREF[3]:     00438ed6(R), 00438f38(R), 00438f61(R)  
    //              long *            Stack[0x18]:4  param_6                   XREF[3]:     00438ee8(R), 00438f71(R), 00438fa0(R)  
    //              long *            Stack[0x1c]:4  param_7                   XREF[2]:     00438f53(R), 00438fdb(R)  
    //              long *            Stack[0x20]:4  param_8                   XREF[2]:     00438f92(R), 00439020(R)  
    //              long *            Stack[0x24]:4  param_9                   XREF[4]:     00438f0c(R), 00438f59(R), 00438fbb(R), 00438fe3(R)  
    //              long *            Stack[0x28]:4  param_10                  XREF[4]:     00438f18(R), 00438f98(R), 0043900f(R), 00439028(R)  
    //              int               Stack[0x2c]:4  param_11                  XREF[2]:     00438f48(R), 00438fcc(R)  
    //              int               Stack[0x30]:4  param_12                  XREF[2]:     00438f87(R), 00438ffe(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     00438ebc(W), 00438fed(R)  
    //              long              Stack[-0x8]:4  ey
    //                               ?ClipDibBlt@@YAHPAUBITMAPINFO256@@PAUtagRECT@@AAJ2222222HH@Z XREF[2]:     DibBlt:0043886b(c), 
    //                               ClipDibBlt                                                                TransDibBlt:00438b69(c)  
    //                              Dib.cpp:280 (1)
    //         00438e80     PUSH       ECX
    //                              Dib.cpp:284 (12)
    //         00438e81     MOV        EAX,dword ptr [ESP + param_2]
    //         00438e85     PUSH       EBX
    //         00438e86     PUSH       EBP
    //         00438e87     PUSH       ESI
    //         00438e88     TEST       EAX,EAX
    //         00438e8a     PUSH       EDI
    //         00438e8b     JZ         LAB_00438e9c
    //                              Dib.cpp:286 (2)
    //         00438e8d     MOV        ESI,dword ptr [EAX]
    //                              Dib.cpp:287 (3)
    //         00438e8f     MOV        EBX,dword ptr [EAX + 0x4]
    //                              Dib.cpp:288 (3)
    //         00438e92     MOV        ECX,dword ptr [EAX + 0x8]
    //                              Dib.cpp:289 (5)
    //         00438e95     MOV        EAX,dword ptr [EAX + 0xc]
    //         00438e98     INC        ECX
    //         00438e99     INC        EAX
    //                              Dib.cpp:291 (2)
    //         00438e9a     JMP        LAB_00438eaa
    //                               LAB_00438e9c                                                 XREF[1]:     00438e8b(j)  
    //                              Dib.cpp:295 (11)
    //         00438e9c     MOV        EAX,dword ptr [ESP + param_1]
    //         00438ea0     XOR        ESI,ESI
    //         00438ea2     XOR        EBX,EBX
    //         00438ea4     MOV        ECX,dword ptr [EAX + 0x4]
    //                              Dib.cpp:296 (3)
    //         00438ea7     MOV        EAX,dword ptr [EAX + 0x8]
    //                               LAB_00438eaa                                                 XREF[1]:     00438e9a(j)  
    //                              Dib.cpp:299 (6)
    //         00438eaa     TEST       EAX,EAX
    //         00438eac     JGE        LAB_00438eb0
    //         00438eae     NEG        EAX
    //                               LAB_00438eb0                                                 XREF[1]:     00438eac(j)  
    //                              Dib.cpp:304 (92)
    //         00438eb0     MOV        EDX,dword ptr [ESP + param_3]
    //         00438eb4     DEC        ECX
    //         00438eb5     DEC        EAX
    //         00438eb6     MOV        dword ptr [ESP + param_1],ECX
    //         00438eba     MOV        EDI,dword ptr [EDX]
    //         00438ebc     MOV        dword ptr [ESP + local_4],EAX
    //         00438ec0     CMP        EDI,ECX
    //         00438ec2     JG         LAB_0043904b
    //         00438ec8     MOV        ECX,dword ptr [ESP + param_4]
    //         00438ecc     MOV        EDX,dword ptr [ECX]
    //         00438ece     CMP        EDX,EAX
    //         00438ed0     JG         LAB_0043904b
    //         00438ed6     MOV        EAX,dword ptr [ESP + param_5]
    //         00438eda     MOV        EBP,dword ptr [EAX]
    //         00438edc     LEA        ECX,[EBP + EDI*0x1 + -0x1]
    //         00438ee0     CMP        ECX,ESI
    //         00438ee2     JL         LAB_0043904b
    //         00438ee8     MOV        EAX,dword ptr [ESP + param_6]
    //         00438eec     MOV        ECX,dword ptr [EAX]
    //         00438eee     LEA        EDX,[ECX + EDX*0x1 + -0x1]
    //         00438ef2     CMP        EDX,EBX
    //         00438ef4     JL         LAB_0043904b
    //         00438efa     CMP        EBP,0x1
    //         00438efd     JL         LAB_0043904b
    //         00438f03     CMP        ECX,0x1
    //         00438f06     JL         LAB_0043904b
    //                              Dib.cpp:308 (12)
    //         00438f0c     MOV        EAX,dword ptr [ESP + param_9]
    //         00438f10     MOV        EAX,dword ptr [EAX]
    //         00438f12     SHL        EAX,0x8
    //         00438f15     CDQ
    //         00438f16     IDIV       EBP
    //                              Dib.cpp:309 (14)
    //         00438f18     MOV        EDX,dword ptr [ESP + param_10]
    //         00438f1c     MOV        EBP,EAX
    //         00438f1e     MOV        EAX,dword ptr [EDX]
    //         00438f20     SHL        EAX,0x8
    //         00438f23     CDQ
    //         00438f24     IDIV       ECX
    //                              Dib.cpp:314 (8)
    //         00438f26     CMP        EDI,ESI
    //         00438f28     MOV        dword ptr [ESP + param_2],EAX
    //         00438f2c     JGE        LAB_00438f61
    //                              Dib.cpp:317 (10)
    //         00438f2e     MOV        EAX,dword ptr [ESP + param_3]
    //         00438f32     MOV        ECX,ESI
    //         00438f34     SUB        ECX,EDI
    //         00438f36     MOV        dword ptr [EAX],ESI
    //                              Dib.cpp:318 (8)
    //         00438f38     MOV        EAX,dword ptr [ESP + param_5]
    //         00438f3c     MOV        EDX,dword ptr [EAX]
    //         00438f3e     SUB        EDX,ECX
    //                              Dib.cpp:320 (8)
    //         00438f40     SHL        ECX,0x8
    //         00438f43     IMUL       ECX,EBP
    //         00438f46     MOV        dword ptr [EAX],EDX
    //                              Dib.cpp:321 (11)
    //         00438f48     MOV        EDX,dword ptr [ESP + param_11]
    //         00438f4c     SAR        ECX,0x10
    //         00438f4f     TEST       EDX,EDX
    //         00438f51     JNZ        LAB_00438f59
    //                              Dib.cpp:322 (6)
    //         00438f53     MOV        EDX,dword ptr [ESP + param_7]
    //         00438f57     ADD        dword ptr [EDX],ECX
    //                               LAB_00438f59                                                 XREF[1]:     00438f51(j)  
    //                              Dib.cpp:323 (12)
    //         00438f59     MOV        EDX,dword ptr [ESP + param_9]
    //         00438f5d     SUB        dword ptr [EDX],ECX
    //         00438f5f     JMP        LAB_00438f65
    //                               LAB_00438f61                                                 XREF[1]:     00438f2c(j)  
    //         00438f61     MOV        EAX,dword ptr [ESP + param_5]
    //                               LAB_00438f65                                                 XREF[1]:     00438f5f(j)  
    //                              Dib.cpp:326 (10)
    //         00438f65     MOV        ESI,dword ptr [ESP + param_4]
    //         00438f69     MOV        EDX,dword ptr [ESI]
    //         00438f6b     CMP        EDX,EBX
    //         00438f6d     JGE        LAB_00438fa0
    //                              Dib.cpp:329 (2)
    //         00438f6f     MOV        dword ptr [ESI],EBX
    //                              Dib.cpp:330 (12)
    //         00438f71     MOV        ESI,dword ptr [ESP + param_6]
    //         00438f75     MOV        ECX,EBX
    //         00438f77     SUB        ECX,EDX
    //         00438f79     MOV        EDX,dword ptr [ESI]
    //         00438f7b     SUB        EDX,ECX
    //                              Dib.cpp:332 (10)
    //         00438f7d     SHL        ECX,0x8
    //         00438f80     IMUL       ECX,dword ptr [ESP + param_2]
    //         00438f85     MOV        dword ptr [ESI],EDX
    //                              Dib.cpp:333 (11)
    //         00438f87     MOV        EDX,dword ptr [ESP + param_12]
    //         00438f8b     SAR        ECX,0x10
    //         00438f8e     TEST       EDX,EDX
    //         00438f90     JNZ        LAB_00438f98
    //                              Dib.cpp:334 (6)
    //         00438f92     MOV        EDX,dword ptr [ESP + param_8]
    //         00438f96     ADD        dword ptr [EDX],ECX
    //                               LAB_00438f98                                                 XREF[1]:     00438f90(j)  
    //                              Dib.cpp:335 (12)
    //         00438f98     MOV        EDX,dword ptr [ESP + param_10]
    //         00438f9c     SUB        dword ptr [EDX],ECX
    //         00438f9e     JMP        LAB_00438fa4
    //                               LAB_00438fa0                                                 XREF[1]:     00438f6d(j)  
    //         00438fa0     MOV        ESI,dword ptr [ESP + param_6]
    //                               LAB_00438fa4                                                 XREF[1]:     00438f9e(j)  
    //                              Dib.cpp:338 (21)
    //         00438fa4     MOV        ECX,dword ptr [ESP + param_3]
    //         00438fa8     MOV        EDX,dword ptr [EAX]
    //         00438faa     MOV        EDI,dword ptr [ESP + param_1]
    //         00438fae     MOV        ECX,dword ptr [ECX]
    //         00438fb0     ADD        ECX,EDX
    //         00438fb2     LEA        EBX,[ECX + -0x1]
    //         00438fb5     CMP        EBX,EDI
    //         00438fb7     JLE        LAB_00438fe3
    //                              Dib.cpp:340 (2)
    //         00438fb9     SUB        ECX,EDI
    //                              Dib.cpp:344 (17)
    //         00438fbb     MOV        EBX,dword ptr [ESP + param_9]
    //         00438fbf     DEC        ECX
    //         00438fc0     SUB        EDX,ECX
    //         00438fc2     SHL        ECX,0x8
    //         00438fc5     IMUL       ECX,EBP
    //         00438fc8     MOV        dword ptr [EAX],EDX
    //         00438fca     MOV        EDI,dword ptr [EBX]
    //                              Dib.cpp:345 (15)
    //         00438fcc     MOV        EDX,dword ptr [ESP + param_11]
    //         00438fd0     SAR        ECX,0x10
    //         00438fd3     SUB        EDI,ECX
    //         00438fd5     TEST       EDX,EDX
    //         00438fd7     MOV        dword ptr [EBX],EDI
    //         00438fd9     JZ         LAB_00438fe7
    //                              Dib.cpp:346 (12)
    //         00438fdb     MOV        EDX,dword ptr [ESP + param_7]
    //         00438fdf     ADD        dword ptr [EDX],ECX
    //         00438fe1     JMP        LAB_00438fe7
    //                               LAB_00438fe3                                                 XREF[1]:     00438fb7(j)  
    //         00438fe3     MOV        EBX,dword ptr [ESP + param_9]
    //                               LAB_00438fe7                                                 XREF[2]:     00438fd9(j), 00438fe1(j)  
    //                              Dib.cpp:349 (21)
    //         00438fe7     MOV        ECX,dword ptr [ESP + param_4]
    //         00438feb     MOV        EDX,dword ptr [ESI]
    //         00438fed     MOV        EDI,dword ptr [ESP + local_4]
    //         00438ff1     MOV        ECX,dword ptr [ECX]
    //         00438ff3     ADD        ECX,EDX
    //         00438ff5     LEA        EBP,[ECX + -0x1]
    //         00438ff8     CMP        EBP,EDI
    //         00438ffa     JLE        LAB_00439028
    //                              Dib.cpp:351 (2)
    //         00438ffc     SUB        ECX,EDI
    //                              Dib.cpp:356 (34)
    //         00438ffe     MOV        EDI,dword ptr [ESP + param_12]
    //         00439002     DEC        ECX
    //         00439003     SUB        EDX,ECX
    //         00439005     SHL        ECX,0x8
    //         00439008     IMUL       ECX,dword ptr [ESP + param_2]
    //         0043900d     MOV        dword ptr [ESI],EDX
    //         0043900f     MOV        EDX,dword ptr [ESP + param_10]
    //         00439013     SAR        ECX,0x10
    //         00439016     MOV        EBP,dword ptr [EDX]
    //         00439018     SUB        EBP,ECX
    //         0043901a     TEST       EDI,EDI
    //         0043901c     MOV        dword ptr [EDX],EBP
    //         0043901e     JZ         LAB_0043902c
    //                              Dib.cpp:357 (12)
    //         00439020     MOV        EDI,dword ptr [ESP + param_8]
    //         00439024     ADD        dword ptr [EDI],ECX
    //         00439026     JMP        LAB_0043902c
    //                               LAB_00439028                                                 XREF[1]:     00438ffa(j)  
    //         00439028     MOV        EDX,dword ptr [ESP + param_10]
    //                               LAB_0043902c                                                 XREF[2]:     0043901e(j), 00439026(j)  
    //                              Dib.cpp:361 (20)
    //         0043902c     CMP        dword ptr [EAX],0x1
    //         0043902f     JL         LAB_0043904b
    //         00439031     CMP        dword ptr [ESI],0x1
    //         00439034     JL         LAB_0043904b
    //         00439036     CMP        dword ptr [EBX],0x1
    //         00439039     JL         LAB_0043904b
    //         0043903b     CMP        dword ptr [EDX],0x1
    //         0043903e     JL         LAB_0043904b
    //                              Dib.cpp:365 (5)
    //         00439040     MOV        EAX,0x1
    //                              Dib.cpp:366 (14)
    //         00439045     POP        EDI
    //         00439046     POP        ESI
    //         00439047     POP        EBP
    //         00439048     POP        EBX
    //         00439049     POP        ECX
    //         0043904a     RET
    //                               LAB_0043904b                                                 XREF[10]:    00438ec2(j), 00438ed0(j), 
    //                                                                                                         00438ee2(j), 00438ef4(j), 
    //                                                                                                         00438efd(j), 00438f06(j), 
    //                                                                                                         0043902f(j), 00439034(j), 
    //                                                                                                         00439039(j), 0043903e(j)  
    //         0043904b     POP        EDI
    //         0043904c     POP        ESI
    //         0043904d     POP        EBP
    //         0043904e     XOR        EAX,EAX
    //         00439050     POP        EBX
    //         00439051     POP        ECX
    //         00439052     RET
    //         00439053     ??         90h
    //         00439054     NOP
    //         00439055     NOP
    //         00439056     NOP
    //         00439057     NOP
    //         00439058     NOP
    //         00439059     NOP
    //         0043905a     NOP
    //         0043905b     NOP
    //         0043905c     NOP
    //         0043905d     NOP
    //         0043905e     NOP
    //         0043905f     NOP
    //                              * void __cdecl GetDibDim(struct BITMAPINFO256 *,long &,long &,long &)                                   *
    //                              void __cdecl GetDibDim(BITMAPINFO256 * param_1, long * param_2, long
    //              void              <VOID>         <RETURN>
    //              BITMAPINFO256 *   Stack[0x4]:4   param_1                   XREF[1]:     00439060(R)  
    //              long *            Stack[0x8]:4   param_2                   XREF[1]:     00439064(R)  
    //              long *            Stack[0xc]:4   param_3                   XREF[1]:     00439076(R)  
    //              long *            Stack[0x10]:4  param_4                   XREF[2]:     00439084(R), 0043908f(R)  
    //                               ?GetDibDim@@YAXPAUBITMAPINFO256@@AAJ11@Z                     XREF[5]:     DibBlt:0043888b(c), 
    //                               GetDibDim                                                                 DibBlt:004388a7(c), 
    //                                                                                                         TransDibBlt:00438ba7(c), 
    //                                                                                                         TransDibBlt:00438bc3(c), 
    //                                                                                                         DibCheckTrans:004395b9(c)  
    //                              Dib.cpp:372 (19)
    //         00439060     MOV        EAX,dword ptr [ESP + param_1]
    //         00439064     MOV        EDX,dword ptr [ESP + param_2]
    //         00439068     MOV        ECX,dword ptr [EAX + 0x4]
    //         0043906b     ADD        ECX,0x3
    //         0043906e     AND        ECX,0xfffffffc
    //         00439071     MOV        dword ptr [EDX],ECX
    //                              Dib.cpp:375 (7)
    //         00439073     MOV        EAX,dword ptr [EAX + 0x8]
    //         00439076     MOV        ECX,dword ptr [ESP + param_3]
    //                              Dib.cpp:376 (6)
    //         0043907a     TEST       EAX,EAX
    //         0043907c     MOV        dword ptr [ECX],EAX
    //         0043907e     JGE        LAB_0043908f
    //                              Dib.cpp:378 (4)
    //         00439080     NEG        EAX
    //         00439082     MOV        dword ptr [ECX],EAX
    //                              Dib.cpp:379 (10)
    //         00439084     MOV        EAX,dword ptr [ESP + param_4]
    //         00439088     MOV        dword ptr [EAX],0x1
    //                              Dib.cpp:383 (1)
    //         0043908e     RET
    //                               LAB_0043908f                                                 XREF[1]:     0043907e(j)  
    //                              Dib.cpp:382 (10)
    //         0043908f     MOV        ECX,dword ptr [ESP + param_4]
    //         00439093     MOV        dword ptr [ECX],0xffffffff
    //                              Dib.cpp:383 (1)
    //         00439099     RET
    //         0043909a     ??         90h
    //         0043909b     NOP
    //         0043909c     NOP
    //         0043909d     NOP
    //         0043909e     NOP
    //         0043909f     NOP
    //                              * long __cdecl TileDibBlt(struct BITMAPINFO256 *,unsigned char *,struct tagRECT *,long,long,long,lon... *
    //                              long __cdecl TileDibBlt(BITMAPINFO256 * param_1, uchar * param_2, ta
    //              long              EAX:4          <RETURN>
    //              BITMAPINFO256 *   Stack[0x4]:4   param_1                   XREF[8]:     00439238(R), 004392a1(R), 00439302(R), 00439360(R), 
    //                                                                                     00439428(R), 0043948d(R), 004394e4(R), 00439538(R)  
    //              uchar *           Stack[0x8]:4   param_2                   XREF[8]:     0043923d(R), 0043929c(R), 004392f4(R), 0043935b(R), 
    //                                                                                     0043942d(R), 00439488(R), 004394d9(R), 00439533(R)  
    //              tagRECT *         Stack[0xc]:4   param_3                   XREF[8]:     00439243(R), 0043928e(R), 004392ef(R), 0043934a(R), 
    //                                                                                     00439433(R), 00439477(R), 004394de(R), 00439525(R)  
    //              long              Stack[0x10]:4  param_4                   XREF[2]:     004391e7(R), 004393de(R)  
    //              long              Stack[0x14]:4  param_5                   XREF[8]:     004391b6(R), 004391c6(W), 00439293(R), 00439380(R), 
    //                                                                                     0043939a(W), 004393e2(W), 004394d4(R), 0043952a(R)  
    //              long              Stack[0x18]:4  param_6                   XREF[8]:     00439135(R), 00439174(W), 00439181(W), 0043918d(W), 
    //                                                                                     004391ef(R), 004393ac(R), 004393e6(R), 00439584(R)  
    //              long              Stack[0x1c]:4  param_7                   XREF[9]:     00439169(R), 00439191(R), 0043919e(W), 004391a9(R), 
    //                                                                                     004391ae(W), 004391c2(R), 004393a8(R), 004393b9(R), 
    //                                                                                     00439580(R)  
    //              long              Stack[0x20]:4  param_8                   XREF[3]:     004390ab(R), 00439376(R), 0043954e(R)  
    //              long              Stack[0x24]:4  param_9                   XREF[5]:     004390c5(R), 00439147(R), 00439195(R), 0043938f(R), 
    //                                                                                     00439567(R)  
    //              BITMAPINFO256 *   Stack[0x28]:4  param_10                  XREF[8]:     00439233(R), 00439289(R), 004392ea(R), 00439345(R), 
    //                                                                                     00439423(R), 00439472(R), 004394cf(R), 00439520(R)  
    //              uchar *           Stack[0x2c]:4  param_11                  XREF[8]:     0043922e(R), 00439284(R), 004392e5(R), 00439340(R), 
    //                                                                                     0043941e(R), 0043946d(R), 004394ca(R), 0043951b(R)  
    //              TRANSINFO *       Stack[0x30]:4  param_12                  XREF[8]:     00439229(R), 0043927f(R), 004392e0(R), 0043933b(R), 
    //                                                                                     004393bd(W), 0043947c(R), 00439558(R), 00439572(W)  
    //              long              Stack[0x34]:4  param_13                  XREF[7]:     004390c9(R), 004390d7(W), 004390f3(W), 00439224(R), 
    //                                                                                     004392db(R), 00439419(R), 004394c5(R)  
    //              long              Stack[0x38]:4  param_14                  XREF[7]:     004390db(R), 004390e5(W), 00439101(W), 0043921f(R), 
    //                                                                                     00439275(R), 00439414(R), 00439463(R)  
    //              long              Stack[0x3c]:4  param_15                  XREF[12]:    004390a3(R), 004390bb(W), 00439123(R), 00439150(W), 
    //                                                                                     00439250(R), 004392ad(R), 0043930f(R), 0043936c(R), 
    //                                                                                     00439440(R), 00439499(R), 004394f1(R), 00439544(R)  
    //              long              Stack[0x40]:4  param_16                  XREF[10]:    004390b6(R), 004390cf(W), 00439143(R), 0043915f(W), 
    //                                                                                     004391e0(R), 004391ff(R), 00439257(R), 004393d7(R), 
    //                                                                                     004393f6(R), 00439447(R)  
    //              int               Stack[0x44]:4  param_17                  XREF[7]:     004391b2(R), 004391da(W), 00439393(R), 0043939e(W), 
    //                                                                                     004393d1(W), 0043956b(R), 00439576(W)  
    //              int               Stack[0x48]:4  param_18                  XREF[5]:     004391d6(R), 004391fb(W), 0043937a(R), 00439385(W), 
    //                                                                                     004393cd(R)  
    //              int               Stack[0x4c]:4  param_19                  XREF[8]:     004391d2(R), 004391eb(W), 004392f9(R), 0043934f(R), 
    //                                                                                     004393c9(R), 004393f2(W), 00439552(R), 0043955d(W)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[5]:     0043911a(W), 0043927a(R), 00439336(R), 00439468(R), 
    //                                                                                     00439516(R)  
    //              undefined4        Stack[-0x8]:4  local_8                   XREF[5]:     00439131(W), 004392d6(R), 00439331(R), 004394c0(R), 
    //                                                                                     00439511(R)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[5]:     0043912d(W), 00439270(R), 0043932c(R), 0043945e(R), 
    //                                                                                     0043950c(R)  
    //              long              Stack[-0x10]:4 SrcLtWid                  XREF[5]:     0043911e(W), 004392c7(R), 00439321(R), 004394b3(R), 
    //                                                                                     00439503(R)  
    //              long              Stack[-0x14]:4 SrcTopHgt                 XREF[5]:     00439163(W), 004392b7(R), 00439316(R), 004394a3(R), 
    //                                                                                     004394f8(R)  
    //              long              Stack[-0x18]:4 DestBotHgt                XREF[5]:     0043910f(W), 0043921a(R), 004392cb(R), 0043940f(R), 
    //                                                                                     004394b7(R)  
    //              long              Stack[-0x1c]:4 SrcRtWid                  XREF[5]:     00439129(W), 0043920f(R), 00439265(R), 00439406(R), 
    //                                                                                     00439455(R)  
    //              long              Stack[-0x20]:4 SrcBotHgt
    //                               ?TileDibBlt@@YAJPAUBITMAPINFO256@@PAEPAUtagRECT@@JJJJJJ01PA  XREF[1]:     Tile:0046e3ca(c)  
    //                               TileDibBlt
    //                              Dib.cpp:394 (3)
    //         004390a0     SUB        ESP,0x1c
    //                              Dib.cpp:396 (19)
    //         004390a3     MOV        ECX,dword ptr [ESP + param_15]
    //         004390a7     PUSH       EBX
    //         004390a8     MOV        EAX,ECX
    //         004390aa     PUSH       EBP
    //         004390ab     MOV        EBP,dword ptr [ESP + param_8]
    //         004390af     PUSH       ESI
    //         004390b0     SHL        EAX,0x8
    //         004390b3     CDQ
    //         004390b4     IDIV       EBP
    //                              Dib.cpp:397 (19)
    //         004390b6     MOV        ESI,dword ptr [ESP + param_16]
    //         004390ba     PUSH       EDI
    //         004390bb     MOV        dword ptr [ESP + param_15],EAX
    //         004390bf     MOV        EAX,ESI
    //         004390c1     SHL        EAX,0x8
    //         004390c4     CDQ
    //         004390c5     IDIV       dword ptr [ESP + param_9]
    //                              Dib.cpp:400 (12)
    //         004390c9     MOV        EDX,dword ptr [ESP + param_13]
    //         004390cd     TEST       EDX,EDX
    //         004390cf     MOV        dword ptr [ESP + param_16],EAX
    //         004390d3     JGE        LAB_004390db
    //                              Dib.cpp:401 (6)
    //         004390d5     ADD        EDX,ECX
    //         004390d7     MOV        dword ptr [ESP + param_13],EDX
    //                               LAB_004390db                                                 XREF[1]:     004390d3(j)  
    //                              Dib.cpp:402 (8)
    //         004390db     MOV        EBX,dword ptr [ESP + param_14]
    //         004390df     TEST       EBX,EBX
    //         004390e1     JGE        LAB_004390e9
    //                              Dib.cpp:403 (6)
    //         004390e3     ADD        EBX,ESI
    //         004390e5     MOV        dword ptr [ESP + param_14],EBX
    //                               LAB_004390e9                                                 XREF[1]:     004390e1(j)  
    //                              Dib.cpp:406 (4)
    //         004390e9     CMP        EDX,ECX
    //         004390eb     JL         LAB_004390f7
    //                               LAB_004390ed                                                 XREF[1]:     004390f1(j)  
    //                              Dib.cpp:407 (10)
    //         004390ed     SUB        EDX,ECX
    //         004390ef     CMP        EDX,ECX
    //         004390f1     JGE        LAB_004390ed
    //         004390f3     MOV        dword ptr [ESP + param_13],EDX
    //                               LAB_004390f7                                                 XREF[1]:     004390eb(j)  
    //                              Dib.cpp:408 (4)
    //         004390f7     CMP        EBX,ESI
    //         004390f9     JL         LAB_00439105
    //                               LAB_004390fb                                                 XREF[1]:     004390ff(j)  
    //                              Dib.cpp:409 (10)
    //         004390fb     SUB        EBX,ESI
    //         004390fd     CMP        EBX,ESI
    //         004390ff     JGE        LAB_004390fb
    //         00439101     MOV        dword ptr [ESP + param_14],EBX
    //                               LAB_00439105                                                 XREF[1]:     004390f9(j)  
    //                              Dib.cpp:412 (2)
    //         00439105     MOV        EAX,ECX
    //                              Dib.cpp:414 (12)
    //         00439107     MOV        EDI,ESI
    //         00439109     SUB        EAX,EDX
    //         0043910b     SUB        EDI,EBX
    //         0043910d     SUB        ECX,EAX
    //         0043910f     MOV        dword ptr [ESP + DestBotHgt],EAX
    //                              Dib.cpp:418 (4)
    //         00439113     SUB        EDX,ECX
    //         00439115     SUB        ESI,EDI
    //                              Dib.cpp:431 (30)
    //         00439117     SHL        EAX,0x10
    //         0043911a     MOV        dword ptr [ESP + local_4],EDX
    //         0043911e     MOV        dword ptr [ESP + SrcLtWid],ESI
    //         00439122     CDQ
    //         00439123     IDIV       dword ptr [ESP + param_15]
    //         00439127     SUB        EBX,ESI
    //         00439129     MOV        dword ptr [ESP + SrcRtWid],EDI
    //         0043912d     MOV        dword ptr [ESP + local_c],ECX
    //         00439131     MOV        dword ptr [ESP + local_8],EBX
    //                              Dib.cpp:444 (58)
    //         00439135     MOV        EBX,dword ptr [ESP + param_6]
    //         00439139     MOV        ECX,EBP
    //         0043913b     MOV        ESI,EAX
    //         0043913d     MOV        EAX,EDI
    //         0043913f     SHL        EAX,0x10
    //         00439142     CDQ
    //         00439143     IDIV       dword ptr [ESP + param_16]
    //         00439147     MOV        EDX,dword ptr [ESP + param_9]
    //         0043914b     SAR        ESI,0x8
    //         0043914e     SUB        ECX,ESI
    //         00439150     MOV        dword ptr [ESP + param_15],ECX
    //         00439154     MOV        EDI,EAX
    //         00439156     MOV        EAX,EDX
    //         00439158     SAR        EDI,0x8
    //         0043915b     SUB        EAX,EDI
    //         0043915d     CMP        EBP,EBX
    //         0043915f     MOV        dword ptr [ESP + param_16],EDI
    //         00439163     MOV        dword ptr [ESP + SrcTopHgt],EAX
    //         00439167     JL         LAB_0043917a
    //         00439169     CMP        EDX,dword ptr [ESP + param_7]
    //         0043916d     JL         LAB_0043917a
    //                              Dib.cpp:446 (9)
    //         0043916f     MOV        EAX,0x1
    //         00439174     MOV        dword ptr [ESP + param_6],EAX
    //                              Dib.cpp:449 (2)
    //         00439178     JMP        LAB_004391ae
    //                               LAB_0043917a                                                 XREF[2]:     00439167(j), 0043916d(j)  
    //                              Dib.cpp:451 (5)
    //         0043917a     MOV        EAX,EBX
    //         0043917c     CDQ
    //         0043917d     IDIV       EBP
    //                              Dib.cpp:452 (13)
    //         0043917f     MOV        EDX,EAX
    //         00439181     MOV        dword ptr [ESP + param_6],EAX
    //         00439185     IMUL       EDX,EBP
    //         00439188     CMP        EDX,EBX
    //         0043918a     JGE        LAB_00439191
    //                              Dib.cpp:453 (5)
    //         0043918c     INC        EAX
    //         0043918d     MOV        dword ptr [ESP + param_6],EAX
    //                               LAB_00439191                                                 XREF[1]:     0043918a(j)  
    //                              Dib.cpp:455 (17)
    //         00439191     MOV        EBX,dword ptr [ESP + param_7]
    //         00439195     MOV        EBP,dword ptr [ESP + param_9]
    //         00439199     MOV        EAX,EBX
    //         0043919b     CDQ
    //         0043919c     IDIV       EBP
    //         0043919e     MOV        dword ptr [ESP + param_7],EAX
    //                              Dib.cpp:456 (7)
    //         004391a2     IMUL       EAX,EBP
    //         004391a5     CMP        EAX,EBX
    //         004391a7     JGE        LAB_004391b2
    //                              Dib.cpp:457 (9)
    //         004391a9     MOV        EAX,dword ptr [ESP + param_7]
    //         004391ad     INC        EAX
    //                               LAB_004391ae                                                 XREF[1]:     00439178(j)  
    //         004391ae     MOV        dword ptr [ESP + param_7],EAX
    //                               LAB_004391b2                                                 XREF[1]:     004391a7(j)  
    //                              Dib.cpp:463 (4)
    //         004391b2     MOV        EAX,dword ptr [ESP + param_17]
    //                              Dib.cpp:468 (28)
    //         004391b6     MOV        EDX,dword ptr [ESP + param_5]
    //         004391ba     TEST       EAX,EAX
    //         004391bc     JZ         LAB_004393b9
    //         004391c2     MOV        EAX,dword ptr [ESP + param_7]
    //         004391c6     MOV        dword ptr [ESP + param_5],EDX
    //         004391ca     TEST       EAX,EAX
    //         004391cc     JLE        LAB_00439584
    //                              Dib.cpp:628 (18)
    //         004391d2     MOV        EBX,dword ptr [ESP + param_19]
    //         004391d6     MOV        EBP,dword ptr [ESP + param_18]
    //         004391da     MOV        dword ptr [ESP + param_17],EAX
    //         004391de     JMP        LAB_004391e4
    //                               LAB_004391e0                                                 XREF[1]:     004393a2(j)  
    //         004391e0     MOV        EDI,dword ptr [ESP + param_16]
    //                               LAB_004391e4                                                 XREF[1]:     004391de(j)  
    //                              Dib.cpp:468 (3)
    //         004391e4     LEA        EAX,[EDX + EDI*0x1]
    //                              Dib.cpp:475 (20)
    //         004391e7     MOV        EDI,dword ptr [ESP + param_4]
    //         004391eb     MOV        dword ptr [ESP + param_19],EAX
    //         004391ef     MOV        EAX,dword ptr [ESP + param_6]
    //         004391f3     TEST       EAX,EAX
    //         004391f5     JLE        LAB_0043938f
    //                              Dib.cpp:472 (4)
    //         004391fb     MOV        dword ptr [ESP + param_18],EAX
    //                               LAB_004391ff                                                 XREF[1]:     00439389(j)  
    //                              Dib.cpp:482 (12)
    //         004391ff     MOV        EAX,dword ptr [ESP + param_16]
    //         00439203     TEST       EAX,EAX
    //         00439205     JZ         LAB_004392b7
    //                              Dib.cpp:485 (4)
    //         0043920b     TEST       ESI,ESI
    //         0043920d     JZ         LAB_00439261
    //                              Dib.cpp:488 (82)
    //         0043920f     MOV        ECX,dword ptr [ESP + SrcRtWid]
    //         00439213     PUSH       0x0
    //         00439215     PUSH       EBX
    //         00439216     PUSH       EBP
    //         00439217     PUSH       0x1
    //         00439219     PUSH       ECX
    //         0043921a     MOV        ECX,dword ptr [ESP + DestBotHgt]
    //         0043921e     PUSH       ECX
    //         0043921f     MOV        ECX,dword ptr [ESP + param_14]
    //         00439223     PUSH       ECX
    //         00439224     MOV        ECX,dword ptr [ESP + param_13]
    //         00439228     PUSH       ECX
    //         00439229     MOV        ECX,dword ptr [ESP + param_12]
    //         0043922d     PUSH       ECX
    //         0043922e     MOV        ECX,dword ptr [ESP + param_11]
    //         00439232     PUSH       ECX
    //         00439233     MOV        ECX,dword ptr [ESP + param_10]
    //         00439237     PUSH       ECX
    //         00439238     MOV        ECX,dword ptr [ESP + param_1]
    //         0043923c     PUSH       EAX
    //         0043923d     MOV        EAX,dword ptr [ESP + param_2]
    //         00439241     PUSH       ESI
    //         00439242     PUSH       EDX
    //         00439243     MOV        EDX,dword ptr [ESP + param_3]
    //         00439247     PUSH       EDI
    //         00439248     PUSH       EDX
    //         00439249     PUSH       EAX
    //         0043924a     PUSH       ECX
    //         0043924b     CALL       TransDibBlt                                      void TransDibBlt(BITMAPINFO256 * param_1, uch
    //         00439250     MOV        ECX,dword ptr [ESP + param_15]
    //         00439257     MOV        EAX,dword ptr [ESP + param_16]
    //         0043925e     ADD        ESP,0x48
    //                               LAB_00439261                                                 XREF[1]:     0043920d(j)  
    //                              Dib.cpp:491 (4)
    //         00439261     TEST       ECX,ECX
    //         00439263     JZ         LAB_004392b7
    //                              Dib.cpp:494 (82)
    //         00439265     MOV        EDX,dword ptr [ESP + SrcRtWid]
    //         00439269     PUSH       0x0
    //         0043926b     PUSH       EBX
    //         0043926c     PUSH       EBP
    //         0043926d     PUSH       0x1
    //         0043926f     PUSH       EDX
    //         00439270     MOV        EDX,dword ptr [ESP + local_c]
    //         00439274     PUSH       EDX
    //         00439275     MOV        EDX,dword ptr [ESP + param_14]
    //         00439279     PUSH       EDX
    //         0043927a     MOV        EDX,dword ptr [ESP + local_4]
    //         0043927e     PUSH       EDX
    //         0043927f     MOV        EDX,dword ptr [ESP + param_12]
    //         00439283     PUSH       EDX
    //         00439284     MOV        EDX,dword ptr [ESP + param_11]
    //         00439288     PUSH       EDX
    //         00439289     MOV        EDX,dword ptr [ESP + param_10]
    //         0043928d     PUSH       EDX
    //         0043928e     MOV        EDX,dword ptr [ESP + param_3]
    //         00439292     PUSH       EAX
    //         00439293     MOV        EAX,dword ptr [ESP + param_5]
    //         00439297     PUSH       ECX
    //         00439298     LEA        ECX,[EDI + ESI*0x1]
    //         0043929b     PUSH       EAX
    //         0043929c     MOV        EAX,dword ptr [ESP + param_2]
    //         004392a0     PUSH       ECX
    //         004392a1     MOV        ECX,dword ptr [ESP + param_1]
    //         004392a5     PUSH       EDX
    //         004392a6     PUSH       EAX
    //         004392a7     PUSH       ECX
    //         004392a8     CALL       TransDibBlt                                      void TransDibBlt(BITMAPINFO256 * param_1, uch
    //         004392ad     MOV        ECX,dword ptr [ESP + param_15]
    //         004392b4     ADD        ESP,0x48
    //                               LAB_004392b7                                                 XREF[2]:     00439205(j), 00439263(j)  
    //                              Dib.cpp:497 (12)
    //         004392b7     MOV        EAX,dword ptr [ESP + SrcTopHgt]
    //         004392bb     TEST       EAX,EAX
    //         004392bd     JZ         LAB_00439376
    //                              Dib.cpp:500 (4)
    //         004392c3     TEST       ESI,ESI
    //         004392c5     JZ         LAB_0043931d
    //                              Dib.cpp:503 (86)
    //         004392c7     MOV        EDX,dword ptr [ESP + SrcLtWid]
    //         004392cb     MOV        ECX,dword ptr [ESP + DestBotHgt]
    //         004392cf     PUSH       0x0
    //         004392d1     PUSH       EBX
    //         004392d2     PUSH       EBP
    //         004392d3     PUSH       0x1
    //         004392d5     PUSH       EDX
    //         004392d6     MOV        EDX,dword ptr [ESP + local_8]
    //         004392da     PUSH       ECX
    //         004392db     MOV        ECX,dword ptr [ESP + param_13]
    //         004392df     PUSH       EDX
    //         004392e0     MOV        EDX,dword ptr [ESP + param_12]
    //         004392e4     PUSH       ECX
    //         004392e5     MOV        ECX,dword ptr [ESP + param_11]
    //         004392e9     PUSH       EDX
    //         004392ea     MOV        EDX,dword ptr [ESP + param_10]
    //         004392ee     PUSH       ECX
    //         004392ef     MOV        ECX,dword ptr [ESP + param_3]
    //         004392f3     PUSH       EDX
    //         004392f4     MOV        EDX,dword ptr [ESP + param_2]
    //         004392f8     PUSH       EAX
    //         004392f9     MOV        EAX,dword ptr [ESP + param_19]
    //         00439300     PUSH       ESI
    //         00439301     PUSH       EAX
    //         00439302     MOV        EAX,dword ptr [ESP + param_1]
    //         00439306     PUSH       EDI
    //         00439307     PUSH       ECX
    //         00439308     PUSH       EDX
    //         00439309     PUSH       EAX
    //         0043930a     CALL       TransDibBlt                                      void TransDibBlt(BITMAPINFO256 * param_1, uch
    //         0043930f     MOV        ECX,dword ptr [ESP + param_15]
    //         00439316     MOV        EAX,dword ptr [ESP + SrcTopHgt]
    //         0043931a     ADD        ESP,0x48
    //                               LAB_0043931d                                                 XREF[1]:     004392c5(j)  
    //                              Dib.cpp:506 (4)
    //         0043931d     TEST       ECX,ECX
    //         0043931f     JZ         LAB_00439376
    //                              Dib.cpp:509 (110)
    //         00439321     MOV        EDX,dword ptr [ESP + SrcLtWid]
    //         00439325     PUSH       0x0
    //         00439327     PUSH       EBX
    //         00439328     PUSH       EBP
    //         00439329     PUSH       0x1
    //         0043932b     PUSH       EDX
    //         0043932c     MOV        EDX,dword ptr [ESP + local_c]
    //         00439330     PUSH       EDX
    //         00439331     MOV        EDX,dword ptr [ESP + local_8]
    //         00439335     PUSH       EDX
    //         00439336     MOV        EDX,dword ptr [ESP + local_4]
    //         0043933a     PUSH       EDX
    //         0043933b     MOV        EDX,dword ptr [ESP + param_12]
    //         0043933f     PUSH       EDX
    //         00439340     MOV        EDX,dword ptr [ESP + param_11]
    //         00439344     PUSH       EDX
    //         00439345     MOV        EDX,dword ptr [ESP + param_10]
    //         00439349     PUSH       EDX
    //         0043934a     MOV        EDX,dword ptr [ESP + param_3]
    //         0043934e     PUSH       EAX
    //         0043934f     MOV        EAX,dword ptr [ESP + param_19]
    //         00439356     PUSH       ECX
    //         00439357     LEA        ECX,[EDI + ESI*0x1]
    //         0043935a     PUSH       EAX
    //         0043935b     MOV        EAX,dword ptr [ESP + param_2]
    //         0043935f     PUSH       ECX
    //         00439360     MOV        ECX,dword ptr [ESP + param_1]
    //         00439364     PUSH       EDX
    //         00439365     PUSH       EAX
    //         00439366     PUSH       ECX
    //         00439367     CALL       TransDibBlt                                      void TransDibBlt(BITMAPINFO256 * param_1, uch
    //         0043936c     MOV        ECX,dword ptr [ESP + param_15]
    //         00439373     ADD        ESP,0x48
    //                               LAB_00439376                                                 XREF[2]:     004392bd(j), 0043931f(j)  
    //         00439376     MOV        EDX,dword ptr [ESP + param_8]
    //         0043937a     MOV        EAX,dword ptr [ESP + param_18]
    //         0043937e     ADD        EDI,EDX
    //         00439380     MOV        EDX,dword ptr [ESP + param_5]
    //         00439384     DEC        EAX
    //         00439385     MOV        dword ptr [ESP + param_18],EAX
    //         00439389     JNZ        LAB_004391ff
    //                               LAB_0043938f                                                 XREF[1]:     004391f5(j)  
    //                              Dib.cpp:468 (25)
    //         0043938f     MOV        EDI,dword ptr [ESP + param_9]
    //         00439393     MOV        EAX,dword ptr [ESP + param_17]
    //         00439397     ADD        EDX,EDI
    //         00439399     DEC        EAX
    //         0043939a     MOV        dword ptr [ESP + param_5],EDX
    //         0043939e     MOV        dword ptr [ESP + param_17],EAX
    //         004393a2     JNZ        LAB_004391e0
    //                              Dib.cpp:514 (4)
    //         004393a8     MOV        EAX,dword ptr [ESP + param_7]
    //                              Dib.cpp:627 (5)
    //         004393ac     IMUL       EAX,dword ptr [ESP + param_6]
    //                              Dib.cpp:628 (8)
    //         004393b1     POP        EDI
    //         004393b2     POP        ESI
    //         004393b3     POP        EBP
    //         004393b4     POP        EBX
    //         004393b5     ADD        ESP,0x1c
    //         004393b8     RET
    //                               LAB_004393b9                                                 XREF[1]:     004391bc(j)  
    //                              Dib.cpp:519 (16)
    //         004393b9     MOV        EAX,dword ptr [ESP + param_7]
    //         004393bd     MOV        dword ptr [ESP + param_12],EDX
    //         004393c1     TEST       EAX,EAX
    //         004393c3     JLE        LAB_00439584
    //                              Dib.cpp:628 (18)
    //         004393c9     MOV        EBX,dword ptr [ESP + param_19]
    //         004393cd     MOV        EBP,dword ptr [ESP + param_18]
    //         004393d1     MOV        dword ptr [ESP + param_17],EAX
    //         004393d5     JMP        LAB_004393db
    //                               LAB_004393d7                                                 XREF[1]:     0043957a(j)  
    //         004393d7     MOV        EDI,dword ptr [ESP + param_16]
    //                               LAB_004393db                                                 XREF[1]:     004393d5(j)  
    //                              Dib.cpp:519 (3)
    //         004393db     LEA        EAX,[EDX + EDI*0x1]
    //                              Dib.cpp:526 (20)
    //         004393de     MOV        EDI,dword ptr [ESP + param_4]
    //         004393e2     MOV        dword ptr [ESP + param_5],EAX
    //         004393e6     MOV        EAX,dword ptr [ESP + param_6]
    //         004393ea     TEST       EAX,EAX
    //         004393ec     JLE        LAB_00439567
    //                              Dib.cpp:523 (4)
    //         004393f2     MOV        dword ptr [ESP + param_19],EAX
    //                               LAB_004393f6                                                 XREF[1]:     00439561(j)  
    //                              Dib.cpp:533 (12)
    //         004393f6     MOV        EAX,dword ptr [ESP + param_16]
    //         004393fa     TEST       EAX,EAX
    //         004393fc     JZ         LAB_004394a3
    //                              Dib.cpp:536 (4)
    //         00439402     TEST       ESI,ESI
    //         00439404     JZ         LAB_00439451
    //                              Dib.cpp:539 (75)
    //         00439406     MOV        ECX,dword ptr [ESP + SrcRtWid]
    //         0043940a     PUSH       EBX
    //         0043940b     PUSH       EBP
    //         0043940c     PUSH       0x1
    //         0043940e     PUSH       ECX
    //         0043940f     MOV        ECX,dword ptr [ESP + DestBotHgt]
    //         00439413     PUSH       ECX
    //         00439414     MOV        ECX,dword ptr [ESP + param_14]
    //         00439418     PUSH       ECX
    //         00439419     MOV        ECX,dword ptr [ESP + param_13]
    //         0043941d     PUSH       ECX
    //         0043941e     MOV        ECX,dword ptr [ESP + param_11]
    //         00439422     PUSH       ECX
    //         00439423     MOV        ECX,dword ptr [ESP + param_10]
    //         00439427     PUSH       ECX
    //         00439428     MOV        ECX,dword ptr [ESP + param_1]
    //         0043942c     PUSH       EAX
    //         0043942d     MOV        EAX,dword ptr [ESP + param_2]
    //         00439431     PUSH       ESI
    //         00439432     PUSH       EDX
    //         00439433     MOV        EDX,dword ptr [ESP + param_3]
    //         00439437     PUSH       EDI
    //         00439438     PUSH       EDX
    //         00439439     PUSH       EAX
    //         0043943a     PUSH       ECX
    //         0043943b     CALL       DibBlt                                           void DibBlt(BITMAPINFO256 * param_1, uchar * 
    //         00439440     MOV        ECX,dword ptr [ESP + param_15]
    //         00439447     MOV        EAX,dword ptr [ESP + param_16]
    //         0043944e     ADD        ESP,0x40
    //                               LAB_00439451                                                 XREF[1]:     00439404(j)  
    //                              Dib.cpp:542 (4)
    //         00439451     TEST       ECX,ECX
    //         00439453     JZ         LAB_004394a3
    //                              Dib.cpp:545 (78)
    //         00439455     MOV        EDX,dword ptr [ESP + SrcRtWid]
    //         00439459     PUSH       EBX
    //         0043945a     PUSH       EBP
    //         0043945b     PUSH       0x1
    //         0043945d     PUSH       EDX
    //         0043945e     MOV        EDX,dword ptr [ESP + local_c]
    //         00439462     PUSH       EDX
    //         00439463     MOV        EDX,dword ptr [ESP + param_14]
    //         00439467     PUSH       EDX
    //         00439468     MOV        EDX,dword ptr [ESP + local_4]
    //         0043946c     PUSH       EDX
    //         0043946d     MOV        EDX,dword ptr [ESP + param_11]
    //         00439471     PUSH       EDX
    //         00439472     MOV        EDX,dword ptr [ESP + param_10]
    //         00439476     PUSH       EDX
    //         00439477     MOV        EDX,dword ptr [ESP + param_3]
    //         0043947b     PUSH       EAX
    //         0043947c     MOV        EAX,dword ptr [ESP + param_12]
    //         00439483     PUSH       ECX
    //         00439484     LEA        ECX,[EDI + ESI*0x1]
    //         00439487     PUSH       EAX
    //         00439488     MOV        EAX,dword ptr [ESP + param_2]
    //         0043948c     PUSH       ECX
    //         0043948d     MOV        ECX,dword ptr [ESP + param_1]
    //         00439491     PUSH       EDX
    //         00439492     PUSH       EAX
    //         00439493     PUSH       ECX
    //         00439494     CALL       DibBlt                                           void DibBlt(BITMAPINFO256 * param_1, uchar * 
    //         00439499     MOV        ECX,dword ptr [ESP + param_15]
    //         004394a0     ADD        ESP,0x40
    //                               LAB_004394a3                                                 XREF[2]:     004393fc(j), 00439453(j)  
    //                              Dib.cpp:548 (12)
    //         004394a3     MOV        EAX,dword ptr [ESP + SrcTopHgt]
    //         004394a7     TEST       EAX,EAX
    //         004394a9     JZ         LAB_0043954e
    //                              Dib.cpp:551 (4)
    //         004394af     TEST       ESI,ESI
    //         004394b1     JZ         LAB_004394ff
    //                              Dib.cpp:554 (76)
    //         004394b3     MOV        EDX,dword ptr [ESP + SrcLtWid]
    //         004394b7     MOV        ECX,dword ptr [ESP + DestBotHgt]
    //         004394bb     PUSH       EBX
    //         004394bc     PUSH       EBP
    //         004394bd     PUSH       0x1
    //         004394bf     PUSH       EDX
    //         004394c0     MOV        EDX,dword ptr [ESP + local_8]
    //         004394c4     PUSH       ECX
    //         004394c5     MOV        ECX,dword ptr [ESP + param_13]
    //         004394c9     PUSH       EDX
    //         004394ca     MOV        EDX,dword ptr [ESP + param_11]
    //         004394ce     PUSH       ECX
    //         004394cf     MOV        ECX,dword ptr [ESP + param_10]
    //         004394d3     PUSH       EDX
    //         004394d4     MOV        EDX,dword ptr [ESP + param_5]
    //         004394d8     PUSH       ECX
    //         004394d9     MOV        ECX,dword ptr [ESP + param_2]
    //         004394dd     PUSH       EAX
    //         004394de     MOV        EAX,dword ptr [ESP + param_3]
    //         004394e2     PUSH       ESI
    //         004394e3     PUSH       EDX
    //         004394e4     MOV        EDX,dword ptr [ESP + param_1]
    //         004394e8     PUSH       EDI
    //         004394e9     PUSH       EAX
    //         004394ea     PUSH       ECX
    //         004394eb     PUSH       EDX
    //         004394ec     CALL       DibBlt                                           void DibBlt(BITMAPINFO256 * param_1, uchar * 
    //         004394f1     MOV        ECX,dword ptr [ESP + param_15]
    //         004394f8     MOV        EAX,dword ptr [ESP + SrcTopHgt]
    //         004394fc     ADD        ESP,0x40
    //                               LAB_004394ff                                                 XREF[1]:     004394b1(j)  
    //                              Dib.cpp:557 (4)
    //         004394ff     TEST       ECX,ECX
    //         00439501     JZ         LAB_0043954e
    //                              Dib.cpp:560 (100)
    //         00439503     MOV        EDX,dword ptr [ESP + SrcLtWid]
    //         00439507     PUSH       EBX
    //         00439508     PUSH       EBP
    //         00439509     PUSH       0x1
    //         0043950b     PUSH       EDX
    //         0043950c     MOV        EDX,dword ptr [ESP + local_c]
    //         00439510     PUSH       EDX
    //         00439511     MOV        EDX,dword ptr [ESP + local_8]
    //         00439515     PUSH       EDX
    //         00439516     MOV        EDX,dword ptr [ESP + local_4]
    //         0043951a     PUSH       EDX
    //         0043951b     MOV        EDX,dword ptr [ESP + param_11]
    //         0043951f     PUSH       EDX
    //         00439520     MOV        EDX,dword ptr [ESP + param_10]
    //         00439524     PUSH       EDX
    //         00439525     MOV        EDX,dword ptr [ESP + param_3]
    //         00439529     PUSH       EAX
    //         0043952a     MOV        EAX,dword ptr [ESP + param_5]
    //         0043952e     PUSH       ECX
    //         0043952f     LEA        ECX,[EDI + ESI*0x1]
    //         00439532     PUSH       EAX
    //         00439533     MOV        EAX,dword ptr [ESP + param_2]
    //         00439537     PUSH       ECX
    //         00439538     MOV        ECX,dword ptr [ESP + param_1]
    //         0043953c     PUSH       EDX
    //         0043953d     PUSH       EAX
    //         0043953e     PUSH       ECX
    //         0043953f     CALL       DibBlt                                           void DibBlt(BITMAPINFO256 * param_1, uchar * 
    //         00439544     MOV        ECX,dword ptr [ESP + param_15]
    //         0043954b     ADD        ESP,0x40
    //                               LAB_0043954e                                                 XREF[2]:     004394a9(j), 00439501(j)  
    //         0043954e     MOV        EDX,dword ptr [ESP + param_8]
    //         00439552     MOV        EAX,dword ptr [ESP + param_19]
    //         00439556     ADD        EDI,EDX
    //         00439558     MOV        EDX,dword ptr [ESP + param_12]
    //         0043955c     DEC        EAX
    //         0043955d     MOV        dword ptr [ESP + param_19],EAX
    //         00439561     JNZ        LAB_004393f6
    //                               LAB_00439567                                                 XREF[1]:     004393ec(j)  
    //                              Dib.cpp:519 (25)
    //         00439567     MOV        EDI,dword ptr [ESP + param_9]
    //         0043956b     MOV        EAX,dword ptr [ESP + param_17]
    //         0043956f     ADD        EDX,EDI
    //         00439571     DEC        EAX
    //         00439572     MOV        dword ptr [ESP + param_12],EDX
    //         00439576     MOV        dword ptr [ESP + param_17],EAX
    //         0043957a     JNZ        LAB_004393d7
    //                              Dib.cpp:514 (4)
    //         00439580     MOV        EAX,dword ptr [ESP + param_7]
    //                               LAB_00439584                                                 XREF[2]:     004391cc(j), 004393c3(j)  
    //                              Dib.cpp:627 (5)
    //         00439584     IMUL       EAX,dword ptr [ESP + param_6]
    //                              Dib.cpp:628 (8)
    //         00439589     POP        EDI
    //         0043958a     POP        ESI
    //         0043958b     POP        EBP
    //         0043958c     POP        EBX
    //         0043958d     ADD        ESP,0x1c
    //         00439590     RET
    //         00439591     ??         90h
    //         00439592     NOP
    //         00439593     NOP
    //         00439594     NOP
    //         00439595     NOP
    //         00439596     NOP
    //         00439597     NOP
    //         00439598     NOP
    //         00439599     NOP
    //         0043959a     NOP
    //         0043959b     NOP
    //         0043959c     NOP
    //         0043959d     NOP
    //         0043959e     NOP
    //         0043959f     NOP
    //                              * int __cdecl DibCheckTrans(struct BITMAPINFO256 *,struct TRANSINFO *,unsigned char *)                  *
    //                              int __cdecl DibCheckTrans(BITMAPINFO256 * param_1, TRANSINFO * param
    //              int               EAX:4          <RETURN>
    //              BITMAPINFO256 *   Stack[0x4]:4   param_1                   XREF[5]:     004395a9(R), 004395fe(W), 00439610(R), 004396bc(R), 
    //                                                                                     004396cb(W)  
    //              TRANSINFO *       Stack[0x8]:4   param_2                   XREF[3]:     004395d5(R), 0043969d(R), 004396d5(R)  
    //              uchar *           Stack[0xc]:4   param_3                   XREF[1]:     00439632(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     004395a4(*), 00439614(R)  
    //              long              Stack[-0x8]:4  orien                     XREF[2]:     004395c8(W), 0043960c(R)  
    //              long              Stack[-0xc]:4  w                         XREF[3]:     004395b2(*), 00439621(R), 0043962d(R)  
    //              long              Stack[-0x10]:4 tw                        XREF[4]:     004395fa(W), 00439650(R), 00439658(W), 004396d9(R)  
    //              int               Stack[-0x14]:4 AnyTrans                  XREF[4]:     004395ad(*), 004395be(R), 004395ee(R), 004396c4(R)  
    //              long              Stack[-0x18]:4 h
    //                               ?DibCheckTrans@@YAHPAUBITMAPINFO256@@PAUTRANSINFO@@PAE@Z     XREF[4]:     TPicture:0046df34(c), 
    //                               DibCheckTrans                                                             TPicture:0046df52(c), 
    //                                                                                                         Load:0046e1f9(c), 
    //                                                                                                         Load:0046e21a(c)  
    //                              Dib.cpp:634 (4)
    //         004395a0     SUB        ESP,0x14
    //         004395a3     PUSH       EBX
    //                              Dib.cpp:640 (26)
    //         004395a4     LEA        EAX=>local_4,[ESP + 0x14]
    //         004395a8     PUSH       ESI
    //         004395a9     MOV        ESI,dword ptr [ESP + param_1]
    //         004395ad     LEA        ECX=>AnyTrans,[ESP + 0x8]
    //         004395b1     PUSH       EAX
    //         004395b2     LEA        EDX=>w,[ESP + 0x14]
    //         004395b6     PUSH       ECX
    //         004395b7     PUSH       EDX
    //         004395b8     PUSH       ESI
    //         004395b9     CALL       GetDibDim                                        void GetDibDim(BITMAPINFO256 * param_1, long 
    //                              Dib.cpp:643 (30)
    //         004395be     MOV        EAX,dword ptr [ESP + AnyTrans]
    //         004395c2     MOV        EBX,dword ptr [ESI + 0x4]
    //         004395c5     ADD        ESP,0x10
    //         004395c8     MOV        dword ptr [ESP + orien],EBX
    //         004395cc     SHL        EAX,0x4
    //         004395cf     PUSH       EAX
    //         004395d0     CALL       malloc                                           undefined malloc()
    //         004395d5     MOV        EDX,dword ptr [ESP + param_2]
    //         004395d9     ADD        ESP,0x4
    //                              Dib.cpp:644 (7)
    //         004395dc     TEST       EAX,EAX
    //         004395de     MOV        dword ptr [EDX + 0x14],EAX
    //         004395e1     JNZ        LAB_004395ee
    //                              Dib.cpp:645 (5)
    //         004395e3     MOV        EAX,0x1
    //                              Dib.cpp:714 (6)
    //         004395e8     POP        ESI
    //         004395e9     POP        EBX
    //         004395ea     ADD        ESP,0x14
    //         004395ed     RET
    //                               LAB_004395ee                                                 XREF[1]:     004395e1(j)  
    //                              Dib.cpp:649 (26)
    //         004395ee     MOV        EAX,dword ptr [ESP + AnyTrans]
    //         004395f2     XOR        ESI,ESI
    //         004395f4     XOR        ECX,ECX
    //         004395f6     PUSH       EDI
    //         004395f7     TEST       EAX,EAX
    //         004395f9     PUSH       EBP
    //         004395fa     MOV        dword ptr [ESP + tw],ESI
    //         004395fe     MOV        dword ptr [ESP + param_1],ECX
    //         00439602     JLE        LAB_004396dd
    //                              Dib.cpp:714 (34)
    //         00439608     XOR        EBP,EBP
    //         0043960a     JMP        LAB_00439614
    //                               LAB_0043960c                                                 XREF[1]:     004396cf(j)  
    //         0043960c     MOV        EBX,dword ptr [ESP + orien]
    //         00439610     MOV        ECX,dword ptr [ESP + param_1]
    //                               LAB_00439614                                                 XREF[1]:     0043960a(j)  
    //         00439614     MOV        EDX,dword ptr [ESP + local_4]
    //         00439618     MOV        ESI,0x1
    //         0043961d     CMP        EDX,ESI
    //         0043961f     JNZ        LAB_0043962a
    //         00439621     MOV        EAX,dword ptr [ESP + w]
    //         00439625     IMUL       EAX,ECX
    //         00439628     JMP        LAB_00439632
    //                               LAB_0043962a                                                 XREF[1]:     0043961f(j)  
    //                              Dib.cpp:654 (12)
    //         0043962a     SUB        EAX,ECX
    //         0043962c     DEC        EAX
    //         0043962d     IMUL       EAX,dword ptr [ESP + w]
    //                               LAB_00439632                                                 XREF[1]:     00439628(j)  
    //         00439632     MOV        ECX,dword ptr [ESP + param_3]
    //                              Dib.cpp:658 (4)
    //         00439636     MOV        EDI,EBX
    //         00439638     ADD        EAX,ECX
    //                              Dib.cpp:659 (6)
    //         0043963a     XOR        ECX,ECX
    //         0043963c     TEST       EBX,EBX
    //         0043963e     JLE        LAB_00439665
    //                               LAB_00439640                                                 XREF[1]:     00439663(j)  
    //                              Dib.cpp:661 (6)
    //         00439640     CMP        byte ptr [EAX + ECX*0x1],0x0
    //         00439644     JZ         LAB_00439650
    //                              Dib.cpp:663 (4)
    //         00439646     TEST       ESI,ESI
    //         00439648     JZ         LAB_00439660
    //                              Dib.cpp:665 (2)
    //         0043964a     XOR        ESI,ESI
    //                              Dib.cpp:666 (2)
    //         0043964c     MOV        EDI,ECX
    //                              Dib.cpp:669 (2)
    //         0043964e     JMP        LAB_00439660
    //                               LAB_00439650                                                 XREF[1]:     00439644(j)  
    //                              Dib.cpp:671 (8)
    //         00439650     MOV        EDX,dword ptr [ESP + tw]
    //         00439654     TEST       EDX,EDX
    //         00439656     JNZ        LAB_00439660
    //                              Dib.cpp:672 (8)
    //         00439658     MOV        dword ptr [ESP + tw],0x1
    //                               LAB_00439660                                                 XREF[3]:     00439648(j), 0043964e(j), 
    //                                                                                                         00439656(j)  
    //                              Dib.cpp:659 (5)
    //         00439660     INC        ECX
    //         00439661     CMP        ECX,EBX
    //         00439663     JL         LAB_00439640
    //                               LAB_00439665                                                 XREF[1]:     0043963e(j)  
    //                              Dib.cpp:678 (6)
    //         00439665     TEST       ESI,ESI
    //         00439667     MOV        EDX,EDI
    //         00439669     JNZ        LAB_0043967f
    //                              Dib.cpp:680 (7)
    //         0043966b     LEA        ECX,[EDI + 0x1]
    //         0043966e     CMP        ECX,EBX
    //         00439670     JGE        LAB_0043967f
    //                               LAB_00439672                                                 XREF[1]:     0043967d(j)  
    //                              Dib.cpp:682 (6)
    //         00439672     CMP        byte ptr [EAX + ECX*0x1],0x0
    //         00439676     JZ         LAB_0043967a
    //                              Dib.cpp:683 (2)
    //         00439678     MOV        EDX,ECX
    //                               LAB_0043967a                                                 XREF[1]:     00439676(j)  
    //                              Dib.cpp:680 (5)
    //         0043967a     INC        ECX
    //         0043967b     CMP        ECX,EBX
    //         0043967d     JL         LAB_00439672
    //                               LAB_0043967f                                                 XREF[2]:     00439669(j), 00439670(j)  
    //                              Dib.cpp:689 (9)
    //         0043967f     TEST       ESI,ESI
    //         00439681     MOV        EBX,0x1
    //         00439686     JNZ        LAB_0043969d
    //                              Dib.cpp:691 (6)
    //         00439688     CMP        EDI,EDX
    //         0043968a     MOV        ECX,EDI
    //         0043968c     JG         LAB_0043969d
    //                               LAB_0043968e                                                 XREF[1]:     00439697(j)  
    //                              Dib.cpp:693 (13)
    //         0043968e     CMP        byte ptr [EAX + ECX*0x1],0x0
    //         00439692     JZ         LAB_0043969b
    //         00439694     INC        ECX
    //         00439695     CMP        ECX,EDX
    //         00439697     JLE        LAB_0043968e
    //         00439699     JMP        LAB_0043969d
    //                               LAB_0043969b                                                 XREF[1]:     00439692(j)  
    //                              Dib.cpp:695 (2)
    //         0043969b     XOR        EBX,EBX
    //                               LAB_0043969d                                                 XREF[3]:     00439686(j), 0043968c(j), 
    //                                                                                                         00439699(j)  
    //                              Dib.cpp:702 (14)
    //         0043969d     MOV        EAX,dword ptr [ESP + param_2]
    //         004396a1     ADD        EBP,0x10
    //         004396a4     MOV        ECX,dword ptr [EAX + 0x14]
    //         004396a7     MOV        dword ptr [ECX + EBP*0x1 + -0x10],ESI
    //                              Dib.cpp:703 (7)
    //         004396ab     MOV        ECX,dword ptr [EAX + 0x14]
    //         004396ae     MOV        dword ptr [ECX + EBP*0x1 + -0xc],EBX
    //                              Dib.cpp:704 (7)
    //         004396b2     MOV        ECX,dword ptr [EAX + 0x14]
    //         004396b5     MOV        dword ptr [ECX + EBP*0x1 + -0x8],EDI
    //                              Dib.cpp:705 (36)
    //         004396b9     MOV        EAX,dword ptr [EAX + 0x14]
    //         004396bc     MOV        ECX,dword ptr [ESP + param_1]
    //         004396c0     MOV        dword ptr [EAX + EBP*0x1 + -0x4],EDX
    //         004396c4     MOV        EAX,dword ptr [ESP + AnyTrans]
    //         004396c8     INC        ECX
    //         004396c9     CMP        ECX,EAX
    //         004396cb     MOV        dword ptr [ESP + param_1],ECX
    //         004396cf     JL         LAB_0043960c
    //         004396d5     MOV        EDX,dword ptr [ESP + param_2]
    //         004396d9     MOV        ESI,dword ptr [ESP + tw]
    //                               LAB_004396dd                                                 XREF[1]:     00439602(j)  
    //                              Dib.cpp:710 (6)
    //         004396dd     TEST       ESI,ESI
    //         004396df     MOV        dword ptr [EDX],ESI
    //         004396e1     JNZ        LAB_004396ef
    //                              Dib.cpp:711 (13)
    //         004396e3     MOV        ECX,dword ptr [EDX + 0x14]
    //         004396e6     PUSH       ECX
    //         004396e7     CALL       free                                             undefined free()
    //         004396ec     ADD        ESP,0x4
    //                               LAB_004396ef                                                 XREF[1]:     004396e1(j)  
    //         004396ef     POP        EBP
    //                              Dib.cpp:713 (3)
    //         004396f0     MOV        EAX,ESI
    //         004396f2     POP        EDI
    //                              Dib.cpp:714 (6)
    //         004396f3     POP        ESI
    //         004396f4     POP        EBX
    //         004396f5     ADD        ESP,0x14
    //         004396f8     RET
    //         004396f9     ??         90h
    //         004396fa     NOP
    //         004396fb     NOP
    //         004396fc     NOP
    //         004396fd     NOP
    //         004396fe     NOP
    //         004396ff     NOP
    //                              * void * __cdecl GetPaletteFromDib(char *,int)                                                          *
    //                              void * __cdecl GetPaletteFromDib(char * param_1, int param_2)
    //              void *            EAX:4          <RETURN>
    //              char *            Stack[0x4]:4   param_1                   XREF[1]:     00439700(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     0043971f(R)  
    //                               ?GetPaletteFromDib@@YAPAXPADH@Z
    //                               GetPaletteFromDib
    //                              Dib.cpp:721 (16)
    //         00439700     MOV        EAX,dword ptr [ESP + param_1]
    //         00439704     PUSH       ESI
    //         00439705     PUSH       EAX
    //         00439706     CALL       DibOpenFile                                      tagBITMAPINFOHEADER * DibOpenFile(char * para
    //         0043970b     MOV        ESI,EAX
    //         0043970d     ADD        ESP,0x4
    //                              Dib.cpp:725 (4)
    //         00439710     TEST       ESI,ESI
    //         00439712     JNZ        LAB_00439716
    //                              Dib.cpp:732 (2)
    //         00439714     POP        ESI
    //         00439715     RET
    //                               LAB_00439716                                                 XREF[1]:     00439712(j)  
    //                              Dib.cpp:721 (1)
    //         00439716     PUSH       EDI
    //                              Dib.cpp:727 (8)
    //         00439717     PUSH       ESI
    //         00439718     CALL       DibCreatePalette                                 void * DibCreatePalette(tagBITMAPINFOHEADER *
    //         0043971d     MOV        EDI,EAX
    //                              Dib.cpp:728 (11)
    //         0043971f     MOV        EAX,dword ptr [ESP + param_2]
    //         00439723     ADD        ESP,0x4
    //         00439726     TEST       EAX,EAX
    //         00439728     JZ         LAB_00439733
    //                              Dib.cpp:729 (9)
    //         0043972a     PUSH       EDI
    //         0043972b     CALL       CreateIdentityPalette                            void CreateIdentityPalette(void * param_1)
    //         00439730     ADD        ESP,0x4
    //                               LAB_00439733                                                 XREF[1]:     00439728(j)  
    //                              Dib.cpp:730 (9)
    //         00439733     PUSH       ESI
    //         00439734     CALL       DibFree                                          void DibFree(tagBITMAPINFOHEADER * param_1)
    //         00439739     ADD        ESP,0x4
    //                              Dib.cpp:731 (3)
    //         0043973c     MOV        EAX,EDI
    //         0043973e     POP        EDI
    //                              Dib.cpp:732 (2)
    //         0043973f     POP        ESI
    //         00439740     RET
    //         00439741     ??         90h
    //         00439742     NOP
    //         00439743     NOP
    //         00439744     NOP
    //         00439745     NOP
    //         00439746     NOP
    //         00439747     NOP
    //         00439748     NOP
    //         00439749     NOP
    //         0043974a     NOP
    //         0043974b     NOP
    //         0043974c     NOP
    //         0043974d     NOP
    //         0043974e     NOP
    //         0043974f     NOP
    //                              * void * __cdecl ReadPalette(char *,long,int)                                                           *
    //                              void * __cdecl ReadPalette(char * param_1, long param_2, int param_3)
    //              void *            EAX:4          <RETURN>
    //              char *            Stack[0x4]:4   param_1                   XREF[8,1]:   00439753(R), 00439864(W), 00439869(*), 00439883(*), 
    //                                                                                     00439899(*), 004398ea(*), 00439906(*), 00439925(*), 
    //                                                                                     0043986f(W)  
    //              long              Stack[0x8]:4   param_2                   XREF[4]:     004397ec(R), 004398d0(W), 00439951(W), 00439961(R)  
    //              int               Stack[0xc]:4   param_3
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[3]:     004397f5(*), 00439817(R), 00439821(R)  
    //              int               Stack[-0x8]:4  resDataSize               XREF[1]:     0043976b(W)  
    //              void *            Stack[-0xc]:4  hpal                      XREF[6]:     00439763(W), 004397d5(W), 004397f9(*), 0043980c(R), 
    //                                                                                     00439837(W), 004399ea(R)  
    //              int               Stack[-0x10]:4 own_mem                   XREF[7]:     0043975f(W), 004397b9(W), 004397e6(R), 00439828(W), 
    //                                                                                     00439841(W), 00439845(R), 004399f1(R)  
    //              char *            Stack[-0x14]:4 data
    //                               ?ReadPalette@@YAPAXPADJH@Z                                   XREF[1]:     get_palette:004643e4(c)  
    //                               ReadPalette
    //                              Dib.cpp:738 (3)
    //         00439750     SUB        ESP,0x10
    //                              Dib.cpp:758 (45)
    //         00439753     MOV        EAX,dword ptr [ESP + param_1]
    //         00439757     PUSH       EBX
    //         00439758     PUSH       EBP
    //         00439759     XOR        EBP,EBP
    //         0043975b     PUSH       ESI
    //         0043975c     CMP        EAX,EBP
    //         0043975e     PUSH       EDI
    //         0043975f     MOV        dword ptr [ESP + own_mem],EBP
    //         00439763     MOV        dword ptr [ESP + hpal],0xffffffff
    //         0043976b     MOV        dword ptr [ESP + resDataSize],EBP
    //         0043976f     JZ         LAB_004397e6
    //         00439771     CMP        byte ptr [EAX],0x0
    //         00439774     JZ         LAB_004397e6
    //         00439776     MOV        CL,byte ptr [shape_file_first]                   = 00h
    //         0043977c     TEST       CL,CL
    //         0043977e     JZ         LAB_004397e6
    //                              Dib.cpp:760 (16)
    //         00439780     PUSH       0x8000
    //         00439785     PUSH       EAX
    //         00439786     CALL       __open                                           undefined __open()
    //         0043978b     MOV        ESI,EAX
    //         0043978d     ADD        ESP,0x8
    //                              Dib.cpp:761 (5)
    //         00439790     CMP        ESI,-0x1
    //         00439793     JZ         LAB_004397e6
    //                              Dib.cpp:763 (12)
    //         00439795     PUSH       0x2
    //         00439797     PUSH       EBP
    //         00439798     PUSH       ESI
    //         00439799     CALL       lseek                                            undefined lseek()
    //         0043979e     ADD        ESP,0xc
    //                              Dib.cpp:764 (11)
    //         004397a1     PUSH       ESI
    //         004397a2     CALL       __tell                                           undefined __tell()
    //         004397a7     ADD        ESP,0x4
    //         004397aa     MOV        EBX,EAX
    //                              Dib.cpp:765 (11)
    //         004397ac     PUSH       EBX
    //         004397ad     CALL       malloc                                           undefined malloc()
    //         004397b2     MOV        EDI,EAX
    //         004397b4     ADD        ESP,0x4
    //                              Dib.cpp:766 (8)
    //         004397b7     CMP        EDI,EBP
    //         004397b9     MOV        dword ptr [ESP + own_mem],EDI
    //         004397bd     JZ         LAB_004397dd
    //                              Dib.cpp:768 (11)
    //         004397bf     PUSH       EBP
    //         004397c0     PUSH       EBP
    //         004397c1     PUSH       ESI
    //         004397c2     CALL       lseek                                            undefined lseek()
    //         004397c7     ADD        ESP,0xc
    //                              Dib.cpp:769 (11)
    //         004397ca     PUSH       EBX
    //         004397cb     PUSH       EDI
    //         004397cc     PUSH       ESI
    //         004397cd     CALL       read                                             undefined read()
    //         004397d2     ADD        ESP,0xc
    //                              Dib.cpp:770 (8)
    //         004397d5     MOV        dword ptr [ESP + hpal],0x1
    //                               LAB_004397dd                                                 XREF[1]:     004397bd(j)  
    //                              Dib.cpp:772 (9)
    //         004397dd     PUSH       ESI
    //         004397de     CALL       close                                            undefined close()
    //         004397e3     ADD        ESP,0x4
    //                               LAB_004397e6                                                 XREF[4]:     0043976f(j), 00439774(j), 
    //                                                                                                         0043977e(j), 00439793(j)  
    //                              Dib.cpp:776 (15)
    //         004397e6     CMP        dword ptr [ESP + own_mem],EBP
    //         004397ea     JNZ        LAB_00439845
    //         004397ec     MOV        EAX,dword ptr [ESP + param_2]
    //         004397f0     CMP        EAX,-0x1
    //         004397f3     JZ         LAB_00439845
    //                              Dib.cpp:778 (23)
    //         004397f5     LEA        ECX=>local_4,[ESP + 0x1c]
    //         004397f9     LEA        EDX=>hpal,[ESP + 0x14]
    //         004397fd     PUSH       ECX
    //         004397fe     PUSH       EDX
    //         004397ff     PUSH       EAX
    //         00439800     PUSH       0x62696e61
    //         00439805     CALL       RESFILE_load                                     uchar * RESFILE_load(ulong param_1, ulong par
    //         0043980a     MOV        ESI,EAX
    //                              Dib.cpp:780 (11)
    //         0043980c     MOV        EAX,dword ptr [ESP + hpal]
    //         00439810     ADD        ESP,0x10
    //         00439813     CMP        EAX,EBP
    //         00439815     JNZ        LAB_00439841
    //                              Dib.cpp:782 (10)
    //         00439817     MOV        EAX,dword ptr [ESP + local_4]
    //         0043981b     PUSH       EAX
    //         0043981c     CALL       malloc                                           undefined malloc()
    //                              Dib.cpp:783 (22)
    //         00439821     MOV        ECX,dword ptr [ESP + local_4]
    //         00439825     ADD        ESP,0x4
    //         00439828     MOV        dword ptr [ESP + own_mem],EAX
    //         0043982c     PUSH       ECX
    //         0043982d     PUSH       ESI
    //         0043982e     PUSH       EAX
    //         0043982f     CALL       memcpy                                           undefined memcpy()
    //         00439834     ADD        ESP,0xc
    //                              Dib.cpp:784 (8)
    //         00439837     MOV        dword ptr [ESP + hpal],0x1
    //                              Dib.cpp:786 (2)
    //         0043983f     JMP        LAB_00439845
    //                               LAB_00439841                                                 XREF[1]:     00439815(j)  
    //                              Dib.cpp:788 (4)
    //         00439841     MOV        dword ptr [ESP + own_mem],ESI
    //                               LAB_00439845                                                 XREF[3]:     004397ea(j), 004397f3(j), 
    //                                                                                                         0043983f(j)  
    //                              Dib.cpp:792 (8)
    //         00439845     MOV        EAX,dword ptr [ESP + own_mem]
    //         00439849     CMP        EAX,EBP
    //         0043984b     JNZ        LAB_00439857
    //                              Dib.cpp:793 (2)
    //         0043984d     XOR        EAX,EAX
    //                              Dib.cpp:899 (8)
    //         0043984f     POP        EDI
    //         00439850     POP        ESI
    //         00439851     POP        EBP
    //         00439852     POP        EBX
    //         00439853     ADD        ESP,0x10
    //         00439856     RET
    //                               LAB_00439857                                                 XREF[1]:     0043984b(j)  
    //                              Dib.cpp:795 (18)
    //         00439857     MOV        DX,word ptr [s___]                               = 0A20h
    //         0043985e     MOV        CL,byte ptr [DAT_005837c6]
    //         00439864     MOV        word ptr [ESP + param_1],DX
    //                              Dib.cpp:799 (18)
    //         00439869     LEA        EDX=>param_1,[ESP + 0x24]
    //         0043986d     PUSH       EDX
    //         0043986e     PUSH       EAX
    //         0043986f     MOV        byte ptr [ESP + param_1+0x2],CL
    //         00439873     CALL       strtok                                           undefined strtok()
    //         00439878     ADD        ESP,0x8
    //                              Dib.cpp:800 (8)
    //         0043987b     CMP        EAX,EBP
    //         0043987d     JZ         LAB_004399ea
    //                              Dib.cpp:803 (14)
    //         00439883     LEA        EAX=>param_1,[ESP + 0x24]
    //         00439887     PUSH       EAX
    //         00439888     PUSH       EBP
    //         00439889     CALL       strtok                                           undefined strtok()
    //         0043988e     ADD        ESP,0x8
    //                              Dib.cpp:804 (8)
    //         00439891     CMP        EAX,EBP
    //         00439893     JZ         LAB_004399ea
    //                              Dib.cpp:807 (14)
    //         00439899     LEA        ECX=>param_1,[ESP + 0x24]
    //         0043989d     PUSH       ECX
    //         0043989e     PUSH       EBP
    //         0043989f     CALL       strtok                                           undefined strtok()
    //         004398a4     ADD        ESP,0x8
    //                              Dib.cpp:808 (8)
    //         004398a7     CMP        EAX,EBP
    //         004398a9     JZ         LAB_004399ea
    //                              Dib.cpp:810 (11)
    //         004398af     PUSH       EAX
    //         004398b0     CALL       atol                                             undefined atol()
    //         004398b5     MOV        EBX,EAX
    //         004398b7     ADD        ESP,0x4
    //                              Dib.cpp:811 (18)
    //         004398ba     LEA        EDX,[EBX*0x4 + 0x8]
    //         004398c1     PUSH       EDX
    //         004398c2     CALL       malloc                                           undefined malloc()
    //         004398c7     MOV        EDI,EAX
    //         004398c9     ADD        ESP,0x4
    //                              Dib.cpp:812 (2)
    //         004398cc     XOR        ESI,ESI
    //                              Dib.cpp:813 (12)
    //         004398ce     CMP        EDI,EBP
    //         004398d0     MOV        dword ptr [ESP + param_2],ESI
    //         004398d4     JZ         LAB_004399ea
    //                              Dib.cpp:817 (13)
    //         004398da     CMP        EBX,EBP
    //         004398dc     MOV        word ptr [EDI + 0x2],BX
    //         004398e0     MOV        word ptr [EDI],0x300
    //         004398e5     JLE        LAB_00439965
    //                              Dib.cpp:899 (3)
    //         004398e7     LEA        ESI,[EDI + 0x5]
    //                               LAB_004398ea                                                 XREF[1]:     0043995f(j)  
    //                              Dib.cpp:819 (15)
    //         004398ea     LEA        EAX=>param_1,[ESP + 0x24]
    //         004398ee     PUSH       EAX
    //         004398ef     PUSH       0x0
    //         004398f1     CALL       strtok                                           undefined strtok()
    //         004398f6     ADD        ESP,0x8
    //                              Dib.cpp:820 (4)
    //         004398f9     TEST       EAX,EAX
    //         004398fb     JZ         LAB_00439961
    //                              Dib.cpp:822 (9)
    //         004398fd     PUSH       EAX
    //         004398fe     CALL       atoi                                             undefined atoi()
    //         00439903     ADD        ESP,0x4
    //                              Dib.cpp:824 (18)
    //         00439906     LEA        ECX=>param_1,[ESP + 0x24]
    //         0043990a     MOV        byte ptr [ESI + -0x1],AL
    //         0043990d     PUSH       ECX
    //         0043990e     PUSH       0x0
    //         00439910     CALL       strtok                                           undefined strtok()
    //         00439915     ADD        ESP,0x8
    //                              Dib.cpp:825 (4)
    //         00439918     TEST       EAX,EAX
    //         0043991a     JZ         LAB_00439961
    //                              Dib.cpp:827 (9)
    //         0043991c     PUSH       EAX
    //         0043991d     CALL       atoi                                             undefined atoi()
    //         00439922     ADD        ESP,0x4
    //                              Dib.cpp:829 (17)
    //         00439925     LEA        EDX=>param_1,[ESP + 0x24]
    //         00439929     MOV        byte ptr [ESI],AL
    //         0043992b     PUSH       EDX
    //         0043992c     PUSH       0x0
    //         0043992e     CALL       strtok                                           undefined strtok()
    //         00439933     ADD        ESP,0x8
    //                              Dib.cpp:830 (4)
    //         00439936     TEST       EAX,EAX
    //         00439938     JZ         LAB_00439961
    //                              Dib.cpp:832 (9)
    //         0043993a     PUSH       EAX
    //         0043993b     CALL       atoi                                             undefined atoi()
    //         00439940     MOV        byte ptr [ESI + 0x1],AL
    //                              Dib.cpp:836 (14)
    //         00439943     LEA        EAX,[EBX + -0x1]
    //         00439946     ADD        ESP,0x4
    //         00439949     CMP        EBP,EAX
    //         0043994b     MOV        byte ptr [ESI + 0x2],0x0
    //         0043994f     JNZ        LAB_00439959
    //                              Dib.cpp:837 (8)
    //         00439951     MOV        dword ptr [ESP + param_2],0x1
    //                               LAB_00439959                                                 XREF[1]:     0043994f(j)  
    //                              Dib.cpp:817 (12)
    //         00439959     INC        EBP
    //         0043995a     ADD        ESI,0x4
    //         0043995d     CMP        EBP,EBX
    //         0043995f     JL         LAB_004398ea
    //                               LAB_00439961                                                 XREF[3]:     004398fb(j), 0043991a(j), 
    //                                                                                                         00439938(j)  
    //         00439961     MOV        ESI,dword ptr [ESP + param_2]
    //                               LAB_00439965                                                 XREF[1]:     004398e5(j)  
    //                              Dib.cpp:840 (12)
    //         00439965     TEST       ESI,ESI
    //         00439967     JZ         LAB_004399e1
    //         00439969     CMP        EBX,0x100
    //         0043996f     JNZ        LAB_004399a3
    //                              Dib.cpp:843 (9)
    //         00439971     MOV        EAX,[System_color_Table]                         = 00000000
    //         00439976     TEST       EAX,EAX
    //         00439978     JL         LAB_004399a3
    //                              Dib.cpp:899 (5)
    //         0043997a     MOV        ECX,DAT_005841e5
    //                               LAB_0043997f                                                 XREF[1]:     004399a1(j)  
    //                              Dib.cpp:846 (3)
    //         0043997f     MOV        DL,byte ptr [ECX + -0x1]=>DAT_005841e4           = 80h
    //                              Dib.cpp:850 (33)
    //         00439982     ADD        ECX,0x8
    //         00439985     MOV        byte ptr [EDI + EAX*0x4 + 0x4],DL
    //         00439989     MOV        DL,byte ptr [ECX + -0x8]=>DAT_005841e5
    //         0043998c     MOV        byte ptr [EDI + EAX*0x4 + 0x5],DL
    //         00439990     MOV        DL,byte ptr [ECX + -0x7]=>DAT_005841e6
    //         00439993     MOV        byte ptr [EDI + EAX*0x4 + 0x6],DL
    //         00439997     MOV        byte ptr [EDI + EAX*0x4 + 0x7],0x0
    //         0043999c     MOV        EAX,dword ptr [ECX + -0x5]=>DAT_005841e8         = 00000001h
    //                                                                                  = 00000002h
    //         0043999f     TEST       EAX,EAX
    //         004399a1     JGE        LAB_0043997f
    //                               LAB_004399a3                                                 XREF[2]:     0043996f(j), 00439978(j)  
    //                              Dib.cpp:854 (4)
    //         004399a3     TEST       ESI,ESI
    //         004399a5     JZ         LAB_004399e1
    //                              Dib.cpp:856 (11)
    //         004399a7     PUSH       EDI
    //         004399a8     CALL       dword ptr [->GDI32.DLL::CreatePalette]           = 0048b204
    //         004399ae     MOV        dword ptr [ESP + 0x18],EAX
    //                              Dib.cpp:858 (34)
    //         004399b2     MOV        EAX,dword ptr [ESP + 0x2c]
    //         004399b6     TEST       EAX,EAX
    //         004399b8     JZ         LAB_004399e1
    //         004399ba     MOV        EAX,[rge_base_game]                              = 00000000
    //         004399bf     MOV        EAX,dword ptr [EAX + 0x48]
    //         004399c2     CMP        byte ptr [EAX + 0x478],0x1
    //         004399c9     JZ         LAB_004399d4
    //         004399cb     CMP        byte ptr [EAX + 0x479],0x1
    //         004399d2     JNZ        LAB_004399e1
    //                               LAB_004399d4                                                 XREF[1]:     004399c9(j)  
    //                              Dib.cpp:859 (13)
    //         004399d4     MOV        ECX,dword ptr [ESP + 0x18]
    //         004399d8     PUSH       ECX
    //         004399d9     CALL       CreateIdentityPalette                            void CreateIdentityPalette(void * param_1)
    //         004399de     ADD        ESP,0x4
    //                               LAB_004399e1                                                 XREF[4]:     00439967(j), 004399a5(j), 
    //                                                                                                         004399b8(j), 004399d2(j)  
    //                              Dib.cpp:861 (9)
    //         004399e1     PUSH       EDI
    //         004399e2     CALL       free                                             undefined free()
    //         004399e7     ADD        ESP,0x4
    //                               LAB_004399ea                                                 XREF[4]:     0043987d(j), 00439893(j), 
    //                                                                                                         004398a9(j), 004398d4(j)  
    //                              Dib.cpp:895 (7)
    //         004399ea     CMP        dword ptr [ESP + hpal],0x1
    //         004399ef     JNZ        LAB_004399fe
    //                              Dib.cpp:896 (13)
    //         004399f1     MOV        EDX,dword ptr [ESP + own_mem]
    //         004399f5     PUSH       EDX
    //         004399f6     CALL       free                                             undefined free()
    //         004399fb     ADD        ESP,0x4
    //                               LAB_004399fe                                                 XREF[1]:     004399ef(j)  
    //                              Dib.cpp:898 (4)
    //         004399fe     MOV        EAX,dword ptr [ESP + 0x18]
    //                              Dib.cpp:899 (8)
    //         00439a02     POP        EDI
    //         00439a03     POP        ESI
    //         00439a04     POP        EBP
    //         00439a05     POP        EBX
    //         00439a06     ADD        ESP,0x10
    //         00439a09     RET
    //         00439a0a     ??         90h
    //         00439a0b     NOP
    //         00439a0c     NOP
    //         00439a0d     NOP
    //         00439a0e     NOP
    //         00439a0f     NOP
    //                              * struct tagBITMAPINFOHEADER * __cdecl DibOpenFile(char *)                                              *
    //                              tagBITMAPINFOHEADER * __cdecl DibOpenFile(char * param_1)
    //              tagBITMAPINFOH    EAX:4          <RETURN>
    //              char *            Stack[0x4]:4   param_1                   XREF[1]:     00439a1a(R)  
    //              _OFSTRUCT         Stack[-0x8c]   of                        XREF[0,1]:   00439a21(*)  
    //              ulong             Stack[-0x90]:4 dwBits
    //              int               Stack[-0x94]:4 fh
    //                               ?DibOpenFile@@YAPAUtagBITMAPINFOHEADER@@PAD@Z                XREF[4]:     GetPaletteFromDib:00439706(c), 
    //                               DibOpenFile                                                               Load:0046e0e7(c), 
    //                                                                                                         Load:0046e12f(c), 
    //                                                                                                         Load:0046e153(c)  
    //                              Dib.cpp:930 (10)
    //         00439a10     SUB        ESP,0x90
    //         00439a16     PUSH       EBX
    //         00439a17     PUSH       EBP
    //         00439a18     PUSH       ESI
    //         00439a19     PUSH       EDI
    //                              Dib.cpp:944 (23)
    //         00439a1a     MOV        EDI,dword ptr [ESP + param_1]
    //         00439a21     LEA        EAX=>of.Reserved1,[ESP + 0x18]
    //         00439a25     PUSH       0x0
    //         00439a27     PUSH       EAX
    //         00439a28     PUSH       EDI
    //         00439a29     CALL       dword ptr [->KERNEL32.DLL::OpenFile]             = 0048a9e6
    //         00439a2f     MOV        ESI,EAX
    //                              Dib.cpp:946 (9)
    //         00439a31     CMP        ESI,-0x1
    //         00439a34     MOV        dword ptr [ESP + 0x10],ESI
    //         00439a38     JNZ        LAB_00439a82
    //                              Dib.cpp:950 (20)
    //         00439a3a     PUSH       0x2
    //         00439a3c     PUSH       EDI
    //         00439a3d     MOV        EDI,dword ptr [->KERNEL32.DLL::GetModuleHandleA] = 0048ab4c
    //         00439a43     PUSH       0x0
    //         00439a45     CALL       EDI=>KERNEL32.DLL::GetModuleHandleA
    //         00439a47     PUSH       EAX
    //         00439a48     CALL       dword ptr [->KERNEL32.DLL::FindResourceA]        = 0048ab3c
    //                              Dib.cpp:955 (4)
    //         00439a4e     TEST       EAX,EAX
    //         00439a50     JZ         LAB_00439a70
    //                              Dib.cpp:956 (19)
    //         00439a52     PUSH       EAX
    //         00439a53     PUSH       0x0
    //         00439a55     CALL       EDI=>KERNEL32.DLL::GetModuleHandleA
    //         00439a57     PUSH       EAX
    //         00439a58     CALL       dword ptr [->KERNEL32.DLL::LoadResource]         = 0048ab2c
    //         00439a5e     PUSH       EAX
    //         00439a5f     CALL       dword ptr [->KERNEL32.DLL::LockResource]         = 0048ab1c
    //                              Dib.cpp:1003 (11)
    //         00439a65     POP        EDI
    //         00439a66     POP        ESI
    //         00439a67     POP        EBP
    //         00439a68     POP        EBX
    //         00439a69     ADD        ESP,0x90
    //         00439a6f     RET
    //                               LAB_00439a70                                                 XREF[1]:     00439a50(j)  
    //                              Dib.cpp:963 (5)
    //         00439a70     CMP        ESI,-0x1
    //         00439a73     JNZ        LAB_00439a82
    //                              Dib.cpp:965 (2)
    //         00439a75     XOR        EAX,EAX
    //                              Dib.cpp:1003 (11)
    //         00439a77     POP        EDI
    //         00439a78     POP        ESI
    //         00439a79     POP        EBP
    //         00439a7a     POP        EBX
    //         00439a7b     ADD        ESP,0x90
    //         00439a81     RET
    //                               LAB_00439a82                                                 XREF[2]:     00439a38(j), 00439a73(j)  
    //                              Dib.cpp:968 (11)
    //         00439a82     PUSH       ESI
    //         00439a83     CALL       DibReadBitmapInfo                                tagBITMAPINFOHEADER * DibReadBitmapInfo(int p
    //         00439a88     MOV        ESI,EAX
    //         00439a8a     ADD        ESP,0x4
    //                              Dib.cpp:970 (4)
    //         00439a8d     TEST       ESI,ESI
    //         00439a8f     JNZ        LAB_00439a9c
    //                              Dib.cpp:1003 (11)
    //         00439a91     POP        EDI
    //         00439a92     POP        ESI
    //         00439a93     POP        EBP
    //         00439a94     POP        EBX
    //         00439a95     ADD        ESP,0x90
    //         00439a9b     RET
    //                               LAB_00439a9c                                                 XREF[1]:     00439a8f(j)  
    //                              Dib.cpp:978 (33)
    //         00439a9c     MOV        EAX,dword ptr [ESI + 0x20]
    //         00439a9f     MOV        EDI,dword ptr [ESI + 0x14]
    //         00439aa2     TEST       EAX,EAX
    //         00439aa4     MOV        dword ptr [ESP + 0x14],EDI
    //         00439aa8     JNZ        LAB_00439abb
    //         00439aaa     MOV        CX,word ptr [ESI + 0xe]
    //         00439aae     CMP        CX,0x8
    //         00439ab2     JA         LAB_00439abb
    //         00439ab4     MOV        EAX,0x1
    //         00439ab9     SHL        EAX,CL
    //                               LAB_00439abb                                                 XREF[2]:     00439aa8(j), 00439ab2(j)  
    //         00439abb     MOV        ECX,dword ptr [ESI]
    //                              Dib.cpp:982 (43)
    //         00439abd     MOV        EBX,dword ptr [->KERNEL32.DLL::GlobalHandle]     = 0048ab0c
    //         00439ac3     LEA        EDI,[EDI + EAX*0x4]
    //         00439ac6     PUSH       ESI
    //         00439ac7     ADD        EDI,ECX
    //         00439ac9     CALL       EBX=>KERNEL32.DLL::GlobalHandle
    //         00439acb     MOV        EBP,dword ptr [->KERNEL32.DLL::GlobalUnlock]     = 0048aafc
    //         00439ad1     PUSH       EAX
    //         00439ad2     CALL       EBP=>KERNEL32.DLL::GlobalUnlock
    //         00439ad4     PUSH       0x0
    //         00439ad6     PUSH       EDI=>DAT_fffffff8
    //         00439ad7     PUSH       ESI=>DAT_fffffff4
    //         00439ad8     CALL       EBX=>KERNEL32.DLL::GlobalHandle
    //         00439ada     PUSH       EAX
    //         00439adb     CALL       dword ptr [->KERNEL32.DLL::GlobalReAlloc]        = 0048aaec
    //         00439ae1     PUSH       EAX
    //         00439ae2     CALL       dword ptr [->KERNEL32.DLL::GlobalLock]           = 0048aade
    //                              Dib.cpp:984 (4)
    //         00439ae8     TEST       EAX,EAX
    //         00439aea     JNZ        LAB_00439b00
    //                              Dib.cpp:986 (16)
    //         00439aec     PUSH       ESI
    //         00439aed     CALL       EBX=>KERNEL32.DLL::GlobalHandle
    //         00439aef     PUSH       EAX
    //         00439af0     CALL       EBP=>KERNEL32.DLL::GlobalUnlock
    //         00439af2     PUSH       ESI
    //         00439af3     CALL       EBX=>KERNEL32.DLL::GlobalHandle
    //         00439af5     PUSH       EAX
    //         00439af6     CALL       dword ptr [->KERNEL32.DLL::GlobalFree]           = 0048aad0
    //                              Dib.cpp:987 (2)
    //         00439afc     XOR        ESI,ESI
    //                              Dib.cpp:989 (2)
    //         00439afe     JMP        LAB_00439b02
    //                               LAB_00439b00                                                 XREF[1]:     00439aea(j)  
    //                              Dib.cpp:991 (2)
    //         00439b00     MOV        ESI,EAX
    //                               LAB_00439b02                                                 XREF[1]:     00439afe(j)  
    //                              Dib.cpp:994 (4)
    //         00439b02     TEST       ESI,ESI
    //         00439b04     JZ         LAB_00439b36
    //                              Dib.cpp:997 (48)
    //         00439b06     MOV        EAX,dword ptr [ESI + 0x20]
    //         00439b09     TEST       EAX,EAX
    //         00439b0b     JNZ        LAB_00439b1e
    //         00439b0d     MOV        CX,word ptr [ESI + 0xe]
    //         00439b11     CMP        CX,0x8
    //         00439b15     JA         LAB_00439b1e
    //         00439b17     MOV        EAX,0x1
    //         00439b1c     SHL        EAX,CL
    //                               LAB_00439b1e                                                 XREF[2]:     00439b0b(j), 00439b15(j)  
    //         00439b1e     MOV        EBX,dword ptr [ESI]
    //         00439b20     MOV        ECX,dword ptr [ESP + 0x14]
    //         00439b24     LEA        EDX,[ESI + EAX*0x4]
    //         00439b27     MOV        EAX,dword ptr [ESP + 0x10]
    //         00439b2b     ADD        EDX,EBX
    //         00439b2d     PUSH       ECX
    //         00439b2e     PUSH       EDX=>DAT_fffffff8
    //         00439b2f     PUSH       EAX=>DAT_fffffff4
    //         00439b30     CALL       dword ptr [->KERNEL32.DLL::_hread]               = 0048aac6
    //                               LAB_00439b36                                                 XREF[1]:     00439b04(j)  
    //                              Dib.cpp:1000 (11)
    //         00439b36     MOV        ECX,dword ptr [ESP + 0x10]
    //         00439b3a     PUSH       ECX
    //         00439b3b     CALL       dword ptr [->KERNEL32.DLL::_lclose]              = 0048aabc
    //                              Dib.cpp:1002 (2)
    //         00439b41     MOV        EAX,ESI
    //                              Dib.cpp:1003 (11)
    //         00439b43     POP        EDI
    //         00439b44     POP        ESI
    //         00439b45     POP        EBP
    //         00439b46     POP        EBX
    //         00439b47     ADD        ESP,0x90
    //         00439b4d     RET
    //         00439b4e     ??         90h
    //         00439b4f     NOP
    //                              * unsigned char * __cdecl ReadDibBits(char *)                                                           *
    //                              uchar * __cdecl ReadDibBits(char * param_1)
    //              uchar *           EAX:4          <RETURN>
    //              char *            Stack[0x4]:4   param_1                   XREF[1]:     00439b50(R)  
    //              _OFSTRUCT         Stack[-0x8c]   of                        XREF[0,1]:   00439b5a(*)  
    //                               ?ReadDibBits@@YAPAEPAD@Z
    //                               ReadDibBits
    //                              Dib.cpp:1011 (29)
    //         00439b50     MOV        ECX,dword ptr [ESP + param_1]
    //         00439b54     SUB        ESP,0x88
    //         00439b5a     LEA        EAX=>of.Reserved1,[ESP]
    //         00439b5e     PUSH       EBP
    //         00439b5f     PUSH       EDI
    //         00439b60     XOR        EDI,EDI
    //         00439b62     PUSH       EDI
    //         00439b63     PUSH       EAX
    //         00439b64     PUSH       ECX
    //         00439b65     CALL       dword ptr [->KERNEL32.DLL::OpenFile]             = 0048a9e6
    //         00439b6b     MOV        EBP,EAX
    //                              Dib.cpp:1019 (5)
    //         00439b6d     CMP        EBP,-0x1
    //         00439b70     JNZ        LAB_00439b7d
    //                              Dib.cpp:1020 (2)
    //         00439b72     XOR        EAX,EAX
    //                              Dib.cpp:1035 (9)
    //         00439b74     POP        EDI
    //         00439b75     POP        EBP
    //         00439b76     ADD        ESP,0x88
    //         00439b7c     RET
    //                               LAB_00439b7d                                                 XREF[1]:     00439b70(j)  
    //                              Dib.cpp:1011 (2)
    //         00439b7d     PUSH       ESI
    //         00439b7e     PUSH       EBX
    //                              Dib.cpp:1022 (11)
    //         00439b7f     PUSH       EBP
    //         00439b80     CALL       DibReadBitmapInfo                                tagBITMAPINFOHEADER * DibReadBitmapInfo(int p
    //         00439b85     MOV        ESI,EAX
    //         00439b87     ADD        ESP,0x4
    //                              Dib.cpp:1023 (4)
    //         00439b8a     TEST       ESI,ESI
    //         00439b8c     JZ         LAB_00439bc3
    //                              Dib.cpp:1026 (29)
    //         00439b8e     MOV        EDI,dword ptr [->KERNEL32.DLL::GlobalHandle]     = 0048ab0c
    //         00439b94     MOV        EBX,dword ptr [ESI + 0x14]
    //         00439b97     PUSH       ESI
    //         00439b98     CALL       EDI=>KERNEL32.DLL::GlobalHandle
    //         00439b9a     PUSH       EAX
    //         00439b9b     CALL       dword ptr [->KERNEL32.DLL::GlobalUnlock]         = 0048aafc
    //         00439ba1     PUSH       ESI
    //         00439ba2     CALL       EDI=>KERNEL32.DLL::GlobalHandle
    //         00439ba4     PUSH       EAX
    //         00439ba5     CALL       dword ptr [->KERNEL32.DLL::GlobalFree]           = 0048aad0
    //                              Dib.cpp:1027 (11)
    //         00439bab     PUSH       EBX
    //         00439bac     CALL       malloc                                           undefined malloc()
    //         00439bb1     MOV        EDI,EAX
    //         00439bb3     ADD        ESP,0x4
    //                              Dib.cpp:1028 (4)
    //         00439bb6     TEST       EDI,EDI
    //         00439bb8     JZ         LAB_00439bc3
    //                              Dib.cpp:1029 (9)
    //         00439bba     PUSH       EBX
    //         00439bbb     PUSH       EDI=>DAT_fffffff8
    //         00439bbc     PUSH       EBP=>DAT_fffffff4
    //         00439bbd     CALL       dword ptr [->KERNEL32.DLL::_hread]               = 0048aac6
    //                               LAB_00439bc3                                                 XREF[2]:     00439b8c(j), 00439bb8(j)  
    //                              Dib.cpp:1032 (8)
    //         00439bc3     PUSH       EBP
    //         00439bc4     CALL       dword ptr [->KERNEL32.DLL::_lclose]              = 0048aabc
    //         00439bca     POP        EBX
    //                              Dib.cpp:1034 (3)
    //         00439bcb     MOV        EAX,EDI
    //         00439bcd     POP        ESI
    //                              Dib.cpp:1035 (9)
    //         00439bce     POP        EDI
    //         00439bcf     POP        EBP
    //         00439bd0     ADD        ESP,0x88
    //         00439bd6     RET
    //         00439bd7     ??         90h
    //         00439bd8     NOP
    //         00439bd9     NOP
    //         00439bda     NOP
    //         00439bdb     NOP
    //         00439bdc     NOP
    //         00439bdd     NOP
    //         00439bde     NOP
    //         00439bdf     NOP
    //                              * int __cdecl DibWriteClipped(struct tagBITMAPINFOHEADER *,char *,long,long,long,long)                  *
    //                              int __cdecl DibWriteClipped(tagBITMAPINFOHEADER * param_1, char * pa
    //              int               EAX:4          <RETURN>
    //              tagBITMAPINFOH    Stack[0x4]:4   param_1                   XREF[1]:     00439c02(R)  
    //              char *            Stack[0x8]:4   param_2                   XREF[1]:     00439c90(R)  
    //              long              Stack[0xc]:4   param_3                   XREF[1]:     00439c7a(R)  
    //              long              Stack[0x10]:4  param_4                   XREF[1]:     00439c6d(R)  
    //              long              Stack[0x14]:4  param_5                   XREF[1]:     00439be6(R)  
    //              long              Stack[0x18]:4  param_6                   XREF[1]:     00439be1(R)  
    //                               ?DibWriteClipped@@YAHPAUtagBITMAPINFOHEADER@@PADJJJJ@Z
    //                               DibWriteClipped
    //                              Dib.cpp:1042 (1)
    //         00439be0     PUSH       EBX
    //                              Dib.cpp:1043 (24)
    //         00439be1     MOV        EBX,dword ptr [ESP + param_6]
    //         00439be5     PUSH       EBP
    //         00439be6     MOV        EBP,dword ptr [ESP + param_5]
    //         00439bea     PUSH       ESI
    //         00439beb     PUSH       EBX
    //         00439bec     PUSH       EBP
    //         00439bed     PUSH       0x8
    //         00439bef     CALL       DibCreate                                        tagBITMAPINFOHEADER * DibCreate(int param_1, 
    //         00439bf4     MOV        ESI,EAX
    //         00439bf6     ADD        ESP,0xc
    //                              Dib.cpp:1045 (4)
    //         00439bf9     TEST       ESI,ESI
    //         00439bfb     JNZ        LAB_00439c01
    //                              Dib.cpp:1059 (4)
    //         00439bfd     POP        ESI
    //         00439bfe     POP        EBP
    //         00439bff     POP        EBX
    //         00439c00     RET
    //                               LAB_00439c01                                                 XREF[1]:     00439bfb(j)  
    //                              Dib.cpp:1042 (1)
    //         00439c01     PUSH       EDI
    //                              Dib.cpp:1048 (51)
    //         00439c02     MOV        EDI,dword ptr [ESP + param_1]
    //         00439c06     MOV        EAX,dword ptr [EDI + 0x20]
    //         00439c09     TEST       EAX,EAX
    //         00439c0b     JNZ        LAB_00439c1e
    //         00439c0d     MOV        CX,word ptr [EDI + 0xe]
    //         00439c11     CMP        CX,0x8
    //         00439c15     JA         LAB_00439c1e
    //         00439c17     MOV        EAX,0x1
    //         00439c1c     SHL        EAX,CL
    //                               LAB_00439c1e                                                 XREF[2]:     00439c0b(j), 00439c15(j)  
    //         00439c1e     SHL        EAX,0x2
    //         00439c21     PUSH       EAX
    //         00439c22     MOV        EAX,dword ptr [EDI]
    //         00439c24     MOV        ECX,EDI
    //         00439c26     MOV        EDX,ESI
    //         00439c28     ADD        ECX,EAX
    //         00439c2a     PUSH       ECX
    //         00439c2b     MOV        ECX,dword ptr [ESI]
    //         00439c2d     ADD        EDX,ECX
    //         00439c2f     PUSH       EDX
    //         00439c30     CALL       memcpy                                           undefined memcpy()
    //                              Dib.cpp:1052 (91)
    //         00439c35     MOV        ECX,dword ptr [EDI + 0x10]
    //         00439c38     MOV        EAX,0x3
    //         00439c3d     ADD        ESP,0xc
    //         00439c40     CMP        ECX,EAX
    //         00439c42     JNZ        LAB_00439c4c
    //         00439c44     MOV        ECX,dword ptr [EDI]
    //         00439c46     LEA        ECX,[EDI + ECX*0x1 + 0xc]
    //         00439c4a     JMP        LAB_00439c56
    //                               LAB_00439c4c                                                 XREF[1]:     00439c42(j)  
    //         00439c4c     MOV        EDX,dword ptr [EDI + 0x20]
    //         00439c4f     LEA        ECX,[EDI + EDX*0x4]
    //         00439c52     MOV        EDX,dword ptr [EDI]
    //         00439c54     ADD        ECX,EDX
    //                               LAB_00439c56                                                 XREF[1]:     00439c4a(j)  
    //         00439c56     CMP        dword ptr [ESI + 0x10],EAX
    //         00439c59     JNZ        LAB_00439c63
    //         00439c5b     MOV        EAX,dword ptr [ESI]
    //         00439c5d     LEA        EAX,[ESI + EAX*0x1 + 0xc]
    //         00439c61     JMP        LAB_00439c6d
    //                               LAB_00439c63                                                 XREF[1]:     00439c59(j)  
    //         00439c63     MOV        EDX,dword ptr [ESI + 0x20]
    //         00439c66     LEA        EAX,[ESI + EDX*0x4]
    //         00439c69     MOV        EDX,dword ptr [ESI]
    //         00439c6b     ADD        EAX,EDX
    //                               LAB_00439c6d                                                 XREF[1]:     00439c61(j)  
    //         00439c6d     MOV        EDX,dword ptr [ESP + param_4]
    //         00439c71     PUSH       0x0
    //         00439c73     PUSH       0x0
    //         00439c75     PUSH       0x1
    //         00439c77     PUSH       EBX
    //         00439c78     PUSH       EBP
    //         00439c79     PUSH       EDX
    //         00439c7a     MOV        EDX,dword ptr [ESP + param_3]
    //         00439c7e     PUSH       EDX
    //         00439c7f     PUSH       ECX
    //         00439c80     PUSH       EDI
    //         00439c81     PUSH       EBX
    //         00439c82     PUSH       EBP
    //         00439c83     PUSH       0x0
    //         00439c85     PUSH       0x0
    //         00439c87     PUSH       0x0
    //         00439c89     PUSH       EAX
    //         00439c8a     PUSH       ESI
    //         00439c8b     CALL       DibBlt                                           void DibBlt(BITMAPINFO256 * param_1, uchar * 
    //                              Dib.cpp:1054 (17)
    //         00439c90     MOV        EAX,dword ptr [ESP + param_2]
    //         00439c94     ADD        ESP,0x40
    //         00439c97     PUSH       EAX
    //         00439c98     PUSH       ESI
    //         00439c99     CALL       DibWriteFile                                     int DibWriteFile(tagBITMAPINFOHEADER * param_
    //         00439c9e     ADD        ESP,0x8
    //                              Dib.cpp:1056 (9)
    //         00439ca1     PUSH       ESI
    //         00439ca2     CALL       DibFree                                          void DibFree(tagBITMAPINFOHEADER * param_1)
    //         00439ca7     ADD        ESP,0x4
    //                              Dib.cpp:1058 (6)
    //         00439caa     MOV        EAX,0x1
    //         00439caf     POP        EDI
    //                              Dib.cpp:1059 (4)
    //         00439cb0     POP        ESI
    //         00439cb1     POP        EBP
    //         00439cb2     POP        EBX
    //         00439cb3     RET
    //         00439cb4     ??         90h
    //         00439cb5     NOP
    //         00439cb6     NOP
    //         00439cb7     NOP
    //         00439cb8     NOP
    //         00439cb9     NOP
    //         00439cba     NOP
    //         00439cbb     NOP
    //         00439cbc     NOP
    //         00439cbd     NOP
    //         00439cbe     NOP
    //         00439cbf     NOP
    //                              * int __cdecl DibWriteFile(struct tagBITMAPINFOHEADER *,char *)                                         *
    //                              int __cdecl DibWriteFile(tagBITMAPINFOHEADER * param_1, char * param
    //              int               EAX:4          <RETURN>
    //              tagBITMAPINFOH    Stack[0x4]:4   param_1                   XREF[1]:     00439cc9(R)  
    //              char *            Stack[0x8]:4   param_2                   XREF[1]:     00439ce0(R)  
    //              _OFSTRUCT         Stack[-0x8c]   of                        XREF[0,1]:   00439ce7(*)  
    //              tagBITMAPFILEH    Stack[-0x9c]   hdr
    //                               ?DibWriteFile@@YAHPAUtagBITMAPINFOHEADER@@PAD@Z              XREF[1]:     DibWriteClipped:00439c99(c)  
    //                               DibWriteFile
    //                              Dib.cpp:1066 (9)
    //         00439cc0     SUB        ESP,0x98
    //         00439cc6     PUSH       EBP
    //         00439cc7     PUSH       ESI
    //         00439cc8     PUSH       EDI
    //                              Dib.cpp:1072 (11)
    //         00439cc9     MOV        EDI,dword ptr [ESP + param_1]
    //         00439cd0     TEST       EDI,EDI
    //         00439cd2     JNZ        LAB_00439ce0
    //                              Dib.cpp:1073 (2)
    //         00439cd4     XOR        EAX,EAX
    //                              Dib.cpp:1095 (10)
    //         00439cd6     POP        EDI
    //         00439cd7     POP        ESI
    //         00439cd8     POP        EBP
    //         00439cd9     ADD        ESP,0x98
    //         00439cdf     RET
    //                               LAB_00439ce0                                                 XREF[1]:     00439cd2(j)  
    //                              Dib.cpp:1075 (26)
    //         00439ce0     MOV        ECX,dword ptr [ESP + param_2]
    //         00439ce7     LEA        EAX=>of.Reserved1,[ESP + 0x1c]
    //         00439ceb     PUSH       0x1002
    //         00439cf0     PUSH       EAX
    //         00439cf1     PUSH       ECX
    //         00439cf2     CALL       dword ptr [->KERNEL32.DLL::OpenFile]             = 0048a9e6
    //         00439cf8     MOV        EBP,EAX
    //                              Dib.cpp:1077 (5)
    //         00439cfa     CMP        EBP,-0x1
    //         00439cfd     JNZ        LAB_00439d0b
    //                              Dib.cpp:1078 (2)
    //         00439cff     XOR        EAX,EAX
    //                              Dib.cpp:1095 (10)
    //         00439d01     POP        EDI
    //         00439d02     POP        ESI
    //         00439d03     POP        EBP
    //         00439d04     ADD        ESP,0x98
    //         00439d0a     RET
    //                               LAB_00439d0b                                                 XREF[1]:     00439cfd(j)  
    //                              Dib.cpp:1080 (8)
    //         00439d0b     MOV        EAX,dword ptr [EDI + 0x20]
    //         00439d0e     MOV        ECX,dword ptr [EDI + 0x14]
    //         00439d11     MOV        EDX,dword ptr [EDI]
    //                              Dib.cpp:1082 (10)
    //         00439d13     MOV        word ptr [ESP + 0xc],0x4d42
    //         00439d1a     LEA        ESI,[ECX + EAX*0x4]
    //                              Dib.cpp:1084 (9)
    //         00439d1d     MOV        word ptr [ESP + 0x12],0x0
    //         00439d24     ADD        ESI,EDX
    //                              Dib.cpp:1085 (7)
    //         00439d26     MOV        word ptr [ESP + 0x14],0x0
    //                              Dib.cpp:1087 (32)
    //         00439d2d     TEST       EAX,EAX
    //         00439d2f     LEA        ECX,[ESI + 0xe]
    //         00439d32     MOV        dword ptr [ESP + 0xe],ECX
    //         00439d36     JNZ        LAB_00439d49
    //         00439d38     MOV        CX,word ptr [EDI + 0xe]
    //         00439d3c     CMP        CX,0x8
    //         00439d40     JA         LAB_00439d49
    //         00439d42     MOV        EAX,0x1
    //         00439d47     SHL        EAX,CL
    //                               LAB_00439d49                                                 XREF[2]:     00439d36(j), 00439d40(j)  
    //         00439d49     LEA        EDX,[EDX + EAX*0x4 + 0xe]
    //                              Dib.cpp:1089 (18)
    //         00439d4d     LEA        EAX,[ESP + 0xc]
    //         00439d51     PUSH       0xe
    //         00439d53     PUSH       EAX
    //         00439d54     PUSH       EBP
    //         00439d55     MOV        dword ptr [ESP + 0x22],EDX
    //         00439d59     CALL       dword ptr [->KERNEL32.DLL::_lwrite]              = 0048ab6a
    //                              Dib.cpp:1090 (9)
    //         00439d5f     PUSH       ESI
    //         00439d60     PUSH       EDI
    //         00439d61     PUSH       EBP
    //         00439d62     CALL       dword ptr [->KERNEL32.DLL::_hwrite]              = 0048ab60
    //                              Dib.cpp:1092 (7)
    //         00439d68     PUSH       EBP
    //         00439d69     CALL       dword ptr [->KERNEL32.DLL::_lclose]              = 0048aabc
    //                              Dib.cpp:1095 (15)
    //         00439d6f     POP        EDI
    //         00439d70     POP        ESI
    //         00439d71     MOV        EAX,0x1
    //         00439d76     POP        EBP
    //         00439d77     ADD        ESP,0x98
    //         00439d7d     RET
    //         00439d7e     ??         90h
    //         00439d7f     NOP
    //                              * void * __cdecl DibCreatePalette(struct tagBITMAPINFOHEADER *)                                         *
    //                              void * __cdecl DibCreatePalette(tagBITMAPINFOHEADER * param_1)
    //              void *            EAX:4          <RETURN>
    //              tagBITMAPINFOH    Stack[0x4]:4   param_1                   XREF[1]:     00439d83(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     00439d8b(W)  
    //              void *            Stack[-0x8]:4  hpal
    //                               ?DibCreatePalette@@YAPAXPAUtagBITMAPINFOHEADER@@@Z           XREF[1]:     GetPaletteFromDib:00439718(c)  
    //                               DibCreatePalette
    //                              Dib.cpp:1105 (3)
    //         00439d80     PUSH       ECX
    //         00439d81     PUSH       EBX
    //         00439d82     PUSH       ESI
    //                              Dib.cpp:1112 (14)
    //         00439d83     MOV        ESI,dword ptr [ESP + param_1]
    //         00439d87     XOR        EBX,EBX
    //         00439d89     CMP        ESI,EBX
    //         00439d8b     MOV        dword ptr [ESP + local_4],EBX
    //         00439d8f     JNZ        LAB_00439d97
    //                              Dib.cpp:1113 (2)
    //         00439d91     XOR        EAX,EAX
    //                              Dib.cpp:1155 (4)
    //         00439d93     POP        ESI
    //         00439d94     POP        EBX
    //         00439d95     POP        ECX
    //         00439d96     RET
    //                               LAB_00439d97                                                 XREF[1]:     00439d8f(j)  
    //                              Dib.cpp:1105 (1)
    //         00439d97     PUSH       EDI
    //                              Dib.cpp:1115 (25)
    //         00439d98     MOV        EDI,dword ptr [ESI + 0x20]
    //         00439d9b     CMP        EDI,EBX
    //         00439d9d     PUSH       EBP
    //         00439d9e     JNZ        LAB_00439db1
    //         00439da0     MOV        CX,word ptr [ESI + 0xe]
    //         00439da4     CMP        CX,0x8
    //         00439da8     JA         LAB_00439db1
    //         00439daa     MOV        EDI,0x1
    //         00439daf     SHL        EDI,CL
    //                               LAB_00439db1                                                 XREF[2]:     00439d9e(j), 00439da8(j)  
    //                              Dib.cpp:1117 (10)
    //         00439db1     CMP        EDI,0x3
    //         00439db4     JNZ        LAB_00439dbd
    //         00439db6     CMP        dword ptr [ESI + 0x10],EDI
    //         00439db9     JNZ        LAB_00439dbd
    //                              Dib.cpp:1118 (2)
    //         00439dbb     XOR        EDI,EDI
    //                               LAB_00439dbd                                                 XREF[2]:     00439db4(j), 00439db9(j)  
    //                              Dib.cpp:1120 (4)
    //         00439dbd     CMP        EDI,EBX
    //         00439dbf     JLE        LAB_00439e25
    //                              Dib.cpp:1122 (2)
    //         00439dc1     MOV        EBP,dword ptr [ESI]
    //                              Dib.cpp:1123 (20)
    //         00439dc3     LEA        EAX,[EDI*0x4 + 0x8]
    //         00439dca     PUSH       EAX
    //         00439dcb     PUSH       0x40
    //         00439dcd     ADD        ESI,EBP
    //         00439dcf     CALL       dword ptr [->KERNEL32.DLL::LocalAlloc]           = 0048ab80
    //         00439dd5     MOV        EBP,EAX
    //                              Dib.cpp:1125 (4)
    //         00439dd7     CMP        EBP,EBX
    //         00439dd9     JZ         LAB_00439e41
    //                              Dib.cpp:1131 (14)
    //         00439ddb     CMP        EDI,EBX
    //         00439ddd     MOV        word ptr [EBP + 0x2],DI
    //         00439de1     MOV        word ptr [EBP],0x300
    //         00439de7     JLE        LAB_00439e09
    //                              Dib.cpp:1155 (3)
    //         00439de9     LEA        EAX,[EBP + 0x5]
    //                               LAB_00439dec                                                 XREF[1]:     00439e07(j)  
    //                              Dib.cpp:1133 (3)
    //         00439dec     MOV        CL,byte ptr [ESI + 0x2]
    //                              Dib.cpp:1138 (26)
    //         00439def     ADD        ESI,0x4
    //         00439df2     MOV        byte ptr [EAX + -0x1],CL
    //         00439df5     MOV        DL,byte ptr [ESI + -0x3]
    //         00439df8     MOV        byte ptr [EAX],DL
    //         00439dfa     MOV        CL,byte ptr [ESI + -0x4]
    //         00439dfd     MOV        byte ptr [EAX + 0x1],CL
    //         00439e00     MOV        byte ptr [EAX + 0x2],BL
    //         00439e03     ADD        EAX,0x4
    //         00439e06     DEC        EDI
    //         00439e07     JNZ        LAB_00439dec
    //                               LAB_00439e09                                                 XREF[1]:     00439de7(j)  
    //                              Dib.cpp:1141 (7)
    //         00439e09     PUSH       EBP
    //         00439e0a     CALL       dword ptr [->GDI32.DLL::CreatePalette]           = 0048b204
    //                              Dib.cpp:1142 (11)
    //         00439e10     PUSH       EBP
    //         00439e11     MOV        dword ptr [ESP + 0x14],EAX
    //         00439e15     CALL       dword ptr [->KERNEL32.DLL::LocalFree]            = 0048ab74
    //                              Dib.cpp:1154 (6)
    //         00439e1b     MOV        EAX,dword ptr [ESP + 0x10]
    //         00439e1f     POP        EBP
    //         00439e20     POP        EDI
    //                              Dib.cpp:1155 (4)
    //         00439e21     POP        ESI
    //         00439e22     POP        EBX
    //         00439e23     POP        ECX
    //         00439e24     RET
    //                               LAB_00439e25                                                 XREF[1]:     00439dbf(j)  
    //                              Dib.cpp:1147 (9)
    //         00439e25     PUSH       EBX
    //         00439e26     CALL       dword ptr [->USER32.DLL::GetDC]                  = 0048ae28
    //         00439e2c     MOV        ESI,EAX
    //                              Dib.cpp:1148 (7)
    //         00439e2e     PUSH       ESI
    //         00439e2f     CALL       dword ptr [->GDI32.DLL::CreateHalftonePalette]   = 0048b214
    //                              Dib.cpp:1149 (12)
    //         00439e35     PUSH       ESI
    //         00439e36     PUSH       EBX=>DAT_fffffff8
    //         00439e37     MOV        dword ptr [ESP + 0x18],EAX
    //         00439e3b     CALL       dword ptr [->USER32.DLL::ReleaseDC]              = 0048ae1c
    //                              Symbol Ref: No symbol: exit
    //                               LAB_00439e41                                                 XREF[1]:     00439dd9(j)  
    //                              Dib.cpp:1154 (6)
    //         00439e41     MOV        EAX,dword ptr [ESP + 0x10]
    //         00439e45     POP        EBP
    //         00439e46     POP        EDI
    //                              Dib.cpp:1155 (4)
    //         00439e47     POP        ESI
    //         00439e48     POP        EBX
    //         00439e49     POP        ECX
    //         00439e4a     RET
    //         00439e4b     ??         90h
    //         00439e4c     NOP
    //         00439e4d     NOP
    //         00439e4e     NOP
    //         00439e4f     NOP
    //                              * struct tagBITMAPINFOHEADER * __cdecl DibReadBitmapInfo(int)                                           *
    //                              tagBITMAPINFOHEADER * __cdecl DibReadBitmapInfo(int param_1)
    //              tagBITMAPINFOH    EAX:4          <RETURN>
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     00439e54(R)  
    //              tagBITMAPINFOH    Stack[-0x2c]   bi
    //              tagBITMAPFILEH    Stack[-0x3c]   bf                        XREF[0,1]:   00439e7a(*)  
    //              tagBITMAPCOREH    Stack[-0x48]   bc                        XREF[1]:     00439e82(W)  
    //              ulong             Stack[-0x4c]:4 off
    //              tagBITMAPINFOH    Stack[-0x54]:4 pdib
    //                               ?DibReadBitmapInfo@@YAPAUtagBITMAPINFOHEADER@@H@Z            XREF[2]:     DibOpenFile:00439a83(c), 
    //                               DibReadBitmapInfo                                                         ReadDibBits:00439b80(c)  
    //                              Dib.cpp:1166 (4)
    //         00439e50     SUB        ESP,0x50
    //         00439e53     PUSH       EBX
    //                              Dib.cpp:1179 (12)
    //         00439e54     MOV        EBX,dword ptr [ESP + param_1]
    //         00439e58     PUSH       EBP
    //         00439e59     PUSH       ESI
    //         00439e5a     CMP        EBX,-0x1
    //         00439e5d     PUSH       EDI
    //         00439e5e     JNZ        LAB_00439e6a
    //                              Dib.cpp:1180 (2)
    //         00439e60     XOR        EAX,EAX
    //                              Dib.cpp:1280 (8)
    //         00439e62     POP        EDI
    //         00439e63     POP        ESI
    //         00439e64     POP        EBP
    //         00439e65     POP        EBX
    //         00439e66     ADD        ESP,0x50
    //         00439e69     RET
    //                               LAB_00439e6a                                                 XREF[1]:     00439e5e(j)  
    //                              Dib.cpp:1182 (16)
    //         00439e6a     MOV        EDI,dword ptr [->KERNEL32.DLL::_llseek]          = 0048aba6
    //         00439e70     XOR        ESI,ESI
    //         00439e72     PUSH       0x1
    //         00439e74     PUSH       ESI
    //         00439e75     PUSH       EBX
    //         00439e76     CALL       EDI=>KERNEL32.DLL::_llseek
    //         00439e78     MOV        EBP,EAX
    //                              Dib.cpp:1184 (23)
    //         00439e7a     LEA        EAX=>bf+0x4,[ESP + 0x28]
    //         00439e7e     PUSH       0xe
    //         00439e80     PUSH       EAX
    //         00439e81     PUSH       EBX
    //         00439e82     MOV        dword ptr [ESP + bc.bcSize],EBP
    //         00439e86     CALL       dword ptr [->KERNEL32.DLL::_lread]               = 0048ab9c
    //         00439e8c     CMP        EAX,0xe
    //         00439e8f     JZ         LAB_00439e9b
    //                              Dib.cpp:1185 (2)
    //         00439e91     XOR        EAX,EAX
    //                              Dib.cpp:1280 (8)
    //         00439e93     POP        EDI
    //         00439e94     POP        ESI
    //         00439e95     POP        EBP
    //         00439e96     POP        EBX
    //         00439e97     ADD        ESP,0x50
    //         00439e9a     RET
    //                               LAB_00439e9b                                                 XREF[1]:     00439e8f(j)  
    //                              Dib.cpp:1190 (9)
    //         00439e9b     CMP        word ptr [ESP + 0x28],0x4d42
    //         00439ea2     JZ         LAB_00439ead
    //                              Dib.cpp:1193 (9)
    //         00439ea4     PUSH       ESI
    //         00439ea5     PUSH       EBP
    //         00439ea6     PUSH       EBX
    //         00439ea7     MOV        dword ptr [ESP + 0x3e],ESI
    //         00439eab     CALL       EDI=>KERNEL32.DLL::_llseek
    //                               LAB_00439ead                                                 XREF[1]:     00439ea2(j)  
    //                              Dib.cpp:1196 (19)
    //         00439ead     LEA        ECX,[ESP + 0x38]
    //         00439eb1     PUSH       0x28
    //         00439eb3     PUSH       ECX
    //         00439eb4     PUSH       EBX
    //         00439eb5     CALL       dword ptr [->KERNEL32.DLL::_lread]               = 0048ab9c
    //         00439ebb     CMP        EAX,0x28
    //         00439ebe     JZ         LAB_00439eca
    //                              Dib.cpp:1197 (2)
    //         00439ec0     XOR        EAX,EAX
    //                              Dib.cpp:1280 (8)
    //         00439ec2     POP        EDI
    //         00439ec3     POP        ESI
    //         00439ec4     POP        EBP
    //         00439ec5     POP        EBX
    //         00439ec6     ADD        ESP,0x50
    //         00439ec9     RET
    //                               LAB_00439eca                                                 XREF[1]:     00439ebe(j)  
    //                              Dib.cpp:1202 (13)
    //         00439eca     MOV        EAX,dword ptr [ESP + 0x38]
    //         00439ece     CMP        EAX,0xc
    //         00439ed1     MOV        dword ptr [ESP + 0x64],EAX
    //         00439ed5     JNZ        LAB_00439f3c
    //                              Dib.cpp:1209 (20)
    //         00439ed7     MOV        ECX,dword ptr [ESP + 0x40]
    //         00439edb     MOV        dword ptr [ESP + 0x1c],EAX
    //         00439edf     MOV        EAX,dword ptr [ESP + 0x3c]
    //         00439ee3     MOV        dword ptr [ESP + 0x24],ECX
    //         00439ee7     MOV        dword ptr [ESP + 0x20],EAX
    //                              Dib.cpp:1212 (9)
    //         00439eeb     MOV        EDX,dword ptr [ESP + 0x22]
    //         00439eef     AND        EAX,0xffff
    //                              Dib.cpp:1222 (72)
    //         00439ef4     PUSH       0x1
    //         00439ef6     MOV        dword ptr [ESP + 0x40],EAX
    //         00439efa     MOV        AX,word ptr [ESP + 0x2a]
    //         00439eff     AND        EDX,0xffff
    //         00439f05     PUSH       -0x1c
    //         00439f07     PUSH       EBX
    //         00439f08     MOV        dword ptr [ESP + 0x44],0x28
    //         00439f10     MOV        dword ptr [ESP + 0x4c],EDX
    //         00439f14     MOV        word ptr [ESP + 0x50],CX
    //         00439f19     MOV        word ptr [ESP + 0x52],AX
    //         00439f1e     MOV        dword ptr [ESP + 0x54],ESI
    //         00439f22     MOV        dword ptr [ESP + 0x58],ESI
    //         00439f26     MOV        dword ptr [ESP + 0x5c],ESI
    //         00439f2a     MOV        dword ptr [ESP + 0x60],ESI
    //         00439f2e     MOV        dword ptr [ESP + 0x64],ESI
    //         00439f32     MOV        dword ptr [ESP + 0x68],ESI
    //         00439f36     CALL       EDI=>KERNEL32.DLL::_llseek
    //         00439f38     MOV        EAX,dword ptr [ESP + 0x38]
    //                               LAB_00439f3c                                                 XREF[1]:     00439ed5(j)  
    //                              Dib.cpp:1227 (31)
    //         00439f3c     MOV        EDI,dword ptr [ESP + 0x58]
    //         00439f40     CMP        EDI,ESI
    //         00439f42     JNZ        LAB_00439f59
    //         00439f44     CMP        word ptr [ESP + 0x46],0x8
    //         00439f4a     JA         LAB_00439f59
    //         00439f4c     MOV        CL,byte ptr [ESP + 0x46]
    //         00439f50     MOV        EBP,0x1
    //         00439f55     SHL        EBP,CL
    //         00439f57     JMP        LAB_00439f5b
    //                               LAB_00439f59                                                 XREF[2]:     00439f42(j), 00439f4a(j)  
    //         00439f59     MOV        EBP,EDI
    //                               LAB_00439f5b                                                 XREF[1]:     00439f57(j)  
    //                              Dib.cpp:1236 (71)
    //         00439f5b     CMP        dword ptr [ESP + 0x4c],ESI
    //         00439f5f     JNZ        LAB_00439f87
    //         00439f61     MOV        ECX,dword ptr [ESP + 0x46]
    //         00439f65     MOV        EDX,dword ptr [ESP + 0x3c]
    //         00439f69     AND        ECX,0xffff
    //         00439f6f     IMUL       EDX,ECX
    //         00439f72     ADD        EDX,0x1f
    //         00439f75     SHR        EDX,0x3
    //         00439f78     AND        EDX,0x1ffffffc
    //         00439f7e     IMUL       EDX,dword ptr [ESP + 0x40]
    //         00439f83     MOV        dword ptr [ESP + 0x4c],EDX
    //                               LAB_00439f87                                                 XREF[1]:     00439f5f(j)  
    //         00439f87     CMP        EDI,ESI
    //         00439f89     JNZ        LAB_00439fa2
    //         00439f8b     CMP        word ptr [ESP + 0x46],0x8
    //         00439f91     JA         LAB_00439fa2
    //         00439f93     MOV        CL,byte ptr [ESP + 0x46]
    //         00439f97     MOV        EDX,0x1
    //         00439f9c     SHL        EDX,CL
    //         00439f9e     MOV        dword ptr [ESP + 0x58],EDX
    //                               LAB_00439fa2                                                 XREF[2]:     00439f89(j), 00439f91(j)  
    //                              Dib.cpp:1239 (29)
    //         00439fa2     LEA        ECX,[EBP*0x4 + 0x0]
    //         00439fa9     ADD        EAX,ECX
    //         00439fab     MOV        dword ptr [ESP + 0x14],ECX
    //         00439faf     PUSH       EAX
    //         00439fb0     PUSH       0x2
    //         00439fb2     CALL       dword ptr [->KERNEL32.DLL::GlobalAlloc]          = 0048ab8e
    //         00439fb8     PUSH       EAX
    //         00439fb9     CALL       dword ptr [->KERNEL32.DLL::GlobalLock]           = 0048aade
    //                              Dib.cpp:1241 (8)
    //         00439fbf     CMP        EAX,ESI
    //         00439fc1     MOV        dword ptr [ESP + 0x10],EAX
    //         00439fc5     JNZ        LAB_00439fd1
    //                              Dib.cpp:1242 (2)
    //         00439fc7     XOR        EAX,EAX
    //                              Dib.cpp:1280 (8)
    //         00439fc9     POP        EDI
    //         00439fca     POP        ESI
    //         00439fcb     POP        EBP
    //         00439fcc     POP        EBX
    //         00439fcd     ADD        ESP,0x50
    //         00439fd0     RET
    //                               LAB_00439fd1                                                 XREF[1]:     00439fc5(j)  
    //                              Dib.cpp:1244 (13)
    //         00439fd1     MOV        ECX,0xa
    //         00439fd6     LEA        ESI,[ESP + 0x38]
    //         00439fda     MOV        EDI,EAX
    //         00439fdc     MOVSD.REP  ES:EDI,ESI
    //                              Dib.cpp:1246 (6)
    //         00439fde     MOV        EDX,dword ptr [EAX]
    //         00439fe0     MOV        ESI,EAX
    //         00439fe2     ADD        ESI,EDX
    //                              Dib.cpp:1248 (4)
    //         00439fe4     TEST       EBP,EBP
    //         00439fe6     JZ         LAB_0043a04c
    //                              Dib.cpp:1250 (7)
    //         00439fe8     CMP        dword ptr [ESP + 0x64],0xc
    //         00439fed     JNZ        LAB_0043a03b
    //                              Dib.cpp:1256 (13)
    //         00439fef     LEA        EAX,[EBP + EBP*0x2]
    //         00439ff3     PUSH       EAX
    //         00439ff4     PUSH       ESI=>DAT_fffffff8
    //         00439ff5     PUSH       EBX=>DAT_fffffff4
    //         00439ff6     CALL       dword ptr [->KERNEL32.DLL::_lread]               = 0048ab9c
    //                              Dib.cpp:1258 (7)
    //         00439ffc     LEA        EDX,[EBP + -0x1]
    //         00439fff     TEST       EDX,EDX
    //         0043a001     JL         LAB_0043a048
    //                              Dib.cpp:1280 (54)
    //         0043a003     LEA        EAX,[ESI + EDX*0x2]
    //         0043a006     LEA        ECX,[ESI + EDX*0x4]
    //         0043a009     MOV        byte ptr [ESP + 0x67],0x0
    //         0043a00e     LEA        ESI,[EDX + 0x1]
    //         0043a011     LEA        EAX,[EDX + EAX*0x1 + 0x1]
    //                               LAB_0043a015                                                 XREF[1]:     0043a037(j)  
    //         0043a015     MOV        DL,byte ptr [EAX + 0x1]
    //         0043a018     SUB        EAX,0x3
    //         0043a01b     MOV        byte ptr [ESP + 0x66],DL
    //         0043a01f     MOV        DL,byte ptr [EAX + 0x2]
    //         0043a022     MOV        byte ptr [ESP + 0x64],DL
    //         0043a026     MOV        DL,byte ptr [EAX + 0x3]
    //         0043a029     MOV        byte ptr [ESP + 0x65],DL
    //         0043a02d     MOV        EDX,dword ptr [ESP + 0x64]
    //         0043a031     MOV        dword ptr [ECX],EDX
    //         0043a033     SUB        ECX,0x4
    //         0043a036     DEC        ESI
    //         0043a037     JNZ        LAB_0043a015
    //                              Dib.cpp:1270 (2)
    //         0043a039     JMP        LAB_0043a048
    //                               LAB_0043a03b                                                 XREF[1]:     00439fed(j)  
    //                              Dib.cpp:1272 (13)
    //         0043a03b     MOV        EAX,dword ptr [ESP + 0x14]
    //         0043a03f     PUSH       EAX
    //         0043a040     PUSH       ESI=>DAT_fffffff8
    //         0043a041     PUSH       EBX=>DAT_fffffff4
    //         0043a042     CALL       dword ptr [->KERNEL32.DLL::_lread]               = 0048ab9c
    //                               LAB_0043a048                                                 XREF[2]:     0043a001(j), 0043a039(j)  
    //                              Dib.cpp:1270 (4)
    //         0043a048     MOV        EAX,dword ptr [ESP + 0x10]
    //                               LAB_0043a04c                                                 XREF[1]:     00439fe6(j)  
    //                              Dib.cpp:1276 (8)
    //         0043a04c     MOV        ECX,dword ptr [ESP + 0x32]
    //         0043a050     TEST       ECX,ECX
    //         0043a052     JZ         LAB_0043a068
    //                              Dib.cpp:1277 (20)
    //         0043a054     MOV        EDX,dword ptr [ESP + 0x18]
    //         0043a058     PUSH       0x0
    //         0043a05a     ADD        ECX,EDX
    //         0043a05c     PUSH       ECX=>DAT_fffffff8
    //         0043a05d     PUSH       EBX=>DAT_fffffff4
    //         0043a05e     CALL       dword ptr [->KERNEL32.DLL::_llseek]              = 0048aba6
    //         0043a064     MOV        EAX,dword ptr [ESP + 0x10]
    //                               LAB_0043a068                                                 XREF[1]:     0043a052(j)  
    //                              Dib.cpp:1280 (8)
    //         0043a068     POP        EDI
    //         0043a069     POP        ESI
    //         0043a06a     POP        EBP
    //         0043a06b     POP        EBX
    //         0043a06c     ADD        ESP,0x50
    //         0043a06f     RET
    //                              * struct tagBITMAPINFOHEADER * __cdecl DibFromBitmap(void *,unsigned long,unsigned int,void *,unsign... *
    //                              tagBITMAPINFOHEADER * __cdecl DibFromBitmap(void * param_1, ulong pa
    //              tagBITMAPINFOH    EAX:4          <RETURN>
    //              void *            Stack[0x4]:4   param_1                   XREF[1]:     0043a077(R)  
    //              ulong             Stack[0x8]:4   param_2
    //              uint              Stack[0xc]:4   param_3
    //              void *            Stack[0x10]:4  param_4                   XREF[1]:     0043a091(R)  
    //              uint              Stack[0x14]:4  param_5
    //              tagBITMAP         Stack[-0x1c]   bm                        XREF[1,1]:   0043a07b(W), 0043a0a9(*)  
    //              int               Stack[-0x20]:4 nColors
    //                               ?DibFromBitmap@@YAPAUtagBITMAPINFOHEADER@@PAXKI0I@Z
    //                               DibFromBitmap
    //                              Dib.cpp:1290 (7)
    //         0043a070     SUB        ESP,0x1c
    //         0043a073     PUSH       EBX
    //         0043a074     PUSH       EBP
    //         0043a075     PUSH       ESI
    //         0043a076     PUSH       EDI
    //                              Dib.cpp:1298 (16)
    //         0043a077     MOV        EDI,dword ptr [ESP + param_1]
    //         0043a07b     MOV        dword ptr [ESP + bm.bmType],0x0
    //         0043a083     TEST       EDI,EDI
    //         0043a085     JNZ        LAB_0043a091
    //                              Dib.cpp:1299 (2)
    //         0043a087     XOR        EAX,EAX
    //                              Dib.cpp:1416 (8)
    //         0043a089     POP        EDI
    //         0043a08a     POP        ESI
    //         0043a08b     POP        EBP
    //         0043a08c     POP        EBX
    //         0043a08d     ADD        ESP,0x1c
    //         0043a090     RET
    //                               LAB_0043a091                                                 XREF[1]:     0043a085(j)  
    //                              Dib.cpp:1301 (8)
    //         0043a091     MOV        EBP,dword ptr [ESP + param_4]
    //         0043a095     TEST       EBP,EBP
    //         0043a097     JNZ        LAB_0043a0a3
    //                              Dib.cpp:1302 (10)
    //         0043a099     PUSH       0xf
    //         0043a09b     CALL       dword ptr [->GDI32.DLL::GetStockObject]          = 0048b1b8
    //         0043a0a1     MOV        EBP,EAX
    //                               LAB_0043a0a3                                                 XREF[1]:     0043a097(j)  
    //                              Dib.cpp:1304 (16)
    //         0043a0a3     MOV        ESI,dword ptr [->GDI32.DLL::GetObjectA]          = 0048b262
    //         0043a0a9     LEA        EAX=>bm.bmWidth,[ESP + 0x14]
    //         0043a0ad     PUSH       EAX
    //         0043a0ae     PUSH       0x18
    //         0043a0b0     PUSH       EDI
    //         0043a0b1     CALL       ESI=>GDI32.DLL::GetObjectA
    //                              Dib.cpp:1305 (10)
    //         0043a0b3     LEA        ECX,[ESP + 0x10]
    //         0043a0b7     PUSH       ECX
    //         0043a0b8     PUSH       0x4
    //         0043a0ba     PUSH       EBP
    //         0043a0bb     CALL       ESI=>GDI32.DLL::GetObjectA
    //                              Dib.cpp:1307 (8)
    //         0043a0bd     MOV        EBX,dword ptr [ESP + 0x38]
    //         0043a0c1     TEST       EBX,EBX
    //         0043a0c3     JNZ        LAB_0043a0dc
    //                              Dib.cpp:1308 (23)
    //         0043a0c5     MOV        EBX,dword ptr [ESP + 0x24]
    //         0043a0c9     MOV        EDX,dword ptr [ESP + 0x26]
    //         0043a0cd     AND        EBX,0xffff
    //         0043a0d3     AND        EDX,0xffff
    //         0043a0d9     IMUL       EBX,EDX
    //                               LAB_0043a0dc                                                 XREF[1]:     0043a0c3(j)  
    //                              Dib.cpp:1310 (22)
    //         0043a0dc     PUSH       0x428
    //         0043a0e1     PUSH       0x2
    //         0043a0e3     CALL       dword ptr [->KERNEL32.DLL::GlobalAlloc]          = 0048ab8e
    //         0043a0e9     PUSH       EAX
    //         0043a0ea     CALL       dword ptr [->KERNEL32.DLL::GlobalLock]           = 0048aade
    //         0043a0f0     MOV        ESI,EAX
    //                              Dib.cpp:1312 (6)
    //         0043a0f2     XOR        EDX,EDX
    //         0043a0f4     CMP        ESI,EDX
    //         0043a0f6     JNZ        LAB_0043a102
    //                              Dib.cpp:1313 (2)
    //         0043a0f8     XOR        EAX,EAX
    //                              Dib.cpp:1416 (8)
    //         0043a0fa     POP        EDI
    //         0043a0fb     POP        ESI
    //         0043a0fc     POP        EBP
    //         0043a0fd     POP        EBX
    //         0043a0fe     ADD        ESP,0x1c
    //         0043a101     RET
    //                               LAB_0043a102                                                 XREF[1]:     0043a0f6(j)  
    //                              Dib.cpp:1315 (6)
    //         0043a102     MOV        dword ptr [ESI],0x28
    //                              Dib.cpp:1316 (7)
    //         0043a108     MOV        EAX,dword ptr [ESP + 0x18]
    //         0043a10c     MOV        dword ptr [ESI + 0x4],EAX
    //                              Dib.cpp:1317 (7)
    //         0043a10f     MOV        ECX,dword ptr [ESP + 0x1c]
    //         0043a113     MOV        dword ptr [ESI + 0x8],ECX
    //                              Dib.cpp:1320 (9)
    //         0043a116     MOV        ECX,dword ptr [ESP + 0x34]
    //         0043a11a     MOV        EAX,0x1
    //                              Dib.cpp:1326 (43)
    //         0043a11f     CMP        BX,0x8
    //         0043a123     MOV        word ptr [ESI + 0xc],AX
    //         0043a127     MOV        word ptr [ESI + 0xe],BX
    //         0043a12b     MOV        dword ptr [ESI + 0x10],ECX
    //         0043a12e     MOV        dword ptr [ESI + 0x14],EDX
    //         0043a131     MOV        dword ptr [ESI + 0x18],EDX
    //         0043a134     MOV        dword ptr [ESI + 0x1c],EDX
    //         0043a137     MOV        dword ptr [ESI + 0x20],EDX
    //         0043a13a     MOV        dword ptr [ESI + 0x24],EDX
    //         0043a13d     JA         LAB_0043a145
    //         0043a13f     MOV        CL,BL
    //         0043a141     SHL        EAX,CL
    //         0043a143     JMP        LAB_0043a147
    //                               LAB_0043a145                                                 XREF[1]:     0043a13d(j)  
    //         0043a145     XOR        EAX,EAX
    //                               LAB_0043a147                                                 XREF[1]:     0043a143(j)  
    //         0043a147     MOV        dword ptr [ESI + 0x20],EAX
    //                              Dib.cpp:1330 (9)
    //         0043a14a     MOV        EAX,dword ptr [ESP + 0x34]
    //         0043a14e     CMP        EAX,0x3
    //         0043a151     JNZ        LAB_0043a18e
    //                              Dib.cpp:1334 (15)
    //         0043a153     CMP        EBX,0x10
    //         0043a156     JZ         LAB_0043a179
    //         0043a158     CMP        EBX,0x18
    //         0043a15b     JZ         LAB_0043a162
    //         0043a15d     CMP        EBX,0x20
    //         0043a160     JNZ        LAB_0043a18e
    //                               LAB_0043a162                                                 XREF[1]:     0043a15b(j)  
    //                              Dib.cpp:1344 (7)
    //         0043a162     MOV        dword ptr [ESI + 0x28],0xff
    //                              Dib.cpp:1345 (7)
    //         0043a169     MOV        dword ptr [ESI + 0x2c],0xff00
    //                              Dib.cpp:1346 (7)
    //         0043a170     MOV        dword ptr [ESI + 0x30],0xff0000
    //                              Dib.cpp:1347 (2)
    //         0043a177     JMP        LAB_0043a18e
    //                               LAB_0043a179                                                 XREF[1]:     0043a156(j)  
    //                              Dib.cpp:1337 (7)
    //         0043a179     MOV        dword ptr [ESI + 0x28],0xf800
    //                              language.dll match for 0x7e0: "Age of Empires Expansion requi
    //                              Dib.cpp:1338 (7)
    //         0043a180     MOV        dword ptr [ESI + 0x2c],0x7e0
    //                              Dib.cpp:1339 (7)
    //         0043a187     MOV        dword ptr [ESI + 0x30],0x1f
    //                               LAB_0043a18e                                                 XREF[3]:     0043a151(j), 0043a160(j), 
    //                                                                                                         0043a177(j)  
    //                              Dib.cpp:1351 (9)
    //         0043a18e     PUSH       EDX
    //         0043a18f     CALL       dword ptr [->GDI32.DLL::CreateCompatibleDC]      = 0048b24c
    //         0043a195     MOV        EBX,EAX
    //                              Dib.cpp:1352 (10)
    //         0043a197     PUSH       0x0
    //         0043a199     PUSH       EBP
    //         0043a19a     PUSH       EBX
    //         0043a19b     CALL       dword ptr [->GDI32.DLL::SelectPalette]           = 0048b1dc
    //                              Dib.cpp:1353 (11)
    //         0043a1a1     PUSH       EBX
    //         0043a1a2     MOV        dword ptr [ESP + 0x40],EAX
    //         0043a1a6     CALL       dword ptr [->GDI32.DLL::RealizePalette]          = 0048b1ca
    //                              Dib.cpp:1356 (9)
    //         0043a1ac     PUSH       0x4
    //         0043a1ae     PUSH       EBX
    //         0043a1af     CALL       dword ptr [->GDI32.DLL::SetStretchBltMode]       = 0048b238
    //                              Dib.cpp:1364 (22)
    //         0043a1b5     MOV        EDX,dword ptr [ESP + 0x40]
    //         0043a1b9     MOV        EAX,dword ptr [ESI + 0x8]
    //         0043a1bc     PUSH       EDX
    //         0043a1bd     PUSH       ESI
    //         0043a1be     PUSH       0x0
    //         0043a1c0     PUSH       EAX
    //         0043a1c1     PUSH       0x0
    //         0043a1c3     PUSH       EDI
    //         0043a1c4     PUSH       EBX
    //         0043a1c5     CALL       dword ptr [->GDI32.DLL::GetDIBits]               = 0048b22c
    //                              Dib.cpp:1366 (27)
    //         0043a1cb     MOV        EAX,dword ptr [ESI + 0x20]
    //         0043a1ce     TEST       EAX,EAX
    //         0043a1d0     JNZ        LAB_0043a1e3
    //         0043a1d2     MOV        CX,word ptr [ESI + 0xe]
    //         0043a1d6     CMP        CX,0x8
    //         0043a1da     JA         LAB_0043a1e3
    //         0043a1dc     MOV        EAX,0x1
    //         0043a1e1     SHL        EAX,CL
    //                               LAB_0043a1e3                                                 XREF[2]:     0043a1d0(j), 0043a1da(j)  
    //         0043a1e3     MOV        dword ptr [ESI + 0x20],EAX
    //                              Dib.cpp:1367 (30)
    //         0043a1e6     MOV        EAX,dword ptr [ESI + 0x14]
    //         0043a1e9     TEST       EAX,EAX
    //         0043a1eb     JNZ        LAB_0043a204
    //         0043a1ed     MOV        AX,word ptr [ESI + 0xe]
    //         0043a1f1     IMUL       EAX,dword ptr [ESI + 0x4]
    //         0043a1f5     ADD        EAX,0x1f
    //         0043a1f8     SHR        EAX,0x3
    //         0043a1fb     AND        EAX,0x1ffffffc
    //         0043a200     IMUL       EAX,dword ptr [ESI + 0x8]
    //                               LAB_0043a204                                                 XREF[1]:     0043a1eb(j)  
    //                              Dib.cpp:1372 (7)
    //         0043a204     TEST       EAX,EAX
    //         0043a206     MOV        dword ptr [ESI + 0x14],EAX
    //         0043a209     JNZ        LAB_0043a235
    //                              Dib.cpp:1374 (4)
    //         0043a20b     MOV        AX,word ptr [ESI + 0xe]
    //                              Dib.cpp:1376 (30)
    //         0043a20f     MOV        ECX,dword ptr [ESP + 0x34]
    //         0043a213     IMUL       EAX,dword ptr [ESI + 0x4]
    //         0043a217     ADD        EAX,0x1f
    //         0043a21a     SHR        EAX,0x3
    //         0043a21d     AND        EAX,0x1ffffffc
    //         0043a222     IMUL       EAX,dword ptr [ESI + 0x8]
    //         0043a226     TEST       ECX,ECX
    //         0043a228     MOV        dword ptr [ESI + 0x14],EAX
    //         0043a22b     JZ         LAB_0043a235
    //                              Dib.cpp:1377 (8)
    //         0043a22d     LEA        ECX,[EAX + EAX*0x2]
    //         0043a230     SHR        ECX,0x1
    //         0043a232     MOV        dword ptr [ESI + 0x14],ECX
    //                               LAB_0043a235                                                 XREF[2]:     0043a209(j), 0043a22b(j)  
    //                              Dib.cpp:1383 (59)
    //         0043a235     MOV        EBP,dword ptr [->KERNEL32.DLL::GlobalHandle]     = 0048ab0c
    //         0043a23b     PUSH       ESI
    //         0043a23c     CALL       EBP=>KERNEL32.DLL::GlobalHandle
    //         0043a23e     PUSH       EAX
    //         0043a23f     CALL       dword ptr [->KERNEL32.DLL::GlobalUnlock]         = 0048aafc
    //         0043a245     MOV        EDX,dword ptr [ESI + 0x20]
    //         0043a248     MOV        EAX,dword ptr [ESI]
    //         0043a24a     PUSH       0x0
    //         0043a24c     LEA        ECX,[EAX + EDX*0x4]
    //         0043a24f     MOV        EDX,dword ptr [ESI + 0x14]
    //         0043a252     ADD        ECX,EDX
    //         0043a254     PUSH       ECX
    //         0043a255     PUSH       ESI
    //         0043a256     CALL       EBP=>KERNEL32.DLL::GlobalHandle
    //         0043a258     PUSH       EAX
    //         0043a259     CALL       dword ptr [->KERNEL32.DLL::GlobalReAlloc]        = 0048aaec
    //         0043a25f     PUSH       EAX
    //         0043a260     CALL       dword ptr [->KERNEL32.DLL::GlobalLock]           = 0048aade
    //         0043a266     MOV        EDI,EAX
    //         0043a268     TEST       EDI,EDI
    //         0043a26a     JZ         LAB_0043a2f1
    //                              Dib.cpp:1399 (49)
    //         0043a270     CMP        dword ptr [EDI + 0x10],0x3
    //         0043a274     JNZ        LAB_0043a27e
    //         0043a276     MOV        EDX,dword ptr [EDI]
    //         0043a278     LEA        EAX,[EDX + EDI*0x1 + 0xc]
    //         0043a27c     JMP        LAB_0043a288
    //                               LAB_0043a27e                                                 XREF[1]:     0043a274(j)  
    //         0043a27e     MOV        EAX,dword ptr [EDI + 0x20]
    //         0043a281     MOV        ECX,dword ptr [EDI]
    //         0043a283     LEA        EAX,[ECX + EAX*0x4]
    //         0043a286     ADD        EAX,EDI
    //                               LAB_0043a288                                                 XREF[1]:     0043a27c(j)  
    //         0043a288     MOV        EDX,dword ptr [ESP + 0x40]
    //         0043a28c     MOV        ECX,dword ptr [ESP + 0x30]
    //         0043a290     PUSH       EDX
    //         0043a291     PUSH       EDI
    //         0043a292     PUSH       EAX
    //         0043a293     MOV        EAX,dword ptr [EDI + 0x8]
    //         0043a296     PUSH       EAX
    //         0043a297     PUSH       0x0
    //         0043a299     PUSH       ECX
    //         0043a29a     PUSH       EBX
    //         0043a29b     CALL       dword ptr [->GDI32.DLL::GetDIBits]               = 0048b22c
    //                              Dib.cpp:1401 (24)
    //         0043a2a1     MOV        EDX,dword ptr [EDI + 0x20]
    //         0043a2a4     TEST       EDX,EDX
    //         0043a2a6     JNZ        LAB_0043a2b9
    //         0043a2a8     MOV        CX,word ptr [EDI + 0xe]
    //         0043a2ac     CMP        CX,0x8
    //         0043a2b0     JA         LAB_0043a2b9
    //         0043a2b2     MOV        EDX,0x1
    //         0043a2b7     SHL        EDX,CL
    //                               LAB_0043a2b9                                                 XREF[2]:     0043a2a6(j), 0043a2b0(j)  
    //                              Dib.cpp:1402 (38)
    //         0043a2b9     MOV        ECX,dword ptr [EDI + 0x14]
    //         0043a2bc     MOV        dword ptr [EDI + 0x20],EDX
    //         0043a2bf     TEST       ECX,ECX
    //         0043a2c1     JNZ        LAB_0043a2df
    //         0043a2c3     MOV        ECX,dword ptr [EDI + 0x4]
    //         0043a2c6     XOR        EDX,EDX
    //         0043a2c8     MOV        DX,word ptr [EDI + 0xe]
    //         0043a2cc     IMUL       ECX,EDX
    //         0043a2cf     ADD        ECX,0x1f
    //         0043a2d2     SHR        ECX,0x3
    //         0043a2d5     AND        ECX,0x1ffffffc
    //         0043a2db     IMUL       ECX,dword ptr [EDI + 0x8]
    //                               LAB_0043a2df                                                 XREF[1]:     0043a2c1(j)  
    //                              Dib.cpp:1406 (7)
    //         0043a2df     TEST       EAX,EAX
    //         0043a2e1     MOV        dword ptr [EDI + 0x14],ECX
    //         0043a2e4     JNZ        LAB_0043a307
    //                              Dib.cpp:1408 (11)
    //         0043a2e6     PUSH       EDI
    //         0043a2e7     CALL       DibFree                                          void DibFree(tagBITMAPINFOHEADER * param_1)
    //         0043a2ec     ADD        ESP,0x4
    //         0043a2ef     JMP        LAB_0043a305
    //                               LAB_0043a2f1                                                 XREF[1]:     0043a26a(j)  
    //                              Dib.cpp:1389 (20)
    //         0043a2f1     PUSH       ESI
    //         0043a2f2     CALL       EBP=>KERNEL32.DLL::GlobalHandle
    //         0043a2f4     PUSH       EAX
    //         0043a2f5     CALL       dword ptr [->KERNEL32.DLL::GlobalUnlock]         = 0048aafc
    //         0043a2fb     PUSH       ESI
    //         0043a2fc     CALL       EBP=>KERNEL32.DLL::GlobalHandle
    //         0043a2fe     PUSH       EAX
    //         0043a2ff     CALL       dword ptr [->KERNEL32.DLL::GlobalFree]           = 0048aad0
    //                               LAB_0043a305                                                 XREF[1]:     0043a2ef(j)  
    //                              Dib.cpp:1390 (2)
    //         0043a305     XOR        EDI,EDI
    //                              Symbol Ref: No symbol: exit
    //                               LAB_0043a307                                                 XREF[1]:     0043a2e4(j)  
    //                              Dib.cpp:1413 (14)
    //         0043a307     MOV        EAX,dword ptr [ESP + 0x3c]
    //         0043a30b     PUSH       0x0
    //         0043a30d     PUSH       EAX
    //         0043a30e     PUSH       EBX
    //         0043a30f     CALL       dword ptr [->GDI32.DLL::SelectPalette]           = 0048b1dc
    //                              Dib.cpp:1414 (7)
    //         0043a315     PUSH       EBX
    //         0043a316     CALL       dword ptr [->GDI32.DLL::DeleteDC]                = 0048b1ec
    //                              Dib.cpp:1415 (2)
    //         0043a31c     MOV        EAX,EDI
    //                              Dib.cpp:1416 (8)
    //         0043a31e     POP        EDI
    //         0043a31f     POP        ESI
    //         0043a320     POP        EBP
    //         0043a321     POP        EBX
    //         0043a322     ADD        ESP,0x1c
    //         0043a325     RET
    //         0043a326     ??         90h
    //         0043a327     NOP
    //         0043a328     NOP
    //         0043a329     NOP
    //         0043a32a     NOP
    //         0043a32b     NOP
    //         0043a32c     NOP
    //         0043a32d     NOP
    //         0043a32e     NOP
    //         0043a32f     NOP
    //                              * int __cdecl DibSetUsage(struct tagBITMAPINFOHEADER *,void *,unsigned int)                             *
    //                              int __cdecl DibSetUsage(tagBITMAPINFOHEADER * param_1, void * param_
    //              int               EAX:4          <RETURN>
    //              tagBITMAPINFOH    Stack[0x4]:4   param_1                   XREF[1]:     0043a34a(R)  
    //              void *            Stack[0x8]:4   param_2                   XREF[1]:     0043a330(R)  
    //              uint              Stack[0xc]:4   param_3
    //              tagPALETTEENTR    Stack[-0x404   ape
    //                               ?DibSetUsage@@YAHPAUtagBITMAPINFOHEADER@@PAXI@Z
    //                               DibSetUsage
    //                              Dib.cpp:1482 (18)
    //         0043a330     MOV        EAX,dword ptr [ESP + param_2]
    //         0043a334     SUB        ESP,0x400
    //         0043a33a     TEST       EAX,EAX
    //         0043a33c     PUSH       EBX
    //         0043a33d     PUSH       EBP
    //         0043a33e     PUSH       ESI
    //         0043a33f     PUSH       EDI
    //         0043a340     JNZ        LAB_0043a34a
    //                              Dib.cpp:1490 (8)
    //         0043a342     PUSH       0xf
    //         0043a344     CALL       dword ptr [->GDI32.DLL::GetStockObject]          = 0048b1b8
    //                               LAB_0043a34a                                                 XREF[1]:     0043a340(j)  
    //                              Dib.cpp:1492 (11)
    //         0043a34a     MOV        EDX,dword ptr [ESP + param_1]
    //         0043a351     TEST       EDX,EDX
    //         0043a353     JNZ        LAB_0043a362
    //                              Dib.cpp:1493 (2)
    //         0043a355     XOR        EAX,EAX
    //                              Dib.cpp:1538 (11)
    //         0043a357     POP        EDI
    //         0043a358     POP        ESI
    //         0043a359     POP        EBP
    //         0043a35a     POP        EBX
    //         0043a35b     ADD        ESP,0x400
    //         0043a361     RET
    //                               LAB_0043a362                                                 XREF[1]:     0043a353(j)  
    //                              Dib.cpp:1495 (24)
    //         0043a362     MOV        ESI,dword ptr [EDX + 0x20]
    //         0043a365     TEST       ESI,ESI
    //         0043a367     JNZ        LAB_0043a37a
    //         0043a369     MOV        CX,word ptr [EDX + 0xe]
    //         0043a36d     CMP        CX,0x8
    //         0043a371     JA         LAB_0043a37a
    //         0043a373     MOV        ESI,0x1
    //         0043a378     SHL        ESI,CL
    //                               LAB_0043a37a                                                 XREF[2]:     0043a367(j), 0043a371(j)  
    //                              Dib.cpp:1497 (10)
    //         0043a37a     CMP        ESI,0x3
    //         0043a37d     JNZ        LAB_0043a386
    //         0043a37f     CMP        dword ptr [EDX + 0x10],ESI
    //         0043a382     JNZ        LAB_0043a386
    //                              Dib.cpp:1498 (2)
    //         0043a384     XOR        ESI,ESI
    //                               LAB_0043a386                                                 XREF[2]:     0043a37d(j), 0043a382(j)  
    //                              Dib.cpp:1500 (8)
    //         0043a386     TEST       ESI,ESI
    //         0043a388     JLE        LAB_0043a410
    //                              Dib.cpp:1502 (2)
    //         0043a38e     MOV        EBX,dword ptr [EDX]
    //                              Dib.cpp:1504 (12)
    //         0043a390     MOV        ECX,dword ptr [ESP + 0x41c]
    //         0043a397     ADD        EBX,EDX
    //         0043a399     DEC        ECX
    //         0043a39a     JZ         LAB_0043a3fd
    //                              Dib.cpp:1523 (13)
    //         0043a39c     CMP        ESI,0x100
    //         0043a3a2     JL         LAB_0043a3a9
    //         0043a3a4     MOV        ESI,0x100
    //                               LAB_0043a3a9                                                 XREF[1]:     0043a3a2(j)  
    //                              Dib.cpp:1525 (15)
    //         0043a3a9     LEA        ECX,[ESP + 0x10]
    //         0043a3ad     PUSH       ECX
    //         0043a3ae     PUSH       ESI
    //         0043a3af     PUSH       0x0
    //         0043a3b1     PUSH       EAX
    //         0043a3b2     CALL       dword ptr [->GDI32.DLL::GetPaletteEntries]       = 0048b270
    //                              Dib.cpp:1527 (4)
    //         0043a3b8     TEST       ESI,ESI
    //         0043a3ba     JLE        LAB_0043a410
    //                              Dib.cpp:1532 (49)
    //         0043a3bc     LEA        EDI,[ESP + 0x10]
    //         0043a3c0     LEA        EBP,[ESP + 0x11]
    //         0043a3c4     SUB        EDI,EBX
    //         0043a3c6     LEA        ECX,[ESP + 0x10]
    //         0043a3ca     LEA        EAX,[EBX + 0x1]
    //         0043a3cd     SUB        EBP,EBX
    //                               LAB_0043a3cf                                                 XREF[1]:     0043a3eb(j)  
    //         0043a3cf     MOV        DL,byte ptr [ECX]
    //         0043a3d1     ADD        ECX,0x4
    //         0043a3d4     MOV        byte ptr [EAX + 0x1],DL
    //         0043a3d7     MOV        DL,byte ptr [EDI + EAX*0x1]
    //         0043a3da     MOV        byte ptr [EAX],DL
    //         0043a3dc     MOV        DL,byte ptr [EBP + EAX*0x1]
    //         0043a3e0     MOV        byte ptr [EAX + -0x1],DL
    //         0043a3e3     MOV        byte ptr [EAX + 0x2],0x0
    //         0043a3e7     ADD        EAX,0x4
    //         0043a3ea     DEC        ESI
    //         0043a3eb     JNZ        LAB_0043a3cf
    //                              Dib.cpp:1537 (5)
    //         0043a3ed     MOV        EAX,0x1
    //                              Dib.cpp:1538 (11)
    //         0043a3f2     POP        EDI
    //         0043a3f3     POP        ESI
    //         0043a3f4     POP        EBP
    //         0043a3f5     POP        EBX
    //         0043a3f6     ADD        ESP,0x400
    //         0043a3fc     RET
    //                               LAB_0043a3fd                                                 XREF[1]:     0043a39a(j)  
    //                              Dib.cpp:1514 (8)
    //         0043a3fd     XOR        EAX,EAX
    //         0043a3ff     MOV        ECX,EBX
    //         0043a401     TEST       ESI,ESI
    //         0043a403     JLE        LAB_0043a410
    //                               LAB_0043a405                                                 XREF[1]:     0043a40e(j)  
    //                              Dib.cpp:1515 (11)
    //         0043a405     MOV        word ptr [ECX],AX
    //         0043a408     INC        EAX
    //         0043a409     ADD        ECX,0x2
    //         0043a40c     CMP        EAX,ESI
    //         0043a40e     JL         LAB_0043a405
    //                               LAB_0043a410                                                 XREF[3]:     0043a388(j), 0043a3ba(j), 
    //                                                                                                         0043a403(j)  
    //                              Dib.cpp:1538 (16)
    //         0043a410     POP        EDI
    //         0043a411     POP        ESI
    //         0043a412     POP        EBP
    //         0043a413     MOV        EAX,0x1
    //         0043a418     POP        EBX
    //         0043a419     ADD        ESP,0x400
    //         0043a41f     RET
    //                              * int __cdecl DibDraw(void *,int,int,int,int,struct tagBITMAPINFOHEADER *,int,int,int,int,long,unsig... *
    //                              int __cdecl DibDraw(void * param_1, int param_2, int param_3, int pa
    //              int               EAX:4          <RETURN>
    //              void *            Stack[0x4]:4   param_1                   XREF[1]:     0043a494(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     0043a48f(R)  
    //              int               Stack[0xc]:4   param_3                   XREF[1]:     0043a484(R)  
    //              int               Stack[0x10]:4  param_4                   XREF[1]:     0043a445(R)  
    //              int               Stack[0x14]:4  param_5                   XREF[1]:     0043a449(R)  
    //              tagBITMAPINFOH    Stack[0x18]:4  param_6                   XREF[1]:     0043a420(R)  
    //              int               Stack[0x1c]:4  param_7                   XREF[1]:     0043a47f(R)  
    //              int               Stack[0x20]:4  param_8                   XREF[1]:     0043a489(R)  
    //              int               Stack[0x24]:4  param_9                   XREF[1]:     0043a42e(R)  
    //              int               Stack[0x28]:4  param_10                  XREF[1]:     0043a429(R)  
    //              long              Stack[0x2c]:4  param_11                  XREF[1]:     0043a474(R)  
    //              uint              Stack[0x30]:4  param_12                  XREF[1]:     0043a479(R)  
    //                               ?DibDraw@@YAHPAXHHHHPAUtagBITMAPINFOHEADER@@HHHHJI@Z
    //                               DibDraw
    //                              Dib.cpp:1546 (8)
    //         0043a420     MOV        EAX,dword ptr [ESP + param_6]
    //         0043a424     TEST       EAX,EAX
    //         0043a426     JNZ        LAB_0043a429
    //                              Dib.cpp:1589 (1)
    //         0043a428     RET
    //                               LAB_0043a429                                                 XREF[1]:     0043a426(j)  
    //                              Dib.cpp:1553 (22)
    //         0043a429     MOV        EDX,dword ptr [ESP + param_10]
    //         0043a42d     PUSH       EDI
    //         0043a42e     MOV        EDI,dword ptr [ESP + param_9]
    //         0043a432     PUSH       ESI
    //         0043a433     PUSH       EBP
    //         0043a434     CMP        EDI,-0x1
    //         0043a437     PUSH       EBX
    //         0043a438     JNZ        LAB_0043a445
    //         0043a43a     CMP        EDX,-0x1
    //         0043a43d     JNZ        LAB_0043a445
    //                              Dib.cpp:1555 (3)
    //         0043a43f     MOV        EDI,dword ptr [EAX + 0x4]
    //                              Dib.cpp:1556 (3)
    //         0043a442     MOV        EDX,dword ptr [EAX + 0x8]
    //                               LAB_0043a445                                                 XREF[2]:     0043a438(j), 0043a43d(j)  
    //                              Dib.cpp:1559 (18)
    //         0043a445     MOV        EBX,dword ptr [ESP + param_4]
    //         0043a449     MOV        ESI,dword ptr [ESP + param_5]
    //         0043a44d     CMP        EBX,-0x1
    //         0043a450     JNZ        LAB_0043a45b
    //         0043a452     CMP        ESI,-0x1
    //         0043a455     JNZ        LAB_0043a45b
    //                              Dib.cpp:1561 (2)
    //         0043a457     MOV        EBX,EDI
    //                              Dib.cpp:1562 (2)
    //         0043a459     MOV        ESI,EDX
    //                               LAB_0043a45b                                                 XREF[2]:     0043a450(j), 0043a455(j)  
    //                              Dib.cpp:1576 (25)
    //         0043a45b     CMP        dword ptr [EAX + 0x10],0x3
    //         0043a45f     JNZ        LAB_0043a469
    //         0043a461     MOV        ECX,dword ptr [EAX]
    //         0043a463     LEA        ECX,[ECX + EAX*0x1 + 0xc]
    //         0043a467     JMP        LAB_0043a474
    //                               LAB_0043a469                                                 XREF[1]:     0043a45f(j)  
    //         0043a469     MOV        ECX,dword ptr [EAX + 0x20]
    //         0043a46c     MOV        EBP,dword ptr [EAX]
    //         0043a46e     LEA        ECX,[EBP + ECX*0x4]
    //         0043a472     ADD        ECX,EAX
    //                               LAB_0043a474                                                 XREF[1]:     0043a467(j)  
    //                              Dib.cpp:1586 (51)
    //         0043a474     MOV        EBP,dword ptr [ESP + param_11]
    //         0043a478     PUSH       EBP
    //         0043a479     MOV        EBP,dword ptr [ESP + param_12]
    //         0043a47d     PUSH       EBP
    //         0043a47e     PUSH       EAX
    //         0043a47f     MOV        EAX,dword ptr [ESP + param_7]
    //         0043a483     PUSH       ECX
    //         0043a484     MOV        ECX,dword ptr [ESP + param_3]
    //         0043a488     PUSH       EDX
    //         0043a489     MOV        EDX,dword ptr [ESP + param_8]
    //         0043a48d     PUSH       EDI
    //         0043a48e     PUSH       EDX
    //         0043a48f     MOV        EDX,dword ptr [ESP + param_2]
    //         0043a493     PUSH       EAX
    //         0043a494     MOV        EAX,dword ptr [ESP + param_1]
    //         0043a498     PUSH       ESI
    //         0043a499     PUSH       EBX
    //         0043a49a     PUSH       ECX
    //         0043a49b     PUSH       EDX
    //         0043a49c     PUSH       EAX
    //         0043a49d     CALL       dword ptr [->GDI32.DLL::StretchDIBits]           = 0048b284
    //         0043a4a3     POP        EBX
    //         0043a4a4     POP        EBP
    //         0043a4a5     POP        ESI
    //         0043a4a6     POP        EDI
    //                              Dib.cpp:1589 (1)
    //         0043a4a7     RET
    //         0043a4a8     ??         90h
    //         0043a4a9     NOP
    //         0043a4aa     NOP
    //         0043a4ab     NOP
    //         0043a4ac     NOP
    //         0043a4ad     NOP
    //         0043a4ae     NOP
    //         0043a4af     NOP
    //                              * struct tagBITMAPINFOHEADER * __cdecl DibCopy(struct tagBITMAPINFOHEADER *)                            *
    //                              tagBITMAPINFOHEADER * __cdecl DibCopy(tagBITMAPINFOHEADER * param_1)
    //              tagBITMAPINFOH    EAX:4          <RETURN>
    //              tagBITMAPINFOH    Stack[0x4]:4   param_1                   XREF[1]:     0043a4b1(R)  
    //                               ?DibCopy@@YAPAUtagBITMAPINFOHEADER@@PAU1@@Z
    //                               DibCopy
    //                              Dib.cpp:1592 (1)
    //         0043a4b0     PUSH       ESI
    //                              Dib.cpp:1595 (8)
    //         0043a4b1     MOV        ESI,dword ptr [ESP + param_1]
    //         0043a4b5     TEST       ESI,ESI
    //         0043a4b7     JNZ        LAB_0043a4bd
    //                              Dib.cpp:1596 (2)
    //         0043a4b9     XOR        EAX,EAX
    //                              Dib.cpp:1602 (2)
    //         0043a4bb     POP        ESI
    //         0043a4bc     RET
    //                               LAB_0043a4bd                                                 XREF[1]:     0043a4b7(j)  
    //                              Dib.cpp:1598 (36)
    //         0043a4bd     MOV        EAX,dword ptr [ESI + 0x20]
    //         0043a4c0     MOV        ECX,dword ptr [ESI]
    //         0043a4c2     PUSH       EDI
    //         0043a4c3     LEA        EDX,[ECX + EAX*0x4]
    //         0043a4c6     MOV        EAX,dword ptr [ESI + 0x14]
    //         0043a4c9     ADD        EDX,EAX
    //         0043a4cb     PUSH       EDX
    //         0043a4cc     PUSH       0x2
    //         0043a4ce     CALL       dword ptr [->KERNEL32.DLL::GlobalAlloc]          = 0048ab8e
    //         0043a4d4     PUSH       EAX
    //         0043a4d5     CALL       dword ptr [->KERNEL32.DLL::GlobalLock]           = 0048aade
    //         0043a4db     MOV        EDI,EAX
    //         0043a4dd     TEST       EDI,EDI
    //         0043a4df     JZ         LAB_0043a4f9
    //                              Dib.cpp:1599 (24)
    //         0043a4e1     MOV        EAX,dword ptr [ESI + 0x20]
    //         0043a4e4     MOV        ECX,dword ptr [ESI]
    //         0043a4e6     LEA        EDX,[ECX + EAX*0x4]
    //         0043a4e9     MOV        ECX,dword ptr [ESI + 0x14]
    //         0043a4ec     ADD        EDX,ECX
    //         0043a4ee     PUSH       EDX
    //         0043a4ef     PUSH       ESI=>DAT_fffffff8
    //         0043a4f0     PUSH       EDI=>DAT_fffffff4
    //         0043a4f1     CALL       memcpy                                           undefined memcpy()
    //         0043a4f6     ADD        ESP,0xc
    //                               LAB_0043a4f9                                                 XREF[1]:     0043a4df(j)  
    //                              Dib.cpp:1601 (3)
    //         0043a4f9     MOV        EAX,EDI
    //         0043a4fb     POP        EDI
    //                              Dib.cpp:1602 (2)
    //         0043a4fc     POP        ESI
    //         0043a4fd     RET
    //         0043a4fe     ??         90h
    //         0043a4ff     NOP
    //                              * struct tagBITMAPINFOHEADER * __cdecl DibCreate(int,int,int)                                           *
    //                              tagBITMAPINFOHEADER * __cdecl DibCreate(int param_1, int param_2, in
    //              tagBITMAPINFOH    EAX:4          <RETURN>
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0043a501(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     0043a506(R)  
    //              int               Stack[0xc]:4   param_3                   XREF[1]:     0043a522(R)  
    //                               ?DibCreate@@YAPAUtagBITMAPINFOHEADER@@HHH@Z                  XREF[1]:     DibWriteClipped:00439bef(c)  
    //                               DibCreate
    //                              Dib.cpp:1605 (1)
    //         0043a500     PUSH       EBX
    //                              Dib.cpp:1611 (38)
    //         0043a501     MOV        EBX,dword ptr [ESP + param_1]
    //         0043a505     PUSH       EBP
    //         0043a506     MOV        EBP,dword ptr [ESP + param_2]
    //         0043a50a     MOV        EAX,EBP
    //         0043a50c     PUSH       ESI
    //         0043a50d     IMUL       EAX,EBX
    //         0043a510     CDQ
    //         0043a511     AND        EDX,0x7
    //         0043a514     PUSH       EDI
    //         0043a515     ADD        EAX,EDX
    //         0043a517     MOV        EDI,EAX
    //         0043a519     SAR        EDI,0x3
    //         0043a51c     ADD        EDI,0x3
    //         0043a51f     AND        EDI,0xfffffffc
    //         0043a522     IMUL       EDI,dword ptr [ESP + param_3]
    //                              Dib.cpp:1613 (24)
    //         0043a527     LEA        EAX,[EDI + 0x428]
    //         0043a52d     PUSH       EAX
    //         0043a52e     PUSH       0x42
    //         0043a530     CALL       dword ptr [->KERNEL32.DLL::GlobalAlloc]          = 0048ab8e
    //         0043a536     PUSH       EAX
    //         0043a537     CALL       dword ptr [->KERNEL32.DLL::GlobalLock]           = 0048aade
    //         0043a53d     MOV        ESI,EAX
    //                              Dib.cpp:1615 (6)
    //         0043a53f     XOR        EAX,EAX
    //         0043a541     CMP        ESI,EAX
    //         0043a543     JNZ        LAB_0043a54a
    //                              Dib.cpp:1659 (5)
    //         0043a545     POP        EDI
    //         0043a546     POP        ESI
    //         0043a547     POP        EBP
    //         0043a548     POP        EBX
    //         0043a549     RET
    //                               LAB_0043a54a                                                 XREF[1]:     0043a543(j)  
    //                              Dib.cpp:1620 (4)
    //         0043a54a     MOV        ECX,dword ptr [ESP + 0x1c]
    //                              Dib.cpp:1630 (45)
    //         0043a54e     CMP        EBX,0x4
    //         0043a551     MOV        dword ptr [ESI],0x28
    //         0043a557     MOV        dword ptr [ESI + 0x4],EBP
    //         0043a55a     MOV        dword ptr [ESI + 0x8],ECX
    //         0043a55d     MOV        word ptr [ESI + 0xc],0x1
    //         0043a563     MOV        word ptr [ESI + 0xe],BX
    //         0043a567     MOV        dword ptr [ESI + 0x10],EAX
    //         0043a56a     MOV        dword ptr [ESI + 0x14],EDI
    //         0043a56d     MOV        dword ptr [ESI + 0x18],EAX
    //         0043a570     MOV        dword ptr [ESI + 0x1c],EAX
    //         0043a573     MOV        dword ptr [ESI + 0x20],EAX
    //         0043a576     MOV        dword ptr [ESI + 0x24],EAX
    //         0043a579     JNZ        LAB_0043a584
    //                              Dib.cpp:1631 (7)
    //         0043a57b     MOV        dword ptr [ESI + 0x20],0x10
    //                              Dib.cpp:1633 (7)
    //         0043a582     JMP        LAB_0043a590
    //                               LAB_0043a584                                                 XREF[1]:     0043a579(j)  
    //         0043a584     CMP        EBX,0x8
    //         0043a587     JNZ        LAB_0043a590
    //                              Dib.cpp:1634 (7)
    //         0043a589     MOV        dword ptr [ESI + 0x20],0x100
    //                               LAB_0043a590                                                 XREF[2]:     0043a582(j), 0043a587(j)  
    //                              Dib.cpp:1638 (25)
    //         0043a590     MOV        EAX,dword ptr [ESI + 0x20]
    //         0043a593     XOR        EDI,EDI
    //         0043a595     CDQ
    //         0043a596     AND        EDX,0xf
    //         0043a599     LEA        ECX,[ESI + 0x28]
    //         0043a59c     ADD        EAX,EDX
    //         0043a59e     SAR        EAX,0x4
    //         0043a5a1     TEST       EAX,EAX
    //         0043a5a3     JLE        LAB_0043a64e
    //                               LAB_0043a5a9                                                 XREF[1]:     0043a648(j)  
    //                              Dib.cpp:1640 (9)
    //         0043a5a9     MOV        dword ptr [ECX],0x0
    //         0043a5af     ADD        ECX,0x4
    //                              Dib.cpp:1641 (9)
    //         0043a5b2     MOV        dword ptr [ECX],pathSystem.MGP_openPaths[50869
    //         0043a5b8     ADD        ECX,0x4
    //                              Dib.cpp:1642 (9)
    //         0043a5bb     MOV        dword ptr [ECX],0x8000
    //         0043a5c1     ADD        ECX,0x4
    //                              Dib.cpp:1643 (9)
    //         0043a5c4     MOV        dword ptr [ECX],pathSystem.MGP_openPaths[54965
    //         0043a5ca     ADD        ECX,0x4
    //                              Dib.cpp:1644 (9)
    //         0043a5cd     MOV        dword ptr [ECX],0x80
    //         0043a5d3     ADD        ECX,0x4
    //                              Dib.cpp:1645 (9)
    //         0043a5d6     MOV        dword ptr [ECX],pathSystem.MGP_openPaths[50885
    //         0043a5dc     ADD        ECX,0x4
    //                              Dib.cpp:1646 (9)
    //         0043a5df     MOV        dword ptr [ECX],0x8080
    //         0043a5e5     ADD        ECX,0x4
    //                              Dib.cpp:1647 (9)
    //         0043a5e8     MOV        dword ptr [ECX],0xc0c0c0
    //         0043a5ee     ADD        ECX,0x4
    //                              Dib.cpp:1648 (9)
    //         0043a5f1     MOV        dword ptr [ECX],pathSystem.MGP_openPaths[54981
    //         0043a5f7     ADD        ECX,0x4
    //                              Dib.cpp:1649 (9)
    //         0043a5fa     MOV        dword ptr [ECX],0xff0000
    //         0043a600     ADD        ECX,0x4
    //                              Dib.cpp:1650 (9)
    //         0043a603     MOV        dword ptr [ECX],0xff00
    //         0043a609     ADD        ECX,0x4
    //                              Dib.cpp:1651 (9)
    //         0043a60c     MOV        dword ptr [ECX],0xffff00
    //         0043a612     ADD        ECX,0x4
    //                              Dib.cpp:1652 (9)
    //         0043a615     MOV        dword ptr [ECX],0xff
    //         0043a61b     ADD        ECX,0x4
    //                              Dib.cpp:1653 (9)
    //         0043a61e     MOV        dword ptr [ECX],0xff00ff
    //         0043a624     ADD        ECX,0x4
    //                              Dib.cpp:1654 (9)
    //         0043a627     MOV        dword ptr [ECX],0xffff
    //         0043a62d     ADD        ECX,0x4
    //                              Dib.cpp:1655 (30)
    //         0043a630     MOV        dword ptr [ECX],0xffffff
    //         0043a636     MOV        EAX,dword ptr [ESI + 0x20]
    //         0043a639     CDQ
    //         0043a63a     AND        EDX,0xf
    //         0043a63d     ADD        ECX,0x4
    //         0043a640     ADD        EAX,EDX
    //         0043a642     INC        EDI
    //         0043a643     SAR        EAX,0x4
    //         0043a646     CMP        EDI,EAX
    //         0043a648     JL         LAB_0043a5a9
    //                               LAB_0043a64e                                                 XREF[1]:     0043a5a3(j)  
    //                              Dib.cpp:1658 (2)
    //         0043a64e     MOV        EAX,ESI
    //                              Dib.cpp:1659 (5)
    //         0043a650     POP        EDI
    //         0043a651     POP        ESI
    //         0043a652     POP        EBP
    //         0043a653     POP        EBX
    //         0043a654     RET
    //         0043a655     ??         90h
    //         0043a656     NOP
    //         0043a657     NOP
    //         0043a658     NOP
    //         0043a659     NOP
    //         0043a65a     NOP
    //         0043a65b     NOP
    //         0043a65c     NOP
    //         0043a65d     NOP
    //         0043a65e     NOP
    //         0043a65f     NOP
    //                              * void __cdecl DibMapToPalette(struct tagBITMAPINFOHEADER *,void *,int,int)                             *
    //                              void __cdecl DibMapToPalette(tagBITMAPINFOHEADER * param_1, void * p
    //              void              <VOID>         <RETURN>
    //              tagBITMAPINFOH    Stack[0x4]:4   param_1                   XREF[1]:     0043a68b(R)  
    //              void *            Stack[0x8]:4   param_2                   XREF[1]:     0043a667(R)  
    //              int               Stack[0xc]:4   param_3
    //              int               Stack[0x10]:4  param_4
    //              uchar[256]        Stack[-0x104   xlat
    //              int               Stack[-0x108   HitEnd                    XREF[1]:     0043a680(W)  
    //              uchar             Stack[-0x10c   TransIndex
    //              int               Stack[-0x110   ZeroBlue
    //              tagPALETTEENTRY   Stack[-0x114   pe                        XREF[1]:     0043a6a7(W)  
    //              tagRGBQUAD *      Stack[-0x118   lpRgb
    //              int               Stack[-0x11c   nDibColors                XREF[2]:     0043a673(W), 0043a69d(*)  
    //              int               Stack[-0x120   nPalColors
    //              ulong             Stack[-0x124   SizeImage
    //              uchar *           Stack[-0x128   lpBits                    XREF[0,1]:   0043a67b(W)  
    //              uchar             Stack[-0x129   ZeroIndex
    //                               ?DibMapToPalette@@YAXPAUtagBITMAPINFOHEADER@@PAXHH@Z         XREF[1]:     Load:0046e1c7(c)  
    //                               DibMapToPalette
    //                              Dib.cpp:1782 (7)
    //         0043a660     SUB        ESP,0x128
    //         0043a666     PUSH       EBX
    //                              Dib.cpp:1797 (51)
    //         0043a667     MOV        EBX,dword ptr [ESP + param_2]
    //         0043a66e     PUSH       EBP
    //         0043a66f     PUSH       ESI
    //         0043a670     TEST       EBX,EBX
    //         0043a672     PUSH       EDI
    //         0043a673     MOV        dword ptr [ESP + nDibColors],0x0
    //         0043a67b     MOV        byte ptr [ESP + lpBits+0x3],0x0
    //         0043a680     MOV        byte ptr [ESP + HitEnd],0x0
    //         0043a685     JZ         LAB_0043aa4e
    //         0043a68b     MOV        EBP,dword ptr [ESP + param_1]
    //         0043a692     TEST       EBP,EBP
    //         0043a694     JZ         LAB_0043aa4e
    //                              Dib.cpp:1801 (3)
    //         0043a69a     MOV        EDI,dword ptr [EBP]
    //                              Dib.cpp:1803 (20)
    //         0043a69d     LEA        EAX=>nDibColors,[ESP + 0x1c]
    //         0043a6a1     PUSH       EAX
    //         0043a6a2     ADD        EDI,EBP
    //         0043a6a4     PUSH       0x4
    //         0043a6a6     PUSH       EBX
    //         0043a6a7     MOV        dword ptr [ESP + pe.peRed],EDI
    //         0043a6ab     CALL       dword ptr [->GDI32.DLL::GetObjectA]              = 0048b262
    //                              Dib.cpp:1804 (36)
    //         0043a6b1     MOV        EDX,dword ptr [EBP + 0x20]
    //         0043a6b4     TEST       EDX,EDX
    //         0043a6b6     JNZ        LAB_0043a6cf
    //         0043a6b8     MOV        CX,word ptr [EBP + 0xe]
    //         0043a6bc     CMP        CX,0x8
    //         0043a6c0     JA         LAB_0043a6cf
    //         0043a6c2     MOV        ESI,0x1
    //         0043a6c7     SHL        ESI,CL
    //         0043a6c9     MOV        dword ptr [ESP + 0x20],ESI
    //         0043a6cd     JMP        LAB_0043a6d5
    //                               LAB_0043a6cf                                                 XREF[2]:     0043a6b6(j), 0043a6c0(j)  
    //         0043a6cf     MOV        dword ptr [ESP + 0x20],EDX
    //         0043a6d3     MOV        ESI,EDX
    //                               LAB_0043a6d5                                                 XREF[1]:     0043a6cd(j)  
    //                              Dib.cpp:1806 (11)
    //         0043a6d5     MOV        EAX,dword ptr [EBP + 0x14]
    //         0043a6d8     TEST       EAX,EAX
    //         0043a6da     MOV        dword ptr [ESP + 0x18],EAX
    //         0043a6de     JNZ        LAB_0043a6ff
    //                              Dib.cpp:1807 (31)
    //         0043a6e0     MOV        EAX,dword ptr [EBP + 0x4]
    //         0043a6e3     XOR        ECX,ECX
    //         0043a6e5     MOV        CX,word ptr [EBP + 0xe]
    //         0043a6e9     IMUL       EAX,ECX
    //         0043a6ec     ADD        EAX,0x1f
    //         0043a6ef     SHR        EAX,0x3
    //         0043a6f2     AND        EAX,0x1ffffffc
    //         0043a6f7     IMUL       EAX,dword ptr [EBP + 0x8]
    //         0043a6fb     MOV        dword ptr [ESP + 0x18],EAX
    //                               LAB_0043a6ff                                                 XREF[1]:     0043a6de(j)  
    //                              Dib.cpp:1809 (31)
    //         0043a6ff     CMP        dword ptr [EBP + 0x10],0x3
    //         0043a703     JNZ        LAB_0043a712
    //         0043a705     MOV        EDX,dword ptr [EBP]
    //         0043a708     LEA        EAX,[EDX + EBP*0x1 + 0xc]
    //         0043a70c     MOV        dword ptr [ESP + 0x14],EAX
    //         0043a710     JMP        LAB_0043a71e
    //                               LAB_0043a712                                                 XREF[1]:     0043a703(j)  
    //         0043a712     MOV        ECX,dword ptr [EBP]
    //         0043a715     LEA        EDX,[ECX + EDX*0x4]
    //         0043a718     ADD        EDX,EBP
    //         0043a71a     MOV        dword ptr [ESP + 0x14],EDX
    //                               LAB_0043a71e                                                 XREF[1]:     0043a710(j)  
    //                              Dib.cpp:1815 (15)
    //         0043a71e     MOV        EAX,dword ptr [ESP + 0x144]
    //         0043a725     TEST       EAX,EAX
    //         0043a727     JZ         LAB_0043a817
    //                              Dib.cpp:1818 (11)
    //         0043a72d     MOV        EAX,dword ptr [ESP + 0x148]
    //         0043a734     TEST       EAX,EAX
    //         0043a736     JZ         LAB_0043a73f
    //                              Dib.cpp:1819 (5)
    //         0043a738     MOV        byte ptr [ESP + 0x30],0x0
    //                              Dib.cpp:1820 (2)
    //         0043a73d     JMP        LAB_0043a75a
    //                               LAB_0043a73f                                                 XREF[1]:     0043a736(j)  
    //                              Dib.cpp:1821 (27)
    //         0043a73f     MOV        EDX,dword ptr [EBP + 0x4]
    //         0043a742     MOV        EAX,dword ptr [EBP + 0x8]
    //         0043a745     ADD        EDX,0x3
    //         0043a748     MOV        ECX,dword ptr [ESP + 0x14]
    //         0043a74c     AND        EDX,0xfffffffc
    //         0043a74f     DEC        EAX
    //         0043a750     IMUL       EDX,EAX
    //         0043a753     MOV        DL,byte ptr [EDX + ECX*0x1]
    //         0043a756     MOV        byte ptr [ESP + 0x30],DL
    //                               LAB_0043a75a                                                 XREF[1]:     0043a73d(j)  
    //                              Dib.cpp:1825 (16)
    //         0043a75a     MOV        ECX,dword ptr [ESP + 0x24]
    //         0043a75e     XOR        EAX,EAX
    //         0043a760     MOV        AL,byte ptr [EDI + 0x2]
    //         0043a763     XOR        EBX,EBX
    //         0043a765     MOV        BL,byte ptr [ECX + 0x1]
    //         0043a768     MOV        ESI,EAX
    //                              Dib.cpp:1826 (9)
    //         0043a76a     XOR        EAX,EAX
    //         0043a76c     MOV        byte ptr [ESP + 0x13],0x0
    //         0043a771     MOV        AL,byte ptr [ECX]
    //                              Dib.cpp:1827 (8)
    //         0043a773     MOV        dword ptr [ESP + 0x34],0x0
    //                              Dib.cpp:1828 (15)
    //         0043a77b     MOV        EDI,0x1
    //         0043a780     JMP        LAB_0043a78a
    //                               LAB_0043a782                                                 XREF[1]:     0043a806(j)  
    //         0043a782     MOV        EAX,dword ptr [ESP + 0x2c]
    //         0043a786     MOV        ECX,dword ptr [ESP + 0x24]
    //                               LAB_0043a78a                                                 XREF[1]:     0043a780(j)  
    //                              Dib.cpp:1831 (2)
    //         0043a78a     ADD        ESI,EDI
    //                              Dib.cpp:1832 (2)
    //         0043a78c     ADD        EBX,EDI
    //                              Dib.cpp:1833 (2)
    //         0043a78e     ADD        EAX,EDI
    //                              Dib.cpp:1835 (39)
    //         0043a790     CMP        ESI,0xff
    //         0043a796     MOV        dword ptr [ESP + 0x2c],EAX
    //         0043a79a     JG         LAB_0043a7b7
    //         0043a79c     CMP        EBX,0xff
    //         0043a7a2     JG         LAB_0043a7b7
    //         0043a7a4     CMP        EAX,0xff
    //         0043a7a9     JG         LAB_0043a7b7
    //         0043a7ab     TEST       ESI,ESI
    //         0043a7ad     JL         LAB_0043a7b7
    //         0043a7af     TEST       EBX,EBX
    //         0043a7b1     JL         LAB_0043a7b7
    //         0043a7b3     TEST       EAX,EAX
    //         0043a7b5     JGE        LAB_0043a7de
    //                               LAB_0043a7b7                                                 XREF[5]:     0043a79a(j), 0043a7a2(j), 
    //                                                                                                         0043a7a9(j), 0043a7ad(j), 
    //                                                                                                         0043a7b1(j)  
    //                              Dib.cpp:1837 (8)
    //         0043a7b7     MOV        EAX,dword ptr [ESP + 0x34]
    //         0043a7bb     TEST       EAX,EAX
    //         0043a7bd     JNZ        LAB_0043a80c
    //                              Dib.cpp:1840 (3)
    //         0043a7bf     OR         EDI,0xffffffff
    //                              Dib.cpp:1841 (5)
    //         0043a7c2     XOR        EDX,EDX
    //         0043a7c4     MOV        DL,byte ptr [ECX + 0x2]
    //                              Dib.cpp:1842 (5)
    //         0043a7c7     XOR        EBX,EBX
    //         0043a7c9     MOV        BL,byte ptr [ECX + 0x1]
    //                              Dib.cpp:1843 (18)
    //         0043a7cc     XOR        EAX,EAX
    //         0043a7ce     MOV        AL,byte ptr [ECX]
    //         0043a7d0     MOV        dword ptr [ESP + 0x34],0x1
    //         0043a7d8     MOV        ESI,EDX
    //         0043a7da     MOV        dword ptr [ESP + 0x2c],EAX
    //                               LAB_0043a7de                                                 XREF[1]:     0043a7b5(j)  
    //                              Dib.cpp:1845 (46)
    //         0043a7de     XOR        ECX,ECX
    //         0043a7e0     MOV        EDX,ESI
    //         0043a7e2     MOV        CH,AL
    //         0043a7e4     MOV        EAX,dword ptr [ESP + 0x140]
    //         0043a7eb     MOV        CL,BL
    //         0043a7ed     AND        EDX,0xff
    //         0043a7f3     SHL        ECX,0x8
    //         0043a7f6     OR         ECX,EDX
    //         0043a7f8     PUSH       ECX
    //         0043a7f9     PUSH       EAX
    //         0043a7fa     CALL       dword ptr [->GDI32.DLL::GetNearestPaletteIndex]  = 0048b294
    //         0043a800     TEST       AL,AL
    //         0043a802     MOV        byte ptr [ESP + 0x13],AL
    //         0043a806     JZ         LAB_0043a782
    //                               LAB_0043a80c                                                 XREF[1]:     0043a7bd(j)  
    //                              Dib.cpp:1829 (11)
    //         0043a80c     MOV        EBX,dword ptr [ESP + 0x140]
    //         0043a813     MOV        ESI,dword ptr [ESP + 0x20]
    //                               LAB_0043a817                                                 XREF[1]:     0043a727(j)  
    //                              Dib.cpp:1849 (13)
    //         0043a817     XOR        EDI,EDI
    //         0043a819     TEST       ESI,ESI
    //         0043a81b     JLE        LAB_0043a89a
    //         0043a81d     MOV        ECX,dword ptr [ESP + 0x24]
    //         0043a821     LEA        ESI,[ECX + 0x2]
    //                               LAB_0043a824                                                 XREF[1]:     0043a896(j)  
    //                              Dib.cpp:1851 (11)
    //         0043a824     MOV        EAX,dword ptr [ESP + 0x144]
    //         0043a82b     TEST       EAX,EAX
    //         0043a82d     JZ         LAB_0043a86f
    //                              Dib.cpp:1853 (14)
    //         0043a82f     MOV        EDX,dword ptr [ESP + 0x30]
    //         0043a833     AND        EDX,0xff
    //         0043a839     CMP        EDI,EDX
    //         0043a83b     JNZ        LAB_0043a844
    //                              Dib.cpp:1854 (5)
    //         0043a83d     MOV        byte ptr [ESP + EDI*0x1 + 0x38],0x0
    //                              Dib.cpp:1855 (2)
    //         0043a842     JMP        LAB_0043a88c
    //                               LAB_0043a844                                                 XREF[1]:     0043a83b(j)  
    //                              Dib.cpp:1857 (25)
    //         0043a844     XOR        EAX,EAX
    //         0043a846     XOR        ECX,ECX
    //         0043a848     MOV        AL,byte ptr [ESI + -0x1]
    //         0043a84b     MOV        CL,byte ptr [ESI]
    //         0043a84d     MOV        AH,byte ptr [ESI + -0x2]
    //         0043a850     SHL        EAX,0x8
    //         0043a853     OR         EAX,ECX
    //         0043a855     PUSH       EAX
    //         0043a856     PUSH       EBX
    //         0043a857     CALL       dword ptr [->GDI32.DLL::GetNearestPaletteIndex]  = 0048b294
    //                              Dib.cpp:1858 (8)
    //         0043a85d     TEST       AL,AL
    //         0043a85f     MOV        byte ptr [ESP + EDI*0x1 + 0x38],AL
    //         0043a863     JNZ        LAB_0043a88c
    //                              Dib.cpp:1859 (8)
    //         0043a865     MOV        DL,byte ptr [ESP + 0x13]
    //         0043a869     MOV        byte ptr [ESP + EDI*0x1 + 0x38],DL
    //                              Dib.cpp:1862 (2)
    //         0043a86d     JMP        LAB_0043a88c
    //                               LAB_0043a86f                                                 XREF[1]:     0043a82d(j)  
    //                              Dib.cpp:1865 (25)
    //         0043a86f     XOR        EAX,EAX
    //         0043a871     XOR        ECX,ECX
    //         0043a873     MOV        AL,byte ptr [ESI + -0x1]
    //         0043a876     MOV        CL,byte ptr [ESI]
    //         0043a878     MOV        AH,byte ptr [ESI + -0x2]
    //         0043a87b     SHL        EAX,0x8
    //         0043a87e     OR         EAX,ECX
    //         0043a880     PUSH       EAX
    //         0043a881     PUSH       EBX
    //         0043a882     CALL       dword ptr [->GDI32.DLL::GetNearestPaletteIndex]  = 0048b294
    //                              Dib.cpp:1866 (16)
    //         0043a888     MOV        byte ptr [ESP + EDI*0x1 + 0x38],AL
    //                               LAB_0043a88c                                                 XREF[3]:     0043a842(j), 0043a863(j), 
    //                                                                                                         0043a86d(j)  
    //         0043a88c     MOV        EAX,dword ptr [ESP + 0x20]
    //         0043a890     INC        EDI
    //         0043a891     ADD        ESI,0x4
    //         0043a894     CMP        EDI,EAX
    //         0043a896     JL         LAB_0043a824
    //                              Dib.cpp:1849 (2)
    //         0043a898     MOV        ESI,EAX
    //                               LAB_0043a89a                                                 XREF[1]:     0043a81b(j)  
    //                              Dib.cpp:1870 (4)
    //         0043a89a     MOV        EAX,dword ptr [ESP + 0x1c]
    //                              Dib.cpp:1875 (7)
    //         0043a89e     CMP        EAX,ESI
    //         0043a8a0     MOV        dword ptr [EBP + 0x20],EAX
    //         0043a8a3     JLE        LAB_0043a923
    //                              Dib.cpp:1877 (52)
    //         0043a8a5     MOV        ESI,dword ptr [->KERNEL32.DLL::GlobalHandle]     = 0048ab0c
    //         0043a8ab     PUSH       EBP
    //         0043a8ac     CALL       ESI=>KERNEL32.DLL::GlobalHandle
    //         0043a8ae     PUSH       EAX
    //         0043a8af     CALL       dword ptr [->KERNEL32.DLL::GlobalUnlock]         = 0048aafc
    //         0043a8b5     MOV        EDX,dword ptr [EBP]
    //         0043a8b8     MOV        EAX,dword ptr [ESP + 0x1c]
    //         0043a8bc     MOV        EDI,dword ptr [ESP + 0x18]
    //         0043a8c0     PUSH       0x0
    //         0043a8c2     LEA        ECX,[EDX + EAX*0x4]
    //         0043a8c5     ADD        ECX,EDI
    //         0043a8c7     PUSH       ECX=>DAT_fffffff8
    //         0043a8c8     PUSH       EBP=>DAT_fffffff4
    //         0043a8c9     CALL       ESI=>KERNEL32.DLL::GlobalHandle
    //         0043a8cb     PUSH       EAX
    //         0043a8cc     CALL       dword ptr [->KERNEL32.DLL::GlobalReAlloc]        = 0048aaec
    //         0043a8d2     PUSH       EAX
    //         0043a8d3     CALL       dword ptr [->KERNEL32.DLL::GlobalLock]           = 0048aade
    //                              Dib.cpp:1878 (44)
    //         0043a8d9     MOV        EAX,dword ptr [EBP + 0x10]
    //         0043a8dc     MOV        ESI,0x3
    //         0043a8e1     CMP        EAX,ESI
    //         0043a8e3     JNZ        LAB_0043a8ee
    //         0043a8e5     MOV        EDX,dword ptr [EBP]
    //         0043a8e8     LEA        EAX,[EDX + EBP*0x1 + 0xc]
    //         0043a8ec     JMP        LAB_0043a8f9
    //                               LAB_0043a8ee                                                 XREF[1]:     0043a8e3(j)  
    //         0043a8ee     MOV        EAX,dword ptr [EBP + 0x20]
    //         0043a8f1     MOV        ECX,dword ptr [EBP]
    //         0043a8f4     LEA        EAX,[ECX + EAX*0x4]
    //         0043a8f7     ADD        EAX,EBP
    //                               LAB_0043a8f9                                                 XREF[1]:     0043a8ec(j)  
    //         0043a8f9     MOV        EDX,dword ptr [ESP + 0x14]
    //         0043a8fd     PUSH       EDI
    //         0043a8fe     PUSH       EDX=>DAT_fffffff8
    //         0043a8ff     PUSH       EAX=>DAT_fffffff4
    //         0043a900     CALL       memmove                                          undefined memmove()
    //                              Dib.cpp:1879 (14)
    //         0043a905     MOV        EAX,dword ptr [EBP + 0x10]
    //         0043a908     ADD        ESP,0xc
    //         0043a90b     CMP        EAX,ESI
    //         0043a90d     JNZ        LAB_0043a99a
    //                              Dib.cpp:1885 (16)
    //         0043a913     MOV        EAX,dword ptr [EBP]
    //         0043a916     LEA        ECX,[EAX + EBP*0x1 + 0xc]
    //         0043a91a     MOV        dword ptr [ESP + 0x14],ECX
    //         0043a91e     JMP        LAB_0043a9a9
    //                               LAB_0043a923                                                 XREF[1]:     0043a8a3(j)  
    //                              Dib.cpp:1881 (6)
    //         0043a923     JGE        LAB_0043a9a9
    //                              Dib.cpp:1883 (39)
    //         0043a929     CMP        dword ptr [EBP + 0x10],0x3
    //         0043a92d     JNZ        LAB_0043a938
    //         0043a92f     MOV        ECX,dword ptr [EBP]
    //         0043a932     LEA        EAX,[ECX + EBP*0x1 + 0xc]
    //         0043a936     JMP        LAB_0043a940
    //                               LAB_0043a938                                                 XREF[1]:     0043a92d(j)  
    //         0043a938     MOV        EDX,dword ptr [EBP]
    //         0043a93b     LEA        EAX,[EDX + EAX*0x4]
    //         0043a93e     ADD        EAX,EBP
    //                               LAB_0043a940                                                 XREF[1]:     0043a936(j)  
    //         0043a940     MOV        ECX,dword ptr [ESP + 0x18]
    //         0043a944     MOV        EDX,dword ptr [ESP + 0x14]
    //         0043a948     PUSH       ECX
    //         0043a949     PUSH       EDX
    //         0043a94a     PUSH       EAX
    //         0043a94b     CALL       memcpy                                           undefined memcpy()
    //                              Dib.cpp:1884 (55)
    //         0043a950     MOV        ESI,dword ptr [->KERNEL32.DLL::GlobalHandle]     = 0048ab0c
    //         0043a956     ADD        ESP,0xc
    //         0043a959     PUSH       EBP
    //         0043a95a     CALL       ESI=>KERNEL32.DLL::GlobalHandle
    //         0043a95c     PUSH       EAX
    //         0043a95d     CALL       dword ptr [->KERNEL32.DLL::GlobalUnlock]         = 0048aafc
    //         0043a963     MOV        EAX,dword ptr [EBP]
    //         0043a966     MOV        ECX,dword ptr [ESP + 0x1c]
    //         0043a96a     PUSH       0x0
    //         0043a96c     LEA        EDX,[EAX + ECX*0x4]
    //         0043a96f     MOV        ECX,dword ptr [ESP + 0x1c]
    //         0043a973     ADD        EDX,ECX
    //         0043a975     PUSH       EDX=>DAT_fffffff8
    //         0043a976     PUSH       EBP=>DAT_fffffff4
    //         0043a977     CALL       ESI=>KERNEL32.DLL::GlobalHandle
    //         0043a979     PUSH       EAX
    //         0043a97a     CALL       dword ptr [->KERNEL32.DLL::GlobalReAlloc]        = 0048aaec
    //         0043a980     PUSH       EAX
    //         0043a981     CALL       dword ptr [->KERNEL32.DLL::GlobalLock]           = 0048aade
    //                              Dib.cpp:1885 (34)
    //         0043a987     CMP        dword ptr [EBP + 0x10],0x3
    //         0043a98b     JNZ        LAB_0043a99a
    //         0043a98d     MOV        EAX,dword ptr [EBP]
    //         0043a990     LEA        ECX,[EAX + EBP*0x1 + 0xc]
    //         0043a994     MOV        dword ptr [ESP + 0x14],ECX
    //         0043a998     JMP        LAB_0043a9a9
    //                               LAB_0043a99a                                                 XREF[2]:     0043a90d(j), 0043a98b(j)  
    //         0043a99a     MOV        EDX,dword ptr [EBP + 0x20]
    //         0043a99d     MOV        EAX,dword ptr [EBP]
    //         0043a9a0     LEA        EAX,[EAX + EDX*0x4]
    //         0043a9a3     ADD        EAX,EBP
    //         0043a9a5     MOV        dword ptr [ESP + 0x14],EAX
    //                               LAB_0043a9a9                                                 XREF[3]:     0043a91e(j), 0043a923(j), 
    //                                                                                                         0043a998(j)  
    //                              Dib.cpp:1891 (14)
    //         0043a9a9     MOV        EAX,dword ptr [EBP + 0x10]
    //         0043a9ac     SUB        EAX,0x0
    //         0043a9af     JZ         LAB_0043a9e3
    //         0043a9b1     DEC        EAX
    //         0043a9b2     JZ         LAB_0043a9cd
    //         0043a9b4     DEC        EAX
    //         0043a9b5     JNZ        LAB_0043aa08
    //                              Dib.cpp:1898 (20)
    //         0043a9b7     MOV        EDX,dword ptr [ESP + 0x18]
    //         0043a9bb     MOV        EAX,dword ptr [ESP + 0x14]
    //         0043a9bf     LEA        ECX,[ESP + 0x38]
    //         0043a9c3     PUSH       ECX
    //         0043a9c4     PUSH       EDX=>DAT_fffffff8
    //         0043a9c5     PUSH       EAX=>DAT_fffffff4
    //         0043a9c6     CALL       xlatRle4                                         undefined xlatRle4()
    //                              Dib.cpp:1899 (2)
    //         0043a9cb     JMP        LAB_0043aa05
    //                               LAB_0043a9cd                                                 XREF[1]:     0043a9b2(j)  
    //                              Dib.cpp:1894 (20)
    //         0043a9cd     MOV        EDX,dword ptr [ESP + 0x18]
    //         0043a9d1     MOV        EAX,dword ptr [ESP + 0x14]
    //         0043a9d5     LEA        ECX,[ESP + 0x38]
    //         0043a9d9     PUSH       ECX
    //         0043a9da     PUSH       EDX=>DAT_fffffff8
    //         0043a9db     PUSH       EAX=>DAT_fffffff4
    //         0043a9dc     CALL       xlatRle8                                         undefined xlatRle8()
    //                              Dib.cpp:1895 (2)
    //         0043a9e1     JMP        LAB_0043aa05
    //                               LAB_0043a9e3                                                 XREF[1]:     0043a9af(j)  
    //                              Dib.cpp:1903 (27)
    //         0043a9e3     MOV        EDX,dword ptr [ESP + 0x18]
    //         0043a9e7     MOV        EAX,dword ptr [ESP + 0x14]
    //         0043a9eb     CMP        word ptr [EBP + 0xe],0x8
    //         0043a9f0     LEA        ECX,[ESP + 0x38]
    //         0043a9f4     PUSH       ECX
    //         0043a9f5     PUSH       EDX=>DAT_fffffff8
    //         0043a9f6     PUSH       EAX=>DAT_fffffff4
    //         0043a9f7     JNZ        LAB_0043aa00
    //         0043a9f9     CALL       xlatClut8                                        undefined xlatClut8()
    //                              Dib.cpp:1904 (2)
    //         0043a9fe     JMP        LAB_0043aa05
    //                               LAB_0043aa00                                                 XREF[1]:     0043a9f7(j)  
    //                              Dib.cpp:1905 (8)
    //         0043aa00     CALL       xlatClut4                                        undefined xlatClut4()
    //                               LAB_0043aa05                                                 XREF[3]:     0043a9cb(j), 0043a9e1(j), 
    //                                                                                                         0043a9fe(j)  
    //         0043aa05     ADD        ESP,0xc
    //                               LAB_0043aa08                                                 XREF[1]:     0043a9b5(j)  
    //                              Dib.cpp:1912 (23)
    //         0043aa08     MOV        EAX,dword ptr [ESP + 0x1c]
    //         0043aa0c     XOR        EDI,EDI
    //         0043aa0e     TEST       EAX,EAX
    //         0043aa10     JLE        LAB_0043aa4e
    //         0043aa12     MOV        ECX,dword ptr [ESP + 0x24]
    //         0043aa16     MOV        EBP,dword ptr [->GDI32.DLL::GetPaletteEntries]   = 0048b270
    //         0043aa1c     LEA        ESI,[ECX + 0x1]
    //                               LAB_0043aa1f                                                 XREF[1]:     0043aa4c(j)  
    //                              Dib.cpp:1914 (11)
    //         0043aa1f     LEA        EDX,[ESP + 0x28]
    //         0043aa23     PUSH       EDX
    //         0043aa24     PUSH       offset DAT_fffffff8
    //         0043aa26     PUSH       EDI=>DAT_fffffff4
    //         0043aa27     PUSH       EBX=>DAT_fffffff0
    //         0043aa28     CALL       EBP=>GDI32.DLL::GetPaletteEntries
    //                              Dib.cpp:1916 (8)
    //         0043aa2a     MOV        AL,byte ptr [ESP + 0x28]
    //         0043aa2e     INC        EDI
    //         0043aa2f     MOV        byte ptr [ESI + 0x1],AL
    //                              Dib.cpp:1917 (6)
    //         0043aa32     MOV        CL,byte ptr [ESP + 0x29]
    //         0043aa36     MOV        byte ptr [ESI],CL
    //                              Dib.cpp:1918 (7)
    //         0043aa38     MOV        DL,byte ptr [ESP + 0x2a]
    //         0043aa3c     MOV        byte ptr [ESI + -0x1],DL
    //                              Dib.cpp:1919 (15)
    //         0043aa3f     MOV        byte ptr [ESI + 0x2],0x0
    //         0043aa43     MOV        EAX,dword ptr [ESP + 0x1c]
    //         0043aa47     ADD        ESI,0x4
    //         0043aa4a     CMP        EDI,EAX
    //         0043aa4c     JL         LAB_0043aa1f
    //                               LAB_0043aa4e                                                 XREF[3]:     0043a685(j), 0043a694(j), 
    //                                                                                                         0043aa10(j)  
    //                              Dib.cpp:1923 (11)
    //         0043aa4e     POP        EDI
    //         0043aa4f     POP        ESI
    //         0043aa50     POP        EBP
    //         0043aa51     POP        EBX
    //         0043aa52     ADD        ESP,0x128
    //         0043aa58     RET
    //         0043aa59     ??         90h
    //         0043aa5a     NOP
    //         0043aa5b     NOP
    //         0043aa5c     NOP
    //         0043aa5d     NOP
    //         0043aa5e     NOP
    //         0043aa5f     NOP
    //                              *                                               FUNCTION                                                *
    //                              undefined xlatClut8()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               xlatClut8                                                    XREF[1]:     DibMapToPalette:0043a9f9(c)  
    //                              Dib.cpp:1691 (17)
    //         0043aa60     MOV        ECX,dword ptr [ESP + Stack[0x8]]
    //         0043aa64     TEST       ECX,ECX
    //         0043aa66     JBE        LAB_0043aa80
    //         0043aa68     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         0043aa6c     PUSH       ESI
    //         0043aa6d     MOV        ESI,dword ptr [ESP + Stack[0xc]]
    //                               LAB_0043aa71                                                 XREF[1]:     0043aa7d(j)  
    //                              Dib.cpp:1699 (14)
    //         0043aa71     XOR        EDX,EDX
    //         0043aa73     MOV        DL,byte ptr [EAX]
    //         0043aa75     INC        EAX
    //         0043aa76     DEC        ECX
    //         0043aa77     MOV        DL,byte ptr [EDX + ESI*0x1]
    //         0043aa7a     MOV        byte ptr [EAX + -0x1],DL
    //         0043aa7d     JNZ        LAB_0043aa71
    //                              Dib.cpp:1691 (1)
    //         0043aa7f     POP        ESI
    //                               LAB_0043aa80                                                 XREF[1]:     0043aa66(j)  
    //                              Dib.cpp:1700 (1)
    //         0043aa80     RET
    //         0043aa81     ??         90h
    //         0043aa82     NOP
    //         0043aa83     NOP
    //         0043aa84     NOP
    //         0043aa85     NOP
    //         0043aa86     NOP
    //         0043aa87     NOP
    //         0043aa88     NOP
    //         0043aa89     NOP
    //         0043aa8a     NOP
    //         0043aa8b     NOP
    //         0043aa8c     NOP
    //         0043aa8d     NOP
    //         0043aa8e     NOP
    //         0043aa8f     NOP
    //                              *                                               FUNCTION                                                *
    //                              undefined xlatClut4()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               xlatClut4                                                    XREF[1]:     DibMapToPalette:0043aa00(c)  
    //                              Dib.cpp:1703 (1)
    //         0043aa90     PUSH       EDI
    //                              Dib.cpp:1707 (17)
    //         0043aa91     MOV        EDI,dword ptr [ESP + Stack[0x8]]
    //         0043aa95     TEST       EDI,EDI
    //         0043aa97     JBE        LAB_0043aac0
    //         0043aa99     MOV        ECX,dword ptr [ESP + Stack[0x4]]
    //         0043aa9d     PUSH       ESI
    //         0043aa9e     MOV        ESI,dword ptr [ESP + Stack[0xc]]
    //                               LAB_0043aaa2                                                 XREF[1]:     0043aabd(j)  
    //                              Dib.cpp:1711 (29)
    //         0043aaa2     XOR        EAX,EAX
    //         0043aaa4     MOV        AL,byte ptr [ECX]
    //         0043aaa6     MOV        EDX,EAX
    //         0043aaa8     SHR        EAX,0x4
    //         0043aaab     AND        EDX,0xf
    //         0043aaae     MOV        AL,byte ptr [EAX + ESI*0x1]
    //         0043aab1     MOV        DL,byte ptr [EDX + ESI*0x1]
    //         0043aab4     SHL        AL,0x4
    //         0043aab7     OR         DL,AL
    //         0043aab9     MOV        byte ptr [ECX],DL
    //         0043aabb     INC        ECX
    //         0043aabc     DEC        EDI
    //         0043aabd     JNZ        LAB_0043aaa2
    //                              Dib.cpp:1703 (1)
    //         0043aabf     POP        ESI
    //                               LAB_0043aac0                                                 XREF[1]:     0043aa97(j)  
    //                              Dib.cpp:1712 (2)
    //         0043aac0     POP        EDI
    //         0043aac1     RET
    //         0043aac2     ??         90h
    //         0043aac3     NOP
    //         0043aac4     NOP
    //         0043aac5     NOP
    //         0043aac6     NOP
    //         0043aac7     NOP
    //         0043aac8     NOP
    //         0043aac9     NOP
    //         0043aaca     NOP
    //         0043aacb     NOP
    //         0043aacc     NOP
    //         0043aacd     NOP
    //         0043aace     NOP
    //         0043aacf     NOP
    //                              *                                               FUNCTION                                                *
    //                              undefined xlatRle8()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               xlatRle8                                                     XREF[1]:     DibMapToPalette:0043a9dc(c)  
    //                              Dib.cpp:1720 (10)
    //         0043aad0     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         0043aad4     PUSH       EBX
    //         0043aad5     PUSH       ESI
    //         0043aad6     MOV        ESI,dword ptr [ESP + Stack[0xc]]
    //                               LAB_0043aada                                                 XREF[5]:     0043aaf8(j), 0043ab15(j), 
    //                                                                                                         0043ab18(j), 0043ab1d(j), 
    //                                                                                                         0043ab30(j)  
    //                              Dib.cpp:1727 (2)
    //         0043aada     MOV        CL,byte ptr [EAX]
    //                              Dib.cpp:1728 (8)
    //         0043aadc     MOV        BL,byte ptr [EAX + 0x1]
    //         0043aadf     INC        EAX
    //         0043aae0     MOV        byte ptr [ESP + Stack[0x4]],BL
    //                              Dib.cpp:1730 (4)
    //         0043aae4     TEST       CL,CL
    //         0043aae6     JNZ        LAB_0043ab1f
    //                              Dib.cpp:1734 (24)
    //         0043aae8     MOV        ECX,dword ptr [ESP + Stack[0x4]]
    //         0043aaec     INC        EAX
    //         0043aaed     AND        ECX,0xff
    //         0043aaf3     MOV        EDX,ECX
    //         0043aaf5     SUB        EDX,0x0
    //         0043aaf8     JZ         LAB_0043aada
    //         0043aafa     DEC        EDX
    //         0043aafb     JZ         LAB_0043ab32
    //         0043aafd     DEC        EDX
    //         0043aafe     JZ         LAB_0043ab1a
    //                              Dib.cpp:1749 (4)
    //         0043ab00     TEST       BL,BL
    //         0043ab02     JBE        LAB_0043ab12
    //                               LAB_0043ab04                                                 XREF[1]:     0043ab10(j)  
    //                              Dib.cpp:1750 (14)
    //         0043ab04     XOR        EDX,EDX
    //         0043ab06     MOV        DL,byte ptr [EAX]
    //         0043ab08     INC        EAX
    //         0043ab09     DEC        ECX
    //         0043ab0a     MOV        DL,byte ptr [ESI + EDX*0x1]
    //         0043ab0d     MOV        byte ptr [EAX + -0x1],DL
    //         0043ab10     JNZ        LAB_0043ab04
    //                               LAB_0043ab12                                                 XREF[1]:     0043ab02(j)  
    //                              Dib.cpp:1752 (5)
    //         0043ab12     TEST       BL,0x1
    //         0043ab15     JZ         LAB_0043aada
    //                              Dib.cpp:1753 (1)
    //         0043ab17     INC        EAX
    //                              Dib.cpp:1755 (2)
    //         0043ab18     JMP        LAB_0043aada
    //                               LAB_0043ab1a                                                 XREF[1]:     0043aafe(j)  
    //                              Dib.cpp:1744 (3)
    //         0043ab1a     ADD        EAX,0x2
    //                              Dib.cpp:1758 (2)
    //         0043ab1d     JMP        LAB_0043aada
    //                               LAB_0043ab1f                                                 XREF[1]:     0043aae6(j)  
    //                              Dib.cpp:1760 (17)
    //         0043ab1f     MOV        ECX,dword ptr [ESP + Stack[0x4]]
    //         0043ab23     AND        ECX,0xff
    //         0043ab29     INC        EAX
    //         0043ab2a     MOV        DL,byte ptr [ECX + ESI*0x1]
    //         0043ab2d     MOV        byte ptr [EAX + -0x1],DL
    //                              Dib.cpp:1762 (2)
    //         0043ab30     JMP        LAB_0043aada
    //                               LAB_0043ab32                                                 XREF[1]:     0043aafb(j)  
    //                              Dib.cpp:1763 (3)
    //         0043ab32     POP        ESI
    //         0043ab33     POP        EBX
    //         0043ab34     RET
    //         0043ab35     ??         90h
    //         0043ab36     NOP
    //         0043ab37     NOP
    //         0043ab38     NOP
    //         0043ab39     NOP
    //         0043ab3a     NOP
    //         0043ab3b     NOP
    //         0043ab3c     NOP
    //         0043ab3d     NOP
    //         0043ab3e     NOP
    //         0043ab3f     NOP
    //                              *                                               FUNCTION                                                *
    //                              undefined xlatRle4()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               xlatRle4                                                     XREF[1]:     DibMapToPalette:0043a9c6(c)  
    //                              Dib.cpp:1766 (1)
    //         0043ab40     RET
    //         0043ab41     ??         90h
    //         0043ab42     NOP
    //         0043ab43     NOP
    //         0043ab44     NOP
    //         0043ab45     NOP
    //         0043ab46     NOP
    //         0043ab47     NOP
    //         0043ab48     NOP
    //         0043ab49     NOP
    //         0043ab4a     NOP
    //         0043ab4b     NOP
    //         0043ab4c     NOP
    //         0043ab4d     NOP
    //         0043ab4e     NOP
    //         0043ab4f     NOP
    //                              *                                               FUNCTION                                                *
    //                              undefined memmove()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               memmove                                                      XREF[1]:     DibMapToPalette:0043a900(c)  
    //                              Dib.cpp:1770 (8)
    //         0043ab50     MOV        EDX,dword ptr [ESP + Stack[0xc]]
    //         0043ab54     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //                              Dib.cpp:1772 (9)
    //         0043ab58     MOV        ECX,dword ptr [ESP + Stack[0x8]]
    //         0043ab5c     PUSH       ESI
    //         0043ab5d     LEA        EAX,[EAX + EDX*0x1 + -0x1]
    //                              Dib.cpp:1774 (11)
    //         0043ab61     MOV        ESI,EDX
    //         0043ab63     LEA        ECX,[ECX + EDX*0x1 + -0x1]
    //         0043ab67     DEC        EDX
    //         0043ab68     TEST       ESI,ESI
    //         0043ab6a     JZ         LAB_0043ab78
    //                              Dib.cpp:1771 (3)
    //         0043ab6c     LEA        ESI,[EDX + 0x1]
    //                               LAB_0043ab6f                                                 XREF[1]:     0043ab76(j)  
    //                              Dib.cpp:1775 (9)
    //         0043ab6f     MOV        DL,byte ptr [ECX]
    //         0043ab71     MOV        byte ptr [EAX],DL
    //         0043ab73     DEC        EAX
    //         0043ab74     DEC        ECX
    //         0043ab75     DEC        ESI
    //         0043ab76     JNZ        LAB_0043ab6f
    //                               LAB_0043ab78                                                 XREF[1]:     0043ab6a(j)  
    //                              Dib.cpp:1776 (2)
    //         0043ab78     POP        ESI
    //         0043ab79     RET
    //         0043ab7a     ??         90h
    //         0043ab7b     NOP
    //         0043ab7c     NOP
    //         0043ab7d     NOP
    //         0043ab7e     NOP
    //         0043ab7f     NOP
    //                              * void __cdecl CreateIdentityPalette(void *)                                                            *
    //                              void __cdecl CreateIdentityPalette(void * param_1)
    //              void              <VOID>         <RETURN>
    //              void *            Stack[0x4]:4   param_1
    //              tagPALETTEENTR    Stack[-0x404   from_pal
    //              tagPALETTEENTR    Stack[-0x804   new_pal
    //              void *            Stack[-0x808   hwnd
    //              void *            Stack[-0x80c   hdc
    //                               ?CreateIdentityPalette@@YAXPAX@Z                             XREF[2]:     GetPaletteFromDib:0043972b(c), 
    //                               CreateIdentityPalette                                                     ReadPalette:004399d9(c)  
    //                              Dib.cpp:1930 (10)
    //         0043ab80     SUB        ESP,0x808
    //         0043ab86     PUSH       EBX
    //         0043ab87     PUSH       EBP
    //         0043ab88     PUSH       ESI
    //         0043ab89     PUSH       EDI
    //                              Dib.cpp:1936 (4)
    //         0043ab8a     XOR        EBX,EBX
    //         0043ab8c     XOR        EDI,EDI
    //                              Dib.cpp:1937 (2)
    //         0043ab8e     XOR        EBP,EBP
    //                              Dib.cpp:1940 (6)
    //         0043ab90     CALL       dword ptr [->USER32.DLL::GetActiveWindow]        = 0048afe4
    //                              Dib.cpp:1941 (8)
    //         0043ab96     CMP        EAX,EBX
    //         0043ab98     MOV        dword ptr [ESP + 0x14],EAX
    //         0043ab9c     JZ         LAB_0043aba1
    //                              Dib.cpp:1942 (1)
    //         0043ab9e     PUSH       EAX
    //                              Dib.cpp:1943 (2)
    //         0043ab9f     JMP        LAB_0043aba2
    //                               LAB_0043aba1                                                 XREF[1]:     0043ab9c(j)  
    //                              Dib.cpp:1944 (11)
    //         0043aba1     PUSH       EBX
    //                               LAB_0043aba2                                                 XREF[1]:     0043ab9f(j)  
    //         0043aba2     CALL       dword ptr [->USER32.DLL::GetDC]                  = 0048ae28
    //         0043aba8     MOV        dword ptr [ESP + 0x10],EAX
    //                              Dib.cpp:1948 (31)
    //         0043abac     LEA        EAX,[ESP + 0x18]
    //         0043abb0     MOV        ECX,dword ptr [ESP + 0x10]
    //         0043abb4     PUSH       EAX
    //         0043abb5     PUSH       0x100
    //         0043abba     PUSH       EBX
    //         0043abbb     PUSH       ECX
    //         0043abbc     CALL       dword ptr [->GDI32.DLL::GetSystemPaletteEntries] = 0048b2d2
    //         0043abc2     TEST       EAX,EAX
    //         0043abc4     JNZ        LAB_0043abcb
    //         0043abc6     MOV        EDI,0x1
    //                               LAB_0043abcb                                                 XREF[1]:     0043abc4(j)  
    //                              Dib.cpp:1951 (37)
    //         0043abcb     MOV        EAX,dword ptr [ESP + 0x81c]
    //         0043abd2     LEA        EDX,[ESP + 0x418]
    //         0043abd9     PUSH       EDX
    //         0043abda     PUSH       0x100
    //         0043abdf     PUSH       EBX
    //         0043abe0     PUSH       EAX
    //         0043abe1     CALL       dword ptr [->GDI32.DLL::GetPaletteEntries]       = 0048b270
    //         0043abe7     TEST       EAX,EAX
    //         0043abe9     JNZ        LAB_0043abf0
    //         0043abeb     MOV        EBP,0x1
    //                               LAB_0043abf0                                                 XREF[1]:     0043abe9(j)  
    //                              Dib.cpp:1953 (11)
    //         0043abf0     LEA        ECX,[ESP + 0x43]
    //         0043abf4     LEA        ESI,[ESP + 0x441]
    //                              Dib.cpp:1957 (16)
    //         0043abfb     XOR        EAX,EAX
    //                               LAB_0043abfd                                                 XREF[1]:     0043ac2a(j)  
    //         0043abfd     MOV        DL,byte ptr [ESP + EAX*0x1 + 0x440]
    //         0043ac04     ADD        ESI,0x4
    //         0043ac07     MOV        byte ptr [ESP + EAX*0x1 + 0x40],DL
    //                              Dib.cpp:1958 (7)
    //         0043ac0b     MOV        DL,byte ptr [ESI + -0x4]
    //         0043ac0e     MOV        byte ptr [ESP + EAX*0x1 + 0x41],DL
    //                              Dib.cpp:1959 (10)
    //         0043ac12     MOV        DL,byte ptr [ESP + EAX*0x1 + 0x442]
    //         0043ac19     MOV        byte ptr [ECX + -0x1],DL
    //                              Dib.cpp:1967 (16)
    //         0043ac1c     MOV        byte ptr [ECX],0x1
    //         0043ac1f     ADD        EAX,0x4
    //         0043ac22     ADD        ECX,0x4
    //         0043ac25     CMP        EAX,0x3b0
    //         0043ac2a     JL         LAB_0043abfd
    //                              Dib.cpp:1970 (8)
    //         0043ac2c     CMP        EDI,EBX
    //         0043ac2e     JNZ        LAB_0043ac34
    //         0043ac30     CMP        EBP,EBX
    //         0043ac32     JZ         LAB_0043ac69
    //                               LAB_0043ac34                                                 XREF[1]:     0043ac2e(j)  
    //                              Dib.cpp:1973 (10)
    //         0043ac34     MOV        ECX,dword ptr [System_color_Table]               = 00000000
    //         0043ac3a     CMP        ECX,EBX
    //         0043ac3c     JL         LAB_0043ac69
    //                              Dib.cpp:1972 (5)
    //         0043ac3e     MOV        EAX,DAT_005841e5
    //                               LAB_0043ac43                                                 XREF[1]:     0043ac67(j)  
    //                              Dib.cpp:1976 (3)
    //         0043ac43     MOV        DL,byte ptr [EAX + -0x1]=>DAT_005841e4           = 80h
    //                              Dib.cpp:1980 (35)
    //         0043ac46     ADD        EAX,0x8
    //         0043ac49     SHL        ECX,0x2
    //         0043ac4c     MOV        byte ptr [ESP + ECX*0x1 + 0x18],DL
    //         0043ac50     MOV        DL,byte ptr [EAX + -0x8]=>DAT_005841e5
    //         0043ac53     MOV        byte ptr [ESP + ECX*0x1 + 0x19],DL
    //         0043ac57     MOV        DL,byte ptr [EAX + -0x7]=>DAT_005841e6
    //         0043ac5a     MOV        byte ptr [ESP + ECX*0x1 + 0x1a],DL
    //         0043ac5e     MOV        byte ptr [ESP + ECX*0x1 + 0x1b],BL
    //         0043ac62     MOV        ECX,dword ptr [EAX + -0x5]=>DAT_005841e8         = 00000001h
    //                                                                                  = 00000002h
    //         0043ac65     CMP        ECX,EBX
    //         0043ac67     JGE        LAB_0043ac43
    //                               LAB_0043ac69                                                 XREF[2]:     0043ac32(j), 0043ac3c(j)  
    //                              Dib.cpp:1987 (16)
    //         0043ac69     MOV        EAX,dword ptr [ESP + 0x10]
    //         0043ac6d     MOV        ECX,dword ptr [ESP + 0x14]
    //         0043ac71     PUSH       EAX
    //         0043ac72     PUSH       ECX
    //         0043ac73     CALL       dword ptr [->USER32.DLL::ReleaseDC]              = 0048ae1c
    //                              Dib.cpp:1990 (19)
    //         0043ac79     MOV        ESI,dword ptr [ESP + 0x81c]
    //         0043ac80     PUSH       0x100
    //         0043ac85     PUSH       ESI
    //         0043ac86     CALL       dword ptr [->GDI32.DLL::ResizePalette]           = 0048b2c2
    //                              Dib.cpp:1991 (18)
    //         0043ac8c     LEA        EDX,[ESP + 0x18]
    //         0043ac90     PUSH       EDX
    //         0043ac91     PUSH       0x100
    //         0043ac96     PUSH       EBX
    //         0043ac97     PUSH       ESI
    //         0043ac98     CALL       dword ptr [->GDI32.DLL::SetPaletteEntries]       = 0048b2ae
    //                              Dib.cpp:1992 (11)
    //         0043ac9e     POP        EDI
    //         0043ac9f     POP        ESI
    //         0043aca0     POP        EBP
    //         0043aca1     POP        EBX
    //         0043aca2     ADD        ESP,0x808
    //         0043aca8     RET
    //         0043aca9     ??         90h
    //         0043acaa     NOP
    //         0043acab     NOP
    //         0043acac     NOP
    //         0043acad     NOP
    //         0043acae     NOP
    //         0043acaf     NOP
    //                              * void * __cdecl CopyPalette(void *)                                                                    *
    //                              void * __cdecl CopyPalette(void * param_1)
    //              void *            EAX:4          <RETURN>
    //              void *            Stack[0x4]:4   param_1                   XREF[1]:     0043acb3(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     0043acb7(W), 0043acc9(*)  
    //              int               Stack[-0x8]:4  nNumEntries
    //                               ?CopyPalette@@YAPAXPAX@Z
    //                               CopyPalette
    //                              Dib.cpp:1999 (3)
    //         0043acb0     PUSH       ECX
    //         0043acb1     PUSH       ESI
    //         0043acb2     PUSH       EDI
    //                              Dib.cpp:2003 (16)
    //         0043acb3     MOV        EDI,dword ptr [ESP + param_1]
    //         0043acb7     MOV        dword ptr [ESP + local_4],0x0
    //         0043acbf     TEST       EDI,EDI
    //         0043acc1     JNZ        LAB_0043acc9
    //                              Dib.cpp:2004 (2)
    //         0043acc3     XOR        EAX,EAX
    //                              Dib.cpp:2026 (4)
    //         0043acc5     POP        EDI
    //         0043acc6     POP        ESI
    //         0043acc7     POP        ECX
    //         0043acc8     RET
    //                               LAB_0043acc9                                                 XREF[1]:     0043acc1(j)  
    //                              Dib.cpp:2006 (14)
    //         0043acc9     LEA        EAX=>local_4,[ESP + 0x8]
    //         0043accd     PUSH       EAX
    //         0043acce     PUSH       0x4
    //         0043acd0     PUSH       EDI
    //         0043acd1     CALL       dword ptr [->GDI32.DLL::GetObjectA]              = 0048b262
    //                              Dib.cpp:2008 (8)
    //         0043acd7     MOV        EAX,dword ptr [ESP + 0x8]
    //         0043acdb     TEST       EAX,EAX
    //         0043acdd     JNZ        LAB_0043ace3
    //                              Dib.cpp:2026 (4)
    //         0043acdf     POP        EDI
    //         0043ace0     POP        ESI
    //         0043ace1     POP        ECX
    //         0043ace2     RET
    //                               LAB_0043ace3                                                 XREF[1]:     0043acdd(j)  
    //                              Dib.cpp:2012 (18)
    //         0043ace3     LEA        ECX,[EAX*0x4 + 0x8]
    //         0043acea     PUSH       ECX
    //         0043aceb     PUSH       0x40
    //         0043aced     CALL       dword ptr [->KERNEL32.DLL::LocalAlloc]           = 0048ab80
    //         0043acf3     MOV        ESI,EAX
    //                              Dib.cpp:2014 (4)
    //         0043acf5     TEST       ESI,ESI
    //         0043acf7     JNZ        LAB_0043acfd
    //                              Dib.cpp:2026 (4)
    //         0043acf9     POP        EDI
    //         0043acfa     POP        ESI
    //         0043acfb     POP        ECX
    //         0043acfc     RET
    //                               LAB_0043acfd                                                 XREF[1]:     0043acf7(j)  
    //                              Dib.cpp:2017 (5)
    //         0043acfd     MOV        word ptr [ESI],0x300
    //                              Dib.cpp:2018 (9)
    //         0043ad02     MOV        DX,word ptr [ESP + 0x8]
    //         0043ad07     MOV        word ptr [ESI + 0x2],DX
    //                              Dib.cpp:2020 (18)
    //         0043ad0b     MOV        ECX,dword ptr [ESP + 0x8]
    //         0043ad0f     LEA        EAX,[ESI + 0x4]
    //         0043ad12     PUSH       EAX
    //         0043ad13     PUSH       ECX=>DAT_fffffff8
    //         0043ad14     PUSH       0x0=>DAT_fffffff4
    //         0043ad16     PUSH       EDI=>DAT_fffffff0
    //         0043ad17     CALL       dword ptr [->GDI32.DLL::GetPaletteEntries]       = 0048b270
    //                              Dib.cpp:2022 (7)
    //         0043ad1d     PUSH       ESI
    //         0043ad1e     CALL       dword ptr [->GDI32.DLL::CreatePalette]           = 0048b204
    //                              Dib.cpp:2024 (9)
    //         0043ad24     PUSH       ESI
    //         0043ad25     MOV        EDI,EAX
    //         0043ad27     CALL       dword ptr [->KERNEL32.DLL::LocalFree]            = 0048ab74
    //                              Dib.cpp:2025 (2)
    //         0043ad2d     MOV        EAX,EDI
    //                              Dib.cpp:2026 (4)
    //         0043ad2f     POP        EDI
    //         0043ad30     POP        ESI
    //         0043ad31     POP        ECX
    //         0043ad32     RET
    //         0043ad33     ??         90h
    //         0043ad34     NOP
    //         0043ad35     NOP
    //         0043ad36     NOP
    //         0043ad37     NOP
    //         0043ad38     NOP
    //         0043ad39     NOP
    //         0043ad3a     NOP
    //         0043ad3b     NOP
    //         0043ad3c     NOP
    //         0043ad3d     NOP
    //         0043ad3e     NOP
    //         0043ad3f     NOP
    //                              * void __cdecl DibFree(struct tagBITMAPINFOHEADER *)                                                    *
    //                              void __cdecl DibFree(tagBITMAPINFOHEADER * param_1)
    //              void              <VOID>         <RETURN>
    //              tagBITMAPINFOH    Stack[0x4]:4   param_1                   XREF[1]:     0043ad41(R)  
    //                               ?DibFree@@YAXPAUtagBITMAPINFOHEADER@@@Z                      XREF[6]:     GetPaletteFromDib:00439734(c), 
    //                               DibFree                                                                   DibWriteClipped:00439ca2(c), 
    //                                                                                                         DibFromBitmap:0043a2e7(c), 
    //                                                                                                         TPicture:0046df66(c), 
    //                                                                                                         ~TPicture:0046e00b(c), 
    //                                                                                                         Load:0046e231(c)  
    //                              Dib.cpp:2029 (1)
    //         0043ad40     PUSH       ESI
    //                              Dib.cpp:2030 (31)
    //         0043ad41     MOV        ESI,dword ptr [ESP + param_1]
    //         0043ad45     PUSH       EDI
    //         0043ad46     MOV        EDI,dword ptr [->KERNEL32.DLL::GlobalHandle]     = 0048ab0c
    //         0043ad4c     PUSH       ESI
    //         0043ad4d     CALL       EDI=>KERNEL32.DLL::GlobalHandle
    //         0043ad4f     PUSH       EAX
    //         0043ad50     CALL       dword ptr [->KERNEL32.DLL::GlobalUnlock]         = 0048aafc
    //         0043ad56     PUSH       ESI
    //         0043ad57     CALL       EDI=>KERNEL32.DLL::GlobalHandle
    //         0043ad59     PUSH       EAX
    //         0043ad5a     CALL       dword ptr [->KERNEL32.DLL::GlobalFree]           = 0048aad0
    //                              Dib.cpp:2031 (3)
    //         0043ad60     POP        EDI
    //         0043ad61     POP        ESI
    //         0043ad62     RET
    //         0043ad63     ??         90h
    //         0043ad64     NOP
    //         0043ad65     NOP
    //         0043ad66     NOP
    //         0043ad67     NOP
    //         0043ad68     NOP
    //         0043ad69     NOP
    //         0043ad6a     NOP
    //         0043ad6b     NOP
    //         0043ad6c     NOP
    //         0043ad6d     NOP
    //         0043ad6e     NOP
    //         0043ad6f     NOP
    return 0;
}

long RGE_Diamond_Map::setup(TDrawArea* param_1, TPanel* param_2, long param_3, long param_4, long param_5, long param_6, uchar param_7, int param_8, TDrawArea* param_9) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return 0;
}

void RGE_Diamond_Map::draw_visible_object(RGE_Static_Object* param_1, uchar param_2, uchar param_3) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return;
}

void RGE_Diamond_Map::draw_object(short param_1, short param_2, uchar param_3, short param_4, RGE_Static_Object* param_5) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return;
}

void RGE_Diamond_Map::draw_clipped_horz_line(short param_1, short param_2, short param_3, uchar param_4, RGE_Map_Image_Line* param_5) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return;
}

