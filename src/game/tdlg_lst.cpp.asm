#include "common.h"
#include "tdlg_lst.h"

TRIBE_Dialog_List::TRIBE_Dialog_List(char* param_1) {
    /* TODO: Stub */
    //                              undefined __thiscall TRIBE_Dialog_List(TRIBE_Dialog_List * this, cha
    //              undefined         <UNASSIGNED>   <RETURN>
    //              TRIBE_Dialog_L    ECX:4 (auto)   this
    //              char *            Stack[0x4]:4   param_1                   XREF[1]:     0050b450(R)  
    //                               ??0TRIBE_Dialog_List@@QAE@PAD@Z
    //                               TRIBE_Dialog_List::TRIBE_Dialog_List
    //                              tdlg_lst.cpp:26 (19)
    //         0050b450     MOV        EAX,dword ptr [ESP + param_1]
    //         0050b454     PUSH       ESI
    //         0050b455     MOV        ESI,this
    //         0050b457     PUSH       EAX
    //         0050b458     CALL       RGE_Dialog_List::RGE_Dialog_List                 undefined RGE_Dialog_List(RGE_Dialog_List * t
    //         0050b45d     MOV        dword ptr [ESI],TRIBE_Dialog_List::`vftable'     = 0050b470
    //                              tdlg_lst.cpp:27 (6)
    //         0050b463     MOV        EAX,ESI
    //         0050b465     POP        ESI
    //         0050b466     RET        0x4
    //         0050b469     ??         90h
    //         0050b46a     NOP
    //         0050b46b     NOP
    //         0050b46c     NOP
    //         0050b46d     NOP
    //         0050b46e     NOP
    //         0050b46f     NOP
}

int TRIBE_Dialog_List::create_list() {
    /* TODO: Stub */
    //                              int __thiscall create_list(TRIBE_Dialog_List * this)
    //              int               EAX:4          <RETURN>
    //              TRIBE_Dialog_L    ECX:4 (auto)   this
    //                               ?create_list@TRIBE_Dialog_List@@MAEHXZ                       XREF[1]:     005766b8(*)  
    //                               TRIBE_Dialog_List::create_list
    //                              tdlg_lst.cpp:33 (17)
    //         0050b4a0     MOV        EAX,dword ptr [ECX + this->field1196_0x4ac]
    //         0050b4a6     SUB        EAX,0x64
    //         0050b4a9     JZ         LAB_0050b4c0
    //         0050b4ab     DEC        EAX
    //         0050b4ac     JZ         LAB_0050b4bb
    //         0050b4ae     DEC        EAX
    //         0050b4af     JZ         LAB_0050b4b6
    //                              tdlg_lst.cpp:46 (5)
    //         0050b4b1     JMP        RGE_Dialog_List::create_list                     int create_list(RGE_Dialog_List * this)
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
    //                               LAB_0050b4b6                                                 XREF[1]:     0050b4af(j)  
    //                              tdlg_lst.cpp:43 (5)
    //         0050b4b6     JMP        TRIBE_Dialog_List::create_research_list          int create_research_list(TRIBE_Dialog_List * 
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
    //                               LAB_0050b4bb                                                 XREF[1]:     0050b4ac(j)  
    //                              tdlg_lst.cpp:40 (5)
    //         0050b4bb     JMP        TRIBE_Dialog_List::create_train_list             int create_train_list(TRIBE_Dialog_List * this)
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
    //                               LAB_0050b4c0                                                 XREF[1]:     0050b4a9(j)  
    //                              tdlg_lst.cpp:37 (5)
    //         0050b4c0     JMP        TRIBE_Dialog_List::create_build_list             int create_build_list(TRIBE_Dialog_List * this)
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
    //         0050b4c5     ??         90h
    //         0050b4c6     NOP
    //         0050b4c7     NOP
    //         0050b4c8     NOP
    //         0050b4c9     NOP
    //         0050b4ca     NOP
    //         0050b4cb     NOP
    //         0050b4cc     NOP
    //         0050b4cd     NOP
    //         0050b4ce     NOP
    //         0050b4cf     NOP
    return 0;
}

