#include "../common.h"
#include "rmm_obj.h"

RGE_RMM_Object_Generator::RGE_RMM_Object_Generator(RGE_Map* param_1, RGE_Random_Map_Module* param_2, RGE_Game_World* param_3, RGE_Object_Info* param_4, uchar param_5) {
    /* TODO: Stub */
//                              undefined __thiscall RGE_RMM_Object_Generator(RGE_RMM_Object_Generat
//              undefined         <UNASSIGNED>   <RETURN>
//              RGE_RMM_Object    ECX:4 (auto)   this
//              RGE_Map *         Stack[0x4]:4   param_1                   XREF[1]:     00485c58(R)
//              RGE_Random_Map    Stack[0x8]:4   param_2                   XREF[1]:     00485c50(R)
//              RGE_Game_World    Stack[0xc]:4   param_3                   XREF[1]:     00485c6b(R)
//              RGE_Object_Inf    Stack[0x10]:4  param_4                   XREF[1]:     00485c67(R)
//              uchar             Stack[0x14]:1  param_5                   XREF[1]:     00485c98(R)
//                               ??0RGE_RMM_Object_Generator@@QAE@PAVRGE_Map@@PAVRGE_Random_  XREF[3]:     add_object_module:00482b47(c),
//                               RGE_RMM_Object_Generator::RGE_RMM_Object_Generator                        generate:004834e3(c),
//                                                                                                         new_game:0052f9e3(c)
//                              rmm_obj.cpp:28 (23)
//         00485c50     MOV        EAX,dword ptr [ESP + param_2]
//         00485c54     PUSH       EBX
//         00485c55     MOV        EBX,this
//         00485c57     PUSH       ESI
//         00485c58     MOV        this,dword ptr [ESP + param_1]
//         00485c5c     PUSH       0x1
//         00485c5e     PUSH       EAX
//         00485c5f     PUSH       this
//         00485c60     MOV        this,EBX
//         00485c62     CALL       RGE_Random_Map_Module::RGE_Random_Map_Module     undefined RGE_Random_Map_Module(RGE_Random_Ma
//                              rmm_obj.cpp:31 (24)
//         00485c67     MOV        ESI,dword ptr [ESP + param_4]
//         00485c6b     MOV        EDX,dword ptr [ESP + param_3]
//         00485c6f     XOR        EAX,EAX
//         00485c71     MOV        dword ptr [EBX],RGE_RMM_Object_Generator::`vft   = 00485dc0
//         00485c77     CMP        ESI,EAX
//         00485c79     MOV        dword ptr [EBX + 0x30],EDX
//         00485c7c     JZ         LAB_00485c8c
//         00485c7e     PUSH       EDI
//                              rmm_obj.cpp:32 (11)
//         00485c7f     MOV        this,0x632
//         00485c84     LEA        EDI,[EBX + 0x34]
//         00485c87     MOVSD.REP  ES:EDI,ESI
//         00485c89     POP        EDI
//                              rmm_obj.cpp:33 (2)
//         00485c8a     JMP        LAB_00485c98
//                               LAB_00485c8c                                                 XREF[1]:     00485c7c(j)
//                              rmm_obj.cpp:35 (6)
//         00485c8c     MOV        dword ptr [EBX + 0x12c4],EAX
//                              rmm_obj.cpp:36 (6)
//         00485c92     MOV        dword ptr [EBX + 0x18f8],EAX
//                               LAB_00485c98                                                 XREF[1]:     00485c8a(j)
//                              rmm_obj.cpp:41 (17)
//         00485c98     MOV        AL,byte ptr [ESP + param_5]
//         00485c9c     MOV        dword ptr [EBX + 0x1c],0x40400000
//         00485ca3     MOV        byte ptr [EBX + 0x191c],AL
//                              rmm_obj.cpp:42 (7)
//         00485ca9     MOV        EAX,EBX
//         00485cab     POP        ESI
//         00485cac     POP        EBX
//         00485cad     RET        0x14
}

void RGE_RMM_Object_Generator::add_quick_obj(long param_1, long param_2, long param_3) {
    /* TODO: Stub */
//                              void __thiscall add_quick_obj(RGE_RMM_Object_Generator * this, long
//              void              <VOID>         <RETURN>
//              RGE_RMM_Object    ECX:4 (auto)   this
//              long              Stack[0x4]:4   param_1                   XREF[1]:     00485cb6(R)
//              long              Stack[0x8]:4   param_2                   XREF[1]:     00485cbb(R)
//              long              Stack[0xc]:4   param_3                   XREF[1]:     00485d9a(R)
//                               ?add_quick_obj@RGE_RMM_Object_Generator@@QAEXJJJ@Z           XREF[5]:     new_game:0052fa52(c),
//                               RGE_RMM_Object_Generator::add_quick_obj                                   new_game:0052faa7(c),
//                                                                                                         new_game:0052fb0e(c),
//                                                                                                         new_game:0052fb87(c),
//                                                                                                         new_game:0052fbd9(c)
//                              rmm_obj.cpp:46 (11)
//         00485cb0     MOV        EAX,dword ptr [ECX + this+0x12c4]
//         00485cb6     MOV        EDX,dword ptr [ESP + param_1]
//         00485cba     PUSH       EBX
//                              rmm_obj.cpp:53 (124)
//         00485cbb     MOV        EBX,dword ptr [ESP + param_2]
//         00485cbf     LEA        EAX,[EAX + EAX*0x2]
//         00485cc2     SHL        EAX,0x4
//         00485cc5     MOV        dword ptr [EAX + this->_padding_*0x1 + 0x34],EDX
//         00485cc9     MOV        EAX,dword ptr [ECX + this+0x12c4]
//         00485ccf     XOR        EDX,EDX
//         00485cd1     LEA        EAX,[EAX + EAX*0x2]
//         00485cd4     SHL        EAX,0x4
//         00485cd7     MOV        dword ptr [EAX + this->_padding_*0x1 + 0x38],0
//         00485cdf     MOV        EAX,dword ptr [ECX + this+0x12c4]
//         00485ce5     LEA        EAX,[EAX + EAX*0x2]
//         00485ce8     SHL        EAX,0x4
//         00485ceb     MOV        byte ptr [EAX + this->_padding_*0x1 + 0x3c],DL
//         00485cef     MOV        EAX,dword ptr [ECX + this+0x12c4]
//         00485cf5     LEA        EAX,[EAX + EAX*0x2]
//         00485cf8     SHL        EAX,0x4
//         00485cfb     MOV        byte ptr [EAX + this->_padding_*0x1 + 0x3d],DL
//         00485cff     MOV        EAX,dword ptr [ECX + this+0x12c4]
//         00485d05     LEA        EAX,[EAX + EAX*0x2]
//         00485d08     SHL        EAX,0x4
//         00485d0b     MOV        dword ptr [EAX + this->_padding_*0x1 + 0x40],0x1
//         00485d13     MOV        EAX,dword ptr [ECX + this+0x12c4]
//         00485d19     LEA        EAX,[EAX + EAX*0x2]
//         00485d1c     SHL        EAX,0x4
//         00485d1f     MOV        dword ptr [EAX + this->_padding_*0x1 + 0x44],0x1
//         00485d27     MOV        EAX,dword ptr [ECX + this+0x12c4]
//         00485d2d     LEA        EAX,[EAX + EAX*0x2]
//         00485d30     SHL        EAX,0x4
//         00485d33     MOV        dword ptr [EAX + this->_padding_*0x1 + 0x48],EBX
//                              rmm_obj.cpp:54 (6)
//         00485d37     MOV        EAX,dword ptr [ECX + this+0x12c4]
//                              rmm_obj.cpp:62 (125)
//         00485d3d     POP        EBX
//         00485d3e     LEA        EAX,[EAX + EAX*0x2]
//         00485d41     SHL        EAX,0x4
//         00485d44     MOV        dword ptr [EAX + this->_padding_*0x1 + 0x4c],0x2
//         00485d4c     MOV        EAX,dword ptr [ECX + this+0x12c4]
//         00485d52     LEA        EAX,[EAX + EAX*0x2]
//         00485d55     SHL        EAX,0x4
//         00485d58     MOV        dword ptr [EAX + this->_padding_*0x1 + 0x50],EDX
//         00485d5c     MOV        EAX,dword ptr [ECX + this+0x12c4]
//         00485d62     LEA        EAX,[EAX + EAX*0x2]
//         00485d65     SHL        EAX,0x4
//         00485d68     MOV        dword ptr [EAX + this->_padding_*0x1 + 0x54],0
//         00485d70     MOV        EAX,dword ptr [ECX + this+0x12c4]
//         00485d76     LEA        EAX,[EAX + EAX*0x2]
//         00485d79     SHL        EAX,0x4
//         00485d7c     MOV        dword ptr [EAX + this->_padding_*0x1 + 0x58],EDX
//         00485d80     MOV        EAX,dword ptr [ECX + this+0x12c4]
//         00485d86     LEA        EDX,[EAX + EAX*0x2]
//         00485d89     SHL        EDX,0x4
//         00485d8c     MOV        dword ptr [EDX + this->_padding_*0x1 + 0x5c],0x1
//         00485d94     MOV        EAX,dword ptr [ECX + this+0x12c4]
//         00485d9a     MOV        EDX,dword ptr [ESP + param_3]
//         00485d9e     ADD        EAX,0x2
//         00485da1     LEA        EAX,[EAX + EAX*0x2]
//         00485da4     SHL        EAX,0x4
//         00485da7     MOV        dword ptr [EAX + this->_padding_*0x1],EDX
//         00485daa     MOV        EAX,dword ptr [ECX + this+0x12c4]
//         00485db0     INC        EAX
//         00485db1     MOV        dword ptr [ECX + this+0x12c4],EAX
//         00485db7     RET        0xc
//         00485dba     ??         90h
//         00485dbb     NOP
//         00485dbc     NOP
//         00485dbd     NOP
//         00485dbe     NOP
//         00485dbf     NOP
    return;
}

uchar RGE_RMM_Object_Generator::generate() {
    /* TODO: Stub */
//                              uchar __thiscall generate(RGE_RMM_Object_Generator * this)
//              uchar             AL:1           <RETURN>
//              RGE_RMM_Object    ECX:4 (auto)   this
//                               ?generate@RGE_RMM_Object_Generator@@UAEEXZ                   XREF[1]:     00571ed8(*)
//                               RGE_RMM_Object_Generator::generate
//                              rmm_obj.cpp:66 (5)
//         00485dc0     PUSH       EBX
//         00485dc1     PUSH       ESI
//         00485dc2     MOV        ESI,this
//         00485dc4     PUSH       EDI
//                              rmm_obj.cpp:71 (10)
//         00485dc5     MOV        AL,byte ptr [ESI + 0x191c]
//         00485dcb     TEST       AL,AL
//         00485dcd     JZ         LAB_00485df9
//                              rmm_obj.cpp:72 (42)
//         00485dcf     MOV        this,word ptr [ESI + 0x18]
//         00485dd3     MOV        DX,word ptr [ESI + 0x14]
//         00485dd7     MOV        EAX,dword ptr [ESI + 0x30]
//         00485dda     PUSH       0x0
//         00485ddc     PUSH       0x0
//         00485dde     DEC        this
//         00485de0     PUSH       0x1
//         00485de2     DEC        DX
//         00485de4     PUSH       this
//         00485de5     PUSH       EDX
//         00485de6     PUSH       0x0
//         00485de8     PUSH       0x0
//         00485dea     PUSH       EAX
//         00485deb     MOV        EAX,dword ptr [EAX + 0x40]
//         00485dee     MOV        this,dword ptr [EAX]
//         00485df0     PUSH       this
//         00485df1     MOV        this,dword ptr [ESI + 0xc]
//         00485df4     CALL       RGE_Map::set_terrain                             void set_terrain(RGE_Map * this, RGE_Player *
//                               LAB_00485df9                                                 XREF[1]:     00485dcd(j)
//                              rmm_obj.cpp:74 (13)
//         00485df9     MOV        this,ESI
//         00485dfb     CALL       RGE_Random_Map_Module::clear_stack               void clear_stack(RGE_Random_Map_Module * this)
//         00485e00     LEA        EDI,[ESI + 0x18fc]
//                              rmm_obj.cpp:77 (9)
//         00485e06     MOV        this,0x8
//         00485e0b     XOR        EAX,EAX
//         00485e0d     STOSD.REP  ES:EDI
//                              rmm_obj.cpp:79 (12)
//         00485e0f     MOV        EAX,dword ptr [ESI + 0x12c4]
//         00485e15     XOR        EDI,EDI
//         00485e17     TEST       EAX,EAX
//         00485e19     JLE        LAB_00485e34
//                              rmm_obj.cpp:86 (3)
//         00485e1b     LEA        EBX,[ESI + 0x34]
//                               LAB_00485e1e                                                 XREF[1]:     00485e32(j)
//                              rmm_obj.cpp:80 (22)
//         00485e1e     PUSH       EBX
//         00485e1f     MOV        this,ESI
//         00485e21     CALL       RGE_RMM_Object_Generator::generate_objects       void generate_objects(RGE_RMM_Object_Generato
//         00485e26     MOV        EAX,dword ptr [ESI + 0x12c4]
//         00485e2c     INC        EDI
//         00485e2d     ADD        EBX,0x30
//         00485e30     CMP        EDI,EAX
//         00485e32     JL         LAB_00485e1e
//                               LAB_00485e34                                                 XREF[1]:     00485e19(j)
//                              rmm_obj.cpp:82 (14)
//         00485e34     MOV        EDX,dword ptr [ESI + 0xc]
//         00485e37     MOV        this,dword ptr [EDX + 0x8dc4]
//         00485e3d     CALL       RGE_Zone_Map_List::delete_zone_maps              void delete_zone_maps(RGE_Zone_Map_List * this)
//                              rmm_obj.cpp:86 (6)
//         00485e42     POP        EDI
//         00485e43     POP        ESI
//         00485e44     MOV        AL,0x1
//         00485e46     POP        EBX
//         00485e47     RET
//         00485e48     ??         90h
//         00485e49     NOP
//         00485e4a     NOP
//         00485e4b     NOP
//         00485e4c     NOP
//         00485e4d     NOP
//         00485e4e     NOP
//         00485e4f     NOP
    return 0;
}

void RGE_RMM_Object_Generator::generate_objects(RGE_Object_Info_Line* param_1) {
    /* TODO: Stub */
//                              void __thiscall generate_objects(RGE_RMM_Object_Generator * this, RG
//              void              <VOID>         <RETURN>
//              RGE_RMM_Object    ECX:4 (auto)   this
//              RGE_Object_Inf    Stack[0x4]:4   param_1                   XREF[1]:     00485e53(R)
//                               ?generate_objects@RGE_RMM_Object_Generator@@IAEXAAURGE_Obje  XREF[1]:     generate:00485e21(c)
//                               RGE_RMM_Object_Generator::generate_objects
//                              rmm_obj.cpp:90 (3)
//         00485e50     PUSH       EBX
//         00485e51     PUSH       EBP
//         00485e52     PUSH       ESI
//                              rmm_obj.cpp:93 (14)
//         00485e53     MOV        ESI,dword ptr [ESP + param_1]
//         00485e57     PUSH       EDI
//         00485e58     MOV        EBX,this
//         00485e5a     MOV        AL,byte ptr [ESI + 0x9]
//         00485e5d     TEST       AL,AL
//         00485e5f     JZ         LAB_00485e8c
//                              rmm_obj.cpp:96 (28)
//         00485e61     MOV        this,dword ptr [EBX + 0x18]
//         00485e64     MOV        EAX,0x1948b0fd
//         00485e69     IMUL       this,dword ptr [EBX + 0x14]
//         00485e6d     IMUL       this,dword ptr [ESI + 0x14]
//         00485e71     IMUL       this
//         00485e73     SAR        EDX,0xb
//         00485e76     MOV        EAX,EDX
//         00485e78     SHR        EAX,0x1f
//         00485e7b     ADD        EDX,EAX
//                              rmm_obj.cpp:97 (8)
//         00485e7d     CMP        EDX,0x1
//         00485e80     MOV        dword ptr [ESI + 0x14],EDX
//         00485e83     JGE        LAB_00485e8c
//                              rmm_obj.cpp:98 (7)
//         00485e85     MOV        dword ptr [ESI + 0x14],0x1
//                               LAB_00485e8c                                                 XREF[2]:     00485e5f(j), 00485e83(j)
//                              rmm_obj.cpp:101 (7)
//         00485e8c     MOV        EAX,dword ptr [ESI + 0x20]
//         00485e8f     TEST       EAX,EAX
//         00485e91     JL         LAB_00485edc
//                              rmm_obj.cpp:103 (12)
//         00485e93     MOV        EAX,dword ptr [EBX + 0x18f8]
//         00485e99     XOR        EBP,EBP
//         00485e9b     TEST       EAX,EAX
//         00485e9d     JLE        LAB_00485f01
//                              rmm_obj.cpp:114 (6)
//         00485e9f     LEA        EDI,[EBX + 0x12cc]
//                               LAB_00485ea5                                                 XREF[1]:     00485ed3(j)
//                              rmm_obj.cpp:104 (10)
//         00485ea5     MOV        this,dword ptr [EDI + 0x4]
//         00485ea8     MOV        EAX,dword ptr [ESI + 0x20]
//         00485eab     CMP        this,EAX
//         00485ead     JNZ        LAB_00485ec7
//                              rmm_obj.cpp:105 (38)
//         00485eaf     MOV        EDX,dword ptr [ESI + 0x28]
//         00485eb2     MOV        EAX,dword ptr [ESI + 0x24]
//         00485eb5     MOV        this,dword ptr [EDI]
//         00485eb7     PUSH       EBP
//         00485eb8     PUSH       EDX
//         00485eb9     MOV        EDX,dword ptr [EDI + -0x4]
//         00485ebc     PUSH       EAX
//         00485ebd     PUSH       this
//         00485ebe     PUSH       EDX
//         00485ebf     PUSH       ESI
//         00485ec0     MOV        this,EBX
//         00485ec2     CALL       RGE_RMM_Object_Generator::place_land_objects     void place_land_objects(RGE_RMM_Object_Genera
//                               LAB_00485ec7                                                 XREF[1]:     00485ead(j)
//         00485ec7     MOV        EAX,dword ptr [EBX + 0x18f8]
//         00485ecd     INC        EBP
//         00485ece     ADD        EDI,0x10
//         00485ed1     CMP        EBP,EAX
//         00485ed3     JL         LAB_00485ea5
//                              rmm_obj.cpp:114 (7)
//         00485ed5     POP        EDI
//         00485ed6     POP        ESI
//         00485ed7     POP        EBP
//         00485ed8     POP        EBX
//         00485ed9     RET        0x4
//                               LAB_00485edc                                                 XREF[1]:     00485e91(j)
//                              rmm_obj.cpp:107 (5)
//         00485edc     CMP        EAX,-0x1
//         00485edf     JNZ        LAB_00485ef0
//                              rmm_obj.cpp:109 (8)
//         00485ee1     PUSH       ESI
//         00485ee2     MOV        this,EBX
//         00485ee4     CALL       RGE_RMM_Object_Generator::place_objects          void place_objects(RGE_RMM_Object_Generator *
//                              rmm_obj.cpp:114 (7)
//         00485ee9     POP        EDI
//         00485eea     POP        ESI
//         00485eeb     POP        EBP
//         00485eec     POP        EBX
//         00485eed     RET        0x4
//                               LAB_00485ef0                                                 XREF[1]:     00485edf(j)
//                              rmm_obj.cpp:110 (5)
//         00485ef0     CMP        EAX,-0x2
//         00485ef3     JNZ        LAB_00485f01
//                              rmm_obj.cpp:113 (12)
//         00485ef5     MOV        EAX,dword ptr [ESI + 0x24]
//         00485ef8     MOV        this,EBX
//         00485efa     PUSH       EAX
//         00485efb     PUSH       ESI
//         00485efc     CALL       RGE_RMM_Object_Generator::place_avoid_objects    void place_avoid_objects(RGE_RMM_Object_Gener
//                               LAB_00485f01                                                 XREF[2]:     00485e9d(j), 00485ef3(j)
//                              rmm_obj.cpp:114 (7)
//         00485f01     POP        EDI
//         00485f02     POP        ESI
//         00485f03     POP        EBP
//         00485f04     POP        EBX
//         00485f05     RET        0x4
//         00485f08     ??         90h
//         00485f09     NOP
//         00485f0a     NOP
//         00485f0b     NOP
//         00485f0c     NOP
//         00485f0d     NOP
//         00485f0e     NOP
//         00485f0f     NOP
    return;
}

