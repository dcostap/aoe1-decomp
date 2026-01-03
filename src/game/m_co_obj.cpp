#include "../common.h"
#include "m_co_obj.h"

RGE_Master_Combat_Object::RGE_Master_Combat_Object(RGE_Master_Combat_Object* param_1, int param_2) {
    /* TODO: Stub */
//                              undefined __thiscall RGE_Master_Combat_Object(RGE_Master_Combat_Obje
//              undefined         <UNASSIGNED>   <RETURN>
//              RGE_Master_Com    ECX:4 (auto)   this
//              RGE_Master_Com    Stack[0x4]:4   param_1                   XREF[1]:     0044fe58(R)
//              int               Stack[0x8]:4   param_2                   XREF[1]:     0044fe6a(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     0044fe6e(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     0044fe88(R)
//              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     0044fe61(W)
//                               ??0RGE_Master_Combat_Object@@QAE@PAV0@H@Z                    XREF[3]:     make_new_master:004507db(c),
//                               RGE_Master_Combat_Object::RGE_Master_Combat_Object                        RGE_Master_Missile_Object:00451465
//                                                                                                         TRIBE_Master_Combat_Object:0050e99
//                              m_co_obj.cpp:27 (42)
//         0044fe40     PUSH       -0x1
//         0044fe42     PUSH       FUN_0055d7b8
//         0044fe47     MOV        EAX,FS:[0x0]
//         0044fe4d     PUSH       EAX
//         0044fe4e     MOV        dword ptr FS:[0x0],ESP
//         0044fe55     PUSH       this
//         0044fe56     PUSH       ESI
//         0044fe57     PUSH       EDI
//         0044fe58     MOV        EDI,dword ptr [ESP + param_1]
//         0044fe5c     MOV        ESI,this
//         0044fe5e     PUSH       0x0
//         0044fe60     PUSH       EDI
//         0044fe61     MOV        dword ptr [ESP + local_10],ESI
//         0044fe65     CALL       RGE_Master_Action_Object::RGE_Master_Action_Ob   undefined RGE_Master_Action_Object(RGE_Master
//                              m_co_obj.cpp:28 (22)
//         0044fe6a     MOV        EAX,dword ptr [ESP + param_2]
//         0044fe6e     MOV        dword ptr [ESP + local_4],0x0
//         0044fe76     TEST       EAX,EAX
//         0044fe78     MOV        dword ptr [ESI],RGE_Master_Combat_Object::`vft   = 0044fea0
//         0044fe7e     JZ         LAB_0044fe88
//                              m_co_obj.cpp:29 (8)
//         0044fe80     PUSH       EDI
//         0044fe81     MOV        this,ESI
//         0044fe83     CALL       RGE_Master_Combat_Object::setup                  int setup(RGE_Master_Combat_Object * this, RG
//                               LAB_0044fe88                                                 XREF[1]:     0044fe7e(j)
//                              m_co_obj.cpp:30 (21)
//         0044fe88     MOV        this,dword ptr [ESP + local_c]
//         0044fe8c     MOV        EAX,ESI
//         0044fe8e     POP        EDI
//         0044fe8f     MOV        dword ptr FS:[0x0],this
//         0044fe96     POP        ESI
//         0044fe97     ADD        ESP,0x10
//         0044fe9a     RET        0x8
//         0044fe9d     ??         90h
//         0044fe9e     NOP
//         0044fe9f     NOP
}

RGE_Master_Combat_Object::RGE_Master_Combat_Object(int param_1, RGE_Sprite** param_2, RGE_Sound** param_3, int param_4) {
    /* TODO: Stub */
//                              undefined __thiscall RGE_Master_Combat_Object(RGE_Master_Combat_Obje
//              undefined         <UNASSIGNED>   <RETURN>
//              RGE_Master_Com    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     0044fedc(R)
//              RGE_Sprite * *    Stack[0x8]:4   param_2                   XREF[1]:     0044fed7(R)
//              RGE_Sound * *     Stack[0xc]:4   param_3                   XREF[1]:     0044fee2(R)
//              int               Stack[0x10]:4  param_4                   XREF[1]:     0044fef6(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     0044fefa(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     0044ff16(R)
//              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     0044feed(W)
//                               ??0RGE_Master_Combat_Object@@QAE@HPAPAVRGE_Sprite@@PAPAVRGE  XREF[4]:     RGE_Master_Missile_Object:004514f1
//                               RGE_Master_Combat_Object::RGE_Master_Combat_Object                        load_master_object:00461442(c),
//                                                                                                         load_master_object:0046fe12(c),
//                                                                                                         TRIBE_Master_Combat_Object:0050ea2
//                              m_co_obj.cpp:36 (54)
//         0044fec0     PUSH       -0x1
//         0044fec2     PUSH       FUN_0055d7d8
//         0044fec7     MOV        EAX,FS:[0x0]
//         0044fecd     PUSH       EAX
//         0044fece     MOV        dword ptr FS:[0x0],ESP
//         0044fed5     PUSH       this
//         0044fed6     PUSH       EBX
//         0044fed7     MOV        EBX,dword ptr [ESP + param_2]
//         0044fedb     PUSH       EBP
//         0044fedc     MOV        EBP,dword ptr [ESP + param_1]
//         0044fee0     PUSH       ESI
//         0044fee1     PUSH       EDI
//         0044fee2     MOV        EDI,dword ptr [ESP + param_3]
//         0044fee6     PUSH       0x0
//         0044fee8     PUSH       EDI
//         0044fee9     MOV        ESI,this
//         0044feeb     PUSH       EBX
//         0044feec     PUSH       EBP
//         0044feed     MOV        dword ptr [ESP + local_10],ESI
//         0044fef1     CALL       RGE_Master_Action_Object::RGE_Master_Action_Ob   undefined RGE_Master_Action_Object(RGE_Master
//                              m_co_obj.cpp:37 (22)
//         0044fef6     MOV        EAX,dword ptr [ESP + param_4]
//         0044fefa     MOV        dword ptr [ESP + local_4],0x0
//         0044ff02     TEST       EAX,EAX
//         0044ff04     MOV        dword ptr [ESI],RGE_Master_Combat_Object::`vft   = 0044fea0
//         0044ff0a     JZ         LAB_0044ff16
//                              m_co_obj.cpp:38 (10)
//         0044ff0c     PUSH       EDI
//         0044ff0d     PUSH       EBX
//         0044ff0e     PUSH       EBP
//         0044ff0f     MOV        this,ESI
//         0044ff11     CALL       RGE_Master_Combat_Object::setup                  int setup(RGE_Master_Combat_Object * this, in
//                               LAB_0044ff16                                                 XREF[1]:     0044ff0a(j)
//                              m_co_obj.cpp:39 (23)
//         0044ff16     MOV        this,dword ptr [ESP + local_c]
//         0044ff1a     MOV        EAX,ESI
//         0044ff1c     POP        EDI
//         0044ff1d     POP        ESI
//         0044ff1e     POP        EBP
//         0044ff1f     MOV        dword ptr FS:[0x0],this
//         0044ff26     POP        EBX
//         0044ff27     ADD        ESP,0x10
//         0044ff2a     RET        0x10
//         0044ff2d     ??         90h
//         0044ff2e     NOP
//         0044ff2f     NOP
}

RGE_Master_Combat_Object::RGE_Master_Combat_Object(_iobuf* param_1, RGE_Sprite** param_2, RGE_Sound** param_3, short param_4, int param_5) {
    /* TODO: Stub */
//                              undefined __thiscall RGE_Master_Combat_Object(RGE_Master_Combat_Obje
//              undefined         <UNASSIGNED>   <RETURN>
//              RGE_Master_Com    ECX:4 (auto)   this
//              _iobuf *          Stack[0x4]:4   param_1                   XREF[2]:     0044ff46(R), 0044ff81(R)
//              RGE_Sprite * *    Stack[0x8]:4   param_2                   XREF[1]:     0044ff50(R)
//              RGE_Sound * *     Stack[0xc]:4   param_3                   XREF[1]:     0044ff4b(R)
//              short             Stack[0x10]:2  param_4                   XREF[1]:     0044ff56(R)
//              int               Stack[0x14]:4  param_5                   XREF[1]:     0044ff6b(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     0044ff6f(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     0044ff90(R)
//              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     0044ff62(W)
//                               ??0RGE_Master_Combat_Object@@QAE@PAU_iobuf@@PAPAVRGE_Sprite  XREF[3]:     RGE_Master_Missile_Object:00451566
//                               RGE_Master_Combat_Object::RGE_Master_Combat_Object                        load_object:0046174f(c),
//                                                                                                         TRIBE_Master_Combat_Object:0050ea9
//                              m_co_obj.cpp:45 (59)
//         0044ff30     PUSH       -0x1
//         0044ff32     PUSH       FUN_0055d7f8
//         0044ff37     MOV        EAX,FS:[0x0]
//         0044ff3d     PUSH       EAX
//         0044ff3e     MOV        dword ptr FS:[0x0],ESP
//         0044ff45     PUSH       this
//         0044ff46     MOV        EAX,dword ptr [ESP + param_1]
//         0044ff4a     PUSH       EBX
//         0044ff4b     MOV        EBX,dword ptr [ESP + param_3]
//         0044ff4f     PUSH       EBP
//         0044ff50     MOV        EBP,dword ptr [ESP + param_2]
//         0044ff54     PUSH       ESI
//         0044ff55     PUSH       EDI
//         0044ff56     MOV        EDI,dword ptr [ESP + param_4]
//         0044ff5a     PUSH       0x0
//         0044ff5c     PUSH       EDI
//         0044ff5d     PUSH       EBX
//         0044ff5e     MOV        ESI,this
//         0044ff60     PUSH       EBP
//         0044ff61     PUSH       EAX
//         0044ff62     MOV        dword ptr [ESP + local_10],ESI
//         0044ff66     CALL       RGE_Master_Action_Object::RGE_Master_Action_Ob   undefined RGE_Master_Action_Object(RGE_Master
//                              m_co_obj.cpp:46 (22)
//         0044ff6b     MOV        EAX,dword ptr [ESP + param_5]
//         0044ff6f     MOV        dword ptr [ESP + local_4],0x0
//         0044ff77     TEST       EAX,EAX
//         0044ff79     MOV        dword ptr [ESI],RGE_Master_Combat_Object::`vft   = 0044fea0
//         0044ff7f     JZ         LAB_0044ff90
//                              m_co_obj.cpp:47 (15)
//         0044ff81     MOV        this,dword ptr [ESP + param_1]
//         0044ff85     PUSH       EDI
//         0044ff86     PUSH       EBX
//         0044ff87     PUSH       EBP
//         0044ff88     PUSH       this
//         0044ff89     MOV        this,ESI
//         0044ff8b     CALL       RGE_Master_Combat_Object::setup                  int setup(RGE_Master_Combat_Object * this, _i
//                               LAB_0044ff90                                                 XREF[1]:     0044ff7f(j)
//                              m_co_obj.cpp:48 (23)
//         0044ff90     MOV        this,dword ptr [ESP + local_c]
//         0044ff94     MOV        EAX,ESI
//         0044ff96     POP        EDI
//         0044ff97     POP        ESI
//         0044ff98     POP        EBP
//         0044ff99     MOV        dword ptr FS:[0x0],this
//         0044ffa0     POP        EBX
//         0044ffa1     ADD        ESP,0x10
//         0044ffa4     RET        0x14
//         0044ffa7     ??         90h
//         0044ffa8     NOP
//         0044ffa9     NOP
//         0044ffaa     NOP
//         0044ffab     NOP
//         0044ffac     NOP
//         0044ffad     NOP
//         0044ffae     NOP
//         0044ffaf     NOP
}