int TRIBE_Dialog_List::create_build_list() {
    /* TODO: Stub */
    //                              int __thiscall create_build_list(TRIBE_Dialog_List * this)
    //              int               EAX:4          <RETURN>
    //              TRIBE_Dialog_L    ECX:4 (auto)   this
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     0050b5a3(W), 0050b5ae(R)  
    //              undefined4        Stack[-0x8]:4  local_8                   XREF[3]:     0050b50b(*), 0050b51d(W), 0050b526(R)  
    //              short             Stack[-0xc]:2  item_num                  XREF[4]:     0050b511(*), 0050b519(W), 0050b56e(R), 0050b59c(R)  
    //              Item_Avail *      Stack[-0x10]:4 item_list
    //                               ?create_build_list@TRIBE_Dialog_List@@IAEHXZ                 XREF[1]:     create_list:0050b4c0(c)  
    //                               TRIBE_Dialog_List::create_build_list
    //                              tdlg_lst.cpp:54 (8)
    //         0050b4d0     SUB        ESP,0xc
    //         0050b4d3     PUSH       EBX
    //         0050b4d4     PUSH       EBP
    //         0050b4d5     MOV        EBX,this
    //         0050b4d7     PUSH       ESI
    //                              tdlg_lst.cpp:60 (14)
    //         0050b4d8     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0050b4de     PUSH       EDI
    //         0050b4df     CALL       RGE_Base_Game::get_player                        RGE_Player * get_player(RGE_Base_Game * this)
    //         0050b4e4     MOV        ESI,EAX
    //                              tdlg_lst.cpp:61 (6)
    //         0050b4e6     XOR        EBP,EBP
    //         0050b4e8     CMP        ESI,EBP
    //         0050b4ea     JNZ        LAB_0050b4f6
    //                              tdlg_lst.cpp:62 (2)
    //         0050b4ec     XOR        EAX,EAX
    //                              tdlg_lst.cpp:91 (8)
    //         0050b4ee     POP        EDI
    //         0050b4ef     POP        ESI
    //         0050b4f0     POP        EBP
    //         0050b4f1     POP        EBX
    //         0050b4f2     ADD        ESP,0xc
    //         0050b4f5     RET
    //                               LAB_0050b4f6                                                 XREF[1]:     0050b4ea(j)  
    //                              tdlg_lst.cpp:65 (13)
    //         0050b4f6     PUSH       0x4
    //         0050b4f8     MOV        this,ESI
    //         0050b4fa     CALL       RGE_Player::is_group_selected                    int is_group_selected(RGE_Player * this, shor
    //         0050b4ff     TEST       EAX,EAX
    //         0050b501     JNZ        LAB_0050b50b
    //                              tdlg_lst.cpp:91 (8)
    //         0050b503     POP        EDI
    //         0050b504     POP        ESI
    //         0050b505     POP        EBP
    //         0050b506     POP        EBX
    //         0050b507     ADD        ESP,0xc
    //         0050b50a     RET
    //                               LAB_0050b50b                                                 XREF[1]:     0050b501(j)  
    //                              tdlg_lst.cpp:71 (27)
    //         0050b50b     LEA        EAX=>local_8,[ESP + 0x14]
    //                              language.dll match for 0x76: "B"
    //         0050b50f     PUSH       0x76
    //         0050b511     LEA        this=>item_num,[ESP + 0x14]
    //         0050b515     PUSH       EAX
    //         0050b516     PUSH       this
    //         0050b517     MOV        this,ESI
    //         0050b519     MOV        dword ptr [ESP + item_num],EBP
    //         0050b51d     MOV        dword ptr [ESP + local_8],EBP
    //         0050b521     CALL       TRIBE_Player::interface_item_avail               void interface_item_avail(TRIBE_Player * this
    //                              tdlg_lst.cpp:73 (9)
    //         0050b526     MOV        EAX,dword ptr [ESP + local_8]
    //         0050b52a     CMP        AX,BP
    //         0050b52d     JNZ        LAB_0050b539
    //                              tdlg_lst.cpp:74 (2)
    //         0050b52f     XOR        EAX,EAX
    //                              tdlg_lst.cpp:91 (8)
    //         0050b531     POP        EDI
    //         0050b532     POP        ESI
    //         0050b533     POP        EBP
    //         0050b534     POP        EBX
    //         0050b535     ADD        ESP,0xc
    //         0050b538     RET
    //                               LAB_0050b539                                                 XREF[1]:     0050b52d(j)  
    //                              tdlg_lst.cpp:80 (21)
    //         0050b539     MOVSX      EDX,AX
    //                              language.dll match for 0x66: "Copperplate Gothic Light"
    //         0050b53c     PUSH       0x66
    //         0050b53e     PUSH       EDX
    //         0050b53f     MOV        word ptr [EBX + 0x4b0],AX
    //         0050b546     CALL       calloc                                           undefined calloc()
    //         0050b54b     ADD        ESP,0x8
    //                              tdlg_lst.cpp:81 (10)
    //         0050b54e     CMP        EAX,EBP
    //         0050b550     MOV        dword ptr [EBX + 0x4b4],EAX
    //         0050b556     JNZ        LAB_0050b562
    //                              tdlg_lst.cpp:82 (2)
    //         0050b558     XOR        EAX,EAX
    //                              tdlg_lst.cpp:91 (8)
    //         0050b55a     POP        EDI
    //         0050b55b     POP        ESI
    //         0050b55c     POP        EBP
    //         0050b55d     POP        EBX
    //         0050b55e     ADD        ESP,0xc
    //         0050b561     RET
    //                               LAB_0050b562                                                 XREF[1]:     0050b556(j)  
    //                              tdlg_lst.cpp:84 (9)
    //         0050b562     CMP        word ptr [EBX + 0x4b0],BP
    //         0050b569     JLE        LAB_0050b5d2
    //                               LAB_0050b56b                                                 XREF[1]:     0050b5d0(j)  
    //                              tdlg_lst.cpp:86 (41)
    //         0050b56b     MOVSX      this,BP
    //         0050b56e     MOV        ESI,dword ptr [ESP + item_num]
    //         0050b572     MOV        EAX,this
    //         0050b574     SHL        EAX,0x4
    //         0050b577     ADD        EAX,this
    //         0050b579     LEA        EDX,[ECX + ECX*0x4]
    //         0050b57c     MOV        this,dword ptr [EBX + 0x4b4]
    //         0050b582     SHL        EDX,0x3
    //         0050b585     LEA        EAX,[EAX + EAX*0x2]
    //         0050b588     MOV        SI,word ptr [ESI + EDX*0x1 + 0x4]
    //         0050b58d     SHL        EAX,0x1
    //         0050b58f     MOV        word ptr [ECX + EAX*0x1 + this->field100_0x64]
    //                              tdlg_lst.cpp:87 (62)
    //         0050b594     MOV        ESI,dword ptr [EBX + 0x4b4]
    //         0050b59a     ADD        ESI,EAX
    //         0050b59c     MOV        EAX,dword ptr [ESP + item_num]
    //         0050b5a0     OR         this,0xffffffff
    //         0050b5a3     MOV        dword ptr [ESP + local_4],ESI
    //         0050b5a7     MOV        EDI,dword ptr [EAX + EDX*0x1]
    //         0050b5aa     XOR        EAX,EAX
    //         0050b5ac     SCASB.RE   ES:EDI
    //         0050b5ae     MOV        EAX,dword ptr [ESP + local_4]
    //         0050b5b2     NOT        this
    //         0050b5b4     SUB        EDI,this
    //         0050b5b6     MOV        EDX,this
    //         0050b5b8     MOV        ESI,EDI
    //         0050b5ba     MOV        EDI,EAX
    //         0050b5bc     SHR        this,0x2
    //         0050b5bf     MOVSD.REP  ES:EDI,ESI
    //         0050b5c1     MOV        this,EDX
    //         0050b5c3     AND        this,0x3
    //         0050b5c6     INC        EBP
    //         0050b5c7     MOVSB.REP  ES:EDI,ESI
    //         0050b5c9     CMP        BP,word ptr [EBX + 0x4b0]
    //         0050b5d0     JL         LAB_0050b56b
    //                               LAB_0050b5d2                                                 XREF[1]:     0050b569(j)  
    //                              tdlg_lst.cpp:91 (13)
    //         0050b5d2     POP        EDI
    //         0050b5d3     POP        ESI
    //         0050b5d4     POP        EBP
    //         0050b5d5     MOV        EAX,0x1
    //         0050b5da     POP        EBX
    //         0050b5db     ADD        ESP,0xc
    //         0050b5de     RET
    //         0050b5df     ??         90h
    return 0;
}

