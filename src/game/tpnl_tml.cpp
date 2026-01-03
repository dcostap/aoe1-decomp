#include "../common.h"
#include "tpnl_tml.h"

Time_Line_Panel::Time_Line_Panel() {
    /* TODO: Stub */
//                              undefined __thiscall Time_Line_Panel(Time_Line_Panel * this)
//              undefined         <UNASSIGNED>   <RETURN>
//              Time_Line_Pane    ECX:4 (auto)   this
//                               ??0Time_Line_Panel@@QAE@XZ                                   XREF[1]:     create_timeline:0051e8f1(c)
//                               Time_Line_Panel::Time_Line_Panel
//                              tpnl_tml.cpp:98 (225)
//         0051e650     PUSH       ESI
//         0051e651     MOV        ESI,this
//         0051e653     CALL       TEasy_Panel::TEasy_Panel                         undefined TEasy_Panel(TEasy_Panel * this)
//         0051e658     XOR        EAX,EAX
//         0051e65a     MOV        dword ptr [ESI + 0x490],0x2
//         0051e664     MOV        dword ptr [ESI + 0x478],EAX
//         0051e66a     MOV        dword ptr [ESI + 0x47c],EAX
//         0051e670     MOV        dword ptr [ESI + 0x480],EAX
//         0051e676     MOV        dword ptr [ESI + 0x484],EAX
//         0051e67c     MOV        dword ptr [ESI + 0x488],EAX
//         0051e682     MOV        dword ptr [ESI + 0x48c],EAX
//         0051e688     MOV        dword ptr [ESI + 0x494],0xffffff
//         0051e692     MOV        dword ptr [ESI + 0x498],EAX
//         0051e698     MOV        dword ptr [ESI + 0x49c],0xffff
//         0051e6a2     MOV        dword ptr [ESI + 0x4a0],EAX
//         0051e6a8     MOV        dword ptr [ESI + 0x4a4],EAX
//         0051e6ae     MOV        dword ptr [ESI + 0x4a8],EAX
//         0051e6b4     MOV        dword ptr [ESI + 0x4ac],EAX
//         0051e6ba     MOV        word ptr [ESI + 0x4b0],AX
//         0051e6c1     MOV        word ptr [ESI + 0x4b2],AX
//         0051e6c8     MOV        dword ptr [ESI + 0x4b4],EAX
//         0051e6ce     MOV        byte ptr [ESI + 0x4b8],0xff
//         0051e6d5     MOV        dword ptr [ESI + 0x4bc],EAX
//         0051e6db     MOV        byte ptr [ESI + 0x4c0],AL
//         0051e6e1     MOV        dword ptr [ESI + 0x4c8],EAX
//         0051e6e7     MOV        byte ptr [ESI + 0x4cc],AL
//         0051e6ed     MOV        byte ptr [ESI + 0x4cd],AL
//         0051e6f3     MOV        byte ptr [ESI + 0x4ce],AL
//         0051e6f9     MOV        byte ptr [ESI + 0x4cf],AL
//         0051e6ff     MOV        byte ptr [ESI + 0x4d0],AL
//         0051e705     MOV        byte ptr [ESI + 0x4d1],AL
//         0051e70b     MOV        dword ptr [ESI + 0x4d4],EAX
//         0051e711     MOV        word ptr [ESI + 0x4d8],AX
//         0051e718     MOV        word ptr [ESI + 0x4da],AX
//         0051e71f     MOV        dword ptr [ESI + 0x508],EAX
//         0051e725     MOV        dword ptr [ESI + 0x518],EAX
//         0051e72b     MOV        dword ptr [ESI],Time_Line_Panel::`vftable'       = 0051e770
//                              tpnl_tml.cpp:102 (6)
//         0051e731     MOV        dword ptr [ESI + 0x80],EAX
//                              tpnl_tml.cpp:103 (7)
//         0051e737     MOV        byte ptr [ESI + 0x51c],0x1
//                              tpnl_tml.cpp:104 (6)
//         0051e73e     MOV        byte ptr [ESI + 0x50c],AL
//                              tpnl_tml.cpp:105 (10)
//         0051e744     MOV        dword ptr [ESI + 0x500],0xc
//                              tpnl_tml.cpp:108 (18)
//         0051e74e     MOV        dword ptr [ESI + 0x520],EAX
//         0051e754     MOV        dword ptr [ESI + 0x524],EAX
//         0051e75a     MOV        dword ptr [ESI + 0x528],EAX
//                              tpnl_tml.cpp:109 (4)
//         0051e760     MOV        EAX,ESI
//         0051e762     POP        ESI
//         0051e763     RET
//         0051e764     ??         90h
//         0051e765     NOP
//         0051e766     NOP
//         0051e767     NOP
//         0051e768     NOP
//         0051e769     NOP
//         0051e76a     NOP
//         0051e76b     NOP
//         0051e76c     NOP
//         0051e76d     NOP
//         0051e76e     NOP
//         0051e76f     NOP
}

Time_Line_Panel::~Time_Line_Panel() {
    /* TODO: Stub */
//                              void __thiscall ~Time_Line_Panel(Time_Line_Panel * this)
//              void              <VOID>         <RETURN>
//              Time_Line_Pane    ECX:4 (auto)   this
//              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     0051e7bf(W), 0051e83f(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     0051e84c(R)
//              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     0051e7ab(W)
//                               ??1Time_Line_Panel@@UAE@XZ                                   XREF[1]:     `scalar_deleting_destructor':0051e
//                               Time_Line_Panel::~Time_Line_Panel
//                              tpnl_tml.cpp:116 (37)
//         0051e790     PUSH       -0x1
//         0051e792     PUSH       FUN_00561468
//         0051e797     MOV        EAX,FS:[0x0]
//         0051e79d     PUSH       EAX
//         0051e79e     MOV        dword ptr FS:[0x0],ESP
//         0051e7a5     PUSH       this
//         0051e7a6     PUSH       EBX
//         0051e7a7     PUSH       ESI
//         0051e7a8     MOV        ESI,this
//         0051e7aa     PUSH       EDI
//         0051e7ab     MOV        dword ptr [ESP + local_10],ESI
//         0051e7af     MOV        dword ptr [ESI],Time_Line_Panel::`vftable'       = 0051e770
//                              tpnl_tml.cpp:120 (16)
//         0051e7b5     MOV        EAX,dword ptr [ESI + 0x518]
//         0051e7bb     XOR        EBX,EBX
//         0051e7bd     CMP        EAX,EBX
//         0051e7bf     MOV        dword ptr [ESP + local_4],EBX
//         0051e7c3     JZ         LAB_0051e7e4
//                               LAB_0051e7c5                                                 XREF[1]:     0051e7e2(j)
//                              tpnl_tml.cpp:122 (6)
//         0051e7c5     MOV        this,dword ptr [EAX + 0xac]
//                              tpnl_tml.cpp:123 (25)
//         0051e7cb     PUSH       EAX
//         0051e7cc     MOV        dword ptr [ESI + 0x518],this
//         0051e7d2     CALL       free                                             undefined free()
//         0051e7d7     MOV        EAX,dword ptr [ESI + 0x518]
//         0051e7dd     ADD        ESP,0x4
//         0051e7e0     CMP        EAX,EBX
//         0051e7e2     JNZ        LAB_0051e7c5
//                               LAB_0051e7e4                                                 XREF[1]:     0051e7c3(j)
//                              tpnl_tml.cpp:126 (10)
//         0051e7e4     MOV        EDI,dword ptr [ESI + 0x4ac]
//         0051e7ea     CMP        EDI,EBX
//         0051e7ec     JZ         LAB_0051e804
//                              tpnl_tml.cpp:128 (16)
//         0051e7ee     MOV        this,EDI
//         0051e7f0     CALL       TShape::~TShape                                  void ~TShape(TShape * this)
//         0051e7f5     PUSH       EDI
//         0051e7f6     CALL       operator_delete                                  void operator_delete(void * param_1)
//         0051e7fb     ADD        ESP,0x4
//                              tpnl_tml.cpp:129 (6)
//         0051e7fe     MOV        dword ptr [ESI + 0x4ac],EBX
//                               LAB_0051e804                                                 XREF[1]:     0051e7ec(j)
//                              tpnl_tml.cpp:132 (10)
//         0051e804     MOV        EDI,dword ptr [ESI + 0x4d4]
//         0051e80a     CMP        EDI,EBX
//         0051e80c     JZ         LAB_0051e824
//                              tpnl_tml.cpp:134 (16)
//         0051e80e     MOV        this,EDI
//         0051e810     CALL       TShape::~TShape                                  void ~TShape(TShape * this)
//         0051e815     PUSH       EDI
//         0051e816     CALL       operator_delete                                  void operator_delete(void * param_1)
//         0051e81b     ADD        ESP,0x4
//                              tpnl_tml.cpp:135 (6)
//         0051e81e     MOV        dword ptr [ESI + 0x4d4],EBX
//                               LAB_0051e824                                                 XREF[1]:     0051e80c(j)
//                              tpnl_tml.cpp:138 (11)
//         0051e824     LEA        EDI,[ESI + 0x520]
//         0051e82a     MOV        EBX,0x3
//                               LAB_0051e82f                                                 XREF[1]:     0051e83b(j)
//                              tpnl_tml.cpp:139 (16)
//         0051e82f     PUSH       EDI
//         0051e830     MOV        this,ESI
//         0051e832     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
//         0051e837     ADD        EDI,0x4
//         0051e83a     DEC        EBX
//         0051e83b     JNZ        LAB_0051e82f
//         0051e83d     MOV        this,ESI
//                              tpnl_tml.cpp:141 (31)
//         0051e83f     MOV        dword ptr [ESP + local_4],0xffffffff
//         0051e847     CALL       TEasy_Panel::~TEasy_Panel                        void ~TEasy_Panel(TEasy_Panel * this)
//         0051e84c     MOV        this,dword ptr [ESP + local_c]
//         0051e850     POP        EDI
//         0051e851     POP        ESI
//         0051e852     MOV        dword ptr FS:[0x0],this
//         0051e859     POP        EBX
//         0051e85a     ADD        ESP,0x10
//         0051e85d     RET
//         0051e85e     ??         90h
//         0051e85f     NOP
}

long Time_Line_Panel::create_timeline(TPanel* param_1, Time_Line_Panel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9, long param_10) {
    /* TODO: Stub */
//                              long __thiscall create_timeline(Time_Line_Panel * this, TPanel * par
//              long              EAX:4          <RETURN>
//              Time_Line_Pane    ECX:4 (auto)   this
//              TPanel *          Stack[0x4]:4   param_1                   XREF[3]:     0051e879(R), 0051e8bf(W), 0051e970(R)
//              Time_Line_Pane    Stack[0x8]:4   param_2                   XREF[2]:     0051e8fa(R), 0051e986(R)
//              long              Stack[0xc]:4   param_3                   XREF[3]:     0051e889(R), 0051e8ac(W), 0051e975(R)
//              long              Stack[0x10]:4  param_4                   XREF[1]:     0051e89e(R)
//              long              Stack[0x14]:4  param_5                   XREF[1]:     0051e8b5(R)
//              long              Stack[0x18]:4  param_6                   XREF[1]:     0051e8c8(R)
//              long              Stack[0x1c]:4  param_7                   XREF[1]:     0051e91e(R)
//              long              Stack[0x20]:4  param_8                   XREF[1]:     0051e938(R)
//              long              Stack[0x24]:4  param_9                   XREF[2]:     0051e88e(R), 0051e8df(W)
//              long              Stack[0x28]:4  param_10                  XREF[1]:     0051e8a3(R)
//              TPanel *          Stack[0x0]:4   parent
//              Time_Line_Pane    Stack[-0x4]:4  this                      XREF[2]:     0051e8e5(W), 0051e8fe(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     0051e9c4(R)
//              undefined4        Stack[-0x10]:4 local_10                  XREF[3]:     0051e87d(W), 0051e996(R), 0051e9b4(R)
//                               ?create_timeline@Time_Line_Panel@@QAEJPAVTPanel@@PAPAV1@JJJ  XREF[1]:     TribeAchievementsScreen:0048d97b(c
//                               Time_Line_Panel::create_timeline
//                              tpnl_tml.cpp:149 (25)
//         0051e860     PUSH       -0x1
//         0051e862     PUSH       FUN_0056148b
//         0051e867     MOV        EAX,FS:[0x0]
//         0051e86d     PUSH       EAX
//         0051e86e     MOV        dword ptr FS:[0x0],ESP
//         0051e875     PUSH       this
//         0051e876     PUSH       EBX
//         0051e877     PUSH       EBP
//         0051e878     PUSH       ESI
//                              tpnl_tml.cpp:158 (87)
//         0051e879     MOV        ESI,dword ptr [ESP + param_1]
//         0051e87d     MOV        dword ptr [ESP + local_10],this
//         0051e881     PUSH       EDI
//         0051e882     MOV        this,ESI
//         0051e884     CALL       TPanel::width                                    long width(TPanel * this)
//         0051e889     IMUL       EAX,dword ptr [ESP + param_3]
//         0051e88e     MOV        EDI,dword ptr [ESP + param_9]
//         0051e892     MOV        this,ESI
//         0051e894     CDQ
//         0051e895     IDIV       EDI
//         0051e897     MOV        EBP,EAX
//         0051e899     CALL       TPanel::height                                   long height(TPanel * this)
//         0051e89e     IMUL       EAX,dword ptr [ESP + param_4]
//         0051e8a3     MOV        EBX,dword ptr [ESP + param_10]
//         0051e8a7     MOV        this,ESI
//         0051e8a9     CDQ
//         0051e8aa     IDIV       EBX
//         0051e8ac     MOV        dword ptr [ESP + param_3],EAX
//         0051e8b0     CALL       TPanel::width                                    long width(TPanel * this)
//         0051e8b5     IMUL       EAX,dword ptr [ESP + param_5]
//         0051e8ba     CDQ
//         0051e8bb     IDIV       EDI
//         0051e8bd     MOV        this,ESI
//         0051e8bf     MOV        dword ptr [ESP + param_1],EAX
//         0051e8c3     CALL       TPanel::height                                   long height(TPanel * this)
//         0051e8c8     IMUL       EAX,dword ptr [ESP + param_6]
//         0051e8cd     CDQ
//         0051e8ce     IDIV       EBX
//                              tpnl_tml.cpp:160 (54)
//         0051e8d0     PUSH       0x52c
//         0051e8d5     MOV        EBX,EAX
//         0051e8d7     CALL       operator_new                                     void * operator_new(uint param_1)
//         0051e8dc     ADD        ESP,0x4
//         0051e8df     MOV        dword ptr [ESP + param_9],EAX
//         0051e8e3     TEST       EAX,EAX
//         0051e8e5     MOV        dword ptr [ESP + this],0x0
//         0051e8ed     JZ         LAB_0051e8f8
//         0051e8ef     MOV        this,EAX
//         0051e8f1     CALL       Time_Line_Panel::Time_Line_Panel                 undefined Time_Line_Panel(Time_Line_Panel * t
//         0051e8f6     JMP        LAB_0051e8fa
//                               LAB_0051e8f8                                                 XREF[1]:     0051e8ed(j)
//         0051e8f8     XOR        EAX,EAX
//                               LAB_0051e8fa                                                 XREF[1]:     0051e8f6(j)
//         0051e8fa     MOV        this,dword ptr [ESP + param_2]
//         0051e8fe     MOV        dword ptr [ESP + this],0xffffffff
//                              tpnl_tml.cpp:161 (24)
//         0051e906     TEST       EAX,EAX
//         0051e908     MOV        dword ptr [this->_padding_],EAX
//         0051e90a     JZ         LAB_0051e9b4
//         0051e910     MOV        this,dword ptr [EAX + 0xd8]
//         0051e916     TEST       this,this
//         0051e918     JNZ        LAB_0051e9b4
//                              tpnl_tml.cpp:168 (8)
//         0051e91e     MOV        EAX,dword ptr [ESP + param_7]
//         0051e922     TEST       EAX,EAX
//         0051e924     JL         LAB_0051e929
//                              tpnl_tml.cpp:169 (1)
//         0051e926     PUSH       EAX
//                              tpnl_tml.cpp:170 (2)
//         0051e927     JMP        LAB_0051e92b
//                               LAB_0051e929                                                 XREF[1]:     0051e924(j)
//                              tpnl_tml.cpp:171 (15)
//         0051e929     PUSH       0xb
//                               LAB_0051e92b                                                 XREF[1]:     0051e927(j)
//         0051e92b     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0051e931     CALL       RGE_Base_Game::get_font                          RGE_Font * get_font(RGE_Base_Game * this, int
//         0051e936     MOV        EDI,EAX
//                              tpnl_tml.cpp:174 (8)
//         0051e938     MOV        EAX,dword ptr [ESP + param_8]
//         0051e93c     TEST       EAX,EAX
//         0051e93e     JL         LAB_0051e943
//                              tpnl_tml.cpp:175 (1)
//         0051e940     PUSH       EAX
//                              tpnl_tml.cpp:176 (2)
//         0051e941     JMP        LAB_0051e945
//                               LAB_0051e943                                                 XREF[1]:     0051e93e(j)
//                              tpnl_tml.cpp:177 (13)
//         0051e943     PUSH       0xb
//                               LAB_0051e945                                                 XREF[1]:     0051e941(j)
//         0051e945     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0051e94b     CALL       RGE_Base_Game::get_font                          RGE_Font * get_font(RGE_Base_Game * this, int
//                              tpnl_tml.cpp:181 (70)
//         0051e950     MOV        EDX,dword ptr [EAX + 0x8]
//         0051e953     MOV        this,dword ptr [EAX + 0x4]
//         0051e956     PUSH       0x0
//         0051e958     PUSH       0x0
//         0051e95a     PUSH       0x0
//         0051e95c     PUSH       0x0
//         0051e95e     PUSH       0x0
//         0051e960     PUSH       0x0
//         0051e962     PUSH       EDX
//         0051e963     MOV        EDX,dword ptr [EAX]
//         0051e965     MOV        EAX,dword ptr [EDI + 0x8]
//         0051e968     PUSH       this
//         0051e969     MOV        this,dword ptr [EDI + 0x4]
//         0051e96c     PUSH       EDX
//         0051e96d     MOV        EDX,dword ptr [EDI]
//         0051e96f     PUSH       EAX
//         0051e970     MOV        EAX,dword ptr [ESP + param_1]
//         0051e974     PUSH       this
//         0051e975     MOV        this,dword ptr [ESP + param_3]
//         0051e979     PUSH       EDX
//         0051e97a     PUSH       EBX
//         0051e97b     PUSH       EAX
//         0051e97c     PUSH       this
//         0051e97d     PUSH       EBP
//         0051e97e     PUSH       ESI
//         0051e97f     MOV        this,ESI
//         0051e981     CALL       TPanel::renderArea                               TDrawArea * renderArea(TPanel * this)
//         0051e986     MOV        ESI,dword ptr [ESP + param_2]
//         0051e98a     PUSH       EAX
//         0051e98b     MOV        this,dword ptr [ESI]
//         0051e98d     CALL       Time_Line_Panel::setup                           long setup(Time_Line_Panel * this, TDrawArea
//         0051e992     TEST       EAX,EAX
//         0051e994     JNZ        LAB_0051e9a6
//                              tpnl_tml.cpp:183 (14)
//         0051e996     MOV        EDX,dword ptr [ESP + local_10]
//         0051e99a     MOV        dword ptr [EDX + 0xd8],0x1
//                              tpnl_tml.cpp:184 (2)
//         0051e9a4     JMP        LAB_0051e9c2
//                               LAB_0051e9a6                                                 XREF[1]:     0051e994(j)
//                              tpnl_tml.cpp:187 (7)
//         0051e9a6     MOV        this,dword ptr [ESI]
//         0051e9a8     CALL       Time_Line_Panel::init_timeline                   void init_timeline(Time_Line_Panel * this)
//                              tpnl_tml.cpp:189 (7)
//         0051e9ad     MOV        EAX,0x1
//         0051e9b2     JMP        LAB_0051e9c4
//                               LAB_0051e9b4                                                 XREF[2]:     0051e90a(j), 0051e918(j)
//                              tpnl_tml.cpp:163 (14)
//         0051e9b4     MOV        EAX,dword ptr [ESP + local_10]
//         0051e9b8     MOV        dword ptr [EAX + 0xd8],0x1
//                               LAB_0051e9c2                                                 XREF[1]:     0051e9a4(j)
//                              tpnl_tml.cpp:164 (2)
//         0051e9c2     XOR        EAX,EAX
//                               LAB_0051e9c4                                                 XREF[1]:     0051e9b2(j)
//                              tpnl_tml.cpp:190 (21)
//         0051e9c4     MOV        this,dword ptr [ESP + local_c]
//         0051e9c8     POP        EDI
//         0051e9c9     POP        ESI
//         0051e9ca     POP        EBP
//         0051e9cb     MOV        dword ptr FS:[0x0],this
//         0051e9d2     POP        EBX
//         0051e9d3     ADD        ESP,0x10
//         0051e9d6     RET        0x28
//         0051e9d9     ??         90h
//         0051e9da     NOP
//         0051e9db     NOP
//         0051e9dc     NOP
//         0051e9dd     NOP
//         0051e9de     NOP
//         0051e9df     NOP
    return 0;
}

long Time_Line_Panel::setup(TDrawArea* param_1, TPanel* param_2, long param_3, long param_4, long param_5, long param_6, void* param_7, long param_8, long param_9, void* param_10, long param_11, long param_12, char* param_13, char* param_14, int param_15, uchar param_16, int param_17, uchar param_18) {
    /* TODO: Stub */
//                              long __thiscall setup(Time_Line_Panel * this, TDrawArea * param_1, T
//              long              EAX:4          <RETURN>
//              Time_Line_Pane    ECX:4 (auto)   this
//              TDrawArea *       Stack[0x4]:4   param_1                   XREF[1]:     0051e9fc(R)
//              TPanel *          Stack[0x8]:4   param_2                   XREF[1]:     0051e9f7(R)
//              long              Stack[0xc]:4   param_3                   XREF[1]:     0051e9f2(R)
//              long              Stack[0x10]:4  param_4                   XREF[1]:     0051e9e4(R)
//              long              Stack[0x14]:4  param_5                   XREF[1]:     0051e9eb(R)
//              long              Stack[0x18]:4  param_6                   XREF[1]:     0051e9e0(R)
//              void *            Stack[0x1c]:4  param_7                   XREF[1]:     0051ea48(R)
//              long              Stack[0x20]:4  param_8                   XREF[1]:     0051ea44(R)
//              long              Stack[0x24]:4  param_9                   XREF[1]:     0051ea40(R)
//              void *            Stack[0x28]:4  param_10                  XREF[1]:     0051ea5e(R)
//              long              Stack[0x2c]:4  param_11                  XREF[1]:     0051ea5a(R)
//              long              Stack[0x30]:4  param_12                  XREF[1]:     0051ea56(R)
//              char *            Stack[0x34]:4  param_13                  XREF[1]:     0051ea6c(R)
//              char *            Stack[0x38]:4  param_14                  XREF[1]:     0051ea78(R)
//              int               Stack[0x3c]:4  param_15                  XREF[1]:     0051ea0a(R)
//              uchar             Stack[0x40]:1  param_16                  XREF[1]:     0051ea0e(R)
//              int               Stack[0x44]:4  param_17                  XREF[1]:     0051ea1c(R)
//              uchar             Stack[0x48]:1  param_18                  XREF[1]:     0051ea12(R)
//                               ?setup@Time_Line_Panel@@QAEJPAVTDrawArea@@PAVTPanel@@JJJJPA  XREF[1]:     create_timeline:0051e98d(c)
//                               Time_Line_Panel::setup
//                              tpnl_tml.cpp:202 (42)
//         0051e9e0     MOV        EAX,dword ptr [ESP + param_6]
//         0051e9e4     MOV        EDX,dword ptr [ESP + param_4]
//         0051e9e8     PUSH       ESI
//         0051e9e9     MOV        ESI,this
//         0051e9eb     MOV        this,dword ptr [ESP + param_5]
//         0051e9ef     PUSH       0x0
//         0051e9f1     PUSH       EAX
//         0051e9f2     MOV        EAX,dword ptr [ESP + param_3]
//         0051e9f6     PUSH       this
//         0051e9f7     MOV        this,dword ptr [ESP + param_2]
//         0051e9fb     PUSH       EDX
//         0051e9fc     MOV        EDX,dword ptr [ESP + param_1]
//         0051ea00     PUSH       EAX
//         0051ea01     PUSH       this
//         0051ea02     PUSH       EDX
//         0051ea03     MOV        this,ESI
//         0051ea05     CALL       TPanel::setup                                    long setup(TPanel * this, TDrawArea * param_1
//                              tpnl_tml.cpp:207 (4)
//         0051ea0a     MOV        EAX,dword ptr [ESP + param_15]
//                              tpnl_tml.cpp:208 (4)
//         0051ea0e     MOV        this,byte ptr [ESP + param_16]
//                              tpnl_tml.cpp:210 (20)
//         0051ea12     MOV        DL,byte ptr [ESP + param_18]
//         0051ea16     MOV        dword ptr [ESI + 0x4b4],EAX
//         0051ea1c     MOV        EAX,dword ptr [ESP + param_17]
//         0051ea20     MOV        byte ptr [ESI + 0x4b8],this
//                              tpnl_tml.cpp:213 (16)
//         0051ea26     TEST       EAX,EAX
//         0051ea28     MOV        dword ptr [ESI + 0x4bc],EAX
//         0051ea2e     MOV        byte ptr [ESI + 0x4c0],DL
//         0051ea34     JZ         LAB_0051ea40
//                              tpnl_tml.cpp:214 (10)
//         0051ea36     MOV        dword ptr [ESI + 0x4c8],0x1
//                               LAB_0051ea40                                                 XREF[1]:     0051ea34(j)
//                              tpnl_tml.cpp:216 (22)
//         0051ea40     MOV        EAX,dword ptr [ESP + param_9]
//         0051ea44     MOV        this,dword ptr [ESP + param_8]
//         0051ea48     MOV        EDX,dword ptr [ESP + param_7]
//         0051ea4c     PUSH       EAX
//         0051ea4d     PUSH       this
//         0051ea4e     PUSH       EDX
//         0051ea4f     MOV        this,ESI
//         0051ea51     CALL       Time_Line_Panel::set_axis_font                   void set_axis_font(Time_Line_Panel * this, vo
//                              tpnl_tml.cpp:217 (22)
//         0051ea56     MOV        EAX,dword ptr [ESP + param_12]
//         0051ea5a     MOV        this,dword ptr [ESP + param_11]
//         0051ea5e     MOV        EDX,dword ptr [ESP + param_10]
//         0051ea62     PUSH       EAX
//         0051ea63     PUSH       this
//         0051ea64     PUSH       EDX
//         0051ea65     MOV        this,ESI
//         0051ea67     CALL       Time_Line_Panel::set_body_font                   void set_body_font(Time_Line_Panel * this, vo
//                              tpnl_tml.cpp:218 (12)
//         0051ea6c     MOV        EAX,dword ptr [ESP + param_13]
//         0051ea70     MOV        this,ESI
//         0051ea72     PUSH       EAX
//         0051ea73     CALL       Time_Line_Panel::set_background                  int set_background(Time_Line_Panel * this, ch
//                              tpnl_tml.cpp:219 (12)
//         0051ea78     MOV        this,dword ptr [ESP + param_14]
//         0051ea7c     PUSH       this
//         0051ea7d     MOV        this,ESI
//         0051ea7f     CALL       Time_Line_Panel::set_special_events              int set_special_events(Time_Line_Panel * this
//                              tpnl_tml.cpp:223 (21)
//         0051ea84     MOV        EDX,dword ptr [ESI + 0x20]
//         0051ea87     PUSH       0x0
//         0051ea89     MOV        EAX,dword ptr [EDX]
//         0051ea8b     MOV        this,dword ptr [EAX + 0x8]
//         0051ea8e     PUSH       this
//         0051ea8f     CALL       dword ptr [->GDI32.DLL::GetNearestPaletteIndex]  = 0048b294
//         0051ea95     MOV        byte ptr [ESP + 0x44],AL
//                              tpnl_tml.cpp:224 (14)
//         0051ea99     MOV        this,ESI
//         0051ea9b     MOV        EDX,dword ptr [ESP + 0x44]
//         0051ea9f     PUSH       EDX
//         0051eaa0     PUSH       0x1
//         0051eaa2     CALL       Time_Line_Panel::set_back_color                  void set_back_color(Time_Line_Panel * this, i
//                              tpnl_tml.cpp:226 (5)
//         0051eaa7     MOV        EAX,0x1
//                              tpnl_tml.cpp:227 (4)
//         0051eaac     POP        ESI
//         0051eaad     RET        0x48
    return 0;
}

void Time_Line_Panel::set_bevel_info(int param_1, int param_2, int param_3, int param_4, int param_5, int param_6, int param_7) {
    /* TODO: Stub */
//                              void __thiscall set_bevel_info(Time_Line_Panel * this, int param_1,
//              void              <VOID>         <RETURN>
//              Time_Line_Pane    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     0051eab0(R)
//              int               Stack[0x8]:4   param_2                   XREF[1]:     0051eab4(R)
//              int               Stack[0xc]:4   param_3                   XREF[1]:     0051eabe(R)
//              int               Stack[0x10]:4  param_4                   XREF[1]:     0051eac8(R)
//              int               Stack[0x14]:4  param_5                   XREF[1]:     0051ead2(R)
//              int               Stack[0x18]:4  param_6                   XREF[1]:     0051eadc(R)
//              int               Stack[0x1c]:4  param_7                   XREF[1]:     0051eae6(R)
//                               ?set_bevel_info@Time_Line_Panel@@QAEXHHHHHHH@Z               XREF[1]:     TribeAchievementsScreen:0048d9ba(c
//                               Time_Line_Panel::set_bevel_info
//                              tpnl_tml.cpp:234 (4)
//         0051eab0     MOV        EAX,dword ptr [ESP + param_1]
//                              tpnl_tml.cpp:236 (10)
//         0051eab4     MOV        DL,byte ptr [ESP + param_2]
//         0051eab8     MOV        dword ptr [ECX + this->bevel_type],EAX
//                              tpnl_tml.cpp:237 (10)
//         0051eabe     MOV        AL,byte ptr [ESP + param_3]
//         0051eac2     MOV        byte ptr [ECX + this->bevel_color1],DL
//                              tpnl_tml.cpp:238 (10)
//         0051eac8     MOV        DL,byte ptr [ESP + param_4]
//         0051eacc     MOV        byte ptr [ECX + this->bevel_color2],AL
//                              tpnl_tml.cpp:239 (10)
//         0051ead2     MOV        AL,byte ptr [ESP + param_5]
//         0051ead6     MOV        byte ptr [ECX + this->bevel_color3],DL
//                              tpnl_tml.cpp:240 (10)
//         0051eadc     MOV        DL,byte ptr [ESP + param_6]
//         0051eae0     MOV        byte ptr [ECX + this->bevel_color4],AL
//                              tpnl_tml.cpp:241 (16)
//         0051eae6     MOV        AL,byte ptr [ESP + param_7]
//         0051eaea     MOV        byte ptr [ECX + this->bevel_color5],DL
//         0051eaf0     MOV        byte ptr [ECX + this->bevel_color6],AL
//                              tpnl_tml.cpp:242 (3)
//         0051eaf6     RET        0x1c
//         0051eaf9     ??         90h
//         0051eafa     NOP
//         0051eafb     NOP
//         0051eafc     NOP
//         0051eafd     NOP
//         0051eafe     NOP
//         0051eaff     NOP
    return;
}

