#include "../common.h"
#include "sprite.h"

RGE_Sprite::RGE_Sprite(short param_1) {
    /* TODO: Stub */
//                              undefined __thiscall RGE_Sprite(RGE_Sprite * this, _iobuf * param_1,
//              undefined         <UNASSIGNED>   <RETURN>
//              RGE_Sprite *      ECX:4 (auto)   this
//              _iobuf *          Stack[0x4]:4   param_1                   XREF[3]:     004bfa96(R), 004bfba3(R), 004bfc32(R)
//              short             Stack[0x8]:2   param_2                   XREF[6]:     004bfa28(R), 004bfa38(*), 004bfb27(R), 004bfc11(R),
//                                                                                     004bfc25(R), 004bfcaf(R)
//              RGE_Sound * *     Stack[0xc]:4   param_3                   XREF[2]:     004bfaf0(R), 004bfc79(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[3]:     004bfc17(W), 004bfcaa(R), 004bfcb4(W)
//              short             Stack[-0x8]:2  index1                    XREF[3]:     004bfc36(*), 004bfc4f(R), 004bfc95(R)
//              short             Stack[-0xc]:2  sound_facet               XREF[3]:     004bfab1(W), 004bfc53(R), 004bfc5f(W)
//              undefined2        Stack[-0xe]:2  local_e                   XREF[2]:     004bfc2d(*), 004bfca0(R)
//              short             Stack[-0x10]:2 last_facet                XREF[2]:     004bfc29(*), 004bfc74(R)
//              short             Stack[-0x12]:2 sound_frame               XREF[2]:     004bfa66(*), 004bfb60(R)
//              short             Stack[-0x14]:2 sound_id                  XREF[2]:     004bfa7a(*), 004bfb55(R)
//              short             Stack[-0x16]:2 temp_loop_once            XREF[2]:     004bfa6b(*), 004bfb46(R)
//              short             Stack[-0x18]:2 temp_randomize_on_start   XREF[2]:     004bfa70(*), 004bfb3b(R)
//              short             Stack[-0x1a]:2 temp_directional          XREF[2]:     004bfa75(*), 004bfb2c(R)
//              short             Stack[-0x1c]:2 temp_animated             XREF[2]:     004bfa83(*), 004bfb1e(R)
//              short             Stack[-0x1e]:2 temp_transparent_picking  XREF[2]:     004bfa88(*), 004bfb1a(R)
//              short             Stack[-0x20]:2 temp_draw_level           XREF[2]:     004bfa8d(*), 004bfafb(R)
//              short             Stack[-0x22]:2 temp_color_flag           XREF[2]:     004bfa3d(*), 004bfade(R)
//              short             Stack[-0x24]:2 temp_mirror_flag
//              short             Stack[-0x26]:2 temp_main_sound
//                               ??0RGE_Sprite@@QAE@PAU_iobuf@@FPAPAVRGE_Sound@@@Z            XREF[1]:     data_load_sprites:00541196(c)
//                               RGE_Sprite::RGE_Sprite
//                              sprite.cpp:140 (8)
//         004bfa20     SUB        ESP,0x24
//         004bfa23     PUSH       EBX
//         004bfa24     PUSH       EBP
//         004bfa25     PUSH       ESI
//         004bfa26     MOV        ESI,this
//                              sprite.cpp:163 (10)
//         004bfa28     MOV        this,word ptr [ESP + param_2]
//         004bfa2d     XOR        EAX,EAX
//         004bfa2f     MOV        dword ptr [ESI + 0x18],EAX
//                              sprite.cpp:164 (3)
//         004bfa32     MOV        dword ptr [ESI + 0x20],EAX
//                              sprite.cpp:165 (3)
//         004bfa35     MOV        dword ptr [ESI + 0x24],EAX
//                              sprite.cpp:195 (149)
//         004bfa38     LEA        EDX=>param_2,[ESP + 0x38]
//         004bfa3c     PUSH       EDI
//         004bfa3d     LEA        EAX=>temp_color_flag,[ESP + 0x12]
//         004bfa41     PUSH       EDX
//         004bfa42     MOV        word ptr [ESI + 0x72],this
//         004bfa46     LEA        EBP,[ESI + 0x36]
//         004bfa49     PUSH       EAX
//         004bfa4a     LEA        this,[ESI + 0x6c]
//         004bfa4d     PUSH       EBP
//         004bfa4e     LEA        EDX,[ESI + 0x68]
//         004bfa51     PUSH       this
//         004bfa52     LEA        EAX,[ESI + 0x64]
//         004bfa55     PUSH       EDX
//         004bfa56     LEA        this,[ESI + 0x34]
//         004bfa59     PUSH       EAX
//         004bfa5a     LEA        EDX,[ESI + 0x32]
//         004bfa5d     PUSH       this
//         004bfa5e     LEA        EAX,[ESI + 0x30]
//         004bfa61     PUSH       EDX
//         004bfa62     LEA        this,[ESI + 0x2e]
//         004bfa65     PUSH       EAX
//         004bfa66     LEA        EDX=>sound_frame,[ESP + 0x46]
//         004bfa6a     PUSH       this
//         004bfa6b     LEA        EAX=>temp_loop_once,[ESP + 0x46]
//         004bfa6f     PUSH       EDX
//         004bfa70     LEA        this=>temp_randomize_on_start,[ESP + 0x48]
//         004bfa74     PUSH       EAX
//         004bfa75     LEA        EDX=>temp_directional,[ESP + 0x4a]
//         004bfa79     PUSH       this
//         004bfa7a     LEA        EAX=>sound_id,[ESP + 0x54]
//         004bfa7e     PUSH       EDX
//         004bfa7f     LEA        this,[ESI + 0x2a]
//         004bfa82     PUSH       EAX
//         004bfa83     LEA        EDX=>temp_animated,[ESP + 0x54]
//         004bfa87     PUSH       this
//         004bfa88     LEA        EAX=>temp_transparent_picking_flag,[ESP + 0x56]
//         004bfa8c     PUSH       EDX
//         004bfa8d     LEA        this=>temp_draw_level,[ESP + 0x58]
//         004bfa91     LEA        EBX,[ESI + 0x60]
//         004bfa94     PUSH       EAX
//         004bfa95     PUSH       this
//         004bfa96     MOV        this,dword ptr [ESP + param_1]
//         004bfa9d     LEA        EDX,[ESI + 0x5e]
//         004bfaa0     PUSH       EBX
//         004bfaa1     LEA        EAX,[ESI + 0x10]
//         004bfaa4     PUSH       EDX
//         004bfaa5     LEA        EDI,[ESI + 0x48]
//         004bfaa8     PUSH       EAX
//         004bfaa9     PUSH       ESI
//         004bfaaa     PUSH       EDI
//         004bfaab     PUSH       s__%s_%s_%d_%hd_%hd_%hd_%hd_%hd_%h               = " %s %s %d %hd %hd %hd %hd %hd %hd %hd %hd
//         004bfab0     PUSH       this
//         004bfab1     MOV        dword ptr [ESP + sound_facet],0xffffffff
//         004bfabc     CALL       fscanf                                           undefined fscanf()
//         004bfac1     ADD        ESP,0x68
//         004bfac4     CMP        EAX,-0x1
//         004bfac7     JZ         LAB_004bfcd1
//                              sprite.cpp:200 (17)
//         004bfacd     PUSH       EDI
//         004bface     MOV        byte ptr [ESI + 0x14],0x0
//         004bfad2     MOV        dword ptr [ESI + 0x1c],0x0
//         004bfad9     CALL       convert_us                                       void convert_us(char * param_1)
//                              sprite.cpp:201 (29)
//         004bfade     MOV        AX,word ptr [ESP + temp_color_flag]
//         004bfae3     XOR        EDI,EDI
//         004bfae5     ADD        ESP,0x4
//         004bfae8     CMP        AX,DI
//         004bfaeb     JL         LAB_004bfaf9
//         004bfaed     MOVSX      EDX,AX
//         004bfaf0     MOV        EAX,dword ptr [ESP + param_3]
//         004bfaf4     MOV        EAX,dword ptr [EAX + EDX*0x4]
//         004bfaf7     JMP        LAB_004bfafb
//                               LAB_004bfaf9                                                 XREF[1]:     004bfaeb(j)
//         004bfaf9     XOR        EAX,EAX
//                               LAB_004bfafb                                                 XREF[1]:     004bfaf7(j)
//                              sprite.cpp:203 (10)
//         004bfafb     CMP        word ptr [ESP + temp_draw_level],DI
//         004bfb00     MOV        dword ptr [ESI + 0x3c],EAX
//         004bfb03     JLE        LAB_004bfb16
//                              sprite.cpp:204 (15)
//         004bfb05     MOV        BX,word ptr [EBX]
//         004bfb08     MOV        this,EBX
//         004bfb0a     SAR        this,0x1
//         004bfb0c     SAR        EBX,0x2
//         004bfb0f     ADD        this,BL
//         004bfb11     MOV        byte ptr [ESI + 0x74],this
//                              sprite.cpp:205 (2)
//         004bfb14     JMP        LAB_004bfb1a
//                               LAB_004bfb16                                                 XREF[1]:     004bfb03(j)
//                              sprite.cpp:206 (4)
//         004bfb16     MOV        byte ptr [ESI + 0x74],0x0
//                               LAB_004bfb1a                                                 XREF[1]:     004bfb14(j)
//                              sprite.cpp:208 (4)
//         004bfb1a     MOV        DL,byte ptr [ESP + temp_transparent_picking_fl
//                              sprite.cpp:212 (27)
//         004bfb1e     MOV        AL,byte ptr [ESP + temp_animated]
//         004bfb22     MOV        byte ptr [ESI + 0x28],DL
//         004bfb25     XOR        EDX,EDX
//         004bfb27     CMP        word ptr [ESP + param_2],DI
//         004bfb2c     MOV        this,byte ptr [ESP + temp_directional]
//         004bfb30     MOV        byte ptr [ESI + 0x29],AL
//         004bfb33     MOV        byte ptr [ESI + 0x2c],this
//         004bfb36     SETG       DL
//                              sprite.cpp:214 (13)
//         004bfb39     XOR        EAX,EAX
//         004bfb3b     CMP        word ptr [ESP + temp_randomize_on_start],DI
//         004bfb40     MOV        byte ptr [ESI + 0x40],DL
//         004bfb43     SETG       AL
//                              sprite.cpp:215 (15)
//         004bfb46     CMP        word ptr [ESP + temp_loop_once],DI
//         004bfb4b     MOV        byte ptr [ESI + 0x70],AL
//         004bfb4e     JZ         LAB_004bfb55
//         004bfb50     ADD        AL,0x2
//         004bfb52     MOV        byte ptr [ESI + 0x70],AL
//                               LAB_004bfb55                                                 XREF[1]:     004bfb4e(j)
//                              sprite.cpp:216 (11)
//         004bfb55     CMP        word ptr [ESP + sound_id],DI
//         004bfb5a     JZ         LAB_004bfb60
//         004bfb5c     ADD        byte ptr [ESI + 0x70],0x4
//                               LAB_004bfb60                                                 XREF[1]:     004bfb5a(j)
//                              sprite.cpp:217 (11)
//         004bfb60     CMP        word ptr [ESP + sound_frame],DI
//         004bfb65     JZ         LAB_004bfb6b
//         004bfb67     ADD        byte ptr [ESI + 0x70],0x8
//                               LAB_004bfb6b                                                 XREF[1]:     004bfb65(j)
//                              sprite.cpp:219 (9)
//         004bfb6b     MOV        AX,word ptr [EBP]
//         004bfb6f     CMP        AX,DI
//         004bfb72     JLE        LAB_004bfbc0
//                              sprite.cpp:221 (14)
//         004bfb74     MOVSX      EAX,AX
//         004bfb77     PUSH       0x10
//         004bfb79     PUSH       EAX
//         004bfb7a     CALL       calloc                                           undefined calloc()
//         004bfb7f     ADD        ESP,0x8
//                              sprite.cpp:222 (10)
//         004bfb82     CMP        word ptr [EBP],0x0
//         004bfb87     MOV        dword ptr [ESI + 0x38],EAX
//         004bfb8a     JLE        LAB_004bfbc3
//                               LAB_004bfb8c                                                 XREF[1]:     004bfbbc(j)
//                              sprite.cpp:227 (50)
//         004bfb8c     MOV        EDX,dword ptr [ESI + 0x38]
//         004bfb8f     MOVSX      this,DI
//         004bfb92     SHL        this,0x4
//         004bfb95     LEA        EAX,[this->pict_name[0] + EDX*0x1]
//         004bfb98     LEA        this,[EAX + 0xc]
//         004bfb9b     LEA        EDX,[EAX + 0xa]
//         004bfb9e     PUSH       this
//         004bfb9f     LEA        this,[EAX + 0x8]
//         004bfba2     PUSH       EDX
//         004bfba3     MOV        EDX,dword ptr [ESP + param_1]
//         004bfba7     PUSH       this
//         004bfba8     PUSH       EAX
//         004bfba9     PUSH       s__%hd_%hd_%hd_%hd                               = " %hd %hd %hd %hd"
//         004bfbae     PUSH       EDX
//         004bfbaf     CALL       fscanf                                           undefined fscanf()
//         004bfbb4     ADD        ESP,0x18
//         004bfbb7     INC        EDI
//         004bfbb8     CMP        DI,word ptr [EBP]
//         004bfbbc     JL         LAB_004bfb8c
//                              sprite.cpp:229 (2)
//         004bfbbe     JMP        LAB_004bfbc3
//                               LAB_004bfbc0                                                 XREF[1]:     004bfb72(j)
//                              sprite.cpp:230 (3)
//         004bfbc0     MOV        dword ptr [ESI + 0x38],EDI
//                               LAB_004bfbc3                                                 XREF[2]:     004bfb8a(j), 004bfbbe(j)
//                              sprite.cpp:232 (11)
//         004bfbc3     MOV        AL,byte ptr [ESI + 0x40]
//         004bfbc6     TEST       AL,AL
//         004bfbc8     JZ         LAB_004bfcca
//                              sprite.cpp:234 (12)
//         004bfbce     MOVSX      EAX,word ptr [ESI + 0x60]
//         004bfbd2     PUSH       0x14
//         004bfbd4     PUSH       EAX
//         004bfbd5     CALL       calloc                                           undefined calloc()
//                              sprite.cpp:235 (14)
//         004bfbda     XOR        EDX,EDX
//         004bfbdc     ADD        ESP,0x8
//         004bfbdf     CMP        word ptr [ESI + 0x60],DX
//         004bfbe3     MOV        dword ptr [ESI + 0x44],EAX
//         004bfbe6     JLE        LAB_004bfc11
//                               LAB_004bfbe8                                                 XREF[1]:     004bfc0f(j)
//                              sprite.cpp:236 (18)
//         004bfbe8     MOVSX      EAX,DX
//         004bfbeb     LEA        this,[EAX + EAX*0x4]
//         004bfbee     LEA        EAX,[this->pict_name[0]*0x4 + 0xc]
//         004bfbf5     MOV        this,0x3
//                               LAB_004bfbfa                                                 XREF[1]:     004bfc08(j)
//                              sprite.cpp:237 (23)
//         004bfbfa     MOV        EDI,dword ptr [ESI + 0x44]
//         004bfbfd     ADD        EAX,0x2
//         004bfc00     DEC        this
//         004bfc01     MOV        word ptr [EAX + EDI*0x1 + -0x2],0xffff
//         004bfc08     JNZ        LAB_004bfbfa
//         004bfc0a     INC        EDX
//         004bfc0b     CMP        DX,word ptr [ESI + 0x60]
//         004bfc0f     JL         LAB_004bfbe8
//                               LAB_004bfc11                                                 XREF[1]:     004bfbe6(j)
//                              sprite.cpp:239 (24)
//         004bfc11     CMP        word ptr [ESP + param_2],0x0
//         004bfc17     MOV        dword ptr [ESP + local_4],0x0
//         004bfc1f     JLE        LAB_004bfcd1
//         004bfc25     MOV        EDI,dword ptr [ESP + param_2]
//                               LAB_004bfc29                                                 XREF[1]:     004bfcb8(j)
//                              sprite.cpp:240 (38)
//         004bfc29     LEA        EDX=>last_facet,[ESP + 0x24]
//         004bfc2d     LEA        EAX=>local_e,[ESP + 0x26]
//         004bfc31     PUSH       EDX
//         004bfc32     MOV        EDX,dword ptr [ESP + param_1]
//         004bfc36     LEA        this=>index1,[ESP + 0x30]
//         004bfc3a     PUSH       EAX
//         004bfc3b     PUSH       this
//         004bfc3c     PUSH       s_%hd_%hd_%hd                                    = "%hd %hd %hd"
//         004bfc41     PUSH       EDX
//         004bfc42     CALL       fscanf                                           undefined fscanf()
//         004bfc47     ADD        ESP,0x14
//         004bfc4a     CMP        EAX,-0x1
//         004bfc4d     JZ         LAB_004bfcaa
//                              sprite.cpp:242 (11)
//         004bfc4f     MOV        EAX,dword ptr [ESP + index1]
//         004bfc53     CMP        word ptr [ESP + sound_facet],AX
//         004bfc58     JNZ        LAB_004bfc5d
//                              sprite.cpp:243 (1)
//         004bfc5a     INC        EDI
//                              sprite.cpp:244 (2)
//         004bfc5b     JMP        LAB_004bfc63
//                               LAB_004bfc5d                                                 XREF[1]:     004bfc58(j)
//                              sprite.cpp:246 (2)
//         004bfc5d     XOR        EDI,EDI
//                              sprite.cpp:247 (4)
//         004bfc5f     MOV        dword ptr [ESP + sound_facet],EAX
//                               LAB_004bfc63                                                 XREF[1]:     004bfc5b(j)
//                              sprite.cpp:251 (17)
//         004bfc63     TEST       AX,AX
//         004bfc66     JL         LAB_004bfcaa
//         004bfc68     CMP        AX,word ptr [ESI + 0x60]
//         004bfc6c     JGE        LAB_004bfcaa
//         004bfc6e     CMP        DI,0x3
//         004bfc72     JGE        LAB_004bfcaa
//                              sprite.cpp:253 (30)
//         004bfc74     MOVSX      EDX,word ptr [ESP + last_facet]
//         004bfc79     MOV        EBP,dword ptr [ESP + param_3]
//         004bfc7d     MOVSX      this,DI
//         004bfc80     MOVSX      EAX,AX
//         004bfc83     MOV        EDX,dword ptr [EBP + EDX*0x4]
//         004bfc87     LEA        EBX,[this->pict_name[0] + EAX*0x4]
//         004bfc8a     ADD        EAX,EBX
//         004bfc8c     MOV        EBX,dword ptr [ESI + 0x44]
//         004bfc8f     MOV        dword ptr [EBX + EAX*0x4],EDX
//                              sprite.cpp:254 (44)
//         004bfc92     MOV        EDX,dword ptr [ESI + 0x44]
//         004bfc95     MOVSX      EAX,word ptr [ESP + index1]
//         004bfc9a     LEA        EAX,[EAX + EAX*0x4]
//         004bfc9d     LEA        this,[this->pict_name[0] + EAX*0x2]
//         004bfca0     MOV        AX,word ptr [ESP + local_e]
//         004bfca5     MOV        word ptr [EDX + this->pict_name[0]*0x2 + 0xc],AX
//                               LAB_004bfcaa                                                 XREF[4]:     004bfc4d(j), 004bfc66(j),
//                                                                                                         004bfc6c(j), 004bfc72(j)
//         004bfcaa     MOV        EAX,dword ptr [ESP + local_4]
//         004bfcae     INC        EAX
//         004bfcaf     CMP        AX,word ptr [ESP + param_2]
//         004bfcb4     MOV        dword ptr [ESP + local_4],EAX
//         004bfcb8     JL         LAB_004bfc29
//                              sprite.cpp:262 (12)
//         004bfcbe     MOV        EAX,ESI
//         004bfcc0     POP        EDI
//         004bfcc1     POP        ESI
//         004bfcc2     POP        EBP
//         004bfcc3     POP        EBX
//         004bfcc4     ADD        ESP,0x24
//         004bfcc7     RET        0xc
//                               LAB_004bfcca                                                 XREF[1]:     004bfbc8(j)
//                              sprite.cpp:259 (7)
//         004bfcca     MOV        dword ptr [ESI + 0x44],0x0
//                               LAB_004bfcd1                                                 XREF[2]:     004bfac7(j), 004bfc1f(j)
//                              sprite.cpp:262 (12)
//         004bfcd1     MOV        EAX,ESI
//         004bfcd3     POP        EDI
//         004bfcd4     POP        ESI
//         004bfcd5     POP        EBP
//         004bfcd6     POP        EBX
//         004bfcd7     ADD        ESP,0x24
//         004bfcda     RET        0xc
//         004bfcdd     ??         90h
//         004bfcde     NOP
//         004bfcdf     NOP
}

