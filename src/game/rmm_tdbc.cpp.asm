#include "common.h"
#include "rmm_tdbc.h"

TRIBE_RMM_Database_Controller::TRIBE_RMM_Database_Controller(char* param_1, char* param_2, char* param_3, char* param_4) {
    /* TODO: Stub */
    //                              undefined __thiscall TRIBE_RMM_Database_Controller(TRIBE_RMM_Databas
    //              undefined         <UNASSIGNED>   <RETURN>
    //              TRIBE_RMM_Data    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     004876f0(R)  
    //                               ??0TRIBE_RMM_Database_Controller@@QAE@H@Z                    XREF[1]:     data_load_random_map:0050f83d(c)  
    //                               TRIBE_RMM_Database_Controller::TRIBE_RMM_Database_Controller
    //                              rmm_tdbc.cpp:52 (19)
    //         004876f0     MOV        EAX,dword ptr [ESP + param_1]
    //         004876f4     PUSH       ESI
    //         004876f5     MOV        ESI,this
    //         004876f7     PUSH       EAX
    //         004876f8     CALL       RGE_RMM_Database_Controller::RGE_RMM_Database_   undefined RGE_RMM_Database_Controller(RGE_RMM
    //         004876fd     MOV        dword ptr [ESI],TRIBE_RMM_Database_Controller:   = 00488870
    //                              rmm_tdbc.cpp:53 (6)
    //         00487703     MOV        EAX,ESI
    //         00487705     POP        ESI
    //         00487706     RET        0x4
    //         00487709     ??         90h
    //         0048770a     NOP
    //         0048770b     NOP
    //         0048770c     NOP
    //         0048770d     NOP
    //         0048770e     NOP
    //         0048770f     NOP
    //                              * public: virtual unsigned char __thiscall TRIBE_RMM_Database_Controller::init(class RGE_Map *,class... *
    //                              uchar __thiscall init(TRIBE_RMM_Database_Controller * this, RGE_Map 
    //              uchar             AL:1           <RETURN>
    //              TRIBE_RMM_Data    ECX:4 (auto)   this
    //              RGE_Map *         Stack[0x4]:4   param_1                   XREF[1]:     00487765(R)  
    //              RGE_Game_World    Stack[0x8]:4   param_2                   XREF[1]:     0048775d(R)  
    //              uchar             Stack[0xc]:1   param_3                   XREF[1]:     00487744(R)  
    //              long              Stack[0x10]:4  param_4                   XREF[1]:     0048773d(R)  
    //              uchar             Stack[0x14]:1  param_5                   XREF[2]:     0048774e(W), 00487755(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     004878bf(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     004878ee(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     0048786f(W)  
    //              RGE_Cliffs_Info   Stack[-0x4d0   cliff_info                XREF[3,13]:  004877ff(R), 00487803(R), 004878b9(W), 0048783d(W), 
    //                                                                                     004878a4(R), 004878da(*), 00487846(W), 0048786b(W), 
    //                                                                                     0048789c(R), 00487867(W), 0048784a(W), 0048784e(W), 
    //                                                                                     00487888(W), 00487878(*), 0048788e(*), 00487893(W)  
    //              long              Stack[-0x4d4   base_cliff_size
    //                               ?init@TRIBE_RMM_Database_Controller@@UAEEPAVRGE_Map@@PAVRGE  XREF[1]:     00571f14(*)  
    //                               TRIBE_RMM_Database_Controller::init
    //                              rmm_tdbc.cpp:57 (30)
    //         00487710     MOV        EAX,FS:[0x0]
    //         00487716     PUSH       -0x1
    //         00487718     PUSH       FUN_0055e6be
    //         0048771d     PUSH       EAX
    //         0048771e     MOV        dword ptr FS:[0x0],ESP
    //         00487725     SUB        ESP,0x4c4
    //         0048772b     PUSH       EBX
    //         0048772c     MOV        EBX,this
    //                              rmm_tdbc.cpp:60 (15)
    //         0048772e     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         00487734     PUSH       ESI
    //         00487735     PUSH       EDI
    //         00487736     CALL       TRIBE_Game::randomizePositions                   int randomizePositions(TRIBE_Game * this)
    //         0048773b     NEG        EAX
    //                              rmm_tdbc.cpp:62 (57)
    //         0048773d     MOV        this,dword ptr [ESP + param_4]
    //         00487744     MOV        EDX,dword ptr [ESP + param_3]
    //         0048774b     SBB        EAX,EAX
    //         0048774d     INC        EAX
    //         0048774e     MOV        byte ptr [ESP + param_5],AL
    //         00487755     MOV        EAX,dword ptr [ESP + param_5]
    //         0048775c     PUSH       EAX
    //         0048775d     MOV        EAX,dword ptr [ESP + param_2]
    //         00487764     PUSH       this
    //         00487765     MOV        this,dword ptr [ESP + param_1]
    //         0048776c     PUSH       EDX
    //         0048776d     PUSH       EAX
    //         0048776e     PUSH       this
    //         0048776f     MOV        this,EBX
    //         00487771     CALL       RGE_RMM_Database_Controller::init                uchar init(RGE_RMM_Database_Controller * this
    //                              rmm_tdbc.cpp:64 (26)
    //         00487776     PUSH       0x40
    //         00487778     PUSH       s_C:\msdev\work\age1_x1\rmm_tdbc.c               = "C:\\msdev\\work\\age1_x1\\rmm_tdbc.cpp"
    //         0048777d     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
    //         00487782     ADD        ESP,0x8
    //         00487785     CMP        EAX,0x1fff
    //         0048778a     JLE        LAB_004878ee
    //                              rmm_tdbc.cpp:69 (8)
    //         00487790     MOV        EAX,dword ptr [EBX + 0x14]
    //         00487793     CMP        EAX,0x48
    //         00487796     JG         LAB_004877a4
    //                              rmm_tdbc.cpp:71 (5)
    //         00487798     MOV        EAX,0x3
    //                              rmm_tdbc.cpp:72 (5)
    //         0048779d     MOV        this,0xa
    //                              rmm_tdbc.cpp:74 (7)
    //         004877a2     JMP        LAB_00487807
    //                               LAB_004877a4                                                 XREF[1]:     00487796(j)  
    //         004877a4     CMP        EAX,0x60
    //         004877a7     JG         LAB_004877b5
    //                              rmm_tdbc.cpp:76 (5)
    //         004877a9     MOV        EAX,0x4
    //                              rmm_tdbc.cpp:77 (5)
    //         004877ae     MOV        this,0xc
    //                              rmm_tdbc.cpp:79 (7)
    //         004877b3     JMP        LAB_00487807
    //                               LAB_004877b5                                                 XREF[1]:     004877a7(j)  
    //         004877b5     CMP        EAX,0x78
    //         004877b8     JG         LAB_004877c6
    //                              rmm_tdbc.cpp:81 (5)
    //         004877ba     MOV        EAX,0x6
    //                              rmm_tdbc.cpp:82 (5)
    //         004877bf     MOV        this,0xe
    //                              rmm_tdbc.cpp:84 (9)
    //         004877c4     JMP        LAB_00487807
    //                               LAB_004877c6                                                 XREF[1]:     004877b8(j)  
    //         004877c6     CMP        EAX,0x90
    //         004877cb     JG         LAB_004877d9
    //                              rmm_tdbc.cpp:86 (5)
    //         004877cd     MOV        EAX,0x8
    //                              rmm_tdbc.cpp:87 (5)
    //         004877d2     MOV        this,0x10
    //                              rmm_tdbc.cpp:89 (9)
    //         004877d7     JMP        LAB_00487807
    //                               LAB_004877d9                                                 XREF[1]:     004877cb(j)  
    //         004877d9     CMP        EAX,0xc8
    //         004877de     JG         LAB_004877ec
    //                              rmm_tdbc.cpp:91 (5)
    //         004877e0     MOV        EAX,0x12
    //                              rmm_tdbc.cpp:92 (5)
    //         004877e5     MOV        this,0x14
    //                              rmm_tdbc.cpp:94 (9)
    //         004877ea     JMP        LAB_00487807
    //                               LAB_004877ec                                                 XREF[1]:     004877de(j)  
    //         004877ec     CMP        EAX,0xfa
    //         004877f1     JG         LAB_004877ff
    //                              rmm_tdbc.cpp:96 (5)
    //         004877f3     MOV        EAX,0x1c
    //                              rmm_tdbc.cpp:97 (15)
    //         004877f8     MOV        this,0x14
    //         004877fd     JMP        LAB_00487807
    //                               LAB_004877ff                                                 XREF[1]:     004877f1(j)  
    //         004877ff     MOV        EAX,dword ptr [ESP + cliff_info.number_of_clif
    //         00487803     MOV        this,dword ptr [ESP + cliff_info.number_of_cli
    //                               LAB_00487807                                                 XREF[6]:     004877a2(j), 004877b3(j), 
    //                                                                                                         004877c4(j), 004877d7(j), 
    //                                                                                                         004877ea(j), 004877fd(j)  
    //                              rmm_tdbc.cpp:100 (20)
    //         00487807     MOV        EDX,dword ptr [EBX + 0x34]
    //         0048780a     MOV        ESI,0x2
    //         0048780f     CMP        EDX,0x8
    //         00487812     JA         switchD_00487814::caseD_3
    //                               switchD_00487814::switchD
    //         00487814     JMP        dword ptr [EDX*0x4 + switchD_00487814::switchd   = 0048781b
    //                               switchD_00487814::caseD_0                                    XREF[2]:     00487814(j), 0048790c(*)  
    //                              rmm_tdbc.cpp:103 (2)
    //         0048781b     XOR        EAX,EAX
    //                              rmm_tdbc.cpp:104 (2)
    //         0048781d     XOR        this,this
    //                              rmm_tdbc.cpp:105 (2)
    //         0048781f     JMP        switchD_00487814::caseD_3
    //                               switchD_00487814::caseD_1                                    XREF[2]:     00487814(j), 00487910(*)  
    //                              rmm_tdbc.cpp:107 (3)
    //         00487821     SUB        EAX,0x5
    //                              rmm_tdbc.cpp:108 (3)
    //         00487824     SUB        this,0x6
    //                              rmm_tdbc.cpp:109 (2)
    //         00487827     JMP        switchD_00487814::caseD_3
    //                               switchD_00487814::caseD_2                                    XREF[2]:     00487814(j), 00487914(*)  
    //                              rmm_tdbc.cpp:111 (3)
    //         00487829     SUB        EAX,0x3
    //                              rmm_tdbc.cpp:112 (2)
    //         0048782c     SUB        this,ESI
    //                              rmm_tdbc.cpp:113 (2)
    //         0048782e     JMP        switchD_00487814::caseD_3
    //                               switchD_00487814::caseD_6                                    XREF[4]:     00487814(j), 00487920(*), 
    //                               switchD_00487814::caseD_8                                                 00487924(*), 0048792c(*)  
    //                               switchD_00487814::caseD_5
    //                              rmm_tdbc.cpp:121 (3)
    //         00487830     SUB        this,0x4
    //                               switchD_00487814::caseD_4                                    XREF[8]:     00487812(j), 00487814(j), 
    //                               switchD_00487814::caseD_7                                                 0048781f(j), 00487827(j), 
    //                               switchD_00487814::caseD_3                                                 0048782e(j), 00487918(*), 
    //                                                                                                         0048791c(*), 00487928(*)  
    //                              rmm_tdbc.cpp:125 (5)
    //         00487833     CMP        this,0x3
    //         00487836     JGE        LAB_0048783d
    //                              rmm_tdbc.cpp:126 (5)
    //         00487838     MOV        this,0x3
    //                               LAB_0048783d                                                 XREF[1]:     00487836(j)  
    //                              rmm_tdbc.cpp:131 (4)
    //         0048783d     MOV        dword ptr [ESP + cliff_info.number_of_cliffs_v
    //                              rmm_tdbc.cpp:132 (3)
    //         00487841     LEA        EAX,[this->field0_0x0 + -0x3]
    //                              rmm_tdbc.cpp:133 (16)
    //         00487844     TEST       EAX,EAX
    //         00487846     MOV        dword ptr [ESP + cliff_info.average_cliff_size
    //         0048784a     MOV        dword ptr [ESP + cliff_info.cliff_to_cliff_spa
    //         0048784e     MOV        dword ptr [ESP + cliff_info.hot_spots[0].x],ESI
    //         00487852     JG         LAB_00487858
    //                              rmm_tdbc.cpp:134 (2)
    //         00487854     XOR        EAX,EAX
    //                              rmm_tdbc.cpp:135 (2)
    //         00487856     JMP        LAB_0048785d
    //                               LAB_00487858                                                 XREF[1]:     00487852(j)  
    //                              rmm_tdbc.cpp:136 (5)
    //         00487858     CDQ
    //         00487859     SUB        EAX,EDX
    //         0048785b     SAR        EAX,0x1
    //                               LAB_0048785d                                                 XREF[1]:     00487856(j)  
    //                              rmm_tdbc.cpp:139 (8)
    //         0048785d     MOV        EDX,dword ptr [EBX + 0x2708]
    //         00487863     SUB        this,EAX
    //                              rmm_tdbc.cpp:140 (29)
    //         00487865     TEST       EDX,EDX
    //         00487867     MOV        dword ptr [ESP + cliff_info.cliff_terrain_spac
    //         0048786b     MOV        dword ptr [ESP + cliff_info.cliff_size_varianc
    //         0048786f     MOV        dword ptr [ESP + local_10],EDX
    //         00487876     JLE        LAB_0048789c
    //         00487878     LEA        this=>cliff_info+0x20,[ESP + 0x2c]
    //         0048787c     LEA        EAX,[EBX + 0x20dc]
    //                               LAB_00487882                                                 XREF[1]:     0048789a(j)  
    //                              rmm_tdbc.cpp:142 (9)
    //         00487882     MOV        ESI,dword ptr [EAX + -0x4]
    //         00487885     ADD        EAX,0x10
    //         00487888     MOV        dword ptr [ECX + cliff_info+0x1c],ESI
    //                              rmm_tdbc.cpp:143 (5)
    //         0048788b     MOV        ESI,dword ptr [EAX + -0x10]
    //         0048788e     MOV        dword ptr [this->field0_0x0]=>cliff_info+0x20,
    //                              rmm_tdbc.cpp:144 (12)
    //         00487890     MOV        ESI,dword ptr [EAX + -0xc]
    //         00487893     MOV        dword ptr [ECX + cliff_info+0x24],ESI
    //         00487896     ADD        this,0xc
    //         00487899     DEC        EDX
    //         0048789a     JNZ        LAB_00487882
    //                               LAB_0048789c                                                 XREF[1]:     00487876(j)  
    //                              rmm_tdbc.cpp:147 (16)
    //         0048789c     MOV        EAX,dword ptr [ESP + cliff_info.cliff_size_var
    //         004878a0     TEST       EAX,EAX
    //         004878a2     JLE        LAB_004878ee
    //         004878a4     MOV        EAX,dword ptr [ESP + cliff_info.number_of_clif
    //         004878a8     TEST       EAX,EAX
    //         004878aa     JLE        LAB_004878ee
    //                              rmm_tdbc.cpp:148 (66)
    //         004878ac     PUSH       0x508
    //         004878b1     CALL       operator_new                                     void * operator_new(uint param_1)
    //         004878b6     ADD        ESP,0x4
    //         004878b9     MOV        dword ptr [ESP + cliff_info.number_of_cliffs],
    //         004878bd     TEST       EAX,EAX
    //         004878bf     MOV        dword ptr [ESP + local_4],0x0
    //         004878ca     JZ         LAB_004878ee
    //         004878cc     MOV        EDX,dword ptr [EBX + 0xc]
    //         004878cf     SUB        ESP,0x4c0
    //         004878d5     MOV        this,0x130
    //         004878da     LEA        ESI=>cliff_info.number_of_cliffs_variance,[ESP
    //         004878e1     MOV        EDI,ESP
    //         004878e3     PUSH       EBX
    //         004878e4     MOVSD.REP  ES:EDI,ESI
    //         004878e6     PUSH       EDX
    //         004878e7     MOV        this,EAX
    //         004878e9     CALL       RGE_RMM_Cliffs_Generator::RGE_RMM_Cliffs_Gener   undefined RGE_RMM_Cliffs_Generator(RGE_RMM_Cl
    //                               LAB_004878ee                                                 XREF[4]:     0048778a(j), 004878a2(j), 
    //                                                                                                         004878aa(j), 004878ca(j)  
    //                              rmm_tdbc.cpp:152 (66)
    //         004878ee     MOV        this,dword ptr [ESP + local_c]
    //         004878f5     POP        EDI
    //         004878f6     POP        ESI
    //         004878f7     MOV        AL,0x1
    //         004878f9     MOV        dword ptr FS:[0x0],this
    //         00487900     POP        EBX
    //         00487901     ADD        ESP,0x4d0
    //         00487907     RET        0x14
    //                              *                                               FUNCTION                                                *
    //                              undefined FUN_0048790a()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0048790a
    //         0048790a     MOV        EDI,EDI
    //                              Symbol Ref: No symbol: NONAME
    //                               switchD_00487814::switchdataD_0048790c                       XREF[1]:     init:00487814(*)  
    //         0048790c     addr       switchD_00487814::caseD_0
    //         00487910     addr       switchD_00487814::caseD_1
    //         00487914     addr       switchD_00487814::caseD_2
    //         00487918     addr       switchD_00487814::caseD_3
    //         0048791c     addr       switchD_00487814::caseD_3
    //         00487920     addr       switchD_00487814::caseD_5
    //         00487924     addr       switchD_00487814::caseD_5
    //         00487928     addr       switchD_00487814::caseD_3
    //         0048792c     addr       switchD_00487814::caseD_5
}

