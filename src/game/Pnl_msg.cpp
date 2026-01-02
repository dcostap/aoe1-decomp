#include "../common.h"
#include "Pnl_msg.h"

TMessagePanel::TMessagePanel(void* param_1, long param_2, long param_3) {
    /* TODO: Stub */
//                              undefined __thiscall TMessagePanel(TMessagePanel * this, void * para
//              undefined         <UNASSIGNED>   <RETURN>
//              TMessagePanel *   ECX:4 (auto)   this
//              void *            Stack[0x4]:4   param_1                   XREF[1]:     00478f62(R)
//              long              Stack[0x8]:4   param_2                   XREF[1]:     00478f66(R)
//              long              Stack[0xc]:4   param_3                   XREF[1]:     00478f70(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     00478f8e(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     00479017(R)
//              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     00478f59(W)
//                               ??0TMessagePanel@@QAE@PAXJJ@Z                                XREF[10]:    TRIBE_Screen_Game:00494863(c),
//                               TMessagePanel::TMessagePanel                                              TRIBE_Screen_Game:00494ac5(c),
//                                                                                                         TRIBE_Screen_Game:00494b05(c),
//                                                                                                         TRIBE_Screen_Game:00494b45(c),
//                                                                                                         TRIBE_Screen_Game:00494b85(c),
//                                                                                                         TRIBE_Screen_Game:00494bc5(c),
//                                                                                                         TRIBE_Screen_Game:00494c05(c),
//                                                                                                         TRIBE_Screen_Game:00494da9(c),
//                                                                                                         TRIBE_Screen_Game:0049507c(c),
//                                                                                                         TRIBE_Screen_Sed:004a851b(c)
//                              Pnl_msg.cpp:51 (75)
//         00478f40     PUSH       -0x1
//         00478f42     PUSH       FUN_0055e4c8
//         00478f47     MOV        EAX,FS:[0x0]
//         00478f4d     PUSH       EAX
//         00478f4e     MOV        dword ptr FS:[0x0],ESP
//         00478f55     PUSH       this
//         00478f56     PUSH       ESI
//         00478f57     MOV        ESI,this
//         00478f59     MOV        dword ptr [ESP + local_10],ESI
//         00478f5d     CALL       TPanel::TPanel                                   undefined TPanel(TPanel * this)
//         00478f62     MOV        this,dword ptr [ESP + param_1]
//         00478f66     MOV        EDX,dword ptr [ESP + param_2]
//         00478f6a     MOV        dword ptr [ESI + 0x304],this
//         00478f70     MOV        this,dword ptr [ESP + param_3]
//         00478f74     MOV        dword ptr [ESI + 0x30c],this
//         00478f7a     OR         this,0xffffffff
//         00478f7d     XOR        EAX,EAX
//         00478f7f     MOV        dword ptr [ESI + 0x364],this
//         00478f85     MOV        dword ptr [ESI + 0x368],this
//                              Pnl_msg.cpp:54 (140)
//         00478f8b     PUSH       EAX
//         00478f8c     MOV        this,ESI
//         00478f8e     MOV        dword ptr [ESP + local_4],EAX
//         00478f92     MOV        dword ptr [ESI + 0xf4],EAX
//         00478f98     MOV        dword ptr [ESI + 0x2f8],EAX
//         00478f9e     MOV        dword ptr [ESI + 0x2fc],EAX
//         00478fa4     MOV        dword ptr [ESI + 0x300],0x1f40
//         00478fae     MOV        dword ptr [ESI + 0x308],EDX
//         00478fb4     MOV        byte ptr [ESI + 0x310],AL
//         00478fba     MOV        byte ptr [ESI + 0x311],AL
//         00478fc0     MOV        dword ptr [ESI + 0x320],0x2
//         00478fca     MOV        dword ptr [ESI + 0x324],EAX
//         00478fd0     MOV        dword ptr [ESI + 0x328],EAX
//         00478fd6     MOV        dword ptr [ESI + 0x32c],EAX
//         00478fdc     MOV        dword ptr [ESI + 0x330],EAX
//         00478fe2     MOV        dword ptr [ESI + 0x36c],EAX
//         00478fe8     MOV        dword ptr [ESI + 0x370],EAX
//         00478fee     MOV        dword ptr [ESI + 0x374],EAX
//         00478ff4     MOV        dword ptr [ESI + 0x378],EAX
//         00478ffa     MOV        dword ptr [ESI + 0x37c],EAX
//         00479000     MOV        dword ptr [ESI],TMessagePanel::`vftable'         = 00479030
//         00479006     MOV        byte ptr [ESI + 0xf8],AL
//         0047900c     MOV        dword ptr [ESI + 0x80],EAX
//         00479012     CALL       TPanel::set_active                               void set_active(TPanel * this, int param_1)
//                              Pnl_msg.cpp:55 (20)
//         00479017     MOV        this,dword ptr [ESP + local_c]
//         0047901b     MOV        EAX,ESI
//         0047901d     MOV        dword ptr FS:[0x0],this
//         00479024     POP        ESI
//         00479025     ADD        ESP,0x10
//         00479028     RET        0xc
//         0047902b     ??         90h
//         0047902c     NOP
//         0047902d     NOP
//         0047902e     NOP
//         0047902f     NOP
}

TMessagePanel::~TMessagePanel() {
    /* TODO: Stub */
//                              void __thiscall ~TMessagePanel(TMessagePanel * this)
//              void              <VOID>         <RETURN>
//              TMessagePanel *   ECX:4 (auto)   this
//              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     0047907a(W)
//              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     0047906a(W)
//                               ??1TMessagePanel@@UAE@XZ                                     XREF[1]:     `scalar_deleting_destructor':00479
//                               TMessagePanel::~TMessagePanel
//                              Pnl_msg.cpp:59 (36)
//         00479050     PUSH       -0x1
//         00479052     PUSH       FUN_0055e4e8
//         00479057     MOV        EAX,FS:[0x0]
//         0047905d     PUSH       EAX
//         0047905e     MOV        dword ptr FS:[0x0],ESP
//         00479065     PUSH       this
//         00479066     PUSH       ESI
//         00479067     MOV        ESI,this
//         00479069     PUSH       EDI
//         0047906a     MOV        dword ptr [ESP + local_10],ESI
//         0047906e     MOV        dword ptr [ESI],TMessagePanel::`vftable'         = 00479030
//                              Pnl_msg.cpp:61 (18)
//         00479074     MOV        EAX,dword ptr [ESI + 0x32c]
//         0047907a     MOV        dword ptr [ESP + local_4],0x0
//         00479082     TEST       EAX,EAX
//         00479084     JZ         LAB_00479097
//                              Pnl_msg.cpp:63 (7)
//         00479086     PUSH       EAX
//         00479087     CALL       dword ptr [->GDI32.DLL::DeleteObject]            = 0048b160
//                              Pnl_msg.cpp:64 (10)
//         0047908d     MOV        dword ptr [ESI + 0x32c],0x0
//                               LAB_00479097                                                 XREF[1]:     00479084(j)
//                              Pnl_msg.cpp:67 (10)
//         00479097     MOV        EDI,dword ptr [ESI + 0x330]
//         0047909d     TEST       EDI,EDI
//         0047909f     JZ         LAB_004790bb
//                              Pnl_msg.cpp:69 (16)
//         004790a1     MOV        this,EDI
//         004790a3     CALL       TDrawArea::~TDrawArea                            void ~TDrawArea(TDrawArea * this)
//         004790a8     PUSH       EDI
//         004790a9     CALL       operator_delete                                  void operator_delete(void * param_1)
//         004790ae     ADD        ESP,0x4
//                              Pnl_msg.cpp:70 (12)
//         004790b1     MOV        dword ptr [ESI + 0x330],0x0
//                               LAB_004790bb                                                 XREF[1]:     0047909f(j)
//         004790bb     MOV        this,ESI
//                              Pnl_msg.cpp:73 (30)
//         004790bd     MOV        dword ptr [ESP + 0x14],0xffffffff
//         004790c5     CALL       TPanel::~TPanel                                  void ~TPanel(TPanel * this)
//         004790ca     MOV        this,dword ptr [ESP + 0xc]
//         004790ce     POP        EDI
//         004790cf     MOV        dword ptr FS:[0x0],this
//         004790d6     POP        ESI
//         004790d7     ADD        ESP,0x10
//         004790da     RET
//         004790db     ??         90h
//         004790dc     NOP
//         004790dd     NOP
//         004790de     NOP
//         004790df     NOP
}

void TMessagePanel::set_rect(long param_1, long param_2, long param_3, long param_4) {
    /* TODO: Stub */
//                              void __thiscall set_rect(TMessagePanel * this, long param_1, long pa
//              void              <VOID>         <RETURN>
//              TMessagePanel *   ECX:4 (auto)   this
//              long              Stack[0x4]:4   param_1                   XREF[1]:     00479106(R)
//              long              Stack[0x8]:4   param_2                   XREF[1]:     004790f2(R)
//              long              Stack[0xc]:4   param_3                   XREF[1]:     00479101(R)
//              long              Stack[0x10]:4  param_4                   XREF[1]:     004790ee(R)
//                               ?set_rect@TMessagePanel@@UAEXJJJJ@Z                          XREF[1]:     00571674(*)
//                               TMessagePanel::set_rect
//                              Pnl_msg.cpp:77 (14)
//         004790e0     MOV        EAX,FS:[0x0]
//         004790e6     PUSH       -0x1
//         004790e8     PUSH       FUN_0055e50b
//         004790ed     PUSH       EAX
//                              Pnl_msg.cpp:79 (39)
//         004790ee     MOV        EAX,dword ptr [ESP + param_4]
//         004790f2     MOV        EDX,dword ptr [ESP + param_2]
//         004790f6     MOV        dword ptr FS:[0x0],ESP
//         004790fd     PUSH       EBX
//         004790fe     PUSH       ESI
//         004790ff     MOV        ESI,this
//         00479101     MOV        this,dword ptr [ESP + param_3]
//         00479105     PUSH       EDI
//         00479106     MOV        EDI,dword ptr [ESP + param_1]
//         0047910a     PUSH       EAX
//         0047910b     PUSH       this
//         0047910c     PUSH       EDX
//         0047910d     PUSH       EDI
//         0047910e     MOV        this,ESI
//         00479110     CALL       TPanel::set_rect                                 void set_rect(TPanel * this, long param_1, lo
//                              Pnl_msg.cpp:83 (42)
//         00479115     MOV        EAX,dword ptr [ESI + 0x364]
//         0047911b     MOV        this,dword ptr [ESI + 0x14]
//         0047911e     XOR        EBX,EBX
//         00479120     CMP        this,EAX
//         00479122     JG         LAB_0047913f
//         00479124     MOV        this,dword ptr [ESI + 0x18]
//         00479127     MOV        EDX,dword ptr [ESI + 0x368]
//         0047912d     CMP        this,EDX
//         0047912f     JG         LAB_0047913f
//         00479131     MOV        EDX,dword ptr [ESI + 0x20]
//         00479134     ADD        EDI,EAX
//         00479136     CMP        EDI,dword ptr [EDX + 0x18]
//         00479139     JL         LAB_00479201
//                               LAB_0047913f                                                 XREF[2]:     00479122(j), 0047912f(j)
//                              Pnl_msg.cpp:85 (10)
//         0047913f     MOV        EAX,dword ptr [ESI + 0x32c]
//         00479145     CMP        EAX,EBX
//         00479147     JZ         LAB_00479156
//                              Pnl_msg.cpp:87 (7)
//         00479149     PUSH       EAX
//         0047914a     CALL       dword ptr [->GDI32.DLL::DeleteObject]            = 0048b160
//                              Pnl_msg.cpp:88 (6)
//         00479150     MOV        dword ptr [ESI + 0x32c],EBX
//                               LAB_00479156                                                 XREF[1]:     00479147(j)
//                              Pnl_msg.cpp:91 (10)
//         00479156     MOV        EDI,dword ptr [ESI + 0x330]
//         0047915c     CMP        EDI,EBX
//         0047915e     JZ         LAB_00479176
//                              Pnl_msg.cpp:93 (16)
//         00479160     MOV        this,EDI
//         00479162     CALL       TDrawArea::~TDrawArea                            void ~TDrawArea(TDrawArea * this)
//         00479167     PUSH       EDI
//         00479168     CALL       operator_delete                                  void operator_delete(void * param_1)
//         0047916d     ADD        ESP,0x4
//                              Pnl_msg.cpp:94 (6)
//         00479170     MOV        dword ptr [ESI + 0x330],EBX
//                               LAB_00479176                                                 XREF[1]:     0047915e(j)
//                              Pnl_msg.cpp:97 (42)
//         00479176     PUSH       0x100
//         0047917b     CALL       operator_new                                     void * operator_new(uint param_1)
//         00479180     ADD        ESP,0x4
//         00479183     MOV        dword ptr [ESP + 0x28],EAX
//         00479187     CMP        EAX,EBX
//         00479189     MOV        dword ptr [ESP + 0x14],EBX
//         0047918d     JZ         LAB_0047919e
//         0047918f     PUSH       EBX
//         00479190     PUSH       s_message_panel                                  = "message panel"
//         00479195     MOV        this,EAX
//         00479197     CALL       TDrawArea::TDrawArea                             undefined TDrawArea(TDrawArea * this, char *
//         0047919c     JMP        LAB_004791a0
//                               LAB_0047919e                                                 XREF[1]:     0047918d(j)
//         0047919e     XOR        EAX,EAX
//                               LAB_004791a0                                                 XREF[1]:     0047919c(j)
//                              Pnl_msg.cpp:98 (37)
//         004791a0     MOV        this,dword ptr [ESI + 0x18]
//         004791a3     MOV        EDX,dword ptr [ESI + 0x14]
//         004791a6     PUSH       EBX
//         004791a7     PUSH       EBX
//         004791a8     PUSH       this
//         004791a9     MOV        this,dword ptr [ESI + 0x20]
//         004791ac     MOV        dword ptr [ESI + 0x330],EAX
//         004791b2     PUSH       EDX
//         004791b3     MOV        EDX,dword ptr [this->_padding_]
//         004791b5     MOV        this,EAX
//         004791b7     PUSH       EDX
//         004791b8     MOV        dword ptr [ESP + 0x28],0xffffffff
//         004791c0     CALL       TDrawArea::Init                                  int Init(TDrawArea * this, TDrawSystem * para
//                              Pnl_msg.cpp:99 (3)
//         004791c5     MOV        EAX,dword ptr [ESI + 0x14]
//                              Pnl_msg.cpp:100 (15)
//         004791c8     MOV        this,dword ptr [ESI + 0x18]
//         004791cb     MOV        dword ptr [ESI + 0x364],EAX
//         004791d1     MOV        dword ptr [ESI + 0x368],this
//                              Pnl_msg.cpp:104 (1)
//         004791d7     DEC        EAX
//                              Pnl_msg.cpp:105 (1)
//         004791d8     DEC        this
//                              Pnl_msg.cpp:107 (40)
//         004791d9     PUSH       this
//         004791da     PUSH       EAX
//         004791db     PUSH       EBX
//         004791dc     PUSH       EBX
//         004791dd     MOV        dword ptr [ESI + 0x334],EBX
//         004791e3     MOV        dword ptr [ESI + 0x338],EBX
//         004791e9     MOV        dword ptr [ESI + 0x33c],EAX
//         004791ef     MOV        dword ptr [ESI + 0x340],this
//         004791f5     CALL       dword ptr [->GDI32.DLL::CreateRectRgn]           = 0048b2ec
//         004791fb     MOV        dword ptr [ESI + 0x32c],EAX
//                               LAB_00479201                                                 XREF[1]:     00479139(j)
//                              Pnl_msg.cpp:110 (8)
//         00479201     CMP        dword ptr [ESI + 0x330],EBX
//         00479207     JZ         LAB_0047922d
//                              Pnl_msg.cpp:111 (34)
//         00479209     LEA        EAX,[ESI + 0x334]
//         0047920f     LEA        this,[ESI + 0x344]
//         00479215     MOV        EDX,dword ptr [EAX]
//         00479217     MOV        dword ptr [this->_padding_],EDX
//         00479219     MOV        EDX,dword ptr [EAX + 0x4]
//         0047921c     MOV        dword ptr [ECX + this->_padding_],EDX
//         0047921f     MOV        EDX,dword ptr [EAX + 0x8]
//         00479222     MOV        dword ptr [ECX + this->_padding_],EDX
//         00479225     MOV        EAX,dword ptr [EAX + 0xc]
//         00479228     MOV        dword ptr [ECX + this->_padding_],EAX
//                              Pnl_msg.cpp:112 (2)
//         0047922b     JMP        LAB_00479241
//                               LAB_0047922d                                                 XREF[1]:     00479207(j)
//                              Pnl_msg.cpp:114 (10)
//         0047922d     MOV        dword ptr [ESI + 0x364],0xffffffff
//                              Pnl_msg.cpp:115 (10)
//         00479237     MOV        dword ptr [ESI + 0x368],0xffffffff
//                               LAB_00479241                                                 XREF[1]:     0047922b(j)
//                              Pnl_msg.cpp:119 (16)
//         00479241     MOV        EDX,dword ptr [ESI]
//         00479243     PUSH       0x1
//         00479245     MOV        this,ESI
//         00479247     MOV        byte ptr [ESI + 0xf3],0x1
//         0047924e     CALL       dword ptr [EDX + 0x20]
//                              Pnl_msg.cpp:121 (20)
//         00479251     MOV        this,dword ptr [ESP + 0xc]
//         00479255     POP        EDI
//         00479256     POP        ESI
//         00479257     MOV        dword ptr FS:[0x0],this
//         0047925e     POP        EBX
//         0047925f     ADD        ESP,0xc
//         00479262     RET        0x10
//         00479265     ??         90h
//         00479266     NOP
//         00479267     NOP
//         00479268     NOP
//         00479269     NOP
//         0047926a     NOP
//         0047926b     NOP
//         0047926c     NOP
//         0047926d     NOP
//         0047926e     NOP
//         0047926f     NOP
    return;
}

