#include "../common.h"
#include "rge_fio.h"

int rge_fake_open(int param_1, int param_2) {
    /* TODO: Stub */
//                              int __cdecl rge_fake_open(int param_1, int param_2)
//              int               EAX:4          <RETURN>
//              int               Stack[0x4]:4   param_1                   XREF[1]:     0047fd31(R)
//              int               Stack[0x8]:4   param_2                   XREF[1]:     0047fd60(R)
//                               ?rge_fake_open@@YAHHH@Z                                      XREF[1]:     open_scenario:004236eb(c)
//                               rge_fake_open
//                              rge_fio.cpp:49 (1)
//         0047fd30     PUSH       ESI
//                              rge_fio.cpp:50 (8)
//         0047fd31     MOV        ESI,dword ptr [ESP + param_1]
//         0047fd35     TEST       ESI,ESI
//         0047fd37     JL         LAB_0047fd86
//                              rge_fio.cpp:55 (34)
//         0047fd39     PUSH       0x1
//         0047fd3b     PUSH       0x10000
//         0047fd40     MOV        byte ptr [DAT_0086b264],0x2
//         0047fd47     MOV        dword ptr [DAT_0086b268],0x0
//         0047fd51     CALL       calloc                                           undefined calloc()
//         0047fd56     MOV        [DAT_0086b270],EAX
//                              rge_fio.cpp:56 (5)
//         0047fd5b     MOV        [DAT_0086b278],EAX
//                              rge_fio.cpp:61 (38)
//         0047fd60     MOV        EAX,dword ptr [ESP + param_2]
//         0047fd64     ADD        ESP,0x8
//         0047fd67     MOV        dword ptr [DAT_0086b280],0x0
//         0047fd71     MOV        dword ptr [DAT_0086b26c],0x0
//         0047fd7b     MOV        dword ptr [DAT_0086b260],ESI
//         0047fd81     MOV        [DAT_0086b27c],EAX
//                               LAB_0047fd86                                                 XREF[1]:     0047fd37(j)
//                              rge_fio.cpp:64 (2)
//         0047fd86     MOV        EAX,ESI
//                              rge_fio.cpp:65 (2)
//         0047fd88     POP        ESI
//         0047fd89     RET
//         0047fd8a     ??         90h
//         0047fd8b     NOP
//         0047fd8c     NOP
//         0047fd8d     NOP
//         0047fd8e     NOP
//         0047fd8f     NOP
    return 0;
}

int rge_open(char* param_1, int param_2) {
    /* TODO: Stub */
//                              int __cdecl rge_open(char * param_1, int param_2, int param_3)
//              int               EAX:4          <RETURN>
//              char *            Stack[0x4]:4   param_1                   XREF[1]:     0047fe28(R)
//              int               Stack[0x8]:4   param_2                   XREF[1]:     0047fe24(R)
//              int               Stack[0xc]:4   param_3                   XREF[1]:     0047fe20(R)
//                               ?rge_open@@YAHPADHH@Z                                        XREF[7]:     save:0044d3fa(c),
//                               rge_open                                                                  save:0048d04f(c),
//                                                                                                         ~TribeInformationAIModule:004d7d3c
//                                                                                                         ~TribeInformationAIModule:004d8069
//                                                                                                         save_game:005437bd(c),
//                                                                                                         base_save:005439d3(c),
//                                                                                                         save_scenario:00543aa5(c)
//                              rge_fio.cpp:96 (24)
//         0047fe20     MOV        EAX,dword ptr [ESP + param_3]
//         0047fe24     MOV        ECX,dword ptr [ESP + param_2]
//         0047fe28     MOV        EDX,dword ptr [ESP + param_1]
//         0047fe2c     PUSH       ESI
//         0047fe2d     PUSH       EDI
//         0047fe2e     PUSH       EAX
//         0047fe2f     PUSH       ECX
//         0047fe30     PUSH       EDX
//         0047fe31     CALL       __open                                           undefined __open()
//         0047fe36     MOV        ESI,EAX
//                              rge_fio.cpp:101 (9)
//         0047fe38     XOR        EDI,EDI
//         0047fe3a     ADD        ESP,0xc
//         0047fe3d     CMP        ESI,EDI
//         0047fe3f     JL         LAB_0047fea4
//                              rge_fio.cpp:105 (33)
//         0047fe41     PUSH       0x1
//         0047fe43     PUSH       0x10000
//         0047fe48     MOV        byte ptr [DAT_0086b264],0x2
//         0047fe4f     MOV        dword ptr [DAT_0086b268],EDI
//         0047fe55     CALL       calloc                                           undefined calloc()
//         0047fe5a     ADD        ESP,0x8
//         0047fe5d     MOV        [DAT_0086b270],EAX
//                              rge_fio.cpp:106 (5)
//         0047fe62     MOV        [DAT_0086b278],EAX
//                              rge_fio.cpp:107 (6)
//         0047fe67     MOV        dword ptr [DAT_0086b280],EDI
//                              rge_fio.cpp:112 (24)
//         0047fe6d     PUSH       0x2
//         0047fe6f     PUSH       EDI
//         0047fe70     PUSH       ESI
//         0047fe71     MOV        dword ptr [DAT_0086b26c],EDI
//         0047fe77     MOV        dword ptr [DAT_0086b260],ESI
//         0047fe7d     CALL       lseek                                            undefined lseek()
//         0047fe82     ADD        ESP,0xc
//                              rge_fio.cpp:113 (14)
//         0047fe85     PUSH       ESI
//         0047fe86     CALL       __tell                                           undefined __tell()
//         0047fe8b     ADD        ESP,0x4
//         0047fe8e     MOV        [DAT_0086b27c],EAX
//                              rge_fio.cpp:114 (6)
//         0047fe93     MOV        dword ptr [DAT_0086b274],EDI
//                              rge_fio.cpp:115 (11)
//         0047fe99     PUSH       EDI
//         0047fe9a     PUSH       EDI
//         0047fe9b     PUSH       ESI
//         0047fe9c     CALL       lseek                                            undefined lseek()
//         0047fea1     ADD        ESP,0xc
//                               LAB_0047fea4                                                 XREF[1]:     0047fe3f(j)
//                              rge_fio.cpp:118 (2)
//         0047fea4     MOV        EAX,ESI
//                              rge_fio.cpp:119 (3)
//         0047fea6     POP        EDI
//         0047fea7     POP        ESI
//         0047fea8     RET
//         0047fea9     ??         90h
//         0047feaa     NOP
//         0047feab     NOP
//         0047feac     NOP
//         0047fead     NOP
//         0047feae     NOP
//         0047feaf     NOP
    return 0;
}

