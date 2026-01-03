#include "../common.h"
#include "asprite.h"

RGE_Active_Sprite::RGE_Active_Sprite(RGE_Sprite* param_1) {
    /* TODO: Stub */
//                              undefined __thiscall RGE_Active_Sprite(RGE_Active_Sprite * this, RGE
//              undefined         <UNASSIGNED>   <RETURN>
//              RGE_Active_Spr    ECX:4 (auto)   this
//              RGE_Sprite *      Stack[0x4]:4   param_1                   XREF[1]:     0041ad22(R)
//                               ??0RGE_Active_Sprite@@QAE@PAVRGE_Sprite@@@Z                  XREF[2]:     RGE_Active_Animated_Sprite:0041b03
//                               RGE_Active_Sprite::RGE_Active_Sprite                                      make_active_sprite:004c0ffe(c)
//                              asprite.cpp:23 (2)
//         0041ad20     MOV        EAX,this
//                              asprite.cpp:25 (7)
//         0041ad22     MOV        this,dword ptr [ESP + param_1]
//         0041ad26     MOV        dword ptr [EAX + 0x4],this
//                              asprite.cpp:26 (15)
//         0041ad29     XOR        this,this
//         0041ad2b     MOV        dword ptr [EAX],RGE_Active_Sprite::`vftable'     = 0041ad40
//         0041ad31     MOV        byte ptr [EAX + 0x8],0x1
//         0041ad35     MOV        dword ptr [EAX + 0xc],this
//                              asprite.cpp:27 (3)
//         0041ad38     MOV        dword ptr [EAX + 0x10],this
//                              asprite.cpp:28 (3)
//         0041ad3b     RET        0x4
//         0041ad3e     ??         90h
//         0041ad3f     NOP
}

RGE_Active_Sprite::RGE_Active_Sprite(int param_1, RGE_Sprite** param_2) {
    /* TODO: Stub */
//                              undefined __thiscall RGE_Active_Sprite(RGE_Active_Sprite * this, int
//              undefined         <UNASSIGNED>   <RETURN>
//              RGE_Active_Spr    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[3]:     0041ad62(R), 0041ad66(*), 0041ad7f(R)
//              RGE_Sprite * *    Stack[0x8]:4   param_2                   XREF[1]:     0041ad8c(R)
//                               ??0RGE_Active_Sprite@@QAE@HPAPAVRGE_Sprite@@@Z               XREF[2]:     load_node:0041a7b6(c),
//                               RGE_Active_Sprite::RGE_Active_Sprite                                      RGE_Active_Animated_Sprite:0041b16
//                              asprite.cpp:32 (2)
//         0041ad60     PUSH       ESI
//         0041ad61     PUSH       EDI
//                              asprite.cpp:36 (29)
//         0041ad62     MOV        EDI,dword ptr [ESP + param_1]
//         0041ad66     LEA        EAX=>param_1,[ESP + 0xc]
//         0041ad6a     MOV        ESI,this
//         0041ad6c     PUSH       0x2
//         0041ad6e     PUSH       EAX
//         0041ad6f     PUSH       EDI
//         0041ad70     MOV        dword ptr [ESI],RGE_Active_Sprite::`vftable'     = 0041ad40
//         0041ad76     MOV        byte ptr [ESI + 0x8],0x1
//         0041ad7a     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//                              asprite.cpp:37 (13)
//         0041ad7f     MOV        AX,word ptr [ESP + param_1]
//         0041ad84     ADD        ESP,0xc
//         0041ad87     TEST       AX,AX
//         0041ad8a     JL         LAB_0041ad9b
//                              asprite.cpp:38 (13)
//         0041ad8c     MOV        EDX,dword ptr [ESP + param_2]
//         0041ad90     MOVSX      this,AX
//         0041ad93     MOV        EAX,dword ptr [EDX + this->_padding_*0x4]
//         0041ad96     MOV        dword ptr [ESI + 0x4],EAX
//                              asprite.cpp:39 (2)
//         0041ad99     JMP        LAB_0041ada2
//                               LAB_0041ad9b                                                 XREF[1]:     0041ad8a(j)
//                              asprite.cpp:40 (7)
//         0041ad9b     MOV        dword ptr [ESI + 0x4],0x0
//                               LAB_0041ada2                                                 XREF[1]:     0041ad99(j)
//                              asprite.cpp:41 (15)
//         0041ada2     LEA        this,[ESI + 0xc]
//         0041ada5     PUSH       0x4
//         0041ada7     PUSH       this
//         0041ada8     PUSH       EDI
//         0041ada9     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         0041adae     ADD        ESP,0xc
//                              asprite.cpp:42 (15)
//         0041adb1     LEA        EDX,[ESI + 0x10]
//         0041adb4     PUSH       0x4
//         0041adb6     PUSH       EDX
//         0041adb7     PUSH       EDI
//         0041adb8     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         0041adbd     ADD        ESP,0xc
//                              asprite.cpp:43 (7)
//         0041adc0     MOV        EAX,ESI
//         0041adc2     POP        EDI
//         0041adc3     POP        ESI
//         0041adc4     RET        0x8
//         0041adc7     ??         90h
//         0041adc8     NOP
//         0041adc9     NOP
//         0041adca     NOP
//         0041adcb     NOP
//         0041adcc     NOP
//         0041adcd     NOP
//         0041adce     NOP
//         0041adcf     NOP
}

RGE_Active_Sprite::~RGE_Active_Sprite() {
    /* TODO: Stub */
//                              void __thiscall ~RGE_Active_Sprite(RGE_Active_Sprite * this)
//              void              <VOID>         <RETURN>
//              RGE_Active_Spr    ECX:4 (auto)   this
//                               ??1RGE_Active_Sprite@@UAE@XZ                                 XREF[3]:     `scalar_deleting_destructor':0041a
//                               RGE_Active_Sprite::~RGE_Active_Sprite                                     ~RGE_Active_Animated_Sprite:0041b2
//                                                                                                         FUN_0055c980:0055c983(c)
//                              asprite.cpp:47 (6)
//         0041add0     MOV        dword ptr [this->_padding_],RGE_Active_Sprite:   = 0041ad40
//                              asprite.cpp:48 (1)
//         0041add6     RET
//         0041add7     ??         90h
//         0041add8     NOP
//         0041add9     NOP
//         0041adda     NOP
//         0041addb     NOP
//         0041addc     NOP
//         0041addd     NOP
//         0041adde     NOP
//         0041addf     NOP
}

void RGE_Active_Sprite::set_offset(long param_1, long param_2) {
    /* TODO: Stub */
//                              void __thiscall set_offset(RGE_Active_Sprite * this, long param_1, l
//              void              <VOID>         <RETURN>
//              RGE_Active_Spr    ECX:4 (auto)   this
//              long              Stack[0x4]:4   param_1                   XREF[1]:     0041ade0(R)
//              long              Stack[0x8]:4   param_2                   XREF[1]:     0041ade4(R)
//                               ?set_offset@RGE_Active_Sprite@@UAEXJJ@Z                      XREF[2]:     0056ee3c(*), 0056ee94(*)
//                               RGE_Active_Sprite::set_offset
//                              asprite.cpp:52 (4)
//         0041ade0     MOV        EAX,dword ptr [ESP + param_1]
//                              asprite.cpp:54 (10)
//         0041ade4     MOV        EDX,dword ptr [ESP + param_2]
//         0041ade8     MOV        dword ptr [ECX + this->offset_x],EAX
//         0041adeb     MOV        dword ptr [ECX + this->offset_y],EDX
//                              asprite.cpp:55 (3)
//         0041adee     RET        0x8
//         0041adf1     ??         90h
//         0041adf2     NOP
//         0041adf3     NOP
//         0041adf4     NOP
//         0041adf5     NOP
//         0041adf6     NOP
//         0041adf7     NOP
//         0041adf8     NOP
//         0041adf9     NOP
//         0041adfa     NOP
//         0041adfb     NOP
//         0041adfc     NOP
//         0041adfd     NOP
//         0041adfe     NOP
//         0041adff     NOP
    return;
}

void RGE_Active_Sprite::save(int param_1) {
    /* TODO: Stub */
//                              void __thiscall save(RGE_Active_Sprite * this, int param_1)
//              void              <VOID>         <RETURN>
//              RGE_Active_Spr    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     0041ae04(R)
//                               ?save@RGE_Active_Sprite@@UAEXH@Z                             XREF[2]:     save:0041b219(c), 0056ee40(*)
//                               RGE_Active_Sprite::save
//                              asprite.cpp:59 (4)
//         0041ae00     PUSH       ESI
//         0041ae01     MOV        ESI,this
//         0041ae03     PUSH       EDI
//                              asprite.cpp:67 (16)
//         0041ae04     MOV        EDI,dword ptr [ESP + param_1]
//         0041ae08     LEA        EAX,[ESI + 0x8]
//         0041ae0b     PUSH       0x1
//         0041ae0d     PUSH       EAX
//         0041ae0e     PUSH       EDI
//         0041ae0f     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//                              asprite.cpp:68 (21)
//         0041ae14     MOV        this,dword ptr [ESI + 0x4]
//         0041ae17     ADD        ESP,0xc
//         0041ae1a     ADD        this,0x72
//         0041ae1d     PUSH       0x2
//         0041ae1f     PUSH       this
//         0041ae20     PUSH       EDI
//         0041ae21     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         0041ae26     ADD        ESP,0xc
//                              asprite.cpp:69 (15)
//         0041ae29     LEA        EDX,[ESI + 0xc]
//         0041ae2c     PUSH       0x4
//         0041ae2e     PUSH       EDX
//         0041ae2f     PUSH       EDI
//         0041ae30     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         0041ae35     ADD        ESP,0xc
//                              asprite.cpp:70 (15)
//         0041ae38     ADD        ESI,0x10
//         0041ae3b     PUSH       0x4
//         0041ae3d     PUSH       ESI
//         0041ae3e     PUSH       EDI
//         0041ae3f     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         0041ae44     ADD        ESP,0xc
//                              asprite.cpp:71 (5)
//         0041ae47     POP        EDI
//         0041ae48     POP        ESI
//         0041ae49     RET        0x4
//         0041ae4c     ??         90h
//         0041ae4d     NOP
//         0041ae4e     NOP
//         0041ae4f     NOP
    return;
}