void RGE_RMM_Object_Generator::make_placement_stack(Map_Stack* param_1, long param_2, long param_3, long param_4, long param_5) {
    /* TODO: Stub */
//                              void __thiscall make_placement_stack(RGE_RMM_Object_Generator * this
//              void              <VOID>         <RETURN>
//              RGE_RMM_Object    ECX:4 (auto)   this
//              Map_Stack *       Stack[0x4]:4   param_1                   XREF[3]:     00485f13(R), 00485fad(R), 004860e5(R)
//              long              Stack[0x8]:4   param_2                   XREF[6]:     00485f1f(R), 00485f4b(W), 00485f5d(W), 00485f8c(W),
//                                                                                     00486006(R), 00486064(R)
//              long              Stack[0xc]:4   param_3                   XREF[6]:     00485f2d(R), 00485f4f(W), 00485f67(W), 00485f91(W),
//                                                                                     00486028(R), 004860b3(R)
//              long              Stack[0x10]:4  param_4
//              long              Stack[0x14]:4  param_5                   XREF[9]:     00485f35(R), 00485f53(W), 00485f75(W), 00485f95(W),
//                                                                                     00485f9c(R), 00485ffa(R), 0048605e(W), 004860f2(R),
//                                                                                     004860f7(W)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[3]:     00485fc9(W), 00486016(R), 00486022(W)
//              undefined4        Stack[-0x8]:4  local_8                   XREF[3]:     00485fc4(W), 00485ffe(R), 0048601e(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[3]:     00485fb3(W), 00485fe8(R), 00486002(W)
//              Map_Stack *       Stack[-0x10]:4 last                      XREF[5]:     00485f57(W), 00485f83(W), 00485fa1(W), 00485fa9(R),
//                                                                                     00486012(R)
//              long              Stack[-0x14]:4 y1
//                               ?make_placement_stack@RGE_RMM_Object_Generator@@IAEXAAUMap_  XREF[4]:     place_avoid_objects:00486329(c),
//                               RGE_RMM_Object_Generator::make_placement_stack                            place_objects:00486531(c),
//                                                                                                         place_land_objects:004867ce(c),
//                                                                                                         place_group:00486a92(c)
//                              rmm_obj.cpp:118 (3)
//         00485f10     SUB        ESP,0x10
//                              rmm_obj.cpp:132 (12)
//         00485f13     MOV        EAX,dword ptr [ESP + param_1]
//         00485f17     PUSH       EBX
//         00485f18     PUSH       EBP
//         00485f19     PUSH       ESI
//         00485f1a     PUSH       EDI
//         00485f1b     MOV        EDI,this
//         00485f1d     XOR        EBX,EBX
//                              rmm_obj.cpp:136 (30)
//         00485f1f     MOV        this,dword ptr [ESP + param_2]
//         00485f23     MOV        dword ptr [EAX + 0x10],EBX
//         00485f26     CMP        this,EBX
//         00485f28     MOV        dword ptr [EAX + 0x14],EBX
//         00485f2b     JL         LAB_00485f89
//         00485f2d     MOV        EDX,dword ptr [ESP + param_3]
//         00485f31     CMP        EDX,EBX
//         00485f33     JL         LAB_00485f89
//         00485f35     MOV        EAX,dword ptr [ESP + param_5]
//         00485f39     CMP        EAX,EBX
//         00485f3b     JL         LAB_00485f89
//                              rmm_obj.cpp:145 (2)
//         00485f3d     MOV        ESI,this
//                              rmm_obj.cpp:146 (6)
//         00485f3f     MOV        EBP,EDX
//         00485f41     SUB        ESI,EAX
//         00485f43     SUB        EBP,EAX
//                              rmm_obj.cpp:147 (2)
//         00485f45     ADD        this,EAX
//                              rmm_obj.cpp:148 (2)
//         00485f47     ADD        EDX,EAX
//                              rmm_obj.cpp:150 (26)
//         00485f49     CMP        ESI,EBX
//         00485f4b     MOV        dword ptr [ESP + param_2],ESI
//         00485f4f     MOV        dword ptr [ESP + param_3],EBP
//         00485f53     MOV        dword ptr [ESP + param_5],this
//         00485f57     MOV        dword ptr [ESP + last],EDX
//         00485f5b     JGE        LAB_00485f63
//         00485f5d     MOV        dword ptr [ESP + param_2],EBX
//         00485f61     MOV        ESI,EBX
//                               LAB_00485f63                                                 XREF[1]:     00485f5b(j)
//                              rmm_obj.cpp:151 (10)
//         00485f63     CMP        EBP,EBX
//         00485f65     JGE        LAB_00485f6d
//         00485f67     MOV        dword ptr [ESP + param_3],EBX
//         00485f6b     MOV        EBP,EBX
//                               LAB_00485f6d                                                 XREF[1]:     00485f65(j)
//                              rmm_obj.cpp:152 (14)
//         00485f6d     MOV        EAX,dword ptr [EDI + 0x14]
//         00485f70     CMP        this,EAX
//         00485f72     JL         LAB_00485f7b
//         00485f74     DEC        EAX
//         00485f75     MOV        dword ptr [ESP + param_5],EAX
//         00485f79     MOV        this,EAX
//                               LAB_00485f7b                                                 XREF[1]:     00485f72(j)
//                              rmm_obj.cpp:153 (14)
//         00485f7b     MOV        EAX,dword ptr [EDI + 0x18]
//         00485f7e     CMP        EDX,EAX
//         00485f80     JL         LAB_00485fa9
//         00485f82     DEC        EAX
//         00485f83     MOV        dword ptr [ESP + last],EAX
//         00485f87     JMP        LAB_00485fa9
//                               LAB_00485f89                                                 XREF[3]:     00485f2b(j), 00485f33(j),
//                                                                                                         00485f3b(j)
//                              rmm_obj.cpp:140 (16)
//         00485f89     MOV        EAX,dword ptr [EDI + 0x14]
//         00485f8c     MOV        dword ptr [ESP + param_2],EBX
//         00485f90     DEC        EAX
//         00485f91     MOV        dword ptr [ESP + param_3],EBX
//         00485f95     MOV        dword ptr [ESP + param_5],EAX
//                              rmm_obj.cpp:141 (16)
//         00485f99     MOV        EAX,dword ptr [EDI + 0x18]
//         00485f9c     MOV        this,dword ptr [ESP + param_5]
//         00485fa0     DEC        EAX
//         00485fa1     MOV        dword ptr [ESP + last],EAX
//         00485fa5     MOV        ESI,EBX
//         00485fa7     MOV        EBP,EBX
//                               LAB_00485fa9                                                 XREF[2]:     00485f80(j), 00485f87(j)
//                              rmm_obj.cpp:158 (36)
//         00485fa9     MOV        EDX,dword ptr [ESP + last]
//         00485fad     MOV        EAX,dword ptr [ESP + param_1]
//         00485fb1     CMP        EBP,EDX
//         00485fb3     MOV        dword ptr [ESP + local_c],EAX
//         00485fb7     JG         LAB_0048602c
//         00485fb9     MOV        EBX,EDX
//         00485fbb     LEA        EAX,[EBP*0x4 + 0x0]
//         00485fc2     SUB        EBX,EBP
//         00485fc4     MOV        dword ptr [ESP + local_8],EAX
//         00485fc8     INC        EBX
//         00485fc9     MOV        dword ptr [ESP + local_4],EBX
//                               LAB_00485fcd                                                 XREF[1]:     00486026(j)
//                              rmm_obj.cpp:159 (12)
//         00485fcd     CMP        ESI,this
//         00485fcf     MOV        EBP,ESI
//         00485fd1     JG         LAB_00486016
//         00485fd3     LEA        EBX,[ESI + ESI*0x2]
//         00485fd6     SHL        EBX,0x3
//                               LAB_00485fd9                                                 XREF[1]:     00486010(j)
//                              rmm_obj.cpp:160 (12)
//         00485fd9     MOV        EDX,dword ptr [EDI + 0x24]
//         00485fdc     MOV        EDX,dword ptr [EDX + EAX*0x1]
//         00485fdf     CMP        byte ptr [EDX + EBP*0x1],0x0
//         00485fe3     JZ         LAB_0048600a
//                              rmm_obj.cpp:162 (3)
//         00485fe5     MOV        this,dword ptr [EDI + 0x2c]
//                              rmm_obj.cpp:163 (18)
//         00485fe8     MOV        EDX,dword ptr [ESP + local_c]
//         00485fec     MOV        ESI,dword ptr [this->_padding_ + EAX*0x1]
//         00485fef     MOV        this,EDI
//         00485ff1     ADD        ESI,EBX
//         00485ff3     PUSH       ESI
//         00485ff4     PUSH       EDX
//         00485ff5     CALL       RGE_Random_Map_Module::add_stack_node            void add_stack_node(RGE_Random_Map_Module * t
//                              rmm_obj.cpp:164 (24)
//         00485ffa     MOV        this,dword ptr [ESP + param_5]
//         00485ffe     MOV        EAX,dword ptr [ESP + local_8]
//         00486002     MOV        dword ptr [ESP + local_c],ESI
//         00486006     MOV        ESI,dword ptr [ESP + param_2]
//                               LAB_0048600a                                                 XREF[1]:     00485fe3(j)
//         0048600a     INC        EBP
//         0048600b     ADD        EBX,0x18
//         0048600e     CMP        EBP,this
//         00486010     JLE        LAB_00485fd9
//                              rmm_obj.cpp:159 (4)
//         00486012     MOV        EDX,dword ptr [ESP + last]
//                               LAB_00486016                                                 XREF[1]:     00485fd1(j)
//                              rmm_obj.cpp:158 (22)
//         00486016     MOV        EBX,dword ptr [ESP + local_4]
//         0048601a     ADD        EAX,0x4
//         0048601d     DEC        EBX
//         0048601e     MOV        dword ptr [ESP + local_8],EAX
//         00486022     MOV        dword ptr [ESP + local_4],EBX
//         00486026     JNZ        LAB_00485fcd
//         00486028     MOV        EBP,dword ptr [ESP + param_3]
//                               LAB_0048602c                                                 XREF[1]:     00485fb7(j)
//                              rmm_obj.cpp:168 (2)
//         0048602c     SUB        this,ESI
//                              rmm_obj.cpp:169 (8)
//         0048602e     SUB        EDX,EBP
//         00486030     DEC        this
//         00486031     DEC        EDX
//         00486032     MOV        EBX,this
//         00486034     MOV        EBP,EDX
//                              rmm_obj.cpp:170 (18)
//         00486036     CMP        EBX,0x1
//         00486039     JLE        LAB_00486101
//         0048603f     CMP        EBP,0x1
//         00486042     JLE        LAB_00486101
//                              rmm_obj.cpp:172 (14)
//         00486048     MOV        EAX,EBP
//         0048604a     IMUL       EAX,EBX
//         0048604d     CDQ
//         0048604e     AND        EDX,0x3
//         00486051     ADD        EAX,EDX
//         00486053     SAR        EAX,0x2
//                              rmm_obj.cpp:173 (8)
//         00486056     TEST       EAX,EAX
//         00486058     JLE        LAB_00486101
//                              rmm_obj.cpp:181 (10)
//         0048605e     MOV        dword ptr [ESP + param_5],EAX
//         00486062     JMP        LAB_00486068
//                               LAB_00486064                                                 XREF[1]:     004860fb(j)
//         00486064     MOV        ESI,dword ptr [ESP + param_2]
//                               LAB_00486068                                                 XREF[1]:     00486062(j)
//                              rmm_obj.cpp:175 (37)
//         00486068     PUSH       0xaf
//         0048606d     PUSH       s_C:\msdev\work\age1_x1\rmm_obj.cp               = "C:\\msdev\\work\\age1_x1\\rmm_obj.cpp"
//         00486072     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
//         00486077     MOV        this,EAX
//         00486079     MOV        EAX,0x80010003
//         0048607e     IMUL       this,EBX
//         00486081     IMUL       this
//         00486083     ADD        EDX,this
//         00486085     ADD        ESP,0x8
//         00486088     SAR        EDX,0xe
//         0048608b     MOV        EAX,EDX
//                              rmm_obj.cpp:176 (57)
//         0048608d     PUSH       0xb0
//         00486092     SHR        EAX,0x1f
//         00486095     ADD        EDX,EAX
//         00486097     PUSH       s_C:\msdev\work\age1_x1\rmm_obj.cp               = "C:\\msdev\\work\\age1_x1\\rmm_obj.cpp"
//         0048609c     ADD        EDX,ESI
//         0048609e     MOV        ESI,EDX
//         004860a0     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
//         004860a5     MOV        this,EAX
//         004860a7     MOV        EAX,0x80010003
//         004860ac     IMUL       this,EBP
//         004860af     IMUL       this
//         004860b1     ADD        EDX,this
//         004860b3     MOV        EAX,dword ptr [ESP + param_3]
//         004860b7     SAR        EDX,0xe
//         004860ba     MOV        this,EDX
//         004860bc     ADD        ESP,0x8
//         004860bf     SHR        this,0x1f
//         004860c2     ADD        EDX,this
//         004860c4     ADD        EDX,EAX
//                              rmm_obj.cpp:177 (19)
//         004860c6     LEA        EAX,[EDX*0x4 + 0x0]
//         004860cd     MOV        EDX,dword ptr [EDI + 0x24]
//         004860d0     MOV        this,dword ptr [EDX + EAX*0x1]
//         004860d3     CMP        byte ptr [this->_padding_ + ESI*0x1],0x0
//         004860d7     JZ         LAB_004860f2
//                              rmm_obj.cpp:178 (40)
//         004860d9     MOV        EDX,dword ptr [EDI + 0x2c]
//         004860dc     LEA        this,[ESI + ESI*0x2]
//         004860df     MOV        EDX,dword ptr [EDX + EAX*0x1]
//         004860e2     LEA        EAX,[EDX + this->_padding_*0x8]
//         004860e5     MOV        this,dword ptr [ESP + param_1]
//         004860e9     PUSH       EAX
//         004860ea     PUSH       this
//         004860eb     MOV        this,EDI
//         004860ed     CALL       RGE_Random_Map_Module::add_stack_node            void add_stack_node(RGE_Random_Map_Module * t
//                               LAB_004860f2                                                 XREF[1]:     004860d7(j)
//         004860f2     MOV        EAX,dword ptr [ESP + param_5]
//         004860f6     DEC        EAX
//         004860f7     MOV        dword ptr [ESP + param_5],EAX
//         004860fb     JNZ        LAB_00486064
//                               LAB_00486101                                                 XREF[3]:     00486039(j), 00486042(j),
//                                                                                                         00486058(j)
//                              rmm_obj.cpp:181 (10)
//         00486101     POP        EDI
//         00486102     POP        ESI
//         00486103     POP        EBP
//         00486104     POP        EBX
//         00486105     ADD        ESP,0x10
//         00486108     RET        0x14
//         0048610b     ??         90h
//         0048610c     NOP
//         0048610d     NOP
//         0048610e     NOP
//         0048610f     NOP
    return;
}