int rge_open(char* param_1, int param_2, int param_3) {
    /* TODO: Stub */
//                              int __cdecl rge_open(char * param_1, int param_2, int param_3)
//              int               EAX:4          <RETURN>
//              char *            Stack[0x4]:4   param_1                   XREF[1]:     0047fe28(R)
//              int               Stack[0x8]:4   param_2                   XREF[1]:     0047fe24(R)
//              int               Stack[0xc]:4   param_3                   XREF[1]:     0047fe20(R)
//                               ?rge_open@@YAHPADHH@Z                                        XREF[7]:     save:0044d3fa(c),
//                               rge_open                                                                  save:0048d04f(c),
//                                                                                                         ~TribeInformationAIModule:004d7d3c
//                                                                                                         ~TribeInformationAIModule:004d8069
//                                                                                                         save_game:005437bd(c),
//                                                                                                         base_save:005439d3(c),
//                                                                                                         save_scenario:00543aa5(c)
//                              rge_fio.cpp:96 (24)
//         0047fe20     MOV        EAX,dword ptr [ESP + param_3]
//         0047fe24     MOV        ECX,dword ptr [ESP + param_2]
//         0047fe28     MOV        EDX,dword ptr [ESP + param_1]
//         0047fe2c     PUSH       ESI
//         0047fe2d     PUSH       EDI
//         0047fe2e     PUSH       EAX
//         0047fe2f     PUSH       ECX
//         0047fe30     PUSH       EDX
//         0047fe31     CALL       __open                                           undefined __open()
//         0047fe36     MOV        ESI,EAX
//                              rge_fio.cpp:101 (9)
//         0047fe38     XOR        EDI,EDI
//         0047fe3a     ADD        ESP,0xc
//         0047fe3d     CMP        ESI,EDI
//         0047fe3f     JL         LAB_0047fea4
//                              rge_fio.cpp:105 (33)
//         0047fe41     PUSH       0x1
//         0047fe43     PUSH       0x10000
//         0047fe48     MOV        byte ptr [DAT_0086b264],0x2
//         0047fe4f     MOV        dword ptr [DAT_0086b268],EDI
//         0047fe55     CALL       calloc                                           undefined calloc()
//         0047fe5a     ADD        ESP,0x8
//         0047fe5d     MOV        [DAT_0086b270],EAX
//                              rge_fio.cpp:106 (5)
//         0047fe62     MOV        [DAT_0086b278],EAX
//                              rge_fio.cpp:107 (6)
//         0047fe67     MOV        dword ptr [DAT_0086b280],EDI
//                              rge_fio.cpp:112 (24)
//         0047fe6d     PUSH       0x2
//         0047fe6f     PUSH       EDI
//         0047fe70     PUSH       ESI
//         0047fe71     MOV        dword ptr [DAT_0086b26c],EDI
//         0047fe77     MOV        dword ptr [DAT_0086b260],ESI
//         0047fe7d     CALL       lseek                                            undefined lseek()
//         0047fe82     ADD        ESP,0xc
//                              rge_fio.cpp:113 (14)
//         0047fe85     PUSH       ESI
//         0047fe86     CALL       __tell                                           undefined __tell()
//         0047fe8b     ADD        ESP,0x4
//         0047fe8e     MOV        [DAT_0086b27c],EAX
//                              rge_fio.cpp:114 (6)
//         0047fe93     MOV        dword ptr [DAT_0086b274],EDI
//                              rge_fio.cpp:115 (11)
//         0047fe99     PUSH       EDI
//         0047fe9a     PUSH       EDI
//         0047fe9b     PUSH       ESI
//         0047fe9c     CALL       lseek                                            undefined lseek()
//         0047fea1     ADD        ESP,0xc
//                               LAB_0047fea4                                                 XREF[1]:     0047fe3f(j)
//                              rge_fio.cpp:118 (2)
//         0047fea4     MOV        EAX,ESI
//                              rge_fio.cpp:119 (3)
//         0047fea6     POP        EDI
//         0047fea7     POP        ESI
//         0047fea8     RET
//         0047fea9     ??         90h
//         0047feaa     NOP
//         0047feab     NOP
//         0047feac     NOP
//         0047fead     NOP
//         0047feae     NOP
//         0047feaf     NOP
    return 0;
}