void RGE_Active_Sprite::update(float param_1, float param_2) {
    /* TODO: Stub */
//                              void __thiscall update(RGE_Active_Sprite * this, float param_1, floa
//              void              <VOID>         <RETURN>
//              RGE_Active_Spr    ECX:4 (auto)   this
//              float             Stack[0x4]:4   param_1
//              float             Stack[0x8]:4   param_2
//                               ?update@RGE_Active_Sprite@@UAEXMM@Z                          XREF[1]:     0056ee44(*)
//                               RGE_Active_Sprite::update
//                              asprite.cpp:75 (3)
//         0041ae50     RET        0x8
//         0041ae53     ??         90h
//         0041ae54     NOP
//         0041ae55     NOP
//         0041ae56     NOP
//         0041ae57     NOP
//         0041ae58     NOP
//         0041ae59     NOP
//         0041ae5a     NOP
//         0041ae5b     NOP
//         0041ae5c     NOP
//         0041ae5d     NOP
//         0041ae5e     NOP
//         0041ae5f     NOP
    return;
}

void RGE_Active_Sprite::draw(short param_1, long param_2, long param_3, long param_4, long param_5, RGE_Color_Table* param_6, TDrawArea* param_7) {
    /* TODO: Stub */
//                              void __thiscall draw(RGE_Active_Sprite * this, short param_1, long p
//              void              <VOID>         <RETURN>
//              RGE_Active_Spr    ECX:4 (auto)   this
//              short             Stack[0x4]:2   param_1                   XREF[1]:     0041ae91(R)
//              long              Stack[0x8]:4   param_2                   XREF[1]:     0041ae8a(R)
//              long              Stack[0xc]:4   param_3                   XREF[1]:     0041ae84(R)
//              long              Stack[0x10]:4  param_4                   XREF[1]:     0041ae7d(R)
//              long              Stack[0x14]:4  param_5                   XREF[1]:     0041ae73(R)
//              RGE_Color_Tabl    Stack[0x18]:4  param_6                   XREF[1]:     0041ae6b(R)
//              TDrawArea *       Stack[0x1c]:4  param_7                   XREF[1]:     0041ae64(R)
//                               ?draw@RGE_Active_Sprite@@UAEXFJJJJPAVRGE_Color_Table@@PAVTD  XREF[1]:     0056ee48(*)
//                               RGE_Active_Sprite::draw
//                              asprite.cpp:80 (63)
//         0041ae60     MOV        EAX,dword ptr [ECX + this->offset_y]
//         0041ae63     PUSH       ESI
//         0041ae64     MOV        ESI,dword ptr [ESP + param_7]
//         0041ae68     PUSH       0x0
//         0041ae6a     PUSH       ESI
//         0041ae6b     MOV        ESI,dword ptr [ESP + param_6]
//         0041ae6f     MOV        EDX,dword ptr [ECX + this->offset_x]
//         0041ae72     PUSH       ESI
//         0041ae73     MOV        ESI,dword ptr [ESP + param_5]
//         0041ae77     MOV        this,dword ptr [ECX + this->sprite]
//         0041ae7a     ADD        ESI,EAX
//         0041ae7c     PUSH       ESI
//         0041ae7d     MOV        ESI,dword ptr [ESP + param_4]
//         0041ae81     ADD        ESI,EDX
//         0041ae83     PUSH       ESI
//         0041ae84     MOV        ESI,dword ptr [ESP + param_3]
//         0041ae88     ADD        ESI,EAX
//         0041ae8a     MOV        EAX,dword ptr [ESP + param_2]
//         0041ae8e     ADD        EAX,EDX
//         0041ae90     PUSH       ESI
//         0041ae91     MOVSX      EDX,word ptr [ESP + param_1]
//         0041ae96     PUSH       EAX
//         0041ae97     PUSH       0x0
//         0041ae99     PUSH       EDX
//         0041ae9a     CALL       RGE_Sprite::draw                                 uchar draw(RGE_Sprite * this, long param_1, l
//                              asprite.cpp:82 (4)
//         0041ae9f     POP        ESI
//         0041aea0     RET        0x1c
//         0041aea3     ??         90h
//         0041aea4     NOP
//         0041aea5     NOP
//         0041aea6     NOP
//         0041aea7     NOP
//         0041aea8     NOP
//         0041aea9     NOP
//         0041aeaa     NOP
//         0041aeab     NOP
//         0041aeac     NOP
//         0041aead     NOP
//         0041aeae     NOP
//         0041aeaf     NOP
    return;
}

void RGE_Active_Sprite::normal_draw(short param_1, long param_2, long param_3, RGE_Color_Table* param_4, TDrawArea* param_5) {
    /* TODO: Stub */
//                              void __thiscall normal_draw(RGE_Active_Sprite * this, short param_1,
//              void              <VOID>         <RETURN>
//              RGE_Active_Spr    ECX:4 (auto)   this
//              short             Stack[0x4]:2   param_1                   XREF[1]:     0041aed0(R)
//              long              Stack[0x8]:4   param_2                   XREF[1]:     0041aec7(R)
//              long              Stack[0xc]:4   param_3                   XREF[1]:     0041aebd(R)
//              RGE_Color_Tabl    Stack[0x10]:4  param_4                   XREF[1]:     0041aeb4(R)
//              TDrawArea *       Stack[0x14]:4  param_5                   XREF[1]:     0041aeb0(R)
//                               ?normal_draw@RGE_Active_Sprite@@UAEXFJJPAVRGE_Color_Table@@  XREF[1]:     0056ee4c(*)
//                               RGE_Active_Sprite::normal_draw
//                              asprite.cpp:86 (46)
//         0041aeb0     MOV        EAX,dword ptr [ESP + param_5]
//         0041aeb4     MOV        EDX,dword ptr [ESP + param_4]
//         0041aeb8     PUSH       EAX
//         0041aeb9     MOV        EAX,dword ptr [ECX + this->offset_y]
//         0041aebc     PUSH       EDX
//         0041aebd     MOV        EDX,dword ptr [ESP + param_3]
//         0041aec1     ADD        EAX,EDX
//         0041aec3     MOV        EDX,dword ptr [ECX + this->offset_x]
//         0041aec6     PUSH       EAX
//         0041aec7     MOV        EAX,dword ptr [ESP + param_2]
//         0041aecb     MOV        this,dword ptr [ECX + this->sprite]
//         0041aece     ADD        EDX,EAX
//         0041aed0     MOVSX      EAX,word ptr [ESP + param_1]
//         0041aed5     PUSH       EDX
//         0041aed6     PUSH       0x0
//         0041aed8     PUSH       EAX
//         0041aed9     CALL       RGE_Sprite::normal_draw                          uchar normal_draw(RGE_Sprite * this, long par
//                              asprite.cpp:88 (3)
//         0041aede     RET        0x14
//         0041aee1     ??         90h
//         0041aee2     NOP
//         0041aee3     NOP
//         0041aee4     NOP
//         0041aee5     NOP
//         0041aee6     NOP
//         0041aee7     NOP
//         0041aee8     NOP
//         0041aee9     NOP
//         0041aeea     NOP
//         0041aeeb     NOP
//         0041aeec     NOP
//         0041aeed     NOP
//         0041aeee     NOP
//         0041aeef     NOP
    return;
}

void RGE_Active_Sprite::shadow_draw(short param_1, long param_2, long param_3, RGE_Color_Table* param_4, TDrawArea* param_5, uchar param_6) {
    /* TODO: Stub */
//                              void __thiscall shadow_draw(RGE_Active_Sprite * this, short param_1,
//              void              <VOID>         <RETURN>
//              RGE_Active_Spr    ECX:4 (auto)   this
//              short             Stack[0x4]:2   param_1                   XREF[1]:     0041af15(R)
//              long              Stack[0x8]:4   param_2                   XREF[1]:     0041af0c(R)
//              long              Stack[0xc]:4   param_3                   XREF[1]:     0041af02(R)
//              RGE_Color_Tabl    Stack[0x10]:4  param_4                   XREF[1]:     0041aef9(R)
//              TDrawArea *       Stack[0x14]:4  param_5                   XREF[1]:     0041aef4(R)
//              uchar             Stack[0x18]:1  param_6                   XREF[1]:     0041aef0(R)
//                               ?shadow_draw@RGE_Active_Sprite@@UAEXFJJPAVRGE_Color_Table@@  XREF[1]:     0056ee50(*)
//                               RGE_Active_Sprite::shadow_draw
//                              asprite.cpp:92 (51)
//         0041aef0     MOV        EAX,dword ptr [ESP + param_6]
//         0041aef4     MOV        EDX,dword ptr [ESP + param_5]
//         0041aef8     PUSH       EAX
//         0041aef9     MOV        EAX,dword ptr [ESP + param_4]
//         0041aefd     PUSH       EDX
//         0041aefe     MOV        EDX,dword ptr [ECX + this->offset_y]
//         0041af01     PUSH       EAX
//         0041af02     MOV        EAX,dword ptr [ESP + param_3]
//         0041af06     ADD        EDX,EAX
//         0041af08     MOV        EAX,dword ptr [ECX + this->offset_x]
//         0041af0b     PUSH       EDX
//         0041af0c     MOV        EDX,dword ptr [ESP + param_2]
//         0041af10     MOV        this,dword ptr [ECX + this->sprite]
//         0041af13     ADD        EAX,EDX
//         0041af15     MOVSX      EDX,word ptr [ESP + param_1]
//         0041af1a     PUSH       EAX
//         0041af1b     PUSH       0x0
//         0041af1d     PUSH       EDX
//         0041af1e     CALL       RGE_Sprite::shadow_draw                          uchar shadow_draw(RGE_Sprite * this, long par
//                              asprite.cpp:94 (3)
//         0041af23     RET        0x18
//         0041af26     ??         90h
//         0041af27     NOP
//         0041af28     NOP
//         0041af29     NOP
//         0041af2a     NOP
//         0041af2b     NOP
//         0041af2c     NOP
//         0041af2d     NOP
//         0041af2e     NOP
//         0041af2f     NOP
    return;
}

