// Auto-generated scaffold unit: effects.cpp.asm
// SourceMap: C:/msdev/work/age1_x1/effects.cpp
#include "../include/common.h"

// Offset: 0x004490E0
undefined RGE_Effects(RGE_Effects* this_, int param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall RGE_Effects::RGE_Effects(int)                                                      *
    //                              *********************************************************************************************************
    //                              undefined __thiscall RGE_Effects(RGE_Effects * this, int param_1)
    //              undefined         <UNASSIGNED>   <RETURN>
    //              RGE_Effects *     ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[5]:     004490e9(R), 00449185(W), 00449191(R), 004491df(R), 
    //                                                                                     004491ec(W)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     004490fe(W), 004491f6(R)  
    //              undefined4        Stack[-0x8]:4  local_8                   XREF[2]:     00449170(W), 0044918b(R)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[2]:     004490f4(W), 004491fe(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[3]:     0044912a(W), 004491fa(R), 0044920a(W)  
    //              int               Stack[-0x14]:4 index                     XREF[3]:     00449134(W), 004491f2(R), 0044920e(W)  
    //                               ??0RGE_Effects@@QAE@H@Z                                      XREF[2]:     TRIBE_Effects:0050d468(c), 
    //                               RGE_Effects::RGE_Effects                                                  effects_init:00541cca(c)  
    //                              effects.cpp:21 (9)
    //         004490e0     SUB        ESP,0x14
    //         004490e3     PUSH       EBX
    //         004490e4     MOV        EBX,this
    //         004490e6     PUSH       EBP
    //         004490e7     PUSH       ESI
    //         004490e8     PUSH       EDI
    //                              effects.cpp:27 (30)
    //         004490e9     MOV        EDI,dword ptr [ESP + param_1]
    //         004490ed     LEA        EBP,[EBX + 0x8]
    //         004490f0     PUSH       0x4
    //         004490f2     PUSH       EBP
    //         004490f3     PUSH       EDI
    //         004490f4     MOV        dword ptr [ESP + local_c],EBX
    //         004490f8     MOV        dword ptr [EBX],RGE_Effects::`vftable'           = 00449240
    //         004490fe     MOV        dword ptr [ESP + local_4],EBP
    //         00449102     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //                              effects.cpp:29 (16)
    //         00449107     MOV        EAX,dword ptr [EBP]
    //         0044910a     XOR        ESI,ESI
    //         0044910c     ADD        ESP,0xc
    //         0044910f     CMP        EAX,ESI
    //         00449111     JLE        LAB_00449224
    //                              effects.cpp:31 (11)
    //         00449117     PUSH       0x2c
    //         00449119     PUSH       EAX
    //         0044911a     CALL       calloc                                           undefined calloc()
    //         0044911f     MOV        dword ptr [EBX + 0x4],EAX
    //                              effects.cpp:34 (18)
    //         00449122     MOV        EAX,dword ptr [EBP]
    //         00449125     ADD        ESP,0x8
    //         00449128     CMP        EAX,ESI
    //         0044912a     MOV        dword ptr [ESP + local_10],ESI
    //         0044912e     JLE        LAB_0044922a
    //                              effects.cpp:63 (4)
    //         00449134     MOV        dword ptr [ESP + index],ESI
    //                               LAB_00449138                                                 XREF[1]:     00449212(j)  
    //                              effects.cpp:36 (3)
    //         00449138     MOV        EBP,dword ptr [EBX + 0x4]
    //                              effects.cpp:37 (15)
    //         0044913b     PUSH       0x1f
    //         0044913d     LEA        EAX,[EBP + 0x2]
    //         00449140     PUSH       EAX
    //         00449141     PUSH       EDI
    //         00449142     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         00449147     ADD        ESP,0xc
    //                              effects.cpp:38 (13)
    //         0044914a     LEA        EBX,[ESI + EBP*0x1 + 0x24]
    //         0044914e     PUSH       0x2
    //         00449150     PUSH       EBX
    //         00449151     PUSH       EDI
    //         00449152     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //                              effects.cpp:41 (15)
    //         00449157     MOV        AX,word ptr [EBX]
    //         0044915a     ADD        ESP,0xc
    //         0044915d     TEST       AX,AX
    //         00449160     JLE        LAB_00449236
    //                              effects.cpp:43 (19)
    //         00449166     MOVSX      this,AX
    //         00449169     LEA        ESI,[ESI + EBP*0x1 + 0x28]
    //         0044916d     PUSH       0xc
    //         0044916f     PUSH       this
    //         00449170     MOV        dword ptr [ESP + local_8],ESI
    //         00449174     CALL       calloc                                           undefined calloc()
    //                              effects.cpp:44 (12)
    //         00449179     XOR        EBP,EBP
    //         0044917b     ADD        ESP,0x8
    //         0044917e     CMP        word ptr [EBX],BP
    //         00449181     MOV        dword ptr [ESI],EAX
    //         00449183     JLE        LAB_004491f2
    //                              effects.cpp:63 (10)
    //         00449185     MOV        dword ptr [ESP + param_1],EBP
    //         00449189     JMP        LAB_0044918f
    //                               LAB_0044918b                                                 XREF[1]:     004491f0(j)  
    //         0044918b     MOV        ESI,dword ptr [ESP + local_8]
    //                               LAB_0044918f                                                 XREF[1]:     00449189(j)  
    //                              effects.cpp:46 (8)
    //         0044918f     MOV        ESI,dword ptr [ESI]
    //         00449191     MOV        EAX,dword ptr [ESP + param_1]
    //         00449195     ADD        ESI,EAX
    //                              effects.cpp:47 (12)
    //         00449197     PUSH       0x1
    //         00449199     PUSH       ESI
    //         0044919a     PUSH       EDI
    //         0044919b     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         004491a0     ADD        ESP,0xc
    //                              effects.cpp:48 (15)
    //         004491a3     LEA        EDX,[ESI + 0x2]
    //         004491a6     PUSH       0x2
    //         004491a8     PUSH       EDX
    //         004491a9     PUSH       EDI
    //         004491aa     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         004491af     ADD        ESP,0xc
    //                              effects.cpp:49 (15)
    //         004491b2     LEA        EAX,[ESI + 0x4]
    //         004491b5     PUSH       0x2
    //         004491b7     PUSH       EAX
    //         004491b8     PUSH       EDI
    //         004491b9     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         004491be     ADD        ESP,0xc
    //                              effects.cpp:50 (15)
    //         004491c1     LEA        this,[ESI + 0x6]
    //         004491c4     PUSH       0x2
    //         004491c6     PUSH       this
    //         004491c7     PUSH       EDI
    //         004491c8     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         004491cd     ADD        ESP,0xc
    //                              effects.cpp:51 (34)
    //         004491d0     ADD        ESI,0x8
    //         004491d3     PUSH       0x4
    //         004491d5     PUSH       ESI
    //         004491d6     PUSH       EDI
    //         004491d7     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         004491dc     MOVSX      EDX,word ptr [EBX]
    //         004491df     MOV        this,dword ptr [ESP + param_1]
    //         004491e3     ADD        ESP,0xc
    //         004491e6     INC        EBP
    //         004491e7     ADD        this,0xc
    //         004491ea     CMP        EBP,EDX
    //         004491ec     MOV        dword ptr [ESP + param_1],this
    //         004491f0     JL         LAB_0044918b
    //                               LAB_004491f2                                                 XREF[1]:     00449183(j)  
    //                              effects.cpp:54 (4)
    //         004491f2     MOV        ESI,dword ptr [ESP + index]
    //                               LAB_004491f6                                                 XREF[1]:     0044923e(j)  
    //                              effects.cpp:34 (8)
    //         004491f6     MOV        this,dword ptr [ESP + local_4]
    //         004491fa     MOV        EAX,dword ptr [ESP + local_10]
    //                              effects.cpp:58 (26)
    //         004491fe     MOV        EBX,dword ptr [ESP + local_c]
    //         00449202     INC        EAX
    //         00449203     MOV        EDX,dword ptr [this->_padding_]
    //         00449205     ADD        ESI,0x2c
    //         00449208     CMP        EAX,EDX
    //         0044920a     MOV        dword ptr [ESP + local_10],EAX
    //         0044920e     MOV        dword ptr [ESP + index],ESI
    //         00449212     JL         LAB_00449138
    //                              effects.cpp:63 (12)
    //         00449218     MOV        EAX,EBX
    //         0044921a     POP        EDI
    //         0044921b     POP        ESI
    //         0044921c     POP        EBP
    //         0044921d     POP        EBX
    //         0044921e     ADD        ESP,0x14
    //         00449221     RET        0x4
    //                               LAB_00449224                                                 XREF[1]:     00449111(j)  
    //                              effects.cpp:60 (3)
    //         00449224     MOV        dword ptr [EBX + 0x4],ESI
    //                              effects.cpp:61 (3)
    //         00449227     MOV        dword ptr [EBP],ESI
    //                               LAB_0044922a                                                 XREF[1]:     0044912e(j)  
    //                              effects.cpp:63 (12)
    //         0044922a     POP        EDI
    //         0044922b     POP        ESI
    //         0044922c     MOV        EAX,EBX
    //         0044922e     POP        EBP
    //         0044922f     POP        EBX
    //         00449230     ADD        ESP,0x14
    //         00449233     RET        0x4
    //                               LAB_00449236                                                 XREF[1]:     00449160(j)  
    //                              effects.cpp:55 (8)
    //         00449236     MOV        dword ptr [ESI + EBP*0x1 + 0x28],0x0
    //                              effects.cpp:54 (2)
    //         0044923e     JMP        LAB_004491f6
}