int RGE_Master_Combat_Object::setup(RGE_Master_Combat_Object* param_1) {
    /* TODO: Stub */
//                              int __thiscall setup(RGE_Master_Combat_Object * this, RGE_Master_Com
//              int               EAX:4          <RETURN>
//              RGE_Master_Com    ECX:4 (auto)   this
//              RGE_Master_Com    Stack[0x4]:4   param_1                   XREF[1]:     0044ffb2(R)
//                               ?setup@RGE_Master_Combat_Object@@IAEHPAV1@@Z                 XREF[3]:     RGE_Master_Combat_Object:0044fe83(
//                               RGE_Master_Combat_Object::setup                                           setup:004515b9(c),
//                                                                                                         setup:0050eaeb(c)
//                              m_co_obj.cpp:53 (2)
//         0044ffb0     PUSH       EBX
//         0044ffb1     PUSH       EBP
//                              m_co_obj.cpp:54 (14)
//         0044ffb2     MOV        EBP,dword ptr [ESP + param_1]
//         0044ffb6     PUSH       ESI
//         0044ffb7     PUSH       EDI
//         0044ffb8     MOV        EBX,this
//         0044ffba     PUSH       EBP
//         0044ffbb     CALL       RGE_Master_Action_Object::setup                  int setup(RGE_Master_Action_Object * this, RG
//                              m_co_obj.cpp:56 (4)
//         0044ffc0     MOV        byte ptr [EBX + 0x4],0x32
//                              m_co_obj.cpp:59 (12)
//         0044ffc4     MOV        EAX,dword ptr [EBP + 0xfc]
//         0044ffca     MOV        dword ptr [EBX + 0xfc],EAX
//                              m_co_obj.cpp:60 (12)
//         0044ffd0     MOV        this,byte ptr [EBP + 0x100]
//         0044ffd6     MOV        byte ptr [EBX + 0x100],this
//                              m_co_obj.cpp:62 (7)
//         0044ffdc     MOV        AX,word ptr [EBP + 0x108]
//                              m_co_obj.cpp:63 (12)
//         0044ffe3     TEST       AX,AX
//         0044ffe6     MOV        word ptr [EBX + 0x108],AX
//         0044ffed     JLE        LAB_00450025
//                              m_co_obj.cpp:65 (11)
//         0044ffef     MOVSX      EDX,AX
//         0044fff2     PUSH       0x4
//         0044fff4     PUSH       EDX
//         0044fff5     CALL       calloc                                           undefined calloc()
//                              m_co_obj.cpp:66 (41)
//         0044fffa     MOVSX      this,word ptr [EBX + 0x108]
//         00450001     SHL        this,0x2
//         00450004     MOV        dword ptr [EBX + 0x10c],EAX
//         0045000a     MOV        ESI,dword ptr [EBP + 0x10c]
//         00450010     MOV        EDI,EAX
//         00450012     MOV        EAX,this
//         00450014     SHR        this,0x2
//         00450017     MOVSD.REP  ES:EDI,ESI
//         00450019     MOV        this,EAX
//         0045001b     ADD        ESP,0x8
//         0045001e     AND        this,0x3
//         00450021     MOVSB.REP  ES:EDI,ESI
//                              m_co_obj.cpp:68 (2)
//         00450023     JMP        LAB_0045002f
//                               LAB_00450025                                                 XREF[1]:     0044ffed(j)
//                              m_co_obj.cpp:69 (10)
//         00450025     MOV        dword ptr [EBX + 0x10c],0x0
//                               LAB_0045002f                                                 XREF[1]:     00450023(j)
//                              m_co_obj.cpp:71 (7)
//         0045002f     MOV        AX,word ptr [EBP + 0x102]
//                              m_co_obj.cpp:72 (12)
//         00450036     TEST       AX,AX
//         00450039     MOV        word ptr [EBX + 0x102],AX
//         00450040     JLE        LAB_00450078
//                              m_co_obj.cpp:74 (11)
//         00450042     MOVSX      this,AX
//         00450045     PUSH       0x4
//         00450047     PUSH       this
//         00450048     CALL       calloc                                           undefined calloc()
//                              m_co_obj.cpp:75 (41)
//         0045004d     MOVSX      this,word ptr [EBX + 0x102]
//         00450054     SHL        this,0x2
//         00450057     MOV        EDX,this
//         00450059     MOV        dword ptr [EBX + 0x104],EAX
//         0045005f     MOV        ESI,dword ptr [EBP + 0x104]
//         00450065     MOV        EDI,EAX
//         00450067     SHR        this,0x2
//         0045006a     MOVSD.REP  ES:EDI,ESI
//         0045006c     MOV        this,EDX
//         0045006e     ADD        ESP,0x8
//         00450071     AND        this,0x3
//         00450074     MOVSB.REP  ES:EDI,ESI
//                              m_co_obj.cpp:77 (2)
//         00450076     JMP        LAB_00450082
//                               LAB_00450078                                                 XREF[1]:     00450040(j)
//                              m_co_obj.cpp:78 (10)
//         00450078     MOV        dword ptr [EBX + 0x104],0x0
//                               LAB_00450082                                                 XREF[1]:     00450076(j)
//                              m_co_obj.cpp:80 (7)
//         00450082     MOV        AX,word ptr [EBP + 0x110]
//                              m_co_obj.cpp:99 (221)
//         00450089     POP        EDI
//         0045008a     MOV        word ptr [EBX + 0x110],AX
//         00450091     MOV        this,dword ptr [EBP + 0x114]
//         00450097     MOV        dword ptr [EBX + 0x114],this
//         0045009d     MOV        EDX,dword ptr [EBP + 0x118]
//         004500a3     MOV        dword ptr [EBX + 0x118],EDX
//         004500a9     MOV        EAX,dword ptr [EBP + 0x120]
//         004500af     MOV        dword ptr [EBX + 0x120],EAX
//         004500b5     MOV        this,word ptr [EBP + 0x124]
//         004500bc     MOV        word ptr [EBX + 0x124],this
//         004500c3     MOV        DX,word ptr [EBP + 0x126]
//         004500ca     MOV        word ptr [EBX + 0x126],DX
//         004500d1     MOV        AL,byte ptr [EBP + 0x128]
//         004500d7     MOV        byte ptr [EBX + 0x128],AL
//         004500dd     MOV        this,word ptr [EBP + 0x12a]
//         004500e4     MOV        word ptr [EBX + 0x12a],this
//         004500eb     MOV        EDX,dword ptr [EBP + 0x12c]
//         004500f1     MOV        dword ptr [EBX + 0x12c],EDX
//         004500f7     MOV        EAX,dword ptr [EBP + 0x130]
//         004500fd     MOV        dword ptr [EBX + 0x130],EAX
//         00450103     MOV        this,dword ptr [EBP + 0x134]
//         00450109     MOV        dword ptr [EBX + 0x134],this
//         0045010f     MOV        DL,byte ptr [EBP + 0x11c]
//         00450115     MOV        byte ptr [EBX + 0x11c],DL
//         0045011b     MOV        EAX,dword ptr [EBP + 0x138]
//         00450121     MOV        dword ptr [EBX + 0x138],EAX
//         00450127     MOV        this,word ptr [EBP + 0x13c]
//         0045012e     MOV        word ptr [EBX + 0x13c],this
//         00450135     MOV        DX,word ptr [EBP + 0x13e]
//         0045013c     MOV        word ptr [EBX + 0x13e],DX
//         00450143     MOV        EAX,dword ptr [EBP + 0x140]
//         00450149     MOV        dword ptr [EBX + 0x140],EAX
//         0045014f     MOV        this,dword ptr [EBP + 0x144]
//         00450155     POP        ESI
//         00450156     MOV        dword ptr [EBX + 0x144],this
//         0045015c     POP        EBP
//         0045015d     MOV        EAX,0x1
//         00450162     POP        EBX
//         00450163     RET        0x4
//         00450166     ??         90h
//         00450167     NOP
//         00450168     NOP
//         00450169     NOP
//         0045016a     NOP
//         0045016b     NOP
//         0045016c     NOP
//         0045016d     NOP
//         0045016e     NOP
//         0045016f     NOP
    return 0;
}