short RGE_Active_Sprite::what_frame() {
    /* TODO: Stub */
//                              short __thiscall what_frame(RGE_Active_Sprite * this)
//              short             AX:2           <RETURN>
//              RGE_Active_Spr    ECX:4 (auto)   this
//                               ?what_frame@RGE_Active_Sprite@@UAEFXZ                        XREF[1]:     0056ee54(*)
//                               RGE_Active_Sprite::what_frame
//                              asprite.cpp:98 (3)
//         0041af30     XOR        AX,AX
//                              asprite.cpp:100 (1)
//         0041af33     RET
//         0041af34     ??         90h
//         0041af35     NOP
//         0041af36     NOP
//         0041af37     NOP
//         0041af38     NOP
//         0041af39     NOP
//         0041af3a     NOP
//         0041af3b     NOP
//         0041af3c     NOP
//         0041af3d     NOP
//         0041af3e     NOP
//         0041af3f     NOP
    return 0;
}

void RGE_Active_Sprite::set_frame(short param_1) {
    /* TODO: Stub */
//                              void __thiscall set_frame(RGE_Active_Sprite * this, short param_1)
//              void              <VOID>         <RETURN>
//              RGE_Active_Spr    ECX:4 (auto)   this
//              short             Stack[0x4]:2   param_1
//                               ?set_frame@RGE_Active_Sprite@@UAEXF@Z                        XREF[1]:     0056ee5c(*)
//                               RGE_Active_Sprite::set_frame
//                              asprite.cpp:104 (3)
//         0041af40     RET        0x4
//         0041af43     ??         90h
//         0041af44     NOP
//         0041af45     NOP
//         0041af46     NOP
//         0041af47     NOP
//         0041af48     NOP
//         0041af49     NOP
//         0041af4a     NOP
//         0041af4b     NOP
//         0041af4c     NOP
//         0041af4d     NOP
//         0041af4e     NOP
//         0041af4f     NOP
    return;
}

uchar RGE_Active_Sprite::is_animating() {
    /* TODO: Stub */
//                              uchar __thiscall is_animating(RGE_Active_Sprite * this)
//              uchar             AL:1           <RETURN>
//              RGE_Active_Spr    ECX:4 (auto)   this
//                               ?is_animating@RGE_Active_Sprite@@UAEEXZ                      XREF[1]:     0056ee58(*)
//                               RGE_Active_Sprite::is_animating
//                              asprite.cpp:109 (2)
//         0041af50     XOR        AL,AL
//                              asprite.cpp:111 (1)
//         0041af52     RET
//         0041af53     ??         90h
//         0041af54     NOP
//         0041af55     NOP
//         0041af56     NOP
//         0041af57     NOP
//         0041af58     NOP
//         0041af59     NOP
//         0041af5a     NOP
//         0041af5b     NOP
//         0041af5c     NOP
//         0041af5d     NOP
//         0041af5e     NOP
//         0041af5f     NOP
    return 0;
}

uchar RGE_Active_Sprite::frame_passed(short param_1) {
    /* TODO: Stub */
//                              uchar __thiscall frame_passed(RGE_Active_Sprite * this, short param_1)
//              uchar             AL:1           <RETURN>
//              RGE_Active_Spr    ECX:4 (auto)   this
//              short             Stack[0x4]:2   param_1
//                               ?frame_passed@RGE_Active_Sprite@@UAEEF@Z                     XREF[1]:     0056ee60(*)
//                               RGE_Active_Sprite::frame_passed
//                              asprite.cpp:115 (2)
//         0041af60     XOR        AL,AL
//                              asprite.cpp:117 (3)
//         0041af62     RET        0x4
//         0041af65     ??         90h
//         0041af66     NOP
//         0041af67     NOP
//         0041af68     NOP
//         0041af69     NOP
//         0041af6a     NOP
//         0041af6b     NOP
//         0041af6c     NOP
//         0041af6d     NOP
//         0041af6e     NOP
//         0041af6f     NOP
    return 0;
}

uchar RGE_Active_Sprite::looped() {
    /* TODO: Stub */
//                              uchar __thiscall looped(RGE_Active_Sprite * this)
//              uchar             AL:1           <RETURN>
//              RGE_Active_Spr    ECX:4 (auto)   this
//                               ?looped@RGE_Active_Sprite@@UAEEXZ                            XREF[1]:     0056ee64(*)
//                               RGE_Active_Sprite::looped
//                              asprite.cpp:121 (2)
//         0041af70     XOR        AL,AL
//                              asprite.cpp:123 (1)
//         0041af72     RET
//         0041af73     ??         90h
//         0041af74     NOP
//         0041af75     NOP
//         0041af76     NOP
//         0041af77     NOP
//         0041af78     NOP
//         0041af79     NOP
//         0041af7a     NOP
//         0041af7b     NOP
//         0041af7c     NOP
//         0041af7d     NOP
//         0041af7e     NOP
//         0041af7f     NOP
    return 0;
}

short RGE_Active_Sprite::get_facetindex(short param_1) {
    /* TODO: Stub */
//                              short __thiscall get_facetindex(RGE_Active_Sprite * this, short para
//              short             AX:2           <RETURN>
//              RGE_Active_Spr    ECX:4 (auto)   this
//              short             Stack[0x4]:2   param_1                   XREF[1]:     0041af81(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[3]:     0041af89(*), 0041af91(W), 0041af9e(*)
//              long              Stack[-0x8]:4  facet_index
//                               ?get_facetindex@RGE_Active_Sprite@@UAEFF@Z                   XREF[1]:     0056ee68(*)
//                               RGE_Active_Sprite::get_facetindex
//                              asprite.cpp:127 (1)
//         0041af80     PUSH       this
//                              asprite.cpp:130 (29)
//         0041af81     MOVSX      EDX,word ptr [ESP + param_1]
//         0041af86     MOV        this,dword ptr [ECX + this->sprite]
//         0041af89     LEA        EAX=>local_4,[ESP]
//         0041af8d     PUSH       EAX
//         0041af8e     PUSH       0x0
//         0041af90     PUSH       EDX
//         0041af91     MOV        dword ptr [ESP + local_4],0x0
//         0041af99     CALL       RGE_Sprite::get_facetindex                       uchar get_facetindex(RGE_Sprite * this, long
//                              asprite.cpp:132 (5)
//         0041af9e     MOV        AX,word ptr [ESP]=>local_4
//                              asprite.cpp:133 (4)
//         0041afa3     POP        this
//         0041afa4     RET        0x4
//         0041afa7     ??         90h
//         0041afa8     NOP
//         0041afa9     NOP
//         0041afaa     NOP
//         0041afab     NOP
//         0041afac     NOP
//         0041afad     NOP
//         0041afae     NOP
//         0041afaf     NOP
    return 0;
}

uchar RGE_Active_Sprite::get_frame(short* param_1, short* param_2, short* param_3, short* param_4, long param_5) {
    /* TODO: Stub */
//                              uchar __thiscall get_frame(RGE_Active_Sprite * this, short * param_1
//              uchar             AL:1           <RETURN>
//              RGE_Active_Spr    ECX:4 (auto)   this
//              short *           Stack[0x4]:4   param_1                   XREF[1]:     0041afc8(R)
//              short *           Stack[0x8]:4   param_2                   XREF[1]:     0041afc3(R)
//              short *           Stack[0xc]:4   param_3                   XREF[1]:     0041afbe(R)
//              short *           Stack[0x10]:4  param_4                   XREF[1]:     0041afb4(R)
//              long              Stack[0x14]:4  param_5                   XREF[1]:     0041afb0(R)
//                               ?get_frame@RGE_Active_Sprite@@UAEEAAF000J@Z                  XREF[1]:     0056ee6c(*)
//                               RGE_Active_Sprite::get_frame
//                              asprite.cpp:137 (35)
//         0041afb0     MOV        EAX,dword ptr [ESP + param_5]
//         0041afb4     MOV        EDX,dword ptr [ESP + param_4]
//         0041afb8     MOV        this,dword ptr [ECX + this->sprite]
//         0041afbb     PUSH       0x0
//         0041afbd     PUSH       EAX
//         0041afbe     MOV        EAX,dword ptr [ESP + param_3]
//         0041afc2     PUSH       EDX
//         0041afc3     MOV        EDX,dword ptr [ESP + param_2]
//         0041afc7     PUSH       EAX
//         0041afc8     MOV        EAX,dword ptr [ESP + param_1]
//         0041afcc     PUSH       EDX
//         0041afcd     PUSH       EAX
//         0041afce     CALL       RGE_Sprite::get_frame                            int get_frame(RGE_Sprite * this, short * para
//                              asprite.cpp:139 (3)
//         0041afd3     RET        0x14
//         0041afd6     ??         90h
//         0041afd7     NOP
//         0041afd8     NOP
//         0041afd9     NOP
//         0041afda     NOP
//         0041afdb     NOP
//         0041afdc     NOP
//         0041afdd     NOP
//         0041afde     NOP
//         0041afdf     NOP
    return 0;
}

uchar RGE_Active_Sprite::get_lowest_draw_level() {
    /* TODO: Stub */
//                              uchar __thiscall get_lowest_draw_level(RGE_Active_Sprite * this)
//              uchar             AL:1           <RETURN>
//              RGE_Active_Spr    ECX:4 (auto)   this
//                               ?get_lowest_draw_level@RGE_Active_Sprite@@QAEEXZ             XREF[1]:     get_lowest_draw_level:0041accd(c)
//                               RGE_Active_Sprite::get_lowest_draw_level
//                              asprite.cpp:143 (7)
//         0041afe0     MOV        this,dword ptr [ECX + this->sprite]
//         0041afe3     TEST       this,this
//         0041afe5     JZ         LAB_0041afec
//                              asprite.cpp:145 (5)
//         0041afe7     JMP        RGE_Sprite::get_lowest_draw_level                uchar get_lowest_draw_level(RGE_Sprite * this)
//                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
//                               LAB_0041afec                                                 XREF[1]:     0041afe5(j)
//                              asprite.cpp:147 (2)
//         0041afec     MOV        AL,0x14
//                              asprite.cpp:148 (1)
//         0041afee     RET
//         0041afef     ??         90h
    return 0;
}