// Offset: 0x00449260
undefined RGE_Effects(RGE_Effects* this_, char* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall RGE_Effects::RGE_Effects(char *)                                                   *
    //                              *********************************************************************************************************
    //                              undefined __thiscall RGE_Effects(RGE_Effects * this, char * param_1)
    //              undefined         <UNASSIGNED>   <RETURN>
    //              RGE_Effects *     ECX:4 (auto)   this
    //              char *            Stack[0x4]:4   param_1                   XREF[3]:     00449260(R), 00449393(*), 004493ac(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[3]:     0044928d(*), 004492ba(R), 004493ea(R)  
    //              long              Stack[-0x8]:4  count                     XREF[3]:     004492c3(W), 004493e6(R), 004493f4(W)  
    //              long              Stack[-0xc]:4  index                     XREF[8]:     004492d1(*), 004492e1(R), 00449313(R), 00449324(R), 
    //                                                                                     0044934d(R), 00449361(R), 004493b3(R), 004493cf(R)  
    //              long              Stack[-0x10]:4 this_effect_num
    //                               ??0RGE_Effects@@QAE@PAD@Z                                    XREF[2]:     TRIBE_Effects:0050d4b8(c), 
    //                               RGE_Effects::RGE_Effects                                                  data_load_effects:005414da(c)  
    //                              effects.cpp:68 (31)
    //         00449260     MOV        EAX,dword ptr [ESP + param_1]
    //         00449264     SUB        ESP,0xc
    //         00449267     PUSH       EBX
    //         00449268     PUSH       EBP
    //         00449269     PUSH       EDI
    //         0044926a     MOV        EDI,this
    //         0044926c     PUSH       s_r                                              = "r"
    //         00449271     PUSH       EAX
    //         00449272     MOV        dword ptr [EDI],RGE_Effects::`vftable'           = 00449240
    //         00449278     CALL       fopen                                            undefined fopen()
    //         0044927d     MOV        EBP,EAX
    //                              effects.cpp:78 (14)
    //         0044927f     XOR        EBX,EBX
    //         00449281     ADD        ESP,0x8
    //         00449284     CMP        EBP,EBX
    //         00449286     JZ         LAB_0044942d
    //         0044928c     PUSH       ESI
    //                              effects.cpp:80 (32)
    //         0044928d     LEA        this=>local_4,[ESP + 0x18]
    //         00449291     LEA        ESI,[EDI + 0x8]
    //         00449294     PUSH       this
    //         00449295     PUSH       ESI
    //         00449296     PUSH       s_%d_%d                                          = "%d %d"
    //         0044929b     PUSH       EBP
    //         0044929c     CALL       fscanf                                           undefined fscanf()
    //         004492a1     ADD        ESP,0x10
    //         004492a4     CMP        EAX,-0x1
    //         004492a7     JZ         LAB_00449413
    //                              effects.cpp:82 (13)
    //         004492ad     MOV        EDX,dword ptr [ESI]
    //         004492af     PUSH       0x2c
    //         004492b1     PUSH       EDX
    //         004492b2     CALL       calloc                                           undefined calloc()
    //         004492b7     MOV        dword ptr [EDI + 0x4],EAX
    //                              effects.cpp:85 (23)
    //         004492ba     MOV        EAX,dword ptr [ESP + local_4]
    //         004492be     ADD        ESP,0x8
    //         004492c1     CMP        EAX,EBX
    //         004492c3     MOV        dword ptr [ESP + count],EBX
    //         004492c7     JLE        LAB_00449418
    //         004492cd     JMP        LAB_004492d1
    //                               LAB_004492cf                                                 XREF[1]:     004493f8(j)  
    //         004492cf     XOR        EBX,EBX
    //                               LAB_004492d1                                                 XREF[1]:     004492cd(j)  
    //                              effects.cpp:87 (16)
    //         004492d1     LEA        EAX=>index,[ESP + 0x10]
    //         004492d5     PUSH       EAX
    //         004492d6     PUSH       s_%d                                             = 6425h
    //         004492db     PUSH       EBP
    //         004492dc     CALL       fscanf                                           undefined fscanf()
    //                              effects.cpp:90 (50)
    //         004492e1     MOV        EAX,dword ptr [ESP + index]
    //         004492e5     ADD        ESP,0xc
    //         004492e8     LEA        this,[EAX + EAX*0x4]
    //         004492eb     LEA        EDX,[EAX + this->_padding_*0x2]
    //         004492ee     MOV        EAX,dword ptr [EDI + 0x4]
    //         004492f1     LEA        EAX,[EAX + EDX*0x4]
    //         004492f4     LEA        this,[EAX + 0x24]
    //         004492f7     ADD        EAX,0x2
    //         004492fa     PUSH       this
    //         004492fb     PUSH       EAX
    //         004492fc     PUSH       s_%s_%hd                                         = "%s %hd"
    //         00449301     PUSH       EBP
    //         00449302     CALL       fscanf                                           undefined fscanf()
    //         00449307     ADD        ESP,0x10
    //         0044930a     CMP        EAX,-0x1
    //         0044930d     JZ         LAB_00449418
    //                              effects.cpp:93 (17)
    //         00449313     MOV        EAX,dword ptr [ESP + index]
    //         00449317     LEA        EDX,[EAX + EAX*0x4]
    //         0044931a     LEA        this,[EAX + EDX*0x2]
    //         0044931d     MOV        EDX,dword ptr [EDI + 0x4]
    //         00449320     MOV        word ptr [EDX + this->_padding_*0x4],AX
    //                              effects.cpp:95 (30)
    //         00449324     MOV        EAX,dword ptr [ESP + index]
    //         00449328     LEA        this,[EAX + EAX*0x4]
    //         0044932b     LEA        EDX,[EAX + this->_padding_*0x2]
    //         0044932e     MOV        EAX,dword ptr [EDI + 0x4]
    //         00449331     LEA        this,[EAX + EDX*0x4]
    //         00449334     MOV        AX,word ptr [EAX + EDX*0x4 + 0x24]
    //         00449339     CMP        AX,BX
    //         0044933c     JLE        LAB_004493cc
    //                              effects.cpp:97 (31)
    //         00449342     MOVSX      this,AX
    //         00449345     PUSH       0xc
    //         00449347     PUSH       this
    //         00449348     CALL       calloc                                           undefined calloc()
    //         0044934d     MOV        this,dword ptr [ESP + index]
    //         00449351     ADD        ESP,0x8
    //         00449354     LEA        EDX,[ECX + ECX*0x4]
    //         00449357     LEA        this,[this->_padding_ + EDX*0x2]
    //         0044935a     MOV        EDX,dword ptr [EDI + 0x4]
    //         0044935d     MOV        dword ptr [EDX + this->_padding_*0x4 + 0x28],EAX
    //                              effects.cpp:98 (23)
    //         00449361     MOV        EAX,dword ptr [ESP + index]
    //         00449365     LEA        this,[EAX + EAX*0x4]
    //         00449368     LEA        EDX,[EAX + this->_padding_*0x2]
    //         0044936b     MOV        this,dword ptr [EDI + 0x4]
    //         0044936e     CMP        word ptr [this->_padding_ + EDX*0x4 + 0x24],BX
    //         00449373     LEA        this,[this->_padding_ + EDX*0x4]
    //         00449376     JLE        LAB_004493d3
    //                               LAB_00449378                                                 XREF[1]:     004493c8(j)  
    //                              effects.cpp:100 (12)
    //         00449378     MOVSX      EAX,BX
    //         0044937b     LEA        EDX,[EAX + EAX*0x2]
    //         0044937e     MOV        EAX,dword ptr [this->_padding_ + 0x28]
    //         00449381     LEA        ESI,[EAX + EDX*0x4]
    //                              effects.cpp:106 (40)
    //         00449384     LEA        this,[ESI + 0x8]
    //         00449387     LEA        EDX,[ESI + 0x6]
    //         0044938a     PUSH       this
    //         0044938b     LEA        EAX,[ESI + 0x4]
    //         0044938e     PUSH       EDX
    //         0044938f     LEA        this,[ESI + 0x2]
    //         00449392     PUSH       EAX
    //         00449393     LEA        EDX=>param_1,[ESP + 0x2c]
    //         00449397     PUSH       this
    //         00449398     PUSH       EDX
    //         00449399     PUSH       s_%hd_%hd_%hd_%hd_%f                             = "%hd %hd %hd %hd %f"
    //         0044939e     PUSH       EBP
    //         0044939f     CALL       fscanf                                           undefined fscanf()
    //         004493a4     ADD        ESP,0x1c
    //         004493a7     CMP        EAX,-0x1
    //         004493aa     JZ         LAB_004493cf
    //                              effects.cpp:108 (30)
    //         004493ac     MOV        AL,byte ptr [ESP + param_1]
    //         004493b0     INC        EBX
    //         004493b1     MOV        byte ptr [ESI],AL
    //         004493b3     MOV        EAX,dword ptr [ESP + index]
    //         004493b7     LEA        this,[EAX + EAX*0x4]
    //         004493ba     LEA        EDX,[EAX + this->_padding_*0x2]
    //         004493bd     MOV        this,dword ptr [EDI + 0x4]
    //         004493c0     CMP        BX,word ptr [this->_padding_ + EDX*0x4 + 0x24]
    //         004493c5     LEA        this,[this->_padding_ + EDX*0x4]
    //         004493c8     JL         LAB_00449378
    //                              effects.cpp:111 (2)
    //         004493ca     JMP        LAB_004493d3
    //                               LAB_004493cc                                                 XREF[1]:     0044933c(j)  
    //                              effects.cpp:112 (7)
    //         004493cc     MOV        dword ptr [this->_padding_ + 0x28],EBX
    //                               LAB_004493cf                                                 XREF[1]:     004493aa(j)  
    //         004493cf     MOV        EAX,dword ptr [ESP + index]
    //                               LAB_004493d3                                                 XREF[2]:     00449376(j), 004493ca(j)  
    //                              effects.cpp:114 (43)
    //         004493d3     MOV        this,dword ptr [EDI + 0x4]
    //         004493d6     LEA        EDX,[EAX + EAX*0x4]
    //         004493d9     LEA        EAX,[EAX + EDX*0x2]
    //         004493dc     LEA        EDX,[ECX + EAX*0x4 + this+0x2]
    //         004493e0     PUSH       EDX
    //         004493e1     CALL       convert_us                                       void convert_us(char * param_1)
    //         004493e6     MOV        EAX,dword ptr [ESP + count]
    //         004493ea     MOV        this,dword ptr [ESP + local_4]
    //         004493ee     ADD        ESP,0x4
    //         004493f1     INC        EAX
    //         004493f2     CMP        EAX,this
    //         004493f4     MOV        dword ptr [ESP + count],EAX
    //         004493f8     JL         LAB_004492cf
    //                              effects.cpp:122 (9)
    //         004493fe     PUSH       EBP
    //         004493ff     CALL       fclose                                           undefined fclose()
    //         00449404     ADD        ESP,0x4
    //                              effects.cpp:129 (12)
    //         00449407     MOV        EAX,EDI
    //         00449409     POP        ESI
    //         0044940a     POP        EDI
    //         0044940b     POP        EBP
    //         0044940c     POP        EBX
    //         0044940d     ADD        ESP,0xc
    //         00449410     RET        0x4
    //                               LAB_00449413                                                 XREF[1]:     004492a7(j)  
    //                              effects.cpp:119 (2)
    //         00449413     MOV        dword ptr [ESI],EBX
    //                              effects.cpp:120 (3)
    //         00449415     MOV        dword ptr [EDI + 0x4],EBX
    //                               LAB_00449418                                                 XREF[2]:     004492c7(j), 0044930d(j)  
    //                              effects.cpp:122 (9)
    //         00449418     PUSH       EBP
    //         00449419     CALL       fclose                                           undefined fclose()
    //         0044941e     ADD        ESP,0x4
    //                              effects.cpp:129 (12)
    //         00449421     MOV        EAX,EDI
    //         00449423     POP        ESI
    //         00449424     POP        EDI
    //         00449425     POP        EBP
    //         00449426     POP        EBX
    //         00449427     ADD        ESP,0xc
    //         0044942a     RET        0x4
    //                               LAB_0044942d                                                 XREF[1]:     00449286(j)  
    //                              effects.cpp:126 (3)
    //         0044942d     MOV        dword ptr [EDI + 0x8],EBX
    //                              effects.cpp:127 (3)
    //         00449430     MOV        dword ptr [EDI + 0x4],EBX
    //                              effects.cpp:129 (11)
    //         00449433     MOV        EAX,EDI
    //         00449435     POP        EDI
    //         00449436     POP        EBP
    //         00449437     POP        EBX
    //         00449438     ADD        ESP,0xc
    //         0044943b     RET        0x4
}

