#include "../common.h"
#include "rmm_base.h"

RGE_Random_Map_Module::RGE_Random_Map_Module(RGE_Map* param_1, RGE_Random_Map_Module* param_2, uchar param_3) {
    /* TODO: Stub */
//                              undefined __thiscall RGE_Random_Map_Module(RGE_Random_Map_Module * t
//              undefined         <UNASSIGNED>   <RETURN>
//              RGE_Random_Map    ECX:4 (auto)   this
//              RGE_Map *         Stack[0x4]:4   param_1                   XREF[1]:     0048079b(R)
//              RGE_Random_Map    Stack[0x8]:4   param_2                   XREF[1]:     00480790(R)
//              uchar             Stack[0xc]:1   param_3                   XREF[1]:     004807ff(R)
//                               ??0RGE_Random_Map_Module@@QAE@PAVRGE_Map@@PAV0@E@Z           XREF[9]:     RGE_RMM_Cliffs_Generator:00481993(
//                               RGE_Random_Map_Module::RGE_Random_Map_Module                              RGE_RMM_Controller:004821d3(c),
//                                                                                                         RGE_RMM_Database_Controller:00482b
//                                                                                                         RGE_RMM_Database_Controller:004830
//                                                                                                         RGE_RMM_Elevation_Generator:004846
//                                                                                                         RGE_RMM_Land_Generator:00485213(c)
//                                                                                                         RGE_RMM_Object_Generator:00485c62(
//                                                                                                         RGE_RMM_Shallows_Generator:0048702
//                                                                                                         RGE_RMM_Terrain_Generator:004888f3
//                              rmm_base.cpp:23 (9)
//         00480790     MOV        EAX,dword ptr [ESP + param_2]
//         00480794     PUSH       EBX
//         00480795     PUSH       EBP
//         00480796     PUSH       ESI
//         00480797     MOV        ESI,this
//                              rmm_base.cpp:27 (23)
//         00480799     XOR        EBX,EBX
//         0048079b     MOV        this,dword ptr [ESP + param_1]
//         0048079f     PUSH       EDI
//         004807a0     CMP        this,EBX
//         004807a2     MOV        dword ptr [ESI],RGE_Random_Map_Module::`vftable' = 004808d0
//         004807a8     MOV        dword ptr [ESI + 0x4],EAX
//         004807ab     MOV        dword ptr [ESI + 0xc],this
//         004807ae     JZ         LAB_004807d0
//                              rmm_base.cpp:29 (5)
//         004807b0     CALL       RGE_Map::give_up_map_offsets                     RGE_Tile * * give_up_map_offsets(RGE_Map * th
//                              rmm_base.cpp:30 (11)
//         004807b5     MOV        this,dword ptr [ESI + 0xc]
//         004807b8     MOV        dword ptr [ESI + 0x10],EAX
//         004807bb     CALL       RGE_Map::get_map_width                           long get_map_width(RGE_Map * this)
//                              rmm_base.cpp:31 (14)
//         004807c0     MOV        this,dword ptr [ESI + 0xc]
//         004807c3     MOV        dword ptr [ESI + 0x14],EAX
//         004807c6     CALL       RGE_Map::get_map_height                          long get_map_height(RGE_Map * this)
//         004807cb     MOV        dword ptr [ESI + 0x18],EAX
//                              rmm_base.cpp:33 (2)
//         004807ce     JMP        LAB_004807d9
//                               LAB_004807d0                                                 XREF[1]:     004807ae(j)
//                              rmm_base.cpp:35 (3)
//         004807d0     MOV        dword ptr [ESI + 0x10],EBX
//                              rmm_base.cpp:36 (3)
//         004807d3     MOV        dword ptr [ESI + 0x14],EBX
//                              rmm_base.cpp:37 (3)
//         004807d6     MOV        dword ptr [ESI + 0x18],EBX
//                               LAB_004807d9                                                 XREF[1]:     004807ce(j)
//                              rmm_base.cpp:46 (38)
//         004807d9     MOV        this,dword ptr [ESI + 0x4]
//         004807dc     LEA        EDI,[ESI + 0x20]
//         004807df     LEA        EBP,[ESI + 0x24]
//         004807e2     MOV        dword ptr [ESI + 0x8],EBX
//         004807e5     MOV        dword ptr [EDI],EBX
//         004807e7     MOV        dword ptr [ESI + 0x28],0x0
//         004807ee     MOV        dword ptr [EBP],EBX
//         004807f1     LEA        EBX,[ESI + 0x28]
//         004807f4     TEST       this,this
//         004807f6     MOV        dword ptr [ESI + 0x2c],0x0
//         004807fd     JNZ        LAB_00480817
//                              rmm_base.cpp:49 (8)
//         004807ff     MOV        AL,byte ptr [ESP + param_3]
//         00480803     TEST       AL,AL
//         00480805     JZ         LAB_0048082c
//                              rmm_base.cpp:50 (7)
//         00480807     MOV        this,ESI
//         00480809     CALL       RGE_Random_Map_Module::create_shared_resources   void create_shared_resources(RGE_Random_Map_M
//                              rmm_base.cpp:59 (9)
//         0048080e     MOV        EAX,ESI
//         00480810     POP        EDI
//         00480811     POP        ESI
//         00480812     POP        EBP
//         00480813     POP        EBX
//         00480814     RET        0xc
//                               LAB_00480817                                                 XREF[1]:     004807fd(j)
//                              rmm_base.cpp:55 (6)
//         00480817     PUSH       ESI
//         00480818     CALL       RGE_Random_Map_Module::add_module                uchar add_module(RGE_Random_Map_Module * this
//                              rmm_base.cpp:57 (15)
//         0048081d     MOV        this,dword ptr [ESI + 0x4]
//         00480820     LEA        EAX,[ESI + 0x2c]
//         00480823     PUSH       EAX
//         00480824     PUSH       EBX
//         00480825     PUSH       EBP
//         00480826     PUSH       EDI
//         00480827     CALL       RGE_Random_Map_Module::share_resources           void share_resources(RGE_Random_Map_Module *
//                               LAB_0048082c                                                 XREF[1]:     00480805(j)
//                              rmm_base.cpp:59 (9)
//         0048082c     MOV        EAX,ESI
//         0048082e     POP        EDI
//         0048082f     POP        ESI
//         00480830     POP        EBP
//         00480831     POP        EBX
//         00480832     RET        0xc
//         00480835     ??         90h
//         00480836     NOP
//         00480837     NOP
//         00480838     NOP
//         00480839     NOP
//         0048083a     NOP
//         0048083b     NOP
//         0048083c     NOP
//         0048083d     NOP
//         0048083e     NOP
//         0048083f     NOP
}

RGE_Random_Map_Module::~RGE_Random_Map_Module() {
    /* TODO: Stub */
//                              void __thiscall ~RGE_Random_Map_Module(RGE_Random_Map_Module * this)
//              void              <VOID>         <RETURN>
//              RGE_Random_Map    ECX:4 (auto)   this
//                               ??1RGE_Random_Map_Module@@QAE@XZ                             XREF[4]:     0048085c(c),
//                               RGE_Random_Map_Module::~RGE_Random_Map_Module                             ~RGE_RMM_Database_Controller:00483
//                                                                                                         de_init:004835c8(c),
//                                                                                                         new_game:0052fc8a(c)
//                              rmm_base.cpp:64 (4)
//         00480840     PUSH       EBX
//         00480841     PUSH       ESI
//         00480842     MOV        ESI,this
//                              rmm_base.cpp:66 (16)
//         00480844     XOR        EBX,EBX
//         00480846     PUSH       EDI
//         00480847     MOV        EAX,dword ptr [ESI + 0x8]
//         0048084a     MOV        dword ptr [ESI],RGE_Random_Map_Module::`vftable' = 004808d0
//         00480850     CMP        EAX,EBX
//         00480852     JZ         LAB_00480871
//                               LAB_00480854                                                 XREF[1]:     0048086f(j)
//                              rmm_base.cpp:67 (29)
//         00480854     MOV        EDI,dword ptr [EAX]
//         00480856     CMP        EDI,EBX
//         00480858     JZ         LAB_0048086a
//         0048085a     MOV        this,EDI
//         0048085c     CALL       RGE_Random_Map_Module::~RGE_Random_Map_Module    void ~RGE_Random_Map_Module(RGE_Random_Map_Mo
//         00480861     PUSH       EDI
//         00480862     CALL       operator_delete                                  void operator_delete(void * param_1)
//         00480867     ADD        ESP,0x4
//                               LAB_0048086a                                                 XREF[1]:     00480858(j)
//         0048086a     MOV        EAX,dword ptr [ESI + 0x8]
//         0048086d     CMP        EAX,EBX
//         0048086f     JNZ        LAB_00480854
//                               LAB_00480871                                                 XREF[1]:     00480852(j)
//                              rmm_base.cpp:69 (7)
//         00480871     MOV        this,dword ptr [ESI + 0x4]
//         00480874     CMP        this,EBX
//         00480876     JNZ        LAB_0048088f
//                              rmm_base.cpp:73 (7)
//         00480878     MOV        this,ESI
//         0048087a     CALL       RGE_Random_Map_Module::destroy_shared_resources  void destroy_shared_resources(RGE_Random_Map_
//                              rmm_base.cpp:87 (3)
//         0048087f     MOV        dword ptr [ESI + 0xc],EBX
//                              rmm_base.cpp:88 (3)
//         00480882     MOV        dword ptr [ESI + 0x10],EBX
//                              rmm_base.cpp:89 (3)
//         00480885     MOV        dword ptr [ESI + 0x14],EBX
//                              rmm_base.cpp:90 (3)
//         00480888     MOV        dword ptr [ESI + 0x18],EBX
//                              rmm_base.cpp:91 (4)
//         0048088b     POP        EDI
//         0048088c     POP        ESI
//         0048088d     POP        EBX
//         0048088e     RET
//                               LAB_0048088f                                                 XREF[1]:     00480876(j)
//                              rmm_base.cpp:79 (6)
//         0048088f     PUSH       ESI
//         00480890     CALL       RGE_Random_Map_Module::remove_module             uchar remove_module(RGE_Random_Map_Module * t
//                              rmm_base.cpp:81 (3)
//         00480895     MOV        dword ptr [ESI + 0x20],EBX
//                              rmm_base.cpp:82 (3)
//         00480898     MOV        dword ptr [ESI + 0x24],EBX
//                              rmm_base.cpp:83 (3)
//         0048089b     MOV        dword ptr [ESI + 0x28],EBX
//                              rmm_base.cpp:84 (3)
//         0048089e     MOV        dword ptr [ESI + 0x2c],EBX
//                              rmm_base.cpp:87 (3)
//         004808a1     MOV        dword ptr [ESI + 0xc],EBX
//                              rmm_base.cpp:88 (3)
//         004808a4     MOV        dword ptr [ESI + 0x10],EBX
//                              rmm_base.cpp:89 (3)
//         004808a7     MOV        dword ptr [ESI + 0x14],EBX
//                              rmm_base.cpp:90 (3)
//         004808aa     MOV        dword ptr [ESI + 0x18],EBX
//                              rmm_base.cpp:91 (4)
//         004808ad     POP        EDI
//         004808ae     POP        ESI
//         004808af     POP        EBX
//         004808b0     RET
//         004808b1     ??         90h
//         004808b2     NOP
//         004808b3     NOP
//         004808b4     NOP
//         004808b5     NOP
//         004808b6     NOP
//         004808b7     NOP
//         004808b8     NOP
//         004808b9     NOP
//         004808ba     NOP
//         004808bb     NOP
//         004808bc     NOP
//         004808bd     NOP
//         004808be     NOP
//         004808bf     NOP
}

float RGE_Random_Map_Module::get_schedule() {
    /* TODO: Stub */
//                              float __thiscall get_schedule(RGE_Random_Map_Module * this)
//              float             ST0:10         <RETURN>
//              RGE_Random_Map    ECX:4 (auto)   this
//                               ?get_schedule@RGE_Random_Map_Module@@IAEMXZ                  XREF[4]:     generate:004808ef(c),
//                               RGE_Random_Map_Module::get_schedule                                       generate:004808fa(c),
//                                                                                                         generate:00480915(c),
//                                                                                                         generate:00480923(c)
//                              rmm_base.cpp:97 (3)
//         004808c0     FLD        float ptr [ECX + this->schedule]
//                              rmm_base.cpp:99 (1)
//         004808c3     RET
//         004808c4     ??         90h
//         004808c5     NOP
//         004808c6     NOP
//         004808c7     NOP
//         004808c8     NOP
//         004808c9     NOP
//         004808ca     NOP
//         004808cb     NOP
//         004808cc     NOP
//         004808cd     NOP
//         004808ce     NOP
//         004808cf     NOP
    return 0;
}

uchar RGE_Random_Map_Module::generate() {
    /* TODO: Stub */
//                              uchar __thiscall generate(RGE_Random_Map_Module * this)
//              uchar             AL:1           <RETURN>
//              RGE_Random_Map    ECX:4 (auto)   this
//              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     004808de(W), 00480952(R)
//              undefined4        Stack[-0x8]:4  local_8                   XREF[4]:     004808f6(W), 004808ff(R), 0048091d(W), 00480928(R)
//                               ?generate@RGE_Random_Map_Module@@UAEEXZ                      XREF[3]:     generate:00482260(j),
//                               RGE_Random_Map_Module::generate                                           generate:00483522(c), 00571e30(*)
//                              rmm_base.cpp:106 (9)
//         004808d0     SUB        ESP,0x8
//         004808d3     PUSH       EBX
//         004808d4     PUSH       EBP
//         004808d5     PUSH       ESI
//         004808d6     MOV        ESI,this
//         004808d8     PUSH       EDI
//                              rmm_base.cpp:111 (2)
//         004808d9     XOR        EBX,EBX
//                              rmm_base.cpp:115 (11)
//         004808db     MOV        EDI,dword ptr [ESI + 0x8]
//         004808de     MOV        dword ptr [ESP + local_4],ESI
//         004808e2     TEST       EDI,EDI
//         004808e4     JZ         LAB_00480956
//                               LAB_004808e6                                                 XREF[1]:     00480950(j)
//                              rmm_base.cpp:117 (3)
//         004808e6     MOV        EBP,dword ptr [EDI + 0x4]
//                              rmm_base.cpp:119 (33)
//         004808e9     TEST       EBX,EBX
//         004808eb     JZ         LAB_00480947
//         004808ed     MOV        this,dword ptr [EDI]
//         004808ef     CALL       RGE_Random_Map_Module::get_schedule              float get_schedule(RGE_Random_Map_Module * th
//         004808f4     MOV        this,dword ptr [EBX]
//         004808f6     FSTP       float ptr [ESP + local_8]
//         004808fa     CALL       RGE_Random_Map_Module::get_schedule              float get_schedule(RGE_Random_Map_Module * th
//         004808ff     FCOMP      float ptr [ESP + local_8]
//         00480903     FNSTSW     AX
//         00480905     TEST       AH,0x41
//         00480908     JZ         LAB_00480947
//                              rmm_base.cpp:125 (2)
//         0048090a     MOV        ESI,EBX
//                               LAB_0048090c                                                 XREF[1]:     00480938(j)
//                              rmm_base.cpp:126 (48)
//         0048090c     MOV        EAX,dword ptr [ESI + 0x4]
//         0048090f     TEST       EAX,EAX
//         00480911     JZ         LAB_0048093c
//         00480913     MOV        this,dword ptr [EDI]
//         00480915     CALL       RGE_Random_Map_Module::get_schedule              float get_schedule(RGE_Random_Map_Module * th
//         0048091a     MOV        EAX,dword ptr [ESI + 0x4]
//         0048091d     FSTP       float ptr [ESP + local_8]
//         00480921     MOV        this,dword ptr [EAX]
//         00480923     CALL       RGE_Random_Map_Module::get_schedule              float get_schedule(RGE_Random_Map_Module * th
//         00480928     FCOMP      float ptr [ESP + local_8]
//         0048092c     FNSTSW     AX
//         0048092e     TEST       AH,0x41
//         00480931     JZ         LAB_0048093c
//         00480933     MOV        ESI,dword ptr [ESI + 0x4]
//         00480936     TEST       ESI,ESI
//         00480938     JNZ        LAB_0048090c
//         0048093a     JMP        LAB_0048094c
//                               LAB_0048093c                                                 XREF[2]:     00480911(j), 00480931(j)
//                              rmm_base.cpp:128 (6)
//         0048093c     MOV        this,dword ptr [ESI + 0x4]
//         0048093f     MOV        dword ptr [EDI + 0x4],this
//                              rmm_base.cpp:129 (3)
//         00480942     MOV        dword ptr [ESI + 0x4],EDI
//                              rmm_base.cpp:130 (2)
//         00480945     JMP        LAB_0048094c
//                               LAB_00480947                                                 XREF[2]:     004808eb(j), 00480908(j)
//                              rmm_base.cpp:121 (3)
//         00480947     MOV        dword ptr [EDI + 0x4],EBX
//                              rmm_base.cpp:122 (8)
//         0048094a     MOV        EBX,EDI
//                               LAB_0048094c                                                 XREF[2]:     0048093a(j), 00480945(j)
//         0048094c     TEST       EBP,EBP
//         0048094e     MOV        EDI,EBP
//         00480950     JNZ        LAB_004808e6
//                              rmm_base.cpp:115 (4)
//         00480952     MOV        ESI,dword ptr [ESP + local_4]
//                               LAB_00480956                                                 XREF[1]:     004808e4(j)
//                              rmm_base.cpp:138 (39)
//         00480956     PUSH       0x8a
//         0048095b     PUSH       s_C:\msdev\work\age1_x1\rmm_base.c               = "C:\\msdev\\work\\age1_x1\\rmm_base.cpp"
//         00480960     MOV        dword ptr [ESI + 0x8],EBX
//         00480963     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
//         00480968     MOV        EDX,dword ptr [L]                                = 00000000
//         0048096e     ADD        ESP,0x8
//         00480971     PUSH       EAX
//         00480972     PUSH       s_RGE_RANDOM_MAP_MODULE::map_start               = "RGE_RANDOM_MAP_MODULE::map startped with r
//         00480977     PUSH       EDX
//         00480978     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
//                              rmm_base.cpp:139 (10)
//         0048097d     MOV        ESI,dword ptr [ESI + 0x8]
//         00480980     ADD        ESP,0xc
//         00480983     TEST       ESI,ESI
//         00480985     JZ         LAB_004809d3
//                               LAB_00480987                                                 XREF[1]:     004809bd(j)
//                              rmm_base.cpp:141 (10)
//         00480987     MOV        this,dword ptr [ESI]
//         00480989     MOV        EAX,dword ptr [this->_padding_]
//         0048098b     CALL       dword ptr [EAX]
//         0048098d     TEST       AL,AL
//         0048098f     JZ         LAB_004809c9
//                              rmm_base.cpp:143 (46)
//         00480991     PUSH       0x8f
//         00480996     PUSH       s_C:\msdev\work\age1_x1\rmm_base.c               = "C:\\msdev\\work\\age1_x1\\rmm_base.cpp"
//         0048099b     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
//         004809a0     MOV        this,dword ptr [L]                               = 00000000
//         004809a6     ADD        ESP,0x8
//         004809a9     PUSH       EAX
//         004809aa     PUSH       s_RGE_RANDOM_MAP_MODULE::module_co               = "RGE_RANDOM_MAP_MODULE::module completed wi
//         004809af     PUSH       this=>DAT_fffffff4
//         004809b0     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
//         004809b5     MOV        ESI,dword ptr [ESI + 0x4]
//         004809b8     ADD        ESP,0xc
//         004809bb     TEST       ESI,ESI
//         004809bd     JNZ        LAB_00480987
//                              rmm_base.cpp:148 (2)
//         004809bf     MOV        AL,0x1
//                              rmm_base.cpp:149 (8)
//         004809c1     POP        EDI
//         004809c2     POP        ESI
//         004809c3     POP        EBP
//         004809c4     POP        EBX
//         004809c5     ADD        ESP,0x8
//         004809c8     RET
//                               LAB_004809c9                                                 XREF[1]:     0048098f(j)
//                              rmm_base.cpp:142 (2)
//         004809c9     XOR        AL,AL
//                              rmm_base.cpp:149 (18)
//         004809cb     POP        EDI
//         004809cc     POP        ESI
//         004809cd     POP        EBP
//         004809ce     POP        EBX
//         004809cf     ADD        ESP,0x8
//         004809d2     RET
//                               LAB_004809d3                                                 XREF[1]:     00480985(j)
//         004809d3     POP        EDI
//         004809d4     POP        ESI
//         004809d5     POP        EBP
//         004809d6     MOV        AL,0x1
//         004809d8     POP        EBX
//         004809d9     ADD        ESP,0x8
//         004809dc     RET
//         004809dd     ??         90h
//         004809de     NOP
//         004809df     NOP
    return 0;
}