void RGE_Active_Sprite::setToFirstFrame() {
    /* TODO: Stub */
//                              void __thiscall setToFirstFrame(RGE_Active_Sprite * this)
//              void              <VOID>         <RETURN>
//              RGE_Active_Spr    ECX:4 (auto)   this
//                               ?setToFirstFrame@RGE_Active_Sprite@@UAEXXZ                   XREF[1]:     0056ee70(*)
//                               RGE_Active_Sprite::setToFirstFrame
//                              asprite.cpp:153 (1)
//         0041aff0     RET
//         0041aff1     ??         90h
//         0041aff2     NOP
//         0041aff3     NOP
//         0041aff4     NOP
//         0041aff5     NOP
//         0041aff6     NOP
//         0041aff7     NOP
//         0041aff8     NOP
//         0041aff9     NOP
//         0041affa     NOP
//         0041affb     NOP
//         0041affc     NOP
//         0041affd     NOP
//         0041affe     NOP
//         0041afff     NOP
    return;
}

int RGE_Active_Sprite::check_for_shadows() {
    /* TODO: Stub */
//                              int __thiscall check_for_shadows(RGE_Active_Sprite * this)
//              int               EAX:4          <RETURN>
//              RGE_Active_Spr    ECX:4 (auto)   this
//                               ?check_for_shadows@RGE_Active_Sprite@@QAEHXZ                 XREF[3]:     delete_list:0041a871(c),
//                               RGE_Active_Sprite::check_for_shadows                                      remove_sprite:0041a9f0(c),
//                                                                                                         check_for_shadows:0041acfa(c)
//                              asprite.cpp:158 (7)
//         0041b000     MOV        this,dword ptr [ECX + this->sprite]
//         0041b003     TEST       this,this
//         0041b005     JZ         LAB_0041b00c
//                              asprite.cpp:160 (5)
//         0041b007     JMP        RGE_Sprite::check_for_shadows                    int check_for_shadows(RGE_Sprite * this)
//                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
//                               LAB_0041b00c                                                 XREF[1]:     0041b005(j)
//                              asprite.cpp:162 (2)
//         0041b00c     XOR        EAX,EAX
//                              asprite.cpp:163 (1)
//         0041b00e     RET
//         0041b00f     ??         90h
    return 0;
}

RGE_Active_Animated_Sprite::RGE_Active_Animated_Sprite(RGE_Sprite* param_1) {
    /* TODO: Stub */
//                              undefined __thiscall RGE_Active_Animated_Sprite(RGE_Active_Animated_
//              undefined         <UNASSIGNED>   <RETURN>
//              RGE_Active_Ani    ECX:4 (auto)   this
//              RGE_Sprite *      Stack[0x4]:4   param_1                   XREF[7]:     0041b028(R), 0041b076(W), 0041b07f(R), 0041b097(W),
//                                                                                     0041b09e(R), 0041b0d0(W), 0041b0d4(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     0041b04e(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     0041b0f0(R)
//              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     0041b032(W)
//              undefined4        Stack[-0x14]:4 local_14                  XREF[2]:     0041b08e(W), 0041b0a5(R)
//              float             Stack[-0x18]:4 tot_time
//                               ??0RGE_Active_Animated_Sprite@@QAE@PAVRGE_Sprite@@@Z         XREF[1]:     make_active_sprite:004c0fcc(c)
//                               RGE_Active_Animated_Sprite::RGE_Active_Animated_Sprite
//                              asprite.cpp:170 (43)
//         0041b010     PUSH       -0x1
//         0041b012     PUSH       FUN_0055c988
//         0041b017     MOV        EAX,FS:[0x0]
//         0041b01d     PUSH       EAX
//         0041b01e     MOV        dword ptr FS:[0x0],ESP
//         0041b025     SUB        ESP,0x8
//         0041b028     MOV        EAX,dword ptr [ESP + param_1]
//         0041b02c     PUSH       EBX
//         0041b02d     PUSH       ESI
//         0041b02e     PUSH       EDI
//         0041b02f     MOV        ESI,this
//         0041b031     PUSH       EAX
//         0041b032     MOV        dword ptr [ESP + local_10],ESI
//         0041b036     CALL       RGE_Active_Sprite::RGE_Active_Sprite             undefined RGE_Active_Sprite(RGE_Active_Sprite
//                              asprite.cpp:176 (29)
//         0041b03b     MOV        this,dword ptr [ESI + 0x4]
//         0041b03e     XOR        EBX,EBX
//         0041b040     MOV        dword ptr [ESI],RGE_Active_Animated_Sprite::`v   = 0041b120
//         0041b046     MOV        byte ptr [ESI + 0x8],0x2
//         0041b04a     MOV        word ptr [ESI + 0x20],BX
//         0041b04e     MOV        dword ptr [ESP + local_4],EBX
//         0041b052     FLD        float ptr [this->_padding_ + 0x68]
//         0041b055     FST        float ptr [ESI + 0x18]
//                              asprite.cpp:177 (13)
//         0041b058     FCOMP      double ptr [DAT_0056ee78]                        = FCh
//         0041b05e     FNSTSW     AX
//         0041b060     TEST       AH,0x1
//         0041b063     JZ         LAB_0041b06c
//                              asprite.cpp:178 (7)
//         0041b065     MOV        dword ptr [ESI + 0x18],0x3a83126f
//                               LAB_0041b06c                                                 XREF[1]:     0041b063(j)
//                              asprite.cpp:180 (6)
//         0041b06c     TEST       byte ptr [this->_padding_ + 0x70],0x4
//         0041b070     JZ         LAB_0041b0ec
//                              asprite.cpp:182 (8)
//         0041b072     MOVSX      EDX,word ptr [this->_padding_ + 0x5e]
//         0041b076     MOV        dword ptr [ESP + param_1],EDX
//                              asprite.cpp:183 (33)
//         0041b07a     PUSH       0xb7
//         0041b07f     FILD       dword ptr [ESP + param_1]
//         0041b083     PUSH       s_C:\msdev\work\age1_x1\asprite.cp               = "C:\\msdev\\work\\age1_x1\\asprite.cpp"
//         0041b088     FMUL       float ptr [this->_padding_ + 0x68]
//         0041b08b     FADD       float ptr [this->_padding_ + 0x6c]
//         0041b08e     FSTP       float ptr [ESP + local_14]
//         0041b092     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
//         0041b097     MOV        dword ptr [ESP + param_1],EAX
//                              asprite.cpp:184 (34)
//         0041b09b     MOV        EDI,dword ptr [ESI + 0x4]
//         0041b09e     FILD       dword ptr [ESP + param_1]
//         0041b0a2     ADD        ESP,0x8
//         0041b0a5     FMUL       float ptr [ESP + local_14]
//         0041b0a9     FMUL       float ptr [DAT_0056ee80]
//         0041b0af     FLD        ST0
//         0041b0b1     FDIV       float ptr [EDI + 0x68]
//         0041b0b4     CALL       __ftol                                           undefined __ftol()
//         0041b0b9     MOV        word ptr [ESI + 0x14],AX
//                              asprite.cpp:185 (9)
//         0041b0bd     MOV        this,word ptr [EDI + 0x5e]
//         0041b0c1     CMP        AX,this
//         0041b0c4     JL         LAB_0041b0e0
//                              asprite.cpp:187 (7)
//         0041b0c6     LEA        EAX,[this->_padding_ + -0x1]
//         0041b0c9     MOV        word ptr [ESI + 0x14],AX
//                              asprite.cpp:188 (19)
//         0041b0cd     MOVSX      EAX,AX
//         0041b0d0     MOV        dword ptr [ESP + param_1],EAX
//         0041b0d4     FILD       dword ptr [ESP + param_1]
//         0041b0d8     FMUL       float ptr [EDI + 0x68]
//         0041b0db     FSUBR      ST0,ST1
//         0041b0dd     FSTP       float ptr [ESI + 0x18]
//                               LAB_0041b0e0                                                 XREF[1]:     0041b0c4(j)
//                              asprite.cpp:190 (10)
//         0041b0e0     MOV        this,word ptr [ESI + 0x14]
//         0041b0e4     FSTP       ST0
//         0041b0e6     MOV        word ptr [ESI + 0x20],this
//                              asprite.cpp:192 (2)
//         0041b0ea     JMP        LAB_0041b0f0
//                               LAB_0041b0ec                                                 XREF[1]:     0041b070(j)
//                              asprite.cpp:193 (4)
//         0041b0ec     MOV        word ptr [ESI + 0x14],BX
//                               LAB_0041b0f0                                                 XREF[1]:     0041b0ea(j)
//                              asprite.cpp:199 (35)
//         0041b0f0     MOV        this,dword ptr [ESP + local_c]
//         0041b0f4     MOV        dword ptr [ESI + 0x1c],EBX
//         0041b0f7     MOV        byte ptr [ESI + 0x22],BL
//         0041b0fa     MOV        byte ptr [ESI + 0x23],BL
//         0041b0fd     MOV        byte ptr [ESI + 0x24],0x1
//         0041b101     MOV        EAX,ESI
//         0041b103     POP        EDI
//         0041b104     POP        ESI
//         0041b105     MOV        dword ptr FS:[0x0],this
//         0041b10c     POP        EBX
//         0041b10d     ADD        ESP,0x14
//         0041b110     RET        0x4
//         0041b113     ??         90h
//         0041b114     NOP
//         0041b115     NOP
//         0041b116     NOP
//         0041b117     NOP
//         0041b118     NOP
//         0041b119     NOP
//         0041b11a     NOP
//         0041b11b     NOP
//         0041b11c     NOP
//         0041b11d     NOP
//         0041b11e     NOP
//         0041b11f     NOP
}

