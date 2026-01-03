#include "../common.h"
#include "rmm_dbct.h"

RGE_RMM_Database_Controller::RGE_RMM_Database_Controller(char* param_1, char* param_2, char* param_3, char* param_4) {
    /* TODO: Stub */
//                              undefined __thiscall RGE_RMM_Database_Controller(RGE_RMM_Database_Co
//              undefined         <UNASSIGNED>   <RETURN>
//              RGE_RMM_Databa    ECX:4 (auto)   this
//              char *            Stack[0x4]:4   param_1                   XREF[1]:     00482c52(R)
//              char *            Stack[0x8]:4   param_2                   XREF[1]:     00482dd1(R)
//              char *            Stack[0xc]:4   param_3                   XREF[1]:     00482ec6(R)
//              char *            Stack[0x10]:4  param_4                   XREF[10]:    00482b87(R), 00482c8b(W), 00482db3(R), 00482dbe(W),
//                                                                                     00482e06(W), 00482ea8(R), 00482eb3(W), 00482efb(W),
//                                                                                     00482fc6(R), 00482fd1(W)
//              undefined         Stack[-0x4]:1  local_4                   XREF[2]:     00482f7f(*), 00482fac(R)
//              long              Stack[-0x8]:4  temp_scale_flag           XREF[2]:     00482f85(*), 00482f9d(R)
//              long              Stack[-0xc]:4  temp_group_flag           XREF[2]:     00482d1e(*), 00482d8b(R)
//              long              Stack[-0x10]:4 temp_by_player_flag       XREF[2]:     00482d24(*), 00482d80(R)
//              long              Stack[-0x14]:4 temp_amount_of_land_used  XREF[2]:     00482d30(*), 00482d75(R)
//              long              Stack[-0x18]:4 temp_placement_type       XREF[2]:     00482d36(*), 00482d6a(R)
//              long              Stack[-0x1c]:4 temp_zone                 XREF[2]:     00482d42(*), 00482d5b(R)
//              long              Stack[-0x20]:4 temp_terrain_type         XREF[3]:     00482ee2(*), 00482ef2(R), 00482fca(R)
//              long              Stack[-0x24]:4 object_num                XREF[3]:     00482ded(*), 00482dfd(R), 00482eac(R)
//              long              Stack[-0x28]:4 terrain_num               XREF[3]:     00482c72(*), 00482c82(R), 00482db7(R)
//              long              Stack[-0x2c]:4 land_num                  XREF[4]:     00482b7e(W), 00482dab(R), 00482e9f(R), 00482fbd(R)
//              undefined4        Stack[-0x30]:4 local_30                  XREF[6]:     00482c99(*), 00482ca9(R), 00482e14(*), 00482e24(R),
//                                                                                     00482f09(*), 00482f19(R)
//              long              Stack[-0x34]:4 map_id                    XREF[6]:     00482bb0(W), 00482bfa(R), 00482c18(R), 00482c68(W),
//                                                                                     00482d47(R), 00482daf(R)
//              _iobuf *          Stack[-0x38]:4 infile
//                               ??0RGE_RMM_Database_Controller@@QAE@PAD000@Z                 XREF[2]:     load_random_map:0045586c(c),
//                               RGE_RMM_Database_Controller::RGE_RMM_Database_Controller                  TRIBE_RMM_Database_Controller:0048
//                              rmm_dbct.cpp:29 (23)
//         00482b70     SUB        ESP,0x34
//         00482b73     PUSH       EBX
//         00482b74     PUSH       EBP
//         00482b75     PUSH       ESI
//         00482b76     XOR        ESI,ESI
//         00482b78     PUSH       EDI
//         00482b79     PUSH       ESI
//         00482b7a     MOV        EDI,this
//         00482b7c     PUSH       ESI
//         00482b7d     PUSH       ESI
//         00482b7e     MOV        dword ptr [ESP + land_num],EDI
//         00482b82     CALL       RGE_Random_Map_Module::RGE_Random_Map_Module     undefined RGE_Random_Map_Module(RGE_Random_Ma
//                              rmm_dbct.cpp:55 (39)
//         00482b87     MOV        EAX,dword ptr [ESP + param_4]
//         00482b8b     PUSH       s_r                                              = "r"
//         00482b90     PUSH       EAX
//         00482b91     MOV        dword ptr [EDI],RGE_RMM_Database_Controller::`   = 00483430
//         00482b97     MOV        dword ptr [EDI + 0x30],ESI
//         00482b9a     MOV        dword ptr [EDI + 0x34],0xffffffff
//         00482ba1     MOV        dword ptr [EDI + 0x38],ESI
//         00482ba4     CALL       fopen                                            undefined fopen()
//         00482ba9     MOV        EBX,EAX
//         00482bab     ADD        ESP,0x8
//                              rmm_dbct.cpp:56 (12)
//         00482bae     CMP        EBX,ESI
//         00482bb0     MOV        dword ptr [ESP + map_id],EBX
//         00482bb4     JZ         LAB_00482c3a
//                              rmm_dbct.cpp:58 (18)
//         00482bba     LEA        EBP,[EDI + 0x4f54]
//         00482bc0     PUSH       EBP
//         00482bc1     PUSH       s__%d                                            = " %d"
//         00482bc6     PUSH       EBX
//         00482bc7     CALL       fscanf                                           undefined fscanf()
//                              rmm_dbct.cpp:60 (10)
//         00482bcc     MOV        EAX,dword ptr [EBP]
//         00482bcf     ADD        ESP,0xc
//         00482bd2     CMP        EAX,ESI
//         00482bd4     JLE        LAB_00482c29
//                              rmm_dbct.cpp:62 (14)
//         00482bd6     PUSH       0x48
//         00482bd8     PUSH       EAX
//         00482bd9     CALL       calloc                                           undefined calloc()
//         00482bde     MOV        dword ptr [EDI + 0x4f58],EAX
//                              rmm_dbct.cpp:63 (10)
//         00482be4     MOV        EAX,dword ptr [EBP]
//         00482be7     ADD        ESP,0x8
//         00482bea     CMP        EAX,ESI
//         00482bec     JLE        LAB_00482c2f
//                              rmm_dbct.cpp:242 (2)
//         00482bee     XOR        EBX,EBX
//                               LAB_00482bf0                                                 XREF[1]:     00482c16(j)
//                              rmm_dbct.cpp:64 (40)
//         00482bf0     MOV        EDX,dword ptr [EDI + 0x4f58]
//         00482bf6     MOV        this,EBX
//         00482bf8     ADD        this,EDX
//         00482bfa     MOV        EDX,dword ptr [ESP + map_id]
//         00482bfe     PUSH       this
//         00482bff     PUSH       s_%d                                             = 6425h
//         00482c04     PUSH       EDX
//         00482c05     CALL       fscanf                                           undefined fscanf()
//         00482c0a     MOV        EAX,dword ptr [EBP]
//         00482c0d     ADD        ESP,0xc
//         00482c10     INC        ESI
//         00482c11     ADD        EBX,0x48
//         00482c14     CMP        ESI,EAX
//         00482c16     JL         LAB_00482bf0
//                              rmm_dbct.cpp:66 (6)
//         00482c18     MOV        EBX,dword ptr [ESP + map_id]
//         00482c1c     XOR        ESI,ESI
//                              rmm_dbct.cpp:69 (9)
//         00482c1e     PUSH       EBX
//         00482c1f     CALL       fclose                                           undefined fclose()
//         00482c24     ADD        ESP,0x4
//                              rmm_dbct.cpp:71 (2)
//         00482c27     JMP        LAB_00482c49
//                               LAB_00482c29                                                 XREF[1]:     00482bd4(j)
//                              rmm_dbct.cpp:67 (6)
//         00482c29     MOV        dword ptr [EDI + 0x4f58],ESI
//                               LAB_00482c2f                                                 XREF[1]:     00482bec(j)
//                              rmm_dbct.cpp:69 (9)
//         00482c2f     PUSH       EBX
//         00482c30     CALL       fclose                                           undefined fclose()
//         00482c35     ADD        ESP,0x4
//                              rmm_dbct.cpp:71 (2)
//         00482c38     JMP        LAB_00482c49
//                               LAB_00482c3a                                                 XREF[1]:     00482bb4(j)
//                              rmm_dbct.cpp:74 (15)
//         00482c3a     LEA        EBP,[EDI + 0x4f54]
//         00482c40     MOV        dword ptr [EDI + 0x4f58],ESI
//         00482c46     MOV        dword ptr [EBP],ESI
//                               LAB_00482c49                                                 XREF[2]:     00482c27(j), 00482c38(j)
//                              rmm_dbct.cpp:77 (9)
//         00482c49     CMP        dword ptr [EBP],ESI
//         00482c4c     JLE        LAB_00482ff0
//                              rmm_dbct.cpp:81 (20)
//         00482c52     MOV        EAX,dword ptr [ESP + param_1]
//         00482c56     PUSH       s_r                                              = "r"
//         00482c5b     PUSH       EAX
//         00482c5c     CALL       fopen                                            undefined fopen()
//         00482c61     MOV        EBP,EAX
//         00482c63     ADD        ESP,0x8
//                              rmm_dbct.cpp:82 (12)
//         00482c66     TEST       EBP,EBP
//         00482c68     MOV        dword ptr [ESP + map_id],EBP
//         00482c6c     JZ         LAB_00482dd1
//                              rmm_dbct.cpp:84 (16)
//         00482c72     LEA        this=>terrain_num,[ESP + 0x1c]
//         00482c76     PUSH       this
//         00482c77     PUSH       s_%d                                             = 6425h
//         00482c7c     PUSH       EBP
//         00482c7d     CALL       fscanf                                           undefined fscanf()
//                              rmm_dbct.cpp:85 (23)
//         00482c82     MOV        EAX,dword ptr [ESP + terrain_num]
//         00482c86     ADD        ESP,0xc
//         00482c89     TEST       EAX,EAX
//         00482c8b     MOV        dword ptr [ESP + param_4],0x0
//         00482c93     JLE        LAB_00482dc8
//                               LAB_00482c99                                                 XREF[1]:     00482dc2(j)
//                              rmm_dbct.cpp:87 (16)
//         00482c99     LEA        EDX=>local_30,[ESP + 0x14]
//         00482c9d     PUSH       EDX
//         00482c9e     PUSH       s_%d                                             = 6425h
//         00482ca3     PUSH       EBP
//         00482ca4     CALL       fscanf                                           undefined fscanf()
//                              rmm_dbct.cpp:88 (20)
//         00482ca9     MOV        EAX,dword ptr [ESP + local_30]
//         00482cad     MOV        this,dword ptr [EDI + 0x4f58]
//         00482cb3     ADD        ESP,0xc
//         00482cb6     LEA        EAX,[EAX + EAX*0x8]
//         00482cb9     LEA        ESI,[ECX + EAX*0x8 + this->_padding_]
//                              rmm_dbct.cpp:98 (44)
//         00482cbd     LEA        EDX,[ESI + 0x1c]
//         00482cc0     LEA        EAX,[ESI + 0x18]
//         00482cc3     PUSH       EDX
//         00482cc4     LEA        this,[ESI + 0x14]
//         00482cc7     PUSH       EAX
//         00482cc8     LEA        EDX,[ESI + 0x10]
//         00482ccb     PUSH       this
//         00482ccc     LEA        EAX,[ESI + 0xc]
//         00482ccf     PUSH       EDX
//         00482cd0     LEA        this,[ESI + 0x8]
//         00482cd3     PUSH       EAX
//         00482cd4     LEA        EDX,[ESI + 0x4]
//         00482cd7     PUSH       this
//         00482cd8     LEA        EBX,[ESI + 0x24]
//         00482cdb     PUSH       EDX
//         00482cdc     PUSH       ESI
//         00482cdd     PUSH       EBX
//         00482cde     PUSH       s_%d_%d_%d_%d_%d_%d_%d_%d_%d                     = "%d %d %d %d %d %d %d %d %d"
//         00482ce3     PUSH       EBP
//         00482ce4     CALL       fscanf                                           undefined fscanf()
//                              rmm_dbct.cpp:100 (13)
//         00482ce9     MOV        EAX,dword ptr [EBX]
//         00482ceb     ADD        ESP,0x2c
//         00482cee     TEST       EAX,EAX
//         00482cf0     JLE        LAB_00483005
//                              rmm_dbct.cpp:102 (11)
//         00482cf6     PUSH       0x2c
//         00482cf8     PUSH       EAX
//         00482cf9     CALL       calloc                                           undefined calloc()
//         00482cfe     MOV        dword ptr [ESI + 0x28],EAX
//                              rmm_dbct.cpp:103 (15)
//         00482d01     MOV        EAX,dword ptr [EBX]
//         00482d03     ADD        ESP,0x8
//         00482d06     XOR        EBP,EBP
//         00482d08     TEST       EAX,EAX
//         00482d0a     JLE        LAB_00482daf
//                              rmm_dbct.cpp:242 (2)
//         00482d10     XOR        EDI,EDI
//                               LAB_00482d12                                                 XREF[1]:     00482da5(j)
//                              rmm_dbct.cpp:117 (70)
//         00482d12     MOV        EAX,dword ptr [ESI + 0x28]
//         00482d15     ADD        EAX,EDI
//         00482d17     LEA        this,[EAX + 0x24]
//         00482d1a     LEA        EDX,[EAX + 0x20]
//         00482d1d     PUSH       this
//         00482d1e     LEA        this=>temp_group_flag,[ESP + 0x3c]
//         00482d22     PUSH       EDX
//         00482d23     PUSH       this
//         00482d24     LEA        EDX=>temp_by_player_flag,[ESP + 0x40]
//         00482d28     LEA        this,[EAX + 0x18]
//         00482d2b     PUSH       EDX
//         00482d2c     PUSH       this
//         00482d2d     LEA        EDX,[EAX + 0x14]
//         00482d30     LEA        this=>temp_amount_of_land_used_percent,[ESP +
//         00482d34     PUSH       EDX
//         00482d35     PUSH       this
//         00482d36     LEA        EDX=>temp_placement_type,[ESP + 0x48]
//         00482d3a     LEA        this,[EAX + 0xc]
//         00482d3d     PUSH       EDX
//         00482d3e     PUSH       this
//         00482d3f     LEA        EDX,[EAX + 0x8]
//         00482d42     LEA        this=>temp_zone,[ESP + 0x4c]
//         00482d46     PUSH       EDX
//         00482d47     MOV        EDX,dword ptr [ESP + map_id]
//         00482d4b     PUSH       this
//         00482d4c     PUSH       EAX
//         00482d4d     PUSH       s_%d_%d_%d_%d_%d_%d_%d_%d_%d_%d_%d               = "%d %d %d %d %d %d %d %d %d %d %d %d"
//         00482d52     PUSH       EDX
//         00482d53     CALL       fscanf                                           undefined fscanf()
//                              rmm_dbct.cpp:119 (15)
//         00482d58     MOV        EAX,dword ptr [ESI + 0x28]
//         00482d5b     MOV        this,byte ptr [ESP + temp_zone]
//         00482d5f     ADD        ESP,0x38
//         00482d62     INC        EBP
//         00482d63     MOV        byte ptr [EAX + EDI*0x1 + 0x4],this
//                              rmm_dbct.cpp:120 (11)
//         00482d67     MOV        EDX,dword ptr [ESI + 0x28]
//         00482d6a     MOV        AL,byte ptr [ESP + temp_placement_type]
//         00482d6e     MOV        byte ptr [EDX + EDI*0x1 + 0x10],AL
//                              rmm_dbct.cpp:121 (11)
//         00482d72     MOV        this,dword ptr [ESI + 0x28]
//         00482d75     MOV        DL,byte ptr [ESP + temp_amount_of_land_used_pe
//         00482d79     MOV        byte ptr [ECX + EDI*0x1 + this+0x11],DL
//                              rmm_dbct.cpp:122 (11)
//         00482d7d     MOV        EAX,dword ptr [ESI + 0x28]
//         00482d80     MOV        this,byte ptr [ESP + temp_by_player_flag]
//         00482d84     MOV        byte ptr [EAX + EDI*0x1 + 0x1c],this
//                              rmm_dbct.cpp:123 (11)
//         00482d88     MOV        EDX,dword ptr [ESI + 0x28]
//         00482d8b     MOV        AL,byte ptr [ESP + temp_group_flag]
//         00482d8f     MOV        byte ptr [EDX + EDI*0x1 + 0x1d],AL
//                              rmm_dbct.cpp:125 (24)
//         00482d93     MOV        this,dword ptr [ESI + 0x28]
//         00482d96     MOV        dword ptr [ECX + EDI*0x1 + this->_padding_],0x8
//         00482d9e     MOV        EAX,dword ptr [EBX]
//         00482da0     ADD        EDI,0x2c
//         00482da3     CMP        EBP,EAX
//         00482da5     JL         LAB_00482d12
//                              rmm_dbct.cpp:128 (8)
//         00482dab     MOV        EDI,dword ptr [ESP + land_num]
//                               LAB_00482daf                                                 XREF[1]:     00482d0a(j)
//         00482daf     MOV        EBP,dword ptr [ESP + map_id]
//                               LAB_00482db3                                                 XREF[1]:     0048300c(j)
//                              rmm_dbct.cpp:85 (21)
//         00482db3     MOV        EAX,dword ptr [ESP + param_4]
//         00482db7     MOV        this,dword ptr [ESP + terrain_num]
//         00482dbb     INC        EAX
//         00482dbc     CMP        EAX,this
//         00482dbe     MOV        dword ptr [ESP + param_4],EAX
//         00482dc2     JL         LAB_00482c99
//                               LAB_00482dc8                                                 XREF[1]:     00482c93(j)
//                              rmm_dbct.cpp:131 (9)
//         00482dc8     PUSH       EBP
//         00482dc9     CALL       fclose                                           undefined fclose()
//         00482dce     ADD        ESP,0x4
//                               LAB_00482dd1                                                 XREF[1]:     00482c6c(j)
//                              rmm_dbct.cpp:135 (20)
//         00482dd1     MOV        EDX,dword ptr [ESP + param_2]
//         00482dd5     PUSH       s_r                                              = "r"
//         00482dda     PUSH       EDX
//         00482ddb     CALL       fopen                                            undefined fopen()
//         00482de0     MOV        EBP,EAX
//         00482de2     ADD        ESP,0x8
//                              rmm_dbct.cpp:136 (8)
//         00482de5     TEST       EBP,EBP
//         00482de7     JZ         LAB_00482ec6
//                              rmm_dbct.cpp:138 (16)
//         00482ded     LEA        EAX=>object_num,[ESP + 0x20]
//         00482df1     PUSH       EAX
//         00482df2     PUSH       s_%d                                             = 6425h
//         00482df7     PUSH       EBP
//         00482df8     CALL       fscanf                                           undefined fscanf()
//                              rmm_dbct.cpp:139 (23)
//         00482dfd     MOV        EAX,dword ptr [ESP + object_num]
//         00482e01     ADD        ESP,0xc
//         00482e04     TEST       EAX,EAX
//         00482e06     MOV        dword ptr [ESP + param_4],0x0
//         00482e0e     JLE        LAB_00482ebd
//                               LAB_00482e14                                                 XREF[1]:     00482eb7(j)
//                              rmm_dbct.cpp:141 (16)
//         00482e14     LEA        this=>local_30,[ESP + 0x14]
//         00482e18     PUSH       this
//         00482e19     PUSH       s_%d                                             = 6425h
//         00482e1e     PUSH       EBP
//         00482e1f     CALL       fscanf                                           undefined fscanf()
//                              rmm_dbct.cpp:142 (20)
//         00482e24     MOV        EAX,dword ptr [ESP + local_30]
//         00482e28     ADD        ESP,0xc
//         00482e2b     LEA        EDX,[EAX + EAX*0x8]
//         00482e2e     MOV        EAX,dword ptr [EDI + 0x4f58]
//         00482e34     LEA        ESI,[EAX + EDX*0x8 + 0x30]
//                              rmm_dbct.cpp:143 (12)
//         00482e38     PUSH       ESI
//         00482e39     PUSH       s_%d                                             = 6425h
//         00482e3e     PUSH       EBP
//         00482e3f     CALL       fscanf                                           undefined fscanf()
//                              rmm_dbct.cpp:145 (11)
//         00482e44     MOV        EAX,dword ptr [ESI]
//         00482e46     XOR        EBX,EBX
//         00482e48     ADD        ESP,0xc
//         00482e4b     CMP        EAX,EBX
//         00482e4d     JLE        LAB_00482ea5
//                              rmm_dbct.cpp:147 (11)
//         00482e4f     PUSH       0x18
//         00482e51     PUSH       EAX
//         00482e52     CALL       calloc                                           undefined calloc()
//         00482e57     MOV        dword ptr [ESI + 0x4],EAX
//                              rmm_dbct.cpp:148 (9)
//         00482e5a     MOV        EAX,dword ptr [ESI]
//         00482e5c     ADD        ESP,0x8
//         00482e5f     TEST       EAX,EAX
//         00482e61     JLE        LAB_00482ea8
//                              rmm_dbct.cpp:242 (2)
//         00482e63     XOR        EDI,EDI
//                               LAB_00482e65                                                 XREF[1]:     00482e9d(j)
//                              rmm_dbct.cpp:155 (34)
//         00482e65     MOV        this,dword ptr [ESI + 0x4]
//         00482e68     LEA        EAX,[this->_padding_ + EDI*0x1]
//         00482e6b     LEA        EDX,[EAX + 0x10]
//         00482e6e     LEA        this,[EAX + 0xc]
//         00482e71     PUSH       EDX
//         00482e72     PUSH       this
//         00482e73     LEA        EDX,[EAX + 0x8]
//         00482e76     LEA        this,[EAX + 0x4]
//         00482e79     PUSH       EDX
//         00482e7a     PUSH       this
//         00482e7b     PUSH       EAX
//         00482e7c     PUSH       s_%d_%d_%d_%d_%d                                 = "%d %d %d %d %d"
//         00482e81     PUSH       EBP
//         00482e82     CALL       fscanf                                           undefined fscanf()
//                              rmm_dbct.cpp:156 (24)
//         00482e87     MOV        EDX,dword ptr [ESI + 0x4]
//         00482e8a     ADD        ESP,0x1c
//         00482e8d     INC        EBX
//         00482e8e     MOV        dword ptr [EDX + EDI*0x1 + 0x14],0x14
//         00482e96     MOV        EAX,dword ptr [ESI]
//         00482e98     ADD        EDI,0x18
//         00482e9b     CMP        EBX,EAX
//         00482e9d     JL         LAB_00482e65
//                              rmm_dbct.cpp:159 (6)
//         00482e9f     MOV        EDI,dword ptr [ESP + land_num]
//         00482ea3     JMP        LAB_00482ea8
//                               LAB_00482ea5                                                 XREF[1]:     00482e4d(j)
//                              rmm_dbct.cpp:160 (3)
//         00482ea5     MOV        dword ptr [ESI + 0x4],EBX
//                               LAB_00482ea8                                                 XREF[2]:     00482e61(j), 00482ea3(j)
//                              rmm_dbct.cpp:139 (21)
//         00482ea8     MOV        EAX,dword ptr [ESP + param_4]
//         00482eac     MOV        this,dword ptr [ESP + object_num]
//         00482eb0     INC        EAX
//         00482eb1     CMP        EAX,this
//         00482eb3     MOV        dword ptr [ESP + param_4],EAX
//         00482eb7     JL         LAB_00482e14
//                               LAB_00482ebd                                                 XREF[1]:     00482e0e(j)
//                              rmm_dbct.cpp:162 (9)
//         00482ebd     PUSH       EBP
//         00482ebe     CALL       fclose                                           undefined fclose()
//         00482ec3     ADD        ESP,0x4
//                               LAB_00482ec6                                                 XREF[1]:     00482de7(j)
//                              rmm_dbct.cpp:166 (20)
//         00482ec6     MOV        EAX,dword ptr [ESP + param_3]
//         00482eca     PUSH       s_r                                              = "r"
//         00482ecf     PUSH       EAX
//         00482ed0     CALL       fopen                                            undefined fopen()
//         00482ed5     MOV        EBP,EAX
//         00482ed7     ADD        ESP,0x8
//                              rmm_dbct.cpp:167 (8)
//         00482eda     TEST       EBP,EBP
//         00482edc     JZ         LAB_00482ff9
//                              rmm_dbct.cpp:169 (16)
//         00482ee2     LEA        this=>temp_terrain_type,[ESP + 0x24]
//         00482ee6     PUSH       this
//         00482ee7     PUSH       s_%d                                             = 6425h
//         00482eec     PUSH       EBP
//         00482eed     CALL       fscanf                                           undefined fscanf()
//                              rmm_dbct.cpp:170 (23)
//         00482ef2     MOV        EAX,dword ptr [ESP + temp_terrain_type]
//         00482ef6     ADD        ESP,0xc
//         00482ef9     TEST       EAX,EAX
//         00482efb     MOV        dword ptr [ESP + param_4],0x0
//         00482f03     JLE        LAB_00482fdb
//                               LAB_00482f09                                                 XREF[1]:     00482fd5(j)
//                              rmm_dbct.cpp:172 (16)
//         00482f09     LEA        EDX=>local_30,[ESP + 0x14]
//         00482f0d     PUSH       EDX
//         00482f0e     PUSH       s_%d                                             = 6425h
//         00482f13     PUSH       EBP
//         00482f14     CALL       fscanf                                           undefined fscanf()
//                              rmm_dbct.cpp:173 (20)
//         00482f19     MOV        EAX,dword ptr [ESP + local_30]
//         00482f1d     MOV        this,dword ptr [EDI + 0x4f58]
//         00482f23     ADD        ESP,0xc
//         00482f26     LEA        EAX,[EAX + EAX*0x8]
//         00482f29     LEA        ESI,[ECX + EAX*0x8 + this->number_of_players]
//                              rmm_dbct.cpp:174 (12)
//         00482f2d     PUSH       ESI
//         00482f2e     PUSH       s_%d                                             = 6425h
//         00482f33     PUSH       EBP
//         00482f34     CALL       fscanf                                           undefined fscanf()
//                              rmm_dbct.cpp:176 (11)
//         00482f39     MOV        EAX,dword ptr [ESI]
//         00482f3b     XOR        EBX,EBX
//         00482f3d     ADD        ESP,0xc
//         00482f40     CMP        EAX,EBX
//         00482f42     JLE        LAB_00482fc3
//                              rmm_dbct.cpp:178 (11)
//         00482f44     PUSH       0x2c
//         00482f46     PUSH       EAX
//         00482f47     CALL       calloc                                           undefined calloc()
//         00482f4c     MOV        dword ptr [ESI + 0x4],EAX
//                              rmm_dbct.cpp:179 (9)
//         00482f4f     MOV        EAX,dword ptr [ESI]
//         00482f51     ADD        ESP,0x8
//         00482f54     TEST       EAX,EAX
//         00482f56     JLE        LAB_00482fc6
//                              rmm_dbct.cpp:242 (2)
//         00482f58     XOR        EDI,EDI
//                               LAB_00482f5a                                                 XREF[1]:     00482fbb(j)
//                              rmm_dbct.cpp:193 (64)
//         00482f5a     MOV        EDX,dword ptr [ESI + 0x4]
//         00482f5d     LEA        EAX,[EDX + EDI*0x1]
//         00482f60     LEA        this,[EAX + 0x28]
//         00482f63     LEA        EDX,[EAX + 0x24]
//         00482f66     PUSH       this
//         00482f67     LEA        this,[EAX + 0x20]
//         00482f6a     PUSH       EDX
//         00482f6b     PUSH       this
//         00482f6c     LEA        EDX,[EAX + 0x1c]
//         00482f6f     LEA        this,[EAX + 0x18]
//         00482f72     PUSH       EDX
//         00482f73     PUSH       this
//         00482f74     LEA        EDX,[EAX + 0x14]
//         00482f77     LEA        this,[EAX + 0x10]
//         00482f7a     PUSH       EDX
//         00482f7b     PUSH       this
//         00482f7c     LEA        EDX,[EAX + 0xc]
//         00482f7f     LEA        this=>local_4,[ESP + 0x5c]
//         00482f83     PUSH       EDX
//         00482f84     PUSH       this
//         00482f85     LEA        EDX=>temp_scale_flag,[ESP + 0x60]
//         00482f89     LEA        this,[EAX + 0x4]
//         00482f8c     PUSH       EDX
//         00482f8d     PUSH       this
//         00482f8e     PUSH       EAX
//         00482f8f     PUSH       s_%d_%d_%d_%d_%d_%d_%d_%d_%d_%d_%d               = "%d %d %d %d %d %d %d %d %d %d %d %d"
//         00482f94     PUSH       EBP
//         00482f95     CALL       fscanf                                           undefined fscanf()
//                              rmm_dbct.cpp:194 (15)
//         00482f9a     MOV        EDX,dword ptr [ESI + 0x4]
//         00482f9d     MOV        AL,byte ptr [ESP + temp_scale_flag]
//         00482fa1     ADD        ESP,0x38
//         00482fa4     INC        EBX
//         00482fa5     MOV        byte ptr [EDX + EDI*0x1 + 0x8],AL
//                              rmm_dbct.cpp:195 (20)
//         00482fa9     MOV        this,dword ptr [ESI + 0x4]
//         00482fac     MOV        DL,byte ptr [ESP + local_4]
//         00482fb0     MOV        byte ptr [ECX + EDI*0x1 + this+0x9],DL
//         00482fb4     MOV        EAX,dword ptr [ESI]
//         00482fb6     ADD        EDI,0x2c
//         00482fb9     CMP        EBX,EAX
//         00482fbb     JL         LAB_00482f5a
//                              rmm_dbct.cpp:198 (6)
//         00482fbd     MOV        EDI,dword ptr [ESP + land_num]
//         00482fc1     JMP        LAB_00482fc6
//                               LAB_00482fc3                                                 XREF[1]:     00482f42(j)
//                              rmm_dbct.cpp:199 (3)
//         00482fc3     MOV        dword ptr [ESI + 0x4],EBX
//                               LAB_00482fc6                                                 XREF[2]:     00482f56(j), 00482fc1(j)
//                              rmm_dbct.cpp:170 (21)
//         00482fc6     MOV        EAX,dword ptr [ESP + param_4]
//         00482fca     MOV        this,dword ptr [ESP + temp_terrain_type]
//         00482fce     INC        EAX
//         00482fcf     CMP        EAX,this
//         00482fd1     MOV        dword ptr [ESP + param_4],EAX
//         00482fd5     JL         LAB_00482f09
//                               LAB_00482fdb                                                 XREF[1]:     00482f03(j)
//                              rmm_dbct.cpp:201 (9)
//         00482fdb     PUSH       EBP
//         00482fdc     CALL       fclose                                           undefined fclose()
//         00482fe1     ADD        ESP,0x4
//                              rmm_dbct.cpp:242 (12)
//         00482fe4     MOV        EAX,EDI
//         00482fe6     POP        EDI
//         00482fe7     POP        ESI
//         00482fe8     POP        EBP
//         00482fe9     POP        EBX
//         00482fea     ADD        ESP,0x34
//         00482fed     RET        0x10
//                               LAB_00482ff0                                                 XREF[1]:     00482c4c(j)
//                              rmm_dbct.cpp:239 (3)
//         00482ff0     MOV        dword ptr [EBP],ESI
//                              rmm_dbct.cpp:240 (6)
//         00482ff3     MOV        dword ptr [EDI + 0x4f58],ESI
//                               LAB_00482ff9                                                 XREF[1]:     00482edc(j)
//                              rmm_dbct.cpp:242 (12)
//         00482ff9     MOV        EAX,EDI
//         00482ffb     POP        EDI
//         00482ffc     POP        ESI
//         00482ffd     POP        EBP
//         00482ffe     POP        EBX
//         00482fff     ADD        ESP,0x34
//         00483002     RET        0x10
//                               LAB_00483005                                                 XREF[1]:     00482cf0(j)
//                              rmm_dbct.cpp:129 (7)
//         00483005     MOV        dword ptr [ESI + 0x28],0x0
//                              rmm_dbct.cpp:128 (5)
//         0048300c     JMP        LAB_00482db3
//         00483011     ??         90h
//         00483012     NOP
//         00483013     NOP
//         00483014     NOP
//         00483015     NOP
//         00483016     NOP
//         00483017     NOP
//         00483018     NOP
//         00483019     NOP
//         0048301a     NOP
//         0048301b     NOP
//         0048301c     NOP
//         0048301d     NOP
//         0048301e     NOP
//         0048301f     NOP
}