RGE_Sprite::RGE_Sprite(int param_1, RGE_Sound** param_2, RGE_Color_Table** param_3) {
    /* TODO: Stub */
//                              undefined __thiscall RGE_Sprite(RGE_Sprite * this, _iobuf * param_1,
//              undefined         <UNASSIGNED>   <RETURN>
//              RGE_Sprite *      ECX:4 (auto)   this
//              _iobuf *          Stack[0x4]:4   param_1                   XREF[3]:     004bfa96(R), 004bfba3(R), 004bfc32(R)
//              short             Stack[0x8]:2   param_2                   XREF[6]:     004bfa28(R), 004bfa38(*), 004bfb27(R), 004bfc11(R),
//                                                                                     004bfc25(R), 004bfcaf(R)
//              RGE_Sound * *     Stack[0xc]:4   param_3                   XREF[2]:     004bfaf0(R), 004bfc79(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[3]:     004bfc17(W), 004bfcaa(R), 004bfcb4(W)
//              short             Stack[-0x8]:2  index1                    XREF[3]:     004bfc36(*), 004bfc4f(R), 004bfc95(R)
//              short             Stack[-0xc]:2  sound_facet               XREF[3]:     004bfab1(W), 004bfc53(R), 004bfc5f(W)
//              undefined2        Stack[-0xe]:2  local_e                   XREF[2]:     004bfc2d(*), 004bfca0(R)
//              short             Stack[-0x10]:2 last_facet                XREF[2]:     004bfc29(*), 004bfc74(R)
//              short             Stack[-0x12]:2 sound_frame               XREF[2]:     004bfa66(*), 004bfb60(R)
//              short             Stack[-0x14]:2 sound_id                  XREF[2]:     004bfa7a(*), 004bfb55(R)
//              short             Stack[-0x16]:2 temp_loop_once            XREF[2]:     004bfa6b(*), 004bfb46(R)
//              short             Stack[-0x18]:2 temp_randomize_on_start   XREF[2]:     004bfa70(*), 004bfb3b(R)
//              short             Stack[-0x1a]:2 temp_directional          XREF[2]:     004bfa75(*), 004bfb2c(R)
//              short             Stack[-0x1c]:2 temp_animated             XREF[2]:     004bfa83(*), 004bfb1e(R)
//              short             Stack[-0x1e]:2 temp_transparent_picking  XREF[2]:     004bfa88(*), 004bfb1a(R)
//              short             Stack[-0x20]:2 temp_draw_level           XREF[2]:     004bfa8d(*), 004bfafb(R)
//              short             Stack[-0x22]:2 temp_color_flag           XREF[2]:     004bfa3d(*), 004bfade(R)
//              short             Stack[-0x24]:2 temp_mirror_flag
//              short             Stack[-0x26]:2 temp_main_sound
//                               ??0RGE_Sprite@@QAE@PAU_iobuf@@FPAPAVRGE_Sound@@@Z            XREF[1]:     data_load_sprites:00541196(c)
//                               RGE_Sprite::RGE_Sprite
//                              sprite.cpp:140 (8)
//         004bfa20     SUB        ESP,0x24
//         004bfa23     PUSH       EBX
//         004bfa24     PUSH       EBP
//         004bfa25     PUSH       ESI
//         004bfa26     MOV        ESI,this
//                              sprite.cpp:163 (10)
//         004bfa28     MOV        this,word ptr [ESP + param_2]
//         004bfa2d     XOR        EAX,EAX
//         004bfa2f     MOV        dword ptr [ESI + 0x18],EAX
//                              sprite.cpp:164 (3)
//         004bfa32     MOV        dword ptr [ESI + 0x20],EAX
//                              sprite.cpp:165 (3)
//         004bfa35     MOV        dword ptr [ESI + 0x24],EAX
//                              sprite.cpp:195 (149)
//         004bfa38     LEA        EDX=>param_2,[ESP + 0x38]
//         004bfa3c     PUSH       EDI
//         004bfa3d     LEA        EAX=>temp_color_flag,[ESP + 0x12]
//         004bfa41     PUSH       EDX
//         004bfa42     MOV        word ptr [ESI + 0x72],this
//         004bfa46     LEA        EBP,[ESI + 0x36]
//         004bfa49     PUSH       EAX
//         004bfa4a     LEA        this,[ESI + 0x6c]
//         004bfa4d     PUSH       EBP
//         004bfa4e     LEA        EDX,[ESI + 0x68]
//         004bfa51     PUSH       this
//         004bfa52     LEA        EAX,[ESI + 0x64]
//         004bfa55     PUSH       EDX
//         004bfa56     LEA        this,[ESI + 0x34]
//         004bfa59     PUSH       EAX
//         004bfa5a     LEA        EDX,[ESI + 0x32]
//         004bfa5d     PUSH       this
//         004bfa5e     LEA        EAX,[ESI + 0x30]
//         004bfa61     PUSH       EDX
//         004bfa62     LEA        this,[ESI + 0x2e]
//         004bfa65     PUSH       EAX
//         004bfa66     LEA        EDX=>sound_frame,[ESP + 0x46]
//         004bfa6a     PUSH       this
//         004bfa6b     LEA        EAX=>temp_loop_once,[ESP + 0x46]
//         004bfa6f     PUSH       EDX
//         004bfa70     LEA        this=>temp_randomize_on_start,[ESP + 0x48]
//         004bfa74     PUSH       EAX
//         004bfa75     LEA        EDX=>temp_directional,[ESP + 0x4a]
//         004bfa79     PUSH       this
//         004bfa7a     LEA        EAX=>sound_id,[ESP + 0x54]
//         004bfa7e     PUSH       EDX
//         004bfa7f     LEA        this,[ESI + 0x2a]
//         004bfa82     PUSH       EAX
//         004bfa83     LEA        EDX=>temp_animated,[ESP + 0x54]
//         004bfa87     PUSH       this
//         004bfa88     LEA        EAX=>temp_transparent_picking_flag,[ESP + 0x56]
//         004bfa8c     PUSH       EDX
//         004bfa8d     LEA        this=>temp_draw_level,[ESP + 0x58]
//         004bfa91     LEA        EBX,[ESI + 0x60]
//         004bfa94     PUSH       EAX
//         004bfa95     PUSH       this
//         004bfa96     MOV        this,dword ptr [ESP + param_1]
//         004bfa9d     LEA        EDX,[ESI + 0x5e]
//         004bfaa0     PUSH       EBX
//         004bfaa1     LEA        EAX,[ESI + 0x10]
//         004bfaa4     PUSH       EDX
//         004bfaa5     LEA        EDI,[ESI + 0x48]
//         004bfaa8     PUSH       EAX
//         004bfaa9     PUSH       ESI
//         004bfaaa     PUSH       EDI
//         004bfaab     PUSH       s__%s_%s_%d_%hd_%hd_%hd_%hd_%hd_%h               = " %s %s %d %hd %hd %hd %hd %hd %hd %hd %hd
//         004bfab0     PUSH       this
//         004bfab1     MOV        dword ptr [ESP + sound_facet],0xffffffff
//         004bfabc     CALL       fscanf                                           undefined fscanf()
//         004bfac1     ADD        ESP,0x68
//         004bfac4     CMP        EAX,-0x1
//         004bfac7     JZ         LAB_004bfcd1
//                              sprite.cpp:200 (17)
//         004bfacd     PUSH       EDI
//         004bface     MOV        byte ptr [ESI + 0x14],0x0
//         004bfad2     MOV        dword ptr [ESI + 0x1c],0x0
//         004bfad9     CALL       convert_us                                       void convert_us(char * param_1)
//                              sprite.cpp:201 (29)
//         004bfade     MOV        AX,word ptr [ESP + temp_color_flag]
//         004bfae3     XOR        EDI,EDI
//         004bfae5     ADD        ESP,0x4
//         004bfae8     CMP        AX,DI
//         004bfaeb     JL         LAB_004bfaf9
//         004bfaed     MOVSX      EDX,AX
//         004bfaf0     MOV        EAX,dword ptr [ESP + param_3]
//         004bfaf4     MOV        EAX,dword ptr [EAX + EDX*0x4]
//         004bfaf7     JMP        LAB_004bfafb
//                               LAB_004bfaf9                                                 XREF[1]:     004bfaeb(j)
//         004bfaf9     XOR        EAX,EAX
//                               LAB_004bfafb                                                 XREF[1]:     004bfaf7(j)
//                              sprite.cpp:203 (10)
//         004bfafb     CMP        word ptr [ESP + temp_draw_level],DI
//         004bfb00     MOV        dword ptr [ESI + 0x3c],EAX
//         004bfb03     JLE        LAB_004bfb16
//                              sprite.cpp:204 (15)
//         004bfb05     MOV        BX,word ptr [EBX]
//         004bfb08     MOV        this,EBX
//         004bfb0a     SAR        this,0x1
//         004bfb0c     SAR        EBX,0x2
//         004bfb0f     ADD        this,BL
//         004bfb11     MOV        byte ptr [ESI + 0x74],this
//                              sprite.cpp:205 (2)
//         004bfb14     JMP        LAB_004bfb1a
//                               LAB_004bfb16                                                 XREF[1]:     004bfb03(j)
//                              sprite.cpp:206 (4)
//         004bfb16     MOV        byte ptr [ESI + 0x74],0x0
//                               LAB_004bfb1a                                                 XREF[1]:     004bfb14(j)
//                              sprite.cpp:208 (4)
//         004bfb1a     MOV        DL,byte ptr [ESP + temp_transparent_picking_fl
//                              sprite.cpp:212 (27)
//         004bfb1e     MOV        AL,byte ptr [ESP + temp_animated]
//         004bfb22     MOV        byte ptr [ESI + 0x28],DL
//         004bfb25     XOR        EDX,EDX
//         004bfb27     CMP        word ptr [ESP + param_2],DI
//         004bfb2c     MOV        this,byte ptr [ESP + temp_directional]
//         004bfb30     MOV        byte ptr [ESI + 0x29],AL
//         004bfb33     MOV        byte ptr [ESI + 0x2c],this
//         004bfb36     SETG       DL
//                              sprite.cpp:214 (13)
//         004bfb39     XOR        EAX,EAX
//         004bfb3b     CMP        word ptr [ESP + temp_randomize_on_start],DI
//         004bfb40     MOV        byte ptr [ESI + 0x40],DL
//         004bfb43     SETG       AL
//                              sprite.cpp:215 (15)
//         004bfb46     CMP        word ptr [ESP + temp_loop_once],DI
//         004bfb4b     MOV        byte ptr [ESI + 0x70],AL
//         004bfb4e     JZ         LAB_004bfb55
//         004bfb50     ADD        AL,0x2
//         004bfb52     MOV        byte ptr [ESI + 0x70],AL
//                               LAB_004bfb55                                                 XREF[1]:     004bfb4e(j)
//                              sprite.cpp:216 (11)
//         004bfb55     CMP        word ptr [ESP + sound_id],DI
//         004bfb5a     JZ         LAB_004bfb60
//         004bfb5c     ADD        byte ptr [ESI + 0x70],0x4
//                               LAB_004bfb60                                                 XREF[1]:     004bfb5a(j)
//                              sprite.cpp:217 (11)
//         004bfb60     CMP        word ptr [ESP + sound_frame],DI
//         004bfb65     JZ         LAB_004bfb6b
//         004bfb67     ADD        byte ptr [ESI + 0x70],0x8
//                               LAB_004bfb6b                                                 XREF[1]:     004bfb65(j)
//                              sprite.cpp:219 (9)
//         004bfb6b     MOV        AX,word ptr [EBP]
//         004bfb6f     CMP        AX,DI
//         004bfb72     JLE        LAB_004bfbc0
//                              sprite.cpp:221 (14)
//         004bfb74     MOVSX      EAX,AX
//         004bfb77     PUSH       0x10
//         004bfb79     PUSH       EAX
//         004bfb7a     CALL       calloc                                           undefined calloc()
//         004bfb7f     ADD        ESP,0x8
//                              sprite.cpp:222 (10)
//         004bfb82     CMP        word ptr [EBP],0x0
//         004bfb87     MOV        dword ptr [ESI + 0x38],EAX
//         004bfb8a     JLE        LAB_004bfbc3
//                               LAB_004bfb8c                                                 XREF[1]:     004bfbbc(j)
//                              sprite.cpp:227 (50)
//         004bfb8c     MOV        EDX,dword ptr [ESI + 0x38]
//         004bfb8f     MOVSX      this,DI
//         004bfb92     SHL        this,0x4
//         004bfb95     LEA        EAX,[this->pict_name[0] + EDX*0x1]
//         004bfb98     LEA        this,[EAX + 0xc]
//         004bfb9b     LEA        EDX,[EAX + 0xa]
//         004bfb9e     PUSH       this
//         004bfb9f     LEA        this,[EAX + 0x8]
//         004bfba2     PUSH       EDX
//         004bfba3     MOV        EDX,dword ptr [ESP + param_1]
//         004bfba7     PUSH       this
//         004bfba8     PUSH       EAX
//         004bfba9     PUSH       s__%hd_%hd_%hd_%hd                               = " %hd %hd %hd %hd"
//         004bfbae     PUSH       EDX
//         004bfbaf     CALL       fscanf                                           undefined fscanf()
//         004bfbb4     ADD        ESP,0x18
//         004bfbb7     INC        EDI
//         004bfbb8     CMP        DI,word ptr [EBP]
//         004bfbbc     JL         LAB_004bfb8c
//                              sprite.cpp:229 (2)
//         004bfbbe     JMP        LAB_004bfbc3
//                               LAB_004bfbc0                                                 XREF[1]:     004bfb72(j)
//                              sprite.cpp:230 (3)
//         004bfbc0     MOV        dword ptr [ESI + 0x38],EDI
//                               LAB_004bfbc3                                                 XREF[2]:     004bfb8a(j), 004bfbbe(j)
//                              sprite.cpp:232 (11)
//         004bfbc3     MOV        AL,byte ptr [ESI + 0x40]
//         004bfbc6     TEST       AL,AL
//         004bfbc8     JZ         LAB_004bfcca
//                              sprite.cpp:234 (12)
//         004bfbce     MOVSX      EAX,word ptr [ESI + 0x60]
//         004bfbd2     PUSH       0x14
//         004bfbd4     PUSH       EAX
//         004bfbd5     CALL       calloc                                           undefined calloc()
//                              sprite.cpp:235 (14)
//         004bfbda     XOR        EDX,EDX
//         004bfbdc     ADD        ESP,0x8
//         004bfbdf     CMP        word ptr [ESI + 0x60],DX
//         004bfbe3     MOV        dword ptr [ESI + 0x44],EAX
//         004bfbe6     JLE        LAB_004bfc11
//                               LAB_004bfbe8                                                 XREF[1]:     004bfc0f(j)
//                              sprite.cpp:236 (18)
//         004bfbe8     MOVSX      EAX,DX
//         004bfbeb     LEA        this,[EAX + EAX*0x4]
//         004bfbee     LEA        EAX,[this->pict_name[0]*0x4 + 0xc]
//         004bfbf5     MOV        this,0x3
//                               LAB_004bfbfa                                                 XREF[1]:     004bfc08(j)
//                              sprite.cpp:237 (23)
//         004bfbfa     MOV        EDI,dword ptr [ESI + 0x44]
//         004bfbfd     ADD        EAX,0x2
//         004bfc00     DEC        this
//         004bfc01     MOV        word ptr [EAX + EDI*0x1 + -0x2],0xffff
//         004bfc08     JNZ        LAB_004bfbfa
//         004bfc0a     INC        EDX
//         004bfc0b     CMP        DX,word ptr [ESI + 0x60]
//         004bfc0f     JL         LAB_004bfbe8
//                               LAB_004bfc11                                                 XREF[1]:     004bfbe6(j)
//                              sprite.cpp:239 (24)
//         004bfc11     CMP        word ptr [ESP + param_2],0x0
//         004bfc17     MOV        dword ptr [ESP + local_4],0x0
//         004bfc1f     JLE        LAB_004bfcd1
//         004bfc25     MOV        EDI,dword ptr [ESP + param_2]
//                               LAB_004bfc29                                                 XREF[1]:     004bfcb8(j)
//                              sprite.cpp:240 (38)
//         004bfc29     LEA        EDX=>last_facet,[ESP + 0x24]
//         004bfc2d     LEA        EAX=>local_e,[ESP + 0x26]
//         004bfc31     PUSH       EDX
//         004bfc32     MOV        EDX,dword ptr [ESP + param_1]
//         004bfc36     LEA        this=>index1,[ESP + 0x30]
//         004bfc3a     PUSH       EAX
//         004bfc3b     PUSH       this
//         004bfc3c     PUSH       s_%hd_%hd_%hd                                    = "%hd %hd %hd"
//         004bfc41     PUSH       EDX
//         004bfc42     CALL       fscanf                                           undefined fscanf()
//         004bfc47     ADD        ESP,0x14
//         004bfc4a     CMP        EAX,-0x1
//         004bfc4d     JZ         LAB_004bfcaa
//                              sprite.cpp:242 (11)
//         004bfc4f     MOV        EAX,dword ptr [ESP + index1]
//         004bfc53     CMP        word ptr [ESP + sound_facet],AX
//         004bfc58     JNZ        LAB_004bfc5d
//                              sprite.cpp:243 (1)
//         004bfc5a     INC        EDI
//                              sprite.cpp:244 (2)
//         004bfc5b     JMP        LAB_004bfc63
//                               LAB_004bfc5d                                                 XREF[1]:     004bfc58(j)
//                              sprite.cpp:246 (2)
//         004bfc5d     XOR        EDI,EDI
//                              sprite.cpp:247 (4)
//         004bfc5f     MOV        dword ptr [ESP + sound_facet],EAX
//                               LAB_004bfc63                                                 XREF[1]:     004bfc5b(j)
//                              sprite.cpp:251 (17)
//         004bfc63     TEST       AX,AX
//         004bfc66     JL         LAB_004bfcaa
//         004bfc68     CMP        AX,word ptr [ESI + 0x60]
//         004bfc6c     JGE        LAB_004bfcaa
//         004bfc6e     CMP        DI,0x3
//         004bfc72     JGE        LAB_004bfcaa
//                              sprite.cpp:253 (30)
//         004bfc74     MOVSX      EDX,word ptr [ESP + last_facet]
//         004bfc79     MOV        EBP,dword ptr [ESP + param_3]
//         004bfc7d     MOVSX      this,DI
//         004bfc80     MOVSX      EAX,AX
//         004bfc83     MOV        EDX,dword ptr [EBP + EDX*0x4]
//         004bfc87     LEA        EBX,[this->pict_name[0] + EAX*0x4]
//         004bfc8a     ADD        EAX,EBX
//         004bfc8c     MOV        EBX,dword ptr [ESI + 0x44]
//         004bfc8f     MOV        dword ptr [EBX + EAX*0x4],EDX
//                              sprite.cpp:254 (44)
//         004bfc92     MOV        EDX,dword ptr [ESI + 0x44]
//         004bfc95     MOVSX      EAX,word ptr [ESP + index1]
//         004bfc9a     LEA        EAX,[EAX + EAX*0x4]
//         004bfc9d     LEA        this,[this->pict_name[0] + EAX*0x2]
//         004bfca0     MOV        AX,word ptr [ESP + local_e]
//         004bfca5     MOV        word ptr [EDX + this->pict_name[0]*0x2 + 0xc],AX
//                               LAB_004bfcaa                                                 XREF[4]:     004bfc4d(j), 004bfc66(j),
//                                                                                                         004bfc6c(j), 004bfc72(j)
//         004bfcaa     MOV        EAX,dword ptr [ESP + local_4]
//         004bfcae     INC        EAX
//         004bfcaf     CMP        AX,word ptr [ESP + param_2]
//         004bfcb4     MOV        dword ptr [ESP + local_4],EAX
//         004bfcb8     JL         LAB_004bfc29
//                              sprite.cpp:262 (12)
//         004bfcbe     MOV        EAX,ESI
//         004bfcc0     POP        EDI
//         004bfcc1     POP        ESI
//         004bfcc2     POP        EBP
//         004bfcc3     POP        EBX
//         004bfcc4     ADD        ESP,0x24
//         004bfcc7     RET        0xc
//                               LAB_004bfcca                                                 XREF[1]:     004bfbc8(j)
//                              sprite.cpp:259 (7)
//         004bfcca     MOV        dword ptr [ESI + 0x44],0x0
//                               LAB_004bfcd1                                                 XREF[2]:     004bfac7(j), 004bfc1f(j)
//                              sprite.cpp:262 (12)
//         004bfcd1     MOV        EAX,ESI
//         004bfcd3     POP        EDI
//         004bfcd4     POP        ESI
//         004bfcd5     POP        EBP
//         004bfcd6     POP        EBX
//         004bfcd7     ADD        ESP,0x24
//         004bfcda     RET        0xc
//         004bfcdd     ??         90h
//         004bfcde     NOP
//         004bfcdf     NOP
}

RGE_Sprite::RGE_Sprite(_iobuf* param_1, short param_2, RGE_Sound** param_3) {
    /* TODO: Stub */
//                              undefined __thiscall RGE_Sprite(RGE_Sprite * this, _iobuf * param_1,
//              undefined         <UNASSIGNED>   <RETURN>
//              RGE_Sprite *      ECX:4 (auto)   this
//              _iobuf *          Stack[0x4]:4   param_1                   XREF[3]:     004bfa96(R), 004bfba3(R), 004bfc32(R)
//              short             Stack[0x8]:2   param_2                   XREF[6]:     004bfa28(R), 004bfa38(*), 004bfb27(R), 004bfc11(R),
//                                                                                     004bfc25(R), 004bfcaf(R)
//              RGE_Sound * *     Stack[0xc]:4   param_3                   XREF[2]:     004bfaf0(R), 004bfc79(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[3]:     004bfc17(W), 004bfcaa(R), 004bfcb4(W)
//              short             Stack[-0x8]:2  index1                    XREF[3]:     004bfc36(*), 004bfc4f(R), 004bfc95(R)
//              short             Stack[-0xc]:2  sound_facet               XREF[3]:     004bfab1(W), 004bfc53(R), 004bfc5f(W)
//              undefined2        Stack[-0xe]:2  local_e                   XREF[2]:     004bfc2d(*), 004bfca0(R)
//              short             Stack[-0x10]:2 last_facet                XREF[2]:     004bfc29(*), 004bfc74(R)
//              short             Stack[-0x12]:2 sound_frame               XREF[2]:     004bfa66(*), 004bfb60(R)
//              short             Stack[-0x14]:2 sound_id                  XREF[2]:     004bfa7a(*), 004bfb55(R)
//              short             Stack[-0x16]:2 temp_loop_once            XREF[2]:     004bfa6b(*), 004bfb46(R)
//              short             Stack[-0x18]:2 temp_randomize_on_start   XREF[2]:     004bfa70(*), 004bfb3b(R)
//              short             Stack[-0x1a]:2 temp_directional          XREF[2]:     004bfa75(*), 004bfb2c(R)
//              short             Stack[-0x1c]:2 temp_animated             XREF[2]:     004bfa83(*), 004bfb1e(R)
//              short             Stack[-0x1e]:2 temp_transparent_picking  XREF[2]:     004bfa88(*), 004bfb1a(R)
//              short             Stack[-0x20]:2 temp_draw_level           XREF[2]:     004bfa8d(*), 004bfafb(R)
//              short             Stack[-0x22]:2 temp_color_flag           XREF[2]:     004bfa3d(*), 004bfade(R)
//              short             Stack[-0x24]:2 temp_mirror_flag
//              short             Stack[-0x26]:2 temp_main_sound
//                               ??0RGE_Sprite@@QAE@PAU_iobuf@@FPAPAVRGE_Sound@@@Z            XREF[1]:     data_load_sprites:00541196(c)
//                               RGE_Sprite::RGE_Sprite
//                              sprite.cpp:140 (8)
//         004bfa20     SUB        ESP,0x24
//         004bfa23     PUSH       EBX
//         004bfa24     PUSH       EBP
//         004bfa25     PUSH       ESI
//         004bfa26     MOV        ESI,this
//                              sprite.cpp:163 (10)
//         004bfa28     MOV        this,word ptr [ESP + param_2]
//         004bfa2d     XOR        EAX,EAX
//         004bfa2f     MOV        dword ptr [ESI + 0x18],EAX
//                              sprite.cpp:164 (3)
//         004bfa32     MOV        dword ptr [ESI + 0x20],EAX
//                              sprite.cpp:165 (3)
//         004bfa35     MOV        dword ptr [ESI + 0x24],EAX
//                              sprite.cpp:195 (149)
//         004bfa38     LEA        EDX=>param_2,[ESP + 0x38]
//         004bfa3c     PUSH       EDI
//         004bfa3d     LEA        EAX=>temp_color_flag,[ESP + 0x12]
//         004bfa41     PUSH       EDX
//         004bfa42     MOV        word ptr [ESI + 0x72],this
//         004bfa46     LEA        EBP,[ESI + 0x36]
//         004bfa49     PUSH       EAX
//         004bfa4a     LEA        this,[ESI + 0x6c]
//         004bfa4d     PUSH       EBP
//         004bfa4e     LEA        EDX,[ESI + 0x68]
//         004bfa51     PUSH       this
//         004bfa52     LEA        EAX,[ESI + 0x64]
//         004bfa55     PUSH       EDX
//         004bfa56     LEA        this,[ESI + 0x34]
//         004bfa59     PUSH       EAX
//         004bfa5a     LEA        EDX,[ESI + 0x32]
//         004bfa5d     PUSH       this
//         004bfa5e     LEA        EAX,[ESI + 0x30]
//         004bfa61     PUSH       EDX
//         004bfa62     LEA        this,[ESI + 0x2e]
//         004bfa65     PUSH       EAX
//         004bfa66     LEA        EDX=>sound_frame,[ESP + 0x46]
//         004bfa6a     PUSH       this
//         004bfa6b     LEA        EAX=>temp_loop_once,[ESP + 0x46]
//         004bfa6f     PUSH       EDX
//         004bfa70     LEA        this=>temp_randomize_on_start,[ESP + 0x48]
//         004bfa74     PUSH       EAX
//         004bfa75     LEA        EDX=>temp_directional,[ESP + 0x4a]
//         004bfa79     PUSH       this
//         004bfa7a     LEA        EAX=>sound_id,[ESP + 0x54]
//         004bfa7e     PUSH       EDX
//         004bfa7f     LEA        this,[ESI + 0x2a]
//         004bfa82     PUSH       EAX
//         004bfa83     LEA        EDX=>temp_animated,[ESP + 0x54]
//         004bfa87     PUSH       this
//         004bfa88     LEA        EAX=>temp_transparent_picking_flag,[ESP + 0x56]
//         004bfa8c     PUSH       EDX
//         004bfa8d     LEA        this=>temp_draw_level,[ESP + 0x58]
//         004bfa91     LEA        EBX,[ESI + 0x60]
//         004bfa94     PUSH       EAX
//         004bfa95     PUSH       this
//         004bfa96     MOV        this,dword ptr [ESP + param_1]
//         004bfa9d     LEA        EDX,[ESI + 0x5e]
//         004bfaa0     PUSH       EBX
//         004bfaa1     LEA        EAX,[ESI + 0x10]
//         004bfaa4     PUSH       EDX
//         004bfaa5     LEA        EDI,[ESI + 0x48]
//         004bfaa8     PUSH       EAX
//         004bfaa9     PUSH       ESI
//         004bfaaa     PUSH       EDI
//         004bfaab     PUSH       s__%s_%s_%d_%hd_%hd_%hd_%hd_%hd_%h               = " %s %s %d %hd %hd %hd %hd %hd %hd %hd %hd
//         004bfab0     PUSH       this
//         004bfab1     MOV        dword ptr [ESP + sound_facet],0xffffffff
//         004bfabc     CALL       fscanf                                           undefined fscanf()
//         004bfac1     ADD        ESP,0x68
//         004bfac4     CMP        EAX,-0x1
//         004bfac7     JZ         LAB_004bfcd1
//                              sprite.cpp:200 (17)
//         004bfacd     PUSH       EDI
//         004bface     MOV        byte ptr [ESI + 0x14],0x0
//         004bfad2     MOV        dword ptr [ESI + 0x1c],0x0
//         004bfad9     CALL       convert_us                                       void convert_us(char * param_1)
//                              sprite.cpp:201 (29)
//         004bfade     MOV        AX,word ptr [ESP + temp_color_flag]
//         004bfae3     XOR        EDI,EDI
//         004bfae5     ADD        ESP,0x4
//         004bfae8     CMP        AX,DI
//         004bfaeb     JL         LAB_004bfaf9
//         004bfaed     MOVSX      EDX,AX
//         004bfaf0     MOV        EAX,dword ptr [ESP + param_3]
//         004bfaf4     MOV        EAX,dword ptr [EAX + EDX*0x4]
//         004bfaf7     JMP        LAB_004bfafb
//                               LAB_004bfaf9                                                 XREF[1]:     004bfaeb(j)
//         004bfaf9     XOR        EAX,EAX
//                               LAB_004bfafb                                                 XREF[1]:     004bfaf7(j)
//                              sprite.cpp:203 (10)
//         004bfafb     CMP        word ptr [ESP + temp_draw_level],DI
//         004bfb00     MOV        dword ptr [ESI + 0x3c],EAX
//         004bfb03     JLE        LAB_004bfb16
//                              sprite.cpp:204 (15)
//         004bfb05     MOV        BX,word ptr [EBX]
//         004bfb08     MOV        this,EBX
//         004bfb0a     SAR        this,0x1
//         004bfb0c     SAR        EBX,0x2
//         004bfb0f     ADD        this,BL
//         004bfb11     MOV        byte ptr [ESI + 0x74],this
//                              sprite.cpp:205 (2)
//         004bfb14     JMP        LAB_004bfb1a
//                               LAB_004bfb16                                                 XREF[1]:     004bfb03(j)
//                              sprite.cpp:206 (4)
//         004bfb16     MOV        byte ptr [ESI + 0x74],0x0
//                               LAB_004bfb1a                                                 XREF[1]:     004bfb14(j)
//                              sprite.cpp:208 (4)
//         004bfb1a     MOV        DL,byte ptr [ESP + temp_transparent_picking_fl
//                              sprite.cpp:212 (27)
//         004bfb1e     MOV        AL,byte ptr [ESP + temp_animated]
//         004bfb22     MOV        byte ptr [ESI + 0x28],DL
//         004bfb25     XOR        EDX,EDX
//         004bfb27     CMP        word ptr [ESP + param_2],DI
//         004bfb2c     MOV        this,byte ptr [ESP + temp_directional]
//         004bfb30     MOV        byte ptr [ESI + 0x29],AL
//         004bfb33     MOV        byte ptr [ESI + 0x2c],this
//         004bfb36     SETG       DL
//                              sprite.cpp:214 (13)
//         004bfb39     XOR        EAX,EAX
//         004bfb3b     CMP        word ptr [ESP + temp_randomize_on_start],DI
//         004bfb40     MOV        byte ptr [ESI + 0x40],DL
//         004bfb43     SETG       AL
//                              sprite.cpp:215 (15)
//         004bfb46     CMP        word ptr [ESP + temp_loop_once],DI
//         004bfb4b     MOV        byte ptr [ESI + 0x70],AL
//         004bfb4e     JZ         LAB_004bfb55
//         004bfb50     ADD        AL,0x2
//         004bfb52     MOV        byte ptr [ESI + 0x70],AL
//                               LAB_004bfb55                                                 XREF[1]:     004bfb4e(j)
//                              sprite.cpp:216 (11)
//         004bfb55     CMP        word ptr [ESP + sound_id],DI
//         004bfb5a     JZ         LAB_004bfb60
//         004bfb5c     ADD        byte ptr [ESI + 0x70],0x4
//                               LAB_004bfb60                                                 XREF[1]:     004bfb5a(j)
//                              sprite.cpp:217 (11)
//         004bfb60     CMP        word ptr [ESP + sound_frame],DI
//         004bfb65     JZ         LAB_004bfb6b
//         004bfb67     ADD        byte ptr [ESI + 0x70],0x8
//                               LAB_004bfb6b                                                 XREF[1]:     004bfb65(j)
//                              sprite.cpp:219 (9)
//         004bfb6b     MOV        AX,word ptr [EBP]
//         004bfb6f     CMP        AX,DI
//         004bfb72     JLE        LAB_004bfbc0
//                              sprite.cpp:221 (14)
//         004bfb74     MOVSX      EAX,AX
//         004bfb77     PUSH       0x10
//         004bfb79     PUSH       EAX
//         004bfb7a     CALL       calloc                                           undefined calloc()
//         004bfb7f     ADD        ESP,0x8
//                              sprite.cpp:222 (10)
//         004bfb82     CMP        word ptr [EBP],0x0
//         004bfb87     MOV        dword ptr [ESI + 0x38],EAX
//         004bfb8a     JLE        LAB_004bfbc3
//                               LAB_004bfb8c                                                 XREF[1]:     004bfbbc(j)
//                              sprite.cpp:227 (50)
//         004bfb8c     MOV        EDX,dword ptr [ESI + 0x38]
//         004bfb8f     MOVSX      this,DI
//         004bfb92     SHL        this,0x4
//         004bfb95     LEA        EAX,[this->pict_name[0] + EDX*0x1]
//         004bfb98     LEA        this,[EAX + 0xc]
//         004bfb9b     LEA        EDX,[EAX + 0xa]
//         004bfb9e     PUSH       this
//         004bfb9f     LEA        this,[EAX + 0x8]
//         004bfba2     PUSH       EDX
//         004bfba3     MOV        EDX,dword ptr [ESP + param_1]
//         004bfba7     PUSH       this
//         004bfba8     PUSH       EAX
//         004bfba9     PUSH       s__%hd_%hd_%hd_%hd                               = " %hd %hd %hd %hd"
//         004bfbae     PUSH       EDX
//         004bfbaf     CALL       fscanf                                           undefined fscanf()
//         004bfbb4     ADD        ESP,0x18
//         004bfbb7     INC        EDI
//         004bfbb8     CMP        DI,word ptr [EBP]
//         004bfbbc     JL         LAB_004bfb8c
//                              sprite.cpp:229 (2)
//         004bfbbe     JMP        LAB_004bfbc3
//                               LAB_004bfbc0                                                 XREF[1]:     004bfb72(j)
//                              sprite.cpp:230 (3)
//         004bfbc0     MOV        dword ptr [ESI + 0x38],EDI
//                               LAB_004bfbc3                                                 XREF[2]:     004bfb8a(j), 004bfbbe(j)
//                              sprite.cpp:232 (11)
//         004bfbc3     MOV        AL,byte ptr [ESI + 0x40]
//         004bfbc6     TEST       AL,AL
//         004bfbc8     JZ         LAB_004bfcca
//                              sprite.cpp:234 (12)
//         004bfbce     MOVSX      EAX,word ptr [ESI + 0x60]
//         004bfbd2     PUSH       0x14
//         004bfbd4     PUSH       EAX
//         004bfbd5     CALL       calloc                                           undefined calloc()
//                              sprite.cpp:235 (14)
//         004bfbda     XOR        EDX,EDX
//         004bfbdc     ADD        ESP,0x8
//         004bfbdf     CMP        word ptr [ESI + 0x60],DX
//         004bfbe3     MOV        dword ptr [ESI + 0x44],EAX
//         004bfbe6     JLE        LAB_004bfc11
//                               LAB_004bfbe8                                                 XREF[1]:     004bfc0f(j)
//                              sprite.cpp:236 (18)
//         004bfbe8     MOVSX      EAX,DX
//         004bfbeb     LEA        this,[EAX + EAX*0x4]
//         004bfbee     LEA        EAX,[this->pict_name[0]*0x4 + 0xc]
//         004bfbf5     MOV        this,0x3
//                               LAB_004bfbfa                                                 XREF[1]:     004bfc08(j)
//                              sprite.cpp:237 (23)
//         004bfbfa     MOV        EDI,dword ptr [ESI + 0x44]
//         004bfbfd     ADD        EAX,0x2
//         004bfc00     DEC        this
//         004bfc01     MOV        word ptr [EAX + EDI*0x1 + -0x2],0xffff
//         004bfc08     JNZ        LAB_004bfbfa
//         004bfc0a     INC        EDX
//         004bfc0b     CMP        DX,word ptr [ESI + 0x60]
//         004bfc0f     JL         LAB_004bfbe8
//                               LAB_004bfc11                                                 XREF[1]:     004bfbe6(j)
//                              sprite.cpp:239 (24)
//         004bfc11     CMP        word ptr [ESP + param_2],0x0
//         004bfc17     MOV        dword ptr [ESP + local_4],0x0
//         004bfc1f     JLE        LAB_004bfcd1
//         004bfc25     MOV        EDI,dword ptr [ESP + param_2]
//                               LAB_004bfc29                                                 XREF[1]:     004bfcb8(j)
//                              sprite.cpp:240 (38)
//         004bfc29     LEA        EDX=>last_facet,[ESP + 0x24]
//         004bfc2d     LEA        EAX=>local_e,[ESP + 0x26]
//         004bfc31     PUSH       EDX
//         004bfc32     MOV        EDX,dword ptr [ESP + param_1]
//         004bfc36     LEA        this=>index1,[ESP + 0x30]
//         004bfc3a     PUSH       EAX
//         004bfc3b     PUSH       this
//         004bfc3c     PUSH       s_%hd_%hd_%hd                                    = "%hd %hd %hd"
//         004bfc41     PUSH       EDX
//         004bfc42     CALL       fscanf                                           undefined fscanf()
//         004bfc47     ADD        ESP,0x14
//         004bfc4a     CMP        EAX,-0x1
//         004bfc4d     JZ         LAB_004bfcaa
//                              sprite.cpp:242 (11)
//         004bfc4f     MOV        EAX,dword ptr [ESP + index1]
//         004bfc53     CMP        word ptr [ESP + sound_facet],AX
//         004bfc58     JNZ        LAB_004bfc5d
//                              sprite.cpp:243 (1)
//         004bfc5a     INC        EDI
//                              sprite.cpp:244 (2)
//         004bfc5b     JMP        LAB_004bfc63
//                               LAB_004bfc5d                                                 XREF[1]:     004bfc58(j)
//                              sprite.cpp:246 (2)
//         004bfc5d     XOR        EDI,EDI
//                              sprite.cpp:247 (4)
//         004bfc5f     MOV        dword ptr [ESP + sound_facet],EAX
//                               LAB_004bfc63                                                 XREF[1]:     004bfc5b(j)
//                              sprite.cpp:251 (17)
//         004bfc63     TEST       AX,AX
//         004bfc66     JL         LAB_004bfcaa
//         004bfc68     CMP        AX,word ptr [ESI + 0x60]
//         004bfc6c     JGE        LAB_004bfcaa
//         004bfc6e     CMP        DI,0x3
//         004bfc72     JGE        LAB_004bfcaa
//                              sprite.cpp:253 (30)
//         004bfc74     MOVSX      EDX,word ptr [ESP + last_facet]
//         004bfc79     MOV        EBP,dword ptr [ESP + param_3]
//         004bfc7d     MOVSX      this,DI
//         004bfc80     MOVSX      EAX,AX
//         004bfc83     MOV        EDX,dword ptr [EBP + EDX*0x4]
//         004bfc87     LEA        EBX,[this->pict_name[0] + EAX*0x4]
//         004bfc8a     ADD        EAX,EBX
//         004bfc8c     MOV        EBX,dword ptr [ESI + 0x44]
//         004bfc8f     MOV        dword ptr [EBX + EAX*0x4],EDX
//                              sprite.cpp:254 (44)
//         004bfc92     MOV        EDX,dword ptr [ESI + 0x44]
//         004bfc95     MOVSX      EAX,word ptr [ESP + index1]
//         004bfc9a     LEA        EAX,[EAX + EAX*0x4]
//         004bfc9d     LEA        this,[this->pict_name[0] + EAX*0x2]
//         004bfca0     MOV        AX,word ptr [ESP + local_e]
//         004bfca5     MOV        word ptr [EDX + this->pict_name[0]*0x2 + 0xc],AX
//                               LAB_004bfcaa                                                 XREF[4]:     004bfc4d(j), 004bfc66(j),
//                                                                                                         004bfc6c(j), 004bfc72(j)
//         004bfcaa     MOV        EAX,dword ptr [ESP + local_4]
//         004bfcae     INC        EAX
//         004bfcaf     CMP        AX,word ptr [ESP + param_2]
//         004bfcb4     MOV        dword ptr [ESP + local_4],EAX
//         004bfcb8     JL         LAB_004bfc29
//                              sprite.cpp:262 (12)
//         004bfcbe     MOV        EAX,ESI
//         004bfcc0     POP        EDI
//         004bfcc1     POP        ESI
//         004bfcc2     POP        EBP
//         004bfcc3     POP        EBX
//         004bfcc4     ADD        ESP,0x24
//         004bfcc7     RET        0xc
//                               LAB_004bfcca                                                 XREF[1]:     004bfbc8(j)
//                              sprite.cpp:259 (7)
//         004bfcca     MOV        dword ptr [ESI + 0x44],0x0
//                               LAB_004bfcd1                                                 XREF[2]:     004bfac7(j), 004bfc1f(j)
//                              sprite.cpp:262 (12)
//         004bfcd1     MOV        EAX,ESI
//         004bfcd3     POP        EDI
//         004bfcd4     POP        ESI
//         004bfcd5     POP        EBP
//         004bfcd6     POP        EBX
//         004bfcd7     ADD        ESP,0x24
//         004bfcda     RET        0xc
//         004bfcdd     ??         90h
//         004bfcde     NOP
//         004bfcdf     NOP
}