RGE_Active_Animated_Sprite::RGE_Active_Animated_Sprite(int param_1, RGE_Sprite** param_2) {
    /* TODO: Stub */
//                              undefined __thiscall RGE_Active_Animated_Sprite(RGE_Active_Animated_
//              undefined         <UNASSIGNED>   <RETURN>
//              RGE_Active_Ani    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     0041b15c(R)
//              RGE_Sprite * *    Stack[0x8]:4   param_2                   XREF[1]:     0041b156(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     0041b174(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     0041b1e5(R)
//              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     0041b164(W)
//                               ??0RGE_Active_Animated_Sprite@@QAE@HPAPAVRGE_Sprite@@@Z      XREF[1]:     load_node:0041a75d(c)
//                               RGE_Active_Animated_Sprite::RGE_Active_Animated_Sprite
//                              asprite.cpp:204 (45)
//         0041b140     PUSH       -0x1
//         0041b142     PUSH       FUN_0055c9a8
//         0041b147     MOV        EAX,FS:[0x0]
//         0041b14d     PUSH       EAX
//         0041b14e     MOV        dword ptr FS:[0x0],ESP
//         0041b155     PUSH       this
//         0041b156     MOV        EAX,dword ptr [ESP + param_2]
//         0041b15a     PUSH       ESI
//         0041b15b     PUSH       EDI
//         0041b15c     MOV        EDI,dword ptr [ESP + param_1]
//         0041b160     MOV        ESI,this
//         0041b162     PUSH       EAX
//         0041b163     PUSH       EDI
//         0041b164     MOV        dword ptr [ESP + local_10],ESI
//         0041b168     CALL       RGE_Active_Sprite::RGE_Active_Sprite             undefined RGE_Active_Sprite(RGE_Active_Sprite
//                              asprite.cpp:207 (33)
//         0041b16d     LEA        this,[ESI + 0x14]
//         0041b170     PUSH       0x2
//         0041b172     PUSH       this
//         0041b173     PUSH       EDI
//         0041b174     MOV        dword ptr [ESP + local_4],0x0
//         0041b17c     MOV        dword ptr [ESI],RGE_Active_Animated_Sprite::`v   = 0041b120
//         0041b182     MOV        byte ptr [ESI + 0x8],0x2
//         0041b186     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         0041b18b     ADD        ESP,0xc
//                              asprite.cpp:208 (15)
//         0041b18e     LEA        EDX,[ESI + 0x18]
//         0041b191     PUSH       0x4
//         0041b193     PUSH       EDX
//         0041b194     PUSH       EDI
//         0041b195     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         0041b19a     ADD        ESP,0xc
//                              asprite.cpp:209 (15)
//         0041b19d     LEA        EAX,[ESI + 0x1c]
//         0041b1a0     PUSH       0x4
//         0041b1a2     PUSH       EAX
//         0041b1a3     PUSH       EDI
//         0041b1a4     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         0041b1a9     ADD        ESP,0xc
//                              asprite.cpp:210 (15)
//         0041b1ac     LEA        this,[ESI + 0x20]
//         0041b1af     PUSH       0x2
//         0041b1b1     PUSH       this
//         0041b1b2     PUSH       EDI
//         0041b1b3     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         0041b1b8     ADD        ESP,0xc
//                              asprite.cpp:211 (15)
//         0041b1bb     LEA        EDX,[ESI + 0x22]
//         0041b1be     PUSH       0x1
//         0041b1c0     PUSH       EDX
//         0041b1c1     PUSH       EDI
//         0041b1c2     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         0041b1c7     ADD        ESP,0xc
//                              asprite.cpp:212 (15)
//         0041b1ca     LEA        EAX,[ESI + 0x23]
//         0041b1cd     PUSH       0x1
//         0041b1cf     PUSH       EAX
//         0041b1d0     PUSH       EDI
//         0041b1d1     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         0041b1d6     ADD        ESP,0xc
//                              asprite.cpp:213 (12)
//         0041b1d9     LEA        this,[ESI + 0x24]
//         0041b1dc     PUSH       0x1
//         0041b1de     PUSH       this
//         0041b1df     PUSH       EDI
//         0041b1e0     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//                              asprite.cpp:214 (24)
//         0041b1e5     MOV        this,dword ptr [ESP + local_c]
//         0041b1e9     ADD        ESP,0xc
//         0041b1ec     MOV        EAX,ESI
//         0041b1ee     MOV        dword ptr FS:[0x0],this
//         0041b1f5     POP        EDI
//         0041b1f6     POP        ESI
//         0041b1f7     ADD        ESP,0x10
//         0041b1fa     RET        0x8
//         0041b1fd     ??         90h
//         0041b1fe     NOP
//         0041b1ff     NOP
}

RGE_Active_Animated_Sprite::~RGE_Active_Animated_Sprite() {
    /* TODO: Stub */
//                              void __thiscall ~RGE_Active_Animated_Sprite(RGE_Active_Animated_Spri
//              void              <VOID>         <RETURN>
//              RGE_Active_Ani    ECX:4 (auto)   this
//                               ??1RGE_Active_Animated_Sprite@@UAE@XZ                        XREF[1]:     `vector_deleting_destructor':0041b
//                               RGE_Active_Animated_Sprite::~RGE_Active_Animated_Sprite
//                              asprite.cpp:218 (11)
//         0041b200     MOV        dword ptr [this->_padding_],RGE_Active_Animate   = 0041b120
//         0041b206     JMP        RGE_Active_Sprite::~RGE_Active_Sprite            void ~RGE_Active_Sprite(RGE_Active_Sprite * t
//                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
//         0041b20b     ??         90h
//         0041b20c     NOP
//         0041b20d     NOP
//         0041b20e     NOP
//         0041b20f     NOP
}

void RGE_Active_Animated_Sprite::save(int param_1) {
    /* TODO: Stub */
//                              void __thiscall save(RGE_Active_Animated_Sprite * this, int param_1)
//              void              <VOID>         <RETURN>
//              RGE_Active_Ani    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     0041b212(R)
//                               ?save@RGE_Active_Animated_Sprite@@UAEXH@Z                    XREF[1]:     0056ee98(*)
//                               RGE_Active_Animated_Sprite::save
//                              asprite.cpp:223 (2)
//         0041b210     PUSH       ESI
//         0041b211     PUSH       EDI
//                              asprite.cpp:224 (12)
//         0041b212     MOV        EDI,dword ptr [ESP + param_1]
//         0041b216     MOV        ESI,this
//         0041b218     PUSH       EDI
//         0041b219     CALL       RGE_Active_Sprite::save                          void save(RGE_Active_Sprite * this, int param
//                              asprite.cpp:226 (15)
//         0041b21e     LEA        EAX,[ESI + 0x14]
//         0041b221     PUSH       0x2
//         0041b223     PUSH       EAX
//         0041b224     PUSH       EDI
//         0041b225     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         0041b22a     ADD        ESP,0xc
//                              asprite.cpp:227 (15)
//         0041b22d     LEA        this,[ESI + 0x18]
//         0041b230     PUSH       0x4
//         0041b232     PUSH       this
//         0041b233     PUSH       EDI
//         0041b234     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         0041b239     ADD        ESP,0xc
//                              asprite.cpp:228 (15)
//         0041b23c     LEA        EDX,[ESI + 0x1c]
//         0041b23f     PUSH       0x4
//         0041b241     PUSH       EDX
//         0041b242     PUSH       EDI
//         0041b243     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         0041b248     ADD        ESP,0xc
//                              asprite.cpp:229 (15)
//         0041b24b     LEA        EAX,[ESI + 0x20]
//         0041b24e     PUSH       0x2
//         0041b250     PUSH       EAX
//         0041b251     PUSH       EDI
//         0041b252     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         0041b257     ADD        ESP,0xc
//                              asprite.cpp:230 (15)
//         0041b25a     LEA        this,[ESI + 0x22]
//         0041b25d     PUSH       0x1
//         0041b25f     PUSH       this
//         0041b260     PUSH       EDI
//         0041b261     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         0041b266     ADD        ESP,0xc
//                              asprite.cpp:231 (15)
//         0041b269     LEA        EDX,[ESI + 0x23]
//         0041b26c     PUSH       0x1
//         0041b26e     PUSH       EDX
//         0041b26f     PUSH       EDI
//         0041b270     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         0041b275     ADD        ESP,0xc
//                              asprite.cpp:232 (15)
//         0041b278     ADD        ESI,0x24
//         0041b27b     PUSH       0x1
//         0041b27d     PUSH       ESI
//         0041b27e     PUSH       EDI
//         0041b27f     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         0041b284     ADD        ESP,0xc
//                              asprite.cpp:233 (5)
//         0041b287     POP        EDI
//         0041b288     POP        ESI
//         0041b289     RET        0x4
//         0041b28c     ??         90h
//         0041b28d     NOP
//         0041b28e     NOP
//         0041b28f     NOP
    return;
}

