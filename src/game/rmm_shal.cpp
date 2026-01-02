#include "../common.h"
#include "rmm_shal.h"

RGE_RMM_Shallows_Generator::RGE_RMM_Shallows_Generator(RGE_Map* param_1, RGE_Random_Map_Module* param_2, RGE_Shallows_Info* param_3) {
    /* TODO: Stub */
//                              undefined __thiscall RGE_RMM_Shallows_Generator(RGE_RMM_Shallows_Gen
//              undefined         <UNASSIGNED>   <RETURN>
//              RGE_RMM_Shallo    ECX:4 (auto)   this
//              RGE_Map *         Stack[0x4]:4   param_1                   XREF[1]:     00487018(R)
//              RGE_Random_Map    Stack[0x8]:4   param_2                   XREF[1]:     00487010(R)
//              RGE_Shallows_I    Stack[0xc]:4   param_3                   XREF[1]:     00487028(R)
//                               ??0RGE_RMM_Shallows_Generator@@QAE@PAVRGE_Map@@PAVRGE_Rando  XREF[1]:     add_shallows_module:00488821(c)
//                               RGE_RMM_Shallows_Generator::RGE_RMM_Shallows_Generator
//                              rmm_shal.cpp:34 (24)
//         00487010     MOV        EAX,dword ptr [ESP + param_2]
//         00487014     PUSH       EBX
//         00487015     PUSH       ESI
//         00487016     MOV        EBX,this
//         00487018     MOV        this,dword ptr [ESP + param_1]
//         0048701c     PUSH       EDI
//         0048701d     PUSH       0x1
//         0048701f     PUSH       EAX
//         00487020     PUSH       this
//         00487021     MOV        this,EBX
//         00487023     CALL       RGE_Random_Map_Module::RGE_Random_Map_Module     undefined RGE_Random_Map_Module(RGE_Random_Ma
//                              rmm_shal.cpp:37 (25)
//         00487028     MOV        ESI,dword ptr [ESP + param_3]
//         0048702c     LEA        EDI,[EBX + 0x30]
//         0048702f     MOV        this,0xc7
//         00487034     MOV        dword ptr [EBX],RGE_RMM_Shallows_Generator::`v   = 00487050
//         0048703a     MOV        dword ptr [EBX + 0x1c],0x3f8ccccd
//                              rmm_shal.cpp:38 (10)
//         00487041     MOV        EAX,EBX
//         00487043     MOVSD.REP  ES:EDI,ESI
//         00487045     POP        EDI
//         00487046     POP        ESI
//         00487047     POP        EBX
//         00487048     RET        0xc
//         0048704b     ??         90h
//         0048704c     NOP
//         0048704d     NOP
//         0048704e     NOP
//         0048704f     NOP
}