int RGE_Master_Combat_Object::setup(int param_1, RGE_Sprite** param_2, RGE_Sound** param_3) {
    /* TODO: Stub */
//                              int __thiscall setup(RGE_Master_Combat_Object * this, int param_1, R
//              int               EAX:4          <RETURN>
//              RGE_Master_Com    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     0045017e(R)
//              RGE_Sprite * *    Stack[0x8]:4   param_2                   XREF[2]:     0045017a(R), 0045033f(R)
//              RGE_Sound * *     Stack[0xc]:4   param_3                   XREF[3]:     00450170(R), 00450322(*), 0045032f(R)
//                               ?setup@RGE_Master_Combat_Object@@IAEHHPAPAVRGE_Sprite@@PAPA  XREF[3]:     RGE_Master_Combat_Object:0044ff11(
//                               RGE_Master_Combat_Object::setup                                           setup:00451635(c),
//                                                                                                         setup:0050eb77(c)
//                              m_co_obj.cpp:104 (28)
//         00450170     MOV        EAX,dword ptr [ESP + param_3]
//         00450174     PUSH       EBX
//         00450175     PUSH       EBP
//         00450176     PUSH       ESI
//         00450177     MOV        ESI,this
//         00450179     PUSH       EDI
//         0045017a     MOV        this,dword ptr [ESP + param_2]
//         0045017e     MOV        EDI,dword ptr [ESP + param_1]
//         00450182     PUSH       EAX
//         00450183     PUSH       this
//         00450184     PUSH       EDI
//         00450185     MOV        this,ESI
//         00450187     CALL       RGE_Master_Action_Object::setup                  int setup(RGE_Master_Action_Object * this, in
//                              m_co_obj.cpp:113 (22)
//         0045018c     LEA        EBP,[ESI + 0x100]
//         00450192     PUSH       0x1
//         00450194     PUSH       EBP
//         00450195     PUSH       EDI
//         00450196     MOV        byte ptr [ESI + 0x4],0x32
//         0045019a     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         0045019f     ADD        ESP,0xc
//                              m_co_obj.cpp:114 (15)
//         004501a2     LEA        EBX,[ESI + 0x108]
//         004501a8     PUSH       0x2
//         004501aa     PUSH       EBX
//         004501ab     PUSH       EDI
//         004501ac     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//                              m_co_obj.cpp:115 (11)
//         004501b1     MOV        AX,word ptr [EBX]
//         004501b4     ADD        ESP,0xc
//         004501b7     TEST       AX,AX
//         004501ba     JLE        LAB_004501e3
//                              m_co_obj.cpp:117 (11)
//         004501bc     MOVSX      EDX,AX
//         004501bf     PUSH       0x4
//         004501c1     PUSH       EDX
//         004501c2     CALL       calloc                                           undefined calloc()
//                              m_co_obj.cpp:118 (26)
//         004501c7     MOVSX      this,word ptr [EBX]
//         004501ca     ADD        ESP,0x8
//         004501cd     MOV        dword ptr [ESI + 0x10c],EAX
//         004501d3     SHL        this,0x2
//         004501d6     PUSH       this
//         004501d7     PUSH       EAX
//         004501d8     PUSH       EDI
//         004501d9     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         004501de     ADD        ESP,0xc
//                              m_co_obj.cpp:120 (2)
//         004501e1     JMP        LAB_004501ed
//                               LAB_004501e3                                                 XREF[1]:     004501ba(j)
//                              m_co_obj.cpp:121 (10)
//         004501e3     MOV        dword ptr [ESI + 0x10c],0x0
//                               LAB_004501ed                                                 XREF[1]:     004501e1(j)
//                              m_co_obj.cpp:123 (15)
//         004501ed     LEA        EBX,[ESI + 0x102]
//         004501f3     PUSH       0x2
//         004501f5     PUSH       EBX
//         004501f6     PUSH       EDI
//         004501f7     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//                              m_co_obj.cpp:124 (11)
//         004501fc     MOV        AX,word ptr [EBX]
//         004501ff     ADD        ESP,0xc
//         00450202     TEST       AX,AX
//         00450205     JLE        LAB_0045022e
//                              m_co_obj.cpp:126 (11)
//         00450207     MOVSX      EDX,AX
//         0045020a     PUSH       0x4
//         0045020c     PUSH       EDX
//         0045020d     CALL       calloc                                           undefined calloc()
//                              m_co_obj.cpp:127 (26)
//         00450212     MOVSX      this,word ptr [EBX]
//         00450215     ADD        ESP,0x8
//         00450218     MOV        dword ptr [ESI + 0x104],EAX
//         0045021e     SHL        this,0x2
//         00450221     PUSH       this
//         00450222     PUSH       EAX
//         00450223     PUSH       EDI
//         00450224     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         00450229     ADD        ESP,0xc
//                              m_co_obj.cpp:129 (2)
//         0045022c     JMP        LAB_00450238
//                               LAB_0045022e                                                 XREF[1]:     00450205(j)
//                              m_co_obj.cpp:130 (10)
//         0045022e     MOV        dword ptr [ESI + 0x104],0x0
//                               LAB_00450238                                                 XREF[1]:     0045022c(j)
//                              m_co_obj.cpp:132 (18)
//         00450238     LEA        EDX,[ESI + 0x110]
//         0045023e     PUSH       0x2
//         00450240     PUSH       EDX
//         00450241     PUSH       EDI
//         00450242     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         00450247     ADD        ESP,0xc
//                              m_co_obj.cpp:133 (18)
//         0045024a     LEA        EAX,[ESI + 0x114]
//         00450250     PUSH       0x4
//         00450252     PUSH       EAX
//         00450253     PUSH       EDI
//         00450254     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         00450259     ADD        ESP,0xc
//                              m_co_obj.cpp:134 (18)
//         0045025c     LEA        EAX,[ESI + 0x118]
//         00450262     PUSH       0x4
//         00450264     PUSH       EAX
//         00450265     PUSH       EDI
//         00450266     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         0045026b     ADD        ESP,0xc
//                              m_co_obj.cpp:135 (18)
//         0045026e     LEA        EAX,[ESI + 0x120]
//         00450274     PUSH       0x4
//         00450276     PUSH       EAX
//         00450277     PUSH       EDI
//         00450278     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         0045027d     ADD        ESP,0xc
//                              m_co_obj.cpp:136 (18)
//         00450280     LEA        this,[ESI + 0x124]
//         00450286     PUSH       0x2
//         00450288     PUSH       this
//         00450289     PUSH       EDI
//         0045028a     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         0045028f     ADD        ESP,0xc
//                              m_co_obj.cpp:137 (18)
//         00450292     LEA        EDX,[ESI + 0x126]
//         00450298     PUSH       0x2
//         0045029a     PUSH       EDX
//         0045029b     PUSH       EDI
//         0045029c     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         004502a1     ADD        ESP,0xc
//                              m_co_obj.cpp:138 (18)
//         004502a4     LEA        EAX,[ESI + 0x128]
//         004502aa     PUSH       0x1
//         004502ac     PUSH       EAX
//         004502ad     PUSH       EDI
//         004502ae     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         004502b3     ADD        ESP,0xc
//                              m_co_obj.cpp:139 (18)
//         004502b6     LEA        this,[ESI + 0x12a]
//         004502bc     PUSH       0x2
//         004502be     PUSH       this
//         004502bf     PUSH       EDI
//         004502c0     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         004502c5     ADD        ESP,0xc
//                              m_co_obj.cpp:140 (18)
//         004502c8     LEA        EDX,[ESI + 0x12c]
//         004502ce     PUSH       0x4
//         004502d0     PUSH       EDX
//         004502d1     PUSH       EDI
//         004502d2     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         004502d7     ADD        ESP,0xc
//                              m_co_obj.cpp:141 (18)
//         004502da     LEA        EAX,[ESI + 0x130]
//         004502e0     PUSH       0x4
//         004502e2     PUSH       EAX
//         004502e3     PUSH       EDI
//         004502e4     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         004502e9     ADD        ESP,0xc
//                              m_co_obj.cpp:142 (18)
//         004502ec     LEA        this,[ESI + 0x134]
//         004502f2     PUSH       0x4
//         004502f4     PUSH       this
//         004502f5     PUSH       EDI
//         004502f6     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         004502fb     ADD        ESP,0xc
//                              m_co_obj.cpp:143 (18)
//         004502fe     LEA        EDX,[ESI + 0x11c]
//         00450304     PUSH       0x1
//         00450306     PUSH       EDX
//         00450307     PUSH       EDI
//         00450308     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         0045030d     ADD        ESP,0xc
//                              m_co_obj.cpp:144 (18)
//         00450310     LEA        EAX,[ESI + 0x138]
//         00450316     PUSH       0x4
//         00450318     PUSH       EAX
//         00450319     PUSH       EDI
//         0045031a     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         0045031f     ADD        ESP,0xc
//                              m_co_obj.cpp:146 (13)
//         00450322     LEA        this=>param_3,[ESP + 0x1c]
//         00450326     PUSH       0x2
//         00450328     PUSH       this
//         00450329     PUSH       EDI
//         0045032a     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//                              m_co_obj.cpp:147 (33)
//         0045032f     MOV        AX,word ptr [ESP + param_3]
//         00450334     ADD        ESP,0xc
//         00450337     TEST       AX,AX
//         0045033a     JL         LAB_00450348
//         0045033c     MOVSX      EDX,AX
//         0045033f     MOV        EAX,dword ptr [ESP + param_2]
//         00450343     MOV        EAX,dword ptr [EAX + EDX*0x4]
//         00450346     JMP        LAB_0045034a
//                               LAB_00450348                                                 XREF[1]:     0045033a(j)
//         00450348     XOR        EAX,EAX
//                               LAB_0045034a                                                 XREF[1]:     00450346(j)
//         0045034a     MOV        dword ptr [ESI + 0xfc],EAX
//                              m_co_obj.cpp:149 (19)
//         00450350     FLD        float ptr [save_game_version]                    = 7.23
//         00450356     FCOMP      float ptr [DAT_00570500]                         = ECh
//         0045035c     FNSTSW     AX
//         0045035e     TEST       AH,0x1
//         00450361     JNZ        LAB_004503b7
//                              m_co_obj.cpp:151 (18)
//         00450363     LEA        this,[ESI + 0x13c]
//         00450369     PUSH       0x2
//         0045036b     PUSH       this
//         0045036c     PUSH       EDI
//         0045036d     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         00450372     ADD        ESP,0xc
//                              m_co_obj.cpp:152 (18)
//         00450375     LEA        EDX,[ESI + 0x13e]
//         0045037b     PUSH       0x2
//         0045037d     PUSH       EDX
//         0045037e     PUSH       EDI
//         0045037f     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         00450384     ADD        ESP,0xc
//                              m_co_obj.cpp:153 (18)
//         00450387     LEA        EAX,[ESI + 0x140]
//         0045038d     PUSH       0x4
//         0045038f     PUSH       EAX
//         00450390     PUSH       EDI
//         00450391     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         00450396     ADD        ESP,0xc
//                              m_co_obj.cpp:154 (18)
//         00450399     ADD        ESI,0x144
//         0045039f     PUSH       0x4
//         004503a1     PUSH       ESI
//         004503a2     PUSH       EDI
//         004503a3     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         004503a8     ADD        ESP,0xc
//                              m_co_obj.cpp:176 (5)
//         004503ab     MOV        EAX,0x1
//                              m_co_obj.cpp:177 (7)
//         004503b0     POP        EDI
//         004503b1     POP        ESI
//         004503b2     POP        EBP
//         004503b3     POP        EBX
//         004503b4     RET        0xc
//                               LAB_004503b7                                                 XREF[1]:     00450361(j)
//                              m_co_obj.cpp:158 (12)
//         004503b7     MOVZX      this,byte ptr [EBP]
//         004503bc     MOV        word ptr [ESI + 0x13c],this
//                              m_co_obj.cpp:159 (7)
//         004503c3     MOVSX      this,word ptr [EBX]
//         004503c6     TEST       this,this
//         004503c8     JLE        LAB_004503ee
//                              m_co_obj.cpp:177 (23)
//         004503ca     MOV        EAX,dword ptr [ESI + 0x104]
//         004503d0     MOV        EDX,this
//         004503d2     ADD        EAX,0x2
//                               LAB_004503d5                                                 XREF[1]:     004503ec(j)
//         004503d5     MOV        this,word ptr [EAX]
//         004503d8     CMP        this,word ptr [ESI + 0x13c]
//         004503df     JLE        LAB_004503e8
//                              m_co_obj.cpp:162 (7)
//         004503e1     MOV        word ptr [ESI + 0x13c],this
//                               LAB_004503e8                                                 XREF[1]:     004503df(j)
//                              m_co_obj.cpp:159 (6)
//         004503e8     ADD        EAX,0x4
//         004503eb     DEC        EDX
//         004503ec     JNZ        LAB_004503d5
//                               LAB_004503ee                                                 XREF[1]:     004503c8(j)
//                              m_co_obj.cpp:166 (31)
//         004503ee     MOVSX      this,word ptr [ESI + 0x108]
//         004503f5     TEST       this,this
//         004503f7     MOV        word ptr [ESI + 0x13e],0x0
//         00450400     JLE        LAB_00450426
//         00450402     MOV        EAX,dword ptr [ESI + 0x10c]
//         00450408     MOV        EDX,this
//         0045040a     ADD        EAX,0x2
//                               LAB_0045040d                                                 XREF[1]:     00450424(j)
//                              m_co_obj.cpp:168 (12)
//         0045040d     MOV        this,word ptr [EAX]
//         00450410     CMP        this,word ptr [ESI + 0x13e]
//         00450417     JLE        LAB_00450420
//                              m_co_obj.cpp:169 (7)
//         00450419     MOV        word ptr [ESI + 0x13e],this
//                               LAB_00450420                                                 XREF[1]:     00450417(j)
//                              m_co_obj.cpp:166 (6)
//         00450420     ADD        EAX,0x4
//         00450423     DEC        EDX
//         00450424     JNZ        LAB_0045040d
//                               LAB_00450426                                                 XREF[1]:     00450400(j)
//                              m_co_obj.cpp:172 (6)
//         00450426     MOV        EDX,dword ptr [ESI + 0x114]
//                              m_co_obj.cpp:173 (18)
//         0045042c     MOV        EAX,dword ptr [ESI + 0x120]
//         00450432     MOV        dword ptr [ESI + 0x140],EDX
//         00450438     MOV        dword ptr [ESI + 0x144],EAX
//                              m_co_obj.cpp:177 (12)
//         0045043e     POP        EDI
//         0045043f     POP        ESI
//         00450440     POP        EBP
//         00450441     MOV        EAX,0x1
//         00450446     POP        EBX
//         00450447     RET        0xc
//         0045044a     ??         90h
//         0045044b     NOP
//         0045044c     NOP
//         0045044d     NOP
//         0045044e     NOP
//         0045044f     NOP
    return 0;
}