uchar RGE_Random_Map_Module::add_module(RGE_Random_Map_Module* param_1) {
    /* TODO: Stub */
//                              uchar __thiscall add_module(RGE_Random_Map_Module * this, RGE_Random
//              uchar             AL:1           <RETURN>
//              RGE_Random_Map    ECX:4 (auto)   this
//              RGE_Random_Map    Stack[0x4]:4   param_1                   XREF[1]:     004809e2(R)
//                               ?add_module@RGE_Random_Map_Module@@IAEEPAV1@@Z               XREF[1]:     RGE_Random_Map_Module:00480818(c)
//                               RGE_Random_Map_Module::add_module
//                              rmm_base.cpp:154 (2)
//         004809e0     PUSH       ESI
//         004809e1     PUSH       EDI
//                              rmm_base.cpp:157 (10)
//         004809e2     MOV        EDI,dword ptr [ESP + param_1]
//         004809e6     MOV        ESI,this
//         004809e8     TEST       EDI,EDI
//         004809ea     JNZ        LAB_004809f3
//                              rmm_base.cpp:158 (2)
//         004809ec     XOR        AL,AL
//                              rmm_base.cpp:169 (5)
//         004809ee     POP        EDI
//         004809ef     POP        ESI
//         004809f0     RET        0x4
//                               LAB_004809f3                                                 XREF[1]:     004809ea(j)
//                              rmm_base.cpp:161 (9)
//         004809f3     PUSH       0x8
//         004809f5     PUSH       0x1
//         004809f7     CALL       calloc                                           undefined calloc()
//                              rmm_base.cpp:164 (9)
//         004809fc     MOV        this,dword ptr [ESI + 0x8]
//         004809ff     ADD        ESP,0x8
//         00480a02     MOV        dword ptr [EAX + 0x4],this
//                              rmm_base.cpp:165 (2)
//         00480a05     MOV        dword ptr [EAX],EDI
//                              rmm_base.cpp:166 (3)
//         00480a07     MOV        dword ptr [ESI + 0x8],EAX
//                              rmm_base.cpp:169 (7)
//         00480a0a     POP        EDI
//         00480a0b     MOV        AL,0x1
//         00480a0d     POP        ESI
//         00480a0e     RET        0x4
//         00480a11     ??         90h
//         00480a12     NOP
//         00480a13     NOP
//         00480a14     NOP
//         00480a15     NOP
//         00480a16     NOP
//         00480a17     NOP
//         00480a18     NOP
//         00480a19     NOP
//         00480a1a     NOP
//         00480a1b     NOP
//         00480a1c     NOP
//         00480a1d     NOP
//         00480a1e     NOP
//         00480a1f     NOP
    return 0;
}

uchar RGE_Random_Map_Module::remove_module(RGE_Random_Map_Module* param_1) {
    /* TODO: Stub */
//                              uchar __thiscall remove_module(RGE_Random_Map_Module * this, RGE_Ran
//              uchar             AL:1           <RETURN>
//              RGE_Random_Map    ECX:4 (auto)   this
//              RGE_Random_Map    Stack[0x4]:4   param_1                   XREF[1]:     00480a2b(R)
//                               ?remove_module@RGE_Random_Map_Module@@IAEEPAV1@@Z            XREF[1]:     ~RGE_Random_Map_Module:00480890(c)
//                               RGE_Random_Map_Module::remove_module
//                              rmm_base.cpp:174 (11)
//         00480a20     MOV        EAX,dword ptr [ECX + this->list]
//         00480a23     XOR        EDX,EDX
//         00480a25     PUSH       ESI
//         00480a26     PUSH       EDI
//         00480a27     TEST       EAX,EAX
//         00480a29     JZ         LAB_00480a5f
//                              rmm_base.cpp:180 (10)
//         00480a2b     MOV        ESI,dword ptr [ESP + param_1]
//         00480a2f     MOV        EDI,dword ptr [EAX]
//         00480a31     CMP        EDI,ESI
//         00480a33     JNZ        LAB_00480a3f
//                              rmm_base.cpp:182 (2)
//         00480a35     MOV        EDX,EAX
//                              rmm_base.cpp:183 (6)
//         00480a37     MOV        EAX,dword ptr [EDX + 0x4]
//         00480a3a     MOV        dword ptr [ECX + this->list],EAX
//                              rmm_base.cpp:185 (2)
//         00480a3d     JMP        LAB_00480a5f
//                               LAB_00480a3f                                                 XREF[1]:     00480a33(j)
//                              rmm_base.cpp:189 (10)
//         00480a3f     MOV        this,dword ptr [EAX + 0x4]
//         00480a42     ADD        EAX,0x4
//         00480a45     TEST       this,this
//         00480a47     JZ         LAB_00480a5f
//                               LAB_00480a49                                                 XREF[1]:     00480a5d(j)
//                              rmm_base.cpp:191 (4)
//         00480a49     CMP        dword ptr [this->_padding_],ESI
//         00480a4b     JNZ        LAB_00480a54
//                              rmm_base.cpp:193 (2)
//         00480a4d     MOV        EDX,this
//                              rmm_base.cpp:194 (16)
//         00480a4f     MOV        this,dword ptr [EDX + 0x4]
//         00480a52     MOV        dword ptr [EAX],this
//                               LAB_00480a54                                                 XREF[1]:     00480a4b(j)
//         00480a54     MOV        EAX,dword ptr [EAX]
//         00480a56     ADD        EAX,0x4
//         00480a59     MOV        this,dword ptr [EAX]
//         00480a5b     TEST       this,this
//         00480a5d     JNZ        LAB_00480a49
//                               LAB_00480a5f                                                 XREF[3]:     00480a29(j), 00480a3d(j),
//                                                                                                         00480a47(j)
//                              rmm_base.cpp:200 (4)
//         00480a5f     TEST       EDX,EDX
//         00480a61     JZ         LAB_00480a73
//                              rmm_base.cpp:201 (9)
//         00480a63     PUSH       EDX
//         00480a64     CALL       free                                             undefined free()
//         00480a69     ADD        ESP,0x4
//                              rmm_base.cpp:205 (2)
//         00480a6c     MOV        AL,0x1
//                              rmm_base.cpp:206 (12)
//         00480a6e     POP        EDI
//         00480a6f     POP        ESI
//         00480a70     RET        0x4
//                               LAB_00480a73                                                 XREF[1]:     00480a61(j)
//         00480a73     POP        EDI
//         00480a74     XOR        AL,AL
//         00480a76     POP        ESI
//         00480a77     RET        0x4
//         00480a7a     ??         90h
//         00480a7b     NOP
//         00480a7c     NOP
//         00480a7d     NOP
//         00480a7e     NOP
//         00480a7f     NOP
    return 0;
}

void RGE_Random_Map_Module::create_shared_resources() {
    /* TODO: Stub */
//                              void __thiscall create_shared_resources(RGE_Random_Map_Module * this)
//              void              <VOID>         <RETURN>
//              RGE_Random_Map    ECX:4 (auto)   this
//                               ?create_shared_resources@RGE_Random_Map_Module@@IAEXXZ       XREF[2]:     RGE_Random_Map_Module:00480809(c),
//                               RGE_Random_Map_Module::create_shared_resources                            init:0048356d(c)
//                              rmm_base.cpp:211 (4)
//         00480a80     PUSH       ESI
//         00480a81     MOV        ESI,this
//         00480a83     PUSH       EDI
//                              rmm_base.cpp:216 (15)
//         00480a84     PUSH       0x1
//         00480a86     MOV        EAX,dword ptr [ESI + 0x18]
//         00480a89     IMUL       EAX,dword ptr [ESI + 0x14]
//         00480a8d     PUSH       EAX
//         00480a8e     CALL       calloc                                           undefined calloc()
//                              rmm_base.cpp:217 (17)
//         00480a93     MOV        this,dword ptr [ESI + 0x18]
//         00480a96     ADD        ESP,0x8
//         00480a99     MOV        dword ptr [ESI + 0x20],EAX
//         00480a9c     PUSH       0x4
//         00480a9e     PUSH       this
//         00480a9f     CALL       calloc                                           undefined calloc()
//                              rmm_base.cpp:218 (15)
//         00480aa4     MOV        this,dword ptr [ESI + 0x18]
//         00480aa7     MOV        dword ptr [ESI + 0x24],EAX
//         00480aaa     ADD        ESP,0x8
//         00480aad     XOR        EAX,EAX
//         00480aaf     TEST       this,this
//         00480ab1     JLE        LAB_00480acc
//                               LAB_00480ab3                                                 XREF[1]:     00480aca(j)
//                              rmm_base.cpp:219 (25)
//         00480ab3     MOV        EDX,EAX
//         00480ab5     MOV        EDI,dword ptr [ESI + 0x20]
//         00480ab8     IMUL       EDX,dword ptr [ESI + 0x14]
//         00480abc     MOV        this,dword ptr [ESI + 0x24]
//         00480abf     ADD        EDX,EDI
//         00480ac1     MOV        dword ptr [this->_padding_ + EAX*0x4],EDX
//         00480ac4     MOV        this,dword ptr [ESI + 0x18]
//         00480ac7     INC        EAX
//         00480ac8     CMP        EAX,this
//         00480aca     JL         LAB_00480ab3
//                               LAB_00480acc                                                 XREF[1]:     00480ab1(j)
//                              rmm_base.cpp:222 (21)
//         00480acc     MOV        EDX,dword ptr [ESI + 0x18]
//         00480acf     PUSH       0x18
//         00480ad1     IMUL       EDX,dword ptr [ESI + 0x14]
//         00480ad5     PUSH       EDX
//         00480ad6     CALL       calloc                                           undefined calloc()
//         00480adb     ADD        ESP,0x8
//         00480ade     MOV        dword ptr [ESI + 0x28],EAX
//                              rmm_base.cpp:223 (14)
//         00480ae1     MOV        EAX,dword ptr [ESI + 0x18]
//         00480ae4     PUSH       0x4
//         00480ae6     PUSH       EAX
//         00480ae7     CALL       calloc                                           undefined calloc()
//         00480aec     MOV        dword ptr [ESI + 0x2c],EAX
//                              rmm_base.cpp:224 (12)
//         00480aef     MOV        EAX,dword ptr [ESI + 0x18]
//         00480af2     ADD        ESP,0x8
//         00480af5     XOR        this,this
//         00480af7     TEST       EAX,EAX
//         00480af9     JLE        LAB_00480b19
//                               LAB_00480afb                                                 XREF[1]:     00480b17(j)
//                              rmm_base.cpp:225 (30)
//         00480afb     MOV        EAX,this
//         00480afd     IMUL       EAX,dword ptr [ESI + 0x14]
//         00480b01     INC        this
//         00480b02     LEA        EDX,[EAX + EAX*0x2]
//         00480b05     MOV        EAX,dword ptr [ESI + 0x28]
//         00480b08     LEA        EDX,[EAX + EDX*0x8]
//         00480b0b     MOV        EAX,dword ptr [ESI + 0x2c]
//         00480b0e     MOV        dword ptr [EAX + this->_padding_*0x4 + -0x4],EDX
//         00480b12     MOV        EAX,dword ptr [ESI + 0x18]
//         00480b15     CMP        this,EAX
//         00480b17     JL         LAB_00480afb
//                               LAB_00480b19                                                 XREF[1]:     00480af9(j)
//                              rmm_base.cpp:228 (9)
//         00480b19     MOV        EAX,dword ptr [ESI + 0x18]
//         00480b1c     XOR        EDX,EDX
//         00480b1e     TEST       EAX,EAX
//         00480b20     JLE        LAB_00480b54
//                               LAB_00480b22                                                 XREF[1]:     00480b52(j)
//                              rmm_base.cpp:229 (11)
//         00480b22     MOV        EAX,dword ptr [ESI + 0x14]
//         00480b25     XOR        this,this
//         00480b27     TEST       EAX,EAX
//         00480b29     JLE        LAB_00480b4c
//         00480b2b     XOR        EAX,EAX
//                               LAB_00480b2d                                                 XREF[1]:     00480b4a(j)
//                              rmm_base.cpp:231 (13)
//         00480b2d     MOV        EDI,dword ptr [ESI + 0x2c]
//         00480b30     ADD        EAX,0x18
//         00480b33     MOV        EDI,dword ptr [EDI + EDX*0x4]
//         00480b36     MOV        dword ptr [EDI + EAX*0x1 + -0x18],this
//                              rmm_base.cpp:232 (18)
//         00480b3a     MOV        EDI,dword ptr [ESI + 0x2c]
//         00480b3d     INC        this
//         00480b3e     MOV        EDI,dword ptr [EDI + EDX*0x4]
//         00480b41     MOV        dword ptr [EDI + EAX*0x1 + -0x14],EDX
//         00480b45     MOV        EDI,dword ptr [ESI + 0x14]
//         00480b48     CMP        this,EDI
//         00480b4a     JL         LAB_00480b2d
//                               LAB_00480b4c                                                 XREF[1]:     00480b29(j)
//                              rmm_base.cpp:228 (8)
//         00480b4c     MOV        EAX,dword ptr [ESI + 0x18]
//         00480b4f     INC        EDX
//         00480b50     CMP        EDX,EAX
//         00480b52     JL         LAB_00480b22
//                               LAB_00480b54                                                 XREF[1]:     00480b20(j)
//                              rmm_base.cpp:234 (3)
//         00480b54     POP        EDI
//         00480b55     POP        ESI
//         00480b56     RET
//         00480b57     ??         90h
//         00480b58     NOP
//         00480b59     NOP
//         00480b5a     NOP
//         00480b5b     NOP
//         00480b5c     NOP
//         00480b5d     NOP
//         00480b5e     NOP
//         00480b5f     NOP
    return;
}

void RGE_Random_Map_Module::destroy_shared_resources() {
    /* TODO: Stub */
//                              void __thiscall destroy_shared_resources(RGE_Random_Map_Module * this)
//              void              <VOID>         <RETURN>
//              RGE_Random_Map    ECX:4 (auto)   this
//                               ?destroy_shared_resources@RGE_Random_Map_Module@@IAEXXZ      XREF[2]:     ~RGE_Random_Map_Module:0048087a(c)
//                               RGE_Random_Map_Module::destroy_shared_resources                           de_init:004835e0(c)
//                              rmm_base.cpp:239 (4)
//         00480b60     PUSH       ESI
//         00480b61     MOV        ESI,this
//         00480b63     PUSH       EDI
//                              rmm_base.cpp:240 (9)
//         00480b64     XOR        EDI,EDI
//         00480b66     MOV        EAX,dword ptr [ESI + 0x20]
//         00480b69     CMP        EAX,EDI
//         00480b6b     JZ         LAB_00480b76
//                              rmm_base.cpp:241 (9)
//         00480b6d     PUSH       EAX
//         00480b6e     CALL       free                                             undefined free()
//         00480b73     ADD        ESP,0x4
//                               LAB_00480b76                                                 XREF[1]:     00480b6b(j)
//                              rmm_base.cpp:244 (10)
//         00480b76     MOV        EAX,dword ptr [ESI + 0x24]
//         00480b79     MOV        dword ptr [ESI + 0x20],EDI
//         00480b7c     CMP        EAX,EDI
//         00480b7e     JZ         LAB_00480b89
//                              rmm_base.cpp:245 (9)
//         00480b80     PUSH       EAX
//         00480b81     CALL       free                                             undefined free()
//         00480b86     ADD        ESP,0x4
//                               LAB_00480b89                                                 XREF[1]:     00480b7e(j)
//                              rmm_base.cpp:248 (10)
//         00480b89     MOV        EAX,dword ptr [ESI + 0x28]
//         00480b8c     MOV        dword ptr [ESI + 0x24],EDI
//         00480b8f     CMP        EAX,EDI
//         00480b91     JZ         LAB_00480b9c
//                              rmm_base.cpp:249 (9)
//         00480b93     PUSH       EAX
//         00480b94     CALL       free                                             undefined free()
//         00480b99     ADD        ESP,0x4
//                               LAB_00480b9c                                                 XREF[1]:     00480b91(j)
//                              rmm_base.cpp:252 (10)
//         00480b9c     MOV        EAX,dword ptr [ESI + 0x2c]
//         00480b9f     MOV        dword ptr [ESI + 0x28],EDI
//         00480ba2     CMP        EAX,EDI
//         00480ba4     JZ         LAB_00480baf
//                              rmm_base.cpp:253 (9)
//         00480ba6     PUSH       EAX
//         00480ba7     CALL       free                                             undefined free()
//         00480bac     ADD        ESP,0x4
//                               LAB_00480baf                                                 XREF[1]:     00480ba4(j)
//                              rmm_base.cpp:254 (3)
//         00480baf     MOV        dword ptr [ESI + 0x2c],EDI
//                              rmm_base.cpp:255 (3)
//         00480bb2     POP        EDI
//         00480bb3     POP        ESI
//         00480bb4     RET
//         00480bb5     ??         90h
//         00480bb6     NOP
//         00480bb7     NOP
//         00480bb8     NOP
//         00480bb9     NOP
//         00480bba     NOP
//         00480bbb     NOP
//         00480bbc     NOP
//         00480bbd     NOP
//         00480bbe     NOP
//         00480bbf     NOP
    return;
}