RGE_Sprite::~RGE_Sprite() {
    /* TODO: Stub */
//                              void __thiscall ~RGE_Sprite(RGE_Sprite * this)
//              void              <VOID>         <RETURN>
//              RGE_Sprite *      ECX:4 (auto)   this
//                               ??1RGE_Sprite@@QAE@XZ                                        XREF[1]:     ~RGE_Game_World:00540b8d(c)
//                               RGE_Sprite::~RGE_Sprite
//                              sprite.cpp:267 (5)
//         004bfce0     PUSH       EBX
//         004bfce1     PUSH       ESI
//         004bfce2     MOV        ESI,this
//         004bfce4     PUSH       EDI
//                              sprite.cpp:268 (14)
//         004bfce5     XOR        EBX,EBX
//         004bfce7     MOV        EDI,dword ptr [ESI + 0x1c]
//         004bfcea     CMP        EDI,EBX
//         004bfcec     JZ         LAB_004bfd0a
//         004bfcee     CMP        byte ptr [ESI + 0x14],BL
//         004bfcf1     JZ         LAB_004bfd0a
//                              sprite.cpp:270 (20)
//         004bfcf3     CMP        EDI,EBX
//         004bfcf5     JZ         LAB_004bfd07
//         004bfcf7     MOV        this,EDI
//         004bfcf9     CALL       TShape::~TShape                                  void ~TShape(TShape * this)
//         004bfcfe     PUSH       EDI
//         004bfcff     CALL       operator_delete                                  void operator_delete(void * param_1)
//         004bfd04     ADD        ESP,0x4
//                               LAB_004bfd07                                                 XREF[1]:     004bfcf5(j)
//                              sprite.cpp:271 (3)
//         004bfd07     MOV        byte ptr [ESI + 0x14],BL
//                               LAB_004bfd0a                                                 XREF[2]:     004bfcec(j), 004bfcf1(j)
//                              sprite.cpp:275 (10)
//         004bfd0a     MOV        EAX,dword ptr [ESI + 0x44]
//         004bfd0d     MOV        dword ptr [ESI + 0x1c],EBX
//         004bfd10     CMP        EAX,EBX
//         004bfd12     JZ         LAB_004bfd20
//                              sprite.cpp:277 (9)
//         004bfd14     PUSH       EAX
//         004bfd15     CALL       free                                             undefined free()
//         004bfd1a     ADD        ESP,0x4
//                              sprite.cpp:278 (3)
//         004bfd1d     MOV        dword ptr [ESI + 0x44],EBX
//                               LAB_004bfd20                                                 XREF[1]:     004bfd12(j)
//                              sprite.cpp:281 (7)
//         004bfd20     MOV        EAX,dword ptr [ESI + 0x38]
//         004bfd23     CMP        EAX,EBX
//         004bfd25     JZ         LAB_004bfd33
//                              sprite.cpp:283 (9)
//         004bfd27     PUSH       EAX
//         004bfd28     CALL       free                                             undefined free()
//         004bfd2d     ADD        ESP,0x4
//                              sprite.cpp:284 (3)
//         004bfd30     MOV        dword ptr [ESI + 0x38],EBX
//                               LAB_004bfd33                                                 XREF[1]:     004bfd25(j)
//                              sprite.cpp:287 (3)
//         004bfd33     MOV        dword ptr [ESI + 0x18],EBX
//                              sprite.cpp:288 (4)
//         004bfd36     POP        EDI
//         004bfd37     POP        ESI
//         004bfd38     POP        EBX
//         004bfd39     RET
//         004bfd3a     ??         90h
//         004bfd3b     NOP
//         004bfd3c     NOP
//         004bfd3d     NOP
//         004bfd3e     NOP
//         004bfd3f     NOP
}

void RGE_Sprite::rehook(RGE_Sprite** param_1) {
    /* TODO: Stub */
//                              void __thiscall rehook(RGE_Sprite * this, RGE_Sprite * * param_1)
//              void              <VOID>         <RETURN>
//              RGE_Sprite *      ECX:4 (auto)   this
//              RGE_Sprite * *    Stack[0x4]:4   param_1                   XREF[1]:     004bfd46(R)
//                               ?rehook@RGE_Sprite@@QAEXPAPAV1@@Z                            XREF[1]:     init_sprites:00541b36(c)
//                               RGE_Sprite::rehook
//                              sprite.cpp:292 (22)
//         004bfd40     MOV        AX,word ptr [ECX + this->draw_list_num]
//         004bfd44     PUSH       ESI
//         004bfd45     PUSH       EDI
//         004bfd46     MOV        EDI,dword ptr [ESP + param_1]
//         004bfd4a     TEST       AX,AX
//         004bfd4d     JLE        LAB_004bfd86
//         004bfd4f     MOV        EDX,dword ptr [ECX + this->draw_list]
//         004bfd52     TEST       EDX,EDX
//         004bfd54     JZ         LAB_004bfd86
//                              sprite.cpp:296 (7)
//         004bfd56     XOR        ESI,ESI
//         004bfd58     TEST       AX,AX
//         004bfd5b     JLE        LAB_004bfd86
//                               LAB_004bfd5d                                                 XREF[1]:     004bfd84(j)
//                              sprite.cpp:298 (20)
//         004bfd5d     MOV        EDX,dword ptr [ECX + this->draw_list]
//         004bfd60     MOVSX      EAX,SI
//         004bfd63     SHL        EAX,0x4
//         004bfd66     ADD        EAX,EDX
//         004bfd68     MOV        DX,word ptr [EAX]
//         004bfd6b     CMP        DX,-0x1
//         004bfd6f     JNZ        LAB_004bfd76
//                              sprite.cpp:299 (3)
//         004bfd71     MOV        dword ptr [EAX + 0x4],this
//                              sprite.cpp:300 (2)
//         004bfd74     JMP        LAB_004bfd7f
//                               LAB_004bfd76                                                 XREF[1]:     004bfd6f(j)
//                              sprite.cpp:301 (16)
//         004bfd76     MOVSX      EDX,DX
//         004bfd79     MOV        EDX,dword ptr [EDI + EDX*0x4]
//         004bfd7c     MOV        dword ptr [EAX + 0x4],EDX
//                               LAB_004bfd7f                                                 XREF[1]:     004bfd74(j)
//         004bfd7f     INC        ESI
//         004bfd80     CMP        SI,word ptr [ECX + this->draw_list_num]
//         004bfd84     JL         LAB_004bfd5d
//                               LAB_004bfd86                                                 XREF[3]:     004bfd4d(j), 004bfd54(j),
//                                                                                                         004bfd5b(j)
//                              sprite.cpp:304 (6)
//         004bfd86     PUSH       EDI
//         004bfd87     CALL       RGE_Sprite::load_facets                          void load_facets(RGE_Sprite * this, RGE_Sprit
//                              sprite.cpp:305 (5)
//         004bfd8c     POP        EDI
//         004bfd8d     POP        ESI
//         004bfd8e     RET        0x4
//         004bfd91     ??         90h
//         004bfd92     NOP
//         004bfd93     NOP
//         004bfd94     NOP
//         004bfd95     NOP
//         004bfd96     NOP
//         004bfd97     NOP
//         004bfd98     NOP
//         004bfd99     NOP
//         004bfd9a     NOP
//         004bfd9b     NOP
//         004bfd9c     NOP
//         004bfd9d     NOP
//         004bfd9e     NOP
//         004bfd9f     NOP
    return;
}

void RGE_Sprite::save(int param_1) {
    /* TODO: Stub */
//                              void __thiscall save(RGE_Sprite * this, int param_1)
//              void              <VOID>         <RETURN>
//              RGE_Sprite *      ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[5]:     004bfdc0(R), 004bff49(W), 004bff4f(R), 004bffaf(R),
//                                                                                     004bffc1(W)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[3]:     004bff43(W), 004bffab(R), 004bffbd(W)
//              long              Stack[-0x8]:4  index1                    XREF[3]:     004bff56(W), 004bff97(R), 004bffa5(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[3]:     004bff6c(W), 004bff72(W), 004bff8a(*)
//              long              Stack[-0x10]:4 info                      XREF[3]:     004bfda9(W), 004bfdbc(W), 004bfe84(*)
//              long              Stack[-0x14]:4 lock1
//                               ?save@RGE_Sprite@@QAEXH@Z                                    XREF[1]:     base_save:00543967(c)
//                               RGE_Sprite::save
//                              sprite.cpp:309 (9)
//         004bfda0     SUB        ESP,0x10
//         004bfda3     PUSH       EBX
//         004bfda4     PUSH       EBP
//         004bfda5     PUSH       ESI
//         004bfda6     PUSH       EDI
//         004bfda7     MOV        EDI,this
//                              sprite.cpp:312 (8)
//         004bfda9     MOV        dword ptr [ESP + info],0xffffffff
//                              sprite.cpp:315 (7)
//         004bfdb1     MOV        EAX,dword ptr [EDI + 0x3c]
//         004bfdb4     TEST       EAX,EAX
//         004bfdb6     JZ         LAB_004bfdc0
//                              sprite.cpp:316 (8)
//         004bfdb8     MOVSX      EAX,word ptr [EAX + 0xc]
//         004bfdbc     MOV        dword ptr [ESP + info],EAX
//                               LAB_004bfdc0                                                 XREF[1]:     004bfdb6(j)
//                              sprite.cpp:318 (19)
//         004bfdc0     MOV        ESI,dword ptr [ESP + param_1]
//         004bfdc4     LEA        this,[EDI + 0x48]
//         004bfdc7     PUSH       0x15
//         004bfdc9     PUSH       this
//         004bfdca     PUSH       ESI
//         004bfdcb     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         004bfdd0     ADD        ESP,0xc
//                              sprite.cpp:319 (12)
//         004bfdd3     PUSH       0xd
//         004bfdd5     PUSH       EDI
//         004bfdd6     PUSH       ESI
//         004bfdd7     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         004bfddc     ADD        ESP,0xc
//                              sprite.cpp:320 (15)
//         004bfddf     LEA        EDX,[EDI + 0x10]
//         004bfde2     PUSH       0x4
//         004bfde4     PUSH       EDX
//         004bfde5     PUSH       ESI
//         004bfde6     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         004bfdeb     ADD        ESP,0xc
//                              sprite.cpp:321 (15)
//         004bfdee     LEA        EAX,[EDI + 0x14]
//         004bfdf1     PUSH       0x1
//         004bfdf3     PUSH       EAX
//         004bfdf4     PUSH       ESI
//         004bfdf5     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         004bfdfa     ADD        ESP,0xc
//                              sprite.cpp:322 (15)
//         004bfdfd     LEA        this,[EDI + 0x28]
//         004bfe00     PUSH       0x1
//         004bfe02     PUSH       this
//         004bfe03     PUSH       ESI
//         004bfe04     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         004bfe09     ADD        ESP,0xc
//                              sprite.cpp:323 (15)
//         004bfe0c     LEA        EDX,[EDI + 0x29]
//         004bfe0f     PUSH       0x1
//         004bfe11     PUSH       EDX
//         004bfe12     PUSH       ESI
//         004bfe13     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         004bfe18     ADD        ESP,0xc
//                              sprite.cpp:324 (15)
//         004bfe1b     LEA        EAX,[EDI + 0x2a]
//         004bfe1e     PUSH       0x2
//         004bfe20     PUSH       EAX
//         004bfe21     PUSH       ESI
//         004bfe22     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         004bfe27     ADD        ESP,0xc
//                              sprite.cpp:325 (15)
//         004bfe2a     LEA        this,[EDI + 0x2c]
//         004bfe2d     PUSH       0x1
//         004bfe2f     PUSH       this
//         004bfe30     PUSH       ESI
//         004bfe31     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         004bfe36     ADD        ESP,0xc
//                              sprite.cpp:326 (15)
//         004bfe39     LEA        EDX,[EDI + 0x2e]
//         004bfe3c     PUSH       0x2
//         004bfe3e     PUSH       EDX
//         004bfe3f     PUSH       ESI
//         004bfe40     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         004bfe45     ADD        ESP,0xc
//                              sprite.cpp:327 (15)
//         004bfe48     LEA        EAX,[EDI + 0x30]
//         004bfe4b     PUSH       0x2
//         004bfe4d     PUSH       EAX
//         004bfe4e     PUSH       ESI
//         004bfe4f     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         004bfe54     ADD        ESP,0xc
//                              sprite.cpp:328 (15)
//         004bfe57     LEA        this,[EDI + 0x32]
//         004bfe5a     PUSH       0x2
//         004bfe5c     PUSH       this
//         004bfe5d     PUSH       ESI
//         004bfe5e     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         004bfe63     ADD        ESP,0xc
//                              sprite.cpp:329 (15)
//         004bfe66     LEA        EDX,[EDI + 0x34]
//         004bfe69     PUSH       0x2
//         004bfe6b     PUSH       EDX
//         004bfe6c     PUSH       ESI
//         004bfe6d     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         004bfe72     ADD        ESP,0xc
//                              sprite.cpp:330 (15)
//         004bfe75     LEA        EBX,[EDI + 0x36]
//         004bfe78     PUSH       0x2
//         004bfe7a     PUSH       EBX
//         004bfe7b     PUSH       ESI
//         004bfe7c     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         004bfe81     ADD        ESP,0xc
//                              sprite.cpp:331 (16)
//         004bfe84     LEA        EAX=>info,[ESP + 0x10]
//         004bfe88     PUSH       0x2
//         004bfe8a     PUSH       EAX
//         004bfe8b     PUSH       ESI
//         004bfe8c     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         004bfe91     ADD        ESP,0xc
//                              sprite.cpp:332 (15)
//         004bfe94     LEA        EBP,[EDI + 0x40]
//         004bfe97     PUSH       0x1
//         004bfe99     PUSH       EBP
//         004bfe9a     PUSH       ESI
//         004bfe9b     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         004bfea0     ADD        ESP,0xc
//                              sprite.cpp:333 (15)
//         004bfea3     LEA        this,[EDI + 0x5e]
//         004bfea6     PUSH       0x2
//         004bfea8     PUSH       this
//         004bfea9     PUSH       ESI
//         004bfeaa     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         004bfeaf     ADD        ESP,0xc
//                              sprite.cpp:334 (15)
//         004bfeb2     LEA        EAX,[EDI + 0x60]
//         004bfeb5     PUSH       0x2
//         004bfeb7     PUSH       EAX
//         004bfeb8     PUSH       ESI
//         004bfeb9     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         004bfebe     ADD        ESP,0xc
//                              sprite.cpp:335 (15)
//         004bfec1     LEA        EDX,[EDI + 0x64]
//         004bfec4     PUSH       0x4
//         004bfec6     PUSH       EDX
//         004bfec7     PUSH       ESI
//         004bfec8     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         004bfecd     ADD        ESP,0xc
//                              sprite.cpp:336 (15)
//         004bfed0     LEA        EAX,[EDI + 0x68]
//         004bfed3     PUSH       0x4
//         004bfed5     PUSH       EAX
//         004bfed6     PUSH       ESI
//         004bfed7     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         004bfedc     ADD        ESP,0xc
//                              sprite.cpp:337 (15)
//         004bfedf     LEA        this,[EDI + 0x6c]
//         004bfee2     PUSH       0x4
//         004bfee4     PUSH       this
//         004bfee5     PUSH       ESI
//         004bfee6     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         004bfeeb     ADD        ESP,0xc
//                              sprite.cpp:338 (15)
//         004bfeee     LEA        EDX,[EDI + 0x70]
//         004bfef1     PUSH       0x1
//         004bfef3     PUSH       EDX
//         004bfef4     PUSH       ESI
//         004bfef5     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         004bfefa     ADD        ESP,0xc
//                              sprite.cpp:339 (15)
//         004bfefd     LEA        EAX,[EDI + 0x72]
//         004bff00     PUSH       0x2
//         004bff02     PUSH       EAX
//         004bff03     PUSH       ESI
//         004bff04     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         004bff09     ADD        ESP,0xc
//                              sprite.cpp:340 (12)
//         004bff0c     LEA        this,[EDI + 0x74]
//         004bff0f     PUSH       0x1
//         004bff11     PUSH       this
//         004bff12     PUSH       ESI
//         004bff13     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//                              sprite.cpp:342 (10)
//         004bff18     MOV        EAX,dword ptr [EDI + 0x38]
//         004bff1b     ADD        ESP,0xc
//         004bff1e     TEST       EAX,EAX
//         004bff20     JZ         LAB_004bff33
//                              sprite.cpp:344 (17)
//         004bff22     MOVSX      EDX,word ptr [EBX]
//         004bff25     SHL        EDX,0x4
//         004bff28     PUSH       EDX
//         004bff29     PUSH       EAX
//         004bff2a     PUSH       ESI
//         004bff2b     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         004bff30     ADD        ESP,0xc
//                               LAB_004bff33                                                 XREF[1]:     004bff20(j)
//                              sprite.cpp:346 (10)
//         004bff33     CMP        byte ptr [EBP],0x0
//         004bff37     JZ         LAB_004bffc7
//                              sprite.cpp:347 (12)
//         004bff3d     XOR        EBX,EBX
//         004bff3f     CMP        word ptr [EDI + 0x60],BX
//         004bff43     MOV        dword ptr [ESP + local_4],EBX
//         004bff47     JLE        LAB_004bffc7
//                              sprite.cpp:358 (10)
//         004bff49     MOV        dword ptr [ESP + param_1],EBX
//         004bff4d     JMP        LAB_004bff53
//                               LAB_004bff4f                                                 XREF[1]:     004bffc5(j)
//         004bff4f     MOV        EBX,dword ptr [ESP + param_1]
//                               LAB_004bff53                                                 XREF[1]:     004bff4d(j)
//                              sprite.cpp:347 (3)
//         004bff53     LEA        EBP,[EBX + 0xc]
//                              sprite.cpp:348 (8)
//         004bff56     MOV        dword ptr [ESP + index1],0x3
//                               LAB_004bff5e                                                 XREF[1]:     004bffa9(j)
//                              sprite.cpp:350 (10)
//         004bff5e     MOV        EAX,dword ptr [EDI + 0x44]
//         004bff61     MOV        this,dword ptr [EBX + EAX*0x1]
//         004bff64     TEST       this,this
//         004bff66     JZ         LAB_004bff72
//                              sprite.cpp:351 (8)
//         004bff68     MOVSX      this,word ptr [ECX + this+0xc]
//         004bff6c     MOV        dword ptr [ESP + local_c],this
//                              sprite.cpp:352 (2)
//         004bff70     JMP        LAB_004bff7a
//                               LAB_004bff72                                                 XREF[1]:     004bff66(j)
//                              sprite.cpp:353 (8)
//         004bff72     MOV        dword ptr [ESP + local_c],0xffffffff
//                               LAB_004bff7a                                                 XREF[1]:     004bff70(j)
//                              sprite.cpp:355 (16)
//         004bff7a     LEA        EDX,[EBP + EAX*0x1]
//         004bff7e     PUSH       0x2
//         004bff80     PUSH       EDX
//         004bff81     PUSH       ESI
//         004bff82     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         004bff87     ADD        ESP,0xc
//                              sprite.cpp:356 (61)
//         004bff8a     LEA        EAX=>local_c,[ESP + 0x14]
//         004bff8e     PUSH       0x2
//         004bff90     PUSH       EAX
//         004bff91     PUSH       ESI
//         004bff92     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         004bff97     MOV        EAX,dword ptr [ESP + index1]
//         004bff9b     ADD        ESP,0xc
//         004bff9e     ADD        EBX,0x4
//         004bffa1     ADD        EBP,0x2
//         004bffa4     DEC        EAX
//         004bffa5     MOV        dword ptr [ESP + index1],EAX
//         004bffa9     JNZ        LAB_004bff5e
//         004bffab     MOV        EAX,dword ptr [ESP + local_4]
//         004bffaf     MOV        EBX,dword ptr [ESP + param_1]
//         004bffb3     MOVSX      this,word ptr [EDI + 0x60]
//         004bffb7     INC        EAX
//         004bffb8     ADD        EBX,0x14
//         004bffbb     CMP        EAX,this
//         004bffbd     MOV        dword ptr [ESP + local_4],EAX
//         004bffc1     MOV        dword ptr [ESP + param_1],EBX
//         004bffc5     JL         LAB_004bff4f
//                               LAB_004bffc7                                                 XREF[2]:     004bff37(j), 004bff47(j)
//                              sprite.cpp:358 (10)
//         004bffc7     POP        EDI
//         004bffc8     POP        ESI
//         004bffc9     POP        EBP
//         004bffca     POP        EBX
//         004bffcb     ADD        ESP,0x10
//         004bffce     RET        0x4
//         004bffd1     ??         90h
//         004bffd2     NOP
//         004bffd3     NOP
//         004bffd4     NOP
//         004bffd5     NOP
//         004bffd6     NOP
//         004bffd7     NOP
//         004bffd8     NOP
//         004bffd9     NOP
//         004bffda     NOP
//         004bffdb     NOP
//         004bffdc     NOP
//         004bffdd     NOP
//         004bffde     NOP
//         004bffdf     NOP
    return;
}

