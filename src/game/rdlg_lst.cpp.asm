#include "common.h"
#include "rdlg_lst.h"

RGE_Dialog_List::RGE_Dialog_List(char* param_1) {
    /* TODO: Stub */
    //                              undefined __thiscall RGE_Dialog_List(RGE_Dialog_List * this, char * 
    //              undefined         <UNASSIGNED>   <RETURN>
    //              RGE_Dialog_Lis    ECX:4 (auto)   this
    //              char *            Stack[0x4]:4   param_1                   XREF[1]:     0047e670(R)  
    //                               ??0RGE_Dialog_List@@QAE@PAD@Z                                XREF[2]:     action:00489fea(c), 
    //                               RGE_Dialog_List::RGE_Dialog_List                                          TRIBE_Dialog_List:0050b458(c)  
    //                              rdlg_lst.cpp:38 (19)
    //         0047e670     MOV        EAX,dword ptr [ESP + param_1]
    //         0047e674     PUSH       ESI
    //         0047e675     MOV        ESI,this
    //         0047e677     PUSH       EAX
    //         0047e678     CALL       TListDialog::TListDialog                         undefined TListDialog(TListDialog * this, cha
    //         0047e67d     MOV        dword ptr [ESI],RGE_Dialog_List::`vftable'       = 0047e690
    //                              rdlg_lst.cpp:39 (6)
    //         0047e683     MOV        EAX,ESI
    //         0047e685     POP        ESI
    //         0047e686     RET        0x4
    //         0047e689     ??         90h
    //         0047e68a     NOP
    //         0047e68b     NOP
    //         0047e68c     NOP
    //         0047e68d     NOP
    //         0047e68e     NOP
    //         0047e68f     NOP
}