int Time_Line_Panel::set_background(char* param_1) {
    /* TODO: Stub */
//                              int __thiscall set_background(Time_Line_Panel * this, char * param_1)
//              int               EAX:4          <RETURN>
//              Time_Line_Pane    ECX:4 (auto)   this
//              char *            Stack[0x4]:4   param_1                   XREF[2]:     0051eb4d(R), 0051eb6b(W)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     0051eb71(W), 0051eb9c(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[2]:     0051ebd8(R), 0051ebec(R)
//              undefined4        Stack[-0x10]:4 local_10                  XREF[2]:     0051eb90(*), 0051ebbb(R)
//              long              Stack[-0x14]:4 y_min                     XREF[2]:     0051eb85(*), 0051ebb7(R)
//              long              Stack[-0x18]:4 y_max                     XREF[2]:     0051eb94(*), 0051ebb3(R)
//              long              Stack[-0x1c]:4 x_min                     XREF[2]:     0051eb8a(*), 0051ebaf(R)
//              long              Stack[-0x20]:4 x_max
//                               ?set_background@Time_Line_Panel@@QAEHPAD@Z                   XREF[1]:     setup:0051ea73(c)
//                               Time_Line_Panel::set_background
//                              tpnl_tml.cpp:248 (29)
//         0051eb00     MOV        EAX,FS:[0x0]
//         0051eb06     PUSH       -0x1
//         0051eb08     PUSH       FUN_005614ab
//         0051eb0d     PUSH       EAX
//         0051eb0e     MOV        dword ptr FS:[0x0],ESP
//         0051eb15     SUB        ESP,0x10
//         0051eb18     PUSH       EBX
//         0051eb19     PUSH       ESI
//         0051eb1a     MOV        ESI,this
//         0051eb1c     PUSH       EDI
//                              tpnl_tml.cpp:251 (12)
//         0051eb1d     XOR        EBX,EBX
//         0051eb1f     MOV        EDI,dword ptr [ESI + 0x4ac]
//         0051eb25     CMP        EDI,EBX
//         0051eb27     JZ         LAB_0051eb4d
//                              tpnl_tml.cpp:253 (16)
//         0051eb29     MOV        this,EDI
//         0051eb2b     CALL       TShape::~TShape                                  void ~TShape(TShape * this)
//         0051eb30     PUSH       EDI
//         0051eb31     CALL       operator_delete                                  void operator_delete(void * param_1)
//         0051eb36     ADD        ESP,0x4
//                              tpnl_tml.cpp:254 (6)
//         0051eb39     MOV        dword ptr [ESI + 0x4ac],EBX
//                              tpnl_tml.cpp:255 (7)
//         0051eb3f     MOV        word ptr [ESI + 0x4b0],BX
//                              tpnl_tml.cpp:256 (7)
//         0051eb46     MOV        word ptr [ESI + 0x4b2],BX
//                               LAB_0051eb4d                                                 XREF[1]:     0051eb27(j)
//                              tpnl_tml.cpp:259 (20)
//         0051eb4d     MOV        EDI,dword ptr [ESP + param_1]
//         0051eb51     CMP        EDI,EBX
//         0051eb53     JZ         LAB_0051ebec
//         0051eb59     CMP        byte ptr [EDI],BL
//         0051eb5b     JZ         LAB_0051ebec
//                              tpnl_tml.cpp:261 (36)
//         0051eb61     PUSH       0x20
//         0051eb63     CALL       operator_new                                     void * operator_new(uint param_1)
//         0051eb68     ADD        ESP,0x4
//         0051eb6b     MOV        dword ptr [ESP + param_1],EAX
//         0051eb6f     CMP        EAX,EBX
//         0051eb71     MOV        dword ptr [ESP + local_4],EBX
//         0051eb75     JZ         LAB_0051eb83
//         0051eb77     PUSH       -0x1
//         0051eb79     PUSH       EDI
//         0051eb7a     MOV        this,EAX
//         0051eb7c     CALL       TShape::TShape                                   undefined TShape(TShape * this, char * param_
//         0051eb81     JMP        LAB_0051eb85
//                               LAB_0051eb83                                                 XREF[1]:     0051eb75(j)
//         0051eb83     XOR        EAX,EAX
//                               LAB_0051eb85                                                 XREF[1]:     0051eb81(j)
//                              tpnl_tml.cpp:262 (42)
//         0051eb85     LEA        this=>y_min,[ESP + 0x14]
//         0051eb89     PUSH       EBX
//         0051eb8a     LEA        EDX=>x_min,[ESP + 0x10]
//         0051eb8e     PUSH       this
//         0051eb8f     PUSH       EDX
//         0051eb90     LEA        this=>local_10,[ESP + 0x24]
//         0051eb94     LEA        EDX=>y_max,[ESP + 0x1c]
//         0051eb98     PUSH       this
//         0051eb99     PUSH       EDX
//         0051eb9a     MOV        this,EAX
//         0051eb9c     MOV        dword ptr [ESP + local_4],0xffffffff
//         0051eba4     MOV        dword ptr [ESI + 0x4ac],EAX
//         0051ebaa     CALL       TShape::shape_minmax                             uchar shape_minmax(TShape * this, long * para
//                              tpnl_tml.cpp:263 (8)
//         0051ebaf     MOV        EAX,dword ptr [ESP + x_min]
//         0051ebb3     MOV        EBX,dword ptr [ESP + y_max]
//                              tpnl_tml.cpp:264 (28)
//         0051ebb7     MOV        this,dword ptr [ESP + y_min]
//         0051ebbb     MOV        EDX,dword ptr [ESP + local_10]
//         0051ebbf     SUB        EAX,EBX
//         0051ebc1     SUB        this,EDX
//         0051ebc3     INC        EAX
//         0051ebc4     INC        this
//         0051ebc5     MOV        word ptr [ESI + 0x4b0],AX
//         0051ebcc     MOV        word ptr [ESI + 0x4b2],this
//                              tpnl_tml.cpp:265 (5)
//         0051ebd3     MOV        EAX,0x1
//                              tpnl_tml.cpp:268 (42)
//         0051ebd8     MOV        this,dword ptr [ESP + local_c]
//         0051ebdc     MOV        dword ptr FS:[0x0],this
//         0051ebe3     POP        EDI
//         0051ebe4     POP        ESI
//         0051ebe5     POP        EBX
//         0051ebe6     ADD        ESP,0x1c
//         0051ebe9     RET        0x4
//                               LAB_0051ebec                                                 XREF[2]:     0051eb53(j), 0051eb5b(j)
//         0051ebec     MOV        this,dword ptr [ESP + local_c]
//         0051ebf0     POP        EDI
//         0051ebf1     POP        ESI
//         0051ebf2     XOR        EAX,EAX
//         0051ebf4     MOV        dword ptr FS:[0x0],this
//         0051ebfb     POP        EBX
//         0051ebfc     ADD        ESP,0x1c
//         0051ebff     RET        0x4
//         0051ec02     ??         90h
//         0051ec03     NOP
//         0051ec04     NOP
//         0051ec05     NOP
//         0051ec06     NOP
//         0051ec07     NOP
//         0051ec08     NOP
//         0051ec09     NOP
//         0051ec0a     NOP
//         0051ec0b     NOP
//         0051ec0c     NOP
//         0051ec0d     NOP
//         0051ec0e     NOP
//         0051ec0f     NOP
    return 0;
}

int Time_Line_Panel::set_background(char* param_1, long param_2) {
    /* TODO: Stub */
//                              int __thiscall set_background(Time_Line_Panel * this, char * param_1
//              int               EAX:4          <RETURN>
//              Time_Line_Pane    ECX:4 (auto)   this
//              char *            Stack[0x4]:4   param_1                   XREF[1]:     0051ec60(R)
//              long              Stack[0x8]:4   param_2                   XREF[2]:     0051ecc8(R), 0051ecde(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[3]:     0051ecbf(W), 0051ecfa(W), 0051ed18(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     0051edad(R)
//              char[260]         Stack[-0x114   file_name2                XREF[2,3]:   0051ed6b(*), 0051ed80(R), 0051ec91(*), 0051ec9d(*),
//                                                                                     0051eccf(*)
//              long              Stack[-0x118   x_max                     XREF[2]:     0051ecb9(W), 0051ecf4(W)
//              undefined4        Stack[-0x11c   local_11c                 XREF[2]:     0051ed75(*), 0051ed84(R)
//              long              Stack[-0x120   x_min                     XREF[2]:     0051ed71(*), 0051ed9b(R)
//              long              Stack[-0x124   y_min                     XREF[2]:     0051ed66(*), 0051ed88(R)
//              long              Stack[-0x128   y_max
//                               ?set_background@Time_Line_Panel@@QAEHPADJ@Z
//                               Time_Line_Panel::set_background
//                              tpnl_tml.cpp:275 (32)
//         0051ec10     MOV        EAX,FS:[0x0]
//         0051ec16     PUSH       -0x1
//         0051ec18     PUSH       FUN_005614dc
//         0051ec1d     PUSH       EAX
//         0051ec1e     MOV        dword ptr FS:[0x0],ESP
//         0051ec25     SUB        ESP,0x118
//         0051ec2b     PUSH       EBX
//         0051ec2c     PUSH       ESI
//         0051ec2d     MOV        ESI,this
//         0051ec2f     PUSH       EDI
//                              tpnl_tml.cpp:279 (12)
//         0051ec30     XOR        EBX,EBX
//         0051ec32     MOV        EDI,dword ptr [ESI + 0x4ac]
//         0051ec38     CMP        EDI,EBX
//         0051ec3a     JZ         LAB_0051ec60
//                              tpnl_tml.cpp:281 (16)
//         0051ec3c     MOV        this,EDI
//         0051ec3e     CALL       TShape::~TShape                                  void ~TShape(TShape * this)
//         0051ec43     PUSH       EDI
//         0051ec44     CALL       operator_delete                                  void operator_delete(void * param_1)
//         0051ec49     ADD        ESP,0x4
//                              tpnl_tml.cpp:282 (6)
//         0051ec4c     MOV        dword ptr [ESI + 0x4ac],EBX
//                              tpnl_tml.cpp:283 (7)
//         0051ec52     MOV        word ptr [ESI + 0x4b0],BX
//                              tpnl_tml.cpp:284 (7)
//         0051ec59     MOV        word ptr [ESI + 0x4b2],BX
//                               LAB_0051ec60                                                 XREF[1]:     0051ec3a(j)
//                              tpnl_tml.cpp:287 (33)
//         0051ec60     MOV        EDI,dword ptr [ESP + param_1]
//         0051ec67     CMP        EDI,EBX
//         0051ec69     JZ         LAB_0051ecde
//         0051ec6b     CMP        byte ptr [EDI],BL
//         0051ec6d     JZ         LAB_0051ecde
//         0051ec6f     PUSH       s_none                                           = "none"
//         0051ec74     PUSH       EDI
//         0051ec75     CALL       stricmp                                          undefined stricmp()
//         0051ec7a     ADD        ESP,0x8
//         0051ec7d     TEST       EAX,EAX
//         0051ec7f     JZ         LAB_0051ecde
//                              tpnl_tml.cpp:289 (13)
//         0051ec81     PUSH       0x2e
//         0051ec83     PUSH       EDI
//         0051ec84     CALL       strchr                                           undefined strchr()
//         0051ec89     ADD        ESP,0x8
//         0051ec8c     TEST       EAX,EAX
//                              tpnl_tml.cpp:290 (13)
//         0051ec8e     PUSH       EDI
//         0051ec8f     JNZ        LAB_0051ec9d
//         0051ec91     LEA        EAX=>file_name2[4],[ESP + 0x24]
//         0051ec95     PUSH       s_%s.shp                                         = "%s.shp"
//         0051ec9a     PUSH       EAX
//                              tpnl_tml.cpp:291 (2)
//         0051ec9b     JMP        LAB_0051eca7
//                               LAB_0051ec9d                                                 XREF[1]:     0051ec8f(j)
//                              tpnl_tml.cpp:292 (18)
//         0051ec9d     LEA        this=>file_name2[4],[ESP + 0x24]
//         0051eca1     PUSH       s_%s                                             = "%s"
//         0051eca6     PUSH       this
//                               LAB_0051eca7                                                 XREF[1]:     0051ec9b(j)
//         0051eca7     CALL       sprintf                                          undefined sprintf()
//         0051ecac     ADD        ESP,0xc
//                              tpnl_tml.cpp:293 (38)
//         0051ecaf     PUSH       0x20
//         0051ecb1     CALL       operator_new                                     void * operator_new(uint param_1)
//         0051ecb6     ADD        ESP,0x4
//         0051ecb9     MOV        dword ptr [ESP + x_max],EAX
//         0051ecbd     CMP        EAX,EBX
//         0051ecbf     MOV        dword ptr [ESP + local_4],EBX
//         0051ecc6     JZ         LAB_0051ed16
//         0051ecc8     MOV        EDX,dword ptr [ESP + param_2]
//         0051eccf     LEA        this=>file_name2[4],[ESP + 0x20]
//         0051ecd3     PUSH       EDX
//         0051ecd4     PUSH       this
//                              tpnl_tml.cpp:296 (9)
//         0051ecd5     MOV        this,EAX
//         0051ecd7     CALL       TShape::TShape                                   undefined TShape(TShape * this, char * param_
//         0051ecdc     JMP        LAB_0051ed18
//                               LAB_0051ecde                                                 XREF[3]:     0051ec69(j), 0051ec6d(j),
//                                                                                                         0051ec7f(j)
//                              tpnl_tml.cpp:295 (12)
//         0051ecde     MOV        EDI,dword ptr [ESP + param_2]
//         0051ece5     CMP        EDI,-0x1
//         0051ece8     JZ         LAB_0051ed29
//                              tpnl_tml.cpp:296 (63)
//         0051ecea     PUSH       0x20
//         0051ecec     CALL       operator_new                                     void * operator_new(uint param_1)
//         0051ecf1     ADD        ESP,0x4
//         0051ecf4     MOV        dword ptr [ESP + x_max],EAX
//         0051ecf8     CMP        EAX,EBX
//         0051ecfa     MOV        dword ptr [ESP + local_4],0x1
//         0051ed05     JZ         LAB_0051ed16
//         0051ed07     PUSH       EDI
//         0051ed08     PUSH       s_                                               = ""
//         0051ed0d     MOV        this,EAX
//         0051ed0f     CALL       TShape::TShape                                   undefined TShape(TShape * this, char * param_
//         0051ed14     JMP        LAB_0051ed18
//                               LAB_0051ed16                                                 XREF[2]:     0051ecc6(j), 0051ed05(j)
//         0051ed16     XOR        EAX,EAX
//                               LAB_0051ed18                                                 XREF[2]:     0051ecdc(j), 0051ed14(j)
//         0051ed18     MOV        dword ptr [ESP + local_4],0xffffffff
//         0051ed23     MOV        dword ptr [ESI + 0x4ac],EAX
//                               LAB_0051ed29                                                 XREF[1]:     0051ece8(j)
//                              tpnl_tml.cpp:298 (19)
//         0051ed29     MOV        this,dword ptr [ESI + 0x4ac]
//         0051ed2f     CMP        this,EBX
//         0051ed31     JZ         LAB_0051ed5c
//         0051ed33     CALL       TShape::is_loaded                                int is_loaded(TShape * this)
//         0051ed38     TEST       EAX,EAX
//         0051ed3a     JNZ        LAB_0051ed5c
//                              tpnl_tml.cpp:300 (26)
//         0051ed3c     MOV        EDI,dword ptr [ESI + 0x4ac]
//         0051ed42     CMP        EDI,EBX
//         0051ed44     JZ         LAB_0051ed56
//         0051ed46     MOV        this,EDI
//         0051ed48     CALL       TShape::~TShape                                  void ~TShape(TShape * this)
//         0051ed4d     PUSH       EDI
//         0051ed4e     CALL       operator_delete                                  void operator_delete(void * param_1)
//         0051ed53     ADD        ESP,0x4
//                               LAB_0051ed56                                                 XREF[1]:     0051ed44(j)
//                              tpnl_tml.cpp:301 (6)
//         0051ed56     MOV        dword ptr [ESI + 0x4ac],EBX
//                               LAB_0051ed5c                                                 XREF[2]:     0051ed31(j), 0051ed3a(j)
//                              tpnl_tml.cpp:304 (10)
//         0051ed5c     MOV        this,dword ptr [ESI + 0x4ac]
//         0051ed62     CMP        this,EBX
//         0051ed64     JZ         LAB_0051edab
//                              tpnl_tml.cpp:306 (26)
//         0051ed66     LEA        EDX=>y_min,[ESP + 0xc]
//         0051ed6a     PUSH       EBX
//         0051ed6b     LEA        EAX=>file_name2,[ESP + 0x20]
//         0051ed6f     PUSH       EDX
//         0051ed70     PUSH       EAX
//         0051ed71     LEA        EDX=>x_min,[ESP + 0x1c]
//         0051ed75     LEA        EAX=>local_11c,[ESP + 0x20]
//         0051ed79     PUSH       EDX
//         0051ed7a     PUSH       EAX
//         0051ed7b     CALL       TShape::shape_minmax                             uchar shape_minmax(TShape * this, long * para
//                              tpnl_tml.cpp:307 (8)
//         0051ed80     MOV        this,dword ptr [ESP + file_name2[0]]
//         0051ed84     MOV        EDI,dword ptr [ESP + local_11c]
//                              tpnl_tml.cpp:308 (7)
//         0051ed88     MOV        EDX,dword ptr [ESP + y_min]
//         0051ed8c     SUB        this,EDI
//         0051ed8e     INC        this
//                              tpnl_tml.cpp:309 (28)
//         0051ed8f     MOV        EAX,0x1
//         0051ed94     MOV        word ptr [ESI + 0x4b0],this
//         0051ed9b     MOV        this,dword ptr [ESP + x_min]
//         0051ed9f     SUB        EDX,this
//         0051eda1     INC        EDX
//         0051eda2     MOV        word ptr [ESI + 0x4b2],DX
//         0051eda9     JMP        LAB_0051edad
//                               LAB_0051edab                                                 XREF[1]:     0051ed64(j)
//                              tpnl_tml.cpp:312 (2)
//         0051edab     XOR        EAX,EAX
//                               LAB_0051edad                                                 XREF[1]:     0051eda9(j)
//                              tpnl_tml.cpp:314 (26)
//         0051edad     MOV        this,dword ptr [ESP + local_c]
//         0051edb4     POP        EDI
//         0051edb5     POP        ESI
//         0051edb6     MOV        dword ptr FS:[0x0],this
//         0051edbd     POP        EBX
//         0051edbe     ADD        ESP,0x124
//         0051edc4     RET        0x8
//         0051edc7     ??         90h
//         0051edc8     NOP
//         0051edc9     NOP
//         0051edca     NOP
//         0051edcb     NOP
//         0051edcc     NOP
//         0051edcd     NOP
//         0051edce     NOP
//         0051edcf     NOP
    return 0;
}

int Time_Line_Panel::set_special_events(char* param_1) {
    /* TODO: Stub */
//                              int __thiscall set_special_events(Time_Line_Panel * this, char * par
//              int               EAX:4          <RETURN>
//              Time_Line_Pane    ECX:4 (auto)   this
//              char *            Stack[0x4]:4   param_1                   XREF[2]:     0051ee1d(R), 0051ee3b(W)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     0051ee41(W), 0051ee6c(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[2]:     0051eea8(R), 0051eebc(R)
//              undefined4        Stack[-0x10]:4 local_10                  XREF[2]:     0051ee60(*), 0051ee8b(R)
//              long              Stack[-0x14]:4 y_min                     XREF[2]:     0051ee55(*), 0051ee87(R)
//              long              Stack[-0x18]:4 y_max                     XREF[2]:     0051ee64(*), 0051ee83(R)
//              long              Stack[-0x1c]:4 x_min                     XREF[2]:     0051ee5a(*), 0051ee7f(R)
//              long              Stack[-0x20]:4 x_max
//                               ?set_special_events@Time_Line_Panel@@QAEHPAD@Z               XREF[2]:     TribeAchievementsScreen:0048d9c6(c
//                               Time_Line_Panel::set_special_events                                       setup:0051ea7f(c)
//                              tpnl_tml.cpp:321 (29)
//         0051edd0     MOV        EAX,FS:[0x0]
//         0051edd6     PUSH       -0x1
//         0051edd8     PUSH       FUN_005614fb
//         0051eddd     PUSH       EAX
//         0051edde     MOV        dword ptr FS:[0x0],ESP
//         0051ede5     SUB        ESP,0x10
//         0051ede8     PUSH       EBX
//         0051ede9     PUSH       ESI
//         0051edea     MOV        ESI,this
//         0051edec     PUSH       EDI
//                              tpnl_tml.cpp:324 (12)
//         0051eded     XOR        EBX,EBX
//         0051edef     MOV        EDI,dword ptr [ESI + 0x4d4]
//         0051edf5     CMP        EDI,EBX
//         0051edf7     JZ         LAB_0051ee1d
//                              tpnl_tml.cpp:326 (16)
//         0051edf9     MOV        this,EDI
//         0051edfb     CALL       TShape::~TShape                                  void ~TShape(TShape * this)
//         0051ee00     PUSH       EDI
//         0051ee01     CALL       operator_delete                                  void operator_delete(void * param_1)
//         0051ee06     ADD        ESP,0x4
//                              tpnl_tml.cpp:327 (6)
//         0051ee09     MOV        dword ptr [ESI + 0x4d4],EBX
//                              tpnl_tml.cpp:328 (7)
//         0051ee0f     MOV        word ptr [ESI + 0x4d8],BX
//                              tpnl_tml.cpp:329 (7)
//         0051ee16     MOV        word ptr [ESI + 0x4da],BX
//                               LAB_0051ee1d                                                 XREF[1]:     0051edf7(j)
//                              tpnl_tml.cpp:332 (20)
//         0051ee1d     MOV        EDI,dword ptr [ESP + param_1]
//         0051ee21     CMP        EDI,EBX
//         0051ee23     JZ         LAB_0051eebc
//         0051ee29     CMP        byte ptr [EDI],BL
//         0051ee2b     JZ         LAB_0051eebc
//                              tpnl_tml.cpp:334 (36)
//         0051ee31     PUSH       0x20
//         0051ee33     CALL       operator_new                                     void * operator_new(uint param_1)
//         0051ee38     ADD        ESP,0x4
//         0051ee3b     MOV        dword ptr [ESP + param_1],EAX
//         0051ee3f     CMP        EAX,EBX
//         0051ee41     MOV        dword ptr [ESP + local_4],EBX
//         0051ee45     JZ         LAB_0051ee53
//         0051ee47     PUSH       -0x1
//         0051ee49     PUSH       EDI
//         0051ee4a     MOV        this,EAX
//         0051ee4c     CALL       TShape::TShape                                   undefined TShape(TShape * this, char * param_
//         0051ee51     JMP        LAB_0051ee55
//                               LAB_0051ee53                                                 XREF[1]:     0051ee45(j)
//         0051ee53     XOR        EAX,EAX
//                               LAB_0051ee55                                                 XREF[1]:     0051ee51(j)
//                              tpnl_tml.cpp:335 (42)
//         0051ee55     LEA        this=>y_min,[ESP + 0x14]
//         0051ee59     PUSH       EBX
//         0051ee5a     LEA        EDX=>x_min,[ESP + 0x10]
//         0051ee5e     PUSH       this
//         0051ee5f     PUSH       EDX
//         0051ee60     LEA        this=>local_10,[ESP + 0x24]
//         0051ee64     LEA        EDX=>y_max,[ESP + 0x1c]
//         0051ee68     PUSH       this
//         0051ee69     PUSH       EDX
//         0051ee6a     MOV        this,EAX
//         0051ee6c     MOV        dword ptr [ESP + local_4],0xffffffff
//         0051ee74     MOV        dword ptr [ESI + 0x4d4],EAX
//         0051ee7a     CALL       TShape::shape_minmax                             uchar shape_minmax(TShape * this, long * para
//                              tpnl_tml.cpp:336 (8)
//         0051ee7f     MOV        EAX,dword ptr [ESP + x_min]
//         0051ee83     MOV        EBX,dword ptr [ESP + y_max]
//                              tpnl_tml.cpp:337 (28)
//         0051ee87     MOV        this,dword ptr [ESP + y_min]
//         0051ee8b     MOV        EDX,dword ptr [ESP + local_10]
//         0051ee8f     SUB        EAX,EBX
//         0051ee91     SUB        this,EDX
//         0051ee93     INC        EAX
//         0051ee94     INC        this
//         0051ee95     MOV        word ptr [ESI + 0x4d8],AX
//         0051ee9c     MOV        word ptr [ESI + 0x4da],this
//                              tpnl_tml.cpp:338 (5)
//         0051eea3     MOV        EAX,0x1
//                              tpnl_tml.cpp:341 (42)
//         0051eea8     MOV        this,dword ptr [ESP + local_c]
//         0051eeac     MOV        dword ptr FS:[0x0],this
//         0051eeb3     POP        EDI
//         0051eeb4     POP        ESI
//         0051eeb5     POP        EBX
//         0051eeb6     ADD        ESP,0x1c
//         0051eeb9     RET        0x4
//                               LAB_0051eebc                                                 XREF[2]:     0051ee23(j), 0051ee2b(j)
//         0051eebc     MOV        this,dword ptr [ESP + local_c]
//         0051eec0     POP        EDI
//         0051eec1     POP        ESI
//         0051eec2     XOR        EAX,EAX
//         0051eec4     MOV        dword ptr FS:[0x0],this
//         0051eecb     POP        EBX
//         0051eecc     ADD        ESP,0x1c
//         0051eecf     RET        0x4
//         0051eed2     ??         90h
//         0051eed3     NOP
//         0051eed4     NOP
//         0051eed5     NOP
//         0051eed6     NOP
//         0051eed7     NOP
//         0051eed8     NOP
//         0051eed9     NOP
//         0051eeda     NOP
//         0051eedb     NOP
//         0051eedc     NOP
//         0051eedd     NOP
//         0051eede     NOP
//         0051eedf     NOP
    return 0;
}

int Time_Line_Panel::set_special_events(char* param_1, long param_2) {
    /* TODO: Stub */
//                              int __thiscall set_special_events(Time_Line_Panel * this, char * par
//              int               EAX:4          <RETURN>
//              Time_Line_Pane    ECX:4 (auto)   this
//              char *            Stack[0x4]:4   param_1                   XREF[1]:     0051ef30(R)
//              long              Stack[0x8]:4   param_2                   XREF[2]:     0051ef98(R), 0051efae(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[3]:     0051ef8f(W), 0051efca(W), 0051efe8(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     0051f07d(R)
//              char[260]         Stack[-0x114   file_name2                XREF[2,3]:   0051f03b(*), 0051f050(R), 0051ef61(*), 0051ef6d(*),
//                                                                                     0051ef9f(*)
//              long              Stack[-0x118   x_max                     XREF[2]:     0051ef89(W), 0051efc4(W)
//              undefined4        Stack[-0x11c   local_11c                 XREF[2]:     0051f045(*), 0051f054(R)
//              long              Stack[-0x120   x_min                     XREF[2]:     0051f041(*), 0051f06b(R)
//              long              Stack[-0x124   y_min                     XREF[2]:     0051f036(*), 0051f058(R)
//              long              Stack[-0x128   y_max
//                               ?set_special_events@Time_Line_Panel@@QAEHPADJ@Z
//                               Time_Line_Panel::set_special_events
//                              tpnl_tml.cpp:348 (32)
//         0051eee0     MOV        EAX,FS:[0x0]
//         0051eee6     PUSH       -0x1
//         0051eee8     PUSH       FUN_0056152c
//         0051eeed     PUSH       EAX
//         0051eeee     MOV        dword ptr FS:[0x0],ESP
//         0051eef5     SUB        ESP,0x118
//         0051eefb     PUSH       EBX
//         0051eefc     PUSH       ESI
//         0051eefd     MOV        ESI,this
//         0051eeff     PUSH       EDI
//                              tpnl_tml.cpp:352 (12)
//         0051ef00     XOR        EBX,EBX
//         0051ef02     MOV        EDI,dword ptr [ESI + 0x4d4]
//         0051ef08     CMP        EDI,EBX
//         0051ef0a     JZ         LAB_0051ef30
//                              tpnl_tml.cpp:354 (16)
//         0051ef0c     MOV        this,EDI
//         0051ef0e     CALL       TShape::~TShape                                  void ~TShape(TShape * this)
//         0051ef13     PUSH       EDI
//         0051ef14     CALL       operator_delete                                  void operator_delete(void * param_1)
//         0051ef19     ADD        ESP,0x4
//                              tpnl_tml.cpp:355 (6)
//         0051ef1c     MOV        dword ptr [ESI + 0x4d4],EBX
//                              tpnl_tml.cpp:356 (7)
//         0051ef22     MOV        word ptr [ESI + 0x4d8],BX
//                              tpnl_tml.cpp:357 (7)
//         0051ef29     MOV        word ptr [ESI + 0x4da],BX
//                               LAB_0051ef30                                                 XREF[1]:     0051ef0a(j)
//                              tpnl_tml.cpp:360 (33)
//         0051ef30     MOV        EDI,dword ptr [ESP + param_1]
//         0051ef37     CMP        EDI,EBX
//         0051ef39     JZ         LAB_0051efae
//         0051ef3b     CMP        byte ptr [EDI],BL
//         0051ef3d     JZ         LAB_0051efae
//         0051ef3f     PUSH       s_none                                           = "none"
//         0051ef44     PUSH       EDI
//         0051ef45     CALL       stricmp                                          undefined stricmp()
//         0051ef4a     ADD        ESP,0x8
//         0051ef4d     TEST       EAX,EAX
//         0051ef4f     JZ         LAB_0051efae
//                              tpnl_tml.cpp:362 (13)
//         0051ef51     PUSH       0x2e
//         0051ef53     PUSH       EDI
//         0051ef54     CALL       strchr                                           undefined strchr()
//         0051ef59     ADD        ESP,0x8
//         0051ef5c     TEST       EAX,EAX
//                              tpnl_tml.cpp:363 (13)
//         0051ef5e     PUSH       EDI
//         0051ef5f     JNZ        LAB_0051ef6d
//         0051ef61     LEA        EAX=>file_name2[4],[ESP + 0x24]
//         0051ef65     PUSH       s_%s.shp                                         = "%s.shp"
//         0051ef6a     PUSH       EAX
//                              tpnl_tml.cpp:364 (2)
//         0051ef6b     JMP        LAB_0051ef77
//                               LAB_0051ef6d                                                 XREF[1]:     0051ef5f(j)
//                              tpnl_tml.cpp:365 (18)
//         0051ef6d     LEA        this=>file_name2[4],[ESP + 0x24]
//         0051ef71     PUSH       s_%s                                             = "%s"
//         0051ef76     PUSH       this
//                               LAB_0051ef77                                                 XREF[1]:     0051ef6b(j)
//         0051ef77     CALL       sprintf                                          undefined sprintf()
//         0051ef7c     ADD        ESP,0xc
//                              tpnl_tml.cpp:366 (38)
//         0051ef7f     PUSH       0x20
//         0051ef81     CALL       operator_new                                     void * operator_new(uint param_1)
//         0051ef86     ADD        ESP,0x4
//         0051ef89     MOV        dword ptr [ESP + x_max],EAX
//         0051ef8d     CMP        EAX,EBX
//         0051ef8f     MOV        dword ptr [ESP + local_4],EBX
//         0051ef96     JZ         LAB_0051efe6
//         0051ef98     MOV        EDX,dword ptr [ESP + param_2]
//         0051ef9f     LEA        this=>file_name2[4],[ESP + 0x20]
//         0051efa3     PUSH       EDX
//         0051efa4     PUSH       this
//                              tpnl_tml.cpp:369 (9)
//         0051efa5     MOV        this,EAX
//         0051efa7     CALL       TShape::TShape                                   undefined TShape(TShape * this, char * param_
//         0051efac     JMP        LAB_0051efe8
//                               LAB_0051efae                                                 XREF[3]:     0051ef39(j), 0051ef3d(j),
//                                                                                                         0051ef4f(j)
//                              tpnl_tml.cpp:368 (12)
//         0051efae     MOV        EDI,dword ptr [ESP + param_2]
//         0051efb5     CMP        EDI,-0x1
//         0051efb8     JZ         LAB_0051eff9
//                              tpnl_tml.cpp:369 (63)
//         0051efba     PUSH       0x20
//         0051efbc     CALL       operator_new                                     void * operator_new(uint param_1)
//         0051efc1     ADD        ESP,0x4
//         0051efc4     MOV        dword ptr [ESP + x_max],EAX
//         0051efc8     CMP        EAX,EBX
//         0051efca     MOV        dword ptr [ESP + local_4],0x1
//         0051efd5     JZ         LAB_0051efe6
//         0051efd7     PUSH       EDI
//         0051efd8     PUSH       s_                                               = ""
//         0051efdd     MOV        this,EAX
//         0051efdf     CALL       TShape::TShape                                   undefined TShape(TShape * this, char * param_
//         0051efe4     JMP        LAB_0051efe8
//                               LAB_0051efe6                                                 XREF[2]:     0051ef96(j), 0051efd5(j)
//         0051efe6     XOR        EAX,EAX
//                               LAB_0051efe8                                                 XREF[2]:     0051efac(j), 0051efe4(j)
//         0051efe8     MOV        dword ptr [ESP + local_4],0xffffffff
//         0051eff3     MOV        dword ptr [ESI + 0x4d4],EAX
//                               LAB_0051eff9                                                 XREF[1]:     0051efb8(j)
//                              tpnl_tml.cpp:371 (19)
//         0051eff9     MOV        this,dword ptr [ESI + 0x4d4]
//         0051efff     CMP        this,EBX
//         0051f001     JZ         LAB_0051f02c
//         0051f003     CALL       TShape::is_loaded                                int is_loaded(TShape * this)
//         0051f008     TEST       EAX,EAX
//         0051f00a     JNZ        LAB_0051f02c
//                              tpnl_tml.cpp:373 (26)
//         0051f00c     MOV        EDI,dword ptr [ESI + 0x4d4]
//         0051f012     CMP        EDI,EBX
//         0051f014     JZ         LAB_0051f026
//         0051f016     MOV        this,EDI
//         0051f018     CALL       TShape::~TShape                                  void ~TShape(TShape * this)
//         0051f01d     PUSH       EDI
//         0051f01e     CALL       operator_delete                                  void operator_delete(void * param_1)
//         0051f023     ADD        ESP,0x4
//                               LAB_0051f026                                                 XREF[1]:     0051f014(j)
//                              tpnl_tml.cpp:374 (6)
//         0051f026     MOV        dword ptr [ESI + 0x4d4],EBX
//                               LAB_0051f02c                                                 XREF[2]:     0051f001(j), 0051f00a(j)
//                              tpnl_tml.cpp:377 (10)
//         0051f02c     MOV        this,dword ptr [ESI + 0x4d4]
//         0051f032     CMP        this,EBX
//         0051f034     JZ         LAB_0051f07b
//                              tpnl_tml.cpp:379 (26)
//         0051f036     LEA        EDX=>y_min,[ESP + 0xc]
//         0051f03a     PUSH       EBX
//         0051f03b     LEA        EAX=>file_name2,[ESP + 0x20]
//         0051f03f     PUSH       EDX
//         0051f040     PUSH       EAX
//         0051f041     LEA        EDX=>x_min,[ESP + 0x1c]
//         0051f045     LEA        EAX=>local_11c,[ESP + 0x20]
//         0051f049     PUSH       EDX
//         0051f04a     PUSH       EAX
//         0051f04b     CALL       TShape::shape_minmax                             uchar shape_minmax(TShape * this, long * para
//                              tpnl_tml.cpp:380 (8)
//         0051f050     MOV        this,dword ptr [ESP + file_name2[0]]
//         0051f054     MOV        EDI,dword ptr [ESP + local_11c]
//                              tpnl_tml.cpp:381 (7)
//         0051f058     MOV        EDX,dword ptr [ESP + y_min]
//         0051f05c     SUB        this,EDI
//         0051f05e     INC        this
//                              tpnl_tml.cpp:382 (28)
//         0051f05f     MOV        EAX,0x1
//         0051f064     MOV        word ptr [ESI + 0x4d8],this
//         0051f06b     MOV        this,dword ptr [ESP + x_min]
//         0051f06f     SUB        EDX,this
//         0051f071     INC        EDX
//         0051f072     MOV        word ptr [ESI + 0x4da],DX
//         0051f079     JMP        LAB_0051f07d
//                               LAB_0051f07b                                                 XREF[1]:     0051f034(j)
//                              tpnl_tml.cpp:385 (2)
//         0051f07b     XOR        EAX,EAX
//                               LAB_0051f07d                                                 XREF[1]:     0051f079(j)
//                              tpnl_tml.cpp:387 (26)
//         0051f07d     MOV        this,dword ptr [ESP + local_c]
//         0051f084     POP        EDI
//         0051f085     POP        ESI
//         0051f086     MOV        dword ptr FS:[0x0],this
//         0051f08d     POP        EBX
//         0051f08e     ADD        ESP,0x124
//         0051f094     RET        0x8
//         0051f097     ??         90h
//         0051f098     NOP
//         0051f099     NOP
//         0051f09a     NOP
//         0051f09b     NOP
//         0051f09c     NOP
//         0051f09d     NOP
//         0051f09e     NOP
//         0051f09f     NOP
    return 0;
}