uchar RGE_RMM_Shallows_Generator::generate() {
    /* TODO: Stub */
//                              uchar __thiscall generate(RGE_RMM_Shallows_Generator * this)
//              uchar             AL:1           <RETURN>
//              RGE_RMM_Shallo    ECX:4 (auto)   this
//              undefined4        Stack[-0x4]:4  local_4                   XREF[3]:     004870a0(W), 004871d9(R), 004871de(W)
//              undefined4        Stack[-0x8]:4  local_8                   XREF[3]:     004870b0(W), 004871b3(R), 004871cc(R)
//              long              Stack[-0xc]:4  index2
//                               ?generate@RGE_RMM_Shallows_Generator@@UAEEXZ                 XREF[1]:     00571ee4(*)
//                               RGE_RMM_Shallows_Generator::generate
//                              rmm_shal.cpp:42 (9)
//         00487050     SUB        ESP,0x8
//         00487053     PUSH       EBX
//         00487054     PUSH       EBP
//         00487055     PUSH       ESI
//         00487056     PUSH       EDI
//         00487057     MOV        ESI,this
//                              rmm_shal.cpp:53 (5)
//         00487059     CALL       RGE_Random_Map_Module::clear_stack               void clear_stack(RGE_Random_Map_Module * this)
//                              rmm_shal.cpp:56 (15)
//         0048705e     MOV        EAX,dword ptr [ESI + 0x348]
//         00487064     XOR        EBX,EBX
//         00487066     TEST       EAX,EAX
//         00487068     JLE        LAB_00487093
//                               LAB_0048706a                                                 XREF[1]:     00487091(j)
//         0048706a     LEA        EBP,[EBX + 0x1]
//                              rmm_shal.cpp:57 (6)
//         0048706d     CMP        EBP,EAX
//         0048706f     MOV        EDI,EBP
//         00487071     JGE        LAB_00487087
//                               LAB_00487073                                                 XREF[1]:     00487085(j)
//                              rmm_shal.cpp:58 (20)
//         00487073     PUSH       EDI
//         00487074     PUSH       EBX
//         00487075     MOV        this,ESI
//         00487077     CALL       RGE_RMM_Shallows_Generator::make_tribe_connect   void make_tribe_connections(RGE_RMM_Shallows_
//         0048707c     MOV        EAX,dword ptr [ESI + 0x348]
//         00487082     INC        EDI
//         00487083     CMP        EDI,EAX
//         00487085     JL         LAB_00487073
//                               LAB_00487087                                                 XREF[1]:     00487071(j)
//                              rmm_shal.cpp:56 (12)
//         00487087     MOV        EAX,dword ptr [ESI + 0x348]
//         0048708d     MOV        EBX,EBP
//         0048708f     CMP        EBX,EAX
//         00487091     JL         LAB_0048706a
//                               LAB_00487093                                                 XREF[1]:     00487068(j)
//                              rmm_shal.cpp:61 (23)
//         00487093     MOV        EAX,dword ptr [ESI + 0x348]
//         00487099     MOV        this,0x2
//         0048709e     ADD        EAX,this
//         004870a0     MOV        dword ptr [ESP + local_4],this
//         004870a4     MOV        dword ptr [ESI + 0x348],EAX
//                              rmm_shal.cpp:62 (3)
//         004870aa     LEA        EBP,[EAX + -0x1]
//                              rmm_shal.cpp:63 (7)
//         004870ad     ADD        EAX,-0x2
//         004870b0     MOV        dword ptr [ESP + local_8],EAX
//                               LAB_004870b4                                                 XREF[1]:     004871e2(j)
//                              rmm_shal.cpp:66 (2)
//         004870b4     XOR        EBX,EBX
//                               LAB_004870b6                                                 XREF[1]:     00487138(j)
//                              rmm_shal.cpp:69 (29)
//         004870b6     PUSH       0x45
//         004870b8     PUSH       s_C:\msdev\work\age1_x1\rmm_shal.c               = "C:\\msdev\\work\\age1_x1\\rmm_shal.cpp"
//         004870bd     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
//         004870c2     MOV        this,EAX
//         004870c4     MOV        EAX,dword ptr [ESI + 0x14]
//         004870c7     ADD        ESP,0x8
//         004870ca     DEC        EAX
//         004870cb     IMUL       this,EAX
//         004870ce     MOV        EAX,0x80010003
//                              rmm_shal.cpp:70 (49)
//         004870d3     PUSH       0x46
//         004870d5     IMUL       this
//         004870d7     ADD        EDX,this
//         004870d9     PUSH       s_C:\msdev\work\age1_x1\rmm_shal.c               = "C:\\msdev\\work\\age1_x1\\rmm_shal.cpp"
//         004870de     SAR        EDX,0xe
//         004870e1     MOV        this,EDX
//         004870e3     SHR        this,0x1f
//         004870e6     ADD        EDX,this
//         004870e8     MOV        EDI,EDX
//         004870ea     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
//         004870ef     MOV        EDX,dword ptr [ESI + 0x18]
//         004870f2     ADD        ESP,0x8
//         004870f5     MOV        this,EAX
//         004870f7     DEC        EDX
//         004870f8     IMUL       this,EDX
//         004870fb     MOV        EAX,0x80010003
//         00487100     IMUL       this
//         00487102     ADD        EDX,this
//                              rmm_shal.cpp:73 (37)
//         00487104     MOV        this,dword ptr [ESI + 0x10]
//         00487107     SAR        EDX,0xe
//         0048710a     MOV        EAX,EDX
//         0048710c     SHR        EAX,0x1f
//         0048710f     ADD        EDX,EAX
//         00487111     LEA        EAX,[EDI + EDI*0x2]
//         00487114     MOV        this,dword ptr [this->_padding_ + EDX*0x4]
//         00487117     MOV        AL,byte ptr [ECX + EAX*0x8 + this+0x5]
//         0048711b     AND        AL,0x1f
//         0048711d     CMP        AL,0x1
//         0048711f     JZ         LAB_00487136
//         00487121     CMP        AL,0x16
//         00487123     JZ         LAB_00487136
//         00487125     CMP        AL,0x4
//         00487127     JZ         LAB_00487136
//                              rmm_shal.cpp:76 (9)
//         00487129     MOV        dword ptr [ESI + EBP*0x8 + 0x30],EDI
//         0048712d     MOV        EBX,0x1
//                              rmm_shal.cpp:77 (4)
//         00487132     MOV        dword ptr [ESI + EBP*0x8 + 0x34],EDX
//                               LAB_00487136                                                 XREF[3]:     0048711f(j), 00487123(j),
//                                                                                                         00487127(j)
//                              rmm_shal.cpp:67 (8)
//         00487136     TEST       EBX,EBX
//         00487138     JZ         LAB_004870b6
//                              rmm_shal.cpp:81 (2)
//         0048713e     XOR        EBX,EBX
//                               LAB_00487140                                                 XREF[1]:     004871c6(j)
//                              rmm_shal.cpp:84 (29)
//         00487140     PUSH       0x54
//         00487142     PUSH       s_C:\msdev\work\age1_x1\rmm_shal.c               = "C:\\msdev\\work\\age1_x1\\rmm_shal.cpp"
//         00487147     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
//         0048714c     MOV        EDX,dword ptr [ESI + 0x14]
//         0048714f     ADD        ESP,0x8
//         00487152     MOV        this,EAX
//         00487154     DEC        EDX
//         00487155     IMUL       this,EDX
//         00487158     MOV        EAX,0x80010003
//                              rmm_shal.cpp:85 (49)
//         0048715d     PUSH       0x55
//         0048715f     IMUL       this
//         00487161     ADD        EDX,this
//         00487163     PUSH       s_C:\msdev\work\age1_x1\rmm_shal.c               = "C:\\msdev\\work\\age1_x1\\rmm_shal.cpp"
//         00487168     SAR        EDX,0xe
//         0048716b     MOV        EAX,EDX
//         0048716d     SHR        EAX,0x1f
//         00487170     ADD        EDX,EAX
//         00487172     MOV        EDI,EDX
//         00487174     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
//         00487179     MOV        EDX,dword ptr [ESI + 0x18]
//         0048717c     ADD        ESP,0x8
//         0048717f     MOV        this,EAX
//         00487181     DEC        EDX
//         00487182     IMUL       this,EDX
//         00487185     MOV        EAX,0x80010003
//         0048718a     IMUL       this
//         0048718c     ADD        EDX,this
//                              rmm_shal.cpp:88 (37)
//         0048718e     MOV        this,dword ptr [ESI + 0x10]
//         00487191     SAR        EDX,0xe
//         00487194     MOV        EAX,EDX
//         00487196     SHR        EAX,0x1f
//         00487199     ADD        EDX,EAX
//         0048719b     LEA        EAX,[EDI + EDI*0x2]
//         0048719e     MOV        this,dword ptr [this->_padding_ + EDX*0x4]
//         004871a1     MOV        AL,byte ptr [ECX + EAX*0x8 + this+0x5]
//         004871a5     AND        AL,0x1f
//         004871a7     CMP        AL,0x1
//         004871a9     JZ         LAB_004871c4
//         004871ab     CMP        AL,0x16
//         004871ad     JZ         LAB_004871c4
//         004871af     CMP        AL,0x4
//         004871b1     JZ         LAB_004871c4
//                              rmm_shal.cpp:91 (13)
//         004871b3     MOV        EAX,dword ptr [ESP + local_8]
//         004871b7     MOV        EBX,0x1
//         004871bc     MOV        dword ptr [ESI + EAX*0x8 + 0x30],EDI
//                              rmm_shal.cpp:92 (4)
//         004871c0     MOV        dword ptr [ESI + EAX*0x8 + 0x34],EDX
//                               LAB_004871c4                                                 XREF[3]:     004871a9(j), 004871ad(j),
//                                                                                                         004871b1(j)
//                              rmm_shal.cpp:82 (8)
//         004871c4     TEST       EBX,EBX
//         004871c6     JZ         LAB_00487140
//                              rmm_shal.cpp:96 (28)
//         004871cc     MOV        EDX,dword ptr [ESP + local_8]
//         004871d0     MOV        this,ESI
//         004871d2     PUSH       EDX
//         004871d3     PUSH       EBP
//         004871d4     CALL       RGE_RMM_Shallows_Generator::make_tribe_connect   void make_tribe_connections(RGE_RMM_Shallows_
//         004871d9     MOV        EAX,dword ptr [ESP + local_4]
//         004871dd     DEC        EAX
//         004871de     MOV        dword ptr [ESP + local_4],EAX
//         004871e2     JNZ        LAB_004870b4
//                              rmm_shal.cpp:102 (10)
//         004871e8     POP        EDI
//         004871e9     POP        ESI
//         004871ea     POP        EBP
//         004871eb     MOV        AL,0x1
//         004871ed     POP        EBX
//         004871ee     ADD        ESP,0x8
//         004871f1     RET
//         004871f2     ??         90h
//         004871f3     NOP
//         004871f4     NOP
//         004871f5     NOP
//         004871f6     NOP
//         004871f7     NOP
//         004871f8     NOP
//         004871f9     NOP
//         004871fa     NOP
//         004871fb     NOP
//         004871fc     NOP
//         004871fd     NOP
//         004871fe     NOP
//         004871ff     NOP
    return 0;
}