void RGE_Sprite::load_facets(RGE_Sprite** param_1) {
    /* TODO: Stub */
//                              void __thiscall load_facets(RGE_Sprite * this, RGE_Sprite * * param_1)
//              void              <VOID>         <RETURN>
//              RGE_Sprite *      ECX:4 (auto)   this
//              RGE_Sprite * *    Stack[0x4]:4   param_1
//                               ?load_facets@RGE_Sprite@@QAEXPAPAV1@@Z                       XREF[1]:     rehook:004bfd87(c)
//                               RGE_Sprite::load_facets
//                              sprite.cpp:362 (7)
//         004bffe0     MOV        dword ptr [ECX + this->shape],0x0
//                              sprite.cpp:382 (4)
//         004bffe7     MOV        byte ptr [ECX + this->loaded],0x1
//                              sprite.cpp:392 (3)
//         004bffeb     RET        0x4
//         004bffee     ??         90h
//         004bffef     NOP
    return;
}

void RGE_Sprite::play_sound(short param_1, short param_2, short param_3) {
    /* TODO: Stub */
//                              void __thiscall play_sound(RGE_Sprite * this, short param_1, short p
//              void              <VOID>         <RETURN>
//              RGE_Sprite *      ECX:4 (auto)   this
//              short             Stack[0x4]:2   param_1                   XREF[3]:     004c0002(R), 004c005d(R), 004c00ab(R)
//              short             Stack[0x8]:2   param_2                   XREF[3]:     004c0007(R), 004c0066(R), 004c00b4(R)
//              short             Stack[0xc]:2   param_3                   XREF[1]:     004bfff4(R)
//                               ?play_sound@RGE_Sprite@@QAEXFFF@Z                            XREF[2]:     draw:0041b487(c),
//                               RGE_Sprite::play_sound                                                    normal_draw:0041b4e2(c)
//                              sprite.cpp:396 (4)
//         004bfff0     PUSH       EBX
//         004bfff1     PUSH       EBP
//         004bfff2     PUSH       ESI
//         004bfff3     PUSH       EDI
//                              sprite.cpp:400 (12)
//         004bfff4     MOV        EDI,dword ptr [ESP + param_3]
//         004bfff8     MOV        EBP,this
//         004bfffa     CMP        DI,word ptr [EBP + 0x60]
//         004bfffe     JL         LAB_004c0002
//                              sprite.cpp:401 (2)
//         004c0000     XOR        EDI,EDI
//                               LAB_004c0002                                                 XREF[1]:     004bfffe(j)
//                              sprite.cpp:403 (19)
//         004c0002     MOV        SI,word ptr [ESP + param_1]
//         004c0007     MOV        BX,word ptr [ESP + param_2]
//         004c000c     CMP        SI,BX
//         004c000f     JZ         LAB_004c00d7
//                              sprite.cpp:406 (22)
//         004c0015     MOV        this,dword ptr [EBP + 0x3c]
//         004c0018     TEST       this,this
//         004c001a     JZ         LAB_004c0032
//         004c001c     TEST       SI,SI
//         004c001f     JZ         LAB_004c002b
//         004c0021     CMP        BX,SI
//         004c0024     JGE        LAB_004c0032
//         004c0026     TEST       BX,BX
//         004c0029     JZ         LAB_004c0032
//                               LAB_004c002b                                                 XREF[1]:     004c001f(j)
//                              sprite.cpp:408 (7)
//         004c002b     PUSH       0x1
//         004c002d     CALL       RGE_Sound::play                                  void play(RGE_Sound * this, int param_1)
//                               LAB_004c0032                                                 XREF[3]:     004c001a(j), 004c0024(j),
//                                                                                                         004c0029(j)
//                              sprite.cpp:411 (11)
//         004c0032     MOV        AL,byte ptr [EBP + 0x40]
//         004c0035     TEST       AL,AL
//         004c0037     JZ         LAB_004c00d7
//                              sprite.cpp:413 (5)
//         004c003d     CMP        SI,BX
//         004c0040     JGE        LAB_004c0090
//                              sprite.cpp:437 (123)
//         004c0042     MOVSX      EBX,DI
//         004c0045     XOR        ESI,ESI
//         004c0047     LEA        EAX,[EBX + EBX*0x4]
//         004c004a     LEA        EDI,[EAX*0x4 + 0xc]
//                               LAB_004c0051                                                 XREF[1]:     004c0087(j)
//         004c0051     MOV        this,dword ptr [EBP + 0x44]
//         004c0054     MOVSX      EAX,word ptr [EDI + this->pict_name[0]*0x1]
//         004c0058     CMP        EAX,-0x1
//         004c005b     JLE        LAB_004c00d7
//         004c005d     MOVSX      EDX,word ptr [ESP + param_1]
//         004c0062     CMP        EAX,EDX
//         004c0064     JL         LAB_004c0080
//         004c0066     MOVSX      EDX,word ptr [ESP + param_2]
//         004c006b     CMP        EAX,EDX
//         004c006d     JGE        LAB_004c0080
//         004c006f     LEA        EAX,[ESI + EBX*0x4]
//         004c0072     MOV        EDX,EBX
//         004c0074     ADD        EDX,EAX
//         004c0076     PUSH       0x1
//         004c0078     MOV        this,dword ptr [this->pict_name[0] + EDX*0x4]
//         004c007b     CALL       RGE_Sound::play                                  void play(RGE_Sound * this, int param_1)
//                               LAB_004c0080                                                 XREF[2]:     004c0064(j), 004c006d(j)
//         004c0080     INC        ESI
//         004c0081     ADD        EDI,0x2
//         004c0084     CMP        ESI,0x3
//         004c0087     JL         LAB_004c0051
//         004c0089     POP        EDI
//         004c008a     POP        ESI
//         004c008b     POP        EBP
//         004c008c     POP        EBX
//         004c008d     RET        0xc
//                               LAB_004c0090                                                 XREF[1]:     004c0040(j)
//         004c0090     MOVSX      EBX,DI
//         004c0093     XOR        ESI,ESI
//         004c0095     LEA        EAX,[EBX + EBX*0x4]
//         004c0098     LEA        EDI,[EAX*0x4 + 0xc]
//                               LAB_004c009f                                                 XREF[1]:     004c00d5(j)
//         004c009f     MOV        this,dword ptr [EBP + 0x44]
//         004c00a2     MOVSX      EAX,word ptr [EDI + this->pict_name[0]*0x1]
//         004c00a6     CMP        EAX,-0x1
//         004c00a9     JLE        LAB_004c00d7
//         004c00ab     MOVSX      EDX,word ptr [ESP + param_1]
//         004c00b0     CMP        EAX,EDX
//         004c00b2     JGE        LAB_004c00bd
//         004c00b4     MOVSX      EDX,word ptr [ESP + param_2]
//         004c00b9     CMP        EAX,EDX
//         004c00bb     JGE        LAB_004c00ce
//                               LAB_004c00bd                                                 XREF[1]:     004c00b2(j)
//                              sprite.cpp:432 (26)
//         004c00bd     LEA        EAX,[ESI + EBX*0x4]
//         004c00c0     MOV        EDX,EBX
//         004c00c2     ADD        EDX,EAX
//         004c00c4     PUSH       0x1
//         004c00c6     MOV        this,dword ptr [this->pict_name[0] + EDX*0x4]
//         004c00c9     CALL       RGE_Sound::play                                  void play(RGE_Sound * this, int param_1)
//                               LAB_004c00ce                                                 XREF[1]:     004c00bb(j)
//         004c00ce     INC        ESI
//         004c00cf     ADD        EDI,0x2
//         004c00d2     CMP        ESI,0x3
//         004c00d5     JL         LAB_004c009f
//                               LAB_004c00d7                                                 XREF[4]:     004c000f(j), 004c0037(j),
//                                                                                                         004c005b(j), 004c00a9(j)
//                              sprite.cpp:437 (7)
//         004c00d7     POP        EDI
//         004c00d8     POP        ESI
//         004c00d9     POP        EBP
//         004c00da     POP        EBX
//         004c00db     RET        0xc
//         004c00de     ??         90h
//         004c00df     NOP
    return;
}

uchar RGE_Sprite::get_facetindex(long param_1, long param_2, long* param_3) {
    /* TODO: Stub */
//                              uchar __thiscall get_facetindex(RGE_Sprite * this, long param_1, lon
//              uchar             AL:1           <RETURN>
//              RGE_Sprite *      ECX:4 (auto)   this
//              long              Stack[0x4]:4   param_1                   XREF[2]:     004c00f9(R), 004c0103(R)
//              long              Stack[0x8]:4   param_2                   XREF[4]:     004c00f3(R), 004c0149(R), 004c016b(R), 004c0187(R)
//              long *            Stack[0xc]:4   param_3                   XREF[4]:     004c00ef(R), 004c0134(R), 004c0174(R), 004c018b(R)
//                               ?get_facetindex@RGE_Sprite@@QAEEJJAAJ@Z                      XREF[5]:     get_facetindex:0041af99(c),
//                               RGE_Sprite::get_facetindex                                                get_facetindex:0041b5bc(c),
//                                                                                                         do_draw:004c02ca(c),
//                                                                                                         get_frame_min_max:004c0b93(c),
//                                                                                                         shape_hit_test:004c0e65(c)
//                              sprite.cpp:441 (15)
//         004c00e0     MOV        AL,byte ptr [ECX + this->mirror_flag]
//         004c00e3     PUSH       ESI
//         004c00e4     TEST       AL,AL
//         004c00e6     JZ         LAB_004c0103
//         004c00e8     CMP        word ptr [ECX + this->facet_num],0x2
//         004c00ed     JNZ        LAB_004c0101
//                              sprite.cpp:445 (10)
//         004c00ef     MOV        EAX,dword ptr [ESP + param_3]
//         004c00f3     MOV        this,dword ptr [ESP + param_2]
//         004c00f7     MOV        dword ptr [EAX],this
//                              sprite.cpp:446 (4)
//         004c00f9     MOV        AL,byte ptr [ESP + param_1]
//                              sprite.cpp:471 (4)
//         004c00fd     POP        ESI
//         004c00fe     RET        0xc
//                               LAB_004c0101                                                 XREF[1]:     004c00ed(j)
//                              sprite.cpp:450 (31)
//         004c0101     TEST       AL,AL
//                               LAB_004c0103                                                 XREF[1]:     004c00e6(j)
//         004c0103     MOV        EDX,dword ptr [ESP + param_1]
//         004c0107     JZ         LAB_004c015a
//         004c0109     MOV        ESI,EAX
//         004c010b     AND        ESI,0xff
//         004c0111     CMP        EDX,ESI
//         004c0113     JG         LAB_004c0120
//         004c0115     MOVSX      ESI,word ptr [ECX + this->facet_num]
//         004c0119     SAR        ESI,0x2
//         004c011c     CMP        EDX,ESI
//         004c011e     JGE        LAB_004c015a
//                               LAB_004c0120                                                 XREF[1]:     004c0113(j)
//                              sprite.cpp:452 (12)
//         004c0120     MOVSX      ESI,word ptr [ECX + this->facet_num]
//         004c0124     MOV        EAX,ESI
//         004c0126     SAR        EAX,0x1
//         004c0128     CMP        EDX,EAX
//         004c012a     JLE        LAB_004c0132
//                              sprite.cpp:453 (4)
//         004c012c     SUB        EAX,EDX
//         004c012e     ADD        EAX,ESI
//                              sprite.cpp:454 (2)
//         004c0130     JMP        LAB_004c0134
//                               LAB_004c0132                                                 XREF[1]:     004c012a(j)
//                              sprite.cpp:455 (8)
//         004c0132     SUB        EAX,EDX
//                               LAB_004c0134                                                 XREF[1]:     004c0130(j)
//         004c0134     MOV        EDX,dword ptr [ESP + param_3]
//         004c0138     MOV        dword ptr [EDX],EAX
//                              sprite.cpp:456 (24)
//         004c013a     MOV        ESI,dword ptr [EDX]
//         004c013c     MOVSX      EAX,word ptr [ECX + this->facet_num]
//         004c0140     MOVSX      this,word ptr [ECX + this->frame_num]
//         004c0144     SAR        EAX,0x2
//         004c0147     SUB        ESI,EAX
//         004c0149     MOV        EAX,dword ptr [ESP + param_2]
//         004c014d     IMUL       ESI,this
//         004c0150     ADD        ESI,EAX
//                              sprite.cpp:458 (4)
//         004c0152     MOV        AL,0x1
//         004c0154     MOV        dword ptr [EDX],ESI
//                              sprite.cpp:471 (4)
//         004c0156     POP        ESI
//         004c0157     RET        0xc
//                               LAB_004c015a                                                 XREF[2]:     004c0107(j), 004c011e(j)
//                              sprite.cpp:464 (4)
//         004c015a     TEST       AL,AL
//         004c015c     JZ         LAB_004c0180
//                              sprite.cpp:465 (28)
//         004c015e     MOVSX      EAX,word ptr [ECX + this->facet_num]
//         004c0162     MOVSX      this,word ptr [ECX + this->frame_num]
//         004c0166     SAR        EAX,0x2
//         004c0169     SUB        EDX,EAX
//         004c016b     MOV        EAX,dword ptr [ESP + param_2]
//         004c016f     IMUL       EDX,this
//         004c0172     ADD        EDX,EAX
//         004c0174     MOV        EAX,dword ptr [ESP + param_3]
//         004c0178     MOV        dword ptr [EAX],EDX
//                              sprite.cpp:469 (2)
//         004c017a     XOR        AL,AL
//                              sprite.cpp:471 (4)
//         004c017c     POP        ESI
//         004c017d     RET        0xc
//                               LAB_004c0180                                                 XREF[1]:     004c015c(j)
//                              sprite.cpp:467 (17)
//         004c0180     MOVSX      this,word ptr [ECX + this->frame_num]
//         004c0184     IMUL       this,EDX
//         004c0187     MOV        EAX,dword ptr [ESP + param_2]
//         004c018b     MOV        EDX,dword ptr [ESP + param_3]
//         004c018f     ADD        this,EAX
//                              sprite.cpp:469 (4)
//         004c0191     XOR        AL,AL
//         004c0193     MOV        dword ptr [EDX],this
//                              sprite.cpp:471 (4)
//         004c0195     POP        ESI
//         004c0196     RET        0xc
//         004c0199     ??         90h
//         004c019a     NOP
//         004c019b     NOP
//         004c019c     NOP
//         004c019d     NOP
//         004c019e     NOP
//         004c019f     NOP
    return 0;
}