void Time_Line_Panel::set_axis_font(void* param_1, long param_2, long param_3) {
    /* TODO: Stub */
//                              void __thiscall set_axis_font(Time_Line_Panel * this, void * param_1
//              void              <VOID>         <RETURN>
//              Time_Line_Pane    ECX:4 (auto)   this
//              void *            Stack[0x4]:4   param_1                   XREF[1]:     0051f0a0(R)
//              long              Stack[0x8]:4   param_2                   XREF[1]:     0051f0a4(R)
//              long              Stack[0xc]:4   param_3                   XREF[1]:     0051f0ae(R)
//                               ?set_axis_font@Time_Line_Panel@@QAEXPAXJJ@Z                  XREF[1]:     setup:0051ea51(c)
//                               Time_Line_Panel::set_axis_font
//                              tpnl_tml.cpp:394 (4)
//         0051f0a0     MOV        EAX,dword ptr [ESP + param_1]
//                              tpnl_tml.cpp:396 (10)
//         0051f0a4     MOV        EDX,dword ptr [ESP + param_2]
//         0051f0a8     MOV        dword ptr [ECX + this->axis_font],EAX
//                              tpnl_tml.cpp:397 (10)
//         0051f0ae     MOV        EAX,dword ptr [ESP + param_3]
//         0051f0b2     MOV        dword ptr [ECX + this->axis_font_wid],EDX
//                              tpnl_tml.cpp:398 (13)
//         0051f0b8     MOV        EDX,dword ptr [this->_padding_]
//         0051f0ba     PUSH       0x1
//         0051f0bc     MOV        dword ptr [ECX + this->axis_font_hgt],EAX
//         0051f0c2     CALL       dword ptr [EDX + 0x20]
//                              tpnl_tml.cpp:399 (3)
//         0051f0c5     RET        0xc
//         0051f0c8     ??         90h
//         0051f0c9     NOP
//         0051f0ca     NOP
//         0051f0cb     NOP
//         0051f0cc     NOP
//         0051f0cd     NOP
//         0051f0ce     NOP
//         0051f0cf     NOP
    return;
}

void Time_Line_Panel::set_body_font(void* param_1, long param_2, long param_3) {
    /* TODO: Stub */
//                              void __thiscall set_body_font(Time_Line_Panel * this, void * param_1
//              void              <VOID>         <RETURN>
//              Time_Line_Pane    ECX:4 (auto)   this
//              void *            Stack[0x4]:4   param_1                   XREF[1]:     0051f0d0(R)
//              long              Stack[0x8]:4   param_2                   XREF[1]:     0051f0d4(R)
//              long              Stack[0xc]:4   param_3                   XREF[1]:     0051f0de(R)
//                               ?set_body_font@Time_Line_Panel@@QAEXPAXJJ@Z                  XREF[1]:     setup:0051ea67(c)
//                               Time_Line_Panel::set_body_font
//                              tpnl_tml.cpp:407 (4)
//         0051f0d0     MOV        EAX,dword ptr [ESP + param_1]
//                              tpnl_tml.cpp:409 (10)
//         0051f0d4     MOV        EDX,dword ptr [ESP + param_2]
//         0051f0d8     MOV        dword ptr [ECX + this->body_font],EAX
//                              tpnl_tml.cpp:410 (10)
//         0051f0de     MOV        EAX,dword ptr [ESP + param_3]
//         0051f0e2     MOV        dword ptr [ECX + this->body_font_wid],EDX
//                              tpnl_tml.cpp:411 (13)
//         0051f0e8     MOV        EDX,dword ptr [this->_padding_]
//         0051f0ea     PUSH       0x1
//         0051f0ec     MOV        dword ptr [ECX + this->body_font_hgt],EAX
//         0051f0f2     CALL       dword ptr [EDX + 0x20]
//                              tpnl_tml.cpp:412 (3)
//         0051f0f5     RET        0xc
//         0051f0f8     ??         90h
//         0051f0f9     NOP
//         0051f0fa     NOP
//         0051f0fb     NOP
//         0051f0fc     NOP
//         0051f0fd     NOP
//         0051f0fe     NOP
//         0051f0ff     NOP
    return;
}

void Time_Line_Panel::set_back_color(int param_1, uchar param_2) {
    /* TODO: Stub */
//                              void __thiscall set_back_color(Time_Line_Panel * this, int param_1,
//              void              <VOID>         <RETURN>
//              Time_Line_Pane    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     0051f100(R)
//              uchar             Stack[0x8]:1   param_2                   XREF[1]:     0051f104(R)
//                               ?set_back_color@Time_Line_Panel@@QAEXHE@Z                    XREF[1]:     setup:0051eaa2(c)
//                               Time_Line_Panel::set_back_color
//                              tpnl_tml.cpp:419 (4)
//         0051f100     MOV        EAX,dword ptr [ESP + param_1]
//                              tpnl_tml.cpp:421 (16)
//         0051f104     MOV        DL,byte ptr [ESP + param_2]
//         0051f108     MOV        dword ptr [ECX + this->fill_back],EAX
//         0051f10e     MOV        byte ptr [ECX + this->back_color],DL
//                              tpnl_tml.cpp:422 (3)
//         0051f114     RET        0x8
//         0051f117     ??         90h
//         0051f118     NOP
//         0051f119     NOP
//         0051f11a     NOP
//         0051f11b     NOP
//         0051f11c     NOP
//         0051f11d     NOP
//         0051f11e     NOP
//         0051f11f     NOP
    return;
}

void Time_Line_Panel::draw_border() {
    /* TODO: Stub */
//                              void __thiscall draw_border(Time_Line_Panel * this)
//              void              <VOID>         <RETURN>
//              Time_Line_Pane    ECX:4 (auto)   this
//                               ?draw_border@Time_Line_Panel@@QAEXXZ                         XREF[1]:     draw:0051fa67(c)
//                               Time_Line_Panel::draw_border
//                              tpnl_tml.cpp:429 (3)
//         0051f120     PUSH       ESI
//         0051f121     MOV        ESI,this
//                              tpnl_tml.cpp:430 (14)
//         0051f123     MOV        EAX,dword ptr [ESI + 0x4c8]
//         0051f129     TEST       EAX,EAX
//         0051f12b     JZ         LAB_0051f2e3
//                              tpnl_tml.cpp:432 (23)
//         0051f131     MOV        this,dword ptr [ESI + 0x20]
//         0051f134     PUSH       0x1
//         0051f136     PUSH       s_tpnl_tml::draw_border                          = "tpnl_tml::draw_border"
//         0051f13b     CALL       TDrawArea::Lock                                  uchar * Lock(TDrawArea * this, char * param_1
//         0051f140     TEST       EAX,EAX
//         0051f142     JZ         switchD_0051f158::default
//                              tpnl_tml.cpp:434 (23)
//         0051f148     MOV        EAX,dword ptr [ESI + 0x4c8]
//         0051f14e     DEC        EAX
//         0051f14f     CMP        EAX,0x6
//         0051f152     JA         switchD_0051f158::default
//                               switchD_0051f158::switchD
//         0051f158     JMP        dword ptr [EAX*0x4 + switchD_0051f158::switchd   = 0051f15f
//                               switchD_0051f158::caseD_1                                    XREF[2]:     0051f158(j), 0051f2e8(*)
//                              tpnl_tml.cpp:437 (39)
//         0051f15f     MOV        DL,byte ptr [ESI + 0x4c0]
//         0051f165     MOV        EAX,dword ptr [ESI + 0x10]
//         0051f168     MOV        this,dword ptr [ESI + 0xc]
//         0051f16b     PUSH       EDX
//         0051f16c     MOV        EDX,dword ptr [ESI + 0x18]
//         0051f16f     LEA        EDX,[EDX + EAX*0x1 + -0x1]
//         0051f173     PUSH       EDX
//         0051f174     MOV        EDX,dword ptr [ESI + 0x14]
//         0051f177     LEA        EDX,[EDX + this->_padding_*0x1 + -0x1]
//         0051f17b     PUSH       EDX
//         0051f17c     PUSH       EAX
//         0051f17d     PUSH       this
//         0051f17e     MOV        this,dword ptr [ESI + 0x20]
//         0051f181     CALL       TDrawArea::DrawRect                              void DrawRect(TDrawArea * this, long param_1,
//                              tpnl_tml.cpp:465 (13)
//         0051f186     MOV        this,dword ptr [ESI + 0x20]
//         0051f189     PUSH       s_tpnl_tml::draw_border                          = "tpnl_tml::draw_border"
//         0051f18e     CALL       TDrawArea::Unlock                                void Unlock(TDrawArea * this, char * param_1)
//                              tpnl_tml.cpp:467 (2)
//         0051f193     POP        ESI
//         0051f194     RET
//                               switchD_0051f158::caseD_2                                    XREF[2]:     0051f158(j), 0051f2ec(*)
//                              tpnl_tml.cpp:441 (19)
//         0051f195     MOV        DL,byte ptr [ESI + 0x4cc]
//         0051f19b     MOV        EAX,dword ptr [ESI + 0x10]
//         0051f19e     MOV        this,dword ptr [ESI + 0xc]
//         0051f1a1     PUSH       EDX
//         0051f1a2     MOV        DL,byte ptr [ESI + 0x4d1]
//                              tpnl_tml.cpp:442 (2)
//         0051f1a8     JMP        LAB_0051f217
//                               switchD_0051f158::caseD_3                                    XREF[2]:     0051f158(j), 0051f2f0(*)
//                              tpnl_tml.cpp:445 (33)
//         0051f1aa     MOV        DL,byte ptr [ESI + 0x4cc]
//         0051f1b0     MOV        EAX,dword ptr [ESI + 0x10]
//         0051f1b3     MOV        this,dword ptr [ESI + 0xc]
//         0051f1b6     PUSH       EDX
//         0051f1b7     MOV        DL,byte ptr [ESI + 0x4cd]
//         0051f1bd     PUSH       EDX
//         0051f1be     MOV        DL,byte ptr [ESI + 0x4d0]
//         0051f1c4     PUSH       EDX
//         0051f1c5     MOV        DL,byte ptr [ESI + 0x4d1]
//                              tpnl_tml.cpp:446 (5)
//         0051f1cb     JMP        LAB_0051f262
//                               switchD_0051f158::caseD_4                                    XREF[2]:     0051f158(j), 0051f2f4(*)
//                              tpnl_tml.cpp:449 (47)
//         0051f1d0     MOV        DL,byte ptr [ESI + 0x4cc]
//         0051f1d6     MOV        EAX,dword ptr [ESI + 0x10]
//         0051f1d9     PUSH       EDX
//         0051f1da     MOV        DL,byte ptr [ESI + 0x4cd]
//         0051f1e0     PUSH       EDX
//         0051f1e1     MOV        DL,byte ptr [ESI + 0x4ce]
//         0051f1e7     MOV        this,dword ptr [ESI + 0xc]
//         0051f1ea     PUSH       EDX
//         0051f1eb     MOV        DL,byte ptr [ESI + 0x4cf]
//         0051f1f1     PUSH       EDX
//         0051f1f2     MOV        DL,byte ptr [ESI + 0x4d0]
//         0051f1f8     PUSH       EDX
//         0051f1f9     MOV        DL,byte ptr [ESI + 0x4d1]
//                              tpnl_tml.cpp:450 (5)
//         0051f1ff     JMP        LAB_0051f2bb
//                               switchD_0051f158::caseD_5                                    XREF[2]:     0051f158(j), 0051f2f8(*)
//                              tpnl_tml.cpp:453 (46)
//         0051f204     MOV        DL,byte ptr [ESI + 0x4d1]
//         0051f20a     MOV        EAX,dword ptr [ESI + 0x10]
//         0051f20d     MOV        this,dword ptr [ESI + 0xc]
//         0051f210     PUSH       EDX
//         0051f211     MOV        DL,byte ptr [ESI + 0x4cc]
//                               LAB_0051f217                                                 XREF[1]:     0051f1a8(j)
//         0051f217     PUSH       EDX
//         0051f218     MOV        EDX,dword ptr [ESI + 0x18]
//         0051f21b     LEA        EDX,[EDX + EAX*0x1 + -0x1]
//         0051f21f     PUSH       EDX
//         0051f220     MOV        EDX,dword ptr [ESI + 0x14]
//         0051f223     LEA        EDX,[EDX + this->_padding_*0x1 + -0x1]
//         0051f227     PUSH       EDX
//         0051f228     PUSH       EAX
//         0051f229     PUSH       this
//         0051f22a     MOV        this,dword ptr [ESI + 0x20]
//         0051f22d     CALL       TDrawArea::DrawBevel                             void DrawBevel(TDrawArea * this, long param_1
//                              tpnl_tml.cpp:465 (13)
//         0051f232     MOV        this,dword ptr [ESI + 0x20]
//         0051f235     PUSH       s_tpnl_tml::draw_border                          = "tpnl_tml::draw_border"
//         0051f23a     CALL       TDrawArea::Unlock                                void Unlock(TDrawArea * this, char * param_1)
//                              tpnl_tml.cpp:467 (2)
//         0051f23f     POP        ESI
//         0051f240     RET
//                               switchD_0051f158::caseD_6                                    XREF[2]:     0051f158(j), 0051f2fc(*)
//                              tpnl_tml.cpp:457 (60)
//         0051f241     MOV        DL,byte ptr [ESI + 0x4d1]
//         0051f247     MOV        EAX,dword ptr [ESI + 0x10]
//         0051f24a     MOV        this,dword ptr [ESI + 0xc]
//         0051f24d     PUSH       EDX
//         0051f24e     MOV        DL,byte ptr [ESI + 0x4d0]
//         0051f254     PUSH       EDX
//         0051f255     MOV        DL,byte ptr [ESI + 0x4cd]
//         0051f25b     PUSH       EDX
//         0051f25c     MOV        DL,byte ptr [ESI + 0x4cc]
//                               LAB_0051f262                                                 XREF[1]:     0051f1cb(j)
//         0051f262     PUSH       EDX
//         0051f263     MOV        EDX,dword ptr [ESI + 0x18]
//         0051f266     LEA        EDX,[EDX + EAX*0x1 + -0x1]
//         0051f26a     PUSH       EDX
//         0051f26b     MOV        EDX,dword ptr [ESI + 0x14]
//         0051f26e     LEA        EDX,[EDX + this->_padding_*0x1 + -0x1]
//         0051f272     PUSH       EDX
//         0051f273     PUSH       EAX
//         0051f274     PUSH       this
//         0051f275     MOV        this,dword ptr [ESI + 0x20]
//         0051f278     CALL       TDrawArea::DrawBevel2                            void DrawBevel2(TDrawArea * this, long param_
//                              tpnl_tml.cpp:465 (13)
//         0051f27d     MOV        this,dword ptr [ESI + 0x20]
//         0051f280     PUSH       s_tpnl_tml::draw_border                          = "tpnl_tml::draw_border"
//         0051f285     CALL       TDrawArea::Unlock                                void Unlock(TDrawArea * this, char * param_1)
//                              tpnl_tml.cpp:467 (2)
//         0051f28a     POP        ESI
//         0051f28b     RET
//                               switchD_0051f158::caseD_7                                    XREF[2]:     0051f158(j), 0051f300(*)
//                              tpnl_tml.cpp:461 (74)
//         0051f28c     MOV        DL,byte ptr [ESI + 0x4d1]
//         0051f292     MOV        EAX,dword ptr [ESI + 0x10]
//         0051f295     PUSH       EDX
//         0051f296     MOV        DL,byte ptr [ESI + 0x4d0]
//         0051f29c     PUSH       EDX
//         0051f29d     MOV        DL,byte ptr [ESI + 0x4cf]
//         0051f2a3     MOV        this,dword ptr [ESI + 0xc]
//         0051f2a6     PUSH       EDX
//         0051f2a7     MOV        DL,byte ptr [ESI + 0x4ce]
//         0051f2ad     PUSH       EDX
//         0051f2ae     MOV        DL,byte ptr [ESI + 0x4cd]
//         0051f2b4     PUSH       EDX
//         0051f2b5     MOV        DL,byte ptr [ESI + 0x4cc]
//                               LAB_0051f2bb                                                 XREF[1]:     0051f1ff(j)
//         0051f2bb     PUSH       EDX
//         0051f2bc     MOV        EDX,dword ptr [ESI + 0x18]
//         0051f2bf     LEA        EDX,[EDX + EAX*0x1 + -0x1]
//         0051f2c3     PUSH       EDX
//         0051f2c4     MOV        EDX,dword ptr [ESI + 0x14]
//         0051f2c7     LEA        EDX,[EDX + this->_padding_*0x1 + -0x1]
//         0051f2cb     PUSH       EDX
//         0051f2cc     PUSH       EAX
//         0051f2cd     PUSH       this
//         0051f2ce     MOV        this,dword ptr [ESI + 0x20]
//         0051f2d1     CALL       TDrawArea::DrawBevel3                            void DrawBevel3(TDrawArea * this, long param_
//                               switchD_0051f158::default                                    XREF[2]:     0051f142(j), 0051f152(j)
//                              tpnl_tml.cpp:465 (13)
//         0051f2d6     MOV        this,dword ptr [ESI + 0x20]
//         0051f2d9     PUSH       s_tpnl_tml::draw_border                          = "tpnl_tml::draw_border"
//         0051f2de     CALL       TDrawArea::Unlock                                void Unlock(TDrawArea * this, char * param_1)
//                               LAB_0051f2e3                                                 XREF[1]:     0051f12b(j)
//                              tpnl_tml.cpp:467 (33)
//         0051f2e3     POP        ESI
//         0051f2e4     RET
    return;
}

void Time_Line_Panel::init_timeline() {
    /* TODO: Stub */
//                              void __thiscall init_timeline(Time_Line_Panel * this)
//              void              <VOID>         <RETURN>
//              Time_Line_Pane    ECX:4 (auto)   this
//              undefined4        Stack[-0x4]:4  local_4                   XREF[6]:     0051f3b0(W), 0051f3b4(R), 0051f3e1(W), 0051f3ec(R),
//                                                                                     0051f4b7(W), 0051f4bb(R)
//              undefined4        Stack[-0x8]:4  local_8                   XREF[2]:     0051f385(W), 0051f3ac(R)
//              long              Stack[-0xc]:4  usable_X
//                               ?init_timeline@Time_Line_Panel@@QAEXXZ                       XREF[1]:     create_timeline:0051e9a8(c)
//                               Time_Line_Panel::init_timeline
//                              tpnl_tml.cpp:476 (7)
//         0051f310     SUB        ESP,0x8
//         0051f313     PUSH       EBP
//         0051f314     PUSH       ESI
//         0051f315     MOV        ESI,this
//                              tpnl_tml.cpp:483 (9)
//         0051f317     XOR        EBP,EBP
//         0051f319     PUSH       EDI
//         0051f31a     MOV        dword ptr [ESI + 0x514],EBP
//                              tpnl_tml.cpp:484 (20)
//         0051f320     MOV        EAX,[rge_base_game]                              = 00000000
//         0051f325     MOV        EAX,dword ptr [EAX + 0x3f4]
//         0051f32b     MOVSX      this,word ptr [EAX + 0x3c]
//         0051f32f     DEC        this
//         0051f330     TEST       this,this
//         0051f332     JLE        LAB_0051f371
//                              tpnl_tml.cpp:483 (5)
//         0051f334     MOV        EDI,0x4
//                               LAB_0051f339                                                 XREF[1]:     0051f36f(j)
//                              tpnl_tml.cpp:486 (17)
//         0051f339     MOV        EDX,dword ptr [EAX + 0x40]
//         0051f33c     MOV        EAX,dword ptr [EDX + EDI*0x1]
//         0051f33f     MOV        this,dword ptr [EAX + 0x83c]
//         0051f345     CALL       TRIBE_History_Info::get_history_entry_num        long get_history_entry_num(TRIBE_History_Info
//                              tpnl_tml.cpp:487 (8)
//         0051f34a     CMP        dword ptr [ESI + 0x514],EAX
//         0051f350     JGE        LAB_0051f358
//                              tpnl_tml.cpp:488 (6)
//         0051f352     MOV        dword ptr [ESI + 0x514],EAX
//                               LAB_0051f358                                                 XREF[1]:     0051f350(j)
//                              tpnl_tml.cpp:484 (25)
//         0051f358     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0051f35e     INC        EBP
//         0051f35f     ADD        EDI,0x4
//         0051f362     MOV        EAX,dword ptr [ECX + this->_padding_]
//         0051f368     MOVSX      EDX,word ptr [EAX + 0x3c]
//         0051f36c     DEC        EDX
//         0051f36d     CMP        EBP,EDX
//         0051f36f     JL         LAB_0051f339
//                               LAB_0051f371                                                 XREF[1]:     0051f332(j)
//                              tpnl_tml.cpp:492 (9)
//         0051f371     MOV        this,ESI
//         0051f373     CALL       TPanel::width                                    long width(TPanel * this)
//         0051f378     MOV        this,EAX
//                              tpnl_tml.cpp:493 (17)
//         0051f37a     MOV        EAX,dword ptr [ESI + 0x514]
//         0051f380     SUB        this,0x31
//         0051f383     TEST       EAX,EAX
//         0051f385     MOV        dword ptr [ESP + local_8],this
//         0051f389     JNZ        LAB_0051f39c
//                              tpnl_tml.cpp:495 (10)
//         0051f38b     MOV        dword ptr [ESI + 0x514],0x1
//                              tpnl_tml.cpp:496 (7)
//         0051f395     MOV        byte ptr [ESI + 0x51c],0x0
//                               LAB_0051f39c                                                 XREF[1]:     0051f389(j)
//                              tpnl_tml.cpp:498 (6)
//         0051f39c     MOV        EDX,dword ptr [ESI + 0x514]
//                              tpnl_tml.cpp:499 (24)
//         0051f3a2     MOV        dword ptr [ESI + 0x504],0x0
//         0051f3ac     FILD       dword ptr [ESP + local_8]
//         0051f3b0     MOV        dword ptr [ESP + local_4],EDX
//         0051f3b4     FILD       dword ptr [ESP + local_4]
//         0051f3b8     FDIVR      ST0,ST1
//                              tpnl_tml.cpp:501 (19)
//         0051f3ba     FCOM       float ptr [DAT_005770b0]                         = align(2)
//         0051f3c0     FSTP       float ptr [ESI + 0x4fc]
//         0051f3c6     FNSTSW     AX
//         0051f3c8     TEST       AH,0x1
//         0051f3cb     JZ         LAB_0051f402
//                              tpnl_tml.cpp:507 (31)
//         0051f3cd     MOV        EAX,EDX
//         0051f3cf     MOV        dword ptr [ESI + 0x4fc],0x3f800000
//         0051f3d9     SUB        EAX,this
//         0051f3db     MOV        dword ptr [ESI + 0x510],this
//         0051f3e1     MOV        dword ptr [ESP + local_4],EAX
//         0051f3e5     MOV        byte ptr [ESI + 0x50c],0x1
//                              tpnl_tml.cpp:508 (20)
//         0051f3ec     FILD       dword ptr [ESP + local_4]
//         0051f3f0     MOV        dword ptr [ESI + 0x508],EAX
//         0051f3f6     FDIVR      ST0,ST1
//         0051f3f8     FSTP       float ptr [ESI + 0x504]
//         0051f3fe     FSTP       ST0
//                              tpnl_tml.cpp:510 (2)
//         0051f400     JMP        LAB_0051f40a
//                               LAB_0051f402                                                 XREF[1]:     0051f3cb(j)
//                              tpnl_tml.cpp:501 (2)
//         0051f402     FSTP       ST0
//                              tpnl_tml.cpp:511 (6)
//         0051f404     MOV        dword ptr [ESI + 0x510],EDX
//                               LAB_0051f40a                                                 XREF[1]:     0051f400(j)
//                              tpnl_tml.cpp:514 (20)
//         0051f40a     FILD       dword ptr [ESI + 0x510]
//         0051f410     FMUL       float ptr [ESI + 0x4fc]
//         0051f416     CALL       __ftol                                           undefined __ftol()
//         0051f41b     ADD        EAX,0x4
//                              tpnl_tml.cpp:520 (29)
//         0051f41e     MOV        this,ESI
//         0051f420     MOV        dword ptr [ESI + 0x4f4],EAX
//         0051f426     CALL       TPanel::height                                   long height(TPanel * this)
//         0051f42b     MOV        this,dword ptr [ESI + 0x480]
//         0051f431     MOV        EDX,0xffffffe6
//         0051f436     SHL        this,0x2
//         0051f439     SUB        EDX,this
//                              tpnl_tml.cpp:523 (18)
//         0051f43b     MOV        this,ESI
//         0051f43d     ADD        EAX,EDX
//         0051f43f     MOV        dword ptr [ESI + 0x4f8],EAX
//         0051f445     CALL       TPanel::xPosition                                long xPosition(TPanel * this)
//         0051f44a     ADD        EAX,0x1b
//                              tpnl_tml.cpp:524 (19)
//         0051f44d     MOV        this,ESI
//         0051f44f     MOV        dword ptr [ESI + 0x4dc],EAX
//         0051f455     CALL       TPanel::yPosition                                long yPosition(TPanel * this)
//         0051f45a     MOV        this,dword ptr [ESI + 0x480]
//                              tpnl_tml.cpp:525 (16)
//         0051f460     MOV        EDX,dword ptr [ESI + 0x4dc]
//         0051f466     MOV        dword ptr [ESI + 0x4e4],EDX
//         0051f46c     LEA        EAX,[EAX + this->_padding_*0x2 + 0xf]
//                              tpnl_tml.cpp:529 (42)
//         0051f470     MOV        this,dword ptr [ESI + 0x4f4]
//         0051f476     MOV        dword ptr [ESI + 0x4e0],EAX
//         0051f47c     MOV        dword ptr [ESI + 0x4e8],EAX
//         0051f482     MOV        EAX,dword ptr [ESI + 0x4f8]
//         0051f488     SUB        this,0x2
//         0051f48b     SUB        EAX,0x3
//         0051f48e     MOV        dword ptr [ESI + 0x4ec],this
//         0051f494     MOV        dword ptr [ESI + 0x4f0],EAX
//                              tpnl_tml.cpp:532 (11)
//         0051f49a     MOV        EAX,dword ptr [ESI + 0x510]
//         0051f4a0     CMP        EAX,0xc
//         0051f4a3     JGE        LAB_0051f4b6
//                              tpnl_tml.cpp:533 (10)
//         0051f4a5     MOV        dword ptr [ESI + 0x500],0x1
//                              tpnl_tml.cpp:538 (7)
//         0051f4af     POP        EDI
//         0051f4b0     POP        ESI
//         0051f4b1     POP        EBP
//         0051f4b2     ADD        ESP,0x8
//         0051f4b5     RET
//                               LAB_0051f4b6                                                 XREF[1]:     0051f4a3(j)
//                              tpnl_tml.cpp:536 (26)
//         0051f4b6     DEC        EAX
//         0051f4b7     MOV        dword ptr [ESP + local_4],EAX
//         0051f4bb     FILD       dword ptr [ESP + local_4]
//         0051f4bf     FMUL       float ptr [DAT_005770b4]                         = ABh
//         0051f4c5     CALL       __ftol                                           undefined __ftol()
//         0051f4ca     MOV        dword ptr [ESI + 0x500],EAX
//                              tpnl_tml.cpp:538 (7)
//         0051f4d0     POP        EDI
//         0051f4d1     POP        ESI
//         0051f4d2     POP        EBP
//         0051f4d3     ADD        ESP,0x8
//         0051f4d6     RET
//         0051f4d7     ??         90h
//         0051f4d8     NOP
//         0051f4d9     NOP
//         0051f4da     NOP
//         0051f4db     NOP
//         0051f4dc     NOP
//         0051f4dd     NOP
//         0051f4de     NOP
//         0051f4df     NOP
    return;
}