void TMessagePanel::set_justification(JustType param_1, JustType param_2, int param_3) {
    /* TODO: Stub */
//                              void __thiscall set_justification(TMessagePanel * this, JustType par
//              void              <VOID>         <RETURN>
//              TMessagePanel *   ECX:4 (auto)   this
//              JustType          Stack[0x4]:4   param_1                   XREF[1]:     00479270(R)
//              JustType          Stack[0x8]:4   param_2                   XREF[1]:     00479274(R)
//              int               Stack[0xc]:4   param_3                   XREF[1]:     0047927e(R)
//                               ?set_justification@TMessagePanel@@QAEXW4JustType@1@0H@Z      XREF[1]:     TRIBE_Screen_Game:004948bd(c)
//                               TMessagePanel::set_justification
//                              Pnl_msg.cpp:128 (4)
//         00479270     MOV        EAX,dword ptr [ESP + param_1]
//                              Pnl_msg.cpp:130 (10)
//         00479274     MOV        EDX,dword ptr [ESP + param_2]
//         00479278     MOV        dword ptr [ECX + this->horz_just],EAX
//                              Pnl_msg.cpp:131 (16)
//         0047927e     MOV        EAX,dword ptr [ESP + param_3]
//         00479282     MOV        dword ptr [ECX + this->vert_just],EDX
//         00479288     MOV        dword ptr [ECX + this->word_wrap],EAX
//                              Pnl_msg.cpp:132 (3)
//         0047928e     RET        0xc
//         00479291     ??         90h
//         00479292     NOP
//         00479293     NOP
//         00479294     NOP
//         00479295     NOP
//         00479296     NOP
//         00479297     NOP
//         00479298     NOP
//         00479299     NOP
//         0047929a     NOP
//         0047929b     NOP
//         0047929c     NOP
//         0047929d     NOP
//         0047929e     NOP
//         0047929f     NOP
    return;
}

void TMessagePanel::show_message(MessageType param_1, char* param_2, uchar param_3, uchar param_4, void* param_5, long param_6, long param_7) {
    /* TODO: Stub */
//                              void __thiscall show_message(TMessagePanel * this, MessageType param
//              void              <VOID>         <RETURN>
//              TMessagePanel *   ECX:4 (auto)   this
//              MessageType       Stack[0x4]:4   param_1                   XREF[1]:     004792a6(R)
//              char *            Stack[0x8]:4   param_2                   XREF[1]:     004792a2(R)
//              uchar             Stack[0xc]:1   param_3                   XREF[1]:     00479366(R)
//              uchar             Stack[0x10]:1  param_4                   XREF[1]:     0047935c(R)
//              void *            Stack[0x14]:4  param_5                   XREF[1]:     004792ae(R)
//              long              Stack[0x18]:4  param_6                   XREF[1]:     004792f5(R)
//              long              Stack[0x1c]:4  param_7                   XREF[1]:     004792f9(R)
//                               ?show_message@TMessagePanel@@QAEXW4MessageType@1@PADEEPAXJJ@Z XREF[30]:    display_system_message:00497414(c)
//                               TMessagePanel::show_message                                               show_comm:0049953a(c),
//                                                                                                         show_comm:00499556(c),
//                                                                                                         show_comm:00499572(c),
//                                                                                                         show_comm:0049958e(c),
//                                                                                                         show_comm:004995aa(c),
//                                                                                                         show_comm:004995c6(c),
//                                                                                                         show_ai:004995ea(c),
//                                                                                                         show_ai:00499606(c),
//                                                                                                         show_ai:00499622(c),
//                                                                                                         show_ai:0049963e(c),
//                                                                                                         show_ai:0049965a(c),
//                                                                                                         show_ai:00499676(c),
//                                                                                                         show_message:004996a0(c),
//                                                                                                         handle_mouse_pointing_at:0049bc49(
//                                                                                                         command_attack:0049bd4d(c),
//                                                                                                         command_building:0049be81(c),
//                                                                                                         command_heal:0049c5dd(c),
//                                                                                                         command_move:0049c8f9(c),
//                                                                                                         command_research:0049cb80(c),
//                                                                                                         [more]
//                              Pnl_msg.cpp:138 (2)
//         004792a0     PUSH       EBX
//         004792a1     PUSH       EBP
//                              Pnl_msg.cpp:140 (73)
//         004792a2     MOV        EBX,dword ptr [ESP + param_2]
//         004792a6     MOV        EBP,dword ptr [ESP + param_1]
//         004792aa     PUSH       ESI
//         004792ab     MOV        ESI,this
//         004792ad     PUSH       EDI
//         004792ae     MOV        EDI,dword ptr [ESP + param_5]
//         004792b2     MOV        EAX,dword ptr [ESI + 0x2f8]
//         004792b8     TEST       EAX,EAX
//         004792ba     JZ         LAB_004792f1
//         004792bc     CMP        dword ptr [ESI + 0xf4],EBP
//         004792c2     JNZ        LAB_004792f1
//         004792c4     LEA        EAX,[ESI + 0xf8]
//         004792ca     PUSH       0x1ff
//         004792cf     PUSH       EAX
//         004792d0     PUSH       EBX
//         004792d1     CALL       strncmp                                          undefined strncmp()
//         004792d6     ADD        ESP,0xc
//         004792d9     TEST       EAX,EAX
//         004792db     JNZ        LAB_004792f1
//         004792dd     TEST       EDI,EDI
//         004792df     JZ         LAB_004793ab
//         004792e5     CMP        EDI,dword ptr [ESI + 0x304]
//                              Pnl_msg.cpp:141 (6)
//         004792eb     JZ         LAB_004793ab
//                               LAB_004792f1                                                 XREF[3]:     004792ba(j), 004792c2(j),
//                                                                                                         004792db(j)
//                              Pnl_msg.cpp:143 (4)
//         004792f1     TEST       EDI,EDI
//         004792f3     JZ         LAB_0047930f
//                              Pnl_msg.cpp:146 (4)
//         004792f5     MOV        this,dword ptr [ESP + param_6]
//                              Pnl_msg.cpp:147 (22)
//         004792f9     MOV        EDX,dword ptr [ESP + param_7]
//         004792fd     MOV        dword ptr [ESI + 0x304],EDI
//         00479303     MOV        dword ptr [ESI + 0x308],this
//         00479309     MOV        dword ptr [ESI + 0x30c],EDX
//                               LAB_0047930f                                                 XREF[1]:     004792f3(j)
//                              Pnl_msg.cpp:152 (15)
//         0047930f     LEA        EDX,[ESI + 0xf8]
//                              language.dll match for 0x80: "Arial"
//         00479315     MOV        this,0x80
//         0047931a     XOR        EAX,EAX
//         0047931c     MOV        EDI,EDX
//                              Pnl_msg.cpp:153 (20)
//         0047931e     PUSH       0x1ff
//         00479323     MOV        dword ptr [ESI + 0xf4],EBP
//         00479329     PUSH       EBX
//         0047932a     PUSH       EDX
//         0047932b     STOSD.REP  ES:EDI
//         0047932d     CALL       strncpy                                          undefined strncpy()
//                              Pnl_msg.cpp:155 (16)
//         00479332     MOV        EBX,dword ptr [ESI + 0xe0]
//         00479338     ADD        ESP,0xc
//         0047933b     INC        EBX
//         0047933c     MOV        dword ptr [ESI + 0xe0],EBX
//                              Pnl_msg.cpp:157 (5)
//         00479342     MOV        EBX,0x1
//                              Pnl_msg.cpp:158 (21)
//         00479347     PUSH       0x9e
//         0047934c     PUSH       s_C:\msdev\work\age1_x1\Pnl_msg.cp               = "C:\\msdev\\work\\age1_x1\\Pnl_msg.cpp"
//         00479351     MOV        dword ptr [ESI + 0x2f8],EBX
//         00479357     CALL       debug_timeGetTime                                ulong debug_timeGetTime(char * param_1, int p
//                              Pnl_msg.cpp:162 (23)
//         0047935c     MOV        this,byte ptr [ESP + param_4]
//         00479360     MOV        dword ptr [ESI + 0x2fc],EAX
//         00479366     MOV        AL,byte ptr [ESP + param_3]
//         0047936a     ADD        ESP,0x8
//         0047936d     MOV        byte ptr [ESI + 0x310],AL
//                              Pnl_msg.cpp:166 (22)
//         00479373     MOV        EAX,dword ptr [ESI + 0x330]
//         00479379     TEST       EAX,EAX
//         0047937b     MOV        dword ptr [ESI + 0x314],EBX
//         00479381     MOV        byte ptr [ESI + 0x311],this
//         00479387     JZ         LAB_00479390
//                              Pnl_msg.cpp:168 (7)
//         00479389     MOV        this,ESI
//         0047938b     CALL       TMessagePanel::render_to_image_buffer            int render_to_image_buffer(TMessagePanel * th
//                               LAB_00479390                                                 XREF[1]:     00479387(j)
//                              Pnl_msg.cpp:171 (8)
//         00479390     MOV        EDI,dword ptr [ESI]
//         00479392     PUSH       EBX
//         00479393     MOV        this,ESI
//         00479395     CALL       dword ptr [EDI + 0x14]
//                              Pnl_msg.cpp:172 (6)
//         00479398     PUSH       EBX
//         00479399     MOV        this,ESI
//         0047939b     CALL       dword ptr [EDI + 0x20]
//                              Pnl_msg.cpp:173 (7)
//         0047939e     MOV        this,dword ptr [ESI + 0x40]
//         004793a1     TEST       this,this
//         004793a3     JZ         LAB_004793ab
//                              Pnl_msg.cpp:175 (6)
//         004793a5     MOV        EDX,dword ptr [this->_padding_]
//         004793a7     PUSH       EBX
//         004793a8     CALL       dword ptr [EDX + 0x20]
//                               LAB_004793ab                                                 XREF[3]:     004792df(j), 004792eb(j),
//                                                                                                         004793a3(j)
//                              Pnl_msg.cpp:178 (7)
//         004793ab     POP        EDI
//         004793ac     POP        ESI
//         004793ad     POP        EBP
//         004793ae     POP        EBX
//         004793af     RET        0x1c
//         004793b2     ??         90h
//         004793b3     NOP
//         004793b4     NOP
//         004793b5     NOP
//         004793b6     NOP
//         004793b7     NOP
//         004793b8     NOP
//         004793b9     NOP
//         004793ba     NOP
//         004793bb     NOP
//         004793bc     NOP
//         004793bd     NOP
//         004793be     NOP
//         004793bf     NOP
    return;
}