int RGE_Dialog_List::setup(TScreenPanel* param_1, char* param_2, long param_3, int param_4, char* param_5) {
    /* TODO: Stub */
    //                              int __thiscall setup(RGE_Dialog_List * this, TScreenPanel * param_1,
    //              int               EAX:4          <RETURN>
    //              RGE_Dialog_Lis    ECX:4 (auto)   this
    //              TScreenPanel *    Stack[0x4]:4   param_1
    //              char *            Stack[0x8]:4   param_2
    //              long              Stack[0xc]:4   param_3
    //              int               Stack[0x10]:4  param_4                   XREF[1]:     0047e6b0(R)  
    //              char *            Stack[0x14]:4  param_5
    //                               ?setup@RGE_Dialog_List@@QAEHPAVTScreenPanel@@PADJH1@Z        XREF[1]:     action:0048a03d(c)  
    //                               RGE_Dialog_List::setup
    //                              rdlg_lst.cpp:45 (9)
    //         0047e6b0     MOV        EAX,dword ptr [ESP + param_4]
    //         0047e6b4     PUSH       EBX
    //         0047e6b5     MOV        EBX,this
    //         0047e6b7     PUSH       EBP
    //         0047e6b8     PUSH       ESI
    //                              rdlg_lst.cpp:54 (8)
    //         0047e6b9     XOR        ESI,ESI
    //         0047e6bb     MOV        dword ptr [EBX + 0x4ac],EAX
    //                              rdlg_lst.cpp:57 (23)
    //         0047e6c1     MOV        EAX,dword ptr [EBX + 0xd8]
    //         0047e6c7     CMP        EAX,ESI
    //         0047e6c9     PUSH       EDI
    //         0047e6ca     MOV        dword ptr [EBX + 0x4b4],ESI
    //         0047e6d0     MOV        dword ptr [EBX + 0x4b8],ESI
    //         0047e6d6     JZ         LAB_0047e6e1
    //                              rdlg_lst.cpp:58 (2)
    //         0047e6d8     XOR        EAX,EAX
    //                              rdlg_lst.cpp:91 (7)
    //         0047e6da     POP        EDI
    //         0047e6db     POP        ESI
    //         0047e6dc     POP        EBP
    //         0047e6dd     POP        EBX
    //         0047e6de     RET        0x14
    //                               LAB_0047e6e1                                                 XREF[1]:     0047e6d6(j)  
    //                              rdlg_lst.cpp:61 (14)
    //         0047e6e1     MOV        EDX,dword ptr [EBX]
    //         0047e6e3     MOV        this,EBX
    //         0047e6e5     CALL       dword ptr [EDX + 0x138]
    //         0047e6eb     TEST       EAX,EAX
    //         0047e6ed     JNZ        LAB_0047e6f6
    //                              rdlg_lst.cpp:91 (7)
    //         0047e6ef     POP        EDI
    //         0047e6f0     POP        ESI
    //         0047e6f1     POP        EBP
    //         0047e6f2     POP        EBX
    //         0047e6f3     RET        0x14
    //                               LAB_0047e6f6                                                 XREF[1]:     0047e6ed(j)  
    //                              rdlg_lst.cpp:65 (7)
    //         0047e6f6     MOV        this,EBX
    //         0047e6f8     CALL       RGE_Dialog_List::sort_list                       void sort_list(RGE_Dialog_List * this)
    //                              rdlg_lst.cpp:68 (7)
    //         0047e6fd     MOV        this,EBX
    //         0047e6ff     CALL       RGE_Dialog_List::calc_list_line                  void calc_list_line(RGE_Dialog_List * this)
    //                              rdlg_lst.cpp:71 (18)
    //         0047e704     MOVSX      EAX,word ptr [EBX + 0x4b0]
    //         0047e70b     PUSH       0x4
    //         0047e70d     PUSH       EAX=>DAT_fffffff8
    //         0047e70e     CALL       calloc                                           undefined calloc()
    //         0047e713     ADD        ESP,0x8
    //                              rdlg_lst.cpp:72 (10)
    //         0047e716     CMP        EAX,ESI
    //         0047e718     MOV        dword ptr [EBX + 0x4b8],EAX
    //         0047e71e     JNZ        LAB_0047e729
    //                              rdlg_lst.cpp:73 (2)
    //         0047e720     XOR        EAX,EAX
    //                              rdlg_lst.cpp:91 (7)
    //         0047e722     POP        EDI
    //         0047e723     POP        ESI
    //         0047e724     POP        EBP
    //         0047e725     POP        EBX
    //         0047e726     RET        0x14
    //                               LAB_0047e729                                                 XREF[1]:     0047e71e(j)  
    //                              rdlg_lst.cpp:74 (11)
    //         0047e729     XOR        EBP,EBP
    //         0047e72b     CMP        word ptr [EBX + 0x4b0],SI
    //         0047e732     JLE        LAB_0047e7aa
    //                              rdlg_lst.cpp:91 (10)
    //         0047e734     MOV        dword ptr [ESP + 0x20],ESI
    //         0047e738     JMP        LAB_0047e73e
    //                               LAB_0047e73a                                                 XREF[1]:     0047e7a8(j)  
    //         0047e73a     MOV        ESI,dword ptr [ESP + 0x20]
    //                               LAB_0047e73e                                                 XREF[1]:     0047e738(j)  
    //                              rdlg_lst.cpp:76 (37)
    //         0047e73e     MOV        EDI,dword ptr [EBX + 0x4b4]
    //         0047e744     OR         this,0xffffffff
    //         0047e747     ADD        EDI,ESI
    //         0047e749     XOR        EAX,EAX
    //         0047e74b     SCASB.RE   ES:EDI
    //         0047e74d     NOT        this
    //         0047e74f     PUSH       0x1
    //         0047e751     PUSH       this=>DAT_fffffff8
    //         0047e752     CALL       calloc                                           undefined calloc()
    //         0047e757     MOV        this,dword ptr [EBX + 0x4b8]
    //         0047e75d     ADD        ESP,0x8
    //         0047e760     MOV        dword ptr [this->_padding_ + EBP*0x4],EAX
    //                              rdlg_lst.cpp:77 (17)
    //         0047e763     MOV        EDX,dword ptr [EBX + 0x4b8]
    //         0047e769     MOV        EDX,dword ptr [EDX + EBP*0x4]
    //         0047e76c     TEST       EDX,EDX
    //         0047e76e     JZ         LAB_0047e81f
    //                              rdlg_lst.cpp:79 (54)
    //         0047e774     MOV        EDI,dword ptr [EBX + 0x4b4]
    //         0047e77a     OR         this,0xffffffff
    //         0047e77d     ADD        EDI,ESI
    //         0047e77f     XOR        EAX,EAX
    //         0047e781     SCASB.RE   ES:EDI
    //         0047e783     NOT        this
    //         0047e785     SUB        EDI,this
    //         0047e787     MOV        EAX,this
    //         0047e789     MOV        ESI,EDI
    //         0047e78b     MOV        EDI,EDX
    //         0047e78d     SHR        this,0x2
    //         0047e790     MOVSD.REP  ES:EDI,ESI
    //         0047e792     MOV        this,EAX
    //         0047e794     AND        this,0x3
    //         0047e797     INC        EBP
    //         0047e798     MOVSB.REP  ES:EDI,ESI
    //         0047e79a     ADD        dword ptr [ESP + 0x20],0x66
    //         0047e79f     MOVSX      this,word ptr [EBX + 0x4b0]
    //         0047e7a6     CMP        EBP,this
    //         0047e7a8     JL         LAB_0047e73a
    //                               LAB_0047e7aa                                                 XREF[1]:     0047e732(j)  
    //                              rdlg_lst.cpp:87 (110)
    //         0047e7aa     MOV        DX,word ptr [EBX + 0x4b2]
    //         0047e7b1     MOV        AX,word ptr [EBX + 0x4b0]
    //         0047e7b8     MOV        this,dword ptr [EBX + 0x4b8]
    //         0047e7be     PUSH       0x1e
    //         0047e7c0     PUSH       offset DAT_fffffff8
    //         0047e7c5     PUSH       offset DAT_fffffff4
    //         0047e7ca     PUSH       offset DAT_fffffff0
    //         0047e7cf     PUSH       0xa
    //         0047e7d1     PUSH       EDX
    //         0047e7d2     MOV        EDX,dword ptr [ESP + 0x3c]
    //         0047e7d6     PUSH       EAX
    //         0047e7d7     PUSH       this
    //         0047e7d8     PUSH       0x131
    //         0047e7dd     PUSH       0x122
    //         0047e7e2     MOV        EAX,dword ptr [ESP + 0x44]
    //         0047e7e6     PUSH       0x2d
    //         0047e7e8     MOV        this,dword ptr [ESP + 0x44]
    //         0047e7ec     PUSH       0xa
    //         0047e7ee     PUSH       EDX
    //         0047e7ef     MOV        EDX,dword ptr [ESP + 0x48]
    //         0047e7f3     PUSH       0x19
    //         0047e7f5     PUSH       0x122
    //         0047e7fa     PUSH       0xa
    //         0047e7fc     PUSH       0xa
    //         0047e7fe     PUSH       0x190
    //         0047e803     PUSH       0x136
    //         0047e808     PUSH       EAX
    //         0047e809     PUSH       this
    //         0047e80a     PUSH       EDX
    //         0047e80b     MOV        this,EBX
    //         0047e80d     CALL       TListDialog::setup                               long setup(TListDialog * this, TPanel * param
    //         0047e812     NEG        EAX
    //         0047e814     SBB        EAX,EAX
    //         0047e816     NEG        EAX
    //                              rdlg_lst.cpp:91 (16)
    //         0047e818     POP        EDI
    //         0047e819     POP        ESI
    //         0047e81a     POP        EBP
    //         0047e81b     POP        EBX
    //         0047e81c     RET        0x14
    //                               LAB_0047e81f                                                 XREF[1]:     0047e76e(j)  
    //         0047e81f     POP        EDI
    //         0047e820     POP        ESI
    //         0047e821     POP        EBP
    //         0047e822     XOR        EAX,EAX
    //         0047e824     POP        EBX
    //         0047e825     RET        0x14
    //         0047e828     ??         90h
    //         0047e829     NOP
    //         0047e82a     NOP
    //         0047e82b     NOP
    //         0047e82c     NOP
    //         0047e82d     NOP
    //         0047e82e     NOP
    //         0047e82f     NOP
    return 0;
}