void Time_Line_Panel::add_pop_total_special_event(long param_1, long param_2, long param_3, int param_4) {
    /* TODO: Stub */
//                              void __thiscall add_pop_total_special_event(Time_Line_Panel * this,
//              void              <VOID>         <RETURN>
//              Time_Line_Pane    ECX:4 (auto)   this
//              long              Stack[0x4]:4   param_1                   XREF[1]:     0051f4ef(R)
//              long              Stack[0x8]:4   param_2                   XREF[1]:     0051f4fe(R)
//              long              Stack[0xc]:4   param_3                   XREF[1]:     0051f4f3(R)
//              int               Stack[0x10]:4  param_4                   XREF[1]:     0051f532(R)
//                               ?add_pop_total_special_event@Time_Line_Panel@@QAEXJJJH@Z     XREF[1]:     draw_timeline:00520722(c)
//                               Time_Line_Panel::add_pop_total_special_event
//                              tpnl_tml.cpp:544 (1)
//         0051f4e0     PUSH       ESI
//                              tpnl_tml.cpp:548 (14)
//         0051f4e1     PUSH       0xb0
//         0051f4e6     MOV        ESI,this
//         0051f4e8     PUSH       0x1
//         0051f4ea     CALL       calloc                                           undefined calloc()
//                              tpnl_tml.cpp:549 (4)
//         0051f4ef     MOV        this,dword ptr [ESP + param_1]
//                              tpnl_tml.cpp:550 (6)
//         0051f4f3     MOV        EDX,dword ptr [ESP + param_3]
//         0051f4f7     MOV        dword ptr [EAX],this
//                              tpnl_tml.cpp:551 (5)
//         0051f4f9     XOR        this,this
//         0051f4fb     MOV        dword ptr [EAX + 0x4],EDX
//                              tpnl_tml.cpp:556 (16)
//         0051f4fe     MOV        EDX,dword ptr [ESP + param_2]
//         0051f502     MOV        dword ptr [EAX + 0x8],this
//         0051f505     MOV        dword ptr [EAX + 0xc],this
//         0051f508     MOV        byte ptr [EAX + 0x10],this
//         0051f50b     MOV        byte ptr [EAX + 0x11],this
//                              tpnl_tml.cpp:558 (3)
//         0051f50e     MOV        dword ptr [EAX + 0x18],this
//                              tpnl_tml.cpp:559 (3)
//         0051f511     MOV        dword ptr [EAX + 0x1c],this
//                              tpnl_tml.cpp:560 (3)
//         0051f514     MOV        dword ptr [EAX + 0x20],this
//                              tpnl_tml.cpp:561 (3)
//         0051f517     MOV        dword ptr [EAX + 0x24],this
//                              tpnl_tml.cpp:562 (3)
//         0051f51a     MOV        dword ptr [EAX + 0x28],this
//                              tpnl_tml.cpp:563 (3)
//         0051f51d     MOV        dword ptr [EAX + 0x2c],this
//                              tpnl_tml.cpp:564 (3)
//         0051f520     MOV        dword ptr [EAX + 0x30],this
//                              tpnl_tml.cpp:565 (3)
//         0051f523     MOV        dword ptr [EAX + 0x34],this
//                              tpnl_tml.cpp:566 (3)
//         0051f526     MOV        dword ptr [EAX + 0x38],this
//                              tpnl_tml.cpp:567 (3)
//         0051f529     MOV        byte ptr [EAX + 0x3c],this
//                              tpnl_tml.cpp:568 (3)
//         0051f52c     MOV        dword ptr [EAX + 0x70],this
//                              tpnl_tml.cpp:569 (3)
//         0051f52f     MOV        byte ptr [EAX + 0x74],this
//                              tpnl_tml.cpp:571 (17)
//         0051f532     MOV        this,dword ptr [ESP + param_4]
//         0051f536     MOV        byte ptr [EAX + 0x12],0x3
//         0051f53a     MOV        dword ptr [EAX + 0x14],EDX
//         0051f53d     MOV        dword ptr [EAX + 0xa8],this
//                              tpnl_tml.cpp:572 (15)
//         0051f543     MOV        EDX,dword ptr [ESI + 0x518]
//         0051f549     ADD        ESP,0x8
//         0051f54c     MOV        dword ptr [EAX + 0xac],EDX
//                              tpnl_tml.cpp:573 (6)
//         0051f552     MOV        dword ptr [ESI + 0x518],EAX
//                              tpnl_tml.cpp:575 (4)
//         0051f558     POP        ESI
//         0051f559     RET        0x10
//         0051f55c     ??         90h
//         0051f55d     NOP
//         0051f55e     NOP
//         0051f55f     NOP
    return;
}

void Time_Line_Panel::record_special_event(uchar param_1, TRIBE_History_Info* param_2, uchar param_3, long param_4, long param_5, long param_6, long param_7) {
    /* TODO: Stub */
//                              void __thiscall record_special_event(Time_Line_Panel * this, uchar p
//              void              <VOID>         <RETURN>
//              Time_Line_Pane    ECX:4 (auto)   this
//              uchar             Stack[0x4]:1   param_1                   XREF[1]:     0051f599(R)
//              TRIBE_History_    Stack[0x8]:4   param_2                   XREF[1]:     0051f56d(R)
//              uchar             Stack[0xc]:1   param_3                   XREF[1]:     0051f5a0(R)
//              long              Stack[0x10]:4  param_4                   XREF[3]:     0051f562(R), 0051f566(*), 0051f5af(R)
//              long              Stack[0x14]:4  param_5                   XREF[1]:     0051f587(R)
//              long              Stack[0x18]:4  param_6                   XREF[1]:     0051f58b(R)
//              long              Stack[0x1c]:4  param_7                   XREF[1]:     0051f592(R)
//                               ?record_special_event@Time_Line_Panel@@QAEXEPAVTRIBE_Histor  XREF[1]:     draw_timeline:00520a24(c)
//                               Time_Line_Panel::record_special_event
//                              tpnl_tml.cpp:582 (2)
//         0051f560     PUSH       ESI
//         0051f561     PUSH       EDI
//                              tpnl_tml.cpp:586 (25)
//         0051f562     MOV        EDI,dword ptr [ESP + param_4]
//         0051f566     LEA        EAX=>param_4,[ESP + 0x18]
//         0051f56a     MOV        ESI,this
//         0051f56c     PUSH       EAX
//         0051f56d     MOV        this,dword ptr [ESP + param_2]
//         0051f571     PUSH       EDI
//         0051f572     CALL       TRIBE_History_Info::get_history_event            uchar get_history_event(TRIBE_History_Info *
//         0051f577     TEST       AL,AL
//         0051f579     JZ         LAB_0051f5f7
//                              tpnl_tml.cpp:589 (12)
//         0051f57b     PUSH       0xb0
//         0051f580     PUSH       0x1
//         0051f582     CALL       calloc                                           undefined calloc()
//                              tpnl_tml.cpp:591 (4)
//         0051f587     MOV        this,dword ptr [ESP + param_5]
//                              tpnl_tml.cpp:592 (7)
//         0051f58b     MOV        EDX,dword ptr [ESP + param_6]
//         0051f58f     MOV        dword ptr [EAX + 0x4],this
//                              tpnl_tml.cpp:593 (7)
//         0051f592     MOV        this,dword ptr [ESP + param_7]
//         0051f596     MOV        dword ptr [EAX + 0x8],EDX
//                              tpnl_tml.cpp:594 (7)
//         0051f599     MOV        DL,byte ptr [ESP + param_1]
//         0051f59d     MOV        dword ptr [EAX + 0xc],this
//                              tpnl_tml.cpp:595 (15)
//         0051f5a0     MOV        this,byte ptr [ESP + param_3]
//         0051f5a4     ADD        ESP,0x8
//         0051f5a7     MOV        dword ptr [EAX],EDI
//         0051f5a9     MOV        byte ptr [EAX + 0x10],DL
//         0051f5ac     MOV        byte ptr [EAX + 0x11],this
//                              tpnl_tml.cpp:596 (4)
//         0051f5af     MOV        DL,byte ptr [ESP + param_4]
//                              tpnl_tml.cpp:598 (8)
//         0051f5b3     XOR        this,this
//         0051f5b5     MOV        byte ptr [EAX + 0x12],DL
//         0051f5b8     MOV        dword ptr [EAX + 0x14],this
//                              tpnl_tml.cpp:599 (3)
//         0051f5bb     MOV        dword ptr [EAX + 0x18],this
//                              tpnl_tml.cpp:600 (3)
//         0051f5be     MOV        dword ptr [EAX + 0x1c],this
//                              tpnl_tml.cpp:601 (3)
//         0051f5c1     MOV        dword ptr [EAX + 0x20],this
//                              tpnl_tml.cpp:602 (3)
//         0051f5c4     MOV        dword ptr [EAX + 0x24],this
//                              tpnl_tml.cpp:603 (3)
//         0051f5c7     MOV        dword ptr [EAX + 0x28],this
//                              tpnl_tml.cpp:604 (3)
//         0051f5ca     MOV        dword ptr [EAX + 0x2c],this
//                              tpnl_tml.cpp:605 (3)
//         0051f5cd     MOV        dword ptr [EAX + 0x30],this
//                              tpnl_tml.cpp:606 (3)
//         0051f5d0     MOV        dword ptr [EAX + 0x34],this
//                              tpnl_tml.cpp:607 (3)
//         0051f5d3     MOV        dword ptr [EAX + 0x38],this
//                              tpnl_tml.cpp:608 (3)
//         0051f5d6     MOV        byte ptr [EAX + 0x3c],this
//                              tpnl_tml.cpp:609 (3)
//         0051f5d9     MOV        dword ptr [EAX + 0x70],this
//                              tpnl_tml.cpp:610 (3)
//         0051f5dc     MOV        byte ptr [EAX + 0x74],this
//                              tpnl_tml.cpp:612 (6)
//         0051f5df     MOV        dword ptr [EAX + 0xa8],this
//                              tpnl_tml.cpp:616 (12)
//         0051f5e5     MOV        this,dword ptr [ESI + 0x518]
//         0051f5eb     MOV        dword ptr [EAX + 0xac],this
//                              tpnl_tml.cpp:617 (6)
//         0051f5f1     MOV        dword ptr [ESI + 0x518],EAX
//                               LAB_0051f5f7                                                 XREF[1]:     0051f579(j)
//                              tpnl_tml.cpp:620 (5)
//         0051f5f7     POP        EDI
//         0051f5f8     POP        ESI
//         0051f5f9     RET        0x1c
//         0051f5fc     ??         90h
//         0051f5fd     NOP
//         0051f5fe     NOP
//         0051f5ff     NOP
    return;
}

int Time_Line_Panel::calculate_icon_location(Special_Events* param_1, short param_2, uchar param_3) {
    /* TODO: Stub */
//                              int __thiscall calculate_icon_location(Time_Line_Panel * this, Speci
//              int               EAX:4          <RETURN>
//              Time_Line_Pane    ECX:4 (auto)   this
//              Special_Events    Stack[0x4]:4   param_1                   XREF[3]:     0051f604(R), 0051f670(*), 0051f682(R)
//              short             Stack[0x8]:2   param_2                   XREF[5]:     0051f64a(R), 0051f8b4(W), 0051f8ce(R), 0051f945(W),
//                                                                                     0051f95f(R)
//              uchar             Stack[0xc]:1   param_3
//              undefined4        Stack[-0x4]:4  local_4                   XREF[4]:     0051f625(W), 0051f70f(W), 0051f9cc(R), 0051f9d8(R)
//              long              Stack[-0x8]:4  temp_start_x              XREF[7]:     0051f629(W), 0051f72c(W), 0051f90e(R), 0051f99f(R),
//                                                                                     0051f9c4(W), 0051f9c8(R), 0051f9e0(R)
//              long              Stack[-0xc]:4  temp_start_y              XREF[8]:     0051f62d(W), 0051f77e(W), 0051f78a(W), 0051f7df(W),
//                                                                                     0051f7eb(W), 0051f86b(W), 0051f9d0(W), 0051f9dc(R)
//              long              Stack[-0x10]:4 temp_start_txt_x1         XREF[11]:    0051f60f(W), 0051f633(W), 0051f640(W), 0051f658(W),
//                                                                                     0051f660(R), 0051f6a4(R), 0051f6bc(W), 0051f6e8(W),
//                                                                                     0051f6fc(W), 0051f704(R), 0051f9e7(R)
//              int               Stack[-0x14]:4 ret_val                   XREF[0,2]:   0051f66c(*), 0051f693(R)
//              short             Stack[-0x16]:2 height
//                               ?calculate_icon_location@Time_Line_Panel@@QAEHPAUSpecial_Ev  XREF[1]:     draw_icon:00520c76(c)
//                               Time_Line_Panel::calculate_icon_location
//                              tpnl_tml.cpp:627 (4)
//         0051f600     SUB        ESP,0x14
//         0051f603     PUSH       EBX
//                              tpnl_tml.cpp:641 (11)
//         0051f604     MOV        EBX,dword ptr [ESP + param_1]
//         0051f608     PUSH       EBP
//         0051f609     PUSH       ESI
//         0051f60a     PUSH       EDI
//         0051f60b     MOV        ESI,this
//         0051f60d     XOR        EDI,EDI
//                              tpnl_tml.cpp:642 (14)
//         0051f60f     MOV        dword ptr [ESP + temp_start_txt_x1],0x1
//         0051f617     MOV        dword ptr [EBX + 0xa8],EDI
//                              tpnl_tml.cpp:644 (22)
//         0051f61d     MOV        this,dword ptr [ESI + 0x4d4]
//         0051f623     CMP        this,EDI
//         0051f625     MOV        dword ptr [ESP + local_4],EDI
//         0051f629     MOV        dword ptr [ESP + temp_start_x],EDI
//         0051f62d     MOV        dword ptr [ESP + temp_start_y],EDI
//         0051f631     JNZ        LAB_0051f637
//                              tpnl_tml.cpp:645 (4)
//         0051f633     MOV        dword ptr [ESP + temp_start_txt_x1],EDI
//                               LAB_0051f637                                                 XREF[1]:     0051f631(j)
//                              tpnl_tml.cpp:647 (9)
//         0051f637     CALL       TShape::shape_count                              long shape_count(TShape * this)
//         0051f63c     TEST       EAX,EAX
//         0051f63e     JNZ        LAB_0051f644
//                              tpnl_tml.cpp:648 (4)
//         0051f640     MOV        dword ptr [ESP + temp_start_txt_x1],EDI
//                               LAB_0051f644                                                 XREF[1]:     0051f63e(j)
//                              tpnl_tml.cpp:650 (20)
//         0051f644     MOV        this,dword ptr [ESI + 0x4d4]
//         0051f64a     MOVSX      EBP,word ptr [ESP + param_2]
//         0051f64f     CALL       TShape::shape_count                              long shape_count(TShape * this)
//         0051f654     CMP        EAX,EBP
//         0051f656     JGE        LAB_0051f660
//                              tpnl_tml.cpp:651 (8)
//         0051f658     MOV        dword ptr [ESP + temp_start_txt_x1],0x0
//                               LAB_0051f660                                                 XREF[1]:     0051f656(j)
//                              tpnl_tml.cpp:654 (12)
//         0051f660     MOV        EAX,dword ptr [ESP + temp_start_txt_x1]
//         0051f664     TEST       EAX,EAX
//         0051f666     JZ         LAB_0051f730
//                              tpnl_tml.cpp:656 (22)
//         0051f66c     LEA        EAX=>ret_val+0x2,[ESP + 0x12]
//         0051f670     LEA        this=>param_1,[ESP + 0x28]
//         0051f674     PUSH       EAX
//         0051f675     PUSH       this
//         0051f676     MOV        this,dword ptr [ESI + 0x4d4]
//         0051f67c     PUSH       EBP
//         0051f67d     CALL       TShape::shape_bounds                             uchar shape_bounds(TShape * this, long param_
//                              tpnl_tml.cpp:657 (10)
//         0051f682     MOV        AX,word ptr [ESP + param_1]
//         0051f687     TEST       AX,AX
//         0051f68a     JLE        LAB_0051f693
//                              tpnl_tml.cpp:658 (7)
//         0051f68c     MOV        word ptr [ESI + 0x4d8],AX
//                               LAB_0051f693                                                 XREF[1]:     0051f68a(j)
//                              tpnl_tml.cpp:659 (10)
//         0051f693     MOV        AX,word ptr [ESP + ret_val+0x2]
//         0051f698     TEST       AX,AX
//         0051f69b     JLE        LAB_0051f6a4
//                              tpnl_tml.cpp:660 (7)
//         0051f69d     MOV        word ptr [ESI + 0x4da],AX
//                               LAB_0051f6a4                                                 XREF[1]:     0051f69b(j)
//                              tpnl_tml.cpp:664 (12)
//         0051f6a4     MOV        EAX,dword ptr [ESP + temp_start_txt_x1]
//         0051f6a8     TEST       EAX,EAX
//         0051f6aa     JZ         LAB_0051f730
//                              tpnl_tml.cpp:667 (12)
//         0051f6b0     MOVSX      EAX,word ptr [ESI + 0x4da]
//         0051f6b7     CMP        EAX,dword ptr [EBX + 0xc]
//         0051f6ba     JLE        LAB_0051f6c4
//                              tpnl_tml.cpp:668 (8)
//         0051f6bc     MOV        dword ptr [ESP + temp_start_txt_x1],0x0
//                               LAB_0051f6c4                                                 XREF[1]:     0051f6ba(j)
//                              tpnl_tml.cpp:670 (36)
//         0051f6c4     MOVSX      EAX,word ptr [ESI + 0x4d8]
//         0051f6cb     MOV        this,dword ptr [EBX + 0x4]
//         0051f6ce     MOV        EBP,dword ptr [ESI + 0x4ec]
//         0051f6d4     CDQ
//         0051f6d5     SUB        EAX,EDX
//         0051f6d7     MOV        EDX,dword ptr [ESI + 0x4dc]
//         0051f6dd     SAR        EAX,0x1
//         0051f6df     ADD        EBP,EDX
//         0051f6e1     LEA        EDX,[this->_padding_ + EAX*0x1]
//         0051f6e4     CMP        EDX,EBP
//         0051f6e6     JLE        LAB_0051f6f0
//                              tpnl_tml.cpp:671 (8)
//         0051f6e8     MOV        dword ptr [ESP + temp_start_txt_x1],0x0
//                               LAB_0051f6f0                                                 XREF[1]:     0051f6e6(j)
//                              tpnl_tml.cpp:672 (12)
//         0051f6f0     SUB        this,EAX
//         0051f6f2     MOV        EAX,dword ptr [ESI + 0x4dc]
//         0051f6f8     CMP        this,EAX
//         0051f6fa     JGE        LAB_0051f704
//                              tpnl_tml.cpp:673 (8)
//         0051f6fc     MOV        dword ptr [ESP + temp_start_txt_x1],0x0
//                               LAB_0051f704                                                 XREF[1]:     0051f6fa(j)
//                              tpnl_tml.cpp:674 (8)
//         0051f704     MOV        EAX,dword ptr [ESP + temp_start_txt_x1]
//         0051f708     TEST       EAX,EAX
//         0051f70a     JZ         LAB_0051f730
//                              tpnl_tml.cpp:682 (36)
//         0051f70c     MOV        EAX,dword ptr [EBX + 0xc]
//         0051f70f     MOV        dword ptr [ESP + local_4],this
//         0051f713     MOV        this,dword ptr [EBX + 0x8]
//         0051f716     CDQ
//         0051f717     SUB        EAX,EDX
//         0051f719     SAR        EAX,0x1
//         0051f71b     LEA        this,[EAX + this->_padding_*0x2]
//         0051f71e     MOVSX      EAX,word ptr [ESI + 0x4da]
//         0051f725     CDQ
//         0051f726     SUB        EAX,EDX
//         0051f728     SAR        EAX,0x1
//         0051f72a     SUB        this,EAX
//         0051f72c     MOV        dword ptr [ESP + temp_start_x],this
//                               LAB_0051f730                                                 XREF[3]:     0051f666(j), 0051f6aa(j),
//                                                                                                         0051f70a(j)
//                              tpnl_tml.cpp:687 (21)
//         0051f730     XOR        EAX,EAX
//         0051f732     MOV        AL,byte ptr [EBX + 0x12]
//         0051f735     CMP        EAX,0x8
//         0051f738     JA         switchD_0051f73e::caseD_3
//                               switchD_0051f73e::switchD
//         0051f73e     JMP        dword ptr [EAX*0x4 + switchD_0051f73e::switchd   = 0051f745
//                               switchD_0051f73e::caseD_0                                    XREF[2]:     0051f73e(j), 0051fa0c(*)
//                              tpnl_tml.cpp:694 (13)
//         0051f745     LEA        EDI,[EBX + 0x3c]
//         0051f748     OR         this,0xffffffff
//         0051f74b     XOR        EAX,EAX
//         0051f74d     SCASB.RE   ES:EDI
//         0051f74f     NOT        this
//         0051f751     DEC        this
//                              tpnl_tml.cpp:698 (38)
//         0051f752     MOV        EDI,dword ptr [EBX + 0x4]
//         0051f755     MOV        dword ptr [EBX + 0x38],this
//         0051f758     MOV        EAX,dword ptr [ESI + 0x488]
//         0051f75e     IMUL       EAX,this
//         0051f761     MOV        EDX,dword ptr [ESI + 0x4dc]
//         0051f767     MOV        this,dword ptr [ESI + 0x4ec]
//         0051f76d     LEA        EDI,[EAX + EDI*0x1 + 0x2]
//         0051f771     LEA        EBP,[this->_padding_ + EDX*0x1]
//         0051f774     CMP        EDI,EBP
//         0051f776     JL         LAB_0051f784
//                              tpnl_tml.cpp:700 (10)
//         0051f778     SUB        this,EAX
//         0051f77a     LEA        EDX,[this->_padding_ + EDX*0x1 + -0x3]
//         0051f77e     MOV        dword ptr [ESP + temp_start_y],EDX
//                              tpnl_tml.cpp:701 (2)
//         0051f782     JMP        LAB_0051f78e
//                               LAB_0051f784                                                 XREF[1]:     0051f776(j)
//                              tpnl_tml.cpp:702 (10)
//         0051f784     MOV        EAX,dword ptr [EBX + 0x4]
//         0051f787     ADD        EAX,0x2
//         0051f78a     MOV        dword ptr [ESP + temp_start_y],EAX
//                               LAB_0051f78e                                                 XREF[1]:     0051f782(j)
//                              tpnl_tml.cpp:704 (19)
//         0051f78e     MOV        EAX,dword ptr [EBX + 0x8]
//         0051f791     MOV        EDI,dword ptr [EBX + 0xc]
//         0051f794     MOV        EDX,dword ptr [ESI + 0x48c]
//         0051f79a     ADD        EAX,EDI
//         0051f79c     SUB        EAX,EDX
//         0051f79e     LEA        this,[EAX + -0x2]
//                              tpnl_tml.cpp:710 (5)
//         0051f7a1     JMP        LAB_0051f872
//                               switchD_0051f73e::caseD_1                                    XREF[2]:     0051f73e(j), 0051fa10(*)
//                              tpnl_tml.cpp:717 (13)
//         0051f7a6     LEA        EDI,[EBX + 0x3c]
//         0051f7a9     OR         this,0xffffffff
//         0051f7ac     XOR        EAX,EAX
//         0051f7ae     SCASB.RE   ES:EDI
//         0051f7b0     NOT        this
//         0051f7b2     DEC        this
//                              tpnl_tml.cpp:721 (38)
//         0051f7b3     MOV        EDI,dword ptr [EBX + 0x4]
//         0051f7b6     MOV        dword ptr [EBX + 0x38],this
//         0051f7b9     MOV        EAX,dword ptr [ESI + 0x488]
//         0051f7bf     IMUL       EAX,this
//         0051f7c2     MOV        EDX,dword ptr [ESI + 0x4dc]
//         0051f7c8     MOV        this,dword ptr [ESI + 0x4ec]
//         0051f7ce     LEA        EDI,[EAX + EDI*0x1 + 0x2]
//         0051f7d2     LEA        EBP,[this->_padding_ + EDX*0x1]
//         0051f7d5     CMP        EDI,EBP
//         0051f7d7     JL         LAB_0051f7e5
//                              tpnl_tml.cpp:723 (10)
//         0051f7d9     SUB        this,EAX
//         0051f7db     LEA        this,[this->_padding_ + EDX*0x1 + -0x8]
//         0051f7df     MOV        dword ptr [ESP + temp_start_y],this
//                              tpnl_tml.cpp:724 (2)
//         0051f7e3     JMP        LAB_0051f7ef
//                               LAB_0051f7e5                                                 XREF[1]:     0051f7d7(j)
//                              tpnl_tml.cpp:725 (10)
//         0051f7e5     MOV        EAX,dword ptr [EBX + 0x4]
//         0051f7e8     ADD        EAX,0x2
//         0051f7eb     MOV        dword ptr [ESP + temp_start_y],EAX
//                               LAB_0051f7ef                                                 XREF[1]:     0051f7e3(j)
//                              tpnl_tml.cpp:727 (31)
//         0051f7ef     MOV        this,dword ptr [ESI + 0x48c]
//         0051f7f5     MOV        EDI,dword ptr [EBX + 0x8]
//         0051f7f8     MOV        EDX,dword ptr [ESI + 0x4f0]
//         0051f7fe     MOV        EAX,dword ptr [ESI + 0x4e0]
//         0051f804     ADD        EAX,EDX
//         0051f806     LEA        EDX,[ECX + EDI*0x1 + this+0x2]
//         0051f80a     CMP        EDX,EAX
//         0051f80c     JL         LAB_0051f87c
//                              tpnl_tml.cpp:728 (7)
//         0051f80e     SUB        EAX,this
//         0051f810     SUB        EAX,0x2
//         0051f813     MOV        EDI,EAX
//                              tpnl_tml.cpp:729 (5)
//         0051f815     JMP        switchD_0051f73e::caseD_3
//                               switchD_0051f73e::caseD_2                                    XREF[2]:     0051f73e(j), 0051fa14(*)
//                              tpnl_tml.cpp:738 (13)
//         0051f81a     LEA        EDI,[EBX + 0x3c]
//         0051f81d     OR         this,0xffffffff
//         0051f820     XOR        EAX,EAX
//         0051f822     SCASB.RE   ES:EDI
//         0051f824     NOT        this
//         0051f826     DEC        this
//                              tpnl_tml.cpp:742 (38)
//         0051f827     MOV        EDI,dword ptr [EBX + 0x4]
//         0051f82a     MOV        dword ptr [EBX + 0x38],this
//         0051f82d     MOV        EAX,dword ptr [ESI + 0x488]
//         0051f833     IMUL       EAX,this
//         0051f836     MOV        EDX,dword ptr [ESI + 0x4dc]
//         0051f83c     MOV        this,dword ptr [ESI + 0x4ec]
//         0051f842     LEA        EDI,[EAX + EDI*0x1 + 0x2]
//         0051f846     LEA        EBP,[this->_padding_ + EDX*0x1]
//         0051f849     CMP        EDI,EBP
//         0051f84b     JL         LAB_0051f855
//                              tpnl_tml.cpp:744 (6)
//         0051f84d     SUB        this,EAX
//         0051f84f     LEA        EAX,[this->_padding_ + EDX*0x1 + -0x3]
//                              tpnl_tml.cpp:745 (2)
//         0051f853     JMP        LAB_0051f85b
//                               LAB_0051f855                                                 XREF[1]:     0051f84b(j)
//                              tpnl_tml.cpp:746 (6)
//         0051f855     MOV        EAX,dword ptr [EBX + 0x4]
//         0051f858     ADD        EAX,0x2
//                               LAB_0051f85b                                                 XREF[1]:     0051f853(j)
//                              tpnl_tml.cpp:748 (33)
//         0051f85b     MOV        this,dword ptr [EBX + 0x8]
//         0051f85e     MOV        EBP,dword ptr [EBX + 0xc]
//         0051f861     MOV        EDX,dword ptr [ESI + 0x48c]
//         0051f867     ADD        this,EBP
//         0051f869     SUB        this,EDX
//         0051f86b     MOV        dword ptr [ESP + temp_start_y],EAX
//         0051f86f     ADD        this,-0x2
//                               LAB_0051f872                                                 XREF[1]:     0051f7a1(j)
//         0051f872     MOV        EDI,dword ptr [ESI + 0x4e0]
//         0051f878     CMP        this,EDI
//         0051f87a     JG         LAB_0051f884
//                               LAB_0051f87c                                                 XREF[1]:     0051f80c(j)
//                              tpnl_tml.cpp:749 (3)
//         0051f87c     ADD        EDI,0x2
//                              tpnl_tml.cpp:750 (17)
//         0051f87f     JMP        switchD_0051f73e::caseD_3
//                               LAB_0051f884                                                 XREF[1]:     0051f87a(j)
//         0051f884     MOV        EAX,dword ptr [ESI + 0x4f0]
//         0051f88a     ADD        EAX,EDI
//         0051f88c     CMP        this,EAX
//         0051f88e     JL         LAB_0051f89c
//                              tpnl_tml.cpp:751 (7)
//         0051f890     SUB        EAX,EDX
//         0051f892     SUB        EAX,0x3
//         0051f895     MOV        EDI,EAX
//                              tpnl_tml.cpp:752 (5)
//         0051f897     JMP        switchD_0051f73e::caseD_3
//                               LAB_0051f89c                                                 XREF[1]:     0051f88e(j)
//                              tpnl_tml.cpp:753 (2)
//         0051f89c     MOV        EDI,this
//                              tpnl_tml.cpp:754 (5)
//         0051f89e     JMP        switchD_0051f73e::caseD_3
//                               switchD_0051f73e::caseD_6                                    XREF[2]:     0051f73e(j), 0051fa24(*)
//                              tpnl_tml.cpp:766 (53)
//         0051f8a3     MOV        this,dword ptr [ESI + 0x4dc]
//         0051f8a9     MOV        EAX,dword ptr [ESI + 0x4ec]
//         0051f8af     ADD        this,EAX
//         0051f8b1     LEA        EDI,[EBX + 0x3c]
//         0051f8b4     MOV        dword ptr [ESP + param_2],this
//         0051f8b8     OR         this,0xffffffff
//         0051f8bb     XOR        EAX,EAX
//         0051f8bd     MOV        EBP,dword ptr [ESI + 0x488]
//         0051f8c3     SCASB.RE   ES:EDI
//         0051f8c5     NOT        this
//         0051f8c7     DEC        this
//         0051f8c8     MOV        EDX,dword ptr [EBX + 0x4]
//         0051f8cb     IMUL       this,EBP
//         0051f8ce     MOV        EAX,dword ptr [ESP + param_2]
//         0051f8d2     ADD        this,EDX
//         0051f8d4     CMP        this,EAX
//         0051f8d6     JLE        LAB_0051f8e2
//                              tpnl_tml.cpp:767 (8)
//         0051f8d8     SUB        EAX,EDX
//         0051f8da     CDQ
//         0051f8db     IDIV       EBP
//         0051f8dd     MOV        dword ptr [EBX + 0x38],EAX
//                              tpnl_tml.cpp:768 (2)
//         0051f8e0     JMP        LAB_0051f8f2
//                               LAB_0051f8e2                                                 XREF[1]:     0051f8d6(j)
//                              tpnl_tml.cpp:769 (16)
//         0051f8e2     LEA        EDI,[EBX + 0x3c]
//         0051f8e5     OR         this,0xffffffff
//         0051f8e8     XOR        EAX,EAX
//         0051f8ea     SCASB.RE   ES:EDI
//         0051f8ec     NOT        this
//         0051f8ee     DEC        this
//         0051f8ef     MOV        dword ptr [EBX + 0x38],this
//                               LAB_0051f8f2                                                 XREF[1]:     0051f8e0(j)
//                              tpnl_tml.cpp:771 (12)
//         0051f8f2     MOV        this,dword ptr [EBX + 0x38]
//         0051f8f5     MOV        EAX,0x2
//         0051f8fa     CMP        this,EAX
//         0051f8fc     JLE        LAB_0051f901
//                              tpnl_tml.cpp:772 (3)
//         0051f8fe     MOV        dword ptr [EBX + 0x38],EAX
//                               LAB_0051f901                                                 XREF[1]:     0051f8fc(j)
//                              tpnl_tml.cpp:775 (46)
//         0051f901     MOVSX      this,word ptr [ESI + 0x4da]
//         0051f908     MOV        EDX,dword ptr [ESI + 0x48c]
//         0051f90e     MOV        EDI,dword ptr [ESP + temp_start_x]
//         0051f912     MOV        EAX,dword ptr [ESI + 0x4f0]
//         0051f918     MOV        ESI,dword ptr [ESI + 0x4e0]
//         0051f91e     ADD        EDI,EDX
//         0051f920     LEA        EBP,[EAX + ESI*0x1]
//         0051f923     LEA        EDI,[EDI + this->_padding_*0x1 + 0x1]
//         0051f927     CMP        EDI,EBP
//         0051f929     JLE        LAB_0051f9c8
//                              tpnl_tml.cpp:780 (5)
//         0051f92f     JMP        LAB_0051f9bc
//                               switchD_0051f73e::caseD_8                                    XREF[2]:     0051f73e(j), 0051fa2c(*)
//                              tpnl_tml.cpp:787 (53)
//         0051f934     MOV        EAX,dword ptr [ESI + 0x4dc]
//         0051f93a     MOV        this,dword ptr [ESI + 0x4ec]
//         0051f940     ADD        EAX,this
//         0051f942     LEA        EDI,[EBX + 0x3c]
//         0051f945     MOV        dword ptr [ESP + param_2],EAX
//         0051f949     OR         this,0xffffffff
//         0051f94c     XOR        EAX,EAX
//         0051f94e     MOV        EBP,dword ptr [ESI + 0x488]
//         0051f954     SCASB.RE   ES:EDI
//         0051f956     NOT        this
//         0051f958     DEC        this
//         0051f959     MOV        EDX,dword ptr [EBX + 0x4]
//         0051f95c     IMUL       this,EBP
//         0051f95f     MOV        EAX,dword ptr [ESP + param_2]
//         0051f963     ADD        this,EDX
//         0051f965     CMP        this,EAX
//         0051f967     JLE        LAB_0051f973
//                              tpnl_tml.cpp:788 (8)
//         0051f969     SUB        EAX,EDX
//         0051f96b     CDQ
//         0051f96c     IDIV       EBP
//         0051f96e     MOV        dword ptr [EBX + 0x38],EAX
//                              tpnl_tml.cpp:789 (2)
//         0051f971     JMP        LAB_0051f983
//                               LAB_0051f973                                                 XREF[1]:     0051f967(j)
//                              tpnl_tml.cpp:790 (16)
//         0051f973     LEA        EDI,[EBX + 0x3c]
//         0051f976     OR         this,0xffffffff
//         0051f979     XOR        EAX,EAX
//         0051f97b     SCASB.RE   ES:EDI
//         0051f97d     NOT        this
//         0051f97f     DEC        this
//         0051f980     MOV        dword ptr [EBX + 0x38],this
//                               LAB_0051f983                                                 XREF[1]:     0051f971(j)
//                              tpnl_tml.cpp:792 (12)
//         0051f983     MOV        this,dword ptr [EBX + 0x38]
//         0051f986     MOV        EAX,0x5
//         0051f98b     CMP        this,EAX
//         0051f98d     JLE        LAB_0051f992
//                              tpnl_tml.cpp:793 (3)
//         0051f98f     MOV        dword ptr [EBX + 0x38],EAX
//                               LAB_0051f992                                                 XREF[1]:     0051f98d(j)
//                              tpnl_tml.cpp:796 (42)
//         0051f992     MOVSX      this,word ptr [ESI + 0x4da]
//         0051f999     MOV        EDX,dword ptr [ESI + 0x48c]
//         0051f99f     MOV        EDI,dword ptr [ESP + temp_start_x]
//         0051f9a3     MOV        EAX,dword ptr [ESI + 0x4f0]
//         0051f9a9     MOV        ESI,dword ptr [ESI + 0x4e0]
//         0051f9af     ADD        EDI,EDX
//         0051f9b1     LEA        EBP,[EAX + ESI*0x1]
//         0051f9b4     LEA        EDI,[EDI + this->_padding_*0x1 + 0x1]
//         0051f9b8     CMP        EDI,EBP
//         0051f9ba     JLE        LAB_0051f9c8
//                               LAB_0051f9bc                                                 XREF[1]:     0051f92f(j)
//                              tpnl_tml.cpp:798 (12)
//         0051f9bc     SUB        EAX,EDX
//         0051f9be     SUB        EAX,this
//         0051f9c0     LEA        EDX,[EAX + ESI*0x1 + -0x1]
//         0051f9c4     MOV        dword ptr [ESP + temp_start_x],EDX
//                               LAB_0051f9c8                                                 XREF[2]:     0051f929(j), 0051f9ba(j)
//                              tpnl_tml.cpp:800 (16)
//         0051f9c8     MOV        EDX,dword ptr [ESP + temp_start_x]
//         0051f9cc     MOV        EAX,dword ptr [ESP + local_4]
//         0051f9d0     MOV        dword ptr [ESP + temp_start_y],EAX
//         0051f9d4     LEA        EDI,[EDX + this->_padding_*0x1 + 0x1]
//                               switchD_0051f73e::caseD_4                                    XREF[10]:    0051f738(j), 0051f73e(j),
//                               switchD_0051f73e::caseD_5                                                 0051f815(j), 0051f87f(j),
//                               switchD_0051f73e::caseD_7                                                 0051f897(j), 0051f89e(j),
//                               switchD_0051f73e::caseD_3                                                 0051fa18(*), 0051fa1c(*),
//                                                                                                         0051fa20(*), 0051fa28(*)
//                              tpnl_tml.cpp:808 (4)
//         0051f9d8     MOV        EAX,dword ptr [ESP + local_4]
//                              tpnl_tml.cpp:809 (4)
//         0051f9dc     MOV        this,dword ptr [ESP + temp_start_y]
//                              tpnl_tml.cpp:811 (7)
//         0051f9e0     MOV        EDX,dword ptr [ESP + temp_start_x]
//         0051f9e4     MOV        dword ptr [EBX + 0x20],EAX
//                              tpnl_tml.cpp:814 (17)
//         0051f9e7     MOV        EAX,dword ptr [ESP + temp_start_txt_x1]
//         0051f9eb     MOV        dword ptr [EBX + 0x28],this
//         0051f9ee     TEST       EAX,EAX
//         0051f9f0     MOV        dword ptr [EBX + 0x24],EDX
//         0051f9f3     MOV        dword ptr [EBX + 0x2c],EDI
//         0051f9f6     JZ         LAB_0051fa02
//                              tpnl_tml.cpp:815 (10)
//         0051f9f8     MOV        dword ptr [EBX + 0xa8],0x1
//                               LAB_0051fa02                                                 XREF[1]:     0051f9f6(j)
//                              tpnl_tml.cpp:817 (46)
//         0051fa02     POP        EDI
//         0051fa03     POP        ESI
//         0051fa04     POP        EBP
//         0051fa05     POP        EBX
//         0051fa06     ADD        ESP,0x14
//         0051fa09     RET        0xc
//                              Symbol Ref: No symbol: NONAME
//                               switchD_0051f73e::switchdataD_0051fa0c                       XREF[1]:     calculate_icon_location:0051f73e(*
//         0051fa0c     addr       switchD_0051f73e::caseD_0
//         0051fa10     addr       switchD_0051f73e::caseD_1
//         0051fa14     addr       switchD_0051f73e::caseD_2
//         0051fa18     addr       switchD_0051f73e::caseD_3
//         0051fa1c     addr       switchD_0051f73e::caseD_3
//         0051fa20     addr       switchD_0051f73e::caseD_3
//         0051fa24     addr       switchD_0051f73e::caseD_6
//         0051fa28     addr       switchD_0051f73e::caseD_3
//         0051fa2c     addr       switchD_0051f73e::caseD_8
    return 0;
}