RGE_RMM_Database_Controller::RGE_RMM_Database_Controller(int param_1) {
    /* TODO: Stub */
//                              undefined __thiscall RGE_RMM_Database_Controller(RGE_RMM_Database_Co
//              undefined         <UNASSIGNED>   <RETURN>
//              RGE_RMM_Databa    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[5]:     0048304c(R), 004830b9(W), 004830c3(R), 004831bd(R),
//                                                                                     004831c7(W)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     0048305a(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     004831db(R)
//              undefined4        Stack[-0x10]:4 local_10                  XREF[2]:     00483071(W), 004831b5(R)
//              undefined4        Stack[-0x14]:4 local_14                  XREF[2]:     004830d9(W), 0048317e(R)
//              RGE_Elevation_    Stack[-0x18]:4 elevation_info            XREF[2]:     00483043(W), 004831cb(R)
//              undefined4        Stack[-0x1c]:4 local_1c                  XREF[3]:     004830af(W), 004831b9(R), 004831d1(W)
//              long              Stack[-0x20]:4 index
//                               ??0RGE_RMM_Database_Controller@@QAE@H@Z                      XREF[2]:     data_load_random_map:004557fd(c),
//                               RGE_RMM_Database_Controller::RGE_RMM_Database_Controller                  TRIBE_RMM_Database_Controller:0048
//                              rmm_dbct.cpp:249 (44)
//         00483020     PUSH       -0x1
//         00483022     PUSH       FUN_0055e658
//         00483027     MOV        EAX,FS:[0x0]
//         0048302d     PUSH       EAX
//         0048302e     MOV        dword ptr FS:[0x0],ESP
//         00483035     SUB        ESP,0x10
//         00483038     PUSH       EBX
//         00483039     PUSH       EBP
//         0048303a     PUSH       ESI
//         0048303b     XOR        EBP,EBP
//         0048303d     PUSH       EDI
//         0048303e     PUSH       EBP
//         0048303f     MOV        EDI,this
//         00483041     PUSH       EBP
//         00483042     PUSH       EBP
//         00483043     MOV        dword ptr [ESP + elevation_info],EDI
//         00483047     CALL       RGE_Random_Map_Module::RGE_Random_Map_Module     undefined RGE_Random_Map_Module(RGE_Random_Ma
//                              rmm_dbct.cpp:262 (46)
//         0048304c     MOV        ESI,dword ptr [ESP + param_1]
//         00483050     LEA        EBX,[EDI + 0x4f54]
//         00483056     PUSH       0x8
//         00483058     PUSH       EBX
//         00483059     PUSH       ESI
//         0048305a     MOV        dword ptr [ESP + local_4],EBP
//         0048305e     MOV        dword ptr [EDI],RGE_RMM_Database_Controller::`   = 00483430
//         00483064     MOV        dword ptr [EDI + 0x30],EBP
//         00483067     MOV        dword ptr [EDI + 0x34],0xffffffff
//         0048306e     MOV        dword ptr [EDI + 0x38],EBP
//         00483071     MOV        dword ptr [ESP + local_10],EBX
//         00483075     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//                              rmm_dbct.cpp:263 (13)
//         0048307a     MOV        EAX,dword ptr [EBX]
//         0048307c     ADD        ESP,0xc
//         0048307f     CMP        EAX,EBP
//         00483081     JLE        LAB_004831db
//                              rmm_dbct.cpp:265 (8)
//         00483087     PUSH       0x48
//         00483089     PUSH       EAX
//         0048308a     CALL       calloc                                           undefined calloc()
//                              rmm_dbct.cpp:266 (25)
//         0048308f     MOV        this,dword ptr [EBX]
//         00483091     ADD        ESP,0x8
//         00483094     MOV        dword ptr [EDI + 0x4f58],EAX
//         0048309a     LEA        this,[ECX + ECX*0x8]
//         0048309d     SHL        this,0x3
//         004830a0     PUSH       this
//         004830a1     PUSH       EAX
//         004830a2     PUSH       ESI
//         004830a3     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//                              rmm_dbct.cpp:268 (17)
//         004830a8     MOV        EAX,dword ptr [EBX]
//         004830aa     ADD        ESP,0xc
//         004830ad     CMP        EAX,EBP
//         004830af     MOV        dword ptr [ESP + local_1c],EBP
//         004830b3     JLE        LAB_004831db
//                              rmm_dbct.cpp:304 (4)
//         004830b9     MOV        dword ptr [ESP + param_1],EBP
//                               LAB_004830bd                                                 XREF[1]:     004831d5(j)
//                              rmm_dbct.cpp:270 (12)
//         004830bd     MOV        EDX,dword ptr [EDI + 0x4f58]
//         004830c3     MOV        EAX,dword ptr [ESP + param_1]
//         004830c7     ADD        EAX,EDX
//                              rmm_dbct.cpp:275 (25)
//         004830c9     PUSH       0x2c
//         004830cb     LEA        EDI,[EAX + 0x4]
//         004830ce     LEA        EBX,[EAX + 0x30]
//         004830d1     LEA        EBP,[EAX + 0x38]
//         004830d4     ADD        EAX,0x40
//         004830d7     PUSH       EDI
//         004830d8     PUSH       ESI
//         004830d9     MOV        dword ptr [ESP + local_14],EAX
//         004830dd     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//                              rmm_dbct.cpp:276 (10)
//         004830e2     MOV        EAX,dword ptr [EDI + 0x24]
//         004830e5     ADD        ESP,0xc
//         004830e8     TEST       EAX,EAX
//         004830ea     JLE        LAB_00483111
//                              rmm_dbct.cpp:278 (11)
//         004830ec     PUSH       0x2c
//         004830ee     PUSH       EAX
//         004830ef     CALL       calloc                                           undefined calloc()
//         004830f4     MOV        dword ptr [EDI + 0x28],EAX
//                              rmm_dbct.cpp:279 (26)
//         004830f7     MOV        EDI,dword ptr [EDI + 0x24]
//         004830fa     ADD        ESP,0x8
//         004830fd     LEA        this,[EDI + EDI*0x4]
//         00483100     LEA        EDX,[EDI + this->_padding_*0x2]
//         00483103     SHL        EDX,0x2
//         00483106     PUSH       EDX
//         00483107     PUSH       EAX
//         00483108     PUSH       ESI
//         00483109     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         0048310e     ADD        ESP,0xc
//                               LAB_00483111                                                 XREF[1]:     004830ea(j)
//                              rmm_dbct.cpp:282 (9)
//         00483111     PUSH       0x8
//         00483113     PUSH       EBX
//         00483114     PUSH       ESI
//         00483115     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//                              rmm_dbct.cpp:283 (9)
//         0048311a     MOV        EAX,dword ptr [EBX]
//         0048311c     ADD        ESP,0xc
//         0048311f     TEST       EAX,EAX
//         00483121     JLE        LAB_00483144
//                              rmm_dbct.cpp:285 (11)
//         00483123     PUSH       0x18
//         00483125     PUSH       EAX
//         00483126     CALL       calloc                                           undefined calloc()
//         0048312b     MOV        dword ptr [EBX + 0x4],EAX
//                              rmm_dbct.cpp:286 (22)
//         0048312e     MOV        EBX,dword ptr [EBX]
//         00483130     ADD        ESP,0x8
//         00483133     LEA        this,[EBX + EBX*0x2]
//         00483136     SHL        this,0x3
//         00483139     PUSH       this
//         0048313a     PUSH       EAX
//         0048313b     PUSH       ESI
//         0048313c     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         00483141     ADD        ESP,0xc
//                               LAB_00483144                                                 XREF[1]:     00483121(j)
//                              rmm_dbct.cpp:289 (9)
//         00483144     PUSH       0x8
//         00483146     PUSH       EBP
//         00483147     PUSH       ESI
//         00483148     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//                              rmm_dbct.cpp:290 (10)
//         0048314d     MOV        EAX,dword ptr [EBP]
//         00483150     ADD        ESP,0xc
//         00483153     TEST       EAX,EAX
//         00483155     JLE        LAB_0048317e
//                              rmm_dbct.cpp:292 (11)
//         00483157     PUSH       0x2c
//         00483159     PUSH       EAX
//         0048315a     CALL       calloc                                           undefined calloc()
//         0048315f     MOV        dword ptr [EBP + 0x4],EAX
//                              rmm_dbct.cpp:293 (28)
//         00483162     MOV        EBP,dword ptr [EBP]
//         00483165     ADD        ESP,0x8
//         00483168     LEA        EDX,[EBP + EBP*0x4]
//         0048316c     LEA        this,[EBP + EDX*0x2]
//         00483170     SHL        this,0x2
//         00483173     PUSH       this
//         00483174     PUSH       EAX
//         00483175     PUSH       ESI
//         00483176     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         0048317b     ADD        ESP,0xc
//                               LAB_0048317e                                                 XREF[1]:     00483155(j)
//                              rmm_dbct.cpp:296 (13)
//         0048317e     MOV        EDI,dword ptr [ESP + local_14]
//         00483182     PUSH       0x8
//         00483184     PUSH       EDI
//         00483185     PUSH       ESI
//         00483186     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//                              rmm_dbct.cpp:297 (9)
//         0048318b     MOV        EAX,dword ptr [EDI]
//         0048318d     ADD        ESP,0xc
//         00483190     TEST       EAX,EAX
//         00483192     JLE        LAB_004831b5
//                              rmm_dbct.cpp:299 (11)
//         00483194     PUSH       0x18
//         00483196     PUSH       EAX
//         00483197     CALL       calloc                                           undefined calloc()
//         0048319c     MOV        dword ptr [EDI + 0x4],EAX
//                              rmm_dbct.cpp:300 (60)
//         0048319f     MOV        EDI,dword ptr [EDI]
//         004831a1     ADD        ESP,0x8
//         004831a4     LEA        EDX,[EDI + EDI*0x2]
//         004831a7     SHL        EDX,0x3
//         004831aa     PUSH       EDX
//         004831ab     PUSH       EAX
//         004831ac     PUSH       ESI
//         004831ad     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         004831b2     ADD        ESP,0xc
//                               LAB_004831b5                                                 XREF[1]:     00483192(j)
//         004831b5     MOV        this,dword ptr [ESP + local_10]
//         004831b9     MOV        EAX,dword ptr [ESP + local_1c]
//         004831bd     MOV        EDI,dword ptr [ESP + param_1]
//         004831c1     INC        EAX
//         004831c2     MOV        EDX,dword ptr [this->_padding_]
//         004831c4     ADD        EDI,0x48
//         004831c7     MOV        dword ptr [ESP + param_1],EDI
//         004831cb     MOV        EDI,dword ptr [ESP + elevation_info]
//         004831cf     CMP        EAX,EDX
//         004831d1     MOV        dword ptr [ESP + local_1c],EAX
//         004831d5     JL         LAB_004830bd
//                               LAB_004831db                                                 XREF[2]:     00483081(j), 004830b3(j)
//                              rmm_dbct.cpp:304 (23)
//         004831db     MOV        this,dword ptr [ESP + local_c]
//         004831df     MOV        EAX,EDI
//         004831e1     POP        EDI
//         004831e2     POP        ESI
//         004831e3     POP        EBP
//         004831e4     MOV        dword ptr FS:[0x0],this
//         004831eb     POP        EBX
//         004831ec     ADD        ESP,0x1c
//         004831ef     RET        0x4
//         004831f2     ??         90h
//         004831f3     NOP
//         004831f4     NOP
//         004831f5     NOP
//         004831f6     NOP
//         004831f7     NOP
//         004831f8     NOP
//         004831f9     NOP
//         004831fa     NOP
//         004831fb     NOP
//         004831fc     NOP
//         004831fd     NOP
//         004831fe     NOP
//         004831ff     NOP
}