int RGE_Master_Combat_Object::setup(_iobuf* param_1, RGE_Sprite** param_2, RGE_Sound** param_3, short param_4) {
    /* TODO: Stub */
//                              int __thiscall setup(RGE_Master_Combat_Object * this, _iobuf * param
//              int               EAX:4          <RETURN>
//              RGE_Master_Com    ECX:4 (auto)   this
//              _iobuf *          Stack[0x4]:4   param_1                   XREF[3]:     0045045a(R), 004504d4(*), 004505c6(R)
//              RGE_Sprite * *    Stack[0x8]:4   param_2                   XREF[2]:     00450455(R), 004505aa(R)
//              RGE_Sound * *     Stack[0xc]:4   param_3                   XREF[3]:     00450463(R), 0045047f(*), 004505bc(R)
//              short             Stack[0x10]:2  param_4                   XREF[3]:     00450451(R), 004504d9(*), 004505a0(R)
//              undefined         Stack[-0x2]:1  local_2                   XREF[2]:     00450499(*), 004505da(R)
//              undefined         Stack[-0x4]:1  local_4                   XREF[2]:     0045049e(*), 004505b8(R)
//              short             Stack[-0x6]:2  temp_fire_missile_at_fra
//              short             Stack[-0x8]:2  temp_break_off_combat
//                               ?setup@RGE_Master_Combat_Object@@IAEHPAU_iobuf@@PAPAVRGE_Sp  XREF[3]:     RGE_Master_Combat_Object:0044ff8b(
//                               RGE_Master_Combat_Object::setup                                           setup:004516db(c),
//                                                                                                         setup:0050ecac(c)
//                              m_co_obj.cpp:182 (1)
//         00450450     PUSH       this
//                              m_co_obj.cpp:191 (33)
//         00450451     MOV        EAX,dword ptr [ESP + param_4]
//         00450455     MOV        EDX,dword ptr [ESP + param_2]
//         00450459     PUSH       EBX
//         0045045a     MOV        EBX,dword ptr [ESP + param_1]
//         0045045e     PUSH       EBP
//         0045045f     PUSH       ESI
//         00450460     MOV        ESI,this
//         00450462     PUSH       EDI
//         00450463     MOV        this,dword ptr [ESP + param_3]
//         00450467     PUSH       EAX
//         00450468     PUSH       this
//         00450469     PUSH       EDX
//         0045046a     PUSH       EBX
//         0045046b     MOV        this,ESI
//         0045046d     CALL       RGE_Master_Action_Object::setup                  int setup(RGE_Master_Action_Object * this, _i
//                              m_co_obj.cpp:213 (124)
//         00450472     LEA        EDI,[ESI + 0x138]
//         00450478     LEA        EAX,[ESI + 0x120]
//         0045047e     PUSH       EDI
//         0045047f     LEA        EDI=>param_3,[ESP + 0x24]
//         00450483     PUSH       EDI
//         00450484     LEA        EDI,[ESI + 0x134]
//         0045048a     PUSH       EDI
//         0045048b     LEA        EDI,[ESI + 0x130]
//         00450491     PUSH       EDI
//         00450492     LEA        EDI,[ESI + 0x12c]
//         00450498     PUSH       EDI
//         00450499     LEA        EDI=>local_2,[ESP + 0x26]
//         0045049d     PUSH       EDI
//         0045049e     LEA        EDI=>local_4,[ESP + 0x28]
//         004504a2     PUSH       EDI
//         004504a3     LEA        EDI,[ESI + 0x126]
//         004504a9     PUSH       EDI
//         004504aa     LEA        EDI,[ESI + 0x124]
//         004504b0     PUSH       EDI
//         004504b1     PUSH       EAX
//         004504b2     LEA        EAX,[ESI + 0x118]
//         004504b8     LEA        this,[ESI + 0x114]
//         004504be     PUSH       EAX
//         004504bf     PUSH       this
//         004504c0     LEA        this,[ESI + 0x110]
//         004504c6     LEA        EDX,[ESI + 0x108]
//         004504cc     PUSH       this
//         004504cd     LEA        EBP,[ESI + 0x102]
//         004504d3     PUSH       EDX
//         004504d4     LEA        EDX=>param_1,[ESP + 0x50]
//         004504d8     PUSH       EBP
//         004504d9     LEA        EAX=>param_4,[ESP + 0x60]
//         004504dd     PUSH       EDX
//         004504de     PUSH       EAX
//         004504df     PUSH       s_%hd_%hd_%hd_%hd_%hd_%f_%f_%f_%hd               = "%hd %hd %hd %hd %hd %f %f %f %hd %hd %hd %
//         004504e4     PUSH       EBX
//         004504e5     MOV        byte ptr [ESI + 0x4],0x32
//         004504e9     CALL       fscanf                                           undefined fscanf()
//                              m_co_obj.cpp:216 (14)
//         004504ee     MOV        AX,word ptr [EBP]
//         004504f2     XOR        EDI,EDI
//         004504f4     ADD        ESP,0x4c
//         004504f7     CMP        AX,DI
//         004504fa     JLE        LAB_0045053e
//                              m_co_obj.cpp:218 (14)
//         004504fc     MOVSX      this,AX
//         004504ff     PUSH       0x4
//         00450501     PUSH       this
//         00450502     CALL       calloc                                           undefined calloc()
//         00450507     ADD        ESP,0x8
//                              m_co_obj.cpp:219 (12)
//         0045050a     CMP        word ptr [EBP],DI
//         0045050e     MOV        dword ptr [ESI + 0x104],EAX
//         00450514     JLE        LAB_00450544
//                               LAB_00450516                                                 XREF[1]:     0045053a(j)
//                              m_co_obj.cpp:220 (38)
//         00450516     MOV        EAX,dword ptr [ESI + 0x104]
//         0045051c     MOVSX      EDX,DI
//         0045051f     LEA        EAX,[EAX + EDX*0x4]
//         00450522     LEA        this,[EAX + 0x2]
//         00450525     PUSH       this
//         00450526     PUSH       EAX
//         00450527     PUSH       s_%hd_%hd                                        = "%hd %hd"
//         0045052c     PUSH       EBX
//         0045052d     CALL       fscanf                                           undefined fscanf()
//         00450532     ADD        ESP,0x10
//         00450535     INC        EDI
//         00450536     CMP        DI,word ptr [EBP]
//         0045053a     JL         LAB_00450516
//                              m_co_obj.cpp:222 (2)
//         0045053c     JMP        LAB_00450544
//                               LAB_0045053e                                                 XREF[1]:     004504fa(j)
//                              m_co_obj.cpp:223 (6)
//         0045053e     MOV        dword ptr [ESI + 0x104],EDI
//                               LAB_00450544                                                 XREF[2]:     00450514(j), 0045053c(j)
//                              m_co_obj.cpp:225 (14)
//         00450544     MOV        AX,word ptr [ESI + 0x108]
//         0045054b     XOR        EDI,EDI
//         0045054d     CMP        AX,DI
//         00450550     JLE        LAB_0045059a
//                              m_co_obj.cpp:227 (14)
//         00450552     MOVSX      EDX,AX
//         00450555     PUSH       0x4
//         00450557     PUSH       EDX
//         00450558     CALL       calloc                                           undefined calloc()
//         0045055d     ADD        ESP,0x8
//                              m_co_obj.cpp:228 (15)
//         00450560     CMP        word ptr [ESI + 0x108],DI
//         00450567     MOV        dword ptr [ESI + 0x10c],EAX
//         0045056d     JLE        LAB_004505a0
//                               LAB_0045056f                                                 XREF[1]:     00450596(j)
//                              m_co_obj.cpp:229 (41)
//         0045056f     MOV        this,dword ptr [ESI + 0x10c]
//         00450575     MOVSX      EAX,DI
//         00450578     LEA        EAX,[this->_padding_ + EAX*0x4]
//         0045057b     LEA        EDX,[EAX + 0x2]
//         0045057e     PUSH       EDX
//         0045057f     PUSH       EAX
//         00450580     PUSH       s_%hd_%hd                                        = "%hd %hd"
//         00450585     PUSH       EBX
//         00450586     CALL       fscanf                                           undefined fscanf()
//         0045058b     ADD        ESP,0x10
//         0045058e     INC        EDI
//         0045058f     CMP        DI,word ptr [ESI + 0x108]
//         00450596     JL         LAB_0045056f
//                              m_co_obj.cpp:231 (2)
//         00450598     JMP        LAB_004505a0
//                               LAB_0045059a                                                 XREF[1]:     00450550(j)
//                              m_co_obj.cpp:232 (6)
//         0045059a     MOV        dword ptr [ESI + 0x10c],EDI
//                               LAB_004505a0                                                 XREF[2]:     0045056d(j), 00450598(j)
//                              m_co_obj.cpp:235 (24)
//         004505a0     MOV        AX,word ptr [ESP + param_4]
//         004505a5     TEST       AX,AX
//         004505a8     JL         LAB_004505b6
//         004505aa     MOV        this,dword ptr [ESP + param_2]
//         004505ae     MOVSX      EAX,AX
//         004505b1     MOV        EAX,dword ptr [this->_padding_ + EAX*0x4]
//         004505b4     JMP        LAB_004505b8
//                               LAB_004505b6                                                 XREF[1]:     004505a8(j)
//         004505b6     XOR        EAX,EAX
//                               LAB_004505b8                                                 XREF[1]:     004505b4(j)
//                              m_co_obj.cpp:240 (30)
//         004505b8     MOV        this,byte ptr [ESP + local_4]
//         004505bc     MOV        DL,byte ptr [ESP + param_3]
//         004505c0     MOV        dword ptr [ESI + 0xfc],EAX
//         004505c6     MOV        AL,byte ptr [ESP + param_1]
//         004505ca     MOV        byte ptr [ESI + 0x128],this
//         004505d0     MOV        byte ptr [ESI + 0x11c],DL
//                              m_co_obj.cpp:245 (49)
//         004505d6     MOVSX      this,word ptr [EBP]
//         004505da     MOVZX      DX,byte ptr [ESP + local_2]
//         004505e0     MOV        byte ptr [ESI + 0x100],AL
//         004505e6     MOV        word ptr [ESI + 0x12a],DX
//         004505ed     MOVZX      AX,AL
//         004505f1     TEST       this,this
//         004505f3     MOV        word ptr [ESI + 0x13c],AX
//         004505fa     JLE        LAB_00450620
//         004505fc     MOV        EAX,dword ptr [ESI + 0x104]
//         00450602     MOV        EDX,this
//         00450604     ADD        EAX,0x2
//                               LAB_00450607                                                 XREF[1]:     0045061e(j)
//                              m_co_obj.cpp:247 (12)
//         00450607     MOV        this,word ptr [EAX]
//         0045060a     CMP        this,word ptr [ESI + 0x13c]
//         00450611     JLE        LAB_0045061a
//                              m_co_obj.cpp:248 (7)
//         00450613     MOV        word ptr [ESI + 0x13c],this
//                               LAB_0045061a                                                 XREF[1]:     00450611(j)
//                              m_co_obj.cpp:245 (6)
//         0045061a     ADD        EAX,0x4
//         0045061d     DEC        EDX
//         0045061e     JNZ        LAB_00450607
//                               LAB_00450620                                                 XREF[1]:     004505fa(j)
//                              m_co_obj.cpp:252 (31)
//         00450620     MOVSX      this,word ptr [ESI + 0x108]
//         00450627     TEST       this,this
//         00450629     MOV        word ptr [ESI + 0x13e],0x0
//         00450632     JLE        LAB_00450658
//         00450634     MOV        EAX,dword ptr [ESI + 0x10c]
//         0045063a     MOV        EDX,this
//         0045063c     ADD        EAX,0x2
//                               LAB_0045063f                                                 XREF[1]:     00450656(j)
//                              m_co_obj.cpp:254 (12)
//         0045063f     MOV        this,word ptr [EAX]
//         00450642     CMP        this,word ptr [ESI + 0x13e]
//         00450649     JLE        LAB_00450652
//                              m_co_obj.cpp:255 (7)
//         0045064b     MOV        word ptr [ESI + 0x13e],this
//                               LAB_00450652                                                 XREF[1]:     00450649(j)
//                              m_co_obj.cpp:252 (6)
//         00450652     ADD        EAX,0x4
//         00450655     DEC        EDX
//         00450656     JNZ        LAB_0045063f
//                               LAB_00450658                                                 XREF[1]:     00450632(j)
//                              m_co_obj.cpp:258 (6)
//         00450658     MOV        this,dword ptr [ESI + 0x114]
//                              m_co_obj.cpp:259 (18)
//         0045065e     MOV        EDX,dword ptr [ESI + 0x120]
//         00450664     MOV        dword ptr [ESI + 0x140],this
//         0045066a     MOV        dword ptr [ESI + 0x144],EDX
//                              m_co_obj.cpp:262 (13)
//         00450670     POP        EDI
//         00450671     POP        ESI
//         00450672     POP        EBP
//         00450673     MOV        EAX,0x1
//         00450678     POP        EBX
//         00450679     POP        this
//         0045067a     RET        0x10
//         0045067d     ??         90h
//         0045067e     NOP
//         0045067f     NOP
    return 0;
}

RGE_Master_Combat_Object::~RGE_Master_Combat_Object() {
    /* TODO: Stub */
//                              void __thiscall ~RGE_Master_Combat_Object(RGE_Master_Combat_Object *
//              void              <VOID>         <RETURN>
//              RGE_Master_Com    ECX:4 (auto)   this
//                               ??1RGE_Master_Combat_Object@@UAE@XZ                          XREF[3]:     `vector_deleting_destructor':0044f
//                               RGE_Master_Combat_Object::~RGE_Master_Combat_Object                       ~RGE_Master_Missile_Object:0045176
//                                                                                                         ~TRIBE_Master_Combat_Object:0050ed
//                              m_co_obj.cpp:268 (3)
//         00450680     PUSH       ESI
//         00450681     MOV        ESI,this
//                              m_co_obj.cpp:269 (16)
//         00450683     MOV        EAX,dword ptr [ESI + 0x10c]
//         00450689     MOV        dword ptr [ESI],RGE_Master_Combat_Object::`vft   = 0044fea0
//         0045068f     TEST       EAX,EAX
//         00450691     JZ         LAB_004506a6
//                              m_co_obj.cpp:271 (9)
//         00450693     PUSH       EAX
//         00450694     CALL       free                                             undefined free()
//         00450699     ADD        ESP,0x4
//                              m_co_obj.cpp:272 (10)
//         0045069c     MOV        dword ptr [ESI + 0x10c],0x0
//                               LAB_004506a6                                                 XREF[1]:     00450691(j)
//                              m_co_obj.cpp:275 (10)
//         004506a6     MOV        EAX,dword ptr [ESI + 0x104]
//         004506ac     TEST       EAX,EAX
//         004506ae     JZ         LAB_004506c3
//                              m_co_obj.cpp:277 (9)
//         004506b0     PUSH       EAX
//         004506b1     CALL       free                                             undefined free()
//         004506b6     ADD        ESP,0x4
//                              m_co_obj.cpp:278 (17)
//         004506b9     MOV        dword ptr [ESI + 0x104],0x0
//                               LAB_004506c3                                                 XREF[1]:     004506ae(j)
//         004506c3     MOV        this,ESI
//         004506c5     CALL       RGE_Master_Action_Object::~RGE_Master_Action_O   void ~RGE_Master_Action_Object(RGE_Master_Act
//                              m_co_obj.cpp:280 (2)
//         004506ca     POP        ESI
//         004506cb     RET
//         004506cc     ??         90h
//         004506cd     NOP
//         004506ce     NOP
//         004506cf     NOP
}