void RGE_Sprite::do_draw(long param_1, long param_2, long param_3, long param_4, RGE_Color_Table* param_5, TDrawArea* param_6, uchar param_7) {
    /* TODO: Stub */
//                              void __thiscall do_draw(RGE_Sprite * this, long param_1, long param_
//              void              <VOID>         <RETURN>
//              RGE_Sprite *      ECX:4 (auto)   this
//              long              Stack[0x4]:4   param_1                   XREF[1]:     004c02ba(R)
//              long              Stack[0x8]:4   param_2                   XREF[1]:     004c01bc(R)
//              long              Stack[0xc]:4   param_3                   XREF[2]:     004c02e5(R), 004c03d1(R)
//              long              Stack[0x10]:4  param_4                   XREF[2]:     004c02dc(R), 004c03c8(R)
//              RGE_Color_Tabl    Stack[0x14]:4  param_5                   XREF[2]:     004c0339(R), 004c0425(R)
//              TDrawArea *       Stack[0x18]:4  param_6                   XREF[4]:     004c0364(R), 004c03af(R), 004c0450(R), 004c0490(R)
//              uchar             Stack[0x1c]:1  param_7                   XREF[1]:     004c027d(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     004c0223(W), 004c024a(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     004c04ca(R)
//              char[256]         Stack[-0x110   s                         XREF[1,6]:   004c021d(W), 004c02f7(*), 004c0317(*), 004c0323(*),
//                                                                                     004c03e3(*), 004c0403(*), 004c040f(*)
//              undefined4        Stack[-0x114   local_114                 XREF[4]:     004c01ca(W), 004c01f1(*), 004c022f(R), 004c0270(R)
//              char *            Stack[-0x118   fname                     XREF[7]:     004c02c1(*), 004c02ee(R), 004c0360(R), 004c03ab(R),
//                                                                                     004c03da(R), 004c044c(R), 004c048c(R)
//              long              Stack[-0x11c   facetindex
//                               ?do_draw@RGE_Sprite@@QAEXJJJJPAVRGE_Color_Table@@PAVTDrawAr  XREF[7]:     draw:004bf02f(c),
//                               RGE_Sprite::do_draw                                                       draw:004c05a2(c),
//                                                                                                         draw:004c060c(c),
//                                                                                                         normal_draw:004c06b8(c),
//                                                                                                         normal_draw:004c0706(c),
//                                                                                                         shadow_draw:004c07c0(c),
//                                                                                                         shadow_draw:004c0819(c)
//                              sprite.cpp:475 (28)
//         004c01a0     PUSH       -0x1
//         004c01a2     PUSH       FUN_0055f8fe
//         004c01a7     MOV        EAX,FS:[0x0]
//         004c01ad     PUSH       EAX
//         004c01ae     MOV        dword ptr FS:[0x0],ESP
//         004c01b5     SUB        ESP,0x10c
//         004c01bb     PUSH       EBX
//                              sprite.cpp:479 (26)
//         004c01bc     MOV        EBX,dword ptr [ESP + param_2]
//         004c01c3     PUSH       EBP
//         004c01c4     PUSH       ESI
//         004c01c5     MOV        ESI,this
//         004c01c7     XOR        EBP,EBP
//         004c01c9     PUSH       EDI
//         004c01ca     MOV        dword ptr [ESP + local_114],EBP
//         004c01ce     MOVSX      EAX,word ptr [ESI + 0x5e]
//         004c01d2     CMP        EBX,EAX
//         004c01d4     JL         LAB_004c01d8
//                              sprite.cpp:480 (2)
//         004c01d6     XOR        EBX,EBX
//                               LAB_004c01d8                                                 XREF[1]:     004c01d4(j)
//                              sprite.cpp:483 (9)
//         004c01d8     CMP        dword ptr [ESI + 0x1c],EBP
//         004c01db     JNZ        LAB_004c027d
//                              sprite.cpp:485 (11)
//         004c01e1     MOV        AL,byte ptr [ESI + 0x14]
//         004c01e4     TEST       AL,AL
//         004c01e6     JZ         LAB_004c04ca
//                              sprite.cpp:487 (19)
//         004c01ec     PUSH       s_.shp                                           = ".shp"
//         004c01f1     LEA        this=>local_114,[ESP + 0x18]
//         004c01f5     PUSH       ESI
//         004c01f6     PUSH       this
//         004c01f7     CALL       addstring                                        void addstring(char * * param_1, char * param
//         004c01fc     ADD        ESP,0xc
//                              sprite.cpp:488 (20)
//         004c01ff     PUSH       0x1e8
//         004c0204     PUSH       s_C:\msdev\work\age1_x1\sprite.cpp               = "C:\\msdev\\work\\age1_x1\\sprite.cpp"
//         004c0209     CALL       debug_timeGetTime                                ulong debug_timeGetTime(char * param_1, int p
//         004c020e     ADD        ESP,0x8
//         004c0211     MOV        EDI,EAX
//                              sprite.cpp:489 (45)
//         004c0213     PUSH       0x20
//         004c0215     CALL       operator_new                                     void * operator_new(uint param_1)
//         004c021a     ADD        ESP,0x4
//         004c021d     MOV        dword ptr [ESP + s[0]],EAX
//         004c0221     CMP        EAX,EBP
//         004c0223     MOV        dword ptr [ESP + local_4],EBP
//         004c022a     JZ         LAB_004c023e
//         004c022c     MOV        EDX,dword ptr [ESI + 0x10]
//         004c022f     MOV        this,dword ptr [ESP + local_114]
//         004c0233     PUSH       EDX
//         004c0234     PUSH       this
//         004c0235     MOV        this,EAX
//         004c0237     CALL       TShape::TShape                                   undefined TShape(TShape * this, char * param_
//         004c023c     JMP        LAB_004c0240
//                               LAB_004c023e                                                 XREF[1]:     004c022a(j)
//         004c023e     XOR        EAX,EAX
//                               LAB_004c0240                                                 XREF[1]:     004c023c(j)
//                              sprite.cpp:490 (48)
//         004c0240     PUSH       0x1ea
//         004c0245     PUSH       s_C:\msdev\work\age1_x1\sprite.cpp               = "C:\\msdev\\work\\age1_x1\\sprite.cpp"
//         004c024a     MOV        dword ptr [ESP + local_4],0xffffffff
//         004c0255     MOV        dword ptr [ESI + 0x1c],EAX
//         004c0258     CALL       debug_timeGetTime                                ulong debug_timeGetTime(char * param_1, int p
//         004c025d     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004c0263     ADD        ESP,0x8
//         004c0266     SUB        EAX,EDI
//         004c0268     PUSH       EAX
//         004c0269     PUSH       0xb
//         004c026b     CALL       RGE_Base_Game::add_to_timing                     void add_to_timing(RGE_Base_Game * this, int
//                              sprite.cpp:491 (13)
//         004c0270     MOV        EDX,dword ptr [ESP + local_114]
//         004c0274     PUSH       EDX
//         004c0275     CALL       free                                             undefined free()
//         004c027a     ADD        ESP,0x4
//                               LAB_004c027d                                                 XREF[1]:     004c01db(j)
//                              sprite.cpp:499 (30)
//         004c027d     MOV        EAX,dword ptr [ESP + param_7]
//         004c0284     XOR        this,this
//         004c0286     MOV        this,byte ptr [ESI + 0x29]
//         004c0289     AND        EAX,0xff
//         004c028e     MOV        dword ptr [ESI + 0x24],EBP
//         004c0291     CMP        this,EAX
//         004c0293     MOV        dword ptr [SDI_Draw_Level],this
//         004c0299     JGE        LAB_004c02a0
//                              sprite.cpp:500 (5)
//         004c029b     MOV        [SDI_Draw_Level],EAX
//                               LAB_004c02a0                                                 XREF[1]:     004c0299(j)
//                              sprite.cpp:502 (8)
//         004c02a0     MOV        EAX,[SDI_List]                                   = 00000000
//         004c02a5     MOV        dword ptr [EAX + 0x6c],EBP
//                              sprite.cpp:503 (9)
//         004c02a8     CMP        word ptr [ESI + 0x2e],BP
//         004c02ac     LEA        EAX,[ESI + 0x2e]
//         004c02af     JZ         LAB_004c02ba
//                              sprite.cpp:505 (9)
//         004c02b1     MOV        this,dword ptr [SDI_List]                        = 00000000
//         004c02b7     MOV        dword ptr [ECX + this->pause_between_loops],EAX
//                               LAB_004c02ba                                                 XREF[1]:     004c02af(j)
//                              sprite.cpp:508 (23)
//         004c02ba     MOV        EAX,dword ptr [ESP + param_1]
//         004c02c1     LEA        EDX=>fname,[ESP + 0x10]
//         004c02c5     PUSH       EDX
//         004c02c6     PUSH       EBX
//         004c02c7     PUSH       EAX
//         004c02c8     MOV        this,ESI
//         004c02ca     CALL       RGE_Sprite::get_facetindex                       uchar get_facetindex(RGE_Sprite * this, long
//         004c02cf     TEST       AL,AL
//                              sprite.cpp:512 (29)
//         004c02d1     MOV        EAX,[do_draw_log]
//         004c02d6     JZ         LAB_004c03c8
//         004c02dc     MOV        EDI,dword ptr [ESP + param_4]
//         004c02e3     CMP        EAX,EBP
//         004c02e5     MOV        EBP,dword ptr [ESP + param_3]
//         004c02ec     JZ         LAB_004c0330
//                              sprite.cpp:515 (29)
//         004c02ee     MOV        EDX,dword ptr [ESP + fname]
//         004c02f2     XOR        this,this
//         004c02f4     MOV        this,byte ptr [ESI + 0x28]
//         004c02f7     LEA        EAX=>s[4],[ESP + 0x1c]
//         004c02fb     PUSH       this
//         004c02fc     PUSH       EDX
//         004c02fd     PUSH       EDI
//         004c02fe     PUSH       EBP
//         004c02ff     PUSH       ESI
//         004c0300     PUSH       s_<%s,%d,%d,%d,%d,m                              = "<%s,%d,%d,%d,%d,m"
//         004c0305     PUSH       EAX
//         004c0306     CALL       sprintf                                          undefined sprintf()
//                              sprite.cpp:516 (12)
//         004c030b     MOV        EAX,[safe_draw_log]
//         004c0310     ADD        ESP,0x1c
//         004c0313     TEST       EAX,EAX
//         004c0315     JZ         LAB_004c0323
//                              sprite.cpp:517 (10)
//         004c0317     LEA        this=>s[4],[ESP + 0x1c]
//         004c031b     PUSH       this
//         004c031c     CALL       write_draw_log2                                  void write_draw_log2(char * param_1)
//                              sprite.cpp:518 (2)
//         004c0321     JMP        LAB_004c032d
//                               LAB_004c0323                                                 XREF[1]:     004c0315(j)
//                              sprite.cpp:519 (13)
//         004c0323     LEA        EDX=>s[4],[ESP + 0x1c]
//         004c0327     PUSH       EDX
//         004c0328     CALL       write_draw_log                                   void write_draw_log(char * param_1)
//                               LAB_004c032d                                                 XREF[1]:     004c0321(j)
//         004c032d     ADD        ESP,0x4
//                               LAB_004c0330                                                 XREF[1]:     004c02ec(j)
//                              sprite.cpp:522 (9)
//         004c0330     MOV        AX,word ptr [ESI + 0x2a]
//         004c0334     TEST       AX,AX
//         004c0337     JGE        LAB_004c037d
//                              sprite.cpp:524 (11)
//         004c0339     MOV        EBX,dword ptr [ESP + param_5]
//         004c0340     TEST       EBX,EBX
//         004c0342     JZ         LAB_004c035b
//                              sprite.cpp:526 (17)
//         004c0344     MOVSX      EAX,word ptr [EBX + 0x26]
//         004c0348     INC        EAX
//         004c0349     SHL        EAX,0x4
//         004c034c     PUSH       EAX
//         004c034d     CALL       _ASMSet_Color_Xform                              undefined _ASMSet_Color_Xform()
//         004c0352     ADD        ESP,0x4
//                              sprite.cpp:527 (4)
//         004c0355     ADD        EBX,0x28
//         004c0358     PUSH       EBX
//                              sprite.cpp:529 (2)
//         004c0359     JMP        LAB_004c035d
//                               LAB_004c035b                                                 XREF[1]:     004c0342(j)
//                              sprite.cpp:531 (29)
//         004c035b     PUSH       0x0
//                               LAB_004c035d                                                 XREF[1]:     004c0359(j)
//         004c035d     MOV        this,byte ptr [ESI + 0x28]
//         004c0360     MOV        EDX,dword ptr [ESP + fname]
//         004c0364     MOV        EAX,dword ptr [ESP + param_6]
//         004c036b     PUSH       this
//         004c036c     MOV        this,dword ptr [ESI + 0x1c]
//         004c036f     PUSH       EDX
//         004c0370     PUSH       EDI
//         004c0371     PUSH       EBP
//         004c0372     PUSH       EAX
//         004c0373     CALL       TShape::shape_mirror                             uchar shape_mirror(TShape * this, TDrawArea *
//                              sprite.cpp:534 (5)
//         004c0378     JMP        LAB_004c04a4
//                               LAB_004c037d                                                 XREF[1]:     004c0337(j)
//                              sprite.cpp:536 (12)
//         004c037d     MOV        this,dword ptr [ESI + 0x18]
//         004c0380     MOVSX      EAX,AX
//         004c0383     CMP        dword ptr [this->pict_name[0] + EAX*0x4],0x0
//         004c0387     JZ         LAB_004c03a6
//                              sprite.cpp:538 (10)
//         004c0389     INC        EAX
//         004c038a     SHL        EAX,0x4
//         004c038d     PUSH       EAX
//         004c038e     CALL       _ASMSet_Color_Xform                              undefined _ASMSet_Color_Xform()
//                              sprite.cpp:539 (17)
//         004c0393     MOVSX      EDX,word ptr [ESI + 0x2a]
//         004c0397     MOV        EAX,dword ptr [ESI + 0x18]
//         004c039a     ADD        ESP,0x4
//         004c039d     MOV        this,dword ptr [EAX + EDX*0x4]
//         004c03a0     ADD        this,0x28
//         004c03a3     PUSH       this
//                              sprite.cpp:541 (2)
//         004c03a4     JMP        LAB_004c03a8
//                               LAB_004c03a6                                                 XREF[1]:     004c0387(j)
//                              sprite.cpp:542 (29)
//         004c03a6     PUSH       0x0
//                               LAB_004c03a8                                                 XREF[1]:     004c03a4(j)
//         004c03a8     MOV        DL,byte ptr [ESI + 0x28]
//         004c03ab     MOV        EAX,dword ptr [ESP + fname]
//         004c03af     MOV        this,dword ptr [ESP + param_6]
//         004c03b6     PUSH       EDX
//         004c03b7     PUSH       EAX
//         004c03b8     PUSH       EDI
//         004c03b9     PUSH       EBP
//         004c03ba     PUSH       this
//         004c03bb     MOV        this,dword ptr [ESI + 0x1c]
//         004c03be     CALL       TShape::shape_mirror                             uchar shape_mirror(TShape * this, TDrawArea *
//                              sprite.cpp:545 (5)
//         004c03c3     JMP        LAB_004c04a4
//                               LAB_004c03c8                                                 XREF[1]:     004c02d6(j)
//                              sprite.cpp:549 (18)
//         004c03c8     MOV        EDI,dword ptr [ESP + param_4]
//         004c03cf     CMP        EAX,EBP
//         004c03d1     MOV        EBP,dword ptr [ESP + param_3]
//         004c03d8     JZ         LAB_004c041c
//                              sprite.cpp:552 (29)
//         004c03da     MOV        EAX,dword ptr [ESP + fname]
//         004c03de     XOR        EDX,EDX
//         004c03e0     MOV        DL,byte ptr [ESI + 0x28]
//         004c03e3     LEA        this=>s[4],[ESP + 0x1c]
//         004c03e7     PUSH       EDX
//         004c03e8     PUSH       EAX
//         004c03e9     PUSH       EDI
//         004c03ea     PUSH       EBP
//         004c03eb     PUSH       ESI
//         004c03ec     PUSH       s_<%s,%d,%d,%d,%d,u                              = "<%s,%d,%d,%d,%d,u"
//         004c03f1     PUSH       this
//         004c03f2     CALL       sprintf                                          undefined sprintf()
//                              sprite.cpp:553 (12)
//         004c03f7     MOV        EAX,[safe_draw_log]
//         004c03fc     ADD        ESP,0x1c
//         004c03ff     TEST       EAX,EAX
//         004c0401     JZ         LAB_004c040f
//                              sprite.cpp:554 (10)
//         004c0403     LEA        EDX=>s[4],[ESP + 0x1c]
//         004c0407     PUSH       EDX
//         004c0408     CALL       write_draw_log2                                  void write_draw_log2(char * param_1)
//                              sprite.cpp:555 (2)
//         004c040d     JMP        LAB_004c0419
//                               LAB_004c040f                                                 XREF[1]:     004c0401(j)
//                              sprite.cpp:556 (13)
//         004c040f     LEA        EAX=>s[4],[ESP + 0x1c]
//         004c0413     PUSH       EAX
//         004c0414     CALL       write_draw_log                                   void write_draw_log(char * param_1)
//                               LAB_004c0419                                                 XREF[1]:     004c040d(j)
//         004c0419     ADD        ESP,0x4
//                               LAB_004c041c                                                 XREF[1]:     004c03d8(j)
//                              sprite.cpp:559 (9)
//         004c041c     MOV        AX,word ptr [ESI + 0x2a]
//         004c0420     TEST       AX,AX
//         004c0423     JGE        LAB_004c045e
//                              sprite.cpp:561 (11)
//         004c0425     MOV        EBX,dword ptr [ESP + param_5]
//         004c042c     TEST       EBX,EBX
//         004c042e     JZ         LAB_004c0447
//                              sprite.cpp:563 (17)
//         004c0430     MOVSX      this,word ptr [EBX + 0x26]
//         004c0434     INC        this
//         004c0435     SHL        this,0x4
//         004c0438     PUSH       this
//         004c0439     CALL       _ASMSet_Color_Xform                              undefined _ASMSet_Color_Xform()
//         004c043e     ADD        ESP,0x4
//                              sprite.cpp:564 (4)
//         004c0441     ADD        EBX,0x28
//         004c0444     PUSH       EBX
//                              sprite.cpp:566 (2)
//         004c0445     JMP        LAB_004c0449
//                               LAB_004c0447                                                 XREF[1]:     004c042e(j)
//                              sprite.cpp:567 (21)
//         004c0447     PUSH       0x0
//                               LAB_004c0449                                                 XREF[1]:     004c0445(j)
//         004c0449     MOV        DL,byte ptr [ESI + 0x28]
//         004c044c     MOV        EAX,dword ptr [ESP + fname]
//         004c0450     MOV        this,dword ptr [ESP + param_6]
//         004c0457     PUSH       EDX
//         004c0458     PUSH       EAX
//         004c0459     PUSH       EDI
//         004c045a     PUSH       EBP
//         004c045b     PUSH       this
//                              sprite.cpp:569 (2)
//         004c045c     JMP        LAB_004c049c
//                               LAB_004c045e                                                 XREF[1]:     004c0423(j)
//                              sprite.cpp:571 (12)
//         004c045e     MOV        EDX,dword ptr [ESI + 0x18]
//         004c0461     MOVSX      EAX,AX
//         004c0464     CMP        dword ptr [EDX + EAX*0x4],0x0
//         004c0468     JZ         LAB_004c0487
//                              sprite.cpp:573 (10)
//         004c046a     INC        EAX
//         004c046b     SHL        EAX,0x4
//         004c046e     PUSH       EAX
//         004c046f     CALL       _ASMSet_Color_Xform                              undefined _ASMSet_Color_Xform()
//                              sprite.cpp:574 (17)
//         004c0474     MOVSX      EAX,word ptr [ESI + 0x2a]
//         004c0478     MOV        this,dword ptr [ESI + 0x18]
//         004c047b     ADD        ESP,0x4
//         004c047e     MOV        EDX,dword ptr [this->pict_name[0] + EAX*0x4]
//         004c0481     ADD        EDX,0x28
//         004c0484     PUSH       EDX
//                              sprite.cpp:576 (2)
//         004c0485     JMP        LAB_004c0489
//                               LAB_004c0487                                                 XREF[1]:     004c0468(j)
//                              sprite.cpp:577 (29)
//         004c0487     PUSH       0x0
//                               LAB_004c0489                                                 XREF[1]:     004c0485(j)
//         004c0489     MOV        AL,byte ptr [ESI + 0x28]
//         004c048c     MOV        this,dword ptr [ESP + fname]
//         004c0490     MOV        EDX,dword ptr [ESP + param_6]
//         004c0497     PUSH       EAX
//         004c0498     PUSH       this
//         004c0499     PUSH       EDI
//         004c049a     PUSH       EBP
//         004c049b     PUSH       EDX
//                               LAB_004c049c                                                 XREF[1]:     004c045c(j)
//         004c049c     MOV        this,dword ptr [ESI + 0x1c]
//         004c049f     CALL       TShape::shape_draw                               uchar shape_draw(TShape * this, TDrawArea * p
//                               LAB_004c04a4                                                 XREF[2]:     004c0378(j), 004c03c3(j)
//                              sprite.cpp:582 (9)
//         004c04a4     MOV        EAX,[do_draw_log]
//         004c04a9     TEST       EAX,EAX
//         004c04ab     JZ         LAB_004c04ca
//                              sprite.cpp:584 (5)
//         004c04ad     MOV        EAX,[safe_draw_log]
//                              sprite.cpp:585 (14)
//         004c04b2     PUSH       s_>                                              = 3Eh
//         004c04b7     TEST       EAX,EAX
//         004c04b9     JZ         LAB_004c04c2
//         004c04bb     CALL       write_draw_log2                                  void write_draw_log2(char * param_1)
//                              sprite.cpp:586 (2)
//         004c04c0     JMP        LAB_004c04c7
//                               LAB_004c04c2                                                 XREF[1]:     004c04b9(j)
//                              sprite.cpp:587 (8)
//         004c04c2     CALL       write_draw_log                                   void write_draw_log(char * param_1)
//                               LAB_004c04c7                                                 XREF[1]:     004c04c0(j)
//         004c04c7     ADD        ESP,0x4
//                               LAB_004c04ca                                                 XREF[2]:     004c01e6(j), 004c04ab(j)
//                              sprite.cpp:590 (27)
//         004c04ca     MOV        this,dword ptr [ESP + local_c]
//         004c04d1     POP        EDI
//         004c04d2     POP        ESI
//         004c04d3     POP        EBP
//         004c04d4     MOV        dword ptr FS:[0x0],this
//         004c04db     POP        EBX
//         004c04dc     ADD        ESP,0x118
//         004c04e2     RET        0x1c
//         004c04e5     ??         90h
//         004c04e6     NOP
//         004c04e7     NOP
//         004c04e8     NOP
//         004c04e9     NOP
//         004c04ea     NOP
//         004c04eb     NOP
//         004c04ec     NOP
//         004c04ed     NOP
//         004c04ee     NOP
//         004c04ef     NOP
    return;
}

uchar RGE_Sprite::draw(long param_1, long param_2, long param_3, long param_4, long param_5, long param_6, RGE_Color_Table* param_7, TDrawArea* param_8, uchar param_9) {
    /* TODO: Stub */
//                              uchar __thiscall draw(RGE_Sprite * this, long param_1, long param_2,
//              uchar             AL:1           <RETURN>
//              RGE_Sprite *      ECX:4 (auto)   this
//              long              Stack[0x4]:4   param_1                   XREF[3]:     004c04f6(R), 004c050b(W), 004c05a7(R)
//              long              Stack[0x8]:4   param_2                   XREF[2]:     004c059c(R), 004c0603(R)
//              long              Stack[0xc]:4   param_3                   XREF[2]:     004c0595(R), 004c05fe(R)
//              long              Stack[0x10]:4  param_4                   XREF[2]:     004c058c(R), 004c05fa(R)
//              long              Stack[0x14]:4  param_5                   XREF[2]:     004c0586(R), 004c05f3(R)
//              long              Stack[0x18]:4  param_6                   XREF[2]:     004c057d(R), 004c05ef(R)
//              RGE_Color_Tabl    Stack[0x1c]:4  param_7                   XREF[2]:     004c053a(R), 004c05e7(R)
//              TDrawArea *       Stack[0x20]:4  param_8                   XREF[2]:     004c0536(R), 004c05dc(R)
//              uchar             Stack[0x24]:1  param_9                   XREF[2]:     004c0570(R), 004c05e2(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[3]:     004c0540(W), 004c05b3(R), 004c05c5(W)
//              undefined4        Stack[-0x8]:4  local_8                   XREF[3]:     004c052c(W), 004c05af(R), 004c05c1(W)
//              long              Stack[-0xc]:4  index                     XREF[2]:     004c0503(W), 004c05ab(R)
//                               ?draw@RGE_Sprite@@QAEEJJJJJJPAVRGE_Color_Table@@PAVTDrawAre  XREF[4]:     draw:0041ae9a(c),
//                               RGE_Sprite::draw                                                          draw:0041b464(c),
//                                                                                                         draw:0045482d(c),
//                                                                                                         draw:0050e82a(c)
//                              sprite.cpp:594 (6)
//         004c04f0     SUB        ESP,0xc
//         004c04f3     MOV        EDX,this
//         004c04f5     PUSH       EBX
//                              sprite.cpp:598 (19)
//         004c04f6     MOV        EBX,dword ptr [ESP + param_1]
//         004c04fa     PUSH       EBP
//         004c04fb     MOVSX      EAX,word ptr [EDX + 0x60]
//         004c04ff     PUSH       ESI
//         004c0500     CMP        EBX,EAX
//         004c0502     PUSH       EDI
//         004c0503     MOV        dword ptr [ESP + index],EDX
//         004c0507     JL         LAB_004c050f
//                              sprite.cpp:599 (6)
//         004c0509     XOR        EBX,EBX
//         004c050b     MOV        dword ptr [ESP + param_1],EBX
//                               LAB_004c050f                                                 XREF[1]:     004c0507(j)
//                              sprite.cpp:601 (24)
//         004c050f     MOV        SI,word ptr [EDX + 0x36]
//         004c0513     TEST       SI,SI
//         004c0516     JLE        LAB_004c05d9
//         004c051c     MOV        EAX,dword ptr [EDX + 0x38]
//         004c051f     TEST       EAX,EAX
//         004c0521     JZ         LAB_004c05d9
//                              sprite.cpp:610 (15)
//         004c0527     XOR        EAX,EAX
//         004c0529     TEST       SI,SI
//         004c052c     MOV        dword ptr [ESP + local_8],EAX
//         004c0530     JLE        LAB_004c0616
//                              sprite.cpp:621 (35)
//         004c0536     MOV        EDI,dword ptr [ESP + param_8]
//         004c053a     MOV        EBP,dword ptr [ESP + param_7]
//         004c053e     XOR        ESI,ESI
//         004c0540     MOV        dword ptr [ESP + local_4],ESI
//                               LAB_004c0544                                                 XREF[1]:     004c05c9(j)
//         004c0544     MOV        this,dword ptr [EDX + 0x38]
//         004c0547     ADD        ESI,this
//         004c0549     MOV        AX,word ptr [ESI + 0xc]
//         004c054d     TEST       AX,AX
//         004c0550     JL         LAB_004c0559
//         004c0552     MOVSX      EAX,AX
//         004c0555     CMP        EAX,EBX
//         004c0557     JNZ        LAB_004c05af
//                               LAB_004c0559                                                 XREF[1]:     004c0550(j)
//                              sprite.cpp:613 (17)
//         004c0559     MOV        this,dword ptr [ESI + 0x4]
//         004c055c     MOVSX      EAX,word ptr [ECX + this->facet_num]
//         004c0560     IMUL       EAX,EBX
//         004c0563     MOVSX      EBX,word ptr [EDX + 0x60]
//         004c0567     CDQ
//         004c0568     IDIV       EBX
//                              sprite.cpp:614 (6)
//         004c056a     MOV        DL,byte ptr [ECX + this->draw_level]
//         004c056d     CMP        DL,0xa
//                              sprite.cpp:615 (26)
//         004c0570     MOV        EDX,dword ptr [ESP + param_9]
//         004c0574     PUSH       EDX
//         004c0575     PUSH       EDI
//         004c0576     MOVSX      EDX,word ptr [ESI + 0xa]
//         004c057a     PUSH       EBP
//         004c057b     JA         LAB_004c058c
//         004c057d     ADD        EDX,dword ptr [ESP + param_6]
//         004c0581     PUSH       EDX
//         004c0582     MOVSX      EDX,word ptr [ESI + 0x8]
//         004c0586     MOV        ESI,dword ptr [ESP + param_5]
//                              sprite.cpp:616 (2)
//         004c058a     JMP        LAB_004c0599
//                               LAB_004c058c                                                 XREF[1]:     004c057b(j)
//                              sprite.cpp:617 (67)
//         004c058c     ADD        EDX,dword ptr [ESP + param_4]
//         004c0590     PUSH       EDX
//         004c0591     MOVSX      EDX,word ptr [ESI + 0x8]
//         004c0595     MOV        ESI,dword ptr [ESP + param_3]
//                               LAB_004c0599                                                 XREF[1]:     004c058a(j)
//         004c0599     ADD        EDX,ESI
//         004c059b     PUSH       EDX
//         004c059c     MOV        EDX,dword ptr [ESP + param_2]
//         004c05a0     PUSH       EDX
//         004c05a1     PUSH       EAX
//         004c05a2     CALL       RGE_Sprite::do_draw                              void do_draw(RGE_Sprite * this, long param_1,
//         004c05a7     MOV        EBX,dword ptr [ESP + param_1]
//         004c05ab     MOV        EDX,dword ptr [ESP + index]
//                               LAB_004c05af                                                 XREF[1]:     004c0557(j)
//         004c05af     MOV        EAX,dword ptr [ESP + local_8]
//         004c05b3     MOV        ESI,dword ptr [ESP + local_4]
//         004c05b7     MOVSX      this,word ptr [EDX + 0x36]
//         004c05bb     INC        EAX
//         004c05bc     ADD        ESI,0x10
//         004c05bf     CMP        EAX,this
//         004c05c1     MOV        dword ptr [ESP + local_8],EAX
//         004c05c5     MOV        dword ptr [ESP + local_4],ESI
//         004c05c9     JL         LAB_004c0544
//                              sprite.cpp:621 (10)
//         004c05cf     POP        EDI
//         004c05d0     POP        ESI
//         004c05d1     POP        EBP
//         004c05d2     POP        EBX
//         004c05d3     ADD        ESP,0xc
//         004c05d6     RET        0x24
//                               LAB_004c05d9                                                 XREF[2]:     004c0516(j), 004c0521(j)
//                              sprite.cpp:603 (3)
//         004c05d9     MOV        AL,byte ptr [EDX + 0x29]
//                              sprite.cpp:604 (28)
//         004c05dc     MOV        this,dword ptr [ESP + param_8]
//         004c05e0     CMP        AL,0xa
//         004c05e2     MOV        EAX,dword ptr [ESP + param_9]
//         004c05e6     PUSH       EAX
//         004c05e7     MOV        EAX,dword ptr [ESP + param_7]
//         004c05eb     PUSH       this
//         004c05ec     PUSH       EAX
//         004c05ed     JA         LAB_004c05fa
//         004c05ef     MOV        this,dword ptr [ESP + param_6]
//         004c05f3     MOV        EAX,dword ptr [ESP + param_5]
//         004c05f7     PUSH       this
//                              sprite.cpp:605 (2)
//         004c05f8     JMP        LAB_004c0603
//                               LAB_004c05fa                                                 XREF[1]:     004c05ed(j)
//                              sprite.cpp:606 (23)
//         004c05fa     MOV        this,dword ptr [ESP + param_4]
//         004c05fe     MOV        EAX,dword ptr [ESP + param_3]
//         004c0602     PUSH       this
//                               LAB_004c0603                                                 XREF[1]:     004c05f8(j)
//         004c0603     MOV        this,dword ptr [ESP + param_2]
//         004c0607     PUSH       EAX
//         004c0608     PUSH       this
//         004c0609     PUSH       EBX
//         004c060a     MOV        this,EDX
//         004c060c     CALL       RGE_Sprite::do_draw                              void do_draw(RGE_Sprite * this, long param_1,
//                              sprite.cpp:607 (5)
//         004c0611     MOV        EAX,0x1
//                               LAB_004c0616                                                 XREF[1]:     004c0530(j)
//                              sprite.cpp:621 (10)
//         004c0616     POP        EDI
//         004c0617     POP        ESI
//         004c0618     POP        EBP
//         004c0619     POP        EBX
//         004c061a     ADD        ESP,0xc
//         004c061d     RET        0x24
    return 0;
}