RGE_RMM_Database_Controller::~RGE_RMM_Database_Controller() {
    /* TODO: Stub */
//                              void __thiscall ~RGE_RMM_Database_Controller(RGE_RMM_Database_Contro
//              void              <VOID>         <RETURN>
//              RGE_RMM_Databa    ECX:4 (auto)   this
//                               ??1RGE_RMM_Database_Controller@@QAE@XZ                       XREF[1]:     ~RGE_Map:0045546b(c)
//                               RGE_RMM_Database_Controller::~RGE_RMM_Database_Controller
//                              rmm_dbct.cpp:308 (3)
//         00483200     PUSH       ESI
//         00483201     MOV        ESI,this
//                              rmm_dbct.cpp:311 (35)
//         00483203     MOV        EAX,dword ptr [ESI + 0x4f54]
//         00483209     MOV        dword ptr [ESI],RGE_RMM_Database_Controller::`   = 00483430
//         0048320f     TEST       EAX,EAX
//         00483211     JLE        LAB_004832cc
//         00483217     MOV        this,dword ptr [ESI + 0x4f58]
//         0048321d     TEST       this,this
//         0048321f     JZ         LAB_004832cc
//         00483225     PUSH       EBX
//                              rmm_dbct.cpp:313 (11)
//         00483226     XOR        EBX,EBX
//         00483228     TEST       EAX,EAX
//         0048322a     JLE        LAB_004832b2
//         00483230     PUSH       EDI
//                              rmm_dbct.cpp:331 (128)
//         00483231     XOR        EDI,EDI
//                               LAB_00483233                                                 XREF[1]:     004832af(j)
//         00483233     MOV        EAX,dword ptr [ESI + 0x4f58]
//         00483239     ADD        EAX,EDI
//         0048323b     MOV        this,dword ptr [EAX + 0x28]
//         0048323e     TEST       this,this
//         00483240     JLE        LAB_0048324e
//         00483242     MOV        this,dword ptr [EAX + 0x2c]
//         00483245     PUSH       this
//         00483246     CALL       free                                             undefined free()
//         0048324b     ADD        ESP,0x4
//                               LAB_0048324e                                                 XREF[1]:     00483240(j)
//         0048324e     MOV        EDX,dword ptr [ESI + 0x4f58]
//         00483254     MOV        this,dword ptr [EDX + EDI*0x1 + 0x30]
//         00483258     LEA        EAX,[EDX + EDI*0x1]
//         0048325b     TEST       this,this
//         0048325d     JLE        LAB_0048326b
//         0048325f     MOV        EAX,dword ptr [EAX + 0x34]
//         00483262     PUSH       EAX
//         00483263     CALL       free                                             undefined free()
//         00483268     ADD        ESP,0x4
//                               LAB_0048326b                                                 XREF[1]:     0048325d(j)
//         0048326b     MOV        this,dword ptr [ESI + 0x4f58]
//         00483271     LEA        EAX,[this->_padding_ + EDI*0x1]
//         00483274     MOV        this,dword ptr [ECX + EDI*0x1 + this->number_o
//         00483278     TEST       this,this
//         0048327a     JLE        LAB_00483288
//         0048327c     MOV        EDX,dword ptr [EAX + 0x3c]
//         0048327f     PUSH       EDX
//         00483280     CALL       free                                             undefined free()
//         00483285     ADD        ESP,0x4
//                               LAB_00483288                                                 XREF[1]:     0048327a(j)
//         00483288     MOV        EAX,dword ptr [ESI + 0x4f58]
//         0048328e     ADD        EAX,EDI
//         00483290     MOV        this,dword ptr [EAX + 0x40]
//         00483293     TEST       this,this
//         00483295     JLE        LAB_004832a3
//         00483297     MOV        this,dword ptr [EAX + 0x44]
//         0048329a     PUSH       this
//         0048329b     CALL       free                                             undefined free()
//         004832a0     ADD        ESP,0x4
//                               LAB_004832a3                                                 XREF[1]:     00483295(j)
//         004832a3     MOV        EAX,dword ptr [ESI + 0x4f54]
//         004832a9     INC        EBX
//         004832aa     ADD        EDI,0x48
//         004832ad     CMP        EBX,EAX
//         004832af     JL         LAB_00483233
//                              rmm_dbct.cpp:308 (1)
//         004832b1     POP        EDI
//                               LAB_004832b2                                                 XREF[1]:     0048322a(j)
//                              rmm_dbct.cpp:328 (15)
//         004832b2     MOV        EDX,dword ptr [ESI + 0x4f58]
//         004832b8     PUSH       EDX
//         004832b9     CALL       free                                             undefined free()
//         004832be     ADD        ESP,0x4
//                              rmm_dbct.cpp:329 (18)
//         004832c1     MOV        dword ptr [ESI + 0x4f54],0x0
//         004832cb     POP        EBX
//                               LAB_004832cc                                                 XREF[2]:     00483211(j), 0048321f(j)
//         004832cc     MOV        this,ESI
//         004832ce     CALL       RGE_Random_Map_Module::~RGE_Random_Map_Module    void ~RGE_Random_Map_Module(RGE_Random_Map_Mo
//                              rmm_dbct.cpp:331 (2)
//         004832d3     POP        ESI
//         004832d4     RET
//         004832d5     ??         90h
//         004832d6     NOP
//         004832d7     NOP
//         004832d8     NOP
//         004832d9     NOP
//         004832da     NOP
//         004832db     NOP
//         004832dc     NOP
//         004832dd     NOP
//         004832de     NOP
//         004832df     NOP
}

uchar RGE_RMM_Database_Controller::save(int param_1) {
    /* TODO: Stub */
//                              uchar __thiscall save(RGE_RMM_Database_Controller * this, int param_1)
//              uchar             AL:1           <RETURN>
//              RGE_RMM_Databa    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[5]:     004832e6(R), 00483338(W), 00483348(R), 0048340a(R),
//                                                                                     0048341a(W)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     004832fb(W), 00483402(R)
//              undefined4        Stack[-0x8]:4  local_8                   XREF[2]:     0048335e(W), 004833d8(R)
//              RGE_Elevation_    Stack[-0xc]:4  elevation_info            XREF[2]:     004832ef(W), 0048333e(R)
//              undefined4        Stack[-0x10]:4 local_10                  XREF[3]:     0048332e(W), 00483406(R), 00483416(W)
//              long              Stack[-0x14]:4 index
//                               ?save@RGE_RMM_Database_Controller@@QAEEH@Z                   XREF[1]:     save:00457e8f(c)
//                               RGE_RMM_Database_Controller::save
//                              rmm_dbct.cpp:335 (6)
//         004832e0     SUB        ESP,0x10
//         004832e3     PUSH       EBX
//         004832e4     PUSH       EBP
//         004832e5     PUSH       ESI
//                              rmm_dbct.cpp:343 (30)
//         004832e6     MOV        ESI,dword ptr [ESP + param_1]
//         004832ea     PUSH       EDI
//         004832eb     MOV        EDI,this
//         004832ed     PUSH       0x8
//         004832ef     MOV        dword ptr [ESP + elevation_info],EDI
//         004832f3     LEA        EBX,[EDI + 0x4f54]
//         004832f9     PUSH       EBX
//         004832fa     PUSH       ESI
//         004832fb     MOV        dword ptr [ESP + local_4],EBX
//         004832ff     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//                              rmm_dbct.cpp:344 (15)
//         00483304     MOV        EAX,dword ptr [EBX]
//         00483306     XOR        EBP,EBP
//         00483308     ADD        ESP,0xc
//         0048330b     CMP        EAX,EBP
//         0048330d     JLE        LAB_00483424
//                              rmm_dbct.cpp:346 (20)
//         00483313     MOV        this,dword ptr [EDI + 0x4f58]
//         00483319     LEA        EAX,[EAX + EAX*0x8]
//         0048331c     SHL        EAX,0x3
//         0048331f     PUSH       EAX
//         00483320     PUSH       this
//         00483321     PUSH       ESI
//         00483322     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//                              rmm_dbct.cpp:348 (17)
//         00483327     MOV        EAX,dword ptr [EBX]
//         00483329     ADD        ESP,0xc
//         0048332c     CMP        EAX,EBP
//         0048332e     MOV        dword ptr [ESP + local_10],EBP
//         00483332     JLE        LAB_00483424
//                              rmm_dbct.cpp:374 (10)
//         00483338     MOV        dword ptr [ESP + param_1],EBP
//         0048333c     JMP        LAB_00483342
//                               LAB_0048333e                                                 XREF[1]:     0048341e(j)
//         0048333e     MOV        EDI,dword ptr [ESP + elevation_info]
//                               LAB_00483342                                                 XREF[1]:     0048333c(j)
//                              rmm_dbct.cpp:350 (12)
//         00483342     MOV        EDX,dword ptr [EDI + 0x4f58]
//         00483348     MOV        EAX,dword ptr [ESP + param_1]
//         0048334c     ADD        EAX,EDX
//                              rmm_dbct.cpp:355 (25)
//         0048334e     PUSH       0x2c
//         00483350     LEA        EDI,[EAX + 0x4]
//         00483353     LEA        EBX,[EAX + 0x30]
//         00483356     LEA        EBP,[EAX + 0x38]
//         00483359     ADD        EAX,0x40
//         0048335c     PUSH       EDI
//         0048335d     PUSH       ESI
//         0048335e     MOV        dword ptr [ESP + local_8],EAX
//         00483362     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//                              rmm_dbct.cpp:356 (10)
//         00483367     MOV        EAX,dword ptr [EDI + 0x24]
//         0048336a     ADD        ESP,0xc
//         0048336d     TEST       EAX,EAX
//         0048336f     JLE        LAB_00483388
//                              rmm_dbct.cpp:357 (23)
//         00483371     LEA        this,[EAX + EAX*0x4]
//         00483374     LEA        EDX,[EAX + this->_padding_*0x2]
//         00483377     MOV        EAX,dword ptr [EDI + 0x28]
//         0048337a     SHL        EDX,0x2
//         0048337d     PUSH       EDX
//         0048337e     PUSH       EAX
//         0048337f     PUSH       ESI
//         00483380     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         00483385     ADD        ESP,0xc
//                               LAB_00483388                                                 XREF[1]:     0048336f(j)
//                              rmm_dbct.cpp:359 (9)
//         00483388     PUSH       0x8
//         0048338a     PUSH       EBX
//         0048338b     PUSH       ESI
//         0048338c     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//                              rmm_dbct.cpp:360 (9)
//         00483391     MOV        EAX,dword ptr [EBX]
//         00483393     ADD        ESP,0xc
//         00483396     TEST       EAX,EAX
//         00483398     JLE        LAB_004833ae
//                              rmm_dbct.cpp:361 (20)
//         0048339a     MOV        EDX,dword ptr [EBX + 0x4]
//         0048339d     LEA        this,[EAX + EAX*0x2]
//         004833a0     SHL        this,0x3
//         004833a3     PUSH       this
//         004833a4     PUSH       EDX
//         004833a5     PUSH       ESI
//         004833a6     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         004833ab     ADD        ESP,0xc
//                               LAB_004833ae                                                 XREF[1]:     00483398(j)
//                              rmm_dbct.cpp:363 (9)
//         004833ae     PUSH       0x8
//         004833b0     PUSH       EBP
//         004833b1     PUSH       ESI
//         004833b2     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//                              rmm_dbct.cpp:364 (10)
//         004833b7     MOV        EAX,dword ptr [EBP]
//         004833ba     ADD        ESP,0xc
//         004833bd     TEST       EAX,EAX
//         004833bf     JLE        LAB_004833d8
//                              rmm_dbct.cpp:365 (23)
//         004833c1     LEA        this,[EAX + EAX*0x4]
//         004833c4     LEA        EDX,[EAX + this->_padding_*0x2]
//         004833c7     MOV        EAX,dword ptr [EBP + 0x4]
//         004833ca     SHL        EDX,0x2
//         004833cd     PUSH       EDX
//         004833ce     PUSH       EAX
//         004833cf     PUSH       ESI
//         004833d0     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         004833d5     ADD        ESP,0xc
//                               LAB_004833d8                                                 XREF[1]:     004833bf(j)
//                              rmm_dbct.cpp:367 (13)
//         004833d8     MOV        EDI,dword ptr [ESP + local_8]
//         004833dc     PUSH       0x8
//         004833de     PUSH       EDI
//         004833df     PUSH       ESI
//         004833e0     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//                              rmm_dbct.cpp:368 (9)
//         004833e5     MOV        EAX,dword ptr [EDI]
//         004833e7     ADD        ESP,0xc
//         004833ea     TEST       EAX,EAX
//         004833ec     JLE        LAB_00483402
//                              rmm_dbct.cpp:369 (54)
//         004833ee     MOV        EDX,dword ptr [EDI + 0x4]
//         004833f1     LEA        this,[EAX + EAX*0x2]
//         004833f4     SHL        this,0x3
//         004833f7     PUSH       this
//         004833f8     PUSH       EDX
//         004833f9     PUSH       ESI
//         004833fa     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         004833ff     ADD        ESP,0xc
//                               LAB_00483402                                                 XREF[1]:     004833ec(j)
//         00483402     MOV        this,dword ptr [ESP + local_4]
//         00483406     MOV        EAX,dword ptr [ESP + local_10]
//         0048340a     MOV        EDI,dword ptr [ESP + param_1]
//         0048340e     INC        EAX
//         0048340f     MOV        EDX,dword ptr [this->_padding_]
//         00483411     ADD        EDI,0x48
//         00483414     CMP        EAX,EDX
//         00483416     MOV        dword ptr [ESP + local_10],EAX
//         0048341a     MOV        dword ptr [ESP + param_1],EDI
//         0048341e     JL         LAB_0048333e
//                               LAB_00483424                                                 XREF[2]:     0048330d(j), 00483332(j)
//                              rmm_dbct.cpp:374 (12)
//         00483424     POP        EDI
//         00483425     POP        ESI
//         00483426     POP        EBP
//         00483427     MOV        AL,0x1
//         00483429     POP        EBX
//         0048342a     ADD        ESP,0x10
//         0048342d     RET        0x4
    return 0;
}

uchar RGE_RMM_Database_Controller::generate() {
    /* TODO: Stub */
//                              uchar __thiscall generate(RGE_RMM_Database_Controller * this)
//              uchar             AL:1           <RETURN>
//              RGE_RMM_Databa    ECX:4 (auto)   this
//              undefined4        Stack[-0x4]:4  local_4                   XREF[8]:     0048345d(W), 00483482(W), 00483494(W), 004834b3(W),
//                                                                                     004834c5(W), 004834ed(W), 004834ff(W), 0048351e(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     00483527(R)
//              undefined4        Stack[-0x10]:4 local_10                  XREF[4]:     00483457(W), 0048348e(W), 004834bf(W), 004834f9(W)
//                               ?generate@RGE_RMM_Database_Controller@@UAEEXZ                XREF[2]:     generate:00488875(c), 00571e88(*)
//                               RGE_RMM_Database_Controller::generate
//                              rmm_dbct.cpp:378 (26)
//         00483430     PUSH       -0x1
//         00483432     PUSH       FUN_0055e69c
//         00483437     MOV        EAX,FS:[0x0]
//         0048343d     PUSH       EAX
//         0048343e     MOV        dword ptr FS:[0x0],ESP
//         00483445     PUSH       this
//         00483446     PUSH       ESI
//         00483447     PUSH       EDI
//         00483448     MOV        ESI,this
//                              rmm_dbct.cpp:381 (51)
//         0048344a     PUSH       0x12cc
//         0048344f     CALL       operator_new                                     void * operator_new(uint param_1)
//         00483454     ADD        ESP,0x4
//         00483457     MOV        dword ptr [ESP + local_10],EAX
//         0048345b     TEST       EAX,EAX
//         0048345d     MOV        dword ptr [ESP + local_4],0x0
//         00483465     JZ         LAB_0048347a
//         00483467     MOV        EDX,dword ptr [ESI + 0xc]
//         0048346a     LEA        this,[ESI + 0x1474]
//         00483470     PUSH       this
//         00483471     PUSH       ESI
//         00483472     PUSH       EDX
//         00483473     MOV        this,EAX
//         00483475     CALL       RGE_RMM_Terrain_Generator::RGE_RMM_Terrain_Gen   undefined RGE_RMM_Terrain_Generator(RGE_RMM_T
//                               LAB_0048347a                                                 XREF[1]:     00483465(j)
//         0048347a     OR         EDI,0xffffffff
//                              language.dll match for 0x1468: "Stone path 5"
//                              rmm_dbct.cpp:382 (49)
//         0048347d     PUSH       0x1468
//         00483482     MOV        dword ptr [ESP + local_4],EDI
//         00483486     CALL       operator_new                                     void * operator_new(uint param_1)
//         0048348b     ADD        ESP,0x4
//         0048348e     MOV        dword ptr [ESP + local_10],EAX
//         00483492     TEST       EAX,EAX
//         00483494     MOV        dword ptr [ESP + local_4],0x1
//         0048349c     JZ         LAB_004834ae
//         0048349e     MOV        EDX,dword ptr [ESI + 0xc]
//         004834a1     LEA        this,[ESI + 0x3c]
//         004834a4     PUSH       this
//         004834a5     PUSH       ESI
//         004834a6     PUSH       EDX
//         004834a7     MOV        this,EAX
//         004834a9     CALL       RGE_RMM_Land_Generator::RGE_RMM_Land_Generator   undefined RGE_RMM_Land_Generator(RGE_RMM_Land
//                               LAB_004834ae                                                 XREF[1]:     0048349c(j)
//                              rmm_dbct.cpp:383 (58)
//         004834ae     PUSH       0x1920
//         004834b3     MOV        dword ptr [ESP + local_4],EDI
//         004834b7     CALL       operator_new                                     void * operator_new(uint param_1)
//         004834bc     ADD        ESP,0x4
//         004834bf     MOV        dword ptr [ESP + local_10],EAX
//         004834c3     TEST       EAX,EAX
//         004834c5     MOV        dword ptr [ESP + local_4],0x2
//         004834cd     JZ         LAB_004834e8
//         004834cf     MOV        EDX,dword ptr [ESI + 0x30]
//         004834d2     LEA        this,[ESI + 0x270c]
//         004834d8     PUSH       0x1
//         004834da     PUSH       this
//         004834db     MOV        this,dword ptr [ESI + 0xc]
//         004834de     PUSH       EDX
//         004834df     PUSH       ESI
//         004834e0     PUSH       this
//         004834e1     MOV        this,EAX
//         004834e3     CALL       RGE_RMM_Object_Generator::RGE_RMM_Object_Gener   undefined RGE_RMM_Object_Generator(RGE_RMM_Ob
//                               LAB_004834e8                                                 XREF[1]:     004834cd(j)
//                              rmm_dbct.cpp:384 (52)
//         004834e8     PUSH       0xfb0
//         004834ed     MOV        dword ptr [ESP + local_4],EDI
//         004834f1     CALL       operator_new                                     void * operator_new(uint param_1)
//         004834f6     ADD        ESP,0x4
//         004834f9     MOV        dword ptr [ESP + local_10],EAX
//         004834fd     TEST       EAX,EAX
//         004834ff     MOV        dword ptr [ESP + local_4],0x3
//         00483507     JZ         LAB_0048351c
//         00483509     MOV        this,dword ptr [ESI + 0xc]
//         0048350c     LEA        EDX,[ESI + 0x3fd4]
//         00483512     PUSH       EDX
//         00483513     PUSH       ESI
//         00483514     PUSH       this
//         00483515     MOV        this,EAX
//         00483517     CALL       RGE_RMM_Elevation_Generator::RGE_RMM_Elevation   undefined RGE_RMM_Elevation_Generator(RGE_RMM
//                               LAB_0048351c                                                 XREF[1]:     00483507(j)
//                              rmm_dbct.cpp:388 (11)
//         0048351c     MOV        this,ESI
//         0048351e     MOV        dword ptr [ESP + local_4],EDI
//         00483522     CALL       RGE_Random_Map_Module::generate                  uchar generate(RGE_Random_Map_Module * this)
//                              rmm_dbct.cpp:389 (17)
//         00483527     MOV        this,dword ptr [ESP + local_c]
//         0048352b     POP        EDI
//         0048352c     MOV        dword ptr FS:[0x0],this
//         00483533     POP        ESI
//         00483534     ADD        ESP,0x10
//         00483537     RET
//         00483538     ??         90h
//         00483539     NOP
//         0048353a     NOP
//         0048353b     NOP
//         0048353c     NOP
//         0048353d     NOP
//         0048353e     NOP
//         0048353f     NOP
    return 0;
}

uchar RGE_RMM_Database_Controller::init(RGE_Map* param_1, RGE_Game_World* param_2, uchar param_3, long param_4, uchar param_5) {
    /* TODO: Stub */
//                              uchar __thiscall init(RGE_RMM_Database_Controller * this, RGE_Map *
//              uchar             AL:1           <RETURN>
//              RGE_RMM_Databa    ECX:4 (auto)   this
//              RGE_Map *         Stack[0x4]:4   param_1                   XREF[1]:     00483553(R)
//              RGE_Game_World    Stack[0x8]:4   param_2                   XREF[1]:     00483540(R)
//              uchar             Stack[0xc]:1   param_3                   XREF[1]:     0048354b(R)
//              long              Stack[0x10]:4  param_4                   XREF[1]:     00483544(R)
//              uchar             Stack[0x14]:1  param_5                   XREF[1]:     00483572(R)
//                               ?init@RGE_RMM_Database_Controller@@UAEEPAVRGE_Map@@PAVRGE_G  XREF[2]:     init:00487771(c), 00571e9c(*)
//                               RGE_RMM_Database_Controller::init
//                              rmm_dbct.cpp:393 (4)
//         00483540     MOV        EAX,dword ptr [ESP + param_2]
//                              rmm_dbct.cpp:396 (15)
//         00483544     MOV        EDX,dword ptr [ESP + param_4]
//         00483548     PUSH       ESI
//         00483549     MOV        ESI,this
//         0048354b     MOV        this,dword ptr [ESP + param_3]
//         0048354f     PUSH       EDI
//         00483550     MOV        dword ptr [ESI + 0x30],EAX
//                              rmm_dbct.cpp:399 (24)
//         00483553     MOV        EAX,dword ptr [ESP + param_1]
//         00483557     AND        this,0xff
//         0048355d     PUSH       EAX
//         0048355e     MOV        dword ptr [ESI + 0x34],this
//         00483561     MOV        this,ESI
//         00483563     MOV        dword ptr [ESI + 0x38],EDX
//         00483566     CALL       RGE_Random_Map_Module::update_map_info           void update_map_info(RGE_Random_Map_Module *
//                              rmm_dbct.cpp:400 (7)
//         0048356b     MOV        this,ESI
//         0048356d     CALL       RGE_Random_Map_Module::create_shared_resources   void create_shared_resources(RGE_Random_Map_M
//                              rmm_dbct.cpp:403 (12)
//         00483572     MOV        this,dword ptr [ESP + param_5]
//         00483576     MOV        EDI,dword ptr [ESI]
//         00483578     PUSH       this
//         00483579     MOV        this,ESI
//         0048357b     CALL       dword ptr [EDI + 0x4]
//                              rmm_dbct.cpp:404 (5)
//         0048357e     MOV        this,ESI
//         00483580     CALL       dword ptr [EDI + 0x8]
//                              rmm_dbct.cpp:405 (5)
//         00483583     MOV        this,ESI
//         00483585     CALL       dword ptr [EDI + 0xc]
//                              rmm_dbct.cpp:406 (5)
//         00483588     MOV        this,ESI
//         0048358a     CALL       dword ptr [EDI + 0x10]
//                              rmm_dbct.cpp:409 (7)
//         0048358d     POP        EDI
//         0048358e     MOV        AL,0x1
//         00483590     POP        ESI
//         00483591     RET        0x14
//         00483594     ??         90h
//         00483595     NOP
//         00483596     NOP
//         00483597     NOP
//         00483598     NOP
//         00483599     NOP
//         0048359a     NOP
//         0048359b     NOP
//         0048359c     NOP
//         0048359d     NOP
//         0048359e     NOP
//         0048359f     NOP
    return 0;
}