RGE_Static_Object* RGE_Master_Combat_Object::make_new_obj(RGE_Player* param_1, float param_2, float param_3, float param_4) {
    /* TODO: Stub */
//                              RGE_Static_Object * __thiscall make_new_obj(RGE_Master_Combat_Object
//              RGE_Static_Obj    EAX:4          <RETURN>
//              RGE_Master_Com    ECX:4 (auto)   this
//              RGE_Player *      Stack[0x4]:4   param_1                   XREF[2]:     004506e7(R), 00450745(W)
//              float             Stack[0x8]:4   param_2                   XREF[2]:     00450715(R), 00450760(R)
//              float             Stack[0xc]:4   param_3                   XREF[2]:     0045070e(R), 00450759(R)
//              float             Stack[0x10]:4  param_4                   XREF[2]:     0045070a(R), 00450755(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     0045074b(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[2]:     0045076f(R), 00450783(R)
//                               ?make_new_obj@RGE_Master_Combat_Object@@UAEPAVRGE_Static_Ob  XREF[1]:     005704d8(*)
//                               RGE_Master_Combat_Object::make_new_obj
//                              m_co_obj.cpp:285 (23)
//         004506d0     MOV        EAX,FS:[0x0]
//         004506d6     PUSH       -0x1
//         004506d8     PUSH       FUN_0055d81b
//         004506dd     PUSH       EAX
//         004506de     MOV        dword ptr FS:[0x0],ESP
//         004506e5     PUSH       EBX
//         004506e6     PUSH       ESI
//                              m_co_obj.cpp:288 (17)
//         004506e7     MOV        EBX,dword ptr [ESP + param_1]
//         004506eb     PUSH       EDI
//         004506ec     MOV        EDI,this
//         004506ee     MOV        AL,byte ptr [EDI + 0xa4]
//         004506f4     TEST       AL,AL
//         004506f6     JZ         LAB_00450738
//                              m_co_obj.cpp:290 (14)
//         004506f8     MOV        AL,byte ptr [EDI + 0x4]
//         004506fb     MOV        this,dword ptr [EBX + 0x3c]
//         004506fe     PUSH       EAX
//         004506ff     CALL       RGE_Game_World::recycle_object_in_to_game        RGE_Static_Object * recycle_object_in_to_game
//         00450704     MOV        ESI,EAX
//                              m_co_obj.cpp:291 (4)
//         00450706     TEST       ESI,ESI
//         00450708     JZ         LAB_00450738
//                              m_co_obj.cpp:293 (24)
//         0045070a     MOV        EAX,dword ptr [ESP + param_4]
//         0045070e     MOV        this,dword ptr [ESP + param_3]
//         00450712     MOV        EDX,dword ptr [ESI]
//         00450714     PUSH       EAX
//         00450715     MOV        EAX,dword ptr [ESP + param_2]
//         00450719     PUSH       this
//         0045071a     PUSH       EAX
//         0045071b     PUSH       EBX
//         0045071c     PUSH       EDI
//         0045071d     MOV        this,ESI
//         0045071f     CALL       dword ptr [EDX + 0x4]
//                              m_co_obj.cpp:294 (2)
//         00450722     MOV        EAX,ESI
//                              m_co_obj.cpp:299 (20)
//         00450724     MOV        this,dword ptr [ESP + 0xc]
//         00450728     MOV        dword ptr FS:[0x0],this
//         0045072f     POP        EDI
//         00450730     POP        ESI
//         00450731     POP        EBX
//         00450732     ADD        ESP,0xc
//         00450735     RET        0x10
//                               LAB_00450738                                                 XREF[2]:     004506f6(j), 00450708(j)
//                              m_co_obj.cpp:298 (55)
//         00450738     PUSH       0x1c4
//         0045073d     CALL       operator_new                                     void * operator_new(uint param_1)
//         00450742     ADD        ESP,0x4
//         00450745     MOV        dword ptr [ESP + param_1],EAX
//         00450749     TEST       EAX,EAX
//         0045074b     MOV        dword ptr [ESP + local_4],0x0
//         00450753     JZ         LAB_00450783
//         00450755     MOV        this,dword ptr [ESP + param_4]
//         00450759     MOV        EDX,dword ptr [ESP + param_3]
//         0045075d     PUSH       0x1
//         0045075f     PUSH       this
//         00450760     MOV        this,dword ptr [ESP + param_2]
//         00450764     PUSH       EDX
//         00450765     PUSH       this
//         00450766     PUSH       EBX
//         00450767     PUSH       EDI
//         00450768     MOV        this,EAX
//         0045076a     CALL       RGE_Combat_Object::RGE_Combat_Object             undefined RGE_Combat_Object(RGE_Combat_Object
//                              m_co_obj.cpp:299 (42)
//         0045076f     MOV        this,dword ptr [ESP + local_c]
//         00450773     MOV        dword ptr FS:[0x0],this
//         0045077a     POP        EDI
//         0045077b     POP        ESI
//         0045077c     POP        EBX
//         0045077d     ADD        ESP,0xc
//         00450780     RET        0x10
//                               LAB_00450783                                                 XREF[1]:     00450753(j)
//         00450783     MOV        this,dword ptr [ESP + local_c]
//         00450787     POP        EDI
//         00450788     POP        ESI
//         00450789     XOR        EAX,EAX
//         0045078b     MOV        dword ptr FS:[0x0],this
//         00450792     POP        EBX
//         00450793     ADD        ESP,0xc
//         00450796     RET        0x10
//         00450799     ??         90h
//         0045079a     NOP
//         0045079b     NOP
//         0045079c     NOP
//         0045079d     NOP
//         0045079e     NOP
//         0045079f     NOP
    return 0;
}

void RGE_Master_Combat_Object::copy_obj(RGE_Master_Static_Object* param_1) {
    /* TODO: Stub */
//                              void __thiscall copy_obj(RGE_Master_Combat_Object * this, RGE_Master
//              void              <VOID>         <RETURN>
//              RGE_Master_Com    ECX:4 (auto)   this
//              RGE_Master_Sta    Stack[0x4]:4   param_1                   XREF[1]:     00450812(R)
//                               ?copy_obj@RGE_Master_Combat_Object@@UAEXPAVRGE_Master_Stati  XREF[3]:     copy_obj:004518b9(c),
//                               RGE_Master_Combat_Object::copy_obj                                        copy_obj:0050ee0b(c), 005704c4(*)
//                              m_co_obj.cpp:311 (2)
//         00450810     PUSH       EBX
//         00450811     PUSH       EBP
//                              m_co_obj.cpp:314 (14)
//         00450812     MOV        EBP,dword ptr [ESP + param_1]
//         00450816     PUSH       ESI
//         00450817     PUSH       EDI
//         00450818     MOV        EBX,this
//         0045081a     PUSH       EBP
//         0045081b     CALL       RGE_Master_Action_Object::copy_obj               void copy_obj(RGE_Master_Action_Object * this
//                              m_co_obj.cpp:316 (12)
//         00450820     MOV        EAX,dword ptr [EBP + 0xfc]
//         00450826     MOV        dword ptr [EBX + 0xfc],EAX
//                              m_co_obj.cpp:317 (6)
//         0045082c     MOV        this,byte ptr [EBP + 0x100]
//                              m_co_obj.cpp:320 (30)
//         00450832     MOV        EAX,dword ptr [EBX + 0x10c]
//         00450838     MOV        byte ptr [EBX + 0x100],this
//         0045083e     MOV        DX,word ptr [EBP + 0x108]
//         00450845     TEST       EAX,EAX
//         00450847     MOV        word ptr [EBX + 0x108],DX
//         0045084e     JZ         LAB_00450859
//                              m_co_obj.cpp:321 (9)
//         00450850     PUSH       EAX
//         00450851     CALL       free                                             undefined free()
//         00450856     ADD        ESP,0x4
//                               LAB_00450859                                                 XREF[1]:     0045084e(j)
//                              m_co_obj.cpp:322 (12)
//         00450859     MOV        AX,word ptr [EBX + 0x108]
//         00450860     TEST       AX,AX
//         00450863     JLE        LAB_0045089b
//                              m_co_obj.cpp:324 (11)
//         00450865     MOVSX      EAX,AX
//         00450868     PUSH       0x4
//         0045086a     PUSH       EAX
//         0045086b     CALL       calloc                                           undefined calloc()
//                              m_co_obj.cpp:325 (41)
//         00450870     MOVSX      this,word ptr [EBX + 0x108]
//         00450877     SHL        this,0x2
//         0045087a     MOV        EDX,this
//         0045087c     MOV        dword ptr [EBX + 0x10c],EAX
//         00450882     MOV        ESI,dword ptr [EBP + 0x10c]
//         00450888     MOV        EDI,EAX
//         0045088a     SHR        this,0x2
//         0045088d     MOVSD.REP  ES:EDI,ESI
//         0045088f     MOV        this,EDX
//         00450891     ADD        ESP,0x8
//         00450894     AND        this,0x3
//         00450897     MOVSB.REP  ES:EDI,ESI
//                              m_co_obj.cpp:327 (2)
//         00450899     JMP        LAB_004508a5
//                               LAB_0045089b                                                 XREF[1]:     00450863(j)
//                              m_co_obj.cpp:328 (10)
//         0045089b     MOV        dword ptr [EBX + 0x10c],0x0
//                               LAB_004508a5                                                 XREF[1]:     00450899(j)
//                              m_co_obj.cpp:330 (14)
//         004508a5     MOV        AX,word ptr [EBP + 0x102]
//         004508ac     MOV        word ptr [EBX + 0x102],AX
//                              m_co_obj.cpp:331 (10)
//         004508b3     MOV        EAX,dword ptr [EBX + 0x104]
//         004508b9     TEST       EAX,EAX
//         004508bb     JZ         LAB_004508c6
//                              m_co_obj.cpp:332 (9)
//         004508bd     PUSH       EAX
//         004508be     CALL       free                                             undefined free()
//         004508c3     ADD        ESP,0x4
//                               LAB_004508c6                                                 XREF[1]:     004508bb(j)
//                              m_co_obj.cpp:333 (12)
//         004508c6     MOV        AX,word ptr [EBX + 0x102]
//         004508cd     TEST       AX,AX
//         004508d0     JLE        LAB_00450908
//                              m_co_obj.cpp:335 (11)
//         004508d2     MOVSX      this,AX
//         004508d5     PUSH       0x4
//         004508d7     PUSH       this
//         004508d8     CALL       calloc                                           undefined calloc()
//                              m_co_obj.cpp:336 (41)
//         004508dd     MOVSX      this,word ptr [EBX + 0x102]
//         004508e4     SHL        this,0x2
//         004508e7     MOV        EDX,this
//         004508e9     MOV        dword ptr [EBX + 0x104],EAX
//         004508ef     MOV        ESI,dword ptr [EBP + 0x104]
//         004508f5     MOV        EDI,EAX
//         004508f7     SHR        this,0x2
//         004508fa     MOVSD.REP  ES:EDI,ESI
//         004508fc     MOV        this,EDX
//         004508fe     ADD        ESP,0x8
//         00450901     AND        this,0x3
//         00450904     MOVSB.REP  ES:EDI,ESI
//                              m_co_obj.cpp:338 (2)
//         00450906     JMP        LAB_00450912
//                               LAB_00450908                                                 XREF[1]:     004508d0(j)
//                              m_co_obj.cpp:339 (10)
//         00450908     MOV        dword ptr [EBX + 0x104],0x0
//                               LAB_00450912                                                 XREF[1]:     00450906(j)
//                              m_co_obj.cpp:341 (7)
//         00450912     MOV        AX,word ptr [EBP + 0x110]
//                              m_co_obj.cpp:358 (216)
//         00450919     POP        EDI
//         0045091a     MOV        word ptr [EBX + 0x110],AX
//         00450921     MOV        this,dword ptr [EBP + 0x114]
//         00450927     MOV        dword ptr [EBX + 0x114],this
//         0045092d     MOV        EDX,dword ptr [EBP + 0x118]
//         00450933     MOV        dword ptr [EBX + 0x118],EDX
//         00450939     MOV        EAX,dword ptr [EBP + 0x120]
//         0045093f     MOV        dword ptr [EBX + 0x120],EAX
//         00450945     MOV        this,word ptr [EBP + 0x124]
//         0045094c     MOV        word ptr [EBX + 0x124],this
//         00450953     MOV        DX,word ptr [EBP + 0x126]
//         0045095a     MOV        word ptr [EBX + 0x126],DX
//         00450961     MOV        AL,byte ptr [EBP + 0x128]
//         00450967     MOV        byte ptr [EBX + 0x128],AL
//         0045096d     MOV        this,word ptr [EBP + 0x12a]
//         00450974     MOV        word ptr [EBX + 0x12a],this
//         0045097b     MOV        EDX,dword ptr [EBP + 0x12c]
//         00450981     MOV        dword ptr [EBX + 0x12c],EDX
//         00450987     MOV        EAX,dword ptr [EBP + 0x130]
//         0045098d     MOV        dword ptr [EBX + 0x130],EAX
//         00450993     MOV        this,dword ptr [EBP + 0x134]
//         00450999     MOV        dword ptr [EBX + 0x134],this
//         0045099f     MOV        DL,byte ptr [EBP + 0x11c]
//         004509a5     MOV        byte ptr [EBX + 0x11c],DL
//         004509ab     MOV        EAX,dword ptr [EBP + 0x138]
//         004509b1     MOV        dword ptr [EBX + 0x138],EAX
//         004509b7     MOV        this,word ptr [EBP + 0x13c]
//         004509be     MOV        word ptr [EBX + 0x13c],this
//         004509c5     MOV        DX,word ptr [EBP + 0x13e]
//         004509cc     MOV        word ptr [EBX + 0x13e],DX
//         004509d3     MOV        EAX,dword ptr [EBP + 0x140]
//         004509d9     MOV        dword ptr [EBX + 0x140],EAX
//         004509df     MOV        this,dword ptr [EBP + 0x144]
//         004509e5     POP        ESI
//         004509e6     MOV        dword ptr [EBX + 0x144],this
//         004509ec     POP        EBP
//         004509ed     POP        EBX
//         004509ee     RET        0x4
//         004509f1     ??         90h
//         004509f2     NOP
//         004509f3     NOP
//         004509f4     NOP
//         004509f5     NOP
//         004509f6     NOP
//         004509f7     NOP
//         004509f8     NOP
//         004509f9     NOP
//         004509fa     NOP
//         004509fb     NOP
//         004509fc     NOP
//         004509fd     NOP
//         004509fe     NOP
//         004509ff     NOP
    return;
}