TRIBE_RMM_Database_Controller::TRIBE_RMM_Database_Controller(int param_1) {
    /* TODO: Stub */
    //                              undefined __thiscall TRIBE_RMM_Database_Controller(TRIBE_RMM_Databas
    //              undefined         <UNASSIGNED>   <RETURN>
    //              TRIBE_RMM_Data    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     004876f0(R)  
    //                               ??0TRIBE_RMM_Database_Controller@@QAE@H@Z                    XREF[1]:     data_load_random_map:0050f83d(c)  
    //                               TRIBE_RMM_Database_Controller::TRIBE_RMM_Database_Controller
    //                              rmm_tdbc.cpp:52 (19)
    //         004876f0     MOV        EAX,dword ptr [ESP + param_1]
    //         004876f4     PUSH       ESI
    //         004876f5     MOV        ESI,this
    //         004876f7     PUSH       EAX
    //         004876f8     CALL       RGE_RMM_Database_Controller::RGE_RMM_Database_   undefined RGE_RMM_Database_Controller(RGE_RMM
    //         004876fd     MOV        dword ptr [ESI],TRIBE_RMM_Database_Controller:   = 00488870
    //                              rmm_tdbc.cpp:53 (6)
    //         00487703     MOV        EAX,ESI
    //         00487705     POP        ESI
    //         00487706     RET        0x4
    //         00487709     ??         90h
    //         0048770a     NOP
    //         0048770b     NOP
    //         0048770c     NOP
    //         0048770d     NOP
    //         0048770e     NOP
    //         0048770f     NOP
    //                              * public: virtual unsigned char __thiscall TRIBE_RMM_Database_Controller::init(class RGE_Map *,class... *
    //                              uchar __thiscall init(TRIBE_RMM_Database_Controller * this, RGE_Map 
    //              uchar             AL:1           <RETURN>
    //              TRIBE_RMM_Data    ECX:4 (auto)   this
    //              RGE_Map *         Stack[0x4]:4   param_1                   XREF[1]:     00487765(R)  
    //              RGE_Game_World    Stack[0x8]:4   param_2                   XREF[1]:     0048775d(R)  
    //              uchar             Stack[0xc]:1   param_3                   XREF[1]:     00487744(R)  
    //              long              Stack[0x10]:4  param_4                   XREF[1]:     0048773d(R)  
    //              uchar             Stack[0x14]:1  param_5                   XREF[2]:     0048774e(W), 00487755(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     004878bf(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     004878ee(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     0048786f(W)  
    //              RGE_Cliffs_Info   Stack[-0x4d0   cliff_info                XREF[3,13]:  004877ff(R), 00487803(R), 004878b9(W), 0048783d(W), 
    //                                                                                     004878a4(R), 004878da(*), 00487846(W), 0048786b(W), 
    //                                                                                     0048789c(R), 00487867(W), 0048784a(W), 0048784e(W), 
    //                                                                                     00487888(W), 00487878(*), 0048788e(*), 00487893(W)  
    //              long              Stack[-0x4d4   base_cliff_size
    //                               ?init@TRIBE_RMM_Database_Controller@@UAEEPAVRGE_Map@@PAVRGE  XREF[1]:     00571f14(*)  
    //                               TRIBE_RMM_Database_Controller::init
    //                              rmm_tdbc.cpp:57 (30)
    //         00487710     MOV        EAX,FS:[0x0]
    //         00487716     PUSH       -0x1
    //         00487718     PUSH       FUN_0055e6be
    //         0048771d     PUSH       EAX
    //         0048771e     MOV        dword ptr FS:[0x0],ESP
    //         00487725     SUB        ESP,0x4c4
    //         0048772b     PUSH       EBX
    //         0048772c     MOV        EBX,this
    //                              rmm_tdbc.cpp:60 (15)
    //         0048772e     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         00487734     PUSH       ESI
    //         00487735     PUSH       EDI
    //         00487736     CALL       TRIBE_Game::randomizePositions                   int randomizePositions(TRIBE_Game * this)
    //         0048773b     NEG        EAX
    //                              rmm_tdbc.cpp:62 (57)
    //         0048773d     MOV        this,dword ptr [ESP + param_4]
    //         00487744     MOV        EDX,dword ptr [ESP + param_3]
    //         0048774b     SBB        EAX,EAX
    //         0048774d     INC        EAX
    //         0048774e     MOV        byte ptr [ESP + param_5],AL
    //         00487755     MOV        EAX,dword ptr [ESP + param_5]
    //         0048775c     PUSH       EAX
    //         0048775d     MOV        EAX,dword ptr [ESP + param_2]
    //         00487764     PUSH       this
    //         00487765     MOV        this,dword ptr [ESP + param_1]
    //         0048776c     PUSH       EDX
    //         0048776d     PUSH       EAX
    //         0048776e     PUSH       this
    //         0048776f     MOV        this,EBX
    //         00487771     CALL       RGE_RMM_Database_Controller::init                uchar init(RGE_RMM_Database_Controller * this
    //                              rmm_tdbc.cpp:64 (26)
    //         00487776     PUSH       0x40
    //         00487778     PUSH       s_C:\msdev\work\age1_x1\rmm_tdbc.c               = "C:\\msdev\\work\\age1_x1\\rmm_tdbc.cpp"
    //         0048777d     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
    //         00487782     ADD        ESP,0x8
    //         00487785     CMP        EAX,0x1fff
    //         0048778a     JLE        LAB_004878ee
    //                              rmm_tdbc.cpp:69 (8)
    //         00487790     MOV        EAX,dword ptr [EBX + 0x14]
    //         00487793     CMP        EAX,0x48
    //         00487796     JG         LAB_004877a4
    //                              rmm_tdbc.cpp:71 (5)
    //         00487798     MOV        EAX,0x3
    //                              rmm_tdbc.cpp:72 (5)
    //         0048779d     MOV        this,0xa
    //                              rmm_tdbc.cpp:74 (7)
    //         004877a2     JMP        LAB_00487807
    //                               LAB_004877a4                                                 XREF[1]:     00487796(j)  
    //         004877a4     CMP        EAX,0x60
    //         004877a7     JG         LAB_004877b5
    //                              rmm_tdbc.cpp:76 (5)
    //         004877a9     MOV        EAX,0x4
    //                              rmm_tdbc.cpp:77 (5)
    //         004877ae     MOV        this,0xc
    //                              rmm_tdbc.cpp:79 (7)
    //         004877b3     JMP        LAB_00487807
    //                               LAB_004877b5                                                 XREF[1]:     004877a7(j)  
    //         004877b5     CMP        EAX,0x78
    //         004877b8     JG         LAB_004877c6
    //                              rmm_tdbc.cpp:81 (5)
    //         004877ba     MOV        EAX,0x6
    //                              rmm_tdbc.cpp:82 (5)
    //         004877bf     MOV        this,0xe
    //                              rmm_tdbc.cpp:84 (9)
    //         004877c4     JMP        LAB_00487807
    //                               LAB_004877c6                                                 XREF[1]:     004877b8(j)  
    //         004877c6     CMP        EAX,0x90
    //         004877cb     JG         LAB_004877d9
    //                              rmm_tdbc.cpp:86 (5)
    //         004877cd     MOV        EAX,0x8
    //                              rmm_tdbc.cpp:87 (5)
    //         004877d2     MOV        this,0x10
    //                              rmm_tdbc.cpp:89 (9)
    //         004877d7     JMP        LAB_00487807
    //                               LAB_004877d9                                                 XREF[1]:     004877cb(j)  
    //         004877d9     CMP        EAX,0xc8
    //         004877de     JG         LAB_004877ec
    //                              rmm_tdbc.cpp:91 (5)
    //         004877e0     MOV        EAX,0x12
    //                              rmm_tdbc.cpp:92 (5)
    //         004877e5     MOV        this,0x14
    //                              rmm_tdbc.cpp:94 (9)
    //         004877ea     JMP        LAB_00487807
    //                               LAB_004877ec                                                 XREF[1]:     004877de(j)  
    //         004877ec     CMP        EAX,0xfa
    //         004877f1     JG         LAB_004877ff
    //                              rmm_tdbc.cpp:96 (5)
    //         004877f3     MOV        EAX,0x1c
    //                              rmm_tdbc.cpp:97 (15)
    //         004877f8     MOV        this,0x14
    //         004877fd     JMP        LAB_00487807
    //                               LAB_004877ff                                                 XREF[1]:     004877f1(j)  
    //         004877ff     MOV        EAX,dword ptr [ESP + cliff_info.number_of_clif
    //         00487803     MOV        this,dword ptr [ESP + cliff_info.number_of_cli
    //                               LAB_00487807                                                 XREF[6]:     004877a2(j), 004877b3(j), 
    //                                                                                                         004877c4(j), 004877d7(j), 
    //                                                                                                         004877ea(j), 004877fd(j)  
    //                              rmm_tdbc.cpp:100 (20)
    //         00487807     MOV        EDX,dword ptr [EBX + 0x34]
    //         0048780a     MOV        ESI,0x2
    //         0048780f     CMP        EDX,0x8
    //         00487812     JA         switchD_00487814::caseD_3
    //                               switchD_00487814::switchD
    //         00487814     JMP        dword ptr [EDX*0x4 + switchD_00487814::switchd   = 0048781b
    //                               switchD_00487814::caseD_0                                    XREF[2]:     00487814(j), 0048790c(*)  
    //                              rmm_tdbc.cpp:103 (2)
    //         0048781b     XOR        EAX,EAX
    //                              rmm_tdbc.cpp:104 (2)
    //         0048781d     XOR        this,this
    //                              rmm_tdbc.cpp:105 (2)
    //         0048781f     JMP        switchD_00487814::caseD_3
    //                               switchD_00487814::caseD_1                                    XREF[2]:     00487814(j), 00487910(*)  
    //                              rmm_tdbc.cpp:107 (3)
    //         00487821     SUB        EAX,0x5
    //                              rmm_tdbc.cpp:108 (3)
    //         00487824     SUB        this,0x6
    //                              rmm_tdbc.cpp:109 (2)
    //         00487827     JMP        switchD_00487814::caseD_3
    //                               switchD_00487814::caseD_2                                    XREF[2]:     00487814(j), 00487914(*)  
    //                              rmm_tdbc.cpp:111 (3)
    //         00487829     SUB        EAX,0x3
    //                              rmm_tdbc.cpp:112 (2)
    //         0048782c     SUB        this,ESI
    //                              rmm_tdbc.cpp:113 (2)
    //         0048782e     JMP        switchD_00487814::caseD_3
    //                               switchD_00487814::caseD_6                                    XREF[4]:     00487814(j), 00487920(*), 
    //                               switchD_00487814::caseD_8                                                 00487924(*), 0048792c(*)  
    //                               switchD_00487814::caseD_5
    //                              rmm_tdbc.cpp:121 (3)
    //         00487830     SUB        this,0x4
    //                               switchD_00487814::caseD_4                                    XREF[8]:     00487812(j), 00487814(j), 
    //                               switchD_00487814::caseD_7                                                 0048781f(j), 00487827(j), 
    //                               switchD_00487814::caseD_3                                                 0048782e(j), 00487918(*), 
    //                                                                                                         0048791c(*), 00487928(*)  
    //                              rmm_tdbc.cpp:125 (5)
    //         00487833     CMP        this,0x3
    //         00487836     JGE        LAB_0048783d
    //                              rmm_tdbc.cpp:126 (5)
    //         00487838     MOV        this,0x3
    //                               LAB_0048783d                                                 XREF[1]:     00487836(j)  
    //                              rmm_tdbc.cpp:131 (4)
    //         0048783d     MOV        dword ptr [ESP + cliff_info.number_of_cliffs_v
    //                              rmm_tdbc.cpp:132 (3)
    //         00487841     LEA        EAX,[this->field0_0x0 + -0x3]
    //                              rmm_tdbc.cpp:133 (16)
    //         00487844     TEST       EAX,EAX
    //         00487846     MOV        dword ptr [ESP + cliff_info.average_cliff_size
    //         0048784a     MOV        dword ptr [ESP + cliff_info.cliff_to_cliff_spa
    //         0048784e     MOV        dword ptr [ESP + cliff_info.hot_spots[0].x],ESI
    //         00487852     JG         LAB_00487858
    //                              rmm_tdbc.cpp:134 (2)
    //         00487854     XOR        EAX,EAX
    //                              rmm_tdbc.cpp:135 (2)
    //         00487856     JMP        LAB_0048785d
    //                               LAB_00487858                                                 XREF[1]:     00487852(j)  
    //                              rmm_tdbc.cpp:136 (5)
    //         00487858     CDQ
    //         00487859     SUB        EAX,EDX
    //         0048785b     SAR        EAX,0x1
    //                               LAB_0048785d                                                 XREF[1]:     00487856(j)  
    //                              rmm_tdbc.cpp:139 (8)
    //         0048785d     MOV        EDX,dword ptr [EBX + 0x2708]
    //         00487863     SUB        this,EAX
    //                              rmm_tdbc.cpp:140 (29)
    //         00487865     TEST       EDX,EDX
    //         00487867     MOV        dword ptr [ESP + cliff_info.cliff_terrain_spac
    //         0048786b     MOV        dword ptr [ESP + cliff_info.cliff_size_varianc
    //         0048786f     MOV        dword ptr [ESP + local_10],EDX
    //         00487876     JLE        LAB_0048789c
    //         00487878     LEA        this=>cliff_info+0x20,[ESP + 0x2c]
    //         0048787c     LEA        EAX,[EBX + 0x20dc]
    //                               LAB_00487882                                                 XREF[1]:     0048789a(j)  
    //                              rmm_tdbc.cpp:142 (9)
    //         00487882     MOV        ESI,dword ptr [EAX + -0x4]
    //         00487885     ADD        EAX,0x10
    //         00487888     MOV        dword ptr [ECX + cliff_info+0x1c],ESI
    //                              rmm_tdbc.cpp:143 (5)
    //         0048788b     MOV        ESI,dword ptr [EAX + -0x10]
    //         0048788e     MOV        dword ptr [this->field0_0x0]=>cliff_info+0x20,
    //                              rmm_tdbc.cpp:144 (12)
    //         00487890     MOV        ESI,dword ptr [EAX + -0xc]
    //         00487893     MOV        dword ptr [ECX + cliff_info+0x24],ESI
    //         00487896     ADD        this,0xc
    //         00487899     DEC        EDX
    //         0048789a     JNZ        LAB_00487882
    //                               LAB_0048789c                                                 XREF[1]:     00487876(j)  
    //                              rmm_tdbc.cpp:147 (16)
    //         0048789c     MOV        EAX,dword ptr [ESP + cliff_info.cliff_size_var
    //         004878a0     TEST       EAX,EAX
    //         004878a2     JLE        LAB_004878ee
    //         004878a4     MOV        EAX,dword ptr [ESP + cliff_info.number_of_clif
    //         004878a8     TEST       EAX,EAX
    //         004878aa     JLE        LAB_004878ee
    //                              rmm_tdbc.cpp:148 (66)
    //         004878ac     PUSH       0x508
    //         004878b1     CALL       operator_new                                     void * operator_new(uint param_1)
    //         004878b6     ADD        ESP,0x4
    //         004878b9     MOV        dword ptr [ESP + cliff_info.number_of_cliffs],
    //         004878bd     TEST       EAX,EAX
    //         004878bf     MOV        dword ptr [ESP + local_4],0x0
    //         004878ca     JZ         LAB_004878ee
    //         004878cc     MOV        EDX,dword ptr [EBX + 0xc]
    //         004878cf     SUB        ESP,0x4c0
    //         004878d5     MOV        this,0x130
    //         004878da     LEA        ESI=>cliff_info.number_of_cliffs_variance,[ESP
    //         004878e1     MOV        EDI,ESP
    //         004878e3     PUSH       EBX
    //         004878e4     MOVSD.REP  ES:EDI,ESI
    //         004878e6     PUSH       EDX
    //         004878e7     MOV        this,EAX
    //         004878e9     CALL       RGE_RMM_Cliffs_Generator::RGE_RMM_Cliffs_Gener   undefined RGE_RMM_Cliffs_Generator(RGE_RMM_Cl
    //                               LAB_004878ee                                                 XREF[4]:     0048778a(j), 004878a2(j), 
    //                                                                                                         004878aa(j), 004878ca(j)  
    //                              rmm_tdbc.cpp:152 (66)
    //         004878ee     MOV        this,dword ptr [ESP + local_c]
    //         004878f5     POP        EDI
    //         004878f6     POP        ESI
    //         004878f7     MOV        AL,0x1
    //         004878f9     MOV        dword ptr FS:[0x0],this
    //         00487900     POP        EBX
    //         00487901     ADD        ESP,0x4d0
    //         00487907     RET        0x14
    //                              *                                               FUNCTION                                                *
    //                              undefined FUN_0048790a()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0048790a
    //         0048790a     MOV        EDI,EDI
    //                              Symbol Ref: No symbol: NONAME
    //                               switchD_00487814::switchdataD_0048790c                       XREF[1]:     init:00487814(*)  
    //         0048790c     addr       switchD_00487814::caseD_0
    //         00487910     addr       switchD_00487814::caseD_1
    //         00487914     addr       switchD_00487814::caseD_2
    //         00487918     addr       switchD_00487814::caseD_3
    //         0048791c     addr       switchD_00487814::caseD_3
    //         00487920     addr       switchD_00487814::caseD_5
    //         00487924     addr       switchD_00487814::caseD_5
    //         00487928     addr       switchD_00487814::caseD_3
    //         0048792c     addr       switchD_00487814::caseD_5
}

uchar TRIBE_RMM_Database_Controller::de_init() {
    /* TODO: Stub */
    //                              uchar __thiscall de_init(TRIBE_RMM_Database_Controller * this)
    //              uchar             AL:1           <RETURN>
    //              TRIBE_RMM_Data    ECX:4 (auto)   this
    //                               ?de_init@TRIBE_RMM_Database_Controller@@UAEEXZ               XREF[1]:     00571f18(*)  
    //                               TRIBE_RMM_Database_Controller::de_init
    //                              rmm_tdbc.cpp:156 (5)
    //         00487930     CALL       RGE_RMM_Database_Controller::de_init             uchar de_init(RGE_RMM_Database_Controller * t
    //                              rmm_tdbc.cpp:159 (2)
    //         00487935     MOV        AL,0x1
    //                              rmm_tdbc.cpp:160 (1)
    //         00487937     RET
    //         00487938     ??         90h
    //         00487939     NOP
    //         0048793a     NOP
    //         0048793b     NOP
    //         0048793c     NOP
    //         0048793d     NOP
    //         0048793e     NOP
    //         0048793f     NOP
    return 0;
}