uchar RGE_RMM_Database_Controller::de_init() {
    /* TODO: Stub */
//                              uchar __thiscall de_init(RGE_RMM_Database_Controller * this)
//              uchar             AL:1           <RETURN>
//              RGE_RMM_Databa    ECX:4 (auto)   this
//                               ?de_init@RGE_RMM_Database_Controller@@UAEEXZ                 XREF[2]:     de_init:00487930(c), 00571ea0(*)
//                               RGE_RMM_Database_Controller::de_init
//                              rmm_dbct.cpp:414 (3)
//         004835a0     PUSH       EDI
//         004835a1     MOV        EDI,this
//                              rmm_dbct.cpp:420 (28)
//         004835a3     MOV        EAX,dword ptr [EDI + 0x8]
//         004835a6     MOV        dword ptr [EDI + 0x30],0x0
//         004835ad     TEST       EAX,EAX
//         004835af     MOV        dword ptr [EDI + 0x34],0xffffffff
//         004835b6     MOV        dword ptr [EDI + 0x38],0x0
//         004835bd     JZ         LAB_004835de
//                              rmm_dbct.cpp:414 (1)
//         004835bf     PUSH       ESI
//                               LAB_004835c0                                                 XREF[1]:     004835db(j)
//                              rmm_dbct.cpp:421 (29)
//         004835c0     MOV        ESI,dword ptr [EAX]
//         004835c2     TEST       ESI,ESI
//         004835c4     JZ         LAB_004835d6
//         004835c6     MOV        this,ESI
//         004835c8     CALL       RGE_Random_Map_Module::~RGE_Random_Map_Module    void ~RGE_Random_Map_Module(RGE_Random_Map_Mo
//         004835cd     PUSH       ESI
//         004835ce     CALL       operator_delete                                  void operator_delete(void * param_1)
//         004835d3     ADD        ESP,0x4
//                               LAB_004835d6                                                 XREF[1]:     004835c4(j)
//         004835d6     MOV        EAX,dword ptr [EDI + 0x8]
//         004835d9     TEST       EAX,EAX
//         004835db     JNZ        LAB_004835c0
//                              rmm_dbct.cpp:414 (1)
//         004835dd     POP        ESI
//                               LAB_004835de                                                 XREF[1]:     004835bd(j)
//                              rmm_dbct.cpp:424 (7)
//         004835de     MOV        this,EDI
//         004835e0     CALL       RGE_Random_Map_Module::destroy_shared_resources  void destroy_shared_resources(RGE_Random_Map_
//                              rmm_dbct.cpp:427 (9)
//         004835e5     PUSH       0x0
//         004835e7     MOV        this,EDI
//         004835e9     CALL       RGE_Random_Map_Module::update_map_info           void update_map_info(RGE_Random_Map_Module *
//                              rmm_dbct.cpp:429 (2)
//         004835ee     XOR        AL,AL
//                              rmm_dbct.cpp:430 (2)
//         004835f0     POP        EDI
//         004835f1     RET
//         004835f2     ??         90h
//         004835f3     NOP
//         004835f4     NOP
//         004835f5     NOP
//         004835f6     NOP
//         004835f7     NOP
//         004835f8     NOP
//         004835f9     NOP
//         004835fa     NOP
//         004835fb     NOP
//         004835fc     NOP
//         004835fd     NOP
//         004835fe     NOP
//         004835ff     NOP
    return 0;
}

void RGE_RMM_Database_Controller::calc_land_start(long param_1, long param_2, long param_3, RGE_Land_Data_Entry* param_4) {
    /* TODO: Stub */
//                              void __thiscall calc_land_start(RGE_RMM_Database_Controller * this,
//              void              <VOID>         <RETURN>
//              RGE_RMM_Databa    ECX:4 (auto)   this
//              long              Stack[0x4]:4   param_1                   XREF[4]:     0048375a(R), 00483815(R), 0048391e(R), 00483967(R)
//              long              Stack[0x8]:4   param_2                   XREF[13]:    0048362c(R), 00483644(W), 00483648(R), 00483679(W),
//                                                                                     00483681(R), 004836a8(W), 004836ac(R), 00483769(W),
//                                                                                     00483819(R), 00483877(R), 00483889(R), 004838d1(R),
//                                                                                     004838fa(W)
//              long              Stack[0xc]:4   param_3                   XREF[11]:    00483635(R), 0048364c(R), 0048375e(R), 00483793(W),
//                                                                                     004838b7(W), 004838bc(R), 00483922(R), 0048396b(R),
//                                                                                     00483981(W), 004839f2(R), 004839fc(W)
//              RGE_Land_Data_    Stack[0x10]:4  param_4                   XREF[6]:     0048372a(R), 00483842(W), 0048384a(W), 00483857(R),
//                                                                                     00483860(W), 00483864(R)
//              undefined8        Stack[-0x8]:8  local_8                   XREF[5]:     00483685(W), 00483691(R), 004836c3(R), 0048376d(W),
//                                                                                     004838ed(R)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[2]:     0048367d(W), 00483868(R)
//              float             Stack[-0x10]:4 bound_square
//              undefined4        Stack[-0x18]:4 local_18                  XREF[3]:     00483829(W), 00483873(R), 00483881(W)
//              undefined4        Stack[-0x1c]:4 local_1c                  XREF[3]:     00483832(W), 0048383a(W), 0048384e(R)
//              long              Stack[-0x20]:4 dx                        XREF[3]:     004836e5(W), 00483726(W), 0048380b(R)
//              long              Stack[-0x24]:4 mid_y2                    XREF[4]:     00483785(W), 004838c8(R), 004838e9(R), 004838fe(W)
//              undefined4        Stack[-0x28]:4 local_28                  XREF[4]:     004836c7(W), 004836f6(R), 004836ff(W), 00483805(R)
//              long              Stack[-0x2c]:4 mid_y1                    XREF[4]:     004836d8(W), 00483703(R), 00483713(W), 004837ff(R)
//              long              Stack[-0x30]:4 mid_x2                    XREF[4]:     0048369c(W), 004836e1(R), 004836f2(W), 004837f3(R)
//              long              Stack[-0x34]:4 mid_x1
//                               ?calc_land_start@RGE_RMM_Database_Controller@@IAEXJJJPAURGE  XREF[2]:     add_land_module:00483b13(c),
//                               RGE_RMM_Database_Controller::calc_land_start                              add_land_module:00483c36(c)
//                              rmm_dbct.cpp:435 (7)
//         00483600     SUB        ESP,0x30
//         00483603     PUSH       EBX
//         00483604     PUSH       EBP
//         00483605     PUSH       ESI
//         00483606     PUSH       EDI
//                              rmm_dbct.cpp:451 (37)
//         00483607     PUSH       0x1c3
//         0048360c     MOV        EDI,this
//         0048360e     PUSH       s_C:\msdev\work\age1_x1\rmm_dbct.c               = "C:\\msdev\\work\\age1_x1\\rmm_dbct.cpp"
//         00483613     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
//         00483618     ADD        ESP,0x8
//         0048361b     PUSH       EAX
//         0048361c     MOV        EAX,[L]                                          = 00000000
//         00483621     PUSH       s_********Random_Map_calc_land_sta               = "********Random Map calc land start, rand:
//         00483626     PUSH       EAX
//         00483627     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
//                              rmm_dbct.cpp:453 (4)
//         0048362c     MOV        EBX,dword ptr [ESP + param_2]
//                              rmm_dbct.cpp:454 (5)
//         00483630     MOV        ESI,dword ptr [EDI + 0x14]
//         00483633     MOV        this,ESI
//                              rmm_dbct.cpp:455 (38)
//         00483635     MOV        EAX,dword ptr [ESP + param_3]
//         00483639     LEA        EBP,[EBX + EBX*0x1]
//         0048363c     ADD        ESP,0xc
//         0048363f     SUB        this,EBP
//         00483641     CMP        EAX,0x3
//         00483644     MOV        dword ptr [ESP + param_2],this
//         00483648     FILD       dword ptr [ESP + param_2]
//         0048364c     FILD       dword ptr [ESP + param_3]
//         00483650     FSQRT
//         00483652     FDIVP
//         00483654     JLE        LAB_00483663
//         00483656     CMP        EAX,0x7
//         00483659     JGE        LAB_00483668
//                              rmm_dbct.cpp:456 (6)
//         0048365b     FMUL       float ptr [DAT_00571ea8]                         = 66h    f
//                              rmm_dbct.cpp:457 (7)
//         00483661     JMP        LAB_0048366e
//                               LAB_00483663                                                 XREF[1]:     00483654(j)
//         00483663     CMP        EAX,0x7
//         00483666     JL         LAB_0048366e
//                               LAB_00483668                                                 XREF[1]:     00483659(j)
//                              rmm_dbct.cpp:458 (6)
//         00483668     FMUL       float ptr [DAT_00571eac]                         = CDh
//                               LAB_0048366e                                                 XREF[2]:     00483661(j), 00483666(j)
//                              rmm_dbct.cpp:462 (50)
//         0048366e     MOV        EAX,ESI
//         00483670     FLD        ST0
//         00483672     CDQ
//         00483673     FMUL       ST1
//         00483675     SUB        EAX,EDX
//         00483677     SAR        EAX,0x1
//         00483679     MOV        dword ptr [ESP + param_2],EAX
//         0048367d     FSTP       float ptr [ESP + local_c]
//         00483681     FILD       dword ptr [ESP + param_2]
//         00483685     FSTP       double ptr [ESP + local_8]
//         00483689     FLD        ST0
//         0048368b     FMUL       double ptr [DAT_00571eb0]                        = CDh
//         00483691     FLD        double ptr [ESP + local_8]
//         00483695     FSUB       ST0,ST1
//         00483697     CALL       __ftol                                           undefined __ftol()
//         0048369c     MOV        dword ptr [ESP + mid_x2],EAX
//                              rmm_dbct.cpp:463 (29)
//         004836a0     MOV        EAX,dword ptr [EDI + 0x18]
//         004836a3     CDQ
//         004836a4     SUB        EAX,EDX
//         004836a6     SAR        EAX,0x1
//         004836a8     MOV        dword ptr [ESP + param_2],EAX
//         004836ac     FILD       dword ptr [ESP + param_2]
//         004836b0     FST        double ptr [ESP + Stack[-0x14]]
//         004836b4     FSUB       ST0,ST1
//         004836b6     CALL       __ftol                                           undefined __ftol()
//         004836bb     FSTP       ST0
//                              rmm_dbct.cpp:464 (21)
//         004836bd     FMUL       double ptr [DAT_00571eb8]                        = CDh
//         004836c3     FLD        double ptr [ESP + local_8]
//         004836c7     MOV        dword ptr [ESP + local_28],EAX
//         004836cb     FSUB       ST0,ST1
//         004836cd     CALL       __ftol                                           undefined __ftol()
//                              rmm_dbct.cpp:465 (15)
//         004836d2     FLD        double ptr [ESP + Stack[-0x14]]
//         004836d6     FSUB       ST0,ST1
//         004836d8     MOV        dword ptr [ESP + mid_y1],EAX
//         004836dc     CALL       __ftol                                           undefined __ftol()
//                              rmm_dbct.cpp:467 (14)
//         004836e1     MOV        this,dword ptr [ESP + mid_x2]
//         004836e5     MOV        dword ptr [ESP + dx],EAX
//         004836e9     CMP        this,EBX
//         004836eb     FSTP       ST0
//         004836ed     JG         LAB_004836f6
//                              rmm_dbct.cpp:468 (7)
//         004836ef     LEA        EDX,[EBX + 0x1]
//         004836f2     MOV        dword ptr [ESP + mid_x2],EDX
//                               LAB_004836f6                                                 XREF[1]:     004836ed(j)
//                              rmm_dbct.cpp:470 (6)
//         004836f6     CMP        dword ptr [ESP + local_28],EBX
//         004836fa     JG         LAB_00483703
//                              rmm_dbct.cpp:471 (7)
//         004836fc     LEA        this,[EBX + 0x1]
//         004836ff     MOV        dword ptr [ESP + local_28],this
//                               LAB_00483703                                                 XREF[1]:     004836fa(j)
//                              rmm_dbct.cpp:473 (13)
//         00483703     MOV        this,dword ptr [ESP + mid_y1]
//         00483707     SUB        ESI,EBX
//         00483709     LEA        EDX,[ESI + -0x1]
//         0048370c     CMP        this,EDX
//         0048370e     JL         LAB_00483717
//                              rmm_dbct.cpp:474 (7)
//         00483710     ADD        ESI,-0x2
//         00483713     MOV        dword ptr [ESP + mid_y1],ESI
//                               LAB_00483717                                                 XREF[1]:     0048370e(j)
//                              rmm_dbct.cpp:476 (12)
//         00483717     MOV        this,dword ptr [EDI + 0x18]
//         0048371a     SUB        this,EBX
//         0048371c     LEA        EDX,[this->_padding_ + -0x1]
//         0048371f     CMP        EAX,EDX
//         00483721     JL         LAB_0048372a
//                              rmm_dbct.cpp:477 (7)
//         00483723     ADD        this,-0x2
//         00483726     MOV        dword ptr [ESP + dx],this
//                               LAB_0048372a                                                 XREF[1]:     00483721(j)
//                              rmm_dbct.cpp:479 (32)
//         0048372a     MOV        ESI,dword ptr [ESP + param_4]
//         0048372e     XOR        EAX,EAX
//         00483730     MOV        AL,byte ptr [ESI + 0x11]
//         00483733     SUB        EAX,0x0
//         00483736     JZ         LAB_00483956
//         0048373c     DEC        EAX
//         0048373d     JZ         LAB_0048390d
//         00483743     DEC        EAX
//         00483744     JNZ        LAB_00483a02
//                              rmm_dbct.cpp:501 (16)
//         0048374a     MOV        EAX,[L]                                          = 00000000
//         0048374f     PUSH       s_********Random_Map_calc_land_end               = "********Random Map calc land end (point3) "
//         00483754     PUSH       EAX
//         00483755     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
//                              rmm_dbct.cpp:502 (29)
//         0048375a     MOV        EAX,dword ptr [ESP + param_1]
//         0048375e     MOV        this,dword ptr [ESP + param_3]
//         00483762     ADD        this,EAX
//         00483764     ADD        ESP,0x8
//         00483767     CMP        EAX,this
//         00483769     MOV        dword ptr [ESP + param_2],EAX
//         0048376d     MOV        dword ptr [ESP + local_8],this
//         00483771     JGE        LAB_00483a02
//                              rmm_dbct.cpp:545 (158)
//         00483777     LEA        EDX,[EAX + EAX*0x2]
//         0048377a     LEA        EAX,[EAX + EDX*0x4]
//         0048377d     LEA        EAX,[EDI + EAX*0x4 + 0x48]
//         00483781     MOV        dword ptr [ESP + Stack[-0x14]],EAX
//         00483785     MOV        dword ptr [ESP + mid_y2],EAX
//                               LAB_00483789                                                 XREF[2]:     004838c2(j), 00483902(j)
//         00483789     PUSH       0x1fc
//         0048378e     PUSH       s_C:\msdev\work\age1_x1\rmm_dbct.c               = "C:\\msdev\\work\\age1_x1\\rmm_dbct.cpp"
//         00483793     MOV        byte ptr [ESP + param_3],0x0
//         00483798     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
//         0048379d     MOV        EDX,dword ptr [EDI + 0x14]
//         004837a0     LEA        EBP,[EBX + EBX*0x1]
//         004837a3     MOV        this,EAX
//         004837a5     SUB        EDX,EBP
//         004837a7     IMUL       this,EDX
//         004837aa     MOV        EAX,0x80010003
//         004837af     ADD        ESP,0x8
//         004837b2     IMUL       this
//         004837b4     ADD        EDX,this
//         004837b6     PUSH       0x1fd
//         004837bb     SAR        EDX,0xe
//         004837be     MOV        EAX,EDX
//         004837c0     PUSH       s_C:\msdev\work\age1_x1\rmm_dbct.c               = "C:\\msdev\\work\\age1_x1\\rmm_dbct.cpp"
//         004837c5     SHR        EAX,0x1f
//         004837c8     ADD        EDX,EAX
//         004837ca     ADD        EDX,EBX
//         004837cc     MOV        ESI,EDX
//         004837ce     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
//         004837d3     MOV        EDX,dword ptr [EDI + 0x18]
//         004837d6     MOV        this,EAX
//         004837d8     SUB        EDX,EBP
//         004837da     MOV        EAX,0x80010003
//         004837df     IMUL       this,EDX
//         004837e2     IMUL       this
//         004837e4     ADD        EDX,this
//         004837e6     ADD        ESP,0x8
//         004837e9     SAR        EDX,0xe
//         004837ec     MOV        EAX,EDX
//         004837ee     SHR        EAX,0x1f
//         004837f1     ADD        EDX,EAX
//         004837f3     MOV        EAX,dword ptr [ESP + mid_x2]
//         004837f7     ADD        EDX,EBX
//         004837f9     CMP        ESI,EAX
//         004837fb     MOV        EBP,EDX
//         004837fd     JLE        LAB_00483815
//         004837ff     CMP        ESI,dword ptr [ESP + mid_y1]
//         00483803     JGE        LAB_00483815
//         00483805     CMP        EBP,dword ptr [ESP + local_28]
//         00483809     JLE        LAB_00483815
//         0048380b     CMP        EBP,dword ptr [ESP + dx]
//         0048380f     JL         LAB_004838b7
//                               LAB_00483815                                                 XREF[3]:     004837fd(j), 00483803(j),
//                                                                                                         00483809(j)
//                              rmm_dbct.cpp:514 (33)
//         00483815     MOV        this,dword ptr [ESP + param_1]
//         00483819     MOV        EAX,dword ptr [ESP + param_2]
//         0048381d     CMP        this,EAX
//         0048381f     JGE        LAB_004838bc
//         00483825     MOV        EDX,dword ptr [ESP + Stack[-0x14]]
//         00483829     MOV        dword ptr [ESP + local_18],EDX
//                               LAB_0048382d                                                 XREF[1]:     00483885(j)
//         0048382d     MOV        EAX,ESI
//         0048382f     SUB        EAX,dword ptr [EDX + -0x4]
//         00483832     MOV        dword ptr [ESP + local_1c],EAX
//                              rmm_dbct.cpp:517 (2)
//         00483836     JNS        LAB_0048383e
//                              rmm_dbct.cpp:518 (14)
//         00483838     NEG        EAX
//         0048383a     MOV        dword ptr [ESP + local_1c],EAX
//                               LAB_0048383e                                                 XREF[1]:     00483836(j)
//         0048383e     MOV        EAX,EBP
//         00483840     SUB        EAX,dword ptr [EDX]
//         00483842     MOV        dword ptr [ESP + param_4],EAX
//                              rmm_dbct.cpp:521 (2)
//         00483846     JNS        LAB_0048384e
//                              rmm_dbct.cpp:522 (6)
//         00483848     NEG        EAX
//         0048384a     MOV        dword ptr [ESP + param_4],EAX
//                               LAB_0048384e                                                 XREF[1]:     00483846(j)
//                              rmm_dbct.cpp:524 (59)
//         0048384e     MOV        EAX,dword ptr [ESP + local_1c]
//         00483852     MOV        EDX,EAX
//         00483854     IMUL       EDX,EAX
//         00483857     MOV        EAX,dword ptr [ESP + param_4]
//         0048385b     IMUL       EAX,EAX
//         0048385e     ADD        EDX,EAX
//         00483860     MOV        dword ptr [ESP + param_4],EDX
//         00483864     FILD       dword ptr [ESP + param_4]
//         00483868     FCOMP      float ptr [ESP + local_c]
//         0048386c     FNSTSW     AX
//         0048386e     TEST       AH,0x41
//         00483871     JNZ        LAB_00483889
//         00483873     MOV        EDX,dword ptr [ESP + local_18]
//         00483877     MOV        EAX,dword ptr [ESP + param_2]
//         0048387b     INC        this
//         0048387c     ADD        EDX,0x34
//         0048387f     CMP        this,EAX
//         00483881     MOV        dword ptr [ESP + local_18],EDX
//         00483885     JL         LAB_0048382d
//         00483887     JMP        LAB_004838bc
//                               LAB_00483889                                                 XREF[1]:     00483871(j)
//                              rmm_dbct.cpp:526 (9)
//         00483889     MOV        EDX,dword ptr [ESP + param_2]
//         0048388d     DEC        EDX
//         0048388e     CMP        this,EDX
//         00483890     JNZ        LAB_004838b7
//                              rmm_dbct.cpp:528 (3)
//         00483892     LEA        EAX,[ECX + ECX*0x2]
//                              rmm_dbct.cpp:530 (34)
//         00483895     PUSH       EBP
//         00483896     PUSH       ESI
//         00483897     PUSH       this
//         00483898     LEA        EDX,[this->_padding_ + EAX*0x4]
//         0048389b     PUSH       s_********Random_Map_calc_land_xy_               = "********Random Map calc land xy player %d
//         004838a0     LEA        EAX,[EDI + EDX*0x4]
//         004838a3     MOV        dword ptr [EAX + 0x48],EBP
//         004838a6     MOV        dword ptr [EAX + 0x44],ESI
//         004838a9     MOV        EAX,[L]                                          = 00000000
//         004838ae     PUSH       EAX
//         004838af     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
//         004838b4     ADD        ESP,0x14
//                               LAB_004838b7                                                 XREF[2]:     0048380f(j), 00483890(j)
//                              rmm_dbct.cpp:532 (5)
//         004838b7     MOV        byte ptr [ESP + param_3],0x1
//                               LAB_004838bc                                                 XREF[2]:     0048381f(j), 00483887(j)
//                              rmm_dbct.cpp:505 (12)
//         004838bc     MOV        AL,byte ptr [ESP + param_3]
//         004838c0     TEST       AL,AL
//         004838c2     JNZ        LAB_00483789
//                              rmm_dbct.cpp:537 (4)
//         004838c8     MOV        EAX,dword ptr [ESP + mid_y2]
//                              rmm_dbct.cpp:539 (60)
//         004838cc     PUSH       EBP
//         004838cd     PUSH       ESI
//         004838ce     MOV        dword ptr [EAX + -0x4],ESI
//         004838d1     MOV        ESI,dword ptr [ESP + param_2]
//         004838d5     MOV        dword ptr [EAX],EBP
//         004838d7     MOV        this,dword ptr [L]                               = 00000000
//         004838dd     PUSH       ESI
//         004838de     PUSH       s_********Random_Map_calc_land_xy_               = "********Random Map calc land xy player %d
//         004838e3     PUSH       this
//         004838e4     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
//         004838e9     MOV        this,dword ptr [ESP + mid_y2]
//         004838ed     MOV        EAX,dword ptr [ESP + local_8]
//         004838f1     ADD        ESP,0x14
//         004838f4     INC        ESI
//         004838f5     ADD        this,0x34
//         004838f8     CMP        ESI,EAX
//         004838fa     MOV        dword ptr [ESP + param_2],ESI
//         004838fe     MOV        dword ptr [ESP + mid_y2],this
//         00483902     JL         LAB_00483789
//                              rmm_dbct.cpp:541 (5)
//         00483908     JMP        LAB_00483a02
//                               LAB_0048390d                                                 XREF[1]:     0048373d(j)
//                              rmm_dbct.cpp:491 (17)
//         0048390d     MOV        EDX,dword ptr [L]                                = 00000000
//         00483913     PUSH       s_********Random_Map_calc_land_end               = "********Random Map calc land end (point2) "
//         00483918     PUSH       EDX
//         00483919     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
//                              rmm_dbct.cpp:492 (22)
//         0048391e     MOV        this,dword ptr [ESP + param_1]
//         00483922     MOV        EAX,dword ptr [ESP + param_3]
//         00483926     ADD        ESP,0x8
//         00483929     LEA        EDX,[EAX + this->_padding_*0x1]
//         0048392c     CMP        this,EDX
//         0048392e     JGE        LAB_00483a02
//                              rmm_dbct.cpp:545 (29)
//         00483934     LEA        EAX,[ECX + ECX*0x2]
//         00483937     SUB        EDX,this
//         00483939     LEA        EAX,[this->_padding_ + EAX*0x4]
//         0048393c     LEA        EAX,[EDI + EAX*0x4 + 0x48]
//                               LAB_00483940                                                 XREF[1]:     0048394f(j)
//         00483940     MOV        this,dword ptr [ESI + 0x14]
//         00483943     MOV        dword ptr [EAX + -0x4],this
//         00483946     MOV        this,dword ptr [ESI + 0x18]
//         00483949     MOV        dword ptr [EAX],this
//         0048394b     ADD        EAX,0x34
//         0048394e     DEC        EDX
//         0048394f     JNZ        LAB_00483940
//                              rmm_dbct.cpp:497 (5)
//         00483951     JMP        LAB_00483a02
//                               LAB_00483956                                                 XREF[1]:     00483736(j)
//                              rmm_dbct.cpp:482 (17)
//         00483956     MOV        EDX,dword ptr [L]                                = 00000000
//         0048395c     PUSH       s_********Random_Map_calc_land_end               = "********Random Map calc land end (point1) "
//         00483961     PUSH       EDX
//         00483962     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
//                              rmm_dbct.cpp:483 (21)
//         00483967     MOV        EAX,dword ptr [ESP + param_1]
//         0048396b     MOV        this,dword ptr [ESP + param_3]
//         0048396f     ADD        this,EAX
//         00483971     ADD        ESP,0x8
//         00483974     CMP        EAX,this
//         00483976     JGE        LAB_00483a02
//                              rmm_dbct.cpp:545 (134)
//         0048397c     LEA        EDX,[EAX + EAX*0x2]
//         0048397f     SUB        this,EAX
//         00483981     MOV        dword ptr [ESP + param_3],this
//         00483985     LEA        EDX,[EAX + EDX*0x4]
//         00483988     LEA        ESI,[EDI + EDX*0x4 + 0x48]
//                               LAB_0048398c                                                 XREF[1]:     00483a00(j)
//         0048398c     PUSH       0x1e5
//         00483991     PUSH       s_C:\msdev\work\age1_x1\rmm_dbct.c               = "C:\\msdev\\work\\age1_x1\\rmm_dbct.cpp"
//         00483996     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
//         0048399b     MOV        this,EAX
//         0048399d     MOV        EAX,dword ptr [EDI + 0x14]
//         004839a0     SUB        EAX,EBP
//         004839a2     ADD        ESP,0x8
//         004839a5     IMUL       this,EAX
//         004839a8     MOV        EAX,0x80010003
//         004839ad     PUSH       0x1e6
//         004839b2     IMUL       this
//         004839b4     ADD        EDX,this
//         004839b6     PUSH       s_C:\msdev\work\age1_x1\rmm_dbct.c               = "C:\\msdev\\work\\age1_x1\\rmm_dbct.cpp"
//         004839bb     SAR        EDX,0xe
//         004839be     MOV        this,EDX
//         004839c0     SHR        this,0x1f
//         004839c3     ADD        EDX,this
//         004839c5     ADD        EDX,EBX
//         004839c7     MOV        dword ptr [ESI + -0x4],EDX
//         004839ca     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
//         004839cf     MOV        EDX,dword ptr [EDI + 0x18]
//         004839d2     MOV        this,EAX
//         004839d4     SUB        EDX,EBP
//         004839d6     MOV        EAX,0x80010003
//         004839db     IMUL       this,EDX
//         004839de     IMUL       this
//         004839e0     ADD        EDX,this
//         004839e2     ADD        ESP,0x8
//         004839e5     SAR        EDX,0xe
//         004839e8     MOV        EAX,EDX
//         004839ea     ADD        ESI,0x34
//         004839ed     SHR        EAX,0x1f
//         004839f0     ADD        EDX,EAX
//         004839f2     MOV        EAX,dword ptr [ESP + param_3]
//         004839f6     ADD        EDX,EBX
//         004839f8     DEC        EAX
//         004839f9     MOV        dword ptr [ESI + -0x34],EDX
//         004839fc     MOV        dword ptr [ESP + param_3],EAX
//         00483a00     JNZ        LAB_0048398c
//                               LAB_00483a02                                                 XREF[6]:     00483744(j), 00483771(j),
//                                                                                                         00483908(j), 0048392e(j),
//                                                                                                         00483951(j), 00483976(j)
//                              rmm_dbct.cpp:543 (20)
//         00483a02     MOV        this,dword ptr [L]                               = 00000000
//         00483a08     PUSH       s_********Random_Map_calc_land_end               = "********Random Map calc land end, rand:"
//         00483a0d     PUSH       this
//         00483a0e     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
//         00483a13     ADD        ESP,0x8
//                              rmm_dbct.cpp:545 (10)
//         00483a16     POP        EDI
//         00483a17     POP        ESI
//         00483a18     POP        EBP
//         00483a19     POP        EBX
//         00483a1a     ADD        ESP,0x30
//         00483a1d     RET        0x10
    return;
}