void Time_Line_Panel::draw() {
    /* TODO: Stub */
//                              void __thiscall draw(Time_Line_Panel * this)
//              void              <VOID>         <RETURN>
//              Time_Line_Pane    ECX:4 (auto)   this
//                               ?draw@Time_Line_Panel@@UAEXXZ                                XREF[1]:     00576fb8(*)
//                               Time_Line_Panel::draw
//                              tpnl_tml.cpp:825 (3)
//         0051fa30     PUSH       ESI
//         0051fa31     MOV        ESI,this
//                              tpnl_tml.cpp:826 (5)
//         0051fa33     CALL       TPanel::draw                                     void draw(TPanel * this)
//                              tpnl_tml.cpp:829 (29)
//         0051fa38     MOV        EAX,dword ptr [ESI + 0x20]
//         0051fa3b     MOV        dword ptr [ESI + 0x38],0x0
//         0051fa42     TEST       EAX,EAX
//         0051fa44     JZ         LAB_0051fa8e
//         0051fa46     MOV        EAX,dword ptr [ESI + 0x70]
//         0051fa49     TEST       EAX,EAX
//         0051fa4b     JZ         LAB_0051fa8e
//         0051fa4d     MOV        EAX,dword ptr [ESI + 0x6c]
//         0051fa50     TEST       EAX,EAX
//         0051fa52     JZ         LAB_0051fa8e
//         0051fa54     PUSH       EDI
//                              tpnl_tml.cpp:832 (9)
//         0051fa55     MOV        EDI,dword ptr [ESI]
//         0051fa57     PUSH       0x0
//         0051fa59     MOV        this,ESI
//         0051fa5b     CALL       dword ptr [EDI + 0x28]
//                              tpnl_tml.cpp:834 (7)
//         0051fa5e     MOV        this,ESI
//         0051fa60     CALL       Time_Line_Panel::draw_background                 void draw_background(Time_Line_Panel * this)
//                              tpnl_tml.cpp:835 (7)
//         0051fa65     MOV        this,ESI
//         0051fa67     CALL       Time_Line_Panel::draw_border                     void draw_border(Time_Line_Panel * this)
//                              tpnl_tml.cpp:836 (7)
//         0051fa6c     MOV        this,ESI
//         0051fa6e     CALL       Time_Line_Panel::draw_axis                       void draw_axis(Time_Line_Panel * this)
//                              tpnl_tml.cpp:837 (7)
//         0051fa73     MOV        this,ESI
//         0051fa75     CALL       Time_Line_Panel::draw_timeline                   void draw_timeline(Time_Line_Panel * this)
//                              tpnl_tml.cpp:838 (7)
//         0051fa7a     MOV        this,ESI
//         0051fa7c     CALL       Time_Line_Panel::draw_special_events             void draw_special_events(Time_Line_Panel * th
//                              tpnl_tml.cpp:839 (7)
//         0051fa81     MOV        this,ESI
//         0051fa83     CALL       Time_Line_Panel::draw_civilization_names         void draw_civilization_names(Time_Line_Panel
//                              tpnl_tml.cpp:841 (6)
//         0051fa88     MOV        this,ESI
//         0051fa8a     CALL       dword ptr [EDI + 0x2c]
//         0051fa8d     POP        EDI
//                               LAB_0051fa8e                                                 XREF[3]:     0051fa44(j), 0051fa4b(j),
//                                                                                                         0051fa52(j)
//                              tpnl_tml.cpp:842 (2)
//         0051fa8e     POP        ESI
//         0051fa8f     RET
    return;
}

void Time_Line_Panel::draw_axis() {
    /* TODO: Stub */
//                              void __thiscall draw_axis(Time_Line_Panel * this)
//              void              <VOID>         <RETURN>
//              Time_Line_Pane    ECX:4 (auto)   this
//              char[100]         Stack[-0x68]   temp_str
//              uchar             Stack[-0x6c]:1 white_color
//                               ?draw_axis@Time_Line_Panel@@QAEXXZ                           XREF[1]:     draw:0051fa6e(c)
//                               Time_Line_Panel::draw_axis
//                              tpnl_tml.cpp:848 (9)
//         0051fa90     SUB        ESP,0x68
//         0051fa93     PUSH       EBX
//         0051fa94     PUSH       EBP
//         0051fa95     PUSH       ESI
//         0051fa96     MOV        ESI,this
//         0051fa98     PUSH       EDI
//                              tpnl_tml.cpp:858 (20)
//         0051fa99     PUSH       0xffffff
//         0051fa9e     MOV        EAX,dword ptr [ESI + 0x20]
//         0051faa1     MOV        this,dword ptr [EAX]
//         0051faa3     MOV        EDX,dword ptr [ECX + this->_padding_]
//         0051faa6     PUSH       EDX
//         0051faa7     CALL       dword ptr [->GDI32.DLL::GetNearestPaletteIndex]  = 0048b294
//                              tpnl_tml.cpp:862 (27)
//         0051faad     MOV        this,dword ptr [ESI + 0x20]
//         0051fab0     PUSH       0x1
//         0051fab2     PUSH       s_tpnl_tml::draw_axis                            = "tpnl_tml::draw_axis"
//         0051fab7     MOV        byte ptr [ESP + 0x18],AL
//         0051fabb     CALL       TDrawArea::Lock                                  uchar * Lock(TDrawArea * this, char * param_1
//         0051fac0     TEST       EAX,EAX
//         0051fac2     JZ         LAB_0051fc17
//                              tpnl_tml.cpp:868 (95)
//         0051fac8     MOV        EDI,dword ptr [ESP + 0x10]
//         0051facc     MOV        this,ESI
//         0051face     PUSH       EDI
//         0051facf     CALL       TPanel::yPosition                                long yPosition(TPanel * this)
//         0051fad4     MOV        this,dword ptr [ESI + 0x480]
//         0051fada     LEA        EDX,[EAX + this->_padding_*0x2]
//         0051fadd     MOV        EAX,dword ptr [ESI + 0x4f8]
//         0051fae3     LEA        this,[EDX + EAX*0x1 + 0xd]
//         0051fae7     PUSH       this
//         0051fae8     MOV        this,ESI
//         0051faea     CALL       TPanel::xPosition                                long xPosition(TPanel * this)
//         0051faef     MOV        EDX,dword ptr [ESI + 0x4f4]
//         0051faf5     MOV        this,ESI
//         0051faf7     LEA        EAX,[EAX + EDX*0x1 + 0x18]
//         0051fafb     PUSH       EAX
//         0051fafc     CALL       TPanel::yPosition                                long yPosition(TPanel * this)
//         0051fb01     MOV        this,dword ptr [ESI + 0x480]
//         0051fb07     LEA        EDX,[EAX + this->_padding_*0x2 + 0xc]
//         0051fb0b     MOV        this,dword ptr [ESI + 0x4f8]
//         0051fb11     ADD        EDX,this
//         0051fb13     MOV        this,ESI
//         0051fb15     PUSH       EDX
//         0051fb16     CALL       TPanel::xPosition                                long xPosition(TPanel * this)
//         0051fb1b     MOV        this,dword ptr [ESI + 0x20]
//         0051fb1e     ADD        EAX,0x19
//         0051fb21     PUSH       EAX
//         0051fb22     CALL       TDrawArea::FillRect                              void FillRect(TDrawArea * this, long param_1,
//                              tpnl_tml.cpp:873 (74)
//         0051fb27     PUSH       EDI
//         0051fb28     MOV        this,ESI
//         0051fb2a     CALL       TPanel::yPosition                                long yPosition(TPanel * this)
//         0051fb2f     MOV        this,dword ptr [ESI + 0x480]
//         0051fb35     LEA        EDX,[EAX + this->_padding_*0x2 + 0xe]
//         0051fb39     MOV        this,ESI
//         0051fb3b     PUSH       EDX
//         0051fb3c     CALL       TPanel::xPosition                                long xPosition(TPanel * this)
//         0051fb41     MOV        this,dword ptr [ESI + 0x4f4]
//         0051fb47     LEA        EDX,[EAX + this->_padding_*0x1 + 0x18]
//         0051fb4b     MOV        this,ESI
//         0051fb4d     PUSH       EDX
//         0051fb4e     CALL       TPanel::yPosition                                long yPosition(TPanel * this)
//         0051fb53     MOV        this,dword ptr [ESI + 0x480]
//         0051fb59     LEA        EDX,[EAX + this->_padding_*0x2 + 0xd]
//         0051fb5d     MOV        this,ESI
//         0051fb5f     PUSH       EDX
//         0051fb60     CALL       TPanel::xPosition                                long xPosition(TPanel * this)
//         0051fb65     MOV        this,dword ptr [ESI + 0x20]
//         0051fb68     ADD        EAX,0x19
//         0051fb6b     PUSH       EAX
//         0051fb6c     CALL       TDrawArea::FillRect                              void FillRect(TDrawArea * this, long param_1,
//                              tpnl_tml.cpp:878 (76)
//         0051fb71     PUSH       EDI
//         0051fb72     MOV        this,ESI
//         0051fb74     CALL       TPanel::yPosition                                long yPosition(TPanel * this)
//         0051fb79     MOV        this,dword ptr [ESI + 0x480]
//         0051fb7f     LEA        EDX,[EAX + this->_padding_*0x2]
//         0051fb82     MOV        EAX,dword ptr [ESI + 0x4f8]
//         0051fb88     LEA        this,[EDX + EAX*0x1 + 0xd]
//         0051fb8c     PUSH       this
//         0051fb8d     MOV        this,ESI
//         0051fb8f     CALL       TPanel::xPosition                                long xPosition(TPanel * this)
//         0051fb94     ADD        EAX,0x1a
//         0051fb97     MOV        this,ESI
//         0051fb99     PUSH       EAX
//         0051fb9a     CALL       TPanel::yPosition                                long yPosition(TPanel * this)
//         0051fb9f     MOV        EDX,dword ptr [ESI + 0x480]
//         0051fba5     MOV        this,ESI
//         0051fba7     LEA        EAX,[EAX + EDX*0x2 + 0xd]
//         0051fbab     PUSH       EAX
//         0051fbac     CALL       TPanel::xPosition                                long xPosition(TPanel * this)
//         0051fbb1     MOV        this,dword ptr [ESI + 0x20]
//         0051fbb4     ADD        EAX,0x19
//         0051fbb7     PUSH       EAX
//         0051fbb8     CALL       TDrawArea::FillRect                              void FillRect(TDrawArea * this, long param_1,
//                              tpnl_tml.cpp:883 (90)
//         0051fbbd     PUSH       EDI
//         0051fbbe     MOV        this,ESI
//         0051fbc0     CALL       TPanel::yPosition                                long yPosition(TPanel * this)
//         0051fbc5     MOV        this,dword ptr [ESI + 0x480]
//         0051fbcb     LEA        EDX,[EAX + this->_padding_*0x2]
//         0051fbce     MOV        EAX,dword ptr [ESI + 0x4f8]
//         0051fbd4     LEA        this,[EDX + EAX*0x1 + 0xd]
//         0051fbd8     PUSH       this
//         0051fbd9     MOV        this,ESI
//         0051fbdb     CALL       TPanel::xPosition                                long xPosition(TPanel * this)
//         0051fbe0     MOV        EDX,dword ptr [ESI + 0x4f4]
//         0051fbe6     MOV        this,ESI
//         0051fbe8     LEA        EAX,[EAX + EDX*0x1 + 0x18]
//         0051fbec     PUSH       EAX
//         0051fbed     CALL       TPanel::yPosition                                long yPosition(TPanel * this)
//         0051fbf2     MOV        this,dword ptr [ESI + 0x480]
//         0051fbf8     LEA        EDX,[EAX + this->_padding_*0x2 + 0xd]
//         0051fbfc     MOV        this,ESI
//         0051fbfe     PUSH       EDX
//         0051fbff     CALL       TPanel::xPosition                                long xPosition(TPanel * this)
//         0051fc04     MOV        this,dword ptr [ESI + 0x4f4]
//         0051fc0a     LEA        EDX,[EAX + this->_padding_*0x1 + 0x17]
//         0051fc0e     MOV        this,dword ptr [ESI + 0x20]
//         0051fc11     PUSH       EDX
//         0051fc12     CALL       TDrawArea::FillRect                              void FillRect(TDrawArea * this, long param_1,
//                               LAB_0051fc17                                                 XREF[1]:     0051fac2(j)
//                              tpnl_tml.cpp:886 (13)
//         0051fc17     MOV        this,dword ptr [ESI + 0x20]
//         0051fc1a     PUSH       s_tpnl_tml::draw_axis                            = "tpnl_tml::draw_axis"
//         0051fc1f     CALL       TDrawArea::Unlock                                void Unlock(TDrawArea * this, char * param_1)
//                              tpnl_tml.cpp:889 (21)
//         0051fc24     MOV        this,dword ptr [ESI + 0x20]
//         0051fc27     PUSH       s_tpnl_tml::draw_axis                            = "tpnl_tml::draw_axis"
//         0051fc2c     CALL       TDrawArea::GetDc                                 void * GetDc(TDrawArea * this, char * param_1)
//         0051fc31     TEST       EAX,EAX
//         0051fc33     JZ         LAB_0051fd80
//                              tpnl_tml.cpp:891 (15)
//         0051fc39     MOV        EAX,dword ptr [ESI + 0x20]
//         0051fc3c     PUSH       0x1
//         0051fc3e     MOV        this,dword ptr [EAX + 0x38]
//         0051fc41     PUSH       this
//         0051fc42     CALL       dword ptr [->GDI32.DLL::SetBkMode]               = 0048b340
//                              tpnl_tml.cpp:892 (20)
//         0051fc48     MOV        EAX,dword ptr [ESI + 0x20]
//         0051fc4b     MOV        EDX,dword ptr [ESI + 0x478]
//         0051fc51     PUSH       EDX
//         0051fc52     MOV        this,dword ptr [EAX + 0x38]
//         0051fc55     PUSH       this
//         0051fc56     CALL       dword ptr [->GDI32.DLL::SelectObject]            = 0048b192
//                              tpnl_tml.cpp:895 (27)
//         0051fc5c     LEA        EDX,[ESP + 0x14]
//         0051fc60     PUSH       0x64
//         0051fc62     PUSH       EDX
//                              language.dll match for 0x2c57: "World Population"
//         0051fc63     PUSH       0x2c57
//         0051fc68     MOV        this,ESI
//         0051fc6a     MOV        dword ptr [ESP + 0x1c],EAX
//         0051fc6e     CALL       TPanel::get_string                               int get_string(TPanel * this, int param_1, ch
//         0051fc73     TEST       EAX,EAX
//         0051fc75     JZ         LAB_0051fcc4
//                              tpnl_tml.cpp:897 (9)
//         0051fc77     MOV        this,ESI
//         0051fc79     CALL       TPanel::xPosition                                long xPosition(TPanel * this)
//         0051fc7e     MOV        EBX,EAX
//                              tpnl_tml.cpp:898 (12)
//         0051fc80     MOV        this,ESI
//         0051fc82     ADD        EBX,0x8
//         0051fc85     CALL       TPanel::yPosition                                long yPosition(TPanel * this)
//         0051fc8a     MOV        EBP,EAX
//                              tpnl_tml.cpp:899 (21)
//         0051fc8c     MOV        EAX,dword ptr [ESI + 0x20]
//         0051fc8f     PUSH       0xffffff
//         0051fc94     ADD        EBP,0x5
//         0051fc97     MOV        this,dword ptr [EAX + 0x38]
//         0051fc9a     PUSH       this
//         0051fc9b     CALL       dword ptr [->GDI32.DLL::SetTextColor]            = 0048b318
//                              tpnl_tml.cpp:900 (35)
//         0051fca1     LEA        EDI,[ESP + 0x14]
//         0051fca5     OR         this,0xffffffff
//         0051fca8     XOR        EAX,EAX
//         0051fcaa     LEA        EDX,[ESP + 0x14]
//         0051fcae     SCASB.RE   ES:EDI
//         0051fcb0     MOV        EAX,dword ptr [ESI + 0x20]
//         0051fcb3     NOT        this
//         0051fcb5     DEC        this
//         0051fcb6     PUSH       this
//         0051fcb7     MOV        this,dword ptr [EAX + 0x38]
//         0051fcba     PUSH       EDX
//         0051fcbb     PUSH       EBP
//         0051fcbc     PUSH       EBX
//         0051fcbd     PUSH       this
//         0051fcbe     CALL       dword ptr [->GDI32.DLL::TextOutA]                = 0048b30c
//                               LAB_0051fcc4                                                 XREF[1]:     0051fc75(j)
//                              tpnl_tml.cpp:904 (27)
//         0051fcc4     LEA        EDX,[ESP + 0x14]
//         0051fcc8     PUSH       0x64
//         0051fcca     PUSH       EDX
//                              language.dll match for 0x2c56: "Time (Hr:Min)"
//         0051fccb     PUSH       0x2c56
//         0051fcd0     MOV        this,ESI
//         0051fcd2     CALL       TPanel::get_string                               int get_string(TPanel * this, int param_1, ch
//         0051fcd7     TEST       EAX,EAX
//         0051fcd9     JZ         LAB_0051fd61
//                              tpnl_tml.cpp:906 (42)
//         0051fcdf     LEA        EDI,[ESP + 0x14]
//         0051fce3     OR         this,0xffffffff
//         0051fce6     XOR        EAX,EAX
//         0051fce8     MOV        EBX,dword ptr [ESI + 0x4dc]
//         0051fcee     SCASB.RE   ES:EDI
//         0051fcf0     NOT        this
//         0051fcf2     DEC        this
//         0051fcf3     MOV        EAX,dword ptr [ESI + 0x4f4]
//         0051fcf9     IMUL       this,dword ptr [ESI + 0x47c]
//         0051fd00     CDQ
//         0051fd01     SHR        this,0x1
//         0051fd03     SUB        EAX,EDX
//         0051fd05     SUB        EBX,this
//         0051fd07     SAR        EAX,0x1
//                              tpnl_tml.cpp:907 (18)
//         0051fd09     MOV        this,ESI
//         0051fd0b     ADD        EBX,EAX
//         0051fd0d     CALL       TPanel::height                                   long height(TPanel * this)
//         0051fd12     MOV        this,ESI
//         0051fd14     MOV        EBP,EAX
//         0051fd16     CALL       TPanel::yPosition                                long yPosition(TPanel * this)
//                              tpnl_tml.cpp:908 (35)
//         0051fd1b     MOV        this,dword ptr [ESI + 0x20]
//         0051fd1e     MOV        EDI,dword ptr [ESI + 0x480]
//         0051fd24     ADD        EBP,EAX
//         0051fd26     MOV        EAX,0xfffffffb
//         0051fd2b     MOV        EDX,dword ptr [ECX + this->_padding_]
//         0051fd2e     SUB        EAX,EDI
//         0051fd30     PUSH       0xffffff
//         0051fd35     PUSH       EDX
//         0051fd36     ADD        EBP,EAX
//         0051fd38     CALL       dword ptr [->GDI32.DLL::SetTextColor]            = 0048b318
//                              tpnl_tml.cpp:909 (35)
//         0051fd3e     LEA        EDI,[ESP + 0x14]
//         0051fd42     OR         this,0xffffffff
//         0051fd45     XOR        EAX,EAX
//         0051fd47     SCASB.RE   ES:EDI
//         0051fd49     NOT        this
//         0051fd4b     DEC        this
//         0051fd4c     LEA        EAX,[ESP + 0x14]
//         0051fd50     PUSH       this
//         0051fd51     MOV        this,dword ptr [ESI + 0x20]
//         0051fd54     PUSH       EAX
//         0051fd55     PUSH       EBP
//         0051fd56     MOV        EDX,dword ptr [ECX + this->_padding_]
//         0051fd59     PUSH       EBX
//         0051fd5a     PUSH       EDX
//         0051fd5b     CALL       dword ptr [->GDI32.DLL::TextOutA]                = 0048b30c
//                               LAB_0051fd61                                                 XREF[1]:     0051fcd9(j)
//                              tpnl_tml.cpp:912 (18)
//         0051fd61     MOV        this,dword ptr [ESI + 0x20]
//         0051fd64     MOV        EAX,dword ptr [ESP + 0x10]
//         0051fd68     PUSH       EAX
//         0051fd69     MOV        EDX,dword ptr [ECX + this->_padding_]
//         0051fd6c     PUSH       EDX
//         0051fd6d     CALL       dword ptr [->GDI32.DLL::SelectObject]            = 0048b192
//                              tpnl_tml.cpp:913 (13)
//         0051fd73     MOV        this,dword ptr [ESI + 0x20]
//         0051fd76     PUSH       s_tpnl_tml::draw_axis                            = "tpnl_tml::draw_axis"
//         0051fd7b     CALL       TDrawArea::ReleaseDc                             void ReleaseDc(TDrawArea * this, char * param
//                               LAB_0051fd80                                                 XREF[1]:     0051fc33(j)
//                              tpnl_tml.cpp:916 (8)
//         0051fd80     POP        EDI
//         0051fd81     POP        ESI
//         0051fd82     POP        EBP
//         0051fd83     POP        EBX
//         0051fd84     ADD        ESP,0x68
//         0051fd87     RET
//         0051fd88     ??         90h
//         0051fd89     NOP
//         0051fd8a     NOP
//         0051fd8b     NOP
//         0051fd8c     NOP
//         0051fd8d     NOP
//         0051fd8e     NOP
//         0051fd8f     NOP
    return;
}

