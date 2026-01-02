#include "../common.h"
#include "mystring.h"

void convert_us(char* param_1) {
    /* TODO: Stub */
//                              void __cdecl convert_us(char * param_1)
//              void              <VOID>         <RETURN>
//              char *            Stack[0x4]:4   param_1                   XREF[1]:     00462d70(R)
//                               ?convert_us@@YAXPAD@Z                                        XREF[4]:     RGE_Effects:004493e1(c),
//                               convert_us                                                                load_terrain_types:0045817a(c),
//                                                                                                         load_border_types:004584f9(c),
//                                                                                                         RGE_Sprite:004bfad9(c)
//                              mystring.cpp:19 (10)
//         00462d70     MOV        ECX,dword ptr [ESP + param_1]
//         00462d74     MOV        AL,byte ptr [ECX]
//         00462d76     TEST       AL,AL
//         00462d78     JZ         LAB_00462d89
//                               LAB_00462d7a                                                 XREF[1]:     00462d87(j)
//                              mystring.cpp:21 (4)
//         00462d7a     CMP        AL,0x5f
//         00462d7c     JNZ        LAB_00462d81
//                              mystring.cpp:22 (3)
//         00462d7e     MOV        byte ptr [ECX],0x20
//                               LAB_00462d81                                                 XREF[1]:     00462d7c(j)
//                              mystring.cpp:20 (8)
//         00462d81     MOV        AL,byte ptr [ECX + 0x1]
//         00462d84     INC        ECX
//         00462d85     TEST       AL,AL
//         00462d87     JNZ        LAB_00462d7a
//                               LAB_00462d89                                                 XREF[1]:     00462d78(j)
//                              mystring.cpp:23 (1)
//         00462d89     RET
//         00462d8a     ??         90h
//         00462d8b     NOP
//         00462d8c     NOP
//         00462d8d     NOP
//         00462d8e     NOP
//         00462d8f     NOP
    return;
}

void unconvert_us(char* param_1) {
    /* TODO: Stub */
//                              void __cdecl unconvert_us(char * param_1)
//              void              <VOID>         <RETURN>
//              char *            Stack[0x4]:4   param_1                   XREF[1]:     00462d90(R)
//                               ?unconvert_us@@YAXPAD@Z
//                               unconvert_us
//                              mystring.cpp:27 (10)
//         00462d90     MOV        ECX,dword ptr [ESP + param_1]
//         00462d94     MOV        AL,byte ptr [ECX]
//         00462d96     TEST       AL,AL
//         00462d98     JZ         LAB_00462da9
//                               LAB_00462d9a                                                 XREF[1]:     00462da7(j)
//                              mystring.cpp:29 (4)
//         00462d9a     CMP        AL,0x20
//         00462d9c     JNZ        LAB_00462da1
//                              mystring.cpp:30 (3)
//         00462d9e     MOV        byte ptr [ECX],0x5f
//                               LAB_00462da1                                                 XREF[1]:     00462d9c(j)
//                              mystring.cpp:28 (8)
//         00462da1     MOV        AL,byte ptr [ECX + 0x1]
//         00462da4     INC        ECX
//         00462da5     TEST       AL,AL
//         00462da7     JNZ        LAB_00462d9a
//                               LAB_00462da9                                                 XREF[1]:     00462d98(j)
//                              mystring.cpp:31 (1)
//         00462da9     RET
//         00462daa     ??         90h
//         00462dab     NOP
//         00462dac     NOP
//         00462dad     NOP
//         00462dae     NOP
//         00462daf     NOP
    return;
}