void TRIBE_RMM_Database_Controller::add_land_module(uchar param_1) {
    /* TODO: Stub */
    //                              void __thiscall add_land_module(TRIBE_RMM_Database_Controller * this
    //              void              <VOID>         <RETURN>
    //              TRIBE_RMM_Data    ECX:4 (auto)   this
    //              uchar             Stack[0x4]:1   param_1                   XREF[3]:     0048797d(R), 00487d61(W), 00487d65(R)  
    //                               ?add_land_module@TRIBE_RMM_Database_Controller@@MAEXE@Z      XREF[1]:     00571f04(*)  
    //                               TRIBE_RMM_Database_Controller::add_land_module
    //                              rmm_tdbc.cpp:165 (6)
    //         00487940     PUSH       EBX
    //         00487941     PUSH       EBP
    //         00487942     PUSH       ESI
    //         00487943     MOV        ESI,this
    //         00487945     PUSH       EDI
    //                              rmm_tdbc.cpp:169 (9)
    //         00487946     MOV        EAX,dword ptr [ESI + 0x34]
    //         00487949     MOV        EDX,dword ptr [ESI + 0x4f58]
    //                              rmm_tdbc.cpp:170 (29)
    //         0048794f     CMP        EAX,0x5
    //         00487952     LEA        this,[EAX + EAX*0x8]
    //         00487955     MOV        EDI,dword ptr [EDX + this->field0_0x0*0x8 + 0x
    //         00487959     LEA        this,[EDX + this->field0_0x0*0x8 + 0x18]
    //         0048795d     JZ         LAB_00487964
    //         0048795f     CMP        EAX,0x8
    //         00487962     JNZ        LAB_0048797d
    //                               LAB_00487964                                                 XREF[1]:     0048795d(j)  
    //         00487964     MOV        EAX,dword ptr [ESI + 0x14]
    //         00487967     CMP        EAX,0x64
    //         0048796a     JGE        LAB_0048797d
    //                              rmm_tdbc.cpp:172 (17)
    //         0048796c     XOR        EDX,EDX
    //         0048796e     CMP        EAX,0x50
    //         00487971     SETGE      DL
    //         00487974     DEC        EDX
    //         00487975     AND        EDX,0xfffffffb
    //         00487978     ADD        EDX,0x19
    //         0048797b     MOV        dword ptr [this->field0_0x0],EDX
    //                               LAB_0048797d                                                 XREF[2]:     00487962(j), 0048796a(j)  
    //                              rmm_tdbc.cpp:179 (12)
    //         0048797d     MOV        EAX,dword ptr [ESP + param_1]
    //         00487981     MOV        this,ESI
    //         00487983     PUSH       EAX
    //         00487984     CALL       RGE_RMM_Database_Controller::add_land_module     void add_land_module(RGE_RMM_Database_Control
    //                              rmm_tdbc.cpp:180 (16)
    //         00487989     MOV        EAX,dword ptr [ESI + 0x34]
    //         0048798c     MOV        EDX,dword ptr [ESI + 0x4f58]
    //         00487992     LEA        this,[EAX + EAX*0x8]
    //         00487995     MOV        dword ptr [EDX + this->field0_0x0*0x8 + 0x18],
    //                              rmm_tdbc.cpp:183 (15)
    //         00487999     MOV        EAX,dword ptr [ESI + 0x34]
    //         0048799c     OR         EDI,0xffffffff
    //         0048799f     CMP        EAX,0x5
    //         004879a2     JGE        LAB_00487aac
    //                              rmm_tdbc.cpp:185 (25)
    //         004879a8     PUSH       0xb9
    //         004879ad     PUSH       s_C:\msdev\work\age1_x1\rmm_tdbc.c               = "C:\\msdev\\work\\age1_x1\\rmm_tdbc.cpp"
    //         004879b2     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
    //         004879b7     ADD        ESP,0x8
    //         004879ba     CMP        EAX,0x3fff
    //         004879bf     JGE        LAB_004879e6
    //                              rmm_tdbc.cpp:188 (18)
    //         004879c1     MOV        this,dword ptr [ESI + 0x1458]
    //         004879c7     XOR        EAX,EAX
    //         004879c9     TEST       this,this
    //         004879cb     MOV        dword ptr [ESI + 0x1460],EDI
    //         004879d1     JLE        LAB_004879e6
    //                              rmm_tdbc.cpp:187 (3)
    //         004879d3     LEA        this,[ESI + 0x5c]
    //                               LAB_004879d6                                                 XREF[1]:     004879e4(j)  
    //                              rmm_tdbc.cpp:189 (16)
    //         004879d6     MOV        dword ptr [this->field0_0x0],EDI
    //         004879d8     MOV        EDX,dword ptr [ESI + 0x1458]
    //         004879de     INC        EAX
    //         004879df     ADD        this,0x34
    //         004879e2     CMP        EAX,EDX
    //         004879e4     JL         LAB_004879d6
    //                               LAB_004879e6                                                 XREF[2]:     004879bf(j), 004879d1(j)  
    //                              rmm_tdbc.cpp:192 (25)
    //         004879e6     PUSH       0xc0
    //         004879eb     PUSH       s_C:\msdev\work\age1_x1\rmm_tdbc.c               = "C:\\msdev\\work\\age1_x1\\rmm_tdbc.cpp"
    //         004879f0     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
    //         004879f5     ADD        ESP,0x8
    //         004879f8     CMP        EAX,0x3fff
    //         004879fd     JGE        LAB_00487a24
    //                              rmm_tdbc.cpp:195 (18)
    //         004879ff     MOV        this,dword ptr [ESI + 0x1458]
    //         00487a05     XOR        EAX,EAX
    //         00487a07     TEST       this,this
    //         00487a09     MOV        dword ptr [ESI + 0x1464],EDI
    //         00487a0f     JLE        LAB_00487a24
    //                              rmm_tdbc.cpp:194 (3)
    //         00487a11     LEA        this,[ESI + 0x60]
    //                               LAB_00487a14                                                 XREF[1]:     00487a22(j)  
    //                              rmm_tdbc.cpp:196 (16)
    //         00487a14     MOV        dword ptr [this->field0_0x0],EDI
    //         00487a16     MOV        EDX,dword ptr [ESI + 0x1458]
    //         00487a1c     INC        EAX
    //         00487a1d     ADD        this,0x34
    //         00487a20     CMP        EAX,EDX
    //         00487a22     JL         LAB_00487a14
    //                               LAB_00487a24                                                 XREF[2]:     004879fd(j), 00487a0f(j)  
    //                              rmm_tdbc.cpp:199 (25)
    //         00487a24     PUSH       0xc7
    //         00487a29     PUSH       s_C:\msdev\work\age1_x1\rmm_tdbc.c               = "C:\\msdev\\work\\age1_x1\\rmm_tdbc.cpp"
    //         00487a2e     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
    //         00487a33     ADD        ESP,0x8
    //         00487a36     CMP        EAX,0x3fff
    //         00487a3b     JGE        LAB_00487a68
    //                              rmm_tdbc.cpp:201 (3)
    //         00487a3d     MOV        EAX,dword ptr [ESI + 0x14]
    //                              rmm_tdbc.cpp:202 (18)
    //         00487a40     MOV        this,dword ptr [ESI + 0x1458]
    //         00487a46     MOV        dword ptr [ESI + 0x1468],EAX
    //         00487a4c     XOR        EAX,EAX
    //         00487a4e     TEST       this,this
    //         00487a50     JLE        LAB_00487a68
    //                              rmm_tdbc.cpp:201 (3)
    //         00487a52     LEA        this,[ESI + 0x64]
    //                               LAB_00487a55                                                 XREF[1]:     00487a66(j)  
    //                              rmm_tdbc.cpp:203 (19)
    //         00487a55     MOV        EDX,dword ptr [ESI + 0x14]
    //         00487a58     INC        EAX
    //         00487a59     MOV        dword ptr [this->field0_0x0],EDX
    //         00487a5b     MOV        EDX,dword ptr [ESI + 0x1458]
    //         00487a61     ADD        this,0x34
    //         00487a64     CMP        EAX,EDX
    //         00487a66     JL         LAB_00487a55
    //                               LAB_00487a68                                                 XREF[2]:     00487a3b(j), 00487a50(j)  
    //                              rmm_tdbc.cpp:206 (25)
    //         00487a68     PUSH       0xce
    //         00487a6d     PUSH       s_C:\msdev\work\age1_x1\rmm_tdbc.c               = "C:\\msdev\\work\\age1_x1\\rmm_tdbc.cpp"
    //         00487a72     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
    //         00487a77     ADD        ESP,0x8
    //         00487a7a     CMP        EAX,0x3fff
    //         00487a7f     JGE        LAB_00487aac
    //                              rmm_tdbc.cpp:208 (3)
    //         00487a81     MOV        EAX,dword ptr [ESI + 0x18]
    //                              rmm_tdbc.cpp:209 (18)
    //         00487a84     MOV        this,dword ptr [ESI + 0x1458]
    //         00487a8a     MOV        dword ptr [ESI + 0x146c],EAX
    //         00487a90     XOR        EAX,EAX
    //         00487a92     TEST       this,this
    //         00487a94     JLE        LAB_00487aac
    //                              rmm_tdbc.cpp:208 (3)
    //         00487a96     LEA        this,[ESI + 0x68]
    //                               LAB_00487a99                                                 XREF[1]:     00487aaa(j)  
    //                              rmm_tdbc.cpp:210 (19)
    //         00487a99     MOV        EDX,dword ptr [ESI + 0x18]
    //         00487a9c     INC        EAX
    //         00487a9d     MOV        dword ptr [this->field0_0x0],EDX
    //         00487a9f     MOV        EDX,dword ptr [ESI + 0x1458]
    //         00487aa5     ADD        this,0x34
    //         00487aa8     CMP        EAX,EDX
    //         00487aaa     JL         LAB_00487a99
    //                               LAB_00487aac                                                 XREF[3]:     004879a2(j), 00487a7f(j), 
    //                                                                                                         00487a94(j)  
    //                              rmm_tdbc.cpp:214 (10)
    //         00487aac     CMP        dword ptr [ESI + 0x34],0x8
    //         00487ab0     JNZ        LAB_00487b39
    //                              rmm_tdbc.cpp:216 (25)
    //         00487ab6     PUSH       0xd8
    //         00487abb     PUSH       s_C:\msdev\work\age1_x1\rmm_tdbc.c               = "C:\\msdev\\work\\age1_x1\\rmm_tdbc.cpp"
    //         00487ac0     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
    //         00487ac5     ADD        ESP,0x8
    //         00487ac8     CMP        EAX,0x3fff
    //         00487acd     JGE        LAB_00487b05
    //                              rmm_tdbc.cpp:219 (3)
    //         00487acf     MOV        EAX,dword ptr [ESI + 0x14]
    //                              rmm_tdbc.cpp:220 (24)
    //         00487ad2     XOR        this,this
    //         00487ad4     MOV        dword ptr [ESI + 0x1468],EAX
    //         00487ada     MOV        EAX,dword ptr [ESI + 0x1458]
    //         00487ae0     TEST       EAX,EAX
    //         00487ae2     MOV        dword ptr [ESI + 0x1460],EDI
    //         00487ae8     JLE        LAB_00487b39
    //                              rmm_tdbc.cpp:218 (3)
    //         00487aea     LEA        EAX,[ESI + 0x64]
    //                               LAB_00487aed                                                 XREF[1]:     00487b01(j)  
    //                              rmm_tdbc.cpp:222 (3)
    //         00487aed     MOV        dword ptr [EAX + -0x8],EDI
    //                              rmm_tdbc.cpp:223 (19)
    //         00487af0     MOV        EDX,dword ptr [ESI + 0x14]
    //         00487af3     MOV        dword ptr [EAX],EDX
    //         00487af5     MOV        EDX,dword ptr [ESI + 0x1458]
    //         00487afb     INC        this
    //         00487afc     ADD        EAX,0x34
    //         00487aff     CMP        this,EDX
    //         00487b01     JL         LAB_00487aed
    //                              rmm_tdbc.cpp:226 (2)
    //         00487b03     JMP        LAB_00487b39
    //                               LAB_00487b05                                                 XREF[1]:     00487acd(j)  
    //                              rmm_tdbc.cpp:229 (3)
    //         00487b05     MOV        EAX,dword ptr [ESI + 0x18]
    //                              rmm_tdbc.cpp:230 (24)
    //         00487b08     XOR        this,this
    //         00487b0a     MOV        dword ptr [ESI + 0x146c],EAX
    //         00487b10     MOV        EAX,dword ptr [ESI + 0x1458]
    //         00487b16     TEST       EAX,EAX
    //         00487b18     MOV        dword ptr [ESI + 0x1464],EDI
    //         00487b1e     JLE        LAB_00487b39
    //                              rmm_tdbc.cpp:228 (3)
    //         00487b20     LEA        EAX,[ESI + 0x68]
    //                               LAB_00487b23                                                 XREF[1]:     00487b37(j)  
    //                              rmm_tdbc.cpp:232 (3)
    //         00487b23     MOV        dword ptr [EAX + -0x8],EDI
    //                              rmm_tdbc.cpp:233 (19)
    //         00487b26     MOV        EDX,dword ptr [ESI + 0x18]
    //         00487b29     MOV        dword ptr [EAX],EDX
    //         00487b2b     MOV        EDX,dword ptr [ESI + 0x1458]
    //         00487b31     INC        this
    //         00487b32     ADD        EAX,0x34
    //         00487b35     CMP        this,EDX
    //         00487b37     JL         LAB_00487b23
    //                               LAB_00487b39                                                 XREF[4]:     00487ab0(j), 00487ae8(j), 
    //                                                                                                         00487b03(j), 00487b1e(j)  
    //                              rmm_tdbc.cpp:239 (22)
    //         00487b39     MOV        EAX,dword ptr [ESI + 0x34]
    //         00487b3c     CMP        EAX,0x2
    //         00487b3f     JL         LAB_00487b46
    //         00487b41     CMP        EAX,0x6
    //         00487b44     JLE        LAB_00487b4f
    //                               LAB_00487b46                                                 XREF[1]:     00487b3f(j)  
    //         00487b46     CMP        EAX,0x8
    //         00487b49     JNZ        LAB_00487c90
    //                               LAB_00487b4f                                                 XREF[1]:     00487b44(j)  
    //                              rmm_tdbc.cpp:241 (29)
    //         00487b4f     PUSH       0xf1
    //         00487b54     PUSH       s_C:\msdev\work\age1_x1\rmm_tdbc.c               = "C:\\msdev\\work\\age1_x1\\rmm_tdbc.cpp"
    //         00487b59     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
    //         00487b5e     ADD        ESP,0x8
    //         00487b61     CMP        EAX,0x3fff
    //         00487b66     JGE        LAB_00487c3a
    //                              rmm_tdbc.cpp:247 (25)
    //         00487b6c     PUSH       0xf7
    //         00487b71     PUSH       s_C:\msdev\work\age1_x1\rmm_tdbc.c               = "C:\\msdev\\work\\age1_x1\\rmm_tdbc.cpp"
    //         00487b76     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
    //         00487b7b     ADD        ESP,0x8
    //         00487b7e     CMP        EAX,0x3fff
    //         00487b83     JGE        LAB_00487ba9
    //                              rmm_tdbc.cpp:248 (15)
    //         00487b85     MOV        this,dword ptr [ESI + 0x1458]
    //         00487b8b     XOR        EAX,EAX
    //         00487b8d     TEST       this,this
    //         00487b8f     JLE        LAB_00487bca
    //         00487b91     LEA        this,[ESI + 0x54]
    //                               LAB_00487b94                                                 XREF[1]:     00487ba5(j)  
    //                              rmm_tdbc.cpp:249 (19)
    //         00487b94     MOV        byte ptr [this->field0_0x0],0x0
    //         00487b97     MOV        EDX,dword ptr [ESI + 0x1458]
    //         00487b9d     ADD        EAX,0x2
    //         00487ba0     ADD        this,0x68
    //         00487ba3     CMP        EAX,EDX
    //         00487ba5     JL         LAB_00487b94
    //                              rmm_tdbc.cpp:250 (2)
    //         00487ba7     JMP        LAB_00487bca
    //                               LAB_00487ba9                                                 XREF[1]:     00487b83(j)  
    //                              rmm_tdbc.cpp:251 (15)
    //         00487ba9     MOV        this,dword ptr [ESI + 0x1458]
    //         00487baf     XOR        EAX,EAX
    //         00487bb1     TEST       this,this
    //         00487bb3     JLE        LAB_00487bca
    //         00487bb5     LEA        this,[ESI + 0x54]
    //                               LAB_00487bb8                                                 XREF[1]:     00487bc8(j)  
    //                              rmm_tdbc.cpp:252 (18)
    //         00487bb8     MOV        byte ptr [this->field0_0x0],AL
    //         00487bba     MOV        EDX,dword ptr [ESI + 0x1458]
    //         00487bc0     ADD        EAX,0x2
    //         00487bc3     ADD        this,0x68
    //         00487bc6     CMP        EAX,EDX
    //         00487bc8     JL         LAB_00487bb8
    //                               LAB_00487bca                                                 XREF[3]:     00487b8f(j), 00487ba7(j), 
    //                                                                                                         00487bb3(j)  
    //                              rmm_tdbc.cpp:255 (15)
    //         00487bca     PUSH       0xff
    //         00487bcf     PUSH       s_C:\msdev\work\age1_x1\rmm_tdbc.c               = "C:\\msdev\\work\\age1_x1\\rmm_tdbc.cpp"
    //         00487bd4     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
    //                              rmm_tdbc.cpp:256 (31)
    //         00487bd9     MOV        this,dword ptr [ESI + 0x1458]
    //         00487bdf     ADD        ESP,0x8
    //         00487be2     CMP        EAX,0x3fff
    //         00487be7     MOV        EAX,0x1
    //         00487bec     JGE        LAB_00487c14
    //         00487bee     CMP        this,EAX
    //         00487bf0     JLE        LAB_00487c31
    //         00487bf2     LEA        this,[ESI + 0x88]
    //                               LAB_00487bf8                                                 XREF[1]:     00487c09(j)  
    //                              rmm_tdbc.cpp:257 (19)
    //         00487bf8     MOV        byte ptr [this->field0_0x0],0x1
    //         00487bfb     MOV        EDX,dword ptr [ESI + 0x1458]
    //         00487c01     ADD        EAX,0x2
    //         00487c04     ADD        this,0x68
    //         00487c07     CMP        EAX,EDX
    //         00487c09     JL         LAB_00487bf8
    //                              rmm_tdbc.cpp:262 (7)
    //         00487c0b     MOV        this,ESI
    //         00487c0d     CALL       TRIBE_RMM_Database_Controller::add_shallows_mo   void add_shallows_module(TRIBE_RMM_Database_C
    //                              rmm_tdbc.cpp:264 (2)
    //         00487c12     JMP        LAB_00487c90
    //                               LAB_00487c14                                                 XREF[1]:     00487bec(j)  
    //                              rmm_tdbc.cpp:259 (11)
    //         00487c14     CMP        this,0x1
    //         00487c17     JLE        LAB_00487c31
    //         00487c19     LEA        this,[ESI + 0x88]
    //                               LAB_00487c1f                                                 XREF[1]:     00487c2f(j)  
    //                              rmm_tdbc.cpp:260 (18)
    //         00487c1f     MOV        byte ptr [this->field0_0x0],AL
    //         00487c21     MOV        EDX,dword ptr [ESI + 0x1458]
    //         00487c27     ADD        EAX,0x2
    //         00487c2a     ADD        this,0x68
    //         00487c2d     CMP        EAX,EDX
    //         00487c2f     JL         LAB_00487c1f
    //                               LAB_00487c31                                                 XREF[2]:     00487bf0(j), 00487c17(j)  
    //                              rmm_tdbc.cpp:262 (7)
    //         00487c31     MOV        this,ESI
    //         00487c33     CALL       TRIBE_RMM_Database_Controller::add_shallows_mo   void add_shallows_module(TRIBE_RMM_Database_C
    //                              rmm_tdbc.cpp:264 (2)
    //         00487c38     JMP        LAB_00487c90
    //                               LAB_00487c3a                                                 XREF[1]:     00487b66(j)  
    //                              rmm_tdbc.cpp:266 (8)
    //         00487c3a     MOV        EAX,dword ptr [ESI + 0x34]
    //         00487c3d     CMP        EAX,0x4
    //         00487c40     JNZ        LAB_00487c6b
    //                              rmm_tdbc.cpp:268 (12)
    //         00487c42     MOV        this,dword ptr [ESI + 0x1458]
    //         00487c48     XOR        EAX,EAX
    //         00487c4a     TEST       this,this
    //         00487c4c     JLE        LAB_00487c62
    //                              rmm_tdbc.cpp:312 (3)
    //         00487c4e     LEA        this,[ESI + 0x54]
    //                               LAB_00487c51                                                 XREF[1]:     00487c60(j)  
    //                              rmm_tdbc.cpp:269 (17)
    //         00487c51     MOV        byte ptr [this->field0_0x0],0x0
    //         00487c54     MOV        EDX,dword ptr [ESI + 0x1458]
    //         00487c5a     INC        EAX
    //         00487c5b     ADD        this,0x34
    //         00487c5e     CMP        EAX,EDX
    //         00487c60     JL         LAB_00487c51
    //                               LAB_00487c62                                                 XREF[1]:     00487c4c(j)  
    //                              rmm_tdbc.cpp:270 (7)
    //         00487c62     MOV        byte ptr [ESI + 0x145c],0x0
    //                              rmm_tdbc.cpp:272 (7)
    //         00487c69     JMP        LAB_00487c90
    //                               LAB_00487c6b                                                 XREF[1]:     00487c40(j)  
    //         00487c6b     CMP        EAX,0x5
    //         00487c6e     JL         LAB_00487c90
    //                              rmm_tdbc.cpp:274 (12)
    //         00487c70     MOV        this,dword ptr [ESI + 0x1458]
    //         00487c76     XOR        EAX,EAX
    //         00487c78     TEST       this,this
    //         00487c7a     JLE        LAB_00487c90
    //                              rmm_tdbc.cpp:312 (3)
    //         00487c7c     LEA        this,[ESI + 0x54]
    //                               LAB_00487c7f                                                 XREF[1]:     00487c8e(j)  
    //                              rmm_tdbc.cpp:275 (17)
    //         00487c7f     MOV        byte ptr [this->field0_0x0],0x0
    //         00487c82     MOV        EDX,dword ptr [ESI + 0x1458]
    //         00487c88     INC        EAX
    //         00487c89     ADD        this,0x34
    //         00487c8c     CMP        EAX,EDX
    //         00487c8e     JL         LAB_00487c7f
    //                               LAB_00487c90                                                 XREF[6]:     00487b49(j), 00487c12(j), 
    //                                                                                                         00487c38(j), 00487c69(j), 
    //                                                                                                         00487c6e(j), 00487c7a(j)  
    //                              rmm_tdbc.cpp:280 (17)
    //         00487c90     MOV        EAX,dword ptr [ESI + 0x34]
    //         00487c93     CMP        EAX,0x5
    //         00487c96     JZ         LAB_00487ca1
    //         00487c98     CMP        EAX,0x8
    //         00487c9b     JNZ        LAB_00487d9b
    //                               LAB_00487ca1                                                 XREF[1]:     00487c96(j)  
    //                              rmm_tdbc.cpp:283 (17)
    //         00487ca1     MOV        EAX,dword ptr [ESI + 0x14]
    //         00487ca4     MOV        EDX,0x14
    //         00487ca9     CMP        EAX,0x64
    //         00487cac     JGE        LAB_00487d52
    //                              rmm_tdbc.cpp:285 (2)
    //         00487cb2     XOR        EDX,EDX
    //                              rmm_tdbc.cpp:290 (29)
    //         00487cb4     MOV        this,dword ptr [ESI + 0x1460]
    //         00487cba     CMP        EAX,0x50
    //         00487cbd     SETGE      DL
    //         00487cc0     DEC        EDX
    //         00487cc1     AND        EDX,0xfffffffb
    //         00487cc4     ADD        EDX,0xf
    //         00487cc7     TEST       this,this
    //         00487cc9     JLE        LAB_00487cd1
    //         00487ccb     MOV        dword ptr [ESI + 0x1460],EDX
    //                               LAB_00487cd1                                                 XREF[1]:     00487cc9(j)  
    //                              rmm_tdbc.cpp:291 (16)
    //         00487cd1     MOV        this,dword ptr [ESI + 0x1464]
    //         00487cd7     TEST       this,this
    //         00487cd9     JLE        LAB_00487ce1
    //         00487cdb     MOV        dword ptr [ESI + 0x1464],EDX
    //                               LAB_00487ce1                                                 XREF[1]:     00487cd9(j)  
    //                              rmm_tdbc.cpp:292 (16)
    //         00487ce1     CMP        dword ptr [ESI + 0x1468],EAX
    //         00487ce7     JGE        LAB_00487cf1
    //         00487ce9     SUB        EAX,EDX
    //         00487ceb     MOV        dword ptr [ESI + 0x1468],EAX
    //                               LAB_00487cf1                                                 XREF[1]:     00487ce7(j)  
    //                              rmm_tdbc.cpp:293 (21)
    //         00487cf1     MOV        EAX,dword ptr [ESI + 0x18]
    //         00487cf4     MOV        this,dword ptr [ESI + 0x146c]
    //         00487cfa     CMP        this,EAX
    //         00487cfc     JGE        LAB_00487d06
    //         00487cfe     SUB        EAX,EDX
    //         00487d00     MOV        dword ptr [ESI + 0x146c],EAX
    //                               LAB_00487d06                                                 XREF[1]:     00487cfc(j)  
    //                              rmm_tdbc.cpp:294 (15)
    //         00487d06     MOV        EAX,dword ptr [ESI + 0x1458]
    //         00487d0c     XOR        EDI,EDI
    //         00487d0e     TEST       EAX,EAX
    //         00487d10     JLE        LAB_00487d52
    //         00487d12     LEA        EAX,[ESI + 0x60]
    //                               LAB_00487d15                                                 XREF[1]:     00487d50(j)  
    //                              rmm_tdbc.cpp:296 (10)
    //         00487d15     MOV        this,dword ptr [EAX + -0x4]
    //         00487d18     TEST       this,this
    //         00487d1a     JLE        LAB_00487d1f
    //         00487d1c     MOV        dword ptr [EAX + -0x4],EDX
    //                               LAB_00487d1f                                                 XREF[1]:     00487d1a(j)  
    //                              rmm_tdbc.cpp:297 (7)
    //         00487d1f     CMP        dword ptr [EAX],0x0
    //         00487d22     JLE        LAB_00487d26
    //         00487d24     MOV        dword ptr [EAX],EDX
    //                               LAB_00487d26                                                 XREF[1]:     00487d22(j)  
    //                              rmm_tdbc.cpp:298 (15)
    //         00487d26     MOV        this,dword ptr [ESI + 0x14]
    //         00487d29     MOV        EBX,dword ptr [EAX + 0x4]
    //         00487d2c     CMP        EBX,this
    //         00487d2e     JGE        LAB_00487d35
    //         00487d30     SUB        this,EDX
    //         00487d32     MOV        dword ptr [EAX + 0x4],this
    //                               LAB_00487d35                                                 XREF[1]:     00487d2e(j)  
    //                              rmm_tdbc.cpp:299 (29)
    //         00487d35     MOV        this,dword ptr [ESI + 0x18]
    //         00487d38     MOV        EBX,dword ptr [EAX + 0x8]
    //         00487d3b     CMP        EBX,this
    //         00487d3d     JGE        LAB_00487d44
    //         00487d3f     SUB        this,EDX
    //         00487d41     MOV        dword ptr [EAX + 0x8],this
    //                               LAB_00487d44                                                 XREF[1]:     00487d3d(j)  
    //         00487d44     MOV        this,dword ptr [ESI + 0x1458]
    //         00487d4a     INC        EDI
    //         00487d4b     ADD        EAX,0x34
    //         00487d4e     CMP        EDI,this
    //         00487d50     JL         LAB_00487d15
    //                               LAB_00487d52                                                 XREF[2]:     00487cac(j), 00487d10(j)  
    //                              rmm_tdbc.cpp:305 (34)
    //         00487d52     MOV        EAX,dword ptr [ESI + 0x14]
    //         00487d55     MOV        this,dword ptr [ESI + 0x18]
    //         00487d58     ADD        EDX,EDX
    //         00487d5a     SUB        EAX,EDX
    //         00487d5c     SUB        this,EDX
    //         00487d5e     IMUL       EAX,this
    //         00487d61     MOV        dword ptr [ESP + param_1],EAX
    //         00487d65     FILD       dword ptr [ESP + param_1]
    //         00487d69     FMUL       double ptr [DAT_00571f20]                        = 9Ah
    //         00487d6f     CALL       __ftol                                           undefined __ftol()
    //                              rmm_tdbc.cpp:307 (14)
    //         00487d74     MOV        this,dword ptr [ESI + 0x1458]
    //         00487d7a     XOR        EDI,EDI
    //         00487d7c     TEST       this,this
    //         00487d7e     MOV        EBP,EAX
    //         00487d80     JLE        LAB_00487d9b
    //                              rmm_tdbc.cpp:303 (3)
    //         00487d82     LEA        EBX,[ESI + 0x3c]
    //                               LAB_00487d85                                                 XREF[1]:     00487d99(j)  
    //                              rmm_tdbc.cpp:308 (22)
    //         00487d85     MOV        EAX,EBP
    //         00487d87     ADD        EBX,0x34
    //         00487d8a     CDQ
    //         00487d8b     IDIV       this
    //         00487d8d     INC        EDI
    //         00487d8e     MOV        dword ptr [EBX + -0x34],EAX
    //         00487d91     MOV        this,dword ptr [ESI + 0x1458]
    //         00487d97     CMP        EDI,this
    //         00487d99     JL         LAB_00487d85
    //                               LAB_00487d9b                                                 XREF[2]:     00487c9b(j), 00487d80(j)  
    //                              rmm_tdbc.cpp:311 (39)
    //         00487d9b     PUSH       0x137
    //         00487da0     PUSH       s_C:\msdev\work\age1_x1\rmm_tdbc.c               = "C:\\msdev\\work\\age1_x1\\rmm_tdbc.cpp"
    //         00487da5     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
    //         00487daa     MOV        EDX,dword ptr [L]                                = 00000000
    //         00487db0     ADD        ESP,0x8
    //         00487db3     PUSH       EAX
    //         00487db4     PUSH       s_Random_Map_land_initilization,_r               = "Random Map land initilization, rand: %d"
    //         00487db9     PUSH       EDX
    //         00487dba     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
    //         00487dbf     ADD        ESP,0xc
    //                              rmm_tdbc.cpp:312 (7)
    //         00487dc2     POP        EDI
    //         00487dc3     POP        ESI
    //         00487dc4     POP        EBP
    //         00487dc5     POP        EBX
    //         00487dc6     RET        0x4
    //         00487dc9     ??         90h
    //         00487dca     NOP
    //         00487dcb     NOP
    //         00487dcc     NOP
    //         00487dcd     NOP
    //         00487dce     NOP
    //         00487dcf     NOP
    return;
}