RGE_Dialog_List::~RGE_Dialog_List() {
    /* TODO: Stub */
    //                              void __thiscall ~RGE_Dialog_List(RGE_Dialog_List * this)
    //              void              <VOID>         <RETURN>
    //              RGE_Dialog_Lis    ECX:4 (auto)   this
    //                               ??1RGE_Dialog_List@@UAE@XZ                                   XREF[2]:     `scalar_deleting_destructor':0047e
    //                               RGE_Dialog_List::~RGE_Dialog_List                                         ~RGE_Dialog_List:0050b48e(T), 
    //                                                                                                         ~TRIBE_Dialog_List:0050b490(j)  
    //                              rdlg_lst.cpp:97 (4)
    //         0047e830     PUSH       ESI
    //         0047e831     MOV        ESI,this
    //         0047e833     PUSH       EDI
    //                              rdlg_lst.cpp:100 (16)
    //         0047e834     MOV        EAX,dword ptr [ESI + 0x4b8]
    //         0047e83a     MOV        dword ptr [ESI],RGE_Dialog_List::`vftable'       = 0047e690
    //         0047e840     TEST       EAX,EAX
    //         0047e842     JZ         LAB_0047e88a
    //                              rdlg_lst.cpp:102 (11)
    //         0047e844     XOR        EDI,EDI
    //         0047e846     CMP        word ptr [ESI + 0x4b0],DI
    //         0047e84d     JLE        LAB_0047e871
    //                               LAB_0047e84f                                                 XREF[1]:     0047e86f(j)  
    //                              rdlg_lst.cpp:104 (13)
    //         0047e84f     MOV        EAX,dword ptr [ESI + 0x4b8]
    //         0047e855     MOV        EAX,dword ptr [EAX + EDI*0x4]
    //         0047e858     TEST       EAX,EAX
    //         0047e85a     JZ         LAB_0047e865
    //                              rdlg_lst.cpp:105 (21)
    //         0047e85c     PUSH       EAX
    //         0047e85d     CALL       free                                             undefined free()
    //         0047e862     ADD        ESP,0x4
    //                               LAB_0047e865                                                 XREF[1]:     0047e85a(j)  
    //         0047e865     MOVSX      this,word ptr [ESI + 0x4b0]
    //         0047e86c     INC        EDI
    //         0047e86d     CMP        EDI,this
    //         0047e86f     JL         LAB_0047e84f
    //                               LAB_0047e871                                                 XREF[1]:     0047e84d(j)  
    //                              rdlg_lst.cpp:107 (15)
    //         0047e871     MOV        EDX,dword ptr [ESI + 0x4b8]
    //         0047e877     PUSH       EDX
    //         0047e878     CALL       free                                             undefined free()
    //         0047e87d     ADD        ESP,0x4
    //                              rdlg_lst.cpp:108 (10)
    //         0047e880     MOV        dword ptr [ESI + 0x4b8],0x0
    //                               LAB_0047e88a                                                 XREF[1]:     0047e842(j)  
    //                              rdlg_lst.cpp:111 (10)
    //         0047e88a     MOV        EAX,dword ptr [ESI + 0x4b4]
    //         0047e890     TEST       EAX,EAX
    //         0047e892     JZ         LAB_0047e8a7
    //                              rdlg_lst.cpp:113 (9)
    //         0047e894     PUSH       EAX
    //         0047e895     CALL       free                                             undefined free()
    //         0047e89a     ADD        ESP,0x4
    //                              rdlg_lst.cpp:114 (17)
    //         0047e89d     MOV        dword ptr [ESI + 0x4b4],0x0
    //                               LAB_0047e8a7                                                 XREF[1]:     0047e892(j)  
    //         0047e8a7     MOV        this,ESI
    //         0047e8a9     CALL       TListDialog::~TListDialog                        void ~TListDialog(TListDialog * this)
    //                              rdlg_lst.cpp:116 (3)
    //         0047e8ae     POP        EDI
    //         0047e8af     POP        ESI
    //         0047e8b0     RET
    //         0047e8b1     ??         90h
    //         0047e8b2     NOP
    //         0047e8b3     NOP
    //         0047e8b4     NOP
    //         0047e8b5     NOP
    //         0047e8b6     NOP
    //         0047e8b7     NOP
    //         0047e8b8     NOP
    //         0047e8b9     NOP
    //         0047e8ba     NOP
    //         0047e8bb     NOP
    //         0047e8bc     NOP
    //         0047e8bd     NOP
    //         0047e8be     NOP
    //         0047e8bf     NOP
}