// Offset: 0x00449440
void RGE_Effects(RGE_Effects* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual __thiscall RGE_Effects::~RGE_Effects(void)                                            *
    //                              *********************************************************************************************************
    //                              void __thiscall ~RGE_Effects(RGE_Effects * this)
    //              void              <VOID>         <RETURN>
    //              RGE_Effects *     ECX:4 (auto)   this
    //                               ??1RGE_Effects@@UAE@XZ                                       XREF[2]:     `vector_deleting_destructor':00449
    //                               RGE_Effects::~RGE_Effects                                                 ~RGE_Effects:0050d49e(T), 
    //                                                                                                         ~TRIBE_Effects:0050d4a0(j)  
    //                              effects.cpp:134 (6)
    //         00449440     PUSH       EBX
    //         00449441     PUSH       EBP
    //         00449442     PUSH       ESI
    //         00449443     PUSH       EDI
    //         00449444     MOV        EDI,this
    //                              effects.cpp:137 (17)
    //         00449446     XOR        EBP,EBP
    //         00449448     XOR        EBX,EBX
    //         0044944a     MOV        EAX,dword ptr [EDI + 0x8]
    //         0044944d     MOV        dword ptr [EDI],RGE_Effects::`vftable'           = 00449240
    //         00449453     CMP        EAX,EBP
    //         00449455     JLE        LAB_00449488
    //                              effects.cpp:141 (2)
    //         00449457     XOR        EAX,EAX
    //                               LAB_00449459                                                 XREF[1]:     00449486(j)  
    //                              effects.cpp:139 (20)
    //         00449459     MOV        EDX,dword ptr [EDI + 0x4]
    //         0044945c     LEA        this,[EAX + EAX*0x4]
    //         0044945f     LEA        ESI,[EAX + this->_padding_*0x2]
    //         00449462     SHL        ESI,0x2
    //         00449465     MOV        EAX,dword ptr [EDX + ESI*0x1 + 0x28]
    //         00449469     CMP        EAX,EBP
    //         0044946b     JZ         LAB_00449476
    //                              effects.cpp:140 (9)
    //         0044946d     PUSH       EAX
    //         0044946e     CALL       free                                             undefined free()
    //         00449473     ADD        ESP,0x4
    //                               LAB_00449476                                                 XREF[1]:     0044946b(j)  
    //                              effects.cpp:141 (18)
    //         00449476     MOV        EAX,dword ptr [EDI + 0x4]
    //         00449479     INC        EBX
    //         0044947a     MOV        dword ptr [EAX + ESI*0x1 + 0x28],EBP
    //         0044947e     MOV        this,dword ptr [EDI + 0x8]
    //         00449481     MOVSX      EAX,BX
    //         00449484     CMP        EAX,this
    //         00449486     JL         LAB_00449459
    //                               LAB_00449488                                                 XREF[1]:     00449455(j)  
    //                              effects.cpp:143 (7)
    //         00449488     MOV        EAX,dword ptr [EDI + 0x4]
    //         0044948b     CMP        EAX,EBP
    //         0044948d     JZ         LAB_0044949b
    //                              effects.cpp:145 (9)
    //         0044948f     PUSH       EAX
    //         00449490     CALL       free                                             undefined free()
    //         00449495     ADD        ESP,0x4
    //                              effects.cpp:146 (3)
    //         00449498     MOV        dword ptr [EDI + 0x4],EBP
    //                               LAB_0044949b                                                 XREF[1]:     0044948d(j)  
    //                              effects.cpp:148 (3)
    //         0044949b     MOV        dword ptr [EDI + 0x8],EBP
    //                              effects.cpp:149 (5)
    //         0044949e     POP        EDI
    //         0044949f     POP        ESI
    //         004494a0     POP        EBP
    //         004494a1     POP        EBX
    //         004494a2     RET
}