void TMessagePanel::show_message2(MessageType param_1, char* param_2, ulong param_3, ulong param_4, void* param_5, long param_6, long param_7, TShape* param_8, int param_9, TShape* param_10, int param_11) {
    /* TODO: Stub */
//                              void __thiscall show_message2(TMessagePanel * this, MessageType para
//              void              <VOID>         <RETURN>
//              TMessagePanel *   ECX:4 (auto)   this
//              MessageType       Stack[0x4]:4   param_1                   XREF[2]:     004793e2(R), 00479469(R)
//              char *            Stack[0x8]:4   param_2                   XREF[1]:     004793c6(R)
//              ulong             Stack[0xc]:4   param_3                   XREF[1]:     004794df(R)
//              ulong             Stack[0x10]:4  param_4                   XREF[1]:     004794d5(R)
//              void *            Stack[0x14]:4  param_5                   XREF[2]:     00479403(R), 00479443(R)
//              long              Stack[0x18]:4  param_6                   XREF[1]:     0047944b(R)
//              long              Stack[0x1c]:4  param_7                   XREF[1]:     0047944f(R)
//              TShape *          Stack[0x20]:4  param_8                   XREF[2]:     00479419(R), 0047946d(R)
//              int               Stack[0x24]:4  param_9                   XREF[2]:     0047942f(R), 00479465(R)
//              TShape *          Stack[0x28]:4  param_10                  XREF[1]:     004793c2(R)
//              int               Stack[0x2c]:4  param_11                  XREF[1]:     004793ce(R)
//                               ?show_message2@TMessagePanel@@QAEXW4MessageType@1@PADKKPAXJ  XREF[1]:     reset_score_display:0049b4fa(c)
//                               TMessagePanel::show_message2
//                              Pnl_msg.cpp:186 (2)
//         004793c0     PUSH       EBX
//         004793c1     PUSH       EBP
//                              Pnl_msg.cpp:188 (129)
//         004793c2     MOV        EBP,dword ptr [ESP + param_10]
//         004793c6     MOV        EBX,dword ptr [ESP + param_2]
//         004793ca     PUSH       ESI
//         004793cb     MOV        ESI,this
//         004793cd     PUSH       EDI
//         004793ce     MOV        EDI,dword ptr [ESP + param_11]
//         004793d2     MOV        EAX,dword ptr [ESI + 0x2f8]
//         004793d8     TEST       EAX,EAX
//         004793da     JZ         LAB_00479443
//         004793dc     MOV        EAX,dword ptr [ESI + 0xf4]
//         004793e2     MOV        this,dword ptr [ESP + param_1]
//         004793e6     CMP        EAX,this
//         004793e8     JNZ        LAB_00479443
//         004793ea     LEA        this,[ESI + 0xf8]
//         004793f0     PUSH       0x1ff
//         004793f5     PUSH       this
//         004793f6     PUSH       EBX
//         004793f7     CALL       strncmp                                          undefined strncmp()
//         004793fc     ADD        ESP,0xc
//         004793ff     TEST       EAX,EAX
//         00479401     JNZ        LAB_00479443
//         00479403     MOV        EAX,dword ptr [ESP + param_5]
//         00479407     TEST       EAX,EAX
//         00479409     JZ         LAB_00479413
//         0047940b     CMP        EAX,dword ptr [ESI + 0x304]
//         00479411     JNZ        LAB_00479443
//                               LAB_00479413                                                 XREF[1]:     00479409(j)
//         00479413     MOV        EDX,dword ptr [ESI + 0x370]
//         00479419     MOV        EAX,dword ptr [ESP + param_8]
//         0047941d     CMP        EDX,EAX
//         0047941f     JNZ        LAB_00479443
//         00479421     CMP        dword ptr [ESI + 0x374],EBP
//         00479427     JNZ        LAB_00479443
//         00479429     MOV        EAX,dword ptr [ESI + 0x378]
//         0047942f     MOV        this,dword ptr [ESP + param_9]
//         00479433     CMP        EAX,this
//         00479435     JNZ        LAB_00479443
//         00479437     CMP        dword ptr [ESI + 0x37c],EDI
//         0047943d     JZ         LAB_0047952b
//                               LAB_00479443                                                 XREF[7]:     004793da(j), 004793e8(j),
//                                                                                                         00479401(j), 00479411(j),
//                                                                                                         0047941f(j), 00479427(j),
//                                                                                                         00479435(j)
//                              Pnl_msg.cpp:191 (8)
//         00479443     MOV        EAX,dword ptr [ESP + param_5]
//         00479447     TEST       EAX,EAX
//         00479449     JZ         LAB_00479465
//                              Pnl_msg.cpp:194 (4)
//         0047944b     MOV        this,dword ptr [ESP + param_6]
//                              Pnl_msg.cpp:195 (22)
//         0047944f     MOV        EDX,dword ptr [ESP + param_7]
//         00479453     MOV        dword ptr [ESI + 0x304],EAX
//         00479459     MOV        dword ptr [ESI + 0x308],this
//         0047945f     MOV        dword ptr [ESI + 0x30c],EDX
//                               LAB_00479465                                                 XREF[1]:     00479449(j)
//                              Pnl_msg.cpp:202 (18)
//         00479465     MOV        EDX,dword ptr [ESP + param_9]
//         00479469     MOV        EAX,dword ptr [ESP + param_1]
//         0047946d     MOV        this,dword ptr [ESP + param_8]
//         00479471     MOV        dword ptr [ESI + 0x378],EDX
//                              Pnl_msg.cpp:205 (33)
//         00479477     LEA        EDX,[ESI + 0xf8]
//         0047947d     MOV        dword ptr [ESI + 0xf4],EAX
//         00479483     MOV        dword ptr [ESI + 0x370],this
//         00479489     MOV        dword ptr [ESI + 0x37c],EDI
//                              language.dll match for 0x80: "Arial"
//         0047948f     MOV        this,0x80
//         00479494     XOR        EAX,EAX
//         00479496     MOV        EDI,EDX
//                              Pnl_msg.cpp:206 (20)
//         00479498     PUSH       0x1ff
//         0047949d     MOV        dword ptr [ESI + 0x374],EBP
//         004794a3     PUSH       EBX
//         004794a4     STOSD.REP  ES:EDI
//         004794a6     PUSH       EDX
//         004794a7     CALL       strncpy                                          undefined strncpy()
//                              Pnl_msg.cpp:208 (10)
//         004794ac     MOV        EBX,dword ptr [ESI + 0xe0]
//         004794b2     ADD        ESP,0xc
//         004794b5     INC        EBX
//                              Pnl_msg.cpp:210 (10)
//         004794b6     MOV        dword ptr [ESI + 0x2f8],0x1
//                              Pnl_msg.cpp:211 (21)
//         004794c0     PUSH       0xd3
//         004794c5     PUSH       s_C:\msdev\work\age1_x1\Pnl_msg.cp               = "C:\\msdev\\work\\age1_x1\\Pnl_msg.cpp"
//         004794ca     MOV        dword ptr [ESI + 0xe0],EBX
//         004794d0     CALL       debug_timeGetTime                                ulong debug_timeGetTime(char * param_1, int p
//                              Pnl_msg.cpp:215 (23)
//         004794d5     MOV        this,dword ptr [ESP + param_4]
//         004794d9     MOV        dword ptr [ESI + 0x2fc],EAX
//         004794df     MOV        EAX,dword ptr [ESP + param_3]
//         004794e3     ADD        ESP,0x8
//         004794e6     MOV        dword ptr [ESI + 0x318],EAX
//                              Pnl_msg.cpp:219 (26)
//         004794ec     MOV        EAX,dword ptr [ESI + 0x330]
//         004794f2     TEST       EAX,EAX
//         004794f4     MOV        dword ptr [ESI + 0x314],0x0
//         004794fe     MOV        dword ptr [ESI + 0x31c],this
//         00479504     JZ         LAB_0047950d
//                              Pnl_msg.cpp:221 (7)
//         00479506     MOV        this,ESI
//         00479508     CALL       TMessagePanel::render_to_image_buffer            int render_to_image_buffer(TMessagePanel * th
//                               LAB_0047950d                                                 XREF[1]:     00479504(j)
//                              Pnl_msg.cpp:224 (9)
//         0047950d     MOV        EDI,dword ptr [ESI]
//         0047950f     PUSH       0x1
//         00479511     MOV        this,ESI
//         00479513     CALL       dword ptr [EDI + 0x14]
//                              Pnl_msg.cpp:225 (7)
//         00479516     PUSH       0x1
//         00479518     MOV        this,ESI
//         0047951a     CALL       dword ptr [EDI + 0x20]
//                              Pnl_msg.cpp:226 (7)
//         0047951d     MOV        this,dword ptr [ESI + 0x40]
//         00479520     TEST       this,this
//         00479522     JZ         LAB_0047952b
//                              Pnl_msg.cpp:228 (7)
//         00479524     MOV        EDX,dword ptr [this->_padding_]
//         00479526     PUSH       0x1
//         00479528     CALL       dword ptr [EDX + 0x20]
//                               LAB_0047952b                                                 XREF[2]:     0047943d(j), 00479522(j)
//                              Pnl_msg.cpp:231 (7)
//         0047952b     POP        EDI
//         0047952c     POP        ESI
//         0047952d     POP        EBP
//         0047952e     POP        EBX
//         0047952f     RET        0x2c
//         00479532     ??         90h
//         00479533     NOP
//         00479534     NOP
//         00479535     NOP
//         00479536     NOP
//         00479537     NOP
//         00479538     NOP
//         00479539     NOP
//         0047953a     NOP
//         0047953b     NOP
//         0047953c     NOP
//         0047953d     NOP
//         0047953e     NOP
//         0047953f     NOP
    return;
}

void TMessagePanel::remove_message() {
    /* TODO: Stub */
//                              void __thiscall remove_message(TMessagePanel * this)
//              void              <VOID>         <RETURN>
//              TMessagePanel *   ECX:4 (auto)   this
//                               ?remove_message@TMessagePanel@@QAEXXZ                        XREF[28]:    handle_game_update:00496bb7(c),
//                               TMessagePanel::remove_message                                             handle_game_update:00496bc2(c),
//                                                                                                         handle_game_update:00496bcd(c),
//                                                                                                         handle_game_update:00496bd8(c),
//                                                                                                         handle_game_update:00496be3(c),
//                                                                                                         handle_game_update:00496bee(c),
//                                                                                                         handle_game_update:00496bf9(c),
//                                                                                                         handle_mouse_down:00497219(c),
//                                                                                                         handle_mouse_down:00497224(c),
//                                                                                                         handle_mouse_down:0049722f(c),
//                                                                                                         handle_mouse_down:0049723a(c),
//                                                                                                         handle_mouse_down:00497245(c),
//                                                                                                         handle_mouse_down:00497250(c),
//                                                                                                         handle_mouse_pointing_at:0049bb84(
//                                                                                                         command_comm_info:0049c0e0(c),
//                                                                                                         command_comm_info:0049c0eb(c),
//                                                                                                         command_comm_info:0049c0f6(c),
//                                                                                                         command_comm_info:0049c101(c),
//                                                                                                         command_comm_info:0049c10c(c),
//                                                                                                         command_comm_info:0049c117(c),
//                                                                                                         [more]
//                              Pnl_msg.cpp:237 (4)
//         00479540     PUSH       ESI
//         00479541     MOV        ESI,this
//         00479543     PUSH       EDI
//                              Pnl_msg.cpp:238 (10)
//         00479544     MOV        EAX,dword ptr [ESI + 0x2f8]
//         0047954a     TEST       EAX,EAX
//         0047954c     JZ         LAB_00479574
//                              Pnl_msg.cpp:241 (17)
//         0047954e     MOV        EDI,dword ptr [ESI]
//         00479550     PUSH       0x0
//         00479552     MOV        dword ptr [ESI + 0x2f8],0x0
//         0047955c     CALL       dword ptr [EDI + 0x14]
//                              Pnl_msg.cpp:242 (7)
//         0047955f     PUSH       0x1
//         00479561     MOV        this,ESI
//         00479563     CALL       dword ptr [EDI + 0x20]
//                              Pnl_msg.cpp:243 (7)
//         00479566     MOV        this,dword ptr [ESI + 0x40]
//         00479569     TEST       this,this
//         0047956b     JZ         LAB_00479574
//                              Pnl_msg.cpp:245 (7)
//         0047956d     MOV        EAX,dword ptr [this->_padding_]
//         0047956f     PUSH       0x1
//         00479571     CALL       dword ptr [EAX + 0x20]
//                               LAB_00479574                                                 XREF[2]:     0047954c(j), 0047956b(j)
//                              Pnl_msg.cpp:249 (10)
//         00479574     MOV        dword ptr [ESI + 0x36c],0x0
//                              Pnl_msg.cpp:250 (3)
//         0047957e     POP        EDI
//         0047957f     POP        ESI
//         00479580     RET
//         00479581     ??         90h
//         00479582     NOP
//         00479583     NOP
//         00479584     NOP
//         00479585     NOP
//         00479586     NOP
//         00479587     NOP
//         00479588     NOP
//         00479589     NOP
//         0047958a     NOP
//         0047958b     NOP
//         0047958c     NOP
//         0047958d     NOP
//         0047958e     NOP
//         0047958f     NOP
    return;
}