void RGE_Active_Animated_Sprite::update(float param_1, float param_2) {
    /* TODO: Stub */
//                              void __thiscall update(RGE_Active_Animated_Sprite * this, float para
//              void              <VOID>         <RETURN>
//              RGE_Active_Ani    ECX:4 (auto)   this
//              float             Stack[0x4]:4   param_1                   XREF[3]:     0041b2cf(R), 0041b300(W), 0041b304(R)
//              float             Stack[0x8]:4   param_2                   XREF[5]:     0041b312(R), 0041b359(R), 0041b370(R), 0041b3c1(W),
//                                                                                     0041b3c5(R)
//                               ?update@RGE_Active_Animated_Sprite@@UAEXMM@Z                 XREF[1]:     0056ee9c(*)
//                               RGE_Active_Animated_Sprite::update
//                              asprite.cpp:237 (5)
//         0041b290     PUSH       EBX
//         0041b291     PUSH       ESI
//         0041b292     MOV        ESI,this
//         0041b294     PUSH       EDI
//                              asprite.cpp:244 (30)
//         0041b295     MOV        EDI,dword ptr [ESI + 0x4]
//         0041b298     MOV        byte ptr [ESI + 0x22],0x0
//         0041b29c     TEST       EDI,EDI
//         0041b29e     MOV        byte ptr [ESI + 0x23],0x0
//         0041b2a2     JZ         LAB_0041b408
//         0041b2a8     MOV        AL,byte ptr [ESI + 0x24]
//         0041b2ab     TEST       AL,AL
//         0041b2ad     JZ         LAB_0041b408
//                              asprite.cpp:246 (10)
//         0041b2b3     MOV        AX,word ptr [EDI + 0x5e]
//         0041b2b7     CMP        word ptr [ESI + 0x14],AX
//         0041b2bb     JL         LAB_0041b2c2
//                              asprite.cpp:247 (5)
//         0041b2bd     DEC        EAX
//         0041b2be     MOV        word ptr [ESI + 0x14],AX
//                               LAB_0041b2c2                                                 XREF[1]:     0041b2bb(j)
//                              asprite.cpp:249 (13)
//         0041b2c2     MOV        AL,byte ptr [EDI + 0x70]
//         0041b2c5     MOV        BL,0x1
//         0041b2c7     TEST       BL,AL
//         0041b2c9     JZ         LAB_0041b408
//                              asprite.cpp:251 (4)
//         0041b2cf     FLD        float ptr [ESP + param_1]
//                              asprite.cpp:252 (19)
//         0041b2d3     FADD       float ptr [ESI + 0x1c]
//         0041b2d6     FCOM       float ptr [ESI + 0x18]
//         0041b2d9     FST        float ptr [ESI + 0x1c]
//         0041b2dc     FNSTSW     AX
//         0041b2de     TEST       BL,AH
//         0041b2e0     JNZ        LAB_0041b406
//                              asprite.cpp:257 (23)
//         0041b2e6     FLD        ST0
//         0041b2e8     FDIV       float ptr [ESI + 0x18]
//         0041b2eb     MOV        AX,word ptr [ESI + 0x14]
//         0041b2ef     MOV        byte ptr [ESI + 0x22],BL
//         0041b2f2     MOV        word ptr [ESI + 0x20],AX
//         0041b2f6     CALL       __ftol                                           undefined __ftol()
//         0041b2fb     MOV        this,EAX
//                              asprite.cpp:258 (21)
//         0041b2fd     MOVSX      EDX,this
//         0041b300     MOV        dword ptr [ESP + param_1],EDX
//         0041b304     FILD       dword ptr [ESP + param_1]
//         0041b308     FMUL       float ptr [ESI + 0x18]
//         0041b30b     FSUBR      ST0,ST1
//         0041b30d     FSTP       float ptr [ESI + 0x1c]
//         0041b310     FSTP       ST0
//                              asprite.cpp:259 (33)
//         0041b312     FLD        float ptr [ESP + param_2]
//         0041b316     FCOMP      double ptr [DAT_0056ee88]
//         0041b31c     FNSTSW     AX
//         0041b31e     TEST       AH,0x41
//         0041b321     JZ         LAB_0041b333
//         0041b323     FLD        float ptr [EDI + 0x64]
//         0041b326     FCOMP      double ptr [DAT_0056ee88]
//         0041b32c     FNSTSW     AX
//         0041b32e     TEST       AH,0x40
//         0041b331     JZ         LAB_0041b349
//                               LAB_0041b333                                                 XREF[1]:     0041b321(j)
//                              asprite.cpp:261 (13)
//         0041b333     XOR        AX,AX
//         0041b336     MOV        AL,this
//         0041b338     ADD        word ptr [ESI + 0x14],AX
//         0041b33c     MOV        AX,word ptr [ESI + 0x14]
//                              asprite.cpp:262 (6)
//         0041b340     CMP        AX,word ptr [EDI + 0x5e]
//         0041b344     JL         LAB_0041b349
//                              asprite.cpp:263 (3)
//         0041b346     MOV        byte ptr [ESI + 0x23],BL
//                               LAB_0041b349                                                 XREF[2]:     0041b331(j), 0041b344(j)
//                              asprite.cpp:267 (33)
//         0041b349     FLD        float ptr [EDI + 0x64]
//         0041b34c     FCOMP      double ptr [DAT_0056ee88]
//         0041b352     FNSTSW     AX
//         0041b354     TEST       AH,0x40
//         0041b357     JNZ        LAB_0041b379
//         0041b359     FLD        float ptr [ESP + param_2]
//         0041b35d     FCOMP      double ptr [DAT_0056ee88]
//         0041b363     FNSTSW     AX
//         0041b365     TEST       AH,0x40
//         0041b368     JNZ        LAB_0041b379
//                              asprite.cpp:271 (15)
//         0041b36a     FLD        float ptr [EDI + 0x68]
//         0041b36d     FMUL       float ptr [EDI + 0x64]
//         0041b370     FDIV       float ptr [ESP + param_2]
//         0041b374     FSTP       float ptr [ESI + 0x18]
//         0041b377     JMP        LAB_0041b37f
//                               LAB_0041b379                                                 XREF[2]:     0041b357(j), 0041b368(j)
//                              asprite.cpp:269 (6)
//         0041b379     MOV        this,dword ptr [EDI + 0x68]
//         0041b37c     MOV        dword ptr [ESI + 0x18],this
//                               LAB_0041b37f                                                 XREF[1]:     0041b377(j)
//                              asprite.cpp:272 (16)
//         0041b37f     FLD        float ptr [ESI + 0x18]
//         0041b382     FCOMP      double ptr [DAT_0056ee78]                        = FCh
//         0041b388     FNSTSW     AX
//         0041b38a     TEST       AH,0x1
//         0041b38d     JZ         LAB_0041b396
//                              asprite.cpp:273 (7)
//         0041b38f     MOV        dword ptr [ESI + 0x18],0x3a83126f
//                               LAB_0041b396                                                 XREF[1]:     0041b38d(j)
//                              asprite.cpp:276 (11)
//         0041b396     MOV        AL,byte ptr [ESI + 0x23]
//         0041b399     TEST       AL,AL
//         0041b39b     JZ         LAB_0041b423
//                              asprite.cpp:278 (22)
//         0041b3a1     FLD        float ptr [EDI + 0x6c]
//         0041b3a4     FCOMP      double ptr [DAT_0056ee88]
//         0041b3aa     FNSTSW     AX
//         0041b3ac     TEST       AH,0x41
//         0041b3af     JNZ        LAB_0041b3e6
//         0041b3b1     CMP        byte ptr [ESI + 0x24],0x2
//         0041b3b5     JZ         LAB_0041b3e6
//                              asprite.cpp:280 (27)
//         0041b3b7     MOVSX      EDX,word ptr [ESI + 0x14]
//         0041b3bb     MOVSX      EAX,word ptr [EDI + 0x5e]
//         0041b3bf     SUB        EDX,EAX
//         0041b3c1     MOV        dword ptr [ESP + param_2],EDX
//         0041b3c5     FILD       dword ptr [ESP + param_2]
//         0041b3c9     FMUL       float ptr [EDI + 0x68]
//         0041b3cc     FSUBR      float ptr [EDI + 0x6c]
//         0041b3cf     FSTP       float ptr [ESI + 0x18]
//                              asprite.cpp:281 (4)
//         0041b3d2     MOV        this,word ptr [EDI + 0x5e]
//                              asprite.cpp:282 (6)
//         0041b3d6     MOV        byte ptr [ESI + 0x24],0x2
//         0041b3da     DEC        this
//                              asprite.cpp:283 (8)
//         0041b3dc     MOV        byte ptr [ESI + 0x23],0x0
//         0041b3e0     MOV        word ptr [ESI + 0x14],this
//                              asprite.cpp:285 (2)
//         0041b3e4     JMP        LAB_0041b408
//                               LAB_0041b3e6                                                 XREF[2]:     0041b3af(j), 0041b3b5(j)
//                              asprite.cpp:287 (3)
//         0041b3e6     MOV        byte ptr [ESI + 0x24],BL
//                              asprite.cpp:288 (10)
//         0041b3e9     MOV        AX,word ptr [EDI + 0x5e]
//         0041b3ed     CMP        word ptr [ESI + 0x14],AX
//         0041b3f1     JL         LAB_0041b408
//                               LAB_0041b3f3                                                 XREF[1]:     0041b402(j)
//                              asprite.cpp:289 (17)
//         0041b3f3     SUB        word ptr [ESI + 0x14],AX
//         0041b3f7     MOV        this,word ptr [ESI + 0x14]
//         0041b3fb     MOV        AX,word ptr [EDI + 0x5e]
//         0041b3ff     CMP        this,AX
//         0041b402     JGE        LAB_0041b3f3
//                              asprite.cpp:252 (4)
//         0041b404     JMP        LAB_0041b408
//                               LAB_0041b406                                                 XREF[1]:     0041b2e0(j)
//         0041b406     FSTP       ST0
//                               LAB_0041b408                                                 XREF[6]:     0041b2a2(j), 0041b2ad(j),
//                                                                                                         0041b2c9(j), 0041b3e4(j),
//                                                                                                         0041b3f1(j), 0041b404(j)
//                              asprite.cpp:296 (13)
//         0041b408     MOV        AL,byte ptr [ESI + 0x23]
//         0041b40b     TEST       AL,AL
//         0041b40d     JZ         LAB_0041b423
//         0041b40f     TEST       byte ptr [EDI + 0x70],0x8
//         0041b413     JZ         LAB_0041b423
//                              asprite.cpp:298 (4)
//         0041b415     MOV        byte ptr [ESI + 0x24],0x0
//                              asprite.cpp:299 (10)
//         0041b419     MOV        DX,word ptr [EDI + 0x5e]
//         0041b41d     DEC        DX
//         0041b41f     MOV        word ptr [ESI + 0x14],DX
//                               LAB_0041b423                                                 XREF[3]:     0041b39b(j), 0041b40d(j),
//                                                                                                         0041b413(j)
//                              asprite.cpp:301 (6)
//         0041b423     POP        EDI
//         0041b424     POP        ESI
//         0041b425     POP        EBX
//         0041b426     RET        0x8
//         0041b429     ??         90h
//         0041b42a     NOP
//         0041b42b     NOP
//         0041b42c     NOP
//         0041b42d     NOP
//         0041b42e     NOP
//         0041b42f     NOP
    return;
}