uchar RGE_RMM_Object_Generator::to_close(RGE_Object_Info_Line* param_1, long param_2, long param_3) {
    /* TODO: Stub */
//                              uchar __thiscall to_close(RGE_RMM_Object_Generator * this, RGE_Objec
//              uchar             AL:1           <RETURN>
//              RGE_RMM_Object    ECX:4 (auto)   this
//              RGE_Object_Inf    Stack[0x4]:4   param_1                   XREF[1]:     00486120(R)
//              long              Stack[0x8]:4   param_2                   XREF[1]:     00486131(R)
//              long              Stack[0xc]:4   param_3                   XREF[1]:     00486124(R)
//                               ?to_close@RGE_RMM_Object_Generator@@IAEEAAURGE_Object_Info_
//                               RGE_RMM_Object_Generator::to_close
//                              rmm_obj.cpp:185 (4)
//         00486110     PUSH       EBX
//         00486111     PUSH       EBP
//         00486112     PUSH       ESI
//         00486113     PUSH       EDI
//                              rmm_obj.cpp:190 (12)
//         00486114     MOV        EDI,dword ptr [ECX + this+0x18f8]
//         0048611a     XOR        ESI,ESI
//         0048611c     TEST       EDI,EDI
//         0048611e     JLE        LAB_00486168
//                              rmm_obj.cpp:198 (28)
//         00486120     MOV        EAX,dword ptr [ESP + param_1]
//         00486124     MOV        EBP,dword ptr [ESP + param_3]
//         00486128     LEA        EDX,[ECX + this+0x12cc]
//         0048612e     MOV        EBX,dword ptr [EAX + 0x24]
//                               LAB_00486131                                                 XREF[1]:     00486154(j)
//         00486131     MOV        this,dword ptr [ESP + param_2]
//         00486135     MOV        EAX,dword ptr [EDX + -0x4]
//         00486138     SUB        this,EAX
//         0048613a     JNS        LAB_0048613e
//                              rmm_obj.cpp:193 (2)
//         0048613c     NEG        this
//                               LAB_0048613e                                                 XREF[1]:     0048613a(j)
//                              rmm_obj.cpp:190 (4)
//         0048613e     MOV        EAX,EBP
//         00486140     SUB        EAX,dword ptr [EDX]
//                              rmm_obj.cpp:196 (4)
//         00486142     JNS        LAB_00486146
//         00486144     NEG        EAX
//                               LAB_00486146                                                 XREF[1]:     00486142(j)
//                              rmm_obj.cpp:198 (8)
//         00486146     CMP        this,EBX
//         00486148     JGE        LAB_0048614e
//         0048614a     CMP        EAX,EBX
//         0048614c     JL         LAB_0048615f
//                               LAB_0048614e                                                 XREF[1]:     00486148(j)
//                              rmm_obj.cpp:190 (8)
//         0048614e     INC        ESI
//         0048614f     ADD        EDX,0x10
//         00486152     CMP        ESI,EDI
//         00486154     JL         LAB_00486131
//                              rmm_obj.cpp:201 (2)
//         00486156     XOR        AL,AL
//                              rmm_obj.cpp:202 (7)
//         00486158     POP        EDI
//         00486159     POP        ESI
//         0048615a     POP        EBP
//         0048615b     POP        EBX
//         0048615c     RET        0xc
//                               LAB_0048615f                                                 XREF[1]:     0048614c(j)
//                              rmm_obj.cpp:199 (2)
//         0048615f     MOV        AL,0x1
//                              rmm_obj.cpp:202 (16)
//         00486161     POP        EDI
//         00486162     POP        ESI
//         00486163     POP        EBP
//         00486164     POP        EBX
//         00486165     RET        0xc
//                               LAB_00486168                                                 XREF[1]:     0048611e(j)
//         00486168     POP        EDI
//         00486169     POP        ESI
//         0048616a     POP        EBP
//         0048616b     XOR        AL,AL
//         0048616d     POP        EBX
//         0048616e     RET        0xc
//         00486171     ??         90h
//         00486172     NOP
//         00486173     NOP
//         00486174     NOP
//         00486175     NOP
//         00486176     NOP
//         00486177     NOP
//         00486178     NOP
//         00486179     NOP
//         0048617a     NOP
//         0048617b     NOP
//         0048617c     NOP
//         0048617d     NOP
//         0048617e     NOP
//         0048617f     NOP
    return 0;
}

void RGE_RMM_Object_Generator::set_search_area(long param_1, long param_2, long param_3, uchar param_4) {
    /* TODO: Stub */
//                              void __thiscall set_search_area(RGE_RMM_Object_Generator * this, lon
//              void              <VOID>         <RETURN>
//              RGE_RMM_Object    ECX:4 (auto)   this
//              long              Stack[0x4]:4   param_1                   XREF[4]:     00486180(R), 004861a1(W), 004861c3(W), 004861ee(R)
//              long              Stack[0x8]:4   param_2                   XREF[1]:     00486189(R)
//              long              Stack[0xc]:4   param_3                   XREF[4]:     00486184(R), 004861cb(W), 004861f2(R), 004861f9(W)
//              uchar             Stack[0x10]:1  param_4                   XREF[1]:     004861d1(R)
//                               ?set_search_area@RGE_RMM_Object_Generator@@IAEXJJJE@Z        XREF[2]:     place_avoid_objects:004862fb(c),
//                               RGE_RMM_Object_Generator::set_search_area                                 place_land_objects:00486798(c)
//                              rmm_obj.cpp:206 (9)
//         00486180     MOV        EDX,dword ptr [ESP + param_1]
//         00486184     MOV        EAX,dword ptr [ESP + param_3]
//         00486188     PUSH       EBX
//                              rmm_obj.cpp:210 (17)
//         00486189     MOV        EBX,dword ptr [ESP + param_2]
//         0048618d     PUSH       EBP
//         0048618e     PUSH       ESI
//         0048618f     PUSH       EDI
//         00486190     MOV        ESI,this
//         00486192     MOV        EDI,EDX
//         00486194     MOV        this,EBX
//         00486196     SUB        EDI,EAX
//         00486198     SUB        this,EAX
//                              rmm_obj.cpp:211 (2)
//         0048619a     ADD        EDX,EAX
//                              rmm_obj.cpp:212 (3)
//         0048619c     LEA        EBP,[EAX + EBX*0x1]
//                              rmm_obj.cpp:214 (8)
//         0048619f     TEST       EDI,EDI
//         004861a1     MOV        dword ptr [ESP + param_1],EBP
//         004861a5     JGE        LAB_004861a9
//                              rmm_obj.cpp:215 (2)
//         004861a7     XOR        EDI,EDI
//                               LAB_004861a9                                                 XREF[1]:     004861a5(j)
//                              rmm_obj.cpp:216 (4)
//         004861a9     TEST       this,this
//         004861ab     JGE        LAB_004861af
//                              rmm_obj.cpp:217 (2)
//         004861ad     XOR        this,this
//                               LAB_004861af                                                 XREF[1]:     004861ab(j)
//                              rmm_obj.cpp:218 (7)
//         004861af     MOV        EAX,dword ptr [ESI + 0x14]
//         004861b2     CMP        EDX,EAX
//         004861b4     JL         LAB_004861b9
//                              rmm_obj.cpp:219 (3)
//         004861b6     LEA        EDX,[EAX + -0x1]
//                               LAB_004861b9                                                 XREF[1]:     004861b4(j)
//                              rmm_obj.cpp:220 (7)
//         004861b9     MOV        EAX,dword ptr [ESI + 0x18]
//         004861bc     CMP        EBP,EAX
//         004861be     JL         LAB_004861c7
//                              rmm_obj.cpp:221 (7)
//         004861c0     LEA        EBP,[EAX + -0x1]
//         004861c3     MOV        dword ptr [ESP + param_1],EBP
//                               LAB_004861c7                                                 XREF[1]:     004861be(j)
//                              rmm_obj.cpp:223 (14)
//         004861c7     MOV        EBX,this
//         004861c9     CMP        this,EBP
//         004861cb     MOV        dword ptr [ESP + param_3],EBX
//         004861cf     JG         LAB_004861ff
//         004861d1     MOV        this,byte ptr [ESP + param_4]
//                               LAB_004861d5                                                 XREF[1]:     004861fd(j)
//                              rmm_obj.cpp:224 (6)
//         004861d5     CMP        EDI,EDX
//         004861d7     MOV        EAX,EDI
//         004861d9     JG         LAB_004861f6
//                              rmm_obj.cpp:223 (3)
//         004861db     SHL        EBX,0x2
//                               LAB_004861de                                                 XREF[1]:     004861ec(j)
//                              rmm_obj.cpp:225 (33)
//         004861de     MOV        EBP,dword ptr [ESI + 0x24]
//         004861e1     INC        EAX
//         004861e2     CMP        EAX,EDX
//         004861e4     MOV        EBP,dword ptr [EBP + EBX*0x1]
//         004861e8     MOV        byte ptr [EBP + EAX*0x1 + -0x1],this
//         004861ec     JLE        LAB_004861de
//         004861ee     MOV        EBP,dword ptr [ESP + param_1]
//         004861f2     MOV        EBX,dword ptr [ESP + param_3]
//                               LAB_004861f6                                                 XREF[1]:     004861d9(j)
//         004861f6     INC        EBX
//         004861f7     CMP        EBX,EBP
//         004861f9     MOV        dword ptr [ESP + param_3],EBX
//         004861fd     JLE        LAB_004861d5
//                               LAB_004861ff                                                 XREF[1]:     004861cf(j)
//                              rmm_obj.cpp:226 (7)
//         004861ff     POP        EDI
//         00486200     POP        ESI
//         00486201     POP        EBP
//         00486202     POP        EBX
//         00486203     RET        0x10
//         00486206     ??         90h
//         00486207     NOP
//         00486208     NOP
//         00486209     NOP
//         0048620a     NOP
//         0048620b     NOP
//         0048620c     NOP
//         0048620d     NOP
//         0048620e     NOP
//         0048620f     NOP
    return;
}

void RGE_RMM_Object_Generator::remove_area_from_lists(long param_1, long param_2, long param_3) {
    /* TODO: Stub */
//                              void __thiscall remove_area_from_lists(RGE_RMM_Object_Generator * th
//              void              <VOID>         <RETURN>
//              RGE_RMM_Object    ECX:4 (auto)   this
//              long              Stack[0x4]:4   param_1                   XREF[4]:     00486210(R), 00486235(W), 00486259(W), 0048628e(R)
//              long              Stack[0x8]:4   param_2                   XREF[5]:     0048621b(R), 00486261(W), 00486277(R), 00486296(R),
//                                                                                     0048629d(W)
//              long              Stack[0xc]:4   param_3                   XREF[4]:     00486214(R), 00486231(W), 0048624b(W), 00486292(R)
//                               ?remove_area_from_lists@RGE_RMM_Object_Generator@@IAEXJJJ@Z  XREF[3]:     place_avoid_objects:00486450(c),
//                               RGE_RMM_Object_Generator::remove_area_from_lists                          place_objects:0048665c(c),
//                                                                                                         place_land_objects:0048698c(c)
//                              rmm_obj.cpp:230 (31)
//         00486210     MOV        EDX,dword ptr [ESP + param_1]
//         00486214     MOV        EAX,dword ptr [ESP + param_3]
//         00486218     PUSH       EBX
//         00486219     PUSH       EBP
//         0048621a     PUSH       ESI
//         0048621b     MOV        ESI,dword ptr [ESP + param_2]
//         0048621f     MOV        EBP,this
//         00486221     MOV        EBX,EDX
//         00486223     MOV        this,ESI
//         00486225     PUSH       EDI
//         00486226     SUB        EBX,EAX
//         00486228     SUB        this,EAX
//         0048622a     LEA        EDI,[EAX + EDX*0x1]
//         0048622d     ADD        EAX,ESI
//                              rmm_obj.cpp:243 (14)
//         0048622f     TEST       EBX,EBX
//         00486231     MOV        dword ptr [ESP + param_3],EDI
//         00486235     MOV        dword ptr [ESP + param_1],EAX
//         00486239     JGE        LAB_0048623d
//         0048623b     XOR        EBX,EBX
//                               LAB_0048623d                                                 XREF[1]:     00486239(j)
//                              rmm_obj.cpp:244 (6)
//         0048623d     TEST       this,this
//         0048623f     JGE        LAB_00486243
//         00486241     XOR        this,this
//                               LAB_00486243                                                 XREF[1]:     0048623f(j)
//                              rmm_obj.cpp:245 (14)
//         00486243     MOV        EDX,dword ptr [EBP + 0x14]
//         00486246     CMP        EDI,EDX
//         00486248     JL         LAB_00486251
//         0048624a     DEC        EDX
//         0048624b     MOV        dword ptr [ESP + param_3],EDX
//         0048624f     MOV        EDI,EDX
//                               LAB_00486251                                                 XREF[1]:     00486248(j)
//                              rmm_obj.cpp:246 (14)
//         00486251     MOV        EDX,dword ptr [EBP + 0x18]
//         00486254     CMP        EAX,EDX
//         00486256     JL         LAB_0048625f
//         00486258     DEC        EDX
//         00486259     MOV        dword ptr [ESP + param_1],EDX
//         0048625d     MOV        EAX,EDX
//                               LAB_0048625f                                                 XREF[1]:     00486256(j)
//                              rmm_obj.cpp:248 (8)
//         0048625f     CMP        this,EAX
//         00486261     MOV        dword ptr [ESP + param_2],this
//         00486265     JG         LAB_004862a3
//                               LAB_00486267                                                 XREF[1]:     004862a1(j)
//                              rmm_obj.cpp:249 (13)
//         00486267     CMP        EBX,EDI
//         00486269     JG         LAB_00486296
//         0048626b     LEA        ESI,[EBX + EBX*0x2]
//         0048626e     SUB        EDI,EBX
//         00486270     SHL        ESI,0x3
//         00486273     INC        EDI
//                               LAB_00486274                                                 XREF[1]:     0048628c(j)
//                              rmm_obj.cpp:250 (47)
//         00486274     MOV        EAX,dword ptr [EBP + 0x2c]
//         00486277     MOV        this,dword ptr [ESP + param_2]
//         0048627b     MOV        EDX,dword ptr [EAX + this->_padding_*0x4]
//         0048627e     MOV        this,EBP
//         00486280     ADD        EDX,ESI
//         00486282     PUSH       EDX
//         00486283     CALL       RGE_Random_Map_Module::remove_stack_node         void remove_stack_node(RGE_Random_Map_Module
//         00486288     ADD        ESI,0x18
//         0048628b     DEC        EDI
//         0048628c     JNZ        LAB_00486274
//         0048628e     MOV        EAX,dword ptr [ESP + param_1]
//         00486292     MOV        EDI,dword ptr [ESP + param_3]
//                               LAB_00486296                                                 XREF[1]:     00486269(j)
//         00486296     MOV        this,dword ptr [ESP + param_2]
//         0048629a     INC        this
//         0048629b     CMP        this,EAX
//         0048629d     MOV        dword ptr [ESP + param_2],this
//         004862a1     JLE        LAB_00486267
//                               LAB_004862a3                                                 XREF[1]:     00486265(j)
//                              rmm_obj.cpp:251 (7)
//         004862a3     POP        EDI
//         004862a4     POP        ESI
//         004862a5     POP        EBP
//         004862a6     POP        EBX
//         004862a7     RET        0xc
//         004862aa     ??         90h
//         004862ab     NOP
//         004862ac     NOP
//         004862ad     NOP
//         004862ae     NOP
//         004862af     NOP
    return;
}