void RGE_RMM_Database_Controller::add_land_module(uchar param_1) {
    /* TODO: Stub */
//                              void __thiscall add_land_module(RGE_RMM_Database_Controller * this,
//              void              <VOID>         <RETURN>
//              RGE_RMM_Databa    ECX:4 (auto)   this
//              uchar             Stack[0x4]:1   param_1                   XREF[1]:     00483cb9(R)
//              long[8][8]        Stack[-0x104   distances                 XREF[0,2]:   00483ce0(*), 00483d3e(*)
//              long[8]           Stack[-0x124   player_teams              XREF[0,10]:  00483dbe(*), 00483dde(*), 00483de5(*), 00483dfa(*),
//                                                                                     00483e00(*), 00483e13(*), 00483e40(*), 00484114(*),
//                                                                                     004840d6(*), 00484132(*)
//              long[8]           Stack[-0x144   team_size                 XREF[2,17]:  00483eed(W), 0048407b(R), 00483cfc(*), 00483d2b(W),
//                                                                                     00483d57(R), 00483d60(W), 00483dee(*), 00483e04(*),
//                                                                                     00483e38(*), 00483e42(*), 00483ebb(*), 00483ee9(*),
//                                                                                     004840b8(*), 00483d53(*), 00483d5a(*), 00483d66(*),
//                                                                                     004840d0(*), 004840e6(*), 00484100(*)
//              long[8]           Stack[-0x168   ty                        XREF[4,8]:   00483ed9(W), 00483f07(R), 00483f4f(R), 00483fbb(R),
//                                                                                     00483ea1(*), 00483ec9(*), 00483ecd(*), 004840c4(*),
//                                                                                     004840c8(*), 004840fc(*), 0048411e(W), 0048413d(*)
//              long              Stack[-0x16c   start_land                XREF[4]:     00483f6f(W), 00483f80(R), 00483fe3(R), 00484027(R)
//              long              Stack[-0x170   swap                      XREF[5]:     00483e0f(W), 00483e21(R), 00483ef7(W), 00483f44(W),
//                                                                                     0048406e(R)
//              undefined4        Stack[-0x174   local_174                 XREF[5]:     00483df6(W), 00483e58(R), 00484004(W), 0048405c(R),
//                                                                                     00484064(W)
//              undefined4        Stack[-0x178   local_178                 XREF[7]:     00483a69(W), 00483b87(R), 00483c49(R), 00483fb1(W),
//                                                                                     00483fdf(W), 00483fe7(R), 00484042(R)
//              long              Stack[-0x17c   land_wanted               XREF[9]:     00483e99(W), 00483eb7(R), 00483efd(R), 00483f73(R),
//                                                                                     00483f9f(R), 0048401d(R), 0048402b(R), 0048406a(R),
//                                                                                     004840ac(R)
//              undefined4        Stack[-0x180   local_180                 XREF[10]:    00483a5e(W), 00483b0a(R), 00483c2d(R), 00483df2(W),
//                                                                                     00483e5c(R), 00483e83(W), 00483ebf(W), 00483edd(R),
//                                                                                     00484094(R), 004840a2(W)
//              long              Stack[-0x184   edge                      XREF[10]:    00483ae2(W), 00483ca2(R), 00483caf(W), 00483cee(W),
//                                                                                     00483d05(R), 00483d90(R), 00483da5(W), 00483ee1(W),
//                                                                                     00484077(R), 00484082(W)
//              long              Stack[-0x188   index1                    XREF[11]:    00483cce(W), 00483d30(R), 00483da1(W), 00483dcf(W),
//                                                                                     00483e6f(R), 00483e7d(W), 00483ea9(W), 00483f2a(R),
//                                                                                     00483f94(R), 00484090(R), 0048409e(W)
//              long              Stack[-0x18c   index                     XREF[13]:    00483b1b(W), 00483b6e(R), 00483bda(R), 00483be4(W),
//                                                                                     00483cea(W), 00483d3a(R), 00483d94(R), 00483da9(W),
//                                                                                     00483dcb(W), 00483e3b(R), 00483e54(R), 00483e67(W),
//                                                                                     0048408c(R)
//              long              Stack[-0x190   current_team              XREF[14]:    00483a2c(W), 00483af0(R), 00483b2b(R), 00483b83(R),
//                                                                                     00483b9b(R), 00483bf9(R), 00483c67(R), 00483cc8(R),
//                                                                                     00483cf4(R), 00483e1a(R), 00483e6b(R), 00483e8d(R),
//                                                                                     004840f8(R), 00484125(R)
//                               ?add_land_module@RGE_RMM_Database_Controller@@MAEXE@Z        XREF[2]:     add_land_module:00487984(c),
//                               RGE_RMM_Database_Controller::add_land_module                              00571e8c(*)
//                              rmm_dbct.cpp:549 (16)
//         00483a20     SUB        ESP,0x190
//         00483a26     PUSH       EBX
//         00483a27     PUSH       EBP
//         00483a28     MOV        EBP,this
//         00483a2a     PUSH       ESI
//         00483a2b     PUSH       EDI
//         00483a2c     MOV        dword ptr [ESP + current_team],EBP
//                              rmm_dbct.cpp:556 (9)
//         00483a30     MOV        EAX,dword ptr [EBP + 0x34]
//         00483a33     MOV        this,dword ptr [EBP + 0x4f58]
//                              rmm_dbct.cpp:559 (29)
//         00483a39     MOV        EBX,dword ptr [EBP + 0x14]
//         00483a3c     MOV        EDI,dword ptr [EBP + 0x18]
//         00483a3f     LEA        EAX,[EAX + EAX*0x8]
//         00483a42     LEA        ESI,[ECX + EAX*0x8 + this->_padding_]
//         00483a46     MOV        EAX,0x51eb851f
//         00483a4b     MOV        this,dword ptr [ESI + 0x1c]
//         00483a4e     IMUL       this,EBX
//         00483a51     IMUL       this,EDI
//         00483a54     IMUL       this
//                              rmm_dbct.cpp:560 (17)
//         00483a56     MOV        this,dword ptr [ESI + 0x14]
//         00483a59     SAR        EDX,0x5
//         00483a5c     MOV        EAX,EDX
//         00483a5e     MOV        dword ptr [ESP + local_180],this
//         00483a62     SHR        EAX,0x1f
//         00483a65     ADD        EDX,EAX
//                              rmm_dbct.cpp:563 (12)
//         00483a67     XOR        this,this
//         00483a69     MOV        dword ptr [ESP + local_178],EDX
//         00483a6d     MOV        dword ptr [EBP + 0x1458],this
//                              rmm_dbct.cpp:564 (9)
//         00483a73     MOV        EDX,dword ptr [ESI + 0x24]
//         00483a76     XOR        EAX,EAX
//         00483a78     CMP        EDX,this
//         00483a7a     JLE        LAB_00483aa2
//                               LAB_00483a7c                                                 XREF[1]:     00483aa0(j)
//                              rmm_dbct.cpp:566 (10)
//         00483a7c     MOV        EDX,dword ptr [ESI + 0x28]
//         00483a7f     CMP        byte ptr [ECX + EDX*0x1 + this+0x1d],0x0
//         00483a84     JZ         LAB_00483a91
//                              rmm_dbct.cpp:567 (9)
//         00483a86     MOV        EDX,dword ptr [EBP + 0x38]
//         00483a89     ADD        dword ptr [EBP + 0x1458],EDX
//                              rmm_dbct.cpp:568 (2)
//         00483a8f     JMP        LAB_00483a97
//                               LAB_00483a91                                                 XREF[1]:     00483a84(j)
//                              rmm_dbct.cpp:569 (17)
//         00483a91     INC        dword ptr [EBP + 0x1458]
//                               LAB_00483a97                                                 XREF[1]:     00483a8f(j)
//         00483a97     MOV        EDX,dword ptr [ESI + 0x24]
//         00483a9a     INC        EAX
//         00483a9b     ADD        this,0x2c
//         00483a9e     CMP        EAX,EDX
//         00483aa0     JL         LAB_00483a7c
//                               LAB_00483aa2                                                 XREF[1]:     00483a7a(j)
//                              rmm_dbct.cpp:572 (9)
//         00483aa2     MOV        AL,byte ptr [ESI + 0x18]
//         00483aa5     MOV        byte ptr [EBP + 0x145c],AL
//                              rmm_dbct.cpp:573 (8)
//         00483aab     MOV        this,dword ptr [ESI]
//         00483aad     MOV        dword ptr [EBP + 0x1460],this
//                              rmm_dbct.cpp:574 (9)
//         00483ab3     MOV        EDX,dword ptr [ESI + 0x4]
//         00483ab6     MOV        dword ptr [EBP + 0x1464],EDX
//                              rmm_dbct.cpp:575 (11)
//         00483abc     MOV        EDX,dword ptr [ESI + 0x8]
//         00483abf     SUB        EBX,EDX
//         00483ac1     MOV        dword ptr [EBP + 0x1468],EBX
//                              rmm_dbct.cpp:576 (5)
//         00483ac7     MOV        this,dword ptr [ESI + 0xc]
//         00483aca     SUB        EDI,this
//                              rmm_dbct.cpp:582 (17)
//         00483acc     XOR        EBX,EBX
//         00483ace     MOV        dword ptr [EBP + 0x146c],EDI
//         00483ad4     MOV        AL,byte ptr [ESI + 0x10]
//         00483ad7     MOV        byte ptr [EBP + 0x1470],AL
//                              rmm_dbct.cpp:584 (15)
//         00483add     MOV        EAX,dword ptr [ESI + 0x24]
//         00483ae0     CMP        EAX,EBX
//         00483ae2     MOV        dword ptr [ESP + edge],EBX
//         00483ae6     JLE        LAB_00483cb9
//                              rmm_dbct.cpp:572 (8)
//         00483aec     XOR        EDI,EDI
//         00483aee     JMP        LAB_00483af4
//                               LAB_00483af0                                                 XREF[1]:     00483cb3(j)
//         00483af0     MOV        EBP,dword ptr [ESP + current_team]
//                               LAB_00483af4                                                 XREF[1]:     00483aee(j)
//                              rmm_dbct.cpp:586 (18)
//         00483af4     MOV        this,dword ptr [ESI + 0x28]
//         00483af7     LEA        EAX,[EDI + this->_padding_*0x1]
//         00483afa     MOV        this,byte ptr [EDI + this->_padding_*0x1 + 0x1d]
//         00483afe     TEST       this,this
//         00483b00     JZ         LAB_00483bf3
//                              rmm_dbct.cpp:588 (18)
//         00483b06     MOV        EDX,dword ptr [EBP + 0x38]
//         00483b09     PUSH       EAX
//         00483b0a     MOV        EAX,dword ptr [ESP + local_180]
//         00483b0e     PUSH       EDX
//         00483b0f     PUSH       EAX
//         00483b10     PUSH       EBX
//         00483b11     MOV        this,EBP
//         00483b13     CALL       RGE_RMM_Database_Controller::calc_land_start     void calc_land_start(RGE_RMM_Database_Control
//                              rmm_dbct.cpp:590 (19)
//         00483b18     MOV        EAX,dword ptr [EBP + 0x38]
//         00483b1b     MOV        dword ptr [ESP + index],0x0
//         00483b23     TEST       EAX,EAX
//         00483b25     JLE        LAB_00483ca2
//                              rmm_dbct.cpp:844 (67)
//         00483b2b     MOV        EAX,dword ptr [ESP + current_team]
//         00483b2f     LEA        this,[EBX + EBX*0x2]
//         00483b32     LEA        EDX,[EBX + this->_padding_*0x4]
//         00483b35     LEA        this,[EAX + EDX*0x4 + 0x50]
//                               LAB_00483b39                                                 XREF[1]:     00483be8(j)
//         00483b39     MOV        EDX,dword ptr [ESI + 0x28]
//         00483b3c     XOR        EAX,EAX
//         00483b3e     MOV        AL,byte ptr [EDI + EDX*0x1 + 0x4]
//         00483b42     MOV        dword ptr [this->_padding_ + -0x10],EAX
//         00483b45     MOV        EDX,dword ptr [ESI + 0x28]
//         00483b48     MOV        EAX,dword ptr [EDI + EDX*0x1 + 0x8]
//         00483b4c     MOV        dword ptr [this->_padding_],EAX
//         00483b4e     MOV        EDX,dword ptr [ESI + 0x28]
//         00483b51     MOV        EAX,dword ptr [EDI + EDX*0x1 + 0xc]
//         00483b55     MOV        dword ptr [this->_padding_ + -0x4],EAX
//         00483b58     MOV        EDX,dword ptr [ESI + 0x28]
//         00483b5b     MOV        AL,byte ptr [EDI + EDX*0x1 + 0x1d]
//         00483b5f     LEA        EBP,[EDI + EDX*0x1]
//         00483b62     CMP        AL,0x1
//         00483b64     JNZ        LAB_00483b6e
//         00483b66     MOV        AL,byte ptr [EBP + 0x10]
//         00483b69     MOV        byte ptr [ECX + this->_padding_],AL
//         00483b6c     JMP        LAB_00483b75
//                               LAB_00483b6e                                                 XREF[1]:     00483b64(j)
//                              rmm_dbct.cpp:598 (7)
//         00483b6e     MOV        DL,byte ptr [ESP + index]
//         00483b72     MOV        byte ptr [ECX + this->_padding_],DL
//                               LAB_00483b75                                                 XREF[1]:     00483b6c(j)
//                              rmm_dbct.cpp:599 (5)
//         00483b75     MOV        EAX,dword ptr [ESI + 0x28]
//         00483b78     XOR        EDX,EDX
//                              rmm_dbct.cpp:607 (116)
//         00483b7a     ADD        this,0x34
//         00483b7d     MOV        DL,byte ptr [EDI + EAX*0x1 + 0x1c]
//         00483b81     MOV        EAX,EDX
//         00483b83     MOV        EDX,dword ptr [ESP + current_team]
//         00483b87     IMUL       EAX,dword ptr [ESP + local_178]
//         00483b8c     MOV        EDX,dword ptr [EDX + 0x38]
//         00483b8f     LEA        EDX,[EDX + EDX*0x4]
//         00483b92     LEA        EBP,[EDX + EDX*0x4]
//         00483b95     CDQ
//         00483b96     SHL        EBP,0x2
//         00483b99     IDIV       EBP
//         00483b9b     MOV        EBP,dword ptr [ESP + current_team]
//         00483b9f     INC        EBX
//         00483ba0     MOV        dword ptr [this->_padding_ + -0x48],EAX
//         00483ba3     MOV        EAX,dword ptr [ESI + 0x28]
//         00483ba6     MOV        EDX,dword ptr [EDI + EAX*0x1 + 0x28]
//         00483baa     MOV        dword ptr [this->_padding_ + -0x2c],EDX
//         00483bad     MOV        EAX,dword ptr [EBP + 0x1460]
//         00483bb3     MOV        dword ptr [this->_padding_ + -0x28],EAX
//         00483bb6     MOV        EDX,dword ptr [EBP + 0x1464]
//         00483bbc     MOV        dword ptr [this->_padding_ + -0x24],EDX
//         00483bbf     MOV        EAX,dword ptr [EBP + 0x1468]
//         00483bc5     MOV        dword ptr [this->_padding_ + -0x20],EAX
//         00483bc8     MOV        EDX,dword ptr [EBP + 0x146c]
//         00483bce     MOV        dword ptr [this->_padding_ + -0x1c],EDX
//         00483bd1     MOV        AL,byte ptr [EBP + 0x1470]
//         00483bd7     MOV        byte ptr [this->_padding_ + -0x18],AL
//         00483bda     MOV        EAX,dword ptr [ESP + index]
//         00483bde     MOV        EDX,dword ptr [EBP + 0x38]
//         00483be1     INC        EAX
//         00483be2     CMP        EAX,EDX
//         00483be4     MOV        dword ptr [ESP + index],EAX
//         00483be8     JL         LAB_00483b39
//                              rmm_dbct.cpp:610 (5)
//         00483bee     JMP        LAB_00483ca2
//                               LAB_00483bf3                                                 XREF[1]:     00483b00(j)
//                              rmm_dbct.cpp:612 (21)
//         00483bf3     LEA        this,[EBX + EBX*0x2]
//         00483bf6     LEA        EDX,[EBX + this->_padding_*0x4]
//         00483bf9     MOV        this,dword ptr [ESP + current_team]
//         00483bfd     LEA        EBP,[this->_padding_ + EDX*0x4]
//         00483c00     XOR        EDX,EDX
//         00483c02     MOV        DL,byte ptr [EAX + 0x4]
//         00483c05     MOV        dword ptr [EBP + 0x40],EDX
//                              rmm_dbct.cpp:613 (10)
//         00483c08     MOV        EAX,dword ptr [ESI + 0x28]
//         00483c0b     MOV        EDX,dword ptr [EDI + EAX*0x1 + 0x8]
//         00483c0f     MOV        dword ptr [EBP + 0x50],EDX
//                              rmm_dbct.cpp:614 (10)
//         00483c12     MOV        EAX,dword ptr [ESI + 0x28]
//         00483c15     MOV        EDX,dword ptr [EDI + EAX*0x1 + 0xc]
//         00483c19     MOV        dword ptr [EBP + 0x4c],EDX
//                              rmm_dbct.cpp:615 (7)
//         00483c1c     MOV        EAX,dword ptr [ESI + 0x28]
//         00483c1f     MOV        DL,byte ptr [EDI + EAX*0x1 + 0x10]
//                              rmm_dbct.cpp:616 (24)
//         00483c23     MOV        EAX,EDI
//         00483c25     MOV        byte ptr [EBP + 0x54],DL
//         00483c28     MOV        EDX,dword ptr [ESI + 0x28]
//         00483c2b     ADD        EAX,EDX
//         00483c2d     MOV        EDX,dword ptr [ESP + local_180]
//         00483c31     PUSH       EAX
//         00483c32     PUSH       0x1
//         00483c34     PUSH       EDX
//         00483c35     PUSH       EBX
//         00483c36     CALL       RGE_RMM_Database_Controller::calc_land_start     void calc_land_start(RGE_RMM_Database_Control
//                              rmm_dbct.cpp:617 (34)
//         00483c3b     MOV        EAX,dword ptr [ESI + 0x28]
//         00483c3e     XOR        this,this
//         00483c40     MOV        this,byte ptr [EDI + EAX*0x1 + 0x1c]
//         00483c44     MOV        EAX,0x51eb851f
//         00483c49     IMUL       this,dword ptr [ESP + local_178]
//         00483c4e     IMUL       this
//         00483c50     SAR        EDX,0x5
//         00483c53     MOV        this,EDX
//         00483c55     SHR        this,0x1f
//         00483c58     ADD        EDX,this
//         00483c5a     MOV        dword ptr [EBP + 0x3c],EDX
//                              rmm_dbct.cpp:618 (10)
//         00483c5d     MOV        EDX,dword ptr [ESI + 0x28]
//         00483c60     MOV        EAX,dword ptr [EDI + EDX*0x1 + 0x28]
//         00483c64     MOV        dword ptr [EBP + 0x58],EAX
//                              rmm_dbct.cpp:619 (13)
//         00483c67     MOV        EAX,dword ptr [ESP + current_team]
//         00483c6b     MOV        this,dword ptr [EAX + 0x1460]
//         00483c71     MOV        dword ptr [EBP + 0x5c],this
//                              rmm_dbct.cpp:620 (9)
//         00483c74     MOV        EDX,dword ptr [EAX + 0x1464]
//         00483c7a     MOV        dword ptr [EBP + 0x60],EDX
//                              rmm_dbct.cpp:621 (9)
//         00483c7d     MOV        this,dword ptr [EAX + 0x1468]
//         00483c83     MOV        dword ptr [EBP + 0x64],this
//                              rmm_dbct.cpp:622 (3)
//         00483c86     LEA        this,[EBX + 0x2]
//                              rmm_dbct.cpp:624 (48)
//         00483c89     INC        EBX
//         00483c8a     LEA        EDX,[ECX + ECX*0x2]
//         00483c8d     LEA        this,[this->_padding_ + EDX*0x4]
//         00483c90     MOV        EDX,dword ptr [EAX + 0x146c]
//         00483c96     MOV        dword ptr [EAX + this->_padding_*0x4],EDX
//         00483c99     MOV        AL,byte ptr [EAX + 0x1470]
//         00483c9f     MOV        byte ptr [EBP + 0x6c],AL
//                               LAB_00483ca2                                                 XREF[2]:     00483b25(j), 00483bee(j)
//         00483ca2     MOV        EAX,dword ptr [ESP + edge]
//         00483ca6     MOV        this,dword ptr [ESI + 0x24]
//         00483ca9     INC        EAX
//         00483caa     ADD        EDI,0x2c
//         00483cad     CMP        EAX,this
//         00483caf     MOV        dword ptr [ESP + edge],EAX
//         00483cb3     JL         LAB_00483af0
//                               LAB_00483cb9                                                 XREF[1]:     00483ae6(j)
//                              rmm_dbct.cpp:629 (15)
//         00483cb9     MOV        AL,byte ptr [ESP + param_1]
//         00483cc0     TEST       AL,AL
//         00483cc2     JZ         LAB_00484150
//                              rmm_dbct.cpp:653 (24)
//         00483cc8     MOV        EDX,dword ptr [ESP + current_team]
//         00483ccc     XOR        EBP,EBP
//         00483cce     MOV        dword ptr [ESP + index1],EBP
//         00483cd2     MOV        EBX,dword ptr [EDX + 0x1458]
//         00483cd8     TEST       EBX,EBX
//         00483cda     JLE        LAB_00483db3
//                              rmm_dbct.cpp:844 (24)
//         00483ce0     LEA        this=>distances[0][1],[ESP + 0xa0]
//         00483ce7     LEA        EAX,[EDX + 0x48]
//         00483cea     MOV        dword ptr [ESP + index],this
//         00483cee     MOV        dword ptr [ESP + edge],EAX
//         00483cf2     JMP        LAB_00483cf8
//                               LAB_00483cf4                                                 XREF[1]:     00483dad(j)
//         00483cf4     MOV        EDX,dword ptr [ESP + current_team]
//                               LAB_00483cf8                                                 XREF[1]:     00483cf2(j)
//                              rmm_dbct.cpp:656 (38)
//         00483cf8     TEST       EBX,EBX
//         00483cfa     JLE        LAB_00483d34
//         00483cfc     LEA        ESI=>team_size[1],[ESP + 0x60]
//         00483d00     ADD        EDX,0x48
//         00483d03     MOV        EDI,EBX
//                               LAB_00483d05                                                 XREF[1]:     00483d2e(j)
//         00483d05     MOV        this,dword ptr [ESP + edge]
//         00483d09     MOV        EBP,dword ptr [EDX + -0x4]
//         00483d0c     ADD        EDX,0x34
//         00483d0f     ADD        ESI,0x4
//         00483d12     MOV        EAX,dword ptr [this->_padding_ + -0x4]
//         00483d15     MOV        this,dword ptr [this->_padding_]
//         00483d17     SUB        EAX,EBP
//         00483d19     MOV        EBP,dword ptr [EDX + -0x34]
//         00483d1c     SUB        this,EBP
//                              rmm_dbct.cpp:660 (18)
//         00483d1e     MOV        EBP,EAX
//         00483d20     IMUL       EBP,EAX
//         00483d23     MOV        EAX,this
//         00483d25     IMUL       EAX,this
//         00483d28     ADD        EBP,EAX
//         00483d2a     DEC        EDI
//         00483d2b     MOV        dword ptr [ESI + team_size[1]],EBP
//         00483d2e     JNZ        LAB_00483d05
//                              rmm_dbct.cpp:656 (4)
//         00483d30     MOV        EBP,dword ptr [ESP + index1]
//                               LAB_00483d34                                                 XREF[1]:     00483cfa(j)
//                              rmm_dbct.cpp:664 (10)
//         00483d34     XOR        EAX,EAX
//         00483d36     TEST       EBX,EBX
//         00483d38     JLE        LAB_00483d48
//         00483d3a     MOV        this,dword ptr [ESP + index]
//                               LAB_00483d3e                                                 XREF[1]:     00483d46(j)
//                              rmm_dbct.cpp:665 (10)
//         00483d3e     MOV        dword ptr [this->_padding_]=>distances[0][1],EAX
//         00483d40     INC        EAX
//         00483d41     ADD        this,0x4
//         00483d44     CMP        EAX,EBX
//         00483d46     JL         LAB_00483d3e
//                               LAB_00483d48                                                 XREF[2]:     00483d38(j), 00483d8e(j)
//                              rmm_dbct.cpp:670 (5)
//         00483d48     MOV        EDI,0x1
//                              rmm_dbct.cpp:671 (6)
//         00483d4d     CMP        EBX,EDI
//         00483d4f     MOV        ESI,EDI
//         00483d51     JLE        LAB_00483d8c
//                              rmm_dbct.cpp:670 (4)
//         00483d53     LEA        this=>team_size[2],[ESP + 0x64]
//                               LAB_00483d57                                                 XREF[1]:     00483d8a(j)
//                              rmm_dbct.cpp:673 (9)
//         00483d57     MOV        EAX,dword ptr [ECX + team_size[1]]
//         00483d5a     MOV        EDX,dword ptr [this->_padding_]=>team_size[2]
//         00483d5c     CMP        EAX,EDX
//         00483d5e     JLE        LAB_00483d84
//                              rmm_dbct.cpp:676 (3)
//         00483d60     MOV        dword ptr [ECX + team_size[1]],EDX
//                              rmm_dbct.cpp:679 (5)
//         00483d63     LEA        EDX,[ESI + EBP*0x8]
//         00483d66     MOV        dword ptr [this->_padding_]=>team_size[2],EAX
//                              rmm_dbct.cpp:680 (24)
//         00483d68     MOV        EDI,dword ptr [ESP + EDX*0x4 + 0xa0]
//         00483d6f     LEA        EAX,[ESP + EDX*0x4 + 0xa0]
//         00483d76     MOV        EDX,dword ptr [ESP + EDX*0x4 + 0x9c]
//         00483d7d     MOV        dword ptr [EAX + -0x4],EDI
//                              rmm_dbct.cpp:681 (2)
//         00483d80     MOV        dword ptr [EAX],EDX
//                              rmm_dbct.cpp:683 (10)
//         00483d82     XOR        EDI,EDI
//                               LAB_00483d84                                                 XREF[1]:     00483d5e(j)
//         00483d84     INC        ESI
//         00483d85     ADD        this,0x4
//         00483d88     CMP        ESI,EBX
//         00483d8a     JL         LAB_00483d57
//                               LAB_00483d8c                                                 XREF[1]:     00483d51(j)
//                              rmm_dbct.cpp:668 (39)
//         00483d8c     TEST       EDI,EDI
//         00483d8e     JZ         LAB_00483d48
//         00483d90     MOV        EDX,dword ptr [ESP + edge]
//         00483d94     MOV        this,dword ptr [ESP + index]
//         00483d98     INC        EBP
//         00483d99     ADD        EDX,0x34
//         00483d9c     ADD        this,0x20
//         00483d9f     CMP        EBP,EBX
//         00483da1     MOV        dword ptr [ESP + index1],EBP
//         00483da5     MOV        dword ptr [ESP + edge],EDX
//         00483da9     MOV        dword ptr [ESP + index],this
//         00483dad     JL         LAB_00483cf4
//                               LAB_00483db3                                                 XREF[1]:     00483cda(j)
//                              rmm_dbct.cpp:690 (20)
//         00483db3     OR         ESI,0xffffffff
//         00483db6     TEST       EBX,EBX
//         00483db8     JLE        LAB_00483dc7
//         00483dba     MOV        this,EBX
//         00483dbc     MOV        EAX,ESI
//         00483dbe     LEA        EDI=>player_teams[1],[ESP + 0x80]
//         00483dc5     STOSD.REP  ES:EDI
//                               LAB_00483dc7                                                 XREF[1]:     00483db8(j)
//                              rmm_dbct.cpp:693 (2)
//         00483dc7     XOR        EDX,EDX
//                              rmm_dbct.cpp:694 (49)
//         00483dc9     CMP        EBX,EDX
//         00483dcb     MOV        dword ptr [ESP + index],EDX
//         00483dcf     MOV        dword ptr [ESP + index1],EDX
//         00483dd3     JLE        LAB_00483e8d
//         00483dd9     MOV        EDI,0x4
//         00483dde     LEA        EAX=>player_teams[1],[ESP + 0x80]
//         00483de5     LEA        this=>player_teams[1],[ESP + 0x80]
//         00483dec     SUB        EDI,EAX
//         00483dee     LEA        EBP=>team_size[1],[ESP + 0x60]
//         00483df2     MOV        dword ptr [ESP + local_180],this
//         00483df6     MOV        dword ptr [ESP + local_174],EDI
//                               LAB_00483dfa                                                 XREF[1]:     00483e87(j)
//                              rmm_dbct.cpp:695 (4)
//         00483dfa     CMP        dword ptr [this->_padding_]=>player_teams[1],ESI
//         00483dfc     JNZ        LAB_00483e6b
//                              rmm_dbct.cpp:700 (21)
//         00483dfe     XOR        EAX,EAX
//         00483e00     MOV        dword ptr [this->_padding_]=>player_teams[1],EDX
//         00483e02     TEST       EBX,EBX
//         00483e04     MOV        dword ptr [EBP]=>team_size[1],0x1
//         00483e0b     JLE        LAB_00483e63
//         00483e0d     ADD        EDI,this
//         00483e0f     MOV        dword ptr [ESP + swap],EDI
//                              rmm_dbct.cpp:844 (122)
//         00483e13     LEA        EDI=>player_teams[1],[ESP + 0x80]
//                               LAB_00483e1a                                                 XREF[1]:     00483e52(j)
//         00483e1a     MOV        EBX,dword ptr [ESP + current_team]
//         00483e1e     LEA        ESI,[EAX + 0x1]
//         00483e21     MOV        EAX,dword ptr [ESP + swap]
//         00483e25     PUSH       ESI
//         00483e26     MOV        this,dword ptr [EBX + 0x30]
//         00483e29     MOV        EDX,dword ptr [ECX + this+0x40]
//         00483e2c     MOV        this,dword ptr [EDX + EAX*0x1]
//         00483e2f     CALL       RGE_Player::relation                             uchar relation(RGE_Player * this, long param_1)
//         00483e34     TEST       AL,AL
//         00483e36     JNZ        LAB_00483e45
//         00483e38     MOV        EAX,dword ptr [EBP]=>team_size[1]
//         00483e3b     MOV        this,dword ptr [ESP + index]
//         00483e3f     INC        EAX
//         00483e40     MOV        dword ptr [EDI]=>player_teams[1],this
//         00483e42     MOV        dword ptr [EBP]=>team_size[1],EAX
//                               LAB_00483e45                                                 XREF[1]:     00483e36(j)
//         00483e45     MOV        this,dword ptr [EBX + 0x1458]
//         00483e4b     MOV        EAX,ESI
//         00483e4d     ADD        EDI,0x4
//         00483e50     CMP        EAX,this
//         00483e52     JL         LAB_00483e1a
//         00483e54     MOV        EDX,dword ptr [ESP + index]
//         00483e58     MOV        EDI,dword ptr [ESP + local_174]
//         00483e5c     MOV        this,dword ptr [ESP + local_180]
//         00483e60     OR         ESI,0xffffffff
//                               LAB_00483e63                                                 XREF[1]:     00483e0b(j)
//         00483e63     INC        EDX
//         00483e64     ADD        EBP,0x4
//         00483e67     MOV        dword ptr [ESP + index],EDX
//                               LAB_00483e6b                                                 XREF[1]:     00483dfc(j)
//         00483e6b     MOV        EBX,dword ptr [ESP + current_team]
//         00483e6f     MOV        EAX,dword ptr [ESP + index1]
//         00483e73     INC        EAX
//         00483e74     ADD        this,0x4
//         00483e77     MOV        EBX,dword ptr [EBX + 0x1458]
//         00483e7d     MOV        dword ptr [ESP + index1],EAX
//         00483e81     CMP        EAX,EBX
//         00483e83     MOV        dword ptr [ESP + local_180],this
//         00483e87     JL         LAB_00483dfa
//                               LAB_00483e8d                                                 XREF[1]:     00483dd3(j)
//                              rmm_dbct.cpp:710 (26)
//         00483e8d     MOV        EAX,dword ptr [ESP + current_team]
//         00483e91     MOV        this,dword ptr [EAX + 0x1458]
//         00483e97     TEST       this,this
//         00483e99     MOV        dword ptr [ESP + land_wanted],this
//         00483e9d     JLE        LAB_00483ea7
//         00483e9f     MOV        EAX,ESI
//         00483ea1     LEA        EDI=>ty[1],[ESP + 0x3c]
//         00483ea5     STOSD.REP  ES:EDI
//                               LAB_00483ea7                                                 XREF[1]:     00483e9d(j)
//                              rmm_dbct.cpp:714 (28)
//         00483ea7     TEST       EDX,EDX
//         00483ea9     MOV        dword ptr [ESP + index1],0x0
//         00483eb1     JLE        LAB_004840ac
//         00483eb7     MOV        EBP,dword ptr [ESP + land_wanted]
//         00483ebb     LEA        this=>team_size[1],[ESP + 0x60]
//         00483ebf     MOV        dword ptr [ESP + local_180],this
//                               LAB_00483ec3                                                 XREF[1]:     004840a6(j)
//                              rmm_dbct.cpp:716 (10)
//         00483ec3     XOR        EAX,EAX
//         00483ec5     TEST       EBP,EBP
//         00483ec7     JLE        LAB_00483ed9
//         00483ec9     LEA        this=>ty[1],[ESP + 0x3c]
//                               LAB_00483ecd                                                 XREF[1]:     00483ed7(j)
//                              rmm_dbct.cpp:717 (12)
//         00483ecd     CMP        dword ptr [this->_padding_]=>ty[1],ESI
//         00483ecf     JZ         LAB_00483ed9
//         00483ed1     INC        EAX
//         00483ed2     ADD        this,0x4
//         00483ed5     CMP        EAX,EBP
//         00483ed7     JL         LAB_00483ecd
//                               LAB_00483ed9                                                 XREF[2]:     00483ec7(j), 00483ecf(j)
//                              rmm_dbct.cpp:720 (4)
//         00483ed9     MOV        dword ptr [ESP + ty[0]],EAX
//                              rmm_dbct.cpp:723 (26)
//         00483edd     MOV        EAX,dword ptr [ESP + local_180]
//         00483ee1     MOV        dword ptr [ESP + edge],0x0
//         00483ee9     MOV        EBX,dword ptr [EAX]=>team_size[1]
//         00483eeb     TEST       EBX,EBX
//         00483eed     MOV        dword ptr [ESP + team_size[0]],EBX
//         00483ef1     JLE        LAB_00484090
//                              rmm_dbct.cpp:720 (10)
//         00483ef7     MOV        dword ptr [ESP + swap],EBX
//         00483efb     JMP        LAB_00483f01
//                               LAB_00483efd                                                 XREF[1]:     00483ff9(j)
//         00483efd     MOV        EBP,dword ptr [ESP + land_wanted]
//                               LAB_00483f01                                                 XREF[3]:     00483efb(j), 00484072(j),
//                                                                                                         00484086(j)
//                              rmm_dbct.cpp:726 (23)
//         00483f01     XOR        EAX,EAX
//         00483f03     TEST       EBX,EBX
//         00483f05     JLE        LAB_00483f34
//         00483f07     MOV        this,dword ptr [ESP + ty[0]]
//         00483f0b     SHL        this,0x5
//         00483f0e     OR         ESI,0xffffffff
//         00483f11     LEA        this,[ESP + this->_padding_*0x1 + 0xa0]
//                               LAB_00483f18                                                 XREF[1]:     00483f26(j)
//                              rmm_dbct.cpp:728 (2)
//         00483f18     MOV        EDX,dword ptr [this->_padding_]
//                              rmm_dbct.cpp:729 (16)
//         00483f1a     CMP        dword ptr [ESP + EDX*0x4 + 0x3c],ESI
//         00483f1e     JZ         LAB_00483f2a
//         00483f20     INC        EAX
//         00483f21     ADD        this,0x4
//         00483f24     CMP        EAX,EBX
//         00483f26     JL         LAB_00483f18
//         00483f28     JMP        LAB_00483f37
//                               LAB_00483f2a                                                 XREF[1]:     00483f1e(j)
//                              rmm_dbct.cpp:731 (13)
//         00483f2a     MOV        this,dword ptr [ESP + index1]
//         00483f2e     MOV        dword ptr [ESP + EDX*0x4 + 0x3c],this
//         00483f32     JMP        LAB_00483f37
//                               LAB_00483f34                                                 XREF[1]:     00483f05(j)
//         00483f34     OR         ESI,0xffffffff
//                               LAB_00483f37                                                 XREF[2]:     00483f28(j), 00483f32(j)
//                              rmm_dbct.cpp:737 (8)
//         00483f37     CMP        EAX,EBX
//         00483f39     JL         LAB_00484077
//                              rmm_dbct.cpp:742 (4)
//         00483f3f     CMP        EBX,EBP
//         00483f41     JGE        LAB_00483f48
//                              rmm_dbct.cpp:743 (5)
//         00483f43     INC        EBX
//         00483f44     MOV        dword ptr [ESP + swap],EBX
//                               LAB_00483f48                                                 XREF[1]:     00483f41(j)
//                              rmm_dbct.cpp:747 (21)
//         00483f48     DEC        EBP
//         00483f49     MOV        EAX,EBP
//         00483f4b     TEST       EAX,EAX
//         00483f4d     JL         LAB_00483f73
//         00483f4f     MOV        EDX,dword ptr [ESP + ty[0]]
//         00483f53     LEA        this,[EAX + EDX*0x8]
//         00483f56     LEA        this,[ESP + this->_padding_*0x4 + 0xa0]
//                               LAB_00483f5d                                                 XREF[1]:     00483f6b(j)
//                              rmm_dbct.cpp:749 (2)
//         00483f5d     MOV        EDX,dword ptr [this->_padding_]
//                              rmm_dbct.cpp:750 (16)
//         00483f5f     CMP        dword ptr [ESP + EDX*0x4 + 0x3c],ESI
//         00483f63     JZ         LAB_00483f6f
//         00483f65     DEC        EAX
//         00483f66     SUB        this,0x4
//         00483f69     TEST       EAX,EAX
//         00483f6b     JGE        LAB_00483f5d
//         00483f6d     JMP        LAB_00483f73
//                               LAB_00483f6f                                                 XREF[1]:     00483f63(j)
//                              rmm_dbct.cpp:752 (4)
//         00483f6f     MOV        dword ptr [ESP + start_land],EDX
//                               LAB_00483f73                                                 XREF[2]:     00483f4d(j), 00483f6d(j)
//                              rmm_dbct.cpp:760 (27)
//         00483f73     MOV        EAX,dword ptr [ESP + land_wanted]
//         00483f77     OR         EDI,0xffffffff
//         00483f7a     XOR        ESI,ESI
//         00483f7c     TEST       EAX,EAX
//         00483f7e     JLE        LAB_00483fe3
//         00483f80     MOV        EDX,dword ptr [ESP + start_land]
//         00483f84     SHL        EDX,0x5
//         00483f87     LEA        EDX,[ESP + EDX*0x1 + 0xa0]
//                               LAB_00483f8e                                                 XREF[1]:     00483fa9(j)
//                              rmm_dbct.cpp:762 (2)
//         00483f8e     MOV        EAX,dword ptr [EDX]
//                              rmm_dbct.cpp:763 (15)
//         00483f90     MOV        this,dword ptr [ESP + EAX*0x4 + 0x3c]
//         00483f94     CMP        this,dword ptr [ESP + index1]
//         00483f98     JZ         LAB_00483f9f
//         00483f9a     CMP        this,-0x1
//         00483f9d     JG         LAB_00483fad
//                               LAB_00483f9f                                                 XREF[1]:     00483f98(j)
//                              rmm_dbct.cpp:760 (14)
//         00483f9f     MOV        EAX,dword ptr [ESP + land_wanted]
//         00483fa3     INC        ESI
//         00483fa4     ADD        EDX,0x4
//         00483fa7     CMP        ESI,EAX
//         00483fa9     JL         LAB_00483f8e
//         00483fab     JMP        LAB_00483fe3
//                               LAB_00483fad                                                 XREF[1]:     00483f9d(j)
//                              rmm_dbct.cpp:767 (4)
//         00483fad     MOV        EDI,dword ptr [ESP + EAX*0x4 + 0x3c]
//                              rmm_dbct.cpp:768 (4)
//         00483fb1     MOV        dword ptr [ESP + local_178],EAX
//                              rmm_dbct.cpp:771 (6)
//         00483fb5     XOR        EAX,EAX
//         00483fb7     TEST       EBX,EBX
//         00483fb9     JLE        LAB_00483fe3
//                              rmm_dbct.cpp:844 (32)
//         00483fbb     MOV        this,dword ptr [ESP + ty[0]]
//         00483fbf     SHL        this,0x5
//         00483fc2     LEA        EDX,[ESP + this->_padding_*0x1 + 0xa0]
//                               LAB_00483fc9                                                 XREF[1]:     00483fd7(j)
//         00483fc9     MOV        this,dword ptr [EDX]
//         00483fcb     CMP        dword ptr [ESP + this->_padding_*0x4 + 0x3c],EDI
//         00483fcf     JZ         LAB_00483fdb
//         00483fd1     INC        EAX
//         00483fd2     ADD        EDX,0x4
//         00483fd5     CMP        EAX,EBX
//         00483fd7     JL         LAB_00483fc9
//         00483fd9     JMP        LAB_00483fe3
//                               LAB_00483fdb                                                 XREF[1]:     00483fcf(j)
//                              rmm_dbct.cpp:777 (4)
//         00483fdb     MOV        EDI,dword ptr [ESP + this->_padding_*0x4 + 0x3c]
//                              rmm_dbct.cpp:778 (4)
//         00483fdf     MOV        dword ptr [ESP + local_178],this
//                               LAB_00483fe3                                                 XREF[4]:     00483f7e(j), 00483fab(j),
//                                                                                                         00483fb9(j), 00483fd9(j)
//                              rmm_dbct.cpp:788 (4)
//         00483fe3     MOV        EDX,dword ptr [ESP + start_land]
//                              rmm_dbct.cpp:789 (4)
//         00483fe7     MOV        EAX,dword ptr [ESP + local_178]
//                              rmm_dbct.cpp:790 (36)
//         00483feb     TEST       EBP,EBP
//         00483fed     MOV        dword ptr [ESP + EDX*0x4 + 0x3c],EDI
//         00483ff1     MOV        dword ptr [ESP + EAX*0x4 + 0x3c],0xffffffff
//         00483ff9     JL         LAB_00483efd
//         00483fff     LEA        this,[EBP + EDI*0x8]
//         00484003     INC        EBP
//         00484004     MOV        dword ptr [ESP + local_174],EBP
//         00484008     LEA        EBX,[ESP + this->_padding_*0x4 + 0xa0]
//                               LAB_0048400f                                                 XREF[1]:     00484068(j)
//                              rmm_dbct.cpp:792 (2)
//         0048400f     MOV        EAX,dword ptr [EBX]
//                              rmm_dbct.cpp:793 (12)
//         00484011     LEA        ESI,[ESP + EAX*0x4 + 0x3c]
//         00484015     MOV        EAX,dword ptr [ESP + EAX*0x4 + 0x3c]
//         00484019     CMP        EAX,EDI
//         0048401b     JNZ        LAB_0048405c
//                              rmm_dbct.cpp:795 (10)
//         0048401d     MOV        EAX,dword ptr [ESP + land_wanted]
//         00484021     XOR        EDX,EDX
//         00484023     TEST       EAX,EAX
//         00484025     JLE        LAB_0048405c
//                              rmm_dbct.cpp:844 (27)
//         00484027     MOV        EAX,dword ptr [ESP + start_land]
//         0048402b     MOV        EBP,dword ptr [ESP + land_wanted]
//         0048402f     SHL        EAX,0x5
//         00484032     LEA        this,[ESP + EAX*0x1 + 0xa0]
//                               LAB_00484039                                                 XREF[1]:     0048404e(j)
//         00484039     MOV        EAX,dword ptr [this->_padding_]
//         0048403b     CMP        dword ptr [ESP + EAX*0x4 + 0x3c],-0x1
//         00484040     JNZ        LAB_00484048
//                              rmm_dbct.cpp:798 (6)
//         00484042     CMP        EAX,dword ptr [ESP + local_178]
//         00484046     JNZ        LAB_00484052
//                               LAB_00484048                                                 XREF[1]:     00484040(j)
//                              rmm_dbct.cpp:795 (10)
//         00484048     INC        EDX
//         00484049     ADD        this,0x4
//         0048404c     CMP        EDX,EBP
//         0048404e     JL         LAB_00484039
//         00484050     JMP        LAB_0048405c
//                               LAB_00484052                                                 XREF[1]:     00484046(j)
//                              rmm_dbct.cpp:800 (6)
//         00484052     MOV        dword ptr [ESI],0xffffffff
//                              rmm_dbct.cpp:801 (31)
//         00484058     MOV        dword ptr [ESP + EAX*0x4 + 0x3c],EDI
//                               LAB_0048405c                                                 XREF[3]:     0048401b(j), 00484025(j),
//                                                                                                         00484050(j)
//         0048405c     MOV        EAX,dword ptr [ESP + local_174]
//         00484060     SUB        EBX,0x4
//         00484063     DEC        EAX
//         00484064     MOV        dword ptr [ESP + local_174],EAX
//         00484068     JNZ        LAB_0048400f
//         0048406a     MOV        EBP,dword ptr [ESP + land_wanted]
//         0048406e     MOV        EBX,dword ptr [ESP + swap]
//         00484072     JMP        LAB_00483f01
//                               LAB_00484077                                                 XREF[1]:     00483f39(j)
//                              rmm_dbct.cpp:723 (25)
//         00484077     MOV        EAX,dword ptr [ESP + edge]
//         0048407b     MOV        this,dword ptr [ESP + team_size[0]]
//         0048407f     INC        EAX
//         00484080     CMP        EAX,this
//         00484082     MOV        dword ptr [ESP + edge],EAX
//         00484086     JL         LAB_00483f01
//         0048408c     MOV        EDX,dword ptr [ESP + index]
//                               LAB_00484090                                                 XREF[1]:     00483ef1(j)
//                              rmm_dbct.cpp:714 (28)
//         00484090     MOV        EAX,dword ptr [ESP + index1]
//         00484094     MOV        EDI,dword ptr [ESP + local_180]
//         00484098     INC        EAX
//         00484099     ADD        EDI,0x4
//         0048409c     CMP        EAX,EDX
//         0048409e     MOV        dword ptr [ESP + index1],EAX
//         004840a2     MOV        dword ptr [ESP + local_180],EDI
//         004840a6     JL         LAB_00483ec3
//                               LAB_004840ac                                                 XREF[1]:     00483eb1(j)
//                              rmm_dbct.cpp:814 (18)
//         004840ac     MOV        EBX,dword ptr [ESP + land_wanted]
//         004840b0     TEST       EBX,EBX
//         004840b2     JLE        LAB_004840be
//         004840b4     MOV        this,EBX
//         004840b6     MOV        EAX,ESI
//         004840b8     LEA        EDI=>team_size[1],[ESP + 0x60]
//         004840bc     STOSD.REP  ES:EDI
//                               LAB_004840be                                                 XREF[1]:     004840b2(j)
//                              rmm_dbct.cpp:817 (10)
//         004840be     XOR        EDI,EDI
//         004840c0     TEST       EBX,EBX
//         004840c2     JLE        LAB_004840f2
//         004840c4     LEA        EDX=>ty[1],[ESP + 0x3c]
//                               LAB_004840c8                                                 XREF[1]:     004840f0(j)
//                              rmm_dbct.cpp:819 (2)
//         004840c8     MOV        this,dword ptr [EDX]=>ty[1]
//                              rmm_dbct.cpp:820 (6)
//         004840ca     XOR        EAX,EAX
//         004840cc     TEST       EBX,EBX
//         004840ce     JLE        LAB_004840ea
//                               LAB_004840d0                                                 XREF[1]:     004840e2(j)
//                              rmm_dbct.cpp:821 (15)
//         004840d0     CMP        dword ptr [ESP + EAX*0x4 + team_size[2]],ESI
//         004840d4     JNZ        LAB_004840df
//         004840d6     CMP        dword ptr [ESP + EAX*0x4 + player_teams[2]],this
//         004840dd     JZ         LAB_004840e6
//                               LAB_004840df                                                 XREF[1]:     004840d4(j)
//                              rmm_dbct.cpp:820 (7)
//         004840df     INC        EAX
//         004840e0     CMP        EAX,EBX
//         004840e2     JL         LAB_004840d0
//         004840e4     JMP        LAB_004840ea
//                               LAB_004840e6                                                 XREF[1]:     004840dd(j)
//                              rmm_dbct.cpp:823 (4)
//         004840e6     MOV        dword ptr [ESP + EAX*0x4 + team_size[2]],EDI
//                               LAB_004840ea                                                 XREF[2]:     004840ce(j), 004840e4(j)
//                              rmm_dbct.cpp:817 (8)
//         004840ea     INC        EDI
//         004840eb     ADD        EDX,0x4
//         004840ee     CMP        EDI,EBX
//         004840f0     JL         LAB_004840c8
//                               LAB_004840f2                                                 XREF[1]:     004840c2(j)
//                              rmm_dbct.cpp:832 (14)
//         004840f2     XOR        this,this
//         004840f4     TEST       EBX,EBX
//         004840f6     JLE        LAB_00484125
//         004840f8     MOV        ESI,dword ptr [ESP + current_team]
//         004840fc     LEA        EDX=>ty[1],[ESP + 0x3c]
//                               LAB_00484100                                                 XREF[1]:     00484121(j)
//                              rmm_dbct.cpp:834 (27)
//         00484100     MOV        EAX,dword ptr [ESP + this->_padding_*0x4 + tea
//         00484104     INC        this
//         00484105     ADD        EDX,0x4
//         00484108     CMP        this,EBX
//         0048410a     LEA        EDI,[EAX + EAX*0x2]
//         0048410d     LEA        EAX,[EAX + EDI*0x4]
//         00484110     MOV        EDI,dword ptr [ESI + EAX*0x4 + 0x44]
//         00484114     MOV        dword ptr [ESP + this->_padding_*0x4 + player_
//         00484118     LEA        EAX,[ESI + EAX*0x4]
//                              rmm_dbct.cpp:835 (8)
//         0048411b     MOV        EAX,dword ptr [EAX + 0x48]
//         0048411e     MOV        dword ptr [EDX + ty[1]],EAX
//         00484121     JL         LAB_00484100
//                              rmm_dbct.cpp:832 (6)
//         00484123     JMP        LAB_00484129
//                               LAB_00484125                                                 XREF[1]:     004840f6(j)
//         00484125     MOV        ESI,dword ptr [ESP + current_team]
//                               LAB_00484129                                                 XREF[1]:     00484123(j)
//                              rmm_dbct.cpp:838 (9)
//         00484129     XOR        EAX,EAX
//         0048412b     TEST       EBX,EBX
//         0048412d     JLE        LAB_00484150
//         0048412f     LEA        this,[ESI + 0x48]
//                               LAB_00484132                                                 XREF[1]:     0048414e(j)
//                              rmm_dbct.cpp:840 (11)
//         00484132     MOV        EDX,dword ptr [ESP + EAX*0x4 + player_teams[2]]
//         00484139     INC        EAX
//         0048413a     MOV        dword ptr [this->_padding_ + -0x4],EDX
//                              rmm_dbct.cpp:841 (19)
//         0048413d     MOV        EDX,dword ptr [ESP + EAX*0x4 + ty[1]]
//         00484141     MOV        dword ptr [this->_padding_],EDX
//         00484143     MOV        EDX,dword ptr [ESI + 0x1458]
//         00484149     ADD        this,0x34
//         0048414c     CMP        EAX,EDX
//         0048414e     JL         LAB_00484132
//                               LAB_00484150                                                 XREF[2]:     00483cc2(j), 0048412d(j)
//                              rmm_dbct.cpp:844 (13)
//         00484150     POP        EDI
//         00484151     POP        ESI
//         00484152     POP        EBP
//         00484153     POP        EBX
//         00484154     ADD        ESP,0x190
//         0048415a     RET        0x4
//         0048415d     ??         90h
//         0048415e     NOP
//         0048415f     NOP
    return;
}