int TRIBE_Dialog_List::create_train_list() {
    /* TODO: Stub */
    //                              int __thiscall create_train_list(TRIBE_Dialog_List * this)
    //              int               EAX:4          <RETURN>
    //              TRIBE_Dialog_L    ECX:4 (auto)   this
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     0050b6af(W), 0050b6ba(R)  
    //              undefined4        Stack[-0x8]:4  local_8                   XREF[3]:     0050b61f(W), 0050b62c(*), 0050b642(R)  
    //              short             Stack[-0xc]:2  item_num                  XREF[4]:     0050b61b(W), 0050b634(*), 0050b67a(R), 0050b6a8(R)  
    //              Item_Avail *      Stack[-0x10]:4 item_list
    //                               ?create_train_list@TRIBE_Dialog_List@@IAEHXZ                 XREF[1]:     create_list:0050b4bb(c)  
    //                               TRIBE_Dialog_List::create_train_list
    //                              tdlg_lst.cpp:97 (8)
    //         0050b5e0     SUB        ESP,0xc
    //         0050b5e3     PUSH       EBX
    //         0050b5e4     PUSH       EBP
    //         0050b5e5     MOV        EBX,this
    //         0050b5e7     PUSH       ESI
    //                              tdlg_lst.cpp:103 (14)
    //         0050b5e8     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0050b5ee     PUSH       EDI
    //         0050b5ef     CALL       RGE_Base_Game::get_player                        RGE_Player * get_player(RGE_Base_Game * this)
    //         0050b5f4     MOV        ESI,EAX
    //                              tdlg_lst.cpp:104 (4)
    //         0050b5f6     XOR        EBP,EBP
    //         0050b5f8     CMP        ESI,EBP
    //                              tdlg_lst.cpp:105 (6)
    //         0050b5fa     JZ         LAB_0050b6eb
    //                              tdlg_lst.cpp:108 (27)
    //         0050b600     CMP        dword ptr [ESI + 0x130],EBP
    //         0050b606     JZ         LAB_0050b6eb
    //         0050b60c     MOV        this,ESI
    //         0050b60e     CALL       RGE_Player::own_selected                         int own_selected(RGE_Player * this)
    //         0050b613     TEST       EAX,EAX
    //         0050b615     JZ         LAB_0050b6eb
    //                              tdlg_lst.cpp:112 (4)
    //         0050b61b     MOV        dword ptr [ESP + item_num],EBP
    //                              tdlg_lst.cpp:113 (4)
    //         0050b61f     MOV        dword ptr [ESP + local_8],EBP
    //                              tdlg_lst.cpp:114 (31)
    //         0050b623     MOV        EAX,dword ptr [ESI + 0x130]
    //         0050b629     MOV        this,dword ptr [EAX + 0x8]
    //         0050b62c     LEA        EAX=>local_8,[ESP + 0x14]
    //         0050b630     MOV        DX,word ptr [ECX + this->field16_0x10]
    //         0050b634     LEA        this=>item_num,[ESP + 0x10]
    //         0050b638     PUSH       EDX
    //         0050b639     PUSH       EAX
    //         0050b63a     PUSH       this
    //         0050b63b     MOV        this,ESI
    //         0050b63d     CALL       TRIBE_Player::interface_item_avail               void interface_item_avail(TRIBE_Player * this
    //                              tdlg_lst.cpp:116 (7)
    //         0050b642     MOV        EAX,dword ptr [ESP + local_8]
    //         0050b646     CMP        AX,BP
    //                              tdlg_lst.cpp:117 (6)
    //         0050b649     JZ         LAB_0050b6eb
    //                              tdlg_lst.cpp:123 (21)
    //         0050b64f     MOVSX      EDX,AX
    //                              language.dll match for 0x66: "Copperplate Gothic Light"
    //         0050b652     PUSH       0x66
    //         0050b654     PUSH       EDX
    //         0050b655     MOV        word ptr [EBX + 0x4b0],AX
    //         0050b65c     CALL       calloc                                           undefined calloc()
    //         0050b661     ADD        ESP,0x8
    //                              tdlg_lst.cpp:124 (8)
    //         0050b664     CMP        EAX,EBP
    //         0050b666     MOV        dword ptr [EBX + 0x4b4],EAX
    //                              tdlg_lst.cpp:125 (2)
    //         0050b66c     JZ         LAB_0050b6eb
    //                              tdlg_lst.cpp:127 (9)
    //         0050b66e     CMP        word ptr [EBX + 0x4b0],BP
    //         0050b675     JLE        LAB_0050b6de
    //                               LAB_0050b677                                                 XREF[1]:     0050b6dc(j)  
    //                              tdlg_lst.cpp:129 (41)
    //         0050b677     MOVSX      this,BP
    //         0050b67a     MOV        ESI,dword ptr [ESP + item_num]
    //         0050b67e     MOV        EAX,this
    //         0050b680     SHL        EAX,0x4
    //         0050b683     ADD        EAX,this
    //         0050b685     LEA        EDX,[ECX + ECX*0x4]
    //         0050b688     MOV        this,dword ptr [EBX + 0x4b4]
    //         0050b68e     SHL        EDX,0x3
    //         0050b691     LEA        EAX,[EAX + EAX*0x2]
    //         0050b694     MOV        SI,word ptr [ESI + EDX*0x1 + 0x4]
    //         0050b699     SHL        EAX,0x1
    //         0050b69b     MOV        word ptr [ECX + EAX*0x1 + this->field100_0x64]
    //                              tdlg_lst.cpp:130 (62)
    //         0050b6a0     MOV        ESI,dword ptr [EBX + 0x4b4]
    //         0050b6a6     ADD        ESI,EAX
    //         0050b6a8     MOV        EAX,dword ptr [ESP + item_num]
    //         0050b6ac     OR         this,0xffffffff
    //         0050b6af     MOV        dword ptr [ESP + local_4],ESI
    //         0050b6b3     MOV        EDI,dword ptr [EAX + EDX*0x1]
    //         0050b6b6     XOR        EAX,EAX
    //         0050b6b8     SCASB.RE   ES:EDI
    //         0050b6ba     MOV        EAX,dword ptr [ESP + local_4]
    //         0050b6be     NOT        this
    //         0050b6c0     SUB        EDI,this
    //         0050b6c2     MOV        EDX,this
    //         0050b6c4     MOV        ESI,EDI
    //         0050b6c6     MOV        EDI,EAX
    //         0050b6c8     SHR        this,0x2
    //         0050b6cb     MOVSD.REP  ES:EDI,ESI
    //         0050b6cd     MOV        this,EDX
    //         0050b6cf     AND        this,0x3
    //         0050b6d2     INC        EBP
    //         0050b6d3     MOVSB.REP  ES:EDI,ESI
    //         0050b6d5     CMP        BP,word ptr [EBX + 0x4b0]
    //         0050b6dc     JL         LAB_0050b677
    //                               LAB_0050b6de                                                 XREF[1]:     0050b675(j)  
    //                              tdlg_lst.cpp:133 (5)
    //         0050b6de     MOV        EAX,0x1
    //                              tdlg_lst.cpp:134 (18)
    //         0050b6e3     POP        EDI
    //         0050b6e4     POP        ESI
    //         0050b6e5     POP        EBP
    //         0050b6e6     POP        EBX
    //         0050b6e7     ADD        ESP,0xc
    //         0050b6ea     RET
    //                               LAB_0050b6eb                                                 XREF[5]:     0050b5fa(j), 0050b606(j), 
    //                                                                                                         0050b615(j), 0050b649(j), 
    //                                                                                                         0050b66c(j)  
    //         0050b6eb     POP        EDI
    //         0050b6ec     POP        ESI
    //         0050b6ed     POP        EBP
    //         0050b6ee     XOR        EAX,EAX
    //         0050b6f0     POP        EBX
    //         0050b6f1     ADD        ESP,0xc
    //         0050b6f4     RET
    //         0050b6f5     ??         90h
    //         0050b6f6     NOP
    //         0050b6f7     NOP
    //         0050b6f8     NOP
    //         0050b6f9     NOP
    //         0050b6fa     NOP
    //         0050b6fb     NOP
    //         0050b6fc     NOP
    //         0050b6fd     NOP
    //         0050b6fe     NOP
    //         0050b6ff     NOP
    return 0;
}