void RGE_RMM_Object_Generator::place_avoid_objects(RGE_Object_Info_Line* param_1, long param_2) {
    /* TODO: Stub */
//                              void __thiscall place_avoid_objects(RGE_RMM_Object_Generator * this,
//              void              <VOID>         <RETURN>
//              RGE_RMM_Object    ECX:4 (auto)   this
//              RGE_Object_Inf    Stack[0x4]:4   param_1                   XREF[5]:     004862de(R), 004863b6(W), 0048640e(R), 00486418(W),
//                                                                                     0048641c(R)
//              long              Stack[0x8]:4   param_2
//              Map_Stack         Stack[-0x1c]   obj_stack                 XREF[1,4]:   00486342(*), 0048630e(*), 00486320(*), 0048635a(*),
//                                                                                     004864d2(*)
//              float             Stack[-0x20]:4 zone                      XREF[4]:     004863c5(W), 004863c9(R), 004863f6(W), 004863fa(R)
//              undefined4        Stack[-0x24]:4 local_24                  XREF[2]:     0048634c(W), 0048636f(R)
//              long              Stack[-0x28]:4 count                     XREF[4]:     004863ab(W), 004863dd(R), 004863e7(W), 00486420(R)
//              float             Stack[-0x2c]:4 tile_x                    XREF[3]:     00486355(*), 00486385(R), 004863a2(R)
//              long              Stack[-0x30]:4 x                         XREF[3]:     00486350(*), 00486389(R), 004863af(R)
//              long              Stack[-0x34]:4 y
//                               ?place_avoid_objects@RGE_RMM_Object_Generator@@IAEXAAURGE_O  XREF[1]:     generate_objects:00485efc(c)
//                               RGE_RMM_Object_Generator::place_avoid_objects
//                              rmm_obj.cpp:255 (3)
//         004862b0     SUB        ESP,0x30
//                              rmm_obj.cpp:269 (11)
//         004862b3     MOV        EAX,0x1010101
//         004862b8     PUSH       EBX
//         004862b9     PUSH       EBP
//         004862ba     PUSH       ESI
//         004862bb     MOV        ESI,this
//         004862bd     PUSH       EDI
//                              rmm_obj.cpp:270 (40)
//         004862be     XOR        EBP,EBP
//         004862c0     MOV        this,dword ptr [ESI + 0x18]
//         004862c3     MOV        EDI,dword ptr [ESI + 0x20]
//         004862c6     IMUL       this,dword ptr [ESI + 0x14]
//         004862ca     MOV        EDX,this
//         004862cc     SHR        this,0x2
//         004862cf     STOSD.REP  ES:EDI
//         004862d1     MOV        this,EDX
//         004862d3     AND        this,0x3
//         004862d6     STOSB.REP  ES:EDI
//         004862d8     MOV        EAX,dword ptr [ESI + 0x18f8]
//         004862de     MOV        EDI,dword ptr [ESP + param_1]
//         004862e2     TEST       EAX,EAX
//         004862e4     JLE        LAB_0048630e
//                              rmm_obj.cpp:269 (6)
//         004862e6     LEA        EBX,[ESI + 0x12c8]
//                               LAB_004862ec                                                 XREF[1]:     0048630c(j)
//                              rmm_obj.cpp:271 (34)
//         004862ec     MOV        EAX,dword ptr [EDI + 0x24]
//         004862ef     MOV        this,dword ptr [EBX + 0x4]
//         004862f2     MOV        EDX,dword ptr [EBX]
//         004862f4     PUSH       0x0
//         004862f6     PUSH       EAX
//         004862f7     PUSH       this
//         004862f8     PUSH       EDX
//         004862f9     MOV        this,ESI
//         004862fb     CALL       RGE_RMM_Object_Generator::set_search_area        void set_search_area(RGE_RMM_Object_Generator
//         00486300     MOV        EAX,dword ptr [ESI + 0x18f8]
//         00486306     INC        EBP
//         00486307     ADD        EBX,0x10
//         0048630a     CMP        EBP,EAX
//         0048630c     JL         LAB_004862ec
//                               LAB_0048630e                                                 XREF[1]:     004862e4(j)
//                              rmm_obj.cpp:273 (12)
//         0048630e     LEA        EAX=>obj_stack.y,[ESP + 0x28]
//         00486312     MOV        this,ESI
//         00486314     PUSH       EAX
//         00486315     CALL       RGE_Random_Map_Module::init_stack                void init_stack(RGE_Random_Map_Module * this,
//                              rmm_obj.cpp:274 (20)
//         0048631a     PUSH       -0x1
//         0048631c     PUSH       -0x1
//         0048631e     PUSH       -0x1
//         00486320     LEA        this=>obj_stack.y,[ESP + 0x34]
//         00486324     PUSH       -0x1
//         00486326     PUSH       this
//         00486327     MOV        this,ESI
//         00486329     CALL       RGE_RMM_Object_Generator::make_placement_stack   void make_placement_stack(RGE_RMM_Object_Gene
//                              rmm_obj.cpp:277 (3)
//         0048632e     MOV        EAX,dword ptr [EDI + 0x1c]
//                              rmm_obj.cpp:282 (17)
//         00486331     MOV        this,dword ptr [ESI + 0x30]
//         00486334     XOR        EDX,EDX
//         00486336     CMP        EAX,-0x1
//         00486339     SETLE      DL
//         0048633c     DEC        EDX
//         0048633d     AND        EAX,EDX
//         0048633f     MOV        EDX,dword ptr [ECX + this+0x40]
//                              rmm_obj.cpp:286 (57)
//         00486342     LEA        this=>obj_stack,[ESP + 0x24]
//         00486346     MOV        EBP,dword ptr [EDX + EAX*0x4]
//         00486349     MOV        EAX,dword ptr [EDI + 0x14]
//         0048634c     MOV        dword ptr [ESP + local_24],EAX
//         00486350     LEA        EDX=>x,[ESP + 0x10]
//         00486354     PUSH       this
//         00486355     LEA        EAX=>tile_x,[ESP + 0x18]
//         00486359     PUSH       EDX
//         0048635a     LEA        this=>obj_stack.y,[ESP + 0x30]
//         0048635e     PUSH       EAX
//         0048635f     PUSH       this
//         00486360     MOV        this,ESI
//         00486362     CALL       RGE_Random_Map_Module::pop_stack                 Map_Stack * pop_stack(RGE_Random_Map_Module *
//         00486367     TEST       EAX,EAX
//         00486369     JZ         LAB_004864d2
//                               LAB_0048636f                                                 XREF[1]:     004864cc(j)
//         0048636f     MOV        EAX,dword ptr [ESP + local_24]
//         00486373     TEST       EAX,EAX
//         00486375     JLE        LAB_004864d2
//                              rmm_obj.cpp:287 (39)
//         0048637b     MOV        this,dword ptr [EDI + 0x4]
//         0048637e     TEST       this,this
//         00486380     JL         LAB_004863a2
//         00486382     MOV        EDX,dword ptr [ESI + 0x10]
//         00486385     MOV        EAX,dword ptr [ESP + tile_x]
//         00486389     MOV        EBX,dword ptr [ESP + x]
//         0048638d     LEA        EAX,[EAX + EAX*0x2]
//         00486390     MOV        EDX,dword ptr [EDX + EBX*0x4]
//         00486393     MOV        AL,byte ptr [EDX + EAX*0x8 + 0x5]
//         00486397     AND        EAX,0x1f
//         0048639a     CMP        EAX,this
//         0048639c     JNZ        LAB_004864af
//                               LAB_004863a2                                                 XREF[1]:     00486380(j)
//                              rmm_obj.cpp:292 (13)
//         004863a2     FILD       dword ptr [ESP + tile_x]
//         004863a6     MOV        this,dword ptr [EDI]
//         004863a8     MOV        EDX,dword ptr [EBP + 0x24]
//         004863ab     FSTP       float ptr [ESP + count]
//                              rmm_obj.cpp:293 (11)
//         004863af     FILD       dword ptr [ESP + x]
//         004863b3     MOV        EBX,dword ptr [EDX + this->_padding_*0x4]
//         004863b6     FSTP       float ptr [ESP + param_1]
//                              rmm_obj.cpp:295 (35)
//         004863ba     FLD        float ptr [EBX + 0x30]
//         004863bd     CALL       __ftol                                           undefined __ftol()
//         004863c2     MOVSX      EAX,AX
//         004863c5     MOV        dword ptr [ESP + zone],EAX
//         004863c9     FILD       dword ptr [ESP + zone]
//         004863cd     FSUBR      float ptr [EBX + 0x30]
//         004863d0     FCOMP      float ptr [DAT_00571edc]                         = align(7)
//         004863d6     FNSTSW     AX
//         004863d8     TEST       AH,0x41
//         004863db     JNZ        LAB_004863eb
//                              rmm_obj.cpp:296 (14)
//         004863dd     FLD        float ptr [ESP + count]
//         004863e1     FSUB       float ptr [null_00571ee0]                        = align(3)
//         004863e7     FSTP       float ptr [ESP + count]
//                               LAB_004863eb                                                 XREF[1]:     004863db(j)
//                              rmm_obj.cpp:298 (35)
//         004863eb     FLD        float ptr [EBX + 0x34]
//         004863ee     CALL       __ftol                                           undefined __ftol()
//         004863f3     MOVSX      this,AX
//         004863f6     MOV        dword ptr [ESP + zone],this
//         004863fa     FILD       dword ptr [ESP + zone]
//         004863fe     FSUBR      float ptr [EBX + 0x34]
//         00486401     FCOMP      float ptr [DAT_00571edc]                         = align(7)
//         00486407     FNSTSW     AX
//         00486409     TEST       AH,0x41
//         0048640c     JNZ        LAB_0048641c
//                              rmm_obj.cpp:299 (14)
//         0048640e     FLD        float ptr [ESP + param_1]
//         00486412     FSUB       float ptr [null_00571ee0]                        = align(3)
//         00486418     FSTP       float ptr [ESP + param_1]
//                               LAB_0048641c                                                 XREF[1]:     0048640c(j)
//                              rmm_obj.cpp:302 (36)
//         0048641c     MOV        EAX,dword ptr [ESP + param_1]
//         00486420     MOV        this,dword ptr [ESP + count]
//         00486424     MOV        EDX,dword ptr [EBX]
//         00486426     PUSH       0x1
//         00486428     PUSH       0x0
//         0048642a     PUSH       0x1
//         0048642c     PUSH       0x1
//         0048642e     PUSH       0x1
//         00486430     PUSH       0x0
//         00486432     PUSH       0x0
//         00486434     PUSH       EAX
//         00486435     PUSH       this
//         00486436     PUSH       EBP
//         00486437     MOV        this,EBX
//         00486439     CALL       dword ptr [EDX + 0x20]
//         0048643c     TEST       AL,AL
//         0048643e     JNZ        LAB_004864af
//                              rmm_obj.cpp:304 (21)
//         00486440     MOV        EDX,dword ptr [EDI + 0x2c]
//         00486443     MOV        EAX,dword ptr [ESP + 0x10]
//         00486447     MOV        this,dword ptr [ESP + 0x14]
//         0048644b     PUSH       EDX
//         0048644c     PUSH       EAX=>DAT_fffffff8
//         0048644d     PUSH       this=>DAT_fffffff4
//         0048644e     MOV        this,ESI
//         00486450     CALL       RGE_RMM_Object_Generator::remove_area_from_lists void remove_area_from_lists(RGE_RMM_Object_Ge
//                              rmm_obj.cpp:305 (16)
//         00486455     XOR        EAX,EAX
//         00486457     MOV        AL,byte ptr [EDI + 0x8]
//         0048645a     SUB        EAX,0x0
//         0048645d     JZ         LAB_0048648f
//         0048645f     DEC        EAX
//         00486460     JZ         LAB_0048647a
//         00486462     DEC        EAX
//         00486463     JNZ        LAB_004864ab
//                              rmm_obj.cpp:316 (19)
//         00486465     MOV        EDX,dword ptr [ESP + 0x10]
//         00486469     MOV        EAX,dword ptr [ESP + 0x14]
//         0048646d     PUSH       EBP
//         0048646e     PUSH       EDX=>DAT_fffffff8
//         0048646f     PUSH       EAX=>DAT_fffffff4
//         00486470     PUSH       EDI=>DAT_fffffff0
//         00486471     MOV        this,ESI
//         00486473     CALL       RGE_RMM_Object_Generator::place_cluster          void place_cluster(RGE_RMM_Object_Generator *
//                              rmm_obj.cpp:317 (2)
//         00486478     JMP        LAB_004864ab
//                               LAB_0048647a                                                 XREF[1]:     00486460(j)
//                              rmm_obj.cpp:312 (19)
//         0048647a     MOV        this,dword ptr [ESP + 0x10]
//         0048647e     MOV        EDX,dword ptr [ESP + 0x14]
//         00486482     PUSH       EBP
//         00486483     PUSH       this=>DAT_fffffff8
//         00486484     PUSH       EDX=>DAT_fffffff4
//         00486485     PUSH       EDI=>DAT_fffffff0
//         00486486     MOV        this,ESI
//         00486488     CALL       RGE_RMM_Object_Generator::place_group            void place_group(RGE_RMM_Object_Generator * t
//                              rmm_obj.cpp:313 (2)
//         0048648d     JMP        LAB_004864ab
//                               LAB_0048648f                                                 XREF[1]:     0048645d(j)
//                              rmm_obj.cpp:308 (28)
//         0048648f     MOV        this,dword ptr [ESP + 0x44]
//         00486493     MOV        EDX,dword ptr [ESP + 0x18]
//         00486497     MOV        EAX,dword ptr [EBP]
//         0048649a     PUSH       0x1
//         0048649c     PUSH       0x0=>DAT_fffffff8
//         0048649e     PUSH       this=>DAT_fffffff4
//         0048649f     MOV        this,dword ptr [EDI]
//         004864a1     PUSH       EDX=>DAT_fffffff0
//         004864a2     PUSH       this
//         004864a3     MOV        this,EBP
//         004864a5     CALL       dword ptr [EAX + 0x94]
//                               LAB_004864ab                                                 XREF[3]:     00486463(j), 00486478(j),
//                                                                                                         0048648d(j)
//                              rmm_obj.cpp:319 (39)
//         004864ab     DEC        dword ptr [ESP + 0x1c]
//                               LAB_004864af                                                 XREF[2]:     0048639c(j), 0048643e(j)
//         004864af     LEA        EDX,[ESP + 0x24]
//         004864b3     LEA        EAX,[ESP + 0x10]
//         004864b7     PUSH       EDX
//         004864b8     LEA        this,[ESP + 0x18]
//         004864bc     PUSH       EAX=>DAT_fffffff8
//         004864bd     LEA        EDX,[ESP + 0x30]
//         004864c1     PUSH       this=>DAT_fffffff4
//         004864c2     PUSH       EDX=>DAT_fffffff0
//         004864c3     MOV        this,ESI
//         004864c5     CALL       RGE_Random_Map_Module::pop_stack                 Map_Stack * pop_stack(RGE_Random_Map_Module *
//         004864ca     TEST       EAX,EAX
//         004864cc     JNZ        LAB_0048636f
//                               LAB_004864d2                                                 XREF[2]:     00486369(j), 00486375(j)
//                              rmm_obj.cpp:323 (12)
//         004864d2     LEA        EAX=>obj_stack.y,[ESP + 0x28]
//         004864d6     MOV        this,ESI
//         004864d8     PUSH       EAX
//         004864d9     CALL       RGE_Random_Map_Module::deinit_stack              void deinit_stack(RGE_Random_Map_Module * thi
//                              rmm_obj.cpp:324 (10)
//         004864de     POP        EDI
//         004864df     POP        ESI
//         004864e0     POP        EBP
//         004864e1     POP        EBX
//         004864e2     ADD        ESP,0x30
//         004864e5     RET        0x8
//         004864e8     ??         90h
//         004864e9     NOP
//         004864ea     NOP
//         004864eb     NOP
//         004864ec     NOP
//         004864ed     NOP
//         004864ee     NOP
//         004864ef     NOP
    return;
}