short RGE_Dialog_List::get_list_id() {
    /* TODO: Stub */
    //                              short __thiscall get_list_id(RGE_Dialog_List * this)
    //              short             AX:2           <RETURN>
    //              RGE_Dialog_Lis    ECX:4 (auto)   this
    //                               ?get_list_id@RGE_Dialog_List@@UAEFXZ                         XREF[2]:     00571e20(*), 005766b0(*)  
    //                               RGE_Dialog_List::get_list_id
    //                              rdlg_lst.cpp:122 (13)
    //         0047e8c0     MOV        AX,word ptr [ECX + this->_padding_]
    //         0047e8c7     CMP        AX,0xffff
    //         0047e8cb     JNZ        LAB_0047e8d1
    //                              rdlg_lst.cpp:124 (3)
    //         0047e8cd     OR         AX,AX
    //                              rdlg_lst.cpp:127 (1)
    //         0047e8d0     RET
    //                               LAB_0047e8d1                                                 XREF[1]:     0047e8cb(j)  
    //                              rdlg_lst.cpp:126 (24)
    //         0047e8d1     MOVSX      EDX,AX
    //         0047e8d4     MOV        this,dword ptr [ECX + this->list_info]
    //         0047e8da     MOV        EAX,EDX
    //         0047e8dc     SHL        EAX,0x4
    //         0047e8df     ADD        EAX,EDX
    //         0047e8e1     LEA        EAX,[EAX + EAX*0x2]
    //         0047e8e4     MOV        AX,word ptr [ECX + EAX*0x2 + this->_padding_]
    //                              rdlg_lst.cpp:127 (1)
    //         0047e8e9     RET
    //         0047e8ea     ??         90h
    //         0047e8eb     NOP
    //         0047e8ec     NOP
    //         0047e8ed     NOP
    //         0047e8ee     NOP
    //         0047e8ef     NOP
    return 0;
}

int RGE_Dialog_List::create_list() {
    /* TODO: Stub */
    //                              int __thiscall create_list(RGE_Dialog_List * this)
    //              int               EAX:4          <RETURN>
    //              RGE_Dialog_Lis    ECX:4 (auto)   this
    //                               ?create_list@RGE_Dialog_List@@MAEHXZ                         XREF[2]:     create_list:0050b4b1(c), 
    //                               RGE_Dialog_List::create_list                                              00571e28(*)  
    //                              rdlg_lst.cpp:133 (9)
    //         0047e8f0     MOV        EAX,dword ptr [ECX + this->list_type]
    //         0047e8f6     DEC        EAX
    //         0047e8f7     JZ         LAB_0047e8fc
    //                              rdlg_lst.cpp:143 (2)
    //         0047e8f9     XOR        EAX,EAX
    //                              rdlg_lst.cpp:145 (1)
    //         0047e8fb     RET
    //                               LAB_0047e8fc                                                 XREF[1]:     0047e8f7(j)  
    //                              rdlg_lst.cpp:137 (5)
    //         0047e8fc     JMP        RGE_Dialog_List::create_object_list              int create_object_list(RGE_Dialog_List * this)
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
    //         0047e901     ??         90h
    //         0047e902     NOP
    //         0047e903     NOP
    //         0047e904     NOP
    //         0047e905     NOP
    //         0047e906     NOP
    //         0047e907     NOP
    //         0047e908     NOP
    //         0047e909     NOP
    //         0047e90a     NOP
    //         0047e90b     NOP
    //         0047e90c     NOP
    //         0047e90d     NOP
    //         0047e90e     NOP
    //         0047e90f     NOP
    return 0;
}