void TRIBE_RMM_Database_Controller::add_terrain_module() {
    /* TODO: Stub */
    //                              void __thiscall add_terrain_module(TRIBE_RMM_Database_Controller * t
    //              void              <VOID>         <RETURN>
    //              TRIBE_RMM_Data    ECX:4 (auto)   this
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[5]:     00487e02(W), 00487e0b(R), 00487e24(W), 00487e35(R), 
    //                                                                                     00487e48(R)  
    //              long              Stack[-0x8]:4  land_tile_num
    //                               ?add_terrain_module@TRIBE_RMM_Database_Controller@@MAEXXZ    XREF[1]:     00571f08(*)  
    //                               TRIBE_RMM_Database_Controller::add_terrain_module
    //                              rmm_tdbc.cpp:321 (7)
    //         00487dd0     PUSH       this
    //         00487dd1     PUSH       EBX
    //         00487dd2     PUSH       EBP
    //         00487dd3     PUSH       ESI
    //         00487dd4     MOV        ESI,this
    //         00487dd6     PUSH       EDI
    //                              rmm_tdbc.cpp:324 (36)
    //         00487dd7     MOV        EAX,dword ptr [ESI + 0x34]
    //         00487dda     MOV        this,dword ptr [ESI + 0x4f58]
    //         00487de0     LEA        EAX,[EAX + EAX*0x8]
    //         00487de3     MOV        this,dword ptr [ECX + EAX*0x8 + this->field32_
    //         00487de7     MOV        EAX,0x51eb851f
    //         00487dec     IMUL       this,dword ptr [ESI + 0x18]
    //         00487df0     IMUL       this,dword ptr [ESI + 0x14]
    //         00487df4     IMUL       this
    //         00487df6     SAR        EDX,0x5
    //         00487df9     MOV        EAX,EDX
    //                              rmm_tdbc.cpp:327 (16)
    //         00487dfb     MOV        this,ESI
    //         00487dfd     SHR        EAX,0x1f
    //         00487e00     ADD        EDX,EAX
    //         00487e02     MOV        dword ptr [ESP + local_4],EDX
    //         00487e06     CALL       RGE_RMM_Database_Controller::add_terrain_module  void add_terrain_module(RGE_RMM_Database_Cont
    //                              rmm_tdbc.cpp:330 (4)
    //         00487e0b     FILD       dword ptr [ESP + local_4]
    //                              rmm_tdbc.cpp:331 (27)
    //         00487e0f     MOV        EAX,dword ptr [ESI + 0x20d4]
    //         00487e15     XOR        EBX,EBX
    //         00487e17     TEST       EAX,EAX
    //         00487e19     FMUL       float ptr [DAT_00571f28]                         = 17h
    //         00487e1f     MOV        EBP,0x6
    //         00487e24     FSTP       float ptr [ESP + local_4]
    //         00487e28     JLE        LAB_00487e61
    //                              rmm_tdbc.cpp:324 (6)
    //         00487e2a     LEA        EDI,[ESI + 0x1480]
    //                               LAB_00487e30                                                 XREF[1]:     00487e5f(j)  
    //                              rmm_tdbc.cpp:332 (5)
    //         00487e30     CMP        dword ptr [EDI + -0x4],EBP
    //         00487e33     JZ         LAB_00487e53
    //                              rmm_tdbc.cpp:334 (17)
    //         00487e35     FLD        float ptr [ESP + local_4]
    //         00487e39     FCOMP      double ptr [DAT_00571f30]
    //         00487e3f     FNSTSW     AX
    //         00487e41     TEST       AH,0x41
    //         00487e44     JNZ        LAB_00487e53
    //                              rmm_tdbc.cpp:336 (27)
    //         00487e46     FILD       dword ptr [EDI]
    //         00487e48     FMUL       float ptr [ESP + local_4]
    //         00487e4c     CALL       __ftol                                           undefined __ftol()
    //         00487e51     MOV        dword ptr [EDI],EAX
    //                               LAB_00487e53                                                 XREF[2]:     00487e33(j), 00487e44(j)  
    //         00487e53     MOV        EAX,dword ptr [ESI + 0x20d4]
    //         00487e59     INC        EBX
    //         00487e5a     ADD        EDI,0x20
    //         00487e5d     CMP        EBX,EAX
    //         00487e5f     JL         LAB_00487e30
    //                               LAB_00487e61                                                 XREF[1]:     00487e28(j)  
    //                              rmm_tdbc.cpp:340 (29)
    //         00487e61     PUSH       0x154
    //         00487e66     PUSH       s_C:\msdev\work\age1_x1\rmm_tdbc.c               = "C:\\msdev\\work\\age1_x1\\rmm_tdbc.cpp"
    //         00487e6b     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
    //         00487e70     ADD        ESP,0x8
    //         00487e73     CMP        EAX,0x1fff
    //         00487e78     JGE        LAB_00487f31
    //                              rmm_tdbc.cpp:342 (27)
    //         00487e7e     MOV        EAX,dword ptr [ESI + 0x20d4]
    //         00487e84     XOR        EDI,EDI
    //         00487e86     TEST       EAX,EAX
    //         00487e88     JLE        LAB_00487f71
    //         00487e8e     LEA        this,[ESI + 0x1480]
    //         00487e94     MOV        EBX,0x2
    //                               LAB_00487e99                                                 XREF[1]:     00487f29(j)  
    //                              rmm_tdbc.cpp:344 (8)
    //         00487e99     MOV        EAX,dword ptr [this->field0_0x0 + -0x4]
    //         00487e9c     CMP        EAX,0xd
    //         00487e9f     JNZ        LAB_00487eb6
    //                              rmm_tdbc.cpp:346 (9)
    //         00487ea1     MOV        EAX,dword ptr [this->field0_0x0 + -0xc]
    //         00487ea4     LEA        EDX,[EAX + EAX*0x2]
    //         00487ea7     MOV        dword ptr [this->field0_0x0 + -0xc],EDX
    //                              rmm_tdbc.cpp:347 (7)
    //         00487eaa     MOV        EAX,dword ptr [this->field0_0x0]
    //         00487eac     LEA        EAX,[EAX + EAX*0x2]
    //         00487eaf     MOV        dword ptr [this->field0_0x0],EAX
    //                              rmm_tdbc.cpp:348 (3)
    //         00487eb1     MOV        dword ptr [ECX + this->field16_0x10],EBX
    //                              rmm_tdbc.cpp:350 (7)
    //         00487eb4     JMP        LAB_00487f1d
    //                               LAB_00487eb6                                                 XREF[1]:     00487e9f(j)  
    //         00487eb6     CMP        EAX,0x14
    //         00487eb9     JNZ        LAB_00487ed1
    //                              rmm_tdbc.cpp:352 (11)
    //         00487ebb     MOV        EAX,dword ptr [this->field0_0x0 + -0xc]
    //         00487ebe     CDQ
    //         00487ebf     SUB        EAX,EDX
    //         00487ec1     SAR        EAX,0x1
    //         00487ec3     MOV        dword ptr [this->field0_0x0 + -0xc],EAX
    //                              rmm_tdbc.cpp:353 (9)
    //         00487ec6     MOV        EAX,dword ptr [this->field0_0x0]
    //         00487ec8     CDQ
    //         00487ec9     SUB        EAX,EDX
    //         00487ecb     SAR        EAX,0x1
    //         00487ecd     MOV        dword ptr [this->field0_0x0],EAX
    //                              rmm_tdbc.cpp:355 (7)
    //         00487ecf     JMP        LAB_00487f1d
    //                               LAB_00487ed1                                                 XREF[1]:     00487eb9(j)  
    //         00487ed1     CMP        EAX,0x13
    //         00487ed4     JNZ        LAB_00487eec
    //                              rmm_tdbc.cpp:357 (11)
    //         00487ed6     MOV        EAX,dword ptr [this->field0_0x0 + -0xc]
    //         00487ed9     CDQ
    //         00487eda     SUB        EAX,EDX
    //         00487edc     SAR        EAX,0x1
    //         00487ede     MOV        dword ptr [this->field0_0x0 + -0xc],EAX
    //                              rmm_tdbc.cpp:358 (9)
    //         00487ee1     MOV        EAX,dword ptr [this->field0_0x0]
    //         00487ee3     CDQ
    //         00487ee4     SUB        EAX,EDX
    //         00487ee6     SAR        EAX,0x1
    //         00487ee8     MOV        dword ptr [this->field0_0x0],EAX
    //                              rmm_tdbc.cpp:360 (7)
    //         00487eea     JMP        LAB_00487f1d
    //                               LAB_00487eec                                                 XREF[1]:     00487ed4(j)  
    //         00487eec     CMP        EAX,0xa
    //         00487eef     JNZ        LAB_00487f0a
    //                              rmm_tdbc.cpp:362 (11)
    //         00487ef1     MOV        EAX,dword ptr [this->field0_0x0 + -0xc]
    //         00487ef4     CDQ
    //         00487ef5     SUB        EAX,EDX
    //         00487ef7     SAR        EAX,0x1
    //         00487ef9     MOV        dword ptr [this->field0_0x0 + -0xc],EAX
    //                              rmm_tdbc.cpp:363 (9)
    //         00487efc     MOV        EAX,dword ptr [this->field0_0x0]
    //         00487efe     CDQ
    //         00487eff     SUB        EAX,EDX
    //         00487f01     SAR        EAX,0x1
    //         00487f03     MOV        dword ptr [this->field0_0x0],EAX
    //                              rmm_tdbc.cpp:364 (3)
    //         00487f05     MOV        dword ptr [ECX + this->field16_0x10],EBX
    //                              rmm_tdbc.cpp:366 (6)
    //         00487f08     JMP        LAB_00487f1d
    //                               LAB_00487f0a                                                 XREF[1]:     00487eef(j)  
    //         00487f0a     CMP        EAX,EBP
    //         00487f0c     JNZ        LAB_00487f1d
    //                              rmm_tdbc.cpp:368 (8)
    //         00487f0e     MOV        EDX,dword ptr [this->field0_0x0 + -0xc]
    //         00487f11     SHL        EDX,0x1
    //         00487f13     MOV        dword ptr [this->field0_0x0 + -0xc],EDX
    //                              rmm_tdbc.cpp:369 (25)
    //         00487f16     MOV        dword ptr [ECX + this->field16_0x10],0x0
    //                               LAB_00487f1d                                                 XREF[5]:     00487eb4(j), 00487ecf(j), 
    //                                                                                                         00487eea(j), 00487f08(j), 
    //                                                                                                         00487f0c(j)  
    //         00487f1d     MOV        EAX,dword ptr [ESI + 0x20d4]
    //         00487f23     INC        EDI
    //         00487f24     ADD        this,0x20
    //         00487f27     CMP        EDI,EAX
    //         00487f29     JL         LAB_00487e99
    //                              rmm_tdbc.cpp:373 (2)
    //         00487f2f     JMP        LAB_00487f71
    //                               LAB_00487f31                                                 XREF[1]:     00487e78(j)  
    //                              rmm_tdbc.cpp:374 (23)
    //         00487f31     MOV        EAX,dword ptr [ESI + 0x20d4]
    //         00487f37     XOR        EDX,EDX
    //         00487f39     TEST       EAX,EAX
    //         00487f3b     JLE        LAB_00487f71
    //         00487f3d     LEA        EAX,[ESI + 0x1490]
    //         00487f43     MOV        EBX,0x2
    //                               LAB_00487f48                                                 XREF[1]:     00487f6f(j)  
    //                              rmm_tdbc.cpp:376 (7)
    //         00487f48     MOV        this,dword ptr [EAX + -0x14]
    //         00487f4b     CMP        this,EBP
    //         00487f4d     JNZ        LAB_00487f57
    //                              rmm_tdbc.cpp:377 (6)
    //         00487f4f     MOV        dword ptr [EAX],0x0
    //                              rmm_tdbc.cpp:378 (5)
    //         00487f55     JMP        LAB_00487f63
    //                               LAB_00487f57                                                 XREF[1]:     00487f4d(j)  
    //         00487f57     CMP        this,0xa
    //                              rmm_tdbc.cpp:380 (7)
    //         00487f5a     JZ         LAB_00487f61
    //         00487f5c     CMP        this,0xd
    //         00487f5f     JNZ        LAB_00487f63
    //                               LAB_00487f61                                                 XREF[1]:     00487f5a(j)  
    //                              rmm_tdbc.cpp:381 (2)
    //         00487f61     MOV        dword ptr [EAX],EBX
    //                               LAB_00487f63                                                 XREF[2]:     00487f55(j), 00487f5f(j)  
    //                              rmm_tdbc.cpp:374 (14)
    //         00487f63     MOV        this,dword ptr [ESI + 0x20d4]
    //         00487f69     INC        EDX
    //         00487f6a     ADD        EAX,0x20
    //         00487f6d     CMP        EDX,this
    //         00487f6f     JL         LAB_00487f48
    //                               LAB_00487f71                                                 XREF[3]:     00487e88(j), 00487f2f(j), 
    //                                                                                                         00487f3b(j)  
    //                              rmm_tdbc.cpp:384 (38)
    //         00487f71     PUSH       0x180
    //         00487f76     PUSH       s_C:\msdev\work\age1_x1\rmm_tdbc.c               = "C:\\msdev\\work\\age1_x1\\rmm_tdbc.cpp"
    //         00487f7b     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
    //         00487f80     ADD        ESP,0x8
    //         00487f83     PUSH       EAX
    //         00487f84     MOV        EAX,[L]                                          = 00000000
    //         00487f89     PUSH       s_Random_Map_terrain_initilization               = "Random Map terrain initilization, rand: %d"
    //         00487f8e     PUSH       EAX
    //         00487f8f     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
    //         00487f94     ADD        ESP,0xc
    //                              rmm_tdbc.cpp:385 (6)
    //         00487f97     POP        EDI
    //         00487f98     POP        ESI
    //         00487f99     POP        EBP
    //         00487f9a     POP        EBX
    //         00487f9b     POP        this
    //         00487f9c     RET
    //         00487f9d     ??         90h
    //         00487f9e     NOP
    //         00487f9f     NOP
    return;
}