void RGE_RMM_Shallows_Generator::make_tribe_connections(long param_1, long param_2) {
    /* TODO: Stub */
//                              void __thiscall make_tribe_connections(RGE_RMM_Shallows_Generator *
//              void              <VOID>         <RETURN>
//              RGE_RMM_Shallo    ECX:4 (auto)   this
//              long              Stack[0x4]:4   param_1                   XREF[1]:     00487206(R)
//              long              Stack[0x8]:4   param_2                   XREF[1]:     00487227(R)
//              float[40]         Stack[-0xa4]   terrain                   XREF[1,8]:   004872ee(W), 00487217(W), 0048725b(*), 00487276(W),
//                                                                                     00487213(*), 00487286(W), 0048727e(W), 00487299(W),
//                                                                                     0048728e(W)
//              Map_Stack         Stack[-0xbc]   stack                     XREF[2,10]:  0048761e(*), 00487660(*), 0048724b(*), 004873b9(*),
//                                                                                     004873f4(*), 0048742c(*), 00487470(*), 004875c8(*),
//                                                                                     0048762c(*), 0048766a(*), 0048767b(*), 004872ea(W)
//              float             Stack[-0xc0]:4 in_zone                   XREF[4]:     00487528(W), 0048752f(W), 00487592(R), 004875d9(R)
//              long              Stack[-0xc4]:4 tx2                       XREF[4]:     004872f2(W), 00487350(W), 0048736a(W), 00487372(R)
//              long              Stack[-0xc8]:4 done                      XREF[5]:     00487237(W), 00487264(R), 0048757b(W), 004875d5(R),
//                                                                                     004875ef(W)
//              long              Stack[-0xcc]:4 ty                        XREF[5]:     00487252(W), 0048725f(*), 004872b2(R), 004875fa(R),
//                                                                                     00487615(W)
//              long              Stack[-0xd0]:4 end_y                     XREF[4]:     004874b2(W), 004874b8(W), 0048758a(R), 0048758e(R)
//              long              Stack[-0xd4]:4 tx1                       XREF[5]:     00487245(W), 00487268(*), 004872a6(R), 00487601(R),
//                                                                                     00487611(W)
//              long              Stack[-0xd8]:4 end_x                     XREF[6]:     0048722e(W), 0048726d(R), 00487568(W), 0048756f(W),
//                                                                                     00487573(R), 004875e5(R)
//              long              Stack[-0xdc]:4 ty2                       XREF[16]:    004872c0(W), 00487313(W), 0048731a(W), 00487322(W),
//                                                                                     0048732e(W), 00487339(W), 00487345(W), 004873c5(R),
//                                                                                     00487400(R), 00487438(R), 004874da(R), 0048754e(R),
//                                                                                     0048760d(R), 00487622(*), 00487647(R), 00487652(*)
//              long              Stack[-0xe0]:4 y                         XREF[14]:    004872c6(W), 00487326(W), 00487332(W), 0048733e(W),
//                                                                                     0048734a(W), 004873c9(R), 00487404(R), 0048743c(R),
//                                                                                     0048749e(R), 0048750e(R), 00487609(R), 00487627(*),
//                                                                                     0048763d(R), 00487665(*)
//              long              Stack[-0xe4]:4 x
//                               ?make_tribe_connections@RGE_RMM_Shallows_Generator@@QAEXJJ@Z XREF[2]:     generate:00487077(c),
//                               RGE_RMM_Shallows_Generator::make_tribe_connections                        generate:004871d4(c)
//                              rmm_shal.cpp:106 (6)
//         00487200     SUB        ESP,0xe0
//                              rmm_shal.cpp:107 (13)
//         00487206     MOV        EAX,dword ptr [ESP + param_1]
//         0048720d     PUSH       EBX
//         0048720e     PUSH       EBP
//         0048720f     PUSH       ESI
//         00487210     MOV        ESI,this
//         00487212     PUSH       EDI
//                              rmm_shal.cpp:122 (56)
//         00487213     LEA        EDI=>terrain[2],[ESP + 0x54]
//         00487217     MOV        dword ptr [ESP + terrain[1]],0x0
//         0048721f     MOV        this,dword ptr [ESI + EAX*0x8 + 0x30]
//         00487223     MOV        EDX,dword ptr [ESI + EAX*0x8 + 0x34]
//         00487227     MOV        EAX,dword ptr [ESP + param_2]
//         0048722e     MOV        dword ptr [ESP + end_x],this
//         00487232     MOV        this,0x27
//         00487237     MOV        dword ptr [ESP + done],EDX
//         0048723b     MOV        EBX,dword ptr [ESI + EAX*0x8 + 0x30]
//         0048723f     MOV        EBP,dword ptr [ESI + EAX*0x8 + 0x34]
//         00487243     XOR        EAX,EAX
//         00487245     MOV        dword ptr [ESP + tx1],EBX
//         00487249     STOSD.REP  ES:EDI
//                              rmm_shal.cpp:127 (16)
//         0048724b     LEA        EAX=>stack.y,[ESP + 0x38]
//         0048724f     MOV        this,ESI
//         00487251     PUSH       EAX
//         00487252     MOV        dword ptr [ESP + ty],EBP
//         00487256     CALL       RGE_Random_Map_Module::init_stack                void init_stack(RGE_Random_Map_Module * this,
//                              rmm_shal.cpp:137 (75)
//         0048725b     LEA        this=>terrain[1],[ESP + 0x50]
//         0048725f     LEA        EDX=>ty,[ESP + 0x24]
//         00487263     PUSH       this
//         00487264     MOV        this,dword ptr [ESP + done]
//         00487268     LEA        EAX=>tx1,[ESP + 0x20]
//         0048726c     PUSH       EDX
//         0048726d     MOV        EDX,dword ptr [ESP + end_x]
//         00487271     PUSH       EAX
//         00487272     PUSH       this
//         00487273     PUSH       EDX
//         00487274     MOV        this,ESI
//         00487276     MOV        dword ptr [ESP + terrain[1]],0x3f800000
//         0048727e     MOV        dword ptr [ESP + terrain[3]],0x3f800000
//         00487286     MOV        dword ptr [ESP + terrain[2]],0x40e00000
//         0048728e     MOV        dword ptr [ESP + terrain[23]],0x41600000
//         00487299     MOV        dword ptr [ESP + terrain[5]],0x40000000
//         004872a1     CALL       RGE_Random_Map_Module::find_path                 uchar find_path(RGE_Random_Map_Module * this,
//                              rmm_shal.cpp:139 (24)
//         004872a6     MOV        EAX,dword ptr [ESP + tx1]
//         004872aa     CMP        EAX,EBX
//         004872ac     JNZ        LAB_00487687
//         004872b2     MOV        this,dword ptr [ESP + ty]
//         004872b6     CMP        this,EBP
//         004872b8     JNZ        LAB_00487687
//                              rmm_shal.cpp:145 (44)
//         004872be     XOR        EBP,EBP
//         004872c0     MOV        dword ptr [ESP + ty2],this
//         004872c4     CMP        EAX,EBP
//         004872c6     MOV        dword ptr [ESP + y],EAX
//         004872ca     JL         LAB_00487687
//         004872d0     CMP        EAX,dword ptr [ESI + 0x14]
//         004872d3     JGE        LAB_00487687
//         004872d9     CMP        this,EBP
//         004872db     JL         LAB_00487687
//         004872e1     CMP        this,dword ptr [ESI + 0x18]
//         004872e4     JGE        LAB_00487687
//                              rmm_shal.cpp:148 (4)
//         004872ea     MOV        dword ptr [ESP + stack.prev],EBP
//                              rmm_shal.cpp:149 (4)
//         004872ee     MOV        dword ptr [ESP + terrain[0]],EBP
//                              rmm_shal.cpp:150 (4)
//         004872f2     MOV        dword ptr [ESP + tx2],EBP
//                               LAB_004872f6                                                 XREF[1]:     00487619(j)
//                              rmm_shal.cpp:154 (28)
//         004872f6     MOV        EDX,dword ptr [ESI + 0x24]
//         004872f9     XOR        EBX,EBX
//         004872fb     MOV        EDX,dword ptr [EDX + this->_padding_*0x4]
//         004872fe     MOV        BL,byte ptr [EDX + EAX*0x1]
//         00487301     MOV        EDX,EBX
//         00487303     ADD        EDX,-0x4
//         00487306     CMP        EDX,0x7
//         00487309     JA         switchD_0048730b::default
//                               switchD_0048730b::switchD
//         0048730b     JMP        dword ptr [EDX*0x4 + switchD_0048730b::switchd   = 00487349
//                               switchD_0048730b::caseD_7                                    XREF[2]:     0048730b(j), 004876a0(*)
//                              rmm_shal.cpp:163 (5)
//         00487312     DEC        this
//         00487313     MOV        dword ptr [ESP + ty2],this
//                              rmm_shal.cpp:164 (2)
//         00487317     JMP        LAB_00487358
//                               switchD_0048730b::caseD_6                                    XREF[2]:     0048730b(j), 0048769c(*)
//                              rmm_shal.cpp:166 (5)
//         00487319     INC        this
//         0048731a     MOV        dword ptr [ESP + ty2],this
//                              rmm_shal.cpp:167 (2)
//         0048731e     JMP        LAB_00487358
//                               switchD_0048730b::caseD_b                                    XREF[2]:     0048730b(j), 004876b0(*)
//                              rmm_shal.cpp:169 (1)
//         00487320     DEC        this
//                              rmm_shal.cpp:170 (9)
//         00487321     DEC        EAX
//         00487322     MOV        dword ptr [ESP + ty2],this
//         00487326     MOV        dword ptr [ESP + y],EAX
//                              rmm_shal.cpp:171 (2)
//         0048732a     JMP        LAB_00487358
//                               switchD_0048730b::caseD_9                                    XREF[2]:     0048730b(j), 004876a8(*)
//                              rmm_shal.cpp:173 (1)
//         0048732c     DEC        this
//                              rmm_shal.cpp:174 (9)
//         0048732d     INC        EAX
//         0048732e     MOV        dword ptr [ESP + ty2],this
//         00487332     MOV        dword ptr [ESP + y],EAX
//                              rmm_shal.cpp:175 (2)
//         00487336     JMP        LAB_00487358
//                               switchD_0048730b::caseD_a                                    XREF[2]:     0048730b(j), 004876ac(*)
//                              rmm_shal.cpp:177 (5)
//         00487338     INC        this
//         00487339     MOV        dword ptr [ESP + ty2],this
//                               switchD_0048730b::caseD_5                                    XREF[2]:     0048730b(j), 00487698(*)
//                              rmm_shal.cpp:178 (5)
//         0048733d     DEC        EAX
//         0048733e     MOV        dword ptr [ESP + y],EAX
//                              rmm_shal.cpp:179 (2)
//         00487342     JMP        LAB_00487358
//                               switchD_0048730b::caseD_8                                    XREF[2]:     0048730b(j), 004876a4(*)
//                              rmm_shal.cpp:181 (5)
//         00487344     INC        this
//         00487345     MOV        dword ptr [ESP + ty2],this
//                               switchD_0048730b::caseD_4                                    XREF[2]:     0048730b(j), 00487694(*)
//                              rmm_shal.cpp:182 (5)
//         00487349     INC        EAX
//         0048734a     MOV        dword ptr [ESP + y],EAX
//                              rmm_shal.cpp:183 (2)
//         0048734e     JMP        LAB_00487358
//                               switchD_0048730b::default                                    XREF[1]:     00487309(j)
//                              rmm_shal.cpp:186 (8)
//         00487350     MOV        dword ptr [ESP + tx2],0x1
//                               LAB_00487358                                                 XREF[6]:     00487317(j), 0048731e(j),
//                                                                                                         0048732a(j), 00487336(j),
//                                                                                                         00487342(j), 0048734e(j)
//                              rmm_shal.cpp:190 (18)
//         00487358     CMP        EAX,EBP
//         0048735a     JL         LAB_0048736a
//         0048735c     CMP        EAX,dword ptr [ESI + 0x14]
//         0048735f     JGE        LAB_0048736a
//         00487361     CMP        this,EBP
//         00487363     JL         LAB_0048736a
//         00487365     CMP        this,dword ptr [ESI + 0x18]
//         00487368     JL         LAB_00487372
//                               LAB_0048736a                                                 XREF[3]:     0048735a(j), 0048735f(j),
//                                                                                                         00487363(j)
//                              rmm_shal.cpp:191 (8)
//         0048736a     MOV        dword ptr [ESP + tx2],0x1
//                               LAB_00487372                                                 XREF[1]:     00487368(j)
//                              rmm_shal.cpp:193 (10)
//         00487372     CMP        dword ptr [ESP + tx2],EBP
//         00487376     JNZ        LAB_0048761e
//                              rmm_shal.cpp:196 (36)
//         0048737c     MOV        EDX,dword ptr [ESI + 0x10]
//         0048737f     LEA        EDI,[EAX + EAX*0x2]
//         00487382     MOV        EDX,dword ptr [EDX + this->_padding_*0x4]
//         00487385     LEA        EDI,[EDX + EDI*0x8]
//         00487388     MOV        DL,byte ptr [EDI + 0x5]
//         0048738b     AND        DL,0x1f
//         0048738e     CMP        DL,0x1
//         00487391     JZ         LAB_00487482
//         00487397     CMP        DL,0x16
//         0048739a     JZ         LAB_00487482
//                              rmm_shal.cpp:223 (20)
//         004873a0     CMP        EAX,EBP
//         004873a2     JLE        LAB_004873cd
//         004873a4     MOV        DL,byte ptr [EDI + -0x13]
//         004873a7     AND        DL,0x1f
//         004873aa     CMP        DL,0x1
//         004873ad     JZ         LAB_004873b4
//         004873af     CMP        DL,0x16
//         004873b2     JNZ        LAB_004873cd
//                               LAB_004873b4                                                 XREF[1]:     004873ad(j)
//                              rmm_shal.cpp:224 (25)
//         004873b4     PUSH       EBP
//         004873b5     PUSH       EBP
//         004873b6     DEC        EAX
//         004873b7     PUSH       this
//         004873b8     PUSH       EAX
//         004873b9     LEA        EAX=>stack.y,[ESP + 0x48]
//         004873bd     PUSH       EAX
//         004873be     MOV        this,ESI
//         004873c0     CALL       RGE_Random_Map_Module::push_stack                void push_stack(RGE_Random_Map_Module * this,
//         004873c5     MOV        this,dword ptr [ESP + ty2]
//         004873c9     MOV        EAX,dword ptr [ESP + y]
//                               LAB_004873cd                                                 XREF[2]:     004873a2(j), 004873b2(j)
//                              rmm_shal.cpp:226 (34)
//         004873cd     MOV        EDX,dword ptr [ESI + 0x14]
//         004873d0     DEC        EDX
//         004873d1     CMP        EAX,EDX
//         004873d3     JGE        LAB_00487408
//         004873d5     MOV        EDX,dword ptr [ESI + 0x10]
//         004873d8     LEA        EDI,[EAX + EAX*0x2]
//         004873db     MOV        EDX,dword ptr [EDX + this->_padding_*0x4]
//         004873de     MOV        DL,byte ptr [EDX + EDI*0x8 + 0x1d]
//         004873e2     AND        DL,0x1f
//         004873e5     CMP        DL,0x1
//         004873e8     JZ         LAB_004873ef
//         004873ea     CMP        DL,0x16
//         004873ed     JNZ        LAB_00487408
//                               LAB_004873ef                                                 XREF[1]:     004873e8(j)
//                              rmm_shal.cpp:227 (25)
//         004873ef     PUSH       EBP
//         004873f0     PUSH       EBP
//         004873f1     INC        EAX
//         004873f2     PUSH       this
//         004873f3     PUSH       EAX
//         004873f4     LEA        EAX=>stack.y,[ESP + 0x48]
//         004873f8     PUSH       EAX
//         004873f9     MOV        this,ESI
//         004873fb     CALL       RGE_Random_Map_Module::push_stack                void push_stack(RGE_Random_Map_Module * this,
//         00487400     MOV        this,dword ptr [ESP + ty2]
//         00487404     MOV        EAX,dword ptr [ESP + y]
//                               LAB_00487408                                                 XREF[2]:     004873d3(j), 004873ed(j)
//                              rmm_shal.cpp:229 (31)
//         00487408     CMP        this,EBP
//         0048740a     JLE        LAB_00487440
//         0048740c     MOV        EDX,dword ptr [ESI + 0x10]
//         0048740f     LEA        EDI,[EAX + EAX*0x2]
//         00487412     MOV        EDX,dword ptr [EDX + this->_padding_*0x4 + -0x4]
//         00487416     MOV        DL,byte ptr [EDX + EDI*0x8 + 0x5]
//         0048741a     AND        DL,0x1f
//         0048741d     CMP        DL,0x1
//         00487420     JZ         LAB_00487427
//         00487422     CMP        DL,0x16
//         00487425     JNZ        LAB_00487440
//                               LAB_00487427                                                 XREF[1]:     00487420(j)
//                              rmm_shal.cpp:230 (25)
//         00487427     PUSH       EBP
//         00487428     DEC        this
//         00487429     PUSH       EBP
//         0048742a     PUSH       this
//         0048742b     PUSH       EAX
//         0048742c     LEA        EAX=>stack.y,[ESP + 0x48]
//         00487430     PUSH       EAX
//         00487431     MOV        this,ESI
//         00487433     CALL       RGE_Random_Map_Module::push_stack                void push_stack(RGE_Random_Map_Module * this,
//         00487438     MOV        this,dword ptr [ESP + ty2]
//         0048743c     MOV        EAX,dword ptr [ESP + y]
//                               LAB_00487440                                                 XREF[2]:     0048740a(j), 00487425(j)
//                              rmm_shal.cpp:232 (45)
//         00487440     MOV        EDX,dword ptr [ESI + 0x18]
//         00487443     DEC        EDX
//         00487444     CMP        this,EDX
//         00487446     JGE        LAB_004875f7
//         0048744c     LEA        EDX,[ECX + this+0x1]
//         0048744f     MOV        this,dword ptr [ESI + 0x10]
//         00487452     LEA        EDI,[EAX + EAX*0x2]
//         00487455     MOV        this,dword ptr [this->_padding_ + EDX*0x4]
//         00487458     MOV        this,byte ptr [ECX + EDI*0x8 + this+0x5]
//         0048745c     AND        this,0x1f
//         0048745f     CMP        this,0x1
//         00487462     JZ         LAB_0048746d
//         00487464     CMP        this,0x16
//         00487467     JNZ        LAB_004875f7
//                               LAB_0048746d                                                 XREF[1]:     00487462(j)
//                              rmm_shal.cpp:233 (21)
//         0048746d     PUSH       EBP
//         0048746e     PUSH       EBP
//         0048746f     PUSH       EDX
//         00487470     LEA        EDX=>stack.y,[ESP + 0x44]
//         00487474     PUSH       EAX
//         00487475     PUSH       EDX
//         00487476     MOV        this,ESI
//         00487478     CALL       RGE_Random_Map_Module::push_stack                void push_stack(RGE_Random_Map_Module * this,
//         0048747d     JMP        LAB_004875f7
//                               LAB_00487482                                                 XREF[2]:     00487391(j), 0048739a(j)
//                              rmm_shal.cpp:198 (52)
//         00487482     PUSH       0xc6
//         00487487     PUSH       s_C:\msdev\work\age1_x1\rmm_shal.c               = "C:\\msdev\\work\\age1_x1\\rmm_shal.cpp"
//         0048748c     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
//         00487491     MOV        this,EAX
//         00487493     MOV        EAX,0x80010003
//         00487498     SHL        this,0x1
//         0048749a     IMUL       this
//         0048749c     ADD        EDX,this
//         0048749e     MOV        EBX,dword ptr [ESP + y]
//         004874a2     SAR        EDX,0xe
//         004874a5     MOV        EAX,EDX
//         004874a7     ADD        ESP,0x8
//         004874aa     SHR        EAX,0x1f
//         004874ad     ADD        EDX,EAX
//         004874af     SUB        EBX,EDX
//         004874b1     DEC        EBX
//         004874b2     MOV        dword ptr [ESP + end_y],EBX
//                              rmm_shal.cpp:199 (2)
//         004874b6     JNS        LAB_004874be
//                              rmm_shal.cpp:200 (6)
//         004874b8     MOV        dword ptr [ESP + end_y],EBP
//         004874bc     MOV        EBX,EBP
//                               LAB_004874be                                                 XREF[1]:     004874b6(j)
//                              rmm_shal.cpp:202 (48)
//         004874be     PUSH       0xca
//         004874c3     PUSH       s_C:\msdev\work\age1_x1\rmm_shal.c               = "C:\\msdev\\work\\age1_x1\\rmm_shal.cpp"
//         004874c8     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
//         004874cd     MOV        this,EAX
//         004874cf     MOV        EAX,0x80010003
//         004874d4     SHL        this,0x1
//         004874d6     IMUL       this
//         004874d8     ADD        EDX,this
//         004874da     MOV        EDI,dword ptr [ESP + ty2]
//         004874de     SAR        EDX,0xe
//         004874e1     MOV        this,EDX
//         004874e3     ADD        ESP,0x8
//         004874e6     SHR        this,0x1f
//         004874e9     ADD        EDX,this
//         004874eb     SUB        EDI,EDX
//         004874ed     DEC        EDI
//                              rmm_shal.cpp:203 (2)
//         004874ee     JNS        LAB_004874f2
//                              rmm_shal.cpp:204 (2)
//         004874f0     XOR        EDI,EDI
//                               LAB_004874f2                                                 XREF[1]:     004874ee(j)
//                              rmm_shal.cpp:206 (45)
//         004874f2     PUSH       0xce
//         004874f7     PUSH       s_C:\msdev\work\age1_x1\rmm_shal.c               = "C:\\msdev\\work\\age1_x1\\rmm_shal.cpp"
//         004874fc     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
//         00487501     MOV        this,EAX
//         00487503     MOV        EAX,0x80010003
//         00487508     SHL        this,0x1
//         0048750a     IMUL       this
//         0048750c     ADD        EDX,this
//         0048750e     MOV        this,dword ptr [ESP + y]
//         00487512     SAR        EDX,0xe
//         00487515     MOV        EAX,EDX
//         00487517     ADD        ESP,0x8
//         0048751a     SHR        EAX,0x1f
//         0048751d     ADD        EDX,EAX
//                              rmm_shal.cpp:207 (15)
//         0048751f     MOV        EAX,dword ptr [ESI + 0x14]
//         00487522     LEA        EDX,[EDX + this->_padding_*0x1 + 0x1]
//         00487526     CMP        EDX,EAX
//         00487528     MOV        dword ptr [ESP + in_zone],EDX
//         0048752c     JL         LAB_00487533
//                              rmm_shal.cpp:208 (5)
//         0048752e     DEC        EAX
//         0048752f     MOV        dword ptr [ESP + in_zone],EAX
//                               LAB_00487533                                                 XREF[1]:     0048752c(j)
//                              rmm_shal.cpp:210 (44)
//         00487533     PUSH       0xd2
//         00487538     PUSH       s_C:\msdev\work\age1_x1\rmm_shal.c               = "C:\\msdev\\work\\age1_x1\\rmm_shal.cpp"
//         0048753d     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
//         00487542     LEA        this,[EAX + EAX*0x2]
//         00487545     MOV        EAX,0x80010003
//         0048754a     IMUL       this
//         0048754c     ADD        EDX,this
//         0048754e     MOV        this,dword ptr [ESP + ty2]
//         00487552     SAR        EDX,0xe
//         00487555     MOV        EAX,EDX
//         00487557     ADD        ESP,0x8
//         0048755a     SHR        EAX,0x1f
//         0048755d     ADD        EDX,EAX
//                              rmm_shal.cpp:211 (15)
//         0048755f     MOV        EAX,dword ptr [ESI + 0x18]
//         00487562     LEA        EDX,[EDX + this->_padding_*0x1 + 0x1]
//         00487566     CMP        EDX,EAX
//         00487568     MOV        dword ptr [ESP + end_x],EDX
//         0048756c     JL         LAB_00487573
//                              rmm_shal.cpp:212 (5)
//         0048756e     DEC        EAX
//         0048756f     MOV        dword ptr [ESP + end_x],EAX
//                               LAB_00487573                                                 XREF[1]:     0048756c(j)
//                              rmm_shal.cpp:214 (27)
//         00487573     MOV        EAX,dword ptr [ESP + end_x]
//         00487577     MOV        this,EDI
//         00487579     CMP        EDI,EAX
//         0048757b     MOV        dword ptr [ESP + done],this
//         0048757f     JG         LAB_004875f7
//         00487581     LEA        EBP,[EDI*0x4 + 0x0]
//         00487588     JMP        LAB_0048758e
//                               LAB_0048758a                                                 XREF[1]:     004875f3(j)
//         0048758a     MOV        EBX,dword ptr [ESP + end_y]
//                               LAB_0048758e                                                 XREF[1]:     00487588(j)
//                              rmm_shal.cpp:215 (18)
//         0048758e     MOV        EDI,dword ptr [ESP + end_y]
//         00487592     MOV        EAX,dword ptr [ESP + in_zone]
//         00487596     CMP        EDI,EAX
//         00487598     JG         LAB_004875e5
//         0048759a     LEA        EDI,[EDI + EDI*0x2]
//         0048759d     SHL        EDI,0x3
//                               LAB_004875a0                                                 XREF[1]:     004875e3(j)
//                              rmm_shal.cpp:216 (35)
//         004875a0     MOV        EDX,dword ptr [ESI + 0x10]
//         004875a3     LEA        EAX,[EDX + EBP*0x1]
//         004875a6     MOV        EDX,dword ptr [EDX + EBP*0x1]
//         004875a9     MOV        DL,byte ptr [EDX + EDI*0x1 + 0x5]
//         004875ad     AND        DL,0x1f
//         004875b0     CMP        DL,0x1
//         004875b3     JZ         LAB_004875c3
//         004875b5     MOV        EAX,dword ptr [EAX]
//         004875b7     MOV        DL,byte ptr [EAX + EDI*0x1 + 0x5]
//         004875bb     AND        DL,0x1f
//         004875be     CMP        DL,0x16
//         004875c1     JNZ        LAB_004875d9
//                               LAB_004875c3                                                 XREF[1]:     004875b3(j)
//                              rmm_shal.cpp:217 (34)
//         004875c3     PUSH       0x0
//         004875c5     PUSH       0x0
//         004875c7     PUSH       this
//         004875c8     LEA        EAX=>stack.y,[ESP + 0x44]
//         004875cc     PUSH       EBX
//         004875cd     PUSH       EAX
//         004875ce     MOV        this,ESI
//         004875d0     CALL       RGE_Random_Map_Module::push_stack                void push_stack(RGE_Random_Map_Module * this,
//         004875d5     MOV        this,dword ptr [ESP + done]
//                               LAB_004875d9                                                 XREF[1]:     004875c1(j)
//         004875d9     MOV        EAX,dword ptr [ESP + in_zone]
//         004875dd     INC        EBX
//         004875de     ADD        EDI,0x18
//         004875e1     CMP        EBX,EAX
//         004875e3     JLE        LAB_004875a0
//                               LAB_004875e5                                                 XREF[1]:     00487598(j)
//                              rmm_shal.cpp:214 (18)
//         004875e5     MOV        EAX,dword ptr [ESP + end_x]
//         004875e9     INC        this
//         004875ea     ADD        EBP,0x4
//         004875ed     CMP        this,EAX
//         004875ef     MOV        dword ptr [ESP + done],this
//         004875f3     JLE        LAB_0048758a
//         004875f5     XOR        EBP,EBP
//                               LAB_004875f7                                                 XREF[4]:     00487446(j), 00487467(j),
//                                                                                                         0048747d(j), 0048757f(j)
//                              rmm_shal.cpp:236 (18)
//         004875f7     MOV        this,dword ptr [ESI + 0x24]
//         004875fa     MOV        EDX,dword ptr [ESP + ty]
//         004875fe     MOV        EAX,dword ptr [this->_padding_ + EDX*0x4]
//         00487601     MOV        this,dword ptr [ESP + tx1]
//         00487605     MOV        byte ptr [EAX + this->_padding_*0x1],0xff
//                              rmm_shal.cpp:237 (4)
//         00487609     MOV        EAX,dword ptr [ESP + y]
//                              rmm_shal.cpp:238 (17)
//         0048760d     MOV        this,dword ptr [ESP + ty2]
//         00487611     MOV        dword ptr [ESP + tx1],EAX
//         00487615     MOV        dword ptr [ESP + ty],this
//         00487619     JMP        LAB_004872f6
//                               LAB_0048761e                                                 XREF[1]:     00487376(j)
//                              rmm_shal.cpp:241 (31)
//         0048761e     LEA        EDX=>stack,[ESP + 0x34]
//         00487622     LEA        EAX=>ty2,[ESP + 0x14]
//         00487626     PUSH       EDX
//         00487627     LEA        this=>y,[ESP + 0x14]
//         0048762b     PUSH       EAX
//         0048762c     LEA        EDX=>stack.y,[ESP + 0x40]
//         00487630     PUSH       this
//         00487631     PUSH       EDX
//         00487632     MOV        this,ESI
//         00487634     CALL       RGE_Random_Map_Module::pop_stack                 Map_Stack * pop_stack(RGE_Random_Map_Module *
//         00487639     TEST       EAX,EAX
//         0048763b     JZ         LAB_0048767b
//                               LAB_0048763d                                                 XREF[1]:     00487679(j)
//                              rmm_shal.cpp:242 (62)
//         0048763d     MOV        EAX,dword ptr [ESP + y]
//         00487641     MOV        this,dword ptr [ESI + 0x10]
//         00487644     LEA        EDX,[EAX + EAX*0x2]
//         00487647     MOV        EAX,dword ptr [ESP + ty2]
//         0048764b     MOV        this,dword ptr [this->_padding_ + EAX*0x4]
//         0048764e     LEA        EAX,[ECX + EDX*0x8 + this+0x5]
//         00487652     LEA        this=>ty2,[ESP + 0x14]
//         00487656     MOV        DL,byte ptr [EAX]
//         00487658     AND        DL,0xe4
//         0048765b     OR         DL,0x4
//         0048765e     MOV        byte ptr [EAX],DL
//         00487660     LEA        EAX=>stack,[ESP + 0x34]
//         00487664     PUSH       EAX
//         00487665     LEA        EDX=>y,[ESP + 0x14]
//         00487669     PUSH       this
//         0048766a     LEA        EAX=>stack.y,[ESP + 0x40]
//         0048766e     PUSH       EDX
//         0048766f     PUSH       EAX
//         00487670     MOV        this,ESI
//         00487672     CALL       RGE_Random_Map_Module::pop_stack                 Map_Stack * pop_stack(RGE_Random_Map_Module *
//         00487677     TEST       EAX,EAX
//         00487679     JNZ        LAB_0048763d
//                               LAB_0048767b                                                 XREF[1]:     0048763b(j)
//                              rmm_shal.cpp:244 (12)
//         0048767b     LEA        this=>stack.y,[ESP + 0x38]
//         0048767f     PUSH       this
//         00487680     MOV        this,ESI
//         00487682     CALL       RGE_Random_Map_Module::deinit_stack              void deinit_stack(RGE_Random_Map_Module * thi
//                               LAB_00487687                                                 XREF[6]:     004872ac(j), 004872b8(j),
//                                                                                                         004872ca(j), 004872d3(j),
//                                                                                                         004872db(j), 004872e4(j)
//                              rmm_shal.cpp:245 (45)
//         00487687     POP        EDI
//         00487688     POP        ESI
//         00487689     POP        EBP
//         0048768a     POP        EBX
//         0048768b     ADD        ESP,0xe0
//         00487691     RET        0x8
//                              Symbol Ref: No symbol: NONAME
//                               switchD_0048730b::switchdataD_00487694                       XREF[1]:     make_tribe_connections:0048730b(*)
//         00487694     addr       switchD_0048730b::caseD_4
//         00487698     addr       switchD_0048730b::caseD_5
//         0048769c     addr       switchD_0048730b::caseD_6
//         004876a0     addr       switchD_0048730b::caseD_7
//         004876a4     addr       switchD_0048730b::caseD_8
//         004876a8     addr       switchD_0048730b::caseD_9
//         004876ac     addr       switchD_0048730b::caseD_a
//         004876b0     addr       switchD_0048730b::caseD_b
//         004876b4     ??         90h
//         004876b5     ??         90h
//         004876b6     ??         90h
//         004876b7     ??         90h
//         004876b8     ??         90h
//         004876b9     ??         90h
//         004876ba     ??         90h
//         004876bb     ??         90h
//         004876bc     ??         90h
//         004876bd     ??         90h
//         004876be     ??         90h
//         004876bf     ??         90h
    return;
}