int RGE_Dialog_List::create_object_list() {
    /* TODO: Stub */
    //                              int __thiscall create_object_list(RGE_Dialog_List * this)
    //              int               EAX:4          <RETURN>
    //              RGE_Dialog_Lis    ECX:4 (auto)   this
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     0047e944(W), 0047ea80(R)  
    //              short             Stack[-0x8]:2  end_i                     XREF[2]:     0047e926(W), 0047e9e5(R)  
    //              RGE_Player *      Stack[-0xc]:4  player                    XREF[3]:     0047e9d9(W), 0047ea73(R), 0047ea85(W)  
    //              short             Stack[-0x10]:2 i                         XREF[4]:     0047e9b6(W), 0047e9fe(R), 0047ea6f(R), 0047ea78(W)  
    //              short             Stack[-0x14]:2 j
    //                               ?create_object_list@RGE_Dialog_List@@IAEHXZ                  XREF[1]:     create_list:0047e8fc(c)  
    //                               RGE_Dialog_List::create_object_list
    //                              rdlg_lst.cpp:151 (8)
    //         0047e910     SUB        ESP,0x10
    //         0047e913     PUSH       EBX
    //         0047e914     PUSH       EBP
    //         0047e915     MOV        EBX,this
    //         0047e917     PUSH       ESI
    //                              rdlg_lst.cpp:158 (12)
    //         0047e918     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0047e91e     PUSH       EDI
    //         0047e91f     CALL       RGE_Base_Game::get_player                        RGE_Player * get_player(RGE_Base_Game * this)
    //                              rdlg_lst.cpp:159 (8)
    //         0047e924     TEST       EAX,EAX
    //         0047e926     MOV        dword ptr [ESP + end_i],EAX
    //         0047e92a     JNZ        LAB_0047e934
    //                              rdlg_lst.cpp:207 (8)
    //         0047e92c     POP        EDI
    //         0047e92d     POP        ESI
    //         0047e92e     POP        EBP
    //         0047e92f     POP        EBX
    //         0047e930     ADD        ESP,0x10
    //         0047e933     RET
    //                               LAB_0047e934                                                 XREF[1]:     0047e92a(j)  
    //                              rdlg_lst.cpp:163 (9)
    //         0047e934     MOV        word ptr [EBX + 0x4b0],0x1
    //                              rdlg_lst.cpp:164 (4)
    //         0047e93d     MOV        BP,word ptr [EAX + 0x22]
    //                              rdlg_lst.cpp:165 (9)
    //         0047e941     TEST       BP,BP
    //         0047e944     MOV        dword ptr [ESP + local_4],EBP
    //         0047e948     JLE        LAB_0047e96c
    //                              rdlg_lst.cpp:207 (15)
    //         0047e94a     XOR        EDX,EDX
    //         0047e94c     MOVSX      ESI,BP
    //                               LAB_0047e94f                                                 XREF[1]:     0047e96a(j)  
    //         0047e94f     MOV        this,dword ptr [EAX + 0x24]
    //         0047e952     MOV        this,dword ptr [this->_padding_ + EDX*0x1]
    //         0047e955     TEST       this,this
    //         0047e957     JZ         LAB_0047e966
    //                              rdlg_lst.cpp:168 (6)
    //         0047e959     CMP        byte ptr [ECX + this+0x4e],0x0
    //         0047e95d     JNZ        LAB_0047e966
    //                              rdlg_lst.cpp:169 (7)
    //         0047e95f     INC        word ptr [EBX + 0x4b0]
    //                               LAB_0047e966                                                 XREF[2]:     0047e957(j), 0047e95d(j)  
    //                              rdlg_lst.cpp:165 (6)
    //         0047e966     ADD        EDX,0x4
    //         0047e969     DEC        ESI
    //         0047e96a     JNZ        LAB_0047e94f
    //                               LAB_0047e96c                                                 XREF[1]:     0047e948(j)  
    //                              rdlg_lst.cpp:172 (12)
    //         0047e96c     MOV        AX,word ptr [EBX + 0x4b0]
    //         0047e973     TEST       AX,AX
    //         0047e976     JNZ        LAB_0047e982
    //                              rdlg_lst.cpp:173 (2)
    //         0047e978     XOR        EAX,EAX
    //                              rdlg_lst.cpp:207 (8)
    //         0047e97a     POP        EDI
    //         0047e97b     POP        ESI
    //         0047e97c     POP        EBP
    //         0047e97d     POP        EBX
    //         0047e97e     ADD        ESP,0x10
    //         0047e981     RET
    //                               LAB_0047e982                                                 XREF[1]:     0047e976(j)  
    //                              rdlg_lst.cpp:176 (20)
    //         0047e982     MOVSX      EDX,AX
    //                              language.dll match for 0x66: "Copperplate Gothic Light"
    //         0047e985     PUSH       0x66
    //         0047e987     PUSH       EDX
    //         0047e988     CALL       calloc                                           undefined calloc()
    //         0047e98d     ADD        ESP,0x8
    //         0047e990     MOV        dword ptr [EBX + 0x4b4],EAX
    //                              rdlg_lst.cpp:177 (4)
    //         0047e996     TEST       EAX,EAX
    //         0047e998     JNZ        LAB_0047e9a2
    //                              rdlg_lst.cpp:207 (8)
    //         0047e99a     POP        EDI
    //         0047e99b     POP        ESI
    //         0047e99c     POP        EBP
    //         0047e99d     POP        EBX
    //         0047e99e     ADD        ESP,0x10
    //         0047e9a1     RET
    //                               LAB_0047e9a2                                                 XREF[1]:     0047e998(j)  
    //                              rdlg_lst.cpp:180 (3)
    //         0047e9a2     OR         this,0xffffffff
    //                              rdlg_lst.cpp:181 (17)
    //         0047e9a5     MOV        EDI,s__<None>_                                   = 20h
    //         0047e9aa     MOV        word ptr [EAX + 0x64],this
    //         0047e9ae     XOR        EAX,EAX
    //         0047e9b0     SCASB.RE   ES:EDI=>s__<None>_                               = 20h
    //                                                                                  = "<None> "
    //         0047e9b2     NOT        this
    //         0047e9b4     SUB        EDI,this
    //                              rdlg_lst.cpp:183 (30)
    //         0047e9b6     MOV        dword ptr [ESP + i],0x1
    //         0047e9be     MOV        EAX,this
    //         0047e9c0     MOV        ESI,EDI
    //         0047e9c2     MOV        EDI,dword ptr [EBX + 0x4b4]
    //         0047e9c8     SHR        this,0x2
    //         0047e9cb     MOVSD.REP  ES:EDI,ESI
    //         0047e9cd     MOV        this,EAX
    //         0047e9cf     AND        this,0x3
    //         0047e9d2     MOVSB.REP  ES:EDI,ESI
    //                              rdlg_lst.cpp:184 (15)
    //         0047e9d4     XOR        ESI,ESI
    //         0047e9d6     TEST       BP,BP
    //         0047e9d9     MOV        dword ptr [ESP + player],ESI
    //         0047e9dd     JLE        LAB_0047ea8f
    //                              rdlg_lst.cpp:207 (2)
    //         0047e9e3     XOR        EBP,EBP
    //                               LAB_0047e9e5                                                 XREF[1]:     0047ea89(j)  
    //                              rdlg_lst.cpp:187 (25)
    //         0047e9e5     MOV        EDX,dword ptr [ESP + end_i]
    //         0047e9e9     MOV        this,dword ptr [EDX + 0x24]
    //         0047e9ec     MOV        EAX,dword ptr [this->_padding_ + EBP*0x1]
    //         0047e9ef     TEST       EAX,EAX
    //         0047e9f1     JZ         LAB_0047ea7c
    //         0047e9f7     MOV        this,byte ptr [EAX + 0x4e]
    //         0047e9fa     TEST       this,this
    //         0047e9fc     JNZ        LAB_0047ea7c
    //                              rdlg_lst.cpp:189 (28)
    //         0047e9fe     MOVSX      this,word ptr [ESP + i]
    //         0047ea03     MOV        EAX,this
    //         0047ea05     SHL        EAX,0x4
    //         0047ea08     ADD        EAX,this
    //         0047ea0a     MOV        this,dword ptr [EBX + 0x4b4]
    //         0047ea10     LEA        EAX,[EAX + EAX*0x2]
    //         0047ea13     SHL        EAX,0x1
    //         0047ea15     MOV        word ptr [ECX + EAX*0x1 + this->_padding_],SI
    //                              rdlg_lst.cpp:197 (15)
    //         0047ea1a     MOV        EDX,dword ptr [EDX + 0x24]
    //         0047ea1d     MOV        this,dword ptr [EDX + EBP*0x1]
    //         0047ea20     MOV        DX,word ptr [ECX + this->_padding_]
    //         0047ea24     TEST       DX,DX
    //         0047ea27     JLE        LAB_0047ea47
    //                              rdlg_lst.cpp:198 (28)
    //         0047ea29     MOV        EDI,dword ptr [EBX + 0x4b4]
    //         0047ea2f     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0047ea35     ADD        EDI,EAX
    //         0047ea37     PUSH       0x64
    //         0047ea39     MOV        ESI,dword ptr [this->_padding_]
    //         0047ea3b     PUSH       EDI
    //         0047ea3c     MOVSX      EAX,DX
    //         0047ea3f     PUSH       EAX
    //         0047ea40     PUSH       0x2
    //         0047ea42     CALL       dword ptr [ESI + 0x1c]
    //                              rdlg_lst.cpp:199 (2)
    //         0047ea45     JMP        LAB_0047ea6f
    //                               LAB_0047ea47                                                 XREF[1]:     0047ea27(j)  
    //                              rdlg_lst.cpp:200 (40)
    //         0047ea47     MOV        EDX,dword ptr [EBX + 0x4b4]
    //         0047ea4d     MOV        EDI,dword ptr [ECX + this->_padding_]
    //         0047ea50     ADD        EDX,EAX
    //         0047ea52     OR         this,0xffffffff
    //         0047ea55     XOR        EAX,EAX
    //         0047ea57     SCASB.RE   ES:EDI
    //         0047ea59     NOT        this
    //         0047ea5b     SUB        EDI,this
    //         0047ea5d     MOV        EAX,this
    //         0047ea5f     MOV        ESI,EDI
    //         0047ea61     MOV        EDI,EDX
    //         0047ea63     SHR        this,0x2
    //         0047ea66     MOVSD.REP  ES:EDI,ESI
    //         0047ea68     MOV        this,EAX
    //         0047ea6a     AND        this,0x3
    //         0047ea6d     MOVSB.REP  ES:EDI,ESI
    //                               LAB_0047ea6f                                                 XREF[1]:     0047ea45(j)  
    //                              rdlg_lst.cpp:202 (32)
    //         0047ea6f     MOV        EAX,dword ptr [ESP + i]
    //         0047ea73     MOV        ESI,dword ptr [ESP + player]
    //         0047ea77     INC        EAX
    //         0047ea78     MOV        dword ptr [ESP + i],EAX
    //                               LAB_0047ea7c                                                 XREF[2]:     0047e9f1(j), 0047e9fc(j)  
    //         0047ea7c     INC        ESI
    //         0047ea7d     ADD        EBP,0x4
    //         0047ea80     CMP        SI,word ptr [ESP + local_4]
    //         0047ea85     MOV        dword ptr [ESP + player],ESI
    //         0047ea89     JL         LAB_0047e9e5
    //                               LAB_0047ea8f                                                 XREF[1]:     0047e9dd(j)  
    //                              rdlg_lst.cpp:207 (13)
    //         0047ea8f     POP        EDI
    //         0047ea90     POP        ESI
    //         0047ea91     POP        EBP
    //         0047ea92     MOV        EAX,0x1
    //         0047ea97     POP        EBX
    //         0047ea98     ADD        ESP,0x10
    //         0047ea9b     RET
    //         0047ea9c     ??         90h
    //         0047ea9d     NOP
    //         0047ea9e     NOP
    //         0047ea9f     NOP
    //                              * int __cdecl rdlg_list_compare(void const *,void const *)                                              *
    //                              int __cdecl rdlg_list_compare(void * param_1, void * param_2)
    //              int               EAX:4          <RETURN>
    //              void *            Stack[0x4]:4   param_1                   XREF[1]:     0047eaa4(R)  
    //              void *            Stack[0x8]:4   param_2                   XREF[1]:     0047eaa0(R)  
    //                               ?rdlg_list_compare@@YAHPBX0@Z                                XREF[1]:     sort_list:0047eadd(*)  
    //                               rdlg_list_compare
    //                              rdlg_lst.cpp:308 (27)
    //         0047eaa0     MOV        EAX,dword ptr [ESP + param_2]
    //         0047eaa4     MOV        ECX,dword ptr [ESP + param_1]
    //         0047eaa8     PUSH       -0x1
    //         0047eaaa     PUSH       EAX
    //         0047eaab     PUSH       -0x1
    //         0047eaad     PUSH       ECX
    //         0047eaae     PUSH       0x1
    //         0047eab0     PUSH       0x400
    //         0047eab5     CALL       dword ptr [->KERNEL32.DLL::CompareStringA]       = 0048abe4
    //                              rdlg_lst.cpp:312 (5)
    //         0047eabb     CMP        EAX,0x1
    //         0047eabe     JNZ        LAB_0047eac4
    //                              rdlg_lst.cpp:313 (3)
    //         0047eac0     OR         EAX,0xffffffff
    //                              rdlg_lst.cpp:320 (1)
    //         0047eac3     RET
    //                               LAB_0047eac4                                                 XREF[1]:     0047eabe(j)  
    //                              rdlg_lst.cpp:314 (10)
    //         0047eac4     XOR        EDX,EDX
    //         0047eac6     CMP        EAX,0x3
    //         0047eac9     SETZ       DL
    //         0047eacc     MOV        EAX,EDX
    //                              rdlg_lst.cpp:320 (1)
    //         0047eace     RET
    //         0047eacf     ??         90h
    return 0;
}