void RGE_RMM_Database_Controller::add_terrain_module() {
    /* TODO: Stub */
//                              void __thiscall add_terrain_module(RGE_RMM_Database_Controller * this)
//              void              <VOID>         <RETURN>
//              RGE_RMM_Databa    ECX:4 (auto)   this
//              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     004841c0(W), 004841c4(R)
//              undefined4        Stack[-0x8]:4  local_8                   XREF[5]:     004841a8(W), 004841bb(R), 0048425b(W), 004842a6(R),
//                                                                                     004842ae(W)
//              long              Stack[-0xc]:4  land_tile_num             XREF[6]:     00484177(W), 00484212(R), 00484226(W), 00484235(W),
//                                                                                     004842fb(R), 00484308(W)
//              long              Stack[-0x10]:4 index
//                               ?add_terrain_module@RGE_RMM_Database_Controller@@MAEXXZ      XREF[2]:     add_terrain_module:00487e06(c),
//                               RGE_RMM_Database_Controller::add_terrain_module                           00571e90(*)
//                              rmm_dbct.cpp:848 (8)
//         00484160     SUB        ESP,0xc
//         00484163     PUSH       EBX
//         00484164     MOV        EBX,this
//         00484166     PUSH       EBP
//         00484167     PUSH       ESI
//                              rmm_dbct.cpp:849 (9)
//         00484168     MOV        EAX,dword ptr [EBX + 0x34]
//         0048416b     MOV        this,dword ptr [EBX + 0x4f58]
//                              rmm_dbct.cpp:859 (61)
//         00484171     XOR        EBP,EBP
//         00484173     PUSH       EDI
//         00484174     LEA        EAX,[EAX + EAX*0x8]
//         00484177     MOV        dword ptr [ESP + land_tile_num],EBP
//         0048417b     LEA        ESI,[this->_padding_ + EAX*0x8]
//         0048417e     MOV        this,dword ptr [EBX + 0x14]
//         00484181     IMUL       this,dword ptr [EBX + 0x18]
//         00484185     IMUL       this,dword ptr [ESI + 0x20]
//         00484189     MOV        EAX,0x51eb851f
//         0048418e     IMUL       this
//         00484190     MOV        this,dword ptr [ESI + 0x30]
//         00484193     SAR        EDX,0x5
//         00484196     MOV        EAX,EDX
//         00484198     MOV        dword ptr [EBX + 0x20d4],this
//         0048419e     SHR        EAX,0x1f
//         004841a1     ADD        EDX,EAX
//         004841a3     MOV        EAX,dword ptr [ESI + 0x30]
//         004841a6     CMP        EAX,EBP
//         004841a8     MOV        dword ptr [ESP + local_8],EDX
//         004841ac     JLE        LAB_0048422c
//                              rmm_dbct.cpp:849 (6)
//         004841ae     LEA        EDI,[EBX + 0x147c]
//                               LAB_004841b4                                                 XREF[1]:     0048422a(j)
//                              rmm_dbct.cpp:861 (34)
//         004841b4     MOV        EDX,dword ptr [ESI + 0x34]
//         004841b7     MOV        EAX,dword ptr [EBP + EDX*0x1]
//         004841bb     IMUL       EAX,dword ptr [ESP + local_8]
//         004841c0     MOV        dword ptr [ESP + local_4],EAX
//         004841c4     FILD       dword ptr [ESP + local_4]
//         004841c8     FMUL       float ptr [DAT_00571ec0]                         = 0Ah
//         004841ce     CALL       __ftol                                           undefined __ftol()
//         004841d3     MOV        dword ptr [EDI + -0x8],EAX
//                              rmm_dbct.cpp:862 (16)
//         004841d6     MOV        this,dword ptr [ESI + 0x34]
//         004841d9     ADD        EDI,0x20
//         004841dc     MOV        EDX,dword ptr [EBP + this->_padding_*0x1 + 0x4]
//         004841e0     ADD        EBP,0x18
//         004841e3     MOV        dword ptr [EDI + -0x20],EDX
//                              rmm_dbct.cpp:863 (10)
//         004841e6     MOV        EAX,dword ptr [ESI + 0x34]
//         004841e9     MOV        this,dword ptr [EBP + EAX*0x1 + -0x10]
//         004841ed     MOV        dword ptr [EDI + -0x1c],this
//                              rmm_dbct.cpp:864 (10)
//         004841f0     MOV        EDX,dword ptr [ESI + 0x34]
//         004841f3     MOV        EAX,dword ptr [EBP + EDX*0x1 + -0x8]
//         004841f7     MOV        dword ptr [EDI + -0x14],EAX
//                              rmm_dbct.cpp:865 (7)
//         004841fa     MOV        dword ptr [EDI + -0x24],0x0
//                              rmm_dbct.cpp:866 (10)
//         00484201     MOV        this,dword ptr [ESI + 0x34]
//         00484204     MOV        EDX,dword ptr [EBP + this->_padding_*0x1 + -0xc]
//         00484208     MOV        dword ptr [EDI + -0x18],EDX
//                              rmm_dbct.cpp:867 (14)
//         0048420b     MOV        EAX,dword ptr [ESI + 0x34]
//         0048420e     MOV        this,dword ptr [EBP + EAX*0x1 + -0x4]
//         00484212     MOV        EAX,dword ptr [ESP + land_tile_num]
//         00484216     MOV        dword ptr [EDI + -0x10],this
//                              rmm_dbct.cpp:868 (19)
//         00484219     MOV        dword ptr [EDI + -0xc],0x1
//         00484220     MOV        this,dword ptr [ESI + 0x30]
//         00484223     INC        EAX
//         00484224     CMP        EAX,this
//         00484226     MOV        dword ptr [ESP + land_tile_num],EAX
//         0048422a     JL         LAB_004841b4
//                               LAB_0048422c                                                 XREF[1]:     004841ac(j)
//                              rmm_dbct.cpp:872 (19)
//         0048422c     MOV        EAX,dword ptr [ESI + 0x28]
//         0048422f     XOR        EDI,EDI
//         00484231     XOR        this,this
//         00484233     CMP        EAX,EDI
//         00484235     MOV        dword ptr [ESP + land_tile_num],EDI
//         00484239     JLE        LAB_00484312
//                               LAB_0048423f                                                 XREF[1]:     0048430c(j)
//                              rmm_dbct.cpp:873 (18)
//         0048423f     MOV        EDX,dword ptr [ESI + 0x2c]
//         00484242     LEA        EAX,[EDI + EDX*0x1]
//         00484245     MOV        EDX,dword ptr [EDI + EDX*0x1 + 0x20]
//         00484249     TEST       EDX,EDX
//         0048424b     JL         LAB_004842fb
//                              rmm_dbct.cpp:875 (7)
//         00484251     MOV        DL,byte ptr [EAX + 0x1d]
//         00484254     TEST       DL,DL
//         00484256     JZ         LAB_004842b6
//                              rmm_dbct.cpp:877 (19)
//         00484258     MOV        EAX,dword ptr [EBX + 0x38]
//         0048425b     MOV        dword ptr [ESP + local_8],0x0
//         00484263     TEST       EAX,EAX
//         00484265     JLE        LAB_004842fb
//                              rmm_dbct.cpp:897 (73)
//         0048426b     LEA        EDX,[ECX + ECX*0x2]
//         0048426e     MOV        EAX,this
//         00484270     SHL        EAX,0x4
//         00484273     LEA        EDX,[this->_padding_ + EDX*0x4]
//         00484276     LEA        EAX,[EAX + EBX*0x1 + 0x20dc]
//         0048427d     LEA        EDX,[EBX + EDX*0x4 + 0x48]
//                               LAB_00484281                                                 XREF[1]:     004842b2(j)
//         00484281     MOV        EBP,dword ptr [EDX + -0x4]
//         00484284     INC        this
//         00484285     MOV        dword ptr [EAX + -0x4],EBP
//         00484288     MOV        EBP,dword ptr [EDX]
//         0048428a     MOV        dword ptr [EAX],EBP
//         0048428c     MOV        EBP,dword ptr [ESI + 0x2c]
//         0048428f     ADD        EDX,0x34
//         00484292     ADD        EAX,0x10
//         00484295     MOV        EBP,dword ptr [EDI + EBP*0x1 + 0x20]
//         00484299     MOV        dword ptr [EAX + -0xc],EBP
//         0048429c     MOV        EBP,dword ptr [ESI + 0x2c]
//         0048429f     MOV        EBP,dword ptr [EDI + EBP*0x1 + 0x24]
//         004842a3     MOV        dword ptr [EAX + -0x8],EBP
//         004842a6     MOV        EBP,dword ptr [ESP + local_8]
//         004842aa     INC        EBP
//         004842ab     CMP        EBP,dword ptr [EBX + 0x38]
//         004842ae     MOV        dword ptr [ESP + local_8],EBP
//         004842b2     JL         LAB_00484281
//                              rmm_dbct.cpp:886 (2)
//         004842b4     JMP        LAB_004842fb
//                               LAB_004842b6                                                 XREF[1]:     00484256(j)
//                              rmm_dbct.cpp:888 (26)
//         004842b6     LEA        EAX,[ECX + ECX*0x2]
//         004842b9     LEA        EDX,[this->_padding_ + EAX*0x4]
//         004842bc     MOV        EAX,this
//         004842be     SHL        EAX,0x4
//         004842c1     MOV        EBP,dword ptr [EBX + EDX*0x4 + 0x44]
//         004842c5     LEA        EDX,[EBX + EDX*0x4]
//         004842c8     ADD        EAX,EBX
//         004842ca     MOV        dword ptr [EAX + 0x20d8],EBP
//                              rmm_dbct.cpp:889 (9)
//         004842d0     MOV        EDX,dword ptr [EDX + 0x48]
//         004842d3     MOV        dword ptr [EAX + 0x20dc],EDX
//                              rmm_dbct.cpp:890 (16)
//         004842d9     MOV        EDX,dword ptr [ESI + 0x2c]
//         004842dc     LEA        EBP,[ECX + this+0x20e]
//         004842e2     MOV        EDX,dword ptr [EDI + EDX*0x1 + 0x20]
//         004842e6     SHL        EBP,0x4
//                              rmm_dbct.cpp:892 (41)
//         004842e9     INC        this
//         004842ea     MOV        dword ptr [EBP + EBX*0x1],EDX
//         004842ee     MOV        EDX,dword ptr [ESI + 0x2c]
//         004842f1     MOV        EDX,dword ptr [EDI + EDX*0x1 + 0x24]
//         004842f5     MOV        dword ptr [EAX + 0x20e4],EDX
//                               LAB_004842fb                                                 XREF[3]:     0048424b(j), 00484265(j),
//                                                                                                         004842b4(j)
//         004842fb     MOV        EAX,dword ptr [ESP + land_tile_num]
//         004842ff     MOV        EDX,dword ptr [ESI + 0x28]
//         00484302     INC        EAX
//         00484303     ADD        EDI,0x2c
//         00484306     CMP        EAX,EDX
//         00484308     MOV        dword ptr [ESP + land_tile_num],EAX
//         0048430c     JL         LAB_0048423f
//                               LAB_00484312                                                 XREF[1]:     00484239(j)
//                              rmm_dbct.cpp:897 (14)
//         00484312     POP        EDI
//         00484313     POP        ESI
//         00484314     MOV        dword ptr [EBX + 0x2708],this
//         0048431a     POP        EBP
//         0048431b     POP        EBX
//         0048431c     ADD        ESP,0xc
//         0048431f     RET
    return;
}