// Offset: 0x004494B0
void RGE_Effects::save(int param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void __thiscall RGE_Effects::save(int)                                                *
    //                              *********************************************************************************************************
    //                              void __thiscall save(RGE_Effects * this, int param_1)
    //              void              <VOID>         <RETURN>
    //              RGE_Effects *     ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[6]:     004494b8(R), 004494e4(W), 004494fd(R), 00449520(R), 
    //                                                                                     00449595(R), 004495a5(W)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     004494c7(W), 0044958d(R)  
    //              undefined4        Stack[-0x8]:4  local_8                   XREF[2]:     0044950c(W), 0044957b(R)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[2]:     0044952a(W), 0044952e(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[2]:     004494c1(W), 004494ea(R)  
    //              undefined4        Stack[-0x14]:4 local_14                  XREF[3]:     004494d9(W), 00449591(R), 004495a1(W)  
    //              int               Stack[-0x18]:4 index
    //                               ?save@RGE_Effects@@UAEXH@Z
    //                               RGE_Effects::save
    //                              effects.cpp:154 (8)
    //         004494b0     SUB        ESP,0x14
    //         004494b3     PUSH       EBX
    //         004494b4     PUSH       ESI
    //         004494b5     MOV        ESI,this
    //         004494b7     PUSH       EDI
    //                              effects.cpp:160 (24)
    //         004494b8     MOV        EDI,dword ptr [ESP + param_1]
    //         004494bc     PUSH       0x4
    //         004494be     LEA        EBX,[ESI + 0x8]
    //         004494c1     MOV        dword ptr [ESP + local_10],ESI
    //         004494c5     PUSH       EBX
    //         004494c6     PUSH       EDI
    //         004494c7     MOV        dword ptr [ESP + local_4],EBX
    //         004494cb     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //                              effects.cpp:163 (26)
    //         004494d0     MOV        this,dword ptr [EBX]
    //         004494d2     XOR        EAX,EAX
    //         004494d4     ADD        ESP,0xc
    //         004494d7     CMP        this,EAX
    //         004494d9     MOV        dword ptr [ESP + local_14],EAX
    //         004494dd     JLE        LAB_004495b0
    //         004494e3     PUSH       EBP
    //         004494e4     MOV        dword ptr [ESP + param_1],EAX
    //         004494e8     JMP        LAB_004494ee
    //                               LAB_004494ea                                                 XREF[1]:     004495a9(j)  
    //                              effects.cpp:160 (4)
    //         004494ea     MOV        ESI,dword ptr [ESP + local_10]
    //                               LAB_004494ee                                                 XREF[1]:     004494e8(j)  
    //                              effects.cpp:165 (3)
    //         004494ee     MOV        ESI,dword ptr [ESI + 0x4]
    //                              effects.cpp:166 (12)
    //         004494f1     PUSH       0x1f
    //         004494f3     LEA        EAX,[ESI + 0x2]
    //         004494f6     PUSH       EAX
    //         004494f7     PUSH       EDI
    //         004494f8     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //                              effects.cpp:167 (24)
    //         004494fd     MOV        this,dword ptr [ESP + param_1]
    //         00449501     ADD        ESP,0xc
    //         00449504     LEA        EBP,[this->_padding_ + ESI*0x1 + 0x24]
    //         00449508     PUSH       0x2
    //         0044950a     PUSH       EBP
    //         0044950b     PUSH       EDI
    //         0044950c     MOV        dword ptr [ESP + local_8],EBP
    //         00449510     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //                              effects.cpp:170 (11)
    //         00449515     XOR        EBX,EBX
    //         00449517     ADD        ESP,0xc
    //         0044951a     CMP        word ptr [EBP],BX
    //         0044951e     JLE        LAB_0044958d
    //                              effects.cpp:172 (18)
    //         00449520     MOV        EDX,dword ptr [ESP + param_1]
    //         00449524     XOR        EBP,EBP
    //         00449526     LEA        EAX,[EDX + ESI*0x1 + 0x28]
    //         0044952a     MOV        dword ptr [ESP + local_c],EAX
    //                               LAB_0044952e                                                 XREF[1]:     0044958b(j)  
    //         0044952e     MOV        this,dword ptr [ESP + local_c]
    //                              effects.cpp:173 (16)
    //         00449532     PUSH       0x1
    //         00449534     MOV        ESI,dword ptr [this->_padding_]
    //         00449536     ADD        ESI,EBP
    //         00449538     PUSH       ESI
    //         00449539     PUSH       EDI
    //         0044953a     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         0044953f     ADD        ESP,0xc
    //                              effects.cpp:174 (15)
    //         00449542     LEA        EDX,[ESI + 0x2]
    //         00449545     PUSH       0x2
    //         00449547     PUSH       EDX
    //         00449548     PUSH       EDI
    //         00449549     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         0044954e     ADD        ESP,0xc
    //                              effects.cpp:175 (15)
    //         00449551     LEA        EAX,[ESI + 0x4]
    //         00449554     PUSH       0x2
    //         00449556     PUSH       EAX
    //         00449557     PUSH       EDI
    //         00449558     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         0044955d     ADD        ESP,0xc
    //                              effects.cpp:176 (15)
    //         00449560     LEA        this,[ESI + 0x6]
    //         00449563     PUSH       0x2
    //         00449565     PUSH       this
    //         00449566     PUSH       EDI
    //         00449567     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         0044956c     ADD        ESP,0xc
    //                              effects.cpp:177 (30)
    //         0044956f     ADD        ESI,0x8
    //         00449572     PUSH       0x4
    //         00449574     PUSH       ESI
    //         00449575     PUSH       EDI
    //         00449576     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         0044957b     MOV        EDX,dword ptr [ESP + local_8]
    //         0044957f     ADD        ESP,0xc
    //         00449582     INC        EBX
    //         00449583     ADD        EBP,0xc
    //         00449586     MOVSX      EAX,word ptr [EDX]
    //         00449589     CMP        EBX,EAX
    //         0044958b     JL         LAB_0044952e
    //                               LAB_0044958d                                                 XREF[1]:     0044951e(j)  
    //                              effects.cpp:163 (34)
    //         0044958d     MOV        this,dword ptr [ESP + local_4]
    //         00449591     MOV        EAX,dword ptr [ESP + local_14]
    //         00449595     MOV        ESI,dword ptr [ESP + param_1]
    //         00449599     INC        EAX
    //         0044959a     MOV        EDX,dword ptr [this->_padding_]
    //         0044959c     ADD        ESI,0x2c
    //         0044959f     CMP        EAX,EDX
    //         004495a1     MOV        dword ptr [ESP + local_14],EAX
    //         004495a5     MOV        dword ptr [ESP + param_1],ESI
    //         004495a9     JL         LAB_004494ea
    //                              effects.cpp:154 (1)
    //         004495af     POP        EBP
    //                               LAB_004495b0                                                 XREF[1]:     004494dd(j)  
    //                              effects.cpp:180 (9)
    //         004495b0     POP        EDI
    //         004495b1     POP        ESI
    //         004495b2     POP        EBX
    //         004495b3     ADD        ESP,0x14
    //         004495b6     RET        0x4
}