void RGE_Dialog_List::sort_list() {
    /* TODO: Stub */
    //                              void __thiscall sort_list(RGE_Dialog_List * this)
    //              void              <VOID>         <RETURN>
    //              RGE_Dialog_Lis    ECX:4 (auto)   this
    //                               ?sort_list@RGE_Dialog_List@@IAEXXZ                           XREF[1]:     setup:0047e6f8(c)  
    //                               RGE_Dialog_List::sort_list
    //                              rdlg_lst.cpp:323 (30)
    //         0047ead0     MOVSX      EAX,word ptr [ECX + this->list_size]
    //         0047ead7     MOV        this,dword ptr [ECX + this->list_info]
    //         0047eadd     PUSH       rdlg_list_compare
    //                              language.dll match for 0x66: "Copperplate Gothic Light"
    //         0047eae2     PUSH       0x66
    //         0047eae4     PUSH       EAX
    //         0047eae5     PUSH       this
    //         0047eae6     CALL       qsort                                            undefined qsort()
    //         0047eaeb     ADD        ESP,0x10
    //                              rdlg_lst.cpp:325 (1)
    //         0047eaee     RET
    //         0047eaef     ??         90h
    return;
}

void RGE_Dialog_List::calc_list_line() {
    /* TODO: Stub */
    //                              void __thiscall calc_list_line(RGE_Dialog_List * this)
    //              void              <VOID>         <RETURN>
    //              RGE_Dialog_Lis    ECX:4 (auto)   this
    //                               ?calc_list_line@RGE_Dialog_List@@IAEXXZ                      XREF[1]:     setup:0047e6ff(c)  
    //                               RGE_Dialog_List::calc_list_line
    //                              rdlg_lst.cpp:331 (5)
    //         0047eaf0     PUSH       EBX
    //         0047eaf1     MOV        EBX,this
    //         0047eaf3     PUSH       EBP
    //         0047eaf4     PUSH       ESI
    //                              rdlg_lst.cpp:337 (18)
    //         0047eaf5     MOV        EAX,dword ptr [EBX]
    //         0047eaf7     PUSH       EDI
    //         0047eaf8     MOV        word ptr [EBX + 0x4b2],0xffff
    //         0047eb01     CALL       dword ptr [EAX + 0x13c]
    //                              rdlg_lst.cpp:339 (6)
    //         0047eb07     CMP        AX,0xffff
    //         0047eb0b     JZ         LAB_0047eb44
    //                              rdlg_lst.cpp:341 (14)
    //         0047eb0d     MOV        BP,word ptr [EBX + 0x4b0]
    //         0047eb14     XOR        ESI,ESI
    //         0047eb16     TEST       BP,BP
    //         0047eb19     JLE        LAB_0047eb44
    //                              rdlg_lst.cpp:343 (34)
    //         0047eb1b     MOV        EDI,dword ptr [EBX + 0x4b4]
    //                               LAB_0047eb21                                                 XREF[1]:     0047eb39(j)  
    //         0047eb21     MOVSX      EDX,SI
    //         0047eb24     MOV        this,EDX
    //         0047eb26     SHL        this,0x4
    //         0047eb29     ADD        this,EDX
    //         0047eb2b     LEA        this,[ECX + ECX*0x2]
    //         0047eb2e     CMP        word ptr [EDI + this->_padding_*0x2 + 0x64],AX
    //         0047eb33     JZ         LAB_0047eb3d
    //         0047eb35     INC        ESI
    //         0047eb36     CMP        SI,BP
    //         0047eb39     JL         LAB_0047eb21
    //         0047eb3b     JMP        LAB_0047eb44
    //                               LAB_0047eb3d                                                 XREF[1]:     0047eb33(j)  
    //                              rdlg_lst.cpp:345 (7)
    //         0047eb3d     MOV        word ptr [EBX + 0x4b2],SI
    //                               LAB_0047eb44                                                 XREF[3]:     0047eb0b(j), 0047eb19(j), 
    //                                                                                                         0047eb3b(j)  
    //                              rdlg_lst.cpp:351 (10)
    //         0047eb44     CMP        word ptr [EBX + 0x4b2],-0x1
    //         0047eb4c     JNZ        LAB_0047eb57
    //                              rdlg_lst.cpp:352 (9)
    //         0047eb4e     MOV        word ptr [EBX + 0x4b2],0x0
    //                               LAB_0047eb57                                                 XREF[1]:     0047eb4c(j)  
    //                              rdlg_lst.cpp:353 (5)
    //         0047eb57     POP        EDI
    //         0047eb58     POP        ESI
    //         0047eb59     POP        EBP
    //         0047eb5a     POP        EBX
    //         0047eb5b     RET
    //         0047eb5c     ??         90h
    //         0047eb5d     NOP
    //         0047eb5e     NOP
    //         0047eb5f     NOP
    return;
}