void RGE_RMM_Database_Controller::add_object_module() {
    /* TODO: Stub */
//                              void __thiscall add_object_module(RGE_RMM_Database_Controller * this)
//              void              <VOID>         <RETURN>
//              RGE_RMM_Databa    ECX:4 (auto)   this
//              undefined4        Stack[-0x4]:4  local_4                   XREF[3]:     004843ff(W), 00484448(R), 00484459(W)
//              long              Stack[-0x8]:4  index1
//                               ?add_object_module@RGE_RMM_Database_Controller@@MAEXXZ       XREF[2]:     add_object_module:00487fa9(c),
//                               RGE_RMM_Database_Controller::add_object_module                            00571e94(*)
//                              rmm_dbct.cpp:901 (7)
//         00484320     PUSH       this
//         00484321     PUSH       EBX
//         00484322     PUSH       EBP
//         00484323     MOV        EBP,this
//         00484325     PUSH       ESI
//         00484326     PUSH       EDI
//                              rmm_dbct.cpp:911 (50)
//         00484327     XOR        EDI,EDI
//         00484329     MOV        EAX,dword ptr [EBP + 0x34]
//         0048432c     MOV        this,dword ptr [EBP + 0x4f58]
//         00484332     LEA        EAX,[EAX + EAX*0x8]
//         00484335     LEA        EDX,[this->_padding_ + EAX*0x8]
//         00484338     MOV        this,0x1
//         0048433d     MOV        EAX,dword ptr [EDX + 0x38]
//         00484340     MOV        dword ptr [EBP + 0x399c],EAX
//         00484346     MOV        EAX,dword ptr [EDX + 0x38]
//         00484349     TEST       EAX,EAX
//         0048434b     JLE        LAB_004843e3
//         00484351     XOR        ESI,ESI
//         00484353     LEA        EAX,[EBP + 0x2710]
//                               LAB_00484359                                                 XREF[1]:     004843dd(j)
//                              rmm_dbct.cpp:913 (16)
//         00484359     MOV        EBX,dword ptr [EDX + 0x3c]
//         0048435c     INC        EDI
//         0048435d     ADD        EAX,0x30
//         00484360     MOV        EBX,dword ptr [ESI + EBX*0x1]
//         00484363     ADD        ESI,0x2c
//         00484366     MOV        dword ptr [EAX + -0x34],EBX
//                              rmm_dbct.cpp:914 (10)
//         00484369     MOV        EBX,dword ptr [EDX + 0x3c]
//         0048436c     MOV        EBX,dword ptr [ESI + EBX*0x1 + -0x28]
//         00484370     MOV        dword ptr [EAX + -0x30],EBX
//                              rmm_dbct.cpp:915 (10)
//         00484373     MOV        EBX,dword ptr [EDX + 0x3c]
//         00484376     MOV        BL,byte ptr [ESI + EBX*0x1 + -0x24]
//         0048437a     MOV        byte ptr [EAX + -0x2c],BL
//                              rmm_dbct.cpp:916 (10)
//         0048437d     MOV        EBX,dword ptr [EDX + 0x3c]
//         00484380     MOV        BL,byte ptr [ESI + EBX*0x1 + -0x23]
//         00484384     MOV        byte ptr [EAX + -0x2b],BL
//                              rmm_dbct.cpp:917 (10)
//         00484387     MOV        EBX,dword ptr [EDX + 0x3c]
//         0048438a     MOV        EBX,dword ptr [ESI + EBX*0x1 + -0x20]
//         0048438e     MOV        dword ptr [EAX + -0x28],EBX
//                              rmm_dbct.cpp:918 (10)
//         00484391     MOV        EBX,dword ptr [EDX + 0x3c]
//         00484394     MOV        EBX,dword ptr [ESI + EBX*0x1 + -0x1c]
//         00484398     MOV        dword ptr [EAX + -0x24],EBX
//                              rmm_dbct.cpp:919 (10)
//         0048439b     MOV        EBX,dword ptr [EDX + 0x3c]
//         0048439e     MOV        EBX,dword ptr [ESI + EBX*0x1 + -0x18]
//         004843a2     MOV        dword ptr [EAX + -0x20],EBX
//                              rmm_dbct.cpp:920 (10)
//         004843a5     MOV        EBX,dword ptr [EDX + 0x3c]
//         004843a8     MOV        EBX,dword ptr [ESI + EBX*0x1 + -0x10]
//         004843ac     MOV        dword ptr [EAX + -0x18],EBX
//                              rmm_dbct.cpp:921 (10)
//         004843af     MOV        EBX,dword ptr [EDX + 0x3c]
//         004843b2     MOV        EBX,dword ptr [ESI + EBX*0x1 + -0xc]
//         004843b6     MOV        dword ptr [EAX + -0x14],EBX
//                              rmm_dbct.cpp:922 (10)
//         004843b9     MOV        EBX,dword ptr [EDX + 0x3c]
//         004843bc     MOV        EBX,dword ptr [ESI + EBX*0x1 + -0x8]
//         004843c0     MOV        dword ptr [EAX + -0x10],EBX
//                              rmm_dbct.cpp:923 (10)
//         004843c3     MOV        EBX,dword ptr [EDX + 0x3c]
//         004843c6     MOV        EBX,dword ptr [ESI + EBX*0x1 + -0x4]
//         004843ca     MOV        dword ptr [EAX + -0xc],EBX
//                              rmm_dbct.cpp:924 (10)
//         004843cd     MOV        EBX,dword ptr [EDX + 0x3c]
//         004843d0     MOV        EBX,dword ptr [ESI + EBX*0x1 + -0x14]
//         004843d4     MOV        dword ptr [EAX + -0x1c],EBX
//                              rmm_dbct.cpp:925 (12)
//         004843d7     MOV        dword ptr [EAX + -0x8],this
//         004843da     CMP        EDI,dword ptr [EDX + 0x38]
//         004843dd     JL         LAB_00484359
//                               LAB_004843e3                                                 XREF[1]:     0048434b(j)
//                              rmm_dbct.cpp:928 (6)
//         004843e3     MOV        EAX,dword ptr [EBP + 0x1458]
//                              rmm_dbct.cpp:930 (8)
//         004843e9     XOR        EBX,EBX
//         004843eb     MOV        dword ptr [EBP + 0x3fd0],EAX
//                              rmm_dbct.cpp:931 (10)
//         004843f1     MOV        EDI,dword ptr [EDX + 0x2c]
//         004843f4     XOR        ESI,ESI
//         004843f6     CMP        byte ptr [EDI + 0x1d],BL
//         004843f9     JZ         LAB_004843fd
//                              rmm_dbct.cpp:932 (2)
//         004843fb     MOV        ESI,this
//                               LAB_004843fd                                                 XREF[1]:     004843f9(j)
//                              rmm_dbct.cpp:933 (17)
//         004843fd     CMP        EAX,EBX
//         004843ff     MOV        dword ptr [ESP + local_4],EBX
//         00484403     JLE        LAB_0048445f
//         00484405     LEA        EAX,[EBP + 0x39a4]
//         0048440b     LEA        EDI,[EBP + 0x48]
//                               LAB_0048440e                                                 XREF[1]:     0048445d(j)
//                              rmm_dbct.cpp:935 (6)
//         0048440e     MOV        this,dword ptr [EDI + -0x4]
//         00484411     MOV        dword ptr [EAX + -0x4],this
//                              rmm_dbct.cpp:936 (4)
//         00484414     MOV        this,dword ptr [EDI]
//         00484416     MOV        dword ptr [EAX],this
//                              rmm_dbct.cpp:937 (3)
//         00484418     MOV        this,dword ptr [EDX + 0x2c]
//                              rmm_dbct.cpp:940 (13)
//         0048441b     TEST       ESI,ESI
//         0048441d     MOV        this,dword ptr [EBX + this->_padding_*0x1]
//         00484420     MOV        dword ptr [EAX + 0x4],this
//         00484423     MOV        dword ptr [EAX + 0x8],ESI
//         00484426     JLE        LAB_00484434
//                              rmm_dbct.cpp:943 (8)
//         00484428     MOV        this,dword ptr [EBP + 0x38]
//         0048442b     INC        ESI
//         0048442c     CMP        ESI,this
//         0048442e     JLE        LAB_00484432
//                              rmm_dbct.cpp:944 (2)
//         00484430     XOR        ESI,ESI
//                               LAB_00484432                                                 XREF[1]:     0048442e(j)
//                              rmm_dbct.cpp:947 (4)
//         00484432     TEST       ESI,ESI
//                               LAB_00484434                                                 XREF[1]:     00484426(j)
//         00484434     JNZ        LAB_00484448
//                              rmm_dbct.cpp:950 (13)
//         00484436     MOV        this,dword ptr [EDX + 0x2c]
//         00484439     ADD        EBX,0x2c
//         0048443c     CMP        byte ptr [EBX + this->_padding_*0x1 + 0x1d],0x0
//         00484441     JZ         LAB_00484448
//                              rmm_dbct.cpp:951 (5)
//         00484443     MOV        ESI,0x1
//                               LAB_00484448                                                 XREF[2]:     00484434(j), 00484441(j)
//                              rmm_dbct.cpp:933 (23)
//         00484448     MOV        this,dword ptr [ESP + local_4]
//         0048444c     ADD        EDI,0x34
//         0048444f     INC        this
//         00484450     ADD        EAX,0x10
//         00484453     CMP        this,dword ptr [EBP + 0x1458]
//         00484459     MOV        dword ptr [ESP + local_4],this
//         0048445d     JL         LAB_0048440e
//                               LAB_0048445f                                                 XREF[1]:     00484403(j)
//                              rmm_dbct.cpp:955 (6)
//         0048445f     POP        EDI
//         00484460     POP        ESI
//         00484461     POP        EBP
//         00484462     POP        EBX
//         00484463     POP        this
//         00484464     RET
//         00484465     ??         90h
//         00484466     NOP
//         00484467     NOP
//         00484468     NOP
//         00484469     NOP
//         0048446a     NOP
//         0048446b     NOP
//         0048446c     NOP
//         0048446d     NOP
//         0048446e     NOP
//         0048446f     NOP
    return;
}