void RGE_Random_Map_Module::update_child_resources() {
    /* TODO: Stub */
//                              void __thiscall update_child_resources(RGE_Random_Map_Module * this)
//              void              <VOID>         <RETURN>
//              RGE_Random_Map    ECX:4 (auto)   this
//                               ?update_child_resources@RGE_Random_Map_Module@@IAEXXZ        XREF[1]:     update_resources:00480bfd(c)
//                               RGE_Random_Map_Module::update_child_resources
//                              rmm_base.cpp:260 (1)
//         00480bc0     PUSH       ESI
//                              rmm_base.cpp:265 (7)
//         00480bc1     MOV        ESI,dword ptr [ECX + this->list]
//         00480bc4     TEST       ESI,ESI
//         00480bc6     JZ         LAB_00480bd6
//                               LAB_00480bc8                                                 XREF[1]:     00480bd4(j)
//                              rmm_base.cpp:266 (14)
//         00480bc8     MOV        this,dword ptr [ESI]
//         00480bca     CALL       RGE_Random_Map_Module::update_resources          void update_resources(RGE_Random_Map_Module *
//         00480bcf     MOV        ESI,dword ptr [ESI + 0x4]
//         00480bd2     TEST       ESI,ESI
//         00480bd4     JNZ        LAB_00480bc8
//                               LAB_00480bd6                                                 XREF[1]:     00480bc6(j)
//                              rmm_base.cpp:267 (2)
//         00480bd6     POP        ESI
//         00480bd7     RET
//         00480bd8     ??         90h
//         00480bd9     NOP
//         00480bda     NOP
//         00480bdb     NOP
//         00480bdc     NOP
//         00480bdd     NOP
//         00480bde     NOP
//         00480bdf     NOP
    return;
}

void RGE_Random_Map_Module::update_resources() {
    /* TODO: Stub */
//                              void __thiscall update_resources(RGE_Random_Map_Module * this)
//              void              <VOID>         <RETURN>
//              RGE_Random_Map    ECX:4 (auto)   this
//                               ?update_resources@RGE_Random_Map_Module@@IAEXXZ              XREF[1]:     update_child_resources:00480bca(c)
//                               RGE_Random_Map_Module::update_resources
//                              rmm_base.cpp:272 (3)
//         00480be0     PUSH       ESI
//         00480be1     MOV        ESI,this
//                              rmm_base.cpp:273 (24)
//         00480be3     LEA        EAX,[ESI + 0x2c]
//         00480be6     LEA        this,[ESI + 0x28]
//         00480be9     PUSH       EAX
//         00480bea     LEA        EDX,[ESI + 0x24]
//         00480bed     PUSH       this
//         00480bee     MOV        this,dword ptr [ESI + 0x4]
//         00480bf1     LEA        EAX,[ESI + 0x20]
//         00480bf4     PUSH       EDX
//         00480bf5     PUSH       EAX
//         00480bf6     CALL       RGE_Random_Map_Module::share_resources           void share_resources(RGE_Random_Map_Module *
//                              rmm_base.cpp:274 (7)
//         00480bfb     MOV        this,ESI
//         00480bfd     CALL       RGE_Random_Map_Module::update_child_resources    void update_child_resources(RGE_Random_Map_Mo
//                              rmm_base.cpp:275 (2)
//         00480c02     POP        ESI
//         00480c03     RET
//         00480c04     ??         90h
//         00480c05     NOP
//         00480c06     NOP
//         00480c07     NOP
//         00480c08     NOP
//         00480c09     NOP
//         00480c0a     NOP
//         00480c0b     NOP
//         00480c0c     NOP
//         00480c0d     NOP
//         00480c0e     NOP
//         00480c0f     NOP
    return;
}

void RGE_Random_Map_Module::update_child_map_info() {
    /* TODO: Stub */
//                              void __thiscall update_child_map_info(RGE_Random_Map_Module * this)
//              void              <VOID>         <RETURN>
//              RGE_Random_Map    ECX:4 (auto)   this
//                               ?update_child_map_info@RGE_Random_Map_Module@@IAEXXZ         XREF[2]:     update_map_info:00480c60(c),
//                               RGE_Random_Map_Module::update_child_map_info                              update_map_info:00480c74(c)
//                              rmm_base.cpp:280 (4)
//         00480c10     PUSH       ESI
//         00480c11     PUSH       EDI
//         00480c12     MOV        EDI,this
//                              rmm_base.cpp:285 (7)
//         00480c14     MOV        ESI,dword ptr [EDI + 0x8]
//         00480c17     TEST       ESI,ESI
//         00480c19     JZ         LAB_00480c2d
//                               LAB_00480c1b                                                 XREF[1]:     00480c2b(j)
//                              rmm_base.cpp:286 (18)
//         00480c1b     MOV        EAX,dword ptr [EDI + 0xc]
//         00480c1e     MOV        this,dword ptr [ESI]
//         00480c20     PUSH       EAX
//         00480c21     CALL       RGE_Random_Map_Module::update_map_info           void update_map_info(RGE_Random_Map_Module *
//         00480c26     MOV        ESI,dword ptr [ESI + 0x4]
//         00480c29     TEST       ESI,ESI
//         00480c2b     JNZ        LAB_00480c1b
//                               LAB_00480c2d                                                 XREF[1]:     00480c19(j)
//                              rmm_base.cpp:287 (3)
//         00480c2d     POP        EDI
//         00480c2e     POP        ESI
//         00480c2f     RET
    return;
}

void RGE_Random_Map_Module::update_map_info(RGE_Map* param_1) {
    /* TODO: Stub */
//                              void __thiscall update_map_info(RGE_Random_Map_Module * this, RGE_Ma
//              void              <VOID>         <RETURN>
//              RGE_Random_Map    ECX:4 (auto)   this
//              RGE_Map *         Stack[0x4]:4   param_1                   XREF[1]:     00480c33(R)
//                               ?update_map_info@RGE_Random_Map_Module@@IAEXPAVRGE_Map@@@Z   XREF[3]:     update_child_map_info:00480c21(c),
//                               RGE_Random_Map_Module::update_map_info                                    init:00483566(c),
//                                                                                                         de_init:004835e9(c)
//                              rmm_base.cpp:292 (3)
//         00480c30     PUSH       ESI
//         00480c31     MOV        ESI,this
//                              rmm_base.cpp:293 (4)
//         00480c33     MOV        this,dword ptr [ESP + param_1]
//                              rmm_base.cpp:295 (9)
//         00480c37     XOR        EAX,EAX
//         00480c39     CMP        this,EAX
//         00480c3b     MOV        dword ptr [ESI + 0xc],this
//         00480c3e     JZ         LAB_00480c69
//                              rmm_base.cpp:297 (5)
//         00480c40     CALL       RGE_Map::give_up_map_offsets                     RGE_Tile * * give_up_map_offsets(RGE_Map * th
//                              rmm_base.cpp:298 (11)
//         00480c45     MOV        this,dword ptr [ESI + 0xc]
//         00480c48     MOV        dword ptr [ESI + 0x10],EAX
//         00480c4b     CALL       RGE_Map::get_map_width                           long get_map_width(RGE_Map * this)
//                              rmm_base.cpp:299 (11)
//         00480c50     MOV        this,dword ptr [ESI + 0xc]
//         00480c53     MOV        dword ptr [ESI + 0x14],EAX
//         00480c56     CALL       RGE_Map::get_map_height                          long get_map_height(RGE_Map * this)
//                              rmm_base.cpp:308 (10)
//         00480c5b     MOV        this,ESI
//         00480c5d     MOV        dword ptr [ESI + 0x18],EAX
//         00480c60     CALL       RGE_Random_Map_Module::update_child_map_info     void update_child_map_info(RGE_Random_Map_Mod
//                              rmm_base.cpp:309 (4)
//         00480c65     POP        ESI
//         00480c66     RET        0x4
//                               LAB_00480c69                                                 XREF[1]:     00480c3e(j)
//                              rmm_base.cpp:308 (16)
//         00480c69     MOV        this,ESI
//         00480c6b     MOV        dword ptr [ESI + 0x10],EAX
//         00480c6e     MOV        dword ptr [ESI + 0x14],EAX
//         00480c71     MOV        dword ptr [ESI + 0x18],EAX
//         00480c74     CALL       RGE_Random_Map_Module::update_child_map_info     void update_child_map_info(RGE_Random_Map_Mod
//                              rmm_base.cpp:309 (4)
//         00480c79     POP        ESI
//         00480c7a     RET        0x4
//         00480c7d     ??         90h
//         00480c7e     NOP
//         00480c7f     NOP
    return;
}

void RGE_Random_Map_Module::share_resources(uchar** param_1, uchar*** param_2, Map_Stack** param_3, Map_Stack*** param_4) {
    /* TODO: Stub */
//                              void __thiscall share_resources(RGE_Random_Map_Module * this, uchar
//              void              <VOID>         <RETURN>
//              RGE_Random_Map    ECX:4 (auto)   this
//              uchar * *         Stack[0x4]:4   param_1                   XREF[1]:     00480c80(R)
//              uchar * * *       Stack[0x8]:4   param_2                   XREF[1]:     00480c8d(R)
//              Map_Stack * *     Stack[0xc]:4   param_3                   XREF[1]:     00480c9a(R)
//              Map_Stack * * *   Stack[0x10]:4  param_4                   XREF[1]:     00480ca7(R)
//                               ?share_resources@RGE_Random_Map_Module@@IAEXPAPAEPAPAPAEPAP  XREF[2]:     RGE_Random_Map_Module:00480827(c),
//                               RGE_Random_Map_Module::share_resources                                    update_resources:00480bf6(c)
//                              rmm_base.cpp:314 (8)
//         00480c80     MOV        EAX,dword ptr [ESP + param_1]
//         00480c84     TEST       EAX,EAX
//         00480c86     JZ         LAB_00480c8d
//                              rmm_base.cpp:316 (5)
//         00480c88     MOV        EDX,dword ptr [ECX + this->search_map]
//         00480c8b     MOV        dword ptr [EAX],EDX
//                               LAB_00480c8d                                                 XREF[1]:     00480c86(j)
//                              rmm_base.cpp:318 (8)
//         00480c8d     MOV        EAX,dword ptr [ESP + param_2]
//         00480c91     TEST       EAX,EAX
//         00480c93     JZ         LAB_00480c9a
//                              rmm_base.cpp:319 (5)
//         00480c95     MOV        EDX,dword ptr [ECX + this->search_map_rows]
//         00480c98     MOV        dword ptr [EAX],EDX
//                               LAB_00480c9a                                                 XREF[1]:     00480c93(j)
//                              rmm_base.cpp:321 (8)
//         00480c9a     MOV        EAX,dword ptr [ESP + param_3]
//         00480c9e     TEST       EAX,EAX
//         00480ca0     JZ         LAB_00480ca7
//                              rmm_base.cpp:322 (5)
//         00480ca2     MOV        EDX,dword ptr [ECX + this->stack_array]
//         00480ca5     MOV        dword ptr [EAX],EDX
//                               LAB_00480ca7                                                 XREF[1]:     00480ca0(j)
//                              rmm_base.cpp:324 (8)
//         00480ca7     MOV        EAX,dword ptr [ESP + param_4]
//         00480cab     TEST       EAX,EAX
//         00480cad     JZ         LAB_00480cb4
//                              rmm_base.cpp:325 (5)
//         00480caf     MOV        this,dword ptr [ECX + this->stack_offsets]
//         00480cb2     MOV        dword ptr [EAX],this
//                               LAB_00480cb4                                                 XREF[1]:     00480cad(j)
//                              rmm_base.cpp:326 (3)
//         00480cb4     RET        0x10
//         00480cb7     ??         90h
//         00480cb8     NOP
//         00480cb9     NOP
//         00480cba     NOP
//         00480cbb     NOP
//         00480cbc     NOP
//         00480cbd     NOP
//         00480cbe     NOP
//         00480cbf     NOP
    return;
}

void RGE_Random_Map_Module::init_stack(Map_Stack* param_1) {
    /* TODO: Stub */
//                              void __thiscall init_stack(RGE_Random_Map_Module * this, Map_Stack *
//              void              <VOID>         <RETURN>
//              RGE_Random_Map    ECX:4 (auto)   this
//              Map_Stack *       Stack[0x4]:4   param_1                   XREF[1]:     00480cc0(R)
//                               ?init_stack@RGE_Random_Map_Module@@IAEXAAUMap_Stack@@@Z      XREF[13]:    randomize_stack:00480ed8(c),
//                               RGE_Random_Map_Module::init_stack                                         find_path:00480fbc(c),
//                                                                                                         setup_cliff_maps:00481a55(c),
//                                                                                                         generate_cliff:00481d3c(c),
//                                                                                                         base_elevation_generate:00484d34(c
//                                                                                                         base_land_generate:00485579(c),
//                                                                                                         place_avoid_objects:00486315(c),
//                                                                                                         place_objects:0048651d(c),
//                                                                                                         place_land_objects:004867b2(c),
//                                                                                                         place_group:00486a72(c),
//                                                                                                         place_cluster:00486c58(c),
//                                                                                                         make_tribe_connections:00487256(c)
//                                                                                                         base_terrain_generate:004890ab(c)
//                              rmm_base.cpp:331 (4)
//         00480cc0     MOV        EAX,dword ptr [ESP + param_1]
//                              rmm_base.cpp:334 (18)
//         00480cc4     XOR        this,this
//         00480cc6     MOV        dword ptr [EAX],0xffffffff
//         00480ccc     MOV        dword ptr [EAX + 0x4],0xffffffff
//         00480cd3     MOV        dword ptr [EAX + 0x10],this
//                              rmm_base.cpp:335 (3)
//         00480cd6     MOV        dword ptr [EAX + 0x14],this
//                              rmm_base.cpp:336 (3)
//         00480cd9     MOV        dword ptr [EAX + 0x8],this
//                              rmm_base.cpp:337 (3)
//         00480cdc     MOV        dword ptr [EAX + 0xc],this
//                              rmm_base.cpp:338 (3)
//         00480cdf     RET        0x4
//         00480ce2     ??         90h
//         00480ce3     NOP
//         00480ce4     NOP
//         00480ce5     NOP
//         00480ce6     NOP
//         00480ce7     NOP
//         00480ce8     NOP
//         00480ce9     NOP
//         00480cea     NOP
//         00480ceb     NOP
//         00480cec     NOP
//         00480ced     NOP
//         00480cee     NOP
//         00480cef     NOP
    return;
}

void RGE_Random_Map_Module::deinit_stack(Map_Stack* param_1) {
    /* TODO: Stub */
//                              void __thiscall deinit_stack(RGE_Random_Map_Module * this, Map_Stack
//              void              <VOID>         <RETURN>
//              RGE_Random_Map    ECX:4 (auto)   this
//              Map_Stack *       Stack[0x4]:4   param_1                   XREF[1]:     00480cf0(R)
//                               ?deinit_stack@RGE_Random_Map_Module@@IAEXAAUMap_Stack@@@Z    XREF[10]:    find_path:00480fef(c),
//                               RGE_Random_Map_Module::deinit_stack                                       base_elevation_generate:004851df(c
//                                                                                                         base_land_generate:00485c12(c),
//                                                                                                         place_avoid_objects:004864d9(c),
//                                                                                                         place_objects:004866e4(c),
//                                                                                                         place_land_objects:00486a48(c),
//                                                                                                         place_group:00486c24(c),
//                                                                                                         place_cluster:00486fff(c),
//                                                                                                         make_tribe_connections:00487682(c)
//                                                                                                         base_terrain_generate:004898b2(c)
//                              rmm_base.cpp:343 (13)
//         00480cf0     MOV        this,dword ptr [ESP + param_1]
//         00480cf4     XOR        EDX,EDX
//         00480cf6     MOV        EAX,dword ptr [ECX + this->map_row_offset]
//         00480cf9     CMP        EAX,EDX
//         00480cfb     JZ         LAB_00480d03
//                              rmm_base.cpp:346 (3)
//         00480cfd     MOV        dword ptr [EAX + 0x14],EDX
//                              rmm_base.cpp:347 (3)
//         00480d00     MOV        dword ptr [ECX + this->map_row_offset],EDX
//                               LAB_00480d03                                                 XREF[1]:     00480cfb(j)
//                              rmm_base.cpp:349 (3)
//         00480d03     RET        0x4
//         00480d06     ??         90h
//         00480d07     NOP
//         00480d08     NOP
//         00480d09     NOP
//         00480d0a     NOP
//         00480d0b     NOP
//         00480d0c     NOP
//         00480d0d     NOP
//         00480d0e     NOP
//         00480d0f     NOP
    return;
}

