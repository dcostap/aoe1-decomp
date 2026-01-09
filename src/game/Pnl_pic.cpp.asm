#include "common.h"
#include "Pnl_pic.h"

TPicturePanel::TPicturePanel() {
    /* TODO: Stub */
    //                              undefined __thiscall TPicturePanel(TPicturePanel * this)
    //              undefined         <UNASSIGNED>   <RETURN>
    //              TPicturePanel *   ECX:4 (auto)   this
    //                               ??0TPicturePanel@@QAE@XZ                                     XREF[4]:     TribeAboutDialog:0043af76(c), 
    //                               TPicturePanel::TPicturePanel                                              TribeEndScreen:0049379a(c), 
    //                                                                                                         TRIBE_Screen_Main_Menu:0049e8da(c)
    //                                                                                                         TribeSelectTribeScreen:004b767c(c)
    //                              Pnl_pic.cpp:30 (50)
    //         0047a1d0     PUSH       ESI
    //         0047a1d1     MOV        ESI,this
    //         0047a1d3     CALL       TPanel::TPanel                                   undefined TPanel(TPanel * this)
    //         0047a1d8     XOR        EAX,EAX
    //         0047a1da     MOV        dword ptr [ESI + 0x108],0x1
    //         0047a1e4     MOV        dword ptr [ESI + 0x104],EAX
    //         0047a1ea     MOV        dword ptr [ESI + 0x10c],EAX
    //         0047a1f0     MOV        dword ptr [ESI + 0x110],EAX
    //         0047a1f6     MOV        dword ptr [ESI + 0x114],EAX
    //         0047a1fc     MOV        dword ptr [ESI + 0x118],EAX
    //                              Pnl_pic.cpp:32 (6)
    //         0047a202     MOV        dword ptr [ESI + 0x80],EAX
    //                              Pnl_pic.cpp:33 (19)
    //         0047a208     MOV        byte ptr [ESI + 0xf4],AL
    //         0047a20e     MOV        dword ptr [ESI],TPicturePanel::`vftable'         = 0047a230
    //         0047a214     MOV        byte ptr [ESI + 0xee],0x2
    //                              Pnl_pic.cpp:34 (10)
    //         0047a21b     MOV        dword ptr [ESI + 0x100],0xffffffff
    //                              Pnl_pic.cpp:35 (4)
    //         0047a225     MOV        EAX,ESI
    //         0047a227     POP        ESI
    //         0047a228     RET
    //         0047a229     ??         90h
    //         0047a22a     NOP
    //         0047a22b     NOP
    //         0047a22c     NOP
    //         0047a22d     NOP
    //         0047a22e     NOP
    //         0047a22f     NOP
}