void TMessagePanel::draw() {
    /* TODO: Stub */
//                              void __thiscall draw(TMessagePanel * this)
//              void              <VOID>         <RETURN>
//              TMessagePanel *   ECX:4 (auto)   this
//              tagRECT           Stack[-0x14]   rect
//              tagSIZE           Stack[-0x1c]:8 ts
//              tagPALETTEENTRY   Stack[-0x24]:4 paletteColor              XREF[1]:     004795cc(W)
//              void *            Stack[-0x2c]:4 old_font
//              ulong             Stack[-0x3c]:4 font_rgb
//              long              Stack[-0x40]:4 hgt
//              long              Stack[-0x44]:4 wid
//              long              Stack[-0x48]:4 x
//              long              Stack[-0x4c]:4 y
//                               ?draw@TMessagePanel@@UAEXXZ                                  XREF[1]:     00571698(*)
//                               TMessagePanel::draw
//                              Pnl_msg.cpp:256 (9)
//         00479590     SUB        ESP,0x48
//         00479593     PUSH       EBX
//         00479594     PUSH       EBP
//         00479595     PUSH       ESI
//         00479596     MOV        ESI,this
//         00479598     PUSH       EDI
//                              Pnl_msg.cpp:265 (47)
//         00479599     MOV        EAX,dword ptr [ESI + 0x20]
//         0047959c     TEST       EAX,EAX
//         0047959e     JZ         LAB_004799fc
//         004795a4     MOV        EAX,dword ptr [ESI + 0x70]
//         004795a7     TEST       EAX,EAX
//         004795a9     JZ         LAB_004799fc
//         004795af     MOV        EAX,dword ptr [ESI + 0x6c]
//         004795b2     TEST       EAX,EAX
//         004795b4     JZ         LAB_004799fc
//         004795ba     MOV        EAX,dword ptr [ESI + 0x2f8]
//         004795c0     TEST       EAX,EAX
//         004795c2     JZ         LAB_004799fc
//                              Pnl_msg.cpp:271 (11)
//         004795c8     MOV        EDI,dword ptr [ESI]
//         004795ca     PUSH       0x0
//         004795cc     MOV        dword ptr [ESP + paletteColor.peRed],EDI
//         004795d0     CALL       dword ptr [EDI + 0x28]
//                              Pnl_msg.cpp:275 (20)
//         004795d3     MOV        EAX,dword ptr [ESI + 0x36c]
//         004795d9     TEST       EAX,EAX
//         004795db     JZ         LAB_00479657
//         004795dd     MOV        this,dword ptr [ESI + 0x330]
//         004795e3     TEST       this,this
//         004795e5     JZ         LAB_00479657
//                              Pnl_msg.cpp:277 (10)
//         004795e7     MOV        AL,byte ptr [ESI + 0xf3]
//         004795ed     TEST       AL,AL
//         004795ef     JZ         LAB_0047960c
//                              Pnl_msg.cpp:279 (7)
//         004795f1     MOV        this,ESI
//         004795f3     CALL       TMessagePanel::render_to_image_buffer            int render_to_image_buffer(TMessagePanel * th
//                              Pnl_msg.cpp:414 (12)
//         004795f8     MOV        this,ESI
//         004795fa     MOV        byte ptr [ESI + 0xf3],0x0
//         00479601     CALL       dword ptr [EDI + 0x2c]
//                              Pnl_msg.cpp:415 (8)
//         00479604     POP        EDI
//         00479605     POP        ESI
//         00479606     POP        EBP
//         00479607     POP        EBX
//         00479608     ADD        ESP,0x48
//         0047960b     RET
//                               LAB_0047960c                                                 XREF[1]:     004795ef(j)
//                              Pnl_msg.cpp:286 (9)
//         0047960c     PUSH       0x1
//         0047960e     PUSH       offset DAT_fffffff8
//         00479610     CALL       TDrawArea::SetTrans                              void SetTrans(TDrawArea * this, int param_1,
//                              Pnl_msg.cpp:287 (38)
//         00479615     MOV        this,dword ptr [ESI + 0x358]
//         0047961b     MOV        EDX,dword ptr [ESI + 0x354]
//         00479621     LEA        EAX,[ESI + 0x344]
//         00479627     PUSH       0x1
//         00479629     PUSH       EAX=>DAT_fffffff8
//         0047962a     MOV        EAX,dword ptr [ESI + 0x20]
//         0047962d     PUSH       this=>DAT_fffffff4
//         0047962e     MOV        this,dword ptr [ESI + 0x330]
//         00479634     PUSH       EDX=>DAT_fffffff0
//         00479635     PUSH       EAX
//         00479636     CALL       TDrawArea::Copy                                  void Copy(TDrawArea * this, TDrawArea * param
//                              Pnl_msg.cpp:288 (15)
//         0047963b     MOV        this,dword ptr [ESI + 0x330]
//         00479641     PUSH       0x1
//         00479643     PUSH       0x0=>DAT_fffffff8
//         00479645     CALL       TDrawArea::SetTrans                              void SetTrans(TDrawArea * this, int param_1,
//                              Pnl_msg.cpp:414 (5)
//         0047964a     MOV        this,ESI
//         0047964c     CALL       dword ptr [EDI + 0x2c]
//                              Pnl_msg.cpp:415 (8)
//         0047964f     POP        EDI
//         00479650     POP        ESI
//         00479651     POP        EBP
//         00479652     POP        EBX
//         00479653     ADD        ESP,0x48
//         00479656     RET
//                               LAB_00479657                                                 XREF[2]:     004795db(j), 004795e5(j)
//                              Pnl_msg.cpp:294 (20)
//         00479657     MOV        AL,byte ptr [ESI + 0xf8]
//         0047965d     LEA        EBP,[ESI + 0xf8]
//         00479663     TEST       AL,AL
//         00479665     JZ         LAB_004799ef
//                              Pnl_msg.cpp:296 (21)
//         0047966b     MOV        this,dword ptr [ESI + 0x20]
//         0047966e     PUSH       s_pnl_msg::draw                                  = "pnl_msg::draw"
//         00479673     CALL       TDrawArea::GetDc                                 void * GetDc(TDrawArea * this, char * param_1)
//         00479678     TEST       EAX,EAX
//         0047967a     JZ         LAB_004799ef
//                              Pnl_msg.cpp:298 (20)
//         00479680     MOV        EDX,dword ptr [ESI + 0x20]
//         00479683     MOV        this,dword ptr [ESI + 0x88]
//         00479689     PUSH       this
//         0047968a     MOV        EAX,dword ptr [EDX + 0x38]
//         0047968d     PUSH       EAX=>DAT_fffffff8
//         0047968e     CALL       dword ptr [->GDI32.DLL::SelectClipRgn]           = 0048b2fc
//                              Pnl_msg.cpp:300 (24)
//         00479694     MOV        EDX,dword ptr [ESI + 0x20]
//         00479697     MOV        this,dword ptr [ESI + 0x304]
//         0047969d     PUSH       this
//         0047969e     MOV        EAX,dword ptr [EDX + 0x38]
//         004796a1     PUSH       EAX=>DAT_fffffff8
//         004796a2     CALL       dword ptr [->GDI32.DLL::SelectObject]            = 0048b192
//         004796a8     MOV        dword ptr [ESP + 0x30],EAX
//                              Pnl_msg.cpp:304 (14)
//         004796ac     MOV        EAX,dword ptr [ESI + 0x314]
//         004796b2     TEST       EAX,EAX
//         004796b4     JZ         LAB_00479751
//                              Pnl_msg.cpp:306 (36)
//         004796ba     MOV        EAX,[rge_base_game]                              = 00000000
//         004796bf     LEA        this,[ESP + 0x38]
//         004796c3     MOV        EDI,dword ptr [->GDI32.DLL::GetPaletteEntries]   = 0048b270
//         004796c9     XOR        EDX,EDX
//         004796cb     MOV        DL,byte ptr [ESI + 0x310]
//         004796d1     PUSH       this
//         004796d2     MOV        this,dword ptr [EAX + 0x48]
//         004796d5     PUSH       offset DAT_fffffff8
//         004796d7     PUSH       EDX=>DAT_fffffff4
//         004796d8     MOV        EDX,dword ptr [ECX + this->_padding_]
//         004796db     PUSH       EDX=>DAT_fffffff0
//         004796dc     CALL       EDI=>GDI32.DLL::GetPaletteEntries
//                              Pnl_msg.cpp:307 (34)
//         004796de     MOV        EAX,dword ptr [ESP + 0x3a]
//         004796e2     MOV        this,dword ptr [ESP + 0x39]
//         004796e6     MOV        EDX,dword ptr [ESP + 0x38]
//         004796ea     AND        EAX,0xff
//         004796ef     SHL        EAX,0x8
//         004796f2     AND        this,0xff
//         004796f8     AND        EDX,0xff
//         004796fe     OR         EAX,this
//                              Pnl_msg.cpp:309 (40)
//         00479700     XOR        this,this
//         00479702     SHL        EAX,0x8
//         00479705     MOV        this,byte ptr [ESI + 0x311]
//         0047970b     OR         EAX,EDX
//         0047970d     MOV        EDX,dword ptr [rge_base_game]                    = 00000000
//         00479713     MOV        dword ptr [ESP + 0x20],EAX
//         00479717     LEA        EAX,[ESP + 0x38]
//         0047971b     PUSH       EAX
//         0047971c     MOV        EAX,dword ptr [EDX + 0x48]
//         0047971f     PUSH       offset DAT_fffffff8
//         00479721     PUSH       this=>DAT_fffffff4
//         00479722     MOV        this,dword ptr [EAX + 0x8]
//         00479725     PUSH       this=>DAT_fffffff0
//         00479726     CALL       EDI=>GDI32.DLL::GetPaletteEntries
//                              Pnl_msg.cpp:310 (39)
//         00479728     MOV        EBX,dword ptr [ESP + 0x3a]
//         0047972c     MOV        EDX,dword ptr [ESP + 0x39]
//         00479730     MOV        EAX,dword ptr [ESP + 0x38]
//         00479734     AND        EBX,0xff
//         0047973a     SHL        EBX,0x8
//         0047973d     AND        EDX,0xff
//         00479743     AND        EAX,0xff
//         00479748     OR         EBX,EDX
//         0047974a     SHL        EBX,0x8
//         0047974d     OR         EBX,EAX
//                              Pnl_msg.cpp:312 (2)
//         0047974f     JMP        LAB_00479761
//                               LAB_00479751                                                 XREF[1]:     004796b4(j)
//                              Pnl_msg.cpp:314 (6)
//         00479751     MOV        this,dword ptr [ESI + 0x318]
//                              Pnl_msg.cpp:315 (10)
//         00479757     MOV        EBX,dword ptr [ESI + 0x31c]
//         0047975d     MOV        dword ptr [ESP + 0x20],this
//                               LAB_00479761                                                 XREF[1]:     0047974f(j)
//                              Pnl_msg.cpp:318 (9)
//         00479761     CMP        dword ptr [ESI + 0xf4],0x2
//         00479768     JNZ        LAB_00479784
//                              Pnl_msg.cpp:320 (15)
//         0047976a     MOV        EDX,dword ptr [ESI + 0x20]
//         0047976d     PUSH       0x0
//         0047976f     MOV        EAX,dword ptr [EDX + 0x38]
//         00479772     PUSH       EAX=>DAT_fffffff8
//         00479773     CALL       dword ptr [->GDI32.DLL::SetBkColor]              = 0048b34c
//                              Pnl_msg.cpp:321 (9)
//         00479779     MOV        this,dword ptr [ESI + 0x20]
//         0047977c     PUSH       0x2
//         0047977e     MOV        EDX,dword ptr [ECX + this->_padding_]
//         00479781     PUSH       EDX=>DAT_fffffff8
//                              Pnl_msg.cpp:323 (2)
//         00479782     JMP        LAB_0047978d
//                               LAB_00479784                                                 XREF[1]:     00479768(j)
//                              Pnl_msg.cpp:324 (15)
//         00479784     MOV        EAX,dword ptr [ESI + 0x20]
//         00479787     PUSH       0x1
//         00479789     MOV        this,dword ptr [EAX + 0x38]
//         0047978c     PUSH       this=>DAT_fffffff8
//                               LAB_0047978d                                                 XREF[1]:     00479782(j)
//         0047978d     CALL       dword ptr [->GDI32.DLL::SetBkMode]               = 0048b340
//                              Pnl_msg.cpp:328 (6)
//         00479793     MOV        EAX,dword ptr [ESI + 0x8c]
//                              Pnl_msg.cpp:335 (68)
//         00479799     MOV        EDI,EBP
//         0047979b     INC        EAX
//         0047979c     OR         this,0xffffffff
//         0047979f     MOV        dword ptr [ESP + 0x14],EAX
//         004797a3     MOV        EAX,dword ptr [ESI + 0x90]
//         004797a9     INC        EAX
//         004797aa     LEA        EDX,[ESP + 0x40]
//         004797ae     MOV        dword ptr [ESP + 0x10],EAX
//         004797b2     MOV        EAX,dword ptr [ESI + 0x14]
//         004797b5     SUB        EAX,0x2
//         004797b8     PUSH       EDX
//         004797b9     MOV        dword ptr [ESP + 0x1c],EAX
//         004797bd     MOV        EAX,dword ptr [ESI + 0x18]
//         004797c0     SUB        EAX,0x2
//         004797c3     MOV        dword ptr [ESP + 0x20],EAX
//         004797c7     XOR        EAX,EAX
//         004797c9     SCASB.RE   ES:EDI
//         004797cb     MOV        EAX,dword ptr [ESI + 0x20]
//         004797ce     NOT        this
//         004797d0     DEC        this
//         004797d1     PUSH       this=>DAT_fffffff8
//         004797d2     MOV        this,dword ptr [EAX + 0x38]
//         004797d5     PUSH       EBP=>DAT_fffffff4
//         004797d6     PUSH       this=>DAT_fffffff0
//         004797d7     CALL       dword ptr [->GDI32.DLL::GetTextExtentPoint32A]   = 0048b328
//                              Pnl_msg.cpp:337 (11)
//         004797dd     MOV        EAX,dword ptr [ESI + 0xf4]
//         004797e3     CMP        EAX,0x1
//         004797e6     JNZ        LAB_004797ef
//                              Pnl_msg.cpp:339 (5)
//         004797e8     MOV        EDI,0x21
//                              Pnl_msg.cpp:341 (7)
//         004797ed     JMP        LAB_0047986a
//                               LAB_004797ef                                                 XREF[1]:     004797e6(j)
//         004797ef     CMP        EAX,0x5
//         004797f2     JNZ        LAB_004797fb
//                              Pnl_msg.cpp:343 (5)
//         004797f4     MOV        EDI,0x22
//                              Pnl_msg.cpp:345 (2)
//         004797f9     JMP        LAB_0047986a
//                               LAB_004797fb                                                 XREF[1]:     004797f2(j)
//                              Pnl_msg.cpp:347 (32)
//         004797fb     MOV        EDI,EBP
//         004797fd     OR         this,0xffffffff
//         00479800     XOR        EAX,EAX
//         00479802     LEA        EDX,[ESP + 0x40]
//         00479806     SCASB.RE   ES:EDI
//         00479808     MOV        EAX,dword ptr [ESI + 0x20]
//         0047980b     PUSH       EDX
//         0047980c     NOT        this
//         0047980e     DEC        this
//         0047980f     PUSH       this=>DAT_fffffff8
//         00479810     MOV        this,dword ptr [EAX + 0x38]
//         00479813     PUSH       EBP=>DAT_fffffff4
//         00479814     PUSH       this=>DAT_fffffff0
//         00479815     CALL       dword ptr [->GDI32.DLL::GetTextExtentPoint32A]   = 0048b328
//                              Pnl_msg.cpp:349 (20)
//         0047981b     MOV        EAX,dword ptr [ESI + 0x328]
//         00479821     TEST       EAX,EAX
//         00479823     JZ         LAB_00479836
//         00479825     MOV        EDX,dword ptr [ESP + 0x18]
//         00479829     MOV        EAX,dword ptr [ESP + 0x40]
//         0047982d     CMP        EAX,EDX
//                              Pnl_msg.cpp:351 (7)
//         0047982f     MOV        EDI,0x10
//         00479834     JG         LAB_0047983b
//                               LAB_00479836                                                 XREF[1]:     00479823(j)
//                              Pnl_msg.cpp:355 (5)
//         00479836     MOV        EDI,0x20
//                               LAB_0047983b                                                 XREF[1]:     00479834(j)
//                              Pnl_msg.cpp:358 (11)
//         0047983b     MOV        EAX,dword ptr [ESI + 0x320]
//         00479841     CMP        EAX,0x4
//         00479844     JNZ        LAB_0047984b
//                              Pnl_msg.cpp:360 (3)
//         00479846     OR         EDI,0x1
//                              Pnl_msg.cpp:362 (7)
//         00479849     JMP        LAB_00479853
//                               LAB_0047984b                                                 XREF[1]:     00479844(j)
//         0047984b     CMP        EAX,0x3
//         0047984e     JNZ        LAB_00479853
//                              Pnl_msg.cpp:364 (3)
//         00479850     OR         EDI,0x2
//                               LAB_00479853                                                 XREF[2]:     00479849(j), 0047984e(j)
//                              Pnl_msg.cpp:371 (11)
//         00479853     MOV        EAX,dword ptr [ESI + 0x324]
//         00479859     CMP        EAX,0x4
//         0047985c     JNZ        LAB_00479862
//                              Pnl_msg.cpp:373 (2)
//         0047985e     OR         EDI,EAX
//                              Pnl_msg.cpp:375 (7)
//         00479860     JMP        LAB_0047986a
//                               LAB_00479862                                                 XREF[1]:     0047985c(j)
//         00479862     CMP        EAX,0x1
//         00479865     JNZ        LAB_0047986a
//                              Pnl_msg.cpp:377 (3)
//         00479867     OR         EDI,0x8
//                               LAB_0047986a                                                 XREF[4]:     004797ed(j), 004797f9(j),
//                                                                                                         00479860(j), 00479865(j)
//                              Pnl_msg.cpp:386 (14)
//         0047986a     MOV        EAX,dword ptr [ESI + 0x20]
//         0047986d     PUSH       EBX
//         0047986e     MOV        this,dword ptr [EAX + 0x38]
//         00479871     PUSH       this=>DAT_fffffff8
//         00479872     CALL       dword ptr [->GDI32.DLL::SetTextColor]            = 0048b318
//                              Pnl_msg.cpp:388 (72)
//         00479878     MOV        EDX,dword ptr [ESP + 0x1c]
//         0047987c     MOV        EAX,dword ptr [ESP + 0x10]
//         00479880     MOV        this,dword ptr [ESP + 0x18]
//         00479884     LEA        EBX,[EDX + EAX*0x1]
//         00479887     MOV        EDX,dword ptr [ESP + 0x14]
//         0047988b     ADD        this,EDX
//         0047988d     MOV        EDX,dword ptr [ESP + 0x10]
//         00479891     MOV        dword ptr [ESP + 0x18],this
//         00479895     ADD        this,-0x2
//         00479898     DEC        EDX
//         00479899     LEA        EAX,[EBX + -0x2]
//         0047989c     MOV        dword ptr [ESP + 0x1c],EDX
//         004798a0     MOV        EDX,dword ptr [ESP + 0x14]
//         004798a4     PUSH       EAX
//         004798a5     MOV        EAX,dword ptr [ESP + 0x20]
//         004798a9     MOV        dword ptr [ESP + 0x28],this
//         004798ad     DEC        EDX
//         004798ae     PUSH       this=>DAT_fffffff8
//         004798af     PUSH       EAX=>DAT_fffffff4
//         004798b0     LEA        this,[ESP + 0x54]
//         004798b4     PUSH       EDX=>DAT_fffffff0
//         004798b5     PUSH       this
//         004798b6     MOV        dword ptr [ESP + 0x3c],EDX
//         004798ba     CALL       dword ptr [->USER32.DLL::SetRect]                = 0048b002
//                              Pnl_msg.cpp:389 (22)
//         004798c0     MOV        EAX,dword ptr [ESI + 0x20]
//         004798c3     LEA        EDX,[ESP + 0x48]
//         004798c7     PUSH       EDI
//         004798c8     PUSH       EDX=>DAT_fffffff8
//         004798c9     MOV        this,dword ptr [EAX + 0x38]
//         004798cc     PUSH       offset DAT_fffffff4
//         004798ce     PUSH       EBP=>DAT_fffffff0
//         004798cf     PUSH       this
//         004798d0     CALL       dword ptr [->USER32.DLL::DrawTextA]              = 0048b10a
//                              Pnl_msg.cpp:391 (34)
//         004798d6     MOV        EDX,dword ptr [ESP + 0x10]
//         004798da     MOV        this,dword ptr [ESP + 0x24]
//         004798de     PUSH       EBX
//         004798df     PUSH       this=>DAT_fffffff8
//         004798e0     LEA        EAX,[EDX + 0x1]
//         004798e3     MOV        EDX,dword ptr [ESP + 0x30]
//         004798e7     MOV        dword ptr [ESP + 0x34],EAX
//         004798eb     PUSH       EAX=>DAT_fffffff4
//         004798ec     LEA        EAX,[ESP + 0x54]
//         004798f0     PUSH       EDX=>DAT_fffffff0
//         004798f1     PUSH       EAX
//         004798f2     CALL       dword ptr [->USER32.DLL::SetRect]                = 0048b002
//                              Pnl_msg.cpp:392 (22)
//         004798f8     MOV        EDX,dword ptr [ESI + 0x20]
//         004798fb     LEA        this,[ESP + 0x48]
//         004798ff     PUSH       EDI
//         00479900     PUSH       this=>DAT_fffffff8
//         00479901     MOV        EAX,dword ptr [EDX + 0x38]
//         00479904     PUSH       offset DAT_fffffff4
//         00479906     PUSH       EBP=>DAT_fffffff0
//         00479907     PUSH       EAX
//         00479908     CALL       dword ptr [->USER32.DLL::DrawTextA]              = 0048b10a
//                              Pnl_msg.cpp:394 (35)
//         0047990e     MOV        this,dword ptr [ESP + 0x14]
//         00479912     MOV        EDX,dword ptr [ESP + 0x18]
//         00479916     LEA        EAX,[EBX + -0x2]
//         00479919     INC        this
//         0047991a     PUSH       EAX
//         0047991b     MOV        EAX,dword ptr [ESP + 0x20]
//         0047991f     PUSH       EDX=>DAT_fffffff8
//         00479920     PUSH       EAX=>DAT_fffffff4
//         00479921     MOV        dword ptr [ESP + 0x34],this
//         00479925     PUSH       this=>DAT_fffffff0
//         00479926     LEA        this,[ESP + 0x58]
//         0047992a     PUSH       this
//         0047992b     CALL       dword ptr [->USER32.DLL::SetRect]                = 0048b002
//                              Pnl_msg.cpp:395 (22)
//         00479931     MOV        EAX,dword ptr [ESI + 0x20]
//         00479934     LEA        EDX,[ESP + 0x48]
//         00479938     PUSH       EDI
//         00479939     PUSH       EDX=>DAT_fffffff8
//         0047993a     MOV        this,dword ptr [EAX + 0x38]
//         0047993d     PUSH       offset DAT_fffffff4
//         0047993f     PUSH       EBP=>DAT_fffffff0
//         00479940     PUSH       this
//         00479941     CALL       dword ptr [->USER32.DLL::DrawTextA]              = 0048b10a
//                              Pnl_msg.cpp:397 (27)
//         00479947     MOV        EDX,dword ptr [ESP + 0x18]
//         0047994b     MOV        EAX,dword ptr [ESP + 0x2c]
//         0047994f     MOV        this,dword ptr [ESP + 0x28]
//         00479953     PUSH       EBX
//         00479954     PUSH       EDX=>DAT_fffffff8
//         00479955     PUSH       EAX=>DAT_fffffff4
//         00479956     LEA        EDX,[ESP + 0x54]
//         0047995a     PUSH       this=>DAT_fffffff0
//         0047995b     PUSH       EDX
//         0047995c     CALL       dword ptr [->USER32.DLL::SetRect]                = 0048b002
//                              Pnl_msg.cpp:398 (22)
//         00479962     MOV        this,dword ptr [ESI + 0x20]
//         00479965     LEA        EAX,[ESP + 0x48]
//         00479969     PUSH       EDI
//         0047996a     PUSH       EAX=>DAT_fffffff8
//         0047996b     MOV        EDX,dword ptr [ECX + this->_padding_]
//         0047996e     PUSH       offset DAT_fffffff4
//         00479970     PUSH       EBP=>DAT_fffffff0
//         00479971     PUSH       EDX
//         00479972     CALL       dword ptr [->USER32.DLL::DrawTextA]              = 0048b10a
//                              Pnl_msg.cpp:401 (18)
//         00479978     MOV        this,dword ptr [ESI + 0x20]
//         0047997b     MOV        EAX,dword ptr [ESP + 0x20]
//         0047997f     PUSH       EAX
//         00479980     MOV        EDX,dword ptr [ECX + this->_padding_]
//         00479983     PUSH       EDX=>DAT_fffffff8
//         00479984     CALL       dword ptr [->GDI32.DLL::SetTextColor]            = 0048b318
//                              Pnl_msg.cpp:403 (29)
//         0047998a     MOV        EAX,dword ptr [ESP + 0x18]
//         0047998e     MOV        this,dword ptr [ESP + 0x10]
//         00479992     MOV        EDX,dword ptr [ESP + 0x14]
//         00479996     DEC        EBX
//         00479997     DEC        EAX
//         00479998     PUSH       EBX
//         00479999     PUSH       EAX=>DAT_fffffff8
//         0047999a     PUSH       this=>DAT_fffffff4
//         0047999b     LEA        EAX,[ESP + 0x54]
//         0047999f     PUSH       EDX=>DAT_fffffff0
//         004799a0     PUSH       EAX
//         004799a1     CALL       dword ptr [->USER32.DLL::SetRect]                = 0048b002
//                              Pnl_msg.cpp:404 (22)
//         004799a7     MOV        EDX,dword ptr [ESI + 0x20]
//         004799aa     LEA        this,[ESP + 0x48]
//         004799ae     PUSH       EDI
//         004799af     PUSH       this=>DAT_fffffff8
//         004799b0     MOV        EAX,dword ptr [EDX + 0x38]
//         004799b3     PUSH       offset DAT_fffffff4
//         004799b5     PUSH       EBP=>DAT_fffffff0
//         004799b6     PUSH       EAX
//         004799b7     CALL       dword ptr [->USER32.DLL::DrawTextA]              = 0048b10a
//                              Pnl_msg.cpp:406 (18)
//         004799bd     MOV        EDX,dword ptr [ESI + 0x20]
//         004799c0     MOV        this,dword ptr [ESP + 0x30]
//         004799c4     PUSH       this
//         004799c5     MOV        EAX,dword ptr [EDX + 0x38]
//         004799c8     PUSH       EAX=>DAT_fffffff8
//         004799c9     CALL       dword ptr [->GDI32.DLL::SelectObject]            = 0048b192
//                              Pnl_msg.cpp:407 (15)
//         004799cf     MOV        this,dword ptr [ESI + 0x20]
//         004799d2     PUSH       0x0
//         004799d4     MOV        EDX,dword ptr [ECX + this->_padding_]
//         004799d7     PUSH       EDX=>DAT_fffffff8
//         004799d8     CALL       dword ptr [->GDI32.DLL::SelectClipRgn]           = 0048b2fc
//                              Pnl_msg.cpp:409 (17)
//         004799de     MOV        this,dword ptr [ESI + 0x20]
//         004799e1     PUSH       s_pnl_msg::draw                                  = "pnl_msg::draw"
//         004799e6     CALL       TDrawArea::ReleaseDc                             void ReleaseDc(TDrawArea * this, char * param
//         004799eb     MOV        EDI,dword ptr [ESP + 0x34]
//                              Symbol Ref: No symbol: finish_up
//                               LAB_004799ef                                                 XREF[2]:     00479665(j), 0047967a(j)
//                              Pnl_msg.cpp:414 (5)
//         004799ef     MOV        this,ESI
//         004799f1     CALL       dword ptr [EDI + 0x2c]
//                              Pnl_msg.cpp:415 (8)
//         004799f4     POP        EDI
//         004799f5     POP        ESI
//         004799f6     POP        EBP
//         004799f7     POP        EBX
//         004799f8     ADD        ESP,0x48
//         004799fb     RET
//                               LAB_004799fc                                                 XREF[4]:     0047959e(j), 004795a9(j),
//                                                                                                         004795b4(j), 004795c2(j)
//                              Pnl_msg.cpp:267 (7)
//         004799fc     MOV        dword ptr [ESI + 0x38],0x0
//                              Pnl_msg.cpp:415 (8)
//         00479a03     POP        EDI
//         00479a04     POP        ESI
//         00479a05     POP        EBP
//         00479a06     POP        EBX
//         00479a07     ADD        ESP,0x48
//         00479a0a     RET
//         00479a0b     ??         90h
//         00479a0c     NOP
//         00479a0d     NOP
//         00479a0e     NOP
//         00479a0f     NOP
    return;
}