void Time_Line_Panel::draw_special_events() {
    /* TODO: Stub */
//                              void __thiscall draw_special_events(Time_Line_Panel * this)
//              void              <VOID>         <RETURN>
//              Time_Line_Pane    ECX:4 (auto)   this
//              void *            Stack[-0x8]:4  old_font
//                               ?draw_special_events@Time_Line_Panel@@QAEXXZ                 XREF[1]:     draw:0051fa7c(c)
//                               Time_Line_Panel::draw_special_events
//                              tpnl_tml.cpp:923 (7)
//         0051fd90     PUSH       this
//         0051fd91     PUSH       EBX
//         0051fd92     PUSH       EBP
//         0051fd93     PUSH       ESI
//         0051fd94     MOV        ESI,this
//         0051fd96     PUSH       EDI
//                              tpnl_tml.cpp:932 (14)
//         0051fd97     MOV        AL,byte ptr [ESI + 0x51c]
//         0051fd9d     TEST       AL,AL
//         0051fd9f     JZ         LAB_0052002c
//                              tpnl_tml.cpp:937 (22)
//         0051fda5     MOV        EAX,dword ptr [ESI + 0x20]
//         0051fda8     MOV        EDI,dword ptr [->GDI32.DLL::GetNearestPaletteI   = 0048b294
//         0051fdae     PUSH       0xffffff
//         0051fdb3     MOV        this,dword ptr [EAX]
//         0051fdb5     MOV        EDX,dword ptr [ECX + this->_padding_]
//         0051fdb8     PUSH       EDX
//         0051fdb9     CALL       EDI=>GDI32.DLL::GetNearestPaletteIndex
//                              tpnl_tml.cpp:939 (13)
//         0051fdbb     MOV        EAX,dword ptr [ESI + 0x20]
//         0051fdbe     PUSH       0x0
//         0051fdc0     MOV        this,dword ptr [EAX]
//         0051fdc2     MOV        EDX,dword ptr [ECX + this->_padding_]
//         0051fdc5     PUSH       EDX
//         0051fdc6     CALL       EDI=>GDI32.DLL::GetNearestPaletteIndex
//                              tpnl_tml.cpp:942 (19)
//         0051fdc8     MOV        this,dword ptr [ESI + 0x20]
//         0051fdcb     PUSH       0x1
//         0051fdcd     PUSH       s_tpnl_tml::draw_special_events                  = "tpnl_tml::draw_special_events"
//         0051fdd2     CALL       TDrawArea::Lock                                  uchar * Lock(TDrawArea * this, char * param_1
//         0051fdd7     TEST       EAX,EAX
//         0051fdd9     JZ         LAB_0051fe36
//                              tpnl_tml.cpp:944 (10)
//         0051fddb     MOV        EDI,dword ptr [ESI + 0x518]
//         0051fde1     TEST       EDI,EDI
//         0051fde3     JZ         LAB_0051fe36
//                               LAB_0051fde5                                                 XREF[1]:     0051fe34(j)
//                              tpnl_tml.cpp:946 (17)
//         0051fde5     XOR        EAX,EAX
//         0051fde7     MOV        AL,byte ptr [EDI + 0x12]
//         0051fdea     CMP        EAX,0x8
//         0051fded     JA         switchD_0051fdef::default
//                               switchD_0051fdef::switchD
//         0051fdef     JMP        dword ptr [EAX*0x4 + switchD_0051fdef::switchd   = 0051fdf6
//                               switchD_0051fdef::caseD_0                                    XREF[2]:     0051fdef(j), 00520034(*)
//                              tpnl_tml.cpp:950 (2)
//         0051fdf6     PUSH       0x0
//                              tpnl_tml.cpp:951 (2)
//         0051fdf8     JMP        LAB_0051fe22
//                               switchD_0051fdef::caseD_1                                    XREF[2]:     0051fdef(j), 00520038(*)
//                              tpnl_tml.cpp:954 (2)
//         0051fdfa     PUSH       0x1
//                              tpnl_tml.cpp:955 (2)
//         0051fdfc     JMP        LAB_0051fe22
//                               switchD_0051fdef::caseD_2                                    XREF[2]:     0051fdef(j), 0052003c(*)
//                              tpnl_tml.cpp:958 (2)
//         0051fdfe     PUSH       0x2
//                              tpnl_tml.cpp:959 (2)
//         0051fe00     JMP        LAB_0051fe22
//                               switchD_0051fdef::caseD_4                                    XREF[2]:     0051fdef(j), 00520044(*)
//                              tpnl_tml.cpp:961 (4)
//         0051fe02     PUSH       0x4
//         0051fe04     PUSH       0x0
//                              tpnl_tml.cpp:962 (2)
//         0051fe06     JMP        LAB_0051fe24
//                               switchD_0051fdef::caseD_5                                    XREF[2]:     0051fdef(j), 00520048(*)
//                              tpnl_tml.cpp:964 (4)
//         0051fe08     PUSH       0x5
//         0051fe0a     PUSH       0x1
//                              tpnl_tml.cpp:965 (2)
//         0051fe0c     JMP        LAB_0051fe24
//                               switchD_0051fdef::caseD_6                                    XREF[2]:     0051fdef(j), 0052004c(*)
//                              tpnl_tml.cpp:967 (4)
//         0051fe0e     PUSH       0x6
//         0051fe10     PUSH       0x2
//                              tpnl_tml.cpp:968 (2)
//         0051fe12     JMP        LAB_0051fe24
//                               switchD_0051fdef::caseD_7                                    XREF[2]:     0051fdef(j), 00520050(*)
//                              tpnl_tml.cpp:970 (4)
//         0051fe14     PUSH       0x7
//         0051fe16     PUSH       0x3
//                              tpnl_tml.cpp:971 (2)
//         0051fe18     JMP        LAB_0051fe24
//                               switchD_0051fdef::caseD_8                                    XREF[2]:     0051fdef(j), 00520054(*)
//                              tpnl_tml.cpp:973 (4)
//         0051fe1a     PUSH       0x8
//         0051fe1c     PUSH       0x4
//                              tpnl_tml.cpp:974 (2)
//         0051fe1e     JMP        LAB_0051fe24
//                               switchD_0051fdef::caseD_3                                    XREF[2]:     0051fdef(j), 00520040(*)
//                              tpnl_tml.cpp:976 (22)
//         0051fe20     PUSH       0x3
//                               LAB_0051fe22                                                 XREF[3]:     0051fdf8(j), 0051fdfc(j),
//                                                                                                         0051fe00(j)
//         0051fe22     PUSH       -0x1
//                               LAB_0051fe24                                                 XREF[5]:     0051fe06(j), 0051fe0c(j),
//                                                                                                         0051fe12(j), 0051fe18(j),
//                                                                                                         0051fe1e(j)
//         0051fe24     PUSH       EDI
//         0051fe25     MOV        this,ESI
//         0051fe27     CALL       Time_Line_Panel::draw_icon                       void draw_icon(Time_Line_Panel * this, Specia
//                               switchD_0051fdef::default                                    XREF[1]:     0051fded(j)
//         0051fe2c     MOV        EDI,dword ptr [EDI + 0xac]
//         0051fe32     TEST       EDI,EDI
//         0051fe34     JNZ        LAB_0051fde5
//                               LAB_0051fe36                                                 XREF[2]:     0051fdd9(j), 0051fde3(j)
//                              tpnl_tml.cpp:983 (13)
//         0051fe36     MOV        this,dword ptr [ESI + 0x20]
//         0051fe39     PUSH       s_tpnl_tml::draw_special_events                  = "tpnl_tml::draw_special_events"
//         0051fe3e     CALL       TDrawArea::Unlock                                void Unlock(TDrawArea * this, char * param_1)
//                              tpnl_tml.cpp:988 (21)
//         0051fe43     MOV        this,dword ptr [ESI + 0x20]
//         0051fe46     PUSH       s_tpnl_tml::draw_special_events                  = "tpnl_tml::draw_special_events"
//         0051fe4b     CALL       TDrawArea::GetDc                                 void * GetDc(TDrawArea * this, char * param_1)
//         0051fe50     TEST       EAX,EAX
//         0051fe52     JZ         LAB_0052002c
//                              tpnl_tml.cpp:990 (15)
//         0051fe58     MOV        EAX,dword ptr [ESI + 0x20]
//         0051fe5b     PUSH       0x1
//         0051fe5d     MOV        this,dword ptr [EAX + 0x38]
//         0051fe60     PUSH       this
//         0051fe61     CALL       dword ptr [->GDI32.DLL::SetBkMode]               = 0048b340
//                              tpnl_tml.cpp:991 (20)
//         0051fe67     MOV        EAX,dword ptr [ESI + 0x20]
//         0051fe6a     MOV        EDX,dword ptr [ESI + 0x484]
//         0051fe70     PUSH       EDX
//         0051fe71     MOV        this,dword ptr [EAX + 0x38]
//         0051fe74     PUSH       this
//         0051fe75     CALL       dword ptr [->GDI32.DLL::SelectObject]            = 0048b192
//                              tpnl_tml.cpp:992 (18)
//         0051fe7b     MOV        EBX,dword ptr [ESI + 0x518]
//         0051fe81     MOV        dword ptr [ESP + 0x10],EAX
//         0051fe85     TEST       EBX,EBX
//         0051fe87     JZ         LAB_0052000d
//                               LAB_0051fe8d                                                 XREF[1]:     00520007(j)
//                              tpnl_tml.cpp:994 (21)
//         0051fe8d     XOR        EAX,EAX
//         0051fe8f     MOV        AL,byte ptr [EBX + 0x12]
//         0051fe92     CMP        EAX,0x8
//         0051fe95     JA         switchD_0051fe9b::caseD_4
//                               switchD_0051fe9b::switchD
//         0051fe9b     JMP        dword ptr [EAX*0x4 + switchD_0051fe9b::switchd   = 0051fea2
//                               switchD_0051fe9b::caseD_0                                    XREF[2]:     0051fe9b(j), 00520058(*)
//                              tpnl_tml.cpp:998 (15)
//         0051fea2     MOV        EDX,dword ptr [ESI + 0x20]
//         0051fea5     PUSH       0x0
//         0051fea7     MOV        EAX,dword ptr [EDX + 0x38]
//         0051feaa     PUSH       EAX
//         0051feab     CALL       dword ptr [->GDI32.DLL::SetTextColor]            = 0048b318
//                              tpnl_tml.cpp:999 (23)
//         0051feb1     MOV        this,dword ptr [EBX + 0x38]
//         0051feb4     MOV        EAX,dword ptr [EBX + 0x2c]
//         0051feb7     LEA        EDX,[EBX + 0x3c]
//         0051feba     PUSH       this
//         0051febb     MOV        this,dword ptr [EBX + 0x28]
//         0051febe     PUSH       EDX
//         0051febf     MOV        EDX,dword ptr [ESI + 0x20]
//         0051fec2     PUSH       EAX
//         0051fec3     PUSH       this
//         0051fec4     MOV        EAX,dword ptr [EDX + 0x38]
//         0051fec7     PUSH       EAX
//                              tpnl_tml.cpp:1000 (5)
//         0051fec8     JMP        LAB_0051fff9
//                               switchD_0051fe9b::caseD_3                                    XREF[2]:     0051fe9b(j), 00520064(*)
//                              tpnl_tml.cpp:1014 (2)
//         0051fecd     MOV        EBP,dword ptr [EBX]
//                              tpnl_tml.cpp:1020 (28)
//         0051fecf     MOV        EDX,dword ptr [ESI + 0x20]
//         0051fed2     NEG        EBP
//         0051fed4     MOV        EAX,dword ptr [EDX + 0x38]
//         0051fed7     PUSH       0xffffff
//         0051fedc     SBB        EBP,EBP
//         0051fede     PUSH       EAX
//         0051fedf     AND        EBP,0xfffffffc
//         0051fee2     ADD        EBP,0x2
//         0051fee5     CALL       dword ptr [->GDI32.DLL::SetTextColor]            = 0048b318
//                              tpnl_tml.cpp:1023 (80)
//         0051feeb     LEA        EDX,[EBX + 0x3c]
//         0051feee     OR         this,0xffffffff
//         0051fef1     MOV        EDI,EDX
//         0051fef3     XOR        EAX,EAX
//         0051fef5     SCASB.RE   ES:EDI
//         0051fef7     NOT        this
//         0051fef9     DEC        this
//         0051fefa     PUSH       this
//         0051fefb     PUSH       EDX
//         0051fefc     MOV        this,ESI
//         0051fefe     CALL       TPanel::yPosition                                long yPosition(TPanel * this)
//         0051ff03     MOV        this,dword ptr [ESI + 0x480]
//         0051ff09     LEA        EDI,[EBX + 0x3c]
//         0051ff0c     LEA        EDX,[EAX + this->_padding_*0x1 + 0x8]
//         0051ff10     OR         this,0xffffffff
//         0051ff13     XOR        EAX,EAX
//         0051ff15     PUSH       EDX
//         0051ff16     SCASB.RE   ES:EDI
//         0051ff18     NOT        this
//         0051ff1a     DEC        this
//         0051ff1b     MOV        EDI,dword ptr [EBX + 0x4]
//         0051ff1e     SHR        this,0x1
//         0051ff20     IMUL       this,dword ptr [ESI + 0x47c]
//         0051ff27     MOV        EAX,EBP
//         0051ff29     SUB        EAX,this
//         0051ff2b     MOV        this,dword ptr [ESI + 0x20]
//         0051ff2e     ADD        EAX,EDI
//         0051ff30     MOV        EDX,dword ptr [ECX + this->_padding_]
//         0051ff33     PUSH       EAX
//         0051ff34     PUSH       EDX
//         0051ff35     CALL       dword ptr [->GDI32.DLL::TextOutA]                = 0048b30c
//                              tpnl_tml.cpp:1027 (90)
//         0051ff3b     LEA        EDX,[EBX + 0x74]
//         0051ff3e     OR         this,0xffffffff
//         0051ff41     MOV        EDI,EDX
//         0051ff43     XOR        EAX,EAX
//         0051ff45     SCASB.RE   ES:EDI
//         0051ff47     NOT        this
//         0051ff49     DEC        this
//         0051ff4a     PUSH       this
//         0051ff4b     PUSH       EDX
//         0051ff4c     MOV        this,ESI
//         0051ff4e     CALL       TPanel::yPosition                                long yPosition(TPanel * this)
//         0051ff53     MOV        this,ESI
//         0051ff55     MOV        EDI,EAX
//         0051ff57     CALL       TPanel::height                                   long height(TPanel * this)
//         0051ff5c     ADD        EDI,EAX
//         0051ff5e     MOV        EAX,dword ptr [ESI + 0x480]
//         0051ff64     SHL        EAX,0x1
//         0051ff66     MOV        this,0xfffffff9
//         0051ff6b     MOV        EDX,dword ptr [ESI + 0x20]
//         0051ff6e     SUB        this,EAX
//         0051ff70     XOR        EAX,EAX
//         0051ff72     ADD        EDI,this
//         0051ff74     OR         this,0xffffffff
//         0051ff77     PUSH       EDI
//         0051ff78     LEA        EDI,[EBX + 0x74]
//         0051ff7b     SCASB.RE   ES:EDI
//         0051ff7d     NOT        this
//         0051ff7f     DEC        this
//         0051ff80     MOV        EDI,dword ptr [EBX + 0x4]
//         0051ff83     SHR        this,0x1
//         0051ff85     IMUL       this,dword ptr [ESI + 0x47c]
//         0051ff8c     MOV        EAX,dword ptr [EDX + 0x38]
//         0051ff8f     SUB        EBP,this
//         0051ff91     ADD        EBP,EDI
//         0051ff93     PUSH       EBP
//         0051ff94     PUSH       EAX
//                              tpnl_tml.cpp:1028 (2)
//         0051ff95     JMP        LAB_0051fff9
//                               switchD_0051fe9b::caseD_6                                    XREF[2]:     0051fe9b(j), 00520070(*)
//                              tpnl_tml.cpp:1031 (10)
//         0051ff97     MOV        EAX,dword ptr [EBX + 0xa8]
//         0051ff9d     TEST       EAX,EAX
//         0051ff9f     JZ         switchD_0051fe9b::caseD_4
//                               switchD_0051fe9b::caseD_1                                    XREF[2]:     0051fe9b(j), 0052005c(*)
//                              tpnl_tml.cpp:1033 (15)
//         0051ffa1     MOV        this,dword ptr [ESI + 0x20]
//         0051ffa4     PUSH       0x0
//         0051ffa6     MOV        EDX,dword ptr [ECX + this->_padding_]
//         0051ffa9     PUSH       EDX
//         0051ffaa     CALL       dword ptr [->GDI32.DLL::SetTextColor]            = 0048b318
//                              tpnl_tml.cpp:1034 (23)
//         0051ffb0     MOV        EAX,dword ptr [EBX + 0x38]
//         0051ffb3     MOV        EDX,dword ptr [EBX + 0x2c]
//         0051ffb6     LEA        this,[EBX + 0x3c]
//         0051ffb9     PUSH       EAX
//         0051ffba     MOV        EAX,dword ptr [EBX + 0x28]
//         0051ffbd     PUSH       this
//         0051ffbe     MOV        this,dword ptr [ESI + 0x20]
//         0051ffc1     PUSH       EDX
//         0051ffc2     PUSH       EAX
//         0051ffc3     MOV        EDX,dword ptr [ECX + this->_padding_]
//         0051ffc6     PUSH       EDX
//                              tpnl_tml.cpp:1036 (2)
//         0051ffc7     JMP        LAB_0051fff9
//                               switchD_0051fe9b::caseD_8                                    XREF[2]:     0051fe9b(j), 00520078(*)
//                              tpnl_tml.cpp:1039 (10)
//         0051ffc9     MOV        EAX,dword ptr [EBX + 0xa8]
//         0051ffcf     TEST       EAX,EAX
//         0051ffd1     JZ         switchD_0051fe9b::caseD_4
//                               switchD_0051fe9b::caseD_2                                    XREF[2]:     0051fe9b(j), 00520060(*)
//                              tpnl_tml.cpp:1041 (15)
//         0051ffd3     MOV        EAX,dword ptr [ESI + 0x20]
//         0051ffd6     PUSH       0x0
//         0051ffd8     MOV        this,dword ptr [EAX + 0x38]
//         0051ffdb     PUSH       this
//         0051ffdc     CALL       dword ptr [->GDI32.DLL::SetTextColor]            = 0048b318
//                              tpnl_tml.cpp:1042 (29)
//         0051ffe2     MOV        EDX,dword ptr [EBX + 0x38]
//         0051ffe5     MOV        this,dword ptr [EBX + 0x2c]
//         0051ffe8     LEA        EAX,[EBX + 0x3c]
//         0051ffeb     PUSH       EDX
//         0051ffec     MOV        EDX,dword ptr [EBX + 0x28]
//         0051ffef     PUSH       EAX
//         0051fff0     MOV        EAX,dword ptr [ESI + 0x20]
//         0051fff3     PUSH       this
//         0051fff4     PUSH       EDX
//         0051fff5     MOV        this,dword ptr [EAX + 0x38]
//         0051fff8     PUSH       this
//                               LAB_0051fff9                                                 XREF[3]:     0051fec8(j), 0051ff95(j),
//                                                                                                         0051ffc7(j)
//         0051fff9     CALL       dword ptr [->GDI32.DLL::TextOutA]                = 0048b30c
//                               switchD_0051fe9b::caseD_5                                    XREF[7]:     0051fe95(j), 0051fe9b(j),
//                               switchD_0051fe9b::caseD_7                                                 0051ff9f(j), 0051ffd1(j),
//                               switchD_0051fe9b::caseD_4                                                 00520068(*), 0052006c(*),
//                                                                                                         00520074(*)
//                              tpnl_tml.cpp:992 (14)
//         0051ffff     MOV        EBX,dword ptr [EBX + 0xac]
//         00520005     TEST       EBX,EBX
//         00520007     JNZ        LAB_0051fe8d
//                               LAB_0052000d                                                 XREF[1]:     0051fe87(j)
//                              tpnl_tml.cpp:1050 (18)
//         0052000d     MOV        EAX,dword ptr [ESI + 0x20]
//         00520010     MOV        EDX,dword ptr [ESP + 0x10]
//         00520014     PUSH       EDX
//         00520015     MOV        this,dword ptr [EAX + 0x38]
//         00520018     PUSH       this
//         00520019     CALL       dword ptr [->GDI32.DLL::SelectObject]            = 0048b192
//                              tpnl_tml.cpp:1051 (13)
//         0052001f     MOV        this,dword ptr [ESI + 0x20]
//         00520022     PUSH       s_tpnl_tml::draw_special_events                  = "tpnl_tml::draw_special_events"
//         00520027     CALL       TDrawArea::ReleaseDc                             void ReleaseDc(TDrawArea * this, char * param
//                               LAB_0052002c                                                 XREF[2]:     0051fd9f(j), 0051fe52(j)
//                              tpnl_tml.cpp:1055 (80)
//         0052002c     POP        EDI
//         0052002d     POP        ESI
//         0052002e     POP        EBP
//         0052002f     POP        EBX
//         00520030     POP        this
//         00520031     RET
    return;
}

void Time_Line_Panel::draw_background() {
    /* TODO: Stub */
//                              void __thiscall draw_background(Time_Line_Panel * this)
//              void              <VOID>         <RETURN>
//              Time_Line_Pane    ECX:4 (auto)   this
//              undefined4        Stack[-0x4]:4  local_4                   XREF[4]:     00520102(R), 00520110(W), 0052015f(R), 00520165(W)
//              short             Stack[-0x8]:2  pic_rows                  XREF[5]:     005200c1(W), 005200cc(W), 005200da(RW), 005200de(R),
//                                                                                     0052015b(R)
//              short             Stack[-0xc]:2  pic_cols
//                               ?draw_background@Time_Line_Panel@@QAEXXZ                     XREF[1]:     draw:0051fa60(c)
//                               Time_Line_Panel::draw_background
//                              tpnl_tml.cpp:1062 (9)
//         00520080     SUB        ESP,0x8
//         00520083     PUSH       EBX
//         00520084     PUSH       EBP
//         00520085     PUSH       ESI
//         00520086     MOV        ESI,this
//         00520088     PUSH       EDI
//                              tpnl_tml.cpp:1069 (14)
//         00520089     MOV        EAX,dword ptr [ESI + 0x4ac]
//         0052008f     TEST       EAX,EAX
//         00520091     JZ         LAB_00520180
//                              tpnl_tml.cpp:1072 (23)
//         00520097     MOV        this,dword ptr [ESI + 0x20]
//         0052009a     PUSH       0x1
//         0052009c     PUSH       s_tpnl_tml::draw_background                      = "tpnl_tml::draw_background"
//         005200a1     CALL       TDrawArea::Lock                                  uchar * Lock(TDrawArea * this, char * param_1
//         005200a6     TEST       EAX,EAX
//         005200a8     JZ         LAB_00520214
//                              tpnl_tml.cpp:1074 (14)
//         005200ae     MOVSX      this,word ptr [ESI + 0x4b0]
//         005200b5     MOV        EDI,dword ptr [ESI + 0x14]
//         005200b8     CMP        this,EDI
//         005200ba     JL         LAB_005200c7
//                              tpnl_tml.cpp:1075 (9)
//         005200bc     MOV        this,0x1
//         005200c1     MOV        dword ptr [ESP + pic_rows],this
//                              tpnl_tml.cpp:1076 (2)
//         005200c5     JMP        LAB_005200e2
//                               LAB_005200c7                                                 XREF[1]:     005200ba(j)
//                              tpnl_tml.cpp:1078 (9)
//         005200c7     MOV        EAX,EDI
//         005200c9     CDQ
//         005200ca     IDIV       this
//         005200cc     MOV        dword ptr [ESP + pic_rows],EAX
//                              tpnl_tml.cpp:1079 (10)
//         005200d0     MOVSX      EAX,AX
//         005200d3     IMUL       EAX,this
//         005200d6     CMP        EAX,EDI
//         005200d8     JGE        LAB_005200de
//                              tpnl_tml.cpp:1080 (8)
//         005200da     INC        dword ptr [ESP + pic_rows]
//                               LAB_005200de                                                 XREF[1]:     005200d8(j)
//         005200de     MOV        this,dword ptr [ESP + pic_rows]
//                               LAB_005200e2                                                 XREF[1]:     005200c5(j)
//                              tpnl_tml.cpp:1083 (14)
//         005200e2     MOVSX      EDI,word ptr [ESI + 0x4b2]
//         005200e9     MOV        EBX,dword ptr [ESI + 0x18]
//         005200ec     CMP        EDI,EBX
//         005200ee     JL         LAB_00520102
//                              tpnl_tml.cpp:1085 (5)
//         005200f0     MOV        EAX,EBX
//         005200f2     CDQ
//         005200f3     IDIV       EDI
//                              tpnl_tml.cpp:1086 (10)
//         005200f5     MOVSX      EDX,AX
//         005200f8     IMUL       EDX,EDI
//         005200fb     CMP        EDX,EBX
//         005200fd     JGE        LAB_00520106
//                              tpnl_tml.cpp:1087 (7)
//         005200ff     INC        EAX
//         00520100     JMP        LAB_00520106
//                               LAB_00520102                                                 XREF[1]:     005200ee(j)
//         00520102     MOV        EAX,dword ptr [ESP + local_4]
//                               LAB_00520106                                                 XREF[2]:     005200fd(j), 00520100(j)
//                              tpnl_tml.cpp:1090 (14)
//         00520106     TEST       AX,AX
//         00520109     JLE        LAB_0052016b
//         0052010b     MOVSX      EAX,AX
//         0052010e     XOR        EBP,EBP
//         00520110     MOV        dword ptr [ESP + local_4],EAX
//                               LAB_00520114                                                 XREF[1]:     00520169(j)
//                              tpnl_tml.cpp:1092 (10)
//         00520114     TEST       this,this
//         00520117     JLE        LAB_0052015f
//         00520119     XOR        EDI,EDI
//         0052011b     MOVSX      EBX,this
//                               LAB_0052011e                                                 XREF[1]:     00520159(j)
//                              tpnl_tml.cpp:1093 (61)
//         0052011e     MOVSX      this,word ptr [ESI + 0x4b2]
//         00520125     MOV        EDX,EBP
//         00520127     MOV        EAX,dword ptr [ESI + 0x10]
//         0052012a     IMUL       EDX,this
//         0052012d     ADD        EDX,EAX
//         0052012f     MOV        this,EDI
//         00520131     MOVSX      EAX,word ptr [ESI + 0x4b0]
//         00520138     IMUL       this,EAX
//         0052013b     MOV        EAX,dword ptr [ESI + 0xc]
//         0052013e     PUSH       0x0
//         00520140     PUSH       0x0
//         00520142     PUSH       0x0
//         00520144     PUSH       EDX
//         00520145     MOV        EDX,dword ptr [ESI + 0x20]
//         00520148     ADD        this,EAX
//         0052014a     PUSH       this
//         0052014b     MOV        this,dword ptr [ESI + 0x4ac]
//         00520151     PUSH       EDX
//         00520152     CALL       TShape::shape_draw                               uchar shape_draw(TShape * this, TDrawArea * p
//         00520157     INC        EDI
//         00520158     DEC        EBX
//         00520159     JNZ        LAB_0052011e
//                              tpnl_tml.cpp:1092 (4)
//         0052015b     MOV        this,dword ptr [ESP + pic_rows]
//                               LAB_0052015f                                                 XREF[1]:     00520117(j)
//                              tpnl_tml.cpp:1090 (12)
//         0052015f     MOV        EAX,dword ptr [ESP + local_4]
//         00520163     INC        EBP
//         00520164     DEC        EAX
//         00520165     MOV        dword ptr [ESP + local_4],EAX
//         00520169     JNZ        LAB_00520114
//                               LAB_0052016b                                                 XREF[1]:     00520109(j)
//                              tpnl_tml.cpp:1096 (13)
//         0052016b     MOV        this,dword ptr [ESI + 0x20]
//         0052016e     PUSH       s_tpnl_tml::draw_background                      = "tpnl_tml::draw_background"
//         00520173     CALL       TDrawArea::Unlock                                void Unlock(TDrawArea * this, char * param_1)
//                              tpnl_tml.cpp:1120 (8)
//         00520178     POP        EDI
//         00520179     POP        ESI
//         0052017a     POP        EBP
//         0052017b     POP        EBX
//         0052017c     ADD        ESP,0x8
//         0052017f     RET
//                               LAB_00520180                                                 XREF[1]:     00520091(j)
//                              tpnl_tml.cpp:1099 (10)
//         00520180     MOV        EAX,dword ptr [ESI + 0x4b4]
//         00520186     TEST       EAX,EAX
//         00520188     JZ         LAB_005201d9
//                              tpnl_tml.cpp:1102 (19)
//         0052018a     MOV        this,dword ptr [ESI + 0x20]
//         0052018d     PUSH       0x1
//         0052018f     PUSH       s_tpnl_tml::draw_background2                     = "tpnl_tml::draw_background2"
//         00520194     CALL       TDrawArea::Lock                                  uchar * Lock(TDrawArea * this, char * param_1
//         00520199     TEST       EAX,EAX
//         0052019b     JZ         LAB_00520214
//                              tpnl_tml.cpp:1104 (39)
//         0052019d     MOV        DL,byte ptr [ESI + 0x4b8]
//         005201a3     MOV        EAX,dword ptr [ESI + 0x10]
//         005201a6     MOV        this,dword ptr [ESI + 0xc]
//         005201a9     PUSH       EDX
//         005201aa     MOV        EDX,dword ptr [ESI + 0x18]
//         005201ad     LEA        EDX,[EDX + EAX*0x1 + -0x1]
//         005201b1     PUSH       EDX
//         005201b2     MOV        EDX,dword ptr [ESI + 0x14]
//         005201b5     LEA        EDX,[EDX + this->_padding_*0x1 + -0x1]
//         005201b9     PUSH       EDX
//         005201ba     PUSH       EAX
//         005201bb     PUSH       this
//         005201bc     MOV        this,dword ptr [ESI + 0x20]
//         005201bf     CALL       TDrawArea::FillRect                              void FillRect(TDrawArea * this, long param_1,
//                              tpnl_tml.cpp:1105 (13)
//         005201c4     MOV        this,dword ptr [ESI + 0x20]
//         005201c7     PUSH       s_tpnl_tml::draw_background2                     = "tpnl_tml::draw_background2"
//         005201cc     CALL       TDrawArea::Unlock                                void Unlock(TDrawArea * this, char * param_1)
//                              tpnl_tml.cpp:1120 (8)
//         005201d1     POP        EDI
//         005201d2     POP        ESI
//         005201d3     POP        EBP
//         005201d4     POP        EBX
//         005201d5     ADD        ESP,0x8
//         005201d8     RET
//                               LAB_005201d9                                                 XREF[1]:     00520188(j)
//                              tpnl_tml.cpp:1111 (7)
//         005201d9     MOV        this,dword ptr [ESI + 0x40]
//         005201dc     TEST       this,this
//         005201de     JZ         LAB_00520214
//                              tpnl_tml.cpp:1113 (16)
//         005201e0     MOV        EAX,dword ptr [ESI + 0x4c8]
//         005201e6     CMP        EAX,0x2
//         005201e9     JL         LAB_00520201
//         005201eb     CMP        EAX,0x7
//         005201ee     JG         LAB_00520201
//                              tpnl_tml.cpp:1114 (9)
//         005201f0     MOV        EAX,dword ptr [this->_padding_]
//         005201f2     ADD        ESI,0x24
//         005201f5     PUSH       ESI
//         005201f6     CALL       dword ptr [EAX + 0x3c]
//                              tpnl_tml.cpp:1120 (8)
//         005201f9     POP        EDI
//         005201fa     POP        ESI
//         005201fb     POP        EBP
//         005201fc     POP        EBX
//         005201fd     ADD        ESP,0x8
//         00520200     RET
//                               LAB_00520201                                                 XREF[2]:     005201e9(j), 005201ee(j)
//                              tpnl_tml.cpp:1115 (10)
//         00520201     MOV        EAX,dword ptr [ECX + this->_padding_]
//         00520207     TEST       EAX,EAX
//         00520209     JNZ        LAB_00520214
//                              tpnl_tml.cpp:1116 (9)
//         0052020b     MOV        EDX,dword ptr [this->_padding_]
//         0052020d     ADD        ESI,0x24
//         00520210     PUSH       ESI
//         00520211     CALL       dword ptr [EDX + 0x34]
//                               LAB_00520214                                                 XREF[4]:     005200a8(j), 0052019b(j),
//                                                                                                         005201de(j), 00520209(j)
//                              tpnl_tml.cpp:1120 (8)
//         00520214     POP        EDI
//         00520215     POP        ESI
//         00520216     POP        EBP
//         00520217     POP        EBX
//         00520218     ADD        ESP,0x8
//         0052021b     RET
//         0052021c     ??         90h
//         0052021d     NOP
//         0052021e     NOP
//         0052021f     NOP
    return;
}