int rge_fake_close(int param_1) {
    /* TODO: Stub */
//                              int __cdecl rge_fake_close(int param_1)
//              int               EAX:4          <RETURN>
//              int               Stack[0x4]:4   param_1                   XREF[1]:     0047feb1(R)
//                               ?rge_fake_close@@YAHH@Z
//                               rge_fake_close
//                              rge_fio.cpp:123 (1)
//         0047feb0     PUSH       EDI
//                              rge_fio.cpp:124 (16)
//         0047feb1     MOV        EDI,dword ptr [ESP + param_1]
//         0047feb5     TEST       EDI,EDI
//         0047feb7     JL         LAB_0047ff1f
//         0047feb9     CMP        EDI,dword ptr [DAT_0086b260]
//         0047febf     JNZ        LAB_0047ff1f
//                              rge_fio.cpp:126 (9)
//         0047fec1     MOV        EAX,[DAT_0086b270]
//         0047fec6     TEST       EAX,EAX
//         0047fec8     JZ         LAB_0047fedd
//                              rge_fio.cpp:128 (9)
//         0047feca     PUSH       EAX
//         0047fecb     CALL       free                                             undefined free()
//         0047fed0     ADD        ESP,0x4
//                              rge_fio.cpp:129 (10)
//         0047fed3     MOV        dword ptr [DAT_0086b270],0x0
//                               LAB_0047fedd                                                 XREF[1]:     0047fec8(j)
//                              rge_fio.cpp:132 (9)
//         0047fedd     MOV        EAX,[DAT_0086b26c]
//         0047fee2     TEST       EAX,EAX
//         0047fee4     JZ         LAB_0047fef9
//                              rge_fio.cpp:134 (9)
//         0047fee6     PUSH       EAX
//         0047fee7     CALL       free                                             undefined free()
//         0047feec     ADD        ESP,0x4
//                              rge_fio.cpp:135 (10)
//         0047feef     MOV        dword ptr [DAT_0086b26c],0x0
//                               LAB_0047fef9                                                 XREF[1]:     0047fee4(j)
//                              rge_fio.cpp:138 (9)
//         0047fef9     MOV        EAX,[DAT_0086b280]
//         0047fefe     TEST       EAX,EAX
//         0047ff00     JZ         LAB_0047ff15
//                              rge_fio.cpp:140 (9)
//         0047ff02     PUSH       EAX
//         0047ff03     CALL       free                                             undefined free()
//         0047ff08     ADD        ESP,0x4
//                              rge_fio.cpp:141 (10)
//         0047ff0b     MOV        dword ptr [DAT_0086b280],0x0
//                               LAB_0047ff15                                                 XREF[1]:     0047ff00(j)
//                              rge_fio.cpp:143 (10)
//         0047ff15     MOV        dword ptr [DAT_0086b260],0xffffffff
//                               LAB_0047ff1f                                                 XREF[2]:     0047feb7(j), 0047febf(j)
//                              rge_fio.cpp:146 (2)
//         0047ff1f     MOV        EAX,EDI
//                              rge_fio.cpp:147 (2)
//         0047ff21     POP        EDI
//         0047ff22     RET
//         0047ff23     ??         90h
//         0047ff24     NOP
//         0047ff25     NOP
//         0047ff26     NOP
//         0047ff27     NOP
//         0047ff28     NOP
//         0047ff29     NOP
//         0047ff2a     NOP
//         0047ff2b     NOP
//         0047ff2c     NOP
//         0047ff2d     NOP
//         0047ff2e     NOP
//         0047ff2f     NOP
    return 0;
}