void TRIBE_RMM_Database_Controller::add_object_module() {
    /* TODO: Stub */
    //                              void __thiscall add_object_module(TRIBE_RMM_Database_Controller * th
    //              void              <VOID>         <RETURN>
    //              TRIBE_RMM_Data    ECX:4 (auto)   this
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[7]:     004880a4(W), 004880a8(R), 004881f7(W), 004881fb(R), 
    //                                                                                     00488343(W), 00488377(R), 0048838b(W)  
    //              undefined4        Stack[-0x8]:4  local_8                   XREF[3]:     00488327(W), 00488373(R), 00488387(W)  
    //              long              Stack[-0xc]:4  index1                    XREF[5]:     00488214(W), 004882bc(R), 004882cb(W), 00488399(R), 
    //                                                                                     004883a7(R)  
    //              long              Stack[-0x10]:4 count                     XREF[4]:     00488134(W), 00488147(W), 004883b1(W), 00488589(R)  
    //              long              Stack[-0x14]:4 extra_island_roll         XREF[0,4]:   004882cf(W), 00488347(R), 0048836e(W), 00488391(R)  
    //              uchar             Stack[-0x15]:1 done
    //                               ?add_object_module@TRIBE_RMM_Database_Controller@@MAEXXZ     XREF[1]:     00571f0c(*)  
    //                               TRIBE_RMM_Database_Controller::add_object_module
    //                              rmm_tdbc.cpp:392 (9)
    //         00487fa0     SUB        ESP,0x14
    //         00487fa3     PUSH       EBX
    //         00487fa4     PUSH       EBP
    //         00487fa5     PUSH       ESI
    //         00487fa6     PUSH       EDI
    //         00487fa7     MOV        EBP,this
    //                              rmm_tdbc.cpp:406 (5)
    //         00487fa9     CALL       RGE_RMM_Database_Controller::add_object_module   void add_object_module(RGE_RMM_Database_Contr
    //                              rmm_tdbc.cpp:408 (15)
    //         00487fae     PUSH       0x198
    //         00487fb3     PUSH       s_C:\msdev\work\age1_x1\rmm_tdbc.c               = "C:\\msdev\\work\\age1_x1\\rmm_tdbc.cpp"
    //         00487fb8     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
    //                              rmm_tdbc.cpp:411 (19)
    //         00487fbd     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         00487fc3     ADD        ESP,0x8
    //         00487fc6     CALL       TRIBE_Game::startingAge                          Age startingAge(TRIBE_Game * this)
    //         00487fcb     CMP        EAX,0x1
    //         00487fce     JNZ        LAB_00488030
    //                              rmm_tdbc.cpp:414 (23)
    //         00487fd0     MOV        EAX,dword ptr [EBP + 0x399c]
    //         00487fd6     XOR        this,this
    //         00487fd8     TEST       EAX,EAX
    //         00487fda     JLE        LAB_00488000
    //         00487fdc     LEA        EAX,[EBP + 0x2720]
    //         00487fe2     MOV        EDX,0x53
    //                               LAB_00487fe7                                                 XREF[1]:     00487ffe(j)  
    //                              rmm_tdbc.cpp:415 (5)
    //         00487fe7     CMP        dword ptr [EAX + -0x14],EDX
    //         00487fea     JNZ        LAB_00487ff2
    //                              rmm_tdbc.cpp:416 (6)
    //         00487fec     MOV        dword ptr [EAX],0x1
    //                               LAB_00487ff2                                                 XREF[1]:     00487fea(j)  
    //                              rmm_tdbc.cpp:414 (14)
    //         00487ff2     MOV        ESI,dword ptr [EBP + 0x399c]
    //         00487ff8     INC        this
    //         00487ff9     ADD        EAX,0x30
    //         00487ffc     CMP        this,ESI
    //         00487ffe     JL         LAB_00487fe7
    //                               LAB_00488000                                                 XREF[1]:     00487fda(j)  
    //                              rmm_tdbc.cpp:418 (23)
    //         00488000     MOV        EAX,dword ptr [EBP + 0x399c]
    //         00488006     XOR        this,this
    //         00488008     TEST       EAX,EAX
    //         0048800a     JLE        LAB_00488030
    //         0048800c     LEA        EAX,[EBP + 0x2720]
    //         00488012     MOV        EDX,0x6d
    //                               LAB_00488017                                                 XREF[1]:     0048802e(j)  
    //                              rmm_tdbc.cpp:419 (5)
    //         00488017     CMP        dword ptr [EAX + -0x14],EDX
    //         0048801a     JNZ        LAB_00488022
    //                              rmm_tdbc.cpp:420 (6)
    //         0048801c     MOV        dword ptr [EAX],0x0
    //                               LAB_00488022                                                 XREF[1]:     0048801a(j)  
    //                              rmm_tdbc.cpp:418 (14)
    //         00488022     MOV        ESI,dword ptr [EBP + 0x399c]
    //         00488028     INC        this
    //         00488029     ADD        EAX,0x30
    //         0048802c     CMP        this,ESI
    //         0048802e     JL         LAB_00488017
    //                               LAB_00488030                                                 XREF[2]:     00487fce(j), 0048800a(j)  
    //                              rmm_tdbc.cpp:424 (10)
    //         00488030     CMP        dword ptr [EBP + 0x34],0x6
    //         00488034     JNZ        LAB_004880fb
    //                              rmm_tdbc.cpp:426 (10)
    //         0048803a     MOV        this,dword ptr [EBP + 0x1458]
    //         00488040     TEST       this,this
    //         00488042     JLE        LAB_00488062
    //                              rmm_tdbc.cpp:567 (30)
    //         00488044     LEA        EAX,[ECX + ECX*0x2]
    //         00488047     LEA        EDX,[this->field0_0x0 + EAX*0x4]
    //         0048804a     LEA        EAX,[EBP + EDX*0x4 + 0x3c]
    //         0048804e     MOV        EDX,this
    //                               LAB_00488050                                                 XREF[1]:     00488060(j)  
    //         00488050     LEA        ESI,[EAX + -0x34]
    //         00488053     MOV        EDI,EAX
    //         00488055     MOV        this,0xd
    //         0048805a     SUB        EAX,0x34
    //         0048805d     DEC        EDX
    //         0048805e     MOVSD.REP  ES:EDI,ESI
    //         00488060     JNZ        LAB_00488050
    //                               LAB_00488062                                                 XREF[1]:     00488042(j)  
    //                              rmm_tdbc.cpp:429 (10)
    //         00488062     MOV        ESI,dword ptr [EBP + 0x14]
    //         00488065     MOV        EAX,0x2aaaaaab
    //         0048806a     IMUL       ESI
    //                              rmm_tdbc.cpp:434 (6)
    //         0048806c     MOV        this,byte ptr [EBP + 0x1458]
    //                              rmm_tdbc.cpp:435 (69)
    //         00488072     MOV        EBX,dword ptr [EBP + 0x18]
    //         00488075     MOV        EAX,EDX
    //         00488077     MOV        byte ptr [EBP + 0x54],this
    //         0048807a     SHR        EAX,0x1f
    //         0048807d     ADD        EDX,EAX
    //         0048807f     MOV        this,ESI
    //         00488081     MOV        EDI,EDX
    //         00488083     MOV        EDX,EBX
    //         00488085     MOV        dword ptr [EBP + 0x40],0x1
    //         0048808c     MOV        dword ptr [EBP + 0x50],0x7
    //         00488093     LEA        EAX,[EDI + EDI*0x1]
    //         00488096     MOV        dword ptr [EBP + 0x4c],0x2
    //         0048809d     SUB        EDX,EAX
    //         0048809f     SUB        this,EAX
    //         004880a1     IMUL       EDX,this
    //         004880a4     MOV        dword ptr [ESP + local_4],EDX
    //         004880a8     FILD       dword ptr [ESP + local_4]
    //         004880ac     FMUL       double ptr [DAT_00571f38]                        = 66h    f
    //         004880b2     CALL       __ftol                                           undefined __ftol()
    //                              rmm_tdbc.cpp:437 (13)
    //         004880b7     MOV        this,dword ptr [EBP + 0xc]
    //         004880ba     MOV        dword ptr [EBP + 0x3c],EAX
    //         004880bd     MOV        dword ptr [EBP + 0x58],0xa
    //                              rmm_tdbc.cpp:441 (5)
    //         004880c4     SUB        ESI,EDI
    //         004880c6     MOV        EAX,dword ptr [ECX + this->field8_0x8]
    //                              rmm_tdbc.cpp:442 (24)
    //         004880c9     SUB        EBX,EDI
    //         004880cb     CDQ
    //         004880cc     SUB        EAX,EDX
    //         004880ce     SAR        EAX,0x1
    //         004880d0     MOV        dword ptr [EBP + 0x44],EAX
    //         004880d3     MOV        EAX,dword ptr [ECX + this->field12_0xc]
    //         004880d6     CDQ
    //         004880d7     SUB        EAX,EDX
    //         004880d9     MOV        dword ptr [EBP + 0x5c],EDI
    //         004880dc     SAR        EAX,0x1
    //         004880de     MOV        dword ptr [EBP + 0x48],EAX
    //                              rmm_tdbc.cpp:445 (26)
    //         004880e1     MOV        EAX,dword ptr [EBP + 0x1458]
    //         004880e7     INC        EAX
    //         004880e8     MOV        dword ptr [EBP + 0x60],EDI
    //         004880eb     MOV        dword ptr [EBP + 0x64],ESI
    //         004880ee     MOV        dword ptr [EBP + 0x68],EBX
    //         004880f1     MOV        byte ptr [EBP + 0x6c],0xa
    //         004880f5     MOV        dword ptr [EBP + 0x1458],EAX
    //                               LAB_004880fb                                                 XREF[1]:     00488034(j)  
    //                              rmm_tdbc.cpp:449 (10)
    //         004880fb     CMP        dword ptr [EBP + 0x34],0x2
    //         004880ff     JGE        LAB_004885a5
    //                              rmm_tdbc.cpp:451 (44)
    //         00488105     PUSH       0x1c3
    //         0048810a     PUSH       s_C:\msdev\work\age1_x1\rmm_tdbc.c               = "C:\\msdev\\work\\age1_x1\\rmm_tdbc.cpp"
    //         0048810f     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
    //         00488114     MOV        this,EAX
    //         00488116     MOV        EAX,0x80010003
    //         0048811b     SHL        this,0x2
    //         0048811e     IMUL       this
    //         00488120     ADD        EDX,this
    //         00488122     ADD        ESP,0x8
    //         00488125     SAR        EDX,0xe
    //         00488128     MOV        EAX,EDX
    //         0048812a     SHR        EAX,0x1f
    //         0048812d     LEA        ESI,[EDX + EAX*0x1 + 0x1]
    //                              rmm_tdbc.cpp:452 (15)
    //         00488131     MOV        EAX,dword ptr [EBP + 0x38]
    //         00488134     MOV        dword ptr [ESP + count],ESI
    //         00488138     LEA        this,[ESI + EAX*0x1]
    //         0048813b     CMP        this,0xa
    //         0048813e     JLE        LAB_0048814d
    //                              rmm_tdbc.cpp:453 (13)
    //         00488140     MOV        this,0xa
    //         00488145     SUB        this,EAX
    //         00488147     MOV        dword ptr [ESP + count],this
    //         0048814b     MOV        ESI,this
    //                               LAB_0048814d                                                 XREF[1]:     0048813e(j)  
    //                              rmm_tdbc.cpp:455 (20)
    //         0048814d     MOV        EAX,dword ptr [EBP + 0x18]
    //         00488150     MOV        EBX,dword ptr [EBP + 0x14]
    //         00488153     ADD        EAX,EBX
    //         00488155     MOV        this,dword ptr [EBP + 0x1458]
    //         0048815b     IMUL       EAX,ESI
    //         0048815e     CDQ
    //         0048815f     IDIV       this
    //                              rmm_tdbc.cpp:456 (6)
    //         00488161     XOR        EDX,EDX
    //         00488163     TEST       this,this
    //         00488165     JLE        LAB_0048817f
    //                              rmm_tdbc.cpp:455 (3)
    //         00488167     LEA        this,[EBP + 0x3c]
    //                               LAB_0048816a                                                 XREF[1]:     0048817d(j)  
    //                              rmm_tdbc.cpp:457 (21)
    //         0048816a     MOV        EBX,dword ptr [this->field0_0x0]
    //         0048816c     ADD        this,0x34
    //         0048816f     SUB        EBX,EAX
    //         00488171     INC        EDX
    //         00488172     MOV        dword ptr [this->field0_0x0 + -0x34],EBX
    //         00488175     MOV        EDI,dword ptr [EBP + 0x1458]
    //         0048817b     CMP        EDX,EDI
    //         0048817d     JL         LAB_0048816a
    //                               LAB_0048817f                                                 XREF[1]:     00488165(j)  
    //                              rmm_tdbc.cpp:459 (12)
    //         0048817f     XOR        EDI,EDI
    //         00488181     XOR        EBX,EBX
    //         00488183     CMP        ESI,EDI
    //         00488185     JLE        LAB_0048859f
    //                              rmm_tdbc.cpp:471 (4)
    //         0048818b     JMP        LAB_0048818f
    //                               LAB_0048818d                                                 XREF[1]:     00488597(j)  
    //         0048818d     XOR        EDI,EDI
    //                               LAB_0048818f                                                 XREF[1]:     0048818b(j)  
    //                              rmm_tdbc.cpp:461 (20)
    //         0048818f     MOV        ESI,dword ptr [EBP + 0x1458]
    //         00488195     MOV        EAX,EBX
    //         00488197     ADD        EAX,ESI
    //         00488199     LEA        EDX,[EAX + EAX*0x2]
    //         0048819c     LEA        EAX,[EAX + EDX*0x4]
    //         0048819f     MOV        dword ptr [EBP + EAX*0x4 + 0x40],EDI
    //                              rmm_tdbc.cpp:462 (16)
    //         004881a3     MOV        EDX,dword ptr [EBP + 0x1458]
    //         004881a9     MOV        EAX,EBX
    //         004881ab     ADD        EAX,EDX
    //         004881ad     LEA        this,[EAX + EAX*0x2]
    //         004881b0     LEA        EDX,[EAX + this->field0_0x0*0x4]
    //                              rmm_tdbc.cpp:463 (24)
    //         004881b3     MOV        EAX,EBX
    //         004881b5     MOV        dword ptr [EBP + EDX*0x4 + 0x50],0x7
    //         004881bd     MOV        this,dword ptr [EBP + 0x1458]
    //         004881c3     ADD        EAX,this
    //         004881c5     LEA        this,[EAX + EAX*0x2]
    //         004881c8     LEA        EDX,[EAX + this->field0_0x0*0x4]
    //                              rmm_tdbc.cpp:464 (38)
    //         004881cb     MOV        this,BL
    //         004881cd     MOV        dword ptr [EBP + EDX*0x4 + 0x4c],0x3
    //         004881d5     MOV        AL,byte ptr [EBP + 0x1458]
    //         004881db     MOV        EDX,dword ptr [EBP + 0x1458]
    //         004881e1     ADD        this,AL
    //         004881e3     MOV        EAX,EBX
    //         004881e5     ADD        EAX,EDX
    //         004881e7     LEA        EDX,[EAX + EAX*0x2]
    //         004881ea     LEA        EAX,[EAX + EDX*0x4]
    //         004881ed     MOV        byte ptr [EBP + EAX*0x4 + 0x54],this
    //                              rmm_tdbc.cpp:465 (35)
    //         004881f1     MOV        this,dword ptr [EBP + 0x18]
    //         004881f4     ADD        this,dword ptr [EBP + 0x14]
    //         004881f7     MOV        dword ptr [ESP + local_4],this
    //         004881fb     FILD       dword ptr [ESP + local_4]
    //         004881ff     FMUL       double ptr [DAT_00571f40]
    //         00488205     CALL       __ftol                                           undefined __ftol()
    //         0048820a     MOV        ESI,dword ptr [EBP + 0x1458]
    //         00488210     MOV        this,EBX
    //         00488212     ADD        this,ESI
    //                              rmm_tdbc.cpp:473 (168)
    //         00488214     MOV        dword ptr [ESP + index1],EDI
    //         00488218     LEA        EDX,[ECX + ECX*0x2]
    //         0048821b     LEA        this,[this->field0_0x0 + EDX*0x4]
    //         0048821e     MOV        dword ptr [EBP + this->field0_0x0*0x4 + 0x3c],
    //         00488222     MOV        EDX,dword ptr [EBP + 0x1458]
    //         00488228     MOV        EAX,EBX
    //         0048822a     ADD        EAX,EDX
    //         0048822c     LEA        EDX,[EAX + EAX*0x2]
    //         0048822f     LEA        EAX,[EAX + EDX*0x4]
    //         00488232     MOV        dword ptr [EBP + EAX*0x4 + 0x58],0xa
    //         0048823a     MOV        this,dword ptr [EBP + 0x1458]
    //         00488240     MOV        EAX,EBX
    //         00488242     ADD        EAX,this
    //         00488244     LEA        this,[EAX + EAX*0x2]
    //         00488247     LEA        EDX,[EAX + this->field0_0x0*0x4]
    //         0048824a     MOV        EAX,dword ptr [EBP + 0x1460]
    //         00488250     MOV        dword ptr [EBP + EDX*0x4 + 0x5c],EAX
    //         00488254     MOV        ESI,dword ptr [EBP + 0x1458]
    //         0048825a     MOV        EAX,EBX
    //         0048825c     ADD        EAX,ESI
    //         0048825e     LEA        this,[EAX + EAX*0x2]
    //         00488261     LEA        EDX,[EAX + this->field0_0x0*0x4]
    //         00488264     MOV        EAX,dword ptr [EBP + 0x1464]
    //         0048826a     MOV        dword ptr [EBP + EDX*0x4 + 0x60],EAX
    //         0048826e     MOV        EDX,dword ptr [EBP + 0x1458]
    //         00488274     MOV        EAX,EBX
    //         00488276     ADD        EAX,EDX
    //         00488278     LEA        this,[EAX + EAX*0x2]
    //         0048827b     LEA        EDX,[EAX + this->field0_0x0*0x4]
    //         0048827e     MOV        EAX,dword ptr [EBP + 0x1468]
    //         00488284     MOV        dword ptr [EBP + EDX*0x4 + 0x64],EAX
    //         00488288     MOV        this,dword ptr [EBP + 0x1458]
    //         0048828e     LEA        EAX,[EBX + this->field0_0x0*0x1 + 0x2]
    //         00488292     MOV        this,dword ptr [EBP + 0x146c]
    //         00488298     LEA        EDX,[EAX + EAX*0x2]
    //         0048829b     LEA        EAX,[EAX + EDX*0x4]
    //         0048829e     MOV        dword ptr [EBP + EAX*0x4],this
    //         004882a2     MOV        this,dword ptr [EBP + 0x1458]
    //         004882a8     MOV        EAX,EBX
    //         004882aa     ADD        EAX,this
    //         004882ac     MOV        this,byte ptr [EBP + 0x1470]
    //         004882b2     LEA        EDX,[EAX + EAX*0x2]
    //         004882b5     LEA        EAX,[EAX + EDX*0x4]
    //         004882b8     MOV        byte ptr [EBP + EAX*0x4 + 0x6c],this
    //                               LAB_004882bc                                                 XREF[1]:     004883a1(j)  
    //                              rmm_tdbc.cpp:476 (4)
    //         004882bc     MOV        EDI,dword ptr [ESP + index1]
    //                              rmm_tdbc.cpp:478 (53)
    //         004882c0     PUSH       0x1de
    //         004882c5     INC        EDI
    //         004882c6     PUSH       s_C:\msdev\work\age1_x1\rmm_tdbc.c               = "C:\\msdev\\work\\age1_x1\\rmm_tdbc.cpp"
    //         004882cb     MOV        dword ptr [ESP + index1],EDI
    //         004882cf     MOV        byte ptr [ESP + extra_island_roll+0x3],0x1
    //         004882d4     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
    //         004882d9     MOV        EDX,dword ptr [EBP + 0x14]
    //         004882dc     MOV        this,EAX
    //         004882de     SUB        EDX,0x10
    //         004882e1     MOV        EAX,0x80010003
    //         004882e6     IMUL       this,EDX
    //         004882e9     IMUL       this
    //         004882eb     ADD        EDX,this
    //         004882ed     ADD        ESP,0x8
    //         004882f0     SAR        EDX,0xe
    //         004882f3     MOV        EAX,EDX
    //                              rmm_tdbc.cpp:479 (50)
    //         004882f5     PUSH       0x1df
    //         004882fa     SHR        EAX,0x1f
    //         004882fd     PUSH       s_C:\msdev\work\age1_x1\rmm_tdbc.c               = "C:\\msdev\\work\\age1_x1\\rmm_tdbc.cpp"
    //         00488302     LEA        ESI,[EDX + EAX*0x1 + 0x8]
    //         00488306     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
    //         0048830b     MOV        EDX,dword ptr [EBP + 0x18]
    //         0048830e     MOV        this,EAX
    //         00488310     SUB        EDX,0x10
    //         00488313     MOV        EAX,0x80010003
    //         00488318     IMUL       this,EDX
    //         0048831b     IMUL       this
    //         0048831d     ADD        EDX,this
    //         0048831f     ADD        ESP,0x8
    //         00488322     SAR        EDX,0xe
    //         00488325     MOV        EAX,EDX
    //                              rmm_tdbc.cpp:480 (51)
    //         00488327     MOV        dword ptr [ESP + local_8],0x0
    //         0048832f     SHR        EAX,0x1f
    //         00488332     LEA        EDI,[EDX + EAX*0x1 + 0x8]
    //         00488336     MOV        EAX,dword ptr [EBP + 0x1458]
    //         0048833c     TEST       EAX,EAX
    //         0048833e     JLE        LAB_00488391
    //         00488340     LEA        EDX,[EBP + 0x48]
    //         00488343     MOV        dword ptr [ESP + local_4],EDX
    //                               LAB_00488347                                                 XREF[1]:     0048838f(j)  
    //         00488347     MOV        AL,byte ptr [ESP + extra_island_roll+0x3]
    //         0048834b     TEST       AL,AL
    //         0048834d     JZ         LAB_00488399
    //         0048834f     MOV        this,dword ptr [EDX + -0x4]
    //         00488352     MOV        EAX,ESI
    //         00488354     SUB        EAX,this
    //         00488356     MOV        this,EDI
    //         00488358     SUB        this,dword ptr [EDX]
    //                              rmm_tdbc.cpp:485 (20)
    //         0048835a     MOV        EDX,EAX
    //         0048835c     IMUL       EDX,EAX
    //         0048835f     MOV        EAX,this
    //         00488361     IMUL       EAX,this
    //         00488364     ADD        EDX,EAX
    //         00488366     CMP        EDX,0x190
    //         0048836c     JGE        LAB_00488373
    //                              rmm_tdbc.cpp:486 (5)
    //         0048836e     MOV        byte ptr [ESP + extra_island_roll+0x3],0x0
    //                               LAB_00488373                                                 XREF[1]:     0048836c(j)  
    //                              rmm_tdbc.cpp:480 (30)
    //         00488373     MOV        EAX,dword ptr [ESP + local_8]
    //         00488377     MOV        EDX,dword ptr [ESP + local_4]
    //         0048837b     MOV        this,dword ptr [EBP + 0x1458]
    //         00488381     INC        EAX
    //         00488382     ADD        EDX,0x34
    //         00488385     CMP        EAX,this
    //         00488387     MOV        dword ptr [ESP + local_8],EAX
    //         0048838b     MOV        dword ptr [ESP + local_4],EDX
    //         0048838f     JL         LAB_00488347
    //                               LAB_00488391                                                 XREF[1]:     0048833e(j)  
    //                              rmm_tdbc.cpp:489 (22)
    //         00488391     MOV        AL,byte ptr [ESP + extra_island_roll+0x3]
    //         00488395     TEST       AL,AL
    //         00488397     JNZ        LAB_004883a7
    //                               LAB_00488399                                                 XREF[1]:     0048834d(j)  
    //         00488399     CMP        dword ptr [ESP + index1],0x3e8
    //         004883a1     JL         LAB_004882bc
    //                               LAB_004883a7                                                 XREF[1]:     00488397(j)  
    //                              rmm_tdbc.cpp:491 (10)
    //         004883a7     CMP        dword ptr [ESP + index1],0x3e8
    //         004883af     JL         LAB_004883b5
    //                              rmm_tdbc.cpp:492 (4)
    //         004883b1     MOV        dword ptr [ESP + count],EBX
    //                               LAB_004883b5                                                 XREF[1]:     004883af(j)  
    //                              rmm_tdbc.cpp:494 (10)
    //         004883b5     MOV        this,dword ptr [EBP + 0x1458]
    //         004883bb     MOV        EAX,EBX
    //         004883bd     ADD        EAX,this
    //                              rmm_tdbc.cpp:509 (316)
    //         004883bf     PUSH       0x1fd
    //         004883c4     PUSH       s_C:\msdev\work\age1_x1\rmm_tdbc.c               = "C:\\msdev\\work\\age1_x1\\rmm_tdbc.cpp"
    //         004883c9     LEA        this,[EAX + EAX*0x2]
    //         004883cc     LEA        EDX,[EAX + this->field0_0x0*0x4]
    //         004883cf     MOV        EAX,EBX
    //         004883d1     MOV        dword ptr [EBP + EDX*0x4 + 0x44],ESI
    //         004883d5     MOV        EDX,dword ptr [EBP + 0x1458]
    //         004883db     ADD        EAX,EDX
    //         004883dd     LEA        this,[EAX + EAX*0x2]
    //         004883e0     LEA        EDX,[EAX + this->field0_0x0*0x4]
    //         004883e3     MOV        dword ptr [EBP + EDX*0x4 + 0x48],EDI
    //         004883e7     MOV        EAX,dword ptr [EBP + 0x399c]
    //         004883ed     LEA        EAX,[EAX + EAX*0x2]
    //         004883f0     SHL        EAX,0x4
    //         004883f3     MOV        dword ptr [EAX + EBP*0x1 + 0x2710],0xffffffff
    //         004883fe     MOV        EAX,dword ptr [EBP + 0x399c]
    //         00488404     LEA        this,[EAX + EAX*0x2]
    //         00488407     SHL        this,0x4
    //         0048840a     MOV        byte ptr [ECX + EBP*0x1 + this->field10004_0x2
    //         00488412     MOV        EAX,dword ptr [EBP + 0x399c]
    //         00488418     XOR        this,this
    //         0048841a     LEA        EDX,[EAX + EAX*0x2]
    //         0048841d     SHL        EDX,0x4
    //         00488420     MOV        byte ptr [EDX + EBP*0x1 + 0x2715],0x0
    //         00488428     MOV        EAX,dword ptr [EBP + 0x399c]
    //         0048842e     LEA        EAX,[EAX + EAX*0x2]
    //         00488431     SHL        EAX,0x4
    //         00488434     MOV        dword ptr [EAX + EBP*0x1 + 0x2718],0x8
    //         0048843f     MOV        EAX,dword ptr [EBP + 0x399c]
    //         00488445     LEA        EDX,[EAX + EAX*0x2]
    //         00488448     SHL        EDX,0x4
    //         0048844b     MOV        dword ptr [EDX + EBP*0x1 + 0x271c],this
    //         00488452     MOV        EAX,dword ptr [EBP + 0x399c]
    //         00488458     LEA        EAX,[EAX + EAX*0x2]
    //         0048845b     SHL        EAX,0x4
    //         0048845e     MOV        dword ptr [EAX + EBP*0x1 + 0x2720],0x1
    //         00488469     MOV        EAX,dword ptr [EBP + 0x399c]
    //         0048846f     LEA        EDX,[EAX + EAX*0x2]
    //         00488472     SHL        EDX,0x4
    //         00488475     MOV        dword ptr [EDX + EBP*0x1 + 0x2724],0x4
    //         00488480     MOV        EAX,dword ptr [EBP + 0x399c]
    //         00488486     MOV        EDX,EBX
    //         00488488     LEA        EAX,[EAX + EAX*0x2]
    //         0048848b     SHL        EAX,0x4
    //         0048848e     MOV        dword ptr [EAX + EBP*0x1 + 0x2728],this
    //         00488495     MOV        EAX,dword ptr [EBP + 0x1458]
    //         0048849b     ADD        EDX,EAX
    //         0048849d     MOV        EAX,dword ptr [EBP + 0x399c]
    //         004884a3     LEA        EAX,[EAX + EAX*0x2]
    //         004884a6     SHL        EAX,0x4
    //         004884a9     MOV        dword ptr [EAX + EBP*0x1 + 0x272c],EDX
    //         004884b0     MOV        EAX,dword ptr [EBP + 0x399c]
    //         004884b6     ADD        EAX,0xd1
    //         004884bb     LEA        EDX,[EAX + EAX*0x2]
    //         004884be     SHL        EDX,0x4
    //         004884c1     MOV        dword ptr [EDX + EBP*0x1],this
    //         004884c4     MOV        EAX,dword ptr [EBP + 0x399c]
    //         004884ca     LEA        EAX,[EAX + EAX*0x2]
    //         004884cd     SHL        EAX,0x4
    //         004884d0     MOV        dword ptr [EAX + EBP*0x1 + 0x2734],0x1a
    //         004884db     MOV        EAX,dword ptr [EBP + 0x399c]
    //         004884e1     LEA        EDX,[EAX + EAX*0x2]
    //         004884e4     SHL        EDX,0x4
    //         004884e7     MOV        dword ptr [EDX + EBP*0x1 + 0x2738],this
    //         004884ee     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
    //         004884f3     ADD        ESP,0x8
    //         004884f6     CMP        EAX,0x3fff
    //                              rmm_tdbc.cpp:510 (25)
    //         004884fb     MOV        EAX,dword ptr [EBP + 0x399c]
    //         00488501     JGE        LAB_00488516
    //         00488503     LEA        EAX,[EAX + EAX*0x2]
    //         00488506     SHL        EAX,0x4
    //         00488509     MOV        dword ptr [EAX + EBP*0x1 + 0x270c],0x66
    //                              rmm_tdbc.cpp:511 (2)
    //         00488514     JMP        LAB_00488527
    //                               LAB_00488516                                                 XREF[1]:     00488501(j)  
    //                              rmm_tdbc.cpp:512 (17)
    //         00488516     LEA        this,[EAX + EAX*0x2]
    //         00488519     SHL        this,0x4
    //         0048851c     MOV        dword ptr [ECX + EBP*0x1 + this->field9996_0x2
    //                               LAB_00488527                                                 XREF[1]:     00488514(j)  
    //                              rmm_tdbc.cpp:513 (6)
    //         00488527     MOV        this,dword ptr [EBP + 0x399c]
    //                              rmm_tdbc.cpp:515 (16)
    //         0048852d     MOV        EDX,dword ptr [EBP + 0x3fd0]
    //         00488533     INC        this
    //         00488534     SHL        EDX,0x4
    //         00488537     MOV        dword ptr [EBP + 0x399c],this
    //                              rmm_tdbc.cpp:517 (50)
    //         0048853d     MOV        this,EBX
    //         0048853f     MOV        dword ptr [EDX + EBP*0x1 + 0x39a4],EDI
    //         00488546     MOV        EAX,dword ptr [EBP + 0x3fd0]
    //         0048854c     ADD        EAX,0x39a
    //         00488551     SHL        EAX,0x4
    //         00488554     MOV        dword ptr [EAX + EBP*0x1],ESI
    //         00488557     MOV        EDX,dword ptr [EBP + 0x3fd0]
    //         0048855d     MOV        EAX,dword ptr [EBP + 0x1458]
    //         00488563     SHL        EDX,0x4
    //         00488566     ADD        this,EAX
    //         00488568     MOV        dword ptr [EDX + EBP*0x1 + 0x39a8],this
    //                              rmm_tdbc.cpp:518 (20)
    //         0048856f     MOV        EAX,dword ptr [EBP + 0x3fd0]
    //         00488575     SHL        EAX,0x4
    //         00488578     MOV        dword ptr [EAX + EBP*0x1 + 0x39ac],0x0
    //                              rmm_tdbc.cpp:519 (26)
    //         00488583     MOV        EDX,dword ptr [EBP + 0x3fd0]
    //         00488589     MOV        EAX,dword ptr [ESP + count]
    //         0048858d     INC        EDX
    //         0048858e     INC        EBX
    //         0048858f     MOV        dword ptr [EBP + 0x3fd0],EDX
    //         00488595     CMP        EBX,EAX
    //         00488597     JL         LAB_0048818d
    //                              rmm_tdbc.cpp:459 (2)
    //         0048859d     MOV        ESI,EAX
    //                               LAB_0048859f                                                 XREF[1]:     00488185(j)  
    //                              rmm_tdbc.cpp:521 (6)
    //         0048859f     ADD        dword ptr [EBP + 0x1458],ESI
    //                               LAB_004885a5                                                 XREF[1]:     004880ff(j)  
    //                              rmm_tdbc.cpp:525 (22)
    //         004885a5     MOV        EAX,dword ptr [EBP + 0x399c]
    //         004885ab     XOR        ESI,ESI
    //         004885ad     TEST       EAX,EAX
    //         004885af     JLE        LAB_00488646
    //         004885b5     LEA        this,[EBP + 0x2738]
    //                               LAB_004885bb                                                 XREF[1]:     00488640(j)  
    //                              rmm_tdbc.cpp:527 (7)
    //         004885bb     MOV        EAX,dword ptr [this->field0_0x0 + -0xc]
    //         004885be     TEST       EAX,EAX
    //         004885c0     JL         LAB_004885e4
    //                              rmm_tdbc.cpp:529 (26)
    //         004885c2     MOV        EAX,dword ptr [this->field0_0x0 + -0x2c]
    //         004885c5     ADD        EAX,-0x3b
    //         004885c8     CMP        EAX,0x2b
    //         004885cb     JA         switchD_004885d5::caseD_3c
    //         004885cd     XOR        EDX,EDX
    //         004885cf     MOV        DL,byte ptr [EAX + switchD_004885d5::switchdat
    //                               switchD_004885d5::switchD
    //         004885d5     JMP        dword ptr [EDX*0x4 + switchD_004885d5::switchd   = 004885dc
    //                               switchD_004885d5::caseD_41                                   XREF[5]:     004885d5(j), 00488678(*), 
    //                               switchD_004885d5::caseD_42                                                0048867c(*), 00488680(*), 
    //                               switchD_004885d5::caseD_66                                                00488684(*)  
    //                               switchD_004885d5::caseD_3b
    //                              rmm_tdbc.cpp:541 (6)
    //         004885dc     MOV        dword ptr [this->field0_0x0],0xc
    //                              rmm_tdbc.cpp:545 (7)
    //         004885e2     JMP        switchD_004885d5::caseD_3c
    //                               LAB_004885e4                                                 XREF[1]:     004885c0(j)  
    //         004885e4     CMP        EAX,-0x2
    //         004885e7     JNZ        switchD_004885d5::caseD_3c
    //                              rmm_tdbc.cpp:547 (26)
    //         004885e9     MOV        EAX,dword ptr [this->field0_0x0 + -0x2c]
    //         004885ec     ADD        EAX,-0x3b
    //         004885ef     CMP        EAX,0x2b
    //         004885f2     JA         switchD_004885d5::caseD_3c
    //         004885f4     XOR        EDX,EDX
    //         004885f6     MOV        DL,byte ptr [EAX + 0x4886cc]=>BYTE_00488691      = 4h
    //                               switchD_004885fc::switchD
    //         004885fc     JMP        dword ptr [EDX*0x4 + switchD_004885fc::switchd   = 00488616
    //                               switchD_004885fc::caseD_41                                   XREF[2]:     004885fc(j), 004886bc(*)  
    //                              rmm_tdbc.cpp:553 (17)
    //         00488603     MOV        EDX,dword ptr [EBP + 0xc]
    //         00488606     MOV        EAX,dword ptr [EDX + 0x8]
    //         00488609     CDQ
    //         0048860a     AND        EDX,0x7
    //         0048860d     ADD        EAX,EDX
    //         0048860f     SAR        EAX,0x3
    //         00488612     MOV        dword ptr [this->field0_0x0],EAX
    //                              rmm_tdbc.cpp:554 (2)
    //         00488614     JMP        switchD_004885d5::caseD_3c
    //                               switchD_004885fc::caseD_42                                   XREF[3]:     004885fc(j), 004886b8(*), 
    //                               switchD_004885fc::caseD_3b                                                004886c0(*)  
    //                              rmm_tdbc.cpp:556 (6)
    //         00488616     MOV        EAX,dword ptr [EBP + 0xc]
    //         00488619     MOV        EDX,dword ptr [EAX + 0x8]
    //                              rmm_tdbc.cpp:557 (2)
    //         0048861c     JMP        LAB_00488624
    //                               switchD_004885fc::caseD_66                                   XREF[2]:     004885fc(j), 004886c4(*)  
    //                              rmm_tdbc.cpp:559 (40)
    //         0048861e     MOV        EDX,dword ptr [EBP + 0xc]
    //         00488621     MOV        EDX,dword ptr [EDX + 0x8]
    //                               LAB_00488624                                                 XREF[1]:     0048861c(j)  
    //         00488624     MOV        EAX,0x2aaaaaab
    //         00488629     IMUL       EDX
    //         0048862b     MOV        EAX,EDX
    //         0048862d     SHR        EAX,0x1f
    //         00488630     ADD        EDX,EAX
    //         00488632     MOV        dword ptr [this->field0_0x0],EDX
    //                               switchD_004885d5::caseD_3d                                   XREF[9]:     004885cb(j), 004885d5(j), 
    //                               switchD_004885d5::caseD_3e                                                004885e2(j), 004885e7(j), 
    //                               switchD_004885d5::caseD_3f                                                004885f2(j), 004885fc(j), 
    //                               switchD_004885d5::caseD_40                                                00488614(j), 00488688(*), 
    //                               switchD_004885d5::caseD_43                                                004886c8(*)  
    //                               switchD_004885d5::caseD_44
    //                               switchD_004885d5::caseD_45
    //                               switchD_004885d5::caseD_46
    //                               switchD_004885d5::caseD_47
    //                               switchD_004885d5::caseD_48
    //                               switchD_004885d5::caseD_49
    //                               switchD_004885d5::caseD_4a
    //                               switchD_004885d5::caseD_4b
    //                               switchD_004885d5::caseD_4c
    //                               switchD_004885d5::caseD_4d
    //                               switchD_004885d5::caseD_4e
    //                               switchD_004885d5::caseD_4f
    //                               switchD_004885d5::caseD_50
    //                               switchD_004885d5::caseD_51
    //                               switchD_004885d5::caseD_52
    //                               switchD_004885d5::caseD_53
    //                               switchD_004885d5::caseD_54
    //                               switchD_004885d5::caseD_55
    //                               switchD_004885d5::caseD_56
    //                               switchD_004885d5::caseD_57
    //                               switchD_004885d5::caseD_58
    //                               switchD_004885d5::caseD_59
    //                               switchD_004885d5::caseD_5a
    //                               switchD_004885d5::caseD_5b
    //                               switchD_004885d5::caseD_5c
    //                               switchD_004885d5::caseD_5d
    //                               switchD_004885d5::caseD_5e
    //                               switchD_004885d5::caseD_5f
    //                               switchD_004885d5::caseD_60
    //                               switchD_004885d5::caseD_61
    //                               switchD_004885d5::caseD_62
    //                               switchD_004885d5::caseD_63
    //                               switchD_004885d5::caseD_64
    //                               switchD_004885d5::caseD_65
    //                               switchD_004885fc::caseD_3c
    //                               switchD_004885fc::caseD_3d
    //                               switchD_004885fc::caseD_3e
    //                               switchD_004885fc::caseD_3f
    //                               switchD_004885fc::caseD_40
    //                               switchD_004885fc::caseD_43
    //                               switchD_004885fc::caseD_44
    //                               switchD_004885fc::caseD_45
    //                               switchD_004885fc::caseD_46
    //                               switchD_004885fc::caseD_47
    //                               switchD_004885fc::caseD_48
    //                               switchD_004885fc::caseD_49
    //                               switchD_004885fc::caseD_4a
    //                               switchD_004885fc::caseD_4b
    //                               switchD_004885fc::caseD_4c
    //                               switchD_004885fc::caseD_4d
    //                               switchD_004885fc::caseD_4e
    //                               switchD_004885fc::caseD_4f
    //                               switchD_004885fc::caseD_50
    //                               switchD_004885fc::caseD_51
    //                               switchD_004885fc::caseD_52
    //                               switchD_004885fc::caseD_53
    //                               switchD_004885fc::caseD_54
    //                               switchD_004885fc::caseD_55
    //                               switchD_004885fc::caseD_56
    //                               switchD_004885fc::caseD_57
    //                               switchD_004885fc::caseD_58
    //                               switchD_004885fc::caseD_59
    //                               switchD_004885fc::caseD_5a
    //                               switchD_004885fc::caseD_5b
    //                               switchD_004885fc::caseD_5c
    //                               switchD_004885fc::caseD_5d
    //                               switchD_004885fc::caseD_5e
    //                               switchD_004885fc::caseD_5f
    //                               switchD_004885fc::caseD_60
    //                               switchD_004885fc::caseD_61
    //                               switchD_004885fc::caseD_62
    //                               switchD_004885fc::caseD_63
    //                               switchD_004885fc::caseD_64
    //                               switchD_004885fc::caseD_65
    //                               switchD_004885d5::caseD_3c
    //         00488634     MOV        EAX,dword ptr [EBP + 0x399c]
    //         0048863a     INC        ESI
    //         0048863b     ADD        this,0x30
    //         0048863e     CMP        ESI,EAX
    //         00488640     JL         LAB_004885bb
    //                               LAB_00488646                                                 XREF[1]:     004885af(j)  
    //                              rmm_tdbc.cpp:566 (39)
    //         00488646     PUSH       0x236
    //         0048864b     PUSH       s_C:\msdev\work\age1_x1\rmm_tdbc.c               = "C:\\msdev\\work\\age1_x1\\rmm_tdbc.cpp"
    //         00488650     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
    //         00488655     MOV        this,dword ptr [L]                               = 00000000
    //         0048865b     ADD        ESP,0x8
    //         0048865e     PUSH       EAX
    //         0048865f     PUSH       s_Random_Map_object_initilization,               = "Random Map object initilization, rand: %d"
    //         00488664     PUSH       this
    //         00488665     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
    //         0048866a     ADD        ESP,0xc
    //                              rmm_tdbc.cpp:567 (139)
    //         0048866d     POP        EDI
    //         0048866e     POP        ESI
    //         0048866f     POP        EBP
    //         00488670     POP        EBX
    //         00488671     ADD        ESP,0x14
    //         00488674     RET
    //                              *                                               FUNCTION                                                *
    //                              undefined FUN_00488675()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00488675
    //         00488675     NOP
    //         00488676     MOV        EDI,EDI
    //                              Symbol Ref: No symbol: NONAME
    //                               switchD_004885d5::switchdataD_00488678                       XREF[1]:     add_object_module:004885d5(*)  
    //         00488678     addr       switchD_004885d5::caseD_3b
    //         0048867c     addr       switchD_004885d5::caseD_3b
    //         00488680     addr       switchD_004885d5::caseD_3b
    //         00488684     addr       switchD_004885d5::caseD_3b
    //         00488688     addr       switchD_004885d5::caseD_3c
    //                              Symbol Ref: No symbol: NONAME
    //                               switchD_004885d5::switchdataD_0048868c                       XREF[1]:     add_object_module:004885cf(*)  
    //         0048868c     db         0h
    //         0048868d     db         4h
    //         0048868e     db         4h
    //         0048868f     db         4h
    //         00488690     db         4h
    //                               BYTE_00488691                                                XREF[1]:     add_object_module:004885f6(*)  
    //         00488691     db         4h
    //         00488692     db         1h
    //         00488693     db         2h
    //         00488694     db         4h
    //         00488695     db         4h
    //         00488696     db         4h
    //         00488697     db         4h
    //         00488698     db         4h
    //         00488699     db         4h
    //         0048869a     db         4h
    //         0048869b     db         4h
    //         0048869c     db         4h
    //         0048869d     db         4h
    //         0048869e     db         4h
    //         0048869f     db         4h
    //         004886a0     db         4h
    //         004886a1     db         4h
    //         004886a2     db         4h
    //         004886a3     db         4h
    //         004886a4     db         4h
    //         004886a5     db         4h
    //         004886a6     db         4h
    //         004886a7     db         4h
    //         004886a8     db         4h
    //         004886a9     db         4h
    //         004886aa     db         4h
    //         004886ab     db         4h
    //         004886ac     db         4h
    //         004886ad     db         4h
    //         004886ae     db         4h
    //         004886af     db         4h
    //         004886b0     db         4h
    //         004886b1     db         4h
    //         004886b2     db         4h
    //         004886b3     db         4h
    //         004886b4     db         4h
    //         004886b5     db         4h
    //         004886b6     db         4h
    //         004886b7     db         3h
    //                              Symbol Ref: No symbol: NONAME
    //                               switchD_004885fc::switchdataD_004886b8                       XREF[1]:     add_object_module:004885fc(*)  
    //         004886b8     addr       switchD_004885fc::caseD_3b
    //         004886bc     addr       switchD_004885fc::caseD_41
    //         004886c0     addr       switchD_004885fc::caseD_3b
    //         004886c4     addr       switchD_004885fc::caseD_66
    //         004886c8     addr       switchD_004885d5::caseD_3c
    //                              Symbol Ref: No symbol: NONAME
    //                               switchD_004885fc::switchdataD_004886cc
    //         004886cc     db         0h
    //         004886cd     db         4h
    //         004886ce     db         4h
    //         004886cf     db         4h
    //         004886d0     db         4h
    //         004886d1     db         4h
    //         004886d2     db         1h
    //         004886d3     db         2h
    //         004886d4     db         4h
    //         004886d5     db         4h
    //         004886d6     db         4h
    //         004886d7     db         4h
    //         004886d8     db         4h
    //         004886d9     db         4h
    //         004886da     db         4h
    //         004886db     db         4h
    //         004886dc     db         4h
    //         004886dd     db         4h
    //         004886de     db         4h
    //         004886df     db         4h
    //         004886e0     db         4h
    //         004886e1     db         4h
    //         004886e2     db         4h
    //         004886e3     db         4h
    //         004886e4     db         4h
    //         004886e5     db         4h
    //         004886e6     db         4h
    //         004886e7     db         4h
    //         004886e8     db         4h
    //         004886e9     db         4h
    //         004886ea     db         4h
    //         004886eb     db         4h
    //         004886ec     db         4h
    //         004886ed     db         4h
    //         004886ee     db         4h
    //         004886ef     db         4h
    //         004886f0     db         4h
    //         004886f1     db         4h
    //         004886f2     db         4h
    //         004886f3     db         4h
    //         004886f4     db         4h
    //         004886f5     db         4h
    //         004886f6     db         4h
    //         004886f7     db         3h
    //         004886f8     ??         90h
    //         004886f9     ??         90h
    //         004886fa     ??         90h
    //         004886fb     ??         90h
    //         004886fc     ??         90h
    //         004886fd     ??         90h
    //         004886fe     ??         90h
    //         004886ff     ??         90h
    return;
}