short RGE_Dialog_List::get_cur_id() {
    /* TODO: Stub */
    //                              short __thiscall get_cur_id(RGE_Dialog_List * this)
    //              short             AX:2           <RETURN>
    //              RGE_Dialog_Lis    ECX:4 (auto)   this
    //                               ?get_cur_id@RGE_Dialog_List@@MAEFXZ                          XREF[2]:     get_cur_id:0050b831(c), 
    //                               RGE_Dialog_List::get_cur_id                                               00571e2c(*)  
    //                              rdlg_lst.cpp:359 (9)
    //         0047eb60     MOV        EAX,dword ptr [ECX + this->list_type]
    //         0047eb66     DEC        EAX
    //         0047eb67     JZ         LAB_0047eb6e
    //                              rdlg_lst.cpp:373 (4)
    //         0047eb69     OR         AX,0xffff
    //                              rdlg_lst.cpp:375 (1)
    //         0047eb6d     RET
    //                               LAB_0047eb6e                                                 XREF[1]:     0047eb67(j)  
    //                              rdlg_lst.cpp:365 (12)
    //         0047eb6e     MOV        EAX,[rge_base_game]                              = 00000000
    //         0047eb73     MOV        AX,word ptr [EAX + 0x3fc]
    //                              rdlg_lst.cpp:375 (1)
    //         0047eb7a     RET
    //         0047eb7b     ??         90h
    //         0047eb7c     NOP
    //         0047eb7d     NOP
    //         0047eb7e     NOP
    //         0047eb7f     NOP
    return 0;
}