TPicturePanel::~TPicturePanel() {
    /* TODO: Stub */
    //                              void __thiscall ~TPicturePanel(TPicturePanel * this)
    //              void              <VOID>         <RETURN>
    //              TPicturePanel *   ECX:4 (auto)   this
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     0047a273(W), 0047a282(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     0047a28f(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     0047a269(W)  
    //                               ??1TPicturePanel@@UAE@XZ                                     XREF[1]:     `scalar_deleting_destructor':0047a
    //                               TPicturePanel::~TPicturePanel
    //                              Pnl_pic.cpp:41 (43)
    //         0047a250     PUSH       -0x1
    //         0047a252     PUSH       FUN_0055e528
    //         0047a257     MOV        EAX,FS:[0x0]
    //         0047a25d     PUSH       EAX
    //         0047a25e     MOV        dword ptr FS:[0x0],ESP
    //         0047a265     PUSH       this
    //         0047a266     PUSH       ESI
    //         0047a267     MOV        ESI,this
    //         0047a269     MOV        dword ptr [ESP + local_10],ESI
    //         0047a26d     MOV        dword ptr [ESI],TPicturePanel::`vftable'         = 0047a230
    //         0047a273     MOV        dword ptr [ESP + local_4],0x0
    //                              Pnl_pic.cpp:42 (7)
    //         0047a27b     CALL       TPicturePanel::free_pic                          void free_pic(TPicturePanel * this)
    //         0047a280     MOV        this,ESI
    //                              Pnl_pic.cpp:43 (29)
    //         0047a282     MOV        dword ptr [ESP + local_4],0xffffffff
    //         0047a28a     CALL       TPanel::~TPanel                                  void ~TPanel(TPanel * this)
    //         0047a28f     MOV        this,dword ptr [ESP + local_c]
    //         0047a293     POP        ESI
    //         0047a294     MOV        dword ptr FS:[0x0],this
    //         0047a29b     ADD        ESP,0x10
    //         0047a29e     RET
    //         0047a29f     ??         90h
    //                              * public: long __thiscall TPicturePanel::setup(class TDrawArea *,class TPanel *,long,long,long,long,... *
    //                              long __thiscall setup(TPicturePanel * this, TDrawArea * param_1, TPa
    //              long              EAX:4          <RETURN>
    //              TPicturePanel *   ECX:4 (auto)   this
    //              TDrawArea *       Stack[0x4]:4   param_1                   XREF[1]:     0047a383(R)  
    //              TPanel *          Stack[0x8]:4   param_2                   XREF[1]:     0047a37a(R)  
    //              long              Stack[0xc]:4   param_3                   XREF[1]:     0047a376(R)  
    //              long              Stack[0x10]:4  param_4                   XREF[1]:     0047a372(R)  
    //              long              Stack[0x14]:4  param_5                   XREF[2]:     0047a353(R), 0047a36e(R)  
    //              long              Stack[0x18]:4  param_6                   XREF[2]:     0047a34f(R), 0047a36a(R)  
    //              char *            Stack[0x1c]:4  param_7                   XREF[3]:     0047a2a3(R), 0047a336(*), 0047a343(R)  
    //              long              Stack[0x20]:4  param_8                   XREF[3]:     0047a2d9(R), 0047a332(*), 0047a348(R)  
    //              int               Stack[0x24]:4  param_9                   XREF[1]:     0047a2dd(R)  
    //              int               Stack[0x28]:4  param_10                  XREF[1]:     0047a2e7(R)  
    //                               ?setup@TPicturePanel@@QAEJPAVTDrawArea@@PAVTPanel@@JJJJPADJ  XREF[4]:     TribeAboutDialog:0043afbd(c), 
    //                               TPicturePanel::setup                                                      TribeEndScreen:004937d6(c), 
    //                                                                                                         TRIBE_Screen_Main_Menu:0049e925(c)
    //                                                                                                         TribeSelectTribeScreen:004b76c8(c)
    //                              Pnl_pic.cpp:50 (3)
    //         0047a2a0     PUSH       EBX
    //         0047a2a1     PUSH       ESI
    //         0047a2a2     PUSH       EDI
    //                              Pnl_pic.cpp:53 (10)
    //         0047a2a3     MOV        EDI,dword ptr [ESP + param_7]
    //         0047a2a7     TEST       EDI,EDI
    //         0047a2a9     MOV        EBX,this
    //         0047a2ab     JZ         LAB_0047a2d2
    //                              Pnl_pic.cpp:54 (35)
    //         0047a2ad     OR         this,0xffffffff
    //         0047a2b0     XOR        EAX,EAX
    //         0047a2b2     SCASB.RE   ES:EDI
    //         0047a2b4     NOT        this
    //         0047a2b6     SUB        EDI,this
    //         0047a2b8     LEA        EDX,[EBX + 0xf4]
    //         0047a2be     MOV        EAX,this
    //         0047a2c0     MOV        ESI,EDI
    //         0047a2c2     MOV        EDI,EDX
    //         0047a2c4     SHR        this,0x2
    //         0047a2c7     MOVSD.REP  ES:EDI,ESI
    //         0047a2c9     MOV        this,EAX
    //         0047a2cb     AND        this,0x3
    //         0047a2ce     MOVSB.REP  ES:EDI,ESI
    //                              Pnl_pic.cpp:55 (2)
    //         0047a2d0     JMP        LAB_0047a2d9
    //                               LAB_0047a2d2                                                 XREF[1]:     0047a2ab(j)  
    //                              Pnl_pic.cpp:56 (7)
    //         0047a2d2     MOV        byte ptr [EBX + 0xf4],0x0
    //                               LAB_0047a2d9                                                 XREF[1]:     0047a2d0(j)  
    //                              Pnl_pic.cpp:57 (4)
    //         0047a2d9     MOV        this,dword ptr [ESP + param_8]
    //                              Pnl_pic.cpp:58 (10)
    //         0047a2dd     MOV        EAX,dword ptr [ESP + param_9]
    //         0047a2e1     MOV        dword ptr [EBX + 0x100],this
    //                              Pnl_pic.cpp:59 (4)
    //         0047a2e7     MOV        this,dword ptr [ESP + param_10]
    //                              Pnl_pic.cpp:61 (20)
    //         0047a2eb     TEST       EAX,EAX
    //         0047a2ed     MOV        dword ptr [EBX + 0x104],EAX
    //         0047a2f3     MOV        dword ptr [EBX + 0x108],this
    //         0047a2f9     JNZ        LAB_0047a2ff
    //         0047a2fb     TEST       this,this
    //         0047a2fd     JZ         LAB_0047a36a
    //                               LAB_0047a2ff                                                 XREF[1]:     0047a2f9(j)  
    //                              Pnl_pic.cpp:63 (11)
    //         0047a2ff     MOV        this,EBX
    //         0047a301     CALL       TPicturePanel::load_pic                          int load_pic(TPicturePanel * this)
    //         0047a306     TEST       EAX,EAX
    //         0047a308     JZ         LAB_0047a36a
    //                              Pnl_pic.cpp:65 (10)
    //         0047a30a     MOV        EAX,dword ptr [EBX + 0x104]
    //         0047a310     TEST       EAX,EAX
    //         0047a312     JZ         LAB_0047a34f
    //                              Pnl_pic.cpp:67 (10)
    //         0047a314     MOV        EAX,dword ptr [EBX + 0x110]
    //         0047a31a     TEST       EAX,EAX
    //         0047a31c     JNZ        LAB_0047a32c
    //                              Pnl_pic.cpp:69 (9)
    //         0047a31e     MOV        EAX,dword ptr [EBX + 0x114]
    //         0047a324     MOV        EDI,dword ptr [EAX + 0x14]
    //                              Pnl_pic.cpp:70 (3)
    //         0047a327     MOV        ESI,dword ptr [EAX + 0x18]
    //                              Pnl_pic.cpp:72 (2)
    //         0047a32a     JMP        LAB_0047a357
    //                               LAB_0047a32c                                                 XREF[1]:     0047a31c(j)  
    //                              Pnl_pic.cpp:74 (23)
    //         0047a32c     MOV        this,dword ptr [EBX + 0x118]
    //         0047a332     LEA        EDX=>param_8,[ESP + 0x2c]
    //         0047a336     LEA        EAX=>param_7,[ESP + 0x28]
    //         0047a33a     PUSH       EDX
    //         0047a33b     PUSH       EAX
    //         0047a33c     PUSH       0x0
    //         0047a33e     CALL       TShape::shape_bounds                             uchar shape_bounds(TShape * this, long param_
    //                              Pnl_pic.cpp:75 (5)
    //         0047a343     MOVSX      EDI,word ptr [ESP + param_7]
    //                              Pnl_pic.cpp:76 (15)
    //         0047a348     MOVSX      ESI,word ptr [ESP + param_8]
    //         0047a34d     JMP        LAB_0047a357
    //                               LAB_0047a34f                                                 XREF[1]:     0047a312(j)  
    //         0047a34f     MOV        ESI,dword ptr [ESP + param_6]
    //         0047a353     MOV        EDI,dword ptr [ESP + param_5]
    //                               LAB_0047a357                                                 XREF[2]:     0047a32a(j), 0047a34d(j)  
    //                              Pnl_pic.cpp:79 (10)
    //         0047a357     MOV        EAX,dword ptr [EBX + 0x108]
    //         0047a35d     TEST       EAX,EAX
    //         0047a35f     JNZ        LAB_0047a372
    //                              Pnl_pic.cpp:80 (17)
    //         0047a361     MOV        this,EBX
    //         0047a363     CALL       TPicturePanel::free_pic                          void free_pic(TPicturePanel * this)
    //         0047a368     JMP        LAB_0047a372
    //                               LAB_0047a36a                                                 XREF[2]:     0047a2fd(j), 0047a308(j)  
    //         0047a36a     MOV        ESI,dword ptr [ESP + param_6]
    //         0047a36e     MOV        EDI,dword ptr [ESP + param_5]
    //                               LAB_0047a372                                                 XREF[2]:     0047a35f(j), 0047a368(j)  
    //                              Pnl_pic.cpp:84 (31)
    //         0047a372     MOV        this,dword ptr [ESP + param_4]
    //         0047a376     MOV        EDX,dword ptr [ESP + param_3]
    //         0047a37a     MOV        EAX,dword ptr [ESP + param_2]
    //         0047a37e     PUSH       0x0
    //         0047a380     PUSH       ESI
    //         0047a381     PUSH       EDI
    //         0047a382     PUSH       this
    //         0047a383     MOV        this,dword ptr [ESP + param_1]
    //         0047a387     PUSH       EDX
    //         0047a388     PUSH       EAX
    //         0047a389     PUSH       this
    //         0047a38a     MOV        this,EBX
    //         0047a38c     CALL       TPanel::setup                                    long setup(TPanel * this, TDrawArea * param_1
    //                              Pnl_pic.cpp:87 (11)
    //         0047a391     POP        EDI
    //         0047a392     POP        ESI
    //         0047a393     MOV        EAX,0x1
    //         0047a398     POP        EBX
    //         0047a399     RET        0x28
    //         0047a39c     ??         90h
    //         0047a39d     NOP
    //         0047a39e     NOP
    //         0047a39f     NOP
}

void TPicturePanel::set_picture(TShape* param_1, long param_2) {
    /* TODO: Stub */
    //                              void __thiscall set_picture(TPicturePanel * this, TShape * param_1, 
    //              void              <VOID>         <RETURN>
    //              TPicturePanel *   ECX:4 (auto)   this
    //              TShape *          Stack[0x4]:4   param_1                   XREF[1]:     0047a3ac(R)  
    //              long              Stack[0x8]:4   param_2                   XREF[1]:     0047a3a8(R)  
    //                               ?set_picture@TPicturePanel@@QAEXPAVTShape@@J@Z
    //                               TPicturePanel::set_picture
    //                              Pnl_pic.cpp:93 (3)
    //         0047a3a0     PUSH       ESI
    //         0047a3a1     MOV        ESI,this
    //                              Pnl_pic.cpp:94 (5)
    //         0047a3a3     CALL       TPicturePanel::free_pic                          void free_pic(TPicturePanel * this)
    //                              Pnl_pic.cpp:96 (8)
    //         0047a3a8     MOV        this,dword ptr [ESP + param_2]
    //         0047a3ac     MOV        EAX,dword ptr [ESP + param_1]
    //                              Pnl_pic.cpp:98 (31)
    //         0047a3b0     MOV        EDX,dword ptr [ESI]
    //         0047a3b2     MOV        dword ptr [ESI + 0x100],this
    //         0047a3b8     PUSH       0x1
    //         0047a3ba     MOV        this,ESI
    //         0047a3bc     MOV        dword ptr [ESI + 0x118],EAX
    //         0047a3c2     MOV        dword ptr [ESI + 0x10c],0x0
    //         0047a3cc     CALL       dword ptr [EDX + 0x20]
    //                              Pnl_pic.cpp:99 (4)
    //         0047a3cf     POP        ESI
    //         0047a3d0     RET        0x8
    //         0047a3d3     ??         90h
    //         0047a3d4     NOP
    //         0047a3d5     NOP
    //         0047a3d6     NOP
    //         0047a3d7     NOP
    //         0047a3d8     NOP
    //         0047a3d9     NOP
    //         0047a3da     NOP
    //         0047a3db     NOP
    //         0047a3dc     NOP
    //         0047a3dd     NOP
    //         0047a3de     NOP
    //         0047a3df     NOP
    return;
}

int TPicturePanel::load_pic() {
    /* TODO: Stub */
    //                              int __thiscall load_pic(TPicturePanel * this)
    //              int               EAX:4          <RETURN>
    //              TPicturePanel *   ECX:4 (auto)   this
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[7]:     0047a438(W), 0047a451(W), 0047a45d(W), 0047a488(W), 
    //                                                                                     0047a4a9(W), 0047a529(W), 0047a54c(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[3]:     0047a4d3(R), 0047a571(R), 0047a59a(R)  
    //              char[80]          Stack[-0x60]   file_name                 XREF[3,4]:   0047a432(W), 0047a482(W), 0047a523(W), 0047a416(*), 
    //                                                                                     0047a444(*), 0047a507(*), 0047a536(*)  
    //                               ?load_pic@TPicturePanel@@IAEHXZ                              XREF[2]:     setup:0047a301(c), 
    //                               TPicturePanel::load_pic                                                   draw:0047a668(c)  
    //                              Pnl_pic.cpp:105 (30)
    //         0047a3e0     MOV        EAX,FS:[0x0]
    //         0047a3e6     PUSH       -0x1
    //         0047a3e8     PUSH       FUN_0055e561
    //         0047a3ed     PUSH       EAX
    //         0047a3ee     MOV        dword ptr FS:[0x0],ESP
    //         0047a3f5     SUB        ESP,0x54
    //         0047a3f8     PUSH       EBX
    //         0047a3f9     PUSH       EBP
    //         0047a3fa     PUSH       ESI
    //         0047a3fb     PUSH       EDI
    //         0047a3fc     MOV        ESI,this
    //                              Pnl_pic.cpp:108 (5)
    //         0047a3fe     CALL       TPicturePanel::free_pic                          void free_pic(TPicturePanel * this)
    //                              Pnl_pic.cpp:110 (18)
    //         0047a403     MOV        AL,byte ptr [ESI + 0xf4]
    //         0047a409     LEA        EBP,[ESI + 0xf4]
    //         0047a40f     XOR        EBX,EBX
    //         0047a411     CMP        AL,BL
    //         0047a413     JZ         LAB_0047a467
    //                              Pnl_pic.cpp:112 (19)
    //         0047a415     PUSH       EBP
    //         0047a416     LEA        EAX=>file_name[4],[ESP + 0x18]
    //         0047a41a     PUSH       s_%s.shp                                         = "%s.shp"
    //         0047a41f     PUSH       EAX
    //         0047a420     CALL       sprintf                                          undefined sprintf()
    //         0047a425     ADD        ESP,0xc
    //                              Pnl_pic.cpp:113 (49)
    //         0047a428     PUSH       0x20
    //         0047a42a     CALL       operator_new                                     void * operator_new(uint param_1)
    //         0047a42f     ADD        ESP,0x4
    //         0047a432     MOV        dword ptr [ESP + file_name[0]],EAX
    //         0047a436     CMP        EAX,EBX
    //         0047a438     MOV        dword ptr [ESP + local_4],EBX
    //         0047a43c     JZ         LAB_0047a45b
    //         0047a43e     MOV        this,dword ptr [ESI + 0x100]
    //         0047a444     LEA        EDX=>file_name[4],[ESP + 0x14]
    //         0047a448     PUSH       this
    //         0047a449     PUSH       EDX
    //         0047a44a     MOV        this,EAX
    //         0047a44c     CALL       TShape::TShape                                   undefined TShape(TShape * this, char * param_
    //         0047a451     MOV        dword ptr [ESP + local_4],0xffffffff
    //                              Pnl_pic.cpp:115 (2)
    //         0047a459     JMP        LAB_0047a4ad
    //                               LAB_0047a45b                                                 XREF[1]:     0047a43c(j)  
    //                              Pnl_pic.cpp:113 (10)
    //         0047a45b     XOR        EAX,EAX
    //         0047a45d     MOV        dword ptr [ESP + local_4],0xffffffff
    //                              Pnl_pic.cpp:115 (19)
    //         0047a465     JMP        LAB_0047a4ad
    //                               LAB_0047a467                                                 XREF[1]:     0047a413(j)  
    //         0047a467     MOV        EAX,dword ptr [ESI + 0x100]
    //         0047a46d     OR         EDI,0xffffffff
    //         0047a470     CMP        EAX,EDI
    //         0047a472     JZ         LAB_0047a59a
    //                              Pnl_pic.cpp:116 (53)
    //         0047a478     PUSH       0x20
    //         0047a47a     CALL       operator_new                                     void * operator_new(uint param_1)
    //         0047a47f     ADD        ESP,0x4
    //         0047a482     MOV        dword ptr [ESP + file_name[0]],EAX
    //         0047a486     CMP        EAX,EBX
    //         0047a488     MOV        dword ptr [ESP + local_4],0x1
    //         0047a490     JZ         LAB_0047a4a7
    //         0047a492     MOV        this,dword ptr [ESI + 0x100]
    //         0047a498     PUSH       this
    //         0047a499     PUSH       s_                                               = ""
    //         0047a49e     MOV        this,EAX
    //         0047a4a0     CALL       TShape::TShape                                   undefined TShape(TShape * this, char * param_
    //         0047a4a5     JMP        LAB_0047a4a9
    //                               LAB_0047a4a7                                                 XREF[1]:     0047a490(j)  
    //         0047a4a7     XOR        EAX,EAX
    //                               LAB_0047a4a9                                                 XREF[1]:     0047a4a5(j)  
    //         0047a4a9     MOV        dword ptr [ESP + local_4],EDI
    //                               LAB_0047a4ad                                                 XREF[2]:     0047a459(j), 0047a465(j)  
    //                              Pnl_pic.cpp:120 (12)
    //         0047a4ad     MOV        this,EAX
    //         0047a4af     MOV        dword ptr [ESI + 0x118],EAX
    //         0047a4b5     CMP        this,EBX
    //         0047a4b7     JZ         LAB_0047a506
    //                              Pnl_pic.cpp:122 (9)
    //         0047a4b9     CALL       TShape::is_loaded                                int is_loaded(TShape * this)
    //         0047a4be     TEST       EAX,EAX
    //         0047a4c0     JZ         LAB_0047a4e6
    //                              Pnl_pic.cpp:124 (11)
    //         0047a4c2     MOV        EAX,0x1
    //         0047a4c7     MOV        dword ptr [ESI + 0x110],EAX
    //                              Pnl_pic.cpp:125 (6)
    //         0047a4cd     MOV        dword ptr [ESI + 0x10c],EAX
    //                              Pnl_pic.cpp:147 (19)
    //         0047a4d3     MOV        this,dword ptr [ESP + local_c]
    //         0047a4d7     MOV        dword ptr FS:[0x0],this
    //         0047a4de     POP        EDI
    //         0047a4df     POP        ESI
    //         0047a4e0     POP        EBP
    //         0047a4e1     POP        EBX
    //         0047a4e2     ADD        ESP,0x60
    //         0047a4e5     RET
    //                               LAB_0047a4e6                                                 XREF[1]:     0047a4c0(j)  
    //                              Pnl_pic.cpp:128 (26)
    //         0047a4e6     MOV        EDI,dword ptr [ESI + 0x118]
    //         0047a4ec     CMP        EDI,EBX
    //         0047a4ee     JZ         LAB_0047a500
    //         0047a4f0     MOV        this,EDI
    //         0047a4f2     CALL       TShape::~TShape                                  void ~TShape(TShape * this)
    //         0047a4f7     PUSH       EDI
    //         0047a4f8     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         0047a4fd     ADD        ESP,0x4
    //                               LAB_0047a500                                                 XREF[1]:     0047a4ee(j)  
    //                              Pnl_pic.cpp:129 (6)
    //         0047a500     MOV        dword ptr [ESI + 0x118],EBX
    //                               LAB_0047a506                                                 XREF[1]:     0047a4b7(j)  
    //                              Pnl_pic.cpp:132 (19)
    //         0047a506     PUSH       EBP
    //         0047a507     LEA        EDX=>file_name[4],[ESP + 0x18]
    //         0047a50b     PUSH       s_%s.bmp                                         = "%s.bmp"
    //         0047a510     PUSH       EDX
    //         0047a511     CALL       sprintf                                          undefined sprintf()
    //         0047a516     ADD        ESP,0xc
    //                              Pnl_pic.cpp:133 (49)
    //         0047a519     PUSH       0x20
    //         0047a51b     CALL       operator_new                                     void * operator_new(uint param_1)
    //         0047a520     ADD        ESP,0x4
    //         0047a523     MOV        dword ptr [ESP + file_name[0]],EAX
    //         0047a527     CMP        EAX,EBX
    //         0047a529     MOV        dword ptr [ESP + local_4],0x2
    //         0047a531     JZ         LAB_0047a548
    //         0047a533     PUSH       EBX
    //         0047a534     PUSH       EBX
    //         0047a535     PUSH       EBX
    //         0047a536     LEA        this=>file_name[4],[ESP + 0x20]
    //         0047a53a     PUSH       -0x1
    //         0047a53c     PUSH       this
    //         0047a53d     MOV        this,EAX
    //         0047a53f     CALL       TPicture::TPicture                               undefined TPicture(TPicture * this, char * pa
    //         0047a544     MOV        EDI,EAX
    //         0047a546     JMP        LAB_0047a54a
    //                               LAB_0047a548                                                 XREF[1]:     0047a531(j)  
    //         0047a548     XOR        EDI,EDI
    //                               LAB_0047a54a                                                 XREF[1]:     0047a546(j)  
    //                              Pnl_pic.cpp:134 (18)
    //         0047a54a     CMP        EDI,EBX
    //         0047a54c     MOV        dword ptr [ESP + local_4],0xffffffff
    //         0047a554     MOV        dword ptr [ESI + 0x114],EDI
    //         0047a55a     JZ         LAB_0047a59a
    //                              Pnl_pic.cpp:136 (4)
    //         0047a55c     CMP        dword ptr [EDI],EBX
    //         0047a55e     JZ         LAB_0047a584
    //                              Pnl_pic.cpp:139 (17)
    //         0047a560     MOV        EAX,0x1
    //         0047a565     MOV        dword ptr [ESI + 0x110],EBX
    //         0047a56b     MOV        dword ptr [ESI + 0x10c],EAX
    //                              Pnl_pic.cpp:147 (19)
    //         0047a571     MOV        this,dword ptr [ESP + local_c]
    //         0047a575     MOV        dword ptr FS:[0x0],this
    //         0047a57c     POP        EDI
    //         0047a57d     POP        ESI
    //         0047a57e     POP        EBP
    //         0047a57f     POP        EBX
    //         0047a580     ADD        ESP,0x60
    //         0047a583     RET
    //                               LAB_0047a584                                                 XREF[1]:     0047a55e(j)  
    //                              Pnl_pic.cpp:142 (16)
    //         0047a584     MOV        this,EDI
    //         0047a586     CALL       TPicture::~TPicture                              void ~TPicture(TPicture * this)
    //         0047a58b     PUSH       EDI
    //         0047a58c     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         0047a591     ADD        ESP,0x4
    //                              Pnl_pic.cpp:143 (6)
    //         0047a594     MOV        dword ptr [ESI + 0x114],EBX
    //                               LAB_0047a59a                                                 XREF[2]:     0047a472(j), 0047a55a(j)  
    //                              Pnl_pic.cpp:147 (21)
    //         0047a59a     MOV        this,dword ptr [ESP + local_c]
    //         0047a59e     POP        EDI
    //         0047a59f     POP        ESI
    //         0047a5a0     POP        EBP
    //         0047a5a1     XOR        EAX,EAX
    //         0047a5a3     MOV        dword ptr FS:[0x0],this
    //         0047a5aa     POP        EBX
    //         0047a5ab     ADD        ESP,0x60
    //         0047a5ae     RET
    //         0047a5af     ??         90h
    return 0;
}

void TPicturePanel::free_pic() {
    /* TODO: Stub */
    //                              void __thiscall free_pic(TPicturePanel * this)
    //              void              <VOID>         <RETURN>
    //              TPicturePanel *   ECX:4 (auto)   this
    //                               ?free_pic@TPicturePanel@@IAEXXZ                              XREF[5]:     ~TPicturePanel:0047a27b(c), 
    //                               TPicturePanel::free_pic                                                   setup:0047a363(c), 
    //                                                                                                         set_picture:0047a3a3(c), 
    //                                                                                                         load_pic:0047a3fe(c), 
    //                                                                                                         draw:0047a6e5(c)  
    //                              Pnl_pic.cpp:153 (4)
    //         0047a5b0     PUSH       ESI
    //         0047a5b1     MOV        ESI,this
    //         0047a5b3     PUSH       EDI
    //                              Pnl_pic.cpp:154 (10)
    //         0047a5b4     MOV        EDI,dword ptr [ESI + 0x114]
    //         0047a5ba     TEST       EDI,EDI
    //         0047a5bc     JZ         LAB_0047a5e6
    //                              Pnl_pic.cpp:156 (10)
    //         0047a5be     MOV        EAX,dword ptr [ESI + 0x10c]
    //         0047a5c4     TEST       EAX,EAX
    //         0047a5c6     JZ         LAB_0047a5dc
    //                              Pnl_pic.cpp:157 (20)
    //         0047a5c8     TEST       EDI,EDI
    //         0047a5ca     JZ         LAB_0047a5dc
    //         0047a5cc     MOV        this,EDI
    //         0047a5ce     CALL       TPicture::~TPicture                              void ~TPicture(TPicture * this)
    //         0047a5d3     PUSH       EDI
    //         0047a5d4     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         0047a5d9     ADD        ESP,0x4
    //                               LAB_0047a5dc                                                 XREF[2]:     0047a5c6(j), 0047a5ca(j)  
    //                              Pnl_pic.cpp:158 (10)
    //         0047a5dc     MOV        dword ptr [ESI + 0x114],0x0
    //                               LAB_0047a5e6                                                 XREF[1]:     0047a5bc(j)  
    //                              Pnl_pic.cpp:161 (10)
    //         0047a5e6     MOV        EDI,dword ptr [ESI + 0x118]
    //         0047a5ec     TEST       EDI,EDI
    //         0047a5ee     JZ         LAB_0047a618
    //                              Pnl_pic.cpp:163 (10)
    //         0047a5f0     MOV        EAX,dword ptr [ESI + 0x10c]
    //         0047a5f6     TEST       EAX,EAX
    //         0047a5f8     JZ         LAB_0047a60e
    //                              Pnl_pic.cpp:164 (20)
    //         0047a5fa     TEST       EDI,EDI
    //         0047a5fc     JZ         LAB_0047a60e
    //         0047a5fe     MOV        this,EDI
    //         0047a600     CALL       TShape::~TShape                                  void ~TShape(TShape * this)
    //         0047a605     PUSH       EDI
    //         0047a606     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         0047a60b     ADD        ESP,0x4
    //                               LAB_0047a60e                                                 XREF[2]:     0047a5f8(j), 0047a5fc(j)  
    //                              Pnl_pic.cpp:165 (10)
    //         0047a60e     MOV        dword ptr [ESI + 0x118],0x0
    //                               LAB_0047a618                                                 XREF[1]:     0047a5ee(j)  
    //                              Pnl_pic.cpp:168 (10)
    //         0047a618     MOV        dword ptr [ESI + 0x10c],0x0
    //                              Pnl_pic.cpp:169 (3)
    //         0047a622     POP        EDI
    //         0047a623     POP        ESI
    //         0047a624     RET
    //         0047a625     ??         90h
    //         0047a626     NOP
    //         0047a627     NOP
    //         0047a628     NOP
    //         0047a629     NOP
    //         0047a62a     NOP
    //         0047a62b     NOP
    //         0047a62c     NOP
    //         0047a62d     NOP
    //         0047a62e     NOP
    //         0047a62f     NOP
    return;
}

void TPicturePanel::draw() {
    /* TODO: Stub */
    //                              void __thiscall draw(TPicturePanel * this)
    //              void              <VOID>         <RETURN>
    //              TPicturePanel *   ECX:4 (auto)   this
    //                               ?draw@TPicturePanel@@UAEXXZ                                  XREF[1]:     00571780(*)  
    //                               TPicturePanel::draw
    //                              Pnl_pic.cpp:175 (3)
    //         0047a630     PUSH       ESI
    //         0047a631     MOV        ESI,this
    //                              Pnl_pic.cpp:176 (34)
    //         0047a633     MOV        EAX,dword ptr [ESI + 0x20]
    //         0047a636     TEST       EAX,EAX
    //         0047a638     JZ         LAB_0047a6f0
    //         0047a63e     MOV        EAX,dword ptr [ESI + 0x70]
    //         0047a641     TEST       EAX,EAX
    //         0047a643     JZ         LAB_0047a6f0
    //         0047a649     MOV        EAX,dword ptr [ESI + 0x6c]
    //         0047a64c     TEST       EAX,EAX
    //         0047a64e     JZ         LAB_0047a6f0
    //         0047a654     PUSH       EDI
    //                              Pnl_pic.cpp:179 (7)
    //         0047a655     MOV        EDI,dword ptr [ESI]
    //         0047a657     PUSH       0x0
    //         0047a659     CALL       dword ptr [EDI + 0x28]
    //                              Pnl_pic.cpp:181 (10)
    //         0047a65c     MOV        EAX,dword ptr [ESI + 0x108]
    //         0047a662     TEST       EAX,EAX
    //         0047a664     JNZ        LAB_0047a66d
    //                              Pnl_pic.cpp:182 (7)
    //         0047a666     MOV        this,ESI
    //         0047a668     CALL       TPicturePanel::load_pic                          int load_pic(TPicturePanel * this)
    //                               LAB_0047a66d                                                 XREF[1]:     0047a664(j)  
    //                              Pnl_pic.cpp:184 (19)
    //         0047a66d     MOV        this,dword ptr [ESI + 0x20]
    //         0047a670     PUSH       0x1
    //         0047a672     PUSH       s_pnl_pic::draw                                  = "pnl_pic::draw"
    //         0047a677     CALL       TDrawArea::Lock                                  uchar * Lock(TDrawArea * this, char * param_1
    //         0047a67c     TEST       EAX,EAX
    //         0047a67e     JZ         LAB_0047a6d9
    //                              Pnl_pic.cpp:186 (10)
    //         0047a680     MOV        EAX,dword ptr [ESI + 0x110]
    //         0047a686     TEST       EAX,EAX
    //         0047a688     JNZ        LAB_0047a6ab
    //                              Pnl_pic.cpp:188 (10)
    //         0047a68a     MOV        this,dword ptr [ESI + 0x114]
    //         0047a690     TEST       this,this
    //         0047a692     JZ         LAB_0047a6cc
    //                              Pnl_pic.cpp:189 (21)
    //         0047a694     MOV        EAX,dword ptr [ESI + 0x10]
    //         0047a697     MOV        EDX,dword ptr [ESI + 0xc]
    //         0047a69a     PUSH       0x0
    //         0047a69c     PUSH       0x0=>DAT_fffffff8
    //         0047a69e     PUSH       EAX=>DAT_fffffff4
    //         0047a69f     MOV        EAX,dword ptr [ESI + 0x20]
    //         0047a6a2     PUSH       EDX=>DAT_fffffff0
    //         0047a6a3     PUSH       EAX
    //         0047a6a4     CALL       TPicture::Draw                                   void Draw(TPicture * this, TDrawArea * param_
    //                              Pnl_pic.cpp:191 (2)
    //         0047a6a9     JMP        LAB_0047a6cc
    //                               LAB_0047a6ab                                                 XREF[1]:     0047a688(j)  
    //                              Pnl_pic.cpp:193 (10)
    //         0047a6ab     MOV        this,dword ptr [ESI + 0x118]
    //         0047a6b1     TEST       this,this
    //         0047a6b3     JZ         LAB_0047a6cc
    //                              Pnl_pic.cpp:194 (23)
    //         0047a6b5     MOV        EDX,dword ptr [ESI + 0x10]
    //         0047a6b8     MOV        EAX,dword ptr [ESI + 0xc]
    //         0047a6bb     PUSH       0x0
    //         0047a6bd     PUSH       0x0=>DAT_fffffff8
    //         0047a6bf     PUSH       0x0=>DAT_fffffff4
    //         0047a6c1     PUSH       EDX=>DAT_fffffff0
    //         0047a6c2     MOV        EDX,dword ptr [ESI + 0x20]
    //         0047a6c5     PUSH       EAX
    //         0047a6c6     PUSH       EDX
    //         0047a6c7     CALL       TShape::shape_draw                               uchar shape_draw(TShape * this, TDrawArea * p
    //                               LAB_0047a6cc                                                 XREF[3]:     0047a692(j), 0047a6a9(j), 
    //                                                                                                         0047a6b3(j)  
    //                              Pnl_pic.cpp:197 (13)
    //         0047a6cc     MOV        this,dword ptr [ESI + 0x20]
    //         0047a6cf     PUSH       s_pnl_pic::draw                                  = "pnl_pic::draw"
    //         0047a6d4     CALL       TDrawArea::Unlock                                void Unlock(TDrawArea * this, char * param_1)
    //                               LAB_0047a6d9                                                 XREF[1]:     0047a67e(j)  
    //                              Pnl_pic.cpp:200 (10)
    //         0047a6d9     MOV        EAX,dword ptr [ESI + 0x108]
    //         0047a6df     TEST       EAX,EAX
    //         0047a6e1     JNZ        LAB_0047a6ea
    //                              Pnl_pic.cpp:201 (7)
    //         0047a6e3     MOV        this,ESI
    //         0047a6e5     CALL       TPicturePanel::free_pic                          void free_pic(TPicturePanel * this)
    //                               LAB_0047a6ea                                                 XREF[1]:     0047a6e1(j)  
    //                              Pnl_pic.cpp:203 (6)
    //         0047a6ea     MOV        this,ESI
    //         0047a6ec     CALL       dword ptr [EDI + 0x2c]
    //         0047a6ef     POP        EDI
    //                               LAB_0047a6f0                                                 XREF[3]:     0047a638(j), 0047a643(j), 
    //                                                                                                         0047a64e(j)  
    //                              Pnl_pic.cpp:204 (2)
    //         0047a6f0     POP        ESI
    //         0047a6f1     RET
    //         0047a6f2     ??         90h
    //         0047a6f3     NOP
    //         0047a6f4     NOP
    //         0047a6f5     NOP
    //         0047a6f6     NOP
    //         0047a6f7     NOP
    //         0047a6f8     NOP
    //         0047a6f9     NOP
    //         0047a6fa     NOP
    //         0047a6fb     NOP
    //         0047a6fc     NOP
    //         0047a6fd     NOP
    //         0047a6fe     NOP
    //         0047a6ff     NOP
    return;
}

long TPicturePanel::setup(TDrawArea* param_1, TPanel* param_2, long param_3, long param_4, long param_5, long param_6, char* param_7, long param_8, int param_9, int param_10) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return 0;
}