void RGE_Active_Animated_Sprite::draw(short param_1, long param_2, long param_3, long param_4, long param_5, RGE_Color_Table* param_6, TDrawArea* param_7) {
    /* TODO: Stub */
//                              void __thiscall draw(RGE_Active_Animated_Sprite * this, short param_
//              void              <VOID>         <RETURN>
//              RGE_Active_Ani    ECX:4 (auto)   this
//              short             Stack[0x4]:2   param_1                   XREF[1]:     0041b440(R)
//              long              Stack[0x8]:4   param_2                   XREF[1]:     0041b451(R)
//              long              Stack[0xc]:4   param_3                   XREF[1]:     0041b44c(R)
//              long              Stack[0x10]:4  param_4                   XREF[1]:     0041b447(R)
//              long              Stack[0x14]:4  param_5                   XREF[1]:     0041b434(R)
//              RGE_Color_Tabl    Stack[0x18]:4  param_6                   XREF[1]:     0041b43b(R)
//              TDrawArea *       Stack[0x1c]:4  param_7                   XREF[1]:     0041b430(R)
//                               ?draw@RGE_Active_Animated_Sprite@@UAEXFJJJJPAVRGE_Color_Tab  XREF[1]:     0056eea0(*)
//                               RGE_Active_Animated_Sprite::draw
//                              asprite.cpp:305 (57)
//         0041b430     MOV        EAX,dword ptr [ESP + param_7]
//         0041b434     MOV        EDX,dword ptr [ESP + param_5]
//         0041b438     PUSH       ESI
//         0041b439     MOV        ESI,this
//         0041b43b     MOV        this,dword ptr [ESP + param_6]
//         0041b43f     PUSH       EDI
//         0041b440     MOV        EDI,dword ptr [ESP + param_1]
//         0041b444     PUSH       0x0
//         0041b446     PUSH       EAX
//         0041b447     MOV        EAX,dword ptr [ESP + param_4]
//         0041b44b     PUSH       this
//         0041b44c     MOV        this,dword ptr [ESP + param_3]
//         0041b450     PUSH       EDX
//         0041b451     MOV        EDX,dword ptr [ESP + param_2]
//         0041b455     PUSH       EAX
//         0041b456     PUSH       this
//         0041b457     MOVSX      EAX,word ptr [ESI + 0x14]
//         0041b45b     MOVSX      this,DI
//         0041b45e     PUSH       EDX
//         0041b45f     PUSH       EAX
//         0041b460     PUSH       this
//         0041b461     MOV        this,dword ptr [ESI + 0x4]
//         0041b464     CALL       RGE_Sprite::draw                                 uchar draw(RGE_Sprite * this, long param_1, l
//                              asprite.cpp:307 (7)
//         0041b469     MOV        AL,byte ptr [ESI + 0x22]
//         0041b46c     TEST       AL,AL
//         0041b46e     JZ         LAB_0041b490
//                              asprite.cpp:309 (28)
//         0041b470     MOV        EAX,[fog_next_shape]
//         0041b475     TEST       EAX,EAX
//         0041b477     JNZ        LAB_0041b48c
//         0041b479     MOV        DX,word ptr [ESI + 0x14]
//         0041b47d     MOV        AX,word ptr [ESI + 0x20]
//         0041b481     MOV        this,dword ptr [ESI + 0x4]
//         0041b484     PUSH       EDI
//         0041b485     PUSH       EDX
//         0041b486     PUSH       EAX
//         0041b487     CALL       RGE_Sprite::play_sound                           void play_sound(RGE_Sprite * this, short para
//                               LAB_0041b48c                                                 XREF[1]:     0041b477(j)
//                              asprite.cpp:310 (4)
//         0041b48c     MOV        byte ptr [ESI + 0x22],0x0
//                               LAB_0041b490                                                 XREF[1]:     0041b46e(j)
//                              asprite.cpp:312 (5)
//         0041b490     POP        EDI
//         0041b491     POP        ESI
//         0041b492     RET        0x1c
//         0041b495     ??         90h
//         0041b496     NOP
//         0041b497     NOP
//         0041b498     NOP
//         0041b499     NOP
//         0041b49a     NOP
//         0041b49b     NOP
//         0041b49c     NOP
//         0041b49d     NOP
//         0041b49e     NOP
//         0041b49f     NOP
    return;
}

void RGE_Active_Animated_Sprite::normal_draw(short param_1, long param_2, long param_3, RGE_Color_Table* param_4, TDrawArea* param_5) {
    /* TODO: Stub */
//                              void __thiscall normal_draw(RGE_Active_Animated_Sprite * this, short
//              void              <VOID>         <RETURN>
//              RGE_Active_Ani    ECX:4 (auto)   this
//              short             Stack[0x4]:2   param_1                   XREF[1]:     0041b4b0(R)
//              long              Stack[0x8]:4   param_2                   XREF[1]:     0041b4b5(R)
//              long              Stack[0xc]:4   param_3                   XREF[1]:     0041b4a4(R)
//              RGE_Color_Tabl    Stack[0x10]:4  param_4                   XREF[1]:     0041b4ab(R)
//              TDrawArea *       Stack[0x14]:4  param_5                   XREF[1]:     0041b4a0(R)
//                               ?normal_draw@RGE_Active_Animated_Sprite@@UAEXFJJPAVRGE_Colo  XREF[1]:     0056eea4(*)
//                               RGE_Active_Animated_Sprite::normal_draw
//                              asprite.cpp:316 (45)
//         0041b4a0     MOV        EAX,dword ptr [ESP + param_5]
//         0041b4a4     MOV        EDX,dword ptr [ESP + param_3]
//         0041b4a8     PUSH       ESI
//         0041b4a9     MOV        ESI,this
//         0041b4ab     MOV        this,dword ptr [ESP + param_4]
//         0041b4af     PUSH       EDI
//         0041b4b0     MOV        EDI,dword ptr [ESP + param_1]
//         0041b4b4     PUSH       EAX
//         0041b4b5     MOV        EAX,dword ptr [ESP + param_2]
//         0041b4b9     PUSH       this
//         0041b4ba     MOVSX      this,word ptr [ESI + 0x14]
//         0041b4be     PUSH       EDX
//         0041b4bf     PUSH       EAX
//         0041b4c0     MOVSX      EDX,DI
//         0041b4c3     PUSH       this
//         0041b4c4     MOV        this,dword ptr [ESI + 0x4]
//         0041b4c7     PUSH       EDX
//         0041b4c8     CALL       RGE_Sprite::normal_draw                          uchar normal_draw(RGE_Sprite * this, long par
//                              asprite.cpp:318 (7)
//         0041b4cd     MOV        AL,byte ptr [ESI + 0x22]
//         0041b4d0     TEST       AL,AL
//         0041b4d2     JZ         LAB_0041b4eb
//                              asprite.cpp:320 (19)
//         0041b4d4     MOV        AX,word ptr [ESI + 0x14]
//         0041b4d8     MOV        this,word ptr [ESI + 0x20]
//         0041b4dc     PUSH       EDI
//         0041b4dd     PUSH       EAX
//         0041b4de     PUSH       this
//         0041b4df     MOV        this,dword ptr [ESI + 0x4]
//         0041b4e2     CALL       RGE_Sprite::play_sound                           void play_sound(RGE_Sprite * this, short para
//                              asprite.cpp:321 (4)
//         0041b4e7     MOV        byte ptr [ESI + 0x22],0x0
//                               LAB_0041b4eb                                                 XREF[1]:     0041b4d2(j)
//                              asprite.cpp:323 (5)
//         0041b4eb     POP        EDI
//         0041b4ec     POP        ESI
//         0041b4ed     RET        0x14
    return;
}

void RGE_Active_Animated_Sprite::shadow_draw(short param_1, long param_2, long param_3, RGE_Color_Table* param_4, TDrawArea* param_5, uchar param_6) {
    /* TODO: Stub */
//                              void __thiscall shadow_draw(RGE_Active_Animated_Sprite * this, short
//              void              <VOID>         <RETURN>
//              RGE_Active_Ani    ECX:4 (auto)   this
//              short             Stack[0x4]:2   param_1                   XREF[1]:     0041b50d(R)
//              long              Stack[0x8]:4   param_2                   XREF[1]:     0041b503(R)
//              long              Stack[0xc]:4   param_3                   XREF[1]:     0041b4fe(R)
//              RGE_Color_Tabl    Stack[0x10]:4  param_4                   XREF[1]:     0041b4f9(R)
//              TDrawArea *       Stack[0x14]:4  param_5                   XREF[1]:     0041b4f4(R)
//              uchar             Stack[0x18]:1  param_6                   XREF[1]:     0041b4f0(R)
//                               ?shadow_draw@RGE_Active_Animated_Sprite@@UAEXFJJPAVRGE_Colo  XREF[1]:     0056eea8(*)
//                               RGE_Active_Animated_Sprite::shadow_draw
//                              asprite.cpp:327 (44)
//         0041b4f0     MOV        EAX,dword ptr [ESP + param_6]
//         0041b4f4     MOV        EDX,dword ptr [ESP + param_5]
//         0041b4f8     PUSH       EAX
//         0041b4f9     MOV        EAX,dword ptr [ESP + param_4]
//         0041b4fd     PUSH       EDX
//         0041b4fe     MOV        EDX,dword ptr [ESP + param_3]
//         0041b502     PUSH       EAX
//         0041b503     MOV        EAX,dword ptr [ESP + param_2]
//         0041b507     PUSH       EDX
//         0041b508     PUSH       EAX
//         0041b509     MOVSX      EDX,word ptr [ECX + this->frame]
//         0041b50d     MOVSX      EAX,word ptr [ESP + param_1]
//         0041b512     MOV        this,dword ptr [ECX + this->_padding_]
//         0041b515     PUSH       EDX
//         0041b516     PUSH       EAX
//         0041b517     CALL       RGE_Sprite::shadow_draw                          uchar shadow_draw(RGE_Sprite * this, long par
//                              asprite.cpp:329 (3)
//         0041b51c     RET        0x18
//         0041b51f     ??         90h
    return;
}

short RGE_Active_Animated_Sprite::what_frame() {
    /* TODO: Stub */
//                              short __thiscall what_frame(RGE_Active_Animated_Sprite * this)
//              short             AX:2           <RETURN>
//              RGE_Active_Ani    ECX:4 (auto)   this
//                               ?what_frame@RGE_Active_Animated_Sprite@@UAEFXZ               XREF[1]:     0056eeac(*)
//                               RGE_Active_Animated_Sprite::what_frame
//                              asprite.cpp:333 (4)
//         0041b520     MOV        AX,word ptr [ECX + this->frame]
//                              asprite.cpp:335 (1)
//         0041b524     RET
//         0041b525     ??         90h
//         0041b526     NOP
//         0041b527     NOP
//         0041b528     NOP
//         0041b529     NOP
//         0041b52a     NOP
//         0041b52b     NOP
//         0041b52c     NOP
//         0041b52d     NOP
//         0041b52e     NOP
//         0041b52f     NOP
    return 0;
}

uchar RGE_Active_Animated_Sprite::is_animating() {
    /* TODO: Stub */
//                              uchar __thiscall is_animating(RGE_Active_Animated_Sprite * this)
//              uchar             AL:1           <RETURN>
//              RGE_Active_Ani    ECX:4 (auto)   this
//                               ?is_animating@RGE_Active_Animated_Sprite@@UAEEXZ             XREF[1]:     0056eeb0(*)
//                               RGE_Active_Animated_Sprite::is_animating
//                              asprite.cpp:339 (22)
//         0041b530     MOV        AL,byte ptr [ECX + this->animate_flag]
//         0041b533     TEST       AL,AL
//         0041b535     JZ         LAB_0041b544
//         0041b537     MOV        this,dword ptr [ECX + this->_padding_]
//         0041b53a     MOV        EAX,0x1
//         0041b53f     TEST       byte ptr [this->_padding_ + 0x70],AL
//         0041b542     JNZ        LAB_0041b546
//                               LAB_0041b544                                                 XREF[1]:     0041b535(j)
//         0041b544     XOR        EAX,EAX
//                               LAB_0041b546                                                 XREF[1]:     0041b542(j)
//                              asprite.cpp:341 (1)
//         0041b546     RET
//         0041b547     ??         90h
//         0041b548     NOP
//         0041b549     NOP
//         0041b54a     NOP
//         0041b54b     NOP
//         0041b54c     NOP
//         0041b54d     NOP
//         0041b54e     NOP
//         0041b54f     NOP
    return 0;
}