void RGE_RMM_Object_Generator::place_objects(RGE_Object_Info_Line* param_1) {
    /* TODO: Stub */
//                              void __thiscall place_objects(RGE_RMM_Object_Generator * this, RGE_O
//              void              <VOID>         <RETURN>
//              RGE_RMM_Object    ECX:4 (auto)   this
//              RGE_Object_Inf    Stack[0x4]:4   param_1                   XREF[5]:     00486536(R), 004865c2(W), 0048661a(R), 00486624(W),
//                                                                                     00486628(R)
//              Map_Stack         Stack[-0x1c]   obj_stack                 XREF[1,4]:   0048654e(*), 00486516(*), 00486528(*), 00486566(*),
//                                                                                     004866dd(*)
//              float             Stack[-0x20]:4 zone                      XREF[4]:     004865d1(W), 004865d5(R), 00486602(W), 00486606(R)
//              undefined4        Stack[-0x24]:4 local_24                  XREF[2]:     00486558(W), 0048657b(R)
//              long              Stack[-0x28]:4 count                     XREF[4]:     004865b7(W), 004865e9(R), 004865f3(W), 0048662c(R)
//              float             Stack[-0x2c]:4 tile_x                    XREF[3]:     00486561(*), 00486591(R), 004865ae(R)
//              long              Stack[-0x30]:4 x                         XREF[3]:     0048655c(*), 00486595(R), 004865bb(R)
//              long              Stack[-0x34]:4 y
//                               ?place_objects@RGE_RMM_Object_Generator@@IAEXAAURGE_Object_  XREF[1]:     generate_objects:00485ee4(c)
//                               RGE_RMM_Object_Generator::place_objects
//                              rmm_obj.cpp:328 (9)
//         004864f0     SUB        ESP,0x30
//         004864f3     PUSH       EBX
//         004864f4     PUSH       EBP
//         004864f5     MOV        EBP,this
//         004864f7     PUSH       ESI
//         004864f8     PUSH       EDI
//                              rmm_obj.cpp:340 (29)
//         004864f9     MOV        EAX,0x1010101
//         004864fe     MOV        this,dword ptr [EBP + 0x14]
//         00486501     MOV        EDI,dword ptr [EBP + 0x20]
//         00486504     IMUL       this,dword ptr [EBP + 0x18]
//         00486508     MOV        EDX,this
//         0048650a     SHR        this,0x2
//         0048650d     STOSD.REP  ES:EDI
//         0048650f     MOV        this,EDX
//         00486511     AND        this,0x3
//         00486514     STOSB.REP  ES:EDI
//                              rmm_obj.cpp:341 (12)
//         00486516     LEA        EAX=>obj_stack.y,[ESP + 0x28]
//         0048651a     MOV        this,EBP
//         0048651c     PUSH       EAX
//         0048651d     CALL       RGE_Random_Map_Module::init_stack                void init_stack(RGE_Random_Map_Module * this,
//                              rmm_obj.cpp:342 (20)
//         00486522     PUSH       -0x1
//         00486524     PUSH       -0x1
//         00486526     PUSH       -0x1
//         00486528     LEA        this=>obj_stack.y,[ESP + 0x34]
//         0048652c     PUSH       -0x1
//         0048652e     PUSH       this
//         0048652f     MOV        this,EBP
//         00486531     CALL       RGE_RMM_Object_Generator::make_placement_stack   void make_placement_stack(RGE_RMM_Object_Gene
//                              rmm_obj.cpp:345 (4)
//         00486536     MOV        EDI,dword ptr [ESP + param_1]
//                              rmm_obj.cpp:350 (20)
//         0048653a     MOV        this,dword ptr [EBP + 0x30]
//         0048653d     XOR        EDX,EDX
//         0048653f     MOV        EAX,dword ptr [EDI + 0x1c]
//         00486542     CMP        EAX,-0x1
//         00486545     SETLE      DL
//         00486548     DEC        EDX
//         00486549     AND        EAX,EDX
//         0048654b     MOV        EDX,dword ptr [ECX + this+0x40]
//                              rmm_obj.cpp:354 (57)
//         0048654e     LEA        this=>obj_stack,[ESP + 0x24]
//         00486552     MOV        EBX,dword ptr [EDX + EAX*0x4]
//         00486555     MOV        EAX,dword ptr [EDI + 0x14]
//         00486558     MOV        dword ptr [ESP + local_24],EAX
//         0048655c     LEA        EDX=>x,[ESP + 0x10]
//         00486560     PUSH       this
//         00486561     LEA        EAX=>tile_x,[ESP + 0x18]
//         00486565     PUSH       EDX
//         00486566     LEA        this=>obj_stack.y,[ESP + 0x30]
//         0048656a     PUSH       EAX
//         0048656b     PUSH       this
//         0048656c     MOV        this,EBP
//         0048656e     CALL       RGE_Random_Map_Module::pop_stack                 Map_Stack * pop_stack(RGE_Random_Map_Module *
//         00486573     TEST       EAX,EAX
//         00486575     JZ         LAB_004866dd
//                               LAB_0048657b                                                 XREF[1]:     004866d7(j)
//         0048657b     MOV        EAX,dword ptr [ESP + local_24]
//         0048657f     TEST       EAX,EAX
//         00486581     JLE        LAB_004866dd
//                              rmm_obj.cpp:355 (39)
//         00486587     MOV        this,dword ptr [EDI + 0x4]
//         0048658a     TEST       this,this
//         0048658c     JL         LAB_004865ae
//         0048658e     MOV        EDX,dword ptr [EBP + 0x10]
//         00486591     MOV        EAX,dword ptr [ESP + tile_x]
//         00486595     MOV        ESI,dword ptr [ESP + x]
//         00486599     LEA        EAX,[EAX + EAX*0x2]
//         0048659c     MOV        EDX,dword ptr [EDX + ESI*0x4]
//         0048659f     MOV        AL,byte ptr [EDX + EAX*0x8 + 0x5]
//         004865a3     AND        EAX,0x1f
//         004865a6     CMP        EAX,this
//         004865a8     JNZ        LAB_004866ba
//                               LAB_004865ae                                                 XREF[1]:     0048658c(j)
//                              rmm_obj.cpp:360 (13)
//         004865ae     FILD       dword ptr [ESP + tile_x]
//         004865b2     MOV        this,dword ptr [EDI]
//         004865b4     MOV        EDX,dword ptr [EBX + 0x24]
//         004865b7     FSTP       float ptr [ESP + count]
//                              rmm_obj.cpp:361 (11)
//         004865bb     FILD       dword ptr [ESP + x]
//         004865bf     MOV        ESI,dword ptr [EDX + this->_padding_*0x4]
//         004865c2     FSTP       float ptr [ESP + param_1]
//                              rmm_obj.cpp:363 (35)
//         004865c6     FLD        float ptr [ESI + 0x30]
//         004865c9     CALL       __ftol                                           undefined __ftol()
//         004865ce     MOVSX      EAX,AX
//         004865d1     MOV        dword ptr [ESP + zone],EAX
//         004865d5     FILD       dword ptr [ESP + zone]
//         004865d9     FSUBR      float ptr [ESI + 0x30]
//         004865dc     FCOMP      float ptr [DAT_00571edc]                         = align(7)
//         004865e2     FNSTSW     AX
//         004865e4     TEST       AH,0x41
//         004865e7     JNZ        LAB_004865f7
//                              rmm_obj.cpp:364 (14)
//         004865e9     FLD        float ptr [ESP + count]
//         004865ed     FSUB       float ptr [null_00571ee0]                        = align(3)
//         004865f3     FSTP       float ptr [ESP + count]
//                               LAB_004865f7                                                 XREF[1]:     004865e7(j)
//                              rmm_obj.cpp:366 (35)
//         004865f7     FLD        float ptr [ESI + 0x34]
//         004865fa     CALL       __ftol                                           undefined __ftol()
//         004865ff     MOVSX      this,AX
//         00486602     MOV        dword ptr [ESP + zone],this
//         00486606     FILD       dword ptr [ESP + zone]
//         0048660a     FSUBR      float ptr [ESI + 0x34]
//         0048660d     FCOMP      float ptr [DAT_00571edc]                         = align(7)
//         00486613     FNSTSW     AX
//         00486615     TEST       AH,0x41
//         00486618     JNZ        LAB_00486628
//                              rmm_obj.cpp:367 (14)
//         0048661a     FLD        float ptr [ESP + param_1]
//         0048661e     FSUB       float ptr [null_00571ee0]                        = align(3)
//         00486624     FSTP       float ptr [ESP + param_1]
//                               LAB_00486628                                                 XREF[1]:     00486618(j)
//                              rmm_obj.cpp:370 (36)
//         00486628     MOV        EAX,dword ptr [ESP + param_1]
//         0048662c     MOV        this,dword ptr [ESP + count]
//         00486630     MOV        EDX,dword ptr [ESI]
//         00486632     PUSH       0x1
//         00486634     PUSH       0x0
//         00486636     PUSH       0x1
//         00486638     PUSH       0x1
//         0048663a     PUSH       0x1
//         0048663c     PUSH       0x0
//         0048663e     PUSH       0x0
//         00486640     PUSH       EAX
//         00486641     PUSH       this
//         00486642     PUSH       EBX
//         00486643     MOV        this,ESI
//         00486645     CALL       dword ptr [EDX + 0x20]
//         00486648     TEST       AL,AL
//         0048664a     JNZ        LAB_004866ba
//                              rmm_obj.cpp:372 (21)
//         0048664c     MOV        EDX,dword ptr [EDI + 0x2c]
//         0048664f     MOV        EAX,dword ptr [ESP + 0x10]
//         00486653     MOV        this,dword ptr [ESP + 0x14]
//         00486657     PUSH       EDX
//         00486658     PUSH       EAX=>DAT_fffffff8
//         00486659     PUSH       this=>DAT_fffffff4
//         0048665a     MOV        this,EBP
//         0048665c     CALL       RGE_RMM_Object_Generator::remove_area_from_lists void remove_area_from_lists(RGE_RMM_Object_Ge
//                              rmm_obj.cpp:373 (16)
//         00486661     XOR        EAX,EAX
//         00486663     MOV        AL,byte ptr [EDI + 0x8]
//         00486666     SUB        EAX,0x0
//         00486669     JZ         LAB_0048669b
//         0048666b     DEC        EAX
//         0048666c     JZ         LAB_00486686
//         0048666e     DEC        EAX
//         0048666f     JNZ        LAB_004866b6
//                              rmm_obj.cpp:384 (19)
//         00486671     MOV        EDX,dword ptr [ESP + 0x10]
//         00486675     MOV        EAX,dword ptr [ESP + 0x14]
//         00486679     PUSH       EBX
//         0048667a     PUSH       EDX=>DAT_fffffff8
//         0048667b     PUSH       EAX=>DAT_fffffff4
//         0048667c     PUSH       EDI=>DAT_fffffff0
//         0048667d     MOV        this,EBP
//         0048667f     CALL       RGE_RMM_Object_Generator::place_cluster          void place_cluster(RGE_RMM_Object_Generator *
//                              rmm_obj.cpp:385 (2)
//         00486684     JMP        LAB_004866b6
//                               LAB_00486686                                                 XREF[1]:     0048666c(j)
//                              rmm_obj.cpp:380 (19)
//         00486686     MOV        this,dword ptr [ESP + 0x10]
//         0048668a     MOV        EDX,dword ptr [ESP + 0x14]
//         0048668e     PUSH       EBX
//         0048668f     PUSH       this=>DAT_fffffff8
//         00486690     PUSH       EDX=>DAT_fffffff4
//         00486691     PUSH       EDI=>DAT_fffffff0
//         00486692     MOV        this,EBP
//         00486694     CALL       RGE_RMM_Object_Generator::place_group            void place_group(RGE_RMM_Object_Generator * t
//                              rmm_obj.cpp:381 (2)
//         00486699     JMP        LAB_004866b6
//                               LAB_0048669b                                                 XREF[1]:     00486669(j)
//                              rmm_obj.cpp:376 (27)
//         0048669b     MOV        this,dword ptr [ESP + 0x44]
//         0048669f     MOV        EDX,dword ptr [ESP + 0x18]
//         004866a3     MOV        EAX,dword ptr [EBX]
//         004866a5     PUSH       0x1
//         004866a7     PUSH       0x0=>DAT_fffffff8
//         004866a9     PUSH       this=>DAT_fffffff4
//         004866aa     MOV        this,dword ptr [EDI]
//         004866ac     PUSH       EDX=>DAT_fffffff0
//         004866ad     PUSH       this
//         004866ae     MOV        this,EBX
//         004866b0     CALL       dword ptr [EAX + 0x94]
//                               LAB_004866b6                                                 XREF[3]:     0048666f(j), 00486684(j),
//                                                                                                         00486699(j)
//                              rmm_obj.cpp:387 (39)
//         004866b6     DEC        dword ptr [ESP + 0x1c]
//                               LAB_004866ba                                                 XREF[2]:     004865a8(j), 0048664a(j)
//         004866ba     LEA        EDX,[ESP + 0x24]
//         004866be     LEA        EAX,[ESP + 0x10]
//         004866c2     PUSH       EDX
//         004866c3     LEA        this,[ESP + 0x18]
//         004866c7     PUSH       EAX=>DAT_fffffff8
//         004866c8     LEA        EDX,[ESP + 0x30]
//         004866cc     PUSH       this=>DAT_fffffff4
//         004866cd     PUSH       EDX=>DAT_fffffff0
//         004866ce     MOV        this,EBP
//         004866d0     CALL       RGE_Random_Map_Module::pop_stack                 Map_Stack * pop_stack(RGE_Random_Map_Module *
//         004866d5     TEST       EAX,EAX
//         004866d7     JNZ        LAB_0048657b
//                               LAB_004866dd                                                 XREF[2]:     00486575(j), 00486581(j)
//                              rmm_obj.cpp:391 (12)
//         004866dd     LEA        EAX=>obj_stack.y,[ESP + 0x28]
//         004866e1     MOV        this,EBP
//         004866e3     PUSH       EAX
//         004866e4     CALL       RGE_Random_Map_Module::deinit_stack              void deinit_stack(RGE_Random_Map_Module * thi
//                              rmm_obj.cpp:392 (10)
//         004866e9     POP        EDI
//         004866ea     POP        ESI
//         004866eb     POP        EBP
//         004866ec     POP        EBX
//         004866ed     ADD        ESP,0x30
//         004866f0     RET        0x4
//         004866f3     ??         90h
//         004866f4     NOP
//         004866f5     NOP
//         004866f6     NOP
//         004866f7     NOP
//         004866f8     NOP
//         004866f9     NOP
//         004866fa     NOP
//         004866fb     NOP
//         004866fc     NOP
//         004866fd     NOP
//         004866fe     NOP
//         004866ff     NOP
    return;
}