void Time_Line_Panel::draw_civilization_names() {
    /* TODO: Stub */
//                              void __thiscall draw_civilization_names(Time_Line_Panel * this)
//              void              <VOID>         <RETURN>
//              Time_Line_Pane    ECX:4 (auto)   this
//              char[100]         Stack[-0x68]   name_str
//              char[100]         Stack[-0xcc]   civ_str
//              char[100]         Stack[-0x130   temp_str
//              void *            Stack[-0x134   old_font
//              long              Stack[-0x138   X_line_pos
//              long              Stack[-0x13c   Y_line_pos
//              long              Stack[-0x140   y_line_segment_length
//              float             Stack[-0x148   pop_total
//                               ?draw_civilization_names@Time_Line_Panel@@QAEXXZ             XREF[1]:     draw:0051fa83(c)
//                               Time_Line_Panel::draw_civilization_names
//                              tpnl_tml.cpp:1127 (12)
//         00520220     SUB        ESP,0x144
//         00520226     PUSH       EBX
//         00520227     PUSH       EBP
//         00520228     MOV        EBP,this
//         0052022a     PUSH       ESI
//         0052022b     PUSH       EDI
//                              tpnl_tml.cpp:1139 (14)
//         0052022c     MOV        AL,byte ptr [EBP + 0x51c]
//         00520232     TEST       AL,AL
//         00520234     JZ         LAB_00520487
//                              tpnl_tml.cpp:1143 (15)
//         0052023a     MOV        EAX,dword ptr [EBP + 0x20]
//         0052023d     PUSH       0x0
//         0052023f     MOV        this,dword ptr [EAX + 0x38]
//         00520242     PUSH       this
//         00520243     CALL       dword ptr [->GDI32.DLL::SetTextColor]            = 0048b318
//                              tpnl_tml.cpp:1145 (21)
//         00520249     MOV        this,dword ptr [EBP + 0x20]
//         0052024c     PUSH       s_tpnl_tml::draw_civilization_name               = "tpnl_tml::draw_civilization_names"
//         00520251     CALL       TDrawArea::GetDc                                 void * GetDc(TDrawArea * this, char * param_1)
//         00520256     TEST       EAX,EAX
//         00520258     JZ         LAB_00520487
//                              tpnl_tml.cpp:1147 (15)
//         0052025e     MOV        EDX,dword ptr [EBP + 0x20]
//         00520261     PUSH       0x1
//         00520263     MOV        EAX,dword ptr [EDX + 0x38]
//         00520266     PUSH       EAX
//         00520267     CALL       dword ptr [->GDI32.DLL::SetBkMode]               = 0048b340
//                              tpnl_tml.cpp:1148 (20)
//         0052026d     MOV        EDX,dword ptr [EBP + 0x20]
//         00520270     MOV        this,dword ptr [EBP + 0x484]
//         00520276     PUSH       this
//         00520277     MOV        EAX,dword ptr [EDX + 0x38]
//         0052027a     PUSH       EAX
//         0052027b     CALL       dword ptr [->GDI32.DLL::SelectObject]            = 0048b192
//                              tpnl_tml.cpp:1151 (35)
//         00520281     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         00520287     MOV        dword ptr [ESP + 0x24],EAX
//         0052028b     XOR        ESI,ESI
//         0052028d     MOV        dword ptr [ESP + 0x10],0x0
//         00520295     MOV        EAX,dword ptr [ECX + this->_padding_]
//         0052029b     MOVSX      EDX,word ptr [EAX + 0x3c]
//         0052029f     DEC        EDX
//         005202a0     TEST       EDX,EDX
//         005202a2     JLE        LAB_005202ec
//                              tpnl_tml.cpp:1147 (5)
//         005202a4     MOV        EDI,0x4
//                               LAB_005202a9                                                 XREF[1]:     005202ea(j)
//                              tpnl_tml.cpp:1153 (54)
//         005202a9     MOV        EAX,dword ptr [EAX + 0x40]
//         005202ac     PUSH       0x0
//         005202ae     PUSH       0x0
//         005202b0     MOV        this,dword ptr [EAX + EDI*0x1]
//         005202b3     MOV        this,dword ptr [this->_padding_ + 0x83c]
//         005202b9     CALL       TRIBE_History_Info::get_history_entry            uchar get_history_entry(TRIBE_History_Info *
//         005202be     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         005202c4     AND        EAX,0xff
//         005202c9     MOV        dword ptr [ESP + 0x14],EAX
//         005202cd     INC        ESI
//         005202ce     MOV        EAX,dword ptr [ECX + this->_padding_]
//         005202d4     ADD        EDI,0x4
//         005202d7     FILD       dword ptr [ESP + 0x14]
//         005202db     MOVSX      EDX,word ptr [EAX + 0x3c]
//                              tpnl_tml.cpp:1154 (13)
//         005202df     FADD       float ptr [ESP + 0x10]
//         005202e3     DEC        EDX
//         005202e4     CMP        ESI,EDX
//         005202e6     FSTP       float ptr [ESP + 0x10]
//         005202ea     JL         LAB_005202a9
//                               LAB_005202ec                                                 XREF[1]:     005202a2(j)
//                              tpnl_tml.cpp:1156 (21)
//         005202ec     FLD        float ptr [ESP + 0x10]
//         005202f0     FCOMP      float ptr [DAT_005770b8]
//         005202f6     FNSTSW     AX
//         005202f8     TEST       AH,0x40
//         005202fb     JNZ        LAB_00520487
//                              tpnl_tml.cpp:1160 (13)
//         00520301     MOV        EAX,dword ptr [EBP + 0x4dc]
//         00520307     ADD        EAX,0x3
//         0052030a     MOV        dword ptr [ESP + 0x20],EAX
//                              tpnl_tml.cpp:1161 (10)
//         0052030e     MOV        EAX,dword ptr [EBP + 0x4e0]
//         00520314     MOV        dword ptr [ESP + 0x1c],EAX
//                              tpnl_tml.cpp:1164 (19)
//         00520318     MOV        EAX,dword ptr [ECX + this->_padding_]
//         0052031e     MOVSX      this,word ptr [EAX + 0x3c]
//         00520322     DEC        this
//         00520323     TEST       this,this
//         00520325     JLE        LAB_00520468
//                              tpnl_tml.cpp:1185 (317)
//         0052032b     MOV        dword ptr [ESP + 0x14],0x0
//         00520333     MOV        EBX,0x4
//                               LAB_00520338                                                 XREF[1]:     00520462(j)
//         00520338     MOV        EDX,dword ptr [EAX + 0x40]
//         0052033b     PUSH       0x0
//         0052033d     PUSH       0x0=>DAT_fffffff8
//         0052033f     MOV        EAX,dword ptr [EDX + EBX*0x1]
//         00520342     MOV        this,dword ptr [EAX + 0x83c]
//         00520348     CALL       TRIBE_History_Info::get_history_entry            uchar get_history_entry(TRIBE_History_Info *
//         0052034d     AND        EAX,0xff
//         00520352     MOV        dword ptr [ESP + 0x18],EAX
//         00520356     FILD       dword ptr [ESP + 0x18]
//         0052035a     FDIV       float ptr [ESP + 0x10]
//         0052035e     FIMUL      dword ptr [EBP + 0x4f0]
//         00520364     CALL       __ftol                                           undefined __ftol()
//         00520369     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0052036f     MOV        dword ptr [ESP + 0x18],EAX
//         00520373     LEA        EAX,[ESP + 0x8c]
//         0052037a     PUSH       0x64
//         0052037c     PUSH       EAX
//         0052037d     MOV        EAX,dword ptr [ECX + this->_padding_]
//         00520383     MOV        EDX,dword ptr [this->_padding_]
//         00520385     PUSH       0x0
//         00520387     MOV        EAX,dword ptr [EAX + 0x40]
//         0052038a     MOV        ESI,dword ptr [EAX + EBX*0x1]
//         0052038d     XOR        EAX,EAX
//         0052038f     MOV        AL,byte ptr [ESI + 0x105]
//         00520395     PUSH       EAX
//         00520396     PUSH       0x69
//         00520398     CALL       dword ptr [EDX + 0x28]
//         0052039b     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         005203a1     MOV        EDX,dword ptr [ECX + this->_padding_]
//         005203a7     MOV        EAX,dword ptr [EDX + 0x40]
//         005203aa     LEA        EDX,[ESP + 0xf0]
//         005203b1     MOV        this,dword ptr [EAX + EBX*0x1]
//         005203b4     XOR        EAX,EAX
//         005203b6     MOV        EDI,dword ptr [ECX + this->_padding_]
//         005203b9     OR         this,0xffffffff
//         005203bc     SCASB.RE   ES:EDI
//         005203be     NOT        this
//         005203c0     SUB        EDI,this
//         005203c2     MOV        EAX,this
//         005203c4     MOV        ESI,EDI
//         005203c6     MOV        EDI,EDX
//         005203c8     LEA        EDX,[ESP + 0xf0]
//         005203cf     SHR        this,0x2
//         005203d2     MOVSD.REP  ES:EDI,ESI
//         005203d4     MOV        this,EAX
//         005203d6     LEA        EAX,[ESP + 0x28]
//         005203da     AND        this,0x3
//         005203dd     MOVSB.REP  ES:EDI,ESI
//         005203df     LEA        this,[ESP + 0x8c]
//         005203e6     PUSH       this
//         005203e7     PUSH       EDX=>DAT_fffffff8
//         005203e8     PUSH       s_%s_-_%s                                        = "%s - %s"
//         005203ed     PUSH       EAX=>DAT_fffffff0
//         005203ee     CALL       sprintf                                          undefined sprintf()
//         005203f3     LEA        EDI,[ESP + 0x38]
//         005203f7     OR         this,0xffffffff
//         005203fa     XOR        EAX,EAX
//         005203fc     ADD        ESP,0x10
//         005203ff     MOV        ESI,dword ptr [ESP + 0x18]
//         00520403     SCASB.RE   ES:EDI
//         00520405     NOT        this
//         00520407     MOV        EAX,ESI
//         00520409     DEC        this
//         0052040a     CDQ
//         0052040b     PUSH       this
//         0052040c     LEA        this,[ESP + 0x2c]
//         00520410     SUB        EAX,EDX
//         00520412     PUSH       this=>DAT_fffffff8
//         00520413     MOV        this,EAX
//         00520415     MOV        EAX,dword ptr [EBP + 0x48c]
//         0052041b     MOV        EDI,dword ptr [ESP + 0x24]
//         0052041f     CDQ
//         00520420     SUB        EAX,EDX
//         00520422     MOV        EDX,dword ptr [ESP + 0x28]
//         00520426     SAR        this,0x1
//         00520428     SAR        EAX,0x1
//         0052042a     SUB        this,EAX
//         0052042c     ADD        this,EDI
//         0052042e     PUSH       this=>DAT_fffffff4
//         0052042f     PUSH       EDX=>DAT_fffffff0
//         00520430     MOV        EAX,dword ptr [EBP + 0x20]
//         00520433     MOV        this,dword ptr [EAX + 0x38]
//         00520436     PUSH       this
//         00520437     CALL       dword ptr [->GDI32.DLL::TextOutA]                = 0048b30c
//         0052043d     MOV        EDX,dword ptr [rge_base_game]                    = 00000000
//         00520443     MOV        this,dword ptr [ESP + 0x14]
//         00520447     ADD        EDI,ESI
//         00520449     ADD        EBX,0x4
//         0052044c     MOV        EAX,dword ptr [EDX + 0x3f4]
//         00520452     INC        this
//         00520453     MOV        dword ptr [ESP + 0x1c],EDI
//         00520457     MOV        dword ptr [ESP + 0x14],this
//         0052045b     MOVSX      EDX,word ptr [EAX + 0x3c]
//         0052045f     DEC        EDX
//         00520460     CMP        this,EDX
//         00520462     JL         LAB_00520338
//                               LAB_00520468                                                 XREF[1]:     00520325(j)
//                              tpnl_tml.cpp:1181 (18)
//         00520468     MOV        this,dword ptr [EBP + 0x20]
//         0052046b     MOV        EAX,dword ptr [ESP + 0x24]
//         0052046f     PUSH       EAX
//         00520470     MOV        EDX,dword ptr [ECX + this->_padding_]
//         00520473     PUSH       EDX=>DAT_fffffff8
//         00520474     CALL       dword ptr [->GDI32.DLL::SelectObject]            = 0048b192
//                              tpnl_tml.cpp:1182 (13)
//         0052047a     MOV        this,dword ptr [EBP + 0x20]
//         0052047d     PUSH       s_tpnl_tml::draw_civilization_name               = "tpnl_tml::draw_civilization_names"
//         00520482     CALL       TDrawArea::ReleaseDc                             void ReleaseDc(TDrawArea * this, char * param
//                               LAB_00520487                                                 XREF[3]:     00520234(j), 00520258(j),
//                                                                                                         005202fb(j)
//                              tpnl_tml.cpp:1185 (11)
//         00520487     POP        EDI
//         00520488     POP        ESI
//         00520489     POP        EBP
//         0052048a     POP        EBX
//         0052048b     ADD        ESP,0x144
//         00520491     RET
//         00520492     ??         90h
//         00520493     NOP
//         00520494     NOP
//         00520495     NOP
//         00520496     NOP
//         00520497     NOP
//         00520498     NOP
//         00520499     NOP
//         0052049a     NOP
//         0052049b     NOP
//         0052049c     NOP
//         0052049d     NOP
//         0052049e     NOP
//         0052049f     NOP
    return;
}

void Time_Line_Panel::draw_timeline() {
    /* TODO: Stub */
//                              void __thiscall draw_timeline(Time_Line_Panel * this)
//              void              <VOID>         <RETURN>
//              Time_Line_Pane    ECX:4 (auto)   this
//              uchar             Stack[-0x8]:1  temp_color                XREF[4]:     00520563(W), 00520572(R), 005206b4(W), 005206c2(R)
//              long              Stack[-0xc]:4  y_line_segment_length     XREF[2]:     00520732(W), 00520736(R)
//              undefined4        Stack[-0x10]:4 local_10                  XREF[3]:     005204e8(W), 00520754(R), 0052076e(W)
//              long              Stack[-0x14]:4 error_correction_time_sl  XREF[6]:     0052052c(W), 00520590(W), 0052060d(R), 0052076a(W),
//                                                                                     00520774(W), 00520778(R)
//              int               Stack[-0x18]:4 special_event_flag        XREF[1]:     00520784(W)
//              long              Stack[-0x1c]:4 intermediate_x_pos        XREF[1]:     00520780(W)
//              long              Stack[-0x20]:4 cntr2                     XREF[1]:     005207a1(W)
//              long              Stack[-0x24]:4 Y_line_total
//              undefined4        Stack[-0x28]:4 local_28                  XREF[4]:     005204f4(W), 0052050a(R), 0052064a(R), 0052065d(W)
//              long              Stack[-0x2c]:4 time_slice_cntr           XREF[3]:     005204ec(W), 005205f8(R), 0052063d(RW)
//              long              Stack[-0x30]:4 error_correction_drop_ti  XREF[4]:     00520502(W), 005205dc(R), 005205ed(R), 00520633(W)
//              undefined4        Stack[-0x34]:4 local_34                  XREF[1]:     005207bc(W)
//              undefined4        Stack[-0x38]:4 local_38                  XREF[4]:     005204e4(W), 005206f6(R), 00520706(W), 00520727(W)
//              long              Stack[-0x3c]:4 pop_sample_cntr           XREF[5]:     005204f0(W), 00520615(R), 0052062b(W), 00520646(R),
//                                                                                     00520659(W)
//              long              Stack[-0x40]:4 cntr_droped_slice_rate    XREF[1]:     005207a5(W)
//              float             Stack[-0x44]:4 float_remainder           XREF[5]:     00520667(W), 00520678(W), 005206ca(R), 005206d1(W),
//                                                                                     005206db(R)
//              float             Stack[-0x48]:4 next_pop_total            XREF[3]:     005204f8(W), 005206d7(R), 00520a9e(W)
//              long              Stack[-0x4c]:4 time_slice                XREF[2]:     0052057d(W), 005205a0(R)
//              float             Stack[-0x50]:4 temp_pop_num              XREF[6]:     00520524(W), 005205ab(R), 005205b3(W), 005205bc(R),
//                                                                                     00520663(R), 00520714(R)
//              float             Stack[-0x54]:4 pop_total                 XREF[0,1]:   00520567(*)
//              uchar             Stack[-0x55]:1 event
//                               ?draw_timeline@Time_Line_Panel@@QAEXXZ                       XREF[1]:     draw:0051fa75(c)
//                               Time_Line_Panel::draw_timeline
//                              tpnl_tml.cpp:1191 (9)
//         005204a0     SUB        ESP,0x54
//         005204a3     PUSH       EBX
//         005204a4     PUSH       EBP
//         005204a5     PUSH       ESI
//         005204a6     MOV        ESI,this
//         005204a8     PUSH       EDI
//                              tpnl_tml.cpp:1217 (14)
//         005204a9     MOV        AL,byte ptr [ESI + 0x51c]
//         005204af     TEST       AL,AL
//         005204b1     JZ         LAB_00520ab5
//                              tpnl_tml.cpp:1219 (23)
//         005204b7     MOV        this,dword ptr [ESI + 0x20]
//         005204ba     PUSH       0x1
//         005204bc     PUSH       s_tpnl_tml::draw_timeline                        = "tpnl_tml::draw_timeline"
//         005204c1     CALL       TDrawArea::Lock                                  uchar * Lock(TDrawArea * this, char * param_1
//         005204c6     TEST       EAX,EAX
//         005204c8     JZ         LAB_00520aa8
//                              tpnl_tml.cpp:1221 (6)
//         005204ce     MOV        EAX,dword ptr [ESI + 0x4dc]
//                              tpnl_tml.cpp:1222 (8)
//         005204d4     XOR        EBX,EBX
//         005204d6     MOV        dword ptr [ESI + 0x4e4],EAX
//                              tpnl_tml.cpp:1231 (38)
//         005204dc     MOV        EAX,dword ptr [ESI + 0x514]
//         005204e2     CMP        EAX,EBX
//         005204e4     MOV        dword ptr [ESP + local_38],EBX
//         005204e8     MOV        dword ptr [ESP + local_10],EBX
//         005204ec     MOV        dword ptr [ESP + time_slice_cntr],EBX
//         005204f0     MOV        dword ptr [ESP + pop_sample_cntr],EBX
//         005204f4     MOV        dword ptr [ESP + local_28],EBX
//         005204f8     MOV        dword ptr [ESP + next_pop_total],EBX
//         005204fc     JLE        LAB_00520aa8
//                              tpnl_tml.cpp:1221 (8)
//         00520502     MOV        dword ptr [ESP + error_correction_drop_time_sl
//                               LAB_0052050a                                                 XREF[1]:     00520aa2(j)
//                              tpnl_tml.cpp:1231 (18)
//         0052050a     MOV        this,dword ptr [ESP + local_28]
//         0052050e     MOV        EAX,dword ptr [ESI + 0x510]
//         00520514     CMP        this,EAX
//         00520516     JGE        LAB_00520aa8
//                              tpnl_tml.cpp:1237 (35)
//         0052051c     MOV        EDX,dword ptr [rge_base_game]                    = 00000000
//         00520522     XOR        EBP,EBP
//         00520524     MOV        dword ptr [ESP + temp_pop_num],0x0
//         0052052c     MOV        dword ptr [ESP + error_correction_time_slice_t
//         00520530     MOV        EAX,dword ptr [EDX + 0x3f4]
//         00520536     MOVSX      this,word ptr [EAX + 0x3c]
//         0052053a     DEC        this
//         0052053b     TEST       this,this
//         0052053d     JLE        LAB_005205bc
//                              tpnl_tml.cpp:1427 (5)
//         0052053f     MOV        EDI,0x4
//                               LAB_00520544                                                 XREF[1]:     005205ba(j)
//                              tpnl_tml.cpp:1239 (20)
//         00520544     MOV        EDX,dword ptr [EAX + 0x40]
//         00520547     PUSH       EBX
//         00520548     PUSH       0x0
//         0052054a     MOV        EAX,dword ptr [EDX + EDI*0x1]
//         0052054d     MOV        this,dword ptr [EAX + 0x83c]
//         00520553     CALL       TRIBE_History_Info::get_history_entry            uchar get_history_entry(TRIBE_History_Info *
//                              tpnl_tml.cpp:1240 (56)
//         00520558     MOV        EDX,dword ptr [rge_base_game]                    = 00000000
//         0052055e     AND        EAX,0xff
//         00520563     MOV        dword ptr [ESP + temp_color],EAX
//         00520567     LEA        this=>pop_total+0x3,[ESP + 0x13]
//         0052056b     MOV        EAX,dword ptr [EDX + 0x3f4]
//         00520571     PUSH       this
//         00520572     FILD       dword ptr [ESP + temp_color]
//         00520576     MOV        this,dword ptr [EAX + 0x40]
//         00520579     PUSH       EBX
//         0052057a     MOV        EDX,dword ptr [this->_padding_ + EDI*0x1]
//         0052057d     FSTP       float ptr [ESP + time_slice]
//         00520581     MOV        this,dword ptr [EDX + 0x83c]
//         00520587     CALL       TRIBE_History_Info::get_history_event            uchar get_history_event(TRIBE_History_Info *
//         0052058c     TEST       AL,AL
//         0052058e     JZ         LAB_00520598
//                              tpnl_tml.cpp:1241 (8)
//         00520590     MOV        dword ptr [ESP + error_correction_time_slice_t
//                               LAB_00520598                                                 XREF[1]:     0052058e(j)
//                              tpnl_tml.cpp:1237 (8)
//         00520598     MOV        EAX,[rge_base_game]                              = 00000000
//         0052059d     ADD        EDI,0x4
//                              tpnl_tml.cpp:1242 (28)
//         005205a0     FLD        float ptr [ESP + time_slice]
//         005205a4     MOV        EAX,dword ptr [EAX + 0x3f4]
//         005205aa     INC        EBP
//         005205ab     FADD       float ptr [ESP + temp_pop_num]
//         005205af     MOVSX      this,word ptr [EAX + 0x3c]
//         005205b3     FSTP       float ptr [ESP + temp_pop_num]
//         005205b7     DEC        this
//         005205b8     CMP        EBP,this
//         005205ba     JL         LAB_00520544
//                               LAB_005205bc                                                 XREF[1]:     0052053d(j)
//                              tpnl_tml.cpp:1244 (21)
//         005205bc     FLD        float ptr [ESP + temp_pop_num]
//         005205c0     FCOMP      float ptr [DAT_005770b8]
//         005205c6     FNSTSW     AX
//         005205c8     TEST       AH,0x40
//         005205cb     JNZ        LAB_00520ab5
//                              tpnl_tml.cpp:1257 (48)
//         005205d1     FLD        float ptr [ESI + 0x504]
//         005205d7     CALL       __ftol                                           undefined __ftol()
//         005205dc     FILD       dword ptr [ESP + error_correction_drop_time_sl
//         005205e0     MOV        EDI,EAX
//         005205e2     FMUL       float ptr [ESI + 0x504]
//         005205e8     CALL       __ftol                                           undefined __ftol()
//         005205ed     MOV        this,dword ptr [ESP + error_correction_drop_ti
//         005205f1     MOV        EDX,0x1
//         005205f6     SUB        EDX,this
//         005205f8     MOV        EBP,dword ptr [ESP + time_slice_cntr]
//         005205fc     IMUL       EDX,EDI
//         005205ff     ADD        EAX,EDX
//                              tpnl_tml.cpp:1259 (39)
//         00520601     MOV        DL,byte ptr [ESI + 0x50c]
//         00520607     SUB        EAX,EBP
//         00520609     TEST       DL,DL
//         0052060b     JZ         LAB_00520646
//         0052060d     MOV        EDX,dword ptr [ESP + error_correction_time_sli
//         00520611     TEST       EDX,EDX
//         00520613     JNZ        LAB_00520646
//         00520615     CMP        dword ptr [ESP + pop_sample_cntr],EAX
//         00520619     JL         LAB_00520646
//         0052061b     MOV        EBP,dword ptr [ESI + 0x508]
//         00520621     LEA        EDX,[this->_padding_ + -0x1]
//         00520624     CMP        EDX,EBP
//         00520626     JGE        LAB_00520646
//                              tpnl_tml.cpp:1262 (1)
//         00520628     INC        this
//                              tpnl_tml.cpp:1264 (20)
//         00520629     CMP        EAX,EDI
//         0052062b     MOV        dword ptr [ESP + pop_sample_cntr],0x0
//         00520633     MOV        dword ptr [ESP + error_correction_drop_time_sl
//         00520637     JLE        LAB_00520a95
//                              tpnl_tml.cpp:1265 (4)
//         0052063d     INC        dword ptr [ESP + time_slice_cntr]
//                              tpnl_tml.cpp:1266 (5)
//         00520641     JMP        LAB_00520a95
//                               LAB_00520646                                                 XREF[4]:     0052060b(j), 00520613(j),
//                                                                                                         00520619(j), 00520626(j)
//                              tpnl_tml.cpp:1271 (4)
//         00520646     MOV        EBP,dword ptr [ESP + pop_sample_cntr]
//                              tpnl_tml.cpp:1272 (4)
//         0052064a     MOV        EDI,dword ptr [ESP + local_28]
//                              tpnl_tml.cpp:1280 (21)
//         0052064e     MOV        EAX,dword ptr [ESI + 0x510]
//         00520654     INC        EBP
//         00520655     INC        EDI
//         00520656     DEC        EAX
//         00520657     CMP        EBX,EAX
//         00520659     MOV        dword ptr [ESP + pop_sample_cntr],EBP
//         0052065d     MOV        dword ptr [ESP + local_28],EDI
//         00520661     JNZ        LAB_00520670
//                              tpnl_tml.cpp:1283 (8)
//         00520663     MOV        this,dword ptr [ESP + temp_pop_num]
//         00520667     MOV        dword ptr [ESP + float_remainder],this
//                              tpnl_tml.cpp:1285 (5)
//         0052066b     JMP        LAB_005206f0
//                               LAB_00520670                                                 XREF[1]:     00520661(j)
//                              tpnl_tml.cpp:1288 (31)
//         00520670     MOV        EDX,dword ptr [rge_base_game]                    = 00000000
//         00520676     XOR        EBP,EBP
//         00520678     MOV        dword ptr [ESP + float_remainder],0x0
//         00520680     MOV        EAX,dword ptr [EDX + 0x3f4]
//         00520686     MOVSX      this,word ptr [EAX + 0x3c]
//         0052068a     DEC        this
//         0052068b     TEST       this,this
//         0052068d     JLE        LAB_005206db
//                              tpnl_tml.cpp:1290 (1)
//         0052068f     INC        EBX
//                              tpnl_tml.cpp:1427 (71)
//         00520690     MOV        EDI,0x4
//                               LAB_00520695                                                 XREF[1]:     005206d5(j)
//         00520695     MOV        EDX,dword ptr [EAX + 0x40]
//         00520698     PUSH       EBX
//         00520699     PUSH       0x0
//         0052069b     MOV        EAX,dword ptr [EDX + EDI*0x1]
//         0052069e     MOV        this,dword ptr [EAX + 0x83c]
//         005206a4     CALL       TRIBE_History_Info::get_history_entry            uchar get_history_entry(TRIBE_History_Info *
//         005206a9     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         005206af     AND        EAX,0xff
//         005206b4     MOV        dword ptr [ESP + temp_color],EAX
//         005206b8     INC        EBP
//         005206b9     MOV        EAX,dword ptr [ECX + this->_padding_]
//         005206bf     ADD        EDI,0x4
//         005206c2     FILD       dword ptr [ESP + temp_color]
//         005206c6     MOVSX      EDX,word ptr [EAX + 0x3c]
//         005206ca     FADD       float ptr [ESP + float_remainder]
//         005206ce     DEC        EDX
//         005206cf     CMP        EBP,EDX
//         005206d1     FSTP       float ptr [ESP + float_remainder]
//         005206d5     JL         LAB_00520695
//                              tpnl_tml.cpp:1288 (4)
//         005206d7     MOV        EBX,dword ptr [ESP + next_pop_total]
//                               LAB_005206db                                                 XREF[1]:     0052068d(j)
//                              tpnl_tml.cpp:1293 (21)
//         005206db     FLD        float ptr [ESP + float_remainder]
//         005206df     FCOMP      float ptr [DAT_005770b8]
//         005206e5     FNSTSW     AX
//         005206e7     TEST       AH,0x40
//         005206ea     JNZ        LAB_00520ab5
//                               LAB_005206f0                                                 XREF[1]:     0052066b(j)
//                              tpnl_tml.cpp:1298 (19)
//         005206f0     MOV        EAX,dword ptr [ESI + 0x500]
//         005206f6     MOV        this,dword ptr [ESP + local_38]
//         005206fa     DEC        EAX
//         005206fb     CMP        this,EAX
//         005206fd     JZ         LAB_0052070c
//         005206ff     TEST       EBX,EBX
//         00520701     JZ         LAB_0052070c
//                              tpnl_tml.cpp:1306 (9)
//         00520703     MOV        EAX,this
//         00520705     INC        EAX
//         00520706     MOV        dword ptr [ESP + local_38],EAX
//         0052070a     JMP        LAB_0052072f
//                               LAB_0052070c                                                 XREF[2]:     005206fd(j), 00520701(j)
//                              tpnl_tml.cpp:1300 (27)
//         0052070c     MOV        this,dword ptr [ESI + 0x4e4]
//         00520712     PUSH       0x1
//         00520714     FLD        float ptr [ESP + temp_pop_num]
//         00520718     PUSH       this
//         00520719     CALL       __ftol                                           undefined __ftol()
//         0052071e     PUSH       EAX
//         0052071f     PUSH       EBX
//         00520720     MOV        this,ESI
//         00520722     CALL       Time_Line_Panel::add_pop_total_special_event     void add_pop_total_special_event(Time_Line_Pa
//                              tpnl_tml.cpp:1301 (8)
//         00520727     MOV        dword ptr [ESP + local_38],0x0
//                               LAB_0052072f                                                 XREF[1]:     0052070a(j)
//                              tpnl_tml.cpp:1309 (22)
//         0052072f     LEA        EBP,[EBX + 0x1]
//         00520732     MOV        dword ptr [ESP + y_line_segment_length],EBP
//         00520736     FILD       dword ptr [ESP + y_line_segment_length]
//         0052073a     FMUL       float ptr [ESI + 0x4fc]
//         00520740     CALL       __ftol                                           undefined __ftol()
//                              tpnl_tml.cpp:1310 (15)
//         00520745     FLD        float ptr [ESI + 0x4fc]
//         0052074b     MOV        EDI,EAX
//         0052074d     CALL       __ftol                                           undefined __ftol()
//         00520752     MOV        this,EAX
//                              tpnl_tml.cpp:1311 (15)
//         00520754     MOV        EDX,dword ptr [ESP + local_10]
//         00520758     IMUL       this,EBP
//         0052075b     MOV        EBP,EDI
//         0052075d     SUB        EBP,EDX
//         0052075f     CMP        this,EBP
//         00520761     JGE        LAB_00520774
//                              tpnl_tml.cpp:1313 (6)
//         00520763     SUB        EDI,EDX
//         00520765     SUB        EDI,this
//         00520767     ADD        EDI,EAX
//                              tpnl_tml.cpp:1314 (9)
//         00520769     INC        EDX
//         0052076a     MOV        dword ptr [ESP + error_correction_time_slice_t
//         0052076e     MOV        dword ptr [ESP + local_10],EDX
//                              tpnl_tml.cpp:1316 (2)
//         00520772     JMP        LAB_00520778
//                               LAB_00520774                                                 XREF[1]:     00520761(j)
//                              tpnl_tml.cpp:1317 (4)
//         00520774     MOV        dword ptr [ESP + error_correction_time_slice_t
//                               LAB_00520778                                                 XREF[1]:     00520772(j)
//                              tpnl_tml.cpp:1320 (22)
//         00520778     MOV        this,dword ptr [ESP + error_correction_time_sl
//         0052077c     XOR        EAX,EAX
//         0052077e     CMP        this,EAX
//         00520780     MOV        dword ptr [ESP + intermediate_x_pos],EAX
//         00520784     MOV        dword ptr [ESP + special_event_flag],EAX
//         00520788     JLE        LAB_00520a95
//                               LAB_0052078e                                                 XREF[1]:     00520a8f(j)
//                              tpnl_tml.cpp:1325 (14)
//         0052078e     MOV        EDX,dword ptr [ESI + 0x4e0]
//         00520794     XOR        this,this
//         00520796     MOV        dword ptr [ESI + 0x4e8],EDX
//                              tpnl_tml.cpp:1329 (41)
//         0052079c     MOV        EAX,[rge_base_game]                              = 00000000
//         005207a1     MOV        dword ptr [ESP + cntr2],this
//         005207a5     MOV        dword ptr [ESP + cntr_droped_slice_rate],this
//         005207a9     MOV        EAX,dword ptr [EAX + 0x3f4]
//         005207af     MOVSX      EDX,word ptr [EAX + 0x3c]
//         005207b3     DEC        EDX
//         005207b4     TEST       EDX,EDX
//         005207b6     JLE        LAB_00520a6a
//         005207bc     MOV        dword ptr [ESP + local_34],this
//         005207c0     MOV        EBX,0x4
//                               LAB_005207c5                                                 XREF[1]:     00520a60(j)
//                              tpnl_tml.cpp:1332 (28)
//         005207c5     MOV        EAX,dword ptr [EAX + 0x40]
//         005207c8     MOV        this,dword ptr [EAX + EBX*0x1]
//         005207cb     MOV        EDX,dword ptr [ECX + this->_padding_]
//         005207d1     MOVSX      EAX,word ptr [EDX + 0x26]
//         005207d5     CMP        EAX,0x7
//         005207d8     JA         switchD_005207da::default
//                               switchD_005207da::switchD
//         005207da     JMP        dword ptr [EAX*0x4 + switchD_005207da::switchd   = 005207e1
//                               switchD_005207da::caseD_0                                    XREF[2]:     005207da(j), 00520ac0(*)
//                              tpnl_tml.cpp:1335 (7)
//         005207e1     MOV        EAX,0xc40000
//         005207e6     JMP        LAB_0052081e
//                               switchD_005207da::caseD_1                                    XREF[2]:     005207da(j), 00520ac4(*)
//                              tpnl_tml.cpp:1336 (7)
//         005207e8     MOV        EAX,0xc8
//         005207ed     JMP        LAB_0052081e
//                               switchD_005207da::caseD_2                                    XREF[2]:     005207da(j), 00520ac8(*)
//                              tpnl_tml.cpp:1337 (7)
//         005207ef     MOV        EAX,0xeaea
//         005207f4     JMP        LAB_0052081e
//                               switchD_005207da::caseD_3                                    XREF[2]:     005207da(j), 00520acc(*)
//                              tpnl_tml.cpp:1338 (7)
//         005207f6     MOV        EAX,0x215a8c
//         005207fb     JMP        LAB_0052081e
//                               switchD_005207da::caseD_4                                    XREF[2]:     005207da(j), 00520ad0(*)
//                              tpnl_tml.cpp:1339 (7)
//         005207fd     MOV        EAX,0x80ff
//         00520802     JMP        LAB_0052081e
//                               switchD_005207da::caseD_5                                    XREF[2]:     005207da(j), 00520ad4(*)
//                              tpnl_tml.cpp:1340 (7)
//         00520804     MOV        EAX,0x8000
//         00520809     JMP        LAB_0052081e
//                               switchD_005207da::caseD_6                                    XREF[2]:     005207da(j), 00520ad8(*)
//                              tpnl_tml.cpp:1341 (7)
//         0052080b     MOV        EAX,pathSystem.MGP_openPaths[54981].total
//         00520810     JMP        LAB_0052081e
//                               switchD_005207da::caseD_7                                    XREF[2]:     005207da(j), 00520adc(*)
//                              tpnl_tml.cpp:1342 (7)
//         00520812     MOV        EAX,pathSystem.MGP_openPaths[54973].total
//         00520817     JMP        LAB_0052081e
//                               switchD_005207da::default                                    XREF[1]:     005207d8(j)
//                              tpnl_tml.cpp:1343 (5)
//         00520819     MOV        EAX,0xffffff
//                               LAB_0052081e                                                 XREF[8]:     005207e6(j), 005207ed(j),
//                                                                                                         005207f4(j), 005207fb(j),
//                                                                                                         00520802(j), 00520809(j),
//                                                                                                         00520810(j), 00520817(j)
//                              tpnl_tml.cpp:1346 (16)
//         0052081e     PUSH       EAX=>pathSystem.MGP_openPaths[54973].total
//         0052081f     MOV        EAX,dword ptr [ESI + 0x20]
//         00520822     MOV        this,dword ptr [EAX]
//         00520824     MOV        EDX,dword ptr [ECX + this->_padding_]
//         00520827     PUSH       EDX
//         00520828     CALL       dword ptr [->GDI32.DLL::GetNearestPaletteIndex]  = 0048b294
//                              tpnl_tml.cpp:1349 (45)
//         0052082e     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         00520834     MOV        byte ptr [ESP + 0x60],AL
//         00520838     MOV        EAX,dword ptr [ESP + 0x1c]
//         0052083c     MOV        EDX,dword ptr [ECX + this->_padding_]
//         00520842     PUSH       EAX
//         00520843     PUSH       0x0
//         00520845     MOV        EAX,dword ptr [EDX + 0x40]
//         00520848     MOV        this,dword ptr [EAX + EBX*0x1]
//         0052084b     MOV        this,dword ptr [this->_padding_ + 0x83c]
//         00520851     CALL       TRIBE_History_Info::get_history_entry            uchar get_history_entry(TRIBE_History_Info *
//         00520856     AND        EAX,0xff
//                              tpnl_tml.cpp:1350 (39)
//         0052085b     MOV        EBP,dword ptr [ESI + 0x4f0]
//         00520861     MOV        dword ptr [ESP + 0x5c],EAX
//         00520865     MOV        dword ptr [ESP + 0x40],EBP
//         00520869     FILD       dword ptr [ESP + 0x5c]
//         0052086d     FSTP       float ptr [ESP + 0x18]
//         00520871     FLD        float ptr [ESP + 0x18]
//         00520875     FDIV       float ptr [ESP + 0x14]
//         00520879     FIMUL      dword ptr [ESP + 0x40]
//         0052087d     CALL       __ftol                                           undefined __ftol()
//                              tpnl_tml.cpp:1352 (28)
//         00520882     FLD        float ptr [ESP + 0x18]
//         00520886     FCOMP      float ptr [DAT_005770b0]                         = align(2)
//         0052088c     MOV        EDI,EAX
//         0052088e     MOV        dword ptr [ESP + 0x5c],EDI
//         00520892     FNSTSW     AX
//         00520894     TEST       AH,0x1
//         00520897     JNZ        LAB_005208a7
//         00520899     CMP        EDI,0x1
//         0052089c     JGE        LAB_005208a7
//                              tpnl_tml.cpp:1353 (9)
//         0052089e     MOV        EDI,0x1
//         005208a3     MOV        dword ptr [ESP + 0x5c],EDI
//                               LAB_005208a7                                                 XREF[2]:     00520897(j), 0052089c(j)
//                              tpnl_tml.cpp:1355 (16)
//         005208a7     CMP        dword ptr [ESI + 0x4fc],0x3f800000
//         005208b1     JZ         LAB_00520994
//                              tpnl_tml.cpp:1358 (15)
//         005208b7     MOV        EDX,dword ptr [ESI + 0x510]
//         005208bd     MOV        EAX,dword ptr [ESP + 0x1c]
//         005208c1     DEC        EDX
//         005208c2     CMP        EAX,EDX
//         005208c4     JNZ        LAB_005208cc
//                              tpnl_tml.cpp:1361 (4)
//         005208c6     FLD        float ptr [ESP + 0x18]
//                              tpnl_tml.cpp:1363 (2)
//         005208ca     JMP        LAB_005208fd
//                               LAB_005208cc                                                 XREF[1]:     005208c4(j)
//                              tpnl_tml.cpp:1365 (49)
//         005208cc     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         005208d2     MOV        EAX,dword ptr [ESP + 0x58]
//         005208d6     PUSH       EAX
//         005208d7     PUSH       0x0
//         005208d9     MOV        EDX,dword ptr [ECX + this->_padding_]
//         005208df     MOV        EAX,dword ptr [EDX + 0x40]
//         005208e2     MOV        this,dword ptr [EAX + EBX*0x1]
//         005208e5     MOV        this,dword ptr [this->_padding_ + 0x83c]
//         005208eb     CALL       TRIBE_History_Info::get_history_entry            uchar get_history_entry(TRIBE_History_Info *
//         005208f0     AND        EAX,0xff
//         005208f5     MOV        dword ptr [ESP + 0x40],EAX
//         005208f9     FILD       dword ptr [ESP + 0x40]
//                               LAB_005208fd                                                 XREF[1]:     005208ca(j)
//                              tpnl_tml.cpp:1367 (25)
//         005208fd     FDIV       float ptr [ESP + 0x20]
//         00520901     MOV        EBP,dword ptr [ESI + 0x4f0]
//         00520907     MOV        dword ptr [ESP + 0x40],EBP
//         0052090b     FILD       dword ptr [ESP + 0x40]
//         0052090f     FMULP
//         00520911     CALL       __ftol                                           undefined __ftol()
//                              tpnl_tml.cpp:1376 (32)
//         00520916     FILD       dword ptr [ESP + 0x4c]
//         0052091a     SUB        EAX,EDI
//         0052091c     MOV        dword ptr [ESP + 0x40],EAX
//         00520920     FDIV       float ptr [ESI + 0x4fc]
//         00520926     FILD       dword ptr [ESP + 0x40]
//         0052092a     FILD       dword ptr [ESP + 0x5c]
//         0052092e     FXCH
//         00520930     FMULP      ST2
//         00520932     FADDP
//         00520934     FLD        ST0
//                              tpnl_tml.cpp:1380 (7)
//         00520936     FXCH
//         00520938     CALL       __ftol                                           undefined __ftol()
//                              tpnl_tml.cpp:1382 (28)
//         0052093d     FLD        float ptr [ESP + 0x18]
//         00520941     FCOMP      float ptr [DAT_005770b0]                         = align(2)
//         00520947     MOV        EDI,EAX
//         00520949     MOV        dword ptr [ESP + 0x5c],EDI
//         0052094d     FNSTSW     AX
//         0052094f     TEST       AH,0x1
//         00520952     JNZ        LAB_00520962
//         00520954     CMP        EDI,0x1
//         00520957     JGE        LAB_00520962
//                              tpnl_tml.cpp:1383 (9)
//         00520959     MOV        EDI,0x1
//         0052095e     MOV        dword ptr [ESP + 0x5c],EDI
//                               LAB_00520962                                                 XREF[2]:     00520952(j), 00520957(j)
//                              tpnl_tml.cpp:1387 (18)
//         00520962     FLD        float ptr [ESP + 0x24]
//         00520966     FADD       ST0,ST1
//         00520968     FILD       dword ptr [ESP + 0x5c]
//         0052096c     FSUBP
//         0052096e     FSTP       float ptr [ESP + 0x24]
//         00520972     FSTP       ST0
//                              tpnl_tml.cpp:1390 (17)
//         00520974     FLD        float ptr [ESP + 0x24]
//         00520978     FCOMP      double ptr [DAT_005770c0]
//         0052097e     FNSTSW     AX
//         00520980     TEST       AH,0x41
//         00520983     JNZ        LAB_00520994
//                              tpnl_tml.cpp:1393 (15)
//         00520985     FLD        float ptr [ESP + 0x24]
//         00520989     FSUB       float ptr [DAT_005770b0]                         = align(2)
//         0052098f     INC        EDI
//         00520990     FSTP       float ptr [ESP + 0x24]
//                               LAB_00520994                                                 XREF[2]:     005208b1(j), 00520983(j)
//                              tpnl_tml.cpp:1398 (27)
//         00520994     MOV        EDX,dword ptr [rge_base_game]                    = 00000000
//         0052099a     MOV        EAX,dword ptr [EDX + 0x3f4]
//         005209a0     MOVSX      this,word ptr [EAX + 0x3c]
//         005209a4     MOV        EAX,dword ptr [ESP + 0x30]
//         005209a8     SUB        this,0x2
//         005209ab     CMP        EAX,this
//         005209ad     JNZ        LAB_005209c9
//                              tpnl_tml.cpp:1401 (11)
//         005209af     MOV        EAX,dword ptr [ESP + 0x44]
//         005209b3     LEA        EDX,[EDI + EAX*0x1]
//         005209b6     CMP        EDX,EBP
//         005209b8     JLE        LAB_005209be
//                              tpnl_tml.cpp:1402 (4)
//         005209ba     MOV        EDI,EBP
//         005209bc     SUB        EDI,EAX
//                               LAB_005209be                                                 XREF[1]:     005209b8(j)
//                              tpnl_tml.cpp:1404 (7)
//         005209be     LEA        this,[EDI + EAX*0x1]
//         005209c1     CMP        this,EBP
//         005209c3     JGE        LAB_005209c9
//                              tpnl_tml.cpp:1405 (4)
//         005209c5     SUB        EBP,EAX
//         005209c7     MOV        EDI,EBP
//                               LAB_005209c9                                                 XREF[2]:     005209ad(j), 005209c3(j)
//                              tpnl_tml.cpp:1409 (28)
//         005209c9     MOV        EBP,dword ptr [ESP + 0x60]
//         005209cd     MOV        EDX,dword ptr [ESI + 0x4e8]
//         005209d3     MOV        EAX,dword ptr [ESI + 0x4e4]
//         005209d9     MOV        this,dword ptr [ESI + 0x20]
//         005209dc     PUSH       EBP
//         005209dd     PUSH       EDI
//         005209de     PUSH       EDX
//         005209df     PUSH       EAX
//         005209e0     CALL       TDrawArea::DrawVertLine                          void DrawVertLine(TDrawArea * this, long para
//                              tpnl_tml.cpp:1412 (8)
//         005209e5     MOV        EAX,dword ptr [ESP + 0x48]
//         005209e9     TEST       EAX,EAX
//         005209eb     JNZ        LAB_00520a29
//                              tpnl_tml.cpp:1413 (60)
//         005209ed     MOV        this,dword ptr [ESI + 0x4e8]
//         005209f3     MOV        EDX,dword ptr [ESI + 0x4e4]
//         005209f9     MOV        EAX,dword ptr [ESP + 0x1c]
//         005209fd     PUSH       EDI
//         005209fe     PUSH       this
//         005209ff     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         00520a05     PUSH       EDX
//         00520a06     PUSH       EAX
//         00520a07     MOV        EDX,dword ptr [ECX + this->_padding_]
//         00520a0d     PUSH       EBP
//         00520a0e     MOV        EAX,dword ptr [EDX + 0x40]
//         00520a11     MOV        this,dword ptr [EAX + EBX*0x1]
//         00520a14     MOV        AL,byte ptr [ESP + 0x44]
//         00520a18     INC        AL
//         00520a1a     MOV        EDX,dword ptr [this->_padding_ + 0x83c]
//         00520a20     MOV        this,ESI
//         00520a22     PUSH       EDX
//         00520a23     PUSH       EAX
//         00520a24     CALL       Time_Line_Panel::record_special_event            void record_special_event(Time_Line_Panel * t
//                               LAB_00520a29                                                 XREF[1]:     005209eb(j)
//                              tpnl_tml.cpp:1417 (61)
//         00520a29     MOV        EDX,dword ptr [ESI + 0x4e8]
//         00520a2f     MOV        EBP,dword ptr [ESP + 0x44]
//         00520a33     ADD        EDX,EDI
//         00520a35     MOV        this,dword ptr [ESP + 0x30]
//         00520a39     MOV        dword ptr [ESI + 0x4e8],EDX
//         00520a3f     MOV        EDX,dword ptr [rge_base_game]                    = 00000000
//         00520a45     ADD        EBP,EDI
//         00520a47     ADD        EBX,0x4
//         00520a4a     MOV        EAX,dword ptr [EDX + 0x3f4]
//         00520a50     INC        this
//         00520a51     MOV        dword ptr [ESP + 0x44],EBP
//         00520a55     MOV        dword ptr [ESP + 0x30],this
//         00520a59     MOVSX      EDX,word ptr [EAX + 0x3c]
//         00520a5d     DEC        EDX
//         00520a5e     CMP        this,EDX
//         00520a60     JL         LAB_005207c5
//                              tpnl_tml.cpp:1329 (4)
//         00520a66     MOV        EBX,dword ptr [ESP + 0x1c]
//                               LAB_00520a6a                                                 XREF[1]:     005207b6(j)
//                              tpnl_tml.cpp:1420 (43)
//         00520a6a     MOV        EBP,dword ptr [ESI + 0x4e4]
//         00520a70     MOV        EAX,dword ptr [ESP + 0x48]
//         00520a74     MOV        EDX,dword ptr [ESP + 0x4c]
//         00520a78     MOV        this,dword ptr [ESP + 0x50]
//         00520a7c     INC        EBP
//         00520a7d     INC        EAX
//         00520a7e     INC        EDX
//         00520a7f     CMP        EAX,this
//         00520a81     MOV        dword ptr [ESI + 0x4e4],EBP
//         00520a87     MOV        dword ptr [ESP + 0x48],EAX
//         00520a8b     MOV        dword ptr [ESP + 0x4c],EDX
//         00520a8f     JL         LAB_0052078e
//                               LAB_00520a95                                                 XREF[3]:     00520637(j), 00520641(j),
//                                                                                                         00520788(j)
//                              tpnl_tml.cpp:1231 (19)
//         00520a95     MOV        EAX,dword ptr [ESI + 0x514]
//         00520a9b     INC        EBX
//         00520a9c     CMP        EBX,EAX
//         00520a9e     MOV        dword ptr [ESP + next_pop_total],EBX
//         00520aa2     JL         LAB_0052050a
//                               LAB_00520aa8                                                 XREF[3]:     005204c8(j), 005204fc(j),
//                                                                                                         00520516(j)
//                              tpnl_tml.cpp:1425 (13)
//         00520aa8     MOV        this,dword ptr [ESI + 0x20]
//         00520aab     PUSH       s_tpnl_tml::draw_timeline                        = "tpnl_tml::draw_timeline"
//         00520ab0     CALL       TDrawArea::Unlock                                void Unlock(TDrawArea * this, char * param_1)
//                               LAB_00520ab5                                                 XREF[3]:     005204b1(j), 005205cb(j),
//                                                                                                         005206ea(j)
//                              tpnl_tml.cpp:1427 (43)
//         00520ab5     POP        EDI
//         00520ab6     POP        ESI
//         00520ab7     POP        EBP
//         00520ab8     POP        EBX
//         00520ab9     ADD        ESP,0x54
//         00520abc     RET
    return;
}