void RGE_Master_Combat_Object::modify(float param_1, uchar param_2) {
    /* TODO: Stub */
//                              void __thiscall modify(RGE_Master_Combat_Object * this, float param_
//              void              <VOID>         <RETURN>
//              RGE_Master_Com    ECX:4 (auto)   this
//              float             Stack[0x4]:4   param_1                   XREF[9]:     00450a21(R), 00450a4b(R), 00450a89(R), 00450a97(R),
//                                                                                     00450aab(R), 00450ab9(R), 00450acc(R), 00450ae4(R),
//                                                                                     00450af9(R)
//              uchar             Stack[0x8]:1   param_2                   XREF[1]:     00450a03(R)
//                               ?modify@RGE_Master_Combat_Object@@UAEXME@Z                   XREF[3]:     modify:00451934(c),
//                               RGE_Master_Combat_Object::modify                                          modify:0050eea4(c), 005704c8(*)
//                              m_co_obj.cpp:362 (3)
//         00450a00     PUSH       ESI
//         00450a01     MOV        ESI,this
//                              m_co_obj.cpp:366 (30)
//         00450a03     MOV        this,dword ptr [ESP + param_2]
//         00450a07     MOV        EAX,this
//         00450a09     AND        EAX,0xff
//         00450a0e     ADD        EAX,-0x8
//         00450a11     CMP        EAX,0xa
//         00450a14     JA         switchD_00450a1a::caseD_d
//                               switchD_00450a1a::switchD
//         00450a1a     JMP        dword ptr [EAX*0x4 + switchD_00450a1a::switchd   = 00450a21
//                               switchD_00450a1a::caseD_8                                    XREF[2]:     00450a1a(j), 00450b0c(*)
//                              m_co_obj.cpp:369 (9)
//         00450a21     FLD        float ptr [ESP + param_1]
//         00450a25     CALL       __ftol                                           undefined __ftol()
//                              m_co_obj.cpp:371 (31)
//         00450a2a     MOV        EDX,dword ptr [ESI + 0x104]
//         00450a30     XOR        this,this
//         00450a32     TEST       EDX,EDX
//         00450a34     MOV        this,AH
//         00450a36     JZ         LAB_00450b05
//         00450a3c     MOVSX      ESI,word ptr [ESI + 0x102]
//         00450a43     AND        this,0xffff
//                              m_co_obj.cpp:373 (2)
//         00450a49     JMP        LAB_00450a73
//                               switchD_00450a1a::caseD_9                                    XREF[2]:     00450a1a(j), 00450b10(*)
//                              m_co_obj.cpp:375 (9)
//         00450a4b     FLD        float ptr [ESP + param_1]
//         00450a4f     CALL       __ftol                                           undefined __ftol()
//                              m_co_obj.cpp:377 (39)
//         00450a54     MOV        EDX,dword ptr [ESI + 0x10c]
//         00450a5a     XOR        this,this
//         00450a5c     TEST       EDX,EDX
//         00450a5e     MOV        this,AH
//         00450a60     JZ         LAB_00450b05
//         00450a66     MOVSX      ESI,word ptr [ESI + 0x108]
//         00450a6d     AND        this,0xffff
//                               LAB_00450a73                                                 XREF[1]:     00450a49(j)
//         00450a73     CMP        this,ESI
//         00450a75     JGE        LAB_00450b05
//                              m_co_obj.cpp:378 (10)
//         00450a7b     AND        EAX,0xff
//         00450a80     MOV        word ptr [EDX + this->_padding_*0x4 + 0x2],AX
//                              m_co_obj.cpp:402 (4)
//         00450a85     POP        ESI
//         00450a86     RET        0x8
//                               switchD_00450a1a::caseD_a                                    XREF[2]:     00450a1a(j), 00450b14(*)
//                              m_co_obj.cpp:381 (10)
//         00450a89     MOV        this,dword ptr [ESP + param_1]
//         00450a8d     MOV        dword ptr [ESI + 0x120],this
//                              m_co_obj.cpp:402 (4)
//         00450a93     POP        ESI
//         00450a94     RET        0x8
//                               switchD_00450a1a::caseD_b                                    XREF[2]:     00450a1a(j), 00450b18(*)
//                              m_co_obj.cpp:384 (16)
//         00450a97     FLD        float ptr [ESP + param_1]
//         00450a9b     CALL       __ftol                                           undefined __ftol()
//         00450aa0     MOV        word ptr [ESI + 0x126],AX
//                              m_co_obj.cpp:402 (4)
//         00450aa7     POP        ESI
//         00450aa8     RET        0x8
//                               switchD_00450a1a::caseD_c                                    XREF[2]:     00450a1a(j), 00450b1c(*)
//                              m_co_obj.cpp:387 (10)
//         00450aab     MOV        EDX,dword ptr [ESP + param_1]
//         00450aaf     MOV        dword ptr [ESI + 0x114],EDX
//                              m_co_obj.cpp:402 (4)
//         00450ab5     POP        ESI
//         00450ab6     RET        0x8
//                               switchD_00450a1a::caseD_f                                    XREF[2]:     00450a1a(j), 00450b28(*)
//                              m_co_obj.cpp:390 (15)
//         00450ab9     FLD        float ptr [ESP + param_1]
//         00450abd     CALL       __ftol                                           undefined __ftol()
//         00450ac2     MOV        byte ptr [ESI + 0x100],AL
//                              m_co_obj.cpp:402 (4)
//         00450ac8     POP        ESI
//         00450ac9     RET        0x8
//                               switchD_00450a1a::caseD_10                                   XREF[2]:     00450a1a(j), 00450b2c(*)
//                              m_co_obj.cpp:393 (20)
//         00450acc     FLD        float ptr [ESP + param_1]
//         00450ad0     CALL       __ftol                                           undefined __ftol()
//         00450ad5     MOVZX      AX,AL
//         00450ad9     MOV        word ptr [ESI + 0x124],AX
//                              m_co_obj.cpp:402 (4)
//         00450ae0     POP        ESI
//         00450ae1     RET        0x8
//                               switchD_00450a1a::caseD_12                                   XREF[2]:     00450a1a(j), 00450b34(*)
//                              m_co_obj.cpp:396 (16)
//         00450ae4     FLD        float ptr [ESP + param_1]
//         00450ae8     CALL       __ftol                                           undefined __ftol()
//         00450aed     MOV        word ptr [ESI + 0x110],AX
//                              m_co_obj.cpp:402 (4)
//         00450af4     POP        ESI
//         00450af5     RET        0x8
//                               switchD_00450a1a::caseD_e                                    XREF[5]:     00450a14(j), 00450a1a(j),
//                               switchD_00450a1a::caseD_11                                                00450b20(*), 00450b24(*),
//                               switchD_00450a1a::caseD_d                                                 00450b30(*)
//                              m_co_obj.cpp:399 (13)
//         00450af8     PUSH       this
//         00450af9     MOV        this,dword ptr [ESP + param_1]
//         00450afd     PUSH       this
//         00450afe     MOV        this,ESI
//         00450b00     CALL       RGE_Master_Action_Object::modify                 void modify(RGE_Master_Action_Object * this,
//                               LAB_00450b05                                                 XREF[3]:     00450a36(j), 00450a60(j),
//                                                                                                         00450a75(j)
//                              m_co_obj.cpp:402 (51)
//         00450b05     POP        ESI
//         00450b06     RET        0x8
    return;
}

void RGE_Master_Combat_Object::modify_delta(float param_1, uchar param_2) {
    /* TODO: Stub */
//                              void __thiscall modify_delta(RGE_Master_Combat_Object * this, float
//              void              <VOID>         <RETURN>
//              RGE_Master_Com    ECX:4 (auto)   this
//              float             Stack[0x4]:4   param_1                   XREF[10]:    00450b63(R), 00450bb2(R), 00450c1b(R), 00450c31(R),
//                                                                                     00450c47(R), 00450c5d(R), 00450c73(R), 00450c88(R),
//                                                                                     00450c9e(R), 00450cb4(R)
//              uchar             Stack[0x8]:1   param_2                   XREF[1]:     00450b45(R)
//                               ?modify_delta@RGE_Master_Combat_Object@@UAEXME@Z             XREF[3]:     modify_delta:00451964(c),
//                               RGE_Master_Combat_Object::modify_delta                                    modify_delta:0050ef7e(c),
//                                                                                                         005704cc(*)
//                              m_co_obj.cpp:406 (5)
//         00450b40     PUSH       EBX
//         00450b41     PUSH       ESI
//         00450b42     MOV        ESI,this
//         00450b44     PUSH       EDI
//                              m_co_obj.cpp:411 (30)
//         00450b45     MOV        this,dword ptr [ESP + param_2]
//         00450b49     MOV        EAX,this
//         00450b4b     AND        EAX,0xff
//         00450b50     ADD        EAX,-0x6
//         00450b53     CMP        EAX,0xc
//         00450b56     JA         switchD_00450b5c::caseD_7
//                               switchD_00450b5c::switchD
//         00450b5c     JMP        dword ptr [EAX*0x4 + switchD_00450b5c::switchd   = 00450c1b
//                               switchD_00450b5c::caseD_8                                    XREF[2]:     00450b5c(j), 00450cd0(*)
//                              m_co_obj.cpp:414 (9)
//         00450b63     FLD        float ptr [ESP + param_1]
//         00450b67     CALL       __ftol                                           undefined __ftol()
//                              m_co_obj.cpp:416 (18)
//         00450b6c     MOV        EDI,dword ptr [ESI + 0x104]
//         00450b72     XOR        EBX,EBX
//         00450b74     TEST       EDI,EDI
//         00450b76     MOV        BL,AH
//         00450b78     JZ         LAB_00450cc1
//                              m_co_obj.cpp:418 (17)
//         00450b7e     MOVSX      ESI,word ptr [ESI + 0x102]
//         00450b85     XOR        EDX,EDX
//         00450b87     TEST       ESI,ESI
//         00450b89     JLE        LAB_00450cc1
//                              m_co_obj.cpp:420 (29)
//         00450b8f     XOR        this,this
//         00450b91     AND        EBX,0xffff
//                               LAB_00450b97                                                 XREF[1]:     00450baa(j)
//         00450b97     MOVSX      this,word ptr [EDI + this->_padding_*0x4]
//         00450b9b     CMP        this,EBX
//         00450b9d     JZ         LAB_00450c01
//         00450b9f     INC        EDX
//         00450ba0     MOV        this,EDX
//         00450ba2     AND        this,0xffff
//         00450ba8     CMP        this,ESI
//         00450baa     JL         LAB_00450b97
//                              m_co_obj.cpp:468 (6)
//         00450bac     POP        EDI
//         00450bad     POP        ESI
//         00450bae     POP        EBX
//         00450baf     RET        0x8
//                               switchD_00450b5c::caseD_9                                    XREF[2]:     00450b5c(j), 00450cd4(*)
//                              m_co_obj.cpp:429 (9)
//         00450bb2     FLD        float ptr [ESP + param_1]
//         00450bb6     CALL       __ftol                                           undefined __ftol()
//                              m_co_obj.cpp:431 (18)
//         00450bbb     MOV        EDI,dword ptr [ESI + 0x10c]
//         00450bc1     XOR        EBX,EBX
//         00450bc3     TEST       EDI,EDI
//         00450bc5     MOV        BL,AH
//         00450bc7     JZ         LAB_00450cc1
//                              m_co_obj.cpp:433 (17)
//         00450bcd     MOVSX      ESI,word ptr [ESI + 0x108]
//         00450bd4     XOR        EDX,EDX
//         00450bd6     TEST       ESI,ESI
//         00450bd8     JLE        LAB_00450cc1
//                              m_co_obj.cpp:435 (29)
//         00450bde     XOR        this,this
//         00450be0     AND        EBX,0xffff
//                               LAB_00450be6                                                 XREF[1]:     00450bf9(j)
//         00450be6     MOVSX      this,word ptr [EDI + this->_padding_*0x4]
//         00450bea     CMP        this,EBX
//         00450bec     JZ         LAB_00450c01
//         00450bee     INC        EDX
//         00450bef     MOV        this,EDX
//         00450bf1     AND        this,0xffff
//         00450bf7     CMP        this,ESI
//         00450bf9     JL         LAB_00450be6
//                              m_co_obj.cpp:468 (6)
//         00450bfb     POP        EDI
//         00450bfc     POP        ESI
//         00450bfd     POP        EBX
//         00450bfe     RET        0x8
//                               LAB_00450c01                                                 XREF[2]:     00450b9d(j), 00450bec(j)
//                              m_co_obj.cpp:437 (20)
//         00450c01     AND        EDX,0xffff
//         00450c07     AND        EAX,0xff
//         00450c0c     ADD        word ptr [EDI + EDX*0x4 + 0x2],AX
//         00450c11     LEA        this,[EDI + EDX*0x4 + 0x2]
//                              m_co_obj.cpp:468 (6)
//         00450c15     POP        EDI
//         00450c16     POP        ESI
//         00450c17     POP        EBX
//         00450c18     RET        0x8
//                               switchD_00450b5c::caseD_6                                    XREF[2]:     00450b5c(j), 00450cc8(*)
//                              m_co_obj.cpp:444 (16)
//         00450c1b     FLD        float ptr [ESP + param_1]
//         00450c1f     FADD       float ptr [ESI + 0xc4]
//         00450c25     FSTP       float ptr [ESI + 0xc4]
//                              m_co_obj.cpp:468 (6)
//         00450c2b     POP        EDI
//         00450c2c     POP        ESI
//         00450c2d     POP        EBX
//         00450c2e     RET        0x8
//                               switchD_00450b5c::caseD_a                                    XREF[2]:     00450b5c(j), 00450cd8(*)
//                              m_co_obj.cpp:447 (16)
//         00450c31     FLD        float ptr [ESP + param_1]
//         00450c35     FADD       float ptr [ESI + 0x120]
//         00450c3b     FSTP       float ptr [ESI + 0x120]
//                              m_co_obj.cpp:468 (6)
//         00450c41     POP        EDI
//         00450c42     POP        ESI
//         00450c43     POP        EBX
//         00450c44     RET        0x8
//                               switchD_00450b5c::caseD_b                                    XREF[2]:     00450b5c(j), 00450cdc(*)
//                              m_co_obj.cpp:450 (16)
//         00450c47     FLD        float ptr [ESP + param_1]
//         00450c4b     CALL       __ftol                                           undefined __ftol()
//         00450c50     ADD        word ptr [ESI + 0x126],AX
//                              m_co_obj.cpp:468 (6)
//         00450c57     POP        EDI
//         00450c58     POP        ESI
//         00450c59     POP        EBX
//         00450c5a     RET        0x8
//                               switchD_00450b5c::caseD_c                                    XREF[2]:     00450b5c(j), 00450ce0(*)
//                              m_co_obj.cpp:453 (16)
//         00450c5d     FLD        float ptr [ESP + param_1]
//         00450c61     FADD       float ptr [ESI + 0x114]
//         00450c67     FSTP       float ptr [ESI + 0x114]
//                              m_co_obj.cpp:468 (6)
//         00450c6d     POP        EDI
//         00450c6e     POP        ESI
//         00450c6f     POP        EBX
//         00450c70     RET        0x8
//                               switchD_00450b5c::caseD_f                                    XREF[2]:     00450b5c(j), 00450cec(*)
//                              m_co_obj.cpp:456 (15)
//         00450c73     FLD        float ptr [ESP + param_1]
//         00450c77     CALL       __ftol                                           undefined __ftol()
//         00450c7c     ADD        byte ptr [ESI + 0x100],AL
//                              m_co_obj.cpp:468 (6)
//         00450c82     POP        EDI
//         00450c83     POP        ESI
//         00450c84     POP        EBX
//         00450c85     RET        0x8
//                               switchD_00450b5c::caseD_10                                   XREF[2]:     00450b5c(j), 00450cf0(*)
//                              m_co_obj.cpp:459 (16)
//         00450c88     FLD        float ptr [ESP + param_1]
//         00450c8c     CALL       __ftol                                           undefined __ftol()
//         00450c91     ADD        word ptr [ESI + 0x124],AX
//                              m_co_obj.cpp:468 (6)
//         00450c98     POP        EDI
//         00450c99     POP        ESI
//         00450c9a     POP        EBX
//         00450c9b     RET        0x8
//                               switchD_00450b5c::caseD_12                                   XREF[2]:     00450b5c(j), 00450cf8(*)
//                              m_co_obj.cpp:462 (16)
//         00450c9e     FLD        float ptr [ESP + param_1]
//         00450ca2     CALL       __ftol                                           undefined __ftol()
//         00450ca7     MOV        word ptr [ESI + 0x110],AX
//                              m_co_obj.cpp:468 (6)
//         00450cae     POP        EDI
//         00450caf     POP        ESI
//         00450cb0     POP        EBX
//         00450cb1     RET        0x8
//                               switchD_00450b5c::caseD_d                                    XREF[6]:     00450b56(j), 00450b5c(j),
//                               switchD_00450b5c::caseD_e                                                 00450ccc(*), 00450ce4(*),
//                               switchD_00450b5c::caseD_11                                                00450ce8(*), 00450cf4(*)
//                               switchD_00450b5c::caseD_7
//                              m_co_obj.cpp:465 (13)
//         00450cb4     MOV        EDX,dword ptr [ESP + param_1]
//         00450cb8     PUSH       this
//         00450cb9     PUSH       EDX
//         00450cba     MOV        this,ESI
//         00450cbc     CALL       RGE_Master_Action_Object::modify_delta           void modify_delta(RGE_Master_Action_Object *
//                               LAB_00450cc1                                                 XREF[4]:     00450b78(j), 00450b89(j),
//                                                                                                         00450bc7(j), 00450bd8(j)
//                              m_co_obj.cpp:468 (59)
//         00450cc1     POP        EDI
//         00450cc2     POP        ESI
//         00450cc3     POP        EBX
//         00450cc4     RET        0x8
//         00450cc7     ??         90h
//                              Symbol Ref: No symbol: NONAME
//                               switchD_00450b5c::switchdataD_00450cc8                       XREF[1]:     modify_delta:00450b5c(*)
//         00450cc8     addr       switchD_00450b5c::caseD_6
//         00450ccc     addr       switchD_00450b5c::caseD_7
//         00450cd0     addr       switchD_00450b5c::caseD_8
//         00450cd4     addr       switchD_00450b5c::caseD_9
//         00450cd8     addr       switchD_00450b5c::caseD_a
//         00450cdc     addr       switchD_00450b5c::caseD_b
//         00450ce0     addr       switchD_00450b5c::caseD_c
//         00450ce4     addr       switchD_00450b5c::caseD_7
//         00450ce8     addr       switchD_00450b5c::caseD_7
//         00450cec     addr       switchD_00450b5c::caseD_f
//         00450cf0     addr       switchD_00450b5c::caseD_10
//         00450cf4     addr       switchD_00450b5c::caseD_7
//         00450cf8     addr       switchD_00450b5c::caseD_12
//         00450cfc     ??         90h
//         00450cfd     ??         90h
//         00450cfe     ??         90h
//         00450cff     ??         90h
    return;
}