void RGE_RMM_Object_Generator::place_land_objects(RGE_Object_Info_Line* param_1, long param_2, long param_3, long param_4, long param_5, long param_6) {
    /* TODO: Stub */
//                              void __thiscall place_land_objects(RGE_RMM_Object_Generator * this,
//              void              <VOID>         <RETURN>
//              RGE_RMM_Object    ECX:4 (auto)   this
//              RGE_Object_Inf    Stack[0x4]:4   param_1                   XREF[3]:     004867d3(R), 0048684a(W), 0048686d(R)
//              long              Stack[0x8]:4   param_2                   XREF[6]:     00486703(R), 004867c1(R), 004868f1(W), 00486949(R),
//                                                                                     00486953(W), 00486957(R)
//              long              Stack[0xc]:4   param_3                   XREF[5]:     0048670e(R), 004867bb(R), 0048682e(R), 0048683f(W),
//                                                                                     0048688c(R)
//              long              Stack[0x10]:4  param_4                   XREF[7]:     00486709(R), 00486853(*), 0048687d(R), 0048689d(R),
//                                                                                     004868bd(R), 004868dd(R), 00486a27(*)
//              long              Stack[0x14]:4  param_5                   XREF[5]:     004867b7(R), 004868e6(W), 00486918(R), 00486922(W),
//                                                                                     0048695b(R)
//              long              Stack[0x18]:4  param_6                   XREF[3]:     004867e1(R), 00486836(W), 00486881(R)
//              Map_Stack         Stack[-0x1c]   obj_stack                 XREF[1,5]:   00486812(*), 004867ab(*), 004867c6(*), 00486858(*),
//                                                                                     00486a2c(*), 00486a41(*)
//              int               Stack[-0x20]:4 temp                      XREF[2]:     00486846(*), 00486a1e(*)
//              float             Stack[-0x24]:4 zone                      XREF[4]:     00486900(W), 00486904(R), 00486931(W), 00486935(R)
//              undefined4        Stack[-0x28]:4 local_28                  XREF[3]:     00486733(W), 0048675d(W), 004868d3(R)
//              long              Stack[-0x2c]:4 min_y1                    XREF[3]:     0048672b(W), 00486741(W), 004868cd(R)
//              long              Stack[-0x30]:4 min_y0                    XREF[3]:     0048672f(W), 0048674f(W), 004868c7(R)
//              long              Stack[-0x34]:4 min_x1                    XREF[3]:     00486727(W), 00486739(W), 004868c1(R)
//              long              Stack[-0x38]:4 min_x0                    XREF[5]:     0048684e(*), 00486879(R), 00486899(R), 004868ea(R),
//                                                                                     00486a22(*)
//              long              Stack[-0x3c]:4 y
//                               ?place_land_objects@RGE_RMM_Object_Generator@@IAEXAAURGE_Ob  XREF[1]:     generate_objects:00485ec2(c)
//                               RGE_RMM_Object_Generator::place_land_objects
//                              rmm_obj.cpp:396 (3)
//         00486700     SUB        ESP,0x38
//                              rmm_obj.cpp:417 (11)
//         00486703     MOV        EDX,dword ptr [ESP + param_2]
//         00486707     PUSH       EBX
//         00486708     PUSH       EBP
//         00486709     MOV        EBP,dword ptr [ESP + param_4]
//         0048670d     PUSH       ESI
//                              rmm_obj.cpp:418 (11)
//         0048670e     MOV        ESI,dword ptr [ESP + param_3]
//         00486712     MOV        EBX,this
//         00486714     PUSH       EDI
//         00486715     MOV        EAX,EDX
//         00486717     MOV        this,ESI
//                              rmm_obj.cpp:420 (6)
//         00486719     LEA        EDI,[EBP + ESI*0x1]
//         0048671d     SUB        EAX,EBP
//                              rmm_obj.cpp:422 (30)
//         0048671f     XOR        ESI,ESI
//         00486721     SUB        this,EBP
//         00486723     ADD        EDX,EBP
//         00486725     CMP        EAX,ESI
//         00486727     MOV        dword ptr [ESP + min_x1],EAX
//         0048672b     MOV        dword ptr [ESP + min_y1],this
//         0048672f     MOV        dword ptr [ESP + min_y0],EDX
//         00486733     MOV        dword ptr [ESP + local_28],EDI
//         00486737     JGE        LAB_0048673d
//         00486739     MOV        dword ptr [ESP + min_x1],ESI
//                               LAB_0048673d                                                 XREF[1]:     00486737(j)
//                              rmm_obj.cpp:423 (8)
//         0048673d     CMP        this,ESI
//         0048673f     JGE        LAB_00486745
//         00486741     MOV        dword ptr [ESP + min_y1],ESI
//                               LAB_00486745                                                 XREF[1]:     0048673f(j)
//                              rmm_obj.cpp:424 (14)
//         00486745     MOV        EAX,dword ptr [EBX + 0x14]
//         00486748     CMP        EDX,EAX
//         0048674a     JL         LAB_00486753
//         0048674c     LEA        this,[EAX + -0x1]
//         0048674f     MOV        dword ptr [ESP + min_y0],this
//                               LAB_00486753                                                 XREF[1]:     0048674a(j)
//                              rmm_obj.cpp:425 (14)
//         00486753     MOV        this,dword ptr [EBX + 0x18]
//         00486756     CMP        EDI,this
//         00486758     JL         LAB_00486761
//         0048675a     LEA        EDX,[this->_padding_ + -0x1]
//         0048675d     MOV        dword ptr [ESP + local_28],EDX
//                               LAB_00486761                                                 XREF[1]:     00486758(j)
//                              rmm_obj.cpp:427 (25)
//         00486761     IMUL       this,EAX
//         00486764     MOV        EDI,dword ptr [EBX + 0x20]
//         00486767     MOV        EDX,this
//         00486769     MOV        EAX,0x1010101
//         0048676e     SHR        this,0x2
//         00486771     STOSD.REP  ES:EDI
//         00486773     MOV        this,EDX
//         00486775     AND        this,0x3
//         00486778     STOSB.REP  ES:EDI
//                              rmm_obj.cpp:428 (12)
//         0048677a     MOV        EAX,dword ptr [EBX + 0x18f8]
//         00486780     XOR        EDI,EDI
//         00486782     CMP        EAX,ESI
//         00486784     JLE        LAB_004867ab
//                              rmm_obj.cpp:427 (6)
//         00486786     LEA        ESI,[EBX + 0x12c8]
//                               LAB_0048678c                                                 XREF[1]:     004867a9(j)
//                              rmm_obj.cpp:429 (31)
//         0048678c     MOV        EAX,dword ptr [ESI + 0x4]
//         0048678f     MOV        this,dword ptr [ESI]
//         00486791     PUSH       0x0
//         00486793     PUSH       EBP
//         00486794     PUSH       EAX
//         00486795     PUSH       this
//         00486796     MOV        this,EBX
//         00486798     CALL       RGE_RMM_Object_Generator::set_search_area        void set_search_area(RGE_RMM_Object_Generator
//         0048679d     MOV        EAX,dword ptr [EBX + 0x18f8]
//         004867a3     INC        EDI
//         004867a4     ADD        ESI,0x10
//         004867a7     CMP        EDI,EAX
//         004867a9     JL         LAB_0048678c
//                               LAB_004867ab                                                 XREF[1]:     00486784(j)
//                              rmm_obj.cpp:431 (12)
//         004867ab     LEA        EDX=>obj_stack.y,[ESP + 0x30]
//         004867af     MOV        this,EBX
//         004867b1     PUSH       EDX
//         004867b2     CALL       RGE_Random_Map_Module::init_stack                void init_stack(RGE_Random_Map_Module * this,
//                              rmm_obj.cpp:432 (28)
//         004867b7     MOV        EAX,dword ptr [ESP + param_5]
//         004867bb     MOV        this,dword ptr [ESP + param_3]
//         004867bf     PUSH       EAX
//         004867c0     PUSH       EBP
//         004867c1     MOV        EBP,dword ptr [ESP + param_2]
//         004867c5     PUSH       this
//         004867c6     LEA        EDX=>obj_stack.y,[ESP + 0x3c]
//         004867ca     PUSH       EBP
//         004867cb     PUSH       EDX
//         004867cc     MOV        this,EBX
//         004867ce     CALL       RGE_RMM_Object_Generator::make_placement_stack   void make_placement_stack(RGE_RMM_Object_Gene
//                              rmm_obj.cpp:436 (12)
//         004867d3     MOV        ESI,dword ptr [ESP + param_1]
//         004867d7     XOR        this,this
//         004867d9     MOV        EAX,dword ptr [ESI + 0x1c]
//         004867dc     CMP        EAX,-0x1
//                              rmm_obj.cpp:438 (2)
//         004867df     JG         LAB_004867f3
//                              rmm_obj.cpp:439 (18)
//         004867e1     MOV        EAX,dword ptr [ESP + param_6]
//         004867e5     SHL        EAX,0x4
//         004867e8     MOV        EAX,dword ptr [EAX + EBX*0x1 + 0x12d4]
//         004867ef     TEST       EAX,EAX
//         004867f1     JLE        LAB_004867f5
//                               LAB_004867f3                                                 XREF[1]:     004867df(j)
//                              rmm_obj.cpp:440 (2)
//         004867f3     MOV        this,EAX
//                               LAB_004867f5                                                 XREF[1]:     004867f1(j)
//                              rmm_obj.cpp:442 (9)
//         004867f5     MOV        EAX,dword ptr [EBX + 0x30]
//         004867f8     MOV        EDX,dword ptr [EAX + 0x40]
//         004867fb     MOV        EDI,dword ptr [EDX + this->_padding_*0x4]
//                              rmm_obj.cpp:446 (8)
//         004867fe     MOV        this,dword ptr [ESI]
//         00486800     MOV        EDX,dword ptr [EDI + 0x24]
//         00486803     MOV        this,dword ptr [EDX + this->_padding_*0x4]
//                              rmm_obj.cpp:447 (8)
//         00486806     TEST       this,this
//         00486808     JZ         LAB_00486a4d
//                              rmm_obj.cpp:452 (32)
//         0048680e     MOVSX      this,word ptr [ECX + this+0x66]
//         00486812     LEA        EDX=>obj_stack,[ESP + 0x2c]
//         00486816     PUSH       EDX
//         00486817     MOV        EDX,dword ptr [EAX + 0x54]
//         0048681a     PUSH       0x20
//         0048681c     MOV        EAX,dword ptr [EDX + this->_padding_*0x4]
//         0048681f     MOV        this,dword ptr [EBX + 0xc]
//         00486822     PUSH       EAX
//         00486823     MOV        this,dword ptr [this->_padding_ + 0x8dc4]
//         00486829     CALL       RGE_Zone_Map_List::get_zone_map                  RGE_Zone_Map * get_zone_map(RGE_Zone_Map_List
//                              rmm_obj.cpp:455 (21)
//         0048682e     MOV        EDX,dword ptr [ESP + param_3]
//         00486832     MOV        this,EAX
//         00486834     PUSH       EDX
//         00486835     PUSH       EBP
//         00486836     MOV        dword ptr [ESP + param_6],EAX
//         0048683a     CALL       RGE_Zone_Map::get_zone_info                      uchar get_zone_info(RGE_Zone_Map * this, long
//         0048683f     MOV        byte ptr [ESP + param_3],AL
//                              rmm_obj.cpp:458 (3)
//         00486843     MOV        EAX,dword ptr [ESI + 0x14]
//                              rmm_obj.cpp:459 (51)
//         00486846     LEA        this=>temp,[ESP + 0x28]
//         0048684a     MOV        dword ptr [ESP + param_1],EAX
//         0048684e     LEA        EDX=>min_x0,[ESP + 0x10]
//         00486852     PUSH       this
//         00486853     LEA        EAX=>param_4,[ESP + 0x5c]
//         00486857     PUSH       EDX
//         00486858     LEA        this=>obj_stack.y,[ESP + 0x38]
//         0048685c     PUSH       EAX
//         0048685d     PUSH       this
//         0048685e     MOV        this,EBX
//         00486860     CALL       RGE_Random_Map_Module::pop_stack                 Map_Stack * pop_stack(RGE_Random_Map_Module *
//         00486865     TEST       EAX,EAX
//         00486867     JZ         LAB_00486a41
//                               LAB_0048686d                                                 XREF[1]:     00486a3b(j)
//         0048686d     MOV        EAX,dword ptr [ESP + param_1]
//         00486871     TEST       EAX,EAX
//         00486873     JLE        LAB_00486a41
//                              rmm_obj.cpp:460 (29)
//         00486879     MOV        EDX,dword ptr [ESP + min_x0]
//         0048687d     MOV        EAX,dword ptr [ESP + param_4]
//         00486881     MOV        this,dword ptr [ESP + param_6]
//         00486885     PUSH       EDX
//         00486886     PUSH       EAX=>DAT_fffffff8
//         00486887     CALL       RGE_Zone_Map::get_zone_info                      uchar get_zone_info(RGE_Zone_Map * this, long
//         0048688c     CMP        byte ptr [ESP + param_3],AL
//         00486890     JNZ        LAB_00486a1e
//                              rmm_obj.cpp:461 (43)
//         00486896     MOV        EAX,dword ptr [ESI + 0x4]
//         00486899     MOV        EBP,dword ptr [ESP + min_x0]
//         0048689d     MOV        this,dword ptr [ESP + param_4]
//         004868a1     TEST       EAX,EAX
//         004868a3     JL         LAB_004868c1
//         004868a5     MOV        EDX,dword ptr [EBX + 0x10]
//         004868a8     LEA        this,[ECX + ECX*0x2]
//         004868ab     MOV        EDX,dword ptr [EDX + EBP*0x4]
//         004868ae     MOV        this,byte ptr [EDX + this->_padding_*0x8 + 0x5]
//         004868b2     AND        this,0x1f
//         004868b5     CMP        this,EAX
//         004868b7     JNZ        LAB_00486a1e
//         004868bd     MOV        this,dword ptr [ESP + param_4]
//                               LAB_004868c1                                                 XREF[1]:     004868a3(j)
//                              rmm_obj.cpp:462 (28)
//         004868c1     CMP        this,dword ptr [ESP + min_x1]
//         004868c5     JLE        LAB_004868dd
//         004868c7     CMP        this,dword ptr [ESP + min_y0]
//         004868cb     JGE        LAB_004868dd
//         004868cd     CMP        EBP,dword ptr [ESP + min_y1]
//         004868d1     JLE        LAB_004868dd
//         004868d3     CMP        EBP,dword ptr [ESP + local_28]
//         004868d7     JL         LAB_00486a1e
//                               LAB_004868dd                                                 XREF[3]:     004868c5(j), 004868cb(j),
//                                                                                                         004868d1(j)
//                              rmm_obj.cpp:466 (13)
//         004868dd     FILD       dword ptr [ESP + param_4]
//         004868e1     MOV        EDX,dword ptr [ESI]
//         004868e3     MOV        EAX,dword ptr [EDI + 0x24]
//         004868e6     FSTP       float ptr [ESP + param_5]
//                              rmm_obj.cpp:467 (11)
//         004868ea     FILD       dword ptr [ESP + min_x0]
//         004868ee     MOV        EBP,dword ptr [EAX + EDX*0x4]
//         004868f1     FSTP       float ptr [ESP + param_2]
//                              rmm_obj.cpp:469 (35)
//         004868f5     FLD        float ptr [EBP + 0x30]
//         004868f8     CALL       __ftol                                           undefined __ftol()
//         004868fd     MOVSX      this,AX
//         00486900     MOV        dword ptr [ESP + zone],this
//         00486904     FILD       dword ptr [ESP + zone]
//         00486908     FSUBR      float ptr [EBP + 0x30]
//         0048690b     FCOMP      float ptr [DAT_00571edc]                         = align(7)
//         00486911     FNSTSW     AX
//         00486913     TEST       AH,0x41
//         00486916     JNZ        LAB_00486926
//                              rmm_obj.cpp:470 (14)
//         00486918     FLD        float ptr [ESP + param_5]
//         0048691c     FSUB       float ptr [null_00571ee0]                        = align(3)
//         00486922     FSTP       float ptr [ESP + param_5]
//                               LAB_00486926                                                 XREF[1]:     00486916(j)
//                              rmm_obj.cpp:472 (35)
//         00486926     FLD        float ptr [EBP + 0x34]
//         00486929     CALL       __ftol                                           undefined __ftol()
//         0048692e     MOVSX      EDX,AX
//         00486931     MOV        dword ptr [ESP + zone],EDX
//         00486935     FILD       dword ptr [ESP + zone]
//         00486939     FSUBR      float ptr [EBP + 0x34]
//         0048693c     FCOMP      float ptr [DAT_00571edc]                         = align(7)
//         00486942     FNSTSW     AX
//         00486944     TEST       AH,0x41
//         00486947     JNZ        LAB_00486957
//                              rmm_obj.cpp:473 (14)
//         00486949     FLD        float ptr [ESP + param_2]
//         0048694d     FSUB       float ptr [null_00571ee0]                        = align(3)
//         00486953     FSTP       float ptr [ESP + param_2]
//                               LAB_00486957                                                 XREF[1]:     00486947(j)
//                              rmm_obj.cpp:476 (37)
//         00486957     MOV        this,dword ptr [ESP + param_2]
//         0048695b     MOV        EDX,dword ptr [ESP + param_5]
//         0048695f     MOV        EAX,dword ptr [EBP]
//         00486962     PUSH       0x1
//         00486964     PUSH       0x1
//         00486966     PUSH       0x1
//         00486968     PUSH       0x1
//         0048696a     PUSH       0x1
//         0048696c     PUSH       0x0
//         0048696e     PUSH       0x0
//         00486970     PUSH       this
//         00486971     PUSH       EDX
//         00486972     PUSH       EDI
//         00486973     MOV        this,EBP
//         00486975     CALL       dword ptr [EAX + 0x20]
//         00486978     TEST       AL,AL
//         0048697a     JNZ        LAB_004869f4
//                              rmm_obj.cpp:478 (21)
//         0048697c     MOV        EAX,dword ptr [ESI + 0x2c]
//         0048697f     MOV        this,dword ptr [ESP + 0x10]
//         00486983     MOV        EDX,dword ptr [ESP + 0x58]
//         00486987     PUSH       EAX
//         00486988     PUSH       this=>DAT_fffffff8
//         00486989     PUSH       EDX=>DAT_fffffff4
//         0048698a     MOV        this,EBX
//         0048698c     CALL       RGE_RMM_Object_Generator::remove_area_from_lists void remove_area_from_lists(RGE_RMM_Object_Ge
//                              rmm_obj.cpp:479 (16)
//         00486991     XOR        EAX,EAX
//         00486993     MOV        AL,byte ptr [ESI + 0x8]
//         00486996     SUB        EAX,0x0
//         00486999     JZ         LAB_004869d3
//         0048699b     DEC        EAX
//         0048699c     JZ         LAB_004869ba
//         0048699e     DEC        EAX
//         0048699f     JNZ        LAB_004869ee
//                              rmm_obj.cpp:497 (19)
//         004869a1     MOV        EAX,dword ptr [ESP + 0x10]
//         004869a5     MOV        this,dword ptr [ESP + 0x58]
//         004869a9     PUSH       EDI
//         004869aa     PUSH       EAX=>DAT_fffffff8
//         004869ab     PUSH       this=>DAT_fffffff4
//         004869ac     PUSH       ESI=>DAT_fffffff0
//         004869ad     MOV        this,EBX
//         004869af     CALL       RGE_RMM_Object_Generator::place_cluster          void place_cluster(RGE_RMM_Object_Generator *
//                              rmm_obj.cpp:500 (4)
//         004869b4     DEC        dword ptr [ESP + 0x4c]
//                              rmm_obj.cpp:502 (2)
//         004869b8     JMP        LAB_00486a1e
//                               LAB_004869ba                                                 XREF[1]:     0048699c(j)
//                              rmm_obj.cpp:493 (19)
//         004869ba     MOV        EDX,dword ptr [ESP + 0x10]
//         004869be     MOV        EAX,dword ptr [ESP + 0x58]
//         004869c2     PUSH       EDI
//         004869c3     PUSH       EDX=>DAT_fffffff8
//         004869c4     PUSH       EAX=>DAT_fffffff4
//         004869c5     PUSH       ESI=>DAT_fffffff0
//         004869c6     MOV        this,EBX
//         004869c8     CALL       RGE_RMM_Object_Generator::place_group            void place_group(RGE_RMM_Object_Generator * t
//                              rmm_obj.cpp:500 (4)
//         004869cd     DEC        dword ptr [ESP + 0x4c]
//                              rmm_obj.cpp:502 (2)
//         004869d1     JMP        LAB_00486a1e
//                               LAB_004869d3                                                 XREF[1]:     00486999(j)
//                              rmm_obj.cpp:488 (27)
//         004869d3     MOV        EAX,dword ptr [ESP + 0x50]
//         004869d7     MOV        this,dword ptr [ESP + 0x5c]
//         004869db     MOV        EDX,dword ptr [EDI]
//         004869dd     PUSH       0x1
//         004869df     PUSH       0x0=>DAT_fffffff8
//         004869e1     PUSH       EAX=>DAT_fffffff4
//         004869e2     MOV        EAX,dword ptr [ESI]
//         004869e4     PUSH       this=>DAT_fffffff0
//         004869e5     PUSH       EAX
//         004869e6     MOV        this,EDI
//         004869e8     CALL       dword ptr [EDX + 0x94]
//                               LAB_004869ee                                                 XREF[1]:     0048699f(j)
//                              rmm_obj.cpp:500 (4)
//         004869ee     DEC        dword ptr [ESP + 0x4c]
//                              rmm_obj.cpp:502 (2)
//         004869f2     JMP        LAB_00486a1e
//                               LAB_004869f4                                                 XREF[1]:     0048697a(j)
//                              rmm_obj.cpp:504 (15)
//         004869f4     MOV        AL,byte ptr [ESI + 0x8]
//         004869f7     TEST       AL,AL
//         004869f9     JNZ        LAB_00486a1e
//         004869fb     MOV        EAX,dword ptr [ESP + 0x40]
//         004869ff     TEST       EAX,EAX
//         00486a01     JNZ        LAB_00486a1e
//                              rmm_obj.cpp:505 (62)
//         00486a03     MOV        EAX,dword ptr [ESP + 0x50]
//         00486a07     MOV        this,dword ptr [ESP + 0x5c]
//         00486a0b     MOV        EDX,dword ptr [EDI]
//         00486a0d     PUSH       0x1
//         00486a0f     PUSH       0x0=>DAT_fffffff8
//         00486a11     PUSH       EAX=>DAT_fffffff4
//         00486a12     MOV        EAX,dword ptr [ESI]
//         00486a14     PUSH       this=>DAT_fffffff0
//         00486a15     PUSH       EAX
//         00486a16     MOV        this,EDI
//         00486a18     CALL       dword ptr [EDX + 0x94]
//                               LAB_00486a1e                                                 XREF[8]:     00486890(j), 004868b7(j),
//                                                                                                         004868d7(j), 004869b8(j),
//                                                                                                         004869d1(j), 004869f2(j),
//                                                                                                         004869f9(j), 00486a01(j)
//         00486a1e     LEA        this=>temp,[ESP + 0x28]
//         00486a22     LEA        EDX=>min_x0,[ESP + 0x10]
//         00486a26     PUSH       this
//         00486a27     LEA        EAX=>param_4,[ESP + 0x5c]
//         00486a2b     PUSH       EDX=>DAT_fffffff8
//         00486a2c     LEA        this=>obj_stack.y,[ESP + 0x38]
//         00486a30     PUSH       EAX=>DAT_fffffff4
//         00486a31     PUSH       this=>DAT_fffffff0
//         00486a32     MOV        this,EBX
//         00486a34     CALL       RGE_Random_Map_Module::pop_stack                 Map_Stack * pop_stack(RGE_Random_Map_Module *
//         00486a39     TEST       EAX,EAX
//         00486a3b     JNZ        LAB_0048686d
//                               LAB_00486a41                                                 XREF[2]:     00486867(j), 00486873(j)
//                              rmm_obj.cpp:509 (12)
//         00486a41     LEA        EDX=>obj_stack.y,[ESP + 0x30]
//         00486a45     MOV        this,EBX
//         00486a47     PUSH       EDX
//         00486a48     CALL       RGE_Random_Map_Module::deinit_stack              void deinit_stack(RGE_Random_Map_Module * thi
//                               LAB_00486a4d                                                 XREF[1]:     00486808(j)
//                              rmm_obj.cpp:510 (10)
//         00486a4d     POP        EDI
//         00486a4e     POP        ESI
//         00486a4f     POP        EBP
//         00486a50     POP        EBX
//         00486a51     ADD        ESP,0x38
//         00486a54     RET        0x18
//         00486a57     ??         90h
//         00486a58     NOP
//         00486a59     NOP
//         00486a5a     NOP
//         00486a5b     NOP
//         00486a5c     NOP
//         00486a5d     NOP
//         00486a5e     NOP
//         00486a5f     NOP
    return;
}