int rge_close(int param_1) {
    /* TODO: Stub */
//                              int __cdecl rge_close(int param_1)
//              int               EAX:4          <RETURN>
//              int               Stack[0x4]:4   param_1                   XREF[1]:     0047ff31(R)
//                               ?rge_close@@YAHH@Z                                           XREF[37]:    get_scenario_info:0041cc34(c),
//                               rge_close                                                                 get_scenario_info:0041cc7d(c),
//                                                                                                         get_scenario_header:0041cd87(c),
//                                                                                                         RGE_Game_Info:0044d2b7(c),
//                                                                                                         RGE_Game_Info:0044d2c5(c),
//                                                                                                         save:0044d456(c),
//                                                                                                         RGE_Scenario_File_Info:0048cf6f(c)
//                                                                                                         RGE_Scenario_File_Info:0048cf8e(c)
//                                                                                                         save:0048d0cb(c),
//                                                                                                         reload_scenarios:0048d3d1(c),
//                                                                                                         ~TribeInformationAIModule:004d8029
//                                                                                                         ~TribeInformationAIModule:004d808b
//                                                                                                         loadUnitHistory:004e4583(c),
//                                                                                                         init:00541e2a(c),
//                                                                                                         init:00541e4e(c),
//                                                                                                         load_scenario5:00544eaf(c),
//                                                                                                         load_scenario5:00545119(c),
//                                                                                                         load_scenario6:005451df(c),
//                                                                                                         load_scenario6:00545449(c),
//                                                                                                         load_scenario7:0054550f(c), [more]
//                              rge_fio.cpp:151 (1)
//         0047ff30     PUSH       EDI
//                              rge_fio.cpp:152 (24)
//         0047ff31     MOV        EDI,dword ptr [ESP + param_1]
//         0047ff35     TEST       EDI,EDI
//         0047ff37     JL         LAB_0047fff0
//         0047ff3d     CMP        EDI,dword ptr [DAT_0086b260]
//         0047ff43     JNZ        LAB_0047fff0
//                              rge_fio.cpp:154 (18)
//         0047ff49     CMP        byte ptr [DAT_0086b264],0x1
//         0047ff50     JNZ        LAB_0047ff87
//         0047ff52     MOV        EAX,[DAT_0086b26c]
//         0047ff57     TEST       EAX,EAX
//         0047ff59     JZ         LAB_0047ff87
//                              rge_fio.cpp:156 (20)
//         0047ff5b     PUSH       0x1
//         0047ff5d     PUSH       0x0
//         0047ff5f     PUSH       0x0
//         0047ff61     PUSH       EAX
//         0047ff62     CALL       deflate_data                                     undefined deflate_data()
//         0047ff67     ADD        ESP,0x10
//         0047ff6a     CMP        EAX,0x2
//         0047ff6d     JNZ        LAB_0047ff79
//                              rge_fio.cpp:157 (10)
//         0047ff6f     MOV        dword ptr [rge_write_error],0x1
//                               LAB_0047ff79                                                 XREF[1]:     0047ff6d(j)
//                              rge_fio.cpp:158 (14)
//         0047ff79     MOV        EAX,[DAT_0086b26c]
//         0047ff7e     PUSH       EAX
//         0047ff7f     CALL       deflate_deinit                                   undefined deflate_deinit()
//         0047ff84     ADD        ESP,0x4
//                               LAB_0047ff87                                                 XREF[2]:     0047ff50(j), 0047ff59(j)
//                              rge_fio.cpp:166 (19)
//         0047ff87     MOV        EAX,[DAT_0086b270]
//         0047ff8c     MOV        dword ptr [DAT_0086b260],0xffffffff
//         0047ff96     TEST       EAX,EAX
//         0047ff98     JZ         LAB_0047ffad
//                              rge_fio.cpp:168 (9)
//         0047ff9a     PUSH       EAX
//         0047ff9b     CALL       free                                             undefined free()
//         0047ffa0     ADD        ESP,0x4
//                              rge_fio.cpp:169 (10)
//         0047ffa3     MOV        dword ptr [DAT_0086b270],0x0
//                               LAB_0047ffad                                                 XREF[1]:     0047ff98(j)
//                              rge_fio.cpp:172 (9)
//         0047ffad     MOV        EAX,[DAT_0086b26c]
//         0047ffb2     TEST       EAX,EAX
//         0047ffb4     JZ         LAB_0047ffc9
//                              rge_fio.cpp:174 (9)
//         0047ffb6     PUSH       EAX
//         0047ffb7     CALL       free                                             undefined free()
//         0047ffbc     ADD        ESP,0x4
//                              rge_fio.cpp:175 (10)
//         0047ffbf     MOV        dword ptr [DAT_0086b26c],0x0
//                               LAB_0047ffc9                                                 XREF[1]:     0047ffb4(j)
//                              rge_fio.cpp:178 (9)
//         0047ffc9     MOV        EAX,[DAT_0086b280]
//         0047ffce     TEST       EAX,EAX
//         0047ffd0     JZ         LAB_0047ffe5
//                              rge_fio.cpp:180 (9)
//         0047ffd2     PUSH       EAX
//         0047ffd3     CALL       free                                             undefined free()
//         0047ffd8     ADD        ESP,0x4
//                              rge_fio.cpp:181 (10)
//         0047ffdb     MOV        dword ptr [DAT_0086b280],0x0
//                               LAB_0047ffe5                                                 XREF[1]:     0047ffd0(j)
//                              rge_fio.cpp:184 (11)
//         0047ffe5     PUSH       EDI
//         0047ffe6     CALL       close                                            undefined close()
//         0047ffeb     ADD        ESP,0x4
//         0047ffee     MOV        EDI,EAX
//                               LAB_0047fff0                                                 XREF[2]:     0047ff37(j), 0047ff43(j)
//                              rge_fio.cpp:187 (2)
//         0047fff0     MOV        EAX,EDI
//                              rge_fio.cpp:188 (2)
//         0047fff2     POP        EDI
//         0047fff3     RET
//         0047fff4     ??         90h
//         0047fff5     NOP
//         0047fff6     NOP
//         0047fff7     NOP
//         0047fff8     NOP
//         0047fff9     NOP
//         0047fffa     NOP
//         0047fffb     NOP
//         0047fffc     NOP
//         0047fffd     NOP
//         0047fffe     NOP
//         0047ffff     NOP
    return 0;
}

void rge_read_uncompressed(int param_1, void* param_2, int param_3) {
    /* TODO: Stub */
//                              void __cdecl rge_read_uncompressed(int param_1, void * param_2, int
//              void              <VOID>         <RETURN>
//              int               Stack[0x4]:4   param_1                   XREF[1]:     00480000(R)
//              void *            Stack[0x8]:4   param_2                   XREF[1]:     00480010(R)
//              int               Stack[0xc]:4   param_3                   XREF[1]:     00480015(R)
//                               ?rge_read_uncompressed@@YAXHPAXH@Z                           XREF[33]:    get_scenario_info:0041cc04(c),
//                               rge_read_uncompressed                                                     get_scenario_info:0041cc14(c),
//                                                                                                         get_scenario_info:0041cc51(c),
//                                                                                                         get_scenario_header:0041cd24(c),
//                                                                                                         RGE_Scenario_Header:0048abdc(c),
//                                                                                                         RGE_Scenario_Header:0048abe8(c),
//                                                                                                         RGE_Scenario_Header:0048abfb(c),
//                                                                                                         RGE_Scenario_Header:0048ac0b(c),
//                                                                                                         RGE_Scenario_Header:0048ac43(c),
//                                                                                                         RGE_Scenario_File_Info:0048ceea(c)
//                                                                                                         RGE_Scenario_File_Info:0048cf26(c)
//                                                                                                         RGE_Scenario_File_Info:0048cf3f(c)
//                                                                                                         reload_scenarios:0048d3b9(c),
//                                                                                                         TRIBE_Scenario_Header:0052aa44(c),
//                                                                                                         TRIBE_Scenario_Header:0052aa50(c),
//                                                                                                         load_scenario5:00544e8f(c),
//                                                                                                         load_scenario5:00544ec8(c),
//                                                                                                         load_scenario6:005451bf(c),
//                                                                                                         load_scenario6:005451f8(c),
//                                                                                                         load_scenario7:005454ef(c), [more]
//                              rge_fio.cpp:194 (16)
//         00480000     MOV        EAX,dword ptr [ESP + param_1]
//         00480004     TEST       EAX,EAX
//         00480006     JL         LAB_00480031
//         00480008     CMP        EAX,dword ptr [DAT_0086b260]
//         0048000e     JNZ        LAB_00480031
//                              rge_fio.cpp:197 (17)
//         00480010     MOV        ECX,dword ptr [ESP + param_2]
//         00480014     PUSH       ESI
//         00480015     MOV        ESI,dword ptr [ESP + param_3]
//         00480019     PUSH       ESI
//         0048001a     PUSH       ECX
//         0048001b     PUSH       EAX
//         0048001c     CALL       read                                             undefined read()
//                              rge_fio.cpp:198 (16)
//         00480021     MOV        EAX,[DAT_0086b27c]
//         00480026     ADD        ESP,0xc
//         00480029     SUB        EAX,ESI
//         0048002b     MOV        [DAT_0086b27c],EAX
//         00480030     POP        ESI
//                               LAB_00480031                                                 XREF[2]:     00480006(j), 0048000e(j)
//                              rge_fio.cpp:202 (1)
//         00480031     RET
//         00480032     ??         90h
//         00480033     NOP
//         00480034     NOP
//         00480035     NOP
//         00480036     NOP
//         00480037     NOP
//         00480038     NOP
//         00480039     NOP
//         0048003a     NOP
//         0048003b     NOP
//         0048003c     NOP
//         0048003d     NOP
//         0048003e     NOP
//         0048003f     NOP
    return;
}