void TMessagePanel::get_true_render_rect(tagRECT* param_1) {
    /* TODO: Stub */
//                              void __thiscall get_true_render_rect(TMessagePanel * this, tagRECT *
//              void              <VOID>         <RETURN>
//              TMessagePanel *   ECX:4 (auto)   this
//              tagRECT *         Stack[0x4]:4   param_1                   XREF[2]:     00479a39(R), 00479a5c(R)
//                               ?get_true_render_rect@TMessagePanel@@UAEXAAUtagRECT@@@Z      XREF[1]:     00571720(*)
//                               TMessagePanel::get_true_render_rect
//                              Pnl_msg.cpp:423 (41)
//         00479a10     MOV        EAX,dword ptr [ECX + this->ImageBuffer]
//         00479a16     TEST       EAX,EAX
//         00479a18     JZ         LAB_00479a5c
//         00479a1a     MOV        EAX,dword ptr [ECX + this->_padding_]
//         00479a1d     TEST       EAX,EAX
//         00479a1f     JZ         LAB_00479a5c
//         00479a21     MOV        EAX,dword ptr [ECX + this->_padding_]
//         00479a24     TEST       EAX,EAX
//         00479a26     JZ         LAB_00479a5c
//         00479a28     MOV        EAX,dword ptr [ECX + this->_padding_]
//         00479a2b     TEST       EAX,EAX
//         00479a2d     JZ         LAB_00479a5c
//         00479a2f     MOV        EAX,dword ptr [ECX + this->showing_message]
//         00479a35     TEST       EAX,EAX
//         00479a37     JZ         LAB_00479a5c
//                              Pnl_msg.cpp:429 (32)
//         00479a39     MOV        EAX,dword ptr [ESP + param_1]
//         00479a3d     ADD        this,0x354
//         00479a43     MOV        EDX,dword ptr [this->_padding_]
//         00479a45     MOV        dword ptr [EAX],EDX
//         00479a47     MOV        EDX,dword ptr [ECX + this->_padding_]
//         00479a4a     MOV        dword ptr [EAX + 0x4],EDX
//         00479a4d     MOV        EDX,dword ptr [ECX + this->_padding_]
//         00479a50     MOV        dword ptr [EAX + 0x8],EDX
//         00479a53     MOV        this,dword ptr [ECX + this->_padding_]
//         00479a56     MOV        dword ptr [EAX + 0xc],this
//                              Pnl_msg.cpp:431 (3)
//         00479a59     RET        0x4
//                               LAB_00479a5c                                                 XREF[5]:     00479a18(j), 00479a1f(j),
//                                                                                                         00479a26(j), 00479a2d(j),
//                                                                                                         00479a37(j)
//                              Pnl_msg.cpp:427 (32)
//         00479a5c     MOV        EDX,dword ptr [ESP + param_1]
//         00479a60     ADD        this,0x8c
//         00479a66     MOV        EAX,dword ptr [this->_padding_]
//         00479a68     MOV        dword ptr [EDX],EAX
//         00479a6a     MOV        EAX,dword ptr [ECX + this->_padding_]
//         00479a6d     MOV        dword ptr [EDX + 0x4],EAX
//         00479a70     MOV        EAX,dword ptr [ECX + this->_padding_]
//         00479a73     MOV        dword ptr [EDX + 0x8],EAX
//         00479a76     MOV        this,dword ptr [ECX + this->_padding_]
//         00479a79     MOV        dword ptr [EDX + 0xc],this
//                              Pnl_msg.cpp:431 (3)
//         00479a7c     RET        0x4
//         00479a7f     ??         90h
    return;
}