void TRIBE_RMM_Database_Controller::add_elevation_module() {
    /* TODO: Stub */
    //                              void __thiscall add_elevation_module(TRIBE_RMM_Database_Controller *
    //              void              <VOID>         <RETURN>
    //              TRIBE_RMM_Data    ECX:4 (auto)   this
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     0048871a(W), 00488721(R)  
    //                               ?add_elevation_module@TRIBE_RMM_Database_Controller@@MAEXXZ  XREF[1]:     00571f10(*)  
    //                               TRIBE_RMM_Database_Controller::add_elevation_module
    //                              rmm_tdbc.cpp:572 (6)
    //         00488700     PUSH       this
    //         00488701     PUSH       EBX
    //         00488702     PUSH       ESI
    //         00488703     PUSH       EDI
    //         00488704     MOV        EBX,this
    //                              rmm_tdbc.cpp:576 (5)
    //         00488706     CALL       RGE_RMM_Database_Controller::add_elevation_mod   void add_elevation_module(RGE_RMM_Database_Co
    //                              rmm_tdbc.cpp:579 (19)
    //         0048870b     PUSH       0x243
    //         00488710     PUSH       s_C:\msdev\work\age1_x1\rmm_tdbc.c               = "C:\\msdev\\work\\age1_x1\\rmm_tdbc.cpp"
    //         00488715     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
    //         0048871a     MOV        dword ptr [ESP + local_4],EAX
    //                              rmm_tdbc.cpp:581 (33)
    //         0048871e     MOV        EAX,dword ptr [EBX + 0x34]
    //         00488721     FILD       dword ptr [ESP + local_4]
    //         00488725     ADD        ESP,0x8
    //         00488728     CMP        EAX,0x7
    //         0048872b     FMUL       float ptr [DAT_00571f48]                         = E0h
    //         00488731     FSUBR      float ptr [DAT_00571f4c]
    //         00488737     FMUL       float ptr [DAT_00571f50]                         = 0Ah
    //         0048873d     JNZ        LAB_00488745
    //                              rmm_tdbc.cpp:582 (6)
    //         0048873f     FMUL       float ptr [DAT_00571f54]
    //                               LAB_00488745                                                 XREF[1]:     0048873d(j)  
    //                              rmm_tdbc.cpp:584 (18)
    //         00488745     MOV        EAX,dword ptr [EBX + 0x491c]
    //         0048874b     XOR        EDI,EDI
    //         0048874d     TEST       EAX,EAX
    //         0048874f     JLE        LAB_00488770
    //         00488751     LEA        ESI,[EBX + 0x3fd4]
    //                               LAB_00488757                                                 XREF[1]:     0048876e(j)  
    //                              rmm_tdbc.cpp:585 (25)
    //         00488757     FILD       dword ptr [ESI]
    //         00488759     FMUL       ST1
    //         0048875b     CALL       __ftol                                           undefined __ftol()
    //         00488760     MOV        dword ptr [ESI],EAX
    //         00488762     MOV        EAX,dword ptr [EBX + 0x491c]
    //         00488768     INC        EDI
    //         00488769     ADD        ESI,0x18
    //         0048876c     CMP        EDI,EAX
    //         0048876e     JL         LAB_00488757
    //                               LAB_00488770                                                 XREF[1]:     0048874f(j)  
    //                              rmm_tdbc.cpp:587 (40)
    //         00488770     PUSH       0x24b
    //         00488775     PUSH       s_C:\msdev\work\age1_x1\rmm_tdbc.c               = "C:\\msdev\\work\\age1_x1\\rmm_tdbc.cpp"
    //         0048877a     FSTP       ST0
    //         0048877c     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
    //         00488781     ADD        ESP,0x8
    //         00488784     PUSH       EAX
    //         00488785     MOV        EAX,[L]                                          = 00000000
    //         0048878a     PUSH       s_Random_Map_elevation_initilizati               = "Random Map elevation initilization, rand: 
    //         0048878f     PUSH       EAX
    //         00488790     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
    //         00488795     ADD        ESP,0xc
    //                              rmm_tdbc.cpp:588 (5)
    //         00488798     POP        EDI
    //         00488799     POP        ESI
    //         0048879a     POP        EBX
    //         0048879b     POP        this
    //         0048879c     RET
    //         0048879d     ??         90h
    //         0048879e     NOP
    //         0048879f     NOP
    return;
}