void rge_write_uncompressed(int param_1, void* param_2, int param_3) {
    /* TODO: Stub */
//                              void __cdecl rge_write_uncompressed(int param_1, void * param_2, int
//              void              <VOID>         <RETURN>
//              int               Stack[0x4]:4   param_1                   XREF[1]:     00480040(R)
//              void *            Stack[0x8]:4   param_2                   XREF[1]:     00480054(R)
//              int               Stack[0xc]:4   param_3                   XREF[1]:     00480050(R)
//                               ?rge_write_uncompressed@@YAXHPAXH@Z                          XREF[12]:    write_scenario_header:0041cdec(c),
//                               rge_write_uncompressed                                                    save:0048acdc(c),
//                                                                                                         save:0048aceb(c),
//                                                                                                         save:0048ad01(c),
//                                                                                                         save:0048ad2f(c),
//                                                                                                         save:0048ad45(c),
//                                                                                                         save:0048d06a(c),
//                                                                                                         save:0048d088(c),
//                                                                                                         save:0048d0a1(c),
//                                                                                                         save:0052aa95(c),
//                                                                                                         save:0052aaa4(c),
//                                                                                                         save_scenario:00543ae5(c)
//                              rge_fio.cpp:208 (16)
//         00480040     MOV        EAX,dword ptr [ESP + param_1]
//         00480044     TEST       EAX,EAX
//         00480046     JL         LAB_00480071
//         00480048     CMP        EAX,dword ptr [DAT_0086b260]
//         0048004e     JNZ        LAB_00480071
//                              rge_fio.cpp:211 (23)
//         00480050     MOV        ECX,dword ptr [ESP + param_3]
//         00480054     MOV        EDX,dword ptr [ESP + param_2]
//         00480058     PUSH       ECX
//         00480059     PUSH       EDX
//         0048005a     PUSH       EAX
//         0048005b     CALL       write                                            undefined write()
//         00480060     ADD        ESP,0xc
//         00480063     TEST       EAX,EAX
//         00480065     JG         LAB_00480071
//                              rge_fio.cpp:212 (10)
//         00480067     MOV        dword ptr [rge_write_error],0x1
//                               LAB_00480071                                                 XREF[3]:     00480046(j), 0048004e(j),
//                                                                                                         00480065(j)
//                              rge_fio.cpp:216 (1)
//         00480071     RET
//         00480072     ??         90h
//         00480073     NOP
//         00480074     NOP
//         00480075     NOP
//         00480076     NOP
//         00480077     NOP
//         00480078     NOP
//         00480079     NOP
//         0048007a     NOP
//         0048007b     NOP
//         0048007c     NOP
//         0048007d     NOP
//         0048007e     NOP
//         0048007f     NOP
    return;
}