uchar RGE_Sprite::normal_draw(long param_1, long param_2, long param_3, long param_4, RGE_Color_Table* param_5, TDrawArea* param_6) {
    /* TODO: Stub */
//                              uchar __thiscall normal_draw(RGE_Sprite * this, long param_1, long p
//              uchar             AL:1           <RETURN>
//              RGE_Sprite *      ECX:4 (auto)   this
//              long              Stack[0x4]:4   param_1                   XREF[5]:     004c0627(R), 004c065e(W), 004c0665(R), 004c06c5(R),
//                                                                                     004c06d3(W)
//              long              Stack[0x8]:4   param_2                   XREF[2]:     004c06a4(R), 004c06fc(R)
//              long              Stack[0xc]:4   param_3                   XREF[2]:     004c069c(R), 004c06f7(R)
//              long              Stack[0x10]:4  param_4                   XREF[2]:     004c068a(R), 004c06f1(R)
//              RGE_Color_Tabl    Stack[0x14]:4  param_5                   XREF[2]:     004c0686(R), 004c06ed(R)
//              TDrawArea *       Stack[0x18]:4  param_6                   XREF[2]:     004c065a(R), 004c06e9(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[3]:     004c0650(W), 004c06bd(R), 004c06cf(W)
//              long              Stack[-0x8]:4  index
//                               ?normal_draw@RGE_Sprite@@QAEEJJJJPAVRGE_Color_Table@@PAVTDr  XREF[2]:     normal_draw:0041aed9(c),
//                               RGE_Sprite::normal_draw                                                   normal_draw:0041b4c8(c)
//                              sprite.cpp:625 (7)
//         004c0620     PUSH       this
//         004c0621     PUSH       EBX
//         004c0622     PUSH       EBP
//         004c0623     PUSH       ESI
//         004c0624     MOV        ESI,this
//         004c0626     PUSH       EDI
//                              sprite.cpp:630 (12)
//         004c0627     MOV        EDI,dword ptr [ESP + param_1]
//         004c062b     MOVSX      EAX,word ptr [ESI + 0x60]
//         004c062f     CMP        EDI,EAX
//         004c0631     JL         LAB_004c0635
//                              sprite.cpp:631 (2)
//         004c0633     XOR        EDI,EDI
//                               LAB_004c0635                                                 XREF[1]:     004c0631(j)
//                              sprite.cpp:633 (24)
//         004c0635     MOV        AX,word ptr [ESI + 0x36]
//         004c0639     XOR        EBX,EBX
//         004c063b     CMP        AX,BX
//         004c063e     JLE        LAB_004c06e3
//         004c0644     CMP        dword ptr [ESI + 0x38],EBX
//         004c0647     JZ         LAB_004c06e3
//                              sprite.cpp:640 (13)
//         004c064d     CMP        AX,BX
//         004c0650     MOV        dword ptr [ESP + local_4],EBX
//         004c0654     JLE        LAB_004c0710
//                              sprite.cpp:652 (44)
//         004c065a     MOV        EBP,dword ptr [ESP + param_6]
//         004c065e     MOV        dword ptr [ESP + param_1],EBX
//                               LAB_004c0662                                                 XREF[1]:     004c06d7(j)
//         004c0662     MOV        this,dword ptr [ESI + 0x38]
//         004c0665     MOV        EDX,dword ptr [ESP + param_1]
//         004c0669     LEA        EAX,[this->pict_name[0] + EDX*0x1]
//         004c066c     MOV        this,dword ptr [ECX + EDX*0x1 + this+0x4]
//         004c0670     CMP        byte ptr [ECX + this->draw_level],0x14
//         004c0674     JNZ        LAB_004c06c1
//         004c0676     MOV        DX,word ptr [EAX + 0xc]
//         004c067a     TEST       DX,DX
//         004c067d     JL         LAB_004c0686
//         004c067f     MOVSX      EDX,DX
//         004c0682     CMP        EDX,EDI
//         004c0684     JNZ        LAB_004c06c1
//                               LAB_004c0686                                                 XREF[1]:     004c067d(j)
//                              sprite.cpp:647 (83)
//         004c0686     MOV        EDX,dword ptr [ESP + param_5]
//         004c068a     MOV        EBX,dword ptr [ESP + param_4]
//         004c068e     PUSH       0x0
//         004c0690     PUSH       EBP
//         004c0691     PUSH       EDX
//         004c0692     MOVSX      EDX,word ptr [EAX + 0xa]
//         004c0696     MOVSX      EAX,word ptr [EAX + 0x8]
//         004c069a     ADD        EDX,EBX
//         004c069c     MOV        EBX,dword ptr [ESP + param_3]
//         004c06a0     ADD        EAX,EBX
//         004c06a2     PUSH       EDX
//         004c06a3     PUSH       EAX
//         004c06a4     MOV        EDX,dword ptr [ESP + param_2]
//         004c06a8     MOVSX      EAX,word ptr [ECX + this->facet_num]
//         004c06ac     IMUL       EAX,EDI
//         004c06af     MOVSX      EBX,word ptr [ESI + 0x60]
//         004c06b3     PUSH       EDX
//         004c06b4     CDQ
//         004c06b5     IDIV       EBX
//         004c06b7     PUSH       EAX
//         004c06b8     CALL       RGE_Sprite::do_draw                              void do_draw(RGE_Sprite * this, long param_1,
//         004c06bd     MOV        EBX,dword ptr [ESP + local_4]
//                               LAB_004c06c1                                                 XREF[2]:     004c0674(j), 004c0684(j)
//         004c06c1     MOVSX      EAX,word ptr [ESI + 0x36]
//         004c06c5     MOV        EDX,dword ptr [ESP + param_1]
//         004c06c9     INC        EBX
//         004c06ca     ADD        EDX,0x10
//         004c06cd     CMP        EBX,EAX
//         004c06cf     MOV        dword ptr [ESP + local_4],EBX
//         004c06d3     MOV        dword ptr [ESP + param_1],EDX
//         004c06d7     JL         LAB_004c0662
//                              sprite.cpp:651 (2)
//         004c06d9     MOV        AL,BL
//                              sprite.cpp:652 (8)
//         004c06db     POP        EDI
//         004c06dc     POP        ESI
//         004c06dd     POP        EBP
//         004c06de     POP        EBX
//         004c06df     POP        this
//         004c06e0     RET        0x18
//                               LAB_004c06e3                                                 XREF[2]:     004c063e(j), 004c0647(j)
//                              sprite.cpp:635 (6)
//         004c06e3     CMP        byte ptr [ESI + 0x29],0x14
//         004c06e7     JNZ        LAB_004c070b
//                              sprite.cpp:636 (34)
//         004c06e9     MOV        this,dword ptr [ESP + param_6]
//         004c06ed     MOV        EDX,dword ptr [ESP + param_5]
//         004c06f1     MOV        EAX,dword ptr [ESP + param_4]
//         004c06f5     PUSH       EBX
//         004c06f6     PUSH       this
//         004c06f7     MOV        this,dword ptr [ESP + param_3]
//         004c06fb     PUSH       EDX
//         004c06fc     MOV        EDX,dword ptr [ESP + param_2]
//         004c0700     PUSH       EAX
//         004c0701     PUSH       this
//         004c0702     PUSH       EDX
//         004c0703     PUSH       EDI
//         004c0704     MOV        this,ESI
//         004c0706     CALL       RGE_Sprite::do_draw                              void do_draw(RGE_Sprite * this, long param_1,
//                               LAB_004c070b                                                 XREF[1]:     004c06e7(j)
//                              sprite.cpp:637 (5)
//         004c070b     MOV        EBX,0x1
//                               LAB_004c0710                                                 XREF[1]:     004c0654(j)
//                              sprite.cpp:652 (10)
//         004c0710     POP        EDI
//         004c0711     POP        ESI
//         004c0712     MOV        AL,BL
//         004c0714     POP        EBP
//         004c0715     POP        EBX
//         004c0716     POP        this
//         004c0717     RET        0x18
//         004c071a     ??         90h
//         004c071b     NOP
//         004c071c     NOP
//         004c071d     NOP
//         004c071e     NOP
//         004c071f     NOP
    return 0;
}

uchar RGE_Sprite::shadow_draw(long param_1, long param_2, long param_3, long param_4, RGE_Color_Table* param_5, TDrawArea* param_6, uchar param_7) {
    /* TODO: Stub */
//                              uchar __thiscall shadow_draw(RGE_Sprite * this, long param_1, long p
//              uchar             AL:1           <RETURN>
//              RGE_Sprite *      ECX:4 (auto)   this
//              long              Stack[0x4]:4   param_1                   XREF[7]:     004c0723(R), 004c0750(W), 004c07c9(R), 004c07d5(W),
//                                                                                     004c07e1(R), 004c081e(W), 004c0826(R)
//              long              Stack[0x8]:4   param_2                   XREF[2]:     004c07a4(R), 004c080f(R)
//              long              Stack[0xc]:4   param_3                   XREF[2]:     004c07a9(R), 004c080a(R)
//              long              Stack[0x10]:4  param_4                   XREF[2]:     004c079c(R), 004c0800(R)
//              RGE_Color_Tabl    Stack[0x14]:4  param_5                   XREF[2]:     004c0790(R), 004c0805(R)
//              TDrawArea *       Stack[0x18]:4  param_6                   XREF[2]:     004c075a(R), 004c07fc(R)
//              uchar             Stack[0x1c]:1  param_7                   XREF[2]:     004c0770(R), 004c07f0(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[4]:     004c075e(W), 004c0765(R), 004c07c5(R), 004c07d1(W)
//                               ?shadow_draw@RGE_Sprite@@QAEEJJJJPAVRGE_Color_Table@@PAVTDr  XREF[2]:     shadow_draw:0041af1e(c),
//                               RGE_Sprite::shadow_draw                                                   shadow_draw:0041b517(c)
//                              sprite.cpp:656 (3)
//         004c0720     PUSH       this
//         004c0721     PUSH       EBX
//         004c0722     PUSH       EBP
//                              sprite.cpp:661 (16)
//         004c0723     MOV        EBP,dword ptr [ESP + param_1]
//         004c0727     PUSH       ESI
//         004c0728     PUSH       EDI
//         004c0729     MOV        EDI,this
//         004c072b     MOVSX      EAX,word ptr [EDI + 0x60]
//         004c072f     CMP        EBP,EAX
//         004c0731     JL         LAB_004c0735
//                              sprite.cpp:662 (2)
//         004c0733     XOR        EBP,EBP
//                               LAB_004c0735                                                 XREF[1]:     004c0731(j)
//                              sprite.cpp:664 (24)
//         004c0735     MOV        AX,word ptr [EDI + 0x36]
//         004c0739     XOR        this,this
//         004c073b     CMP        AX,this
//         004c073e     JLE        LAB_004c07ed
//         004c0744     CMP        dword ptr [EDI + 0x38],this
//         004c0747     JZ         LAB_004c07ed
//                              sprite.cpp:671 (13)
//         004c074d     CMP        AX,this
//         004c0750     MOV        dword ptr [ESP + param_1],this
//         004c0754     JLE        LAB_004c0826
//                              sprite.cpp:684 (33)
//         004c075a     MOV        EBX,dword ptr [ESP + param_6]
//         004c075e     MOV        dword ptr [ESP + local_4],this
//                               LAB_004c0762                                                 XREF[1]:     004c07df(j)
//         004c0762     MOV        this,dword ptr [EDI + 0x38]
//         004c0765     MOV        EDX,dword ptr [ESP + local_4]
//         004c0769     MOV        ESI,dword ptr [ECX + EDX*0x1 + this+0x4]
//         004c076d     LEA        EAX,[this->pict_name[0] + EDX*0x1]
//         004c0770     MOV        DL,byte ptr [ESP + param_7]
//         004c0774     MOV        this,byte ptr [ESI + 0x29]
//         004c0777     CMP        this,DL
//         004c0779     JZ         LAB_004c07c5
//                              sprite.cpp:676 (21)
//         004c077b     CMP        this,0x14
//         004c077e     JNC        LAB_004c07c5
//         004c0780     MOV        this,word ptr [EAX + 0xc]
//         004c0784     TEST       this,this
//         004c0787     JL         LAB_004c0790
//         004c0789     MOVSX      this,this
//         004c078c     CMP        this,EBP
//         004c078e     JNZ        LAB_004c07c5
//                               LAB_004c0790                                                 XREF[1]:     004c0787(j)
//                              sprite.cpp:679 (81)
//         004c0790     MOV        EDX,dword ptr [ESP + param_5]
//         004c0794     PUSH       0x0
//         004c0796     MOVSX      this,word ptr [EAX + 0xa]
//         004c079a     PUSH       EBX
//         004c079b     PUSH       EDX
//         004c079c     ADD        this,dword ptr [ESP + param_4]
//         004c07a0     MOVSX      EDX,word ptr [EAX + 0x8]
//         004c07a4     MOV        EAX,dword ptr [ESP + param_2]
//         004c07a8     PUSH       this
//         004c07a9     ADD        EDX,dword ptr [ESP + param_3]
//         004c07ad     PUSH       EDX
//         004c07ae     PUSH       EAX
//         004c07af     MOVSX      EAX,word ptr [ESI + 0x60]
//         004c07b3     IMUL       EAX,EBP
//         004c07b6     MOVSX      this,word ptr [EDI + 0x60]
//         004c07ba     CDQ
//         004c07bb     IDIV       this
//         004c07bd     MOV        this,ESI
//         004c07bf     PUSH       EAX
//         004c07c0     CALL       RGE_Sprite::do_draw                              void do_draw(RGE_Sprite * this, long param_1,
//                               LAB_004c07c5                                                 XREF[3]:     004c0779(j), 004c077e(j),
//                                                                                                         004c078e(j)
//         004c07c5     MOV        EDX,dword ptr [ESP + local_4]
//         004c07c9     MOV        EAX,dword ptr [ESP + param_1]
//         004c07cd     ADD        EDX,0x10
//         004c07d0     INC        EAX
//         004c07d1     MOV        dword ptr [ESP + local_4],EDX
//         004c07d5     MOV        dword ptr [ESP + param_1],EAX
//         004c07d9     MOVSX      EDX,word ptr [EDI + 0x36]
//         004c07dd     CMP        EAX,EDX
//         004c07df     JL         LAB_004c0762
//                              sprite.cpp:683 (4)
//         004c07e1     MOV        AL,byte ptr [ESP + param_1]
//                              sprite.cpp:684 (8)
//         004c07e5     POP        EDI
//         004c07e6     POP        ESI
//         004c07e7     POP        EBP
//         004c07e8     POP        EBX
//         004c07e9     POP        this
//         004c07ea     RET        0x1c
//                               LAB_004c07ed                                                 XREF[2]:     004c073e(j), 004c0747(j)
//                              sprite.cpp:666 (15)
//         004c07ed     MOV        AL,byte ptr [EDI + 0x29]
//         004c07f0     MOV        DL,byte ptr [ESP + param_7]
//         004c07f4     CMP        AL,DL
//         004c07f6     JZ         LAB_004c081e
//         004c07f8     CMP        AL,0x14
//         004c07fa     JNC        LAB_004c081e
//                              sprite.cpp:667 (34)
//         004c07fc     MOV        EAX,dword ptr [ESP + param_6]
//         004c0800     MOV        EDX,dword ptr [ESP + param_4]
//         004c0804     PUSH       this
//         004c0805     MOV        this,dword ptr [ESP + param_5]
//         004c0809     PUSH       EAX
//         004c080a     MOV        EAX,dword ptr [ESP + param_3]
//         004c080e     PUSH       this
//         004c080f     MOV        this,dword ptr [ESP + param_2]
//         004c0813     PUSH       EDX
//         004c0814     PUSH       EAX
//         004c0815     PUSH       this
//         004c0816     PUSH       EBP
//         004c0817     MOV        this,EDI
//         004c0819     CALL       RGE_Sprite::do_draw                              void do_draw(RGE_Sprite * this, long param_1,
//                               LAB_004c081e                                                 XREF[2]:     004c07f6(j), 004c07fa(j)
//                              sprite.cpp:668 (8)
//         004c081e     MOV        dword ptr [ESP + param_1],0x1
//                               LAB_004c0826                                                 XREF[1]:     004c0754(j)
//                              sprite.cpp:683 (4)
//         004c0826     MOV        AL,byte ptr [ESP + param_1]
//                              sprite.cpp:684 (8)
//         004c082a     POP        EDI
//         004c082b     POP        ESI
//         004c082c     POP        EBP
//         004c082d     POP        EBX
//         004c082e     POP        this
//         004c082f     RET        0x1c
//         004c0832     ??         90h
//         004c0833     NOP
//         004c0834     NOP
//         004c0835     NOP
//         004c0836     NOP
//         004c0837     NOP
//         004c0838     NOP
//         004c0839     NOP
//         004c083a     NOP
//         004c083b     NOP
//         004c083c     NOP
//         004c083d     NOP
//         004c083e     NOP
//         004c083f     NOP
    return 0;
}

int RGE_Sprite::get_size(long* param_1, long* param_2, long* param_3, long* param_4, long param_5) {
    /* TODO: Stub */
//                              int __thiscall get_size(RGE_Sprite * this, long * param_1, long * pa
//              int               EAX:4          <RETURN>
//              RGE_Sprite *      ECX:4 (auto)   this
//              long *            Stack[0x4]:4   param_1                   XREF[1]:     004c091b(R)
//              long *            Stack[0x8]:4   param_2                   XREF[1]:     004c0916(R)
//              long *            Stack[0xc]:4   param_3                   XREF[1]:     004c0911(R)
//              long *            Stack[0x10]:4  param_4                   XREF[1]:     004c090d(R)
//              long              Stack[0x14]:4  param_5                   XREF[1]:     004c0909(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     004c08b1(W), 004c08d9(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[2]:     004c092f(R), 004c0942(R)
//              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     004c08ab(W)
//              undefined4        Stack[-0x14]:4 local_14                  XREF[4]:     004c0877(*), 004c087d(W), 004c08be(R), 004c08fc(R)
//              char *            Stack[-0x18]:4 fname
//                               ?get_size@RGE_Sprite@@QAEHAAJ000J@Z                          XREF[2]:     draw:004befef(c),
//                               RGE_Sprite::get_size                                                      get_frame_min_max:004c0bba(c)
//                              sprite.cpp:688 (28)
//         004c0840     MOV        EAX,FS:[0x0]
//         004c0846     PUSH       -0x1
//         004c0848     PUSH       FUN_0055f91b
//         004c084d     PUSH       EAX
//         004c084e     MOV        dword ptr FS:[0x0],ESP
//         004c0855     SUB        ESP,0x8
//         004c0858     PUSH       ESI
//         004c0859     MOV        ESI,this
//         004c085b     PUSH       EDI
//                              sprite.cpp:691 (11)
//         004c085c     MOV        EAX,dword ptr [ESI + 0x1c]
//         004c085f     TEST       EAX,EAX
//         004c0861     JNZ        LAB_004c0909
//                              sprite.cpp:693 (11)
//         004c0867     MOV        AL,byte ptr [ESI + 0x14]
//         004c086a     TEST       AL,AL
//         004c086c     JZ         LAB_004c0942
//                              sprite.cpp:696 (27)
//         004c0872     PUSH       s_.shp                                           = ".shp"
//         004c0877     LEA        EAX=>local_14,[ESP + 0xc]
//         004c087b     PUSH       ESI
//         004c087c     PUSH       EAX
//         004c087d     MOV        dword ptr [ESP + local_14],0x0
//         004c0885     CALL       addstring                                        void addstring(char * * param_1, char * param
//         004c088a     ADD        ESP,0xc
//                              sprite.cpp:697 (20)
//         004c088d     PUSH       0x2b9
//         004c0892     PUSH       s_C:\msdev\work\age1_x1\sprite.cpp               = "C:\\msdev\\work\\age1_x1\\sprite.cpp"
//         004c0897     CALL       debug_timeGetTime                                ulong debug_timeGetTime(char * param_1, int p
//         004c089c     ADD        ESP,0x8
//         004c089f     MOV        EDI,EAX
//                              sprite.cpp:698 (46)
//         004c08a1     PUSH       0x20
//         004c08a3     CALL       operator_new                                     void * operator_new(uint param_1)
//         004c08a8     ADD        ESP,0x4
//         004c08ab     MOV        dword ptr [ESP + local_10],EAX
//         004c08af     TEST       EAX,EAX
//         004c08b1     MOV        dword ptr [ESP + local_4],0x0
//         004c08b9     JZ         LAB_004c08cd
//         004c08bb     MOV        this,dword ptr [ESI + 0x10]
//         004c08be     MOV        EDX,dword ptr [ESP + local_14]
//         004c08c2     PUSH       this
//         004c08c3     PUSH       EDX
//         004c08c4     MOV        this,EAX
//         004c08c6     CALL       TShape::TShape                                   undefined TShape(TShape * this, char * param_
//         004c08cb     JMP        LAB_004c08cf
//                               LAB_004c08cd                                                 XREF[1]:     004c08b9(j)
//         004c08cd     XOR        EAX,EAX
//                               LAB_004c08cf                                                 XREF[1]:     004c08cb(j)
//                              sprite.cpp:699 (45)
//         004c08cf     PUSH       0x2bb
//         004c08d4     PUSH       s_C:\msdev\work\age1_x1\sprite.cpp               = "C:\\msdev\\work\\age1_x1\\sprite.cpp"
//         004c08d9     MOV        dword ptr [ESP + local_4],0xffffffff
//         004c08e1     MOV        dword ptr [ESI + 0x1c],EAX
//         004c08e4     CALL       debug_timeGetTime                                ulong debug_timeGetTime(char * param_1, int p
//         004c08e9     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004c08ef     ADD        ESP,0x8
//         004c08f2     SUB        EAX,EDI
//         004c08f4     PUSH       EAX
//         004c08f5     PUSH       0xb
//         004c08f7     CALL       RGE_Base_Game::add_to_timing                     void add_to_timing(RGE_Base_Game * this, int
//                              sprite.cpp:700 (13)
//         004c08fc     MOV        EAX,dword ptr [ESP + local_14]
//         004c0900     PUSH       EAX
//         004c0901     CALL       free                                             undefined free()
//         004c0906     ADD        ESP,0x4
//                               LAB_004c0909                                                 XREF[1]:     004c0861(j)
//                              sprite.cpp:706 (38)
//         004c0909     MOV        this,dword ptr [ESP + param_5]
//         004c090d     MOV        EDX,dword ptr [ESP + param_4]
//         004c0911     MOV        EAX,dword ptr [ESP + param_3]
//         004c0915     PUSH       this
//         004c0916     MOV        this,dword ptr [ESP + param_2]
//         004c091a     PUSH       EDX
//         004c091b     MOV        EDX,dword ptr [ESP + param_1]
//         004c091f     PUSH       EAX
//         004c0920     PUSH       this
//         004c0921     MOV        this,dword ptr [ESI + 0x1c]
//         004c0924     PUSH       EDX
//         004c0925     CALL       TShape::shape_minmax                             uchar shape_minmax(TShape * this, long * para
//         004c092a     AND        EAX,0xff
//                              sprite.cpp:707 (40)
//         004c092f     MOV        this,dword ptr [ESP + local_c]
//         004c0933     MOV        dword ptr FS:[0x0],this
//         004c093a     POP        EDI
//         004c093b     POP        ESI
//         004c093c     ADD        ESP,0x14
//         004c093f     RET        0x14
//                               LAB_004c0942                                                 XREF[1]:     004c086c(j)
//         004c0942     MOV        this,dword ptr [ESP + local_c]
//         004c0946     POP        EDI
//         004c0947     XOR        EAX,EAX
//         004c0949     MOV        dword ptr FS:[0x0],this
//         004c0950     POP        ESI
//         004c0951     ADD        ESP,0x14
//         004c0954     RET        0x14
//         004c0957     ??         90h
//         004c0958     NOP
//         004c0959     NOP
//         004c095a     NOP
//         004c095b     NOP
//         004c095c     NOP
//         004c095d     NOP
//         004c095e     NOP
//         004c095f     NOP
    return 0;
}