void TRIBE_RMM_Database_Controller::add_shallows_module() {
    /* TODO: Stub */
    //                              void __thiscall add_shallows_module(TRIBE_RMM_Database_Controller * 
    //              void              <VOID>         <RETURN>
    //              TRIBE_RMM_Data    ECX:4 (auto)   this
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     00488808(W), 00488830(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     00488854(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[2]:     004887c9(W), 004887e4(R)  
    //              RGE_Shallows_I    Stack[-0x32c   shallows_info             XREF[1,4]:   00488802(W), 004887dd(W), 00488818(*), 004887d2(*), 
    //                                                                                     004887e2(*)  
    //                               ?add_shallows_module@TRIBE_RMM_Database_Controller@@IAEXXZ   XREF[2]:     add_land_module:00487c0d(c), 
    //                               TRIBE_RMM_Database_Controller::add_shallows_module                        add_land_module:00487c33(c)  
    //                              rmm_tdbc.cpp:593 (30)
    //         004887a0     PUSH       -0x1
    //         004887a2     PUSH       FUN_0055e6de
    //         004887a7     MOV        EAX,FS:[0x0]
    //         004887ad     PUSH       EAX
    //         004887ae     MOV        dword ptr FS:[0x0],ESP
    //         004887b5     SUB        ESP,0x320
    //         004887bb     PUSH       ESI
    //         004887bc     MOV        ESI,this
    //                              rmm_tdbc.cpp:599 (27)
    //         004887be     XOR        EDX,EDX
    //         004887c0     PUSH       EDI
    //         004887c1     MOV        EAX,dword ptr [ESI + 0x1458]
    //         004887c7     TEST       EAX,EAX
    //         004887c9     MOV        dword ptr [ESP + local_10],EAX
    //         004887d0     JLE        LAB_004887f5
    //         004887d2     LEA        this=>shallows_info+0x8,[ESP + 0x10]
    //         004887d6     LEA        EAX,[ESI + 0x48]
    //                               LAB_004887d9                                                 XREF[1]:     004887f3(j)  
    //                              rmm_tdbc.cpp:601 (7)
    //         004887d9     MOV        EDI,dword ptr [EAX + -0x4]
    //         004887dc     INC        EDX
    //         004887dd     MOV        dword ptr [ECX + shallows_info+0x4],EDI
    //                              rmm_tdbc.cpp:602 (21)
    //         004887e0     MOV        EDI,dword ptr [EAX]
    //         004887e2     MOV        dword ptr [this->field0_0x0]=>shallows_info+0x
    //         004887e4     MOV        EDI,dword ptr [ESP + local_10]
    //         004887eb     ADD        EAX,0x34
    //         004887ee     ADD        this,0x8
    //         004887f1     CMP        EDX,EDI
    //         004887f3     JL         LAB_004887d9
    //                               LAB_004887f5                                                 XREF[1]:     004887d0(j)  
    //                              rmm_tdbc.cpp:605 (49)
    //         004887f5     PUSH       0x34c
    //         004887fa     CALL       operator_new                                     void * operator_new(uint param_1)
    //         004887ff     ADD        ESP,0x4
    //         00488802     MOV        dword ptr [ESP + shallows_info.shallows[0].x],
    //         00488806     TEST       EAX,EAX
    //         00488808     MOV        dword ptr [ESP + local_4],0x0
    //         00488813     JZ         LAB_00488826
    //         00488815     MOV        EDX,dword ptr [ESI + 0xc]
    //         00488818     LEA        this=>shallows_info+0x4,[ESP + 0xc]
    //         0048881c     PUSH       this
    //         0048881d     PUSH       ESI
    //         0048881e     PUSH       EDX
    //         0048881f     MOV        this,EAX
    //         00488821     CALL       RGE_RMM_Shallows_Generator::RGE_RMM_Shallows_G   undefined RGE_RMM_Shallows_Generator(RGE_RMM_
    //                               LAB_00488826                                                 XREF[1]:     00488813(j)  
    //                              rmm_tdbc.cpp:607 (46)
    //         00488826     PUSH       0x25f
    //         0048882b     PUSH       s_C:\msdev\work\age1_x1\rmm_tdbc.c               = "C:\\msdev\\work\\age1_x1\\rmm_tdbc.cpp"
    //         00488830     MOV        dword ptr [ESP + local_4],0xffffffff
    //         0048883b     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
    //         00488840     ADD        ESP,0x8
    //         00488843     PUSH       EAX
    //         00488844     MOV        EAX,[L]                                          = 00000000
    //         00488849     PUSH       s_Random_Map_shallows_initilizatio               = "Random Map shallows initilization, rand: %d"
    //         0048884e     PUSH       EAX
    //         0048884f     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
    //                              rmm_tdbc.cpp:608 (26)
    //         00488854     MOV        this,dword ptr [ESP + local_c]
    //         0048885b     ADD        ESP,0xc
    //         0048885e     MOV        dword ptr FS:[0x0],this
    //         00488865     POP        EDI
    //         00488866     POP        ESI
    //         00488867     ADD        ESP,0x32c
    //         0048886d     RET
    //         0048886e     ??         90h
    //         0048886f     NOP
    return;
}

uchar TRIBE_RMM_Database_Controller::generate() {
    /* TODO: Stub */
    //                              uchar __thiscall generate(TRIBE_RMM_Database_Controller * this)
    //              uchar             AL:1           <RETURN>
    //              TRIBE_RMM_Data    ECX:4 (auto)   this
    //              undefined1        Stack[-0x1]:1  local_1                   XREF[2]:     0048887a(W), 004888cf(R)  
    //              uchar             Stack[-0x5]:1  ret_num
    //                               ?generate@TRIBE_RMM_Database_Controller@@UAEEXZ              XREF[1]:     00571f00(*)  
    //                               TRIBE_RMM_Database_Controller::generate
    //                              rmm_tdbc.cpp:614 (5)
    //         00488870     PUSH       this
    //         00488871     PUSH       EBX
    //         00488872     PUSH       ESI
    //         00488873     MOV        ESI,this
    //                              rmm_tdbc.cpp:617 (9)
    //         00488875     CALL       RGE_RMM_Database_Controller::generate            uchar generate(RGE_RMM_Database_Controller * 
    //         0048887a     MOV        byte ptr [ESP + local_1],AL
    //                              rmm_tdbc.cpp:623 (13)
    //         0048887e     MOV        EAX,dword ptr [ESI + 0x18]
    //         00488881     XOR        EBX,EBX
    //         00488883     TEST       EAX,EAX
    //         00488885     JLE        LAB_004888cf
    //         00488887     PUSH       EDI
    //         00488888     PUSH       EBP
    //         00488889     XOR        EBP,EBP
    //                               LAB_0048888b                                                 XREF[1]:     004888cb(j)  
    //                              rmm_tdbc.cpp:624 (11)
    //         0048888b     MOV        EAX,dword ptr [ESI + 0x14]
    //         0048888e     XOR        EDI,EDI
    //         00488890     TEST       EAX,EAX
    //         00488892     JLE        LAB_004888c2
    //         00488894     XOR        EDX,EDX
    //                               LAB_00488896                                                 XREF[1]:     004888c0(j)  
    //                              rmm_tdbc.cpp:625 (19)
    //         00488896     MOV        EAX,dword ptr [ESI + 0x10]
    //         00488899     LEA        this,[EAX + EBP*0x1]
    //         0048889c     MOV        EAX,dword ptr [EAX + EBP*0x1]
    //         0048889f     MOV        AL,byte ptr [EAX + EDX*0x1 + 0x5]
    //         004888a3     AND        AL,0x1f
    //         004888a5     CMP        AL,0x10
    //         004888a7     JNZ        LAB_004888b7
    //                              rmm_tdbc.cpp:626 (25)
    //         004888a9     MOV        this,dword ptr [this->field0_0x0]
    //         004888ab     MOV        AL,byte ptr [ECX + EDX*0x1 + this->field5_0x5]
    //         004888af     LEA        this,[ECX + EDX*0x1 + this->field5_0x5]
    //         004888b3     AND        AL,0xe0
    //         004888b5     MOV        byte ptr [this->field0_0x0],AL
    //                               LAB_004888b7                                                 XREF[1]:     004888a7(j)  
    //         004888b7     MOV        EAX,dword ptr [ESI + 0x14]
    //         004888ba     INC        EDI
    //         004888bb     ADD        EDX,0x18
    //         004888be     CMP        EDI,EAX
    //         004888c0     JL         LAB_00488896
    //                               LAB_004888c2                                                 XREF[1]:     00488892(j)  
    //                              rmm_tdbc.cpp:623 (13)
    //         004888c2     MOV        EAX,dword ptr [ESI + 0x18]
    //         004888c5     INC        EBX
    //         004888c6     ADD        EBP,0x4
    //         004888c9     CMP        EBX,EAX
    //         004888cb     JL         LAB_0048888b
    //         004888cd     POP        EBP
    //         004888ce     POP        EDI
    //                               LAB_004888cf                                                 XREF[1]:     00488885(j)  
    //                              rmm_tdbc.cpp:628 (4)
    //         004888cf     MOV        AL,byte ptr [ESP + local_1]
    //                              rmm_tdbc.cpp:629 (4)
    //         004888d3     POP        ESI
    //         004888d4     POP        EBX
    //         004888d5     POP        this
    //         004888d6     RET
    //         004888d7     ??         90h
    //         004888d8     NOP
    //         004888d9     NOP
    //         004888da     NOP
    //         004888db     NOP
    //         004888dc     NOP
    //         004888dd     NOP
    //         004888de     NOP
    //         004888df     NOP
    //                              * public: __thiscall RGE_RMM_Terrain_Generator::RGE_RMM_Terrain_Generator(class RGE_Map *,class RGE_... *
    //                              undefined __thiscall RGE_RMM_Terrain_Generator(RGE_RMM_Terrain_Gener
    //              undefined         <UNASSIGNED>   <RETURN>
    //              RGE_RMM_Terrai    ECX:4 (auto)   this
    //              RGE_Map *         Stack[0x4]:4   param_1                   XREF[1]:     004888e8(R)  
    //              RGE_Random_Map    Stack[0x8]:4   param_2                   XREF[1]:     004888e0(R)  
    //              RGE_Terrain_In    Stack[0xc]:4   param_3                   XREF[1]:     004888f8(R)  
    //                               ??0RGE_RMM_Terrain_Generator@@QAE@PAVRGE_Map@@PAVRGE_Random  XREF[2]:     add_terrain_module:00482864(c), 
    //                               RGE_RMM_Terrain_Generator::RGE_RMM_Terrain_Generator                      generate:00483475(c)  
    //                              rmm_terr.cpp:24 (24)
    //         004888e0     MOV        EAX,dword ptr [ESP + param_2]
    //         004888e4     PUSH       EBX
    //         004888e5     PUSH       ESI
    //         004888e6     MOV        EBX,this
    //         004888e8     MOV        this,dword ptr [ESP + param_1]
    //         004888ec     PUSH       EDI
    //         004888ed     PUSH       0x1
    //         004888ef     PUSH       EAX
    //         004888f0     PUSH       this
    //         004888f1     MOV        this,EBX
    //         004888f3     CALL       RGE_Random_Map_Module::RGE_Random_Map_Module     undefined RGE_Random_Map_Module(RGE_Random_Ma
    //                              rmm_terr.cpp:25 (20)
    //         004888f8     MOV        ESI,dword ptr [ESP + param_3]
    //         004888fc     MOV        this,0x4a6
    //         00488901     LEA        EDI,[EBX + 0x30]
    //         00488904     MOV        dword ptr [EBX],RGE_RMM_Terrain_Generator::`vf   = 00488920
    //         0048890a     MOVSD.REP  ES:EDI,ESI
    //                              rmm_terr.cpp:28 (15)
    //         0048890c     POP        EDI
    //         0048890d     MOV        dword ptr [EBX + 0x1c],0x40000000
    //         00488914     MOV        EAX,EBX
    //         00488916     POP        ESI
    //         00488917     POP        EBX
    //         00488918     RET        0xc
    //         0048891b     ??         90h
    //         0048891c     NOP
    //         0048891d     NOP
    //         0048891e     NOP
    //         0048891f     NOP
    return 0;
}

uchar TRIBE_RMM_Database_Controller::init(RGE_Map* param_1, RGE_Game_World* param_2, uchar param_3, long param_4, uchar param_5) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return 0;
}