int TRIBE_Dialog_List::create_research_list() {
    /* TODO: Stub */
    //                              int __thiscall create_research_list(TRIBE_Dialog_List * this)
    //              int               EAX:4          <RETURN>
    //              TRIBE_Dialog_L    ECX:4 (auto)   this
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     0050b7cf(W), 0050b7da(R)  
    //              undefined4        Stack[-0x8]:4  local_8                   XREF[3]:     0050b73f(W), 0050b74c(*), 0050b762(R)  
    //              short             Stack[-0xc]:2  item_num                  XREF[4]:     0050b73b(W), 0050b754(*), 0050b79a(R), 0050b7c8(R)  
    //              Item_Avail *      Stack[-0x10]:4 item_list
    //                               ?create_research_list@TRIBE_Dialog_List@@IAEHXZ              XREF[1]:     create_list:0050b4b6(c)  
    //                               TRIBE_Dialog_List::create_research_list
    //                              tdlg_lst.cpp:140 (8)
    //         0050b700     SUB        ESP,0xc
    //         0050b703     PUSH       EBX
    //         0050b704     PUSH       EBP
    //         0050b705     MOV        EBX,this
    //         0050b707     PUSH       ESI
    //                              tdlg_lst.cpp:146 (14)
    //         0050b708     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0050b70e     PUSH       EDI
    //         0050b70f     CALL       RGE_Base_Game::get_player                        RGE_Player * get_player(RGE_Base_Game * this)
    //         0050b714     MOV        ESI,EAX
    //                              tdlg_lst.cpp:147 (4)
    //         0050b716     XOR        EBP,EBP
    //         0050b718     CMP        ESI,EBP
    //                              tdlg_lst.cpp:148 (6)
    //         0050b71a     JZ         LAB_0050b80b
    //                              tdlg_lst.cpp:151 (27)
    //         0050b720     CMP        dword ptr [ESI + 0x130],EBP
    //         0050b726     JZ         LAB_0050b80b
    //         0050b72c     MOV        this,ESI
    //         0050b72e     CALL       RGE_Player::own_selected                         int own_selected(RGE_Player * this)
    //         0050b733     TEST       EAX,EAX
    //         0050b735     JZ         LAB_0050b80b
    //                              tdlg_lst.cpp:155 (4)
    //         0050b73b     MOV        dword ptr [ESP + item_num],EBP
    //                              tdlg_lst.cpp:156 (4)
    //         0050b73f     MOV        dword ptr [ESP + local_8],EBP
    //                              tdlg_lst.cpp:157 (31)
    //         0050b743     MOV        EAX,dword ptr [ESI + 0x130]
    //         0050b749     MOV        this,dword ptr [EAX + 0x8]
    //         0050b74c     LEA        EAX=>local_8,[ESP + 0x14]
    //         0050b750     MOV        DX,word ptr [ECX + this->field16_0x10]
    //         0050b754     LEA        this=>item_num,[ESP + 0x10]
    //         0050b758     PUSH       EDX
    //         0050b759     PUSH       EAX
    //         0050b75a     PUSH       this
    //         0050b75b     MOV        this,ESI
    //         0050b75d     CALL       TRIBE_Player::interface_tech_avail               void interface_tech_avail(TRIBE_Player * this
    //                              tdlg_lst.cpp:159 (7)
    //         0050b762     MOV        EAX,dword ptr [ESP + local_8]
    //         0050b766     CMP        AX,BP
    //                              tdlg_lst.cpp:160 (6)
    //         0050b769     JZ         LAB_0050b80b
    //                              tdlg_lst.cpp:166 (21)
    //         0050b76f     MOVSX      EDX,AX
    //                              language.dll match for 0x66: "Copperplate Gothic Light"
    //         0050b772     PUSH       0x66
    //         0050b774     PUSH       EDX
    //         0050b775     MOV        word ptr [EBX + 0x4b0],AX
    //         0050b77c     CALL       calloc                                           undefined calloc()
    //         0050b781     ADD        ESP,0x8
    //                              tdlg_lst.cpp:167 (8)
    //         0050b784     CMP        EAX,EBP
    //         0050b786     MOV        dword ptr [EBX + 0x4b4],EAX
    //                              tdlg_lst.cpp:168 (2)
    //         0050b78c     JZ         LAB_0050b80b
    //                              tdlg_lst.cpp:170 (9)
    //         0050b78e     CMP        word ptr [EBX + 0x4b0],BP
    //         0050b795     JLE        LAB_0050b7fe
    //                               LAB_0050b797                                                 XREF[1]:     0050b7fc(j)  
    //                              tdlg_lst.cpp:172 (41)
    //         0050b797     MOVSX      this,BP
    //         0050b79a     MOV        ESI,dword ptr [ESP + item_num]
    //         0050b79e     MOV        EAX,this
    //         0050b7a0     SHL        EAX,0x4
    //         0050b7a3     ADD        EAX,this
    //         0050b7a5     LEA        EDX,[ECX + ECX*0x4]
    //         0050b7a8     MOV        this,dword ptr [EBX + 0x4b4]
    //         0050b7ae     SHL        EDX,0x3
    //         0050b7b1     LEA        EAX,[EAX + EAX*0x2]
    //         0050b7b4     MOV        SI,word ptr [ESI + EDX*0x1 + 0x4]
    //         0050b7b9     SHL        EAX,0x1
    //         0050b7bb     MOV        word ptr [ECX + EAX*0x1 + this->field100_0x64]
    //                              tdlg_lst.cpp:173 (62)
    //         0050b7c0     MOV        ESI,dword ptr [EBX + 0x4b4]
    //         0050b7c6     ADD        ESI,EAX
    //         0050b7c8     MOV        EAX,dword ptr [ESP + item_num]
    //         0050b7cc     OR         this,0xffffffff
    //         0050b7cf     MOV        dword ptr [ESP + local_4],ESI
    //         0050b7d3     MOV        EDI,dword ptr [EAX + EDX*0x1]
    //         0050b7d6     XOR        EAX,EAX
    //         0050b7d8     SCASB.RE   ES:EDI
    //         0050b7da     MOV        EAX,dword ptr [ESP + local_4]
    //         0050b7de     NOT        this
    //         0050b7e0     SUB        EDI,this
    //         0050b7e2     MOV        EDX,this
    //         0050b7e4     MOV        ESI,EDI
    //         0050b7e6     MOV        EDI,EAX
    //         0050b7e8     SHR        this,0x2
    //         0050b7eb     MOVSD.REP  ES:EDI,ESI
    //         0050b7ed     MOV        this,EDX
    //         0050b7ef     AND        this,0x3
    //         0050b7f2     INC        EBP
    //         0050b7f3     MOVSB.REP  ES:EDI,ESI
    //         0050b7f5     CMP        BP,word ptr [EBX + 0x4b0]
    //         0050b7fc     JL         LAB_0050b797
    //                               LAB_0050b7fe                                                 XREF[1]:     0050b795(j)  
    //                              tdlg_lst.cpp:176 (5)
    //         0050b7fe     MOV        EAX,0x1
    //                              tdlg_lst.cpp:177 (18)
    //         0050b803     POP        EDI
    //         0050b804     POP        ESI
    //         0050b805     POP        EBP
    //         0050b806     POP        EBX
    //         0050b807     ADD        ESP,0xc
    //         0050b80a     RET
    //                               LAB_0050b80b                                                 XREF[5]:     0050b71a(j), 0050b726(j), 
    //                                                                                                         0050b735(j), 0050b769(j), 
    //                                                                                                         0050b78c(j)  
    //         0050b80b     POP        EDI
    //         0050b80c     POP        ESI
    //         0050b80d     POP        EBP
    //         0050b80e     XOR        EAX,EAX
    //         0050b810     POP        EBX
    //         0050b811     ADD        ESP,0xc
    //         0050b814     RET
    //         0050b815     ??         90h
    //         0050b816     NOP
    //         0050b817     NOP
    //         0050b818     NOP
    //         0050b819     NOP
    //         0050b81a     NOP
    //         0050b81b     NOP
    //         0050b81c     NOP
    //         0050b81d     NOP
    //         0050b81e     NOP
    //         0050b81f     NOP
    return 0;
}