void RGE_Active_Animated_Sprite::set_frame(short param_1) {
    /* TODO: Stub */
//                              void __thiscall set_frame(RGE_Active_Animated_Sprite * this, short p
//              void              <VOID>         <RETURN>
//              RGE_Active_Ani    ECX:4 (auto)   this
//              short             Stack[0x4]:2   param_1                   XREF[1]:     0041b550(R)
//                               ?set_frame@RGE_Active_Animated_Sprite@@UAEXF@Z               XREF[1]:     0056eeb4(*)
//                               RGE_Active_Animated_Sprite::set_frame
//                              asprite.cpp:345 (9)
//         0041b550     MOV        AX,word ptr [ESP + param_1]
//         0041b555     MOV        word ptr [ECX + this->frame],AX
//                              asprite.cpp:347 (3)
//         0041b559     RET        0x4
//         0041b55c     ??         90h
//         0041b55d     NOP
//         0041b55e     NOP
//         0041b55f     NOP
    return;
}

uchar RGE_Active_Animated_Sprite::frame_passed(short param_1) {
    /* TODO: Stub */
//                              uchar __thiscall frame_passed(RGE_Active_Animated_Sprite * this, sho
//              uchar             AL:1           <RETURN>
//              RGE_Active_Ani    ECX:4 (auto)   this
//              short             Stack[0x4]:2   param_1                   XREF[1]:     0041b56e(R)
//                               ?frame_passed@RGE_Active_Animated_Sprite@@UAEEF@Z            XREF[1]:     0056eeb8(*)
//                               RGE_Active_Animated_Sprite::frame_passed
//                              asprite.cpp:351 (36)
//         0041b560     MOV        AL,byte ptr [ECX + this->frame_changed]
//         0041b563     TEST       AL,AL
//         0041b565     JZ         LAB_0041b587
//         0041b567     MOV        AL,byte ptr [ECX + this->frame_looped]
//         0041b56a     TEST       AL,AL
//         0041b56c     JNZ        LAB_0041b57f
//         0041b56e     MOV        AX,word ptr [ESP + param_1]
//         0041b573     CMP        word ptr [ECX + this->frame],AX
//         0041b577     JL         LAB_0041b587
//         0041b579     CMP        word ptr [ECX + this->last_frame],AX
//         0041b57d     JGE        LAB_0041b587
//                               LAB_0041b57f                                                 XREF[1]:     0041b56c(j)
//         0041b57f     MOV        EAX,0x1
//                              asprite.cpp:353 (3)
//         0041b584     RET        0x4
//                               LAB_0041b587                                                 XREF[3]:     0041b565(j), 0041b577(j),
//                                                                                                         0041b57d(j)
//                              asprite.cpp:352 (2)
//         0041b587     XOR        EAX,EAX
//                              asprite.cpp:353 (3)
//         0041b589     RET        0x4
//         0041b58c     ??         90h
//         0041b58d     NOP
//         0041b58e     NOP
//         0041b58f     NOP
    return 0;
}

uchar RGE_Active_Animated_Sprite::looped() {
    /* TODO: Stub */
//                              uchar __thiscall looped(RGE_Active_Animated_Sprite * this)
//              uchar             AL:1           <RETURN>
//              RGE_Active_Ani    ECX:4 (auto)   this
//                               ?looped@RGE_Active_Animated_Sprite@@UAEEXZ                   XREF[1]:     0056eebc(*)
//                               RGE_Active_Animated_Sprite::looped
//                              asprite.cpp:357 (3)
//         0041b590     MOV        AL,byte ptr [ECX + this->frame_looped]
//                              asprite.cpp:359 (1)
//         0041b593     RET
//         0041b594     ??         90h
//         0041b595     NOP
//         0041b596     NOP
//         0041b597     NOP
//         0041b598     NOP
//         0041b599     NOP
//         0041b59a     NOP
//         0041b59b     NOP
//         0041b59c     NOP
//         0041b59d     NOP
//         0041b59e     NOP
//         0041b59f     NOP
    return 0;
}

short RGE_Active_Animated_Sprite::get_facetindex(short param_1) {
    /* TODO: Stub */
//                              short __thiscall get_facetindex(RGE_Active_Animated_Sprite * this, s
//              short             AX:2           <RETURN>
//              RGE_Active_Ani    ECX:4 (auto)   this
//              short             Stack[0x4]:2   param_1                   XREF[1]:     0041b5ae(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[3]:     0041b5a8(*), 0041b5b4(W), 0041b5c1(*)
//              long              Stack[-0x8]:4  facet_index
//                               ?get_facetindex@RGE_Active_Animated_Sprite@@UAEFF@Z          XREF[1]:     0056eec0(*)
//                               RGE_Active_Animated_Sprite::get_facetindex
//                              asprite.cpp:363 (1)
//         0041b5a0     PUSH       this
//                              asprite.cpp:366 (32)
//         0041b5a1     MOVSX      EDX,word ptr [ECX + this->frame]
//         0041b5a5     MOV        this,dword ptr [ECX + this->_padding_]
//         0041b5a8     LEA        EAX=>local_4,[ESP]
//         0041b5ac     PUSH       EAX
//         0041b5ad     PUSH       EDX
//         0041b5ae     MOVSX      EAX,word ptr [ESP + param_1]
//         0041b5b3     PUSH       EAX
//         0041b5b4     MOV        dword ptr [ESP + local_4],0x0
//         0041b5bc     CALL       RGE_Sprite::get_facetindex                       uchar get_facetindex(RGE_Sprite * this, long
//                              asprite.cpp:368 (5)
//         0041b5c1     MOV        AX,word ptr [ESP]=>local_4
//                              asprite.cpp:369 (4)
//         0041b5c6     POP        this
//         0041b5c7     RET        0x4
//         0041b5ca     ??         90h
//         0041b5cb     NOP
//         0041b5cc     NOP
//         0041b5cd     NOP
//         0041b5ce     NOP
//         0041b5cf     NOP
    return 0;
}

uchar RGE_Active_Animated_Sprite::get_frame(short* param_1, short* param_2, short* param_3, short* param_4, long param_5) {
    /* TODO: Stub */
//                              uchar __thiscall get_frame(RGE_Active_Animated_Sprite * this, short
//              uchar             AL:1           <RETURN>
//              RGE_Active_Ani    ECX:4 (auto)   this
//              short *           Stack[0x4]:4   param_1                   XREF[1]:     0041b5eb(R)
//              short *           Stack[0x8]:4   param_2                   XREF[1]:     0041b5e6(R)
//              short *           Stack[0xc]:4   param_3                   XREF[1]:     0041b5e1(R)
//              short *           Stack[0x10]:4  param_4                   XREF[1]:     0041b5dc(R)
//              long              Stack[0x14]:4  param_5                   XREF[1]:     0041b5d4(R)
//                               ?get_frame@RGE_Active_Animated_Sprite@@UAEEAAF000J@Z         XREF[1]:     0056eec4(*)
//                               RGE_Active_Animated_Sprite::get_frame
//                              asprite.cpp:373 (38)
//         0041b5d0     MOVSX      EAX,word ptr [ECX + this->frame]
//         0041b5d4     MOV        EDX,dword ptr [ESP + param_5]
//         0041b5d8     MOV        this,dword ptr [ECX + this->_padding_]
//         0041b5db     PUSH       EAX
//         0041b5dc     MOV        EAX,dword ptr [ESP + param_4]
//         0041b5e0     PUSH       EDX
//         0041b5e1     MOV        EDX,dword ptr [ESP + param_3]
//         0041b5e5     PUSH       EAX
//         0041b5e6     MOV        EAX,dword ptr [ESP + param_2]
//         0041b5ea     PUSH       EDX
//         0041b5eb     MOV        EDX,dword ptr [ESP + param_1]
//         0041b5ef     PUSH       EAX
//         0041b5f0     PUSH       EDX
//         0041b5f1     CALL       RGE_Sprite::get_frame                            int get_frame(RGE_Sprite * this, short * para
//                              asprite.cpp:375 (3)
//         0041b5f6     RET        0x14
//         0041b5f9     ??         90h
//         0041b5fa     NOP
//         0041b5fb     NOP
//         0041b5fc     NOP
//         0041b5fd     NOP
//         0041b5fe     NOP
//         0041b5ff     NOP
    return 0;
}

void RGE_Active_Animated_Sprite::setToFirstFrame() {
    /* TODO: Stub */
//                              void __thiscall setToFirstFrame(RGE_Active_Animated_Sprite * this)
//              void              <VOID>         <RETURN>
//              RGE_Active_Ani    ECX:4 (auto)   this
//                               ?setToFirstFrame@RGE_Active_Animated_Sprite@@UAEXXZ          XREF[1]:     0056eec8(*)
//                               RGE_Active_Animated_Sprite::setToFirstFrame
//                              asprite.cpp:380 (12)
//         0041b600     MOV        AX,word ptr [ECX + this->frame]
//         0041b604     MOV        byte ptr [ECX + this->frame_changed],0x1
//         0041b608     MOV        word ptr [ECX + this->last_frame],AX
//                              asprite.cpp:383 (6)
//         0041b60c     MOV        word ptr [ECX + this->frame],0x0
//                              asprite.cpp:384 (1)
//         0041b612     RET
//         0041b613     ??         90h
//         0041b614     NOP
//         0041b615     NOP
//         0041b616     NOP
//         0041b617     NOP
//         0041b618     NOP
//         0041b619     NOP
//         0041b61a     NOP
//         0041b61b     NOP
//         0041b61c     NOP
//         0041b61d     NOP
//         0041b61e     NOP
//         0041b61f     NOP
    return;
}