long TMessagePanel::handle_idle() {
    /* TODO: Stub */
//                              long __thiscall handle_idle(TMessagePanel * this)
//              long              EAX:4          <RETURN>
//              TMessagePanel *   ECX:4 (auto)   this
//                               ?handle_idle@TMessagePanel@@UAEJXZ                           XREF[1]:     005716b4(*)
//                               TMessagePanel::handle_idle
//                              Pnl_msg.cpp:438 (3)
//         00479a80     PUSH       ESI
//         00479a81     MOV        ESI,this
//                              Pnl_msg.cpp:440 (38)
//         00479a83     MOV        EAX,dword ptr [ESI + 0x6c]
//         00479a86     TEST       EAX,EAX
//         00479a88     JZ         LAB_00479ad4
//         00479a8a     MOV        EAX,dword ptr [ESI + 0x2f8]
//         00479a90     TEST       EAX,EAX
//         00479a92     JZ         LAB_00479ad4
//         00479a94     MOV        EAX,dword ptr [ESI + 0xf4]
//         00479a9a     CMP        EAX,0x1
//         00479a9d     JZ         LAB_00479aa9
//         00479a9f     CMP        EAX,0x3
//         00479aa2     JZ         LAB_00479aa9
//         00479aa4     CMP        EAX,0x4
//         00479aa7     JNZ        LAB_00479ad4
//                               LAB_00479aa9                                                 XREF[2]:     00479a9d(j), 00479aa2(j)
//                              Pnl_msg.cpp:442 (36)
//         00479aa9     PUSH       0x1ba
//         00479aae     PUSH       s_C:\msdev\work\age1_x1\Pnl_msg.cp               = "C:\\msdev\\work\\age1_x1\\Pnl_msg.cpp"
//         00479ab3     CALL       debug_timeGetTime                                ulong debug_timeGetTime(char * param_1, int p
//         00479ab8     MOV        EDX,dword ptr [ESI + 0x2fc]
//         00479abe     MOV        this,dword ptr [ESI + 0x300]
//         00479ac4     SUB        EAX,EDX
//         00479ac6     ADD        ESP,0x8
//         00479ac9     CMP        EAX,this
//         00479acb     JL         LAB_00479ad4
//                              Pnl_msg.cpp:443 (7)
//         00479acd     MOV        this,ESI
//         00479acf     CALL       TMessagePanel::remove_message                    void remove_message(TMessagePanel * this)
//                               LAB_00479ad4                                                 XREF[4]:     00479a88(j), 00479a92(j),
//                                                                                                         00479aa7(j), 00479acb(j)
//                              Pnl_msg.cpp:445 (2)
//         00479ad4     XOR        EAX,EAX
//                              Pnl_msg.cpp:446 (2)
//         00479ad6     POP        ESI
//         00479ad7     RET
//         00479ad8     ??         90h
//         00479ad9     NOP
//         00479ada     NOP
//         00479adb     NOP
//         00479adc     NOP
//         00479add     NOP
//         00479ade     NOP
//         00479adf     NOP
    return 0;
}