void RGE_RMM_Database_Controller::add_elevation_module() {
    /* TODO: Stub */
//                              void __thiscall add_elevation_module(RGE_RMM_Database_Controller * t
//              void              <VOID>         <RETURN>
//              RGE_RMM_Databa    ECX:4 (auto)   this
//              undefined4        Stack[-0x4]:4  local_4                   XREF[3]:     004845ca(W), 0048468d(R), 0048469a(W)
//              long              Stack[-0x8]:4  index                     XREF[3]:     004845ee(W), 00484639(R), 00484641(W)
//              long              Stack[-0xc]:4  index2
//                               ?add_elevation_module@RGE_RMM_Database_Controller@@MAEXXZ    XREF[2]:     add_elevation_module:00488706(c),
//                               RGE_RMM_Database_Controller::add_elevation_module                         00571e98(*)
//                              rmm_dbct.cpp:962 (3)
//         00484470     SUB        ESP,0x8
//                              rmm_dbct.cpp:963 (16)
//         00484473     MOV        EAX,dword ptr [ECX + this->map_type]
//         00484476     MOV        EDX,dword ptr [ECX + this+0x4f58]
//         0048447c     PUSH       EBX
//         0048447d     PUSH       EBP
//         0048447e     LEA        EAX,[EAX + EAX*0x8]
//         00484481     PUSH       ESI
//         00484482     PUSH       EDI
//                              rmm_dbct.cpp:972 (17)
//         00484483     MOV        EBX,0x1
//         00484488     LEA        ESI,[EDX + EAX*0x8 + 0x4]
//         0048448c     MOV        EDX,dword ptr [ECX + this->_padding_]
//         0048448f     MOV        EAX,0x51eb851f
//                              rmm_dbct.cpp:974 (64)
//         00484494     XOR        EBP,EBP
//         00484496     IMUL       EDX,dword ptr [ESI + 0x1c]
//         0048449a     IMUL       EDX,dword ptr [ECX + this->_padding_]
//         0048449e     IMUL       EDX
//         004844a0     SAR        EDX,0x5
//         004844a3     MOV        EAX,EDX
//         004844a5     MOV        dword ptr [ECX + this+0x491c],0x4
//         004844af     SHR        EAX,0x1f
//         004844b2     ADD        EDX,EAX
//         004844b4     MOV        EAX,0x51eb851f
//         004844b9     MOV        EDI,EDX
//         004844bb     MOV        dword ptr [ECX + this+0x3fd8],EBX
//         004844c1     MOV        dword ptr [ECX + this+0x3fdc],0xa
//         004844cb     MOV        dword ptr [ECX + this+0x3fe8],EBP
//         004844d1     LEA        EDX,[EDI + EDI*0x4]
//                              rmm_dbct.cpp:975 (15)
//         004844d4     MOV        dword ptr [ECX + this+0x3fe4],EBP
//         004844da     SHL        EDX,0x1
//         004844dc     IMUL       EDX
//         004844de     SAR        EDX,0x5
//         004844e1     MOV        EAX,EDX
//                              rmm_dbct.cpp:976 (15)
//         004844e3     MOV        dword ptr [ECX + this+0x3fe0],0x2
//         004844ed     SHR        EAX,0x1f
//         004844f0     ADD        EDX,EAX
//                              rmm_dbct.cpp:978 (25)
//         004844f2     MOV        EAX,0x51eb851f
//         004844f7     MOV        dword ptr [ECX + this->elevation_info.elevatio
//         004844fd     LEA        EDX,[EDI*0x8 + 0x0]
//         00484504     IMUL       EDX
//         00484506     SAR        EDX,0x5
//         00484509     MOV        EAX,EDX
//                              rmm_dbct.cpp:979 (15)
//         0048450b     MOV        dword ptr [ECX + this+0x3ff0],0x2
//         00484515     SHR        EAX,0x1f
//         00484518     ADD        EDX,EAX
//                              rmm_dbct.cpp:985 (38)
//         0048451a     MOV        EAX,0x51eb851f
//         0048451f     MOV        dword ptr [ECX + this+0x3fec],EDX
//         00484525     LEA        EDX,[EDI + EDI*0x2]
//         00484528     SHL        EDX,0x1
//         0048452a     IMUL       EDX
//         0048452c     SAR        EDX,0x5
//         0048452f     MOV        EAX,EDX
//         00484531     MOV        dword ptr [ECX + this+0x3ff4],0x8
//         0048453b     SHR        EAX,0x1f
//         0048453e     ADD        EDX,EAX
//                              rmm_dbct.cpp:993 (32)
//         00484540     MOV        EAX,0x51eb851f
//         00484545     SHL        EDI,0x2
//         00484548     MOV        dword ptr [ECX + this+0x4004],EDX
//         0048454e     IMUL       EDI
//         00484550     SAR        EDX,0x5
//         00484553     MOV        EAX,EDX
//         00484555     MOV        dword ptr [ECX + this+0x4000],EBP
//         0048455b     SHR        EAX,0x1f
//         0048455e     ADD        EDX,EAX
//                              rmm_dbct.cpp:994 (71)
//         00484560     MOV        EAX,0x4
//         00484565     MOV        dword ptr [ECX + this+0x3ffc],EBX
//         0048456b     MOV        dword ptr [ECX + this+0x3ff8],EBX
//         00484571     MOV        dword ptr [ECX + this+0x4008],0x3
//         0048457b     MOV        dword ptr [ECX + this+0x400c],0x6
//         00484585     MOV        dword ptr [ECX + this+0x4018],EBP
//         0048458b     MOV        dword ptr [ECX + this+0x4014],0x2
//         00484595     MOV        dword ptr [ECX + this+0x4010],EBX
//         0048459b     MOV        dword ptr [ECX + this+0x401c],EDX
//         004845a1     MOV        dword ptr [ECX + this+0x4020],EAX
//                              rmm_dbct.cpp:995 (6)
//         004845a7     MOV        dword ptr [ECX + this+0x4024],EAX
//                              rmm_dbct.cpp:996 (6)
//         004845ad     MOV        dword ptr [ECX + this+0x4030],EBP
//                              rmm_dbct.cpp:997 (10)
//         004845b3     MOV        dword ptr [ECX + this+0x402c],0x3
//                              rmm_dbct.cpp:998 (6)
//         004845bd     MOV        dword ptr [ECX + this+0x4028],EBX
//                              rmm_dbct.cpp:1001 (17)
//         004845c3     MOV        EAX,dword ptr [ESI + 0x24]
//         004845c6     XOR        EDX,EDX
//         004845c8     CMP        EAX,EBP
//         004845ca     MOV        dword ptr [ESP + local_4],EBP
//         004845ce     JLE        LAB_004846a4
//                               LAB_004845d4                                                 XREF[1]:     0048469e(j)
//                              rmm_dbct.cpp:1002 (16)
//         004845d4     MOV        EAX,dword ptr [ESI + 0x28]
//         004845d7     ADD        EAX,EBP
//         004845d9     MOV        EDI,dword ptr [EAX + 0x20]
//         004845dc     TEST       EDI,EDI
//         004845de     JL         LAB_0048468d
//                              rmm_dbct.cpp:1004 (7)
//         004845e4     MOV        BL,byte ptr [EAX + 0x1d]
//         004845e7     TEST       BL,BL
//         004845e9     JZ         LAB_00484649
//                              rmm_dbct.cpp:1006 (19)
//         004845eb     MOV        EAX,dword ptr [ECX + this->number_of_players]
//         004845ee     MOV        dword ptr [ESP + index],0x0
//         004845f6     TEST       EAX,EAX
//         004845f8     JLE        LAB_0048468d
//                              rmm_dbct.cpp:1026 (73)
//         004845fe     LEA        EDI,[EDX + EDX*0x2]
//         00484601     MOV        EAX,EDX
//         00484603     SHL        EAX,0x4
//         00484606     LEA        EDI,[EDX + EDI*0x4]
//         00484609     LEA        EAX,[EAX + this->_padding_*0x1 + 0x4924]
//         00484610     LEA        EDI,[ECX + EDI*0x4 + this+0x48]
//                               LAB_00484614                                                 XREF[1]:     00484645(j)
//         00484614     MOV        EBX,dword ptr [EDI + -0x4]
//         00484617     INC        EDX
//         00484618     MOV        dword ptr [EAX + -0x4],EBX
//         0048461b     MOV        EBX,dword ptr [EDI]
//         0048461d     MOV        dword ptr [EAX],EBX
//         0048461f     MOV        EBX,dword ptr [ESI + 0x28]
//         00484622     ADD        EDI,0x34
//         00484625     ADD        EAX,0x10
//         00484628     MOV        EBX,dword ptr [EBP + EBX*0x1 + 0x20]
//         0048462c     MOV        dword ptr [EAX + -0xc],EBX
//         0048462f     MOV        EBX,dword ptr [ESI + 0x28]
//         00484632     MOV        EBX,dword ptr [EBP + EBX*0x1 + 0x24]
//         00484636     MOV        dword ptr [EAX + -0x8],EBX
//         00484639     MOV        EBX,dword ptr [ESP + index]
//         0048463d     INC        EBX
//         0048463e     CMP        EBX,dword ptr [ECX + this->number_of_players]
//         00484641     MOV        dword ptr [ESP + index],EBX
//         00484645     JL         LAB_00484614
//                              rmm_dbct.cpp:1015 (2)
//         00484647     JMP        LAB_0048468d
//                               LAB_00484649                                                 XREF[1]:     004845e9(j)
//                              rmm_dbct.cpp:1017 (25)
//         00484649     LEA        EAX,[EDX + EDX*0x2]
//         0048464c     LEA        EAX,[EDX + EAX*0x4]
//         0048464f     MOV        EBX,dword ptr [ECX + EAX*0x4 + this+0x44]
//         00484653     LEA        EDI,[this->_padding_ + EAX*0x4]
//         00484656     LEA        EAX,[EDX + 0x492]
//         0048465c     SHL        EAX,0x4
//         0048465f     MOV        dword ptr [EAX + this->_padding_*0x1],EBX
//                              rmm_dbct.cpp:1018 (10)
//         00484662     MOV        EDI,dword ptr [EDI + 0x48]
//         00484665     MOV        EAX,EDX
//         00484667     SHL        EAX,0x4
//         0048466a     ADD        EAX,this
//                              rmm_dbct.cpp:1021 (56)
//         0048466c     INC        EDX
//         0048466d     MOV        dword ptr [EAX + 0x4924],EDI
//         00484673     MOV        EDI,dword ptr [ESI + 0x28]
//         00484676     MOV        EDI,dword ptr [EBP + EDI*0x1 + 0x20]
//         0048467a     MOV        dword ptr [EAX + 0x4928],EDI
//         00484680     MOV        EDI,dword ptr [ESI + 0x28]
//         00484683     MOV        EDI,dword ptr [EBP + EDI*0x1 + 0x24]
//         00484687     MOV        dword ptr [EAX + 0x492c],EDI
//                               LAB_0048468d                                                 XREF[3]:     004845de(j), 004845f8(j),
//                                                                                                         00484647(j)
//         0048468d     MOV        EAX,dword ptr [ESP + local_4]
//         00484691     MOV        EDI,dword ptr [ESI + 0x24]
//         00484694     INC        EAX
//         00484695     ADD        EBP,0x2c
//         00484698     CMP        EAX,EDI
//         0048469a     MOV        dword ptr [ESP + local_4],EAX
//         0048469e     JL         LAB_004845d4
//                               LAB_004846a4                                                 XREF[1]:     004845ce(j)
//                              rmm_dbct.cpp:1026 (14)
//         004846a4     POP        EDI
//         004846a5     POP        ESI
//         004846a6     POP        EBP
//         004846a7     MOV        dword ptr [ECX + this+0x4f50],EDX
//         004846ad     POP        EBX
//         004846ae     ADD        ESP,0x8
//         004846b1     RET
//         004846b2     ??         90h
//         004846b3     NOP
//         004846b4     NOP
//         004846b5     NOP
//         004846b6     NOP
//         004846b7     NOP
//         004846b8     NOP
//         004846b9     NOP
//         004846ba     NOP
//         004846bb     NOP
//         004846bc     NOP
//         004846bd     NOP
//         004846be     NOP
//         004846bf     NOP
    return;
}