short TRIBE_Dialog_List::get_cur_id() {
    /* TODO: Stub */
    //                              short __thiscall get_cur_id(TRIBE_Dialog_List * this)
    //              short             AX:2           <RETURN>
    //              TRIBE_Dialog_L    ECX:4 (auto)   this
    //                               ?get_cur_id@TRIBE_Dialog_List@@MAEFXZ                        XREF[1]:     005766bc(*)  
    //                               TRIBE_Dialog_List::get_cur_id
    //                              tdlg_lst.cpp:183 (17)
    //         0050b820     MOV        EAX,dword ptr [ECX + this->field1196_0x4ac]
    //         0050b826     SUB        EAX,0x64
    //         0050b829     JZ         LAB_0050b836
    //         0050b82b     DEC        EAX
    //         0050b82c     JZ         LAB_0050b836
    //         0050b82e     DEC        EAX
    //         0050b82f     JZ         LAB_0050b836
    //                              tdlg_lst.cpp:196 (5)
    //         0050b831     JMP        RGE_Dialog_List::get_cur_id                      short get_cur_id(RGE_Dialog_List * this)
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
    //                               LAB_0050b836                                                 XREF[3]:     0050b829(j), 0050b82c(j), 
    //                                                                                                         0050b82f(j)  
    //                              tdlg_lst.cpp:187 (4)
    //         0050b836     OR         AX,0xffff
    //                              tdlg_lst.cpp:198 (1)
    //         0050b83a     RET
    //         0050b83b     ??         90h
    //         0050b83c     NOP
    //         0050b83d     NOP
    //         0050b83e     NOP
    //         0050b83f     NOP
    return 0;
}

TRIBE_Dialog_List::~TRIBE_Dialog_List() {
    /* TODO: Stub */
    //                              void __thiscall ~TRIBE_Dialog_List(TRIBE_Dialog_List * this)
    //              void              <VOID>         <RETURN>
    //              TRIBE_Dialog_L    ECX:4 (auto)   this
    //                               ??1TRIBE_Dialog_List@@UAE@XZ                                 XREF[1]:     `scalar_deleting_destructor':0050b
    //                               TRIBE_Dialog_List::~TRIBE_Dialog_List
    //         0050b490     JMP        RGE_Dialog_List::~RGE_Dialog_List
    //         0050b495     ??         90h
    //         0050b496     NOP
    //         0050b497     NOP
    //         0050b498     NOP
    //         0050b499     NOP
    //         0050b49a     NOP
    //         0050b49b     NOP
    //         0050b49c     NOP
    //         0050b49d     NOP
    //         0050b49e     NOP
    //         0050b49f     NOP
}