int TMessagePanel::render_to_image_buffer() {
    /* TODO: Stub */
//                              int __thiscall render_to_image_buffer(TMessagePanel * this)
//              int               EAX:4          <RETURN>
//              TMessagePanel *   ECX:4 (auto)   this
//              tagRECT           Stack[-0x14]   rect
//              tagSIZE           Stack[-0x1c]:8 ts
//              tagPALETTEENTRY   Stack[-0x24]:4 paletteColor
//              void *            Stack[-0x28]:4 old_font
//              ulong             Stack[-0x2c]:4 font_rgb
//              long              Stack[-0x30]:4 hgt
//              ulong             Stack[-0x34]:4 back_rgb
//              long              Stack[-0x38]:4 wid
//              long              Stack[-0x3c]:4 y
//              int               Stack[-0x40]:4 Display_hgt
//              long              Stack[-0x44]:4 x
//                               ?render_to_image_buffer@TMessagePanel@@IAEHXZ                XREF[3]:     show_message:0047938b(c),
//                               TMessagePanel::render_to_image_buffer                                     show_message2:00479508(c),
//                                                                                                         draw:004795f3(c)
//                              Pnl_msg.cpp:455 (9)
//         00479ae0     SUB        ESP,0x40
//         00479ae3     PUSH       EBX
//         00479ae4     PUSH       EBP
//         00479ae5     PUSH       ESI
//         00479ae6     MOV        ESI,this
//         00479ae8     PUSH       EDI
//                              Pnl_msg.cpp:472 (12)
//         00479ae9     MOV        this,dword ptr [ESI + 0x330]
//         00479aef     TEST       this,this
//         00479af1     JNZ        LAB_00479afd
//         00479af3     XOR        EAX,EAX
//                              Pnl_msg.cpp:694 (8)
//         00479af5     POP        EDI
//         00479af6     POP        ESI
//         00479af7     POP        EBP
//         00479af8     POP        EBX
//         00479af9     ADD        ESP,0x40
//         00479afc     RET
//                               LAB_00479afd                                                 XREF[1]:     00479af1(j)
//                              Pnl_msg.cpp:477 (14)
//         00479afd     LEA        EBX,[ESI + 0x334]
//         00479b03     PUSH       0x1
//         00479b05     PUSH       EBX
//         00479b06     CALL       TDrawArea::PtrClear                              void PtrClear(TDrawArea * this, tagRECT * par
//                              Pnl_msg.cpp:481 (16)
//         00479b0b     MOV        AL,byte ptr [ESI + 0xf8]
//         00479b11     LEA        EDI,[ESI + 0xf8]
//         00479b17     TEST       AL,AL
//         00479b19     JNZ        LAB_00479b68
//                              Pnl_msg.cpp:483 (23)
//         00479b1b     MOV        EDI,dword ptr [->USER32.DLL::SetRect]            = 0048b002
//         00479b21     PUSH       0x1
//         00479b23     PUSH       0x1
//         00479b25     PUSH       0x0
//         00479b27     LEA        EAX,[ESI + 0x344]
//         00479b2d     PUSH       0x0
//         00479b2f     PUSH       EAX
//         00479b30     CALL       EDI=>USER32.DLL::SetRect
//                              Pnl_msg.cpp:484 (31)
//         00479b32     MOV        EAX,dword ptr [ESI + 0x90]
//         00479b38     MOV        this,dword ptr [ESI + 0x8c]
//         00479b3e     LEA        EDX,[EAX + 0x1]
//         00479b41     PUSH       EDX
//         00479b42     LEA        EDX,[ECX + this+0x1]
//         00479b45     PUSH       EDX
//         00479b46     PUSH       EAX
//         00479b47     LEA        EAX,[ESI + 0x354]
//         00479b4d     PUSH       this
//         00479b4e     PUSH       EAX
//         00479b4f     CALL       EDI=>USER32.DLL::SetRect
//                              Pnl_msg.cpp:485 (10)
//         00479b51     MOV        dword ptr [ESI + 0x36c],0x1
//                              Pnl_msg.cpp:486 (5)
//         00479b5b     MOV        EAX,0x1
//                              Pnl_msg.cpp:694 (8)
//         00479b60     POP        EDI
//         00479b61     POP        ESI
//         00479b62     POP        EBP
//         00479b63     POP        EBX
//         00479b64     ADD        ESP,0x40
//         00479b67     RET
//                               LAB_00479b68                                                 XREF[1]:     00479b19(j)
//                              Pnl_msg.cpp:491 (20)
//         00479b68     MOV        this,dword ptr [ESI + 0x330]
//         00479b6e     PUSH       s_pnl_msg::render_to_image_buffer                = "pnl_msg::render_to_image_buffer"
//         00479b73     CALL       TDrawArea::GetDc                                 void * GetDc(TDrawArea * this, char * param_1)
//         00479b78     TEST       EAX,EAX
//         00479b7a     JNZ        LAB_00479b84
//                              Pnl_msg.cpp:694 (8)
//         00479b7c     POP        EDI
//         00479b7d     POP        ESI
//         00479b7e     POP        EBP
//         00479b7f     POP        EBX
//         00479b80     ADD        ESP,0x40
//         00479b83     RET
//                               LAB_00479b84                                                 XREF[1]:     00479b7a(j)
//                              Pnl_msg.cpp:495 (12)
//         00479b84     MOV        this,dword ptr [ESI + 0x330]
//         00479b8a     PUSH       EBX
//         00479b8b     CALL       TDrawArea::SetClipRect                           void SetClipRect(TDrawArea * this, tagRECT *
//                              Pnl_msg.cpp:496 (23)
//         00479b90     MOV        EDX,dword ptr [ESI + 0x330]
//         00479b96     MOV        this,dword ptr [ESI + 0x32c]
//         00479b9c     PUSH       this
//         00479b9d     MOV        EAX,dword ptr [EDX + 0x38]
//         00479ba0     PUSH       EAX
//         00479ba1     CALL       dword ptr [->GDI32.DLL::SelectClipRgn]           = 0048b2fc
//                              Pnl_msg.cpp:499 (27)
//         00479ba7     MOV        EDX,dword ptr [ESI + 0x330]
//         00479bad     MOV        this,dword ptr [ESI + 0x304]
//         00479bb3     PUSH       this
//         00479bb4     MOV        EAX,dword ptr [EDX + 0x38]
//         00479bb7     PUSH       EAX
//         00479bb8     CALL       dword ptr [->GDI32.DLL::SelectObject]            = 0048b192
//         00479bbe     MOV        dword ptr [ESP + 0x2c],EAX
//                              Pnl_msg.cpp:502 (14)
//         00479bc2     MOV        EAX,dword ptr [ESI + 0x314]
//         00479bc8     TEST       EAX,EAX
//         00479bca     JZ         LAB_00479c67
//                              Pnl_msg.cpp:504 (36)
//         00479bd0     MOV        EAX,[rge_base_game]                              = 00000000
//         00479bd5     LEA        this,[ESP + 0x30]
//         00479bd9     MOV        EBP,dword ptr [->GDI32.DLL::GetPaletteEntries]   = 0048b270
//         00479bdf     XOR        EDX,EDX
//         00479be1     MOV        DL,byte ptr [ESI + 0x310]
//         00479be7     PUSH       this
//         00479be8     MOV        this,dword ptr [EAX + 0x48]
//         00479beb     PUSH       0x1
//         00479bed     PUSH       EDX
//         00479bee     MOV        EDX,dword ptr [ECX + this->_padding_]
//         00479bf1     PUSH       EDX
//         00479bf2     CALL       EBP=>GDI32.DLL::GetPaletteEntries
//                              Pnl_msg.cpp:505 (34)
//         00479bf4     MOV        EAX,dword ptr [ESP + 0x32]
//         00479bf8     MOV        this,dword ptr [ESP + 0x31]
//         00479bfc     MOV        EDX,dword ptr [ESP + 0x30]
//         00479c00     AND        EAX,0xff
//         00479c05     SHL        EAX,0x8
//         00479c08     AND        this,0xff
//         00479c0e     AND        EDX,0xff
//         00479c14     OR         EAX,this
//                              Pnl_msg.cpp:507 (40)
//         00479c16     XOR        this,this
//         00479c18     SHL        EAX,0x8
//         00479c1b     MOV        this,byte ptr [ESI + 0x311]
//         00479c21     OR         EAX,EDX
//         00479c23     MOV        EDX,dword ptr [rge_base_game]                    = 00000000
//         00479c29     MOV        dword ptr [ESP + 0x28],EAX
//         00479c2d     LEA        EAX,[ESP + 0x30]
//         00479c31     PUSH       EAX
//         00479c32     MOV        EAX,dword ptr [EDX + 0x48]
//         00479c35     PUSH       0x1
//         00479c37     PUSH       this
//         00479c38     MOV        this,dword ptr [EAX + 0x8]
//         00479c3b     PUSH       this
//         00479c3c     CALL       EBP=>GDI32.DLL::GetPaletteEntries
//                              Pnl_msg.cpp:508 (39)
//         00479c3e     MOV        EAX,dword ptr [ESP + 0x32]
//         00479c42     MOV        EDX,dword ptr [ESP + 0x31]
//         00479c46     MOV        this,dword ptr [ESP + 0x30]
//         00479c4a     AND        EAX,0xff
//         00479c4f     SHL        EAX,0x8
//         00479c52     AND        EDX,0xff
//         00479c58     AND        this,0xff
//         00479c5e     OR         EAX,EDX
//         00479c60     SHL        EAX,0x8
//         00479c63     OR         EAX,this
//                              Pnl_msg.cpp:510 (2)
//         00479c65     JMP        LAB_00479c77
//                               LAB_00479c67                                                 XREF[1]:     00479bca(j)
//                              Pnl_msg.cpp:512 (6)
//         00479c67     MOV        EDX,dword ptr [ESI + 0x318]
//                              Pnl_msg.cpp:513 (14)
//         00479c6d     MOV        EAX,dword ptr [ESI + 0x31c]
//         00479c73     MOV        dword ptr [ESP + 0x28],EDX
//                               LAB_00479c77                                                 XREF[1]:     00479c65(j)
//         00479c77     MOV        dword ptr [ESP + 0x20],EAX
//                              Pnl_msg.cpp:517 (11)
//         00479c7b     MOV        EAX,dword ptr [ESI + 0xf4]
//         00479c81     CMP        EAX,0x2
//         00479c84     JNZ        LAB_00479ca6
//                              Pnl_msg.cpp:519 (18)
//         00479c86     MOV        this,dword ptr [ESI + 0x330]
//         00479c8c     PUSH       0x0
//         00479c8e     MOV        EDX,dword ptr [ECX + this->_padding_]
//         00479c91     PUSH       EDX
//         00479c92     CALL       dword ptr [->GDI32.DLL::SetBkColor]              = 0048b34c
//                              Pnl_msg.cpp:520 (12)
//         00479c98     MOV        EAX,dword ptr [ESI + 0x330]
//         00479c9e     PUSH       0x2
//         00479ca0     MOV        this,dword ptr [EAX + 0x38]
//         00479ca3     PUSH       this
//                              Pnl_msg.cpp:522 (2)
//         00479ca4     JMP        LAB_00479cb2
//                               LAB_00479ca6                                                 XREF[1]:     00479c84(j)
//                              Pnl_msg.cpp:524 (18)
//         00479ca6     MOV        EDX,dword ptr [ESI + 0x330]
//         00479cac     PUSH       0x1
//         00479cae     MOV        EAX,dword ptr [EDX + 0x38]
//         00479cb1     PUSH       EAX
//                               LAB_00479cb2                                                 XREF[1]:     00479ca4(j)
//         00479cb2     CALL       dword ptr [->GDI32.DLL::SetBkMode]               = 0048b340
//                              Pnl_msg.cpp:529 (18)
//         00479cb8     MOV        EAX,dword ptr [ESI + 0x14]
//         00479cbb     MOV        EBP,dword ptr [EBX]
//         00479cbd     MOV        EBX,dword ptr [ESI + 0x338]
//         00479cc3     SUB        EAX,0x2
//         00479cc6     MOV        dword ptr [ESP + 0x1c],EAX
//                              Pnl_msg.cpp:530 (6)
//         00479cca     MOV        EAX,dword ptr [ESI + 0x18]
//         00479ccd     SUB        EAX,0x2
//                              Pnl_msg.cpp:533 (57)
//         00479cd0     LEA        this,[ESP + 0x38]
//         00479cd4     MOV        dword ptr [ESP + 0x24],EAX
//         00479cd8     PUSH       this
//         00479cd9     INC        EBP
//         00479cda     OR         this,0xffffffff
//         00479cdd     XOR        EAX,EAX
//         00479cdf     INC        EBX
//         00479ce0     SCASB.RE   ES:EDI
//         00479ce2     MOV        EDX,dword ptr [ESI + 0x330]
//         00479ce8     LEA        EAX,[ESI + 0xf8]
//         00479cee     NOT        this
//         00479cf0     DEC        this
//         00479cf1     MOV        dword ptr [ESP + 0x14],EBP
//         00479cf5     PUSH       this
//         00479cf6     PUSH       EAX
//         00479cf7     MOV        EAX,dword ptr [EDX + 0x38]
//         00479cfa     MOV        dword ptr [ESP + 0x24],EBX
//         00479cfe     PUSH       EAX
//         00479cff     CALL       dword ptr [->GDI32.DLL::GetTextExtentPoint32A]   = 0048b328
//         00479d05     TEST       EAX,EAX
//         00479d07     JNZ        LAB_00479d4c
//                              Pnl_msg.cpp:535 (35)
//         00479d09     MOV        this,dword ptr [ESP + 0x24]
//         00479d0d     MOV        EAX,dword ptr [ESP + 0x1c]
//         00479d11     MOV        EDI,dword ptr [->USER32.DLL::SetRect]            = 0048b002
//         00479d17     LEA        EDX,[this->_padding_ + EBX*0x1 + -0x2]
//         00479d1b     LEA        this,[EAX + EBP*0x1 + -0x2]
//         00479d1f     PUSH       EDX
//         00479d20     DEC        EBX
//         00479d21     PUSH       this
//         00479d22     DEC        EBP
//         00479d23     PUSH       EBX
//         00479d24     LEA        EDX,[ESP + 0x4c]
//         00479d28     PUSH       EBP
//         00479d29     PUSH       EDX
//         00479d2a     CALL       EDI=>USER32.DLL::SetRect
//                              Pnl_msg.cpp:536 (17)
//         00479d2c     PUSH       0x1
//         00479d2e     PUSH       0x1
//         00479d30     LEA        EAX,[ESI + 0x344]
//         00479d36     PUSH       0x0
//         00479d38     PUSH       0x0
//         00479d3a     PUSH       EAX
//         00479d3b     CALL       EDI=>USER32.DLL::SetRect
//                              Pnl_msg.cpp:537 (10)
//         00479d3d     MOV        dword ptr [ESI + 0x36c],0x0
//                              Pnl_msg.cpp:694 (5)
//         00479d47     JMP        LAB_0047a0d5
//                               LAB_00479d4c                                                 XREF[1]:     00479d07(j)
//                              Pnl_msg.cpp:543 (8)
//         00479d4c     MOV        EAX,dword ptr [ESP + 0x3c]
//         00479d50     MOV        EBX,dword ptr [ESP + 0x38]
//                              Pnl_msg.cpp:547 (25)
//         00479d54     MOV        EDI,dword ptr [ESI + 0xf4]
//         00479d5a     ADD        EAX,0x2
//         00479d5d     MOV        dword ptr [ESP + 0x14],EAX
//         00479d61     XOR        this,this
//         00479d63     XOR        EAX,EAX
//         00479d65     CMP        EDI,0x1
//         00479d68     LEA        EDX,[EBX + 0x2]
//         00479d6b     JNZ        LAB_00479d7f
//                              Pnl_msg.cpp:550 (13)
//         00479d6d     MOV        EAX,dword ptr [ESI + 0x14]
//         00479d70     MOV        EDI,0x21
//         00479d75     SUB        EAX,EDX
//         00479d77     SAR        EAX,0x1
//         00479d79     DEC        EAX
//                              Pnl_msg.cpp:552 (10)
//         00479d7a     JMP        LAB_00479e4a
//                               LAB_00479d7f                                                 XREF[1]:     00479d6b(j)
//         00479d7f     CMP        EDI,0x5
//         00479d82     JNZ        LAB_00479d96
//                              Pnl_msg.cpp:555 (11)
//         00479d84     MOV        EAX,dword ptr [ESI + 0x14]
//         00479d87     MOV        EDI,0x22
//         00479d8c     SUB        EAX,EDX
//         00479d8e     DEC        EAX
//                              Pnl_msg.cpp:556 (2)
//         00479d8f     XOR        this,this
//                              Pnl_msg.cpp:558 (5)
//         00479d91     JMP        LAB_00479e4a
//                               LAB_00479d96                                                 XREF[1]:     00479d82(j)
//                              Pnl_msg.cpp:560 (16)
//         00479d96     MOV        EDX,dword ptr [ESI + 0x328]
//         00479d9c     TEST       EDX,EDX
//         00479d9e     JZ         LAB_00479dbd
//         00479da0     CMP        EBX,dword ptr [ESP + 0x1c]
//         00479da4     JLE        LAB_00479dbd
//                              Pnl_msg.cpp:564 (10)
//         00479da6     MOV        this,dword ptr [ESI + 0x18]
//         00479da9     MOV        EDX,dword ptr [ESI + 0x14]
//         00479dac     MOV        dword ptr [ESP + 0x14],this
//                              Pnl_msg.cpp:565 (2)
//         00479db0     XOR        EAX,EAX
//                              Pnl_msg.cpp:566 (7)
//         00479db2     XOR        this,this
//         00479db4     MOV        EDI,0x10
//                              Pnl_msg.cpp:567 (2)
//         00479db9     XOR        EBX,EBX
//                              Pnl_msg.cpp:569 (2)
//         00479dbb     JMP        LAB_00479dd3
//                               LAB_00479dbd                                                 XREF[2]:     00479d9e(j), 00479da4(j)
//                              Pnl_msg.cpp:572 (3)
//         00479dbd     LEA        EDX,[EBX + 0x1]
//                              Pnl_msg.cpp:573 (14)
//         00479dc0     MOV        EBX,dword ptr [ESP + 0x3c]
//         00479dc4     INC        EBX
//         00479dc5     MOV        EDI,0x20
//         00479dca     MOV        dword ptr [ESP + 0x14],EBX
//                              Pnl_msg.cpp:574 (5)
//         00479dce     MOV        EBX,0x1
//                               LAB_00479dd3                                                 XREF[1]:     00479dbb(j)
//                              Pnl_msg.cpp:579 (11)
//         00479dd3     MOV        EBP,dword ptr [ESI + 0x320]
//         00479dd9     CMP        EBP,0x4
//         00479ddc     JNZ        LAB_00479def
//                              Pnl_msg.cpp:581 (3)
//         00479dde     OR         EDI,0x1
//                              Pnl_msg.cpp:582 (12)
//         00479de1     TEST       EBX,EBX
//         00479de3     JZ         LAB_00479e09
//         00479de5     MOV        EAX,dword ptr [ESI + 0x14]
//         00479de8     SUB        EAX,EDX
//         00479dea     SAR        EAX,0x1
//         00479dec     DEC        EAX
//                              Pnl_msg.cpp:584 (7)
//         00479ded     JMP        LAB_00479e09
//                               LAB_00479def                                                 XREF[1]:     00479ddc(j)
//         00479def     CMP        EBP,0x3
//         00479df2     JNZ        LAB_00479e03
//                              Pnl_msg.cpp:586 (3)
//         00479df4     OR         EDI,0x2
//                              Pnl_msg.cpp:587 (10)
//         00479df7     TEST       EBX,EBX
//         00479df9     JZ         LAB_00479e09
//         00479dfb     MOV        EAX,dword ptr [ESI + 0x14]
//         00479dfe     SUB        EAX,EDX
//         00479e00     DEC        EAX
//                              Pnl_msg.cpp:589 (2)
//         00479e01     JMP        LAB_00479e09
//                               LAB_00479e03                                                 XREF[1]:     00479df2(j)
//                              Pnl_msg.cpp:592 (6)
//         00479e03     TEST       EBX,EBX
//         00479e05     JZ         LAB_00479e09
//         00479e07     XOR        EAX,EAX
//                               LAB_00479e09                                                 XREF[5]:     00479de3(j), 00479ded(j),
//                                                                                                         00479df9(j), 00479e01(j),
//                                                                                                         00479e05(j)
//                              Pnl_msg.cpp:597 (11)
//         00479e09     MOV        EBP,dword ptr [ESI + 0x324]
//         00479e0f     CMP        EBP,0x4
//         00479e12     JNZ        LAB_00479e28
//                              Pnl_msg.cpp:599 (2)
//         00479e14     OR         EDI,EBP
//                              Pnl_msg.cpp:600 (16)
//         00479e16     TEST       EBX,EBX
//         00479e18     JZ         LAB_00479e46
//         00479e1a     MOV        this,dword ptr [ESI + 0x18]
//         00479e1d     MOV        EBX,dword ptr [ESP + 0x14]
//         00479e21     SUB        this,EBX
//         00479e23     SAR        this,0x1
//         00479e25     DEC        this
//                              Pnl_msg.cpp:602 (7)
//         00479e26     JMP        LAB_00479e46
//                               LAB_00479e28                                                 XREF[1]:     00479e12(j)
//         00479e28     CMP        EBP,0x1
//         00479e2b     JNZ        LAB_00479e40
//                              Pnl_msg.cpp:604 (3)
//         00479e2d     OR         EDI,0x8
//                              Pnl_msg.cpp:605 (14)
//         00479e30     TEST       EBX,EBX
//         00479e32     JZ         LAB_00479e46
//         00479e34     MOV        this,dword ptr [ESI + 0x18]
//         00479e37     MOV        EBP,dword ptr [ESP + 0x14]
//         00479e3b     SUB        this,EBP
//         00479e3d     DEC        this
//                              Pnl_msg.cpp:607 (2)
//         00479e3e     JMP        LAB_00479e46
//                               LAB_00479e40                                                 XREF[1]:     00479e2b(j)
//                              Pnl_msg.cpp:610 (10)
//         00479e40     TEST       EBX,EBX
//         00479e42     JZ         LAB_00479e46
//         00479e44     XOR        this,this
//                               LAB_00479e46                                                 XREF[5]:     00479e18(j), 00479e26(j),
//                                                                                                         00479e32(j), 00479e3e(j),
//                                                                                                         00479e42(j)
//         00479e46     MOV        EBP,dword ptr [ESP + 0x10]
//                               LAB_00479e4a                                                 XREF[2]:     00479d7a(j), 00479d91(j)
//                              Pnl_msg.cpp:617 (6)
//         00479e4a     TEST       this,this
//         00479e4c     JGE        LAB_00479e50
//         00479e4e     XOR        this,this
//                               LAB_00479e50                                                 XREF[1]:     00479e4c(j)
//                              Pnl_msg.cpp:618 (6)
//         00479e50     TEST       EAX,EAX
//         00479e52     JGE        LAB_00479e56
//         00479e54     XOR        EAX,EAX
//                               LAB_00479e56                                                 XREF[1]:     00479e52(j)
//                              Pnl_msg.cpp:620 (6)
//         00479e56     MOV        dword ptr [ESI + 0x344],EAX
//                              Pnl_msg.cpp:622 (2)
//         00479e5c     ADD        EAX,EDX
//                              Pnl_msg.cpp:623 (12)
//         00479e5e     MOV        EDX,dword ptr [ESP + 0x14]
//         00479e62     MOV        dword ptr [ESI + 0x348],this
//         00479e68     ADD        this,EDX
//                              Pnl_msg.cpp:625 (28)
//         00479e6a     MOV        EDX,dword ptr [ESI + 0x33c]
//         00479e70     CMP        EAX,EDX
//         00479e72     MOV        dword ptr [ESI + 0x34c],EAX
//         00479e78     MOV        dword ptr [ESI + 0x350],this
//         00479e7e     JLE        LAB_00479e86
//         00479e80     MOV        dword ptr [ESI + 0x34c],EDX
//                               LAB_00479e86                                                 XREF[1]:     00479e7e(j)
//                              Pnl_msg.cpp:626 (16)
//         00479e86     MOV        EAX,dword ptr [ESI + 0x340]
//         00479e8c     CMP        this,EAX
//         00479e8e     JLE        LAB_00479e96
//         00479e90     MOV        dword ptr [ESI + 0x350],EAX
//                               LAB_00479e96                                                 XREF[1]:     00479e8e(j)
//                              Pnl_msg.cpp:629 (21)
//         00479e96     MOV        this,dword ptr [ESI + 0x330]
//         00479e9c     MOV        EAX,dword ptr [ESP + 0x20]
//         00479ea0     PUSH       EAX
//         00479ea1     MOV        EDX,dword ptr [ECX + this->_padding_]
//         00479ea4     PUSH       EDX
//         00479ea5     CALL       dword ptr [->GDI32.DLL::SetTextColor]            = 0048b318
//                              Pnl_msg.cpp:632 (60)
//         00479eab     MOV        EAX,dword ptr [ESP + 0x24]
//         00479eaf     MOV        this,dword ptr [ESP + 0x18]
//         00479eb3     MOV        EDX,dword ptr [ESP + 0x1c]
//         00479eb7     ADD        EBP,EDX
//         00479eb9     MOV        EDX,dword ptr [ESP + 0x18]
//         00479ebd     LEA        EBX,[EAX + this->_padding_*0x1]
//         00479ec0     DEC        EDX
//         00479ec1     MOV        dword ptr [ESP + 0x24],EDX
//         00479ec5     MOV        EDX,dword ptr [ESP + 0x10]
//         00479ec9     LEA        EAX,[EBX + -0x2]
//         00479ecc     LEA        this,[EBP + -0x2]
//         00479ecf     PUSH       EAX
//         00479ed0     MOV        EAX,dword ptr [ESP + 0x28]
//         00479ed4     DEC        EDX
//         00479ed5     PUSH       this
//         00479ed6     PUSH       EAX
//         00479ed7     LEA        this,[ESP + 0x4c]
//         00479edb     PUSH       EDX
//         00479edc     PUSH       this
//         00479edd     MOV        dword ptr [ESP + 0x34],EDX
//         00479ee1     CALL       dword ptr [->USER32.DLL::SetRect]                = 0048b002
//                              Pnl_msg.cpp:633 (31)
//         00479ee7     LEA        EDX,[ESP + 0x40]
//         00479eeb     PUSH       EDI
//         00479eec     PUSH       EDX
//         00479eed     LEA        EAX,[ESI + 0xf8]
//         00479ef3     PUSH       -0x1
//         00479ef5     PUSH       EAX
//         00479ef6     MOV        EAX,dword ptr [ESI + 0x330]
//         00479efc     MOV        this,dword ptr [EAX + 0x38]
//         00479eff     PUSH       this
//         00479f00     CALL       dword ptr [->USER32.DLL::DrawTextA]              = 0048b10a
//                              Pnl_msg.cpp:635 (33)
//         00479f06     MOV        EDX,dword ptr [ESP + 0x18]
//         00479f0a     LEA        EAX,[EBP + -0x2]
//         00479f0d     PUSH       EBX
//         00479f0e     PUSH       EAX
//         00479f0f     MOV        EAX,dword ptr [ESP + 0x28]
//         00479f13     LEA        this,[EDX + 0x1]
//         00479f16     MOV        dword ptr [ESP + 0x24],this
//         00479f1a     PUSH       this
//         00479f1b     LEA        this,[ESP + 0x4c]
//         00479f1f     PUSH       EAX
//         00479f20     PUSH       this
//         00479f21     CALL       dword ptr [->USER32.DLL::SetRect]                = 0048b002
//                              Pnl_msg.cpp:636 (31)
//         00479f27     LEA        EDX,[ESP + 0x40]
//         00479f2b     PUSH       EDI
//         00479f2c     PUSH       EDX
//         00479f2d     LEA        EAX,[ESI + 0xf8]
//         00479f33     PUSH       -0x1
//         00479f35     PUSH       EAX
//         00479f36     MOV        EAX,dword ptr [ESI + 0x330]
//         00479f3c     MOV        this,dword ptr [EAX + 0x38]
//         00479f3f     PUSH       this
//         00479f40     CALL       dword ptr [->USER32.DLL::DrawTextA]              = 0048b10a
//                              Pnl_msg.cpp:638 (33)
//         00479f46     MOV        EDX,dword ptr [ESP + 0x10]
//         00479f4a     LEA        EAX,[EBX + -0x2]
//         00479f4d     PUSH       EAX
//         00479f4e     MOV        EAX,dword ptr [ESP + 0x28]
//         00479f52     LEA        this,[EDX + 0x1]
//         00479f55     PUSH       EBP
//         00479f56     PUSH       EAX
//         00479f57     MOV        dword ptr [ESP + 0x2c],this
//         00479f5b     PUSH       this
//         00479f5c     LEA        this,[ESP + 0x50]
//         00479f60     PUSH       this
//         00479f61     CALL       dword ptr [->USER32.DLL::SetRect]                = 0048b002
//                              Pnl_msg.cpp:639 (31)
//         00479f67     LEA        EDX,[ESP + 0x40]
//         00479f6b     PUSH       EDI
//         00479f6c     PUSH       EDX
//         00479f6d     LEA        EAX,[ESI + 0xf8]
//         00479f73     PUSH       -0x1
//         00479f75     PUSH       EAX
//         00479f76     MOV        EAX,dword ptr [ESI + 0x330]
//         00479f7c     MOV        this,dword ptr [EAX + 0x38]
//         00479f7f     PUSH       this
//         00479f80     CALL       dword ptr [->USER32.DLL::DrawTextA]              = 0048b10a
//                              Pnl_msg.cpp:641 (23)
//         00479f86     MOV        EDX,dword ptr [ESP + 0x1c]
//         00479f8a     MOV        EAX,dword ptr [ESP + 0x20]
//         00479f8e     PUSH       EBX
//         00479f8f     PUSH       EBP
//         00479f90     PUSH       EDX
//         00479f91     LEA        this,[ESP + 0x4c]
//         00479f95     PUSH       EAX
//         00479f96     PUSH       this
//         00479f97     CALL       dword ptr [->USER32.DLL::SetRect]                = 0048b002
//                              Pnl_msg.cpp:642 (31)
//         00479f9d     LEA        EDX,[ESP + 0x40]
//         00479fa1     PUSH       EDI
//         00479fa2     PUSH       EDX
//         00479fa3     LEA        EAX,[ESI + 0xf8]
//         00479fa9     PUSH       -0x1
//         00479fab     PUSH       EAX
//         00479fac     MOV        EAX,dword ptr [ESI + 0x330]
//         00479fb2     MOV        this,dword ptr [EAX + 0x38]
//         00479fb5     PUSH       this
//         00479fb6     CALL       dword ptr [->USER32.DLL::DrawTextA]              = 0048b10a
//                              Pnl_msg.cpp:645 (21)
//         00479fbc     MOV        EAX,dword ptr [ESI + 0x330]
//         00479fc2     MOV        EDX,dword ptr [ESP + 0x28]
//         00479fc6     PUSH       EDX
//         00479fc7     MOV        this,dword ptr [EAX + 0x38]
//         00479fca     PUSH       this
//         00479fcb     CALL       dword ptr [->GDI32.DLL::SetTextColor]            = 0048b318
//                              Pnl_msg.cpp:647 (25)
//         00479fd1     MOV        EDX,dword ptr [ESP + 0x18]
//         00479fd5     MOV        EAX,dword ptr [ESP + 0x10]
//         00479fd9     DEC        EBX
//         00479fda     DEC        EBP
//         00479fdb     PUSH       EBX
//         00479fdc     PUSH       EBP
//         00479fdd     PUSH       EDX
//         00479fde     LEA        this,[ESP + 0x4c]
//         00479fe2     PUSH       EAX
//         00479fe3     PUSH       this
//         00479fe4     CALL       dword ptr [->USER32.DLL::SetRect]                = 0048b002
//                              Pnl_msg.cpp:648 (31)
//         00479fea     LEA        EDX,[ESP + 0x40]
//         00479fee     PUSH       EDI
//         00479fef     PUSH       EDX
//         00479ff0     LEA        EAX,[ESI + 0xf8]
//         00479ff6     PUSH       -0x1
//         00479ff8     PUSH       EAX
//         00479ff9     MOV        EAX,dword ptr [ESI + 0x330]
//         00479fff     MOV        this,dword ptr [EAX + 0x38]
//         0047a002     PUSH       this
//         0047a003     CALL       dword ptr [->USER32.DLL::DrawTextA]              = 0048b10a
//                              Pnl_msg.cpp:653 (10)
//         0047a009     MOV        this,dword ptr [ESI + 0x370]
//         0047a00f     TEST       this,this
//         0047a011     JZ         LAB_0047a06a
//                              Pnl_msg.cpp:656 (9)
//         0047a013     MOV        EDX,dword ptr [ESI + 0x378]
//         0047a019     MOV        EAX,dword ptr [ECX + this->_padding_]
//                              Pnl_msg.cpp:661 (57)
//         0047a01c     MOV        EBX,dword ptr [ESI + 0x348]
//         0047a022     MOV        EDI,EDX
//         0047a024     SHL        EDI,0x5
//         0047a027     ADD        EAX,EDI
//         0047a029     PUSH       0x0
//         0047a02b     PUSH       0x0
//         0047a02d     PUSH       EDX
//         0047a02e     MOV        EDX,dword ptr [EAX + 0x1c]
//         0047a031     MOV        EDI,dword ptr [EAX + 0x10]
//         0047a034     MOV        EAX,dword ptr [EAX + 0x18]
//         0047a037     LEA        EDX,[EDX + EBX*0x1 + 0x6]
//         0047a03b     SUB        EAX,EDI
//         0047a03d     PUSH       EDX
//         0047a03e     MOV        EDX,dword ptr [ESI + 0x344]
//         0047a044     LEA        EAX,[EAX + EDX*0x1 + -0x4]
//         0047a048     MOV        EDX,dword ptr [ESI + 0x330]
//         0047a04e     PUSH       EAX
//         0047a04f     PUSH       EDX
//         0047a050     CALL       TShape::shape_draw                               uchar shape_draw(TShape * this, TDrawArea * p
//                              Pnl_msg.cpp:663 (21)
//         0047a055     MOV        this,dword ptr [ESI + 0x344]
//         0047a05b     MOV        EAX,0xfffffffc
//         0047a060     SUB        EAX,EDI
//         0047a062     ADD        this,EAX
//         0047a064     MOV        dword ptr [ESI + 0x344],this
//                               LAB_0047a06a                                                 XREF[1]:     0047a011(j)
//                              Pnl_msg.cpp:666 (10)
//         0047a06a     MOV        this,dword ptr [ESI + 0x374]
//         0047a070     TEST       this,this
//         0047a072     JZ         LAB_0047a0cb
//                              Pnl_msg.cpp:669 (9)
//         0047a074     MOV        EDX,dword ptr [ESI + 0x37c]
//         0047a07a     MOV        EDI,dword ptr [ECX + this->_padding_]
//                              Pnl_msg.cpp:674 (57)
//         0047a07d     MOV        EBX,dword ptr [ESI + 0x348]
//         0047a083     MOV        EAX,EDX
//         0047a085     SHL        EAX,0x5
//         0047a088     ADD        EAX,EDI
//         0047a08a     PUSH       0x0
//         0047a08c     PUSH       0x0
//         0047a08e     PUSH       EDX
//         0047a08f     MOV        EDX,dword ptr [EAX + 0x1c]
//         0047a092     MOV        EDI,dword ptr [EAX + 0x10]
//         0047a095     MOV        EAX,dword ptr [EAX + 0x18]
//         0047a098     LEA        EDX,[EDX + EBX*0x1 + 0x6]
//         0047a09c     SUB        EAX,EDI
//         0047a09e     PUSH       EDX
//         0047a09f     MOV        EDX,dword ptr [ESI + 0x344]
//         0047a0a5     LEA        EAX,[EAX + EDX*0x1 + -0x4]
//         0047a0a9     MOV        EDX,dword ptr [ESI + 0x330]
//         0047a0af     PUSH       EAX
//         0047a0b0     PUSH       EDX
//         0047a0b1     CALL       TShape::shape_draw                               uchar shape_draw(TShape * this, TDrawArea * p
//                              Pnl_msg.cpp:676 (21)
//         0047a0b6     MOV        this,dword ptr [ESI + 0x344]
//         0047a0bc     MOV        EAX,0xfffffffc
//         0047a0c1     SUB        EAX,EDI
//         0047a0c3     ADD        this,EAX
//         0047a0c5     MOV        dword ptr [ESI + 0x344],this
//                               LAB_0047a0cb                                                 XREF[1]:     0047a072(j)
//                              Pnl_msg.cpp:680 (10)
//         0047a0cb     MOV        dword ptr [ESI + 0x36c],0x1
//                              Symbol Ref: No symbol: rib_exit
//                               LAB_0047a0d5                                                 XREF[1]:     00479d47(j)
//                              Pnl_msg.cpp:683 (21)
//         0047a0d5     MOV        EDX,dword ptr [ESI + 0x330]
//         0047a0db     MOV        this,dword ptr [ESP + 0x2c]
//         0047a0df     PUSH       this
//         0047a0e0     MOV        EAX,dword ptr [EDX + 0x38]
//         0047a0e3     PUSH       EAX
//         0047a0e4     CALL       dword ptr [->GDI32.DLL::SelectObject]            = 0048b192
//                              Pnl_msg.cpp:684 (18)
//         0047a0ea     MOV        this,dword ptr [ESI + 0x330]
//         0047a0f0     PUSH       0x0
//         0047a0f2     MOV        EDX,dword ptr [ECX + this->_padding_]
//         0047a0f5     PUSH       EDX
//         0047a0f6     CALL       dword ptr [->GDI32.DLL::SelectClipRgn]           = 0048b2fc
//                              Pnl_msg.cpp:685 (16)
//         0047a0fc     MOV        this,dword ptr [ESI + 0x330]
//         0047a102     PUSH       s_pnl_msg::render_to_image_buffer                = "pnl_msg::render_to_image_buffer"
//         0047a107     CALL       TDrawArea::ReleaseDc                             void ReleaseDc(TDrawArea * this, char * param
//                              Pnl_msg.cpp:688 (12)
//         0047a10c     MOV        EAX,dword ptr [ESI + 0x8c]
//         0047a112     MOV        this,dword ptr [ESI + 0x344]
//                              Pnl_msg.cpp:689 (22)
//         0047a118     MOV        EDX,dword ptr [ESI + 0x348]
//         0047a11e     ADD        this,EAX
//         0047a120     MOV        dword ptr [ESI + 0x354],this
//         0047a126     MOV        this,dword ptr [ESI + 0x90]
//         0047a12c     ADD        EDX,this
//                              Pnl_msg.cpp:694 (48)
//         0047a12e     POP        EDI
//         0047a12f     MOV        dword ptr [ESI + 0x358],EDX
//         0047a135     MOV        EDX,dword ptr [ESI + 0x34c]
//         0047a13b     ADD        EDX,EAX
//         0047a13d     MOV        EAX,dword ptr [ESI + 0x350]
//         0047a143     ADD        EAX,this
//         0047a145     MOV        dword ptr [ESI + 0x35c],EDX
//         0047a14b     MOV        dword ptr [ESI + 0x360],EAX
//         0047a151     MOV        EAX,dword ptr [ESI + 0x36c]
//         0047a157     POP        ESI
//         0047a158     POP        EBP
//         0047a159     POP        EBX
//         0047a15a     ADD        ESP,0x40
//         0047a15d     RET
//         0047a15e     ??         90h
//         0047a15f     NOP
    return 0;
}