void RGE_Random_Map_Module::push_stack(Map_Stack* param_1, long param_2, long param_3, float param_4, float param_5) {
    /* TODO: Stub */
//                              void __thiscall push_stack(RGE_Random_Map_Module * this, Map_Stack *
//              void              <VOID>         <RETURN>
//              RGE_Random_Map    ECX:4 (auto)   this
//              Map_Stack *       Stack[0x4]:4   param_1                   XREF[1]:     00480d30(R)
//              long              Stack[0x8]:4   param_2                   XREF[1]:     00480d10(R)
//              long              Stack[0xc]:4   param_3                   XREF[1]:     00480d1b(R)
//              float             Stack[0x10]:4  param_4                   XREF[2]:     00480d69(R), 00480d85(R)
//              float             Stack[0x14]:4  param_5                   XREF[4]:     00480d3e(R), 00480d55(R), 00480d6d(R), 00480d89(R)
//                               ?push_stack@RGE_Random_Map_Module@@IAEXAAUMap_Stack@@JJMM@Z  XREF[48]:    find_path:00481179(c),
//                               RGE_Random_Map_Module::push_stack                                         find_path:00481252(c),
//                                                                                                         find_path:0048133c(c),
//                                                                                                         find_path:0048143c(c),
//                                                                                                         find_path:0048152f(c),
//                                                                                                         find_path:004815f9(c),
//                                                                                                         find_path:004816e4(c),
//                                                                                                         find_path:004817ae(c),
//                                                                                                         base_elevation_generate:00484e42(c
//                                                                                                         base_land_generate:00485675(c),
//                                                                                                         base_land_generate:004856b6(c),
//                                                                                                         base_land_generate:004856f3(c),
//                                                                                                         base_land_generate:00485728(c),
//                                                                                                         base_land_generate:0048592a(c),
//                                                                                                         base_land_generate:004859b1(c),
//                                                                                                         base_land_generate:00485a30(c),
//                                                                                                         base_land_generate:00485ab1(c),
//                                                                                                         place_cluster:00486ed4(c),
//                                                                                                         place_cluster:00486f2c(c),
//                                                                                                         place_cluster:00486f7e(c), [more]
//                              rmm_base.cpp:355 (24)
//         00480d10     MOV        EAX,dword ptr [ESP + param_2]
//         00480d14     PUSH       ESI
//         00480d15     PUSH       EDI
//         00480d16     MOV        EDI,this
//         00480d18     LEA        EDX,[EAX + EAX*0x2]
//         00480d1b     MOV        EAX,dword ptr [ESP + param_3]
//         00480d1f     MOV        this,dword ptr [EDI + 0x2c]
//         00480d22     MOV        this,dword ptr [this->_padding_ + EAX*0x4]
//         00480d25     LEA        ESI,[this->_padding_ + EDX*0x8]
//                              rmm_base.cpp:365 (8)
//         00480d28     MOV        this,EDI
//         00480d2a     PUSH       ESI
//         00480d2b     CALL       RGE_Random_Map_Module::remove_stack_node         void remove_stack_node(RGE_Random_Map_Module
//                              rmm_base.cpp:368 (7)
//         00480d30     MOV        EDX,dword ptr [ESP + param_1]
//         00480d34     MOV        this,dword ptr [EDX + 0x10]
//                              rmm_base.cpp:369 (18)
//         00480d37     TEST       this,this
//         00480d39     JZ         LAB_00480d7c
//         00480d3b     FLD        float ptr [ECX + this->map]
//         00480d3e     FCOMP      float ptr [ESP + param_5]
//         00480d42     FNSTSW     AX
//         00480d44     TEST       AH,0x1
//         00480d47     JZ         LAB_00480d7c
//                               LAB_00480d49                                                 XREF[1]:     00480d5e(j)
//                              rmm_base.cpp:381 (2)
//         00480d49     MOV        EDX,this
//                              rmm_base.cpp:382 (3)
//         00480d4b     MOV        this,dword ptr [ECX + this->map_row_offset]
//                              rmm_base.cpp:383 (18)
//         00480d4e     TEST       this,this
//         00480d50     JZ         LAB_00480d60
//         00480d52     FLD        float ptr [ECX + this->map]
//         00480d55     FCOMP      float ptr [ESP + param_5]
//         00480d59     FNSTSW     AX
//         00480d5b     TEST       AH,0x1
//         00480d5e     JNZ        LAB_00480d49
//                               LAB_00480d60                                                 XREF[1]:     00480d50(j)
//                              rmm_base.cpp:385 (9)
//         00480d60     PUSH       ESI
//         00480d61     PUSH       EDX
//         00480d62     MOV        this,EDI
//         00480d64     CALL       RGE_Random_Map_Module::add_stack_node            void add_stack_node(RGE_Random_Map_Module * t
//                              rmm_base.cpp:386 (4)
//         00480d69     MOV        EDX,dword ptr [ESP + param_4]
//                              rmm_base.cpp:387 (10)
//         00480d6d     MOV        EAX,dword ptr [ESP + param_5]
//         00480d71     MOV        dword ptr [ESI + 0x8],EDX
//         00480d74     MOV        dword ptr [ESI + 0xc],EAX
//                              rmm_base.cpp:395 (5)
//         00480d77     POP        EDI
//         00480d78     POP        ESI
//         00480d79     RET        0x14
//                               LAB_00480d7c                                                 XREF[2]:     00480d39(j), 00480d47(j)
//                              rmm_base.cpp:372 (9)
//         00480d7c     PUSH       ESI
//         00480d7d     PUSH       EDX
//         00480d7e     MOV        this,EDI
//         00480d80     CALL       RGE_Random_Map_Module::add_stack_node            void add_stack_node(RGE_Random_Map_Module * t
//                              rmm_base.cpp:373 (4)
//         00480d85     MOV        this,dword ptr [ESP + param_4]
//                              rmm_base.cpp:374 (10)
//         00480d89     MOV        EDX,dword ptr [ESP + param_5]
//         00480d8d     MOV        dword ptr [ESI + 0x8],this
//         00480d90     MOV        dword ptr [ESI + 0xc],EDX
//                              rmm_base.cpp:395 (5)
//         00480d93     POP        EDI
//         00480d94     POP        ESI
//         00480d95     RET        0x14
//         00480d98     ??         90h
//         00480d99     NOP
//         00480d9a     NOP
//         00480d9b     NOP
//         00480d9c     NOP
//         00480d9d     NOP
//         00480d9e     NOP
//         00480d9f     NOP
    return;
}

Map_Stack* RGE_Random_Map_Module::pop_stack(Map_Stack* param_1, long* param_2, long* param_3, float* param_4) {
    /* TODO: Stub */
//                              Map_Stack * __thiscall pop_stack(RGE_Random_Map_Module * this, Map_S
//              Map_Stack *       EAX:4          <RETURN>
//              RGE_Random_Map    ECX:4 (auto)   this
//              Map_Stack *       Stack[0x4]:4   param_1                   XREF[1]:     00480da0(R)
//              long *            Stack[0x8]:4   param_2                   XREF[1]:     00480db2(R)
//              long *            Stack[0xc]:4   param_3                   XREF[1]:     00480dbb(R)
//              float *           Stack[0x10]:4  param_4                   XREF[1]:     00480dc4(R)
//                               ?pop_stack@RGE_Random_Map_Module@@IAEPAUMap_Stack@@AAU2@AAJ  XREF[25]:    find_path:004817d8(c),
//                               RGE_Random_Map_Module::pop_stack                                          generate_cliff:00481d59(c),
//                                                                                                         generate_cliff:00481f3c(c),
//                                                                                                         base_elevation_generate:00484da4(c
//                                                                                                         base_elevation_generate:00484f02(c
//                                                                                                         base_land_generate:004857c4(c),
//                                                                                                         base_land_generate:00485b40(c),
//                                                                                                         base_land_generate:00485bc6(c),
//                                                                                                         place_avoid_objects:00486362(c),
//                                                                                                         place_avoid_objects:004864c5(c),
//                                                                                                         place_objects:0048656e(c),
//                                                                                                         place_objects:004866d0(c),
//                                                                                                         place_land_objects:00486860(c),
//                                                                                                         place_land_objects:00486a34(c),
//                                                                                                         place_group:00486af5(c),
//                                                                                                         place_group:00486c10(c),
//                                                                                                         place_cluster:00486d71(c),
//                                                                                                         place_cluster:00486feb(c),
//                                                                                                         make_tribe_connections:00487634(c)
//                                                                                                         make_tribe_connections:00487672(c)
//                                                                                                         [more]
//                              rmm_base.cpp:400 (12)
//         00480da0     MOV        EAX,dword ptr [ESP + param_1]
//         00480da4     PUSH       ESI
//         00480da5     MOV        ESI,dword ptr [EAX + 0x10]
//         00480da8     TEST       ESI,ESI
//         00480daa     JNZ        LAB_00480db2
//                              rmm_base.cpp:404 (2)
//         00480dac     XOR        EAX,EAX
//                              rmm_base.cpp:414 (4)
//         00480dae     POP        ESI
//         00480daf     RET        0x10
//                               LAB_00480db2                                                 XREF[1]:     00480daa(j)
//                              rmm_base.cpp:408 (6)
//         00480db2     MOV        EAX,dword ptr [ESP + param_2]
//         00480db6     MOV        EDX,dword ptr [ESI]
//                              rmm_base.cpp:411 (26)
//         00480db8     PUSH       ESI
//         00480db9     MOV        dword ptr [EAX],EDX
//         00480dbb     MOV        EAX,dword ptr [ESP + param_3]
//         00480dbf     MOV        EDX,dword ptr [ESI + 0x4]
//         00480dc2     MOV        dword ptr [EAX],EDX
//         00480dc4     MOV        EAX,dword ptr [ESP + param_4]
//         00480dc8     MOV        EDX,dword ptr [ESI + 0x8]
//         00480dcb     MOV        dword ptr [EAX],EDX
//         00480dcd     CALL       RGE_Random_Map_Module::remove_stack_node         void remove_stack_node(RGE_Random_Map_Module
//                              rmm_base.cpp:413 (2)
//         00480dd2     MOV        EAX,ESI
//                              rmm_base.cpp:414 (4)
//         00480dd4     POP        ESI
//         00480dd5     RET        0x10
//         00480dd8     ??         90h
//         00480dd9     NOP
//         00480dda     NOP
//         00480ddb     NOP
//         00480ddc     NOP
//         00480ddd     NOP
//         00480dde     NOP
//         00480ddf     NOP
    return 0;
}

void RGE_Random_Map_Module::add_stack_node(Map_Stack* param_1, Map_Stack* param_2) {
    /* TODO: Stub */
//                              void __thiscall add_stack_node(RGE_Random_Map_Module * this, Map_Sta
//              void              <VOID>         <RETURN>
//              RGE_Random_Map    ECX:4 (auto)   this
//              Map_Stack *       Stack[0x4]:4   param_1                   XREF[1]:     00480df9(R)
//              Map_Stack *       Stack[0x8]:4   param_2                   XREF[1]:     00480de1(R)
//                               ?add_stack_node@RGE_Random_Map_Module@@IAEXPAUMap_Stack@@0@Z XREF[10]:    push_stack:00480d64(c),
//                               RGE_Random_Map_Module::add_stack_node                                     push_stack:00480d80(c),
//                                                                                                         randomize_stack:00480f35(c),
//                                                                                                         randomize_stack:00480f66(c),
//                                                                                                         randomize_stack:00480f75(c),
//                                                                                                         link_stack_randomly:00484c62(c),
//                                                                                                         make_placement_stack:00485ff5(c),
//                                                                                                         make_placement_stack:004860ed(c),
//                                                                                                         place_cluster:00486c79(c),
//                                                                                                         link_stack_randomly:00488f77(c)
//                              rmm_base.cpp:419 (1)
//         00480de0     PUSH       ESI
//                              rmm_base.cpp:420 (18)
//         00480de1     MOV        ESI,dword ptr [ESP + param_2]
//         00480de5     MOV        EAX,dword ptr [ESI + 0x10]
//         00480de8     TEST       EAX,EAX
//         00480dea     JNZ        LAB_00480df3
//         00480dec     MOV        EAX,dword ptr [ESI + 0x14]
//         00480def     TEST       EAX,EAX
//         00480df1     JZ         LAB_00480df9
//                               LAB_00480df3                                                 XREF[1]:     00480dea(j)
//                              rmm_base.cpp:421 (6)
//         00480df3     PUSH       ESI
//         00480df4     CALL       RGE_Random_Map_Module::remove_stack_node         void remove_stack_node(RGE_Random_Map_Module
//                               LAB_00480df9                                                 XREF[1]:     00480df1(j)
//                              rmm_base.cpp:423 (7)
//         00480df9     MOV        EAX,dword ptr [ESP + param_1]
//         00480dfd     MOV        this,dword ptr [EAX + 0x10]
//                              rmm_base.cpp:424 (6)
//         00480e00     MOV        dword ptr [ESI + 0x14],EAX
//         00480e03     MOV        dword ptr [ESI + 0x10],this
//                              rmm_base.cpp:426 (7)
//         00480e06     MOV        this,dword ptr [EAX + 0x10]
//         00480e09     TEST       this,this
//         00480e0b     JZ         LAB_00480e10
//                              rmm_base.cpp:427 (3)
//         00480e0d     MOV        dword ptr [ECX + this->map_width],ESI
//                               LAB_00480e10                                                 XREF[1]:     00480e0b(j)
//                              rmm_base.cpp:429 (3)
//         00480e10     MOV        dword ptr [EAX + 0x10],ESI
//                              rmm_base.cpp:430 (4)
//         00480e13     POP        ESI
//         00480e14     RET        0x8
//         00480e17     ??         90h
//         00480e18     NOP
//         00480e19     NOP
//         00480e1a     NOP
//         00480e1b     NOP
//         00480e1c     NOP
//         00480e1d     NOP
//         00480e1e     NOP
//         00480e1f     NOP
    return;
}

void RGE_Random_Map_Module::remove_stack_node(Map_Stack* param_1) {
    /* TODO: Stub */
//                              void __thiscall remove_stack_node(RGE_Random_Map_Module * this, Map_
//              void              <VOID>         <RETURN>
//              RGE_Random_Map    ECX:4 (auto)   this
//              Map_Stack *       Stack[0x4]:4   param_1                   XREF[1]:     00480e20(R)
//                               ?remove_stack_node@RGE_Random_Map_Module@@IAEXPAUMap_Stack@  XREF[8]:     push_stack:00480d2b(c),
//                               RGE_Random_Map_Module::remove_stack_node                                  pop_stack:00480dcd(c),
//                                                                                                         add_stack_node:00480df4(c),
//                                                                                                         setup_cliff_maps:00481c92(c),
//                                                                                                         invalidate_cliff_area:00482164(c),
//                                                                                                         remove_area_from_lists:00484cdd(c)
//                                                                                                         remove_area_from_lists:00486283(c)
//                                                                                                         remove_area_from_lists:00489003(c)
//                              rmm_base.cpp:434 (14)
//         00480e20     MOV        EAX,dword ptr [ESP + param_1]
//         00480e24     XOR        EDX,EDX
//         00480e26     PUSH       ESI
//         00480e27     MOV        this,dword ptr [EAX + 0x14]
//         00480e2a     CMP        this,EDX
//         00480e2c     JZ         LAB_00480e34
//                              rmm_base.cpp:436 (6)
//         00480e2e     MOV        ESI,dword ptr [EAX + 0x10]
//         00480e31     MOV        dword ptr [ECX + this->map_row_offset],ESI
//                               LAB_00480e34                                                 XREF[1]:     00480e2c(j)
//                              rmm_base.cpp:438 (7)
//         00480e34     MOV        this,dword ptr [EAX + 0x10]
//         00480e37     CMP        this,EDX
//         00480e39     JZ         LAB_00480e41
//                              rmm_base.cpp:439 (6)
//         00480e3b     MOV        ESI,dword ptr [EAX + 0x14]
//         00480e3e     MOV        dword ptr [ECX + this->map_width],ESI
//                               LAB_00480e41                                                 XREF[1]:     00480e39(j)
//                              rmm_base.cpp:441 (3)
//         00480e41     MOV        dword ptr [EAX + 0x10],EDX
//                              rmm_base.cpp:442 (3)
//         00480e44     MOV        dword ptr [EAX + 0x14],EDX
//                              rmm_base.cpp:443 (4)
//         00480e47     POP        ESI
//         00480e48     RET        0x4
//         00480e4b     ??         90h
//         00480e4c     NOP
//         00480e4d     NOP
//         00480e4e     NOP
//         00480e4f     NOP
    return;
}

void RGE_Random_Map_Module::clear_stack() {
    /* TODO: Stub */
//                              void __thiscall clear_stack(RGE_Random_Map_Module * this)
//              void              <VOID>         <RETURN>
//              RGE_Random_Map    ECX:4 (auto)   this
//                               ?clear_stack@RGE_Random_Map_Module@@IAEXXZ                   XREF[6]:     find_path:00481021(c),
//                               RGE_Random_Map_Module::clear_stack                                        setup_cliff_maps:00481a47(c),
//                                                                                                         generate:00484707(c),
//                                                                                                         generate:00485245(c),
//                                                                                                         generate:00485dfb(c),
//                                                                                                         generate:00487059(c)
//                              rmm_base.cpp:448 (13)
//         00480e50     MOV        EAX,dword ptr [ECX + this->map_height]
//         00480e53     PUSH       ESI
//         00480e54     PUSH       EDI
//         00480e55     XOR        ESI,ESI
//         00480e57     XOR        EDI,EDI
//         00480e59     CMP        EAX,ESI
//         00480e5b     JLE        LAB_00480e91
//                              rmm_base.cpp:448 (1)
//         00480e5d     PUSH       EBX
//                               LAB_00480e5e                                                 XREF[1]:     00480e8e(j)
//                              rmm_base.cpp:454 (11)
//         00480e5e     MOV        EAX,dword ptr [ECX + this->map_width]
//         00480e61     XOR        EDX,EDX
//         00480e63     CMP        EAX,ESI
//         00480e65     JLE        LAB_00480e88
//         00480e67     XOR        EAX,EAX
//                               LAB_00480e69                                                 XREF[1]:     00480e86(j)
//                              rmm_base.cpp:456 (14)
//         00480e69     MOV        EBX,dword ptr [ECX + this->stack_offsets]
//         00480e6c     INC        EDX
//         00480e6d     ADD        EAX,0x18
//         00480e70     MOV        EBX,dword ptr [EBX + EDI*0x4]
//         00480e73     MOV        dword ptr [EBX + EAX*0x1 + -0x8],ESI
//                              rmm_base.cpp:457 (17)
//         00480e77     MOV        EBX,dword ptr [ECX + this->stack_offsets]
//         00480e7a     MOV        EBX,dword ptr [EBX + EDI*0x4]
//         00480e7d     MOV        dword ptr [EBX + EAX*0x1 + -0x4],ESI
//         00480e81     MOV        EBX,dword ptr [ECX + this->map_width]
//         00480e84     CMP        EDX,EBX
//         00480e86     JL         LAB_00480e69
//                               LAB_00480e88                                                 XREF[1]:     00480e65(j)
//                              rmm_base.cpp:453 (8)
//         00480e88     MOV        EAX,dword ptr [ECX + this->map_height]
//         00480e8b     INC        EDI
//         00480e8c     CMP        EDI,EAX
//         00480e8e     JL         LAB_00480e5e
//                              rmm_base.cpp:448 (1)
//         00480e90     POP        EBX
//                               LAB_00480e91                                                 XREF[1]:     00480e5b(j)
//                              rmm_base.cpp:459 (3)
//         00480e91     POP        EDI
//         00480e92     POP        ESI
//         00480e93     RET
//         00480e94     ??         90h
//         00480e95     NOP
//         00480e96     NOP
//         00480e97     NOP
//         00480e98     NOP
//         00480e99     NOP
//         00480e9a     NOP
//         00480e9b     NOP
//         00480e9c     NOP
//         00480e9d     NOP
//         00480e9e     NOP
//         00480e9f     NOP
    return;
}