int RGE_Sprite::get_frame(short* param_1, short* param_2, short* param_3, short* param_4, long param_5, long param_6) {
    /* TODO: Stub */
//                              int __thiscall get_frame(RGE_Sprite * this, short * param_1, short *
//              int               EAX:4          <RETURN>
//              RGE_Sprite *      ECX:4 (auto)   this
//              short *           Stack[0x4]:4   param_1                   XREF[5]:     004c0a46(R), 004c0a7a(W), 004c0acc(R), 004c0ada(W),
//                                                                                     004c0b20(R)
//              short *           Stack[0x8]:4   param_2                   XREF[4]:     004c0a4a(R), 004c0aba(R), 004c0ae0(R), 004c0b24(R)
//              short *           Stack[0xc]:4   param_3                   XREF[3]:     004c0a59(R), 004c0ab6(R), 004c0b32(R)
//              short *           Stack[0x10]:4  param_4                   XREF[4]:     004c0a4e(R), 004c0abf(R), 004c0b12(R), 004c0b3d(R)
//              long              Stack[0x14]:4  param_5                   XREF[2]:     004c0aae(R), 004c0aea(R)
//              long              Stack[0x18]:4  param_6                   XREF[2]:     004c0a9d(R), 004c0ae6(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     004c09cf(W), 004c09f3(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     004c0b4d(R)
//              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     004c09c9(W)
//              undefined4        Stack[-0x14]:4 local_14                  XREF[4]:     004c0999(*), 004c099f(W), 004c09d8(R), 004c0a16(R)
//              char *            Stack[-0x18]:4 fname
//                               ?get_frame@RGE_Sprite@@QAEHAAF000JJ@Z                        XREF[2]:     get_frame:0041afce(c),
//                               RGE_Sprite::get_frame                                                     get_frame:0041b5f1(c)
//                              sprite.cpp:711 (29)
//         004c0960     MOV        EAX,FS:[0x0]
//         004c0966     PUSH       -0x1
//         004c0968     PUSH       FUN_0055f93b
//         004c096d     PUSH       EAX
//         004c096e     MOV        dword ptr FS:[0x0],ESP
//         004c0975     SUB        ESP,0x8
//         004c0978     PUSH       EBX
//         004c0979     PUSH       EBP
//         004c097a     PUSH       ESI
//         004c097b     MOV        ESI,this
//                              sprite.cpp:716 (12)
//         004c097d     XOR        EBX,EBX
//         004c097f     PUSH       EDI
//         004c0980     CMP        dword ptr [ESI + 0x1c],EBX
//         004c0983     JNZ        LAB_004c0a23
//                              sprite.cpp:718 (11)
//         004c0989     MOV        AL,byte ptr [ESI + 0x14]
//         004c098c     TEST       AL,AL
//         004c098e     JZ         LAB_004c0b1c
//                              sprite.cpp:721 (23)
//         004c0994     PUSH       s_.shp                                           = ".shp"
//         004c0999     LEA        EAX=>local_14,[ESP + 0x14]
//         004c099d     PUSH       ESI
//         004c099e     PUSH       EAX
//         004c099f     MOV        dword ptr [ESP + local_14],EBX
//         004c09a3     CALL       addstring                                        void addstring(char * * param_1, char * param
//         004c09a8     ADD        ESP,0xc
//                              sprite.cpp:722 (20)
//         004c09ab     PUSH       0x2d2
//         004c09b0     PUSH       s_C:\msdev\work\age1_x1\sprite.cpp               = "C:\\msdev\\work\\age1_x1\\sprite.cpp"
//         004c09b5     CALL       debug_timeGetTime                                ulong debug_timeGetTime(char * param_1, int p
//         004c09ba     ADD        ESP,0x8
//         004c09bd     MOV        EDI,EAX
//                              sprite.cpp:723 (42)
//         004c09bf     PUSH       0x20
//         004c09c1     CALL       operator_new                                     void * operator_new(uint param_1)
//         004c09c6     ADD        ESP,0x4
//         004c09c9     MOV        dword ptr [ESP + local_10],EAX
//         004c09cd     CMP        EAX,EBX
//         004c09cf     MOV        dword ptr [ESP + local_4],EBX
//         004c09d3     JZ         LAB_004c09e7
//         004c09d5     MOV        this,dword ptr [ESI + 0x10]
//         004c09d8     MOV        EDX,dword ptr [ESP + local_14]
//         004c09dc     PUSH       this
//         004c09dd     PUSH       EDX
//         004c09de     MOV        this,EAX
//         004c09e0     CALL       TShape::TShape                                   undefined TShape(TShape * this, char * param_
//         004c09e5     JMP        LAB_004c09e9
//                               LAB_004c09e7                                                 XREF[1]:     004c09d3(j)
//         004c09e7     XOR        EAX,EAX
//                               LAB_004c09e9                                                 XREF[1]:     004c09e5(j)
//                              sprite.cpp:724 (45)
//         004c09e9     PUSH       0x2d4
//         004c09ee     PUSH       s_C:\msdev\work\age1_x1\sprite.cpp               = "C:\\msdev\\work\\age1_x1\\sprite.cpp"
//         004c09f3     MOV        dword ptr [ESP + local_4],0xffffffff
//         004c09fb     MOV        dword ptr [ESI + 0x1c],EAX
//         004c09fe     CALL       debug_timeGetTime                                ulong debug_timeGetTime(char * param_1, int p
//         004c0a03     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004c0a09     ADD        ESP,0x8
//         004c0a0c     SUB        EAX,EDI
//         004c0a0e     PUSH       EAX
//         004c0a0f     PUSH       0xb
//         004c0a11     CALL       RGE_Base_Game::add_to_timing                     void add_to_timing(RGE_Base_Game * this, int
//                              sprite.cpp:725 (13)
//         004c0a16     MOV        EAX,dword ptr [ESP + local_14]
//         004c0a1a     PUSH       EAX
//         004c0a1b     CALL       free                                             undefined free()
//         004c0a20     ADD        ESP,0x4
//                               LAB_004c0a23                                                 XREF[1]:     004c0983(j)
//                              sprite.cpp:731 (35)
//         004c0a23     MOV        AX,word ptr [ESI + 0x2e]
//         004c0a27     CMP        AX,BX
//         004c0a2a     JNZ        LAB_004c0a32
//         004c0a2c     CMP        word ptr [ESI + 0x32],BX
//         004c0a30     JZ         LAB_004c0a46
//                               LAB_004c0a32                                                 XREF[1]:     004c0a2a(j)
//         004c0a32     CMP        word ptr [ESI + 0x30],BX
//         004c0a36     JNZ        LAB_004c0b20
//         004c0a3c     CMP        word ptr [ESI + 0x34],BX
//         004c0a40     JNZ        LAB_004c0b20
//                               LAB_004c0a46                                                 XREF[1]:     004c0a30(j)
//                              sprite.cpp:740 (4)
//         004c0a46     MOV        EBP,dword ptr [ESP + param_1]
//                              sprite.cpp:741 (4)
//         004c0a4a     MOV        EDI,dword ptr [ESP + param_2]
//                              sprite.cpp:743 (25)
//         004c0a4e     MOV        this,dword ptr [ESP + param_4]
//         004c0a52     MOV        word ptr [EBP],BX
//         004c0a56     MOV        word ptr [EDI],BX
//         004c0a59     MOV        EBX,dword ptr [ESP + param_3]
//         004c0a5d     MOV        word ptr [EBX],0x0
//         004c0a62     MOV        word ptr [this->pict_name[0]],0x0
//                              sprite.cpp:745 (16)
//         004c0a67     MOV        AX,word ptr [ESI + 0x36]
//         004c0a6b     TEST       AX,AX
//         004c0a6e     JLE        LAB_004c0ae6
//         004c0a70     MOV        EDX,dword ptr [ESI + 0x38]
//         004c0a73     TEST       EDX,EDX
//         004c0a75     JZ         LAB_004c0ae6
//                              sprite.cpp:748 (13)
//         004c0a77     TEST       AX,AX
//         004c0a7a     MOV        dword ptr [ESP + param_1],0x0
//         004c0a82     JLE        LAB_004c0aff
//                              sprite.cpp:759 (2)
//         004c0a84     XOR        EDI,EDI
//                               LAB_004c0a86                                                 XREF[1]:     004c0ade(j)
//                              sprite.cpp:749 (7)
//         004c0a86     MOV        AL,byte ptr [ESI + 0x2c]
//         004c0a89     TEST       AL,AL
//         004c0a8b     JBE        LAB_004c0acc
//                              sprite.cpp:752 (83)
//         004c0a8d     MOV        this,dword ptr [ESI + 0x38]
//         004c0a90     MOVSX      EBX,word ptr [ESI + 0x60]
//         004c0a94     MOV        DX,word ptr [EDI + this->pict_name[0]*0x1 + 0xa]
//         004c0a99     LEA        EAX,[EDI + this->pict_name[0]*0x1]
//         004c0a9c     PUSH       EDX
//         004c0a9d     MOV        EDX,dword ptr [ESP + param_6]
//         004c0aa1     MOV        this,dword ptr [EAX + 0x4]
//         004c0aa4     MOV        AX,word ptr [EAX + 0x8]
//         004c0aa8     PUSH       EAX
//         004c0aa9     PUSH       EDX
//         004c0aaa     MOVSX      EAX,word ptr [ECX + this->facet_num]
//         004c0aae     IMUL       EAX,dword ptr [ESP + param_5]
//         004c0ab3     CDQ
//         004c0ab4     IDIV       EBX
//         004c0ab6     MOV        EBX,dword ptr [ESP + param_3]
//         004c0aba     MOV        EDX,dword ptr [ESP + param_2]
//         004c0abe     PUSH       EAX
//         004c0abf     MOV        EAX,dword ptr [ESP + param_4]
//         004c0ac3     PUSH       EAX
//         004c0ac4     PUSH       EBX
//         004c0ac5     PUSH       EDX
//         004c0ac6     PUSH       EBP
//         004c0ac7     CALL       RGE_Sprite::get_frame_min_max                    int get_frame_min_max(RGE_Sprite * this, shor
//                               LAB_004c0acc                                                 XREF[1]:     004c0a8b(j)
//         004c0acc     MOV        EAX,dword ptr [ESP + param_1]
//         004c0ad0     ADD        EDI,0x10
//         004c0ad3     MOVSX      this,word ptr [ESI + 0x36]
//         004c0ad7     INC        EAX
//         004c0ad8     CMP        EAX,this
//         004c0ada     MOV        dword ptr [ESP + param_1],EAX
//         004c0ade     JL         LAB_004c0a86
//                              sprite.cpp:746 (31)
//         004c0ae0     MOV        EDI,dword ptr [ESP + param_2]
//         004c0ae4     JMP        LAB_004c0aff
//                               LAB_004c0ae6                                                 XREF[2]:     004c0a6e(j), 004c0a75(j)
//         004c0ae6     MOV        EDX,dword ptr [ESP + param_6]
//         004c0aea     MOV        EAX,dword ptr [ESP + param_5]
//         004c0aee     PUSH       0x0
//         004c0af0     PUSH       0x0
//         004c0af2     PUSH       EDX
//         004c0af3     PUSH       EAX
//         004c0af4     PUSH       this
//         004c0af5     PUSH       EBX
//         004c0af6     PUSH       EDI
//         004c0af7     PUSH       EBP
//         004c0af8     MOV        this,ESI
//         004c0afa     CALL       RGE_Sprite::get_frame_min_max                    int get_frame_min_max(RGE_Sprite * this, shor
//                               LAB_004c0aff                                                 XREF[2]:     004c0a82(j), 004c0ae4(j)
//                              sprite.cpp:755 (29)
//         004c0aff     CMP        word ptr [EBP],0x0
//         004c0b04     JNZ        LAB_004c0b0c
//         004c0b06     CMP        word ptr [EBX],0x0
//         004c0b0a     JZ         LAB_004c0b1c
//                               LAB_004c0b0c                                                 XREF[1]:     004c0b04(j)
//         004c0b0c     CMP        word ptr [EDI],0x0
//         004c0b10     JNZ        LAB_004c0b48
//         004c0b12     MOV        this,dword ptr [ESP + param_4]
//         004c0b16     CMP        word ptr [this->pict_name[0]],0x0
//         004c0b1a     JNZ        LAB_004c0b48
//                               LAB_004c0b1c                                                 XREF[2]:     004c098e(j), 004c0b0a(j)
//                              sprite.cpp:758 (4)
//         004c0b1c     XOR        EAX,EAX
//         004c0b1e     JMP        LAB_004c0b4d
//                               LAB_004c0b20                                                 XREF[2]:     004c0a36(j), 004c0a40(j)
//                              sprite.cpp:733 (4)
//         004c0b20     MOV        EDX,dword ptr [ESP + param_1]
//                              sprite.cpp:734 (14)
//         004c0b24     MOV        this,dword ptr [ESP + param_2]
//         004c0b28     MOV        word ptr [EDX],AX
//         004c0b2b     MOV        AX,word ptr [ESI + 0x30]
//         004c0b2f     MOV        word ptr [this->pict_name[0]],AX
//                              sprite.cpp:735 (11)
//         004c0b32     MOV        EAX,dword ptr [ESP + param_3]
//         004c0b36     MOV        DX,word ptr [ESI + 0x32]
//         004c0b3a     MOV        word ptr [EAX],DX
//                              sprite.cpp:736 (11)
//         004c0b3d     MOV        EDX,dword ptr [ESP + param_4]
//         004c0b41     MOV        this,word ptr [ESI + 0x34]
//         004c0b45     MOV        word ptr [EDX],this
//                               LAB_004c0b48                                                 XREF[2]:     004c0b10(j), 004c0b1a(j)
//                              sprite.cpp:737 (5)
//         004c0b48     MOV        EAX,0x1
//                               LAB_004c0b4d                                                 XREF[1]:     004c0b1e(j)
//                              sprite.cpp:759 (21)
//         004c0b4d     MOV        this,dword ptr [ESP + local_c]
//         004c0b51     POP        EDI
//         004c0b52     POP        ESI
//         004c0b53     POP        EBP
//         004c0b54     MOV        dword ptr FS:[0x0],this
//         004c0b5b     POP        EBX
//         004c0b5c     ADD        ESP,0x14
//         004c0b5f     RET        0x18
//         004c0b62     ??         90h
//         004c0b63     NOP
//         004c0b64     NOP
//         004c0b65     NOP
//         004c0b66     NOP
//         004c0b67     NOP
//         004c0b68     NOP
//         004c0b69     NOP
//         004c0b6a     NOP
//         004c0b6b     NOP
//         004c0b6c     NOP
//         004c0b6d     NOP
//         004c0b6e     NOP
//         004c0b6f     NOP
    return 0;
}

int RGE_Sprite::get_frame_min_max(short* param_1, short* param_2, short* param_3, short* param_4, long param_5, long param_6, short param_7, short param_8) {
    /* TODO: Stub */
//                              int __thiscall get_frame_min_max(RGE_Sprite * this, short * param_1,
//              int               EAX:4          <RETURN>
//              RGE_Sprite *      ECX:4 (auto)   this
//              short *           Stack[0x4]:4   param_1                   XREF[1]:     004c0bfe(R)
//              short *           Stack[0x8]:4   param_2                   XREF[1]:     004c0c10(R)
//              short *           Stack[0xc]:4   param_3                   XREF[1]:     004c0c1e(R)
//              short *           Stack[0x10]:4  param_4                   XREF[1]:     004c0c2c(R)
//              long              Stack[0x14]:4  param_5                   XREF[4]:     004c0b8e(R), 004c0bb2(*), 004c0bd0(R), 004c0be4(R)
//              long              Stack[0x18]:4  param_6                   XREF[4]:     004c0b73(R), 004c0ba8(*), 004c0bd4(R), 004c0be0(R)
//              short             Stack[0x1c]:2  param_7                   XREF[1]:     004c0be8(R)
//              short             Stack[0x20]:2  param_8                   XREF[1]:     004c0bed(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     004c0ba3(*), 004c0bf6(R)
//              long              Stack[-0x8]:4  calc_max_y                XREF[2]:     004c0bad(*), 004c0bf2(R)
//              long              Stack[-0xc]:4  calc_min_y                XREF[2]:     004c0b86(*), 004c0b98(R)
//              long              Stack[-0x10]:4 facetindex
//                               ?get_frame_min_max@RGE_Sprite@@QAEHAAF000JJFF@Z              XREF[2]:     get_frame:004c0ac7(c),
//                               RGE_Sprite::get_frame_min_max                                             get_frame:004c0afa(c)
//                              sprite.cpp:763 (3)
//         004c0b70     SUB        ESP,0xc
//                              sprite.cpp:772 (17)
//         004c0b73     MOV        EAX,dword ptr [ESP + param_6]
//         004c0b77     PUSH       EBX
//         004c0b78     PUSH       ESI
//         004c0b79     MOV        ESI,this
//         004c0b7b     PUSH       EDI
//         004c0b7c     MOVSX      this,word ptr [ESI + 0x5e]
//         004c0b80     CMP        EAX,this
//         004c0b82     JL         LAB_004c0b86
//                              sprite.cpp:773 (2)
//         004c0b84     XOR        EAX,EAX
//                               LAB_004c0b86                                                 XREF[1]:     004c0b82(j)
//                              sprite.cpp:776 (18)
//         004c0b86     LEA        EDX=>calc_min_y,[ESP + 0xc]
//         004c0b8a     MOV        this,ESI
//         004c0b8c     PUSH       EDX
//         004c0b8d     PUSH       EAX
//         004c0b8e     MOV        EAX,dword ptr [ESP + param_5]
//         004c0b92     PUSH       EAX
//         004c0b93     CALL       RGE_Sprite::get_facetindex                       uchar get_facetindex(RGE_Sprite * this, long
//                              sprite.cpp:779 (43)
//         004c0b98     MOV        this,dword ptr [ESP + calc_min_y]
//         004c0b9c     AND        EAX,0xff
//         004c0ba1     MOV        EDI,EAX
//         004c0ba3     LEA        EDX=>local_4,[ESP + 0x14]
//         004c0ba7     PUSH       this
//         004c0ba8     LEA        EAX=>param_6,[ESP + 0x34]
//         004c0bac     PUSH       EDX
//         004c0bad     LEA        this=>calc_max_y,[ESP + 0x18]
//         004c0bb1     PUSH       EAX
//         004c0bb2     LEA        EDX=>param_5,[ESP + 0x38]
//         004c0bb6     PUSH       this
//         004c0bb7     PUSH       EDX
//         004c0bb8     MOV        this,ESI
//         004c0bba     CALL       RGE_Sprite::get_size                             int get_size(RGE_Sprite * this, long * param_
//         004c0bbf     TEST       EAX,EAX
//         004c0bc1     JNZ        LAB_004c0bcc
//                              sprite.cpp:803 (9)
//         004c0bc3     POP        EDI
//         004c0bc4     POP        ESI
//         004c0bc5     POP        EBX
//         004c0bc6     ADD        ESP,0xc
//         004c0bc9     RET        0x20
//                               LAB_004c0bcc                                                 XREF[1]:     004c0bc1(j)
//                              sprite.cpp:783 (4)
//         004c0bcc     TEST       EDI,EDI
//         004c0bce     JZ         LAB_004c0be0
//                              sprite.cpp:785 (4)
//         004c0bd0     MOV        this,dword ptr [ESP + param_5]
//                              sprite.cpp:786 (8)
//         004c0bd4     MOV        EAX,dword ptr [ESP + param_6]
//         004c0bd8     NEG        this
//         004c0bda     NEG        EAX
//                              sprite.cpp:787 (12)
//         004c0bdc     MOV        ESI,this
//         004c0bde     JMP        LAB_004c0be8
//                               LAB_004c0be0                                                 XREF[1]:     004c0bce(j)
//         004c0be0     MOV        ESI,dword ptr [ESP + param_6]
//         004c0be4     MOV        EAX,dword ptr [ESP + param_5]
//                               LAB_004c0be8                                                 XREF[1]:     004c0bde(j)
//                              sprite.cpp:791 (5)
//         004c0be8     MOVSX      this,word ptr [ESP + param_7]
//                              sprite.cpp:792 (9)
//         004c0bed     MOVSX      EDX,word ptr [ESP + param_8]
//         004c0bf2     MOV        EDI,dword ptr [ESP + calc_max_y]
//                              sprite.cpp:794 (8)
//         004c0bf6     MOV        EBX,dword ptr [ESP + local_4]
//         004c0bfa     ADD        EAX,this
//         004c0bfc     ADD        ESI,this
//                              sprite.cpp:797 (18)
//         004c0bfe     MOV        this,dword ptr [ESP + param_1]
//         004c0c02     ADD        EDI,EDX
//         004c0c04     ADD        EBX,EDX
//         004c0c06     MOVSX      EDX,word ptr [this->pict_name[0]]
//         004c0c09     CMP        EAX,EDX
//         004c0c0b     JGE        LAB_004c0c10
//         004c0c0d     MOV        word ptr [this->pict_name[0]],AX
//                               LAB_004c0c10                                                 XREF[1]:     004c0c0b(j)
//                              sprite.cpp:798 (14)
//         004c0c10     MOV        EAX,dword ptr [ESP + param_2]
//         004c0c14     MOVSX      this,word ptr [EAX]
//         004c0c17     CMP        EDI,this
//         004c0c19     JGE        LAB_004c0c1e
//         004c0c1b     MOV        word ptr [EAX],DI
//                               LAB_004c0c1e                                                 XREF[1]:     004c0c19(j)
//                              sprite.cpp:799 (14)
//         004c0c1e     MOV        EAX,dword ptr [ESP + param_3]
//         004c0c22     MOVSX      EDX,word ptr [EAX]
//         004c0c25     CMP        ESI,EDX
//         004c0c27     JLE        LAB_004c0c2c
//         004c0c29     MOV        word ptr [EAX],SI
//                               LAB_004c0c2c                                                 XREF[1]:     004c0c27(j)
//                              sprite.cpp:800 (14)
//         004c0c2c     MOV        EAX,dword ptr [ESP + param_4]
//         004c0c30     MOVSX      this,word ptr [EAX]
//         004c0c33     CMP        EBX,this
//         004c0c35     JLE        LAB_004c0c3a
//         004c0c37     MOV        word ptr [EAX],BX
//                               LAB_004c0c3a                                                 XREF[1]:     004c0c35(j)
//                              sprite.cpp:803 (14)
//         004c0c3a     POP        EDI
//         004c0c3b     POP        ESI
//         004c0c3c     MOV        EAX,0x1
//         004c0c41     POP        EBX
//         004c0c42     ADD        ESP,0xc
//         004c0c45     RET        0x20
//         004c0c48     ??         90h
//         004c0c49     NOP
//         004c0c4a     NOP
//         004c0c4b     NOP
//         004c0c4c     NOP
//         004c0c4d     NOP
//         004c0c4e     NOP
//         004c0c4f     NOP
    return 0;
}

uchar RGE_Sprite::get_lowest_draw_level() {
    /* TODO: Stub */
//                              uchar __thiscall get_lowest_draw_level(RGE_Sprite * this)
//              uchar             AL:1           <RETURN>
//              RGE_Sprite *      ECX:4 (auto)   this
//                               ?get_lowest_draw_level@RGE_Sprite@@QAEEXZ                    XREF[7]:     get_lowest_draw_level:0041afe7(c),
//                               RGE_Sprite::get_lowest_draw_level                                         key_down_action:0048a3aa(c),
//                                                                                                         key_down_action:004abbfa(c),
//                                                                                                         handle_scroll_view:0053a907(c),
//                                                                                                         mouse_left_down_action:0053e692(c)
//                                                                                                         mouse_left_up_action:0053ec7f(c),
//                                                                                                         command_place_object:0053f9c5(c)
//                              sprite.cpp:807 (1)
//         004c0c50     PUSH       ESI
//                              sprite.cpp:812 (9)
//         004c0c51     MOV        SI,word ptr [ECX + this->draw_list_num]
//         004c0c55     TEST       SI,SI
//         004c0c58     JNZ        LAB_004c0c5f
//                              sprite.cpp:813 (3)
//         004c0c5a     MOV        AL,byte ptr [ECX + this->draw_level]
//                              sprite.cpp:827 (2)
//         004c0c5d     POP        ESI
//         004c0c5e     RET
//                               LAB_004c0c5f                                                 XREF[1]:     004c0c58(j)
//                              sprite.cpp:818 (7)
//         004c0c5f     TEST       SI,SI
//         004c0c62     MOV        AL,0x14
//         004c0c64     JLE        LAB_004c0c80
//                              sprite.cpp:827 (18)
//         004c0c66     MOV        EDX,dword ptr [ECX + this->draw_list]
//         004c0c69     ADD        EDX,0x4
//         004c0c6c     MOVSX      ESI,SI
//                               LAB_004c0c6f                                                 XREF[1]:     004c0c7e(j)
//         004c0c6f     MOV        this,dword ptr [EDX]
//         004c0c71     MOV        this,byte ptr [ECX + this->draw_level]
//         004c0c74     CMP        this,AL
//         004c0c76     JNC        LAB_004c0c7a
//                              sprite.cpp:822 (2)
//         004c0c78     MOV        AL,this
//                               LAB_004c0c7a                                                 XREF[1]:     004c0c76(j)
//                              sprite.cpp:818 (6)
//         004c0c7a     ADD        EDX,0x10
//         004c0c7d     DEC        ESI
//         004c0c7e     JNZ        LAB_004c0c6f
//                               LAB_004c0c80                                                 XREF[1]:     004c0c64(j)
//                              sprite.cpp:827 (2)
//         004c0c80     POP        ESI
//         004c0c81     RET
//         004c0c82     ??         90h
//         004c0c83     NOP
//         004c0c84     NOP
//         004c0c85     NOP
//         004c0c86     NOP
//         004c0c87     NOP
//         004c0c88     NOP
//         004c0c89     NOP
//         004c0c8a     NOP
//         004c0c8b     NOP
//         004c0c8c     NOP
//         004c0c8d     NOP
//         004c0c8e     NOP
//         004c0c8f     NOP
    return 0;
}

uchar RGE_Sprite::hit_test(short param_1, short param_2, long param_3, long param_4) {
    /* TODO: Stub */
//                              uchar __thiscall hit_test(RGE_Sprite * this, short param_1, short pa
//              uchar             AL:1           <RETURN>
//              RGE_Sprite *      ECX:4 (auto)   this
//              short             Stack[0x4]:2   param_1                   XREF[2]:     004c0c98(R), 004c0d15(R)
//              short             Stack[0x8]:2   param_2                   XREF[2]:     004c0c94(R), 004c0d1f(R)
//              long              Stack[0xc]:4   param_3                   XREF[2]:     004c0d0d(R), 004c0d5f(R)
//              long              Stack[0x10]:4  param_4                   XREF[2]:     004c0cf9(R), 004c0d5b(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[3]:     004c0cf0(W), 004c0d33(R), 004c0d41(W)
//              long              Stack[-0x8]:4  index
//                               ?hit_test@RGE_Sprite@@QAEEFFJJ@Z                             XREF[2]:     hit_test:004c5ffc(c),
//                               RGE_Sprite::hit_test                                                      hit_test:004c6044(c)
//                              sprite.cpp:831 (4)
//         004c0c90     PUSH       this
//         004c0c91     PUSH       EBX
//         004c0c92     PUSH       EBP
//         004c0c93     PUSH       ESI
//                              sprite.cpp:835 (43)
//         004c0c94     MOV        EDX,dword ptr [ESP + param_2]
//         004c0c98     MOV        ESI,dword ptr [ESP + param_1]
//         004c0c9c     PUSH       EDI
//         004c0c9d     MOV        EDI,this
//         004c0c9f     XOR        EBX,EBX
//         004c0ca1     MOV        AX,word ptr [EDI + 0x2e]
//         004c0ca5     CMP        AX,BX
//         004c0ca8     JNZ        LAB_004c0cb0
//         004c0caa     CMP        word ptr [EDI + 0x32],BX
//         004c0cae     JZ         LAB_004c0cdf
//                               LAB_004c0cb0                                                 XREF[1]:     004c0ca8(j)
//         004c0cb0     MOV        this,word ptr [EDI + 0x30]
//         004c0cb4     CMP        this,BX
//         004c0cb7     JNZ        LAB_004c0cbf
//         004c0cb9     CMP        word ptr [EDI + 0x34],BX
//         004c0cbd     JZ         LAB_004c0cdf
//                               LAB_004c0cbf                                                 XREF[1]:     004c0cb7(j)
//                              sprite.cpp:836 (22)
//         004c0cbf     CMP        SI,AX
//         004c0cc2     JL         LAB_004c0cdf
//         004c0cc4     CMP        SI,word ptr [EDI + 0x32]
//         004c0cc8     JG         LAB_004c0cdf
//         004c0cca     CMP        DX,this
//         004c0ccd     JL         LAB_004c0cdf
//         004c0ccf     CMP        DX,word ptr [EDI + 0x34]
//         004c0cd3     JG         LAB_004c0cdf
//                              sprite.cpp:837 (2)
//         004c0cd5     MOV        AL,0x1
//                              sprite.cpp:850 (8)
//         004c0cd7     POP        EDI
//         004c0cd8     POP        ESI
//         004c0cd9     POP        EBP
//         004c0cda     POP        EBX
//         004c0cdb     POP        this
//         004c0cdc     RET        0x10
//                               LAB_004c0cdf                                                 XREF[6]:     004c0cae(j), 004c0cbd(j),
//                                                                                                         004c0cc2(j), 004c0cc8(j),
//                                                                                                         004c0ccd(j), 004c0cd3(j)
//                              sprite.cpp:839 (14)
//         004c0cdf     MOV        AX,word ptr [EDI + 0x36]
//         004c0ce3     CMP        AX,BX
//         004c0ce6     JLE        LAB_004c0d5b
//         004c0ce8     CMP        dword ptr [EDI + 0x38],EBX
//         004c0ceb     JZ         LAB_004c0d5b
//                              sprite.cpp:842 (9)
//         004c0ced     CMP        AX,BX
//         004c0cf0     MOV        dword ptr [ESP + local_4],EBX
//         004c0cf4     JLE        LAB_004c0d47
//                               LAB_004c0cf6                                                 XREF[1]:     004c0d45(j)
//                              sprite.cpp:845 (81)
//         004c0cf6     MOV        EAX,dword ptr [EDI + 0x38]
//         004c0cf9     MOV        EDX,dword ptr [ESP + param_4]
//         004c0cfd     MOVSX      EBP,word ptr [EDI + 0x60]
//         004c0d01     MOV        this,dword ptr [EAX + EBX*0x1 + 0x4]
//         004c0d05     LEA        ESI,[EAX + EBX*0x1]
//         004c0d08     PUSH       EDX
//         004c0d09     MOVSX      EAX,word ptr [ECX + this->facet_num]
//         004c0d0d     IMUL       EAX,dword ptr [ESP + param_3]
//         004c0d12     CDQ
//         004c0d13     IDIV       EBP
//         004c0d15     MOV        DX,word ptr [ESP + param_1]
//         004c0d1a     SUB        DX,word ptr [ESI + 0x8]
//         004c0d1e     PUSH       EAX
//         004c0d1f     MOV        AX,word ptr [ESP + param_2]
//         004c0d24     SUB        AX,word ptr [ESI + 0xa]
//         004c0d28     PUSH       EAX
//         004c0d29     PUSH       EDX
//         004c0d2a     CALL       RGE_Sprite::shape_hit_test                       uchar shape_hit_test(RGE_Sprite * this, short
//         004c0d2f     TEST       AL,AL
//         004c0d31     JNZ        LAB_004c0d51
//         004c0d33     MOV        EAX,dword ptr [ESP + local_4]
//         004c0d37     ADD        EBX,0x10
//         004c0d3a     MOVSX      this,word ptr [EDI + 0x36]
//         004c0d3e     INC        EAX
//         004c0d3f     CMP        EAX,this
//         004c0d41     MOV        dword ptr [ESP + local_4],EAX
//         004c0d45     JL         LAB_004c0cf6
//                               LAB_004c0d47                                                 XREF[1]:     004c0cf4(j)
//                              sprite.cpp:849 (2)
//         004c0d47     XOR        AL,AL
//                              sprite.cpp:850 (8)
//         004c0d49     POP        EDI
//         004c0d4a     POP        ESI
//         004c0d4b     POP        EBP
//         004c0d4c     POP        EBX
//         004c0d4d     POP        this
//         004c0d4e     RET        0x10
//                               LAB_004c0d51                                                 XREF[1]:     004c0d31(j)
//                              sprite.cpp:846 (2)
//         004c0d51     MOV        AL,0x1
//                              sprite.cpp:850 (8)
//         004c0d53     POP        EDI
//         004c0d54     POP        ESI
//         004c0d55     POP        EBP
//         004c0d56     POP        EBX
//         004c0d57     POP        this
//         004c0d58     RET        0x10
//                               LAB_004c0d5b                                                 XREF[2]:     004c0ce6(j), 004c0ceb(j)
//                              sprite.cpp:840 (19)
//         004c0d5b     MOV        EAX,dword ptr [ESP + param_4]
//         004c0d5f     MOV        this,dword ptr [ESP + param_3]
//         004c0d63     PUSH       EAX
//         004c0d64     PUSH       this
//         004c0d65     PUSH       EDX
//         004c0d66     PUSH       ESI
//         004c0d67     MOV        this,EDI
//         004c0d69     CALL       RGE_Sprite::shape_hit_test                       uchar shape_hit_test(RGE_Sprite * this, short
//                              sprite.cpp:850 (8)
//         004c0d6e     POP        EDI
//         004c0d6f     POP        ESI
//         004c0d70     POP        EBP
//         004c0d71     POP        EBX
//         004c0d72     POP        this
//         004c0d73     RET        0x10
//         004c0d76     ??         90h
//         004c0d77     NOP
//         004c0d78     NOP
//         004c0d79     NOP
//         004c0d7a     NOP
//         004c0d7b     NOP
//         004c0d7c     NOP
//         004c0d7d     NOP
//         004c0d7e     NOP
//         004c0d7f     NOP
    return 0;
}