void rge_read(int param_1, void* param_2, int param_3) {
    /* TODO: Stub */
//                              void __cdecl rge_read(int param_1, void * param_2, int param_3)
//              void              <VOID>         <RETURN>
//              int               Stack[0x4]:4   param_1                   XREF[4]:     00480096(R), 004800dd(R), 0048014c(W), 00480162(*)
//              void *            Stack[0x8]:4   param_2                   XREF[3]:     00480086(R), 00480090(W), 004801bf(R)
//              int               Stack[0xc]:4   param_3                   XREF[2]:     004800ae(R), 0048019c(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     00480148(*), 00480175(W)
//              int               Stack[-0x8]:4  temp_max
//                               ?rge_read@@YAXHPAXH@Z                                        XREF[1083]:  load:00403ef1(c),
//                               rge_read                                                                  setup:00407557(c),
//                                                                                                         setup:00407567(c),
//                                                                                                         setup:00407588(c),
//                                                                                                         setup:004075a8(c),
//                                                                                                         setup:004075b7(c),
//                                                                                                         setup:004075c6(c),
//                                                                                                         setup:004075d5(c),
//                                                                                                         setup:004075e4(c),
//                                                                                                         setup:004075f3(c),
//                                                                                                         setup:00407603(c),
//                                                                                                         setup:00407639(c),
//                                                                                                         setup:00407652(c),
//                                                                                                         RGE_Sound:004bbf56(c),
//                                                                                                         RGE_Sound:004bbf62(c),
//                                                                                                         RGE_Sound:004bbf71(c),
//                                                                                                         RGE_Sound:004bbf80(c),
//                                                                                                         RGE_Sound:004bbfbb(c),
//                                                                                                         RGE_Sound:004bbfce(c),
//                                                                                                         TRIBE_Action_Discovery_Artifact:00
//                                                                                                         [more]
//                              rge_fio.cpp:222 (1)
//         00480080     PUSH       ECX
//                              rge_fio.cpp:230 (21)
//         00480081     MOV        EAX,[ENABLE_COMPRESSION]                         = 1h
//         00480086     MOV        ECX,dword ptr [ESP + param_2]
//         0048008a     PUSH       EBX
//         0048008b     PUSH       EBP
//         0048008c     PUSH       ESI
//         0048008d     PUSH       EDI
//         0048008e     TEST       EAX,EAX
//         00480090     MOV        dword ptr [ESP + param_2],ECX
//         00480094     JNZ        LAB_004800dd
//                              rge_fio.cpp:232 (24)
//         00480096     MOV        EAX,dword ptr [ESP + param_1]
//         0048009a     TEST       EAX,EAX
//         0048009c     JL         LAB_00480285
//         004800a2     CMP        EAX,dword ptr [DAT_0086b260]
//         004800a8     JNZ        LAB_00480285
//                              rge_fio.cpp:234 (12)
//         004800ae     MOV        ESI,dword ptr [ESP + param_3]
//         004800b2     PUSH       ESI
//         004800b3     PUSH       ECX
//         004800b4     PUSH       EAX
//         004800b5     CALL       read                                             undefined read()
//                              rge_fio.cpp:235 (6)
//         004800ba     MOV        ECX,dword ptr [DAT_0086b27c]
//                              rge_fio.cpp:236 (23)
//         004800c0     MOV        EAX,[DAT_0086b274]
//         004800c5     ADD        ESP,0xc
//         004800c8     SUB        ECX,ESI
//         004800ca     ADD        EAX,ESI
//         004800cc     MOV        dword ptr [DAT_0086b27c],ECX
//         004800d2     MOV        [DAT_0086b274],EAX
//                              rge_fio.cpp:306 (6)
//         004800d7     POP        EDI
//         004800d8     POP        ESI
//         004800d9     POP        EBP
//         004800da     POP        EBX
//         004800db     POP        ECX
//         004800dc     RET
//                               LAB_004800dd                                                 XREF[1]:     00480094(j)
//                              rge_fio.cpp:248 (24)
//         004800dd     MOV        ESI,dword ptr [ESP + param_1]
//         004800e1     TEST       ESI,ESI
//         004800e3     JL         LAB_00480285
//         004800e9     CMP        ESI,dword ptr [DAT_0086b260]
//         004800ef     JNZ        LAB_00480285
//                              rge_fio.cpp:250 (13)
//         004800f5     MOV        AL,[DAT_0086b264]
//         004800fa     TEST       AL,AL
//         004800fc     JZ         LAB_0048019c
//                              rge_fio.cpp:252 (5)
//         00480102     CALL       _Inf32BufSize                                    undefined _Inf32BufSize()
//                              rge_fio.cpp:253 (16)
//         00480107     PUSH       0x1
//         00480109     PUSH       EAX
//         0048010a     CALL       calloc                                           undefined calloc()
//         0048010f     ADD        ESP,0x8
//         00480112     MOV        [DAT_0086b26c],EAX
//                              rge_fio.cpp:256 (13)
//         00480117     MOV        EAX,[DAT_0086b27c]
//         0048011c     PUSH       0x1
//         0048011e     PUSH       EAX
//         0048011f     CALL       calloc                                           undefined calloc()
//                              rge_fio.cpp:257 (22)
//         00480124     MOV        ECX,dword ptr [DAT_0086b27c]
//         0048012a     ADD        ESP,0x8
//         0048012d     MOV        [DAT_0086b280],EAX
//         00480132     PUSH       ECX
//         00480133     PUSH       EAX
//         00480134     PUSH       ESI
//         00480135     CALL       read                                             undefined read()
//                              rge_fio.cpp:260 (6)
//         0048013a     MOV        EDX,dword ptr [DAT_0086b27c]
//                              rge_fio.cpp:266 (66)
//         00480140     MOV        EAX,[DAT_0086b26c]
//         00480145     ADD        ESP,0xc
//         00480148     LEA        ECX=>local_4,[ESP + 0x10]
//         0048014c     MOV        dword ptr [ESP + param_1],EDX
//         00480150     MOV        EDX,dword ptr [DAT_0086b270]
//         00480156     PUSH       0x1
//         00480158     PUSH       EAX
//         00480159     PUSH       ECX
//         0048015a     MOV        ECX,dword ptr [DAT_0086b280]
//         00480160     PUSH       0x0
//         00480162     LEA        EAX=>param_1,[ESP + 0x28]
//         00480166     PUSH       EDX
//         00480167     PUSH       EAX
//         00480168     PUSH       0x0
//         0048016a     PUSH       ECX
//         0048016b     MOV        dword ptr [DAT_0086b25c],0x0
//         00480175     MOV        dword ptr [ESP + local_4],0x10000
//         0048017d     CALL       _Inf32Decode                                     undefined _Inf32Decode()
//                              rge_fio.cpp:268 (19)
//         00480182     MOV        EDX,dword ptr [ESP + 0x38]
//         00480186     MOV        EAX,[DAT_0086b25c]
//         0048018b     ADD        ESP,0x20
//         0048018e     ADD        EAX,EDX
//         00480190     MOV        [DAT_0086b25c],EAX
//                              rge_fio.cpp:270 (7)
//         00480195     MOV        byte ptr [DAT_0086b264],0x0
//                               LAB_0048019c                                                 XREF[1]:     004800fc(j)
//                              rge_fio.cpp:274 (35)
//         0048019c     MOV        EBX,dword ptr [ESP + param_3]
//         004801a0     MOV        EAX,[DAT_0086b268]
//         004801a5     MOV        ESI,dword ptr [DAT_0086b278]
//         004801ab     LEA        ECX,[EBX + EAX*0x1]
//         004801ae     CMP        ECX,0x10000
//         004801b4     JL         LAB_00480253
//                               LAB_004801ba                                                 XREF[1]:     0048024d(j)
//         004801ba     MOV        EBP,0x10000
//                              rge_fio.cpp:277 (6)
//         004801bf     MOV        EDI,dword ptr [ESP + param_2]
//         004801c3     SUB        EBP,EAX
//                              rge_fio.cpp:286 (78)
//         004801c5     PUSH       0x1
//         004801c7     MOV        ECX,EBP
//         004801c9     MOV        EDX,ECX
//         004801cb     SHR        ECX,0x2
//         004801ce     MOVSD.REP  ES:EDI,ESI
//         004801d0     MOV        ECX,EDX
//         004801d2     LEA        EDX,[ESP + 0x14]
//         004801d6     AND        ECX,0x3
//         004801d9     MOVSB.REP  ES:EDI,ESI
//         004801db     MOV        EAX,[DAT_0086b27c]
//         004801e0     MOV        ECX,dword ptr [DAT_0086b26c]
//         004801e6     MOV        dword ptr [ESP + 0x1c],EAX
//         004801ea     MOV        EAX,[DAT_0086b270]
//         004801ef     PUSH       ECX
//         004801f0     PUSH       EDX
//         004801f1     MOV        EDX,dword ptr [DAT_0086b25c]
//         004801f7     PUSH       0x0
//         004801f9     LEA        ECX,[ESP + 0x28]
//         004801fd     PUSH       EAX
//         004801fe     MOV        EAX,[DAT_0086b280]
//         00480203     PUSH       ECX
//         00480204     PUSH       EDX
//         00480205     PUSH       EAX
//         00480206     MOV        dword ptr [ESP + 0x30],0x10000
//         0048020e     CALL       _Inf32Decode                                     undefined _Inf32Decode()
//                              rge_fio.cpp:288 (10)
//         00480213     MOV        ECX,dword ptr [ESP + 0x38]
//         00480217     MOV        EDI,dword ptr [DAT_0086b25c]
//                              rge_fio.cpp:292 (4)
//         0048021d     MOV        EDX,dword ptr [ESP + 0x3c]
//                              rge_fio.cpp:293 (50)
//         00480221     MOV        ESI,dword ptr [DAT_0086b270]
//         00480227     SUB        EBX,EBP
//         00480229     ADD        ESP,0x20
//         0048022c     ADD        EDI,ECX
//         0048022e     XOR        EAX,EAX
//         00480230     ADD        EDX,EBP
//         00480232     CMP        EBX,0x10000
//         00480238     MOV        dword ptr [DAT_0086b25c],EDI
//         0048023e     MOV        [DAT_0086b268],EAX
//         00480243     MOV        dword ptr [ESP + 0x1c],EDX
//         00480247     MOV        dword ptr [DAT_0086b278],ESI
//         0048024d     JGE        LAB_004801ba
//                               LAB_00480253                                                 XREF[1]:     004801b4(j)
//                              rge_fio.cpp:297 (4)
//         00480253     TEST       EBX,EBX
//         00480255     JLE        LAB_00480285
//                              rge_fio.cpp:299 (20)
//         00480257     MOV        EDI,dword ptr [ESP + 0x1c]
//         0048025b     MOV        ECX,EBX
//         0048025d     MOV        EDX,ECX
//         0048025f     SHR        ECX,0x2
//         00480262     MOVSD.REP  ES:EDI,ESI
//         00480264     MOV        ECX,EDX
//         00480266     AND        ECX,0x3
//         00480269     MOVSB.REP  ES:EDI,ESI
//                              rge_fio.cpp:300 (6)
//         0048026b     MOV        ECX,dword ptr [DAT_0086b268]
//                              rge_fio.cpp:301 (20)
//         00480271     MOV        EAX,[DAT_0086b278]
//         00480276     ADD        ECX,EBX
//         00480278     ADD        EAX,EBX
//         0048027a     MOV        dword ptr [DAT_0086b268],ECX
//         00480280     MOV        [DAT_0086b278],EAX
//                               LAB_00480285                                                 XREF[5]:     0048009c(j), 004800a8(j),
//                                                                                                         004800e3(j), 004800ef(j),
//                                                                                                         00480255(j)
//                              rge_fio.cpp:306 (6)
//         00480285     POP        EDI
//         00480286     POP        ESI
//         00480287     POP        EBP
//         00480288     POP        EBX
//         00480289     POP        ECX
//         0048028a     RET
//         0048028b     ??         90h
//         0048028c     NOP
//         0048028d     NOP
//         0048028e     NOP
//         0048028f     NOP
    return;
}