uchar RGE_Random_Map_Module::check_stack(Map_Stack* param_1) {
    /* TODO: Stub */
//                              uchar __thiscall check_stack(RGE_Random_Map_Module * this, Map_Stack
//              uchar             AL:1           <RETURN>
//              RGE_Random_Map    ECX:4 (auto)   this
//              Map_Stack *       Stack[0x4]:4   param_1                   XREF[1]:     00480ea0(R)
//                               ?check_stack@RGE_Random_Map_Module@@IAEEPAUMap_Stack@@@Z
//                               RGE_Random_Map_Module::check_stack
//                              rmm_base.cpp:464 (18)
//         00480ea0     MOV        EAX,dword ptr [ESP + param_1]
//         00480ea4     MOV        this,dword ptr [EAX + 0x10]
//         00480ea7     TEST       this,this
//         00480ea9     JNZ        LAB_00480eb7
//         00480eab     MOV        this,dword ptr [EAX + 0x14]
//         00480eae     TEST       this,this
//         00480eb0     JNZ        LAB_00480eb7
//                              rmm_base.cpp:468 (2)
//         00480eb2     XOR        AL,AL
//                              rmm_base.cpp:469 (3)
//         00480eb4     RET        0x4
//                               LAB_00480eb7                                                 XREF[2]:     00480ea9(j), 00480eb0(j)
//                              rmm_base.cpp:466 (2)
//         00480eb7     MOV        AL,0x1
//                              rmm_base.cpp:469 (3)
//         00480eb9     RET        0x4
//         00480ebc     ??         90h
//         00480ebd     NOP
//         00480ebe     NOP
//         00480ebf     NOP
    return 0;
}

void RGE_Random_Map_Module::randomize_stack(Map_Stack* param_1) {
    /* TODO: Stub */
//                              void __thiscall randomize_stack(RGE_Random_Map_Module * this, Map_St
//              void              <VOID>         <RETURN>
//              RGE_Random_Map    ECX:4 (auto)   this
//              Map_Stack *       Stack[0x4]:4   param_1                   XREF[1]:     00480ee3(R)
//              Map_Stack[100]    Stack[-0x964   sub_stacks                XREF[3,6]:   00480f4a(W), 00480f7c(R), 00480f8b(W), 00480ecc(*),
//                                                                                     00480f46(*), 00480f52(*), 00480f4e(*), 00480f59(*),
//                                                                                     00480f6b(*)
//              undefined4        Stack[-0x968   local_968                 XREF[3]:     00480eea(W), 00480f91(R), 00480f96(W)
//                               ?randomize_stack@RGE_Random_Map_Module@@IAEXPAUMap_Stack@@@Z XREF[1]:     setup_cliff_maps:00481cb5(c)
//                               RGE_Random_Map_Module::randomize_stack
//                              rmm_base.cpp:473 (12)
//         00480ec0     SUB        ESP,0x968
//         00480ec6     PUSH       EBX
//         00480ec7     PUSH       EBP
//         00480ec8     PUSH       ESI
//         00480ec9     PUSH       EDI
//         00480eca     MOV        EBX,this
//                              rmm_base.cpp:480 (9)
//         00480ecc     LEA        ESI=>sub_stacks[0].y,[ESP + 0x18]
//         00480ed0     MOV        EDI,0x64
//                               LAB_00480ed5                                                 XREF[1]:     00480ee1(j)
//                              rmm_base.cpp:481 (14)
//         00480ed5     PUSH       ESI
//         00480ed6     MOV        this,EBX
//         00480ed8     CALL       RGE_Random_Map_Module::init_stack                void init_stack(RGE_Random_Map_Module * this,
//         00480edd     ADD        ESI,0x18
//         00480ee0     DEC        EDI
//         00480ee1     JNZ        LAB_00480ed5
//                              rmm_base.cpp:486 (7)
//         00480ee3     MOV        ESI,dword ptr [ESP + param_1]
//                              rmm_base.cpp:506 (15)
//         00480eea     MOV        dword ptr [ESP + local_968],0x2
//                               LAB_00480ef2                                                 XREF[1]:     00480f9a(j)
//         00480ef2     MOV        EAX,dword ptr [ESI + 0x10]
//         00480ef5     TEST       EAX,EAX
//         00480ef7     JZ         LAB_00480f41
//                               LAB_00480ef9                                                 XREF[1]:     00480f3f(j)
//                              rmm_base.cpp:488 (36)
//         00480ef9     PUSH       0x1e8
//         00480efe     PUSH       s_C:\msdev\work\age1_x1\rmm_base.c               = "C:\\msdev\\work\\age1_x1\\rmm_base.cpp"
//         00480f03     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
//         00480f08     LEA        EAX,[EAX + EAX*0x4]
//         00480f0b     ADD        ESP,0x8
//         00480f0e     LEA        this,[EAX + EAX*0x4]
//         00480f11     MOV        EAX,0x80010003
//         00480f16     SHL        this,0x2
//         00480f19     IMUL       this
//         00480f1b     ADD        EDX,this
//                              rmm_base.cpp:489 (36)
//         00480f1d     MOV        this,dword ptr [ESI + 0x10]
//         00480f20     SAR        EDX,0xe
//         00480f23     MOV        EAX,EDX
//         00480f25     PUSH       this
//         00480f26     SHR        EAX,0x1f
//         00480f29     ADD        EDX,EAX
//         00480f2b     MOV        this,EBX
//         00480f2d     LEA        EDX,[EDX + EDX*0x2]
//         00480f30     LEA        EAX,[ESP + EDX*0x8 + 0x1c]
//         00480f34     PUSH       EAX
//         00480f35     CALL       RGE_Random_Map_Module::add_stack_node            void add_stack_node(RGE_Random_Map_Module * t
//         00480f3a     MOV        EAX,dword ptr [ESI + 0x10]
//         00480f3d     TEST       EAX,EAX
//         00480f3f     JNZ        LAB_00480ef9
//                               LAB_00480f41                                                 XREF[1]:     00480ef7(j)
//                              rmm_base.cpp:493 (17)
//         00480f41     MOV        EAX,0x18
//         00480f46     LEA        EBP=>sub_stacks[0].prev,[ESP + 0x28]
//         00480f4a     MOV        dword ptr [ESP + sub_stacks[0].x],EAX
//                               LAB_00480f4e                                                 XREF[1]:     00480f8f(j)
//         00480f4e     LEA        EDI=>sub_stacks[1].prev,[ESP + EAX*0x1 + 0x28]
//                               LAB_00480f52                                                 XREF[2]:     00480f6f(j), 00480f7a(j)
//                              rmm_base.cpp:497 (12)
//         00480f52     MOV        EAX,dword ptr [EBP]=>sub_stacks[0].prev
//         00480f55     TEST       EAX,EAX
//         00480f57     JNZ        LAB_00480f62
//         00480f59     CMP        dword ptr [EDI]=>sub_stacks[1].prev,0x0
//         00480f5c     JZ         LAB_00480f7c
//                              rmm_base.cpp:499 (4)
//         00480f5e     TEST       EAX,EAX
//         00480f60     JZ         LAB_00480f6b
//                               LAB_00480f62                                                 XREF[1]:     00480f57(j)
//                              rmm_base.cpp:500 (9)
//         00480f62     PUSH       EAX
//         00480f63     PUSH       ESI
//         00480f64     MOV        this,EBX
//         00480f66     CALL       RGE_Random_Map_Module::add_stack_node            void add_stack_node(RGE_Random_Map_Module * t
//                               LAB_00480f6b                                                 XREF[1]:     00480f60(j)
//                              rmm_base.cpp:501 (6)
//         00480f6b     MOV        EAX,dword ptr [EDI]=>sub_stacks[1].prev
//         00480f6d     TEST       EAX,EAX
//         00480f6f     JZ         LAB_00480f52
//                              rmm_base.cpp:502 (9)
//         00480f71     PUSH       EAX
//         00480f72     PUSH       ESI
//         00480f73     MOV        this,EBX
//         00480f75     CALL       RGE_Random_Map_Module::add_stack_node            void add_stack_node(RGE_Random_Map_Module * t
//                              rmm_base.cpp:503 (2)
//         00480f7a     JMP        LAB_00480f52
//                               LAB_00480f7c                                                 XREF[1]:     00480f5c(j)
//                              rmm_base.cpp:493 (36)
//         00480f7c     MOV        EAX,dword ptr [ESP + sub_stacks[0].x]
//         00480f80     ADD        EBP,0x30
//         00480f83     ADD        EAX,0x30
//         00480f86     CMP        EAX,0x978
//         00480f8b     MOV        dword ptr [ESP + sub_stacks[0].x],EAX
//         00480f8f     JL         LAB_00480f4e
//         00480f91     MOV        EAX,dword ptr [ESP + local_968]
//         00480f95     DEC        EAX
//         00480f96     MOV        dword ptr [ESP + local_968],EAX
//         00480f9a     JNZ        LAB_00480ef2
//                              rmm_base.cpp:506 (13)
//         00480fa0     POP        EDI
//         00480fa1     POP        ESI
//         00480fa2     POP        EBP
//         00480fa3     POP        EBX
//         00480fa4     ADD        ESP,0x968
//         00480faa     RET        0x4
//         00480fad     ??         90h
//         00480fae     NOP
//         00480faf     NOP
    return;
}

uchar RGE_Random_Map_Module::find_path(long param_1, long param_2, long* param_3, long* param_4, float* param_5) {
    /* TODO: Stub */
//                              uchar __thiscall find_path(RGE_Random_Map_Module * this, long param_
//              uchar             AL:1           <RETURN>
//              RGE_Random_Map    ECX:4 (auto)   this
//              long              Stack[0x4]:4   param_1                   XREF[1]:     00480fd3(R)
//              long              Stack[0x8]:4   param_2                   XREF[1]:     00480fce(R)
//              long *            Stack[0xc]:4   param_3                   XREF[1]:     00480fc9(R)
//              long *            Stack[0x10]:4  param_4                   XREF[1]:     00480fc5(R)
//              float *           Stack[0x14]:4  param_5                   XREF[1]:     00480fc1(R)
//              Map_Stack         Stack[-0x1c]   path_stack                XREF[0,3]:   00480fb3(*), 00480fd9(*), 00480fe6(*)
//                               ?find_path@RGE_Random_Map_Module@@IAEEJJAAJ0PAM@Z            XREF[1]:     make_tribe_connections:004872a1(c)
//                               RGE_Random_Map_Module::find_path
//                              rmm_base.cpp:512 (3)
//         00480fb0     SUB        ESP,0x18
//                              rmm_base.cpp:516 (14)
//         00480fb3     LEA        EAX=>path_stack.y,[ESP]
//         00480fb7     PUSH       EBX
//         00480fb8     PUSH       ESI
//         00480fb9     MOV        ESI,this
//         00480fbb     PUSH       EAX
//         00480fbc     CALL       RGE_Random_Map_Module::init_stack                void init_stack(RGE_Random_Map_Module * this,
//                              rmm_base.cpp:517 (37)
//         00480fc1     MOV        this,dword ptr [ESP + param_5]
//         00480fc5     MOV        EDX,dword ptr [ESP + param_4]
//         00480fc9     MOV        EAX,dword ptr [ESP + param_3]
//         00480fcd     PUSH       this
//         00480fce     MOV        this,dword ptr [ESP + param_2]
//         00480fd2     PUSH       EDX
//         00480fd3     MOV        EDX,dword ptr [ESP + param_1]
//         00480fd7     PUSH       EAX
//         00480fd8     PUSH       this
//         00480fd9     LEA        EAX=>path_stack.y,[ESP + 0x18]
//         00480fdd     PUSH       EDX
//         00480fde     PUSH       EAX
//         00480fdf     MOV        this,ESI
//         00480fe1     CALL       RGE_Random_Map_Module::find_path                 uchar find_path(RGE_Random_Map_Module * this,
//                              rmm_base.cpp:519 (14)
//         00480fe6     LEA        this=>path_stack.y,[ESP + 0x8]
//         00480fea     MOV        BL,AL
//         00480fec     PUSH       this
//         00480fed     MOV        this,ESI
//         00480fef     CALL       RGE_Random_Map_Module::deinit_stack              void deinit_stack(RGE_Random_Map_Module * thi
//                              rmm_base.cpp:521 (2)
//         00480ff4     MOV        AL,BL
//                              rmm_base.cpp:522 (8)
//         00480ff6     POP        ESI
//         00480ff7     POP        EBX
//         00480ff8     ADD        ESP,0x18
//         00480ffb     RET        0x14
//         00480ffe     ??         90h
//         00480fff     NOP
    return 0;
}