// Offset: 0x004495C0
void RGE_Effects::do_effect(short param_1, RGE_Player* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void __thiscall RGE_Effects::do_effect(short,class RGE_Player *)                      *
    //                              *********************************************************************************************************
    //                              void __thiscall do_effect(RGE_Effects * this, short param_1, RGE_Pla
    //              void              <VOID>         <RETURN>
    //              RGE_Effects *     ECX:4 (auto)   this
    //              short             Stack[0x4]:2   param_1                   XREF[3]:     004495c0(R), 0044968a(W), 004496a2(R)  
    //              RGE_Player *      Stack[0x8]:4   param_2                   XREF[1]:     004495f3(R)  
    //              undefined4        Stack[-0x14]:4 local_14                  XREF[3]:     00449629(*), 0044964b(*), 0044966d(*)  
    //                               ?do_effect@RGE_Effects@@UAEXFPAVRGE_Player@@@Z               XREF[1]:     do_effect:0050d53d(c)  
    //                               RGE_Effects::do_effect
    //                              effects.cpp:186 (18)
    //         004495c0     MOVSX      EAX,word ptr [ESP + param_1]
    //         004495c5     MOV        EDX,dword ptr [ECX + this->effect_num]
    //         004495c8     PUSH       EBX
    //         004495c9     CMP        EAX,EDX
    //         004495cb     PUSH       EDI
    //         004495cc     JGE        LAB_004496e8
    //                              effects.cpp:201 (12)
    //         004495d2     MOV        this,dword ptr [ECX + this->effects]
    //         004495d5     LEA        EDX,[EAX + EAX*0x4]
    //         004495d8     LEA        EAX,[EAX + EDX*0x2]
    //         004495db     LEA        EBX,[this->_padding_ + EAX*0x4]
    //                              effects.cpp:203 (8)
    //         004495de     TEST       EBX,EBX
    //         004495e0     JZ         LAB_004496e8
    //                              effects.cpp:206 (13)
    //         004495e6     XOR        EDI,EDI
    //         004495e8     CMP        word ptr [EBX + 0x24],DI
    //         004495ec     JLE        LAB_004496e8
    //         004495f2     PUSH       ESI
    //                              effects.cpp:208 (7)
    //         004495f3     MOV        ESI,dword ptr [ESP + param_2]
    //                               LAB_004495f7                                                 XREF[1]:     004496e1(j)  
    //         004495f7     MOVSX      EAX,DI
    //                              effects.cpp:209 (30)
    //         004495fa     XOR        this,this
    //         004495fc     LEA        EDX,[EAX + EAX*0x2]
    //         004495ff     MOV        EAX,dword ptr [EBX + 0x28]
    //         00449602     MOV        this,byte ptr [EAX + EDX*0x4]
    //         00449605     LEA        EAX,[EAX + EDX*0x4]
    //         00449608     CMP        this,0x5
    //         0044960b     JA         switchD_00449611::default
    //                               switchD_00449611::switchD
    //         00449611     JMP        dword ptr [this->_padding_*0x4 + switchD_00449   = 0044965c
    //                               switchD_00449611::caseD_4                                    XREF[2]:     00449611(j), 00449700(*)  
    //                              effects.cpp:216 (4)
    //         00449618     MOV        this,word ptr [EAX + 0x6]
    //                              effects.cpp:218 (25)
    //         0044961c     MOV        DX,word ptr [EAX + 0x2]
    //         00449620     FLD        float ptr [EAX + 0x8]
    //         00449623     PUSH       this
    //         00449624     PUSH       this
    //         00449625     MOV        this,word ptr [EAX + 0x4]
    //         00449629     FSTP       float ptr [ESP]=>local_14
    //         0044962c     PUSH       this
    //         0044962d     PUSH       EDX
    //         0044962e     MOV        this,ESI
    //         00449630     CALL       RGE_Player::modify_tobj_delta                    void modify_tobj_delta(RGE_Player * this, sho
    //                              effects.cpp:219 (5)
    //         00449635     JMP        switchD_00449611::default
    //                               switchD_00449611::caseD_5                                    XREF[2]:     00449611(j), 00449704(*)  
    //                              effects.cpp:226 (4)
    //         0044963a     MOV        this,word ptr [EAX + 0x6]
    //                              effects.cpp:228 (25)
    //         0044963e     MOV        DX,word ptr [EAX + 0x2]
    //         00449642     FLD        float ptr [EAX + 0x8]
    //         00449645     PUSH       this
    //         00449646     PUSH       this
    //         00449647     MOV        this,word ptr [EAX + 0x4]
    //         0044964b     FSTP       float ptr [ESP]=>local_14
    //         0044964e     PUSH       this
    //         0044964f     PUSH       EDX
    //         00449650     MOV        this,ESI
    //         00449652     CALL       RGE_Player::modify_tobj_percent                  void modify_tobj_percent(RGE_Player * this, s
    //                              effects.cpp:229 (5)
    //         00449657     JMP        switchD_00449611::default
    //                               switchD_00449611::caseD_0                                    XREF[2]:     00449611(j), 004496f0(*)  
    //                              effects.cpp:236 (4)
    //         0044965c     MOV        this,word ptr [EAX + 0x6]
    //                              effects.cpp:238 (25)
    //         00449660     MOV        DX,word ptr [EAX + 0x2]
    //         00449664     FLD        float ptr [EAX + 0x8]
    //         00449667     PUSH       this
    //         00449668     PUSH       this
    //         00449669     MOV        this,word ptr [EAX + 0x4]
    //         0044966d     FSTP       float ptr [ESP]=>local_14
    //         00449670     PUSH       this
    //         00449671     PUSH       EDX
    //         00449672     MOV        this,ESI
    //         00449674     CALL       RGE_Player::modify_tobj                          void modify_tobj(RGE_Player * this, short par
    //                              effects.cpp:239 (2)
    //         00449679     JMP        switchD_00449611::default
    //                               switchD_00449611::caseD_1                                    XREF[2]:     00449611(j), 004496f4(*)  
    //                              effects.cpp:243 (4)
    //         0044967b     MOV        this,word ptr [EAX + 0x2]
    //                              effects.cpp:244 (4)
    //         0044967f     MOV        DX,word ptr [EAX + 0x4]
    //                              effects.cpp:245 (3)
    //         00449683     MOV        EAX,dword ptr [EAX + 0x8]
    //                              effects.cpp:247 (10)
    //         00449686     CMP        this,-0x1
    //         0044968a     MOV        dword ptr [ESP + param_1],EAX
    //         0044968e     JLE        switchD_00449611::default
    //                              effects.cpp:249 (5)
    //         00449690     TEST       DX,DX
    //         00449693     JNZ        LAB_004496a2
    //                              effects.cpp:250 (11)
    //         00449695     MOV        EDX,EAX
    //         00449697     PUSH       EDX
    //         00449698     PUSH       this
    //         00449699     MOV        this,ESI
    //         0044969b     CALL       RGE_Player::new_attribute_num                    void new_attribute_num(RGE_Player * this, sho
    //                              effects.cpp:251 (2)
    //         004496a0     JMP        switchD_00449611::default
    //                               LAB_004496a2                                                 XREF[1]:     00449693(j)  
    //                              effects.cpp:252 (15)
    //         004496a2     MOV        EDX,dword ptr [ESP + param_1]
    //         004496a6     MOV        EAX,dword ptr [ESI]
    //         004496a8     PUSH       0x0
    //         004496aa     PUSH       EDX
    //         004496ab     PUSH       this
    //         004496ac     MOV        this,ESI
    //         004496ae     CALL       dword ptr [EAX + 0x78]
    //                              effects.cpp:254 (2)
    //         004496b1     JMP        switchD_00449611::default
    //                               switchD_00449611::caseD_2                                    XREF[2]:     00449611(j), 004496f8(*)  
    //                              effects.cpp:258 (4)
    //         004496b3     MOV        this,word ptr [EAX + 0x2]
    //                              effects.cpp:260 (6)
    //         004496b7     CMP        this,-0x1
    //         004496bb     JLE        switchD_00449611::default
    //                              effects.cpp:261 (12)
    //         004496bd     MOV        AL,byte ptr [EAX + 0x4]
    //         004496c0     PUSH       EAX
    //         004496c1     PUSH       this
    //         004496c2     MOV        this,ESI
    //         004496c4     CALL       RGE_Player::make_available                       void make_available(RGE_Player * this, short 
    //                              effects.cpp:263 (2)
    //         004496c9     JMP        switchD_00449611::default
    //                               switchD_00449611::caseD_3                                    XREF[2]:     00449611(j), 004496fc(*)  
    //                              effects.cpp:270 (28)
    //         004496cb     MOV        this,word ptr [EAX + 0x4]
    //         004496cf     MOV        DX,word ptr [EAX + 0x2]
    //         004496d3     PUSH       this
    //         004496d4     PUSH       EDX
    //         004496d5     MOV        this,ESI
    //         004496d7     CALL       RGE_Player::copy_obj                             void copy_obj(RGE_Player * this, short param_
    //                               switchD_00449611::default                                    XREF[9]:     0044960b(j), 00449635(j), 
    //                                                                                                         00449657(j), 00449679(j), 
    //                                                                                                         0044968e(j), 004496a0(j), 
    //                                                                                                         004496b1(j), 004496bb(j), 
    //                                                                                                         004496c9(j)  
    //         004496dc     INC        EDI
    //         004496dd     CMP        DI,word ptr [EBX + 0x24]
    //         004496e1     JL         LAB_004495f7
    //                              effects.cpp:186 (1)
    //         004496e7     POP        ESI
    //                               LAB_004496e8                                                 XREF[3]:     004495cc(j), 004495e0(j), 
    //                                                                                                         004495ec(j)  
    //                              effects.cpp:274 (32)
    //         004496e8     POP        EDI
    //         004496e9     POP        EBX
    //         004496ea     RET        0x8
}

// Offset: 0x004496ED
undefined FUN_004496ed() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_004496ed()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_004496ed
    //         004496ed     NOP
    //         004496ee     MOV        EDI,EDI
    //                              Symbol Ref: No symbol: NONAME
    //                               switchD_00449611::switchdataD_004496f0                       XREF[1]:     do_effect:00449611(*)  
}