uchar RGE_Sprite::shape_hit_test(short param_1, short param_2, long param_3, long param_4) {
    /* TODO: Stub */
//                              uchar __thiscall shape_hit_test(RGE_Sprite * this, short param_1, sh
//              uchar             AL:1           <RETURN>
//              RGE_Sprite *      ECX:4 (auto)   this
//              short             Stack[0x4]:2   param_1                   XREF[3]:     004c0eb1(R), 004c0f23(R), 004c0f4f(R)
//              short             Stack[0x8]:2   param_2                   XREF[3]:     004c0ee6(R), 004c0f1c(R), 004c0f48(R)
//              long              Stack[0xc]:4   param_3                   XREF[1]:     004c0e60(R)
//              long              Stack[0x10]:4  param_4                   XREF[1]:     004c0e4e(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     004c0df2(W), 004c0e1a(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[4]:     004c0ef9(R), 004c0f30(R), 004c0f5a(R), 004c0f6e(R)
//              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     004c0dec(W)
//              undefined4        Stack[-0x14]:4 local_14                  XREF[2]:     004c0e97(*), 004c0ef1(R)
//              long              Stack[-0x18]:4 ymax                      XREF[2]:     004c0ea2(*), 004c0eeb(R)
//              long              Stack[-0x1c]:4 ymin                      XREF[3]:     004c0e9c(*), 004c0eba(R), 004c0edc(R)
//              long              Stack[-0x20]:4 xmax                      XREF[3]:     004c0ea6(*), 004c0ec8(R), 004c0ed2(R)
//              long              Stack[-0x24]:4 xmin                      XREF[4]:     004c0e58(*), 004c0e93(R), 004c0f18(R), 004c0f44(R)
//              long              Stack[-0x28]:4 shape_num                 XREF[4]:     004c0db8(*), 004c0dbe(W), 004c0dff(R), 004c0e3d(R)
//              char *            Stack[-0x2c]:4 fname
//                               ?shape_hit_test@RGE_Sprite@@QAEEFFJJ@Z                       XREF[2]:     hit_test:004c0d2a(c),
//                               RGE_Sprite::shape_hit_test                                                hit_test:004c0d69(c)
//                              sprite.cpp:855 (29)
//         004c0d80     MOV        EAX,FS:[0x0]
//         004c0d86     PUSH       -0x1
//         004c0d88     PUSH       FUN_0055f95b
//         004c0d8d     PUSH       EAX
//         004c0d8e     MOV        dword ptr FS:[0x0],ESP
//         004c0d95     SUB        ESP,0x1c
//         004c0d98     PUSH       EBX
//         004c0d99     PUSH       ESI
//         004c0d9a     MOV        ESI,this
//         004c0d9c     PUSH       EDI
//                              sprite.cpp:864 (11)
//         004c0d9d     MOV        EAX,dword ptr [ESI + 0x1c]
//         004c0da0     TEST       EAX,EAX
//         004c0da2     JNZ        LAB_004c0e4a
//                              sprite.cpp:866 (11)
//         004c0da8     MOV        AL,byte ptr [ESI + 0x14]
//         004c0dab     TEST       AL,AL
//         004c0dad     JZ         LAB_004c0f6e
//                              sprite.cpp:869 (27)
//         004c0db3     PUSH       s_.shp                                           = ".shp"
//         004c0db8     LEA        EAX=>shape_num,[ESP + 0x10]
//         004c0dbc     PUSH       ESI
//         004c0dbd     PUSH       EAX
//         004c0dbe     MOV        dword ptr [ESP + shape_num],0x0
//         004c0dc6     CALL       addstring                                        void addstring(char * * param_1, char * param
//         004c0dcb     ADD        ESP,0xc
//                              sprite.cpp:870 (20)
//         004c0dce     PUSH       0x366
//         004c0dd3     PUSH       s_C:\msdev\work\age1_x1\sprite.cpp               = "C:\\msdev\\work\\age1_x1\\sprite.cpp"
//         004c0dd8     CALL       debug_timeGetTime                                ulong debug_timeGetTime(char * param_1, int p
//         004c0ddd     ADD        ESP,0x8
//         004c0de0     MOV        EDI,EAX
//                              sprite.cpp:871 (46)
//         004c0de2     PUSH       0x20
//         004c0de4     CALL       operator_new                                     void * operator_new(uint param_1)
//         004c0de9     ADD        ESP,0x4
//         004c0dec     MOV        dword ptr [ESP + local_10],EAX
//         004c0df0     TEST       EAX,EAX
//         004c0df2     MOV        dword ptr [ESP + local_4],0x0
//         004c0dfa     JZ         LAB_004c0e0e
//         004c0dfc     MOV        this,dword ptr [ESI + 0x10]
//         004c0dff     MOV        EDX,dword ptr [ESP + shape_num]
//         004c0e03     PUSH       this
//         004c0e04     PUSH       EDX
//         004c0e05     MOV        this,EAX
//         004c0e07     CALL       TShape::TShape                                   undefined TShape(TShape * this, char * param_
//         004c0e0c     JMP        LAB_004c0e10
//                               LAB_004c0e0e                                                 XREF[1]:     004c0dfa(j)
//         004c0e0e     XOR        EAX,EAX
//                               LAB_004c0e10                                                 XREF[1]:     004c0e0c(j)
//                              sprite.cpp:872 (45)
//         004c0e10     PUSH       0x368
//         004c0e15     PUSH       s_C:\msdev\work\age1_x1\sprite.cpp               = "C:\\msdev\\work\\age1_x1\\sprite.cpp"
//         004c0e1a     MOV        dword ptr [ESP + local_4],0xffffffff
//         004c0e22     MOV        dword ptr [ESI + 0x1c],EAX
//         004c0e25     CALL       debug_timeGetTime                                ulong debug_timeGetTime(char * param_1, int p
//         004c0e2a     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004c0e30     ADD        ESP,0x8
//         004c0e33     SUB        EAX,EDI
//         004c0e35     PUSH       EAX
//         004c0e36     PUSH       0xb
//         004c0e38     CALL       RGE_Base_Game::add_to_timing                     void add_to_timing(RGE_Base_Game * this, int
//                              sprite.cpp:873 (13)
//         004c0e3d     MOV        EAX,dword ptr [ESP + shape_num]
//         004c0e41     PUSH       EAX
//         004c0e42     CALL       free                                             undefined free()
//         004c0e47     ADD        ESP,0x4
//                               LAB_004c0e4a                                                 XREF[1]:     004c0da2(j)
//                              sprite.cpp:879 (12)
//         004c0e4a     MOVSX      this,word ptr [ESI + 0x5e]
//         004c0e4e     MOV        EAX,dword ptr [ESP + param_4]
//         004c0e52     CMP        EAX,this
//         004c0e54     JLE        LAB_004c0e58
//                              sprite.cpp:880 (2)
//         004c0e56     XOR        EAX,EAX
//                               LAB_004c0e58                                                 XREF[1]:     004c0e54(j)
//                              sprite.cpp:883 (20)
//         004c0e58     LEA        EDX=>xmin,[ESP + 0x10]
//         004c0e5c     MOV        this,ESI
//         004c0e5e     PUSH       EDX
//         004c0e5f     PUSH       EAX
//         004c0e60     MOV        EAX,dword ptr [ESP + param_3]
//         004c0e64     PUSH       EAX
//         004c0e65     CALL       RGE_Sprite::get_facetindex                       uchar get_facetindex(RGE_Sprite * this, long
//         004c0e6a     MOV        BL,AL
//                              sprite.cpp:886 (28)
//         004c0e6c     XOR        EAX,EAX
//         004c0e6e     MOV        AL,byte ptr [ESI + 0x2c]
//         004c0e71     SUB        EAX,0x0
//         004c0e74     JZ         LAB_004c0f6e
//         004c0e7a     DEC        EAX
//         004c0e7b     JZ         LAB_004c0f0d
//         004c0e81     DEC        EAX
//         004c0e82     JNZ        LAB_004c0f6e
//                              sprite.cpp:899 (11)
//         004c0e88     MOV        this,dword ptr [ESI + 0x1c]
//         004c0e8b     TEST       this,this
//         004c0e8d     JZ         LAB_004c0f6e
//                              sprite.cpp:901 (30)
//         004c0e93     MOV        EDX,dword ptr [ESP + xmin]
//         004c0e97     LEA        EAX=>local_14,[ESP + 0x20]
//         004c0e9b     PUSH       EDX
//         004c0e9c     LEA        EDX=>ymin,[ESP + 0x1c]
//         004c0ea0     PUSH       EAX
//         004c0ea1     PUSH       EDX
//         004c0ea2     LEA        EAX=>ymax,[ESP + 0x28]
//         004c0ea6     LEA        EDX=>xmax,[ESP + 0x20]
//         004c0eaa     PUSH       EAX
//         004c0eab     PUSH       EDX
//         004c0eac     CALL       TShape::shape_minmax                             uchar shape_minmax(TShape * this, long * para
//                              sprite.cpp:904 (31)
//         004c0eb1     MOVSX      EAX,word ptr [ESP + param_1]
//         004c0eb6     TEST       BL,BL
//         004c0eb8     JZ         LAB_004c0ed2
//         004c0eba     MOV        this,dword ptr [ESP + ymin]
//         004c0ebe     NEG        this
//         004c0ec0     CMP        EAX,this
//         004c0ec2     JL         LAB_004c0f6e
//         004c0ec8     MOV        EDX,dword ptr [ESP + xmax]
//         004c0ecc     NEG        EDX
//         004c0ece     CMP        EAX,EDX
//                              sprite.cpp:905 (2)
//         004c0ed0     JMP        LAB_004c0ee0
//                               LAB_004c0ed2                                                 XREF[1]:     004c0eb8(j)
//                              sprite.cpp:908 (37)
//         004c0ed2     CMP        EAX,dword ptr [ESP + xmax]
//         004c0ed6     JL         LAB_004c0f6e
//         004c0edc     CMP        EAX,dword ptr [ESP + ymin]
//                               LAB_004c0ee0                                                 XREF[1]:     004c0ed0(j)
//         004c0ee0     JG         LAB_004c0f6e
//         004c0ee6     MOVSX      EAX,word ptr [ESP + param_2]
//         004c0eeb     CMP        EAX,dword ptr [ESP + ymax]
//         004c0eef     JL         LAB_004c0f6e
//         004c0ef1     CMP        EAX,dword ptr [ESP + local_14]
//         004c0ef5     JG         LAB_004c0f6e
//                              sprite.cpp:909 (2)
//         004c0ef7     MOV        AL,0x1
//                              sprite.cpp:915 (20)
//         004c0ef9     MOV        this,dword ptr [ESP + local_c]
//         004c0efd     MOV        dword ptr FS:[0x0],this
//         004c0f04     POP        EDI
//         004c0f05     POP        ESI
//         004c0f06     POP        EBX
//         004c0f07     ADD        ESP,0x28
//         004c0f0a     RET        0x10
//                               LAB_004c0f0d                                                 XREF[1]:     004c0e7b(j)
//                              sprite.cpp:892 (7)
//         004c0f0d     MOV        this,dword ptr [ESI + 0x1c]
//         004c0f10     TEST       this,this
//         004c0f12     JZ         LAB_004c0f6e
//                              sprite.cpp:893 (4)
//         004c0f14     TEST       BL,BL
//         004c0f16     JZ         LAB_004c0f44
//                              sprite.cpp:894 (24)
//         004c0f18     MOV        EAX,dword ptr [ESP + xmin]
//         004c0f1c     MOVSX      EDX,word ptr [ESP + param_2]
//         004c0f21     PUSH       EAX
//         004c0f22     PUSH       EDX
//         004c0f23     MOVSX      EAX,word ptr [ESP + param_1]
//         004c0f28     NEG        EAX
//         004c0f2a     PUSH       EAX
//         004c0f2b     CALL       TShape::shape_check                              uchar shape_check(TShape * this, long param_1
//                              sprite.cpp:915 (20)
//         004c0f30     MOV        this,dword ptr [ESP + local_c]
//         004c0f34     MOV        dword ptr FS:[0x0],this
//         004c0f3b     POP        EDI
//         004c0f3c     POP        ESI
//         004c0f3d     POP        EBX
//         004c0f3e     ADD        ESP,0x28
//         004c0f41     RET        0x10
//                               LAB_004c0f44                                                 XREF[1]:     004c0f16(j)
//                              sprite.cpp:896 (22)
//         004c0f44     MOV        EDX,dword ptr [ESP + xmin]
//         004c0f48     MOVSX      EAX,word ptr [ESP + param_2]
//         004c0f4d     PUSH       EDX
//         004c0f4e     PUSH       EAX
//         004c0f4f     MOVSX      EDX,word ptr [ESP + param_1]
//         004c0f54     PUSH       EDX
//         004c0f55     CALL       TShape::shape_check                              uchar shape_check(TShape * this, long param_1
//                              sprite.cpp:915 (42)
//         004c0f5a     MOV        this,dword ptr [ESP + local_c]
//         004c0f5e     MOV        dword ptr FS:[0x0],this
//         004c0f65     POP        EDI
//         004c0f66     POP        ESI
//         004c0f67     POP        EBX
//         004c0f68     ADD        ESP,0x28
//         004c0f6b     RET        0x10
//                               LAB_004c0f6e                                                 XREF[10]:    004c0dad(j), 004c0e74(j),
//                                                                                                         004c0e82(j), 004c0e8d(j),
//                                                                                                         004c0ec2(j), 004c0ed6(j),
//                                                                                                         004c0ee0(j), 004c0eef(j),
//                                                                                                         004c0ef5(j), 004c0f12(j)
//         004c0f6e     MOV        this,dword ptr [ESP + local_c]
//         004c0f72     POP        EDI
//         004c0f73     POP        ESI
//         004c0f74     XOR        AL,AL
//         004c0f76     MOV        dword ptr FS:[0x0],this
//         004c0f7d     POP        EBX
//         004c0f7e     ADD        ESP,0x28
//         004c0f81     RET        0x10
//         004c0f84     ??         90h
//         004c0f85     NOP
//         004c0f86     NOP
//         004c0f87     NOP
//         004c0f88     NOP
//         004c0f89     NOP
//         004c0f8a     NOP
//         004c0f8b     NOP
//         004c0f8c     NOP
//         004c0f8d     NOP
//         004c0f8e     NOP
//         004c0f8f     NOP
    return 0;
}

RGE_Active_Sprite* RGE_Sprite::make_active_sprite() {
    /* TODO: Stub */
//                              RGE_Active_Sprite * __thiscall make_active_sprite(RGE_Sprite * this)
//              RGE_Active_Spr    EAX:4          <RETURN>
//              RGE_Sprite *      ECX:4 (auto)   this
//              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     004c0fbf(W), 004c0ff1(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[3]:     004c0fd1(R), 004c1003(R), 004c1013(R)
//              undefined4        Stack[-0x10]:4 local_10                  XREF[2]:     004c0fb9(W), 004c0feb(W)
//                               ?make_active_sprite@RGE_Sprite@@QAEPAVRGE_Active_Sprite@@XZ  XREF[1]:     add_sprite:0041a976(c)
//                               RGE_Sprite::make_active_sprite
//                              sprite.cpp:919 (25)
//         004c0f90     PUSH       -0x1
//         004c0f92     PUSH       FUN_0055f986
//         004c0f97     MOV        EAX,FS:[0x0]
//         004c0f9d     PUSH       EAX
//         004c0f9e     MOV        dword ptr FS:[0x0],ESP
//         004c0fa5     PUSH       this
//         004c0fa6     PUSH       ESI
//         004c0fa7     MOV        ESI,this
//                              sprite.cpp:920 (6)
//         004c0fa9     TEST       byte ptr [ESI + 0x70],0x1
//         004c0fad     JZ         LAB_004c0fe1
//                              sprite.cpp:921 (34)
//         004c0faf     PUSH       0x28
//         004c0fb1     CALL       operator_new                                     void * operator_new(uint param_1)
//         004c0fb6     ADD        ESP,0x4
//         004c0fb9     MOV        dword ptr [ESP + local_10],EAX
//         004c0fbd     TEST       EAX,EAX
//         004c0fbf     MOV        dword ptr [ESP + local_4],0x0
//         004c0fc7     JZ         LAB_004c1013
//         004c0fc9     PUSH       ESI
//         004c0fca     MOV        this,EAX
//         004c0fcc     CALL       RGE_Active_Animated_Sprite::RGE_Active_Animate   undefined RGE_Active_Animated_Sprite(RGE_Acti
//                              sprite.cpp:924 (16)
//         004c0fd1     MOV        this,dword ptr [ESP + local_c]
//         004c0fd5     MOV        dword ptr FS:[0x0],this
//         004c0fdc     POP        ESI
//         004c0fdd     ADD        ESP,0x10
//         004c0fe0     RET
//                               LAB_004c0fe1                                                 XREF[1]:     004c0fad(j)
//                              sprite.cpp:923 (34)
//         004c0fe1     PUSH       0x14
//         004c0fe3     CALL       operator_new                                     void * operator_new(uint param_1)
//         004c0fe8     ADD        ESP,0x4
//         004c0feb     MOV        dword ptr [ESP + local_10],EAX
//         004c0fef     TEST       EAX,EAX
//         004c0ff1     MOV        dword ptr [ESP + local_4],0x1
//         004c0ff9     JZ         LAB_004c1013
//         004c0ffb     PUSH       ESI
//         004c0ffc     MOV        this,EAX
//         004c0ffe     CALL       RGE_Active_Sprite::RGE_Active_Sprite             undefined RGE_Active_Sprite(RGE_Active_Sprite
//                              sprite.cpp:924 (34)
//         004c1003     MOV        this,dword ptr [ESP + local_c]
//         004c1007     MOV        dword ptr FS:[0x0],this
//         004c100e     POP        ESI
//         004c100f     ADD        ESP,0x10
//         004c1012     RET
//                               LAB_004c1013                                                 XREF[2]:     004c0fc7(j), 004c0ff9(j)
//         004c1013     MOV        this,dword ptr [ESP + local_c]
//         004c1017     XOR        EAX,EAX
//         004c1019     MOV        dword ptr FS:[0x0],this
//         004c1020     POP        ESI
//         004c1021     ADD        ESP,0x10
//         004c1024     RET
//         004c1025     ??         90h
//         004c1026     NOP
//         004c1027     NOP
//         004c1028     NOP
//         004c1029     NOP
//         004c102a     NOP
//         004c102b     NOP
//         004c102c     NOP
//         004c102d     NOP
//         004c102e     NOP
//         004c102f     NOP
    return 0;
}

int RGE_Sprite::check_for_shadows() {
    /* TODO: Stub */
//                              int __thiscall check_for_shadows(RGE_Sprite * this)
//              int               EAX:4          <RETURN>
//              RGE_Sprite *      ECX:4 (auto)   this
//                               ?check_for_shadows@RGE_Sprite@@QAEHXZ                        XREF[2]:     add_sprite:0041a920(c),
//                               RGE_Sprite::check_for_shadows                                             check_for_shadows:0041b007(c)
//                              sprite.cpp:930 (18)
//         004c1030     MOV        DX,word ptr [ECX + this->draw_list_num]
//         004c1034     PUSH       EBX
//         004c1035     TEST       DX,DX
//         004c1038     PUSH       ESI
//         004c1039     JLE        LAB_004c1064
//         004c103b     MOV        ESI,dword ptr [ECX + this->draw_list]
//         004c103e     TEST       ESI,ESI
//         004c1040     JZ         LAB_004c1064
//                              sprite.cpp:942 (9)
//         004c1042     MOVSX      EDX,DX
//         004c1045     XOR        EAX,EAX
//         004c1047     TEST       EDX,EDX
//         004c1049     JLE        LAB_004c1073
//                              sprite.cpp:951 (3)
//         004c104b     LEA        this,[ESI + 0x4]
//                               LAB_004c104e                                                 XREF[1]:     004c105d(j)
//                              sprite.cpp:945 (17)
//         004c104e     MOV        ESI,dword ptr [this->pict_name[0]]
//         004c1050     MOV        BL,byte ptr [ESI + 0x29]
//         004c1053     TEST       BL,BL
//         004c1055     JZ         LAB_004c106b
//         004c1057     INC        EAX
//         004c1058     ADD        this,0x10
//         004c105b     CMP        EAX,EDX
//         004c105d     JL         LAB_004c104e
//                              sprite.cpp:950 (2)
//         004c105f     XOR        EAX,EAX
//                              sprite.cpp:951 (3)
//         004c1061     POP        ESI
//         004c1062     POP        EBX
//         004c1063     RET
//                               LAB_004c1064                                                 XREF[2]:     004c1039(j), 004c1040(j)
//                              sprite.cpp:938 (7)
//         004c1064     MOV        AL,byte ptr [ECX + this->draw_level]
//         004c1067     TEST       AL,AL
//         004c1069     JNZ        LAB_004c1073
//                               LAB_004c106b                                                 XREF[1]:     004c1055(j)
//                              sprite.cpp:939 (5)
//         004c106b     MOV        EAX,0x1
//                              sprite.cpp:951 (8)
//         004c1070     POP        ESI
//         004c1071     POP        EBX
//         004c1072     RET
//                               LAB_004c1073                                                 XREF[2]:     004c1049(j), 004c1069(j)
//         004c1073     POP        ESI
//         004c1074     XOR        EAX,EAX
//         004c1076     POP        EBX
//         004c1077     RET
//         004c1078     ??         90h
//         004c1079     NOP
//         004c107a     NOP
//         004c107b     NOP
//         004c107c     NOP
//         004c107d     NOP
//         004c107e     NOP
//         004c107f     NOP
    return 0;
}

void RGE_Sprite::update(ulong param_1) {
    /* TODO: Stub */
//                              void __thiscall update(RGE_Sprite * this, ulong param_1)
//              void              <VOID>         <RETURN>
//              RGE_Sprite *      ECX:4 (auto)   this
//              ulong             Stack[0x4]:4   param_1                   XREF[1]:     004c10aa(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     004c1097(W), 004c109b(R)
//                               ?update@RGE_Sprite@@QAEXK@Z                                  XREF[1]:     update_sprites:00542eb5(c)
//                               RGE_Sprite::update
//                              sprite.cpp:955 (6)
//         004c1080     PUSH       this
//         004c1081     PUSH       EBX
//         004c1082     PUSH       ESI
//         004c1083     MOV        ESI,this
//         004c1085     PUSH       EDI
//                              sprite.cpp:956 (14)
//         004c1086     MOV        AL,byte ptr [ESI + 0x14]
//         004c1089     TEST       AL,AL
//         004c108b     JZ         LAB_004c10f4
//         004c108d     MOV        EDI,dword ptr [ESI + 0x1c]
//         004c1090     TEST       EDI,EDI
//         004c1092     JZ         LAB_004c10f4
//                              sprite.cpp:958 (22)
//         004c1094     MOV        this,dword ptr [ESI + 0x24]
//         004c1097     MOV        dword ptr [ESP + local_4],this
//         004c109b     FILD       dword ptr [ESP + local_4]
//         004c109f     FCOMP      double ptr [null_00574528]                       = align(8)
//         004c10a5     FNSTSW     AX
//         004c10a7     TEST       AH,0x40
//                              sprite.cpp:960 (9)
//         004c10aa     MOV        EAX,dword ptr [ESP + param_1]
//         004c10ae     JZ         LAB_004c10c1
//         004c10b0     MOV        dword ptr [ESI + 0x20],EAX
//                              sprite.cpp:961 (7)
//         004c10b3     MOV        dword ptr [ESI + 0x24],0x1
//                              sprite.cpp:975 (7)
//         004c10ba     POP        EDI
//         004c10bb     POP        ESI
//         004c10bc     POP        EBX
//         004c10bd     POP        this
//         004c10be     RET        0x4
//                               LAB_004c10c1                                                 XREF[1]:     004c10ae(j)
//                              sprite.cpp:965 (7)
//         004c10c1     MOV        EBX,dword ptr [ESI + 0x20]
//         004c10c4     MOV        EDX,EAX
//         004c10c6     SUB        EDX,EBX
//                              sprite.cpp:966 (5)
//         004c10c8     MOV        dword ptr [ESI + 0x20],EAX
//         004c10cb     ADD        EDX,this
//                              sprite.cpp:968 (12)
//         004c10cd     MOV        EAX,EDX
//         004c10cf     MOV        dword ptr [ESI + 0x24],EDX
//         004c10d2     CMP        EAX,0x2bf20
//         004c10d7     JL         LAB_004c10f4
//                              sprite.cpp:970 (20)
//         004c10d9     TEST       EDI,EDI
//         004c10db     JZ         LAB_004c10ed
//         004c10dd     MOV        this,EDI
//         004c10df     CALL       TShape::~TShape                                  void ~TShape(TShape * this)
//         004c10e4     PUSH       EDI
//         004c10e5     CALL       operator_delete                                  void operator_delete(void * param_1)
//         004c10ea     ADD        ESP,0x4
//                               LAB_004c10ed                                                 XREF[1]:     004c10db(j)
//                              sprite.cpp:971 (7)
//         004c10ed     MOV        dword ptr [ESI + 0x1c],0x0
//                               LAB_004c10f4                                                 XREF[3]:     004c108b(j), 004c1092(j),
//                                                                                                         004c10d7(j)
//                              sprite.cpp:975 (7)
//         004c10f4     POP        EDI
//         004c10f5     POP        ESI
//         004c10f6     POP        EBX
//         004c10f7     POP        this
//         004c10f8     RET        0x4
//         004c10fb     ??         90h
//         004c10fc     NOP
//         004c10fd     NOP
//         004c10fe     NOP
//         004c10ff     NOP
    return;
}