void addstring(char** param_1, char* param_2, char* param_3) {
    /* TODO: Stub */
//                              void __cdecl addstring(char * * param_1, char * param_2, char * para
//              void              <VOID>         <RETURN>
//              char * *          Stack[0x4]:4   param_1                   XREF[1]:     00462e13(R)
//              char *            Stack[0x8]:4   param_2                   XREF[3]:     00462db3(R), 00462dd4(W), 00462df9(R)
//              char *            Stack[0xc]:4   param_3                   XREF[2]:     00462dc1(R), 00462dfd(R)
//                               ?addstring@@YAXPAPADPAD1@Z                                   XREF[21]:    RGE_Color_Table:004244a7(c),
//                               addstring                                                                 load_terrain_types:00457ef2(c),
//                                                                                                         load_border_types:004582c2(c),
//                                                                                                         add_description:0048ccf8(c),
//                                                                                                         load_campaign:0048ffc1(c),
//                                                                                                         load_campaign:0048ffe2(c),
//                                                                                                         load_campaign:00490017(c),
//                                                                                                         load_campaign:00490038(c),
//                                                                                                         make_campaign:0049017d(c),
//                                                                                                         make_campaign:0049024f(c),
//                                                                                                         Check_shape:004b8e80(c),
//                                                                                                         Check_shape:004b8eaa(c),
//                                                                                                         Check_shape:004b8ec1(c),
//                                                                                                         Check_shape:004b8ef8(c),
//                                                                                                         Check_shape:004b8f0f(c),
//                                                                                                         Check_shape:004b8f4a(c),
//                                                                                                         Check_shape:004b8f61(c),
//                                                                                                         do_draw:004c01f7(c),
//                                                                                                         get_size:004c0885(c),
//                                                                                                         get_frame:004c09a3(c), [more]
//                              mystring.cpp:35 (3)
//         00462db0     PUSH       EBX
//         00462db1     PUSH       EBP
//         00462db2     PUSH       ESI
//                              mystring.cpp:36 (14)
//         00462db3     MOV        ESI,dword ptr [ESP + param_2]
//         00462db7     PUSH       EDI
//         00462db8     MOV        EDI,ESI
//         00462dba     OR         ECX,0xffffffff
//         00462dbd     XOR        EAX,EAX
//         00462dbf     SCASB.RE   ES:EDI
//                              mystring.cpp:37 (4)
//         00462dc1     MOV        EDI,dword ptr [ESP + param_3]
//                              mystring.cpp:41 (29)
//         00462dc5     PUSH       0x1
//         00462dc7     NOT        ECX
//         00462dc9     DEC        ECX
//         00462dca     MOV        EBX,ECX
//         00462dcc     OR         ECX,0xffffffff
//         00462dcf     SCASB.RE   ES:EDI
//         00462dd1     NOT        ECX
//         00462dd3     DEC        ECX
//         00462dd4     MOV        dword ptr [ESP + param_2],ECX
//         00462dd8     LEA        EAX,[ECX + EBX*0x1 + 0x1]
//         00462ddc     PUSH       EAX
//         00462ddd     CALL       calloc                                           undefined calloc()
//                              mystring.cpp:43 (23)
//         00462de2     MOV        ECX,EBX
//         00462de4     MOV        EBP,EAX
//         00462de6     MOV        EDX,ECX
//         00462de8     MOV        EDI,EBP
//         00462dea     SHR        ECX,0x2
//         00462ded     MOVSD.REP  ES:EDI,ESI
//         00462def     MOV        ECX,EDX
//         00462df1     ADD        ESP,0x8
//         00462df4     AND        ECX,0x3
//         00462df7     MOVSB.REP  ES:EDI,ESI
//                              mystring.cpp:44 (26)
//         00462df9     MOV        ECX,dword ptr [ESP + param_2]
//         00462dfd     MOV        ESI,dword ptr [ESP + param_3]
//         00462e01     MOV        EAX,ECX
//         00462e03     LEA        EDI,[EBP + EBX*0x1]
//         00462e07     SHR        ECX,0x2
//         00462e0a     MOVSD.REP  ES:EDI,ESI
//         00462e0c     MOV        ECX,EAX
//         00462e0e     AND        ECX,0x3
//         00462e11     MOVSB.REP  ES:EDI,ESI
//                              mystring.cpp:46 (10)
//         00462e13     MOV        ESI,dword ptr [ESP + param_1]
//         00462e17     MOV        EAX,dword ptr [ESI]
//         00462e19     TEST       EAX,EAX
//         00462e1b     JZ         LAB_00462e26
//                              mystring.cpp:47 (9)
//         00462e1d     PUSH       EAX
//         00462e1e     CALL       free                                             undefined free()
//         00462e23     ADD        ESP,0x4
//                               LAB_00462e26                                                 XREF[1]:     00462e1b(j)
//                              mystring.cpp:48 (2)
//         00462e26     MOV        dword ptr [ESI],EBP
//                              mystring.cpp:49 (5)
//         00462e28     POP        EDI
//         00462e29     POP        ESI
//         00462e2a     POP        EBP
//         00462e2b     POP        EBX
//         00462e2c     RET
//         00462e2d     ??         90h
//         00462e2e     NOP
//         00462e2f     NOP
    return;
}