void RGE_Master_Combat_Object::modify_percent(float param_1, uchar param_2) {
    /* TODO: Stub */
//                              void __thiscall modify_percent(RGE_Master_Combat_Object * this, floa
//              void              <VOID>         <RETURN>
//              RGE_Master_Com    ECX:4 (auto)   this
//              float             Stack[0x4]:4   param_1                   XREF[8]:     00450d21(R), 00450d35(R), 00450d58(R), 00450d6c(R),
//                                                                                     00450d8f(R), 00450db1(R), 00450dc5(R), 00450dda(R)
//              uchar             Stack[0x8]:1   param_2                   XREF[7]:     00450d03(R), 00450d50(W), 00450d54(R), 00450d87(W),
//                                                                                     00450d8b(R), 00450da9(W), 00450dad(R)
//                               ?modify_percent@RGE_Master_Combat_Object@@UAEXME@Z           XREF[3]:     modify_percent:00451994(c),
//                               RGE_Master_Combat_Object::modify_percent                                  modify_percent:0050efce(c),
//                                                                                                         005704d0(*)
//                              m_co_obj.cpp:472 (3)
//         00450d00     PUSH       ESI
//         00450d01     MOV        ESI,this
//                              m_co_obj.cpp:473 (30)
//         00450d03     MOV        this,dword ptr [ESP + param_2]
//         00450d07     MOV        EAX,this
//         00450d09     AND        EAX,0xff
//         00450d0e     ADD        EAX,-0x6
//         00450d11     CMP        EAX,0xc
//         00450d14     JA         switchD_00450d1a::caseD_7
//                               switchD_00450d1a::switchD
//         00450d1a     JMP        dword ptr [EAX*0x4 + switchD_00450d1a::switchd   = 00450d21
//                               switchD_00450d1a::caseD_6                                    XREF[2]:     00450d1a(j), 00450dec(*)
//                              m_co_obj.cpp:480 (16)
//         00450d21     FLD        float ptr [ESP + param_1]
//         00450d25     FMUL       float ptr [ESI + 0xc4]
//         00450d2b     FSTP       float ptr [ESI + 0xc4]
//                              m_co_obj.cpp:504 (4)
//         00450d31     POP        ESI
//         00450d32     RET        0x8
//                               switchD_00450d1a::caseD_a                                    XREF[2]:     00450d1a(j), 00450dfc(*)
//                              m_co_obj.cpp:483 (16)
//         00450d35     FLD        float ptr [ESP + param_1]
//         00450d39     FMUL       float ptr [ESI + 0x120]
//         00450d3f     FSTP       float ptr [ESI + 0x120]
//                              m_co_obj.cpp:504 (4)
//         00450d45     POP        ESI
//         00450d46     RET        0x8
//                               switchD_00450d1a::caseD_b                                    XREF[2]:     00450d1a(j), 00450e00(*)
//                              m_co_obj.cpp:486 (31)
//         00450d49     MOVSX      this,word ptr [ESI + 0x126]
//         00450d50     MOV        dword ptr [ESP + param_2],this
//         00450d54     FILD       dword ptr [ESP + param_2]
//         00450d58     FMUL       float ptr [ESP + param_1]
//         00450d5c     CALL       __ftol                                           undefined __ftol()
//         00450d61     MOV        word ptr [ESI + 0x126],AX
//                              m_co_obj.cpp:504 (4)
//         00450d68     POP        ESI
//         00450d69     RET        0x8
//                               switchD_00450d1a::caseD_c                                    XREF[2]:     00450d1a(j), 00450e04(*)
//                              m_co_obj.cpp:489 (16)
//         00450d6c     FLD        float ptr [ESP + param_1]
//         00450d70     FMUL       float ptr [ESI + 0x114]
//         00450d76     FSTP       float ptr [ESI + 0x114]
//                              m_co_obj.cpp:504 (4)
//         00450d7c     POP        ESI
//         00450d7d     RET        0x8
//                               switchD_00450d1a::caseD_f                                    XREF[2]:     00450d1a(j), 00450e10(*)
//                              m_co_obj.cpp:492 (30)
//         00450d80     MOVSX      EDX,word ptr [ESI + 0x124]
//         00450d87     MOV        dword ptr [ESP + param_2],EDX
//         00450d8b     FILD       dword ptr [ESP + param_2]
//         00450d8f     FMUL       float ptr [ESP + param_1]
//         00450d93     CALL       __ftol                                           undefined __ftol()
//         00450d98     MOV        byte ptr [ESI + 0x100],AL
//                              m_co_obj.cpp:504 (4)
//         00450d9e     POP        ESI
//         00450d9f     RET        0x8
//                               switchD_00450d1a::caseD_10                                   XREF[2]:     00450d1a(j), 00450e14(*)
//                              m_co_obj.cpp:495 (31)
//         00450da2     MOVSX      EAX,word ptr [ESI + 0x124]
//         00450da9     MOV        dword ptr [ESP + param_2],EAX
//         00450dad     FILD       dword ptr [ESP + param_2]
//         00450db1     FMUL       float ptr [ESP + param_1]
//         00450db5     CALL       __ftol                                           undefined __ftol()
//         00450dba     MOV        word ptr [ESI + 0x124],AX
//                              m_co_obj.cpp:504 (4)
//         00450dc1     POP        ESI
//         00450dc2     RET        0x8
//                               switchD_00450d1a::caseD_12                                   XREF[2]:     00450d1a(j), 00450e1c(*)
//                              m_co_obj.cpp:498 (16)
//         00450dc5     FLD        float ptr [ESP + param_1]
//         00450dc9     CALL       __ftol                                           undefined __ftol()
//         00450dce     MOV        word ptr [ESI + 0x110],AX
//                              m_co_obj.cpp:504 (4)
//         00450dd5     POP        ESI
//         00450dd6     RET        0x8
//                               switchD_00450d1a::caseD_d                                    XREF[6]:     00450d14(j), 00450d1a(j),
//                               switchD_00450d1a::caseD_e                                                 00450df0(*), 00450e08(*),
//                               switchD_00450d1a::caseD_11                                                00450e0c(*), 00450e18(*)
//                               switchD_00450d1a::caseD_7
//                              m_co_obj.cpp:501 (13)
//         00450dd9     PUSH       this
//         00450dda     MOV        this,dword ptr [ESP + param_1]
//         00450dde     PUSH       this
//         00450ddf     MOV        this,ESI
//         00450de1     CALL       RGE_Master_Action_Object::modify_percent         void modify_percent(RGE_Master_Action_Object
//                               switchD_00450d1a::caseD_9                                    XREF[3]:     00450d1a(j), 00450df4(*),
//                               switchD_00450d1a::caseD_8                                                 00450df8(*)
//                              m_co_obj.cpp:504 (58)
//         00450de6     POP        ESI
//         00450de7     RET        0x8
    return;
}