uchar RGE_Random_Map_Module::find_path(Map_Stack* param_1, long param_2, long param_3, long* param_4, long* param_5, float* param_6) {
    /* TODO: Stub */
//                              uchar __thiscall find_path(RGE_Random_Map_Module * this, Map_Stack *
//              uchar             AL:1           <RETURN>
//              RGE_Random_Map    ECX:4 (auto)   this
//              Map_Stack *       Stack[0x4]:4   param_1                   XREF[10]:    00481154(R), 0048122d(R), 00481317(R), 00481426(R),
//                                                                                     00481519(R), 004815d4(R), 004816ce(R), 0048179c(R),
//                                                                                     004817cb(R), 0048182c(R)
//              long              Stack[0x8]:4   param_2                   XREF[18]:    00481052(R), 004810a2(R), 0048115c(R), 00481182(R),
//                                                                                     00481194(R), 00481235(R), 0048125b(R), 0048126d(R),
//                                                                                     00481345(R), 00481358(R), 00481445(R), 00481456(R),
//                                                                                     00481538(R), 00481549(R), 004817cf(*), 004817e9(R),
//                                                                                     0048185c(R), 00481882(R)
//              long              Stack[0xc]:4   param_3                   XREF[26]:    00481047(R), 004810af(R), 0048117e(R), 00481190(R),
//                                                                                     00481257(R), 00481269(R), 0048131f(R), 00481341(R),
//                                                                                     00481354(R), 00481400(R), 00481441(R), 00481452(R),
//                                                                                     004814f3(R), 00481534(R), 00481545(R), 004815dc(R),
//                                                                                     004815fe(R), 0048160c(R), 004816a8(R), 004816e9(R)
//              long *            Stack[0x10]:4  param_4                   XREF[11]:    0048103b(R), 0048129a(R), 00481562(R), 004817e5(R),
//                                                                                     00481854(R), 0048187a(R), 0048189c(R), 004818c2(R),
//                                                                                     004818e4(R), 00481925(R), 0048194a(R)
//              long *            Stack[0x14]:4  param_5                   XREF[14]:    0048104b(R), 004811c1(R), 004813f3(R), 004814e6(R),
//                                                                                     0048169b(R), 00481770(R), 004817f1(R), 00481860(R),
//                                                                                     004818a4(R), 004818ca(R), 004818ec(R), 00481906(R),
//                                                                                     0048192c(R), 00481952(R)
//              float *           Stack[0x18]:4  param_6                   XREF[9]:     0048107c(R), 00481126(R), 004811ff(R), 004812f1(R),
//                                                                                     004813ad(R), 004814a0(R), 004815ad(R), 0048165d(R),
//                                                                                     0048172b(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     00481015(W), 00481558(R)
//              long              Stack[-0x8]:4  map_w                     XREF[4]:     0048101d(W), 004810e2(R), 00481465(R), 00481700(R)
//              long              Stack[-0xc]:4  map_h                     XREF[10]:    004810c3(W), 004810c7(R), 00481382(W), 00481422(R),
//                                                                                     00481475(W), 00481515(R), 00481634(W), 004816d5(R),
//                                                                                     0048180d(W), 00481811(R)
//              long              Stack[-0x10]:4 ty                        XREF[10]:    00481009(W), 0048114e(R), 00481227(R), 00481313(R),
//                                                                                     004813f7(R), 004814ea(R), 004815ce(R), 0048169f(R),
//                                                                                     00481769(R), 004817c2(*)
//              float             Stack[-0x14]:4 cost                      XREF[6]:     004810cd(W), 004810ec(R), 004811c5(R), 0048129e(R),
//                                                                                     00481566(R), 00481817(W)
//              float             Stack[-0x18]:4 hcost                     XREF[8]:     004812c4(W), 0048132b(R), 00481408(R), 004814fb(R),
//                                                                                     00481589(W), 004815e8(R), 004816b0(R), 0048177e(R)
//              float             Stack[-0x1c]:4 tcost                     XREF[18]:    00481072(W), 00481084(R), 0048112d(W), 00481131(R),
//                                                                                     00481206(W), 0048120a(R), 004812ed(W), 00481305(R),
//                                                                                     004813b3(W), 004813b7(R), 004814a6(W), 004814aa(R),
//                                                                                     004815a9(W), 004815b1(R), 00481663(W), 00481667(R),
//                                                                                     00481731(W), 00481735(R)
//              uchar             Stack[-0x20]:1 tile_type                 XREF[30]:    00481160(W), 00481164(R), 00481168(R), 00481239(W),
//                                                                                     0048123d(R), 00481241(R), 00481323(W), 00481327(R),
//                                                                                     0048132f(R), 00481392(W), 004813ef(R), 00481404(W),
//                                                                                     0048141e(R), 0048142d(R), 0048144b(R), 00481485(W),
//                                                                                     004814e2(R), 004814f7(W), 00481511(R), 00481520(R)
//              float             Stack[-0x24]:4 calc_cost                 XREF[0,22]:  0048125f(W), 00481271(W), 00481286(W), 0048128d(W),
//                                                                                     004813d3(R), 00481683(R), 00481186(W), 00481198(W),
//                                                                                     004811ad(W), 004811b4(W), 004814c6(R), 00481751(R),
//                                                                                     00481349(W), 0048135c(W), 0048136f(W), 004813df(R),
//                                                                                     004814d2(R), 00481602(W), 00481610(W), 00481621(W)
//              uchar             Stack[-0x25]:1 right
//              uchar             Stack[-0x26]:1 down
//              uchar             Stack[-0x27]:1 up
//              undefined4        Stack[-0x38]:4 local_38                  XREF[8]:     0048116e(*), 00481247(*), 00481333(*), 00481431(*),
//                                                                                     00481524(*), 004815f0(*), 004816d9(*), 004817a3(*)
//                               ?find_path@RGE_Random_Map_Module@@IAEEAAUMap_Stack@@JJAAJ1P  XREF[1]:     find_path:00480fe1(c)
//                               RGE_Random_Map_Module::find_path
//                              rmm_base.cpp:526 (9)
//         00481000     SUB        ESP,0x24
//         00481003     PUSH       EBX
//         00481004     PUSH       EBP
//         00481005     PUSH       ESI
//         00481006     MOV        ESI,this
//         00481008     PUSH       EDI
//                              rmm_base.cpp:533 (24)
//         00481009     MOV        dword ptr [ESP + ty],0x0
//         00481011     MOV        EAX,dword ptr [ESI + 0x14]
//         00481014     DEC        EAX
//         00481015     MOV        dword ptr [ESP + local_4],EAX
//         00481019     MOV        EAX,dword ptr [ESI + 0x18]
//         0048101c     DEC        EAX
//         0048101d     MOV        dword ptr [ESP + map_w],EAX
//                              rmm_base.cpp:546 (5)
//         00481021     CALL       RGE_Random_Map_Module::clear_stack               void clear_stack(RGE_Random_Map_Module * this)
//                              rmm_base.cpp:547 (21)
//         00481026     MOV        this,dword ptr [ESI + 0x18]
//         00481029     MOV        EDI,dword ptr [ESI + 0x20]
//         0048102c     IMUL       this,dword ptr [ESI + 0x14]
//         00481030     MOV        EDX,this
//         00481032     XOR        EAX,EAX
//         00481034     SHR        this,0x2
//         00481037     STOSD.REP  ES:EDI
//         00481039     MOV        this,EDX
//                              rmm_base.cpp:550 (59)
//         0048103b     MOV        EBP,dword ptr [ESP + param_4]
//         0048103f     AND        this,0x3
//         00481042     STOSB.REP  ES:EDI
//         00481044     MOV        EAX,dword ptr [ESI + 0x24]
//         00481047     MOV        this,dword ptr [ESP + param_3]
//         0048104b     MOV        EDI,dword ptr [ESP + param_5]
//         0048104f     MOV        EDX,dword ptr [EAX + this->_padding_*0x4]
//         00481052     MOV        EAX,dword ptr [ESP + param_2]
//         00481056     MOV        byte ptr [EDX + EAX*0x1],0x3
//         0048105a     MOV        EAX,dword ptr [EDI]
//         0048105c     MOV        this,dword ptr [EBP]
//         0048105f     MOV        EDX,dword ptr [ESI + 0x10]
//         00481062     SHL        EAX,0x2
//         00481065     LEA        EBX,[ECX + ECX*0x2]
//         00481068     MOV        EDX,dword ptr [EDX + EAX*0x1]
//         0048106b     MOV        DL,byte ptr [EDX + EBX*0x8 + 0x5]
//         0048106f     AND        DL,0x1f
//         00481072     MOV        byte ptr [ESP + tcost],DL
//                              rmm_base.cpp:551 (6)
//         00481076     MOV        EDX,dword ptr [ESI + 0x24]
//         00481079     MOV        EAX,dword ptr [EDX + EAX*0x1]
//                              rmm_base.cpp:554 (32)
//         0048107c     MOV        EDX,dword ptr [ESP + param_6]
//         00481080     MOV        byte ptr [EAX + this->_padding_*0x1],0x2
//         00481084     MOV        this,dword ptr [ESP + tcost]
//         00481088     AND        this,0xff
//         0048108e     FLD        float ptr [EDX + this->_padding_*0x4]
//         00481091     FCOMP      float ptr [null_00571e38]                        = align(18)
//         00481097     FNSTSW     AX
//         00481099     TEST       AH,0x41
//                              rmm_base.cpp:555 (6)
//         0048109c     JNZ        LAB_00481966
//                              rmm_base.cpp:560 (7)
//         004810a2     MOV        EDX,dword ptr [ESP + param_2]
//         004810a6     MOV        this,dword ptr [EBP]
//                              rmm_base.cpp:561 (12)
//         004810a9     MOV        EBP,dword ptr [EDI]
//         004810ab     MOV        EAX,EDX
//         004810ad     SUB        EAX,this
//         004810af     MOV        this,dword ptr [ESP + param_3]
//         004810b3     MOV        EDI,this
//                              rmm_base.cpp:564 (28)
//         004810b5     MOV        EBX,EAX
//         004810b7     SUB        EDI,EBP
//         004810b9     IMUL       EBX,EAX
//         004810bc     MOV        EAX,EDI
//         004810be     IMUL       EAX,EDI
//         004810c1     ADD        EBX,EAX
//         004810c3     MOV        dword ptr [ESP + map_h],EBX
//         004810c7     FILD       dword ptr [ESP + map_h]
//         004810cb     FSQRT
//         004810cd     FST        float ptr [ESP + cost]
//                              rmm_base.cpp:566 (17)
//         004810d1     FCOMP      double ptr [null_00571e40]                       = align(10)
//         004810d7     FNSTSW     AX
//         004810d9     TEST       AH,0x40
//         004810dc     JNZ        LAB_0048182c
//                               LAB_004810e2                                                 XREF[1]:     00481826(j)
//                              rmm_base.cpp:575 (10)
//         004810e2     CMP        this,dword ptr [ESP + map_w]
//         004810e6     JGE        LAB_004811b4
//                              rmm_base.cpp:578 (22)
//         004810ec     FLD        float ptr [ESP + cost]
//         004810f0     CMP        EBP,this
//         004810f2     JLE        LAB_004810fc
//         004810f4     FSUB       float ptr [null_00571e48]                        = align(2)
//         004810fa     JMP        LAB_00481102
//                               LAB_004810fc                                                 XREF[1]:     004810f2(j)
//         004810fc     FSUB       float ptr [DAT_00571e4c]
//                               LAB_00481102                                                 XREF[1]:     004810fa(j)
//                              rmm_base.cpp:580 (15)
//         00481102     MOV        EAX,dword ptr [ESI + 0x24]
//         00481105     LEA        EBP,[ECX + this+0x1]
//         00481108     MOV        EAX,dword ptr [EAX + EBP*0x4]
//         0048110b     LEA        EDI,[EAX + EDX*0x1]
//         0048110e     MOV        AL,byte ptr [EAX + EDX*0x1]
//                              rmm_base.cpp:581 (8)
//         00481111     TEST       AL,AL
//         00481113     JNZ        LAB_004811a1
//                              rmm_base.cpp:584 (13)
//         00481119     MOV        this,dword ptr [ESI + 0x10]
//         0048111c     LEA        EDX,[EDX + EDX*0x2]
//         0048111f     MOV        EAX,dword ptr [this->_padding_ + EBP*0x4]
//         00481122     MOV        this,byte ptr [EAX + EDX*0x8 + 0x5]
//                              rmm_base.cpp:586 (40)
//         00481126     MOV        EAX,dword ptr [ESP + param_6]
//         0048112a     AND        this,0x1f
//         0048112d     MOV        byte ptr [ESP + tcost],this
//         00481131     MOV        EDX,dword ptr [ESP + tcost]
//         00481135     AND        EDX,0xff
//         0048113b     FLD        float ptr [EAX + EDX*0x4]
//         0048113e     FCOMP      double ptr [null_00571e40]                       = align(10)
//         00481144     LEA        this,[EAX + EDX*0x4]
//         00481147     FNSTSW     AX
//         00481149     TEST       AH,0x41
//         0048114c     JNZ        LAB_0048118d
//                              rmm_base.cpp:588 (6)
//         0048114e     FLD        float ptr [ESP + ty]
//         00481152     FADD       float ptr [this->_padding_]
//                              rmm_base.cpp:590 (42)
//         00481154     MOV        EAX,dword ptr [ESP + param_1]
//         00481158     PUSH       this
//         00481159     MOV        byte ptr [EDI],0x7
//         0048115c     MOV        EDX,dword ptr [ESP + param_2]
//         00481160     FSTP       float ptr [ESP + tile_type]
//         00481164     FLD        float ptr [ESP + tile_type]
//         00481168     MOV        this,dword ptr [ESP + tile_type]
//         0048116c     FADD       ST0,ST1
//         0048116e     FSTP       float ptr [ESP]=>local_38
//         00481171     PUSH       this
//         00481172     PUSH       EBP
//         00481173     PUSH       EDX
//         00481174     PUSH       EAX
//         00481175     MOV        this,ESI
//         00481177     FSTP       ST0
//         00481179     CALL       RGE_Random_Map_Module::push_stack                void push_stack(RGE_Random_Map_Module * this,
//                              rmm_base.cpp:593 (15)
//         0048117e     MOV        this,dword ptr [ESP + param_3]
//         00481182     MOV        EDX,dword ptr [ESP + param_2]
//         00481186     MOV        byte ptr [ESP + calc_cost+0x2],0x1
//         0048118b     JMP        LAB_004811b9
//                               LAB_0048118d                                                 XREF[1]:     0048114c(j)
//                              rmm_base.cpp:596 (3)
//         0048118d     MOV        byte ptr [EDI],0x1
//                              rmm_base.cpp:600 (27)
//         00481190     MOV        this,dword ptr [ESP + param_3]
//         00481194     MOV        EDX,dword ptr [ESP + param_2]
//         00481198     MOV        byte ptr [ESP + calc_cost+0x2],0x0
//         0048119d     FSTP       ST0
//         0048119f     JMP        LAB_004811b9
//                               LAB_004811a1                                                 XREF[1]:     00481113(j)
//         004811a1     CMP        AL,0x2
//         004811a3     FSTP       ST0
//         004811a5     JZ         LAB_0048184e
//                              rmm_base.cpp:608 (7)
//         004811ab     CMP        AL,0x1
//         004811ad     SETNZ      byte ptr [ESP + calc_cost+0x2]
//                              rmm_base.cpp:613 (2)
//         004811b2     JMP        LAB_004811b9
//                               LAB_004811b4                                                 XREF[1]:     004810e6(j)
//                              rmm_base.cpp:614 (5)
//         004811b4     MOV        byte ptr [ESP + calc_cost+0x2],0x0
//                               LAB_004811b9                                                 XREF[3]:     0048118b(j), 0048119f(j),
//                                                                                                         004811b2(j)
//                              rmm_base.cpp:617 (8)
//         004811b9     TEST       this,this
//         004811bb     JLE        LAB_0048128d
//                              rmm_base.cpp:619 (26)
//         004811c1     MOV        EBX,dword ptr [ESP + param_5]
//         004811c5     FLD        float ptr [ESP + cost]
//         004811c9     CMP        dword ptr [EBX],this
//         004811cb     JGE        LAB_004811d5
//         004811cd     FSUB       float ptr [null_00571e48]                        = align(2)
//         004811d3     JMP        LAB_004811db
//                               LAB_004811d5                                                 XREF[1]:     004811cb(j)
//         004811d5     FSUB       float ptr [DAT_00571e4c]
//                               LAB_004811db                                                 XREF[1]:     004811d3(j)
//                              rmm_base.cpp:621 (15)
//         004811db     MOV        EAX,dword ptr [ESI + 0x24]
//         004811de     LEA        EBP,[this->_padding_ + -0x1]
//         004811e1     MOV        EAX,dword ptr [EAX + EBP*0x4]
//         004811e4     LEA        EDI,[EAX + EDX*0x1]
//         004811e7     MOV        AL,byte ptr [EAX + EDX*0x1]
//                              rmm_base.cpp:622 (8)
//         004811ea     TEST       AL,AL
//         004811ec     JNZ        LAB_0048127a
//                              rmm_base.cpp:625 (13)
//         004811f2     MOV        this,dword ptr [ESI + 0x10]
//         004811f5     LEA        EDX,[EDX + EDX*0x2]
//         004811f8     MOV        EAX,dword ptr [this->_padding_ + EBP*0x4]
//         004811fb     MOV        this,byte ptr [EAX + EDX*0x8 + 0x5]
//                              rmm_base.cpp:626 (40)
//         004811ff     MOV        EAX,dword ptr [ESP + param_6]
//         00481203     AND        this,0x1f
//         00481206     MOV        byte ptr [ESP + tcost],this
//         0048120a     MOV        EDX,dword ptr [ESP + tcost]
//         0048120e     AND        EDX,0xff
//         00481214     FLD        float ptr [EAX + EDX*0x4]
//         00481217     FCOMP      double ptr [null_00571e40]                       = align(10)
//         0048121d     LEA        this,[EAX + EDX*0x4]
//         00481220     FNSTSW     AX
//         00481222     TEST       AH,0x41
//         00481225     JNZ        LAB_00481266
//                              rmm_base.cpp:628 (6)
//         00481227     FLD        float ptr [ESP + ty]
//         0048122b     FADD       float ptr [this->_padding_]
//                              rmm_base.cpp:630 (42)
//         0048122d     MOV        EAX,dword ptr [ESP + param_1]
//         00481231     PUSH       this
//         00481232     MOV        byte ptr [EDI],0x6
//         00481235     MOV        EDX,dword ptr [ESP + param_2]
//         00481239     FSTP       float ptr [ESP + tile_type]
//         0048123d     FLD        float ptr [ESP + tile_type]
//         00481241     MOV        this,dword ptr [ESP + tile_type]
//         00481245     FADD       ST0,ST1
//         00481247     FSTP       float ptr [ESP]=>local_38
//         0048124a     PUSH       this
//         0048124b     PUSH       EBP
//         0048124c     PUSH       EDX
//         0048124d     PUSH       EAX
//         0048124e     MOV        this,ESI
//         00481250     FSTP       ST0
//         00481252     CALL       RGE_Random_Map_Module::push_stack                void push_stack(RGE_Random_Map_Module * this,
//                              rmm_base.cpp:633 (15)
//         00481257     MOV        this,dword ptr [ESP + param_3]
//         0048125b     MOV        EDX,dword ptr [ESP + param_2]
//         0048125f     MOV        byte ptr [ESP + calc_cost+0x1],0x1
//         00481264     JMP        LAB_00481292
//                               LAB_00481266                                                 XREF[1]:     00481225(j)
//                              rmm_base.cpp:635 (3)
//         00481266     MOV        byte ptr [EDI],0x1
//                              rmm_base.cpp:639 (27)
//         00481269     MOV        this,dword ptr [ESP + param_3]
//         0048126d     MOV        EDX,dword ptr [ESP + param_2]
//         00481271     MOV        byte ptr [ESP + calc_cost+0x1],0x0
//         00481276     FSTP       ST0
//         00481278     JMP        LAB_00481292
//                               LAB_0048127a                                                 XREF[1]:     004811ec(j)
//         0048127a     CMP        AL,0x2
//         0048127c     FSTP       ST0
//         0048127e     JZ         LAB_00481874
//                              rmm_base.cpp:646 (7)
//         00481284     CMP        AL,0x1
//         00481286     SETNZ      byte ptr [ESP + calc_cost+0x1]
//                              rmm_base.cpp:651 (2)
//         0048128b     JMP        LAB_00481292
//                               LAB_0048128d                                                 XREF[1]:     004811bb(j)
//                              rmm_base.cpp:652 (5)
//         0048128d     MOV        byte ptr [ESP + calc_cost+0x1],0x0
//                               LAB_00481292                                                 XREF[3]:     00481264(j), 00481278(j),
//                                                                                                         0048128b(j)
//                              rmm_base.cpp:655 (8)
//         00481292     TEST       EDX,EDX
//         00481294     JLE        LAB_00481558
//                              rmm_base.cpp:657 (26)
//         0048129a     MOV        EAX,dword ptr [ESP + param_4]
//         0048129e     FLD        float ptr [ESP + cost]
//         004812a2     CMP        dword ptr [EAX],EDX
//         004812a4     JGE        LAB_004812ae
//         004812a6     FSUB       float ptr [null_00571e48]                        = align(2)
//         004812ac     JMP        LAB_004812b4
//                               LAB_004812ae                                                 XREF[1]:     004812a4(j)
//         004812ae     FSUB       float ptr [DAT_00571e4c]
//                               LAB_004812b4                                                 XREF[1]:     004812ac(j)
//                              rmm_base.cpp:659 (26)
//         004812b4     MOV        EBX,dword ptr [ESI + 0x24]
//         004812b7     LEA        EAX,[this->_padding_*0x4 + 0x0]
//         004812be     LEA        EDI,[EDX + -0x1]
//         004812c1     MOV        EBX,dword ptr [EBX + EAX*0x1]
//         004812c4     FSTP       float ptr [ESP + hcost]
//         004812c8     LEA        EBP,[EBX + EDI*0x1]
//         004812cb     MOV        BL,byte ptr [EBX + EDI*0x1]
//                              rmm_base.cpp:660 (8)
//         004812ce     TEST       BL,BL
//         004812d0     JNZ        LAB_00481363
//                              rmm_base.cpp:662 (12)
//         004812d6     MOV        this,dword ptr [ESI + 0x10]
//         004812d9     LEA        EDX,[EDI + EDI*0x2]
//         004812dc     MOV        EAX,dword ptr [this->_padding_ + EAX*0x1]
//         004812df     LEA        EAX,[EAX + EDX*0x8]
//                              rmm_base.cpp:663 (5)
//         004812e2     MOV        AL,byte ptr [EAX + 0x5]
//         004812e5     MOV        this,AL
//                              rmm_base.cpp:664 (30)
//         004812e7     AND        EAX,0x1f
//         004812ea     AND        this,0x1f
//         004812ed     MOV        byte ptr [ESP + tcost],this
//         004812f1     MOV        this,dword ptr [ESP + param_6]
//         004812f5     FLD        float ptr [this->_padding_ + EAX*0x4]
//         004812f8     FCOMP      float ptr [null_00571e38]                        = align(18)
//         004812fe     FNSTSW     AX
//         00481300     TEST       AH,0x41
//         00481303     JNZ        LAB_00481350
//                              rmm_base.cpp:666 (4)
//         00481305     MOV        EDX,dword ptr [ESP + tcost]
//                              rmm_base.cpp:668 (56)
//         00481309     PUSH       this
//         0048130a     AND        EDX,0xff
//         00481310     FLD        float ptr [this->_padding_ + EDX*0x4]
//         00481313     FADD       float ptr [ESP + ty]
//         00481317     MOV        EDX,dword ptr [ESP + param_1]
//         0048131b     MOV        byte ptr [EBP],0x4
//         0048131f     MOV        this,dword ptr [ESP + param_3]
//         00481323     FSTP       float ptr [ESP + tile_type]
//         00481327     FLD        float ptr [ESP + tile_type]
//         0048132b     FADD       float ptr [ESP + hcost]
//         0048132f     MOV        EAX,dword ptr [ESP + tile_type]
//         00481333     FSTP       float ptr [ESP]=>local_38
//         00481336     PUSH       EAX
//         00481337     PUSH       this
//         00481338     PUSH       EDI
//         00481339     PUSH       EDX
//         0048133a     MOV        this,ESI
//         0048133c     CALL       RGE_Random_Map_Module::push_stack                void push_stack(RGE_Random_Map_Module * this,
//                              rmm_base.cpp:671 (15)
//         00481341     MOV        this,dword ptr [ESP + param_3]
//         00481345     MOV        EDX,dword ptr [ESP + param_2]
//         00481349     MOV        byte ptr [ESP + calc_cost+0x3],0x1
//         0048134e     JMP        LAB_00481374
//                               LAB_00481350                                                 XREF[1]:     00481303(j)
//                              rmm_base.cpp:673 (4)
//         00481350     MOV        byte ptr [EBP],0x1
//                              rmm_base.cpp:677 (24)
//         00481354     MOV        this,dword ptr [ESP + param_3]
//         00481358     MOV        EDX,dword ptr [ESP + param_2]
//         0048135c     MOV        byte ptr [ESP + calc_cost+0x3],0x0
//         00481361     JMP        LAB_00481374
//                               LAB_00481363                                                 XREF[1]:     004812d0(j)
//         00481363     CMP        BL,0x2
//         00481366     JZ         LAB_00481896
//                              rmm_base.cpp:684 (8)
//         0048136c     CMP        BL,0x1
//         0048136f     SETNZ      byte ptr [ESP + calc_cost+0x3]
//                               LAB_00481374                                                 XREF[2]:     0048134e(j), 00481361(j)
//                              rmm_base.cpp:690 (8)
//         00481374     TEST       this,this
//         00481376     JLE        LAB_00481465
//                              rmm_base.cpp:693 (28)
//         0048137c     MOV        EBX,dword ptr [ESI + 0x24]
//         0048137f     LEA        EAX,[this->_padding_ + -0x1]
//         00481382     MOV        dword ptr [ESP + map_h],EAX
//         00481386     MOV        EBX,dword ptr [EBX + EAX*0x4]
//         00481389     LEA        EBP,[EAX*0x4 + 0x0]
//         00481390     ADD        EBX,EDI
//         00481392     MOV        dword ptr [ESP + tile_type],EBX
//         00481396     MOV        BL,byte ptr [EBX]
//                              rmm_base.cpp:694 (8)
//         00481398     TEST       BL,BL
//         0048139a     JNZ        LAB_0048145c
//                              rmm_base.cpp:697 (13)
//         004813a0     MOV        EAX,dword ptr [ESI + 0x10]
//         004813a3     LEA        EBX,[EDI + EDI*0x2]
//         004813a6     MOV        EAX,dword ptr [EAX + EBP*0x1]
//         004813a9     MOV        AL,byte ptr [EAX + EBX*0x8 + 0x5]
//                              rmm_base.cpp:698 (38)
//         004813ad     MOV        EBX,dword ptr [ESP + param_6]
//         004813b1     AND        AL,0x1f
//         004813b3     MOV        byte ptr [ESP + tcost],AL
//         004813b7     MOV        EAX,dword ptr [ESP + tcost]
//         004813bb     AND        EAX,0xff
//         004813c0     FLD        float ptr [EBX + EAX*0x4]
//         004813c3     FCOMP      float ptr [null_00571e38]                        = align(18)
//         004813c9     LEA        EBX,[EBX + EAX*0x4]
//         004813cc     FNSTSW     AX
//         004813ce     TEST       AH,0x41
//         004813d1     JNZ        LAB_0048144b
//                              rmm_base.cpp:700 (20)
//         004813d3     MOV        AL,byte ptr [ESP + calc_cost+0x1]
//         004813d7     TEST       AL,AL
//         004813d9     JZ         LAB_00481465
//         004813df     MOV        AL,byte ptr [ESP + calc_cost+0x3]
//         004813e3     TEST       AL,AL
//         004813e5     JZ         LAB_00481465
//                              rmm_base.cpp:702 (8)
//         004813e7     FLD        float ptr [EBX]
//         004813e9     FMUL       float ptr [DAT_00571e50]                         = 7Bh    {
//                              rmm_base.cpp:703 (4)
//         004813ef     MOV        this,dword ptr [ESP + tile_type]
//                              rmm_base.cpp:704 (78)
//         004813f3     MOV        EDX,dword ptr [ESP + param_5]
//         004813f7     FSUBR      float ptr [ESP + ty]
//         004813fb     MOV        byte ptr [this->_padding_],0x8
//         004813fe     MOV        EAX,dword ptr [EDX]
//         00481400     MOV        this,dword ptr [ESP + param_3]
//         00481404     FSTP       float ptr [ESP + tile_type]
//         00481408     FLD        float ptr [ESP + hcost]
//         0048140c     CMP        EAX,this
//         0048140e     JGE        LAB_00481418
//         00481410     FSUB       float ptr [DAT_00571e54]                         = 85h
//         00481416     JMP        LAB_0048141e
//                               LAB_00481418                                                 XREF[1]:     0048140e(j)
//         00481418     FSUB       float ptr [DAT_00571e58]                         = 85h
//                               LAB_0048141e                                                 XREF[1]:     00481416(j)
//         0048141e     FLD        float ptr [ESP + tile_type]
//         00481422     MOV        EDX,dword ptr [ESP + map_h]
//         00481426     MOV        EAX,dword ptr [ESP + param_1]
//         0048142a     FADD       ST0,ST1
//         0048142c     PUSH       this
//         0048142d     MOV        this,dword ptr [ESP + tile_type]
//         00481431     FSTP       float ptr [ESP]=>local_38
//         00481434     PUSH       this
//         00481435     PUSH       EDX
//         00481436     PUSH       EDI
//         00481437     PUSH       EAX
//         00481438     MOV        this,ESI
//         0048143a     FSTP       ST0
//         0048143c     CALL       RGE_Random_Map_Module::push_stack                void push_stack(RGE_Random_Map_Module * this,
//                              rmm_base.cpp:707 (10)
//         00481441     MOV        this,dword ptr [ESP + param_3]
//         00481445     MOV        EDX,dword ptr [ESP + param_2]
//         00481449     JMP        LAB_00481465
//                               LAB_0048144b                                                 XREF[1]:     004813d1(j)
//                              rmm_base.cpp:708 (7)
//         0048144b     MOV        this,dword ptr [ESP + tile_type]
//         0048144f     MOV        byte ptr [this->_padding_],0x1
//                              rmm_base.cpp:710 (19)
//         00481452     MOV        this,dword ptr [ESP + param_3]
//         00481456     MOV        EDX,dword ptr [ESP + param_2]
//         0048145a     JMP        LAB_00481465
//                               LAB_0048145c                                                 XREF[1]:     0048139a(j)
//         0048145c     CMP        BL,0x2
//         0048145f     JZ         LAB_004818bc
//                               LAB_00481465                                                 XREF[5]:     00481376(j), 004813d9(j),
//                                                                                                         004813e5(j), 00481449(j),
//                                                                                                         0048145a(j)
//                              rmm_base.cpp:720 (10)
//         00481465     CMP        this,dword ptr [ESP + map_w]
//         00481469     JGE        LAB_00481558
//                              rmm_base.cpp:723 (28)
//         0048146f     MOV        EBX,dword ptr [ESI + 0x24]
//         00481472     LEA        EAX,[ECX + this+0x1]
//         00481475     MOV        dword ptr [ESP + map_h],EAX
//         00481479     MOV        EBX,dword ptr [EBX + EAX*0x4]
//         0048147c     LEA        EBP,[EAX*0x4 + 0x0]
//         00481483     ADD        EBX,EDI
//         00481485     MOV        dword ptr [ESP + tile_type],EBX
//         00481489     MOV        BL,byte ptr [EBX]
//                              rmm_base.cpp:724 (8)
//         0048148b     TEST       BL,BL
//         0048148d     JNZ        LAB_0048154f
//                              rmm_base.cpp:727 (13)
//         00481493     MOV        EAX,dword ptr [ESI + 0x10]
//         00481496     LEA        EBX,[EDI + EDI*0x2]
//         00481499     MOV        EAX,dword ptr [EAX + EBP*0x1]
//         0048149c     MOV        AL,byte ptr [EAX + EBX*0x8 + 0x5]
//                              rmm_base.cpp:728 (38)
//         004814a0     MOV        EBX,dword ptr [ESP + param_6]
//         004814a4     AND        AL,0x1f
//         004814a6     MOV        byte ptr [ESP + tcost],AL
//         004814aa     MOV        EAX,dword ptr [ESP + tcost]
//         004814ae     AND        EAX,0xff
//         004814b3     FLD        float ptr [EBX + EAX*0x4]
//         004814b6     FCOMP      float ptr [null_00571e38]                        = align(18)
//         004814bc     LEA        EBX,[EBX + EAX*0x4]
//         004814bf     FNSTSW     AX
//         004814c1     TEST       AH,0x41
//         004814c4     JNZ        LAB_0048153e
//                              rmm_base.cpp:730 (20)
//         004814c6     MOV        AL,byte ptr [ESP + calc_cost+0x2]
//         004814ca     TEST       AL,AL
//         004814cc     JZ         LAB_00481558
//         004814d2     MOV        AL,byte ptr [ESP + calc_cost+0x3]
//         004814d6     TEST       AL,AL
//         004814d8     JZ         LAB_00481558
//                              rmm_base.cpp:732 (8)
//         004814da     FLD        float ptr [EBX]
//         004814dc     FMUL       float ptr [DAT_00571e50]                         = 7Bh    {
//                              rmm_base.cpp:733 (4)
//         004814e2     MOV        this,dword ptr [ESP + tile_type]
//                              rmm_base.cpp:734 (78)
//         004814e6     MOV        EDX,dword ptr [ESP + param_5]
//         004814ea     FSUBR      float ptr [ESP + ty]
//         004814ee     MOV        byte ptr [this->_padding_],0x9
//         004814f1     MOV        EAX,dword ptr [EDX]
//         004814f3     MOV        this,dword ptr [ESP + param_3]
//         004814f7     FSTP       float ptr [ESP + tile_type]
//         004814fb     FLD        float ptr [ESP + hcost]
//         004814ff     CMP        EAX,this
//         00481501     JLE        LAB_0048150b
//         00481503     FSUB       float ptr [DAT_00571e54]                         = 85h
//         00481509     JMP        LAB_00481511
//                               LAB_0048150b                                                 XREF[1]:     00481501(j)
//         0048150b     FSUB       float ptr [DAT_00571e58]                         = 85h
//                               LAB_00481511                                                 XREF[1]:     00481509(j)
//         00481511     FLD        float ptr [ESP + tile_type]
//         00481515     MOV        EDX,dword ptr [ESP + map_h]
//         00481519     MOV        EAX,dword ptr [ESP + param_1]
//         0048151d     FADD       ST0,ST1
//         0048151f     PUSH       this
//         00481520     MOV        this,dword ptr [ESP + tile_type]
//         00481524     FSTP       float ptr [ESP]=>local_38
//         00481527     PUSH       this
//         00481528     PUSH       EDX
//         00481529     PUSH       EDI
//         0048152a     PUSH       EAX
//         0048152b     MOV        this,ESI
//         0048152d     FSTP       ST0
//         0048152f     CALL       RGE_Random_Map_Module::push_stack                void push_stack(RGE_Random_Map_Module * this,
//                              rmm_base.cpp:737 (10)
//         00481534     MOV        this,dword ptr [ESP + param_3]
//         00481538     MOV        EDX,dword ptr [ESP + param_2]
//         0048153c     JMP        LAB_00481558
//                               LAB_0048153e                                                 XREF[1]:     004814c4(j)
//                              rmm_base.cpp:738 (7)
//         0048153e     MOV        this,dword ptr [ESP + tile_type]
//         00481542     MOV        byte ptr [this->_padding_],0x1
//                              rmm_base.cpp:740 (19)
//         00481545     MOV        this,dword ptr [ESP + param_3]
//         00481549     MOV        EDX,dword ptr [ESP + param_2]
//         0048154d     JMP        LAB_00481558
//                               LAB_0048154f                                                 XREF[1]:     0048148d(j)
//         0048154f     CMP        BL,0x2
//         00481552     JZ         LAB_004818de
//                               LAB_00481558                                                 XREF[6]:     00481294(j), 00481469(j),
//                                                                                                         004814cc(j), 004814d8(j),
//                                                                                                         0048153c(j), 0048154d(j)
//                              rmm_base.cpp:751 (10)
//         00481558     CMP        EDX,dword ptr [ESP + local_4]
//         0048155c     JGE        LAB_004817c2
//                              rmm_base.cpp:753 (26)
//         00481562     MOV        EBX,dword ptr [ESP + param_4]
//         00481566     FLD        float ptr [ESP + cost]
//         0048156a     CMP        dword ptr [EBX],EDX
//         0048156c     JLE        LAB_00481576
//         0048156e     FSUB       float ptr [null_00571e48]                        = align(2)
//         00481574     JMP        LAB_0048157c
//                               LAB_00481576                                                 XREF[1]:     0048156c(j)
//         00481576     FSUB       float ptr [DAT_00571e4c]
//                               LAB_0048157c                                                 XREF[1]:     00481574(j)
//                              rmm_base.cpp:754 (3)
//         0048157c     LEA        EDI,[EDX + 0x1]
//                              rmm_base.cpp:755 (23)
//         0048157f     MOV        EDX,dword ptr [ESI + 0x24]
//         00481582     LEA        EBP,[this->_padding_*0x4 + 0x0]
//         00481589     FSTP       float ptr [ESP + hcost]
//         0048158d     MOV        EAX,dword ptr [EDX + EBP*0x1]
//         00481590     LEA        EDX,[EAX + EDI*0x1]
//         00481593     MOV        AL,byte ptr [EAX + EDI*0x1]
//                              rmm_base.cpp:756 (4)
//         00481596     TEST       AL,AL
//         00481598     JNZ        LAB_00481617
//                              rmm_base.cpp:759 (19)
//         0048159a     MOV        this,dword ptr [ESI + 0x10]
//         0048159d     LEA        EAX,[EDI + EDI*0x2]
//         004815a0     MOV        this,dword ptr [this->_padding_ + EBP*0x1]
//         004815a3     MOV        AL,byte ptr [ECX + EAX*0x8 + this+0x5]
//         004815a7     AND        AL,0x1f
//         004815a9     MOV        byte ptr [ESP + tcost],AL
//                              rmm_base.cpp:760 (33)
//         004815ad     MOV        EAX,dword ptr [ESP + param_6]
//         004815b1     MOV        this,dword ptr [ESP + tcost]
//         004815b5     AND        this,0xff
//         004815bb     FLD        float ptr [EAX + this->_padding_*0x4]
//         004815be     FCOMP      float ptr [null_00571e38]                        = align(18)
//         004815c4     LEA        this,[EAX + this->_padding_*0x4]
//         004815c7     FNSTSW     AX
//         004815c9     TEST       AH,0x41
//         004815cc     JNZ        LAB_00481609
//                              rmm_base.cpp:762 (6)
//         004815ce     FLD        float ptr [ESP + ty]
//         004815d2     FADD       float ptr [this->_padding_]
//                              rmm_base.cpp:764 (42)
//         004815d4     MOV        EAX,dword ptr [ESP + param_1]
//         004815d8     PUSH       this
//         004815d9     MOV        byte ptr [EDX],0x5
//         004815dc     MOV        EDX,dword ptr [ESP + param_3]
//         004815e0     FSTP       float ptr [ESP + tile_type]
//         004815e4     FLD        float ptr [ESP + tile_type]
//         004815e8     FADD       float ptr [ESP + hcost]
//         004815ec     MOV        this,dword ptr [ESP + tile_type]
//         004815f0     FSTP       float ptr [ESP]=>local_38
//         004815f3     PUSH       this
//         004815f4     PUSH       EDX
//         004815f5     PUSH       EDI
//         004815f6     PUSH       EAX
//         004815f7     MOV        this,ESI
//         004815f9     CALL       RGE_Random_Map_Module::push_stack                void push_stack(RGE_Random_Map_Module * this,
//                              rmm_base.cpp:767 (11)
//         004815fe     MOV        this,dword ptr [ESP + param_3]
//         00481602     MOV        byte ptr [ESP + calc_cost+0x3],0x1
//         00481607     JMP        LAB_00481626
//                               LAB_00481609                                                 XREF[1]:     004815cc(j)
//                              rmm_base.cpp:769 (3)
//         00481609     MOV        byte ptr [EDX],0x1
//                              rmm_base.cpp:773 (19)
//         0048160c     MOV        this,dword ptr [ESP + param_3]
//         00481610     MOV        byte ptr [ESP + calc_cost+0x3],0x0
//         00481615     JMP        LAB_00481626
//                               LAB_00481617                                                 XREF[1]:     00481598(j)
//         00481617     CMP        AL,0x2
//         00481619     JZ         LAB_00481900
//                              rmm_base.cpp:780 (7)
//         0048161f     CMP        AL,0x1
//         00481621     SETNZ      byte ptr [ESP + calc_cost+0x3]
//                               LAB_00481626                                                 XREF[2]:     00481607(j), 00481615(j)
//                              rmm_base.cpp:786 (8)
//         00481626     TEST       this,this
//         00481628     JLE        LAB_00481700
//                              rmm_base.cpp:789 (26)
//         0048162e     MOV        EDX,dword ptr [ESI + 0x24]
//         00481631     LEA        EBX,[this->_padding_ + -0x1]
//         00481634     MOV        dword ptr [ESP + map_h],EBX
//         00481638     MOV        EAX,dword ptr [EDX + EBX*0x4]
//         0048163b     LEA        EBP,[EBX*0x4 + 0x0]
//         00481642     LEA        EDX,[EAX + EDI*0x1]
//         00481645     MOV        AL,byte ptr [EAX + EDI*0x1]
//                              rmm_base.cpp:790 (8)
//         00481648     TEST       AL,AL
//         0048164a     JNZ        LAB_004816f8
//                              rmm_base.cpp:793 (13)
//         00481650     MOV        EAX,dword ptr [ESI + 0x10]
//         00481653     LEA        EBX,[EDI + EDI*0x2]
//         00481656     MOV        EAX,dword ptr [EAX + EBP*0x1]
//         00481659     MOV        AL,byte ptr [EAX + EBX*0x8 + 0x5]
//                              rmm_base.cpp:794 (38)
//         0048165d     MOV        EBX,dword ptr [ESP + param_6]
//         00481661     AND        AL,0x1f
//         00481663     MOV        byte ptr [ESP + tcost],AL
//         00481667     MOV        EAX,dword ptr [ESP + tcost]
//         0048166b     AND        EAX,0xff
//         00481670     FLD        float ptr [EBX + EAX*0x4]
//         00481673     FCOMP      float ptr [null_00571e38]                        = align(18)
//         00481679     LEA        EBX,[EBX + EAX*0x4]
//         0048167c     FNSTSW     AX
//         0048167e     TEST       AH,0x41
//         00481681     JNZ        LAB_004816ef
//                              rmm_base.cpp:796 (16)
//         00481683     MOV        AL,byte ptr [ESP + calc_cost+0x1]
//         00481687     TEST       AL,AL
//         00481689     JZ         LAB_00481700
//         0048168b     MOV        AL,byte ptr [ESP + calc_cost+0x3]
//         0048168f     TEST       AL,AL
//         00481691     JZ         LAB_00481700
//                              rmm_base.cpp:798 (8)
//         00481693     FLD        float ptr [EBX]
//         00481695     FMUL       float ptr [DAT_00571e50]                         = 7Bh    {
//                              rmm_base.cpp:800 (78)
//         0048169b     MOV        this,dword ptr [ESP + param_5]
//         0048169f     FSUBR      float ptr [ESP + ty]
//         004816a3     MOV        byte ptr [EDX],0xa
//         004816a6     MOV        EDX,dword ptr [this->_padding_]
//         004816a8     MOV        EAX,dword ptr [ESP + param_3]
//         004816ac     FSTP       float ptr [ESP + tile_type]
//         004816b0     FLD        float ptr [ESP + hcost]
//         004816b4     CMP        EDX,EAX
//         004816b6     JGE        LAB_004816c0
//         004816b8     FSUB       float ptr [DAT_00571e5c]                         = CDh
//         004816be     JMP        LAB_004816c6
//                               LAB_004816c0                                                 XREF[1]:     004816b6(j)
//         004816c0     FSUB       float ptr [DAT_00571e60]                         = CDh
//                               LAB_004816c6                                                 XREF[1]:     004816be(j)
//         004816c6     FLD        float ptr [ESP + tile_type]
//         004816ca     MOV        EAX,dword ptr [ESP + tile_type]
//         004816ce     MOV        EDX,dword ptr [ESP + param_1]
//         004816d2     FADD       ST0,ST1
//         004816d4     PUSH       this
//         004816d5     MOV        this,dword ptr [ESP + map_h]
//         004816d9     FSTP       float ptr [ESP]=>local_38
//         004816dc     PUSH       EAX
//         004816dd     PUSH       this
//         004816de     PUSH       EDI
//         004816df     PUSH       EDX
//         004816e0     MOV        this,ESI
//         004816e2     FSTP       ST0
//         004816e4     CALL       RGE_Random_Map_Module::push_stack                void push_stack(RGE_Random_Map_Module * this,
//                              rmm_base.cpp:803 (6)
//         004816e9     MOV        this,dword ptr [ESP + param_3]
//         004816ed     JMP        LAB_00481700
//                               LAB_004816ef                                                 XREF[1]:     00481681(j)
//                              rmm_base.cpp:804 (3)
//         004816ef     MOV        byte ptr [EDX],0x1
//                              rmm_base.cpp:806 (14)
//         004816f2     MOV        this,dword ptr [ESP + param_3]
//         004816f6     JMP        LAB_00481700
//                               LAB_004816f8                                                 XREF[1]:     0048164a(j)
//         004816f8     CMP        AL,0x2
//         004816fa     JZ         LAB_00481922
//                               LAB_00481700                                                 XREF[5]:     00481628(j), 00481689(j),
//                                                                                                         00481691(j), 004816ed(j),
//                                                                                                         004816f6(j)
//                              rmm_base.cpp:816 (10)
//         00481700     CMP        this,dword ptr [ESP + map_w]
//         00481704     JGE        LAB_004817c2
//                              rmm_base.cpp:819 (12)
//         0048170a     MOV        EAX,dword ptr [ESI + 0x24]
//         0048170d     INC        this
//         0048170e     MOV        EDX,dword ptr [EAX + this->_padding_*0x4]
//         00481711     MOV        AL,byte ptr [EDX + EDI*0x1]
//         00481714     ADD        EDX,EDI
//                              rmm_base.cpp:820 (8)
//         00481716     TEST       AL,AL
//         00481718     JNZ        LAB_004817ba
//                              rmm_base.cpp:823 (13)
//         0048171e     MOV        EAX,dword ptr [ESI + 0x10]
//         00481721     LEA        EBX,[EDI + EDI*0x2]
//         00481724     MOV        EAX,dword ptr [EAX + this->_padding_*0x4]
//         00481727     MOV        AL,byte ptr [EAX + EBX*0x8 + 0x5]
//                              rmm_base.cpp:824 (38)
//         0048172b     MOV        EBX,dword ptr [ESP + param_6]
//         0048172f     AND        AL,0x1f
//         00481731     MOV        byte ptr [ESP + tcost],AL
//         00481735     MOV        EAX,dword ptr [ESP + tcost]
//         00481739     AND        EAX,0xff
//         0048173e     FLD        float ptr [EBX + EAX*0x4]
//         00481741     FCOMP      float ptr [null_00571e38]                        = align(18)
//         00481747     LEA        EBX,[EBX + EAX*0x4]
//         0048174a     FNSTSW     AX
//         0048174c     TEST       AH,0x41
//         0048174f     JNZ        LAB_004817b5
//                              rmm_base.cpp:826 (16)
//         00481751     MOV        AL,byte ptr [ESP + calc_cost+0x2]
//         00481755     TEST       AL,AL
//         00481757     JZ         LAB_004817c2
//         00481759     MOV        AL,byte ptr [ESP + calc_cost+0x3]
//         0048175d     TEST       AL,AL
//         0048175f     JZ         LAB_004817c2
//                              rmm_base.cpp:828 (12)
//         00481761     FLD        float ptr [EBX]
//         00481763     FMUL       float ptr [DAT_00571e50]                         = 7Bh    {
//         00481769     FSUBR      float ptr [ESP + ty]
//                              rmm_base.cpp:829 (3)
//         0048176d     MOV        byte ptr [EDX],0xb
//                              rmm_base.cpp:830 (67)
//         00481770     MOV        EDX,dword ptr [ESP + param_5]
//         00481774     MOV        EAX,dword ptr [EDX]
//         00481776     MOV        EDX,dword ptr [ESP + param_3]
//         0048177a     FSTP       float ptr [ESP + tile_type]
//         0048177e     FLD        float ptr [ESP + hcost]
//         00481782     CMP        EAX,EDX
//         00481784     JLE        LAB_0048178e
//         00481786     FSUB       float ptr [DAT_00571e5c]                         = CDh
//         0048178c     JMP        LAB_00481794
//                               LAB_0048178e                                                 XREF[1]:     00481784(j)
//         0048178e     FSUB       float ptr [DAT_00571e60]                         = CDh
//                               LAB_00481794                                                 XREF[1]:     0048178c(j)
//         00481794     FLD        float ptr [ESP + tile_type]
//         00481798     MOV        EDX,dword ptr [ESP + tile_type]
//         0048179c     MOV        EAX,dword ptr [ESP + param_1]
//         004817a0     FADD       ST0,ST1
//         004817a2     PUSH       this
//         004817a3     FSTP       float ptr [ESP]=>local_38
//         004817a6     PUSH       EDX
//         004817a7     PUSH       this
//         004817a8     PUSH       EDI
//         004817a9     PUSH       EAX
//         004817aa     MOV        this,ESI
//         004817ac     FSTP       ST0
//         004817ae     CALL       RGE_Random_Map_Module::push_stack                void push_stack(RGE_Random_Map_Module * this,
//                              rmm_base.cpp:833 (2)
//         004817b3     JMP        LAB_004817c2
//                               LAB_004817b5                                                 XREF[1]:     0048174f(j)
//                              rmm_base.cpp:834 (3)
//         004817b5     MOV        byte ptr [EDX],0x1
//                              rmm_base.cpp:836 (10)
//         004817b8     JMP        LAB_004817c2
//                               LAB_004817ba                                                 XREF[1]:     00481718(j)
//         004817ba     CMP        AL,0x2
//         004817bc     JZ         LAB_00481944
//                               LAB_004817c2                                                 XREF[6]:     0048155c(j), 00481704(j),
//                                                                                                         00481757(j), 0048175f(j),
//                                                                                                         004817b3(j), 004817b8(j)
//                              rmm_base.cpp:846 (106)
//         004817c2     LEA        this=>ty,[ESP + 0x24]
//         004817c6     LEA        EDX=>param_3,[ESP + 0x40]
//         004817ca     PUSH       this
//         004817cb     MOV        this,dword ptr [ESP + param_1]
//         004817cf     LEA        EAX=>param_2,[ESP + 0x40]
//         004817d3     PUSH       EDX
//         004817d4     PUSH       EAX
//         004817d5     PUSH       this
//         004817d6     MOV        this,ESI
//         004817d8     CALL       RGE_Random_Map_Module::pop_stack                 Map_Stack * pop_stack(RGE_Random_Map_Module *
//         004817dd     TEST       EAX,EAX
//         004817df     JZ         LAB_00481966
//         004817e5     MOV        this,dword ptr [ESP + param_4]
//         004817e9     MOV        EDX,dword ptr [ESP + param_2]
//         004817ed     MOV        EAX,EDX
//         004817ef     MOV        EBP,dword ptr [this->_padding_]
//         004817f1     MOV        this,dword ptr [ESP + param_5]
//         004817f5     SUB        EAX,EBP
//         004817f7     MOV        EBP,dword ptr [this->_padding_]
//         004817f9     MOV        this,dword ptr [ESP + param_3]
//         004817fd     MOV        EDI,this
//         004817ff     MOV        EBX,EAX
//         00481801     SUB        EDI,EBP
//         00481803     IMUL       EBX,EAX
//         00481806     MOV        EAX,EDI
//         00481808     IMUL       EAX,EDI
//         0048180b     ADD        EBX,EAX
//         0048180d     MOV        dword ptr [ESP + map_h],EBX
//         00481811     FILD       dword ptr [ESP + map_h]
//         00481815     FSQRT
//         00481817     FST        float ptr [ESP + cost]
//         0048181b     FCOMP      double ptr [null_00571e40]                       = align(10)
//         00481821     FNSTSW     AX
//         00481823     TEST       AH,0x40
//         00481826     JZ         LAB_004810e2
//                               LAB_0048182c                                                 XREF[1]:     004810dc(j)
//                              rmm_base.cpp:568 (15)
//         0048182c     MOV        this,dword ptr [ESP + param_1]
//         00481830     MOV        EAX,dword ptr [ECX + this->map_row_offset]
//         00481833     TEST       EAX,EAX
//         00481835     JZ         LAB_0048195a
//                              rmm_base.cpp:569 (7)
//         0048183b     MOV        dword ptr [EAX + 0x14],0x0
//                              rmm_base.cpp:570 (2)
//         00481842     MOV        AL,0x1
//                              rmm_base.cpp:849 (10)
//         00481844     POP        EDI
//         00481845     POP        ESI
//         00481846     POP        EBP
//         00481847     POP        EBX
//         00481848     ADD        ESP,0x24
//         0048184b     RET        0x18
//                               LAB_0048184e                                                 XREF[1]:     004811a5(j)
//                              rmm_base.cpp:603 (6)
//         0048184e     MOV        EAX,dword ptr [ESI + 0x24]
//         00481851     MOV        this,dword ptr [EAX + EBP*0x4]
//                              rmm_base.cpp:604 (12)
//         00481854     MOV        EAX,dword ptr [ESP + param_4]
//         00481858     MOV        byte ptr [this->_padding_ + EDX*0x1],0x7
//         0048185c     MOV        EDX,dword ptr [ESP + param_2]
//                              rmm_base.cpp:605 (6)
//         00481860     MOV        this,dword ptr [ESP + param_5]
//         00481864     MOV        dword ptr [EAX],EDX
//                              rmm_base.cpp:606 (4)
//         00481866     MOV        AL,0x1
//         00481868     MOV        dword ptr [this->_padding_],EBP
//                              rmm_base.cpp:849 (10)
//         0048186a     POP        EDI
//         0048186b     POP        ESI
//         0048186c     POP        EBP
//         0048186d     POP        EBX
//         0048186e     ADD        ESP,0x24
//         00481871     RET        0x18
//                               LAB_00481874                                                 XREF[1]:     0048127e(j)
//                              rmm_base.cpp:641 (6)
//         00481874     MOV        EAX,dword ptr [ESI + 0x24]
//         00481877     MOV        this,dword ptr [EAX + EBP*0x4]
//                              rmm_base.cpp:642 (14)
//         0048187a     MOV        EAX,dword ptr [ESP + param_4]
//         0048187e     MOV        byte ptr [this->_padding_ + EDX*0x1],0x6
//         00481882     MOV        EDX,dword ptr [ESP + param_2]
//         00481886     MOV        dword ptr [EAX],EDX
//                              rmm_base.cpp:643 (2)
//         00481888     MOV        dword ptr [EBX],EBP
//                              rmm_base.cpp:644 (2)
//         0048188a     MOV        AL,0x1
//                              rmm_base.cpp:849 (10)
//         0048188c     POP        EDI
//         0048188d     POP        ESI
//         0048188e     POP        EBP
//         0048188f     POP        EBX
//         00481890     ADD        ESP,0x24
//         00481893     RET        0x18
//                               LAB_00481896                                                 XREF[1]:     00481366(j)
//                              rmm_base.cpp:679 (6)
//         00481896     MOV        EDX,dword ptr [ESI + 0x24]
//         00481899     MOV        EAX,dword ptr [EDX + this->_padding_*0x4]
//                              rmm_base.cpp:680 (8)
//         0048189c     MOV        this,dword ptr [ESP + param_4]
//         004818a0     MOV        byte ptr [EAX + EDI*0x1],0x4
//                              rmm_base.cpp:681 (12)
//         004818a4     MOV        EAX,dword ptr [ESP + param_5]
//         004818a8     MOV        EDX,dword ptr [ESP + param_3]
//         004818ac     MOV        dword ptr [this->_padding_],EDI
//         004818ae     MOV        dword ptr [EAX],EDX
//                              rmm_base.cpp:682 (2)
//         004818b0     MOV        AL,0x1
//                              rmm_base.cpp:849 (10)
//         004818b2     POP        EDI
//         004818b3     POP        ESI
//         004818b4     POP        EBP
//         004818b5     POP        EBX
//         004818b6     ADD        ESP,0x24
//         004818b9     RET        0x18
//                               LAB_004818bc                                                 XREF[1]:     0048145f(j)
//                              rmm_base.cpp:712 (6)
//         004818bc     MOV        this,dword ptr [ESI + 0x24]
//         004818bf     MOV        EDX,dword ptr [this->_padding_ + EAX*0x4]
//                              rmm_base.cpp:713 (8)
//         004818c2     MOV        this,dword ptr [ESP + param_4]
//         004818c6     MOV        byte ptr [EDX + EDI*0x1],0x8
//                              rmm_base.cpp:714 (8)
//         004818ca     MOV        EDX,dword ptr [ESP + param_5]
//         004818ce     MOV        dword ptr [this->_padding_],EDI
//         004818d0     MOV        dword ptr [EDX],EAX
//                              rmm_base.cpp:715 (2)
//         004818d2     MOV        AL,0x1
//                              rmm_base.cpp:849 (10)
//         004818d4     POP        EDI
//         004818d5     POP        ESI
//         004818d6     POP        EBP
//         004818d7     POP        EBX
//         004818d8     ADD        ESP,0x24
//         004818db     RET        0x18
//                               LAB_004818de                                                 XREF[1]:     00481552(j)
//                              rmm_base.cpp:742 (6)
//         004818de     MOV        this,dword ptr [ESI + 0x24]
//         004818e1     MOV        EDX,dword ptr [this->_padding_ + EAX*0x4]
//                              rmm_base.cpp:743 (8)
//         004818e4     MOV        this,dword ptr [ESP + param_4]
//         004818e8     MOV        byte ptr [EDX + EDI*0x1],0x9
//                              rmm_base.cpp:744 (8)
//         004818ec     MOV        EDX,dword ptr [ESP + param_5]
//         004818f0     MOV        dword ptr [this->_padding_],EDI
//         004818f2     MOV        dword ptr [EDX],EAX
//                              rmm_base.cpp:745 (2)
//         004818f4     MOV        AL,0x1
//                              rmm_base.cpp:849 (10)
//         004818f6     POP        EDI
//         004818f7     POP        ESI
//         004818f8     POP        EBP
//         004818f9     POP        EBX
//         004818fa     ADD        ESP,0x24
//         004818fd     RET        0x18
//                               LAB_00481900                                                 XREF[1]:     00481619(j)
//                              rmm_base.cpp:775 (6)
//         00481900     MOV        EAX,dword ptr [ESI + 0x24]
//         00481903     MOV        this,dword ptr [EAX + this->_padding_*0x4]
//                              rmm_base.cpp:777 (16)
//         00481906     MOV        EAX,dword ptr [ESP + param_5]
//         0048190a     MOV        byte ptr [this->_padding_ + EDI*0x1],0x5
//         0048190e     MOV        EDX,dword ptr [ESP + param_3]
//         00481912     MOV        dword ptr [EBX],EDI
//         00481914     MOV        dword ptr [EAX],EDX
//                              rmm_base.cpp:778 (2)
//         00481916     MOV        AL,0x1
//                              rmm_base.cpp:849 (10)
//         00481918     POP        EDI
//         00481919     POP        ESI
//         0048191a     POP        EBP
//         0048191b     POP        EBX
//         0048191c     ADD        ESP,0x24
//         0048191f     RET        0x18
//                               LAB_00481922                                                 XREF[1]:     004816fa(j)
//                              rmm_base.cpp:808 (3)
//         00481922     MOV        this,dword ptr [ESI + 0x24]
//                              rmm_base.cpp:809 (7)
//         00481925     MOV        EAX,dword ptr [ESP + param_4]
//         00481929     MOV        EDX,dword ptr [this->_padding_ + EBX*0x4]
//                              rmm_base.cpp:810 (12)
//         0048192c     MOV        this,dword ptr [ESP + param_5]
//         00481930     MOV        byte ptr [EDX + EDI*0x1],0xa
//         00481934     MOV        dword ptr [EAX],EDI
//         00481936     MOV        dword ptr [this->_padding_],EBX
//                              rmm_base.cpp:811 (2)
//         00481938     MOV        AL,0x1
//                              rmm_base.cpp:849 (10)
//         0048193a     POP        EDI
//         0048193b     POP        ESI
//         0048193c     POP        EBP
//         0048193d     POP        EBX
//         0048193e     ADD        ESP,0x24
//         00481941     RET        0x18
//                               LAB_00481944                                                 XREF[1]:     004817bc(j)
//                              rmm_base.cpp:838 (6)
//         00481944     MOV        EDX,dword ptr [ESI + 0x24]
//         00481947     MOV        EAX,dword ptr [EDX + this->_padding_*0x4]
//                              rmm_base.cpp:839 (8)
//         0048194a     MOV        EDX,dword ptr [ESP + param_4]
//         0048194e     MOV        byte ptr [EAX + EDI*0x1],0xb
//                              rmm_base.cpp:840 (8)
//         00481952     MOV        EAX,dword ptr [ESP + param_5]
//         00481956     MOV        dword ptr [EDX],EDI
//         00481958     MOV        dword ptr [EAX],this
//                               LAB_0048195a                                                 XREF[1]:     00481835(j)
//                              rmm_base.cpp:841 (2)
//         0048195a     MOV        AL,0x1
//                              rmm_base.cpp:849 (22)
//         0048195c     POP        EDI
//         0048195d     POP        ESI
//         0048195e     POP        EBP
//         0048195f     POP        EBX
//         00481960     ADD        ESP,0x24
//         00481963     RET        0x18
//                               LAB_00481966                                                 XREF[2]:     0048109c(j), 004817df(j)
//         00481966     POP        EDI
//         00481967     POP        ESI
//         00481968     POP        EBP
//         00481969     XOR        AL,AL
//         0048196b     POP        EBX
//         0048196c     ADD        ESP,0x24
//         0048196f     RET        0x18
//         00481972     ??         90h
//         00481973     NOP
//         00481974     NOP
//         00481975     NOP
//         00481976     NOP
//         00481977     NOP
//         00481978     NOP
//         00481979     NOP
//         0048197a     NOP
//         0048197b     NOP
//         0048197c     NOP
//         0048197d     NOP
//         0048197e     NOP
//         0048197f     NOP
    return 0;
}