void RGE_RMM_Object_Generator::place_group(RGE_Object_Info_Line* param_1, long param_2, long param_3, RGE_Player* param_4) {
    /* TODO: Stub */
//                              void __thiscall place_group(RGE_RMM_Object_Generator * this, RGE_Obj
//              void              <VOID>         <RETURN>
//              RGE_RMM_Object    ECX:4 (auto)   this
//              RGE_Object_Inf    Stack[0x4]:4   param_1                   XREF[1]:     00486a77(R)
//              long              Stack[0x8]:4   param_2                   XREF[5]:     00486a7f(R), 00486b4d(W), 00486ba5(R), 00486baf(W),
//                                                                                     00486bb3(R)
//              long              Stack[0xc]:4   param_3                   XREF[4]:     00486a7b(R), 00486ad1(W), 00486ad7(W), 00486b06(R)
//              RGE_Player *      Stack[0x10]:4  param_4                   XREF[5]:     00486b02(R), 00486b42(W), 00486b74(R), 00486b7e(W),
//                                                                                     00486bb7(R)
//              Map_Stack         Stack[-0x1c]   obj_stack                 XREF[1,4]:   00486adf(*), 00486a66(*), 00486a8a(*), 00486aed(*),
//                                                                                     00486c1d(*)
//              float             Stack[-0x20]:4 zone                      XREF[4]:     00486b5c(W), 00486b60(R), 00486b8d(W), 00486b91(R)
//              undefined4        Stack[-0x24]:4 local_24                  XREF[1]:     00486a6e(W)
//              undefined4        Stack[-0x28]:4 local_28                  XREF[3]:     00486ae8(*), 00486b1c(R), 00486b39(R)
//              long              Stack[-0x2c]:4 x                         XREF[3]:     00486ae3(*), 00486b20(R), 00486b46(R)
//              long              Stack[-0x30]:4 y
//                               ?place_group@RGE_RMM_Object_Generator@@IAEXAAURGE_Object_In  XREF[3]:     place_avoid_objects:00486488(c),
//                               RGE_RMM_Object_Generator::place_group                                     place_objects:00486694(c),
//                                                                                                         place_land_objects:004869c8(c)
//                              rmm_obj.cpp:514 (6)
//         00486a60     SUB        ESP,0x2c
//         00486a63     PUSH       EBX
//         00486a64     PUSH       EBP
//         00486a65     PUSH       ESI
//                              rmm_obj.cpp:525 (17)
//         00486a66     LEA        EAX=>obj_stack.y,[ESP + 0x20]
//         00486a6a     PUSH       EDI
//         00486a6b     MOV        EBX,this
//         00486a6d     PUSH       EAX
//         00486a6e     MOV        dword ptr [ESP + local_24],EBX
//         00486a72     CALL       RGE_Random_Map_Module::init_stack                void init_stack(RGE_Random_Map_Module * this,
//                              rmm_obj.cpp:526 (32)
//         00486a77     MOV        ESI,dword ptr [ESP + param_1]
//         00486a7b     MOV        EDX,dword ptr [ESP + param_3]
//         00486a7f     MOV        EAX,dword ptr [ESP + param_2]
//         00486a83     MOV        this,dword ptr [ESI + 0x18]
//         00486a86     PUSH       this
//         00486a87     PUSH       0x0
//         00486a89     PUSH       EDX
//         00486a8a     LEA        this=>obj_stack.y,[ESP + 0x30]
//         00486a8e     PUSH       EAX
//         00486a8f     PUSH       this
//         00486a90     MOV        this,EBX
//         00486a92     CALL       RGE_RMM_Object_Generator::make_placement_stack   void make_placement_stack(RGE_RMM_Object_Gene
//                              rmm_obj.cpp:529 (3)
//         00486a97     MOV        EBP,dword ptr [ESI + 0xc]
//                              rmm_obj.cpp:530 (52)
//         00486a9a     MOV        EDI,dword ptr [ESI + 0x10]
//         00486a9d     PUSH       0x212
//         00486aa2     PUSH       s_C:\msdev\work\age1_x1\rmm_obj.cp               = "C:\\msdev\\work\\age1_x1\\rmm_obj.cpp"
//         00486aa7     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
//         00486aac     MOV        this,EAX
//         00486aae     LEA        EDX,[EDI + EDI*0x1]
//         00486ab1     IMUL       this,EDX
//         00486ab4     MOV        EAX,0x80010003
//         00486ab9     ADD        ESP,0x8
//         00486abc     IMUL       this
//         00486abe     ADD        EDX,this
//         00486ac0     SAR        EDX,0xe
//         00486ac3     MOV        EAX,EDX
//         00486ac5     SHR        EAX,0x1f
//         00486ac8     ADD        EDX,EAX
//         00486aca     SUB        EDX,EDI
//         00486acc     ADD        EBP,EDX
//                              rmm_obj.cpp:531 (9)
//         00486ace     CMP        EBP,0x1
//         00486ad1     MOV        dword ptr [ESP + param_3],EBP
//         00486ad5     JGE        LAB_00486adf
//                              rmm_obj.cpp:532 (8)
//         00486ad7     MOV        dword ptr [ESP + param_3],0x1
//                               LAB_00486adf                                                 XREF[1]:     00486ad5(j)
//                              rmm_obj.cpp:534 (51)
//         00486adf     LEA        this=>obj_stack,[ESP + 0x20]
//         00486ae3     LEA        EDX=>x,[ESP + 0x10]
//         00486ae7     PUSH       this
//         00486ae8     LEA        EAX=>local_28,[ESP + 0x18]
//         00486aec     PUSH       EDX
//         00486aed     LEA        this=>obj_stack.y,[ESP + 0x2c]
//         00486af1     PUSH       EAX
//         00486af2     PUSH       this
//         00486af3     MOV        this,EBX
//         00486af5     CALL       RGE_Random_Map_Module::pop_stack                 Map_Stack * pop_stack(RGE_Random_Map_Module *
//         00486afa     TEST       EAX,EAX
//         00486afc     JZ         LAB_00486c1d
//         00486b02     MOV        EDI,dword ptr [ESP + param_4]
//                               LAB_00486b06                                                 XREF[1]:     00486c17(j)
//         00486b06     MOV        EAX,dword ptr [ESP + param_3]
//         00486b0a     TEST       EAX,EAX
//         00486b0c     JLE        LAB_00486c1d
//                              rmm_obj.cpp:535 (39)
//         00486b12     MOV        this,dword ptr [ESI + 0x4]
//         00486b15     TEST       this,this
//         00486b17     JL         LAB_00486b39
//         00486b19     MOV        EDX,dword ptr [EBX + 0x10]
//         00486b1c     MOV        EAX,dword ptr [ESP + local_28]
//         00486b20     MOV        EBP,dword ptr [ESP + x]
//         00486b24     LEA        EAX,[EAX + EAX*0x2]
//         00486b27     MOV        EDX,dword ptr [EDX + EBP*0x4]
//         00486b2a     MOV        AL,byte ptr [EDX + EAX*0x8 + 0x5]
//         00486b2e     AND        EAX,0x1f
//         00486b31     CMP        EAX,this
//         00486b33     JNZ        LAB_00486bfa
//                               LAB_00486b39                                                 XREF[1]:     00486b17(j)
//                              rmm_obj.cpp:539 (13)
//         00486b39     FILD       dword ptr [ESP + local_28]
//         00486b3d     MOV        this,dword ptr [ESI]
//         00486b3f     MOV        EDX,dword ptr [EDI + 0x24]
//         00486b42     FSTP       float ptr [ESP + param_4]
//                              rmm_obj.cpp:540 (11)
//         00486b46     FILD       dword ptr [ESP + x]
//         00486b4a     MOV        ESI,dword ptr [EDX + this->_padding_*0x4]
//         00486b4d     FSTP       float ptr [ESP + param_2]
//                              rmm_obj.cpp:542 (35)
//         00486b51     FLD        float ptr [ESI + 0x30]
//         00486b54     CALL       __ftol                                           undefined __ftol()
//         00486b59     MOVSX      EAX,AX
//         00486b5c     MOV        dword ptr [ESP + zone],EAX
//         00486b60     FILD       dword ptr [ESP + zone]
//         00486b64     FSUBR      float ptr [ESI + 0x30]
//         00486b67     FCOMP      float ptr [DAT_00571edc]                         = align(7)
//         00486b6d     FNSTSW     AX
//         00486b6f     TEST       AH,0x41
//         00486b72     JNZ        LAB_00486b82
//                              rmm_obj.cpp:543 (14)
//         00486b74     FLD        float ptr [ESP + param_4]
//         00486b78     FSUB       float ptr [null_00571ee0]                        = align(3)
//         00486b7e     FSTP       float ptr [ESP + param_4]
//                               LAB_00486b82                                                 XREF[1]:     00486b72(j)
//                              rmm_obj.cpp:545 (35)
//         00486b82     FLD        float ptr [ESI + 0x34]
//         00486b85     CALL       __ftol                                           undefined __ftol()
//         00486b8a     MOVSX      this,AX
//         00486b8d     MOV        dword ptr [ESP + zone],this
//         00486b91     FILD       dword ptr [ESP + zone]
//         00486b95     FSUBR      float ptr [ESI + 0x34]
//         00486b98     FCOMP      float ptr [DAT_00571edc]                         = align(7)
//         00486b9e     FNSTSW     AX
//         00486ba0     TEST       AH,0x41
//         00486ba3     JNZ        LAB_00486bb3
//                              rmm_obj.cpp:546 (14)
//         00486ba5     FLD        float ptr [ESP + param_2]
//         00486ba9     FSUB       float ptr [null_00571ee0]                        = align(3)
//         00486baf     FSTP       float ptr [ESP + param_2]
//                               LAB_00486bb3                                                 XREF[1]:     00486ba3(j)
//                              rmm_obj.cpp:548 (36)
//         00486bb3     MOV        EBX,dword ptr [ESP + param_2]
//         00486bb7     MOV        EBP,dword ptr [ESP + param_4]
//         00486bbb     MOV        EDX,dword ptr [ESI]
//         00486bbd     PUSH       0x1
//         00486bbf     PUSH       0x0
//         00486bc1     PUSH       0x1
//         00486bc3     PUSH       0x1
//         00486bc5     PUSH       0x1
//         00486bc7     PUSH       0x0
//         00486bc9     PUSH       0x0
//         00486bcb     PUSH       EBX
//         00486bcc     PUSH       EBP
//         00486bcd     PUSH       EDI
//         00486bce     MOV        this,ESI
//         00486bd0     CALL       dword ptr [EDX + 0x20]
//         00486bd3     TEST       AL,AL
//         00486bd5     JNZ        LAB_00486bf2
//                              rmm_obj.cpp:550 (23)
//         00486bd7     MOV        this,dword ptr [ESP + 0x40]
//         00486bdb     MOV        EAX,dword ptr [EDI]
//         00486bdd     PUSH       0x1
//         00486bdf     PUSH       0x0=>DAT_fffffff8
//         00486be1     MOV        EDX,dword ptr [this->_padding_]
//         00486be3     PUSH       EBX=>DAT_fffffff4
//         00486be4     PUSH       EBP=>DAT_fffffff0
//         00486be5     PUSH       EDX
//         00486be6     MOV        this,EDI
//         00486be8     CALL       dword ptr [EAX + 0x94]
//                              rmm_obj.cpp:551 (47)
//         00486bee     DEC        dword ptr [ESP + 0x48]
//                               LAB_00486bf2                                                 XREF[1]:     00486bd5(j)
//         00486bf2     MOV        EBX,dword ptr [ESP + 0x18]
//         00486bf6     MOV        ESI,dword ptr [ESP + 0x40]
//                               LAB_00486bfa                                                 XREF[1]:     00486b33(j)
//         00486bfa     LEA        EAX,[ESP + 0x20]
//         00486bfe     LEA        this,[ESP + 0x10]
//         00486c02     PUSH       EAX
//         00486c03     LEA        EDX,[ESP + 0x18]
//         00486c07     PUSH       this=>DAT_fffffff8
//         00486c08     LEA        EAX,[ESP + 0x2c]
//         00486c0c     PUSH       EDX=>DAT_fffffff4
//         00486c0d     PUSH       EAX=>DAT_fffffff0
//         00486c0e     MOV        this,EBX
//         00486c10     CALL       RGE_Random_Map_Module::pop_stack                 Map_Stack * pop_stack(RGE_Random_Map_Module *
//         00486c15     TEST       EAX,EAX
//         00486c17     JNZ        LAB_00486b06
//                               LAB_00486c1d                                                 XREF[2]:     00486afc(j), 00486b0c(j)
//                              rmm_obj.cpp:555 (12)
//         00486c1d     LEA        this=>obj_stack.y,[ESP + 0x24]
//         00486c21     PUSH       this
//         00486c22     MOV        this,EBX
//         00486c24     CALL       RGE_Random_Map_Module::deinit_stack              void deinit_stack(RGE_Random_Map_Module * thi
//                              rmm_obj.cpp:556 (10)
//         00486c29     POP        EDI
//         00486c2a     POP        ESI
//         00486c2b     POP        EBP
//         00486c2c     POP        EBX
//         00486c2d     ADD        ESP,0x2c
//         00486c30     RET        0x10
//         00486c33     ??         90h
//         00486c34     NOP
//         00486c35     NOP
//         00486c36     NOP
//         00486c37     NOP
//         00486c38     NOP
//         00486c39     NOP
//         00486c3a     NOP
//         00486c3b     NOP
//         00486c3c     NOP
//         00486c3d     NOP
//         00486c3e     NOP
//         00486c3f     NOP
    return;
}