void Time_Line_Panel::draw_icon(Special_Events* param_1, short param_2, uchar param_3) {
    /* TODO: Stub */
//                              void __thiscall draw_icon(Time_Line_Panel * this, Special_Events * p
//              void              <VOID>         <RETURN>
//              Time_Line_Pane    ECX:4 (auto)   this
//              Special_Events    Stack[0x4]:4   param_1                   XREF[1]:     00520b0c(R)
//              short             Stack[0x8]:2   param_2                   XREF[1]:     00520c6d(R)
//              uchar             Stack[0xc]:1   param_3                   XREF[1]:     00520c69(R)
//              char[50]          Stack[-0x38]   temp_str                  XREF[4,8]:   00520b10(W), 00520cbc(R), 00520cdf(R), 00520d02(R),
//                                                                                     00520b29(*), 00520b42(*), 00520b5b(*), 00520b72(*),
//                                                                                     00520b9e(*), 00520bb0(*), 00520c34(*), 00520c46(*)
//              uchar             Stack[-0x3c]:1 black_color
//                               ?draw_icon@Time_Line_Panel@@QAEXPAUSpecial_Events@@FE@Z      XREF[1]:     draw_special_events:0051fe27(c)
//                               Time_Line_Panel::draw_icon
//                              tpnl_tml.cpp:1433 (8)
//         00520ae0     SUB        ESP,0x38
//         00520ae3     PUSH       EBX
//         00520ae4     MOV        EBX,this
//         00520ae6     PUSH       EBP
//         00520ae7     PUSH       ESI
//                              tpnl_tml.cpp:1443 (23)
//         00520ae8     MOV        EAX,dword ptr [EBX + 0x20]
//         00520aeb     MOV        ESI,dword ptr [->GDI32.DLL::GetNearestPaletteI   = 0048b294
//         00520af1     PUSH       EDI
//         00520af2     PUSH       0xffffff
//         00520af7     MOV        this,dword ptr [EAX]
//         00520af9     MOV        EDX,dword ptr [ECX + this->_padding_]
//         00520afc     PUSH       EDX
//         00520afd     CALL       ESI=>GDI32.DLL::GetNearestPaletteIndex
//                              tpnl_tml.cpp:1445 (13)
//         00520aff     MOV        EAX,dword ptr [EBX + 0x20]
//         00520b02     PUSH       0x0
//         00520b04     MOV        this,dword ptr [EAX]
//         00520b06     MOV        EDX,dword ptr [ECX + this->_padding_]
//         00520b09     PUSH       EDX
//         00520b0a     CALL       ESI=>GDI32.DLL::GetNearestPaletteIndex
//                              tpnl_tml.cpp:1448 (29)
//         00520b0c     MOV        ESI,dword ptr [ESP + param_1]
//         00520b10     MOV        byte ptr [ESP + temp_str[0]],AL
//         00520b14     XOR        EAX,EAX
//         00520b16     MOV        AL,byte ptr [ESI + 0x12]
//         00520b19     CMP        EAX,0x8
//         00520b1c     JA         switchD_00520b22::caseD_6
//                               switchD_00520b22::switchD
//         00520b22     JMP        dword ptr [EAX*0x4 + switchD_00520b22::switchd   = 00520b29
//                               switchD_00520b22::caseD_0                                    XREF[2]:     00520b22(j), 00520d28(*)
//                              tpnl_tml.cpp:1452 (23)
//         00520b29     LEA        EAX=>temp_str[4],[ESP + 0x14]
//         00520b2d     PUSH       0x32
//         00520b2f     PUSH       EAX
//                              language.dll match for 0x106a: "Tool Age"
//         00520b30     PUSH       0x106a
//         00520b35     MOV        this,EBX
//         00520b37     CALL       TPanel::get_string                               int get_string(TPanel * this, int param_1, ch
//         00520b3c     TEST       EAX,EAX
//         00520b3e     JZ         switchD_00520b22::caseD_4
//                              tpnl_tml.cpp:1456 (2)
//         00520b40     JMP        LAB_00520b72
//                               switchD_00520b22::caseD_1                                    XREF[2]:     00520b22(j), 00520d2c(*)
//                              tpnl_tml.cpp:1461 (23)
//         00520b42     LEA        EAX=>temp_str[4],[ESP + 0x14]
//         00520b46     PUSH       0x32
//         00520b48     PUSH       EAX
//                              language.dll match for 0x106b: "Bronze Age"
//         00520b49     PUSH       0x106b
//         00520b4e     MOV        this,EBX
//         00520b50     CALL       TPanel::get_string                               int get_string(TPanel * this, int param_1, ch
//         00520b55     TEST       EAX,EAX
//         00520b57     JZ         switchD_00520b22::caseD_4
//                              tpnl_tml.cpp:1465 (2)
//         00520b59     JMP        LAB_00520b72
//                               switchD_00520b22::caseD_2                                    XREF[2]:     00520b22(j), 00520d30(*)
//                              tpnl_tml.cpp:1470 (23)
//         00520b5b     LEA        EAX=>temp_str[4],[ESP + 0x14]
//         00520b5f     PUSH       0x32
//         00520b61     PUSH       EAX
//                              language.dll match for 0x106c: "Iron Age"
//         00520b62     PUSH       0x106c
//         00520b67     MOV        this,EBX
//         00520b69     CALL       TPanel::get_string                               int get_string(TPanel * this, int param_1, ch
//         00520b6e     TEST       EAX,EAX
//         00520b70     JZ         switchD_00520b22::caseD_4
//                               LAB_00520b72                                                 XREF[2]:     00520b40(j), 00520b59(j)
//                              tpnl_tml.cpp:1472 (22)
//         00520b72     LEA        this=>temp_str[4],[ESP + 0x14]
//         00520b76     LEA        EDX,[ESI + 0x3c]
//         00520b79     PUSH       this
//         00520b7a     PUSH       s_%s                                             = "%s"
//         00520b7f     PUSH       EDX
//         00520b80     CALL       sprintf                                          undefined sprintf()
//         00520b85     ADD        ESP,0xc
//                              tpnl_tml.cpp:1474 (5)
//         00520b88     JMP        switchD_00520b22::caseD_6
//                               switchD_00520b22::caseD_5                                    XREF[7]:     00520b22(j), 00520b3e(j),
//                               switchD_00520b22::caseD_7                                                 00520b57(j), 00520b70(j),
//                               switchD_00520b22::caseD_4                                                 00520d38(*), 00520d3c(*),
//                                                                                                         00520d44(*)
//                              tpnl_tml.cpp:1489 (4)
//         00520b8d     MOV        byte ptr [ESI + 0x3c],0x0
//                              tpnl_tml.cpp:1490 (5)
//         00520b91     JMP        switchD_00520b22::caseD_6
//                               switchD_00520b22::caseD_8                                    XREF[2]:     00520b22(j), 00520d48(*)
//                              tpnl_tml.cpp:1492 (26)
//         00520b96     MOV        EAX,dword ptr [ESI + 0x1c]
//         00520b99     MOV        this,dword ptr [ESI + 0x18]
//         00520b9c     PUSH       EAX
//         00520b9d     PUSH       this
//         00520b9e     LEA        EDX=>temp_str[4],[ESP + 0x1c]
//         00520ba2     PUSH       s_%ld/%1d                                        = "%ld/%1d"
//         00520ba7     PUSH       EDX
//         00520ba8     CALL       sprintf                                          undefined sprintf()
//         00520bad     ADD        ESP,0x10
//                              tpnl_tml.cpp:1493 (22)
//         00520bb0     LEA        EAX=>temp_str[4],[ESP + 0x14]
//         00520bb4     LEA        this,[ESI + 0x3c]
//         00520bb7     PUSH       EAX
//         00520bb8     PUSH       s_%s                                             = "%s"
//         00520bbd     PUSH       this
//         00520bbe     CALL       sprintf                                          undefined sprintf()
//         00520bc3     ADD        ESP,0xc
//                               switchD_00520b22::caseD_3                                    XREF[2]:     00520b22(j), 00520d34(*)
//                              tpnl_tml.cpp:1496 (18)
//         00520bc6     MOV        EDX,dword ptr [ESI + 0x14]
//         00520bc9     LEA        EDI,[ESI + 0x3c]
//         00520bcc     PUSH       EDX
//         00520bcd     PUSH       s_%ld                                            = "%ld"
//         00520bd2     PUSH       EDI
//         00520bd3     CALL       sprintf                                          undefined sprintf()
//                              tpnl_tml.cpp:1497 (8)
//         00520bd8     OR         this,0xffffffff
//         00520bdb     XOR        EAX,EAX
//         00520bdd     ADD        ESP,0xc
//                              tpnl_tml.cpp:1502 (20)
//         00520be0     XOR        EBP,EBP
//         00520be2     SCASB.RE   ES:EDI
//         00520be4     MOV        EAX,dword ptr [ESI]
//         00520be6     NOT        this
//         00520be8     LEA        EAX,[EAX + EAX*0x2]
//         00520beb     DEC        this
//         00520bec     MOV        dword ptr [ESI + 0x38],this
//         00520bef     XOR        this,this
//         00520bf1     LEA        EDI,[EAX + EAX*0x4]
//                              tpnl_tml.cpp:1503 (5)
//         00520bf4     CMP        EDI,0x3b
//         00520bf7     JLE        LAB_00520c32
//                              tpnl_tml.cpp:1505 (21)
//         00520bf9     MOV        EAX,0x88888889
//         00520bfe     IMUL       EDI
//         00520c00     MOV        this,EDX
//         00520c02     ADD        this,EDI
//         00520c04     SAR        this,0x5
//         00520c07     MOV        EAX,this
//         00520c09     SHR        EAX,0x1f
//         00520c0c     ADD        this,EAX
//                              tpnl_tml.cpp:1507 (5)
//         00520c0e     CMP        this,0x3b
//         00520c11     JLE        LAB_00520c32
//                              tpnl_tml.cpp:1509 (21)
//         00520c13     MOV        EAX,0x88888889
//         00520c18     IMUL       this
//         00520c1a     ADD        EDX,this
//         00520c1c     SAR        EDX,0x5
//         00520c1f     MOV        EAX,EDX
//         00520c21     SHR        EAX,0x1f
//         00520c24     ADD        EDX,EAX
//         00520c26     MOV        EBP,EDX
//                              tpnl_tml.cpp:1510 (10)
//         00520c28     SHL        EDX,0x4
//         00520c2b     SUB        EDX,EBP
//         00520c2d     NEG        EDX
//         00520c2f     LEA        this,[this->_padding_ + EDX*0x4]
//                               LAB_00520c32                                                 XREF[2]:     00520bf7(j), 00520c11(j)
//                              tpnl_tml.cpp:1513 (20)
//         00520c32     PUSH       this
//         00520c33     PUSH       EBP
//         00520c34     LEA        EAX=>temp_str[4],[ESP + 0x1c]
//         00520c38     PUSH       s_%1ld:%02ld                                     = "%1ld:%02ld"
//         00520c3d     PUSH       EAX
//         00520c3e     CALL       sprintf                                          undefined sprintf()
//         00520c43     ADD        ESP,0x10
//                              tpnl_tml.cpp:1514 (19)
//         00520c46     LEA        this=>temp_str[4],[ESP + 0x14]
//         00520c4a     LEA        EDI,[ESI + 0x74]
//         00520c4d     PUSH       this
//         00520c4e     PUSH       s_%s                                             = "%s"
//         00520c53     PUSH       EDI
//         00520c54     CALL       sprintf                                          undefined sprintf()
//                              tpnl_tml.cpp:1515 (16)
//         00520c59     OR         this,0xffffffff
//         00520c5c     XOR        EAX,EAX
//         00520c5e     ADD        ESP,0xc
//         00520c61     SCASB.RE   ES:EDI
//         00520c63     NOT        this
//         00520c65     DEC        this
//         00520c66     MOV        dword ptr [ESI + 0x70],this
//                               switchD_00520b22::caseD_6                                    XREF[5]:     00520b1c(j), 00520b22(j),
//                                                                                                         00520b88(j), 00520b91(j),
//                                                                                                         00520d40(*)
//                              tpnl_tml.cpp:1521 (18)
//         00520c69     MOV        EDX,dword ptr [ESP + param_3]
//         00520c6d     MOV        EDI,dword ptr [ESP + param_2]
//         00520c71     PUSH       EDX
//         00520c72     PUSH       EDI
//         00520c73     PUSH       ESI
//         00520c74     MOV        this,EBX
//         00520c76     CALL       Time_Line_Panel::calculate_icon_location         int calculate_icon_location(Time_Line_Panel *
//                              tpnl_tml.cpp:1522 (16)
//         00520c7b     XOR        this,this
//         00520c7d     MOV        this,byte ptr [ESI + 0x12]
//         00520c80     SUB        this,0x0
//         00520c83     JZ         LAB_00520d02
//         00520c85     DEC        this
//         00520c86     JZ         LAB_00520cdf
//         00520c88     DEC        this
//         00520c89     JZ         LAB_00520cbc
//                              tpnl_tml.cpp:1544 (8)
//         00520c8b     TEST       EAX,EAX
//         00520c8d     JZ         LAB_00520d1b
//                              tpnl_tml.cpp:1545 (31)
//         00520c93     MOV        this,dword ptr [ESI + 0x24]
//         00520c96     MOV        EDX,dword ptr [ESI + 0x20]
//         00520c99     MOVSX      EAX,DI
//         00520c9c     PUSH       0x0
//         00520c9e     PUSH       0x0
//         00520ca0     PUSH       EAX
//         00520ca1     MOV        EAX,dword ptr [EBX + 0x20]
//         00520ca4     PUSH       this
//         00520ca5     MOV        this,dword ptr [EBX + 0x4d4]
//         00520cab     PUSH       EDX
//         00520cac     PUSH       EAX
//         00520cad     CALL       TShape::shape_draw                               uchar shape_draw(TShape * this, TDrawArea * p
//                              tpnl_tml.cpp:1550 (10)
//         00520cb2     POP        EDI
//         00520cb3     POP        ESI
//         00520cb4     POP        EBP
//         00520cb5     POP        EBX
//         00520cb6     ADD        ESP,0x38
//         00520cb9     RET        0xc
//                               LAB_00520cbc                                                 XREF[1]:     00520c89(j)
//                              tpnl_tml.cpp:1538 (25)
//         00520cbc     MOV        this,dword ptr [ESP + temp_str[0]]
//         00520cc0     MOV        EDX,dword ptr [ESI + 0xc]
//         00520cc3     MOV        EAX,dword ptr [ESI + 0x8]
//         00520cc6     PUSH       this
//         00520cc7     MOV        this,dword ptr [ESI + 0x4]
//         00520cca     PUSH       EDX
//         00520ccb     PUSH       EAX
//         00520ccc     PUSH       this
//         00520ccd     MOV        this,dword ptr [EBX + 0x20]
//         00520cd0     CALL       TDrawArea::DrawVertLine                          void DrawVertLine(TDrawArea * this, long para
//                              tpnl_tml.cpp:1550 (10)
//         00520cd5     POP        EDI
//         00520cd6     POP        ESI
//         00520cd7     POP        EBP
//         00520cd8     POP        EBX
//         00520cd9     ADD        ESP,0x38
//         00520cdc     RET        0xc
//                               LAB_00520cdf                                                 XREF[1]:     00520c86(j)
//                              tpnl_tml.cpp:1532 (25)
//         00520cdf     MOV        EDX,dword ptr [ESP + temp_str[0]]
//         00520ce3     MOV        EAX,dword ptr [ESI + 0xc]
//         00520ce6     MOV        this,dword ptr [ESI + 0x8]
//         00520ce9     PUSH       EDX
//         00520cea     MOV        EDX,dword ptr [ESI + 0x4]
//         00520ced     PUSH       EAX
//         00520cee     PUSH       this
//         00520cef     MOV        this,dword ptr [EBX + 0x20]
//         00520cf2     PUSH       EDX
//         00520cf3     CALL       TDrawArea::DrawVertLine                          void DrawVertLine(TDrawArea * this, long para
//                              tpnl_tml.cpp:1550 (10)
//         00520cf8     POP        EDI
//         00520cf9     POP        ESI
//         00520cfa     POP        EBP
//         00520cfb     POP        EBX
//         00520cfc     ADD        ESP,0x38
//         00520cff     RET        0xc
//                               LAB_00520d02                                                 XREF[1]:     00520c83(j)
//                              tpnl_tml.cpp:1526 (25)
//         00520d02     MOV        EAX,dword ptr [ESP + temp_str[0]]
//         00520d06     MOV        this,dword ptr [ESI + 0xc]
//         00520d09     MOV        EDX,dword ptr [ESI + 0x8]
//         00520d0c     PUSH       EAX
//         00520d0d     MOV        EAX,dword ptr [ESI + 0x4]
//         00520d10     PUSH       this
//         00520d11     MOV        this,dword ptr [EBX + 0x20]
//         00520d14     PUSH       EDX
//         00520d15     PUSH       EAX
//         00520d16     CALL       TDrawArea::DrawVertLine                          void DrawVertLine(TDrawArea * this, long para
//                               LAB_00520d1b                                                 XREF[1]:     00520c8d(j)
//                              tpnl_tml.cpp:1550 (49)
//         00520d1b     POP        EDI
//         00520d1c     POP        ESI
//         00520d1d     POP        EBP
//         00520d1e     POP        EBX
//         00520d1f     ADD        ESP,0x38
//         00520d22     RET        0xc
    return;
}

void Time_Line_Panel::draw_legend() {
    /* TODO: Stub */
//                              void __thiscall draw_legend(Time_Line_Panel * this)
//              void              <VOID>         <RETURN>
//              Time_Line_Pane    ECX:4 (auto)   this
//                               ?draw_legend@Time_Line_Panel@@QAEXXZ
//                               Time_Line_Panel::draw_legend
//                              tpnl_tml.cpp:1554 (3)
//         00520d50     PUSH       ESI
//         00520d51     MOV        ESI,this
//                              tpnl_tml.cpp:1561 (10)
//         00520d53     MOV        this,dword ptr [ESI + 0x4d4]
//         00520d59     TEST       this,this
//         00520d5b     JZ         LAB_00520d6d
//                              tpnl_tml.cpp:1564 (9)
//         00520d5d     CALL       TShape::shape_count                              long shape_count(TShape * this)
//         00520d62     TEST       EAX,EAX
//         00520d64     JZ         LAB_00520d6d
//                              tpnl_tml.cpp:1568 (7)
//         00520d66     MOV        this,ESI
//         00520d68     CALL       TPanel::width                                    long width(TPanel * this)
//                               LAB_00520d6d                                                 XREF[2]:     00520d5b(j), 00520d64(j)
//                              tpnl_tml.cpp:1570 (2)
//         00520d6d     POP        ESI
//         00520d6e     RET
//         00520d6f     ??         90h
    return;
}