void TMessagePanel::set_font(void* param_1, long param_2, long param_3) {
    /* TODO: Stub */
//                              void __thiscall set_font(TMessagePanel * this, void * param_1, long
//              void              <VOID>         <RETURN>
//              TMessagePanel *   ECX:4 (auto)   this
//              void *            Stack[0x4]:4   param_1                   XREF[1]:     0047a190(R)
//              long              Stack[0x8]:4   param_2                   XREF[1]:     0047a1a8(R)
//              long              Stack[0xc]:4   param_3                   XREF[1]:     0047a19e(R)
//                               ?set_font@TMessagePanel@@UAEXPAXJJ@Z                         XREF[1]:     00571748(*)
//                               TMessagePanel::set_font
//                              Pnl_msg.cpp:700 (14)
//         0047a190     MOV        EAX,dword ptr [ESP + param_1]
//         0047a194     MOV        EDX,dword ptr [ECX + this->font]
//         0047a19a     CMP        EDX,EAX
//         0047a19c     JZ         LAB_0047a1c6
//                              Pnl_msg.cpp:705 (14)
//         0047a19e     MOV        EDX,dword ptr [ESP + param_3]
//         0047a1a2     MOV        dword ptr [ECX + this->font],EAX
//         0047a1a8     MOV        EAX,dword ptr [ESP + param_2]
//                              Pnl_msg.cpp:707 (26)
//         0047a1ac     PUSH       0x1
//         0047a1ae     MOV        dword ptr [ECX + this->font_wid],EAX
//         0047a1b4     MOV        EAX,dword ptr [this->_padding_]
//         0047a1b6     MOV        dword ptr [ECX + this->font_hgt],EDX
//         0047a1bc     MOV        byte ptr [ECX + this+0xf3],0x1
//         0047a1c3     CALL       dword ptr [EAX + 0x20]
//                               LAB_0047a1c6                                                 XREF[1]:     0047a19c(j)
//                              Pnl_msg.cpp:709 (3)
//         0047a1c6     RET        0xc
//         0047a1c9     ??         90h
//         0047a1ca     NOP
//         0047a1cb     NOP
//         0047a1cc     NOP
//         0047a1cd     NOP
//         0047a1ce     NOP
//         0047a1cf     NOP
    return;
}