void RGE_RMM_Object_Generator::place_cluster(RGE_Object_Info_Line* param_1, long param_2, long param_3, RGE_Player* param_4) {
    /* TODO: Stub */
//                              void __thiscall place_cluster(RGE_RMM_Object_Generator * this, RGE_O
//              void              <VOID>         <RETURN>
//              RGE_RMM_Object    ECX:4 (auto)   this
//              RGE_Object_Inf    Stack[0x4]:4   param_1                   XREF[3]:     00486c7e(R), 00486d0b(R), 00486d90(R)
//              long              Stack[0x8]:4   param_2                   XREF[4]:     00486c60(R), 00486d49(W), 00486d4f(W), 00486d57(R)
//              long              Stack[0xc]:4   param_3                   XREF[3]:     00486c64(R), 00486c93(W), 00486ca5(W)
//              RGE_Player *      Stack[0x10]:4  param_4                   XREF[5]:     00486d7e(R), 00486db7(W), 00486dbb(R), 00486de8(W),
//                                                                                     00486dec(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     00486c54(W)
//              Map_Stack         Stack[-0x1c]   obj_stack                 XREF[1,5]:   00486d5b(*), 00486c46(*), 00486c71(*), 00486d69(*),
//                                                                                     00486ff8(*), 00486c50(W)
//              float             Stack[-0x20]:4 zone                      XREF[2]:     00486c9f(W), 00486ccb(W)
//              long              Stack[-0x24]:4 y1                        XREF[2]:     00486c97(W), 00486caf(W)
//              long              Stack[-0x28]:4 y0                        XREF[2]:     00486c9b(W), 00486cbd(W)
//              long              Stack[-0x2c]:4 x1                        XREF[4]:     00486da0(W), 00486dcf(R), 00486dd9(W), 00486e1a(*)
//              float             Stack[-0x30]:4 tile_x                    XREF[4]:     00486da8(W), 00486e00(R), 00486e0a(W), 00486e15(*)
//              float             Stack[-0x34]:4 tile_y                    XREF[5]:     00486cdd(W), 00486cf1(R), 00486cf8(W), 00486d64(*),
//                                                                                     00486d97(R)
//              long              Stack[-0x38]:4 x                         XREF[6]:     00486cd3(W), 00486ce6(R), 00486cfe(R), 00486d05(W),
//                                                                                     00486d5f(*), 00486da4(R)
//              long              Stack[-0x3c]:4 y
//                               ?place_cluster@RGE_RMM_Object_Generator@@IAEXAAURGE_Object_  XREF[3]:     place_avoid_objects:00486473(c),
//                               RGE_RMM_Object_Generator::place_cluster                                   place_objects:0048667f(c),
//                                                                                                         place_land_objects:004869af(c)
//                              rmm_obj.cpp:560 (6)
//         00486c40     SUB        ESP,0x38
//         00486c43     PUSH       EBX
//         00486c44     PUSH       EBP
//         00486c45     PUSH       ESI
//                              rmm_obj.cpp:578 (23)
//         00486c46     LEA        EAX=>obj_stack.y,[ESP + 0x2c]
//         00486c4a     PUSH       EDI
//         00486c4b     XOR        EBX,EBX
//         00486c4d     MOV        ESI,this
//         00486c4f     PUSH       EAX
//         00486c50     MOV        dword ptr [ESP + obj_stack.prev],EBX
//         00486c54     MOV        dword ptr [ESP + local_4],EBX
//         00486c58     CALL       RGE_Random_Map_Module::init_stack                void init_stack(RGE_Random_Map_Module * this,
//                              rmm_obj.cpp:579 (33)
//         00486c5d     MOV        this,dword ptr [ESI + 0x2c]
//         00486c60     MOV        EDI,dword ptr [ESP + param_2]
//         00486c64     MOV        EBP,dword ptr [ESP + param_3]
//         00486c68     LEA        EDX,[EDI + EDI*0x2]
//         00486c6b     MOV        EAX,dword ptr [this->_padding_ + EBP*0x4]
//         00486c6e     LEA        this,[EAX + EDX*0x8]
//         00486c71     LEA        EDX=>obj_stack.y,[ESP + 0x30]
//         00486c75     PUSH       this
//         00486c76     PUSH       EDX
//         00486c77     MOV        this,ESI
//         00486c79     CALL       RGE_Random_Map_Module::add_stack_node            void add_stack_node(RGE_Random_Map_Module * t
//                              rmm_obj.cpp:582 (6)
//         00486c7e     MOV        EAX,dword ptr [ESP + param_1]
//         00486c82     MOV        EDX,EDI
//                              rmm_obj.cpp:583 (9)
//         00486c84     MOV        this,EBP
//         00486c86     MOV        EAX,dword ptr [EAX + 0x18]
//         00486c89     SUB        EDX,EAX
//         00486c8b     SUB        this,EAX
//                              rmm_obj.cpp:584 (2)
//         00486c8d     ADD        EDI,EAX
//                              rmm_obj.cpp:585 (2)
//         00486c8f     ADD        EBP,EAX
//                              rmm_obj.cpp:587 (26)
//         00486c91     CMP        EDX,EBX
//         00486c93     MOV        dword ptr [ESP + param_3],EDX
//         00486c97     MOV        dword ptr [ESP + y1],this
//         00486c9b     MOV        dword ptr [ESP + y0],EDI
//         00486c9f     MOV        dword ptr [ESP + zone],EBP
//         00486ca3     JGE        LAB_00486cab
//         00486ca5     MOV        dword ptr [ESP + param_3],EBX
//         00486ca9     MOV        EDX,EBX
//                               LAB_00486cab                                                 XREF[1]:     00486ca3(j)
//                              rmm_obj.cpp:588 (10)
//         00486cab     CMP        this,EBX
//         00486cad     JGE        LAB_00486cb5
//         00486caf     MOV        dword ptr [ESP + y1],EBX
//         00486cb3     MOV        this,EBX
//                               LAB_00486cb5                                                 XREF[1]:     00486cad(j)
//                              rmm_obj.cpp:589 (14)
//         00486cb5     MOV        EAX,dword ptr [ESI + 0x14]
//         00486cb8     CMP        EDI,EAX
//         00486cba     JL         LAB_00486cc3
//         00486cbc     DEC        EAX
//         00486cbd     MOV        dword ptr [ESP + y0],EAX
//         00486cc1     MOV        EDI,EAX
//                               LAB_00486cc3                                                 XREF[1]:     00486cba(j)
//                              rmm_obj.cpp:590 (14)
//         00486cc3     MOV        EAX,dword ptr [ESI + 0x18]
//         00486cc6     CMP        EBP,EAX
//         00486cc8     JL         LAB_00486cd1
//         00486cca     DEC        EAX
//         00486ccb     MOV        dword ptr [ESP + zone],EAX
//         00486ccf     MOV        EBP,EAX
//                               LAB_00486cd1                                                 XREF[1]:     00486cc8(j)
//                              rmm_obj.cpp:592 (8)
//         00486cd1     CMP        this,EBP
//         00486cd3     MOV        dword ptr [ESP + x],this
//         00486cd7     JG         LAB_00486d0b
//                               LAB_00486cd9                                                 XREF[1]:     00486d09(j)
//                              rmm_obj.cpp:593 (10)
//         00486cd9     MOV        EAX,EDX
//         00486cdb     CMP        EDX,EDI
//         00486cdd     MOV        dword ptr [ESP + tile_y],EAX
//         00486ce1     JG         LAB_00486cfe
//                               LAB_00486ce3                                                 XREF[1]:     00486cfc(j)
//                              rmm_obj.cpp:594 (27)
//         00486ce3     MOV        this,dword ptr [ESI + 0x24]
//         00486ce6     MOV        EBX,dword ptr [ESP + x]
//         00486cea     MOV        this,dword ptr [this->_padding_ + EBX*0x4]
//         00486ced     MOV        byte ptr [this->_padding_ + EAX*0x1],0x1
//         00486cf1     MOV        EAX,dword ptr [ESP + tile_y]
//         00486cf5     INC        EAX
//         00486cf6     CMP        EAX,EDI
//         00486cf8     MOV        dword ptr [ESP + tile_y],EAX
//         00486cfc     JLE        LAB_00486ce3
//                               LAB_00486cfe                                                 XREF[1]:     00486ce1(j)
//                              rmm_obj.cpp:592 (13)
//         00486cfe     MOV        EAX,dword ptr [ESP + x]
//         00486d02     INC        EAX
//         00486d03     CMP        EAX,EBP
//         00486d05     MOV        dword ptr [ESP + x],EAX
//         00486d09     JLE        LAB_00486cd9
//                               LAB_00486d0b                                                 XREF[1]:     00486cd7(j)
//                              rmm_obj.cpp:597 (4)
//         00486d0b     MOV        EAX,dword ptr [ESP + param_1]
//                              rmm_obj.cpp:598 (55)
//         00486d0f     PUSH       0x256
//         00486d14     PUSH       s_C:\msdev\work\age1_x1\rmm_obj.cp               = "C:\\msdev\\work\\age1_x1\\rmm_obj.cpp"
//         00486d19     MOV        EBP,dword ptr [EAX + 0xc]
//         00486d1c     MOV        EDI,dword ptr [EAX + 0x10]
//         00486d1f     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
//         00486d24     MOV        this,EAX
//         00486d26     LEA        EDX,[EDI + EDI*0x1]
//         00486d29     IMUL       this,EDX
//         00486d2c     MOV        EAX,0x80010003
//         00486d31     ADD        ESP,0x8
//         00486d34     IMUL       this
//         00486d36     ADD        EDX,this
//         00486d38     SAR        EDX,0xe
//         00486d3b     MOV        EAX,EDX
//         00486d3d     SHR        EAX,0x1f
//         00486d40     ADD        EDX,EAX
//         00486d42     SUB        EDX,EDI
//         00486d44     ADD        EBP,EDX
//                              rmm_obj.cpp:599 (9)
//         00486d46     CMP        EBP,0x1
//         00486d49     MOV        dword ptr [ESP + param_2],EBP
//         00486d4d     JGE        LAB_00486d5b
//                              rmm_obj.cpp:600 (12)
//         00486d4f     MOV        dword ptr [ESP + param_2],0x1
//         00486d57     MOV        EBP,dword ptr [ESP + param_2]
//                               LAB_00486d5b                                                 XREF[1]:     00486d4d(j)
//                              rmm_obj.cpp:602 (53)
//         00486d5b     LEA        this=>obj_stack,[ESP + 0x2c]
//         00486d5f     LEA        EDX=>x,[ESP + 0x10]
//         00486d63     PUSH       this
//         00486d64     LEA        EAX=>tile_y,[ESP + 0x18]
//         00486d68     PUSH       EDX
//         00486d69     LEA        this=>obj_stack.y,[ESP + 0x38]
//         00486d6d     PUSH       EAX
//         00486d6e     PUSH       this
//         00486d6f     MOV        this,ESI
//         00486d71     CALL       RGE_Random_Map_Module::pop_stack                 Map_Stack * pop_stack(RGE_Random_Map_Module *
//         00486d76     TEST       EAX,EAX
//         00486d78     JZ         LAB_00486ff8
//         00486d7e     MOV        EBX,dword ptr [ESP + param_4]
//         00486d82     JMP        LAB_00486d88
//                               LAB_00486d84                                                 XREF[1]:     00486ff2(j)
//         00486d84     MOV        EBP,dword ptr [ESP + 0x50]
//                               LAB_00486d88                                                 XREF[1]:     00486d82(j)
//         00486d88     TEST       EBP,EBP
//         00486d8a     JLE        LAB_00486ff8
//                              rmm_obj.cpp:604 (7)
//         00486d90     MOV        EDX,dword ptr [ESP + param_1]
//         00486d94     MOV        this,dword ptr [EBX + 0x24]
//                              rmm_obj.cpp:606 (13)
//         00486d97     FILD       dword ptr [ESP + tile_y]
//         00486d9b     MOV        EAX,dword ptr [EDX]
//         00486d9d     MOV        EDI,dword ptr [this->_padding_ + EAX*0x4]
//         00486da0     FSTP       float ptr [ESP + x1]
//                              rmm_obj.cpp:607 (8)
//         00486da4     FILD       dword ptr [ESP + x]
//         00486da8     FSTP       float ptr [ESP + tile_x]
//                              rmm_obj.cpp:609 (35)
//         00486dac     FLD        float ptr [EDI + 0x30]
//         00486daf     CALL       __ftol                                           undefined __ftol()
//         00486db4     MOVSX      EDX,AX
//         00486db7     MOV        dword ptr [ESP + param_4],EDX
//         00486dbb     FILD       dword ptr [ESP + param_4]
//         00486dbf     FSUBR      float ptr [EDI + 0x30]
//         00486dc2     FCOMP      float ptr [DAT_00571edc]                         = align(7)
//         00486dc8     FNSTSW     AX
//         00486dca     TEST       AH,0x41
//         00486dcd     JNZ        LAB_00486ddd
//                              rmm_obj.cpp:610 (14)
//         00486dcf     FLD        float ptr [ESP + x1]
//         00486dd3     FSUB       float ptr [null_00571ee0]                        = align(3)
//         00486dd9     FSTP       float ptr [ESP + x1]
//                               LAB_00486ddd                                                 XREF[1]:     00486dcd(j)
//                              rmm_obj.cpp:612 (35)
//         00486ddd     FLD        float ptr [EDI + 0x34]
//         00486de0     CALL       __ftol                                           undefined __ftol()
//         00486de5     MOVSX      EAX,AX
//         00486de8     MOV        dword ptr [ESP + param_4],EAX
//         00486dec     FILD       dword ptr [ESP + param_4]
//         00486df0     FSUBR      float ptr [EDI + 0x34]
//         00486df3     FCOMP      float ptr [DAT_00571edc]                         = align(7)
//         00486df9     FNSTSW     AX
//         00486dfb     TEST       AH,0x41
//         00486dfe     JNZ        LAB_00486e0e
//                              rmm_obj.cpp:613 (14)
//         00486e00     FLD        float ptr [ESP + tile_x]
//         00486e04     FSUB       float ptr [null_00571ee0]                        = align(3)
//         00486e0a     FSTP       float ptr [ESP + tile_x]
//                               LAB_00486e0e                                                 XREF[1]:     00486dfe(j)
//                              rmm_obj.cpp:615 (23)
//         00486e0e     MOV        this,dword ptr [ESI + 0x30]
//         00486e11     MOV        EBP,dword ptr [EDI]
//         00486e13     PUSH       0x1
//         00486e15     LEA        EDX=>tile_x,[ESP + 0x1c]
//         00486e19     PUSH       this
//         00486e1a     LEA        EAX=>x1,[ESP + 0x24]
//         00486e1e     PUSH       EDX
//         00486e1f     PUSH       EAX
//         00486e20     MOV        this,EDI
//         00486e22     CALL       dword ptr [EBP + 0x24]
//                              rmm_obj.cpp:618 (38)
//         00486e25     MOV        this,dword ptr [ESP + 0x18]
//         00486e29     MOV        EDX,dword ptr [ESP + 0x1c]
//         00486e2d     PUSH       0x1
//         00486e2f     PUSH       0x0=>DAT_fffffff8
//         00486e31     PUSH       offset DAT_fffffff4
//         00486e33     PUSH       offset DAT_fffffff0
//         00486e35     PUSH       0x1
//         00486e37     PUSH       0x0
//         00486e39     PUSH       0x0
//         00486e3b     PUSH       this
//         00486e3c     PUSH       EDX
//         00486e3d     PUSH       EBX
//         00486e3e     MOV        this,EDI
//         00486e40     CALL       dword ptr [EBP + 0x20]
//         00486e43     TEST       AL,AL
//         00486e45     JNZ        LAB_00486fd5
//                              rmm_obj.cpp:620 (31)
//         00486e4b     MOV        this,dword ptr [ESP + 0x18]
//         00486e4f     MOV        EDX,dword ptr [ESP + 0x1c]
//         00486e53     MOV        EAX,dword ptr [EBX]
//         00486e55     PUSH       0x1
//         00486e57     PUSH       0x0=>DAT_fffffff8
//         00486e59     PUSH       this=>DAT_fffffff4
//         00486e5a     MOV        this,dword ptr [ESP + 0x58]
//         00486e5e     PUSH       EDX=>DAT_fffffff0
//         00486e5f     MOV        EDX,dword ptr [this->_padding_]
//         00486e61     MOV        this,EBX
//         00486e63     PUSH       EDX
//         00486e64     CALL       dword ptr [EAX + 0x94]
//                              rmm_obj.cpp:621 (4)
//         00486e6a     MOV        EDX,dword ptr [ESP + 0x50]
//                              rmm_obj.cpp:622 (19)
//         00486e6e     MOV        EAX,dword ptr [ESI + 0x24]
//         00486e71     MOV        this,dword ptr [ESP + 0x10]
//         00486e75     DEC        EDX
//         00486e76     MOV        dword ptr [ESP + 0x50],EDX
//         00486e7a     MOV        EDX,dword ptr [EAX + this->_padding_*0x4]
//         00486e7d     MOV        EAX,dword ptr [ESP + 0x14]
//                              rmm_obj.cpp:623 (33)
//         00486e81     MOV        this,dword ptr [ESP + 0x54]
//         00486e85     MOV        byte ptr [EDX + EAX*0x1],0x0
//         00486e89     MOV        EAX,dword ptr [ESP + 0x14]
//         00486e8d     CMP        EAX,this
//         00486e8f     JLE        LAB_00486ee3
//         00486e91     MOV        EDX,dword ptr [ESI + 0x24]
//         00486e94     MOV        this,dword ptr [ESP + 0x10]
//         00486e98     MOV        EDX,dword ptr [EDX + this->_padding_*0x4]
//         00486e9b     CMP        byte ptr [EDX + EAX*0x1 + -0x1],0x0
//         00486ea0     JZ         LAB_00486ee7
//                              rmm_obj.cpp:624 (69)
//         00486ea2     PUSH       0x270
//         00486ea7     PUSH       s_C:\msdev\work\age1_x1\rmm_obj.cp               = "C:\\msdev\\work\\age1_x1\\rmm_obj.cpp"
//         00486eac     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
//         00486eb1     ADD        ESP,0x8
//         00486eb4     MOV        dword ptr [ESP + 0x58],EAX
//         00486eb8     FILD       dword ptr [ESP + 0x58]
//         00486ebc     MOV        EAX,dword ptr [ESP + 0x10]
//         00486ec0     PUSH       this
//         00486ec1     MOV        this,dword ptr [ESP + 0x18]
//         00486ec5     LEA        EDX,[ESP + 0x34]
//         00486ec9     FSTP       float ptr [ESP]
//         00486ecc     PUSH       0x0=>DAT_fffffff8
//         00486ece     DEC        this
//         00486ecf     PUSH       EAX=>DAT_fffffff4
//         00486ed0     PUSH       this=>DAT_fffffff0
//         00486ed1     PUSH       EDX
//         00486ed2     MOV        this,ESI
//         00486ed4     CALL       RGE_Random_Map_Module::push_stack                void push_stack(RGE_Random_Map_Module * this,
//         00486ed9     MOV        this,dword ptr [ESP + 0x10]
//         00486edd     MOV        EAX,dword ptr [ESP + 0x14]
//         00486ee1     JMP        LAB_00486ee7
//                               LAB_00486ee3                                                 XREF[1]:     00486e8f(j)
//         00486ee3     MOV        this,dword ptr [ESP + 0x10]
//                               LAB_00486ee7                                                 XREF[2]:     00486ea0(j), 00486ee1(j)
//                              rmm_obj.cpp:626 (19)
//         00486ee7     CMP        EAX,dword ptr [ESP + 0x20]
//         00486eeb     JGE        LAB_00486f39
//         00486eed     MOV        EDX,dword ptr [ESI + 0x24]
//         00486ef0     MOV        EDX,dword ptr [EDX + this->_padding_*0x4]
//         00486ef3     CMP        byte ptr [EDX + EAX*0x1 + 0x1],0x0
//         00486ef8     JZ         LAB_00486f39
//                              rmm_obj.cpp:627 (63)
//         00486efa     PUSH       0x273
//         00486eff     PUSH       s_C:\msdev\work\age1_x1\rmm_obj.cp               = "C:\\msdev\\work\\age1_x1\\rmm_obj.cpp"
//         00486f04     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
//         00486f09     ADD        ESP,0x8
//         00486f0c     MOV        dword ptr [ESP + 0x58],EAX
//         00486f10     FILD       dword ptr [ESP + 0x58]
//         00486f14     MOV        EAX,dword ptr [ESP + 0x10]
//         00486f18     PUSH       this
//         00486f19     MOV        this,dword ptr [ESP + 0x18]
//         00486f1d     LEA        EDX,[ESP + 0x34]
//         00486f21     FSTP       float ptr [ESP]
//         00486f24     PUSH       0x0=>DAT_fffffff8
//         00486f26     INC        this
//         00486f27     PUSH       EAX=>DAT_fffffff4
//         00486f28     PUSH       this=>DAT_fffffff0
//         00486f29     PUSH       EDX
//         00486f2a     MOV        this,ESI
//         00486f2c     CALL       RGE_Random_Map_Module::push_stack                void push_stack(RGE_Random_Map_Module * this,
//         00486f31     MOV        this,dword ptr [ESP + 0x10]
//         00486f35     MOV        EAX,dword ptr [ESP + 0x14]
//                               LAB_00486f39                                                 XREF[2]:     00486eeb(j), 00486ef8(j)
//                              rmm_obj.cpp:629 (19)
//         00486f39     CMP        this,dword ptr [ESP + 0x24]
//         00486f3d     JLE        LAB_00486f8b
//         00486f3f     MOV        EDX,dword ptr [ESI + 0x24]
//         00486f42     MOV        EDX,dword ptr [EDX + this->_padding_*0x4 + -0x4]
//         00486f46     CMP        byte ptr [EDX + EAX*0x1],0x0
//         00486f4a     JZ         LAB_00486f8b
//                              rmm_obj.cpp:630 (63)
//         00486f4c     PUSH       0x276
//         00486f51     PUSH       s_C:\msdev\work\age1_x1\rmm_obj.cp               = "C:\\msdev\\work\\age1_x1\\rmm_obj.cpp"
//         00486f56     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
//         00486f5b     ADD        ESP,0x8
//         00486f5e     MOV        dword ptr [ESP + 0x58],EAX
//         00486f62     FILD       dword ptr [ESP + 0x58]
//         00486f66     MOV        EAX,dword ptr [ESP + 0x10]
//         00486f6a     PUSH       this
//         00486f6b     MOV        this,dword ptr [ESP + 0x18]
//         00486f6f     DEC        EAX
//         00486f70     FSTP       float ptr [ESP]
//         00486f73     PUSH       0x0=>DAT_fffffff8
//         00486f75     PUSH       EAX=>DAT_fffffff4
//         00486f76     LEA        EDX,[ESP + 0x3c]
//         00486f7a     PUSH       this=>DAT_fffffff0
//         00486f7b     PUSH       EDX
//         00486f7c     MOV        this,ESI
//         00486f7e     CALL       RGE_Random_Map_Module::push_stack                void push_stack(RGE_Random_Map_Module * this,
//         00486f83     MOV        this,dword ptr [ESP + 0x10]
//         00486f87     MOV        EAX,dword ptr [ESP + 0x14]
//                               LAB_00486f8b                                                 XREF[2]:     00486f3d(j), 00486f4a(j)
//                              rmm_obj.cpp:632 (19)
//         00486f8b     CMP        this,dword ptr [ESP + 0x28]
//         00486f8f     JGE        LAB_00486fd5
//         00486f91     MOV        EDX,dword ptr [ESI + 0x24]
//         00486f94     MOV        this,dword ptr [EDX + this->_padding_*0x4 + 0x4]
//         00486f98     CMP        byte ptr [this->_padding_ + EAX*0x1],0x0
//         00486f9c     JZ         LAB_00486fd5
//                              rmm_obj.cpp:633 (90)
//         00486f9e     PUSH       0x279
//         00486fa3     PUSH       s_C:\msdev\work\age1_x1\rmm_obj.cp               = "C:\\msdev\\work\\age1_x1\\rmm_obj.cpp"
//         00486fa8     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
//         00486fad     MOV        EDX,dword ptr [ESP + 0x18]
//         00486fb1     ADD        ESP,0x8
//         00486fb4     MOV        dword ptr [ESP + 0x58],EAX
//         00486fb8     MOV        EAX,dword ptr [ESP + 0x14]
//         00486fbc     FILD       dword ptr [ESP + 0x58]
//         00486fc0     PUSH       this
//         00486fc1     INC        EDX
//         00486fc2     LEA        this,[ESP + 0x34]
//         00486fc6     FSTP       float ptr [ESP]
//         00486fc9     PUSH       0x0=>DAT_fffffff8
//         00486fcb     PUSH       EDX=>DAT_fffffff4
//         00486fcc     PUSH       EAX=>DAT_fffffff0
//         00486fcd     PUSH       this
//         00486fce     MOV        this,ESI
//         00486fd0     CALL       RGE_Random_Map_Module::push_stack                void push_stack(RGE_Random_Map_Module * this,
//                               LAB_00486fd5                                                 XREF[3]:     00486e45(j), 00486f8f(j),
//                                                                                                         00486f9c(j)
//         00486fd5     LEA        EDX,[ESP + 0x2c]
//         00486fd9     LEA        EAX,[ESP + 0x10]
//         00486fdd     PUSH       EDX
//         00486fde     LEA        this,[ESP + 0x18]
//         00486fe2     PUSH       EAX=>DAT_fffffff8
//         00486fe3     LEA        EDX,[ESP + 0x38]
//         00486fe7     PUSH       this=>DAT_fffffff4
//         00486fe8     PUSH       EDX=>DAT_fffffff0
//         00486fe9     MOV        this,ESI
//         00486feb     CALL       RGE_Random_Map_Module::pop_stack                 Map_Stack * pop_stack(RGE_Random_Map_Module *
//         00486ff0     TEST       EAX,EAX
//         00486ff2     JNZ        LAB_00486d84
//                               LAB_00486ff8                                                 XREF[2]:     00486d78(j), 00486d8a(j)
//                              rmm_obj.cpp:637 (12)
//         00486ff8     LEA        EAX=>obj_stack.y,[ESP + 0x30]
//         00486ffc     MOV        this,ESI
//         00486ffe     PUSH       EAX
//         00486fff     CALL       RGE_Random_Map_Module::deinit_stack              void deinit_stack(RGE_Random_Map_Module * thi
//                              rmm_obj.cpp:638 (10)
//         00487004     POP        EDI
//         00487005     POP        ESI
//         00487006     POP        EBP
//         00487007     POP        EBX
//         00487008     ADD        ESP,0x38
//         0048700b     RET        0x10
//         0048700e     ??         90h
//         0048700f     NOP
    return;
}