void getstring(char** param_1, char* param_2) {
    /* TODO: Stub */
//                              void __cdecl getstring(char * * param_1, char * param_2)
//              void              <VOID>         <RETURN>
//              char * *          Stack[0x4]:4   param_1                   XREF[1]:     00462e40(R)
//              char *            Stack[0x8]:4   param_2                   XREF[1]:     00462e32(R)
//                               ?getstring@@YAXPAPADPAD@Z                                    XREF[13]:    scenario_info:0042376e(c),
//                               getstring                                                                 get_scenario_list:0044cb66(c),
//                                                                                                         get_people_list:0044d891(c),
//                                                                                                         get_campaign_list:0044d901(c),
//                                                                                                         setup:004524bf(c),
//                                                                                                         setup:00452f85(c),
//                                                                                                         copy_obj:00453471(c),
//                                                                                                         RGE_Player:0046e80a(c),
//                                                                                                         add_description:0048cce6(c),
//                                                                                                         make_campaign:004901e0(c),
//                                                                                                         make_campaign:004901f6(c),
//                                                                                                         TRIBE_Tech:0050bd7e(c),
//                                                                                                         condition_description:00532e8a(c)
//                              mystring.cpp:53 (2)
//         00462e30     PUSH       EBX
//         00462e31     PUSH       ESI
//                              mystring.cpp:54 (14)
//         00462e32     MOV        ESI,dword ptr [ESP + param_2]
//         00462e36     PUSH       EDI
//         00462e37     MOV        EDI,ESI
//         00462e39     OR         ECX,0xffffffff
//         00462e3c     XOR        EAX,EAX
//         00462e3e     SCASB.RE   ES:EDI
//                              mystring.cpp:56 (16)
//         00462e40     MOV        EDI,dword ptr [ESP + param_1]
//         00462e44     NOT        ECX
//         00462e46     MOV        EAX,dword ptr [EDI]
//         00462e48     DEC        ECX
//         00462e49     MOV        EBX,ECX
//         00462e4b     INC        EBX
//         00462e4c     TEST       EAX,EAX
//         00462e4e     JZ         LAB_00462e59
//                              mystring.cpp:57 (9)
//         00462e50     PUSH       EAX
//         00462e51     CALL       free                                             undefined free()
//         00462e56     ADD        ESP,0x4
//                               LAB_00462e59                                                 XREF[1]:     00462e4e(j)
//                              mystring.cpp:59 (10)
//         00462e59     PUSH       0x1
//         00462e5b     PUSH       EBX
//         00462e5c     CALL       calloc                                           undefined calloc()
//         00462e61     MOV        dword ptr [EDI],EAX
//                              mystring.cpp:60 (21)
//         00462e63     MOV        ECX,EBX
//         00462e65     MOV        EDI,EAX
//         00462e67     MOV        EAX,ECX
//         00462e69     SHR        ECX,0x2
//         00462e6c     MOVSD.REP  ES:EDI,ESI
//         00462e6e     MOV        ECX,EAX
//         00462e70     ADD        ESP,0x8
//         00462e73     AND        ECX,0x3
//         00462e76     MOVSB.REP  ES:EDI,ESI
//                              mystring.cpp:61 (4)
//         00462e78     POP        EDI
//         00462e79     POP        ESI
//         00462e7a     POP        EBX
//         00462e7b     RET
//         00462e7c     ??         90h
//         00462e7d     NOP
//         00462e7e     NOP
//         00462e7f     NOP
    return;
}