int rge_buffer_full(uchar* param_1, int param_2) {
    /* TODO: Stub */
//                              int __cdecl rge_buffer_full(uchar * param_1, int param_2)
//              int               EAX:4          <RETURN>
//              uchar *           Stack[0x4]:4   param_1                   XREF[1]:     00480294(R)
//              int               Stack[0x8]:4   param_2                   XREF[1]:     00480290(R)
//                               ?rge_buffer_full@@YAHPAEH@Z                                  XREF[1]:     rge_write:0048033e(*)
//                               rge_buffer_full
//                              rge_fio.cpp:310 (29)
//         00480290     MOV        EAX,dword ptr [ESP + param_2]
//         00480294     MOV        ECX,dword ptr [ESP + param_1]
//         00480298     MOV        EDX,dword ptr [DAT_0086b260]
//         0048029e     PUSH       EAX
//         0048029f     PUSH       ECX
//         004802a0     PUSH       EDX
//         004802a1     CALL       write                                            undefined write()
//         004802a6     ADD        ESP,0xc
//         004802a9     TEST       EAX,EAX
//         004802ab     JG         LAB_004802b7
//                              rge_fio.cpp:313 (10)
//         004802ad     MOV        dword ptr [rge_write_error],0x1
//                               LAB_004802b7                                                 XREF[1]:     004802ab(j)
//                              rge_fio.cpp:318 (2)
//         004802b7     XOR        EAX,EAX
//                              rge_fio.cpp:320 (1)
//         004802b9     RET
//         004802ba     ??         90h
//         004802bb     NOP
//         004802bc     NOP
//         004802bd     NOP
//         004802be     NOP
//         004802bf     NOP
    return 0;
}