void RGE_Master_Combat_Object::save(int param_1) {
    /* TODO: Stub */
//                              void __thiscall save(RGE_Master_Combat_Object * this, int param_1)
//              void              <VOID>         <RETURN>
//              RGE_Master_Com    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[4]:     00450e23(R), 00450e3d(W), 00450e43(W), 00450fa1(*)
//                               ?save@RGE_Master_Combat_Object@@UAEXH@Z                      XREF[3]:     save:004519a9(c),
//                               RGE_Master_Combat_Object::save                                            save:0050f01b(c), 005704d4(*)
//                              m_co_obj.cpp:509 (3)
//         00450e20     PUSH       EBX
//         00450e21     PUSH       ESI
//         00450e22     PUSH       EDI
//                              m_co_obj.cpp:512 (12)
//         00450e23     MOV        EDI,dword ptr [ESP + param_1]
//         00450e27     MOV        ESI,this
//         00450e29     PUSH       EDI
//         00450e2a     CALL       RGE_Master_Action_Object::save                   void save(RGE_Master_Action_Object * this, in
//                              m_co_obj.cpp:514 (28)
//         00450e2f     MOV        EAX,dword ptr [ESI + 0xfc]
//         00450e35     TEST       EAX,EAX
//         00450e37     JZ         LAB_00450e43
//         00450e39     MOV        AX,word ptr [EAX + 0x72]
//         00450e3d     MOV        dword ptr [ESP + param_1],EAX
//         00450e41     JMP        LAB_00450e4b
//                               LAB_00450e43                                                 XREF[1]:     00450e37(j)
//         00450e43     MOV        dword ptr [ESP + param_1],0xffffffff
//                               LAB_00450e4b                                                 XREF[1]:     00450e41(j)
//                              m_co_obj.cpp:518 (18)
//         00450e4b     LEA        this,[ESI + 0x100]
//         00450e51     PUSH       0x1
//         00450e53     PUSH       this
//         00450e54     PUSH       EDI
//         00450e55     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         00450e5a     ADD        ESP,0xc
//                              m_co_obj.cpp:519 (15)
//         00450e5d     LEA        EBX,[ESI + 0x108]
//         00450e63     PUSH       0x2
//         00450e65     PUSH       EBX
//         00450e66     PUSH       EDI
//         00450e67     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//                              m_co_obj.cpp:520 (13)
//         00450e6c     MOV        EAX,dword ptr [ESI + 0x10c]
//         00450e72     ADD        ESP,0xc
//         00450e75     TEST       EAX,EAX
//         00450e77     JZ         LAB_00450e8a
//                              m_co_obj.cpp:521 (17)
//         00450e79     MOVSX      EDX,word ptr [EBX]
//         00450e7c     SHL        EDX,0x2
//         00450e7f     PUSH       EDX
//         00450e80     PUSH       EAX
//         00450e81     PUSH       EDI
//         00450e82     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         00450e87     ADD        ESP,0xc
//                               LAB_00450e8a                                                 XREF[1]:     00450e77(j)
//                              m_co_obj.cpp:522 (15)
//         00450e8a     LEA        EBX,[ESI + 0x102]
//         00450e90     PUSH       0x2
//         00450e92     PUSH       EBX
//         00450e93     PUSH       EDI
//         00450e94     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//                              m_co_obj.cpp:523 (13)
//         00450e99     MOV        EAX,dword ptr [ESI + 0x104]
//         00450e9f     ADD        ESP,0xc
//         00450ea2     TEST       EAX,EAX
//         00450ea4     JZ         LAB_00450eb7
//                              m_co_obj.cpp:524 (17)
//         00450ea6     MOVSX      this,word ptr [EBX]
//         00450ea9     SHL        this,0x2
//         00450eac     PUSH       this
//         00450ead     PUSH       EAX
//         00450eae     PUSH       EDI
//         00450eaf     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         00450eb4     ADD        ESP,0xc
//                               LAB_00450eb7                                                 XREF[1]:     00450ea4(j)
//                              m_co_obj.cpp:525 (18)
//         00450eb7     LEA        EDX,[ESI + 0x110]
//         00450ebd     PUSH       0x2
//         00450ebf     PUSH       EDX
//         00450ec0     PUSH       EDI
//         00450ec1     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         00450ec6     ADD        ESP,0xc
//                              m_co_obj.cpp:526 (18)
//         00450ec9     LEA        EAX,[ESI + 0x114]
//         00450ecf     PUSH       0x4
//         00450ed1     PUSH       EAX
//         00450ed2     PUSH       EDI
//         00450ed3     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         00450ed8     ADD        ESP,0xc
//                              m_co_obj.cpp:527 (18)
//         00450edb     LEA        this,[ESI + 0x118]
//         00450ee1     PUSH       0x4
//         00450ee3     PUSH       this
//         00450ee4     PUSH       EDI
//         00450ee5     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         00450eea     ADD        ESP,0xc
//                              m_co_obj.cpp:528 (18)
//         00450eed     LEA        EDX,[ESI + 0x120]
//         00450ef3     PUSH       0x4
//         00450ef5     PUSH       EDX
//         00450ef6     PUSH       EDI
//         00450ef7     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         00450efc     ADD        ESP,0xc
//                              m_co_obj.cpp:529 (18)
//         00450eff     LEA        EAX,[ESI + 0x124]
//         00450f05     PUSH       0x2
//         00450f07     PUSH       EAX
//         00450f08     PUSH       EDI
//         00450f09     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         00450f0e     ADD        ESP,0xc
//                              m_co_obj.cpp:530 (18)
//         00450f11     LEA        this,[ESI + 0x126]
//         00450f17     PUSH       0x2
//         00450f19     PUSH       this
//         00450f1a     PUSH       EDI
//         00450f1b     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         00450f20     ADD        ESP,0xc
//                              m_co_obj.cpp:531 (18)
//         00450f23     LEA        EDX,[ESI + 0x128]
//         00450f29     PUSH       0x1
//         00450f2b     PUSH       EDX
//         00450f2c     PUSH       EDI
//         00450f2d     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         00450f32     ADD        ESP,0xc
//                              m_co_obj.cpp:532 (18)
//         00450f35     LEA        EAX,[ESI + 0x12a]
//         00450f3b     PUSH       0x2
//         00450f3d     PUSH       EAX
//         00450f3e     PUSH       EDI
//         00450f3f     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         00450f44     ADD        ESP,0xc
//                              m_co_obj.cpp:533 (18)
//         00450f47     LEA        this,[ESI + 0x12c]
//         00450f4d     PUSH       0x4
//         00450f4f     PUSH       this
//         00450f50     PUSH       EDI
//         00450f51     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         00450f56     ADD        ESP,0xc
//                              m_co_obj.cpp:534 (18)
//         00450f59     LEA        EDX,[ESI + 0x130]
//         00450f5f     PUSH       0x4
//         00450f61     PUSH       EDX
//         00450f62     PUSH       EDI
//         00450f63     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         00450f68     ADD        ESP,0xc
//                              m_co_obj.cpp:535 (18)
//         00450f6b     LEA        EAX,[ESI + 0x134]
//         00450f71     PUSH       0x4
//         00450f73     PUSH       EAX
//         00450f74     PUSH       EDI
//         00450f75     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         00450f7a     ADD        ESP,0xc
//                              m_co_obj.cpp:536 (18)
//         00450f7d     LEA        this,[ESI + 0x11c]
//         00450f83     PUSH       0x1
//         00450f85     PUSH       this
//         00450f86     PUSH       EDI
//         00450f87     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         00450f8c     ADD        ESP,0xc
//                              m_co_obj.cpp:537 (18)
//         00450f8f     LEA        EDX,[ESI + 0x138]
//         00450f95     PUSH       0x4
//         00450f97     PUSH       EDX
//         00450f98     PUSH       EDI
//         00450f99     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         00450f9e     ADD        ESP,0xc
//                              m_co_obj.cpp:538 (16)
//         00450fa1     LEA        EAX=>param_1,[ESP + 0x10]
//         00450fa5     PUSH       0x2
//         00450fa7     PUSH       EAX
//         00450fa8     PUSH       EDI
//         00450fa9     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         00450fae     ADD        ESP,0xc
//                              m_co_obj.cpp:539 (18)
//         00450fb1     LEA        this,[ESI + 0x13c]
//         00450fb7     PUSH       0x2
//         00450fb9     PUSH       this
//         00450fba     PUSH       EDI
//         00450fbb     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         00450fc0     ADD        ESP,0xc
//                              m_co_obj.cpp:540 (18)
//         00450fc3     LEA        EDX,[ESI + 0x13e]
//         00450fc9     PUSH       0x2
//         00450fcb     PUSH       EDX
//         00450fcc     PUSH       EDI
//         00450fcd     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         00450fd2     ADD        ESP,0xc
//                              m_co_obj.cpp:541 (18)
//         00450fd5     LEA        EAX,[ESI + 0x140]
//         00450fdb     PUSH       0x4
//         00450fdd     PUSH       EAX
//         00450fde     PUSH       EDI
//         00450fdf     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         00450fe4     ADD        ESP,0xc
//                              m_co_obj.cpp:542 (18)
//         00450fe7     ADD        ESI,0x144
//         00450fed     PUSH       0x4
//         00450fef     PUSH       ESI
//         00450ff0     PUSH       EDI
//         00450ff1     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         00450ff6     ADD        ESP,0xc
//                              m_co_obj.cpp:543 (6)
//         00450ff9     POP        EDI
//         00450ffa     POP        ESI
//         00450ffb     POP        EBX
//         00450ffc     RET        0x4
//         00450fff     ??         90h
    return;
}

long RGE_Master_Combat_Object::calc_base_damage_ability(RGE_Master_Combat_Object* param_1) {
    /* TODO: Stub */
//                              long __thiscall calc_base_damage_ability(RGE_Master_Combat_Object *
//              long              EAX:4          <RETURN>
//              RGE_Master_Com    ECX:4 (auto)   this
//              RGE_Master_Com    Stack[0x4]:4   param_1                   XREF[6]:     00451000(R), 0045103f(W), 00451059(W), 00451067(R),
//                                                                                     0045106b(W), 0045106f(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     00451035(W), 00451039(R)
//              undefined4        Stack[-0x8]:4  local_8                   XREF[3]:     0045102b(W), 0045108a(R), 00451092(W)
//                               ?calc_base_damage_ability@RGE_Master_Combat_Object@@UAEJPAV  XREF[4]:     005704e8(*), 00570588(*),
//                               RGE_Master_Combat_Object::calc_base_damage_ability                        00576728(*), 00576768(*)
//                              m_co_obj.cpp:549 (7)
//         00451000     MOV        EDX,dword ptr [ESP + param_1]
//         00451004     SUB        ESP,0x8
//                              m_co_obj.cpp:555 (23)
//         00451007     FLD        float ptr [DAT_00570504]
//         0045100d     MOVSX      EAX,word ptr [EDX + 0x108]
//         00451014     PUSH       EBX
//         00451015     PUSH       EBP
//         00451016     PUSH       ESI
//         00451017     PUSH       EDI
//         00451018     MOV        EDI,dword ptr [EDX + 0x10c]
//                              m_co_obj.cpp:558 (4)
//         0045101e     TEST       EAX,EAX
//         00451020     JLE        LAB_00451098
//                              m_co_obj.cpp:562 (35)
//         00451022     MOVSX      EBX,word ptr [ECX + this->armor_num]
//         00451029     XOR        EDX,EDX
//         0045102b     MOV        dword ptr [ESP + local_8],EAX
//         0045102f     MOV        DL,byte ptr [ECX + this->base_armor]
//         00451035     MOV        dword ptr [ESP + local_4],EDX
//                               LAB_00451039                                                 XREF[1]:     00451096(j)
//         00451039     MOV        EAX,dword ptr [ESP + local_4]
//         0045103d     TEST       EBX,EBX
//         0045103f     MOV        dword ptr [ESP + param_1],EAX
//         00451043     JLE        LAB_00451063
//                              m_co_obj.cpp:563 (16)
//         00451045     MOV        SI,word ptr [EDI]
//         00451048     MOV        EAX,dword ptr [ECX + this->armor]
//         0045104e     MOV        EDX,EBX
//                               LAB_00451050                                                 XREF[1]:     00451061(j)
//         00451050     CMP        word ptr [EAX],SI
//         00451053     JNZ        LAB_0045105d
//                              m_co_obj.cpp:564 (14)
//         00451055     MOVSX      EBP,word ptr [EAX + 0x2]
//         00451059     MOV        dword ptr [ESP + param_1],EBP
//                               LAB_0045105d                                                 XREF[1]:     00451053(j)
//         0045105d     ADD        EAX,0x4
//         00451060     DEC        EDX
//         00451061     JNZ        LAB_00451050
//                               LAB_00451063                                                 XREF[1]:     00451043(j)
//                              m_co_obj.cpp:568 (20)
//         00451063     MOVSX      EDX,word ptr [EDI + 0x2]
//         00451067     FILD       dword ptr [ESP + param_1]
//         0045106b     MOV        dword ptr [ESP + param_1],EDX
//         0045106f     FILD       dword ptr [ESP + param_1]
//         00451073     FXCH
//         00451075     FSUBP
//                              m_co_obj.cpp:569 (13)
//         00451077     FCOM       double ptr [DAT_00570508]
//         0045107d     FNSTSW     AX
//         0045107f     TEST       AH,0x41
//         00451082     JNZ        LAB_00451088
//                              m_co_obj.cpp:570 (2)
//         00451084     FADDP
//                              m_co_obj.cpp:569 (4)
//         00451086     JMP        LAB_0045108a
//                               LAB_00451088                                                 XREF[1]:     00451082(j)
//         00451088     FSTP       ST0
//                               LAB_0045108a                                                 XREF[1]:     00451086(j)
//                              m_co_obj.cpp:570 (14)
//         0045108a     MOV        EAX,dword ptr [ESP + local_8]
//         0045108e     ADD        EDI,0x4
//         00451091     DEC        EAX
//         00451092     MOV        dword ptr [ESP + local_8],EAX
//         00451096     JNZ        LAB_00451039
//                               LAB_00451098                                                 XREF[1]:     00451020(j)
//                              m_co_obj.cpp:573 (15)
//         00451098     FCOM       double ptr [DAT_00570510]
//         0045109e     FNSTSW     AX
//         004510a0     TEST       AH,0x1
//         004510a3     JZ         LAB_004510ad
//         004510a5     FSTP       ST0
//                              m_co_obj.cpp:574 (6)
//         004510a7     FLD        float ptr [DAT_00570518]
//                               LAB_004510ad                                                 XREF[1]:     004510a3(j)
//                              m_co_obj.cpp:576 (5)
//         004510ad     CALL       __ftol                                           undefined __ftol()
//                              m_co_obj.cpp:577 (10)
//         004510b2     POP        EDI
//         004510b3     POP        ESI
//         004510b4     POP        EBP
//         004510b5     POP        EBX
//         004510b6     ADD        ESP,0x8
//         004510b9     RET        0x4
//         004510bc     ??         90h
//         004510bd     NOP
//         004510be     NOP
//         004510bf     NOP
    return 0;
}

RGE_Master_Static_Object* RGE_Master_Combat_Object::make_new_master() {
    /* TODO: Stub */
// <NO ASSEMBLY FOUND>
    return 0;
}