void rge_write(int param_1, void* param_2, int param_3) {
    /* TODO: Stub */
//                              void __cdecl rge_write(int param_1, void * param_2, int param_3)
//              void              <VOID>         <RETURN>
//              int               Stack[0x4]:4   param_1                   XREF[1]:     004802c7(R)
//              void *            Stack[0x8]:4   param_2                   XREF[2]:     004802e5(R), 0048035c(R)
//              int               Stack[0xc]:4   param_3                   XREF[2]:     004802e1(R), 00480358(R)
//                               ?rge_write@@YAXHPAXH@Z                                       XREF[974]:   save:0040d0bb(c),
//                               rge_write                                                                 save:0040d156(c),
//                                                                                                         Save:0046e031(c),
//                                                                                                         Save:0046e040(c),
//                                                                                                         Save:0046e04f(c),
//                                                                                                         Save:0046e05e(c),
//                                                                                                         Save:0046e07c(c),
//                                                                                                         Save:0046e095(c),
//                                                                                                         save:004d8502(c),
//                                                                                                         save:004e5e54(c),
//                                                                                                         save:004e5e66(c),
//                                                                                                         save:004e5e78(c),
//                                                                                                         save:004e5e8a(c),
//                                                                                                         save:004e5e9c(c),
//                                                                                                         save:004e5eae(c),
//                                                                                                         save:004e5ec0(c),
//                                                                                                         save:004e5ed2(c),
//                                                                                                         save:004e5ee4(c),
//                                                                                                         save:004e5ef6(c),
//                                                                                                         save:004e5f08(c), [more]
//                              rge_fio.cpp:326 (7)
//         004802c0     MOV        EAX,[ENABLE_COMPRESSION]                         = 1h
//         004802c5     TEST       EAX,EAX
//                              rge_fio.cpp:332 (26)
//         004802c7     MOV        EAX,dword ptr [ESP + param_1]
//         004802cb     JNZ        LAB_00480307
//         004802cd     TEST       EAX,EAX
//         004802cf     JL         LAB_00480382
//         004802d5     CMP        EAX,dword ptr [DAT_0086b260]
//         004802db     JNZ        LAB_00480382
//                              rge_fio.cpp:334 (27)
//         004802e1     MOV        ECX,dword ptr [ESP + param_3]
//         004802e5     MOV        EDX,dword ptr [ESP + param_2]
//         004802e9     PUSH       ECX
//         004802ea     PUSH       EDX
//         004802eb     PUSH       EAX
//         004802ec     CALL       write                                            undefined write()
//         004802f1     ADD        ESP,0xc
//         004802f4     TEST       EAX,EAX
//         004802f6     JG         LAB_00480382
//                              rge_fio.cpp:356 (10)
//         004802fc     MOV        dword ptr [rge_write_error],0x1
//                              rge_fio.cpp:360 (1)
//         00480306     RET
//                               LAB_00480307                                                 XREF[1]:     004802cb(j)
//                              rge_fio.cpp:343 (12)
//         00480307     TEST       EAX,EAX
//         00480309     JL         LAB_00480382
//         0048030b     CMP        EAX,dword ptr [DAT_0086b260]
//         00480311     JNZ        LAB_00480382
//                              rge_fio.cpp:345 (9)
//         00480313     CMP        byte ptr [DAT_0086b264],0x1
//         0048031a     JZ         LAB_00480358
//                              rge_fio.cpp:347 (7)
//         0048031c     MOV        byte ptr [DAT_0086b264],0x1
//                              rge_fio.cpp:349 (5)
//         00480323     CALL       deflate_buf_size                                 undefined deflate_buf_size()
//                              rge_fio.cpp:350 (8)
//         00480328     PUSH       0x1
//         0048032a     PUSH       EAX
//         0048032b     CALL       calloc                                           undefined calloc()
//                              rge_fio.cpp:352 (40)
//         00480330     MOV        ECX,dword ptr [DAT_0086b270]
//         00480336     ADD        ESP,0x8
//         00480339     MOV        [DAT_0086b26c],EAX
//         0048033e     PUSH       rge_buffer_full
//         00480343     PUSH       0x10000
//         00480348     PUSH       ECX
//         00480349     PUSH       0x1
//         0048034b     PUSH       0x2
//         0048034d     PUSH       0x4b
//         0048034f     PUSH       EAX
//         00480350     CALL       deflate_init                                     undefined deflate_init()
//         00480355     ADD        ESP,0x1c
//                               LAB_00480358                                                 XREF[1]:     0048031a(j)
//                              rge_fio.cpp:355 (32)
//         00480358     MOV        EDX,dword ptr [ESP + param_3]
//         0048035c     MOV        EAX,dword ptr [ESP + param_2]
//         00480360     MOV        ECX,dword ptr [DAT_0086b26c]
//         00480366     PUSH       0x0
//         00480368     PUSH       EDX
//         00480369     PUSH       EAX
//         0048036a     PUSH       ECX
//         0048036b     CALL       deflate_data                                     undefined deflate_data()
//         00480370     ADD        ESP,0x10
//         00480373     CMP        EAX,0x2
//         00480376     JNZ        LAB_00480382
//                              rge_fio.cpp:356 (10)
//         00480378     MOV        dword ptr [rge_write_error],0x1
//                               LAB_00480382                                                 XREF[6]:     004802cf(j), 004802db(j),
//                                                                                                         004802f6(j), 00480309(j),
//                                                                                                         00480311(j), 00480376(j)
//                              rge_fio.cpp:360 (1)
//         00480382     RET
//         00480383     ??         90h
//         00480384     NOP
//         00480385     NOP
//         00480386     NOP
//         00480387     NOP
//         00480388     NOP
//         00480389     NOP
//         0048038a     NOP
//         0048038b     NOP
//         0048038c     NOP
//         0048038d     NOP
//         0048038e     NOP
//         0048038f     NOP
    return;
}

